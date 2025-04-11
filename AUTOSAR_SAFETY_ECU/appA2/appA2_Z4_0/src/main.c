/*

 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "stdint.h"
#include "Dio.h"
#include "Mcu.h"
#include "Port.h"


int main(void)
{
	volatile uint32_t counter;
	Mcu_Init(&McuModuleConfiguration);

	Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_0);

	Port_Init(&PortConfigSet);

	while(1)
	{
		Dio_WriteChannel(DioConf_DioChannel_LED_2, STD_HIGH);
		counter = 1000000;
		while(counter--);

		Dio_WriteChannel(DioConf_DioChannel_LED_2, STD_LOW);
		counter = 1000000;
		while(counter--);

	}
}
