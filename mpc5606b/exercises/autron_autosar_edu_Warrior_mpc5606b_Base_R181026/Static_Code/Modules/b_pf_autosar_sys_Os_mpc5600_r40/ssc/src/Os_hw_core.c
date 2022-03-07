/**
*   @file    Os_hw_core.c
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

#ifdef __cplusplus
extern "C"
{
#endif



/****************** generic includes START ***********************/
#include <Os_prop_autosar.h>

#include <Os_types_basic.h>

#include <Os_types_public.h>
#include <Os_types_common_public.h>
#include <Os_types_common_internal.h>

#include <Os_internal_api.h>
#include <Os_internal_types.h>

#include <Os_internal_config.h>

#include <Os_platform.h>
/****************** generic includes END ***********************/

#ifndef OSLINT

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#if defined(OSGHSPPC)
OSASM ("    .section    \".ostext\", \"vax\" ");
OSASM ("    .vle                             ");
#endif

#if defined(OSCWPPC)
/* C prototypes for called extern function are necessary only for CW compiler,
so these prototypes are placed here not in OS headers */
#pragma require_prototypes off
/* to suppress redundant warnings for asm functions */
extern char _f_ostext[];
extern char _e_ostext[];

extern void OSExceptionError (OSDWORD srr0, OSDWORD srr1);

#if defined(OSMEMPROTECTION)
extern void OSTLBException (OSDWORD srr0, OSDWORD srr1);
#endif
#endif

#define OSEXCEPTIONTOS  (OsExceptionStack+(OSEXCEPTIONSTACKSIZE-OSSTKADDS)*4)     /* TOS for exception handlers */


extern void OSInterruptDispatcher1 (void); /**< called from OSInterruptDispatcher, Located in Os_isr.c */


/******************************************************************************
* Function: OSInterruptDispatcher
* Description: wrapper for OSInterruptDispatcher1
* Returns:
* Notes: CPU context saving and loading
******************************************************************************/


#if (defined(OSE200Z0) && (!defined(OSMPC5660))) || defined(OSE200Z1) || defined(OSE200Z3) || defined(OSE200Z4) || \
defined(OSE200Z7)

#if defined(OSCWPPC)
OSASM void OSInterruptDispatcher (void)
{
    nofralloc

#else
    OSASMF (.globl OSInterruptDispatcher);
    OSASMF (OSInterruptDispatcher:);
#endif      /* defined(OSCWPPC) */

    OSASMF2 (e_stwu r1, -0x50 (r1));    /* prepare frame and 8 additional bytes for EABI */

    #if defined(OSDIABPPC) || defined(OSGHSPPC)
    OSASMF4 (.byte 0x18, 0x01, 0x11, 0x0C);    /* e_stmvgprw  0xC(r1): save R0, R3-R12 */
    OSASMF4 (.byte 0x18, 0x21, 0x11, 0x38);    /* e_stmvsprw  0x38(r1): save CR, LR, CTR, XER */
    OSASMF4 (.byte 0x18, 0x81, 0x11, 0x48);    /* e_stmvsrrw  0x48(r1): save SRR0, SRR1 */
    #endif /* defined(OSDIABPPC) || defined(OSGHSPPC) */
    #if defined(OSCWPPC)
    OSASMF (opword 0x1801110C);    /* e_stmvgprw  0xC(r1): save R0, R3-R12 */
    OSASMF (opword 0x18211138);    /* e_stmvsprw  0x38(r1): save CR, LR, CTR, XER */
    OSASMF (opword 0x18811148);    /* e_stmvsrrw  0x48(r1): save SRR0, SRR1 */
    #endif /* defined(OSCWPPC) */

    OSASMF (e_bl OSInterruptDispatcher1);

    #if defined(OSDIABPPC) || defined(OSGHSPPC)
    OSASMF4 (.byte 0x18, 0x81, 0x10, 0x48);    /* e_lmvsrrw   0x48(r1): load SRR0, SRR1 */
    OSASMF4 (.byte 0x18, 0x21, 0x10, 0x38);    /* e_lmvsprw   0x38(r1): load CR, LR, CTR, XER */
    OSASMF4 (.byte 0x18, 0x01, 0x10, 0x0C);    /* e_ldmvgprw  0xC(r1): load R0, R3-R12 */
    #endif /* defined(OSDIABPPC) || defined(OSGHSPPC) */
    #if defined(OSCWPPC)
    OSASMF (opword 0x18811048);    /* e_lmvsrrw   0x48(r1): load SRR0, SRR1 */
    OSASMF (opword 0x18211038);    /* e_lmvsprw   0x38(r1): load CR, LR, CTR, XER */
    OSASMF (opword 0x1801100C);    /* e_ldmvgprw  0xC(r1): load R0, R3-R12 */
    #endif /* defined(OSCWPPC) */

    OSASMF3 (e_addi r1, r1, 0x50);
    OSASMF (se_rfi);

#if defined(OSCWPPC)
}
#endif

