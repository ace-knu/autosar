/**
*   @file    Os_counter.c
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
* @section Os_counter_c_REF_5_1_1
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters. 
* The section identification define's naming convention is defined by AutoSar and identifiers are longer than 31 character. 
* Compilers are checked for support this length of identifiers.
*
* @section Os_counter_c_REF_14_4_1
* Violates MISRA 2004 Required Rule 14.4, Use of goto is deprecated
* The goto statement shall not be used.
* The goto statement is used to implement of overrun protection algorithm (for HW counters).
*
* @section Os_counter_c_REF_14_7_1
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function 
* A function shall have a sigle point of exit at the end of finction.
* The returned statement is result of error hanling.
*
* @section Os_counter_c_REF_19_1_1
* Violates MISRA 2004 Advisory Rule 19.1, declaration before #include
* #include statements in a file should only be preceded by other preprocessor directives or comments. 
* MemMap is required by AutoSAR to be included in the middle of the source file(s).
*
* @section Os_counter_c_REF_19_4_1
* Violates MISRA 2004 Required Rule 19.4, Expression-like macro not parenthesized
* The macro cannot be parenthesized because of assembler limitation, in all instances of
* this macro usage the macro is in brackets.
*
* @section Os_counter_c_REF_19_7_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* A function should be used in preference to a funcion-ike macro.
* Function like macros are used to reduce code complexity and for performance reasons.
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

#include <Os_counter_api.h>
#include <Os_counter_types.h>
#include <Os_counter_internal_api.h>
#include <Os_counter_internal_types.h>
#include <Os_counter_config.h>

/*
* @violates @ref Os_counter_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSCOUNTER)
#if defined(OSALMINCCOUNTER)
OSDECLAREVAR (OSNEAR OSDWORD, OsCtrIncCounter_);
#endif /* defined(OSALMINCCOUNTER) */
#endif /* defined(OSCOUNTER) */


/*
* @violates @ref Os_counter_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_counter_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#define OS_START_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_counter_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if defined(OSCOUNTER)
/*  Global OS variables */
OSCTRCB OsCounters[OSNCTRS];    /* Counters table */

#if defined(OSALMINCCOUNTER)
/*
 * the counter increment value inspired by
 * corresponding alarm action
 * (only for SW counters)
 */
OSWORD OsCtrIncValue[OSNCTRS - OSNHWCTRS];
#endif /* defined(OSALMINCCOUNTER) */

#endif /* defined(OSCOUNTER) */

#define OS_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_counter_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#define OSTEXT_START_SEC_CODE
/*
* @violates @ref Os_counter_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if defined(OSCOUNTER)
/*  Private OS Services */

#if !defined(OSCALCULATEOBJIND)
#define ctrInd (ctrId)
#endif

#if defined(OSALMINCCOUNTER)
static void OSAlmCounterTrigger (OSWORD ctrInd);
#endif


/******************************************************************************
 * Function:    OSInitCounters
 *
 * Description: initializes counters
 *
 * Returns:     none
 *
 ******************************************************************************/
void
OSInitCounters (void)
{
    OSCARDINAL i;


    for (i = 0U; i < OSNCTRS; i++)
    {

        #if defined(OSAPPLICATION)
        OsCounters[i].appMask = OsCountersCfg[i].appMask;       /* copy application identification mask value */
        OsCounters[i].appId = OsCountersCfg[i].appId;   /* copy application identification value */
        #endif

        #if (OSNALMS > 0U)
        /*  Configuration Data  */
        OsCounters[i].alarm = OSALM0;   /* pointer to assigned running alarms  */
        #endif

        OsCounters[i].value = 0U;

        #if defined(OSALMINCCOUNTER)
        #if (OSNHWCTRS > 0U)
        if (i >= OSNHWCTRS)
        #endif
        {
            OsCtrIncValue[i - OSNHWCTRS] = 0U;
        }
        #endif
    }

    #if defined(OSALMINCCOUNTER)
    OsCtrIncCounter = 0U;
    #endif
}

