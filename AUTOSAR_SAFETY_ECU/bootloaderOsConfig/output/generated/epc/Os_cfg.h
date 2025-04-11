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


/* Applications */
#define OsApplication_1 ((ApplicationType)OS_MKOBJID(OBJECT_APPLICATION, 0U)) /* Application ID */

/* Spinlock */

/* Application modes */
#define OsAppMode_0 ((AppModeType)0U)      /* AppMode ID */

/* Common stack */

/* Task definitions */
#define OsTask_Core0 ((TaskType)OS_MKOBJID(OBJECT_TASK, 0U)) /* Task ID */
extern void FuncOsTask_Core0(void); /* Task entry point */

/* ISR functions */

/* ISRs definition */

/* ISR1 id */

/* Resources definitions */
#define RES_SCHEDULER ((ResourceType)OS_MKOBJID(OBJECT_RESOURCE, 0U)) /* Resource ID */

/* Events definition */

/* Alarms identification */

/* Counters identification */
#define SYSTEMTIMER ((CounterType)OS_MKOBJID(OBJECT_COUNTER, 0U)) /* Counter ID */
#define OSMINCYCLE_SYSTEMTIMER ((TickType)0x1f4U) /* SYSTEMTIMER */
#define OSMAXALLOWEDVALUE_SYSTEMTIMER ((TickType)0xffffU) /* SYSTEMTIMER */
#define OSTICKSPERBASE_SYSTEMTIMER 1000UL  /* SYSTEMTIMER */
#define OS_TICKS2NS_SYSTEMTIMER(ticks) (PhysicalTimeType)(ticks*1000000U) /*  */
#define OS_TICKS2US_SYSTEMTIMER(ticks) (PhysicalTimeType)((OSQWORD)(ticks)*1000000ULL/1000UL) /*  */
#define OS_TICKS2MS_SYSTEMTIMER(ticks) (PhysicalTimeType)((OSQWORD)(ticks)*1000000ULL/1000000UL) /*  */
#define OS_TICKS2SEC_SYSTEMTIMER(ticks) (PhysicalTimeType)((OSQWORD)(ticks)*1000000ULL/1000000000UL) /*  */
#define OSMINCYCLE ((TickType)0x1f4U)      /* SysTimer */
#define OSMAXALLOWEDVALUE ((TickType)0xffffU) /* SysTimer */
#define OSTICKSPERBASE 1000UL              /* SysTimer */
#define OSTICKDURATION 1000000UL           /* SysTimer */

/* Messages identification */

/* Flags identification */

/* Message callback prototypes */

/* scheduletable */
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#define APP_STOP_SEC_CODE
#include    "Os_memmap.h"

#endif /* OSCFG_H */

