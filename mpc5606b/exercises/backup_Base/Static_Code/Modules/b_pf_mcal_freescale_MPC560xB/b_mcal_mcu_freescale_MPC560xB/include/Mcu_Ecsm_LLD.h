/**
*   @file    Mcu_Ecsm_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - ECSM Low level driver header file.
*   @details ECSM IP module low level driver.
*
*   @addtogroup MCU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : MC
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF13_ASR_REL_4_0_REV_0003_20170719
*
*   (c) Copyright 2006-2016 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef MCU_ECSM_LLD_H
#define MCU_ECSM_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_Escm_LLD_h_REF_1
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*
* @section Mcu_Escm_LLD_h_REF_2
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and
* functions shall not be reused. Symbol required to be defined when one compiler is used.
* Requested by AutoSAR (Req. COMPILER010).
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys_ECSM.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcu_Ecsm_LLD.h
* @implements     DMCU05083, DMCU05084, DMCU05085, DMCU05086, DMCU05087, DMCU05088,
*                 DMCU05089
*/
#define MCU_ECSM_VENDOR_ID                      43
/*
* @violates @ref Mcu_Escm_LLD_h_REF_1 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_ECSM_AR_RELEASE_MAJOR_VERSION       4
/*
* @violates @ref Mcu_Escm_LLD_h_REF_1 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_ECSM_AR_RELEASE_MINOR_VERSION       0
/*
* @violates @ref Mcu_Escm_LLD_h_REF_1 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_ECSM_AR_RELEASE_REVISION_VERSION    3
#define MCU_ECSM_SW_MAJOR_VERSION               1
#define MCU_ECSM_SW_MINOR_VERSION               0
#define MCU_ECSM_SW_PATCH_VERSION               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys_ECSM.h header file are of the same vendor */
#if (MCU_ECSM_VENDOR_ID != ECSM_REG_VENDOR_ID)
#error "Mcu_Ecsm_LLD.h and Reg_eSys_ECSM.h have different vendor ids"
#endif
/*
* @implements     DMCU06001
*/
/* Check if current file and Reg_eSys_ECSM header file are of the same Autosar version */
#if ((MCU_ECSM_AR_RELEASE_MAJOR_VERSION   != ECSM_REG_AR_RELEASE_MAJOR_VERSION) || \
    (MCU_ECSM_AR_RELEASE_MINOR_VERSION    != ECSM_REG_AR_RELEASE_MINOR_VERSION) || \
    (MCU_ECSM_AR_RELEASE_REVISION_VERSION != ECSM_REG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcu_Ecsm_LLD.h and Reg_eSys_ECSM.h are different"
#endif
/* Check if current file and Reg_eSys_ECSM.h header file are of the same Software version */
#if ((MCU_ECSM_SW_MAJOR_VERSION != ECSM_REG_SW_MAJOR_VERSION) || \
     (MCU_ECSM_SW_MINOR_VERSION != ECSM_REG_SW_MINOR_VERSION) || \
     (MCU_ECSM_SW_PATCH_VERSION != ECSM_REG_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcu_Ecsm_LLD.h and Reg_eSys_ECSM.h are different"
#endif
/* Check if current file and Std_Types configuration header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
   #if ((MCU_ECSM_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
        (MCU_ECSM_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
   #error "AutoSar Version Numbers of Mcu_Ecsm_LLD.h and Std_Types.h are different"
   #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#ifdef IPV_ECSM
    #if (IPV_ECSM == IPV_ECSM_01_00_00_08) /*  MPC56XXK has changed bit definitions*/
/*
* @violates @ref Mcu_Escm_LLD_h_REF_2 The names of standard library
* macros, objects and functions shall not be reused.
*/
        #define ECSM_SET_MUDCR            ((uint32)0x80000000UL)
/*
* @violates @ref Mcu_Escm_LLD_h_REF_2 The names of standard library
* macros, objects and functions shall not be reused.
*/
        #define ECSM_CLEAR_MUDCR          ((uint32)0x00000000UL)
/*
* @violates @ref Mcu_Escm_LLD_h_REF_2 The names of standard library
* macros, objects and functions shall not be reused.
*/
        #define ECSM_SET_MUDCR_1          ((uint32)0x40000000UL)
/*
* @violates @ref Mcu_Escm_LLD_h_REF_2 The names of standard library
* macros, objects and functions shall not be reused.
*/
        #define ECSM_CLEAR_MUDCR_1        ((uint32)0x00000000UL)
    #else /* all other platform */
/*
* @violates @ref Mcu_Escm_LLD_h_REF_2 The names of standard library
* macros, objects and functions shall not be reused.
*/
        #define ECSM_SET_MUDCR            ((uint32)0x40000000UL)
/*
* @violates @ref Mcu_Escm_LLD_h_REF_2 The names of standard library
* macros, objects and functions shall not be reused.
*/
        #define ECSM_CLEAR_MUDCR          ((uint32)0x00000000UL)
/*
* @violates @ref Mcu_Escm_LLD_h_REF_2 The names of standard library
* macros, objects and functions shall not be reused.
*/
        #define ECSM_SET_MUDCR_1          ((uint32)0x40000000UL)
/*
* @violates @ref Mcu_Escm_LLD_h_REF_2 The names of standard library
* macros, objects and functions shall not be reused.
*/
        #define ECSM_CLEAR_MUDCR_1        ((uint32)0x00000000UL)
    #endif
#else /* default values if smth goes wrong */
    #define ECSM_SET_MUDCR            ((uint32)0x40000000UL)
    #define ECSM_CLEAR_MUDCR          ((uint32)0x00000000UL)
    #define ECSM_SET_MUDCR_1          ((uint32)0x40000000UL)
    #define ECSM_CLEAR_MUDCR_1        ((uint32)0x00000000UL)
#endif
/*
* @violates @ref Mcu_Escm_LLD_h_REF_2 The names of standard library
* macros, objects and functions shall not be reused.
*/
#define ECSM_MUDCR_1_ENABLE       ((uint32)0x00000001UL)
/*
* @violates @ref Mcu_Escm_LLD_h_REF_2 The names of standard library
* macros, objects and functions shall not be reused.
*/
#define ECSM_MUDCR_1_DISABLE      ((uint32)0x00000000UL)
/*
* @violates @ref Mcu_Escm_LLD_h_REF_2 The names of standard library
* macros, objects and functions shall not be reused.
*/
#define ECSM_MASK_R1BC            ((uint8)0x20U)
/*
* @violates @ref Mcu_Escm_LLD_h_REF_2 The names of standard library
* macros, objects and functions shall not be reused.
*/
#define ECSM_MASK_RNCE            ((uint8)0x02U)
/*
* @violates @ref Mcu_Escm_LLD_h_REF_2 The names of standard library
* macros, objects and functions shall not be reused.
*/
#define ECSM_MASK_ER1BR_ERNCR_ENABLE  ((uint8)0x22U)

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
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

#ifdef IPV_ECSM
  #if ((IPV_ECSM == IPV_ECSM_01_00_02_00) || (IPV_ECSM == IPV_ECSM_01_00_00_04) || (IPV_ECSM == IPV_ECSM_01_00_00_08)) /*  XPC56XXL / XPC56AXP60 / MPC56XXK */
FUNC(void, MCU_CODE) Ecsm_SetMUDCR(VAR(uint32, AUTOMATIC) mudcr_value,VAR(uint32, AUTOMATIC) mudcr1_value);
  #else
FUNC(void, MCU_CODE) Ecsm_SetMUDCR(VAR(uint32, AUTOMATIC) mudcr_value);
  #endif
#endif

#ifdef IPV_ECSM /* XPC5602D/XPC5604B/XPC5607B/XPC56XXA 4M/MPC5676R/XPC56XXA 2M/XPC56AXP60/XPC560XP50/XPC560XP40 */
  #if ((IPV_ECSM == IPV_ECSM_10_10_00_12) || (IPV_ECSM == IPV_ECSM_01_00_00_09) || \
       (IPV_ECSM == IPV_ECSM_01_00_01_04) || (IPV_ECSM == IPV_ECSM_00_00_00_20) || \
       (IPV_ECSM == IPV_ECSM_01_00_02_02) || (IPV_ECSM == IPV_ECSM_01_00_00_04) || \
       (IPV_ECSM == IPV_ECSM_01_00_01_02) || (IPV_ECSM == IPV_ECSM_01_00_02_07) || \
       (IPV_ECSM == IPV_ECSM_B1_00_00_08)) 
    #if (MCU_GET_RAM_STATE_API == STD_ON)
FUNC (Mcu_RamStateType, MCU_CODE) Ecsm_GetRamState(VAR (void, MCU_VAR));

FUNC(void, MCU_CODE) Ecsm_GetRamInit(VAR (void, MCU_VAR));
    #endif 
  #endif 
#endif 

#ifdef __cplusplus
}
#endif

#endif /* MCU_ECSM_LLD_H */

/** @} */
