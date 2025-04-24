#include "CanTp_Types.h"

#define CANTP_SINGLEFRAME_LENGTH 8
#define CANTP_FIRSTFRAME_LENGTH 8

/********************************************************************************************
 *                                Global Variables                                          *
 ********************************************************************************************/
//variable to save the current state of the network layer
NetworkLayerStatus_t networkLayerStatus= N_S_IDLE;

CanTp_ConfigType * currentCanTpCfgPtr;

// Buffer to save the message received from the application
uint8_t dataBuffer[MAX_DATA_LENGTH]; //TODO: buffer should be allocated by upper layer

// Variable to store the total message length
uint16_t dataBufferLength= 0;

static uint8_t N_WFTcounter= 0;

// Flag to indicate if the data in the buffer is valid or no
static uint8_t isDataBufferHasValidData= FALSE;

uint8_t sequenceNumber = SEQUENCE_NUMBER_INIT_VALUE;
uint16_t byteNumber = BYTE_NUMBER_INIT_VALUE;
static uint8_t ST_Min= 0;
uint8_t blockSize= 0;

TimerType_t currentTimer;
bool timerElapsed = false;

/********* Temp global variable to test the timers using windows.h library ******/
//static HANDLE hTimerQueue= NULL;
//static HANDLE hTimer= NULL;
/**********************************************************************************************************
 *                                          Functions Definition                                          *
 **********************************************************************************************************/


/********************************************************************************************************** 
 * Function Description:
 *      Consruct and directly transmit the message ob the CAN bus.
 *      The message is a single frame message.
 *    
 * Inputs:
 *      *data     : Pointer to the data buffer.
 *      dataLength: The length of the data buffer.
 **********************************************************************************************************/
Std_ReturnType TransmitSingleFrame(uint8_t * data, uint8_t dataLength)
{
	int i;
	SingleFrame_t sf;
	// Byte 0 LSB
	sf.SF_PCI = SINGLE_FRAME_PCI_INDICATOR + dataLength;
	// Byte 0 MSB
	//sf.SF_PCI = (0x0 << 4) | (dataLength & 0x0F);


	// Start to fill the single frame data
	for(i = 0 ; i < SINGLE_FRAME_DATA_SEND_SIZE ; ++i)
	{
		// If the current index is less than the max data length index (valid data) --> add it to the struct
		if(i < dataLength)
		{
			sf.Data[i]= data[i];
		}
		// If the current index is larger than the valid data length --> Pad the remaining enteries
		else
		{
			sf.Data[i]= 0x55;
		}
	}

	// Start transmitting the data to the Can If
	networkLayerStatus= N_S_TX_BUSY;

	//printf("Single frame received: 0x%x ", sf.SF_PCI);
	for(i= 0 ; i < SINGLE_FRAME_DATA_SEND_SIZE ; i++)
	{
		//printf("%x ", sf.Data[i]);
	}
	//printf("\n\n");

	// TODO: (PDU ID?)
	PduInfoType pduInfo;
	pduInfo.SduDataPtr = &sf; //TODO: this should include the N_AI
	pduInfo.SduLength = CANTP_SINGLEFRAME_LENGTH;
	return CanIf_Transmit(0,&pduInfo);
}

/********************************************************************************************************** 
 * Function Description:
 *      Consruct and directly transmit the First frame to the Can If.

 * Inputs:
 *      *data     : Pointer to the data buffer
 *      dataLength: The length of the data buffer
 **********************************************************************************************************/
