/**
*   @file    Os_platform_base.h
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

#ifndef OS_PLATFORM_BASE_H
#define OS_PLATFORM_BASE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_platform.h>

/*
 * this file will include base addresses for the specific platform
 * will be on platform specific branch
 * now contains defines for all the platforms
 *
 */

/*
 *  Timer base addresses ***********************************************************************************************
 */












      /* Pictus */
#if defined(OSMPC5602P)
#define OSeTimerBASE0   (0xFFE18000UL)    /* eTimer0 base address */
#define OSPITBASE       (0xC3FF0000UL)    /* PIT base address */
#define OSSTMBASE       (0xFFF3C000UL)    /* STM base address */
#endif

      /* Pictus */
#if defined(OSMPC5604P)
#define OSeTimerBASE0   (0xFFE18000UL)    /* eTimer0 base address */
#define OSeTimerBASE1   (0xFFE1C000UL)    /* eTimer1 base address */
#define OSPITBASE       (0xC3FF0000UL)    /* PIT base address */
#define OSSTMBASE       (0xFFF3C000UL)    /* STM base address */
#endif

      /* Bolero */
#if defined(OSMPC5602D)
#define OSeMIOSBASE0    (0xC3FA0000UL)    /* eMIOS0 base address */
#define OSPITBASE       (0xC3FF0000UL)    /* PIT base address */
#define OSSTMBASE       (0xFFF3C000UL)    /* STM base address */
#endif

      /* Bolero */
#if defined(OSMPC5604B) || defined(OSMPC5606B) || \
    defined(OSMPC5607B) || defined(OSMPC5606S)
#define OSeMIOSBASE0    (0xC3FA0000UL)    /* eMIOS0 base address */
#define OSeMIOSBASE1    (0xC3FA4000UL)    /* eMIOS1 base address */
#define OSPITBASE       (0xC3FF0000UL)    /* PIT base address */
#define OSSTMBASE       (0xFFF3C000UL)    /* STM base address */
#endif














/*
 * INTC base address ***************************************************************************************************
 */


#define OSINTC_BASE_ADDR        (0xFFF48000UL)



#if defined(OSMEMPROTECTION)

/*
 *  MPU base addresses **************************************************************************************************
 */


#if defined(OSMPC5604B) || defined(OSMPC5606B) || defined(OSMPC5607B) || defined(OSMPC5606S)
#define OSMPU_BASE (0xFFF10000UL)
#endif











#endif /* defined(OSMEMPROTECTION) */

/*
 *  SEMA4 base addresses **************************************************************************************************
 */






/*
 *  SSCM base addresses **************************************************************************************************
 */





/*
 *  CRP base addresses **************************************************************************************************
 */





#if defined(OSMEMPROTECTION)
/*
 * Peripheral memory regions - only needed for devices with MPU ***********************************************************************************
 */








#if defined(OSMPC5604B)
#define OSBRIDGE1ADDR (0xC3F88000UL)
#define OSBRIDGE1SIZE (0x0006C000UL)

#define OSBRIDGE2ADDR (0xFFE00000UL)
#define OSBRIDGE2SIZE (0x00200000UL)
#endif

#if defined(OSMPC5606B)
#define OSBRIDGE1ADDR (0xC3F88000UL)
#define OSBRIDGE1SIZE (0x0006C000UL)

#define OSBRIDGE2ADDR (0xFFE00000UL)
#define OSBRIDGE2SIZE (0x00200000UL)
#endif

#if defined(OSMPC5607B)
#define OSBRIDGE1ADDR (0xC3F88000UL)
#define OSBRIDGE1SIZE (0x0006C000UL)

#define OSBRIDGE2ADDR (0xFFE00000UL)
#define OSBRIDGE2SIZE (0x00200000UL)
#endif
    








#endif /* defined(OSMEMPROTECTION) */


#ifdef __cplusplus
}
#endif

#endif /*OS_PLATFORM_BASE_H */

/** @} */
