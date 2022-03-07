/**
*   @file    Fee_Cfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Fee - AUTOSAR Module Flash EEPROM Emulation Driver.
*   @details Definitions of all Pre-compile configuration structures.
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
/*==================================================================================================
==================================================================================================*/

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
*
* @section Fee_cfg_h_REF_5
* Violates MISRA 2004 Advisory Rule 19.1, #include statement preceded by some code 
* #include statements should only be preceded by other preprocessor directiove or comments.
*
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fee.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_VENDOR_ID_CFG_C                      43U
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FEE_AR_RELEASE_MAJOR_VERSION_CFG_C       4
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FEE_AR_RELEASE_MINOR_VERSION_CFG_C       0
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FEE_AR_RELEASE_REVISION_VERSION_CFG_C    3
/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
/* @violates @ref Fee_cfg_h_REF_4 Identifier clash */
#define FEE_SW_MAJOR_VERSION_CFG_C               1
#define FEE_SW_MINOR_VERSION_CFG_C               0
#define FEE_SW_PATCH_VERSION_CFG_C               1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Fee header file are of the same vendor */
#if (FEE_VENDOR_ID_CFG_C != FEE_VENDOR_ID)
    #error "Fee_Cfg.c and Fee.h have different vendor ids"
#endif
/* Check if current file and Fls header file are of the same Autosar version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION_CFG_C    != FEE_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_CFG_C    != FEE_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_CFG_C != FEE_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fee_Cfg.c and Fee.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FEE_SW_MAJOR_VERSION_CFG_C != FEE_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_CFG_C != FEE_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION_CFG_C != FEE_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fee_Cfg.c and Fee.h are different"
#endif



/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
#define FEE_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Fee_cfg_h_REF_1 Repeated include file */
#include "MemMap.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/



/* Configuration of cluster group FeeClusterGroup0 */
STATIC CONST(Fee_ClusterType, FEE_CONST) Fee_FeeClusterGroup0[2] =
{
    /* FeeCluster_0 */
    {
        0U, /* Start address */
        16384U /* Size */
    },
    /* FeeCluster_1 */
    {
        16384U, /* Start address */
        16384U /* Size */
    }
};

/* Configuration of cluster group FeeClusterGroup1 */
STATIC CONST(Fee_ClusterType, FEE_CONST) Fee_FeeClusterGroup1[2] =
{
    /* FeeCluster_2 */
    {
        32768U, /* Start address */
        16384U /* Size */
    },
    /* FeeCluster_3 */
    {
        49152U, /* Start address */
        16384U /* Size */
    }
};

/* Configuration of cluster group set */
CONST(Fee_ClusterGroupType, FEE_CONST) Fee_ClrGrps[FEE_NUMBER_OF_CLUSTER_GROUPS] =
{
    /* FeeClusterGroup0 */
    {
        Fee_FeeClusterGroup0, /* Cluster set */
        2U /* Number of clusters */
    },
    /* FeeClusterGroup1 */
    {
        Fee_FeeClusterGroup1, /* Cluster set */
        2U /* Number of clusters */
    }
};

