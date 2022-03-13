/**
*   @file    Reg_eSys_FlexCan.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - MPC560xB FlexCan Registers and Macros Definitions.
*   @details Header file for MPC560xB FlexCan Registers and Macros Definitions.
*
*   @addtogroup CAN_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : FLEXCAN
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


#ifndef REG_ESYS_FLEXCAN_H
#define REG_ESYS_FLEXCAN_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_FlexCan_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Reg_eSys_FlexCan_h_REF_3
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
* @section Reg_eSys_FlexCan_h_REF_4
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section Reg_eSys_FlexCan_h_REF_5
* Violates MISRA 2004 Required Rule 19.10, Within a definition of a function-like macro, 
* the arguments shall be enclosed in parentheses.
*
* @section Reg_eSys_FlexCan_h_REF_6
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
* @section Reg_eSys_FlexCan_h_REF_7
* Violates MISRA 2004 Required Rule  8.12, Array declared with unknown size.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "Reg_eSys.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @brief Internal micro-dependent versioning.
*/
#define CAN_VENDOR_ID_REGFLEX                    43
#define CAN_MODULE_ID_REGFLEX                    80
/* @violates @ref Reg_eSys_FlexCan_h_REF_6 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_MAJOR_VERSION_REGFLEX     4
/* @violates @ref Reg_eSys_FlexCan_h_REF_6 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_MINOR_VERSION_REGFLEX     0
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_3 Violates MISRA 2004 Required Rule 1.4, Identifier clash
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_6 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_REVISION_VERSION_REGFLEX  3
#define CAN_SW_MAJOR_VERSION_REGFLEX             1
#define CAN_SW_MINOR_VERSION_REGFLEX             0
#define CAN_SW_PATCH_VERSION_REGFLEX             1
/**@}*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief Memory size reserved for one Can controller
*/
#define FLEXCAN_OFFSET          ((uint32)0x00004000U)
/**
* @brief Offset for the first MB
*/
#define FLEXCAN_MB_OFFSET       ((uint32)0x00000080U)
/**
* @brief Offset for the RXIMR register
*/
#define FLEXCAN_RXIMR_OFFSET    ((uint32)0x00000880U)
/**
* @brief Mask for 32 bits register
*/
#define FLEXCAN_32BITMASK       ((uint32)0xFFFFFFFFU)
/**
* @brief Mask for 8 bits of IMASK registers that are reserved for Fifo
*/
#define FLEXCAN_FIFO_MASK       ((uint32)0x000000FFU)
/**
* @brief Define for left shifting 5 bits.
*/
#define FLEXCAN_MB_SHIFT5BIT      ((uint8)0x5U)
/**
* @brief Offset of the Standard ID in the ID reg of MB.
*/
#define FLEXCAN_STANDARD_ID_SHIFT ((uint32)18U)
/**
* @brief Offset of the LENGTH field in the MBCS register of MB.
*/
#define FLEXCAN_MBCS_LENGTH_SHIFT ((uint32)16U)
/**
* @brief Offset of the PRIO field in ID register of the MB.
*/
#define FLEXCAN_MB_ID_PRIO_SHIFT  ((uint32)28U)
/**
* @brief Mask for 32 index values (0 to 31 indexes).
*/
#define FLEXCAN_MASK_32BITS       ((uint32)0x1FU)

/**
* @{
* @brief Current architectures of FLEXcan have 32 or 64 MBs for each controller
*/
#define FLEXCAN_MB_32           (32U)
#define FLEXCAN_MB_64           (64U)
/**@}*/

/**
* @{
* @brief Define for MB data
*/
#define FLEXCAN_MB_DATABYTE_REG   ((uint32)4U)
#define FLEXCAN_MB_DATABYTE_FIRST ((uint32)0xFF000000U)
#define FLEXCAN_MB_DATABYTES      ((uint8)0x8U)
/**@}*/

#if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
/**
* @{
* @brief Define for MB data and interrupt mask intialization value
*/
#define CAN_MB_14                    ((uint8)14U)
#define CAN_MB_15                    ((uint8)15U)
#define CAN_TABLE_ID6                ((uint8)6U)
#define CAN_TABLE_ID7                ((uint8)7U)
#define INTERRUPT_MASKS_INIT_VALUE   ((uint8)0x0U)
/**@}*/
#endif

/**
* @brief Define used for Can_ControlerDescriptorType.ControllerOffset when controller is not enabled.
*/
#define FLEXCAN_NULL_OFFSET       ((uint8)0xFFU)


/*==================================================================================================
                BIT MASKS FOR SOFTWARE ERROR FLAGS
==================================================================================================*/
#if (CAN_WAKEUP_SUPPORT == STD_ON)
/**
* @brief MCR: wakeup software flag
*/
#define SWF_WAK_MASK    ((uint8)0x01U)
#endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
/**
* @brief CTRL: busoff software flag
*/
#define SWF_BOFF_MASK   ((uint8)0x02U)
/**
* @brief CTRL: error software flag
*/
#define SWF_ERR_MASK    ((uint8)0x04U)
/**
* @brief IMASK2, IMASK1: message buffers software flags
*/
#define SWF_MB_MASK     ((uint8)0x08U)
/**
* @brief MCR: tx/rx warning interrupts software flags
*/
#define SWF_WRNINT_MASK ((uint8)0x10U)


/*==================================================================================================
                CONTROLLER OPTIONS
==================================================================================================*/
/**
* @{
* @brief Controller options - set by the Tresos configuration
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_6 This is required as per autosar Requirement. */
#define CAN_CONTROLLERCONFIG_BUSOFFSWREC    ((uint32)0x00000001U)
#define CAN_CONTROLLERCONFIG_RXFIFO         ((uint32)0x00000002U)
#define CAN_CONTROLLERCONFIG_IDAM_A         ((uint32)0x00000004U)
#define CAN_CONTROLLERCONFIG_IDAM_B         ((uint32)0x00000008U)
#define CAN_CONTROLLERCONFIG_IDAM_C         ((uint32)0x00000010U)
#define CAN_CONTROLLERCONFIG_IDAM_D         ((uint32)0x00000020U)
#define CAN_CONTROLLERCONFIG_WAKEUP_SRC     ((uint32)0x00000040U)
#define CAN_CONTROLLERCONFIG_LPRIO_EN       ((uint32)0x00000080U)
#define CAN_CONTROLLERCONFIG_OVER_EN        ((uint32)0x00000100U)
#define CAN_CONTROLLERCONFIG_WARN_EN        ((uint32)0x00000200U)
#define CAN_CONTROLLERCONFIG_RXPOL_EN       ((uint32)0x00000400U)
#define CAN_CONTROLLERCONFIG_TXPOL_EN       ((uint32)0x00000800U)
#define CAN_CONTROLLERCONFIG_BOPOL_EN       ((uint32)0x00001000U)
#define CAN_CONTROLLERCONFIG_WKPOL_EN       ((uint32)0x00002000U)
#define CAN_CONTROLLERCONFIG_WRNINT_EN      ((uint32)0x00004000U)
#define CAN_CONTROLLERCONFIG_WAKSUP_EN      ((uint32)0x00008000U)
#define CAN_CONTROLLERCONFIG_ERR_EN         ((uint32)0x00020000U)
#if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
    #define CAN_CONTROLLERCONFIG_BCC_EN     ((uint32)0x00010000U)
