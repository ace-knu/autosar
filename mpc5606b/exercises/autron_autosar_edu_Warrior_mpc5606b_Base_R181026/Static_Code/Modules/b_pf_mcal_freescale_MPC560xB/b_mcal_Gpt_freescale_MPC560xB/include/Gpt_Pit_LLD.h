/**
*   @file    Gpt_Pit_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - PIT driver header file.
*   @details PIT driver interface.
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

#ifndef GPT_PIT_LLD_H
#define GPT_PIT_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section GPT_PIT_LLD_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
* This violation is due to function like macro defined for register operations.
* Function like macro are used to reduce code complexity.
*
* @section GPT_PIT_LLD_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_PIT_LLD_H_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, Violates only preprocessor statements and comments before
* '#include'. This violation  is not  fixed since  the inclusion  of MemMap.h  is as  per Autosar
* requirement MEMMAP003.
*
* @section GPT_PIT_LLD_H_REF_4
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @violates @ref GPT_PIT_LLD_H_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "Std_Types.h"
/* @violates @ref GPT_PIT_LLD_H_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "Gpt.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_Pit_LLD.h
* @requirements   BSW00374, BSW00379, BSW00318
*
* @implements DGPT09400
*/
#define GPT_PIT_LLD_VENDOR_ID                       43
#define GPT_PIT_LLD_MODULE_ID                       100
/* @violates @ref GPT_PIT_LLD_H_REF_4 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_PIT_LLD_AR_RELEASE_MAJOR_VERSION        4
/* @violates @ref GPT_PIT_LLD_H_REF_4 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_PIT_LLD_AR_RELEASE_MINOR_VERSION        0
/* @violates @ref GPT_PIT_LLD_H_REF_4 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_PIT_LLD_AR_RELEASE_REVISION_VERSION     3
#define GPT_PIT_LLD_SW_MAJOR_VERSION                1
#define GPT_PIT_LLD_SW_MINOR_VERSION                0
#define GPT_PIT_LLD_SW_PATCH_VERSION                1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((GPT_PIT_LLD_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_PIT_LLD_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt_Pit_LLD.h and Std_Types.h are different"
    #endif
#endif

#if (GPT_PIT_LLD_VENDOR_ID != GPT_VENDOR_ID)
    #error "Gpt_Pit_LLD.h and Gpt.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_PIT_LLD_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_PIT_LLD_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_PIT_LLD_AR_RELEASE_REVISION_VERSION != GPT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Pit_LLD.h and Gpt.h are different"
#endif
/* Check if header file and Gpt header file are of the same software version */
#if ((GPT_PIT_LLD_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION) || \
     (GPT_PIT_LLD_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION) || \
     (GPT_PIT_LLD_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Pit_LLD.h and Gpt.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#if (GPT_DEV_ERROR_DETECT == STD_ON)
/**
* @brief  PIT specific macro for checking the timeout value.
* @param[in]      value     Timeout vaule
* @return     Boolean: TRUE - Time out value is valid
*                      FALSE - Time out value is Invalid
* @implements DGPT09210
*/
/* @violates @ref GPT_PIT_LLD_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7,  Use of function like macro */
#define PIT_LLD_INVALID_TIMEOUT_VALUE(value)    ((value) > PIT_LDVAL_MAX_VALUE)
#endif

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
/* @violates @ref GPT_PIT_LLD_H_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
/* @violates @ref GPT_PIT_LLD_H_REF_3 Only preprocessor statements and comments before "#include" */
#include "MemMap.h"

FUNC (void, GPT_CODE) Pit_LLD_InitChannel(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
                                          VAR(boolean, AUTOMATIC) freezeEnable);

#if (GPT_DEINIT_API == STD_ON)
FUNC (void, GPT_CODE) Pit_LLD_DeInit(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel);
#endif

FUNC (void, GPT_CODE) Pit_LLD_StartTimer(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
                                         VAR(Gpt_ValueType, AUTOMATIC) value,
                                         VAR(Gpt_ChannelModeType, AUTOMATIC) channelMode);

FUNC (void, GPT_CODE) Pit_LLD_StopTimer(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
                                        P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr);

#if ((GPT_TIME_ELAPSED_API == STD_ON) || (GPT_TIME_REMAINING_API == STD_ON))
FUNC (void, GPT_CODE) Pit_LLD_GetTime(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
                                      P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr);
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
FUNC (void, GPT_CODE) Pit_LLD_SetSleepMode(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
                                           VAR(boolean, AUTOMATIC) wakeUpEnabled,
                                           P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr);
#endif

#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
FUNC (void, GPT_CODE) Pit_LLD_EnableNotification(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel);

FUNC (void, GPT_CODE) Pit_LLD_DisableNotification(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel);
#endif

#define GPT_STOP_SEC_CODE
/* @violates @ref GPT_PIT_LLD_H_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
/* @violates @ref GPT_PIT_LLD_H_REF_3 Only preprocessor statements and comments before "#include" */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*GPT_PIT_LLD_H*/

/** @} */
