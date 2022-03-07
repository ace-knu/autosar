/**
*   @file    Gpt_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt  - Gpt driver configuration header file.
*   @details GPT driver header file, containing C and XPath constructs for generating Gpt
*   configuration header file.
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

#ifndef GPT_CFG_H
#define GPT_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section GPT_CFG_H_REF_1
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
* @section GPT_CFG_H_REF_2
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused
*
* @section GPT_CFG_H_REF_3
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, a constant, a
* parenthesised expression, a type qualifier, a storage class specifier, or a do-while-zero construct
*
* @section GPT_CFG_H_REF_4
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* This violation is due to large macro name. This is maintained for better readability.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys_eMIOS_CfgEx.h"
#include "Gpt_eMIOS_LLD_CfgEx.h"
#include "Gpt_Stm_LLD_CfgEx.h"
#include "Gpt_Pit_LLD_CfgEx.h"
#include "Gpt_Rtc_LLD_CfgEx.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
@{
* @brief          Gpt_Cfg.h
* @requirements   BSW00374, BSW00379, BSW00318
* @implements     DGPT03600
*/
#define GPT_VENDOR_ID_CFG                    43
/* @violates @ref GPT_CFG_H_REF_1 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_AR_RELEASE_MAJOR_VERSION_CFG     4
/* @violates @ref GPT_CFG_H_REF_1 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_AR_RELEASE_MINOR_VERSION_CFG     0
/* @violates @ref GPT_CFG_H_REF_1 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_AR_RELEASE_REVISION_VERSION_CFG  3
#define GPT_SW_MAJOR_VERSION_CFG             1
#define GPT_SW_MINOR_VERSION_CFG             0
#define GPT_SW_PATCH_VERSION_CFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Gpt_Cfg.h file and Gpt_eMIOS_LLD_CfgEx.h header file are of the same vendor */
#if (GPT_VENDOR_ID_CFG != GPT_EMIOS_LLD_CFGEX_H_VENDOR_ID)
    #error "Gpt_Cfg.h and eMios_Gpt_eMIOS_LLD_CfgEx.h have different vendor ids"
#endif
/* Check if header file and Emios Cfg LLD header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_CFG != GPT_EMIOS_LLD_CFGEX_H_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_CFG != GPT_EMIOS_LLD_CFGEX_H_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_CFG != GPT_EMIOS_LLD_CFGEX_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Cfg.h and Gpt_eMIOS_LLD_CfgEx.h are different"
#endif
/* Check if header file and Emios Cfg LLD header file are of the same software version */
#if ((GPT_SW_MAJOR_VERSION_CFG != GPT_EMIOS_LLD_CFGEX_H_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_CFG != GPT_EMIOS_LLD_CFGEX_H_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_CFG != GPT_EMIOS_LLD_CFGEX_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Cfg.h and eMios_Gpt_LLD_CfgEx.h are different"
#endif

/* Check if Gpt_Cfg.h file and Gpt_Stm_LLD_CfgEx.h header file are of the same vendor */
#if (GPT_VENDOR_ID_CFG != GPT_STM_LLD_CFG_EX_VENDOR_ID)
    #error "Gpt_Cfg.h and Gpt_Stm_LLD_CfgEx.h have different vendor ids"
#endif
/* Check if Gpt_Cfg.h file and Gpt_Stm_LLD_CfgEx.h header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_CFG != GPT_STM_LLD_CFG_EX_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_CFG != GPT_STM_LLD_CFG_EX_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_CFG != GPT_STM_LLD_CFG_EX_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Cfg.h and Gpt_Stm_LLD_CfgEx.h are different"
#endif
/* Check if Gpt_Cfg.h file and Gpt_Stm_LLD_CfgEx.h header file are of the same software version */
#if ((GPT_SW_MAJOR_VERSION_CFG != GPT_STM_LLD_CFG_EX_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_CFG != GPT_STM_LLD_CFG_EX_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_CFG != GPT_STM_LLD_CFG_EX_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Cfg.h and Gpt_Stm_LLD_CfgEx.h are different"
#endif

