/*

 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "BootManager_cfg.h"
#include "stdint.h"
#include "flags.h"
#include "Dio.h"
#include "Fls.h"
#include "Mcu.h"
#include "Port.h"
#include "crc.h"



#define FLAGS_SECTOR_SIZE 16384
/* variables initialization and extracting flags from memory */
uint8_t app_sector_buffer[SECTOR_SIZE]  __attribute__((section(".appSectorBuffer")));
extern uint32_t flags_section[];
void (*ptr_to_bootloader)(void);
void (*ptr_to_flashbank_A)(void);
void (*ptr_to_flashbank_B)(void);

void flsWaitUntilJobDone(void);


int main(void)
{
	/*Initialize Core Peripherals */
	Mcu_Init(&McuModuleConfiguration);

	Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_0);

	Fls_Init(&FlsConfigSet);

	Port_Init(&PortConfigSet);

	Std_ReturnType fls_ret;
	MemIf_JobResultType jobResult;
	meta_data meta_data_instance;

	/*TODO*/
	flags flags_instance = {
			.programming_session = 0,
			.current_app = 0,
			.flashbank_A_valid = 1,
			.flashbank_B_valid = 0,
			.flashing_in_progress = 0,
			.reset_during_flash = 0,
	};

	fls_ret = Fls_Erase(0, FLAGS_SECTOR_SIZE);
	flsWaitUntilJobDone();
	jobResult = Fls_GetJobResult();

	fls_ret = Fls_Write(FLAGS , &flags_instance, QUAD_PAGE_SIZE);
	flsWaitUntilJobDone();
	jobResult = Fls_GetJobResult();
	/* Turn On on board LED1 to indicate Boot Manager state*/

	Dio_WriteChannel(DioConf_DioChannel_LED_1, STD_LOW);

	/* Initialize pointers to BL and APP */
	ptr_to_bootloader 	= (func_ptr_t) BOOTLOADER_RESET_VECTOR_ADDRESS;
	ptr_to_flashbank_A	= (func_ptr_t) FLASHBANK_A_ENTRY_POINT;
	ptr_to_flashbank_B	= (func_ptr_t) FLASHBANK_B_ENTRY_POINT;

	uint32_t meta_data;
	uint16_t computed_crc;
	uint32_t app_length;

	fls_ret = Fls_Read(FLAGS, &flags_instance, QUAD_PAGE_SIZE);
	flsWaitUntilJobDone();

	if(flags_instance.flashing_in_progress)
	{
		flags_instance.reset_during_flash = 1;

		fls_ret = Fls_Erase(FLAGS, FLAGS_SECTOR_SIZE);
		flsWaitUntilJobDone();

		fls_ret = Fls_Write(FLAGS , &flags_instance, QUAD_PAGE_SIZE);
		flsWaitUntilJobDone();
	}

	/* Jump to BL if programming_session flag is set or current APP is invalid*/
	if(flags_instance.programming_session)
	{
		/*Shouldnt we reset the flag ?*/
		Dio_WriteChannel(DioConf_DioChannel_LED_1, STD_HIGH);
		ptr_to_bootloader();
	}
	else
	{
		/* jump to boot loader if APP is invalid */
		if(flags_instance.current_app == 0){
			if(!flags_instance.flashbank_A_valid)
			{
				Dio_WriteChannel(DioConf_DioChannel_LED_1, STD_HIGH);
				ptr_to_bootloader();
			}
		}else{
			if(!flags_instance.flashbank_B_valid)
			{
				Dio_WriteChannel(DioConf_DioChannel_LED_1, STD_HIGH);
				ptr_to_bootloader();
			}
		}

		/*Check app validity*/

		uint32_t currentFlashBankStartAddress = FLASHBANK_A_LOGICAL_ADDRESS_SECTOR_1;
		bool valid_crc = false;

		if(flags_instance.current_app == 0)
		{
			currentFlashBankStartAddress = FLASHBANK_A_LOGICAL_ADDRESS_SECTOR_1;
		}
		else
		{
			currentFlashBankStartAddress = FLASHBANK_B_LOGICAL_ADDRESS_SECTOR_1;
		}

		fls_ret = Fls_Read((currentFlashBankStartAddress + FLASHBANK_SIZE - QUAD_PAGE_SIZE),&meta_data_instance , QUAD_PAGE_SIZE);
		flsWaitUntilJobDone();

		uint32_t app_length = meta_data_instance.app_length;
		uint16_t stored_crc = meta_data_instance.crc_ccitt;

		valid_crc = memory_check(currentFlashBankStartAddress, app_length, stored_crc, app_sector_buffer);

		if(!valid_crc){
			/* Invalidate the flash bank due to invalid CRC */
			if(flags_instance.current_app == 0){
				flags_instance.flashbank_A_valid = 0;
			}else{
				flags_instance.flashbank_B_valid = 0;
			}

			fls_ret = Fls_Erase(FLAGS, FLAGS_SECTOR_SIZE);
			flsWaitUntilJobDone();

			fls_ret = Fls_Write(FLAGS , &flags_instance, QUAD_PAGE_SIZE);
			flsWaitUntilJobDone();

			Dio_WriteChannel(DioConf_DioChannel_LED_1, STD_HIGH);
			ptr_to_bootloader();

		}else{
			if(flags_instance.current_app == 0){
				Dio_WriteChannel(DioConf_DioChannel_LED_1, STD_HIGH);
				ptr_to_flashbank_A();
			}else{
				Dio_WriteChannel(DioConf_DioChannel_LED_1, STD_HIGH);
				ptr_to_flashbank_B();
			}
		}
	}
	/* Loop forever */
	for(;;) {
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
