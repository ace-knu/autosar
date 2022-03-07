/**
*   @file    Gpt_PBcfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt -  GPT driver configuration source file.
*   @details GPT driver source file, containing C and XPath constructs for generating Gpt
*            configuration source file for the Post-build configuration variant.
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Gpt_PBcfg_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include'
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement
* MEMMAP003.
*
* @section Gpt_PBcfg_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Gpt_PBcfg_C_REF_3
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* The long names are maintained for better readability..
*
* @section Gpt_PBcfg_C_REF_4
* Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope
* If a variable to be used within a Function in the same file use Static.Similarly if a function is called 
* from elsewhere within the same file use Static.
*
* @section Gpt_PBcfg_C_REF_5
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
/**
* @file           Gpt_PBcfg.c
* @requirements   BSW00374, BSW00318
* @violates @ref Gpt_PBcfg_C_REF_3 Violates MISRA 2004 Required Rule 1.4, Identifier clash
* @implements     DGPT03800
*/
#include "Gpt.h"
#include "Mcal.h"

#if (GPT_PRECOMPILE_SUPPORT == STD_OFF)
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_PBcfg.c
* @requirements   BSW00374, BSW00318
*/
#define GPT_VENDOR_ID_PBCFG_C                      43
/* @violates @ref Gpt_PBcfg_C_REF_5 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_AR_RELEASE_MAJOR_VERSION_PBCFG_C       4
/* @violates @ref Gpt_PBcfg_C_REF_5 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_AR_RELEASE_MINOR_VERSION_PBCFG_C       0
/* @violates @ref Gpt_PBcfg_C_REF_3 Violates MISRA 2004 Required Rule 1.4, Identifier clash */
/* @violates @ref Gpt_PBcfg_C_REF_5 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_AR_RELEASE_REVISION_VERSION_PBCFG_C    3
#define GPT_SW_MAJOR_VERSION_PBCFG_C               1
#define GPT_SW_MINOR_VERSION_PBCFG_C               0
#define GPT_SW_PATCH_VERSION_PBCFG_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Gpt_PBcfg.c file and Gpt.h header file are of the same vendor */
#if (GPT_VENDOR_ID_PBCFG_C != GPT_VENDOR_ID)
    #error "Gpt_PBcfg.c and Gpt.h have different vendor ids"
#endif
/* Check if Gpt_PBcfg.c file and Gpt.h header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_PBCFG_C != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_PBCFG_C != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_PBCFG_C != GPT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_PBcfg.c and Gpt.h are different"
#endif
/* Check if Gpt_PBcfg.c file and Gpt.h header file are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION_PBCFG_C != GPT_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_PBCFG_C != GPT_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_PBCFG_C != GPT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_PBcfg.c and Gpt.h are different"
#endif

/*================================================================================================*/
#define GPT_START_SEC_CODE
/* @violates @ref Gpt_PBcfg_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include' */
/* @violates @ref Gpt_PBcfg_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Short description of the violated MISRA rule (rule headline) */
#include "MemMap.h"
/**
* @{
* @brief The callback functions defined by the user to be called as channel notifications 
*/
extern void Wdg_Cbk_GptNotification0(void);
extern void GptChannelConfiguration_Dummy_Cbk(void);
extern void NvM_Call_NvM_BITP_MainFunction(void);
extern void GptChannelConfiguration_IoHwAbTest_Cbk(void);
#define GPT_STOP_SEC_CODE
/* @violates @ref Gpt_PBcfg_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include' */
/* @violates @ref Gpt_PBcfg_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Short description of the violated MISRA rule (rule headline) */
#include "MemMap.h"
/** @} */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/* @violates @ref Gpt_PBcfg_C_REF_5 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Gpt_PBcfg_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include' */
/* @violates @ref Gpt_PBcfg_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Short description of the violated MISRA rule (rule headline) */
#include "MemMap.h"