#endif    /* (defined(OSE200Z0) && (!defined(OSMPC5660))) || defined(OSE200Z1) || defined(OSE200Z3) || defined(OSE200Z4) || \
             defined(OSE200Z7) */

/******************************************************************************
* Function:    OSSetJmp
* Description: Save current execution environment into buffer
* Input:       r3  - pointer to environment buffer
* Return:      always 0 
* Notes:       The following registers are saved:
*              LR (return address), r1, CTR, r14 - r31
******************************************************************************/
#if defined(OSNOFASTTERMINATE)
#if defined(OSCWPPC)
OSASM OSSIGNEDDWORD OSSetJmp (OSJMP_BUF)  /**** check if proper ret.type and parameter can be put in here ****/
{
    nofralloc
#endif  /* defined(OSCWPPC) */

    #if defined(OSDIABPPC) || defined(OSGHSPPC)
    OSASMF (.globl OSSetJmp);
    OSASMF (OSSetJmp:);
    #endif   /* defined(OSDIABPPC) || defined(OSGHSPPC) */

    OSASMF (se_mflr r4);
    OSASMF2 (se_stw r1, 0 (r3));
    OSASMF2 (e_stwu r4, 4 (r3));
    OSASMF (mfctr r4);
    OSASMF2 (e_stwu r4, 4 (r3));
    OSASMF2 (e_stmw r14, 4 (r3));    /* save r14 .. r31 */
    OSASMF2 (se_li r3, 0);
    OSASMF (se_blr);

#if defined(OSCWPPC)
}
#endif   /* defined(OSCWPPC) */

/******************************************************************************
* Function:    OSLongJmp
* Description: Restore execution environment from buffer
* Input:       r3  - pointer to environment buffer
* Return:      always 1 
* Notes:       The following registers are restored:
*              LR (return address), r1, CTR, r14 - r31
******************************************************************************/
#if defined(OSCWPPC)
OSASM OSSIGNEDDWORD    OSLongJmp (OSJMP_BUF)
{
    nofralloc
#else
    OSASMF (.globl OSLongJmp);
    OSASMF (OSLongJmp:);
#endif       /* defined(OSCWPPC) */

    OSASMF2 (se_lwz r1, 0 (r3));
    OSASMF2 (e_lwzu r5, 4 (r3));
    OSASMF (se_mtlr r5);
    OSASMF2 (e_lwzu r5, 4 (r3));
    OSASMF (se_mtctr r5);
    OSASMF2 (e_lmw r14, 4 (r3));    /* restore r14 .. r31 */
    OSASMF2 (se_li r3, 1);

#if defined(OSDIABPPC)
    OSASMF(.globl OsTaskExit); 
    OSASMF(OsTaskExit:); /* this label used to mark exit from task */
#endif

    OSASMF (se_blr);

#if defined(OSCWPPC)
}
#endif       /* defined(OSCWPPC) */
#endif       /* defined(OSNOFASTTERMINATE) */

/*
* System calls for different number of parameters
*/

#if defined(OSMEMPROTECTION)

#if (OSNNOTTRUSTEDAPPS > 0U)
/*****************************************************************************
* Function:    OS2SystemMode
*
* Description: Returns from OSSystemCallHandler always in supervisor mode,
*              call is allowed only from OS code
*
* Returns:     R3 - value of MSR before call
*
*****************************************************************************/
#if defined(OSCWPPC)
OSASM OSDWORD OS2SystemMode( void )
{
    nofralloc
#else
    OSASMF(     .globl OS2SystemMode );
    OSASMF( OS2SystemMode:           );
#endif /* defined(OSCWPPC) */
    OSASMF(     se_sc                );
    OSASMF(     se_blr               );
#if defined(OSCWPPC)
}
#endif /* defined(OSCWPPC) */
#endif /* (OSNNOTTRUSTEDAPPS > 0U) */

