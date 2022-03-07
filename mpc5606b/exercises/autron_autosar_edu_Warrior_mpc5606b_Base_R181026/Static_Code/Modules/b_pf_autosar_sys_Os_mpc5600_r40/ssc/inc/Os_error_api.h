/**
*   @file    Os_error_api.h
*   @version 4.0.69
*
*   @brief   AUTOSAR OS - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup [OS]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR OS 4.0
*   Platform             : Power Architecture
*   Peripheral           : e200z0/e200z0h
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 4.0.69
*   Build Version        : MPC5600V4_OS_4.0.69_ASR_REL_4_0_REV_0003
*
*   (c) Copyright 2013 Freescale Semiconductor Inc.
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef OS_ERROR_API_H
#define OS_ERROR_API_H

#ifdef __cplusplus
extern "C"
{
#endif            /* __cplusplus */

#include <Os_prop_autosar_api.h>
#include <Os_error_types.h> /* for OSServiceIdType */

#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

/*
* public variables accessed from public API
*/
#if defined(OSGETSERVICEID) || defined(OSPARAMETERACCESS)
OSDECLAREVAR (extern OSNEAR OSServiceIdType, OsService_);    /* for OSErrorGetServiceId() from ErrorHook */
#define OsService OSUSEVAR(OsService_)

OSDECLAREVAR (extern OSNEAR OSDWORD, OsObjId_);    /* for first parameter                      */
#define OsObjId OSUSEVAR(OsObjId_)
#endif            /* defined(OSGETSERVICEID) || defined(OSPARAMETERACCESS) */

#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"


#if defined(OSHOOKERROR)
#define OSHOOK_START_SEC_CODE
#include "Os_memmap.h"

extern void ErrorHook (StatusType error); /**< user provided code  */

#define OSHOOK_STOP_SEC_CODE
#include "Os_memmap.h"
#endif

/*  public - error codes */

/* #define E_OK                      ( (StatusType) 0 )    -- defined in Os_types_common_public.h   */
#define E_OS_ACCESS               ( (StatusType) 1 )    /* Access to the service/object denied  */
#define E_OS_CALLEVEL             ( (StatusType) 2 )    /* Access to the service from the ISR is not permitted  */
#define E_OS_ID                   ( (StatusType) 3 )    /* Object ID is invalid */
#define E_OS_LIMIT                ( (StatusType) 4 )    /* Limit of services/objects exceeded   */
#define E_OS_NOFUNC               ( (StatusType) 5 )    /* The object is not used, service rejected */
#define E_OS_RESOURCE             ( (StatusType) 6 )    /* Task still occupies resource */
#define E_OS_STATE                ( (StatusType) 7 )    /* The state of the object is not correct for the required service */
#define E_OS_VALUE                ( (StatusType) 8 )    /* Value outside of the admissible limit    */
#define E_OS_SERVICEID            ( (StatusType) 9 )    /* Service can not be called */

#define E_OS_ILLEGAL_ADDRESS      ( (StatusType)11 )    /* An invalid address is given as a parameter to a service */
#define E_OS_MISSINGEND           ( (StatusType)12 )    /* Tasks terminates without a TerminateTask() or ChainTask() call */
#define E_OS_DISABLEDINT          ( (StatusType)13 )    /* A service of the OS is called inside an interrupt disable/enable pair */
#define E_OS_STACKFAULT           ( (StatusType)14 )    /* A stack fault detected via stack monitoring by the OS */
#define E_OS_PROTECTION_MEMORY    ( (StatusType)15 )    /* A memory access violation occurred */
#define E_OS_PROTECTION_TIME      ( (StatusType)16 )    /* A Task/Category 2 ISR exceeds its execution time budget */
#define E_OS_PROTECTION_LOCKED    ( (StatusType)17 )    /* A Task/Category 2 ISR blocks for too long */
#define E_OS_PROTECTION_EXCEPTION ( (StatusType)18 )    /* A trap occurred */

#define E_OS_PROTECTION_ARRIVAL   ( (StatusType)19 )        /* A Task/Category 2 ISR arrives before its timeframe has expired */
#define E_OS_PROTECTION_ISR_ARRIVAL ( (StatusType)20 )    /* additional error code. It is used only by OS. */

/* Implementation specific error codes */
#define E_OS_SYS_FATAL            ( (StatusType)21 )    /* OS fatal error */
#define E_OS_SYS_ORDER            ( (StatusType)23 )    /* Incorrect order of function calling  */



#define E_OS_PARAM_POINTER        ( (StatusType)29 )            /* A pointer argument os an API is null */

