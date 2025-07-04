/**
*   @file    Mcu_FXOSC.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Fast External Oscillator functions implementation.
*   @details Specific functions for FXOSC configuration and control.
*
*   @addtogroup MCU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : PA
*   Peripheral           : MC
*   Dependencies         : none
*
*   Autosar Version      : 4.3.1
*   Autosar Revision     : ASR_REL_4_3_REV_0001
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC574XG_MCAL_1_0_1_RTM_HF6_ASR_REL_4_3_REV_0001_20210223
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2019 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/


#ifdef __cplusplus
extern "C"
{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_FXOSC_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_FXOSC_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_FXOSC_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a
* pointer to a function and a type other than an integral type. This violation is due to the
* pointer arithmetic used to write/ read the data to/from the registers
*
* @section Mcu_FXOSC_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is requiered
* This warning appears when defining functions that will be used by the upper layers.
*
* @section Mcu_FXOSC_c_REF_5
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between
* a pointer type and an integral type
* The cast is used to access memory mapped registers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_FXOSC.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

#ifndef USER_MODE_REG_PROT_ENABLED
#define USER_MODE_REG_PROT_ENABLED ( MCU_USER_MODE_REG_PROT_ENABLED )
#endif

#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define Mcu_FXOSC_VENDOR_ID_C                      43
#define Mcu_FXOSC_AR_RELEASE_MAJOR_VERSION_C       4
#define Mcu_FXOSC_AR_RELEASE_MINOR_VERSION_C       3
#define Mcu_FXOSC_AR_RELEASE_REVISION_VERSION_C    1
#define Mcu_FXOSC_SW_MAJOR_VERSION_C               1
#define Mcu_FXOSC_SW_MINOR_VERSION_C               0
#define Mcu_FXOSC_SW_PATCH_VERSION_C               1


/*==================================================================================================
                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if current file and Mcu_CMU header file are of the same vendor */
#if (Mcu_FXOSC_VENDOR_ID_C != MCU_FXOSC_VENDOR_ID)
    #error "Mcu_FXOSC.c and Mcu_FXOSC.h have different vendor ids"
#endif
/* Check if current file and Mcu__CMU header file are of the same Autosar version */
#if ((Mcu_FXOSC_AR_RELEASE_MAJOR_VERSION_C    != MCU_FXOSC_AR_RELEASE_MAJOR_VERSION) || \
     (Mcu_FXOSC_AR_RELEASE_MINOR_VERSION_C    != MCU_FXOSC_AR_RELEASE_MINOR_VERSION) || \
     (Mcu_FXOSC_AR_RELEASE_REVISION_VERSION_C != MCU_FXOSC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_FXOSC.c and Mcu_FXOSC.h are different"
#endif
/* Check if current file and Mcu_CMU header file are of the same Software version */
#if ((Mcu_FXOSC_SW_MAJOR_VERSION_C != MCU_FXOSC_SW_MAJOR_VERSION) || \
     (Mcu_FXOSC_SW_MINOR_VERSION_C != MCU_FXOSC_SW_MINOR_VERSION) || \
     (Mcu_FXOSC_SW_PATCH_VERSION_C != MCU_FXOSC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_FXOSC.c and Mcu_FXOSC.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((Mcu_FXOSC_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (Mcu_FXOSC_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_FXOSC.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((Mcu_FXOSC_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (Mcu_FXOSC_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_FXOSC.c and SilRegMacros.h are different"
    #endif
#endif

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_FXOSC_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files
* @violates @ref Mcu_FXOSC_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (MCU_FXOSC_UNDER_MCU_CONTROL == STD_ON)

/**
* @brief            Write FXOSC configuration if under MCU control
* @details          
*
* @param[in]        Mcu_pFxoscConf - configuration pointer
*
* @return           void
*
*/
/** @violates @ref Mcu_FXOSC_c_REF_4 Violates MISRA 2004 Required Rule 8.10, global declaration of function */
FUNC( void, MCU_CODE) Mcu_FXOSC_Config(P2CONST(Mcu_FXOSC_ConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pFxoscConf)
{
    /* write FXOSC configuration registers */
    /** @violates @ref Mcu_FXOSC_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FXOSC_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FXOSC_CTL_ADDR32, Mcu_pFxoscConf->u32FxoscCtl);
}
#endif /* (MCU_FXOSC_UNDER_MCU_CONTROL == STD_ON) */



#if (MCU_FXOSC_INT_USED == STD_ON)

FUNC( void, MCU_CODE) Mcu_FXOSC_ClockInterrupt(VAR(void, AUTOMATIC))
{
    VAR( uint32, AUTOMATIC) u32Status ;
    
    /* get CTL value */
    /** @violates @ref Mcu_FXOSC_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FXOSC_c_REF_5 The cast is used to access memory mapped registers.*/
    u32Status = REG_READ32(FXOSC_CTL_ADDR32) ;
    
    /* clear the IRQ - write 1 to clear */
    /** @violates @ref Mcu_FXOSC_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FXOSC_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FXOSC_CTL_ADDR32 , (u32Status | FXOSC_CTL_I_OSC_MASK32));
}

#endif


#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_FXOSC_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_FXOSC_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