/******************************************************************************
* Function:    System call handler
*
* Description: Handles system calls (sc)
*
* Returns:     R3 - return value of old MSR
*
******************************************************************************/
#if defined(OSCWPPC)
OSASM void OSSystemCallHandler( void )
{                        
    nofralloc
#else
    OSASMF(     .globl OSSystemCallHandler            );
    OSASMF( OSSystemCallHandler:                      );
#endif /* defined(OSCWPPC) */


    OSASMF(     mfsrr1      r3                        ); /* load SRR1 */
    OSASMF2(    se_mr       r4,r3                     ); /* copy value of SRR1 */
    OSASMF2(    se_bclri    r4,17                     ); /* clear PR bit */
    OSASMF(     mtsrr1      r4                        ); /* save SRR1 */
    OSASMF(     se_rfi                                );
#if defined(OSCWPPC)
}
#endif /* defined(OSCWPPC) */

#endif       /* defined(OSMEMPROTECTION) */


/******************************************************************************
* Function:    OSCriticalException
* Description: Handles critical exception
* Returns:     
* Notes:       the processor uses CSRR0/CSRR1
******************************************************************************/
#if defined(OSCWPPC)
OSASM void OSCriticalException (void)
{
    nofralloc
#else
    OSASMF (.globl OSCriticalException);
    OSASMF (OSCriticalException:);
#endif       /* defined(OSCWPPC) */

    #if defined(OSMEMPROTECTION)
    /* switch stack to exception stack and call OSExceptionError() */

    OSASMF2 (e_lis r1, OSEXCEPTIONTOS@ha);
    OSASMF3 (e_add16i r1, r1, OSEXCEPTIONTOS@l);

    #endif       /* defined(OSMEMPROTECTION) */

    OSASMF (mfcsrr0 r3);
    OSASMF (mfcsrr1 r4);
    OSASMF (e_b OSExceptionError);
    /* This point is not reachable */
    OSASMF (OSCriticalExceptionEnd:);
    OSASMF (se_b OSCriticalExceptionEnd);

#if defined(OSCWPPC)
}
#endif       /* defined(OSCWPPC) */

/******************************************************************************
* Function:    OSMachineCheckException
* Description: Handles machine check exception
* Returns:     
* Notes:       the processor uses MCSRR0/MCSRR1
******************************************************************************/
#if defined(OSCWPPC)
OSASM void OSMachineCheckException (void)
{
    nofralloc
#else
    OSASMF (.globl OSMachineCheckException);
    OSASMF (OSMachineCheckException:);
#endif  /* defined(OSCWPPC) */

    #if defined(OSMEMPROTECTION)

    /* switch stack to exception stack and call OSExceptionError() */

    OSASMF2 (e_lis r1, OSEXCEPTIONTOS@ha);
    OSASMF3 (e_add16i r1, r1, OSEXCEPTIONTOS@l);


    #endif       /* defined(OSMEMPROTECTION) */

    #if defined(OSMULTICORE) && defined(OSMPC564xB)
    /* machine check exception may occur on Z0 or Z4. */
    OSASMF2(    mfspr    r3, 286                 );  /* PIR -> r3  */
    OSASMF2(    se_cmpi  r3, 0                   );  /* is core Z4 */
    OSASMF(     se_beq  OSMachineCheckException3 ); 
    OSASMF(     mfcsrr0  r3                      );  /* read Z0 csrrx registers */
    OSASMF(     mfcsrr1  r4                      );
    OSASMF(     se_b OSMachineCheckException4    );    
    OSASMF( OSMachineCheckException3:            );  
    OSASMF(     mfmcsrr0 r3                      );  /* read Z4 mcsrrx registers */
    OSASMF(     mfmcsrr1 r4                      );
    OSASMF( OSMachineCheckException4:            );
    #else
    #if defined(OSE200Z4) || defined(OSE200Z7)
    OSASMF(     mfmcsrr0 r3                      );
    OSASMF(     mfmcsrr1 r4                      );
    #else
    OSASMF(     mfcsrr0  r3                      );
    OSASMF(     mfcsrr1  r4                      );
    #endif /* defined(OSE200Z4) || defined(OSE200Z7) */
    #endif /* defined(OSMULTICORE) && defined(OSMPC564xB) */
    OSASMF(     e_b      OSMCExceptionError        );

    /* This point is not reachable */
    OSASMF (OSMachineCheckExceptionEnd:);
    OSASMF (se_b OSMachineCheckExceptionEnd);

#if defined(OSCWPPC)
}
#endif    /* defined(OSCWPPC) */