/* Check if Gpt_Cfg.h file and Reg_eSys_eMIOS_CfgEx.h header file are of the same vendor */
#if (GPT_VENDOR_ID_CFG != REG_ESYS_EMIOS_CFGEX_H_VENDOR_ID)
    #error "Gpt_Cfg.h and Reg_eSys_eMIOS_Cfgex.h have different vendor ids"
#endif
/* Check if header file and Reg_eSys_EMIOS_Cfgex header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_CFG != REG_ESYS_EMIOS_CFGEX_H_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_CFG != REG_ESYS_EMIOS_CFGEX_H_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_CFG != REG_ESYS_EMIOS_CFGEX_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Cfg.h and Reg_eSys_eMIOS_Cfgex.h are different"
#endif
/* Check if header file and Reg_eSys_EMIOS_Cfgex header file are of the same software version */
#if ((GPT_SW_MAJOR_VERSION_CFG != REG_ESYS_EMIOS_CFGEX_H_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_CFG != REG_ESYS_EMIOS_CFGEX_H_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_CFG != REG_ESYS_EMIOS_CFGEX_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Cfg.h and Reg_eSys_EMIOS_Cfgex.h are different"
#endif

/* Check if Gpt_Cfg.h file and Gpt_Pit_LLD_CfgEx.h header file are of the same vendor */
#if (GPT_VENDOR_ID_CFG != GPT_PIT_LLD_CFG_EX_VENDOR_ID)
    #error "Gpt_Cfg.h and Gpt_Pit_LLD_CfgEx.h have different vendor ids"
#endif
/* Check if Gpt_Cfg.h file and Gpt_Pit_LLD_CfgEx.h header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_CFG != GPT_PIT_LLD_CFG_EX_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_CFG != GPT_PIT_LLD_CFG_EX_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_CFG != GPT_PIT_LLD_CFG_EX_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gpt_Cfg.h and Gpt_Pit_LLD_CfgEx.h are different"
#endif
/* Check if Gpt_Cfg.h file and Gpt_Pit_LLD_CfgEx.h header file are of the same software version */
#if ((GPT_SW_MAJOR_VERSION_CFG != GPT_PIT_LLD_CFG_EX_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_CFG != GPT_PIT_LLD_CFG_EX_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_CFG != GPT_PIT_LLD_CFG_EX_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_Cfg.h and Gpt_Pit_LLD_CfgEx.h are different"
#endif

#if (GPT_VENDOR_ID_CFG != GPT_RTC_LLD_CFG_EX_VENDOR_ID)
    #error "Gpt_Cfg.h and Gpt_Rtc_LLD_CfgEx.h have different vendor ids"
#endif
/* Check if header file and Rtc Cfg LLD header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_CFG != GPT_RTC_LLD_CFG_EX_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_CFG != GPT_RTC_LLD_CFG_EX_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_CFG != GPT_RTC_LLD_CFG_EX_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Cfg.h and Gpt_Rtc_LLD_CfgEx.h are different"
#endif
/* Check if header file and Rtc Cfg LLD header file are of the same software version */
#if ((GPT_SW_MAJOR_VERSION_CFG != GPT_RTC_LLD_CFG_EX_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_CFG != GPT_RTC_LLD_CFG_EX_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_CFG != GPT_RTC_LLD_CFG_EX_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Cfg.h and Gpt_Rtc_LLD_CfgEx.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @{
* @brief IDs for peripherals
*/
#define GPT_EMIOS_MODULE  0u
#define GPT_PIT_MODULE    1u
#define GPT_STM_MODULE    2u
#define GPT_RTC_MODULE    3u
/** @} */

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/** 
* @brief Gpt Dev error detect switch
*
* @implements     DGPT01004
*/
#define GPT_DEV_ERROR_DETECT (STD_ON)
/** 
* @brief Report Wakeup Source switch
*/
#define GPT_REPORT_WAKEUP_SOURCE (STD_ON)

