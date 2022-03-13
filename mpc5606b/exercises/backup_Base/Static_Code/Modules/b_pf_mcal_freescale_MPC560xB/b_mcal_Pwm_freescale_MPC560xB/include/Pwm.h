/**
*   @file    Pwm.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Pwm - Pwm module API header.
*   @details Pwm module API header.
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

#ifndef PWM_H
#define PWM_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_H_REF_1
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
*
* @section Pwm_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Pwm_H_REF_3
* Violates MISRA 2004 Required Rule 8.7,
* Objects shall be defined at block scope if they are only accessed from within a single function.
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
/*
* @file           Pwm.h
* @implements     DPWM02202
*/
/*
* @violates @ref Pwm_H_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Std_Types.h"
#include "Pwm_Cfg.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Pwm.h
* @implements     DPWM02001, DPWM02002, DPWM02003, DPWM02024, DPWM02025, DPWM02026, DPWM02027
*/
#define PWM_VENDOR_ID                       43
#define PWM_MODULE_ID                       121
#define PWM_AR_RELEASE_MAJOR_VERSION        4
#define PWM_AR_RELEASE_MINOR_VERSION        0
#define PWM_AR_RELEASE_REVISION_VERSION     3
#define PWM_SW_MAJOR_VERSION                1
#define PWM_SW_MINOR_VERSION                0
#define PWM_SW_PATCH_VERSION                1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Std_Types.h are of the same Autosar version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Pwm.h and Std_Types.h are different"
#endif
#endif


/* Check if source file and PWM configuration header file are of the same vendor */
#if (PWM_VENDOR_ID != PWM_CFG_H_VENDOR_ID)
    #error "Pwm.h and Pwm_Cfg.h have different vendor ids"
