#ifndef OS_VECTORTABLE_H_
#define OS_VECTORTABLE_H_

/* polyspace:begin<MISRA-C:19.4:Not a defect:Justify with annotations>  Macro should be used as is */
/* polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations>  Macro should be used as is */
/**************************************************************************************
*
*   Freescale(TM) and the Freescale logo are trademarks of Freescale Semiconductor, Inc.
*   All other product or service names are the property of their respective owners.
*   (c) Copyright 2013 Freescale Semiconductor Inc.
*   All Rights Reserved.
*
*   You can use this example for any purpose on any computer system with the
*   following restrictions:
*
*   1. This example is provided "as is", without warranty.
*
*   2. You don't remove this copyright notice from this example or any direct derivation
*      thereof.
*
*  Description:  AUTOSAR OS sample application
*
**************************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

typedef unsigned int DWORD;

#if defined(OSDIABPPC)
#define PPCASM                 __asm volatile
#endif            /* defined(OSDIABPPC) */

#if defined(OSCWPPC)
#define PPCASM                 asm
#endif            /* defined(OSCWPPC) */

#if defined(OSGHSPPC)
#define PPCASM                 asm
#endif            /* defined(OSGHSPPC) */


/*
 * definitions for assembler functions
*/
#if defined(OSDIABPPC) || defined(OSGHSPPC)
/* polyspace<MISRA-C:19.13:Not a defect:Justify with annotations>  # should be used for OS */
#define PPCASM_STR(x) #x
#define PPCASMF(x) PPCASM (" "PPCASM_STR(x)" ")
#define PPCASMF2(x,x1) PPCASM (" "PPCASM_STR(x)","PPCASM_STR(x1)" ")
#define PPCASMF3(x,x1,x2) PPCASM (" "PPCASM_STR(x)","PPCASM_STR(x1)","PPCASM_STR(x2)" ")
#define PPCASMF4(x,x1,x2,x3) PPCASM (" "PPCASM_STR(x)","PPCASM_STR(x1)","PPCASM_STR(x2)","PPCASM_STR(x3)" ")
#define PPCASMF5(x,x1,x2,x3,x4) PPCASM (" "PPCASM_STR(x)","PPCASM_STR(x1)","PPCASM_STR(x2)","PPCASM_STR(x3)","PPCASM_STR(x4)" ")

#endif            /* defined(OSDIABPPC) || defined(OSGHSPPC) */

#if defined(OSCWPPC)

/* polyspace<MISRA-C:19.13:Not a defect:Justify with annotations>  # should be used for OS */
#define PPCASMF(x)  x
#define PPCASMF2(x,x1)  x,x1
#define PPCASMF3(x,x1,x2) x,x1,x2
#define PPCASMF4(x,x1,x2,x3) x,x1,x2,x3
#define PPCASMF5(x,x1,x2,x3,x4) x,x1,x2,x3,x4

#endif            /* defined(OSCWPPC) */

#ifdef __cplusplus
}
#endif

#endif /* OS_VECTORTABLE_H_ */

/* polyspace:end<MISRA-C:19.4:Not a defect:Justify with annotations>  Macro should be used as is */
/* polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations>  Macro should be used as is */