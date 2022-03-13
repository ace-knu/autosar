/**
*   @file    Os_isr_internal_api.h
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

#ifndef OS_ISR_INTERNAL_API_H_
#define OS_ISR_INTERNAL_API_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>
#include <Os_isr_internal_types.h>

#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSISRENTRYEXIT) && defined (OSHOOKERROR_EXT)
OSDECLAREVAR (extern OSNEAR OSDWORD, OsIntCheck_);      /* check correct order of the nested Suspend/Resume pairs */
#define OsIntCheck OSUSEVAR(OsIntCheck_)
#endif

#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"


#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"


      /* single core */

#if defined(OSTIMINGPROTECTION)
#define OSNIPLSP  (OSNIPLS+1U)
#else
#define OSNIPLSP  OSNIPLS
#endif

#if (OSNIPLSP > 0U)
#if defined(OSTERMINATION)
extern OSJMP_BUF OsISRbufs[OSNIPLSP];
#endif
extern OS_ISRTYPEPTR OsIsrArray[OSNIPLSP];      /* its index is OsIsrLevel */
#endif /* OSNIPLSP > 0U */


#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"


#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"


OSDECLAREVAR (extern OSNEAR OSDWORD, OsOldMsr_);              /* Saved MSR for EnableAll/DisableAllInterrupts */
#define OsOldMsr OSUSEVAR(OsOldMsr_)

OSDECLAREVAR (extern OSNEAR OSBYTE, OsSuspendLevelAll_);      /* level of the nested Suspend/ResumeAll pairs */
#define OsSuspendLevelAll OSUSEVAR(OsSuspendLevelAll_)

OSDECLAREVAR (extern OSNEAR OSINTMASKTYPE, OsOldIntMaskAll_); /* SuspendAll/ResumeAllInterrupts services */
#define OsOldIntMaskAll OSUSEVAR(OsOldIntMaskAll_)

OSDECLAREVAR (extern OSNEAR OSINTMASKTYPE, OsOldInterruptMask_);        /* Saved interrupt mask for SuspendOS/ResumeOSInterrupts services and for Hooks */
#define OsOldInterruptMask OSUSEVAR(OsOldInterruptMask_)

#if defined(OSISRENTRYEXIT)
OSDECLAREVAR (extern OSNEAR OSBYTE, OsSuspendLevel_);   /* level of the nested Suspend/Resume pairs */
#define OsSuspendLevel OSUSEVAR(OsSuspendLevel_)
#endif /* defined(OSISRENTRYEXIT) */

#if defined(OSUSEISRLEVEL)

OSDECLAREVAR (extern OSNEAR OSISRLEVELTYPE, OsIsrLevel_);  /* num of active ISRs & context bits */
#define OsIsrLevel OSUSEVAR(OsIsrLevel_)

#if defined(OSISRENTRYEXIT) || !defined(OSSC1)
OSDECLAREVAR (extern OSNEAR OSDWORD, OsInitialMSR_);    /* saved initial MSR */
#define OsInitialMSR OSUSEVAR(OsInitialMSR_)
#endif

#endif /* defined(OSUSEISRLEVEL) */


#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#if (OSNISR > 0U)
extern OS_ISRTYPE OsIsrTable[OSNISR + 1U];       /* ISR table */
#endif

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSUSEISRSTACK)

#if defined(OSSC2) && !defined(OSISRSTACKSIZE)
#define OSISRSTACKSIZE       64U /* 256 bytes for TP interrupts */
#endif

    /* below when !defined(OSMULTICORE) */
    #define OSISRSTKEND OsISRStack
    #define OSISRTOS    (OSISRSTKEND + OSISRSTACKSIZE)


#define OSSTACK_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"
/* ISR stack (for master core) */
extern OSDWORD OsISRStack[OSISRSTACKSIZE];
#define OSSTACK_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#endif /* defined(OSUSEISRSTACK) */

