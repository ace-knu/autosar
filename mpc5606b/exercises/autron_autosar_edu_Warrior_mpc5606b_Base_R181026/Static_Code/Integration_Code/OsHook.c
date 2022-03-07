#include "OsHook.h"
#include "os.h"
#include "EcuM.h"
#include "Os_Debug.h"
#include "ErrM.h"

unsigned int GulOsErrorCount = 0;
unsigned int GulOsErrorLastPosition = 0;
OsError GucOsError[SZ_OSERROR] = {{_NoService, _E_OK, (AlarmType)0xFFFF}};
unsigned int GulOsPreTaskHook = 0;
unsigned int GulOsPostTaskHook = 0;
unsigned char GucOsStartupHook = 0;
errorValue GucOsShutdownError = _E_OK;
uint32 Os_GulOsLimitError = 0;
uint32 Os_GulOsStackFaultError = 0;
uint32 Os_GulOsSystemErrorCount = 0;


#define OSHOOK_START_SEC_CODE
#include "Os_memmap.h"

void ErrorHook(unsigned char error)
{
	GulOsErrorLastPosition = GulOsErrorCount & MASK_OSERROR_BUF;
	GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].api = (errorApi)OSErrorGetServiceId();
	GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].errorNo = (errorValue)error;
	switch((errorApi)OSErrorGetServiceId()){
	/* part of public API */
	case _StartOS:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsAppModeId = OS_GETOBJIND(OSError_StartOS_Mode());
		break;
	case _CallTrustedFunction:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsTrustedFunctionIndexId = OS_GETOBJIND(OSError_CallTrustedFunction_FunctionID());
		break;
	case _CheckISRMemoryAccess:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsISRId = OS_GETOBJIND(OSError_CheckISRMemoryAccess_ISRID());
		break;
	case _CheckTaskMemoryAccess:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsTaskId = OS_GETOBJIND(OSError_CheckTaskMemoryAccess_TaskID());
		break;
	case _CheckObjectAccess:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsApplicationId = OS_GETOBJIND(OSError_CheckObjectAccess_ApplicationID());
		break;
	case _GetApplicationState:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsApplicationId = OS_GETOBJIND(OSError_GetApplicationState_ApplicationID());
		break;
	case _TerminateApplication:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsApplicationId = OS_GETOBJIND(OSError_TerminateApplication_ApplicationID());
		break;
	case _CheckObjectOwnership:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsObjectTypeId = OS_GETOBJIND(OSError_CheckObjectOwnership_ObjectID());
		break;
/* task management services */
	case _ActivateTask:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsTaskId = OS_GETOBJIND(OSError_ActivateTask_TaskID());
		break;
	case _ChainTask:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsTaskId = OS_GETOBJIND(OSError_ChainTask_TaskID());
		break;
	case _GetTaskState:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsTaskId = OS_GETOBJIND(OSError_GetTaskState_TaskID());
		break;
	case _DisableInterruptSource:
/* interrupt handling services */
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsISRId = OS_GETOBJIND(OSError_DisableInterruptSource_ISRID());
		break;
	case _EnableInterruptSource:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsISRId = OS_GETOBJIND(OSError_EnableInterruptSource_ISRID());
		break;
#if defined(OSRESOURCE)
	case _GetResource:
/* resource management services */
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsResourceId = OS_GETOBJIND(OSError_GetResource_ResID());
		break;
	case _ReleaseResource:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsResourceId = OS_GETOBJIND(OSError_ReleaseResource_ResID());
		break;
#endif
	case _SetEvent:
/* event control services */
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsTaskId = OS_GETOBJIND(OSError_SetEvent_TaskID());
		break;
	case _GetEvent:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsTaskId = OS_GETOBJIND(OSError_GetEvent_TaskID());
		break;
/* alarms services */
	case _GetAlarmBase:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsAlarmId = OS_GETOBJIND(OSError_GetAlarmBase_AlarmID());
		break;
	case _GetAlarm:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsAlarmId = OS_GETOBJIND(OSError_GetAlarm_AlarmID());
		break;
	case _SetRelAlarm:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsAlarmId = OS_GETOBJIND(OSError_SetRelAlarm_AlarmID());
		break;
	case _SetAbsAlarm:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsAlarmId = OS_GETOBJIND(OSError_SetAbsAlarm_AlarmID());
		break;
	case _CancelAlarm:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsAlarmId = OS_GETOBJIND(OSError_CancelAlarm_AlarmID());
/* counters services */
		break;
	case _InitCounter:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsCounterId = OS_GETOBJIND(OSError_InitCounter_CounterID());
		break;
	case _IncrementCounter:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsCounterId = OS_GETOBJIND(OSError_IncrementCounter_CounterID());
		break;
	case _GetCounterValue:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsCounterId = OS_GETOBJIND(OSError_GetCounterValue_CounterID());
		break;
	case _GetElapsedValue:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsCounterId = OS_GETOBJIND(OSError_GetElapsedValue_CounterID());
		break;
	case _GetCounterInfo:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsCounterId = OS_GETOBJIND(OSError_GetCounterInfo_CounterID());
		break;
#if defined(OSSCHEDULETABLES)
/* schedule table */
	case _StartScheduleTableAbs:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsScheduleTableId = OS_GETOBJIND(OSError_StartScheduleTableAbs_ScheduleTableID());
		break;
	case _StartScheduleTableRel:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsScheduleTableId = OS_GETOBJIND(OSError_StartScheduleTableRel_ScheduleTableID());
		break;
	case _StopScheduleTable:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsScheduleTableId = OS_GETOBJIND(OSError_StopScheduleTable_ScheduleTableID());
		break;
	case _NextScheduleTable:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsScheduleTableId = OS_GETOBJIND(OSError_NextScheduleTable_ScheduleTableID());
		break;
	case _StartScheduleTableSynchron:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsScheduleTableId = OS_GETOBJIND(OSError_StartScheduleTableSynchron_ScheduleTableID());
		break;
	case _SyncScheduleTable:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsScheduleTableId = OS_GETOBJIND(OSError_SyncScheduleTable_ScheduleTableID());
		break;
	case _SetScheduleTableAsync:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsScheduleTableId = OS_GETOBJIND(OSError_SetScheduleTableAsync_ScheduleTableID());
		break;
	case _GetScheduleTableStatus:
		GucOsError[GulOsErrorCount & MASK_OSERROR_BUF].param.OsScheduleTableId = OS_GETOBJIND(OSError_GetScheduleTableStatus_ScheduleTableID());
		break;
#endif
	default:
		/* do nothing */
		break;
	}
	GulOsErrorCount++;

	ErrM_OsErrorNotification(error);
}

void PreTaskHook (void)
{
	GulOsPreTaskHook++;
	Os_GetTaskJitter();
	#if (OS_DEBUG_CPULOAD == STD_ON)
	Os_ResetIdleEntry();
	#endif
}

void PostTaskHook (void)
{
	GulOsPostTaskHook++;
}

void StartupHook( void )
{
	GucOsStartupHook++;
	#if (OS_DEBUG_STACKDEPTH == STD_ON)
	Os_FillMainStackPattern();
	#endif
	#if (OS_DEBUG_CPULOAD == STD_ON)
	Os_InitCPULoad();
	#endif
}

void ShutdownHook(StatusType error)
{
	GucOsShutdownError = (errorValue)error;
	ErrM_OsErrorNotification(error);
	EcuM_Shutdown();
}

void PreIsrHook (void)
{
	#if (OS_DEBUG_CPULOAD == STD_ON)
	Os_ITEntryForCPULoad();
	#endif
}

void PostIsrHook (void)
{
	#if (OS_DEBUG_CPULOAD == STD_ON)
	Os_ITExitForCPULoad();
	#endif
}

#define OSHOOK_STOP_SEC_CODE
#include "Os_memmap.h"
