/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : EcuM.h                                                        **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR EcuM Module                                           **
**                                                                            **
**  PURPOSE   : Provision of external declaration of APIs and Service IDs     **
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
** 2.7.2      30-Mar-2016   Sanghoon Bae  Redmine #7887                       **
** 2.5.5      08-Jul-2016   Sanghoon Bae  Redmine #5257                       **
** 2.5.2      04-Dec-2015   Daejun Park   Redmine #3599                       **
**                                        -Change ResetReason type            **
** 2.5.0      20-Aug-2015   Sanghoon Bae  Redmine #2583                       **
**                                        -Add ECUM_GETRESETREASON_SID        **
**                                        -Add EcuM_GetResetReason function   **
** 2.4.1      27-May-2015   Jihoon Jung   Redmine #2550                       **
** 2.2.1      26-Dec-2014   Daejun Park   Redmine #1879                       **
**                                        -Update to AUTRON template          **
** 1.1.0      07-Mar-2014   Daejun Park   Cleanup code                        **
** 1.0.11     04-Jul-2013   Daejun Park   CR~129, XAR~581 : EcuM library      **
** 1.0.0      04-Mar-2013   Daejun Park   Initial version                     **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */

#ifndef ECUM_H
#define ECUM_H


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "EcuM_Cbk.h"
#include "EcuM_Types.h"
#include "EcuM_Cfg.h"
#include "EcuM_Generated_Types.h"

#include "Mcu.h"
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/* Instance ID */
#define ECUM_INSTANCE_ID                  ((uint8)0x00u)

/* Service ID for EcuM_GetVersionInfo */
#define ECUM_GETVERSIONINFO_SID           ((uint8)0x00u)

/* Service ID for EcuM_GoDown */
#define ECUM_GODOWN_SID                   ((uint8)0x1Fu)

/* Service ID for EcuM_GoHalt */
#define ECUM_GOHALT_SID                   ((uint8)0x20u)

/* Service ID for EcuM_GoPoll */
#define ECUM_GOPOLL_SID                   ((uint8)0x21u)

/* Service ID for EcuM_Init */
#define ECUM_INIT_SID                     ((uint8)0x01u)

/* Service ID for EcuM_Shutdown */
#define ECUM_SHUTDOWN_SID                 ((uint8)0x02u)

/* Service ID for EcuM_SelectShutdownTarget */
#define ECUM_SELECTSHUTDOWNTARGET_SID     ((uint8)0x06u)

/* Service ID for EcuM_GetLastShutdownTarget */
#define ECUM_GETLASTSHUTDOWNTARGET_SID    ((uint8)0x08u)

/* Service ID for EcuM_GetShutdownTarget */
#define ECUM_GETSHUTDOWNTARGET_SID        ((uint8)0x09u)

/* Service ID for EcuM_SelectShutdownCause */
#define ECUM_SELECTSHUTDOWNCAUSE_SID      ((uint8)0x1Bu)

/* Service ID for EcuM_GetShutdownCause */
#define ECUM_GETSHUTDOWNCAUSE_SID         ((uint8)0x1Cu)

/* Service ID for EcuM_GetMostRecentShutdown */
#define ECUM_GETMOSTRECENTSHUTDOWN_SID    ((uint8)0x1Du)

/* Service ID for EcuM_GetNextRecentShutdown */
#define ECUM_GETNEXTRECENTSHUTDOWN_SID    ((uint8)0x1Eu)

/* Service ID for EcuM_GetPendingWakeupEvents */
#define ECUM_GETPENDINGWAKEUPEVENTS_SID   ((uint8)0x0du)

/* Service ID for EcuM_ClearWakeupEvent */
#define ECUM_CLEARWAKEUPEVENT_SID         ((uint8)0x16u)

/* Service ID for EcuM_GetValidatedWakeupEvents */
#define ECUM_GETVALIDATEDWAKEUPEVENTS_SID ((uint8)0x15u)

/* Service ID for EcuM_GetExpiredWakeupEvents */
#define ECUM_GETEXPIREDWAKEUPEVENTS_SID   ((uint8)0x19u)

/* Service ID for EcuM_SetRelWakeupAlarm */
#define ECUM_SETRELWAKEUPALARM_SID        ((uint8)0x22u)

/* Service ID for EcuM_SetAbsWakeupAlarm */
#define ECUM_SETABSWAKEUPALARM_SID        ((uint8)0x23u)

/* Service ID for EcuM_AbortWakeupAlarm */
#define ECUM_ABORTWAKEUPALARM_SID         ((uint8)0x24u)

/* Service ID for EcuM_GetCurrentTime */
#define ECUM_GETCURRENTTIME_SID           ((uint8)0x25u)

/* Service ID for EcuM_GetWakeupTime */
#define ECUM_GETWAKEUPTIME_SID            ((uint8)0x26u)

/* Service ID for EcuM_SetClock */
#define ECUM_SETCLOCK_SID                 ((uint8)0x27u)

/* Service ID for EcuM_GetResetReason */
#define ECUM_GETRESETREASON_SID           ((uint8)0x28u)

/* Service ID for EcuM_SelectBootTarget */
#define ECUM_SELECTBOOTTARGET_SID         ((uint8)0x12u)

/* Service ID for EcuM_GetBootTarget */
#define ECUM_GETBOOTTARGET_SID            ((uint8)0x13u)

/* Service ID for EcuM_MainFunction */
#define ECUM_MAINFUNCTION_SID             ((uint8)0x18u)

