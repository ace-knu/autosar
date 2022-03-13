/**
*   @file    Os_hw_core_compiler.h
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

#ifndef OS_HW_CORE_COMPILER_H_
#define OS_HW_CORE_COMPILER_H_


#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Os_hw_core_compiler_h_REF_19_4_1
* Violates MISRA 2004 Required Rule 19.4, Expression-like macro not parenthesized
* The macro cannot be parenthesized because of assembler limitation, in all instances of
* this macro usage the macro is in brackets.
*/

#include <Os_hw_core_compiler_api.h>   /* get the defines in the private space too */


#if !defined(OSCWPPC)
#if defined(__MWERKS__)
#define OSCWPPC
#endif     /* defined(__MWERKS__) */
#endif

#if defined(OSGHSPPC)
#include <ppc_ghs.h>    /* for intrinsic functions only */
#endif

#if defined(OSDIABPPC)
#if !defined(OSDIABPPC_ASM_H)
#define OSDIABPPC_ASM_H
#include <diab/asm.h>    /* for intrinsic functions only */
#endif
#endif

#if !defined(OSCWPPC) && !defined(OSDIABPPC) && !defined(OSGHSPPC)
#error "Compiler is not defined"
#endif


#if defined(OSDIABPPC)
    #define OSCNTLZW( x )         (OSDWORD)__cntlzw( (OSDWORD)(x) )
    #define OSMTSPR( spr, value ) __mtspr( spr, (OSDWORD)(value) )
#endif            /* defined(OSDIABPPC) */

#if defined(OSCWPPC)
    #define OSCNTLZW( x )         (OSDWORD)__cntlzw( (OSDWORD)(x) )
#endif            /* defined(OSCWPPC) */

#if defined(OSGHSPPC)
    #define OSCNTLZW( x )         (OSDWORD)__CLZ32( (OSDWORD)(x) )
    #define OSMTSPR( spr, value ) __MTSPR( spr, (OSDWORD)(value) )
#endif            /* defined(OSGHSPPC) */



/* Disable/Enable Hardware Interrupts */
#if defined(OSDIABPPC)
    #define OSDHI()             __wrteei( 0 ); __msync()
    #define OSEHI()             __msync(); __wrteei( 1 )
#endif       /* defined(OSDIABPPC) */

#if defined(OSCWPPC)
    #define OSDHI()             OSASM{ wrteei 0 }; OSASM{ msync }
    #define OSEHI()             OSASM{ msync };  OSASM{ wrteei 1 }
#endif       /* defined(OSCWPPC) */

#if defined(OSGHSPPC)
    #define OSDHI()             __DI( ); __MSYNC( )
    #define OSEHI()             __MSYNC( ); __EI( )
#endif       /* defined(OSGHSPPC) */



/* Set the SP register new value */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSASM void OSLOADSP (OSDWORD * loadsp)
{
%reg loadsp
    mr r1, loadsp
}
#endif

#if defined(OSCWPPC)
OSINLINE void OSLOADSP (register OSDWORD * loadsp)
{
    OSASM volatile
    {
        mr r1, loadsp;
    }
}
#endif


/* Get the SP register value */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSASM OSDWORD OSGETSTACKPOINTER_ (void)
{
    mr r3, r1
}

OSINLINE OSDWORD OSGETSTACKPOINTER (void)
{
    return OSGETSTACKPOINTER_();
}
#endif

#if defined(OSCWPPC)
OSINLINE OSDWORD OSGETSTACKPOINTER (void)
{
    register OSDWORD x;
    OSASM
    {
        mr x, r1;
    }
    return x;
}
#endif


/* Get the HID0 register value */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE OSDWORD OSGETHID0 (void)
{
    return OSMFSPR( 1008 );
}
#endif

#if defined(OSCWPPC)
OSINLINE OSDWORD OSGETHID0 (void)
{
    register OSDWORD x;
    OSASM
    {
        mfspr x, 1008;
    }                /* read HID0 */
    return x;
}
#endif


