/**
*   @file    Os_tp_internal_api_v3.h
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

#ifndef OS_TP_INTERNAL_API_V3_H
#define OS_TP_INTERNAL_API_V3_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <Os_tp_internal_types.h>       /* for OSTPRESLOCK */
#include <Os_isr_internal_api.h>

#include <Os_hook_internal_api.h>

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSTIMINGPROTECTION)


/* TP control blocks of resource locking time for tasks */
#if (OSNTPTSKRESLOCKTIME > 0U)
        extern OSTPRESLOCK OsTPTskResLockTime[OSNTPTSKRESLOCKS];
#endif /* (OSNTPTSKRESLOCKTIME > 0U) */

         /* TP control blocks of resource locking time for ISR2s */
#if (OSNTPISRRESLOCKTIME > 0U)
        extern OSTPRESLOCK OsTPISRResLockTime[OSNTPISRRESLOCKS];
#endif /* (OSNTPISRRESLOCKTIME > 0U) */

#endif /* defined(OSTIMINGPROTECTION) */

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSTIMINGPROTECTION)

/* Note. In some cases TP uses forced software interrupt invoked with MSR(EE)=0.
   But when MSR(EE) will be 1 a low priority interrupt may occurr before
   TP interrupt because of known INTC "feature". As a result TP handler
   cannot use OSISRLEVELMASKED to define current TP violator.
   So special TP object variables are introduced. 
*/

#if (OSNTPBGTS > 0U)
OSDECLAREVAR (extern OSNEAR OSObjectType, OsTPBudgetObject_);   /* TP object (TASK or ISR2) with current budget */
#define OsTPBudgetObject OSUSEVAR(OsTPBudgetObject_)
#endif

#if (OSNTPTSKINTLOCKTIME > 0U) || (OSNTPISRINTLOCKTIME > 0U)
OSDECLAREVAR (extern OSNEAR OSObjectType, OsTPIntLockObject_);  /* TP object (TASK or ISR2) with current interrupt locking time */
#define OsTPIntLockObject OSUSEVAR(OsTPIntLockObject_)
#endif

#if (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U)
OSDECLAREVAR (extern OSNEAR OSObjectType, OsTPResLockObject_);  /* TP object (TASK or ISR2) with current resource locking time */
#define OsTPResLockObject OSUSEVAR(OsTPResLockObject_)
#endif

OSDECLAREVAR (extern OSNEAR OSBYTE, OsTPForceReason_);  /* reason of TP forced interrupt */

#define OsTPForceReason OSUSEVAR(OsTPForceReason_)
OSDECLAREVAR (extern OSNEAR OSTPTICKTYPE, OsTPTimVal_); /* current STM count value */
#define OsTPTimVal OSUSEVAR(OsTPTimVal_)

#if (OSNTPISRARRIV > 0U) || (OSNTPTSKARRIV > 0U)
OSDECLAREVAR (extern OSNEAR OSDWORD, OsTPOverflowCnt_); /* TP overflow counter */
#define OsTPOverflowCnt OSUSEVAR(OsTPOverflowCnt_)
#endif


#endif /* defined(OSTIMINGPROTECTION) */

#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"


#if defined(OSTIMINGPROTECTION)
    #if (OSNTPTSKBGTS > 0U) && (OSNXTSKS > 0U)
        #define OSTPWAITEVT         ( (OSBYTE)0x20 )    /* Task is inside WaitEvent function    */
        #define OSTPSetWAITEVT()    ( OsRunning->status |= OSTPWAITEVT )
        #define OSTPClrWAITEVT()    ( OsRunning->status &= ~OSTPWAITEVT )
    #else
        #define OSTPSetWAITEVT()
        #define OSTPClrWAITEVT()
    #endif /* (OSNTPTSKBGTS > 0U) && (OSNXTSKS > 0U)  */
#else
    #define OSTPSetWAITEVT()
    #define OSTPClrWAITEVT()
#endif /* defined(OSTIMINGPROTECTION) */

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#if defined (OSTIMINGPROTECTION)

#include <Os_timer_internal_api.h>

#if defined(OSTIMSTM) || defined(OSTIM2STM)
#error  Error of the OS Configuration: the STM timer should be used only for TP in SC2/4
#endif

