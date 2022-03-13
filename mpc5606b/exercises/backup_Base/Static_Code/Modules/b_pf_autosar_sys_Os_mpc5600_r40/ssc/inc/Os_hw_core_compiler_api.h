/**
*   @file    Os_hw_core_compiler_api.h
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

#ifndef OS_HW_CORE_COMPILER_API_H_
#define OS_HW_CORE_COMPILER_API_H_

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Os_hw_core_compiler_api_h_REF_19_7_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* A function should be used in preference to a funcion-ike macro.
* Function like macros are used to reduce code complexity and for performance reasons.
*/

#if defined(OSGHSPPC)
/*
 * @violates @ref Os_hw_core_compiler_api_h_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define OSMFSPR( spr )        __MFSPR( spr )
#endif            /* defined(OSGHSPPC) */

#if defined(OSDIABPPC)
/*
 * @violates @ref Os_hw_core_compiler_api_h_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define OSMFSPR( spr )        __mfspr( spr )
#endif            /* defined(OSDIABPPC) */


/*
* we need this in the public domain as there are exposed multicore variables
*/

/*
* Get the MSR register value
*/

#if defined(OSDIABPPC)
/*
 * @violates @ref Os_hw_core_compiler_api_h_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define OSGETMSR( ) (OSDWORD)__mfmsr( )
#endif

#if defined(OSGHSPPC)
/*
 * @violates @ref Os_hw_core_compiler_api_h_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define OSGETMSR( ) (OSDWORD)__GETSR( )
#endif

#if defined(OSCWPPC)
OSINLINE OSDWORD
OSGETMSR (void)
{
    register OSDWORD x;
    OSASM
    {
        mfmsr x;
    }
    return x;
}
#endif

/*
* Set the MSR register new value
*/
#if defined(OSDIABPPC)
/*
 * @violates @ref Os_hw_core_compiler_api_h_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define OSSETMSR( x ) __mtmsr( (OSDWORD)x )
#endif

#if defined(OSGHSPPC)
/*
 * @violates @ref Os_hw_core_compiler_api_h_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define OSSETMSR( x ) __SETSR( (OSDWORD)x )
#endif

#if defined(OSCWPPC)
OSINLINE void
OSSETMSR (register OSDWORD x)
{
    OSASM
    {
        mtmsr x;
    }
}
#endif

/* msync and isynch core instruction macros */
#if defined(OSDIABPPC)
/*
 * @violates @ref Os_hw_core_compiler_api_h_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define OSMSYNC()           __msync( )
/*
 * @violates @ref Os_hw_core_compiler_api_h_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define OSISYNC()           __isync( )
#endif       /* defined(OSDIABPPC) */

#if defined(OSCWPPC)
/*
 * @violates @ref Os_hw_core_compiler_api_h_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define OSMSYNC()           OSASM{ msync }
/*
 * @violates @ref Os_hw_core_compiler_api_h_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define OSISYNC()           OSASM{ se_isync }
#endif       /* defined(OSCWPPC) */

#if defined(OSGHSPPC)
/*
 * @violates @ref Os_hw_core_compiler_api_h_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define OSMSYNC()           __MSYNC( )
/*
 * @violates @ref Os_hw_core_compiler_api_h_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define OSISYNC()           __ISYNC( )
#endif       /* defined(OSGHSPPC) */


#ifdef __cplusplus
}
#endif


#endif /*OS_HW_CORE_COMPILER_API_H_*/

/** @} */

