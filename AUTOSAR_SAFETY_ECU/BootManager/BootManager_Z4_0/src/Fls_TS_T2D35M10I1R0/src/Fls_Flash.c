/**
*   @file    Fls_Flash_Code.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Flash IPV_FLASHV2 driver source code.
*
*   @addtogroup FLS
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : PA
*   Peripheral           : IPV_FLASHV2
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section fls_flash_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_flash_c_REF_2
* Violates MISRA 2004 Advisory Rule 11.4,  A cast should not be performed between a pointer
* to object type and a different pointer to object type
* Due to casting between a pointer and unsigned long
*
* @section fls_flash_c_REF_3
* Violates MISRA 2004 Required Rule 12.4, Side effects on right hand of logical operator: '||' or '&&'.
* This violation is because of complex statement
*
* @section fls_flash_c_REF_4
* Violates MISRA 2004 Required Rule 1.2, No reliance shall be placed on undefined or unspecified behaviour
* This violation is because of complex statement
*
* @section fls_flash_c_REF_5
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* This violation is not fixed since if hardware error is detected it should return from the function
*
* @section fls_flash_c_REF_6
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* Return from function as soon as the read/write/erase/operation finished
*
* @section fls_flash_c_REF_7
* Violates MISRA 2004 Advisory Rule 12.6, Booleans operands are not used for logical
* operators '&&', '||' and '!'
* This violation because of it is not effectively boolean
*
* @section fls_flash_c_REF_8
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* The cast can not be avoided as it is used to access memory mapped registers.
*
* @section fls_flash_c_REF_9
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_flash_c_REF_10
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic
* This violation is because of complex statement
*
* @section fls_flash_c_REF_11
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* State variables may be used by LLD layer.
*
* @section fls_flash_c_REF_12
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
*
* @section fls_flash_c_REF_13
* Violates MISRA 2004 Required Rule 17.2, Pointer subtraction shall only be applied to pointers
* that address elements of the same array
* Due to the pointers that address elements are not the same array
*
* @section fls_flash_c_REF_14
* Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable.
* The code is not dynamically linked. An absolute stack address is obtained
* when taking the address of the near auto variable.
*
* @section fls_flash_c_REF_15
* Violates MISRA 2004 Required Rule 17.4, Cast of complex expression changes signedness
* The pointer subtraction is made inside while loop and due to its condition the subtraction
* result is always positive and therefore it can be casted to unsigned.
*
* @section fls_flash_c_REF_16
* Violates MISRA 2004 Required Rule 11.1, cast from pointer to unsigned long
* Due to casting between a pointer and unsigned long representing address.
*
* @section fls_flash_c_REF_17
* Violates MISRA 2004 Required Rule 14.6, more than one 'break' terminates loop
* Once abnormal condition is indicated, the loop is terminated by 'break'. Since
* there are handled several abnormal conditions, the loop contains more
* than one 'break'.
*
* @section fls_flash_c_REF_18
* Violates MISRA 2004 Required Rule 11.1, cast from pointer to unsigned long
* On ARM platform, the liker is not aware whether Access Code copied to RAM
* by the FLS driver is compiled in Thumb mode. Therefore LSB bit in its
* address needs to be set to notify the core that the code executed after BLX
* instruction branching to AC code is in Thumb-encoded.
*
* @section fls_flash_c_REF_19
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type other than an integral type.
* The cast is made in order to access memory mapped registers.
*
* @section fls_flash_c_REF_20
* Violates MISRA 2004 Required Rule 8.8, Object/function previously declared.
* The rule 8.8 requires that 'An external object or function shall be declared in one and only one file'.
* This requirement is fulfilled since the function is declared as in only one file
*
* @section fls_flash_c_REF_21
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* This function may be called from Mcal.h in Base module
*
* @section fls_flash_c_REF_22
* Violates MISRA 2004 Required Rule 12.10, The comma operator shall not be used
* This comma operator was used for the side effect. The return value from called
* was not evaluated
*
* @section fls_flash_c_REF_23
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer
* to a function and any type other than an integral type contents in that address.
* This violation is due to casting unsigned long to pointer and access these addresses for updating
* contents in that address.
*
* @section fls_flash_c_REF_24
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only accessed
* from within a single function. Variable is may be used in many functions depend on user configurations
*
* @section fls_flash_c_REF_25
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* This function may be called from upper layer
*
* @section fls_flash_c_REF_26
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results are invariant shall not be permitted
* Variable is compared with same value more than one time to support multi derivatives of platfom.
* @section fls_flash_c_REF_27
* Violates MISRA 2004 Required Rule 10.3, The value of a complex expression of integer type *shall only be cast to a type of the same signedness that is no wider than the underlying type *of the expression.
*
* @section fls_flash_c_REF_28
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not
* be implicitly converted to a different underlying type.
*
* @section fls_c_REF_27
* Violates MISRA 2004 Required Rule 14.6, more than one 'break' terminates loop
* Once abnormal condition is indicated, the loop is terminated by 'break'. Since
* there are handled several abnormal conditions, the loop contains more
* than one 'break'.
*
* @section fls_c_REF_2
* Violates MISRA 2004 Advisory Rule 11.4, Boolean operations whose results are invariant shall not be permitted
* @section fls_c_REF_41
* Violates MISRA 2004 Required Rule 11.1, Boolean operations whose results are invariant shall not be permitted
* Variable is compared with same value more than one time to support multi derivatives of platfom.
* @section fls_c_REF_30
* Violates MISRA 2004 Advisory Rule 11.4, Boolean operations whose results are invariant shall not be permitted
* Variable is compared with same value more than one time to support multi derivatives of platfom.
*
* @section fls_c_REF_31
* Violates MISRA 2004 Required Rule 11.5, Boolean operations whose results are invariant shall not be permitted
* Variable is compared with same value more than one time to support multi derivatives of platfom.
*
* @section fls_c_REF_32
* Violates MISRA 2004 Required Rule 11.1, Boolean operations whose results are invariant shall not be permitted
* Variable is compared with same value more than one time to support multi derivatives of platfom.
*
* @section fls_c_REF_33
* Violates MISRA 2004 Required Rule 17.3, Boolean operations whose results are invariant shall not be permitted
* Variable is compared with same value more than one time to support multi derivatives of platfom.
*
* @section fls_c_REF_38
* Violates MISRA 2004 Required Rule 8.10, Boolean operations whose results are invariant shall not be permitted
* Variable is compared with same value more than one time to support multi derivatives of platfom.

* @section fls_c_REF_42
* Violates MISRA 2004 Required Rule 8.10, Boolean operations whose results are invariant shall not be permitted
* Variable is compared with same value more than one time to support multi derivatives of platfom.
*
* @section fls_c_REF_43
* Violates MISRA 2004 Required Rule 19.11, All macro identifers in preprocessor directives shall be defned before use
* All macro identifers in preprocessor directives shall be defned before use, except in #ifdef and #ifndef
* preprocessor directives and the defned() operator.
*
* @section fls_c_REF_7
* Violates MISRA 2004 Required Rule 12.2, Boolean operations whose results are invariant shall not be permitted
* @section fls_c_REF_8
* Violates MISRA 2004 Required Rule 12.4, The right-hand operand of a logical && or || operator shall not
contain side effects.
* @section fls_c_REF_5
* Violates MISRA 2004 Required Rule 14.7, The right-hand operand of a logical && or || operator shall not
contain side effects.
* Variable is compared with same value more than one time to support multi derivatives of platfom.
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters.
* The used compilers use more than 31 chars for identifiers.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#include "Fls_Flash.h"
#include "Fls_Flash_Types.h"
#include "Reg_eSys_FLASHC.h"


#if(( FLS_DEV_ERROR_DETECT == STD_ON ) || ( FLS_RUNTIME_ERROR_DETECT == STD_ON ))
#include "Det.h"
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */

#include "SchM_Fls.h"
#include "StdRegMacros.h"

#if (STD_ON == FLS_ENABLE_USER_MODE_SUPPORT)
#include "RegLockMacros.h"
#endif /* STD_ON == FLS_ENABLE_USER_MODE_SUPPORT */

