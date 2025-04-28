/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "BootLoader_cfg.h"
#include <stdint.h>
#include "flags.h"
#include "Dio.h"
#include "Fls.h"
#include "Mcu.h"
#include "Port.h"
#include "Can.h"
#include "Os.h"
#include "Os_cfg.h"
#include "UDS_utils.h"
#include "uds_server.h"
#include "sessionCtrl_bootloader_util.h"
#include "CanTp.h"
#include "CanIf.h"

uint8_t transmitFlag = 0;
uint8_t alarmFlag = 0;

uint8_t togglesCount = 0;

#define UDS_TX_NPDUID 0
#define UDS_RX_NPDUID 1

void sendCanMessageBlocking(Can_PduType *CanMessagePtr)
{
	Can_Write(CanHardwareObject_1, CanMessagePtr);
	transmitFlag = 1;

	while(transmitFlag)
	{
		Can_MainFunction_Write();
		Can_MainFunction_Read();
	}
}

void testFlashingSequenceWithCanFrames(void)
{
	uint8_t sessctrl[] = {0x02, 0x10, 0x01};
	uint8_t reqDownload[] = {0x10, 0x0B, 0x34, 0x01, 0x44, 0x00, 0x00, 0x00};
	uint8_t reqDownload1[] = {0x21, 0x00, 0x00, 0x00, 0x06, 0x07};
	uint8_t trans11[] = {0x10, 0x0B, 0x36, 0x01, 0x11, 0x00, 0x00, 0x01};
	uint8_t trans12[] = {0x21, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00};

	uint8_t * progSessionFrames[] = {
			sessctrl,
			reqDownload,
			reqDownload1,
			trans11,
			trans12
	};

	uint8_t lengths[] = {
			sizeof(sessctrl),
			sizeof(reqDownload),
			sizeof(reqDownload1),
			sizeof(trans11),
			sizeof(trans12)
	};

	for (int i = 0; i<5; i++)
	{
		Can_PduType CanMessage;
		CanMessage.length = lengths[i];
		CanMessage.swPduHandle = 0;
		CanMessage.id = 1;
		CanMessage.sdu = progSessionFrames[i];
		sendCanMessageBlocking(&CanMessage);
	}
}


