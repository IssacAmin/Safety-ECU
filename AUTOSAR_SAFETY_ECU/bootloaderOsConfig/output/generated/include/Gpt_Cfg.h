/**
*   @file    Gpt_Cfg.h
*   @implements    Gpt_Cfg.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt  - Gpt driver configuration header file.
*   @details GPT driver header file, containing C and XPath constructs for generating Gpt
*            configuration header file.
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : PA
*   Peripheral           : eMios_Stm_Pit
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

#ifndef GPT_CFG_H
#define GPT_CFG_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*     Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*     on the significance of more than 31 characters. The used compilers use more than 31 chars for
*     identifiers.
*
* @section GPT_CFG_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_CFG_H_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
* @section GPT_CFG_H_REF_3
* Violates MISRA 2004 Required Rule 19.4, Braces not used for some macros
* Braces are not used for macros which expand to multiple statements separated by ";" character.
*
* @section GPT_CFG_H_REF_4
* Violates MISRA 2004 Required Rule 8.7, Some global variables used by a single driver function shall be
* exported to user application.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/** @violates @ref GPT_CFG_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "Mcal.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/




#define GPT_VENDOR_ID_CFG                    43
/** @violates @ref GPT_CFG_H_REF_2 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_AR_RELEASE_MAJOR_VERSION_CFG     4
/** @violates @ref GPT_CFG_H_REF_2 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_AR_RELEASE_MINOR_VERSION_CFG     3
/** @violates @ref GPT_CFG_H_REF_2 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_AR_RELEASE_REVISION_VERSION_CFG  1
#define GPT_SW_MAJOR_VERSION_CFG             1
#define GPT_SW_MINOR_VERSION_CFG             0
#define GPT_SW_PATCH_VERSION_CFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if this header file and Mcal.h file are of the same Autosar version */
    #if ((GPT_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt_Cfg.h and Mcal.h are different"
    #endif
    
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief Gpt Dev error detect switch
*
*/
#define GPT_DEV_ERROR_DETECT (STD_ON)

/**
* @brief Report Wakeup Source switch
*/
#define GPT_REPORT_WAKEUP_SOURCE (STD_ON)

/**
* @brief GPT_VERSION_INFO_API switch
*
*/
#define GPT_VERSION_INFO_API (STD_ON)

/**
* @brief GPT_DEINIT_API switch
*
*/
#define GPT_DEINIT_API (STD_ON)

/**
* @brief GPT_TIME_ELAPSED_API switch
*
*/
#define GPT_TIME_ELAPSED_API (STD_ON)

/**
* @brief GPT_TIME_REMAINING_API switch
*
*/
#define GPT_TIME_REMAINING_API (STD_ON)

/**
* @brief GPT_ENABLE_DISABLE_NOTIFICATION_API switch
*
*/
#define GPT_ENABLE_DISABLE_NOTIFICATION_API (STD_ON)

/**
* @brief GPT_WAKEUP_FUNCTIONALITY_API switch
*
*/
#define GPT_WAKEUP_FUNCTIONALITY_API (STD_ON)

/**
* @brief GPT_PREDEFTIMER_FUNCTIONALITY_API switch
*
*/
#define GPT_PREDEFTIMER_FUNCTIONALITY_API (STD_ON)

/**
* @brief Enable/disable support for changing timeout value during timer running
*
*/
#define GPT_CHANGE_NEXT_TIMEOUT_VALUE (STD_OFF)

/**
* @brief Enable/disable API for Dual Mode support.
*/
#define GPT_SET_CLOCK_MODE           (STD_OFF)


/**
* @brief Enable/disable API for Chain Mode.
*/
#define GPT_CHAIN_MODE (STD_OFF)


/**
* @brief Support Clock Source Selection for STM Timers
*/
#define GPT_STM_ENABLECLOCKSWITCH   (STD_ON)

/**
*   @brief   Enables or disables the access to a hardware register from user mode
*            USER_MODE_SOFT_LOCKING:        All reads to hw registers will be done via REG_PROT, user mode access
*            SUPERVISOR_MODE_SOFT_LOCKING:  Locks the access to the registers only for supervisor mode
*
*
*/
#define GPT_USER_MODE_SOFT_LOCKING       (STD_OFF)

/**
* @brief Support for User mode.
*        If this parameter has been configured to 'TRUE' the GPT driver code can be executed from both supervisor and user mode.
*
*/

#define GPT_ENABLE_USER_MODE_SUPPORT    (STD_OFF)

 

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef GPT_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == GPT_ENABLE_USER_MODE_SUPPORT)
   #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Gpt in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == GPT_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifdef GPT_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */


/**
* @brief Support for GPT RTC Standby wakeup.
*        If this parameter has been configured to 'TRUE' the GPT driver code will NOT CLEAR the interrupt flag if on init time *(Gpt_Rtc_Init()) the flag is already set.
*
*/

#define GPT_RTC_STANDBY_WAKEUP_SUPPORT    (STD_OFF)


/* Gpt Pre Compile Switch */

#define GPT_PRECOMPILE_SUPPORT (STD_ON)








/**
* @brief These defines indicate that at least one chennel from each module is used in all configurations.
*
*/
#define GPT_STM_USED (STD_OFF)
#define GPT_EMIOS_USED (STD_OFF)
#define GPT_PIT_USED (STD_ON)
#define GPT_RTC_USED (STD_OFF)
#define GPT_PIT_RTI_USED (STD_OFF)