#endif /* (CAN_BCC_SUPPORT_ENABLE == STD_ON) */
#define CAN_CONTROLLERCONFIG_IDAM_MASK      ((uint32)0x0000003CU)
/**@}*/

/*==================================================================================================
                            MESSAGE BUFFER BIT MASKS FOR ALL STRUCTURE
==================================================================================================*/
/**
* @brief MB code: bits 27:24 in CS reg
*/
#define FLEXCAN_MBCS_CODE         ((uint32)0x0F000000U)
/**
* @brief MB code: message buffer used for Tx
*/
#define FLEXCAN_MBCS_CODETX       ((uint32)0x08000000U)
/**
* @brief MB code: Transmit contents of Tx message buffer
*/
#define FLEXCAN_MBCS_CODETXEN     ((uint32)0x04000000U)
/**
* @brief MB code: transmit the message whenever a remote frame with a matching ID is received
*/
#define FLEXCAN_MBCS_CODETXRTR    ((uint32)0x02000000U)
/**
* @brief MB code: Abort transmission
*/
#define FLEXCAN_MBCS_CODETXABORT  ((uint32)0x01000000U)
/**
* @brief MB code: Message buffer used for Rx
*/
#define FLEXCAN_MBCS_CODERX       ((uint32)0x00000000U)
/**
* @brief MB code: Rx message buffer overrun (a new message arrived before the previous one was picked-up)
*/
#define FLEXCAN_MBCS_CODERXOVRR   ((uint32)0x06000000U)
/**
* @brief MB code: Rx message buffer empty
*/
#define FLEXCAN_MBCS_CODERXEMPTY  ((uint32)0x04000000U)
/**
* @brief MB code: Rx message buffer is full (a new message has arrived)
*/
#define FLEXCAN_MBCS_CODERXFULL   ((uint32)0x02000000U)
/**
* @brief MB code: MB busy and cannot be read
*/
#define FLEXCAN_MBCS_CODERXBUSY   ((uint32)0x01000000U)
/**
* @brief SRR bit, must be written as '1' in any Tx MB
*/
#define FLEXCAN_MBCS_SRR          ((uint32)0x00400000U)
/**
* @brief IDE bit, 0=standard ID, 1=extended ID
*/
#define FLEXCAN_MBCS_IDE          ((uint32)0x00200000U)
/**
* @brief RTR bit, 0=data frame, 1=remote frame
*/
#define FLEXCAN_MBCS_RTR          ((uint32)0x00100000U)
/**
* @brief DLC (data length code)
*/
#define FLEXCAN_MBCS_LENGTH       ((uint32)0x000F0000U)
/**
* @brief Time stamp of Rx and Tx frames (timer value captured at the time the beginning of the ID appears on the bus)
*/
#define FLEXCAN_MBCS_TIMESTAMP    ((uint32)0x0000FFFFU)
/**
* @brief Local Tx priority (added in front of the ID to determine Tx priority)
*/
#define FLEXCAN_MBID_PRIO         ((uint32)0xE0000000U)
/**
* @brief Extended (bits 0-28) ID
*/
#define FLEXCAN_MBID_ID_EXTENDED  ((uint32)0x1FFFFFFFU)
/**
* @brief IDE flag used in extended ID mode to identify whether the ID is Extended/Standard.(According to Can_IdType from SWS_Can_Driver.pdf of ASR3.0)
*/
#define FLEXCAN_MBC_ID_IDE           ((uint32)0x80000000U)
/**
* @brief Standard (bits 18-28) ID
*/
#define FLEXCAN_MBID_ID_STANDARD  ((uint32)0x1FFC0000U)


/*==================================================================================================
                    INTERRUPT MASKS & FLAGS REGISTERS:
                        IMASK2 (Base + 0x0024); IMASK1 (Base + 0x0028)
                        IFLAG2 (Base + 0x002C); IFLAG1 (Base + 0x0030)
==================================================================================================*/
/**
* @{
* @brief Imask and Iflag index registers
*/
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64 )
  #define FLEXCAN_IMASK2_INDEX  ((uint8)0U)
  #define FLEXCAN_IMASK1_INDEX  ((uint8)1U)
  #define FLEXCAN_IFLAG2_INDEX  ((uint8)0U)
  #define FLEXCAN_IFLAG1_INDEX  ((uint8)1U)
#else
  #define FLEXCAN_IMASK1_INDEX  ((uint8)0U)
  #define FLEXCAN_IFLAG1_INDEX  ((uint8)0U)
#endif
/**@}*/

