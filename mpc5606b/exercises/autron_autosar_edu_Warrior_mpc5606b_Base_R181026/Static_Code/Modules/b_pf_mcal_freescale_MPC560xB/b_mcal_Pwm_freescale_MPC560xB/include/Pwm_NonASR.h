/**
*   @file    Pwm_NonASR.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Pwm - Pwm module NonAutosar API header.
*   @details Pwm NonAutosar APIs and defines.
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


#ifndef PWM_NONASR_H
#define PWM_NONASR_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
*@section Pwm_NonASR_H_REF_1
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
*
* @section Pwm_NonASR_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*/


/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==============================================================================================*/

/*
* @file           Pwm_NonASR.h
* @implements     DPWM02204
*/
/*
* @violates @ref Pwm_NonASR_H_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Std_Types.h"
/*
* @violates @ref Pwm_NonASR_H_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm.h"


/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Pwm_NonASR.h
* @implements     DPWM02501, DPWM02502, DPWM02503, DPWM02505, DPWM02509, DPWM02510, DPWM02511, DPWM02512
*/
#define PWM_NONASR_H_VENDOR_ID                      43
#define PWM_NONASR_H_MODULE_ID                      121
/*
* @violates @ref Pwm_NonASR_H_REF_1 This is required as per autosar Requirement, 
*/
#define PWM_NONASR_H_AR_RELEASE_MAJOR_VERSION       4
/*
* @violates @ref Pwm_NonASR_H_REF_1 This is required as per autosar Requirement, 
*/
#define PWM_NONASR_H_AR_RELEASE_MINOR_VERSION       0
/*
* @violates @ref Pwm_NonASR_H_REF_1 This is required as per autosar Requirement, 
*/
#define PWM_NONASR_H_AR_RELEASE_REVISION_VERSION    3
#define PWM_NONASR_H_SW_MAJOR_VERSION               1
#define PWM_NONASR_H_SW_MINOR_VERSION               0
#define PWM_NONASR_H_SW_PATCH_VERSION               1
/**@}*/
/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Std_Types.h are of the same Autosar version */
#if ((PWM_NONASR_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_NONASR_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Pwm_NonASR.h and Std_Types.h are different"
#endif
#endif


/* Check if source file and PWM configuration header file are of the same vendor */
#if (PWM_NONASR_H_VENDOR_ID != PWM_CFG_H_VENDOR_ID)
    #error "Pwm_NonASR.h and Pwm_Cfg.h have different vendor ids"
#endif


/* Check if source file and PWM configuration header file are of the same Autosar version */
#if ((PWM_NONASR_H_AR_RELEASE_MAJOR_VERSION != PWM_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_NONASR_H_AR_RELEASE_MINOR_VERSION != PWM_CFG_H_AR_RELEASE_MINOR_VERSION) || \
        (PWM_NONASR_H_AR_RELEASE_REVISION_VERSION != PWM_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_NonASR.h and Pwm_Cfg.h are different"
#endif


/* Check if source file and PWM configuration header file are of the same software version */
#if ((PWM_NONASR_H_SW_MAJOR_VERSION != PWM_CFG_H_SW_MAJOR_VERSION) || \
        (PWM_NONASR_H_SW_MINOR_VERSION != PWM_CFG_H_SW_MINOR_VERSION) || \
        (PWM_NONASR_H_SW_PATCH_VERSION != PWM_CFG_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_NonASR.h and Pwm_Cfg.h are different"
#endif

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/**
* @brief   API service ID of implementation specific Pwm_SetCounterBus function
* @details Parameters used when raising an error/exception
* @implements   DPWM02508
*/
#define PWM_SETCOUNTERBUS_ID     0x09U

/**
* @brief   API service ID of implementation specific Pwm_SetChannelOutput function
* @details Parameters used when raising an error/exception
* @implements   DPWM02506
*/
#define PWM_SETCHANNELOUTPUT_ID  0x0AU

/**
* @brief   API service ID of implementation specific Pwm_SetClockMode function
* @details Parameters used when raising an error/exception
* @implements   DPWM02507
*/
#define PWM_SETCLOCKMODE_ID  0x0BU
/**
* @brief   API service ID of implementation specific Pwm_SetTriggerDelay function
* @details Parameters used when raising an error/exception
* @implements   DPWM02516
*/
#define PWM_SETTRIGGERDELAY_ID  0x0CU
/**
* @brief   Error code generated when Pwm_SetCounterBus is called with an invalid parameter
* @details Errors and exceptions that will be detected by the PWM driver
* @implements   DPWM02504
*/
#define PWM_E_COUNTERBUS         0x19U

/**
* @brief   API service ID of implementation specific Pwm_GetChannelState function
* @details Parameters used when raising an error/exception
* @implements   DPWM02517
*/
#define PWM_GETCHANNELSTATE_ID 0x0DU

/**
* @brief   API service ID of Pwm_BufferTransferEnableDisable function
* @details Parameters used when raising an error/exception
* @implements   DPWM02519
*/
#define PWM_BUFTRANSFER_ID 0x0EU

/**
* @brief          API service ID
* @implements     DPWM06091
*/
#define PWM_FORCESWOUTPUT_ID    0x0FU

/**
* @brief          API service ID of Pwm_DmaSetDutyCycle
* @implements     DPWM06097
*/
#define PWM_DMASETDUDTCYCLE_ID    0x10U

/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/*===============================================================================================
*                              STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
*                                     FUNCTION PROTOTYPES
===============================================================================================*/

/*
* @violates @ref Pwm_NonASR_H_REF_1 only preprocessor statements and comments before "#include"
*/
#define PWM_START_SEC_CODE
/*
* @violates @ref Pwm_NonASR_H_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"

#ifdef PWM_SETCOUNTERBUS_API
#if (PWM_SETCOUNTERBUS_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_SetCounterBus(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber,
        VAR(uint32, AUTOMATIC) Bus
    );
#endif
#endif

#ifdef PWM_SETCHANNELOUTPUT_API
#if (PWM_SETCHANNELOUTPUT_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_SetChannelOutput(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber,
        VAR(Pwm_StateType, AUTOMATIC) State
    );
#endif
#endif

#ifdef PWM_DUAL_CLOCK_MODE
#if (PWM_DUAL_CLOCK_MODE==STD_ON)
FUNC (void, PWM_CODE) Pwm_SetClockMode(
        VAR(Pwm_SelectPrescalerType, AUTOMATIC) Prescaler
    );
#endif
#endif

#ifdef PWM_FEATURE_OPWMT
#if (PWM_FEATURE_OPWMT == STD_ON)

#ifdef PWM_SET_TRIGGER_DELAY_API
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_SetTriggerDelay
                      (
                          VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber,
                          VAR(uint16, AUTOMATIC) TriggerDelay
                      );
#endif
#endif

#endif
#endif/*PWM_FEATURE_OPWMT*/

#ifdef PWM_SET_PERIOD_DUTY_NOUPDATE_API
#if (PWM_SET_PERIOD_DUTY_NOUPDATE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_SetPeriodAndDuty_NoUpdate(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber,
        VAR(Pwm_PeriodType, AUTOMATIC)  Period,
        VAR(uint16, AUTOMATIC) DutyCycle
    );
#endif
#endif

#ifdef PWM_SET_DUTY_CYCLE_NOUPDATE_API
#if (PWM_SET_DUTY_CYCLE_NOUPDATE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_SetDutyCycle_NoUpdate(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber,
        VAR(uint16, AUTOMATIC) DutyCycle
    );
