/**
*   @file    Pwm_eMIOS_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Pwm - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
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

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_eMIOS_LLD_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, :  Repeated include files,  Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
*@section Pwm_eMIOS_LLD_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
*
*/
#ifndef PWM_EMIOS_LLD_H
#define PWM_EMIOS_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/*===============================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
===============================================================================================*/
/*
* @violates @ref Pwm_eMIOS_LLD_H_REF_1 Repeated include files
*/
#include "Std_Types.h"



/*===============================================================================================
                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/

/**
* @{
*/
#define PWM_EMIOS_LLD_H_VENDOR_ID                           43
#define PWM_EMIOS_LLD_H_MODULE_ID                           121
/*
* @violates @ref Pwm_eMIOS_LLD_H_REF_2 This is required as per autosar Requirement, 
*/
#define PWM_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION            4
/*
* @violates @ref Pwm_eMIOS_LLD_H_REF_2 This is required as per autosar Requirement, 
*/
#define PWM_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION            0
/*
* @violates @ref Pwm_eMIOS_LLD_H_REF_2 This is required as per autosar Requirement, 
*/
#define PWM_EMIOS_LLD_H_AR_RELEASE_REVISION_VERSION         3
/*
* @violates @ref Pwm_eMIOS_LLD_H_REF_2 This is required as per autosar Requirement, 
*/
#define PWM_EMIOS_LLD_H_SW_MAJOR_VERSION                    1
/*
* @violates @ref Pwm_eMIOS_LLD_H_REF_2 This is required as per autosar Requirement, 
*/
#define PWM_EMIOS_LLD_H_SW_MINOR_VERSION                    0
/*
* @violates @ref Pwm_eMIOS_LLD_H_REF_2 This is required as per autosar Requirement, 
*/
#define PWM_EMIOS_LLD_H_SW_PATCH_VERSION                    1
/** @} */

/*===============================================================================================
                                      FILE VERSION CHECKS
===============================================================================================*/
/* Check if source file and Std_Types.h are of the same Autosar version */

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

#if ((PWM_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Pwm_eMIOS_LLD.h and Std_Types.h are different"
#endif

#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */


/*===============================================================================================
                                           CONSTANTS
===============================================================================================*/


/*===============================================================================================
                                       DEFINES AND MACROS
===============================================================================================*/


/*===============================================================================================
                                             ENUMS
===============================================================================================*/


/*===============================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/
/*
* @violates @ref Pwm_eMIOS_LLD_H_REF_2 This is required as per autosar Requirement, 
*/
#define PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Pwm_eMIOS_LLD_H_REF_1 Repeated include files
*/
#include "MemMap.h"


#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief    array used for reverse translation between Hw channel and Logical channel
*           used to call the logical channel notification in the hw channel ISR
*/
    extern VAR(Pwm_ChannelType, PWM_VAR) Pwm_eMIOS_LLD_RevHardwareTable[ PWM_EMIOS_HW_CHANNELS ];
#endif

/*
* @violates @ref Pwm_eMIOS_LLD_H_REF_2 This is required as per autosar Requirement, 
*/
#define PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

/*
* @violates @ref Pwm_eMIOS_LLD_H_REF_1 Repeated include files
*/
#include "MemMap.h"


/*===============================================================================================
                                     FUNCTION PROTOTYPES
===============================================================================================*/
#define PWM_START_SEC_CODE

/*
* @violates @ref Pwm_eMIOS_LLD_H_REF_1 Repeated include files
*/
#include "MemMap.h"

/*===============================================================================================*/
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_Init(
        P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr
    );


/*===============================================================================================*/
#if (PWM_DE_INIT_API == STD_ON)
    FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_DeInit(void);
#endif /* PWM_DE_INIT_API */


/*===============================================================================================*/
#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SETCOUNTERBUS_API == STD_ON))
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_SetDutyCycle(
        VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber,
        VAR(uint16, AUTOMATIC) DutyCycle,
        VAR(uint8,  AUTOMATIC) useSection
    );
#endif /* PWM_SET_DUTY_CYCLE_API */


/*===============================================================================================*/

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_SetPeriodAndDuty(
        VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber,
        VAR(Pwm_PeriodType,  AUTOMATIC) Period,
        VAR(uint16,          AUTOMATIC) DutyCycle
    );