Std_ReturnType TransmitFirstFrame(uint8_t * data, uint8_t dataLength)
{
	int i;
	FirstFrame_t ff;

	// Byte 0 LSB
	ff.FF_PCI= (uint16_t)(FIRST_FRAME_PCI_INDICATOR<<12) + dataLength;

	//Byte 0 is the MSB
	//ff.FF_PCI = (0x1 << 12) | (dataLength & 0x0FFF);


	for(i= 0 ; i < FIRST_FRAME_DATA_SEND_SIZE ; i++)
	{
		ff.Data[i]= data[i];
	}

	//printf("First Frame: 0x%x ", ff.FF_PCI);
	for(i= 0 ; i < FIRST_FRAME_DATA_SEND_SIZE ; i++)
	{
		//printf("%x ", ff.Data[i]);
	}
	//printf("\n");

	// TODO: Send FF, variable type FC by refrence to Can If AND Start Timer to detect the timeout
	PduInfoType pduInfo;
	pduInfo.SduDataPtr = &ff;
	pduInfo.SduLength = 8;
	return CanIf_Transmit (0,&pduInfo);
}


/**********************************************************************************************************
 * Function Description:
 *      Function that construct the consecutive frame (Add PCI and frame sequence number) and send it to
 *      the Can If based on the block size.
 *
 * Inputs:
 *      *data         : Pointer to the data buffer.
 *      sequenceNumber: The sequence number of the CF
 **********************************************************************************************************/
Std_ReturnType TransmitConsecutiveFrame(uint8_t * data, uint8_t sequnceNumber)
{
	uint8_t result= E_NOT_OK;
	ConsecutiveFrame_t cf;
	static uint16_t bytesTransmitted= 6;

	static uint16_t remaingBytes= 0;

	int i;
	remaingBytes= dataBufferLength - bytesTransmitted;
	//printf("remaining bytes: %d\n\n", remaingBytes);

	if(NULL != data)
	{
		result= N_OK;

		cf.CF_PCI= (CONSECUTIVE_FRAME_PCI_INDICATOR<<4) | sequnceNumber;


		for(i= 0 ; i < CONSECUTIVE_FRAME_DATA_SEND_SIZE ; ++i)
		{
			// If the current index is less than the max data length index (valid data) --> add it to the struct
			if(i < remaingBytes)
			{
				cf.Data[i]= data[i];
				bytesTransmitted++;
			}
			// End of the message to be sent
			else
			{
				cf.Data[i]= 0x55;
			}
		}

		if(remaingBytes <= 7)
		{
			networkLayerStatus= N_S_IDLE;
			bytesTransmitted= 6;
		}


		//printf("Consecutive Frame: 0x%x ", cf.CF_PCI);
		for(i= 0 ; i < CONSECUTIVE_FRAME_DATA_SEND_SIZE ; i++)
		{
			//printf("%x ", cf.Data[i]);
		}
		//printf("\n");

		PduInfoType pduInfo;
		pduInfo.SduDataPtr = &cf;
		pduInfo.SduLength = 8;
		return CanIf_Transmit(0,&pduInfo);
	}
	else
	{
		result= E_NOT_OK;
	}
}

/*******************************************************************************************************
 * Function Description:
 *      Function that construct the Flow control frame (BS, ST_Min, wait/continue/abort transmission)
 *      and send it to the Can If based on the block size.
 *
 * Inputs:
 *      bs       : Block Size
 *      st_min   : Time between transmitting two consecutive frames
 *      fc_flags : Flag from the FC frame that decide to (continue sending CF/Wait for FC/Abort transmission)
 **********************************************************************************************************/ 
Std_ReturnType TransmitFlowControlFrame(uint8_t bs, uint8_t st_min, uint8_t fc_flags)
{
	uint8_t result= E_NOT_OK;
	int i;
	uint8_t fc[8]= {0x00, bs, st_min, 0x55, 0x55, 0x55, 0x55, 0x55};

	fc[FLOW_CONTROL_FRAME_PCI_INDEX]= 0x30 | fc_flags;

	//printf("Flow control frame sent to the sender: 0x");
	for(i= 0 ; i < FLOW_CONTROL_FRAME_SIZE ; i++)
	{
		//printf("%x ", fc[i]);
	}
	//printf("\n\n");

	PduInfoType pduInfo;
	pduInfo.SduDataPtr = &fc;
	pduInfo.SduLength = CANTP_FIRSTFRAME_LENGTH;
	CanIf_Transmit (0,&pduInfo);

	return result;
}

