/**
*   @file    Fls_PBcfg.c
*   @implements Fls_PBcfg.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Definitions of all post-build configuration structures.
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
* @section fls_pbcfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before 
* '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping.
* 
* @section fls_pbcfg_c_REF_2
* Violates MISRA 2004 Required Rule 11.1, Conversions involing function pointers must be to/from integral types.
* This violation is due to FLS213.
* 
* @section fls_pbcfg_c_REF_3
* Violates MISRA 2004 Advisory Rule 11.4, A cast should not be performed between a pointer to object type
* and a different pointer to object type.
* This violation is due to FLS213.
* 
* @section fls_pbcfg_c_REF_4
* Violates MISRA 2004 Required Rule 8.8, Object/function previously declared.
* The rule 8.8 requires that 'An external object or function shall be declared in one and only one file'.
* This requirement is fulfilled since the function is declared as external in and only in one configuration 
* C file (Fls_Cfg.c or Fls_PBcfg.c). There is no need to put the declaration into Fls_Cfg.h and made it 
* accessible for all modules which includes Fls.h/Fls_Cfg.h.
* 
* @section fls_pbcfg_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, Could be made static.  
* Making FlsConfigSet_0 static would make it unaccessible to the application.
*
* @section fls_pbcfg_c_REF_6
* Violates MISRA 2004 Required Rule 20.2, Re-use of C90 identifier pattern.
* This is just a matter of a symbol specified in the configuration.
* 
* @section fls_pbcfg_c_REF_7
* Violates MISRA 2004 Required Rule 8.8,
* An external object or function shall be declared in one and only one file.
* Possible MISRA error if the same callback function or variable name is used in multiple configuration variants. 
* Callback function/variable name is set by the driver user so this cannot be fixed by updating the driver code.
*
* @section fls_pbcfg_c_REF_8
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* This violation is due to FLS213.
* 
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
*
* @section [global]
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*  
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#include "Reg_eSys_FLASHC.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_CFG_C                      43
#define FLS_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define FLS_AR_RELEASE_MINOR_VERSION_CFG_C       3
#define FLS_AR_RELEASE_REVISION_VERSION_CFG_C    1
#define FLS_SW_MAJOR_VERSION_CFG_C               1
#define FLS_SW_MINOR_VERSION_CFG_C               0
#define FLS_SW_PATCH_VERSION_CFG_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != FLS_VENDOR_ID)
    #error "Fls_PBcfg.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != FLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_PBcfg.c and Fls.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_CFG_C != FLS_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_CFG_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_PBcfg.c and Fls.h are different"
#endif


/* Check if current file and Reg_eSys_FLASHC header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != ESYS_FLASHC_VENDOR_ID)
    #error "Fls_PBcfg.c and Reg_eSys_FLASHC.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_FLASHC header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != ESYS_FLASHC_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != ESYS_FLASHC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_PBcfg.c and Reg_eSys_FLASHC.h are different"
#endif
/* Check if current file and Reg_eSys_FLASHC header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != ESYS_FLASHC_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_CFG_C != ESYS_FLASHC_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_CFG_C != ESYS_FLASHC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_PBcfg.c and Reg_eSys_FLASHC.h are different"
#endif


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define FLS_START_SEC_CODE_AC
/* 
* @violates @ref fls_pbcfg_c_REF_1 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#ifdef _LINARO_C_MPC574XG_ 
#if (FLS_HW_OPERATION_ABORT_SUPPORTED == STD_ON)
#if (FLS_TIMEOUT_HANDLING == STD_ON)
/* @violates @ref fls_pbcfg_c_REF_4 Object/function previously declared */
extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC, P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAbort ) __attribute__ ((section (".acfls_code_rom")));
#else
/* @violates @ref fls_pbcfg_c_REF_4 Object/function previously declared */
extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) ) __attribute__ ((section (".acfls_code_rom")));
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */
#else   /* FLS_HW_OPERATION_ABORT_SUPPORTED == STD_OFF */
#if (FLS_TIMEOUT_HANDLING == STD_ON)
/* @violates @ref fls_pbcfg_c_REF_4 Object/function previously declared */
extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC ) __attribute__ ((section (".acfls_code_rom")));
#else
/* @violates @ref fls_pbcfg_c_REF_4 Object/function previously declared */
extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) ) __attribute__ ((section (".acfls_code_rom")));
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */
#endif  /* FLS_HW_OPERATION_ABORT_SUPPORTED == STD_ON */
#else
#if (FLS_HW_OPERATION_ABORT_SUPPORTED == STD_ON)
#if (FLS_TIMEOUT_HANDLING == STD_ON)
/* @violates @ref fls_pbcfg_c_REF_4 Object/function previously declared */
extern void Fls_Flash_AccessCode(CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC, P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAbort );
#else
/* @violates @ref fls_pbcfg_c_REF_4 Object/function previously declared */
extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) );
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */
#else   /* FLS_HW_OPERATION_ABORT_SUPPORTED == STD_OFF */
#if (FLS_TIMEOUT_HANDLING == STD_ON)
/* @violates @ref fls_pbcfg_c_REF_4 Object/function previously declared */
extern void Fls_Flash_AccessCode(CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC );
#else
/* @violates @ref fls_pbcfg_c_REF_4 Object/function previously declared */
extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) );
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */
#endif  /* FLS_HW_OPERATION_ABORT_SUPPORTED == STD_ON */
#endif /* #ifdef _LINARO_C_MPC574XG_ */

