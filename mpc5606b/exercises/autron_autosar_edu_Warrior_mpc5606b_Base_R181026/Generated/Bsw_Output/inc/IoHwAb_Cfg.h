/*******************************************************************************
**  FILE-NAME: IoHwAb_Cfg.h                                                   **
**                                                                            **
**  MODULE-NAME: AUTOSAR I/O Hardware Abstraction Module                      **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 1.1.21                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/
/*
 * INPUT FILE:    E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Ecud_IoHwAb.arxml
 *                E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Mcal\Ecud_Pwm.arxml
 *                E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Mcal\Ecud_Spi.arxml
 *                E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Mcal\Ecud_Dio.arxml
 *                E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Mcal\Ecud_Icu.arxml
 *                E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Mcal\Ecud_Port.arxml
 *                E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Mcal\Ecud_Adc.arxml
 *                E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Mcal\Ecud_Mcu.arxml
 *                E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Mcal\Ecud_Gpt.arxml
 *                E:\00_AUTOSAR\Project\autron_autosar_edu_Warrior_mpc5606b_Base_R181026\Configuration\ECU\Ecud_Os.arxml
 * GENERATED ON:  This timestamp is removed.
 */

#ifndef IOHWAB_CFG_H
#define IOHWAB_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "IoHwAb_Types.h"
#include "Det.h"
#include "Rte_Type.h"
#include "Dio.h"
#include "Port.h"
#include "Adc.h"
#include "Icu.h"
#include "Gpt.h"
#include "Pwm.h"
#include "Dem.h"

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define IOHWAB_AR_RELEASE_MAJOR_VERSION                    (4)
#define IOHWAB_AR_RELEASE_MINOR_VERSION                    (0)
#define IOHWAB_AR_RELEASE_REVISION_VERSION                 (3)
#define IOHWAB_SW_MAJOR_VERSION                            (1)
#define IOHWAB_SW_MINOR_VERSION                            (1)
#define IOHWAB_SW_PATCH_VERSION                            (21)
#define IOHWAB_VENDOR_ID                                   ((uint16)76)
#define IOHWAB_MODULE_ID                                   ((uint16)254)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Pre-compile option for Development Error Checking */
#define IOHWAB_DEV_ERROR_DETECT                       (STD_ON)

/* Pre-compile option for Version Info API */
#define IOHWAB_VERSION_INFO_API                       (STD_OFF)

/* Pre-compile option for Digtal Direct */
#define IOHWAB_USE_DIG_DIR                            (STD_ON)

/* Pre-compile option for Analog Input Direct */
#define IOHWAB_USE_ANA_IN_DIR                         (STD_ON)

/* Pre-compile option for PWM */
#define IOHWAB_USE_PWM                                (STD_ON)

/* Pre-compile option for Gpt */
#define IOHWAB_USE_GPT                                (STD_ON)

/* Pre-compile option for Icu */
#define IOHWAB_USE_ICU                                (STD_ON)

/* Pre-compile option for Ocu */
#define IOHWAB_USE_OCU                                (STD_OFF)

/* Pre-compile option for IO Manager */
#define IOHWAB_USE_IO_MAN                             (STD_ON)

/* Pre-compile option for FastTimer in IO Manager */
#define IOHWAB_USE_IO_MAN_FASTTIMER                   (STD_OFF)

/* Pre-compile option for GptTimer in IO Manager */
#define IOHWAB_USE_IO_MAN_GPTTIMER                    (STD_ON)

/* Pre-compile option for Analog Input */
#define IOHWAB_USE_ANA_IN                             (STD_ON)

/* Pre-compile option for Digital Input */
#define IOHWAB_USE_DIG_IN                             (STD_OFF)

/* Pre-compile option for using MC33972 */
#define IOHWAB_USE_MC33972                            (STD_OFF)

/* Pre-compile option for external interrupt in MC33972 */
#define IOHWAB_MC33972_EXTINT                         (STD_OFF)

/* Pre-compile option for Digital Output */
#define IOHWAB_USE_DIG_OUT                            (STD_OFF)

/* Pre-compile option for using L9826 */
#define IOHWAB_USE_L9826                              (STD_OFF)

/* Pre-compile option for diagnosis info in L9826 */
#define IOHWAB_USE_L9826_DIAG                         (STD_OFF)

