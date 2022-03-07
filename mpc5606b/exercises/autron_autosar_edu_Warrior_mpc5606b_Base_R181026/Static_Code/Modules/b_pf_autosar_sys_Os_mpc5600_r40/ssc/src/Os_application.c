/**
*   @file    Os_application.c
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
* @section Os_application_c_REF_5_1_1
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters. 
* The section identification define's naming convention is defined by AutoSar and identifiers are longer than 31 character. 
* Compilers are checked for support this length of identifiers.
*
* @section Os_application_c_REF_14_7_1
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function 
* A function shall have a sigle point of exit at the end of finction.
* The returned statement is result of error hanling.
*
* @section Os_application_c_REF_17_4_1
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* Array indexing shall be the only allowed form of pointer arithmetic
* The pointers are used to increase of OS performance.
*
* @section Os_application_c_REF_16_10_1
* Violates MISRA 2004 Required Rule 16.10, Ignoring return value of function
* If a function returns error information, then that error information shall be tested.
* Function OSLongJmp is used for switching context and it is not supposed 
* to return to the place where it is called.
*
* @section Os_application_c_REF_19_1_1
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

#include <Os_application_api.h>
#include <Os_application_internal_api.h>
#include <Os_application_config.h>

#include    <string.h>          /* for memcpy()    */

/*
* @violates @ref Os_application_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSAPPLICATION)
#if defined(OSAPPIDRAM)
OSDECLAREVAR (OSNEAR OSAPPLICATIONTYPE, OsAppID_);
#endif
#endif /* defined(OSAPPLICATION) */


/*
* @violates @ref Os_application_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_application_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#define OS_START_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_application_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if defined(OSAPPLICATION)
OSAPPCB OsAppTable[OSNAPPS];
#endif /* defined(OSAPPLICATION) */

#define OS_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_application_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if !defined(OSCALCULATEOBJIND)
#define appInd (appId)
#endif


#define OSTEXT_START_SEC_CODE
/*
* @violates @ref Os_application_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if defined(OSAPPLICATION)
/******************************************************************************
 * Function :   OsInitApplications
 * Description: makes OsAppTable of OsAppCfgTable
 * Returns:     none
 ******************************************************************************/
void 
OSInitApplications (void)
{    

    OSCARDINAL i;

    for (i = 0U; i < OSNAPPS; i++)
    {

        memcpy (&OsAppTable[i], &OsAppCfgTable[i], sizeof (OsAppCfgTable[i]));

        OsAppTable[i].state = APPLICATION_ACCESSIBLE;

        #if (OSNTRUSTEDFUNCTIONS > 0U)
        #if defined(OSTPBUDGET)
        OsAppTable[i].tpError = 0U;
        #endif
        OsAppTable[i].tfContext = 0U;
        #endif
    }

    OSSetCurApp (OSINVALID_OSAPPLICATION);
}

/******************************************************************************
 * Function :   CheckObjectAccess
 *
 * Description: returns ability of given application to access given object
 *
 * Return: ACCESS   application has access to an object
 *         NOACCESS otherwise
 ******************************************************************************/