#endif
#endif

#ifdef PWM_SYNC_UPDATE
#if (PWM_SYNC_UPDATE == STD_ON)
FUNC (void, PWM_CODE) Pwm_SyncUpdate(
            VAR(Pwm_ModuleType,AUTOMATIC) Module,
            VAR(uint16,AUTOMATIC) MaskValue
    );
#endif
#endif

#ifdef PWM_GET_CHANNEL_STATE
#if (PWM_GET_CHANNEL_STATE == STD_ON)
FUNC (Pwm_DutyType, PWM_CODE) Pwm_GetChannelState(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber
    );
#endif
#endif

#ifdef MULTI_PWM_CHANNEL_SYNCH
#if (MULTI_PWM_CHANNEL_SYNCH==STD_ON)
/**
@brief   Implementation specific function to enable/disable the buffer transfer.

@details This function is useful to enable/disable the buffer transfer to synchronize multiple PWM channels.

    - if any function (except Pwm_Init) is called before Pwm_Init has been called,
    the called function shall raise development error PWM_E_UNINIT.

    Report the error to the Development Error Tracer.

    Skip the desired functionality in order to avoid any corruptions of
    data or hardware registers: This means leave the function without any actions.

@param[in] ModuleIndex - eMIOS module
           ChannelMask - channel mask set

@remarks PR-MCAL-3299
@implements   DPWM01011, DPWM02518
*/
extern FUNC (void, PWM_CODE) Pwm_BufferTransferEnableDisable
                             (
                                 VAR(uint8, AUTOMATIC) ModuleIndex,
                                 VAR(uint32, AUTOMATIC) ChannelMask
                             );

#endif
#endif

#ifdef PWM_OUTPUTSWCONTROL_API
#if (PWM_OUTPUTSWCONTROL_API == STD_ON)
FUNC (void, PWM_CODE)Pwm_ForceSWOutputValue(
            VAR(Pwm_ChannelType, AUTOMATIC) PwmChannel,
            VAR(Pwm_OutputStateType, AUTOMATIC) Val
    );
#endif
#endif

#ifdef PWM_DMASETDUTYCYCLE_API
#if (PWM_DMASETDUTYCYCLE_API == STD_ON)
FUNC (void, PWM_CODE)Pwm_DmaSetDutyCycle(
            P2VAR(Pwm_DutyDmaType, AUTOMATIC, PWM_APPL_DATA) BufferPtr,
            VAR(uint16, AUTOMATIC) BufferSize
    );
#endif
#endif
/*
* @violates @ref Pwm_NonASR_H_REF_1 only preprocessor statements and comments before "#include"
*/
#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm_NonASR_H_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* PWM_NONASR_H */

/** @} */
