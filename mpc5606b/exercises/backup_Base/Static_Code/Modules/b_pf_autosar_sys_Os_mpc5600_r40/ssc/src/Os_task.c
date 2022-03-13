/**
*   @file    Os_task.c
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

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Os_task_c_REF_5_1_1
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters. 
* The section identification define's naming convention is defined by AutoSar and identifiers are longer than 31 character. 
* Compilers are checked for support this length of identifiers.
*
* @section Os_task_c_REF_14_7_1
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function 
* A function shall have a sigle point of exit at the end of finction.
* The returned statement is result of error hanling.
*
* @section Os_task_c_REF_17_4_1
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* Array indexing shall be the only allowed form of pointer arithmetic
* The pointers are used to increase of OS performance.
*
* @section Os_task_c_REF_19_1_1
* Violates MISRA 2004 Advisory Rule 19.1, declaration before #include
* #include statements in a file should only be preceded by other preprocessor directives or comments. 
* MemMap is required by AutoSAR to be included in the middle of the source file(s).
*/


/****************** generic includes START ***********************/
#include <Os_prop_autosar.h>

#include <Os_types_basic.h>

#include <Os_types_public.h>
#include <Os_types_common_public.h>
#include <Os_types_common_internal.h>

#include <Os_internal_api.h>
#include <Os_internal_types.h>
#include <Os_internal_config.h>

#include <Os_platform.h>
/****************** generic includes END ***********************/

#include <Os_task_api.h>
#include <Os_task_types.h>
#include <Os_task_internal_types.h>
#include <Os_task_config.h>
#include <Os_task_internal_api.h>

#include <Os_event_internal_api.h>
#include <Os_resource_internal_api.h>

/*
* @violates @ref Os_task_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSUSETCB)
OSDECLAREVAR (OSNEAR OSTSKCBPTR, OsRunning_);   /* running task (0, if no task is running) */
#else
OSDECLAREVAR (OSNEAR OSTASKTYPE, OsRunning_);   /* running task (0, if no task is running) */
#endif

/*
* @violates @ref Os_task_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_task_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#define OS_START_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_task_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#if defined(OSUSETCB)

OSTSKCB OsTaskTable[OSNTSKS + 1U];

#else /* defined(OSUSETCB) */

OSBYTE OsTaskStatus[OSNTSKS];   /* Tasks status */

#if defined(OSINRES)
TaskType OsPrio2Task[OSNTSKS];  /* references from priority to task */
#endif

#endif /* defined(OSUSETCB) */

#define OS_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_task_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#define OSTEXT_START_SEC_CODE
/*
* @violates @ref Os_task_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if !defined(OSCALCULATEOBJIND)
#define taskInd (taskId)
#endif

/*  Task management */

/******************************************************************************
 * Function:    OSSCActivateTask
 *
 * Description: activates the Task, make it RUNNING if conditions are met
 *
 * Return: none
 ******************************************************************************/
OSINLINE void
OSSCActivateTask (OSWORD taskInd)
{


    #if defined(OSUSETCB) || defined(OSINRES)
    #if defined(OSECC)
    #if (OSNXTSKS > 0U)
    OsTaskTable[taskInd].set_event = OSNOEVENTS;
    #endif
    #endif /* defined(OSECC) */

    OSActivateTask (taskInd);

    #else
    OSTask2Ready (taskInd);
    #endif /* defined(OSUSETCB)  || defined(OSINRES) */
}


/******************************************************************************
 * Function:    ActivateTask
 *
 * Description: activates the Task, make it RUNNING if conditions are met
 *
 * Return: E_OK                       no errors
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_LIMIT    (ext.status) the task is already active
 *         E_OS_ACCESS   (ext.status) access to the object denied
 ******************************************************************************/
