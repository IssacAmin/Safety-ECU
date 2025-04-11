/**
*   @file    Fls_IPW.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Fls IP wrapper related functions.
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
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section fls_ipw_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_ipw_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_ipw_c_REF_3
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* Return from function as soon as to finish
*
* @section fls_ipw_c_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
*
* @section fls_ipw_c_REF_5
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* This violation is not fixed since if hardware error is detected it should return from the function
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters.
* The used compilers use more than 31 chars for identifiers.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#include "Fls_IPW.h"
#if (STD_ON == FLS_INTERNAL_FLASH_AVAILABLE)
#include "Fls_Flash.h"
#endif
#if (STD_ON == FLS_QSPI_FLASH_AVAILABLE)
#include "Fls_Qspi.h"
#endif

#if (STD_ON == FLS_INTERNAL_FLASH_AVAILABLE)
#if (FLS_INTERNAL_SECTORS_CONFIGURED == STD_ON)
#if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif
#endif  /*#if (STD_ON == FLS_INTERNAL_FLASH_AVAILABLE)*/
#endif  /*#if (FLS_INTERNAL_SECTORS_CONFIGURED == STD_ON)*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_IPW_VENDOR_ID_C                           43
#define FLS_IPW_MODULE_ID_C                           92
/*
* @violates @ref fls_ipw_c_REF_4 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
#define FLS_IPW_AR_RELEASE_MAJOR_VERSION_C            4
/*
* @violates @ref fls_ipw_c_REF_4 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
#define FLS_IPW_AR_RELEASE_MINOR_VERSION_C            3
/*
* @violates @ref fls_ipw_c_REF_4 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
#define FLS_IPW_AR_RELEASE_REVISION_VERSION_C         1
#define FLS_IPW_SW_MAJOR_VERSION_C                    1
#define FLS_IPW_SW_MINOR_VERSION_C                    0
#define FLS_IPW_SW_PATCH_VERSION_C                    1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_IPW_VENDOR_ID_C != FLS_VENDOR_ID)
    #error "Fls_IPW.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls header file are of the same Autosar version */