/* Macros to clear context  */
#if defined(OSISRENTRYEXIT)
#define OSCLEARCNTXANDLEVELS( ) \
        OsIsrLevel = 0U; /* clear context */ \
        OsSuspendLevel = 0U; /* clear SuspendOSInterrupts() calls counter */  \
        OsSuspendLevelAll = 0U;  /* clear SuspendAllInterrupts() calls counter */
#else
#define OSCLEARCNTXANDLEVELS( ) \
        OSCLEARCNTX(); /* clear context */ \
        OsSuspendLevelAll = 0U;  /* clear SuspendAllInterrupts() calls counter */
#endif

/* Macros to clear suspend levels  */
#if defined(OSISRENTRYEXIT)
#define OSCLEARSUSPENDLEVELS( ) \
        OsSuspendLevelAll = 0U; \
        OsSuspendLevel = 0U;
#else
#define OSCLEARSUSPENDLEVELS( ) \
        OsSuspendLevelAll = 0U;
#endif


/* ISR Management Mode Configuration */

#if !defined(OSHIGHINTPRIO)
    #if defined(OSTIMINGPROTECTION)
    #define OSHIGHINTPRIO OSHIGHTPISRPRIO
    #else
    #define OSHIGHINTPRIO OSHIGHISRPRIO
    #endif
#endif /* !defined(OSHIGHINTISRPRIO) */


#define OSHOOK_START_SEC_CODE
#include "Os_memmap.h"

#if defined(OSISRHOOKS)
extern void PreIsrHook (void);
extern void PostIsrHook (void);
#define OSPreIsrHook( )   PreIsrHook()
#define OSPostIsrHook( )  PostIsrHook()
#else
#define OSPreIsrHook( )
#define OSPostIsrHook( )
#endif

#define OSHOOK_STOP_SEC_CODE
#include "Os_memmap.h"

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

    /* OS internal functions */
extern void OSInitializeISR (void);

#if defined(OSAPPLICATION)
#if defined(OSKILLAPPISRS)
extern void OSKillAppISRs (OSAPPLICATIONTYPE appId);
#endif
#endif


    #if defined(OSMEMPROTECTION)
        #if (OSNTRUSTEDFUNCTIONS > 0U)
        #if (OSNUSERISR > 0U)
        extern void OSDisableISRs4App (OSAPPLICATIONTYPE appId);
        extern void OSEnableISRs4App (OSAPPLICATIONTYPE appId);
        #endif
        #endif /* (OSNTRUSTEDFUNCTIONS > 0U) */
    #endif /* defined(OSMEMPROTECTION) */
    

#if defined(OSTIMINGPROTECTION)
#if defined(OSHOOKPROTECTION)
extern void OSTPLeaveISR (void);
#endif
#endif /* defined(OSTIMINGPROTECTION) */

#if defined(OSRESOURCEISR)
extern void OSReleaseISRResource (OS_ISRTYPEPTR handlerPtr);
#endif

#if (OSNISR > 0U)
    #if defined(OSTERMINATION)
    #if !defined(OSNOISR2)
    extern void OSKillISR (OS_ISRTYPEPTR isrToKill);
    extern void OSKillRunningISR (void);
    #endif
    #endif /* defined(OSTERMINATION) */
#endif /* OSNISR > 0U */


#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#if (OSNISR > 0U)

#define  OSDisableISRSource(isrPtr) OSCLEAR_INT_PSRX((isrPtr)->index)
#define  OSEnableISRSource(isrPtr)  OSSET_INT_PSRX((isrPtr)->index, (isrPtr)->isrPrio)

#endif /* OSNISR > 0U */

#if defined(OSSC1) && !defined(OSISRENTRYEXIT)
#define OSSETTASKMSR()  OSEHI()
#else
#define OSSETTASKMSR()  OSMSYNC(); OSSETMSR(OsInitialMSR)       /* set MSR for Task */
#endif

     /* Macros for INTC IPL manipulations, to be called with all interrupts disabled */
