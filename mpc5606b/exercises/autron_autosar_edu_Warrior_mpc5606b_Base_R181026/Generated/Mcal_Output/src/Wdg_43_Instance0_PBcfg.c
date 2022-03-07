/**
*   @file    Wdg_43_Instance0_PBcfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Wdg - contains the data exported by the watchodg module
*   @details Contains the information that will be exported by the module, as requested by Autosar.
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Wdg_43_Instance0_PBcfg_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the contents 
* of a header file being included twice.
* Required by the Autosar specification.Needed for different code sections definition.
*
* @section Wdg_43_Instance0_PBcfg_c_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 
* character significance and case sensitivity are supported for external identifiers.
* define name is required by the AUTOSAR specifications although it exceedes the max length of 31 characters.
*
* @section Wdg_43_Instance0_PBcfg_c_REF_3
* Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope
* If a variable to be used within a Function in the same file use Static.Similarly if a function is called 
* from elsewhere within the same file use Static.
*
* @section Wdg_43_Instance0_PBcfg_c_REF_4
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded by 
* other preprocessor directives or comments.
* This mechanism is used to properly place code and variables into their sections.
*
* @section Wdg_43_Instance0_PBcfg_c_REF_5
* Violates MISRA 2004 Required Rule 16.9, function identifier used without '&' or parenthisized parameter list: 'Callback'
*
* @section Wdg_43_Instance0_PBcfg_c_REF_6
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Wdg_Channel.h"
#if(WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/*
* @violates @ref Wdg_43_Instance0_PBcfg_c_REF_1 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order 
* to prevent the contents of a header file being included twice.
*/
#include "Dem.h"
#endif
#if (WDG_TYPE == WDG_INTERNAL_MODULE)
    #include "Reg_eSys_Swt.h"
#endif
#if (WDG_INSTANCE0 == STD_ON)



/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_VENDOR_ID_PBCFG_C                    43
/* @violates @ref Wdg_43_Instance0_PBcfg_c_REF_6 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_AR_RELEASE_MAJOR_VERSION_PBCFG_C     4
/* @violates @ref Wdg_43_Instance0_PBcfg_c_REF_6 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_AR_RELEASE_MINOR_VERSION_PBCFG_C     0
/*
* @violates @ref Wdg_43_Instance0_PBcfg_c_REF_2 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to 
* ensure that 31 character significance and case sensitivity are supported for external identifiers.
*/
/* @violates @ref Wdg_43_Instance0_PBcfg_c_REF_6 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_AR_RELEASE_REVISION_VERSION_PBCFG_C  3
#define WDG_SW_MAJOR_VERSION_PBCFG_C             1
#define WDG_SW_MINOR_VERSION_PBCFG_C             0
#define WDG_SW_PATCH_VERSION_PBCFG_C             1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if(WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
    /* Check if source file and Dem header file are of the same Autosar version */
    #if (( WDG_AR_RELEASE_MAJOR_VERSION_PBCFG_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         ( WDG_AR_RELEASE_MINOR_VERSION_PBCFG_C != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wdg_43_Instance0_PBcfg.c and Dem.h are different"
    #endif
    #endif
#endif

/* Check if current file and Wdg header file are of the same vendor */
#if (WDG_VENDOR_ID_PBCFG_C != WDG_CHANNEL_VENDOR_ID)
    #error "Wdg_43_Instance0_PBcfg.c and Wdg_Channel.h have different vendor ids"
#endif

