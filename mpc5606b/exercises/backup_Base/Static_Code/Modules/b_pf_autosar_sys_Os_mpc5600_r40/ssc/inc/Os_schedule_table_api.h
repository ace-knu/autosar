/**
*   @file    Os_schedule_table_api.h
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

#ifndef OS_SCHEDULE_TABLE_API_H_
#define OS_SCHEDULE_TABLE_API_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar_api.h>
#include <Os_schedule_table_types.h>    /* for StatusType, ResourceType */
#include <Os_memory_api.h>      /* for OSServiceCallX defines */


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

/*** Schedule Tables ***/

#if defined(OSSCHEDULETABLES)

/*
 *  used by GetScheduleTableStatus
 */
#define SCHEDULETABLE_NOT_STARTED   ((ScheduleTableStatusType)0)
#define SCHEDULETABLE_STOPPED         SCHEDULETABLE_NOT_STARTED
#define SCHEDULETABLE_NEXT          ((ScheduleTableStatusType)1)
#define SCHEDULETABLE_WAITING       ((ScheduleTableStatusType)2)
#define SCHEDULETABLE_RUNNING       ((ScheduleTableStatusType)3)
#define SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS   ((ScheduleTableStatusType)4)


/*  OS Services  */
extern StatusType OS_StartScheduleTableAbs (ScheduleTableType sctId, TickType tickValue);
extern StatusType OS_StartScheduleTableRel (ScheduleTableType sctId, TickType offset);
extern StatusType OS_StopScheduleTable (ScheduleTableType sctId);
extern StatusType OS_NextScheduleTable (ScheduleTableType sctId_current, ScheduleTableType sctId_next);

extern StatusType OS_StartScheduleTableSynchron (ScheduleTableType sctId);

extern StatusType OS_SyncScheduleTable (ScheduleTableType sctId, GlobalTimeTickType globalTime);
extern StatusType OS_SetScheduleTableAsync (ScheduleTableType sctId);
extern StatusType OS_GetScheduleTableStatus (ScheduleTableType sctId, ScheduleTableStatusRefType scheduleStatus);


#if defined(OSMEMPROTECTION)

/* Inline wrappers for OS services */
OSINLINE StatusType
StartScheduleTableAbs (ScheduleTableType sctId, TickType tickValue)
{
    OSServiceCall2 (StatusType, sctId, tickValue, StartScheduleTableAbs);
}

OSINLINE StatusType
StartScheduleTableRel (ScheduleTableType sctId, TickType offset)
{
    OSServiceCall2 (StatusType, sctId, offset, StartScheduleTableRel);
}

OSINLINE StatusType
StopScheduleTable (ScheduleTableType sctId)
{
    OSServiceCall1 (StatusType, sctId, StopScheduleTable);
}

OSINLINE StatusType
NextScheduleTable (ScheduleTableType sctId_current, ScheduleTableType sctId_next)
{
    OSServiceCall2 (StatusType, sctId_current, sctId_next, NextScheduleTable);
}

OSINLINE StatusType
StartScheduleTableSynchron (ScheduleTableType sctId)
{
    OSServiceCall1 (StatusType, sctId, StartScheduleTableSynchron);
}

OSINLINE StatusType
SyncScheduleTable (ScheduleTableType sctId, GlobalTimeTickType globalTime)
{
    OSServiceCall2 (StatusType, sctId, globalTime, SyncScheduleTable);
}

OSINLINE StatusType
SetScheduleTableAsync (ScheduleTableType sctId)
{
    OSServiceCall1 (StatusType, sctId, SetScheduleTableAsync);
}

OSINLINE StatusType
GetScheduleTableStatus (ScheduleTableType sctId, ScheduleTableStatusRefType scheduleStatus)
{
    OSServiceCall2 (StatusType, sctId, scheduleStatus, GetScheduleTableStatus);
}

#else /* defined(OSMEMPROTECTION) */

#define StartScheduleTableAbs(sctId, tickValue)       OS_StartScheduleTableAbs(sctId, tickValue)
#define StartScheduleTableRel(sctId, offset)          OS_StartScheduleTableRel(sctId, offset)
#define StopScheduleTable(sctId)                      OS_StopScheduleTable(sctId)
#define GetScheduleTableStatus(sctId, scheduleStatus) OS_GetScheduleTableStatus(sctId, scheduleStatus)
#define NextScheduleTable(sctId_current, sctId_next)  OS_NextScheduleTable(sctId_current, sctId_next)

#define StartScheduleTableSynchron(sctId)             OS_StartScheduleTableSynchron(sctId)

#define SyncScheduleTable(sctId, globalTime)          OS_SyncScheduleTable(sctId, globalTime)
#define SetScheduleTableAsync(sctId)                  OS_SetScheduleTableAsync(sctId)

#endif /* defined(OSMEMPROTECTION) */

#endif /* defined(OSSCHEDULETABLES) */

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif


#endif /*OS_SCHEDULE_TABLE_API_H_ */

/** @} */
