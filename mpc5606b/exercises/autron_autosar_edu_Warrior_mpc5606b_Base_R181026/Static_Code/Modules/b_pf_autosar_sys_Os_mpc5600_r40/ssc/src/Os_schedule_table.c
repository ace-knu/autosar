/**
*   @file    Os_schedule_table.c
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
* @section Os_schedule_table_c_REF_14_7_1
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function 
* A function shall have a sigle point of exit at the end of finction.
* The returned statement is result of error hanling.
*
* @section Os_schedule_table_c_REF_17_4_1
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* Array indexing shall be the only allowed form of pointer arithmetic
* The pointers are used to increase of OS performance.
*
* @section Os_schedule_table_c_REF_19_1_1
* Violates MISRA 2004 Advisory Rule 19.1, declaration before #include
* #include statements in a file should only be preceded by other preprocessor directives or comments. 
* MemMap is required by AutoSAR to be included in the middle of the source file(s).
*
* @section Os_schedule_table_c_REF_19_7_1
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

#include <Os_schedule_table_api.h>
#include <Os_schedule_table_types.h>
#include <Os_schedule_table_internal_api.h>
#include <Os_schedule_table_internal_types.h>
#include <Os_schedule_table_config.h>

#if defined(OSSCHEDULETABLES)

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#if (OSNALMS > 0U)
#if (OSNSCTALMS > 0U) && (OSNUSERALMS == 0U)
OSSCTALMCB OsSCTAlarms[OSNSCTALMS];
#endif
#endif /* (OSNALMS > 0U) */

OSSCTCB OsScheduleTables[OSNSCTS];

#define OS_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_schedule_table_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#define OSTEXT_START_SEC_CODE
/*
* @violates @ref Os_schedule_table_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

/*
* @violates @ref Os_schedule_table_c_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define OSSctCBGetStatus(s) ((s) & OSSCTCBSTATUS)       /* get Schedule Table status */
/*
* @violates @ref Os_schedule_table_c_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define OSSctCBSetStatus(t,s) ( *((ScheduleTableStatusType*)&(t) + 1U) = (s) )   /* set Schedule Table status */

/* Prototypes */
static void OSStartScheduleTable (OSSCTCB * sctCB, TickType absval);

/******************************************************************************
 * Function:    OSInitScheduleTables
 *
 * Description: Initializes schedule tables
 *
 * Returns:     none
 *
 * Notes: 
 ******************************************************************************/
void
OSInitScheduleTables (void)
{
    OSCARDINAL i;

    for (i = 0U; i < OSNSCTS; i++)       /* Note that OSNSCTS is equal to OSNSCTALMS */
    {
        OSALMSCTARRAY[i].ctrIndex = OsScheduleTablesCfg[i].ctrIndex;    /* attached Counter ID  */
        OSALMSCTARRAY[i].prev = OSALMCBPTR0;
        OSALMSCTARRAY[i].next = OSALMCBPTR0;

        OsScheduleTables[i].nextId = OSSCT0;
        OsScheduleTables[i].almId = &OSALMSCTARRAY[i];

        #if defined(OSSCTSYNCEXPLICIT)
        OsScheduleTables[i].precision = OsScheduleTablesCfg[i].precision;
        OsScheduleTables[i].length = OsScheduleTablesCfg[i].length;
        #endif /* defined(OSSCTSYNCEXPLICIT) */
        OsScheduleTables[i].ctrIndex = OsScheduleTablesCfg[i].ctrIndex;

        OsScheduleTables[i].initialOffset = OsScheduleTablesCfg[i].initialOffset;

        #if defined(OSSCTSYNCEXPLICIT)
        OsScheduleTables[i].deviation = 0U;
        #endif
        OsScheduleTables[i].firstEP = OsScheduleTablesCfg[i].firstEP;
        OsScheduleTables[i].state = (OSWORD)(((OSWORD)OsScheduleTablesCfg[i].opts) << OSSCTCFGBITS) & OSSCTSTATE;
        #if defined(OSAPPLICATION)
        OsScheduleTables[i].appMask = OsScheduleTablesCfg[i].appMask;
        OsScheduleTables[i].appId = OsScheduleTablesCfg[i].appId;
        #endif
    }
}

/***************************************************************************
 * inline function :   OSKillScheduleTable
 *
 * Description: Kills Schedule Table with given pointer
 *
 * Returns:     nothing
 *
 * Notes:       none
 *
 **************************************************************************/