/*******************************************************************************************************
 * Function Description:
 *      API to requests transmission of message data with length bytes from the sender to the receiver
 *      peer entities over the network layer.
 *
 * Inputs:
 *      msg_type    : The type of the message (Diagnostic/Remote Diagnostic)
 *      address_info: The address information of the message
 *      *data       : Pointer to the data buffer
 *      data_length : The length of the data buffer
 **********************************************************************************************************/
ServiceResult_t N_USData_Request(MessageType_t msg_type, N_AI address_info, uint8_t * data, uint32_t data_length)
{
	// Variable to save the return value of the function
	ServiceResult_t result= N_RESULT_ERROR;
	int i;

	/*
	 * 1) Check the status of the service provider (network layer).
	 * 2) Compare the data length with the maximum payload size for CAN frames to choose to send SF or FF+CF.
	 * 3) If single frame --> transmit directly over the bus
	 *     If Multi frames --> send FF
	 *                         wait for FC frame --> time out if not received (return time out error)
	 *                                                 if received --> send CF or wait for FC base on the BS value in the FC
	 */

	// Parameters Checking (Make sure that the pointer is not pointing NULL) and the network layer
	// If the network layer is currently sending/recieving --> reject the current request
	// state is idle to handle the request
	if( (NULL != data) && (N_S_IDLE == networkLayerStatus) && (data_length <= MAX_DATA_LENGTH))
	{
		result= N_RESULT_OK;
	}
	else
	{
		result= N_RESULT_ERROR;
	}

	if(N_RESULT_OK == result)
	{
		// TODO: check the return value
		networkLayerStatus= N_S_TX_READY;

		// If the data length less than 8 bytes --> only single frame needed
		if(MAX_SINGLE_FRAME_DATA_LENGTH >= data_length)
		{
			//Construct the Single Frame check on the
			TransmitSingleFrame(data, data_length);

			// End of handling the request
			networkLayerStatus= N_S_IDLE;
		}

		// If the data length greater than 8 bytes --> segment the data to Multi frame
		else
		{
			/*
			 * 1) Save the data in the buffer and change the flag to indicate that the buffer has valid data
			 * 2) Transmit the first frame
			 * 3) Change the network layer status to wait for the FC frame
			 * 4) Start the timer to wait for the FC frame
			 */
			dataBufferLength= data_length;
			for(i=0 ; i < dataBufferLength ; i++)
			{
				dataBuffer[i]= data[i];
			}
			isDataBufferHasValidData= TRUE;

			// Transmit the first frame and start the timer to wait for the FC frame
			TransmitFirstFrame(dataBuffer, dataBufferLength);

			WAIT_FC_FRAME(MAX_WAIT_FOR_FC_FRAME_IN_SECONDS);
			networkLayerStatus= N_S_TX_WAIT_FC;
		}

	}
	else
	{
		// Do Nothing
		//printf("\n\n\n\nRequest Rejected: %x\n", networkLayerStatus);
	}


	return result;

}

/*******************************************************************************************************
 * Function Description:
 *      Function that based on the received FC frame will take action to send BS consecutive frames or
 *      wait for another FC frame or abort transmission.
 *      
 * Inputs:
 *      *data    : Pointer to the data buffer.
 *      blockSize: Number of CF to send
 *      st_min   : Time between transmitting two consecutive frames
 *      fc_flags : Flag from the FC frame that decide to (continue sending CF/Wait for FC/Abort transmission)    
 **********************************************************************************************************/
