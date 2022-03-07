/**
*   @file    Os_prop_platform.h
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

#ifndef OS_PROP_PLATFORM_H
#define OS_PROP_PLATFORM_H


#ifdef __cplusplus
extern "C"
{
#endif


/*
 *  in here only defines needed in the PLATFORM layer, no need to export them to the upper layers
 *
 */

#include <Os_prop_autosar.h>

#if !defined(OSPROPH)
    #include    "Os_prop.h"    /* OS Properties */
#else      /* !defined(OSPROPH)    */
    #include    OSPROPH    /* OS Properties */
#endif      /* !defined(OSPROPH)    */


#ifdef __cplusplus
}
#endif


#endif /*OS_PROP_PLATFORM_H*/

/** @} */

