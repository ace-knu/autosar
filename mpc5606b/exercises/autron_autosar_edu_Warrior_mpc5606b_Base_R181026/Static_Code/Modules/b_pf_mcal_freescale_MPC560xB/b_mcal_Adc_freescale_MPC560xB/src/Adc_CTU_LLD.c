/**
*   @file    Adc_CTU_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - low level driver source file.
*   @details This is the low level driver source file, implemented for the Ctu hardware IP.
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
* @section Adc_CTU_LLD_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
* 
* @section Adc_CTU_LLD_c_REF_2
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
/* @violates @ref Adc_CTU_LLD_c_REF_1 Repeated include file */
#include "Adc_CTU_LLD.h"
/* @violates @ref Adc_CTU_LLD_c_REF_1 Repeated include file */
#include "Adc_CTU_ipversion.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Adc_CTU_LLD.c
*/
#define CTU_LLD_VENDOR_ID_C                    (43)
/* @violates @ref Adc_CTU_LLD_c_REF_2 Identifier exceeds 31 characters */
#define CTU_LLD_AR_RELEASE_MAJOR_VERSION_C     (4)
/* @violates @ref Adc_CTU_LLD_c_REF_2 Identifier exceeds 31 characters */
#define CTU_LLD_AR_RELEASE_MINOR_VERSION_C     (0)
/* @violates @ref Adc_CTU_LLD_c_REF_2 Identifier exceeds 31 characters */
#define CTU_LLD_AR_RELEASE_REVISION_VERSION_C  (3)
#define CTU_LLD_SW_MAJOR_VERSION_C             (1)
#define CTU_LLD_SW_MINOR_VERSION_C             (0)
#define CTU_LLD_SW_PATCH_VERSION_C             (1)


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CTU header file are from the same vendor */
#if (CTU_LLD_VENDOR_ID_C != CTU_VENDOR_ID)
    #error "Adc_CTU_LLD.c and Adc_CTU_LLD.h have different vendor ids"
#endif

/* Check if source file and CTUV2 header file are of the same Autosar version */
#if ((CTU_LLD_AR_RELEASE_MAJOR_VERSION_C != CTU_AR_RELEASE_MAJOR_VERSION) || \
     (CTU_LLD_AR_RELEASE_MINOR_VERSION_C != CTU_AR_RELEASE_MINOR_VERSION) || \
     (CTU_LLD_AR_RELEASE_REVISION_VERSION_C != CTU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Adc_CTU_LLD.c and Adc_CTU_LLD.h are different"
#endif

/* Check if source file and CTU header file are of the same Software version */
#if ((CTU_LLD_SW_MAJOR_VERSION_C != CTU_SW_MAJOR_VERSION) || \
     (CTU_LLD_SW_MINOR_VERSION_C != CTU_SW_MINOR_VERSION) || \
     (CTU_LLD_SW_PATCH_VERSION_C != CTU_SW_PATCH_VERSION))
    #error "Software Version Numbers of Adc_CTU_LLD.c and Adc_CTU_LLD.h are different"
#endif

/* Check if source file and CTU register header file are from the same vendor */
#if (CTU_LLD_VENDOR_ID_C != CTU_REG_VENDOR_ID)
    #error "Adc_CTU_LLD.c and Reg_eSys_CTU.h have different vendor ids"
#endif

/* Check if source file and CTU register header file are of the same Autosar version */
#if ((CTU_LLD_AR_RELEASE_MAJOR_VERSION_C != CTU_REG_AR_RELEASE_MAJOR_VERSION) || \
     (CTU_LLD_AR_RELEASE_MINOR_VERSION_C != CTU_REG_AR_RELEASE_MINOR_VERSION) || \
     (CTU_LLD_AR_RELEASE_REVISION_VERSION_C != CTU_REG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Adc_CTU_LLD.c and Reg_eSys_CTU.h are different"
#endif

/* Check if source file and CTU register header file are of the same Software version */
#if ((CTU_LLD_SW_MAJOR_VERSION_C != CTU_REG_SW_MAJOR_VERSION) || \
     (CTU_LLD_SW_MINOR_VERSION_C != CTU_REG_SW_MINOR_VERSION) || \
     (CTU_LLD_SW_PATCH_VERSION_C != CTU_REG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Adc_CTU_LLD.c and Reg_eSys_CTU.h are different"
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
/* @violates @ref Adc_CTU_LLD_c_REF_2 Identifier exceeds 31 characters */
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Adc_CTU_LLD_c_REF_1 Repeated include file MemMap.h */
#include "MemMap.h"


/* @violates @ref Adc_CTU_LLD_c_REF_2 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Adc_CTU_LLD_c_REF_1 Repeated include file MemMap.h */
#include "MemMap.h"


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#define ADC_START_SEC_CODE
/* @violates @ref Adc_CTU_LLD_c_REF_1 Repeated include file */
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define ADC_STOP_SEC_CODE
/* @violates @ref Adc_CTU_LLD_c_REF_1 Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