/*==================================================================================================
                BIT MASKS FOR MODULE CONFIGURATION REGISTER: MCR (Base+0x0000)
==================================================================================================*/
/**
* @brief MCR bit31: Module Disable (module disabled when 1)
*/
#define FLEXCAN_MCR_MDIS      ((uint32)0x80000000U)
/**
* @brief MCR bit30: Freeze enable (enable to enter freeze mode when HALT is set)
*/
#define FLEXCAN_MCR_FRZ       ((uint32)0x40000000U)
/**
* @brief MCR bit29: FIFO mode enable
*/
#define FLEXCAN_MCR_FEN       ((uint32)0x20000000U)
/**
* @brief MCR bit28: Module Halt (module enters freeze mode when this bit is set providing the FRZ bit is set)
*/
#define FLEXCAN_MCR_HALT      ((uint32)0x10000000U)
/**
* @brief MCR bit27: Module Not Ready (either disabled or in freeze mode)
*/
#define FLEXCAN_MCR_NOTRDY    ((uint32)0x08000000U)
/**
* @brief MCR bit26: Wake Up Interrupt Mask (1 = Wake Up Interrupt is enabled, 0 = Wake Up Interrupt is disabled)
*/
#define FLEXCAN_MCR_WAK_MSK   ((uint32)0x04000000U)
/**
* @brief MCR bit25: Module Soft Reset (the bit remains set until reset is completed)
*/
#define FLEXCAN_MCR_SOFTRST   ((uint32)0x02000000U)
/**
* @brief MCR bit24: Freeze Mode Acknowledge
*/
#define FLEXCAN_MCR_FRZACK    ((uint32)0x01000000U)
/**
* @brief MCR bit23: Supervisor Mode (1 = Affected registers are in Supervisor memory space.
* @details    MCR bit23: Supervisor Mode (1 = Affected registers are in Supervisor memory space.
* Any access without supervisor permission behaves as though the access was done
*    to an unimplemented register location 0 = Affected registers are in Unrestricted memory space)
*/
#define FLEXCAN_MCR_SUPV      ((uint32)0x00800000U)
/**
* @brief MCR bit22: Self Wakeup from Doze or Stop modes
*/
#define FLEXCAN_MCR_SLF_WAK   ((uint32)0x00400000U)
/**
* @brief MCR bit21: Warning interrupt enable (TWRNINT and RWRNINT flags generate an iterrupt if set)
*/
#define FLEXCAN_MCR_WRNEN     ((uint32)0x00200000U)
/**
* @brief MCR bit20: Module Disable Acknowledge
*/
#define FLEXCAN_MCR_LPMACK    ((uint32)0x00100000U)
/**
* @brief MCR bit19: Wake Up Source
* @details MCR bit19: Wake Up Source (1 = FlexCAN uses the filtered Rx input to detect recessive to dominant edges on the CAN bus,
*                                     0 = FlexCAN uses the unfiltered Rx input to detect recessive to dominant edges on the CAN bus)
*/
#define FLEXCAN_MCR_WAK_SRC   ((uint32)0x00080000U)
/**
* @brief MCR bit18: Doze Mode Enable
* @details MCR bit18: Doze Mode Enable (1 = FlexCAN is enabled to enter low power mode when Doze
*                                   Mode is requested, 0 = FlexCAN is not enabled to enter low power mode when Doze Mode is requested)
*/
#define FLEXCAN_MCR_DOZE     ((uint32)0x00040000U)
/**
* @brief MCR bit17: Self Rx Disable (module will receive its own Tx messages when cleared)
*/
#define FLEXCAN_MCR_SRXDIS    ((uint32)0x00020000U)
/**
* @brief MCR bit16: Backwards Compatibility Configuration (individual message buffer masks are used when set, global & MB14,MB15 masks are used when cleared)
*/
#define FLEXCAN_MCR_BCC       ((uint32)0x00010000U)
/**
* @brief MCR bit13: Local Priority Enable (the PRIO field in Tx MB ID is used when set)
*/
#define FLEXCAN_MCR_LPRIOEN   ((uint32)0x00002000U)
/**
* @brief MCR bit12: Abort Enable (Tx abort is enabled when set)
*/
#define FLEXCAN_MCR_AEN       ((uint32)0x00001000U)
/**
* @brief MCR bit9-8: ID acceptance mode for the FIFO mode
*/
#define FLEXCAN_MCR_IDAM      ((uint32)0x00000300U)
/**
* @brief             ID acceptance mode: one standard or extended ID
*/
#define FLEXCAN_MCR_IDAM32    ((uint32)0x00000000U)
/**
* @brief             ID acceptance mode: two standard or partial extended IDs
*/
#define FLEXCAN_MCR_IDAM16    ((uint32)0x00000100U)
/**
* @brief             ID acceptance mode: four partial standard or extended IDs
*/
#define FLEXCAN_MCR_IDAM08    ((uint32)0x00000200U)
/**
* @brief MCR bit5-0: Maximum number of MBs in use (field value plus 1)
*/
#define FLEXCAN_MCR_MAXMB     ((uint32)0x0000003FU)


/*==================================================================================================
                BIT MASKS FOR CONTROL REGISTER: CTRL (Base+0x0004)
==================================================================================================*/
/**
* @brief CTRL bit31-24: Clock divider (clock is divided by field value plus 1)
*/
#define FLEXCAN_CTRL_PRESDIV  ((uint32)0xFF000000U)
/**
* @brief CTRL bit23-22: Resynchronization jump width (the width is field value plus 1 time quantum)
*/
#define FLEXCAN_CTRL_RJW      ((uint32)0x00C00000U)
/**
* @brief CTRL bit21-19: Phase segment 1 (length of the segment is field value plus 1 time quantum)
*/
#define FLEXCAN_CTRL_PSEG1    ((uint32)0x00380000U)
/**
* @brief CTRL bit18-16: Phase segment 2 (length of the segment is field value plus 1 time quantum)
*/
#define FLEXCAN_CTRL_PSEG2    ((uint32)0x00070000U)
/**
* @brief CTRL bit15: Bus Off Mask (bus off interrupt enabled when set)
*/
#define FLEXCAN_CTRL_BOFFMSK  ((uint32)0x00008000U)
/**
* @brief CTRL bit14: Error Mask (error interrupt enabled when set)
*/
#define FLEXCAN_CTRL_ERRMSK   ((uint32)0x00004000U)
/**
* @brief CTRL bit13: Clock source selection (0=oscillator clock, 1=system clock)
*/
#define FLEXCAN_CTRL_CLKSRC   ((uint32)0x00002000U)
/**
* @brief CTRL bit12: Loop-Back mode (loop-back mode enabled when set)
*/
#define FLEXCAN_CTRL_LPB      ((uint32)0x00001000U)
/**
* @brief CTRL bit11: Tx Warning interrupt enable (enabled when bit is set)
*/
#define FLEXCAN_CTRL_TWRNMSK  ((uint32)0x00000800U)
/**
* @brief CTRL bit10: Rx Warning interrupt enable (enabled when bit is set)
*/
#define FLEXCAN_CTRL_RWRNMSK  ((uint32)0x00000400U)
/**
* @brief CTRL bit7: Sampling mode (0=1 sample, 1=3 samples)
*/
#define FLEXCAN_CTRL_SMP      ((uint32)0x00000080U)
/**
* @brief CTRL bit6: Bus off recovery mode (0=automatic, 1=manual)
*/
#define FLEXCAN_CTRL_BOFFREC  ((uint32)0x00000040U)
/**
* @brief CTRL bit5: Timer Synchronization (when set the free-running timer is reset each time a message is received into MB0)
*/
#define FLEXCAN_CTRL_TSYN     ((uint32)0x00000020U)
/**
* @brief CTRL bit4: Lowest Buffer First (0=highest priority buffer transmitted first, 1=lowest numbered buffer transmitted first)
*/
#define FLEXCAN_CTRL_LBUF     ((uint32)0x00000010U)
/**
* @brief CTRL bit3: Listen only mode (listen only mode is enabled when bit is set)
*/
#define FLEXCAN_CTRL_LOM      ((uint32)0x00000008U)
/**
* @brief CTRL bit2-0: Propagation Segment (length of the segment is field value plus 1 time quantum)
*/
#define FLEXCAN_CTRL_PROPSEG  ((uint32)0x00000007U)


