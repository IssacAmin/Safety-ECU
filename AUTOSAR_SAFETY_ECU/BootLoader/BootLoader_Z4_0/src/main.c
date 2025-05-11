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
#include "UDS_utils.h"
#include "uds_server.h"
#include "sessionCtrl_bootloader_util.h"
#include "CanTp.h"
#include "CanIf.h"

#define UDS_TX_NPDUID 0
#define UDS_RX_NPDUID 1

FUNC(void,CAN_CODE) canErrorNotification( void)
{
	Dio_WriteChannel(DioConf_DioChannel_LED_5, STD_LOW);
	return;
}

void (*ptr_to_bootloader)(void);
void (*ptr_to_flashbank_A)(void);
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

	/* Turn On on board LED3 to indicate Boot Loader state*/
	Dio_WriteChannel(DioConf_DioChannel_LED_3, STD_LOW);

	//	 	testcantpSenderWithCanFrames();

	/*UDS Set up*/
	UDS_serverInit();
	set_BootLoader_ActiveFlag();
	uint8_t progSessReq[] = {0x10,0x1};
	UDS_REQ_t req;
	req.data = &progSessReq;
	req.udsDataLen = 2;
	req.msgType = UDS_MType_Diagnostics;
	req.trgAddType = UDS_A_TA_PHYSICAL;
	req.srcAdd = 0x55;
	req.trgAdd = 0xAA;
	req.status = UDS_REQUEST_STATUS_NOT_SERVED;
	UDS_RequestIndication(&req);
	UDS_mainFunction();


	//	testFlashingSequenceWithCanFrames();

	//	testFlashingSequenceWithUdsPayloads();
	//
	//	ptr_to_flashbank_B();
	StartOS(OsAppMode_0);                            /* jump to OS startup */

	/* Loop forever */
	for(;;) {
	}
}

void ShutdownHook (StatusType error)
{
	Dio_WriteChannel(DioConf_DioChannel_LED_1, STD_LOW);
}

void func(void)
{
	Dio_WriteChannel(DioConf_DioChannel_LED_1, STD_LOW);
}


uint8_t UDS_sendResponse(UDS_RES_t *response)
{
	PduInfoType PduInfo;

	//TODO: add application layer addressing info to data payload
	PduInfo.SduDataPtr = response->data;
	PduInfo.SduLength = response->udsDataLen;
	CanTp_Transmit(UDS_TX_NPDUID, &PduInfo);
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

TASK(OsTask2_Core0)
{
	StatusType ret;
	static uint32_t count = 0;

	count++;
	if(count == 500)
	{
		count = 0;
		Dio_FlipChannel(DioConf_DioChannel_LED_5);
	}

	UDS_mainFunction();

	Can_MainFunction_Write();
	Can_MainFunction_Read();
	Can_MainFunction_BusOff();
	Can_MainFunction_Mode();

	CanTp_MainFunction();

	UDSUtils_MainFunction();

	ret = SetRelAlarm(task2WakeupAlarm, 8, 0);
	ret = TerminateTask();
	/*should never get here*/
	while(1);
}

TASK(OsTask_Core0)
{
	StatusType ret;
	uint8_t bytesT[] = {1, 2, 3};

	static TickType previousTicks = 0;
	TickType diff, ticksBuff;

	//	testcantpSenderWithCanFrames();
	//	 testcantpRecieverWithCanFrames();

	bool sendVar = false;
	for(;;)                                  /* main endless loop */
	{
		//		if(sendVar == true){
		//			Can_PduType CanMessage;
		//			CanMessage.length = 3;
		//			CanMessage.swPduHandle = 0;
		//			CanMessage.id = 1;
		//			CanMessage.sdu = bytesT;
		//			Can_Write(CanHardwareObject_1, &CanMessage);
		//		}

		ticksBuff = previousTicks;
		ret = GetElapsedValue (SYSTEMTIMER,&ticksBuff, &diff);
		if (diff >= 4000)
		{
			ret = GetCounterValue(SYSTEMTIMER, &previousTicks);
			Dio_FlipChannel(DioConf_DioChannel_LED_6);
		}
		

		//check for incoming messages
		
	}
}


void flsWaitUntilJobDone(void)
{
	Fls_MainFunction();
	while(Fls_GetJobResult() == MEMIF_JOB_PENDING)
	{
		Fls_MainFunction();
	}
}
