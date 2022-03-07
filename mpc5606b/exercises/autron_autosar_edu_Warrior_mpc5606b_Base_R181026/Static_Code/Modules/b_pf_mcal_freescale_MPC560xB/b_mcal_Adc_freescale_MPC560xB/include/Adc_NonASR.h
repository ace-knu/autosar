/**
*   @file    Adc_NonASR.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - Non AUTOSAR driver API and development errors definition.
*   @details This file contains the ADC Non Autosar driver API and development errors definition.
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


#ifndef ADC_NONASR_H
#define ADC_NONASR_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_NonASR_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include'
* This is an Autosar memory management requirement.
*
* @section Adc_NonASR_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the 
* contents of a header being included twice. 
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Adc_NonASR_h_REF_3
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character signifiance and case
* sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Adc_NonASR_h_REF_4
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not more than 31 characters
* Violation is needed because of Autosar restrictions for naming File version check macros.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @implements     DADC00002 */
/*
* @violates @ref Adc_NonASR_h_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Std_Types.h"
/*
* @violates @ref Adc_NonASR_h_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Mcal.h"
/*
* @violates @ref Adc_NonASR_h_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Adc_Cfg.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Adc_NonASR.h
* @implements     DADC03024
*/
#define ADC_NONASR_VENDOR_ID                    (43)
/* @violates @ref Adc_NonASR_h_REF_4 Identifier exceeds 31 characters */
#define ADC_NONASR_AR_RELEASE_MAJOR_VERSION     (4)
/* @violates @ref Adc_NonASR_h_REF_4 Identifier exceeds 31 characters */
#define ADC_NONASR_AR_RELEASE_MINOR_VERSION     (0)
/* 
* @violates @ref Adc_NonASR_h_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
/* @violates @ref Adc_NonASR_h_REF_4 Identifier exceeds 31 characters */
#define ADC_NONASR_AR_RELEASE_REVISION_VERSION  (3)
#define ADC_NONASR_SW_MAJOR_VERSION             (1)
#define ADC_NONASR_SW_MINOR_VERSION             (0)
#define ADC_NONASR_SW_PATCH_VERSION             (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* @implements     DADC06002 */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if source file and Std_Types header file are of the same AutoSar version */
 #if ((ADC_NONASR_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_NONASR_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
 #error "AutoSar Version Numbers of Adc_NonASR.h and Std_Types.h are different"
 #endif
#endif

/* Check if source file and ADC configuration header file are of the same vendor */
#if (ADC_NONASR_VENDOR_ID != ADC_CFG_H_VENDOR_ID)
#error "Adc_NonASR.h and Adc_Cfg.h have different vendor ids"
#endif

/* Check if source file and ADC configuration header file are of the same Autosar version */
#if ((ADC_NONASR_AR_RELEASE_MAJOR_VERSION != ADC_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_NONASR_AR_RELEASE_MINOR_VERSION != ADC_CFG_H_AR_RELEASE_MINOR_VERSION) || \
     (ADC_NONASR_AR_RELEASE_REVISION_VERSION != ADC_CFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Adc_NonASR.h and Adc_Cfg.h are different"
#endif

/* Check if source file and ADC configuration header file are of the same software version */
#if ((ADC_NONASR_SW_MAJOR_VERSION != ADC_CFG_H_SW_MAJOR_VERSION) || \
     (ADC_NONASR_SW_MINOR_VERSION != ADC_CFG_H_SW_MINOR_VERSION) || \
     (ADC_NONASR_SW_PATCH_VERSION != ADC_CFG_H_SW_PATCH_VERSION))
#error "Software Version Numbers of Adc_NonASR.h and Adc_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*
* @brief          Non Autosar development errors.
* @details        Development errors generated for Non-Autsoar API's.
*
* @implements     DADC03025
* @note           All Non AUTOSAR error codes
*
*/
#if (ADC_SET_MODE_API == STD_ON)
#define ADC_E_SET_MODE                          ((uint8)0x1BU)
#endif
#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
#define ADC_E_PARAM_TRIGGER                     ((uint8)0x1CU)
#define ADC_E_INVALID_CHANNEL_CONFIG            ((uint8)0x23U)
#endif
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
/* @violates @ref Adc_NonASR_h_REF_4 Identifier exceeds 31 characters */
#define ADC_E_WRONG_ENABLE_CH_DISABLE_CH_GROUP  ((uint8)0x1DU)
/* 
* @violates @ref Adc_NonASR_h_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
/* @violates @ref Adc_NonASR_h_REF_4 Identifier exceeds 31 characters */
#define ADC_E_WRONG_ENABLE_CH_DISABLE_CH_ID     ((uint8)0x1EU)
#endif
#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
#define ADC_E_WRONG_CONF_THRHLD_GROUP           ((uint8)0x1FU)
#define ADC_E_WRONG_CONF_THRHLD_VALUE           ((uint8)0x20U)
#endif
#ifdef ADC_CTUV2_AUTO_DMA_FIFO_THRESHOLD
#if (ADC_CTUV2_AUTO_DMA_FIFO_THRESHOLD == STD_ON)
#define ADC_E_WRONG_CTUV2UNIT_INDEX             ((uint8)0x21U)
#define ADC_E_WRONG_CTUV2FIFO_INDEX             ((uint8)0x22U)
#endif
#endif