/* TP force interrupt  redirected to INTC software interrupt source */
#define OSTPSOFTINT      5u
#define OSTPSOFTINVOKE   ((OSDWORD)0x20000)
#define OSTPSOFTCLEAR    ((OSDWORD)0x10000)



/*  Assignment of STM channels. */

#define OSTPCH_OVF        0u    /* channel for overflow counter (OVF) */
#define OSTPCH_INTLOCK    1u    /* channel for Interrupt locking time */
#define OSTPCH_BUDGET     2u    /* channel for Task/ISR budget        */
#define OSTPCH_RESLOCK    3u    /* channel for Resource locking time  */




/* Return low part of TP time */
#define OSTPGetTimVal() ( OSSTM_CNT )

#define OSTPTimerClearFlag(ch)  (OSSTM_CIR(ch) = OSSTMFLBIT)    /* clear flag for the STM channel */
#define OSTPTimerEnable(ch)     (OSSTM_CCR(ch) = OSSTMCENBIT)   /* enable interrupt from the STM channel */

/* Disable STM channel */
#define OSTPTimerDisable(ch)                  \
    OSSTM_CCR(ch) = 0U;                       \
    OSTPTimerClearFlag(ch)

/* Arm STM channel */
#define OSTPTimerArm(ticks,ch)                \
    OSSTM_CMP(ch)=(ticks);                    \
    OSTPTimerClearFlag(ch);                   \
    OSTPTimerEnable(ch)

/* Check the STM channel interrupt request */
#define OSTPTimerInterruptRaised(ch) ((OSSTM_CIR(ch) & OSSTMFLBIT) != 0U)

#define OSTPTimerForceClearFlag()   (OSINTC_SSCIR4_7 = OSTPSOFTCLEAR)
#define OSTPTimerInterruptForce(r)        \
    OsTPForceReason |= (r);               \
    (OSINTC_SSCIR4_7 = OSTPSOFTINVOKE)
 
/* Forced TP interrupt */

/* Reason of TP forced interrupt */
#define OSTPFORCEBUDGET      ((OSBYTE)0x01)
#define OSTPFORCEINTLOCK     ((OSBYTE)0x02)
#define OSTPFORCERESLOCK     ((OSBYTE)0x04)
#define OSTPFORCETSKARRIVAL  ((OSBYTE)0x10)
#define OSTPFORCEISRARRIVAL  ((OSBYTE)0x20)
#if (OSNTRUSTEDFUNCTIONS > 0U)
/* Bit to indicate postopened reaction on TP violation occured inside of trusted function */
#define OSTPFORCEPOSTPONED  ((OSBYTE)0x80)
#endif


/* STM freeze mode */
#if defined(OSTPTIMFREEZE)
#define OSTPTIMFRZBIT  OSSTMFREEZEBIT
#else
#define OSTPTIMFRZBIT  0x00U
#endif

/* STM control register bits */
#if defined(OSTPTIMPRESCALER)
#define OSTPSTMCR  ((OSTPTIMPRESCALER << 8) | OSTPTIMFRZBIT | OSSTMCENBIT)
#else
#define OSTPSTMCR  (OSTPTIMFRZBIT | OSSTMCENBIT)
#endif

/* STM initialization */
#define OSTPTimerInit()                         \
    OSTPTimerShutdown();                        \
    OSSTM_CR = OSTPSTMCR;                       \
    OSTPStartOVFCh()



#if (OSNTPISRARRIV > 0U) || (OSNTPTSKARRIV > 0U)  /* there is inter-arrival time protection */
#define OSTPStartOVFCh() OSTPTimerArm(0U,OSTPCH_OVF)
#else
#define OSTPStartOVFCh()
#endif /* (OSNTPISRARRIV > 0U) || (OSNTPTSKARRIV > 0U) */





/* STM shutdown */
#define OSTPTimerShutdown()                                          \
    OSSTM_CR = 0U;                                                   \
    OSSTM_CNT = 1U; /* to prevent OVF interrupt directly after StartOS() */ \
    OSSTM_CCR(0) = 0U;                                                  \
    OSSTM_CCR(1) = 0U;                                                  \
    OSSTM_CCR(2) = 0U;                                                  \
    OSSTM_CCR(3) = 0U;                                                  \
    OSSTM_CIR(0) = OSSTMFLBIT;                                          \
    OSSTM_CIR(1) = OSSTMFLBIT;                                          \
    OSSTM_CIR(2) = OSSTMFLBIT;                                          \
    OSSTM_CIR(3) = OSSTMFLBIT;                                          \
    OSTPTimerForceClearFlag()

