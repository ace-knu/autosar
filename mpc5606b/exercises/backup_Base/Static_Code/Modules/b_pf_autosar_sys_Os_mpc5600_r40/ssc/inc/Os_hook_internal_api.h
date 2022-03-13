/**
*   @file    Os_hook_internal_api.h
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

#ifndef OS_HOOK_INTERNAL_API_H_
#define OS_HOOK_INTERNAL_API_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_hook_api.h>

#include <Os_orti_internal_api.h>

/* Start of hooks code section */
#define OSHOOK_START_SEC_CODE
#include "Os_memmap.h"

#if defined(OSHOOKPROTECTION) 
    #if !defined(OSSC1)
        #define OSSETPROTCNXT() (OsIsrLevel = (OsIsrLevel & OSISRLEVELTASKMASK) | OSISRLEVELHOOKPROTECTION)
        #define OSCLRPROTCNTX() (OsIsrLevel =  OsIsrLevel & OSISRLEVELTASKMASK)
    #endif          /* !defined(OSSC1) */
#endif            /* defined(OSHOOKPROTECTION)  */

#if defined(OSHOOKPRETASK)

#if defined(OSISRENTRYEXIT) || defined(OSCHECKCONTEXT)
/******************************************************************************
* Macro:       OSPreTaskHook
* Description: call User hook, setting special level
* Returns:
* Notes:       OsSuspendLevel shall be equal to 0, interrupts disabled
******************************************************************************/
#define OSCallPreTaskHook( )                                \
    OsIsrLevel |= OSISRLEVELHOOKPRETASK;                    \
    OSOrtiSetServiceWatch( OSServiceId_PreTaskHook );       \
    PreTaskHook();                                          \
    OSOrtiServiceWatchOnExit( OSServiceId_PreTaskHook );    \
    OsIsrLevel &= (OSISRLEVELTYPE)(~OSISRLEVELHOOKPRETASK)
#else  /* if defined(OSISRENTRYEXIT) || defined(OSCONTEXTCHECK) */
#define OSCallPreTaskHook( ) \
    OSOrtiSetServiceWatch( OSServiceId_PreTaskHook );       \
    PreTaskHook();                                          \
    OSOrtiServiceWatchOnExit( OSServiceId_PreTaskHook )
#endif /* if defined(OSISRENTRYEXIT) || defined(OSCONTEXTCHECK) */

#define OSPreTaskHook( ) \
    if( OSHASRUNNINGTASK )    \
    {                         \
        OSCallPreTaskHook( ); \
    }

#else            /* defined(OSHOOKPRETASK) */

#define OSCallPreTaskHook()
#define OSPreTaskHook()

#endif            /* defined(OSHOOKPRETASK) */

#if defined(OSHOOKPOSTTASK)

#if defined(OSISRENTRYEXIT) || defined(OSCHECKCONTEXT)
/******************************************************************************
* Macro:       OSPostTaskHook
* Description:
* Returns:
* Notes:       OsSuspendLevel shall be equal to 0, interrupts disabled
******************************************************************************/
#define OSPostTaskHook( ) \
    OsIsrLevel |= OSISRLEVELHOOKPOSTTASK;                    /* set special ISR level                           */ \
    OSOrtiSetServiceWatch( OSServiceId_PostTaskHook );       /* set watch to this service                       */ \
    PostTaskHook();                                                                                                \
    OSOrtiServiceWatchOnExit( OSServiceId_PostTaskHook );    /* clean service watch on hook leaving             */ \
    OsIsrLevel &= (OSISRLEVELTYPE)(~OSISRLEVELHOOKPOSTTASK); /* reset special ISR level                         */
#else  /* if defined(OSISRENTRYEXIT) || defined(OSCONTEXTCHECK) */
#define OSPostTaskHook() \
    OSOrtiSetServiceWatch( OSServiceId_PostTaskHook );       /* set watch to this service                       */ \
    PostTaskHook();                                                                                                \
    OSOrtiServiceWatchOnExit( OSServiceId_PostTaskHook );    /* clean service watch on hook leaving             */
#endif /* if defined(OSISRENTRYEXIT) || defined(OSCONTEXTCHECK) */

#else            /* defined(OSHOOKPOSTTASK) */
#define OSPostTaskHook( )
#endif            /* defined(OSHOOKPOSTTASK) */

#define OSHOOK_STOP_SEC_CODE
#include "Os_memmap.h"

#ifdef __cplusplus
}
#endif

#endif /*OS_HOOK_INTERNAL_API_H_*/

/** @} */