#define FLS_STOP_SEC_CODE_AC
/* 
* @violates @ref fls_pbcfg_c_REF_1 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


                                                                                                                                                                                
            
        



#define FLS_START_SEC_CONFIG_DATA_8
/* 
* @violates @ref fls_pbcfg_c_REF_1 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
/* aFlsSectorFlags[] (FlsConfigSet) */
static CONST(uint8, FLS_CONST) FlsConfigSet_aFlsSectorFlags[17] =
{
    0U, /* (Fls_Flags_Sector) */
    0U, /* (Fls_Flashbank_A_0) */
    0U, /* (Fls_Flashbank_A_1) */
    0U, /* (Fls_Flashbank_A_2) */
    0U, /* (Fls_Flashbank_A_3) */
    0U, /* (Fls_Flashbank_A_4) */
    0U, /* (Fls_Flashbank_A_5) */
    0U, /* (Fls_Flashbank_A_6) */
    0U, /* (Fls_Flashbank_A_7) */
    0U, /* (Fls_Flashbank_B_0) */
    0U, /* (Fls_Flashbank_B_1) */
    0U, /* (Fls_Flashbank_B_2) */
    0U, /* (Fls_Flashbank_B_3) */
    0U, /* (Fls_Flashbank_B_4) */
    0U, /* (Fls_Flashbank_B_5) */
    0U, /* (Fls_Flashbank_B_6) */
    0U /* (Fls_Flashbank_B_7) */
};
/* aFlsSectorUnlock[] (FlsConfigSet) */
static CONST(uint8, FLS_CONST) FlsConfigSet_aFlsSectorUnlock[17] =
{
    1U, /* (Fls_Flags_Sector) */
    1U, /* (Fls_Flashbank_A_0) */
    1U, /* (Fls_Flashbank_A_1) */
    1U, /* (Fls_Flashbank_A_2) */
    1U, /* (Fls_Flashbank_A_3) */
    1U, /* (Fls_Flashbank_A_4) */
    1U, /* (Fls_Flashbank_A_5) */
    1U, /* (Fls_Flashbank_A_6) */
    1U, /* (Fls_Flashbank_A_7) */
    1U, /* (Fls_Flashbank_B_0) */
    1U, /* (Fls_Flashbank_B_1) */
    1U, /* (Fls_Flashbank_B_2) */
    1U, /* (Fls_Flashbank_B_3) */
    1U, /* (Fls_Flashbank_B_4) */
    1U, /* (Fls_Flashbank_B_5) */
    1U, /* (Fls_Flashbank_B_6) */
    1U /* (Fls_Flashbank_B_7) */
};
#define FLS_STOP_SEC_CONFIG_DATA_8
/* 
* @violates @ref fls_pbcfg_c_REF_1 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
/* 
* @violates @ref fls_pbcfg_c_REF_1 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
/* aFlsSectorEndAddr[] (FlsConfigSet) */
static CONST(Fls_AddressType, FLS_CONST) FlsConfigSet_aFlsSectorEndAddr[17] =
{
    (Fls_AddressType)16383U, /* FlsSectorEndAddr (Fls_Flags_Sector)*/
    (Fls_AddressType)278527U, /* FlsSectorEndAddr (Fls_Flashbank_A_0)*/
    (Fls_AddressType)540671U, /* FlsSectorEndAddr (Fls_Flashbank_A_1)*/
    (Fls_AddressType)802815U, /* FlsSectorEndAddr (Fls_Flashbank_A_2)*/
    (Fls_AddressType)1064959U, /* FlsSectorEndAddr (Fls_Flashbank_A_3)*/
    (Fls_AddressType)1327103U, /* FlsSectorEndAddr (Fls_Flashbank_A_4)*/
    (Fls_AddressType)1589247U, /* FlsSectorEndAddr (Fls_Flashbank_A_5)*/
    (Fls_AddressType)1851391U, /* FlsSectorEndAddr (Fls_Flashbank_A_6)*/
    (Fls_AddressType)2113535U, /* FlsSectorEndAddr (Fls_Flashbank_A_7)*/
    (Fls_AddressType)2375679U, /* FlsSectorEndAddr (Fls_Flashbank_B_0)*/
    (Fls_AddressType)2637823U, /* FlsSectorEndAddr (Fls_Flashbank_B_1)*/
    (Fls_AddressType)2899967U, /* FlsSectorEndAddr (Fls_Flashbank_B_2)*/
    (Fls_AddressType)3162111U, /* FlsSectorEndAddr (Fls_Flashbank_B_3)*/
    (Fls_AddressType)3424255U, /* FlsSectorEndAddr (Fls_Flashbank_B_4)*/
    (Fls_AddressType)3686399U, /* FlsSectorEndAddr (Fls_Flashbank_B_5)*/
    (Fls_AddressType)3948543U, /* FlsSectorEndAddr (Fls_Flashbank_B_6)*/
    (Fls_AddressType)4210687U /* FlsSectorEndAddr (Fls_Flashbank_B_7)*/
};

