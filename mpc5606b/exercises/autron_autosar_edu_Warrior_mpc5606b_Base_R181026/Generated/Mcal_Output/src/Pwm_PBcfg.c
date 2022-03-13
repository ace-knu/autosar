/**
*   @file    Pwm_PBcfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Pwm - Pwm post-build configuration file.
*   @details post-build configuration structure instances.
*
*   @addtogroup PWM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS200
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
extern "C" {
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_PBcfg_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* MemMap.h included after each section define in order to set the current memory section
*
* @section Pwm_PBcfg_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Pwm_PBcfg_C_REF_3
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Pwm_PBcfg_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Pwm_PBcfg_C_REF_5
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @{
* @file           Pwm_PBcfg.c
* @implements     DPWM03703
*/
#include "Pwm.h"
#include "Mcal.h"
#include "Pwm_Cfg.h"
/*
* @implements DPWM05001
*/
#include "Dem.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define PWM_PB_CFG_C_VENDOR_ID                      43
#define PWM_PB_CFG_C_MODULE_ID                      121

/*
* @violates @ref Pwm_PBcfg_C_REF_5 This is required as per autosar Requirement,
*/
#define PWM_PB_CFG_C_AR_RELEASE_MAJOR_VERSION       4
/*
* @violates @ref Pwm_PBcfg_C_REF_5 This is required as per autosar Requirement,
*/
#define PWM_PB_CFG_C_AR_RELEASE_MINOR_VERSION       0
/*
* @violates @ref Pwm_PBcfg_C_REF_5 This is required as per autosar Requirement,
*/
#define PWM_PB_CFG_C_AR_RELEASE_REVISION_VERSION    3
#define PWM_PB_CFG_C_SW_MAJOR_VERSION               1
#define PWM_PB_CFG_C_SW_MINOR_VERSION               0
#define PWM_PB_CFG_C_SW_PATCH_VERSION               1
/**@}*/
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

#if (PWM_PB_CFG_C_VENDOR_ID != PWM_VENDOR_ID)
    #error "Pwm_PBCfg.c and Pwm.h have different vendor ids"
