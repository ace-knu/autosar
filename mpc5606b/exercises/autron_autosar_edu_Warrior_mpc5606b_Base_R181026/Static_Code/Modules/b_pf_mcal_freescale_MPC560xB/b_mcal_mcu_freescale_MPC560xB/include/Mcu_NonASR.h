/**
*   @file     Mcu_NonASR.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - High level header of MCU driver.
*   @details This file contains declarations of the functions not defined by AutoSAR.
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
#ifndef MCU_NONASR_H
#define MCU_NONASR_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_NonASR_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_NonASR_H_REF_2
* Violates MISRA 2004 Required Rule 1.4, Identifier clash. Define name is required by the AUTOSAR 
* specifications although it exceeds the max length of 31 characters
*
* @section Mcu_NonASR_H_REF_3
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
/**
* @file           Mcu_NonASR.h
*/
/* @violates @ref Mcu_NonASR_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files */
#include "Std_Types.h"
/* @violates @ref Mcu_NonASR_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files */
#include "Mcu_Cfg.h"
#ifdef MCU_SSCM_GET_STATUS_API
#if ((MCU_SSCM_GET_STATUS_API == STD_ON) || (MCU_SSCM_GET_MEMCONFIG_API == STD_ON) || \
     (MCU_SSCM_GET_UOPS_API == STD_ON))
/* @violates @ref Mcu_NonASR_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files */
#include "Mcu_SSCM_Types.h"
#endif
#endif
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_VENDOR_ID_NONASR                    43
/*
* @violates @ref Mcu_NonASR_H_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_AR_RELEASE_MAJOR_VERSION_NONASR     4
/*
* @violates @ref Mcu_NonASR_H_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_AR_RELEASE_MINOR_VERSION_NONASR     0
/* @violates @ref Mcu_NonASR_H_REF_2 MISRA 2004 Required Rule 1.4, Identifier clash */
/*
* @violates @ref Mcu_NonASR_H_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_AR_RELEASE_REVISION_VERSION_NONASR  3
#define MCU_SW_MAJOR_VERSION_NONASR             1
#define MCU_SW_MINOR_VERSION_NONASR             0
#define MCU_SW_PATCH_VERSION_NONASR             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if source file and Std_Types header file are of the same AutoSar version */
 #if ((MCU_AR_RELEASE_MAJOR_VERSION_NONASR != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_AR_RELEASE_MINOR_VERSION_NONASR != STD_TYPES_AR_RELEASE_MINOR_VERSION))
 #error "AutoSar Version Numbers of Mcu_NonASR.h and Std_Types.h are different"
 #endif
#endif

/* Check if source file and MCU configuration header file are of the same vendor */
#if (MCU_VENDOR_ID_NONASR != MCU_VENDOR_ID_CFG)
#error "Mcu_NonASR.h and Mcu_Cfg.h have different vendor ids"
#endif

/* Check if source file and MCU configuration header file are of the same Autosar version */
#if ((MCU_AR_RELEASE_MAJOR_VERSION_NONASR != MCU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MCU_AR_RELEASE_MINOR_VERSION_NONASR != MCU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MCU_AR_RELEASE_REVISION_VERSION_NONASR != MCU_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Mcu_NonASR.h and Mcu_Cfg.h are different"
#endif

/* Check if source file and MCU configuration header file are of the same software version */
#if ((MCU_SW_MAJOR_VERSION_NONASR != MCU_SW_MAJOR_VERSION_CFG) || \
     (MCU_SW_MINOR_VERSION_NONASR != MCU_SW_MINOR_VERSION_CFG) || \
     (MCU_SW_PATCH_VERSION_NONASR != MCU_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Mcu_NonASR.h and Mcu_Cfg.h are different"
#endif
#ifdef MCU_SSCM_GET_STATUS_API
#if ((MCU_SSCM_GET_STATUS_API == STD_ON) || (MCU_SSCM_GET_MEMCONFIG_API == STD_ON) || \
     (MCU_SSCM_GET_UOPS_API == STD_ON))
/* Check if source file and MCU configuration header file are of the same vendor */
#if (MCU_VENDOR_ID_NONASR != MCU_SSCM_TYPESEX_VENDOR_ID)
#error "Mcu_NonASR.h and Mcu_SSCM_Types.h have different vendor ids"
#endif

