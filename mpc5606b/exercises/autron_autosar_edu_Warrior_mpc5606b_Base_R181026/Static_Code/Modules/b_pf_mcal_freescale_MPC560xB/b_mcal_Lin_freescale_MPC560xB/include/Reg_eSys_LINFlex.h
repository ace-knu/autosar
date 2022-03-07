/**
*   @file    Reg_eSys_LINFlex.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - LINFlex Registers and Macros Definitions.
*   @details Header file for LINFlex Registers and Macros Definitions.
*
*   @addtogroup LIN
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : LINFlex
*   Dependencies         : 
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF5_ASR_REL_4_0_REV_0003_20140822
*
*   (c) Copyright 2006-2014 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef REG_eSys_LINFlex_H
#define REG_eSys_LINFlex_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_LINFlex_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, This violation is due to function
* like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Reg_eSys_LINFlex_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Reg_eSys_LINFlex_h_REF_3
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Reg_eSys_LINFlex_h_REF_4
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal
* and external) shall not rely on the significance of more 
* than 31 characters.
*
* @section Reg_eSys_LINFlex_h_REF_5
* Violates MISRA 2004 Required Rule  8.12, Array declared with unknown size.
*
* @section Reg_eSys_LINFlex_h_REF_6
* Violates MISRA 2004 Required Rule 19.10, Within a definition of a function-like macro, 
* the arguments shall be enclosed in parentheses.
*
* @section Reg_eSys_LINFlex_h_REF_7
* Violates MISRA 2004 Required Rule 19.4, : C macros shall only expand to
* a braced initializer, a constant, a string literal, a parenthesized expression, 
* a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_LINFlex.h
* @implements     DLIN04202
*/
#define LIN_VENDOR_ID_REGFLEX                    43

/* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_MAJOR_VERSION_REGFLEX     4

/* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_MINOR_VERSION_REGFLEX     0
/*
* @violates @ref Reg_eSys_LINFlex_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_REVISION_VERSION_REGFLEX  3
#define LIN_SW_MAJOR_VERSION_REGFLEX             1
#define LIN_SW_MINOR_VERSION_REGFLEX             0
#define LIN_SW_PATCH_VERSION_REGFLEX             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief    IPV_LINFLEX macro definition.
* @details  Generic define for LINFLEX2 IP class.
*/
#define IPV_LINFLEX_00_10_00  (0x00001362UL)

/**
* @brief    IPV_LINFLEX macro definition.
* @details  Generic define for LINFLEX3 IP class.
*/
#define IPV_LINFLEX_03_00_00  (0x0003006DUL)

#define IPV_LINFLEX_04_00_00  (0x00040000UL)

/* sveral settings of the low level driver depends on the LINFlex IP hw version                   */
/* IPV_LINFLEX_00_10_00 - Spectrum/Bolero implementation                                          */
/* IPV_LINFLEX_03_00_00 - Leopard implementation                                                  */
/* IPV_LINFLEX_xx_xx_xx - ....                                                                    */
/*                                                                                                */
/* IPV_LINFLEX shall be defined in Reg_eSys.h file with the appropriate value                     */
/* because this convention started with Leopard and in order to keep the backward compatibility   */
/* the following 3 lines defines the default value for IPV_LINFLEX                                */
/* the only rule you need to follow is to include Reg_eSys.h before Reg_eSys_LINFlex.h in any     */
/* c source file                                                                                  */
#ifndef IPV_LINFLEX
    /*#define IPV_LINFLEX IPV_LINFLEX_00_10_00*/
    #error "IPV_LINFLEX not defined"
#endif

#define LIN_START_SEC_CONST_32
/** 
* @violates @ref Reg_eSys_LINFlex_h_REF_3 #include statements in a file should
*                only be preceded by other preprocessor directives or comments.
*/
#include "MemMap.h"

/** 
* @violates @ref Reg_eSys_LINFlex_h_REF_5 Violates MISRA 2004 Required
*                Rule 8.8, Array declared with unknown size.
*/
extern CONST(uint32, LIN_CONST) LIN_BASE_ADDRESS[];

#define LIN_STOP_SEC_CONST_32
/** 
* @violates @ref Reg_eSys_LINFlex_h_REF_3 #include statements in a file should
*                only be preceded by other preprocessor directives or comments.
*/
#include "MemMap.h"
/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access base addresses of LINFlex IPs.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
*/
#define LIN_GET_BASE_ADDRESS(offset) ((uint32)( LIN_BASE_ADDRESS[offset] ))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Control Register 1 (LINCR1).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINCR1(offset)    ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x00uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Interrupt Enable Register (LINIER).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINIER(offset)    ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x04uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Status Register (LINSR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINSR(offset)     ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x08uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Error Status Register (LINESR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINESR(offset)    ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x0CuL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register UART Mode Control Register (UARTCR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_UARTCR(offset)    ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x10uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register UART Mode Status Register (UARTSR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_UARTSR(offset)    ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x14uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Time-Out Control Status Register (LINTCSR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINTCSR(offset)   ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x18uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Output Compare Register (LINOCR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINOCR(offset)    ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x1CuL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Time-Out Control Register (LINTOCR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINTOCR(offset)   ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x20uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Fractional Baud Rate Register (LINFBRR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINFBRR(offset)   ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x24uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Integer Baud Rate Register (LINIBRR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINIBRR(offset)   ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x28uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Checksum Field Register (LINCFR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINCFR(offset)    ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x2CuL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Control Register 2 (LINCR2).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINCR2(offset)    ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x30uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register Buffer Identifier Register (BIDR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_BIDR(offset)      ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x34uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register Buffer Data Register Least Significant (BDRL).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_BDRL(offset)      ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x38uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register Buffer Data Register Most Significant (BDRM).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_BDRM(offset)      ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x3CuL))


/*=============== additional registers for LINFlex3 IP ================================*/
#if IPV_LINFLEX >= IPV_LINFLEX_03_00_00

    /**
    * @brief    LINFLEX Registers macro definition.
    * @details  LINFLEX macro to access register Global control register (GCR).
    * @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    */
    #define LINFLEX_GCR(offset)       ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x8CuL))

    /**
    * @brief    LINFLEX Registers macro definition.
    * @details  LINFLEX macro to access register UART preset timeout register (UARTPTO).
    * @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    */
    #define LINFLEX_UARTPTO(offset)   ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x90uL))

    /**
    * @brief    LINFLEX Registers macro definition.
    * @details  LINFLEX macro to access register UART current timeout register (UARTCTO).
    * @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    */
    #define LINFLEX_UARTCTO(offset)   ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x94uL))

    /**
    * @brief    LINFLEX Registers macro definition.
    * @details  LINFLEX macro to access register DMA Tx enable register (DMATXE).
    * @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    */
    #define LINFLEX_DMATXE(offset)    ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x98uL))

    /**
    * @brief    LINFLEX Registers macro definition.
    * @details  LINFLEX macro to access register DMA Rx enable register (DMARXE).
    * @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    */
    #define LINFLEX_DMARXE(offset)    ((uint32)(LIN_GET_BASE_ADDRESS(offset) + 0x9CuL))

#endif
/*=============== end additional registers for LINFlex3 IP ============================*/

/**
* @brief    LINFLEX Registers bits.
* @details  LINCR1 register bit masks.
*/
#define LINFLEX_LINCR1_INIT_MASK  (0x00000001UL)
#define LINFLEX_LINCR1_SLEEP_MASK (0x00000002UL)
#define LINFLEX_LINCR1_MME_MASK   (0x00000010UL)
#define LINFLEX_LINCR1_LBKM_MASK  (0x00000020UL)
#define LINFLEX_LINCR1_SFTM_MASK  (0x00000040UL)
#define LINFLEX_LINCR1_BF_MASK    (0x00000080UL)
#define LINFLEX_LINCR1_MBL_MASK   (0x00000F00UL)
#define LINFLEX_LINCR1_AWUM_MASK  (0x00001000UL)
#define LINFLEX_LINCR1_CFD_MASK   (0x00004000UL)
#define LINFLEX_LINCR1_CCD_MASK   (0x00008000UL)
#define LINFLEX_LINCR1_RESET_MASK (0x00000083UL)

/**
* @brief    LINFLEX Registers bits.
* @details  LIN master break length selection register bit masks.
*/
#define LINFLEX_LINCR1_MBL_10_BITS_MASK   (0x00000000UL)
#define LINFLEX_LINCR1_MBL_11_BITS_MASK   (0x00000100UL)
#define LINFLEX_LINCR1_MBL_12_BITS_MASK   (0x00000200UL)
#define LINFLEX_LINCR1_MBL_13_BITS_MASK   (0x00000300UL)
#define LINFLEX_LINCR1_MBL_14_BITS_MASK   (0x00000400UL)
#define LINFLEX_LINCR1_MBL_15_BITS_MASK   (0x00000500UL)
#define LINFLEX_LINCR1_MBL_16_BITS_MASK   (0x00000600UL)
#define LINFLEX_LINCR1_MBL_17_BITS_MASK   (0x00000700UL)
#define LINFLEX_LINCR1_MBL_18_BITS_MASK   (0x00000800UL)
#define LINFLEX_LINCR1_MBL_19_BITS_MASK   (0x00000900UL)
#define LINFLEX_LINCR1_MBL_20_BITS_MASK   (0x00000A00UL)
#define LINFLEX_LINCR1_MBL_21_BITS_MASK   (0x00000B00UL)
#define LINFLEX_LINCR1_MBL_22_BITS_MASK   (0x00000C00UL)
#define LINFLEX_LINCR1_MBL_23_BITS_MASK   (0x00000D00UL)
#define LINFLEX_LINCR1_MBL_36_BITS_MASK   (0x00000E00UL)
#define LINFLEX_LINCR1_MBL_50_BITS_MASK   (0x00000F00UL)

/**
* @brief    LINFLEX Registers bits.
* @details  LINIER register bit masks.
*/
#define LINFLEX_LINIER_HRIE_MASK  (0x00000001UL)
#define LINFLEX_LINIER_DTIE_MASK  (0x00000002UL)
#define LINFLEX_LINIER_DRIE_MASK  (0x00000004UL)
#define LINFLEX_LINIER_DBEIE_MASK (0x00000008UL)
#define LINFLEX_LINIER_DBFIE_MASK (0x00000010UL)
#define LINFLEX_LINIER_WUIE_MASK  (0x00000020UL)
#define LINFLEX_LINIER_LSIE_MASK  (0x00000040UL)
#define LINFLEX_LINIER_BOIE_MASK  (0x00000080UL)
#define LINFLEX_LINIER_FEIE_MASK  (0x00000100UL)
#define LINFLEX_LINIER_HEIE_MASK  (0x00000800UL)
#define LINFLEX_LINIER_CEIE_MASK  (0x00001000UL)
#define LINFLEX_LINIER_BEIE_MASK  (0x00002000UL)
#define LINFLEX_LINIER_OCIE_MASK  (0x00004000UL)
#define LINFLEX_LINIER_SZIE_MASK  (0x00008000UL)

/**
* @brief    LINFLEX Registers bits.
* @details  LINSR register bit masks.
*/
#define LINFLEX_LINSR_HRF_MASK    (0x00000001UL)
#define LINFLEX_LINSR_DTF_MASK    (0x00000002UL)
#define LINFLEX_LINSR_DRF_MASK    (0x00000004UL)
#define LINFLEX_LINSR_DBEF_MASK   (0x00000008UL)
#define LINFLEX_LINSR_DBFF_MASK   (0x00000010UL)
#define LINFLEX_LINSR_WUF_MASK    (0x00000020UL)
#define LINFLEX_LINSR_RPS_MASK    (0x00000040UL)
#define LINFLEX_LINSR_RBSY_MASK   (0x00000080UL)
#define LINFLEX_LINSR_RMB_MASK    (0x00000200UL)
#define LINFLEX_LINSR_LINS_MASK   (0x0000F000UL)

/**
* @brief    LINFLEX LIN states.
* @details  Sleep mode: LINFlex is in Sleep mode to save power consumption.
*
* @implements   DLIN04201
*/
#define LINFLEX_LINSR_SLEEP_MODE          0x00U

/**
* @brief    LINFLEX LIN states.
* @details  Initialization mode: LINFlex is in Initialization mode.
*
* @implements   DLIN04201
*/
#define LINFLEX_LINSR_INIT_MODE           0x01U

/**
* @brief    LINFLEX LIN states.
* @details  Idle mode: This state is entered on several events:
*                - SLEEP bit and INIT in LINCR1 register have been cleared by software
*                - A falling edge has been received on RX pin and AWUM bit is set
*                - The previous frame reception or transmission has been completed or aborted.
*
* @implements   DLIN04201
*/
#define LINFLEX_LINSR_IDLE_MODE           0x02U

/**
* @brief    LINFLEX LIN states.
* @details  Break transmission ongoing.
*
* @implements   DLIN04201
*/
#define LINFLEX_LINSR_BREAK_TX_MODE       0x03U

/**
* @brief    LINFLEX LIN states.
* @details  Break transmission has been completed.Break Delimiter transmission is ongoing.
*
* @implements   DLIN04201
*/
#define LINFLEX_LINSR_BREAK_DEL_TX_MODE   0x04U

/**
* @brief    LINFLEX LIN states.
* @details  Synch Field transmission is ongoing.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
* @implements   DLIN04201
*/
#define LINFLEX_LINSR_SYNC_FIELD_TX_MODE  0x05U

/**
* @brief    LINFLEX LIN states.
* @details  Identifier transmission is ongoing.
*
* @implements   DLIN04201
*/
#define LINFLEX_LINSR_ID_FIELD_TX_MODE    0x06U

/**
* @brief    LINFLEX LIN states.
* @details  Header transmission is completed.
*
* @implements   DLIN04201
*/
#define LINFLEX_LINSR_HEADER_TX_MODE      0x07U

/**
* @brief    LINFLEX LIN states.
* @details  Response reception/transmission is ongoing.
*
* @implements   DLIN04201
*/
#define LINFLEX_LINSR_DATA_RX_TX_MODE     0x08U

/**
* @brief    LINFLEX LIN states.
* @details  Data reception/transmission completed. Checksum RX/TX ongoing.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
* @implements   DLIN04201
*/
#define LINFLEX_LINSR_CHECKSUM_RX_TX_MODE 0x09U

/**
* @brief    LINFLEX LIN states.
* @details  Reset LIN State Interrupt (generated on LIN state change).
*
* @implements   DLIN04201
*/
#define LINFLEX_LINSR_RESET_LSIE_MODE     0x0FU

/**
* @brief    LINFLEX Registers bits.
* @details  LINESR register bit masks.
*/
#define LINFLEX_LINESR_NF_MASK     (0x00000001UL)
#define LINFLEX_LINESR_BOF_MASK    (0x00000080UL)
#define LINFLEX_LINESR_FEF_MASK    (0x00000100UL)
#define LINFLEX_LINESR_IDPEF_MASK  (0x00000200UL)
#define LINFLEX_LINESR_BDEF_MASK   (0x00000400UL)
#define LINFLEX_LINESR_SFEF_MASK   (0x00000800UL)
#define LINFLEX_LINESR_CEF_MASK    (0x00001000UL)
#define LINFLEX_LINESR_BEF_MASK    (0x00002000UL)
#define LINFLEX_LINESR_OCF_MASK    (0x00004000UL)
#define LINFLEX_LINESR_SZF_MASK    (0x00008000UL)

/**
* @brief    LINFLEX Registers bits.
* @details  UARTCR register bit masks.
*/
#define LINFLEX_UARTCR_UART_MASK   (0x00000001UL)
#if IPV_LINFLEX <= IPV_LINFLEX_00_10_00
    #define LINFLEX_UARTCR_WL_MASK  (0x00000002UL)
