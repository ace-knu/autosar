/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Os_InitSram.c                                                 **
**                                                                            **
**  TARGET    : MPC56xx                                                       **
**                                                                            **
**  PRODUCT   : -                                                             **
**                                                                            **
**  PURPOSE   : SRAM ECC Initialize.                                          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 1.0.0     16-Mar-2015    MJ.Woo        Initial version                     **
** 1.0.1     16-Mar-2015    Jung Ji-Hoon  Modify Ram ECC Handler              **
**                                        AppCallbackOnSystemError ->         **
**                                        ErrM_OsErrorNotification            **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_prop.h"
#include "Mcu_LLD.h"
#include "ErrM.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define SRAM_BASE_ADDR 0x40000000

/* The size of internal RAM */
#if defined(OSMPC5602P)
        #define OSLOOP_SIZE (20*1024)>>7

    #elif defined(OSMPC5604P)
        #define OSLOOP_SIZE (40*1024)>>7

    #elif defined(OSMPC5602D)
        #define OSLOOP_SIZE (16*1024)>>7

    #elif defined(OSMPC5604B)
        #define OSLOOP_SIZE (48*1024)>>7

    #elif defined(OSMPC5606B)
        #define OSLOOP_SIZE (80*1024)>>7

    #elif defined(OSMPC5607B)
        #define OSLOOP_SIZE (96*1024)>>7

    #else
        #error "MCU type is not specified"
#endif

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/***************************************************************************//**
 * Function Name        : __ghs_board_memory_init
 *
 * Service ID           : NA
 *
 * Description          : Code to initialize all internal RAM.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : This must be executed before using RAM to avoid
 *                        ECC errors.
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
#if defined(FLASH_START)
#if defined(OSGHSPPC)
#pragma asm
    .set BASE_SRAM_ADDRESS, SRAM_BASE_ADDR
    .set OS_LOOP_SIZE,      OSLOOP_SIZE; /* Loop counter to get all of L2SRAM */
    .set MC_RGM_DES,        0xC3FE4002
#if defined(OSGHSPPC)
    .globl __ghs_board_memory_init

__ghs_board_memory_init:
#endif
#elif defined(OSCWPPC)
extern void VTABLE(void);
void __ghs_board_memory_init(void)
{
  OSDWORD BASE_SRAM_ADDRESS = SRAM_BASE_ADDR;
  OSDWORD OS_LOOP_SIZE      = OSLOOP_SIZE; /* Loop counter to get all of L2SRAM */
  OSDWORD MC_RGM_DES        = 0xC3FE4002;
asm
{
#endif
__ghsautoimport_ghs_board_memory_init:
    ; /* Set Exception Vector Table */
#if defined(OSGHSPPC)
    e_lis  r11, %hi(VTABLE)
    e_or2i r11, %lo(VTABLE)
#elif defined(OSCWPPC)
    e_lis  r11, VTABLE@h
    e_or2i r11, VTABLE@l
#endif
    mtspr  ivpr, r11
    ; /* Check whether Power On Reset was occurred */
#if defined(OSGHSPPC)
    e_lis  r11, %hi(MC_RGM_DES)
    e_or2i r11, %lo(MC_RGM_DES)
#elif defined(OSCWPPC)
    e_lis  r11, MC_RGM_DES@h
    e_or2i r11, MC_RGM_DES@l
#endif
    e_lhz  r12, 0(r11)
    e_andi r12, r12, 0x8000
    e_cmpi r12, 0x8000
    ; /* If Reset reason is not POR, skip SRAM init */
    se_bne PassSramInit

    ; /* Init all SRAM */
#if defined(OSGHSPPC)
    e_lis  r11, %hi(BASE_SRAM_ADDRESS)
#elif defined(OSCWPPC)
    e_lis  r11, BASE_SRAM_ADDRESS@h
#endif
    e_li   r12, OSLOOP_SIZE
    mtctr  r12
init_l2sram_loop:
    e_stmw r0, 0(r11) ; /* Write all 32 GPRs to L2SRAM */
    e_addi r11, r11, 128
    e_bdnz init_l2sram_loop
PassSramInit:
    se_blr
#if defined(OSGHSPPC)
#pragma endasm
#elif defined(OSCWPPC)
}
}
#endif
#endif /* if defined(FLASH_START) */

/***************************************************************************//**
 * Function Name        : Os_RamEccHandle
 *
 * Service ID           : NA
 *
 * Description          : Init all SRAM ECC and reset MCU
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
#if defined(OSGHSPPC)
void Os_RamEccHandle(void)
#elif defined(OSCWPPC)
asm void Os_RamEccHandle(void)
#endif
{
  /*
   * OS_MPU_CESR.B.VLD = 0(If Memory Protection is used)
   * InitAllSram
   * Mcu_PerformReset()
   */
#if defined(OSGHSPPC)
  #pragma asm
#endif
  #if defined(OSMEMPROTECTION)
  e_lis         r6, %hi(0xFFF10000)
  se_lwz        r7, 0x0(r6)
  e_li          r12, 0
  e_rlwimi      r7, r12, 0, 0x1F, 0x1F
  se_stw        r7, 0x0(r6)
  #endif
#if defined(OSGHSPPC)
  e_lis         r11, %hi(SRAM_BASE_ADDR)
#elif defined(OSCWPPC)
  e_lis         r11, SRAM_BASE_ADDR@h
#endif
  e_li          r12, OSLOOP_SIZE
  mtctr         r12
  WriteAllGPRs:
  e_stmw r0, 0(r11) ; /* Write all 32 GPRs to L2SRAM */
  e_addi r11, r11, 128
  e_bdnz WriteAllGPRs

#if defined(OSGHSPPC)
  ; /* r3 should be set already in exception handler */
#elif defined(OSCWPPC)
  /*;*/ /* r3 should be set already in exception handler */
#endif
  e_bl          ErrM_OsErrorNotification
  e_b           Mcu_LLD_PerformReset
#if defined(OSGHSPPC)
  #pragma endasm
#endif
}

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