/* paSectorProgSize[] (FlsConfigSet) */
static CONST(Fls_LengthType, FLS_CONST) FlsConfigSet_aFlsProgSize[17] =
{
    (Fls_LengthType)FLS_WRITE_QUAD_PAGE, /* FlsProgrammingSize (Fls_Flags_Sector) */
    (Fls_LengthType)FLS_WRITE_QUAD_PAGE, /* FlsProgrammingSize (Fls_Flashbank_A_0) */
    (Fls_LengthType)FLS_WRITE_QUAD_PAGE, /* FlsProgrammingSize (Fls_Flashbank_A_1) */
    (Fls_LengthType)FLS_WRITE_QUAD_PAGE, /* FlsProgrammingSize (Fls_Flashbank_A_2) */
    (Fls_LengthType)FLS_WRITE_QUAD_PAGE, /* FlsProgrammingSize (Fls_Flashbank_A_3) */
    (Fls_LengthType)FLS_WRITE_QUAD_PAGE, /* FlsProgrammingSize (Fls_Flashbank_A_4) */
    (Fls_LengthType)FLS_WRITE_QUAD_PAGE, /* FlsProgrammingSize (Fls_Flashbank_A_5) */
    (Fls_LengthType)FLS_WRITE_QUAD_PAGE, /* FlsProgrammingSize (Fls_Flashbank_A_6) */
    (Fls_LengthType)FLS_WRITE_QUAD_PAGE, /* FlsProgrammingSize (Fls_Flashbank_A_7) */
    (Fls_LengthType)FLS_WRITE_QUAD_PAGE, /* FlsProgrammingSize (Fls_Flashbank_B_0) */
    (Fls_LengthType)FLS_WRITE_QUAD_PAGE, /* FlsProgrammingSize (Fls_Flashbank_B_1) */
    (Fls_LengthType)FLS_WRITE_QUAD_PAGE, /* FlsProgrammingSize (Fls_Flashbank_B_2) */
    (Fls_LengthType)FLS_WRITE_QUAD_PAGE, /* FlsProgrammingSize (Fls_Flashbank_B_3) */
    (Fls_LengthType)FLS_WRITE_QUAD_PAGE, /* FlsProgrammingSize (Fls_Flashbank_B_4) */
    (Fls_LengthType)FLS_WRITE_QUAD_PAGE, /* FlsProgrammingSize (Fls_Flashbank_B_5) */
    (Fls_LengthType)FLS_WRITE_QUAD_PAGE, /* FlsProgrammingSize (Fls_Flashbank_B_6) */
    (Fls_LengthType)FLS_WRITE_QUAD_PAGE /* FlsProgrammingSize (Fls_Flashbank_B_7) */
};


