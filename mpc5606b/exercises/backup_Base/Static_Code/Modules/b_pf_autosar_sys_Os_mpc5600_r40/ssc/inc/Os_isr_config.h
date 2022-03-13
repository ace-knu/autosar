/**
*   @file    Os_isr_config.h
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

#ifndef OS_ISR_CONFIG_H_
#define OS_ISR_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>

#include <Os_types_basic.h>     /* for OSSHORT ... */
#include <Os_types_common_internal.h>

#include <Os_platform_config.h>

#include <Os_tp_internal_types.h>       /* for OSTPRESLOCK */

#if (OSNISR > 0U)

struct tagISRCFGTYPE
{
    #if defined(OSMEMPROTECTION)
    OSDWORD *stackPtr;          /* top of ISR stack     */
    OSDWORD *isrBos;            /* bottom of ISR stack (note that OSUSEBOS is defined always for SC3/4) */
    #endif

    OSVOIDFUNCVOID userISR;     /* actual ISR function */
    OSISRTYPE type;             /* type of the ISR */
    OSWORD index;               /* Index of interrupt in the external interrupts table */
    OSBYTE isrPrio;             /* Interrupt priority */

    #if defined(OSTIMINGPROTECTION)


    #if  (OSNTPISRBGTS > 0U)
    OSTPTICKTYPE tpExecBudget;  /* execution time for ISR */
    #endif

    #if (OSNTPISRARRIV > 0U)
    OSTPTICKTYPE tpTimeFrame;   /* Time frame for inter-arrival rate protection */
    #endif

    #if (OSNTPISRINTLOCKTIME > 0U)
    OSTPTICKTYPE tpIntLockTime; /* interrupt locking time */
    #endif

    #if (OSNTPISRRESLOCKTIME > 0U)
    const OSTPRESLOCK *tpResLock; /* TP resource locking time configurations */
    OSWORD tpNumberResLock;     /* number of resource lock configurations for this ISR2 */
    #endif
    #endif /* defined(OSTIMINGPROTECTION) */

    #if defined(OSAPPLICATION)
    OSAPPLICATIONTYPE appId;    /* application identification value */
    #endif
};

typedef struct tagISRCFGTYPE OSISRCFGTYPE;

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

        /* Interrupts configuration table */
extern const OSISRCFGTYPE OsIsrCfg[OSNISR + 1U];

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#endif



#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"


extern const OSSHORT OsIsr[OSNINTC];             /**< one interrupt controller in single core */

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#define OSISREXCEPTIONIDX  OSNINTC      /* reserved vector number of INTC  */
#define OSISREXCEPTIONPRIO 1


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

extern void OSISRException (void);

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif

#endif /*OS_ISR_CONFIG_H_ */

/** @} */
