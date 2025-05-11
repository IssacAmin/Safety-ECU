/*
 * eraseMemoryRoutine.c
 *
 *  Created on: May 9, 2025
 *      Author: omart
 */

#include "uds_routines_types.h"
#include "UDS_utils.h"

uint8_t rid_FF00_start(uint8_t* data,uint8_t dataLen)
{
	BL_UDS_UtilsReq_MetaData_t BL_UtilsReq = {BL_UTIL_REQ_ERASE_FLASH_BANK,NULL,0U,5U};
    return BLUtils_createNewRequest(&BL_UtilsReq);
}

uint8_t rid_FF00_checkRes(uint8_t* data,uint8_t dataLen)
{
	if(read_flags(CURRENT_APP) == 0)
	{
		return read_flags(FLASHBANK_A_ERASED);
	}
	else
	{
		return read_flags(FLASHBANK_B_ERASED);
	}
}


uint8_t preFlashConditionsChecks(void)
{
	if(read_flags(CURRENT_APP) == 0)
	{
		return read_flags(FLASHBANK_A_ERASED);
	}
	else
	{
		return read_flags(FLASHBANK_B_ERASED);
	}
}