#if defined(OSHWCOUNTER)
/***************************************************************************
 * Function :   OSSysTimerCancel
 *
 * Description: disable interrupts from output compare channel
 *
 * Returns: 
 *
 * Notes:       for HW counters only
 *
 **************************************************************************/
#if (OSNHWCTRS == 1U)
void
OSSysTimerCancel (void)
{
#elif (OSNHWCTRS > 1U)
void
OSSysTimerCancel (OSWORD ctrId)
{
    #if defined(OSCWPPC)
    #pragma unused( ctrId ) /* to suppress warning about unused variable */
    #endif
#endif /* (OSNHWCTRS > 1U) */

    {
        #if (OSNSYSHWCTRS > 0U)
        #if (OSNSYSHWCTRS == 2U)
        if (ctrId == OSTIMER1) /* (CORE0)SysTimer ID */
        {
        #endif
            OSSysTimDisableInt ();      /* disable output compare interrupt     */
            OSSysTimClearFlag ();       /* clear output compare interrupt flag  */
        #if (OSNSYSHWCTRS == 2U)
        }
        else                    /* SecondTimer ID */
        {                       /* this is for Second Timer */
            OSSecondDisableInt ();      /* disable output compare interrupt     */
            OSSecondClearFlag ();       /* clear output compare interrupt flag  */
        }
        #endif
        #endif /* (OSNSYSHWCTRS > 0U) */
    }
}

/***************************************************************************
 * Function :   OSSysTimerArm
 *
 * Description: set interruption point and enable interrupts
 *
 * Returns: 
 *
 * Notes:       for HW counters only
 *
 **************************************************************************/
#if (OSNHWCTRS == 1U)
void
OSSysTimerArm (OSHWTickType ticks)
{
#elif (OSNHWCTRS > 1U)
void
OSSysTimerArm (OSWORD ctrId, OSHWTickType ticks)
{
    #if defined(OSCWPPC)
    #pragma unused( ctrId ) /* to suppress warning about unused variable */
    #endif
#endif /* (OSNHWCTRS > 1U) */

    {
        #if (OSNSYSHWCTRS > 0U)
        #if (OSNSYSHWCTRS == 2U)
        if (ctrId == OSTIMER1) /* (CORE0)SysTimer ID */
        {
        #endif
            OSTIMCHOC = ticks;  /* set next point to OC register */
            OSSysTimClearFlag ();       /* clear output compare interrupt flag  */
            OSSysTimEnableInt ();       /* enable interrupts on channel */
        #if (OSNSYSHWCTRS == 2U)
        }
        else                    /* SecondTimer ID */
        {                       /* this is for Second Timer */
            OSTIM2CHOC = ticks; /* set next point to OC register */
            OSSecondClearFlag ();       /* clear output compare interrupt flag  */
            OSSecondEnableInt ();       /* enable interrupts on channel */
        }
        #endif
        #endif /* (OSNSYSHWCTRS > 0U) */
    }
}
#endif /* defined(OSHWCOUNTER) */

#if (OSNSYSHWCTRS > 0U)
/***************************************************************************
 * Function :   OSISRSystemTimer
 *
 * Description: ISR Cat2 for system timer
 *
 * Notes:       called only if timer is armed (HW counter used)
 *
 **************************************************************************/
void
OSISRSystemTimer (void)
{
    OSTPStopBudget ();      /* stop timing protection for preempted runable */

    if (OSSysTimFlagIsSet ())   /* if interrupt is not spurious */
    {
        OSSetCurApp (OSINVALID_OSAPPLICATION);  /* OS ISR does not belongs to any OS-Application */
        OSSystemEnterISR2 ();
        OSDI ();
        #if (OSNALMS > 0U)
        /* An ISR2 can interrupt this system timer ISR between
           OSSystemEnterISR2() and OSDI(). If that ISR2 calls an alarm
           service (like SetAlarmAbs() or CancelAlarm()), the alarm queue
           may became empty here.
           Secondly, an alarm set by SetAlarmAbs() called from that ISR2
           (for example) may trigger here. So two checks are necessary.
           ENGR00217477 */
        if ((OsCounters[OSTIMER1].alarm != OSALM0) && (OSSysTimFlagIsSet () != 0U))
        {
            OSSysTimClearFlag ();
            OSCounterNotify (OSTIMER1);
        }
        #endif
        OSSystemLeaveISR2 ();
    }
    OSWARNSUPPRESS
}

#if (OSNSYSHWCTRS == 2U)
/***************************************************************************
 * Function :   OSISRSecondTimer
 *
 * Description: ISR Cat2 for second timer
 *
 * Returns:
 *
 * Notes:       called only if timer is armed (HW counter used)
 *
 **************************************************************************/
void
OSISRSecondTimer (void)
{

    OSTPStopBudget ();      /* stop timing protection for preempted runable */

    if (OSSecondFlagIsSet () != 0U)   /* if interrupt is not spurious */
    {
        OSSetCurApp (OSINVALID_OSAPPLICATION);  /* OS ISR does not belongs to any OS-Application */
        OSSystemEnterISR2 ();
        OSDI ();

        #if (OSNALMS > 0U)
        if ((OsCounters[OSTIMER2].alarm != OSALM0) && (OSSecondFlagIsSet () != 0U))
        {
            OSSecondClearFlag ();
            OSCounterNotify (OSTIMER2);
        }
        #endif

        OSSystemLeaveISR2 ();
    }
    OSWARNSUPPRESS
}
#endif /* OSNSYSHWCTRS == 2U */

#else /* (OSNSYSHWCTRS > 0U) */

#if defined(OSSYSTIMER)         /* 1st system timer is SW */


/*
 * @violates @ref Os_counter_c_REF_19_4_1 MISRA 2004 Required Rule 19.4, Expression-like macro not parenthesized
 */
/*
 * @violates @ref Os_counter_c_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define OSSysSWTimFlagIsSet()  OSSysTimFlagIsSet()
/*
 * @violates @ref Os_counter_c_REF_19_4_1 MISRA 2004 Required Rule 19.4, Expression-like macro not parenthesized
 */
/*
 * @violates @ref Os_counter_c_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define OSSysSWTimClearFlag()  OSSysTimClearFlag()

/***************************************************************************
 * Function :   OSISRSystemTimer
 *
 * Description: ISR Cat2 for system timer
 *
 * Returns: 
 *
 * Notes:       SW counter used
 *
 **************************************************************************/
void
OSISRSystemTimer (void)
{

    #if defined(OSTIMSTM)
    TickType Tcnt;
    #endif

    OSTPStopBudget ();          /* stop timing protection for preempted runable */
   
    if (OSSysSWTimFlagIsSet() != 0U) /* if interrupt is not spurious */
    {
        OSSetCurApp (OSINVALID_OSAPPLICATION);  /* OS ISR does not belongs to any OS-Application */
        OSSystemEnterISR2 ();
        OSSysSWTimClearFlag();

        OSDI ();

        #if defined(OSTIMSTM)
        #if (OSTIMMODULO < 0x80000000U)
    again:
        #endif /* (OSTIMMODULO < 0x80000000) */

        Tcnt = OSTIMCHOC + OSTIMMODULO; /* set new value of the STM counter register for next interrupt */
        OSTIMCHOC = Tcnt;       /* set next value for interrupt */

        #endif /* defined(OSTIMSTM) */

        #if !defined(OSALMINCCOUNTER)
        OSCounterTrigger (OSTIMER1);
        #else
        OSAlmCounterTrigger (OSTIMER1);
        #endif /* !defined(OSALMINCCOUNTER) */

        #if defined(OSTIMSTM)
        #if defined(OSTIMMODULO)
        #if (OSTIMMODULO < 0x80000000U)
        Tcnt -= OSTIMMODULO;
        if ((TickType) (OSTIMTCNT - Tcnt) > OSTIMMODULO)
        {
            OSSysTimClearFlag ();
            /*
             * @violates @ref Os_counter_c_REF_14_4_1 MISRA 2004 Required Rule 14.4, Use of goto is deprecated
             */
            goto again;
        }
        #endif /* (OSTIMMODULO < 0x80000000) */
        #endif /* defined(OSTIMMODULO) */
        #endif /* defined(OSTIMSTM) */

        OSSystemLeaveISR2 ();
    }

    OSWARNSUPPRESS
}
#endif /* defined(OSSYSTIMER)  */
#endif /* OSNSYSHWCTRS == 1U */

#if defined(OSSECONDSOFT)


/*
 * @violates @ref Os_counter_c_REF_19_4_1 MISRA 2004 Required Rule 19.4, Expression-like macro not parenthesized
 */
/*
 * @violates @ref Os_counter_c_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define OSSecondSWFlagIsSet()  OSSecondFlagIsSet()
/*
 * @violates @ref Os_counter_c_REF_19_4_1 MISRA 2004 Required Rule 19.4, Expression-like macro not parenthesized
 */
/*
 * @violates @ref Os_counter_c_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define OSSecondSWClearFlag()  OSSecondClearFlag()

/***************************************************************************
 * Function :   OSISRSecondTimer
 *
 * Description: ISR Cat2 for 2nd system timer
 *
 * Returns: 
 *
 * Notes:       SW counter used
 *
 **************************************************************************/
void
OSISRSecondTimer (void)
{

    #if defined(OSTIM2STM)
    TickType Tcnt;
    #endif

    OSTPStopBudget ();          /* stop timing protection for preempted runable */

    if (OSSecondSWFlagIsSet() != 0U)  /* if interrupt is not spurious */
    {
        OSSetCurApp (OSINVALID_OSAPPLICATION);  /* OS ISR does not belongs to any OS-Application */
        OSSystemEnterISR2 ();
        OSSecondSWClearFlag ();

        OSDI ();

        #if defined(OSTIM2STM)
        #if (OSTIM2MODULO < 0x80000000U)
    again:
        #endif
        /* (OSTIM2MODULO < 0x80000000) */

        Tcnt = OSTIM2CHOC + OSTIM2MODULO;       /* set new value of the STM counter register for next interrupt */
        OSTIM2CHOC = Tcnt;      /* set next value for interrupt */

        #endif /* defined(OSTIM2STM) */

        #if !defined(OSALMINCCOUNTER)
        OSCounterTrigger (OSTIMER2);
        #else
        OSAlmCounterTrigger (OSTIMER2);
        #endif /* !defined(OSALMINCCOUNTER) */

        #if defined(OSTIM2STM)
        #if defined(OSTIM2MODULO)
        #if (OSTIM2MODULO < 0x80000000U)
        Tcnt -= OSTIM2MODULO;
        if ((TickType) (OSTIM2TCNT - Tcnt) > OSTIM2MODULO)
        {
            OSSecondClearFlag ();
            /*
             * @violates @ref Os_counter_c_REF_14_4_1 MISRA 2004 Required Rule 14.4, Use of goto is deprecated
             */
            goto again;
        }
        #endif /* (OSTIM2MODULO < 0x80000000) */
        #endif /* defined(OSTIM2MODULO) */
        #endif /* defined(OSTIM2STM) */

        OSSystemLeaveISR2 ();
    }

    OSWARNSUPPRESS
}
#endif /* defined(OSSECONDSOFT) */


#if defined(OSSYSTIMER)
/***************************************************************************
 * Function :   OSStopTimers
 *
 * Description: disable all timer(s) are defined for the master core
 *
 * Returns: 
 *
 * Notes:       only interrupts are disabled, timers are not stopped
 *
 **************************************************************************/
void
OSStopTimers (void)
{

    OSSysTimStop ();        /* stop System timer */
    OSSysTimDisableInt ();  /* disable output compare interrupt for System timer */
    OSSysTimClearFlag ();   /* clear output compare interrupt flag System timer */
    #if defined(OSSECONDTIMER)
    OSSecondStop ();        /* stop Second timer */
    OSSecondDisableInt ();  /* disable output compare interrupt from Second timer */
    OSSecondClearFlag ();   /* clear output compare interrupt flag Second timer */
    #endif /* defined(OSSECONDTIMER) */
}

/***************************************************************************
 * Function :   OSStartTimers
 *
 * Description: initialize channel(s) HW of timer(s) are defined for the master core
 *              and start it
 *
 * Notes:       1. MPC55xx/56xx HW specific 
 *
 **************************************************************************/
void 
OSStartTimers (void)
{
    OSSysTimSetHW ();
    OSSysTimClearFlag ();   /* clear interrupt flag  */
    #if (OSNSYSHWCTRS == 0U)
    OSSysTimEnableInt ();   /* enable interrupt for SW system timer */
    #endif

    #if defined(OSSECONDTIMER)
    OSSecondSetHW ();       /* second timer HW initialization */
    OSSecondClearFlag ();   /* clear interrupt flag  */
    #if (OSNSYSHWCTRS < 2U)
    OSSecondEnableInt ();   /* enable interrupt for SW second timer */
    #endif
    #endif    
}
#endif /* defined(OSSYSTIMER) */


#if defined(OSSYSTIMER) || defined(OS2SYSTIMER)
/***************************************************************************
 * Function :   OSInitSystemTimer
 *
 * Description: initialize general HW of timer(s)
 *
 * Notes:       1. MPC55xx/56xx HW specific,
 *              2. called with interrupts disabled 
 *
 **************************************************************************/
void
OSInitSystemTimer (void)
{

    /* System Timer initialization */
    {
        #if defined(OSSYSTIMER)
        #if defined(OSCWPPC)
        #pragma warn_no_side_effect off /* to suppress warning about expression has no effect */
        #endif
        OSTimHWprepare ();
        #if defined(OSCWPPC)
        #pragma warn_no_side_effect reset
        #endif
        #endif
    }


    /* Second Timer initialization */
    #if defined(OSSECONDTIMER) || defined(OS2SECONDTIMER)

    {
        #if defined(OSSECONDTIMER)
        #if defined(OSTIM2INIT)
        #if defined(OSCWPPC)
        #pragma warn_no_side_effect off /* to suppress warning about expression has no effect */
        #endif
        OSTim2HWprepare ();
        #if defined(OSCWPPC)
        #pragma warn_no_side_effect reset
        #endif
        #endif
        #endif
    }
    #endif /* defined(OSSECONDTIMER) || defined(OS2SECONDTIMER) */
}
#endif /* defined(OSSECONDTIMER) || defined(OS2SECONDTIMER) */

/* Public services */

/******************************************************************************
 * Function:    InitCounter
 *
 * Description: Set initial counter value
 *
 * Return: E_OK                       no errors 
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_VALUE                 value outside of the admissible limit
 *         E_OS_ACCESS                access to the object denied
 *
 * Notes: If alarms are linked to this counter, then its state unchanged.
 ******************************************************************************/
StatusType
OS_InitCounter (CounterType ctrId, TickType value)
{
    #if defined(OSCWPPC)
    #pragma unused( ctrId ) /* to suppress warning about unused variable */
    #endif


    #if defined(OSCALCULATEOBJIND)
    OSWORD ctrInd;
    #endif

    OSOrtiSetServiceWatch (OSServiceId_InitCounter);    /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_InitCounter, ctrId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_InitCounter, ctrId);
        }
    }
    #endif /* OSCHECKCONTEXT */

    #if defined(OSEXTSTATUS)
    if (OSCTRIDISINVALID (ctrId))
    {   /* invalid ID */
        /*
         * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_InitCounter, ctrId);
    }
    #endif

    #if defined(OSCALCULATEOBJIND)
    ctrInd = OS_GETOBJIND (ctrId);
    #endif

    #if defined(OSEXTSTATUS)
    if (value > OsCountersCfg[ctrInd].maxallowedvalue)
    {   /* value is outside of admissible limit */
        /*
         * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_VALUE, OSServiceId_InitCounter, ctrId);
    }
    #endif

    /*
     * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKACCESSRIGHTS (OsCounters[ctrInd].appMask, OSServiceId_InitCounter, ctrId);

    #if defined(OSSWCOUNTER)
    #if defined(OSHWCOUNTER)
    if (ctrInd >= OSNHWCTRS)
    #endif
    {
        OSSWCtrInit (ctrInd, value);
    }
    #endif /* defined(OSSWCOUNTER) */

    #if defined(OSHWCOUNTER)
    #if defined(OSSWCOUNTER)
    else
    #endif /* defined(OSSWCOUNTER) */
    {
        OSHWCtrInit (ctrInd, (OSHWTickType)value);
    }
    #endif /* defined(OSHWCOUNTER) */

    OSOrtiServiceWatchOnExit (OSServiceId_InitCounter);
    return E_OK;
}