#if (STD_ON == FLS_SYNCRONIZE_CACHE)
#include "Mcl.h"
#endif /* FLS_SYNCRONIZE_CACHE */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_FLASH_VENDOR_ID_C                      43
#define FLS_FLASH_MODULE_ID_C                      92
/*
* @violates @ref fls_flash_c_REF_12 The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for external identifiers.
*/
#define FLS_FLASH_AR_RELEASE_MAJOR_VERSION_C       4
/*
* @violates @ref fls_flash_c_REF_12 The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
#define FLS_FLASH_AR_RELEASE_MINOR_VERSION_C       3
/*
* @violates @ref fls_flash_c_REF_12 The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
#define FLS_FLASH_AR_RELEASE_REVISION_VERSION_C    1
#define FLS_FLASH_SW_MAJOR_VERSION_C               1
#define FLS_FLASH_SW_MINOR_VERSION_C               0
#define FLS_FLASH_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_FLASH_VENDOR_ID_C != FLS_VENDOR_ID)
    #error "Fls_Flash.c and Fls.h have different vendor ids"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Fls header file are of the same Autosar version */
    #if ((FLS_FLASH_AR_RELEASE_MAJOR_VERSION_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_FLASH_AR_RELEASE_MINOR_VERSION_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
         (FLS_FLASH_AR_RELEASE_REVISION_VERSION_C    != FLS_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Flash.c and Fls.h are different"
    #endif
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_FLASH_SW_MAJOR_VERSION_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_FLASH_SW_MINOR_VERSION_C != FLS_SW_MINOR_VERSION) || \
     (FLS_FLASH_SW_PATCH_VERSION_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Flash.c and Fls.h are different"
#endif

/* Check if current file and Fls_Flash header file are of the same vendor */
#if (FLS_FLASH_VENDOR_ID_C != FLS_FLASH_VENDOR_ID)
    #error "Fls_Flash.c and Fls_Flash.h have different vendor ids"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Fls_Flash header file are of the same Autosar version */
    #if ((FLS_FLASH_AR_RELEASE_MAJOR_VERSION_C    != FLS_FLASH_AR_RELEASE_MAJOR_VERSION   ) || \
         (FLS_FLASH_AR_RELEASE_MINOR_VERSION_C    != FLS_FLASH_AR_RELEASE_MINOR_VERSION   ) || \
         (FLS_FLASH_AR_RELEASE_REVISION_VERSION_C != FLS_FLASH_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Flash.c and Fls_Flash.h are different"
    #endif
#endif
/* Check if current file and Fls_Flash header file are of the same Software version */
#if ((FLS_FLASH_SW_MAJOR_VERSION_C != FLS_FLASH_SW_MAJOR_VERSION) || \
     (FLS_FLASH_SW_MINOR_VERSION_C != FLS_FLASH_SW_MINOR_VERSION) || \
     (FLS_FLASH_SW_PATCH_VERSION_C != FLS_FLASH_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Flash.c and Fls_Flash.h are different"
#endif

/* Check if current file and Reg_eSys_FLASHC.h header file are of the same vendor */
#if (FLS_FLASH_VENDOR_ID_C != ESYS_FLASHC_VENDOR_ID)
    #error "Fls_Flash.c and Reg_eSys_FLASHC.h have different vendor ids"
#endif
/* Check if current file and Fls header file are of the same Autosar version */
#if ((FLS_FLASH_AR_RELEASE_MAJOR_VERSION_C    != ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_FLASH_AR_RELEASE_MINOR_VERSION_C    != ESYS_FLASHC_AR_RELEASE_MINOR_VERSION) || \
     (FLS_FLASH_AR_RELEASE_REVISION_VERSION_C != ESYS_FLASHC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_Flash.c and Reg_eSys_FLASHC.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_FLASH_SW_MAJOR_VERSION_C != ESYS_FLASHC_SW_MAJOR_VERSION) || \
     (FLS_FLASH_SW_MINOR_VERSION_C != ESYS_FLASHC_SW_MINOR_VERSION) || \
     (FLS_FLASH_SW_PATCH_VERSION_C != ESYS_FLASHC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Flash.c and Reg_eSys_FLASHC.h are different"
#endif

/* Check if current file and Fls_Flash_Types.h header file are of the same vendor */
#if (FLS_FLASH_VENDOR_ID_C != FLS_FLASH_TYPES_VENDOR_ID)
    #error "Fls_Flash.c and Fls_Flash_Types.h have different vendor ids"
#endif
/* Check if current file and Fls_Flash_Types header file are of the same Autosar version */
#if ((FLS_FLASH_AR_RELEASE_MAJOR_VERSION_C    != FLS_FLASH_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_FLASH_AR_RELEASE_MINOR_VERSION_C    != FLS_FLASH_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLS_FLASH_AR_RELEASE_REVISION_VERSION_C != FLS_FLASH_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_Flash.c and Fls_Flash_Types.h are different"
#endif
/* Check if current file and Fls_Flash_Types header file are of the same Software version */
#if ((FLS_FLASH_SW_MAJOR_VERSION_C != FLS_FLASH_TYPES_SW_MAJOR_VERSION) || \
     (FLS_FLASH_SW_MINOR_VERSION_C != FLS_FLASH_TYPES_SW_MINOR_VERSION) || \
     (FLS_FLASH_SW_PATCH_VERSION_C != FLS_FLASH_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Flash.c and Fls_Flash_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StdRegMacros header file are of the same Autosar version */
    #if ((FLS_FLASH_AR_RELEASE_MAJOR_VERSION_C    != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_FLASH_AR_RELEASE_MINOR_VERSION_C    != STDREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Flash.c and StdRegMacros.h are different"
    #endif
#endif


#if(( FLS_DEV_ERROR_DETECT == STD_ON ) || ( FLS_RUNTIME_ERROR_DETECT == STD_ON ))
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((FLS_FLASH_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_FLASH_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls.c and Det.h are different"
    #endif
#endif
#endif

#if (STD_ON == FLS_ENABLE_USER_MODE_SUPPORT)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and RegLockMacros header file are of the same Autosar version */
    #if ((FLS_FLASH_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_FLASH_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls.c and RegLockMacros.h are different"
    #endif
#endif
#endif /* STD_ON == FLS_ENABLE_USER_MODE_SUPPORT */

#if (STD_ON == FLS_SYNCRONIZE_CACHE)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcl header file are of the same Autosar version */
    #if ((FLS_FLASH_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION_H) || \
         (FLS_FLASH_AR_RELEASE_MINOR_VERSION_C != MCL_AR_RELEASE_MINOR_VERSION_H) \
        )
        #error "AutoSar Version Numbers of Fls.c and Mcl.h are different"
    #endif
#endif
#endif /* FLS_SYNCRONIZE_CACHE */

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define FLS_START_SEC_CODE
/*
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice.
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements and comments before '#include'
*/
#include "Fls_MemMap.h"

#if (STD_ON == FLS_ENABLE_USER_MODE_SUPPORT)
#ifdef FLS_FLASH_REG_PROT_AVAILABLE
    FUNC(void, FLS_CODE) Fls_Flash_SetUserAccessAllowed(void);
#endif
#endif /* STD_ON == FLS_ENABLE_USER_MODE_SUPPORT */

#if(( FLS_ERASE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_BLANK_CHECK == STD_ON )||(FLS_WRITE_VERIFY_CHECK == STD_ON) || ( FLS_COMPARE_API == STD_ON ) || ( FLS_BLANK_CHECK_API == STD_ON ))
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_VerifyMemoryArea
(
    VAR(volatile Fls_Flash_DataBusWidthType, AUTOMATIC ) u32FlashAreaPtr,
    P2CONST( Fls_Flash_DataBusWidthType, AUTOMATIC, FLS_APPL_CONST ) pUserBufferPtr,
    VAR( Fls_LengthType, AUTOMATIC) u32DataLength
);
#endif    /* FLS_ERASE_BLANK_CHECK || FLS_WRITE_BLANK_CHECK || FLS_WRITE_VERIFY_CHECK */
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_ReadBytes
(
    VAR(Fls_DataBytesType, AUTOMATIC) u8DataLength
);
static FUNC( void, FLS_CODE ) Fls_Flash_PageWrite
(
    CONST(uint32, AUTOMATIC) u32TotalBytes
);
static FUNC( boolean, FLS_CODE ) Fls_Flash_FinishHVOperation( void );

#if( STD_ON == FLS_DSI_HANDLER_API )
static FUNC( boolean, FLS_CODE ) Fls_Flash_ECCTest( void );
#endif /* #if( STD_ON == FLS_DSI_HANDLER_API ) */

#define FLS_STOP_SEC_CODE
/*
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice.
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements and comments before '#include'
*/
#include "Fls_MemMap.h"
/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice.
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements and comments before '#include'
*/
#include "Fls_MemMap.h"

#if( FLS_DSI_HANDLER_API == STD_ON )
/**
    @brief Current status of the sector read operation. The Fls_DsiHandler function can terminate
        the read operation by setting this volatile variable to FLASH_E_FAILED
*/
static VAR( volatile Fls_LLDReturnType, FLS_VAR ) Fls_Flash_eReadStatus = FLASH_E_OK;

/**
    @brief Current status of the sector compare operation. The Fls_DsiHandler function can terminate
        the compare operation by setting this volatile variable to FLASH_E_FAILED
*/
/* @violates @ref fls_flash_c_REF_24 Objects shall be defined at block scope if they are only accessed from within a single function*/
static VAR( volatile Fls_LLDReturnType, FLS_VAR ) Fls_Flash_eCompareStatus = FLASH_E_OK;
#endif

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice.
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements and comments before '#include'
*/
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_8
/*
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice.
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements and comments before '#include'
*/
#include "Fls_MemMap.h"

/**
    @brief Physical address of currently read uint8, uint32 from flash
*/
/* @violates @ref fls_flash_c_REF_24 Objects shall be defined at block scope if they are only accessed from within a single function */
static P2VAR(volatile uint8, FLS_VAR, FLS_APPL_CONST) volatile Fls_Flash_pReadAddressPtr = NULL_PTR;
/**
    @brief Physical address of currently compared uint8, uint32 from user buffer
*/
/* @violates @ref fls_flash_c_REF_24 Objects shall be defined at block scope if they are only accessed from within a single function */
static P2CONST(volatile uint8, FLS_VAR, FLS_APPL_CONST) volatile Fls_Flash_pCompareAddressPtr = NULL_PTR;

#define FLS_STOP_SEC_VAR_INIT_8
/*
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice.
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements and comments before '#include'
*/
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_32
/*
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice.
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements and comments before '#include'
*/
#include "Fls_MemMap.h"

/**
    @brief 'double word program operation' iterator
*/
static VAR(uint32, FLS_VAR) Fls_Flash_u32ProgramCycle = 0UL;

/**
    @brief 'double word program operation' count
*/
static VAR(uint32, FLS_VAR) Fls_Flash_u32DoubleWordToCopy = 0UL;
/**
    @brief 'number of word / double word needed for program operation'
*/
static VAR(uint32, FLS_VAR) Fls_Flash_u32DoubleWordCounter = 0UL;

/**
    @brief 'read variables'
*/
static VAR(uint8, AUTOMATIC) Fls_Flash_u8ReadAddress8 = 0U;
static VAR(uint32, AUTOMATIC) Fls_Flash_u32ReadAddress32 = 0U;

/**
    @brief 'data copy' auxiliary pointers
*/
static P2VAR(volatile uint32, FLS_VAR, FLS_APPL_DATA) Fls_Flash_pTargetAddressPtr = NULL_PTR;
static P2CONST(uint32, FLS_VAR, FLS_APPL_CONST) Fls_Flash_pSourceAddressPtr = NULL_PTR;
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
static P2CONST(volatile uint32, FLS_VAR, FLS_APPL_CONST) Fls_Flash_pEndAddressPtr = NULL_PTR;
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */

#define FLS_STOP_SEC_VAR_INIT_32
/*
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice.
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements and comments before '#include'
*/
#include "Fls_MemMap.h"


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define FLS_START_SEC_CODE
/*
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice.
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements and comments before '#include'
*/
#include "Fls_MemMap.h"

#if (STD_ON == FLS_ENABLE_USER_MODE_SUPPORT)
#ifdef FLS_FLASH_REG_PROT_AVAILABLE
/**
* @brief        Enable user mode support to access C55FMC registers
*
* @details      Set UAA bit in FLASH_REG_PROT_GCR to allow user access locked registers in C55FMC module
*
* @param[in]    none
* @retval       none
*
* @pre          The user mode is enabled
*
*/
/* @violates @ref fls_c_REF_38 All declarations and definitions of objects or functions at file scope shall have internal linkage unless external linkage required */
FUNC(void, FLS_CODE) Fls_Flash_SetUserAccessAllowed(void)
{
    /*
    * @violates @ref fls_c_REF_41 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
    /* Set UAA bit in REG_PROT register */
   SET_USER_ACCESS_ALLOWED(FLASH_BASEADDR, FLASH_PERIPH_SIZE_U32);
}
#endif /* ifdef FLS_FLASH_REG_PROT_AVAILABLE */
#endif /* STD_ON == FLS_ENABLE_USER_MODE_SUPPORT */

/**
* @brief          Disables HV operation with timeout.
* @return         Success (DONE)
*/
static FUNC( boolean, FLS_CODE ) Fls_Flash_FinishHVOperation( void )
{
#if (FLS_TIMEOUT_HANDLING == STD_ON)
    uint32 u32TimerCounterAbort = FLS_ABT_TIMEOUT_VALUE;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

    VAR(boolean, AUTOMATIC) bRetVal;

    /* disable HV to finalize/abort the operation */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
    REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_EHV_U32);

#if (FLS_TIMEOUT_HANDLING == STD_ON)
    /* wait until done or abort timeout is reached */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
    while((0U == REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_DONE_U32)) && (0U < u32TimerCounterAbort) )
    {
        --u32TimerCounterAbort;
    }
#else
    /* wait until done or abort timeout is reached */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
    while(0U == REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_DONE_U32))
    {
    }
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

    /* return true if DONE */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
    if (0U != REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_DONE_U32))
    {
        bRetVal = (boolean)TRUE;
    }
    else
    {
        bRetVal = (boolean)FALSE;
    }

    MCAL_FAULT_INJECTION_POINT(FLS_FIP_10_FLS_FLASH_FINISH_HV_OPERATION);

    return(bRetVal);
}

/**
* @brief          Initialize flash hardware.
*/
/* @violates @ref fls_flash_c_REF_25 All declarations and definitions of objects or functions at file scope shall have internal linkage unless external linkage required */
FUNC( void, FLS_CODE ) Fls_Flash_Init( void )
{
    VAR(uint32, AUTOMATIC) u32McrValue = 0UL;
    /* Use diffrent iterator for configured array and physical one */
    VAR(uint32, AUTOMATIC) u32ArrayIter = 0UL;
    VAR(uint32, AUTOMATIC) u32ConfigIter=0UL;

    Fls_eLLDJobResult = MEMIF_JOB_OK;
#if (STD_ON == FLS_ENABLE_USER_MODE_SUPPORT)
#ifdef FLS_FLASH_REG_PROT_AVAILABLE
    /* Enable user mode support */
    Mcal_Trusted_Call(Fls_Flash_SetUserAccessAllowed);
#endif
#endif /* STD_ON == FLS_ENABLE_USER_MODE_SUPPORT */

    /* iterate over all configured sectors (they are allowed to be sorted
       independently of their physical order) */
    for (u32ConfigIter = 0U; u32ConfigIter < Fls_pConfigPtr->u32SectorCount; u32ConfigIter++ )
    {
            /* This sector is configured to be unlocked? */
            if (1U == (*(Fls_pConfigPtr->paSectorUnlock))[u32ConfigIter])
            {
                /* Read LOCK registers */
                /* If belong to LOCK0 register */
                if(FLASH_LOCK0_ADDR32 == (uint32)(*((*(Fls_pConfigPtr->pSectorList))[u32ConfigIter])).u32AddrSpaceBloLockRegAddr)
                {
                    /* Directly set protection bit */
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */
                    REG_BIT_CLEAR32(FLASH_LOCK0_ADDR32, (uint32)(*((*(Fls_pConfigPtr->pSectorList))[u32ConfigIter])).u32AddrSpaceBloLockValue);
                }
                else if (FLASH_LOCK1_ADDR32 == (uint32)(*((*(Fls_pConfigPtr->pSectorList))[u32ConfigIter])).u32AddrSpaceBloLockRegAddr)
                {
                    /* Directly set protection bit */
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */
                    REG_BIT_CLEAR32(FLASH_LOCK1_ADDR32, (uint32)(*((*(Fls_pConfigPtr->pSectorList))[u32ConfigIter])).u32AddrSpaceBloLockValue);
                }
                else if (FLASH_LOCK2_ADDR32 == (uint32)(*((*(Fls_pConfigPtr->pSectorList))[u32ConfigIter])).u32AddrSpaceBloLockRegAddr)
                {
                    /* Directly set protection bit */
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */
                    REG_BIT_CLEAR32(FLASH_LOCK2_ADDR32, (uint32)(*((*(Fls_pConfigPtr->pSectorList))[u32ConfigIter])).u32AddrSpaceBloLockValue);
                }
                else if (FLASH_LOCK3_ADDR32 == (uint32)(*((*(Fls_pConfigPtr->pSectorList))[u32ConfigIter])).u32AddrSpaceBloLockRegAddr)
                {
                    /* Directly set protection bit */
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */
                    REG_BIT_CLEAR32(FLASH_LOCK3_ADDR32, (uint32)(*((*(Fls_pConfigPtr->pSectorList))[u32ConfigIter])).u32AddrSpaceBloLockValue);
                }
                else
                {
                    /* No operation */
                }
            }
    } /* for (u32ConfigIter = 0U; u32ConfigIter < Fls_pConfigPtr->u32SectorCount; u32ConfigIter++ ) */


    u32ArrayIter = 0U;
    /* process all FLASH arrays */
    for( u32ArrayIter = 0U; u32ArrayIter < FLS_FLASH_ARRAY_COUNT; u32ArrayIter++ )
    {
        MCAL_FAULT_INJECTION_POINT(FLS_FIP_7_FLS_FLASH_INIT);
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */
        u32McrValue =  REG_READ32(FLASH_MCR_ADDR32);
        /* is program suspend operation possible within array? */
        if((boolean)TRUE == Fls_Flash_aArrayList0[u32ArrayIter].bProgramSuspPossible)
        {
            /* this sector a candidate to be in erase suspend operation state */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_19 Conversions shall not be
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type
            * and an integral type
            */
            if(0U != REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_PSUS_U32))
            {
                /* suspended operation cannot be aborted, */
                /* so resume previously suspended program operation, and */
                /*
            * performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
                */
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PSUS_U32);
                MCAL_FAULT_INJECTION_POINT(FLS_FIP_8_FLS_FLASH_INIT);

                /* if definitely in suspended operation state ...
                  (PSUS Bit can be cleared only if suspended operation is completed)*/
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
                */
                if(0U == REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_PSUS_U32))
                {
                    /* immediatly abort it */
                    if((boolean)TRUE == Fls_Flash_FinishHVOperation() )
                    {
                        /* terminate aborted program operation */
                        /*
                        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                        * @violates @ref fls_flash_c_REF_23 Conversions shall not be
                        * performed between a pointer to a function and any type other than an integral type
                        */
                        REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32);
                    }
                    else
                    {
                        /* Error, program was not aborted */
                                    #if( FLS_TRANSIENT_FAULT_DETECT == STD_ON )
                    (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_WRITE_FAILED);
                    #endif
                                        Fls_eLLDJob = FLASH_JOB_NONE;
                        Fls_eLLDJobResult = MEMIF_JOB_FAILED;

                    }
                }
                else
                {
                    /* Error, program was not resumed because it is not yet suspended */
                                    #if( FLS_TRANSIENT_FAULT_DETECT == STD_ON )
                    (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_WRITE_FAILED);
                    #endif
                                    Fls_eLLDJob = FLASH_JOB_NONE;
                    Fls_eLLDJobResult = MEMIF_JOB_FAILED;

                }
            }
        }

        MCAL_FAULT_INJECTION_POINT(FLS_FIP_1_FLS_FLASH_INIT);

        /* update the value of MCR register */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        */
        u32McrValue =  REG_READ32(FLASH_MCR_ADDR32);
        /* is erase suspend operation possible within array? */
        if((boolean)TRUE == Fls_Flash_aArrayList0[u32ArrayIter].bEraseSuspPossible)
        {
            /* this sector a candidate to be in erase suspend operation state */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
            */
            if(0U != REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_ESUS_U32))
            {
                /* suspended operation cannot be aborted, */
                /* so resume previously suspended erase operation, and */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
                * @violates @ref fls_flash_c_REF_23 Conversions shall not be
                * performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type
                */
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ESUS_U32);

                MCAL_FAULT_INJECTION_POINT(FLS_FIP_2_FLS_FLASH_INIT);

                /* if definitely in suspended operation state ...
                  (ESUS Bit can be cleared only if suspended operation is completed)*/
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
                */
                if(0U == REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_ESUS_U32))
                {
                    /* immediatly abort it */
                    if( (boolean)TRUE == Fls_Flash_FinishHVOperation() )
                    {
                        /* terminate aborted erase operation */
                        /*
                        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                        * @violates @ref fls_flash_c_REF_23 Conversions shall not be
               * performed between a pointer to a function and any type other than an integral type
                        */
                        REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ERS_U32);
                    }
                    else
                    {
                        /* Error, erase was not aborted */
                        #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_ERASE_FAILED);
                        #endif
                        Fls_eLLDJob = FLASH_JOB_NONE;
                        Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                    }
                }
                else
                {
                    /* Error, erase was not resumed because it is not yet suspended */
                    #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_ERASE_FAILED);
                    #endif
                    Fls_eLLDJob = FLASH_JOB_NONE;
                    Fls_eLLDJobResult = MEMIF_JOB_FAILED;

                }
            }
        }
        /* update the value of MCR register */
        /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type
    * and an integral type
    */
        u32McrValue = REG_READ32(FLASH_MCR_ADDR32);
        /* abort possible pending normal erase/program operation */
        if((0U != (u32McrValue & FLASH_MCR_ERS_U32)) || (0U != (u32McrValue & FLASH_MCR_PGM_U32)))
        {
           /* manage abort possible pending normal erase/program operation */
        if( (boolean)TRUE == Fls_Flash_FinishHVOperation() )
            {
                /* terminate erase operation */
                /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type
                */
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ERS_U32);
                /* terminate program operation */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
                */
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32);
            }
            else
            {
                /* Error, operation was not aborted */
                            /* @violates @ref fls_c_REF_43 All macro identifers in preprocessor directives shall be defned before use */
                #if( FLS_TRANSIENT_FAULT_DETECT == STD_ON )
                if( 0U != (u32McrValue & FLASH_MCR_ERS_U32) )
                {
                    (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_ERASE_FAILED);
                }
                if( 0U != (u32McrValue & FLASH_MCR_PGM_U32) )
                {
                    (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_WRITE_FAILED);
                }
                #endif
                            Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_FAILED;

            }
        }

        /* clear possible SBC, EER, RWE events within array */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
        */
        REG_BIT_SET32(FLASH_MCR_ADDR32,FLASH_MCR_SBC_W1C|FLASH_MCR_EER_W1C|FLASH_MCR_RWE_W1C);

        /* clear block select registers */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
        */
        REG_WRITE32(FLASH_SEL0_ADDR32,0U);
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
        */
        REG_WRITE32(FLASH_SEL1_ADDR32,0U);
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
        */
        REG_WRITE32(FLASH_SEL2_ADDR32,0U);
    }
}