ObjectAccessType
OS_CheckObjectAccess (ApplicationType appId, ObjectTypeType objectType, OSObjectType objectId)
{
    OSWORD objIndex;
    OSAPPLICATIONMASKTYPE appIdBit;
    OSAPPLICATIONMASKTYPE appMask;


    OSOrtiSetServiceWatch (OSServiceId_CheckObjectAccess);

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK | OSISRLEVELHOOKERROR | OSISRLEVELHOOKAPPERROR | OSISRLEVELHOOKPROTECTION))
    {
        #if defined(OSHOOKERROR_EXT) &&  defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSErrorHook (E_OS_DISABLEDINT, OSServiceId_CheckObjectAccess, 0U);
        }
        else
        {
            /*
             * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSErrorHook (E_OS_CALLEVEL, OSServiceId_CheckObjectAccess, 0U);
        }
        #endif
 
        OSOrtiServiceWatchOnExit (OSServiceId_CheckObjectAccess);
        /*
         * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return (NO_ACCESS);
    }
    #endif /* defined(OSCHECKCONTEXT) */

    if (OSAPPIDISINVALID (appId))
    {
        #if defined(OSHOOKERROR_EXT)
        OSErrorHook (E_OS_ID, OSServiceId_CheckObjectAccess, appId); /* invalid ID */
        #endif

        OSOrtiServiceWatchOnExit (OSServiceId_CheckObjectAccess);
        /*
         * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return (NO_ACCESS);
    }

    #if defined(OSEXTSTATUS)
    if (objectType != OS_GETOBJTYP (objectId))
    {
        #if defined(OSHOOKERROR_EXT)
        OSErrorHook (E_OS_VALUE, OSServiceId_CheckObjectAccess, appId);
        #endif

        OSOrtiServiceWatchOnExit (OSServiceId_CheckObjectAccess);
        /*
         * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return (NO_ACCESS);
    }
    #endif

    appIdBit = (OSAPPLICATIONMASKTYPE)(1U << OS_GETOBJIND (appId));
    objIndex = OS_GETOBJIND (objectId);
    appMask = 0U;

    switch (objectType)
    {
        case OBJECT_TASK:
            if (objIndex < OSNTSKS)
            {
                appMask = OsTaskCfgTable[objIndex].appMask;
            }
            #if defined(OSHOOKERROR_EXT)
            else
            {
                OSErrorHook (E_OS_ID, OSServiceId_CheckObjectAccess, appId); /* invalid ID */
            }
            #endif
            break;

        #if !defined(OSNOISR)
        case OBJECT_ISR:
            if (objIndex < OSNISR)
            {
                appMask = OSGIVENAPPMASK (OsIsrTable[objIndex].appId);
            }            
            #if defined(OSHOOKERROR_EXT)
            else
            {
                OSErrorHook (E_OS_ID, OSServiceId_CheckObjectAccess, appId); /* invalid ID */
            }
            #endif
            break;
        #endif

        #if (OSNUSERALMS > 0U)
        case OBJECT_ALARM:
            if (objIndex < OSNUSERALMS)
            {
                appMask = OsAlarmsCfg[objIndex].appMask;
            }
            #if defined(OSHOOKERROR_EXT)
            else
            {
                OSErrorHook (E_OS_ID, OSServiceId_CheckObjectAccess, appId); /* invalid ID */
            }
            #endif
            break;
        #endif

        #if defined(OSRESOURCE)
        case OBJECT_RESOURCE:
            if (objIndex < (OSNRESS + OSNISRRESS))
            {
                appMask = OsResCfg[objIndex].appMask;
            }
            #if defined(OSHOOKERROR_EXT)
            else
            {
                OSErrorHook (E_OS_ID, OSServiceId_CheckObjectAccess, appId); /* invalid ID */
            }
            #endif
            break;
        #endif

        #if defined(OSCOUNTER)
        case OBJECT_COUNTER:
            if (objIndex < OSNCTRS)
            {
                appMask = OsCountersCfg[objIndex].appMask;
            }
            #if defined(OSHOOKERROR_EXT)
            else
            {
                OSErrorHook (E_OS_ID, OSServiceId_CheckObjectAccess, appId); /* invalid ID */
            }
            #endif
            break;
        #endif

        #if defined(OSSCHEDULETABLES)
        case OBJECT_SCHEDULETABLE:
            if (objIndex < OSNSCTS)
            {
                appMask = OsScheduleTablesCfg[objIndex].appMask;
            }
            #if defined(OSHOOKERROR_EXT)
            else
            {
                OSErrorHook (E_OS_ID, OSServiceId_CheckObjectAccess, appId); /* invalid ID */
            }
            #endif
            break;
        #endif

        #if (OSNMSGS > 0U)
        case OBJECT_MESSAGE:
            if (objIndex < OSNMSGS)
            {
                if (objIndex < OSNRCVMSGS)
                {
                    appMask = OsMessages[objIndex].appMask;
                }
                else                /* sending messages  */
                {
                    appMask = OsSndMessages[objIndex - OSNRCVMSGS].appMask;
                }
            }
            #if defined(OSHOOKERROR_EXT)
            else
            {
                OSErrorHook (E_OS_ID, OSServiceId_CheckObjectAccess, appId); /* invalid ID */
            }
            #endif
            break;
        #endif


        default:
            break;
    }

    OSOrtiServiceWatchOnExit (OSServiceId_CheckObjectAccess);
    return ((appMask & appIdBit) == 0U) ? (NO_ACCESS) : (ACCESS);
}

