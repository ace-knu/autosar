/**
*   @file    Reg_eSys_Swt.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Wdg - Software Watchdog Timer (SWT) Registers
*   @details Contains information about the SWT's registers
*
*   @addtogroup  Wdg
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : Swt
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF12_ASR_REL_4_0_REV_0003_20161209
*
*   (c) Copyright 2006-2016 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef REG_ESYS_SWT_H
#define REG_ESYS_SWT_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_Swt_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precaution shall be taken in order to prevent the
* contents of a header file being included twice.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Reg_eSys_Swt_h_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
* @section Reg_eSys_Swt_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* MemMap.h included after each section define in order to set the current memory section.
* This mechanism is used to properly place code and variables into their sections.*
*
* @section Reg_eSys_Swt_h_REF_4
* Violates MISRA 2004 Required Rule 8.12, When an array is declared with external linkage, its size
* shall be stated explicitly or defined implicitly by initialisation.
*
* @section Reg_eSys_Swt_h_REF_5
* Violates MISRA 2004 Advisory Rule 19.7, A function should be used in preference to a function-like
* macro.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys.h"

#include "Reg_Macros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief  Parameters that shall be published within the driver header file and also in the 
* module's description file
*/
#define REG_ESYS_SWT_VENDOR_ID                      43
/* @violates @ref Reg_eSys_Swt_h_REF_2 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define REG_ESYS_SWT_AR_RELEASE_MAJOR_VERSION       4
/* @violates @ref Reg_eSys_Swt_h_REF_2 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define REG_ESYS_SWT_AR_RELEASE_MINOR_VERSION       0
/* @violates @ref Reg_eSys_Swt_h_REF_2 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define REG_ESYS_SWT_AR_RELEASE_REVISION_VERSION    3
#define REG_ESYS_SWT_SW_MAJOR_VERSION               1
#define REG_ESYS_SWT_SW_MINOR_VERSION               0
#define REG_ESYS_SWT_SW_PATCH_VERSION               1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define WDG_START_SEC_CONST_32
/* @violates @ref Reg_eSys_Swt_h_REF_1 Precaution shall be taken in order to prevent the contents of a header file being included twice.*/
/* @violates @ref Reg_eSys_Swt_h_REF_3 Only preprocessor statements and comments before 'include' */
#include "MemMap.h"

extern CONST(uint32, WDG_CONST) SWT_BASE_ADDRS[WDG_NO_OF_INSTANCES];

#define WDG_STOP_SEC_CONST_32
/* @violates @ref Reg_eSys_Swt_h_REF_1 Precaution shall be taken in order to prevent the contents of a header file being included twice.*/
/* @violates @ref Reg_eSys_Swt_h_REF_3 Only preprocessor statements and comments before 'include' */
#include "MemMap.h"
/**
* @brief This constant specifies the SWT Control Register
*/
/* @violates @ref Reg_eSys_Swt_h_REF_5 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define SWT_CR(u8ModuleIdx)                 ((uint32)(SWT_BASE_ADDRS[(u8ModuleIdx)] + (uint32)0x00UL))

/**
* @brief This constant specifies the SWT Interrupt Register
*/
/* @violates @ref Reg_eSys_Swt_h_REF_5 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define SWT_IR(u8ModuleIdx)                 ((uint32)(SWT_BASE_ADDRS[(u8ModuleIdx)] + (uint32)0x04UL))

/**
* @brief This constant specifies the SWT Time-out Register
*/
/* @violates @ref Reg_eSys_Swt_h_REF_5 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define SWT_TO(u8ModuleIdx)                 ((uint32)(SWT_BASE_ADDRS[(u8ModuleIdx)] + (uint32)0x08UL))

/**
* @brief This constant specifies the SWT Window Register
*/
/* @violates @ref Reg_eSys_Swt_h_REF_5 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define SWT_WN(u8ModuleIdx)                 ((uint32)(SWT_BASE_ADDRS[(u8ModuleIdx)] + (uint32)0x0CUL))

/**
* @brief This constant specifies the SWT Service Register
*/
/* @violates @ref Reg_eSys_Swt_h_REF_5 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define SWT_SR(u8ModuleIdx)                 ((uint32)(SWT_BASE_ADDRS[(u8ModuleIdx)] + (uint32)0x10UL))

/**
* @brief This constant specifies the SWT Output Register
*/
/* @violates @ref Reg_eSys_Swt_h_REF_5 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define SWT_CO(u8ModuleIdx)                 ((uint32)(SWT_BASE_ADDRS[(u8ModuleIdx)] + (uint32)0x14UL))

/**
* @brief This constant specifies the SWT Service Key Register
*/
/* @violates @ref Reg_eSys_Swt_h_REF_5 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define SWT_SK(u8ModuleIdx)                 ((uint32)(SWT_BASE_ADDRS[(u8ModuleIdx)] + (uint32)0x18UL))

/**
* @brief This constant specifies the value of the CR's Wdg enable bit if enabled
*/
/** @violates @ref Reg_eSys_Swt_h_REF_3 MISRA 2004 Required Rule 19.4, Disallowed definition for macro */
#define SWT_WDG_ENABLED                     (0x00000001UL)

