/**
*   @file    Gpt.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - Gpt driver header file.
*   @details GPT driver header file, containing the Autosar API specification and other variables
*            and functions that are exported by the GPT driver.
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

#ifndef GPT_H
#define GPT_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section GPT_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement.
*
* @section GPT_H_REF_2
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* The long names are maintained for better readability.
*
* @section GPT_H_REF_3
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
* @section GPT_H_REF_4
* Violates MISRA 2004 Required Rule  8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used
*
* @section GPT_H_REF_5
* Violates MISRA 2004 Required Rule 8.7,
* Objects shall be defined at block scope if they are only accessed from within a single function.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file Gpt.h
* @implements     DGPT02400
*/
/* @violates @ref GPT_H_REF_1 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "Std_Types.h"
#include "Gpt_Cfg.h"

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#include "EcuM_Cbk.h"
#endif

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt.h
* @requirements   BSW00374, BSW00379, BSW00318
* @{
*/
#define GPT_VENDOR_ID                       43
#define GPT_MODULE_ID                       100
#define GPT_AR_RELEASE_MAJOR_VERSION        4
#define GPT_AR_RELEASE_MINOR_VERSION        0
/* @violates @ref GPT_H_REF_2 Violates MISRA 2004 Required Rule 1.4, Identifier clash*/
#define GPT_AR_RELEASE_REVISION_VERSION     3
#define GPT_SW_MAJOR_VERSION                1
#define GPT_SW_MINOR_VERSION                0
#define GPT_SW_PATCH_VERSION                1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((GPT_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt.h and Std_Types.h are different"
    #endif
#endif

/* Check if source file and ADC configuration header file are of the same vendor */
#if (GPT_VENDOR_ID != GPT_VENDOR_ID_CFG)
    #error "Gpt.h and Gpt_Cfg.h have different vendor ids"