Std_ReturnType ReceivedFlowControlFrameHandling(uint8_t *data, uint8_t bs, uint8_t St_min, uint8_t fc_flags)
{
	uint8_t result= E_NOT_OK;
	uint8_t waitFlowControlFlag_f= TRUE;

	if(TRUE == isDataBufferHasValidData)
	{
		// If the FS equals 0 --> continue sending CF
		if(fc_flags == FLOW_CONTROL_CONTINUE_TRANSMISSION)
		{
			N_WFTcounter= 0;
			ST_Min= St_min;
			blockSize= bs;
			/*
			 * 1) Transmit CF based on the number of BS from the received FC frame
			 * 2) If all consecutive frames are transmitted:
			 *              --> 1) Change the network layer state to IDLE
			 *                  2) reset the sequence number and byte number
			 *    Else:
			 *              --> 1) Change the network layer state to wait for the next FC frame
			 *                  2) Start the timer to wait for the next FC frame
			 */
			TransmitConsecutiveFrame((dataBuffer + byteNumber), sequenceNumber);

			// After transmitting the consecutive frame successfully, point to the next seven byte
			// to send them in the next itteration
			byteNumber += 7;
			sequenceNumber= (sequenceNumber+1)%16;
			blockSize--;
			// Start timer to send the next CF when it fires
			WAIT_ST_MIN(ST_Min);

			result= N_RESULT_OK;
		}

		// If FC request to wait
		else if(fc_flags == FLOW_CONTROL_WAIT_FOR_TRANSMISSION)
		{
			// Increment the number of wait requestes requested by the receiver
			N_WFTcounter++;

			// Check if the wait requestes exceeds the maximum number
			if(MAX_WAIT_CONTROL_FRAMES_COUNT > N_WFTcounter)
			{
				networkLayerStatus= N_S_TX_WAIT_FC;

				WAIT_FC_FRAME(MAX_WAIT_FOR_FC_FRAME_IN_SECONDS);

				//printf("Waiting for the next flow control frame...\n");
				result= E_OK;
			}
			else
			{
				/*
				 * If exceed the maximum number of wait requestes:
				 *          --> 1) Change the stateof the network laye to IDLE
				 *              2) Reset the variables value t obe ready for the next transmission
				 *              3) Return "N_RESULT_WFT_OVRN"
				 */
				isDataBufferHasValidData= FALSE;
				networkLayerStatus      = N_S_IDLE;
				sequenceNumber          = SEQUENCE_NUMBER_INIT_VALUE;
				N_WFTcounter            = 0;
				byteNumber              = BYTE_NUMBER_INIT_VALUE;
				result                  = N_RESULT_WFT_OVRN;
				//printf("Transmission aborted \"Max count of wait request exceeded\"\n");
			}
		}
		// If the FS equals 2 --> abort transmission
		else if(fc_flags == FLOW_CONTROL_ABORT_TRANSMISSION)
		{
			/*
			 * If the FC wants to abort the transmission:
			 *          --> 1) Change the state of the network laye to IDLE.
			 *              2) Reset the variables value t obe ready for the next transmission.
			 *              3) Return "N_RESULT_WFT_OVRN".
			 */
			isDataBufferHasValidData= FALSE;
			networkLayerStatus= N_S_IDLE;
			sequenceNumber    = SEQUENCE_NUMBER_INIT_VALUE;
			N_WFTcounter      = 0;
			byteNumber        = BYTE_NUMBER_INIT_VALUE;
			result            = N_RESULT_BUFFER_OVFLW;
			//printf("Transmission aborted \"FC Aborted\".\n");
		}
		// Invalid fc flag value
		else
		{
			N_WFTcounter= 0;
			result      = N_RESULT_INVALID_FS;
		}
	}
	else
	{
		//printf("NO VALID DATA\n\n");
	}

	return result;
}



/**********************************************************************************************************
 * Function Description:
 *      API to indicate the reception of a message from the network layer to the application layer.
 *      
 * Inputs:
 *      msg_type    : The type of the message (Diagnostic/Remote Diagnostic)
 *      address_info: The address information of the message
 *      *data       : Pointer to the data buffer
 *      data_length : The length of the data buffer
 **********************************************************************************************************/
void N_USData_Confirm(MessageType_t msg_type, N_AI address_info, ServiceResult_t result)
{

}

