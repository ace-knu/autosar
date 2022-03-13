/**
*   @file    Os_alarm.c
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
* @section Os_alarm_c_REF_5_1_1
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters. 
* The section identification define's naming convention is defined by AutoSar and identifiers are longer than 31 character. 
* Compilers are checked for support this length of identifiers.
*
* @section Os_alarm_c_REF_14_4_1
* Violates MISRA 2004 Required Rule 14.4, Use of goto is deprecated
* The goto statement shall not be used.
* The goto statement is used to implement of overrun protection algorithm (for HW counters).
*
* @section Os_alarm_c_REF_14_7_1
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function 
* A function shall have a sigle point of exit at the end of finction.
* The returned statement is result of error hanling.
*
* @section Os_alarm_c_REF_17_4_1
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* Array indexing shall be the only allowed form of pointer arithmetic
* The pointers are used to increase of OS performance.
*
* @section Os_alarm_c_REF_19_1_1
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

#include <Os_alarm_api.h>
#include <Os_alarm_types.h>
#include <Os_alarm_internal_api.h>
#include <Os_alarm_internal_types.h>
#include <Os_alarm_config.h>


/*
* @violates @ref Os_alarm_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSHWCOUNTER)
OSDECLAREVAR (OSNEAR OSHWTickType, OsTimVal_);
#endif

/*
* @violates @ref Os_alarm_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_alarm_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#define OS_START_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_alarm_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if (OSNALMS > 0U)
#if (OSNUSERALMS > 0U) && (OSNSCTALMS == 0U)
OSALMCB OsAlarms[OSNUSERALMS];
#endif
#endif /* (OSNALMS > 0U) */

#define OS_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_alarm_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#define OS_START_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_alarm_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if (OSNALMS > 0U)
#if (OSNUSERALMS > 0U) && (OSNSCTALMS > 0U)
OSALLALARMS OsAllAlarms;               /**< common CB for alarms and sct */
#endif
#endif /* (OSNALMS > 0U) */

#define OS_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_alarm_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#define OSTEXT_START_SEC_CODE
/*
* @violates @ref Os_alarm_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#define userAlmId ((OSALMCB *) almId)

#if !defined(OSCALCULATEOBJIND)
#define almInd (almId)
#endif


#if (OSNALMS > 0U)
 /*****************************************************************************
 * Function:    OSKillAlarm
 *
 * Description: Stop the alarm without checkings (unlike OS_CancelAlarm)
 *
 * Returns:     none
 *
 * Notes:       used in TerminateApplication
 *
 ******************************************************************************/
void
OSKillAlarm (OSAlmType alarmPtr)
{
    #if defined(OSHWCOUNTER)
    OSAlmType almRef;
    OSAlmType min = OSALMCBPTR0;
    OSWORD ctrInd;

    ctrInd = alarmPtr->ctrIndex;
    #endif

    (alarmPtr->prev)->next = alarmPtr->next;
    if (alarmPtr->next != OSALMCBPTR0)  /* Is this alarm last in the list ? */
    {
        alarmPtr->next->prev = alarmPtr->prev;
    }
    #if defined(OSHWCOUNTER)
    #if defined(OSSWCOUNTER)
    if (ctrInd < OSNHWCTRS)
    #endif
    {
        alarmPtr->prev = OSALMCBPTR0;   /* It is necessary for check E_OS_STATE */
        OsTimVal = (OSHWTickType)OSHWCtrGetOC (ctrInd);       /* set osTimVal */
        if (OsCounters[ctrInd].alarm == OSALM0)
        {   /* if there are no more alarms on HW counter */
            OSHWCtrCancel (ctrInd);     /* then cancel it */
        }
        else
        {   /* reArm counter and check for expiried alarms */
            OSHWTickType time1, time2;

            almRef = OsCounters[ctrInd].alarm;
            do
            {
                time2 = OSCTRBITS (almRef->value - OsTimVal);

                if ((min == OSALMCBPTR0) || (OSCTRBITS (min->value - OsTimVal) > time2))
                {
                    min = almRef;
                }
                almRef = almRef->next;

            }
            while (almRef != OSALM0);

            if (min->value != OsTimVal) /* an other alarm to be armed */
            {
                OsTimVal = (OSHWTickType)OSHWCtrValue (ctrInd);       /* set OsTimVal the current counter value */
                if (OSHWCtrInterruptRaised (ctrInd))    /* Interrupt raised since last OSDI() */
                {
                    OsTimVal = (OSHWTickType)OSHWCtrGetOC (ctrInd);   /* set OsTimVal the current value of the OC register */
                }
                OSHWCtrArm (ctrInd, (OSHWTickType)min->value);

                time1 = OSCTRBITS (OSHWCtrValue (ctrInd) - OsTimVal);
                time2 = OSCTRBITS (OSHWCtrGetOC (ctrInd) - OsTimVal);

                /* if new alarm already expiried  */
                if (time1 >= time2)
                {
                    OSCounterNotify (ctrInd);
                }
            }
        }

    }
    #if defined(OSSWCOUNTER)
    else
    #endif /* defined(OSSWCOUNTER) */
    #endif /* defined(OSHWCOUNTER) */
    {
        alarmPtr->prev = OSALMCBPTR0;   /* It is necessary for check E_OS_STATE */
    }
}

