/**
*     @file Icu_LLD.h
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - Brief description.
*     @details Detailed description.
*
*     @addtogroup ICU_MODULE
*     @{
*/
/*==================================================================================================
*     Project AUTOSAR 4.0 MCAL
*     Platform PA
*     Peripheral eMIOS
*     Dependencies none
*
*     Autosar Version 4.0.3
*     Autosar Revision ASR_REL_4_0_REV_0003
*     Autosar ConfVariant
*     SWVersion 1.0.1
*     BuildVersion MPC560xB_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20140606
*
*     (c) Copyright 2006-2014 Freescale Semiconductor Inc and STMicroelectronics
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/


/**
* @file    Icu_LLD.h
* @remarks Implements DICU02600
*/

/**
* @page misra_violations MISRA-C:2004 violations
* 
* @section Icu_LLD_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
* 
* @section Icu_LLD_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
* 
* @section Icu_LLD_h_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
*@section Icu_LLD_h_REF_4
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
* @section Icu_LLD_h_REF_5
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused
*
* @section Icu_LLD_h_REF_6
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only accessed
* from within a single function.
*/



#ifndef ICU_LLD_H
#define ICU_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Icu_LLD_h_REF_2 precautions to prevent the contents
*        of a header file being included twice 
*/

#include "Icu.h"

#if (ICU_DUAL_CLOCK_MODE == STD_ON)
/*
* @violates @ref Icu_LLD_h_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
    #include "Icu_NonASR.h"
#endif /* ICU_DUAL_CLOCK_MODE */
/*
* @violates @ref Icu_LLD_h_REF_2 precautions to prevent the contents
*        of a header file being included twice 
*/
#include "Std_Types.h"
/*
* @violates @ref Icu_LLD_h_REF_2 precautions to prevent the contents
*        of a header file being included twice 
*/
#include "Icu_eMIOS_LLD.h"
#include "Icu_eMIOS_LLD_CfgEx.h"
/*
* @violates @ref Icu_LLD_h_REF_2 precautions to prevent the contents
*        of a header file being included twice 
*/
#include "Icu_Siul_LLD_CfgEx.h"
/*
* @violates @ref Icu_LLD_h_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu_WKPU_LLD_CfgEx.h"
/*
* @violates @ref Icu_LLD_h_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Reg_eSys_eMIOS.h"
#include "Icu_Siul_LLD.h"
#if(ICU_DMA_SUPPORTED == STD_ON)
#include "Reg_eSys_eMIOS_CfgEx.h"
#include "Dma_LLD.h"
#endif
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Icu_LLD.h
* @brief          Source file version information
* @implements     DICU02027, DICU02028, DICU02029, DICU02030, DICU02031, DICU02032, DICU02033
*/
#define ICU_LLD_VENDOR_ID                       43

/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_LLD_AR_RELEASE_MAJOR_VERSION        4
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_LLD_AR_RELEASE_MINOR_VERSION        0
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_LLD_AR_RELEASE_REVISION_VERSION     3

#define ICU_LLD_SW_MAJOR_VERSION                1
#define ICU_LLD_SW_MINOR_VERSION                0
#define ICU_LLD_SW_PATCH_VERSION                1
/**@}*/

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file Icu_LLD.h and Icu_eMIOS_LLD.h header  file have the same Vendor Id version */
#if (ICU_LLD_VENDOR_ID != ICU_EMIOS_LLD_H_VENDOR_ID)
#error "Icu_LLD.h and Icu_eMIOS_LLD.h have different vendor IDs"
#endif

