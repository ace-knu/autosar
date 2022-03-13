/**
*   @file    Os_tp_v3.c
*   @version 4.0.69
*
*   @brief   AUTOSAR OS - Brief file description (one line).
*   @details timing protection for Autosar V3 and V4
*    Notes: Configuration macros:
*    OSNTPBGTS           - number of tasks and ISRs with execution budget
*    OSNTPTSKBGTS        - number of tasks with execution budget
*    OSNTPISRBGTS        - number of ISR2s with execution budget
*    OSNTPTSKARRIV       - number of tasks with ISR arrival rate
*    OSNTPISRARRIV       - number of ISR2s with ISR arrival rate
*    OSNTPTSKINTLOCKTIME - number of tasks with OS interrupt locking Time
*    OSNTPISRINTLOCKTIME - number of ISR2s with OS interrupt locking Time
*    OSNTPTSKRESLOCKTIME - number of tasks with at least one resource locking Time
*    OSNTPISRRESLOCKTIME - number of ISR2s with at least one resource locking Time
*    OSNTPTSKRESLOCKS    - number of all resource locking time configurations for tasks
*    OSNTPISRRESLOCKS    - number of all resource locking time configurations for ISRs
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
* @section Os_tp_v3_c_REF_5_1_1
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters. 
* The section identification define's naming convention is defined by AutoSar and identifiers are longer than 31 character. 
* Compilers are checked for support this length of identifiers.
*
* @section Os_tp_v3_c_REF_14_7_1
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function 
* A function shall have a sigle point of exit at the end of finction.
* The returned statement is result of error hanling.
*
* @section Os_tp_v3_c_REF_17_4_1
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* Array indexing shall be the only allowed form of pointer arithmetic
* The pointers are used to increase of OS performance.
*
* @section Os_tp_v3_c_REF_19_1_1
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


#include <Os_application_api.h> /* for INVALID_OSAPPLICATION */
#include <Os_task_api.h> /* for INVALID_TASK */
#include <Os_isr_api.h> /* for INVALID_ISR */

#include <string.h>

#if defined(OSTIMINGPROTECTION)


#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

/* TP control blocks of resource locking time for tasks and ISR2s */
#if (OSNTPTSKRESLOCKTIME > 0U)

OSTPRESLOCK OsTPTskResLockTime[OSNTPTSKRESLOCKS];

#endif /* (OSNTPTSKRESLOCKTIME > 0U) */

#if (OSNTPISRRESLOCKTIME > 0U)

                  /* for single core */
OSTPRESLOCK OsTPISRResLockTime[OSNTPISRRESLOCKS];

#endif /* (OSNTPISRRESLOCKTIME > 0U) */

#define OS_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_tp_v3_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

/*
* @violates @ref Os_tp_v3_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_START_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_tp_v3_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if (OSNTPBGTS > 0U)
OSDECLAREVAR (OSNEAR OSObjectType, OsTPBudgetObject_);  /* TP object (TASK or ISR2) with current budget */
#endif

#if (OSNTPTSKINTLOCKTIME > 0U) || (OSNTPISRINTLOCKTIME > 0U)
OSDECLAREVAR (OSNEAR OSObjectType, OsTPIntLockObject_); /* TP object (TASK or ISR2) with current interrupt locking time */
#endif

#if (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U)
OSDECLAREVAR (OSNEAR OSObjectType, OsTPResLockObject_); /* TP object (TASK or ISR2) with current resource locking time */
#endif

OSDECLAREVAR (OSNEAR OSBYTE, OsTPForceReason_); /* reason of TP forced interrupt */
OSDECLAREVAR (OSNEAR OSTPTICKTYPE, OsTPTimVal_);        /* current STM count value */

#if (OSNTPISRARRIV > 0U) || (OSNTPTSKARRIV > 0U)
OSDECLAREVAR (OSNEAR OSDWORD, OsTPOverflowCnt_);        /* TP overflow counter */
#endif



/*
* @violates @ref Os_tp_v3_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_tp_v3_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#define OSTEXT_START_SEC_CODE
/*
* @violates @ref Os_tp_v3_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

/* Prototypes */
#if defined(OSHOOKPROTECTION)
#if defined(OSTPBUDGET)
#define OSTPKILL
#endif

#if defined(OSTPKILL)
static void OSTPKillObjects (ProtectionReturnType action, StatusType err);
#endif
static ProtectionReturnType OSTPProtectionHook (OSObjectType object, StatusType err);
#endif
#if (OSNTRUSTEDFUNCTIONS > 0U) && defined (OSTPBUDGET)
static OSBYTE OSIsTFContext (StatusType err);
#endif

