/**
*   @file    Os_scheduler_internal_api.h
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

#ifndef OS_SCHEDULER_INTERNAL_API_H_
#define OS_SCHEDULER_INTERNAL_API_H_


#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>
#include <Os_types_basic.h>     /* for OSWORD ... */
#include <Os_types_common_internal.h>   /* for OSTSKCBPTR */

#include <Os_task_internal_types.h>     /* for OsRunning and types */
#include <Os_task_config.h>     /* for OSTSKNONPREEMPT */


#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

OSDECLAREVAR (extern OSNEAR OSDWORD, OsSchedulerVector1_);      /* Mask of activated tasks(priorities) */
#define OsSchedulerVector1 OSUSEVAR(OsSchedulerVector1_)

#if defined(OSEXTPRIORS)
OSDECLAREVAR (extern OSNEAR OSDWORD, OsSchedulerVector2_);      /* Mask of activated tasks(priorities) Extended vector */
#define OsSchedulerVector2 OSUSEVAR(OsSchedulerVector2_)
#endif /* defined(OSEXTPRIORS) */

#if (OSNTRUSTEDFUNCTIONS > 0U)
OSDECLAREVAR (extern OSNEAR OSDWORD, OsSchedulerVectorMask1_);  /* Mask on mask of activated tasks(priorities) */
#define OsSchedulerVectorMask1 OSUSEVAR(OsSchedulerVectorMask1_)

#if defined(OSEXTPRIORS)
OSDECLAREVAR (extern OSNEAR OSDWORD, OsSchedulerVectorMask2_);  /* Mask on mask of activated tasks(priorities) Extended vector */
#define OsSchedulerVectorMask2 OSUSEVAR(OsSchedulerVectorMask2_)
#endif
#endif /* (OSNTRUSTEDFUNCTIONS > 0U) */

#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"


#define OSDWORDMSB          0x80000000UL

    /* Scheduler vector width */
#define OSSCHMAXBITNUM 32U

#if defined(OSEXTPRIORS)
#define OSSCHWIDE       2U       /* Number of scheduler registers/variables */
#else /* defined(OSEXTPRIORS) */
#define OSSCHWIDE       1U       /* Number of scheduler registers/variables */
#endif /* defined(OSEXTPRIORS) */

#define OSSCHEDULERVECTORSIZE ( 32U * OSSCHWIDE )

#if defined(OSUSETCB)

#define OSHASRUNNINGTASK        (OsRunning != &OsTaskTable[OSNULLTASK])
#define OSRUNNINGSTATUS         OsRunning->status
#define OSTASKCB(taskId)        OsTaskTable[(taskId)]
#define OSTASKSTATUS(taskId)    OsTaskTable[(taskId)].status

#define OSREMOVETASK(task)      OSTask2Suspend((task)->taskId)
#define OSTSKPRIO(task)         (task)->taskId

#define OSTSKIND(task)          (task)->taskId
#define OSCallTask()            (*OsRunning->entry)()

#if defined(OSRESOURCE) || defined(OSINRES)
#define OSGETTASK(prio)         OsPrioLink[(prio)]
#define OSGETMAXPRIOTASK        OSGETTASK( OSMask2Task() )
#else /* defined(OSRESOURCE) || defined(OSINRES) */
#define OSGETTASK(prio)         (&OsTaskTable[(prio)])
#define OSGETMAXPRIOTASK        OSGETTASK( OSPRIO2TASKID( OSMask2Task() ) )
#endif /* defined(OSRESOURCE) || defined(OSINRES) */

#else /* defined(OSUSETCB) */

#define OSHASRUNNINGTASK        (OsRunning != OSNULLTASK)
#define OSRUNNINGSTATUS         OsTaskStatus[OsRunning]
#define OSTASKSTATUS(taskId)    OsTaskStatus[(taskId)]
#define OSREMOVETASK(taskId)    OSTask2Suspend(taskId)
#define OSTSKIND(task)          task
#define OSTSKPRIO(task)         task
#define OSCallTask()            (*OsTaskEntry[OsRunning])()

#if defined(OSINRES)
#define OSGETTASK(prio)         OsPrio2Task[prio]
#else /* defined(OSINRES) */
#define OSGETTASK(prio)         prio
#endif /* defined(OSINRES) */

#define OSGETMAXPRIOTASK        OSGETTASK( OSMask2Task() )

#endif /* defined(OSUSETCB) */


#define OSPRIO2TASKID(prio) prio


#if defined(OSUSETCB)

#if defined(OSRESOURCE) || defined(OSINRES)

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#define OSNPRIORS (OSNTSKS+1U)
extern OSTSKCBPTR OsPrioLink[OSNPRIORS];        /* Priority Link table */

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#endif /* defined(OSRESOURCE) || defined(OSINRES) */

