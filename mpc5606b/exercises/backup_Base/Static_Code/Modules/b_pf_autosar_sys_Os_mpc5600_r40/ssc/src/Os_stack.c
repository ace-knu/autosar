/**
*   @file    Os_stack.c
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
* @section Os_stack_c_REF_5_1_1
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters. 
* The section identification define's naming convention is defined by AutoSar and identifiers are longer than 31 character. 
* Compilers are checked for support this length of identifiers.
*
* @section Os_stack_c_REF_14_7_1
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function 
* A function shall have a sigle point of exit at the end of finction.
* The returned statement is result of error hanling.
*
* @section Os_stack_c_REF_17_4_1
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* Array indexing shall be the only allowed form of pointer arithmetic
* The pointers are used to increase of OS performance.
*
* @section Os_stack_c_REF_19_1_1
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

#include <Os_isr_api.h>         /* for INVALID_ISR */

#include <Os_stack_api.h>
#include <Os_stack_internal_api.h>
#include <Os_stack_config.h>

/* Stacks */

#if defined(OSUSEISRSTACK)

/*
* @violates @ref Os_stack_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OSSTACK_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"
OSDWORD OsISRStack[OSISRSTACKSIZE];
/*
* @violates @ref Os_stack_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OSSTACK_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_stack_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#endif /* defined(OSUSEISRSTACK) */

/*
* @violates @ref Os_stack_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OSSTACK_START_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_stack_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if (OSNXTSKS > 0U) || defined(OSMEMPROTECTION)
#if defined(OSSTKSIZE)
OSDWORD OsStacks[(OSSTKSIZE + OSSTKBASICSIZE) / 4U];
#else
#if (OSSTKBASICSIZE > 0U)
OSDWORD OsStacks[OSSTKBASICSIZE / 4U];
#endif
#endif
#endif /* (OSNXTSKS > 0U) || defined(OSMEMPROTECTION) */

/*
* @violates @ref Os_stack_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OSSTACK_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_stack_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"



#if !defined(OSCALCULATEOBJIND)
#define taskInd (taskId)
#endif

#define OSTEXT_START_SEC_CODE
/*
* @violates @ref Os_stack_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

/*****************************************************************************
 * inline function  : OSFillStacks
 *
 * Description:
 *
 * Returns:
 *
 * Notes: none
 *****************************************************************************/
#if defined(OSSTKCHECK) || (OSORTIDEBUGLEVEL > 0U)
void
OSFillStacks (void)
{

    #if (OSNXTSKS > 0U) || (defined(OSMEMPROTECTION) && ((OSNUSERISR > 0U) || (OSNIOCCALLBACKS > 0U))) || \
        defined(OSUSEISRSTACK)
    OSDWORD *pstk;
    #endif

    /*
    * @violates @ref Os_stack_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    OSSTKSETGUARD (OSSTACKBOTTOM);      /* common stack initialization */

    #if (OSNXTSKS > 0U) || (defined(OSMEMPROTECTION) && ((OSNUSERISR > 0U) || (OSNIOCCALLBACKS > 0U)))


        #if defined(OSSTKSIZE) || (OSSTKBASICSIZE > 0U)
        /* stack initialization for extended tasks and for ISRs in the SC3..4 */
        /*
        * @violates @ref Os_stack_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        for (pstk = OSRUNNABLESTKBEG; pstk < &OsStacks[sizeof (OsStacks) / sizeof (OsStacks[0])]; pstk++)
        {
            *pstk = OSORTISTACKPATTERN;
        }
        #endif

    #endif /* (OSNXTSKS > 0U) || (defined(OSMEMPROTECTION) && ((OSNUSERISR > 0U) || (OSNIOCCALLBACKS > 0U)))  */

    #if defined(OSUSEISRSTACK)      /* SC1,ECC1 with ISRs category 2 or SC2 */
    for (pstk = OSISRSTKEND; pstk < OSISRTOS; pstk++)
    {
        *pstk = OSORTISTACKPATTERN;
    }
    #endif /* defined(OSUSEISRSTACK) */
}
#endif /* defined(OSSTKCHECK) || (OSORTIDEBUGLEVEL > 0U) */

#if defined(OSSTKCHECK) || (OSORTIDEBUGLEVEL > 0U)
/***************************************************************************
 * Function:   OSGetUsedBytes
 *
 * Description: Calculates number of used bytes
 *
 * input:   start stack pointer, size in long words
 *
 * Returns: number of bytes
 *
 **************************************************************************/
