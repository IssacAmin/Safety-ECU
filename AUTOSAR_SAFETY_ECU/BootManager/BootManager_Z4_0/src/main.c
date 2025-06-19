/*

 * main implementation: use this 'C' sample to create your own application
 *
 */

#include <flashbankConfig.h>
#include "derivative.h" /* include peripheral declarations */
#include "stdint.h"
#include "flags.h"
#include "Dio.h"
#include "Fls.h"
#include "Mcu.h"
#include "Port.h"
#include "UDS_utils.h"



#define FLAGS_SECTOR_SIZE 16384
/* variables initialization and extracting flags from memory */
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

	flags flags_instance;
	//TODO: use the fucking utils
	fls_ret = Fls_Read(FLAGS, &flags_instance, QUAD_PAGE_SIZE);
	flsWaitUntilJobDone();

	/* Turn On on board LED1 to indicate Boot Manager state*/
	Dio_WriteChannel(DioConf_DioChannel_LED_1, STD_LOW);

	/* Initialize pointers to BL and APP */
	ptr_to_bootloader 	= (func_ptr_t) BOOTLOADER_RESET_VECTOR_ADDRESS;
	ptr_to_flashbank_A	= (func_ptr_t) FLASHBANK_A_ENTRY_POINT;
	ptr_to_flashbank_B	= (func_ptr_t) FLASHBANK_B_ENTRY_POINT;

	if(flags_instance.bootLoader_update_request)
	{
		UDS_Utils_ReturnType ret;
		ret = updateBootloader(&flags_instance);
	}

	//TODO: eh da????
	if(flags_instance.flashing_in_progress)
	{
		/*TODO: there should be another action here jump to bootloader? notify and log error? eh elklam*/
		//TODO: use modify flag
		flags_instance.reset_during_flash = 1;
		flags_instance.flashing_in_progress = 0;

		fls_ret = Fls_Erase(FLAGS, FLAGS_SECTOR_SIZE);
		flsWaitUntilJobDone();

		fls_ret = Fls_Write(FLAGS , &flags_instance, QUAD_PAGE_SIZE);
		flsWaitUntilJobDone();
	}
	else
	{
		Dio_WriteChannel(DioConf_DioChannel_LED_1, STD_HIGH);
		/* Jump to BL if programming_session flag is set or current APP is invalid*/
		if(flags_instance.programming_session)
		{
			ptr_to_bootloader();
		}
		else
		{
			if(flags_instance.current_app == 0)
			{
				if(flags_instance.flashbank_A_valid)
				{
					validate_flashbank(PRIMARY_APP,&flags_instance);
					fls_ret = Fls_Write(FLAGS , &flags_instance, QUAD_PAGE_SIZE);
					flsWaitUntilJobDone();
					if(flags_instance.flashbank_A_valid == 1U)
					{
						ptr_to_flashbank_A();
					}
				}
				else if(flags_instance.flashbank_B_valid)
				{
					validate_flashbank(SECONDARY_APP,&flags_instance);
					if(flags_instance.flashbank_B_valid == 1U)
					{
						flags_instance.current_app = 1;
						fls_ret = Fls_Write(FLAGS , &flags_instance, QUAD_PAGE_SIZE);
						flsWaitUntilJobDone();
						ptr_to_flashbank_B();
					}
				}
			}
			else
			{
				if(flags_instance.flashbank_B_valid)
				{
					validate_flashbank(PRIMARY_APP,&flags_instance);
					fls_ret = Fls_Write(FLAGS , &flags_instance, QUAD_PAGE_SIZE);
					flsWaitUntilJobDone();
					if(flags_instance.flashbank_B_valid == 1U)
					{
						ptr_to_flashbank_B();
					}
				}
				else if(flags_instance.flashbank_A_valid)
				{
					validate_flashbank(SECONDARY_APP,&flags_instance);
					if(flags_instance.flashbank_A_valid == 1U)
					{
						flags_instance.current_app = 0;
						fls_ret = Fls_Write(FLAGS , &flags_instance, QUAD_PAGE_SIZE);
						flsWaitUntilJobDone();
						ptr_to_flashbank_A();
					}

				}
			}
			ptr_to_bootloader();
		}
	}
	/* Loop forever */
	Dio_WriteChannel(DioConf_DioChannel_LED_1, STD_LOW);
	for(;;) {
	}
}


