/**
*   @file    Fls_Cfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Definitions of all Pre-compile configuration structures.
*
*   @addtogroup FLS
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : Flash_Memory
*   Dependencies         : 
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20140606
*
*   (c) Copyright 2006-2014 Freescale Semiconductor Inc and STMicroelectronics
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
* @section fls_cfg_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_cfg_c_REF_2
* Violates MISRA 2004 Advisory Rule 11.4,  A cast should not be performed between a pointer
* to object type and a different pointer to object type
* Due to casting between a pointer and unsigned long
*
* @section fls_cfg_c_REF_4
* Violates MISRA 2004 Required Rule 1.2, No reliance shall be placed on undefined or unspecified behaviour
* This violation is because of complex statement
*
* @section fls_cfg_c_REF_8
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer
* to a function and any type other than an integral type contents in that address.
* This violation is due to casting unsigned long to pointer and access these addresses for updating
* contents in that address.
*
* @section fls_cfg_c_REF_9
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_cfg_c_REF_12
* Violates MISRA 2004 Required Rule 11.5, A cast shall not be performed that removes any const and
* volatile qualification from the type address by a pointer
* Because of removing the const qualification from the type address by a pointer
*
* @section fls_cfg_c_REF_13
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
*
* @section fls_cfg_c_REF_15
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters. These Mcro  names are decided as per AUTOSAR guideline.
*
* @section fls_cfg_c_REF_19
* Violates MISRA 2004 Required Rule 8.12,
* When an array is declared with external linkage, its size shall be stated explicitly or defined
* implicitly by initialization.
* The size of the required array eliment is fixed for one compiler. But across compilers this size
* will vary. So in this array definition specific size is not mentioned.
*
* @section fls_cfg_c_REF_20
* Violates MISRA 2004 Required Rule 10.1,
* The value of an expression of integer type shall not be implicitly converted to a different underlying type if:
* a. it is not a conversion to a wider integer type of the same signedness, or
* b. the expression is complex, or
* c. the expression is not constant and is a function argument, or
* d. the expression is not constant and is a return expression.
* The expression is constant so as per above part (c) this expression is required
*
* @section fls_cfg_c_REF_21
* Violates MISRA 2004 Required Rule 20.2,
* The name of standard library macros, objects and functions shall not be reused.
* This violation is because of library macros, objects and functions are reused
*
* @section fls_cfg_c_REF_29
* Violates MISRA 2004 Required Rule 16.9, A function identifier shall only be used with either a
* preceding &, or with a parenthesised parameter list, which may be empty.
* This function identifier is used as function pointer.
*
* @section fls_cfg_c_REF_30
* Violates MISRA 2004 Advisory Rule 6.3, Typedefs that indicate size and signedness should be used in place of the basic types
*
* @section fls_cfg_c_REF_31
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared in one and only one file
*
*/

/* @implements     DFLS02072 */

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#include "Dem.h"
#ifdef FLS_PRECOMPILE_SUPPORT

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @implements     DFLS02068 */
#define FLS_VENDOR_ID_PCFG_C                      43
/*
* @violates @ref fls_cfg_c_REF_13 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
/*
* @violates @ref fls_cfg_c_REF_15 Identifiers more than 31 characters.
*/
#define FLS_AR_RELEASE_MAJOR_VERSION_PCFG_C       4
/*
* @violates @ref fls_cfg_c_REF_13 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
/*
* @violates @ref fls_cfg_c_REF_15 Identifiers more than 31 characters.
*/
#define FLS_AR_RELEASE_MINOR_VERSION_PCFG_C       0
/*
* @violates @ref fls_cfg_c_REF_13 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
/*
* @violates @ref fls_cfg_c_REF_15 Identifiers more than 31 characters.
*/
#define FLS_AR_RELEASE_REVISION_VERSION_PCFG_C    3
#define FLS_SW_MAJOR_VERSION_PCFG_C               1
#define FLS_SW_MINOR_VERSION_PCFG_C               0
#define FLS_SW_PATCH_VERSION_PCFG_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
/* @violates @ref fls_cfg_c_REF_20 Implicitly converted to a different underlying type */
#if (FLS_VENDOR_ID_PCFG_C != FLS_VENDOR_ID)
    #error "Fls_Cfg.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_PCFG_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_PCFG_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_PCFG_C != FLS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fls_Cfg.c and Fls.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_PCFG_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_PCFG_C != FLS_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_PCFG_C != FLS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fls_Cfg.c and Fls.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if source file and Dem header file are of the same version */
 #if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG != DEM_AR_RELEASE_MINOR_VERSION))
 #error "AutoSar Version Numbers of Fls_Cfg.h and Dem.h are different"
 #endif
#endif

                            
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define FLS_START_SEC_CODE
/*
* @violates @ref fls_cfg_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_cfg_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"

/* Declaration of Fls notification function (Fee_JobEndNotification())*/
/* @violates @ref fls_cfg_c_REF_21 The name of standard library macros, objects and functions shall not be reused */
extern FUNC( void, FLS_CODE ) Fee_JobEndNotification( void );