/**
* @brief This constant specifies the value of the CR's Wdg enable bit if disabled
*/
/** @violates @ref Reg_eSys_Swt_h_REF_3 MISRA 2004 Required Rule 19.4, Disallowed definition for macro */
#define SWT_WDG_DISABLED                    (0x00000000UL)

/**
* @brief This constant specifies the value of the CR's debug mode control bit if enabled
*/
#define SWT_WDG_STOP_IN_DEBUG               (0x00000002UL)

/**
* @brief This constant specifies the value of the CR's debug mode control bit if disabled
*/
#define SWT_WDG_RUN_IN_DEBUG                (0x00000000UL)

/**
* @brief This constant specifies the value of the CR's stop mode control bit if enabled
*/
#define SWT_WDG_STOP_IN_HALT                (0x00000004UL)

/**
* @brief This constant specifies the value of the CR's stop mode control bit if disabled
*/
#define SWT_WDG_RUN_IN_HALT                 (0x00000000UL)

/**
* @brief This constant specifies the value of the CR's clock selection bit if enabled
*/
#define SWT_WDG_OSCILLATOR                  (0x00000008UL)

/**
* @brief This constant specifies the value of the CR's clock selection bit if disabled
*/
#define SWT_WDG_SYSTEM_CLOCK                (0x00000000UL)

/**
* @brief This constant specifies the value of the CR's soft lock bit if enabled
*/
#define SWT_WDG_SOFT_LOCK                   (0x00000010UL)

/**
* @brief This constant specifies the value of the CR's soft lock bit if disabled
*/
#define SWT_WDG_NO_SOFT_LOCK                (0x00000000UL)

/**
* @brief This constant specifies the value of the CR's hard lock bit if enabled
*/
#define SWT_WDG_HARD_LOCK                   (0x00000020UL)

/**
* @brief This constant specifies the value of the CR's hard lock bit if disabled
*/
#define SWT_WDG_NO_HARD_LOCK                (0x00000000UL)

/**
* @brief This constant specifies the value of the CR's interrupt then reset bit if disabled
*        Generate an interrupt on an initial time-out, reset on a second consecutive time-out
*/
#define SWT_INTERRUPT_TOGGLE                (0x00000040UL)

/**
* @brief This constant specifies the value of the CR's interrupt then reset bit if enabled
*        Generate Reset on a time-out
*/
#define SWT_RESET_ON_TIMEOUT                (0x00000000UL)

/**
* @brief This constant specifies the value of the CR's window mode bit if enabled
*        Windowed mode, the service sequence is only valid when the down counter
*        is less then value in the SWT_WN register
*/
#define SWT_TRIGGER_MODE_WINDOW             (0x00000080UL)