/***************************************************************************
 * Function:    OSInitializeTP
 *
 * Description: initialize TP HW and start timer
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
#if(OSNAPPMODES > 1U)
void OSInitializeTP (AppModeType mode)
{
#if defined(OSCWPPC)
#pragma unused( mode ) /* to suppress warning about unused variable */
#endif
#else
void OSInitializeTP (void)
{
#endif

    #if (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U)
    OSTPRESLOCK * tpResLock;
    #endif

    OSCARDINAL i;
    #if  (OSNTPTSKARRIV > 0U) || (OSNTPISRARRIV > 0U)
    OSSIGNEDQWORD curTime;
    #endif

    #if (OSNTPBGTS > 0U)
    OsTPBudgetObject = OSTPOBJECT0;
    #endif

    #if (OSNTPTSKINTLOCKTIME > 0U) || (OSNTPISRINTLOCKTIME > 0U)
    OsTPIntLockObject = OSTPOBJECT0;
    #endif

    #if (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U)
    OsTPResLockObject = OSTPOBJECT0;
    #endif

    OSTPTimerInit ();           /* init TP HW */
    OsTPForceReason = 0U;

    #if (OSNTPISRARRIV > 0U) || (OSNTPTSKARRIV > 0U)
    OsTPOverflowCnt = 0U;
    #endif

    #if  (OSNTPTSKARRIV > 0U) || (OSNTPISRARRIV > 0U)
    OsTPTimVal = OSTPGetTimVal ();
    OSTPGetTime64 (curTime);    /* get current TP time counter */
    #endif

    /* Init TP for tasks */
    #if (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPTSKBGTS > 0U) || (OSNTPTSKARRIV > 0U) || (OSNTPTSKINTLOCKTIME > 0U)
    {
        OSTSKCBPTR task;
        const OSTSK *task_cfg;

        #if (OSNTPTSKRESLOCKTIME > 0U)
        /*
        * @violates @ref Os_tp_v3_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        tpResLock = &OsTPTskResLockTime[0];
        #endif

        for (i = 0U; i < OSNTSKS; i++)
        {

            task_cfg = &(OsTaskCfgTable[i]);


            task = &(OsTaskTable[i]);

            #if (OSNTPTSKBGTS > 0U)
            task->tpExecBudget = task_cfg->tpExecBudget;
            task->tpRemained = task->tpExecBudget;
            #endif

            #if  (OSNTPTSKARRIV > 0U)
            task->tpTimeFrame = task_cfg->tpTimeFrame;
            #endif

            #if (OSNTPTSKINTLOCKTIME > 0U)
            task->tpIntLockTime = task_cfg->tpIntLockTime;
            #endif

            #if (OSNTPTSKRESLOCKTIME > 0U)
            task->tpResources = OSNULLRES;
            task->tpNumberResLock = task_cfg->tpNumberResLock;
            task->tpResLock = tpResLock;
            memcpy (tpResLock, task_cfg->tpResLock, sizeof (*tpResLock) * task->tpNumberResLock);
            /*
            * @violates @ref Os_tp_v3_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            tpResLock += task->tpNumberResLock;
            #endif

            /* Start TP for the  auto-startup tasks  */
            #if (OSNTPTSKARRIV > 0U)
            #if (OSNAPPMODES > 1U)
            if ((task_cfg->autostart & (1U << mode)) != 0U)
            #else
            if ((task_cfg->property & OSTSKACTIVATE) != 0U)
            #endif
            {
                /* Start TP for the task */
                task->tpLast = curTime;
            }
            else
            {
                /* Reset inter-arrival protection for the task */
                task->tpLast = curTime - ((OSSIGNEDQWORD) task->tpTimeFrame);
            }
        #endif /* (OSNTPTSKARRIV > 0U) */
        }
        /* Initialization of nulltask TP fields is placed to
           OSInitTasks() because these fields may be used in the
           services called from StartupHook(). Note that StartupHook()
           is called before OSInitializeTP(). */
    }
    #endif /* (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPTSKBGTS > 0U) || (OSNTPTSKARRIV > 0U) || (OSNTPTSKINTLOCKTIME > 0U) */


    /* Init TP for ISR2s */
    #if (OSNTPISRRESLOCKTIME > 0U) || (OSNTPISRBGTS > 0U) || (OSNTPISRARRIV > 0U) || (OSNTPISRINTLOCKTIME > 0U)
    {
        const OSISRCFGTYPE *handlerCfgPtr;
        OS_ISRTYPEPTR handlerTablePtr;

        #if (OSNTPISRRESLOCKTIME > 0U)
        /*
        * @violates @ref Os_tp_v3_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        tpResLock = &OsTPISRResLockTime[0];
        #endif

        for (i = 0U; i < (OSNISR+1U); i++)
        {
            handlerCfgPtr = &(OsIsrCfg[i]);
            handlerTablePtr = &(OsIsrTable[i]);


            #if (OSNTPISRBGTS > 0U)
            handlerTablePtr->tpExecBudget = handlerCfgPtr->tpExecBudget;
            #endif

            #if (OSNTPISRARRIV > 0U)
            handlerTablePtr->tpTimeFrame = handlerCfgPtr->tpTimeFrame;
            handlerTablePtr->tpLast = curTime - (OSSIGNEDQWORD)handlerTablePtr->tpTimeFrame;
            #endif

            #if (OSNTPISRINTLOCKTIME > 0U)
            handlerTablePtr->tpIntLockTime = handlerCfgPtr->tpIntLockTime;
            #endif

            #if (OSNTPISRRESLOCKTIME > 0U)
            handlerTablePtr->tpNumberResLock = handlerCfgPtr->tpNumberResLock;
            handlerTablePtr->tpResLock = tpResLock;
            memcpy (tpResLock, handlerCfgPtr->tpResLock, sizeof (*tpResLock) * handlerTablePtr->tpNumberResLock);
            /*
            * @violates @ref Os_tp_v3_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            tpResLock += handlerTablePtr->tpNumberResLock;
            #endif
        }
    }
    #endif /* (OSNTPISRRESLOCKTIME > 0U) || (OSNTPISRBGTS > 0U) || (OSNTPISRARRIV > 0U) || (OSNTPISRINTLOCKTIME > 0U) */
}

