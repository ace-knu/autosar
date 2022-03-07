/**
*   @file    Os_ioc_config.h
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

#ifndef OS_IOC_CONFIG_H_
#define OS_IOC_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>

#include <Os_types_basic.h>
#include <Os_types_common_internal.h>



#if (OSNIOCBUFFERS > 0U)

/* Buffer info structure - for "LastIsBest" communication type */
struct tagIOCBUFFERINFO
{
    OSBYTEPTR dataBuf;
    OSWORD dataSize;

    #if (OSNIOCCALLBACKS > 0U)
    OSCALLBACK callBack;
    #endif

    OSAPPLICATIONMASKTYPE sndAppMask;
    OSAPPLICATIONTYPE rcvAppId;

    #if defined(OSIOCACTION)
    OSWORD taskIndex;
    #if defined(OSIOCSETEVENT)
    EventMaskType event;
    #endif
    #endif
};

typedef struct tagIOCBUFFERINFO OSIOCBUFFERINFO;

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

extern const OSIOCBUFFERINFO OsIocBufferInfo[OSNIOCBUFFERS];

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#endif /* (OSNIOCBUFFERS > 0U) */

#if (OSNIOCGROUPBUFFERS > 0U)

/* Buffer info structure - for group "LastIsBest" communication type */
struct tagIOCGROUPBUFFERINFO
{
    #if (OSNIOCCALLBACKS > 0U)
    OSCALLBACK callBack;
    #endif

    OSAPPLICATIONMASKTYPE sndAppMask;
    OSAPPLICATIONTYPE rcvAppId;

    #if defined(OSIOCACTION)
    OSWORD taskIndex;
    #if defined(OSIOCSETEVENT)
    EventMaskType event;
    #endif
    #endif
};

typedef struct tagIOCGROUPBUFFERINFO OSIOCGROUPBUFFERINFO;

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

extern const OSIOCGROUPBUFFERINFO OsIocGroupBufferInfo[OSNIOCGROUPBUFFERS];

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#endif /* (OSNIOCGROUPBUFFERS > 0U) */

#if (OSNIOCQUEUES > 0U) || (OSNIOCGROUPQUEUES > 0U)

/* Queue info structure - for "Queued" communication type */
struct tagIOCQUEUEINFO
{
    OSBYTEPTR dataQueue;
    OSWORD dataSize;
    OSWORD queueSize;

    #if (OSNIOCCALLBACKS > 0U)
    OSCALLBACK callBack;
    #endif

    OSAPPLICATIONMASKTYPE sndAppMask;
    OSAPPLICATIONTYPE rcvAppId;

    #if defined(OSIOCACTION)
    OSWORD taskIndex;
    #if defined(OSIOCSETEVENT)
    EventMaskType event;
    #endif
    #endif
};

typedef struct tagIOCQUEUEINFO OSIOCQUEUEINFO;

#endif /* (OSNIOCQUEUES > 0U) || (OSNIOCGROUPQUEUES > 0U) */

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#if (OSNIOCQUEUES > 0U)
extern const OSIOCQUEUEINFO OsIocQueueInfo[OSNIOCQUEUES];
#endif
#if (OSNIOCGROUPQUEUES > 0U)
extern const OSIOCQUEUEINFO OsIocGroupQueueInfo[OSNIOCGROUPQUEUES];
#endif

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"


#if (OSNIOCBUFFERS > 0U) || (OSNIOCGROUPBUFFERS > 0U)

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"
extern void OSIOC_Init (void);
#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#endif



#ifdef __cplusplus
}
#endif

#endif /*OS_IOC_CONFIG_H_ */

/** @} */
