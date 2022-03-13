/**
*   @file    Os_application_api.h
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

#ifndef OS_APPLICATION_API_H_
#define OS_APPLICATION_API_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar_api.h>
#include <Os_application_types.h>

#include <Os_memory_api.h>

 /*
  * API in this file
  *
  * CheckObjectAccess
  * CheckObjectOwnership
  *
  * GetApplicationID
  * TerminateApplication
  * AllowAccess
  * GetApplicationState
  *
  */

 /*
  * return value for CheckObjectOwnership and GetApplicationID
  */
#define INVALID_OSAPPLICATION   ((ApplicationType)OS_MKOBJID(OBJECT_APPLICATION, OSNAPPS))

#if defined(OSAPPLICATION)

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

extern ObjectAccessType OS_CheckObjectAccess (ApplicationType appId, ObjectTypeType objectType, OSObjectType objectId);
extern ApplicationType OS_CheckObjectOwnership (ObjectTypeType objectType, OSObjectType objectId);
extern ApplicationType OS_GetApplicationID (void);


extern StatusType OS_GetApplicationState (ApplicationType appId, ApplicationStateRefType stateRef);
extern StatusType OS_AllowAccess (void);

extern StatusType OS_TerminateApplication (ApplicationType appId, RestartType RestartOption);


#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#endif /* defined(OSAPPLICATION) */

#if defined(OSMEMPROTECTION)

OSINLINE ObjectAccessType
CheckObjectAccess (ApplicationType appId, ObjectTypeType objectType, OSObjectType objectId)
{
    OSServiceCall3 (ObjectAccessType, appId, objectType, objectId, CheckObjectAccess);
}

OSINLINE ApplicationType
CheckObjectOwnership (ObjectTypeType objectType, OSObjectType objectId)
{
    OSServiceCall2 (ApplicationType, objectType, objectId, CheckObjectOwnership);
}

OSINLINE ApplicationType
GetApplicationID (void)
{
    OSServiceCall0 (ApplicationType, GetApplicationID);
}


OSINLINE StatusType
AllowAccess (void)
{
    OSServiceCall0 (StatusType, AllowAccess);
}

OSINLINE StatusType
GetApplicationState (ApplicationType appId, ApplicationStateRefType stateRef)
{
    OSServiceCall2 (StatusType, appId, stateRef, GetApplicationState);
}


OSINLINE StatusType
TerminateApplication (ApplicationType appId, RestartType RestartOption)
{
    OSServiceCall2 (StatusType, appId, RestartOption, TerminateApplication);
}


#else /* below for SC1/2 = !defined(OSMEMPROTECTION)  */



#define CheckObjectAccess( appId, objectType, objectId )    OS_CheckObjectAccess( appId, objectType, objectId )
#define CheckObjectOwnership( objectType, objectId   )      OS_CheckObjectOwnership( objectType, objectId )

#define GetApplicationID()                                  OS_GetApplicationID()

#define AllowAccess()                                       OS_AllowAccess( )
#define GetApplicationState( appId, stateRef )              OS_GetApplicationState( appId, stateRef )

#define TerminateApplication( appId, RestartOption )        OS_TerminateApplication( appId, RestartOption )


#endif /* defined(OSMEMPROTECTION) */


#ifdef __cplusplus
}
#endif

#endif /*OS_APPLICATION_API_H_ */

/** @} */
