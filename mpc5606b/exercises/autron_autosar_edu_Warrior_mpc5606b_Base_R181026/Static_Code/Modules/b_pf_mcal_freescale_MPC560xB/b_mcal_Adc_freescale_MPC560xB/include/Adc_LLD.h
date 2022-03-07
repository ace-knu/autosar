/**
*   @file    Adc_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - Separation header layer of high-low level drivers.
*   @details Header interface between common and low level driver.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : ADCDIG
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

#ifndef ADC_LLD_H
#define ADC_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_LLD_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro. This violation is due to 
* function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Adc_LLD_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section Adc_LLD_h_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not more than 31 characters
* Violation is needed because of Autosar restrictions for naming File version check macros.
*
* @section Adc_LLD_h_REF_4
* Violates MISRA 2004 Required Rule 19.4, Permitted use of macros
* This violation is needed to provide a commonly available HLD API for all HW platforms.
* HLD APIs are translated into specific LLD API using such macro substitutions.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @implements     DADC00005 */
#include "Adc_ADCDig_LLD.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Adc_LLD.h
* @implements     DADC04001
*/
#define ADC_LLD_H_VENDOR_ID                       (43)
/* @violates @ref Adc_LLD_h_REF_3 Identifier exceeds 31 characters */
#define ADC_LLD_H_AR_RELEASE_MAJOR_VERSION        (4)
/* @violates @ref Adc_LLD_h_REF_3 Identifier exceeds 31 characters */
#define ADC_LLD_H_AR_RELEASE_MINOR_VERSION        (0)
/* @violates @ref Adc_LLD_h_REF_3 Identifier exceeds 31 characters */
#define ADC_LLD_H_AR_RELEASE_REVISION_VERSION     (3)
#define ADC_LLD_H_SW_MAJOR_VERSION                (1)
#define ADC_LLD_H_SW_MINOR_VERSION                (0)
#define ADC_LLD_H_SW_PATCH_VERSION                (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* @implements     DADC06005 */
/* Check if source file and Adc_ADCDig_LLD header file are of the same vendor */
#if (ADC_LLD_H_VENDOR_ID != ADC_VENDOR_ID_DIG_LLD)
    #error "Adc_LLD.c and Adc_Adc_ADCDig_LLD.h have different vendor ids"
#endif

/* Check if source file and Adc_ADCDig_LLD header file are of the same Autosar version */
    #if ((ADC_LLD_H_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION_DIG_LLD) || \
         (ADC_LLD_H_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION_DIG_LLD) || \
         (ADC_LLD_H_AR_RELEASE_REVISION_VERSION != ADC_AR_RELEASE_REVISION_VERSION_DIG_LLD))
    #error "AutoSar Version Numbers of Adc_LLD.h and Adc_ADCDig_LLD.h are different"
#endif

/* Check if source file and ADC Adc_ADCDig_LLD header file are of the same software version */
#if ((ADC_LLD_H_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION_DIG_LLD) || \
     (ADC_LLD_H_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION_DIG_LLD) || \
     (ADC_LLD_H_SW_PATCH_VERSION != ADC_SW_PATCH_VERSION_DIG_LLD))
#error "Software Version Numbers of Adc_LLD.h and Adc_ADCDig_LLD.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          Access to teh channel index of a group.
* @details        Helper macro to ease access to the channel index of a group.
*
* @implements     DADC04002
*
* @violates @ref Adc_LLD_h_REF_1 Use of function like macro.
*/
/* @violates @ref Adc_LLD_h_REF_1 Use of function like macro. */
#define Adc_GroupChannelIndex(group,channel)  (Adc_Cfg_Ptr->Groups[(group)].Assignment[(channel)])


/**
* @brief          Functions mapping.
* @details        Middle layer versus Low layer functions mapping
*
* @implements     DADC04003
*
*/
/* @violates @ref Adc_LLD_h_REF_4 Permitted use of macros */
#define Adc_LLD_Init                   ADCDig_LLD_Init
/* @violates @ref Adc_LLD_h_REF_4 Permitted use of macros */
#define Adc_LLD_GetStreamLastPointer   ADCDig_LLD_GetStreamLastPointer
/* @violates @ref Adc_LLD_h_REF_4 Permitted use of macros */
#define Adc_LLD_StartNormalConversion  ADCDig_LLD_StartNormalConversion