/** 
* @brief GPT_VERSION_INFO_API switch
*
* @implements     DGPT01018
*/
#define GPT_VERSION_INFO_API (STD_OFF)
/** 
* @brief GPT_DEINIT_API switch
*
* @implements     DGPT01019
*/
#define GPT_DEINIT_API (STD_OFF)
/** 
* @brief GPT_TIME_ELAPSED_API switch
*
* @implements     DGPT01020
*/
#define GPT_TIME_ELAPSED_API (STD_ON)
/** 
* @brief GPT_TIME_REMAINING_API switch
*
* @implements     DGPT01021
*/
#define GPT_TIME_REMAINING_API (STD_ON)
/** 
* @brief GPT_ENABLE_DISABLE_NOTIFICATION_API switch
*
* @implements     DGPT01016
*/
/* @violates @ref GPT_CFG_H_REF_1 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_ENABLE_DISABLE_NOTIFICATION_API (STD_ON)
/** 
* @brief GPT_WAKEUP_FUNCTIONALITY_API switch
*
* @implements     DGPT01017
*/
#define GPT_WAKEUP_FUNCTIONALITY_API (STD_ON)
/**
* @brief Enable Non-Autosar API for Dual Mode support.
*
* @implements     DGPT01031
*/
#define GPT_DUAL_CLOCK_MODE (STD_OFF)

/* EMIOS counter has 16 bits - Bolero specific */
/* @violates @ref GPT_CFG_H_REF_2 This is not a standard library macro. */
/* @violates @ref GPT_CFG_H_REF_3 C macros shall only expand to a braced initialiser,  a constant, a parenthesised expression */
#define EMIOS_EMIOSCNT_MAX_VALUE      ((uint32)0x000FFFFuL)






#define GPT_PRECOMPILE_SUPPORT (STD_OFF)


/**
* @{
* @brief Number of Gpt channels configured 
*/
#define GPT_CHANNEL_NUM_1   5
/** @} */

/**
* @brief   Specific the max channels of one config set in all config sets.
*/
#define GPT_MAX_EXCLUSIVE_AREA  (5U)



/**
* @{
* @brief Symbolic names of channels 
*/

/* @violates @ref GPT_CFG_H_REF_4 Violates MISRA 2004 Required Rule 1.4, Identifier clash */
/* @violates @ref GPT_CFG_H_REF_1 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_Wdg  0


/* @violates @ref GPT_CFG_H_REF_4 Violates MISRA 2004 Required Rule 1.4, Identifier clash */
/* @violates @ref GPT_CFG_H_REF_1 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_IoHwAbTest  1


/* @violates @ref GPT_CFG_H_REF_4 Violates MISRA 2004 Required Rule 1.4, Identifier clash */
/* @violates @ref GPT_CFG_H_REF_1 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_STM  2


/* @violates @ref GPT_CFG_H_REF_4 Violates MISRA 2004 Required Rule 1.4, Identifier clash */
/* @violates @ref GPT_CFG_H_REF_1 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_Memory  3


/* @violates @ref GPT_CFG_H_REF_4 Violates MISRA 2004 Required Rule 1.4, Identifier clash */
/* @violates @ref GPT_CFG_H_REF_1 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_EMIOS4  4


/** @} */

/**
* @{
* @brief IRQ Defines 
*/
#define GPT_PIT_CH_1_ISR_USED
#define GPT_EMIOS_0_CH_3_ISR_USED
#define GPT_STM_0_CH_0_ISR_USED
#define GPT_PIT_CH_3_ISR_USED
#define GPT_EMIOS_0_CH_4_ISR_USED
/** @} */


/* Configuration structures for PB*/
/* @violates @ref GPT_CFG_H_REF_3 C macros shall only expand to a braced initialiser,  a constant, a parenthesised expression */
#define GPT_CFG_EXTERN_DECLARATIONS \
extern CONST(Gpt_ConfigType, GPT_CONST) GptChannelConfigSet;


/**
* @brief The number of HW channels
*/
#define GPT_HW_CHANNEL_NUM   77

/* The number of EMIOS HW channels */

/**
* @brief The number of EMIOS HW channels 
*/
#define GPT_EMIOS_CHAN_NUM 64

/**
* @brief The number of PIT HW channels 
*/
#define GPT_PIT_CHAN_NUM      8

/**
* @brief The number of STM HW channels 
*/
#define GPT_STM_CHAN_NUM      4

/**
* @brief The number of RTC HW channels
*/
#define GPT_RTC_CHAN_NUM      1

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

#endif  /* GPT_CFG_H */

/** @} */
