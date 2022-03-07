/**
*   @file    Os_setup.c
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
* @section Os_setup_c_REF_14_7_1
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function 
* A function shall have a sigle point of exit at the end of finction.
* The returned statement is result of error hanling.
*
* @section Os_setup_c_REF_16_10_1
* Violates MISRA 2004 Required Rule 16.10, Ignoring return value of function
* If a function returns error information, then that error information shall be tested.
* Function OS2SystemMode is used for switching to system mode and it is not supposed 
* to analyze the return value where it is called.
*
* @section Os_setup_c_REF_17_4_1
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* Array indexing shall be the only allowed form of pointer arithmetic
* The pointers are used to increase of OS performance.
*
* @section Os_setup_c_REF_19_1_1
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

#include <Os_setup_api.h>
#include <Os_setup_internal_api.h>
#include <Os_setup_internal_types.h>

#include <Os_stack_internal_api.h>
#include <Os_resource_internal_api.h>

#if defined(OSMEMPROTECTION) || defined(OSHOOKPROTECTION) || (defined(OSMULTICORE) && defined(OSSBSSCOPY))

#define  OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

OSBYTE OsStarted;               /* boolean variable, it shall be OSFALSE (0) before StartOS() call  */

#define OS_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_setup_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#endif /* defined(OSMEMPROTECTION) || defined(OSHOOKPROTECTION) || (defined(OSMULTICORE) && defined(OSSBSSCOPY)) */

#define OS_START_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_setup_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if (OSORTIDEBUGLEVEL > 0U) || (OSNAPPMODES > 1U)
OSNONCACHE AppModeType OsCurAppMode;
#endif

#define OS_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_setup_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#define OSTEXT_START_SEC_CODE
/*
* @violates @ref Os_setup_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#if defined(OSAPPLICATION)


#if defined(OSAPPHOOKSTARTUP)
static OSUSE_FRAME void OSAppStartupHooks (void);

/***************************************************************************
 * inline function  : OSGetAppStartupHook
 *
 * Description: 
 *
 * Returns: application specific startup hook address
 *
 * Notes: none
 **************************************************************************/
static OSINLINE OSHKSTARTUP
OSGetAppStartupHook (OSAPPCB * app)
{
    return app->startup;
}

#endif /* defined(OSAPPHOOKSTARTUP) */

#if defined(OSAPPHOOKSHUTDOWN)
/***************************************************************************
 * inline function  : OSGetAppShutdownHook
 *
 * Description: 
 *
 * Returns: application specific shutdown hook address
 *
 * Notes: none
 **************************************************************************/
static OSINLINE OSHKSHUTDOWN
OSGetAppShutdownHook (OSAPPCB * app)
{
    return app->shutdown;
}

#endif /* defined(OSAPPHOOKSHUTDOWN) */
#endif /* defined(OSAPPLICATION) */



/*  Public OS Services  */

/******************************************************************************
 * Function:    StartOS
 *
 * Description: OS data initialization from configuration tables
 *
 * Returns:     none
 *
 * Notes:
 *
 ******************************************************************************/