/*==================================================================================================
                BIT MASKS FOR SHIFTING CONTROL REGISTER VALUES
==================================================================================================*/
/**
* @{
* @brief Offset bits for CTRL register
*/
#define FLEXCAN_CTRL_PRESDIV_SHIFT   ((uint8)24U)
#define FLEXCAN_CTRL_RJW_SHIFT       ((uint8)22U)
#define FLEXCAN_CTRL_PSEG1_SHIFT     ((uint8)19U)
#define FLEXCAN_CTRL_PSEG2_SHIFT     ((uint8)16U)
#define FLEXCAN_CTRL_CLKSRC_SHIFT    ((uint8)13U)
#define FLEXCAN_CTRL_LPB_SHIFT       ((uint8)12U)
#define FLEXCAN_CTRL_SMP_SHIFT       ((uint8)7U)
#define FLEXCAN_CTRL_BOFFREC_SHIFT   ((uint8)6U)
#define FLEXCAN_CTRL_LBUF_SHIFT      ((uint8)4U)
#define FLEXCAN_CTRL_LOM_SHIFT       ((uint8)3U)
/**@}*/

/*==================================================================================================
                BIT MASKS FOR ERROR AND STATUS REGISTER: ESR (Base+0x0020)
==================================================================================================*/
/**
* @brief ESR bit17: Tx error warning interrupt flag (set when TXWRN becomes set while WRNEN is set)
*/
#define FLEXCAN_ESR_TWRNINT   ((uint32)0x00020000U)
/**
* @brief ESR bit16: Rx error warning interrupt flag (set when RXWRN becomes set while WRNEN is set)
*/
#define FLEXCAN_ESR_RWRNINT   ((uint32)0x00010000U)
/**
* @brief ESR bit15: Recessive bit error (when set it indicates that at least one bit wans transmitted as recessive, but received as dominant)
*/
#define FLEXCAN_ESR_BIT1ERR   ((uint32)0x00008000U)
/**
* @brief ESR bit14: Dominant bit error (when set it indicates that at least one bit wans transmitted as dominant, but received as recessive)
*/
#define FLEXCAN_ESR_BIT0ERR   ((uint32)0x00004000U)
/**
* @brief ESR bit13: Acknowledge error (dominant acknowledge has been detected)
*/
#define FLEXCAN_ESR_ACKERR    ((uint32)0x00002000U)
/**
* @brief ESR bit12: CRC error detected
*/
#define FLEXCAN_ESR_CRCERR    ((uint32)0x00001000U)
/**
* @brief ESR bit11: Form error detected
*/
#define FLEXCAN_ESR_FRMERR    ((uint32)0x00000800U)
/**
* @brief ESR bit10: Stuffing error detected
*/
#define FLEXCAN_ESR_STFERR    ((uint32)0x00000400U)
/**
* @brief ESR bit9: Tx error warning flag (set when Tx error counter >=96)
*/
#define FLEXCAN_ESR_TXWRN     ((uint32)0x00000200U)
/**
* @brief ESR bit8: Rx error warning flag (set when Rx error counter >=96)
*/
#define FLEXCAN_ESR_RXWRN     ((uint32)0x00000100U)
/**
* @brief ESR bit7: Can bus IDLE
*/
#define FLEXCAN_ESR_IDLE      ((uint32)0x00000080U)
/**
* @brief ESR bit6: Indicates type of activity when IDLE==0 (0=Rx, 1=Tx)
*/
#define FLEXCAN_ESR_TXRX      ((uint32)0x00000040U)
/**
* @brief ESR bit5-4: Fault state (00=error active, 01=error passive, 1x=bus off)
*/
#define FLEXCAN_ESR_FLTCONF   ((uint32)0x00000030U)
/**
* @brief ESR bit2: Bus off interrupt flag (set after the module enters bus off state)
*/
#define FLEXCAN_ESR_BOFFINT   ((uint32)0x00000004U)
/**
* @brief ESR bit1: Error interrupt flag (set when at least one of the error bits (BIT1ERR..STFERR) is set)
*/
#define FLEXCAN_ESR_ERRINT    ((uint32)0x00000002U)
/**
* @brief ESR bit0: Wake-Up Interrupt (1 = Indicates a recessive to dominant transition received on the CAN bus when the FlexCAN module is in Doze Mode or Stop Mode,
*/
#define FLEXCAN_ESR_WAK_INT   ((uint32)0x00000001U)

/*==================================================================================================
                BIT MASKS FOR CONTROL 2 REGISTER: CTRL2 (Base+0x0034)
==================================================================================================*/
/**
* @brief CTRL2 bit2: Error-correction Configuration Register Write Enable
*/
#define FLEXCAN_CTRL2_ECRWRE   ((uint32)0x20000000U)

/*==================================================================================================
                BIT MASKS FOR MEMORY ERROR CONTROL REGISTER: MECR (Base+0x0AE0)
==================================================================================================*/
/**
* @brief MECR bit0: Error Configuration Register Write Disable
*/
#define FLEXCAN_MECR_ECRWRDIS   ((uint32)0x80000000U)
/**
* @brief MECR bit24: Non-Correctable Errors In FlexCAN Access Put Device In Freeze Mode
*/
#define FLEXCAN_MECR_NCEFAFRZ   ((uint32)0x00000080U)

/*==================================================================================================
                BIT MASKS FOR FIFO INTs
==================================================================================================*/
#if (CAN_RXFIFO_ENABLE == STD_ON)
/**
* @brief Overflow Condition: bit7 of IFRL register
*/
#define FLEXCAN_FIFO_OVERFLOW_INT_MASK   ((uint32)0x00000080U)
/**
* @brief Fifo Warning: bit6 of IFRL register
*/
#define FLEXCAN_FIFO_WARNING_INT_MASK    ((uint32)0x00000040U)
/**
* @brief Fifo Available: bit5 of IFRL register
*/
#define FLEXCAN_FIFO_AVAILABLE_INT_MASK  ((uint32)0x00000020U)