#elif IPV_LINFLEX >= IPV_LINFLEX_03_00_00
    #define LINFLEX_UARTCR_WL0_MASK (0x00000002UL)
#endif
#define LINFLEX_UARTCR_PCE_MASK    (0x00000004UL)
#if IPV_LINFLEX <= IPV_LINFLEX_00_10_00
    #define LINFLEX_UARTCR_OP_MASK (0x00000008UL)
#elif IPV_LINFLEX >= IPV_LINFLEX_03_00_00
    #define LINFLEX_UARTCR_PC0     (0x00000008UL)
#endif
#define LINFLEX_UARTCR_TXEN_MASK   (0x00000010UL)
#define LINFLEX_UARTCR_RXEN_MASK   (0x00000020UL)
#if IPV_LINFLEX >= IPV_LINFLEX_03_00_00
    #define LINFLEX_UARTCR_PC1     (0x00000040UL)
#endif
#if IPV_LINFLEX <= IPV_LINFLEX_00_10_00
    #define LINFLEX_UARTCR_RDFL_MASK   (0x00000C00UL)
    #define LINFLEX_UARTCR_TDFL_MASK   (0x00006000UL)
#elif IPV_LINFLEX >= IPV_LINFLEX_03_00_00
    #define LINFLEX_UARTCR_WL1_MASK     (0x00000080UL)
    #define LINFLEX_UARTCR_TFBM_MASK    (0x00000100UL)
    #define LINFLEX_UARTCR_RFBM_MASK    (0x00000200UL)
    #define LINFLEX_UARTCR_RDFLRFC_MASK (0x00001C00UL)
    #define LINFLEX_UARTCR_TDFLTFC_MASK (0x0000E000UL)
#endif

/**
* @brief    UART mode.
* @details  Receiver Data Field length selection.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_UARTCR_RX_BUFF_SIZE_1_BYTES_MASK   (0x00000000UL)

/* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement. */
#define LINFLEX_UARTCR_RX_BUFF_SIZE_2_BYTES_MASK   (0x00000400UL)

/* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement. */
#define LINFLEX_UARTCR_RX_BUFF_SIZE_3_BYTES_MASK   (0x00000800UL)

/* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement. */
#define LINFLEX_UARTCR_RX_BUFF_SIZE_4_BYTES_MASK   (0x00000C00UL)

/**
* @brief    UART mode.
* @details  Transmitter Data Field length selection.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_UARTCR_TX_BUFF_SIZE_1_BYTES_MASK   (0x00000000UL)

/* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement. */
#define LINFLEX_UARTCR_TX_BUFF_SIZE_2_BYTES_MASK   (0x00002000UL)

/* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement. */
#define LINFLEX_UARTCR_TX_BUFF_SIZE_3_BYTES_MASK   (0x00004000UL)

/* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement. */
#define LINFLEX_UARTCR_TX_BUFF_SIZE_4_BYTES_MASK   (0x00006000UL)

/**
* @brief    LINFLEX Registers bits.
* @details  UARTSR register bit masks.
*/
#define LINFLEX_UARTSR_NF_MASK     (0x00000001UL)
#if IPV_LINFLEX <= IPV_LINFLEX_00_10_00
    #define LINFLEX_UARTSR_DTF_MASK         (0x00000002UL)
    #define LINFLEX_UARTSR_DRF_MASK         (0x00000004UL)
#elif IPV_LINFLEX >= IPV_LINFLEX_03_00_00
    #define LINFLEX_UARTSR_DTFTFF_MASK      (0x00000002UL)
    #define LINFLEX_UARTSR_DRFRFE_MASK      (0x00000004UL)
    #define LINFLEX_UARTSR_TO_MASK          (0x00000008UL)
#endif
#define LINFLEX_UARTSR_WUF_MASK    (0x00000020UL)
#define LINFLEX_UARTSR_RPS_MASK    (0x00000040UL)
#define LINFLEX_UARTSR_BOF_MASK    (0x00000080UL)
#define LINFLEX_UARTSR_FEF_MASK    (0x00000100UL)
#define LINFLEX_UARTSR_RMB_MASK    (0x00000200UL)
#define LINFLEX_UARTSR_PE0_MASK    (0x00000400UL)
#define LINFLEX_UARTSR_PE1_MASK    (0x00000800UL)
#define LINFLEX_UARTSR_PE2_MASK    (0x00001000UL)
#define LINFLEX_UARTSR_PE3_MASK    (0x00002000UL)
#define LINFLEX_UARTSR_OCF_MASK    (0x00004000UL)
#define LINFLEX_UARTSR_SZF_MASK    (0x00008000UL)

/**
* @brief    LINFLEX Registers bits.
* @details  LINTCSR register bit masks.
*/
#define LINFLEX_LINTCSR_TOCE_MASK  (0x00000100UL)
#define LINFLEX_LINTCSR_IOT_MASK   (0x00000200UL)
#define LINFLEX_LINTCSR_LTOM_MASK  (0x00000400UL)
#define LINFLEX_LINTCSR_CNT_MASK   (0x000000FFUL)
#define LINFLEX_LINTCSR_RESET_MASK (0x00000000UL)

/**
* @brief    LINFLEX Registers bits.
* @details  LINOCR register bit masks.
*/
#define LINFLEX_LINOCR_OC1_MASK    (0x000000FFUL)
#define LINFLEX_LINOCR_OC2_MASK    (0x0000FF00UL)

/**
* @brief    LINFLEX Registers bits.
* @details  LINTOCR register bit masks.
*/
#define LINFLEX_LINTOCR_RTO_MASK   (0x00000F00UL)
#define LINFLEX_LINTOCR_HTO_MASK   (0x0000007FUL)

/**
* @brief    LINFLEX Registers bits.
* @details  LINFBRR register bit masks.
*/
#define LINFLEX_LINFBRR_DIV_F_MASK (0x0000000FUL)

/**
* @brief    LINFLEX Registers bits.
* @details  LINIBRR register bit masks.
*/
#if IPV_LINFLEX <= IPV_LINFLEX_00_10_00
    #define LINFLEX_LINIBRR_DIV_M_MASK (0x1FFF0000UL)
#elif ((IPV_LINFLEX >= IPV_LINFLEX_03_00_00) && (IPV_LINFLEX < IPV_LINFLEX_04_00_00))
    #define LINFLEX_LINIBRR_DIV_M_MASK (0xFFFFF000UL)
#elif IPV_LINFLEX >= IPV_LINFLEX_04_00_00
    #define LINFLEX_LINIBRR_DIV_M_MASK (0xFFFFFF00UL)
#endif

/**
* @brief    LINFLEX Registers bits.
* @details  LINCFR register bit masks.
*/
#define LINFLEX_LINCFR_CF_MASK     (0x000000FFUL)

/**
* @brief    LINFLEX Registers bits.
* @details  LINCR2 register bit masks.
*/
#define LINFLEX_LINCR2_HTRQ_MASK   (0x00000100UL)
#define LINFLEX_LINCR2_ABRQ_MASK   (0x00000200UL)
#define LINFLEX_LINCR2_DTRQ_MASK   (0x00000400UL)
#define LINFLEX_LINCR2_DDRQ_MASK   (0x00000800UL)
#define LINFLEX_LINCR2_WURQ_MASK   (0x00001000UL)
#define LINFLEX_LINCR2_IOPE_MASK   (0x00002000UL)
#define LINFLEX_LINCR2_IOBE_MASK   (0x00004000UL)

/**
* @brief    LINFLEX Registers bits.
* @details  BIDR register bit masks.
*/
#define LINFLEX_BIDR_ID_MASK       (0x0000003FUL)
#define LINFLEX_BIDR_CCS_MASK      (0x00000100UL)
#define LINFLEX_BIDR_DIR_MASK      (0x00000200UL)
#define LINFLEX_BIDR_DFL_EXT_MASK  (0x0000FC00UL)
#define LINFLEX_BIDR_DFL_NOR_MASK  (0x00001C00UL)
#define LINFLEX_BIDR_DFL_SET_MASK  (0x00000007UL)

/**
* @brief    LINFLEX Registers bits.
* @details  BDRL register bit masks.
*/
#define LINFLEX_BDRL_DATA3_MASK    (0xFF000000UL)
#define LINFLEX_BDRL_DATA2_MASK    (0x00FF0000UL)
#define LINFLEX_BDRL_DATA1_MASK    (0x0000FF00UL)
#define LINFLEX_BDRL_DATA0_MASK    (0x000000FFUL)
#define LINFLEX_BDRL_EMPTY_MASK    (0xFFFFFF00UL)

/**
* @brief    LINFLEX Registers bits.
* @details  BDRM register bit masks.
*/
#define LINFLEX_BDRM_DATA7_MASK    (0xFF000000UL)
#define LINFLEX_BDRM_DATA6_MASK    (0x00FF0000UL)
#define LINFLEX_BDRM_DATA5_MASK    (0x0000FF00UL)
#define LINFLEX_BDRM_DATA4_MASK    (0x000000FFUL)
#define LINFLEX_BDRM_EMPTY_MASK    (0x00000000UL)

/* -----------------------------------------LINFBRR/LINIBRR registers---------------------------------------------*/

/**
* @brief    LINFBRR/LINIBRR registers - Set baudrate macro.
* @details  It has a limitation for LINIBRR value on 16 bits only
*               On Leopard this value is on 20 bits, but considering
*               LIN 2.x standard and maximum clock rate for peripherals
*               (120 MHz) this value cannot exceed 16 bits
*               In case this limitation has to be avoided, also plugins
*               modules have to be modified.
*/
/* 
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
* @violates @ref Reg_eSys_LINFlex_h_REF_7 C macros shall only expand to a braced initializer...
*/
#define LINFLEX_LLM_RESET_BAUDRATE(offset){ \
               REG_WRITE32(LINFLEX_LINFBRR(offset), 0); \
               REG_WRITE32(LINFLEX_LINIBRR(offset), 0); \
               }
#if IPV_LINFLEX < IPV_LINFLEX_04_00_00
/* 
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
* @violates @ref Reg_eSys_LINFlex_h_REF_7 C macros shall only expand to a braced initializer...
*/
#define LINFLEX_LLM_SET_BAUDRATE(offset, value){ \
               REG_WRITE32(LINFLEX_LINFBRR(offset), (value & LINFLEX_LINFBRR_DIV_F_MASK)); \
               REG_WRITE32(LINFLEX_LINIBRR(offset), ((value & LINFLEX_LINIBRR_DIV_M_MASK)>>(uint8)16U)); \
               }
#elif IPV_LINFLEX >= IPV_LINFLEX_04_00_00
/* 
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
* @violates @ref Reg_eSys_LINFlex_h_REF_7 C macros shall only expand to a braced initializer...
*/
#define LINFLEX_LLM_SET_BAUDRATE(offset, value){ \
               REG_WRITE32(LINFLEX_LINFBRR(offset), (value & LINFLEX_LINFBRR_DIV_F_MASK)); \
               REG_WRITE32(LINFLEX_LINIBRR(offset), ((value & LINFLEX_LINIBRR_DIV_M_MASK)>>(uint8)8U)); \
               }
#endif
/* -----------------------------------------LINCR1 register-------------------------------------------------------*/

/**
* @brief    LINFLEX registers - LINCR1 register bit masks.
* @details  Reset LINCR1 macro.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LINCR1_Reset(offset) ( REG_BIT_SET32(LINFLEX_LINCR1(offset), LINFLEX_LINCR1_RESET_MASK) )

/* Checksum calculation    */

/*----------------------------------------------------------------*/
/*  CFD CCD  LINCFR          Checksum sent                        */
/*----------------------------------------------------------------*/
/*   1   1   Read/Write      None                                 */
/*   1   0   Read-only       None                                 */
/*   0   1   Read/Write      Programmed in LINCFR by bits CF[0:7] */
/*   0   0   Read-only Mode  Hardware calculated                  */
/*----------------------------------------------------------------*/


/* Checksum Calculation Disable. This bit is used to disable the checksum calculation. */
/* - 0 Checksum calculation is done by hardware. When this bit is reset the LINCFR register is read-only. */
/* - 1 Checksum calculation is disabled. When this bit is set the LINCFR register is read/write. User can */
/*     program this register to send a software calculated CRC (provided CFD is reset).                   */

/**
* @brief    LINCR1 registers - Checksum Calculation Enable.
* @details  Checksum calculation is done by software.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_CCD_Enable(offset) ( REG_BIT_SET32(LINFLEX_LINCR1(offset), LINFLEX_LINCR1_CCD_MASK) )

/**
* @brief    LINCR1 registers - Checksum Calculation Disable.
* @details  Checksum calculation is done by hardware.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_CCD_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINCR1(offset), LINFLEX_LINCR1_CCD_MASK) )

/* Checksum field disable. This bit is used to disable the checksum field transmission. */
/* - 0 Checksum field is sent after the required number of data bytes is sent. */
/* - 1 No checksum field is sent. */

/**
* @brief    LINCR1 registers - Checksum field Enable.
* @details  No checksum field is sent.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_CFD_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), LINFLEX_LINCR1_CFD_MASK) )

/**
* @brief    LINCR1 registers - Checksum field Disable.
* @details  Checksum field is sent after the required number of data bytes is sent.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_CFD_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINCR1(offset), LINFLEX_LINCR1_CFD_MASK) )


/* Automatic Wake-Up Mode. This bit controls the behavior of the LINFlex hardware during Sleep mode. */
/* - 0 The Sleep mode is exited on software request by clearing the SLEEP bit of the LINCR register. */
/* - 1 The Sleep mode is exited automatically by hardware on RX dominant state detection. The SLEEP  */
/*     bit of the LINCR register is cleared by hardware whenever WUF bit in LINSR is set.            */

/**
* @brief    LINCR1 registers - Automatic Wake-Up Mode Enable.
* @details  The Sleep mode is exited automatically by hardware on RX dominant state detection. The SLEEP
*               bit of the LINCR register is cleared by hardware whenever WUF bit in LINSR is set.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_AWUM_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), LINFLEX_LINCR1_AWUM_MASK) )

/**
* @brief    LINCR1 registers - Automatic Wake-Up Mode Disable.
* @details  The Sleep mode is exited on software request by clearing the SLEEP bit of the LINCR register.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_AWUM_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINCR1(offset), LINFLEX_LINCR1_AWUM_MASK) )


/* Select break character length */
/*|--------------------------------------------------------|*/
/*|          MBL[0:3]         |          Length            |*/
/*|--------------------------------------------------------|*/
/*|            0000           |          10-bit            |*/
/*|---------------------------|----------------------------|*/
/*|            0001           |          11-bit            |*/
/*|---------------------------|----------------------------|*/
/*|            0010           |          12-bit            |*/
/*|---------------------------|----------------------------|*/
/*|            0011           |          13-bit            |*/
/*|---------------------------|----------------------------|*/
/*|            0100           |          14-bit            |*/
/*|---------------------------|----------------------------|*/
/*|            0101           |          15-bit            |*/
/*|---------------------------|----------------------------|*/
/*|            0110           |          16-bit            |*/
/*|---------------------------|----------------------------|*/
/*|            0111           |          17-bit            |*/
/*|---------------------------|----------------------------|*/
/*|            1000           |          18-bit            |*/
/*|---------------------------|----------------------------|*/
/*|            1001           |          19-bit            |*/
/*|---------------------------|----------------------------|*/
/*|            1010           |          20-bit            |*/
/*|---------------------------|----------------------------|*/
/*|            1011           |          21-bit            |*/
/*|---------------------------|----------------------------|*/
/*|            1100           |          22-bit            |*/
/*|---------------------------|----------------------------|*/
/*|            1101           |          23-bit            |*/
/*|---------------------------|----------------------------|*/
/*|            1110           |          36-bit            |*/
/*|---------------------------|----------------------------|*/
/*|            1111           |          50-bit            |*/
/*|------------------------------------------------------ -|*/


