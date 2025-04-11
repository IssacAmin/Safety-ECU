#include "CanTp_Types.h"

uint8_t remainingBlocks= 0;
uint8_t expectedSequenceNumber= SEQUENCE_NUMBER_INIT_VALUE;

extern void Dcm_CopyRxData (PduIdType id,const PduInfoType* info);

/*********************************************************************************************
 *                                Functions Definition                                       *
 *********************************************************************************************/
 
//This should be a call to send the ff to the upper layer!!!
Std_ReturnType N_USData_FFHandling(MessageType_t msg_type, N_AI address_info, uint8_t *data, uint32_t data_length)
{
    /*
     * 1) Check the data length (FF_DL !!!!) is valid and fits within the receiver's buffer size.
     * 2) Issue FF indication to the Upper Layer
     * 3) Prepare for Reassembly (allocate buffer).
     * 4) Send FC frame to the sender.
     */

     Std_ReturnType result= E_NOT_OK;

     int i;

     /* 
      * 1) check the data is not NULL data and not ZERO
      * 2) check the data length is less than the maximum data length
      */
     if((MAX_DATA_LENGTH >= data_length) && (0 != data_length) && (NULL != data))
     {
        result= E_OK;

        // Set the total message length
        dataBufferLength = (( (uint16_t)data[0] & 0x0f ) << 8) + (uint16_t)data[1];

        // Save the first 6 bytes of the data in the buffer
        for(i = 0 ; i < FIRST_FRAME_DATA_SEND_SIZE ; ++i)
        {
            dataBuffer[i]= data[i+2];
        }
        // Increment the byte number pointer to start saving the next CF in the buffer
        byteNumber = BYTE_NUMBER_INIT_VALUE;


        // change the network layer status to RX_BUSY
        networkLayerStatus= N_S_RX_BUSY;

        // TODO: change the parameter of the function to be more generic
        TransmitFlowControlFrame(CONSECUITVE_FRAME_BLOCK_SIZE, 1, FLOW_CONTROL_CONTINUE_TRANSMISSION);
        remainingBlocks = CONSECUITVE_FRAME_BLOCK_SIZE;
        WAIT_N_CR(5);

        // TODO: send the FFIndication to the application
//         N_USData_FFIndication(msg_type, address_info, data_length);
     }
     else
     {
        // TODO: Send FC frame to the sender to abort the transmission
        // TransmitFlowControlFrame(FLOW_CONTROL_ABORT_TRANSMISSION, 0, 0);
     }
     return result;
}


Std_ReturnType N_USData_CFHandling(uint8_t *data)
{
    Std_ReturnType result= E_NOT_OK;

    int i;

    uint8_t receivedDataSequenceNumber= (data[CONSECUTIVE_FRAME_PCI_INDEX] & CONSECUTIVE_FRAME_PCI_MASK);

    /* 
     * 1) Check the sequence number of the received frame.
     * 2) Append the data to the buffer.
     * 3) If the sender sent BS consecutive frames --> send the FC frame to the sender.
     * 3) If all data has been received --> send the data buffer to the application.
     */
    if(receivedDataSequenceNumber == expectedSequenceNumber)
    {
        result= E_OK;
        // Save the data in the buffer
//        //printf("consecutive frame: 0x");
        for(i = 1 ; i <= CONSECUTIVE_FRAME_DATA_SEND_SIZE ; ++i)
        {
            dataBuffer[byteNumber]= data[i];
//            //printf("%x ", dataBuffer[byteNumber]);
            byteNumber++;

            if(byteNumber == dataBufferLength)
            {
//                //printf("\nKHALSNAAAAAAAAAAAAA\n\n");
                break;
            }
            else
            {
                // Do nothing
            }
        }
        //printf("\n");
        remainingBlocks--;

        // Increment the sequence number
        expectedSequenceNumber= (expectedSequenceNumber+1)%16;

        // Check if the full msg is received
        if(byteNumber == dataBufferLength)
        {
            // Reset the variables to be used in the next reception
            expectedSequenceNumber= SEQUENCE_NUMBER_INIT_VALUE;
            networkLayerStatus    = N_S_IDLE;
            byteNumber            = BYTE_NUMBER_INIT_VALUE;

            //printf("\n\nThe message is received Successfully\n\nData: 0x");
            for(i= 0 ; i <= dataBufferLength ; i++)
            {
                //printf("%d\n", dataBuffer[i]);
            }
            //printf("MABROOOOOOOOOOOOOOOOOOOOOOOOOOOOOOK\n\n");
            // TODO: Send the data buffer to the application

            PduInfoType info =
            {
            		.SduDataPtr = dataBuffer,
					.SduLength = dataBufferLength
            };
            Dcm_CopyRxData(UDS_PDU_ID, &info);


        }
        else
        {
            // Check if the sender sent all the consecutive blocks
            if(0 == remainingBlocks)
            {
                // Send the FC frame to the sender
                TransmitFlowControlFrame(CONSECUITVE_FRAME_BLOCK_SIZE, 1, FLOW_CONTROL_CONTINUE_TRANSMISSION);
                WAIT_N_CR(5);
                remainingBlocks= CONSECUITVE_FRAME_BLOCK_SIZE;
            }
            else
            {
                // Start timer to wait for the next CF to detect timeout when it fires
                WAIT_N_CR(5);
            }
        }
    }
    else
    {
        result                = N_RESULT_WRONG_SN;
        expectedSequenceNumber= SEQUENCE_NUMBER_INIT_VALUE;
        networkLayerStatus    = N_S_IDLE;
        byteNumber            = BYTE_NUMBER_INIT_VALUE;

        //printf("Wrong sequence number\n\n");
        
        // TODO: Abort reception and send FC frame to the sender
    }
}
/*******************************************************************************************************
 * Function Description:
 *      Call back function to handle the received data from the Can If and pass it to the application
 *
 * Inputs:
 *      msg_type    : The type of the message (Diagnostic/Remote Diagnostic).
 *      address_info: The address information of the message.
 *      *data       : Pointer to the data buffer.
 *      data_length : The length of the data buffer.
 *      *result     : the result of the service.
 **********************************************************************************************************/