OSUSE_FRAME void StartOS (AppModeType mode)
{
    #if defined(OSCWPPC)
    #pragma unused (mode) /* to suppress warning about unused variable */
    #endif

    OSDHI ();



    OSOrtiSetServiceWatch (OSServiceId_StartOS);        /* set watch to this service */
    OSOrtiSetOldServiceID (OSServiceId_StartOS);

    #if defined(OSEXTSTATUS)
    if ((mode >= OSNAPPMODES)
        )
    {
        #if defined(OSHOOKERROR_EXT)
        OSOrtiSetServiceWatch (OSServiceId_ErrorHook);  /* set watch to this service */
        ErrorHook (E_OS_VALUE);
        OSOrtiServiceWatchOnExit (OSServiceId_ErrorHook);       /* clean service watch on hook leaving */
        #endif
        OSOrtiServiceWatchOnExit (OSServiceId_StartOS);
        /*
         * @violates @ref Os_setup_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return;
    }
    #endif

    OSCLEARPARAM ();            /* clear parameters for ErrorHook */

    #if defined(OSMEMPROTECTION)
    OSInitMemProtection ();     /* setting all used data sections for system PID, code sections for usre PID */
    #endif

    #if defined(OSAPPLICATION)
    OSInitApplications ();      /* making OsAppTable of OsConstAppTable */
    #endif

    #if defined(OSTERMINATION)
    OsKilled = 0U;
    #endif

    #if(OSORTIDEBUGLEVEL > 0U) || (OSNAPPMODES > 1U)
    OsCurAppMode = mode;
    #endif /* (OSORTIDEBUGLEVEL > 0U)  || (OSNAPPMODES > 1U) */

    OsSuspendLevelAll = 0U;

    /* ISR initialization   */
    OSInitializeISR ();


    /* System Timers initialization */
    OSInitSystemTimer ();


    #if defined(OSMEMPROTECTION) || defined(OSHOOKPROTECTION) || (defined(OSMULTICORE) && defined(OSSBSSCOPY))
    OsStarted = OSTRUE;
    #endif

    #if(OSORTIDEBUGLEVEL > 0U)
    OsLastError = E_OK;
    #endif /* (OSORTIDEBUGLEVEL > 0 ) */

    /* Scheduler initialization */
    OsSchedulerVector1 = 0U;
    #if defined(OSEXTPRIORS)
    OsSchedulerVector2 = 0U;
    #endif /* defined(OSEXTPRIORS) */

    #if (OSNTRUSTEDFUNCTIONS > 0U)
    OsSchedulerVectorMask1 = 0xFFFFFFFFUL;
    #if defined(OSEXTPRIORS)
    OsSchedulerVectorMask2 = 0xFFFFFFFFUL;
    #endif
    #endif /* (OSNTRUSTEDFUNCTIONS > 0U) */

    /* Tasks initialization */
    #if(OSNAPPMODES > 1U)
    OSInitTasks (mode);
    #else
    OSInitTasks ();
    #endif

    /* Fill stacks */
    OSFillStacks ();

    /* Resources initialization */
    #if defined(OSRESOURCE)
    OSInitResources ();
    #endif

    /* Counters initialization */
    #if defined(OSCOUNTER)
    OSInitCounters ();
    #endif

    /* Alarms initialization */
    #if (OSNUSERALMS > 0U)
    OSInitAlarms ();
    #endif

    /* Schedule tables initialization */
    #if defined(OSSCHEDULETABLES)
    OSInitScheduleTables ();
    #endif



    /* IOC initialization */
    #if defined(OSIOC)
    OSInitIOC ();
    #endif


    #if defined(OSHOOKSTARTUP) || defined(OSAPPHOOKSTARTUP)


    OSOrtiSetServiceWatch (OSServiceId_StartupHook);    /* set watch to this service              */

    #if defined(OSHOOKSTARTUP)
    OsIsrLevel |= OSISRLEVELHOOKSTARTUP;        /* to block scheduler during StartupHook  */
    StartupHook ();             /* user hook or empty macro               */
    OsIsrLevel &= (OSISRLEVELTYPE) (~OSISRLEVELHOOKSTARTUP);
    OSCLEARSUSPENDLEVELS ();
    #endif

    #if defined(OSAPPLICATION)
    #if defined(OSAPPHOOKSTARTUP)
    OsIsrLevel |= OSISRLEVELHOOKAPPSTARTUP;
    OSAppStartupHooks ();
    OsIsrLevel &= ~OSISRLEVELHOOKAPPSTARTUP;
    #endif /* defined(OSAPPHOOKSTARTUP) */
    #endif /* defined(OSAPPLICATION) */

    OSOrtiServiceWatchOnExit (OSServiceId_StartupHook); /* clean service watch on hook leaving    */

    #endif /* OSHOOKSTARTUP || OSAPPHOOKSTARTUP */

    /* System Timers start */
    OSStartSystemTimer ();

    #if defined(OSTIMINGPROTECTION)
    #if(OSNAPPMODES > 1U)
    OSInitializeTP (mode);
    #else
    OSInitializeTP ();
    #endif
    #endif /* defined(OSTIMINGPROTECTION) */

    #if defined(OSAUTOALARMS)
    #if(OSNAPPMODES > 1U)
    OSInitAutoAlarms (mode);
    #else
    OSInitAutoAlarms ();
    #endif
    #endif /* OSAUTOALARMS */

    #if defined(OSAUTOSCHEDULETABLES)
    #if(OSNAPPMODES > 1U)
    OSInitAutoScheduleTables (mode);
    #else
    OSInitAutoScheduleTables ();
    #endif
    #endif /* OSAUTOSCHEDULETABLES */

    /*  Start scheduler */
    #if defined(OSISRENTRYEXIT) || (!defined(OSSC1))
    OsInitialMSR = OSGETMSR () | OSMSR_EE;      /* save initial MSR, used for Tasks start */
    #endif


    #if defined(OSMEMPROTECTION)
    /* Switch to common stack for NULL-task */
    OSLOADSP (OsRunning->tos);
    OSMP_TASK_OPEN_STACK ();
    #endif /* defined(OSMEMPROTECTION) */



    OSEHI ();
    #if defined(OSISRENTRYEXIT)
    OSDI ();
    #endif

    /*
    * @violates @ref Os_setup_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    if (OSPRIO2TASKID (OSMask2Task ()) != OSNULLTASK)
    {
        OSTaskForceDispatch (); /* start autostarted Tasks  */
    }
    OSEI ();                    /* end of initialization if there were no autostarted Tasks */

    for (;;)
    {
    #if defined(OSHOOKSCHEDULER)    /* not configurable by OIL */
        OSOrtiSetServiceWatch (OSServiceId_IdleLoopHook);       /* set watch to this service */
        IdleLoopHook ();
        OSOrtiServiceWatchOnExit (OSServiceId_IdleLoopHook);    /* clean service watch on hook leaving */
    #else
        OSWAIT ();
    #endif
    }

    OSWARNSUPPRESS
}

