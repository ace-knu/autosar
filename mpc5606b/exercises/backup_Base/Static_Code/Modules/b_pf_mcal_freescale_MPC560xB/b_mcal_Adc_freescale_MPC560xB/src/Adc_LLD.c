/**
*   @file    Adc_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - Separation source layer of high-low level drivers.
*   @details Source interface between common and low level driver.
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_LLD_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* There are different kinds of execution code sections.
*
* @section Adc_LLD_c_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not more than 31 characters
* Violation is needed because of Autosar restrictions for naming File version check macros.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @implements     DADC00006 */
#include "Adc.h"
#include "Adc_LLD.h"
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/* @violates @ref Adc_LLD_c_REF_1 Repeated include file */
#include "Dem.h"
#endif
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @implements     DADC04004 */
#define ADC_LLD_C_VENDOR_ID                    (43)
/* @violates @ref Adc_LLD_c_REF_2 Identifier exceeds 31 characters */
#define ADC_LLD_C_AR_RELEASE_MAJOR_VERSION     (4)
/* @violates @ref Adc_LLD_c_REF_2 Identifier exceeds 31 characters */
#define ADC_LLD_C_AR_RELEASE_MINOR_VERSION     (0)
/* @violates @ref Adc_LLD_c_REF_2 Identifier exceeds 31 characters */
#define ADC_LLD_C_AR_RELEASE_REVISION_VERSION  (3)
#define ADC_LLD_C_SW_MAJOR_VERSION             (1)
#define ADC_LLD_C_SW_MINOR_VERSION             (0)
#define ADC_LLD_C_SW_PATCH_VERSION             (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* @implements     DADC06006 */

/* Check if source file and ADC header file are of the same vendor */
#if (ADC_LLD_C_VENDOR_ID != ADC_VENDOR_ID)
    #error "Adc_LLD.c and Adc.h have different vendor ids"
#endif

/* Check if source file and ADC header file are of the same Autosar version */
#if ((ADC_LLD_C_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_LLD_C_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION) || \
     (ADC_LLD_C_AR_RELEASE_REVISION_VERSION != ADC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Adc_LLD.c and Adc.h are different"
#endif

/* Check if source file and ADC header file are of the same Software version */
#if ((ADC_LLD_C_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION) || \
     (ADC_LLD_C_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION) || \
     (ADC_LLD_C_SW_PATCH_VERSION != ADC_SW_PATCH_VERSION))
    #error "Software Version Numbers of Adc_LLD.c and Adc.h are different"
#endif

/* Check if source file and ADC LLD header file are from the same vendor */
#if (ADC_LLD_C_VENDOR_ID != ADC_LLD_H_VENDOR_ID)
    #error "Adc_LLD.c and Adc_LLD.h have different vendor ids"
#endif

/* Check if source file and ADC LLD header file are of the same Autosar version */
#if ((ADC_LLD_C_AR_RELEASE_MAJOR_VERSION != ADC_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_LLD_C_AR_RELEASE_MINOR_VERSION != ADC_LLD_H_AR_RELEASE_MINOR_VERSION) || \
     (ADC_LLD_C_AR_RELEASE_REVISION_VERSION != ADC_LLD_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Adc_LLD.c and Adc_LLD.h are different"
#endif

/* Check if source file and ADC LLD header file are of the same Software version */
#if ((ADC_LLD_C_SW_MAJOR_VERSION != ADC_LLD_H_SW_MAJOR_VERSION) || \
     (ADC_LLD_C_SW_MINOR_VERSION != ADC_LLD_H_SW_MINOR_VERSION) || \
     (ADC_LLD_C_SW_PATCH_VERSION != ADC_LLD_H_SW_PATCH_VERSION))
  #error "Software Version Numbers of Adc_LLD.c and Adc_LLD.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
 /* Check if source file and Dem header file are of the same version */
 #if ((ADC_LLD_C_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_LLD_C_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION))
 #error "AutoSar Version Numbers of Adc_LLD.c and Dem.h are different"
 #endif
  #endif

 /* Check if source file and DET header file are of the same version */
 #if (ADC_DEV_ERROR_DETECT == STD_ON)
    #if ((ADC_LLD_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
         (ADC_LLD_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Adc_LLD.c and Det.h are different"
    #endif
 #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/* @violates @ref Adc_LLD_c_REF_2 Identifier exceeds 31 characters */
#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Adc_LLD_c_REF_1 Repeated include file MemMap.h
*/
#include "MemMap.h"

/* @violates @ref Adc_LLD_c_REF_2 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Adc_LLD_c_REF_1 Repeated include file MemMap.h
*/
#include "MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define ADC_START_SEC_CODE
/**
* @violates @ref Adc_LLD_c_REF_1 Repeated include file MemMap.h
*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define ADC_STOP_SEC_CODE
/**
* @violates @ref Adc_LLD_c_REF_1 Repeated include file MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