#define OSISRSetPrio(prio) (OSINTC_CPR = (prio)) /* Set current ISR prio to the highest OS ISR prio */
#define OSISRGetPrio()     OSINTC_CPR            /* Get current ISR prio */

     /* Unmasks all interrupts */
#define OSISRALLON() OSMSYNC(); OSISRSetPrio(0U)

#if !defined(OSISRENTRYEXIT) && !defined(OSTIMINGPROTECTION)
      /* If there are no ISR configured Disable/Enable interrupts macros are empty */
#define OSIMSAVE
#define OSDIS( save )
#define OSRI( save )
#define OSDI()
#define OSEI()

#else /* !defined(OSISRENTRYEXIT) && !defined(OSTIMINGPROTECTION) */

        /* defines the "save" local variables for current interrupts state saving */
        /* ; shall be in the definition to avoid it inside local variables declaration */
#define OSIMSAVE  OSINTMASKTYPE save;

        /* Enable all interrupts in INTC */
#define OSEI()    OSISRALLON()

  /* Disable all interrupts (for Multilevel interrupts - all */
  /*             interrupts of cat.2 and interrupt of TP Timer) */
  /* Notes: State of interrupts is saved into the "save" local variables */
#define OSDI()  OSISRSetPrio(OSHIGHINTPRIO); OSMSYNC()

  /* OSDIS saves current SIMASK in the local variable and */
  /* disables all interrupts of the category 2 and Timers interrupts */
#define OSDIS( save )            \
    (save) = OSISRGetPrio();     \
    if( (save) < OSHIGHINTPRIO ) \
    {                            \
        OSDI();                  \
    }


  /* Restore interrupts state from the "save" local variables */
  /* Notes: enables external interrupts */
#define OSRI( save )    OSMSYNC(); OSISRSetPrio(save)

#endif /* !defined(OSISRENTRYEXIT) && !defined(OSTIMINGPROTECTION) */



#if !defined(OSNOISR)
/* End Of Interrupt, restore IPL */
#define OSEOIR()        (OSINTC_EOIR = 0U)
#endif



/* FIT and DEC interrupts are redirected to Software settable interrupts 6 and 7 */
#define OSSIFIT 6U
#define OSSIDEC 7U
#define OSFITSOFTINVOKE 0x0200U
#define OSDECSOFTINVOKE 0x2U



#if defined(OSISRENTRYEXIT) && defined(OSORTIRUNNINGISRID)
    /* ORTI support for tracing ISR */

    /* macro for setting ISR Id for ORTI */
        #define OSOrtiSetISRId(ISRId)(OSISRId = (OSWORD)(ISRId))

#else /* defined(OSISRENTRYEXIT) && defined(OSORTIRUNNINGISRID) */
    #define OSOrtiSetISRId(ISRId)
#endif /* defined(OSISRENTRYEXIT) && defined(OSORTIRUNNINGISRID) */



/******************************* Constants ********************************/

#define OSISRLEVELMASK               ((OSISRLEVELTYPE)0x0000001FUL)

