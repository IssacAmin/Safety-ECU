/*
 * udsIf.c
 *
 *  Created on: May 14, 2025
 *      Author: Fady
 */

#include "CanTp.h"

#define UDS_TX_NPDUID 0
#define UDS_RX_NPDUID 1

uint8_t UDS_sendResponse(UDS_RES_t *response)
{
	PduInfoType PduInfo;

	//TODO: add application layer addressing info to data payload
	PduInfo.SduDataPtr = response->data;
	PduInfo.SduLength = response->udsDataLen;
	CanTp_Transmit(UDS_TX_NPDUID, &PduInfo);
	WaitEvent(canTpTxConfirmationEvent);
	ClearEvent(canTpTxConfirmationEvent);
	return 1;
}

void PduR_CantpReception(PduIdType NPduId, PduInfoType* info)
{
	//decide the upper layer based on the NPduId
	if(1 == NPduId)
	{
		UDS_REQ_t req;
		req.data = info->SduDataPtr;
		req.udsDataLen = info->SduLength;
		req.msgType = UDS_MType_Diagnostics;
		req.trgAddType = UDS_A_TA_PHYSICAL;
		req.srcAdd = 0x55;
		req.trgAdd = 0xAA;
		req.status = UDS_REQUEST_STATUS_NOT_SERVED;
		UDS_RequestIndication(&req);
	}
}