#if defined(OSAPPHOOKSTARTUP)
/***************************************************************************
 * function  : OSAppStartupHooks
 *
 * Description:  calls application specific startup hooks
 *
 * Returns: 
 *
 * Notes: none
 **************************************************************************/
static OSUSE_FRAME void OSAppStartupHooks (void)
{
    OSCARDINAL i;

    for (i = 0U; i < OSNAPPS; i++)
    {
        OSAPPCB *app;
        OSHKSTARTUP startup;

        app = &(OsAppTable[i]);


        OSSetCurApp (i);

        /*
         * OS data including OS application structure ('app' points to it) is not
         * available in user mode therefore startup() address is
         * calculated before jump to user mode
         */
        startup = OSGetAppStartupHook (app);

        if (startup != 0U)
        {
            #if defined(OSMEMPROTECTION)
            void *stackStore = (void *) OSGETSTACKPOINTER ();
            OSDWORD *tos = OSSTACKTOP - (OSDWORD)OSSTKADDS;

            /* In SC3/4 classes app. specific startup hooks use the common stack */
            OSMP_STACK_DESC ((OSDWORD) OSSTACKBOTTOM, (OSDWORD) tos);
            OSLOADSP (tos);

            #if (OSNNOTTRUSTEDAPPS > 0U)
            if (OSMP_IS_NONTRUSTEDAPP (i))
            {
                OSMP_APP_OPEN_DATA ();
                OS2UserMode ();
                startup ();
                /*
                 * @violates @ref Os_setup_c_REF_16_10_1 MISRA 2004 Required Rule 16.10, Ignoring return value of function
                 */
                OS2SystemMode ();       /* to supervisor mode */
            }
            else
            #endif
            #endif /* defined(OSMEMPROTECTION) */
            {
                startup ();
            }
            #if defined(OSSYSSTKCHECK)
            OSSTKSETGUARD (OSSTACKBOTTOM);      /* common stack initialization */
            #endif
            #if defined(OSMEMPROTECTION)
            OSStackEnableAccess ();     /* restore OS rights for osstack area */
            OSLOADSP (stackStore);
            #endif
            OSCLEARSUSPENDLEVELS ();
        }
    }

    OSSetCurApp (i);            /* set OSINVALID_OSAPPLICATION */
}
#endif /* defined(OSAPPHOOKSTARTUP) */

/******************************************************************************
 * Function :   OSShutdownOS
 *
 * Description: Calls shutdown hook, disables interrupts from system timers,
 *              Sets Power-down mode
 *
 * Returns:     never
 *
 ******************************************************************************/
