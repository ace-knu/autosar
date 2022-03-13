/**
*   @file    Os_task_internal_api.h
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

#ifndef OS_TASK_INTERNAL_API_H_
#define OS_TASK_INTERNAL_API_H_


#ifdef __cplusplus
extern "C"
{
#endif


#include <Os_types_common_internal.h>   /* for OSTSKCBPTR */

#include <Os_task_internal_types.h>

#include <Os_application_internal_types.h>      /* for OSAPPCB */

#include <Os_scheduler_internal_api.h>  /* for OSTask2Suspend, OSTASKRUNPRIO and friends */


/* Task status      */
                                                /*#define OSTCBSCHEDULER  ( (OSBYTE)0x01 ) *//* (0x01) Task has allocated (locked) the scheduler */
#define OSTCBFIRST       ( (OSBYTE)0x02 )       /* (0x02) First run of task (context must be built) */
#define OSTCBWAIT        ( (OSBYTE)0x04 )       /* (0x04) Task is waiting for an event              */
#define OSTCBNOSUSPENDED ( (OSBYTE)0x10 )       /* Task is not in suspended state, for Ext. Status  */

#define OSTCBSTART      ((OSBYTE)(OSTCBFIRST | OSTCBNOSUSPENDED))


#if defined(OSBCC)

#if defined(OSEXTPRIORS)
#define OSCHECKTASKSTATUS(taskId)  \
    ( (taskId < OSSCHMAXBITNUM) ? \
    ((OsSchedulerVector1 &  ( OSDWORDMSB >> taskId )) ? 1U : 0U) : \
    ((OsSchedulerVector2 &  ( OSDWORDMSB >> ((OSTASKTYPE)taskId - OSSCHMAXBITNUM))) ? 1U : 0U ))
#else /* defined(OSEXTPRIORS) */
#define OSCHECKTASKSTATUS(taskId) \
    (( OsSchedulerVector1 & ( OSDWORDMSB >> (taskId) )) ? 1U : 0U )
#endif /* defined(OSEXTPRIORS) */

#endif /* defined(OSBCC)  */


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#if defined(OSSYSSTKCHECK)

extern void OSCheckStack (void);

#if defined(OSUSETOS)           /* note that OSSYSSTKCHECK is defined ==> field 'bos' is used */
                                          /* Restore stack pad for running task  */
#define OSSTKRESTOREPAD() OSSTKSETGUARD( OsRunning->bos )
#else
#define OSSTKRESTOREPAD() OSSTKSETGUARD( OSSTACKBOTTOM )
#endif

#else
#define OSCheckStack()
#define OSSTKRESTOREPAD()
#endif /* defined(OSSYSSTKCHECK) */


#if(OSNAPPMODES > 1U)
extern void OSInitTasks (AppModeType mode);
#else
extern void OSInitTasks (void);
#endif


#if defined(OSTERMINATION)
extern void OSKillTask (OSTSKCBPTR taskPtr);
#endif

#if !defined(OSSC1) || defined(OSEXTSTATUS)
extern void OSKillRunningTask (void);
#endif

#if defined(OSAPPLICATION)
extern void OSKillAppTasks (OSAPPLICATIONTYPE appId);
#endif



#if defined(OSTIMINGPROTECTION)

#if defined(OSSYSSTKCHECK)      /* Check stack of running task and stop TP if the task is not killed after stack checking */
#if defined(OSSTKHOOKPROTECTION)
#define OSCHECKSTACK_TP(tpstopfunc)                 \
    OSCheckStack();                                 \
    if( (OsKilled & OSRUNTSKKILLED) != 0U )         \
    {                                               \
        OsKilled &= ~OSRUNTSKKILLED;                \
    }                                               \
    else                                            \
    {                                               \
        tpstopfunc();                               \
    }
#else
      /* Note that stack violation is fatal when ProtectionHook is not configured */
#define OSCHECKSTACK_TP(tpstopfunc) OSCheckStack(); tpstopfunc()
#endif /* defined(OSSTKHOOKPROTECTION) */
#else
#define OSCHECKSTACK_TP(tpstopfunc) tpstopfunc()
#endif /* defined(OSSYSSTKCHECK) */

#else /* defined(OSTIMINGPROTECTION) */

       /* It is for SC3 (because OSCHECKSTACK_TP() is used only in the OS dispatchers for SC2,3,4) */
