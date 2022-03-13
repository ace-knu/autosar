/**
*   @file    Os_scheduler_api.h
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

#ifndef OS_SCHEDULER_API_H
#define OS_SCHEDULER_API_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <Os_prop_autosar_api.h>
#include <Os_memory_api.h>      /* for OSServiceCallX defines */

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

extern StatusType OS_Schedule (void);

/*  Public OS Services  */

#if defined(OSMEMPROTECTION)

OSINLINE StatusType
Schedule (void)
{
    OSServiceCall0 (StatusType, Schedule);
}

#else /* defined(OSMEMPROTECTION) */

#define Schedule( ) OS_Schedule( )

#endif /* defined(OSMEMPROTECTION) */

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /*OS_SCHEDULER_API_H */

/** @} */