/* Nils */
#define OSTPOBJECT0     ((OSObjectType)0)
#define OSTPRESLOCK0    ((OSTPRESLOCK *)0)
#define OSTPLOCK0       OSTPRESLOCK0


/* --- TP interface macros and functions --- */

#if (OSNAPPMODES > 1U)
extern void OSInitializeTP (AppModeType mode);
#else
extern void OSInitializeTP (void);
#endif

/***************************************************************************
 * Fuction: OSTPTimerRemained
 *
 * Description:  return the remained time until the compare event
 *
 * Notes:       OsTPTimVal shall be updated before 
 *
 **************************************************************************/
OSINLINE OSTPTICKTYPE
OSTPTimerRemained (OSWORD ch)
{
    register OSTPTICKTYPE value;

    value = OSSTM_CMP (ch) - OsTPTimVal;

    if (((OSSTM_CIR (ch)) & OSSTMFLBIT) != 0U)
    {
        value = 0U;
    }

    return value;
}

/***************************************************************************
 * Macro: OSTPGetTime64
 *
 * Description:  return full TP time (in 'timval64' variable)
 *
 * Notes:   1. the same macro interface as for DEC timer
 *          2. OsTPTimVal shall be updated before 
 *
 **************************************************************************/
#define OSTPGetTime64(timval64)                             \
{                                                           \
    register OSDWORD up;                                    \
                                                            \
    up = OsTPOverflowCnt;                                   \
                                                            \
    if( ((OSSTM_CIR(OSTPCH_OVF)) & OSSTMFLBIT) != 0U )       \
    {                                                       \
        OsTPTimVal = OSSTM_CNT;                             \
        up++;                                               \
    }                                                       \
                                                            \
    (timval64) = (OSSIGNEDQWORD)(( (OSQWORD)up << 32u ) + OsTPTimVal);       \
}

#define OSTPGetRemained()     OSTPTimerRemained(OSTPCH_BUDGET)          /**< get the remained time on the budget */
#define OSTPResLockRemained() OSTPTimerRemained(OSTPCH_RESLOCK)         /**< get the remained time on the resource locking time */


#define OSTPTASKOBJECT(task)    OSTP_MKOBJID(OBJECT_TASK, (task)->taskId)
#define OSTPISROBJECT(isr)      OSTP_MKOBJID(OBJECT_ISR, ((isr) - &OsIsrTable[0]))

#if (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U)

/* Start interrupt locking time */
#define OSTPStartResLock(val, obj)                                      \
    OSTPTimerArm((val) + OsTPTimVal, OSTPCH_RESLOCK);                   \
    if( ( OSSTM_CNT - OsTPTimVal ) >= ( OSSTM_CMP(OSTPCH_RESLOCK) - (OsTPTimVal) ) ) \
    {                                                                   \
        OSTPTimerDisable(OSTPCH_RESLOCK);                               \
        OSTPTimerInterruptForce(OSTPFORCERESLOCK);                      \
    }                                                                   \
    OsTPResLockObject = (obj)

/* Reset interrupt locking time */
#define OSTPResetResLock()                      \
    OSTPTimerDisable(OSTPCH_RESLOCK);           \
    OsTPResLockObject = OSTPOBJECT0
  
#endif /* (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U) */

#if (OSNTPBGTS > 0U)

/* Reset timing protection execution budget */
#define OSTPResetBudget()                       \
    OSTPTimerDisable(OSTPCH_BUDGET);            \
    OsTPBudgetObject = OSTPOBJECT0

/* Start timing protection execution budget */
#define OSTPStartBudget(val, obj)                                       \
    OSTPTimerArm((val) + OsTPTimVal, OSTPCH_BUDGET);                    \
    if( ( OSSTM_CNT - OsTPTimVal ) >= ( OSSTM_CMP(OSTPCH_BUDGET) - (OsTPTimVal) ) ) \
    {                                                                   \
        OSTPTimerDisable(OSTPCH_BUDGET);                                \
        OSTPTimerInterruptForce(OSTPFORCEBUDGET);                       \
    }                                                                   \
    OsTPBudgetObject = (obj)

