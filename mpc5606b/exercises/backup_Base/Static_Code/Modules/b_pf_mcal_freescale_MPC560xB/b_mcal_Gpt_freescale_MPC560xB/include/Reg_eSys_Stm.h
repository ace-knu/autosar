/**
*   @file    Reg_eSys_Stm.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - STM driver header file.
*   @details STM main register description.
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS_Stm_Pit_Rtc
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

#ifndef REG_ESYS_STM_H
#define REG_ESYS_STM_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section REG_ESYS_STM_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section REG_ESYS_STM_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section REG_ESYS_STM_H_REF_3
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
* @section REG_ESYS_STM_H_REF_4
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused
*
* @section REG_ESYS_STM_H_REF_5
* Violates MISRA 2004 Required Rule 8.12, When an array is declared with external linkage, its size shall be 
* stated explicitly or defined implicitly by initialisation.
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @violates @ref REG_ESYS_STM_H_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "Reg_eSys.h"
/* @violates @ref REG_ESYS_STM_H_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "Reg_Macros.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief Parameters that shall be published within the Gpt driver header file and also in the
*       module's description file
* @requirements BSW00374, BSW00379, BSW00318
* @implements DGPT08400
* @{
*/
#define REG_ESYS_STM_VENDOR_ID                       43
/* @violates @ref REG_ESYS_STM_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define REG_ESYS_STM_AR_RELEASE_MAJOR_VERSION        4
/* @violates @ref REG_ESYS_STM_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define REG_ESYS_STM_AR_RELEASE_MINOR_VERSION        0
/* @violates @ref REG_ESYS_STM_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define REG_ESYS_STM_AR_RELEASE_REVISION_VERSION     3
#define REG_ESYS_STM_SW_MAJOR_VERSION                1
#define REG_ESYS_STM_SW_MINOR_VERSION                0
#define REG_ESYS_STM_SW_PATCH_VERSION                1
/** @} */
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/**
* @brief STM base address array declaration
*/
#ifdef  STM_2_BASEADDR
extern CONST(uint32, GPT_CONST) STM_BASE_ADDR[3];
#else
#ifdef  STM_1_BASEADDR
extern CONST(uint32, GPT_CONST) STM_BASE_ADDR[2];
#else 
extern CONST(uint32, GPT_CONST) STM_BASE_ADDR[1];
#endif
#endif

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_MODULE_INDEX(channel)      (((uint32)(channel) & (uint32)STM_MOD_MASK) >> STM_MOD_SHIFT)

/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_CHANNEL_INDEX(channel)     (((uint32)(channel) & (uint32)STM_CH_MASK)  >> STM_CH_SHIFT)

/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_NUMBER_CHANNEL                (((uint32)1) << STM_MOD_SHIFT)

/**
* @{
* @brief System Timer Module (STM) Registers address
*/
/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_CR(channel)      (STM_BASE_ADDR[STM_MODULE_INDEX(channel)] + (uint32)0x0UL)
/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_CNT(channel)     (STM_BASE_ADDR[STM_MODULE_INDEX(channel)] + (uint32)0x4UL)

/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_CCR(channel)     (STM_BASE_ADDR[STM_MODULE_INDEX(channel)] + ((uint32)(STM_CHANNEL_INDEX(channel))<<4) + (uint32)0x10UL)
/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_CIR(channel)     (STM_BASE_ADDR[STM_MODULE_INDEX(channel)] + ((uint32)(STM_CHANNEL_INDEX(channel))<<4) + (uint32)0x14UL)
/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_CMP(channel)     (STM_BASE_ADDR[STM_MODULE_INDEX(channel)] + ((uint32)(STM_CHANNEL_INDEX(channel))<<4) + (uint32)0x18UL)
/** @} */

/**
* @{
* @brief Mask Enabling and Disabling function
*/
#define STM_TEN_DISABLED ((uint32)0x00000000UL)
#define STM_TEN_ENABLED  ((uint32)0x00000001UL)
#define STM_CCR_DISABLE  ((uint32)0x00000000UL)
#define STM_CCR_ENABLE   ((uint32)0x00000001UL)
#define STM_CIR_CLEAR    ((uint32)0x00000001UL)
#define STM_FRZ_ENABLE   ((uint32)0x00000002UL)

#define STM_OVERFLOW_PAD         ((uint8)1U)
/* Mask for prescaler setting */
#define STM_PRESCALER_MASK ((uint32)0x0000FF00UL)
/** @} */

/**
* @brief Highest possible value for STM channels
*/
#define STM_CNT_MAX_VALUE                      ((uint32)0xFFFFFFFFuL)

/**
* @brief Macros for System Timer Module (STM) Registers
*/
/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_TIMER_COUNTER_DISABLE(channel) (REG_BIT_CLEAR32(STM_CR(channel),STM_TEN_ENABLED))  /**< @brief Macro to Disable STM counter */
/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_TIMER_COUNTER_ENABLE(channel)  (REG_BIT_SET32(STM_CR(channel),STM_TEN_ENABLED))  /**< @brief Macro to enable STM counter */
/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_CH_DISABLE(channel)            (REG_WRITE32(STM_CCR(channel),STM_CCR_DISABLE))  /**< @brief Macro to disable STM channel */
/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_CH_ENABLE(channel)             (REG_WRITE32(STM_CCR(channel),STM_CCR_ENABLE))  /**< @brief Macro to enable STM channel */
/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_CH_READ_ISR_REQ(channel)       (REG_READ32(STM_CIR(channel)))  /**< @brief Macro to read the interrupt status */
/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_CH_CLEAR_ISR_REQ(channel)      (REG_WRITE32(STM_CIR(channel),STM_CIR_CLEAR))  /**< @brief Macro to clear the interrupt flag  */
/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_GET_COUNTER(channel)           (REG_READ32(STM_CNT(channel)))  /**< @brief Macro to get the counter value */
/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_SET_PRESCALER(channel, value)  (REG_RMW32(STM_CR(channel),STM_PRESCALER_MASK,(uint32)(((uint32)(value))<<(uint32)8U)))  /**< @brief Macro to set the prescaler value  */
/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_SET_COMPARE(channel, value)    (REG_WRITE32((STM_CMP(channel)),(value)))  /**< @brief Macro to set the compare value */
/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_GET_COMPARE(channel)           (REG_READ32(STM_CMP(channel)))  /**< @brief Macro to get the compare value */
/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_SET_FRZ(channel)               (REG_BIT_SET32(STM_CR(channel),STM_FRZ_ENABLE))  /**< @brief Macro to enable the Freeze */
/**< @brief Macro to disbale the Freeze */
/* @violates @ref REG_ESYS_STM_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define STM_CLR_FRZ(channel)               (REG_BIT_CLEAR32(STM_CR(channel),STM_FRZ_ENABLE))

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*REG_ESYS_STM_H*/

/** @} */