/**
* @brief    LINCR1 registers - LIN Master Break Length.
* @details  The following macro set the Break length in Master mode to 10.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_BREAK_10_BIT_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), (LINFLEX_LINCR1_MBL_MASK & LINFLEX_LINCR1_MBL_10_BITS_MASK) ))

/**
* @brief    LINCR1 registers - LIN Master Break Length.
* @details  The following macro set the Break length in Master mode to 11.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_BREAK_11_BIT_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), (LINFLEX_LINCR1_MBL_MASK & LINFLEX_LINCR1_MBL_11_BITS_MASK) ))

/**
* @brief    LINCR1 registers - LIN Master Break Length.
* @details  The following macro set the Break length in Master mode to 12.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_BREAK_12_BIT_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), (LINFLEX_LINCR1_MBL_MASK & LINFLEX_LINCR1_MBL_12_BITS_MASK) ))

/**
* @brief    LINCR1 registers - LIN Master Break Length.
* @details  The following macro set the Break length in Master mode to 13.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_BREAK_13_BIT_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), (LINFLEX_LINCR1_MBL_MASK & LINFLEX_LINCR1_MBL_13_BITS_MASK) ))

/**
* @brief    LINCR1 registers - LIN Master Break Length.
* @details  The following macro set the Break length in Master mode to 14.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_BREAK_14_BIT_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), (LINFLEX_LINCR1_MBL_MASK & LINFLEX_LINCR1_MBL_14_BITS_MASK) ))

/**
* @brief    LINCR1 registers - LIN Master Break Length.
* @details  The following macro set the Break length in Master mode to 15.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_BREAK_15_BIT_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), (LINFLEX_LINCR1_MBL_MASK & LINFLEX_LINCR1_MBL_15_BITS_MASK) ))

/**
* @brief    LINCR1 registers - LIN Master Break Length.
* @details  The following macro set the Break length in Master mode to 16.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_BREAK_16_BIT_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), (LINFLEX_LINCR1_MBL_MASK & LINFLEX_LINCR1_MBL_16_BITS_MASK) ))

/**
* @brief    LINCR1 registers - LIN Master Break Length.
* @details  The following macro set the Break length in Master mode to 17.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_BREAK_17_BIT_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), (LINFLEX_LINCR1_MBL_MASK & LINFLEX_LINCR1_MBL_17_BITS_MASK) ))

/**
* @brief    LINCR1 registers - LIN Master Break Length.
* @details  The following macro set the Break length in Master mode to 18.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_BREAK_18_BIT_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), (LINFLEX_LINCR1_MBL_MASK & LINFLEX_LINCR1_MBL_18_BITS_MASK) ))

/**
* @brief    LINCR1 registers - LIN Master Break Length.
* @details  The following macro set the Break length in Master mode to 19.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_BREAK_19_BIT_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), (LINFLEX_LINCR1_MBL_MASK & LINFLEX_LINCR1_MBL_19_BITS_MASK) ))

/**
* @brief    LINCR1 registers - LIN Master Break Length.
* @details  The following macro set the Break length in Master mode to 20.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_BREAK_20_BIT_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), (LINFLEX_LINCR1_MBL_MASK & LINFLEX_LINCR1_MBL_20_BITS_MASK) ))

/**
* @brief    LINCR1 registers - LIN Master Break Length.
* @details  The following macro set the Break length in Master mode to 21.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_BREAK_21_BIT_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), (LINFLEX_LINCR1_MBL_MASK & LINFLEX_LINCR1_MBL_21_BITS_MASK) ))

/**
* @brief    LINCR1 registers - LIN Master Break Length.
* @details  The following macro set the Break length in Master mode to 22.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_BREAK_22_BIT_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), (LINFLEX_LINCR1_MBL_MASK & LINFLEX_LINCR1_MBL_22_BITS_MASK) ))

/**
* @brief    LINCR1 registers - LIN Master Break Length.
* @details  The following macro set the Break length in Master mode to 23.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_BREAK_23_BIT_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), (LINFLEX_LINCR1_MBL_MASK & LINFLEX_LINCR1_MBL_23_BITS_MASK) ))

/**
* @brief    LINCR1 registers - LIN Master Break Length.
* @details  The following macro set the Break length in Master mode to 36.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_BREAK_36_BIT_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), (LINFLEX_LINCR1_MBL_MASK & LINFLEX_LINCR1_MBL_36_BITS_MASK) ))

/**
* @brief    LINCR1 registers - LIN Master Break Length.
* @details  The following macro set the Break length in Master mode to 50.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_BREAK_50_BIT_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), (LINFLEX_LINCR1_MBL_MASK & LINFLEX_LINCR1_MBL_50_BITS_MASK) ))

/**
* @brief    LINCR1 registers - LIN Master Break Length.
* @details  The following macro set the Break length in Master mode to the value parameter.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
*/
#define LINFLEX_LLM_LIN_BREAK_LENGTH_Set(offset, value) ( REG_BIT_SET32(LINFLEX_LINCR1(offset), ((value << 8U) & LINFLEX_LINCR1_MBL_MASK) ))

/* Bypass filter */
/* - 0 No interrupt if ID does not match any filter. */
/* - 1 An RX interrupt is generated on ID not matching any filter.  */

/**
* @brief    LINCR1 registers - Bypass filter.
* @details  An RX interrupt is generated on ID not matching any filter.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_BF_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINCR1(offset), LINFLEX_LINCR1_BF_MASK) )

/**
* @brief    LINCR1 registers - Bypass filter.
* @details  No interrupt if ID does not match any filter.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_BF_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINCR1(offset), LINFLEX_LINCR1_BF_MASK) )

/* Test modes */
/* Two test modes are available: Loop Back mode and Self Test mode. They can be selected by the LBKM and SFTM bits in the */
/* LINCR1 register. These bits must be configured while LINFlex is in Initialization mode. Once one of the two test modes */
/* has been selected, LINFlex must be started in Normal mode. */

/* Loop Back mode */
/* LINFlex can be put in Loop Back mode by setting the LBKM bit in the LINCR register. In Loop Back mode, the LINFlex     */
/* treats its own transmitted messages as received messages. This mode is provided for self test functions. To be         */
/* independent of external events, the LIN core ignores the LINRX signal. In this mode, the LINFlex performs an internal  */
/* feedback from its Tx output to its Rx input. The actual value of the LINRX input pin is disregarded by the LINFlex. The*/
/* transmitted messages can be monitored on the LINTX pin.*/

/* Self Test mode */
/* LINFlex can be put in Self Test mode by setting the LBKM and SFTM bits in the LINCR register. This mode can be used for*/
/* a Hot Self Test, meaning the LINFlex can be tested as in Loop Back mode but without affecting a running LIN system   */
/* connected to the LINTX and LINRX pins. In this mode, the LINRX pin is disconnected from the LINFlex and the LINTX pin  */
/* is held recessive. */

/*----------------------------*/
/* LBKM  SFTM  Mode           */
/*----------------------------*/
/*   0     0   None           */
/*   0     1   None           */
/*   1     0   Loop Back Mode */
/*   1     1   Self Test Mode */
/*----------------------------*/

/**
* @brief    LINCR1 registers - Loop Back mode enable.
* @details  Enable the Loop Back mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LOOP_BACK_MODE_Enable(offset) ( REG_BIT_SET32(LINFLEX_LINCR1(offset), LINFLEX_LINCR1_LBKM_MASK) )

/**
* @brief    LINCR1 registers - Self Test mode enable.
* @details  Enable the Self Test mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
* @violates @ref Reg_eSys_LINFlex_h_REF_7 C macros shall only expand to a braced initializer...
*/
#define LINFLEX_LLM_SELF_TEST_MODE_Enable(offset) { \
               REG_BIT_SET32(LINFLEX_LINCR1(offset), LINFLEX_LINCR1_LBKM_MASK); \
               REG_BIT_SET32(LINFLEX_LINCR1(offset), LINFLEX_LINCR1_SFTM_MASK); \
               }

/* Master Mode Enable */
/* - 0 Slave mode enable. */
/* - 1 Master mode enable.  */

/**
* @brief    LINCR1 registers - Master Mode Enable.
* @details  Enable the Master mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_MASTER_Enable(offset) ( REG_BIT_SET32(LINFLEX_LINCR1(offset), LINFLEX_LINCR1_MME_MASK) )

/**
* @brief    LINCR1 registers - Slave Mode Enable.
* @details  Enable the Slave mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_SLAVE_Enable(offset)  ( REG_BIT_CLEAR32(LINFLEX_LINCR1(offset), LINFLEX_LINCR1_MME_MASK) )



/* Sleep Mode Request. This bit is set by software to request LINFlex to enter Sleep mode. */
/* This bit is cleared by software to exit Sleep mode or by hardware if the AWUM bit in    */
/* LINCR1 and the WUF bit in LINSR are set */

/* Initialization Request. The software sets this bit to switch hardware into Initialization */
/* mode. If the SLEEP bit is reset, LINFlex enters Normal mode when clearing the INIT bit.   */

/*---------------------------------*/
/* SLEEP  INIT Operating mode      */
/*---------------------------------*/
/*   1     0   Sleep (reset value) */
/*   x     1   Initialization      */
/*   0     0   Normal              */
/*---------------------------------*/

/**
* @brief    LINCR1 registers - Enters Sleep Mode.
* @details  Enters the Sleep mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_ENTER_SLEEP_MODE(offset) ( REG_BIT_SET32(LINFLEX_LINCR1(offset), LINFLEX_LINCR1_SLEEP_MASK) )

/**
* @brief    LINCR1 registers - Exit Sleep Mode.
* @details  Exit the Sleep mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_EXIT_SLEEP_MODE(offset)  ( REG_BIT_CLEAR32(LINFLEX_LINCR1(offset), LINFLEX_LINCR1_SLEEP_MASK) )

/**
* @brief    LINCR1 registers - Enters Init Mode.
* @details  Enters the Init mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_ENTER_INIT_MODE(offset) ( REG_BIT_SET32(LINFLEX_LINCR1(offset), LINFLEX_LINCR1_INIT_MASK) )

/**
* @brief    LINCR1 registers - Exit Init Mode.
* @details  Exit the Init mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_EXIT_INIT_MODE(offset)  ( REG_BIT_CLEAR32(LINFLEX_LINCR1(offset), LINFLEX_LINCR1_INIT_MASK) )


/**
* @brief    LINCR1 registers - Exit Normal Mode Enters Init Mode.
* @details  Exit the Normal mode and enters the Sleep mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
* @violates @ref Reg_eSys_LINFlex_h_REF_7 C macros shall only expand to a braced initializer...
*/
#define LINFLEX_EXIT_NORMAL_MODE_TO_INIT_MODE(offset) { \
                                      LINFLEX_LLM_EXIT_SLEEP_MODE(offset); \
                                      LINFLEX_LLM_ENTER_INIT_MODE(offset); \
                                    }

/* -----------------------------------------LINIER register-------------------------------------------------------*/
/* Stuck at Zero Interrupt Enable. This bit controls the LINESR[SZF] or UARTSR[SZF] interrupt request generation. */

/**
* @brief    LINIER registers - Stuck at Zero Interrupt Enable.
* @details  This macro enables the LINESR[SZF] or UARTSR[SZF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_SZIE_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINIER(offset), LINFLEX_LINIER_SZIE_MASK) )

/**
* @brief    LINIER registers - Stuck at Zero Interrupt Disable.
* @details  This macro disables the LINESR[SZF] or UARTSR[SZF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_IRQ_SZIE_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINIER(offset), LINFLEX_LINIER_SZIE_MASK) )

/**
* @brief    LINIER registers - Stuck at Zero Interrupt Read.
* @details  This macro read the LINESR[SZF] or UARTSR[SZF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_SZIE_Read(offset)    ( ( ( REG_READ32(LINFLEX_LINIER(offset)) & LINFLEX_LINIER_SZIE_MASK ) == LINFLEX_LINIER_SZIE_MASK) ? TRUE : FALSE )

/* Output Compare Interrupt Enable. This bit controls the LINESR[OCF] or UARTSR[OCF] interrupt request generation. */

/**
* @brief    LINIER registers - Output Compare Interrupt Enable.
* @details  This macro enables the LINESR[OCF] or UARTSR[OCF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_OCIE_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINIER(offset), LINFLEX_LINIER_OCIE_MASK) )

/**
* @brief    LINIER registers - Output Compare Interrupt Enable.
* @details  This macro disables the LINESR[OCF] or UARTSR[OCF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_IRQ_OCIE_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINIER(offset), LINFLEX_LINIER_OCIE_MASK) )

/**
* @brief    LINIER registers - Output Compare Interrupt Enable.
* @details  This macro read the LINESR[OCF] or UARTSR[OCF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_OCIE_Read(offset)    ( ( ( REG_READ32(LINFLEX_LINIER(offset)) & LINFLEX_LINIER_OCIE_MASK ) == LINFLEX_LINIER_OCIE_MASK) ? TRUE : FALSE )

/* Bit Error Interrupt Enable. This bit controls the LINESR[BEF] interrupt request generation. */

/**
* @brief    LINIER registers - Bit Error Interrupt Enable.
* @details  This macro enables the LINESR[BEF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_BEIE_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINIER(offset), LINFLEX_LINIER_BEIE_MASK) )

/**
* @brief    LINIER registers - Bit Error Interrupt Enable.
* @details  This macro disables the LINESR[BEF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_IRQ_BEIE_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINIER(offset), LINFLEX_LINIER_BEIE_MASK) )

/**
* @brief    LINIER registers - Bit Error Interrupt Enable.
* @details  This macro read the LINESR[BEF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_BEIE_Read(offset)    ( ( ( REG_READ32(LINFLEX_LINIER(offset)) & LINFLEX_LINIER_BEIE_MASK ) == LINFLEX_LINIER_BEIE_MASK) ? TRUE : FALSE )

/* Checksum Error Interrupt Enable. This bit controls the LINESR[CEF] interrupt request generation. */

/**
* @brief    LINIER registers - Checksum Error Interrupt Enable.
* @details  This macro enables the LINESR[CEF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_CEIE_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINIER(offset), LINFLEX_LINIER_CEIE_MASK) )

/**
* @brief    LINIER registers - Checksum Error Interrupt Enable.
* @details  This macro disables the LINESR[CEF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_IRQ_CEIE_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINIER(offset), LINFLEX_LINIER_CEIE_MASK) )

/**
* @brief    LINIER registers - Checksum Error Interrupt Enable.
* @details  This macro read the LINESR[CEF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_CEIE_Read(offset)    ( ( ( REG_READ32(LINFLEX_LINIER(offset)) & LINFLEX_LINIER_CEIE_MASK ) == LINFLEX_LINIER_CEIE_MASK) ? TRUE : FALSE )

/* Header Error Interrupt Enable. This bit controls the LINESR[BDEF], LINESR[SFEF], LINESR[IDPEF] interrupt requests generation. */
/* Interrupt will be generated on Break Delimiter error, Synch Field error, ID field error. */