#ifdef ADC_ENABLE_BCTU
#if (ADC_ENABLE_BCTU == STD_ON)
#if (ADC_HW_TRIGGER_API == STD_ON)
#define ADC_BCTU_SETMODE_ID                     ((uint8)0x23U)
#define ADC_BCTU_E_SETMODE                      ((uint8)0x24U)
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#endif /* (ADC_ENABLE_BCTU == STD_ON) */
#endif /* ADC_ENABLE_BCTU */

#ifdef ADC_CTUV2_COMMON_ENABLE_NEW_API
#if (ADC_CTUV2_COMMON_ENABLE_NEW_API == STD_ON)
#define ADC_E_WRONG_CTUV2_TRIGGER               ((uint8)0x25U)
#define ADC_E_WRONG_CTUV2_CLCR_TRIGGER          ((uint8)0x26U)
#endif
#endif


/*
* @brief          Non AUTOSAR API's IDs.
* @details        Non AUTOSAR API's service IDs.
*
* @implements     DADC03026
* @note           All non AUTOSAR API's service IDs
*
*/
#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
#define ADC_HWRESULTREADGROUP_ID                (0x0DU)
#define ADC_ENABLECTUTRIGGER_ID                 (0x0EU)
#define ADC_DISABLECTUTRIGGER_ID                (0x0FU)
#endif
#if (ADC_SET_MODE_API == STD_ON)
#define ADC_SETMODE_ID                          (0x10U)
#endif
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
#define ADC_DUALCLOCKMODE_ID                    (0x11U)
#endif
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
#define ADC_ENABLE_CHANNEL_ID                   (0x12U)
#define ADC_DISABLE_CHANNEL_ID                  (0x13U)
#endif
#if (ADC_GET_INJECTED_CONVERSION_STATUS_API == STD_ON)
/* @violates @ref Adc_NonASR_h_REF_4 Identifier exceeds 31 characters */
#define ADC_GETINJECTEDCONVERSIONSTATUS_ID      (0x14U)
#endif
#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
#define ADC_CONFIGURE_THRESHOLD_ID              (0x15U)
#endif
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
#define ADC_SETCLOCKMODE_ID                     (0x31U)
#endif
#ifdef ADC_CTUV2_AUTO_DMA_FIFO_THRESHOLD
#if (ADC_CTUV2_AUTO_DMA_FIFO_THRESHOLD == STD_ON)
/* @violates @ref Adc_NonASR_h_REF_4 Identifier exceeds 31 characters */
#define ADC_CTUV2_AUTODMAFIFOTHRESHOLD_ID       (0x32U)
#endif
#endif

#ifdef ADC_ENABLE_BCTU
#if (ADC_ENABLE_BCTU == STD_ON)
#if (ADC_HW_TRIGGER_API == STD_ON)
#define ADC_BCTU_SOFTWARE_TRIG_ID               (0x33U)
#define ADC_BCTU_E_PARAM_TRIG                   (0x34U)
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#endif /* (ADC_ENABLE_BCTU == STD_ON) */
#endif /* ADC_ENABLE_BCTU */

#define ADC_UPDATEGROUPNUMBERSAMPLES_ID         (0x16U)
#define ADC_GETLASTSAMPLES_ID                   (0x17U)
#define ADC_GETSAMPLERESULT_ID                  (0x18U)

