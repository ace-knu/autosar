/**
*   @file    Os_isr_internal_types.h
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

#ifndef OS_ISR_INTERNAL_TYPES_H_
#define OS_ISR_INTERNAL_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>

#include <Os_types_basic.h>     /* for OSDWORD ...   */
#include <Os_types_common_internal.h>   /* for OSAPPLICATIONTYPE */

#include <Os_resource_internal_types.h> /* for OSResType */

#include <Os_tp_internal_types.h>       /* for OSTPRESLOCK */

/* ISR control structure */
struct tagISRTYPE
{

    #if defined(OSMEMPROTECTION)
    OSDWORD *stackPtr;          /* top of ISR stack     */
    OSDWORD *isrBos;            /* bottom of ISR stack  */
    #endif

    #if defined(OSTERMINATION)
    OSBYTE isKilled;            /* set when the ISR is killed via ProtectionHook or via TerminateApplication() */
    #endif

    #if defined(OSUSERESLINK)
    OSRefResType resources;     /* pointer to the resources */
    #endif

    OSVOIDFUNCVOID userISR;     /* actual ISR function */
    OSISRTYPE type;             /* type of the ISR */
    OSWORD index;               /* Index of interrupt in the external interrupts table */
    OSBYTE isrPrio;             /* Interrupt priority */

    #if defined(OSTIMINGPROTECTION)
    #if  (OSNTPISRBGTS > 0U)
    OSTPTICKTYPE tpExecBudget;  /* the execution budget */
    OSTPTICKTYPE tpRemained;    /* remained time on the budget */
    #endif

    #if  (OSNTPISRARRIV > 0U)
    OSTPTICKTYPE tpTimeFrame;   /* time frame */
    OSSIGNEDQWORD tpLast;       /* 63-bit time of last successful transition to 'ready' state */
    #endif

    #if (OSNTPISRINTLOCKTIME > 0U)
    OSTPTICKTYPE tpIntLockTime; /* interrupt locking time */
    #endif

    #if (OSNTPISRRESLOCKTIME > 0U)
    OSTPRESLOCK *tpResLock;     /* pointer to array with resource locking time configurations  */
    OSResType tpResources;      /* the head of the list of occupied resources with started TP */
    OSWORD tpNumberResLock;     /* number of resource with locking time */
    #endif

    #endif                          /* defined(OSTIMINGPROTECTION) */


    #if defined(OSAPPLICATION)
    OSAPPLICATIONTYPE appId;    /* application identification value */
    #endif

    #if defined(OSMEMPROTECTION)
    #if (OSNTRUSTEDFUNCTIONS > 0U)
    OSBYTE disabled;            /* indicates that Isr source is disabled outside of trusted function */
    #endif
    #endif
};


#ifdef __cplusplus
}
#endif

#endif /*OS_ISR_INTERNAL_TYPES_H_ */

/** @} */