/* paSectorPageSize[] (FlsConfigSet) */
static CONST(Fls_LengthType, FLS_CONST) FlsConfigSet_aFlsSectorPageSize[17] =
{
    (Fls_LengthType)8U, /* FlsPageSize (Fls_Flags_Sector) */
    (Fls_LengthType)8U, /* FlsPageSize (Fls_Flashbank_A_0) */
    (Fls_LengthType)8U, /* FlsPageSize (Fls_Flashbank_A_1) */
    (Fls_LengthType)8U, /* FlsPageSize (Fls_Flashbank_A_2) */
    (Fls_LengthType)8U, /* FlsPageSize (Fls_Flashbank_A_3) */
    (Fls_LengthType)8U, /* FlsPageSize (Fls_Flashbank_A_4) */
    (Fls_LengthType)8U, /* FlsPageSize (Fls_Flashbank_A_5) */
    (Fls_LengthType)8U, /* FlsPageSize (Fls_Flashbank_A_6) */
    (Fls_LengthType)8U, /* FlsPageSize (Fls_Flashbank_A_7) */
    (Fls_LengthType)8U, /* FlsPageSize (Fls_Flashbank_B_0) */
    (Fls_LengthType)8U, /* FlsPageSize (Fls_Flashbank_B_1) */
    (Fls_LengthType)8U, /* FlsPageSize (Fls_Flashbank_B_2) */
    (Fls_LengthType)8U, /* FlsPageSize (Fls_Flashbank_B_3) */
    (Fls_LengthType)8U, /* FlsPageSize (Fls_Flashbank_B_4) */
    (Fls_LengthType)8U, /* FlsPageSize (Fls_Flashbank_B_5) */
    (Fls_LengthType)8U, /* FlsPageSize (Fls_Flashbank_B_6) */
    (Fls_LengthType)8U /* FlsPageSize (Fls_Flashbank_B_7) */
};