/**
* @brief    LINIER registers - Header Error Interrupt Enable.
* @details  This macro enables the LINESR[BDEF], LINESR[SFEF], LINESR[IDPEF] interrupt requests generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_HEIE_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINIER(offset), LINFLEX_LINIER_HEIE_MASK) )

/**
* @brief    LINIER registers - Header Error Interrupt Enable.
* @details  This macro disables LINESR[BDEF], LINESR[SFEF], LINESR[IDPEF] interrupt requests generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_IRQ_HEIE_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINIER(offset), LINFLEX_LINIER_HEIE_MASK) )

/**
* @brief    LINIER registers - Header Error Interrupt Enable.
* @details  This macro read the LINESR[BDEF], LINESR[SFEF], LINESR[IDPEF] interrupt requests generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_HEIE_Read(offset)    ( ( ( REG_READ32(LINFLEX_LINIER(offset)) & LINFLEX_LINIER_HEIE_MASK ) == LINFLEX_LINIER_HEIE_MASK) ? TRUE : FALSE )

/* Framing Error Interrupt Enable. This bit controls the LINESR[FEF] or UARTSR[FEF] interrupt request generation. */

/**
* @brief    LINIER registers - Framing Error Interrupt Enable.
* @details  This macro enables the LINESR[FEF] or UARTSR[FEF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_FEIE_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINIER(offset), LINFLEX_LINIER_FEIE_MASK) )

/**
* @brief    LINIER registers - Framing Error Interrupt Enable.
* @details  This macro disables the LINESR[FEF] or UARTSR[FEF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_IRQ_FEIE_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINIER(offset), LINFLEX_LINIER_FEIE_MASK) )

/**
* @brief    LINIER registers - Framing Error Interrupt Enable.
* @details  This macro read the LINESR[FEF] or UARTSR[FEF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_FEIE_Read(offset)    ( ( ( REG_READ32(LINFLEX_LINIER(offset)) & LINFLEX_LINIER_FEIE_MASK ) == LINFLEX_LINIER_FEIE_MASK) ? TRUE : FALSE )

/* Buffer Overrun Interrupt Enable. This bit controls the LINESR[BOF] or UARTSR[BOF] interrupt request generation. */

/**
* @brief    LINIER registers - Buffer Overrun Interrupt Enable.
* @details  This macro enables the LINESR[BOF] or UARTSR[BOF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_BOIE_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINIER(offset), LINFLEX_LINIER_BOIE_MASK) )

/**
* @brief    LINIER registers - Buffer Overrun Interrupt Enable.
* @details  This macro disables the LINESR[BOF] or UARTSR[BOF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_IRQ_BOIE_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINIER(offset), LINFLEX_LINIER_BOIE_MASK) )

/**
* @brief    LINIER registers - Buffer Overrun Interrupt Enable.
* @details  This macro read the LINESR[BOF] or UARTSR[BOF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_BOIE_Read(offset)    ( ( ( REG_READ32(LINFLEX_LINIER(offset)) & LINFLEX_LINIER_BOIE_MASK ) == LINFLEX_LINIER_BOIE_MASK) ? TRUE : FALSE )

/* LIN State Interrupt Enable. This interrupt is generated on LIN state change (LINSR). */
/* This interrupt can be used for debugging purposes. It has no status flag but is reset when writing 1111 into */
/* the LIN state bits in the LINSR register. */

/**
* @brief    LINIER registers - LIN State Interrupt Enable.
* @details  This macro enables the LIN state change (LINSR) interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_LSIE_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINIER(offset), LINFLEX_LINIER_LSIE_MASK) )

/**
* @brief    LINIER registers - LIN State Interrupt Enable.
* @details  This macro disables the LIN state change (LINSR) interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_IRQ_LSIE_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINIER(offset), LINFLEX_LINIER_LSIE_MASK) )

/**
* @brief    LINIER registers - LIN State Interrupt Enable.
* @details  This macro read the LIN state change (LINSR) interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_LSIE_Read(offset)    ( ( ( REG_READ32(LINFLEX_LINIER(offset)) & LINFLEX_LINIER_LSIE_MASK ) == LINFLEX_LINIER_LSIE_MASK) ? TRUE : FALSE )

/* Wake-up Interrupt Enable. This bit controls the LINSR[WUF] or UARTSR[WUF] interrupt request generation. */

/**
* @brief    LINIER registers - Wake-up Interrupt Enable.
* @details  This macro enables the LINSR[WUF] or UARTSR[WUF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_WUIE_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINIER(offset), LINFLEX_LINIER_WUIE_MASK) )

/**
* @brief    LINIER registers - Wake-up Interrupt Enable.
* @details  This macro disables the LINSR[WUF] or UARTSR[WUF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_IRQ_WUIE_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINIER(offset), LINFLEX_LINIER_WUIE_MASK) )

/**
* @brief    LINIER registers - Wake-up Interrupt Enable.
* @details  This macro read the LINSR[WUF] or UARTSR[WUF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_WUIE_Read(offset)    ( ( ( REG_READ32(LINFLEX_LINIER(offset)) & LINFLEX_LINIER_WUIE_MASK ) == LINFLEX_LINIER_WUIE_MASK) ? TRUE : FALSE )

/* Data Buffer Full Interrupt Enable. This interrupt is generated when data buffer register is full. */

/**
* @brief    LINIER registers - Data Buffer Full Interrupt Enable.
* @details  This macro enables the interrupt request generation when data buffer register is full.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_IRQ_DBFIE_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINIER(offset), LINFLEX_LINIER_DBFIE_MASK) )

/**
* @brief    LINIER registers - Data Buffer Full Interrupt Enable.
* @details  This macro disables the interrupt request generation when data buffer register is full.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_IRQ_DBFIE_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINIER(offset), LINFLEX_LINIER_DBFIE_MASK) )

/**
* @brief    LINIER registers - Data Buffer Full Interrupt Enable.
* @details  This macro read the interrupt request generation when data buffer register is full.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_DBFIE_Read(offset)    ( ( ( REG_READ32(LINFLEX_LINIER(offset)) & LINFLEX_LINIER_DBFIE_MASK ) == LINFLEX_LINIER_DBFIE_MASK) ? TRUE : FALSE )

/* Data Buffer Empty Interrupt Enable. This interrupt is generated when data buffer register is empty. */

/**
* @brief    LINIER registers - Data Buffer Empty Interrupt Enable.
* @details  This macro enables the interrupt request generation when data buffer register is empty.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_IRQ_DBEIE_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINIER(offset), LINFLEX_LINIER_DBEIE_MASK) )

/**
* @brief    LINIER registers - Data Buffer Empty Interrupt Enable.
* @details  This macro disables the interrupt request generation when data buffer register is empty.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_IRQ_DBEIE_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINIER(offset), LINFLEX_LINIER_DBEIE_MASK) )

/**
* @brief    LINIER registers - Data Buffer Empty Interrupt Enable.
* @details  This macro read the interrupt request generation when data buffer register is empty.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_DBEIE_Read(offset)    ( ( ( REG_READ32(LINFLEX_LINIER(offset)) & LINFLEX_LINIER_DBEIE_MASK ) == LINFLEX_LINIER_DBEIE_MASK) ? TRUE : FALSE )

/* Data Reception Complete Interrupt Enable. This bit controls the LINSR[DRF] or UARTSR[DRF] interrupt request generation. */

/**
* @brief    LINIER registers - Data Reception Complete Interrupt Enable.
* @details  This macro enables the LINSR[DRF] or UARTSR[DRF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_DRIE_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINIER(offset), LINFLEX_LINIER_DRIE_MASK) )

/**
* @brief    LINIER registers - Data Reception Complete Interrupt Enable.
* @details  This macro disables the LINSR[DRF] or UARTSR[DRF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_IRQ_DRIE_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINIER(offset), LINFLEX_LINIER_DRIE_MASK) )

/**
* @brief    LINIER registers - Data Reception Complete Interrupt Enable.
* @details  This macro read the LINSR[DRF] or UARTSR[DRF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_DRIE_Read(offset)    ( ( ( REG_READ32(LINFLEX_LINIER(offset)) & LINFLEX_LINIER_DRIE_MASK ) == LINFLEX_LINIER_DRIE_MASK) ? TRUE : FALSE )

/* Data Transmitted Interrupt Enable. This bit controls the LINSR[DTF] or UARTSR[DTF] interrupt request generation. */

/**
* @brief    LINIER registers - Data Transmitted Complete Interrupt Enable.
* @details  This macro enables the LINSR[DTF] or UARTSR[DTF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_DTIE_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINIER(offset), LINFLEX_LINIER_DTIE_MASK) )

/**
* @brief    LINIER registers - Data Transmitted Complete Interrupt Enable.
* @details  This macro disables the LINSR[DTF] or UARTSR[DTF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_IRQ_DTIE_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINIER(offset), LINFLEX_LINIER_DTIE_MASK) )

/**
* @brief    LINIER registers - Data Transmitted Complete Interrupt Enable.
* @details  This macro read the LINSR[DTF] or UARTSR[DTF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_DTIE_Read(offset)    ( ( ( REG_READ32(LINFLEX_LINIER(offset)) & LINFLEX_LINIER_DTIE_MASK ) == LINFLEX_LINIER_DTIE_MASK) ? TRUE : FALSE )

/* Header Received Interrupt Enable. This bit controls the LINSR[HRF] interrupt request generation. */
/* Interrupt generated when a valid LIN header has been received. */

/**
* @brief    LINIER registers - Header Received Interrupt Enable.
* @details  This macro enables the LINSR[HRF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_HRIE_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINIER(offset), LINFLEX_LINIER_HRIE_MASK) )

/**
* @brief    LINIER registers - Header Received Interrupt Enable.
* @details  This macro disables the LINSR[HRF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_IRQ_HRIE_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINIER(offset), LINFLEX_LINIER_HRIE_MASK) )

/**
* @brief    LINIER registers - Header Received Interrupt Enable.
* @details  This macro read the LINSR[HRF] interrupt request generation.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_IRQ_HRIE_Read(offset)    ( ( ( REG_READ32(LINFLEX_LINIER(offset)) & LINFLEX_LINIER_HRIE_MASK ) == LINFLEX_LINIER_HRIE_MASK) ? TRUE : FALSE )

/* -----------------------------------------LINSR register-------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------*/
/* LINSR.LINS[0..3] values    LIN states                                                                               */
/*---------------------------------------------------------------------------------------------------------------------*/
/*            0               Sleep mode: LINFlex is in Sleep mode to save power consumption.                          */
/*            1               Initialization mode: LINFlex is in Initialization mode.                                  */
/*            2               Idle mode: This state is entered on several events:                                      */
/*                                         SLEEP bit and INIT in LINCR1 register have been cleared by software,        */
/*                                         A falling edge has been received on RX pin and AWUM bit is set,             */
/*                                         The previous frame reception or transmission has been completed or aborted. */
/*            3               Break transmission ongoing.                                                              */
/*            4               Break transmission has been completed.Break Delimiter transmission is ongoing.           */
/*            5               Synch Field transmission is ongoing.                                                     */
/*            6               Identifier transmission is ongoing.                                                      */
/*            7               Header transmission is completed.                                                        */
/*            8               Response reception/transmission is ongoing.                                              */
/*            9               Data reception/transmission completed. Checksum RX/TX ongoing.                           */
/*            F               Sleep mode: Reset LIN State Interrupt (generated on LIN state change).                   */
/*---------------------------------------------------------------------------------------------------------------------*/

/**
* @brief    LINSR registers - LIN state.
* @details  This macro returns the LIN State:
*               0  Sleep mode: LINFlex is in Sleep mode to save power consumption
*               1  Initialization mode: LINFlex is in Initialization mode
*               2  Idle mode: This state is entered on several events:
*                       SLEEP bit and INIT in LINCR1 register have been cleared by software,
*                       A falling edge has been received on RX pin and AWUM bit is set,
*                       The previous frame reception or transmission has been completed or aborted
*               3  Break transmission ongoing
*               4  Break transmission has been completed.Break Delimiter transmission is ongoing
*               5  Synch Field transmission is ongoing
*               6  Identifier transmission is ongoing
*               7  Header transmission is completed
*               8  Response reception/transmission is ongoing
*               9  Data reception/transmission completed. Checksum RX/TX ongoing
*               F  Sleep mode: Reset LIN State Interrupt (generated on LIN state change)
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_STATE_Read(offset)  ( REG_READ32(LINFLEX_LINSR(offset)) & LINFLEX_LINSR_LINS_MASK )


/* Release Message Buffer. This bit must be cleared by software after reading data received in the buffer.*/
/* - 0 Buffer is free.                                                                                   */
/* - 1 Buffer ready to be read by software. This bit must be cleared by software after reading data      */
/*     received in the buffer.                                                                           */

/**
* @brief    LINSR registers - Release Message Buffer.
* @details  This macro read the Message Buffer to verify if it's free.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_IS_MSG_BUFFER_FREE(offset)     ( ( ( REG_READ32(LINFLEX_LINSR(offset)) & LINFLEX_LINSR_RMB_MASK ) == LINFLEX_LINSR_RMB_MASK) ? FALSE : TRUE )

/**
* @brief    LINSR registers - Release Message Buffer.
* @details  This macro releases the Message Buffer.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_RELEASE_MESSAGE_BUFFER(offset) ( REG_WRITE32(LINFLEX_LINSR(offset), LINFLEX_LINSR_RMB_MASK) )

/* Receiver Busy Flag. In Slave mode, after header reception, if DIR bit in BIDR is reset and reception  */
/* starts then this bit is set. In this case, user cannot set DTRQ bit in LINCR2.                        */
/* - 0: Receiver is Idle                                                                                 */
/* - 1: Reception ongoing                                                                                */

/**
* @brief    LINSR registers - Receiver Busy Flag.
* @details  This macro read the Receiver Busy Flag to verify if the receiver is idle or ongoing.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_IS_RX_BUSY(offset)    ( ( ( REG_READ32(LINFLEX_LINSR(offset)) & LINFLEX_LINSR_RBSY_MASK ) == LINFLEX_LINSR_RBSY_MASK) ? TRUE : FALSE )

/**
* @brief    LINSR registers - Receiver Busy Flag.
* @details  This macro clears the Receiver Busy Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_RX_BUSY_Clear(offset) ( REG_WRITE32(LINFLEX_LINSR(offset), LINFLEX_LINSR_RBSY_MASK) )

/* LIN receive pin state. This bit reflects the current status of LINRX pin for diagnostic purposes.     */

/**
* @brief    LINSR registers - LIN receive pin state.
* @details  This macro read the bit reflecting the current status of LINRX pin for diagnostic purposes.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_RX_PIN_STATE_Read(offset)   (( REG_READ32(LINFLEX_LINSR(offset)) & LINFLEX_LINSR_RPS_MASK ))

/* Wake-up Flag. This bit is set by hardware and indicates to the software that LINFlex has detected a   */
/* falling edge on the LINRX pin when:                                                                   */
/*     slave is in Sleep mode,                                                                           */
/*     master is in Sleep mode or idle state.                                                            */
/* This bit must be cleared by software. It is reset by hardware in Initialization mode.An interrupt is  */
/* generated if WUIE bit in LINIER is set.                                                               */

/**
* @brief    LINSR registers - Wake-up Flag.
* @details  This macro read the bit indicating to the software that LINFlex has detected a
*               falling edge on the LINRX pin.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_WAKEUP_RECEIVED(offset)  ( ( ( REG_READ32(LINFLEX_LINSR(offset)) & LINFLEX_LINSR_WUF_MASK ) == LINFLEX_LINSR_WUF_MASK) ? TRUE : FALSE )

/**
* @brief    LINSR registers - Wake-up Flag.
* @details  This macro clears the Wake-up Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_WAKEUP_Clear(offset)     ( REG_WRITE32(LINFLEX_LINSR(offset), LINFLEX_LINSR_WUF_MASK) )

/* Data Buffer Full Flag. This bit is set by hardware and indicates the buffer is full. It is set only when*/
/* receiving extended frames (DFL > 7). This bit must be cleared by software. It is reset by hardware in */
/* Initialization mode.                                                                                  */

