/**
*   @file Reg_eSys_SIUL.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Icu - SIUL low level driver register defines.
*   @details The description of the registers of the SIUL module.
*
*   @addtogroup Siul
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS
*   Dependencies         : none
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


#ifndef REG_ESYS_SIUL_H
#define REG_ESYS_SIUL_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_SIUL_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Reg_eSys_SIUL_H_REF_3
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
*@section Reg_eSys_SIUL_H_REF_4
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*
* @file  Reg_eSys_SIUL.h
*/
/*   @implements     DICU04700 */
#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @implements     DICU04201, DICU04202, DICU04203, DICU04204, DICU04205, DICU04206, DICU04207
*/
#define SIUL_VENDOR_ID_REG                    43
/*
* @violates @ref Reg_eSys_SIUL_H_REF_4 This is required as per autosar Requirement, 
*/
#define SIUL_AR_RELEASE_MAJOR_VERSION_REG     4
/*
* @violates @ref Reg_eSys_SIUL_H_REF_4 This is required as per autosar Requirement, 
*/
#define SIUL_AR_RELEASE_MINOR_VERSION_REG     0
/* @violates @ref Reg_eSys_SIUL_H_REF_3 Violates MISRA 2004 Required Rule 1.4 */
/*
* @violates @ref Reg_eSys_SIUL_H_REF_4 This is required as per autosar Requirement, 
*/
#define SIUL_AR_RELEASE_REVISION_VERSION_REG  3
#define SIUL_SW_MAJOR_VERSION_REG             1
#define SIUL_SW_MINOR_VERSION_REG             0
#define SIUL_SW_PATCH_VERSION_REG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*lint -save -e961*/
/*==================================================================================================
*                               DEFINES AND MACROS
==================================================================================================*/

/* @brief IP version siul.01.00.02.04 */
#define IPV_SIUL_01_00_02_04    (0x01000204UL)

/* @brief IP version siul.01.00.01.15 */
#define IPV_SIUL_01_00_01_15    (0x01000115UL)

/* @brief IP version siul.01.00.01.17 */
#define IPV_SIUL_01_00_01_17    (0x01000117UL)

/* @brief IP version siul.01.00.02.02 */
#define IPV_SIUL_01_00_02_02    (0x01000202UL)
/* Registers definition */

/* @brief MCU ID Register #1 address, bits and masks */
#define SIUL_MIDR1                (SIUL_BASEADDR + 0x04UL)
#define SIUL_MIDR1_PARTNUM        (0xFFFF0000UL)
#define SIUL_MIDR1_CSP            (0x00008000UL)
#define SIUL_MIDR1_PKG            (0x00007C00UL)
#define SIUL_MIDR1_MAJOR_MASK     (0x000000F0UL)
#define SIUL_MIDR1_MINOR_MASK     (0x0000000FUL)

/* @brief MCU ID Register #2 address, bits and masks */
#define SIUL_MIDR2                (SIUL_BASEADDR + 0x08UL)
#define SIUL_MIDR2_SF             (0x80000000UL)
#define SIUL_MIDR2_FLASH_SIZE_1   (0x78000000UL)
#define SIUL_MIDR2_FLASH_SIZE_2   (0x07800000UL)
#define SIUL_MIDR2_PARTNUM        (0x0000FF00UL)
#define SIUL_MIDR2_EE             (0x00000010UL)
#define SIUL_MIDR2_FR             (0x00000001UL)

/* @brief Interrupt Status Flag Register address, bits and masks */
#define SIUL_ISR                  (SIUL_BASEADDR + 0x14UL)
#define SIUL_ISR_EIF              (0x0000FFFFUL)

/* @brief Interrupt Request Flag Register address, bits and masks */
#define SIUL_IRER                 (SIUL_BASEADDR + 0x18UL)
#define SIUL_IRER_IRE             (0x0000FFFFUL)

/* @brief Interrupt Rising Edge Event Register address, bits and masks */
#define SIUL_IREER                (SIUL_BASEADDR + 0x28UL)
#define SIUL_IREER_IREE           (0x0000FFFFUL)

/* @brief Interrupt Falling Edge Event Register address, bits and masks */
#define SIUL_IFEER                (SIUL_BASEADDR + 0x2CUL)
#define SIUL_IFEER_IFEE           (0x0000FFFFUL)