static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) Fls_Flags_Sector_FlsConfigSet_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)0x00FA0000,         /* pSectorStartAddressPtr */
    FLASH_LMS_MSL4_U32,                   /* u32AddrSpaceBloSelValue */
    FLASH_LML_MLK4_U32,                   /* u32AddrSpaceBloLockValue */
    FLASH_SEL0_ADDR32,                    /* u32SectorBloSelRegAddr */
    FLASH_LOCK0_ADDR32,                   /* u32AddrSpaceBloLockRegAddr */
    (boolean)TRUE,                        /* bEccTriggersExc */
    10U         /* u32SectorId (Sector location to calculate cfgCRC) */
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) Fls_Flashbank_A_0_FlsConfigSet_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)0x01000000,         /* pSectorStartAddressPtr */
    FLASH_LGBS_LGSL0_U32,                 /* u32AddrSpaceBloSelValue */
    FLASH_LGBL_LGLK0_U32,                 /* u32AddrSpaceBloLockValue */
    FLASH_SEL2_ADDR32,                    /* u32SectorBloSelRegAddr */
    FLASH_LOCK2_ADDR32,                   /* u32AddrSpaceBloLockRegAddr */
    (boolean)TRUE,                        /* bEccTriggersExc */
    16U         /* u32SectorId (Sector location to calculate cfgCRC) */
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) Fls_Flashbank_A_1_FlsConfigSet_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)0x01040000,         /* pSectorStartAddressPtr */
    FLASH_LGBS_LGSL1_U32,                 /* u32AddrSpaceBloSelValue */
    FLASH_LGBL_LGLK1_U32,                 /* u32AddrSpaceBloLockValue */
    FLASH_SEL2_ADDR32,                    /* u32SectorBloSelRegAddr */
    FLASH_LOCK2_ADDR32,                   /* u32AddrSpaceBloLockRegAddr */
    (boolean)TRUE,                        /* bEccTriggersExc */
    17U         /* u32SectorId (Sector location to calculate cfgCRC) */
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) Fls_Flashbank_A_2_FlsConfigSet_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)0x01080000,         /* pSectorStartAddressPtr */
    FLASH_LGBS_LGSL2_U32,                 /* u32AddrSpaceBloSelValue */
    FLASH_LGBL_LGLK2_U32,                 /* u32AddrSpaceBloLockValue */
    FLASH_SEL2_ADDR32,                    /* u32SectorBloSelRegAddr */
    FLASH_LOCK2_ADDR32,                   /* u32AddrSpaceBloLockRegAddr */
    (boolean)TRUE,                        /* bEccTriggersExc */
    18U         /* u32SectorId (Sector location to calculate cfgCRC) */
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) Fls_Flashbank_A_3_FlsConfigSet_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)0x010C0000,         /* pSectorStartAddressPtr */
    FLASH_LGBS_LGSL3_U32,                 /* u32AddrSpaceBloSelValue */
    FLASH_LGBL_LGLK3_U32,                 /* u32AddrSpaceBloLockValue */
    FLASH_SEL2_ADDR32,                    /* u32SectorBloSelRegAddr */
    FLASH_LOCK2_ADDR32,                   /* u32AddrSpaceBloLockRegAddr */
    (boolean)TRUE,                        /* bEccTriggersExc */
    19U         /* u32SectorId (Sector location to calculate cfgCRC) */
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) Fls_Flashbank_A_4_FlsConfigSet_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)0x01100000,         /* pSectorStartAddressPtr */
    FLASH_LGBS_LGSL4_U32,                 /* u32AddrSpaceBloSelValue */
    FLASH_LGBL_LGLK4_U32,                 /* u32AddrSpaceBloLockValue */
    FLASH_SEL2_ADDR32,                    /* u32SectorBloSelRegAddr */
    FLASH_LOCK2_ADDR32,                   /* u32AddrSpaceBloLockRegAddr */
    (boolean)TRUE,                        /* bEccTriggersExc */
    20U         /* u32SectorId (Sector location to calculate cfgCRC) */
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) Fls_Flashbank_A_5_FlsConfigSet_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)0x01140000,         /* pSectorStartAddressPtr */
    FLASH_LGBS_LGSL5_U32,                 /* u32AddrSpaceBloSelValue */
    FLASH_LGBL_LGLK5_U32,                 /* u32AddrSpaceBloLockValue */
    FLASH_SEL2_ADDR32,                    /* u32SectorBloSelRegAddr */
    FLASH_LOCK2_ADDR32,                   /* u32AddrSpaceBloLockRegAddr */
    (boolean)TRUE,                        /* bEccTriggersExc */
    21U         /* u32SectorId (Sector location to calculate cfgCRC) */
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) Fls_Flashbank_A_6_FlsConfigSet_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)0x01180000,         /* pSectorStartAddressPtr */
    FLASH_LGBS_LGSL6_U32,                 /* u32AddrSpaceBloSelValue */
    FLASH_LGBL_LGLK6_U32,                 /* u32AddrSpaceBloLockValue */
    FLASH_SEL2_ADDR32,                    /* u32SectorBloSelRegAddr */
    FLASH_LOCK2_ADDR32,                   /* u32AddrSpaceBloLockRegAddr */
    (boolean)TRUE,                        /* bEccTriggersExc */
    22U         /* u32SectorId (Sector location to calculate cfgCRC) */
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) Fls_Flashbank_A_7_FlsConfigSet_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)0x011C0000,         /* pSectorStartAddressPtr */
    FLASH_LGBS_LGSL7_U32,                 /* u32AddrSpaceBloSelValue */
    FLASH_LGBL_LGLK7_U32,                 /* u32AddrSpaceBloLockValue */
    FLASH_SEL2_ADDR32,                    /* u32SectorBloSelRegAddr */
    FLASH_LOCK2_ADDR32,                   /* u32AddrSpaceBloLockRegAddr */
    (boolean)TRUE,                        /* bEccTriggersExc */
    23U         /* u32SectorId (Sector location to calculate cfgCRC) */
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) Fls_Flashbank_B_0_FlsConfigSet_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)0x01200000,         /* pSectorStartAddressPtr */
    FLASH_LGBS_LGSL8_U32,                 /* u32AddrSpaceBloSelValue */
    FLASH_LGBL_LGLK8_U32,                 /* u32AddrSpaceBloLockValue */
    FLASH_SEL2_ADDR32,                    /* u32SectorBloSelRegAddr */
    FLASH_LOCK2_ADDR32,                   /* u32AddrSpaceBloLockRegAddr */
    (boolean)TRUE,                        /* bEccTriggersExc */
    24U         /* u32SectorId (Sector location to calculate cfgCRC) */
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) Fls_Flashbank_B_1_FlsConfigSet_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)0x01240000,         /* pSectorStartAddressPtr */
    FLASH_LGBS_LGSL9_U32,                 /* u32AddrSpaceBloSelValue */
    FLASH_LGBL_LGLK9_U32,                 /* u32AddrSpaceBloLockValue */
    FLASH_SEL2_ADDR32,                    /* u32SectorBloSelRegAddr */
    FLASH_LOCK2_ADDR32,                   /* u32AddrSpaceBloLockRegAddr */
    (boolean)TRUE,                        /* bEccTriggersExc */
    25U         /* u32SectorId (Sector location to calculate cfgCRC) */
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) Fls_Flashbank_B_2_FlsConfigSet_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)0x01280000,         /* pSectorStartAddressPtr */
    FLASH_LGBS_LGSL10_U32,                /* u32AddrSpaceBloSelValue */
    FLASH_LGBL_LGLK10_U32,                /* u32AddrSpaceBloLockValue */
    FLASH_SEL2_ADDR32,                    /* u32SectorBloSelRegAddr */
    FLASH_LOCK2_ADDR32,                   /* u32AddrSpaceBloLockRegAddr */
    (boolean)TRUE,                        /* bEccTriggersExc */
    26U         /* u32SectorId (Sector location to calculate cfgCRC) */
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) Fls_Flashbank_B_3_FlsConfigSet_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)0x012C0000,         /* pSectorStartAddressPtr */
    FLASH_LGBS_LGSL11_U32,                /* u32AddrSpaceBloSelValue */
    FLASH_LGBL_LGLK11_U32,                /* u32AddrSpaceBloLockValue */
    FLASH_SEL2_ADDR32,                    /* u32SectorBloSelRegAddr */
    FLASH_LOCK2_ADDR32,                   /* u32AddrSpaceBloLockRegAddr */
    (boolean)TRUE,                        /* bEccTriggersExc */
    27U         /* u32SectorId (Sector location to calculate cfgCRC) */
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) Fls_Flashbank_B_4_FlsConfigSet_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)0x01300000,         /* pSectorStartAddressPtr */
    FLASH_LGBS_LGSL12_U32,                /* u32AddrSpaceBloSelValue */
    FLASH_LGBL_LGLK12_U32,                /* u32AddrSpaceBloLockValue */
    FLASH_SEL2_ADDR32,                    /* u32SectorBloSelRegAddr */
    FLASH_LOCK2_ADDR32,                   /* u32AddrSpaceBloLockRegAddr */
    (boolean)TRUE,                        /* bEccTriggersExc */
    28U         /* u32SectorId (Sector location to calculate cfgCRC) */
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) Fls_Flashbank_B_5_FlsConfigSet_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)0x01340000,         /* pSectorStartAddressPtr */
    FLASH_LGBS_LGSL13_U32,                /* u32AddrSpaceBloSelValue */
    FLASH_LGBL_LGLK13_U32,                /* u32AddrSpaceBloLockValue */
    FLASH_SEL2_ADDR32,                    /* u32SectorBloSelRegAddr */
    FLASH_LOCK2_ADDR32,                   /* u32AddrSpaceBloLockRegAddr */
    (boolean)TRUE,                        /* bEccTriggersExc */
    29U         /* u32SectorId (Sector location to calculate cfgCRC) */
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) Fls_Flashbank_B_6_FlsConfigSet_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)0x01380000,         /* pSectorStartAddressPtr */
    FLASH_LGBS_LGSL14_U32,                /* u32AddrSpaceBloSelValue */
    FLASH_LGBL_LGLK14_U32,                /* u32AddrSpaceBloLockValue */
    FLASH_SEL2_ADDR32,                    /* u32SectorBloSelRegAddr */
    FLASH_LOCK2_ADDR32,                   /* u32AddrSpaceBloLockRegAddr */
    (boolean)TRUE,                        /* bEccTriggersExc */
    30U         /* u32SectorId (Sector location to calculate cfgCRC) */
};
static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) Fls_Flashbank_B_7_FlsConfigSet_sInternalSectorInfo =
{
    /* 
    * @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
    * @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
    */
    (volatile uint32*)0x013C0000,         /* pSectorStartAddressPtr */
    FLASH_LGBS_LGSL15_U32,                /* u32AddrSpaceBloSelValue */
    FLASH_LGBL_LGLK15_U32,                /* u32AddrSpaceBloLockValue */
    FLASH_SEL2_ADDR32,                    /* u32SectorBloSelRegAddr */
    FLASH_LOCK2_ADDR32,                   /* u32AddrSpaceBloLockRegAddr */
    (boolean)TRUE,                        /* bEccTriggersExc */
    31U         /* u32SectorId (Sector location to calculate cfgCRC) */
};