/* Check if header file Icu_LLD.h and Icu_eMIOS_LLD.h header file are of the Autosar version */

    #if ((ICU_LLD_AR_RELEASE_MAJOR_VERSION != ICU_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_LLD_AR_RELEASE_MINOR_VERSION != ICU_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION) || \
         (ICU_LLD_AR_RELEASE_REVISION_VERSION != ICU_EMIOS_LLD_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_LLD.h and Icu_eMIOS_LLD.h are different"
    #endif

/* Check if header file Icu_LLD.h and Icu_eMIOS_LLD.h header file are of the same software version */
#if ((ICU_LLD_SW_MAJOR_VERSION != ICU_EMIOS_LLD_H_SW_MAJOR_VERSION) || \
     (ICU_LLD_SW_MINOR_VERSION != ICU_EMIOS_LLD_H_SW_MINOR_VERSION) || \
     (ICU_LLD_SW_PATCH_VERSION != ICU_EMIOS_LLD_H_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_LLD.h and Icu_eMIOS_LLD.h are different"
#endif


/* Check if Icu_LLD.h and Icu_eMIOS_LLD_CfgEx.h header file have the same Vendor Id version */
#if (ICU_LLD_VENDOR_ID != ICU_EMIOS_LLD_CFGEX_H_VENDOR_ID)
#error "Icu_LLD.h and Icu_eMIOS_LLD_CfgEx.h have different vendor IDs"
#endif


    #if ((ICU_LLD_AR_RELEASE_MAJOR_VERSION != ICU_EMIOS_LLD_CFGEX_H_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_LLD_AR_RELEASE_MINOR_VERSION != ICU_EMIOS_LLD_CFGEX_H_AR_RELEASE_MINOR_VERSION) || \
         (ICU_LLD_AR_RELEASE_REVISION_VERSION != ICU_EMIOS_LLD_CFGEX_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_LLD.h and Icu_eMIOS_LLD_CfgEx.h are different"
    #endif

/* Check if  Icu_LLD.h and Icu_eMIOS_LLD_CfgEx.h header file are of the same software version */
#if ((ICU_LLD_SW_MAJOR_VERSION != ICU_EMIOS_LLD_CFGEX_H_SW_MAJOR_VERSION) || \
     (ICU_LLD_SW_MINOR_VERSION != ICU_EMIOS_LLD_CFGEX_H_SW_MINOR_VERSION) || \
     (ICU_LLD_SW_PATCH_VERSION != ICU_EMIOS_LLD_CFGEX_H_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_LLD.h and Icu_eMIOS_LLD_CfgEx.h are different"
#endif


/* Check if  Icu_LLD.h and SIUL_Icu_LLD_CfgEx.h header file have the same Vendor Id version */
#if (ICU_LLD_VENDOR_ID != ICU_SIUL_LLD_CFG_EX_VENDOR_ID)
#error "Icu_LLD.h and SIUL_Icu_LLD_CfgEx.h have different vendor IDs"
#endif

/* Check if header file Icu_LLD.h and SIUL_Icu_LLD_CfgEx.h header file are of the Autosar version */

    #if ((ICU_LLD_AR_RELEASE_MAJOR_VERSION != ICU_SIUL_LLD_CFG_EX_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_LLD_AR_RELEASE_MINOR_VERSION != ICU_SIUL_LLD_CFG_EX_AR_RELEASE_MINOR_VERSION) || \
         (ICU_LLD_AR_RELEASE_REVISION_VERSION != ICU_SIUL_LLD_CFG_EX_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_LLD.h and SIUL_Icu_LLD_CfgEx.h are different"
    #endif

/* Check if Icu_LLD.h and SIUL_Icu_LLD_CfgEx.h header file are of the same software version */
#if ((ICU_LLD_SW_MAJOR_VERSION != ICU_SIUL_LLD_CFG_EX_SW_MAJOR_VERSION) || \
     (ICU_LLD_SW_MINOR_VERSION != ICU_SIUL_LLD_CFG_EX_SW_MINOR_VERSION) || \
     (ICU_LLD_SW_PATCH_VERSION != ICU_SIUL_LLD_CFG_EX_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_LLD.h and SIUL_Icu_LLD_CfgEx.h are different"
#endif


/* Check if Icu_LLD.h and WKPU_Icu_LLD_CfgEx.h header  file have the same Vendor Id version */
#if (ICU_LLD_VENDOR_ID != WKPU_VENDOR_ID_EXT_H)
#error "Icu_LLD.h and WKPU_Icu_LLD_CfgEx.h have different vendor IDs"
#endif

/* Check if header file Icu_LLD.h and WKPU_Icu_LLD_CfgEx.h header file are of the Autosar version */

    #if ((ICU_LLD_AR_RELEASE_MAJOR_VERSION != WKPU_AR_RELEASE_MAJOR_VERSION_EXT_H) || \
         (ICU_LLD_AR_RELEASE_MINOR_VERSION != WKPU_AR_RELEASE_MINOR_VERSION_EXT_H) || \
         (ICU_LLD_AR_RELEASE_REVISION_VERSION != WKPU_AR_RELEASE_REVISION_VERSION_EXT_H))
    #error "AutoSar Version Numbers of Icu_LLD.h and WKPU_Icu_LLD_CfgEx.h are different"
    #endif

/* Check if Icu_LLD.h and WKPU_Icu_LLD_CfgEx.h header file are of the same software version */
#if ((ICU_LLD_SW_MAJOR_VERSION != WKPU_SW_MAJOR_VERSION_EXT_H) || \
     (ICU_LLD_SW_MINOR_VERSION != WKPU_SW_MINOR_VERSION_EXT_H) || \
     (ICU_LLD_SW_PATCH_VERSION != WKPU_SW_PATCH_VERSION_EXT_H))
#error "Software Version Numbers of Icu_LLD.h and WKPU_Icu_LLD_CfgEx.h are different"
#endif


/* Check if header file Icu_LLD.h and Icu.h header file have the same Vendor Id version */
#if (ICU_LLD_VENDOR_ID != ICU_VENDOR_ID)
#error "Icu_LLD.h and Icu.h have different vendor IDs"
#endif

/* Check if header file Icu_LLD.h and Icu.h header file are of the Autosar version */
#if ((ICU_LLD_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_LLD_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION) || \
     (ICU_LLD_AR_RELEASE_REVISION_VERSION != ICU_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_LLD.h and Icu.h are different"
#endif
/* Check if header file Icu_LLD.h and Icu.h header file are of the same software version */
#if ((ICU_LLD_SW_MAJOR_VERSION != ICU_SW_MAJOR_VERSION) || \
     (ICU_LLD_SW_MINOR_VERSION != ICU_SW_MINOR_VERSION) || \
     (ICU_LLD_SW_PATCH_VERSION != ICU_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_LLD.h and Icu.h are different"
#endif

#if ( ICU_DUAL_CLOCK_MODE == STD_ON )
    /* Check if header file Icu_LLD.h and Icu_NonASR.h header file have the same Vendor Id
       version */
    #if (ICU_LLD_VENDOR_ID != ICU_NONASR_VENDOR_ID_H)
    #error "Icu_LLD.h and Icu_NonASR.h have different vendor IDs"
    #endif

    /* Check if header file Icu_LLD.h and Icu_NonASR.h header file are of the Autosar
       version */
        #if ((ICU_LLD_AR_RELEASE_MAJOR_VERSION != ICU_NONASR_AR_RELEASE_MAJOR_VERSION_H) || \
             (ICU_LLD_AR_RELEASE_MINOR_VERSION != ICU_NONASR_AR_RELEASE_MINOR_VERSION_H) || \
             (ICU_LLD_AR_RELEASE_REVISION_VERSION != ICU_NONASR_AR_RELEASE_REVISION_VERSION_H))
        #error "AutoSar Version Numbers of Icu_LLD.h and Icu_NonASR.h are different"
        #endif

    /* Check if header file Icu_LLD.h and Icu_NonASR.h header file are of the same software
       version */
    #if ((ICU_LLD_SW_MAJOR_VERSION != ICU_NONASR_SW_MAJOR_VERSION_H) || \
         (ICU_LLD_SW_MINOR_VERSION != ICU_NONASR_SW_MINOR_VERSION_H) || \
         (ICU_LLD_SW_PATCH_VERSION != ICU_NONASR_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Icu_LLD.h and Icu_NonASR.h are different"
    #endif
#endif /* ICU_DUAL_CLOCK_MODE */

/* Check if header file Icu_LLD.h and Std_Types.h header file are of the Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_LLD_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_LLD_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu_LLD.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/* Macros to name the HW channels (eMIOS and IRQ's) */
/**
* @{
* @brief      eMIOS Channels
* @details    eMIOS Hardware Channels
* @implements DICU02601
*/
#define ICU_EMIOS_0_CH_0        0U
#define ICU_EMIOS_0_CH_1        (ICU_EMIOS_0_CH_0 +  1U)
#define ICU_EMIOS_0_CH_2        (ICU_EMIOS_0_CH_0 +  2U)
#define ICU_EMIOS_0_CH_3        (ICU_EMIOS_0_CH_0 +  3U)
#define ICU_EMIOS_0_CH_4        (ICU_EMIOS_0_CH_0 +  4U)
#define ICU_EMIOS_0_CH_5        (ICU_EMIOS_0_CH_0 +  5U)
#define ICU_EMIOS_0_CH_6        (ICU_EMIOS_0_CH_0 +  6U)
#define ICU_EMIOS_0_CH_7        (ICU_EMIOS_0_CH_0 +  7U)
#define ICU_EMIOS_0_CH_8        (ICU_EMIOS_0_CH_0 +  8U)
#define ICU_EMIOS_0_CH_9        (ICU_EMIOS_0_CH_0 +  9U)
#define ICU_EMIOS_0_CH_10       (ICU_EMIOS_0_CH_0 + 10U)
#define ICU_EMIOS_0_CH_11       (ICU_EMIOS_0_CH_0 + 11U)
#define ICU_EMIOS_0_CH_12       (ICU_EMIOS_0_CH_0 + 12U)
#define ICU_EMIOS_0_CH_13       (ICU_EMIOS_0_CH_0 + 13U)
#define ICU_EMIOS_0_CH_14       (ICU_EMIOS_0_CH_0 + 14U)
#define ICU_EMIOS_0_CH_15       (ICU_EMIOS_0_CH_0 + 15U)
#define ICU_EMIOS_0_CH_16       (ICU_EMIOS_0_CH_0 + 16U)
#define ICU_EMIOS_0_CH_17       (ICU_EMIOS_0_CH_0 + 17U)
#define ICU_EMIOS_0_CH_18       (ICU_EMIOS_0_CH_0 + 18U)
#define ICU_EMIOS_0_CH_19       (ICU_EMIOS_0_CH_0 + 19U)
#define ICU_EMIOS_0_CH_20       (ICU_EMIOS_0_CH_0 + 20U)
#define ICU_EMIOS_0_CH_21       (ICU_EMIOS_0_CH_0 + 21U)
#define ICU_EMIOS_0_CH_22       (ICU_EMIOS_0_CH_0 + 22U)
#define ICU_EMIOS_0_CH_23       (ICU_EMIOS_0_CH_0 + 23U)
#define ICU_EMIOS_0_CH_24       (ICU_EMIOS_0_CH_0 + 24U)
#define ICU_EMIOS_0_CH_25       (ICU_EMIOS_0_CH_0 + 25U)
#define ICU_EMIOS_0_CH_26       (ICU_EMIOS_0_CH_0 + 26U)
#define ICU_EMIOS_0_CH_27       (ICU_EMIOS_0_CH_0 + 27U)
#define ICU_EMIOS_0_CH_28       (ICU_EMIOS_0_CH_0 + 28U)
#define ICU_EMIOS_0_CH_29       (ICU_EMIOS_0_CH_0 + 29U)
#define ICU_EMIOS_0_CH_30       (ICU_EMIOS_0_CH_0 + 30U)
#define ICU_EMIOS_0_CH_31       (ICU_EMIOS_0_CH_0 + 31U)

#define ICU_EMIOS_1_CH_0        (ICU_EMIOS_0_CH_31 + 1U)
#define ICU_EMIOS_1_CH_1        (ICU_EMIOS_1_CH_0 +  1U)
#define ICU_EMIOS_1_CH_2        (ICU_EMIOS_1_CH_0 +  2U)
#define ICU_EMIOS_1_CH_3        (ICU_EMIOS_1_CH_0 +  3U)
#define ICU_EMIOS_1_CH_4        (ICU_EMIOS_1_CH_0 +  4U)
#define ICU_EMIOS_1_CH_5        (ICU_EMIOS_1_CH_0 +  5U)
#define ICU_EMIOS_1_CH_6        (ICU_EMIOS_1_CH_0 +  6U)
#define ICU_EMIOS_1_CH_7        (ICU_EMIOS_1_CH_0 +  7U)
#define ICU_EMIOS_1_CH_8        (ICU_EMIOS_1_CH_0 +  8U)
#define ICU_EMIOS_1_CH_9        (ICU_EMIOS_1_CH_0 +  9U)
#define ICU_EMIOS_1_CH_10       (ICU_EMIOS_1_CH_0 + 10U)
#define ICU_EMIOS_1_CH_11       (ICU_EMIOS_1_CH_0 + 11U)
#define ICU_EMIOS_1_CH_12       (ICU_EMIOS_1_CH_0 + 12U)
#define ICU_EMIOS_1_CH_13       (ICU_EMIOS_1_CH_0 + 13U)
#define ICU_EMIOS_1_CH_14       (ICU_EMIOS_1_CH_0 + 14U)
#define ICU_EMIOS_1_CH_15       (ICU_EMIOS_1_CH_0 + 15U)
#define ICU_EMIOS_1_CH_16       (ICU_EMIOS_1_CH_0 + 16U)
#define ICU_EMIOS_1_CH_17       (ICU_EMIOS_1_CH_0 + 17U)
#define ICU_EMIOS_1_CH_18       (ICU_EMIOS_1_CH_0 + 18U)
#define ICU_EMIOS_1_CH_19       (ICU_EMIOS_1_CH_0 + 19U)
#define ICU_EMIOS_1_CH_20       (ICU_EMIOS_1_CH_0 + 20U)
#define ICU_EMIOS_1_CH_21       (ICU_EMIOS_1_CH_0 + 21U)
#define ICU_EMIOS_1_CH_22       (ICU_EMIOS_1_CH_0 + 22U)
#define ICU_EMIOS_1_CH_23       (ICU_EMIOS_1_CH_0 + 23U)
#define ICU_EMIOS_1_CH_24       (ICU_EMIOS_1_CH_0 + 24U)
#define ICU_EMIOS_1_CH_25       (ICU_EMIOS_1_CH_0 + 25U)
#define ICU_EMIOS_1_CH_26       (ICU_EMIOS_1_CH_0 + 26U)
#define ICU_EMIOS_1_CH_27       (ICU_EMIOS_1_CH_0 + 27U)
#define ICU_EMIOS_1_CH_28       (ICU_EMIOS_1_CH_0 + 28U)
#define ICU_EMIOS_1_CH_29       (ICU_EMIOS_1_CH_0 + 29U)
#define ICU_EMIOS_1_CH_30       (ICU_EMIOS_1_CH_0 + 30U)
#define ICU_EMIOS_1_CH_31       (ICU_EMIOS_1_CH_0 + 31U)
/**@}*/

/**
* @{
* @brief      External Interrupt Channels
* @details    SIU IRQ Channels
* @implements DICU02602
*/
#define ICU_IRQ_0           (ICU_EMIOS_1_CH_31 + 1U)
#define ICU_IRQ_1           (ICU_IRQ_0 +  1U)
#define ICU_IRQ_2           (ICU_IRQ_0 +  2U)
#define ICU_IRQ_3           (ICU_IRQ_0 +  3U)
#define ICU_IRQ_4           (ICU_IRQ_0 +  4U)
#define ICU_IRQ_5           (ICU_IRQ_0 +  5U)
#define ICU_IRQ_6           (ICU_IRQ_0 +  6U)
#define ICU_IRQ_7           (ICU_IRQ_0 +  7U)
#define ICU_IRQ_8           (ICU_IRQ_0 +  8U)
#define ICU_IRQ_9           (ICU_IRQ_0 +  9U)
#define ICU_IRQ_10          (ICU_IRQ_0 + 10U)
#define ICU_IRQ_11          (ICU_IRQ_0 + 11U)
#define ICU_IRQ_12          (ICU_IRQ_0 + 12U)
#define ICU_IRQ_13          (ICU_IRQ_0 + 13U)
#define ICU_IRQ_14          (ICU_IRQ_0 + 14U)
#define ICU_IRQ_15          (ICU_IRQ_0 + 15U)
#define ICU_IRQ_16          (ICU_IRQ_0 + 16U)
#define ICU_IRQ_17          (ICU_IRQ_0 + 17U)
#define ICU_IRQ_18          (ICU_IRQ_0 + 18U)
#define ICU_IRQ_19          (ICU_IRQ_0 + 19U)
#define ICU_IRQ_20          (ICU_IRQ_0 + 20U)
#define ICU_IRQ_21          (ICU_IRQ_0 + 21U)
#define ICU_IRQ_22          (ICU_IRQ_0 + 22U)
#define ICU_IRQ_23          (ICU_IRQ_0 + 23U)
/**@}*/

/**
* @{
* @brief      External Interrupt Channels
* @details    WKUP IRQ Channels
* @implements DICU02603
*/
#define ICU_WKUP_0          (ICU_IRQ_23 +  1U)
#define ICU_WKUP_1          (ICU_WKUP_0 +  1U)
#define ICU_WKUP_2          (ICU_WKUP_0 +  2U)
#define ICU_WKUP_3          (ICU_WKUP_0 +  3U)
#define ICU_WKUP_4          (ICU_WKUP_0 +  4U)
#define ICU_WKUP_5          (ICU_WKUP_0 +  5U)
#define ICU_WKUP_6          (ICU_WKUP_0 +  6U)
#define ICU_WKUP_7          (ICU_WKUP_0 +  7U)
#define ICU_WKUP_8          (ICU_WKUP_0 +  8U)
#define ICU_WKUP_9          (ICU_WKUP_0 +  9U)
#define ICU_WKUP_10         (ICU_WKUP_0 + 10U)
#define ICU_WKUP_11         (ICU_WKUP_0 + 11U)
#define ICU_WKUP_12         (ICU_WKUP_0 + 12U)
#define ICU_WKUP_13         (ICU_WKUP_0 + 13U)
#define ICU_WKUP_14         (ICU_WKUP_0 + 14U)
#define ICU_WKUP_15         (ICU_WKUP_0 + 15U)
#define ICU_WKUP_16         (ICU_WKUP_0 + 16U)
#define ICU_WKUP_17         (ICU_WKUP_0 + 17U)
#define ICU_WKUP_18         (ICU_WKUP_0 + 18U)
#define ICU_WKUP_19         (ICU_WKUP_0 + 19U)
#define ICU_WKUP_20         (ICU_WKUP_0 + 20U)
#define ICU_WKUP_21         (ICU_WKUP_0 + 21U)
#define ICU_WKUP_22         (ICU_WKUP_0 + 22U)
#define ICU_WKUP_23         (ICU_WKUP_0 + 23U)
#define ICU_WKUP_24         (ICU_WKUP_0 + 24U)
#define ICU_WKUP_25         (ICU_WKUP_0 + 25U)
#define ICU_WKUP_26         (ICU_WKUP_0 + 26U)
#define ICU_WKUP_27         (ICU_WKUP_0 + 27U)
#define ICU_WKUP_28         (ICU_WKUP_0 + 28U)
#if (ICU_DMA_SUPPORTED == (STD_ON))
#define    ICU_EMIOS_DMA_CH_0    ((uint8)0U)
#define    ICU_EMIOS_DMA_CH_1    ((uint8)1U)
#define    ICU_EMIOS_DMA_CH_2    ((uint8)2U)
#define    ICU_EMIOS_DMA_CH_3    ((uint8)3U)
#define    ICU_EMIOS_DMA_CH_4    ((uint8)4U)
#define    ICU_EMIOS_DMA_CH_5    ((uint8)5U)
#define    ICU_EMIOS_DMA_CH_6    ((uint8)6U)
#define    ICU_EMIOS_DMA_CH_7    ((uint8)7U)
#define    ICU_EMIOS_DMA_CH_8    ((uint8)8U)
#define    ICU_EMIOS_DMA_CH_9    ((uint8)9U)
#define    ICU_EMIOS_DMA_CH_10    ((uint8)10U)
#define    ICU_EMIOS_DMA_CH_11    ((uint8)11U)
#define    ICU_EMIOS_DMA_CH_12    ((uint8)12U)
#define    ICU_EMIOS_DMA_CH_13    ((uint8)13U)
#define    ICU_EMIOS_DMA_CH_14    ((uint8)14U)
#define    ICU_EMIOS_DMA_CH_15    ((uint8)15U)
#define    ICU_EMIOS_DMA_CH_16    ((uint8)16U)
#define    ICU_EMIOS_DMA_CH_17    ((uint8)17U)
#define    ICU_EMIOS_DMA_CH_18    ((uint8)18U)
#define    ICU_EMIOS_DMA_CH_19    ((uint8)19U)
#define    ICU_EMIOS_DMA_CH_20    ((uint8)20U)
#define    ICU_EMIOS_DMA_CH_21    ((uint8)21U)
#define    ICU_EMIOS_DMA_CH_22    ((uint8)22U)
#define    ICU_EMIOS_DMA_CH_23    ((uint8)23U)
#define    ICU_EMIOS_DMA_CH_24    ((uint8)24U)
#define    ICU_EMIOS_DMA_CH_25    ((uint8)25U)
#define    ICU_EMIOS_DMA_CH_26    ((uint8)26U)
#define    ICU_EMIOS_DMA_CH_27    ((uint8)27U)
#define    ICU_EMIOS_DMA_CH_28    ((uint8)28U)
#define    ICU_EMIOS_DMA_CH_29    ((uint8)29U)
#define    ICU_EMIOS_DMA_CH_30    ((uint8)30U)
#define    ICU_EMIOS_DMA_CH_31    ((uint8)31U)
#define    ICU_EMIOS_DMA_CH_32    ((uint8)32U)
#define    ICU_EMIOS_DMA_CH_33    ((uint8)33U)
#define    ICU_EMIOS_DMA_CH_34    ((uint8)34U)
#define    ICU_EMIOS_DMA_CH_35    ((uint8)35U)
#define    ICU_EMIOS_DMA_CH_36    ((uint8)36U)
#define    ICU_EMIOS_DMA_CH_37    ((uint8)37U)
#define    ICU_EMIOS_DMA_CH_38    ((uint8)38U)
#define    ICU_EMIOS_DMA_CH_39    ((uint8)39U)
#define    ICU_EMIOS_DMA_CH_40    ((uint8)40U)
#define    ICU_EMIOS_DMA_CH_41    ((uint8)41U)
#define    ICU_EMIOS_DMA_CH_42    ((uint8)42U)
#define    ICU_EMIOS_DMA_CH_43    ((uint8)43U)
#define    ICU_EMIOS_DMA_CH_44    ((uint8)44U)
#define    ICU_EMIOS_DMA_CH_45    ((uint8)45U)
#define    ICU_EMIOS_DMA_CH_46    ((uint8)46U)
#define    ICU_EMIOS_DMA_CH_47    ((uint8)47U)
#define    ICU_EMIOS_DMA_CH_48    ((uint8)48U)
#define    ICU_EMIOS_DMA_CH_49    ((uint8)49U)
#define    ICU_EMIOS_DMA_CH_50    ((uint8)50U)
#define    ICU_EMIOS_DMA_CH_51    ((uint8)51U)
#define    ICU_EMIOS_DMA_CH_52    ((uint8)52U)
#define    ICU_EMIOS_DMA_CH_53    ((uint8)53U)
#define    ICU_EMIOS_DMA_CH_54    ((uint8)54U)
#define    ICU_EMIOS_DMA_CH_55    ((uint8)55U)
#define    ICU_EMIOS_DMA_CH_56    ((uint8)56U)
#define    ICU_EMIOS_DMA_CH_57    ((uint8)57U)
#define    ICU_EMIOS_DMA_CH_58    ((uint8)58U)
#define    ICU_EMIOS_DMA_CH_59    ((uint8)59U)
#define    ICU_EMIOS_DMA_CH_60    ((uint8)60U)
#define    ICU_EMIOS_DMA_CH_61    ((uint8)61U)
#define    ICU_EMIOS_DMA_CH_62    ((uint8)62U)
#define    ICU_EMIOS_DMA_CH_63    ((uint8)63U)

/*
 * @violates @ref Icu_LLD_h_REF_1 Function-like macro defined
 */
#endif
/**@}*/


#define ICU_CNT1_BUSA            23U /* A Side, Counter Bus A */
#define ICU_CNT2_BUSA            (eMIOS_N_CHANNELS + 23U) /* B Side, Counter Bus A */

#define ICU_CNT1_BUSB            0U  /* A Side, Counter Bus B */
#define ICU_CNT2_BUSB            (eMIOS_N_CHANNELS + 0U) /* B Side, Counter Bus B */

#define ICU_CNT1_BUSC            8U  /* A Side, Counter Bus C */
#define ICU_CNT2_BUSC            (eMIOS_N_CHANNELS + 8U) /* B Side, Counter Bus C */

#define ICU_CNT1_BUSD            16U /* A Side, Counter Bus D */
#define ICU_CNT2_BUSD            (eMIOS_N_CHANNELS + 16U) /* B Side, Counter Bus D */


#define ICU_CNT1_BUSE            24U /* A Side, Counter Bus E */
#define ICU_CNT2_BUSE            (eMIOS_N_CHANNELS + 24U) /* B Side, Counter Bus E */
/*
 * Macros regarding the maximum count value of ICU EMIOS channel internal counter
 */
/**
@{
@brief      EMIOS_INTERNAL_COUNTER_MAX_COUNT - the maximum count of eMIOS channel's internal counter
@details    Represents the maximum count of eMIOS channel's internal counter
*/
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Icu_LLD_h_REF_5 This is not a standard library macro, 
*/
#define EMIOS_INTERNAL_COUNTER_MAX_COUNT        0xffffU


/*
  * Macros regarding the maximum number of HW channels from different IP modules
 */
/**
* @{
* @brief      ICU_MAX_eMIOS_CHANNELS - the maximum number of eMIOS channels
* @details    Represents the maximum number of eMIOS channels, not necessary all
*             are available for a specific derivative. If some channels are
*             missing for a derivative, the encoding of the channels will be not
*             contiguous.
* @implements DICU02604
*/
#define ICU_MAX_eMIOS_CHANNELS      (ICU_IRQ_0)
/**@}*/

/**
* @{
* @brief      ICU_MAX_IRQ_CHANNELS - the maximum number of IRQ channels
* @details    Represents the maximum number of IRQ channels, not necessary all
*             are available for a specific derivative. If some channels are
*             missing for a derivative, the encoding of the channels will be not
*             contiguous.
* @implements DICU02605
*/
#define ICU_MAX_IRQ_CHANNELS        (ICU_WKUP_0)
/**@}*/

/**
* @{
* @brief      ICU_MAX_WKUP_CHANNELS - the maximum number of WKUP channels
* @details    Represents the maximum number of WKUP channels, not necessary all
*             are available for a specific derivative. If some channels are
*             missing for a derivative, the encoding of the channels will be not
*             contiguous.
* @implements DICU02606
*/
#define ICU_MAX_WKUP_CHANNELS        (ICU_WKUP_28 + 1U)
/**@}*/

/**
* @{
* @brief      ICU_MAX_HW_CHANNELS - the highest ICU hardware channel number
* @details    Represents the maximum number of IRQ channels, not necessary all
*             are available for a specific derivative. If some channels are
*             missing for a derivative, the encoding of the channels will be not
*             contiguous.
* @implements DICU02607
*/
#define ICU_MAX_HW_CHANNELS         (ICU_MAX_WKUP_CHANNELS)
/**@}*/

/**
* @{
* @brief      ICU_VALID_CHANNEL_INPUT_LEVEL - the maximum number of eMIOS channels
* @details    Represents the maximum number of eMIOS channels, To get the status of
*             input pin using an API Icu_GetInputLevel the channel should be an emios
*             Channel.
* @implements PPR-MCAL-3242
*/
#define ICU_VALID_CHANNEL_INPUT_LEVEL         (ICU_MAX_eMIOS_CHANNELS)
/**@}*/

/**
* @{
  * @brief Macros to translate ICU generic channels to specific hardware channels
  * @implements DICU02608,DICU02609,DICU02610,DICU02611,DICU02612
 */
/**
* @violates @ref Icu_LLD_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/


#if (eMIOS_N_CHANNELS == 32U)
/*
 * @violates @ref Icu_LLD_h_REF_1 Function-like macro defined
 */
#define ICU_eMIOS_CHANNEL(ch)       (ch)
/*
 * @violates @ref Icu_LLD_h_REF_1 Function-like macro defined
 */
#define eMIOS_ICU_CHANNEL(ch)       (ch)
#else
#define ICU_eMIOS_CHANNEL(ch)       (((( ((uint8)((ch) / eMIOS_N_CHANNELS)) << EMIOS_MOD_SHIFT ) & \
                                                   EMIOS_MOD_MASK) | (( ((uint8)((ch) %  \
                                                   eMIOS_N_CHANNELS)) << EMIOS_CH_SHIFT ) &  \
                                                                                    EMIOS_CH_MASK)))
#define eMIOS_ICU_CHANNEL(ch)       (((((ch) & EMIOS_MOD_MASK)>> \
                                                          EMIOS_MOD_SHIFT) *  eMIOS_N_CHANNELS) +  \
                                                          ((ch) & EMIOS_CH_MASK) >>  EMIOS_CH_SHIFT)