#endif
/* Check if source file and PWM configuration header file are of the same Autosar version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION != PWM_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_AR_RELEASE_MINOR_VERSION != PWM_CFG_H_AR_RELEASE_MINOR_VERSION) || \
        (PWM_AR_RELEASE_REVISION_VERSION != PWM_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm.h and Pwm_Cfg.h are different"
#endif
/* Check if source file and PWM configuration header file are of the same software version */
#if ((PWM_SW_MAJOR_VERSION != PWM_CFG_H_SW_MAJOR_VERSION) || \
        (PWM_SW_MINOR_VERSION != PWM_CFG_H_SW_MINOR_VERSION) || \
        (PWM_SW_PATCH_VERSION != PWM_CFG_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm.h and Pwm_Cfg.h are different"
#endif


/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/**
* @brief            100% dutycycle
* @details          Errors and exceptions that will be detected by the PWM driver generated when
*                   Pwm_SetDutyCycle or Pwm_SetPeriodAndDuty are called with a value for dutycyle
*                   out of valid range [0x0000, 0x8000]
* @implements       DPWM02006
*/
#define PWM_DUTY_CYCLE_100 ((uint16)0x8000U)

/**
* @brief            API Pwm_Init service called with wrong parameter
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       DPWM02010
*/
#define PWM_E_PARAM_CONFIG         0x10U

/**
* @brief            API service used without module initialization
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       DPWM02015
*/
#define PWM_E_UNINIT               0x11U

/**
* @brief            API service used with an invalid channel Identifier
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       DPWM02009
*/
#define PWM_E_PARAM_CHANNEL        0x12U

/**
* @brief            Usage of unauthorized PWM service on PWM channel configured a fixed period
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       DPWM02014
*/
#define PWM_E_PERIOD_UNCHANGEABLE  0x13U

/**
* @brief            API Pwm_Init service called while the PWM driver has already been initialised
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       DPWM02007
*/
#define PWM_E_ALREADY_INITIALIZED  0x14U

/**
* @brief            Invalid polarity selected for edge notification
* @details          Will be generated when an invalid polarity, edge notification is requested for one pwm channel.
*                   Due to the limitations that are present in the eMIOS implementation not all
*                   the polarity notifications combinations can be supported.
* @implements       DPWM02011
*/
#define PWM_E_PARAM_NOTIFICATION   0x18U

/**
* @brief            NULL function is configured as notification callback
* @details          Will be generated when a NULL function is configured as notification callback for
*                   one pwm channel and Pwm_EnableNotification is called for that channel
* @implements       DPWM02012
*/
#define PWM_E_PARAM_NOTIFICATION_NULL  0x16U

/**
* @brief            Pwm_SetDutyCycle or Pwm_SetPeriodAndDuty called with invalid dutycycle range
* @details          Generated when Pwm_SetDutyCycle or Pwm_SetPeriodAndDuty are called with a value
*                   for dutycyle out of valid range [0x0000, 0x8000]
* @implements       DPWM02008
*/
#define PWM_E_DUTYCYCLE_RANGE          0x17U

/**
* @brief            Generated when a NULL pointer is passed to Pwm_GetVersionInfo function
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       DPWM02013
*/
#define PWM_E_PARAM_POINTER            0x15U



/**
* @brief            API service ID of Pwm_Init function
* @details          Parameters used when raising an error/exception
* @implements       DPWM02019
*/
#define PWM_INIT_ID                0x00U

/**
* @brief            API service ID of Pwm_DeInit function
* @details          Parameters used when raising an error/exception
* @implements       DPWM02004
*/
#define PWM_DEINIT_ID              0x01U

/**
* @brief            API service ID of Pwm_SetDutyCycle function
* @details          Parameters used when raising an error/exception
* @implements       DPWM02021
*/
#define PWM_SETDUTYCYCLE_ID        0x02U

/**
* @brief            API service ID of Pwm_SetPeriodAndDuty function
* @details          Parameters used when raising an error/exception
* @implements       DPWM02023
*/
#define PWM_SETPERIODANDDUTY_ID    0x03U

/**
* @brief            API service ID of Pwm_SetOutputToIdle function
* @details          Parameters used when raising an error/exception
* @implements       DPWM02022
*/
#define PWM_SETOUTPUTTOIDLE_ID     0x04U

/**
* @brief            API service ID of Pwm_GetOutputState function
* @details          Parameters used when raising an error/exception
* @implements       DPWM02017
*/
#define PWM_GETOUTPUTSTATE_ID      0x05U

/**
* @brief            API service ID of Pwm_DisableNotification function
* @details          Parameters used when raising an error/exception
* @implements       DPWM02005
*/
#define PWM_DISABLENOTIFICATION_ID 0x06U

/**
* @brief            API service ID of Pwm_EnableNotification function
* @details          Parameters used when raising an error/exception
* @implements       DPWM02016
*/
#define PWM_ENABLENOTIFICATION_ID  0x07U

/**
* @brief            API service ID of Pwm_GetVersionInfo function
* @details          Parameters used when raising an error/exception
* @implements       DPWM02018
*/
#define PWM_GETVERSIONINFO_ID      0x08U

/**
* @brief            API service ID of Pwm_Schm_ProtectResource function
* @details          Parameters used when raising an error/exception
* @implements       
*/
#define PWM_SCHM_PROTECTRESOURCE_ID   0x09U

/**
* @brief            API service ID of Pwm_Schm_UnprotectResource function
* @details          Parameters used when raising an error/exception
* @implements       
*/
#define PWM_SCHM_UNPROTECTRESOURCE_ID   0x0AU


/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/*===============================================================================================
*                            STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*
* @violates @ref Pwm_H_REF_1 This is required as per autosar Requirement, 
*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Pwm_H_REF_2 Precautions shall be taken in order to prevent the contents of a 
* header file being included twice 
*/
#include "MemMap.h"


#if (PWM_PRECOMPILE_SUPPORT != STD_ON)
/* @violates @ref Pwm_H_REF_3 the define cannot be moved inside the block scope because it must be visible from other layers */
PWM_INIT_CONFIG_PB_DEFINES
#endif

#if ( PWM_PRECOMPILE_SUPPORT == STD_ON)
/* @violates @ref Pwm_H_REF_3 the define cannot be moved inside the block scope because it must be visible from other layers */
PWM_INIT_CONFIG_PC_DEFINE
#endif

/*
* @violates @ref Pwm_H_REF_1 This is required as per autosar Requirement, 
*/
#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Pwm_H_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"

/*===============================================================================================
                                     FUNCTION PROTOTYPES
===============================================================================================*/

/*
* @violates @ref Pwm_H_REF_1 only preprocessor statements and comments before "#include"
*/
#define PWM_START_SEC_CODE
/*
* @violates @ref Pwm_H_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"

FUNC (void, PWM_CODE) Pwm_Init(
        P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr
    );

#if (PWM_DE_INIT_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_DeInit(void);
#endif

#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_SetDutyCycle(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber,
        VAR(uint16, AUTOMATIC) DutyCycle
    );
#endif

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_SetPeriodAndDuty(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber,
        VAR(Pwm_PeriodType, AUTOMATIC) Period,
        VAR(uint16, AUTOMATIC) DutyCycle
    );
#endif

#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_SetOutputToIdle(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber
    );
#endif

#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
FUNC (Pwm_OutputStateType, PWM_CODE) Pwm_GetOutputState(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber
    );
#endif

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
FUNC (void, PWM_CODE) Pwm_EnableNotification(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber,
        VAR(Pwm_EdgeNotificationType, AUTOMATIC) Notification
    );
#endif

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
FUNC (void, PWM_CODE) Pwm_DisableNotification(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber
    );
#endif

#if (PWM_VERSION_INFO_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_GetVersionInfo(
        P2VAR(Std_VersionInfoType , AUTOMATIC, PWM_APPL_DATA) versioninfo
    );
#endif

FUNC (void, PWM_CODE) Pwm_Schm_ProtectResource(VAR(uint8, AUTOMATIC) Pwm_ExclusiveArea);
FUNC (void, PWM_CODE) Pwm_Schm_UnprotectResource(VAR(uint8, AUTOMATIC) Pwm_ExclusiveArea);

/*
* @violates @ref Pwm_H_REF_1 only preprocessor statements and comments before "#include"
*/
#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm_H_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* PWM_H */

/** @} */