/* @brief Interrupt Filter Enable Register address, bits and masks */
#define SIUL_IFER                 (SIUL_BASEADDR + 0x30UL)
#define SIUL_IFER_IFE             (0x0000FFFFUL)

/*
* @brief Pad Configuration Register address for a specific pin.
*/
/*
* @violates @ref Reg_eSys_SIUL_H_REF_1 Function-like macro
* defined.
*/
#define SIUL_PCR(PIN)             ((uint32)(SIUL_BASEADDR) + (uint32)0x40UL + (((uint32)(PIN))<<(1)))

/* @brief Pad Configuration Register bits and masks */
#define SIUL_PCR_SMC              ((uint16)0x4000U)
#define SIUL_PCR_APC              ((uint16)0x2000U)
#define SIUL_PCR_PA               ((uint16)0x0C00U)
#define SIUL_PCR_OBE              ((uint16)0x0200U)
#define SIUL_PCR_IBE              ((uint16)0x0100U)
#define SIUL_PCR_ODE              ((uint16)0x0020U)
#define SIUL_PCR_SRC              ((uint16)0x00C0U)
#define SIUL_PCR_WPE              ((uint16)0x0002U)
#define SIUL_PCR_WPS              ((uint16)0x0001U)

/*
* @brief Pad Selection for Multiplexed Inputs address for as specific offset
*/
/*
* @violates @ref Reg_eSys_SIUL_H_REF_1 Function-like macro
* defined.
*/
#define SIUL_PSMI(PSMI_OFFSET)    (SIUL_BASEADDR + (uint32)(PSMI_OFFSET) + (uint32)0x500UL)

/* @brief Pad Selection for Multiplexed Inputs bits and masks */
#define SIUL_PSMI_PADSEL0         (0x0F000000UL)
#define SIUL_PSMI_PADSEL1         (0x000F0000UL)
#define SIUL_PSMI_PADSEL2         (0x00000F00UL)
#define SIUL_PSMI_PADSEL3         (0x0000000FUL)

/* @brief Max PSMI register index for siul.01.00.02.04 */
#define SIUL_PSMI_MAX_SIUL_01_00_02_04     ((uint8)0x43)

/* @brief Max PSMI register index for siul.01.00.01.15 */
#define SIUL_PSMI_MAX_SIUL_01_00_01_15     ((uint8)0x23)

/* @brief Max PSMI register index for siul.01.00.01.17 */
#define SIUL_PSMI_MAX_SIUL_01_00_01_17     ((uint8)0x3f)

/* @brief PSMI bit values */
#define SIUL_PSMI_RESET          ((uint32)0x00000000U)

/*
* @brief GPIO Pad Data Output Register address
*/
/*
* @violates @ref Reg_eSys_SIUL_H_REF_1 Function-like macro
* defined.
*/
#define SIUL_GPDO(PIN)            (SIUL_BASEADDR + (uint32)0x600UL + (uint32)(PIN))

/* @brief GPIO Pad Data Output Register 0 */
#define SIUL_GPDO_PDO_0           (0x01000000UL)

/* @brief GPIO Pad Data Output Register 1 */
#define SIUL_GPDO_PDO_1           (0x00010000UL)

/* @brief GPIO Pad Data Output Register 2 */
#define SIUL_GPDO_PDO_2           (0x00000100UL)

/* @brief GPIO Pad Data Output Register 3 */
#define SIUL_GPDO_PDO_3           (0x00000001UL)

/*
* @brief GPIO Pad Data Input Register address
*/
/*
* @violates @ref Reg_eSys_SIUL_H_REF_1 Function-like macro
* defined
*/
#define SIUL_GPDI(PIN)            (SIUL_BASEADDR + (uint32)0x800UL + (uint32)(PIN))

/* @brief GPIO Pad Data Input Register 0 */
#define SIUL_GPDI_PDI_0           (0x01000000UL)

/* @brief GPIO Pad Data Input Register 1 */
#define SIUL_GPDI_PDI_1           (0x00010000UL)

/* @brief GPIO Pad Data Input Register 2 */
#define SIUL_GPDI_PDI_2           (0x00000100UL)

/* @brief GPIO Pad Data Input Register 3 */
#define SIUL_GPDI_PDI_3           (0x00000001UL)

