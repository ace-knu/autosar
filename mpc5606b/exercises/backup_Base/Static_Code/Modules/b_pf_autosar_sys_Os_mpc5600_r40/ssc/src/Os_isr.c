/**
*   @file    Os_isr.c
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
* @section Os_isr_c_REF_5_1_1
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters. 
* The section identification define's naming convention is defined by AutoSar and identifiers are longer than 31 character. 
* Compilers are checked for support this length of identifiers.
*
* @section Os_isr_c_REF_14_7_1
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function 
* A function shall have a sigle point of exit at the end of finction.
* The returned statement is result of error hanling.
*
* @section Os_isr_c_REF_16_10_1
* Violates MISRA 2004 Required Rule 16.10, Ignoring return value of function
* If a function returns error information, then that error information shall be tested.
* Function OSLongJmp is used for switching context and it is not supposed to return to the place where it is called.
* Function OS2SystemMode is used for switching to system mode and it is not supposed 
* to analyze the return value where it is called.
*
* @section Os_isr_c_REF_17_4_1
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* Array indexing shall be the only allowed form of pointer arithmetic
* The pointers are used to increase of OS performance.
*
* @section Os_isr_c_REF_19_1_1
* Violates MISRA 2004 Advisory Rule 19.1, declaration before #include
* #include statements in a file should only be preceded by other preprocessor directives or comments. 
* MemMap is required by AutoSAR to be included in the middle of the source file(s).
*
* @section Os_isr_c_REF_19_4_1
* Violates MISRA 2004 Required Rule 19.4, Expression-like macro not parenthesized
* The macro cannot be parenthesized because of assembler limitation, in all instances of
* this macro usage the macro is in brackets.
*
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

#include <Os_task_api.h> /* for INVALID_TASK */
#include <Os_isr_api.h>
#include <Os_isr_internal_api.h>
#include <Os_isr_internal_types.h>
#include <Os_isr_config.h>

#include <Os_stack_internal_api.h>
#include <Os_resource_internal_api.h>

/*
* @violates @ref Os_isr_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSISRENTRYEXIT) && defined (OSHOOKERROR_EXT)
OSDECLAREVAR (OSNEAR OSDWORD, OsIntCheck_);     /* check correct order of the nested Suspend/Resume pairs */
#endif

/*
* @violates @ref Os_isr_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

/*
* @violates @ref Os_isr_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"


/*
* @violates @ref Os_isr_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_isr_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#define OS_START_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_isr_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if defined(OSTERMINATION)
#if (OSNIPLSP > 0U)
OSJMP_BUF OsISRbufs[OSNIPLSP];  /* jump buffers for skipping killed ISRs */
#endif
#endif /* defined(OSTERMINATION) */

#define OS_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_isr_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#define OS_START_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_isr_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if (OSNISR > 0U)

#if (OSNIPLSP > 0U)
OS_ISRTYPEPTR OsIsrArray[OSNIPLSP];     /* its index is OsIsrLevel */
#endif


OS_ISRTYPE OsIsrTable[OSNISR + 1U];

#endif /* OSNISR > 0U */

#define OS_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_isr_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

/*
* @violates @ref Os_isr_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_START_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_isr_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


OSDECLAREVAR (OSNEAR OSDWORD, OsOldMsr_);                 /* Saved MSR for EnableAll/DisableAllInterrupts */
OSDECLAREVAR (OSNEAR OSBYTE, OsSuspendLevelAll_);         /* level of the nested Suspend/ResumeAll pairs */
OSDECLAREVAR (OSNEAR OSINTMASKTYPE, OsOldIntMaskAll_);    /* SuspendAll/ResumeAllInterrupts services */
OSDECLAREVAR (OSNEAR OSINTMASKTYPE, OsOldInterruptMask_); /* Saved interrupt mask for SuspendOS/ResumeOSInterrupts services and for Hooks */

#if defined(OSISRENTRYEXIT)
OSDECLAREVAR (OSNEAR OSBYTE, OsSuspendLevel_);            /* level of the nested Suspend/Resume pairs */
#endif

#if defined(OSUSEISRLEVEL)

OSDECLAREVAR (OSNEAR OSISRLEVELTYPE, OsIsrLevel_);        /* num of active ISRs & context bits */

#if defined(OSISRENTRYEXIT) || (!defined(OSSC1))
OSDECLAREVAR (OSNEAR OSDWORD, OsInitialMSR_);             /* saved initial MSR */
#endif

#endif /* defined(OSUSEISRLEVEL) */

/*
* @violates @ref Os_isr_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_isr_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if defined(OSUSERVTABLE) && defined(OSMULTICORE)
#define APP_START_SEC_CODE
#include "MemMap.h"

extern void UserInitVectors (void);

#define APP_STOP_SEC_CODE
#include "MemMap.h"
#endif


#define OSTEXT_START_SEC_CODE
/*
* @violates @ref Os_isr_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#define OS_START_SEC_CONST_UNSPECIFIED
/*
* @violates @ref Os_isr_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if !defined(OSCALCULATEOBJIND)
#define handlerInd (handlerId)
#endif

/*************************    Private OS Services    ***************************/

OSINLINE OSDWORD
OSGetMsrDI (void)
{
    register OSDWORD msr;
    msr = OSGETMSR ();
    OSSETMSR (msr & ~(OSMSR_EE | OSMSR_CE));
    return msr;
}

/*************************    Public OS Services    ***************************/

#if !defined(OSEXTSTATUS)


/******************************************************************************
 * ex-Macro:    DisableAllInterrupts
 * Description: OSEK Service
 * Returns:     none
 ******************************************************************************/
void
OS_DisableAllInterrupts (void)
{
    OSGETCOREID 
    OSOrtiSetServiceWatch (OSServiceId_DisableAllInterrupts);
    OsOldMsr = OSGetMsrDI ();
    OSOrtiServiceWatchOnExit (OSServiceId_DisableAllInterrupts);
}


/******************************************************************************
 * ex-Macro:    EnableAllInterrupts
 * Description: OSEK Service
 * Returns:     none
 * Notes:       shall be called only after DisableAllInterrupts
 ******************************************************************************/
void
OS_EnableAllInterrupts (void)
{
    OSGETCOREID 
    OSOrtiSetServiceWatch (OSServiceId_EnableAllInterrupts);
    OSMSYNC ();
    OSSETMSR (OsOldMsr);
    OSOrtiServiceWatchOnExit (OSServiceId_EnableAllInterrupts);
}

#else /* !defined(OSEXTSTATUS) */


/******************************************************************************
* Function: DisableAllInterrupts
* Description: OSEK Service
* Return: none
******************************************************************************/
void
OS_DisableAllInterrupts (void)
{
    OSOrtiSetServiceWatch (OSServiceId_DisableAllInterrupts);

    if ((OsIsrLevel & OSISRLEVELDISABLEDINT) == 0U)
    {
        OsOldMsr = OSGetMsrDI ();
        OsIsrLevel |= OSISRLEVELDISABLEDINT;
        OsSuspendLevelAll++;    /* it is checked in OSInterruptDispatcher for pairing */
    }

    #if defined(OSHOOKERROR_EXT)
    else
    {
        OSErrorHook (E_OS_DISABLEDINT, OSServiceId_DisableAllInterrupts, 0U);
    }
    #endif

    OSOrtiServiceWatchOnExit (OSServiceId_DisableAllInterrupts);
}


/******************************************************************************
 * Function:    EnableAllInterrupts
 * Description: OSEK Service
 * Return:      none
 * Notes:       shall be called only after DisableAllInterrupts
 ******************************************************************************/
void
OS_EnableAllInterrupts (void)
{
    OSOrtiSetServiceWatch (OSServiceId_EnableAllInterrupts);

    if (OsIsrLevel & OSISRLEVELDISABLEDINT)
    {
        OsSuspendLevelAll--;    /* decrease counter of nested Suspend/Resume pairs */
        OsIsrLevel &= ~OSISRLEVELDISABLEDINT;
        OSMSYNC ();
        OSSETMSR (OsOldMsr);
    }

    #if defined(OSHOOKERROR_EXT)
    else
    {
        OSErrorHook (E_OS_SYS_ORDER, OSServiceId_EnableAllInterrupts, 0U);
    }
    #endif

    OSOrtiServiceWatchOnExit (OSServiceId_EnableAllInterrupts);
}

#endif /* !defined(OSEXTSTATUS) */


/******************************************************************************
 * Function:    SuspendAllInterrupts
 *
 * Description: Save interrupt state and disable all interrupts
 *
 * Return:      none
 *
 * Notes:
 ******************************************************************************/
