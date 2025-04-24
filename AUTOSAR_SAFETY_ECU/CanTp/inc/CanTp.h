#ifndef __CANTP__
#define __CANTP__

#include "CanTp_Types.h"
#include "uds_types.h"
#include "CanTp_Cfg.h"
/********************************************************************************************
 *                                Function Prototypes                                       *
 ********************************************************************************************/

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
ServiceResult_t N_USData_Request(PduIdType NPduId, MessageType_t msg_type, N_AI address_info, uint8_t * data, uint32_t data_length);

/**************************************************************************
 * Function Description:
 *      Consruct and directly transmit the message ob the CAN bus.
 *      The message is a single frame message.
 *
 * Inputs:
 *      *data     : Pointer to the data buffer.
 *      dataLength: The length of the data bufferr.
 ***************************************************************************/
Std_ReturnType TransmitSingleFrame(PduIdType NPduId, uint8_t * data, uint8_t dataLength);


/**************************************************************************
 * Function Description:
 *      Consruct and directly transmit the First frame to the Can If.
 *
 * Inputs:
 *      *data     : Pointer to the data buffer
 *      dataLength: The length of the data buffer
 ***************************************************************************/
Std_ReturnType TransmitFirstFrame(PduIdType NPduId, uint8_t * data, uint8_t dataLength);

/*******************************************************************************************************
 * Function Description:
 *      Function that construct the consecutive frame (Add PCI and frame sequence number) and send it to
 *      the Can If based on the block size.
 *
 * Inputs:
 *      *data         : Pointer to the data buffer.
 *      sequenceNumber: The sequence number of the CF
 **********************************************************************************************************/
Std_ReturnType TransmitConsecutiveFrame(PduIdType NPduId, uint8_t * data, uint8_t sequnceNumber);

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
Std_ReturnType TransmitFlowControlFrame(PduIdType NPduId, uint8_t bs, uint8_t st_min, uint8_t fc_flags);

/*******************************************************************************************************
 * Function Description:
 *      Function that based on the received FC frame will take action to send BS consecutive frames or
 *      wait for another FC frame or abort transmission.
 *
 *
 * Inputs:
 *      *data    : Pointer to the data buffer.
 *      blockSize: Number of CF to send
 *      st_min   : Time between transmitting two consecutive frames
 *      fc_flags : Flag from the FC frame that decide to (continue sending CF/Wait for FC/Abort transmission)
 **********************************************************************************************************/
Std_ReturnType ReceivedFlowControlFrameHandling(PduIdType NPduId, uint8_t *data, uint8_t bs, uint8_t St_min, uint8_t fc_flags);

/**********************************************************************************************************
 *
 **********************************************************************************************************/
void N_USData_Confirm(MessageType_t msg_type, N_AI address_info, ServiceResult_t result);



/********************************************************************************************
 *                                Function Prototypes                                       *
 ********************************************************************************************/

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
Std_ReturnType N_USData_Indication(PduIdType NPduId, MessageType_t msg_type, N_AI address_info, uint8_t * data, uint32_t data_length,  ServiceResult_t * result);


Std_ReturnType N_USData_FFHandling(PduIdType NPduId, MessageType_t msg_type, N_AI address_info, uint8_t *data, uint32_t data_length);

Std_ReturnType N_USData_CFHandling(PduIdType NPduId, uint8_t *data);

void N_USData_FFIndication(PduIdType NPduId,  MessageType_t msg_type, N_AI address_info, uint32_t data_length);

void CanTp_RxIndication (PduIdType RxIPduId,  const PduInfoType* PduInfoPtr );

void CanTp_Init (const CanTp_ConfigType* CfgPtr);

Std_ReturnType CanTp_Transmit ( PduIdType TxNPduId, const PduInfoType* PduInfoPtr );

void CanTp_MainFunction(void);

#endif
