
#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section fls_flash_const_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_c_REF_42
* Violates MISRA 2004 Required Rule 8.11, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_flash_const_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_flash_const_c_REF_3
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* The variable is used across module.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#include "Fls_Flash_Types.h"
#include "Reg_eSys_FLASHC.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_FLASH_CONST_VENDOR_ID_C                           43
#define FLS_FLASH_CONST_MODULE_ID_C                           92
#define FLS_FLASH_CONST_AR_RELEASE_MAJOR_VERSION_C            4
#define FLS_FLASH_CONST_AR_RELEASE_MINOR_VERSION_C            3
#define FLS_FLASH_CONST_AR_RELEASE_REVISION_VERSION_C         1
#define FLS_FLASH_CONST_SW_MAJOR_VERSION_C                    1
#define FLS_FLASH_CONST_SW_MINOR_VERSION_C                    0
#define FLS_FLASH_CONST_SW_PATCH_VERSION_C                    1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls.h header file are of the same vendor */
#if (FLS_FLASH_CONST_VENDOR_ID_C != FLS_VENDOR_ID)
    #error "Fls_Flash_Const.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls.h header file are of the same Software version */
#if ((FLS_FLASH_CONST_SW_MAJOR_VERSION_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_FLASH_CONST_SW_MINOR_VERSION_C != FLS_SW_MINOR_VERSION) || \
     (FLS_FLASH_CONST_SW_PATCH_VERSION_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Flash_Const.c and Fls.h are different"
#endif
/* Check if current file and Dem header file are of the same Autosar version */
#if ((FLS_FLASH_CONST_AR_RELEASE_MAJOR_VERSION_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_FLASH_CONST_AR_RELEASE_MINOR_VERSION_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_FLASH_CONST_AR_RELEASE_REVISION_VERSION_C != FLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_Flash_Const.c and Fls.h are different"
#endif


/* Check if current file and Fls_Flash_Types.h header file are of the same vendor */
#if (FLS_FLASH_CONST_VENDOR_ID_C != FLS_FLASH_TYPES_VENDOR_ID)
    #error "Fls_Flash_Const.c and Fls_Flash_Types.h have different vendor ids"
#endif
/* Check if current file and Fls_Flash_Types.h header file are of the same Software version */
#if ((FLS_FLASH_CONST_SW_MAJOR_VERSION_C != FLS_FLASH_TYPES_SW_MAJOR_VERSION) || \
     (FLS_FLASH_CONST_SW_MINOR_VERSION_C != FLS_FLASH_TYPES_SW_MINOR_VERSION) || \
     (FLS_FLASH_CONST_SW_PATCH_VERSION_C != FLS_FLASH_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Flash_Const.c and Fls_Flash_Types.h are different"
#endif
/* Check if current file and Dem header file are of the same Autosar version */
#if ((FLS_FLASH_CONST_AR_RELEASE_MAJOR_VERSION_C    != FLS_FLASH_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_FLASH_CONST_AR_RELEASE_MINOR_VERSION_C    != FLS_FLASH_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLS_FLASH_CONST_AR_RELEASE_REVISION_VERSION_C != FLS_FLASH_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_Flash_Const.c and Fls_Flash_Types.h are different"
#endif

/* Check if current file and Reg_eSys_FLASHC.h header file are of the same vendor */
#if (FLS_FLASH_CONST_VENDOR_ID_C != ESYS_FLASHC_VENDOR_ID)
    #error "Fls_Flash_Const.c and Reg_eSys_FLASHC.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_FLASHC.h header file are of the same Software version */
#if ((FLS_FLASH_CONST_SW_MAJOR_VERSION_C != ESYS_FLASHC_SW_MAJOR_VERSION) || \
     (FLS_FLASH_CONST_SW_MINOR_VERSION_C != ESYS_FLASHC_SW_MINOR_VERSION) || \
     (FLS_FLASH_CONST_SW_PATCH_VERSION_C != ESYS_FLASHC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Flash_Const.c and Reg_eSys_FLASHC.h are different"
#endif
/* Check if current file and Dem header file are of the same Autosar version */
#if ((FLS_FLASH_CONST_AR_RELEASE_MAJOR_VERSION_C    != ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_FLASH_CONST_AR_RELEASE_MINOR_VERSION_C    != ESYS_FLASHC_AR_RELEASE_MINOR_VERSION) || \
     (FLS_FLASH_CONST_AR_RELEASE_REVISION_VERSION_C != ESYS_FLASHC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_Flash_Const.c and Reg_eSys_FLASHC.h are different"
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
#define FLS_START_SEC_CONST_UNSPECIFIED
/*
* @violates @ref fls_flash_const_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
*/
#include "Fls_MemMap.h"

/**
    @brief FLASH array description
*/
/* @violates @ref fls_flash_const_c_REF_3 All declarations and definitions of objects or functions. */
CONST(Fls_Flash_ArrayInfoType, FLS_CONST) Fls_Flash_aArrayList0[1U]=
{
    {    /* FLS_CODE_ARRAY_0_A */
        (boolean)TRUE,      /*bProgramSuspPossible*/
        (boolean)TRUE       /*bEraseSuspPossible*/
    }
};


#define FLS_STOP_SEC_CONST_UNSPECIFIED
/*
* @violates @ref fls_flash_const_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_flash_const_c_REF_2 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"



#define FLS_START_SEC_CONST_32
/*
* @violates @ref fls_flash_const_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_flash_const_c_REF_2 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"

#if (FLS_BLANK_CHECK_API == STD_ON)
/**
    @brief Flash erased value for erased state
*/
/*
* @violates @ref fls_c_REF_42 Objects shall be defined at block scope if they are only accessed
* from within a single function
*/
CONST(uint32, FLS_CONST) Fls_Flash_ErasedValue = FLS_ERASED_VALUE;
#endif

/**
    @brief Mapping between command ID and number of FCCOB registers used.
*/
/* @violates @ref fls_flash_const_c_REF_3 All declarations and definitions of objects or functions. */
CONST(uint32, FLS_CONST) Fls_Flash_FccobixCmdSize[20U]=
{
    (uint32)0UL,    /* ARR[0] RESERVED */
    (uint32)0UL,    /* ARR[1] FLASH_CMD_ERASE_VERIFY_ALL_BLOCKS_U8 */
    (uint32)1UL,    /* ARR[2] FLASH_CMD_ERASE_VERIFY_BLOCK_U8 */
    (uint32)2UL,    /* ARR[3] FLASH_CMD_ERASE_VERIFY_PFLASH_U8 */
    (uint32)1UL,    /* ARR[4] FLASH_CMD_READ_ONCE_U8 */
    (uint32)0UL,    /* ARR[5] RESERVED */
    (uint32)5UL,    /* ARR[6] FLASH_CMD_PROGRAM_PFLASH_U8 */
    (uint32)5UL,    /* ARR[7] FLASH_CMD_PROGRAM_ONCE_U8 */
    (uint32)0UL,    /* ARR[8] FLASH_CMD_ERASE_ALL_BLOCKS_U8 */
    (uint32)1UL,    /* ARR[9] FLASH_CMD_ERASE_FLASH_BLOCK_U8 */
    (uint32)1UL,    /* ARR[A] FLASH_CMD_ERASE_PFLASH_SECTOR_U8 */
    (uint32)0UL,    /* ARR[B] FLASH_CMD_UNSECURE_FLASH_U8 */
    (uint32)0UL,    /* ARR[C] FLASH_CMD_VERIFY_BACKDOOR_KEY_U8 */
    (uint32)2UL,    /* ARR[D] FLASH_CMD_SET_USER_MARGIN_U8 */
    (uint32)2UL,    /* ARR[E] FLASH_CMD_SET_FIELD_MARGIN_U8 */
    (uint32)0UL,    /* ARR[F] RESERVED */
    (uint32)2UL,    /* ARR[10] FLASH_CMD_ERASE_VERIFY_EEPROM_SECTION_U8 */
    (uint32)0UL,    /* ARR[11] FLASH_CMD_PROGRAM_EEPROM_U8. Note: variable length! */
    (uint32)1UL,    /* ARR[12] FLASH_CMD_ERASE_EEPROM_SECTOR_U8 */
    (uint32)0UL     /* ARR[13] FLASH_CMD_PROTECTION_OVERRIDE_U8. Note: variable length! */
};

#define FLS_STOP_SEC_CONST_32
/*
* @violates @ref fls_flash_const_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_flash_const_c_REF_2 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"




#ifdef __cplusplus
}
#endif