#endif /* defined(OSUSETCB) */


/* Internal Resources */
#if defined(OSINRES)

#if defined(OSUSETCB)
#define OSTASKRUNPRIO(task)     (task)->runprio
#define OSSETBITRUNPRIO()                                               \
    OSSetPrioBit(OSTASKRUNPRIO(OsRunning));                             \
    OsPrioLink[OSTASKRUNPRIO(OsRunning)] = OsRunning

#define OSSETRUNPRIO() \
    OsRunning->prio2Task = OsPrioLink[OSTASKRUNPRIO(OsRunning)];        \
    OSSETBITRUNPRIO()

#define OSRESETRUNPRIO()        (OsPrioLink[OSTASKRUNPRIO(OsRunning)] = OsRunning->prio2Task)

#else /* defined(OSUSETCB) */
#define OSSETBITRUNPRIO()                                               \
    OSSetPrioBit(OSTASKRUNPRIO(OsRunning));                             \
    OsPrio2Task[OSTASKRUNPRIO(OsRunning)] = OsRunning

#define OSTASKRUNPRIO(task)     OsTaskRunPrio[(task)]
#define OSSETRUNPRIO()          OSSETBITRUNPRIO();
#define OSRESETRUNPRIO()        (OsPrio2Task[OSTASKRUNPRIO(OsRunning)] = OSTASKRUNPRIO(OsRunning))

#endif /* defined(OSUSETCB) */

#if defined(OSECC)
#define OSCLEARRUNPRIOBITISNECESSARY()                                  \
    ((OSTASKRUNPRIO( OsRunning ) != OSTSKPRIO(OsRunning) ) &&           \
     ((OSTASKSTATUS( OSPRIO2TASKID( OSTASKRUNPRIO( OsRunning ) ) ) & (OSTCBNOSUSPENDED | OSTCBWAIT)) != OSTCBNOSUSPENDED) \
    )
#else /* defined(OSECC) */
#define OSCLEARRUNPRIOBITISNECESSARY()                                  \
    ((OSTASKRUNPRIO( OsRunning ) != OSTSKPRIO(OsRunning) ) &&           \
     ((OSTASKSTATUS( OSPRIO2TASKID( OSTASKRUNPRIO( OsRunning ) ) ) & OSTCBNOSUSPENDED) != OSTCBNOSUSPENDED) \
    )
#endif /* defined(OSECC) */

#else /* defined(OSINRES) */

#define OSSETRUNPRIO()
#define OSSETBITRUNPRIO()

#endif /* defined(OSINRES) */

/*  Private OS Services */

#if defined(OSEXTPRIORS)

#define OSSETBITNUM2MASK(taskprio)                                      \
    ( ((OSPRIOTYPE)(taskprio) < (OSPRIOTYPE)OSSCHMAXBITNUM) ?                                   \
      (OsSchedulerVector1 |=  (OSDWORD)( OSDWORDMSB >> (taskprio) )) :           \
      (OsSchedulerVector2 |=  (OSDWORD)( OSDWORDMSB >> ((OSTASKTYPE)(taskprio) - OSSCHMAXBITNUM)) ) \
    )

#define OSTask2Suspend(taskprio)                                        \
    ( ((OSPRIOTYPE)(taskprio) < (OSPRIOTYPE)OSSCHMAXBITNUM) ?                                   \
      (OsSchedulerVector1 &= (OSDWORD)( ~( OSDWORDMSB >> (taskprio) ) )) :           \
      (OsSchedulerVector2 &= (OSDWORD)( ~( OSDWORDMSB >> ((OSTASKTYPE)(taskprio) - OSSCHMAXBITNUM)) ) ) \
    )

#else /* defined(OSEXTPRIORS) */

#define OSTask2Suspend(taskprio)    ( OsSchedulerVector1 &= (OSDWORD)( ~( OSDWORDMSB >> (taskprio) ) ) )

#define OSSETBITNUM2MASK(taskprio)  ( OsSchedulerVector1 |=  (OSDWORD)( OSDWORDMSB >> (taskprio) ) )

#endif /* defined(OSEXTPRIORS) */


#define OSTask2Ready( taskId )      OSSETBITNUM2MASK( taskId )
#define OSSetPrioBit( taskId )      OSSETBITNUM2MASK( taskId )






#if defined(OSHOOKPROTECTION) && (OSNTPTSKARRIV > 0U)
/* Macros are intended for 'task activation' */
#define OSActivateTaskInAlm( taskId )                   \
    if( OSTPStartTaskFrameInAlm( taskId ) == OSTRUE )   \
    {                                                   \
        OSTASKSTATUS( taskId ) |= OSTCBSTART;           \
        OSTask2Ready( taskId );                         \
    }