static OSINLINE void
OSKillScheduleTable (OSSCTCB * sctCB)
{
    if (sctCB->nextId != OSSCT0)
    {   /*  state of 'next' Schedule Table is changed to SCHEDULETABLE_STOPPED (OS453) */
        /*
        * @violates @ref Os_schedule_table_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        OSSctCBSetStatus (sctCB->nextId->state, SCHEDULETABLE_STOPPED);
        sctCB->nextId = OSSCT0; /* invalidate 'next' Schedule Table */
    }

    if (sctCB->almId->prev != OSALMCBPTR0)      /* check that alarm is set */
    {
        OSKillAlarm ((OSAlmType) sctCB->almId);
    }

    /*
    * @violates @ref Os_schedule_table_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    OSSctCBSetStatus (sctCB->state, SCHEDULETABLE_STOPPED);
}

#if defined(OSAPPLICATION)
/***************************************************************************
 * Function:    OSKillAppScheduleTables
 *
 * Description: kills all schedule tables of given application
 *
 * Notes:
 *
 **************************************************************************/
void
OSKillAppScheduleTables (OSAPPLICATIONTYPE appId)
{
    OSDWORD i;
    OSSCTCB *sctCB;

    for (i = 0U; i < OSNSCTS; i++)
    {
        sctCB = &OsScheduleTables[i];
        if (sctCB->appId == appId)
        {
            sctCB->appMask = OSGIVENAPPMASK (appId);
            OSKillScheduleTable (sctCB);
        }
    }
}
#endif /* defined(OSAPPLICATION) */

/***************************************************************************
 * Function :   OSStartScheduleTable
 *
 * Description: 
 *
 * Notes:
 *
 **************************************************************************/
static void
OSStartScheduleTable (OSSCTCB * sctCB, TickType absval)
{
    sctCB->currentEP = sctCB->firstEP;  /* current action */

    /* OSSCTCBSYNCUP shall be remained(can be set by prev.Schedule Table for (OS505)) */
    sctCB->state &= ((OSWORD)(~OSSCTCBSTATUS) | OSSCTCBSYNCUP);
    sctCB->state |= SCHEDULETABLE_RUNNING;

    #if defined(OSSCTSYNCIMPLICIT)
    if ((sctCB->state & OSSCTCFGIMPLMASK) != 0U) /* for IMPLICIT Schedule Table */
    {
        /*
        * @violates @ref Os_schedule_table_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        OSSctCBSetStatus (sctCB->state, SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS);
    }
    #endif

    sctCB->almId->value = absval;
    sctCB->almId->cycle = 0U;

    #if defined(OSSCTSYNCEXPLICIT)
    sctCB->deviation = 0U;      /* for start of Schedule Table via 'next' */
    #endif
}

/***************************************************************************
 * Function :   OSProcessScheduleTable
 *
 * Description: Check notification parameters of the Schedule Tables
 *              expiry points, and perform notification
 *
 * Returns:     valid new almId if next Schedule Tables started, otherwise
 *              OSALM0
 *
 **************************************************************************/
OSAlmType
OSProcessScheduleTable (OSSCTALMCB * almId)
{
    OSSCTCB * sctCB;        /* current Schedule Table */
    OSSCTEPREF sctEP;
    OSAlmType newAlmId = OSALM0;

    #if defined(OSSCTSYNCEXPLICIT)
    TickType adj;               /*  current adjustment value */
    #endif
    /*
    * @violates @ref Os_schedule_table_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    sctCB = &OsScheduleTables[almId - &OSALMSCTARRAY[0]];
    sctEP = sctCB->currentEP;

    do  /* Actions for all expiry points with equal offsets */
    {
        if (sctCB->state & OSSCTCBEND)
        {
            OSSCTCB *nextId = sctCB->nextId;

            if (nextId != OSSCT0)
            {
                if (OSSctCBGetStatus (nextId->state) == SCHEDULETABLE_NEXT)
                {
                    OSStartScheduleTable (nextId, almId->value);    /* in almId->value - current counter value */
                    newAlmId = (OSAlmType) nextId->almId;   /* almId for 'next' Schedule Table */

                    #if defined(OSSCTSYNCEXPLICIT)
                    if ((nextId->state & OSSCTCBSYNCUP) != 0U)
                    {
                        if (OSSctCBGetStatus (sctCB->state) == SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS)
                        {
                            nextId->state &= ((~OSSCTCBSTATUS) | OSSCTCBSYNCUP);    /* remain OSSCTCBSYNCUP */
                            /* the 'next' Schedule Table gets a synchronous status */
                            nextId->state |= SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
                        }
                        if (sctCB->deviation > 0U)
                        {
                            nextId->deviation = sctCB->deviation;   /* remained Deviation from prev.Schedule Table (OS505) */
                            if (nextId->deviation >= nextId->precision)
                            {
                                nextId->state &= ((~OSSCTCBSTATUS) | OSSCTCBSYNCUP);        /* remain OSSCTCBSYNCUP */
                                /* the 'next' Schedule Table is remained in asynchronous status */
                                nextId->state |= SCHEDULETABLE_RUNNING;
                            }
                            if (sctCB->state & OSSCTCBDIRSIGN)
                            {
                                nextId->state |= OSSCTCBDIRSIGN;    /* set flag of sync.direction from prev.Schedule Table */
                            }
                        }
                    }
                    #endif
                }
                sctCB->nextId = OSSCT0;

                /*
                * @violates @ref Os_schedule_table_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
                */
                OSSctCBSetStatus (sctCB->state, SCHEDULETABLE_STOPPED);
                almId->cycle = 0U;
                /*
                 * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
                 */
                return newAlmId;
            }
            if ((sctCB->state & OSSCTCFGPERIODICMASK) == 0U) /* check that Schedule Table is non periodic */
            {
                /*
                * @violates @ref Os_schedule_table_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
                */
                OSSctCBSetStatus (sctCB->state, SCHEDULETABLE_STOPPED);
                almId->cycle = 0U;
                /*
                 * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
                 */
                return newAlmId;
            }

            sctCB->state &= ~OSSCTCBEND;
        }

        almId->cycle = sctEP->delta;    /* new time to next EP */

        #if defined(OSSCTSYNCEXPLICIT)
        if (almId->cycle != 0U)
        {
            if ((sctCB->state & OSSCTCFGEXPLMASK) != 0U)
            {   /* Schedule Table configured with EXPLICIT synchronization */
                if ((sctCB->state & OSSCTCBSYNCUP) != 0U)        /* check flag of sync.correction */
                {
                    if (sctCB->deviation != 0U)
                    {   /* it is an additional condition for status change */
                        if (sctCB->deviation < sctCB->precision)
                        {
                            sctCB->state &= ~OSSCTCBSTATUS;     /* the Schedule Table gets a synchronous status */
                            sctCB->state |= SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
                        }

                        if ((sctCB->state & OSSCTCBDIRSIGN) != 0U)
                        {
                            adj = ((OSSCTEPEXPL *) sctEP)->maxRetard;   /* Retard value */
                        }
                        else
                        {
                            adj = ((OSSCTEPEXPL *) sctEP)->maxAdvance;  /* Advance value */
                        }
                        if (sctCB->deviation < adj)
                        {   /* deviation is less than correction value, correct it to zero */
                            adj = sctCB->deviation;
                        }
                        sctCB->deviation -= adj;        /* deviation is corrected */

                        if ((sctCB->state & OSSCTCBDIRSIGN) != 0U)
                        {   /* decrease of Delay */
                            almId->cycle = sctEP->delta - adj;  /* Delay is always greater, it's checked by SG */
                        }
                        else
                        {
                            almId->cycle = sctEP->delta + adj;  /* increase of Delay */
                        }
                    }
                    else
                    {   /* the Schedule Table gets a synchronous status */
                        sctCB->state &= ~(OSSCTCBSTATUS | OSSCTCBSYNCUP);
                        sctCB->state |= SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
                    }
                }
            }
        }
        #endif /* defined(OSSCTSYNCEXPLICIT) */

        #if defined(OSSCTNULLPOINT)
        if (sctEP->action.taskIndex != OSNTSKS)
        #endif
        {   /* it is not a null-point */
            #if defined(OSAPPLICATION)
            OSNotifyAlarmAction ((OSALMACTPTR) & sctEP->action, sctCB->appId);  /* perform alarm action */
            #else
            OSNotifyAlarmAction ((OSALMACTPTR) & sctEP->action);
            #endif
        }

        sctEP = sctEP->next;    /* set pointer to the next EP */
        sctCB->currentEP = sctEP;
        #if (OSORTIDEBUGLEVEL > 0U)
        sctCB->ortiEPoffset = ((OSSCTEP *) sctEP)->offset;      /* save EP offset for ORTI */
        #endif
        if (sctEP == sctCB->firstEP)
        {
            sctCB->state |= OSSCTCBEND; /* it's a last EP */

        }
    }
    while (almId->cycle == 0U);

    return newAlmId;
}

/* Public services */


/*****************************************************************************
 * Function:    StartScheduleTableAbs
 *
 * Description: Start the processing of a Schedule Table at its first
 *              expiry point after the underlaying counter reaches
 *              <tickvalue>
 *
 * Return: E_OK                       no errors 
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_VALUE                 value outside of the admissible limit
 *         E_OS_ACCESS                access to the object denied
 *         E_OS_STATE                 wrong state of the object
 ****************************************************************************/
StatusType
OS_StartScheduleTableAbs (ScheduleTableType sctId, TickType tickvalue)
{
    OSSCTCB *sctCB;
    #if defined(OSEXTSTATUS) || defined(OSHWCOUNTER)
    OSWORD ctrInd;
    #endif
    OSIMSAVE                    /* OSINTMASKTYPE save; */
    OSOrtiSetServiceWatch (OSServiceId_StartScheduleTableAbs);      /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_StartScheduleTableAbs, sctId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_StartScheduleTableAbs, sctId);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)
    if (OSSCTIDISINVALID (sctId))
    {
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_StartScheduleTableAbs, sctId);
    }
    #endif /* defined(OSEXTSTATUS) */

    sctCB = &OsScheduleTables[OS_GETOBJIND (sctId)];
    #if defined(OSEXTSTATUS) || defined(OSHWCOUNTER)
    ctrInd = sctCB->ctrIndex;
    #endif

    #if defined(OSEXTSTATUS)
    if (tickvalue > OsCountersCfg[ctrInd].maxallowedvalue)
    {
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_VALUE, OSServiceId_StartScheduleTableAbs, sctId);
    }
    #endif /* defined(OSEXTSTATUS) */

    {
        OSDIS (save);
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSCHECKACCESSRIGHTSRI (sctCB->appMask, OSServiceId_StartScheduleTableAbs, sctId);
        if (OSSctCBGetStatus (sctCB->state) != SCHEDULETABLE_STOPPED)
        {   /* if Schedule Table is already started('waiting' inclusive) or 'next' */
            OSRI (save);
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_STATE, OSServiceId_StartScheduleTableAbs, sctId);
        }

        #if defined(OSHWCOUNTER)
        OSSetTimVal (ctrInd);
        #endif

        OSPUTPARAM (OSServiceId_StartScheduleTableAbs, sctId);
        OSStartScheduleTable (sctCB, tickvalue);
        OSInsertAlarm ((OSAlmType) sctCB->almId);
        OSCLEARPARAM ();

        OSOrtiSetOldServiceID (OSServiceId_StartScheduleTableAbs);
        OSDISPATCH ();
    }
    OSOrtiResetIdOnExit ();
    OSRI (save);
    return E_OK;
}


