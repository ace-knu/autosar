/**
*   @file    Os_platform_config.h
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

#ifndef OS_PLATFORM_CONFIG_H
#define OS_PLATFORM_CONFIG_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_platform.h>

/*
 * platform specific file
 * placed on platform branch
 * because of this we have only defines for specific platforms and derivatives
 */

/*
 *  core configuration *********************************************************
 */


#define OSE200Z0                /* all MPC5600 MCUs have Z0 core */











/*
 * INTC configuration - interrupt table length *********************************
 */







/* Pictus */
#if defined(OSMPC5602P) || defined(OSMPC5604P)
#define OSNINTC (222U)
#endif

/* Bolero */
#if defined(OSMPC5602D)
#define OSNINTC (155U)
#endif

/* Bolero */
#if defined(OSMPC5604B)
#define OSNINTC (217U)
#endif

/* Bolero */
#if defined(OSMPC5606B) || defined(OSMPC5607B)
#define OSNINTC (234U)
#endif

/* Spectrum */



















/*
 *  Timers available on configuration ******************************************
 */










/* Pictus */
#if defined(OSMPC5602P)
#define OSTIMEReTimer
#define OSTIMPIT_TYPE2
#endif

/* Pictus */
#if defined(OSMPC5604P)
#define OSTIMEReTimer
#define OSTIMEReTimer1
#define OSTIMPIT_TYPE2
#endif


/* Bolero */
#if defined(OSMPC5602D)
#define OSTIMEReMIOS
#define OSTIMPIT_TYPE2
#endif

/* Bolero/Spectrum */
#if defined(OSMPC5604B) || defined(OSMPC5606B) || defined(OSMPC5607B) || defined(OSMPC5606S)
#define OSTIMEReMIOS
#define OSTIMEReMIOS1
#define OSTIMPIT_TYPE2
#endif













#ifdef __cplusplus
}
#endif

#endif /*OS_PLATFORM_CONFIG_H */

/** @} */
