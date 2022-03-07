/**
*   @file    Os_platform.h
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

#ifndef OS_PLATFORM_H_
#define OS_PLATFORM_H_

#ifdef __cplusplus
extern "C"
{
#endif


/*
 * platform specific file
 * placed on platform branch
 * includes available only if present on specific platform
 * conditional includes not needed as the right files will be included only on the specific platform
 */

#include <Os_prop_platform.h> /**< user provided platform configuration */
#include <Os_platform_config.h> /**< select IPs available on platform */
#include <Os_platform_base.h>   /**< provides base addresses for each IP */
#include <Os_hw_core.h>          /**< provides register access macros  */

#include <Os_platform_timers.h>
#include <Os_platform_interrupt.h>


#include <Os_platform_application.h>
#include <Os_platform_memory.h>


#ifdef __cplusplus
}
#endif


#endif /* OS_PLATFORM_H_ */

/** @} */
