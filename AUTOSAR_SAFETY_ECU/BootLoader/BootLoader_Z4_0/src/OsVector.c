/**************************************************************************/
/*                                                                        */
/* DESCRIPTION:                                                           */
/* This is a generic base template for all core exceptions, excluding     */
/* IVOR4 exceptions which have seperate handler                           */
/*                                                                        */
/* This file starts in memory at the beginning of the                     */
/*".core_exceptions_table" section.                                       */
/**************************************************************************/
#include "compiler_api.h"

#define PPCASMF(x) PPCASM (" " tostring(x) " ")
#define PPCASMF2(x,x1) PPCASM (" " tostring(x) "," tostring(x1) " ")

#define VECTOR_C
/******************************************************************************
*
*   Freescale(TM) and the Freescale logo are trademarks of Freescale Semiconductor, Inc.
*   All other product or service names are the property of their respective owners.
*   (c) Copyright 2013 Freescale Semiconductor Inc.
*   All Rights Reserved.
*
*   You can use this example for any purpose on any computer system with the
*   following restrictions:
*
*   1. This example is provided  as is , without warranty.
*
*   2. You don't remove this copyright notice from this example or any direct
*      derivation thereof.
*
* Description:    Vector table for OS/MPC574xGv4
*
* Notes:
*
******************************************************************************/

#include    <Os.h>
#include    <Os_platform_config.h>
#include    <Os_compiler_internal_api.h>

#define OSVECTORS_START_SEC_CODE
// #include <MemMap.h> application specific

#if defined(OSDIABPPC)
#define OSALIGN   asm volatile (" .skip 0x0C ")
#endif
#if defined(OSGHSPPC)
#define OSALIGN   asm (" .skip 0x0C ")
#endif

#if defined(OSDIABPPC) || defined(OSGHSPPC) || defined(__GNUC__)
    OSASMF(   .globl VTABLE                   );
    OSASMF(VTABLE:                            ); /* Vector table start address */

#elif defined(OSCWPPC)  /* defined(OSDIABPPC) || defined(OSGHSPPC) */

extern void OSCriticalException( void );
extern void OSMachineCheckException( void );
extern void OSNonCriticalException( void );
extern void OSInterruptDispatcher( void );
extern void OSSystemCallHandler( void );
extern void OSDebugException( void );
extern void VTABLE( void );
#pragma function_align 16
#define SIXTEEN_BYTES 16
#pragma force_active on

#define OSALIGN  .align SIXTEEN_BYTES

/* The section .vector (which contains VTABLE) should have proper alignment in linker file */
asm void VTABLE( void )
{
    nofralloc
#endif

    OSASMF(    e_b   OSCriticalException        ); /* 0x00, Critical input */

    OSALIGN;
    OSASMF(    e_b   OSMachineCheckException    ); /* 0x10, Machine check */

    OSALIGN;
    OSASMF(    e_b   OSNonCriticalException     ); /* 0x20, Data storage */

    OSALIGN;
    OSASMF(    e_b   OSNonCriticalException     ); /* 0x30, Instruction storage */

    OSALIGN;
    OSASMF(    e_b   OSInterruptDispatcher      ); /* 0x40, External input */

    OSALIGN;
    OSASMF(    e_b   OSNonCriticalException     ); /* 0x50, Alignment */

    OSALIGN;
    OSASMF(    e_b   OSNonCriticalException     ); /* 0x60, Program */

    OSALIGN;
    OSASMF(    e_b   OSNonCriticalException     ); /* 0x70, Performance monitor */

    OSALIGN;
#if defined(OSSC3) || defined(OSSC4)               /* 0x80, System call */
    OSASMF(    e_b   OSSystemCallHandler        );
#else
    OSASMF(    e_b   OSNonCriticalException     );
#endif

    OSALIGN;
    OSASMF(    e_b   OSDebugException           ); /* 0x90, Debug */

    OSALIGN;
    OSASMF(    e_b   OSNonCriticalException     ); /* 0xA0, EFP data */

    OSALIGN;
    OSASMF(    e_b   OSNonCriticalException     ); /* 0xB0, EFP round */

    OSALIGN;
    OSASMF(    e_b   OSNonCriticalException     ); /* 0xC0, reserved */

    OSALIGN;
    OSASMF(    e_b   OSNonCriticalException     ); /* 0xD0, reserved */

    OSALIGN;
    OSASMF(    e_b   OSNonCriticalException     ); /* 0xE0, reserved */

    OSALIGN;
    OSASMF(    e_b   OSNonCriticalException     ); /* 0xF0, reserved */

#if defined(OSCWPPC)
}
#endif

#define OSVECTORS_STOP_SEC_CODE
