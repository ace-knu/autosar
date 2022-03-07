/**
*   @file    Os_counter_internal_api.h
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

#ifndef OS_COUNTER_INTERNAL_API_H_
#define OS_COUNTER_INTERNAL_API_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>
#include <Os_types_basic.h>

#include <Os_counter_internal_types.h>
#include <Os_counter_config.h> /**< for OsCountersCfg */

#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSCOUNTER)
#if defined(OSALMINCCOUNTER)
OSDECLAREVAR (extern OSNEAR OSDWORD, OsCtrIncCounter_);
#define OsCtrIncCounter OSUSEVAR(OsCtrIncCounter_)
#endif /* defined(OSALMINCCOUNTER) */
#endif /* defined(OSCOUNTER) */

#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#if defined(OSCOUNTER)

#if defined(OSSECONDTIMER)
#if (OSNHWCTRS  < 2U)
#define OSSECONDSOFT            /* Second Timer is SW */
#endif
#endif

#if (OSNSYSTMRS > 0U)
#include <Os_timer_internal_api.h>
#endif

#if defined(OSHWCOUNTER)

#if (OSNHWCTRS == 1U)

#define OSHWCtrArm( ctrId, value )  OSSysTimerArm( value )
extern void OSSysTimerArm (OSHWTickType ticks);
#define OSHWCtrCancel( ctrId ) OSSysTimerCancel()
extern void OSSysTimerCancel (void);

#elif (OSNHWCTRS > 1U)

#define OSHWCtrArm( ctrId, value )  OSSysTimerArm( ctrId, value )
extern void OSSysTimerArm (OSWORD ctrInd, OSHWTickType ticks);

#define OSHWCtrCancel( ctrId ) OSSysTimerCancel( ctrId )
extern void OSSysTimerCancel (OSWORD ctrInd);

#endif /* OSNHWCTRS == 1U */

#endif /* defined(OSHWCOUNTER) */


/*  Private OS Services */

extern void OSInitCounters (void);

#if defined(OSSWCOUNTER)
#define OSSWCtrInit(ctrId, vl)    (OsCounters[(ctrId)].value = (vl))
#define OSSWCtrValue(ctrId)       (OsCounters[(ctrId)].value)
#endif


#if defined(OSSWCOUNTER)

#define OSIncrementCounter(ctrId)                                       \
    if( OSSWCtrValue(ctrId) == OsCountersCfg[(ctrId)].maxallowedvalue ) \
    {                                                                   \
        OSSWCtrInit( (ctrId), 0UL );                                    \
    }                                                                   \
    else                                                                \
    {                                                                   \
        OSSWCtrValue(ctrId)++;                                          \
    }                                                                   \

#if (OSNALMS > 0U)
#define OSCounterTrigger(ctrInd) \
    OSIncrementCounter(ctrInd)   \
    OSCheckAlarms(ctrInd)
#else /* OSNALMS > 0U */
#define OSCounterTrigger(ctrInd) \
    OSIncrementCounter(ctrInd)
#endif /* OSNALMS > 0U */

#endif /* defined(OSSWCOUNTER) */


#if defined(OSSYSTIMER) || defined(OS2SYSTIMER)
extern void OSInitSystemTimer (void);

#if defined(OSSYSTIMER)
extern void OSStartTimers (void);
extern void OSStopTimers (void);
#endif

/***************************************************************************
 * Function :   OSShutdownSystemTimer
 *
 * Description: disable all timer(s)
 *
 * Returns: 
 *
 * Notes:       only interrupts are disabled, timers are not stopped
 *
 **************************************************************************/
OSINLINE void
OSShutdownSystemTimer (void)
{

    
    {
        #if defined(OSSYSTIMER)    
        OSStopTimers ();
        #endif    
    }
       
}

/***************************************************************************
 * Function :   OSStartSystemTimer
 *
 * Description: initialize channel(s) HW of timer(s) and start it
 *
 * Notes:       1. MPC55xx/56xx HW specific,
 *              2. called with interrupts disabled 
 *
 **************************************************************************/
OSINLINE void
OSStartSystemTimer (void)
{

    /* System/Second Timer initialization */
    {
        #if defined(OSSYSTIMER)
        OSStartTimers ();
        #endif
    }
    
}
#else
#define OSInitSystemTimer()
#define OSStartSystemTimer()
#endif /* defined(OSSYSTIMER) || defined(OS2SYSTIMER) */

#else /* defined(OSCOUNTER) */

#define OSInitSystemTimer()
#define OSStartSystemTimer()

#endif /* defined(OSCOUNTER) */

#if (OSNALMS > 0U)

/******************************************************************************
* Function:    OSAbsTickValue
* Description:
* Returns:     Absolute tick value
* Notes:
******************************************************************************/
OSINLINE TickType
OSAbsTickValue (OSWORD ctrInd, TickType rel)
{

    #if defined(OSSWCOUNTER)

    #if defined(OSHWCOUNTER)
    if (ctrInd >= OSNHWCTRS)
    #endif
    {
        if ((OsCountersCfg[ctrInd].maxallowedvalue - OSSWCtrValue (ctrInd)) < rel)
        {
            rel -= (OsCountersCfg[ctrInd].maxallowedvalue - OSSWCtrValue (ctrInd) + 1U);
        }
        else
        {
            rel += OSSWCtrValue (ctrInd);
        }
    }
    #endif /* defined(OSSWCOUNTER) */

    #if defined(OSHWCOUNTER)

    #if defined(OSSWCOUNTER)
    else
    #endif /* defined(OSSWCOUNTER) */
    {
        OsTimVal = OSHWCtrValue (ctrInd);       /* set OsTimValue to the current counter value */

        if ((OsCounters[ctrInd].alarm != OSALM0) && OSHWCtrInterruptRaised (ctrInd))
        {                       /* if there is an alarm set for the counter and HW counter has crossed old OC value */
            OsTimVal = OSHWCtrGetOC (ctrInd);   /* set OsTimValue to the current value of the OC register */
            /* to achieve valid comparison in OsSetAlarm */
            rel += OSHWCtrValue (ctrInd);       /* re-read the counter value to avoid race conditions */
        }
        else
        {
            rel += OsTimVal;
        }
        rel = OSCTRBITS (rel);
    }
    #endif /* defined(OSHWCOUNTER) */

    return rel;
}
#endif /* (OSNALMS > 0U)  */

#if (OSNALMS > 0U)

#if defined(OSHWCOUNTER)
 /******************************************************************************
  * Function:    OSSetTimVal
  * Description:
  * Returns:
  * Notes:
  ******************************************************************************/
OSINLINE void
OSSetTimVal (OSWORD ctrInd)
{
    #if defined(OSSWCOUNTER)
    if (ctrInd < OSNHWCTRS)
    #endif
    {
        OsTimVal = OSHWCtrValue (ctrInd);       /* set OsTimValue to the current counter value */
        if (OsCounters[ctrInd].alarm != OSALM0)
        {                       /* if there was an alarm */
            if (OSHWCtrInterruptRaised (ctrInd))        /* and HW counter has crossed old OC value */
            {
                OsTimVal = OSHWCtrGetOC (ctrInd);       /* set OsTimValue to the current value of the OC register */
            }                   /* to achieve valid comparison in OsSetAlarm */
        }
    }
}
#endif /* defined(OSHWCOUNTER) */

#endif /* #if (OSNALMS > 0U) */

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif

#endif /*OS_COUNTER_INTERNAL_API_H_ */

/** @} */
