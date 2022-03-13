/**
*   @file    Os_application_internal_types.h
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
#ifndef OS_APPLICATION_INTERNAL_TYPES_H_
#define OS_APPLICATION_INTERNAL_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>
#include <Os_types_basic.h>     /* for OSDWORD    */
#include <Os_types_common_internal.h>   /* for OSCALLBACK */
#include <Os_error_internal_types.h>    /* for OSHKERROR */
#include <Os_tp_config.h>       /* for OSTPBUDGET */

    /* OS-Application control block */
typedef struct
{
    #if defined(OSAPPHOOKSTARTUP)
    OSHKSTARTUP startup;        /* pointer to startup hook */
    #endif
    #if defined(OSAPPHOOKSHUTDOWN)
    OSHKSHUTDOWN shutdown;      /* pointer to shutdown hook */
    #endif
    #if defined(OSAPPHOOKERROR)
    OSHKERROR error;            /* pointer to error hook */
    #endif

    OSDWORD tasks;              /* all tasks of the application, priority-wise */

    #if defined(OSEXTPRIORS)
    OSDWORD tasks2;             /* tasks of the application, priority-wise, if the tasks are more than 32 */
    #endif
    #if defined(OSHAS_RESTARTTASK)
    OSWORD restartTask;         /* index in OsTaskTable */
    #endif
    ApplicationStateType state; /* OS-Application state */
    #if (OSNTRUSTEDFUNCTIONS > 0U)
    #if defined(OSTPBUDGET)
    StatusType tpError;         /* an error code of TP violation occured inside trusted function */
    #endif
    OSBYTE tfContext;           /* counter of nested calls of CallTrustedFunction() */
    #endif                      /* (OSNTRUSTEDFUNCTIONS > 0U) */

} OSAPPCB;                      /* this structure includes fields of OSAPP stucture */

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSAPPLICATION)
extern OSAPPCB OsAppTable[OSNAPPS];
#endif

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif

#endif /*OS_APPLICATION_INTERNAL_TYPES_H_ */

/** @} */