#if ((FLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_IPW_AR_RELEASE_MINOR_VERSION_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_IPW_AR_RELEASE_REVISION_VERSION_C != FLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_IPW.c and Fls.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_IPW_SW_MAJOR_VERSION_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_IPW_SW_MINOR_VERSION_C != FLS_SW_MINOR_VERSION) || \
     (FLS_IPW_SW_PATCH_VERSION_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_IPW.c and Fls.h are different"
#endif


/* Check if current file and Fls_IPW.h header file have the same Vendor ID */
#if (FLS_IPW_VENDOR_ID_C != FLS_IPW_VENDOR_ID_H)
    #error "Fls_IPW.c and Fls_IPW.h have different vendor ids"
#endif
/* Check if current file and Fls_IPW.h header file are of the same Software version */
#if ((FLS_IPW_SW_MAJOR_VERSION_C != FLS_IPW_SW_MAJOR_VERSION_H) || \
     (FLS_IPW_SW_MINOR_VERSION_C != FLS_IPW_SW_MINOR_VERSION_H) || \
     (FLS_IPW_SW_PATCH_VERSION_C != FLS_IPW_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Fls_IPW.c and Fls_IPW.h are different"
#endif
/* Check if current file and Fls_IPW.h header file are of the same Autosar version */
#if ((FLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != FLS_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLS_IPW_AR_RELEASE_MINOR_VERSION_C    != FLS_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (FLS_IPW_AR_RELEASE_REVISION_VERSION_C != FLS_IPW_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Fls_IPW.c and Fls_IPW.h are different"
#endif

#if (STD_ON == FLS_INTERNAL_FLASH_AVAILABLE)
/* Check if current file and Fls_Flash header file are of the same vendor */
#if (FLS_IPW_VENDOR_ID_C != FLS_FLASH_VENDOR_ID)
    #error "Fls_IPW.c and Fls_Flash.h have different vendor ids"
#endif
/* Check if current file and Fls_Flash header file are of the same Autosar version */
#if ((FLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != FLS_FLASH_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_IPW_AR_RELEASE_MINOR_VERSION_C    != FLS_FLASH_AR_RELEASE_MINOR_VERSION) || \
     (FLS_IPW_AR_RELEASE_REVISION_VERSION_C != FLS_FLASH_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_IPW.c and Fls_Flash.h are different"
#endif
/* Check if current file and Fls_Flash header file are of the same Software version */
#if ((FLS_IPW_SW_MAJOR_VERSION_C != FLS_FLASH_SW_MAJOR_VERSION) || \
     (FLS_IPW_SW_MINOR_VERSION_C != FLS_FLASH_SW_MINOR_VERSION) || \
     (FLS_IPW_SW_PATCH_VERSION_C != FLS_FLASH_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_IPW.c and Fls_Flash.h are different"
#endif
#endif

#if (STD_ON == FLS_QSPI_FLASH_AVAILABLE)
/* Check if current file and Fls_Qspi header file are of the same vendor */
#if (FLS_IPW_VENDOR_ID_C != FLS_QSPI_VENDOR_ID_H)
    #error "Fls_IPW.c and Fls_Qspi.h have different vendor ids"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Fls_Qspi header file are of the same Autosar version */
    #if ((FLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != FLS_QSPI_AR_RELEASE_MAJOR_VERSION_H) || \
         (FLS_IPW_AR_RELEASE_MINOR_VERSION_C    != FLS_QSPI_AR_RELEASE_MINOR_VERSION_H) \
        )
        #error "AutoSar Version Numbers of Fls_IPW.c and Fls_Qspi.h are different"
    #endif
#endif
/* Check if current file and Fls_Qspi header file are of the same Software version */
#if ((FLS_IPW_SW_MAJOR_VERSION_C != FLS_QSPI_SW_MAJOR_VERSION_H) || \
     (FLS_IPW_SW_MINOR_VERSION_C != FLS_QSPI_SW_MINOR_VERSION_H) || \
     (FLS_IPW_SW_PATCH_VERSION_C != FLS_QSPI_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Fls_IPW.c and Fls_Qspi.h are different"
#endif
#endif


#if (STD_ON == FLS_INTERNAL_FLASH_AVAILABLE)
#if (FLS_INTERNAL_SECTORS_CONFIGURED == STD_ON)
#if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((FLS_IPW_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_IPW_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_IPW.c and Det.h are different"
    #endif
#endif
#endif
#endif  /*#if (STD_ON == FLS_INTERNAL_FLASH_AVAILABLE)*/
#endif  /*#if (FLS_INTERNAL_SECTORS_CONFIGURED == STD_ON)*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define FLS_START_SEC_CODE
/*
* @violates @ref fls_ipw_c_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice.
* @violates @ref fls_ipw_c_REF_2 Only preprocessor statements and comments before "#include"
*/
#include "Fls_MemMap.h"

/*

*/
FUNC(void, FLS_CODE) Fls_IPW_Init(void)
{
    /* Initialize flash hardware
       NOTE: The variable 'Fls_eLLDJobResult' will be updated in the below function*/
#if (FLS_INTERNAL_FLASH_AVAILABLE == STD_ON)
#if (FLS_INTERNAL_SECTORS_CONFIGURED == STD_ON)
    Fls_Flash_Init();
    if(MEMIF_JOB_FAILED == Fls_eLLDJobResult)
    {
        /* Error during Fls_Flash_Init, abort any subsequent IP initializations. */
        /* @violates @ref fls_ipw_c_REF_3 Return statement before end of function. */
        return;
    }
#endif
#endif
}

/*

*/
FUNC(void, FLS_CODE) Fls_IPW_AbortSuspended(void)
{
    if( FLASH_E_FAILED == Fls_Flash_AbortSuspended(FLS_MAINFUNCTION_ID))
    {
        Fls_eLLDJob = FLASH_JOB_NONE;
        Fls_eLLDJobResult = MEMIF_JOB_FAILED;
    }
    return;
}

#if (FLS_CANCEL_API == STD_ON )
/*

*/
FUNC(void, FLS_CODE) Fls_IPW_Cancel(void)
{
    if(MEMIF_JOB_PENDING == Fls_eLLDJobResult )
    {
        Fls_Flash_Cancel();
        if(MEMIF_JOB_PENDING == Fls_eLLDJobResult)
        {
            /* Error during Fls_Flash_Cancel, the job was not canceled. */
    /* @violates @ref fls_ipw_c_REF_3 Return statement before end of function. */
            return;
        }
    }
    else
    {
        /* no hardware job (asynchronous) is pending, do nothing */

        /* Mark the internal job as failed.*/
        Fls_eLLDJob = FLASH_JOB_NONE;
        Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
        Fls_eLLDJobResult = MEMIF_JOB_CANCELED;
    }

}
#endif


/**
* @brief          Process ongoing erase or write hardware job.
* @details        In case Async Operation is ongoing this function will complete the following job:
*                 - Erase
*                 - Erase on Interleaved sectors
*                 - Write
*                 - Erase blank Check
*                 .
*
* @implements     Fls_IPW_LLDMainFunction_Activity
*
* @note           Dem_ReportErrorStatus(Fls_pConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when erase operation failed due to hardware error.
*                 Dem_ReportErrorStatus(Fls_pConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when write operation failed due to hardware error
*/
FUNC( void, FLS_CODE ) Fls_IPW_LLDMainFunction( void )
{

    if(MEMIF_JOB_PENDING == Fls_eLLDJobResult)
    {
        /* some hardware job (asynchronous) is pending */
        if (FLASH_JOB_ERASE == Fls_eLLDJob )
        {
            Fls_Flash_MainFunctionErase();
        }
        /* Write hardware job (asynchronous) is pending */
        else if (FLASH_JOB_WRITE == Fls_eLLDJob )
        {
            Fls_Flash_MainFunctionWrite();
        }
    #if( FLS_ERASE_BLANK_CHECK == STD_ON )
        else if ( FLASH_JOB_ERASE_BLANK_CHECK == Fls_eLLDJob )
        {
            Fls_Flash_MainFunctionEraseBlankCheck();
        }
    #endif
        else
        {
            /* Do nothing - should not happen in Fully Trusted Environment;
               'else' clause added to fulfill MISRA Rule 14.10 */
        }
    }
    else
    {
        /* no hardware job (asynchronous) is pending, do nothing */
    }
}


/*

*/
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_IPW_SectorRead
(
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST(Fls_AddressType, AUTOMATIC) u32Length,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) pJobDataDestPtr
)
{
    VAR( Fls_LLDReturnType, AUTOMATIC ) eLldRetVal = FLASH_E_FAILED;

    eLldRetVal = Fls_Flash_SectorRead( Fls_u32JobSectorIt, u32SectorOffset, u32Length, pJobDataDestPtr );

    return eLldRetVal;
}

#if(( FLS_COMPARE_API == STD_ON ) || ( FLS_BLANK_CHECK_API == STD_ON ))
/**
* @brief          IP wrapper sector compare function.
* @details        Route the compare job to appropriate low level IP function.
*/
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_IPW_SectorCompare
(
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST(Fls_AddressType, AUTOMATIC) u32Length,
    P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) pJobDataSrcPtr
)
{
    VAR( Fls_LLDReturnType, AUTOMATIC ) eLldRetVal = FLASH_E_FAILED;

    eLldRetVal = Fls_Flash_SectorCompare( Fls_u32JobSectorIt, u32SectorOffset, u32Length, pJobDataSrcPtr );

    return eLldRetVal;
}
#endif /* ( FLS_COMPARE_API == STD_ON ) || (FLS_BLANK_CHECK_API == STD_ON) */

/**
* @brief          IP wrapper sector erase function.
* @details        Route the erase job to appropriate low level IP function.
*/
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_IPW_SectorErase
(
#if(FLS_ERASE_BLANK_CHECK == STD_ON)
    CONST( Fls_LengthType, AUTOMATIC ) u32PhysicalSectorSize,
#endif
    CONST( boolean, AUTOMATIC ) bAsynch
)
{
    VAR( Fls_LLDReturnType, AUTOMATIC ) eLldRetVal = FLASH_E_FAILED;
    /* Call Low-Level driver to erase one internal sector with
        the Fls_u32JobSectorIt sector index */
#if( (FLS_ERASE_BLANK_CHECK == STD_ON) ||  (STD_ON == FLS_SYNCRONIZE_CACHE) )
    eLldRetVal = Fls_Flash_SectorErase( Fls_u32JobSectorIt, u32PhysicalSectorSize, bAsynch );
#else
    eLldRetVal = Fls_Flash_SectorErase( Fls_u32JobSectorIt, bAsynch );
#endif
    return eLldRetVal;
}

/**
* @brief          IP wrapper sector write function.
* @details        Route the write job to appropriate low level IP function.
*/
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_IPW_SectorWrite
(
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST(Fls_AddressType, AUTOMATIC) u32Length,
    P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) pJobDataSrcPtr,
    CONST( boolean, AUTOMATIC ) bAsynch
)
{
    VAR( Fls_LLDReturnType, AUTOMATIC ) eLldRetVal = FLASH_E_FAILED;

    eLldRetVal = Fls_Flash_SectorWrite( Fls_u32JobSectorIt, u32SectorOffset, u32Length, pJobDataSrcPtr, bAsynch );

    return eLldRetVal;
}



#define FLS_STOP_SEC_CODE
/*
* @violates @ref fls_ipw_c_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice.
* @violates @ref fls_ipw_c_REF_2 Only preprocessor statements and comments before "#include"
*/
#include "Fls_MemMap.h"


#ifdef __cplusplus
}
#endif