#if defined(OSSYSSTKCHECK)
    #if defined(OSHOOKPROTECTION)
        #define OSCHECKSTACK_TP(arg)   OSCheckStack();  OsKilled &= ~OSRUNTSKKILLED
    #else
        #define OSCHECKSTACK_TP(arg)   OSCheckStack()
    #endif /* defined(OSHOOKPROTECTION) */
#else
    #define OSCHECKSTACK_TP(arg)
#endif /* defined(OSSYSSTKCHECK) */

#endif /* defined(OSTIMINGPROTECTION) */


#if defined(OSMEMPROTECTION)
#if (OSNTRUSTEDFUNCTIONS > 0U)
/*****************************************************************************
 * inline function: OSDisableTasks4App
 * Description:     clears bits in scheduler vector mask for tasks of given
 *                  application except of current running task
 * Returns:         none
 *****************************************************************************/
OSINLINE void
OSDisableTasks4App (OSAPPCB * app)
{
    OsSchedulerVectorMask1 &= ~(app->tasks);
    #if defined(OSEXTPRIORS)
    OsSchedulerVectorMask2 &= ~(app->tasks2);
    if (OsRunning->taskId < OSSCHMAXBITNUM)
    {
    #endif
        OsSchedulerVectorMask1 |= (OSDWORDMSB >> (OsRunning->taskId));
    #if defined(OSEXTPRIORS)
    }
    else
    {
        OsSchedulerVectorMask2 |= (OSDWORDMSB >> ((OSTASKTYPE) OsRunning->taskId - OSSCHMAXBITNUM));
    }
    #endif /* defined(OSEXTPRIORS) */
}

/*****************************************************************************
 * Macro:           OSEnableTasks4App
 * Description:     set bit in scheduler vector mask for tasks of given
 *                  application
 * Returns:         none
 *****************************************************************************/
#if defined(OSEXTPRIORS)
#define OSEnableTasks4App( app ) \
    OsSchedulerVectorMask1 |= (app)->tasks; \
    OsSchedulerVectorMask2 |= (app)->tasks2;
#else
#define OSEnableTasks4App( app ) OsSchedulerVectorMask1 |= (app)->tasks;
#endif
#endif /* (OSNTRUSTEDFUNCTIONS > 0U) */
#endif /* defined(OSMEMPROTECTION) */

/******************************************************************************
* inline function: OSResetInternalPrio
* Description:     clears bit in scheduler vector if there is no OTHER ready
*                  task of running priority, resets Task prio to assigned
* Returns:         none
******************************************************************************/
#if defined(OSINRES)
OSINLINE void
OSResetInternalPrio (void)
{
    if (OSCLEARRUNPRIOBITISNECESSARY ())
    {                           /* if there is no ready task of this prio. */
        OSTask2Suspend (OSTASKRUNPRIO (OsRunning));     /* then clear bit in OsScheduler           */
    }
    OSRESETRUNPRIO ();
}
#else
#define OSResetInternalPrio( )
#endif

/******************************************************************************
* inline function: OSResetInternalPrio2
* Description:     clears bit in scheduler vector if there is no ready task
*                  of running priority, resets Task prio to assigned
* Returns:         none
******************************************************************************/
#if defined(OSINRES)

#if defined(OSECC)

OSINLINE void
OSResetInternalPrio2 (void)
{
    if ((OSTASKSTATUS (OSPRIO2TASKID (OSTASKRUNPRIO (OsRunning))) & (OSTCBNOSUSPENDED | OSTCBWAIT)) != OSTCBNOSUSPENDED)
    {                           /* if there is no ready task of this prio.  */
        OSTask2Suspend (OSTASKRUNPRIO (OsRunning));     /* then clear bit in OsScheduler         */
    }
    OSRESETRUNPRIO ();
}

#else /* defined(OSECC) */

OSINLINE void
OSResetInternalPrio2 (void)
{
    if ((OSTASKSTATUS (OSPRIO2TASKID (OSTASKRUNPRIO (OsRunning))) & OSTCBNOSUSPENDED) == 0U)
    {                           /* if there is no ready task of this prio.  */
        OSTask2Suspend (OSTASKRUNPRIO (OsRunning));     /* then clear bit in OsScheduler         */
    }
    OSRESETRUNPRIO ();
}

#endif /* defined(OSECC) */

#else /* defined(OSINRES) */

#define OSResetInternalPrio2( )

#endif /* defined(OSINRES) */




#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif


#endif /*OS_TASK_INTERNAL_API_H_ */

/** @} */