/* Set the HID0 register new value */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE volatile void OSSETHID0 (register OSDWORD x)
{
    OSMTSPR( 1008, x ); OSMSYNC( );
}
#endif

#if defined(OSCWPPC)
OSINLINE volatile void OSSETHID0 (register OSDWORD x)
{
    OSASM
    {
        mtspr 1008, x;
    }
    OSASM
    {
        msync;
    }
}
#endif


/* SPRG1 contains the head of the task list */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE OSDWORD OSGetSPRG1 (void)
{
    return OSMFSPR( 273 );
}
#endif

#if defined(OSCWPPC)
OSINLINE OSDWORD OSGetSPRG1 (void)
{
    register OSDWORD x;

    OSASM
    {
        mfsprg1 x;
    }
    return x;
}
#endif


/* Set the SPRG1 register new value */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE void OSSetSPRG1 (register OSDWORD x)
{
    OSMTSPR( 273, x );
}
#endif

#if defined(OSCWPPC)
OSINLINE void OSSetSPRG1 (register OSDWORD x)
{
    OSASM
    {
        mtsprg1 x;
    }
}
#endif


#if defined(OSE200Z1) || defined(OSE200Z3) || defined(OSE200Z4) || defined(OSE200Z6) || defined(OSE200Z7)

/* Get the SPRG4 register value, can be read from user/supervisor mode */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE OSDWORD OSGetSPRG4 (void)
{
    return OSMFSPR( 260 );
}
#endif

#if defined(OSCWPPC)
OSINLINE OSDWORD OSGetSPRG4 (void)
{
    register OSDWORD x;

    OSASM
    {
        mfspr x, 260;
    }
        return x;
}
#endif


/* Set the SPRG4 register new value */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE void OSSetSPRG4 (register OSDWORD x)
{
    OSMTSPR( 276, x );
}
#endif

#if defined(OSCWPPC)
OSINLINE void OSSetSPRG4 (register OSDWORD x)
{
    OSASM
    {
        mtsprg4 x;
    }
}
#endif
#endif  /* defined(OSE200Z1) || defined(OSE200Z3) || defined(OSE200Z4) || defined(OSE200Z6) || defined(OSE200Z7) */


/* Get the PID0 register value */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE OSDWORD OSGetPID0 (void)
{
    return OSMFSPR( 48 );
}
#endif

#if defined(OSCWPPC)
OSINLINE OSDWORD OSGetPID0 (void)
{
    register OSDWORD x;

    OSASM
    {
        mfpid0 x;
    }
    return x;
}
#endif


/* Set the PID0 register value */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE void OSSetPID0 (register OSDWORD x)
{
    OSMTSPR( 48, x ); OSISYNC( );
}
#endif

#if defined(OSCWPPC)
OSINLINE void OSSetPID0 (register OSDWORD x)
{
    OSASM
    {
        mtpid0 x;
    }
    OSISYNC ();
}
#endif


#if defined(OSE200Z6) || defined(OSE200Z7)
#define OSL1CSR0_DSB (0x00040000UL)    /* disable store buffer bit */

/* Get the L1CSR0 register value */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE OSDWORD OSGetL1CSR0 (void)
{
    return OSMFSPR( 1010 );
}
#endif

#if defined(OSCWPPC)
OSINLINE OSDWORD OSGetL1CSR0 (void)
{
    register OSDWORD x;

    OSASM
    {
        mfl1csr0 x;
    }
    return x;
}
#endif


/* Set the L1CSR0 register value */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE void OSSetL1CSR0 (register OSDWORD x)
{
    OSMTSPR( 1010, x );
}
#endif

#if defined(OSCWPPC)
OSINLINE void OSSetL1CSR0 (register OSDWORD x)
{
    OSASM
    {
        mtl1csr0 x;
    }
}
#endif
#endif       /* defined(OSE200Z6)|| defined(OSE200Z7) */


#if defined(OSUSEWAIT)
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE void OSWAIT (void)
{
    OSASM("wait");
}
#endif

