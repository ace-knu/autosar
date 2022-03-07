/**
*   @file    Os_alarm_api.h
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

#ifndef OS_ALARM_API_H
#define OS_ALARM_API_H

#ifdef __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

#include <Os_prop_autosar_api.h>

#include <Os_alarm_types.h>
#include <Os_memory_api.h>      /* for OSServiceCallX defines */

/* Note: Condition '#if defined OSALARM' is equivalent to condition '#if OSNUSERALMS > 0' */
/* Note: Condition '#if OSNALMS > 0' is equivalent to conditions '#if OSNUSERALMS > 0 || OSNSCTALMS > 0' */

#if (OSNALMS > 0U)
#if (OSNUSERALMS > 0U)
/* OSEK req. */
#define ALARMCALLBACK(funcName) void funcName( void )
#endif
#endif

#if (OSNUSERALMS > 0U)

#define DeclareAlarm(Alarm) extern OSBYTE osdummy

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

/* Alarm Autosar public API  */
extern StatusType OS_GetAlarmBase (AlarmType almId, AlarmBaseRefType info);
extern StatusType OS_GetAlarm (AlarmType almId, TickRefType tickRef);
extern StatusType OS_SetRelAlarm (AlarmType almId, TickType increment, TickType cycle);
extern StatusType OS_SetAbsAlarm (AlarmType almId, TickType start, TickType cycle);
extern StatusType OS_CancelAlarm (AlarmType almId);


#if defined(OSMEMPROTECTION)

/* inline wrappers for OS services */

OSINLINE StatusType GetAlarmBase (AlarmType almId, AlarmBaseRefType info)
{
    OSServiceCall2 (StatusType, almId, info, GetAlarmBase);
}

OSINLINE StatusType GetAlarm (AlarmType almId, TickRefType tickRef)
{
    OSServiceCall2 (StatusType, almId, tickRef, GetAlarm);
}

OSINLINE StatusType SetRelAlarm (AlarmType almId, TickType increment, TickType cycle)
{
    OSServiceCall3 (StatusType, almId, increment, cycle, SetRelAlarm);
}

OSINLINE StatusType SetAbsAlarm (AlarmType almId, TickType start, TickType cycle)
{
    OSServiceCall3 (StatusType, almId, start, cycle, SetAbsAlarm);
}

OSINLINE StatusType CancelAlarm (AlarmType almId)
{
    OSServiceCall1 (StatusType, almId, CancelAlarm);
}

#else                           /* defined(OSMEMPROTECTION) */

#define GetAlarmBase(almId, info)            OS_GetAlarmBase(almId, info)
#define GetAlarm(almId, tickRef)             OS_GetAlarm(almId, tickRef)
#define SetRelAlarm(almId, increment, cycle) OS_SetRelAlarm(almId, increment, cycle)
#define SetAbsAlarm(almId, start, cycle)     OS_SetAbsAlarm(almId, start, cycle)
#define CancelAlarm(almId)                   OS_CancelAlarm(almId)

#endif                          /* defined(OSMEMPROTECTION) */

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#endif                          /* (OSNUSERALMS > 0U) */

#ifdef __cplusplus
}
#endif                          /* __cplusplus */

#endif                          /*OS_ALARM_API_H */

/** @} */
