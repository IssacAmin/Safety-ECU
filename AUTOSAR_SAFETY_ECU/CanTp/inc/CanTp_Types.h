#ifndef __CANTP_TYPES__
#define __CANTP_TYPES__

#include <stdint.h>
#include <stdio.h>
#include <null.h>
#include <stdbool.h>

#include "Std_Types.h"

#include "ComStack_Types.h"

#include "uds_types.h"

#include "CanIf.h"

#include "Os.h"


/********************************************************************************************
 *                                         MACROS                                           *
 ********************************************************************************************/
#define TRUE                                         1
#define FALSE                                        0

#define MAX_SINGLE_FRAME_DATA_LENGTH                 7
#define MAX_DATA_LENGTH                              4095
#define MAX_SEQUENCE_NUMBER                          15

#define SEQUENCE_NUMBER_INIT_VALUE                   1
#define BYTE_NUMBER_INIT_VALUE                       6

#define SINGLE_FRAME_DATA_SEND_SIZE                  7
#define FIRST_FRAME_DATA_SEND_SIZE                   6
#define CONSECUTIVE_FRAME_DATA_SEND_SIZE             7

#define SINGLE_FRAME_PCI_INDICATOR                   0x00
#define FIRST_FRAME_PCI_INDICATOR                    0x01
#define CONSECUTIVE_FRAME_PCI_INDICATOR              0x02
#define FLOW_CONTROL_FRAME_PCI_INDICATOR             0X03

#define FLOW_CONTROL_FC_FLAGS_MASK                   0x0F
#define FLOW_CONTROL_RECEIVED_FRAME_TYPE_MASK        0xF0

#define FLOW_CONTROL_FRAME_FC_FLAG_INDEX             0
#define FLOW_CONTROL_FRAME_PCI_INDEX                 0
#define FLOW_CONTROL_FRAME_BS_INDEX                  1
#define FLOW_CONTROL_FRAME_STMIN_INDEX               2
#define FLOW_CONTROL_FRAME_SIZE                      8

#define CONSECUTIVE_FRAME_PCI_INDEX                  0
#define CONSECUTIVE_FRAME_PCI_MASK                   0x0F

#define RECEIVED_FRAME_PCI_INDEX                     0

#define FLOW_CONTROL_CONTINUE_TRANSMISSION           0
#define FLOW_CONTROL_WAIT_FOR_TRANSMISSION           1
#define FLOW_CONTROL_ABORT_TRANSMISSION              2

#define MAX_WAIT_CONTROL_FRAMES_COUNT                6
#define MAX_WAIT_FOR_FC_FRAME_IN_SECONDS             1

#define CONSECUITVE_FRAME_BLOCK_SIZE                 3


 /********************************************************************************************
  *                                Type Definition                                           *
  ********************************************************************************************/
 typedef enum{
     CAN_BASE_PHY,       //CAN 2.0 base 11 bit addressing - physical
     CAN_BASE_FUNC,      //CAN 2.0 base 11 bit addressing - functional
     CAN_EXT_PHY,        //CAN 2.0 EXTENDED 29 bit addressing - physical
     CAN_EXT_FUNC,       //CAN 2.0 EXTENDED 29 bit addressing - functional

 }N_TAtype_t;


 typedef enum{
     DIAGNOSTIC,
     REMOTE_DIAGNOSTIC   //Remote adds to the N_AI the optional AE field
 }MessageType_t;

 typedef enum {
     N_RESULT_OK,           // Operation successful
     N_RESULT_TIMEOUT_A,    // Timeout occurred during transmission
     N_RESULT_TIMEOUT_Bs,   // Timeout waiting for Flow Control (FC) frame
     N_RESULT_TIMEOUT_Cr,   // Timeout waiting for Consecutive Frame (CF)
     N_RESULT_WRONG_SN,     // Sequence number mismatch in CF
     N_RESULT_INVALID_FS,   // Invalid Flow Status in FC frame
     N_RESULT_UNEXP_PDU,    // Unexpected Protocol Data Unit (PDU) received
     N_RESULT_WFT_OVRN,     // Wait Frame (WFT) overflow (too many WFTs)
     N_RESULT_BUFFER_OVFLW, // Buffer overflow (data exceeds available space)
     N_RESULT_ERROR         // General error
 } ServiceResult_t;


 typedef enum{
     N_OK,                   // Parameter change successful
     N_RX_ON,                //Reception process is ongoing (change not allowed)
     N_WRONG_PARAMETER,      // Invalid parameter ID requested
     N_WRONG_VALUE           // Invalid value assigned to the parameter
 }ChangeParameterResult_t;


 typedef enum{
     CTS,                    //Continue to send
     WAIT,                   //wait
     OVFLW                   //Overflow
 }FlowControlState_t;

 typedef enum{
     SINGLE_FRAME_PCI        = 0,       //Indicates type of frame (bit 7 - 4) in PCI
     FIRST_FRAME_PCI         = 1,
     CONSECUTIVE_FRAME_PCI   = 2,
     FLOW_CONTROL_FRAME_PCI  = 3,
 }FrameType_t;

 typedef enum{
     SINGLE_FRAME,
     MULTI_FRAME
 }TransmitFrame_t;

 typedef enum {
     N_S_IDLE 	    = 0x00,     // Has to pending action
     N_S_RX_BUSY 	= 0x02,     // Reception is in progress
     N_S_TX_BUSY 	= 0x04,     // Transmission is in progress
     N_S_TX_READY 	= 0x05,     // Transmission is ready to begin
     N_S_TX_WAIT_FC = 0x10,     // Transmission is in progress and waits

 }NetworkLayerStatus_t;

