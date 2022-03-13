/**
*   @file    Os_stack_api.h
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

#ifndef OS_STACK_API_H_
#define OS_STACK_API_H_


#ifdef __cplusplus
extern "C"
{
#endif


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#if defined(OSSTKCHECK) || (OSORTIDEBUGLEVEL > 0U)

extern OSWORD OS_GetRunningStackUsage (void);
#if defined(OSMEMPROTECTION) && (OSNXTSKS > 0U)
OSINLINE OSWORD GetRunningStackUsage (void)
{
    OSServiceCall0 (OSWORD, GetRunningStackUsage);
}
#else
#define GetRunningStackUsage() OS_GetRunningStackUsage()
#endif

#if !defined(OSMEMPROTECTION)
extern OSWORD GetStackUsage (TaskType taskId);
#endif

#endif /* defined(OSSTKCHECK) || (OSORTIDEBUGLEVEL > 0U) */

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif


#endif /*OS_STACK_API_H_ */

/** @} */
