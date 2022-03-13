/**
*   @file    Gpt_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - Gpt driver header file.
*   @details GPT driver header file, containing variables, functions prototypes, data types and/or
*            defines and macros that:
*            - are Autosar specific and are not exported by the GPT driver.
*            - are not related to the GPT driver related IPs.
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

#ifndef GPT_LLD_H
#define GPT_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section GPT_LLD_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_LLD_H_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section GPT_LLD_H_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
* @section GPT_LLD_H_REF_4
* Violates MISRA 2004 Required Rule 8.8, declaring an external identifier in a header file,
* that will be included in any file where the identifier is defined or used.
*
* @section GPT_LLD_H_REF_5
* Violates MISRA 2004 Required Rule 8.7,
* Objects shall be defined at block scope if they are only accessed from within a single function.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#if (GPT_DUAL_CLOCK_MODE == STD_ON)
#include "Gpt_NonASR.h"
#endif /* GPT_DUAL_CLOCK_MODE */

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_LLD.h
* @requirements   BSW00374, BSW00379, BSW00318
* @implements     DGPT03900
* @{
*/
#define GPT_LLD_VENDOR_ID                      43
/* @violates @ref GPT_LLD_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_LLD_AR_RELEASE_MAJOR_VERSION       4
/* @violates @ref GPT_LLD_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_LLD_AR_RELEASE_MINOR_VERSION       0
/* @violates @ref GPT_LLD_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_LLD_AR_RELEASE_REVISION_VERSION    3
#define GPT_LLD_SW_MAJOR_VERSION               1
#define GPT_LLD_SW_MINOR_VERSION               0
#define GPT_LLD_SW_PATCH_VERSION               1
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief   Defines for GPT_WAKE_UP disabled
* @details Defines for GPT_WAKE_UP status disabled
* @implements   DGPT03308
*/
#define GPT_WAKE_UP_DISABLED          ((uint8)0x00U)
/**
* @brief   Defines for GPT_WAKE_UP enabled
* @details Defines for GPT_WAKE_UP status enabled
* @implements   DGPT03307
*/
#define GPT_WAKE_UP_ENABLED           ((uint8)0x01U)

/**
* @brief   Defines for GPT_WAKEUP_GENERATED
* @details Status flag for GPT_WAKEUP interrupt generated
* @implements   DGPT03322
*/
#define GPT_WAKEUP_NO                 ((uint8)0x00U)
/**
* @brief   Defines for GPT_WAKEUP_GENERATED 
* @details Status flag for GPT_WAKEUP interrupt not generated
* @implements   DGPT03321
*/
#define GPT_WAKEUP_YES                ((uint8)0x01U)

/**
* @brief   Defines for GPT_NOTIFICATION disabled
* @details Defines of the GPT_NOTIFICATION status disabled
* @implements   DGPT03310
*/
#define GPT_NOTIFICATION_DISABLED     ((uint8)0x00U)
/**
* @brief   Defines for GPT_NOTIFICATION enabled
* @details Defines of the GPT_NOTIFICATION status enabled
* @implements   DGPT03309
*/
#define GPT_NOTIFICATION_ENABLED      ((uint8)0x01U)

/**
* @brief   macro for retrieving the channel mode
* @details returns the channel mode from the Gpt_LLD_ChannelInfo array
*
* @param[in]     channel         Numeric identifier of the GPT channel
*
* @return value describing the channel mode
*
* @implements   DGPT03313
* @violates @ref GPT_LLD_H_REF_2 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
*/
#define GPT_GET_CHANNEL_MODE(channel)           (((Gpt_LLD_ChannelBitInfo[(channel)])&(uint8)0x04U)>>2U)

/**
* @brief   macro for retrieving the channel's WAKE_UP bit
* @details returns the channel's GPT_WAKE_UP configuration from the Gpt_LLD_ChannelInfo array
*
* @param[in]     channel         Numeric identifier of the GPT channel
* @param[in]     value           new value for channel mode
*
* @implements   DGPT03312
* @violates @ref GPT_LLD_H_REF_2 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
*/
#define GPT_SET_CHANNEL_MODE(channel, value)    ((Gpt_LLD_ChannelBitInfo[(channel)]) = ((uint8)((value)<<2U)|((Gpt_LLD_ChannelBitInfo[(channel)])&(uint8)~0x04U)))

/**
* @brief   macro for retrieving the channel mode
* @details returns the channel mode from the Gpt_LLD_ChannelInfo array
*
* @param[in]     channel         Numeric identifier of the GPT channel
*
* @return value describing the channel's WAKE_UP configuration
*
* @implements   DGPT03317
* @violates @ref GPT_LLD_H_REF_2 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
*/
#define GPT_GET_WAKE_UP(channel)                (((Gpt_LLD_ChannelBitInfo[(channel)])&(uint8)0x02U)>>1U)

/**
* @brief   macro for setting the channel's WAKE_UP bit
* @details sets the chanel's GPT_WAKE_UP configuration in the Gpt_LLD_ChannelInfo array
*
* @param[in]     channel         Numeric identifier of the GPT channel
* @param[in]     value           new value for channel mode
*
* @implements   DGPT03316
* @violates @ref GPT_LLD_H_REF_2 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
*/
#define GPT_SET_WAKE_UP(channel, value)         ((Gpt_LLD_ChannelBitInfo[(channel)]) = ((uint8)((value)<<1U)|((Gpt_LLD_ChannelBitInfo[(channel)])&(uint8)~0x02U)))

/**
* @brief   macro for retrieving the status of the channel's WAKE_UP GENERATED bit
* @details returns the channel's WAKE_UP GENERATED flag from the Gpt_LLD_ChannelInfo array
*
* @param[in]     channel         Numeric identifier of the GPT channel
*
* @return value of the channel's WAKE_UP GENERATED flag
*
* @implements   DGPT03320
* @violates @ref GPT_LLD_H_REF_2 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
*/
#define GPT_GET_WAKEUP_GEN(channel)             (((Gpt_LLD_ChannelBitInfo[(channel)])&(uint8)0x08U)>>3U)

/**
* @brief   macro for setting the channel's WAKE_UP GENERATED bit
* @details sets the channel's WAKE_UP GENERATED flag in the Gpt_LLD_ChannelInfo array
*
* @param[in]     channel         Numeric identifier of the GPT channel
* @param[in]     value           the value of channel's WAKE_UP GENERATED flag
*
* @implements   DGPT03319
* @violates @ref GPT_LLD_H_REF_2 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
*/
#define GPT_SET_WAKEUP_GEN(channel, value)      ((Gpt_LLD_ChannelBitInfo[(channel)]) = ((uint8)((value)<<3U)|((Gpt_LLD_ChannelBitInfo[(channel)])&(uint8)~0x08U)))

/**
* @brief   macro for retrieving the channel's NOTIFICATION bit
* @details returns the channel's NOTIFICATION configuration from the Gpt_LLD_ChannelInfo array
*
* @param[in]     channel         Numeric identifier of the GPT channel
*
* @return  value describing the channel's NOTIFICATION configuration
*
* @implements   DGPT03315
* @violates @ref GPT_LLD_H_REF_2 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
*/
#define GPT_GET_NOTIFICATION(channel)           ((Gpt_LLD_ChannelBitInfo[(channel)])&(uint8)0x01U)

/**
* @brief   macro for setting the channel's NOTIFICATION bit
* @details sets the channel's NOTIFICATION configuration in the Gpt_LLD_ChannelInfo array
*
* @param[in]     channel         Numeric identifier of the GPT channel
* @param[in]     value           new value for NOTIFICATION
*
* @implements   DGPT03314
* @violates @ref GPT_LLD_H_REF_2 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
*/
#define GPT_SET_NOTIFICATION(channel, value)    ((Gpt_LLD_ChannelBitInfo[(channel)]) = ((value)|((Gpt_LLD_ChannelBitInfo[(channel)])&(uint8)~0x01U)))

/**
* @brief   macro for retrieving the channel's WAKE_UP_CAPABILITY bit
* @details returns the channel's WAKE_UP_CAPABILITY configuration from the Gpt_LLD_ChannelInfo array
*
* @param[in]     channel         Numeric identifier of the GPT channel
*
* @return value describing the channel's WAKE_UP_CAPABILITY configuration
*
* @implements   DGPT03318
* @violates @ref GPT_LLD_H_REF_2 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
*/
#define GPT_LLD_GET_WAKE_UP_CAPABILITY(channel)\
            ((Gpt_LLD_ChannelConfigPtr[(channel)].Gpt_EnableWakeup == (boolean)TRUE) ? (TRUE) : (FALSE))

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/** 
* @brief Low level configuration for channel specific parameters
* @implements   DGPT03301
*/
typedef struct
{
    VAR(Gpt_ValueType, GPT_VAR) Gpt_ReloadValue; /**< @brief for a HW channel represents the load value; */
    VAR(Gpt_ValueType, GPT_VAR) Gpt_StopValue;   /**< @brief for a HW channel represents the stop value; */
} Gpt_LLD_ChannelInfoType;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/








#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and MemMap.h file are of the same Autosar version */
    #if ((GPT_LLD_AR_RELEASE_MAJOR_VERSION != MEMMAP_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_LLD_AR_RELEASE_MINOR_VERSION != MEMMAP_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt_LLD.h and MemMap.h are different"
    #endif
#endif

#define GPT_START_SEC_VAR_NO_INIT_8
/* @violates @ref GPT_LLD_H_REF_1 Repeated include file MemMap.h */
#include "MemMap.h"
/** 
* @brief  Array containing "HW channel" vs "logical channel correspondence" for EMIOS:
* @implements DGPT03306
*/
/* @violates @ref GPT_LLD_H_REF_4 Violates MISRA 2004 Required Rule 8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used */
extern VAR(uint8, GPT_VAR) GPT_LLD_EMIOS_HardwareMap[GPT_EMIOS_CHAN_NUM];

/** 
* @brief  Array containing "HW channel" vs "logical channel correspondence" for PIT:
* @implements DGPT03304
*/
/* @violates @ref GPT_LLD_H_REF_4 Violates MISRA 2004 Required Rule 8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used */
extern VAR(uint8, GPT_VAR) GPT_LLD_PIT_HardwareMap[GPT_PIT_CHAN_NUM];

/** 
* @brief  Array containing "HW channel" vs "logical channel correspondence" for STM:
* @implements DGPT03305
*/
/* @violates @ref GPT_LLD_H_REF_4 Violates MISRA 2004 Required Rule 8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used */
extern VAR(uint8, GPT_VAR) GPT_LLD_STM_HardwareMap[GPT_STM_CHAN_NUM];

/** 
* @brief  Array containing "HW channel" vs "logical channel correspondence" for RTC:
* @implements DGPT03319
*/
/* @violates @ref GPT_LLD_H_REF_4 Violates MISRA 2004 Required Rule 8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used */
extern VAR(uint8, GPT_VAR) GPT_LLD_RTC_HardwareMap[GPT_RTC_CHAN_NUM];
#define GPT_STOP_SEC_VAR_NO_INIT_8
/* @violates @ref GPT_LLD_H_REF_1 Repeated include file MemMap.h */
#include "MemMap.h"

/* @violates @ref GPT_LLD_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref GPT_LLD_H_REF_1 Repeated include file MemMap.h */
#include "MemMap.h"
/** 
* @brief Pointer to a data structure containing channel configuration information (set in tresos)
* @implements DGPT03302
*/
extern P2CONST(Gpt_LLD_ChannelConfigType, GPT_VAR, GPT_APPL_CONST) Gpt_LLD_ChannelConfigPtr;
/* @violates @ref GPT_LLD_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref GPT_LLD_H_REF_1 Repeated include file MemMap.h */
#include "MemMap.h"


#define GPT_START_SEC_VAR_NO_INIT_32
/* @violates @ref GPT_LLD_H_REF_1 Repeated include file MemMap.h */
#include "MemMap.h"
/** 
* @brief Array of data structure elements storing timeout, channel mode, wakeup and notification 
*        information.
* @implements DGPT03303
*/
/* @violates @ref GPT_LLD_H_REF_4 Violates MISRA 2004 Required Rule 8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used */
extern VAR(Gpt_LLD_ChannelInfoType, GPT_VAR) Gpt_LLD_ChannelInfo[GPT_HW_CHANNEL_NUM];
/**< @brief stores information about channel mode, wake up, notification - each on 1 bit */
/* @violates @ref GPT_LLD_H_REF_4 Violates MISRA 2004 Required Rule 8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used */
extern VAR(uint8, GPT_VAR) Gpt_LLD_ChannelBitInfo[GPT_HW_CHANNEL_NUM];
#define GPT_STOP_SEC_VAR_NO_INIT_32
/* @violates @ref GPT_LLD_H_REF_1 Repeated include file MemMap.h */
#include "MemMap.h"

#if (GPT_PRECOMPILE_SUPPORT == STD_ON)
/* @violates @ref GPT_LLD_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref GPT_LLD_H_REF_1 Repeated include file MemMap.h */
#include "MemMap.h"

 /** 
* @brief Configuration structure for Precompile Config Variant
*/
/* @violates @ref GPT_LLD_H_REF_5 the define cannot be moved inside the block scope because it must be visible from other layers */
extern CONST(Gpt_ConfigType, GPT_CONST) Gpt_InitConfigPC;
/* @violates @ref GPT_LLD_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED

/* @violates @ref GPT_LLD_H_REF_1 Repeated include file MemMap.h */
#include "MemMap.h"

#endif


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define GPT_START_SEC_CODE
/* @violates @ref GPT_LLD_H_REF_1 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

FUNC (void, GPT_CODE) Gpt_LLD_Init(void);

FUNC (void, GPT_CODE) Gpt_LLD_DeInit(void);

FUNC (Std_ReturnType, GPT_CODE) Gpt_LLD_CheckStartTimeoutValue(VAR(Gpt_ChannelType, AUTOMATIC) channel,
                                                               VAR(Gpt_ValueType, AUTOMATIC) value);

FUNC (void, GPT_CODE) Gpt_LLD_StartTimer(VAR(Gpt_ChannelType, AUTOMATIC) channel,
                                                   VAR(Gpt_ValueType, AUTOMATIC) value);

FUNC (void, GPT_CODE) Gpt_LLD_StopTimer(VAR(Gpt_ChannelType, AUTOMATIC) channel);

#if (GPT_TIME_ELAPSED_API == STD_ON)
FUNC (void, GPT_CODE) Gpt_LLD_GetTimeElapsed(VAR(Gpt_ChannelType, AUTOMATIC) channel,
                                             P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr);
#endif

#if (GPT_TIME_REMAINING_API == STD_ON)
FUNC (void, GPT_CODE) Gpt_LLD_GetTimeRemaining(VAR(Gpt_ChannelType, AUTOMATIC) channel,
                                               P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr);
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
FUNC (void, GPT_CODE) Gpt_LLD_SetSleepMode(void);

FUNC (void, GPT_CODE) Gpt_LLD_SetNormalMode(void);
#endif

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
FUNC (void, GPT_CODE) Gpt_LLD_EnableNotification(VAR(Gpt_ChannelType, AUTOMATIC) channel);

FUNC (void, GPT_CODE) Gpt_LLD_DisableNotification(VAR(Gpt_ChannelType, AUTOMATIC) channel);
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
FUNC (void, GPT_CODE) Gpt_LLD_DisableWakeup(VAR(Gpt_ChannelType, AUTOMATIC) channel);

FUNC (void, GPT_CODE) Gpt_LLD_EnableWakeup(VAR(Gpt_ChannelType, AUTOMATIC) channel);

FUNC (void, GPT_CODE) Gpt_LLD_Cbk_CheckWakeup(VAR(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource);
#endif /* GPT_WAKEUP_FUNCTIONALITY_API == STD_ON */

#if (GPT_DUAL_CLOCK_MODE == STD_ON)
FUNC (void, GPT_CODE) Gpt_LLD_SelectPrescaler(VAR(Gpt_ClockModeType, AUTOMATIC) ClkMode);
#endif /* GPT_DUAL_CLOCK_MODE == STD_ON */

FUNC (void, GPT_CODE) Gpt_eMIOS_LLD_ProcessInterrupt(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel);

FUNC (void, GPT_CODE) Gpt_Pit_ProcessInterrupt(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel);

FUNC (void, GPT_CODE) Gpt_Stm_ProcessInterrupt(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel);

FUNC (void, GPT_CODE) Gpt_Rtc_ProcessInterrupt(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel);

#define GPT_STOP_SEC_CODE
/* @violates @ref GPT_LLD_H_REF_1 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*GPT_LLD_H*/

/** @} */