#endif

/*
* @violates @ref Icu_LLD_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define ICU_IRQ_CHANNEL(ch)         ((ch) - ICU_IRQ_0)
/*
 * @violates @ref Icu_LLD_h_REF_1 Function-like macro defined
 */
#define IRQ_ICU_CHANNEL(ch)         ((ch) + ICU_IRQ_0)

/*
 * @violates @ref Icu_LLD_h_REF_1 Function-like macro defined
 */
#define ICU_WKPU_CHANNEL(ch)        ((ch) - ICU_WKUP_0)
/*
 * @violates @ref Icu_LLD_h_REF_1 Function-like macro defined
 */
#define WKPU_ICU_CHANNEL(ch)        ((ch) + ICU_WKUP_0)


/**@}*/


/* Specific IRQ Channel parameters
  *  - defines the bitfields used in Icu_ParamValue member for ICU External Interrupt Channels
 */

/**
* @{
* @brief SIUL Channel Parameters
* @remarks Interrupt Filter Enable Register (IFER)
*          These macros are used in ICU plug-in
*/

/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_INT_FILTER_ENABLE_PARAM_MASK       ((uint32)BIT4)
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Icu_LLD_h_REF_3 Identifier clash.
*/
#define ICU_SIUL_INT_FILTER_ENABLE_PARAM_SHIFT      ((uint32)4U)
/**@}*/