/* IOC error codes */
#ifdef RTE_E_OK
#define IOC_E_OK                  RTE_E_OK
#define IOC_E_NOK                 RTE_E_NOK
#define IOC_E_LIMIT               RTE_E_LIMIT
#define IOC_E_LOST_DATA           RTE_E_LOST_DATA
#define IOC_E_NO_DATA             RTE_E_NO_DATA
#else
#define IOC_E_OK                  ((Std_ReturnType)0)
#define IOC_E_NOK                 ((Std_ReturnType)1)
#define IOC_E_LIMIT               ((Std_ReturnType)130)
#define IOC_E_LOST_DATA           ((Std_ReturnType)64)
#define IOC_E_NO_DATA             ((Std_ReturnType)131)
#endif            /* RTE_E_OK */


#if defined(OSGETSERVICEID)
#define OSErrorGetServiceId()       (OsService)
#endif

#if !defined(OSCOMHOOKERROR)
/* no sence to have it defined w/o COMErrorHook */
#undef OSCOMGETSERVICEID
#undef OSCOMPARAMETERACCESS
#endif

#if defined(OSCOMPARAMETERACCESS) && !defined(OSCOMGETSERVICEID)
#define OSCOMGETSERVICEID
#endif

/*
* part of public API, service IDs
*/
#if defined(OSORTICURRENTSERVICEID)  || defined(OSGETSERVICEID) || defined(OSCOMGETSERVICEID) || defined(OSCOMPARAMETERACCESS)

/* OSEK OS services groups identifiers */
#define OSSYSTEMSERVICEIDBASE        0x00    /* operating system execution control services */
#define OSTASKSERVICEIDBASE          0x20    /* task management services */
#define OSISRSERVICEIDBASE           0x30    /* interrupt handling services */
#define OSRESOURCESERVICEIDBASE      0x50    /* resource management services */
#define OSEVENTSERVICEIDBASE         0x60    /* event control services */
#define OSMESSAGESERVICEIDBASE       0x70    /* messages services */
#define OSCOUNTERSERVICEIDBASE       0x90    /* counters services */
#define OSALARMSERVICEIDBASE         0xA0    /* alarms services */
#define OSHOOKSERVICEIDBASE          0xB0    /* hook routines */
#define OSSCHEDULETABLESERVICEIDBASE 0xC0    /* schedule table routines */
#define OSMULTICORESERVICEIDBASE     0xD0    /* multicore routines */

#define OSServiceId_NoService                   ((OSServiceIdType)0)

/*  some services does not call ErrorHook but listed here */

#define OSServiceId_StartOS                     ((OSServiceIdType)( OSSYSTEMSERVICEIDBASE + 0x02 ))
#define OSServiceId_ShutdownOS                  ((OSServiceIdType)( OSSYSTEMSERVICEIDBASE + 0x04 ))
#define OSServiceId_GetActiveApplicationMode    ((OSServiceIdType)( OSSYSTEMSERVICEIDBASE + 0x06 ))
#define OSServiceId_GetApplicationID            ((OSServiceIdType)( OSSYSTEMSERVICEIDBASE + 0x08 ))
#define OSServiceId_CallTrustedFunction         ((OSServiceIdType)( OSSYSTEMSERVICEIDBASE + 0x0A ))
#define OSServiceId_CheckISRMemoryAccess        ((OSServiceIdType)( OSSYSTEMSERVICEIDBASE + 0x0C ))
#define OSServiceId_CheckTaskMemoryAccess       ((OSServiceIdType)( OSSYSTEMSERVICEIDBASE + 0x0E ))
#define OSServiceId_CheckObjectAccess           ((OSServiceIdType)( OSSYSTEMSERVICEIDBASE + 0x10 ))
#define OSServiceId_CheckObjectOwnership        ((OSServiceIdType)( OSSYSTEMSERVICEIDBASE + 0x12 ))
#define OSServiceId_TerminateApplication        ((OSServiceIdType)( OSSYSTEMSERVICEIDBASE + 0x14 ))
#define OSServiceId_AllowAccess                 ((OSServiceIdType)( OSSYSTEMSERVICEIDBASE + 0x16 ))
#define OSServiceId_GetApplicationState         ((OSServiceIdType)( OSSYSTEMSERVICEIDBASE + 0x18 ))
#define OSServiceId_ShutdownAllCores            ((OSServiceIdType)( OSSYSTEMSERVICEIDBASE + 0x1A ))

