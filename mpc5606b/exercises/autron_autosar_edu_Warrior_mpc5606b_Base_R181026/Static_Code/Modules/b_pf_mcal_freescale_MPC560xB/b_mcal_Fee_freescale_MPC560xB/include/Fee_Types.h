/**
*   @file    Fee_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Fee - Exported types.
*   @details Definitions of all flash EEPROM emulation driver exported types.
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
#ifndef FEE_TYPES_H
#define FEE_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Fee_types_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file.
* The headers files are protected against multiple inclusions.
*
* @section Fee_types_h_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
/* @violates @ref Fee_types_h_REF_1 Repeated include file */
#include "Std_Types.h"
#include "MemIf_Types.h"
#include "Fls.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_TYPES_VENDOR_ID                    43U
#define FEE_TYPES_MODULE_ID                    21U
/* @violates @ref Fee_types_h_REF_2 Identifier exceeds 31 characters */
#define FEE_TYPES_AR_RELEASE_MAJOR_VERSION     4
/* @violates @ref Fee_types_h_REF_2 Identifier exceeds 31 characters */
#define FEE_TYPES_AR_RELEASE_MINOR_VERSION     0
/* @violates @ref Fee_types_h_REF_2 Identifier exceeds 31 characters */
#define FEE_TYPES_AR_RELEASE_REVISION_VERSION  3
#define FEE_TYPES_SW_MAJOR_VERSION             1
#define FEE_TYPES_SW_MINOR_VERSION             0
#define FEE_TYPES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Std_Types header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((FEE_TYPES_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_TYPES_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Fee_Types.h and Std_Types.h are different"
#endif
/* Check if current file and Fls header file are of the same version */
#if ((FEE_TYPES_AR_RELEASE_MAJOR_VERSION != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_TYPES_AR_RELEASE_MINOR_VERSION != FLS_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Fee_Types.h and Fls.h are different"
#endif
#endif

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** 
* @brief        Fee cluster group run-time Information 
* @api 
* @implements   DFEE03085 
*/ 
typedef struct 
{ 
    Fls_AddressType  clusterTotalSpace;   /**< @brief Total space in the selected cluster group */ 
    Fls_AddressType  clusterFreeSpace;    /**< @brief Free space in the selected cluster group */
    uint8            blockHeaderOverhead; /**< @brief Block Overhead (header valid and inval flag)*/
    uint8            virtualPageSize;     /**< @brief Fee Virtual Page Size */
    uint32           numberOfSwap;        /**< @brief Number of cluster swap performed in the 
                                                      selected cluster group */
} Fee_ClusterGroupRuntimeInfoType; 

/** 
* @brief        Fee block configuration structure
* @api
* @implements   DFEE03003
*/
typedef struct 
{
    uint16 blockNumber;          /**< @brief Fee block number */     
    uint16 blockSize;            /**< @brief Size of Fee block in bytes */       
    uint8 clrGrp;                /**< @brief  Index of cluster group the Fee 
                                      block belongs to */          
    boolean immediateData;       /**< @brief TRUE if immediate data block */  
} Fee_BlockConfigType;

/**
* @brief Fee cluster configuration structure
* @api
* @implements DFEE03004
*/
typedef struct 
{
    Fls_AddressType startAddr;   /**< @brief Address of Fee cluster in flash */ 
    Fls_LengthType length;       /**< @brief Size of Fee cluster in bytes */      
} Fee_ClusterType;

/**
* @brief Fee cluster group configuration structure
* @api
* @implements DFEE03005
*/
typedef struct 
{
    CONSTP2CONST( Fee_ClusterType, FEE_CONST, FEE_APPL_CONST ) clrPtr; 
                                 /** < @brief Pointer to array of Fee cluster 
                                       configurations */ 
    uint32 clrCount;             /**< @brief Number of clusters in cluster group */ 
} Fee_ClusterGroupType;

#ifdef __cplusplus
}
#endif

#endif /* FEE_TYPES_H */

/** @}*/
