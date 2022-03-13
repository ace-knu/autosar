/**
*   @file    Os_alarm_internal_types.h
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

#ifndef OS_ALARM_INTERNAL_TYPES_H_
#define OS_ALARM_INTERNAL_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>
#include <Os_types_basic.h>     /* for OSDWORD    */
#include <Os_types_common_internal.h>   /* for OSCALLBACK */

#if (OSNALMS > 0U)

#if (OSNUSERALMS > 0U)
        /* Structure of the alarm control block  */
struct TagOSALMCB
{
    /* this field shall be first in the record because it is used in OsCheckAlarms */
    OSAlmType next;                /* next alarm in the list */
    OSAlmType prev;                /* previous alarm in the list   */
    TickType value;                /* Alarms' expiration value   */
    TickType cycle;                /* period value for cyclic alarm    */

    /*  Copy of Configuration Data  */
    OSWORD ctrIndex;               /* attached Counter ID  */

    #if defined(OSALMINCCOUNTER)
    OSWORD ctrIndexInc;            /* Alarms' increment counter */
    #endif

    #if (OSNUSERALMS > 0U)
    OSALMACT action;               /* Alarm action */
    #endif

    #if defined(OSALMCALLBACK)
    OSCALLBACK callBack;           /* Alarms' hook entry  */
    #endif

    #if defined(OSAPPLICATION)
    #if (OSNUSERALMS > 0U)
    OSAPPLICATIONTYPE appId;       /* application identification value */
    OSAPPLICATIONMASKTYPE appMask; /* application access mask */
    #endif
    #endif
};

typedef struct TagOSALMCB OSALMCB;      /* Alarm control block (node)   */

#endif /* (OSNUSERALMS > 0U) */

#endif /* (OSNALMS > 0U) */

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#if (OSNALMS > 0U)
#if (OSNUSERALMS > 0U) && (OSNSCTALMS == 0U)
extern OSALMCB OsAlarms[OSNUSERALMS];
#endif
#endif /* (OSNALMS > 0U) */

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif



#endif /*OS_ALARM_INTERNAL_TYPES_H_ */

/** @} */
