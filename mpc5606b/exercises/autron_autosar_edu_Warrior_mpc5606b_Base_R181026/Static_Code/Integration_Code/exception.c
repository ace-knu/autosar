/*
 * exception.c
 *
 *  Created on: 2014. 6. 3.
 *      Author: 1000059
 */

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

#include <exception.h>
#include "Fls_Cfg.h"
#include "Fls_Api.h"
#include "Mcu.h"
/****************** generic includes END ***********************/

#ifndef OSLINT

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#if defined(OSGHSPPC)
OSASM ("    .section    \".ostext\", \"vax\" ");
OSASM ("    .vle                             ");
#elif defined(OSCWPPC)
#pragma section code_type ".ostext"
#endif

/* TOS for exception handlers */
#define OSEXCEPTIONTOS  (OsExceptionStack+(OSEXCEPTIONSTACKSIZE-OSSTKADDS)*4)

extern void OSNonCriticalException(void);
#if defined(OSCWPPC)
extern void Os_RamEccHandle(void);
extern Fls_InstructionAddressType BoleroDsi_Handler(
                                            Fls_InstructionAddressType instr_pt,
                                            Fls_DataAddressType data_pt,
                                            uint32 syndrome);
#endif
/* Private functions */
/* ----------------- */
static Fls_InstructionAddressType Bolero_getNextInstructionAddress(
                                        ExceptionDetailsPtrType excDetails_pt);


/******************************************************************************
* Function:    Os_MachineCheckException
* Description: Handles Machine Check exception
*              if not MPU error, disable MPU and InitAllSram and MCU reset
*              else do AUTOSAR standard handling
* Returns:
* Notes:       the processor uses CSRR0/CSRR1
******************************************************************************/
#if defined(OSGHSPPC)
void Os_MachineCheckException(void)
#elif defined(OSCWPPC)
asm void Os_MachineCheckException(void)
#endif
{
  #if defined(OSMEMPROTECTION)
  /* if (OS_MPU_CESR.B.SPERRn == 0)
   *   goto InitAllSram
   * else
   *   goto OSMachineCheckException() */
#if defined(OSGHSPPC)
  #pragma asm
#endif
  e_lis         r7, %hi(0xFFF10000)
  se_lwz        r7, 0x0(r7)
  e_srwi.       r7, r7, 0x18
  se_beq        InitAllSram
  e_b           OSMachineCheckException ; /* No return */
#if defined(OSGHSPPC)
  #pragma endasm
#endif
  #endif

#if defined(OSGHSPPC)
  #pragma asm
#endif
  InitAllSram:
  e_li          r3, 24; /* _E_OS_SYS_MACHINECHECK */
  e_b           Os_RamEccHandle
#if defined(OSGHSPPC)
  #pragma endasm
#endif

  /* Do not reach here */
#if defined(OSGHSPPC)
  #pragma asm
#endif
  se_rfci
#if defined(OSGHSPPC)
  #pragma endasm
#endif
}

/******************************************************************************
* Function:    Os_DataStorageException
* Description: Handles Data Storage exception
* Returns:
* Notes:       the processor uses SRR0/SRR1
******************************************************************************/
#if defined(OSGHSPPC)
void void Os_DataStorageException(void)
#elif defined(OSCWPPC)
asm void Os_DataStorageException(void)
#endif
{
#if defined(OSGHSPPC)
  #pragma asm
#endif
  #if defined(OSMEMPROTECTION)
  mtspr       sprg0, r1
  e_lis       r1, %hi(OSEXCEPTIONTOS)
  e_add16i    r1, r1, %lo(OSEXCEPTIONTOS)
  #endif
  e_stwu      r1, -80(r1)

  e_stmvgprw  36(r1)
  e_stmvsprw  20(r1)
  e_stmvsrrw  12(r1)

  ; /* if CodeFlash error(CFLASH_MCR: 0xC3F88000) */
  ; /*   goto DsiHandler */
  ; /* else if DataFlash error(DFLASH_MCR: 0xC3F8C000) */
  ; /*   goto DsiHandler */
  ; /* else */
  ; /*   goto CheckMpuError */
  e_lis       r12, 0xC3F9
  e_lwz       r9, -0x8000(r12)
  e_andi.     r0, r9, 0x8000
  se_bne      DsiHandler
  e_lis       r12, 0xC3F9
  e_lwz       r9, -0x4000(r12)
  e_andi.     r0, r9, 0x8000
  se_beq      CheckMpuError
  DsiHandler:
  mfspr       r5, 62
  mfspr       r4, 61
  mfsrr0      r3
  e_bl        BoleroDsi_Handler

#if defined(OSGHSPPC)
  e_lmvsprw   20(%r1)
  e_lmvsrrw   12(%r1)
#elif defined(OSCWPPC)
  e_lmvsprw   20(r1)
  e_lmvsrrw   12(r1)
#endif
  mtsrr0      r3

#if defined(OSGHSPPC)
  e_lmvgprw   36(%r1)
#elif defined(OSCWPPC)
  e_lmvgprw   36(r1)
#endif

#if defined(OSGHSPPC)
  e_add16i    %r1, %r1, 80
#elif defined(OSCWPPC)
  e_add16i    r1, r1, 80
#endif
  #if defined(OSMEMPROTECTION)
  mfspr       r1, sprg0
  #endif

  se_rfi

  CheckMpuError:
  #if defined(OSMEMPROTECTION)
  ;/* if (OS_MPU_CESR.B.SPERRn == 0) */
  ;/*   goto RamEccHandle */
  ;/* else */
  ;/*   goto OSNonCriticalException() */
  e_lis         r7, %hi(0xFFF10000)
  se_lwz        r7, 0x0(r7)
  e_srwi.       r7, r7, 0x18
  se_beq        RamEccHandle
  e_b           OSNonCriticalException ; /* No return */
  #endif

  RamEccHandle:
  e_li          r3, 25; /* _E_OS_SYS_DATASTORAGE */
  e_b           Os_RamEccHandle
#if defined(OSGHSPPC)
  #pragma endasm
#endif
}