/* task management services */
#define OSServiceId_ActivateTask                ((OSServiceIdType)( OSTASKSERVICEIDBASE + 0x00 ))
#define OSServiceId_TerminateTask               ((OSServiceIdType)( OSTASKSERVICEIDBASE + 0x02 ))
#define OSServiceId_ChainTask                   ((OSServiceIdType)( OSTASKSERVICEIDBASE + 0x04 ))
#define OSServiceId_Schedule                    ((OSServiceIdType)( OSTASKSERVICEIDBASE + 0x06 ))
#define OSServiceId_GetTaskID                   ((OSServiceIdType)( OSTASKSERVICEIDBASE + 0x08 ))
#define OSServiceId_GetTaskState                ((OSServiceIdType)( OSTASKSERVICEIDBASE + 0x0A ))

/* interrupt handling services */
#define OSServiceId_ResumeAllInterrupts         ((OSServiceIdType)( OSISRSERVICEIDBASE + 0x00 ))
#define OSServiceId_SuspendAllInterrupts        ((OSServiceIdType)( OSISRSERVICEIDBASE + 0x02 ))
#define OSServiceId_ResumeOSInterrupts          ((OSServiceIdType)( OSISRSERVICEIDBASE + 0x04 ))
#define OSServiceId_SuspendOSInterrupts         ((OSServiceIdType)( OSISRSERVICEIDBASE + 0x06 ))
#define OSServiceId_EnableAllInterrupts         ((OSServiceIdType)( OSISRSERVICEIDBASE + 0x08 ))
#define OSServiceId_DisableAllInterrupts        ((OSServiceIdType)( OSISRSERVICEIDBASE + 0x0A ))
#define OSServiceId_EnableInterruptSource       ((OSServiceIdType)( OSISRSERVICEIDBASE + 0x0C ))
#define OSServiceId_DisableInterruptSource      ((OSServiceIdType)( OSISRSERVICEIDBASE + 0x0E ))
#define OSServiceId_GetISRID                    ((OSServiceIdType)( OSISRSERVICEIDBASE + 0x10 ))

/* resource management services */
#define OSServiceId_GetResource                 ((OSServiceIdType)( OSRESOURCESERVICEIDBASE + 0x00 ))
#define OSServiceId_ReleaseResource             ((OSServiceIdType)( OSRESOURCESERVICEIDBASE + 0x02 ))
/* event control services */
#define OSServiceId_SetEvent                    ((OSServiceIdType)( OSEVENTSERVICEIDBASE + 0x00 ))
#define OSServiceId_ClearEvent                  ((OSServiceIdType)( OSEVENTSERVICEIDBASE + 0x02 ))
#define OSServiceId_GetEvent                    ((OSServiceIdType)( OSEVENTSERVICEIDBASE + 0x04 ))
#define OSServiceId_WaitEvent                   ((OSServiceIdType)( OSEVENTSERVICEIDBASE + 0x06 ))
/* message services - used only for ORTI */
#define OSServiceId_SendMessage                 ((OSServiceIdType)( OSMESSAGESERVICEIDBASE + 0x00 ))
#define OSServiceId_ReceiveMessage              ((OSServiceIdType)( OSMESSAGESERVICEIDBASE + 0x02 ))
#define OSServiceId_GetMessageStatus            ((OSServiceIdType)( OSMESSAGESERVICEIDBASE + 0x08 ))
#define OSServiceId_StartCOM                    ((OSServiceIdType)( OSMESSAGESERVICEIDBASE + 0x0A ))
#define OSServiceId_StopCOM                     ((OSServiceIdType)( OSMESSAGESERVICEIDBASE + 0x0C ))
#define OSServiceId_ReadFlag                    ((OSServiceIdType)( OSMESSAGESERVICEIDBASE + 0x12 ))
#define OSServiceId_ResetFlag                   ((OSServiceIdType)( OSMESSAGESERVICEIDBASE + 0x14 ))
#define OSServiceId_GetCOMApplicationMode       ((OSServiceIdType)( OSMESSAGESERVICEIDBASE + 0x16 ))
#define OSServiceId_InitMessage                 ((OSServiceIdType)( OSMESSAGESERVICEIDBASE + 0x18 ))

#if (OSNMSGS > 0U)
typedef enum
{
    COMServiceId_SendMessage = OSServiceId_SendMessage,
    COMServiceId_ReceiveMessage = OSServiceId_ReceiveMessage,
    COMServiceId_GetMessageStatus = OSServiceId_GetMessageStatus,
    COMServiceId_StartCOM = OSServiceId_StartCOM,
    COMServiceId_StopCOM = OSServiceId_StopCOM,
    COMServiceId_GetCOMApplicationMode = OSServiceId_GetCOMApplicationMode,
    COMServiceId_InitMessage = OSServiceId_InitMessage,
    COMServiceId_ReadFlag = OSServiceId_ReadFlag,
    COMServiceId_ResetFlag = OSServiceId_ResetFlag
} COMServiceIdType;
#endif /* (OSNMSGS > 0U) */