#ifdef ADC_CTUV2_COMMON_ENABLE_NEW_API
#if (ADC_CTUV2_COMMON_ENABLE_NEW_API == STD_ON)
/* @violates @ref Adc_NonASR_h_REF_4 Identifier exceeds 31 characters */
#define ADC_CTUV2_SET_TRG_HANDLER_CTRL_REGS_ID  (0x35U)
/* @violates @ref Adc_NonASR_h_REF_4 Identifier exceeds 31 characters */
#define ADC_CTUV2_EN_DIS_TRG_HANDLER_CTRL_REGS_ID  (0x36U)
/* @violates @ref Adc_NonASR_h_REF_4 Identifier exceeds 31 characters */
#define ADC_CTUV2_SET_CMD_LIST_HANDLER_CTRL_REGS_ID (0x37U)
/* @violates @ref Adc_NonASR_h_REF_4 Identifier exceeds 31 characters */
#define ADC_CTUV2_SET_TRIGGER_COMPARE_REGS_ID  (0x38U)
#endif
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief          Group Acess Mode type.
* @details        Used for value received by Tressos interface configuration.
*
* @api
* @implements     DADC03027
*/
typedef enum
{
  ADC_NORMAL = 0U, /**< @brief Normal mode */
  ADC_ALTERNATE    /**< @brief Alternate mode */
} Adc_NonASR_DualClockModeType;
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*
* @brief          NCMR structure type
* @details        This structure is used to enable/disable SW (not injected) trigger groups
*
* @api
* @implements     DADC06010
*/
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
typedef struct
{
 uint32 Adc_NCMR0; /* Precision configured channels */
 uint32 Adc_NCMR1; /* extended configured channels */
 uint32 Adc_NCMR2; /* External configured channels */
} Adc_NCMR_Type;
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#ifndef ADC_PRECOMPILE_SUPPORT
/* @violates @ref Adc_NonASR_h_REF_4 Identifier exceeds 31 characters */
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref ADC_h_REF_1 Only preprocessor statements and comments before "#include" */
/*
* @violates @ref Adc_NonASR_h_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

/* @violates @ref Adc_NonASR_h_REF_4 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref ADC_h_REF_1 Only preprocessor statements and comments before "#include" */
/*
* @violates @ref Adc_NonASR_h_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"
#endif

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define ADC_START_SEC_CODE
/* @violates @ref Adc_NonASR_h_REF_1 Only preprocessor statements and comments before "#include" */
/*
* @violates @ref Adc_NonASR_h_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

#if (ADC_SET_MODE_API == STD_ON)
FUNC (Std_ReturnType, ADC_CODE) Adc_SetMode
(
  VAR(Adc_SetModeType, AUTOMATIC) SetMode
);
#endif

#if (ADC_HW_TRIGGER_API == STD_ON)
#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
FUNC(void, ADC_CODE) Adc_EnableCtuTrigger
(
  VAR(Adc_GroupType, AUTOMATIC) Group,
  VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource
);

FUNC(void, ADC_CODE) Adc_DisableCtuTrigger
(
  VAR(Adc_GroupType, AUTOMATIC) Group,
  VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource
);

FUNC(Std_ReturnType, ADC_CODE) Adc_HwResultReadGroup
(
  VAR(Adc_GroupType, AUTOMATIC) Group,
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataPtr
);
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#endif /* (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) */

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
FUNC(Std_ReturnType, ADC_CODE) Adc_SetClockMode
(
  VAR(Adc_NonASR_DualClockModeType, AUTOMATIC) ClockMode
);
#endif

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
FUNC(void, ADC_CODE) Adc_EnableChannel
(
  VAR(Adc_GroupType, AUTOMATIC) GroupId,
  VAR(Adc_ChannelType, AUTOMATIC) ChannelId
);
FUNC(void, ADC_CODE) Adc_DisableChannel
(
  VAR(Adc_GroupType, AUTOMATIC) GroupId,
  VAR(Adc_ChannelType, AUTOMATIC) ChannelId
);
#endif

#if (ADC_GET_INJECTED_CONVERSION_STATUS_API == STD_ON)
FUNC(Adc_StatusType, ADC_CODE) Adc_GetInjectedConversionStatus
(
  VAR(Adc_HwUnitType, AUTOMATIC) unit
);
#endif

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
FUNC(Std_ReturnType, ADC_CODE) Adc_ConfigureThreshold
(
  VAR(Adc_GroupType, AUTOMATIC) GroupId,
  VAR(Adc_ValueGroupType, AUTOMATIC) LowValue,
  VAR(Adc_ValueGroupType, AUTOMATIC) HighValue
);
#endif

#ifdef ADC_CTUV2_AUTO_DMA_FIFO_THRESHOLD
#if (ADC_CTUV2_AUTO_DMA_FIFO_THRESHOLD == STD_ON) || defined(__DOXYGEN__)
FUNC(Std_ReturnType, ADC_CODE) Adc_GetCTU2DmaLastSampleIndex
(
  VAR(uint8, AUTOMATIC) CtuIdx,
  VAR(uint8, AUTOMATIC) FifoIdx,
  P2VAR(uint16, AUTOMATIC, ADC_APPL_DATA) PtrToSampleIndex
);
#endif /* if (ADC_CTUV2_AUTO_DMA_FIFO_THRESHOLD == STD_ON) || defined(__DOXYGEN__) */
#endif /* ifdef ADC_CTUV2_AUTO_DMA_FIFO_THRESHOLD */

