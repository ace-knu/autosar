/**
*   @file    Fee_Version.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Fee - Version Information.
*   @details Flash EEPROM emulation driver version information.
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

#ifndef FEE_VERSION_H 
#define FEE_VERSION_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Fee_Version_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* Define name is required by the AUTOSAR specifications although it exceeds the
* max length of 31 characters.
*
*/


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_AR_RELEASE_MAJOR_VERSION     4
#define FEE_AR_RELEASE_MINOR_VERSION     0
/* @violates @ref Fee_Version_h_REF_1 Identifier clash */
#define FEE_AR_RELEASE_REVISION_VERSION  3
#define FEE_SW_MAJOR_VERSION             1
#define FEE_SW_MINOR_VERSION             0
#define FEE_SW_PATCH_VERSION             1

#ifdef __cplusplus
}
#endif

#endif /* FEE_VERSION_H */

/** @} */

