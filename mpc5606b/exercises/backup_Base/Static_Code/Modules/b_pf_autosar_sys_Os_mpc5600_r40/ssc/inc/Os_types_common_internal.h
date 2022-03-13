/**
*   @file    Os_types_common_internal.h
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

#ifndef OS_TYPES_COMMON_INTERNAL_H_
#define OS_TYPES_COMMON_INTERNAL_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>

#include <Os_types_basic.h>

typedef signed char OSPRIOTYPE;
typedef OSDWORD OSTASKTYPE;     /*  for internal representation (then compiler don't recast register to TaskType */
typedef OSDWORD OSINTMASKTYPE;  /*  Interrupt mask                              */
typedef OSDWORD OSISRLEVELTYPE; /*  system level type */

typedef unsigned char OSSUSPENDLEVELTYPE;

typedef void (*OSCALLBACK) (void);

/************************************************************************************************************************/

#if defined(OSTIMINGPROTECTION)
typedef OSDWORD OSTPTICKTYPE;
#endif


/************************************************************************************************************************/

#if defined(OSUSETCB)
typedef struct TagOSTSKCB OSTSKCB;      /* Task control block */
typedef OSTSKCB *OSTSKCBPTR;    /* Pointer to the task control block */
#endif


#if defined(OSNOFASTTERMINATE)
typedef void (*OSTASKENTRY) (void);
#else
typedef OSTASKTYPE (*OSTASKENTRY) (void);
#endif


#if defined(OSUSETCB)
#define OSJBLEN (21)            /* 21 GPRs; (library _JBLEN is 26) */
#else /* if task CB is not used */
#define OSJBLEN (21)            /* 21 registers saved */
#endif /* defined(OSUSETCB) */

#if defined(OSUSETCB)

/*  Contexts of tasks */
typedef OSDWORD OSJMP_BUF[OSJBLEN];
typedef OSDWORD *OSJMP_BUFPTR;

#endif

/************************************************************************************************************************/


typedef struct tagISRTYPE OS_ISRTYPE;
typedef OS_ISRTYPE *OS_ISRTYPEPTR;


/* the ISR type */
typedef void (*OSVOIDFUNCVOID) (void);


typedef enum
{ OSNONTRUSTEDISR2, OSTRUSTEDISR2, OSISR1, OSSYSINTERRUPT, OSTPISR1, OSCALLBACKISR, OSSYSLINKEDINTERRUPT } OSISRTYPE;

/************************************************************************************************************************/
#if (OSNALMS > 0U)

typedef struct TagOSREFALM *OSAlmType;  /* OS internal type - pointer to the alarm node    */

/*  Common alarm structure. It is used only as a reference type (OsAlmType) during the processing alarm queue.
 *  NB! User and Schedule Table alarms must have the same items at the beginning
 */
struct TagOSREFALM
{
    OSAlmType next;             /* next alarm in the list */
    OSAlmType prev;             /* previous alarm in the list   */
    TickType value;             /* Alarms' expiration value   */
    TickType cycle;             /* period value for cyclic alarm    */
    OSWORD ctrIndex;            /* attached Counter ID  */
};

#define OSALMCBPTR0         ( (OSAlmType)0 )    /* Null-pointer */
#define OSALM0              OSALMCBPTR0 /* AlarmId is address of the alarm control block    */


/*
 * use in both Alarm and Schedule table
 */
struct TagOSALMACT              /* Structure of the alarm action    */
{                               /* used in Alarms and Schedule Tables for Task Activation and Events only   */
    OSWORD taskIndex;           /* Task to start or to set Event    */

    #if  defined(OSALMSETEVENT) || defined(OSSCTSETEVENT)
    EventMaskType event;        /* if event==0 alarm activates task */
    /* else it sets event for this task */
    #endif                          /* defined(OSALMSETEVENT) || defined(OSSCTSETEVENT) */
};

typedef struct TagOSALMACT OSALMACT;    /* Alarm action */
typedef const OSALMACT *OSALMACTPTR;  /* Pointer to alarm action */

#endif /* (OSNALMS > 0U) */

/************************************************************************************************************************/
/*
 *
 * used in resource, isr and task
 *
 */

#if defined(OSUSERESLINK)


/* reference resource CB */
typedef struct TagOSREFRESCB OSREFRESCB;
typedef OSREFRESCB *OSRefResType;

struct TagOSREFRESCB
{
    OSRefResType nextRes;       /* Link to next item in the resource list */
};


#endif /* defined(OSUSERESLINK) */
/************************************************************************************************************************/

#ifdef __cplusplus
}
#endif


#endif /*OS_TYPES_COMMON_INTERNAL_H_ */

/** @} */
