/**
*   @file    Os_resource_internal_types.h
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

#ifndef OS_RESOURCE_INTERNAL_TYPES_H_
#define OS_RESOURCE_INTERNAL_TYPES_H_


#ifdef __cplusplus
extern "C"
{
#endif

/*
 *  resource and spinlock specific internal types
 */

#include <Os_prop_autosar.h>
#include <Os_types_basic.h>             /* for OSWORD type ...  */
#include <Os_types_common_public.h>     /* for OSObjectType ... */
#include <Os_types_common_internal.h>   /* for OSPRIOTYPE, OSTSKCBPTR ...   */


#if defined(OSRESOURCE)

#define OSNALLRES (OSNRESS + OSNISRRESS)

/* resource control block */
typedef struct TagOSRESCB OSRESCB;
typedef OSRESCB *OSResType;

struct TagOSRESCB
{

    #if defined(OSUSERESLINK)   
    OSRefResType nextRes;          /* Link to next item in the resource list */

    #endif /* defined(OSUSERESLINK) */

    OSPRIOTYPE resPrio;            /* Resource priority for task resources */
    OSTSKCBPTR prio2task;          /* to save the OsPrioLink[]/ISR last resource previous value  */

    #if defined(OSRESOURCEISR)
    OSINTMASKTYPE savedIsrMask;    /* previous Interrupt mask */
    #endif                         /* defined(OSRESOURCEISR) */

    #if defined(OSTIMINGPROTECTION)

    #if (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U)
    OSTPTICKTYPE tpRemained;       /* remained time on resource locking time */
    OSResType tpNextRes;           /* Link to next item in the list of resources with started TP */
    #endif
    #endif /* defined(OSTIMINGPROTECTION) */

    #if (OSORTIDEBUGLEVEL > 0U) || defined(OSEXTSTATUS)
    OSBYTE isUsed;                 /* Flag that the resource is used */
    #endif

    #if (OSORTIDEBUGLEVEL > 0U)
    OSPRIOTYPE curPrio;            /* current task priority */
    #endif


    #if defined(OSAPPLICATION)
    OSAPPLICATIONMASKTYPE appMask; /* application access mask */
    #endif
};

#endif /* defined(OSRESOURCE) */


#if defined(OSRESOURCE)

#define OSNALLRES_ OSNALLRES


#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

extern OSRESCB OsResources[OSNALLRES_];         /**< resource control block declaration */

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#endif /* defined(OSRESOURCE) */


#ifdef __cplusplus
}
#endif


#endif /*OS_RESOURCE_INTERNAL_TYPES_H_ */

/** @} */
