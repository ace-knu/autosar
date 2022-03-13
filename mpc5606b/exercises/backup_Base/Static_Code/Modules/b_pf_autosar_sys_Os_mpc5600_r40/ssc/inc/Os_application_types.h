/**
*   @file    Os_application_types.h
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

#ifndef OS_APPLICATION_TYPES_H_
#define OS_APPLICATION_TYPES_H_


#ifdef __cplusplus
extern "C"
{
#endif


#include <Os_prop_autosar_api.h>
#include <Os_types_common_public.h>

/* needed in the API */
typedef OSBYTE ObjectTypeType;
typedef OSBYTE ObjectAccessType;

/* Standard Constants of ObjectAccessType */
#define ACCESS                 ((ObjectAccessType)0)
#define NO_ACCESS              ((ObjectAccessType)1)

typedef enum  { NO_RESTART, RESTART } RestartType;    /* RestartOption for TerminateApplication */

typedef OSBYTE                ApplicationStateType; /* The state of an OS-Application */
typedef ApplicationStateType *ApplicationStateRefType;

#define APPLICATION_ACCESSIBLE ((ApplicationStateType)0)
#define APPLICATION_RESTARTING ((ApplicationStateType)1)
#define APPLICATION_TERMINATED ((ApplicationStateType)2)

#ifdef __cplusplus
}
#endif

#endif /*OS_APPLICATION_TYPES_H_*/


/** @} */
