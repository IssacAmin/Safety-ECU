#include "CanTp_Types.h"



CanTp_RxIdType CanTpRxIdListTest[] =
{
    {
        .CanTpNSduIndex = 0, 
        .CanTpIPduId = 0
    },

    {
        .CanTpNSduIndex = 1, 
        .CanTpIPduId = 1
    }
};

//sorted by NSduId
CanTp_NSduType CanTpNSduConfigList[] =
{
    {
        .direction = ISO15765_TRANSMIT,
        .configData.CanTpTxNSdu.CanTp_RxFcLPduId = 0,
        .configData.CanTpTxNSdu.CanTp_TxLPduId = 0,
        .configData.CanTpTxNSdu.CanTpAddressingMode = CANTP_STANDARD,
        .configData.CanTpTxNSdu.CanTpNas = 2,
        .configData.CanTpTxNSdu.CanTpNbs = 2,
        .configData.CanTpTxNSdu.CanTpNcs = 2,
        .configData.CanTpTxNSdu.CanTpTxPaddingActivation = CANTP_ON,
        .configData.CanTpTxNSdu.CanTpTxTaType = CANTP_PHYSICAL,
        .configData.CanTpTxNSdu.CanTpNSa = 0x55,
        .configData.CanTpTxNSdu.CanTpNTa = 0xAA
    },

    {
        .direction = ISO15765_RECEIVE,
        .configData.CanTpRxNSdu.CanTp_RxLPduId = 0,
        .configData.CanTpRxNSdu.CanTp_TxFcLPduId = 0,
        .configData.CanTpRxNSdu.CanTpAddressingFormant = CANTP_STANDARD,
        .configData.CanTpRxNSdu.CanTpBs = 30,
        .configData.CanTpRxNSdu.CanTpNar = 5000,
        .configData.CanTpRxNSdu.CanTpNbr = 1000,
        .configData.CanTpRxNSdu.CanTpNcr = 1000,
        .configData.CanTpRxNSdu.CanTpRxPaddingActivation = CANTP_ON,
        .configData.CanTpRxNSdu.CanTpRxTaType = CANTP_FUNCTIONAL,
        .configData.CanTpRxNSdu.CanTpWftMax = 5,
        .configData.CanTpRxNSdu.CanTpSTmin = 0,
        .configData.CanTpRxNSdu.CanTpNSa = 0xAA,
        .configData.CanTpRxNSdu.CanTpNTa = 0x55
    }
};

CanTp_GeneralType CanTpGeneralTest = 
{
    .pdu_list_size = 2
};

CanTp_ConfigType canTpCfgTest = {
    .CanTpNSduList = CanTpNSduConfigList, 
    .CanTpRxIdList = CanTpRxIdListTest, 
    .CanTpGeneral = &CanTpGeneralTest
};