#if (ADC_DEINIT_API == STD_ON)
/* @violates @ref Adc_LLD_h_REF_4 Permitted use of macros */
#define Adc_LLD_DeInit                 ADCDig_LLD_DeInit
#endif /* (ADC_DEINIT_API == STD_ON) */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/* @violates @ref Adc_LLD_h_REF_4 Permitted use of macros */
#define Adc_LLD_StartGroupConversion   ADCDig_LLD_StartGroupConversion
/* @violates @ref Adc_LLD_h_REF_4 Permitted use of macros */
#define Adc_LLD_StopGroupConversion    ADCDig_LLD_StopGroupConversion
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_HW_TRIGGER_API == STD_ON)
/* @violates @ref Adc_LLD_h_REF_4 Permitted use of macros */
#define Adc_LLD_EnableHardwareTrigger  ADCDig_LLD_EnableHardwareTrigger
/* @violates @ref Adc_LLD_h_REF_4 Permitted use of macros */
#define Adc_LLD_DisableHardwareTrigger ADCDig_LLD_DisableHardwareTrigger
#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
/* @violates @ref Adc_LLD_h_REF_4 Permitted use of macros */
#define Adc_LLD_EnableCtuTrigger        ADCDig_LLD_EnableCtuTrigger
/* @violates @ref Adc_LLD_h_REF_4 Permitted use of macros */
#define Adc_LLD_DisableCtuTrigger       ADCDig_LLD_DisableCtuTrigger
/* @violates @ref Adc_LLD_h_REF_4 Permitted use of macros */
#define Adc_LLD_HwResultReadGroup       ADCDig_LLD_HwResultReadGroup
#endif /* (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#if (ADC_READ_GROUP_API == STD_ON)
  /* @violates @ref Adc_LLD_h_REF_4 Permitted use of macros */
  #define Adc_LLD_ReadGroup            ADCDig_LLD_ReadGroup
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#ifdef ADC_DMA_SUPPORTED
/* @violates @ref Adc_LLD_h_REF_4 Permitted use of macros */
#define Adc_StartDMAOperation          ADCDig_StartDMAOperation
#endif /* ADC_DMA_SUPPORTED */

#if (ADC_SET_MODE_API == STD_ON)
/* @violates @ref Adc_LLD_h_REF_4 Permitted use of macros */
#define Adc_LLD_SetMode                ADCDig_LLD_SetMode
#endif /* (ADC_SET_MODE_API == STD_ON) */

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
/* @violates @ref Adc_LLD_h_REF_4 Permitted use of macros */
#define Adc_LLD_SetClockMode           ADCDig_LLD_SetClockMode
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */

#if (ADC_GET_INJECTED_CONVERSION_STATUS_API == STD_ON)
#if (ADC_HW_TRIGGER_API == STD_ON)
/* @violates @ref Adc_LLD_h_REF_4 Permitted use of macros */
/* @violates @ref Adc_LLD_h_REF_3 Identifier exceeds 31 characters */
#define Adc_LLD_GetInjectedConversionStatus ADCDig_LLD_GetInjectedConversionStatus
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#endif /* (ADC_GET_INJECTED_CONVERSION_STATUS_API == STD_ON) */

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
/* @violates @ref Adc_LLD_h_REF_4 Permitted use of macros */
  #define Adc_LLD_ConfigureThreshold ADCDig_LLD_ConfigureThreshold
#endif
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#ifndef ADC_PRECOMPILE_SUPPORT
/* @violates @ref Adc_LLD_h_REF_3 Identifier exceeds 31 characters */
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Adc_LLD_h_REF_2 Repeated include file MemMap.h
*/
#include "MemMap.h"


/* @violates @ref Adc_LLD_h_REF_3 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Adc_LLD_h_REF_2 Repeated include file MemMap.h
*/
#include "MemMap.h"
#endif

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define ADC_START_SEC_CODE
/**
* @violates @ref Adc_LLD_h_REF_2 Repeated include file MemMap.h
*/
#include "MemMap.h"


#define ADC_STOP_SEC_CODE
/**
* @violates @ref Adc_LLD_h_REF_2 Repeated include file MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ADC_LLD_H */

/** @} */
