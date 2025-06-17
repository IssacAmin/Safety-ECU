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

uint8_t transmitFlag;

uint8_t canTpTxConfirmationFlag = 1;

FUNC(void,CAN_CODE) canErrorNotification( void)
																{
	Dio_WriteChannel(DioConf_DioChannel_LED_5, STD_LOW);
	return;
																}

void UDS_setSecurityLvlAfterProgSessionReset(UDS_SecurityLevel_t* lvlRecord);

static void BL_InitUDS(void)
{
	/*UDS Set up*/
	/*Initialize The server*/
	UDS_serverInit();

	/*Is there a programming session request pending ?*/
	if(read_flags(PROGRAMMING_SESSION))
	{

		/*Force The Security Level*/
		/*get the last security level*/
		uint8_t uds_secLvl = read_flags(UDS_LAST_SECURITY_LEVEL);
		/*get level record structure*/
		UDS_SecurityLevel_t *securityLvlRecord = (UDS_SecurityLevel_t*)UDS_BinaryID_Search(securityLevels,sizeof(UDS_SecurityLevel_t),UDS_NUMBER_OF_SECURITY_LEVELS,&(uds_secLvl),1);
		if(NULL != securityLvlRecord)
		{
			UDS_setSecurityLvlAfterProgSessionReset(securityLvlRecord);
			uint8_t progSessReq[] = {0x10,0x2};
			UDS_REQ_t req;
			req.data = &progSessReq;
			req.udsDataLen = 2;
			/*meta data should be checked*/
			req.msgType = UDS_MType_Diagnostics;
			req.trgAddType = UDS_A_TA_PHYSICAL;
			req.srcAdd = 0x55;
			req.trgAdd = 0xAA;
			req.status = UDS_REQUEST_STATUS_NOT_SERVED;
			UDS_RequestIndication(&req);
//			UDS_mainFunction();
		}
		modify_flag(PROGRAMMING_SESSION,FLAG_CLEAR);
		modify_flag(UDS_LAST_SECURITY_LEVEL,SECURITY_LVL_DEFAULT_ID);
	}
}

void (*ptr_to_bootloader)(void);
void (*ptr_to_flashbank_A)(void);
void (*ptr_to_flashbank_B)(void) = 0x1200000;

uint32_t x = 1000;
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

	init_flags();
	/*Set the bootloader flag for the UDS*/
	set_BootLoader_ActiveFlag();

	BL_InitUDS();

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


TASK(OsTask3_Core0)
{
	uint8_t uds_waitFlag = 0;
	StatusType ret;
	static uint32_t count = 0;

	//	CancelAlarm(task3WakeupAlarm);

	count++;
	if(count == 500)
	{
		count = 0;
		Dio_FlipChannel(DioConf_DioChannel_LED_4);
	}

//	uint8_t bytesT[] = {1, 2, 3, 4, 5, 6, 7, 8};
//	Can_PduType CanMessage;
//	CanMessage.length = 8;
//	CanMessage.swPduHandle = 0;
//	CanMessage.id = 0x456;
//	CanMessage.sdu = bytesT;
//	Can_Write(CanHardwareObject_1, &CanMessage);

	Can_MainFunction_Write();
	Can_MainFunction_Read();
	Can_MainFunction_BusOff();
	Can_MainFunction_Mode();

	CanTp_MainFunction();

	ret = SetRelAlarm(task3WakeupAlarm, 2000, 0);
	ret = TerminateTask();
}
TASK(OsTask2_Core0)
{
	uint8_t uds_waitFlag = 0;
	StatusType ret;
	static uint32_t count = 0;
	uint32_t sleepTime = 0;
	while(1)
	{
		count++;
		if(count == 500)
		{
			count = 0;
			Dio_FlipChannel(DioConf_DioChannel_LED_5);
		}

		uds_waitFlag = UDS_mainFunction();

		if(uds_waitFlag)
		{
			uds_waitFlag = 0;
			sleepTime = 100;
		}
		else
		{
			sleepTime = 20;
		}

		ret = SetRelAlarm(task2WakeupAlarm, sleepTime, 0);
		ret = TerminateTask();
	}
}

TASK(OsTask_Core0)
{
	StatusType ret;

	static TickType previousTicks = 0;
	TickType diff, ticksBuff;

	//	testcantpSenderWithCanFrames();
	//	 testcantpRecieverWithCanFrames();

	bool sendVar = false;
	for(;;)                                  /* main endless loop */
	{
		//		if(sendVar == true){
		//		}

		ticksBuff = previousTicks;
		ret = GetElapsedValue (SYSTEMTIMER,&ticksBuff, &diff);
		if (diff >= 4000)
		{
			ret = GetCounterValue(SYSTEMTIMER, &previousTicks);
			Dio_FlipChannel(DioConf_DioChannel_LED_6);
		}

		BLUtil_mainFunction();

	}

}


