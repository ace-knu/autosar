/**
*   @file    Reg_eSys_DMAMUX.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - DMAMUX Registers and Macros Definitions.
*   @details DMAMux IP module low level driver .
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

#ifndef REG_eSys_DMAMUX_H
#define REG_eSys_DMAMUX_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_DMAMUX_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined because
* of code complexity
*
* @section Reg_eSys_DMAMUX_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Reg_eSys_DMAMUX_H_REF_3
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*
* @section Reg_eSys_DMAMUX_H_REF_4
* Violates MISRA 2004 Required Rule 19.10, In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##.
* This is required for better readability of macro.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @violates @ref Reg_eSys_DMAMUX_H_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Reg_eSys.h"
/**
* @violates @ref Reg_eSys_DMAMUX_H_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Reg_Macros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMAMUX_REG_VENDOR_ID                      43
/*
* @violates @ref Reg_eSys_DMAMUX_H_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define DMAMUX_REG_AR_RELEASE_MAJOR_VERSION       4
/*
* @violates @ref Reg_eSys_DMAMUX_H_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define DMAMUX_REG_AR_RELEASE_MINOR_VERSION       0
/*
* @violates @ref Reg_eSys_DMAMUX_H_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define DMAMUX_REG_AR_RELEASE_REVISION_VERSION    3
#define DMAMUX_REG_SW_MAJOR_VERSION               1
#define DMAMUX_REG_SW_MINOR_VERSION               0
#define DMAMUX_REG_SW_PATCH_VERSION               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#ifndef DMAMUX_CTRL_MAX_CHANNELS
/**
* @brief Define to identify max number of channels per DMAMUX controller
*/
#define DMAMUX_CTRL_MAX_CHANNELS            (0x10U)

/**
* @brief Mask used to select the DMAMUX controller for a given channel
*/
#define DMAMUX_CTRL_MAX_CHANNELS_MASK       (0x0FU)
#endif

/**
* @brief Define to the shift value for used to identify the module
*/
#define DMAMUX_CTRL_MAX_CHANNELS_SHIFT      (0x04U)

/**
* @brief Macro to extract the controller index for a given channel
*/
/**
* @violates @ref Reg_eSys_DMAMUX_H_REF_1 Function-like macro defined because of code complexity
* @violates @ref Reg_eSys_DMAMUX_H_REF_4 In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses
*/
#define DMAMUX_CTRL_INDEX(channel)  \
        ((uint32)(((channel & ((uint8)(~DMAMUX_CTRL_MAX_CHANNELS_MASK))))>> \
                DMAMUX_CTRL_MAX_CHANNELS_SHIFT))

/**
* @brief Macro to extract the channel index in a controller for a given channel
*/
/**
* @violates @ref Reg_eSys_DMAMUX_H_REF_1 Function-like macro defined because of code complexity
*/
#define DMAMUX_CHANNEL_INDEX(channel)     ((channel) & DMAMUX_CTRL_MAX_CHANNELS_MASK)

/**
* @brief Macro to extract the address of CHCONF register based on a given channel
*/
/**
* @violates @ref Reg_eSys_DMAMUX_H_REF_1 Function-like macro defined because of code complexity
*/
#define DMAMUX_CHCONF(channel) \
        (DMAMUX_BASE_ADDR[DMAMUX_CTRL_INDEX(channel)] + DMAMUX_CHANNEL_INDEX(channel))

/**
* @brief          DMA Channel source (slot) mask
*/
#define DMAMUX_SOURCE_MASK          ((uint8)0x3F)

/**
* @brief          DMA Channel trigger enable mask
*/
#define DMAMUX_TRIG_MASK            ((uint8)0x40)

/**
* @brief          Bit shift count to position the TRIG bit
*/
#define DMAMUX_TRIG_SHIFT           ((uint8)6)

/**
* @brief          DMA Channel enable mask
*/
#define DMAMUX_ENBL_MASK            ((uint8)0x80)
/**
* @brief          Bit shift count to position the ENBL bit
*/
#define DMAMUX_ENBL_SHIFT           ((uint8)7)

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


#ifdef __cplusplus
}
#endif

#endif /* REG_eSys_DMAMUX_H */

/** @} */