OSWORD
OSGetUsedBytes (const OSDWORD * start, OSWORD num)
{
    for (; num > 0U; num-- )
    {
        if (*start != OSORTISTACKPATTERN)
        {
            break;
        }
        /*
        * @violates @ref Os_stack_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        start++;
    }

    return (OSWORD) (num * 4U);
}

/***************************************************************************
 * Function:    GetRunningStackUsage
 *
 * Description: Calculates task stack usage
 *
 * Returns:     stack usage in bytes;
 *              OSSTKNOASSIGNED if Task has no own stack
 *
 **************************************************************************/
OSWORD
OS_GetRunningStackUsage (void)
{
    #if (OSNXTSKS == 0U)
    /*
     * @violates @ref Os_stack_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    return (OSSTKNOASSIGNED);   /* single stack */

    #else /* (OSNXTSKS == 0U) */

    if (OSTSKIND (OsRunning) == OSNULLTASK) /* No running task */
    {
        /*
         * @violates @ref Os_stack_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return (OSSTKNOASSIGNED);
    }

    if ((OSRUNNINGSTATUS & OSTSKEXTENDED) == 0U) /* Basic task has single stack */
    {
        /*
         * @violates @ref Os_stack_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return (OSSTKNOASSIGNED);
    }

    #if defined(OSMEMPROTECTION)
    /* it is required only to avoid memory exceptions */
    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASK | OSISRLEVELHOOKERROR | OSISRLEVELHOOKAPPERROR | OSISRLEVELHOOKTASK))
    {
        /*
         * @violates @ref Os_stack_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return (OSSTKNOASSIGNED);
    }
    #endif
    #endif

    /*
    * @violates @ref Os_stack_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    return (OSGetUsedBytes (OsRunning->bos, (OSWORD) (OsRunning->tos - OsRunning->bos)));

    #endif /* (OSNXTSKS == 0U) */
}

#if !defined(OSMEMPROTECTION)
/***************************************************************************
 * Function:    GetStackUsage
 *
 * Description: Calculates task stack usage
 *
 * inp:  task ID
 *
 * Returns:     stack usage in bytes;
 *              OSSTKNOASSIGNED if Task has no own stack
 *
 **************************************************************************/
OSWORD
GetStackUsage (TaskType taskId)
{
    #if defined(OSEXTSTATUS)
    if (OSTASKIDISINVALID (taskId))
    #else
    if (OS_GETOBJIND (taskId) >= OSNTSKS)
    #endif
    {   /* invalid taskId */
        /*
         * @violates @ref Os_stack_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return (OSSTKNOASSIGNED);
    }

    #if (OSNXTSKS == 0U)
    /*
     * @violates @ref Os_stack_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
     */
    return (OSSTKNOASSIGNED);   /* single stack */
    #else /* (OSNXTSKS == 0U) */
    if ((OSTASKSTATUS (OS_GETOBJIND (taskId)) & OSTSKEXTENDED) == 0U)    /* Basic task has single stack */
    {
        /*
         * @violates @ref Os_stack_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return (OSSTKNOASSIGNED);
    }

    return (OSGetUsedBytes
            (OsTaskTable[OS_GETOBJIND (taskId)].bos,
             (OSWORD) (OsTaskTable[OS_GETOBJIND (taskId)].tos - OsTaskTable[OS_GETOBJIND (taskId)].bos))
            );
    #endif /* (OSNXTSKS == 0U) */
}
#endif /* !defined(OSMEMPROTECTION) */
#endif /* defined(OSSTKCHECK) || (OSORTIDEBUGLEVEL > 0U) */

#if defined(OSSYSSTKCHECK)
/***************************************************************************
 * Function:    OSCheckStack
 *
 * Description: Check task stack overflow for preempted Task
 *
 * Returns:     none
 *
 **************************************************************************/
void
OSCheckStack (void)
{

    #if defined(OSUSETOS)
    if (OSTSKIND (OsRunning) == OSNULLTASK)
    {
        /*
         * @violates @ref Os_stack_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function 
         */
        return;
    }

    /*
    * @violates @ref Os_stack_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    if (OSSTKINVALID (OsRunning->bos))
    #else
    /*
    * @violates @ref Os_stack_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    if (OSSTKINVALID (OSSTACKBOTTOM))
    #endif
    {
    #if defined(OSSTKHOOKPROTECTION)
        ProtectionReturnType action;

        #if defined(OSAPPLICATION)
        RestartType restart = NO_RESTART;
        #endif

        OSPUTERROR (E_OS_STACKFAULT);

        /* set violator Id */
        OsViolatorTaskId = OS_MKOBJID (OBJECT_TASK, OsRunning->taskId);

        #if defined(OSAPPLICATION)
        OsViolatorAppId = OS_MKOBJID (OBJECT_APPLICATION, OsTaskCfgTable[OsRunning->taskId].appId);
        #endif

        OsViolatorISRId = INVALID_ISR;

        OSOrtiSetServiceWatch (OSServiceId_ProtectionHook);     /* set watch to this service */
        OSSETPROTCNXT ();
        OSCLEARSUSPENDLEVELS ();        /* [OS093] */
        action = ProtectionHook (E_OS_STACKFAULT);
        OSCLRPROTCNTX ();
        OSOrtiServiceWatchOnExit (OSServiceId_ProtectionHook);  /* clear service watch on hook leaving */

        switch (action)         /* call user's hook */
        {
            case PRO_KILLTASKISR:
                OSKillTask (OsRunning);
                break;

            #if defined(OSAPPLICATION)

            case PRO_KILLAPPL_RESTART:
                #if defined(OSHAS_RESTARTTASK)
                if (OsAppTable[OsRunning->appId].restartTask == OSINVALID_TASK)
                #endif
                {
                    /* no restart task was configured for the faulty OS-Application (OS557) */
                    OSShutdownOS (E_OS_STACKFAULT);
                }
                restart = RESTART;      /* no break */

            case PRO_KILLAPPL:
                if (OSTerminateApplication ((OSAPPLICATIONTYPE)OS_GETOBJIND (OsViolatorAppId), restart))
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
}
#endif /* defined(OSSYSSTKCHECK) */

#define OSTEXT_STOP_SEC_CODE
/*
* @violates @ref Os_stack_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"



#ifdef __cplusplus
}
#endif


/** @} */