/*  FLASH physical sectorization description */
static CONSTP2CONST(Fls_Flash_InternalSectorInfoType, FLS_VAR, FLS_APPL_CONST) FlsConfigSet_aSectorList[17] =
{
    /* FLS_CODE_ARRAY_0_PART_3_M04 */
    &Fls_Flags_Sector_FlsConfigSet_sInternalSectorInfo
    ,    /* FLS_CODE_ARRAY_0_PART_6_LG00 */
    &Fls_Flashbank_A_0_FlsConfigSet_sInternalSectorInfo
    ,    /* FLS_CODE_ARRAY_0_PART_6_LG01 */
    &Fls_Flashbank_A_1_FlsConfigSet_sInternalSectorInfo
    ,    /* FLS_CODE_ARRAY_0_PART_6_LG02 */
    &Fls_Flashbank_A_2_FlsConfigSet_sInternalSectorInfo
    ,    /* FLS_CODE_ARRAY_0_PART_6_LG03 */
    &Fls_Flashbank_A_3_FlsConfigSet_sInternalSectorInfo
    ,    /* FLS_CODE_ARRAY_0_PART_6_LG04 */
    &Fls_Flashbank_A_4_FlsConfigSet_sInternalSectorInfo
    ,    /* FLS_CODE_ARRAY_0_PART_6_LG05 */
    &Fls_Flashbank_A_5_FlsConfigSet_sInternalSectorInfo
    ,    /* FLS_CODE_ARRAY_0_PART_6_LG06 */
    &Fls_Flashbank_A_6_FlsConfigSet_sInternalSectorInfo
    ,    /* FLS_CODE_ARRAY_0_PART_6_LG07 */
    &Fls_Flashbank_A_7_FlsConfigSet_sInternalSectorInfo
    ,    /* FLS_CODE_ARRAY_0_PART_7_LG08 */
    &Fls_Flashbank_B_0_FlsConfigSet_sInternalSectorInfo
    ,    /* FLS_CODE_ARRAY_0_PART_7_LG09 */
    &Fls_Flashbank_B_1_FlsConfigSet_sInternalSectorInfo
    ,    /* FLS_CODE_ARRAY_0_PART_7_LG10 */
    &Fls_Flashbank_B_2_FlsConfigSet_sInternalSectorInfo
    ,    /* FLS_CODE_ARRAY_0_PART_7_LG11 */
    &Fls_Flashbank_B_3_FlsConfigSet_sInternalSectorInfo
    ,    /* FLS_CODE_ARRAY_0_PART_7_LG12 */
    &Fls_Flashbank_B_4_FlsConfigSet_sInternalSectorInfo
    ,    /* FLS_CODE_ARRAY_0_PART_7_LG13 */
    &Fls_Flashbank_B_5_FlsConfigSet_sInternalSectorInfo
    ,    /* FLS_CODE_ARRAY_0_PART_7_LG14 */
    &Fls_Flashbank_B_6_FlsConfigSet_sInternalSectorInfo
    ,    /* FLS_CODE_ARRAY_0_PART_7_LG15 */
    &Fls_Flashbank_B_7_FlsConfigSet_sInternalSectorInfo
};