#if defined(OSCWPPC)
OSINLINE void OSWAIT (void)
{
    OSASM
    {
        wait;
    }
}
#endif
#else
/* 'wait' can stop some clk(depends on derivative) */
#define OSWAIT()
#endif /* defined(OSUSEWAIT) */


/* Time base reading macros */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
#define OSGETTB( ) OSMFSPR( 268 )
/*
* @violates @ref Os_hw_core_compiler_h_REF_19_4_1 MISRA 2004 Required Rule 19.4, Expression-like macro not parenthesized
*/
#define OSGETTBU( x ) x = OSMFSPR( 269 )
/*
* @violates @ref Os_hw_core_compiler_h_REF_19_4_1 MISRA 2004 Required Rule 19.4, Expression-like macro not parenthesized
*/
#define OSGETTBL( x ) x = OSMFSPR( 268 )
#endif

#if defined(OSCWPPC)
OSINLINE OSDWORD OSGETTB (void)
{
    register OSDWORD x;
    OSASM
    {
        mfspr x, 268;
    }                /* read timebase via UTBL */
    return x;
}

#define OSGETTBU( x )  OSASM { mfspr x, 269; }
#define OSGETTBL( x )  OSASM { mfspr x, 268; }
#endif       /* defined(OSCWPPC) */

#define OSGETTB64(tb)                        \
{                                           \
    register OSDWORD low, up1, up2;         \
                                            \
    OSGETTBU(up1);                          \
    OSGETTBL(low);                          \
    OSGETTBU(up2);                          \
                                            \
    if( up1 != up2 )                        \
    {                                       \
        OSGETTBL(low);                      \
    }                                       \
                                            \
    (tb) = ( (OSQWORD)up2 << 32ull ) + low; \
}


/* Time base writing macros, ticks must be more then zero */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE void OSSETTBL (register OSSIGNEDDWORD x)
{
    OSMTSPR( 284, x );
}

OSINLINE void OSSETTBU (register OSSIGNEDDWORD x)
{
    OSMTSPR( 285, x );
}
#endif

#if defined(OSCWPPC)
OSINLINE void OSSETTBL (register OSSIGNEDDWORD x)
{
    OSASM
    {
        mtspr 284, x;
    }
}

OSINLINE void OSSETTBU (register OSSIGNEDDWORD x)
{
    OSASM
    {
     mtspr 285, x;
    }
}
#endif       /* defined(OSCWPPC) */


/* Get the TCR register value */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE OSDWORD OsGetTCR (void)
{
    return OSMFSPR( 340 );
}
#endif

#if defined(OSCWPPC)
OSINLINE OSDWORD OsGetTCR (void)
{
    register OSDWORD x;
    OSASM
    {
        mfspr x, 340;
    }
    return x;
}
#endif


/* Set the TCR register new value */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE void OsSetTCR (register OSDWORD x)
{
    OSMTSPR( 340, x );
}
#endif

#if defined(OSCWPPC)
OSINLINE void OsSetTCR (register OSDWORD x)
{
    OSASM
    {
        mtspr 340, x;
    }
}
#endif


/* Get the TSR register value */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE OSDWORD OsGetTSR (void)
{
    return OSMFSPR( 336 );
}
#endif

#if defined(OSCWPPC)
OSINLINE OSDWORD OsGetTSR (void)
{
    register OSDWORD x;
    OSASM
    {
        mfspr x, 336;
    }
    return x;
}
#endif


/* Set the TSR register new value */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE void OsSetTSR (register OSDWORD x)
{
    OSMTSPR( 336, x );
}
#endif

#if defined(OSCWPPC)
OSINLINE void OsSetTSR (register OSDWORD x)
{
    OSASM
    {
        mtspr 336, x
    };
}
#endif




/***************************************************************************
* Macro  : OsSetIVPR()
* Description: Sets Interrupt Vector Prefix Register (IVPR)
* Returns: none
* Notes: It is used in OSInitializeISR
**************************************************************************/
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE void OsSetIVPR (register OSDWORD x)
{
    OSMTSPR( 63, x );
}
#endif