/**
* @brief          Managing Abort Erase suspend.
* @details        An erase suspend is resumed and after immediately aborted
*/
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_AbortSuspended( VAR( uint8, AUTOMATIC) u8ServiceID )
{
    VAR(uint32, AUTOMATIC) u32ArrayIter = 0UL;
    VAR(uint32, AUTOMATIC) u32McrValue = 0UL;
    VAR( Fls_LLDReturnType, AUTOMATIC ) eRetVal = FLASH_E_OK;

    for( u32ArrayIter = 0U; u32ArrayIter < FLS_FLASH_ARRAY_COUNT; u32ArrayIter++ )
    {
        MCAL_FAULT_INJECTION_POINT(FLS_FIP_5_FLS_FLASH_ABORT_SUSPENDED);
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        */
        u32McrValue = REG_READ32(FLASH_MCR_ADDR32);
        /* is program suspend operation possible within array? */
        if((boolean)TRUE == Fls_Flash_aArrayList0[u32ArrayIter].bProgramSuspPossible)
        {
            /* this sector a candidate to be in erase suspend operation state */
            if(0U != (u32McrValue & FLASH_MCR_PSUS_U32))
            {
                /* suspended operation cannot be aborted, */
                /* so resume previously suspended program operation, and */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
                */
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PSUS_U32);

                MCAL_FAULT_INJECTION_POINT(FLS_FIP_6_FLS_FLASH_ABORT_SUSPENDED);
                /* if definitely in suspended operation state ...
                  (PSUS Bit can be cleared only if suspended operation is completed)*/
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
                */
                if(0U == REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_PSUS_U32))
                {
                    /* immediatly abort it */
                    if((boolean)TRUE == Fls_Flash_FinishHVOperation() )
                    {
                        /* terminate aborted program operation */
                        /*
                        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                        * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
                        */
                        REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32);
                    }
                    else
                    {
                        /* Error, program was not aborted */
                                            /* @violates @ref fls_c_REF_43 All macro identifers in preprocessor directives shall be defned before use */
                        #if( FLS_TIMEOUT_HANDLING == STD_ON )
                        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, u8ServiceID, FLS_E_TIMEOUT);
                        #endif
                                            eRetVal = FLASH_E_FAILED;
                    }
                }
                else
                {
                    /* Error, program was not resumed because it is not yet suspended */
                                    /* @violates @ref fls_c_REF_43 All macro identifers in preprocessor directives shall be defned before use */
                    #if( FLS_TRANSIENT_FAULT_DETECT == STD_ON )
                    (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, u8ServiceID, FLS_E_WRITE_FAILED);
                    #endif
                                    eRetVal = FLASH_E_FAILED;
                }
            }
        }

        MCAL_FAULT_INJECTION_POINT(FLS_FIP_3_FLS_FLASH_ABORT_SUSPENDED);

        /* update the value of MCR register */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
        */
        u32McrValue = REG_READ32(FLASH_MCR_ADDR32);
        /* is erase suspend operation possible within array? */
        if((boolean)TRUE == Fls_Flash_aArrayList0[u32ArrayIter].bEraseSuspPossible)
        {
            /* this sector a candidate to be in erase suspend operation state */
            if(0U != (u32McrValue & FLASH_MCR_ESUS_U32))
            {
                /* suspended operation cannot be aborted, */
                /* so resume previously suspended erase operation, and */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
                */
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ESUS_U32);

                MCAL_FAULT_INJECTION_POINT(FLS_FIP_4_FLS_FLASH_ABORT_SUSPENDED);

                /* if definitely in suspended operation state ...
                  (ESUS Bit can be cleared only if suspended operation is completed)*/
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
                */
                if(0U == REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_ESUS_U32))
                {
                    /* immediatly abort it */
                    if( (boolean)TRUE == Fls_Flash_FinishHVOperation() )
                    {
                        /* terminate aborted erase operation */
                        /*
                        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                        * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
                        */
                        REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ERS_U32);
                    }
                    else
                    {
                        /* Error, erase was not aborted */
                                            /* @violates @ref fls_c_REF_43 All macro identifers in preprocessor directives shall be defned before use */
                        #if( FLS_TIMEOUT_HANDLING == STD_ON )
                        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, u8ServiceID, FLS_E_TIMEOUT);
                        #endif
                                            eRetVal = FLASH_E_FAILED;
                    }
                }
                else
                {
                    /* Error, erase was not resumed because it is not yet suspended */
                                    /* @violates @ref fls_c_REF_43 All macro identifers in preprocessor directives shall be defned before use */
                    #if( FLS_TRANSIENT_FAULT_DETECT == STD_ON )
                    (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, u8ServiceID, FLS_E_ERASE_FAILED);
                    #endif
                                    eRetVal = FLASH_E_FAILED;
                }
            }
        }
    }
    return eRetVal;
}