/******************************************************************************
* Function:    OSNonCriticalException
* Description: Handles non-critical exception
* Returns:     
* Notes:       the processor uses SRR0/SRR1
******************************************************************************/
#if defined(OSCWPPC)
OSASM void OSNonCriticalException (void)
{
    nofralloc
#else
    OSASMF (.globl OSNonCriticalException);
    OSASMF (OSNonCriticalException:);
#endif       /* defined(OSCWPPC) */

    #if defined(OSMEMPROTECTION)
    /* switch stack to exception stack and call OSExceptionError() */


    OSASMF2 (e_lis r1, OSEXCEPTIONTOS@ha);
    OSASMF3 (e_add16i r1, r1, OSEXCEPTIONTOS@l);

    #endif       /* defined(OSMEMPROTECTION) */

    OSASMF (mfsrr0 r3);
    OSASMF (mfsrr1 r4);
    OSASMF (e_b OSExceptionError);
    /* This point is not reachable */

    OSASMF (OSNonCriticalExceptionEnd:);
    OSASMF (se_b OSNonCriticalExceptionEnd);

#if defined(OSCWPPC)
}
#endif    /* defined(OSCWPPC) */


/******************************************************************************
* Function:    OSDebugException
* Description: Handles debug exception
* Returns:     never
******************************************************************************/
#if defined(OSCWPPC)
OSASM void OSDebugException (void)
{
    nofralloc
#else
    OSASMF (.globl OSDebugException);
    OSASMF (OSDebugException:);
#endif     /* defined(OSCWPPC) */

    #if defined(OSMEMPROTECTION)
    /* switch stack to exception stack and call OSExceptionError() */

    OSASMF2 (e_lis r1, OSEXCEPTIONTOS@ha);
    OSASMF3 (e_add16i r1, r1, OSEXCEPTIONTOS@l);

    #endif       /* defined(OSMEMPROTECTION) */

    OSASMF2 (se_li r3, 21);        /* set E_OS_SYS_FATAL */

    OSASMF (e_b OSShutdownOS);

    OSASMF (OSDebugExceptionEnd:);
    OSASMF (se_b OSDebugExceptionEnd);

#if defined(OSCWPPC)
}
#endif   /* defined(OSCWPPC) */

#if defined(OSMEMPROTECTION)
/******************************************************************************
* Function:    OSTLBErrorException
* Description: Handles both code and data TLB exceptions
* Returns:     
* Notes:       the processor uses SRR0/SRR1
******************************************************************************/
#if defined(OSCWPPC)
OSASM void OSTLBErrorException (void)
{
    nofralloc
#else
    OSASMF (.globl OSTLBErrorException);
    OSASMF (OSTLBErrorException:);
#endif       /* defined(OSCWPPC) */

    /* switch stack to exception stack and call OSExceptionError() */

    OSASMF2 (e_lis r1, OSEXCEPTIONTOS@ha);
    OSASMF3 (e_add16i r1, r1, OSEXCEPTIONTOS@l);


    OSASMF (mfsrr0 r3);
    OSASMF (mfsrr1 r4);
    OSASMF (e_b OSTLBException);

    /* This point is not reachable */
    OSASMF (OSTLBErrorExceptionEnd:);
    OSASMF (se_b OSTLBErrorExceptionEnd);

#if defined(OSCWPPC)
}
#endif       /* defined(OSCWPPC) */
#endif       /* defined(OSMEMPROTECTION) */


/***************************************************************************
* Function:    OSDECisr interrupt service routine
* Description: redirects interrupt request to INTC
* Notes:
**************************************************************************/

/***************************************************************************
* Function:    OSFITisr interrupt service routine
* Description: redirects interrupt request to INTC
* Notes:
**************************************************************************/

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#endif /*  ifndef OSLINT  */




#ifdef __cplusplus
}
#endif





/** @} */