/******************************************************************************
 * Function:    GetCounterValue
 *
 * Description: Return counter value
 *
 * Return: E_OK                       no errors 
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_ACCESS                access to the object denied
 ******************************************************************************/
StatusType
OS_GetCounterValue (CounterType ctrId, TickRefType tickRef)
{
    #if defined(OSCWPPC)
    #pragma unused( ctrId ) /* to suppress warning about unused variable */
    #endif

    TickType value;


    #if defined(OSCALCULATEOBJIND)
    OSWORD ctrInd;
    #endif

    OSOrtiSetServiceWatch (OSServiceId_GetCounterValue);        /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_GetCounterValue, ctrId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_GetCounterValue, ctrId);
        }
    }
    #endif /* OSCHECKCONTEXT */

    #if defined(OSEXTSTATUS)
    if (OSCTRIDISINVALID (ctrId))
    {   /* invalid ID */
        /*
         * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_GetCounterValue, ctrId);
    }
    #endif

    #if defined(OSCALCULATEOBJIND)
    ctrInd = OS_GETOBJIND (ctrId);
    #endif

    /*
     * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKACCESSRIGHTS (OsCounters[ctrInd].appMask, OSServiceId_GetCounterValue, ctrId);
    /*
     * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKWRITEACCESS (tickRef, sizeof (TickType), OSServiceId_GetCounterValue, ctrId);

    #if defined(OSSWCOUNTER)
    #if defined(OSHWCOUNTER)
    if (ctrInd >= OSNHWCTRS)
    #endif
    {
        value = (TickType) OSSWCtrValue (ctrInd);
    }
    #endif /* defined(OSSWCOUNTER) */

    #if defined(OSHWCOUNTER)
    #if defined(OSSWCOUNTER)
    else
    #endif /* defined(OSSWCOUNTER) */
    {
        {
            value = (TickType) OSHWCtrValue (ctrInd);
        }
    }
    #endif /* defined(OSHWCOUNTER) */


    *tickRef = value;
    OSOrtiServiceWatchOnExit (OSServiceId_GetCounterValue);
    return E_OK;
}