#if defined(OSCWPPC)
OSINLINE void OsSetIVPR (register OSDWORD x)
{
    OSASM
    {
        mtspr 63, x;
    }
}
#endif



#if defined(OSUSEISRSTACK) || defined(OSSYSTIMER) || defined(OS2SYSTIMER) || \
defined(OSTIMINGPROTECTION) || defined(OSMEMPROTECTION)

#if defined(OSDIABPPC)
OSASM void OSLoadISRSP (OSDWORD * isrsp)
{
%reg isrsp
    e_stwu r1, -4(isrsp)    /*  store stack pointer into environment buffer */
    e_add16i r1, isrsp, -8
}
#endif            /* defined(OSDIABPPC) */

#if defined(OSGHSPPC)
OSASM void OSLoadISRSP_ (OSDWORD * isrsp)
{
%reg isrsp
    e_stwu r1, -4(isrsp)
    e_add16i r1, isrsp, -8
}

OSINLINE void OSLoadISRSP (OSDWORD * isrsp)
{
    OSLoadISRSP_ (isrsp);
}
#endif  /* defined(OSGHSPPC) */

#if defined(OSCWPPC)
OSINLINE void OSLoadISRSP (register OSDWORD * isrsp)
{
    OSASM
    {
        e_stwu r1, -4 (isrsp);
    }
    OSASM
    {
        e_add16i r1, isrsp, -8;
    }
}
#endif /* defined(OSCWPPC) */



#if defined(OSDIABPPC)
OSASM void OSRestoreSP (void)
{
    se_lwz r1,8(r1)
}
#endif            /* defined(OSDIABPPC) */

#if defined(OSGHSPPC)
OSASM void OSRestoreSP ()
{
    se_lwz r1,8(r1)
}
#endif            /* defined(OSGHSPPC) */

#if defined(OSCWPPC)
OSINLINE void OSRestoreSP (void)
{
    OSASM
    {
        se_lwz r1,8(r1);
    }
}
#endif       /* defined(OSCWPPC) */

#else

#define OSRestoreSP()

#endif  /* defined(OSUSEISRSTACK) || defined(OSSYSTIMER) || defined(OS2SYSTIMER) || \
defined(OSTIMINGPROTECTION) || defined(OSMEMPROTECTION) */


/*****************************************************************************
* inline function: OSGetESR
* Description:     get the value of Exception syndrome register
* Returns:         the value of ESR
*****************************************************************************/
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE OSDWORD OSGetESR (void)
{
    return OSMFSPR( 62 );
}
#endif

#if defined(OSCWPPC)
OSINLINE OSDWORD OSGetESR (void)
{
    register OSDWORD x;

    OSASM
    {
        mfspr x,62;
    }
    return x;
}
#endif


/*****************************************************************************
* inline function: OSGetMCSR
* Description:     get the value of Machine Check Syndrome Register
* Returns:         the value of MCSR
****************************************************************************/
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSINLINE OSDWORD OSGetMCSR (void)
{
    return OSMFSPR( 572 );
}
#endif

#if defined(OSCWPPC)
OSINLINE OSDWORD OSGetMCSR (void)
{
    register OSDWORD x;

    OSASM
    {
        mfspr x,572;
    }
    return x;
}
#endif


/*****************************************************************************
* inline function: OSSetMCSR
* Description:     set Machine Check Syndrome Register
* Returns:         none
****************************************************************************/
#if defined(OSGHSPPC) || defined(OSDIABPPC)
#define OSSetMCSR( x ) OSMTSPR( 572, x )
#endif

#if defined(OSCWPPC)
OSINLINE void OSSetMCSR (register OSDWORD x)
{
    OSASM
    {
        mtspr 572, x;
    }
}
#endif



#ifdef __cplusplus
}
#endif

#endif /*OS_HW_CORE_COMPILER_H_*/

/** @} */

