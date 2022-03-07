/**
*   @file    Reg_eSys_DSPI.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - Reg eSys header file.
*   @details Reg eSys header file.

*   @addtogroup [SPI_MODULE]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : DSPI
*   Dependencies         : 
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20140606
*
*   (c) Copyright 2006-2014 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef REG_eSys_DSPI_H
#define REG_eSys_DSPI_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_DSPI_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7,
* A function should be used in preference to a function-like macro.
* Compiler abstraction need to implement function-like macros to hide
* compiler specifics from the implementation.
*
* @section Reg_eSys_DSPI_h_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Reg_eSys_DSPI_h_REF_3
* Violates MISRA 2004 Required Rule  8.12, This violation is not fixed since array size is defined
* base on number of DSPI hw units supported, which is platform dependent.
*
* @section Reg_eSys_DSPI_h_REF_4
* Violates MISRA 2004 Required Rule 19.10, Within a definition of a function-like macro, 
* the arguments shall be enclosed in parentheses.
*
* @section Reg_eSys_DSPI_h_REF_5
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
 *
 * @section Reg_eSys_DSPI_h_REF_6
* Violates MISRA 2004 Required Rule 19.4, This violation cannot be fixed since function and variables
* cannot be declared and defined within braces.
* For example:
* #define var  (variable)
* int var;
* In the above scenario, the var is replaced with (variable) i.e. it will become int (variable); ->This
* is not the syntax for variable declaration.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Reg_eSys_DSPI.c
* @requirements   BSW00374, BSW00318, SPI276.
*/
/*
* @violates @ref Reg_eSys_DSPI_h_REF_2 Precautions shall be taken in order to prevent the contents of a header 
* file being included twice.
*/
#include "Reg_eSys.h"
#include "Reg_Macros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define SPI_START_SEC_CONST_32
/*
* @violates @ref Reg_eSys_DSPI_h_REF_2 Precautions shall be taken in order to prevent the contents of a header 
* file being included twice.
*/
#include "MemMap.h"

/* HWUnit base address mapping array */
/* @violates @ref Reg_eSys_DSPI_h_REF_3 Violates MISRA 2004 Required Rule 8.12, Array declared with unknown size.*/
extern CONST(uint32, SPI_CONST) DSPI_BASE_ADDRS[];

#define SPI_STOP_SEC_CONST_32
/*
* @violates @ref Reg_eSys_DSPI_h_REF_2 Precautions shall be taken in order to prevent the contents of a header 
* file being included twice.
*/
#include "MemMap.h"
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief Macros used for low-level DSPI register manipulation (begin section).
*/
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*to a function-like macro.
*/
#define DSPI_GET_BASE_ADDRESS(offset) \
    ((uint32) (DSPI_BASE_ADDRS[(offset)]))

/* Mode control Register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_MCR(offset) \
    ((uint32) (DSPI_GET_BASE_ADDRESS(offset)))

/* Reserved Register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_HCR(offset) \
    ((uint32) (DSPI_GET_BASE_ADDRESS(offset) + 0x04u))

/* Transfer count */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TCR(offset) \
    ((uint32) (DSPI_GET_BASE_ADDRESS(offset) + 0x08u))

