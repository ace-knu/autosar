/**
*   @file    Wdg_Swt_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Wdg - Software Watchdog Timer (SWT) Registers
*   @details Contains information about the SWT's registers
*
*   @addtogroup  Wdg
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : Swt
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF12_ASR_REL_4_0_REV_0003_20161209
*
*   (c) Copyright 2006-2016 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef WDG_SWT_LLD_H
#define WDG_SWT_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Wdg_Swt_LLD_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the contents 
* of a header file being included twice.
* Required by the Autosar specification.Needed for different code sections definition.
*
* @section Wdg_Swt_LLD_h_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Wdg_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_SWT_LLD_VENDOR_ID                       43
/*
* @violates @ref Wdg_Swt_LLD_h_REF_2 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define WDG_SWT_LLD_AR_RELEASE_MAJOR_VERSION        4
/*
* @violates @ref Wdg_Swt_LLD_h_REF_2 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define WDG_SWT_LLD_AR_RELEASE_MINOR_VERSION        0
/*
* @violates @ref Wdg_Swt_LLD_h_REF_2 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define WDG_SWT_LLD_AR_RELEASE_REVISION_VERSION     3
#define WDG_SWT_LLD_SW_MAJOR_VERSION                1
#define WDG_SWT_LLD_SW_MINOR_VERSION                0
#define WDG_SWT_LLD_SW_PATCH_VERSION                1

/*==================================================================================================
*                                    FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Std_Types header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((WDG_SWT_LLD_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_SWT_LLD_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Wdg_Swt_LLD.h and Std_Types.h are different"
#endif
#endif
/* Check if current file and Wdg_Cfg header file are of the same vendor */
#if (WDG_SWT_LLD_VENDOR_ID != WDG_VENDOR_ID_CFG)
    #error "Wdg_Swt_LLD.h and Wdg_Cfg.h have different vendor ids"
#endif

/* Check if source file and Wdg_Cfg header file are of the same Autosar version */
#if ((WDG_SWT_LLD_AR_RELEASE_MAJOR_VERSION    != WDG_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (WDG_SWT_LLD_AR_RELEASE_MINOR_VERSION    != WDG_AR_RELEASE_MINOR_VERSION_CFG) || \
     (WDG_SWT_LLD_AR_RELEASE_REVISION_VERSION != WDG_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Wdg_Swt_LLD.h and Wdg_Cfg.h are different"
#endif

/* Check if source file and Wdg_Cfg header file are of the same Software version */
#if ((WDG_SWT_LLD_SW_MAJOR_VERSION != WDG_SW_MAJOR_VERSION_CFG) || \
     (WDG_SWT_LLD_SW_MINOR_VERSION != WDG_SW_MINOR_VERSION_CFG) || \
     (WDG_SWT_LLD_SW_PATCH_VERSION != WDG_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Wdg_Swt_LLD.h and Wdg_Cfg.h are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else 
#define WDG_START_SEC_RAMCODE
#endif

/*
* @violates @ref Wdg_Swt_LLD_h_REF_1 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order 
* to prevent the contents of a header file being included twice.
*/
#include "MemMap.h"

FUNC(Std_ReturnType, WDG_CODE) Wdg_SWT_Init(P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr,
                                               CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance);

FUNC(Std_ReturnType, WDG_CODE) Wdg_SWT_SetMode(CONST(WdgIf_ModeType, AUTOMATIC) Mode,
                                               CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance);

FUNC(void, WDG_CODE) Wdg_SWT_Trigger(CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance);

FUNC(Std_ReturnType, WDG_CODE) Wdg_SWT_CheckModeSettings(CONST(WdgIf_ModeType, AUTOMATIC) Mode,
                                               CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance);
FUNC(Std_ReturnType, WDG_CODE)
     Wdg_SWT_CheckInitSettings(P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr);

#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else 
#define WDG_STOP_SEC_RAMCODE
#endif

/*
* @violates @ref Wdg_Swt_LLD_h_REF_1 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order 
* to prevent the contents of a header file being included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* WDG_SWT_LLD_H */

/** @} */
