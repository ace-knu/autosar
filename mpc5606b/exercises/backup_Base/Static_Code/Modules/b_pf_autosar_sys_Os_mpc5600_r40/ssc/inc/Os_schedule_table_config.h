/**
*   @file    Os_schedule_table_config.h
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

#ifndef OS_SCHEDULE_TABLE_CONFIG_H_
#define OS_SCHEDULE_TABLE_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>
#include <Os_types_basic.h>     /* for OSWORD ... */
#include <Os_types_common_public.h>     /* for TickType ... */
#include <Os_types_common_internal.h>   /* for OSALMACT */

    /* Alarms */
#if (OSNALMS > 0U)

        /* Schedule tables  */
#if (OSNSCTS > 0U)

typedef const struct TagOSREFSCTEP *OSSCTEPREF; /* Reference to expiry point structure (expiry points data is constant) */
struct TagOSREFSCTEP
{
    OSSCTEPREF next;            /* the next expiry point */
    OSALMACT action;
    TickType delta;             /* Delay (in ticks) between the current expiry point 
                                   and the next expiry point(or the end of the schedule if it's 
                                   last expiry point) */
};

typedef struct TagOSSCTEP OSSCTEP;
struct TagOSSCTEP               /* Expiry point structure for Schedule Tables w/o explicit synch.strategy */
{
    OSSCTEPREF next;            /* the next expiry point */
    OSALMACT action;
    TickType delta;             /* Delay (in ticks) between the current expiry point 
                                   and the next expiry point(or the end of the schedule if it's 
                                   last expiry point) */
    #if (OSORTIDEBUGLEVEL > 0U)
    TickType offset;            /* expiry point offset(or zero for the first EP if Schedule Table is single-shot) */
    #endif
};


#if defined(OSSCTSYNCEXPLICIT)
typedef struct TagOSSCTEPEXPL OSSCTEPEXPL;

struct TagOSSCTEPEXPL           /* Expiry point structure for Schedule Tables with explicit synch.strategy */
{
    OSSCTEPREF next;            /* the next expiry point */
    OSALMACT action;
    TickType delta;             /* Delay (in ticks) between the current expiry point 
                                   and the next expiry point(or the end of the schedule if it's 
                                   last expiry point) */
    TickType offset;            /* expiry point offset(or zero for the first EP if Schedule Table is single-shot) */
    TickType maxRetard;         /* MAXRETARD value for the previous expiry point */
    TickType maxAdvance;        /* MAXADVANCE value for the previous expiry point */
};
#endif /* defined(OSSCTSYNCEXPLICIT) */


            /* declaration of configuration structure not needed,
             * declared static in configuration C file as it's
             * referenced in the  OSSCT structure only
             */

struct TagOSSCT                 /* Structure of the Schedule Table cfg  */
{
    OSWORD ctrIndex;            /* attached Counter ID  */
    #if defined(OSSCTSYNCEXPLICIT)
    TickType length;            /* the length of the Schedule Table in ticks */
    #endif
    TickType initialOffset;     /* Initial Offset of the Schedule Table */

    OSSCTEPREF firstEP;         /* the pointer to first expiry point in the Schedule Table */


    #if defined(OSSCTSYNCEXPLICIT)
    TickType precision;         /* Schedule Table PRECISION value */
    #endif
    #if defined(OSAPPLICATION)
    OSAPPLICATIONMASKTYPE appMask; /* Application identification mask value */
    OSAPPLICATIONTYPE appId;    /* Application identification value */
    #endif

    OSBYTE opts;                /* config byte of the Schedule Table */
};

typedef struct TagOSSCT OSSCT;  /* Schedule table cfg */

/* Bit flags in Schedule Table configuration 'state' field,used by sg only */
#define OSSCTCFGPERIODIC        ((OSWORD)0x1)   /* Schedule table is periodic */

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

extern const OSSCT OsScheduleTablesCfg[OSNSCTS];        /* declaration of Schedule Table configuration structure */

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#endif /* (OSNSCTS > 0U) */

#endif /* (OSNALMS > 0U) */

#if defined(OSSCHEDULETABLES)

#if defined(OSAUTOSCHEDULETABLES)

/* The schedule tables which are started on startup of the OS with a given offset. */
struct tagSCTAUTOTYPE
{
    OSWORD sctIndex;
    TickType offset;

    #if (OSNAPPMODES > 1U)
    OSDWORD autostart;
    #endif

    OSBYTE type;
};

typedef struct tagSCTAUTOTYPE OSSCTAUTOTYPE;


#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

extern const OSSCTAUTOTYPE OsAutoScheduleTablesCfg[OSNAUTOSCTS];           /**< declaration of Auto-started Schedule Table array */

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#endif /* defined(OSAUTOSCHEDULETABLES) */

#endif

#if defined(OSSCHEDULETABLES) /**< Schedule table */

#define OSSCTABSOLUTE   ((OSWORD)1)
#define OSSCTRELATIVE   ((OSWORD)2)
#define OSSCTSYNCHRON   ((OSWORD)3)


#define OSSCTCFGIMPLICIT        ((OSBYTE)0x2)   /* Sync strategy is implicit */
#define OSSCTCFGEXPLICIT        ((OSBYTE)0x4)   /* Sync strategy is explicit */


#define OSSCTCFGBITS            ((OSWORD)8)     /* the first cfg.bit in 'state' */
#define OSSCTCFGIMPLMASK        ((OSWORD)0x200) /* Implicit strategy mask */
#define OSSCTCFGEXPLMASK        ((OSWORD)0x400) /* Explicit strategy mask */
#define OSSCTCFGSTRATMASK       ((OSWORD)0x600) /* strategy mask */

#endif /* defined(OSSCHEDULETABLES) */


#ifdef __cplusplus
}
#endif


#endif /*OS_SCHEDULE_TABLE_CONFIG_H_ */

/** @} */
