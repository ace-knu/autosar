/**
*   @file    Os_event.c
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
* @section Os_event_c_REF_14_7_1
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function 
* A function shall have a sigle point of exit at the end of finction.
* The returned statement is result of error hanling.
*
* @section Os_event_c_REF_19_1_1
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

#include <Os_event_api.h>
#include <Os_event_internal_api.h>


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#if defined(OSECC) && (OSNXTSKS > 0U)

#if !defined(OSCALCULATEOBJIND)
#define taskInd (taskId)
#endif

/*  Private OS Services */

/***************************************************************************
 * Function : OSSetEvent
 *
 * Description: set event and moves Task to Ready state
 *
 * Returns: none
 *
 **************************************************************************/
void
OSSetEvent (OSTSKCBPTR task, EventMaskType mask)
{
    task->set_event |= mask;

    if ((task->status & OSTCBWAIT) != 0U)        /* if task is waiting for event */
    {
        if ((task->wait_event & mask) != 0U)     /* event we are waiting on has occurred */
        {
            OSReleaseTask (task->taskId, mask);
        }
    }
    return;
}

/***************************************************************************
 * Function : OSSetEventInAlm
 *
 * Description: set event and moves Task to Ready state 
 *
 * Returns: none
 *
 **************************************************************************/
#if (OSNTPTSKARRIV > 0U) && defined(OSHOOKPROTECTION)
void
OSSetEventInAlm (OSTSKCBPTR task, EventMaskType mask)
{
    task->set_event |= mask;

    if ((task->status & OSTCBWAIT) != 0U)
    {
        if ((task->wait_event & mask) != 0U)     /* Any event is occurred */
        {
            OSReleaseTaskInAlm (task->taskId, mask);
        }
    }

    return;
}
#endif /* (OSNTPTSKARRIV > 0U) && defined(OSHOOKPROTECTION) */


/*** Public OS Services ***/

/******************************************************************************
 * Function:    SetEvent
 *
 * Description: set event and performs dispatching if nessesary
 *
 * Return: E_OK                       no errors
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_ACCESS   (ext.status) the task is the basic task (not extended)
 *         E_OS_STATE    (ext.status) the task is in suspended state
 *         E_OS_ACCESS   (ext.status) access to the object denied
 ******************************************************************************/