/**
* @brief    LINSR registers - Data Buffer Full Flag.
* @details  This macro read the bit indicating to the software that the buffer is full.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_IS_DATA_BUFF_FULL(offset)       ( ( ( REG_READ32(LINFLEX_LINSR(offset)) & LINFLEX_LINSR_DBFF_MASK ) == LINFLEX_LINSR_DBFF_MASK) ? TRUE : FALSE )

/**
* @brief    LINSR registers - Data Buffer Full Flag.
* @details  This macro clears the Data Buffer Full Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_DATA_BUFF_FULL_Clear(offset)    ( REG_WRITE32(LINFLEX_LINSR(offset), LINFLEX_LINSR_DBFF_MASK) )

/* Data Buffer Empty Flag. This bit is set by hardware and indicates the buffer is empty. It is set only */
/* when transmitting extended frames (DFL > 7). This bit must be cleared by software, once buffer has been*/
/* filled again, in order to start transmission. This bit is reset by hardware in Initialization mode.   */

/**
* @brief    LINSR registers - Data Buffer Empty Flag.
* @details  This macro read the bit indicating to the software that the buffer is empty.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_IS_DATA_BUFF_EMPTY(offset)      ( ( ( REG_READ32(LINFLEX_LINSR(offset)) & LINFLEX_LINSR_DBEF_MASK ) == LINFLEX_LINSR_DBEF_MASK) ? TRUE : FALSE )

/**
* @brief    LINSR registers - Data Buffer Empty Flag.
* @details  This macro clears the Data Buffer Empty Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_DATA_BUFF_EMPTY_Clear(offset)   ( REG_WRITE32(LINFLEX_LINSR(offset), LINFLEX_LINSR_DBEF_MASK) )

/* Data Reception Completed Flag. This bit is set by hardware and indicates the data reception is        */
/* completed. This bit must be cleared by software. It is reset by hardware in Initialization mode.      */
/* Note: It isn't set in case of bit or framing error.                                                   */

/**
* @brief    LINSR registers - Data Reception Completed Flag.
* @details  This macro read the bit indicating to the software that the data reception is completed.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_IS_DATA_RX_COMPLETED(offset)    ( ( ( REG_READ32(LINFLEX_LINSR(offset)) & LINFLEX_LINSR_DRF_MASK ) == LINFLEX_LINSR_DRF_MASK) ? TRUE : FALSE )

/**
* @brief    LINSR registers - Data Reception Completed Flag.
* @details  This macro clears the Data Reception Completed Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_DATA_RX_COMPLETED_Clear(offset) ( REG_WRITE32(LINFLEX_LINSR(offset), LINFLEX_LINSR_DRF_MASK) )

/* Data Transmission Completed Flag. This bit is set by hardware and indicates the data TX is completed. */
/* This bit must be cleared by software. It's reset by hardware in Initialization mode. Note: This flag  */
/* is not set in case of bit error if IOBE bit is reset.                                                 */

/**
* @brief    LINSR registers - Data Transmission Completed Flag.
* @details  This macro read the bit indicating to the software that the data TX is completed.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_IS_DATA_TX_COMPLETED(offset)    ( ( ( REG_READ32(LINFLEX_LINSR(offset)) & LINFLEX_LINSR_DTF_MASK ) == LINFLEX_LINSR_DTF_MASK) ? TRUE : FALSE )

/**
* @brief    LINSR registers - Data Transmission Completed Flag.
* @details  This macro clears the Data Transmission Completed Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_DATA_TX_COMPLETED_Clear(offset) ( REG_WRITE32(LINFLEX_LINSR(offset), LINFLEX_LINSR_DTF_MASK) )

/* Header Reception Flag. This bit is set by hardware and indicates a valid header reception is completed.*/
/* This bit must be cleared by software. This bit is reset by HW in Initialization mode and at end of    */
/* completed or aborted frame. Note: If filters are enabled, this bit is set only when identifier software*/
/* filtering is required, that is to say:                                                                */
/*     all filters are inactive and BF bit in LINCR1 is set;                                             */
/*     no match in any filter and BF bit in LINCR1 is set;                                               */
/*     TX filter match.                                                                                  */

/**
* @brief    LINSR registers - Header Reception Flag.
* @details  This macro read the bit indicating to the software that valid header reception is completed.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_HEADER_RECEIVED(offset)         ( ( ( REG_READ32(LINFLEX_LINSR(offset)) & LINFLEX_LINSR_HRF_MASK ) == LINFLEX_LINSR_HRF_MASK) ? TRUE : FALSE )

/**
* @brief    LINSR registers - Header Reception Flag.
* @details  This macro clears the Header Reception Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_HEADER_RECEIVED_Clear(offset)   ( REG_WRITE32(LINFLEX_LINSR(offset), LINFLEX_LINSR_HRF_MASK) )

/* -----------------------------------------LINESR register-------------------------------------------------------*/

/* Stuck at zero Flag. This bit is set by hardware when the bus is dominant for more than a 100-bit time.*/
/* It is cleared by software.                                                                            */

/**
* @brief    LINESR registers - Stuck at zero Flag.
* @details  This macro read the bit indicating to the software that the bus is dominant for more than a 100-bit time.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_SZF_Read(offset)  ( ( ( REG_READ32(LINFLEX_LINESR(offset)) & LINFLEX_LINESR_SZF_MASK ) == LINFLEX_LINESR_SZF_MASK) ? TRUE : FALSE )

/**
* @brief    LINESR registers - Stuck at zero Flag.
* @details  This macro clears the Stuck at zero Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_SZF_Clear(offset) ( REG_WRITE32(LINFLEX_LINESR(offset), LINFLEX_LINESR_SZF_MASK) )

/* Output Compare Flag. If this bit is set and IOT bit in LINTCSR is set, LINFlex moves to Idle state.   */
/* If LTOM bit in LINTCSR register is set then OCF is reset by hardware in Initialization mode. If LTOM  */
/* bit is reset, then OCF maintains its status whatever the mode is.                                     */
/* - 0 No output compare event occurred.                                                                 */
/* - 1 The content of the counter has matched the content of OC1[0:7] or OC2[0:7] in LINOCR.             */

/**
* @brief    LINESR registers - Output Compare Flag.
* @details  This macro read the OCF bit. If this bit is set and IOT bit in LINTCSR is set, LINFlex moves to Idle state.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_OCF_Read(offset)  ( ( ( REG_READ32(LINFLEX_LINESR(offset)) & LINFLEX_LINESR_OCF_MASK ) == LINFLEX_LINESR_OCF_MASK) ? TRUE : FALSE )

/**
* @brief    LINESR registers - Output Compare Flag.
* @details  This macro clears the Output Compare Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_OCF_Clear(offset) ( REG_BIT_SET32(LINFLEX_LINESR(offset), LINFLEX_LINESR_OCF_MASK) )

/* Bit Error Flag. This bit is set by hardware and indicates to the software that LINFlex has detected a */
/* bit error. This error can occur during response field transmission (Slave and Master modes) or during */
/* header transmission (in Master mode). This bit is cleared by software.                                */

/**
* @brief    LINESR registers - Bit Error Flag.
* @details  This macro read the bit indicating to the software that LINFlex has detected a bit error.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_BEF_Read(offset)  ( ( ( REG_READ32(LINFLEX_LINESR(offset)) & LINFLEX_LINESR_BEF_MASK ) == LINFLEX_LINESR_BEF_MASK) ? TRUE : FALSE )

/**
* @brief    LINESR registers - Bit Error Flag.
* @details  This macro clears the Bit Error Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_BEF_Clear(offset) ( REG_WRITE32(LINFLEX_LINESR(offset), LINFLEX_LINESR_BEF_MASK) )

/* Checksum Error Flag. This bit is set by hardware and indicates that the received checksum does not    */
/* match the hardware calculated checksum. This bit is cleared by software. Note: This bit is never set  */
/* if CCD or CFD bit in LINCR1 register is set.                                                          */

/**
* @brief    LINESR registers - Checksum Error Flag.
* @details  This macro read the bit indicating to the software that the received checksum does not
*               match the hardware calculated checksum.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_CEF_Read(offset)  ( ( ( REG_READ32(LINFLEX_LINESR(offset)) & LINFLEX_LINESR_CEF_MASK ) == LINFLEX_LINESR_CEF_MASK) ? TRUE : FALSE )

/**
* @brief    LINESR registers - Checksum Error Flag.
* @details  This macro clears the Checksum Error Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_CEF_Clear(offset) ( REG_WRITE32(LINFLEX_LINESR(offset), LINFLEX_LINESR_CEF_MASK) )

/* Synch Field Error Flag. This bit is set by hardware and indicates that a Synch Field error occurred   */
/* (inconsistent Synch Field).                                                                           */

/**
* @brief    LINESR registers - Synch Field Error Flag.
* @details  This macro read the bit indicating to the software that Synch Field error occurred
*               (inconsistent Synch Field).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_SFEF_Read(offset)  ( ( ( REG_READ32(LINFLEX_LINESR(offset)) & LINFLEX_LINESR_SFEF_MASK ) == LINFLEX_LINESR_SFEF_MASK) ? TRUE : FALSE )

/**
* @brief    LINESR registers - Synch Field Error Flag.
* @details  This macro clears the Synch Field Error Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_SFEF_Clear(offset) ( REG_WRITE32(LINFLEX_LINESR(offset), LINFLEX_LINESR_SFEF_MASK) )

/* Break Delimiter Error Flag. This bit is set by hardware and indicates that the received Break Delimiter*/
/* is too short (less than one bit time).                                                                */

/**
* @brief    LINESR registers - Break Delimiter Error Flag.
* @details  This macro read the bit indicating to the software that received Break Delimiter
*               is too short (less than one bit time).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_BDEF_Read(offset)  ( ( ( REG_READ32(LINFLEX_LINESR(offset)) & LINFLEX_LINESR_BDEF_MASK ) == LINFLEX_LINESR_BDEF_MASK) ? TRUE : FALSE )

/**
* @brief    LINESR registers - Break Delimiter Error Flag.
* @details  This macro clears the Break Delimiter Error Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_BDEF_Clear(offset) ( REG_WRITE32(LINFLEX_LINESR(offset), LINFLEX_LINESR_BDEF_MASK) )

/* Identifier Parity Error Flag. This bit is set by hardware and indicates that a Identifier Parity error*/
/* occurred. Note: Header interrupt is triggered when SFEF or BDEF or IDPEF bit is set and HEIE bit in   */
/* LINIER is set.                                                                                        */

/**
* @brief    LINESR registers - Identifier Parity Error Flag.
* @details  This macro read the bit indicating to the software that an Identifier Parity error
*               occurred.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_IDPEF_Read(offset)  ( ( ( REG_READ32(LINFLEX_LINESR(offset)) & LINFLEX_LINESR_IDPEF_MASK ) == LINFLEX_LINESR_IDPEF_MASK) ? TRUE : FALSE )

/**
* @brief    LINESR registers - Identifier Parity Error Flag.
* @details  This macro clears the Identifier Parity Error Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_IDPEF_Clear(offset) ( REG_WRITE32(LINFLEX_LINESR(offset), LINFLEX_LINESR_IDPEF_MASK) )

/* Framing Error Flag. This bit is set by hardware and indicates to the software that LINFlex has detected*/
/* a framing error (invalid stop bit). This error can occur during reception of any data in the response */
/* field (Master or Slave mode) or during reception of Synch Field or Identifier Field in Slave mode.    */

/**
* @brief    LINESR registers - Framing Error Flag.
* @details  This macro read the bit indicating to the software that LINFlex has detected a framing
*               error (invalid stop bit).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_FEF_Read(offset)  ( ( ( REG_READ32(LINFLEX_LINESR(offset)) & LINFLEX_LINESR_FEF_MASK ) == LINFLEX_LINESR_FEF_MASK) ? TRUE : FALSE )

/**
* @brief    LINESR registers - Framing Error Flag.
* @details  This macro clears the Framing Error Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_FEF_Clear(offset) ( REG_WRITE32(LINFLEX_LINESR(offset), LINFLEX_LINESR_FEF_MASK) )

/* Buffer Overrun Flag. This bit is set by hardware when a new data byte is received and the buffer full */
/* flag is not cleared. If RBLM in LINCR1 is set then the new byte received is discarded. If RBLM is reset*/
/* then the new byte overwrites the buffer. It can be cleared by software.*/

/**
* @brief    LINESR registers - Buffer Overrun Flag.
* @details  This macro read the bit indicating to the software that a new data byte is received
*               and the buffer full flag is not cleared.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_BOF_Read(offset)  ( ( ( REG_READ32(LINFLEX_LINESR(offset)) & LINFLEX_LINESR_BOF_MASK ) == LINFLEX_LINESR_BOF_MASK) ? TRUE : FALSE )

/**
* @brief    LINESR registers - Buffer Overrun Flag.
* @details  This macro clears the Buffer Overrun Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_BOF_Clear(offset) ( REG_WRITE32(LINFLEX_LINESR(offset), LINFLEX_LINESR_BOF_MASK) )

/* Noise Flag. This bit is set by hardware when noise is detected on a received character. This bit is   */
/* cleared by software.                                                                                  */

/**
* @brief    LINESR registers - Noise Flag.
* @details  This macro read the bit indicating to the software that a noise is detected onr
*               a received character.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_NF_Read(offset)  ( ( ( REG_READ32(LINFLEX_LINESR(offset)) & LINFLEX_LINESR_NF_MASK ) == LINFLEX_LINESR_NF_MASK) ? TRUE : FALSE )

/**
* @brief    LINESR registers - Noise Flag.
* @details  This macro clears the Noise Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_NF_Clear(offset) ( REG_WRITE32(LINFLEX_LINESR(offset), LINFLEX_LINESR_NF_MASK) )

/* -----------------------------------------UARTCR register-------------------------------------------------------*/

/* Transmitter Data Field length. These bits set the number of bytes to be transmitted in UART mode.     */
/* These bits can be programmed only when the UART bit is set. TDFL[0:1] = Transmit buffer size - 1:     */
/* 00: Transmit buffer size = 1                                                                          */
/* 01: Transmit buffer size = 2                                                                          */
/* 10: Transmit buffer size = 3                                                                          */
/* 11: Transmit buffer size = 4                                                                          */

/**
* @brief    UARTCR registers - Transmitter Data Field length.
* @details  The following macro set the number of bytes to be transmitted in UART mode to 1.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_TX_BUFF_1_BYTE_Set(offset)  ( REG_BIT_CLEAR32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_TX_BUFF_SIZE_4_BYTES_MASK) )
/**
* @brief    UARTCR registers - Transmitter Data Field length.
* @details  The following macro set the number of bytes to be transmitted in UART mode to 2.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_TX_BUFF_2_BYTES_Set(offset) ( REG_BIT_SET32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_TX_BUFF_SIZE_2_BYTES_MASK) )
/**
* @brief    UARTCR registers - Transmitter Data Field length.
* @details  The following macro set the number of bytes to be transmitted in UART mode to 3.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_TX_BUFF_3_BYTES_Set(offset) ( REG_BIT_SET32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_TX_BUFF_SIZE_3_BYTES_MASK) )
/**
* @brief    UARTCR registers - Transmitter Data Field length.
* @details  The following macro set the number of bytes to be transmitted in UART mode to 4.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_TX_BUFF_4_BYTES_Set(offset) ( REG_BIT_SET32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_TX_BUFF_SIZE_4_BYTES_MASK) )

/* Receiver Data Field length. These bits set the number of bytes to be received in UART mode.           */
/* These bits can be programmed only when the UART bit is set. RDFL[0:1] = Receive buffer size - 1:      */
/* 00: Receive buffer size = 1                                                                           */
/* 01: Receive buffer size = 2                                                                           */
/* 10: Receive buffer size = 3                                                                           */
/* 11: Receive buffer size = 4                                                                           */