void
OS_SuspendAllInterrupts (void)
{
    OSOrtiSetServiceWatch (OSServiceId_SuspendAllInterrupts);

    #if defined(OSEXTSTATUS)
    if ((OsIsrLevel & OSISRLEVELDISABLEDINT) == 0U)
    {
    #endif

        if (OsSuspendLevelAll == 0U)
        {                       /* if it is the first call to SuspendAllInterrupts, then disable */
            OsOldIntMaskAll = OSGetMsrDI ();    /* disable all ext.interrupts */
            #if defined(OSEXTSTATUS)
            OsIsrLevel |= OSISRLEVELDISABLEDINTALL;
            #endif
        }

        #if defined(OSHOOKERROR_EXT) && defined(OSISRENTRYEXIT)
        /* it is limited to nesting level of 32 */
        OsIntCheck |= 0x1U << (OsSuspendLevel + OsSuspendLevelAll);
        #endif

        OsSuspendLevelAll++;    /* increase counter of nested Suspend/Resume pairs */

    #if defined(OSEXTSTATUS)
    }
    #if defined(OSHOOKERROR_EXT)
    else
    {
        OSErrorHook (E_OS_DISABLEDINT, OSServiceId_SuspendAllInterrupts, 0U);
    }
    #endif

    #endif /* defined(OSEXTSTATUS) */

    OSOrtiServiceWatchOnExit (OSServiceId_SuspendAllInterrupts);
}


/******************************************************************************
 * Function:    ResumeAllInterrupts
 *
 * Description: Restore interrupt state saved by SuspendAllInterrupts service
 *
 * Return:      none
 *
 * Notes:
 ******************************************************************************/
