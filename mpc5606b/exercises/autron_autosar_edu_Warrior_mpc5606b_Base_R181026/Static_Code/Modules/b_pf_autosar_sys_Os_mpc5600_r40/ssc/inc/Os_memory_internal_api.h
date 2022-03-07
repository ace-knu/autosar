/**
*   @file    Os_memory_internal_api.h
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

#ifndef OS_MEMORY_INTERNAL_API_H_
#define OS_MEMORY_INTERNAL_API_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <Os_prop_autosar.h>

#include <Os_types_basic.h>     /* for OSDWORD */
#include <Os_types_common_internal.h>   /* for OSAPPLICATIONTYPE */

#include <Os_memory_types.h>    /* for RestartType */
#include <Os_memory_internal_types.h>

#if defined(OSMEMPROTECTION)


#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

OSDECLAREVAR (extern OSNEAR OSDWORD, OsStackDesc_);            /* address of MPU osstack descriptor per core */
OSDECLAREVAR (extern OSNEAR OSDWORD, OsRunableStackDesc_);     /* address of MPU runable stack descriptor per core */
#define OsRunableStackDesc OSUSEVAR(OsRunableStackDesc_)
#define OsStackDesc OSUSEVAR(OsStackDesc_)

    #if (OSNNOTTRUSTEDAPPS > 1U)
        OSDECLAREVAR (extern OSNEAR OSAPPLICATIONTYPE, OsLastApp_);     /* Last nontrusted application ID */
        #define OsLastApp OSUSEVAR(OsLastApp_)
    #endif

#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"


#endif /* defined(OSMEMPROTECTION) */


#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSMEMPROTECTION)

#if (OSNMEMDATA0 > 0U)
/* Array of application data section addresses (in RAM) */
extern OSMP_DSADDR_CB OsMPDataRAM[OSNNOTTRUSTEDAPPS];
#endif
#if (OSNMEMDATA1 > 0U)
extern OSMP_DSADDR_CB OsMPDataRAM_1[OSNNOTTRUSTEDAPPS];
#endif
#if (OSNMEMDATA2 > 0U)
extern OSMP_DSADDR_CB OsMPDataRAM_2[OSNNOTTRUSTEDAPPS];
#endif

/* Array of application peripheral section addresses (in RAM) */
#if defined(OSPERIPHERALS0)
extern OSMP_DSADDR_CB OsMPPeripheralRAM[OSNNOTTRUSTEDAPPS];
#endif
#if defined(OSPERIPHERALS1)
extern OSMP_DSADDR_CB OsMPPeripheralRAM_1[OSNNOTTRUSTEDAPPS];
#endif
#if defined(OSPERIPHERALS2)
extern OSMP_DSADDR_CB OsMPPeripheralRAM_2[OSNNOTTRUSTEDAPPS];
#endif

#endif /* defined(OSMEMPROTECTION) */

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSMEMPROTECTION)

#if (OSNTRUSTEDFUNCTIONS > 0U)

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_sections.h"

extern const OS_TRUSTED_FUNCTION OsTrustedFunctionsTable[OSNTRUSTEDFUNCTIONS];
extern const OSBYTE OsTrustedFunctionsAppId[OSNTRUSTEDFUNCTIONS];

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_sections.h"

#endif /* OSNTRUSTEDFUNCTIONS > 0 */

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

extern void OSInitMemProtection (void);


extern AccessType OSCheckWriteAccess (MemoryStartAddressType address, MemorySizeType size);



#define OSCHECKWRITEACCESS( address, size, ID, param )                     \
    if( OSCheckWriteAccess( (MemoryStartAddressType)(address), (size) ) == OSFALSE ) \
    {                                                                      \
       if( 0 == (address) )                                                \
       {                                                                   \
           OSRETERROR( E_OS_PARAM_POINTER, (ID), (param) );                \
       }                                                                   \
       OSRETERROR( E_OS_ILLEGAL_ADDRESS, (ID), (param) );                  \
    }

#if defined(OSIOC)
extern AccessType OSIOCCheckReadAccess (MemoryStartAddressType address, MemorySizeType size);

#define OSIOCCHECKWRITEACCESS( address, size )                             \
    if( OSCheckWriteAccess( (MemoryStartAddressType)(address), (size) ) == OSFALSE ) \
    {                                                                      \
       return IOC_E_NOK;                                                   \
    }

#define OSIOCCHECKREADACCESS( address, size )                                \
    if( OSIOCCheckReadAccess( (MemoryStartAddressType)(address), (size) ) == OSFALSE ) \
    {                                                                        \
       return IOC_E_NOK;                                                     \
    }
#endif /* defined(OSIOC) */


#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#if (OSNNOTTRUSTEDAPPS > 0U)

#define OS2UserMode() OSSETMSR(OSGETMSR() | OSMSR_PR )