/**
* @brief This constant specifies the value of the CR's window mode bit if disabled
*        Regular mode, service sequence can be done at any time
*/
#define SWT_TRIGGER_MODE_REGULAR            (0x00000000UL)

/**
* @brief This constant specifies the value of the CR's reset on invalid access bit if enabled
*        Invalid access to the SWT causes a system reset if WEN = 1
*/
/* @violates @ref Reg_eSys_Swt_h_REF_2 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define SWT_INVALID_ACCESS_GEN_SYSTEM_RESET (0x00000100UL)

/**
* @brief This constant specifies the value of the CR's reset on invalid access bit if disabled
*        Invalid access to the SWT generates a bus error+
*/
/* @violates @ref Reg_eSys_Swt_h_REF_2 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define SWT_INVALID_ACCESS_GEN_BUS_ERROR    (0x00000000UL)

/**
* @brief This constant specifies the value of the CR's master access protection
*        Master acces protection enabled
*/
#define SWT_MAP_ENABLE_4BITS                 (0xF0000000UL)

/**
* @brief This constant specifies the value of the CR's master access protection
* Master acces protection enabled
*/
#define SWT_MAP_ENABLE_8BITS                (0xFF000000UL)
#define SWT_MAP7_ENABLE                     (0x01000000UL)
#define SWT_MAP6_ENABLE                     (0x02000000UL)
#define SWT_MAP5_ENABLE                     (0x04000000UL)
#define SWT_MAP4_ENABLE                     (0x08000000UL)
#define SWT_MAP3_ENABLE                     (0x10000000UL)
#define SWT_MAP2_ENABLE                     (0x20000000UL)
#define SWT_MAP1_ENABLE                     (0x40000000UL)
#define SWT_MAP0_ENABLE                     (0x80000000UL)

/**
* @brief This constant specifies the value of the CR's master access protection
*        Master acces protection enabled
*/
#define SWT_MAP_ENABLE_6BITS                (0xCF000000UL)


/**
* @brief This constant indicates that the fixed service sequence is chosen
*/
#define SWT_FIXED_SERVICE_SEQ               (0x00000000UL)

/**
* @brief This constant indicates that the keyed service sequence is chosen
*/
#define SWT_KEYED_SERVICE_SEQ               (0x00000200UL)

/**
* @brief This constant specifies the value of the first part of the unlock sequence
*        which clears the soft lock
*/
#define SWT_UNLOCK_SEQ1                     (0x0000C520UL)

/**
* @brief This constant specifies the value of the second part of the unlock sequence
*        which clears the soft lock
*/
#define SWT_UNLOCK_SEQ2                     (0x0000D928UL)

/**
* @brief This constant specifies the value of the first part of the fixed service
*        sequence which resets the timeout
*/
#define SWT_FIXED_SERVICE_SEQ1              (0x0000A602UL)

/**
* @brief This constant specifies the value of the second part of the fixed service
*        sequence which resets the timeout
*/
#define SWT_FIXED_SERVICE_SEQ2              (0x0000B480UL)

/**
* @brief This constant specifies the value of the second part of the fixed service
*        sequence which resets the timeout
*        value = (((17UL * REG_READ32(SWT_SK)) + 3UL) mod 2^16)
*/
/* @violates @ref Reg_eSys_Swt_h_REF_5 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define SWT_GET_KEYED_SERVICE_SEQ1(u8ModuleIdx)            ((uint32) ((((17UL * REG_READ32(SWT_SK(u8ModuleIdx)))) + 3UL) & 0x0000FFFFUL))

/**
* @brief  This constant specifies the value that clears the flag and the interrupt. It is
*         written in SWT_IR on the TIF bit
*/
#define SWT_IR_CLEAR                        (0x00000001UL)

#ifdef __cplusplus
}
#endif

#endif  /* REG_ESYS_SWT_H */

/** @} */
