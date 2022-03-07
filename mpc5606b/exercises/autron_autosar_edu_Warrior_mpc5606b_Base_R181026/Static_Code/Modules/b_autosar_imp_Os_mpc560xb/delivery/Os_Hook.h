/*******************************************************************************
**                                                                            **
**  (C) 2016 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Os_Hook.h                                                     **
**                                                                            **
**  TARGET    : MPC560xB                                                      **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Header file for Os Hook containing the declaration of error   **
**              information                                                   **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 1.1.0     04-Nov-2016    JH.Lee        Redmine #6493                       **   
** 1.0.4     22-Sep-2016    MJ.Woo        Redmine #5990                       **
** 1.0.0     03-Mar-2016    MJ.Woo        Initial version                     **
*******************************************************************************/

#ifndef OS_HOOK_H
#define OS_HOOK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define SZ_OSERROR 8
#define MASK_OSERROR_BUF 0x7

/* OS Error code redefine for easy to see in debugger */
typedef enum ETag_Os_ErrorValueType
{
  _E_OK = E_OK,
  _E_OS_ACCESS = E_OS_ACCESS,       /* Access to the service/object denied */
  _E_OS_CALLEVEL = E_OS_CALLEVEL,   /* Access to the service from
                                       the ISR is not permitted */
  _E_OS_ID = E_OS_ID,               /* Object ID is invalid */
  _E_OS_LIMIT = E_OS_LIMIT,         /* Limit of services/objects exceeded */
  _E_OS_NOFUNC = E_OS_NOFUNC,       /* The object is not used,
                                       service rejected */
  _E_OS_RESOURCE = E_OS_RESOURCE,   /* Task still occupies resource */
  _E_OS_STATE = E_OS_STATE,         /* The state of the object is not correct
                                       for the required service */
  _E_OS_VALUE = E_OS_VALUE,         /* Value outside of the admissible limit */
  _E_OS_SERVICEID = E_OS_SERVICEID, /* Service can not be called */
  _E_OS_ILLEGAL_ADDRESS = E_OS_ILLEGAL_ADDRESS, /* An invalid address is given
                                                   as a parameter to a service */
  _E_OS_MISSINGEND = E_OS_MISSINGEND,   /* Tasks terminates without a
                                           TerminateTask() or ChainTask() call */
  _E_OS_DISABLEDINT = E_OS_DISABLEDINT, /* A service of the OS is called inside
                                           an interrupt disable/enable pair */
  _E_OS_STACKFAULT = E_OS_STACKFAULT,   /* A stack fault detected via
                                           stack monitoring by the OS */
  _E_OS_PROTECTION_MEMORY = E_OS_PROTECTION_MEMORY,   /* A memory access
                                                         violation occurred */
  _E_OS_PROTECTION_TIME = E_OS_PROTECTION_TIME, /* A Task/Category 2 ISR exceeds
                                                   its execution time budget */
  _E_OS_PROTECTION_LOCKED = E_OS_PROTECTION_LOCKED,   /* A Task/Category 2 ISR
                                                         blocks for too long */
  _E_OS_PROTECTION_EXCEPTION = E_OS_PROTECTION_EXCEPTION, /* A trap occurred */
  _E_OS_PROTECTION_ARRIVAL = E_OS_PROTECTION_ARRIVAL, /* A Task/Category 2 ISR
                                                        arrives before its
                                                        timeframe has expired */
  _E_OS_PROTECTION_ISR_ARRIVAL = E_OS_PROTECTION_ISR_ARRIVAL, /* Additional
                                                              error code. It is
                                                              used only by OS */
  /* Implementation specific error codes */
  _E_OS_SYS_FATAL= E_OS_SYS_FATAL,  /* OS fatal error */
  _E_OS_SYS_ORDER= E_OS_SYS_ORDER,  /* Incorrect order of function calling */
  _E_OS_SYS_MACHINECHECK = 24,      /* OS fatal error: MachineCheck Exception */
  _E_OS_SYS_DATASTORAGE = 25,       /* OS fatal error: DataStorage Exception */
} Os_ErrorValueType;