void
OS_ResumeAllInterrupts (void)
{
    OSOrtiSetServiceWatch (OSServiceId_ResumeAllInterrupts);

    #if defined(OSEXTSTATUS)
    if ((OsIsrLevel & OSISRLEVELDISABLEDINT) == 0U)
    {
    #endif
        if (OsSuspendLevelAll == 0U)
        {
            #if defined(OSHOOKERROR_EXT)
            OSErrorHook (E_OS_SYS_ORDER, OSServiceId_ResumeAllInterrupts, 0U);
            #endif
            
            OSOrtiServiceWatchOnExit (OSServiceId_ResumeAllInterrupts);
            /*
             * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return;
        }

        #if defined(OSHOOKERROR_EXT) && defined(OSISRENTRYEXIT)
        /* it is limited to nesting level of 32 */
        if ((OsIntCheck & (0x1U << (OsSuspendLevel + OsSuspendLevelAll - 1U))) == 0U)
        {
            OSErrorHook (E_OS_SYS_ORDER, OSServiceId_ResumeAllInterrupts, 0U);
        }
        #endif

        OsSuspendLevelAll--;    /* decrease counter of nested Suspend/Resume pairs */

        if (OsSuspendLevelAll == 0U)     /* if at outmost level of Suspend/Resume pair, restore interrupt level */
        {
            #if defined(OSEXTSTATUS)
            OsIsrLevel &= ~OSISRLEVELDISABLEDINTALL;
            #endif
            
            OSMSYNC ();
            OSSETMSR (OsOldIntMaskAll);
            OSOrtiServiceWatchOnExit (OSServiceId_ResumeAllInterrupts);
            /*
             * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return;
        }                       /* otherwise nothing to do  */

    #if defined(OSEXTSTATUS)
    }
    #if defined(OSHOOKERROR_EXT)
    else
    {
        OSErrorHook (E_OS_DISABLEDINT, OSServiceId_ResumeAllInterrupts, 0U);
    }
    #endif
    #endif /* defined(OSEXTSTATUS) */

    OSOrtiServiceWatchOnExit (OSServiceId_ResumeAllInterrupts);
}

#if defined(OSISRENTRYEXIT)

/******************************************************************************
 * Function:    SuspendOSInterrupts
 *
 * Description: Save interrupt state and disable all OS interrupts
 *
 * Return:      none
 *
 * Notes:
 ******************************************************************************/
void
OS_SuspendOSInterrupts (void)
{
    OSINTMASKTYPE currentIPL;

    OSOrtiSetServiceWatch (OSServiceId_SuspendOSInterrupts);

    #if defined(OSEXTSTATUS)
    if ((OsIsrLevel & OSISRLEVELDISABLEDINT) == 0U)
    {
    #endif
        currentIPL = OSISRGetPrio ();
        #if !defined(OSNOISR1)
        if (currentIPL > OSHIGHINTPRIO)
        {                       /* nothing to do in ISR1 */
            OSOrtiServiceWatchOnExit (OSServiceId_SuspendOSInterrupts);
            /*
             * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return;
        }
        #endif

        if (OsSuspendLevel == 0U)        /* if first call of Suspend Interrupts, then disable them */
        {

            #if defined(OSHOOKS)
            if ((OsIsrLevel & (OSISRLEVELHOOKANY)) == 0U)
            #endif
            {                   /* tasks and ISRs cat.2 */
                OSISRSetPrio (OSHIGHISRPRIO);
                OSMSYNC ();
                OsOldInterruptMask = currentIPL;
                OSTPStartIntLockTime ();
            }

            #if defined(OSEXTSTATUS)
            OsIsrLevel |= OSISRLEVELDISABLEDINTOS;
            #endif
        }

        OsSuspendLevel++;       /* increase counter of nested Suspend/Resume pairs */

        #if defined(OSHOOKERROR_EXT)
        /* it is limited to nesting level of 32 */
        OsIntCheck &= ~(0x1U << (OsSuspendLevel + OsSuspendLevelAll - 1U));
        #endif

    #if defined(OSEXTSTATUS)
    }
    #if defined(OSHOOKERROR_EXT)
    else
    {
        OSErrorHook (E_OS_DISABLEDINT, OSServiceId_SuspendOSInterrupts, 0U);
    }
    #endif
    #endif /* defined(OSEXTSTATUS) */

    OSOrtiServiceWatchOnExit (OSServiceId_SuspendOSInterrupts);
}

/******************************************************************************
 * Function:    ResumeOSInterrupts
 *
 * Description: Restore interrupt state saved by SuspendOSInterrupts service
 *
 * Returns:     none
 *
 * Notes:       allows nesting
 ******************************************************************************/
void
OS_ResumeOSInterrupts (void)
{
    OSOrtiSetServiceWatch (OSServiceId_ResumeOSInterrupts);

    #if defined(OSEXTSTATUS)
    if ((OsIsrLevel & OSISRLEVELDISABLEDINT) == 0U)
    {
    #endif

        #if !defined(OSNOISR1)
        if (OSISRGetPrio () > OSHIGHINTPRIO)
        {                       /* nothing to do in ISR1 */
            OSOrtiServiceWatchOnExit (OSServiceId_ResumeOSInterrupts);
            /*
             * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return;
        }
        #endif

        if (OsSuspendLevel == 0U)
        {
            #if defined(OSHOOKERROR_EXT)
            OSErrorHook (E_OS_SYS_ORDER, OSServiceId_ResumeOSInterrupts, 0U);
            #endif
            OSOrtiServiceWatchOnExit (OSServiceId_ResumeOSInterrupts);
            /*
             * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return;
        }

        #if defined(OSHOOKERROR_EXT)
        /* it is limited to nesting level of 32 */
        if ((OsIntCheck & (0x1U << (OsSuspendLevel + OsSuspendLevelAll - 1U))) != 0U)
        {
            OSErrorHook (E_OS_SYS_ORDER, OSServiceId_ResumeOSInterrupts, 0U);
        }
        #endif

        if (OsSuspendLevel == 1U)
        {                       /* if out most level of Suspend/Resume pair, then restore interrupt state */
            #if defined(OSEXTSTATUS)
            OsIsrLevel &= ~OSISRLEVELDISABLEDINTOS;
            #endif

            #if defined(OSHOOKS)
            if ((OsIsrLevel & (OSISRLEVELHOOKANY)) == 0U)
            #endif
            {
                OSTPStopIntLockTime ();
                OSResumeInterrupts ();  /* restore OS interrupts and  */
                /* decrease counter of nested Suspend/Resume pairs */
            }
            #if defined(OSHOOKS)
            else
            {                   /* hooks */
                OsSuspendLevel--;
            }
            #endif
        }
        else
        {
            OsSuspendLevel--;
        }

    #if defined(OSEXTSTATUS)
    }
    #if defined(OSHOOKERROR_EXT)
    else
    {
        OSErrorHook (E_OS_DISABLEDINT, OSServiceId_ResumeOSInterrupts, 0U);
    }
    #endif
    #endif /* defined(OSEXTSTATUS) */

    OSOrtiServiceWatchOnExit (OSServiceId_ResumeOSInterrupts);
}

/******************************************************************************
 * Function:    GetISRID
 *
 * Description: shows which ISR is running
 *
 * Return:      current ISR Id or INVALID_ISR.
 *
 ******************************************************************************/
ISRType
OS_GetISRID (void)
{
    OSWORD objIndex;

    OSOrtiSetServiceWatch (OSServiceId_GetISRID);

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK | OSISRLEVELHOOKERROR | OSISRLEVELHOOKAPPERROR | OSISRLEVELHOOKPROTECTION))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            #if defined(OSHOOKERROR_EXT)
            OSErrorHook (E_OS_DISABLEDINT, OSServiceId_GetISRID, 0U);
            #endif
            OSOrtiServiceWatchOnExit (OSServiceId_GetISRID);
            /*
             * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return (INVALID_ISR);
        }
        else
        #endif
        {
            #if defined(OSHOOKERROR_EXT)
            OSErrorHook (E_OS_CALLEVEL, OSServiceId_GetISRID, 0U);
            #endif
            OSOrtiServiceWatchOnExit (OSServiceId_GetISRID);
            /*
             * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return (INVALID_ISR);
        }
    }
    #endif /* OSCHECKCONTEXT */

    if (OSISRLEVELMASKED == 0U)
    {
        OSOrtiServiceWatchOnExit (OSServiceId_GetISRID);
        /*
         * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return (INVALID_ISR);
    }
    /*
    * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    objIndex = OsIsrArray[OSISRLEVELMASKED - 1U]->index;

    OSOrtiServiceWatchOnExit (OSServiceId_GetISRID);
    return (ISRType)OS_MKOBJID (OBJECT_ISR, OsIsr[objIndex]);
}

#endif /* defined(OSISRENTRYEXIT) */

/* Prototypes */
void OSInterruptDispatcher1 (void);
#if defined(OSISRENTRYEXIT)
static void OSLeaveISR (void);
#endif
extern void VTABLE (void);

#if !defined(OSNOISR2)
#if defined(OSSTKHOOKPROTECTION)
static void OSStackKillISR (OS_ISRTYPEPTR handlerPtr);
#endif
#endif

#if defined(OSCWPPC)
#if defined(OSE200Z6) || defined(OSE200Z3) || defined(OSE200Z4) || defined(OSE200Z7)
OSASM void OSInitIVORS (void);
#endif
#endif

/* Private OS Services */

/***************************************************************************
 * Function :   OSISRException
 *
 * Description: ISR for catching unregistered interrupts
 *
 * Notes:       called only if unregistered interrupt occurred 
 *
 **************************************************************************/
void
OSISRException (void)
{
    OSPUTERROR (E_OS_SYS_FATAL);
    OSShutdownOS (E_OS_SYS_FATAL);
}

#if defined(OSTERMINATION)
#if !defined(OSNOISR2)
/******************************************************************************
 * function:      OSKillRunningISR(void)
 *
 * Description: kills ISR2 that caused ProtectionHook 
 *
 * Returns: none 
 *
 * Notes:   it is called from protection handler only
 ******************************************************************************/
void
OSKillRunningISR (void)
{
    
    #if defined(OSMEMPROTECTION)
    #if (OSNTRUSTEDFUNCTIONS > 0U)
    OSAPPCB * app;
    #endif
    #endif /* defined(OSMEMPROTECTION) */

    /*
    * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    OS_ISRTYPEPTR handlerPtr = OsIsrArray[OSISRLEVELMASKED - 1U];

    #if defined(OSMEMPROTECTION)
    #if (OSNTRUSTEDFUNCTIONS > 0U)
    app = &OsAppTable[handlerPtr->appId];
    if (0U != app->tfContext)
    {
        app->tfContext = 0U;
        #if defined(OSTPBUDGET)
        app->tpError = 0U;
        #endif
        #if (OSNUSERISR > 0U)
        OSEnableISRs4App (handlerPtr->appId);
        #endif
        OSEnableTasks4App (app);
    }
    #endif /* (OSNTRUSTEDFUNCTIONS > 0U) */
    #endif /* defined(OSMEMPROTECTION) */

    OSTPKillISRBudget ();

    #if defined(OSRESOURCEISR)
    OSReleaseISRResources (handlerPtr);
    #endif

    handlerPtr->isKilled = OSTRUE;

    /*
    * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    OSISRSTKRESTOREPAD (handlerPtr->isrBos);   /* restore stack pad, just in case */

    OSTPKillIntLockTime ();

    OsSuspendLevel = 0U;
    OsSuspendLevelAll = 0U;
    OSCLEARCNTX ();             /* clear all context bits */
}

#if defined(OSSTKHOOKPROTECTION)
/******************************************************************************
 * Function:      OSStackKillISR 
 *
 * Description: kills given ISR2 
 *
 * Returns: none 
 *
 * Notes: May be called only from ISR stack monitoring code
 *        OsIsrLevel is not changed
 ******************************************************************************/
static void
OSStackKillISR (OS_ISRTYPEPTR handlerPtr)
{

    /*
    * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    if (handlerPtr == OsIsrArray[OSISRLEVELMASKED - 1U])        /* running ISR */
    {
        OSTPKillIntLockTime ();
        OsSuspendLevel = 0U;
        OsSuspendLevelAll = 0U;
    }

    #if defined(OSRESOURCEISR)
    OSReleaseISRResources (handlerPtr);
    #endif
}
#endif /* defined(OSSTKHOOKPROTECTION) */

/******************************************************************************
 * Function:      OSKillISR
 *
 * Description: kills given ISR2  
 *
 * Returns: none 
 *
 * Notes:       OsIsrLevel is not changed
 ******************************************************************************/
void
OSKillISR (OS_ISRTYPEPTR handlerPtr)
{


    /*
    * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    if (handlerPtr == OsIsrArray[OSISRLEVELMASKED - 1U])        /* running ISR */
    {
        OSTPKillISRBudget ();

        /*
        * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        OSISRSTKRESTOREPAD (handlerPtr->isrBos);       /* restore stack pad, just in case */

        OSTPKillIntLockTime ();
        OsSuspendLevel = 0U;
        OsSuspendLevelAll = 0U;
        OSCLEARCNTX ();         /* clear all context bits */
    }

    #if defined(OSRESOURCEISR)
    OSReleaseISRResources (handlerPtr);
    #endif

    handlerPtr->isKilled = OSTRUE;
}

#endif /* !defined(OSNOISR2) */
#endif /* defined(OSTERMINATION) */

#if !(defined(OSUSERVTABLE) && defined(OSMULTICORE)) /* If not defined user vector table  */
#if defined(OSE200Z6) || defined(OSE200Z3) || defined(OSE200Z4) || defined(OSE200Z7)
/***************************************************************************
 * Function : OSInitIVORS
 *
 * Description: initializes all IVORS to point to vector table
 *
 * Returns: none
 *
 **************************************************************************/

OSASM void
OSInitIVORS (void)
{
    #if defined(OSCWPPC)
    nofralloc
    #endif

    e_lis r0, VTABLE@ha   /*                                                             */
    e_add16i r0, r0, VTABLE@l     /*                                                             */
    e_rlwinm r0, r0, 0, 16, 27      /*                                                             */
    mtspr IVOR0, r0         /* IVOR0 400 Critical input                                    */
    e_add16i r3, r0, 0x010  /*                                                             */
    mtspr IVOR1, r3         /* IVOR1 401 Machine check                                     */
    e_add16i r3, r0, 0x020  /*                                                             */
    mtspr IVOR2, r3         /* IVOR2 402 Data storage                                      */
    e_add16i r3, r0, 0x030  /*                                                             */
    mtspr IVOR3, r3         /* IVOR3 403 Instruction storage                               */
    e_add16i r3, r0, 0x040  /*                                                             */
    mtspr IVOR4, r3         /* IVOR4 404 External input                                    */
    e_add16i r3, r0, 0x050  /*                                                             */
    mtspr IVOR5, r3         /* IVOR5 405 Alignment                                         */
    e_add16i r3, r0, 0x060  /*                                                             */
    mtspr IVOR6, r3         /* IVOR7 406 Program                                           */
    e_add16i r3, r0, 0x070  /*                                                             */
    mtspr IVOR7, r3         /* IVOR7 407 Floating-point unavailable                        */
    e_add16i r3, r0, 0x080  /*                                                             */
    mtspr IVOR8, r3         /* IVOR8 408 System call                                       */
    e_add16i r3, r0, 0x090  /*                                                             */
    mtspr IVOR9, r3         /* IVOR9 409 Auxiliary processor unavailable. Not used by the e200z6. */
    e_add16i r3, r0, 0x0A0  /*                                                             */
    mtspr IVOR10, r3        /* IVOR10 410 Decrementer                                      */
    e_add16i r3, r0, 0x0B0  /*                                                             */
    mtspr IVOR11, r3        /* IVOR11 411 Fixed-interval timer interrupt                   */
    e_add16i r3, r0, 0x0C0  /*                                                             */
    mtspr IVOR12, r3        /* IVOR12 412 Watchdog timer interrupt                         */
    e_add16i r3, r0, 0x0D0  /*                                                             */
    mtspr IVOR13, r3        /* IVOR13 413 Data TLB error                                   */
    e_add16i r3, r0, 0x0E0  /*                                                             */
    mtspr IVOR14, r3        /* IVOR14 414 Instruction TLB error                            */
    e_add16i r3, r0, 0x0F0  /*                                                             */
    mtspr IVOR15, r3        /* IVOR15 415 Debug                                            */
    /* IVOR16-IVOR31 - Reserved for future architectural use       */
    e_add16i r3, r0, 0x100  /*                                                             */
    mtspr IVOR32, r3        /* IVOR32 528 SPE APU unavailable                              */
    e_add16i r3, r0, 0x110  /*                                                             */
    mtspr IVOR33, r3        /* IVOR33 529 SPE floating-point data exception                */
    e_add16i r3, r0, 0x120  /*                                                             */
    mtspr IVOR34, r3        /* IVOR34 530 SPE floating-point round exception               */

    #if defined(OSCWPPC)
    se_blr
    #endif
}
#endif /* defined(OSE200Z6) || defined(OSE200Z3) || defined(OSE200Z4) || defined(OSE200Z7) */

/******************************************************************************
 * Function:    OSInitVectors
 *
 * Description: Initializes CPU exceptions
 *
 * Returns:     none
 *
 * Notes: 
 ******************************************************************************/
static OSINLINE void
OSInitVectors (void)
{

    #if defined(OSE200Z6) || defined(OSE200Z3) || defined(OSE200Z4) || defined(OSE200Z7)
    OsSetIVPR ((OSDWORD) &VTABLE & 0xFFFF0000UL); /* Set Interrupt vector prefix */
    OSInitIVORS ();
    #else
    OsSetIVPR ((OSDWORD) &VTABLE); /* Set Interrupt vector prefix, VTABLE address must be aligned
                                      for Z1, Z0 cores to a 4-Kbyte boundary */
    #endif

}
#endif /* !(defined(OSUSERVTABLE) && defined(OSMULTICORE)) */

/******************************************************************************
 * Function:    OSInitializeISR
 * Description: Initializes ISRs
 * Returns:     none
 * Notes: 
 ******************************************************************************/
void
OSInitializeISR (void)
{

    OSDWORD i;

    #if (OSNISR > 0U)

    const OSISRCFGTYPE *handlerCfgPtr;
    OS_ISRTYPEPTR handlerTablePtr;

    for (i = 0U; i < (OSNISR+1U); i++)
    {
        handlerCfgPtr = &(OsIsrCfg[i]);
        handlerTablePtr = &(OsIsrTable[i]);


        #if defined(OSAPPLICATION)
        handlerTablePtr->appId = handlerCfgPtr->appId;
        #endif

        #if defined(OSMEMPROTECTION)
        /*
        * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        handlerTablePtr->stackPtr = handlerCfgPtr->stackPtr - (OSDWORD)OSSTKADDS;
        handlerTablePtr->isrBos = handlerCfgPtr->isrBos;
        #endif /* defined(OSMEMPROTECTION) */

        #if defined(OSTERMINATION)
        handlerTablePtr->isKilled = OSFALSE;
        #endif

        #if defined(OSUSERESLINK)
        handlerTablePtr->resources = OSNULLREFRES;
        #endif

        handlerTablePtr->userISR = handlerCfgPtr->userISR;
        handlerTablePtr->type = handlerCfgPtr->type;
        handlerTablePtr->index = handlerCfgPtr->index;

        handlerTablePtr->isrPrio = handlerCfgPtr->isrPrio;


        #if defined(OSMEMPROTECTION)
        #if (OSNTRUSTEDFUNCTIONS > 0U)
        handlerTablePtr->disabled = 0U;
        #endif
        #endif
    }

    #endif /*OSNISR > 0U */


    #if defined(OSRESOURCEISR)
    OsISRResourceCounter = 0U;  /* clear ISR resource counter      */
    #endif

    #if defined(OSUSEISRLEVEL)
    OsIsrLevel = 0U;            /* no ISR/critical section running */
    #endif

    #if defined(OSISRENTRYEXIT)
    OsSuspendLevel = 0U;        /* level of the nested Suspend/Resume pairs */
    #endif

    #if !(defined(OSUSERVTABLE) && defined(OSMULTICORE))
    OSInitVectors ();           /* initialize vector table */
    #else
    UserInitVectors ();         /* initialize user vector table */
    #endif

    /* Machine check enable (ME=1) */
    OSSETMSR (OSGETMSR () | OSMSR_ME);  /* MPU violation events and another 'bus errors' will be handled as exceptions (not CPU reset) */

    for (i = 0U; i < OSNINTC; i++)
    {

        OSCLEAR_INT_PSRX (i);
        #if (OSNISR > 0U)
        if (OsIsr[i] != (OSSHORT)OSNISR)
        {
            OSSET_INT_PSRX (i, OsIsrCfg[OsIsr[i]].isrPrio);     /* note: OsIsrCfg[i].isrPrio may include 
                                                                   PRC_SEL bits instead of OsIsrTable[i].isrPrio */
        }
        #endif
    }

    OSINTC_MCR &= ~OSINTC_MCR_HVEN;     /* Software vector mode            */
    OSINTC_MCR &= ~OSINTC_MCR_VTES;     /* Vector Table Entry Size = 4     */


    OSINTC_IACKR = 0U;

    OSOrtiSetISRId (OSINVALID_ISR);     /* no running ISR                  */

    OSISRALLON ();              /* Enable all Interrupts (IPL = 0) */
}

#if defined(OSTIMINGPROTECTION)
#if defined(OSHOOKPROTECTION)
/***************************************************************************
 * Function:    OSTPLeaveISR
 *
 * Description: performs dispatch before return from TP ISR if needed
 *
 * Notes:       called only if ISR and/or Task was killed, under OSDHI()
 *
 **************************************************************************/
void
OSTPLeaveISR (void)
{
    #if defined(OSISRENTRYEXIT)
    if (OSISRLEVELMASKED == 0U)
    #endif
    {
        if ((OsKilled & OSRUNTSKKILLED) != 0U)
        {
            /*
            * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            OsRunning = OSGETMAXPRIOTASK;
            OsKilled &= ~OSRUNTSKKILLED;
            OSSETTASKMSR ();    /* set MSR for Task, EE = 1 */
            OSTaskInternalDispatch ();
        }
        /* return to running Task */
    }

    #if defined(OSISRENTRYEXIT)
    #if !defined(OSNOISR2)
    /*
    * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    else if (OsIsrArray[OSISRLEVELMASKED - 1U]->isKilled != OSFALSE)
    {
        OsIsrLevel--;
        /*
         * @violates @ref Os_isr_c_REF_16_10_1 MISRA 2004 Required Rule 16.10, Ignoring return value of function
         * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used         
         */
        OSLongJmp (OsISRbufs[OSISRLEVELMASKED]);        /* back to OSInterruptDispatcher */
    }
    else
    {
        /* to satisfy MISRA Violates MISRA 2004 Required Rule 14.10, no 'else' at end of 'if ... else if' chain */
    }
    #endif
    #endif /* defined(OSISRENTRYEXIT) */

}
#endif /* defined(OSHOOKPROTECTION) */
#endif /* defined(OSTIMINGPROTECTION) */

#if !defined(OSNOISR2)
#if defined(OSMEMPROTECTION)
#if (OSNNONTRUSTEDISR > 0U)
/******************************************************************************
 * Function:    OSCallNonTrustedISR2
 *
 * Description: this is the wrapper to call a user's non trusted ISR of category 2
 *
 * Returns:     
 *
 ******************************************************************************/

static OSINLINE void
OSCallNonTrustedISR2 (OSVOIDFUNCVOID userISR)
{

    OS2UserModeEHI ();      /* to user mode */
    userISR();              /* it's important that userISR is calculated before transfer to user mode,
                               note OS data (OsIsrTable[]) may be not accessed here. */ 
    /*
     * @violates @ref Os_isr_c_REF_16_10_1 MISRA 2004 Required Rule 16.10, Ignoring return value of function
     */
    OS2SystemMode ();       /* to supervisor mode */
    OSDI ();
    OSDHI ();
}

/******************************************************************************
 * Function:    OSNonTrustedISR2
 *
 * Description: call a user's non trusted ISR of category 2
 *
 * Returns:     none
 *
 ******************************************************************************/

static OSINLINE void
OSNonTrustedISR2 (OS_ISRTYPEPTR ptr)
{
        
    OSMP_APP_OPEN_DATA ();
    OsIsrLevel++;
    OSPreIsrHook ();
    OSTPStartISRBudget (ptr);
    
    OSCallNonTrustedISR2 (ptr->userISR);

    OSTPResetISRBudget ();
    OSPostIsrHook ();
}
#endif /* (OSNNONTRUSTEDISR > 0U) */
#endif /* defined(OSMEMPROTECTION) */

/******************************************************************************
 * Function:    OSTrustedISR2
 *
 * Description: this is the wrapper to call a user's trusted ISR of category 2
 *              or ISR of category 2 for SC1 or SC2 configuration
 *
 * Returns:     none
 *
 ******************************************************************************/
#if defined(OSMULTICORE) && (!defined(OSSC1))
    static OSUSE_FRAME void OSTrustedISR2 (OS_ISRTYPEPTR ptr)       /* w/a to avoid placement of some registers on stack in OSInterruptDispatcher1 */
#else
    static OSINLINE OSUSE_FRAME void OSTrustedISR2 (OS_ISRTYPEPTR ptr)
#endif
{
    #if defined(OSUSEISRSTACK) || defined(OSSC1)
    if (OSISRLEVELMASKED == 0U)
    {
        OSSWITCH2STACK_ISR ();
    }
    #endif
    OsIsrLevel++;
    OSPreIsrHook ();
    OSTPStartISRBudget (ptr);

    OSEHI ();
    ptr->userISR ();            /* call User ISR */
    OSDI ();
    OSDHI ();

    /* for AR v3,4.. */
    OSTPResetISRBudget ();

    OSPostIsrHook ();
    #if defined(OSUSEISRSTACK)
    if (OSISRLEVELMASKED == 1U)
    {
        OSSWITCH2STACK_TASK ();
    }
    #endif
    OSWARNSUPPRESS
}
#endif /* !defined(OSNOISR2) */

/******************************************************************************
 * Function :    OSInterruptDispatcher1
 *
 * Description:  This is a Dispatcher for External Interrupts 
 *
 * Note:    
 ******************************************************************************/
OSUSE_FRAME void OSInterruptDispatcher1 (void)
{
    #if (OSNISR > 0U)

    OS_ISRTYPEPTR handlerPtr;       /* pointer to ISR descriptor */

    #if defined(OSUSEISRLEVEL)
    OSDWORD oldPri;             /* saved current ISR priority */
    #endif

    #if defined(OSAPPLICATION)
    #if defined(OSISRENTRYEXIT)
    OSAPPLICATIONTYPE curApp;
    #endif
    #endif

    #if defined(OSUSEISRLEVEL)
    oldPri = OSISRGetPrio ();   /* get the previous IPL (before reading IACKR) */
    #endif

    handlerPtr = &(OsIsrTable[OsIsr[OSINTC_IACKR >> 2]]);

    #if !defined(OSNOISR1)
    if (handlerPtr->type == OSISR1)
    {
        #if defined(OSCHECKCONTEXT)
        oldPri = OsIsrLevel;           /* oldPri is used differently than in ISRs cat.2 */
        OsIsrLevel |= OSISRLEVELISR1;  /* set flag for context check */
        #endif

        OSEHI ();

        handlerPtr->userISR ();     /* call User ISR */

        OSDHI ();

        #if defined(OSCHECKCONTEXT)
        OsIsrLevel = oldPri;    /* restore previous context (ISR1) */
        #endif

        OSEOIR ();              /* restore IPL */
        /*
         * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return;
    }
    #endif /* !defined(OSNOISR1) */

    #if defined(OSUSEISRLEVEL)
    if (oldPri >= OSISRGetPrio ())
    {   /* temporary ignore disabled ISR that is raised because of INTC "feature" with interrupt latching */
        OSEOIR ();              /* restore IPL */
        /*
         * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return;
    }
    #endif

    #if defined(OSTIMINGPROTECTION)
    #if defined(OSTPTIMSTM) || defined(OS2TPTIMSTM)
    #if (OSNTPTSKBGTS > 0U) || (OSNTPISRARRIV > 0U)
    if (handlerPtr->type == OSTPISR1)
    {
        handlerPtr->userISR ();     /* call TP interrupt handler */
        OSEOIR ();              /* restore IPL */
        /*
         * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return;
    }
    #endif
    #endif
    #endif

    #if defined(OSISRENTRYEXIT)

    #if defined(OSAPPLICATION)
    curApp = (OSAPPLICATIONTYPE)OSGetCurApp ();
    #endif

    /*
    * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    OsIsrArray[OSISRLEVELMASKED] = handlerPtr;

    #if defined(OSSYSSTKCHECK)
    if (OSISRLEVELMASKED == 0U)
    {   /* check stack of interrupted Task  */
        OSCheckStack ();
    }
    #endif /* defined(OSSYSSTKCHECK) */
  
    switch (handlerPtr->type)
    {
        case OSSYSINTERRUPT:        
            #if defined(OSMEMPROTECTION)
            OSStackEnableAccess ();
            OSLoadISRSP (handlerPtr->stackPtr);
            #else
            #if defined(OSUSEISRSTACK)
            if (OSISRLEVELMASKED == 0U)
            {   /* common ISR stack is used in SC1, SC2 */
                OSSWITCH2STACK_ISR ();
            }
            #endif
            #endif /* defined(OSMEMPROTECTION) */

            OSOrtiSetISRId (OsIsr[handlerPtr->index]);
            handlerPtr->userISR ();

            #if defined(OSMEMPROTECTION)
            OSRestoreSP ();
            #else
            #if defined(OSUSEISRSTACK)
            #if defined(OSSYSSTKCHECK)
            if (OSCHECKISRSTACK ())
            {   /* stack fault after OS system timer ISR */
                OSPUTERROR (E_OS_STACKFAULT);
                OSShutdownOS (E_OS_STACKFAULT);
            }
            #endif
            if (0U == OSISRLEVELMASKED)
            {
                OSSWITCH2STACK_TASK ();
            }
            #endif
            #endif /* defined(OSMEMPROTECTION) */

            break;

        default:  /* ISR cat.2 */
            #if !defined(OSNOISR2)

            #if defined(OSTERMINATION)
            /*
             * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
             */
            if (0 == OSSetJmp (OsISRbufs[OSISRLEVELMASKED]))        /* for killing ISR */
            #endif
            {
                #if (OSNIOCCALLBACKS > 0U)
                if (handlerPtr->type == OSCALLBACKISR)
                {
                    if (OSIocPrepareCallbackISR (handlerPtr) == OSFALSE)
                    {
                        OSEOIR ();
                        /*
                        * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
                        */
                        return;
                    }

                    OSSetCurApp (handlerPtr->appId);
                }
                else
                #endif /* (OSNIOCCALLBACKS > 0U) */
                {
                    OSSetCurApp (handlerPtr->appId);

                    /* Check inter-arrival rate for ISR2 */
                    #if (OSNTPISRARRIV > 0U) && defined(OSHOOKPROTECTION)
                    if (OSTPISRArrivalRate (handlerPtr) != OSTRUE)
                    {
                        OSSetCurApp (curApp); /* restore application */
                        OSEOIR ();            /* restore IPL */
                        /*
                         * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
                         */
                        return;
                    }
                    #else
                    OSTPISRArrivalRate (handlerPtr);
                    #endif
                }

                #if defined(OSMEMPROTECTION)
                /* Prepare MPU for ISR2 stack */
                OSMP_ISR2_OPEN_STACK (handlerPtr);
                OSLOADSP (handlerPtr->stackPtr);
                #endif

                OSOrtiSetISRId (OsIsr[handlerPtr->index]);

                #if defined(OSMEMPROTECTION)
                #if (OSNNONTRUSTEDISR > 0U)
                if ( OSMP_IS_NONTRUSTEDAPP(handlerPtr->appId) )
                {
                    OSNonTrustedISR2 (handlerPtr);
                }
                else
                #endif /* (OSNNONTRUSTEDISR > 0U) */
                #endif /* defined(OSMEMPROTECTION) */
                {
                    OSTrustedISR2 (handlerPtr);
                }

            #if defined(OSSYSSTKCHECK)
            /*
            * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            if (OSCHECKISRSTACK ())
            {
                #if defined(OSSTKHOOKPROTECTION)
                ProtectionReturnType action;

                OSPUTERROR (E_OS_STACKFAULT);
                /* set violator Id */
                OsViolatorTaskId = INVALID_TASK;
                #if defined(OSAPPLICATION)
                OsViolatorAppId = OS_MKOBJID (OBJECT_APPLICATION, (ApplicationType)OSGetCurApp ());
                #endif
                OsViolatorISRId = OS_MKOBJID (OBJECT_ISR, OsIsr[handlerPtr->index]);

                /* Restore corrupted stack pad  */
                #if defined(OSSC2)
                OSSTKSETGUARD (OSISRSTKEND);
                #else
                /* for SC3/4 */
                /*
                * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
                */
                OSSTKSETGUARD (handlerPtr->isrBos);
                #endif

                OSOrtiSetServiceWatch (OSServiceId_ProtectionHook);     /* set watch to this service */
                OSSETPROTCNXT ();
                OSCLEARSUSPENDLEVELS ();        /* [OS093] */
                action = ProtectionHook (E_OS_STACKFAULT);
                OSCLRPROTCNTX ();
                OSOrtiServiceWatchOnExit (OSServiceId_ProtectionHook);  /* clear service watch on hook leaving */

                switch (action)
                {
                    case PRO_KILLTASKISR:
                        /* note the ISR is finished already */
                        OSStackKillISR (handlerPtr);
                        break;
                    #if defined(OSAPPLICATION)
                    case PRO_KILLAPPL:
                        handlerPtr->isKilled = OSTRUE;      /* the ISR is finished already */
                        if (OSTerminateApplication ((OSAPPLICATIONTYPE)OS_GETOBJIND (OsViolatorAppId), (RestartType)NO_RESTART))
                        {
                            break;
                        }
                        OSShutdownOS (E_OS_STACKFAULT);
                        /* unreachable point */
                    case PRO_KILLAPPL_RESTART:
                        #if defined(OSHAS_RESTARTTASK)
                        if (OsAppTable[OS_GETOBJIND (OsViolatorAppId)].restartTask == OSINVALID_TASK)
                        #endif
                        {
                            /* no restart task was configured for the faulty OS-Application (OS557) */
                            OSShutdownOS (E_OS_STACKFAULT);
                        }

                        handlerPtr->isKilled = OSTRUE;      /* the ISR is finished already */
                        if (OSTerminateApplication ((OSAPPLICATIONTYPE)OS_GETOBJIND (OsViolatorAppId), (RestartType)RESTART))
                        {
                            break;
                        }
                        /* no break - OSShutdownOS() shall be called */
                        #endif /* defined(OSAPPLICATION) */
                    case PRO_SHUTDOWN:
                    default:
                        OSShutdownOS (E_OS_STACKFAULT);
                }
                #else
                OSPUTERROR (E_OS_STACKFAULT);
                OSShutdownOS (E_OS_STACKFAULT);
                #endif /* defined(OSSTKHOOKPROTECTION) */
                }
                #endif /* defined(OSSYSSTKCHECK) */             
                
            OsIsrLevel--;

            if ((OsSuspendLevelAll != 0U) || (OsSuspendLevel != 0U))      /* check Suspend/Resume pairing */
            {
                OSErrorHook_noPar (E_OS_DISABLEDINT);   /* OS368 */
            
                OsSuspendLevelAll = 0U;
                OSTPKillIntLockTime ();
                OsSuspendLevel = 0U;
                OsIsrLevel &= ~OSISRLEVELDISABLEDINTERRUPTS;
            }

            #if defined(OSRESOURCEISR)
            if (handlerPtr->resources != OSNULLREFRES)
            {
                OSErrorHook_noPar (E_OS_RESOURCE);      /* OS369 */
                OSReleaseISRResources (handlerPtr);
            }
            #endif /* defined(OSRESOURCEISR) */

            #if defined(OSMEMPROTECTION)
            /*
            * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            OSLOADSP ((OSDWORD *) OsISRbufs[OSISRLEVELMASKED][0]);      /* restore stack */
            #endif
            }   /* end of "if(OSSetJmp)" */
            #if defined(OSMEMPROTECTION)
            OSStackEnableAccess ();
            #endif

            #if defined(OSTERMINATION)
            handlerPtr->isKilled = OSFALSE;
            #endif
            #endif /* !defined(OSNOISR2) */
            /* end of ISR cat.2 processing */        
            break;
    } /* end of 'switch (handlerPtr->type)' */        


    /* OS returns here under OSDHI() and OSDI() */

    #if !defined(OSNOISR2)    
    #if defined(OSTERMINATION)
    /*
    * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    if ((OSISRLEVELMASKED != 0U) && (OSTRUE == OsIsrArray[OSISRLEVELMASKED - 1U]->isKilled))
    {   /* if preempted ISR was killed */
        OsIsrLevel--;
        /*
         * @violates @ref Os_isr_c_REF_16_10_1 MISRA 2004 Required Rule 16.10, Ignoring return value of function
         * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
         */
        OSLongJmp (OsISRbufs[OSISRLEVELMASKED]);        /* restore context and go back */
    }
    #endif /* defined(OSTERMINATION) */

    #endif /* !defined(OSNOISR2) */

    #if defined(OSORTIRUNNINGISRID)
    if (OSISRLEVEL == 0U)
    {   /* return to task level */
        OSOrtiSetISRId (OSINVALID_ISR);
    }
    else
    {   /* return to preempted ISR */
        OSOrtiSetISRId (OsIsr[OsIsrArray[OSISRLEVELMASKED - 1U]->index]);
    }
    #endif
    
    #if defined(OSAPPLICATION)
    /*
    * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    if ((OsIsrLevel == 0U) && ((OsRunning != OSGETMAXPRIOTASK) || ((OsKilled & OSRUNTSKKILLED) != 0U)))
    #else
    /*
    * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    if ((OsIsrLevel == 0U) && (OsRunning != OSGETMAXPRIOTASK))
    #endif
    {
        #if defined(OSAPPLICATION)
        #if defined(OSTIMINGPROTECTION)
        if ((OsKilled & OSRUNTSKKILLED) != 0U)
        {   /* if a task was killed via TerminateApplication() in SC2/4  - unconditional dispatch */
            OSEHI ();
            /*
            * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            OsRunning = OSGETMAXPRIOTASK;
            OsKilled &= ~OSRUNTSKKILLED;
            OSSETTASKMSR ();    /* set MSR for Task, EE = 1 */
            OSTaskInternalDispatch ();
            /* no return here */
        }
        #endif
        #endif
        OSLeaveISR ();
    }
    #if !defined(OSSC1)
    else
    {
        if (OSISRLEVELMASKED == 0U)
        {   /* we are returning from ISR cat.2 to the same Task */
            #if defined(OSTIMINGPROTECTION)
            if (handlerPtr->isrPrio != OSHIGHINTPRIO)
            {   /* not executed after TP Timer ISR */
                OSTPResumeTaskBudget ();
            }
            #endif
            
            #if defined(OSMEMPROTECTION)
            /* Prepare MPU for TASK stack */
            OSMP_TASK_OPEN_STACK ();
            #endif
        }
        #if !defined(OSNOISR2)
        else
        {
            #if defined(OSTIMINGPROTECTION)
            register OSBYTE tmpPrio;

            tmpPrio = handlerPtr->isrPrio;  /* priority of current ISR  */
            #endif
            /*
            * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            handlerPtr = OsIsrArray[OSISRLEVELMASKED - 1U];
            if (handlerPtr->type <= OSTRUSTEDISR2)  /* if it is ISR category 2  */
            {
                #if defined(OSTIMINGPROTECTION)
                if (tmpPrio != OSHIGHINTPRIO)
                {   /* not executed after TP Timer ISR */
                    OSTPResumeISRBudget (handlerPtr);
                }
                #endif

                #if defined(OSMEMPROTECTION)
                /* Prepare MPU for ISR2 stack */
                OSMP_ISR2_OPEN_STACK (handlerPtr);
                #endif
            }
        }
        #endif /* !defined(OSNOISR2) */
    }
    #endif /* !defined(OSSC1) */

    OSMSYNC ();
    OSISRSetPrio (oldPri);      /* instead of OSEOIR()  */

    OSSetCurApp (curApp);       /* restore application */

    #if defined(OSMEMPROTECTION)
    /* Prepare MPU for data of current OS-application if the OS-application is nontrusted */
    OSMP_NONTRUSTEDAPP_OPEN_DATA ();
    #endif

    #else
    OSISRException ();          /* shall not be reached */
    #endif /* defined(OSISRENTRYEXIT) */

    #else
    OSISRException ();
    #endif /* OSNISR > 0 */

    OSWARNSUPPRESS              /* For extra CW warning suppress (OS manipulates SP) */
}

