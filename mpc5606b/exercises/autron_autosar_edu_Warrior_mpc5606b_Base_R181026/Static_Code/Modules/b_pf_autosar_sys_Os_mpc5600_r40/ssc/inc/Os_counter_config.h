/**
*   @file    Os_counter_config.h
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
#ifndef OS_COUNTER_CONFIG_H_
#define OS_COUNTER_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>
#include <Os_types_basic.h>     /* for OSDWORD ... */
#include <Os_types_common_internal.h>   /* for OSAPPLICATIONTYPE ... */
#include <Os_counter_types.h>   /* for TickType */

#define OSCTR0    (OSNCTRS)           /* Id for unused counter */

typedef OSDWORD PhysicalTimeType;     /**< Counter ticks */

    /* Counter configuration table  */
struct TagOSCTR
{

    #if defined(OSAPPLICATION)
    OSAPPLICATIONMASKTYPE appMask; /* Application identification mask value */
    #endif

    TickType maxallowedvalue;
    TickType ticksperbase;         /* conversion constant  */

    #if defined(OSEXTSTATUS)
    TickType mincycle;             /* minimum period value for alarm */
    #endif                         /* defined(OSEXTSTATUS) */


    #if defined(OSAPPLICATION)
    OSAPPLICATIONTYPE appId;       /* application identification value */
    #endif

};

typedef struct TagOSCTR OSCTR;  /* Counter configuration table  */
typedef OSCTR *OSCTRPTR;        /* Pointer to the counter configuration table   */

#if defined(OSCOUNTER)

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

extern const OSCTR OsCountersCfg[OSNCTRS];               /**<  Counters configuration data declaration */

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#endif

#if defined(OSSYSTIMER) || defined(OS2SYSTIMER)

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#if defined(OSSYSTIMER)
extern void OSISRSystemTimer (void);
#endif


#if defined(OSSECONDTIMER) || defined(OS2SECONDTIMER)

#if defined(OSSECONDTIMER)
extern void OSISRSecondTimer (void);
#endif


#endif /* defined(OSSECONDTIMER) || defined(OS2SECONDTIMER) */

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#endif /* defined(OSSYSTIMER) || defined(OS2SYSTIMER) */


#ifdef __cplusplus
}
#endif

#endif /*OS_COUNTER_CONFIG_H_ */

/** @} */