/* Declaration of Fls notification function (Fee_JobErrorNotification())*/
/* @violates @ref fls_cfg_c_REF_21 The name of standard library macros, objects and functions shall not be reused */
extern FUNC( void, FLS_CODE ) Fee_JobErrorNotification( void );

#define FLS_STOP_SEC_CODE
/*
* @violates @ref fls_cfg_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_cfg_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

#define FLS_START_SEC_CONST_UNSPECIFIED
/*
* @violates @ref fls_cfg_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_cfg_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"
/* Position independent erase/write access code in ROM */
/*
* @violates @ref fls_cfg_c_REF_31  An external object or function shall be declared in one and only one file
*/
extern FUNC(void, FLS_CODE) Fls_LLD_AccessCode(P2VAR(volatile uint32, AUTOMATIC, FLS_CODE) regBasePtr,\
                                        P2FUNC(void, FLS_CODE, CallBack)(),\
                                        P2VAR(volatile uint32, AUTOMATIC, FLS_CODE) timerCounterAC);
 
#define FLS_STOP_SEC_CONST_UNSPECIFIED
/*
* @violates @ref fls_cfg_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_cfg_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"

/*
* @violates @ref fls_cfg_c_REF_15 Identifiers more than 31 characters.
*/
#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref fls_cfg_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_cfg_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"
/**
* @brief         Values for production code Event Ids.
* @details       FLS production code Event Ids.
*
*/
/*
* @violates @ref fls_cfg_c_REF_15 Identifiers more than 31 characters.
*/
#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref fls_cfg_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_cfg_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"

#define FLS_START_SEC_CONFIG_DATA_8
/*
* @violates @ref fls_cfg_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_cfg_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"
/* FlsSectorFlags[] (FlsConfigSet_0) */
STATIC CONST(uint8, FLS_CONST) FlsConfigSet_0_FlsSectorFlags[4] =
{
    FLS_SECTOR_ERASE_ASYNCH | FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_0) */
    FLS_SECTOR_ERASE_ASYNCH | FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_1) */
    FLS_SECTOR_ERASE_ASYNCH | FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_2) */
    FLS_SECTOR_ERASE_ASYNCH | FLS_PAGE_WRITE_ASYNCH /* (FlsSector_3) */
};
/* FlsSectorUnlock[] (FlsConfigSet_0) */
STATIC CONST(uint8, FLS_CONST) FlsConfigSet_0_FlsSectorUnlock[4] =
{
    1U, /* (FlsSector_0) */
    1U, /* (FlsSector_1) */
    1U, /* (FlsSector_2) */
    1U /* (FlsSector_3) */
};
#define FLS_STOP_SEC_CONFIG_DATA_8
/*
* @violates @ref fls_cfg_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_cfg_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"

/*
* @violates @ref fls_cfg_c_REF_15 Identifiers more than 31 characters.
*/
#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref fls_cfg_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_cfg_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"
/* FlsSectorEndAddr[] (FlsConfigSet_0) */
STATIC CONST(Fls_AddressType, FLS_CONST) FlsConfigSet_0_FlsSectorEndAddr[4] =
{
    16383U, /* FlsSectorEndAddr (FlsSector_0)*/
    32767U, /* FlsSectorEndAddr (FlsSector_1)*/
    49151U, /* FlsSectorEndAddr (FlsSector_2)*/
    65535U /* FlsSectorEndAddr (FlsSector_3)*/
};
/* FlsPageSize[] (FlsConfigSet_0) */
STATIC CONST(Fls_LengthType, FLS_CONST) FlsConfigSet_0_FlsPageSize[4] =
{
    8U, /* FlsPageSize (FlsSector_0) */
    8U, /* FlsPageSize (FlsSector_1) */
    8U, /* FlsPageSize (FlsSector_2) */
    8U /* FlsPageSize (FlsSector_3) */
};
/* FlsProgrammingSize[] (FlsConfigSet_0) */
STATIC CONST(Fls_LengthType, FLS_CONST) FlsConfigSet_0_FlsProgSize[4] =
{
/* @violates @ref fls_cfg_c_REF_20 Implicitly converted to a different underlying type */
    FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_0) */
/* @violates @ref fls_cfg_c_REF_20 Implicitly converted to a different underlying type */
    FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_1) */
/* @violates @ref fls_cfg_c_REF_20 Implicitly converted to a different underlying type */
    FLS_WRITE_DOUBLE_WORD, /* FlsProgrammingSize (FlsSector_2) */
/* @violates @ref fls_cfg_c_REF_20 Implicitly converted to a different underlying type */
    FLS_WRITE_DOUBLE_WORD /* FlsProgrammingSize (FlsSector_3) */