/**
* @brief Buffer MB7 Interrupt or FIFO Overflow
*/
#define FLEXCAN_FIFOOVERFLOW_INT_INDEX   ((uint8)0x7U)
/**
* @brief Buffer MB6 Interrupt or FIFO Warning
*/
#define FLEXCAN_FIFOWARNING_INT_INDEX    ((uint8)0x6U)
/**
* @brief Buffer MB5 Interruptor Frames Available in FIFO
*/
#define FLEXCAN_FIFOFRAME_INT_INDEX      ((uint8)0x5U)

/**
* @brief Message buffers used by FIFO engine
*/
#define FLEXCAN_FIFO_MB_COUNT           ((uint8)0x08U)
/**
* @brief Used to write table ID
*/
#define FLEXCAN_TABLEID_ADDR_OFFSET      ((uint32)0x000000E0U)
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */

/*==================================================================================================
                BIT MASKS FOR DBG1 and DBG2 registers 
==================================================================================================*/
#if defined(ERR_IPV_FLEXCAN_0009)
    #if (ERR_IPV_FLEXCAN_0009== STD_ON)
    
#define FLEXCAN_DBG1_CFSM ((uint32)0x0000003FU)
#define FLEXCAN_DBG2_APP  ((uint32)0x00008000U)

    #else
        #error "The define ERR_IPV_FLEXCAN_0009 must not be STD_OFF"
    #endif /* (ERR_IPV_FLEXCAN_0009== STD_ON)*/
#endif /* (ERR_IPV_FLEXCAN_0009) */

/*==================================================================================================
                              FLEXCAN Register address calculation Macros
==================================================================================================*/

/**
* @brief Macro for Returning Base address of the controller.
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define CAN_GET_BASE_ADDRESS(offset) ( (uint32)( FLEXCAN_BASE_ADDRS[offset] ))


/**
* @brief Macro for Module Configuration (MCR) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MCR(offset)         ( (uint32)( CAN_GET_BASE_ADDRESS(offset) ) )



/**
* @brief Macro for Control Register (CTRL) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_CTRL(offset)        ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x04U ) )



/**
* @brief Macro for Free Running Timer (TIMER) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_TIMER(offset)       ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x08U ) )


/**
* @brief Macro for Rx Global Mask (RXGMASK) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_RXGMASK(offset)     ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x10U ) )



/**
* @brief Macro for Rx Buffer 14 Mask (RX14MASK) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_RX14MASK(offset)    ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x14U ) )



/**
* @brief Macro for Rx Buffer 15 Mask (RX15MASK) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_RX15MASK(offset)    ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x18U ) )



/**
* @brief Macro for Error Counter Register (ECR) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_ECR(offset)         ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x1CU ) )



/**
* @brief Macro for Error and Status Register (ESR) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_ESR(offset)         ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x20U ) )



/**
* @brief Macro for Interrupt Masks 2 (IMASK2) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_IMASK2(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x24U ) )



/**
* @brief Macro for Interrupt Masks 1 (IMASK1) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_IMASK1(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x28U ) )


#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
/**
* @brief Macro for Interrupt Flags 2 (IFLAG2) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_IFLAG2(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x2CU ) )

#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64 ) */

/**
* @brief Macro for Interrupt Flags 1 (IFLAG1) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_IFLAG1(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x30U ) )
/**
* @brief Macro for Control Register 2 (CTRL2) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_CTRL2(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x34U ) )
/**
* @brief Macro for RxFifo structure ID Table 0-7 register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_RXFIFO_ID(offset, id)  ( (uint32)( CAN_GET_BASE_ADDRESS(offset) +  \
                                                   (uint32)FLEXCAN_TABLEID_ADDR_OFFSET + ((uint32)(id) * (uint32)(0x04U)) ))



/**
* @brief Macro for Message Buffers MB0_MB63 register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MB(offset, mb)          ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + \
                                                    ((uint32)(mb) * (uint32)(0x10U)) + (uint32)(FLEXCAN_MB_OFFSET) ))



/**
* @brief Macro for Message Buffers ID of MB0_MB63 register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MB_ID(offset, mb)       ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + \
                                                   (uint32)(FLEXCAN_MB_OFFSET) + \
                                                   (((uint32)(mb) * (uint32)(0x10U)) + (uint32)(0x04U)) ))



/**
* @brief Macro for Message Buffers DATA0 - DATA3 of MB0_MB63 register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MB_DATA_LOW(offset, mb) ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + \
                                                    (uint32)(FLEXCAN_MB_OFFSET) + \
                                                    (((uint32)(mb) * (uint32)(0x10U)) + (uint32)(0x08U)) ))



/**
* @brief Macro for Message Buffers DATA4 - DATA7 of MB0_MB63 register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MB_DATA_HIGH(offset, mb)    ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + \
                                                       (uint32)(FLEXCAN_MB_OFFSET) + \
                                                       (((uint32)(mb) * (uint32)(0x10U)) + (uint32)(0x0CU)) ))



/**
* @brief Macro for Rx Individual Mask Registers RXIMR0_RXIMR63 register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_RXIMR(offset, mb)           ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + \
                                                        (uint32)(FLEXCAN_RXIMR_OFFSET) + \
                                                        ((uint32)(mb) * (uint32)(0x04U)) ))



/**
* @brief Macro for Message Buffers DATA0 - DATA7 of MB0_MB63 register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MB_DATA(offset, mb, databyte)   ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + \
                                                           (uint32)(FLEXCAN_MB_OFFSET) + \
                                                           (((uint32)(mb) * (uint32)(0x10U)) + (uint32)(0x08U) + (uint32)(databyte)) ))


/**
* @brief Macro for Memory Error Control Register (MECR) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MECR(offset)        ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0xAE0U ) )

#if defined(ERR_IPV_FLEXCAN_0009)
    #if (ERR_IPV_FLEXCAN_0009== STD_ON)
/**
* @brief Macro for Debug1 (DBG1) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_DBG1(offset)       ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x58U ) )

/**
* @brief Macro for Debug2 (DBG2) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_DBG2(offset)       ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x5CU ) )

    #else
        #error "The define ERR_IPV_FLEXCAN_0009 must not be STD_OFF"
    #endif /* (ERR_IPV_FLEXCAN_0009== STD_ON)*/