/******************************************************************************
 * Function:    StartScheduleTableRel
 *
 * Description: Start the processing of a Schedule Table at its first
 *              expiry point after offset <offset> ticks have elapsed
 *
 * Return: E_OK                       no errors 
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_VALUE                 value outside of the admissible limit
 *         E_OS_ACCESS                access to the object denied
 *         E_OS_STATE                 wrong state of the object
 ******************************************************************************/
StatusType
OS_StartScheduleTableRel (ScheduleTableType sctId, TickType increment)
{
    OSSCTCB *sctCB;
    OSWORD ctrInd;
    OSIMSAVE                    /* OSINTMASKTYPE save;       */
    OSOrtiSetServiceWatch (OSServiceId_StartScheduleTableRel);      /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_StartScheduleTableRel, sctId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_StartScheduleTableRel, sctId);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)
    if (OSSCTIDISINVALID (sctId))
    {
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_StartScheduleTableRel, sctId);
    }
    #endif /* defined(OSEXTSTATUS) */

    sctCB = &OsScheduleTables[OS_GETOBJIND (sctId)];
    ctrInd = sctCB->ctrIndex;

    #if defined(OSEXTSTATUS)
    #if defined(OSSCTSYNCIMPLICIT)
    if ((sctCB->state & OSSCTCFGIMPLMASK) != 0U)
    {   /* Schedule Table is implicitly synchronized */
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_StartScheduleTableRel, sctId);
    }
    #endif

    if ( (increment == 0U) || (increment > (OsCountersCfg[ctrInd].maxallowedvalue
                               - sctCB->initialOffset        /* OS276 */
       )))
    {
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_VALUE, OSServiceId_StartScheduleTableRel, sctId);
    }
    #endif /* defined(OSEXTSTATUS) */

    {
        OSDIS (save);

        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSCHECKACCESSRIGHTSRI (sctCB->appMask, OSServiceId_StartScheduleTableRel, sctId);

        if (OSSctCBGetStatus (sctCB->state) != SCHEDULETABLE_STOPPED)
        {   /* if Schedule Table is already started('waiting' inclusive) or 'next' */
            OSRI (save);
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_STATE, OSServiceId_StartScheduleTableRel, sctId);
        }

        increment = OSAbsTickValue (ctrInd, increment);

        OSPUTPARAM (OSServiceId_StartScheduleTableRel, sctId);
        OSStartScheduleTable (sctCB, increment);
        OSInsertAlarm ((OSAlmType) sctCB->almId);
        OSCLEARPARAM ();

        OSOrtiSetOldServiceID (OSServiceId_StartScheduleTableRel);
        OSDISPATCH ();
    }
    OSOrtiResetIdOnExit ();
    OSRI (save);
    return E_OK;
}