/* counters services */
#define OSServiceId_InitCounter                 ((OSServiceIdType)( OSCOUNTERSERVICEIDBASE + 0x00 ))
#define OSServiceId_IncrementCounter            ((OSServiceIdType)( OSCOUNTERSERVICEIDBASE + 0x02 ))
#define OSServiceId_GetCounterValue             ((OSServiceIdType)( OSCOUNTERSERVICEIDBASE + 0x04 ))
#define OSServiceId_GetElapsedValue             ((OSServiceIdType)( OSCOUNTERSERVICEIDBASE + 0x06 ))
#define OSServiceId_OSGetElapsedCounterValue    (OSServiceId_GetElapsedValue)

#define OSServiceId_GetCounterInfo              ((OSServiceIdType)( OSCOUNTERSERVICEIDBASE + 0x08 ))
/* alarms services */
#define OSServiceId_GetAlarmBase                ((OSServiceIdType)( OSALARMSERVICEIDBASE + 0x00 ))
#define OSServiceId_GetAlarm                    ((OSServiceIdType)( OSALARMSERVICEIDBASE + 0x02 ))
#define OSServiceId_SetRelAlarm                 ((OSServiceIdType)( OSALARMSERVICEIDBASE + 0x04 ))
#define OSServiceId_SetAbsAlarm                 ((OSServiceIdType)( OSALARMSERVICEIDBASE + 0x06 ))
#define OSServiceId_CancelAlarm                 ((OSServiceIdType)( OSALARMSERVICEIDBASE + 0x08 ))
/* hook routines */
#define OSServiceId_ErrorHook                   ((OSServiceIdType)( OSHOOKSERVICEIDBASE + 0x00 ))
#define OSServiceId_PreTaskHook                 ((OSServiceIdType)( OSHOOKSERVICEIDBASE + 0x02 ))
#define OSServiceId_PostTaskHook                ((OSServiceIdType)( OSHOOKSERVICEIDBASE + 0x04 ))
#define OSServiceId_StartupHook                 ((OSServiceIdType)( OSHOOKSERVICEIDBASE + 0x06 ))
#define OSServiceId_ShutdownHook                ((OSServiceIdType)( OSHOOKSERVICEIDBASE + 0x08 ))
#define OSServiceId_IdleLoopHook                ((OSServiceIdType)( OSHOOKSERVICEIDBASE + 0x0A ))    /* extra service */
#define OSServiceId_COMErrorHook                ((OSServiceIdType)( OSHOOKSERVICEIDBASE + 0x0C ))
#define OSServiceId_ProtectionHook              ((OSServiceIdType)( OSHOOKSERVICEIDBASE + 0x0E ))
/* schedule table routines */
#define OSServiceId_StartScheduleTableAbs       ((OSServiceIdType)( OSSCHEDULETABLESERVICEIDBASE + 0x00 ))
#define OSServiceId_StartScheduleTableRel       ((OSServiceIdType)( OSSCHEDULETABLESERVICEIDBASE + 0x02 ))
#define OSServiceId_StopScheduleTable           ((OSServiceIdType)( OSSCHEDULETABLESERVICEIDBASE + 0x04 ))
#define OSServiceId_NextScheduleTable           ((OSServiceIdType)( OSSCHEDULETABLESERVICEIDBASE + 0x06 ))
#define OSServiceId_SyncScheduleTable           ((OSServiceIdType)( OSSCHEDULETABLESERVICEIDBASE + 0x08 ))
#define OSServiceId_SetScheduleTableAsync       ((OSServiceIdType)( OSSCHEDULETABLESERVICEIDBASE + 0x0A ))
#define OSServiceId_GetScheduleTableStatus      ((OSServiceIdType)( OSSCHEDULETABLESERVICEIDBASE + 0x0C ))
#define OSServiceId_StartScheduleTableSynchron  ((OSServiceIdType)( OSSCHEDULETABLESERVICEIDBASE + 0x0E ))
/* multicore routines */
#define OSServiceId_GetSpinlock                 ((OSServiceIdType)( OSMULTICORESERVICEIDBASE + 0x00 ))
#define OSServiceId_TryToGetSpinlock            ((OSServiceIdType)( OSMULTICORESERVICEIDBASE + 0x02 ))
#define OSServiceId_ReleaseSpinlock             ((OSServiceIdType)( OSMULTICORESERVICEIDBASE + 0x04 ))
#define OSServiceId_GetCoreID                   ((OSServiceIdType)( OSMULTICORESERVICEIDBASE + 0x06 ))
#define OSServiceId_StartCore                   ((OSServiceIdType)( OSMULTICORESERVICEIDBASE + 0x08 ))
#define OSServiceId_StartNonAutosarCore         ((OSServiceIdType)( OSMULTICORESERVICEIDBASE + 0x0A ))