/**
* @{
* @brief SIUL Channel Parameters
* @remarks Interrupt Filter Maximum Counter Registers (IFMC0 to IFMC23)
*          These macros are used in ICU plug-in
*/
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_INT_FILTER_COUNTER_PARAM_MASK      ((BIT3|BIT2|BIT1|BIT0))
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Icu_LLD_h_REF_3 Identifier clash.
*/
#define ICU_SIUL_INT_FILTER_COUNTER_PARAM_SHIFT     ((uint32)0U)
/**@}*/


/**
* @{
* @brief WKPU Channel Parameters
* @remarks Wakeup/Interrupt Filter Enable Register (WIFER)
*          These macros are used in ICU plug-in
*/
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_WKPU_INT_FILTER_ENABLE_PARAM_MASK       (BIT1)
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Icu_LLD_h_REF_3 Identifier clash.
*/
#define ICU_WKPU_INT_FILTER_ENABLE_PARAM_SHIFT      ((uint32)1U)
/**@}*/


/* Specific WKPU Channel parameters
  *  - defines for bitfields used in Icu_ParamValue member for ICU WKPU Channels
 */
/**
* @{
* @brief WKPU Channel Parameters
* @remarks Wakeup/Interrupt Pullup Enable Register (WIPUER)
*          These macros are used in ICU plug-in
*/
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_WKPU_PULLUP_ENABLE_PARAM_MASK           (BIT0)
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_WKPU_PULLUP_ENABLE_PARAM_SHIFT          ((uint32)0U)
/**@}*/


