/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : EcuM_PCTypes.h                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR EcuM Module                                           **
**                                                                            **
**  PURPOSE   : Provision of pre-compile time parameters                      **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                              Revision History                              **
********************************************************************************
** Revision   Date          By            Description                         **
********************************************************************************
** 2.7.2      03-Apr-2017   Sanghoon Bae  Redmine #7886                       **
** 2.4.1      27-May-2015   Jihoon Jung   Redmine #2550                       **
** 2.2.1      26-Dec-2014   Daejun Park   Redmine #1879                       **
**                                        -Update to AUTRON template          **
** 2.1.0      24-Sep-2014   Daejun Park   Redmine #1367                       **
** 1.1.0      07-Mar-2014   Daejun Park   Move macro definition               **
**                                        to EcuM_Types.h                     **
** 1.0.10     04-Jul-2013   Daejun Park   CR~129, XAR~581 : EcuM library      **
**                                        -Change array variables in          **
**                                         EcuM_GaaOsTaskEventMask to pointer **
**                                         variables for library              **
**                                        -Do not pre-define array size       **
**                                         for library                        **
** 1.0.0      04-Mar-2013   Daejun Park   Initial version                     **
*******************************************************************************/

#ifndef ECUM_PCTYPES_H
#define ECUM_PCTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "EcuM.h"

#include "Mcu.h"
#include "ComStack_Types.h"
#include "Os.h"

/*******************************************************************************
**                       Global Data                                          **
*******************************************************************************/
/* Structure for EcuM Sleep Modes */
typedef struct STag_EcuM_SleepModeConfigType
{
  /* Status Mask for Wakeup Source */
  EcuM_WakeupSourceType ddWakeupSourceMask;

  /* Mcu Mode type */
  Mcu_ModeType ddMcuSleepModeType;

  /* Sleep Mode ID */
  uint8 ucSleepModeId;

  /* Sleep Mode suspend */
  boolean blSleepModeSuspnd;
} EcuM_SleepModeConfigType;

/* Structure for EcuM Wakeup Source */
typedef struct STag_EcuM_WakeupSource
{
  /* RAM Pointer to EcuM_GaaWakeupCounter */
  P2VAR(uint16, AUTOMATIC, ECUM_CONFIG_DATA) pEcuMWakeupCounter;

  /* RAM Pointer to EcuM_GaaWakeupStatus */
  P2VAR(EcuM_WakeupStatusType, AUTOMATIC, ECUM_CONFIG_DATA)
  pEcuMWakeupStatus;

  /* Wakeup Source Id */
  EcuM_WakeupSourceType ddWakeupSourceId;

  /* ComM Channel ID */
  uint16 usComMChannel;

  /* Timer Count for Validation */
  uint16 usWakeupValidationTimeOut;

  /* Reset Reason Detected by MCU Driver */
  uint8 ucResetReason;

  /* Wakeup Source Polling */
  boolean blWakeupSourcePolling;
} EcuM_WakeupSource;

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)

/* Structure for EcuM Alarm Clock  */
typedef struct STag_EcuM_AlarmClock
{
  /* Reference to EcuMFlexUserConfig from EcuMAlarmClockUser */
  EcuM_UserType ddUser;

  /* Alarm clock timeout */
  uint16 usAlarmClockTimeOut;

  /* Alarm clock Id */
  uint8 ucAlarmClockId;
  
} EcuM_AlarmClock;
#endif /* End of if (ECUM_ALARM_CLOCK_PRESENT == STD_ON) */

 /* Structure for EcuM Shutdown target */
typedef struct STag_EcuM_LastShutdown
{
  /* Most recent shutdown target / Last shutdown target of EcuM */
  EcuM_StateType ddMostRecentTarget;

  /* Next recent shutdown target / Last shutdown target of EcuM */
  EcuM_StateType ddNextRecentTarget;

  /* Most recent shutdown cause. */
  EcuM_ShutdownCauseType ddMostRecentShutDownCause;

  /* Next recent shutdown cause */
  EcuM_ShutdownCauseType ddNextRecentShutDownCause;

  /* Most Recent sleep mode index */
  uint8 ucMostRecentSlpModeId;

  /* Next Recent sleep mode index */
  uint8 ucNextRecentSlpModeId;

  /* Most Recent reset mode index */
  uint8 ucMostRecentRstModeId;

  /* Next Recent reset mode index */
  uint8 ucNextRecentRstModeId;
} EcuM_LastShutdown;

 /* Structure for EcuM Shutdown cause,target and boot target */
