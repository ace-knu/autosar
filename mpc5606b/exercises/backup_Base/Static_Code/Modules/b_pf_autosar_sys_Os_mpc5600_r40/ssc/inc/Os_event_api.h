/**
*   @file    Os_event_api.h
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

#ifndef OS_EVENT_API_H
#define OS_EVENT_API_H

#ifdef __cplusplus
extern "C"
{
#endif    /* __cplusplus */

#include <Os_prop_autosar_api.h>
#include <Os_memory_api.h>  /* for OSServiceCallX defines */

#if ( defined(OSECC) && (OSNXTSKS > 0U) ) /* events only available in extended mode && extended tasks available */


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

/*  Public OS Services  */
extern StatusType OS_SetEvent   ( TaskType taskId, EventMaskType mask );
extern StatusType OS_ClearEvent ( EventMaskType mask );
extern StatusType OS_WaitEvent  ( EventMaskType mask );
extern StatusType OS_GetEvent   ( TaskType taskId, EventMaskRefType maskRef );

#define DeclareEvent(Event)  extern OSBYTE osdummy

/*  Public OS API  */
#if defined(OSMEMPROTECTION)

OSINLINE StatusType SetEvent (TaskType taskId, EventMaskType mask)
{
    OSServiceCall2 (StatusType, taskId, mask, SetEvent);
}

OSINLINE StatusType ClearEvent (EventMaskType mask)
{
    OSServiceCall1 (StatusType, mask, ClearEvent);
}

OSINLINE StatusType WaitEvent (EventMaskType mask)
{
    OSServiceCall1 (StatusType, mask, WaitEvent);
}

OSINLINE StatusType GetEvent (TaskType taskId, EventMaskRefType maskRef)
{
    OSServiceCall2 (StatusType, taskId, maskRef, GetEvent);
}

#else            /* defined(OSMEMPROTECTION) */

#define SetEvent(taskId, mask)    OS_SetEvent(taskId, mask)
#define ClearEvent(mask)          OS_ClearEvent(mask)
#define WaitEvent(mask)           OS_WaitEvent(mask)
#define GetEvent(taskId, maskRef) OS_GetEvent(taskId, maskRef)

#endif            /* defined(OSMEMPROTECTION) */

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#endif    /* defined(OSECC) && (OSNXTSKS > 0U) */


#ifdef __cplusplus
}
#endif            /* __cplusplus */

#endif /*OS_EVENT_API_H*/

/** @} */