#define OSActivateTask( taskId )                        \
    if( OSTPStartTaskFrame( taskId ) == OSTRUE )        \
    {                                                   \
        OSTASKSTATUS( taskId ) |= OSTCBSTART;           \
        OSTask2Ready( taskId );                         \
    }

/* Macros are used where an event is set. */
#if defined(OSECC) && (OSNXTSKS > 0U)

#define OSReleaseTaskInAlm( taskId, mask )              \
    if( OSTPStartTaskFrameInAlm( taskId ) == OSTRUE )   \
    {                                                   \
        OSTASKSTATUS( taskId ) &= (OSBYTE)(~OSTCBWAIT); \
        OSTask2Ready( taskId );                         \
    }

#define OSReleaseTask( taskId, mask )                   \
    if( OSTPStartTaskFrame( taskId ) == OSTRUE )        \
    {                                                   \
        OSTASKSTATUS( taskId ) &= (OSBYTE)(~OSTCBWAIT); \
        OSTask2Ready( taskId );                         \
    }

#endif /* defined(OSECC) && (OSNXTSKS > 0U) */

#else /* defined(OSHOOKPROTECTION) && (OSNTPTSKARRIV > 0U) */


         /* Macro is intended for 'task activation' */
#define OSActivateTaskInAlm( taskId )           \
    OSTPStartTaskFrameInAlm( taskId );          \
    OSTASKSTATUS( taskId ) |= OSTCBSTART;       \
    OSTask2Ready( taskId )

#define OSActivateTask( taskId )   OSActivateTaskInAlm( taskId )

#if defined(OSECC) && (OSNXTSKS > 0U)

                  /* Macro is intended for use in 'set event'.  */
#define OSReleaseTaskInAlm( taskId, mask )              \
    OSTPStartTaskFrameInAlm( taskId );                  \
    OSTASKSTATUS( taskId ) &= (OSBYTE)(~OSTCBWAIT);     \
    OSTask2Ready( taskId )

#define OSReleaseTask( taskId, mask )    OSReleaseTaskInAlm( (taskId), (mask) )

#endif

#endif /* defined(OSHOOKPROTECTION) && (OSNTPTSKARRIV > 0U) */




#if (OSNTRUSTEDFUNCTIONS > 0U)

#if defined(OSEXTPRIORS)
#define OSSCHEDULEVECTOR2MASKED (OsSchedulerVector2 & OsSchedulerVectorMask2)
#endif

#define OSSCHEDULEVECTOR1MASKED (OsSchedulerVector1 & OsSchedulerVectorMask1)

#else /* (OSNTRUSTEDFUNCTIONS > 0U) */
#if defined(OSEXTPRIORS)
#define OSSCHEDULEVECTOR2MASKED OsSchedulerVector2
#endif

#define OSSCHEDULEVECTOR1MASKED OsSchedulerVector1

#endif /* (OSNTRUSTEDFUNCTIONS > 0U) */



#if !defined(OSEXTPRIORS)
#define OSMask2Task( ) ( (OSTASKTYPE) OSCNTLZW( OSSCHEDULEVECTOR1MASKED ) )

OSINLINE OSTASKTYPE
OSMask2KilledTask (register OSDWORD scheduler_vector1)
{
    return (OSTASKTYPE) OSCNTLZW (scheduler_vector1);
}

#else /* defined(OSEXTPRIORS) */

OSINLINE OSTASKTYPE
OSMask2Task (void)
{
    register OSDWORD result;
    register OSDWORD tmp;
        result = OSCNTLZW (OSSCHEDULEVECTOR1MASKED);    /* calculate number of leading 'zeros' till first 'one' from left */

    if (result >= OSSCHMAXBITNUM)
    {
        tmp = OSCNTLZW (OSSCHEDULEVECTOR2MASKED);       /* calculate number of leading 'zeros' till first 'one' from left */
        result += tmp;
    }

    return result;
}

OSINLINE OSTASKTYPE
OSMask2KilledTask (register OSDWORD scheduler_vector1, register OSDWORD scheduler_vector2)
{
    register OSDWORD result;
    register OSDWORD tmp;
    result = OSCNTLZW (scheduler_vector1);      /* calculate number of leading 'zeros' till first 'one' from left */

    if (result >= OSSCHMAXBITNUM)
    {
        tmp = OSCNTLZW (scheduler_vector2);     /* calculate number of leading 'zeros' till first 'one' from left */
        result += tmp;
    }
    return result;
}

#endif /* !defined(OSEXTPRIORS) */

#if defined(OSNOFASTTERMINATE)

#if defined(OSTERMINATION)

/***************************************************************************
 * Macro:    OSGETCONTEXTHEAD
 * Description: get the head in the task list
 **************************************************************************/