/**
* @{
* @brief Specific eMIOS Channel parameters
* @remarks defines for bitfields used in Icu_ParamValue member for ICU eMIOS Channels
*/
#define ICU_EMIOS_PRESC_ALT_PARAM_MASK          ((uint32)(BIT14|BIT13))
#define ICU_EMIOS_PRESC_ALT_PARAM_SHIFT         ((uint32)13U)
#define ICU_EMIOS_UC_MODE_PARAM_MASK            ((uint32)(BIT12|BIT11|BIT10|BIT9))
#define ICU_EMIOS_UC_MODE_PARAM_SHIFT           ((uint32)9U)

#define ICU_EMIOS_FREEZE_PARAM_MASK             ((uint32)BIT8)
#define ICU_EMIOS_FREEZE_PARAM_SHIFT            ((uint32)8U)

#define ICU_EMIOS_PRESCALER_PARAM_MASK          ((uint32)(BIT7|BIT6))
#define ICU_EMIOS_PRESCALER_PARAM_SHIFT         ((uint32)6U)

#define ICU_EMIOS_DIG_FILTER_PARAM_MASK         ((uint32)(BIT5|BIT4|BIT3|BIT2))
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_DIG_FILTER_PARAM_SHIFT        ((uint32)2U)

#define ICU_EMIOS_BUS_SELECT_PARAM_MASK         ((uint32)(BIT1|BIT0))
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_BUS_SELECT_PARAM_SHIFT        ((uint32)0U)
/**@}*/

/**
* @{
* @brief Used for identifying the not configured channels
*/
#define ICU_INDEX_NULL                          0xFFU
/**@}*/

/**
 * @{
 * @brief   Macros for handling the actual states of the ICU Channels
 * @remarks These bitfields are used to set Icu_ChannelState array
*/


/**
* @{
* @brief Wakeup feature is currently enabled
*/
#define ICU_CHANNEL_STATE_WKUP                  ((Icu_ChannelStateType)BIT0)
#define ICU_CHANNEL_STATE_WKUP_SHIFT            0U
#define ICU_CHANNEL_STATE_WKUP_MASK             ((Icu_ChannelStateType)BIT0)
/**@}*/

/**
* @{
* @brief The current channel status - IDLE / ACTIVE
*/
#define ICU_CHANNEL_STATE_IDLE                  ((Icu_ChannelStateType)BIT1)
#define ICU_CHANNEL_STATE_IDLE_SHIFT            1U
#define ICU_CHANNEL_STATE_IDLE_MASK             ((Icu_ChannelStateType)BIT1)
/**@}*/

