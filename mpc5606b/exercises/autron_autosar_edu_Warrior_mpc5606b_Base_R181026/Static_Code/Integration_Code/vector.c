#define VECTOR_C
/******************************************************************************
*
*   Freescale(TM) and the Freescale logo are trademarks of Freescale Semiconductor, Inc.
*   All other product or service names are the property of their respective owners.
*   (c) Copyright 2013 Freescale Semiconductor Inc.
*   All Rights Reserved.
*
*   You can use this example for any purpose on any computer system with the
*   following restrictions:
*
*   1. This example is provided  as is , without warranty.
*
*   2. You don't remove this copyright notice from this example or any direct
*      derivation thereof.
*
* Description:    Vector table for OS/MPC5600
*
* Notes:
*
******************************************************************************/
#include <Os.h>
#include <app_compiler_abstraction.h>
#include "exception.h"

#define OSVECTORS_START_SEC_CODE
#include <MemMap.h>

#if defined(OSDIABPPC)
#define VEC_ALIGN   asm volatile (" .skip 0x0C ")
#endif

#if defined(OSGHSPPC)
#define VEC_ALIGN   asm (" .skip 0x0C ")
#endif

#if defined(OSDIABPPC) || defined(OSGHSPPC)
    PPCASMF(   .globl VTABLE                   );
    PPCASMF(VTABLE:                            ); /* Vector table start address */

#elif defined(OSCWPPC)  /* defined(OSDIABPPC) || defined(OSGHSPPC) */

extern void OSCriticalException( void );
extern void OSMachineCheckException( void );
extern void OSNonCriticalException( void );
extern void OSInterruptDispatcher( void );
extern void OSSystemCallHandler( void );
extern void OSTLBErrorException( void );
extern void OSDebugException( void );
extern void VTABLE( void );
#define SIXTEEN_BYTES 16
#pragma force_active on
#pragma function_align 16

#define VEC_ALIGN  .align SIXTEEN_BYTES

asm void VTABLE( void )
{
    nofralloc
#endif

    PPCASMF(    e_b   OSCriticalException        ); /* Critical input */

    VEC_ALIGN;
    PPCASMF(    e_b   Os_MachineCheckException   ); /* Machine check */

    VEC_ALIGN;
    PPCASMF(    e_b   Os_DataStorageException    ); /* Data storage */

    VEC_ALIGN;
    PPCASMF(    e_b   OSNonCriticalException     ); /* Instruction storage */

    VEC_ALIGN;
    PPCASMF(    e_b   OSInterruptDispatcher      ); /* External input */

    VEC_ALIGN;
    PPCASMF(    e_b   OSNonCriticalException     ); /* Alignment */

    VEC_ALIGN;
    PPCASMF(    e_b   OSNonCriticalException     ); /* Program */

    VEC_ALIGN;
    PPCASMF(    e_b   OSNonCriticalException     ); /* Floating-point unavailable */

    VEC_ALIGN;
#if defined(OSSC3) || defined(OSSC4)                /* System call */
    PPCASMF(    e_b   OSSystemCallHandler        );
#else
    PPCASMF(    e_b   OSNonCriticalException     );
#endif

    VEC_ALIGN;
    PPCASMF(    e_b   OSNonCriticalException     );

    VEC_ALIGN;
    PPCASMF(    e_b   OSNonCriticalException     ); /* Decrementer */

    VEC_ALIGN;
    PPCASMF(    e_b   OSNonCriticalException     ); /* Fixed Interval Timer */

    VEC_ALIGN;
    PPCASMF(    e_b   OSCriticalException        ); /* Watchdog Timer */

    VEC_ALIGN;
#if defined(OSSC3)  || defined(OSSC4)
    PPCASMF(    e_b   OSTLBErrorException        ); /* Data TLB Error */
#else
    PPCASMF(    e_b   OSNonCriticalException     );
#endif

    VEC_ALIGN;
#if defined(OSSC3)  || defined(OSSC4)
    PPCASMF(    e_b   OSTLBErrorException        ); /* Instruction TLB Error */
#else
    PPCASMF(    e_b   OSNonCriticalException     );
#endif

    VEC_ALIGN;
    PPCASMF(    e_b   OSDebugException           ); /* Debug */

#if defined(OSCWPPC)
}
#endif

#define OSVECTORS_STOP_SEC_CODE
#include <MemMap.h>