#endif /* PWM_SET_PERIOD_AND_DUTY_API */


/*===============================================================================================*/
#if ( PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_SetOutputToIdle(
        VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber
    );
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */


/*===============================================================================================*/
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
FUNC (Pwm_OutputStateType, PWM_CODE) Pwm_eMIOS_LLD_GetOutputState(
        VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber
    );
#endif /* PWM_GET_OUTPUT_STATE_API */


/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/*
* @violates @ref Pwm_eMIOS_LLD_H_REF_2 This is required as per autosar Requirement, 
*/
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_EnableNotification(
        VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber,
        VAR(Pwm_EdgeNotificationType, AUTOMATIC) Notification
    );
#endif /* PWM_NOTIFICATION_SUPPORTED */


/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/*
* @violates @ref Pwm_eMIOS_LLD_H_REF_2 This is required as per autosar Requirement, 
*/
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_DisableNotification(
        VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber
    );
#endif /* PWM_NOTIFICATION_SUPPORTED */


/*===============================================================================================*/
#if (PWM_SETCOUNTERBUS_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_SetCounterBus(
        VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber,
        VAR(uint32, AUTOMATIC)          Bus
    );
#endif /* PWM_SETCOUNTERBUS_API */


/*===============================================================================================*/
#if (PWM_SETCHANNELOUTPUT_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_SetChannelOutput(
        VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber,
        VAR(Pwm_StateType, AUTOMATIC)          State
    );
#endif /* PWM_SETCHANNELOUTPUT_API */


/*===============================================================================================*/
#if (PWM_DUAL_CLOCK_MODE == STD_ON)
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_SelectPrescaler(
        VAR(Pwm_SelectPrescalerType, AUTOMATIC) Prescaler
    );
#endif /* PWM_DUAL_CLOCK_MODE */


/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)

/* this function is defined in this file but because a declaration is needed and
*  and a Pwm_eMIOS_LLD_IRQ.h file is not available will be declared here
*/
/*
* @violates @ref Pwm_eMIOS_LLD_IRQ_C_REF_5 function previously declared
*/
    FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_ProcessInterrupt( VAR(Pwm_ChannelType, AUTOMATIC) hw_ch_id );
#endif

/*===============================================================================================*/
#ifdef PWM_FEATURE_OPWMT
    #if (PWM_FEATURE_OPWMT == STD_ON)
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_SetTriggerDelay
                      (
                          VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber,
                          VAR(Pwm_PeriodType, AUTOMATIC)  TriggerDelay
                      );

#endif
    #endif
#endif
/*===============================================================================================*/

#ifdef MULTI_PWM_CHANNEL_SYNCH
#if (MULTI_PWM_CHANNEL_SYNCH == STD_ON)
/**
@brief   Implementation specific function to enable/disble the buffer transfer.

@details This function is useful to enable/disble the buffer transfer to synchronize
         multiple PWM channels.

@param[in] ModuleIndex - eMIOS module
           ChannelMask - channel mask set

@remarks PR-MCAL-3299
@implements   DPWM04019
*/
/*
* @violates @ref Pwm_eMIOS_LLD_H_REF_2 This is required as per autosar Requirement, 
*/
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_BufferTransferEnableDisable(
                             VAR(uint8, AUTOMATIC) ModuleIndex,
                             VAR(uint32, AUTOMATIC) ChannelMask
      );
#endif
#endif
/*===============================================================================================*/
#if (PWM_GET_CHANNEL_STATE == STD_ON)
/**
@brief   Implementation specific function to get the Duty cycle of the given PWM channel
 @param[in] LogicalChannelNumber - pwm channel id
@remarks PR-MCAL-3295    
@implements DPWM04020
*/
FUNC(uint16, PWM_CODE)  Pwm_eMIOS_LLD_GetChannelState    ( 
                                                                VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber
                                                            );
#endif    /*PWM_GET_CHANNEL_STATE*/
/*===============================================================================================*/

#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm_eMIOS_LLD_H_REF_1 Repeated include files
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif


#endif   /* EMIOS_PWM_LLD_H */

/** @} */