OSINLINE OSTSKCBPTR
OSGETCONTEXTHEAD (void)
{
    return (OSTSKCBPTR) OSGetSPRG1 ();
}
#endif


#if defined(OSMEMPROTECTION)

#if defined(OSCOMMONSTKSIZE)

/* Stack alignment on 32 for basic tasks in SC3..4: R1 &= ~0x1f and then  R1 -= OSSTKADDS */
#if defined(OSDIABPPC) || defined(OSGHSPPC)
OSASM void
OSALIGNSTACK (void)
{
    e_rlwinm r1, r1, 0, 0, 0x1a 
    se_subi r1, 8
}
#endif

#if defined(OSCWPPC)
OSINLINE void
OSALIGNSTACK (void)
{
    OSASM volatile
    {
        e_rlwinm r1, r1, 0, 0, 0x1a 
        se_subi r1, 8
    }
}
#endif                          /* defined(OSCWPPC) */

#else

#define OSALIGNSTACK()

#endif /* defined(OSCOMMONSTKSIZE) */

#else

#define OSALIGNSTACK()

#endif /* defined(OSMEMPROTECTION) */


/***************************************************************************
 * Macro  : OSSAVECONTEXTADDR
 * Description: Saves the current content of the SPRG1
 *              into Task control block,
 *              sets the new SPRG1 value as Task control block address
 * Returns: none
 * Notes:
 **************************************************************************/
#define OSSAVECONTEXTADDR( task )               \
    (task)->prev = (OSTSKCBPTR) OSGetSPRG1();   \
    OSSetSPRG1((OSDWORD)(task))

/***************************************************************************
 * Macro:    OSLOADCONTEXTADDR
 * Description: Loads the content of the SPRG1 from Task context.
 **************************************************************************/
#define OSLOADCONTEXTADDR( task ) OSSetSPRG1((OSDWORD)(task)->prev)

/***************************************************************************
 * Macro:    OSLOADBASICSP
 * Description: Loads SP of last preempted basic task
 * Note: The macro switches stack.
 *       It cannot be implemented as inline function because the
 *       compiler may call the function instead of inlining.
 **************************************************************************/
#define OSLOADBASICSP()                     \
{                                           \
    register OSTSKCBPTR task;               \
    task = (OSTSKCBPTR)OSGetSPRG1();        \
    OSLOADSP((OSDWORD *)task->pcontext[0]); \
    OSALIGNSTACK();                         \
}

#endif /* defined(OSNOFASTTERMINATE) */


extern void OSTaskForceDispatch (void);
extern void OSTaskInternalDispatch (void);

#if defined(OSNOFASTTERMINATE)

extern void OSTaskTerminateDispatch (void);

#if defined(OSUSETCB)
extern OSSIGNEDDWORD OSSetJmp (OSJMP_BUF);
extern OSSIGNEDDWORD OSLongJmp (OSJMP_BUF);
#endif /* OSUSETCB */

#endif /* OSNOFASTTERMINATE */

#if defined(OSSC1)
#if defined(OSEXTSTATUS)
#define OSDispatchOnError()                                             \
    OSDI();                                                             \
    OSCheckStack();                                 /* check stack overflow */ \
    OSErrorHook_noPar( E_OS_MISSINGEND );           /* Task returned w/o TerminateTask  */ \
    OSCLEARCNTXANDLEVELS( );                                            \
    OSPostTaskHook( );                                                  \
    OSKillRunningTask();    /* remove Task from list and clear Resources */ \
    OsRunning = OSGETMAXPRIOTASK
#else
#define OSDispatchOnError()  OSShutdownOS(E_OS_MISSINGEND)
#endif
#endif /* defined(OSSC1) */

/* Must be called with disabled all/system interrupts */
#if defined(OSMIXPREEMPT)
#define OSDISPALLOWED ((OSRUNNINGSTATUS & OSTSKNONPREEMPT) == 0U)
#endif


/* OSDISPATCH( ) definition , check current task on preemptive condition and call dispatcher if necessary */
#if defined(OSMIXPREEMPT) || defined(OSFULLPREEMPT)
OSINLINE void
OSDISPATCH (void)
{
    if ((OsRunning != OSGETMAXPRIOTASK)
            #if defined(OSISRENTRYEXIT)
            && (OsIsrLevel == 0U)
            #endif
        )
    {
        #if defined(OSMIXPREEMPT)
        if (OSDISPALLOWED)
        #endif
        {
            OSTaskForceDispatch ();
        }
    }
}
#else /* OSNOPREEMPT  */
      /* no call to dispatcher at all */
#define OSDISPATCH( )
#endif /* Scheduling policy */


#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif

#endif /*OS_SCHEDULER_INTERNAL_API_H_ */

/** @} */
