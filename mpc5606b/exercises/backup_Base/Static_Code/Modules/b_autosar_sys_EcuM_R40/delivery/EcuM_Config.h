/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : EcuM_Config.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR EcuM Module                                           **
**                                                                            **
**  PURPOSE   : Provision of external declaration of constant variables       **
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
** 2.2.1      26-Dec-2014   Daejun Park   Redmine #1879                       **
**                                        -Update to AUTRON template          **
** 2.1.0      24-Sep-2014   Daejun Park    Redmine #1367                      **
**                                         -Add spinlock variable             **
** 2.0.4      12-Jun-2014   Daejun Park    Add feature MCU_NORMAL_MODE        **
** 1.2.0      10-Apr-2014   Daejun Park    Move EcuM_GucNoOfAlarms variable   **
** 1.1.0      07-Mar-2014   Daejun Park    Add new constant variable for lib  **
** 1.0.10     04-Jul-2013   Daejun Park    CR~129, XAR~581 : EcuM library     **
**                                         -Add new precompile option         **
**                                          ECUM_DEMERROR_REPORT              **
**                                         -As per EcuM4047 in SWS,           **
**                                          ECUM_DEF_BEHAVIOUR_ENABLED should **
**                                          affect only ECUM_E_IMPROPER_CALLER**
**                                         -Add new constant variable         **
**                                          EcuM_GulOsNumOfTasks to replace   **
**                                          macro in static code              **
** 1.0.8      07-Jun-2013   Daejun Park    CR~119, XAR~558 : EcuM library     **
**                                         -Add inclusion of header file      **
**                                          EcuM.h                            **
**                                         -Add new constant variables        **
**                                          to replace macros in static code  **
** 1.0.0      04-Mar-2013   Daejun Park   Initial version                     **
*******************************************************************************/

#ifndef ECUM_CONFIG_H_
#define ECUM_CONFIG_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "EcuM_Cfg.h"

#include "Mcu.h"
#include "Os.h"
#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
#include "Gpt.h"
#endif
#if (ECUM_DEMERROR_REPORT == STD_ON)
#include "Dem.h"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define ECUM_START_SEC_CONST_8
#include "MemMap.h"
extern const uint8 EcuM_GucNoOfResetModes;

extern const uint8 EcuM_GucNoOfGoDownUsers;

extern const uint8 EcuM_GucNoOfWakeupSources;

extern const uint8 EcuM_GucNoOfShutdownCause;

extern const uint8 EcuM_GucNoOfSleepModes;

extern const uint8 EcuM_GucNoOfCores;

extern const uint8 EcuM_GucNoOfOsResources;

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)

extern const uint8 EcuM_GucNoOfAlarms;

extern const uint8 EcuM_GucNoOfClockUsers;

#endif

#if (ECUM_MULTI_CORE_SUPPORT == STD_ON)

extern const uint8 EcuM_GucNoOfOsTasks;

extern const uint8 EcuM_GucNoOfEventMasks;

extern const uint8 EcuM_GucSlaveCoreMask;

#endif

#define ECUM_STOP_SEC_CONST_8
#include "MemMap.h"


#define ECUM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern const AppModeType EcuM_GddDefaultAppMode;

#if (ECUM_MCU_NORMAL_MODE_SUPPORT == STD_ON)

extern const Mcu_ModeType EcuM_GulMcuNormalMode;

#endif

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
    
extern const EcuM_WakeupSourceType EcuM_GddAlarmWakeupSourceId;

extern const Gpt_ChannelType EcuM_GucGptChannelId;

#endif

#if (ECUM_MULTI_CORE_SUPPORT == STD_ON)

extern const SpinlockIdType EcuM_GucSpinlock;

#endif

#if (ECUM_DEMERROR_REPORT == STD_ON)
#if (ECUM_DEF_BEHAVIOUR_ENABLED == STD_ON)

extern const Dem_EventIdType EcuM_GusEImproperCaller;

#endif

extern const Dem_EventIdType EcuM_GusEConfigurationDataInconsistent;

extern const Dem_EventIdType EcuM_GusERamCheckFailed;

#endif

#define ECUM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"







#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)

#define ECUM_START_SEC_CONST_32
#include "MemMap.h"
extern const uint32 EcuM_GulGptChannelTickMax;
#define ECUM_STOP_SEC_CONST_32
#include "MemMap.h"

#endif






#endif /* ECUM_CONFIG_H_ */