/***************************************************************************
 * Function:    OSSCNotifyAlarmAction
 *
 * Description: 
 *
 * Notes:
 *
 **************************************************************************/
static OSINLINE_ void
OSSCNotifyAlarmAction (OSALMACTPTR action)
{
    #if defined(OSBCC)
    if (OSTASKACTEXHAUSTED (action->taskIndex))
    {
        OSErrorHook_noPar (E_OS_LIMIT); /* attempt to multiply activation */
    }
    else
    {
        #if defined(OSNOFASTTERMINATE) || defined(OSINRES)
        OSActivateTaskInAlm (action->taskIndex);
        #else
        OSTask2Ready (action->taskIndex);
        #endif
    }

    #elif defined(OSECC)
    #if (OSNXTSKS > 0U)
    #if defined(OSALMSETEVENT) || defined(OSSCTSETEVENT)
    if (action->event)
    {
        if ((OSTASKSTATUS (action->taskIndex) & OSTCBNOSUSPENDED) == 0U)
        {
            OSErrorHook_noPar (E_OS_STATE);     /* the task is in a suspended state */
        }
        else
        {
            OSSetEventInAlm (&OsTaskTable[action->taskIndex], action->event);
        }
        /*
         * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return;
    }
    else
    #endif /* defined(OSALMSETEVENT) || defined(OSSCTSETEVENT) */
    {
        if (OSTASKACTEXHAUSTED (action->taskIndex))
        {
            OSErrorHook_noPar (E_OS_LIMIT);     /* attempt to multiply activation */
        }
        else
        {
            OsTaskTable[action->taskIndex].set_event = OSNOEVENTS;
            /* set flag that task has no valid context  yet */
            OSActivateTaskInAlm (action->taskIndex);
        }
    }

    #else /* OSNXTSKS > 0     */
    if (OSTASKACTEXHAUSTED (action->taskIndex))
    {
        OSErrorHook_noPar (E_OS_LIMIT); /* attempt to multiply activation */
    }
    else
    {   /* set flag that task has no valid context yet */
        OSActivateTaskInAlm (action->taskIndex);
    }

    #endif /* OSNXTSKS > 0     */

    #endif /* defined(OSECC)  */

    return;
}


/***************************************************************************
 * Function:    OSNotifyAlarmAction
 *
 * Description: 
 *
 * Notes:
 *
 **************************************************************************/
#if defined(OSAPPLICATION)
void 
OSNotifyAlarmAction (OSALMACTPTR action, OSAPPLICATIONTYPE appId)
#else
void 
OSNotifyAlarmAction (OSALMACTPTR action)
#endif
{

    #if defined(OSAPPLICATION)
    if ((OSGIVENAPPMASK (appId) & OsTaskTable[action->taskIndex].appMask) == 0U)
    {
        OSErrorHook_noPar (E_OS_ACCESS);
        /*
         * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return;
    }
    #endif

    OSSCNotifyAlarmAction (action);
}


#if defined(OSHWCOUNTER)
/***************************************************************************
 * Function :   OSCounterNotify
 *
 * Description: check for expired alarms and perform appropriate actions
 *
 * Returns:
 *
 * Notes:       1. called only if at least one alarm expired.
 *              2. this is intended for alarms on "HW" counters only
 *
 **************************************************************************/
void 
OSCounterNotify (OSWORD ctrInd)
{

    OSAlmType almId;            /* current alarm        */
    OSAlmType *almRef;          /* temporary pointer    */
    OSHWTickType minVal;
    OSHWTickType delta;

    #if defined(OSSCHEDULETABLES)
    OSAlmType newAlmId;
    #endif

    #if defined(OSALMINCCOUNTER)
    OSWORD index;
    #endif

again:

    OsTimVal = (OSHWTickType)OSHWCtrGetOC (ctrInd);   /* set osTimVal */
    minVal = OsTimVal - 1U;
    delta = (OSHWTickType)OSCTRBITS (0xFFFFFFFFUL);

    #if defined(OSSCHEDULETABLES)

almAdded:
    newAlmId = OSALM0;
    #endif /* defined(OSSCHEDULETABLES) */

    almRef = &(OsCounters[ctrInd].alarm);

    do
    {
        if ((*almRef)->value == OsTimVal)
        {
            almId = *almRef;
            #if defined(OSSCHEDULETABLES)
            #if (OSNUSERALMS > 0U)
            if (almId >= ((OSAlmType) & OSALMSCTARRAY[0]))      /* if it is schedule table alarm. */
            /* Note: the array of user alarms is located in the memory before the array of schedule table alarms. */
            {
            #endif
                newAlmId = OSProcessScheduleTable ((OSSCTALMCB *) almId);
            #if (OSNUSERALMS > 0U)
            }
            else
            #endif
            #endif /* defined(OSSCHEDULETABLES) */

            #if (OSNUSERALMS > 0U)
            #if defined(OSALMCALLBACK)
            if (userAlmId->callBack)
            {
                #if defined(OSGETSERVICEID)
                OSServiceIdType tmpId;
                tmpId = OsService;
                OSCLEARPARAM ();
                #endif

                OsIsrLevel |= OSISRLEVELALMCALLBACK;
                userAlmId->callBack ();
                OsIsrLevel &= (OSISRLEVELTYPE) (~OSISRLEVELALMCALLBACK);

                #if defined(OSGETSERVICEID)
                OsService = tmpId;
                #endif
            }
            else
            #endif /* defined(OSALMCALLBACK) */

            #if defined(OSALMINCCOUNTER)
            if (userAlmId->ctrIndexInc != OSCTR0)
            {
                OsCtrIncValue[userAlmId->ctrIndexInc - OSNHWCTRS]++;
                OsCtrIncCounter++;

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
            else
            #endif /* defined(OSALMINCCOUNTER) */
            {
                #if defined(OSAPPLICATION)
                OSNotifyAlarmAction (&userAlmId->action, userAlmId->appId);     /* perform alarm action */
                #else
                OSNotifyAlarmAction (&userAlmId->action);       /* perform alarm action */
                #endif
            }
            #endif /* (OSNUSERALMS > 0U) */

            if (almId->cycle == 0U)
            {                   /* remove alarm from list if it is not cyclic */
                (almId->prev)->next = almId->next;
                if (almId->next != OSALMCBPTR0) /* Is it the last alarm in the list ?   */
                {
                    (almId->next)->prev = almId->prev;
                }
                almId->prev = OSALMCBPTR0;      /* It is necessary for check E_OS_STATE */
            }
            else
            {                   /* reinsert alarm if it is cyclic       */
                almId->value = OSCTRBITS (almId->value + almId->cycle);
                if (OSCTRBITS (almId->value - OsTimVal) < delta)
                {
                    minVal = (OSHWTickType)almId->value;
                    delta = OSCTRBITS (minVal - OsTimVal);
                }
                almRef = &(*almRef)->next;
            }

            #if defined(OSSCHEDULETABLES)
            if (newAlmId != OSALMCBPTR0)
            {
                /* Easy insert into head of list */
                newAlmId->next = OsCounters[ctrInd].alarm;
                OsCounters[ctrInd].alarm = newAlmId;
                newAlmId->prev = (OSAlmType) (&(OsCounters[ctrInd].alarm));     /* The counter node is previous for first in list */
                if (newAlmId->next != OSALMCBPTR0)      /* There are already alarms in the list */
                {
                    (newAlmId->next)->prev = newAlmId;
                }
                /*
                * @violates @ref Os_alarm_c_REF_14_4_1 MISRA 2004 Required Rule 14.4, Use of goto is deprecated
                */
                goto almAdded;
            }
            #endif /* defined(OSSCHEDULETABLES) */

        }
        else
        {                       /* value != OsTimVal */

            if (OSCTRBITS ((*almRef)->value - OsTimVal) < delta)
            {
                minVal = (OSHWTickType)((*almRef)->value);
                delta = OSCTRBITS (minVal - OsTimVal);
            }

            almRef = &((*almRef)->next);
        }

    }
    while (*almRef != OSALM0);


    if (OsCounters[ctrInd].alarm != OSALM0)
    {                           /* arm counter if there are attached alarms */
        OSHWTickType time1, time2;

        OSHWCtrArm (ctrInd, minVal);

        time1 = OSCTRBITS (OSHWCtrValue (ctrInd) - OsTimVal);
        time2 = OSCTRBITS (minVal - OsTimVal);

        if (time1 >= time2)     /* if new alarm already expired */
        {
            OSHWCtrCancel (ctrInd);     /* disable interrupt and clear channel flag */
            /*
            * @violates @ref Os_alarm_c_REF_14_4_1 MISRA 2004 Required Rule 14.4, Use of goto is deprecated
            */
            goto again;         /* repeat notification                      */
        }
    }
    else
    {                           /* otherwise inform it that no more alarms  */
        OSHWCtrCancel (ctrInd);
    }
}
#endif /* defined(OSHWCOUNTER) */

/***************************************************************************
 * Function:    OSCheckAlarms
 *
 * Description: Check linked alarms
 *
 * Returns:
 *
 * Notes:       for SW counters
 *
 **************************************************************************/
void 
OSCheckAlarms (OSWORD ctrInd)
{

    OSAlmType almId;        /* current alarm        */
    TickType *delta;

    #if defined(OSSCHEDULETABLES)
    OSAlmType newAlmId;

almAdded:
    newAlmId = OSALM0;
    #endif /* defined(OSSCHEDULETABLES) */

    almId = OsCounters[ctrInd].alarm;
    while (almId != OSALMCBPTR0)
    {
        delta = &(almId->value);
        if (*delta == OsCounters[ctrInd].value)
        {
            #if defined(OSSCHEDULETABLES)
            #if (OSNUSERALMS > 0U)
            if (almId >= ((OSAlmType) & OSALMSCTARRAY[0]))      /* if it is schedule table alarm. */
                /* Note: the array of user alarms is located in the memory before the array of schedule table alarms. */
            {
            #endif
                newAlmId = OSProcessScheduleTable ((OSSCTALMCB *) almId);
            #if (OSNUSERALMS > 0U)
            }
            else
            #endif
            #endif /* defined(OSSCHEDULETABLES) */
            #if (OSNUSERALMS > 0U)
            #if defined(OSALMCALLBACK)
            if (userAlmId->callBack)
            {
                #if defined(OSGETSERVICEID)
                OSServiceIdType tmpId;
                tmpId = OsService;
                OSCLEARPARAM ();
                #endif

                OsIsrLevel |= OSISRLEVELALMCALLBACK;
                userAlmId->callBack ();
                OsIsrLevel &= (OSISRLEVELTYPE) (~OSISRLEVELALMCALLBACK);

                #if defined(OSGETSERVICEID)
                OsService = tmpId;
                #endif
            }
            else
            #endif  /* defined(OSALMCALLBACK) */
            #if defined(OSALMINCCOUNTER)
            if (userAlmId->ctrIndexInc != OSCTR0)
            {
                OsCtrIncValue[userAlmId->ctrIndexInc - OSNHWCTRS]++;
                OsCtrIncCounter++;
            }
            else
            #endif  /* defined(OSALMINCCOUNTER) */
            {
                #if defined(OSAPPLICATION)
                OSNotifyAlarmAction (&userAlmId->action, userAlmId->appId);     /* perform alarm action */
                #else
                OSNotifyAlarmAction (&userAlmId->action);       /* perform alarm action */
                #endif
            }
            #endif /* (OSNUSERALMS > 0U) */

            if (almId->cycle == 0U)
            {                   /* remove alarm from list if it is not cyclic */
                (almId->prev)->next = almId->next;
                if (almId->next != OSALMCBPTR0) /* Is it alarme last in the list ? */
                {
                    (almId->next)->prev = almId->prev;
                }
                almId->prev = OSALMCBPTR0;      /* It is necessary for check E_OS_STATE */
            }
            else
            {
                /* reinsert alarm if it is cyclic   */

                if ((OsCountersCfg[ctrInd].maxallowedvalue - *delta) < almId->cycle)
                {
                    /* if next counter value for cyclic alarm is higher than maxallowedvalue */
                    *delta += (almId->cycle - OsCountersCfg[ctrInd].maxallowedvalue) - 1U;
                }
                else
                {
                    *delta += almId->cycle;
                }
            }
            #if defined(OSSCHEDULETABLES)
            if (newAlmId != OSALMCBPTR0)
            {                   /* insert into head of list */
                newAlmId->next = OsCounters[ctrInd].alarm;
                OsCounters[ctrInd].alarm = newAlmId;
                newAlmId->prev = (OSAlmType) (&(OsCounters[ctrInd].alarm));     /* "previous" is counter link    */
                if (newAlmId->next != OSALMCBPTR0)      /* There are already alarms in the list */
                {
                    (newAlmId->next)->prev = newAlmId;
                }
                /*
                 * @violates @ref Os_alarm_c_REF_14_4_1 MISRA 2004 Required Rule 14.4, Use of goto is deprecated
                 */
                goto almAdded;
            }
            #endif /* defined(OSSCHEDULETABLES) */
        }
        almId = almId->next;
    }
}

/******************************************************************************
 * Function :   OSInsertAlarm
 *
 * Description: Insert alarm into list attached to counter,
 *              arm HW counter if it is the first alarm.
 *
 * Notes:       called with interrupts disabled
 *
 ******************************************************************************/
void
OSInsertAlarm (OSAlmType almId)
{
    OSWORD ctrInd;

    ctrInd = almId->ctrIndex;

    almId->next = OsCounters[ctrInd].alarm;     /* Alarm is linked into head of the list */
    OsCounters[ctrInd].alarm = almId;
    almId->prev = (OSAlmType) (&(OsCounters[ctrInd].alarm));    /* The counter node is previous for first in list */
    if (almId->next != OSALMCBPTR0)     /* There are already alarms in the list */
    {
        (almId->next)->prev = almId;
    }

    #if defined(OSHWCOUNTER)
    #if defined(OSSWCOUNTER)
    if (ctrInd < OSNHWCTRS)
    #endif
    {
        OSHWTickType time1, time2;

        time1 = OSCTRBITS (OSHWCtrGetOC (ctrInd) - OsTimVal);
        time2 = OSCTRBITS (almId->value - OsTimVal);

        if ((almId->next == OSALMCBPTR0) || (time1 > time2))
        {                       /* if new HW alarm is the first to expire */
            OSHWCtrArm (ctrInd, (OSHWTickType)almId->value); /* then arm it */
        }
        /* check if alarm(s) just expiried */
        time1 = OSCTRBITS (OSHWCtrValue (ctrInd) - OsTimVal);
        time2 = OSCTRBITS (OSHWCtrGetOC (ctrInd) - OsTimVal);

        if (time1 >= time2)
        {
            OSCounterNotify (ctrInd);
        }
    }
    #if defined(OSSWCOUNTER)
    else
    #endif
    #endif /* defined(OSHWCOUNTER) */

    #if defined(OSSWCOUNTER)
    {
        /* if the macro OS_STRICT_ABS_ALARMS defined, the alarm will expire after the next overrun of the underlying counter */
        #if !defined(OS_STRICT_ABS_ALARMS)
        if (almId->value == OSSWCtrValue (ctrInd))
        {
            OSCheckAlarms (ctrInd);

            #if defined(OSALMINCCOUNTER)
            while (OsCtrIncCounter != 0U)
            {
                OSWORD index;

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
            #endif
        }
        #endif /* !defined(OS_STRICT_ABS_ALARMS) */
    }
    #endif /* defined(OSSWCOUNTER)  */
}
#endif /* OSNALMS > 0U */

#if OSNUSERALMS > 0U
/******************************************************************************
 * Function:    OSInitAlarms
 *
 * Description: initializes user alarms
 *
 * Returns:     none
 *
 ******************************************************************************/
void 
OSInitAlarms (void)
{
    OSCARDINAL i;

    for (i = 0U; i < OSNUSERALMS; i++)
    {

        #if defined(OSAPPLICATION)
        OSALMARRAY[i].appMask = OsAlarmsCfg[i].appMask; /* copy application identification mask value */
        OSALMARRAY[i].appId = OsAlarmsCfg[i].appId;     /* copy application identification value */
        #endif

        OSALMARRAY[i].action.taskIndex = OsAlarmsCfg[i].taskIndex;
        /* for BCC1 events are not supported, action is only activate task */

        #if defined(OSALMSETEVENT)      /* events are supported if necessary */
        OSALMARRAY[i].action.event = OsAlarmsCfg[i].event;      /* if event==0 then alarm activates task 
                                                                   else it sets event for this task */
        #elif defined(OSSCTSETEVENT)
        OSALMARRAY[i].action.event = 0U; /* alarm event field is not used in this configuration */
        #endif /* defined(OSALMSETEVENT) */

        OSALMARRAY[i].ctrIndex = OsAlarmsCfg[i].ctrIndex;       /* attached Counter ID  */
        OSALMARRAY[i].prev = OSALMCBPTR0;
        OSALMARRAY[i].next = OSALMCBPTR0;

        #if defined(OSALMCALLBACK)
        OSALMARRAY[i].callBack = OsAlarmsCfg[i].callBack;
        #endif

        #if defined(OSALMINCCOUNTER)
        OSALMARRAY[i].ctrIndexInc = OsAlarmsCfg[i].ctrIndexInc;
        #endif
    }

}

#if defined(OSAPPLICATION)
/***************************************************************************
 * Function:    OSKillAppAlarms
 *
 * Description: kills all alarms of given application
 *
 * Notes:
 *
 **************************************************************************/
void
OSKillAppAlarms (OSAPPLICATIONTYPE appId)
{
    OSWORD i;
    OSALMCB *almRef;

    almRef = &OSALMARRAY[0];

    for (i = 0U; i < OSNUSERALMS; i++)
    {
        if (appId == almRef->appId)
        {
            almRef->appMask = OSGIVENAPPMASK (appId);
            if (almRef->prev != OSALMCBPTR0)
            {
                OSKillAlarm ((OSAlmType) almRef);
            }
        }
        /*
        * @violates @ref Os_alarm_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic by increment or decrement used
        */
        almRef++;
    }
}
#endif /* defined(OSAPPLICATION) */

/******************************************************************************
 * Function:    GetAlarmBase
 *
 * Description: Get the alarm base characteristics
 *
 * Return: E_OK                       no errors
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_ACCESS                access to the object denied
 ******************************************************************************/
StatusType
OS_GetAlarmBase (AlarmType almId, AlarmBaseRefType info)
{

    OSWORD ctrInd;
    OSALMCB *almRef;

    #if defined(OSCALCULATEOBJIND)
    OSWORD almInd;
    #endif

    OSOrtiSetServiceWatch (OSServiceId_GetAlarmBase);   /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK | OSISRLEVELHOOKERROR | OSISRLEVELHOOKAPPERROR | OSISRLEVELHOOKTASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_GetAlarmBase, almId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_GetAlarmBase, almId);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)
    if (OSALMIDISINVALID (almId))       /* invalid ID */
    {
        /*
         * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_GetAlarmBase, almId);
    }
    #endif

    #if defined(OSCALCULATEOBJIND)
    almInd = OS_GETOBJIND (almId);
    #endif

    almRef = &OSALMARRAY[almInd];

    /*
     * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKACCESSRIGHTS (OsAlarmsCfg[almInd].appMask, OSServiceId_GetAlarmBase, almId);

    /*
     * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKWRITEACCESS (info, sizeof (AlarmBaseType), OSServiceId_GetAlarmBase, almId);

    ctrInd = almRef->ctrIndex;
    info->maxallowedvalue = OsCountersCfg[ctrInd].maxallowedvalue;
    info->ticksperbase = OsCountersCfg[ctrInd].ticksperbase;

    #if defined(OSEXTSTATUS)
    info->mincycle = OsCountersCfg[ctrInd].mincycle;
    #endif /* defined(OSEXTSTATUS) */

    OSOrtiServiceWatchOnExit (OSServiceId_GetAlarmBase);
    return E_OK;
}

/******************************************************************************
 * Function:    OSSCGetAlarm
 *
 * Description: Get the number of tick before alarm expires
 *
 * Return: none
 ******************************************************************************/
OSINLINE_ void
OSSCGetAlarm (OSALMCB * almRef, TickRefType tickRef)
{
    OSWORD ctrInd;

    ctrInd = almRef->ctrIndex;

    #if defined(OSSWCOUNTER)
    #if defined(OSHWCOUNTER)
    if (ctrInd >= OSNHWCTRS)
    #endif
    {
        *tickRef = OSSWCtrValue (ctrInd);
    }
    #endif /* defined(OSSWCOUNTER) */

    #if defined(OSHWCOUNTER)
    #if defined(OSSWCOUNTER)
    else
    #endif /* defined(OSSWCOUNTER) */
    {
        *tickRef = OSHWCtrValue (ctrInd);
    }
    #endif /* defined(OSHWCOUNTER) */

    if (almRef->value >= *tickRef)
    {
        *tickRef = almRef->value - *tickRef;
    }
    else
    {
        *tickRef = (almRef->value + OsCountersCfg[ctrInd].maxallowedvalue + 1U) - *tickRef;
    }
}


/******************************************************************************
 * Function:    GetAlarm
 *
 * Description: Get the number of tick before alarm expires
 *
 * Return: E_OK                       no errors
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_NOFUNC                not used alarm
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_ACCESS                access to the object denied
 ******************************************************************************/
StatusType
OS_GetAlarm (AlarmType almId, TickRefType tickRef)
{

    OSALMCB *almRef;
    OSIMSAVE                    /* OSINTMASKTYPE save; */
    #if defined(OSCALCULATEOBJIND)
    OSWORD almInd;
    #endif

    OSOrtiSetServiceWatch (OSServiceId_GetAlarm);       /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK | OSISRLEVELHOOKERROR | OSISRLEVELHOOKAPPERROR | OSISRLEVELHOOKTASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_GetAlarm, almId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_GetAlarm, almId);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)
    if (OSALMIDISINVALID (almId))       /* invalid ID */
    {
        /*
         * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_GetAlarm, almId);
    }
    #endif

    #if defined(OSCALCULATEOBJIND)
    almInd = OS_GETOBJIND (almId);
    #endif

    almRef = &OSALMARRAY[almInd];


    /*
     * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKWRITEACCESS (tickRef, sizeof (TickType), OSServiceId_GetAlarm, almId);

    {
        OSDIS (save);
        /*
         * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSCHECKACCESSRIGHTSRI (almRef->appMask, OSServiceId_GetAlarm, almId);
        if (almRef->prev == OSALMCBPTR0)        /* Alarm is not linked in the list - not used alarm */
        {                       /* The alarm is not used */
            OSRI (save);
            /*
             * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_NOFUNC, OSServiceId_GetAlarm, almId);
        }
        OSSCGetAlarm (almRef, tickRef);
        OSOrtiServiceWatchOnExit (OSServiceId_GetAlarm);
    }
    OSRI (save);
    return E_OK;
}

#if defined(OSAUTOALARMS)
/***************************************************************************
 * Function :   OSInitAutoAlarms
 *
 * Description: Initialize autostarted alarms
 *
 * Notes:       used only by OSStartUp
 *
 **************************************************************************/
#if (OSNAPPMODES > 1U)
void 
OSInitAutoAlarms (AppModeType mode)
#else /* (OSNAPPMODES > 1U) */
void 
OSInitAutoAlarms (void)
#endif /* (OSNAPPMODES > 1U) */
{

    OSCARDINAL i;
    OSWORD ctrInd;
    OSALMCB *almId;
    TickType start;

    for (i = 0U; i < OSNAUTOALMS; i++)
    {

        #if (OSNAPPMODES > 1U)
        if ((OsAutoAlarms[i].autostart & (OSDWORD)((OSDWORD)1U << mode)) != 0U)
        {
        #endif /* (OSNAPPMODES > 1U) */

            almId = OsAutoAlarms[i].almId;
            ctrInd = almId->ctrIndex;
            start = OsAutoAlarms[i].time;

            if (OsAutoAlarms[i].type == OSALMRELATIVE)
            {
                start = OSAbsTickValue (ctrInd, start);
            }


            #if defined(OSHWCOUNTER)
            else
            {
                OSSetTimVal (ctrInd);
            }
            #endif

            /*********** insert alarm into list **************/
            almId->value = start;
            almId->cycle = OsAutoAlarms[i].cycle;

            OSInsertAlarm ((OSAlmType) almId);

        #if (OSNAPPMODES > 1U)
        }
        #endif /* (OSNAPPMODES > 1U) */
    }
}
#endif /* defined(OSAUTOALARMS) */


/******************************************************************************
 * Function:    SetRelAlarm
 *
 * Description: Start the relative alarm
 *
 * Return: E_OK                       no errors 
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_STATE                 wrong state of the object
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_VALUE                 value outside of the admissible limit
 *         E_OS_ACCESS                access to the object denied
 ******************************************************************************/
StatusType
OS_SetRelAlarm (AlarmType almId, TickType increment, TickType cycle)
{

    #if defined(OSEXTSTATUS) || defined(OSHWCOUNTER) || defined(OSSWCOUNTER)
    OSWORD ctrInd;
    #endif

    OSALMCB *almRef;
    OSIMSAVE                    /* OSINTMASKTYPE save; */

    #if defined(OSCALCULATEOBJIND)
    OSWORD almInd;
    #endif

    OSOrtiSetServiceWatch (OSServiceId_SetRelAlarm);    /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_SetRelAlarm, almId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_SetRelAlarm, almId);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    if (increment == 0U)
    {   /* zero increment value is ambiguous */
        /*
         * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_VALUE, OSServiceId_SetRelAlarm, almId);
    }

    #if defined(OSEXTSTATUS)
    if (OSALMIDISINVALID (almId))       /* invalid ID */
    {
        /*
         * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_SetRelAlarm, almId);
    }
    #endif

    #if defined(OSCALCULATEOBJIND)
    almInd = OS_GETOBJIND (almId);
    #endif

    almRef = &OSALMARRAY[almInd];

    #if defined(OSEXTSTATUS) || defined(OSHWCOUNTER) || defined(OSSWCOUNTER)
    ctrInd = almRef->ctrIndex;
    #endif

    #if defined(OSEXTSTATUS)
    /* Check initial value and cycle value */
    if (increment > OsCountersCfg[ctrInd].maxallowedvalue)      /* increment value is outside of admissible limit */
    {
        /*
         * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_VALUE, OSServiceId_SetRelAlarm, almId);
    }
    if ((cycle != 0U) &&
        ((cycle > OsCountersCfg[ctrInd].maxallowedvalue) || (cycle < OsCountersCfg[ctrInd].mincycle))
       )
    {   /* cycle value is outside of admissible limit */
        /*
         * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_VALUE, OSServiceId_SetRelAlarm, almId);
    }
    #endif /* defined(OSEXTSTATUS) */


    {
        OSDIS (save);

        /*
         * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSCHECKACCESSRIGHTSRI (almRef->appMask, OSServiceId_SetRelAlarm, almId);

        /* Check state of the alarm */
        if (almRef->prev != OSALMCBPTR0) /* Alarm is linked in the list - running alarm */
        {                                /* The alarm is already in use */
            OSRI (save);
            /*
             * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_STATE, OSServiceId_SetRelAlarm, almId);
        }

        OSOrtiSetOldServiceID (OSServiceId_SetRelAlarm);

        increment = OSAbsTickValue (ctrInd, increment);

        OSPUTPARAM (OSServiceId_SetRelAlarm, almId);
        almRef->value = increment;
        almRef->cycle = cycle;
        OSInsertAlarm ((OSAlmType) almRef);
        OSCLEARPARAM ();
        OSDISPATCH ();
    }
    OSOrtiResetIdOnExit ();
    OSRI (save);
    return E_OK;
}


/******************************************************************************
 * Function:    SetAbsAlarm
 *
 * Description: Start the alarm
 *
 * Return: E_OK                       no errors 
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_STATE                 wrong state of the object
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_VALUE                 value outside of the admissible limit
 *         E_OS_ACCESS                access to the object denied
 ******************************************************************************/
StatusType
OS_SetAbsAlarm (AlarmType almId, TickType start, TickType cycle)
{


    #if defined(OSEXTSTATUS) || defined(OSHWCOUNTER)
    OSWORD ctrInd;
    #endif

    OSALMCB *almRef;
    OSIMSAVE                    /* OSINTMASKTYPE save; */

    #if defined(OSCALCULATEOBJIND)
    OSWORD almInd;
    #endif

    OSOrtiSetServiceWatch (OSServiceId_SetAbsAlarm);    /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_SetAbsAlarm, almId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_SetAbsAlarm, almId);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)
    if (OSALMIDISINVALID (almId))       /* invalid ID */
    {
        /*
         * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_SetAbsAlarm, almId);
    }
    #endif

    #if defined(OSCALCULATEOBJIND)
    almInd = OS_GETOBJIND (almId);
    #endif

    almRef = &OSALMARRAY[almInd];

    #if defined(OSEXTSTATUS) || defined(OSHWCOUNTER)
    ctrInd = almRef->ctrIndex;
    #endif

    #if defined(OSEXTSTATUS)
    /* Check initial value and cycle value */
    if (start > OsCountersCfg[ctrInd].maxallowedvalue)  /* start value is outside of admissible limit */
    {
        /*
         * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_VALUE, OSServiceId_SetAbsAlarm, almId);
    }
    if ((cycle != 0U) &&
        ((cycle > OsCountersCfg[ctrInd].maxallowedvalue) || (cycle < OsCountersCfg[ctrInd].mincycle))
       )
    {   /* cycle value is outside of admissible limit */
        /*
         * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_VALUE, OSServiceId_SetAbsAlarm, almId);
    }
    #endif /* defined(OSEXTSTATUS) */


    {
        OSDIS (save);

        /*
         * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSCHECKACCESSRIGHTSRI (almRef->appMask, OSServiceId_SetAbsAlarm, almId);

        /* Check state of the alarm */
        if (almRef->prev != OSALMCBPTR0)        /* Alarm is linked in the list - running alarm */
        {   /* The alarm is already in use */
            OSRI (save);
            /*
             * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_STATE, OSServiceId_SetAbsAlarm, almId);
        }

        OSOrtiSetOldServiceID (OSServiceId_SetAbsAlarm);

        #if defined(OSHWCOUNTER)
        OSSetTimVal (ctrInd);
        #endif

        OSPUTPARAM (OSServiceId_SetAbsAlarm, almId);
        almRef->value = start;
        almRef->cycle = cycle;
        OSInsertAlarm ((OSAlmType) almRef);
        OSCLEARPARAM ();

        OSDISPATCH ();
    }
    OSOrtiResetIdOnExit ();
    OSRI (save);
    return E_OK;
}


 /*****************************************************************************
 * Function:    CancelAlarm
 *
 * Description: Stop the alarm
 *
 * Return: E_OK                       no errors 
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_NOFUNC                not used alarm
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_ACCESS   (ext.status) access to the object denied
 ******************************************************************************/
StatusType
OS_CancelAlarm (AlarmType almId)
{
    OSALMCB *almRef;
    OSIMSAVE                    /* OSINTMASKTYPE save; */

    #if defined(OSCALCULATEOBJIND)
    OSWORD almInd;
    #endif

    OSOrtiSetServiceWatch (OSServiceId_CancelAlarm);    /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_CancelAlarm, almId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_CancelAlarm, almId);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)
    if (OSALMIDISINVALID (almId))       /* invalid ID */
    {
        /*
         * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_CancelAlarm, almId);
    }
    #endif

    #if defined(OSCALCULATEOBJIND)
    almInd = OS_GETOBJIND (almId);
    #endif

    almRef = &OSALMARRAY[almInd];


    {
        OSDIS (save);

        /*
         * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSCHECKACCESSRIGHTSRI (almRef->appMask, OSServiceId_CancelAlarm, almId);

        if (almRef->prev == OSALMCBPTR0)      /* Alarm is not used  */
        {                       /* The alarm is not used            */
            OSRI (save);        /* attempt to multiply deactivation */
            /*
             * @violates @ref Os_alarm_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_NOFUNC, OSServiceId_CancelAlarm, almId);
        }

        OSPUTPARAM (OSServiceId_CancelAlarm, almId);
        OSKillAlarm ((OSAlmType) almRef);
        OSCLEARPARAM ();

        OSOrtiSetOldServiceID (OSServiceId_CancelAlarm);
        OSDISPATCH ();
    }
    OSOrtiResetIdOnExit ();
    OSRI (save);
    return E_OK;
}

#endif /* OSNUSERALMS > 0U */

#define OSTEXT_STOP_SEC_CODE
/*
* @violates @ref Os_alarm_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif


/** @} */
