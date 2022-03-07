/**
*   @file    Os_resource_api.h
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

#ifndef OS_RESOURCE_API_H
#define OS_RESOURCE_API_H


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <Os_prop_autosar_api.h>
#include <Os_memory_api.h>      /* for OSServiceCallX defines */
#include <Os_resource_types.h>  /* for StatusType, ResourceType */

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

    /*  Public OS Services  */
#if defined(OSRESOURCE)

#define DeclareResource(ResID) extern OSBYTE osdummy

extern StatusType OS_GetResource (ResourceType resId);
extern StatusType OS_ReleaseResource (ResourceType resId);

#if defined(OSMEMPROTECTION)

OSINLINE StatusType
GetResource (ResourceType resId)
{
    OSServiceCall1 (StatusType, resId, GetResource);
}

OSINLINE StatusType
ReleaseResource (ResourceType resId)
{
    OSServiceCall1 (StatusType, resId, ReleaseResource);
}

#else

#define GetResource(resId)     OS_GetResource(resId)
#define ReleaseResource(resId) OS_ReleaseResource(resId)
#endif


#else /* defined(OSRESOURCE) */

#if defined(OSINRES)            /* if there are internal Resources  */
#define DeclareResource(ResID) extern OSBYTE osdummy
#endif

#endif /* defined(OSRESOURCE) */


#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /*OS_RESOURCE_API_H */

/** @} */