void testFlashingSequenceWithUdsPayloads(void)
{
	uint8_t sess[] ={0x10,0x01};
	uint8_t req[] = {0x34,0x01,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9B};
	uint8_t trans1[] = {0x36,0x01,0x11,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0x00};
	uint8_t trans2[] = {0x36,0x02,0x00,0x00,0x00,0x48,0x00,0x00,0x00,0x00,0x80,
			0x18,0x21,0x06,0xE0,0x00,0x80,0xD9,0x01,0xD7,0xF1,0x01,0x1F,0x79
			,0xFF,0xE5,0x7D,0x70,0xE0,0xE1,0x00,0x1C,0x67,0x4E,0xA4,0x79,0xFF,
			0xE8,0xA9,0x48,0x03,0x79,0xFF,0xEA,0x0B,0x70,0xE0,0xE1,0x00,0x1C,
			0x67,0x59,0x40,0x79,0xFF,0xFB,0xC3,0x48,0x73,0x48,0x14,0x79,0xFF,
			0xE6,0x37,0x70,0xE0,0xE0,0x0F,0x70,0xE8,0xC2,0x40,0xD2,0x7F,0x44,
			0x00,0xC2,0x7F,0x18,0xC7,0x84,0xFF,0xD2,0x6F,0x2A,0x07,0x7F,0x80,
			0x00,0x20,0x7C,0xE0,0x00,0x26,0x74,0xE7,0xE0,0x07,0x7C,0xE8,0x01,
			0x20,0x7A,0x02,0xFF,0xE6,0x48,0x73,0x48,0x04,0x79,0xFF,0xE6,0x05
			,0x70,0xE0,0xE0,0x0F,0x70,0xE8,0xC2,0x40,0xD2,0x7F,0x44,0x00,0xC2
			,0x7F,0x18,0xC7,0x84,0xFF,0xD2,0x6F,0x2A,0x07,0x7F,0x80};

	uint8_t trans3[] = {0x36,0x03,0x11,0x00,0x00,0x48,0x80,0x00,0x00,0x11,0x80};
	uint8_t transExit[] = {0x37};

	uint8_t writeDid1[] = {0x2E,0x00,0x00,0x01};

	uint8_t writeDid2[] = {0x2E,0x00,0x01,0x00,0x00,0x01,0x02,0x10,0x01};

	PduInfoType info;
	info.SduDataPtr = sess;
	info.SduLength = sizeof(sess);
	PduR_CantpReception(1, &info);

	info.SduDataPtr = req;
	info.SduLength = sizeof(req);
	PduR_CantpReception(1, &info);


	info.SduDataPtr = trans1;
	info.SduLength = sizeof(trans1);
	PduR_CantpReception(1, &info);


	info.SduDataPtr = trans2;
	info.SduLength = sizeof(trans2);
	PduR_CantpReception(1, &info);

	info.SduDataPtr = trans3;
	info.SduLength = sizeof(trans3);
	PduR_CantpReception(1, &info);

	info.SduDataPtr = transExit;
	info.SduLength = sizeof(transExit);
	PduR_CantpReception(1, &info);

	info.SduDataPtr = writeDid1;
	info.SduLength = sizeof(writeDid1);
	PduR_CantpReception(1, &info);

	info.SduDataPtr = writeDid2;
	info.SduLength = sizeof(writeDid2);
	PduR_CantpReception(1, &info);
}
void testcantpRecieverWithCanFrames(void)
{
	char ff []= {0x10, 0x35, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06};
	char cf1[]= {0x21, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D};
	char cf2[]= {0x22, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14};
	char cf3[]= {0x23, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B};
	char cf4[]= {0x24, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22};
	char cf5[]= {0x25, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29};
	char cf6[]= {0x26, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30};
	char cf7[]= {0x27, 0x31, 0x32, 0x33, 0x34, 0x35};

	Can_PduType CanMessage;
	CanMessage.length = 8;
	CanMessage.swPduHandle = 0;
	CanMessage.id = 0;

	CanMessage.sdu = ff;

	Can_Write(CanHardwareObject_1, &CanMessage);
	transmitFlag = 1;

	while(transmitFlag)
	{
		Can_MainFunction_Write();
		Can_MainFunction_Read();
	}

	CanMessage.length = 8;
	CanMessage.swPduHandle = 0;
	CanMessage.id = 0;

	CanMessage.sdu = cf1;

	Can_Write(CanHardwareObject_1, &CanMessage);
	transmitFlag = 1;
	while(transmitFlag)
	{
		Can_MainFunction_Write();
		Can_MainFunction_Read();
	}


	CanMessage.length = 8;
	CanMessage.swPduHandle = 0;
	CanMessage.id = 0;

	CanMessage.sdu = cf2;

	Can_Write(CanHardwareObject_1, &CanMessage);
	transmitFlag = 1;
	while(transmitFlag)
	{
		Can_MainFunction_Write();
		Can_MainFunction_Read();
	}


	CanMessage.length = 8;
	CanMessage.swPduHandle = 0;
	CanMessage.id = 0;

	CanMessage.sdu = cf3;

	Can_Write(CanHardwareObject_1, &CanMessage);
	transmitFlag = 1;

	while(transmitFlag)
	{
		Can_MainFunction_Write();
		Can_MainFunction_Read();
	}
	CanMessage.length = 8;
	CanMessage.swPduHandle = 0;
	CanMessage.id = 0;

	CanMessage.sdu = cf4;

	Can_Write(CanHardwareObject_1, &CanMessage);
	transmitFlag = 1;
	while(transmitFlag)
	{
		Can_MainFunction_Write();
		Can_MainFunction_Read();
	}

	CanMessage.length = 8;
	CanMessage.swPduHandle = 0;
	CanMessage.id = 0;

	CanMessage.sdu = cf5;

	Can_Write(CanHardwareObject_1, &CanMessage);
	transmitFlag = 1;
	while(transmitFlag)
	{
		Can_MainFunction_Write();
		Can_MainFunction_Read();
	}

	CanMessage.length = 8;
	CanMessage.swPduHandle = 0;
	CanMessage.id = 0;

	CanMessage.sdu = cf6;

	Can_Write(CanHardwareObject_1, &CanMessage);
	transmitFlag = 1;
	while(transmitFlag)
	{
		Can_MainFunction_Write();
		Can_MainFunction_Read();
	}

	CanMessage.length = 7;
	CanMessage.swPduHandle = 0;
	CanMessage.id = 0;

	CanMessage.sdu = cf7;

	Can_Write(CanHardwareObject_1, &CanMessage);
	transmitFlag = 1;
	while(transmitFlag)
	{
		Can_MainFunction_Write();
		Can_MainFunction_Read();
	}
}

