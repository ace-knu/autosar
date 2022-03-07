/**
*   @file    Os_counter_api.h
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

#ifndef OS_COUNTER_API_H
#define OS_COUNTER_API_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <Os_prop_autosar_api.h>
#include <Os_counter_types.h>   /* for StatusType and counter specific types */
#include <Os_memory_api.h>      /* for OSServiceCallX defines */

#if defined(OSCOUNTER)

/* Public OS Services  */

#if (OSNCTRS > 0U)

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#define DeclareCounter(Counter)  extern OSBYTE osdummy

extern StatusType OS_IncrementCounter (CounterType ctrId);
extern StatusType OS_GetCounterValue (CounterType ctrId, TickRefType tickRef);

extern StatusType OS_GetElapsedValue (CounterType ctrId, TickRefType valueRef, TickRefType tickRef);

/*
 * Freescale specific - non Autosar API
 */
extern StatusType OS_InitCounter (CounterType ctrId, TickType value);
extern StatusType OS_GetCounterInfo (CounterType ctrId, CtrInfoRefType info);

#if defined(OSMEMPROTECTION)

OSINLINE StatusType
IncrementCounter (CounterType ctrId)
{
    OSServiceCall1 (StatusType, ctrId, IncrementCounter);
}

OSINLINE StatusType
GetCounterValue (CounterType ctrId, TickRefType tickRef)
{
    OSServiceCall2 (StatusType, ctrId, tickRef, GetCounterValue);
}

OSINLINE StatusType
GetElapsedValue (CounterType ctrId, TickRefType previousValue, TickRefType tickRef)
{
    OSServiceCall3 (StatusType, ctrId, previousValue, tickRef, GetElapsedValue);
}

/*
 * Freescale specific - non Autosar
 */
OSINLINE StatusType
InitCounter (CounterType ctrId, TickType value)
{
    OSServiceCall2 (StatusType, ctrId, value, InitCounter);
}

OSINLINE StatusType
GetCounterInfo (CounterType ctrId, CtrInfoRefType info)
{
    OSServiceCall2 (StatusType, ctrId, info, GetCounterInfo);
}

#else

#define GetCounterValue(ctrId, tickRef)                       OS_GetCounterValue(ctrId, tickRef)

#define GetCounterValue(ctrId, tickRef)                       OS_GetCounterValue(ctrId, tickRef)

#define GetElapsedValue(ctrId, previousValue, tickRef)      OS_GetElapsedValue(ctrId, previousValue, tickRef)
#define IncrementCounter(ctrId)                               OS_IncrementCounter(ctrId)

/*
 * Freescale specific - non Autosar
 */
#define InitCounter(ctrId, value)                             OS_InitCounter(ctrId, value)
#define GetCounterInfo(ctrId, info)                           OS_GetCounterInfo(ctrId, info)
#endif

#if defined(OSSYSTIMER)
#define OS_StartTimers()  OSStartTimers()
#define OS_StopTimers()   OSStopTimers()
#endif

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#endif /* OSNCTRS > 0U  */

#endif /* defined(OSCOUNTER) */

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /*OS_COUNTER_API_H */

/** @} */
