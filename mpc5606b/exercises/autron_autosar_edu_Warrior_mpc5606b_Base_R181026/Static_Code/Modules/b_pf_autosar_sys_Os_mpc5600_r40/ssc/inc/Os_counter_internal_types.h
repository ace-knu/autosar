/**
*   @file    Os_counter_internal_types.h
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

#ifndef OS_COUNTER_INTERNAL_TYPES_H_
#define OS_COUNTER_INTERNAL_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>
#include <Os_types_basic.h>     /* for OSDWORD ... */
#include <Os_types_common_internal.h>   /* for OSAPPLICATIONTYPE, OSAlmType */
#include <Os_counter_types.h>   /* for TickType */

/* Counter control block            */
struct TagOSCTRCB                  /* counter control block (node) */
{
#if (OSNALMS > 0U)
    OSAlmType alarm;               /* pointer to assigned running alarms */
#endif

    TickType value;                /* current value of counter */


#if defined(OSAPPLICATION)
    OSAPPLICATIONTYPE appId;       /* application identification value */
    OSAPPLICATIONMASKTYPE appMask; /* application access mask */
#endif
};

typedef struct TagOSCTRCB OSCTRCB;         /**< Counter control block  */


#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSCOUNTER)

extern OSCTRCB OsCounters[OSNCTRS];       /**< Counters control blocks declaration */

#if defined(OSALMINCCOUNTER)
extern OSWORD OsCtrIncValue[OSNCTRS - OSNHWCTRS];              /**< Counter increment value inspired by corresponding alarm action */
#endif

#endif

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif


#endif /*OS_COUNTER_INTERNAL_TYPES_H_ */

/** @} */
