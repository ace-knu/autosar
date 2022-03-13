/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : EcuM_Config.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR EcuM Module                                           **
**                                                                            **
**  PURPOSE   : Provision of definition of constant variables                 **
**              to save the configured values                                 **
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
** 2.5.3      12-Jan-2016   Daejun Park   Redmine #3856                       **
**                                        -Update precompile option           **
** 2.5.1      12-Oct-2015   Sanghoon Bae  Redmine #3035                       **
** 2.2.1      26-Dec-2014   Daejun Park   Redmine #1879                       **
**                                        -Update to AUTRON template          **
** 2.1.0      24-Sep-2014   Daejun Park   Redmine #1367                       **
**                                        -Add spinlock variable              **
** 2.0.4      12-Jun-2014   Daejun Park   Add feature MCU_NORMAL_MODE         **
** 2.0.0      24-Apr-2014   Daejun Park   Update major version                **
** 1.2.0      10-Apr-2014   Daejun Park   Move EcuM_GucNoOfAlarms variable    **
** 1.1.0      07-Mar-2014   Daejun Park   Add new constant variable for lib   **
** 1.0.10     04-Jul-2013   Daejun Park   CR~129, XAR~581 : EcuM library,     **
**                                                          Dem event         **
**                                        -Add new precompile option          **
**                                         ECUM_DEMERROR_REPORT               **
**                                        -As per EcuM4047 in SWS,            **
**                                         ECUM_DEF_BEHAVIOUR_ENABLED should  **
**                                         affect only ECUM_E_IMPROPER_CALLER **
**                                        -Add new constant variable          **
**                                         EcuM_GulOsNumOfTasks to replace    **
**                                         macro in static code               **
** 1.0.8      07-Jun-2013   Daejun Park   CR~119, XAR~558 : EcuM library      **
**                                        -Add inclusion of header file       **
**                                         EcuM_Config.h                      **
**                                        -Add new constant variables         **
**                                         to replace macros in static code   **
** 1.0.0      04-Mar-2013   Daejun Park   Initial version                     **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "EcuM_Config.h"
#include "EcuM_Cfg.h"
#if (ECUM_DEMERROR_REPORT == STD_ON)
#include "EcuM_Dem_Cfg.h"
# endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define ECUM_START_SEC_CONST_8
#include "MemMap.h"
const uint8 EcuM_GucNoOfResetModes = ECUM_NO_OF_RESETMODES;

const uint8 EcuM_GucNoOfGoDownUsers = ECUM_NO_OF_GODOWNUSERS;

const uint8 EcuM_GucNoOfWakeupSources = ECUM_NO_OF_WAKEUPSOURCES;

const uint8 EcuM_GucNoOfShutdownCause = ECUM_NO_OF_SHUTDOWNCAUSE;

const uint8 EcuM_GucNoOfSleepModes = ECUM_NO_OF_SLEEPMODES;

const uint8 EcuM_GucNoOfCores = ECUM_NO_OF_CORES;

const uint8 EcuM_GucNoOfOsResources = ECUM_NO_OF_OSRESOURCES;

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
const uint8 EcuM_GucNoOfAlarms = ECUM_NO_OF_ALARMS;

const uint8 EcuM_GucNoOfClockUsers = ECUM_NO_OF_CLOCKUSERS;
#endif

#if (ECUM_MULTI_CORE_SUPPORT == STD_ON)
const uint8 EcuM_GucNoOfOsTasks = ECUM_NO_OF_OS_TASKS;

const uint8 EcuM_GucNoOfEventMasks = ECUM_NO_OF_EVENT_MASKS;

const uint8 EcuM_GucSlaveCoreMask = ECUM_SLAVE_CORE_MASK;
#endif

#define ECUM_STOP_SEC_CONST_8
#include "MemMap.h"

#define ECUM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
const AppModeType EcuM_GddDefaultAppMode = ECUM_DEFAULT_APP_MODE;

#if (ECUM_MCU_NORMAL_MODE_SUPPORT == STD_ON)
const Mcu_ModeType EcuM_GulMcuNormalMode = ECUM_MCU_NORMAL_MODE;
#endif

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
const EcuM_WakeupSourceType EcuM_GddAlarmWakeupSourceId = 
  ECUM_ALARM_WAKEUP_SOURCE_ID;

const Gpt_ChannelType EcuM_GucGptChannelId = ECUM_GPT_CHANNEL_ID;
#endif

#if (ECUM_MULTI_CORE_SUPPORT == STD_ON)
const SpinlockIdType EcuM_GucSpinlock = ECUM_OS_SPINLOCK;
#endif

#if (ECUM_DEMERROR_REPORT == STD_ON)
#if (ECUM_DEF_BEHAVIOUR_ENABLED == STD_ON)

const Dem_EventIdType EcuM_GusEImproperCaller = ECUM_E_IMPROPER_CALLER;

#endif

const Dem_EventIdType EcuM_GusEConfigurationDataInconsistent = 
  ECUM_E_CONFIGURATION_DATA_INCONSISTENT;

const Dem_EventIdType EcuM_GusERamCheckFailed = ECUM_E_RAM_CHECK_FAILED;

#endif

#define ECUM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
#define ECUM_START_SEC_CONST_32
#include "MemMap.h"
const uint32 EcuM_GulGptChannelTickMax = ECUM_GPT_CHANNEL_TICK_MAX;
#define ECUM_STOP_SEC_CONST_32
#include "MemMap.h"

#endif