StatusType
OS_ActivateTask (TaskType taskId)
{
    OSIMSAVE                    /* OSINTMASKTYPE save; */
    #if defined(OSCALCULATEOBJIND)
    OSWORD taskInd;
    #endif

    OSOrtiSetServiceWatch (OSServiceId_ActivateTask);

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
           /*
            * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
            */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_ActivateTask, taskId);
        }
        else
        #endif
        {
           /*
            * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
            */
           OSRETERROR (E_OS_CALLEVEL, OSServiceId_ActivateTask, taskId);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)
    if (OSTASKIDISINVALID (taskId))
    {
        /*
         * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_ActivateTask, taskId); /* invalid ID */
    }
    #endif

    #if defined(OSCALCULATEOBJIND)
    taskInd = OS_GETOBJIND (taskId);
    #endif


    {
        OSDIS (save);
        /*
         * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSCHECKACCESSRIGHTSRI (OsTaskTable[taskInd].appMask, OSServiceId_ActivateTask, taskId);
        if (OSTASKACTEXHAUSTED (taskInd))
        {
            OSRI (save);
            /*
             * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_LIMIT, OSServiceId_ActivateTask, taskId);  /* attempt to multiply activation */
        }
        OSOrtiSetOldServiceID (OSServiceId_ActivateTask);
        OSSCActivateTask (taskInd);
        OSDISPATCH ();
    }
    OSOrtiResetIdOnExit ();     /* set that the caller service is finished */
    OSRI (save);
    return E_OK;
}

#if defined(OSNOFASTTERMINATE)
/******************************************************************************
 * Function:    TerminateTask
 *
 * Description: Terminate the running task
 *
 * Return: function doesn't returns if there are no errors
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_RESOURCE (ext.status) task still occupies resources
 *
 * Notes: do not return on success
 ******************************************************************************/
StatusType
OS_TerminateTask (void)
{
    
    OSOrtiSetServiceWatch (OSServiceId_TerminateTask);

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
           /*
            * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
            */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_TerminateTask, 0U);
        }
        else
        #endif
        {
           /*
            * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
            */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_TerminateTask, 0U);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)
    #if defined(OSUSERESLINK)
    if (OsRunning->resources != OSNULLREFRES)   /* resource is occupied */
    {
        /*
         * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_RESOURCE, OSServiceId_TerminateTask, 0U);
    }
    #endif /* defined(OSUSERESLINK) */
    
    #endif /* OSEXTSTATUS */
    
    OSDI ();

    OSOrtiSetOldServiceID (OSServiceId_TerminateTask);

    OSTaskTerminateDispatch (); /* force dispatcher for terminate case */

    /* never return at this point */
    return (E_OK);
}


/******************************************************************************
 * Function:    ChainTask
 *
 * Description: Terminate the running task and start the given task
 *
 * Return: function doesn't returns if there are no errors
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_RESOURCE (ext.status) calling task still occupies resources
 *         E_OS_ID       (ext.status) the task identifier is invalid
 *         E_OS_LIMIT    (ext.status) non-allowed multiply activation of the task
 *         E_OS_ACCESS   (ext.status) access to the object denied
 *
 * Notes:   do not return on success
 ******************************************************************************/
StatusType
OS_ChainTask (TaskType taskId)
{
    #if defined(OSCALCULATEOBJIND)
    OSWORD taskInd;
    #endif

    OSOrtiSetServiceWatch (OSServiceId_ChainTask);

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
           /*
            * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
            */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_ChainTask, taskId);
        }
        else
        #endif
        {
           /*
            * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
            */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_ChainTask, taskId);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)
    #if defined(OSUSERESLINK)
    if (OsRunning->resources != OSNULLREFRES)   /* resource is occupied */
    {
        /*
         * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_RESOURCE, OSServiceId_ChainTask, taskId);
    }
    #endif /* defined(OSUSERESLINK) */


    if (OSTASKIDISINVALID (taskId))     /* invalid ID */
    {
        /*
         * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_ChainTask, taskId);
    }
    #endif

    #if defined(OSCALCULATEOBJIND)
    taskInd = OS_GETOBJIND (taskId);
    #endif

    {
        OSDI ();
        /*
         * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSCHECKACCESSRIGHTSEI (OsTaskTable[taskInd].appMask, OSServiceId_ChainTask, taskId);
        if ((OSTASKACTEXHAUSTED (taskInd) != 0U) && (OSTSKIND (OsRunning) != taskInd))
        {
            OSEI ();
           /*
            * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
            */
            OSRETERROR (E_OS_LIMIT, OSServiceId_ChainTask, taskId);     /* attempt to multiply activation */
        }
        #if (OSNXTSKS > 0U)
        OsTaskTable[taskInd].set_event = OSNOEVENTS;
        #endif
        OSActivateTask (taskInd);
    }
    OSOrtiSetOldServiceID (OSServiceId_ChainTask);
    OSTaskTerminateDispatch (); /* force dispatcher for terminate case */
    /* never return to this point */
    return E_OK;
}

