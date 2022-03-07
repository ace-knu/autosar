/**
*   @file    Icu_eMIOS_LLD_CfgEx.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Icu - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup EMIOS_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS
*   Dependencies         : none
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

#ifndef ICU_EMIOS_LLD_CFG_EX_H
#define ICU_EMIOS_LLD_CFG_EX_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_eMIOS_LLD_CfgEx_h_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_eMIOS_LLD_CfgEx_h_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
*@section Icu_eMIOS_LLD_CfgEx_h_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
/* @implements     DICU03800 */

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @violates @ref Icu_eMIOS_LLD_CfgEx_h_2 Identifier clash.
*/
/* @implements     DICU03201, DICU03202, DICU03203, DICU03204, DICU03205, DICU03206, DICU03207 */
#define ICU_EMIOS_LLD_CFGEX_H_VENDOR_ID            43
#define ICU_EMIOS_LLD_CFGEX_H_MODULE_ID            122
/*
* @violates @ref Icu_eMIOS_LLD_CfgEx_h_3 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_LLD_CFGEX_H_AR_RELEASE_MAJOR_VERSION          4
/*
* @violates @ref Icu_eMIOS_LLD_CfgEx_h_2 Identifier clash.
*/
/*
* @violates @ref Icu_eMIOS_LLD_CfgEx_h_3 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_LLD_CFGEX_H_AR_RELEASE_MINOR_VERSION          0
/*
* @violates @ref Icu_eMIOS_LLD_CfgEx_h_2 Identifier clash.
*/
/*
* @violates @ref Icu_eMIOS_LLD_CfgEx_h_3 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_LLD_CFGEX_H_AR_RELEASE_REVISION_VERSION       3
/*
* @violates @ref Icu_eMIOS_LLD_CfgEx_h_3 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_LLD_CFGEX_H_SW_MAJOR_VERSION                  1
/*
* @violates @ref Icu_eMIOS_LLD_CfgEx_h_3 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_LLD_CFGEX_H_SW_MINOR_VERSION                  0
/*
* @violates @ref Icu_eMIOS_LLD_CfgEx_h_3 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_LLD_CFGEX_H_SW_PATCH_VERSION                  1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          Possible dividers for an Emios channel.
*/
/**
* @brief          channel prescaler = 1
*
* @implements     DICU03501
*/
#define ICU_EMIOS_LLD_CH_PRES_1   0
/**
* @brief          channel prescaler = 2
*
* @implements     DICU03502
*/
#define ICU_EMIOS_LLD_CH_PRES_2   1
/**
* @brief          channel prescaler = 3
*
* @implements     DICU03503
*/
#define ICU_EMIOS_LLD_CH_PRES_3   2
/**
* @brief          channel prescaler = 4
*
* @implements     DICU03504
*/
#define ICU_EMIOS_LLD_CH_PRES_4   3

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define ICU_START_SEC_CODE
/*
* @violates @ref Icu_eMIOS_LLD_CfgEx_h_1 precautions to prevent the contents of a header file being
*           included twice
*/
#include "MemMap.h"

/* Check if header file and MemMap.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((ICU_EMIOS_LLD_CFGEX_H_AR_RELEASE_MAJOR_VERSION != MEMMAP_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_EMIOS_LLD_CFGEX_H_AR_RELEASE_MINOR_VERSION != MEMMAP_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu_eMIOS_LLD_CfgEx.h and MemMap.h are different"
#endif
#endif


#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_eMIOS_LLD_CfgEx_h_1 precautions to prevent the contents of a header file being
*           included twice
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*ICU_EMIOS_LLD_CFG_EX_H*/
/** @} */