/***************************************************************************
 * Function:    CheckObjectOwnership
 *
 * Description: finds the application that owns the object
 *
 * Return: ID of the application that owns the object,
 *         INVALID_OSAPPLICATION if no application owns the object
 *         or if the object is RES_SCHEDULER
 **************************************************************************/
ApplicationType
OS_CheckObjectOwnership (ObjectTypeType objectType, OSObjectType objectId)
{
    OSWORD objIndex;
    ApplicationType appId;

    OSOrtiSetServiceWatch (OSServiceId_CheckObjectOwnership);

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK | OSISRLEVELHOOKERROR | OSISRLEVELHOOKAPPERROR | OSISRLEVELHOOKPROTECTION))
    {
        #if defined(OSHOOKERROR_EXT) && defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            OSErrorHook (E_OS_DISABLEDINT, OSServiceId_CheckObjectOwnership, 0U);
        }
        else
        {
            OSErrorHook (E_OS_CALLEVEL, OSServiceId_CheckObjectOwnership, 0U);
        }
        #endif

        OSOrtiServiceWatchOnExit (OSServiceId_CheckObjectOwnership);
        /*
         * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return (INVALID_OSAPPLICATION);
    }
    #endif /* OSCHECKCONTEXT */

    #if defined(OSEXTSTATUS)
    if (objectType != OS_GETOBJTYP (objectId))
    {
        #if defined(OSHOOKERROR_EXT)
        OSErrorHook (E_OS_VALUE, OSServiceId_CheckObjectOwnership, objectId);
        #endif

        OSOrtiServiceWatchOnExit (OSServiceId_CheckObjectOwnership);
        /*
         * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return (INVALID_OSAPPLICATION);
    }
    #endif

    objIndex = OS_GETOBJIND (objectId);
    switch (objectType)
    {
    case OBJECT_TASK:
        appId = (objIndex < OSNTSKS) ? OS_MKOBJID (OBJECT_APPLICATION, OsTaskTable[objIndex].appId) : INVALID_OSAPPLICATION;
        break;

    #if (OSNISR > 0U)
    case OBJECT_ISR:
        appId = (objIndex < OSNISR) ? OS_MKOBJID(OBJECT_APPLICATION, OsIsrTable[objIndex].appId) : INVALID_OSAPPLICATION;
        break;
    #endif

    #if (OSNUSERALMS > 0U)
    case OBJECT_ALARM:
        appId = (objIndex < OSNUSERALMS) ? OS_MKOBJID (OBJECT_APPLICATION, OSALMARRAY[objIndex].appId) : INVALID_OSAPPLICATION;
        break;
    #endif

    #if defined(OSCOUNTER)
    case OBJECT_COUNTER:
        appId = (objIndex < OSNCTRS) ? OS_MKOBJID (OBJECT_APPLICATION, OsCounters[objIndex].appId) : INVALID_OSAPPLICATION;
        break;
    #endif

    #if defined(OSSCHEDULETABLES)
    case OBJECT_SCHEDULETABLE:
        appId = (objIndex < OSNSCTS) ? OS_MKOBJID (OBJECT_APPLICATION, OsScheduleTables[objIndex].appId) : INVALID_OSAPPLICATION;
        break;
    #endif

    #if (OSNMSGS > 0U)
    case OBJECT_MESSAGE:
        if (objIndex < OSNRCVMSGS) /* Receiving messages */
        {
            appId = OS_MKOBJID (OBJECT_APPLICATION, OsMessages[objIndex].appId);
        }
        else                       /* Sending messages */
        {
            objIndex = objIndex - OSNRCVMSGS;
            appId = (objIndex < OSNSNDMSGS) ? OS_MKOBJID (OBJECT_APPLICATION, OsSndMessages[objIndex].appId) : INVALID_OSAPPLICATION;
        }
        break;
    #endif



    default:
        #if defined(OSHOOKERROR_EXT)
        OSErrorHook (E_OS_VALUE, OSServiceId_CheckObjectOwnership, objectId);
        #endif        
        appId = INVALID_OSAPPLICATION;
        break;

    } /* end switch (objectType) */

    OSOrtiServiceWatchOnExit (OSServiceId_CheckObjectOwnership);
    return appId;
}