#endif /* (OSNTPBGTS > 0U) */

#if (OSNTPBGTS > 0U) || (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U)
extern void OSTPStopBudget (void);
#else
#define OSTPStopBudget()
#endif

#if (OSNTPTSKARRIV > 0U)
    #if defined(OSHOOKPROTECTION)
        extern OSBYTE OSTPStartTaskFrame (OSWORD taskId);
        extern OSBYTE OSTPStartTaskFrameInAlm (OSWORD taskId);
    #else
        extern void OSTPStartTaskFrameInAlm (OSWORD taskId);
        #define OSTPStartTaskFrame(taskId) OSTPStartTaskFrameInAlm( taskId )
    #endif
#else /* (OSNTPTSKARRIV > 0U) */
    #define OSTPStartTaskFrame( arg )
    #define OSTPStartTaskFrameInAlm( arg )
#endif /* (OSNTPTSKARRIV > 0U) */


#if (OSNTPTSKBGTS > 0U) || (OSNTPTSKRESLOCKTIME > 0U)

extern void OSTPResumeTaskBudget (void);

/***************************************************************************
 * Function: OSTPStopTaskBudget
 *
 * Description: Stop task timing protection (the budget and/or the resource 
 *              locking time) when a task is preempted
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
OSINLINE void
OSTPStopTaskBudget (void)
{
    #if (OSNTPTSKBGTS > 0U) && (OSNXTSKS > 0U)
        if ((OsRunning->status & OSTPWAITEVT) != OSTPWAITEVT)
    {
    #endif

        OsTPTimVal = OSTPGetTimVal ();

        #if (OSNTPTSKRESLOCKTIME > 0U)
        if (OsRunning->tpResources)     /* there is a resource with started TP */
        {
            OsRunning->tpResources->tpRemained = OSTPTimerRemained (OSTPCH_RESLOCK);
            OSTPResetResLock ();
        }
        #endif /* (OSNTPTSKRESLOCKTIME > 0U) */

        #if (OSNTPTSKBGTS > 0U)
        if (OsRunning->tpExecBudget > 0U)        /* TP budget is applied for this task */
        {
            OsRunning->tpRemained = OSTPTimerRemained (OSTPCH_BUDGET);
            OSTPResetBudget ();
        }
        #endif

    #if (OSNTPTSKBGTS > 0U) && (OSNXTSKS > 0U)
    }
    else                        /* the task goes in wait state */
    {
        OsRunning->tpRemained = OsRunning->tpExecBudget;        /* reset task budget */
        OSTPResetBudget ();
        /* Note that the queue tpResource must be empty here
           because of all resources shall be released before WaitEvent() */
    }
    #endif
}


#if (OSNXTSKS > 0U) && (OSNTPTSKBGTS > 0U)
/***************************************************************************
 * Function: OSTPRestartTaskBudget
 *
 * Description: Restart task budget for extended tasks 
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
OSINLINE void
OSTPRestartTaskBudget (void)
{
    if (OsRunning->tpExecBudget > 0U)        /* TP budget is applied for this task */
    {
        OsTPTimVal = OSTPGetTimVal ();
        OsRunning->tpRemained = OsRunning->tpExecBudget;
        OSTPStartBudget (OsRunning->tpRemained, OSTPTASKOBJECT (OsRunning));
    }
}
#else
#define OSTPRestartTaskBudget()
#endif /* (OSNXTSKS > 0U) && (OSNTPTSKBGTS > 0U) */

/***************************************************************************
 * Function: OSTPResetTaskBudget
 *
 * Description: Reset task timing protection (the budget and/or the resource 
 *              locking time)
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
OSINLINE void
OSTPResetTaskBudget (void)
{

    #if (OSNTPTSKBGTS > 0U)
    OSTPResetBudget ();
    OsRunning->tpRemained = OsRunning->tpExecBudget;
    #endif

    #if (OSNTPTSKRESLOCKTIME > 0U)
    OSTPResetResLock ();
    OsRunning->tpResources = OSNULLRES;
    #endif
}

/***************************************************************************
 * Function: OSTPResetReadyTask
 *
 * Description: Reset task timing protection (the budget and/or the
 *              resource locking time) for task in ready state (not running)
 *              
 * Returns: 
 *
 * Notes:       It used to reset TP fields for the task when the task is not
 *              running and the task is killed
 *
 **************************************************************************/
