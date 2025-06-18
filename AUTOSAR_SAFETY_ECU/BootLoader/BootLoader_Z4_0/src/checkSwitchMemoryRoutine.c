#include "uds_routines_types.h"
#include "UDS_utils.h"

typedef struct
{
    uint8_t         routineRunning;
    uint8_t         routineStarted;
    uint8_t         routineRes;
    FlashBankType   routineData;
}validateSwitchMemRoutineFlags_t;
/*Check Memory Routine Flags*/
validateSwitchMemRoutineFlags_t routine_ff01={0,0,0,0};

/*Swtich flashbank routine Flags*/
validateSwitchMemRoutineFlags_t routine_ff02={0,0,0,0};

void routineCallBack(uint8_t status,validateSwitchMemRoutineFlags_t* routineFlags)
{
    routineFlags->routineRunning = 0;
    if(0U == status)
    {
        routineFlags->routineRes = ROUTINE_STATUS_COMPLETED_FAILURE;
    }
    routineFlags->routineRes = ROUTINE_STATUS_COMPLETED_SUCCESS;
}

void rid_FF01_callBack(uint8_t status)
{
    validateSwitchMemRoutineFlags_t* routineFlags = &routine_ff01;
    routineCallBack(status,routineFlags);
}

void rid_FF02_callBack(uint8_t status)
{
    validateSwitchMemRoutineFlags_t* routineFlags = &routine_ff02;
    routineCallBack(status,routineFlags);
}

uint8_t routineStart(uint8_t* data,uint8_t dataLen,validateSwitchMemRoutineFlags_t* routineFlags,BL_UDS_UtilsReq_MetaData_t* BL_UtilsReq)
{
    if(routineFlags->routineRunning)
	{
		return 0U;
	}
    // if(dataLen != sizeof(FlashBankType))
    // {
    //     return 0U;
    // }

    routineFlags->routineData = data[0];
    
    if(BLUtils_createNewRequest(BL_UtilsReq))
	{
		routineFlags->routineRunning = 1;
		routineFlags->routineStarted = 1;
		return 1U;
	}
    return 0U;
}

uint8_t rid_FF01_start(uint8_t* data,uint8_t dataLen)
{
    BL_UDS_UtilsReq_MetaData_t BL_UtilsReq = {rid_FF01_callBack,BL_UTILS_REQ_VALIDATE_FLASH_BANK,&(routine_ff01.routineData),sizeof(FlashBankType),1U};
    return routineStart(data,dataLen,&routine_ff01,&BL_UtilsReq);
}

uint8_t rid_FF02_start(uint8_t* data,uint8_t dataLen)
{
    BL_UDS_UtilsReq_MetaData_t BL_UtilsReq = {rid_FF02_callBack,BL_UTILS_REQ_SWITCH_FLASH_BANK,&(routine_ff02.routineData),sizeof(FlashBankType),1U};
    return routineStart(data,dataLen,&routine_ff02,&BL_UtilsReq);
}

UDS_RoutineStatus_t routineCheckRes(validateSwitchMemRoutineFlags_t* routineFlags)
{
    if(routineFlags->routineStarted == 0U)
	{
		return ROUTINE_STATUS_NOT_STARTED;
	}
	else if(routineFlags->routineRunning == 1U)
	{
		return ROUTINE_STATUS_RUNNING;
	}
	routineFlags->routineStarted = 0;
	return routineFlags->routineRes;
}
UDS_RoutineStatus_t rid_FF01_checkRes(uint8_t* data,uint8_t dataLen)
{
    return routineCheckRes(&routine_ff01);
}
UDS_RoutineStatus_t rid_FF02_checkRes(uint8_t* data,uint8_t dataLen)
{
    return routineCheckRes(&routine_ff02);
}
