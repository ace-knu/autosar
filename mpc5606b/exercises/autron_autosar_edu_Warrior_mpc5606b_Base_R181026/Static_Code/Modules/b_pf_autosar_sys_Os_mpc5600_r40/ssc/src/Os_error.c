/**
*   @file    Os_error.c
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
* @section Os_error_c_REF_5_1_1
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters. 
* The section identification define's naming convention is defined by AutoSar and identifiers are longer than 31 character. 
* Compilers are checked for support this length of identifiers.
*
* @section Os_error_c_REF_16_10_1
* Violates MISRA 2004 Required Rule 16.10, Ignoring return value of function
* If a function returns error information, then that error information shall be tested.
* Function OS2SystemMode is used for switching to system mode and it is not supposed 
* to analyze the return value where it is called.
*
* @section Os_error_c_REF_19_1_1
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

#include <Os_memory_api.h>      /* for OSMP_IS_NONTRUSTEDAPP   */

#include <Os_error_api.h>
#include <Os_error_internal_api.h>
#include <Os_error_internal_types.h>

#include <Os_hook_api.h>        /* for OsViolatorTaskId* variables declaration */


/*
* @violates @ref Os_error_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSTERMINATION)

OSDECLAREVAR (OSNEAR OSBYTE, OsKilled_);        /* flags that Task or ISR was killed or some TP context */

#if defined(OSHOOKPROTECTION)
OSDECLAREVAR (OSNEAR TaskType, OsViolatorTaskId_);      /* Task Id of task which has violated */
OSDECLAREVAR (OSNEAR ISRType, OsViolatorISRId_);        /* ISR2 Id of ISR2 which has violated */
#if defined(OSAPPLICATION)
OSDECLAREVAR (OSNEAR ApplicationType, OsViolatorAppId_);        /* Application Id of runnable which has violated */
#endif
#endif /* defined(OSHOOKPROTECTION) */

#endif /* defined(OSTERMINATION) */

/*
* @violates @ref Os_error_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_error_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

/*
* @violates @ref Os_error_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_START_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_error_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if defined(OSGETSERVICEID) || defined(OSPARAMETERACCESS)
OSDECLAREVAR (OSNEAR OSServiceIdType, OsService_);      /* for OSErrorGetServiceId() from ErrorHook */
OSDECLAREVAR (OSNEAR OSDWORD, OsObjId_);        /* for first parameter                      */
#endif /* defined(OSGETSERVICEID) || defined(OSPARAMETERACCESS) */

/*
* @violates @ref Os_error_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_error_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#define OSTEXT_START_SEC_CODE
/*
* @violates @ref Os_error_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if defined(OSAPPLICATION)
#if defined(OSAPPHOOKERROR)
/***************************************************************************
 * inline function  : OSGetAppErrorHook
 *
 * Description:
 *
 * Returns: application specific error hook address
 *
 * Notes: none
 **************************************************************************/
static OSINLINE OSHKERROR
OSGetAppErrorHook (const OSAPPCB* app)
{
    return app->error;
}

/******************************************************************************
 * function:       OSCallAppErrorHook
 *
 * Description: calls user defined application specific hook (if any)
 *
 * Returns: none
 *
 * Notes:
 ******************************************************************************/
static OSINLINE void
OSCallAppErrorHook (StatusType error)
{
    
    OSHKERROR appErrorHook;
    OSAPPCB *app;

    if (OSGetCurApp () != OSINVALID_OSAPPLICATION)
    {
        app = &OsAppTable[OSGetCurApp ()];
        appErrorHook = OSGetAppErrorHook (app);

        if (appErrorHook != 0U)
        {
            #if (OSNNOTTRUSTEDAPPS > 0U)
            if (OSMP_IS_NONTRUSTEDAPP (OSGetCurApp ()))
            {
                OSMP_APP_OPEN_DATA ();
                OS2UserMode ();
                appErrorHook (error); /* call application specific error hook */
                /*
                * @violates @ref Os_error_c_REF_16_10_1 MISRA 2004 Required Rule 16.10, Ignoring return value of function
                */
                OS2SystemMode ();     /* to supervisor mode */
            }
            else
            #endif /* (OSNNOTTRUSTEDAPPS > 0U) */
            {
                appErrorHook (error); /* call application specific error hook */
            }
        }
    }
}

