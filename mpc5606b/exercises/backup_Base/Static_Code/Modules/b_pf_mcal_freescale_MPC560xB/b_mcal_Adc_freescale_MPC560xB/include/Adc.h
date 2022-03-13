/**
*   @file    Adc.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - driver API and development errors definition.
*   @details This file contains the ADC Autosar driver API and development errors definition.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : ADCDIG
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

#ifndef ADC_H
#define ADC_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,
* only preprocessor statements and comments before '#include'
* This is an Autosar memory management requirement.
*
* @section Adc_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the 
* contents of a header being included twice. 
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Adc_h_REF_3
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character signifiance and case
* sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Adc_h_REF_4
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @implements     DADC00001 */
/*
* @violates @ref Adc_h_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Std_Types.h"
/*
* @violates @ref Adc_h_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Mcal.h"
/*
* @violates @ref Adc_h_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Adc_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Adc.h
* @implements     DADC03001
*/
#define ADC_VENDOR_ID                           (43)
#define ADC_MODULE_ID                           (123)
#define ADC_AR_RELEASE_MAJOR_VERSION            (4)
#define ADC_AR_RELEASE_MINOR_VERSION            (0)
/*
* @violates @ref Adc_h_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_REVISION_VERSION         (3)
#define ADC_SW_MAJOR_VERSION                    (1)
#define ADC_SW_MINOR_VERSION                    (0)
#define ADC_SW_PATCH_VERSION                    (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* @implements     DADC06001 */

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if source file and Std_Types header file are of the same AutoSar version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
 #error "AutoSar Version Numbers of Adc.h and Std_Types.h are different"
 #endif
#endif

/* Check if source file and ADC configuration header file are of the same vendor */
#if (ADC_VENDOR_ID != ADC_CFG_H_VENDOR_ID)
#error "Adc.h and Adc_Cfg.h have different vendor ids"
#endif

/* Check if source file and ADC configuration header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION != ADC_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION != ADC_CFG_H_AR_RELEASE_MINOR_VERSION) || \
     (ADC_AR_RELEASE_REVISION_VERSION != ADC_CFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Adc.h and Adc_Cfg.h are different"
#endif

/* Check if source file and ADC configuration header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION != ADC_CFG_H_SW_MAJOR_VERSION) || \
     (ADC_SW_MINOR_VERSION != ADC_CFG_H_SW_MINOR_VERSION) || \
     (ADC_SW_PATCH_VERSION != ADC_CFG_H_SW_PATCH_VERSION))
#error "Software Version Numbers of Adc.h and Adc_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          Development errors.
* @details        The following errors shall be detectable by the ADC module depending on its 
*                 configuration (development / production mode).
*
* @implements     DADC03002
* @note           All error codes
*
*/
#define ADC_E_UNINIT                            ((uint8)0x0AU)
#define ADC_E_BUSY                              ((uint8)0x0BU)
#define ADC_E_IDLE                              ((uint8)0x0CU)
#define ADC_E_ALREADY_INITIALIZED               ((uint8)0x0DU)
#define ADC_E_PARAM_CONFIG                      ((uint8)0x0EU)
#define ADC_E_PARAM_POINTER                     ((uint8)0x14U)
#define ADC_E_PARAM_GROUP                       ((uint8)0x15U)
#define ADC_E_WRONG_CONV_MODE                   ((uint8)0x16U)
#define ADC_E_WRONG_TRIGG_SRC                   ((uint8)0x17U)
#define ADC_E_NOTIF_CAPABILITY                  ((uint8)0x18U)
#define ADC_E_BUFFER_UNINIT                     ((uint8)0x19U)
#define ADC_E_QUEUE_FULL                        ((uint8)0x1AU)

#define ADC_E_PARAM_GROUP_SAMPLES               ((uint8)0x25U)

/**
* @brief          Catastrophic Errors.
* @details        The following errors shall be detectable by the ADC module in case of
*                 Catastrophic Errors Recovery (CER).
*
* @implements     DADC03003
* @note           All catastrophic error codes
*
*/
#define ADC_CER_TRIG_SRC_TYPE                   ((uint8)0x4AU)
#define ADC_CER_MODE_TYPE_INT                   ((uint8)0x4BU)
#define ADC_CER_CORRUPTED_RES_TYPE              ((uint8)0x4CU)
#define ADC_CER_LIMIT_RANGE_TYPE                ((uint8)0x4DU)
/* @violates @ref Adc_h_REF_4 Identifier exceeds 31 characters */
#define ADC_CER_CHANNEL_ID_CORRUPTED_TYPE       ((uint8)0x4EU)