/* DSPI Clock and transfer attributes */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 Function-like macro defined
*/
/* DSPI Clock and transfer attributes */
#define DSPI_CTAR(offset) \
    ((uint32) (DSPI_GET_BASE_ADDRESS(offset) + 0x0Cu + (SPI_CTAR_USED * 0x04u)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_CTAR0(offset) \
    ((uint32) (DSPI_GET_BASE_ADDRESS(offset) + 0x0Cu))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_CTAR1(offset) \
    ((uint32) (DSPI_GET_BASE_ADDRESS(offset) + 0x10u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_CTAR2(offset) \
    ((uint32) (DSPI_GET_BASE_ADDRESS(offset) + 0x14u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 Function-like macro defined
*/
#define DSPI_BASEADDR2CTAR(base_addr) \
    ((uint32)((base_addr) + (0x0cu + (SPI_CTAR_USED * 0x04u))))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_CTAR3(offset) \
    ((uint32) (DSPI_GET_BASE_ADDRESS(offset) + 0x18u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_CTAR4(offset) \
    ((uint32) (DSPI_GET_BASE_ADDRESS(offset) + 0x1Cu))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_CTAR5(offset) \
    ((uint32) (DSPI_GET_BASE_ADDRESS(offset) + 0x20u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_CTAR6(offset) \
    ((uint32) (DSPI_GET_BASE_ADDRESS(offset) + 0x24u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_CTAR7(offset) \
    ((uint32) (DSPI_GET_BASE_ADDRESS(offset) + 0x28u))

/* DSPI Status register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_BASEADDR2SR(base_addr) \
    ((uint32)((base_addr) + 0x2Cu))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_SR(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x2Cu))

/* DSPI DMA/Interrupt request select and enable register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_RSER(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x30u))

/* DSPI Push TX FIFO Register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_BASEADDR2PUSHR(base_addr) \
    ((uint32)((base_addr) + 0x34u))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_PUSHR(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x34u))

/* DSPI Pop RX register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_BASEADDR2POPR(base_addr) \
    ((uint32)((base_addr) + 0x38u))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_POPR(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x38u))

/* DSPI Transmit FIFO Reg0 -3 */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TXFR0(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x3Cu))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TXFR1(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x40u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TXFR2(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x44u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TXFR3(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x48u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TXFR4(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x4Cu))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TXFR5(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x50u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TXFR6(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x54u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TXFR7(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x58u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TXFR8(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x5Cu))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TXFR9(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x60u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TXFR10(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x64u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TXFR11(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x68u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TXFR12(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x6Cu))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TXFR13(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x70u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TXFR14(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x74u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TXFR15(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x78u))


/* DSPI Receive FIFO Reg0-3 */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_RXFR0(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x7Cu))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_RXFR1(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x80u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_RXFR2(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x84u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_RXFR3(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x88u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_RXFR4(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x8Cu))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_RXFR5(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x90u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_RXFR6(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x94u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_RXFR7(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x98u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_RXFR8(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0x9Cu))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_RXFR9(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xA0u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_RXFR10(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xA4u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_RXFR11(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xA8u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_RXFR12(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xACu))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_RXFR13(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xB0u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_RXFR14(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xB4u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_RXFR15(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xB8u))

/* Not used for SPI module - driver/handler */

/* DSPI DSI Config register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xBCu))

/* DSPI DSI serialization data register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_SDR(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xC0u))

/* DSPI DSI alternate serialization data register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_ASDR(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xC4u))

/* DSPI DSI transmit comparison register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_COMPR(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xC8u))

/* DSPI DSI deserialization data register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DDR(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xCCu))

/* DSPI DSI Config register1 */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR1(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xD0u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_SSR(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xD4u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_PISR0(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xD8u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_PISR1(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xDCu))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_PISR2(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xE0u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_PISR3(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xE4u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DIMR(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xE8u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DPIR(offset) \
    ((uint32)(DSPI_GET_BASE_ADDRESS(offset) + 0xECu))
/*-----------------------------------------------------------------------*/
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*    to a function-like macro.
*/

/* Update register */
#define DSPI_MSTR           ((uint32) (0x80000000u))
#define DPSI_PCSSE          ((uint32) (0x02000000u))

/* DSPI MCR attributes */
#define DSPI_MCR_MSTR            ((uint32)0x80000000u)
#define DSPI_MCR_DCONF           ((uint32)0x30000000u)
#define DSPI_MCR_CONT_SCKE       ((uint32)0x40000000u)
#define DSPI_MCR_PCSIS_ALL       ((uint32)0x00FF0000u)

#ifdef TSB_MODE_SUPPORTED
/*Added for initialsation in TSB mode*/
#define DSPI_MCR_DCONF_DSI       ((uint32)0x10000000u)  /*DSI configuration of DSPI*/
#define DSPI_MCR_DCONF_CSI       ((uint32)0x20000000u)  /*CSI configuration of DSPI*/
#define DSPI_MCR_RX_FIFO         ((uint32)0x00001000u)  /*Receive FIFO*/
#define DSPI_MCR_TX_FIFO         ((uint32)0x00002000u)  /*Transmit FIFO*/
#define DSPI_MCR_HALT            ((uint32)0x00000001u)  /*Halt 0 : starts tranfer, 1: stops transfer*/
#endif /*TSB_MODE_SUPPORTED*/

#define DSPI_PCS0_IDLEHIGH       ((uint32)0x00010000u)
#define DSPI_PCS1_IDLEHIGH       ((uint32)0x00020000u)
#define DSPI_PCS2_IDLEHIGH       ((uint32)0x00040000u)
#define DSPI_PCS3_IDLEHIGH       ((uint32)0x00080000u)
#define DSPI_PCS4_IDLEHIGH       ((uint32)0x00100000u)
#define DSPI_PCS5_IDLEHIGH       ((uint32)0x00200000u)
#define DSPI_PCS6_IDLEHIGH       ((uint32)0x00400000u)
#define DSPI_PCS7_IDLEHIGH       ((uint32)0x00800000u)

#define DSPI_CLR_TXFIFO_MASK     ((uint32) (0x00000800u))
#define DSPI_CLR_RXFIFO_MASK     ((uint32) (0x00000400u))

/* Write to CTARx Register - Word access */
/* Individual flag write access shall be provided based LLD requirment */
/* Practically this file should provide write access to bits / nibble / bytes */
#define DSPI_FRAME_SIZE_MASK         ((uint32) 0x78000000u)
#define DSPI_CTAR_LSBFE_MASK         ((uint32) 0x01000000u)
#define DSPI_DBR_MASK                ((uint32) 0x80000000u)
#define DSPI_CPOL_MASK               ((uint32) 0x04000000u)
#define DSPI_CPHA_MASK               ((uint32) 0x02000000u)
#define DSPI_LSBFE_MASK              ((uint32) 0x01000000u)
#define DSPI_PCSSCK_MASK             ((uint32) 0x00C00000u)  /* 1, 3, 5 , 7 */
#define DSPI_PASC_MASK               ((uint32) 0x00300000u)
#define DSPI_PDT_MASK                ((uint32) 0x000C0000u)
#define DSPI_PBR_MASK                ((uint32) 0x00030000u)
#define DSPI_CSSCK_MASK              ((uint32) 0x0000F000u)
#define DSPI_ASC_MASK                ((uint32) 0x00000F00u)
#define DSPI_DT_MASK                 ((uint32) 0x000000F0u)
#define DSPI_BR_MASK                 ((uint32) 0x0000000Fu)

/*-----------Read DSPI Status Register-S--tart-------------------------------*/
#define DSPI_TCF_STS_MASK        ((uint32) 0x80000000u)
#define DSPI_TXRXS_STS_MASK      ((uint32) 0x40000000u)
#define DSPI_EOQF_STS_MASK       ((uint32) 0x10000000u)
#define DSPI_TUUF_STS_MASK       ((uint32) 0x08000000u)
#define DSPI_TFFF_STS_MASK       ((uint32) 0x02000000u)
#define DSPI_DPEF_STS_MASK       ((uint32) 0x00400000u)
#define DSPI_SPEF_STS_MASK       ((uint32) 0x00200000u)
#define DSPI_DDIF_STS_MASK       ((uint32) 0x00100000u)
#define DSPI_RFOF_STS_MASK       ((uint32) 0x00080000u)
#define DSPI_RFDF_STS_MASK       ((uint32) 0x00020000u)
#define DSPI_TXCTR_STS_MASK      ((uint32) 0x0000F000u)
#define DSPI_TXNXT_STS_MASK      ((uint32) 0x00000F00u)
#define DSPI_RXCTR_STS_MASK      ((uint32) 0x000000F0u)
#define DSPI_RXNXT_STS_MASK      ((uint32) 0x0000000Fu)

/*----Write to DSPI DMA/Interrupt Request Select and Enable - Start ----------*/
#define DSPI_TCF_RE_MASK     ((uint32) 0x80000000u)
#define DSPI_EOQF_RE_MASK    ((uint32) 0x10000000u)
#define DSPI_TFUF_RE_MASK    ((uint32) 0x08000000u)
#define DSPI_TFFF_RE_MASK    ((uint32) 0x02000000u)
#define DSPI_TFFF_DIRS_MASK  ((uint32) 0x01000000u)
#define DSPI_DPEF_RE_MASK    ((uint32) 0x00400000u)
#define DSPI_SPEF_RE_MASK    ((uint32) 0x00200000u)
#define DSPI_DDIF_RE_MASK    ((uint32) 0x00100000u)
#define DSPI_RFOF_RE_MASK    ((uint32) 0x00080000u)
#define DSPI_RFDF_RE_MASK    ((uint32) 0x00020000u)
#define DSPI_RFDF_DIRS_MASK  ((uint32) 0x00010000u)
#define DSPI_RSER_RESET_MASK ((uint32) 0x00000000u)

/* ---------------DSPI FIFO Transmit Register - Start ----------------------- */
#define DSPI_CONT_MASK           ((uint32) 0x80000000u)
#define DSPI_CTAS_MASK           ((uint32) 0x70000000u)
#define DSPI_EOQ_MASK            ((uint32) 0x08000000u)
#define DSPI_CTCNT_MASK          ((uint32) 0x04000000u)
#define DSPI_PE_MASK             ((uint32) 0x02000000u)
#define DSPI_PP_MASK             ((uint32) 0x01000000u)
#define DSPI_PCS7_MASK           ((uint32) 0x00800000u)
#define DSPI_PCS6_MASK           ((uint32) 0x00400000u)
#define DSPI_PCS5_MASK           ((uint32) 0x00200000u)
#define DSPI_PCS4_MASK           ((uint32) 0x00100000u)
#define DSPI_PCS3_MASK           ((uint32) 0x00080000u)
#define DSPI_PCS2_MASK           ((uint32) 0x00040000u)
#define DSPI_PCS1_MASK           ((uint32) 0x00020000u)
#define DSPI_PCS0_MASK           ((uint32) 0x00010000u)
#define DSPI_TXDATA_MASK         ((uint32) 0x0000FFFFu)

/* ---------------DSPI FIFO Receive Register - Start------------------------- */
#define DSPI_RXDATA_MASK             ((uint32) 0x0000FFFFu)

/* ---------------DSPI Transmit FIFO Register0-4 - Start---------------------- */
#define DSPI_TX_CMD_MASK             ((uint32) 0xFFFF0000u)

/* DSPI CTAR attributes */
#define DSPI_CTAR_DBR_0          ((uint32)0x00000000u)
#define DSPI_CTAR_DBR_1          ((uint32)0x80000000u)

#define DSPI_CTAR_CPOL_LOW       ((uint32)0x00000000u)
#define DSPI_CTAR_CPOL_HIGH      ((uint32)0x04000000u)

#define DSPI_CTAR_CPHA_LEADING   ((uint32)0x02000000u)
#define DSPI_CTAR_CPHA_TRAILING  ((uint32)0x00000000u)

#define DSPI_CTAR_MSB            ((uint32)0x00000000u)
#define DSPI_CTAR_LSB            ((uint32)0x01000000u)

#define DSPI_CTAR_PCSCLK_0       ((uint32)0x00000000u)
#define DSPI_CTAR_PCSCLK_1       ((uint32)0x00000000u)
#define DSPI_CTAR_PCSCLK_3       ((uint32)0x00400000u)
#define DSPI_CTAR_PCSCLK_5       ((uint32)0x00800000u)
#define DSPI_CTAR_PCSCLK_7       ((uint32)0x00C00000u)

#define DSPI_CTAR_PASC_0         ((uint32)0x00000000u)
#define DSPI_CTAR_PASC_1         ((uint32)0x00000000u)
#define DSPI_CTAR_PASC_3         ((uint32)0x00100000u)
#define DSPI_CTAR_PASC_5         ((uint32)0x00200000u)
#define DSPI_CTAR_PASC_7         ((uint32)0x00300000u)

#define DSPI_CTAR_PDT_0          ((uint32)0x00000000u)
#define DSPI_CTAR_PDT_1          ((uint32)0x00000000u)
#define DSPI_CTAR_PDT_3          ((uint32)0x00040000u)
#define DSPI_CTAR_PDT_5          ((uint32)0x00080000u)
#define DSPI_CTAR_PDT_7          ((uint32)0x000C0000u)

#define DSPI_CTAR_PBR_0          ((uint32)0x00000000u)
#define DSPI_CTAR_PBR_2          ((uint32)0x00000000u)
#define DSPI_CTAR_PBR_3          ((uint32)0x00010000u)
#define DSPI_CTAR_PBR_5          ((uint32)0x00020000u)
#define DSPI_CTAR_PBR_7          ((uint32)0x00030000u)

#define DSPI_CTAR_SCSCLK_0       ((uint32)0x00000000u)
#define DSPI_CTAR_SCSCLK_2       ((uint32)0x00000000u)
#define DSPI_CTAR_SCSCLK_4       ((uint32)0x00001000u)
#define DSPI_CTAR_SCSCLK_8       ((uint32)0x00002000u)
#define DSPI_CTAR_SCSCLK_16      ((uint32)0x00003000u)
#define DSPI_CTAR_SCSCLK_32      ((uint32)0x00004000u)
#define DSPI_CTAR_SCSCLK_64      ((uint32)0x00005000u)
#define DSPI_CTAR_SCSCLK_128     ((uint32)0x00006000u)
#define DSPI_CTAR_SCSCLK_256     ((uint32)0x00007000u)
#define DSPI_CTAR_SCSCLK_512     ((uint32)0x00008000u)
#define DSPI_CTAR_SCSCLK_1024    ((uint32)0x00009000u)
#define DSPI_CTAR_SCSCLK_2048    ((uint32)0x0000A000u)
#define DSPI_CTAR_SCSCLK_4096    ((uint32)0x0000B000u)
#define DSPI_CTAR_SCSCLK_8192    ((uint32)0x0000C000u)
#define DSPI_CTAR_SCSCLK_16384   ((uint32)0x0000D000u)
#define DSPI_CTAR_SCSCLK_32768   ((uint32)0x0000E000u)
#define DSPI_CTAR_SCSCLK_65536   ((uint32)0x0000F000u)

#define DSPI_CTAR_SASC_0         ((uint32)0x00000000u)
#define DSPI_CTAR_SASC_2         ((uint32)0x00000000u)
#define DSPI_CTAR_SASC_4         ((uint32)0x00000100u)
#define DSPI_CTAR_SASC_8         ((uint32)0x00000200u)
#define DSPI_CTAR_SASC_16        ((uint32)0x00000300u)
#define DSPI_CTAR_SASC_32        ((uint32)0x00000400u)
#define DSPI_CTAR_SASC_64        ((uint32)0x00000500u)
#define DSPI_CTAR_SASC_128       ((uint32)0x00000600u)
#define DSPI_CTAR_SASC_256       ((uint32)0x00000700u)
#define DSPI_CTAR_SASC_512       ((uint32)0x00000800u)
#define DSPI_CTAR_SASC_1024      ((uint32)0x00000900u)
#define DSPI_CTAR_SASC_2048      ((uint32)0x00000A00u)
#define DSPI_CTAR_SASC_4096      ((uint32)0x00000B00u)
#define DSPI_CTAR_SASC_8192      ((uint32)0x00000C00u)
#define DSPI_CTAR_SASC_16384     ((uint32)0x00000D00u)
#define DSPI_CTAR_SASC_32768     ((uint32)0x00000E00u)
#define DSPI_CTAR_SASC_65536     ((uint32)0x00000F00u)

#define DSPI_CTAR_SDT_0          ((uint32)0x00000000u)
#define DSPI_CTAR_SDT_2          ((uint32)0x00000000u)
#define DSPI_CTAR_SDT_4          ((uint32)0x00000010u)
#define DSPI_CTAR_SDT_8          ((uint32)0x00000020u)
#define DSPI_CTAR_SDT_16         ((uint32)0x00000030u)
#define DSPI_CTAR_SDT_32         ((uint32)0x00000040u)
#define DSPI_CTAR_SDT_64         ((uint32)0x00000050u)
#define DSPI_CTAR_SDT_128        ((uint32)0x00000060u)
#define DSPI_CTAR_SDT_256        ((uint32)0x00000070u)
#define DSPI_CTAR_SDT_512        ((uint32)0x00000080u)
#define DSPI_CTAR_SDT_1024       ((uint32)0x00000090u)
#define DSPI_CTAR_SDT_2048       ((uint32)0x000000A0u)
#define DSPI_CTAR_SDT_4096       ((uint32)0x000000B0u)
#define DSPI_CTAR_SDT_8192       ((uint32)0x000000C0u)
#define DSPI_CTAR_SDT_16384      ((uint32)0x000000D0u)
#define DSPI_CTAR_SDT_32768      ((uint32)0x000000E0u)
#define DSPI_CTAR_SDT_65536      ((uint32)0x000000F0u)

#define DSPI_CTAR_SBR_0          ((uint32)0x00000000u)
#define DSPI_CTAR_SBR_2          ((uint32)0x00000000u)
#define DSPI_CTAR_SBR_4          ((uint32)0x00000001u)
#define DSPI_CTAR_SBR_6          ((uint32)0x00000002u)
#define DSPI_CTAR_SBR_8          ((uint32)0x00000003u)
#define DSPI_CTAR_SBR_16         ((uint32)0x00000004u)
#define DSPI_CTAR_SBR_32         ((uint32)0x00000005u)
#define DSPI_CTAR_SBR_64         ((uint32)0x00000006u)
#define DSPI_CTAR_SBR_128        ((uint32)0x00000007u)
#define DSPI_CTAR_SBR_256        ((uint32)0x00000008u)
#define DSPI_CTAR_SBR_512        ((uint32)0x00000009u)
#define DSPI_CTAR_SBR_1024       ((uint32)0x0000000Au)
#define DSPI_CTAR_SBR_2048       ((uint32)0x0000000Bu)
#define DSPI_CTAR_SBR_4096       ((uint32)0x0000000Cu)
#define DSPI_CTAR_SBR_8192       ((uint32)0x0000000Du)
#define DSPI_CTAR_SBR_16384      ((uint32)0x0000000Eu)
#define DSPI_CTAR_SBR_32768      ((uint32)0x0000000Fu)

/* DSPI CMD attributes */
#define DSPI_CMD_CONTINOUS_FALSE  ((uint32)0x00000000u)
#define DSPI_CMD_CONTINOUS_TRUE   ((uint32)0x80000000u)

#define DSPI_CMD_CTAR_SEL        ((uint32)(SPI_CTAR_USED << 28u))
#define DSPI_CMD_CTAR_SEL_0     ((uint32)0x00000000u)
#define DSPI_CMD_CTAR_SEL_1     ((uint32)0x10000000u)
#define DSPI_CMD_CTAR_SEL_2     ((uint32)0x20000000u)
#define DSPI_CMD_CTAR_SEL_3     ((uint32)0x30000000u)
#define DSPI_CMD_CTAR_SEL_4     ((uint32)0x40000000u)
#define DSPI_CMD_CTAR_SEL_5     ((uint32)0x50000000u)
#define DSPI_CMD_CTAR_SEL_6     ((uint32)0x60000000u)
#define DSPI_CMD_CTAR_SEL_7     ((uint32)0x70000000u)

#define DSPI_CMD_MSB            ((uint32)0x00000000u)
#define DSPI_CMD_LSB            ((uint32)0x01000000u)

#define DSPI_CMD_WIDTH_4         ((uint32)0x18000000u)
#define DSPI_CMD_WIDTH_5         ((uint32)0x20000000u)
#define DSPI_CMD_WIDTH_6         ((uint32)0x28000000u)
#define DSPI_CMD_WIDTH_7         ((uint32)0x30000000u
#define DSPI_CMD_WIDTH_8         ((uint32)0x38000000u)
#define DSPI_CMD_WIDTH_9         ((uint32)0x40000000u)
#define DSPI_CMD_WIDTH_10        ((uint32)0x48000000u)
#define DSPI_CMD_WIDTH_11        ((uint32)0x50000000u)
#define DSPI_CMD_WIDTH_12        ((uint32)0x58000000u)
#define DSPI_CMD_WIDTH_13        ((uint32)0x60000000u)
#define DSPI_CMD_WIDTH_14        ((uint32)0x68000000u)
#define DSPI_CMD_WIDTH_15        ((uint32)0x70000000u)
#define DSPI_CMD_WIDTH_16        ((uint32)0x78000000u)

#define DSPI_CMD_PCS0            ((uint32)0x00010000u)
#define DSPI_CMD_PCS1            ((uint32)0x00020000u)
#define DSPI_CMD_PCS2            ((uint32)0x00040000u)
#define DSPI_CMD_PCS3            ((uint32)0x00080000u)
#define DSPI_CMD_PCS4            ((uint32)0x00100000u)
#define DSPI_CMD_PCS5            ((uint32)0x00200000u)
#define DSPI_CMD_PCS6            ((uint32)0x00400000u)
#define DSPI_CMD_PCS7            ((uint32)0x00800000u)

#ifdef TSB_MODE_SUPPORTED
/*DSI Configuration Register selects various attributes associated
with DSI and CSI Configurations.*/
/*TSBC bit enables the Timed Serial Bus Configuration.*/
#define DSPI_DSICR_TSBC           ((uint32)0x00100000u)
/*ctar3 selection*/
#define DSPI_DSICR_DSICTAS_CTAR3  ((uint32)0x00003000u)
#endif /*TSB_MODE_SUPPORTED*/

/**
* @brief Macros used for low-level DSPI register read/writes operations (begin section).
*/
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*    to a function-like macro.
*/
/* @violates @ref Reg_eSys_DSPI_h_REF_6 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */    
#define DSPI_LLM_MASTER_CONFIG(offset, value) { \
                           REG_RMW32(DSPI_MCR(offset),DSPI_MSTR,(value)); \
                           REG_BIT_SET32 (DSPI_MCR(offset),DSPI_MSTR); \
                         }

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_MCR_CONFIG(offset, value) \
    ( REG_WRITE32(DSPI_MCR(offset), (value)) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_MCR_PCSSE_SET(offset) \
    ( REG_BIT_SET32(DSPI_MCR(offset), DPSI_PCSSE) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_MCR_PCSSE_RESET(offset) \
    ( REG_BIT_CLEAR32(DSPI_MCR(offset), DPSI_PCSSE) )

#ifdef TSB_MODE_SUPPORTED
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_MCR_HALT_CLEAR(offset) \
    ( REG_BIT_CLEAR32(DSPI_MCR(offset), DSPI_MCR_HALT) )
#endif /*TSB_MODE_SUPPORTED*/

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_MCR_READ(offset) \
    ( REG_READ32(DSPI_MCR(offset) ) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SET_TXFIFO(offset) \
    (REG_BIT_SET32(DSPI_MCR(offset), DSPI_CLR_TXFIFO_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_CLR_TXFIFO(offset) \
    (REG_BIT_CLEAR32(DSPI_MCR(offset), DSPI_CLR_TXFIFO_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SET_RXFIFO(offset) \
    (REG_BIT_SET32(DSPI_MCR(offset), DSPI_CLR_RXFIFO_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_CLR_RXFIFO(offset) \
    (REG_BIT_CLEAR32(DSPI_MCR(offset), DSPI_CLR_RXFIFO_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_MCR_RESET(offset) \
    (REG_WRITE32(DSPI_MCR(offset), 0x00004001u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_CTAR0_READ(offset) \
    ( REG_READ32(DSPI_CTAR0(offset) ) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_CTAR0_CONFIG(offset, value) \
    ( REG_WRITE32(DSPI_CTAR0(offset),(value)))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_CTAR1_CONFIG(offset, value) \
    ( REG_WRITE32(DSPI_CTAR1(offset),(value)))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_CTAR2_CONFIG(offset, value) \
    ( REG_WRITE32(DSPI_CTAR2(offset),(value)))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_CTAR3_CONFIG(offset, value) \
    ( REG_WRITE32(DSPI_CTAR3(offset),(value)))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_CTAR4_CONFIG(offset, value) \
    ( REG_WRITE32(DSPI_CTAR4(offset),(value)))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_CTAR5_CONFIG(offset, value) \
    ( REG_WRITE32(DSPI_CTAR5(offset),(value)))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_CTAR6_CONFIG(offset, value) \
    ( REG_WRITE32(DSPI_CTAR6(offset),(value)))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_CTAR7_CONFIG(offset, value) \
    ( REG_WRITE32(DSPI_CTAR7(offset),(value)))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_CTAR0_FRAMESIZE(offset, value) \
    (REG_WRITE32( DSPI_CTAR0(offset), (value)) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_LSBFE(offset) \
    ( REG_BIT_SET32(DSPI_CTAR0(offset), DSPI_CTAR_LSBFE_MASK) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_MSBFE(offset) \
    ( REG_BIT_CLEAR32(DSPI_CTAR0(offset), DSPI_CTAR_LSBFE_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_DBR_SET(offset) \
    ( REG_BIT_SET32(DSPI_CTAR0(offset), DSPI_DBR_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_DBR_RESET(offset) \
    ( REG_BIT_CLEAR32(DSPI_CTAR0(offset), DSPI_DBR_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_CPOL_SCK_HIGH(offset) \
    ( REG_BIT_SET32(DSPI_CTAR0(offset), DSPI_CPOL_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_CPOL_SCK_LOW(offset) \
    ( REG_BIT_CLEAR32(DSPI_CTAR0(offset), DSPI_CPOL_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_ClK_PHASE_HIGH(offset) \
    ( REG_BIT_SET32(DSPI_CTAR0(offset), DSPI_CPHA_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_ClK_PHASE_LOW(offset) \
    ( REG_BIT_CLEAR32(DSPI_CTAR0(offset), DSPI_CPHA_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_LSBFE_SET(offset) \
    ( REG_BIT_SET32(DSPI_CTAR0(offset), DSPI_LSBFE_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_MSBFE_SET(offset) \
    ( REG_BIT_CLEAR32(DSPI_CTAR0(offset), DSPI_LSBFE_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_PCSSCK_DELAY(offset,value) \
    ( REG_WRITE32(DSPI_CTAR0(offset), (value) ) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_PASC_DELAY(offset,value) \
    ( REG_WRITE32(DSPI_CTAR0(offset), (value) ) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_PDT_DELAY(offset,value) \
    ( REG_WRITE32(DSPI_CTAR0(offset), (value) ) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_PBR_DELAY(offset,value) \
    ( REG_WRITE32(DSPI_CTAR0(offset), (value) ) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_CSSCK_DELAY(offset,value) \
    ( REG_WRITE32(DSPI_CTAR0(offset), (value) ) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_ASC_DELAY(offset,value) \
    ( REG_WRITE32(DSPI_CTAR0(offset), (value) ) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_DT_DELAY(offset,value) \
    ( REG_WRITE32(DSPI_CTAR0(offset), (value) ) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WR_BR_DELAY(offset,value) \
    ( REG_WRITE32(DSPI_CTAR0(offset), (value) ) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_RESET_CTAR_REG(offset) \
    ( REG_WRITE32(DSPI_CTAR(offset),0x78000000))    
    
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_RESET_CTAR0_REG(offset) \
    ( REG_WRITE32(DSPI_CTAR0(offset),0x78000000))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_RESET_CTAR1_REG(offset) \
    ( REG_WRITE32(DSPI_CTAR1(offset),0x78000000))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_RESET_CTAR2_REG(offset) \
    ( REG_WRITE32(DSPI_CTAR2(offset),0x78000000))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_RESET_CTAR3_REG(offset) \
    ( REG_WRITE32(DSPI_CTAR3(offset),0x78000000))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_RESET_CTAR4_REG(offset) \
    ( REG_WRITE32(DSPI_CTAR4(offset),0x78000000))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_RESET_CTAR5_REG(offset) \
    ( REG_WRITE32(DSPI_CTAR5(offset),0x78000000))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_RESET_CTAR6_REG(offset) \
    ( REG_WRITE32(DSPI_CTAR6(offset),0x78000000))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_RESET_CTAR7_REG(offset) \
    ( REG_WRITE32(DSPI_CTAR7(offset),0x78000000))

/* ---------- Read transfer count register to manage queue --Start ---------- */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TCR(offset)  (REG_READ32(DSPIC_TCR(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_RESET_TCR(offset) (REG_WRITE32(DSPI_TCR(offset),0x00000000))

/* ---------- Read transfer count register to manage queue --End-- ---------- */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define READ_TCF_BIT(offset)  (REG_READ32(DSPI_SR(offset) ) & DSPI_TCF_STS_MASK)
/* Read TCF bit */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TCF_BIT(offset) \
    ((DSPI_TCF_STS_MASK == (REG_READ32(DSPI_SR(offset)) & DSPI_TCF_STS_MASK )) \
        ? TRUE : FALSE )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_TCF_RESET(offset) \
    (REG_WRITE32(DSPI_SR(offset), DSPI_TCF_STS_MASK) )

/* Read TXRXS bit */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXRXS_BIT(offset) \
    ((DSPI_TXRXS_STS_MASK == (REG_READ32(DSPI_SR(offset)) & DSPI_TXRXS_STS_MASK)) \
        ? TRUE : FALSE )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SET_TXRXS_BIT(offset) \
    ( REG_WRITE32(DSPI_SR(offset), DSPI_TXRXS_STS_MASK))

/* Read EQOF bit */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_EOQF_BIT(offset) \
    ((DSPI_EOQF_STS_MASK == (REG_READ32(DSPI_SR(offset)) & DSPI_EOQF_STS_MASK))\
        ? TRUE : FALSE)

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_CLEAR_EOQF(offset) \
    (REG_WRITE32(DSPI_SR(offset), DSPI_EOQF_STS_MASK))

/* Read TFUF bit */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TFUF_BIT(offset) \
    ((DSPI_TUUF_STS_MASK == (REG_READ32(DSPI_SR(offset)) & DSPI_TUUF_STS_MASK))\
        ? TRUE : FALSE)

/* Read TFFF bit */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TFFF_BIT(offset) \
    ((DSPI_TFFF_STS_MASK == (REG_READ32(DSPI_SR(offset)) & DSPI_TFFF_STS_MASK))\
        ? TRUE : FALSE)

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_CLEAR_TFFF_BIT(offset) \
    ( REG_WRITE32(DSPI_SR(offset), DSPI_TFFF_STS_MASK))

/* Read RFOF bit */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RFOF_BIT(offset) \
    ((DSPI_RFOF_STS_MASK == (REG_READ32(DSPI_SR(offset)) & DSPI_RFOF_STS_MASK))\
        ? TRUE : FALSE)

/* Read RFOF bit */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RFDF_BIT(offset) \
    ((DSPI_RFDF_STS_MASK == (REG_READ32(DSPI_SR(offset)) & DSPI_RFDF_STS_MASK))\
        ? TRUE : FALSE)

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_CLEAR_RFDF_BIT(offset) \
    ( REG_WRITE32(DSPI_SR(offset), DSPI_RFDF_STS_MASK))

/* Read TXCTR FIFO value - Nibble */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXCTR_VAL(offset) \
    ( ( ( REG_READ32(DSPI_SR(offset) ) & DSPI_TXCTR_STS_MASK) >> 12 ))

/* Read TXNXT FIFO value - Nibble */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXNXT_VAL(offset) \
    ( ( ( REG_READ32(DSPI_SR(offset) ) & DSPI_TXNXT_STS_MASK) >> 8 ))

/* Read RXCTR FIFO value - Nibble */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RXCTR_VAL(offset) \
    ( ( ( REG_READ32(DSPI_SR(offset) ) & DSPI_RXCTR_STS_MASK) >> 4 ))

/* Read POPNXT RX FIFO value - Nibble */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RXNXT_VAL(offset) \
    ( ( ( REG_READ32(DSPI_SR(offset) ) & DSPI_RXNXT_STS_MASK) ) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_RESET_STATUS_REG(offset) \
    ( REG_WRITE32(DSPI_SR(offset), 0x10020000))
/*-----------Read DSPI Status Register -End-----------------------------------*/

/* Complete Word write access */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_WRITE_RSER_REG(offset,value) \
    ( REG_WRITE32(DSPI_RSER(offset), (value)))

/* Reset RSER register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_RESET_RSER_REG(offset) \
    ( REG_WRITE32(DSPI_RSER(offset), DSPI_RSER_RESET_MASK) )

/* Enable TCF bit */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_ENABLE_TCF(offset) \
    ( REG_BIT_SET32(DSPI_RSER(offset), DSPI_TCF_RE_MASK) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_DISABLE_TCF(offset) \
    ( REG_BIT_CLEAR32(DSPI_RSER(offset), DSPI_TCF_RE_MASK) )
/* Enable EOQF bit */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_ENABLE_EOQF(offset) \
    ( REG_BIT_SET32(DSPI_RSER(offset), DSPI_EOQF_RE_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_DISABLE_EOQF(offset) \
    ( REG_BIT_CLEAR32(DSPI_RSER(offset), DSPI_EOQF_RE_MASK))

/* Enable TFUF bit */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_ENABLE_TFUF(offset) \
    ( REG_BIT_SET32(DSPI_RSER(offset), DSPI_TFUF_RE_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_DISABLE_TFUF(offset) \
    ( REG_BIT_CLEAR32(DSPI_RSER(offset), DSPI_TFUF_RE_MASK))

/* Enable/disable of TFFFRE bit */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_ENABLE_TFFFRE(offset) \
    ( REG_BIT_SET32(DSPI_RSER(offset), DSPI_TFFF_RE_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_DISABLE_TFFFRE(offset) \
    ( REG_BIT_CLEAR32(DSPI_RSER(offset), DSPI_TFFF_RE_MASK))

/* Enable TFFF_DIRS bit */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_ENABLE_TFFF_DIRS(offset) \
    ( REG_BIT_SET32(DSPI_RSER(offset), DSPI_TFFF_DIRS_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_DISABLE_TFFF_DIRS(offset) \
    ( REG_BIT_CLEAR32(DSPI_RSER(offset), DSPI_TFFF_DIRS_MASK))

/* Enable RFOF bit */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_ENABLE_RFOF(offset) \
    ( REG_BIT_SET32(DSPI_RSER(offset), DSPI_RFOF_RE_MASK) )

/* Enable RFDF bit */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_ENABLE_RFDF(offset) \
    ( REG_BIT_SET32(DSPI_RSER(offset), DSPI_RFDF_RE_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_DISABLE_RFDF(offset) \
    ( REG_BIT_CLEAR32(DSPI_RSER(offset), DSPI_RFDF_RE_MASK))

/* Enable RFDF_DIRS bit */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_ENABLE_RFDF_DIRS(offset) \
    ( REG_BIT_SET32(DSPI_RSER(offset), DSPI_RFDF_DIRS_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_DISABLE_RFDF_DIRS(offset) \
    ( REG_BIT_CLEAR32(DSPI_RSER(offset), DSPI_RFDF_DIRS_MASK))
/*----Write to DSPI DMA/Interrupt Request Select and Enable - End-----------*/

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_TX_FIFO_READ(offset)   (REG_READ32(DSPI_PUSHR(offset)))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SELECT_CONT_PHPRl_CS(offset) \
    ( REG_BIT_SET32(DSPI_PUSHR(offset), DSPI_CONT_MASK))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
 /*
* @violates @ref Reg_eSys_DSPI_h_REF_5 This is required as per autosar Requirement, 
*/
#define DSPI_LLM_SELECT_CONT_PHPRl_CS_RESET(offset) \
    ( REG_BIT_CLEAR32(DSPI_PUSHR(offset), DSPI_CONT_MASK) )

/* value: MIN = 0x00, Max = 0x07 - defines the CTAR<x> Register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SELECT_TX_REG(offset, value) \
    ( REG_WRITE32(DSPI_PUSHR(offset), (value) ) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_CTAS_READ(offset) \
    ( REG_READ32(DSPI_PUSHR(offset) & DSPI_CTAS_MASK ) )

/* Enable End of Queue flag */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SET_EOQ_FLAG(offset) \
    ( REG_BIT_SET32(DSPI_PUSHR(offset), DSPI_EOQ_MASK) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_RESET_TCNT_FLAG(offset) \
    ( REG_BIT_SET32(DSPI_PUSHR(offset), DSPI_CTCNT_MASK) )

/* Enable Peripheral Chip select 0 - 7 */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SELECT_PCS7(offset) \
    ( REG_BIT_SET32(DSPI_PUSHR(offset), DSPI_PCS7_MASK) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SELECT_PCS6(offset) \
    ( REG_BIT_SET32(DSPI_PUSHR(offset), DSPI_PCS6_MASK) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SELECT_PCS5(offset) \
    ( REG_BIT_SET32(DSPI_PUSHR(offset), DSPI_PCS5_MASK) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SELECT_PCS4(offset) \
    ( REG_BIT_SET32(DSPI_PUSHR(offset), DSPI_PCS4_MASK) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SELECT_PCS3(offset) \
    ( REG_BIT_SET32(DSPI_PUSHR(offset), DSPI_PCS3_MASK) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SELECT_PCS2(offset) \
    ( REG_BIT_SET32(DSPI_PUSHR(offset), DSPI_PCS2_MASK) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SELECT_PCS1(offset) \
    ( REG_BIT_SET32(DSPI_PUSHR(offset), DSPI_PCS1_MASK) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SELECT_PCS0(offset) \
    ( REG_BIT_SET32(DSPI_PUSHR(offset), DSPI_PCS0_MASK) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SELECT_PCS7_RESET(offset) \
    ( REG_BIT_CLEAR32(DSPI_PUSHR(offset), DSPI_PCS7_MASK) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SELECT_PCS6_RESET(offset) \
    ( REG_BIT_CLEAR32(DSPI_PUSHR(offset), DSPI_PCS6_MASK) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SELECT_PCS5_RESET(offset) \
    ( REG_BIT_CLEAR32(DSPI_PUSHR(offset), DSPI_PCS5_MASK) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SELECT_PCS4_RESET(offset) \
    ( REG_BIT_CLEAR32(DSPI_PUSHR(offset), DSPI_PCS4_MASK) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SELECT_PCS3_RESET(offset) \
    ( REG_BIT_CLEAR32(DSPI_PUSHR(offset), DSPI_PCS3_MASK) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SELECT_PCS2_RESET(offset) \
    ( REG_BIT_CLEAR32(DSPI_PUSHR(offset), DSPI_PCS2_MASK) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SELECT_PCS1_RESET(offset) \
    ( REG_BIT_CLEAR32(DSPI_PUSHR(offset), DSPI_PCS1_MASK) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_SELECT_PCS0_RESET(offset) \
    ( REG_BIT_CLEAR32(DSPI_PUSHR(offset), DSPI_PCS0_MASK) )

/* Transmit Data on selected SPI buffer */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_TXDATA(offset, value) \
    ( REG_WRITE32(DSPI_PUSHR(offset),(value)) )

/* Reset FIFO Transmit Register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_RESET_FIFO_TX_REG(offset) \
    ( REG_WRITE32(DSPI_MCR(offset),DSPI_CLR_TXFIFO_MASK))
/* ---------------DSPI FIFO Transmit Register - End-------------------------- */

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_RXDATA(offset)     (REG_READ32 (DSPI_POPR(offset)))

/* ---------------DSPI Transmit FIFO Register0-15 - Start---------------------- */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXCMD0(offset) \
    ( ( ( REG_READ32 (DSPI_TXFR0(offset)) & DSPI_TX_CMD_MASK ) >> 16) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXCMD1(offset) \
    ( ( ( REG_READ32 (DSPI_TXFR1(offset)) & DSPI_TX_CMD_MASK ) >> 16) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXCMD2(offset) \
    ( ( ( REG_READ32 (DSPI_TXFR2(offset)) & DSPI_TX_CMD_MASK ) >> 16) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXCMD3(offset) \
    ( ( ( REG_READ32 (DSPI_TXFR3(offset)) & DSPI_TX_CMD_MASK ) >> 16) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXCMD4(offset) \
    ( ( ( REG_READ32 (DSPI_TXFR4(offset)) & DSPI_TX_CMD_MASK ) >> 16) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXCMD5(offset) \
    ( ( ( REG_READ32 (DSPI_TXFR5(offset)) & DSPI_TX_CMD_MASK ) >> 16) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXCMD6(offset) \
    ( ( ( REG_READ32 (DSPI_TXFR6(offset)) & DSPI_TX_CMD_MASK ) >> 16) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXCMD7(offset) \
    ( ( ( REG_READ32 (DSPI_TXFR7(offset)) & DSPI_TX_CMD_MASK ) >> 16) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXCMD8(offset) \
    ( ( ( REG_READ32 (DSPI_TXFR8(offset)) & DSPI_TX_CMD_MASK ) >> 16) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXCMD9(offset) \
    ( ( ( REG_READ32 (DSPI_TXFR9(offset)) & DSPI_TX_CMD_MASK ) >> 16) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXCMD10(offset) \
    ( ( ( REG_READ32 (DSPI_TXFR10(offset)) & DSPI_TX_CMD_MASK ) >> 16) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXCMD11(offset) \
    ( ( ( REG_READ32 (DSPI_TXFR11(offset)) & DSPI_TX_CMD_MASK ) >> 16) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXCMD12(offset) \
    ( ( ( REG_READ32 (DSPI_TXFR12(offset)) & DSPI_TX_CMD_MASK ) >> 16) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXCMD13(offset) \
    ( ( ( REG_READ32 (DSPI_TXFR13(offset)) & DSPI_TX_CMD_MASK ) >> 16) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXCMD14(offset) \
    ( ( ( REG_READ32 (DSPI_TXFR14(offset)) & DSPI_TX_CMD_MASK ) >> 16) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXCMD15(offset) \
    ( ( ( REG_READ32 (DSPI_TXFR15(offset)) & DSPI_TX_CMD_MASK ) >> 16) )

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXDATA0(offset)     (REG_READ16 (DSPI_TXFR0(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXDATA1(offset)     (REG_READ16 (DSPI_TXFR1(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXDATA2(offset)     (REG_READ16 (DSPI_TXFR2(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXDATA3(offset)     (REG_READ16 (DSPI_TXFR3(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXDATA4(offset)     (REG_READ16 (DSPI_TXFR4(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXDATA5(offset)     (REG_READ16 (DSPI_TXFR5(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXDATA6(offset)     (REG_READ16 (DSPI_TXFR6(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXDATA7(offset)     (REG_READ16 (DSPI_TXFR7(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXDATA8(offset)     (REG_READ16 (DSPI_TXFR8(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXDATA9(offset)     (REG_READ16 (DSPI_TXFR9(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXDATA10(offset)    (REG_READ16 (DSPI_TXFR10(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXDATA11(offset)    (REG_READ16 (DSPI_TXFR11(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXDATA12(offset)    (REG_READ16 (DSPI_TXFR12(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXDATA13(offset)    (REG_READ16 (DSPI_TXFR13(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXDATA14(offset)    (REG_READ16 (DSPI_TXFR14(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_TXDATA15(offset)    (REG_READ16 (DSPI_TXFR15(offset)))
/* ---------------DSPI Transmit FIFO Register0-15 - End-------------------------- */

/* ---------------DSPI Receive FIFO Register0-15 - Start---------------------- */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RXDATA0(offset)     (REG_READ32 (DSPI_RXFR0(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RXDATA1(offset)     (REG_READ32 (DSPI_RXFR1(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RXDATA2(offset)     (REG_READ32 (DSPI_RXFR2(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RXDATA3(offset)     (REG_READ32 (DSPI_RXFR3(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RXDATA4(offset)     (REG_READ32 (DSPI_RXFR4(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RXDATA5(offset)     (REG_READ32 (DSPI_RXFR5(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RXDATA6(offset)     (REG_READ32 (DSPI_RXFR6(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RXDATA7(offset)     (REG_READ32 (DSPI_RXFR7(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RXDATA8(offset)     (REG_READ32 (DSPI_RXFR8(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RXDATA9(offset)     (REG_READ32 (DSPI_RXFR9(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RXDATA10(offset)    (REG_READ32 (DSPI_RXFR10(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RXDATA11(offset)    (REG_READ32 (DSPI_RXFR11(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RXDATA12(offset)    (REG_READ32 (DSPI_RXFR12(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RXDATA13(offset)    (REG_READ32 (DSPI_RXFR13(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RXDATA14(offset)    (REG_READ32 (DSPI_RXFR14(offset)))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_READ_RXDATA15(offset)    (REG_READ32 (DSPI_RXFR15(offset)))
/* ---------------DSPI Receive FIFO Register0-15 - End------------------------ */

#ifdef TSB_MODE_SUPPORTED
/*----------------DSPI DSI Configuration Register DSPI_DSICR -----------------------------*/
/*Timed Serial Bus Configuration enabled*/
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_TXSS_SET       ((uint32)0x00080000u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_TXSS_CLEAR     ((uint32)0x00000000u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CID_SET        ((uint32)0x00010000u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CID_CLEAR      ((uint32)0x00000000u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CS_DPCS0       ((uint32)0x00000001u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CS_DPCS1       ((uint32)0x00000002u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CS_DPCS2       ((uint32)0x00000004u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CS_DPCS3       ((uint32)0x00000008u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CS_DPCS4       ((uint32)0x00000010u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CS_DPCS5       ((uint32)0x00000020u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CS_DPCS6       ((uint32)0x00000040u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CS_DPCS7       ((uint32)0x00000080u)

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_DSICR_TSBC_SET(offset) \
    ( REG_BIT_SET32(DSPI_DSICR(offset), DSPI_DSICR_TSBC))

 /*Timed Serial Bus Configuration disabled*/
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_DSICR_TSBC_CLEAR(offset) \
    ( REG_BIT_CLEAR32(DSPI_DSICR(offset), DSPI_DSICR_TSBC))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_DSICR_DSICTAS_CTAR3(offset) \
    ( REG_BIT_SET32(DSPI_DSICR(offset), DSPI_DSICR_DSICTAS_CTAR3))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_DSICR_CONFIG(offset, value) \
    ( REG_WRITE32(DSPI_DSICR(offset), (value)) )

/*----------------DSPI DSI Configuration Register1 DSPI_DSICR1 -----------------------------*/
#define DSPI_DSICR1_CS_DPCS0       ((uint32)0x00000001u)
#define DSPI_DSICR1_CS_DPCS1       ((uint32)0x00000002u)
#define DSPI_DSICR1_CS_DPCS2       ((uint32)0x00000004u)
#define DSPI_DSICR1_CS_DPCS3       ((uint32)0x00000008u)
#define DSPI_DSICR1_CS_DPCS4       ((uint32)0x00000010u)
#define DSPI_DSICR1_CS_DPCS5       ((uint32)0x00000020u)
#define DSPI_DSICR1_CS_DPCS6       ((uint32)0x00000040u)
#define DSPI_DSICR1_CS_DPCS7       ((uint32)0x00000080u)
#define DSPI_DSICR1_TSBCNT_3       ((uint32)0x03000000u)
#define DSPI_DSICR1_TSBCNT_4       ((uint32)0x04000000u)
#define DSPI_DSICR1_TSBCNT_5       ((uint32)0x05000000u)
#define DSPI_DSICR1_TSBCNT_6       ((uint32)0x06000000u)
#define DSPI_DSICR1_TSBCNT_7       ((uint32)0x07000000u)
#define DSPI_DSICR1_TSBCNT_8       ((uint32)0x08000000u)
#define DSPI_DSICR1_TSBCNT_9       ((uint32)0x09000000u)
#define DSPI_DSICR1_TSBCNT_10      ((uint32)0x0A000000u)
#define DSPI_DSICR1_TSBCNT_11      ((uint32)0x0B000000u)
#define DSPI_DSICR1_TSBCNT_12      ((uint32)0x0C000000u)
#define DSPI_DSICR1_TSBCNT_13      ((uint32)0x0D000000u)
#define DSPI_DSICR1_TSBCNT_14      ((uint32)0x0E000000u)
#define DSPI_DSICR1_TSBCNT_15      ((uint32)0x0F000000u)
#define DSPI_DSICR1_TSBCNT_16      ((uint32)0x10000000u)
#define DSPI_DSICR1_TSBCNT_17      ((uint32)0x11000000u)
#define DSPI_DSICR1_TSBCNT_18      ((uint32)0x12000000u)
#define DSPI_DSICR1_TSBCNT_19      ((uint32)0x13000000u)
#define DSPI_DSICR1_TSBCNT_20      ((uint32)0x14000000u)
#define DSPI_DSICR1_TSBCNT_21      ((uint32)0x15000000u)
#define DSPI_DSICR1_TSBCNT_22      ((uint32)0x16000000u)
#define DSPI_DSICR1_TSBCNT_23      ((uint32)0x17000000u)
#define DSPI_DSICR1_TSBCNT_24      ((uint32)0x18000000u)
#define DSPI_DSICR1_TSBCNT_25      ((uint32)0x19000000u)
#define DSPI_DSICR1_TSBCNT_26      ((uint32)0x1A000000u)
#define DSPI_DSICR1_TSBCNT_27      ((uint32)0x1B000000u)
#define DSPI_DSICR1_TSBCNT_28      ((uint32)0x1C000000u)
#define DSPI_DSICR1_TSBCNT_29      ((uint32)0x1D000000u)
#define DSPI_DSICR1_TSBCNT_30      ((uint32)0x1E000000u)
#define DSPI_DSICR1_TSBCNT_31      ((uint32)0x1F000000u)
#define DSPI_DUALRECEIVER_DISABLED ((uint32)0x00000000u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_DSICR1_CONFIG(offset, value) \
    ( REG_WRITE32(DSPI_DSICR1(offset), (value)) )

/*----------------DSPI CTAR3 Clock and Transfer Attributes Register3  -----------------------------*/
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_CTAR3_WR_LSBFE(offset) \
    ( REG_BIT_SET32(DSPI_CTAR3(offset), DSPI_CTAR_LSBFE_MASK) )

/*----------------DSPI ASDR Alternate Serialisation Data Register  -----------------------------*/
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_LLM_ASDR_CONFIG(offset, value) \
    ( REG_WRITE32(DSPI_ASDR(offset), (value)) )
#endif /*TSB_MODE_SUPPORTED*/


/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* REG_eSys_DSPI_H */



/** @} */