#if(( FLS_ERASE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_BLANK_CHECK == STD_ON )||(FLS_WRITE_VERIFY_CHECK == STD_ON) || ( FLS_COMPARE_API == STD_ON ) || ( FLS_BLANK_CHECK_API == STD_ON ))
/**
* @brief          Check that the addressed flash memory area is erased or written
* @details        The function compares the contents of the addressed flash memory
*                 area against the value of an erased flash cell to check that the block
*                 has been completely erased or written
*
* @param[in]      1           u32FlashAreaPtr is variable to contain first address of the addressed flash memory area
*                             aligned to MCU bus width boundary
* @param[in]      2           pUserBufferPtr first address of the application buffer area
*                             aligned to MCU bus width boundary
* @param[in]      3           u32DataLength number of bytes to compare aligned to the MCU bus
*                             width
*
* @return         Fls_LLDReturnType
* @retval         FLASH_E_OK operation succeeded
* @retval         FLASH_E_FAILED operation failed due to hardware error (ECC)
*                 or contents of the addressed memory area don't match with value of
*                 an erased flash cell
*
* @note           Report the FLS_E_VERIFY_ERASE_FAILED Det error when the blank
*                 check operation failed due to hardware error (ECC) or contents of
*                 the addressed memory area didn't match with value of an erased
*                 flash cell
*/
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_VerifyMemoryArea
(
    VAR(volatile Fls_Flash_DataBusWidthType, AUTOMATIC ) u32FlashAreaPtr,
    P2CONST( Fls_Flash_DataBusWidthType, AUTOMATIC, FLS_APPL_CONST ) pUserBufferPtr,
    VAR(Fls_LengthType, AUTOMATIC) u32DataLength
)
{
    VAR(Fls_DataBytesType, AUTOMATIC) u8DataLength = FLS_SIZE_1BYTE;
#if( FLS_DSI_HANDLER_API == STD_ON )
    Fls_Flash_eCompareStatus = FLASH_E_PENDING;
    Fls_Flash_eReadStatus = FLASH_E_OK;
#endif

    /* Start address to be compared */
    /*
    * @violates @ref fls_flash_c_REF_16 cast from pointer to unsigned long Due to casting between a pointer and unsigned long representing address
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
    Fls_Flash_pReadAddressPtr = (uint8 *)u32FlashAreaPtr;

    /* Source address to be compared */
    if(NULL_PTR != pUserBufferPtr)
    {
        /* @violates @ref fls_c_REF_2 A cast should not be performed between a pointer to object type and a different pointer to object type */
        Fls_Flash_pCompareAddressPtr = (const uint8 *)pUserBufferPtr;
    }
#if ((FLS_BLANK_CHECK_API == STD_ON) || (FLS_ERASE_BLANK_CHECK == STD_ON))
    else
    {
        /* @violates @ref fls_c_REF_2 A cast should not be performed between a pointer to object type and a different pointer to object type */
        Fls_Flash_pCompareAddressPtr = (volatile const uint8 *)(&Fls_Flash_ErasedValue);
    }
#endif
#ifdef CACHE_INVALIDATE_MACROS
#if (CACHE_INVALIDATE_MACROS == STD_ON)
    /* Invalidate the cache, in order to display the erased flash values */
    Mcl_CacheInvalidateAll();
#endif /* CACHE_INVALIDATE_MACROS == STD_ON */
#endif /* ifdef CACHE_INVALIDATE_MACROS */

#if(FLS_EXTENDED_READ_ERROR_CHECK == STD_ON)
    /* clear read monitoring error flags (w1c) */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    */
    REG_BIT_SET32(FLASH_MCR_ADDR32, FLASH_MCR_RVE_W1C | FLASH_MCR_RRE_W1C | FLASH_MCR_RWE_W1C | FLASH_MCR_SBC_W1C);
#endif

    do
    {
        /* Verifying 4 byte if it is aligned */
        /* Compiler_Warning: see fls_c_REF_CW_01 */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.This violation is because of complex statement
        * @violates @ref fls_flash_c_REF_2 A conversion should not be performed between a pointer to object and an integer type
        */
        if((4U <= u32DataLength ) && (0U == ( (uint32)Fls_Flash_pReadAddressPtr % 4U )) && (0U == ( (uint32)Fls_Flash_pCompareAddressPtr % 4U )))
        {
            u8DataLength = FLS_SIZE_4BYTE;
        }
        else /* Verifying 1 byte if it is not aligned */
        {
            u8DataLength = FLS_SIZE_1BYTE;
        }

        if(FLASH_E_FAILED == Fls_Flash_ReadBytes(u8DataLength))
        {
            /* Errors occurred when verify the memory flash*/
            /* @violates @ref fls_flash_c_REF_5 Return statement before end of function.*/
            return FLASH_E_FAILED;
        }

        if (FLS_SIZE_1BYTE == u8DataLength)
        {
            if( *Fls_Flash_pCompareAddressPtr != Fls_Flash_u8ReadAddress8 )
            {
#if( FLS_DSI_HANDLER_API == STD_ON )
                if( FLASH_E_PENDING == Fls_Flash_eCompareStatus )
                {
                    Fls_Flash_eCompareStatus = FLASH_E_BLOCK_INCONSISTENT;
                }
#else
                /* @violates @ref fls_flash_c_REF_5 Return statement before end of function.*/
                return FLASH_E_BLOCK_INCONSISTENT;        /* Read data differs from expected value */
#endif /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
            }
        }
        /* Compare 4byte*/
        else
        {
            /* @violates @ref fls_flash_c_REF_2 A conversion should not be performed between a pointer to object and an integer type */
            if( ((uint32)(*(const volatile uint32 *)Fls_Flash_pCompareAddressPtr)) != Fls_Flash_u32ReadAddress32 )
            {
#if( FLS_DSI_HANDLER_API == STD_ON )
                if( FLASH_E_PENDING == Fls_Flash_eCompareStatus )
                {
                    Fls_Flash_eCompareStatus = FLASH_E_BLOCK_INCONSISTENT;
                }
#else
                /* @violates @ref fls_flash_c_REF_5 Return statement before end of function.*/
                return FLASH_E_BLOCK_INCONSISTENT;         /* Read data differs from expected value */
#endif /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
            }
        }

        if(NULL_PTR != pUserBufferPtr)
        {
            /* @violates @ref fls_flash_c_REF_15 Cast of complex expression changes signedness */
            Fls_Flash_pCompareAddressPtr += (uint32)u8DataLength;
        }
        /* @violates @ref fls_flash_c_REF_15 Cast of complex expression changes signedness */
        Fls_Flash_pReadAddressPtr += (uint32)u8DataLength;
        u32DataLength -= (uint32)u8DataLength;
#if( FLS_DSI_HANDLER_API == STD_ON )
    /*
     * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.This violation is because of complex statement
     */
    }while((u32DataLength > 0U) && ( FLASH_E_PENDING == Fls_Flash_eCompareStatus ));
#else /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
    }while(u32DataLength > 0U);
#endif /* #if( FLS_DSI_HANDLER_API == STD_ON ) */

#if(FLS_EXTENDED_READ_ERROR_CHECK == STD_ON)
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.
    */
    if(0U != REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_RVE_W1C | FLASH_MCR_RRE_W1C | FLASH_MCR_RWE_W1C | FLASH_MCR_SBC_W1C ))
    {
        return FLASH_E_FAILED;
    }
#endif /* #if(FLS_EXTENDED_READ_ERROR_CHECK == STD_ON) */

#if( FLS_DSI_HANDLER_API == STD_ON )
    if( FLASH_E_PENDING == Fls_Flash_eCompareStatus )
    {
        Fls_Flash_eCompareStatus = FLASH_E_OK;
    }
    return Fls_Flash_eCompareStatus;
#else
    return FLASH_E_OK;
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
}
#endif    /* FLS_ERASE_BLANK_CHECK  || FLS_WRITE_BLANK_CHECK*/

static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_ReadBytes
(
    VAR(Fls_DataBytesType, AUTOMATIC) u8DataLength
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;

#if( FLS_DSI_HANDLER_API == STD_ON )
    VAR( boolean, AUTOMATIC ) bWasEccEvent = (boolean)FALSE;
#endif /* #if( FLS_DSI_HANDLER_API == STD_ON ) */

#if( FLS_DSI_HANDLER_API == STD_ON )
        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
        /* clear EER flags (w1c) */
        /*
         * @violates @ref fls_flash_c_REF_16 cast from pointer to unsigned long Due to casting between a pointer and unsigned long representing address
         * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
         */
        REG_BIT_SET32(FLASH_MCR_ADDR32,FLASH_MCR_EER_W1C );
#endif /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
    /* Read flash location */
    if ((Fls_DataBytesType)FLS_SIZE_1BYTE == (Fls_DataBytesType)u8DataLength)
    {
        Fls_Flash_u8ReadAddress8 = *Fls_Flash_pReadAddressPtr;
    }
    else if (FLS_SIZE_4BYTE == u8DataLength)
    {
        /* @violates @ref fls_flash_c_REF_2 A conversion should not be performed between a pointer to object and an integer type */
        Fls_Flash_u32ReadAddress32 = *(volatile uint32 *)Fls_Flash_pReadAddressPtr;
    }
    else
    {
        /* Errors because to configuration*/
        /* @violates @ref Fls_Flash_c_REF_4 A function should have a single point of exit at the end */
        /* @violates @ref fls_flash_c_REF_5 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
#if( FLS_DSI_HANDLER_API == STD_ON )
    if( ((boolean)FALSE) == (uint32)(*((*(Fls_pConfigPtr->pSectorList))[Fls_u32JobSectorIt])).bEccTriggersExc )
    {
        /* This sector does not trigger an interrupt when encountering an ECC. We need to verify the ECC status bit. */
        /*
         * @violates @ref fls_flash_c_REF_16 cast from pointer to unsigned long Due to casting between a pointer and unsigned long representing address
         * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
         */
        if(0U != REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_EER_W1C))
        {
            bWasEccEvent = Fls_Flash_ECCTest();
        }
        else
        {
            bWasEccEvent = (boolean)FALSE;
        }
    }
    /* end flash access section: implementation depends on integrator */
    if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
    {
        /* Call Fls_FinishedFlashAccessNotif function if configured */
        Fls_pConfigPtr->finishedFlashAccessNotifPtr();
    }

    if (((boolean)TRUE) == bWasEccEvent)
    {
        if( FLASH_E_PENDING == Fls_Flash_eCompareStatus )
        {
            Fls_Flash_eCompareStatus = FLASH_E_FAILED;
        }
        if( FLASH_E_PENDING == Fls_Flash_eReadStatus )
        {
            Fls_Flash_eReadStatus = FLASH_E_FAILED;
        }
    }
#endif /* #if( FLS_DSI_HANDLER_API == STD_ON ) */

    return eRetVal;
}

FUNC( void, FLS_CODE ) Fls_Flash_MainFunctionErase( void )
{
    /* FLASH_JOB_ERASE */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
    if(0U != REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_DONE_U32))
    {
        /* erase/program high voltage sequence already finished */

        /* verify that erase operation was successful */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */
        if(0U != REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_PEG_U32 ))
        {
            /* disable high voltage */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_EHV_U32 );
            /* terminate erase operation */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ERS_U32 );

            /* clear block select registers */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            REG_WRITE32(FLASH_SEL0_ADDR32,0U);
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            REG_WRITE32(FLASH_SEL1_ADDR32,0U);
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            REG_WRITE32(FLASH_SEL2_ADDR32,0U);

#if( FLS_ERASE_BLANK_CHECK == STD_ON )
            /* schedule erase blank check of flash sector */
            Fls_eLLDJob = FLASH_JOB_ERASE_BLANK_CHECK;
#else
            /* erase operation succeed */
            Fls_u32JobSectorIt++;   /* The sector was successfully erased, increment the sector iterator.*/

            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_OK;
#endif /* FLS_ERASE_BLANK_CHECK == STD_ON */
        }
        else
        {
            /* disable high voltage */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_EHV_U32 );
            /* terminate erase operation */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ERS_U32 );
            /* clear block select registers */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            REG_WRITE32(FLASH_SEL0_ADDR32,0U);
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            REG_WRITE32(FLASH_SEL1_ADDR32,0U);
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            REG_WRITE32(FLASH_SEL2_ADDR32,0U);
            /* erase operation failed */
                    /* @violates @ref fls_c_REF_43 All macro identifers in preprocessor directives shall be defned before use */
            #if( FLS_TRANSIENT_FAULT_DETECT == STD_ON )
            (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
            #endif
                    Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
        }
    }
    else
    {
#if (FLS_TIMEOUT_HANDLING == STD_ON)
        /* Operation in progress, handle possible timeout */
        Fls_u32LLDTimeout_Counter--;
        if( 0U == Fls_u32LLDTimeout_Counter )
        {
            /* Abort the HV operation */
           (void) Fls_Flash_FinishHVOperation();
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ERS_U32 );
            /* clear block select registers */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            REG_WRITE32(FLASH_SEL0_ADDR32,0U);
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            REG_WRITE32(FLASH_SEL1_ADDR32,0U);
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            REG_WRITE32(FLASH_SEL2_ADDR32,0U);
            /* erase operation failed */
            /* @violates @ref fls_c_REF_43 All macro identifers in preprocessor directives shall be defned before use */
            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
            (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
            #endif
            #if( FLS_TRANSIENT_FAULT_DETECT == STD_ON )
            (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
            #endif
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
        }
#else
        /* erase/program high voltage sequence didn't finished yet */
        /* wait for another call of Fls_Flash_MainFunction, do nothing */
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }
}