#endif /* defined(OSORTICURRENTSERVICEID)  || defined(OSGETSERVICEID) || defined(OSCOMGETSERVICEID) || defined(OSCOMPARAMETERACCESS) */


#if defined(OSPARAMETERACCESS)
/*
 * part of public API
 * macros for access of OS services 1st parameter
 */
#define OSError_StartOS_Mode()                               ((AppModeType)OsObjId)
#define OSError_CallTrustedFunction_FunctionID()             ((TrustedFunctionIndexType)OsObjId)
#define OSError_CheckISRMemoryAccess_ISRID()                 ((ISRType)OsObjId)
#define OSError_CheckTaskMemoryAccess_TaskID()               ((TaskType)OsObjId)
#define OSError_CheckObjectAccess_ApplicationID()            ((ApplicationType)OsObjId)
#define OSError_GetApplicationState_ApplicationID()          ((ApplicationType)OsObjId)
#define OSError_TerminateApplication_ApplicationID()         ((ApplicationType)OsObjId)
#define OSError_CheckObjectOwnership_ObjectID()              ((ObjectTypeType)OsObjId)

/* task management services */      
#define OSError_ActivateTask_TaskID()                        ((TaskType)OsObjId)
#define OSError_ChainTask_TaskID()                           ((TaskType)OsObjId)
#define OSError_GetTaskState_TaskID()                        ((TaskType)OsObjId)
/* interrupt handling services */
#define OSError_DisableInterruptSource_ISRID()               ((ISRType)OsObjId)
#define OSError_EnableInterruptSource_ISRID()                ((ISRType)OsObjId)
/* resource management services */
#define OSError_GetResource_ResID()                          ((ResourceType)OsObjId)
#define OSError_ReleaseResource_ResID()                      ((ResourceType)OsObjId)
/* event control services */
#define OSError_SetEvent_TaskID()                            ((TaskType)OsObjId)
#define OSError_GetEvent_TaskID()                            ((TaskType)OsObjId)

/* alarms services */
#define OSError_GetAlarmBase_AlarmID()                       ((AlarmType)OsObjId)
#define OSError_GetAlarm_AlarmID()                           ((AlarmType)OsObjId)
#define OSError_SetRelAlarm_AlarmID()                        ((AlarmType)OsObjId)
#define OSError_SetAbsAlarm_AlarmID()                        ((AlarmType)OsObjId)
#define OSError_CancelAlarm_AlarmID()                        ((AlarmType)OsObjId)
/* counters services */
#define OSError_InitCounter_CounterID()                      ((CounterType)OsObjId)
#define OSError_IncrementCounter_CounterID()                 ((CounterType)OsObjId)
#define OSError_GetCounterValue_CounterID()                  ((CounterType)OsObjId)
#define OSError_GetElapsedValue_CounterID()                  ((CounterType)OsObjId)
#define OSError_GetCounterInfo_CounterID()                   ((CounterType)OsObjId)
/* schedule table */
#define OSError_StartScheduleTableAbs_ScheduleTableID()      ((ScheduleTableType)OsObjId)
#define OSError_StartScheduleTableRel_ScheduleTableID()      ((ScheduleTableType)OsObjId)
#define OSError_StopScheduleTable_ScheduleTableID()          ((ScheduleTableType)OsObjId)
#define OSError_NextScheduleTable_ScheduleTableID()          ((ScheduleTableType)OsObjId)
#define OSError_StartScheduleTableSynchron_ScheduleTableID() ((ScheduleTableType)OsObjId)
#define OSError_SyncScheduleTable_ScheduleTableID()          ((ScheduleTableType)OsObjId)
#define OSError_SetScheduleTableAsync_ScheduleTableID()      ((ScheduleTableType)OsObjId)
#define OSError_GetScheduleTableStatus_ScheduleTableID()     ((ScheduleTableType)OsObjId)
#endif /* defined(OSPARAMETERACCESS) */


#ifdef __cplusplus
}
#endif            /* __cplusplus */


#endif /*OS_ERROR_API_H*/

/** @} */

