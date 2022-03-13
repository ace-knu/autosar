/**
*   @file    Fee_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Fee - AUTOSAR Module Flash EEPROM Emulation Driver.
*   @details Definitions of all pre-compile configuration parameters..
*
*   @addtogroup FEE
*   @{

*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : none
*   Dependencies         : Fls
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF7_ASR_REL_4_0_REV_0003_20150304
*
*   (c) Copyright 2006-2015 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/

#ifndef FEE_CFG_H
#define FEE_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Fee_cfg_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file.
* Repeatedly included but does not have a standard include guard due to AUTOSAR 
* requirement MEMMAP003.
*
* @section Fee_cfg_h_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
* @section Fee_cfg_h_REF_3
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for macro
*
* @section Fee_cfg_h_REF_4
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fee_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_VENDOR_ID_CFG                    43U
#define FEE_MODULE_ID_CFG                    21U
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FEE_AR_RELEASE_MAJOR_VERSION_CFG     4
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FEE_AR_RELEASE_MINOR_VERSION_CFG     0
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FEE_AR_RELEASE_REVISION_VERSION_CFG  3
#define FEE_SW_MAJOR_VERSION_CFG             1
#define FEE_SW_MINOR_VERSION_CFG             0
#define FEE_SW_PATCH_VERSION_CFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MODULENAME configuration header file are of the same vendor */
#if (FEE_VENDOR_ID_CFG != FEE_TYPES_VENDOR_ID)
#error "Fee_Types.h and Fee_Cfg.h have different vendor ids"
#endif
/* Check if current file and MODULENAME configuration header file are of the same Autosar version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION_CFG    != FEE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_CFG    != FEE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_CFG != FEE_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Fee_Types.h and Fee_Cfg.h are different"
#endif
/* Check if current file and MODULENAME configuration header file are of the same software version */
#if ((FEE_SW_MAJOR_VERSION_CFG != FEE_TYPES_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_CFG != FEE_TYPES_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION_CFG != FEE_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Fee_Types.h and Fee_Cfg.h are different"
#endif
        
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/* Pre-processor switch to enable and disable development error detection */
#define FEE_DEV_ERROR_DETECT                (STD_ON)
                                        
/* Pre-processor switch to enable / disable the API to read out the modules
    version information */
#define FEE_VERSION_INFO_API                (STD_ON)

/* Compiler switch to enable/disable the SetMode functionality of the module */
#define FEE_SETMODE_API_SUPPORTED           (STD_ON)

/* Pre-processor switch to enable /disable the Fls_Cancel function of the module */
#define FEE_CANCEL_API                     (STD_OFF)

/* The size in bytes to which logical blocks shall be aligned */
#define FEE_VIRTUAL_PAGE_SIZE               (16U)

/* Job end notification routine provided by the upper layer    module (declaration) */
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_3 Disallowed definition for macro */
#define FEE_NVM_JOB_END_NOTIFICATION_DECL   extern void NvM_JobEndNotification(void);

/* Job end notification routine provided by the upper layer    module */
/* @violates @ref Fee_cfg_h_REF_3 Disallowed definition for macro */
#define FEE_NVM_JOB_END_NOTIFICATION        NvM_JobEndNotification();

/* Job error notification routine provided by the upper layer module (declaration) */
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_3 Disallowed definition for macro */
#define FEE_NVM_JOB_ERROR_NOTIFICATION_DECL  extern void NvM_JobErrorNotification(void);

/* Job error notification routine provided by the upper layer module */
/* @violates @ref Fee_cfg_h_REF_3 Disallowed definition for macro */
#define FEE_NVM_JOB_ERROR_NOTIFICATION       NvM_JobErrorNotification();

/* Number of configured Fee cluster groups */
#define FEE_NUMBER_OF_CLUSTER_GROUPS        (2U)

/* Number of configured Fee blocks */
#define FEE_NUMBER_OF_BLOCKS                (15U)

/* Management overhead per logical block in bytes */
#define FEE_BLOCK_OVERHEAD                  (48U)

/* Management overhead per logical cluster in bytes */
#define FEE_CLUSTER_OVERHEAD                (48U)

/* Size of the data buffer in bytes */
#define FEE_DATA_BUFFER_SIZE                (48U)

/* The contents of an erased flash memory cell */
#define FEE_ERASED_VALUE                    (0xffU)

/* Value of the block and cluster validation flag */
#define FEE_VALIDATED_VALUE                (0x81U)

/* Value of the block and cluster invalidation flag */
#define FEE_INVALIDATED_VALUE              (0x18U)

/* If reset, power loss etc. occurs here, neither newly nor previously written data is available */
#define FEE_BLOCK_ALWAYS_AVAILABLE          (STD_OFF)

/* Symbolic names of configured Fee blocks */
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FeeConf_FeeBlockConfiguration_FeeBlock_ConfigID     (2U)
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FeeConf_FeeBlockConfiguration_FeeBlock_ConfigID_copy1     (3U)
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FeeConf_FeeBlockConfiguration_FeeBlock_DemNonVolatileData     (4U)
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FeeConf_FeeBlockConfiguration_FeeBlock_DemNonVolatileData_copy1     (5U)
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FeeConf_FeeBlockConfiguration_FeeBlock_DemEventStatusNvRamBlock     (6U)
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FeeConf_FeeBlockConfiguration_FeeBlock_DemEventStatusNvRamBlock_copy1     (7U)
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FeeConf_FeeBlockConfiguration_FeeBlock_DemPriEvtMem_0     (8U)
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FeeConf_FeeBlockConfiguration_FeeBlock_DemPriEvtMem_0_copy1     (9U)
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FeeConf_FeeBlockConfiguration_FeeBlock_DemPriEvtMem_1     (10U)
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FeeConf_FeeBlockConfiguration_FeeBlock_DemPriEvtMem_1_copy1     (11U)
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FeeConf_FeeBlockConfiguration_FeeBlock_DemPriEvtMem_2     (12U)
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FeeConf_FeeBlockConfiguration_FeeBlock_DemPriEvtMem_2_copy1     (13U)
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FeeConf_FeeBlockConfiguration_FeeBlock_IntTst_TestBlock1     (14U)
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FeeConf_FeeBlockConfiguration_FeeBlock_IntTst_TestBlock2     (16U)
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FeeConf_FeeBlockConfiguration_FeeBlock_IntTst_TestBlock3     (18U)
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
#define FEE_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Fee_cfg_h_REF_1 Repeated include file */
#include "MemMap.h"


/* Configuration of cluster group set */
extern CONST(Fee_ClusterGroupType, FEE_CONST) Fee_ClrGrps[FEE_NUMBER_OF_CLUSTER_GROUPS];

/* Configuration of Fee blocks */
extern CONST(Fee_BlockConfigType, FEE_CONST) Fee_BlockConfig[FEE_NUMBER_OF_BLOCKS];

/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
#define FEE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Fee_cfg_h_REF_1 Repeated include file */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* FEE_CFG_H */

/** @} */