STATIC CONST(Gpt_LLD_ChannelConfigType, GPT_CONST) Gpt_InitChannelPB_1[GPT_CHANNEL_NUM_1]=
{
    {
        (Gpt_ChannelType)(PIT_CH_1), /* GPT physical channel no. */
        (Gpt_ChannelType)(GPT_PIT_MODULE), /* hardware module ID */
        GPT_CH_MODE_CONTINUOUS, /* Timer mode:continous/one-shot */
        (uint8)0, /* not used*/
        (Gpt_PrescaleType)(0), /* Not used */
        (boolean)TRUE, /* Freeze Enable */
        (boolean)FALSE, /* Wakeup capability */
        &Wdg_Cbk_GptNotification0, /* Channel notification */
         (Gpt_WakeUpType) 0U, /* Wakeup information */ 
        (boolean)FALSE /*Enable/Disable Ecum Notification */
    },
    {
        (Gpt_ChannelType)(EMIOS_0_CH_3), /* GPT physical channel no. */
        (Gpt_ChannelType)(GPT_EMIOS_MODULE), /* hardware module ID */
        GPT_CH_MODE_CONTINUOUS, /* Timer mode:continous/one-shot */
        (uint8)0, /* not used*/
        (Gpt_PrescaleType)GPT_EMIOS_LLD_CH_PRES_1, /* EMIOS Clock divider */
        (boolean)TRUE, /* Freeze Enable */
        (boolean)FALSE, /* Wakeup capability */
        &GptChannelConfiguration_Dummy_Cbk, /* Channel notification */
         (Gpt_WakeUpType) 0U, /* Wakeup information */ 
        (boolean)FALSE /*Enable/Disable Ecum Notification */
    },
    {
        (Gpt_ChannelType)(STM_0_CH_0), /* GPT physical channel no. */
        (Gpt_ChannelType)(GPT_STM_MODULE), /* hardware module ID */
        GPT_CH_MODE_ONESHOT, /* Timer mode:continous/one-shot */
        (uint8)0, /* not used*/
        (Gpt_PrescaleType)(63U), /* STM Clock divider */
        (boolean)TRUE, /* Freeze Enable */
        (boolean)FALSE, /* Wakeup capability */
        NULL_PTR, /* Channel notification */
         (Gpt_WakeUpType) 0U, /* Wakeup information */ 
        (boolean)FALSE /*Enable/Disable Ecum Notification */
    },
    {
        (Gpt_ChannelType)(PIT_CH_3), /* GPT physical channel no. */
        (Gpt_ChannelType)(GPT_PIT_MODULE), /* hardware module ID */
        GPT_CH_MODE_ONESHOT, /* Timer mode:continous/one-shot */
        (uint8)0, /* not used*/
        (Gpt_PrescaleType)(0), /* Not used */
        (boolean)TRUE, /* Freeze Enable */
        (boolean)FALSE, /* Wakeup capability */
        &NvM_Call_NvM_BITP_MainFunction, /* Channel notification */
         (Gpt_WakeUpType) 0U, /* Wakeup information */ 
        (boolean)FALSE /*Enable/Disable Ecum Notification */
    },
    {
        (Gpt_ChannelType)(EMIOS_0_CH_4), /* GPT physical channel no. */
        (Gpt_ChannelType)(GPT_EMIOS_MODULE), /* hardware module ID */
        GPT_CH_MODE_ONESHOT, /* Timer mode:continous/one-shot */
        (uint8)0, /* not used*/
        (Gpt_PrescaleType)GPT_EMIOS_LLD_CH_PRES_1, /* EMIOS Clock divider */
        (boolean)TRUE, /* Freeze Enable */
        (boolean)FALSE, /* Wakeup capability */
        &GptChannelConfiguration_IoHwAbTest_Cbk, /* Channel notification */
         (Gpt_WakeUpType) 0U, /* Wakeup information */ 
        (boolean)FALSE /*Enable/Disable Ecum Notification */
    }

};
/* @violates @ref Gpt_PBcfg_C_REF_4 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
CONST(Gpt_ConfigType, GPT_CONST) GptChannelConfigSet =
{
    (uint8)GPT_CHANNEL_NUM_1,
    Gpt_InitChannelPB_1
};


/* @violates @ref Gpt_PBcfg_C_REF_5 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Gpt_PBcfg_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include' */
/* @violates @ref Gpt_PBcfg_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Short description of the violated MISRA rule (rule headline) */
#include "MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#endif  /* not GPT_PRECOMPILE_SUPPORT */

#ifdef __cplusplus
}
#endif

/** @} */
