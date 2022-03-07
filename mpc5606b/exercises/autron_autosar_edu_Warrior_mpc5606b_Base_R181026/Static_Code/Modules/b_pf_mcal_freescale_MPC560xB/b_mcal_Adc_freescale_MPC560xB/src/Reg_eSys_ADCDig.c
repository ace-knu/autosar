/**
*   @file    Reg_eSys_ADCDig.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - module register and macro definitions.
*   @details Adc module registers, and macrodefinitions used to manipulate the module registers.
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
* @section  Reg_eSys_ADCDig_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* There are different kinds of execution code sections.
*
* @section  Reg_eSys_ADCDig_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* "#include". This violation is not fixed since the inclusion of MemMap.h is as per Autosar
* requirement.
*
* @section Reg_eSys_ADCDig_c_REF_3
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character signifiance and case
* sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Reg_eSys_ADCDig_c_REF_4
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
#include "Std_Types.h"
#include "Reg_eSys.h"
#include "Adc_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @file           Reg_eSys_ADCDig.c
*/
#define ADC_VENDOR_ID_REG_C                      (43)
/*
* @violates @ref Reg_eSys_ADCDig_c_REF_3 The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers
*/
/* @violates @ref Reg_eSys_ADCDig_c_REF_4 Identifier exceeds 31 characters */
#define ADC_AR_RELEASE_MAJOR_VERSION_REG_C       (4)
/*
* @violates @ref Reg_eSys_ADCDig_c_REF_3 The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers
*/
/* @violates @ref Reg_eSys_ADCDig_c_REF_4 Identifier exceeds 31 characters */
#define ADC_AR_RELEASE_MINOR_VERSION_REG_C       (0)
/*
* @violates @ref Reg_eSys_ADCDig_c_REF_3 The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers
*/
/* @violates @ref Reg_eSys_ADCDig_c_REF_4 Identifier exceeds 31 characters */
#define ADC_AR_RELEASE_REVISION_VERSION_REG_C    (3)
#define ADC_SW_MAJOR_VERSION_REG_C               (1)
#define ADC_SW_MINOR_VERSION_REG_C               (0)
#define ADC_SW_PATCH_VERSION_REG_C               (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

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
#define ADC_START_SEC_CONST_32
/* @violates @ref Reg_eSys_ADCDig_c_REF_1 Repeated include file */
#include "MemMap.h"

/**
* @brief base address array for ADCDig
*/
#ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
CONST(uint32, ADC_CONST) ADCDIG_BASE_ADDR[] = {
#ifdef ADC0_BASEADDR
  ADC0_BASEADDR
#endif
#ifdef ADC1_BASEADDR
  ,ADC1_BASEADDR
#endif
#ifdef ADC2_BASEADDR
  ,ADC2_BASEADDR
#endif
#ifdef ADC3_BASEADDR
  ,ADC3_BASEADDR
#endif
};
#else /* Bolero 256k-128k */
CONST(uint32, ADC_VAR) ADCDIG_BASE_ADDR[] = {
 #ifdef ADC1_BASEADDR
   ADC1_BASEADDR
 #endif
};
#endif

#define ADC_STOP_SEC_CONST_32
/*
* @violates @ref Reg_eSys_ADCDig_c_REF_2 Only preprocessor statements and comments before "#include"
* @violates @ref Reg_eSys_ADCDig_c_REF_1 Repeated include file
*/
#include "MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