/**
* @{
* @brief Notification is enabled
*/
#define ICU_CHANNEL_STATE_NOTIFICATION          ((Icu_ChannelStateType)BIT2)
#define ICU_CHANNEL_STATE_NOTIF_SHIFT           2U
#define ICU_CHANNEL_STATE_NOTIF_MASK            ((Icu_ChannelStateType)BIT2)
/**@}*/

/**
* @{
* @brief The current channel state
*/
#define ICU_CHANNEL_STATE_RUNNING               ((Icu_ChannelStateType)BIT3)
#define ICU_CHANNEL_STATE_RUNNING_SHIFT         3U
#define ICU_CHANNEL_STATE_RUNNING_MASK          ((Icu_ChannelStateType)BIT3)
/**@}*/

/**
* @{
* @brief Overflow flag
*/
#define ICU_CHANNEL_STATE_OVERFLOW              ((Icu_ChannelStateType)BIT4)
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_CHANNEL_STATE_OVERFLOW_SHIFT        4U
#define ICU_CHANNEL_STATE_OVERFLOW_MASK         ((Icu_ChannelStateType)BIT4)
/**@}*/

/**
* @{
* @brief Rising edge
*/
#define ICU_CHANNEL_STATE_RISING                ((Icu_ChannelStateType)BIT5)
#define ICU_CHANNEL_STATE_RISING_SHIFT          5U
#define ICU_CHANNEL_STATE_RISING_MASK           ((Icu_ChannelStateType)BIT5)
/**@}*/

/**
* @{
* @brief Falling edge
*/
#define ICU_CHANNEL_STATE_FALLING               ((Icu_ChannelStateType)BIT6)
#define ICU_CHANNEL_STATE_FALLING_SHIFT         6U
#define ICU_CHANNEL_STATE_FALLING_MASK          ((Icu_ChannelStateType)BIT6)
/**@}*/

/**
* @{
* @brief Both edges
*/
#define ICU_CHANNEL_STATE_BOTH_EDGES            ((Icu_ChannelStateType)(BIT6|BIT5))
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_CHANNEL_STATE_BOTH_EDGES_SHIFT      5U
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_CHANNEL_STATE_BOTH_EDGES_MASK       ((Icu_ChannelStateType)(BIT6|BIT5))
/**@}*/

/**
 * @{
 * @brief Wakeup source
*/
#define ICU_CHANNEL_IS_WAKEUP_SOURCE            ((Icu_ChannelStateType)BIT7)
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_CHANNEL_IS_WAKEUP_SOURCE_SHIFT      7U
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_CHANNEL_IS_WAKEUP_SOURCE_MASK       ((Icu_ChannelStateType)BIT7)
/**@}*/

/**@}*/
#if ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON))
#if (ICU_DMA_SUPPORTED == STD_ON)

#define ICU_DMA_UPDATE_DLAST_SGA  0x80000000U
#define  ICU_DMA_MAJORLOOP_COUNT     ((uint8)4U)
/*
 * @violates @ref Icu_LLD_h_REF_1 Function-like macro defined
 */
#define ICU_LLM_READ_MAJORCOUNT_CITER(Channel) (REG_READ16(DMA_TCD5_CITER(Channel)) & 0x7FFFU )
/*
 * @violates @ref Icu_LLD_h_REF_1 Function-like macro defined
 */
#define ICU_LLM_READ_MAJORCOUNT_BITER(Channel) (REG_READ16(DMA_TCD7_BITER(Channel)) & 0x7FFFU )
#endif
#endif
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*================================================================================================*/
/**
* @brief   ICU Channel state type
*
* @implements     DICU02024
*/
/*================================================================================================*/
typedef uint8 Icu_ChannelStateType;

#if (ICU_DMA_SUPPORTED == (STD_ON))
typedef uint16 Icu_Dmabuffertype;
#endif

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#ifdef ICU_PRECOMPILE_SUPPORT
/**
* @brief External declaration of the ICU configuration structure for pre-compiled mode
*/

/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Icu_LLD_h_REF_2 Precautions shall be taken in order to prevent the contents of a
* header file being included twice
*/
#include "MemMap.h"

/*
* @violates @ref Icu_LLD_h_REF_6 Objects shall be defined at block scope if they are only accessed
* from within a single function
*/

extern CONST(Icu_ConfigType, ICU_CONST) Icu_Configs_PC;

/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Icu_LLD_h_REF_2 Precautions shall be taken in order to prevent the contents of a
* header file being included twice
*/
#include "MemMap.h"

#endif  /* ICU_PRECOMPILE_SUPPORT */

/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Icu_LLD_h_REF_2 Precautions shall be taken in order to prevent the contents of a
* header file being included twice
*/
#include "MemMap.h"
/**
* @brief Pointer initialized during init with the address of the received configuration structure.
* @details Will be used by all functions to access the configuration data.
*
* @implements DICU01213
*/
extern P2CONST(Icu_ConfigType, ICU_VAR, ICU_APPL_CONST) Icu_Cfg_Ptr;
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
#define ICU_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Icu_LLD_h_REF_2 Precautions shall be taken in order to prevent the contents of a
* header file being included twice
*/
#include "MemMap.h"



/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
/*
* @violates @ref Icu_LLD_h_REF_2 Precautions shall be taken in order to prevent the contents of a
* header file being included twice
*/
#include "MemMap.h"
/*================================================================================================*/
/**
* @brief      Icu driver function that initializes the ICU hardware channel.
* @details    This function initializes a hardware ICU channel
*
* @param[in]  tempPtr     - Pointer to configuration structure
* @param[in]  numChl      - The index of ICU channel for current configuration structure
* @param[in]  msChannel   - This index relates the Icu Channel number with the respective global
*                           variable, depending on the measurement mode. Each kind of measurement
*                           mode has an array(s) in the ICU driver, this index points to the
*                           corresponding variable within the ICU channel.
*/
/*================================================================================================*/
#if ((ICU_TIMESTAMP_API == STD_ON) || (ICU_EDGE_COUNT_API == STD_ON))
FUNC (void, ICU_CODE) Icu_LLD_InitChannel(P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) tempPtr,
                                          VAR(Icu_ChannelType, AUTOMATIC) numChl,
                                          CONST(Icu_ChannelType, AUTOMATIC) msChannel);
#else
FUNC (void, ICU_CODE) Icu_LLD_InitChannel(
                                  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) tempPtr,
                                  VAR(Icu_ChannelType, AUTOMATIC) numChl);
#endif
/*================================================================================================*/
/**
* @brief      Icu driver function that de-initializes the ICU hardware channel.
* @details    This function de-initializes the ICU hardware channel.
*
* @param[in]  numChl - The index of ICU channel for current configuration structure
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_DeInitChannel(VAR(Icu_ChannelType, AUTOMATIC) numChl);

#if (ICU_SET_MODE_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu driver function that sets the ICU hardware channel into sleep mode.
* @details    This function sets the ICU hardware channels (eMIOS, SIUL or WKUP) into SLEEP mode
*
* @param[in]  numChl - The index of ICU channel for current configuration structure
* @param[in]  active - ICU channel is active during SLEEP mode (wakeup was enabled)
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_SetSleepMode(VAR(Icu_ChannelType, AUTOMATIC) numChl,
                                           VAR(boolean, AUTOMATIC) active);

/*================================================================================================*/
/**
* @brief      Icu driver function that sets the ICU hardware channel into NORMAL mode.
* @details    This function sets the ICU hardware channels (eMIOS, SIUL or WKUP) into NORMAL mode,
*             Enables the notification for the channel.
*
* @param[in]  numChl - The index of ICU channel for current configuration structure
* @param[in]  active - ICU channel is active during NORMAL mode (notification was enabled)
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_SetNormalMode(VAR(Icu_ChannelType, AUTOMATIC) numChl,
                                            VAR(boolean, AUTOMATIC) active);

#endif  /* ICU_SET_MODE_API == STD_ON */