Std_ReturnType CanTp_Transmit ( PduIdType TxNPduId, const PduInfoType* PduInfoPtr )
{
	//TODO: should be async
	//TODO: validate input parameters

	CanTp_NSduType * CanTpNSduRecordPtr = &(currentCanTpCfgPtr->CanTpNSduList[TxNPduId]);

	//TODO: get address info from metadata if NSdu uses a generic connection
	N_AI addressInfo =
	{
		.N_SA = CanTpNSduRecordPtr->configData.CanTpTxNSdu.CanTpNSa,
		.N_TA = CanTpNSduRecordPtr->configData.CanTpTxNSdu.CanTpNTa,
		.N_TAtype = CanTpNSduRecordPtr->configData.CanTpTxNSdu.CanTpTxTaType
	};

	//TODO: where to get message type?
	N_USData_Request(DIAGNOSTIC, addressInfo, PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength);

	return N_OK;
}

void StartTimer(TimerType_t timerType, uint8_t time_sec)
{
	StatusType ret;
	ret = SetRelAlarm(canTp_OsAlarm, time_sec * 1000, 0);
	currentTimer = timerType;
}

void StopTimer(void)
{
	StatusType ret;
	ret = CancelAlarm(canTp_OsAlarm);
}


void canTpOsAlarmCallback(void)
{
	timerElapsed = true;
}


void CanTp_TxConfirmation(PduIdType CanTpPduId, Std_ReturnType ret)
{
	//TODO: translate the LPduId to NPduId and notify PduR
}


void CanTp_MainFunction (void)
{
	if(timerElapsed == true)
	{
		timerElapsed = false;
		switch (currentTimer)
		{
		case ST_MIN_TIMER:

			if((byteNumber < dataBufferLength) && (blockSize > 0))
			{
				TransmitConsecutiveFrame((dataBuffer + byteNumber), sequenceNumber);
				// After transmitting the consecutive frame successfully, point to the next seven byte
				// to send them in the next iteration
				byteNumber += 7;
				sequenceNumber= (sequenceNumber+1)%16;
				blockSize--;
				/*
				 * Check if this was the last CF in the message
				 */
				if(byteNumber > dataBufferLength)
				{
					//TODO: Send the confirmation to the application
					networkLayerStatus= N_S_IDLE;
					sequenceNumber    = SEQUENCE_NUMBER_INIT_VALUE;
					byteNumber        = BYTE_NUMBER_INIT_VALUE;

					//waitFlowControlFlag_f= FALSE;
					//printf("Transmission Completed\n\n");
				}
				else
				{
					if(0 == blockSize)
					{
						// change the network layer status to waiting for flow control frame
						networkLayerStatus= N_S_TX_WAIT_FC;
						WAIT_FC_FRAME(MAX_WAIT_FOR_FC_FRAME_IN_SECONDS);

						//printf("Block size limit reached, FC timer is started !!\n\n");
					}
					else
					{
						// Still have more CF to send (BS > 0)
						WAIT_ST_MIN(ST_Min);
					}
				}
			}
			else
			{
				// Do Nothing
			}
			break;

		case FC_TIMER:
			// If the timer fired and the network layer is waiting for the FC frame
			if(N_S_TX_WAIT_FC == networkLayerStatus)
			{
				// If the network layer is waiting for the FC frame and the timer fired
				// --> abort the transmission
				isDataBufferHasValidData= FALSE;
				networkLayerStatus      = N_S_IDLE;
				sequenceNumber          = SEQUENCE_NUMBER_INIT_VALUE;
				N_WFTcounter            = 0;
				byteNumber              = BYTE_NUMBER_INIT_VALUE;
				//printf("Transmission aborted \"FC Timeout\".\n");
			}
			break;


		case N_CR_TIMER:

			expectedSequenceNumber= SEQUENCE_NUMBER_INIT_VALUE;
			remainingBlocks       = 0;
			networkLayerStatus    = N_S_IDLE;
			byteNumber            = BYTE_NUMBER_INIT_VALUE;

			//printf("Transmission aborted \"CF Timeout\".\n");
			break;

		default:
			break;
		}
	}

}

void CanTp_Init (const CanTp_ConfigType* CfgPtr)
{
	currentCanTpCfgPtr = CfgPtr;
}