char data[] = {
		0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A,
		0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14,
		0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E,
		0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
		0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32,
		0x33, 0x34, 0x35};

void testcantpSenderWithCanFrames(void)
{

	PduInfoType PduInfo =
	{
			.SduDataPtr = data,
			.SduLength = 0x35
	};

	CanTp_Transmit(0, &PduInfo);

	//	 uint8_t fc[]= {0x30, 0x0A, 0x01};
	//
	//	 Can_PduType CanMessage;
	//	 CanMessage.length = 3;
	//
	//	 CanMessage.swPduHandle = 0;
	//	 CanMessage.id = 0;
	//	 CanMessage.sdu = fc;
	//
	//	 Can_Write(CanHardwareObject_1, &CanMessage);
}

FUNC(void,CAN_CODE) canErrorNotification( void)
																																												 {
	Dio_WriteChannel(DioConf_DioChannel_LED_5, STD_LOW);
	return;
																																												 }
void (*ptr_to_bootloader)(void);
void (*ptr_to_flashbank_A)(void) ;
void (*ptr_to_flashbank_B)(void) = 0x1200000;

int main(void)
{
	/*Initialize Core Peripherals */
	Mcu_Init(&McuModuleConfiguration);

	Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_0);

	Port_Init(&PortConfigSet);

	Fls_Init(&FlsConfigSet);

	//TODO: move to canif
	Can_Init(&CanConfigSet0);

	CanIf_Init(&CanIf_Config_Test);

	CanTp_Init(&canTpCfgTest);

	Std_ReturnType canRet;

	Can_DisableControllerInterrupts(0);

	Can_ControllerStateType controllerState;

	canRet = Can_GetControllerMode(0, &controllerState);

	canRet = Can_SetControllerMode(0,CAN_CS_STARTED);

	canRet = Can_GetControllerMode(0, &controllerState);

	/* Turn On on board LED2 to indicate Boot Loader state*/
	Dio_WriteChannel(DioConf_DioChannel_LED_3, STD_LOW);

	//	 	testcantpSenderWithCanFrames();

	set_BootLoader_ActiveFlag();

	//	testFlashingSequenceWithCanFrames();

//	testFlashingSequenceWithUdsPayloads();
//
//	ptr_to_flashbank_B();
	StartOS(OsAppMode_0);                            /* jump to OS startup */

	/* Loop forever */
	for(;;) {
	}
}

void func(void)
{
	volatile uint32_t i = 100000;
	while(i--);
}

void ShutdownHook (StatusType error)
{
	Dio_WriteChannel(DioConf_DioChannel_LED_1, STD_LOW);
}


uint8_t UDS_sendResponse(UDS_RES_t *response)
{
	PduInfoType PduInfo;

	//TODO: add application layer addressing info to data payload
	PduInfo.SduDataPtr = response->data;
	PduInfo.SduLength = response->udsDataLen;
	//	CanTp_Transmit(UDS_TX_NPDUID, &PduInfo);

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
		UDS_RequestIndication(&req);
		UDS_mainFunction();
	}
}


TASK(OsTask_Core0)
{
	StatusType ret;

	int counter = 0;
	uint8_t bytesT[] = {1, 2, 3};

	testcantpSenderWithCanFrames();
	//	 testcantpRecieverWithCanFrames();

	for(;;)                                  /* main endless loop */
	{
		Can_PduType CanMessage;
		CanMessage.length = 3;
		CanMessage.swPduHandle = 0;
		CanMessage.id = 1;
		CanMessage.sdu = bytesT;
		sendCanMessageBlocking(&CanMessage);

		Dio_FlipChannel(DioConf_DioChannel_LED_6);
		UDS_mainFunction();

		Can_MainFunction_Write();
		Can_MainFunction_Read();
		Can_MainFunction_BusOff();
		Can_MainFunction_Mode();

		CanTp_MainFunction();

		volatile uint32_t i = 100000;
		while(i--); //OS enters into machine check exception without this delay
	}
}

