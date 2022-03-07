/**
*   @file    Os_ioc_internal_types.h
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

#ifndef OS_IOC_INTERNAL_TYPES_H_
#define OS_IOC_INTERNAL_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>

#include <Os_types_common_public.h>
#include <Os_types_basic.h>
#include <Os_types_common_internal.h>



#if defined(OSIOCACTION)
struct TagOSIOCACT              /* Structure of the IOC action    */
{
    OSWORD taskIndex;
    #if defined(OSIOCSETEVENT)
    EventMaskType event;
    #endif
};

typedef struct TagOSIOCACT OSIOCACT;    /* IOC action */
#endif /* defined(OSIOCACTION) */


#if (OSNIOCCALLBACKS > 0U) || defined(OSIOCACTION)

typedef struct TagOSIOCCOMMCB * OSIOCCommCBType;  /* OS internal type - pointer to the IOC callback node    */

/*  Common IOC communication structure. It is used only as a reference type (OSIOCCommCBType) during the processing IOC callbacks and actions.
 *  NB! All communication control block structures have to have fields with the same types at the beginning.
 */
struct TagOSIOCCOMMCB
{
    #if (OSNIOCCALLBACKS > 0U)
    OSIOCCommCBType next;
    OSCALLBACK callBack;
    #endif
    OSAPPLICATIONMASKTYPE sndAppMask;
    OSAPPLICATIONMASKTYPE rcvAppMask;
    OSAPPLICATIONTYPE rcvAppId;


    #if defined(OSIOCACTION)
    OSIOCACT action;
    #endif
};

#if (OSNIOCCALLBACKS > 0U)
typedef struct TagOSIOCCALLBACKQUEUE OSIocCallbackQueue;  /*  Callback queue structure */
struct TagOSIOCCALLBACKQUEUE
{
    OSIOCCommCBType head;
    OSIOCCommCBType tail;
};
#endif

#endif /* (OSNIOCCALLBACKS > 0U) || defined(OSIOCACTION) */

#if (OSNIOCBUFFERS > 0U)

struct tagIOCBUFFERCOMMCB
{
    #if (OSNIOCCALLBACKS > 0U)
    OSIOCCommCBType next;

    OSCALLBACK callBack;
    #endif

    OSAPPLICATIONMASKTYPE sndAppMask;
    OSAPPLICATIONMASKTYPE rcvAppMask;
    OSAPPLICATIONTYPE rcvAppId;


    #if defined(OSIOCACTION)
    OSIOCACT action;
    #endif

    OSWORD dataSize;
    OSBYTEPTR dataBuf;
};

typedef struct tagIOCBUFFERCOMMCB OSIOCBUFFERCOMMCB;

#endif /* OSNIOCBUFFERS > 0U */

#if (OSNIOCGROUPBUFFERS > 0U)

struct tagIOCGROUPBUFFERCOMMCB
{
    #if (OSNIOCCALLBACKS > 0U)
    OSIOCCommCBType next;

    OSCALLBACK callBack;
    #endif

    OSAPPLICATIONMASKTYPE sndAppMask;
    OSAPPLICATIONMASKTYPE rcvAppMask;
    OSAPPLICATIONTYPE rcvAppId;


    #if defined(OSIOCACTION)
    OSIOCACT action;
    #endif
};

typedef struct tagIOCGROUPBUFFERCOMMCB OSIOCGROUPBUFFERCOMMCB;

#endif /* OSNIOCGROUPBUFFERS > 0U */


#if (OSNIOCQUEUES > 0U) || (OSNIOCGROUPQUEUES > 0U)

struct tagIOCQUEUECOMMCB
{
    #if (OSNIOCCALLBACKS > 0U)
    OSIOCCommCBType next;

    OSCALLBACK callBack;
    #endif

    OSAPPLICATIONMASKTYPE sndAppMask;
    OSAPPLICATIONMASKTYPE rcvAppMask;
    OSAPPLICATIONTYPE rcvAppId;


    #if defined(OSIOCACTION)
    OSIOCACT action;
    #endif

    OSBYTEPTR dataQueue;
    OSWORD dataSize;
    OSWORD queueSize;

    OSWORD nItems;
    OSWORD head;
    OSWORD tail;
    OSBYTE overflow;
};

typedef struct tagIOCQUEUECOMMCB OSIOCQUEUECOMMCB;

#endif /* (OSNIOCQUEUES > 0U) || (OSNIOCGROUPQUEUES > 0U) */


#ifdef __cplusplus
}
#endif

#endif /*OS_IOC_INTERNAL_TYPES_H_ */

/** @} */