OSINLINE void
OSTPResetReadyTask (OSTSKCBPTR task)
{
    #if (OSNTPTSKBGTS > 0U)
    task->tpRemained = task->tpExecBudget;      /* reset task budget */
    #endif

    #if  (OSNTPTSKRESLOCKTIME > 0U)
    task->tpResources = OSNULLRES;      /* reset TP resource lock' queue */
    #endif
}

#if defined(OSHOOKPOSTTASK) && defined(OSISRENTRYEXIT)
/***************************************************************************
 * Function: OSTPPostTaskHook
 *
 * Description: Set task budget for PostTaskHook() called OSLeaveISR.
 *
 * Returns: 
 *
 * Notes:  Must be used with disabled ISR2 and TP timer interrupts
 *
 **************************************************************************/
OSINLINE void
OSTPPostTaskHook (void)
{
    #if (OSNTPTSKRESLOCKTIME > 0U)
    OSTPTICKTYPE resRemained = 0U;
    #endif
    #if (OSNTPTSKBGTS > 0U)
    OSTPTICKTYPE bgtRemained = 0U;
    #endif

    OsTPTimVal = OSTPGetTimVal ();

    #if (OSNTPTSKRESLOCKTIME > 0U)
    if (OsRunning->tpResources) /* there is a resource with started TP */
    {
        resRemained = OsRunning->tpResources->tpRemained;
        OSTPStartResLock (resRemained, OSTPTASKOBJECT (OsRunning));
    }
    #endif /* (OSNTPTSKRESLOCKTIME > 0U) */
    #if (OSNTPTSKBGTS > 0U)
    if (OsRunning->tpExecBudget > 0U)    /* TP budget is applied for this task */
    {
        bgtRemained = OsRunning->tpRemained;
        OSTPStartBudget (bgtRemained, OSTPTASKOBJECT (OsRunning));
    }
    #endif

    OSPostTaskHook ();          /* call user hook */

    OsTPTimVal = OSTPGetTimVal ();

    #if (OSNTPTSKRESLOCKTIME > 0U)
    if (resRemained > 0U)        /* resource budget was started */
    {
        OsRunning->tpResources->tpRemained = OSTPTimerRemained (OSTPCH_RESLOCK);
        OSTPResetResLock ();
    }
    #endif /* (OSNTPTSKRESLOCKTIME > 0U) */
    #if (OSNTPTSKBGTS > 0U)
    if (bgtRemained > 0U)        /* task budget was started */
    {
        OsRunning->tpRemained = OSTPTimerRemained (OSTPCH_BUDGET);
        OSTPResetBudget ();
    }
    #endif
}
#else
#define OSTPPostTaskHook()
#endif /* defined(OSHOOKPOSTTASK) && defined(OSISRENTRYEXIT) */

#else
#define OSTPResetReadyTask(arg)
#define OSTPStopTaskBudget()
#define OSTPResumeTaskBudget()
#define OSTPResetTaskBudget()
#define OSTPRestartTaskBudget()
#define OSTPPostTaskHook()  OSPostTaskHook()

#endif /* (OSNTPTSKBGTS > 0U) || (OSNTPTSKRESLOCKTIME > 0U) */

#if (OSNTPISRARRIV > 0U)
#if defined(OSHOOKPROTECTION)
extern OSBYTE OSTPISRArrivalRate (OS_ISRTYPEPTR isr);
#else
extern void OSTPISRArrivalRate (OS_ISRTYPEPTR isr);
#endif
#else
#define OSTPISRArrivalRate( arg )
#endif /* (OSNTPISRARRIV > 0U) */