#if defined(OSISRENTRYEXIT)

#if defined(OSSC1)
#if !defined(OSNOFASTTERMINATE)
/***************************************************************************
 * Function:    OSLeaveISR
 *
 * Description: Leave ISR and switch tasks' context, if needed
 *
 * Returns:     none
 *
 * Notes: 
 *
 **************************************************************************/
static void
OSLeaveISR (void)
{

    #if defined(OSRESOURCE)
    OSTSKCBPTR osOldRunning;        /* currently running task    */
    #else
    OSTASKTYPE osOldRunning;        /* currently running task    */
    #endif

    OSTASKTYPE osChainTask;     /* task to be chain    (if any)    */

    /* Check condition of dispatching, if dispatching is not needed then return, else dispatch  */
    #if defined(OSMIXPREEMPT)
    if (OSHASRUNNINGTASK)       /* if interrupted task is not idle loop */
    {
        if (!OSDISPALLOWED)
        {
            /*
             * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return;             /* if non-preemptive task was interrupted, then no launch    */
        }
    }
    #elif defined(OSNOPREEMPT)

    if (OSHASRUNNINGTASK)
    {
        /*
         * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return;                 /* for non-preemptive system no Task switch    */
    }                           /* if interrupt occurred while any task was running    */
    #elif defined(OSFULLPREEMPT)
    /* nothing here */
    #endif
    /* defined(OSMIXPREEMPT) */

    OSEHI ();
    osOldRunning = OsRunning;   /* save running task (if any)    */

    #if defined(OSHOOKPOSTTASK)
    if (OSHASRUNNINGTASK)
    {
        OSPostTaskHook ();      /* user hook or empty macro */
    }
    #endif /* defined(OSHOOKPOSTTASK) */

    while ((OsRunning = OSGETMAXPRIOTASK) != osOldRunning)      /* cycle to launch all preempting tasks    */
    {
        OSOrtiSetRunningId ();
        OSSETRUNPRIO ();        /* set internal resource priority, if any       */
        OSOrtiResetIdOnExit (); /* set that the caller service is finished */
        OSCallPreTaskHook ();
        OSSETTASKMSR ();        /* set MSR for Task, EE = 1 */
        OSEI ();
        osChainTask = OSCallTask ();    /* execute the task, and get the ID of chained task */
        OSDI ();
        OSCheckStack ();        /* check main stack overflow */
        OSResetInternalPrio2 ();

        #if defined(OSRESOURCE) || defined(OSINRES)
        OSRUNNINGSTATUS &= (~OSTCBNOSUSPENDED); /* clear "nonsuspended" flag */
        #endif

        OSREMOVETASK (OsRunning);

        if (osChainTask != OSINVALID_TASK)      /* if some task needs to be chained    */
        {
            OSTask2Ready (osChainTask); /* then readies chained task    */
        }

        OSPostTaskHook ();      /* user hook or empty macro */
    }
    OSOrtiSetRunningId ();
    OSSETBITRUNPRIO ();         /* Restore runprio bit */

    OSOrtiResetIdOnExit ();     /* set that the caller service is finished */
    OSPreTaskHook ();           /* call user hook */
    OSDHI ();
    return;
}