#if defined(OSISRENTRYEXIT)
#define OS2UserModeEHI() OSMSYNC(); OSSETMSR(OsInitialMSR | OSMSR_PR )
#else
            /* Switch to user mode with interrupts enabled (set PR & EE bits) */
#define OS2UserModeEHI() OSMSYNC(); OSSETMSR(OSGETMSR() | OSMSR_EE | OSMSR_PR )
#endif

#else /* (OSNNOTTRUSTEDAPPS > 0U) */

#define OS2UserModeEHI( arg )

#endif /* (OSNNOTTRUSTEDAPPS > 0U) */

#else /* OSMEMPROTECTION */


#if defined(OSEXTSTATUS)

#define OSCHECKWRITEACCESS( address, size, ID, param )   \
    if( 0 == (address) )                                 \
    {                                                    \
        OSRETERROR( E_OS_PARAM_POINTER, (ID), (param) ); \
    }

#if defined(OSIOC)

#define OSIOCCHECKWRITEACCESS( address, size ) \
    if( 0 == (address) )                       \
    {                                          \
        return IOC_E_NOK;                      \
    }

#define OSIOCCHECKREADACCESS( address, size ) \
    if( 0 == (address) )                      \
    {                                         \
        return IOC_E_NOK;                     \
    }

#endif /* defined(OSIOC) */

#else /* defined(OSEXTSTATUS) */

#define OSCHECKWRITEACCESS( address, size, ID, param )

#if defined(OSIOC)

#define OSIOCCHECKWRITEACCESS( address, size )
#define OSIOCCHECKREADACCESS( address, size )

#endif

#endif /* defined(OSEXTSTATUS) */


#endif /* OSMEMPROTECTION */

#if defined(OSMEMPROTECTION)

#if (OSNNOTTRUSTEDAPPS > 0U)


/*****************************************************************************
* Function :   OSMP_DATA_DESC
* Description: Set MPU descriptor(s) for current application data(s)
*              and application peripheral region(s)
* Returns:     none
*****************************************************************************/
#define OSMP_DATA_DESC()                                        \
{                                                               \
    OSMP_DATA_0_DESC();                                         \
    OSMP_DATA_1_DESC();                                         \
    OSMP_DATA_2_DESC();                                         \
    OSMP_PER_0_DESC();                                          \
    OSMP_PER_1_DESC();                                          \
    OSMP_PER_2_DESC();                                          \
}

         /* Prepare MPU descriptor fields */
#define OSMP_PREP_DESC(mpdata, mpdataram, appId)                      \
{                                                                     \
    OSMP_DSADDR const *ds;                                            \
    OSMP_DSADDR_CB *dsram;                                            \
                                                                      \
    ds = & (mpdata) [(appId)];                                        \
    dsram = & (mpdataram) [(appId)];                                  \
                                                                      \
    dsram->startaddr = ds->startaddr;                                 \
    dsram->endaddr = ds->endaddr;                                     \
                                                                      \
    if( ds->startaddr < ds->endaddr ) /* data section is not empty */ \
    {                                                                 \
        if( (dsram->endaddr & (OSMPU_GRANULARITY-1U) ) == 0U ) /* end address is aligned by MPU granularity */ \
        {                                                             \
            dsram->endaddr--;                                         \
        }                                                             \
        dsram->valid = OSMPU_RGD_W3_VLD;                              \
    }                                                                 \
    else                                                              \
    {                                                                 \
        dsram->valid = 0U;                                            \
    }                                                                 \
}

#endif /* (OSNNOTTRUSTEDAPPS > 0U) */


/*  Enable/disable access to the whole section .osstack */
/* Set current runable stack MPU descriptor */
    #define OSSTACKDESC OsStackDesc

#define OSStackEnableAccess()  (OSMPU_RGD_ADDR( OSSTACKDESC, OSMPU_RGD_WORD3 ) = (OSMPU_RGD_W3_VLD))
#define OSStackDisableAccess() (OSMPU_RGD_ADDR( OSSTACKDESC, OSMPU_RGD_WORD3 ) = ((OSDWORD)0))

#if (OSNNOTTRUSTEDAPPS > 0U)

      /* Copy prepared MPU descriptor fields to HW */
#define _OSMP_DATA_DESC(mpdataram)                                       \
{                                                                        \
    OSMP_DSADDR_CB *dsram = &(mpdataram)[OSGetCurApp()];                 \
    /* Writes to either following words clears descriptor's valid bit */ \
    OSMPU_RGD_ADDR(dsram->descaddr,OSMPU_RGD_WORD0) = dsram->startaddr;  \
    OSMPU_RGD_ADDR(dsram->descaddr,OSMPU_RGD_WORD1) = dsram->endaddr;    \
    /* Restore descriptor's valid bit */                                 \
    OSMPU_RGD_ADDR(dsram->descaddr,OSMPU_RGD_WORD3) = dsram->valid;      \
}