#if (OSNTRUSTEDFUNCTIONS > 0U) && defined (OSTPBUDGET)
/***************************************************************************
 * Function:    OSIsTFContext
 *
 * Description: defines - is current OS-Application in Trusted Function context 
 *              or not.
 *
 * Returns:     OSTRUE if current OS-Application is in Trusted Function context 
 *              otherwise - OSFALSE.
 *
 * Notes:
 ***************************************************************************/
static OSBYTE
OSIsTFContext (StatusType err)
{
    OSAPPLICATIONTYPE curApp;
    OSAPPCB *app;

    curApp = (OSAPPLICATIONTYPE)OSGetCurApp ();

    if (curApp != OSINVALID_OSAPPLICATION)
    {
        app = &OsAppTable[curApp];

        /* Check that a trusted function has been called by current runable */
        if ((app->tfContext > 0U) && (app->tpError == 0U))
        {
            app->tpError = err;
            /*
             * @violates @ref Os_tp_v3_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return OSTRUE;
        }
    }

    return OSFALSE;
}
#endif /* (OSNTRUSTEDFUNCTIONS > 0U) && defined (OSTPBUDGET) */

#if defined(OSHOOKPROTECTION)
/***************************************************************************
 * Function:    OSTPProtectionHook
 *
 * Description: identifies violator object and calls the user protection hook
 *
 * Returns:  the action desired by user
 *
 * Notes:
 ***************************************************************************/
static ProtectionReturnType
OSTPProtectionHook (OSObjectType object, StatusType err)
{
    ProtectionReturnType action;
    #if !defined(OSNOISR2)
    OSWORD handlerId;
    #endif

    if (object != OSTPOBJECT0)
    {
        #if defined(OSAPPLICATION)
        OSAPPLICATIONTYPE appId;
        #endif
        #if !defined(OSNOISR2)
        if (OSTP_GETOBJTYP (object) == OBJECT_ISR)
        {
            handlerId = OSTP_GETOBJIND (object);
            OsViolatorTaskId = INVALID_TASK;
            OsViolatorISRId = OS_MKOBJID (OBJECT_ISR, handlerId);
            #if defined(OSAPPLICATION)
            appId = (OSAPPLICATIONTYPE)OS_MKOBJID (OBJECT_APPLICATION, OsIsrTable[handlerId].appId);
            #endif
        }
        else
        #endif /* !defined(OSNOISR2) */
        {
            OsViolatorISRId = INVALID_ISR;
            OsViolatorTaskId = OS_MKOBJID (OBJECT_TASK, OSTP_GETOBJIND (object));
            #if defined(OSAPPLICATION)
            appId = (OSAPPLICATIONTYPE)OS_MKOBJID (OBJECT_APPLICATION, OsTaskTable[OSTP_GETOBJIND (object)].appId);
            #endif
        }
        #if defined(OSAPPLICATION)
        OsViolatorAppId = OS_MKOBJID (OBJECT_APPLICATION, appId);
        #endif
    }
    else
    {
        /* This situation is possible if OSTPProtectionHook is called from a alarm action */
        OsViolatorTaskId = INVALID_TASK;
        OsViolatorISRId = INVALID_ISR;
        #if defined(OSAPPLICATION)
        OsViolatorAppId = INVALID_OSAPPLICATION;
        #endif
    }

    OSOrtiSetServiceWatch (OSServiceId_ProtectionHook); /* set watch to this service */
    OSSETPROTCNXT ();
    OsSuspendLevel = 0U;        /* [OS093] */
    #if (OSNTPTSKARRIV > 0U)
    OsSuspendLevelAll = 0U;     /* OsSuspendLevelAll != 0 may be here
                                   only if task arrival rate violation occurs */
    #endif
    action = ProtectionHook (err);
    OSCLRPROTCNTX ();
    OSOrtiServiceWatchOnExit (OSServiceId_ProtectionHook);      /* clear service watch on hook leaving */

    return action;
}

#if defined(OSTPKILL)
/***************************************************************************
 * Function:    OSTPKillObjects
 *
 * Description: terminates runn-ables as required by the action
 *
 * Returns:  
 *
 * Notes:  it shall be used only in TP interrupts
 ***************************************************************************/
static void
OSTPKillObjects (ProtectionReturnType action, StatusType err)
{
    #if defined(OSAPPLICATION)
    RestartType restart = NO_RESTART;
    #endif

        switch (action)
    {
        case PRO_TERMINATETASKISR:
            #if !defined(OSNOISR2)
            if (OsViolatorISRId != INVALID_ISR)
            {
                OSWORD handlerId = OS_GETOBJIND (OsViolatorISRId);

                #if (OSNTPISRARRIV > 0U)
                if (err != E_OS_PROTECTION_ISR_ARRIVAL)
                #endif
                {
                    OSKillISR (&OsIsrTable[handlerId]);
                }
                /* else
                   nothing to do because of user's ISR has not been called actually
                 */
            }
            else
            #endif  /* !defined(OSNOISR2) */
            {
                OSKillTask (&OsTaskTable[OS_GETOBJIND (OsViolatorTaskId)]);
            }

            break;

        case PRO_TERMINATEAPPL_RESTART:
            #if defined(OSAPPLICATION)
            #if defined(OSHAS_RESTARTTASK)
            if (OsAppTable[OS_GETOBJIND (OsViolatorAppId)].restartTask == OSINVALID_TASK)
            #endif
            {
                /* no restart task was configured for the faulty OS-Application (OS557) */
                OSSetCurApp (OS_GETOBJIND (OsViolatorAppId));
                OSShutdownOS (err);
            }
            restart = RESTART;  /* no break */
            #endif /* defined(OSAPPLICATION) */

        case PRO_TERMINATEAPPL:
            #if defined(OSAPPLICATION)
            {
                if (OSTerminateApplication ((OSAPPLICATIONTYPE)OS_GETOBJIND (OsViolatorAppId), restart))
                {
                    break;
                }
            }
            /* No break. ShutdownOS() shall be called */
            #endif

        case PRO_IGNORE:       /* OSTPKillObjects cannot be called if the
                                   action=PRO_IGNORE and err=E_OS_PROTECTION_ARRIVAL 
                                   (see OSTPStartTaskFrame or OSTPISRArrivalRate).
                                   And so ShutdownOS shall be called here (OS475) */
        case PRO_SHUTDOWN:
        default:
            #if (OSNTPISRARRIV > 0U)
            if (err == E_OS_PROTECTION_ISR_ARRIVAL)
            {
                err = E_OS_PROTECTION_ARRIVAL;
            }
            #endif
            OSShutdownOS (err);
    }
}
#endif /* defined(OSTPKILL) */

#if defined(OSTPBUDGET)
/***************************************************************************
 * Function:    OSTPHandler
 *
 * Description: Handler for timing protection violation
 *
 * Returns: 
 *
 * Notes:  it shall be used only in TP interrupts
 ***************************************************************************/
OSINLINE void
OSTPHandler (OSObjectType object, StatusType err)
{
    OSPUTERROR (err);
    OSTPKillObjects (OSTPProtectionHook (object, err), err);
}
#endif
#endif /* defined(OSHOOKPROTECTION) */




#if (OSNTPBGTS > 0U)
/***************************************************************************
 * Function:    OSISRTPTimerBudget 
 *
 * Description: Interrupt handler for 'budget' STM channel 
 *
 * Returns: 
 *
 * Notes: 
 *
 **************************************************************************/
void
OSISRTPTimerBudget (void)
{
    if (!OSTPTimerInterruptRaised (OSTPCH_BUDGET))
    {
        /*
         * @violates @ref Os_tp_v3_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return;                 /* ignore spurious interrupt */
    }

    OSTPTimerClearFlag (OSTPCH_BUDGET);

    #if (OSNTRUSTEDFUNCTIONS > 0U) && defined (OSTPBUDGET)
    if (OSIsTFContext (E_OS_PROTECTION_TIME) == OSTRUE)
    {
        /*
         * @violates @ref Os_tp_v3_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return;
    }
    #endif
    #if defined(OSHOOKPROTECTION)
    OSEHI ();
    OSTPHandler (OsTPBudgetObject, E_OS_PROTECTION_TIME);

    OSDHI ();
    OSTPLeaveISR ();

    #else
    OSPUTERROR (E_OS_PROTECTION_TIME);
    OSShutdownOS (E_OS_PROTECTION_TIME);
    #endif /* defined(OSHOOKPROTECTION) */
}
#endif /* (OSNTPBGTS > 0U) */


#if (OSNTPTSKINTLOCKTIME > 0U) || (OSNTPISRINTLOCKTIME > 0U)
/***************************************************************************
 * Function:    OSISRTPTimerIntLock
 *
 * Description: Interrupt handler for 'interrupt locking time' STM channel 
 *
 * Returns: 
 *
 * Notes: 
 *
 **************************************************************************/
void
OSISRTPTimerIntLock (void)
{
    if (!OSTPTimerInterruptRaised (OSTPCH_INTLOCK))
    {
        /*
         * @violates @ref Os_tp_v3_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return;                 /* ignore spurious interrupt */
    }
    OSTPTimerClearFlag (OSTPCH_INTLOCK);

    #if (OSNTRUSTEDFUNCTIONS > 0U) && defined (OSTPBUDGET)
    if (OSIsTFContext (E_OS_PROTECTION_LOCKED) == OSTRUE)
    {
        /*
         * @violates @ref Os_tp_v3_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return;
    }
    #endif
    #if defined(OSHOOKPROTECTION)
    OSEHI ();
    OSTPHandler (OsTPIntLockObject, E_OS_PROTECTION_LOCKED);
    OSDHI ();
    OSTPLeaveISR ();
    #else
    OSPUTERROR (E_OS_PROTECTION_LOCKED);
    OSShutdownOS (E_OS_PROTECTION_LOCKED);
    #endif /* defined(OSHOOKPROTECTION) */
}
#endif /* (OSNTPTSKINTLOCKTIME > 0U) || (OSNTPISRINTLOCKTIME > 0U) */

#if (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U)
/***************************************************************************
 * Function:    OSISRTPTimerResLock
 *
 * Description: Interrupt handler for 'resource locking time' STM channel 
 *
 * Returns: 
 *
 * Notes: 
 *
 **************************************************************************/
void
OSISRTPTimerResLock (void)
{
    if (!OSTPTimerInterruptRaised (OSTPCH_RESLOCK))
    {
        /*
         * @violates @ref Os_tp_v3_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return;                 /* ignore spurious interrupt */
    }

    OSTPTimerClearFlag (OSTPCH_RESLOCK);

    #if (OSNTRUSTEDFUNCTIONS > 0U) && defined (OSTPBUDGET)
    if (OSIsTFContext (E_OS_PROTECTION_LOCKED) == OSTRUE)
    {
        /*
         * @violates @ref Os_tp_v3_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return;
    }
    #endif

    #if defined(OSHOOKPROTECTION)

    OSEHI ();
    OSTPHandler (OsTPResLockObject, E_OS_PROTECTION_LOCKED);
    OSDHI ();
    OSTPLeaveISR ();
    #else
    OSPUTERROR (E_OS_PROTECTION_LOCKED);
    OSShutdownOS (E_OS_PROTECTION_LOCKED);
    #endif /* defined(OSHOOKPROTECTION) */
}
#endif /* (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U) */

/***************************************************************************
 * Function:    OSISRTPForced
 *
 * Description: handler for forced TP interrupt
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
void
OSISRTPForced (void)
{
    StatusType err;
    #if defined(OSTPBUDGET) && defined(OSHOOKPROTECTION)
    OSObjectType object;
    #endif

    OSTPTimerForceClearFlag ();

    err = E_OS_SYS_FATAL;


    #if defined(OSTPBUDGET)

    #if (OSNTPBGTS > 0U)
    if ((OsTPForceReason & OSTPFORCEBUDGET) != 0U)
    {
        OsTPForceReason = 0U;
        err = E_OS_PROTECTION_TIME;
        #if defined(OSHOOKPROTECTION)
        object = OsTPBudgetObject;
        #endif
    }
    #endif

    #if (OSNTPTSKINTLOCKTIME > 0U) || (OSNTPISRINTLOCKTIME > 0U)
    if ((OsTPForceReason & OSTPFORCEINTLOCK) != 0U)
    {
        OsTPForceReason = 0U;
        err = E_OS_PROTECTION_LOCKED;
        #if defined(OSHOOKPROTECTION)
        object = OsTPIntLockObject;
        #endif
    }
    #endif

    #if (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U)
    if ((OsTPForceReason & OSTPFORCERESLOCK) != 0U)
    {
        OsTPForceReason = 0U;
        err = E_OS_PROTECTION_LOCKED;
        #if defined(OSHOOKPROTECTION)
        object = OsTPResLockObject;
        #endif
    }
    #endif

    #if (OSNTRUSTEDFUNCTIONS > 0U)
    if ((OsTPForceReason & OSTPFORCEPOSTPONED) != 0U)
    {
        OSAPPLICATIONTYPE curApp = (OSAPPLICATIONTYPE)OSGetCurApp ();

        err = OsAppTable[curApp].tpError;
        OsAppTable[curApp].tpError = 0U;

        OsTPForceReason = 0U;

        #if defined(OSHOOKPROTECTION)
        #if !defined(OSNOISR2)
        if (OSISRLEVELMASKED == 0U)
        #endif
        {
            object = OSTPTASKOBJECT (OsRunning);
        }
        #if !defined(OSNOISR2)
        else
        {
            /*
            * @violates @ref Os_tp_v3_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            OS_ISRTYPEPTR handlerPtr = OsIsrArray[OSISRLEVELMASKED - 1U];
            /*
            * @violates @ref Os_tp_v3_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            object = OSTPISROBJECT (handlerPtr);
        }
        #endif
        #endif /* defined(OSHOOKPROTECTION) */
    }
    #endif /* (OSNTRUSTEDFUNCTIONS > 0U) */

    #if (OSNTRUSTEDFUNCTIONS > 0U) || defined(OSHOOKPROTECTION)
    if (err != E_OS_SYS_FATAL)
    {
        #if (OSNTRUSTEDFUNCTIONS > 0U)
        if (OSIsTFContext (err) == OSTRUE)
        {
            /*
             * @violates @ref Os_tp_v3_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return;
        }
        #endif
        #if defined(OSHOOKPROTECTION)
        OSEHI ();
        OSTPHandler (object, err);
        OSDHI ();
        OSTPLeaveISR ();
        #endif /* defined(OSHOOKPROTECTION) */
    }
    #endif /* (OSNTRUSTEDFUNCTIONS > 0U) || defined(OSHOOKPROTECTION) */


    #endif /* defined(OSTPBUDGET) */
    OSPUTERROR (err);
    OSShutdownOS (err);
}

#if (OSNTPISRARRIV > 0U) || (OSNTPTSKARRIV > 0U)
/***************************************************************************
 * Function:    OSISRTPTimerOVF
 *
 * Description: Interrupt handler for 'overflow' STM channel 
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
void
OSISRTPTimerOVF (void)
{
    OsTPOverflowCnt++;

    OSTPTimerClearFlag (OSTPCH_OVF);
}
#endif /* (OSNTPISRARRIV > 0U) || (OSNTPTSKARRIV > 0U) */

#if(OSNTPBGTS > 0U) || (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U)
/***************************************************************************
 * Function: OSTPStopBudget
 *
 * Description: Stop (preempt) timing protection (the budget and/or the 
 *              resource locking time) when a task or ISR is preempted by 
 *              ISR2 or system timer
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
void
OSTPStopBudget (void)
{
    OsTPTimVal = OSTPGetTimVal ();  /* get the current timer counter one time */

    #if (OSNTPTSKBGTS > 0U)
    if (OSTP_GETOBJTYP (OsTPBudgetObject) == OBJECT_TASK)
    {
        OsRunning->tpRemained = OSTPTimerRemained (OSTPCH_BUDGET);
        OSTPResetBudget ();
    }
    #if (OSNTPISRBGTS > 0U)
    else
    #endif
    #endif /* (OSNTPTSKBGTS > 0U) */

    #if (OSNTPISRBGTS > 0U)
    if (OSTP_GETOBJTYP (OsTPBudgetObject) == OBJECT_ISR)
    {
        OsIsrTable[OSTP_GETOBJIND (OsTPBudgetObject)].tpRemained = OSTPTimerRemained (OSTPCH_BUDGET);
        OSTPResetBudget ();
    }
    #if (OSNTPTSKBGTS > 0U)
    else
    {
        /* To satisfy Note 960: Violates MISRA 2004 Required Rule 14.10, no 'else' at end of 'if ... else if' chain */
    }
    #endif
    #endif /* (OSNTPISRBGTS > 0U) */

    #if (OSNTPTSKRESLOCKTIME > 0U)
    if (OSTP_GETOBJTYP (OsTPResLockObject) == OBJECT_TASK)
    {
        OsRunning->tpResources->tpRemained = OSTPTimerRemained (OSTPCH_RESLOCK);
        OSTPResetResLock ();
    }
    #if (OSNTPISRRESLOCKTIME > 0U)
    else
    #endif
    #endif /* (OSNTPTSKRESLOCKTIME > 0U) */
    #if (OSNTPISRRESLOCKTIME > 0U)
    if (OSTP_GETOBJTYP (OsTPResLockObject) == OBJECT_ISR)
    {
        OsIsrTable[OSTP_GETOBJIND (OsTPResLockObject)].tpResources->tpRemained = OSTPTimerRemained (OSTPCH_RESLOCK);
        OSTPResetResLock ();
    }
    #if (OSNTPTSKRESLOCKTIME > 0U)
    else
    {
        /* To satisfy Note 960: Violates MISRA 2004 Required Rule 14.10, no 'else' at end of 'if ... else if' chain */
    }
    #endif
    #endif /* (OSNTPISRRESLOCKTIME > 0U) */
}
#endif /* (OSNTPBGTS > 0U) || (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U) */

#if (OSNTPTSKARRIV > 0U)
/***************************************************************************
 * Function: OSTPStartTaskFrameInAlm
 *
 * Description: start inter-arrival control when a task is activated or released
 *
 * Returns:     
 *
 * Notes:    
 **************************************************************************/
#if defined(OSHOOKPROTECTION)
OSBYTE
OSTPStartTaskFrameInAlm (OSWORD taskId)
#else
void
OSTPStartTaskFrameInAlm (OSWORD taskId)
#endif
{
    OSTSKCBPTR task;

    task = &OsTaskTable[taskId];

    /* Inter-arrival time protection */
    if (task->tpTimeFrame > 0U)
    {
        OSSIGNEDQWORD curTime;

        OsTPTimVal = OSTPGetTimVal ();
        OSTPGetTime64 (curTime);

        if (curTime < (task->tpLast + (OSSIGNEDQWORD) task->tpTimeFrame))
        {                       /* an attempt is made to activate a task before the end of task time-frame */
            OSPUTERROR (E_OS_PROTECTION_ARRIVAL);

            #if defined(OSHOOKPROTECTION)
            if (PRO_IGNORE != OSTPProtectionHook (OSTPOBJECT0, E_OS_PROTECTION_ARRIVAL))
            #endif /* defined(OSHOOKPROTECTION) */

            {
                OSShutdownOS (E_OS_PROTECTION_ARRIVAL);
            }

            #if defined(OSHOOKPROTECTION)
            /*
             * @violates @ref Os_tp_v3_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return OSFALSE;
            #endif
        }
        task->tpLast = curTime;
    }

    #if defined(OSHOOKPROTECTION)
    return OSTRUE;
    #endif
}

#if defined(OSHOOKPROTECTION)
/***************************************************************************
 * Function: OSTPStartTaskFrame
 *
 * Description: start inter-arrival control when a task is activated or released
 *
 * Returns:     OSTRUE if Ok, or OSFALSE if it's impossible to
 *              activate/release the task.
 *
 * Notes:       it is implemented as a macro in API header if
 *              OSHOOKPROTECTION is not defined
 *
 **************************************************************************/
OSBYTE
OSTPStartTaskFrame (OSWORD taskId)
{
    OSTSKCBPTR task;
    task = &OsTaskTable[taskId];

    /* Inter-arrival time protection */
    if (task->tpTimeFrame > 0U)
    {
        OSSIGNEDQWORD curTime;

        OsTPTimVal = OSTPGetTimVal ();
        OSTPGetTime64 (curTime);

        if (curTime < (task->tpLast + (OSSIGNEDQWORD) task->tpTimeFrame))
        {                       /* an attempt is made to activate a task before the end of task timeframe */
            OSObjectType object;

            OSPUTERROR (E_OS_PROTECTION_ARRIVAL);
            #if defined(OSISRENTRYEXIT)
            if (OSISRLEVELMASKED > 0U)
            {
                OS_ISRTYPEPTR handlerPtr = OsIsrArray[OSISRLEVELMASKED - 1U];
                object = OSTPISROBJECT (handlerPtr);
            }
            else
            #endif /* defined(OSISRENTRYEXIT) */
            {
                object = OSTPTASKOBJECT (OsRunning);
            }

            if (PRO_IGNORE != OSTPProtectionHook (object, E_OS_PROTECTION_ARRIVAL))
            {
                /* OS506 */
                OSShutdownOS (E_OS_PROTECTION_ARRIVAL);
            }
            /*
             * @violates @ref Os_tp_v3_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return OSFALSE;     /* activation is ignored regardless of protection hook action [OS465] */
        }

        task->tpLast = curTime; /* [OS469, OS472] */
    }

    return OSTRUE;
}
#endif /* defined(OSHOOKPROTECTION) */
#endif /* (OSNTPTSKARRIV > 0U) */

#if (OSNTPISRARRIV > 0U)
/***************************************************************************
 * Function: OSTPISRArrivalRate
 *
 * Description: Start inter-arrival protection for ISR:
 *
 * Returns:  TRUE if no violation
 *
 * Notes: OSShutdownOS will be called if violation occurs AND
 *        Protection Hook is not configured.
 *
 **************************************************************************/
#if defined(OSHOOKPROTECTION)
OSBYTE
OSTPISRArrivalRate (OS_ISRTYPEPTR handlerPtr)
#else
void
OSTPISRArrivalRate (OS_ISRTYPEPTR handlerPtr)
#endif
{
    OsTPTimVal = OSTPGetTimVal ();

    /* Inter-arrival time protection */
    if (handlerPtr->tpTimeFrame > 0U)
    {
        OSSIGNEDQWORD curTime;

        OSTPGetTime64 (curTime);

        if (curTime < (handlerPtr->tpLast + (OSSIGNEDQWORD)handlerPtr->tpTimeFrame))
        {                       /*  cat.2 interrupt occurs before the end of ISR timeframe */
            #if defined(OSHOOKPROTECTION)
            ProtectionReturnType hookAction;
            #endif

            OSPUTERROR (E_OS_PROTECTION_ARRIVAL);
            #if defined(OSHOOKPROTECTION)
            OsIsrLevel++;       /* it's necessary for service GetISRID() may be invoked from user's ProtectionHook() */
            hookAction = OSTPProtectionHook (OSTPISROBJECT (handlerPtr), E_OS_PROTECTION_ARRIVAL);
            OsIsrLevel--;

            if (hookAction != PRO_IGNORE)       /* protection hook returned action != PRO_IGNORE */
            {
                OSShutdownOS (E_OS_PROTECTION_ARRIVAL);
            }
            /*
             * @violates @ref Os_tp_v3_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return OSFALSE;     /* user provided ISR2 will not executed regardless of protection hook action [OS048] */
            #else
            OSShutdownOS (E_OS_PROTECTION_ARRIVAL);
            #endif /* defined(OSHOOKPROTECTION) */
        }
        handlerPtr->tpLast = curTime;
    }

    #if defined(OSHOOKPROTECTION)
    return OSTRUE;
    #endif
}
#endif /* (OSNTPISRARRIV > 0U) */

#if (OSNTPTSKRESLOCKTIME > 0U)
/***************************************************************************
 * Function: OSTPStartTaskResLockTime
 *
 * Description: Start resource locking time in a task
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
void
OSTPStartTaskResLockTime (OSWORD resInd)
{
    OSWORD i;
    OsTPTimVal = OSTPGetTimVal ();

    for (i = 0U; i < OsRunning->tpNumberResLock; i++)
    {
        /*
        * @violates @ref Os_tp_v3_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        if (OsRunning->tpResLock[i].resId == resInd)
        {
            OSTPTICKTYPE locktime, remained;

            /*
            * @violates @ref Os_tp_v3_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            locktime = OsRunning->tpResLock[i].lockTime;

            if (OsRunning->tpResources) /* there is another resource with started TP locking time */
            {
                remained = OSTPTimerRemained (OSTPCH_RESLOCK);

                if (remained <= locktime)
                {
                    break;
                }
                OsRunning->tpResources->tpRemained = remained - locktime;
            }
            else
            {
                /* Nothing todo */
            }

            OSTPStartResLock (locktime, OSTPTASKOBJECT (OsRunning));

            /* Add resource to link of task resources with started TP  */
            OsResources[resInd].tpNextRes = OsRunning->tpResources;
            OsRunning->tpResources = &OsResources[resInd];
            break;
        }
    }
}

/***************************************************************************
 * Function: OSTPResetTaskResLockTime
 *
 * Description: Reset task resource locking time
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
void
OSTPResetTaskResLockTime (OSResType resRef)
{
    if (resRef == OsRunning->tpResources)
    {
        OSTPTICKTYPE remained;

        OsTPTimVal = OSTPGetTimVal ();

        remained = OSTPTimerRemained (OSTPCH_RESLOCK);

        OsRunning->tpResources = resRef->tpNextRes;

        OSTPResetResLock ();

        if (OsRunning->tpResources)
        {                       /* restore  locking time of a previos resourse for this task */
            OSTPStartResLock (OsRunning->tpResources->tpRemained + remained, OSTPTASKOBJECT (OsRunning));
        }
        else
        {
            /* Nothing todo */
        }
    }
}

#endif /* (OSNTPTSKRESLOCKTIME > 0U)  */

#if (OSNTPISRRESLOCKTIME > 0U)
/***************************************************************************
 * Function: OSTPStartISRResLockTime
 *
 * Description: Start resource locking time in a ISR
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
void
OSTPStartISRResLockTime (OSWORD resInd)
{
    OSWORD i;
    /*
    * @violates @ref Os_tp_v3_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    OS_ISRTYPEPTR handlerPtr = OsIsrArray[OSISRLEVELMASKED - 1U];

    OsTPTimVal = OSTPGetTimVal ();

    for (i = 0U; i < handlerPtr->tpNumberResLock; i++)
    {
        /*
        * @violates @ref Os_tp_v3_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        if (handlerPtr->tpResLock[i].resId == resInd)
        {
            OSTPTICKTYPE locktime, remained;

            /*
            * @violates @ref Os_tp_v3_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            locktime = handlerPtr->tpResLock[i].lockTime;

            if (handlerPtr->tpResources)       /* there is another resouce with started TP locking time */
            {
                remained = OSTPTimerRemained (OSTPCH_RESLOCK);

                if (remained <= locktime)
                {
                    break;
                }
                handlerPtr->tpResources->tpRemained = remained - locktime;
            }
            else
            {
                /* Nothing todo */
            }

            /*
            * @violates @ref Os_tp_v3_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            OSTPStartResLock (locktime, OSTPISROBJECT (handlerPtr));

            /* Add resource to link of ISR2 resources with started TP  */
            OsResources[resInd].tpNextRes = handlerPtr->tpResources;
            handlerPtr->tpResources = &OsResources[resInd];
            break;
        }
    }
}