/**
* @brief    UARTCR registers - Transmitter Data Field length.
* @details  The following macro set the number of bytes to be received in UART mode to 1.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_RX_BUFF_1_BYTE_Set(offset)  ( REG_BIT_CLEAR32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_RX_BUFF_SIZE_4_BYTES_MASK) )
/**
* @brief    UARTCR registers - Transmitter Data Field length.
* @details  The following macro set the number of bytes to be received in UART mode to 2.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_RX_BUFF_2_BYTES_Set(offset) ( REG_BIT_SET32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_RX_BUFF_SIZE_2_BYTES_MASK) )
/**
* @brief    UARTCR registers - Transmitter Data Field length.
* @details  The following macro set the number of bytes to be received in UART mode to 3.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_RX_BUFF_3_BYTES_Set(offset) ( REG_BIT_SET32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_RX_BUFF_SIZE_3_BYTES_MASK) )
/**
* @brief    UARTCR registers - Transmitter Data Field length.
* @details  The following macro set the number of bytes to be received in UART mode to 4.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_RX_BUFF_4_BYTES_Set(offset) ( REG_BIT_SET32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_RX_BUFF_SIZE_4_BYTES_MASK) )

/* Receiver Enable. This bit can be programmed only when the UART bit is set.                            */
/* 0: Receiver disable                                                                                   */
/* 1: Receiver enable                                                                                    */

/**
* @brief    UARTCR registers - Receiver Enable.
* @details  Enables the RX in UART mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_RX_Enable(offset)  ( REG_BIT_SET32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_RXEN_MASK) )

/**
* @brief    UARTCR registers - Receiver Disable.
* @details  Disables the RX in UART mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_RX_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_RXEN_MASK) )

/* Transmitter Enable. This bit can be programmed only when the UART bit is set. Note: Transmission starts*/
/* when this bit is set and when writing DATA0 in the BDRL register.                                     */
/* 0: Transmitter disable                                                                                */
/* 1: Transmitter enable                                                                                 */

/**
* @brief    UARTCR registers - Transmitter Enable.
* @details  Enables the TX in UART mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_TX_Enable(offset)  ( REG_BIT_SET32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_TXEN_MASK) )

/**
* @brief    UARTCR registers - Transmitter Disable.
* @details  Disables the TX in UART mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_TX_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_TXEN_MASK) )

/* Odd Parity. This bit can be programmed in Initialization mode only when the UART bit is set.          */
/* 0: Sent parity is even                                                                                */
/* 1: Sent parity is odd                                                                                 */

/**
* @brief    UARTCR registers - Even Parity.
* @details  Set the Even Parity in UART mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_UART_EVEN_PARITY_Set(offset) ( REG_BIT_CLEAR32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_TXEN_MASK) )

/**
* @brief    UARTCR registers - Odd Parity.
* @details  Set the Odd Parity in UART mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_ODD_PARITY_Set(offset)  ( REG_BIT_SET32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_TXEN_MASK) )

/* Parity Control Enable. This bit can be programmed in Initialization mode only when the UART bit is set.*/
/* 0: Parity transmit/check disable                                                                       */
/* 1: Parity transmit/check enable                                                                        */

/**
* @brief    UARTCR registers - Parity Control Enable.
* @details  Enable the Parity transmit/check in UART mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_UART_PARITY_CONTROL_Enable(offset)  ( REG_BIT_SET32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_PCE_MASK) )

/**
* @brief    UARTCR registers - Parity Control Disable.
* @details  Disable the Parity transmit/check in UART mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*
* @violates @ref Reg_eSys_LINFlex_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_UART_PARITY_CONTROL_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_PCE_MASK) )

/* Word Length in UART mode. This bit can be programmed in Initialization mode only when the UART bit is set.*/
/* 0: 7-bit data + parity bit                                                                                */
/* 1: 8-bit data (or 9-bit if PCE is set)                                                                    */

/**
* @brief    UARTCR registers - Word Length in UART mode.
* @details  Set the 7-bit data + parity bit in UART mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_8_BITS_DATA_PARITY_Set(offset) ( REG_BIT_SET32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_WL_MASK) )

/**
* @brief    UARTCR registers - Word Length in UART mode.
* @details  Set the 8-bit data (or 9-bit if PCE is set) in UART mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_7_BITS_DATA_PARITY_Set(offset) ( REG_BIT_CLEAR32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_WL_MASK) )

/* UART mode enable. This bit can be programmed in Initialization mode only.                             */
/* 0: LIN mode                                                                                           */
/* 1: UART mode                                                                                          */

/**
* @brief    UARTCR registers - UART mode enable.
* @details  Enables the UART mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_MODE_Set(offset) ( REG_BIT_SET32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_UART_MASK) )

/**
* @brief    UARTCR registers - LIN mode enable.
* @details  Enables the LIN mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LIN_MODE_Set(offset) ( REG_BIT_CLEAR32(LINFLEX_UARTCR(offset), LINFLEX_UARTCR_UART_MASK) )

/* -----------------------------------------UARTSR register-------------------------------------------------------*/

/* Stuck at zero Flag. This bit is set by hardware when the bus is dominant for more than a 100-bit time.*/
/* It is cleared by software.                                                                            */

/**
* @brief    UARTSR registers - Stuck at zero Flag.
* @details  This macro read the bit indicating to the software that bus is dominant for
*               more than a 100-bit time.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_SZF_Read(offset)   ( ( ( REG_READ32(LINFLEX_UARTSR(offset)) & LINFLEX_UARTSR_SZF_MASK ) == LINFLEX_UARTSR_SZF_MASK) ? TRUE : FALSE )

/**
* @brief    UARTSR registers - Stuck at zero Flag.
* @details  This macro clears the Stuck at zero Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_SZF_Clear(offset)   ( REG_WRITE32(LINFLEX_UARTSR(offset), LINFLEX_UARTSR_SZF_MASK ))

/* OCF Output Compare Flag. An interrupt is generated if the OCIE bit in LINIER register is set.         */
/* 0: No output compare event occurred                                                                   */
/* 1: The content of the counter has matched the content of OC1[0:7] or OC2[0:7] in LINOCR.              */

/**
* @brief    UARTSR registers - Output Compare Flag.
* @details  This macro read the bit indicating to the software that the counter has
*               matched the content of OC1[0:7] or OC2[0:7] in LINOCR.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_OCF_Read(offset)  ( ( ( REG_READ32(LINFLEX_UARTSR(offset)) & LINFLEX_UARTSR_OCF_MASK ) == LINFLEX_UARTSR_OCF_MASK) ? TRUE : FALSE )

/**
* @brief    UARTSR registers - Output Compare Flag.
* @details  This macro clears the Output Compare Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_OCF_Clear(offset) ( REG_WRITE32(LINFLEX_UARTSR(offset), LINFLEX_UARTSR_OCF_MASK ))

/* Parity Error Flag Rx3. This bit indicates if there is a parity error in the corresponding received byte*/
/* (Rx3). No interrupt is generated if this error occurs.                                                */
/* 0: No parity error                                                                                    */
/* 1: Parity error                                                                                       */

/**
* @brief    UARTSR registers - Parity Error Flag Rx3.
* @details  This macro read the bit indicating to the software that a parity error
*               in the corresponding received byte (Rx3).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_PE3_Read(offset)  ( ( ( REG_READ32(LINFLEX_UARTSR(offset)) & LINFLEX_UARTSR_PE3_MASK ) == LINFLEX_UARTSR_PE3_MASK) ? TRUE : FALSE )

/**
* @brief    UARTSR registers - Parity Error Flag Rx3.
* @details  This macro clears the Parity Error Flag Rx3.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_PE3_Clear(offset) ( REG_WRITE32(LINFLEX_UARTSR(offset), LINFLEX_UARTSR_PE3_MASK ))

/* Parity Error Flag Rx2. This bit indicates if there is a parity error in the corresponding received byte*/
/* (Rx2). No interrupt is generated if this error occurs.                                                */
/* 0: No parity error                                                                                    */
/* 1: Parity error                                                                                       */

/**
* @brief    UARTSR registers - Parity Error Flag Rx2.
* @details  This macro read the bit indicating to the software that a parity error
*               in the corresponding received byte (Rx2).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_PE2_Read(offset)  ( ( ( REG_READ32(LINFLEX_UARTSR(offset)) & LINFLEX_UARTSR_PE2_MASK ) == LINFLEX_UARTSR_PE2_MASK) ? TRUE : FALSE )

/**
* @brief    UARTSR registers - Parity Error Flag Rx2.
* @details  This macro clears the Parity Error Flag Rx2.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_PE2_Clear(offset) ( REG_WRITE32(LINFLEX_UARTSR(offset), LINFLEX_UARTSR_PE2_MASK ))

/* Parity Error Flag Rx1. This bit indicates if there is a parity error in the corresponding received byte*/
/* (Rx1). No interrupt is generated if this error occurs.                                                */
/* 0: No parity error                                                                                    */
/* 1: Parity error                                                                                       */

/**
* @brief    UARTSR registers - Parity Error Flag Rx1.
* @details  This macro read the bit indicating to the software that a parity error
*               in the corresponding received byte (Rx1).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_PE1_Read(offset)  ( ( ( REG_READ32(LINFLEX_UARTSR(offset)) & LINFLEX_UARTSR_PE1_MASK ) == LINFLEX_UARTSR_PE1_MASK) ? TRUE : FALSE )

/**
* @brief    UARTSR registers - Parity Error Flag Rx1.
* @details  This macro clears the Parity Error Flag Rx1.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_PE1_Clear(offset) ( REG_WRITE32(LINFLEX_UARTSR(offset), LINFLEX_UARTSR_PE1_MASK ))

/* Parity Error Flag Rx0. This bit indicates if there is a parity error in the corresponding received byte*/
/* (Rx0). No interrupt is generated if this error occurs.                                                */
/* 0: No parity error                                                                                    */
/* 1: Parity error                                                                                       */

/**
* @brief    UARTSR registers - Parity Error Flag Rx0.
* @details  This macro read the bit indicating to the software that a parity error
*               in the corresponding received byte (Rx0).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_PE0_Read(offset)  ( ( ( REG_READ32(LINFLEX_UARTSR(offset)) & LINFLEX_UARTSR_PE0_MASK ) == LINFLEX_UARTSR_PE0_MASK) ? TRUE : FALSE )

/**
* @brief    UARTSR registers - Parity Error Flag Rx0.
* @details  This macro clears the Parity Error Flag Rx0.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_PE0_Clear(offset) ( REG_WRITE32(LINFLEX_UARTSR(offset), LINFLEX_UARTSR_PE0_MASK ))

/* Release Message Buffer. This bit is cleared by hardware in Initialization mode.                       */
/* (Rx0). No interrupt is generated if this error occurs.                                                */
/* 0: Buffer is free                                                                                     */
/* 1: Buffer ready to be read by software. This bit must be cleared by software after reading data       */
/*    received in the buffer.                                                                            */

/**
* @brief    UARTSR registers - Release Message Buffer.
* @details  This macro read the Message Buffer to verify if it's free.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_RMB_Read(offset)  ( ( ( REG_READ32(LINFLEX_UARTSR(offset)) & LINFLEX_UARTSR_RMB_MASK ) == LINFLEX_UARTSR_RMB_MASK) ? TRUE : FALSE )

/**
* @brief    UARTSR registers - Release Message Buffer.
* @details  This macro releases the Message Buffer.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_RMB_Clear(offset) ( REG_WRITE32(LINFLEX_UARTSR(offset), LINFLEX_UARTSR_RMB_MASK ))

/* Framing Error Flag. This bit is set by hardware and indicates to the software that LINFlex has detected*/
/* a framing error (invalid stop bit).                                                                   */

/**
* @brief    UARTSR registers - Framing Error Flag.
* @details  This macro read the bit indicating to the software that LINFlex has detected
*               a framing error (invalid stop bit).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_FEF_Read(offset)  ( ( ( REG_READ32(LINFLEX_UARTSR(offset)) & LINFLEX_UARTSR_FEF_MASK ) == LINFLEX_UARTSR_FEF_MASK) ? TRUE : FALSE )

/**
* @brief    UARTSR registers - Framing Error Flag.
* @details  This macro clears the Framing Error Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_FEF_Clear(offset) ( REG_WRITE32(LINFLEX_UARTSR(offset), LINFLEX_UARTSR_FEF_MASK ))

/* Buffer Overrun Flag. This bit is set by hardware when a new data byte is received and the buffer full */
/* flag is not cleared. If RBLM in LINCR1 is set then the new byte received is discarded. If RBLM is reset*/
/* then the new byte overwrites buffer. it can be cleared by software.                                   */

/**
* @brief    UARTSR registers - Buffer Overrun Flag.
* @details  This macro read the bit indicating to the software that a new data byte is received
*               and the buffer full flag is not cleared.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_BOF_Read(offset)  ( ( ( REG_READ32(LINFLEX_UARTSR(offset)) & LINFLEX_UARTSR_BOF_MASK ) == LINFLEX_UARTSR_BOF_MASK) ? TRUE : FALSE )

/**
* @brief    UARTSR registers - Buffer Overrun Flag.
* @details  This macro clears the Buffer Overrun Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_BOF_Clear(offset) ( REG_WRITE32(LINFLEX_UARTSR(offset), LINFLEX_UARTSR_BOF_MASK ))

/* UART receive pin state. This bit reflects the current status of UARTRX pin for diagnostic purposes.   */

/**
* @brief    UARTSR registers - UART receive pin state.
* @details  This macro read the bit reflecting the current status of UARTRX pin
*               for diagnostic purposes.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_RPS_Read(offset)   (( REG_READ32(LINFLEX_UARTSR(offset)) & LINFLEX_UARTSR_RPS_MASK ))

/* Wake-up Flag. This bit is set by hardware and indicates to the software that LINFlex has detected a   */
/* falling edge on the LINRX pin in Sleep mode. This bit must be cleared by software. It is reset by     */
/* hardware in Initialization mode. An interrupt is generated if WUIE bit in LINIER is set.              */

/**
* @brief    UARTSR registers - Wake-up Flag.
* @details  This macro read the bit indicating to the software that LINFlex has detected a
*               falling edge on the LINRX pin in Sleep mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_WUF_Read(offset)  ( ( ( REG_READ32(LINFLEX_UARTSR(offset)) & LINFLEX_UARTSR_WUF_MASK ) == LINFLEX_UARTSR_WUF_MASK) ? TRUE : FALSE )

/**
* @brief    UARTSR registers - Wake-up Flag.
* @details  This macro clears the Wake-up Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_WUF_Clear(offset)     ( REG_WRITE32(LINFLEX_UARTSR(offset), LINFLEX_UARTSR_WUF_MASK) )

/* Data Reception Completed Flag. This bit is set by hardware and indicates the data reception is        */
/* completed, that is, the number of bytes programmed in RDFL[0:1] in UARTCR have been received. This bit*/
/* must be cleared by software. It is reset by hardware in Initialization mode. An interrupt is generated*/
/* if DRIE bit in LINIER is set. Note: In UART mode, this flag is set in case of framing error, parity   */
/* error or overrun.                                                                                     */

