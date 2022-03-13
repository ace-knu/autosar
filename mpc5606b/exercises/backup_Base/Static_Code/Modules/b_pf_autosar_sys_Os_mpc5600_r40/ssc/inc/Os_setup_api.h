/**
*   @file    Os_setup_api.h
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

#ifndef OS_SETUP_API_H
#define OS_SETUP_API_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <Os_prop_autosar_api.h>

#include <Os_types_common_public.h>     /* for AppModeType */
#include <Os_memory_api.h>      /* for OSServiceCallX defines */




#define OSDEFAULTAPPMODE (AppModeType)0



#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

extern void StartOS (AppModeType mode);
extern void OS_ShutdownOS (StatusType error);
extern AppModeType OS_GetActiveApplicationMode (void);

/*
 * public API
 */
#if defined(OSMEMPROTECTION)

OSINLINE void
ShutdownOS (StatusType error)
{
    OSServiceCall1V (error, ShutdownOS);
}

OSINLINE AppModeType
GetActiveApplicationMode (void)
{
    OSServiceCall0 (AppModeType, GetActiveApplicationMode);
}

#else /* OSMEMPROTECTION */

#define ShutdownOS( error ) OS_ShutdownOS( error )
#define GetActiveApplicationMode() OS_GetActiveApplicationMode()

#endif /* defined(OSMEMPROTECTION) */

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /*OS_SETUP_API_H */

/** @} */