#else
/* below when OSNOFASTTERMINATE is defined */

/***************************************************************************
 * Function:    OSLeaveISR
 *
 * Description: Leave ISR and switch tasks' context, if needed
 *
 * Returns:     none
 *
 * Notes:       for SC1 (BCC1 w/o FastTerminate or ECC1)
 *
 **************************************************************************/
static void
OSLeaveISR (void)
{

    OSTSKCBPTR osOldRunning;        /* currently running task    */
    OSJMP_BUF context;

    #if defined(OSTERMINATION)
    if ((OsKilled & OSRUNTSKKILLED) == 0U)
    #endif
    {
        #if defined(OSMIXPREEMPT)
        if (!OSDISPALLOWED)
        {
            /*
             * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return;                 /* if non-preemptive task was interrupted, */
            /* or running task take scheduler then no launch */
        }
        #elif defined(OSFULLPREEMPT)
        /* Nothing to do */
        #else
        /* OSNOPREEMPT */
        if (OSHASRUNNINGTASK)
        {
            /*
             * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return;                 /* for non-preemptive system nothing launch,    */
        }                           /* if interrupt occurred while any task was running */
        #endif /* defined(OSMIXPREEMPT) */

        OSSETTASKMSR ();            /* set MSR for Task, EE = 1 */
        osOldRunning = OsRunning;   /* save running task (if any)    */

        #if defined(OSHOOKPOSTTASK)
        if (OSTSKIND (osOldRunning) != OSNULLTASK)
        {
            OSSetCurApp (OsRunning->appId);
            OSPostTaskHook ();  /* call user hook               */
        }
        #endif /* defined(OSHOOKPOSTTASK) */

        OsRunning = OSGETMAXPRIOTASK;
        osOldRunning->pcontext = context;

        if (OSSetJmp (context))     /* save context of preempted task    */
        {
            /* return point from dispatched tasks */
            OSSETBITRUNPRIO ();     /* Restore runprio bit */
            OSOrtiResetIdOnExit (); /* set that the caller service is finished */
            OSPreTaskHook ();
            OSDHI ();
            /*
             * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return;
        }

        #if (OSNXTSKS > 0U)
        if ((osOldRunning->status & OSTSKEXTENDED) == 0U)
        #endif
        {
            OSSAVECONTEXTADDR (osOldRunning);
        }
    }
    #if defined(OSTERMINATION)
    else
    {
        /* Running TASK was killed */
        OSSETTASKMSR ();        /* set MSR for Task, EE = 1 */
        OsKilled &= ~OSRUNTSKKILLED;
        OsRunning = OSGETMAXPRIOTASK;
    }
    #endif

    OSTaskInternalDispatch ();

    /* never return at this point */
    /*
     * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    return;
    /*
    * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
    */
    OSWARNSUPPRESS              /* For extra CW warning suppress */
}
#endif /* !defined(OSNOFASTTERMINATE) */

#else /* defined(OSSC1) */

/***************************************************************************
 * Function :   OSLeaveISR
 *
 * Description: Leave ISR and switch tasks' context, if needed
 *
 * Returns:     none
 *
 * Notes:       for SC2,3,4 all Tasks and ISRs has own stacks
 *
 **************************************************************************/
static void
OSLeaveISR (void)
{

    OSTSKCBPTR osOldRunning;        /* currently running task   */
    OSJMP_BUF context;

    #if defined(OSTERMINATION)
    if ((OsKilled & OSRUNTSKKILLED) == 0U)
    #endif
    {
        #if !defined(OSFULLPREEMPT)
        if (OSHASRUNNINGTASK)
        {
            #if !defined(OSNOPREEMPT)
            if (!OSDISPALLOWED)     /* no check for Non-preemptive system  */
            #endif
                                    /* Scheduling policy    */
            {
                OSTPResumeTaskBudget ();
                #if defined(OSMEMPROTECTION)
                OSMP_TASK_OPEN_STACK ();    /* Prepare MPU for TASK stack */
                #endif
                /*
                 * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
                 */
                return;             /* there are some non-preemptive conditions for running task */
            }
        }
        #endif /* !defined(OSFULLPREEMPT) */

        OSSETTASKMSR ();            /* set MSR for Task, EE = 1 */
        osOldRunning = OsRunning;   /* save running task (if any)    */

        #if defined(OSHOOKPOSTTASK)
        if (OSTSKIND (osOldRunning) != OSNULLTASK)
        {
            OSSetCurApp (OsRunning->appId);
            OSTPPostTaskHook ();        /* call user hook */
        }
        #endif /* defined(OSHOOKPOSTTASK) */

        /*
        * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        OsRunning = OSGETMAXPRIOTASK;
        osOldRunning->pcontext = context;

        if (OSSetJmp (context))     /* save context of preempted task    */
        {                           /* returns here from dispatched tasks */
            #if defined(OSMEMPROTECTION)
            OSEHI ();
            #endif
            /*
            * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            OSSETBITRUNPRIO ();     /* Restore runprio bit */
            OSOrtiResetIdOnExit (); /* set that the caller service is finished */
            OSPreTaskHook ();
            OSDHI ();
            /*
             * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            return;
        }

        #if (OSNXTSKS > 0U)
        if ((osOldRunning->status & OSTSKEXTENDED) == 0U)
        #endif
        {
            OSSAVECONTEXTADDR (osOldRunning);
        }
    }
    #if defined(OSTERMINATION)
    else
    {
        /* Running TASK was killed */
        OSSETTASKMSR ();        /* set MSR for Task, EE = 1 */
        OsKilled &= ~OSRUNTSKKILLED;
        /*
        * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        OsRunning = OSGETMAXPRIOTASK;
    }
    #endif

    OSTaskInternalDispatch ();
    /* unreachable point */
}

#endif /* defined(OSSC1) */
#endif /* defined(OSISRENTRYEXIT) */

#if (OSNISR > 0U)
/******************************************************************************
 * Function:    DisableInterruptSource
 *
 * Description: disables interrupt source in INTC
 *
 * Return: E_OK                       no errors
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) ISR identifier is invalid
 *         E_OS_ACCESS                access to the object denied
 ******************************************************************************/
StatusType
OS_DisableInterruptSource (ISRType handlerId)
{

    OS_ISRTYPEPTR Isr;
    OSIMSAVE                    /* OSINTMASKTYPE save; */
    #if defined(OSCALCULATEOBJIND)
    OSWORD handlerInd;
    #endif

    OSOrtiSetServiceWatch (OSServiceId_DisableInterruptSource);

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_DisableInterruptSource, handlerId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_DisableInterruptSource, handlerId);
        }
    }
    #endif /* OSCHECKCONTEXT */

    #if defined(OSEXTSTATUS)
    if (OSISRIDISINVALID (handlerId))
    {
        /*
         * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_DisableInterruptSource, handlerId);        /* invalid ID */
    }
    #endif

    #if defined(OSCALCULATEOBJIND)
    handlerInd = OS_GETOBJIND (handlerId);
    #endif

    Isr = &OsIsrTable[handlerInd];

    #if defined(OSEXTSTATUS)
    if (Isr->type > OSISR1)     /* if it is not a User defined ISR */
    {
        /*
         * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_DisableInterruptSource, handlerId);        /* invalid ID */
    }
    #endif /* defined(OSEXTSTATUS) */



    OSDIS (save);

    #if defined(OSAPPLICATION)
    if (Isr->appId != OSGetCurApp ())
    {
        OSRI (save);
        /*
         * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ACCESS, OSServiceId_DisableInterruptSource, handlerId);
    }
    #endif

    #if defined(OSMEMPROTECTION)
    #if (OSNTRUSTEDFUNCTIONS > 0U)
    if (0U == OsAppTable[Isr->appId].tfContext)
    {
        Isr->disabled = OSTRUE;
    }
    #if defined(OSEXTSTATUS)
    else
    {
        OSRI (save);
        /*
         * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_CALLEVEL, OSServiceId_DisableInterruptSource, handlerId);
    }
    #endif
    #endif
    #endif

    OSDisableISRSource (Isr);   /* disable ISR's source immediately */


    OSRI (save);

    OSOrtiServiceWatchOnExit (OSServiceId_DisableInterruptSource);

    return E_OK;
}

/******************************************************************************
 * Function:    EnableInterruptSource
 *
 * Description: enables interrupt source in INTC
 *
 * Return: E_OK                       no errors
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_ID       (ext.status) ISR identifier is invalid
 *         E_OS_ACCESS                access to the object denied
 *         E_OS_NOFUNC                Arrival rate of ISR is reached
  ******************************************************************************/
StatusType
OS_EnableInterruptSource (ISRType handlerId)
{

    OS_ISRTYPEPTR Isr;
    OSIMSAVE                    /* OSINTMASKTYPE save; */
    #if defined(OSCALCULATEOBJIND)
    OSWORD handlerInd;
    #endif

    OSOrtiSetServiceWatch (OSServiceId_EnableInterruptSource);

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASKMASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_EnableInterruptSource, handlerId);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_EnableInterruptSource, handlerId);
        }
    }
    #endif /* OSCHECKCONTEXT */

    #if defined(OSEXTSTATUS)
    if (OSISRIDISINVALID (handlerId))
    {
        /*
         * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_EnableInterruptSource, handlerId); /* invalid ID */
    }
    #endif

    #if defined(OSCALCULATEOBJIND)
    handlerInd = OS_GETOBJIND (handlerId);
    #endif

    Isr = &OsIsrTable[handlerInd];

    #if defined(OSEXTSTATUS)
    if (Isr->type == OSSYSINTERRUPT)
    {
        /*
         * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ID, OSServiceId_EnableInterruptSource, handlerId); /* invalid ID */
    }
    #endif /* defined(OSEXTSTATUS) */




    OSDIS (save);

    #if defined(OSAPPLICATION)
    if (Isr->appId != OSGetCurApp ())
    {
        OSRI (save);
        /*
         * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_ACCESS, OSServiceId_EnableInterruptSource, handlerId);
    }
    #endif

    #if defined(OSMEMPROTECTION)
    #if (OSNTRUSTEDFUNCTIONS > 0U)
    if (0U == OsAppTable[Isr->appId].tfContext)
    {
        Isr->disabled = OSFALSE;
    }
    #if defined(OSEXTSTATUS)
    else
    {
        OSRI (save);
        /*
         * @violates @ref Os_isr_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        OSRETERROR (E_OS_CALLEVEL, OSServiceId_DisableInterruptSource, handlerId);
    }
    #endif
    #endif /* (OSNTRUSTEDFUNCTIONS > 0U) */
    #endif /* defined(OSMEMPROTECTION) */


    OSEnableISRSource (Isr);    /* enable ISR's source immediately */

    OSRI (save);
    OSOrtiServiceWatchOnExit (OSServiceId_EnableInterruptSource);
    return E_OK;
}