/*******************************************************************************
 * Function:    GetElapsedValue
 *
 *
 * Description: Return elapsed counter value
 *
 * Return: E_OK                       no errors 
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_VALUE                 value outside of the admissible limit
 *         E_OS_ACCESS                access to the object denied
 *         E_OS_ILLEGAL_ADDRESS       invalid pointer parameter
 ******************************************************************************/
StatusType
OS_GetElapsedValue (CounterType ctrId,
                           TickRefType valueRef,
                           TickRefType tickRef)
{
    TickType elapsedValue, currentValue;


    #if defined(OSCALCULATEOBJIND)
    OSWORD ctrInd;
    #endif

    OSOrtiSetServiceWatch (OSServiceId_OSGetElapsedCounterValue);       /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_OSGetElapsedCounterValue, ctrId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_OSGetElapsedCounterValue, ctrId);
        }
    }
    #endif /* OSCHECKCONTEXT */

    #if defined(OSEXTSTATUS)
    if (OSCTRIDISINVALID (ctrId))
    {                           /* invalid ID */
       /*
        * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
        */
       OSRETERROR (E_OS_ID, OSServiceId_OSGetElapsedCounterValue, ctrId);
    }
    #endif

    #if defined(OSCALCULATEOBJIND)
    ctrInd = OS_GETOBJIND (ctrId);
    #endif

    /*
     * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKWRITEACCESS (valueRef, sizeof (TickRefType), OSServiceId_OSGetElapsedCounterValue, ctrId);

    /*
     * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKACCESSRIGHTS (OsCounters[ctrInd].appMask, OSServiceId_OSGetElapsedCounterValue, ctrId);

    #if defined(OSEXTSTATUS)

    if (OsCountersCfg[ctrInd].maxallowedvalue < (*valueRef))
    {
        /*
         * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_VALUE, OSServiceId_OSGetElapsedCounterValue, ctrId);
    }
    #endif /* defined(OSEXTSTATUS) */


    /*
     * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKWRITEACCESS (tickRef, sizeof (TickRefType), OSServiceId_OSGetElapsedCounterValue, ctrId);

    #if defined(OSSWCOUNTER)
    #if defined(OSHWCOUNTER)
    if (ctrInd >= OSNHWCTRS)
    #endif
    {
        currentValue = (TickType) OSSWCtrValue (ctrInd);
    }
    #endif /* defined(OSSWCOUNTER) */

    #if defined(OSHWCOUNTER)

    #if defined(OSSWCOUNTER)
    else
    #endif /* defined(OSSWCOUNTER) */
    {
        {
            currentValue = (TickType) OSHWCtrValue (ctrInd);
        }
    }

    #endif /* defined(OSHWCOUNTER) */


    if (currentValue >= (*valueRef))
    {
        elapsedValue = currentValue - (*valueRef);
    }
    else
    {
        elapsedValue = (OsCountersCfg[ctrInd].maxallowedvalue + 1U) - ((*valueRef) - currentValue);
    }


    *tickRef = elapsedValue;
    *valueRef = currentValue;
    OSOrtiServiceWatchOnExit (OSServiceId_OSGetElapsedCounterValue);
    return E_OK;
}