/* Check if source file and MCU configuration header file are of the same Autosar version */
#if ((MCU_AR_RELEASE_MAJOR_VERSION_NONASR != MCU_SSCM_TYPESEX_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_AR_RELEASE_MINOR_VERSION_NONASR != MCU_SSCM_TYPESEX_AR_RELEASE_MINOR_VERSION) || \
     (MCU_AR_RELEASE_REVISION_VERSION_NONASR != MCU_SSCM_TYPESEX_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcu_NonASR.h and Mcu_SSCM_Types.h are different"
#endif

/* Check if source file and MCU configuration header file are of the same software version */
#if ((MCU_SW_MAJOR_VERSION_NONASR != MCU_SSCM_TYPESEX_SW_MAJOR_VERSION) || \
     (MCU_SW_MINOR_VERSION_NONASR != MCU_SSCM_TYPESEX_SW_MINOR_VERSION) || \
     (MCU_SW_PATCH_VERSION_NONASR != MCU_SSCM_TYPESEX_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcu_NonASR.h and Mcu_SSCM_Types.h are different"
#endif     
#endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define MCU_START_SEC_CODE
/*
* @violates @ref Mcu_NonASR_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

#if (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON) || defined(__DOXYGEN__)

/**
 * @brief   eMios Global Prescaler Enable.
 * @details This function enable/disable the GPREN bit of the EMIOSMCR register of an 
 *          addressed eMIOS instance. 
 * @pre     Function requires an execution of @p Mcu_Init() before it can be 
 *          used, otherwise it reports error to @p DET.
 * 
 * @param[in] eMios_module   MCU_EMIOS_MODULE_0 --> Select eMios 0 
 *                           MCU_EMIOS_MODULE_1 --> Select eMios 1
 *
 * @param[in] value          MCU_EMIOS_GPREN_BIT_ENABLE   --> Global Prescaler Enabled
 *                           MCU_EMIOS_GPREN_BIT_DISABLE  --> Global Prescaler Disabled (no clock)
 *
 * @return                   void
 *
 * @implements      DMCU06051             
 *
 * @api
 *
 */
extern FUNC(void, MCU_CODE) Mcu_eMios_Configure_GPREN (VAR (uint8, AUTOMATIC) eMios_module, VAR (uint8, AUTOMATIC) value);

#endif /* #if MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON */

#ifdef MCU_CONFIGURE_CLK_OUT
    #if (MCU_CONFIGURE_CLK_OUT==STD_OFF)
extern FUNC(void, MCU_CODE) Mcu_Enable_ClockOutput (VAR (Mcu_ClockType, AUTOMATIC) ClockSetting);
extern FUNC(void, MCU_CODE) Mcu_Disable_ClockOutput (void);
   #endif /* MCU_CONFIGURE_CLK_OUT==STD_OFF */
#endif /* MCU_CONFIGURE_CLK_OUT */

#if (MCU_GET_DEVICE_INFO_API == STD_ON)
extern FUNC (void, MCU_CODE) Mcu_GetDeviceInfo (P2VAR(Mcu_DeviceInfoType, AUTOMATIC, \
         MCU_APPL_DATA) deviceinfo);
#endif /* MCU_GET_DEVICE_INFO_API */

#ifdef MCU_DISABLE_CMU
extern FUNC (void, MCU_CODE) Mcu_Disable_CMU(VAR (uint8, AUTOMATIC) cmuIndex);
#endif   /* MCU_DISABLE_CMU */

#ifdef MCU_SSCM_GET_STATUS_API

#if (MCU_SSCM_GET_STATUS_API == STD_ON)
extern FUNC (Mcu_SSCM_ReturnType, MCU_CODE) Mcu_SscmGetStatus(VAR( void, AUTOMATIC));
#endif /* MCU_SSCM_GET_STATUS_API == STD_ON */

#if (MCU_SSCM_GET_MEMCONFIG_API == STD_ON)
extern FUNC(Mcu_SSCM_ReturnType, MCU_CODE) Mcu_SscmGetMemConfig(VAR( void, AUTOMATIC));
#endif /* MCU_SSCM_GET_MEMCONFIG_API == STD_ON */

#if (MCU_SSCM_GET_UOPS_API == STD_ON)
extern FUNC (Mcu_SSCM_ReturnType, MCU_CODE) Mcu_SscmGetUops(VAR( void, AUTOMATIC));
#endif /* MCU_SSCM_GET_UOPS_API == STD_ON */

#endif

#define MCU_STOP_SEC_CODE
/*
* @violates @ref Mcu_NonASR_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* MCU_NONASR_H */

/** @} */
