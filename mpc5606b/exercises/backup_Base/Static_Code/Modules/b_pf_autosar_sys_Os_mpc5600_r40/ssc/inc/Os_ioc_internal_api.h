/**
*   @file    Os_ioc_internal_api.h
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

#ifndef OS_IOC_INTERNAL_API_H_
#define OS_IOC_INTERNAL_API_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>
#include <Os_types_common_internal.h>

#include <Os_ioc_internal_types.h>

#if defined(OSIOC)

#if (OSNIOCCALLBACKS > 0U)

#define OSIOCCALLBACKPTR0 ((OSIOCCommCBType)0u)  /* IOC callback node null-pointer */

#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include    "Os_sections.h"

OSDECLAREVAR (extern OSNEAR OSIocCallbackQueue, OsIOCCallbacks_);   /* Queue for IOC callbacks */
#define OsIOCCallbacks OSUSEVAR(OsIOCCallbacks_)

extern OSNEAR OSWORD OsIOCCallbackCommId;    /* IOC communication ID for which callback shall be invoked */

#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include    "Os_sections.h"

#endif /* (OSNIOCCALLBACKS > 0U) */

#define OS_START_SEC_VAR_UNSPECIFIED
#include    "Os_sections.h"


#if (OSNIOCBUFFERS > 0U)
extern OSNONCACHE OSIOCBUFFERCOMMCB OsIocBufferCommCB[OSNIOCBUFFERS];
#endif

#if (OSNIOCGROUPBUFFERS > 0U)
extern OSNONCACHE OSIOCGROUPBUFFERCOMMCB OsIocGroupBufferCommCB[OSNIOCGROUPBUFFERS];
#endif

#if (OSNIOCQUEUES > 0U)
extern OSNONCACHE OSIOCQUEUECOMMCB OsIocQueueCommCB[OSNIOCQUEUES];
#endif

#if (OSNIOCGROUPQUEUES > 0U)
extern OSNONCACHE OSIOCQUEUECOMMCB OsIocGroupQueueCommCB[OSNIOCGROUPQUEUES];
#endif

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include    "Os_sections.h"

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

/* IOC function prototypes */
/* Here's commId is our internal communication number that one-to-one maps to <IocId>
   (this mapping is provided by SysGen).
   For example:
   commId    IocId
   0         comm1
   1         comm2
*/
extern void OSInitIOC (void);

#if defined(OSIOCACTION)
extern void OSIocAction (OSIOCACT * action, OSAPPLICATIONTYPE appId);
#endif /* defined(OSIOCACTION) */

#if (OSNIOCCALLBACKS > 0U)
extern OSBYTE OSIocPrepareCallbackISR (OS_ISRTYPEPTR handlerPtr);
extern void OSIocRemoveAppCallBack (OSAPPLICATIONTYPE appId);
extern void OSIocInsertCallback(OSIOCCommCBType cb);
#endif /* (OSNIOCCALLBACKS > 0U) */

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#if (OSNIOCCALLBACKS > 0U)

#define OSIocCallbackInvoke()  OSIOCCore0Invoke()
#define OSIocCallbackClear()  OSIOCCore0ClearFlag()

#endif /* OSNIOCCALLBACKS > 0 */

#endif /* defined(OSIOC) */

#ifdef __cplusplus
}
#endif

#endif /*OS_IOC_INTERNAL_API_H_ */

/** @} */