/******************************************************************************
 * Function:    StopScheduleTable
 *
 * Description: Stop the Schedule Table from processing any further
 *              expiry points
 *
 * Return: E_OK                       no errors 
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_NOFUNC                already stopped Schedule Table
 *         E_OS_ACCESS                access to the object denied
 ******************************************************************************/
StatusType
OS_StopScheduleTable (ScheduleTableType sctId)
{
    OSSCTCB *sctCB;

    OSIMSAVE                    /* OSINTMASKTYPE save;       */
    OSOrtiSetServiceWatch (OSServiceId_StopScheduleTable);  /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_StopScheduleTable, sctId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_StopScheduleTable, sctId);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)
    if (OSSCTIDISINVALID (sctId))
    {
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_StopScheduleTable, sctId);
    }
    #endif /* defined(OSEXTSTATUS) */

    sctCB = &OsScheduleTables[OS_GETOBJIND (sctId)];

    {
        OSDIS (save);
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSCHECKACCESSRIGHTSRI (sctCB->appMask, OSServiceId_StopScheduleTable, sctId);
        if (OSSctCBGetStatus (sctCB->state) == SCHEDULETABLE_STOPPED)
        {                       /* Schedule Table was already stopped */
            OSRI (save);
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_NOFUNC, OSServiceId_StopScheduleTable, sctId);
        }

        OSPUTPARAM (OSServiceId_StopScheduleTable, sctId);
        OSKillScheduleTable (sctCB);
        OSCLEARPARAM ();

        OSOrtiSetOldServiceID (OSServiceId_StopScheduleTable);
        OSDISPATCH ();
    }
    OSOrtiResetIdOnExit ();
    OSRI (save);
    return E_OK;
}

/******************************************************************************
 * Function: NextScheduleTable
 *
 * Description: Start the processing of Schedule Table <sctId_next>
 *              after <sctId_current> reaches its period/length
 *
 * Return: E_OK                       no errors 
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_NOFUNC                already stopped Schedule Table
 *         E_OS_STATE                 wrong state of the object
 *         E_OS_ACCESS                access to the object denied
 ******************************************************************************/
