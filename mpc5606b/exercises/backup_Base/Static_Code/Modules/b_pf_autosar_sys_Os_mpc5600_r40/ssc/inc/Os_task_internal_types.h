/**
*   @file    Os_task_internal_types.h
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

#ifndef OS_TASK_INTERNAL_TYPES_H_
#define OS_TASK_INTERNAL_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>
#include <Os_types_basic.h>     /* for OSDWORD ... */
#include <Os_types_common_internal.h>   /* for OSTASKENTRY ... */

#include <Os_tp_internal_types.h>       /* for OSTPRESLOCK */

#if defined(OSUSETCB)
       
struct TagOSTSKCB                  /* Task control block structure */
{
    OSTASKENTRY entry;             /* entry point of task */

    #if defined(OSUSETOS)
    OSDWORD *tos;                  /* top of task stack */
    #if defined(OSUSEBOS)
    OSDWORD *bos;                  /* bottom of task stack */
    #endif
    #endif                         /* defined(OSUSETOS) */

    #if (OSNXTSKS > 0U)
    /*  Attributes of extended task */
    EventMaskType wait_event;      /* mask of waited events */
    EventMaskType set_event;       /* mask of set events    */
    #endif

    OSJMP_BUFPTR pcontext;         /* pointer to task context stored on own task stack */
    OSTSKCBPTR prev;               /* pointer to preempted (previous) task */

    #if defined(OSUSERESLINK)
    OSRefResType resources;        /* The head of the occupied resources list */
    #endif

    #if (OSORTIDEBUGLEVEL > 0U) && defined(OSRESOURCE)
    OSPRIOTYPE curPrio;            /* current task priority */
    #endif

    #if defined(OSINRES)
    OSBYTE runprio;                /* running prio (internal resource) */
    OSTSKCBPTR prio2Task;          /* references from priority to task */
    #endif                         /* defined(OSINRES) */

    OSBYTE status;                 /* task status (initial equal property ) */
    TaskType taskId;               /* task id (task number in task table)  */

    #if defined(OSAPPLICATION)
    OSAPPLICATIONTYPE appId;       /* application identification value */
    OSAPPLICATIONMASKTYPE appMask; /* application access mask */
    #endif

    #if defined(OSTIMINGPROTECTION)

    /* TP data for AUTOSAR spec. V3/4 */
    #if  (OSNTPTSKBGTS > 0U)
    OSTPTICKTYPE tpExecBudget;  /* the execution budget */
    OSTPTICKTYPE tpRemained;    /* remained time on the budget */
    #endif

    #if  (OSNTPTSKARRIV > 0U)
    OSTPTICKTYPE tpTimeFrame;   /* time frame */
    OSSIGNEDQWORD tpLast;       /* 63-bit time of last successful transition to 'ready' state */
    #endif

    #if (OSNTPTSKINTLOCKTIME > 0U)
    OSTPTICKTYPE tpIntLockTime; /* interrupt locking time */
    #endif

    #if (OSNTPTSKRESLOCKTIME > 0U)
    OSTPRESLOCK *tpResLock;     /* pointer to array with resource locking time configurations  */
    OSResType tpResources;      /* The head of the list of occupied resources with started TP */
    OSWORD tpNumberResLock;     /* number of resource with locking time */
    #endif
    #endif                      /* defined(OSTIMINGPROTECTION) */


};


#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

                  /* +1 - for null task */
extern OSTSKCB OsTaskTable[OSNTSKS + 1U];        /* Task control blocks table */

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#else /* defined(OSUSETCB) */

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

extern OSBYTE OsTaskStatus[OSNTSKS];    /* Tasks status */

#if defined(OSINRES)
extern TaskType OsPrio2Task[OSNTSKS];   /* References from priority to task */
#endif /* defined(OSINRES) */

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#endif /* defined(OSUSETCB) */


#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSUSETCB)
OSDECLAREVAR (extern OSNEAR OSTSKCBPTR, OsRunning_);    /* running task (0, if no task is running) */
#else /* defined(OSUSETCB) */
OSDECLAREVAR (extern OSNEAR OSTASKTYPE, OsRunning_);    /* running task (0, if no task is running) */
#endif /* defined(OSUSETCB) */

#define OsRunning OSUSEVAR(OsRunning_)

#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif



#endif /*OS_TASK_INTERNAL_TYPES_H_ */

/** @} */