#endif /* defined(OSNOFASTTERMINATE) */

/******************************************************************************
 * Function:    GetTaskId
 *
 * Description: Return the index, corresponding to running task.
 *
 * Return: E_OK                       no errors
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
  ******************************************************************************/
StatusType
OS_GetTaskID (TaskRefType taskIdRef)
{
    OSOrtiSetServiceWatch (OSServiceId_GetTaskID);

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck
        (OSISRLEVELTASKMASK | OSISRLEVELHOOKERROR | OSISRLEVELHOOKAPPERROR | OSISRLEVELHOOKTASK | OSISRLEVELHOOKPROTECTION))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
           /*
            * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
            */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_GetTaskID, 0U);
        }
        else
        #endif
        {
           /*
            * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
            */
           OSRETERROR (E_OS_CALLEVEL, OSServiceId_GetTaskID, 0U);
        }
    }
    #endif /* OSCHECKCONTEXT */

    /*
     * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKWRITEACCESS (taskIdRef, sizeof (TaskType), OSServiceId_GetTaskID, 0U);

    *taskIdRef = OS_MKOBJID (OBJECT_TASK, (OSWORD) OSTSKIND (OsRunning));

    OSOrtiServiceWatchOnExit (OSServiceId_GetTaskID);   /* clean service watch on hook leaving */
    return (E_OK);
}

/******************************************************************************
 * Function:    OSSCGetTaskState
 *
 * Description: Return the status of the given task
 *
 * Return: none
 ******************************************************************************/
OSINLINE_ void
OSSCGetTaskState (OSWORD taskInd, TaskStateRefType stateRef)
{
    if (taskInd == OSTSKIND (OsRunning))
    {
        *stateRef = RUNNING;
    }                           /* else if ECC1 , there is WAITING state */

    #if defined(OSECC) && (OSNXTSKS > 0U)
    else if ((OSTASKSTATUS (taskInd) & OSTCBWAIT) != 0U)
    {
        *stateRef = WAITING;
    }
    #endif /* defined(OSECC) && (OSNXTSKS > 0U) */

    else
    {
        if (OSISTASKNOSUSPEND (taskInd))
        {
            *stateRef = READY;
        }
        else
        {
            *stateRef = SUSPENDED;
        }
    }
}

/******************************************************************************
 * Function:    GetTaskState
 *
 * Description: Return the status of the given task
 *
 * Return: E_OK                       no errors
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) task identifier is invalid
 *         E_OS_ACCESS   (ext.status) access to the object denied
 ******************************************************************************/
