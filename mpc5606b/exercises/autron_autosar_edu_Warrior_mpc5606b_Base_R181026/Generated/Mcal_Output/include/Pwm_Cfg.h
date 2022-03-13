
/**
*   @file    Pwm_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Pwm - Pwm configuration file.
*   @details API flags and structure declarations.
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

#ifndef PWM_CFG_H
#define PWM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_Cfg_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* MemMap.h included after each section define in order to set the current memory section
*
* @section Pwm_Cfg_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
*@section Pwm_Cfg_H_REF_3
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
*
*@section Pwm_Cfg_H_REF_4
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* This violation is due to large macro name. This is maintained for better readability.
*
*@section Pwm_Cfg_H_REF_5
* Violates MISRA 2004 Required Rule 8.7,
* Objects shall be defined at block scope if they are only accessed from within a single function.
*
*@section Pwm_Cfg_H_REF_6
* Violates MISRA 2004 Required Rule 19.4, This violation cannot be fixed since functions and variables
* cannot be declared and defined within braces.
* For example:
* #define var  (variable)
* int var;
* In the above scenario, the var is replaced with (variable) i.e. it will become int (variable);
* ->This is not the synctax for variable declaration.
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @{
* @file           Pwm_Cfg.h
* @implements     DPWM03702
* 
*/
#include "Mcal.h"


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define PWM_CFG_H_VENDOR_ID                         43
#define PWM_CFG_H_MODULE_ID                         121

 /*
* @violates @ref Pwm_Cfg_H_REF_3 This is required as per autosar Requirement, 
*/
#define PWM_CFG_H_AR_RELEASE_MAJOR_VERSION          4
 /*
* @violates @ref Pwm_Cfg_H_REF_3 This is required as per autosar Requirement, 
*/
#define PWM_CFG_H_AR_RELEASE_MINOR_VERSION          0
 /*
* @violates @ref Pwm_Cfg_H_REF_3 This is required as per autosar Requirement, 
*/
#define PWM_CFG_H_AR_RELEASE_REVISION_VERSION       3

#define PWM_CFG_H_SW_MAJOR_VERSION                  1
#define PWM_CFG_H_SW_MINOR_VERSION                  0
#define PWM_CFG_H_SW_PATCH_VERSION                  1
/**@}*/


/*==================================================================================================
                                       DEFINES AND MACROS

    Exception - the follwing macros/types are used in the included files and must be defined
                before the include in order to take effect
==================================================================================================*/
/**
* @brief   selects between 16bit or 24bit emios implementation
*/
#define PWM_EMIOS_16_BITS_VARIANT   (STD_ON)


/**
@brief   Switch to indicate that  atleast one channel is configured in OPWMT mode
@remarks PR-MCAL-3277
@implements DPWM03153
*/
#define PWM_FEATURE_OPWMT  (STD_OFF)

/**
@brief Switch to indicate that  atleast one channel is configured in OPWMCB mode
@remarks PR-MCAL-3278
@implements DPWM03151
*/
#define PWM_FEATURE_OPWMCB (STD_OFF)

/**
@brief   Switch to indicate that  atleast one channel is configured in DAOC mode
@remarks PR-MCAL-3273
@implements DPWM03155
*/
#define PWM_FEATURE_DAOC   (STD_OFF)


/**
@brief   Specifies if multiple pwm channel synchronization feature is available
@remarks PR-MCAL-3299
@implements DPWM03112
*/
#define MULTI_PWM_CHANNEL_SYNCH  (STD_OFF)

#ifdef PWM_EMIOS_16_BITS_VARIANT
 #if  (PWM_EMIOS_16_BITS_VARIANT == STD_ON)

    /* 16bit EMIOS */

/**
* @brief   channel period typedef
* @implements DPWM03110
*/
    typedef uint16 Pwm_PeriodType;

#ifdef PWM_FEATURE_DAOC
 #if  (PWM_FEATURE_DAOC == STD_ON)
    /**
     @brief
    */
    #define PWM_DAOC_COUNTER    ((uint16)0xFFFF)

 #endif
#endif
 #else

    /* 24bit EMIOS */

/**
* @brief   channel period typedef
* @implements DPWM03110
*/
    typedef uint32 Pwm_PeriodType;