/******************************************************************************
 * Function:    GetApplicationID
 *
 * Description: shows which applications task,ISR or hook is running
 *
 * Returns:     current application Id or INVALID_OSAPPLICATION
 ******************************************************************************/
ApplicationType
OS_GetApplicationID (void)
{
    OSWORD appInd;

    OSOrtiSetServiceWatch (OSServiceId_GetApplicationID);

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK | OSISRLEVELHOOKPROTECTION |
                         OSISRLEVELHOOKERROR | OSISRLEVELHOOKAPPERROR |
                         OSISRLEVELHOOKTASK |
                         OSISRLEVELHOOKSTARTUP | OSISRLEVELHOOKAPPSTARTUP |
                         OSISRLEVELHOOKSHUTDOWN | OSISRLEVELHOOKAPPSHUTDOWN))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            #if defined(OSHOOKERROR_EXT)
            OSErrorHook (E_OS_DISABLEDINT, OSServiceId_GetApplicationID, 0U);
            #endif

            OSOrtiServiceWatchOnExit (OSServiceId_GetApplicationID);
            /*
             * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return (INVALID_OSAPPLICATION);
        }
        else
        #endif /* defined(OSEXTSTATUS) */
        {
            #if defined(OSHOOKERROR_EXT)
            OSErrorHook (E_OS_CALLEVEL, OSServiceId_GetApplicationID, 0U);
            #endif

            OSOrtiServiceWatchOnExit (OSServiceId_GetApplicationID);
            /*
             * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return (INVALID_OSAPPLICATION);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    appInd = (OSWORD)OSGetCurApp ();


    OSOrtiServiceWatchOnExit (OSServiceId_GetApplicationID);
    return OS_MKOBJID (OBJECT_APPLICATION, appInd);
}


/*****************************************************************************
 * Function:    OSSCTerminateApplication
 *
 * Description: kills all tasks and ISRs which belong to current application
 *
 * Return: none
 *****************************************************************************/
OSINLINE_ void 
OSSCTerminateApplication (OSAPPLICATIONTYPE appInd, RestartType RestartOption, OSAPPLICATIONTYPE curApp)
{
    (void) OSTerminateApplication (appInd, RestartOption);

    if (appInd == curApp)       /* self termination  */
    {
        if (((OsKilled & OSRUNTSKKILLED) != 0U)
        #if defined(OSISRENTRYEXIT)
            && (OSISRLEVELMASKED == 0U)
        #endif
            )
        {                       /* it is not executed if called from OSMCTerminateApplication() */
            OSSETTASKMSR ();    /* set MSR for Task, EE = 1 */
            OsKilled &= ~OSRUNTSKKILLED;
            /*
            * @violates @ref Os_application_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
             OsRunning = OSGETMAXPRIOTASK;
            OSTaskInternalDispatch ();
        }

        #if (OSNIPLS > 0U)
        /* otherwise running ISR is killed - no other option */
        OSDHI ();
        OsIsrLevel--;
        /*
         * @violates @ref Os_application_c_REF_16_10_1 MISRA 2004 Required Rule 16.10, Ignoring return value of function
         * @violates @ref Os_application_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used         
         */
        OSLongJmp (OsISRbufs[OSISRLEVELMASKED]);        /* back to OSInterruptDispatcher */
        #endif /* (OSNIPLS > 0U) */

        /* unreachable point */
    }
}


/*****************************************************************************
 * Function:    TerminateApplication
 *
 * Description: kills all tasks and ISRs which belong to current application
 *
 * Return: function doesn't returns if there are no errors
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_VALUE                 value outside of the admissible limit
 *****************************************************************************/
StatusType
OS_TerminateApplication (ApplicationType appId, RestartType RestartOption)
{

    OSAPPCB *app;
    OSIMSAVE                    /* OSINTMASKTYPE save; */
    OSAPPLICATIONTYPE curApp;

    #if defined(OSCALCULATEOBJIND)
    OSAPPLICATIONTYPE appInd;
    #endif

    OSOrtiSetServiceWatch (OSServiceId_TerminateApplication);

    curApp = (OSAPPLICATIONTYPE)OSGetCurApp ();

    #if defined(OSCALCULATEOBJIND)
    appInd = (OSAPPLICATIONTYPE)OS_GETOBJIND (appId);
    #endif

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK | OSISRLEVELHOOKAPPERROR))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_TerminateApplication, appId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_TerminateApplication, appId);
        }
    }

    #if defined(OSEXTSTATUS)
    else if (((OsIsrLevel & OSISRLEVELHOOKAPPERROR) != 0U) && (appInd != curApp))
    {
        /* only self termination is allowed from app. specific error hook */
        /*
         * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_CALLEVEL, OSServiceId_TerminateApplication, appId);
    }
    else
    {
        /* to satisfy MISRA Violates MISRA 2004 Required Rule 14.10, no 'else' at end of 'if ... else if' chain */
    }
    #endif
    #endif /* OSCHECKCONTEXT */

    #if defined(OSEXTSTATUS)
    if (((OSWORD) RestartOption) > ((OSWORD) RESTART))
    {
        /*
         * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_VALUE, OSServiceId_TerminateApplication, appId);
    }

    if (OSAPPIDISINVALID (appId))
    {
        /*
         * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_TerminateApplication, appId);  /* invalid ID */
    }

    #if (OSNNOTTRUSTEDAPPS > 0U)
    if ((appInd != curApp) && OSMP_IS_NONTRUSTEDAPP (curApp))
    {
        /*
         * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ACCESS, OSServiceId_TerminateApplication, appId);
    }
    #endif
    #endif /* defined(OSEXTSTATUS) */

    app = &OsAppTable[appInd];

    {
        OSDIS (save);
        if (app->state == APPLICATION_TERMINATED)
        {
            OSRI (save);
            /*
             * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_STATE, OSServiceId_TerminateApplication, appId);   /* invalid state */
        }
        if (app->state == APPLICATION_RESTARTING)
        {
            /* state is APPLICATION_RESTARTING */
            if (appInd != curApp)
            {
                /* the caller does not belong to the given application */
                OSRI (save);
                /*
                 * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
                 */
                OSRETERROR (E_OS_STATE, OSServiceId_TerminateApplication, appId);       /* invalid state */
            }
            else
            {
                /* the caller does belong to the given application, 
                   but Restart option is RESTART [OS548] */
                if (RestartOption == RESTART)
                {
                    OSRI (save);
                    /*
                     * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
                     */
                    OSRETERROR (E_OS_STATE, OSServiceId_TerminateApplication, appId);   /* invalid state */
                }
            }
        }
        OSOrtiSetOldServiceID (OSServiceId_TerminateApplication);
        OSSCTerminateApplication ((OSAPPLICATIONTYPE)appInd, RestartOption, curApp);

        #if defined(OSHAS_RESTARTTASK)
        OSDISPATCH ();
        #endif
    }

    OSOrtiResetIdOnExit ();     /* set that the caller service is finished */
    OSRI (save);
    return E_OK;
}

