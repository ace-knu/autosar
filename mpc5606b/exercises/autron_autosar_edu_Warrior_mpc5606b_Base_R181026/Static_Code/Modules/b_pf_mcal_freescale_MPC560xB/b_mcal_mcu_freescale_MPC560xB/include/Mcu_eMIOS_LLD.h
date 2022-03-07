/**
*   @file    Mcu_eMIOS_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
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
/**
*
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_eMIOS_LLD_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Precautions shall be taken in order to prevent the contents of a
* header file being included twice.
* This is not a violation since all header files are protected against multiple inclusions.
*
* @section Mcu_eMIOS_LLD_H_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, A function should be used in preference to a function-like
* macro. This is the compiler abstraction specified in AutoSar Specification of Compiler Abstraction.
*
* @section Mcu_eMIOS_LLD_H_REF_3
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
* 
*/
#ifndef MCU_EMIOS_LLD_H
#define MCU_EMIOS_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Mcu_eMIOS_LLD_H_REF_1 Repeated include file
*/
#include "Std_Types.h"
#include "Reg_eSys_eMIOS.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @implements     DMCU05401, DMCU05402, DMCU05403, DMCU05404, DMCU05405, DMCU05406,
*                  DMCU05407
*/

#define MCU_EMIOS_LLD_H_VENDOR_ID            43

/*
* @violates @ref Mcu_eMIOS_LLD_H_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION        4
/*
* @violates @ref Mcu_eMIOS_LLD_H_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION        0
/*
* @violates @ref Mcu_eMIOS_LLD_H_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_EMIOS_LLD_H_AR_RELEASE_REVISION_VERSION     3
/*
* @violates @ref Mcu_eMIOS_LLD_H_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_EMIOS_LLD_H_SW_MAJOR_VERSION                1
/*
* @violates @ref Mcu_eMIOS_LLD_H_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_EMIOS_LLD_H_SW_MINOR_VERSION                0
/*
* @violates @ref Mcu_eMIOS_LLD_H_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_EMIOS_LLD_H_SW_PATCH_VERSION                1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Mcu.h file are of the same vendor */
/* #if (MCU_EMIOS_LLD_H_VENDOR_ID != MCU_VENDOR_ID_CFG)
    #error "Mcu_eMIOS_LLD.h and Mcu.h have different vendor ids"
#endif */

/* Check if source file and Gpt header file are of the same Autosar version */
/* #if ((MCU_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION != MCU_AR_RELEASE_MAJOR_VERSION) || \
        (MCU_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION != MCU_AR_RELEASE_MINOR_VERSION) || \
        (MCU_EMIOS_LLD_H_AR_RELEASE_REVISION_VERSION != MCU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_eMIOS_LLD.h and Mcu.h are different"
#endif */


/* Check if source file and Mcu header file are of the same software version */
/* #if ((MCU_EMIOS_LLD_H_SW_MAJOR_VERSION != MCU_SW_MAJOR_VERSION) || \
        (MCU_EMIOS_LLD_H_SW_MINOR_VERSION != MCU_SW_MINOR_VERSION) || \
        (MCU_EMIOS_LLD_H_SW_PATCH_VERSION != MCU_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcu_eMIOS_LLD.h and Mcu.h are different"
#endif */
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#define MCU_EMIOS_CONFIGURE_GPREN_ID          (0x30U)
#define MCU_GPREN_BIT                         ((uint32)0x04000000UL)
#define MCU_EMIOS_MODULE_0                    (0x00U)
#define MCU_EMIOS_MODULE_1                    (0x01U)
#define MCU_EMIOS_GPREN_BIT_ENABLE            (0x01U)
#define MCU_EMIOS_GPREN_BIT_DISABLE           (0x00U)

/*
 * @violates @ref Mcu_eMIOS_LLD_H_REF_2 Advisory Rule 19.7, A function should be used in preference to a 
 * function-like macro.
 */
#define MCU_EMIOS_GPREN_SET(emios_idx)        (REG_BIT_SET32(((uint32)(EMIOS_MCR(emios_idx))), (MCU_GPREN_BIT)))
/*
 * @violates @ref Mcu_eMIOS_LLD_H_REF_2 Advisory Rule 19.7, A function should be used in preference to a 
 * function-like macro.
 */
#define MCU_EMIOS_GPREN_CLEAR(emios_idx)      (REG_BIT_CLEAR32(((uint32)(EMIOS_MCR(emios_idx))),((uint32)(MCU_GPREN_BIT))))
/*
 * @violates @ref Mcu_eMIOS_LLD_H_REF_2 Advisory Rule 19.7, A function should be used in preference to a 
 * function-like macro.
 */
#define MCU_EMIOS_GPREN_Conf(emios_idx,value) (((value)>(uint8)(0)) ? (MCU_EMIOS_GPREN_SET(emios_idx)) : (MCU_EMIOS_GPREN_CLEAR(emios_idx)))

/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          EMIOS configuration.
*/
typedef struct {
    VAR(uint32,  AUTOMATIC) EmiosCr[EMIOS_NB_MODULES];
} eMIOS_ConfigType;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define MCU_START_SEC_CODE
/*
* @violates @ref Mcu_eMIOS_LLD_H_REF_1 Repeated include file
*/
#include "MemMap.h"

FUNC (void, MCU_CODE) Mcu_EMIOS_Init (P2CONST(eMIOS_ConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr);

#define MCU_STOP_SEC_CODE
/*
* @violates @ref Mcu_eMIOS_LLD_H_REF_1 Repeated include file
*/
#include "MemMap.h"


#ifdef __cplusplus
}
#endif


#endif   /* MCU_EMIOS_LLD_H */

/** @} */
