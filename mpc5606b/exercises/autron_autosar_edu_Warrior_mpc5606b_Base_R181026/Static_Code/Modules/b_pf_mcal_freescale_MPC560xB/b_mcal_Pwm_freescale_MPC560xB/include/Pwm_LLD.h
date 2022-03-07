/**
*   @file    Pwm_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Pwm - Pwm LLD API.
*   @details Pwm LLD API.
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

#ifndef PWM_LLD_H
#define PWM_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_LLD_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* Pwm LLD layer need to implement function-like macros to hide implementation specifics from the upper layers.
*
* @section Pwm_LLD_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Pwm_LLD_H_REF_3
* Violates MISRA 2004 Required Rule 19.4, This violation cannot be fixed since functions and variables
* cannot be declared and defined within braces.
* For example:
* #define var  (variable)
* int var;
* In the above scenario, the var is replaced with (variable) i.e. it will become int (variable);
* ->This is not the synctax for variable declaration.
*
* @section Pwm_LLD_H_REF_4
* Violates MISRA 2004 Required Rule 19.10, In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as
* the operand of # or ##.
*
* @section Pwm_LLD_H_REF_5
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
*
* @section Pwm_LLD_H_REF_6
* Violates MISRA 2004 Required Rule 8.7,
* Objects shall be defined at block scope if they are only accessed from within a single function.
*
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
#include "Pwm_eMIOS_LLD.h"
#include "Reg_eSys_eMIOS.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Pwm_LLD.h
* @implements     DPWM03706
* @implements     DPWM03201, DPWM03202, DPWM03203, DPWM03204, DPWM03205, DPWM03206, DPWM03207, DPWM03208
*/
#define PWM_LLD_H_VENDOR_ID                         43
#define PWM_LLD_H_MODULE_ID                         121
/*
* @violates @ref Pwm_LLD_H_REF_5 This is required as per autosar Requirement,
*/
#define PWM_LLD_H_AR_RELEASE_MAJOR_VERSION          4
/*
* @violates @ref Pwm_LLD_H_REF_5 This is required as per autosar Requirement,
*/
#define PWM_LLD_H_AR_RELEASE_MINOR_VERSION          0
/*
* @violates @ref Pwm_LLD_H_REF_5 This is required as per autosar Requirement,
*/
#define PWM_LLD_H_AR_RELEASE_REVISION_VERSION       3
#define PWM_LLD_H_SW_MAJOR_VERSION                  1
#define PWM_LLD_H_SW_MINOR_VERSION                  0
#define PWM_LLD_H_SW_PATCH_VERSION                  1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/


#if (PWM_LLD_H_VENDOR_ID != PWM_EMIOS_LLD_H_VENDOR_ID)
    #error "Pwm_LLD.h and Pwm_eMIOS_LLD.h have different vendor ids"
#endif