typedef enum{
    FC_TIMER,
    ST_MIN_TIMER,
    N_CR_TIMER

}TimerType_t;

 //Defined Structs

 typedef struct{
     uint8_t     N_SA;       //Source Address: encodes the sending network layer protocol entity
     uint8_t     N_TA;       //Target Address: Encodes the recieving entity
     N_TAtype_t    N_TAtype;   //Target address type
     uint8_t     N_AE;       //optional address extenstion
 } N_AI;


 typedef struct{
     uint8_t SF_PCI;         // 0x0000 + DATA LENGTH  [0 - 8]
     uint8_t Data[7];
 }SingleFrame_t;

 typedef struct{
     uint16_t FF_PCI;        // 0x0001 + DATA LENGTH [0 - 4095]
     uint8_t Data[6];
 }FirstFrame_t;

 typedef struct{
     uint8_t CF_PCI;         //0x0010 + Sequence Number
     uint8_t Data[7];
 }ConsecutiveFrame_t;

 typedef struct{
     uint8_t FC_PCI;                         // 0x0011 + FLOW STATE
     uint8_t FC_BS;                          // Block Size
     uint8_t FC_ST_MIN;                      // minimum separation time
     uint16_t Fill1;
     uint8_t Fill2;                          //NULL Data set as 0xAA
 }FlowControlFrame_t;

 typedef struct{
     uint32_t N_As;                            //Timeout for N_PDU in sender side
     uint32_t N_Ar;                            //Timeout for N_PDU in receiver side
     uint32_t N_Bs;                            //
     uint32_t N_Cr;

 }NetworkTimeouts;


 typedef struct {
     /* sender paramters */
     uint32_t                    send_arbitration_id; /* used to reply consecutive frame */
     /* message buffer */
     uint8_t*                    send_buffer;
     uint16_t                    send_buf_size;
     uint16_t                    send_size;
     uint16_t                    send_offset;
     /* multi-frame flags */
     uint8_t                     send_sn;
     uint16_t                    send_bs_remain; /* Remaining block size */
     uint8_t                     send_st_min;    /* Separation Time between consecutive frames, unit millis */
     uint8_t                     send_wtf_count; /* Maximum number of FC.Wait frame transmissions  */
     uint32_t                    send_timer_st;  /* Last time send consecutive frame */
     uint32_t                    send_timer_bs;  /* Time until reception of the next FlowControl N_PDU
                                                    start at sending FF, CF, receive FC
                                                    end at receive FC */
     int                         send_protocol_result;
     uint8_t                     send_status;
 } IsoTpLinkTx_t;

 typedef struct {
     /* receiver paramters */
     uint32_t                    receive_arbitration_id;
     /* message buffer */
     uint8_t*                    receive_buffer;
     uint16_t                    receive_buf_size;
     uint16_t                    receive_size;
     uint16_t                    receive_offset;
     /* multi-frame control */
     uint8_t                     receive_sn;
     uint8_t                     receive_bs_count; /* Maximum number of FC.Wait frame transmissions  */
     uint32_t                    receive_timer_cr; /* Time until transmission of the next ConsecutiveFrame N_PDU
                                                      start at sending FC, receive CF
                                                      end at receive FC */
     int                         receive_protocol_result;
     uint8_t                     receive_status;
 } IsoTpLinkRx_t;


typedef enum {
    CANTP_OFF, CANTP_ON
} CanTp_StateType;


typedef enum {
    CANTP_EXTENDED, CANTP_MIXED, CANTP_MIXED29BIT, CANTP_NORMALFIXED, CANTP_STANDARD
} CanTp_AddressingFormantType;

typedef enum {
    CANTP_FUNCTIONAL, CANTP_PHYSICAL
} CanTp_TaTypeType;

