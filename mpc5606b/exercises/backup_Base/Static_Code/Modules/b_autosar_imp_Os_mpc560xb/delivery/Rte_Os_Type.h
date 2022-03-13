/**
*    @file        Rte_Os_Type.h
*    @version     4.0.69
*
*    @brief       AUTOSAR OS Rte Os types definition.
*    @details     AUTOSAR Rte Os types definition.
*/
    
/*==================================================================================================
*    Project      : AUTOSAR OS 4.0
*    Patform      : Power Architecture
*    Peripheral   : e200z0/e200z0h
*    Dependencies : none
*    
*    Autosar Version       : 4.0.3
*    Autosar Revision      : ASR_REL_4_0_REV_0003
*    Autosar Conf. Variant : 
*    Software Version      : 4.0.69
*    Build Version         : MPC5600V4_OS_4.0.69_ASR_REL_4_0_REV_0003
*
*    (c) Copyright 2013 Freescale Semiconductor Inc.
*    All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef RTE_OS_TYPE_H
#define RTE_OS_TYPE_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief Parameters that shall be published within the standard types header file and also in the
*        module's description file
*/
#define RTE_OS_TYPE_VENDOR_ID                     43
#define RTE_OS_TYPE_AR_RELEASE_MAJOR_VERSION      4
#define RTE_OS_TYPE_AR_RELEASE_MINOR_VERSION      0
#define RTE_OS_TYPE_AR_RELEASE_REVISION_VERSION   3
#define RTE_OS_TYPE_SW_MAJOR_VERSION              4
#define RTE_OS_TYPE_SW_MINOR_VERSION              0
#define RTE_OS_TYPE_SW_PATCH_VERSION              69

/* Redmine #6453 */
#include "Rte_Type.h"

#ifdef __cplusplus
}
#endif

#endif /* #ifndef RTE_OS_TYPE_H */
