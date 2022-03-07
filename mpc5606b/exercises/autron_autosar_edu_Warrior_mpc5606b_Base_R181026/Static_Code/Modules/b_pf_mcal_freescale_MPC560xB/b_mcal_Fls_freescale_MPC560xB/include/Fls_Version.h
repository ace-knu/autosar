/**
*   @file    Fls_Version.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Flash driver version information.
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

#ifndef FLS_VERSION_H 
#define FLS_VERSION_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section fls_version_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @implements     DFLS02068 */
#define FLS_AR_RELEASE_MAJOR_VERSION     4
#define FLS_AR_RELEASE_MINOR_VERSION     0
/*
* @violates @ref fls_version_h_REF_1 The compiler/linker
* shall be checked to ensure that 31 character significance and case sensitivity are supported
* for external identifiers
*/
#define FLS_AR_RELEASE_REVISION_VERSION  3
#define FLS_SW_MAJOR_VERSION             1
#define FLS_SW_MINOR_VERSION             0
#define FLS_SW_PATCH_VERSION             1

#ifdef __cplusplus
}
#endif

#endif /* FLS_VERSION_H */