#endif /* (ERR_IPV_FLEXCAN_0009) */
/*==================================================================================================
                            FLEXCAN Register Configuration Macros
==================================================================================================*/
/**
* @brief Macro for MCR Register Configuration
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MCR_CONFIG( offset, value)  (REG_WRITE32( FLEXCAN_MCR(offset), (uint32)(value)))



/**
* @brief Macro for CTRL Register Configuration
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_CTRL_CONFIG( offset, value)  (REG_WRITE32( FLEXCAN_CTRL(offset), (uint32)(value)))



/**
* @brief Macro for ECR Register Configuration
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_ECR_CONFIG( offset, value)  (REG_WRITE32( FLEXCAN_ECR(offset), (uint32)(value)))



/**
* @brief Macro for ESR Register Configuration
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_ESR_CONFIG( offset, value)  (REG_WRITE32( FLEXCAN_ESR(offset), (uint32)(value)))


#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
/**
* @brief Macro for IMASK2 Register Configuration
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_IMASK2_CONFIG( offset, value)  (REG_WRITE32( FLEXCAN_IMASK2(offset), (uint32)(value)))

#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64 ) */


/**
* @brief Macro for IMASK1 Register Configuration
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_IMASK1_CONFIG( offset, value)  (REG_WRITE32( FLEXCAN_IMASK1(offset), (uint32)(value)))


#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
/**
* @brief Macro for IFLAG2 Register Configuration
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_IFLAG2_CONFIG( offset, value)  (REG_WRITE32( FLEXCAN_IFLAG2(offset), (uint32)(value)))

#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64 ) */


/**
* @brief Macro for IFLAG1 Register Configuration
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_IFLAG1_CONFIG( offset, value)  (REG_WRITE32( FLEXCAN_IFLAG1(offset), (uint32)(value)))



/**
* @brief Macro for IFLAG Register Configuration
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_IFLAG_CONFIG( offset, regindex, value)  (((regindex) == 0U) ? (REG_WRITE32( FLEXCAN_IFLAG2(offset), (uint32)(value))) : (REG_WRITE32( FLEXCAN_IFLAG1(offset), (uint32)(value))))

/**
* @brief Macro for RxFifo Configuration
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_RXFIFO_ID_CONFIG( offset, id, value)  (REG_WRITE32( FLEXCAN_RXFIFO_ID(offset, id), (uint32)(value)))



/**
* @brief Macro for MB Control and Status (C/S) Configuration
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MB_CS_CONFIG( offset, mb, value)  (REG_WRITE32( FLEXCAN_MB(offset, mb), (uint32)(value)))



/**
* @brief Macro for MB ID Configuration. Preserve PRIO field if it configured by Can_InitController API.
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MB_ID_CONFIG( offset, mb, value)  (REG_WRITE32( FLEXCAN_MB_ID(offset, mb), (uint32)(value | ((REG_READ32(FLEXCAN_MB_ID(offset, mb))) & 0xE0000000U) )))



/**
* @brief Macro for Data BYTEs ZERO-THREE Configuration
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MB_Data_LOW_CONFIG( offset, mb, value)  (REG_WRITE32( FLEXCAN_MB_DATA_LOW(offset, mb), (uint32)(value)))



/**
* @brief Macro for Data BYTEs FOUR-SEVEN Configuration
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MB_Data_HIGH_CONFIG( offset, mb, value)  (REG_WRITE32( FLEXCAN_MB_DATA_HIGH(offset, mb), (uint32)(value)))



/**
* @brief Macro for RXIMR Register Configuration
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_RXIMR_CONFIG( offset, mb, value)  (REG_WRITE32(FLEXCAN_RXIMR(offset, mb), (uint32)(value)))



/**
* @brief Macro for MB Data Configuration
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MB_DATA_CONFIG( offset, mb, databyte, value)  (REG_WRITE8(FLEXCAN_MB_DATA(offset, mb, databyte), (uint8)(value)))


#if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_RXGMASK_CONFIG(offset,value)                    (  REG_WRITE32(FLEXCAN_RXGMASK(offset), (value)) )

/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_RX14MASK_CONFIG(offset,value)                    (  REG_WRITE32(FLEXCAN_RX14MASK(offset), (value)) )


/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_RX15MASK_CONFIG(offset,value)                    (  REG_WRITE32(FLEXCAN_RX15MASK(offset), (value)) )

#endif

/*==================================================================================================
                            FLEXCAN Register Read Macros
==================================================================================================*/

/**
* @brief Macro for Read Module Configuration (MCR) Register
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MCR_READ(offset)  (REG_READ32( FLEXCAN_MCR(offset)))


/**
* @brief Macro for Read Control (CTRL) Register
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_CTRL_READ(offset)  (REG_READ32( FLEXCAN_CTRL(offset)))

#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
/**
* @brief Macro for Read IMASK2 Register
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_IMASK2_READ(offset)  (REG_READ32( FLEXCAN_IMASK2(offset)))

#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64 ) */

/**
* @brief Macro for Read IMASK1 Register
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_IMASK1_READ(offset)  (REG_READ32( FLEXCAN_IMASK1(offset)))



#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
/**
* @brief Macro for Read IFLAG2 Register
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_IFLAG2_READ(offset)  (REG_READ32( FLEXCAN_IFLAG2(offset)))

#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64 ) */