typedef const uint32 CanTp_NSaType;
typedef const uint32 CanTp_NTaType;


typedef struct {
    const CanTp_AddressingFormantType CanTpAddressingMode;
    const PduIdType CanTpNSduIndex;
    const PduIdType CanTpReferringTxIndex;
    const PduIdType CanTpIPduId;
} CanTp_RxIdType;


//missing: sduid, sduref, ae
typedef struct {
    const uint8 CanTpBs;  /* Sets the maximum number of messages of N-PDUs before flow control. */
    const uint16 CanTpNar;  /* Timeout for transmission of a CAN frame (ms). */
    const uint16 CanTpNbr;
    const uint16 CanTpNcr;  /* Time out for consecutive frames (ms). */
    const CanTp_AddressingFormantType CanTpAddressingFormant;
    const CanTp_StateType CanTpRxPaddingActivation;  /* Enable use of padding. */
    const CanTp_TaTypeType CanTpRxTaType;  /* Functional or physical addressing. */
    const uint8 CanTpWftMax;  /* Max number FC wait that can be transmitted consecutively. */
    const uint16 CanTpSTmin;  /* Minimum time the sender shall wait between transmissions of two N-PDU. */
    const CanTp_NSaType *CanTpNSa;
    const CanTp_NTaType *CanTpNTa;


    const PduIdType CanTp_RxLPduId; //for recieving SF, CF, FF through canif
    const PduIdType CanTp_TxFcLPduId; // When recieving this Pdu is used for sending fc frames through canif.
} CanTp_RxNSduType;

//missing: tc, sduid, ae
typedef struct {
    const uint16 CanTpNas;  /* N_As timeout for transmission of any CAN frame. */
    const uint16 CanTpNbs;  /* N_Bs timeout of transmission until reception of next Flow Control. */
    const uint16 CanTpNcs;  /* N_Bs timeout of transmission until reception of next Flow Control. */
    const CanTp_AddressingFormantType CanTpAddressingMode; 
    const CanTp_StateType CanTpTxPaddingActivation;  /* Enable use of padding. */
    const CanTp_TaTypeType CanTpTxTaType;  /* Functional or physical addressing. */
    const CanTp_NSaType CanTpNSa;
    const CanTp_NTaType CanTpNTa;

    const PduIdType CanTp_TxLPduId; //for sending SF, CF, FF through canif
    const PduIdType CanTp_RxFcLPduId; // When sending this Pdu is used for recieving fc frames through canif
} CanTp_TxNSduType; 

typedef enum {
    ISO15765_TRANSMIT, ISO15765_RECEIVE
} CanTp_DirectionType;

typedef enum {
    CANTP_NOT_LAST_ENTRY, CANTP_END_OF_LIST
} CanTp_ListItemType;

typedef struct {
    const CanTp_DirectionType direction;
    const CanTp_ListItemType listItemType;
    union {
        const CanTp_RxNSduType 	CanTpRxNSdu;
        const CanTp_TxNSduType 	CanTpTxNSdu;
    } configData;
    const boolean CanTpFDSupport;
} CanTp_NSduType;

typedef struct {
    const uint32 main_function_period;
    const uint32 number_of_sdus;
    const uint32 number_of_pdus;
    const uint32 pdu_list_size;
    const uint8 padding;
} CanTp_GeneralType; 

typedef struct {
    /** General configuration paramters for the CANTP module. */
    const CanTp_GeneralType *CanTpGeneral; // 10.2.3
    const CanTp_NSduType *CanTpNSduList;
    const CanTp_RxIdType *CanTpRxIdList;
} CanTp_ConfigType;





void StartTimer(TimerType_t timerType, uint8_t time_sec);

void StopTimer(void);

#define WAIT_ST_MIN(time_in_ms)                      StartTimer(ST_MIN_TIMER, time_in_ms)
#define WAIT_FC_FRAME(time_in_ms)                    StartTimer(FC_TIMER, time_in_ms)
#define WAIT_N_CR(time_in_ms)                        StartTimer(N_CR_TIMER, time_in_ms)
#define STOP_TIMER()                                 StopTimer()
/*******************************************************************************************
*                    Shared Global Variables between RX and Tx                             *
********************************************************************************************/
//variable to save the current state of the network layer
extern NetworkLayerStatus_t networkLayerStatus;

// Buffer to save the message received from the upper layer
extern uint8_t dataBuffer[MAX_DATA_LENGTH]; //TODO: buffer should be allocated by upper layer

extern uint16_t byteNumber;

extern uint16_t dataBufferLength;

extern uint8_t remainingBlocks;

extern uint8_t expectedSequenceNumber;

#endif /*__CANTP_TYPES__*/