/**
* @brief    UARTSR registers - Data Reception Completed Flag.
* @details  This macro read the bit indicating to the software that the data reception is
*               completed.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_DRF_Read(offset)    ( ( ( REG_READ32(LINFLEX_UARTSR(offset)) & LINFLEX_UARTSR_DRF_MASK ) == LINFLEX_UARTSR_DRF_MASK) ? TRUE : FALSE )

/**
* @brief    UARTSR registers - Data Reception Completed Flag.
* @details  This macro clears the Data Reception Completed Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_DRF_Clear(offset) ( REG_WRITE32(LINFLEX_UARTSR(offset), LINFLEX_UARTSR_DRF_MASK) )

/* Data Transmission Completed Flag. This bit is set by hardware and indicates the data transmission is  */
/* completed, that is, the number of bytes programmed in TDFL[0:1] have been transmitted. This bit must  */
/* be cleared by software. It is reset by hardware in Initialization mode. An interrupt is generated if  */
/* DTIE bit in LINIER is set.                                                                            */

/**
* @brief    UARTSR registers - Data Transmission Completed Flag.
* @details  This macro read the bit indicating to the software that the data transmission is
*               completed.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_DTF_Read(offset)    ( ( ( REG_READ32(LINFLEX_UARTSR(offset)) & LINFLEX_UARTSR_DTF_MASK ) == LINFLEX_UARTSR_DTF_MASK) ? TRUE : FALSE )

/**
* @brief    UARTSR registers - Data Transmission Completed Flag.
* @details  This macro clears the Data Transmission Completed Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_DTF_Clear(offset) ( REG_WRITE32(LINFLEX_UARTSR(offset), LINFLEX_UARTSR_DTF_MASK) )

/* Noise Flag. This bit is set by hardware when noise is detected on a received character. This bit is   */
/* cleared by software.                                                                                  */

/**
* @brief    UARTSR registers - Noise Flag.
* @details  This macro read the bit indicating to the software that noise is
*               detected on a received character.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_NF_Read(offset)  ( ( ( REG_READ32(LINFLEX_UARTSR(offset)) & LINFLEX_UARTSR_NF_MASK ) == LINFLEX_UARTSR_NF_MASK) ? TRUE : FALSE )

/**
* @brief    UARTSR registers - Noise Flag.
* @details  This macro clears the Noise Flag.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_UART_NF_Clear(offset) ( REG_WRITE32(LINFLEX_UARTSR(offset), LINFLEX_UARTSR_NF_MASK ))
/* -----------------------------------------LINTCSR register--------------------------------------*/

/**
* @brief    LINFLEX registers - LINTCSR register bit masks.
* @details  Reset LINTCSR macro.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_LINTCSR_Reset(offset) ( REG_BIT_SET32(LINFLEX_LINTCSR(offset), LINFLEX_LINTCSR_RESET_MASK) )

/* LIN timeout mode. This bit can be set/cleared in Initialization mode only.                     */
/* - 0 LIN timeout mode (header, response and frame timeout detection).                           */
/* - 1 Output compare mode.                                                                       */

/**
* @brief    LINTCSR registers - Output compare mode.
* @details  Set the Output compare mode.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_LIN_TIMEOUT_MODE_Set(offset)    ( REG_BIT_CLEAR32(LINFLEX_LINTCSR(offset), LINFLEX_LINTCSR_LTOM_MASK) )

/**
* @brief    LINTCSR registers - LIN timeout mode.
* @details  Set the LIN timeout mode (header, response and frame timeout detection).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_OUTPUT_COMPARE_MODE_Set(offset) ( REG_BIT_SET32(LINFLEX_LINTCSR(offset), LINFLEX_LINTCSR_LTOM_MASK) )

/* Idle on Timeout. This bit can be set/cleared in Initialization mode only.                      */
/* - 0 LIN state machine not reset to Idle on timeout event.                                      */
/* - 1 LIN state machine reset to Idle on timeout event.                                          */

/**
* @brief    LINTCSR registers - Idle on Timeout.
* @details  LIN state machine not reset to Idle on timeout event.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_NOT_RESET_STATE_MACHINE_TO_IOT_Set(offset) ( REG_BIT_CLEAR32(LINFLEX_LINTCSR(offset), LINFLEX_LINTCSR_IOT_MASK) )

/**
* @brief    LINTCSR registers - Idle on Timeout.
* @details  LIN state machine reset to Idle on timeout event.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_RESET_STATE_MACHINE_TO_IOT_Set(offset)     ( REG_BIT_SET32(LINFLEX_LINTCSR(offset), LINFLEX_LINTCSR_IOT_MASK) )

/* Timeout counter enable. TOCE bit is configurable by software in Initialization mode. If LIN state is  */
/* not Init and if timer is in LIN timeout mode, then hardware takes control of TOCE bit.                */
/* - 0 Timeout counter disable. OCF bit in LINESR or UARTSR is not set on an output compare event.       */
/* - 1 Timeout counter enable. OCF bit is set if an output compare event occurs.                         */

/**
* @brief    LINTCSR registers - Timeout counter disable.
* @details  Timeout counter disable. OCF bit in LINESR or UARTSR is not set on an output compare event
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_TIMEOUT_COUNTER_Disable(offset) ( REG_BIT_CLEAR32(LINFLEX_LINTCSR(offset), LINFLEX_LINTCSR_TOCE_MASK) )

/**
* @brief    LINTCSR registers - Timeout counter enable.
* @details  Timeout counter enable. OCF bit is set if an output compare event occurs.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_TIMEOUT_COUNTER_Enable(offset)  ( REG_BIT_SET32(LINFLEX_LINTCSR(offset), LINFLEX_LINTCSR_TOCE_MASK) )

/* Counter Value. These bits indicate the LIN Timeout counter value.                              */

/**
* @brief    LINTCSR registers - Timeout counter enable.
* @details  Timeout counter enable. OCF bit is set if an output compare event occurs.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_COUNTER_VALUE_Read(offset)  ( REG_READ32(LINFLEX_LINTCSR(offset)) & LINFLEX_LINTCSR_CNT_MASK )

/**
* @brief    LINTCSR registers - Timeout counter enable.
* @details  Timeout counter enable. OCF bit is set if an output compare event occurs.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_COUNTER_VALUE_Reset(offset) ( REG_BIT_SET32(LINFLEX_LINTCSR(offset), LINFLEX_LINTCSR_CNT_MASK) )

/* -----------------------------------------LINOCR register---------------------------------------*/

/* Output compare 2 value. These bits contain the value to be compared to the value of bits CNT[0:7] in  */
/* LINTCSR. If LTOM in the LINTCSR register is set, these bits are read-only.                            */

/**
* @brief    LINOCR registers - Read Output compare 2 value.
* @details  Read the Output compare 2 value.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_OC2_Read(offset)       ( (REG_READ32(LINFLEX_LINOCR(offset)) & LINFLEX_LINOCR_OC2_MASK)>>8U )

/**
* @brief    LINOCR registers - Set Output compare 2 value.
* @details  Set the Output compare 2 value.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
*/
#define LINFLEX_LLM_OC2_Set(offset, value) ( REG_WRITE32(LINFLEX_LINOCR(offset), (value & LINFLEX_LINOCR_OC2_MASK)))

/* Output compare 1 value. These bits contain the value to be compared to the value of bits CNT[0:7] in  */
/* LINTCSR. If LTOM in the LINTCSR register is set, these bits are read-only.                            */

/**
* @brief    LINOCR registers - Read Output compare 1 value.
* @details  Read the Output compare 1 value.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_OC1_Read(offset)       (REG_READ32(LINFLEX_LINOCR(offset)) & LINFLEX_LINOCR_OC1_MASK)

/**
* @brief    LINOCR registers - Set Output compare 1 value.
* @details  Set the Output compare 1 value.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
*/
#define LINFLEX_LLM_OC1_Set(offset, value) ( REG_WRITE32(LINFLEX_LINOCR(offset), (value & LINFLEX_LINOCR_OC1_MASK)))

/* -----------------------------------------LINTOCR register--------------------------------------*/

/* Response timeout value. This register contains the response timeout duration (in bit time) for 1 byte.*/
/* The reset value is 0Eh = 14, corresponding to TResponse_Maximum = 1.4 x TResponse_Nominal.            */

/**
* @brief    LINTOCR registers - Read Response timeout value.
* @details  Read the Response timeout value.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_RTO_Read(offset)       ( (REG_READ32(LINFLEX_LINTOCR(offset)) & LINFLEX_LINTOCR_RTO_MASK)>>8U )

/**
* @brief    LINTOCR registers - Set Response timeout value.
* @details  Set the Response timeout value.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
*/
#define LINFLEX_LLM_RTO_Set(offset, value) ( REG_WRITE32(LINFLEX_LINTOCR(offset), (value & LINFLEX_LINTOCR_RTO_MASK))) 

/* Header timeout value. This register contains the header timeout duration (in bit time). This value does*/
/* not include the first 11 dominant bits of the Break. The reset value is the 25h = 37, corresponding to*/
/* THeader_Maximum in the LIN specification. HTO[0:6] can be written only for Slave mode.                */

/**
* @brief    LINTOCR registers - Read Header timeout value.
* @details  Read the Header timeout value.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_HTO_Read(offset)       ( REG_READ32(LINFLEX_LINTOCR(offset)) & LINFLEX_LINTOCR_HTO_MASK )

/**
* @brief    LINTOCR registers - Set Header timeout value.
* @details  Set the Header timeout value.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
*/
#define LINFLEX_LLM_HTO_Set(offset, value) ( REG_WRITE32(LINFLEX_LINTOCR(offset), (value & LINFLEX_LINTOCR_HTO_MASK))) 

/* -----------------------------------------LINCFR register---------------------------------------*/

/* Checksum bits. When CCD bit in LINCR1 is cleared these bits are read-only. When CCD bit is set, these */
/* bits are read/write.                                                                                  */

/**
* @brief    LINCFR registers - Read Checksum bits.
* @details  Read the Checksum bits.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_CF_Read(offset)       ( REG_AREAD32(LINFLEX_LINCFR(offset), 0x08) )

/**
* @brief    LINCFR registers - Set Header timeout value.
* @details  Set the Checksum bits.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
*/
#define LINFLEX_LLM_CF_Set(offset, value) ( REG_AWRITE32(LINFLEX_LINCFR(offset), 0x08, value) )

/* -----------------------------------------LINCR2 register---------------------------------------*/

/* Idle on Bit Error. This bit can be set/cleared in Initialization mode only.                    */
/* - 0 Bit error does not reset LIN state machine.                                                */
/* - 1 Bit error reset LIN state machine.                                                         */

/**
* @brief    LINCR2 registers - LIN state machine does not reset on Bit Error.
* @details  Bit error does not reset LIN state machine.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*
* @violates @ref Reg_eSys_LINFlex_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_NOT_RESET_STATE_MACHINE_ON_IOBE_Set(offset) ( REG_BIT_CLEAR32(LINFLEX_LINCR2(offset), LINFLEX_LINCR2_IOBE_MASK) )

/**
* @brief    LINCR2 registers - LIN state machine reset on Bit Error.
* @details  Bit error reset LIN state machine.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*
* @violates @ref Reg_eSys_LINFlex_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_RESET_STATE_MACHINE_ON_IOBE_Set(offset)     ( REG_BIT_SET32(LINFLEX_LINCR2(offset), LINFLEX_LINCR2_IOBE_MASK) )

/* Idle on Identifier Parity Error. This bit can be set/cleared in Initialization mode only.      */
/* - 0 Identifier Parity error does not reset LIN state machine.                                  */
/* - 1 Identifier Parity error reset LIN state machine.                                           */

/**
* @brief    LINCR2 registers - LIN state machine does not reset on Identifier Parity Error.
* @details  Identifier Parity error does not reset LIN state machine.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*
* @violates @ref Reg_eSys_LINFlex_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_NOT_RESET_STATE_MACHINE_ON_IOPE_Set(offset) ( REG_BIT_CLEAR32(LINFLEX_LINCR2(offset), LINFLEX_LINCR2_IOPE_MASK) )

/**
* @brief    LINCR2 registers - LIN state machine reset on Identifier Parity Error.
* @details  Identifier Parity error reset LIN state machine.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*
* @violates @ref Reg_eSys_LINFlex_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
* @violates @ref Reg_eSys_LINFlex_h_REF_4 This is required as per Autosar Requirement.
*/
#define LINFLEX_LLM_RESET_STATE_MACHINE_ON_IOPE_Set(offset)     ( REG_BIT_SET32(LINFLEX_LINCR2(offset), LINFLEX_LINCR2_IOPE_MASK) )

/* Wake-up Generation Request. Setting this bit generates a wake-up pulse. It is reset by hardware when  */
/* the wake-up character has been transmitted. The character sent is copied from DATA0 in BDRL buffer.   */
/* Note that this bit cannot be set in Sleep mode. Software has to exit Sleep mode before requesting a   */
/* wake-up. Bit error is not checked when transmitting the wake-up request.                              */

/**
* @brief    LINCR2 registers - Wake-up Generation Request.
* @details  Setting this bit generates a wake-up pulse.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_WURQ_Set(offset)     ( REG_BIT_SET32(LINFLEX_LINCR2(offset), LINFLEX_LINCR2_WURQ_MASK) )

/* Data Discard Request. Set by software to stop data reception if the frame does not concern the node.  */
/* This bit is reset by hardware once LINFlex has moved to idle state. In Slave mode, this bit can be set*/
/* only when HRF bit in LINSR is set and identifier did not match any filter.                            */

/**
* @brief    LINCR2 registers - Data Discard Request.
* @details  Setting this bit stop data reception if the frame does not concern the node.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DDRQ_Set(offset)     ( REG_BIT_SET32(LINFLEX_LINCR2(offset), LINFLEX_LINCR2_DDRQ_MASK) )

/* Data Transmission Request. Set by software in Slave mode to request the transmission of the LIN Data  */
/* field stored in the Buffer data register. This bit can be set only when HRF bit in LINSR is set.      */
/* Cleared by hardware when the request has been completed or aborted or on an error condition. In Master*/
/* mode, this bit is set by hardware when DIR bit in BIDR is set and header transmission is completed.   */

/**
* @brief    LINCR2 registers - Data Transmission Request.
* @details  Set this bit in Slave mode to request the transmission of the LIN Data.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DTRQ_Set(offset)     ( REG_BIT_SET32(LINFLEX_LINCR2(offset), LINFLEX_LINCR2_DTRQ_MASK) )

/* Abort Request. Set by software to abort the current transmission. Cleared by hardware when the        */
/* transmission has been aborted. LINFlex aborts the transmission at the end of the current bit. This bit*/
/* can also abort a wake-up request. It can also be used in UART mode.                                   */

/**
* @brief    LINCR2 registers - Abort Request.
* @details  Abort the current transmission.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_ABRQ_Set(offset)     ( REG_BIT_SET32(LINFLEX_LINCR2(offset), LINFLEX_LINCR2_ABRQ_MASK) )

/**
* @brief    LINCR2 registers - Read Abort Request bits.
* @details  Read the Abort Request bits.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_ABRQ_Read(offset)    ( ( ( REG_READ32(LINFLEX_LINCR2(offset)) & LINFLEX_LINCR2_ABRQ_MASK ) == LINFLEX_LINCR2_ABRQ_MASK) ? TRUE : FALSE )

/* Header Transmission Request. Set by software to request the transmission of the LIN header. Cleared by*/
/* hardware when the request has been completed or aborted. This bit has no effect in UART mode.         */

/**
* @brief    LINCR2 registers - Set Header Transmission Request.
* @details  Request the transmission of the LIN header.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_HTRQ_Set(offset)     ( REG_BIT_SET32(LINFLEX_LINCR2(offset), LINFLEX_LINCR2_HTRQ_MASK) )

/* -----------------------------------------BIDR register-----------------------------------------*/

/* Data Field Length. These bits define the number of data bytes in the response part of the frame.      */
/* DFL[0:5] = Number of data bytes - 1. Normally, LIN uses only DFL[0:2] to manage frames with a maximum */
/* of 8 bytes of data. Identifier filters are compatible with DFL[0:2] only. DFL[3:5] are provided to    */
/* manage extended frames.                                                                               */

