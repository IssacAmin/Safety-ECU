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
 
 void toogleLED(Dio_ChannelType channel)
 {
	 SuspendOSInterrupts();
	 uint8_t currentState = Dio_ReadChannel(channel);
	 if(currentState == STD_LOW)
	 {
		 Dio_WriteChannel(channel, STD_HIGH);
	 }
	 else if(currentState = STD_HIGH)
	 {
		 Dio_WriteChannel(channel, STD_LOW);
	 }
	 ResumeOSInterrupts();
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
	 CanMessage.swPduHandle = UDS_PDU_ID;
	 CanMessage.id = UDS_PDU_ID;
 
	 CanMessage.sdu = ff;
 
	 Can_Write(CanHardwareObject_1, &CanMessage);
	 transmitFlag = 1;
 
	 while(transmitFlag)
	 {
		 Can_MainFunction_Write();
		 Can_MainFunction_Read();
	 }
 
	 CanMessage.length = 8;
	 CanMessage.swPduHandle = UDS_PDU_ID;
	 CanMessage.id = UDS_PDU_ID;
 
	 CanMessage.sdu = cf1;
 
	 Can_Write(CanHardwareObject_1, &CanMessage);
	 transmitFlag = 1;
	 while(transmitFlag)
	 {
		 Can_MainFunction_Write();
		 Can_MainFunction_Read();
	 }
 
 
	 CanMessage.length = 8;
	 CanMessage.swPduHandle = UDS_PDU_ID;
	 CanMessage.id = UDS_PDU_ID;
 
	 CanMessage.sdu = cf2;
 
	 Can_Write(CanHardwareObject_1, &CanMessage);
	 transmitFlag = 1;
	 while(transmitFlag)
	 {
		 Can_MainFunction_Write();
		 Can_MainFunction_Read();
	 }
 
 
	 CanMessage.length = 8;
	 CanMessage.swPduHandle = UDS_PDU_ID;
	 CanMessage.id = UDS_PDU_ID;
 
	 CanMessage.sdu = cf3;
 
	 Can_Write(CanHardwareObject_1, &CanMessage);
	 transmitFlag = 1;
 
	 while(transmitFlag)
	 {
		 Can_MainFunction_Write();
		 Can_MainFunction_Read();
	 }
	 CanMessage.length = 8;
	 CanMessage.swPduHandle = UDS_PDU_ID;
	 CanMessage.id = UDS_PDU_ID;
 
	 CanMessage.sdu = cf4;
 
	 Can_Write(CanHardwareObject_1, &CanMessage);
	 transmitFlag = 1;
	 while(transmitFlag)
	 {
		 Can_MainFunction_Write();
		 Can_MainFunction_Read();
	 }
 
	 CanMessage.length = 8;
	 CanMessage.swPduHandle = UDS_PDU_ID;
	 CanMessage.id = UDS_PDU_ID;
 
	 CanMessage.sdu = cf5;
 
	 Can_Write(CanHardwareObject_1, &CanMessage);
	 transmitFlag = 1;
	 while(transmitFlag)
	 {
		 Can_MainFunction_Write();
		 Can_MainFunction_Read();
	 }
 
	 CanMessage.length = 8;
	 CanMessage.swPduHandle = UDS_PDU_ID;
	 CanMessage.id = UDS_PDU_ID;
 
	 CanMessage.sdu = cf6;
 
	 Can_Write(CanHardwareObject_1, &CanMessage);
	 transmitFlag = 1;
	 while(transmitFlag)
	 {
		 Can_MainFunction_Write();
		 Can_MainFunction_Read();
	 }
 
	 CanMessage.length = 7;
	 CanMessage.swPduHandle = UDS_PDU_ID;
	 CanMessage.id = UDS_PDU_ID;
 
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
 
	 uint8_t fc[]= {0x30, 0x0A, 0x01};
 
	 Can_PduType CanMessage;
	 CanMessage.length = 3;
 
	 CanMessage.swPduHandle = UDS_PDU_ID;
	 CanMessage.id = UDS_PDU_ID;
	 CanMessage.sdu = fc;
 
	 Can_Write(CanHardwareObject_1, &CanMessage);
 }
 
 FUNC(void,CAN_CODE) canErrorNotification( void)
																								 {
	 Dio_WriteChannel(DioConf_DioChannel_LED_5, STD_LOW);
	 return;
																								 }
 void (*ptr_to_bootloader)(void);
 void (*ptr_to_flashbank_A)(void);
 void (*ptr_to_flashbank_B)(void);
 
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
 
	 //	testcantpSenderWithCanFrames();
 
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
 
 TASK(OsTask_Core0)
 {
	 StatusType ret;
 
	 int counter = 0;
 
	 testcantpSenderWithCanFrames();
 
	 for(;;)                                  /* main endless loop */
	 {
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
 