Std_ReturnType N_USData_Indication(MessageType_t msg_type, N_AI address_info, uint8_t * data, uint32_t data_length,  ServiceResult_t * result)
{

}

static void  CanTp_HandleRecievedFrame(MessageType_t msg_type, N_AI address_info, uint8_t * data, uint32_t data_length)
{
    uint8_t frameType= ((data[RECEIVED_FRAME_PCI_INDEX] & (uint8_t)FLOW_CONTROL_RECEIVED_FRAME_TYPE_MASK)>>4);
    uint8_t bs;
    uint8_t STmin;
    uint8_t FC_Flag;

    int i;
    //printf("Data Indication: %x\n", frameType);

    switch (frameType)
    {
    // Single Frame
    case SINGLE_FRAME_PCI_INDICATOR:
        //printf("Single Frame received\n");
        for(i = 0 ; i < data_length ; ++i)
        {
            dataBuffer[i]= data[i+1];
        }
        //TODO: send the singleFrameReceived to the application
        //printf("0X");
        for(i = 0 ; i < data_length ; ++i)
        {
            //printf("%x ", dataBuffer[i]);
        }
        
        break;

    case FIRST_FRAME_PCI_INDICATOR:
        //printf("First Frame received\n");
        if( N_S_IDLE == networkLayerStatus)
        {
            //*result= E_OK;
            // Start handling the first frame and send the FC frae to the sender
            N_USData_FFHandling(msg_type, address_info, data, data_length);
        }
        else
        {
            // Do nothing
        }
        break;

    case CONSECUTIVE_FRAME_PCI:
        if( N_S_RX_BUSY == networkLayerStatus)
        {
            STOP_TIMER();
            // Start handling the CF frame
            //printf("ha call the cf\n");
            N_USData_CFHandling(data);
        }
        else
        {
            // Do nothing
            //printf("Not waiting for CF frame right now, Reception Aborted...\n");
        }
        break;

    case FLOW_CONTROL_FRAME_PCI:
        if ( N_S_TX_WAIT_FC == networkLayerStatus)
        {
            /*
             * If the flow control received and we are waiting for it
             *   --> 1) Stop FC timer
             *       2) Extract the BS, STmin, FC_Flag and save them
             *       3) Change the network layer status to TX_BUSY
             *       4) Call the function to handle the received FC frame
             */
            STOP_TIMER();
            bs     = data[FLOW_CONTROL_FRAME_BS_INDEX];
            STmin  = data[FLOW_CONTROL_FRAME_STMIN_INDEX];
            FC_Flag= data[FLOW_CONTROL_FRAME_FC_FLAG_INDEX] & FLOW_CONTROL_FC_FLAGS_MASK;

            networkLayerStatus= N_S_TX_BUSY;
            //printf("fc: %x\n", FC_Flag);
            //printf("Flow Control Frame: BS: %d, STmin: %d, FC_Flag: %d\n", bs, STmin, FC_Flag);
            ReceivedFlowControlFrameHandling(dataBuffer, bs, STmin, FC_Flag);
        }
        else
        {
            //printf("Not waiting for FC frame right now\n");
            //TODO: send to the can If invalid FC frame received
        }
        break;

    default:
        //printf("Invalid Frame Type\n");
        break;
    }
}

void CanTp_RxIndication (PduIdType RxPduId,  const PduInfoType* PduInfoPtr )
{

	//TODO: retrieve addressing information from  the address info in cantp how is it retrieved from pduid
	MessageType_t msg_type = DIAGNOSTIC;
	N_AI address_info = {
			.N_SA = 0xff,
			.N_TA = 0x55,
			.N_TAtype = CAN_BASE_PHY
	};
	CanTp_HandleRecievedFrame(msg_type, address_info, PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength);
}