typedef struct STag_EcuM_ShutdownCauseTarget
{
  /*  variable to store current shutdownCause */
  EcuM_ShutdownCauseType ddShutdownCause;

  /*  Variable to indicate Boot Target */
  EcuM_BootTargetType ddBootTarget;

  /*  variable to store selected shutdown target of EcuM */
  uint8 ucSelectShutdownTarget;

  /*  variable to store current sleep mode of EcuM */
  uint8 ucSleepMode;

  /*  variable to store current reset mode of EcuM */
  uint8 ucResetMode;

} EcuM_ShutdownCauseTarget;

#if (ECUM_DEV_ERROR_DETECT == STD_ON)
typedef struct STag_EcuM_DetErrorStatus
{
  /*  variable to store last Instance ID */
  uint8 ucInstanceId;

  /*  variable to store last API ID */
  uint8 ucApiId;

  /*  variable to store last Error ID */
  uint8 ucErrorId;
} EcuM_DetErrorStatus;
#endif

#define ECUM_START_SEC_CONST_8
#include "MemMap.h"

/* Array for EcuMResetMode to identify the reset mode in service like
EcuM_SelectShutdownTarget */
/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
   extern CONST(uint8, ECUM_CONST) EcuM_GaaResetModeId[];

/* Array for EcuMShutdownCause to identifies the shutdown cause */
/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern CONST(uint8, ECUM_CONST) EcuM_GaaShutdownCauseId[];

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
/* Reference to EcuMFlexUserConfig from EcuMSetClockAllowedUserRef */
/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern CONST(uint8, ECUM_CONST) EcuM_GaaSetClockAllowedUser[];

#endif

#define ECUM_STOP_SEC_CONST_8
#include "MemMap.h"

#define ECUM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Reference to EcuMFlexUserConfig from EcuMGoDownAllowedUserRef */
/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern CONST(uint8, ECUM_CONST) EcuM_GaaGoDownAllowedUser[];

/* Array for Sleep Modes Structure to identifies the sleep mode */
/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern CONST(EcuM_SleepModeConfigType, ECUM_CONST) EcuM_GaaSleepModes[];

/* Array for Wakeup Source Structure to define the identifier of this
wake up source */
/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern CONST(EcuM_WakeupSource, ECUM_CONST) EcuM_GaaWakeSource[];

/* Array for EcuM Users */
/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern CONST(EcuM_UserType, ECUM_CONST) EcuM_GaaUsers[];

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)


/* Array for EcuM Users */
/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern CONST(EcuM_AlarmClock, ECUM_CONST) EcuM_GaaAlarmClock[];
#endif /* End of if (ECUM_ALARM_CLOCK_PRESENT == STD_ON) */


/* Reference to EcuMOSResource from EcuMCommonConfiguration container */
/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern CONST(ResourceType, ECUM_CONST) EcuM_GaaOsResources[];

#if (ECUM_MULTI_CORE_SUPPORT == STD_ON)
/* Array for Core ID
 * Master Core : EcuM_GaaCoreID[0]
 * Slave Cores : EcuM_GaaCoreID[1] ~ */
/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern CONST(CoreIdType, ECUM_CONST) EcuM_GaaCoreID[];

/* Reference to OsEvent container through OsTaskEventRef in OsTask container */
/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern CONST(EventMaskType, ECUM_CONST) EcuM_GaaEventMask[];

/* Reference to OsTask container through OsTaskRef in EcuMFlexConfiguration container */
/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern CONST(TaskType, ECUM_CONST) EcuM_GaaOsTask[];
#endif

#define ECUM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"




/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* ECUM_PCTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