#endif /* defined(OSAPPHOOKERROR) */
#endif /* defined(OSAPPLICATION) */

#if defined(OSHOOKERROR) || defined(OSAPPHOOKERROR)

#if defined(OSGETSERVICEID) || defined(OSPARAMETERACCESS)

/******************************************************************************
 * Function:    OSErrorHook
 * Description: calls user defined hook if not nested
 * Returns:
 * Notes:       2 variants - differ in number of arguments
 ******************************************************************************/
void
OSErrorHook (StatusType error, OSServiceIdType ID, OSObjectType param)
#else
void
OSErrorHook_1 (StatusType error)
#endif
{
    
    OSISRLEVELTYPE oldIsrLevel;
    OSBYTE oldSuspendLevelAll;
    OSINTMASKTYPE oldIntMaskAll;
    OSINTMASKTYPE oldInterruptMask;
    OSDWORD oldMsr;

    #if defined(OSISRENTRYEXIT)
    OSBYTE oldSuspendLevel;
    #endif

    OSPUTERROR (error);

    if ((OsIsrLevel & (OSISRLEVELHOOKERROR | OSISRLEVELHOOKAPPERROR)) == 0U)     /* if not nested call */
    {
        #if defined(OSISRENTRYEXIT)
        if ((OsSuspendLevel == 0U) && ((OsIsrLevel & (OSISRLEVELHOOKTASK)) == 0U))
        {   /* if called not from Pre/PostTaskHook */
            OSSuspendInterrupts ();     /* disable OS interrupts */
            /* and increase counter of nested Suspend/Resume pairs */
        }
        else
        {
            OsSuspendLevel++;   /* increase counter of nested Suspend/Resume pairs */
        }
        #endif

        OSPUTPARAM (ID, param);

        oldIsrLevel = OsIsrLevel;               /* save old value, then clear context flags */
        OsIsrLevel = (OsIsrLevel & OSISRLEVELMASK) | OSISRLEVELHOOKERROR; /* and set ErrorHook flag */
        oldSuspendLevelAll = OsSuspendLevelAll; /* save SuspendAllInterrupts() calls counter */
        OsSuspendLevelAll = 0U;
        oldMsr = OsOldMsr;                      /* save OsOldMsr */
        oldIntMaskAll = OsOldIntMaskAll;        /* save OsOldIntMaskAll */
        oldInterruptMask = OsOldInterruptMask;  /* save copy of IPL */

        #if defined(OSISRENTRYEXIT)
        oldSuspendLevel = OsSuspendLevel;       /* save SuspendOSInterrupts() calls counter */
        OsSuspendLevel = 0U;
        #endif
        
        #if defined(OSHOOKERROR)
        OSOrtiSetServiceWatch (OSServiceId_ErrorHook); /* set watch to this service */
        ErrorHook (error);
        OSOrtiServiceWatchOnExit (OSServiceId_ErrorHook); /* clean service watch on hook leaving */
        #endif

        #if defined(OSAPPHOOKERROR)
        OsIsrLevel = (OsIsrLevel & OSISRLEVELMASK) | OSISRLEVELHOOKAPPERROR; /* set flag for context checking */
        OsSuspendLevelAll = 0U;
        OsOldInterruptMask = oldInterruptMask;  /* restore copy of IPL */
        OsOldIntMaskAll = oldIntMaskAll;        /* restore OsOldIntMaskAll */
        OsOldMsr = oldMsr;                      /* restore OsOldMsr */
        #if defined(OSISRENTRYEXIT)
        OsSuspendLevel = 0U;
        #endif
        OSCallAppErrorHook (error);
        #endif /* defined(OSAPPHOOKERROR) */

        #if defined(OSISRENTRYEXIT)
        OsSuspendLevel = oldSuspendLevel;       /* restore SuspendOSInterrupts() calls counter */
        #endif
        
        OsOldInterruptMask = oldInterruptMask;  /* restore copy of IPL */
        OsOldIntMaskAll = oldIntMaskAll;        /* restore OsOldIntMaskAll */
        OsOldMsr = oldMsr;                      /* restore OsOldMsr */
        OsSuspendLevelAll = oldSuspendLevelAll; /* restore SuspendAllInterrupts() calls counter */
        OsIsrLevel = oldIsrLevel;               /* restore ISR level */

        OSCLEARPARAM ();

        #if defined(OSISRENTRYEXIT)
        if ((OsSuspendLevel == 1U) && ((OsIsrLevel & (OSISRLEVELHOOKTASK)) == 0U))
        {   /* if called not from Pre/PostTaskHook */
            OSResumeInterrupts ();      /* restore OS interrupts */
            /* and decrease counter of nested Suspend/Resume pairs */
        }
        else
        {
            OsSuspendLevel--;   /* decrease counter of nested Suspend/Resume pairs */
        }
        #endif
    }
}

