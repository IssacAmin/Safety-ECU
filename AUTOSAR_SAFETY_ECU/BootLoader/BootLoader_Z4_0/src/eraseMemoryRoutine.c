/*
 * eraseMemoryRoutine.c
 *
 *  Created on: May 9, 2025
 *      Author: omart
 */

#include "uds_routines_types.h"
#include "UDS_utils.h"

uint8_t routineRunning = 0;
uint8_t routineStarted = 0;
UDS_RoutineStatus_t routineRes = 0;

void rid_FF00_callBack(uint8_t status)
{
	routineRunning = 0;
	if(0U == status)
	{
		routineRes = ROUTINE_STATUS_COMPLETED_FAILURE;
	}
	routineRes = ROUTINE_STATUS_COMPLETED_SUCCESS;
}

uint8_t rid_FF00_start(uint8_t* data,uint8_t dataLen)
{
	if(routineRunning)
	{
		return 0U;
	}
	BL_UDS_UtilsReq_MetaData_t BL_UtilsReq = {rid_FF00_callBack,BL_UTILS_REQ_ERASE_FLASH_BANK,NULL,0U,5U};
	if(BLUtils_createNewRequest(&BL_UtilsReq))
	{
		routineRunning = 1;
		routineStarted = 1;
		return 1U;
	}
    return 0U;
}

UDS_RoutineStatus_t rid_FF00_checkRes(uint8_t* data,uint8_t dataLen)
{
	if(routineStarted == 0U)
	{
		return ROUTINE_STATUS_NOT_STARTED;
	}
	else if(routineRunning == 1U)
	{
		return ROUTINE_STATUS_RUNNING;
	}
	routineStarted = 0;
	return routineRes;
}

uint8_t preFlashConditionsChecks(void)
{
	if(read_flags(CURRENT_APP) == 0)
	{
		return read_flags(FLASHBANK_B_ERASED);
	}
	else
	{
		return read_flags(FLASHBANK_A_ERASED);
	}
	return 1;
}