OSUSE_FRAME void OSShutdownOS (StatusType error)
{
    #if defined(OSCWPPC)
    #pragma unused( error )        /* to suppress warning about unused variable */
    #endif


    #if defined(OSAPPLICATION)
    #if defined(OSAPPHOOKSHUTDOWN) || (defined(OSMULTICORE) && (OSNSPINLOCKS > 0U))
    OSCARDINAL i;
    #endif
    #endif

    OSMPC_DCI ();            /* disable ALL interrupts    */
    OSMSYNC ();


    #if defined(OSMEMPROTECTION)
    OSStackEnableAccess ();    /* restore OS rights for osstack area */
    #endif

    #if defined(OSTIMINGPROTECTION)
    OSTPTimerShutdown ();        /* shutdown timing protection timer (hardware) */
    #endif

    #if defined(OSSYSTIMER) || defined(OS2SYSTIMER)
    OSShutdownSystemTimer ();    /* shutdown system timer (hardware)        */
    #endif

    #if defined(OSHOOKSHUTDOWN) || defined(OSAPPHOOKSHUTDOWN)

    OSOrtiSetServiceWatch (OSServiceId_ShutdownHook);    /* set watch to this service */
    OSCLEARSUSPENDLEVELS();

    #if defined(OSAPPLICATION)
    #if defined(OSAPPHOOKSHUTDOWN)
    OsIsrLevel |= OSISRLEVELHOOKAPPSHUTDOWN;
    /* Application specific shutdown hooks */
    for (i = 0U; i < OSNAPPS; i++)
    {
        OSAPPCB* app;
        OSHKSHUTDOWN shutdown;
    
        app = &(OsAppTable[i]);
        OSSetCurApp (i);
    
        /* OS data including OS application structure ('app' points to it) is not avaliable in user mode
           therefore shutdown() address is calculated before jump to user mode  */
        shutdown = OSGetAppShutdownHook (app);
    
        if (shutdown != 0U)
        {
            #if defined(OSMEMPROTECTION)
            OSDWORD *tos = OSSTACKTOP - (OSDWORD)OSSTKADDS;
    
            OSMP_STACK_DESC ((OSDWORD) OSSTACKBOTTOM, (OSDWORD) tos);
            OSLOADSP (tos);
    
            #if (OSNNOTTRUSTEDAPPS > 0U)
            if (OSMP_IS_NONTRUSTEDAPP (i))
            {
                OSMP_APP_OPEN_DATA ();
                OS2UserMode ();
                shutdown (error);
                /*
                 * @violates @ref Os_setup_c_REF_16_10_1 MISRA 2004 Required Rule 16.10, Ignoring return value of function
                 */
                OS2SystemMode(); /* to supervisor mode */
            }
            else
            #endif
            #endif  /* defined(OSMEMPROTECTION) */
            {
                shutdown (error);
            }
    
            #if defined(OSMEMPROTECTION)
            OSStackEnableAccess ();    /* restore OS rights for osstack area */
            #endif
            OSCLEARSUSPENDLEVELS();
            /* no stack restoration here as it is indifferent which one is used farther */
        }
    }

    OsIsrLevel &= ~OSISRLEVELHOOKAPPSHUTDOWN;
    OSSetCurApp (i);            /* set OSINVALID_OSAPPLICATION */

    #endif /* defined(OSAPPHOOKSHUTDOWN) */
    #endif /* defined(OSAPPLICATION) */


    #if defined(OSHOOKSHUTDOWN)
    OsIsrLevel |= OSISRLEVELHOOKSHUTDOWN;
    ShutdownHook (error);
    OsIsrLevel &= (OSISRLEVELTYPE) (~OSISRLEVELHOOKSHUTDOWN);
    #endif

    OSOrtiServiceWatchOnExit (OSServiceId_ShutdownHook);        /* clean service watch on hook leaving  */


    #endif /* defined(OSHOOKSHUTDOWN) || defined(OSAPPHOOKSHUTDOWN) */

    /* Set Power-down mode */
    OSOrtiServiceWatchOnExit (OSServiceId_ShutdownOS);  /* clean service watch on leaving service  */

    OSSETHID0 ((OSDWORD)(OSGETHID0 () & 0xFF1FFFFFul) | OSHID0_SLEEP);   /* Enable SLEEP mode  */
    OSSETMSR (OSGETMSR () | OSMSR_POW);                         /* set POW bit in MSR */

    for (;;)
    {
    }                           /* wait forever */

    OSWARNSUPPRESS
}

/******************************************************************************
 * Function:    OS_ShutdownOS
 *
 * Description: Shutdown OS
 *
 * Returns:     only if the call is not allowed
 *
 * Notes:       disables all interrupts and stops CPU
 *
 ******************************************************************************/