FUNC( void, FLS_CODE ) Fls_Flash_MainFunctionWrite( void )
{
    /* FLASH_JOB_WRITE */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
    if(0U != REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_DONE_U32))
    {
        /* erase/program high voltage sequence already finished */

        /* verify that program operation was successful */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */
        if(0U != REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_PEG_U32 ))
        {
            /* program operation was successful */

            /* disable high voltage */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_EHV_U32 );

            #if( FLS_WRITE_VERIFY_CHECK == STD_ON )
            /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic */
            if( FLASH_E_OK != Fls_Flash_VerifyMemoryArea \
                                /* Compiler_Warning: see fls_c_REF_CW_01 */
                                /*
                                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                                * @violates @ref fls_flash_c_REF_16 cast from pointer to unsigned long Due to casting between a pointer and unsigned long representing address
                                * @violates @ref fls_flash_c_REF_15 Cast of complex expression changes signedness
                                */
                                 ( (uint32)(Fls_Flash_pTargetAddressPtr - (Fls_u32LLDNumberOfStepBack/4U)), \
                                 /* @violates @ref fls_flash_c_REF_15 Cast of complex expression changes signedness*/
                                  Fls_Flash_pSourceAddressPtr - (Fls_u32LLDNumberOfStepBack/4U), \
                                  Fls_u32LLDNumberOfStepBack \
                                )
              )
            {
                /* terminate program operation */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                */
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32 );

                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_WRITE_FAILED);
                #endif
                /* @violates @ref fls_flash_c_REF_5 Return statement before end of function. */
                return;
            }
            #endif    /* FLS_WRITE_VERIFY_CHECK == STD_ON */

            /* more double word program operation to be performed? */
            if(Fls_Flash_u32ProgramCycle<Fls_Flash_u32DoubleWordToCopy)
            {
                /* continue with next double word program operation */

                /* if not page aligned execute dw programming */
                /* Compiler_Warning: see fls_c_REF_CW_01 */
                /*
                * @violates @ref fls_c_REF_41 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_7 Booleans operands are not used for logical operators '&&', '||' and '!'
                * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on undefned or unspecifed behaviour.
                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type
                * @violates @ref fls_c_REF_7 Booleans operands are not used for logical operators '&&', '||' and '!' and an integral type
                * @violates @ref fls_c_REF_8 The right-hand operand of a logical && or || operator shall not contain side effects.
                */
                if( (0U !=((uint32)Fls_Flash_pTargetAddressPtr % (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt] ))|| \
                    (Fls_u32LLDRemainingDataToWrite < (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt] ) \
                  )
                {
                    #if( FLS_WRITE_BLANK_CHECK == STD_ON )
                    /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic */
                    if( FLASH_E_OK != Fls_Flash_VerifyMemoryArea \
                                        /* Compiler_Warning: see fls_c_REF_CW_01 */
                                        /*
                                        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                                        * @violates @ref fls_flash_c_REF_16 cast from pointer to unsigned long Due to casting between a pointer and unsigned long representing address
                                        */
                                        ( (uint32)Fls_Flash_pTargetAddressPtr, \
                                           NULL_PTR, \
                                          (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt] \
                                        )
                      )
                    {
                        /* terminate program operation */
                        /*
                        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                        * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                        */
                        REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32 );

                        Fls_eLLDJob = FLASH_JOB_NONE;
                        Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                        #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_ERASE_FAILED);
                        #endif
                        /* @violates @ref fls_c_REF_5 Return statement before end of function. */
                        return;
                    }
                    #endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */
                    /*It is time to do word or double word programming */
                    /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic */
                    Fls_Flash_PageWrite((*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt]);
                    Fls_Flash_u32ProgramCycle++;
                    /*
                    * @violates @ref fls_flash_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic
                    * @violates @ref fls_c_REF_7 Booleans operands are not used for logical operators '&&', '||' and '!'
                    */
                    Fls_u32LLDRemainingDataToWrite -= (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt];
                    #if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                    /* target and source address has been incresed by Fls_Flash_PageWrite,
                       so we need a number of step back for both pointer to perform a write
                       verify check*/
                    /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic */
                    Fls_u32LLDNumberOfStepBack = (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt];
                    #endif
                }
                else
                {
                    #if( FLS_WRITE_BLANK_CHECK == STD_ON )
                    if( FLASH_E_OK != Fls_Flash_VerifyMemoryArea \
                                        /* Compiler_Warning: see fls_c_REF_CW_01 */
                                        /*
                                        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                                        * @violates @ref fls_flash_c_REF_16 cast from pointer to unsigned long Due to casting between a pointer and unsigned long representing address
                                        */
                                        ( (uint32)Fls_Flash_pTargetAddressPtr, \
                                          NULL_PTR, \
                                          (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt] \
                                        )
                      )
                    {
                        /* terminate program operation */
                        /*
                        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                        * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                        */
                        REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32 );

                        Fls_eLLDJob = FLASH_JOB_NONE;
                        Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                        #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_ERASE_FAILED);
                        #endif
                        /* @violates @ref fls_c_REF_5 Return statement before end of function. */
                        return;
                    }
                    #endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */
                    /* it is time to do page programming */
                    Fls_Flash_PageWrite((*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt]);
                    Fls_Flash_u32ProgramCycle+=Fls_Flash_u32DoubleWordCounter;
                    /*
                    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on undefined or unspecified behaviour
                    * @violates @ref fls_c_REF_7 Booleans operands are not used for logical operators '&&', '||' and '!'
                    */
                    Fls_u32LLDRemainingDataToWrite -= (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt];
                    #if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                    /* target and source address has been increased by Fls_Flash_PageWrite,
                       so we need a number of step back for both pointer to perform a write
                       verify check*/
                    Fls_u32LLDNumberOfStepBack = (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt];
                    #endif
                }

                /* start internal erase/program sequence */
                /*
                * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */
                REG_BIT_SET32(FLASH_MCR_ADDR32,FLASH_MCR_EHV_U32 );

                Fls_eLLDJob = FLASH_JOB_WRITE;
                Fls_eLLDJobResult = MEMIF_JOB_PENDING;
            }
            else
            {
                /* all double word program operations succeed */
                /* terminate program operation */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                */
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32 );

                /* For a Write Job in ASYNC mode check if Fls_u32JobSectorIt should be increased */
                if( (Fls_u32JobAddrIt > ((*(Fls_pConfigPtr->paSectorEndAddr))[Fls_u32JobSectorIt]) ))
                {
                    /* Move on to the next sector */
                    Fls_u32JobSectorIt++;
                }

                /* program operation succeed */
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_OK;
            }
        }
        else
        {
            /* program operation was not successful */

            /* disable high voltage */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed
            * between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
            */
            REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_EHV_U32 );
            /* terminate program operation */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed
            * between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
            */
            REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32 );
            /* program operation failed */

                    /* @violates @ref fls_c_REF_43 All macro identifers in preprocessor directives shall be defned before use */
            #if( FLS_TRANSIENT_FAULT_DETECT == STD_ON )
            (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
            #endif
                    Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
        }
    }
    else
    {
#if (FLS_TIMEOUT_HANDLING == STD_ON)
        /* Operation in progress, handle possible timeout */
        Fls_u32LLDTimeout_Counter--;
        if( 0U == Fls_u32LLDTimeout_Counter )
        {
            /* Abort the HV operation */
            (void) Fls_Flash_FinishHVOperation();
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32);
            /* write operation failed */

            /* @violates @ref fls_c_REF_43 All macro identifers in preprocessor directives shall be defned before use */
            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
            (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
            #endif
            #if( FLS_TRANSIENT_FAULT_DETECT == STD_ON )
            (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
            #endif
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
        }
#else
        /* erase/program high voltage sequence didn't finished yet */
        /* wait for another call of Fls_Flash_MainFunction, do nothing */
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }
}

#if( FLS_ERASE_BLANK_CHECK == STD_ON )
FUNC( void, FLS_CODE ) Fls_Flash_MainFunctionEraseBlankCheck( void )
{
    /* FLASH_JOB_ERASE_BLANK_CHECK */
    /*
    * @violates @ref fls_flash_c_REF_13 Pointer subtraction shall only be applied to pointers that address elements of the same array
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_33 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    */
    while (Fls_Flash_pTargetAddressPtr < Fls_Flash_pEndAddressPtr)
    {
        /*
        * @violates @ref fls_flash_c_REF_13 Pointer subtraction shall only be applied to pointers that address elements of the same array
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic
        * @violates @ref fls_c_REF_33 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        */
        if (((Fls_Flash_pEndAddressPtr - Fls_Flash_pTargetAddressPtr)*4U) >=
              FLS_MAX_ERASE_BLANK_CHECK
           )
        {
            /* at least one erase blank check with FLS_MAX_ERASE_BLANK_CHECK size */
            if( FLASH_E_OK != Fls_Flash_VerifyMemoryArea
                                /* Compiler_Warning: see fls_c_REF_CW_01 */
                                /*
                                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                                * @violates @ref fls_flash_c_REF_16 cast from pointer to unsigned long Due to casting between a pointer and unsigned long representing address
                                */
                                ( (uint32)Fls_Flash_pTargetAddressPtr,
                                  NULL_PTR, \
                                  FLS_MAX_ERASE_BLANK_CHECK
                                )
              )
            {
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_ERASE_FAILED);
            #endif
                /* @violates @ref fls_flash_c_REF_5 Return statement before end of function. */
                return;
            }
            /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic */
            Fls_Flash_pTargetAddressPtr += FLS_MAX_ERASE_BLANK_CHECK/(Fls_Flash_DataBusWidthType)4;
            /* @violates @ref fls_flash_c_REF_5 Return statement before end of function. */
            return;
        }
        else
        {
            /* at least one erase blank check with 4 bytes size */
            if( FLASH_E_OK != Fls_Flash_VerifyMemoryArea \
                                /* Compiler_Warning: see fls_c_REF_CW_01 */
                                /*
                                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                                * @violates @ref fls_flash_c_REF_16 cast from pointer to unsigned long Due to casting between a pointer and unsigned long representing address
                                */
                                ( (uint32)Fls_Flash_pTargetAddressPtr, \
                                  NULL_PTR, \
                            /*
                            * @violates @ref fls_flash_c_REF_13 Pointer subtraction shall only be applied to pointers that address elements of the same array
                            * @violates @ref fls_flash_c_REF_15 Cast of complex expression changes signedness
                            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type
                            * @violates @ref fls_flash_c_REF_27 The value of a complex expression of integer type shall only be cast to a type of the same signedness that is no wider than the underlying type of the expression.
                            * @violates @ref fls_c_REF_33 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                            */
                                  (Fls_LengthType)((Fls_Flash_pEndAddressPtr - Fls_Flash_pTargetAddressPtr)*4U) \
                                )
              )
            {
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_ERASE_FAILED);
            #endif
                /* @violates @ref fls_flash_c_REF_5 Return statement before end of function. */
                return;
            }
            /*
            * @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic
            * @violates @ref fls_flash_c_REF_13 Pointer subtraction shall only be applied to pointers that address elements of the same array
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_c_REF_33 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            Fls_Flash_pTargetAddressPtr += Fls_Flash_pEndAddressPtr - Fls_Flash_pTargetAddressPtr;
            /* @violates @ref fls_flash_c_REF_5 Return statement before end of function. */
            return;
        }
    }
    /* erase blank check succeeded */
    Fls_u32JobSectorIt++;   /* The sector was successfully erased, increment the sector iterator.*/

    Fls_eLLDJob = FLASH_JOB_NONE;
    Fls_eLLDJobResult = MEMIF_JOB_OK;
}
#endif

#if (FLS_CANCEL_API == STD_ON )
/**
* @brief          Cancel ongoing erase or write hardware job.
* @details        In case Async Operation is ongoing this function will abort the following jobs:
*                 - Erase
*                 - Erase on Interleaved sectors
*                 - Write
*                 .
*/
FUNC( void, FLS_CODE ) Fls_Flash_Cancel( void )
{
    if (FLASH_JOB_ERASE == Fls_eLLDJob )
    {
        /* FLASH_JOB_ERASE */
        /* hence make erase-abort operation */

        /* abort erase/program operation */
        if( (boolean)TRUE == Fls_Flash_FinishHVOperation() )
        {
            /* terminate erase operation */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
            */
            REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ERS_U32);
            /* clear block select registers */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
            */
            REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ERS_U32 );
            /* clear block select registers */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
            */
            REG_WRITE32(FLASH_SEL0_ADDR32,0U);
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
            */
            REG_WRITE32(FLASH_SEL1_ADDR32,0U);
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
            */
            REG_WRITE32(FLASH_SEL2_ADDR32,0U);

            /* erase operation canceled */
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_CANCELED;
        }
    }
    else
    {
        /* FLASH_JOB_WRITE */
        /* hence make program-abort operation */

        /* abort erase/program operation */
        if( (boolean)TRUE == Fls_Flash_FinishHVOperation() )
        {
            /* terminate program operation */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
            */
            REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);

            /* program operation canceled */
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_CANCELED;
        }
    }
}
#endif /* FLS_CANCEL_API == STD_ON */

/**
* @brief          Erase one complete flash sector.
*
* @param[in]      1           ePhySector Physical sector ID
* @param[in]      2           bAsynch Set to TRUE for asynchronous and FALSE for synchronous
*                             function operation
*
* @return         Fls_LLDReturnType
* @retval         FLASH_E_OK Operation succeeded
* @retval         FLASH_E_FAILED Operation failed due to hardware error
* @retval         FLASH_E_PENDING The operation has not yet been finished
*                 (only for asynchronous operation )
*
* @pre            ePhySector must be in range
* @pre            The module must be initialized
*
* @implements     Fls_Flash_SectorErase_Activity
*
* @note           Dem_ReportErrorStatus(Fls_pConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when erase operation failed due to hardware error
*/
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_SectorErase
(
    CONST( Fls_PhysicalSectorType, AUTOMATIC) ePhySector,
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
    CONST(Fls_LengthType, AUTOMATIC) u32PhysicalSectorSize,
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */
    CONST( boolean, AUTOMATIC) bAsynch
)
{
    VAR(uint32, AUTOMATIC) u32BloSelRegAddr = (uint32)(*((*(Fls_pConfigPtr->pSectorList))[ePhySector])).u32SectorBloSelRegAddr;
    VAR(uint32, AUTOMATIC) u32BloSelValue = (uint32)(*((*(Fls_pConfigPtr->pSectorList))[ePhySector])).u32AddrSpaceBloSelValue;
    VAR(uint32, AUTOMATIC) u32BloLockRegAddr = (uint32)(*((*(Fls_pConfigPtr->pSectorList))[ePhySector])).u32AddrSpaceBloLockRegAddr;
    VAR(uint32, AUTOMATIC) u32BloLockValue = (uint32)(*((*(Fls_pConfigPtr->pSectorList))[ePhySector])).u32AddrSpaceBloLockValue;

#if (FLS_TIMEOUT_HANDLING == STD_ON)
    VAR(uint32, AUTOMATIC) u32Abort_Timeout_Counter;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

    Fls_Flash_pTargetAddressPtr = (*((*(Fls_pConfigPtr->pSectorList))[ePhySector])).pSectorStartAddressPtr;

#if( FLS_ERASE_BLANK_CHECK == STD_ON )
    /*
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_33 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    */
    Fls_Flash_pEndAddressPtr = ((*((*(Fls_pConfigPtr->pSectorList))[ePhySector])).pSectorStartAddressPtr + (u32PhysicalSectorSize/(Fls_Flash_DataBusWidthType)4));
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */

    /* verify that EHV may be set */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    */
    if((0UL != REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_ERS_U32|FLASH_MCR_PGM_U32|FLASH_MCR_ESUS_U32)) || \
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    */
        (0UL != REG_BIT_GET32(FLASH_UT0_ADDR32, FLASH_UT0_AIE_U32))
    /* @violates @ref fls_c_REF_8 The right-hand operand of a logical && or || operator shall not contain side effects.     */
      )
    {
        /*  EHV may not be set: modify operation already in progress */
        /* @violates @ref fls_c_REF_5 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    /* verify that sector is not protected against erase/program operations */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    */
    if(REG_READ32(u32BloLockRegAddr) & u32BloLockValue )
    {
        /* sector protected: erase operation failed */
        /*  @violates @ref fls_flash_c_REF_5 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    if ((boolean)FALSE == bAsynch)
    {
        /* setup erase operation */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        */
        REG_BIT_SET32(FLASH_MCR_ADDR32, FLASH_MCR_ERS_U32);

        /* load adequate block select register */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        */
        REG_WRITE32(u32BloSelRegAddr, u32BloSelValue );
        /* make an erase interlock write, dummy data word write */
        *Fls_Flash_pTargetAddressPtr = 0xFFFFFFFFU;

#ifdef CACHE_INVALIDATE_MACROS
#if (CACHE_INVALIDATE_MACROS == STD_ON)
        /* Flush the interlock write from cache to flash */
        Mcl_CacheFlushAll();
#endif /* CACHE_INVALIDATE_MACROS == STD_ON */
#endif /* ifdef CACHE_INVALIDATE_MACROS */

#if (FLS_TIMEOUT_HANDLING == STD_ON)
        /* Initialize timeout counters */
        Fls_u32LLDTimeout_Counter = FLS_SYNC_ERASE_TIMEOUT_VALUE;
        u32Abort_Timeout_Counter = FLS_ABT_TIMEOUT_VALUE;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }

        MCAL_FAULT_INJECTION_POINT(FLS_FIP_11_FLS_FLASH_SECTOR_ERASE);

        /* call flash access code routine */
#if (FLS_TIMEOUT_HANDLING == STD_ON)
        /*
        * @violates @ref fls_flash_c_REF_14 Taking address of near auto variable.
        * @violates @ref fls_flash_c_REF_18 Cast from pointer to unsigned long
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */
        FLASH_AC_CALL(Fls_pConfigPtr->acErasePtr, Fls_AcErasePtrType)(FLASH_BASEADDR, Fls_pConfigPtr->acCallBackPtr, &Fls_u32LLDTimeout_Counter, &u32Abort_Timeout_Counter);
#else
        /*
        * @violates @ref fls_flash_c_REF_18 Cast from pointer to unsigned long
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */
        FLASH_AC_CALL(Fls_pConfigPtr->acErasePtr, Fls_AcErasePtrType)(FLASH_BASEADDR, Fls_pConfigPtr->acCallBackPtr);
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

        MCAL_FAULT_INJECTION_POINT(FLS_FIP_12_FLS_FLASH_SECTOR_ERASE);

        /* end flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }

        /* verify that erase operation was successful */
#if (FLS_TIMEOUT_HANDLING == STD_ON)
        /*  PEG is valid only after DONE transition to 1 which might not be the case if the timeout event occured */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        */
        if((0U != REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_PEG_U32)) && (0U != Fls_u32LLDTimeout_Counter) && (0U != u32Abort_Timeout_Counter))
