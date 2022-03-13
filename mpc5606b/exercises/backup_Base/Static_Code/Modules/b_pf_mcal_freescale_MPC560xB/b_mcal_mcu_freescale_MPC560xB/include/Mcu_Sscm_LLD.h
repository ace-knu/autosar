/**
*   @file    Mcu_SSCM.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Function prototypes.
*   @details Interface available for IPW layer only.
*
*   @addtogroup MCU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : MC
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF13_ASR_REL_4_0_REV_0003_20170719
*
*   (c) Copyright 2006-2016 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/


#ifndef MCU_SSCM_H
#define MCU_SSCM_H


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_SSCM_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_SSCM_h_REF_2
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_SSCM_Types.h"
#include "Reg_eSys_SSCM.h"


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcu_SSCM.h
*/
#define MCU_SSCM_LLD_VENDOR_ID                          43
/*
* @violates @ref Mcu_SSCM_h_REF_2 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_SSCM_LLD_AR_RELEASE_MAJOR_VERSION           4
/*
* @violates @ref Mcu_SSCM_h_REF_2 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_SSCM_LLD_AR_RELEASE_MINOR_VERSION           0
/*
* @violates @ref Mcu_SSCM_h_REF_2 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_SSCM_LLD_AR_RELEASE_REVISION_VERSION        3
#define MCU_SSCM_LLD_SW_MAJOR_VERSION                   1
#define MCU_SSCM_LLD_SW_MINOR_VERSION                   0
#define MCU_SSCM_LLD_SW_PATCH_VERSION                   1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


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
#define MCU_START_SEC_CODE
/*
* @violates @ref Mcu_SSCM_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

#if (MCU_SSCM_ERROR_CONFIG == STD_ON)
FUNC (void, MCU_CODE) Mcu_Sscm_Init(VAR(uint16, AUTOMATIC) mcu_sscm_config_val);
#endif /* MCU_SSCM_ERROR_CONFIG == STD_ON */

#if (MCU_SSCM_GET_STATUS_API == STD_ON)
FUNC (Mcu_SSCM_ReturnType, MCU_CODE) Mcu_Sscm_GetStatus(VAR( void, AUTOMATIC));
#endif /* MCU_SSCM_GET_STATUS_API == STD_ON */

#if (MCU_SSCM_GET_MEMCONFIG_API == STD_ON)
FUNC (Mcu_SSCM_ReturnType, MCU_CODE) Mcu_Sscm_GetMemConfig(VAR( void, AUTOMATIC));
#endif /* MCU_SSCM_GET_MEMCONFIG_API == STD_ON */

#if (MCU_SSCM_GET_UOPS_API == STD_ON)
FUNC (Mcu_SSCM_ReturnType, MCU_CODE) Mcu_Sscm_GetUops(VAR( void, AUTOMATIC));
#endif /* MCU_SSCM_GET_UOPS_API == STD_ON */

#define MCU_STOP_SEC_CODE
/*
* @violates @ref Mcu_SSCM_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* MCU_SSCM_H */

/** @} */
