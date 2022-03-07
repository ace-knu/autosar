/**
*   @file    EcuM.c
*   @version 1.0.1
*
*   @brief   AUTOSAR EcuM - module implementation.
*   @details This module implements stubs for the AUTOSAR EcuM
*            This file contains sample code only. It is not part of the production code deliverables
*
*   @addtogroup ECUM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : 
*   Dependencies         : 
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
extern "C" {
#endif
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"

#ifdef TEST_CAN
#include "CanIf.h"
#endif
#include "EcuM.h"
#ifdef TEST_GPT
#include "Gpt.h"
#include "Gpt_TestNotifications.h"
#endif
#ifdef TEST_LIN
#include "LinIf.h"
#endif
#ifdef TEST_ICU
#include "Icu_test_ext_common.h"
#endif

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
#define ECUM_VENDOR_ID_C        43
#define ECUM_AR_RELEASE_MAJOR_VERSION_C 4
#define ECUM_AR_RELEASE_MINOR_VERSION_C 0
#define ECUM_AR_RELEASE_REVISION_VERSION_C 3
#define ECUM_SW_MAJOR_VERSION_C 1
#define ECUM_SW_MINOR_VERSION_C 0
#define ECUM_SW_PATCH_VERSION_C 1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ECUM header file are of the same vendor */
#if (ECUM_VENDOR_ID_C != ECUM_VENDOR_ID)
    #error "EcuM.c and EcuM.h have different vendor ids"
#endif

/* Check if source file and ECUM header file are of the same Autosar version */

#if ((ECUM_AR_RELEASE_MAJOR_VERSION_C != ECUM_AR_RELEASE_MAJOR_VERSION) || \
     (ECUM_AR_RELEASE_MINOR_VERSION_C != ECUM_AR_RELEASE_MINOR_VERSION) || \
     (ECUM_AR_RELEASE_REVISION_VERSION_C != ECUM_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of EcuM.c and EcuM.h are different"
#endif

/* Check if source file and ECUM header file are of the same Software version */
#if ((ECUM_SW_MAJOR_VERSION_C != ECUM_SW_MAJOR_VERSION) || \
     (ECUM_SW_MINOR_VERSION_C != ECUM_SW_MINOR_VERSION) || \
     (ECUM_SW_PATCH_VERSION_C != ECUM_SW_PATCH_VERSION))
    #error "Software Version Numbers of EcuM.c and EcuM.h are different"
#endif

#ifdef TEST_CAN
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Can header file are of the same version */
#if ((ECUM_AR_RELEASE_MAJOR_VERSION_C != CANIF_AR_RELEASE_MAJOR_VERSION) || \
     (ECUM_AR_RELEASE_MINOR_VERSION_C != CANIF_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of EcuM.c and CanIf.h are different"
#endif
#endif
#endif

#ifdef TEST_GPT
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Gpt header file are of the same version */
#if ((ECUM_AR_RELEASE_MAJOR_VERSION_C != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (ECUM_AR_RELEASE_MINOR_VERSION_C != GPT_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of EcuM.c and Gpt.h are different"
#endif
#endif
#endif

#ifdef TEST_LIN
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Lin header file are of the same version */
#if ((ECUM_AR_RELEASE_MAJOR_VERSION_C != LIN_IF_AR_RELEASE_MAJOR_VERSION_CBK) || \
     (ECUM_AR_RELEASE_MINOR_VERSION_C != LIN_IF_AR_RELEASE_MINOR_VERSION_CBK))
    #error "AutoSar Version Numbers of EcuM.c and LinIf.h are different"
#endif
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Std_Types header file are of the same version */
#if ((ECUM_AR_RELEASE_MAJOR_VERSION_C  != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ECUM_AR_RELEASE_MINOR_VERSION_C != STD_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of EcuM.c and Std_Types.h are different"
#endif
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
/* put all ECUM variables into defined sections */
#define ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

VAR(EcuM_WakeupSourceType, ECUM_VAR) EcuMLastWakeupEvent; /**< @brief last wakeup event to EcuM (source ID)*/

#define ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/* put all ECUM code into defined sections */
#define ECUM_START_SEC_CODE
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief   This function sets the last wakeup event of the ECUM.
* @details This is a function stub only.
* 
* @param[in]     events  last wakeup event
* 
*/
FUNC(void, ECUM_CODE) EcuM_SetWakeupEvent(VAR(EcuM_WakeupSourceType, AUTOMATIC) events)
{
    EcuMLastWakeupEvent = events;
}

/*================================================================================================*/
/**
* @brief   This function validates the wakeup event.
* @details This is a function stub only. Functionality is void in this implementation
* 
* @param[in]     events wakeup event to validate
*/
FUNC(void, ECUM_CODE) EcuM_ValidateWakeupEvent(VAR(EcuM_WakeupSourceType, AUTOMATIC) events)
{

}

/*================================================================================================*/
/**
* @brief   This function checks the wakeup source against possible sources of wakeup.
* @details This is a function stub only. It calls the wakeup interfaces of CANIf, GPT and LIN with the wakeupSource parameter.
* 
* @param[in]     wakeupSource  wakeup source ID
* 
*/
FUNC(void, ECUM_CODE) EcuM_CheckWakeup(VAR(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource)
{
#ifdef TEST_CAN
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
    CanIf_CheckWakeup(wakeupSource);
#endif
#endif
#ifdef TEST_GPT
    Gpt_Cbk_CheckWakeup(wakeupSource);
#endif
#ifdef TEST_LIN
    LinIf_Cbk_CheckWakeup(wakeupSource);
#endif
#ifdef TEST_ICU
    Icu_TE_Cbk_CheckWakeup(wakeupSource);
#endif
}

#define ECUM_STOP_SEC_CODE
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file */

/** @} */