/* External QSPI flash parameters. */

/* paHwCh[] (FlsConfigSet) */
static CONST(Fls_HwChType, FLS_CONST) FlsConfigSet_paHwCh[17] =
{
    FLS_CH_INTERN, /* (Fls_Flags_Sector) */
    FLS_CH_INTERN, /* (Fls_Flashbank_A_0) */
    FLS_CH_INTERN, /* (Fls_Flashbank_A_1) */
    FLS_CH_INTERN, /* (Fls_Flashbank_A_2) */
    FLS_CH_INTERN, /* (Fls_Flashbank_A_3) */
    FLS_CH_INTERN, /* (Fls_Flashbank_A_4) */
    FLS_CH_INTERN, /* (Fls_Flashbank_A_5) */
    FLS_CH_INTERN, /* (Fls_Flashbank_A_6) */
    FLS_CH_INTERN, /* (Fls_Flashbank_A_7) */
    FLS_CH_INTERN, /* (Fls_Flashbank_B_0) */
    FLS_CH_INTERN, /* (Fls_Flashbank_B_1) */
    FLS_CH_INTERN, /* (Fls_Flashbank_B_2) */
    FLS_CH_INTERN, /* (Fls_Flashbank_B_3) */
    FLS_CH_INTERN, /* (Fls_Flashbank_B_4) */
    FLS_CH_INTERN, /* (Fls_Flashbank_B_5) */
    FLS_CH_INTERN, /* (Fls_Flashbank_B_6) */
    FLS_CH_INTERN /* (Fls_Flashbank_B_7) */
};