StatusType
OS_NextScheduleTable (ScheduleTableType sctId_current, ScheduleTableType sctId_next)
{
    OSSCTCB *sctCB_current;
    OSSCTCB *sctCB_next;

    OSIMSAVE                    /* OSINTMASKTYPE save; */
    OSOrtiSetServiceWatch (OSServiceId_NextScheduleTable);  /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_NextScheduleTable, sctId_current);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_NextScheduleTable, sctId_current);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)
    if (OSSCTIDISINVALID (sctId_next) || OSSCTIDISINVALID (sctId_current))
    {
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_NextScheduleTable, sctId_current);
    }
    #endif /* defined(OSEXTSTATUS) */

    sctCB_current = &OsScheduleTables[OS_GETOBJIND (sctId_current)];
    sctCB_next = &OsScheduleTables[OS_GETOBJIND (sctId_next)];


    OSDIS (save);
    /*
     * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKACCESSRIGHTSRI (sctCB_current->appMask, OSServiceId_NextScheduleTable, sctId_current);
    /*
     * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKACCESSRIGHTSRI (sctCB_next->appMask, OSServiceId_NextScheduleTable, sctId_current);
    #if defined(OSEXTSTATUS)
    if (sctCB_current->ctrIndex != sctCB_next->ctrIndex)
    {
        OSRI (save);
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_NextScheduleTable, sctId_current);
    }
    #endif /* defined(OSEXTSTATUS) */
    if (OSSctCBGetStatus (sctCB_next->state) != SCHEDULETABLE_STOPPED)
    {                           /* 'next' Schedule Table is already started or next */
        OSRI (save);
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_STATE, OSServiceId_NextScheduleTable, sctId_current);
    }
    if ((OSSctCBGetStatus (sctCB_current->state) == SCHEDULETABLE_STOPPED) ||
        (OSSctCBGetStatus (sctCB_current->state) == SCHEDULETABLE_NEXT))
    {
        OSRI (save);
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_NOFUNC, OSServiceId_NextScheduleTable, sctId_current);
    }
    #if defined(OSSCTSYNCEXPLICIT) || (defined(OSEXTSTATUS) && defined(OSSCTSYNCIMPLICIT))
    /* check that the both Schedule Tables are configured with sync.strategy */
    if (((sctCB_current->state & OSSCTCFGSTRATMASK) != 0U) && ((sctCB_next->state & OSSCTCFGSTRATMASK) != 0U))
    {
    #if defined(OSEXTSTATUS)
        if ((sctCB_current->state & sctCB_next->state & OSSCTCFGSTRATMASK) == 0U)
        {   /* strategies are not equal (OS484) */
            OSRI (save);
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_ID, OSServiceId_NextScheduleTable, sctId_current);
        }
    #endif
    #if defined(OSSCTSYNCEXPLICIT)
        if ((sctCB_current->state & OSSCTCFGEXPLMASK) == (sctCB_next->state & OSSCTCFGEXPLMASK))
        {
            if (sctCB_current->length == sctCB_next->length)    /* lengths are equal */
            {
                if ((sctCB_current->state & OSSCTCBSYNCUP) != 0U)
                {
                    sctCB_next->state |= OSSCTCBSYNCUP; /* continue synchronization of the 'next' Schedule Table (OS505) */
                }
            }
        }
    #endif /* defined(OSSCTSYNCEXPLICIT) */
    }
    #endif /* defined(OSSCTSYNCEXPLICIT) || (defined(OSEXTSTATUS) && defined(OSSCTSYNCIMPLICIT)) */

    if (sctCB_current->nextId != OSSCT0)        /* restore status of previous 'next' Schedule Table (OS324) */
    {
        /*
        * @violates @ref Os_schedule_table_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        OSSctCBSetStatus (sctCB_current->nextId->state, SCHEDULETABLE_STOPPED);
    }

    sctCB_current->nextId = sctCB_next; /* save 'next' */

    sctCB_next->state &= ~OSSCTCBSTATUS;
    sctCB_next->state |= SCHEDULETABLE_NEXT;

    OSOrtiServiceWatchOnExit (OSServiceId_NextScheduleTable);
    OSRI (save);

    return E_OK;
}

/******************************************************************************
 * Function:    StartScheduleTableSynchron
 *
 * Description: It is used for processing of Schedule Table at first expiry point after the 
 *              global time is set.
 *
 * Return: E_OK                       no errors 
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_STATE                 wrong state of the object
 *         E_OS_ACCESS                access to the object denied
 ******************************************************************************/
StatusType
OS_StartScheduleTableSynchron (ScheduleTableType sctId)
{
    #if defined(OSCWPPC)
    #pragma unused( sctId ) /* to suppress warning about unused variable */
    #endif

    #if defined(OSSCTSYNCEXPLICIT)
    OSSCTCB *sctCB;
    OSIMSAVE                    /* OSINTMASKTYPE save;       */
    #endif
    /* defined(OSSCTSYNCEXPLICIT) */
    OSOrtiSetServiceWatch (OSServiceId_StartScheduleTableSynchron); /* set watch to this service */

    #if !defined(OSSCTSYNCEXPLICIT)
    #if defined(OSEXTSTATUS)
    /*
     * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSRETERROR (E_OS_ID, OSServiceId_StartScheduleTableSynchron, sctId);
    #else
    OSOrtiServiceWatchOnExit (OSServiceId_StartScheduleTableSynchron);
    /*
     * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    return E_OK;
    #endif

    #else /* !defined(OSSCTSYNCEXPLICIT) */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_StartScheduleTableSynchron, sctId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_StartScheduleTableSynchron, sctId);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)
    if (OSSCTIDISINVALID (sctId))
    {
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_StartScheduleTableSynchron, sctId);
    }
    #endif

    sctCB = &OsScheduleTables[OS_GETOBJIND (sctId)];


    #if defined(OSEXTSTATUS)
    if ((sctCB->state & OSSCTCFGEXPLMASK) == 0U) /* Schedule Table can't be synchronized */
    {
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_StartScheduleTableSynchron, sctId);
    }
    #endif /* defined(OSEXTSTATUS) */

    OSDIS (save);
    /*
     * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKACCESSRIGHTSRI (sctCB->appMask, OSServiceId_StartScheduleTableSynchron, sctId);
    if (OSSctCBGetStatus (sctCB->state) != SCHEDULETABLE_STOPPED)
    {   /* Schedule Table was already started */
        OSRI (save);
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_STATE, OSServiceId_StartScheduleTableSynchron, sctId);
    }


    /*
    * @violates @ref Os_schedule_table_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    OSSctCBSetStatus (sctCB->state, SCHEDULETABLE_WAITING);     /* the Schedule Table gets the waiting status */

    OSRI (save);

    OSOrtiServiceWatchOnExit (OSServiceId_StartScheduleTableSynchron);
    return E_OK;

    #endif /* !defined(OSSCTSYNCEXPLICIT) */
}

/******************************************************************************
 * Function:    SyncScheduleTable
 *
 * Description: It is used to synchronize the processing of the
 *              Schedule Table to global time.
 *
 * Return: E_OK                       no errors 
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_STATE                 wrong state of the object
 *         E_OS_VALUE                 value outside of the admissible limit
 *         E_OS_ACCESS                access to the object denied
 ******************************************************************************/
StatusType
OS_SyncScheduleTable (ScheduleTableType sctId, GlobalTimeTickType globalTime)
{
    #if defined(OSCWPPC)
    #pragma unused( sctId, globalTime ) /* to suppress warning about unused variable */
    #endif

    #if defined(OSSCTSYNCEXPLICIT)
    OSSCTCB *sctCB;

    TickType ctrValue;
    OSWORD ctrInd;
    TickType deltaTime, dev1, dev2;     /* auxiliary variables */

    OSIMSAVE                    /* OSINTMASKTYPE save */
    #endif /* defined(OSSCTSYNCEXPLICIT) */
    
    OSOrtiSetServiceWatch (OSServiceId_SyncScheduleTable);  /* set watch to this service */

    #if !defined(OSSCTSYNCEXPLICIT)
    #if defined(OSEXTSTATUS)
    /*
     * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSRETERROR (E_OS_ID, OSServiceId_SyncScheduleTable, sctId);
    #else
    OSOrtiServiceWatchOnExit (OSServiceId_SyncScheduleTable);
    /*
     * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    return E_OK;
    #endif

    #else /* !defined(OSSCTSYNCEXPLICIT) */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_SyncScheduleTable, sctId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_SyncScheduleTable, sctId);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)
    if (OSSCTIDISINVALID (sctId))
    {
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_SyncScheduleTable, sctId);
    }
    #endif /* defined(OSEXTSTATUS) */

    sctCB = &OsScheduleTables[OS_GETOBJIND (sctId)];
    ctrInd = sctCB->ctrIndex;


    OSDIS (save);
    /*
     * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKACCESSRIGHTSRI (sctCB->appMask, OSServiceId_SyncScheduleTable, sctId);
    /* fix the counter value as soon as possible! */
    #if defined(OSSWCOUNTER)
    #if defined(OSHWCOUNTER)
    if (ctrInd >= OSNHWCTRS)
    #endif
    {
        ctrValue = OSSWCtrValue (ctrInd);       /* get counter value for SW counter */
    }
    #endif /* defined(OSSWCOUNTER) */

    #if defined(OSHWCOUNTER)
    #if defined(OSSWCOUNTER)
    else
    #endif
    {
        ctrValue = OSHWCtrValue (ctrInd);       /* get counter value for HW counter */
    }
    #endif /* defined(OSHWCOUNTER) */

    #if defined(OSEXTSTATUS)
    if ((sctCB->state & OSSCTCFGEXPLMASK) == 0U) /* the Schedule Table can not be synchronized */
    {
        OSRI (save);
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_SyncScheduleTable, sctId);
    }
    #endif /* defined(OSEXTSTATUS) */

    #if defined(OSEXTSTATUS)        /* global time can not be more than Schedule Table length */
    if (globalTime >= sctCB->length)
    {
        OSRI (save);
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_VALUE, OSServiceId_SyncScheduleTable, sctId);
    }
    #endif /* defined(OSEXTSTATUS) */
    if ((OSSctCBGetStatus (sctCB->state) == SCHEDULETABLE_STOPPED) || (OSSctCBGetStatus (sctCB->state) == SCHEDULETABLE_NEXT))
    {                           /* if Schedule Table hasn't been started or in next status(OS363) */
        OSRI (save);
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_STATE, OSServiceId_SyncScheduleTable, sctId);
    }

    if (OSSctCBGetStatus (sctCB->state) == SCHEDULETABLE_WAITING)
    {   /* StartScheduleTableSynchron() has been called */
        deltaTime = sctCB->length - globalTime; /* start of the Schedule Table should be set to zero of this table */

        deltaTime = OSAbsTickValue (ctrInd, deltaTime);

        /* restart of the Schedule Table from WAITING state */
        OSStartScheduleTable (sctCB, deltaTime);
        OSInsertAlarm ((OSAlmType) sctCB->almId);

        {   /* in this case the Schedule Table gets a synchronous status */
            /*
            * @violates @ref Os_schedule_table_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            OSSctCBSetStatus (sctCB->state, SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS);
        }

        OSOrtiSetOldServiceID (OSServiceId_SyncScheduleTable);
        OSDISPATCH ();
        OSOrtiResetIdOnExit ();

        OSRI (save);
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return E_OK;
    }
    /* twice for clarity only */

    /* local time = NextEP.Offset - (DriveCtr.Match - DriveCtr.Now) */
    deltaTime = sctCB->almId->value - ctrValue;

    if (ctrValue > sctCB->almId->value)
    {
        deltaTime += OsCountersCfg[ctrInd].maxallowedvalue + 1U;
    }
    if (sctCB->almId->cycle == 0U)
    {
        deltaTime = sctCB->length - (deltaTime % sctCB->length);        /* case when a local time hasn't come yet */
    }
    else
    {
        deltaTime = ((OSSCTEPEXPL *) sctCB->currentEP)->offset - deltaTime;
        if (deltaTime > sctCB->length)
        {
            deltaTime += sctCB->length;
        }
    }

    if (deltaTime == globalTime)
    {   /* the Schedule Table gets a synchronous status */
        sctCB->state &= ~(OSSCTCBSTATUS | OSSCTCBSYNCUP);
        sctCB->state |= SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
    }
    else
    {
        /* calculation of deviation and adjustment value */
        dev2 = deltaTime - globalTime;
        dev1 = globalTime - deltaTime;

        if (dev1 > sctCB->length)
        {
            dev1 += sctCB->length;
        }
        if (dev2 > sctCB->length)
        {
            dev2 += sctCB->length;
        }
        if (dev1 > dev2)
        {
            /* TableTicksAheadOfSyncCounter > TableTicksBehindOfSyncCounter */
            sctCB->state &= ~(OSSCTCBDIRSIGN);  /* flag of Delay increase */
            sctCB->deviation = dev2;
        }
        else
        {
            /* TableTicksAheadOfSyncCounter <= TableTicksBehindOfSyncCounter */
            sctCB->state |= OSSCTCBDIRSIGN;     /* flag of Delay decrease */
            sctCB->deviation = dev1;
        }
        sctCB->state &= ~OSSCTCBSTATUS;

        if (sctCB->deviation < sctCB->precision)        /* deviation is compared with PRECISSION value */
        {
            sctCB->state |= SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;      /* the Schedule Table gets sync.status */
        }
        else
        {
            sctCB->state |= SCHEDULETABLE_RUNNING;      /* the Schedule Table gets async.status */
        }

        sctCB->state |= OSSCTCBSYNCUP;  /* setting flag of the sync.correction  */
    }

    OSOrtiServiceWatchOnExit (OSServiceId_SyncScheduleTable);
    OSRI (save);

    return E_OK;
    #endif /* !defined(OSSCTSYNCEXPLICIT) */
}

/******************************************************************************
 * Function:    SetScheduleTableAsync
 *
 * Description: set the synchronization status of the sctId to asynchronous.
 *
 * Return: E_OK                       no errors 
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_STATE                 wrong state of the object
 *         E_OS_ACCESS                access to the object denied
 ******************************************************************************/
StatusType
OS_SetScheduleTableAsync (ScheduleTableType sctId)
{
    #if defined(OSCWPPC)
    #pragma unused( sctId ) /* to suppress warning about unused variable */
    #endif

    #if defined(OSSCTSYNCEXPLICIT)
    OSSCTCB *sctCB;
    OSIMSAVE            /* OSINTMASKTYPE save; */
    #endif

    OSOrtiSetServiceWatch (OSServiceId_SetScheduleTableAsync);    /* set watch to this service */

    #if !defined(OSSCTSYNCEXPLICIT)
    #if defined(OSEXTSTATUS)
    /*
     * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSRETERROR (E_OS_ID, OSServiceId_SetScheduleTableAsync, sctId);
    #else
    OSOrtiServiceWatchOnExit (OSServiceId_SetScheduleTableAsync);
    /*
     * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    return E_OK;
    #endif

    #else /* !defined(OSSCTSYNCEXPLICIT) */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_SetScheduleTableAsync, sctId);
        }
        else
        #endif
        {
           /*
            * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
            */
           OSRETERROR (E_OS_CALLEVEL, OSServiceId_SetScheduleTableAsync, sctId);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)
    if (OSSCTIDISINVALID (sctId))
    {
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_SetScheduleTableAsync, sctId);
    }
    #endif /* defined(OSEXTSTATUS) */

    sctCB = &OsScheduleTables[OS_GETOBJIND (sctId)];


    #if defined(OSEXTSTATUS)
    if ((sctCB->state & OSSCTCFGEXPLMASK) == 0U) /* Schedule Table can't be synchronized */
    {
        /*
         * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_SetScheduleTableAsync, sctId);
    }
    #endif

    OSDIS (save);
    /*
     * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKACCESSRIGHTSRI (sctCB->appMask, OSServiceId_SetScheduleTableAsync, sctId);
    if ((sctCB->state & OSSCTCFGEXPLMASK) != 0U) /* Schedule Table is EXPLICIT */
    {
        if ((OSSctCBGetStatus (sctCB->state) != SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS) &&
            (OSSctCBGetStatus (sctCB->state) != SCHEDULETABLE_RUNNING)
            )
        {
            /* applicable only for Schedule Tables with SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS or SCHEDULETABLE_RUNNING */
            OSRI (save);
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_STATE, OSServiceId_SetScheduleTableAsync, sctId);
        }
        /* the operation stops further synchronization until SyncScheduleTable() call is made (OS362) */
        sctCB->state &= ~(OSSCTCBSTATUS | OSSCTCBSYNCUP);
        if (sctCB->nextId != OSSCT0)
        {                       /* stop further synchronization for 'next' Schedule Table (OS362,OS505) */
            sctCB->nextId->state &= ~OSSCTCBSYNCUP;
        }
        /* the Schedule Table gets a running status */
        sctCB->state |= SCHEDULETABLE_RUNNING;
    }

    OSRI (save);
    OSOrtiServiceWatchOnExit (OSServiceId_SetScheduleTableAsync);

    return E_OK;

    #endif /* !defined(OSSCTSYNCEXPLICIT) */
}

/******************************************************************************
 * Function:    GetScheduleTableStatus
 *
 * Description: get the Schedule Table status
 *
 * Return: E_OK                       no errors 
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_ACCESS                access to the object denied
 ******************************************************************************/
StatusType
OS_GetScheduleTableStatus (ScheduleTableType sctId, ScheduleTableStatusRefType scheduleStatus)
{
    OSSCTCB * sctCB;

    OSOrtiSetServiceWatch (OSServiceId_GetScheduleTableStatus); /* set watch to this service */

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_GetScheduleTableStatus, sctId);
        }
        else
        #endif
        {
          /*
           * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
           */
          OSRETERROR (E_OS_CALLEVEL, OSServiceId_GetScheduleTableStatus, sctId);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)
    if (OSSCTIDISINVALID (sctId))
    {
       /*
        * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
        */
       OSRETERROR (E_OS_ID, OSServiceId_GetScheduleTableStatus, sctId);
    }
    #endif /* defined(OSEXTSTATUS) */

    sctCB = &OsScheduleTables[OS_GETOBJIND (sctId)];
    /*
     * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKACCESSRIGHTS (OsScheduleTablesCfg[OS_GETOBJIND (sctId)].appMask, OSServiceId_GetScheduleTableStatus, sctId);
    /*
     * @violates @ref Os_schedule_table_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKWRITEACCESS (scheduleStatus, sizeof (ScheduleTableStatusType), OSServiceId_GetScheduleTableStatus, sctId);

    *scheduleStatus = (ScheduleTableStatusType) OSSctCBGetStatus (sctCB->state);

    OSOrtiServiceWatchOnExit (OSServiceId_GetScheduleTableStatus);

    return E_OK;
}

#if (OSNAUTOSCTS > 0U)
/***************************************************************************
 * Function :   OSInitAutoScheduleTables
 *
 * Description: Initialize autostarted Schedule Tables
 *
 * Notes:       used only by OSStartUp
 *
 **************************************************************************/
#if (OSNAPPMODES > 1U)
void
OSInitAutoScheduleTables (AppModeType mode)
#else  /* (OSNAPPMODES > 1U) */
void
OSInitAutoScheduleTables (void)
#endif /* (OSNAPPMODES > 1U) */
{
    OSCARDINAL i;
    OSWORD ctrInd;
    TickType start;
    OSSCTCB *sctCB;
    const OSSCTAUTOTYPE *acfg;

    for (i = 0U; i < OSNAUTOSCTS; i++)
    {
        acfg = &OsAutoScheduleTablesCfg[i];
        #if (OSNAPPMODES > 1U)
        if ((acfg->autostart & (1U << mode)) != 0U)
        {
        #endif /* (OSNAPPMODES > 1U) */
            sctCB = &OsScheduleTables[acfg->sctIndex];
            ctrInd = sctCB->ctrIndex;

            if (acfg->type == OSSCTSYNCHRON)
            {
                /*
                * @violates @ref Os_schedule_table_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
                */
                OSSctCBSetStatus (sctCB->state, SCHEDULETABLE_WAITING); /* the Schedule Table gets the waiting status */
            }
            else
            {
                start = acfg->offset;
                #if defined(OSHWCOUNTER)
                if (acfg->type == OSSCTABSOLUTE)
                {
                    OSSetTimVal (ctrInd);
                }
                else
                #endif
                {
                    if (acfg->type == OSSCTRELATIVE)
                    {
                        start = OSAbsTickValue (ctrInd, start);
                    }
                }
                OSStartScheduleTable (sctCB, start);
                OSInsertAlarm ((OSAlmType) sctCB->almId);
            }
        #if (OSNAPPMODES > 1U)
        }
        #endif /* (OSNAPPMODES > 1U) */
    }
}
#endif /* defined(OSNAUTOSCTS) */

#define OSTEXT_STOP_SEC_CODE
/*
* @violates @ref Os_schedule_table_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#endif /* defined(OSSCHEDULETABLES) */


#ifdef __cplusplus
}
#endif



/** @} */