void
OS_ShutdownOS (StatusType error)
{
    OSOrtiSetServiceWatch (OSServiceId_ShutdownOS); /* set watch to this service */

    #if defined(OSMEMPROTECTION)
    #if (OSNNOTTRUSTEDAPPS > 0U)
    if ((OSGetCurApp () < OSNNOTTRUSTEDAPPS) && ((OsIsrLevel & OSISRLEVELHOOKERROR) == 0U))
    {   /* if current app is non-trusted, and call is not from ErrorHook */
        OSOrtiServiceWatchOnExit (OSServiceId_ShutdownOS);
        /*
         * @violates @ref Os_setup_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return;
    }
    #endif
    #endif

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck
        (OSISRLEVELTASKMASK | OSISRLEVELHOOKERROR | OSISRLEVELHOOKAPPERROR | OSISRLEVELHOOKSTARTUP | OSISRLEVELHOOKAPPSTARTUP)
        )
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            #if defined(OSHOOKERROR_EXT)
            OSErrorHook (E_OS_DISABLEDINT, OSServiceId_ShutdownOS, 0U);
            #endif
            OSOrtiServiceWatchOnExit (OSServiceId_ShutdownOS);
            /*
             * @violates @ref Os_setup_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return;
        }
        else
        #endif /* OSEXTSTATUS */
        {
            #if defined(OSHOOKERROR_EXT)
            OSErrorHook (E_OS_CALLEVEL, OSServiceId_ShutdownOS, 0U);
            #endif
            OSOrtiServiceWatchOnExit (OSServiceId_ShutdownOS);
            /*
             * @violates @ref Os_setup_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return;
        }
    }
    #endif /* OSCHECKCONTEXT */

    OSShutdownOS (error);
    /* never return here */
}

#if defined(OSCHECKCONTEXT)
/******************************************************************************
 * Function :   GetActiveApplicationMode
 *
 * Description: 
 *
 * Returns:     AppModeType
 *
 ******************************************************************************/
AppModeType
OS_GetActiveApplicationMode (void)
{
    OSOrtiSetServiceWatch (OSServiceId_GetActiveApplicationMode);

    #if defined(OSHOOKERROR_EXT)
    #if defined(OSEXTSTATUS)
    if (OSIsrLevelCheck (OSISRLEVELDISABLEDINTERRUPTS | OSISRLEVELTASKMASK |
                         OSISRLEVELHOOKERROR | OSISRLEVELHOOKAPPERROR |
                         OSISRLEVELHOOKTASK |
                         OSISRLEVELHOOKSTARTUP | OSISRLEVELHOOKAPPSTARTUP |
                         OSISRLEVELHOOKSHUTDOWN | OSISRLEVELHOOKAPPSHUTDOWN))
    {
        if (OSIsrLevelCheck (OSISRLEVELDISABLEDINTERRUPTS))
        {
            OSErrorHook (E_OS_DISABLEDINT, OSServiceId_GetActiveApplicationMode, 0U);
        }
    #else
        if (OSIsrLevelCheck
            (OSISRLEVELTASKMASK | OSISRLEVELHOOKERROR | OSISRLEVELHOOKAPPERROR | OSISRLEVELHOOKTASK | OSISRLEVELHOOKSTARTUP |
            OSISRLEVELHOOKSHUTDOWN)
           )
        {
    #endif
            OSErrorHook (E_OS_CALLEVEL, OSServiceId_GetActiveApplicationMode, 0U);
        }
    }
    #endif /* defined(OSHOOKERROR_EXT) */

    OSOrtiServiceWatchOnExit (OSServiceId_GetActiveApplicationMode);

    return (OSCURAPPMODE);
}

#else /* defined(OSCHECKCONTEXT) */

AppModeType
OS_GetActiveApplicationMode (void)
{
    #if defined(OSORTICURRENTSERVICEID)
    OSOrtiSetServiceWatch (OSServiceId_GetActiveApplicationMode);
    OSOrtiServiceWatchOnExit (OSServiceId_GetActiveApplicationMode);
    #endif /* defined(OSORTICURRENTSERVICEID) */

    return (OSCURAPPMODE);
}

#endif /* defined(OSCHECKCONTEXT) */

#define OSTEXT_STOP_SEC_CODE
/*
* @violates @ref Os_setup_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"



#ifdef __cplusplus
}
#endif



/** @} */
