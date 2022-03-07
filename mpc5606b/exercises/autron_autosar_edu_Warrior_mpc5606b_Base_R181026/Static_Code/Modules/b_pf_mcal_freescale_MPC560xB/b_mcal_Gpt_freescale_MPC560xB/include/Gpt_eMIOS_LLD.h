/**
*   @file    Gpt_eMIOS_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS_Stm_Pit_Rtc
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

#ifndef GPT_EMIOS_LLD_H
#define GPT_EMIOS_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
* 
*
* @section Gpt_eMIOS_LLD_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, : Use of function like macro.
* This vioaltion is due to function like macro defined for register operations.
* Function like macro are used to reduce code complexity.
*
* @section Gpt_eMIOS_LLD_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, : Repeated include file
* This violation  is not  fixed since  the inclusion  of MemMap.h  is as  per Autosar  requirement
* MEMMAP003.
*
* @section Gpt_eMIOS_LLD_H_REF_3
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
* @section Gpt_eMIOS_LLD_H_REF_4
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Gpt_eMIOS_LLD_H_REF_2 Repeated include file 
*/
#include "Std_Types.h"
/*
* @violates @ref Gpt_eMIOS_LLD_H_REF_2 Repeated include file 
*/
#include "modules.h"
/*
* @violates @ref Gpt_eMIOS_LLD_H_REF_2 Repeated include file 
*/
#include "Gpt.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @implements     DGPT07500 */
#define GPT_EMIOS_LLD_H_VENDOR_ID                       43
#define GPT_EMIOS_LLD_H_MODULE_ID                       100
/* @violates @ref Gpt_eMIOS_LLD_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION        4
/* @violates @ref Gpt_eMIOS_LLD_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION        0
/* @violates @ref Gpt_eMIOS_LLD_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_EMIOS_LLD_H_AR_RELEASE_REVISION_VERSION     3
/* @violates @ref Gpt_eMIOS_LLD_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_EMIOS_LLD_H_SW_MAJOR_VERSION                1
/* @violates @ref Gpt_eMIOS_LLD_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_EMIOS_LLD_H_SW_MINOR_VERSION                0
/* @violates @ref Gpt_eMIOS_LLD_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_EMIOS_LLD_H_SW_PATCH_VERSION                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((GPT_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Gpt_eMIOS_LLD.h and Std_Types.h are different"
    #endif

    /* Check if header file and modules.h file are of the same Autosar version */
    #if ((GPT_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION != MODULES_AR_RELEASE_MAJOR_VERSION_H) || \
         (GPT_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION != MODULES_AR_RELEASE_MINOR_VERSION_H))
         #error "AutoSar Version Numbers of Gpt_eMIOS_LLD.h and modules.h are different"
    #endif
#endif

/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_EMIOS_LLD_H_AR_RELEASE_REVISION_VERSION != GPT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_eMIOS_LLD.h and Gpt.h are different"
#endif

/* Check if source file and Gpt header file are of the same software version */
#if ((GPT_EMIOS_LLD_H_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION) || \
     (GPT_EMIOS_LLD_H_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION) || \
     (GPT_EMIOS_LLD_H_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_eMIOS_LLD.h and Gpt.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#if (GPT_DEV_ERROR_DETECT == STD_ON)

/**
* @brief        Emios specific macro for checking the timeout value.
*
* @param[in]    value     Timeout vaule
*
* @return       Boolean
* @retval       TRUE - Time out value is valid
* @retval       FALSE - Time out value is Invalid
*
* @implements   DGPT07213
*/
/*
* @violates @ref Gpt_eMIOS_LLD_H_REF_1 Use of function like macro 
*/
/* @violates @ref Gpt_eMIOS_LLD_H_REF_4 This is not a standard library macro. */
#define EMIOS_LLD_INVALID_TIMEOUT_VALUE(value)    ((value) > (Gpt_ValueType)EMIOS_EMIOSCNT_MAX_VALUE)

#endif

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

#define GPT_START_SEC_CODE
/*
* @violates @ref Gpt_eMIOS_LLD_H_REF_2 Repeated include file MemMap.h 
*/
#include "MemMap.h"

FUNC (void, GPT_CODE) Emios_LLD_InitChannel(
        VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
        VAR(Gpt_PrescaleType, AUTOMATIC) channelPrescale,
        VAR(boolean, AUTOMATIC) freezeEnable
    );

#if (GPT_DEINIT_API == STD_ON)
FUNC (void, GPT_CODE) Emios_LLD_DeInit(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel);
#endif /* GPT_DEINIT_API */

FUNC (void, GPT_CODE) Emios_LLD_StartTimer(
        VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
        VAR(Gpt_ValueType, AUTOMATIC) value,
        VAR(Gpt_ChannelModeType, AUTOMATIC) channelMode
    );

FUNC (void, GPT_CODE) Emios_LLD_StopTimer(
        VAR(Gpt_ChannelType, AUTOMATIC) hwChannel, 
        P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr
    );

#if ((GPT_TIME_ELAPSED_API == STD_ON) || (GPT_TIME_REMAINING_API == STD_ON))
FUNC (void, GPT_CODE) Emios_LLD_GetTime(
        VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
        P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr
    );
#endif /* GPT_TIME_API */

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
FUNC (void, GPT_CODE) Emios_LLD_SetSleepMode(
        VAR(uint8, AUTOMATIC) hwChannel, VAR(boolean, AUTOMATIC) wakeUpEnabled,
        P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr
    );
#endif /* GPT_WAKEUP_FUNCTIONALITY_API */

#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
FUNC (void, GPT_CODE) Emios_LLD_EnableNotification(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel);

FUNC (void, GPT_CODE) Emios_LLD_DisableNotification(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel);
#endif /* GPT_ENABLE_DISABLE_NOTIFICATION_API */

#if (GPT_DUAL_CLOCK_MODE == STD_ON)
FUNC (void, GPT_CODE) Emios_LLD_SelectPrescaler(
        VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
        VAR(Gpt_PrescaleType, AUTOMATIC) chPrescale
    );
#endif /* GPT_DUAL_CLOCK_MODE */


#define GPT_STOP_SEC_CODE
/*
* @violates @ref Gpt_eMIOS_LLD_H_REF_2 Repeated include file MemMap.h 
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*Gpt_eMIOS_LLD_H*/

/** @} */