/* Pre-compile option for using L99MC6 */
#define IOHWAB_USE_L99MC6                             (STD_OFF)

/* Pre-compile option for using TLE7240SL */
#define IOHWAB_USE_TLE7240SL                          (STD_OFF)

/* Pre-compile option for diagnosis info in TLE7240SL */
#define IOHWAB_USE_TLE7240SL_DIAG                     (STD_OFF)

/* Pre-compile option for Input Supply Switch */
#define IOHWAB_USE_IN_SUP_SWT                         (STD_OFF)

/* Pre-compile option for Digital Supply Switch */
#define IOHWAB_USE_DIG_SUP_SWT                        (STD_OFF)

/* Pre-compile option for Digital Supply Switch in low power mode */
#define IOHWAB_USE_DIG_SUP_SWT_LP                     (STD_OFF)

/* Pre-compile option for Analog Supply Switch */
#define IOHWAB_USE_ANA_SUP_SWT                        (STD_OFF)

/* Pre-compile option for Voltage Monitoring */
#define IOHWAB_USE_VOL_MON                            (STD_OFF)

/* Pre-compile option for Low Power Flag */
#define IOHWAB_USE_LP_FLAG                            (STD_OFF)

/* Pre-compile option for Pm Module */
#define IOHWAB_USE_PM_MODULE                          (STD_OFF)

/* Pre-compile option for Dem Event Params */
#define IOHWAB_USE_DEM_EVENT                          (STD_ON)


/* polyspace:begin<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation */
/* polyspace:begin<MISRA-C:9.14:Not a defect:Justify with annotations> No Impact of this rule violation */
/* polyspace:begin<MISRA-C:19.4:Not a defect:Justify with annotations> No Impact of this rule violation */
/*******************************************************************************
**                      General                                               **
*******************************************************************************/
#define IOHWAB_MCAL_FREESCALE_MPC560XB                

#define IOHWAB_GEN_NUM_PORT_PIN_CHS                   (12U)

#define IOHWAB_ADC_READDIRECT_MAX_DELAY               (65535U)

#define IOHWAB_E_BUSY                                 (DemConf_DemEventParameter_IOHWAB_E_BUSY)
#define IOHWAB_E_PROC_FAIL                            (DemConf_DemEventParameter_IOHWAB_E_PROC_FAIL)
#define IOHWAB_E_SETUP_FAIL                           (DemConf_DemEventParameter_IOHWAB_E_SETUP_FAIL)
#define IOHWAB_E_WRONG_PARAM                          (DemConf_DemEventParameter_IOHWAB_E_WRONG_PARAM)
#define IOHWAB_E_WRONG_SETTING                        (DemConf_DemEventParameter_IOHWAB_E_WRONG_SETTING)
#define IOHWAB_E_WRONG_STATE                          (DemConf_DemEventParameter_IOHWAB_E_WRONG_STATE)

typedef struct STag_IoHwAb_GenInfoPropertyType
{
  Dio_ChannelType ddDioChType;
  Port_PinType ddPortPinType;
  uint8 ucPolar;
  Port_PinDirectionType ddCfgPinDir;
}IoHwAb_GenInfoPropertyType;

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(IoHwAb_GenInfoPropertyType, IOHWAB_CONST)IoHwAb_GaaGenInfos[];
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Digital Direct                                        **
*******************************************************************************/
#define IOHWAB_DIGDIR_NUM_LGC                         (5U)

#define IoHwAbDigitalDirectLogical_LED01              (0U)
#define IoHwAbDigitalDirectLogical_S01                (1U)
#define IoHwAbDigitalDirectLogical_S02                (2U)
#define IoHwAbDigitalDirectLogical_S03                (3U)
#define IoHwAbDigitalDirectLogical_S04                (4U)

#define IOHWAB_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
/* Array of words for bidirectional module direction info */
extern VAR(Port_PinDirectionType, IOHWAB_VAR)IoHwAb_GaaDigDirPinDir[];
#define IOHWAB_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(IoHwAb_IndexType, IOHWAB_CONST)IoHwAb_GaaDigDirChIdx[];
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Analog Input Direct                                   **
*******************************************************************************/
#define IOHWAB_ANAINDIR_NUM_ADC_GROUPS                (1U)