/* paSectorHwAddress[] (FlsConfigSet) */
static CONST(Fls_AddressType, FLS_CONST) FlsConfigSet_paSectorHwAddress[17] =
{
    (Fls_AddressType)0U, /* (Fls_Flags_Sector) */
    (Fls_AddressType)0U, /* (Fls_Flashbank_A_0) */
    (Fls_AddressType)0U, /* (Fls_Flashbank_A_1) */
    (Fls_AddressType)0U, /* (Fls_Flashbank_A_2) */
    (Fls_AddressType)0U, /* (Fls_Flashbank_A_3) */
    (Fls_AddressType)0U, /* (Fls_Flashbank_A_4) */
    (Fls_AddressType)0U, /* (Fls_Flashbank_A_5) */
    (Fls_AddressType)0U, /* (Fls_Flashbank_A_6) */
    (Fls_AddressType)0U, /* (Fls_Flashbank_A_7) */
    (Fls_AddressType)0U, /* (Fls_Flashbank_B_0) */
    (Fls_AddressType)0U, /* (Fls_Flashbank_B_1) */
    (Fls_AddressType)0U, /* (Fls_Flashbank_B_2) */
    (Fls_AddressType)0U, /* (Fls_Flashbank_B_3) */
    (Fls_AddressType)0U, /* (Fls_Flashbank_B_4) */
    (Fls_AddressType)0U, /* (Fls_Flashbank_B_5) */
    (Fls_AddressType)0U, /* (Fls_Flashbank_B_6) */
    (Fls_AddressType)0U /* (Fls_Flashbank_B_7) */
};




/**
* @brief        Structure used to set function pointers notification, working mode
*/
/* Fls module initialization data (FlsConfigSet)*/
/* @violates @ref fls_pbcfg_c_REF_5 Could be made static */

CONST(Fls_ConfigType, FLS_CONST) FlsConfigSet=
{
    /* @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types */
    /* @violates @ref fls_pbcfg_c_REF_3 Cast from pointer to pointer */
    /* @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.*/
    (Fls_AcErasePtrType)&Fls_Flash_AccessCode, /* FlsAcErase */
    /* @violates @ref fls_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types */
    /* @violates @ref fls_pbcfg_c_REF_3 Cast from pointer to pointer */
    /* @violates @ref fls_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.*/
    (Fls_AcWritePtrType)&Fls_Flash_AccessCode, /* FlsAcWrite */
    NULL_PTR, /* FlsACCallback */  
    NULL_PTR, /* FlsJobEndNotification */
    NULL_PTR, /* FlsJobErrorNotification */  
    NULL_PTR, /* FlsStartFlashAccessNotif */
    NULL_PTR, /* FlsFinishedFlashAccessNotif */
    MEMIF_MODE_SLOW, /* FlsDefaultMode */
    1048576U, /* FlsMaxReadFastMode */
    1024U, /* FlsMaxReadNormalMode */
    256U, /* FlsMaxWriteFastMode */
    8U, /* FlsMaxWriteNormalMode */
    17U, /* FlsSectorCount */
    &FlsConfigSet_aFlsSectorEndAddr,                /* (*paSectorEndAddr)[]  */
    &FlsConfigSet_aSectorList,                      /* (*pSectorList)[] */
    &FlsConfigSet_aFlsSectorFlags,                  /* (*paSectorFlags)[] */
    &FlsConfigSet_aFlsProgSize,                     /* (*paSectorProgSize)[] */
    &FlsConfigSet_aFlsSectorPageSize,               /* (*paSectorPageSize)[] */    
    &FlsConfigSet_aFlsSectorUnlock,                 /* (*paSectorUnlock)[] */
    &FlsConfigSet_paHwCh,                           /* (*paHwCh)[] */
    &FlsConfigSet_paSectorHwAddress,                /* (*paSectorHwAddress)[] */
    16447U /* configCrc */
};
#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* 
* @violates @ref fls_pbcfg_c_REF_1 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @}*/
