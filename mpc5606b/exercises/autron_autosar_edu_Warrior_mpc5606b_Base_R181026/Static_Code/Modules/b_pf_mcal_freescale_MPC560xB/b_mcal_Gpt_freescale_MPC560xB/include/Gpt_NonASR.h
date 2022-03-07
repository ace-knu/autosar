/**
*   @file    Gpt_NonASR.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - GPT driver non Autosar header file.
*   @details GPT driver header file, containing non Autosar API specification and other variables
*            and functions that are exported by the GPT driver.
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

#ifndef GPT_NONASR_H
#define GPT_NONASR_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
@page misra_violations MISRA-C:2004 violations

@section GPT_NonASR_H_REF_1
Violates MISRA 2004 Required Rule 19.15, Repeated include file
This violation is not fixed since all header files are protected against multiple inclusions.

 @section GPT_NonASR_H_REF_2
 Violates MISRA 2004 Required Rule 1.4, Identifier clash.
The long names are maintained for better readability..
*
* @section GPT_NonASR_H_REF_3
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/* @violates @ref GPT_NonASR_H_REF_1 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "Std_Types.h"
/* @violates @ref GPT_NonASR_H_REF_1 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "Gpt.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_NonASR.h
* @requirements   BSW00374, BSW00379, BSW00318
* @implements     DGPT02600
* @{
*/
#define GPT_VENDOR_ID_NONASR_H                      43
#define GPT_MODULE_ID_NONASR_H                      100
/* @violates @ref GPT_NonASR_H_REF_3 Violates MISRA 2004 Required Rule 5.1,
* The long identifiers are maintained for better readability. */
#define GPT_AR_RELEASE_MAJOR_VERSION_NONASR_H       4
/* @violates @ref GPT_NonASR_H_REF_3 Violates MISRA 2004 Required Rule 5.1,
* The long identifiers are maintained for better readability. */
#define GPT_AR_RELEASE_MINOR_VERSION_NONASR_H       0
/* @violates @ref GPT_NonASR_H_REF_2 Violates MISRA 2004 Required Rule 1.4,  Identifier clash*/
/* @violates @ref GPT_NonASR_H_REF_3 Violates MISRA 2004 Required Rule 5.1,
* The long identifiers are maintained for better readability. */
#define GPT_AR_RELEASE_REVISION_VERSION_NONASR_H    3
#define GPT_SW_MAJOR_VERSION_NONASR_H               1
#define GPT_SW_MINOR_VERSION_NONASR_H               0
#define GPT_SW_PATCH_VERSION_NONASR_H               1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((GPT_AR_RELEASE_MAJOR_VERSION_NONASR_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_AR_RELEASE_MINOR_VERSION_NONASR_H != STD_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt_NonASR.h and Std_Types.h are different"
    #endif
#endif

/* Check if source file and GPT configuration header file are of the same vendor */
#if (GPT_VENDOR_ID_NONASR_H != GPT_VENDOR_ID_CFG)
    #error "Gpt_NonASR.h and GPT_Cfg.h have different vendor IDs"
#endif
/* Check if header file and GPT configuration header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_NONASR_H != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (GPT_AR_RELEASE_MINOR_VERSION_NONASR_H != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
     (GPT_AR_RELEASE_REVISION_VERSION_NONASR_H != GPT_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Gpt_NonASR.h and Gpt_Cfg.h are different"
#endif
/* Check if header file and GPT configuration header file are of the same software version */
#if ((GPT_SW_MAJOR_VERSION_NONASR_H != GPT_SW_MAJOR_VERSION_CFG) || \
     (GPT_SW_MINOR_VERSION_NONASR_H != GPT_SW_MINOR_VERSION_CFG) || \
     (GPT_SW_PATCH_VERSION_NONASR_H != GPT_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of GptNonASR.h and Gpt_Cfg.h are different"
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief   API Gpt_SetClockMode service called with wrong parameter
* @details Parameters used when raising an error/exception
*/
#define GPT_E_PARAM_CLOCK_MODE          0x7AU

/**
* @brief   API service ID for Gpt_SetClockMode function
* @details Parameters used when raising an error/exception
*/
#define GPT_SET_CLOCK_MODE_ID           0x7BU

/**
* @brief   API service ID for Gpt_ChangeNextTimeoutValue function
* @details Parameters used when raising an error/exception
*/
/* @violates @ref GPT_NonASR_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID    0x7CU

/**
* @brief Prescaler type
*
* @implements     DGPT02201
*/
#if (GPT_DUAL_CLOCK_MODE == STD_ON)
typedef enum
{
    GPT_NORMAL    = 0x0U,
    GPT_ALTERNATE = 0x1U
}Gpt_ClockModeType;
#endif /* GPT_DUAL_CLOCK_MODE */

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

#define GPT_START_SEC_CODE
/* @violates @ref GPT_NonASR_H_REF_1 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"


#if (GPT_DUAL_CLOCK_MODE == STD_ON)
FUNC (void, GPT_CODE) Gpt_SetClockMode(VAR(Gpt_ClockModeType, AUTOMATIC) clkMode);
#endif

#ifdef GPT_CHANGE_NEXT_TIMEOUT_VALUE
#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
FUNC (void, GPT_CODE) Gpt_ChangeNextTimeoutValue(VAR(Gpt_ChannelType, AUTOMATIC) channel, VAR(Gpt_ValueType, AUTOMATIC) value);
#endif /* GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON */
#endif

#define GPT_STOP_SEC_CODE
/* @violates @ref GPT_NonASR_H_REF_1 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* GPT_NONASR_H */

/** @} */
