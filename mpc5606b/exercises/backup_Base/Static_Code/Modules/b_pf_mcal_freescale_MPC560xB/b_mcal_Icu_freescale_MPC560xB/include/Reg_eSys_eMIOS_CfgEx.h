/**
*   @file    Reg_eSys_EMIOS_CfgEx.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Icu - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup EMIOS_DRIVER
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


/**
*
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_eMIOS_CfgEx_h_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Reg_eSys_eMIOS_CfgEx_h_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Reg_eSys_eMIOS_CfgEx_h_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Reg_eSys_eMIOS_CfgEx_h_4
* Violates MISRA 2004 Required Rule 20.2, This violation is not fixed since we have not used any
* Standard library macros.
*
*@section Reg_eSys_eMIOS_CfgEx_h_5
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of 
* identifiers(internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
*/
#ifndef REG_ESYS_EMIOS_CFGEX_H
#define REG_ESYS_EMIOS_CFGEX_H

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
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "modules.h"
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Reg_eSys.h"
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Reg_Macros.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief   Header file version information
*/
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_5 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_CFGEX_H_VENDOR_ID                            43
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_5 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_CFGEX_H_AR_RELEASE_MAJOR_VERSION             4
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_3 The compiler/linker shall be checked to ensure 31 
* character  significance and case sensitivity are supported for external identifiers
*/
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_5 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_CFGEX_H_AR_RELEASE_MINOR_VERSION             0
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_3 The compiler/linker shall be checked to ensure 31 
* character  significance and case sensitivity are supported for external identifiers
*/
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_5 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_CFGEX_H_AR_RELEASE_REVISION_VERSION          3
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_5 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_CFGEX_H_SW_MAJOR_VERSION                     1
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_5 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_CFGEX_H_SW_MINOR_VERSION                     0
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_5 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_CFGEX_H_SW_PATCH_VERSION                     1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* No checks needed as the included files ( Reg_eSys.h, Reg_Macros.h) do not define versions */


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/



/**
* @brief EMIOS channels defines
*/

/*
 * EMIOS channel encoding
 *
 * [              3 bit | 5 bit                ]
 * [ module id: 7 ... 0 | channel id: 31 ... 0 ]
 */
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro, 
*/
#define EMIOS_MOD_MASK  ((uint8)0xE0)
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro, 
*/
#define EMIOS_MOD_SHIFT ((uint8)5U)
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro, 
*/
#define EMIOS_CH_MASK   ((uint8)0x1F)
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro, 
*/
#define EMIOS_CH_SHIFT  ((uint8)0U)


/** EMIOS module and channel decoding */
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_2 Function-like macro defined
*/
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro, 
*/
#define EMIOS_MODULE_INDEX(ch)      ((uint8)(((ch) & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT))
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_2 Function-like macro defined
*/
/*
* @violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro, 
*/
#define EMIOS_CHANNEL_INDEX(ch)     ((uint8)(((ch) & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT))

/**
* @brief EMIOS Channels defines
*/
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_0     ((uint8)0x00)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_1     ((uint8)0x01)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_2     ((uint8)0x02)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_3     ((uint8)0x03)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_4     ((uint8)0x04)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_5     ((uint8)0x05)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_6     ((uint8)0x06)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_7     ((uint8)0x07)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_8     ((uint8)0x08)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_9     ((uint8)0x09)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_10    ((uint8)0x0A)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_11    ((uint8)0x0B)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_12    ((uint8)0x0C)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_13    ((uint8)0x0D)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_14    ((uint8)0x0E)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_15    ((uint8)0x0F)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_16    ((uint8)0x10)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_17    ((uint8)0x11)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_18    ((uint8)0x12)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_19    ((uint8)0x13)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_20    ((uint8)0x14)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_21    ((uint8)0x15)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_22    ((uint8)0x16)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_23    ((uint8)0x17)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_24    ((uint8)0x18)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_25    ((uint8)0x19)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_26    ((uint8)0x1A)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_27    ((uint8)0x1B)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_28    ((uint8)0x1C)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_29    ((uint8)0x1D)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_30    ((uint8)0x1E)

/** @violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_31    ((uint8)0x1F)

/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_0    (EMIOS_CHANNEL_0)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_1    (EMIOS_CHANNEL_1)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_2    (EMIOS_CHANNEL_2)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_3    (EMIOS_CHANNEL_3)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_4    (EMIOS_CHANNEL_4)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_5    (EMIOS_CHANNEL_5)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_6    (EMIOS_CHANNEL_6)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_7    (EMIOS_CHANNEL_7)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_8    (EMIOS_CHANNEL_8)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_9    (EMIOS_CHANNEL_9)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_10   (EMIOS_CHANNEL_10)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_11   (EMIOS_CHANNEL_11)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_12   (EMIOS_CHANNEL_12)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_13   (EMIOS_CHANNEL_13)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_14   (EMIOS_CHANNEL_14)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_15   (EMIOS_CHANNEL_15)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_16   (EMIOS_CHANNEL_16)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_17   (EMIOS_CHANNEL_17)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_18   (EMIOS_CHANNEL_18)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_19   (EMIOS_CHANNEL_19)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_20   (EMIOS_CHANNEL_20)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_21   (EMIOS_CHANNEL_21)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_22   (EMIOS_CHANNEL_22)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_23   (EMIOS_CHANNEL_23)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_24   (EMIOS_CHANNEL_24)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_25   (EMIOS_CHANNEL_25)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_26   (EMIOS_CHANNEL_26)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_27   (EMIOS_CHANNEL_27)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_28   (EMIOS_CHANNEL_28)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_29   (EMIOS_CHANNEL_29)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_30   (EMIOS_CHANNEL_30)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_0_CH_31   (EMIOS_CHANNEL_31)
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_0    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_0))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_1    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_1))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_2    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_2))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_3    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_3))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_4    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_4))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_5    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_5))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_6    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_6))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_7    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_7))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_8    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_8))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_9    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_9))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_10   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_10))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_11   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_11))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_12   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_12))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_13   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_13))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_14   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_14))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_15   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_15))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_16   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_16))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_17   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_17))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_18   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_18))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_19   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_19))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_20   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_20))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_21   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_21))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_22   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_22))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_23   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_23))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_24   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_24))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_25   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_25))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_26   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_26))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_27   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_27))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_28   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_28))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_29   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_29))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_30   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_30))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_1_CH_31   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_31))

/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_0    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_0))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_1    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_1))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_2    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_2))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_3    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_3))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_4    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_4))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_5    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_5))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_6    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_6))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_7    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_7))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_8    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_8))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_9    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_9))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_10   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_10))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_11   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_11))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_12   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_12))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_13   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_13))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_14   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_14))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_15   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_15))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_16   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_16))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_17   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_17))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_18   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_18))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_19   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_19))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_20   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_20))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_21   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_21))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_22   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_22))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_23   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_23))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_24   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_24))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_25   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_25))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_26   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_26))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_27   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_27))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_28   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_28))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_29   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_29))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_30   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_30))
/**@violates @ref Reg_eSys_eMIOS_CfgEx_h_4 This is not a standard library macro */
#define EMIOS_2_CH_31   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_31))
/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_EMIOS_CFGEX_H */
/** @} */