/**
* @brief Macro for Read IFLAG1 Register
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_IFLAG1_READ(offset)  (REG_READ32( FLEXCAN_IFLAG1(offset)))



/**
* @brief Macro for Read Error Control (ECR) Register
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_ECR_READ(offset)  (REG_READ32( FLEXCAN_ECR(offset)))



/**
* @brief Macro for Read Error and Status Register (ESR) Register
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_ESR_READ(offset)  (REG_READ32( FLEXCAN_ESR(offset)))



/**
* @brief Macro for Read  MB configuration register
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MB_READ(offset,mb)  (REG_READ32( FLEXCAN_MB(offset, mb)))


/**
* @brief Macro for Read Message Buffers MB0_MB63 Register
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MB_READ_CS( offset, mb)  (REG_READ32( FLEXCAN_MB(offset, mb)) & (uint32)(FLEXCAN_MBCS_CODE))


/**
* @brief Macro for Read EXTENDED ID Register
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MB_READ_ID_EXTENDED( offset, mb)  (REG_READ32( FLEXCAN_MB_ID(offset, mb)) & (uint32)(FLEXCAN_MBID_ID_EXTENDED))


/**
* @brief Macro for Read STANDARD ID Register
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MB_READ_ID_STANDARD( offset, mb)  ((REG_READ32( FLEXCAN_MB_ID(offset, mb)) & (uint32)(FLEXCAN_MBID_ID_STANDARD)) >> (uint32)(18U))



/**
* @brief Macro for Read DATA BYTEs ZERO-THREE
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MB_READ_DATA_LOW( offset, mb)  (REG_READ32( FLEXCAN_MB_DATA_LOW(offset, mb)))



/**
* @brief Macro for Read DATA BYTEs FOUR-SEVEN
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MB_READ_DATA_HIGH( offset, mb)  (REG_READ32( FLEXCAN_MB_DATA_HIGH(offset, mb)))



/**
* @brief Macro for Read DATA BYTEs 0 - 7
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_MB_READ_DATA_BYTE( offset, mb, byte)  (REG_READ8(FLEXCAN_MB_DATA(offset, mb, byte)))



/**
* @brief Macro for Read Rx Individual Mask Registers RXIMR0-RXIMR15 Register
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_RXIMR_READ(offset)  (REG_READ32( FLEXCAN_RXIMR(offset, mb)))



/**
* @brief Macro for Read Free Running Timer (TIMER) Register
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_TIMER_READ(offset)  (REG_READ32( FLEXCAN_TIMER(offset)))

#if defined(ERR_IPV_FLEXCAN_0009)
    #if (ERR_IPV_FLEXCAN_0009== STD_ON)
/**
* @brief Macro for Read Debug1 (DBG1) Register
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_DBG1_READ(offset)  (REG_READ32( FLEXCAN_DBG1(offset)))

/**
* @brief Macro for Read Debug2 (DBG2) Register
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_DBG2_READ(offset)  (REG_READ32( FLEXCAN_DBG2(offset)))

    #else
        #error "The define ERR_IPV_FLEXCAN_0009 must not be STD_OFF"
    #endif /* (ERR_IPV_FLEXCAN_0009== STD_ON)*/
#endif /* (ERR_IPV_FLEXCAN_0009) */
/*==================================================================================================
                              FLEXCAN Register Bit Configuration Macros
==================================================================================================*/
/**
* @{
* @brief MCR Register: BASE + 0x0000 bits set
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_SET_MCR_MDIS(offset)           ( REG_BIT_SET32( FLEXCAN_MCR(offset), FLEXCAN_MCR_MDIS) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_MCR_FRZ(offset)            ( REG_BIT_SET32( FLEXCAN_MCR(offset), FLEXCAN_MCR_FRZ) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_MCR_FEN(offset)            ( REG_BIT_SET32( FLEXCAN_MCR(offset), FLEXCAN_MCR_FEN) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_MCR_HALT(offset)           ( REG_BIT_SET32( FLEXCAN_MCR(offset), FLEXCAN_MCR_HALT) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_MCR_WAK_MSK(offset)        ( REG_BIT_SET32( FLEXCAN_MCR(offset), FLEXCAN_MCR_WAK_MSK) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_MCR_SOFT_RST(offset)       ( REG_BIT_SET32( FLEXCAN_MCR(offset), FLEXCAN_MCR_SOFTRST) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_MCR_SUPV(offset)           ( REG_BIT_SET32( FLEXCAN_MCR(offset), FLEXCAN_MCR_SUPV) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_MCR_SLF_WAK(offset)        ( REG_BIT_SET32( FLEXCAN_MCR(offset), FLEXCAN_MCR_SLF_WAK) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_MCR_WRNEN(offset)          ( REG_BIT_SET32( FLEXCAN_MCR(offset), FLEXCAN_MCR_WRNEN) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_MCR_WAK_SRC(offset)        ( REG_BIT_SET32( FLEXCAN_MCR(offset), FLEXCAN_MCR_WAK_SRC) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_MCR_DOZE(offset)           ( REG_BIT_SET32( FLEXCAN_MCR(offset), FLEXCAN_MCR_DOZE) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_MCR_SRXDIS(offset)         ( REG_BIT_SET32( FLEXCAN_MCR(offset), FLEXCAN_MCR_SRXDIS) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_MCR_BCC(offset)            ( REG_BIT_SET32( FLEXCAN_MCR(offset), FLEXCAN_MCR_BCC) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_MCR_LPRIOEN(offset)        ( REG_BIT_SET32( FLEXCAN_MCR(offset), FLEXCAN_MCR_LPRIOEN) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_MCR_AEN(offset)            ( REG_BIT_SET32( FLEXCAN_MCR(offset), FLEXCAN_MCR_AEN) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_SET_MCR_IDAM(offset, value)    ( REG_RMW32( FLEXCAN_MCR(offset), FLEXCAN_MCR_IDAM, (uint32)value) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_5 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
#define FLEXCAN_SET_MCR_MAXMB(offset, value)   ( REG_RMW32( FLEXCAN_MCR(offset), FLEXCAN_MCR_MAXMB, (uint32)value) )

/**@}*/

/**
* @{
* @brief MCR Register: BASE + 0x0000 bits clear
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_CLEAR_MCR_MDIS(offset)         ( REG_BIT_CLEAR32( FLEXCAN_MCR(offset), FLEXCAN_MCR_MDIS) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_MCR_FRZ(offset)          ( REG_BIT_CLEAR32( FLEXCAN_MCR(offset), FLEXCAN_MCR_FRZ) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_MCR_FEN(offset)          ( REG_BIT_CLEAR32( FLEXCAN_MCR(offset), FLEXCAN_MCR_FEN) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_MCR_HALT(offset)         ( REG_BIT_CLEAR32( FLEXCAN_MCR(offset), FLEXCAN_MCR_HALT) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_MCR_WAK_MSK(offset)      ( REG_BIT_CLEAR32( FLEXCAN_MCR(offset), FLEXCAN_MCR_WAK_MSK) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_MCR_SUPV(offset)         ( REG_BIT_CLEAR32( FLEXCAN_MCR(offset), FLEXCAN_MCR_SUPV) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_MCR_SLF_WAK(offset)      ( REG_BIT_CLEAR32( FLEXCAN_MCR(offset), FLEXCAN_MCR_SLF_WAK) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_MCR_WRNEN(offset)        ( REG_BIT_CLEAR32( FLEXCAN_MCR(offset), FLEXCAN_MCR_WRNEN) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_MCR_WAK_SRC(offset)      ( REG_BIT_CLEAR32( FLEXCAN_MCR(offset), FLEXCAN_MCR_WAK_SRC) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_MCR_DOZE(offset)         ( REG_BIT_CLEAR32( FLEXCAN_MCR(offset), FLEXCAN_MCR_DOZE) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_MCR_SRXDIS(offset)       ( REG_BIT_CLEAR32( FLEXCAN_MCR(offset), FLEXCAN_MCR_SRXDIS) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_MCR_BCC(offset)          ( REG_BIT_CLEAR32( FLEXCAN_MCR(offset), FLEXCAN_MCR_BCC) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_MCR_LPRIOEN(offset)      ( REG_BIT_CLEAR32( FLEXCAN_MCR(offset), FLEXCAN_MCR_LPRIOEN) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_MCR_AEN(offset)          ( REG_BIT_CLEAR32( FLEXCAN_MCR(offset), FLEXCAN_MCR_AEN) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_MCR_IDAM(offset)         ( REG_BIT_CLEAR32( FLEXCAN_MCR(offset), FLEXCAN_MCR_IDAM) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_MCR_MAXMB(offset)        ( REG_BIT_CLEAR32( FLEXCAN_MCR(offset), FLEXCAN_MCR_MAXMB) )

/**@}*/