#define IOHWAB_ANAINDIR_NUM_LGC                       (1U)

#define IOHWAB_ANAINDIR_MAX_BUF_LENGTH                (1U)

#define IoHwAbAnalogInputDirectLogical_01             (0U)

typedef struct STag_IoHwAb_AnaInDirInfoPropertyType
{
  Adc_GroupType ddAdcGroupType;
  uint8 ucAdcGroupLength;
  uint8 ucAdcHwUnitId;
  uint8 ucAdcHwUnitNum;
#if (IOHWAB_USE_ANA_IN == STD_ON)
  uint8 ucAdcAllGroupId;
#endif /* (IOHWAB_USE_ANA_IN == STD_ON) */
}IoHwAb_AnaInDirInfoPropertyType;

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(IoHwAb_AnaInDirInfoPropertyType, IOHWAB_CONST)IoHwAb_GaaAnaInDirInfos[];
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


#define IOHWAB_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
extern VAR(Adc_ValueGroupType, IOHWAB_VAR)IoHwAb_GaaAnaInDirAdcResults[];
#define IOHWAB_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      IO Manager                                            **
*******************************************************************************/
/* /Gpt/Gpt/GptChannelConfigSet/GptChannelConfiguration_IoHwAbTest */
#define IOHWAB_IOM_GPT_TIMER_ID                       (GptConf_GptChannelConfiguration_GptChannelConfiguration_IoHwAbTest)

#define IOHWAB_IOM_GPT_TICKS_FOR_1US                  (1U)

#define IOHWAB_IOM_TASK_FG1                           (OsTask_BSW_FG1_IOManager)

#define IOHWAB_IOM_TASK_FG2                           (OsTask_BSW_FG2_IOManager)

#define IOHWAB_IOM_TASK_FG1_FUNC                      TASK(OsTask_BSW_FG1_IOManager)

#define IOHWAB_IOM_TASK_FG2_FUNC                      TASK(OsTask_BSW_FG2_IOManager)

#define IOHWAB_IOM_MULTI_ACT_DELAY                    (200U)


/*******************************************************************************
**                      Analog Input                                          **
*******************************************************************************/
#define IOHWAB_ANAIN_NUM_LGC                          (1U)

#define IOHWAB_ANAIN_NUM_ADC_ALLGROUP                 (1U)

#define IOHWAB_ANAIN_NUM_MAX_CHS_IN_UNIT              (32U)

#define IoHwAbAnalogInputLogical_PD00                 (0U)

#define IOHWAB_ANAIN_BUSY_ERR                         (RTE_E_IoHwAb_If_AnaIn_E_BUSY)