#else
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */
        if(REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_PEG_U32))
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */
        {
            /* terminate erase operation */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_ERS_U32);

            /* clear adequate block select register */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
            */
            REG_WRITE32(u32BloSelRegAddr, 0U);
        }
        else
        {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
        #if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
            /*
            * @violates @ref fls_flash_c_REF_28 The value of an expression of integer type shall not be implicitly converted to a different underlying type.
            */
            if((0 == Fls_u32LLDTimeout_Counter)||(0 == u32Abort_Timeout_Counter))
                {
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
                }
        #endif
        #endif
            /* terminate erase operation */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be  performed between a pointer to a function and any type other than an integral type
            */
            REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_ERS_U32);

            /* clear adequate block select register */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            REG_WRITE32(u32BloSelRegAddr, 0U);
            /* erase operation failed */
            /* @violates @ref fls_c_REF_5 Return statement before end of function. */
            return FLASH_E_FAILED;
        }

#if( FLS_ERASE_BLANK_CHECK == STD_ON )
        /* Compiler_Warning: see fls_c_REF_CW_01 */
        /*
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_c_REF_41 Boolean operations whose results are invariant shall not be permitted
        */
        if( FLASH_E_OK != Fls_Flash_VerifyMemoryArea((uint32)Fls_Flash_pTargetAddressPtr, NULL_PTR, u32PhysicalSectorSize) )
        {
            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_ERASE_FAILED);
            #endif
            /* @violates @ref fls_flash_c_REF_5 Return statement before end of function. */
            return FLASH_E_FAILED;
        }
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */
        /* erase operation succeed */
        /* @violates @ref fls_flash_c_REF_6 Return statement before end of function. */
        return FLASH_E_OK;
    }
    else /* bAsynch == TRUE */
    {
        /* setup erase operation */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        */
        REG_BIT_SET32(FLASH_MCR_ADDR32, FLASH_MCR_ERS_U32);
        /* load adequate block select register */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        */
        REG_WRITE32(u32BloSelRegAddr, u32BloSelValue );
        /* make an erase interlock write, dummy data word write */
        *Fls_Flash_pTargetAddressPtr = 0xFFFFFFFFU;

#ifdef CACHE_INVALIDATE_MACROS
#if (CACHE_INVALIDATE_MACROS == STD_ON)
        /* Flush the interlock write from cache to flash */
        Mcl_CacheFlushAll();
#endif /* CACHE_INVALIDATE_MACROS == STD_ON */
#endif /* ifdef CACHE_INVALIDATE_MACROS */

        /* start internal erase/program sequence */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        */
        REG_BIT_SET32(FLASH_MCR_ADDR32, FLASH_MCR_EHV_U32);

        Fls_eLLDJob = FLASH_JOB_ERASE;
        Fls_eLLDJobResult = MEMIF_JOB_PENDING;

#if (FLS_TIMEOUT_HANDLING == STD_ON)
        /* Initialize timeout counter */
        Fls_u32LLDTimeout_Counter = FLS_ASYNC_ERASE_TIMEOUT_VALUE;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

        /*
        * @violates @ref fls_c_REF_5 Bitwise operators shall not be applied to operands whose underlying type is signed.
        * @violates @ref fls_c_REF_5 Bitwise operators shall not be applied to operands whose underlying type is signed.
        */
        return FLASH_E_PENDING;
    }
}

/**
* @brief          Write one or more complete flash pages into given flash sector.
*
* @param[in]      ePhySector Physical sector ID
* @param[in]      u32SectorOffset sector offset in bytes
* @param[in]      u32DataLength data length in bytes
* @param[in]      pDataPtr data to be written
* @param[in]      bAsynch set to TRUE for asynchronous and FALSE for synchronous function operation
*
* @return         Fls_LLDReturnType
* @retval         FLASH_E_OK Operation succeeded
* @retval         FLASH_E_FAILED Operation failed due to hardware error
* @retval         FLASH_E_PENDING The operation has not yet been finished
*                 (only for asynchronous operation )
*
* @pre            u32SectorOffset must be double word aligned
* @pre            u32DataLength must be multiple double word length
* @pre            ePhySector must be in range
* @pre            The module must be initialized
*
* @implements     Fls_Flash_SectorWrite_Activity
*
* @note           Dem_ReportErrorStatus(Fls_pConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when write operation failed due to hardware error
*/
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_SectorWrite
(
    CONST( Fls_PhysicalSectorType, AUTOMATIC) ePhySector,
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST(Fls_LengthType, AUTOMATIC) u32DataLength,
    CONSTP2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) pDataPtr,
    CONST( boolean, AUTOMATIC) bAsynch
)
{
    VAR(uint32, AUTOMATIC) u32BloLockRegAddr = (uint32)(*((*(Fls_pConfigPtr->pSectorList))[ePhySector])).u32AddrSpaceBloLockRegAddr;
    VAR(uint32, AUTOMATIC) u32BloLockValue = (uint32)(*((*(Fls_pConfigPtr->pSectorList))[ePhySector])).u32AddrSpaceBloLockValue;
#if (FLS_TIMEOUT_HANDLING == STD_ON)
    VAR(uint32, AUTOMATIC) u32Abort_Timeout_Counter;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

    /* @violates @ref fls_c_REF_2 A cast should not be performed between a pointer to object type and a different pointer to object type */
    Fls_Flash_pSourceAddressPtr = (const uint32*)(pDataPtr);
    /*
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic
    */
    Fls_Flash_pTargetAddressPtr = (*((*(Fls_pConfigPtr->pSectorList))[ePhySector])).pSectorStartAddressPtr + \
                               (u32SectorOffset/4U);

    Fls_u32LLDRemainingDataToWrite = u32DataLength;

    /* verify that EHV may be set */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    */
    if((0UL != REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_ERS_U32|FLASH_MCR_PGM_U32|FLASH_MCR_ESUS_U32)) || \
    /*
    * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.This violation is because of complex statement
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    */
        (0UL != REG_BIT_GET32(FLASH_UT0_ADDR32, FLASH_UT0_AIE_U32))
    /*
    * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.This violation is because of complex statement
    * @violates @ref fls_c_REF_8 The right-hand operand of a logical && or || operator shall not contain side effects.
    */
      )
    {
        /*  EHV may not be set: modify operation already in progress */
        /* @violates @ref fls_c_REF_5 Return statement before end of function. */
        return FLASH_E_FAILED;
    }

    /* Verify that sector is not protected against erase/program operations and Program Hardware Lock */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    */
    if (  REG_READ32(u32BloLockRegAddr) & u32BloLockValue)
    {
        /* Sector protected: program operation failed */
        /* @violates @ref fls_c_REF_5 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    /* Number of word (i.e.32bits=4bytes) double word (i.e.64bits=8bytes) to be copied  */
    /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic */
    Fls_Flash_u32DoubleWordToCopy = u32DataLength/(*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt];
    /* Number of word or dw to be copied in one program operation */
    /*
    * @violates @ref fls_c_REF_7 Booleans operands are not used  for logical operators '&&', '||' and '!'
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on undefned or unspecifed behaviour.
    */
    Fls_Flash_u32DoubleWordCounter = (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt] / (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt];
    Fls_Flash_u32ProgramCycle = 0U;

    /* before going into programming loop (and potential performing Verify Erase operation) and setting MCR[PGM],
       invalidate the flash prefetch buffer by performing a bogus interlock write while MCR[PGM,ERS] == 0 */
    *Fls_Flash_pTargetAddressPtr = 0x0UL;

#ifdef CACHE_INVALIDATE_MACROS
#if (CACHE_INVALIDATE_MACROS == STD_ON)
    /* Flush the interlock write from cache to flash */
    Mcl_CacheFlushAll();
#endif /* CACHE_INVALIDATE_MACROS == STD_ON */
#endif /* ifdef CACHE_INVALIDATE_MACROS */

    if ((boolean)FALSE == bAsynch)
    {
        /* setup program operation */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        */
        REG_BIT_SET32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);

        /* process all double word program operations */
        /*for( Fls_Flash_u32ProgramCycle=0U; Fls_Flash_u32ProgramCycle < Fls_Flash_u32DoubleWordToCopy; \
             Fls_Flash_u32ProgramCycle++ )*/
        while (Fls_Flash_u32ProgramCycle < Fls_Flash_u32DoubleWordToCopy)
        {

            /* if not page aligned execute dw programming */
            /* Compiler_Warning: see fls_c_REF_CW_01 */
            /*
            * @violates @ref fls_c_REF_41 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_c_REF_7 Booleans operands are not used  for logical operators '&&', '||' and '!'
            * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on undefned or unspecifed behaviour.
            */
            if( (0U != ((uint32)Fls_Flash_pTargetAddressPtr % (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt] )) || \
                (Fls_u32LLDRemainingDataToWrite < (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt] ) \
                /* @violates @ref fls_c_REF_8 The right-hand operand of a logical && or || operator shall not contain side effects.  */
              )
            {
#if( FLS_WRITE_BLANK_CHECK == STD_ON )
                /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic */
                if( FLASH_E_OK != Fls_Flash_VerifyMemoryArea \
                                    /* Compiler_Warning: see fls_c_REF_CW_01 */
                                    /*
                                    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                                    * @violates @ref fls_flash_c_REF_16 cast from pointer to unsigned long Due to casting between a pointer and unsigned long representing address
                                    */
                                    ( (uint32)Fls_Flash_pTargetAddressPtr, \
                                       NULL_PTR, \
                                      (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt] \
                                    )
                  )
                {
                    /* terminate program operation */
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    */
                    REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_ERASE_FAILED);
                    /* @violates @ref fls_c_REF_5 Return statement before end of function. */
                    return FLASH_E_FAILED;
                }
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */
                /*It is time to do word or double word programming */
                /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic */
                Fls_Flash_PageWrite((*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt]);
                Fls_Flash_u32ProgramCycle++;
                /*
                * @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic
                * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on undefned or unspecifed behaviour.
                * @violates @ref fls_c_REF_7 Booleans operands are not used for logical operators '&&', '||' and '!'
                */
                Fls_u32LLDRemainingDataToWrite -= (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt];
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                /* target and source address has been incresed by Fls_Flash_PageWrite,
                   so we need a number of step back for both pointer to perform a write
                   verify check*/
                /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic */
                Fls_u32LLDNumberOfStepBack = (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt];
#endif
            }
            else
            {
#if( FLS_WRITE_BLANK_CHECK == STD_ON )
                if( FLASH_E_OK != Fls_Flash_VerifyMemoryArea \
                                    /* Compiler_Warning: see fls_c_REF_CW_01 */
                                    /*
                                    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                                    * @violates @ref fls_flash_c_REF_16 cast from pointer to unsigned long Due to casting between a pointer and unsigned long representing address
                                    */
                                    ( (uint32)Fls_Flash_pTargetAddressPtr, \
                                       NULL_PTR, \
                                      (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt] \
                                    )
                  )
                {
                    /* terminate program operation */
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    */
                    REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);
                #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_ERASE_FAILED);
                #endif
                    /* @violates @ref fls_c_REF_5 Return statement before end of function. */
                    return FLASH_E_FAILED;
                }
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */
                /* it is time to do page programming */
                Fls_Flash_PageWrite((*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt]);
                Fls_Flash_u32ProgramCycle+=Fls_Flash_u32DoubleWordCounter;
                /*
                * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on undefned or unspecifed behaviour.
                * @violates @ref fls_c_REF_7 Booleans operands are not used for logical operators '&&', '||' and '!'
                */
                Fls_u32LLDRemainingDataToWrite -= (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt];
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                /* target and source address has been increased by Fls_Flash_PageWrite,
                   so we need a number of step back for both pointer to perform a write
                   verify check*/
                Fls_u32LLDNumberOfStepBack = (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt];
#endif
            }