StatusType
OS_SetEvent (TaskType taskId, EventMaskType mask)
{

    OSIMSAVE                    /* OSINTMASKTYPE save; */
    OSTSKCB * task_cb;

    #if defined(OSCALCULATEOBJIND)
    OSWORD taskInd;             /* index in Tasks tables */
    #endif

    OSOrtiSetServiceWatch (OSServiceId_SetEvent);       /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_SetEvent, taskId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_SetEvent, taskId);
        }
    }
    #endif /* OSCHECKCONTEXT */

    #if defined(OSEXTSTATUS)
    if (OSTASKIDISINVALID (taskId))     /* invalid ID */
    {
        /*
         * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_SetEvent, taskId);
    }
    #endif

    #if defined(OSCALCULATEOBJIND)
    taskInd = OS_GETOBJIND (taskId);
    #endif

    task_cb = &OsTaskTable[taskInd];

    #if defined(OSEXTSTATUS)
    if ((task_cb->status & OSTSKEXTENDED) == 0U) /* it isn't an extended task */
    {
        /*
         * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ACCESS, OSServiceId_SetEvent, taskId);
    }
    #endif /* OSEXTSTATUS */


    {

        OSDIS (save);

        /*
         * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSCHECKACCESSRIGHTSRI (task_cb->appMask, OSServiceId_SetEvent, taskId);

        if ((task_cb->status & OSTCBNOSUSPENDED) == 0U)
        {
            OSRI (save);
            #if defined(OSEXTSTATUS)        /* the task is in a suspended state */
            /*
             * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_STATE, OSServiceId_SetEvent, taskId);
            #else
            OSOrtiServiceWatchOnExit (OSServiceId_SetEvent);
            /*
             * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return E_OK;
            #endif
        }

        OSOrtiSetOldServiceID (OSServiceId_SetEvent);

        OSSetEvent (task_cb, mask);
        OSDISPATCH ();

    }

    OSOrtiResetIdOnExit ();
    OSRI (save);
    return E_OK;
}

/******************************************************************************
 * Function:    ClearEvent
 *
 * Description: the events of the extended task are cleared according
 *              to the event mask
 *
 * Return: E_OK                       no errors
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ACCESS   (ext.status) the task is the basic task (not extended)
 *         E_OS_STATE    (ext.status) the task is in suspended state
 ******************************************************************************/
StatusType
OS_ClearEvent (EventMaskType mask)
{
    OSIMSAVE                    /* OSINTMASKTYPE save; */
    
    
    OSOrtiSetServiceWatch (OSServiceId_ClearEvent); /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_ClearEvent, 0U);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_ClearEvent, 0U);
        }
    }
    #endif /* OSCHECKCONTEXT */

    #if defined(OSEXTSTATUS)
    if ((OsRunning->status & OSTSKEXTENDED) == 0U)       /* it isn't an extended task */
    {
        /*
         * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ACCESS, OSServiceId_ClearEvent, 0U);
    }
    #endif

    OSDIS (save);
    OsRunning->set_event &= (EventMaskType) (~mask);
    OSRI (save);

    OSOrtiServiceWatchOnExit (OSServiceId_ClearEvent);
    return E_OK;
}

/******************************************************************************
 * Function :   WaitEvent
 *
 * Description: wait event; performs dispatching if necessary
 *
 * Return: E_OK                       no errors
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ACCESS   (ext.status) the task is the basic task (not extended)
 *         E_OS_RESOURCE (ext.status) the task occupies the resources
 ******************************************************************************/
StatusType
OS_WaitEvent (EventMaskType mask)
{
    OSOrtiSetServiceWatch (OSServiceId_WaitEvent);  /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_WaitEvent, 0U);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_WaitEvent, 0U);
        }
    }
    #endif /* OSCHECKCONTEXT */

    #if defined(OSEXTSTATUS)

    if ((OsRunning->status & OSTSKEXTENDED) == 0U)       /* it isn't an extended task */
    {
        /*
         * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ACCESS, OSServiceId_WaitEvent, 0U);
    }

    #if defined(OSUSERESLINK)

    if (OsRunning->resources != OSNULLREFRES)   /* resources are occupied */
    {
        /*
         * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_RESOURCE, OSServiceId_WaitEvent, 0U);
    }

    #endif /* defined(OSUSERESLINK) */

    #endif /* OSEXTSTATUS */


    OSDI ();                    /* It is not necessary to save./restore int.mask  because    */
    /* this service shall be called with enabled interrupts only */

    #if (OSNTRUSTEDFUNCTIONS > 0U)
    if (0U != OsAppTable[OsRunning->appId].tfContext)
    {
        OSEI ();
        /*
         * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_STATE, OSServiceId_WaitEvent, 0U);
    }
    #endif /* (OSNTRUSTEDFUNCTIONS > 0U) */

    OSOrtiSetOldServiceID (OSServiceId_WaitEvent);

    OSTPSetWAITEVT ();

    OsRunning->wait_event = mask;

    /* if event we are waiting on is not already set */
    if ((mask & OsRunning->set_event) == 0U)
    {
        OSResetInternalPrio2 ();
        OSRUNNINGSTATUS |= OSTCBWAIT;  /* set Task to waiting state */
        OSREMOVETASK (OsRunning);      /* remove task from ready queue */
        OSTaskForceDispatch ();        /* force dispatcher */
    }

    #if defined(OSTIMINGPROTECTION) && ( (OSNTPTSKBGTS > 0U) || (OSNTPTSKARRIV > 0U) )
    else
    {
        #if defined(OSHOOKPROTECTION) && (OSNTPTSKARRIV > 0U)
        if (OSTPStartTaskFrame (OsRunning->taskId))
        #else
        OSTPStartTaskFrame (OsRunning->taskId);
        #endif
        {
            OSTPRestartTaskBudget ();
        }
        #if defined(OSHOOKPROTECTION) && (OSNTPTSKARRIV > 0U)
        else                    /* there is task arrival rate violation */
        {
            /* action is PRO_IGNORE */
            /* event is remained in set state(OS467) */
            OSResetInternalPrio2 ();
            OSRUNNINGSTATUS |= OSTCBWAIT;  /* set Task to waiting state */
            OSREMOVETASK (OsRunning);      /* remove task from ready queue */
            OSTaskForceDispatch ();        /* force dispatcher */
        }
        #endif
    }
    #endif /* defined(OSTIMINGPROTECTION) && ( (OSNTPTSKBGTS > 0U) || (OSNTPTSKARRIV > 0U) ) */

    OSTPClrWAITEVT ();

    OSOrtiResetIdOnExit ();
    OSEI ();
    return E_OK;
}

/******************************************************************************
 * Function:    GetEvent
 *
 * Description: returns the current state of all event bits of the task
 *
 * Return: E_OK                       no errors
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_ACCESS                access to the object denied
 *
 * Notes: without critical section 
 ******************************************************************************/
StatusType
OS_GetEvent (TaskType taskId, EventMaskRefType maskRef)
{
    EventMaskType event;

    #if defined(OSCALCULATEOBJIND)
    OSWORD taskInd;         /* index in Tasks tables */
    #endif

    OSTSKCB *task_cb;

    OSOrtiSetServiceWatch (OSServiceId_GetEvent);       /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK | OSISRLEVELHOOKERROR | OSISRLEVELHOOKAPPERROR | OSISRLEVELHOOKTASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_GetEvent, taskId);
        }
        else
        #endif
        {
           /*
            * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
            */
           OSRETERROR (E_OS_CALLEVEL, OSServiceId_GetEvent, taskId);
        }
    }
    #endif /* OSCHECKCONTEXT */

    #if defined(OSEXTSTATUS)
    if (OSTASKIDISINVALID (taskId))     /* invalid ID */
    {
       /*
        * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
        */
       OSRETERROR (E_OS_ID, OSServiceId_GetEvent, taskId);
    }
    #endif

    #if defined(OSCALCULATEOBJIND)
    taskInd = OS_GETOBJIND (taskId);
    #endif

    #if defined(OSEXTSTATUS)
    if ((OSTASKSTATUS (taskInd) & OSTSKEXTENDED) == 0U)  /* it isn't an extended task */
    {
       /*
        * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
        */
       OSRETERROR (E_OS_ACCESS, OSServiceId_GetEvent, taskId);
    }

    if ((OSTASKSTATUS (taskInd) & OSTCBNOSUSPENDED) == 0U)       /* the task is in a suspended state */
    {
       /*
        * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
        */
       OSRETERROR (E_OS_STATE, OSServiceId_GetEvent, taskId);
    }
    #endif /* defined(OSEXTSTATUS) */

    task_cb = &OsTaskTable[taskInd];
    /*
     * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKACCESSRIGHTS (OsTaskCfgTable[taskInd].appMask, OSServiceId_GetEvent, taskId);
    /*
     * @violates @ref Os_event_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKWRITEACCESS (maskRef, sizeof (EventMaskType), OSServiceId_GetEvent, taskId);

    event = task_cb->set_event;
    *maskRef = event;

    OSOrtiServiceWatchOnExit (OSServiceId_GetEvent);
    return E_OK;
}

#endif /* defined(OSECC) && (OSNXTSKS > 0U) */

#define OSTEXT_STOP_SEC_CODE
/*
* @violates @ref Os_event_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif


/** @} */