#if defined(OSALMINCCOUNTER)
/******************************************************************************
 * Function:    OSAlmCounterTrigger
 *
 * Description: Increment counter value and another counters values if expired
 *              alarm(s) has "increment counter" action.
 *
 * Returns: 
 *
 * Notes:
 *
 ******************************************************************************/
static void
OSAlmCounterTrigger (OSWORD ctrInd)
{

    OSWORD index;
    OsCtrIncCounter = 0U;
    OSCounterTrigger (ctrInd);

    while (OsCtrIncCounter != 0U)
    {
        /* Check for all SW counters */
        for (index = OSNHWCTRS; index < OSNCTRS; index++)
        {
            if (OsCtrIncValue[index - OSNHWCTRS] > 0U)
            {
                OsCtrIncValue[index - OSNHWCTRS]--;
                OsCtrIncCounter--;
                OSCounterTrigger (index);
            }
        }
    }
}
#endif

/******************************************************************************
 * Function:    IncrementCounter
 *
 * Description: Increment counter value and check attached alarms
 *
 * Return: E_OK                       no errors 
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_ACCESS                access to the object denied
 ******************************************************************************/
StatusType
OS_IncrementCounter (CounterType ctrId)
{
    #if defined(OSCWPPC)
    #pragma unused( ctrId ) /* to suppress warning about unused variable */
    #endif
    
    #if defined(OSSWCOUNTER)
    OSIMSAVE                    /* OSINTMASKTYPE save; */
    #endif

    #if (defined(OSCALCULATEOBJIND) && defined(OSSWCOUNTER)) || defined(OSEXTSTATUS)        
    OSWORD ctrInd;
    #endif

    OSOrtiSetServiceWatch (OSServiceId_IncrementCounter);       /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_IncrementCounter, ctrId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_IncrementCounter, ctrId);
        }
    }
    #endif /* OSCHECKCONTEXT */

    #if (defined(OSCALCULATEOBJIND) && defined(OSSWCOUNTER)) || defined(OSEXTSTATUS)
    ctrInd = OS_GETOBJIND (ctrId);
    #endif

    #if defined(OSEXTSTATUS)
    if ((OSCTRIDISINVALID (ctrId))
        #if defined(OSHWCOUNTER)
        || (ctrInd < OSNHWCTRS)
        #endif
        )                       /* invalid ID */
    {
        /*
         * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_IncrementCounter, ctrId);
    }
    #endif /* OSEXTSTATUS */

    

    #if defined(OSSWCOUNTER)

    OSDIS (save);

    /*
     * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKACCESSRIGHTSRI (OsCounters[ctrInd].appMask, OSServiceId_IncrementCounter, ctrId);

    OSOrtiSetOldServiceID (OSServiceId_IncrementCounter);

    #if (OSNALMS > 0U)
    OSPUTPARAM (OSServiceId_IncrementCounter, ctrId);
    #endif

    #if !defined(OSALMINCCOUNTER)
    OSCounterTrigger (ctrInd);
    #else
    OSAlmCounterTrigger (ctrInd);
    #endif /* !defined(OSALMINCCOUNTER) */

    #if (OSNALMS > 0U)
    OSCLEARPARAM ();

    OSDISPATCH ();
    #endif /* (OSNALMS > 0U) */

    OSOrtiResetIdOnExit ();
    OSRI (save);

    #endif /* defined(OSSWCOUNTER) */

    return E_OK;
}

