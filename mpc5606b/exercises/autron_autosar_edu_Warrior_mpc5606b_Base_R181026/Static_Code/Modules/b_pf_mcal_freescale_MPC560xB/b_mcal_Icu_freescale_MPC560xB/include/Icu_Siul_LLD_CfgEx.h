/**
*     @file    Icu_Siul_LLD_CfgEx.h
*     @version 1.0.1
* 
*     @brief   AUTOSAR Icu - SIUL low level driver exported structures.
*     @details Interface between the high level driver (Autosar dependent) and the low level driver(platform dependent).
* 
*     @implements     DICU04600
*     @addtogroup ICU_MODULE
*     @{
*/
/*==================================================================================================    
*     Project             : AUTOSAR 4.0 MCAL
*     Platform            : PA
*     Peripheral          : eMIOS
*     Dependencies        : none
* 
*     Autosar Version     : 4.0.3
*     Autosar Revision    : ASR_REL_4_0_REV_0003
*     Autosar ConfVariant : 
*     SWVersion           : 1.0.1
*     BuildVersion        : MPC560xB_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20140606
* 
*     (c) Copyright 2006-2014 Freescale Semiconductor Inc and STMicroelectronics
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef SIUL_LLD_EX_H
#define SIUL_LLD_EX_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
* 
* @section Icu_Siul_LLD_CfgEx_h_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers. 
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
*@section Icu_Siul_LLD_CfgEx_h_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*/

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @implements     DICU04101, DICU04102, DICU04103, DICU04104, DICU04105, DICU04106, DICU04107
*/
#define ICU_SIUL_LLD_CFG_EX_VENDOR_ID                   43
/*
* @violates @ref Icu_Siul_LLD_CfgEx_h_2 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_LLD_CFG_EX_AR_RELEASE_MAJOR_VERSION   4
/*
* @violates @ref Icu_Siul_LLD_CfgEx_h_1 Identifier clash.
*/
/*
* @violates @ref Icu_Siul_LLD_CfgEx_h_2 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_LLD_CFG_EX_AR_RELEASE_MINOR_VERSION   0
/*
* @violates @ref Icu_Siul_LLD_CfgEx_h_1 Identifier clash.
*/
/*
* @violates @ref Icu_Siul_LLD_CfgEx_h_2 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_LLD_CFG_EX_AR_RELEASE_REVISION_VERSION   3
/*
* @violates @ref Icu_Siul_LLD_CfgEx_h_2 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_LLD_CFG_EX_SW_MAJOR_VERSION   1
/*
* @violates @ref Icu_Siul_LLD_CfgEx_h_2 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_LLD_CFG_EX_SW_MINOR_VERSION   0
/*
* @violates @ref Icu_Siul_LLD_CfgEx_h_2 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_LLD_CFG_EX_SW_PATCH_VERSION   1


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/**
* @{
* @brief SIUL External Interrupt Channels defines
*/
#define SIUL_IRQ_0    ((uint8) 0U)
#define SIUL_IRQ_1    ((uint8) 1U)
#define SIUL_IRQ_2    ((uint8) 2U)
#define SIUL_IRQ_3    ((uint8) 3U)
#define SIUL_IRQ_4    ((uint8) 4U)
#define SIUL_IRQ_5    ((uint8) 5U)
#define SIUL_IRQ_6    ((uint8) 6U)
#define SIUL_IRQ_7    ((uint8) 7U)
#define SIUL_IRQ_8    ((uint8) 8U)
#define SIUL_IRQ_9    ((uint8) 9U)
#define SIUL_IRQ_10   ((uint8)10U)
#define SIUL_IRQ_11   ((uint8)11U)
#define SIUL_IRQ_12   ((uint8)12U)
#define SIUL_IRQ_13   ((uint8)13U)
#define SIUL_IRQ_14   ((uint8)14U)
#define SIUL_IRQ_15   ((uint8)15U)
#define SIUL_IRQ_16   ((uint8)16U)
#define SIUL_IRQ_17   ((uint8)17U)
#define SIUL_IRQ_18   ((uint8)18U)
#define SIUL_IRQ_19   ((uint8)19U)
#define SIUL_IRQ_20   ((uint8)20U)
#define SIUL_IRQ_21   ((uint8)21U)
#define SIUL_IRQ_22   ((uint8)22U)
#define SIUL_IRQ_23   ((uint8)23U)
#define SIUL_IRQ_24   ((uint8)24U)
#define SIUL_IRQ_25   ((uint8)25U)
#define SIUL_IRQ_26   ((uint8)26U)
#define SIUL_IRQ_27   ((uint8)27U)
#define SIUL_IRQ_28   ((uint8)28U)
#define SIUL_IRQ_29   ((uint8)29U)
#define SIUL_IRQ_30   ((uint8)30U)
#define SIUL_IRQ_31   ((uint8)31U)

/**@}*/

/**
* @{
* @brief Filter for enabling the SIUL interrupt
*/
#define SIUL_INT_FILTER_ENABLE  (0x1U)
/**@}*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif  /* SIUL_LLD_EX_H */
/** @} */