/* Configuration of Fee blocks */
CONST(Fee_BlockConfigType, FEE_CONST) Fee_BlockConfig[FEE_NUMBER_OF_BLOCKS] =
{
    /* FeeBlock_ConfigID */
    {
        FeeConf_FeeBlockConfiguration_FeeBlock_ConfigID, /* FeeBlockNumber */
        4U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean) FALSE, /* FeeImmediateData */
    },
    /* FeeBlock_ConfigID_copy1 */
    {
        FeeConf_FeeBlockConfiguration_FeeBlock_ConfigID_copy1, /* FeeBlockNumber */
        4U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean) FALSE, /* FeeImmediateData */
    },
    /* FeeBlock_DemNonVolatileData */
    {
        FeeConf_FeeBlockConfiguration_FeeBlock_DemNonVolatileData, /* FeeBlockNumber */
        11U, /* FeeBlockSize */
        1U, /* FeeClusterGroup */
        (boolean) FALSE, /* FeeImmediateData */
    },
    /* FeeBlock_DemNonVolatileData_copy1 */
    {
        FeeConf_FeeBlockConfiguration_FeeBlock_DemNonVolatileData_copy1, /* FeeBlockNumber */
        11U, /* FeeBlockSize */
        1U, /* FeeClusterGroup */
        (boolean) FALSE, /* FeeImmediateData */
    },
    /* FeeBlock_DemEventStatusNvRamBlock */
    {
        FeeConf_FeeBlockConfiguration_FeeBlock_DemEventStatusNvRamBlock, /* FeeBlockNumber */
        52U, /* FeeBlockSize */
        1U, /* FeeClusterGroup */
        (boolean) FALSE, /* FeeImmediateData */
    },
    /* FeeBlock_DemEventStatusNvRamBlock_copy1 */
    {
        FeeConf_FeeBlockConfiguration_FeeBlock_DemEventStatusNvRamBlock_copy1, /* FeeBlockNumber */
        52U, /* FeeBlockSize */
        1U, /* FeeClusterGroup */
        (boolean) FALSE, /* FeeImmediateData */
    },
    /* FeeBlock_DemPriEvtMem_0 */
    {
        FeeConf_FeeBlockConfiguration_FeeBlock_DemPriEvtMem_0, /* FeeBlockNumber */
        20U, /* FeeBlockSize */
        1U, /* FeeClusterGroup */
        (boolean) FALSE, /* FeeImmediateData */
    },
    /* FeeBlock_DemPriEvtMem_0_copy1 */
    {
        FeeConf_FeeBlockConfiguration_FeeBlock_DemPriEvtMem_0_copy1, /* FeeBlockNumber */
        20U, /* FeeBlockSize */
        1U, /* FeeClusterGroup */
        (boolean) FALSE, /* FeeImmediateData */
    },
    /* FeeBlock_DemPriEvtMem_1 */
    {
        FeeConf_FeeBlockConfiguration_FeeBlock_DemPriEvtMem_1, /* FeeBlockNumber */
        20U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean) FALSE, /* FeeImmediateData */
    },
    /* FeeBlock_DemPriEvtMem_1_copy1 */
    {
        FeeConf_FeeBlockConfiguration_FeeBlock_DemPriEvtMem_1_copy1, /* FeeBlockNumber */
        20U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean) FALSE, /* FeeImmediateData */
    },
    /* FeeBlock_DemPriEvtMem_2 */
    {
        FeeConf_FeeBlockConfiguration_FeeBlock_DemPriEvtMem_2, /* FeeBlockNumber */
        20U, /* FeeBlockSize */
        1U, /* FeeClusterGroup */
        (boolean) FALSE, /* FeeImmediateData */
    },
    /* FeeBlock_DemPriEvtMem_2_copy1 */
    {
        FeeConf_FeeBlockConfiguration_FeeBlock_DemPriEvtMem_2_copy1, /* FeeBlockNumber */
        20U, /* FeeBlockSize */
        1U, /* FeeClusterGroup */
        (boolean) FALSE, /* FeeImmediateData */
    },
    /* FeeBlock_IntTst_TestBlock1 */
    {
        FeeConf_FeeBlockConfiguration_FeeBlock_IntTst_TestBlock1, /* FeeBlockNumber */
        7U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean) FALSE, /* FeeImmediateData */
    },
    /* FeeBlock_IntTst_TestBlock2 */
    {
        FeeConf_FeeBlockConfiguration_FeeBlock_IntTst_TestBlock2, /* FeeBlockNumber */
        9U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean) FALSE, /* FeeImmediateData */
    },
    /* FeeBlock_IntTst_TestBlock3 */
    {
        FeeConf_FeeBlockConfiguration_FeeBlock_IntTst_TestBlock3, /* FeeBlockNumber */
        2U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean) FALSE, /* FeeImmediateData */
    }
};


/* @violates @ref Fee_cfg_h_REF_2 Identifier exceeds 31 characters */
#define FEE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Fee_cfg_h_REF_1 Repeated include file */
/* @violates @ref Fee_cfg_h_REF_5 #include statement preceded by some code */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @}*/