#ifdef PWM_FEATURE_DAOC
 #if  (PWM_FEATURE_DAOC == STD_ON)
    /**
     @brief
    */
    #define PWM_DAOC_COUNTER    ((uint32)0x00FFFFFF)
 #endif
#endif
 #endif

#else

 #error "Unknown EMIOS type, PWM_EMIOS_16_BITS_VARIANT is undefined";

#endif

/**
* @brief   Switch to indicate that Pwm_SetClockMode API is supported
* @implements DPWM03115
*/
#define PWM_DUAL_CLOCK_MODE    (STD_OFF)


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pwm_eMIOS_LLD_CfgEx.h"
#include "Reg_eSys_eMIOS_CfgEx.h"

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and PWM configuration header file are of the same vendor */
#if (PWM_CFG_H_VENDOR_ID != PWM_EMIOS_LLD_CFGEX_H_VENDOR_ID)
    #error "Pwm_Cfg.h and Pwm_eMIOS_LLD_CfgEx.h have different vendor ids"
#endif


/* Check if source file and PWM configuration header file are of the same Autosar version */
#if ((PWM_CFG_H_AR_RELEASE_MAJOR_VERSION != PWM_EMIOS_LLD_CFGEX_H_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_CFG_H_AR_RELEASE_MINOR_VERSION != PWM_EMIOS_LLD_CFGEX_H_AR_RELEASE_MINOR_VERSION) || \
        (PWM_CFG_H_AR_RELEASE_REVISION_VERSION != PWM_EMIOS_LLD_CFGEX_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Cfg.h and Pwm_eMIOS_LLD_CfgEx.h are different"
#endif

/* Check if source file and PWM configuration header file are of the same software version */
#if ((PWM_CFG_H_SW_MAJOR_VERSION != PWM_EMIOS_LLD_CFGEX_H_SW_MAJOR_VERSION) || \
        (PWM_CFG_H_SW_MINOR_VERSION != PWM_EMIOS_LLD_CFGEX_H_SW_MINOR_VERSION)  || \
        (PWM_CFG_H_SW_PATCH_VERSION != PWM_EMIOS_LLD_CFGEX_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Cfg.h and Pwm_eMIOS_LLD_CfgEx.h are different"
#endif


/* Check if source file and EMIOS configuration header file are of the same vendor */
#if (PWM_CFG_H_VENDOR_ID != REG_ESYS_EMIOS_CFGEX_H_VENDOR_ID)
    #error "Pwm_Cfg.h and Reg_eSys_EMIOS_CfgEx.h have different vendor ids"
#endif

/* Check if source file and PWM configuration header file are of the same Autosar version */
#if ((PWM_CFG_H_AR_RELEASE_MAJOR_VERSION != REG_ESYS_EMIOS_CFGEX_H_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_CFG_H_AR_RELEASE_MINOR_VERSION != REG_ESYS_EMIOS_CFGEX_H_AR_RELEASE_MINOR_VERSION) || \
        (PWM_CFG_H_AR_RELEASE_REVISION_VERSION != REG_ESYS_EMIOS_CFGEX_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Cfg.h and Pwm_Reg_eSys_eMIOS_CfgEx.h are different"
#endif

/* Check if source file and PWM configuration header file are of the same software version */
#if ((PWM_CFG_H_SW_MAJOR_VERSION != REG_ESYS_EMIOS_CFGEX_H_SW_MAJOR_VERSION) || \
        (PWM_CFG_H_SW_MINOR_VERSION != REG_ESYS_EMIOS_CFGEX_H_SW_MINOR_VERSION)  || \
        (PWM_CFG_H_SW_PATCH_VERSION != REG_ESYS_EMIOS_CFGEX_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Cfg.h and Reg_eSys_EMIOS_CfgEx.h are different"
#endif


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       PLATFORM SPECIFIC DEFINES AND MACROS
==================================================================================================*/


/* Platform specific DET errors */

/**
@* brief   generated when the configured offset for the OPWMB channel is >= than the period of the associated MCB channel
*
* @implements DPWM03121
*/
#define PWM_E_CHANNEL_OFFSET_VALUE   0x1AU


/**
* @brief   generated when the requested offset value plus the current requested dutycycle leads to
*          programming event B over the Period value leading to unexpected behavior of the pwm signal
*
* @implements DPWM03120
*/
 /*
* @violates @ref Pwm_Cfg_H_REF_3 This is required as per autosar Requirement, 
*/
#define PWM_E_OPWMB_CHANNEL_OFFSET_DUTYCYCLE_RANGE     0x1BU

/**
 @brief   generated when the configured trigger value for the OPWMTchannel is >= than the period of the channel
@remarks Covers
*/
 /*
* @violates @ref Pwm_Cfg_H_REF_3 This is required as per autosar Requirement, 
*/
#define PWM_E_OPWMT_CHANNEL_TRIGGER_RANGE 0x1CU
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/**
* @brief   Switch to indicate that Pwm_DeInit API is supported
*
* @implements DPWM03116
*/
#define PWM_DE_INIT_API             (STD_OFF)


/**
* @brief   Switch to indicate that Pwm_GetOutputState API is supported
* @implements DPWM03126
*/
#define PWM_GET_OUTPUT_STATE_API    (STD_ON)


/**
* @brief   Switch to indicate that Pwm_SetDutyCycle API is supported
* @implements DPWM03131
*/
#define PWM_SET_DUTY_CYCLE_API      (STD_ON)


/**
* @brief   Switch to indicate that Pwm_SetOutputToIdle API is supported
* @implements DPWM03132
*/
#define PWM_SET_OUTPUT_TO_IDLE_API  (STD_ON)


/**
* @brief   Switch to indicate that Pwm_SetPeriodAndDuty API is supported
* @implements DPWM03133
*/
#define PWM_SET_PERIOD_AND_DUTY_API (STD_ON)


/**
* @brief   Switch to indicate that Pwm_GetVersionInfo API is supported
* @implements DPWM03140
*/
#define PWM_VERSION_INFO_API         (STD_OFF)


/**
* @brief   Switch to indicate that Pwm_SetCounterBus API is supported
* @implements DPWM03135
*/
#define PWM_SETCOUNTERBUS_API         (STD_OFF)


/**
* @brief   Switch to indicate that Pwm_SetChannelOutput API is supported
* @implements DPWM03134
*/
#define PWM_SETCHANNELOUTPUT_API         (STD_OFF)


/**
* @brief   Switch for enabling the development error detection.
* @implements DPWM03117
*/
#define PWM_DEV_ERROR_DETECT (STD_ON)


/**
* @brief   Switch to indicate that register A is updated at dutycycle change for OPWMT mode
* @implements DPWM03115
*/
#define PWM_CHANGE_REGISTER_A_SWITCH    (STD_OFF)


/**
* @brief   Switch for enabling the update of the duty cycle parameter at the end of the current period
* @implements DPWM03119
*/
#define PWM_DUTYCYCLE_UPDATED_ENDPERIOD   (STD_ON)

/**
* @brief   Switch to indicate that the notifications are supported
* @implements DPWM03129
*/
#define PWM_NOTIFICATION_SUPPORTED        (STD_OFF)
/**
@brief   Switch to indicate that Pwm_SetChannelOutput API is supported
@implements DPWM03156
*/
#define PWM_SET_TRIGGER_DELAY_API         (STD_OFF)

/**
* @brief   Switch to indicate that Dem_ReportErrorStatus API is supported
* @implements DPWM03154
*/
 /*
* @violates @ref Pwm_Cfg_H_REF_3 This is required as per autosar Requirement, 
*/
#define PWM_DISABLE_DEM_REPORT_ERROR_STATUS   (STD_ON)

/**
* @brief   Switch for enabling the update of the period parameter at the end of the current period
* @implements DPWM03118
*/
 /*
* @violates @ref Pwm_Cfg_H_REF_3 This is required as per autosar Requirement, 
*/
#define PWM_DUTY_PERIOD_UPDATED_ENDPERIOD (STD_ON)

/**
* @brief   Switch to indicate that Pwm_GetChannelState API is supported
* @implements DPWM03152
*/
#define PWM_GET_CHANNEL_STATE    (STD_OFF)

/**
* @brief   Specifies the InstanceId of this module instance.
*          If only one instance is present it shall have the Id 0.
*          Not used in the current implementation
* @implements DPWM03127
*/
#define PWM_INDEX    (0U)

/**
* @brief   Specific the max channels of one config set in all config sets.
*/
#define PWM_MAX_CHANNELS  (2U)


#define PWM_PRECOMPILE_SUPPORT (STD_OFF)

/** @brief Symbolic Names for configured channels */

/* @violates @ref Pwm_Cfg_H_REF_3 The long identifiers are maintained for better readability. */
/* @violates @ref Pwm_Cfg_H_REF_4 Identifier clash. */
#define PwmConf_PwmChannel_PwmChannel_0         ((Pwm_ChannelType)0)

/* @violates @ref Pwm_Cfg_H_REF_3 The long identifiers are maintained for better readability. */
/* @violates @ref Pwm_Cfg_H_REF_4 Identifier clash. */
#define PwmConf_PwmChannel_PwmChannel_EMIOS23         ((Pwm_ChannelType)1)




#define PwmChannel_0_EMIOS_0_CH_2    ((Pwm_ChannelType)EMIOS_0_CH_2)

#define PwmChannel_EMIOS23_EMIOS_0_CH_23    ((Pwm_ChannelType)EMIOS_0_CH_23)

/**@}*/

/**
    @brief ISRs configured for Pwm channels
    @details Macros for Pwm channels used in ISR
    @remarks Covers PWM115
@{
*/

    /* EMIOS ISR enable macros not generated because PwmNotificationSupported was not checked - notfications not supported in this configuration */

/**@}*/


/**
* @brief emios modules available on this platform
* @implements DPWM03125
*/
#define PWM_EMIOS_MODULES_CFG        (2UL)
/**
* @brief emios channels available on EMIOS 0
* @implements DPWM03123
*/
#define PWM_EMIOS_A_HW_CHANNELS_CFG  (32UL)


/**
* @brief This constant specifies the total number of eMIOS channels It's used to reserve global ram variables used for each individual pwm channel
* @implements DPWM03125
*/

#if (PWM_EMIOS_MODULES_CFG == 1UL)

#define PWM_EMIOS_HW_CHANNELS    (PWM_EMIOS_A_HW_CHANNELS_CFG)

#else

#define PWM_EMIOS_HW_CHANNELS    (PWM_EMIOS_MODULES_CFG * 32U)

#endif



/**
* @brief        Output state of a PWM channel
* @details      PWM_HIGH - The output state of PWM channel is HIGH
*               PWM_LOW - The output state of PWM channel LOW
* @implements DPWM03109
*/
typedef enum
{
    PWM_LOW = 0,
    PWM_HIGH
} Pwm_OutputStateType;

/**
* @brief    Definition of the type of edge notification of a PWM channel
* @details  PWM_RISING_EDGE - Notification will be called when a rising edge occurs on the PWM output signal.
*           PWM_FALLING_EDGE - Notification will be called when a falling edge occurs on the PWM output signal.
*           PWM_BOTH_EDGES - Notification will be called when either a rising edge or falling edge occur on the PWM output signal.
* @implements DPWM03105
*/
typedef enum
{
    PWM_RISING_EDGE = 0,
    PWM_FALLING_EDGE,
    PWM_BOTH_EDGES
} Pwm_EdgeNotificationType;

/**
* @brief    Defines class of PWM channel
* @details  PWM_VARIABLE_PERIOD - The PWM channel has a variable period. The duty cycle and the period can be changed.
*           PWM_FIXED_PERIOD - The PWM channel has a fixed period. Only the duty cycle can be changed.
*           PWM_FIXED_PERIOD_SHIFTED - The PWM channel has a fixed shifted period. Impossible to change it ( only if supported by hardware)
* @implements DPWM03101
*/
typedef enum
{
    PWM_VARIABLE_PERIOD = 0,
    PWM_FIXED_PERIOD,
    PWM_FIXED_PERIOD_SHIFTED
} Pwm_ChannelClassType;

#if (PWM_SETCHANNELOUTPUT_API == STD_ON)
/**
* @brief    Defines state of PWM channel
* @details  PWM_ACTIVE - The PWM pin will be in the same state of configured polarity
*           PWM_INACTIVE - The PWM pin will be in the opposite state of configured polarity
* @implements DPWM03111
*/
typedef enum
{
    PWM_ACTIVE = 0,
    PWM_INACTIVE
} Pwm_StateType;
#endif

/**
* @brief   IP used to implement this channel
* @details This channel is implemented using one eMIOS HW unified channel
* @implements DPWM03106
*/
typedef enum
{
    PWM_EMIOS_CHANNEL = 0
} Pwm_IpType;


/*==================================================================================================
                              STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief   channel id typedef, used as type for both logical and hw channel ids.
* @implements DPWM03103
*/
typedef uint8 Pwm_ChannelType;



/**
* @brief   channel notification typedef
* @implements DPWM03108
*/
typedef void (*Pwm_NotifyType)(void);

#if (PWM_GET_CHANNEL_STATE == STD_ON)
/**
* @brief   Channel duty typedef
* implements DPWM03153
*/
typedef uint16 Pwm_DutyType;
#endif

/**
* @brief Low level channel configuration structure
* @details Pwm channel eMIOS specific configuration structure
* @implements DPWM03107
*/
typedef struct
{
    CONST(Pwm_EMIOS_ChannelConfigType, PWM_CONST)  EmiosCfg; /* @brief Pwm channel eMIOS specific configuration structure */

} Pwm_LLD_ChannelConfigType;

/**
* @brief Prescaler type
* @implements DPWM03150
*/
#if (PWM_DUAL_CLOCK_MODE == STD_ON)
typedef enum
    {
        PWM_NORMAL = 0,
        PWM_ALTERNATE
    } Pwm_SelectPrescalerType;
#endif


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
* @implements DPWM03102
*/
typedef struct {

    /* PWM generic parameters, IP independent */
    CONST(Pwm_ChannelClassType, PWM_CONST)       Pwm_ChannelClassValue; /* @brief channel type: Variable/Fixed period */
    CONST(Pwm_OutputStateType,  PWM_CONST)       Pwm_Polarity; /* @brief Pwm signal polarity:   High or low  */
    CONST(Pwm_PeriodType,       PWM_CONST)       Pwm_DefaultPeriodValue; /* @brief Default value for period */
    CONST(uint16,               PWM_CONST)       Pwm_DefaultDutyCycleValue; /* @brief Default value for duty cycle: [0-0x8000] (0-100%)*/
    CONST(Pwm_OutputStateType,  PWM_CONST)       Pwm_IdleState; /* @brief Pwm signal idle state: High or low */
    CONST(Pwm_NotifyType,       PWM_CONST)       Pwm_Channel_Notification; /* @brief Pointer to notification function   */
    CONST(Pwm_IpType,           PWM_CONST)       IpType; /* @brief the IP used to implement this specific Pwm channel */

    /* IP specific parameters */
    CONST(Pwm_LLD_ChannelConfigType, PWM_CONST)  SpecificCfg; /* @brief Pwm channel IP specific parameters */
} Pwm_ChannelConfigType;

/**
* @brief   pwm high level configuration structure
* @details This is the type of data structure containing the initialization data for the PWM driver.
*          \n ChannelCount - number of configured channels
*          \n ChannelsPtr - pointer to the configured channels
* @implements DPWM03104
*/
typedef struct {

    CONST(Pwm_ChannelType,       PWM_CONST)   ChannelCount; /* @brief number of configured channels */
    CONST(Pwm_ChannelConfigType, PWM_CONST)  *ChannelsPtr; /* @brief pointer to the configured channels */
} Pwm_ConfigType;


 /*==================================================================================================
                                  GLOBAL VARIABLE DECLARATIONS
 ==================================================================================================*/
 /*
* @violates @ref Pwm_Cfg_H_REF_3 This is required as per autosar Requirement, 
*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* @brief reference for PWM_E_UNEXPECTED_IRQ */

/* @violates @ref Pwm_Cfg_H_REF_5 the define cannot be moved inside the block scope */
extern CONST(Mcal_DemErrorType, PWM_CONST) Pwm_E_UnexpectedIrqCfg;



/* @brief declaration of config sets for PB configuration */
#if (PWM_PRECOMPILE_SUPPORT == STD_OFF )

/* @violates @ref Pwm_Cfg_H_REF_6 C macros shall only expand to a braced, a constant, a parenthesised */
#define PWM_INIT_CONFIG_PB_DEFINES \


extern CONST(Pwm_ConfigType, PWM_CONST) PwmChannelConfigSet_0;




#endif /* PWM_PRECOMPILE_SUPPORT */

/*
* @violates @ref Pwm_Cfg_H_REF_3 This is required as per autosar Requirement, 
*/
#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Pwm_Cfg_H_REF_1 Only preprocessor statements and comments before "#include"
*/
/*
* @violates @ref Pwm_Cfg_H_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"
/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif    /*PWM_CFG_H*/



