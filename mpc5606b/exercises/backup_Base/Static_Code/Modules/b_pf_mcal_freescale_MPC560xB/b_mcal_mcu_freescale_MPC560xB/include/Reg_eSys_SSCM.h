/**
*   @file    Reg_eSys_SSCM.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Macros for memory access.
*   @details Macros/Defines used for registry and memory read/write.
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


#ifndef REG_ESYS_SSCM_H
#define REG_ESYS_SSCM_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section REG_ESYS_SSCM_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section REG_ESYS_SSCM_H_REF_2
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
/* @violates @ref REG_ESYS_SSCM_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files */
#include "Reg_eSys.h"


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_SSCM.h
*/
#define REG_ESYS_SSCM_VENDOR_ID                         43
/*
* @violates @ref REG_ESYS_SSCM_H_REF_2 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define REG_ESYS_SSCM_AR_RELEASE_MAJOR_VERSION          3
/*
* @violates @ref REG_ESYS_SSCM_H_REF_2 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define REG_ESYS_SSCM_AR_RELEASE_MINOR_VERSION          2
/*
* @violates @ref REG_ESYS_SSCM_H_REF_2 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define REG_ESYS_SSCM_AR_RELEASE_REVISION_VERSION       0
#define REG_ESYS_SSCM_SW_MAJOR_VERSION                  1
#define REG_ESYS_SSCM_SW_MINOR_VERSION                  0
#define REG_ESYS_SSCM_SW_PATCH_VERSION                  1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/* STATUS: System Status Register Address. */
#define SSCM_STATUS_ADDR16                  ((uint32)(SSCM_BASEADDR + (uint32)0x0000UL))
/* MEMCONFIG: System Memory and ID Register Address. */
#define SSCM_MEMCONFIG_ADDR16               ((uint32)(SSCM_BASEADDR + (uint32)0x0002UL))
/* ERROR: Error Configuration Register Address. */
#define SSCM_ERROR_ADDR16                   ((uint32)(SSCM_BASEADDR + (uint32)0x0006UL))
/* DEBUGPORT: Debug Status Port Register Address. */
#define SSCM_DEBUGPORT_ADDR16               ((uint32)(SSCM_BASEADDR + (uint32)0x0008UL))

/* PWCMPH: Password Comparison Register High Word Register Address. */
#define SSCM_PWCMPH_ADDR32                  ((uint32)(SSCM_BASEADDR + (uint32)0x000CUL))
/* PWCMPL: Password Comparison Register Low Word Register Address. */
#define SSCM_PWCMPL_ADDR32                  ((uint32)(SSCM_BASEADDR + (uint32)0x0010UL))

/* DPMBOOT: DPM Boot Register Address. */
#define SSCM_DPMBOOT_ADDR32                 ((uint32)(SSCM_BASEADDR + (uint32)0x0018UL))
/* DPMKEY: DPM Boot Key Register Address. */
#define SSCM_DPMKEY_ADDR32                  ((uint32)(SSCM_BASEADDR + (uint32)0x001CUL))

/* UOPS: User Option Status Register Address. */
#define SSCM_UOPS_ADDR32                    ((uint32)(SSCM_BASEADDR + (uint32)0x0020UL))
/* SCTR: SSCM Control Register Address. */
#define SSCM_SCTR_ADDR32                    ((uint32)(SSCM_BASEADDR + (uint32)0x0024UL))

#define SSCM_STATUS_LSM_MASK16              ((uint16)0x8000U)
#define SSCM_STATUS_LOCK_STEP_MODE          ((uint16)0x8000U)
#define SSCM_STATUS_DECOUPLED_MODE          ((uint16)0x0000U)

#define SSCM_ERROR_RAE_DISABLE              ((uint16)0x0000U)
#define SSCM_ERROR_RAE_ENABLE               ((uint16)0x0001U)
#define SSCM_ERROR_PAE_DISABLE              ((uint16)0x0000U)
#define SSCM_ERROR_PAE_ENABLE               ((uint16)0x0002U)


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


#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_SSCM_H */

/** @} */