/**
* @{
* @brief CTRL Register: BASE + 0x0004 bits set
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_SET_CTRL_BOFFMSK(offset)       ( REG_BIT_SET32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_BOFFMSK) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_CTRL_ERRMSK(offset)        ( REG_BIT_SET32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_ERRMSK) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_CTRL_CLKSRC(offset)        ( REG_BIT_SET32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_CLKSRC) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_CTRL_LPB(offset)           ( REG_BIT_SET32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_LPB) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_CTRL_TWRNMSK(offset)       ( REG_BIT_SET32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_TWRNMSK) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_CTRL_RWRNMSK(offset)       ( REG_BIT_SET32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_RWRNMSK) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_CTRL_SMP(offset)           ( REG_BIT_SET32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_SMP) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_CTRL_BOFFREC(offset)       ( REG_BIT_SET32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_BOFFREC) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_CTRL_TSYN(offset)          ( REG_BIT_SET32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_TSYN) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_CTRL_LBUF(offset)          ( REG_BIT_SET32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_LBUF) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_CTRL_LOM(offset)           ( REG_BIT_SET32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_LOM) )

/**@}*/

/**
* @{
* @brief CTRL Register: BASE + 0x0004 bits clear
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_CLEAR_CTRL_BOFFMSK(offset)      ( REG_BIT_CLEAR32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_BOFFMSK) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_CTRL_ERRMSK(offset)       ( REG_BIT_CLEAR32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_ERRMSK) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_CTRL_CLKSRC(offset)       ( REG_BIT_CLEAR32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_CLKSRC) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_CTRL_LPB(offset)          ( REG_BIT_CLEAR32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_LPB) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_CTRL_TWRNMSK(offset)      ( REG_BIT_CLEAR32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_TWRNMSK) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_CTRL_RWRNMSK(offset)      ( REG_BIT_CLEAR32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_RWRNMSK) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_CTRL_SMP(offset)          ( REG_BIT_CLEAR32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_SMP) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_CTRL_BOFFREC(offset)      ( REG_BIT_CLEAR32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_BOFFREC) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_CTRL_TSYN(offset)         ( REG_BIT_CLEAR32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_TSYN) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_CTRL_LBUF(offset)         ( REG_BIT_CLEAR32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_LBUF) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_CTRL_LOM(offset)          ( REG_BIT_CLEAR32( FLEXCAN_CTRL(offset), FLEXCAN_CTRL_LOM) )

/**@}*/

/**
* @{
* @brief ESR Register: BASE + 0x0020 bits set
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_SET_ESR_BOFFINT(offset)         ( REG_WRITE32( FLEXCAN_ESR(offset), FLEXCAN_ESR_BOFFINT) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_ESR_ERRINT(offset)          ( REG_WRITE32( FLEXCAN_ESR(offset), FLEXCAN_ESR_ERRINT) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_ESR_WAK_INT(offset)         ( REG_WRITE32( FLEXCAN_ESR(offset), FLEXCAN_ESR_WAK_INT) )

/**@}*/


/**
* @{
* @brief CTRL2 Register: BASE + 0x0034 bits set
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_CTRL2_ECRWRE(offset)           ( REG_BIT_SET32( FLEXCAN_CTRL2(offset), FLEXCAN_CTRL2_ECRWRE) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_CTRL2_ECRWRE(offset)         ( REG_BIT_CLEAR32( FLEXCAN_CTRL2(offset), FLEXCAN_CTRL2_ECRWRE) )

/**@}*/

/**
* @{
* @brief MECR Register: BASE + 0x0AE0 bits set
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_MECR_ECRWRDIS(offset)         ( REG_BIT_CLEAR32( FLEXCAN_MECR(offset), FLEXCAN_MECR_ECRWRDIS) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_MECR_ECRWRDIS(offset)            ( REG_BIT_SET32( FLEXCAN_MECR(offset), FLEXCAN_MECR_ECRWRDIS) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CLEAR_MECR_NCEFAFRZ(offset)         ( REG_BIT_CLEAR32( FLEXCAN_MECR(offset), FLEXCAN_MECR_NCEFAFRZ) )
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_SET_MECR_NCEFAFRZ(offset)            ( REG_BIT_SET32( FLEXCAN_MECR(offset), FLEXCAN_MECR_NCEFAFRZ) )
/**@}*/
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#define CAN_START_SEC_CONST_UNSPECIFIED
/* @violates @ref Reg_eSys_FlexCan_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */

#include "MemMap.h"
/* @violates @ref Reg_eSys_FlexCan_h_REF_7 Violates MISRA 2004 Required Rule 8.8, Array declared with unknown size.*/
extern CONST(uint32, CAN_CONST) FLEXCAN_BASE_ADDRS[];

#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/

#include "MemMap.h"

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#if (CAN_PRECOMPILE_SUPPORT == STD_OFF)
/* @violates @ref Reg_eSys_FlexCan_h_REF_6 This is required as per autosar Requirement. */
#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"

/* @violates @ref Reg_eSys_FlexCan_h_REF_6 This is required as per autosar Requirement. */
#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"
#endif

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_START_SEC_CODE
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"

#define CAN_STOP_SEC_CODE
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*TEMPLATE_H*/

/** @} */