/******************************************************************************
 * Function:    GetCounterInfo
 *
 * Description: Fill counter info structure
 *
 * Return: E_OK                       no errors 
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_ACCESS                access to the object denied
 ******************************************************************************/
StatusType
OS_GetCounterInfo (CounterType ctrId, CtrInfoRefType info)
{

    #if defined(OSCALCULATEOBJIND)
    OSWORD ctrInd;
    #endif

    OSOrtiSetServiceWatch (OSServiceId_GetCounterInfo); /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_GetCounterInfo, ctrId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_GetCounterInfo, ctrId);
        }
    }
    #endif /* OSCHECKCONTEXT */

    #if defined(OSEXTSTATUS)
    if (OSCTRIDISINVALID (ctrId))
    {   /* invalid ID */
        /*
         * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_GetCounterInfo, ctrId);
    }
    #endif

    #if defined(OSCALCULATEOBJIND)
    ctrInd = OS_GETOBJIND (ctrId);
    #endif

    /*
     * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKACCESSRIGHTS (OsCountersCfg[ctrInd].appMask, OSServiceId_GetCounterInfo, ctrId);
    
    /*
     * @violates @ref Os_counter_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKWRITEACCESS (info, sizeof (CtrInfoType), OSServiceId_GetCounterInfo, ctrId);

    /* Fill counter info structure */
    info->maxallowedvalue = OsCountersCfg[ctrInd].maxallowedvalue;
    info->ticksperbase = OsCountersCfg[ctrInd].ticksperbase;

    #if defined(OSEXTSTATUS)
    info->mincycle = OsCountersCfg[ctrInd].mincycle;
    #endif /* defined(OSEXTSTATUS) */

    OSOrtiServiceWatchOnExit (OSServiceId_GetCounterInfo);
    return E_OK;
}
#endif /* defined(OSCOUNTER) */

#define OSTEXT_STOP_SEC_CODE
/*
* @violates @ref Os_counter_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif


/** @} */