/**
* @brief    BIDR registers - Read Data Field Length for Normal frames.
* @details  Read DFL[0:2] where DFL[0:2] = Number of data bytes in the response part of the frame - 1.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DFL_Normal_Read(offset)   (( REG_READ32(LINFLEX_BIDR(offset)) & LINFLEX_BIDR_DFL_NOR_MASK )  >> 10U)

/**
* @brief    BIDR registers - Read Data Field Length for Extended frames.
* @details  Read DFL[0:5] where DFL[0:5] = Number of data bytes in the response part of the frame - 1.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DFL_Extended_Read(offset) ( REG_READ32(LINFLEX_BIDR(offset)) & LINFLEX_BIDR_DFL_EXT_MASK )

/**
* @brief    BIDR registers - Set Data Field Length.
* @details  Set the Data Field Length.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
*/
#define LINFLEX_LLM_DFL_Set(offset, value)    ( REG_BIT_SET32(LINFLEX_BIDR(offset), ((value & LINFLEX_BIDR_DFL_SET_MASK) << 10U) ) )

/**
* @brief    BIDR registers - Clear Data Field Length.
* @details  Clear the Data Field Length bits.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DFL_Clear(offset)         ( REG_BIT_CLEAR32(LINFLEX_BIDR(offset), LINFLEX_BIDR_DFL_EXT_MASK) )

/* Direction. This bit controls the direction of the data field.                                  */
/* - 0 LINFlex receives the data and copy them in the BDRL and BDRM registers.                    */
/* - 1 LINFlex transmits the data from the BDR registers.                                         */

/**
* @brief    BIDR registers - Set Rx direction of the frame.
* @details  LINFLEX receives the data and copy them in the BDRL and BDRM registers.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_RX_DIRECTION_Set(offset)  ( REG_BIT_CLEAR32(LINFLEX_BIDR(offset), LINFLEX_BIDR_DIR_MASK) )

/**
* @brief    BIDR registers - Set Tx direction of the frame.
* @details  LINFLEX transmits the data from the BDR registers.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_TX_DIRECTION_Set(offset)  ( REG_BIT_SET32(LINFLEX_BIDR(offset), LINFLEX_BIDR_DIR_MASK) )

/* Classic Checksum. This bit controls the type of checksum applied on the current message.       */
/* - 0 Enhanced Checksum covering Identifier and Data fields. This is compatible with LIN specification  */
/*     2.0 and higher.                                                                            */
/* - 1 Classic Checksum covering Data fields only. This is compatible with LIN specification 1.3 and     */
/*     below.                                                                                     */

/**
* @brief    BIDR registers - Set Enhanced Checksum for the frame.
* @details  Set Enhanced Checksum covering Identifier and Data fields.
*               This is compatible with LIN specification 2.0 and higher.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_ENHANCED_CKS_Set(offset)  ( REG_BIT_CLEAR32(LINFLEX_BIDR(offset), LINFLEX_BIDR_CCS_MASK) )

/**
* @brief    BIDR registers - Set Classic Checksum for the frame.
* @details  Set Classic Checksum covering Data fields only.
*               This is compatible with LIN specification 1.3 and below.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_CLASSIC_CKS_Set(offset)   ( REG_BIT_SET32(LINFLEX_BIDR(offset), LINFLEX_BIDR_CCS_MASK) )

/* Identifier. Identifier part of the identifier field without the identifier parity.             */

/**
* @brief    BIDR registers - Read Frame Identifier.
* @details  Read the Identifier part of the identifier field without
*               the identifier parity.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_ID_Read(offset)           ( REG_READ32(LINFLEX_BIDR(offset)) & LINFLEX_BIDR_ID_MASK )

/**
* @brief    BIDR registers - Set Frame Identifier.
* @details  Set the Identifier part of the identifier field without
*               the identifier parity.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
*/
#define LINFLEX_LLM_ID_Set(offset, value)     ( REG_BIT_SET32(LINFLEX_BIDR(offset), (value & LINFLEX_BIDR_ID_MASK) ) )

/**
* @brief    BIDR registers - Clear Frame Identifier.
* @details  Clear the Identifier part of the identifier field without
*               the identifier parity.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_ID_Clear(offset)          ( REG_BIT_CLEAR32(LINFLEX_BIDR(offset), LINFLEX_BIDR_ID_MASK) )

/* -----------------------------------------BDRL register-----------------------------------------*/

/* Data Byte 3. Data byte 3 of the data field.                                                    */

/**
* @brief    BDRL registers - Read Data Byte 3.
* @details  Read the Data byte 3 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DATA3_Read(offset)        ( ( REG_READ32(LINFLEX_BDRL(offset)) & LINFLEX_BDRL_DATA3_MASK)>>24U )

/**
* @brief    BDRL registers - Clear Data Byte 3.
* @details  Clear the Data byte 3 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DATA3_Clear(offset)       ( REG_BIT_CLEAR32(LINFLEX_BDRL(offset), LINFLEX_BDRL_DATA3_MASK) )

/**
* @brief    BIDR registers - Set Data Byte 3.
* @details  Set the Data byte 3 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
* @violates @ref Reg_eSys_LINFlex_h_REF_7 C macros shall only expand to a braced initializer...
*/
#define LINFLEX_LLM_DATA3_Set(offset, value)  { \
                                        LINFLEX_LLM_DATA3_Clear(offset); \
                                        REG_BIT_SET32(LINFLEX_BDRL(offset), ((uint32)value << 24U) ); \
                                      }

/* Data Byte 2. Data byte 2 of the data field.                                                    */

/**
* @brief    BDRL registers - Read Data Byte 2.
* @details  Read the Data byte 2 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DATA2_Read(offset)        ( (REG_READ32(LINFLEX_BDRL(offset)) & LINFLEX_BDRL_DATA2_MASK)>>16U )

/**
* @brief    BDRL registers - Clear Data Byte 2.
* @details  Clear the Data byte 2 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DATA2_Clear(offset)       ( REG_BIT_CLEAR32(LINFLEX_BDRL(offset), LINFLEX_BDRL_DATA2_MASK) )

/**
* @brief    BIDR registers - Set Data Byte 2.
* @details  Set the Data byte 2 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
* @violates @ref Reg_eSys_LINFlex_h_REF_7 C macros shall only expand to a braced initializer...
*/
#define LINFLEX_LLM_DATA2_Set(offset, value)  { \
                                        LINFLEX_LLM_DATA2_Clear(offset); \
                                        REG_BIT_SET32(LINFLEX_BDRL(offset), ((uint32)value << 16U) ); \
                                      }

/* Data Byte 1. Data byte 1 of the data field.                                                    */

/**
* @brief    BDRL registers - Read Data Byte 1.
* @details  Read the Data byte 1 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DATA1_Read(offset)        ( (REG_READ32(LINFLEX_BDRL(offset)) & LINFLEX_BDRL_DATA1_MASK)>>8U )

/**
* @brief    BDRL registers - Clear Data Byte 1.
* @details  Clear the Data byte 1 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DATA1_Clear(offset)       ( REG_BIT_CLEAR32(LINFLEX_BDRL(offset), LINFLEX_BDRL_DATA1_MASK) )

/**
* @brief    BIDR registers - Set Data Byte 1.
* @details  Set the Data byte 1 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
* @violates @ref Reg_eSys_LINFlex_h_REF_7 C macros shall only expand to a braced initializer...
*/
#define LINFLEX_LLM_DATA1_Set(offset, value)  { \
                                        LINFLEX_LLM_DATA1_Clear(offset); \
                                        REG_BIT_SET32(LINFLEX_BDRL(offset), ((uint32)value << 8U) ); \
                                      }

/* Data Byte 0. Data byte 0 of the data field.                                                    */

/**
* @brief    BDRL registers - Read Data Byte 0.
* @details  Read the Data byte 0 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DATA0_Read(offset)        ( REG_READ32(LINFLEX_BDRL(offset)) & LINFLEX_BDRL_DATA0_MASK )

/**
* @brief    BDRL registers - Clear Data Byte 0.
* @details  Clear the Data byte 0 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DATA0_Clear(offset)       ( REG_BIT_CLEAR32(LINFLEX_BDRL(offset), LINFLEX_BDRL_DATA0_MASK) )

/**
* @brief    BIDR registers - Set Data Byte 0.
* @details  Set the Data byte 0 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
* @violates @ref Reg_eSys_LINFlex_h_REF_7 C macros shall only expand to a braced initializer...
*/
#define LINFLEX_LLM_DATA0_Set(offset, value)  { \
                                        LINFLEX_LLM_DATA0_Clear(offset); \
                                        REG_BIT_SET32(LINFLEX_BDRL(offset), value ); \
                                      }

/* Read all the BDRL register (Data Bytes number 3,2,1 and 0 of the data field).                  */

/**
* @brief    BDRL registers - Read all the BDRL register.
* @details  Read all the BDRL register (Data Bytes number 3,2,1 and 0 of the data field).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_BDRL_Read(offset)        ( REG_READ32(LINFLEX_BDRL(offset)))

/* Write the BDRL register (Data Bytes number 3,2,1 and 0 of the data field).                     */

/**
* @brief    BDRL registers - Write all the BDRL register.
* @details  Write all the BDRL register (Data Bytes number 3,2,1 and 0 of the data field).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
*/
#define LINFLEX_LLM_BDRL_Write(offset, value) (REG_WRITE32(LINFLEX_BDRL(offset), value ) )

/**
* @brief    BDRL registers - Is the BDRL register empty ?
* @details  Verify if the BDRL register is empty.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
*/
#define LINFLEX_LLM_IS_BDRL_EMPTY(offset)         ( ( ( REG_READ32(LINFLEX_BDRL(offset)) & \
                                                        LINFLEX_BDRL_EMPTY_MASK ) == \
                                                        LINFLEX_BDRM_EMPTY_MASK) ? TRUE : FALSE )
/* -----------------------------------------BDRM register-----------------------------------------*/

/* Data Byte 7. Data byte 7 of the data field.                                                    */

/**
* @brief    BDRL registers - Read Data Byte 7.
* @details  Read the Data byte 7 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DATA7_Read(offset)        ( (REG_READ32(LINFLEX_BDRM(offset)) & LINFLEX_BDRM_DATA7_MASK)>>24U )

/**
* @brief    BDRL registers - Clear Data Byte 7.
* @details  Clear the Data byte 7 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DATA7_Clear(offset)       ( REG_BIT_CLEAR32(LINFLEX_BDRM(offset), LINFLEX_BDRM_DATA7_MASK) )

/**
* @brief    BIDR registers - Set Data Byte 7.
* @details  Set the Data byte 7 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
* @violates @ref Reg_eSys_LINFlex_h_REF_7 C macros shall only expand to a braced initializer...
*/
#define LINFLEX_LLM_DATA7_Set(offset, value)  { \
                                        LINFLEX_LLM_DATA7_Clear(offset); \
                                        REG_BIT_SET32(LINFLEX_BDRM(offset), ((uint32)value << 24U) ); \
                                      }

/* Data Byte 6. Data byte 6 of the data field.                                                    */

/**
* @brief    BDRL registers - Read Data Byte 6.
* @details  Read the Data byte 6 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DATA6_Read(offset)        ( (REG_READ32(LINFLEX_BDRM(offset)) & LINFLEX_BDRM_DATA6_MASK)>>16U )

/**
* @brief    BDRL registers - Clear Data Byte 6.
* @details  Clear the Data byte 6 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DATA6_Clear(offset)       ( REG_BIT_CLEAR32(LINFLEX_BDRM(offset), LINFLEX_BDRM_DATA6_MASK) )

/**
* @brief    BIDR registers - Set Data Byte 6.
* @details  Set the Data byte 6 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
* @violates @ref Reg_eSys_LINFlex_h_REF_7 C macros shall only expand to a braced initializer...
*/
#define LINFLEX_LLM_DATA6_Set(offset, value)  { \
                                        LINFLEX_LLM_DATA6_Clear(offset); \
                                        REG_BIT_SET32(LINFLEX_BDRM(offset), ((uint32)value << 16U) ); \
                                      }

/* Data Byte 5. Data byte 5 of the data field.                                                    */

/**
* @brief    BDRL registers - Read Data Byte 5.
* @details  Read the Data byte 5 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DATA5_Read(offset)        ( (REG_READ32(LINFLEX_BDRM(offset)) & LINFLEX_BDRM_DATA5_MASK)>>8U )

/**
* @brief    BDRL registers - Clear Data Byte 5.
* @details  Clear the Data byte 5 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DATA5_Clear(offset)       ( REG_BIT_CLEAR32(LINFLEX_BDRM(offset), LINFLEX_BDRM_DATA5_MASK) )

/**
* @brief    BIDR registers - Set Data Byte 5.
* @details  Set the Data byte 5 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
* @violates @ref Reg_eSys_LINFlex_h_REF_7 C macros shall only expand to a braced initializer...
*/
#define LINFLEX_LLM_DATA5_Set(offset, value)  { \
                                        LINFLEX_LLM_DATA5_Clear(offset); \
                                        REG_BIT_SET32(LINFLEX_BDRM(offset), ((uint32)value << 8U) ); \
                                      }

/* Data Byte 4. Data byte 4 of the data field.                                                    */

/**
* @brief    BDRL registers - Read Data Byte 4.
* @details  Read the Data byte 4 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DATA4_Read(offset)        ( REG_READ32(LINFLEX_BDRM(offset)) & LINFLEX_BDRM_DATA4_MASK )

/**
* @brief    BDRL registers - Clear Data Byte 4.
* @details  Clear the Data byte 4 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_DATA4_Clear(offset)       ( REG_BIT_CLEAR32(LINFLEX_BDRM(offset), LINFLEX_BDRM_DATA4_MASK) )

/**
* @brief    BIDR registers - Set Data Byte 4.
* @details  Set the Data byte 4 of the data field.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
* @violates @ref Reg_eSys_LINFlex_h_REF_7 C macros shall only expand to a braced initializer...
*/
#define LINFLEX_LLM_DATA4_Set(offset, value)  { \
                                        LINFLEX_LLM_DATA4_Clear(offset); \
                                        REG_BIT_SET32(LINFLEX_BDRM(offset), (value ) ); \
                                      }

/* Read the BDRM register (Data Bytes number 7,6,5 and 4 of the data field).                      */

/**
* @brief    BDRM registers - Read all the BDRM register.
* @details  Read all the BDRM register (Data Bytes number 7,6,5 and 4 of the data field).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LLM_BDRM_Read(offset)        ( REG_READ32(LINFLEX_BDRM(offset)))

/* Write the BDRM register (Data Bytes number 7,6,5 and 4 of the data field).                     */

/**
* @brief    BDRM registers - Write all the BDRM register.
* @details  Write all the BDRM register (Data Bytes number 7,6,5 and 4 of the data field).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
*/
#define LINFLEX_LLM_BDRM_Write(offset, value) (REG_WRITE32(LINFLEX_BDRM(offset), value ) )

/**
* @brief    BDRM registers - Is the BDRM register empty ?
* @details  Verify if the BDRM register is empty.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* @violates @ref Reg_eSys_LINFlex_h_REF_6 Violates MISRA 2004 Required Rule 
*                19.10, arguments shall be enclosed in parentheses.
*/
#define LINFLEX_LLM_IS_BDRM_EMPTY(offset)         ( ( REG_READ32(LINFLEX_BDRM(offset)) == \
                                                                 LINFLEX_BDRM_EMPTY_MASK) ? \
                                                                 TRUE : FALSE )

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* REG_eSys_LINFlex_H */

/** @} */