#if defined(OSUSEISRLEVEL)

    #define OSISRLEVELTASK               ((OSISRLEVELTYPE)0x80000000UL)       /* ISR resource bit allowed for Task */
    #define OSISRLEVELDISABLEDINT        ((OSISRLEVELTYPE)0x40000000UL)
    #define OSISRLEVELDISABLEDINTOS      ((OSISRLEVELTYPE)0x20000000UL)
    #define OSISRLEVELDISABLEDINTALL     ((OSISRLEVELTYPE)0x10000000UL)
    #define OSISRLEVELDISABLEDINTERRUPTS ((OSISRLEVELTYPE)0x70000000UL)
    #define OSISRLEVELHOOKSTARTUP        ((OSISRLEVELTYPE)0x04000000UL)
    #define OSISRLEVELHOOKSHUTDOWN       ((OSISRLEVELTYPE)0x02000000UL)
    #define OSISRLEVELHOOKPRETASK        ((OSISRLEVELTYPE)0x01000000UL)
    #define OSISRLEVELHOOKPOSTTASK       ((OSISRLEVELTYPE)0x00800000UL)
    #define OSISRLEVELHOOKTASK           ((OSISRLEVELTYPE)0x01800000UL)
    #define OSISRLEVELHOOKERROR          ((OSISRLEVELTYPE)0x00400000UL)
    #define OSISRLEVELHOOKPROTECTION     ((OSISRLEVELTYPE)0x00200000UL)
    #define OSISRLEVELHOOKCOM            ((OSISRLEVELTYPE)0x00100000UL)
    #define OSISRLEVELHOOKANYSYSTEM      ((OSISRLEVELTYPE)0x07F00000UL)
    #define OSISRLEVELALMCALLBACK        ((OSISRLEVELTYPE)0x00080000UL)
    #define OSISRLEVELHOOKAPPERROR       ((OSISRLEVELTYPE)0x00040000UL)
    #define OSISRLEVELISR1               ((OSISRLEVELTYPE)0x00020000UL)
    #define OSISRLEVELHOOKAPPSTARTUP     ((OSISRLEVELTYPE)0x00008000UL)
    #define OSISRLEVELHOOKAPPSHUTDOWN    ((OSISRLEVELTYPE)0x00004000UL)
    #define OSISRLEVELHOOKANY            ((OSISRLEVELTYPE)0x07F4C000UL)
    #define OSISRLEVELTASKMASK           ((OSISRLEVELTYPE)0x8000001FUL)

    #define OSIsrLevelCheck(mask) ((OsIsrLevel & (~(mask))) != (OSISRLEVELTYPE)(0UL))
    #define OSCLEARCNTX() (OsIsrLevel &= OSISRLEVELTASKMASK)

#else /* defined(OSUSEISRLEVEL) */

    #define OSCLEARCNTX()
#endif /* defined(OSUSEISRLEVEL) */


#if (OSNISR > 0U)

#if defined(OSUSEISRSTACK)
    #define OSSWITCH2STACK_TASK()   OSRestoreSP()
    #define OSSWITCH2STACK_ISR()    OSLoadISRSP(OSISRTOS)
    #if defined(OSSYSSTKCHECK)
        #define OSCHECKISRSTACK()    OSSTKINVALID(OSISRSTKEND)  /* for SC2 or ECC1 */
    #endif
#else
    #if defined(OSSYSSTKCHECK)
    #if defined(OSMEMPROTECTION)
        #define OSCHECKISRSTACK()    OSSTKINVALID(handlerPtr->isrBos)       /* for SC3,4 */
    #else
        #define OSCHECKISRSTACK()    OSSTKINVALID(OSSTACKBOTTOM)        /* for BCC1 and SC1 */
    #endif
    #endif /* defined(OSSYSSTKCHECK) */
#endif /* defined(OSUSEISRSTACK) */


#if defined(OSSYSSTKCHECK)
    #if defined(OSMEMPROTECTION)
        #define OSISRSTKRESTOREPAD(bos) OSSTKSETGUARD( bos )    /* for SC3..4 */
    #elif defined(OSUSEISRSTACK)
        #define OSISRSTKRESTOREPAD(arg) OSSTKSETGUARD( OSISRSTKEND )    /* for SC2 or ECC1, SC1 */
    #else
        #define OSISRSTKRESTOREPAD(arg) OSSTKSETGUARD( OSSTACKBOTTOM )  /* for BCC1, SC1 */
    #endif /* defined(OSMEMPROTECTION) */
#else
    #define OSISRSTKRESTOREPAD(arg)
#endif /* defined(OSSYSSTKCHECK) */


#if defined(OSISRENTRYEXIT)