/******************************************************************************
 * Function:    OSErrorHook_noPar
 * Description: calls user defined hook if not nested
 * Returns:
 * Notes:       called from internal OS functions with interrupts disabled
 ******************************************************************************/
void
OSErrorHook_noPar (StatusType error)
{
    
    OSISRLEVELTYPE oldIsrLevel;
    OSBYTE oldSuspendLevelAll;
    OSINTMASKTYPE oldIntMaskAll;
    OSINTMASKTYPE oldInterruptMask;
    OSDWORD oldMsr;

    #if defined(OSISRENTRYEXIT)
    OSBYTE oldSuspendLevel;
    #endif

    OSPUTERROR (error);

    if ((OsIsrLevel & (OSISRLEVELHOOKERROR | OSISRLEVELHOOKAPPERROR)) == 0U)     /* if not nested call */
    {

        oldIsrLevel = OsIsrLevel;               /* save old value, then clear context flags */
        OsIsrLevel = (OsIsrLevel & OSISRLEVELMASK) | OSISRLEVELHOOKERROR; /* and set ErrorHook flag */
        oldSuspendLevelAll = OsSuspendLevelAll; /* save SuspendAllInterrupts() calls counter */
        OsSuspendLevelAll = 0U;
        oldMsr = OsOldMsr;      /* save OsOldMsr */
        oldIntMaskAll = OsOldIntMaskAll;        /* save OsOldIntMaskAll */
        oldInterruptMask = OsOldInterruptMask;  /* save copy of IPL */

        #if defined(OSISRENTRYEXIT)
        oldSuspendLevel = OsSuspendLevel;       /* save SuspendOSInterrupts() calls counter */
        OsSuspendLevel = 0U;
        #endif

        #if defined(OSHOOKERROR)
        OSOrtiSetServiceWatch (OSServiceId_ErrorHook);  /* set watch to this service */
        ErrorHook (error);
        OSOrtiServiceWatchOnExit (OSServiceId_ErrorHook); /* clean service watch on hook leaving */
        #endif

        #if defined(OSAPPHOOKERROR)
        
        OsIsrLevel = (OsIsrLevel & OSISRLEVELMASK) | OSISRLEVELHOOKAPPERROR; /* set flag for context checking */
        OsSuspendLevelAll = 0U;
        OsOldInterruptMask = oldInterruptMask;  /* restore copy of IPL */
        OsOldIntMaskAll = oldIntMaskAll;        /* restore OsOldIntMaskAll */
        OsOldMsr = oldMsr;                      /* restore OsOldMsr */

        #if defined(OSISRENTRYEXIT)
        OsSuspendLevel = 0U;
        #endif

        OSCallAppErrorHook (error);

        #endif /* defined(OSAPPHOOKERROR) */

        #if defined(OSISRENTRYEXIT)
        OsSuspendLevel = oldSuspendLevel;       /* restore SuspendOSInterrupts() calls counter */
        #endif

        OsOldInterruptMask = oldInterruptMask;  /* restore copy of IPL */
        OsOldIntMaskAll = oldIntMaskAll;        /* restore OsOldIntMaskAll */
        OsOldMsr = oldMsr;                      /* restore OsOldMsr */
        OsSuspendLevelAll = oldSuspendLevelAll; /* restore SuspendAllInterrupts() calls counter */
        OsIsrLevel = oldIsrLevel;               /* restore ISR level */

    }
}

#endif /* defined(OSHOOKERROR) || defined(OSAPPHOOKERROR) */

#define OSTEXT_STOP_SEC_CODE
/*
* @violates @ref Os_error_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif



/** @} */