#endif
/* Check if header file and GPT configuration header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (GPT_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
     (GPT_AR_RELEASE_REVISION_VERSION != GPT_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Gpt.h and Gpt_Cfg.h are different"
#endif
/* Check if header file and GPT configuration header file are of the same software version */
#if ((GPT_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION_CFG) || \
     (GPT_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION_CFG) || \
     (GPT_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Gpt.h and Gpt_Cfg.h are different"
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and EcuM_Cbk.h file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION != ECUM_CBK_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION != ECUM_CBK_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Gpt.h and EcuM_Cbk.h are different"
#endif
#endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief wrong module index in switch statement
* @details Gpt_HW_Module has an out of range value
*
* @implements     DGPT02111
*/
#define GPT_CER_WRONGMODULE       ((uint8)0x01U)

/**
* @brief error in interrupt function
* @details hw channel has out of range value or configuration pointer is NULL (interrupt occured while
*          the driver was unitialized or the memory was corrupted)
*
* @implements     DGPT02112
*/
#define GPT_CER_UNINIT_INTERRUPT ((uint8)0x02U)

/**
* @brief function called without module initialization
* @details Errors and exceptions that will be detected by the GPT driver
*
* @implements     DGPT02113
*/
#define GPT_E_UNINIT        ((uint8)0x0AU)

/**
* @brief function called when timer channel is still running
* @details Errors and exceptions that will be detected by the GPT driver
*
* @implements     DGPT02114
*/
#define GPT_E_BUSY          ((uint8)0x0BU)

/**
* @brief initialization called when already initialized
* @details Errors and exceptions that will be detected by the GPT driver
*
* @implements     DGPT02115
*/
#define GPT_E_ALREADY_INITIALIZED   ((uint8)0x0DU)

/**
* @brief function called for invalid channel
* @details Errors and exceptions that will be detected by the GPT driver
*
* @implements     DGPT02116
*/
#define GPT_E_PARAM_CHANNEL ((uint8)0x14U)

/**
* @brief function called with parameter value out of range
* @details Errors and exceptions that will be detected by the GPT driver
*
* @implements     DGPT02117
*/
#define GPT_E_PARAM_VALUE   ((uint8)0x15U)

/**
* @brief function called with NULL pointer
* @details Errors and exceptions that will be detected by the GPT driver
*
* @implements     DGPT02118
*/
#define GPT_E_PARAM_POINTER  ((uint8)0x16U)

/**
* @brief function  called with invalid mode param.
* @details Errors and exceptions that will be detected by the GPT driver
*
* @implements     DGPT02119
*/
#define GPT_E_PARAM_MODE    ((uint8)0x1FU)

/* API SERVICE IDs */
/**
* @brief API service ID for Gpt_LLD_CheckStartTimeoutValue  function
* @details Parameters used when raising a CER error/exception
*
* @implements     DGPT02120
*/
#define GPT_CHECKTIMEOUTVALUE_ID       ((uint8)0x00U)

/**
* @brief API service ID for Gpt_GetVersionInfo  function
* @details Parameters used when raising an error/exception
*
* @implements     DGPT02121
*/
#define GPT_GETVERSIONINFO_ID       ((uint8)0x00U)

/**
* @brief API service ID for Gpt_Init function
* @details Parameters used when raising an error/exception
*
* @implements     DGPT02122
*/
#define GPT_INIT_ID                 ((uint8)0x01U)

/**
* @brief API service ID for Gpt_DeInit function
* @details Parameters used when raising an error/exception
*
* @implements     DGPT02123
*/
#define GPT_DEINIT_ID               ((uint8)0x02U)

/**
* @brief API service ID for Gpt_GetTimeElapsed function
* @details Parameters used when raising an error/exception
*
* @implements     DGPT02124
*/
#define GPT_TIMEELAPSED_ID          ((uint8)0x03U)

/**
* @brief API service ID for Gpt_GetTimeRemaining function
* @details Parameters used when raising an error/exception
*
* @implements     DGPT02125
*/
#define GPT_TIMEREMAINING_ID        ((uint8)0x04U)

/**
* @brief API service ID for Gpt_StartTimer function
* @details Parameters used when raising an error/exception
*
* @implements     DGPT02126
*/
#define GPT_STARTTIMER_ID           ((uint8)0x05U)

/**
* @brief API service ID for Gpt_StopTimer function
* @details Parameters used when raising an error/exception
*
* @implements     DGPT02127
*/
#define GPT_STOPTIMER_ID            ((uint8)0x06U)

/**
* @brief API service ID for Gpt_EnableNotification function
* @details Parameters used when raising an error/exception
*
* @implements     DGPT02128
*/
#define GPT_ENABLENOTIFICATION_ID   ((uint8)0x07U)

/**
* @brief API service ID for Gpt_DisableNotification function
* @details Parameters used when raising an error/exception
*
* @implements     DGPT02129
*/
#define GPT_DISABLENOTIFICATION_ID  ((uint8)0x08U)

/**
* @brief API service ID for Gpt_SetMode function
* @details Parameters used when raising an error/exception
*
* @implements     DGPT02130
*/
#define GPT_SETMODE_ID              ((uint8)0x09U)

/**
* @brief API service ID for Gpt_DisableWakeup function
* @details Parameters used when raising an error/exception
*
* @implements     DGPT02131
*/
#define GPT_DISABLEWAKEUP_ID        ((uint8)0x0AU)

/**
* @brief API service ID for Gpt_EnableWakeup function
* @details Parameters used when raising an error/exception
*
* @implements     DGPT02132
*/
#define GPT_ENABLEWAKEUP_ID         ((uint8)0x0BU)

/**
* @brief API service ID for Gpt_CheckWakeup function
* @details Parameters used when raising an error/exception
*
* @implements     DGPT02134
*/
#define GPT_CHECKWAKEUP_ID      ((uint8)0x0CU)

/**
* @brief service ID for Gpt_Schm_UnprotectResource function
* @details Parameters used when raising an error/exception
*
*/
#define GPT_SCHM_PROTECTRESOURCE_ID      ((uint8)0x0DU)

/**
* @brief service ID for Gpt_Schm_protectResource function
* @details Parameters used when raising an error/exception
*
*/
#define GPT_SCHM_UNPROTECTRESOURCE_ID      ((uint8)0x0EU)

/**
* @brief Instance ID of this gpt driver.
*
* @implements     DGPT02133
*/
#define GPT_INSTANCE_ID   ((uint8)0U)

/**
* @brief Macro to Intialise loop variable to 0.
*
* @implements     DGPT02135
*/
#define GPT_LOOP_INIT     ((uint8)0U)

/**
* @brief Macro to Intialise loop variable to 0.
*
* @implements     DGPT02136
*/
#define GPT_INDEX_ZERO    ((uint8)0U)

/**
* @brief one shot mode.
*
* @implements     DGPT02137
*/
#define GPT_CH_MODE_ONESHOT             ((uint8)0x00U)

/**
* @brief continous mode.
*
* @implements     DGPT02138
*/
#define GPT_CH_MODE_CONTINUOUS           ((uint8)0x01U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief This enumerated type allows the selection of different power modes.
*
* @implements DGPT02105
*/
typedef enum
{
    GPT_MODE_NORMAL = 0,                    /**< @brief GPT Normal operation mode of the GPT */
    GPT_MODE_SLEEP                          /**< @brief GPT sleep mode */
} Gpt_ModeType;

/**
* @brief This enumerated type allows the selection of channel status type.
*
* @implements DGPT02107
*/
typedef enum
{
    GPT_STATUS_UNINITIALIZED = 0,           /**< @brief GPT channel status - uninitialized */
    GPT_STATUS_INITIALIZED,                 /**< @brief GPT channel status - initialized */
    GPT_STATUS_STOPPED,                     /**< @brief GPT channel status - stopped */
    GPT_STATUS_EXPIRED,                     /**< @brief GPT channel status - expired */
    GPT_STATUS_RUNNING                      /**< @brief GPT channel status - running */
} Gpt_ChannelStatusType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief Gpt channel ID data type
*
* @implements DGPT02103
*/
typedef VAR(uint8,GPT_VAR) Gpt_ChannelType;

/**
* @brief Gpt timeout value data type.Used for reading the current timer value/setting periodic timer
*        values (in number of ticks) up to hours
*
* @implements DGPT02104
*/
typedef VAR(uint32,GPT_VAR) Gpt_ValueType;

/**
* @brief Gpt channel notification type.  The callback notifications shall be configurable as pointers
*        to user defined functions within the configuration structure.
*
* @implements DGPT02109
*/
typedef P2FUNC (void, GPT_APPL_CODE, Gpt_NotifyType)(void);

/**
* @brief Gpt channel mode type. Indicates of whether the channel mode is "CONTINUOUS" or "ONE SHOT".
*
* @implements DGPT02106
*/
typedef VAR(uint32,GPT_VAR) Gpt_ChannelModeType;

/**
* @brief Gpt prescale type. It specifies the GPT module specific prescaler factor per channel.
*
* @implements DGPT02108
*/
typedef VAR(uint32,GPT_VAR) Gpt_PrescaleType;

/**
* @brief Gpt Wake up type.
*
* @implements DGPT02110
*/
typedef VAR(uint32,GPT_VAR) Gpt_WakeUpType;

/**
* @brief Gpt channel configuration type.
*
* @implements   DGPT02102
*/
typedef struct
{
    VAR(Gpt_ChannelType, GPT_VAR) Gpt_HW_Channel;              /**< @brief GPT hw channel ID */
    VAR(Gpt_ChannelType, GPT_VAR) Gpt_HW_Module;               /**< @brief GPT hw module used */
    VAR(Gpt_ChannelModeType, GPT_VAR) Gpt_ChannelMode;         /**< @brief GPT channel mode */
    VAR(uint8, GPT_VAR) Gpt_ChannelClkSrc;                     /**< @brief GPT clock source */
    VAR(Gpt_PrescaleType, GPT_VAR) Gpt_ChannelPrescale;        /**< @brief GPT ch prescaler value*/
#if (GPT_DUAL_CLOCK_MODE == STD_ON)
    VAR(Gpt_PrescaleType, GPT_VAR) Gpt_ChannelPrescale_Alternate;/**<@brief ch 2nd prescaler val */
#endif /* GPT_DUAL_CLOCK_MODE */
    VAR(boolean, GPT_VAR) Gpt_FreezeEnable;                    /**<@brief GPT ch freeze enable */
    VAR(boolean, GPT_VAR) Gpt_EnableWakeup;                    /**<@brief GPT ch WakeUp enable */
    VAR(Gpt_NotifyType, GPT_VAR) Gpt_Notification;             /**<@brief pointer to ISR function*/
    VAR(Gpt_WakeUpType, GPT_VAR) Gpt_ChannelWakeUpInfo;        /**<@brief EcuM wake up reference */
    /* @violates @ref GPT_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
    VAR(boolean, GPT_VAR) GptDisableEcumWakeupSourceNotification;  /**<@brief Enable/Disable Ecum Notification */
#ifdef     GPT_OUTPUT_ENABLE_MODE
#if (GPT_OUTPUT_ENABLE_MODE==STD_ON)
    VAR(uint32, GPT_VAR) GptControlRegister2;
    VAR(uint8, GPT_VAR) GptChannelSecSrc;
#endif
#endif     
} Gpt_LLD_ChannelConfigType;

/**
* @brief Gpt configuration type - this is the type of the data structure including the configuration
*        set required for initializing the GPT driver.
*
* @implements   DGPT02101
*/
typedef struct
{
    VAR(uint8, GPT_VAR) Gpt_Channel_Count;                  /**< @brief the number of GPT channels (configured in tresos plugin builder)*/
    P2CONST(Gpt_LLD_ChannelConfigType, GPT_VAR, GPT_APPL_CONST) Gpt_ChannelConfigPtr;   /**< brief pointer to the GPT channel configuration */
} Gpt_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/* @violates @ref GPT_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref GPT_H_REF_1 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"
/**
* @brief   Global variable used for indicating the current GPT driver mode.
*
* @implements DGPT02102
*/
/* @violates @ref GPT_H_REF_5 the define cannot be moved inside the block scope because it must be visible from other layers */
extern VAR(Gpt_ModeType, GPT_VAR) Gpt_Current_Mode;

/**
* @brief   Global variable (pointer) used for storing the GPT driver configuration data
*
* @implements DGPT02100
*/
extern P2CONST(Gpt_ConfigType, GPT_VAR, GPT_APPL_CONST) Gpt_Cfg_Ptr;
/* @violates @ref GPT_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref GPT_H_REF_1 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

/* @violates @ref GPT_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref GPT_H_REF_1 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"
/**
* @brief   Global array used for indicating the current status of the GPT channels.
*
* @implements DGPT02101
*/
/* @violates @ref GPT_H_REF_4 Violates MISRA 2004 Required Rule 8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used */
extern VAR(Gpt_ChannelStatusType, GPT_VAR) Gpt_ChannelStatus[GPT_HW_CHANNEL_NUM];

/* @violates @ref GPT_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref GPT_H_REF_1 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"


#if (GPT_PRECOMPILE_SUPPORT == STD_OFF)
/* @violates @ref GPT_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref GPT_H_REF_1 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

/* Import extern declarations of GPT configuration from Gpt_Cfg.h */
GPT_CFG_EXTERN_DECLARATIONS

/* @violates @ref GPT_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref GPT_H_REF_1 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"
#endif

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define GPT_START_SEC_CODE
/* @violates @ref GPT_H_REF_1 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#if (GPT_VERSION_INFO_API == STD_ON)
extern FUNC(void, GPT_CODE) Gpt_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA) versioninfo);
#endif

FUNC (void, GPT_CODE) Gpt_Init(P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) configPtr);

#if (GPT_DEINIT_API == STD_ON)
FUNC (void, GPT_CODE) Gpt_DeInit(void);
#endif

#if (GPT_TIME_ELAPSED_API == STD_ON)
FUNC (Gpt_ValueType, GPT_CODE) Gpt_GetTimeElapsed(VAR(Gpt_ChannelType, AUTOMATIC) channel);
#endif

#if (GPT_TIME_REMAINING_API == STD_ON)
FUNC (Gpt_ValueType, GPT_CODE) Gpt_GetTimeRemaining(VAR(Gpt_ChannelType, AUTOMATIC) channel);
#endif

FUNC (void, GPT_CODE) Gpt_StartTimer(VAR(Gpt_ChannelType, AUTOMATIC) channel, VAR(Gpt_ValueType, AUTOMATIC) value);

FUNC (void, GPT_CODE) Gpt_StopTimer(VAR(Gpt_ChannelType, AUTOMATIC) channel);

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
FUNC (void, GPT_CODE) Gpt_EnableNotification(VAR(Gpt_ChannelType, AUTOMATIC) channel);

FUNC (void, GPT_CODE) Gpt_DisableNotification(VAR(Gpt_ChannelType, AUTOMATIC) channel);
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
FUNC (void, GPT_CODE) Gpt_SetMode(VAR(Gpt_ModeType, AUTOMATIC) mode);

FUNC (void, GPT_CODE) Gpt_DisableWakeup(VAR(Gpt_ChannelType, AUTOMATIC) channel);

FUNC (void, GPT_CODE) Gpt_EnableWakeup(VAR(Gpt_ChannelType, AUTOMATIC) channel);

FUNC (void, GPT_CODE) Gpt_CheckWakeup(VAR(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource);
#endif

FUNC (void, GPT_CODE) Gpt_Schm_ProtectResource(VAR(uint8, AUTOMATIC) Gpt_ExclusiveArea);

FUNC (void, GPT_CODE) Gpt_Schm_UnprotectResource(VAR(uint8, AUTOMATIC) Gpt_ExclusiveArea);

#define GPT_STOP_SEC_CODE
/* @violates @ref GPT_H_REF_1 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*GPT_H*/

/** @} */