/***************************************************************************
 * function:   OSTerminateApplication( OSAPPLICATIONTYPE appInd, RestartType RestartOption )
 *
 * Description: kills all tasks and ISRs which belong to current application
 *
 * Returns:    OSTRUE on success,
 *             OSFALSE - otherwise
 *
 * Notes:
 **************************************************************************/
OSWORD
OSTerminateApplication (OSAPPLICATIONTYPE appInd, RestartType RestartOption)
{
    #if defined(OSCWPPC)
    #pragma unused( RestartOption ) /* to suppress warning about unused variable */
    #endif

    #if defined(OSHAS_RESTARTTASK)
    OSWORD restartTask;
    #endif

    OSAPPCB *app;
    #if defined(OSCOUNTER)
    OSWORD i;
    #endif

    if (appInd == OSINVALID_OSAPPLICATION)
    {   /* it might be in ErrorHook */
        /*
         * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return OSFALSE;
    }

    app = &OsAppTable[appInd];

    #if (OSNUSERALMS > 0U)
    OSKillAppAlarms (appInd);
    #endif

    #if defined(OSSCHEDULETABLES)
    OSKillAppScheduleTables (appInd);
    #endif

    OSKillAppTasks (appInd);    /* kill all tasks of this application */

    #if defined(OSKILLAPPISRS)
    OSKillAppISRs (appInd);     /* kill ISRs of this application */
    #endif

    #if defined(OSMEMPROTECTION)
    #if (OSNTRUSTEDFUNCTIONS > 0U)
    if (0U != app->tfContext)
    {
        app->tfContext = 0U;
        #if defined(OSTPBUDGET)
        app->tpError = 0U;
        #endif

        #if (OSNUSERISR > 0U)
        OSEnableISRs4App (appInd);
        #endif
        OSEnableTasks4App (app);
    }
    #endif /* (OSNTRUSTEDFUNCTIONS > 0U) */
    #endif /* defined(OSMEMPROTECTION) */

    #if defined(OSHAS_RESTARTTASK)

    restartTask = OsAppTable[appInd].restartTask;

    if ((restartTask != OSINVALID_TASK) && (RESTART == RestartOption))
    {   /* set Task ready as in ActivateTask   */
        #if defined(OSECC)
        #if (OSNXTSKS > 0U)
        OsTaskTable[restartTask].set_event = OSNOEVENTS;
        #endif
        #endif /* defined(OSECC) */

        OSActivateTaskInAlm (restartTask);      /* here is the same case as when task is activated from alarm action */
        app->state = APPLICATION_RESTARTING;
    }
    else
    {
        app->state = APPLICATION_TERMINATED;
    }
    #else
    app->state = APPLICATION_TERMINATED;
    #endif /* defined(OSHAS_RESTARTTASK) */

    #if defined(OSCOUNTER)
    for (i = 0U; i < OSNCTRS; i++)
    {
        if (appInd == OsCounters[i].appId)
        {
            OsCounters[i].appMask = OSGIVENAPPMASK (appInd);
        }
    }
    #endif

    return OSTRUE;
}

/***************************************************************************
 * Function:    AllowAccess
 *
 * Description: This service sets the own state of an OS-Application
 *              from APPLICATION_RESTARTING to APPLICATION_ACCESSIBLE
 *
 * Return:      E_OK             - no errors
 *              E_OS_STATE       - the OS-Application of the caller is in
 *                                 the wrong state
 *              E_OS_DISABLEDINT - (ext.status) service call while
 *                                 interrupts disabled
 *              E_OS_CALLEVEL    - (ext.status) service call from wrong context
 **************************************************************************/
StatusType
OS_AllowAccess (void)
{
    OSAPPLICATIONTYPE appId;


    OSIMSAVE                /* OSINTMASKTYPE save; */
    OSWORD i;

    OSOrtiSetServiceWatch (OSServiceId_AllowAccess);

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_AllowAccess, 0U);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_AllowAccess, 0U);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    appId = (OSAPPLICATIONTYPE)OSGetCurApp ();

    OSDIS (save);

    if (OsAppTable[appId].state != APPLICATION_RESTARTING)
    {
        OSRI (save);
        /*
         * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_STATE, OSServiceId_AllowAccess, 0U);
    }

    OsAppTable[appId].state = APPLICATION_ACCESSIBLE;

    for (i = 0U; i < OSNTSKS; i++)
    {
        if (appId == OsTaskTable[i].appId)
        {
            OsTaskTable[i].appMask = OsTaskCfgTable[i].appMask;
        }
    }

    #if (OSNUSERALMS > 0U)
    for (i = 0U; i < OSNUSERALMS; i++)
    {
        if (appId == OSALMARRAY[i].appId)
        {
            OSALMARRAY[i].appMask = OsAlarmsCfg[i].appMask;
        }
    }
    #endif

    #if defined(OSSCHEDULETABLES)
    for (i = 0U; i < OSNSCTS; i++)
    {
        if (OsScheduleTables[i].appId == appId)
        {
            OsScheduleTables[i].appMask = OsScheduleTablesCfg[i].appMask;
        }
    }
    #endif

    #if defined(OSCOUNTER)
    for (i = 0U; i < OSNCTRS; i++)
    {
        if (appId == OsCounters[i].appId)
        {
            OsCounters[i].appMask = OsCountersCfg[i].appMask;
        }
    }
    #endif

    OSRI (save);

    OSOrtiServiceWatchOnExit (OSServiceId_AllowAccess);

    return E_OK;
}

/*****************************************************************************
 * Function:    GetApplicationState
 *
 * Description: This service return the current state of given application
 *
 * Return: E_OK             - no errors
 *         E_OS_DISABLEDINT - (ext.status) service call while
 *                            interrupts disabled
 *         E_OS_CALLEVEL    - (ext.status) service call from wrong context
 *         E_OS_ID          - (ext.status) the identifier is invalid
 *****************************************************************************/
StatusType
OS_GetApplicationState (ApplicationType appId, ApplicationStateRefType stateRef)
{
    OSOrtiSetServiceWatch (OSServiceId_GetApplicationState);

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK | OSISRLEVELHOOKPROTECTION |
                         OSISRLEVELHOOKERROR | OSISRLEVELHOOKAPPERROR |
                         OSISRLEVELHOOKTASK |
                         OSISRLEVELHOOKSTARTUP | OSISRLEVELHOOKAPPSTARTUP |
                         OSISRLEVELHOOKSHUTDOWN | OSISRLEVELHOOKAPPSHUTDOWN))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_GetApplicationState, appId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_GetApplicationState, appId);
        }
    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)
    if (OSAPPIDISINVALID (appId))
    {
        /*
         * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_GetApplicationState, appId);
    }
    #endif

    /*
     * @violates @ref Os_application_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    OSCHECKWRITEACCESS (stateRef, sizeof (ApplicationStateType), OSServiceId_GetApplicationState, appId);

    *stateRef = OsAppTable[OS_GETOBJIND (appId)].state;

    OSOrtiServiceWatchOnExit (OSServiceId_GetApplicationState);
    return E_OK;
}
#endif /* defined(OSAPPLICATION) */

#define OSTEXT_STOP_SEC_CODE
/*
* @violates @ref Os_application_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif



/** @} */
