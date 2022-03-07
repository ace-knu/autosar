/**
*   @file    Os_isr_api.h
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

#ifndef OS_ISR_API_H
#define OS_ISR_API_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <Os_prop_autosar_api.h>
#include <Os_memory_api.h>        /**< for OSServiceCallX defines */
#include <Os_types_basic.h>       /**< for OSDECLAREVAR and OSUSEVAR */

/*
 * ISRs definitions
 */
#define ISR(IsrName)        void OS_isr_##IsrName( void )

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

extern void OS_DisableAllInterrupts (void);
extern void OS_EnableAllInterrupts (void);
extern void OS_SuspendAllInterrupts (void);
extern void OS_ResumeAllInterrupts (void);


OSINLINE void
OSStarted_DisableAllInterrupts (void)
{
    #if defined(OSMEMPROTECTION)
    OSServiceCall0VEE (DisableAllInterrupts);
    #else
    OS_DisableAllInterrupts ();
    #endif
}

OSINLINE void
OSStarted_EnableAllInterrupts (void)
{
    #if defined(OSMEMPROTECTION)
    OSServiceCall0VEE (EnableAllInterrupts);
    #else
    OS_EnableAllInterrupts ();
    #endif
}

OSINLINE void
OSStarted_SuspendAllInterrupts (void)
{
    #if defined(OSMEMPROTECTION)
    OSServiceCall0VEE (SuspendAllInterrupts);
    #else
    OS_SuspendAllInterrupts ();
    #endif
}

OSINLINE void
OSStarted_ResumeAllInterrupts (void)
{
    #if defined(OSMEMPROTECTION)
    OSServiceCall0VEE (ResumeAllInterrupts);
    #else
    OS_ResumeAllInterrupts ();
    #endif
}

OSINLINE void
OSNoStarted_DisableAllInterrupts (void)
{
    OS_DisableAllInterrupts ();
}

OSINLINE void
OSNoStarted_EnableAllInterrupts (void)
{
    OS_EnableAllInterrupts ();
}

OSINLINE void
OSNoStarted_SuspendAllInterrupts (void)
{
    OS_SuspendAllInterrupts ();
}

OSINLINE void
OSNoStarted_ResumeAllInterrupts (void)
{
    OS_ResumeAllInterrupts ();
}

#if defined(OSMEMPROTECTION)

OSINLINE void
DisableAllInterrupts (void)
{
    if (!OsStarted)             /* OS299 */
    {
        OSNoStarted_DisableAllInterrupts ();
    }
    else
    {
        OSServiceCall0VEE (DisableAllInterrupts);
    }
}

OSINLINE void
EnableAllInterrupts (void)
{
    if (!OsStarted)             /* OS299 */
    {
        OSNoStarted_EnableAllInterrupts ();
    }
    else
    {
        OSServiceCall0VEE (EnableAllInterrupts);
    }
}

OSINLINE void
SuspendAllInterrupts (void)
{
    if (!OsStarted)             /* OS299 */
    {
        OSNoStarted_SuspendAllInterrupts ();
    }
    else
    {
        OSServiceCall0VEE (SuspendAllInterrupts);
    }
}

OSINLINE void
ResumeAllInterrupts (void)
{
    if (!OsStarted)             /* OS299 */
    {
        OSNoStarted_ResumeAllInterrupts ();
    }
    else
    {
        OSServiceCall0VEE (ResumeAllInterrupts);
    }
}

#else /* defined(OSMEMPROTECTION) */

OSINLINE void
DisableAllInterrupts (void)
{
    {
        OS_DisableAllInterrupts ();
    }
}

OSINLINE void
EnableAllInterrupts (void)
{
    {
        OS_EnableAllInterrupts ();
    }
}

OSINLINE void
SuspendAllInterrupts (void)
{
    {
        OS_SuspendAllInterrupts ();
    }
}

OSINLINE void
ResumeAllInterrupts (void)
{
    {
        OS_ResumeAllInterrupts ();
    }
}

#endif /* defined(OSMEMPROTECTION) */

#define OSINVALID_ISR  OSNISR

#define INVALID_ISR OS_MKOBJID(OBJECT_ISR, OSINVALID_ISR)

#if defined(OSISRENTRYEXIT)

extern void OS_ResumeOSInterrupts (void);
extern void OS_SuspendOSInterrupts (void);
extern ISRType OS_GetISRID (void);

        /*  Public OS Services  */
#if defined(OSMEMPROTECTION)

OSINLINE void
ResumeOSInterrupts (void)
{
    OSServiceCall0V (ResumeOSInterrupts);
}

OSINLINE void
SuspendOSInterrupts (void)
{
    OSServiceCall0V (SuspendOSInterrupts);
}

OSINLINE ISRType
GetISRID (void)
{
    OSServiceCall0 (ISRType, GetISRID);
}

#else /* defined(OSMEMPROTECTION) */

#define ResumeOSInterrupts( )  OS_ResumeOSInterrupts( )
#define SuspendOSInterrupts( ) OS_SuspendOSInterrupts( )
#define GetISRID( )            OS_GetISRID( )

#endif /* defined(OSMEMPROTECTION) */

#else /* defined(OSISRENTRYEXIT) */

#define ResumeOSInterrupts( )
#define SuspendOSInterrupts( )
#define GetISRID( )            INVALID_ISR

#endif /* defined(OSISRENTRYEXIT) */

#if (OSNISR > 0U)

#define DeclareISR(ISR)  extern OSBYTE osdummy

extern StatusType OS_EnableInterruptSource (ISRType enableIsr);
extern StatusType OS_DisableInterruptSource (ISRType disableIsr);

#if defined(OSMEMPROTECTION)
OSINLINE StatusType
EnableInterruptSource (ISRType enableISR)
{
    OSServiceCall1 (StatusType, enableISR, EnableInterruptSource);
}

OSINLINE StatusType
DisableInterruptSource (ISRType disableISR)
{
    OSServiceCall1 (StatusType, disableISR, DisableInterruptSource);
}
#else
#define EnableInterruptSource(enableISR)  OS_EnableInterruptSource(enableISR)
#define DisableInterruptSource(enableISR) OS_DisableInterruptSource(enableISR)
#endif

#endif /* OSNISR > 0U */

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"



#ifdef __cplusplus
}
#endif /* __cplusplus */



#endif /*OS_ISR_API_H */

/** @} */