/***************************************************************************
 * Function: OSTPResetISRResLockTime
 *
 * Description: Reset ISR resource locking time
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
void
OSTPResetISRResLockTime (OSResType resRef)
{
    /*
    * @violates @ref Os_tp_v3_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    OS_ISRTYPEPTR handlerPtr = OsIsrArray[OSISRLEVELMASKED - 1U];

    if (resRef == handlerPtr->tpResources)
    {
        OSTPTICKTYPE remained;

        OsTPTimVal = OSTPGetTimVal ();

        remained = OSTPTimerRemained (OSTPCH_RESLOCK);

        handlerPtr->tpResources = resRef->tpNextRes;

        OSTPResetResLock ();

        if (handlerPtr->tpResources)
        {                       /* restore locking time of a previos resourse for this task */
            /*
            * @violates @ref Os_tp_v3_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            OSTPStartResLock (handlerPtr->tpResources->tpRemained + remained, OSTPISROBJECT (handlerPtr));
        }
        else
        {
            /* Nothing todo */
        }
    }
}

#endif /* (OSNTPISRRESLOCKTIME > 0U)  */


#if (OSNTPTSKBGTS > 0U) || (OSNTPTSKRESLOCKTIME > 0U)
/***************************************************************************
 * Function: OSTPResumeTaskBudget
 *
 * Description: Resume timing protection execution budget and resource
 *              locking time when a task is started after preempting
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
void
OSTPResumeTaskBudget (void)
{

    OsTPTimVal = OSTPGetTimVal ();

    #if (OSNTPTSKRESLOCKTIME > 0U)
    if (OsRunning->tpResources) /* there is a resource with started TP */
    {
        OSTPStartResLock (OsRunning->tpResources->tpRemained, OSTPTASKOBJECT (OsRunning));
    }
    #endif /* (OSNTPTSKRESLOCKTIME > 0U) */


    #if (OSNTPTSKBGTS > 0U)
    if (OsRunning->tpExecBudget > 0U)    /* TP budget is applied for this task */
    {
        OSTPStartBudget (OsRunning->tpRemained, OSTPTASKOBJECT (OsRunning));
    }
    #endif
}
#endif /* (OSNTPTSKBGTS > 0U) || (OSNTPTSKRESLOCKTIME > 0U) */

#define OSTEXT_STOP_SEC_CODE
/*
* @violates @ref Os_tp_v3_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#endif /* defined(OSTIMINGPROTECTION) */



#ifdef __cplusplus
}
#endif



/** @} */