Fls_InstructionAddressType BoleroDsi_Handler(
                                            Fls_InstructionAddressType instr_pt,
                                            Fls_DataAddressType data_pt,
                                            uint32 syndrome)
{
    /*LDRA_NOANALYSIS*/
    Fls_ExceptionDetailsType excDetails;
#if( FLS_DSI_HANDLER_API == STD_ON )
    Fls_CompHandlerReturnType specificHandlerResult = FLS_UNHANDLED;
#endif

    excDetails.instruction_pt = instr_pt;
    excDetails.data_pt        = data_pt;
    excDetails.syndrome_u32   = syndrome;

#if 0
    ... /* customer specific processing */
#endif

#if( FLS_DSI_HANDLER_API == STD_ON )
    /* here call the FLS driver function */
    specificHandlerResult = Fls_DsiHandler( &excDetails );

    switch(specificHandlerResult)
    {
        case FLS_HANDLED_SKIP:
            /* exception was handled by one of the functions called above,    *
             * Continue exceution, skipping the causing instruction           */
            instr_pt = Bolero_getNextInstructionAddress(&excDetails);
            break;
        case FLS_HANDLED_RETRY:
            /* exception was handled by one of the functions called above,    *
             * Continue exceution, retrying the causing instruction           *
             * Thus, we don't need to modify instr_pt                         */
            break;
        case FLS_UNHANDLED:
            /* special handling: try to store some info that nobody handled   *
             * this exception Then, try to shut-down in a controlled way.     *
             * For this purpose we just fall through ...                      */
            OSNonCriticalException();
            break;

        case FLS_HANDLED_STOP:
             /* Try to shut-down in a controlled way.                         *
              * If there's no chance to shut down in a controlled way,        *
              * just fall through ...                                         */
            OSNonCriticalException();
            break;

        default:
            /* unexpected return - we end in an endless loop                  */
            OSNonCriticalException();
            break;
    }
#else
    instr_pt = Bolero_getNextInstructionAddress(&excDetails);
#endif
    return instr_pt;
    /*LDRA_ANALYSIS*/
}


/* This function determines the address of the instruction following the      *
 * causing instruction.                                                       *
*  Note that in case of jump instructions the returned address is NOT address *
*  of the jump target!                                                        */
/**************************************************************
 *  Name                 :  Bolero_getNextInstructionAddress
 *  Description          :
 *  Parameters           :  ExceptionDetailsPtrType excDetails_pt
 *  Return               :	Fls_InstructionAddressType
 *  Critical/explanation :  No
 **************************************************************/
static Fls_InstructionAddressType Bolero_getNextInstructionAddress(
                                          ExceptionDetailsPtrType excDetails_pt)
{
    /*LDRA_NOANALYSIS*/
    Fls_InstructionAddressType instrAddress = excDetails_pt->instruction_pt;
    /* use the first byte of the instruction */
    const uint8_least opCode = (*instrAddress) & 0x90u;

    /*########################################################################
     * Z0 core supports only VLMEI code so nobody check (line below) is done
     * on the ERS register to verify if the code is in VLMEI
     * const uint8_least isPpcMode =
     *                   ((excDetails_pt->syndrome_u32 & EXC_ESR_VLEMI) == 0);
     *########################################################################*/

    /* whe have to increase the address by four, if the causing instruction   *
     * does not lie within an VLE-section,                                    *
     * or if its actually a 32bit VLE Instruction                             */
    if (opCode == 0x10)
    {
        /* most significant 4 Bits have a value of 1,3,5,7 */
        instrAddress += 4;    /* instruction was 32 bit */
    }
    else
    {
        /* most significant 4 Bits have a value of 0,2,4,6,8,9,A,B,C,D,E      *
         * (and F, which is reserved)                                         */
        instrAddress += 2;    /* instruction was 16 bit */
    }

    return instrAddress;
    /*LDRA_ANALYSIS*/
}

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#endif /*  ifndef OSLINT  */




#ifdef __cplusplus
}
#endif





/** @} */