#define IOHWAB_ADCHWUNIT_MAX_NUM                      (1U)

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
void AdcAllGrp0Nf(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
extern VAR(boolean, IOHWAB_VAR)IoHwAb_GblAnaInAdcIsBusy[];
#define IOHWAB_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

typedef struct STag_IoHwAb_AnaInInfoPropertyType
{
  uint8 ucAdcGroupId;
  uint8 ucAdcHwUnitId;
  uint8 ucAdcHwUnitNum;
  Adc_GroupType ddAdcGroupType;
  uint8 ucIndexInResultBuffer;
  uint16 usDefVal;
  uint8 ucFiltCst;
}IoHwAb_AnaInInfoPropertyType;

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(IoHwAb_AnaInInfoPropertyType, IOHWAB_CONST)IoHwAb_GaaAnaInInfos[];
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

typedef struct STag_IoHwAb_AnaInAllGroupInfoPropertyType
{
  Adc_GroupType ddAdcAllGroupType;
  uint8 ucAdcHwUnitId;
  uint8 ucAdcHwUnitNum;  
}IoHwAb_AnaInAllGroupInfoPropertyType;

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(IoHwAb_AnaInAllGroupInfoPropertyType, IOHWAB_CONST)IoHwAb_GaaAnaInAllGroupInfos[];
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

typedef struct STag_IoHwAb_AnaInResultBufferType
{
  boolean blEnable;
  uint16 usRawResult;
  uint16 usFiltResult;
}IoHwAb_AnaInResultBufferType;

#define IOHWAB_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
extern VAR(IoHwAb_AnaInResultBufferType, IOHWAB_VAR)IoHwAb_GaaAnaInFiltResults[];
#define IOHWAB_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

typedef struct STag_IoHwAb_AnaInAdcResultBufferType
{
  Adc_ValueGroupType usOneChBuffer;
  Adc_ValueGroupType usAllChBuffer[IOHWAB_ANAIN_NUM_ADC_ALLGROUP]
    [IOHWAB_ANAIN_NUM_MAX_CHS_IN_UNIT];
}IoHwAb_AnaInAdcResultBufferType;

#define IOHWAB_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
extern VAR(IoHwAb_AnaInAdcResultBufferType, IOHWAB_VAR)IoHwAb_GaaAnaInAdcResults;
#define IOHWAB_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Digital Input                                         **
*******************************************************************************/


/*******************************************************************************
**                      Digital Output                                        **
*******************************************************************************/


/*******************************************************************************
**                      Input Supply                                          **
*******************************************************************************/


/*******************************************************************************
**                      Voltage Monitoring                                    **
*******************************************************************************/


/*******************************************************************************
**                      ICU                                                   **
*******************************************************************************/
#define IOHWAB_ICU_GET_INPUT_STATE_API                (STD_ON)

#define IOHWAB_ICU_TIMESTAMP_API                      (STD_ON)

#define IOHWAB_ICU_EDGE_COUNT_API                     (STD_ON)

#define IOHWAB_ICU_EDGE_DETECT_API                    (STD_ON)

#define IOHWAB_ICU_SIGNAL_MEASUREMENT_API             (STD_ON)

#define IOHWAB_ICU_GET_TIME_ELAPSED_API               (STD_ON)

#define IOHWAB_ICU_GET_DUTY_CYCLE_VALUES_API          (STD_ON)

#define IOHWAB_ICU_NUM_LGC                            (1U)

#define IoHwAbIcuLogical_Timestamp_PA8                (0U)

/* Icu_SetActivationCondition */
typedef P2FUNC(void, IOHWAB_CODE, Icu_SetActivationConditionFuncPtr)(Icu_ChannelType, Icu_ActivationType);
extern Icu_SetActivationConditionFuncPtr IoHwAb_GpIcuSetActivationCondition;

/* Icu_DisableNotificationFuncPtr */
typedef P2FUNC(void, IOHWAB_CODE, Icu_DisableNotificationFuncPtr)(Icu_ChannelType);
extern Icu_DisableNotificationFuncPtr IoHwAb_GpIcuDisableNotification;

/* Icu_EnableNotificationFuncPtr */
typedef P2FUNC(void, IOHWAB_CODE, Icu_EnableNotificationFuncPtr)(Icu_ChannelType);
extern Icu_EnableNotificationFuncPtr IoHwAb_GpIcuEnableNotification;

/* Icu_GetInputStateFuncPtr */
typedef P2FUNC(Icu_InputStateType, IOHWAB_CODE, Icu_GetInputStateFuncPtr)(Icu_ChannelType);
extern Icu_GetInputStateFuncPtr IoHwAb_GpIcuGetInputState;

/* Icu_StartTimestampFuncPtr */
typedef P2FUNC(void, IOHWAB_CODE, Icu_StartTimestampFuncPtr)(Icu_ChannelType, Icu_ValueType*, uint16, uint16);
extern Icu_StartTimestampFuncPtr IoHwAb_GpIcuStartTimestamp;

/* Icu_StopTimestampFuncPtr */
typedef P2FUNC(void, IOHWAB_CODE, Icu_StopTimestampFuncPtr)(Icu_ChannelType);
extern Icu_StopTimestampFuncPtr IoHwAb_GpIcuStopTimestamp;

/* Icu_GetTimestampIndexFuncPtr */
typedef P2FUNC(Icu_IndexType, IOHWAB_CODE, Icu_GetTimestampIndexFuncPtr)(Icu_ChannelType);
extern Icu_GetTimestampIndexFuncPtr IoHwAb_GpIcuGetTimestampIndex;

/* Icu_ResetEdgeCountFuncPtr */
typedef P2FUNC(void, IOHWAB_CODE, Icu_ResetEdgeCountFuncPtr)(Icu_ChannelType);
extern Icu_ResetEdgeCountFuncPtr IoHwAb_GpIcuResetEdgeCount;

/* Icu_EnableEdgeCountFuncPtr */
typedef P2FUNC(void, IOHWAB_CODE, Icu_EnableEdgeCountFuncPtr)(Icu_ChannelType);
extern Icu_EnableEdgeCountFuncPtr IoHwAb_GpIcuEnableEdgeCount;

/* Icu_DisableEdgeCountFuncPtr */
typedef P2FUNC(void, IOHWAB_CODE, Icu_DisableEdgeCountFuncPtr)(Icu_ChannelType);
extern Icu_DisableEdgeCountFuncPtr IoHwAb_GpIcuDisableEdgeCount;

/* Icu_GetEdgeNumbersFuncPtr */
typedef P2FUNC(Icu_EdgeNumberType, IOHWAB_CODE, Icu_GetEdgeNumbersFuncPtr)(Icu_ChannelType);
extern Icu_GetEdgeNumbersFuncPtr IoHwAb_GpIcuGetEdgeNumbers;

/* Icu_EnableEdgeDetectionFuncPtr */
typedef P2FUNC(void, IOHWAB_CODE, Icu_EnableEdgeDetectionFuncPtr)(Icu_ChannelType);
extern Icu_EnableEdgeDetectionFuncPtr IoHwAb_GpIcuEnableEdgeDetection;

/* Icu_DisableEdgeDetectionFuncPtr */
typedef P2FUNC(void, IOHWAB_CODE, Icu_DisableEdgeDetectionFuncPtr)(Icu_ChannelType);
extern Icu_DisableEdgeDetectionFuncPtr IoHwAb_GpIcuDisableEdgeDetection;

/* Icu_StartSignalMeasurementFuncPtr */
typedef P2FUNC(void, IOHWAB_CODE, Icu_StartSignalMeasurementFuncPtr)(Icu_ChannelType);
extern Icu_StartSignalMeasurementFuncPtr IoHwAb_GpIcuStartSignalMeasurement;

/* Icu_StopSignalMeasurementFuncPtr */
typedef P2FUNC(void, IOHWAB_CODE, Icu_StopSignalMeasurementFuncPtr)(Icu_ChannelType);
extern Icu_StopSignalMeasurementFuncPtr IoHwAb_GpIcuStopSignalMeasurement;

/* Icu_GetTimeElapsedFuncPtr */
typedef P2FUNC(Icu_ValueType, IOHWAB_CODE, Icu_GetTimeElapsedFuncPtr)(Icu_ChannelType);
extern Icu_GetTimeElapsedFuncPtr IoHwAb_GpIcuGetTimeElapsed;

/* Icu_GetDutyCycleValuesFuncPtr */
typedef P2FUNC(void, IOHWAB_CODE, Icu_GetDutyCycleValuesFuncPtr)(Icu_ChannelType, Icu_DutyCycleType*);
extern Icu_GetDutyCycleValuesFuncPtr IoHwAb_GpIcuGetDutyCycleValues;

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Icu_ChannelType, IOHWAB_CONST)IoHwAb_GaaIcuChIdx[];
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      GPT                                                   **
*******************************************************************************/
#define IOHWAB_GPT_TIME_ELAPSED_API                   (STD_ON)