#if ((OSNTPBGTS > 0U) || (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U) ) && !defined(OSNOISR2)
/***************************************************************************
 * Function: OSTPStartISRBudget
 *
 * Description: Start timing protection for ISR:
 *             - the execution budget
 *             - resource locking time
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
OSINLINE void
OSTPStartISRBudget (OS_ISRTYPEPTR isr)
{
    #if defined(OSCWPPC)
    #pragma unused( isr ) /* to suppress warning about unused variable */
    #endif


    OSTPStopBudget ();    /* stop TP for preempted task or ISR2 */

    #if (OSNTPISRBGTS > 0U)
    if (isr->tpExecBudget > 0U)    /* TP budget is applied for this ISR2 */
    {
        OsTPTimVal = OSTPGetTimVal ();
        OSTPStartBudget (isr->tpExecBudget, OSTPISROBJECT (isr));
    }
    #endif

    #if (OSNTPISRRESLOCKTIME > 0U)
    isr->tpResources = OSNULLRES;
    #endif
}
#else
#define OSTPStartISRBudget( arg )
#endif /* ((OSNTPBGTS > 0U) || (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U) ) && !defined(OSNOISR2) */


#if (OSNTPISRBGTS > 0U) || (OSNTPISRRESLOCKTIME > 0U)
/***************************************************************************
 * Function: OSTPResetISRBudget
 *
 * Description: Reset the ISR2 budget
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
OSINLINE void
OSTPResetISRBudget (void)
{


    #if (OSNTPISRBGTS > 0U)
    OSTPResetBudget ();
    #endif

    #if (OSNTPISRRESLOCKTIME > 0U)
    OSTPResetResLock ();
    #endif
}

#define OSTPKillISRBudget()  OSTPResetISRBudget()

/***************************************************************************
 * Function: OSTPResumeISRBudget
 *
 * Description: Resume the ISR2 budget and/or the resource locking time
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
OSINLINE void
OSTPResumeISRBudget (OS_ISRTYPEPTR isr)
{
    OsTPTimVal = OSTPGetTimVal ();

    #if (OSNTPISRRESLOCKTIME > 0U)
    if (isr->tpResources)       /* there is a resource with started TP */
    {
        OSTPStartResLock (isr->tpResources->tpRemained, OSTPISROBJECT (isr));
    }
    #endif /* (OSNTPISRRESLOCKTIME > 0U) */

    #if (OSNTPISRBGTS > 0U)
    if (isr->tpExecBudget > 0U)  /* TP budget is applied for this ISR2 */
    {
        OSTPStartBudget (isr->tpRemained, OSTPISROBJECT (isr));
    }
    #endif
}
#else

#define OSTPResumeISRBudget( arg )
#define OSTPResetISRBudget()
#define OSTPKillISRBudget()

#endif /* (OSNTPISRBGTS > 0U) || (OSNTPISRRESLOCKTIME >0) */


#if (OSNTPTSKINTLOCKTIME > 0U) || (OSNTPISRINTLOCKTIME > 0U)

/* Start interrupt locking time */
#define OSTPStartIntLock(val, obj)                                      \
    OSTPTimerArm((val) + OsTPTimVal, OSTPCH_INTLOCK);                   \
    if( ( OSSTM_CNT - OsTPTimVal ) >= ( OSSTM_CMP(OSTPCH_INTLOCK) - (OsTPTimVal) ) ) \
    {                                                                   \
        OSTPTimerDisable(OSTPCH_INTLOCK);                               \
        OSTPTimerInterruptForce(OSTPFORCEINTLOCK);                      \
    }                                                                   \
    OsTPIntLockObject = (obj)

#if (OSNTPTSKINTLOCKTIME > 0U)
extern void OSTPStartTaskIntLockTime (OSTPTICKTYPE locktime);
#endif
#if (OSNTPISRINTLOCKTIME > 0U)
extern void OSTPStartISRIntLockTime (OS_ISRTYPEPTR isr, OSTPTICKTYPE locktime);
#endif


/***************************************************************************
 * Function: OSTPStartIntLockTime
 *
 * Description: Start timing protection for OS interrupt locking time
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
OSINLINE void
OSTPStartIntLockTime (void)
{
    OSTPTICKTYPE locktime;
    OsTPTimVal = OSTPGetTimVal ();

    if (OSISRLEVELMASKED == 0U)
    {
        #if (OSNTPTSKINTLOCKTIME > 0U)
        locktime = OsRunning->tpIntLockTime;
        if (locktime > 0U)
        {
            OSTPStartIntLock (locktime, OSTPTASKOBJECT (OsRunning));
        }
        #endif /* (OSNTPTSKINTLOCKTIME > 0U) */
    }
    else
    {
        #if (OSNTPISRINTLOCKTIME > 0U)

        OS_ISRTYPEPTR isr = OsIsrArray[OSISRLEVELMASKED - 1U];
        locktime = isr->tpIntLockTime;
        if (locktime > 0U)
        {
            OSTPStartIntLock (locktime, OSTPISROBJECT (isr));
        }
        #endif /* (OSNTPISRINTLOCKTIME > 0U) */
    }
}