#if (FLS_TIMEOUT_HANDLING == STD_ON)
            /* Initialize timeout counters */
            Fls_u32LLDTimeout_Counter = FLS_SYNC_WRITE_TIMEOUT_VALUE;
            u32Abort_Timeout_Counter = FLS_ABT_TIMEOUT_VALUE;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

            /* start flash access section: implementation depends on integrator */
            if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
            {
                /* Call FlsStartFlashAccessNotif function if configured */
                Fls_pConfigPtr->startFlashAccessNotifPtr();
            }

            MCAL_FAULT_INJECTION_POINT(FLS_FIP_13_FLS_FLASH_SECTOR_WRITE);

            /* call flash access code routine */
#if (FLS_TIMEOUT_HANDLING == STD_ON)
            /*
            * @violates @ref fls_flash_c_REF_14 Taking address of near auto variable.
            * @violates @ref fls_flash_c_REF_18 Cast from pointer to unsigned long
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type  and an integral type
            */
            FLASH_AC_CALL(Fls_pConfigPtr->acWritePtr, Fls_AcWritePtrType)(FLASH_BASEADDR, Fls_pConfigPtr->acCallBackPtr, &Fls_u32LLDTimeout_Counter, &u32Abort_Timeout_Counter);
#else
            /*
            * @violates @ref fls_flash_c_REF_18 Cast from pointer to unsigned long
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            */
            FLASH_AC_CALL(Fls_pConfigPtr->acWritePtr, Fls_AcWritePtrType)(FLASH_BASEADDR, Fls_pConfigPtr->acCallBackPtr);
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

            MCAL_FAULT_INJECTION_POINT(FLS_FIP_14_FLS_FLASH_SECTOR_ERASE);

            /* end flash access section: implementation depends on integrator */
            if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
            {
                /* Call Fls_FinishedFlashAccessNotif function if configured */
                Fls_pConfigPtr->finishedFlashAccessNotifPtr();
            }

            /* verify that program operation was successful */
            /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic */
#if (FLS_TIMEOUT_HANDLING == STD_ON)
            /*  PEG is valid only after DONE transition to 1 which might not be the case if the timeout event occured */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            if((0U != REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_PEG_U32)) && (0U != Fls_u32LLDTimeout_Counter) && (0U != u32Abort_Timeout_Counter))
#else
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            if(REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_PEG_U32))
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */
            {
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                if( FLASH_E_OK != Fls_Flash_VerifyMemoryArea
                                     (
                                        /* Compiler_Warning: see fls_c_REF_CW_01 */
                                        /*
                                        * @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic
                                        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                                        * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                                        */
                                       (uint32)(Fls_Flash_pTargetAddressPtr - (Fls_u32LLDNumberOfStepBack/4U)),
                                        /*
                                        * @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic
                                        * @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic
                                        */
                                        Fls_Flash_pSourceAddressPtr - (Fls_u32LLDNumberOfStepBack/4U),
                                        Fls_u32LLDNumberOfStepBack
                                     )
                  )
                {
                    /* terminate program operation */
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    */
                    REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);

                #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_WRITE_FAILED);
                #endif
                /* @violates @ref fls_flash_c_REF_5 Return statement before end of function. */
                    return FLASH_E_FAILED;
                }
#endif    /* FLS_WRITE_VERIFY_CHECK == STD_ON */

                /* program operation succeed */
                /* continue with next double word program operation */
            }
            else
            {
                #if (FLS_TIMEOUT_HANDLING == STD_ON)
                #if (FLS_RUNTIME_ERROR_DETECT == STD_ON)
                    /*
                    * @violates @ref fls_flash_c_REF_28 The value of an expression of integer type shall not be implicitly converted to a different underlying type.
                    */
                    if((0 == Fls_u32LLDTimeout_Counter)||(0 == u32Abort_Timeout_Counter))
                    {
                        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
                    }
                #endif
                #endif
                /* terminate program operation */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                */
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);

                /* program operation failed */
                /* @violates @ref fls_flash_c_REF_5 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
        }

        /* all double word program operations succeed */
        /* terminate program operation */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        */
        REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);

        /* program operation succeed */
        /* @violates @ref fls_flash_c_REF_6 Return statement before end of function. */
        return FLASH_E_OK;
    }
    else /* bAsynch == TRUE */
    {
        /* setup program operation */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        */
        REG_BIT_SET32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);

        /* first double word program operation */
        Fls_Flash_u32ProgramCycle=0U;
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
        Fls_u32LLDNumberOfStepBack = 0U;
#endif
        /* if not page aligned execute dw programming */
        /* Compiler_Warning: see fls_c_REF_CW_01 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        */
        if( (0U != ((uint32)Fls_Flash_pTargetAddressPtr % (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt] )) || \
        /*
        * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on undefned or unspecifed behaviour.
        * @violates @ref fls_c_REF_7 Booleans operands are not used for logical operators '&&', '||' and '!'
        */
                    (Fls_u32LLDRemainingDataToWrite < (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt] ) \
                    /* @violates @ref fls_c_REF_8 The right-hand operand of a logical && or || operator shall not contain side effects. */
          )
        {
#if( FLS_WRITE_BLANK_CHECK == STD_ON )
            /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic */
            if( FLASH_E_OK != Fls_Flash_VerifyMemoryArea \
                                /* Compiler_Warning: see fls_c_REF_CW_01 */
                                /*
                                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                                * @violates @ref fls_flash_c_REF_16 cast from pointer to unsigned long Due to casting between a pointer and unsigned long representing address
                                */
                               ( (uint32)Fls_Flash_pTargetAddressPtr, \
                                  NULL_PTR, \
                                 (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt] \
                               )
              )
            {
                /* terminate program operation */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                */
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);
                    #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_ERASE_FAILED);
                    #endif
                /* @violates @ref fls_c_REF_5 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */
            /*It is time to do word or double word programming */
            /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the */
            Fls_Flash_PageWrite((*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt]);
            Fls_Flash_u32ProgramCycle++;
            /*
            * @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic
            * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on undefned or unspecifed behaviour.
            * @violates @ref fls_c_REF_7 Booleans operands are not used for logical operators '&&', '||' and '!'
            */
            Fls_u32LLDRemainingDataToWrite -= (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt];
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
            /* target and source address has been incresed by Fls_Flash_PageWrite,
               so we need a number of step back for both pointer to perform a write
               verify check*/
            /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic */
            Fls_u32LLDNumberOfStepBack = (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt];
#endif
        }
        else
        {
#if( FLS_WRITE_BLANK_CHECK == STD_ON )
            if( FLASH_E_OK != Fls_Flash_VerifyMemoryArea \
                                /* Compiler_Warning: see fls_c_REF_CW_01 */
                                /*
                                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                                * @violates @ref fls_flash_c_REF_16 cast from pointer to unsigned long Due to casting between a pointer and unsigned long representing address
                                */
                                ( (uint32)Fls_Flash_pTargetAddressPtr, \
                                  NULL_PTR, \
                                  /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the */
                                  (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt] \
                                )
              )
            {
                /* terminate program operation */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                */
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_ERASE_FAILED);
                /* @violates @ref fls_c_REF_5 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */
            /* it is time to do page programming */
            /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the */
            Fls_Flash_PageWrite((*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt]);
            Fls_Flash_u32ProgramCycle+=Fls_Flash_u32DoubleWordCounter;
            /*
            * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on undefned or unspecifed behaviour.
            * @violates @ref fls_c_REF_7 Booleans operands are not used for logical operators '&&', '||' and '!'
            */
            Fls_u32LLDRemainingDataToWrite -= (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt];
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
            /* target and source address has been incresed by Fls_Flash_PageWrite,
               so we need a number of step back for both pointer to perform a write
               verify check*/
            Fls_u32LLDNumberOfStepBack = (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt];
#endif
        }
        /* start internal erase/program sequence */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */
        REG_BIT_SET32(FLASH_MCR_ADDR32, FLASH_MCR_EHV_U32);
        Fls_eLLDJob = FLASH_JOB_WRITE;
        Fls_eLLDJobResult = MEMIF_JOB_PENDING;

#if (FLS_TIMEOUT_HANDLING == STD_ON)
        /* Initialize timeout counter */
        Fls_u32LLDTimeout_Counter = FLS_ASYNC_WRITE_TIMEOUT_VALUE;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

        /* @violates @ref fls_flash_c_REF_6 Return statement before end of function. */
        return FLASH_E_PENDING;
    }
}

/**
* @brief          Execute an interlock write and next program.
*
* @param[in]      1           u32TotalBytes Total number of bytes to program
*
*/
static FUNC( void, FLS_CODE ) Fls_Flash_PageWrite
( CONST(uint32, AUTOMATIC) u32TotalBytes )
{
    uint32 u32Counter;

    for (u32Counter=0UL; u32Counter < (u32TotalBytes/4U); u32Counter++)
    {
        /* make a program data interlock write, first word data write */
        *Fls_Flash_pTargetAddressPtr = *Fls_Flash_pSourceAddressPtr;
        /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic */
        Fls_Flash_pTargetAddressPtr += 1;
        /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic */
        Fls_Flash_pSourceAddressPtr += 1;
    }

#ifdef CACHE_INVALIDATE_MACROS
#if (CACHE_INVALIDATE_MACROS == STD_ON)
    /* Flush written data from cache to flush, before starting the actual HV programming */
    Mcl_CacheFlushAll();
#endif /* CACHE_INVALIDATE_MACROS == STD_ON */
#endif /* ifdef CACHE_INVALIDATE_MACROS */
}

/**
* @brief          Read one or more bytes from given flash sector
*
* @param[in]      1           ePhySector Physical sector ID
* @param[in]      2           u32SectorOffset sector offset in bytes
* @param[in]      3           u32DataLength data length in bytes
* @param[out]     pDataPtr    where read data to be written
*
* @return Fls_LLDReturnType
* @retval FLASH_E_OK Operation succeeded
*
* @implements     Fls_Flash_SectorRead_Activity
*/
/*
* @violates @ref fls_flash_c_REF_25 All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
*/
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_SectorRead
(
    CONST( Fls_PhysicalSectorType, AUTOMATIC) ePhySector,
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    VAR(Fls_LengthType, AUTOMATIC) u32DataLength,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) pDataPtr
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(Fls_DataBytesType, AUTOMATIC) u8DataLength = FLS_SIZE_1BYTE;
#if( FLS_DSI_HANDLER_API == STD_ON )
    Fls_Flash_eReadStatus = FLASH_E_PENDING;
    Fls_Flash_eCompareStatus = FLASH_E_OK;
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */

    /* Physical flash address to read */
    /*
    * @violates @ref fls_flash_c_REF_2 A cast should not be performed between a pointer to object type and a different pointer to object type
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic
    */
    Fls_Flash_pReadAddressPtr = (volatile uint8 *)((*((*(Fls_pConfigPtr->pSectorList))[ePhySector])).pSectorStartAddressPtr) + \
                              u32SectorOffset;

    /* first invalidate the flash prefetch buffer by performing a bogus interlock write
       (avoid write if MCR[PGM|ERS] == 0)*/
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
    if(0UL == REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32 | FLASH_MCR_ERS_U32))
    {
       /*
        * @violates @ref fls_c_REF_30 Cast from pointer to pointer
        * @violates @ref fls_c_REF_31 A cast shall not be performed that removes any const and
        * volatile qualification from the type address by a pointer
        * @violates @ref fls_flash_c_REF_28 The value of an expression of integer type shall not be implicitly converted to a different underlying type
        */
        *Fls_Flash_pReadAddressPtr = 0x0UL;

#ifdef CACHE_INVALIDATE_MACROS
#if (CACHE_INVALIDATE_MACROS == STD_ON)
        /* Flush the interlock write from cache to flash */
        Mcl_CacheFlushAll();
        /* Invalidate the bogus interlock write from cache, before the flash read */
        Mcl_CacheInvalidateAll();
#endif /* CACHE_INVALIDATE_MACROS == STD_ON */
#endif /* ifdef CACHE_INVALIDATE_MACROS */
    }

#if(FLS_EXTENDED_READ_ERROR_CHECK == STD_ON)
    /* clear read monitoring error flags (w1c) */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
    */
    REG_BIT_SET32(FLASH_MCR_ADDR32, FLASH_MCR_RVE_W1C | FLASH_MCR_RRE_W1C | FLASH_MCR_RWE_W1C | FLASH_MCR_SBC_W1C);