/* Check if source file and Wdg header file are of the same Autosar version */
#if ((WDG_AR_RELEASE_MAJOR_VERSION_PBCFG_C != WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_AR_RELEASE_MINOR_VERSION_PBCFG_C != WDG_CHANNEL_AR_RELEASE_MINOR_VERSION) || \
     (WDG_AR_RELEASE_REVISION_VERSION_PBCFG_C != WDG_CHANNEL_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_43_Instance0_PBcfg.c and Wdg_Channel.h are different"
#endif
/* Check if source file and Wdg header file are of the same Software version */
#if ((WDG_SW_MAJOR_VERSION_PBCFG_C != WDG_CHANNEL_SW_MAJOR_VERSION) || \
     (WDG_SW_MINOR_VERSION_PBCFG_C != WDG_CHANNEL_SW_MINOR_VERSION) || \
     (WDG_SW_PATCH_VERSION_PBCFG_C != WDG_CHANNEL_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wdg_43_Instance0_PBcfg.c and Wdg_Channel.h are different"
#endif

#if (WDG_TYPE == WDG_INTERNAL_MODULE)
    /* Check if source file and Reg_eSys_Swt header file are of the same vendor */
    #if (WDG_VENDOR_ID_PBCFG_C != REG_ESYS_SWT_VENDOR_ID)
        #error "Wdg_43_Instance0_PBcfg.c and Reg_eSys_Swt.h have different vendor ids"
    #endif
    
    /* Check if source file and Reg_eSys_Swt header file are of the same Autosar version */
    #if ((WDG_AR_RELEASE_MAJOR_VERSION_PBCFG_C != REG_ESYS_SWT_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_AR_RELEASE_MINOR_VERSION_PBCFG_C != REG_ESYS_SWT_AR_RELEASE_MINOR_VERSION) || \
         (WDG_AR_RELEASE_REVISION_VERSION_PBCFG_C != REG_ESYS_SWT_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of Wdg_43_Instance0_PBcfg.c and Reg_eSys_Swt.h are different"
    #endif
    
    /* Check if source file and Reg_eSys_Swt header file are of the same Software version */
    #if ((WDG_SW_MAJOR_VERSION_PBCFG_C != REG_ESYS_SWT_SW_MAJOR_VERSION) || \
         (WDG_SW_MINOR_VERSION_PBCFG_C != REG_ESYS_SWT_SW_MINOR_VERSION) || \
         (WDG_SW_PATCH_VERSION_PBCFG_C != REG_ESYS_SWT_SW_PATCH_VERSION))
        #error "Software Version Numbers of Wdg_43_Instance0_PBcfg.c and Reg_eSys_Swt.h are different"
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
/* @violates @ref Wdg_43_Instance0_PBcfg_c_REF_6 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Wdg_43_Instance0_PBcfg_c_REF_1 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order 
* to prevent the contents of a header file being included twice.
*/
#include "MemMap.h"


#if (WDG_POSTBUILD_SUPPORT == STD_ON)


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/


/**
 *   @brief External Notifications for Wdg Interrupt
 */

extern FUNC (void, WDG_CODE) RE_Wdg_Cbk(void);



/**
 * @brief  This constant contains the configuration set for the post build time
*/


/*
* @violates @ref Wdg_43_Instance0_PBcfg_c_REF_3 MISRA 2004 Required Rule 8.10, Declarations and definitions 
* of Objects or Functions at File scope
*/
CONST(Wdg_ConfigType, WDG_CONST) WdgSettingsConfig =
{
    {
       /* OFF Mode */
       {
           ( SWT_WDG_DISABLED | SWT_WDG_NO_HARD_LOCK| SWT_WDG_NO_SOFT_LOCK),
           0x00000000UL,    /* Time-out config */
           0x00000000UL,    /* Window config */
           0UL,             /* Time-out config in usec */
           0UL              /* Window config in usec */
       },
       /* SLOW Mode */
       {
           ( SWT_WDG_ENABLED |SWT_WDG_NO_HARD_LOCK | SWT_WDG_NO_SOFT_LOCK |     SWT_TRIGGER_MODE_REGULAR |     SWT_FIXED_SERVICE_SEQ |     SWT_WDG_RUN_IN_HALT |     SWT_WDG_STOP_IN_DEBUG |     SWT_WDG_OSCILLATOR |          SWT_RESET_ON_TIMEOUT |          SWT_INVALID_ACCESS_GEN_SYSTEM_RESET      ), /* WDG Control and configuration */
           0x00003200UL,       /* Time-out config */
           0x00003200UL,        /* Window config */
           100000UL,                        /* Time-out config in usec */
           100000UL                          /* Window config in usec */
       },
       /* FAST Mode */
       {
           ( SWT_WDG_ENABLED| SWT_WDG_NO_HARD_LOCK | SWT_WDG_NO_SOFT_LOCK |     SWT_TRIGGER_MODE_REGULAR |     SWT_FIXED_SERVICE_SEQ |     SWT_WDG_STOP_IN_HALT |     SWT_WDG_STOP_IN_DEBUG |     SWT_WDG_OSCILLATOR |          SWT_RESET_ON_TIMEOUT |          SWT_INVALID_ACCESS_GEN_SYSTEM_RESET      ), /* WDG Control and configuration */
           0x00000a00UL,       /* Time-out config */
           0x00000a00UL,        /* Window config */
           20000UL,                        /* Time-out config in usec */
           20000UL                          /* Window config in usec */
        }
    },
    WDG_IPW_INSTANCE0,
    WDGIF_SLOW_MODE, 
    WDG_FIXED_SERVICE,
    (Wdg_ServiceKeyWidthType)0,
/*
* @violates @ref Wdg_43_Instance0_PBcfg_c_REF_5 MISRA 2004 Required Rule 16.9, function identifier used without '&' or parenthisized parameter list: 'Callback' 
*/    
    RE_Wdg_Cbk, /* WdgCallbackNotification0 */
    (Gpt_ChannelType)GptConf_GptChannelConfiguration_GptChannelConfiguration_Wdg,
    (uint32)64
};



#endif
/* @violates @ref Wdg_43_Instance0_PBcfg_c_REF_6 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Wdg_43_Instance0_PBcfg_c_REF_1 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order 
* to prevent the contents of a header file being included twice.
*
* @violates @ref Wdg_43_Instance0_PBcfg_c_REF_4 MISRA 2004 Advisory Rule 19.1, #include statements in a file should only 
* be preceded by other preprocessor directives or comments. 
*
*/

#include "MemMap.h"


/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

#endif /* #if WDG_INSTANCE_43_Instance0 == STD_ON*/
#ifdef __cplusplus
}
#endif

/** @} */
