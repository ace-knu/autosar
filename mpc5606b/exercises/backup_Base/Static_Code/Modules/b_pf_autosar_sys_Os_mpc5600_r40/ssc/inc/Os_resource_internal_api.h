/**
*   @file    Os_resource_internal_api.h
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

#ifndef OS_RESOURCE_INTERNAL_API_H_
#define OS_RESOURCE_INTERNAL_API_H_


#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>
#include <Os_types_common_internal.h>   /* for OSTSKCBPTR ...   */

#include <Os_resource_internal_types.h>


#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSRESOURCEISR)
OSDECLAREVAR (extern OSNEAR OSWORD, OsISRResourceCounter_);
#define OsISRResourceCounter OSUSEVAR(OsISRResourceCounter_)
#endif

#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"


   /* resource internal defines */
#if defined(OSUSERESLINK)

#define OSNULLREFRES  (OSRefResType)0
#define OSNULLRES     (OSResType)0


#endif /* defined(OSUSERESLINK) */

#if defined(OSRESOURCE)

        /* used in Os_mem.c and Os_resource.c */
#if defined(OSRES_SCHEDULER)
#define OSRES_SCHEDULER_ID ((ResourceType)OS_MKOBJID(OBJECT_RESOURCE, (OSNALLRES-1U)))
#endif

#if defined(OSUSETCB)
#define OSNULLPRIOLINK (OSTSKCBPTR)0            /**< used in Os_task.c and Os_resource.c */
#endif

#endif /* defined(OSRESOURCE) */


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"


    /*  resource internal os api  */
#if defined(OSRESOURCE)
extern void OSInitResources (void);         /**< used in Os_setup.c */
#endif /* defined(OSRESOURCE) */

#if defined(OSUSERESLINK)

extern void OSReleaseTaskResource (const OSTSKCBPTR taskPtr);        /**< defined in Os_resource.c used in Os_task.c */

#if defined(OSRESOURCEISR) && defined(OSUSERESLINK)
extern void OSReleaseISRResources (OS_ISRTYPEPTR handlerPtr);               /**< defined in Os_resource.c used in Os_isr.c */
#endif

#endif /* OSUSERESLINK */


#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif


#endif /*OS_RESOURCE_INTERNAL_API_H_ */

/** @} */