#ifdef ADC_ENABLE_BCTU
#if (ADC_ENABLE_BCTU == STD_ON)
#if (ADC_HW_TRIGGER_API == STD_ON)

#if (BCTU_SOFT_TRG_API == STD_ON)
FUNC(Std_ReturnType, ADC_CODE) Adc_BCtuStartSoftwareTrigger
(
  VAR(uint8, AUTOMATIC) InputTrigger
);
#endif
#if (BCTU_SET_MODE_API == STD_ON)
FUNC(Std_ReturnType, ADC_CODE) Adc_BCtuSetMode
(
    VAR(BCtu_OperationMode, AUTOMATIC) OperationMode
);
#endif

#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#endif /* (ADC_ENABLE_BCTU == STD_ON) */
#endif /* ADC_BCTU_ENABLED */

#ifdef ADC_NOTIFY_ON_STREAM_COMPLETED
#if (STD_ON == ADC_NOTIFY_ON_STREAM_COMPLETED)
#if (STD_ON == ADC_GROUP_UPDATE_NUMBER_SAMPLES_API)
FUNC(Std_ReturnType, ADC_CODE) Adc_GroupUpdateNumberSamples
                (
                  VAR(Adc_GroupType, AUTOMATIC) Group,
                  VAR(Adc_StreamNumSampleType, ADC_APPL_DATA) NumDMASamples
                );
#endif /* #if (STD_ON == ADC_GROUP_UPDATE_NUMBER_SAMPLES_API) */
#if (STD_ON == ADC_GROUP_GET_LAST_SAMPLE_API)
FUNC(Std_ReturnType, ADC_CODE) Adc_GroupGetLastSamples
                (
                  VAR(Adc_GroupType, AUTOMATIC) Group,
                  P2VAR(Adc_StreamNumSampleType, AUTOMATIC, ADC_APPL_DATA) PtrNumberSamples,
                  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) PtrSampleValues
                );
#endif /* if (STD_ON == ADC_GROUP_GET_LAST_SAMPLE_API) */
#if (STD_ON == ADC_READ_GROUP_SAMPLE_RESULT_API)
FUNC(Std_ReturnType, ADC_CODE) Adc_ReadGroupSampleResult
                (
                  VAR(Adc_GroupType, AUTOMATIC) Group,
                  VAR(Adc_StreamNumSampleType, ADC_APPL_DATA) SampleIndex,
                  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) PtrSampleValues
                );
#endif /* if (STD_ON == ADC_READ_GROUP_SAMPLE_RESULT_API)*/
#endif /* if (STD_ON == ADC_NOTIFY_ON_STREAM_COMPLETED) */
#endif /* ifdef ADC_NOTIFY_ON_STREAM_COMPLETED */

#ifdef ADC_CTUV2_COMMON_ENABLE_NEW_API
#if (ADC_CTUV2_COMMON_ENABLE_NEW_API == STD_ON) || defined(__DOXYGEN__)
FUNC(Std_ReturnType, ADC_CODE) Adc_SetCTU2TriggerHandlerCtrlRegs
/* @violates @ref Adc_NonASR_h_REF_4 Identifier exceeds 31 characters */
(
  VAR(uint8, AUTOMATIC) Trigger,
  VAR(uint8, AUTOMATIC) Thcr_value
);
FUNC(Std_ReturnType, ADC_CODE) Adc_CTU2TriggerHandlerCtrlRegsEnableDisable
/* @violates @ref Adc_NonASR_h_REF_4 Identifier exceeds 31 characters */
(
  VAR(uint8, AUTOMATIC) Trigger,
  VAR(boolean, AUTOMATIC) Enable
);
FUNC(Std_ReturnType, ADC_CODE) Adc_SetCTU2CmdListHandlerCtrlRegs
/* @violates @ref Adc_NonASR_h_REF_4 Identifier exceeds 31 characters */
(
  VAR(uint8, AUTOMATIC) Trigger,
  VAR(uint8, AUTOMATIC) clcr_value
);
FUNC(Std_ReturnType, ADC_CODE) Adc_SetCTU2TriggerCompareRegs
(
  VAR(uint8, AUTOMATIC) Trigger,
  VAR(uint16, AUTOMATIC) compare_value
);
#endif
#endif

#define ADC_STOP_SEC_CODE
/* @violates @ref Adc_NonASR_h_REF_1 Only preprocessor statements and comments before "#include" */
/*
* @violates @ref Adc_NonASR_h_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ADC_NONASR_H */

/** @} */