#if defined(OSSC1)

#if defined(OSBCC)
    #define OSSWITCH2STACK_ISR()    OSCheckStack()  /* check main stack overflow */
    #define OSSWITCH2STACK_TASK()   OSCheckStack()
#endif /* defined(OSBCC) */

#endif /* defined(OSSC1) */

/***************************************************************************
 * Macro:       OSSystemEnterISR2
 *
 * Description: switch stack if needed, enable interrupts
 *
 * Notes:       for SC1..4
 *
**************************************************************************/
#define OSSystemEnterISR2() \
    OsIsrLevel++;           \
    OSPreIsrHook( );        \
    OSEHI()

/***************************************************************************
 * Macro:       OSSystemLeaveISR2
 *
 * Description: Leave ISR - switch stack if required
 *
 * Notes:       for SC1..4
 *
 **************************************************************************/
#define OSSystemLeaveISR2( ) \
    OSDHI( );                \
    OSPostIsrHook( );        \
    OsIsrLevel--

#endif /* defined(OSISRENTRYEXIT) */

#endif /* (OSNISR > 0U) */
/***************************** internal macros ****************************/

#if defined(OSISRENTRYEXIT)


/*
 * OSSuspend/OSResumeInterrupts macros are used in OSErrorHooks only
 */

/***************************************************************************
 * Macro:       OSSuspendInterrupts
 * Description: save interrupt mask and disable ISRs cat.2
 * Returns:     none
 * Notes:       called only if OsSuspendLevel == 0
 **************************************************************************/
OSINLINE void
OSSuspendInterrupts (void)
{
    OSINTMASKTYPE oldMask;
    oldMask = OSISRGetPrio ();

    #if (OSHIGHISRPRIO > 0U)
    if (oldMask < OSHIGHISRPRIO)
    {                           /* change level only if it is not higher    */
        OSISRSetPrio (OSHIGHISRPRIO);
        OSMSYNC ();
    }
    #endif
    OsSuspendLevel++;           /* increase counter of nested Suspend/Resume pairs */
    OsOldInterruptMask = oldMask;
}


/***************************************************************************
 * Macro:       OSResumeInterrupts
 * Description: Restore interrupt mask from the global variable
 * Returns:     none
 * Notes:       called only if OsSuspendLevel == 1
 **************************************************************************/
#define OSResumeInterrupts()         \
    OsSuspendLevel--;                \
    OSMSYNC();                       \
    OSISRSetPrio(OsOldInterruptMask)

#endif /* defined(OSISRENTRYEXIT) */

#if defined(OSTIMINGPROTECTION)
#if !defined(OSUSEISRLEVEL)
#define OSISRLEVELMASKED 0U
#endif /* !defined(OSUSEISRLEVEL) */
#endif /* defined(OSTIMINGPROTECTION) */

#if defined(OSRESOURCEISR) || defined(OSUSECONTEXT) || defined(OSEXTSTATUS)
/* ISR level used for ISR nesting control */
#define OSISRLEVELMASKED (OsIsrLevel & OSISRLEVELMASK)
#else
#if defined(OSUSEISRLEVEL)
#define OSISRLEVELMASKED  OsIsrLevel
#endif /*  !defined(OSUSEISRLEVEL)  */
#endif

#if !defined(OSNOISR)
/* Special ISR level to be used in hooks to avoid changing interrupt status */
#define OSISRRESOURCELEVEL  ((OSISRLEVELTYPE)0x80000000UL) /* ISR level for task, which got resource with ISR priority */
/* ISR level used for check in services */
#define OSISRLEVEL (OsIsrLevel & ~OSISRRESOURCELEVEL)
#else

#define OSISRLEVEL  OsIsrLevel
#endif /* !defined(OSNOISR) */


#ifdef __cplusplus
}
#endif


#endif /*OS_ISR_INTERNAL_API_H_ */

/** @} */
