/**
*   @file    Os_memory_api.h
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

#ifndef OS_MEMORY_API_H_
#define OS_MEMORY_API_H_

#ifdef __cplusplus
extern "C"
{
#endif            /* __cplusplus */

#include <Os_prop_autosar_api.h>
#include <Os_types_basic.h>
#include <Os_hw_core_compiler_api.h>

#if defined(OSMEMPROTECTION) || defined(OSHOOKPROTECTION) || (defined(OSMULTICORE) && defined(OSSBSSCOPY))

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

extern OSBYTE OsStarted;    /* Boolean variable, it shall be OSFALSE (0) before StartOS() call  */

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#endif /* defined(OSMEMPROTECTION) || defined(OSHOOKPROTECTION) || (defined(OSMULTICORE) && defined(OSSBSSCOPY)) */

#if defined(OSMEMPROTECTION)

/* Application data section addresses for various compilers (sysgen uses these macros too) */
#if defined(OSCWPPC)
#define OSMP_BEGIN_DSAPPL(DSNAME) _f_##DSNAME
#define OSMP_END_DSAPPL(DSNAME)   _e_##DSNAME
#endif

#if defined(OSGHSPPC)
#define OSMP_BEGIN_DSAPPL(DSNAME) __ghsbegin_##DSNAME##_data
#define OSMP_END_DSAPPL(DSNAME)   __ghsend_##DSNAME##_bss
#endif

#if defined(OSDIABPPC)
#define OSMP_BEGIN_DSAPPL(DSNAME) _f_##DSNAME
#define OSMP_END_DSAPPL(DSNAME)   _e_##DSNAME
#endif

#endif


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"


#if defined(OSMEMPROTECTION)

#define OSMP_IS_TRUSTEDAPP(appIndex) ( (appIndex) >= (OSAPPLICATIONTYPE)OSNNOTTRUSTEDAPPS )
#define OSMP_IS_NONTRUSTEDAPP(appIndex) ( (appIndex) < (OSAPPLICATIONTYPE)OSNNOTTRUSTEDAPPS )

#define OSServiceMSYNC()


/*
 * implemented in Os_hw_core.c
 */
extern OSDWORD OS2SystemMode( void );
extern void OSTLBException( OSDWORD srr0, OSDWORD srr1 );

#if (OSNNOTTRUSTEDAPPS == 0U)
    #define OSEnterServiceV()                            OSServiceMSYNC()
    #define OSLeaveServiceV()
    #define OSEnterService(type)                         { type ret; OSServiceMSYNC(); ret = 
    #define OSLeaveService()                             return ret; }
    #define OSLeaveServiceVEE()
#else /* (OSNNOTTRUSTEDAPPS == 0U) */
    #define OSEnterServiceV()                            { OSDWORD oldMSR = OS2SystemMode();
    #define OSLeaveServiceV()                            OSSETMSR(oldMSR); OSMSYNC(); }
    #define OSEnterService(type)                         { type ret; OSDWORD oldMSR = OS2SystemMode(); ret = 
    #define OSLeaveService()                             OSSETMSR(oldMSR); OSMSYNC(); return ret; }
    #define OSLeaveServiceVEE()                          OSSETMSR( (oldMSR & 0xFFFF7FFF) | (OSGETMSR() & 0x00008000) ); OSMSYNC(); }
#endif /* (OSNNOTTRUSTEDAPPS == 0U) */ 

#define OSServiceCall0V(name)                        OSEnterServiceV() OS_##name(); OSLeaveServiceV()
#define OSServiceCall1V(arg, name)                   OSEnterServiceV() OS_##name(arg); OSLeaveServiceV()
#define OSServiceCall2V(arg1, arg2, name)            OSEnterServiceV() OS_##name((arg1), (arg2)); OSLeaveServiceV()
#define OSServiceCall0(type, name)                   OSEnterService(type) OS_##name(); OSLeaveService()
#define OSServiceCall1(type, arg, name)              OSEnterService(type) OS_##name(arg); OSLeaveService()
#define OSServiceCall2(type, arg1, arg2, name)       OSEnterService(type) OS_##name((arg1), (arg2)); OSLeaveService()
#define OSServiceCall3(type, arg1, arg2, arg3, name) OSEnterService(type) OS_##name((arg1), (arg2), (arg3)); OSLeaveService()
#define OSServiceCall0VEE(name)                      OSEnterServiceV() OS_##name(); OSLeaveServiceVEE()

#endif /* end if defined(OSMEMPROTECTION) */

/*
* API in this file
*
* OSMEMORY_IS_READABLE(x)
* OSMEMORY_IS_WRITEABLE(x)
* OSMEMORY_IS_EXECUTABLE(x)
* OSMEMORY_IS_STACKSPACE(x)
*
* only available if OSMEMPROTECTION is on
* CallTrustedFunction
* CheckISRMemoryAccess
* CheckTaskMemoryAccess
*
*/


/*  part of Autosar OS public API
 *
 * These macros return a value not equal to zero if the memory is
 * readable / writable / executable or stack space
*/
#define OSMEMORY_IS_READABLE(x)   ( ((x) & OSMP_R) != 0U )
#define OSMEMORY_IS_WRITEABLE(x)  ( ((x) & OSMP_W) != 0U )
#define OSMEMORY_IS_EXECUTABLE(x) ( ((x) & OSMP_E) != 0U )
#define OSMEMORY_IS_STACKSPACE(x) ( ((x) & OSMP_S) != 0U )

#if defined(OSMEMPROTECTION)

#if (OSNTRUSTEDFUNCTIONS > 0U)
extern StatusType OS_CallTrustedFunction (TrustedFunctionIndexType ix, TrustedFunctionParameterRefType ptr);
#endif

#if !defined(OSNOISR2)
extern AccessType OS_CheckISRMemoryAccess (ISRType handlerId, MemoryStartAddressType address, MemorySizeType size);
#endif

extern AccessType OS_CheckTaskMemoryAccess (TaskType handlerId, MemoryStartAddressType address, MemorySizeType size);

/*
 *  the Memory public API
 */

#if (OSNTRUSTEDFUNCTIONS > 0U)
OSINLINE StatusType 
CallTrustedFunction (TrustedFunctionIndexType ix, TrustedFunctionParameterRefType ptr)
{
    OSServiceCall2 (StatusType, ix, ptr, CallTrustedFunction);
}
#endif

#if !defined(OSNOISR2)
OSINLINE AccessType 
CheckISRMemoryAccess (ISRType handlerId, MemoryStartAddressType address, MemorySizeType size)
{
    OSServiceCall3 (AccessType, handlerId, address, size, CheckISRMemoryAccess);
}
#endif

OSINLINE AccessType 
CheckTaskMemoryAccess (TaskType taskId, MemoryStartAddressType address, MemorySizeType size)
{
    OSServiceCall3 (AccessType, taskId, address, size, CheckTaskMemoryAccess);
}

#endif /* defined(OSMEMPROTECTION) */

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif



#endif /*OS_MEMORY_API_H_*/

/** @} */