/**
* @brief          API's IDs.
* @details        AUTOSAR API's service IDs.
*
* @implements     DADC03004
* @note           All AUTOSAR API's service IDs
*
*/
#define ADC_INIT_ID                             (0x00U)
#define ADC_DEINIT_ID                           (0x01U)
#define ADC_STARTGROUPCONVERSION_ID             (0x02U)
#define ADC_STOPGROUPCONVERSION_ID              (0x03U)
#define ADC_VALUEREADGROUP_ID                   (0x04U)
#define ADC_ENABLEHARDWARETRIGGER_ID            (0x05U)
#define ADC_DISABLEHARDWARETRIGGER_ID           (0x06U)
#define ADC_ENABLEGROUPNOTIFICATION_ID          (0x07U)
#define ADC_DISABLEGROUPNOTIFICATION_ID         (0x08U)
#define ADC_GETGROUPSTATUS_ID                   (0x09U)
#define ADC_GETVERSIONINFO_ID                   (0x0AU)
#define ADC_GETSTREAMLASTPOINTER_ID             (0x0BU)
#define ADC_SETUPRESULTBUFFER_ID                (0x0CU)

/**
* @brief          API's IDs.
* @details        Catastrophic Errors Recovery (CER) API's service IDs.
*
* @implements     DADC03005
* @note           All CER API's service IDs
*
*/
/* @violates @ref Adc_h_REF_4 Identifier exceeds 31 characters */
#define ADC_COPYQUEUEDATA2DMACOMMMANDBUFFER_ID  (0x30U)
/* @violates @ref Adc_h_REF_4 Identifier exceeds 31 characters */
#define ADC_IRQ_CFIFO_EMPTY_COMMON_FUNC_ID      (0x31U)
/* @violates @ref Adc_h_REF_4 Identifier exceeds 31 characters */
#define ADC_IRQ_RFIFO_FULL_COMMON_FUNC_ID       (0x32U)
/* @violates @ref Adc_h_REF_4 Identifier exceeds 31 characters */
#define ADC_EQADC_LLD_STARTNORMALCONVERSION_ID  (0x33U)
#define ADC_EQADC_LLD_READGROUP_ID              (0x34U)
#define ADC_ENDNORMALCONV_ID                    (0x35U)
#define ADC_DMAENDNORMALCONV_ID                 (0x36U)
#define ADC_ADCDIG_LLD_READGROUP_ID             (0x37U)
/* @violates @ref Adc_h_REF_4 Identifier exceeds 31 characters */
#define ADC_ADCDIG_LLD_GETSTREAMLASTPOINTER_ID  (0x38U)
/* @violates @ref Adc_h_REF_4 Identifier exceeds 31 characters */
#define ADC_DMA_INTERRUPT_COMMON_FUNC_ID        (0x39U)
/* @violates @ref Adc_h_REF_4 Identifier exceeds 31 characters */
#define ADC_CHECKCONVERSIONVALUESINRANGEC_ID    (0x3AU)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Structure for group status.
* @details        This structure contains the group status information.
*
* @api
*
* @implements     DADC03006
*/
typedef struct
{
  Adc_StatusType Conversion; /**< @brief Group status */
  Adc_GroupConversionStateType AlreadyConverted; /**< @brief Group was previously converted or not */
#ifndef IPV_EQADC
 #ifdef ADC_DMA_SUPPORTED
 #if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
  Adc_Dma_ContinuousType Adc_Dma_Continuous; /**< @brief DMA configured channels are continuous or not */
 #endif /* #if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY) */
 #endif /* #ifdef ADC_DMA_SUPPORTED */
#endif /* #ifndef IPV_EQADC */
#if (STD_ON==ADC_HW_TRIGGER_API)
  Adc_HWTriggeringType HwTriggering; /**< @brief hw trigger enabled/disabled */
#endif /* #if (STD_ON==ADC_HW_TRIGGER_API) */
#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
  Adc_NotificationType Notification; /**< @brief notification enabled/disabled */
#endif /* #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
  Adc_StreamNumSampleType ResultIndex; /**< @brief index into streaming buffer that is currently being filled */
#ifdef ADC_NOTIFY_ON_STREAM_COMPLETED
#if (STD_ON == ADC_NOTIFY_ON_STREAM_COMPLETED)
  Adc_StreamNumSampleType CurrentNumDMASamples; /**< @brief Num. DMA samples to stream */
#endif
#endif
} Adc_GroupStatusType;