/* OS Service id redefine for easy to see in debugger */
typedef enum ETag_Os_ErrorApiType
{
  _NoService = OSServiceId_NoService,
  _StartOS = OSServiceId_StartOS,
  _ShutdownOS = OSServiceId_ShutdownOS,
  _GetActiveApplicationMode = OSServiceId_GetActiveApplicationMode,
  _GetApplicationID = OSServiceId_GetApplicationID,
  _CallTrustedFunction = OSServiceId_CallTrustedFunction,
  _CheckISRMemoryAccess = OSServiceId_CheckISRMemoryAccess,
  _CheckTaskMemoryAccess = OSServiceId_CheckTaskMemoryAccess,
  _CheckObjectAccess = OSServiceId_CheckObjectAccess,
  _CheckObjectOwnership = OSServiceId_CheckObjectOwnership,
  _TerminateApplication = OSServiceId_TerminateApplication,
  _AllowAccess = OSServiceId_AllowAccess,
  _GetApplicationState = OSServiceId_GetApplicationState,
  _ShutdownAllCores = OSServiceId_ShutdownAllCores,

  /* task management services */
  _ActivateTask = OSServiceId_ActivateTask,
  _TerminateTask = OSServiceId_TerminateTask,
  _ChainTask = OSServiceId_ChainTask,
  _Schedule = OSServiceId_Schedule,
  _GetTaskID = OSServiceId_GetTaskID,
  _GetTaskState = OSServiceId_GetTaskState,

  /* interrupt handling services */
  _ResumeAllInterrupts = OSServiceId_ResumeAllInterrupts,
  _SuspendAllInterrupts = OSServiceId_SuspendAllInterrupts,
  _ResumeOSInterrupts = OSServiceId_ResumeOSInterrupts,
  _SuspendOSInterrupts = OSServiceId_SuspendOSInterrupts,
  _EnableAllInterrupts = OSServiceId_EnableAllInterrupts,
  _DisableAllInterrupts = OSServiceId_DisableAllInterrupts,
  _EnableInterruptSource = OSServiceId_EnableInterruptSource,
  _DisableInterruptSource = OSServiceId_DisableInterruptSource,
  _GetISRID = OSServiceId_GetISRID,

  /* resource management services */
  _GetResource = OSServiceId_GetResource,
  _ReleaseResource = OSServiceId_ReleaseResource,

  /* event control services */
  _SetEvent = OSServiceId_SetEvent,
  _ClearEvent = OSServiceId_ClearEvent,
  _GetEvent = OSServiceId_GetEvent,
  _WaitEvent = OSServiceId_WaitEvent,

  /* message services - used only for ORTI */
  _SendMessage = OSServiceId_SendMessage,
  _ReceiveMessage = OSServiceId_ReceiveMessage,
  _GetMessageStatus = OSServiceId_GetMessageStatus,
  _StartCOM = OSServiceId_StartCOM,
  _StopCOM = OSServiceId_StopCOM,
  _ReadFlag = OSServiceId_ReadFlag,
  _ResetFlag = OSServiceId_ResetFlag,
  _GetCOMApplicationMode = OSServiceId_GetCOMApplicationMode,
  _InitMessage = OSServiceId_InitMessage,

  /* counter services */
  _InitCounter = OSServiceId_InitCounter,
  _IncrementCounter = OSServiceId_IncrementCounter,
  _GetCounterValue = OSServiceId_GetCounterValue,
  _GetElapsedValue = OSServiceId_GetElapsedValue,
  _OSGetElapsedCounterValue = OSServiceId_OSGetElapsedCounterValue,
  _GetCounterInfo = OSServiceId_GetCounterInfo,

  /* alarms services */
  _GetAlarmBase = OSServiceId_GetAlarmBase,
  _GetAlarm = OSServiceId_GetAlarm,
  _SetRelAlarm = OSServiceId_SetRelAlarm,
  _SetAbsAlarm = OSServiceId_SetAbsAlarm,
  _CancelAlarm = OSServiceId_CancelAlarm,

  /* hook routines */
  _ErrorHook = OSServiceId_ErrorHook,
  _PreTaskHook = OSServiceId_PreTaskHook,
  _PostTaskHook = OSServiceId_PostTaskHook,
  _StartupHook = OSServiceId_StartupHook,
  _ShutdownHook = OSServiceId_ShutdownHook,
  _IdleLoopHook = OSServiceId_IdleLoopHook,
  _COMErrorHook = OSServiceId_COMErrorHook,
  _ProtectionHook = OSServiceId_ProtectionHook,

  /* schedule table services */
  _StartScheduleTableAbs = OSServiceId_StartScheduleTableAbs,
  _StartScheduleTableRel = OSServiceId_StartScheduleTableRel,
  _StopScheduleTable = OSServiceId_StopScheduleTable,
  _NextScheduleTable = OSServiceId_NextScheduleTable,
  _SyncScheduleTable = OSServiceId_SyncScheduleTable,
  _SetScheduleTableAsync = OSServiceId_SetScheduleTableAsync,
  _GetScheduleTableStatus = OSServiceId_GetScheduleTableStatus,
  _StartScheduleTableSynchron = OSServiceId_StartScheduleTableSynchron,

  /* multicore services */
  _GetSpinlock = OSServiceId_GetSpinlock,
  _TryToGetSpinlock = OSServiceId_TryToGetSpinlock,
  _ReleaseSpinlock = OSServiceId_ReleaseSpinlock,
  _GetCoreID = OSServiceId_GetCoreID,
  _StartCore = OSServiceId_StartCore,
  _StartNonAutosarCore = OSServiceId_StartNonAutosarCore,

} Os_ErrorApiType;

/* polyspace<MISRA-C:18.4:Not a defect:Justify with annotations> Union should be used to get Id parameter  */
typedef union UTag_Os_ParamBlockType
{
  AlarmType OsAlarmId;
  AppModeType OsAppModeId;
  ApplicationType OsApplicationId;
  CounterType OsCounterId;
  ISRType OsISRId;
  ObjectTypeType OsObjectTypeId;
  #if defined(OSRESOURCE)
  ResourceType OsResourceId;
  #endif
  TaskType OsTaskId;
  #if defined(OSSCHEDULETABLES)
  ScheduleTableType OsScheduleTableId;
  #endif
  TrustedFunctionIndexType OsTrustedFunctionIndexId;
} Os_ParamBlockType;

typedef struct STag_Os_ErrorType
{
	Os_ErrorApiType enApi;
	Os_ErrorValueType enErrorNo;
	Os_ParamBlockType unParam;
} Os_ErrorType;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define OSHOOK_START_SEC_CODE
#include "Os_memmap.h"
extern FUNC(void, OS_CODE) Os_UpdateOsErrorInfo(StatusType LddError);
extern FUNC(void, OS_CODE) AppCallbackOnSystemError(StatusType ErrorId);
#define OSHOOK_STOP_SEC_CODE
#include "Os_memmap.h"

#endif /* OS_HOOK_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