/**
* @{
* @brief eMios channel resource defines
*/


/**
* @{
* @brief Symbolic names of channels
*/

            /** @violates @ref GPT_CFG_H_REF_2 Identifier clash */
        #define GptConf_GptChannelConfiguration_GptChannelConfiguration_0  (0U)
            

/*@}*/

/**
* @brief This define is a reserved logical channel name representing a not existing/configured
*        hardware channel.
*
*/
#define GPT_CHN_NOT_USED    (255U)

/**
* @brief The maxiumum number of HW channels. This is used to allocate memory space for channel runtime info.
*/
#define GPT_HW_CHANNEL_NUM   (1U)

#define GPT_PIT_MODULE_SINGLE_INTERRUPT (STD_OFF)
#define GPT_STM_MODULE_SINGLE_INTERRUPT (STD_OFF)

/**
* @{
* @brief IRQ Defines for each channel used
*/

/**
* @{
* @brief Defines for HW IPs will be used by GPT driver
*/







#define GPT_EMIOS_0_NUM_CHANNEL_U8 (32U)
#define GPT_EMIOS_1_NUM_CHANNEL_U8 (32U)
#define GPT_EMIOS_2_NUM_CHANNEL_U8 (32U)
/**
* @brief The maximum number of channels per module for EMIOS
*/
#define GPT_EMIOS_CHANNELS_PER_MODULE_U8 (32U)
/* Number of EMIOS modules available on platform */
#define GPT_EMIOS_MODULES_NUM_U8  (3U)


#define GPT_PIT_0_NUM_CHANNEL_U8 (17U)
/**
* @brief The maximum number of channels per module for PIT
*/
#define GPT_PIT_CHANNELS_PER_MODULE_U8 (17U)
/* Number of PIT modules available on platform */
#define GPT_PIT_MODULES_NUM_U8  (1U)


#define GPT_STM_0_NUM_CHANNEL_U8 (4U)
#define GPT_STM_1_NUM_CHANNEL_U8 (4U)
#define GPT_STM_2_NUM_CHANNEL_U8 (4U)
/**
* @brief The maximum number of channels per module for STM
*/
#define GPT_STM_CHANNELS_PER_MODULE_U8 (4U)
/* Number of STM modules available on platform */
#define GPT_STM_MODULES_NUM_U8  (3U)


#define GPT_RTC_0_NUM_CHANNEL_U8 (1U)
/**
* @brief The maximum number of channels per module for RTC
*/
#define GPT_RTC_CHANNELS_PER_MODULE_U8 (1U)
/* Number of RTC modules available on platform */
#define GPT_RTC_MODULES_NUM_U8  (1U)

/**
* @brief The total number of indexes used by the hardware to logic channel map
*/
#define GPT_CHANNEL_IDX_NUM    ((GPT_EMIOS_CHANNELS_PER_MODULE_U8 * GPT_EMIOS_MODULES_NUM_U8) + (GPT_PIT_CHANNELS_PER_MODULE_U8 * GPT_PIT_MODULES_NUM_U8) + (GPT_STM_CHANNELS_PER_MODULE_U8 * GPT_STM_MODULES_NUM_U8) + (GPT_RTC_CHANNELS_PER_MODULE_U8 * GPT_RTC_MODULES_NUM_U8))

/**
@{
@brief ID for peripheral. This ID need to match the order in the hardware to logic channels mapping table
*      because it is used as a base index.
*/
/** @brief index where the STM channels start */
#define GPT_STM_MODULE       (0U)                                                     
/** @brief index where the PIT channels start */
#define GPT_PIT_MODULE       (GPT_STM_CHANNELS_PER_MODULE_U8 * GPT_STM_MODULES_NUM_U8)
/** @brief index where the EMIOS channels start */
#define GPT_EMIOS_MODULE     (GPT_PIT_MODULE + (GPT_PIT_CHANNELS_PER_MODULE_U8 * GPT_PIT_MODULES_NUM_U8))
/** @brief index where the Rtc channels start*/
#define GPT_RTC_MODULE       (GPT_EMIOS_MODULE + (GPT_EMIOS_CHANNELS_PER_MODULE_U8 * GPT_EMIOS_MODULES_NUM_U8))
/** @} */

/** 
* @brief  Switch to enable/disable the production error reporting.
*/
#define GPT_DISABLE_DEM_REPORT_ERROR_STATUS           (STD_ON)

/** 
* @brief  This is a timeout value which is used to wait till PIT_RTI_LDVAL is synchronized into the RTI clock domain
*/
#define GPT_TIMEOUT_COUNTER  (65535UL)


#define GPT_HW_PREDEFTIMER_NUM                              (4U) /** @brief number for channels predef timer supported by the platform */


/**
*   @brief export configuration Gpt driver
*/





/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
* @brief Predef Timer type. Indicates the type of predef timer.
* @implements   Gpt_PredefTimerType_enumeration
*/
typedef enum
{
    GPT_PREDEF_TIMER_1US_16BIT = 0x0U,
    GPT_PREDEF_TIMER_1US_24BIT,
    GPT_PREDEF_TIMER_1US_32BIT,
    GPT_PREDEF_TIMER_100US_32BIT
}Gpt_PredefTimerType;
#endif
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* GPT_CFG_H */

/** @} */