#if ((PWM_LLD_H_AR_RELEASE_MAJOR_VERSION != PWM_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_LLD_H_AR_RELEASE_MINOR_VERSION != PWM_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION) || \
        (PWM_LLD_H_AR_RELEASE_REVISION_VERSION != PWM_EMIOS_LLD_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_LLD.h and Pwm_eMIOS_LLD.h are different"
#endif

#if ((PWM_LLD_H_SW_MAJOR_VERSION != PWM_EMIOS_LLD_H_SW_MAJOR_VERSION) || \
        (PWM_LLD_H_SW_MINOR_VERSION != PWM_EMIOS_LLD_H_SW_MINOR_VERSION) || \
        (PWM_LLD_H_SW_PATCH_VERSION != PWM_EMIOS_LLD_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_LLD.h and Pwm_eMIOS_LLD.h are different"
#endif

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/*===============================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*
* @violates @ref Pwm_LLD_H_REF_5 This is required as per autosar Requirement,
*/
#define PWM_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Pwm_LLD_H_REF_2 Precautions shall be taken in order to prevent the
*                            contents of a header being included twice.
*/
#include "MemMap.h"

/**
* @brief        A pointer to the configuration structure
* @details      pointer to the top level configuration structure - valid only when the driver is in the
*               initialized state
*
*/
/*
* @violates @ref Pwm_LLD_H_REF_6 Objects shall be defined at block scope if they are only accessed
* from within a single function
*/
extern P2CONST(Pwm_ConfigType, PWM_VAR, PWM_APPL_CONST) Pwm_Cfg_Ptr;
/*
* @violates @ref Pwm_LLD_H_REF_5 This is required as per autosar Requirement,
*/
#define PWM_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Pwm_LLD_H_REF_2 Precautions shall be taken in order to prevent the
*                            contents of a header being included twice.
*/
#include "MemMap.h"

/*===============================================================================================
*                                     FUNCTION PROTOTYPES
===============================================================================================*/

#define PWM_START_SEC_CODE
/*
* @violates @ref Pwm_LLD_H_REF_2 Precautions shall be taken in order to prevent the
*                            contents of a header being included twice.
*/
#include "MemMap.h"

/*================================================================================================*/
/**
* @brief            Pwm_LLD_Init
* @details          This function call the supported IP initialization functions.
*
* @param[in]        ConfigPtr - pointer to PWM top configuration structure
*
* @return           void
*
* @implements       DPWM03213
*
* @violates @ref Pwm_LLD_H_REF_1 Function-like macro defined
*/
/*
* @violates @ref Pwm_LLD_H_REF_3 C macros shall only expand to a braced initialiser,
*    a constant, a parenthesised expression
*/
#define Pwm_LLD_Init(ConfigPtr)   Pwm_eMIOS_LLD_Init((ConfigPtr))


/*================================================================================================*/
#if (PWM_DE_INIT_API == STD_ON)

/**
* @brief            Pwm_LLD_DeInit
* @details          This function call the supported IP deinitialization functions.
*
* @return           void
*
* @implements       DPWM03209
*
* @violates @ref Pwm_LLD_H_REF_1 Function-like macro defined
*/
/*
* @violates @ref Pwm_LLD_H_REF_3 C macros shall only expand to a braced initialiser,
*    a constant, a parenthesised expression
*/
#define Pwm_LLD_DeInit()          Pwm_eMIOS_LLD_DeInit()
#endif /* PWM_DE_INIT_API */


/*================================================================================================*/
#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
/**
* @brief            Pwm_LLD_SetDutyCycle
* @details          This function will call SetDutyCycle function for the corresponding IP of PwmChannel
*
* @param[in]        PwmChannel      pwm channel id
* @param[in]        DutyCycle       pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return           void
*
* @implements       DPWM03215
*
* @violates @ref Pwm_LLD_H_REF_1 Function-like macro defined
*/
/*
* @violates @ref Pwm_LLD_H_REF_3 C macros shall only expand to a braced initialiser,
* a constant, a parenthesised expression
*/
#define Pwm_LLD_SetDutyCycle( ch_id, DutyCycle)  Pwm_eMIOS_LLD_SetDutyCycle((ch_id), (DutyCycle), (uint8)(STD_ON))
#endif /* PWM_SET_DUTY_CYCLE_API */


/*================================================================================================*/
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/**
* @brief            Pwm_LLD_SetPeriodAndDuty
* @details          This function will call SetPeriodAndDuty function for the corresponding IP of PwmChannel
*
* @param[in]        PwmChannel      pwm channel id
* @param[in]        Period          pwm signal period value
* @param[in]        DutyCycle       pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return           void
*
* @implements       DPWM03217
*
* @violates @ref Pwm_LLD_H_REF_1 Function-like macro defined
*/
/*
* @violates @ref Pwm_LLD_H_REF_3 C macros shall only expand to a braced initialiser,
* a constant, a parenthesised expression
*/
#define Pwm_LLD_SetPeriodAndDuty(ch_id, Period, DutyCycle)  Pwm_eMIOS_LLD_SetPeriodAndDuty((ch_id), (Period), (DutyCycle))
#endif /* PWM_SET_PERIOD_AND_DUTY_API */


/*================================================================================================*/
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/**
* @brief            Pwm_LLD_SetOutputToIdle
* @details          This function will call SetOutputToIdle function for the corresponding IP of PwmChannel
*
* @param[in]        PwmChannel      pwm channel id
*
* @return           void
*
* @implements       DPWM03216
*
* @violates @ref Pwm_LLD_H_REF_1 Function-like macro defined
*/
/*
* @violates @ref Pwm_LLD_H_REF_3 C macros shall only expand to a braced initialiser,
* a constant, a parenthesised expression
*/
#define Pwm_LLD_SetOutputToIdle(ch_id)  Pwm_eMIOS_LLD_SetOutputToIdle((ch_id))
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */


/*================================================================================================*/
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief            Pwm_LLD_GetOutputState
* @details          This function will call GetOutputState function for the corresponding IP of PwmChannel
*
* @param[in]        PwmChannel      pwm channel id
*
* @return           Pwm_OutputStateType Pwm signal output logic value
* @retval           PWM_LOW             The output pin is in LOW logic level
* @retval           PWM_HIGH            The output pin is in HIGH logic level
*
* @implements       DPWM03212
*
* @violates @ref Pwm_LLD_H_REF_1 Function-like macro defined
*/
/*
* @violates @ref Pwm_LLD_H_REF_3 C macros shall only expand to a braced initialiser,
* a constant, a parenthesised expression
*/
#define Pwm_LLD_GetOutputState(ch_id)   Pwm_eMIOS_LLD_GetOutputState((ch_id))
#endif /* PWM_GET_OUTPUT_STATE_API */


/*================================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief            Pwm_LLD_DisableNotification
* @details          This function will call DisableNotification function for the corresponding IP of PwmChannel
*
* @param[in]        PwmChannel      pwm channel id
*
* @implements       DPWM03210
*
* @violates @ref Pwm_LLD_H_REF_1 Function-like macro defined
*/
/*
* @violates @ref Pwm_LLD_H_REF_3 C macros shall only expand to a braced initialiser,
* a constant, a parenthesised expression
*/
#define Pwm_LLD_EnableNotification( ch_id, Notification) Pwm_eMIOS_LLD_EnableNotification((ch_id), (Notification))

/**
* @brief            Pwm_LLD_EnableNotification
* @details          This function will call EnableNotification function for the corresponding IP of PwmChannel
*
* @param[in]        PwmChannel      pwm channel id
*
* @implements       DPWM03211
*
* @violates @ref Pwm_LLD_H_REF_1 Function-like macro defined
*/
/*
* @violates @ref Pwm_LLD_H_REF_3 C macros shall only expand to a braced initialiser,
* a constant, a parenthesised expression
*/
#define Pwm_LLD_DisableNotification(ch_id)  Pwm_eMIOS_LLD_DisableNotification ((ch_id))
#endif /* PWM_NOTIFICATION_SUPPORTED */


/*================================================================================================*/
#if (PWM_SETCOUNTERBUS_API == STD_ON)
/**
* @brief  Mapping between low level layer and high level layer for Pwm_LLD_SetCounterBus function.
* @implements DPWM03220
* @requirements PWM_CUSTOM001
* @violates @ref Pwm_LLD_H_REF_1 Function-like macro defined
*/
/*
* @violates @ref Pwm_LLD_H_REF_3 C macros shall only expand to a braced initialiser,
* a constant, a parenthesised expression
*/
#define Pwm_LLD_SetCounterBus( ch_id, Bus )   Pwm_eMIOS_LLD_SetCounterBus( (ch_id), (Bus) )
#endif /* PWM_SETCOUNTERBUS_API */


/*================================================================================================*/
#if (PWM_SETCHANNELOUTPUT_API == STD_ON)
/**
* @brief  Mapping between low level layer and high level layer for Pwm_LLD_SetChannelOutput function.
* @requirements PR-MCAL-3173
* @implements DPWM03221
* @violates @ref Pwm_LLD_H_REF_1 Function-like macro defined
*/
/*
* @violates @ref Pwm_LLD_H_REF_3 C macros shall only expand to a braced initialiser,
* a constant, a parenthesised expression
*/
#define Pwm_LLD_SetChannelOutput( ch_id, State )   Pwm_eMIOS_LLD_SetChannelOutput((ch_id), (State))
#endif /* PWM_SETCHANNELOUTPUT_API */

/*================================================================================================*/
#if (PWM_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief  Mapping between low level layer and high level layer for
*         Pwm_LLD_SelectPrescaler function.
* @implements   DPWM03214
* @requirements PR-MCAL-3199
*/
/*
* @violates @ref Pwm_LLD_H_REF_1 Function-like macro defined
*/
/*
* @violates @ref Pwm_LLD_H_REF_3 C macros shall only expand to a braced initialiser,
* a constant, a parenthesised expression
*/
#define Pwm_LLD_SelectPrescaler( Prescaler )  Pwm_eMIOS_LLD_SelectPrescaler( (Prescaler) )
#endif /* PWM_DUAL_CLOCK_MODE */
/*================================================================================================*/

#ifdef MULTI_PWM_CHANNEL_SYNCH
    #if (MULTI_PWM_CHANNEL_SYNCH == STD_ON)
    /**
    @brief  Mapping between low level layer and high level layer for
            Pwm_LLD_BufferTransferEnableDisable function.
    @implements   DPWM03223
    @requirements PR-MCAL-3299
    */
    /*
    * @violates @ref Pwm_LLD_H_REF_1 Function-like macro defined
    */
    /*
    * @violates @ref Pwm_LLD_H_REF_5 This is required as per autosar Requirement,
    */
    /*
    * @violates @ref Pwm_LLD_H_REF_3 C macros shall only expand to a braced initialiser,
    *    a constant, a parenthesised expression
    */
    #define Pwm_LLD_BufferTransferEnableDisable(ModuleIndex, ChannelMask) \
                                                        Pwm_eMIOS_LLD_BufferTransferEnableDisable \
                                                                    ( \
                                                                      (ModuleIndex),\
                                                                      (ChannelMask) \
                                                                    )
    #endif
#endif
/*================================================================================================*/
#ifdef PWM_FEATURE_OPWMT
#if (PWM_FEATURE_OPWMT == STD_ON)
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
/**
* @brief  This function will call set configured triggerdelay during runtime.
* @requirements PR-MCAL-3234
* @implements DPWM03222
* @violates @ref Pwm_LLD_H_REF_1 Function-like macro defined
*/
/*
* @violates @ref Pwm_LLD_H_REF_3 C macros shall only expand to a braced initialiser,
*    a constant, a parenthesised expression
*/
#define Pwm_LLD_SetTriggerDelay( ch_id, TriggerDelay) Pwm_eMIOS_LLD_SetTriggerDelay \
                                                             ( \
                                                                 (ch_id), \
                                                                 (TriggerDelay) \
                                                             )
#endif/*PWM_SET_TRIGGER_DELAY_API*/
#endif
#endif/*PWM_FEATURE_OPWMT*/
/*================================================================================================*/
#if (PWM_GET_CHANNEL_STATE == STD_ON)
/**
@brief   Implementation specific function to get the Duty cycle of the given PWM channel
 @param[in] LogicalChannelNumber - pwm channel id
* @implements DPWM03218
* @requirements   PR-MCAL-3295
*/
/*
* @violates @ref Pwm_LLD_H_REF_1 Function-like macro defined
*/
/*
* @violates @ref Pwm_LLD_H_REF_5 This is required as per autosar Requirement,
*/
/*
* @violates @ref Pwm_LLD_H_REF_3 C macros shall only expand to a braced initialiser,
*    a constant, a parenthesised expression
*/
#define Pwm_LLD_GetChannelState( ch_id )    Pwm_eMIOS_LLD_GetChannelState( (ch_id) )

#endif/*PWM_GET_CHANNEL_STATE*/

#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm_LLD_H_REF_2 Precautions shall be taken in order to prevent the
*                            contents of a header being included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* PWM_LLD_H*/

/** @} */
