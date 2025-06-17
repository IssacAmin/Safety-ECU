/******************************************************************************
*
*       Freescale(TM) and the Freescale logo are trademarks of Freescale Semiconductor, Inc.
*       All other product or service names are the property of their respective owners.
*       (C) Freescale Semiconductor, Inc. 2025
*
*       THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
*       BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
*       Freescale Semiconductor, Inc.
*
*       Description: Configuration Header file
*
*       Note: The implementation that was used is: AUTOSAR_MPC574xG
*       System Generator for AUTOSAR OS/MPC574xG - Version: 4.0 Build 4.0.92
*
********************************************************************************/
#ifndef OSCFG_H
#define OSCFG_H
#define APP_START_SEC_CODE
#include    "Os_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#include "Os_counter_config.h"

/* Applications */
#define OsApplication_1 ((ApplicationType)OS_MKOBJID(OBJECT_APPLICATION, 0U)) /* Application ID */

/* Spinlock */

/* Application modes */
#define OsAppMode_0 ((AppModeType)0U)      /* AppMode ID */

/* Common stack */
#define OSOsTask2_Core0STKSIZE 10248U      /* stack size of OsTask2_Core0 */
#define OSOsTask2_Core0STKBOS OSRUNNABLESTKBEG /* OsTask2_Core0 bos */
#define OSOsTask2_Core0STKTOS (OSOsTask2_Core0STKBOS + OSOsTask2_Core0STKSIZE/4U) /* OsTask2_Core0 tos */

/* Task definitions */
#define OsTask3_Core0 ((TaskType)OS_MKOBJID(OBJECT_TASK, 0U)) /* Task ID */
extern void FuncOsTask3_Core0(void); /* Task entry point */
#define OsTask2_Core0 ((TaskType)OS_MKOBJID(OBJECT_TASK, 1U)) /* Task ID */
extern void FuncOsTask2_Core0(void); /* Task entry point */
#define OsTask_Core0 ((TaskType)OS_MKOBJID(OBJECT_TASK, 2U)) /* Task ID */
extern void FuncOsTask_Core0(void); /* Task entry point */

/* ISR functions */

/* ISRs definition */

/* ISR1 id */

/* Resources definitions */
#define RES_SCHEDULER ((ResourceType)OS_MKOBJID(OBJECT_RESOURCE, 0U)) /* Resource ID */

/* Events definition */
#define canTpTxConfirmationEvent ((EventMaskType)1U) /* Event mask */

/* Alarms identification */
#define task2WakeupAlarm ((AlarmType)OS_MKOBJID(OBJECT_ALARM, 0U)) /* Alarm ID */
#define task3WakeupAlarm ((AlarmType)OS_MKOBJID(OBJECT_ALARM, 1U)) /* Alarm ID */
#define canTp_OsAlarm ((AlarmType)OS_MKOBJID(OBJECT_ALARM, 2U)) /* Alarm ID */
void canTpOsAlarmCallback(void); /* callback function of canTp_OsAlarm */
#define udsDefaultSecurityLevelResetTimeoutAlarm ((AlarmType)OS_MKOBJID(OBJECT_ALARM, 3U)) /* Alarm ID */
void UDS_defaultSecurityLevelResetCallack(void); /* callback function of udsDefaultSecurityLevelResetTimeoutAlarm */
#define udsSecurityAccessAttemptCountTimeoutAlarm ((AlarmType)OS_MKOBJID(OBJECT_ALARM, 4U)) /* Alarm ID */
void uds_secLvl_attempt_callBack(void); /* callback function of udsSecurityAccessAttemptCountTimeoutAlarm */
#define udsSessionTimeoutAlarm ((AlarmType)OS_MKOBJID(OBJECT_ALARM, 5U)) /* Alarm ID */
void UDS_defaultSessionResetCallBack(void); /* callback function of udsSessionTimeoutAlarm */

/* Counters identification */
#define SYSTEMTIMER ((CounterType)OS_MKOBJID(OBJECT_COUNTER, 0U)) /* Counter ID */
#define OSMINCYCLE_SYSTEMTIMER ((TickType)0x1U) /* SYSTEMTIMER */
#define OSMAXALLOWEDVALUE_SYSTEMTIMER ((TickType)0xffffU) /* SYSTEMTIMER */
#define OSTICKSPERBASE_SYSTEMTIMER 1000UL  /* SYSTEMTIMER */
#define OS_TICKS2NS_SYSTEMTIMER(ticks) (PhysicalTimeType)(ticks*12500U) /*  */
#define OS_TICKS2US_SYSTEMTIMER(ticks) (PhysicalTimeType)((OSQWORD)(ticks)*12500ULL/1000UL) /*  */
#define OS_TICKS2MS_SYSTEMTIMER(ticks) (PhysicalTimeType)((OSQWORD)(ticks)*12500ULL/1000000UL) /*  */
#define OS_TICKS2SEC_SYSTEMTIMER(ticks) (PhysicalTimeType)((OSQWORD)(ticks)*12500ULL/1000000000UL) /*  */
#define OSMINCYCLE ((TickType)0x1U)        /* SysTimer */
#define OSMAXALLOWEDVALUE ((TickType)0xffffU) /* SysTimer */
#define OSTICKSPERBASE 1000UL              /* SysTimer */
#define OSTICKDURATION 12500UL             /* SysTimer */

/* Messages identification */

/* Flags identification */

/* Message callback prototypes */

/* scheduletable */
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#define APP_STOP_SEC_CODE
#include    "Os_memmap.h"

#endif /* OSCFG_H */

