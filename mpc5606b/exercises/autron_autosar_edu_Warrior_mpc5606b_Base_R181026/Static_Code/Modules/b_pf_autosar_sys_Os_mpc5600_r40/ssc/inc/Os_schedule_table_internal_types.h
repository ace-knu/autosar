/**
*   @file    Os_schedule_table_internal_types.h
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

#ifndef OS_SCHEDULE_TABLE_INTERNAL_TYPES_H_
#define OS_SCHEDULE_TABLE_INTERNAL_TYPES_H_



#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>
#include <Os_types_basic.h>     /* for OSWORD ... */
#include <Os_types_common_public.h>     /* for TickType ... */
#include <Os_types_common_internal.h>   /* for OSALMACT */

#include <Os_schedule_table_config.h>   /* for OSSCTEP */

    /* Schedule table */
#if defined(OSSCHEDULETABLES)

#define OSSCTABSOLUTE   ((OSWORD)1)
#define OSSCTRELATIVE   ((OSWORD)2)
#define OSSCTSYNCHRON   ((OSWORD)3)

#define OSSCTSTATE      ((OSWORD)0xFF00)        /* Schedule Table state mask */
#define OSSCT0          ((OSSCTCB *) 0) /* idle Schedule Table */

#endif /* defined(OSSCHEDULETABLES) */


/* Alarms */
#if (OSNALMS > 0U)

    /* Schedule tables  */
#if (OSNSCTS > 0U)

typedef struct TagOSREFALM OSSCTALMCB;  /* Schedule table alarm control block (node) */

typedef struct TagOSSCTCB OSSCTCB;      /* Schedule table control block */

struct TagOSSCTCB                  /* Structure of the Schedule Table control block */
{
    /* Current Data */
    OSSCTEPREF currentEP;          /* the current expiry point */
    OSSCTCB *nextId;               /* the ScheduleTableId_To (used only for NextScheduleTable) */
    OSSCTALMCB *almId;             /* the alarm for this SCT */
    #if defined(OSSCTSYNCEXPLICIT)
    TickType deviation;            /* Deviation between local time of the Schedule Table
                                      and value of the synchronization counter */
    TickType precision;            /* Schedule Table synchronization PRECISION value */
    TickType syncData;             /* current EP offset/global time/deviation - depends on OS version */
    TickType length;               /* the length of the Schedule Table in ticks */
    #endif
    TickType initialOffset;        /* Initial Offset of the Schedule Table */
    #if (OSORTIDEBUGLEVEL > 0U)
    TickType ortiEPoffset;         /* expiry point offset is defined for ORTI */
    #endif
    OSSCTEPREF firstEP;            /* the pointer to first expiry point in the Schedule Table */
    OSWORD ctrIndex;               /* attached Counter ID  */
    OSWORD state;                  /* the config(MS) and status(LS) of Schedule Table */
    #if defined(OSAPPLICATION)
    OSAPPLICATIONTYPE appId;       /* Application identification value */
    OSAPPLICATIONMASKTYPE appMask; /* application access mask */
    #endif
};

#endif /* (OSNSCTS > 0U) */

#endif /* (OSNALMS > 0U) */


#ifdef __cplusplus
}
#endif


#endif /*OS_SCHEDULE_TABLE_INTERNAL_TYPES_H_ */

/** @} */