/*
* @brief Parallel GPIO Pad Data Output Register address
*/
/*
* @violates @ref Reg_eSys_SIUL_H_REF_1 Function-like macro
* defined
*/
#define SIUL_PGPDO(PGPDO_OFFSET)  (SIUL_BASEADDR + (uint32)0xC00UL + (PGPDO_OFFSET))

/*
* @brief Parallel GPIO Pad Data Input Register address
*/
/*
* @violates @ref Reg_eSys_SIUL_H_REF_1 Function-like macro
* defined
*/
#define SIUL_PGPDI(PGPDI_OFFSET)  (SIUL_BASEADDR + (uint32)0xC40UL + (PGPDI_OFFSET))

/*
* @brief  Masked Parallel GPIO Pad Data Output Register address
*/
/*
* @violates @ref Reg_eSys_SIUL_H_REF_1 Function-like macro
* defined
*/
#define SIUL_MPGPDO(MPGPDO_OFFSET)(SIUL_BASEADDR + (uint32)0xC80UL + (MPGPDO_OFFSET))

/* @brief  Masked Parallel GPIO Pad Data Output Register(Mask Field) */
#define SIUL_MPGPDO_MASK          (0xFFFF0000UL)

/* @brief  Masked Parallel Pad Data Out */
#define SIUL_MPGPDO_MPPDO         (0x0000FFFFUL)

/*
* @brief Interrupt Filter Maximum Counter Register address
*/
/*
* @violates @ref Reg_eSys_SIUL_H_REF_1 Function-like macro
* defined
*/
#define SIUL_IFMC(IFMC_OFFSET)      (SIUL_BASEADDR + (IFMC_OFFSET) + (uint32)0x1000UL)

/* @brief Interrupt Filter Maximum Counter mask */
#define SIUL_IFMC_MAXCNT          (0x0000000FUL)

/*
* @brief Interrupt Filter Clock Prescaler Register
*/
#define SIUL_IFCPR                  (SIUL_BASEADDR + 0x1080UL)

/* @brief Interrupt Filter Clock Prescaler Register masks and shift counts */
#define SIUL_IFCPR_IFCP           (0x0000000FUL)
#define SIUL_IFCPR_SHIFT            0U

/* @brief PCR bit masks and bit values */
#define SIUL_PCR_SMC_ON           ((uint16)0x4000U)
#define SIUL_PCR_SMC_OFF          ((uint16)0x0000U)
#define SIUL_PCR_APC_ON           ((uint16)0x2000U)
#define SIUL_PCR_APC_OFF          ((uint16)0x0000U)
#define SIUL_PCR_PA_GPIO          ((uint16)0x0000U)
#define SIUL_PCR_PA_ALT1          ((uint16)0x0400U)
#define SIUL_PCR_PA_ALT2          ((uint16)0x0800U)
#define SIUL_PCR_PA_ALT3          ((uint16)0x0C00U)
#define SIUL_PCR_PA_ALT4          ((uint16)0x1000U)
#define SIUL_PCR_OBE_ON           ((uint16)0x0200U)
#define SIUL_PCR_OBE_OFF          ((uint16)0x0000U)
#define SIUL_PCR_IBE_ON           ((uint16)0x0100U)
#define SIUL_PCR_IBE_OFF          ((uint16)0x0000U)
#define SIUL_PCR_ODE_ON           ((uint16)0x0020U)
#define SIUL_PCR_ODE_OFF          ((uint16)0x0000U)
#define SIUL_PCR_SRC_ON           ((uint16)0x0004U)
#define SIUL_PCR_SRC_OFF          ((uint16)0x0000U)
#define SIUL_PCR_WPE_ON           ((uint16)0x0002U)
#define SIUL_PCR_WPE_OFF          ((uint16)0x0000U)
#define SIUL_PCR_WPS_ON           ((uint16)0x0001U)
#define SIUL_PCR_WPS_OFF          ((uint16)0x0000U)

/* @brief PCR PA offset */
#define SIUL_PCR_PA_OFFSET          ((uint8)10)

/* @brief Mode bit offset mask */
#define SIUL_MODE_BIT_OFFSET_MASK   ((uint8)0x0F)

/*lint -restore*/

#ifdef __cplusplus
}
#endif
/* REG_ESYS_SIUL_H */
#endif
/** @} */