StatusType
OS_GetTaskState (TaskType taskId, TaskStateRefType stateRef)
{
    OSIMSAVE                    /* OSINTMASKTYPE save; */
    #if defined(OSCALCULATEOBJIND)
    OSWORD taskInd;
    #endif

    OSOrtiSetServiceWatch (OSServiceId_GetTaskState);

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK | OSISRLEVELHOOKERROR | OSISRLEVELHOOKAPPERROR | OSISRLEVELHOOKTASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
           /*
            * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
            */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_GetTaskState, taskId);
        }
        else
        #endif
        {
           /*
            * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
            */
           OSRETERROR (E_OS_CALLEVEL, OSServiceId_GetTaskState, taskId);
        }
    }
    #endif /* OSCHECKCONTEXT */

    #if defined(OSEXTSTATUS)
    if (OSTASKIDISINVALID (taskId))
    {
        /*
         * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_GetTaskState, taskId); /* invalid ID */
    }
    #endif

    #if defined(OSCALCULATEOBJIND)
    taskInd = OS_GETOBJIND (taskId);
    #endif

    /*
     * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKACCESSRIGHTS (OsTaskCfgTable[taskInd].appMask, OSServiceId_GetTaskState, taskId);
    /*
     * @violates @ref Os_task_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKWRITEACCESS (stateRef, sizeof (TaskStateType), OSServiceId_GetTaskState, taskId);

    {
        OSDIS (save);
        OSSCGetTaskState (taskInd, stateRef);
        OSOrtiServiceWatchOnExit (OSServiceId_GetTaskState);
    }
    OSRI (save);
    return E_OK;
}

#if defined(OSAPPLICATION)
/***************************************************************************
 * function:   OSKillAppTasks()
 *
 * Description: kills all tasks which belong to given OS-Application 
 *
 * Returns:     none
 *
 **************************************************************************/
void
OSKillAppTasks (OSAPPLICATIONTYPE appId)
{
    OSWORD tskPrio;
    OSDWORD tasksVector = OsAppTable[appId].tasks;

    #if defined(OSEXTPRIORS)
    OSDWORD tasksVector2 = OsAppTable[appId].tasks2;
    #endif

    #if defined(OSEXTPRIORS)
    while ((tskPrio = (OSWORD)OSMask2KilledTask (tasksVector, tasksVector2)) != OSSCHEDULERVECTORSIZE)
    #else
    while ((tskPrio = (OSWORD)OSMask2KilledTask (tasksVector)) != OSSCHEDULERVECTORSIZE)
    #endif
    {
        #define tskInd (tskPrio)
        OsTaskTable[tskInd].appMask = OSGIVENAPPMASK (appId);
        if ((OsTaskTable[tskInd].status & OSTCBNOSUSPENDED) != 0U)
        {
            OSKillTask (&OsTaskTable[tskInd]);
        }
        #undef tskInd
        #if defined(OSEXTPRIORS)
        if (tskPrio >= OSSCHMAXBITNUM)
        {
            tasksVector2 &= (OSDWORD)(~(OSDWORDMSB >> (tskPrio - OSSCHMAXBITNUM)));
        }
        else
        #endif /* defined(OSEXTPRIORS) */
        {
            tasksVector &= (OSDWORD)(~(OSDWORDMSB >> tskPrio));
        }
    }
}
#endif /* defined(OSAPPLICATION) */

#if (!defined(OSSC1)) || defined(OSEXTSTATUS)
/***************************************************************************
 * Function:    OSKillRunningTask
 *
 * Description: kills running Task and performs appropriate cleanup 
 *
 * Notes:       shall not be used by protection handlers.
 *
 **************************************************************************/
void
OSKillRunningTask (void)
{
    OSRUNNINGSTATUS &= ~(OSTCBNOSUSPENDED); /* clear flags */
    OSRUNNINGSTATUS |= OSTCBFIRST;      /* set flag that task has no valid context  yet */


    #if defined(OSUSERESLINK)
    OSReleaseTaskResource (OsRunning);
    #endif

    OSResetInternalPrio2 ();
    OSREMOVETASK (OsRunning);

    #if defined(OSISRENTRYEXIT)
    OSTPKillIntLockTime ();
    #endif
    OSSETTASKMSR ();            /* set MSR for Task, EE = 1 */
}

#endif /* (!defined(OSSC1)) || defined(OSEXTSTATUS) */

