/**
* @file    Wdg_Cbk.h
* @version 1.0.1
* @brief   AUTOSAR Wdg - Software Watchdog Timer (SWT) Registers
* @details Contains information about the SWT's registers
*
* @addtogroup  Wdg
* @{
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

#ifndef WDG_CBK_H
#define WDG_CBK_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Wdg_Cbk_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the contents 
* of a header file being included twice.
* Required by the Autosar specification.Needed for different code sections definition.
* @section Wdg_Cbk_h_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Wdg_Cfg.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_CBK_VENDOR_ID                    43
/* @violates @ref Wdg_Cbk_h_REF_2 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_CBK_AR_RELEASE_MAJOR_VERSION     4
/* @violates @ref Wdg_Cbk_h_REF_2 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_CBK_AR_RELEASE_MINOR_VERSION     0
/* @violates @ref Wdg_Cbk_h_REF_2 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_CBK_AR_RELEASE_REVISION_VERSION  3
#define WDG_CBK_SW_MAJOR_VERSION             1
#define WDG_CBK_SW_MINOR_VERSION             0
#define WDG_CBK_SW_PATCH_VERSION             1

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
*                                            ENUMS
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

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else 
#define WDG_START_SEC_RAMCODE
#endif

/*
* @violates @ref Wdg_Cbk_h_REF_1 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice.
*/
#include "MemMap.h"

#if (WDG_INSTANCE0 == STD_ON)
FUNC(void,WDG_CODE)  Wdg_Cbk_GptNotification0(void);
#endif

#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else 
#define WDG_STOP_SEC_RAMCODE
#endif

/*
* @violates @ref Wdg_Cbk_h_REF_1 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*WDG_CBK_H*/
/** @} */