/* @violates @ref fls_cfg_c_REF_20 Implicitly converted to a different underlying type */
};
/* FlsPhysicalSector[] (FlsConfigSet_0) */
/*
* @violates @ref fls_cfg_c_REF_15 Identifiers more than 31 characters.
*/
STATIC CONST(Fls_LLD_PhysicalSectorType, FLS_CONST) FlsConfigSet_0_FlsPhysicalSector[4] =
{
    FLS_DATA_ARRAY_0_L00, /* FlsPhysicalSector (FlsSector_0) */
    FLS_DATA_ARRAY_0_L01, /* FlsPhysicalSector (FlsSector_1) */
    FLS_DATA_ARRAY_0_L02, /* FlsPhysicalSector (FlsSector_2) */
    FLS_DATA_ARRAY_0_L03 /* FlsPhysicalSector (FlsSector_3) */
};
/**
* @brief        Structure used to set function pointers notification, working mode
* @implements   DFLS02073, DFLS02074, DFLS02075, DFLS02076, DFLS02077, DFLS02078, DFLS02079, DFLS02080, DFLS02081, DFLS02082, DFLS02083, DFLS02084, DFLS02085
*/
/* Fls module initialization data */ 
CONST(Fls_ConfigType, FLS_CONST) Fls_ConfigSetPC =
{
    /*
    * @violates @ref fls_cfg_c_REF_12 A cast shall not be performed that removes any const and
    * volatile qualification from the type address by a pointer
    * @violates @ref fls_cfg_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    * @violates @ref fls_cfg_c_REF_8 Conversions shall not be performed between 
    * a pointer to a function and any type other than an integral type
    * @violates @ref fls_cfg_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    */    
    (Fls_LLD_AcErasePtrType)&Fls_LLD_AccessCode, /* FlsAcErase */
    /*
    * @violates @ref fls_cfg_c_REF_12 A cast shall not be performed that removes any const and
    * volatile qualification from the type address by a pointer
    * @violates @ref fls_cfg_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    * @violates @ref fls_cfg_c_REF_8 Conversions shall not be performed between 
    * a pointer to a function and any type other than an integral type
    * @violates @ref fls_cfg_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    */      
    (Fls_LLD_AcWritePtrType)&Fls_LLD_AccessCode, /* FlsAcWrite */
    /*
    * @violates @ref fls_cfg_c_REF_29 A function identifier shall only be used with either a
    * preceding &, or with a parenthesised parameter list, which may be empty.
    */
    NULL_PTR, /* FlsACCallback */
    /*
    * @violates @ref fls_cfg_c_REF_29 A function identifier shall only be used with either a
    * preceding &, or with a parenthesised parameter list, which may be empty.
    */    
    Fee_JobEndNotification, /* FlsJobEndNotification */
    /*
    * @violates @ref fls_cfg_c_REF_29 A function identifier shall only be used with either a
    * preceding &, or with a parenthesised parameter list, which may be empty.
    */    
    Fee_JobErrorNotification, /* FlsJobErrorNotification */
    MEMIF_MODE_FAST, /* FlsDefaultMode */
    1048576U, /* FlsMaxReadFastMode */
    1024U, /* FlsMaxReadNormalMode */
    256U, /* FlsMaxWriteFastMode */
    256U, /* FlsMaxWriteNormalMode */
    4U, /* FlsSectorCount */
    FlsConfigSet_0_FlsSectorEndAddr, /* FlsSectorEndAddr[]  */
    FlsConfigSet_0_FlsPhysicalSector, /* FlsPhysicalSector[] */
    FlsConfigSet_0_FlsSectorFlags, /* FlsSectorFlags[] */
    FlsConfigSet_0_FlsPageSize, /* FlsPageSize[] */
    FlsConfigSet_0_FlsProgSize, /* FlsProgSize[] */
    FlsConfigSet_0_FlsSectorUnlock, /* FlsSectorUnlock[] */

    /**
     * @brief   DEM error parameters
     */
/* @violates @ref fls_cfg_c_REF_20 Implicitly converted to a different underlying type */
    {STD_ON, 2U},    /* FLS_E_COMPARE_FAILED parameters */
/* @violates @ref fls_cfg_c_REF_20 Implicitly converted to a different underlying type */
    {STD_ON, 3U},    /* FLS_E_ERASE_FAILED parameters */
/* @violates @ref fls_cfg_c_REF_20 Implicitly converted to a different underlying type */
    {STD_ON, 4U},    /* FLS_E_READ_FAILED parameters */
/* @violates @ref fls_cfg_c_REF_20 Implicitly converted to a different underlying type */
    {STD_ON, 5U},    /* FLS_E_UNEXPECTED_FLASH_ID parameters */
/* @violates @ref fls_cfg_c_REF_20 Implicitly converted to a different underlying type */
    {STD_ON, 6U}     /* FLS_E_WRITE_FAILED parameters */
};
/*
* @violates @ref fls_cfg_c_REF_15 Identifiers more than 31 characters.
*/
#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref fls_cfg_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_cfg_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"


#endif /* FLS_PRECOMPILE_SUPPORT */
#ifdef __cplusplus
}
#endif

/** @}*/