#if defined(OSTERMINATION)
/******************************************************************************
 * Function:    OSKillTask
 *
 * Description: kills any task (running or ready) and performs appropriate cleanup 
 *
 * Returns:     n/a
 *
 * Notes:       called with OS and TP interrupts disabled
 *
 ******************************************************************************/
void
OSKillTask (OSTSKCBPTR taskPtr)
{
    #if defined(OSMEMPROTECTION)
    #if (OSNTRUSTEDFUNCTIONS > 0U)
    OSAPPCB *app;
    #endif
    #endif /* defined(OSMEMPROTECTION) */

    taskPtr->status &= ~(OSTCBNOSUSPENDED | OSTCBWAIT); /* clear flags */

    #if defined(OSMEMPROTECTION)
    #if (OSNTRUSTEDFUNCTIONS > 0U)
    app = &OsAppTable[taskPtr->appId];
    if (0U != app->tfContext)
    {
        app->tfContext = 0U;
    #if defined(OSTPBUDGET)
        app->tpError = 0U;
    #endif
        OSEnableTasks4App (app);
    #if (OSNUSERISR > 0U)
        OSEnableISRs4App (taskPtr->appId);
    #endif
    }
    #endif /* (OSNTRUSTEDFUNCTIONS > 0U) */
    #endif /* defined(OSMEMPROTECTION) */

    if (taskPtr == OsRunning)
    {
        #if defined(OSUSEISRLEVEL)
        if (OSISRLEVELMASKED == 0U)
        {   /* we are on Task level */
            OsIsrLevel = 0U;
        #endif

            OSTPResetTaskBudget ();

            #if defined(OSISRENTRYEXIT)
            OSTPKillIntLockTime ();
            OsSuspendLevel = 0U;
            #endif

            OsSuspendLevelAll = 0U;

            /*
            * @violates @ref Os_task_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            OSSTKRESTOREPAD (); /* restore stack pad of running task, just in case */

            OSDI ();
            OSSETTASKMSR ();    /* set MSR for Task, EE = 1 */
            OSCLEARCNTX ();     /* clear all context bits */

        #if defined(OSUSEISRLEVEL)
        }
        #endif

        OsKilled |= OSRUNTSKKILLED;
    }

    else
    {
        OSTPResetReadyTask (taskPtr);

        #if (OSNXTSKS > 0U)
        if ((taskPtr->status & (OSTSKEXTENDED | OSTCBFIRST)) == 0U)
        #else
        if ((taskPtr->status & OSTCBFIRST) == 0U)
        #endif
        {
            OSTSKCBPTR item, next;

            item = OSGETCONTEXTHEAD (); /* head of list */
            if (item == taskPtr)        /* killed task is on head of the list */
            {
                OSLOADCONTEXTADDR (item);
            }
            else                /* look for the killed task context in the list */
            {
                do
                {
                    next = item;
                    item = item->prev;
                }
                while (item != taskPtr);

                next->prev = item->prev;
            }
        }
    }

    taskPtr->status |= OSTCBFIRST;      /* set flag that task has no valid context yet */

    #if defined(OSUSERESLINK)
    OSReleaseTaskResource (taskPtr);
    #else
    #endif /* defined(OSUSERESLINK) */

    #if defined(OSRESOURCE) || defined(OSINRES)
    /*
    * @violates @ref Os_task_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    if (OSGETTASK (OSTSKPRIO (taskPtr)) == taskPtr)
    #endif
    {   /* if this Task static prio points to this Task */
        OSTask2Suspend (OSTSKPRIO (taskPtr));
    }
    #if defined(OSINRES)
    #if defined(OSECC)
    /*
    * @violates @ref Os_task_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    if ((OSTASKSTATUS (OSPRIO2TASKID (OSTASKRUNPRIO (taskPtr))) & (OSTCBNOSUSPENDED | OSTCBWAIT)) != OSTCBNOSUSPENDED)
    #else
    /*
    * @violates @ref Os_task_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    if ((OSTASKSTATUS (OSPRIO2TASKID (OSTASKRUNPRIO (taskPtr))) & OSTCBNOSUSPENDED) == 0U)
    #endif
    {   /* if there is no ready task of this prio */
        OSTask2Suspend (OSTASKRUNPRIO (taskPtr));
    }

    /*
    * @violates @ref Os_task_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    if ((OsPrioLink[OSTASKRUNPRIO (taskPtr)] == taskPtr) && (OSTASKRUNPRIO (taskPtr) != taskPtr->taskId))
    {                           /* if this prio was occupied by this Task and it is not it's own prio */
        /*
        * @violates @ref Os_task_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        OsPrioLink[OSTASKRUNPRIO (taskPtr)] = taskPtr->prio2Task;       /* RESETRUNPRIO */
    }
    #endif /* defined(OSINRES) */
}
#endif /* defined(OSTERMINATION) */