#endif
#if ((PWM_PB_CFG_C_AR_RELEASE_MAJOR_VERSION != PWM_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_PB_CFG_C_AR_RELEASE_MINOR_VERSION != PWM_AR_RELEASE_MINOR_VERSION) || \
        (PWM_PB_CFG_C_AR_RELEASE_REVISION_VERSION != PWM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_PBCfg.c and Pwm.h are different"
#endif


#if ((PWM_PB_CFG_C_SW_MAJOR_VERSION != PWM_SW_MAJOR_VERSION) || \
        (PWM_PB_CFG_C_SW_MINOR_VERSION != PWM_SW_MINOR_VERSION) || \
        (PWM_PB_CFG_C_SW_PATCH_VERSION != PWM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_PBCfg.c and Pwm.h are different"
#endif


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

#if (PWM_PRECOMPILE_SUPPORT == STD_OFF)
/* put Pwm_InitChannel structure into specified section */
/*
* @violates @ref Pwm_PBcfg_C_REF_5 This is required as per autosar Requirement,
*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Pwm_PBcfg_C_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"

/**
* @brief Dem Event report ID
* @implements DPWM05001
*/
/* @violates @ref Pwm_PBcfg_C_REF_3 external ... could be made static
*/
CONST(Mcal_DemErrorType, PWM_CONST) Pwm_E_UnexpectedIrqCfg=
    {(uint32)STD_ON, (uint32)11U}; /* PWM_E_UNEXPECTED_IRQ parameters*/ 

/**
* @brief Prototype of User Notifications
* @implements DPWM02101
*/





/**
* @brief Number of configured Pwm channels
* @implements DPWM03304
*/


#define PWM_CONF_CHANNELS_PB_0  ((Pwm_ChannelType)2)



/**
* @brief   pwm channel high level configuration structure
* @details Defines the class of PWM channel
*          \n Pwm_ChannelClassValue - channel type: Variable/Fixed period
*          \n Pwm_Polarity - Pwm signal polarity:   High or low
*          \n Pwm_DefaultPeriodValue - Default value for period
*          \n Pwm_DefaultDutyCycleValue - Default value for duty cycle: [0-0x8000] (0-100%)
*          \n Pwm_IdleState - Pwm signal idle state: High or low
*          \n Pwm_Channel_Notification - Pointer to notification function
*          \n IpType - the IP used to implement this specific Pwm channel
*          \n SpecificCfg - Pwm channel IP specific parameters
*
* @implements DPWM03303
*/
/* @violates @ref Pwm_PBcfg_C_REF_3 external ... could be made static
*/
CONST(Pwm_ChannelConfigType, PWM_CONST) Pwm_Channels_PB_0[PWM_CONF_CHANNELS_PB_0] =
{
{
PWM_VARIABLE_PERIOD,/* channel type: Variable/Fixed period */
    PWM_HIGH,/* signal polarity */

(Pwm_PeriodType)0x2710, /* 10000 ticks - default period value */
(uint16)0x4000,/* default duty cycle value */
    PWM_LOW,/* signal idle state */
        NULL_PTR,
    PWM_EMIOS_CHANNEL, /* channel ip type */
    /* PWM eMIOS channel specific configuration structure */
    {{
             (Pwm_ChannelType)PwmChannel_0_EMIOS_0_CH_2,/* assigned eMIOS HW channel id */
    /*EMiOS  channel Addr*/

   (uint32)0xc3fa0000UL, /*EMiOS 0 Module Addr*/
           (uint32)0xc3fa0060UL, /*EMiOS 0 channel Addr*/
    (Pwm_EmiosCtrlParamType)(PWM_BUS_INTERNAL_COUNTER | PWM_MODE_OPWFMB  | PWM_PRES_1
 ),
(Pwm_PeriodType)0,/* leading edge of the PWM output pulse in OPWMB, OPWMT modes */

#ifdef PWM_FEATURE_OPWMT
    #if (PWM_FEATURE_OPWMT == STD_ON)
(Pwm_PeriodType)0,/* delay for generating the trigger event in OPWMT mode */
    #endif
#endif
    (boolean)FALSE,/* Pwm_Offset and Pwm_TriggerDelay adjusted during runtime */
    #ifdef PWM_FEATURE_OPWMCB
        #if (PWM_FEATURE_OPWMCB == STD_ON)
    (uint16)0/*deadtime parameter */
        #endif
    #endif
    }}
},/* end channel */
{
PWM_VARIABLE_PERIOD,/* channel type: Variable/Fixed period */
    PWM_HIGH,/* signal polarity */

(Pwm_PeriodType)0x2710, /* 10000 ticks - default period value */
(uint16)0x0000,/* default duty cycle value */
    PWM_LOW,/* signal idle state */
        NULL_PTR,
    PWM_EMIOS_CHANNEL, /* channel ip type */
    /* PWM eMIOS channel specific configuration structure */
    {{
             (Pwm_ChannelType)PwmChannel_EMIOS23_EMIOS_0_CH_23,/* assigned eMIOS HW channel id */
    /*EMiOS  channel Addr*/

   (uint32)0xc3fa0000UL, /*EMiOS 0 Module Addr*/
           (uint32)0xc3fa0300UL, /*EMiOS 0 channel Addr*/
    (Pwm_EmiosCtrlParamType)(PWM_BUS_INTERNAL_COUNTER | PWM_MODE_OPWFMB  | PWM_PRES_1
 ),
(Pwm_PeriodType)0,/* leading edge of the PWM output pulse in OPWMB, OPWMT modes */

#ifdef PWM_FEATURE_OPWMT
    #if (PWM_FEATURE_OPWMT == STD_ON)
(Pwm_PeriodType)0,/* delay for generating the trigger event in OPWMT mode */
    #endif
#endif
    (boolean)FALSE,/* Pwm_Offset and Pwm_TriggerDelay adjusted during runtime */
    #ifdef PWM_FEATURE_OPWMCB
        #if (PWM_FEATURE_OPWMCB == STD_ON)
    (uint16)0/*deadtime parameter */
        #endif
    #endif
    }}
}};

/**
* @brief   pwm high level configuration structure
* @details This is the type of data structure containing the initialization data for the PWM driver.
*          \n ChannelCount - number of configured channels
*          \n ChannelsPtr - pointer to the configured channels
*/
/* @violates @ref Pwm_PBcfg_C_REF_3 external ... could be made static
*/
CONST(Pwm_ConfigType, PWM_CONST) PwmChannelConfigSet_0 =
{
    PWM_CONF_CHANNELS_PB_0, /* number of configured PWM channels in the array */
    Pwm_Channels_PB_0       /* pointer to array of channes */
};


/* stop putting configuration structure into section PWM_STOP_CONFIG_DATA_UNSPECIFIED */
/*
* @violates @ref Pwm_PBcfg_C_REF_5 This is required as per autosar Requirement,
*/
#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Pwm_PBcfg_C_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
/*
* @violates @ref Pwm_PBcfg_C_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"


#endif  /* end #ifndef PWM_PRECOMPILE_SUPPORT*/

 /*==================================================================================================
                                        GLOBAL VARIABLES
 ==================================================================================================*/

 /*==================================================================================================
                                    LOCAL FUNCTION PROTOTYPES
 ==================================================================================================*/

 /*==================================================================================================
                                        LOCAL FUNCTIONS
 ==================================================================================================*/

 /*==================================================================================================
                                        GLOBAL FUNCTIONS
 ==================================================================================================*/


#ifdef __cplusplus
}
#endif
