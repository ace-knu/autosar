/**
*   @file    Os_event_internal_api.h
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

#ifndef OS_EVENT_INTERNAL_API_H_
#define OS_EVENT_INTERNAL_API_H_

#ifdef __cplusplus
extern "C"
{
#endif            /* __cplusplus */

#include <Os_prop_autosar.h>
#include <Os_types_basic.h>              /* for OSBYTE ... */
#include <Os_types_common_internal.h>    /* for OSTSKCBPTR ...   */


#if ( defined(OSECC) && (OSNXTSKS > 0U) )

/*  private constants */
#define OSNOEVENTS  ((EventMaskType) 0 )

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

/*  private OS Services  */
extern void OSSetEvent (OSTSKCBPTR task, EventMaskType mask);



#if(OSNTPTSKARRIV > 0U) && defined(OSHOOKPROTECTION)
extern void OSSetEventInAlm (OSTSKCBPTR task, EventMaskType mask);
#else
#define OSSetEventInAlm( task, mask )   OSSetEvent( (task), (mask) )
#endif


#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#endif

#ifdef __cplusplus
}
#endif            /* __cplusplus */


#endif /*OS_EVENT_INTERNAL_API_H_*/

/** @} */