/******************************************************************************
 * Function:    OSInitTasks
 *
 * Description: Initializes tasks
 *
 * Returns:     none
 *
 * Notes: 
 ******************************************************************************/
#if(OSNAPPMODES > 1U)
void
OSInitTasks (AppModeType mode)
#else
void
OSInitTasks (void)
#endif
{

    OSCARDINAL i;

    #if defined(OSUSETCB)
    OSTSKCBPTR task_cb;
    const OSTSK *task_cfg;
    #endif

    /* Init task's control blocks */
    #if defined(OSUSETCB)


    #if defined(OSRESOURCE)

    for (i = 0U; i < OSNPRIORS; i++)
    {
        /*
        * @violates @ref Os_task_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        OsPrioLink[i] = OSNULLPRIOLINK; /* Priority Link table  */
    }
    #endif

    for (i = 0U; i < OSNTSKS; i++)
    {
        task_cb = &(OsTaskTable[i]);
        task_cfg = &(OsTaskCfgTable[i]);



        #if defined(OSAPPLICATION)
        task_cb->appMask = task_cfg->appMask;   /* copy application identification mask value */
        task_cb->appId = task_cfg->appId;       /* copy application identification value */
        #endif

        task_cb->entry = task_cfg->entry;       /* entry point of task */
        task_cb->taskId = task_cfg->taskId;

        #if defined(OSINRES)
        task_cb->runprio = (OSBYTE)task_cfg->runprio;
        #endif

        #if defined(OSRESOURCE) || defined(OSINRES)
        /*
        * @violates @ref Os_task_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        OsPrioLink[task_cfg->taskId] = task_cb;
        #endif

        task_cb->status = (OSBYTE) (OSTCBFIRST | (task_cfg->property));

        #if defined(OSUSETOS)
        #if (OSNXTSKS > 0U)
        if ((task_cfg->property & OSTSKEXTENDED) != 0U)
        {
            /*
            * @violates @ref Os_task_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            task_cb->tos = task_cfg->tos - (OSDWORD)OSSTKADDS;   /* -8 bytes because it is necessary to reserve space for backchain */
            #if defined(OSUSEBOS)
            /*
            * @violates @ref Os_task_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            task_cb->bos = task_cfg->bos;       /* bottom of task stack */
            #endif
        }
        else
        #endif /* (OSNXTSKS > 0U) */

        {   /* for Basic tasks */
            task_cb->tos = 0U;
            #if defined(OSUSEBOS)
            task_cb->bos = OSSTACKBOTTOM;       /* BOS for basic tasks */
            #endif
        }
        #endif /* defined(OSUSETOS) */

        #if (OSNXTSKS > 0U)
        task_cb->set_event = OSNOEVENTS;        /* clear set_event field */
        #endif

        #if defined(OSUSERESLINK)
        task_cb->resources = OSNULLREFRES;
        #endif

        #if defined(OSRESOURCE)
        #if(OSORTIDEBUGLEVEL > 0U)
        task_cb->curPrio = (OSPRIOTYPE) (task_cb->taskId);
        #endif
        #endif /* OSRESOURCE */


        /* Activate auto-startup tasks  */
        #if(OSNAPPMODES > 1U)
        if ((task_cfg->autostart & (OSDWORD)((OSDWORD)1U << mode)) != 0U)
        #else
        if ((task_cfg->property & OSTSKACTIVATE) != 0U)
        #endif
        {
            task_cb->status |= OSTCBSTART;
            OSTask2Ready (task_cfg->taskId);
        }
    }

