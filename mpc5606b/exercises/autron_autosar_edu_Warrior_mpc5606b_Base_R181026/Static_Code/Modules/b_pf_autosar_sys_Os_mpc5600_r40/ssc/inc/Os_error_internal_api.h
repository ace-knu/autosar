/**
*   @file    Os_error_internal_api.h
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

#ifndef OS_ERROR_INTERNAL_API_H_
#define OS_ERROR_INTERNAL_API_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>

#include <Os_error_api.h>             /**< needed because we share error codes with the public API */
#include <Os_error_internal_types.h>

#if defined(OSTERMINATION)

#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

OSDECLAREVAR (extern OSNEAR OSBYTE, OsKilled_); /* flags that Task or ISR was killed and some TP context */
#define OsKilled OSUSEVAR(OsKilled_)

#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#define OSRUNTSKKILLED  ((OSBYTE)0x1)   /**< flags in OsKilled */

#endif /* defined(OSTERMINATION) */

#if defined(OSGETSERVICEID) || defined(OSPARAMETERACCESS)

#define OSPUTPARAM(ID, parm) \
    if( OsService == OSServiceId_NoService ) \
    { \
        OsService = (ID); OsObjId = (OSDWORD)(parm); \
    }

#define OSCLEARPARAM() (OsService = OSServiceId_NoService)

#else            /* defined(OSGETSERVICEID) || defined(OSPARAMETERACCESS) */

   #define OSPUTPARAM(ID, parm)
   #define OSCLEARPARAM()

#endif            /* defined(OSGETSERVICEID) || defined(OSPARAMETERACCESS) */

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#if defined(OSHOOKERROR) || defined(OSAPPHOOKERROR)

extern void OSErrorHook_noPar (StatusType error);

#if defined(OSGETSERVICEID) || defined(OSPARAMETERACCESS)
extern void OSErrorHook (StatusType error, OSServiceIdType ID, OSObjectType param);
#else
extern void OSErrorHook_1 (StatusType error);
#define OSErrorHook( error, ID, param ) OSErrorHook_1( error )
#endif

#define OSRETERROR( error, ID, param ) \
    OSErrorHook( (error), (ID), (param) ); \
    OSOrtiServiceWatchOnExit( ID ); \
    return( error )

#define OSRETERROR2( error, ID, param ) \
    OSErrorHook( (error), (ID), (param) ); \
    OSOrtiResetIdOnExit( ); \
    return( error )

#else            /* defined(OSHOOKERROR) || defined(OSAPPHOOKERROR) */

#define OSRETERROR( error, ID, param )  \
    OSPUTERROR( error ); \
    OSOrtiServiceWatchOnExit( ID ); \
    return( error )

#define OSRETERROR2( error, ID, param )  \
    OSPUTERROR( error ); \
    OSOrtiResetIdOnExit( ); \
    return( error )

#define OSErrorHook_noPar( error )

#endif            /* defined(OSHOOKERROR) || defined(OSAPPHOOKERROR) */

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif


#endif /*OS_ERROR_INTERNAL_API_H_*/

/** @} */

