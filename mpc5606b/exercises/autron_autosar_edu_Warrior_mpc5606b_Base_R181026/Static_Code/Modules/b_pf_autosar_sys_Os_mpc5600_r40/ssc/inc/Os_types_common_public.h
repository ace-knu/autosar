/**
*   @file    Os_types_common_public.h
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

#ifndef OS_TYPES_COMMON_PUBLIC_H_
#define OS_TYPES_COMMON_PUBLIC_H_


#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_types_basic.h>

#define OSFALSE         (0U)
#define OSTRUE          (1U)

/*
 *  types required by the Autosar API
 */

typedef OSBYTE OSAPPLICATIONTYPE;
typedef OSBYTE OSAPPLICATIONMASKTYPE;

/* avoid collision with MCAL */
#ifndef STATUSTYPEDEFINED
/* prescribed by OSEK/VDX */
#define STATUSTYPEDEFINED       /* required by OSEK/VDX Binding Specification */

#define E_OK                      ( (StatusType) 0 )   /* No error, successful completion  */
typedef unsigned char StatusType;       /* OSEK: Status type             */

#endif /* !defined(STATUSTYPEDEFINED) */


typedef OSWORD OSObjectType;            /* bits [15] - Core Id, bits [14..11] - ObjType, bits [10..0] - ObjId, */

typedef OSObjectType TaskType;          /* used in task, events api ... */

typedef OSDWORD TickType;               /* Type for timers ticks - use by counter, alarm, schedule table alarm */
typedef TickType  *TickRefType;         /* OSEK: Reference to counter value - use by counter and alarm */


/* used in both alarm and counter */
#if defined(OSCOUNTER)

/* OSEK: counter characteristics storage */
typedef struct
{
    TickType maxallowedvalue;   /* maximum possible allowed count value; */
    TickType ticksperbase;      /* number of ticks required to reach a counter-specific
                                   significant unit (it is a user constant, OS does not use it) */
    #if defined(OSEXTSTATUS)
    TickType mincycle;          /* minimum allowed number of ticks for a cyclic alarm */
    #endif

} CtrInfoType;

typedef CtrInfoType *CtrInfoRefType;    /* reference to counter characteristics */

#endif /* defined(OSCOUNTER)  */


typedef OSDWORD EventMaskType;                /**< used in event and alarm  */
typedef EventMaskType *EventMaskRefType;      /**< used in event and alarm */


typedef OSObjectType ApplicationType;
typedef unsigned char AppModeType;      /* OSEK: Application mode type   */


typedef OSObjectType    ISRType; /* used both in memory and ISR */


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /*OS_TYPES_COMMON_PUBLIC_H_ */

/** @} */

