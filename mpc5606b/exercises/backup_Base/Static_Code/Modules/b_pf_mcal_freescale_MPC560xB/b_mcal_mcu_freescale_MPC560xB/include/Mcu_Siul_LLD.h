/**
* @file    Mcu_Siul_LLD.h
* @version 1.0.1
*
* @brief   AUTOSAR Mcu - SIUL low level IP driver interface.
* @details API of the SIUL low level IP driver.
*
* @addtogroup Siul
* @{
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

#ifndef MCU_SIUL_LLD_H
#define MCU_SIUL_LLD_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section MCU_SIUL_LLD_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h, 
* Precautions shall be taken in order to prevent the contents of a header file 
* being included twice This is not a violation since all header files are 
* protected against multiple inclusions
*
* @section MCU_SIUL_LLD_H_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
* before '#include' MemMap.h included after each section define in order to set 
* the current memory section
*
* @section MCU_SIUL_LLD_H_REF_3
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys_SIUL.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @file           Mcu_Siul_LLD.h
* @implements     DMCU05083, DMCU05084, DMCU05085, DMCU05086, DMCU05087, DMCU05088,
*                 DMCU05089
*/
#define MCU_SIUL_VENDOR_ID                      43
/*
* @violates @ref MCU_SIUL_LLD_H_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_SIUL_AR_RELEASE_MAJOR_VERSION       4
/*
* @violates @ref MCU_SIUL_LLD_H_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_SIUL_AR_RELEASE_MINOR_VERSION       0
/*
* @violates @ref MCU_SIUL_LLD_H_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_SIUL_AR_RELEASE_REVISION_VERSION    3
#define MCU_SIUL_SW_MAJOR_VERSION               1
#define MCU_SIUL_SW_MINOR_VERSION               0
#define MCU_SIUL_SW_PATCH_VERSION               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys_ECSM.h header file are of the same vendor */
#if (MCU_SIUL_VENDOR_ID != ECSM_REG_VENDOR_ID)
#error "Mcu_Siul_LLD.h and Reg_eSys_ECSM.h have different vendor ids"
#endif
/*
* @implements     DMCU06001
*/
/* Check if current file and Reg_eSys_ECSM header file are of the same Autosar version */
#if ((MCU_SIUL_AR_RELEASE_MAJOR_VERSION   != ECSM_REG_AR_RELEASE_MAJOR_VERSION) || \
    (MCU_SIUL_AR_RELEASE_MINOR_VERSION    != ECSM_REG_AR_RELEASE_MINOR_VERSION) || \
    (MCU_SIUL_AR_RELEASE_REVISION_VERSION != ECSM_REG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcu_Siul_LLD.h and Reg_eSys_ECSM.h are different"
#endif
/* Check if current file and Reg_eSys_ECSM.h header file are of the same Software version */
#if ((MCU_SIUL_SW_MAJOR_VERSION != ECSM_REG_SW_MAJOR_VERSION) || \
     (MCU_SIUL_SW_MINOR_VERSION != ECSM_REG_SW_MINOR_VERSION) || \
     (MCU_SIUL_SW_PATCH_VERSION != ECSM_REG_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcu_Siul_LLD.h and Reg_eSys_ECSM.h are different"
#endif
/* Check if current file and Std_Types configuration header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
   #if ((MCU_SIUL_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
        (MCU_SIUL_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
   #error "AutoSar Version Numbers of Mcu_Siul_LLD.h and Std_Types.h are different"
   #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
/* @violates @ref MCU_SIUL_LLD_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
/*
* @violates @ref MCU_SIUL_LLD_H_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*                            before '#include' MemMap.h
*/
#include "MemMap.h"

#define MCU_STOP_SEC_CODE
/* @violates @ref MCU_SIUL_LLD_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
/*
* @violates @ref MCU_SIUL_LLD_H_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*                            before '#include' MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* MCU_SIUL_LLD_H */
/** @} */
