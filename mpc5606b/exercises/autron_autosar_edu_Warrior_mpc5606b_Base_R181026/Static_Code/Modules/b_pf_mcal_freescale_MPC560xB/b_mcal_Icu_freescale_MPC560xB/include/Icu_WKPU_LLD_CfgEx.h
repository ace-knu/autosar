/**
 *     @file    Icu_Wkpu_LLD_CfgEx.h
 *     @version 1.0.1
 * 
 *     @brief   AUTOSAR Icu - WKPU header file support for ICU driver.
 *     @details WKPU header file, containing the variables and functions that are exported by the WKPU driver.
 * 
 *     @addtogroup Wkpu
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
/**
* @file    Icu_Wkpu_LLD_CfgEx.h
* @remarks Implements DICU06301
*/
#ifndef WKPU_LLD_EX_H
#define WKPU_LLD_EX_H

/**
* @page misra_violations MISRA-C:2004 violations
*
*@section Icu_WKPU_LLD_CfgEx_h_1
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
*@{
*@brief   Header file version information
*@remarks Covers BSW00374, BSW00379, BSW00318
*/
#define WKPU_VENDOR_ID_EXT_H          43

/*
* @violates @ref Icu_WKPU_LLD_CfgEx_h_1 This is required as per autosar Requirement, 
*/
#define WKPU_AR_RELEASE_MAJOR_VERSION_EXT_H    4
/*
* @violates @ref Icu_WKPU_LLD_CfgEx_h_1 This is required as per autosar Requirement, 
*/
#define WKPU_AR_RELEASE_MINOR_VERSION_EXT_H    0
/*
* @violates @ref Icu_WKPU_LLD_CfgEx_h_1 This is required as per autosar Requirement, 
*/
#define WKPU_AR_RELEASE_REVISION_VERSION_EXT_H   3

#define WKPU_SW_MAJOR_VERSION_EXT_H   1
#define WKPU_SW_MINOR_VERSION_EXT_H   0
#define WKPU_SW_PATCH_VERSION_EXT_H   1
/**@}*/

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/**
*@{
*@brief WKPU External Interrupt Channels defines
*@implements DICU06302
*/
#define WKPU_0    ((uint8) 0U)
#define WKPU_1    ((uint8) 1U)
#define WKPU_2    ((uint8) 2U)
#define WKPU_3    ((uint8) 3U)
#define WKPU_4    ((uint8) 4U)
#define WKPU_5    ((uint8) 5U)
#define WKPU_6    ((uint8) 6U)
#define WKPU_7    ((uint8) 7U)
#define WKPU_8    ((uint8) 8U)
#define WKPU_9    ((uint8) 9U)
#define WKPU_10   ((uint8)10U)
#define WKPU_11   ((uint8)11U)
#define WKPU_12   ((uint8)12U)
#define WKPU_13   ((uint8)13U)
#define WKPU_14   ((uint8)14U)
#define WKPU_15   ((uint8)15U)
#define WKPU_16   ((uint8)16U)
#define WKPU_17   ((uint8)17U)
#define WKPU_18   ((uint8)18U)
#define WKPU_19   ((uint8)19U)
#define WKPU_20   ((uint8)20U)
#define WKPU_21   ((uint8)21U)
#define WKPU_22   ((uint8)22U)
#define WKPU_23   ((uint8)23U)
#define WKPU_24   ((uint8)24U)
#define WKPU_25   ((uint8)25U)
#define WKPU_26   ((uint8)26U)
#define WKPU_27   ((uint8)27U)
#define WKPU_28   ((uint8)28U)
#define WKPU_29   ((uint8)29U)
#define WKPU_30   ((uint8)30U)
#define WKPU_31   ((uint8)31U)
/**@}*/

/**
*@{
*@brief Filter for enabling the WKUP interrupt
*@implements DICU06303
*/
#define WKPU_INT_FILTER_ENABLE  0x1U
/**@}*/

/**
*@{
*@brief define for enabling WKUP pullup
*@implements DICU06303
*/
#define WKPU_PULLUP_ENABLE      0x1U
/**@}*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif  /* WKPU_LLD_EX_H */
/**@}*/