/*** NULLTASK CB initialization ***/


    task_cb = &(OsTaskTable[OSNULLTASK]);


    #if defined(OSAPPLICATION)
    task_cb->appMask = 0U;
    task_cb->appId = OSNAPPS;
    #endif

    task_cb->entry = 0U;        /* entry point of task */
    task_cb->taskId = OSNULLTASK;

    #if defined(OSINRES)
    task_cb->runprio = OSNTSKS;
    #endif

    #if defined(OSRESOURCE) || defined(OSINRES)
    /*
    * @violates @ref Os_task_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    OsPrioLink[OSNPRIORS - 1U] = task_cb;        /* Init priorities link table */
    #endif

    task_cb->status = OSTCBNOSUSPENDED;
    OSTask2Ready (OSNULLTASK);

    #if defined(OSUSETOS)
    #if defined(OSMEMPROTECTION)
    /*
    * @violates @ref Os_task_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    task_cb->tos = OSSTACKTOP - (OSDWORD)OSSTKADDS;
    #else
    task_cb->tos = 0U;
    #endif
    #if defined(OSUSEBOS)
    task_cb->bos = OSSTACKBOTTOM;
    #endif
    #endif /* defined(OSUSETOS) */

    #if (OSNXTSKS > 0U)
    task_cb->set_event = OSNOEVENTS;
    #endif

    #if defined(OSUSERESLINK)
    task_cb->resources = OSNULLREFRES;
    #endif

    #if defined(OSRESOURCE)
    #if(OSORTIDEBUGLEVEL > 0U)
    task_cb->curPrio = (OSPRIOTYPE) (OSNULLTASK);
    #endif
    #endif /* OSRESOURCE */

    #if defined(OSTIMINGPROTECTION)
    /* Initialize nulltask TP fields */
    #if (OSNTPTSKBGTS > 0U)
    task_cb->tpExecBudget = 0U;
    #endif
    #if (OSNTPTSKARRIV > 0U)
    task_cb->tpTimeFrame = 0U;
    #endif
    #if (OSNTPTSKINTLOCKTIME > 0U)
    task_cb->tpIntLockTime = 0U;
    #endif
    #if (OSNTPTSKRESLOCKTIME > 0U)
    task_cb->tpNumberResLock = 0U;
    task_cb->tpResources = OSNULLRES;
    #endif
    #endif /* defined(OSTIMINGPROTECTION) */

    /* end of NULLTASK CB initialization */

    OsRunning = task_cb;        /* no running task yet  */

    #else /* defined(OSUSETCB) */

    for (i = 0U; i < OSNTSKS; i++)
    {
        OsTaskStatus[i] = OsTaskProperty[i];
        #if(OSNAPPMODES > 1U)
        if ((OsTaskAutostart[i] & (1U << mode)) != 0U)
        #else
        if ((OsTaskStatus[i] & OSTSKACTIVATE) != 0U)
        #endif
        {
            OsTaskStatus[i] |= OSTCBSTART;
            OSTask2Ready (i);
        }
        #if defined(OSINRES)
        OsPrio2Task[i] = i;
        #endif
        /* note that 'fast terminate' mode is not used in multicore environment */
    }

    OsRunning = OSNULLTASK;     /* no running task yet  */
    #endif /* defined(OSUSETCB) */
    OSOrtiSetRunningId ();    
}

#define OSTEXT_STOP_SEC_CODE
/*
* @violates @ref Os_task_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif


/** @} */