/**
* @brief          Structure for hardware unit status.
* @details        This structure contains the HW unit status information.
*
* @api
*
* @implements     DADC03007
*/
typedef struct
{
  Adc_StatusType Status; /**< @brief Status of the HW unit: IDLE, BUSY, COMPLETED */
  Adc_QueueIndexType QueueIndex; /**< @brief Filled slots in the queue */
  Adc_GroupType Queue[ADC_QUEUE_MAX_DEPTH_MAX]; /**< @brief Queued groups indexes, always executing Queue[0] */
#if (STD_ON==ADC_HW_TRIGGER_API)
  Adc_GroupType HwQueue[ADC_HW_QUEUE]; /**< @brief The depth of the hardware queue */
  Adc_QueueIndexType HwQueueIndex; /**< @brief Filled slots in the Hw queue */
 #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
  Adc_MhtGroupType HwQueueGroupType; /**< @brief When != 0 indicate MHT groups in queue, else regular */
 #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
#endif /* (STD_ON==ADC_HW_TRIGGER_API)*/
#ifndef IPV_EQADC
  Adc_GroupType SwInjQueue[1]; /**< @brief The depth of the software injected queue */
  Adc_QueueIndexType SwInjQueueIndex; /**< @brief Filled slots in the Sw injected queue */
#endif /* #ifndef IPV_EQADC */
  boolean InjConvOngoin; /**< @brief Indicates Injected conversion or normal conversion */
} Adc_UnitStatusType;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#ifndef ADC_PRECOMPILE_SUPPORT
/* @violates @ref Adc_h_REF_4 Identifier exceeds 31 characters */
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Adc_h_REF_1 Only preprocessor statements and comments before "#include" */
/*
* @violates @ref Adc_h_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

/* @violates @ref Adc_h_REF_4 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Adc_h_REF_1 Only preprocessor statements and comments before "#include" */
/*
* @violates @ref Adc_h_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"
#endif

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define ADC_START_SEC_CODE
/* @violates @ref Adc_h_REF_1 Only preprocessor statements and comments before "#include" */
/*
* @violates @ref Adc_h_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

FUNC(void, ADC_CODE) Adc_Init
(
  P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) ConfigPtr
);

FUNC(Std_ReturnType, ADC_CODE) Adc_SetupResultBuffer
(
  VAR(Adc_GroupType, AUTOMATIC) Group,
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataBufferPtr
);

#if (ADC_DEINIT_API == STD_ON)
FUNC(void, ADC_CODE) Adc_DeInit
(
  void
);
#endif /* (ADC_DEINIT_API == STD_ON) */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
FUNC(void, ADC_CODE) Adc_StartGroupConversion
(
  VAR(Adc_GroupType, AUTOMATIC) Group
);

FUNC(void, ADC_CODE) Adc_StopGroupConversion
(
  VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

FUNC(Std_ReturnType, ADC_CODE) Adc_ReadGroup
(
  VAR(Adc_GroupType, AUTOMATIC) Group,
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataBufferPtr
);

#if (ADC_HW_TRIGGER_API == STD_ON)
FUNC(void, ADC_CODE) Adc_EnableHardwareTrigger
(
  VAR(Adc_GroupType, AUTOMATIC) Group
);

FUNC(void, ADC_CODE) Adc_DisableHardwareTrigger
(
  VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
FUNC(void, ADC_CODE) Adc_EnableGroupNotification
(
  VAR(Adc_GroupType, AUTOMATIC) Group
);

FUNC(void, ADC_CODE) Adc_DisableGroupNotification
(
  VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

FUNC(Adc_StatusType, ADC_CODE) Adc_GetGroupStatus
(
  VAR(Adc_GroupType, AUTOMATIC) Group
);

FUNC(Adc_StreamNumSampleType, ADC_CODE) Adc_GetStreamLastPointer
(
  VAR(Adc_GroupType, AUTOMATIC) Group,
  P2P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) PtrToSamplePtr
);

#if (ADC_VERSION_INFO_API == STD_ON)
FUNC(void, ADC_CODE) Adc_GetVersionInfo
(
  P2VAR(Std_VersionInfoType , AUTOMATIC, ADC_APPL_DATA) versioninfo
);
#endif /* (ADC_VERSION_INFO_API == STD_ON) */

#define ADC_STOP_SEC_CODE
/* @violates @ref Adc_h_REF_1 Only preprocessor statements and comments before "#include" */
/*
* @violates @ref Adc_h_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ADC_H */

/** @} */
