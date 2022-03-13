/**
*   @file    Fls_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Definitions of all pre-compile configuration parameters.
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

#ifndef FLS_CFG_H
#define FLS_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Fls_Cfg_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section Fls_Cfg_H_REF_2
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters. These Mcro  names are decided as per AUTOSAR guideline.
*
* @section Fls_Cfg_H_REF_3
* Violates MISRA 2004 Required Rule 8.7,
* Objects shall be defined at block scope if they are only accessed from within 
* a single function.
* This violation is because of Objects are defined global but used within a single function
*
*/

/* @implements     DFLS02070 */

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls_Types.h"
#include "Mcal.h"
#include "Dem.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @implements     DFLS02068 */
#define FLS_VENDOR_ID_CFG                    43
#define FLS_MODULE_ID_CFG                    92
/*
* @violates @ref Fls_Cfg_H_REF_2 Identifiers more than 31 characters.
*/
#define FLS_AR_RELEASE_MAJOR_VERSION_CFG     4
/*
* @violates @ref Fls_Cfg_H_REF_2 Identifiers more than 31 characters.
*/
#define FLS_AR_RELEASE_MINOR_VERSION_CFG     0
/*
* @violates @ref Fls_Cfg_H_REF_2 Identifiers more than 31 characters.
*/
#define FLS_AR_RELEASE_REVISION_VERSION_CFG  3
#define FLS_SW_MAJOR_VERSION_CFG             1
#define FLS_SW_MINOR_VERSION_CFG             0
#define FLS_SW_PATCH_VERSION_CFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls configuration header file are of the same vendor */
#if (FLS_TYPES_VENDOR_ID != FLS_VENDOR_ID_CFG)
#error "Fls_Types.h and Fls_Cfg.h have different vendor ids"
#endif
/* Check if current file and Fls configuration header file are of the same Autosar version */
#if ((FLS_TYPES_AR_RELEASE_MAJOR_VERSION    != FLS_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_TYPES_AR_RELEASE_MINOR_VERSION    != FLS_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_TYPES_AR_RELEASE_REVISION_VERSION != FLS_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Fls_Types.h and Fls_Cfg.h are different"
#endif
/* Check if current file and Fls configuration header file are of the same software version */
#if ((FLS_TYPES_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION_CFG) || \
     (FLS_TYPES_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION_CFG) || \
     (FLS_TYPES_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Fls_Types.h and Fls_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if source file and Dem header file are of the same version */
 #if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG != DEM_AR_RELEASE_MINOR_VERSION))
 #error "AutoSar Version Numbers of Fls_Cfg.h and Dem.h are different"
 #endif
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* STD_ON: Flash access code loaded on job start / unloaded on job end or error */
#define FLS_AC_LOAD_ON_JOB_START    (STD_OFF)

/* Compile switch to enable and disable the Fls_Cancel function */
#define FLS_CANCEL_API              (STD_OFF)

/* Compile switch to enable and disable the Fls_Compare function */
#define FLS_COMPARE_API             (STD_OFF)

/* Pre-processor switch to enable and disable development error detection */
#define FLS_DEV_ERROR_DETECT        (STD_ON)

/* Compile switch to enable and disable the Fls_GetJobResult function */
#define FLS_GET_JOB_RESULT_API      (STD_ON)

/* Compile switch to enable and disable the Fls_GetStatus function */
#define FLS_GET_STATUS_API          (STD_ON)

/* Compile switch to enable and disable the Fls_SetMode function */
#define FLS_SET_MODE_API            (STD_ON)

/* Pre-processor switch to enable / disable the API to read out the modules version information */
#define FLS_VERSION_INFO_API        (STD_ON)

/* Pre-processor switch to enable / disable the API to report data storage (ECC) errors to the flash driver */
#define FLS_DSI_HANDLER_API         (STD_ON)

/* Pre-processor switch to enable / disable the API to report data storage (ECC) errors to the flash driver */
#define FLS_ECC_WITH_NO_EXCEPTION   (STD_ON)

/* Pre-processor switch to enable / disable the erase blank check */
#define FLS_ERASE_BLANK_CHECK       (STD_ON)

/* Pre-processor switch to enable / disable the write blank check */
#define FLS_WRITE_BLANK_CHECK       (STD_ON)

/* Pre-processor switch to enable / disable the write verify check */
#define FLS_WRITE_VERIFY_CHECK      (STD_ON)

/* The maximum number of bytes to blank check in one cycle of the flash driver's job processing function */
#define FLS_MAX_ERASE_BLANK_CHECK   256U

/* Timeout value for Erase and Write operation (also used fot resumed oparation) */
#define FLS_OPT_TIMEOUT_VALUE        2147483647U

/* Timeout value for Abort operation */
#define FLS_ABT_TIMEOUT_VALUE        32767U

/* Number of bytes in RAM needed for the erase flash access code */
#define FLS_AC_SIZE_ERASE           84U

/* Number of bytes in RAM needed for the write flash access code */
#define FLS_AC_SIZE_WRITE           84U

/* The contents of an erased flash memory cell */
#define FLS_ERASED_VALUE            0xffffffffU

/* Fls Driver Index */
/*
* @violates @ref Fls_Cfg_H_REF_2 Identifiers more than 31 characters.
*/
#define FlsConf_FlsGeneral_FlsDriverIndex_0            0U

/**
* @brief   Switches the Production Error Detection and Notification OFF
*/

#define FLS_DEM_ERROR_DETECT   (STD_ON)  /* Enable Production Error Detection */


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Fls Config Type
* @details        Fls module initialization data structure
* @implements     DFLS02006
*/
typedef struct
{
    /**
    * @brief pointer to erase access code function in RAM or ROM
    */
    Fls_LLD_AcErasePtrType acErasePtr;
    /**
    * @brief pointer to write access code function in RAM or ROM
    */
    Fls_LLD_AcWritePtrType acWritePtr;
    /**
    * @brief pointer to ac callback function
    */
    Fls_ACCallbackPtrType acCallBackPtr;
    /**
    * @brief pointer to job end notification function
    */
    Fls_JobEndNotificationPtrType jobEndNotificationPtr;
    /**
    * @brief pointer to job error notification function
    */
    Fls_JobErrorNotificationPtrType jobErrorNotificationPtr;
    /**
    * @brief default FLS device mode after initialization (MEMIF_MODE_FAST, MEMIF_MODE_SLOW)
    */
    MemIf_ModeType defaultMode;
    /**
    * @brief max number of bytes to read in one cycle of Fls_MainFunction (fast mode)
    */
    Fls_LengthType maxReadFastMode;
    /**
    * @brief max number of bytes to read in one cycle of  Fls_MainFunction (normal mode)
    */
    Fls_LengthType maxReadNormalMode;
    /**
    * @brief max number of bytes to write in one cycle of Fls_MainFunction (fast mode)
    */
    Fls_LengthType maxWriteFastMode;
    /**
    * @brief max number of bytes to write in one cycle of  Fls_MainFunction (normal mode)
    */
    Fls_LengthType maxWriteNormalMode;
    /**
    * @brief number of configured logical sectors
    */
    Fls_SectorCountType sectorCount;
    /**
    * @brief pointer to array containing last logical address of each configured sector
    */
    CONSTP2CONST( Fls_AddressType, FLS_CONST, FLS_APPL_CONST ) sectorEndAddr;
    /**
    * @brief pointer to array containing physical sector ID of each configured sector
    */
    CONSTP2CONST( Fls_LLD_PhysicalSectorType, FLS_CONST, FLS_APPL_CONST ) physicalSector;
    /**
    * @brief pointer to array containing flags set of each configured sector
    */
    CONSTP2CONST( uint8, FLS_CONST, FLS_APPL_CONST ) sectorFlags;
    /**
    * @brief pointer to array containing page size of each configured sector
    */
    CONSTP2CONST( Fls_LengthType, FLS_CONST, FLS_APPL_CONST ) sectorPageSize;
    /**
    * @brief pointer to array containing page size of each configured sector
    */
    CONSTP2CONST( Fls_LengthType, FLS_CONST, FLS_APPL_CONST ) sectorProgSize;
    /**
    * @brief pointer to array containing Unlock information of each configured sector
    */
    CONSTP2CONST( uint8, FLS_CONST, FLS_APPL_CONST ) sectorUnlock;

    /**
     * @brief FLS Driver DEM Error: FLS_E_COMPARE_FAILED
     * @implements     DFLS05051
     */
    CONST(Mcal_DemErrorType, FLS_CONST) Fls_E_CompareFailedCfg;
    /**
     * @brief FLS Driver DEM Error: FLS_E_ERASE_FAILED
     * @implements     DFLS05052
     */
    CONST(Mcal_DemErrorType, FLS_CONST) Fls_E_EraseFailedCfg;
    /**
     * @brief FLS Driver DEM Error: FLS_E_READ_FAILED
     * @implements     DFLS05053
     */
    CONST(Mcal_DemErrorType, FLS_CONST) Fls_E_ReadFailedCfg;
    /**
     * @brief FLS Driver DEM Error: FLS_E_UNEXPECTED_FLASH_ID
     * @implements     DFLS05054
     */
    CONST(Mcal_DemErrorType, FLS_CONST) Fls_E_UnexpectedFlashIdCfg;
    /**
     * @brief FLS Driver DEM Error: FLS_E_WRITE_FAILED
     * @implements     DFLS05055
     */
    CONST(Mcal_DemErrorType, FLS_CONST) Fls_E_WriteFailedCfg;


} Fls_ConfigType;

/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/
/*
* @violates @ref Fls_Cfg_H_REF_2 Identifiers more than 31 characters.
*/
#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Fls_Cfg_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"
/**
* @brief         Declaration of Dem events.
* @implements
*/


/* Precompile Support OFF */
/* FLS_PRECOMPILE_SUPPORT must be defined only for Pre-Compile version. */

#ifdef FLS_PRECOMPILE_SUPPORT
/* Declaration of pre-compile structure */
/*
* @violates @ref Fls_Cfg_H_REF_3 Objects shall be defined at block scope if they are only accessed from within 
* a single function.
*/
extern CONST(Fls_ConfigType, FLS_CONST) Fls_ConfigSetPC;
#else /* FLS_PRECOMPILE_SUPPORT */

/* Declaration of post-build structure (FlsConfigSet_0)*/
/*
* @violates @ref Fls_Cfg_H_REF_3 Objects shall be defined at block scope if they are only accessed from within 
* a single function.
*/
extern CONST(Fls_ConfigType, FLS_CONST) FlsConfigSet_0;

#endif /* FLS_PRECOMPILE_SUPPORT */ 
/*
* @violates @ref Fls_Cfg_H_REF_2 Identifiers more than 31 characters.
*/
#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Fls_Cfg_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* FLS_CFG_H */