#if (ICU_DISABLE_WAKEUP_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu driver function that disables the wakeup for channel.
* @details    This function disables wakeup for ICU hardware channels.
* @param[in]  numChl - The index of ICU channel for current configuration structure
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_DisableWakeup(VAR(Icu_ChannelType, AUTOMATIC) numChl);
#endif  /* ICU_DISABLE_WAKEUP_API == STD_ON */

#if (ICU_ENABLE_WAKEUP_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu driver function that enables the wakeup for channel.
* @details    This function enables wakeup for ICU hardware channels.
*
* @param[in]  numChl - The index of ICU channel for current configuration structure
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_EnableWakeup(VAR(Icu_ChannelType, AUTOMATIC) numChl);
#endif  /* ICU_ENABLE_WAKEUP_API == STD_ON */

/*================================================================================================*/
/**
* @brief      Icu driver function that sets activation conditiond for channel with requested
*             activation type.
* @details    This function sets the requested Activation for the channels (eMIOS, SIUL or WKUP)
*
* @param[in]  numChl     - The index of ICU channel for current configuration structure
* @param[in]  Activation - the type of activation for the ICU channel.
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_SetActivationCondition(VAR(Icu_ChannelType, AUTOMATIC) numChl,
                                                     VAR(Icu_ActivationType, AUTOMATIC) Activation);

/*================================================================================================*/
/**
* @brief      Icu driver function that disables the notification for channel.
* @details    This function disables notification for an ICU Hardware Channel.
*             For disabling notification, for some ICU channels, the interrupt
*             for the channel must be also disabled
*
* @param[in]  numChl - The index of ICU channel for current configuration structure
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_DisableNotification(VAR(Icu_ChannelType, AUTOMATIC) numChl);

/*================================================================================================*/
/**
* @brief      Icu driver function that enables the notification for channel.
* @details    This function enables notification for an ICU Hardware Channel.
*             For enabling notifications for some ICU channels, the interrupt
*             for the channel must be also re-enabled
*
* @param[in]  numChl - The index of ICU channel for current configuration structure
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_EnableNotification(VAR(Icu_ChannelType, AUTOMATIC) numChl);

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu driver function that gets the input state of ICU hardware channel.
* @details    This function gets the state of ICU channel (eMIOS, SIUL or WKUP)
*
* @param[in]  numChl - The index of ICU channel for current configuration structure
*
* @return     Icu_InputStateType
*              - ICU_ACTIVE - An activation edge has been detected
*              - ICU_IDLE - No activation edge has been detected.
*/
/*================================================================================================*/
FUNC (Icu_InputStateType, ICU_CODE) Icu_LLD_GetInputState(VAR(Icu_ChannelType, AUTOMATIC) numChl);

#endif  /* ICU_GET_INPUT_STATE_API == STD_ON */

#if (ICU_TIMESTAMP_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu driver function that starts the time stamp of ICU hardware channel.
* @details    This function starts the time stamp measurement of ICU channel.
*
* @param[in]  numChl - The index of ICU channel for current configuration structure
* @param[in]  msChannel - The index of Logical ICU channel
* @param[in]  BufferPtr - Pointer to the buffer
* @param[in]  BufferSize - Size of buffer
* @param[in]  NotifyInterval - Notification interval time
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_StartTimestamp(VAR(Icu_ChannelType, AUTOMATIC) numChl,
                                             CONST(Icu_ChannelType, AUTOMATIC) msChannel,
                                             P2VAR(Icu_ValueType, AUTOMATIC, ICU_APPL_DATA) BufferPtr,
                                             VAR(uint16, AUTOMATIC) BufferSize,
                                             VAR(uint16, AUTOMATIC) NotifyInterval);

/*================================================================================================*/
/**
* @brief      Icu driver function that stops the time stamp of ICU hardware channel.
* @details    This function stops the time stamp measurement of ICU channel.
*
* @param[in]  numChl - The index of ICU channel for current configuration structure
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_StopTimestamp(VAR(Icu_ChannelType, AUTOMATIC) numChl);

/*================================================================================================*/
/**
* @brief      Icu driver function that gets the time stamp index of ICU logical channel.
* @details    This function gets the time stamp measurement index of ICU logical channel.
*             If Buffer pointer of channel is NULL_PTR then it returns value as 0 else
*             it returns the value of time stamp index.
*
* @param[in]  msChannel - The index of ICU channel for current configuration structure
*
* @return     Icu_IndexType - Timestamp index
*/
/*================================================================================================*/
#if (ICU_DMA_SUPPORTED == STD_ON)
FUNC (Icu_IndexType, ICU_CODE) Icu_LLD_GetTimestampIndex(
                                                      CONST(Icu_ChannelType, AUTOMATIC) msChannel,
                                                      VAR(Icu_ChannelType, AUTOMATIC) Channel);
#else
FUNC (Icu_IndexType, ICU_CODE) Icu_LLD_GetTimestampIndex(CONST(Icu_ChannelType, AUTOMATIC) msChannel);
#endif
#endif
/* ICU_TIMESTAMP_API == STD_ON */
#if ((ICU_SET_MODE_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON) || (ICU_EDGE_COUNT_API == STD_ON))

/*================================================================================================*/
/**
* @brief      Icu driver function that gets the status of ICU hardware channel.
* @details    This function returns TRUE if channel is running else returns FALSE.
*
* @param[in]  numChl - The index of ICU channel for current configuration structure
*
* @return     boolean
*              - true - if the given channel is running
*              - false - if the channel is in idle state
*/
/*================================================================================================*/
FUNC (boolean, ICU_CODE) Icu_LLD_Channel_Get_Status(VAR(Icu_ChannelType, AUTOMATIC) numChl);
#endif 
/*((ICU_SET_MODE_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON) || (ICU_EDGE_COUNT_API == STD_ON))*/


#if (ICU_EDGE_COUNT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu driver function that resets the edge counter measurement of ICU channel.
* @details    This function:
*              - Clears the overflow flag
*              - Resets the edge counter measurement of ICU hardware channel
*
* @param[in]  numChl - The index of ICU channel for current configuration structure
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_ResetEdgeCount(VAR(Icu_ChannelType, AUTOMATIC) numChl);

/*================================================================================================*/
/**
* @brief      Icu driver function that enables the edge counter measurement of ICU channel.
* @details    This function enables the edge counter measurement of ICU hardware channel
*
* @param[in]  numChl - The index of ICU channel for current configuration structure
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_EnableEdgeCount(VAR(Icu_ChannelType, AUTOMATIC) numChl);

/*================================================================================================*/
/**
* @brief      Icu driver function that disables the edge counter measurement of ICU channel.
* @details    This function disables the edge counter measurement of ICU hardware channel
*
* @param[in]  numChl - The index of ICU channel for current configuration structure
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_DisableEdgeCount(VAR(Icu_ChannelType, AUTOMATIC) numChl);

/*================================================================================================*/
/**
* @brief      Icu driver function that gets edge counter measurement of ICU channel.
* @details    his function returns counter value (the number of counter edges) of ICU channel
*
* @param[in]  numChl - The index of ICU channel for current configuration structure
*
* @return     Icu_EdgeNumberType - Counted edges number
*/
/*================================================================================================*/
FUNC (Icu_EdgeNumberType, ICU_CODE) Icu_LLD_GetEdgeNumbers(VAR(Icu_ChannelType, AUTOMATIC) numChl);
#endif  /* ICU_EDGE_COUNT_API == STD_ON */