/* Service ID for EcuM_SetWakeupEvents */
#define ECUM_SETWAKEUPEVENT_SID           ((uint8)0x0cu)

/* Service ID for EcuM_ValidateWakeupEvent */
#define ECUM_VALIDATEWAKEUPEVENT_SID      ((uint8)0x14u)

/* Service ID for EcuM_StartupTwo  */
#define ECUM_STARTUPTWO_SID               ((uint8)0x1au)

/*******************************************************************************
**                                  Macros                                    **
*******************************************************************************/

#define ECUM_ZERO                         (0x00u)
#define ECUM_ONE                          (0x01u)
#define ECUM_TWO                          (0x02u)
#define ECUM_FOUR                         (0x04u)

#define ECUM_NO_EVENTS                    ((EcuM_WakeupSourceType)0x00000000u)

#define ECUM_UNINITIALIZED                ((boolean)0x00u)
#define ECUM_INITIALIZED                  ((boolean)0x01u)

#define ECUM_FALSE                        ((boolean)0x00u)
#define ECUM_TRUE                         ((boolean)0x01u)

#define ECUM_COMM_INVALID_CHANNEL         ((uint16)65535u)
#define ECUM_NO_ACTIVE_ALARM              ((uint32)0xFFFFFFFFu)

#define ECUM_ALRAM_LOOP_MAX               ((uint16)1000u)

/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> use function like-macro for reduce execution time and stack */
#define ECUM_UNUSED(x)                    do{if((uint32)(x) != \
                                           (uint32)ECUM_ZERO) {}}while(0)
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> use function like-macro for reduce execution time and stack */
#define ECUM_UNUSED_PTR(x)                do{if((x) != NULL_PTR) {}}while(0)
    
#define ECUM_INVALID_SLEEPMODEID       ((uint16) 0xffffu)

#define ECUM_INVALID_SHUTDOWN          ((uint8) 0xffu)


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define ECUM_START_SEC_CODE
#include "MemMap.h"

#if (ECUM_VERSION_INFO_API == STD_ON)
/* Extern for EcuM_GetVersionInfo API */
extern FUNC(void, ECUM_CODE) EcuM_GetVersionInfo
  (P2VAR(Std_VersionInfoType, AUTOMATIC, ECUM_APPL_DATA)versioninfo);
#endif

/* Check For Rte_EcuM.h Has Extern for EcuM_ShutdownTarget CS IF */
#ifndef RTE_RUNNABLE_SelectShutdownTarget
/* Extern for EcuM_SelectShutdownTarget API */
/* polyspace<MISRA-C:8.8:Not a defect:Justify with annotations> also used by BswM (AUTOSAR Standard : BswM0008) */
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownTarget
  (EcuM_StateType shutdownTarget, uint8 shutdownMode);
#endif

#ifndef RTE_RUNNABLE_GoDown
/* Extern for EcuM_GoDown */
/* polyspace<MISRA-C:8.8:Not a defect:Justify with annotations> also used by BswM (AUTOSAR Standard : BswM0008) */
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoDown(uint16 caller);
#endif

#ifndef RTE_RUNNABLE_GoHalt
/* Extern for EcuM_GoHalt */
/* polyspace<MISRA-C:8.8:Not a defect:Justify with annotations> also used by BswM (AUTOSAR Standard : BswM0008) */
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoHalt(void);
#endif

#ifndef RTE_RUNNABLE_GoPoll
/* Extern for EcuM_GoPoll */
/* polyspace<MISRA-C:8.8:Not a defect:Justify with annotations> also used by BswM (AUTOSAR Standard : BswM0008) */
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoPoll(void);
#endif

/* Extern for EcuM_MainFunction */
extern FUNC(void, ECUM_CODE) EcuM_MainFunction0(void);
extern FUNC(void, ECUM_CODE) EcuM_MainFunction1(void);
extern FUNC(void, ECUM_CODE) EcuM_MainFunction2(void);

/* Extern for EcuM_Init API */
extern FUNC(void, ECUM_CODE) EcuM_Init(void);

/* Internal Function for StateStartpTwo */
extern FUNC(void, ECUM_CODE) EcuM_StartupTwo(void);

/* Extern for EcuM_Shutdown API */
extern FUNC(void, ECUM_CODE) EcuM_Shutdown(void);

/* Extern for EcuM_GetPendingWakeupEvents API */
extern FUNC(EcuM_WakeupSourceType, ECUM_CODE)
  EcuM_GetPendingWakeupEvents(void);

/* Extern for EcuM_GetValidatedWakeupEvents API */
extern FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetValidatedWakeupEvents
  (void);

/* Extern for EcuM_ClearWakeupEvent API */
/* polyspace<MISRA-C:8.8:Not a defect:Justify with annotations> also used by BswM (AUTOSAR Standard : BswM0008) */
extern FUNC(void, ECUM_CODE) EcuM_ClearWakeupEvent
  (EcuM_WakeupSourceType wakeupSource);

/* Extern for EcuM_GetExpiredWakeupEvents API */
extern FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetExpiredWakeupEvents(void);

/* Extern for EcuM_GetResetReason API */
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetResetReason
  (P2VAR(Mcu_ResetType, AUTOMATIC, ECUM_APPL_DATA) resetreason);

#define ECUM_STOP_SEC_CODE
#include "MemMap.h"

/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */

#endif /* ECUM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