/***************************************************************************
 * Macro: OSTPKillIntLockTime
 *
 * Description: Reset timing protection for OS interrupt lock time
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
#define OSTPKillIntLockTime()                   \
    OSTPTimerDisable(OSTPCH_INTLOCK);           \
    OsTPIntLockObject = OSTPOBJECT0

/***************************************************************************
 * Macro: OSTPStopIntLockTime
 *
 * Description: Stop timing protection for OS interrupt locking time
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
#define OSTPStopIntLockTime() OSTPKillIntLockTime()

#else

#define OSTPStartIntLockTime()
#define OSTPStopIntLockTime()
#define OSTPKillIntLockTime()

#endif
       /* (OSNTPTSKINTLOCKTIME > 0U) || (OSNTPISRINTLOCKTIME > 0U) */

#if (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U)

#if (OSNTPTSKRESLOCKTIME > 0U)
extern void OSTPStartTaskResLockTime (OSWORD resInd);
extern void OSTPResetTaskResLockTime (OSResType resRef);
#endif
#if (OSNTPISRRESLOCKTIME > 0U)
extern void OSTPStartISRResLockTime (OSWORD resInd);
extern void OSTPResetISRResLockTime (OSResType resRef);
#endif

/***************************************************************************
 * Function: OSTPStartResLockTime
 *
 * Description: Start resource locking time in a task or ISR2
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
OSINLINE void
OSTPStartResLockTime (OSWORD resInd)
{
    
    #if defined(OSISRENTRYEXIT)
    if (OSISRLEVELMASKED == 0U)
    {
    #endif
        #if (OSNTPTSKRESLOCKTIME > 0U)
        OSTPStartTaskResLockTime (resInd);
        #endif
    #if defined(OSISRENTRYEXIT)
    }
    else
    {
        #if (OSNTPISRRESLOCKTIME > 0U)
        OSTPStartISRResLockTime (resInd);
        #endif
    }
    #endif
}

/***************************************************************************
 * Function: OSTPResetResLockTime
 *
 * Description: Reset resource locking time in a task or ISR2
 *
 * Returns: 
 *
 * Notes:
 *
 **************************************************************************/
OSINLINE void
OSTPResetResLockTime (OSResType resRef)
{
    #if defined(OSISRENTRYEXIT)
    if (OSISRLEVELMASKED == 0U)
    {
    #endif

        #if (OSNTPTSKRESLOCKTIME > 0U)
        OSTPResetTaskResLockTime (resRef);
        #endif

    #if defined(OSISRENTRYEXIT)
    }
    else
    {
        #if (OSNTPISRRESLOCKTIME > 0U)
        OSTPResetISRResLockTime (resRef);
        #endif
    }
    #endif
}
#else
#define OSTPStartResLockTime( arg )
#define OSTPResetResLockTime( arg )
#endif /* (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U) */

#else /* defined (OSTIMINGPROTECTION) */

/*
 * Empty TP interface macros in the case timing protection is not enabled
 */
#define OSTPStartTaskFrame( arg )
#define OSTPStartTaskFrameInAlm( arg )
#define OSTPResetReadyTask(arg)
#define OSTPResumeTaskBudget()
#define OSTPResetTaskBudget()
#define OSTPStopTaskBudget()
#define OSTPRestartTaskBudget()
#define OSTPStartISRBudget( arg )
#define OSTPResetISRBudget()
#define OSTPKillISRBudget()
#define OSTPResumeISRBudget( arg )
#define OSTPStopBudget()
#define OSTPStartIntLockTime()
#define OSTPStopIntLockTime()
#define OSTPKillIntLockTime()
#define OSTPStartResLockTime( arg )
#define OSTPResetResLockTime( arg )
#define OSTPISRArrivalRate( arg )
#define OSTPPostTaskHook()  OSPostTaskHook()

#define OSTPGETCOREID OSGETCOREID

#endif /* defined (OSTIMINGPROTECTION) */


#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /*OS_TP_INTERNAL_API_V3_H */

/** @} */