#define IOHWAB_GPT_TIME_REMAINING_API                 (STD_ON)

#define IOHWAB_GPT_ENABLE_DISABLE_NOTIFICATION_API    (STD_ON)

#define IOHWAB_GPT_NUM_LGC                            (2U)

#define IoHwAbGptLogical0                             (0U)
#define IoHwAbGptLogical_EMIOS4                       (1U)

/* Gpt_StartTimer */
typedef P2FUNC(void, IOHWAB_CODE, Gpt_StartTimerFuncPtr)(Gpt_ChannelType, Gpt_ValueType);
extern Gpt_StartTimerFuncPtr IoHwAb_GpGptStartTimer;

/* Gpt_StopTimer */
typedef P2FUNC(void, IOHWAB_CODE, Gpt_StopTimerFuncPtr)(Gpt_ChannelType);
extern Gpt_StopTimerFuncPtr IoHwAb_GpGptStopTimer;

/* Gpt_GetTimeElapsed */
typedef P2FUNC(Gpt_ValueType, IOHWAB_CODE, Gpt_GetTimeElapsedFuncPtr)(Gpt_ChannelType);
extern Gpt_GetTimeElapsedFuncPtr IoHwAb_GpGptGetTimeElapsed;

/* Gpt_GetTimeRemaining */
typedef P2FUNC(Gpt_ValueType, IOHWAB_CODE, Gpt_GetTimeRemainingFuncPtr)(Gpt_ChannelType);
extern Gpt_GetTimeRemainingFuncPtr IoHwAb_GpGptGetTimeRemaining;