#if defined(OSAPPLICATION)
#if defined(OSKILLAPPISRS)
/***************************************************************************
 * Function:    OSKillAppISRs
 *
 * Description: kills all the ISRs belonging to given application
 *
 * Returns:     none
 *
 * Notes:    
 ***************************************************************************/
void
OSKillAppISRs (OSAPPLICATIONTYPE appId)
{
    OSWORD i;

    for (i = 0U; i < OSNISR; i++)
    {
        if (appId == OsIsrCfg[i].appId)
        {

            OSDisableISRSource (&OsIsrTable[i]);    /* disable ISR's source */

        }
    }

    #if (!defined(OSNOISR2)) || (OSNIOCCALLBACKS > 0U)
    for (i = 0U; i < OSISRLEVELMASKED; i++)
    {
        OS_ISRTYPEPTR handlerPtr;

        /*
        * @violates @ref Os_isr_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        handlerPtr = OsIsrArray[i];

        if (appId == handlerPtr->appId)
        {
            #if defined(OSSTKHOOKPROTECTION)
            if (handlerPtr->isKilled == OSTRUE)
            {
                OSStackKillISR (handlerPtr);
                handlerPtr->isKilled = OSFALSE;
            }
            else
            #endif
            {
                OSKillISR (handlerPtr);
            }
        }
    }
    #endif

    #if (OSNIOCCALLBACKS > 0U)
    /* Remove IOC callback(s) (that belong(s) to specified OS-Application) from callback queue if any */
    OSIocRemoveAppCallBack (appId);
    #endif
}
#endif /* defined(OSKILLAPPISRS) */
#endif /* defined(OSAPPLICATION) */

#if defined(OSMEMPROTECTION)
#if (OSNTRUSTEDFUNCTIONS > 0U)
#if (OSNUSERISR > 0U)
/*****************************************************************************
 * Function:    OSDisableISRs4App
 *
 * Description: disable all the ISRs category 2 belonging to given application
 *
 * Returns:     none
 *
 * Notes:    
 *****************************************************************************/
void
OSDisableISRs4App (OSAPPLICATIONTYPE appId)
{
    OS_ISRTYPEPTR handlerPtr;
    OSDWORD i;

    for (i = 0U; i < OSNISR; i++)
    {
        handlerPtr = &(OsIsrTable[i]);
        if ((appId == handlerPtr->appId)
            #if !defined(OSNOISR1)
            && (OSTRUSTEDISR2 >= handlerPtr->type)
            #endif
            )
        {
            OSDisableISRSource (handlerPtr);
        }
    }
}

/*****************************************************************************
 * Function:    OSEnableISRs4App
 *
 * Description: enable all the ISRs category 2 belonging to given application
 *
 * Returns:     none
 *
 * Notes:    
 *****************************************************************************/
void
OSEnableISRs4App (OSAPPLICATIONTYPE appId)
{
    OS_ISRTYPEPTR handlerPtr;
    OSDWORD i;
   
    for (i = 0U; i < OSNISR; i++)
    {
        handlerPtr = &(OsIsrTable[i]);
        if ((appId == handlerPtr->appId)
            #if !defined(OSNOISR1)
            && (OSTRUSTEDISR2 >= handlerPtr->type)
            #endif
            #if (OSNTRUSTEDFUNCTIONS > 0U)
            && (handlerPtr->disabled == OSFALSE) /* is ISR disabled outside of trusted function? */
            #endif
            )
        {
            OSEnableISRSource (handlerPtr);
        }
    }
}
#endif /* (OSNUSERISR > 0U) */
#endif /* (OSNTRUSTEDFUNCTIONS > 0U) */
#endif /* defined(OSMEMPROTECTION) */

#endif /* OSNISR > 0U */

#define OSTEXT_STOP_SEC_CODE
/*
* @violates @ref Os_isr_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif


/** @} */
