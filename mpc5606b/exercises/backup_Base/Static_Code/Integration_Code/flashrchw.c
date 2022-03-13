#define FLASHRCHW_C
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
*   1. This example is provided "as is", without warranty.
*
*   2. You don't remove this copyright notice from this example or any direct
*      derivation thereof.
*
* Description:    BAM RCHW block for OS/MPC5600
*
* Notes:
*
******************************************************************************/

#if defined(FLASH_START)

#include    <Os.h>

#define RCHW_VAL 0x015A0000

#if defined(OSCWPPC)
extern void __start(void);
#else
extern void _start(void);
#endif

#define RCHW_START_SEC_DATA
#include "MemMap.h"

#if defined(OSDIABPPC)
#pragma option -Xsmall-const=0 /* to ensure placement of RCHW1,2 variables in the section .rchwdata */
#endif

#if defined(OSCWPPC)
#define RCHWDATA __declspec(section ".rchwdata") 
#define ENTRY_POINT __start
#else
#define RCHWDATA
#define ENTRY_POINT  _start
#endif

RCHWDATA const uint32 RCHW1=RCHW_VAL;
RCHWDATA const uint32 RCHW2=(uint32)ENTRY_POINT;

#define RCHW_STOP_SEC_DATA
#include "MemMap.h"

#endif /* defined(FLASH_START) */