#if (OSNMEMDATA0 > 0U)
#define OSMP_DATA_0_DESC() _OSMP_DATA_DESC(OsMPDataRAM)
#else
#define OSMP_DATA_0_DESC()
#endif

#if (OSNMEMDATA1 > 0U)
#define OSMP_DATA_1_DESC() _OSMP_DATA_DESC(OsMPDataRAM_1)
#else
#define OSMP_DATA_1_DESC()
#endif

#if (OSNMEMDATA2 > 0U)
#define OSMP_DATA_2_DESC() _OSMP_DATA_DESC(OsMPDataRAM_2)
#else
#define OSMP_DATA_2_DESC()
#endif

#if defined(OSPERIPHERALS0)
#define OSMP_PER_0_DESC()  _OSMP_DATA_DESC(OsMPPeripheralRAM)
#else
#define OSMP_PER_0_DESC()
#endif
#if defined(OSPERIPHERALS1)
#define OSMP_PER_1_DESC()  _OSMP_DATA_DESC(OsMPPeripheralRAM_1)
#else
#define OSMP_PER_1_DESC()
#endif
#if defined(OSPERIPHERALS2)
#define OSMP_PER_2_DESC()  _OSMP_DATA_DESC(OsMPPeripheralRAM_2)
#else
#define OSMP_PER_2_DESC()
#endif

    #define OSMP_PER_0_DESC_CLOSE()
    #define OSMP_PER_1_DESC_CLOSE()
    #define OSMP_PER_2_DESC_CLOSE()

#else /* (OSNNOTTRUSTEDAPPS > 0U) */

#define OSMP_DATA_DESC()

#endif /* (OSNNOTTRUSTEDAPPS > 0U) */

/* Set current runable stack MPU descriptor */
    #define OSRUNABLESTACKDESC OsRunableStackDesc

#define OSMP_STACK_DESC(stackbos, stacktos)                                     \
{                                                                               \
    /* Writes to either of the following words clears descriptor's valid bit */ \
    OSMPU_RGD_ADDR(OSRUNABLESTACKDESC, OSMPU_RGD_WORD0) = (stackbos);           \
    OSMPU_RGD_ADDR(OSRUNABLESTACKDESC, OSMPU_RGD_WORD1) = (stacktos); /* NB! stacktos = cfg->stacktos - OSSTKADDS, */ \
    /*     -> -1 it's not necessary */                                          \
    /* Restore descriptor's valid bit */                                        \
    OSMPU_RGD_ADDR(OSRUNABLESTACKDESC, OSMPU_RGD_WORD3) = OSMPU_RGD_W3_VLD;     \
    OSStackDisableAccess();                                                     \
}

#if (OSNNOTTRUSTEDAPPS > 1U)
/* There is more than one nontrusted OS-application */
#define OSMPSWITCH /* It's necessary to switch MP before runable switching */
#endif


#if defined(OSMPSWITCH)

#define OSMP_APP_OPEN_DATA()                                               \
if( OsLastApp != OSGetCurApp() )                                           \
{                                                                          \
    OSMP_DATA_DESC(); /* Turn on MPU descripror for OS-application data */ \
    OsLastApp = (OSAPPLICATIONTYPE)OSGetCurApp();                                             \
}


      /* Prepare MPU for nontrusted OS-application */
#define OSMP_NONTRUSTEDAPP_OPEN_DATA()                                             \
    if( OSMP_IS_NONTRUSTEDAPP(OSGetCurApp()) ) /* OS-application is non-trusted */ \
    {                                                                              \
        OSMP_APP_OPEN_DATA();                                                      \
    }
#else
#define OSMP_APP_OPEN_DATA()
#define OSMP_NONTRUSTEDAPP_OPEN_DATA()
#endif /* defined(OSMPSWITCH) */


      /* Prepare MPU for TASK stack */
#define OSMP_TASK_OPEN_STACK() \
    OSMP_STACK_DESC((OSDWORD)OsRunning->bos, (OSDWORD)OsRunning->tos)

#if !defined(OSNOISR2)
/* Prepare MPU for ISR2 stack */
#define OSMP_ISR2_OPEN_STACK(isr)   OSMP_STACK_DESC((OSDWORD)(isr)->isrBos, (OSDWORD)(isr)->stackPtr)
#endif



#endif  /* defined(OSMEMPROTECTION) */

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

/* Prototypes of core exception handlers */
extern void OSExceptionError( OSDWORD srr0, OSDWORD srr1 );
extern void OSMCExceptionError( OSDWORD mcsrr0, OSDWORD mcsrr1 );

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /*OS_MEMORY_INTERNAL_API_H_ */

/** @} */