#endif

    do
    {
        /* Read flash location */
        /* Verifying 4 byte if it is aligned */
        /* Compiler_Warning: see fls_c_REF_CW_01 */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.This violation is because of complex statement
        * @violates @ref fls_flash_c_REF_2 A conversion should not be performed between a pointer to object and an integer type
        */
        if((0U == ( (uint32)pDataPtr % 4U )) && (0U == ( (uint32)Fls_Flash_pReadAddressPtr % 4U )) && (4U <= u32DataLength))
        {
            u8DataLength = FLS_SIZE_4BYTE;
        }
        else /* At least one of the buffers is unaligned or there are less than 4 bytes left. */
        {
            u8DataLength = FLS_SIZE_1BYTE;
        }

        if(FLASH_E_FAILED == Fls_Flash_ReadBytes(u8DataLength))
        {
            /* Errors occurred when verify the memory flash*/
            /* @violates @ref fls_flash_c_REF_5 Return statement before end of function. */
            return FLASH_E_FAILED;
        }

        if(FLS_SIZE_4BYTE == u8DataLength)
        {
            /* @violates @ref fls_flash_c_REF_2 A conversion should not be performed between a pointer to object and an integer type */
            *( uint32*)(pDataPtr) = Fls_Flash_u32ReadAddress32;
        }
        else
        {
            *pDataPtr = Fls_Flash_u8ReadAddress8;
        }
        /* @violates @ref fls_flash_c_REF_15 Cast of complex expression changes signedness*/
        pDataPtr += (uint32)u8DataLength;
        /* @violates @ref fls_flash_c_REF_15 Cast of complex expression changes signedness*/
        Fls_Flash_pReadAddressPtr += (uint32)u8DataLength;
        u32DataLength -= (uint32)u8DataLength;
#if( FLS_DSI_HANDLER_API == STD_ON )
    /*
     * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.This violation is because of complex statement
     */
    }while((u32DataLength > 0U) && ( FLASH_E_PENDING == Fls_Flash_eReadStatus ));
#else   /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
    }while(u32DataLength > 0U);
#endif /* #if( FLS_DSI_HANDLER_API == STD_ON ) */

#if( FLS_DSI_HANDLER_API == STD_ON )
    if( FLASH_E_PENDING == Fls_Flash_eReadStatus )
    {
        Fls_Flash_eReadStatus = FLASH_E_OK;
    }

    eRetVal = Fls_Flash_eReadStatus;
#else
    eRetVal = FLASH_E_OK;
#endif

#if(FLS_EXTENDED_READ_ERROR_CHECK == STD_ON)
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.
    */
    if(0U != (REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_RVE_W1C | FLASH_MCR_RRE_W1C | FLASH_MCR_RWE_W1C | FLASH_MCR_SBC_W1C)))
    {
        eRetVal = FLASH_E_FAILED;
    }
#endif

    return eRetVal;
}
#if(( FLS_COMPARE_API == STD_ON ) || ( FLS_BLANK_CHECK_API == STD_ON ))
/**
* @brief          Compare data buffer with content of given flash sector.
*
* @param[in]      1           ePhySector Physical sector ID
* @param[in]      2           u32SectorOffset sector offset in bytes
* @param[in]      3           u32DataLength data length in bytes
* @param[in]      4           pDataPtr data to be compared
*
* @return         Fls_LLDReturnType
* @retval         FLASH_E_OK Operation succeeded
* @retval         FLASH_E_BLOCK_INCONSISTENT Data buffer doesn't match with content of flash sector
*
* @implements     Fls_Flash_SectorCompare_Activity
*/
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_SectorCompare
(
    CONST( Fls_PhysicalSectorType, AUTOMATIC) ePhySector,
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    VAR(Fls_LengthType, AUTOMATIC) u32DataLength,
    CONSTP2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) pDataPtr
)
{
    /* Physical flash address to read */
    /*
    * @violates @ref fls_flash_c_REF_2 A cast should not be performed between a pointer to object type and a different pointer to object type
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic
    */
    Fls_Flash_pReadAddressPtr = (volatile uint8 *)((*((*(Fls_pConfigPtr->pSectorList))[ePhySector])).pSectorStartAddressPtr) + \
                              u32SectorOffset;

    /* first invalidate the flash prefetch buffer by performing a bogus interlock write
       (avoid write if MCR[PGM|ERS] == 0)*/
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    * @violates @ref fls_flash_c_REF_28 The value of an expression of integer type shall not be implicitly converted to a different underlying type
    */
    if(0UL == REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32 | FLASH_MCR_ERS_U32))
    {
       /*
        * @violates @ref fls_c_REF_30 Cast from pointer to pointer
        * @violates @ref fls_c_REF_31 A cast shall not be performed that removes any const and
        * volatile qualification from the type address by a pointer
        * @violates @ref fls_flash_c_REF_28 The value of an expression of integer type shall not be implicitly converted to a different underlying type
        */
        *Fls_Flash_pReadAddressPtr = 0x0UL;

#ifdef CACHE_INVALIDATE_MACROS
#if (CACHE_INVALIDATE_MACROS == STD_ON)
        /* Flush the interlock write from cache to flash */
        Mcl_CacheFlushAll();
        /* Invalidate the bogus interlock write from cache, before the flash read */
        Mcl_CacheInvalidateAll();
#endif /* CACHE_INVALIDATE_MACROS == STD_ON */
#endif /* ifdef CACHE_INVALIDATE_MACROS */
    }
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    /* @violates @ref fls_flash_c_REF_16 cast from pointer to unsigned long Due to casting between a pointer and unsigned long representing address
     * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
     * @violates @ref fls_flash_c_REF_2 A conversion should not be performed between a pointer to object and an integer type
     */
    return Fls_Flash_VerifyMemoryArea((uint32)Fls_Flash_pReadAddressPtr,(const uint32*)pDataPtr, u32DataLength);
}
#endif /* ( FLS_COMPARE_API == STD_ON ) || (FLS_BLANK_CHECK_API == STD_ON) */


#if( FLS_DSI_HANDLER_API == STD_ON )
/**
* @brief          Low level data storage exception handler.
*
* @return         Exc_CompHandlerReturnType
* @retval         EXC_HANDLED_SKIP The data storage exception was
*                 caused by currently pending flash read or compare job
* @retval         EXC_UNHANDLED The data storage exception was
*                 NOT caused by currently pending flash read or compare job
*
*/
/*
* @violates @ref fls_flash_c_REF_11 All declarations and definitions of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Fls_CompHandlerReturnType, FLS_CODE ) Fls_DsiHandler
(
    P2CONST( Fls_ExceptionDetailsType, AUTOMATIC, FLS_APPL_CONST ) pExceptionDetailsPtr
)
{
    VAR( Fls_CompHandlerReturnType, AUTOMATIC ) u8RetVal = FLS_UNHANDLED;

    /* @errata ERR_IPV_FLASH_0005 */
    #ifdef ERR_IPV_FLASH_0005
      #if (ERR_IPV_FLASH_0005 == STD_ON)
        VAR(uint8, AUTOMATIC) u8DataPtr;

        u8DataPtr = *((volatile uint8 *)0x00C02000U);
     #endif
    #endif

    /*  Check whether there is
        [1] pending read, compare, erase or write job,
        [2] exception syndrome register indicates "DSI reason"(caused by driver load instruction) or
                "DSI cache reason"(caused by a cache fetch, triggered by the flash access), and
        [3] data_pt is in the same cache line as the address currently accessed by pending flash read or flash compare job*/
    if( (FLASH_E_PENDING == Fls_Flash_eReadStatus )
        &&
        ( ( FLASH_DSI_EXC_SYNDROME       == (pExceptionDetailsPtr->syndrome_u32 & FLASH_DSI_EXC_SYNDROME)     ) ||
          ( FLASH_DSI_EXC_SYNDROME_CACHE == (pExceptionDetailsPtr->syndrome_u32 & FLASH_DSI_EXC_SYNDROME_CACHE) )
        )
        &&
        /* The reported exception address is in the same 32 bytes cache line as the Fls_Flash_pReadAddressPtr */
        /* Compiler_Warning: see fls_c_REF_CW_01 */
        /*
        * @violates @ref fls_flash_c_REF_25 Cast from pointer to unsigned long
        * Due to casting between a pointer and unsigned long representing address.
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        */
        ( ((uint32)pExceptionDetailsPtr->data_pt >> 5) == ((uint32)Fls_Flash_pReadAddressPtr >> 5) )
        /*
        * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.
        * This violation is because of complex statement
        * @violates @ref fls_c_REF_8 The right-hand operand of a logical && or || operator shall not contain side effects.
        */
      )
    {
        Fls_Flash_eReadStatus = FLASH_E_FAILED;
        u8RetVal = FLS_HANDLED_SKIP;
    }
    else if( (FLASH_E_PENDING == Fls_Flash_eCompareStatus )
            &&
            ( ( FLASH_DSI_EXC_SYNDROME       == (pExceptionDetailsPtr->syndrome_u32 & FLASH_DSI_EXC_SYNDROME)     ) ||
              ( FLASH_DSI_EXC_SYNDROME_CACHE == (pExceptionDetailsPtr->syndrome_u32 & FLASH_DSI_EXC_SYNDROME_CACHE) )
            )
            &&
            /* The reported exception address is in the same 32 bytes cache line as the Fls_Flash_pReadAddressPtr */
            /* Compiler_Warning: see fls_c_REF_CW_01 */
            /*
            * @violates @ref fls_flash_c_REF_25 Cast from pointer to unsigned long
            * Due to casting between a pointer and unsigned long representing address.
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
             */
            ( ( ((uint32)pExceptionDetailsPtr->data_pt >> 5) == ((uint32)Fls_Flash_pReadAddressPtr >> 5) ) ||
            /* Compiler_Warning: see fls_c_REF_CW_01 */
            /*
            * @violates @ref fls_flash_c_REF_25 Cast from pointer to unsigned long
            * Due to casting between a pointer and unsigned long representing address.
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            */
            ( ((uint32)pExceptionDetailsPtr->data_pt >> 5) == ((uint32)Fls_Flash_pCompareAddressPtr >> 5) )
            /*
            * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.
            * This violation is because of complex statement
            * @violates @ref fls_c_REF_8 The right-hand operand of a logical && or || operator shall not contain side effects.
            */
            )
            /*
            * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.
            * This violation is because of complex statement
            * @violates @ref fls_c_REF_8 The right-hand operand of a logical && or || operator shall not contain side effects.
            */
           )
    {
        Fls_Flash_eCompareStatus = FLASH_E_FAILED;
        u8RetVal = FLS_HANDLED_SKIP;
    }
    else
    {
        /* FLS_UNHANDLED */
    }

    return u8RetVal;
}

static FUNC( boolean, FLS_CODE ) Fls_Flash_ECCTest( void )
{
    VAR(boolean, AUTOMATIC) bWasECC = (boolean)FALSE;
    VAR(uint32, AUTOMATIC) Fls_Flash_u32ReadECC = 0U;
    P2VAR(volatile uint32, AUTOMATIC, FLS_APPL_DATA) Fls_Flash_pECCAddressPtr;
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    /*
     * @violates @ref fls_flash_c_REF_16 cast from pointer to unsigned long Due to casting between a pointer and unsigned long representing address
     * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
     * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on undefned or unspecifed behaviour.
     * @violates @ref fls_c_REF_7 The value of an expression shall be the same under any order of evaluation that the standard permits
     * @violates @ref fls_flash_c_REF_15 Cast of complex expression changes signedness
     * @violates @ref fls_flash_c_REF_2 A conversion should not be performed between a pointer to object and an integer type
     */
    Fls_Flash_pECCAddressPtr = (volatile uint32 *)(Fls_Flash_pReadAddressPtr - ((uint32)Fls_Flash_pReadAddressPtr % 4U));

    Fls_Flash_u32ReadECC = *Fls_Flash_pECCAddressPtr;

    /* first invalidate the flash prefetch buffer by performing a bogus interlock write*/
    /*
    * @violates @ref fls_flash_c_REF_16 cast from pointer to unsigned long Due to casting between a pointer and unsigned long representing address
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
    if(0UL == REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32 | FLASH_MCR_ERS_U32))
    {
        *Fls_Flash_pECCAddressPtr = 0U;
    }
    /* clear ECC status (EER bit) (w1c) */
    /*
    * @violates @ref fls_flash_c_REF_16 cast from pointer to unsigned long Due to casting between a pointer and unsigned long representing address
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
    REG_BIT_SET32(FLASH_MCR_ADDR32,FLASH_MCR_EER_W1C );

    if(FLS_ECC_VALUE != Fls_Flash_u32ReadECC)
    {
        bWasECC = (boolean)FALSE;
    }
    else
    {
        Fls_Flash_u32ReadECC = *Fls_Flash_pECCAddressPtr;
        /*
         * @violates @ref fls_flash_c_REF_16 cast from pointer to unsigned long Due to casting between a pointer and unsigned long representing address
         * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
         */
        if((0U != REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_EER_W1C)) && (FLS_ECC_VALUE == Fls_Flash_u32ReadECC))
        {
            bWasECC = (boolean)TRUE;
        }
        else
        {
            bWasECC = (boolean)FALSE;
        }
    }

    return bWasECC;
}
#endif /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
#define FLS_STOP_SEC_CODE
/*
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice.
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements and comments before '#include'
*/
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif
