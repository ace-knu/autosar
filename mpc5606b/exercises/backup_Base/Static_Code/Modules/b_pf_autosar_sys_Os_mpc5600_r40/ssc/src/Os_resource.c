/**
*   @file    Os_resource.c
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
* @section Os_resource_c_REF_5_1_1
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters. 
* The section identification define's naming convention is defined by AutoSar and identifiers are longer than 31 character. 
* Compilers are checked for support this length of identifiers.
*
* @section Os_resource_c_REF_14_7_1
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function 
* A function shall have a sigle point of exit at the end of finction.
* The returned statement is result of error hanling.
*
* @section Os_resource_c_REF_17_4_1
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* Array indexing shall be the only allowed form of pointer arithmetic
* The pointers are used to increase of OS performance.
*
* @section Os_resource_c_REF_19_1_1
* Violates MISRA 2004 Advisory Rule 19.1, declaration before #include
* #include statements in a file should only be preceded by other preprocessor directives or comments. 
* MemMap is required by AutoSAR to be included in the middle of the source file(s).
*
* @section Os_resource_c_REF_19_7_1
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

#include <Os_resource_api.h>
#include <Os_resource_types.h>
#include <Os_resource_internal_api.h>
#include <Os_resource_internal_types.h>
#include <Os_resource_config.h>

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSRESOURCE)
OSRESCB OsResources[OSNALLRES_];
#endif

#define OS_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_resource_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

/*
* @violates @ref Os_resource_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_START_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_resource_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if defined(OSRESOURCEISR)
OSDECLAREVAR (OSNEAR OSWORD, OsISRResourceCounter_);
#endif

/*
* @violates @ref Os_resource_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_resource_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#define OSTEXT_START_SEC_CODE
/*
* @violates @ref Os_resource_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

/*  Conditional compilation */

/*  Resource management */

/*  Private OS Services */

#if defined(OSUSERESLINK)

#define OSRESREF ((OSResType)resRef)


/******************************************************************************
 * Function:    OSReleaseTaskResource
 *
 * Description: Releases resources taken by the task
 *
 * Returns:     none
 *
 * Notes:       used for TerminateApplication service
 ******************************************************************************/
void
OSReleaseTaskResource (const OSTSKCBPTR taskPtr)
{
    OSRefResType resRef;

    while (taskPtr->resources != OSNULLREFRES)
    {
        resRef = taskPtr->resources;

        #if defined(OSRESOURCE)
        {
            #if defined(OSRESOURCEISR)
            if (OSRESREF->resPrio < 0)  /* resPrio < 0 - ISR resource */
            {
                OsISRResourceCounter--;
                if (OsISRResourceCounter == 0U)  /* It is the first ISR resource */
                {
                    OsIsrLevel &= ~OSISRRESOURCELEVEL;  /* unblock scheduler */
                }
            }
            else
            #endif
            {
                /*
                * @violates @ref Os_resource_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
                */
                OSGETTASK (OSRESREF->resPrio) = OSRESREF->prio2task;

                #if (OSNXTSKS > 0U)
                /*
                * @violates @ref Os_resource_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
                */
                if ((OSTASKSTATUS (OSPRIO2TASKID (OSRESREF->resPrio)) & (OSTCBNOSUSPENDED | OSTCBWAIT)) != OSTCBNOSUSPENDED)
                #else
                /*
                * @violates @ref Os_resource_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
                */
                if ((OSTASKSTATUS (OSPRIO2TASKID (OSRESREF->resPrio)) & OSTCBNOSUSPENDED) == 0U)
                #endif
                {
                    OSTask2Suspend (OSRESREF->resPrio); /* clear bit in OsScheduleVector */
                }
            }


            #if (OSORTIDEBUGLEVEL > 0U) || defined(OSEXTSTATUS)
            OSRESREF->isUsed = 0U;
            #endif
        }
        #endif /* defined(OSRESOURCE) */


        taskPtr->resources = resRef->nextRes;
    }
}

#if (defined(OSRESOURCEISR) || (OSNSPINLOCKS > 0U))
/******************************************************************************
 * Function:    OSReleaseISRResources
 *
 * Description: Releases resources of the ISR without any checking
 *
 * Returns:     none 
 *
 * Notes:       intended for "kill" functions
 ******************************************************************************/
void
OSReleaseISRResources (OS_ISRTYPEPTR handlerPtr)
{
    OSRefResType resRef;
    OSRefResType *resources;

    resources = &(handlerPtr->resources);

    while (*resources != OSNULLREFRES)
    {
        resRef = *resources;
        #if defined(OSRESOURCEISR)
        {

            #if (OSORTIDEBUGLEVEL > 0U) || defined(OSEXTSTATUS)
            OSRESREF->isUsed = 0U;
            #endif
            OsISRResourceCounter--;
            if (OsISRResourceCounter == 0U)      /* It is the first ISR resource */
            {
                OsIsrLevel &= ~OSISRRESOURCELEVEL;      /* unblock scheduler */
            }
        }
        #endif /* defined(OSRESOURCEISR) */


        *resources = resRef->nextRes;
    }
}

#endif /* (defined(OSRESOURCEISR) || (OSNSPINLOCKS > 0U)) */

#endif /* defined(OSUSERESLINK) */

#if defined(OSRESOURCE)


/******************************************************************************
 * Function:    OSInitResources
 *
 * Description: initializes resources
 *
 * Returns:     none
 *
 ******************************************************************************/
void
OSInitResources (void)
{
    OSCARDINAL i;


#define ind (i)

    /* resources' initialization */
    for (i = 0U; i < OSNALLRES; i++)
    {
        #if defined(OSAPPLICATION)



        OsResources[ind].appMask = OsResCfg[i].appMask;
        OsResources[ind].resPrio    = OsResCfg[i].resPrio;
        #else
        OsResources[ind].resPrio = OsResPrioTbl[ind];
        #endif       /* defined(OSAPPLICATION) */

        OsResources[ind].prio2task = OSNULLPRIOLINK;
        #if defined(OSEXTSTATUS) || (OSORTIDEBUGLEVEL > 0U)
        OsResources[ind].isUsed = 0U;
        #endif

        #if defined(OSUSERESLINK)
        OsResources[ind].nextRes = OSNULLREFRES;
        #endif       /* defined(OSUSERESLINK) */

        #if(OSORTIDEBUGLEVEL > 0U)
        OsResources[ind].curPrio = 0;
        #endif

        #if defined(OSTIMINGPROTECTION)
        #if (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U)
        OsResources[ind].tpRemained = 0U;
        OsResources[ind].tpNextRes = OSNULLRES;
        #endif
        #endif /* defined(OSTIMINGPROTECTION) */
    }

#undef ind
}

/*  Public OS Services */

/******************************************************************************
 * Function:    GetResource
 *
 * Description: occupies resource
 *
 * Return: E_OK                       no errors 
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_ACCESS                access to the object denied
 ******************************************************************************/
StatusType
OS_GetResource (ResourceType resId)
{


    volatile OSIMSAVE           /* volatile OSINTMASKTYPE save; */
    OSResType resRef;

    #if defined(OSRESOURCEISR) && defined(OSUSERESLINK)
    OSRefResType *curResRef;    /* reference to ISR or Task resource field */
    #endif


    OSOrtiSetServiceWatch (OSServiceId_GetResource);

    #if defined(OSRESOURCEISR) && defined(OSUSERESLINK)
    if (OSISRLEVELMASKED > 0U)
    {
        /*
        * @violates @ref Os_resource_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        curResRef = &(OsIsrArray[OSISRLEVELMASKED - 1U]->resources);
    }
    else
    {
        /*
        * @violates @ref Os_resource_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        curResRef = &(OsRunning->resources);
    }
    #endif


    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_resource_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_GetResource, resId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_resource_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_GetResource, resId);
        }
    }
    #endif /* OSCHECKCONTEXT */

    #if defined(OSEXTSTATUS)
    if (OSRESIDISINVALID (resId))       /* invalid ID */
    {
        /*
         * @violates @ref Os_resource_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_GetResource, resId);
    }
    #endif /* OSEXTSTATUS */

    resRef = &OsResources[OS_GETOBJIND (resId)];

    #if defined(OSEXTSTATUS)

    if (resRef->isUsed)         /* attempt to access occupied resource  */
    {
        /*
         * @violates @ref Os_resource_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ACCESS, OSServiceId_GetResource, resId);
    }

    #if defined(OSISRENTRYEXIT)
    if (OSISRLEVEL != 0U)        /* Check call level */
    {
        #if defined(OSRESOURCEISR)
        if (resRef->resPrio < 0)        /* resPrio < 0 - ISR resource */
        {
            /*
            * @violates @ref Os_resource_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            if (((OSPRIOTYPE)OsIsrArray[OSISRLEVELMASKED - 1U]->isrPrio) > (-(resRef->resPrio)))
            {   /* resource priority is lower than assigned ISR priority */
                /*
                 * @violates @ref Os_resource_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
                 */
                OSRETERROR (E_OS_ACCESS, OSServiceId_GetResource, resId);
            }
        }
        else    /* resource is not for ISR */
        #endif
        {
           /*
            * @violates @ref Os_resource_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
            */
           OSRETERROR (E_OS_ACCESS, OSServiceId_GetResource, resId);
        }
    }
    #endif /* OSISRENTRYEXIT */

    #if defined(OSRESOURCEISR)
    if (resRef->resPrio >= 0)   /* resPrio >= 0 - TASK resource */
    #endif
    {
        if ((OSPRIOTYPE)OSTSKPRIO (OsRunning) < resRef->resPrio)    /* or resource with lower priority */
        {
           /*
            * @violates @ref Os_resource_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
            */
           OSRETERROR (E_OS_ACCESS, OSServiceId_GetResource, resId);
        }
    }
    #endif /* OSEXTSTATUS */


    OSDIS (save);

    /*
     * @violates @ref Os_resource_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKACCESSRIGHTSRI (resRef->appMask, OSServiceId_GetResource, resId);

    OSTPStartResLockTime (OS_GETOBJIND (resId));

    #if defined(OSEXTSTATUS) || (OSORTIDEBUGLEVEL > 0U)
    resRef->isUsed = 1U;
    #endif

    #if defined(OSRESOURCEISR)
    if (resRef->resPrio < 0)    /* resPrio < 0 - ISR resource */
    {
        OSPRIOTYPE prio;
        
        OsIsrLevel |= OSISRRESOURCELEVEL;       /* block scheduler */

        resRef->savedIsrMask = save;
        prio = -(resRef->resPrio);
        save = (OSINTMASKTYPE)prio;

        if (save < resRef->savedIsrMask)
        {
            save = resRef->savedIsrMask;
        }

        #if defined(OSUSERESLINK)
        resRef->nextRes = *curResRef;
        *curResRef = (OSRefResType) resRef;
        #endif
    }
    else                        /* Task level resource */
    #endif /* defined(OSRESOURCEISR) */
    {
        /*
        * @violates @ref Os_resource_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        resRef->prio2task = OSGETTASK (resRef->resPrio);
        /*
        * @violates @ref Os_resource_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        OSGETTASK (resRef->resPrio) = OsRunning;

        OSSetPrioBit (resRef->resPrio);

        resRef->nextRes = OsRunning->resources;
        OsRunning->resources = (OSRefResType) resRef;

    }

    #if(OSORTIDEBUGLEVEL > 0U)
    #if !defined(OSNOISR2)
    if (OSISRLEVELMASKED == 0U)
    {
    #endif
        resRef->curPrio = OsRunning->curPrio;   /* save the current task prio value */

        if (OsRunning->curPrio > resRef->resPrio)       /* internal prio are in reversed order */
        {
            OsRunning->curPrio = resRef->resPrio;
        }
    #if !defined(OSNOISR2)
    }
    #endif
    #endif /* (OSORTIDEBUGLEVEL > 0U) */

    #if defined(OSRESOURCEISR)
    if (resRef->resPrio < 0)    /* resPrio < 0 - ISR resource */
    {
        OsISRResourceCounter++;
    }
    #endif /* defined(OSRESOURCEISR) */

    OSRI (save);
    OSOrtiServiceWatchOnExit (OSServiceId_GetResource);
    return (E_OK);
}

/******************************************************************************
 * Function:    ReleaseResource
 *
 * Description: releases resource, rescheduling may occur
 *
 * Return: E_OK                       no errors 
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) the identifier is invalid
 *         E_OS_NOFUNC                occupied/released before resource
 *         E_OS_ACCESS                access to the object denied
 *         E_OS_RESOURCE              a SPINLOCK has to be released before this RESOURCE
 ******************************************************************************/
StatusType
OS_ReleaseResource (ResourceType resId)
{
    volatile OSIMSAVE           /* volatile OSINTMASKTYPE save; */
    OSResType resRef;

    #if defined(OSRESOURCEISR) && defined(OSUSERESLINK)
    OSRefResType *curResRef;    /* reference to ISR or Task resource field */
    #endif

    OSOrtiSetServiceWatch (OSServiceId_ReleaseResource);

    #if defined(OSRESOURCEISR) && defined(OSUSERESLINK)
    if (OSISRLEVELMASKED > 0U)
    {
        /*
        * @violates @ref Os_resource_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        curResRef = &(OsIsrArray[OSISRLEVELMASKED - 1U]->resources);
    }
    else
    {
        /*
        * @violates @ref Os_resource_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        curResRef = &(OsRunning->resources);
    }
    #endif


    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_resource_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_ReleaseResource, resId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_resource_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_ReleaseResource, resId);
        }
    }
    #endif /* OSCHECKCONTEXT */

    #if defined(OSEXTSTATUS)
    if (OSRESIDISINVALID (resId))       /* invalid ID */
    {
        /*
         * @violates @ref Os_resource_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_ReleaseResource, resId);
    }
    #endif /* OSEXTSTATUS */



    resRef = &OsResources[OS_GETOBJIND (resId)];

    #if defined(OSEXTSTATUS)
    if ((resRef->isUsed) == 0U)      /* attempt to access not occupied resource */
    {
        /*
         * @violates @ref Os_resource_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_NOFUNC, OSServiceId_ReleaseResource, resId);
    }

    #if defined(OSRESOURCEISR)
    if (resRef->resPrio < 0)    /* ISR resource */
    {
        if (*curResRef != (OSRefResType) resRef)        /* another resource has to be released before */
        {
            /*
             * @violates @ref Os_resource_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_NOFUNC, OSServiceId_ReleaseResource, resId);
        }
        #if defined(OSISRENTRYEXIT)
        if (OSISRLEVEL != 0U)    /* Check call level */
        {
            /*
            * @violates @ref Os_resource_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            if (((OSPRIOTYPE)OsIsrArray[OSISRLEVELMASKED - 1U]->isrPrio) > (-(resRef->resPrio)))
            {   /* resource priority is lower than assigned ISR priority */
                /*
                 * @violates @ref Os_resource_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
                 */
                OSRETERROR (E_OS_ACCESS, OSServiceId_ReleaseResource, resId);
            }
        }
        #endif /* defined(OSISRENTRYEXIT) */
    }
    else        /* TASK resource */
    #endif /* defined(OSRESOURCEISR) */
    {
        if (OsRunning->resources != (OSRefResType) resRef)      /* another resource has to be released before */
        {
            /*
             * @violates @ref Os_resource_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_NOFUNC, OSServiceId_ReleaseResource, resId);
        }

        #if defined(OSISRENTRYEXIT)

        if (OSISRLEVELMASKED != 0U)      /* Check call level */
        {
            /*
             * @violates @ref Os_resource_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_ACCESS, OSServiceId_ReleaseResource, resId);       /* resource is not for ISR */
        }
        #endif
        if ((OSPRIOTYPE)OSTSKPRIO (OsRunning) < resRef->resPrio)    /* or resource with lower priority */
        {
            /*
             * @violates @ref Os_resource_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_ACCESS, OSServiceId_ReleaseResource, resId);
        }
    }
    #endif /* OSEXTSTATUS */

    OSDIS (save);

    #if !defined(OSEXTSTATUS)
    /*
     * @violates @ref Os_resource_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKACCESSRIGHTSRI (resRef->appMask, OSServiceId_ReleaseResource, resId);
    #endif

    OSTPResetResLockTime (resRef);

    #if defined(OSRESOURCEISR)
    if (resRef->resPrio < 0)    /* resPrio < 0 - ISR resource */
    {
        #if (OSORTIDEBUGLEVEL > 0U) || defined(OSEXTSTATUS)
        resRef->isUsed = 0U;
        #endif

        #if defined(OSUSERESLINK)
        *curResRef = resRef->nextRes;
        #endif

        save = resRef->savedIsrMask;

        OsISRResourceCounter--;
        if (OsISRResourceCounter == 0U)  /* It is the first ISR resource */
        {
            OsIsrLevel &= ~OSISRRESOURCELEVEL;  /* unblock scheduler */
        }
    }
    else
    #endif /* OSRESOURCEISR */

    {
        /*
        * @violates @ref Os_resource_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        OSGETTASK (resRef->resPrio) = resRef->prio2task;

        #if defined(OSECC)
        /*
        * @violates @ref Os_resource_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        if ((OSTASKSTATUS (OSGETTASK (resRef->resPrio)->taskId) & (OSTCBNOSUSPENDED | OSTCBWAIT)) != OSTCBNOSUSPENDED)
        #else
        /*
        * @violates @ref Os_resource_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        if ((OSTASKSTATUS (OSGETTASK (resRef->resPrio)->taskId) & OSTCBNOSUSPENDED) == 0U)
        #endif
        {
            OSTask2Suspend (resRef->resPrio);
        }
        #if (OSORTIDEBUGLEVEL > 0U) || defined(OSEXTSTATUS)
        resRef->isUsed = 0U;
        #endif

        #if defined(OSUSERESLINK)
        OsRunning->resources = resRef->nextRes;
        #endif
    }

    #if(OSORTIDEBUGLEVEL > 0U)
    #if !defined(OSNOISR2)
    if (OSISRLEVELMASKED == 0U)
    {
    #endif
        if (OsRunning->curPrio < resRef->curPrio)
        {
            OsRunning->curPrio = resRef->curPrio;
        }
    #if !defined(OSNOISR2)
    }
    #endif
    #endif /* (OSORTIDEBUGLEVEL > 0U) */

    OSOrtiSetOldServiceID (OSServiceId_ReleaseResource);
    OSDISPATCH ();
    OSOrtiResetIdOnExit ();

    OSRI (save);
    return (E_OK);
}
#endif /* OSRESOURCE */

#define OSTEXT_STOP_SEC_CODE
/*
* @violates @ref Os_resource_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif


/** @} */
