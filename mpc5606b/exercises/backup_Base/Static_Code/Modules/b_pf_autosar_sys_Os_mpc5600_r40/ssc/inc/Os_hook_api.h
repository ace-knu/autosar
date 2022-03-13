/**
*   @file    Os_hook_api.h
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

#ifndef OS_HOOK_API_H_
#define OS_HOOK_API_H_



#ifdef __cplusplus
extern "C"{
#endif

#include <Os_prop_autosar_api.h>


/*
 * nonAutosar, Freescale specific variables
 */
#if defined(OSTERMINATION)

#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSHOOKPROTECTION)

OSDECLAREVAR (extern OSNEAR TaskType, OsViolatorTaskId_);       /* Task Id of task which has violated */
#define OsViolatorTaskId OSUSEVAR(OsViolatorTaskId_)

OSDECLAREVAR (extern OSNEAR ISRType, OsViolatorISRId_);         /* ISR2 Id of ISR2 which has violated */
#define OsViolatorISRId OSUSEVAR(OsViolatorISRId_)

#if defined(OSAPPLICATION)
OSDECLAREVAR (extern OSNEAR ApplicationType, OsViolatorAppId_); /* Application Id of runnable which has violated */
#define OsViolatorAppId OSUSEVAR(OsViolatorAppId_)
#endif

#endif /* defined(OSHOOKPROTECTION) */

#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#endif /* defined(OSTERMINATION) */



/*
 * user provided code
 */
#if defined(OSHOOKPROTECTION) 
#if !defined(OSSC1)

typedef unsigned char ProtectionReturnType;

#define OSHOOK_START_SEC_CODE
#include "Os_memmap.h"

extern ProtectionReturnType ProtectionHook (StatusType FatalError);

#define OSHOOK_STOP_SEC_CODE
#include "Os_memmap.h"

#define PRO_KILLTASKISR           ((ProtectionReturnType)1)
#define PRO_KILLAPPL              ((ProtectionReturnType)2)
#define PRO_KILLAPPL_RESTART      ((ProtectionReturnType)3)
#define PRO_SHUTDOWN              ((ProtectionReturnType)4)

#define PRO_TERMINATETASKISR      PRO_KILLTASKISR
#define PRO_TERMINATEAPPL         PRO_KILLAPPL
#define PRO_TERMINATEAPPL_RESTART PRO_KILLAPPL_RESTART
#define PRO_IGNORE                ((ProtectionReturnType)5)

#endif /* !defined(OSSC1) */
#endif /* defined(OSHOOKPROTECTION) */


#define OSHOOK_START_SEC_CODE
#include "Os_memmap.h"

#if defined(OSHOOKSTARTUP)
extern void StartupHook (void);
#endif

#if defined(OSHOOKSHUTDOWN)
extern void ShutdownHook (StatusType error);
#endif

#if defined(OSHOOKPRETASK)
extern void PreTaskHook (void);
#endif

#if defined(OSHOOKPOSTTASK)
extern void PostTaskHook (void);
#endif

#define OSHOOK_STOP_SEC_CODE
#include "Os_memmap.h"


#ifdef __cplusplus
}
#endif



#endif /*OS_HOOK_API_H_*/

/** @} */