/*================================================================================================*/
/**
 * @brief      Icu driver function that enables edge detection.
 * @details    Icu driver function that enables edge detection using the ip low level driver
 * @param[in]      numChl - The index of ICU channel for current configuration structure
 * @return         void
*/
/*================================================================================================*/
#if (ICU_EDGE_DETECT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_LLD_EnableEdgeDetection(VAR(Icu_ChannelType, AUTOMATIC) numChl);
#endif /* ICU_EDGE_DETECT_API */

/*================================================================================================*/
/**
 * @brief      Icu driver function that disables edge detection.
 * @details    Icu driver function that enables edge detection using the ip low level driver
 * @param[in]      numChl - The index of ICU channel for current configuration structure
 * @return         void
*/
/*================================================================================================*/
#if (ICU_EDGE_DETECT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_LLD_DisableEdgeDetection(VAR(Icu_ChannelType, AUTOMATIC) numChl);
#endif /* ICU_EDGE_DETECT_API */


/*================================================================================================*/
/**
 * @brief          Icu_LLD_CheckWakeup
 * @details        Checks if a wakeup capable ICU channel is the source for a wakeup event.
 *
 * @param[in]      WakeupSource - Informatin on wakeup source to be checked. The associated ICU 
 *                 channel can be determined from configuration data.
 *
 * @return         void
 *
 * @implements     DICU020041
*/
/*================================================================================================*/
#if ((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON) && (ICU_REPORT_WAKEUP_SOURCE == STD_ON) && \
 (ICU_ENABLE_WAKEUP_API == STD_ON))
FUNC (void, ICU_CODE) Icu_LLD_CheckWakeup( VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource );
#endif /* ICU_WAKEUP_FUNCTIONALITY_API && ICU_REPORT_WAKEUP_SOURCE  &&  ICU_ENABLE_WAKEUP_API */

#if ((ICU_EDGE_COUNT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON) || \
     (ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) )
/*================================================================================================*/
/**
* @brief      Icu driver function that checks overflow flag status of ICU channel
* @details    This function returns the overflow status for the given channel and
*             resets the channel status flag
*
* @param[in]  numChl - The index of ICU channel for current configuration structure
*
* @return     boolean
*              - true - if an overflow event occurred for the given channel
*              - false - if no overflow event occurred for the given channel
*/
/*================================================================================================*/
FUNC (boolean, ICU_CODE) Icu_LLD_Get_Overflow(VAR(Icu_ChannelType, AUTOMATIC) numChl);

#endif  /* ICU_EDGE_COUNT_API == STD_ON */

#if (ICU_DUAL_CLOCK_MODE == STD_ON)
/*================================================================================================*/
/**
 * @brief      This function changes the channel prescaler.
 * @details    This function sets all channels prescalers based on the input mode.
 *
 * @param[in]  tempPtr   - Pointer to configuration structure
 * @param[in]  numChl    - The index of ICU channel for current configuration structure
 * @param[in]  Prescaler - Prescaler type ( Normal or Alternate )
 *
 * @return void
 *
 * @violates @ref Icu_LLD_c_REF_4 MISRA-C:2004 17.4: Array indexing shall be the only allowed form
 *             of pointer arithmetic.
 *
 * @implements DICU02015
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_SelectPrescaler(
                                 P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) tempPtr,
                                 VAR(Icu_ChannelType, AUTOMATIC) numChl,
                                 VAR(Icu_SelectPrescalerType, AUTOMATIC) Prescaler);
/* ICU_DUAL_CLOCK_MODE == STD_ON */
#endif

/*================================================================================================*/
/**
* @brief      This function returns the actual status of PIN.

* @details    This function returns the actual status of PIN .
*
* @param[in]     Channel          Numeric identifier of the ICU channel
*
* @return  void
*
* @pre        Icu_Init must be called before.
*
* @implements DICU02702
*/
/*================================================================================================*/

FUNC (boolean, ICU_CODE) Icu_LLD_GetInputLevel(VAR(Icu_ChannelType, AUTOMATIC) numChl);


#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu driver function that starts the signal measurement of ICU channel.
* @details    This function:
*             - Configures the Activation type depends on tempProperty value
*             - starts the signal measurement of ICU channel.
*
*
* @param[in]  tempPtr - Buffer pointer
* @param[in]  hwChannel - ICU hardware channel number
* @param[in]  tempProperty - Time measurement type (HIGH or LOW)
* @param[in]  msChannel - The index of ICU logical channel
* @param[in]  numChl - The index of ICU channel for current configuration structure
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_StartSignalMeasurement(P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) tempPtr,
                                                     CONST(Icu_ChannelType, AUTOMATIC) hwChannel,
                                                     VAR(Icu_ParamType, AUTOMATIC) tempProperty,
                                                     CONST(Icu_ChannelType, AUTOMATIC) msChannel,
                                                     VAR(Icu_ChannelType, AUTOMATIC) numChl);

/*================================================================================================*/
/**
* @brief      Icu driver function that stops the signal measurement of ICU channel.
* @details    This function stops the signal measurement of ICU channel.
*
* @param[in]  numChl - The index of ICU channel for current configuration structure
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_StopSignalMeasurement(VAR(Icu_ChannelType, AUTOMATIC) numChl);

#endif  /* ICU_SIGNAL_MEASUREMENT_API == STD_ON */

#if (ICU_GET_PULSE_WIDTH_API == STD_ON)
/*================================================================================================*/
/**
 @brief      This function returns the signals High time, Low time and Period without using the 
                    channel interrupt.
 @details    This function returns the signals High time, Low time and Period without using the 
                    channel interrupt.
 @param[in]     Channel          Numeric identifier of the ICU channel
 @pre        Icu_Init must be called before.
 @implements DICU02420
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_GetPulseWidth(VAR(Icu_ChannelType, AUTOMATIC) numChl);
#endif

/*================================================================================================*/
/**
* @brief      Icu driver function that handles the interrupt of ICU channel.
* @details    Interrupt function  that may  jump to  the WakeUp  function (Depending  on the  selected
*             configuration)  and branches  to the  proper actions  depending the  mode in  which the
*             channel is operating.
*
* @param[in]  numChl - ICU logical channel
* @param[in]  flags  - Interrupts Status Flags
*
* @remarks    Covers ICU020, ICU021, ICU055, ICU056, ICU057
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_ProcessCommonInterrupt(VAR(Icu_ChannelType, AUTOMATIC) numChl,  \
                                                     VAR(uint32, AUTOMATIC) flags);

/*================================================================================================*/
/**
 * @brief      Icu driver function that clears the input state of ICU channel.
 * @details    This function clears the input state of ICU channel used in
 *              signal measurement mode
 *
 * @param[in]  numChl - The index of ICU channel for current configuration structure
 *
 *@implements  DICU02416
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_LLD_ClearActiveState(VAR(Icu_ChannelType, AUTOMATIC) numChl);
/*================================================================================================*/
/**
 @brief      The function enables pull up for not configured and unavailable Wakeup pins.
 @details    The function enables pull up for not configured and unavailable Wakeup pins.
 @param[in]    None
*/
/*================================================================================================*/
/*
* @violates @ref Icu_LLD_h_REF_4 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_LLD_PullUpNonBondedWakeupPin(void);

#if (ICU_CAPTURERGISTER_API == STD_ON)
/*================================================================================================*/
/**
 @brief  This service Returns the current value of Register A. This API is used when user wants to 
         know the time difference between 2 channels.
*/
/*================================================================================================*/
FUNC (Icu_ValueType, ICU_CODE)   Icu_LLD_GetCaptureRegisterValue(VAR(Icu_ChannelType,  \
                                                                      AUTOMATIC) Channel);
#endif
#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_LLD_h_REF_2 Precautions shall be taken in order to prevent the contents of a
* header file being included twice
*/
#include "MemMap.h"
#ifdef __cplusplus
}
#endif

#endif  /* ICU_LLD_H */
/**@}*/