/* Gpt_DisableNotification */
typedef P2FUNC(void, IOHWAB_CODE, Gpt_DisableNotificationFuncPtr)(Gpt_ChannelType);
extern Gpt_DisableNotificationFuncPtr IoHwAb_GpGptDisableNotification;

/* Gpt_EnableNotification */
typedef P2FUNC(void, IOHWAB_CODE, Gpt_EnableNotificationFuncPtr)(Gpt_ChannelType);
extern Gpt_EnableNotificationFuncPtr IoHwAb_GpGptEnableNotification;

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Gpt_ChannelType, IOHWAB_CONST)IoHwAb_GaaGptChIdx[];
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      PWM                                                   **
*******************************************************************************/
#define IOHWAB_PWM_SET_DUTY_CYCLE_API                 (STD_ON)

#define IOHWAB_PWM_SET_PERIOD_AND_DUTY_API            (STD_ON)

#define IOHWAB_PWM_SET_OUTPUT_TO_IDLE_API             (STD_ON)

#define IOHWAB_PWM_GET_OUTPUT_STATE_API               (STD_ON)

#define IOHWAB_PWM_NOTIFICATION_SUPPORTED             (STD_ON)

#define IOHWAB_PWM_NUM_LGC                            (1U)

#define IoHwAbPwm_0                                   (0U)

/* Pwm_SetDutyCycle */
typedef P2FUNC(void, IOHWAB_CODE, Pwm_SetDutyCycleFuncPtr)(Pwm_ChannelType, uint16);
extern Pwm_SetDutyCycleFuncPtr IoHwAb_GpPwmSetDutyCycle;

/* Pwm_SetPeriodAndDuty */
typedef P2FUNC(void, IOHWAB_CODE, Pwm_SetPeriodAndDutyFuncPtr)(Pwm_ChannelType, Pwm_PeriodType, uint16);
extern Pwm_SetPeriodAndDutyFuncPtr IoHwAb_GpPwmSetPeriodAndDuty;

/* Pwm_SetOutputToIdle */
typedef P2FUNC(void, IOHWAB_CODE, Pwm_SetOutputToIdleFuncPtr)(Pwm_ChannelType);
extern Pwm_SetOutputToIdleFuncPtr IoHwAb_GpPwmSetOutputToIdle;

/* Pwm_GetOutputState */
typedef P2FUNC(Pwm_OutputStateType, IOHWAB_CODE, Pwm_GetOutputStateFuncPtr)(Pwm_ChannelType);
extern Pwm_GetOutputStateFuncPtr IoHwAb_GpPwmGetOutputState;

/* Pwm_DisableNotification */
/* Disabled by MCAL setting */
typedef P2FUNC(void, IOHWAB_CODE, Pwm_DisableNotificationFuncPtr)(Pwm_ChannelType);
extern Pwm_DisableNotificationFuncPtr IoHwAb_GpPwmDisableNotification;

/* Pwm_EnableNotification */
/* Disabled by MCAL setting */
typedef P2FUNC(void, IOHWAB_CODE, Pwm_EnableNotificationFuncPtr)(Pwm_ChannelType, Pwm_EdgeNotificationType);
extern Pwm_EnableNotificationFuncPtr IoHwAb_GpPwmEnableNotification;

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Pwm_ChannelType, IOHWAB_CONST)IoHwAb_GaaPwmChIdx[];
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      OCU                                                   **
*******************************************************************************/



/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/* polyspace:end<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation */
/* polyspace:end<MISRA-C:9.14:Not a defect:Justify with annotations> No Impact of this rule violation */
/* polyspace:end<MISRA-C:19.4:Not a defect:Justify with annotations> No Impact of this rule violation */
#endif /* IOHWAB_CFG_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
