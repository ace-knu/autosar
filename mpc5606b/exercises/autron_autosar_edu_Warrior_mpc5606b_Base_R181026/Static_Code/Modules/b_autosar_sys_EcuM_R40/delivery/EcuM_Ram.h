/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : EcuM_Ram.h                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR EcuM Module                                           **
**                                                                            **
**  PURPOSE   : Header file of EcuM_Ram.c                                     **
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
** 2.5.5      08-Jul-2016   Sanghoon Bae  Redmine #5257                       **
** 2.5.0      20-Aug-2015   Sanghoon Bae  Redmine #2571                       **
**                                        -Add EcuM_GucSleepModeIndex variable**
** 2.4.1      27-May-2015   Jihoon Jung   Redmine #2550                       **
** 2.3.2      29-Mar-2015   Daejun Park   Redmine #2388                       **
**                                        -Add EcuM_GddWakeupType variable    **
** 2.2.1      26-Dec-2014   Daejun Park   Redmine #1879                       **
**                                        -Update to AUTRON template          **
** 2.2.0      26-Nov-2014   Daejun Park   Modify alarm wakeup process         **
** 2.1.0      24-Sep-2014   Daejun Park   Redmine #1367                       **
** 1.1.0      07-Mar-2014   Daejun Park   -Add/Remove global variables        **
** 1.0.10     04-Jul-2013   Daejun Park   CR~129, XAR~581 : EcuM library      **
**                                        -Do not pre-define array size       **
**                                         for library                        **
** 1.0.8      07-Jun-2013   Daejun Park   CR~119, XAR~558 : EcuM library      **
**                                        -Add global variable                **
**                                         EcuM_GaaSetEventInv                **
** 1.0.0      04-Mar-2013   Daejun Park   Initial version                     **
*******************************************************************************/

#ifndef ECUM_RAM_H
#define ECUM_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "EcuM_Types.h"
#include "EcuM_PCTypes.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define ECUM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#if (ECUM_DEV_ERROR_DETECT == STD_ON)
/* Global variable to store Initialization status of EcuM */
extern VAR(boolean, ECUM_VAR_POWER_ON_INIT) EcuM_GblInitStatus;
#endif

/* Global variable to store the sleep cycle status */
extern VAR(boolean, ECUM_VAR_POWER_ON_INIT) EcuM_GblSleepCycle;

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
/* Global variable to store the alarm cycle status */
extern VAR(boolean, ECUM_VAR_POWER_ON_INIT) EcuM_GblAlarmCycle;

/* Global variable to store the alarm expiry status status of Alarm */
extern VAR(boolean, ECUM_VAR_POWER_ON_INIT) EcuM_GblAlarmExpired;
#endif

#define ECUM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"


#define ECUM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "MemMap.h"
#if (ECUM_DEV_ERROR_DETECT == STD_ON)
/* Global structure to hold the last Det error status */
extern VAR(EcuM_DetErrorStatus, ECUM_VAR_POWER_ON_INIT) EcuM_GstLastDetError;
#endif

/* Global variable to store the wakeup type */
extern VAR(EcuM_WakeupType, ECUM_VAR_POWER_ON_INIT) EcuM_GddWakeupType;

/* Global variable to hold the Pending Wakeup sources */
extern VAR(EcuM_WakeupSourceType, ECUM_VAR_POWER_ON_INIT)
  EcuM_GddPendingWakeupEvents;

/* Global variable to hold the Expired Wakeup sources */
extern VAR(EcuM_WakeupSourceType, ECUM_VAR_POWER_ON_INIT)
  EcuM_GddExpiredWakeupEvents;

/* Global variable to hold the validated Wakeup sources */
extern VAR(EcuM_WakeupSourceType, ECUM_VAR_POWER_ON_INIT)
  EcuM_GddValidatedWakeupEvents;

/* Global Variable to store wakeup status */
/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern VAR(EcuM_WakeupStatusType, ECUM_VAR_POWER_ON_INIT) EcuM_GaaWakeupStatus[];

#define ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "MemMap.h"


#define ECUM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
#if (ECUM_MULTI_CORE_SUPPORT == STD_ON)
/* Global variable to store the shutdown status of EcuM */
extern VAR(uint8, ECUM_VAR_POWER_ON_INIT) EcuM_GucShutdownMask;

/* Global variable to store the sleep status of EcuM in case of EcuM halt*/
extern VAR(uint8, ECUM_VAR_POWER_ON_INIT) EcuM_GucHaltMask;

/* Global variable to store the sleep status of EcuM in case of EcuM poll*/
extern VAR(uint8, ECUM_VAR_POWER_ON_INIT) EcuM_GucPollMask;
#endif /* End of if (ECUM_MULTI_CORE_SUPPORT == STD_ON) */

/* Global pointer to hold EcuM Sleep Mode Index data */
extern VAR(uint8, ECUM_VAR_NOINIT) EcuM_GucSleepModeIndex;
#define ECUM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define ECUM_START_SEC_VAR_POWER_ON_CLEARED_16
#include "MemMap.h"
#if (ECUM_MULTI_CORE_SUPPORT == STD_ON)
/* Global variable to count the number of cores based on number of
 * time SetEvent function */
extern VAR(uint16, ECUM_VAR_POWER_ON_INIT) EcuM_GulNoOfCore;

#endif /* End of if (ECUM_MULTI_CORE_SUPPORT == STD_ON) */

/* Global variable to store the shutdown status of EcuM */
/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern VAR(uint16, ECUM_VAR_POWER_ON_INIT) EcuM_GaaWakeupCounter[];

/* Global pointer to hold EcuM Sleep Mode Index data */
extern VAR(uint16, ECUM_VAR_NOINIT) EcuM_GusSleepModeId;

#define ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_16
#include "MemMap.h"


#define ECUM_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)

/* Global array to store Alarm time of each Alarm */
/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern VAR(uint32, ECUM_VAR_POWER_ON_INIT) EcuM_GaaAlarmTime[];

/* Global variable to store the status of Running Timer */
extern VAR(uint32, ECUM_VAR_POWER_ON_INIT) EcuM_GulRunningTimer;

/* Global variable to store the Master Clock Alarm time of EcuM */
extern VAR(uint32, ECUM_VAR_POWER_ON_INIT) EcuM_GulMasterAlarm;

/* Global variable to store the next GPT tick */
extern VAR(uint32, ECUM_VAR_POWER_ON_INIT) EcuM_GulNextTick;

#endif /* End of if (ECUM_ALARM_CLOCK_PRESENT == STD_ON) */

#define ECUM_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"



#define ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"
/* Global Variable to store EcuM state */
extern VAR(EcuM_StateType, ECUM_VAR_NOINIT) EcuM_GddState;

/* Global Variable to store Mcu reset reason */
extern VAR(Mcu_ResetType, ECUM_VAR_NOINIT) EcuM_GddResetReason;
#define ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define ECUM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "MemMap.h"
/* Global Variable to hold the last shutdown target */
extern VAR(EcuM_LastShutdown, ECUM_VAR_NOINIT) EcuM_GstLastShutdown;

/* Global Variable to hold the shutdown cause,target and boot target */
extern VAR(EcuM_ShutdownCauseTarget, ECUM_VAR_NOINIT)
  EcuM_GstShutdownCauseTarget;
#define ECUM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "MemMap.h"

#define ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"
/* Global pointer to hold EcuM Configuration Data */
extern P2CONST(EcuM_ConfigType, ECUM_VAR_NOINIT, ECUM_CONST)
  EcuM_GpEcuMConfigPtr;
#define ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* ECUM_RAM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

