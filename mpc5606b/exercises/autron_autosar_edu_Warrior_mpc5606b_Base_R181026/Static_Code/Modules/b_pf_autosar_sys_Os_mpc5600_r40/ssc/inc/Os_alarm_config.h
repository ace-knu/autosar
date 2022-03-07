/**
*   @file    Os_alarm_config.h
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

#ifndef OS_ALARM_CONFIG_H_
#define OS_ALARM_CONFIG_H_


#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>
#include <Os_types_basic.h>             /* for OSBYTE, OSWORD ... */
#include <Os_types_common_public.h>     /* for TickType ... */
#include <Os_types_common_internal.h>   /* for OSCALLBACK */

#include <Os_alarm_internal_types.h>    



#if (OSNALMS > 0U)

#if (OSNUSERALMS > 0U)

#if defined(OSAUTOALARMS)

struct tagALMAUTOTYPE           /* Structure of autostarted alarm   */
{
    OSALMCB *almId;             /* Reference to alarm               */
    TickType time;              /* Time to start (relative)         */
    TickType cycle;             /* Alarm cycle, 0 for non-cycled    */
    
    #if (OSNAPPMODES > 1U)
    OSDWORD autostart;          /* bit mask of modes for start      */
    #endif                      /* (OSNAPPMODES > 1) */
    
    OSBYTE type;                /* type of autostart alarm */
};

typedef struct tagALMAUTOTYPE OSALMAUTOTYPE;

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

extern const OSALMAUTOTYPE OsAutoAlarms[OSNAUTOALMS];

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#endif /* defined(OSAUTOALARMS) */

#endif /* (OSNUSERALMS > 0U) */

#if (OSNUSERALMS > 0U)

struct TagOSALM                 /* Structure of the alarm cfg table */
{
    #if defined(OSAPPLICATION)
    OSAPPLICATIONMASKTYPE appMask; /* Application access mask          */
    #endif

    OSWORD taskIndex;           /* Task to start or to set Event    */

    #if defined(OSECC) && defined(OSALMSETEVENT) && (OSNXTSKS > 0U)
    EventMaskType event;        /* if event==0 alarm activates task */
    /* else it sets event for this task */
    #endif                      /*  defined(OSECC) && defined(OSALMSETEVENT) && (OSNXTSKS>0) */

    OSWORD ctrIndex;            /* attached Counter ID  */

    #if defined(OSALMCALLBACK)
    OSCALLBACK callBack;        /* Alarms' hook entry  */
    #endif                      /* defined(OSALMCALLBACK) */

    #if defined(OSALMINCCOUNTER)
    OSWORD ctrIndexInc;         /* Alarms' increment counter */
    #endif

    #if defined(OSAPPLICATION)
    OSAPPLICATIONTYPE appId;    /* application identification value */
    #endif
};

typedef struct TagOSALM OSALM;  /* Alarm configuration table    */

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

extern const OSALM OsAlarmsCfg[OSNUSERALMS];    /*  Configuration Data */

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#endif /* (OSNUSERALMS > 0U) */

#endif /* (OSNALMS > 0U) */


#if (OSNALMS > 0U)

#if (OSNUSERALMS > 0U)

#if defined(OSAUTOALARMS)
#define OSALMABSOLUTE ((OSBYTE)1)       /* Alarm absolute autostart type */
#define OSALMRELATIVE ((OSBYTE)2)       /* Alarm relative autostart type */
#endif

#endif /* (OSNUSERALMS > 0U) */

#endif /* (OSNALMS > 0U) */


#ifdef __cplusplus
}
#endif


#endif /*OS_ALARM_CONFIG_H_ */

/** @} */
