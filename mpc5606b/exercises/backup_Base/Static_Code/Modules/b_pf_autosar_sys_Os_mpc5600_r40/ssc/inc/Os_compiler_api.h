/**
*   @file    Os_compiler_api.h
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

#ifndef OS_COMPILER_API_H
#define OS_COMPILER_API_H

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef _lint
#define OSLINT                _lint
#endif

#if !defined(OSCWPPC)
#if defined(__MWERKS__)
#define OSCWPPC
#endif /* defined(__MWERKS__) */
#endif

#if defined(OSGHSPPC)
#include <ppc_ghs.h>            /* for intrinsic functions only */
#endif

#if defined(OSDIABPPC)
#if !defined(OSDIABPPC_ASM_H)
#define OSDIABPPC_ASM_H
#include <diab/asm.h>           /* for intrinsic functions only */
#endif
#endif

#if !defined(OSCWPPC) && !defined(OSDIABPPC) && !defined(OSGHSPPC)
#error "Compiler is not defined"
#endif

#if defined(OSDIABPPC)
#define OSASM                 __asm volatile
#endif /* defined(OSDIABPPC) */

#if defined(OSCWPPC)
#define OSASM                 asm
#endif /* defined(OSCWPPC) */

#if defined(OSGHSPPC)
#define OSASM                 asm
#endif /* defined(OSGHSPPC) */


#if defined(OSDIABPPC)
#define OSNEAR                __attribute__(( section(".ossbss") ))
#endif

#if defined(OSCWPPC)
#define OSNEAR                __declspec(section ".ossdata")
#endif

#if defined(OSGHSPPC)
#define OSNEAR
#endif


#define OSNONCACHE


/*
 * definitions for INLINE functions
 * these are needed in the public API
 */

#if defined(OSDIABPPC)
      /* This string should be documented for the inline function using in ISR */
#define OSINLINE                 __inline__
#endif /* defined(OSDIABPPC) */

#if defined(OSCWPPC)
#define OSINLINE                   inline
#endif /* defined(OSCWPPC) */


#if defined(OSGHSPPC)
#ifdef __cplusplus
#define OSINLINE                inline
#else
#define OSINLINE              __inline
#endif
#endif /* defined(OSGHSPPC) */

#ifdef OSLINT
#define OSINLINE_
#else
#define OSINLINE_ OSINLINE
#endif


#ifdef __cplusplus
}
#endif

#endif /*OS_COMPILER_API_H */

/** @} */
