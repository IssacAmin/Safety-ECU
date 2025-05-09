/*
 * eraseMemoryRoutine.c
 *
 *  Created on: May 9, 2025
 *      Author: omart
 */

#include "uds_routines_types.h"
#include "UDS_utils.h"


uint8_t rid_0001_start(uint8_t* data,uint8_t dataLen)
{
	UDS_Utils_ReturnType ret;
	uint8_t i = 0;
	for(;i<5;i++)
	{
		ret = erase_flashbank();
		if(FLASH_OK == ret)
		{
			return 1U;
		}
	}
	return 0U;
}
