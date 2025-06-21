/*

 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "stdint.h"
#include "Dio.h"
#include "Mcu.h"
#include "Port.h"
#include "Fls.h"
#include "Can.h"
#include "CanIf.h"
#include "CanTp.h"
#include "Os.h"

uint8_t transmitFlag;

void ShutdownHook (StatusType error)
{
	Dio_WriteChannel(DioConf_DioChannel_LED_1, STD_LOW);
}

void func(void)
{
	Dio_WriteChannel(DioConf_DioChannel_LED_1, STD_LOW);
}

FUNC(void,CAN_CODE) canErrorNotification( void)
		{
	Dio_WriteChannel(DioConf_DioChannel_LED_5, STD_LOW);
	return;
		}

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

	/* Turn On on board LED4 to indicate App state*/
	Dio_WriteChannel(DioConf_DioChannel_LED_6, STD_LOW);

	init_flags();

	StartOS(OsAppMode_0);                            /* jump to OS startup */


	while(1);
}

TASK(OsTask3_Core0)
{
	uint8_t uds_waitFlag = 0;
	StatusType ret;
	static uint32_t count = 0;

	static uint32_t sleepTime = 100;
	count++;
	if(count == 500)
	{
		count = 0;
	}


	static volatile uint32_t sentFramesCount = 0;

//	uint8_t bytesT[] = {sentFramesCoun+t, 2, 3, 4, 5};
//	sentFramesCount++;
//	Can_PduType CanMessage;
//	CanMessage.length = 5;
//	CanMessage.swPduHandle = 0;
//	CanMessage.id = 0x456;
//	CanMessage.sdu = bytesT;
//	Can_Write(CanHardwareObject_1, &CanMessage);

	Can_MainFunction_Write();
	Can_MainFunction_Read();
	Can_MainFunction_BusOff();
	Can_MainFunction_Mode();

	CanTp_MainFunction();

	ret = SetRelAlarm(task3WakeupAlarm, sleepTime, 0);
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

	for(;;)                                  /* main endless loop */
	{
		ticksBuff = previousTicks;
		ret = GetElapsedValue (SYSTEMTIMER,&ticksBuff, &diff);
		if (diff >= 4000)
		{
			ret = GetCounterValue(SYSTEMTIMER, &previousTicks);
		}
	}

}
