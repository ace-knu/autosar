/**
*   @file    Pwm.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Pwm - Pwm high level interface implementation.
*   @details Pwm high level interface implementation.
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
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include'
* MemMap.h included after each section define in order to set the current memory section
*
* @section Pwm_C_REF_2
* Violates MISRA 2004 Required Rule 17.4, This violation is due to the use of pointer arithmetic,
* which is used for the speed optimization, the indexing of the pointer is taken care and hence the
* unintended memory location will not be accessed.
*
* @section Pwm_C_REF_3
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Pwm_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Pwm_C_REF_5
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Pwm_C_REF_6
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
*
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/

/*
* @file           Pwm.c
* @implements     DPWM02201
*/
#include "Mcal.h"
#include "Pwm.h"
#include "Pwm_LLD.h"
#include "SchM_Pwm.h"


#if (PWM_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif


/*===============================================================================================
*                                        SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Pwm.c
* @implements     DPWM02301, DPWM02302, DPWM02303, DPWM02305, DPWM02306, DPWM02307, DPWM02308
*/
#define PWM_VENDOR_ID_C                         43
#define PWM_AR_RELEASE_MAJOR_VERSION_C          4
#define PWM_AR_RELEASE_MINOR_VERSION_C          0
/*
* @violates @ref Pwm_C_REF_4 Identifier clash.
*/
/*
* @violates @ref Pwm_C_REF_6 This is required as per autosar Requirement, 
*/
#define PWM_AR_RELEASE_REVISION_VERSION_C       3
#define PWM_SW_MAJOR_VERSION_C                  1
#define PWM_SW_MINOR_VERSION_C                  0
#define PWM_SW_PATCH_VERSION_C                  1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

/* Check if source file and PWM header file are of the same vendor */
#if (PWM_VENDOR_ID_C != PWM_VENDOR_ID)
    #error "Pwm.c and Pwm.h have different vendor ids"
#endif
/* Check if source file and PWM header file are of the same Autosar version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION_C != PWM_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_AR_RELEASE_MINOR_VERSION_C != PWM_AR_RELEASE_MINOR_VERSION) || \
        (PWM_AR_RELEASE_REVISION_VERSION_C != PWM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm.c and Pwm.h are different"
#endif
/* Check if source file and PWM header file are of the same Software version */
#if ((PWM_SW_MAJOR_VERSION_C != PWM_SW_MAJOR_VERSION)  || \
        (PWM_SW_MINOR_VERSION_C != PWM_SW_MINOR_VERSION)  || \
        (PWM_SW_PATCH_VERSION_C != PWM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm.c and Pwm.h are different"
#endif

/* Check if source file and PWM LLD header file are of the same vendor */
#if (PWM_VENDOR_ID_C != PWM_LLD_H_VENDOR_ID)
    #error "Pwm.c and Pwm.h have different vendor ids"
#endif
/* Check if source file and PWM LLD header file are of the same Autosar version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION_C != PWM_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_AR_RELEASE_MINOR_VERSION_C != PWM_LLD_H_AR_RELEASE_MINOR_VERSION) || \
        (PWM_AR_RELEASE_REVISION_VERSION_C != PWM_LLD_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm.c and Pwm.h are different"
#endif
/* Check if source file and PWM LLD header file are of the same Software version */
#if ((PWM_SW_MAJOR_VERSION_C != PWM_LLD_H_SW_MAJOR_VERSION) || \
        (PWM_SW_MINOR_VERSION_C != PWM_LLD_H_SW_MINOR_VERSION) || \
        (PWM_SW_PATCH_VERSION_C != PWM_LLD_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm.c and Pwm.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    /* Check if source file and DET header file are of the same version */
    #if ((PWM_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
            (PWM_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Pwm.c and Det.h are different"
    #endif
#endif

#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*===============================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
===============================================================================================*/


/*===============================================================================================
*                                       LOCAL CONSTANTS
===============================================================================================*/


/*===============================================================================================
*                                       LOCAL VARIABLES
===============================================================================================*/


/*===============================================================================================
*                                       GLOBAL CONSTANTS
===============================================================================================*/


/*===============================================================================================
*                                       GLOBAL VARIABLES
===============================================================================================*/
/*
* @violates @ref Pwm_C_REF_6 This is required as per autosar Requirement, 
*/
#define PWM_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Pwm_C_REF_5 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"

/**
@brief pointer to the top level configuration structure - valid only when the driver is in the
       initialized state
*/
/*
* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
P2CONST(Pwm_ConfigType, PWM_VAR, PWM_APPL_CONST) Pwm_Cfg_Ptr = NULL_PTR;
/*
* @violates @ref Pwm_C_REF_6 This is required as per autosar Requirement, 
*/
#define PWM_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Pwm_C_REF_1 Only preprocessor statements and comments before "#include"
*/
/*
* @violates @ref Pwm_C_REF_5 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"

/*===============================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
===============================================================================================*/

/*===============================================================================================
*                                       LOCAL FUNCTIONS
===============================================================================================*/

/*===============================================================================================
*                                       GLOBAL FUNCTIONS
===============================================================================================*/
#define PWM_START_SEC_CODE
/*
* @violates @ref Pwm_C_REF_1 Only preprocessor statements and comments before "#include"
*/
/*
* @violates @ref Pwm_C_REF_5 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"
/**
* @brief        This function initializes the Pwm driver.
* @details      The function Pwm_Init shall initialize all internals variables and the used
*               PWM structure of the microcontroller according to the parameters
*               specified in ConfigPtr.
*               If the duty cycle parameter equals:
*
*                   - 0% or 100% : Then the PWM output signal shall be in the state according
*                       to the configured polarity parameter;
*
*                   - >0% and <100%: Then the PWM output signal shall be modulated according
*                       to parameters period, duty cycle and configured polarity.
*
*               The function Pwm_SetDutyCycle shall update the duty cycle always at the end
*               of the period if supported by the implementation and configured
*               with PwmDutycycleUpdatedEndperiod.
*
*               The driver shall avoid spikes on the PWM output signal when updating
*               the PWM period and duty.
*
*               If development error detection for the Pwm module is enabled, the PWM functions
*               shall check the channel class type and raise development error PWM_E_PERIOD_UNCHANGEABLE
*               if the PWM channel is not declared as a variable period type.
*
*               If development error detection for the Pwm module is enabled, the PWM functions
*               shall check the parameter ChannelNumber and raise development error PWM_E_PARAM_CHANNEL
*               if the parameter ChannelNumber is invalid.
*
*               If development error detection for the Pwm module is enabled, when a development
*               error occurs, the corresponding PWM function shall:
*
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions of
*                       data or hardware registers (this means leave the function without any actions).
*                   - Return pwm level low for the function Pwm_GetOutputState.
*
*               The function Pwm_Init shall disable all notifications. The reason is that the users
*               of these notifications may not be ready. They can call Pwm_EnableNotification
*               to start notifications.
*
*               The function Pwm_Init shall only initialize the configured resources and shall not touch
*               resources that are not configured in the configuration file.
*
*               If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*               The detailed description of the detected errors can be found in chapter
*               Error classification and chapter API specification (see PWM_SWS).
*
*               If development error detection is enabled, calling the routine Pwm_Init
*               while the PWM driver and hardware are already initialized will cause a
*               development error PWM_E_ALREADY_INITIALIZED.
*               The desired functionality shall be left without any action.
*
*               For pre-compile and link time configuration variants, a NULL pointer shall be passed
*               to the initialization routine. In this case the check for this NULL pointer
*               has to be omitted.
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function
*               shall raise development error PWM_E_UNINIT.
*
* @param[in]    ConfigPtr       pointer to PWM top configuration structure
*
* @return       void
*
* @api
*
* @implements     DPWM01006, DPWM02033
*
*/
/*
* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC (void, PWM_CODE) Pwm_Init(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr)
{

/* @implements DPWM01019 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    /* If already initialized, error */
    if (NULL_PTR != Pwm_Cfg_Ptr)
    {
        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0U,
            (uint8) PWM_INIT_ID,
            (uint8) PWM_E_ALREADY_INITIALIZED
        );
    }
#if (PWM_PRECOMPILE_SUPPORT != STD_ON)
    else if (NULL_PTR == ConfigPtr)
    {
        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0U,
            (uint8) PWM_INIT_ID,
            (uint8) PWM_E_PARAM_CONFIG
        );
    }
    else
    {
#endif /* PWM_PRECOMPILE_SUPPORT */
#endif /* PWM_DEV_ERROR_DETECT */

        /* Save pointer in global variable */
#if (PWM_PRECOMPILE_SUPPORT == STD_ON)
        if (NULL_PTR == ConfigPtr)
        {
            Pwm_Cfg_Ptr = &Pwm_InitConfig_PC;
        }
        else
        {
#endif /* PWM_PRECOMPILE_SUPPORT */
            Pwm_Cfg_Ptr = ConfigPtr;

#if (PWM_PRECOMPILE_SUPPORT == STD_ON)
        }
#endif /* PWM_PRECOMPILE_SUPPORT */

        /* (P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST)) */
        Pwm_LLD_Init( Pwm_Cfg_Ptr );

#if (PWM_PRECOMPILE_SUPPORT != STD_ON)
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        }
#endif /* PWM_DEV_ERROR_DETECT */
#endif /* PWM_PRECOMPILE_SUPPORT */

}


/*===============================================================================================*/
#if (PWM_DE_INIT_API == STD_ON)
/**
* @brief        This function deinitializes the Pwm driver.
* @details      The function Pwm_DeInit shall deinitialize the PWM module.
*
*               The function Pwm_DeInit shall set the state of the PWM output signals
*               to the idle state.
*               The function Pwm_DeInit shall disable PWM interrupts and PWM signal edge notifications.
*               The function Pwm_DeInit shall be pre-compile time configurable On/Off by the
*               configuration parameter PwmDeInitApi function prototype.
*               If development error detection for the Pwm module is enabled,
*               when a development error occurs, the corresponding PWM function shall:
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions
*                       of data or hardware registers (this means leave the function without any actions).
*                   - Return pwm level low for the function Pwm_GetOutputState.
*
*               If development error detection for the Pwm module is enabled, if any function
*               (except Pwm_Init) is called before Pwm_Init has been called, the called function
*               shall raise development error PWM_E_UNINIT.
*
* @return       void
*
* @api
*
* @implements   DPWM01001, DPWM02028
*
*/
/*
* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC (void, PWM_CODE) Pwm_DeInit(void)
{
    if (NULL_PTR != Pwm_Cfg_Ptr)
    {
        Pwm_LLD_DeInit();
        Pwm_Cfg_Ptr = NULL_PTR;
    }
/* @implements DPWM01014 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    else
    {

        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_DEINIT_ID,
            (uint8) PWM_E_UNINIT
        );
    }
#endif /* end PWM_DEV_ERROR_DETECT */
}
#endif /* API SWITCH */


/*===============================================================================================*/
#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
/**
* @brief            This function sets the dutycycle for the specified Pwm channel.
* @details          The function Pwm_SetDutyCycle shall set the duty cycle of the PWM channel.
*
*                   The function Pwm_SetDutyCycle shall set the PWM output state according
*                   to the configured polarity parameter, when the duty cycle = 0% or 100%.
*                   The function Pwm_SetDutyCycle shall modulate the PWM output signal according
*                   to parameters period, duty cycle and configured polarity,
*                   when the duty cycle > 0 % and < 100%.
*
*                   If development error detection for the Pwm module is enabled,
*                   the PWM functions shall check the parameter ChannelNumber and raise development error
*                   PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
*
*                   If development error detection for the Pwm module is enabled,
*                   when a development error occurs, the corresponding PWM function shall:
*                       - Report the error to the Development Error Tracer.
*                       - Skip the desired functionality in order to avoid any corruptions
*                           of data or hardware registers (this means leave the function without any actions).
*                       - Return pwm level low for the function Pwm_GetOutputState.
*
*                   The Pwm module shall comply with the following scaling scheme for the duty cycle:
*                       - 0x0000 means 0%.
*                       - 0x8000 means 100%.
*                       - 0x8000 gives the highest resolution while allowing 100% duty cycle to be
*                           represented with a 16 bit value.
*                           As an implementation guide, the following source code example is given:
*                           AbsoluteDutyCycle = ((uint32)AbsolutePeriodTime * RelativeDutyCycle) >> 15;
*
*                   If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*                   The detailed description of the detected errors can be found in chapter
*                   Error classification and chapter API specification (see PWM_SWS).
*
*
* @param[in]        ChannelNumber       pwm channel id
* @param[in]        DutyCycle           pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return void
*
* @api
*
* @implements     DPWM01008, DPWM02035
*/

/*
* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC (void, PWM_CODE) Pwm_SetDutyCycle(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber,
        VAR(uint16, AUTOMATIC) DutyCycle
    )
{
    if (NULL_PTR != Pwm_Cfg_Ptr)
    {
/* @implements DPWM01021 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        if (ChannelNumber >= Pwm_Cfg_Ptr->ChannelCount)
        {

            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_SETDUTYCYCLE_ID,
                (uint8) PWM_E_PARAM_CHANNEL
            );
        }
        else if (DutyCycle > PWM_DUTY_CYCLE_100)
        {

            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_SETDUTYCYCLE_ID,
                (uint8) PWM_E_DUTYCYCLE_RANGE
            );
        }
        else
        {
#endif /* PWM_DEV_ERROR_DETECT */

            /* call LLD function */
            /*
             @note MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness
             */
            Pwm_LLD_SetDutyCycle(ChannelNumber, DutyCycle);
        }
/* @implements DPWM01021 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {

        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_SETDUTYCYCLE_ID,
            (uint8) PWM_E_UNINIT
        );
    }
#endif /* PWM_DEV_ERROR_DETECT */
}
#endif /* PWM_DE_INIT_API*/


/*===============================================================================================*/
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/**
* @brief            This function sets the period and the dutycycle for the specified Pwm channel.
* @details          The function Pwm_SetPeriodAndDuty shall set the duty cycle of the PWM channel.
*
*                   If development error detection for the Pwm module is enabled, the PWM functions
*                   shall check the channel class type and raise development error PWM_E_PERIOD_UNCHANGEABLE
*                   if the PWM channel is not declared as a variable period type.
*
*                   If development error detection for the Pwm module is enabled,
*                   the PWM functions shall check the parameter ChannelNumber and raise development error
*                   PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
*
*                   If development error detection for the Pwm module is enabled,
*                   when a development error occurs, the corresponding PWM function shall:
*                       - Report the error to the Development Error Tracer.
*                       - Skip the desired functionality in order to avoid any corruptions
*                           of data or hardware registers (this means leave the function without any actions).
*                       - Return pwm level low for the function Pwm_GetOutputState.
*
*                   The Pwm module shall comply with the following scaling scheme for the duty cycle:
*                       - 0x0000 means 0%.
*                       - 0x8000 means 100%.
*                       - 0x8000 gives the highest resolution while allowing 100% duty cycle to be
*                           represented with a 16 bit value.
*                           As an implementation guide, the following source code example is given:
*                           AbsoluteDutyCycle = ((uint32)AbsolutePeriodTime * RelativeDutyCycle) >> 15;
*
*                   If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*                   The detailed description of the detected errors can be found in chapter
*                   Error classification and chapter API specification (see PWM_SWS).
*
*                   If development error detection for the Pwm module is enabled, if any function
*                   (except Pwm_Init) is called before Pwm_Init has been called, the called function shall
*                   raise development error PWM_E_UNINIT.
*
* @param[in]        ChannelNumber - pwm channel id
* @param[in]        Period        - pwm signal period value
* @param[in]        DutyCycle     - pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return           void
*
* @api
*
* @implements       DPWM01010, DPWM02037
*
*/

/*
* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC (void, PWM_CODE) Pwm_SetPeriodAndDuty(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber,
        VAR(Pwm_PeriodType, AUTOMATIC)  Period,
        VAR(uint16, AUTOMATIC)          DutyCycle
    )
{
    if (NULL_PTR != Pwm_Cfg_Ptr)
    {
/* @implements DPWM01023 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        if (ChannelNumber >= Pwm_Cfg_Ptr->ChannelCount)
        {

            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_SETPERIODANDDUTY_ID,
                (uint8) PWM_E_PARAM_CHANNEL
            );
        }
        else if (DutyCycle > PWM_DUTY_CYCLE_100)
        {

            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_SETPERIODANDDUTY_ID,
                (uint8) PWM_E_DUTYCYCLE_RANGE
            );
        }
        else if
        (
            /* @violates @ref Pwm_C_REF_2 pointer arithmetic other than array indexing used */
            PWM_VARIABLE_PERIOD != Pwm_Cfg_Ptr->ChannelsPtr[ChannelNumber].Pwm_ChannelClassValue
        )
        {

            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_SETPERIODANDDUTY_ID,
                (uint8) PWM_E_PERIOD_UNCHANGEABLE
            );
        }
        else
        {
#endif /* PWM_DEV_ERROR_DETECT */

            Pwm_LLD_SetPeriodAndDuty( ChannelNumber, Period, DutyCycle  );
        }
/* @implements DPWM01023 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {

        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_SETPERIODANDDUTY_ID,
            (uint8) PWM_E_UNINIT
        );
    }
#endif /* PWM_DEV_ERROR_DETECT */

}
#endif /* PWM_SET_PERIOD_AND_DUTY_API */


/*===============================================================================================*/
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/**
* @brief            This function sets the generated pwm signal to the idle value configured.
* @details          The function Pwm_SetOutputToIdle shall set immediately the
*                   PWM output to the configured Idle state.
*
*                   If development error detection for the Pwm module is enabled, the PWM functions
*                   shall check the parameter ChannelNumber and raise development error PWM_E_PARAM_CHANNEL
*                   if the parameter ChannelNumber is invalid.
*
*                   If development error detection for the Pwm module is enabled, when a
*                   development error occurs, the corresponding PWM function shall:
*                       - Report the error to the Development Error Tracer.
*                       - Skip the desired functionality in order to avoid any corruptions of data
*                           or hardware registers (this means leave the function without any actions).
*
*                   If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*                   The detailed description of the detected errors can be found in chapter
*                   Error classification and chapter API specification (see PWM_SWS).
*
*                   After the call of the function Pwm_SetOutputToIdle, variable period type channels
*                   shall be reactivated either using the Api Pwm_SetPeriodAndDuty() to activate
*                   the PWM channel with the new passed period or Api Pwm_SetDutyCycle() to activate
*                   the PWM channel with the old period.
*
*                   After the call of the function Pwm_SetOutputToIdle, fixed period type channels
*                   shall be reactivated using only the API Api Pwm_SetDutyCycle() to activate
*                   the PWM channel with the old period.
*
*                   If development error detection for the Pwm module is enabled, if any function
*                   (except Pwm_Init) is called before Pwm_Init has been called, the called function
*                   shall raise development error PWM_E_UNINIT.
*
* @param[in]        ChannelNumber - pwm channel id
*
* @return           void
*
* @api
*
* @implements       DPWM01009, DPWM02036
*
*/
/*
* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC (void, PWM_CODE) Pwm_SetOutputToIdle(VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber)
{
    if (NULL_PTR != Pwm_Cfg_Ptr)
    {
/* @implements DPWM01022 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        if (ChannelNumber >= Pwm_Cfg_Ptr->ChannelCount)
        {

            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_SETOUTPUTTOIDLE_ID,
                (uint8) PWM_E_PARAM_CHANNEL
            );
        }
        else
        {
#endif /* PWM_DEV_ERROR_DETECT */
            Pwm_LLD_SetOutputToIdle( ChannelNumber );
        }
/* @implements DPWM01022 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {

        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_SETOUTPUTTOIDLE_ID,
            (uint8) PWM_E_UNINIT
        );
    }
#endif /* PWM_DEV_ERROR_DETECT */

}
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */


/*===============================================================================================*/
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief            This function returns the signal output state.
* @details          The function Pwm_GetOutputState shall read the internal state of
*                   the PWM output signal and return it as defined in the diagram below (see PWM_SWS).
*
*                   If development error detection for the Pwm module is enabled,
*                   the PWM functions shall check the parameter ChannelNumber and
*                   raise development error PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
*
*                   If development error detection for the Pwm module is enabled, when a
*                   development error occurs, the corresponding PWM function shall:
*                      - Report the error to the Development Error Tracer.
*                      - Skip the desired functionality in order to avoid any corruptions of
*                           data or hardware registers (this means leave the function without any actions).
*                      - Return pwm level low for the function Pwm_GetOutputState.
*
*                   If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*                   The detailed description of the detected errors can be found in chapter
*                   Error classification and chapter API specification (see PWM_SWS).
*
*                   Due to real time constraint and setting of the PWM channel (project dependant),
*                   the output state can be modified just after the call of the service Pwm_GetOutputState.
*
*                   If development error detection for the Pwm module is enabled, if any function
*                   (except Pwm_Init) is called before Pwm_Init has been called, the called function
*                   shall raise development error PWM_E_UNINIT.
*
* @param[in]        ChannelNumber - pwm channel id
*
* @return           Pwm_OutputStateType  pwm signal output logic value
* @retval           PWM_LOW -  The output state of PWM channel is low
* @retval           PWM_HIGH - The output state of PWM channel is high
*
* @api
*
* @implements       DPWM01004, DPWM02031
*
* @note             Due to hardware limitation this function will always return PWM_LOW
*
*/

/*
* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC (Pwm_OutputStateType, PWM_CODE) Pwm_GetOutputState(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber
    )
{
    VAR(Pwm_OutputStateType, AUTOMATIC) tempReturn=PWM_LOW;

    if (NULL_PTR != Pwm_Cfg_Ptr)
    {
/* @implements DPWM01018 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        if (ChannelNumber >= Pwm_Cfg_Ptr->ChannelCount)
        {

            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_GETOUTPUTSTATE_ID,
                (uint8) PWM_E_PARAM_CHANNEL
            );
        }
        else
        {
#endif /* PWM_DEV_ERROR_DETECT */
            tempReturn = Pwm_LLD_GetOutputState( ChannelNumber );
        }
/* @implements DPWM01018 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {

        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_GETOUTPUTSTATE_ID,
            (uint8) PWM_E_UNINIT
        );
    }
#endif /* PWM_DEV_ERROR_DETECT */
    return (tempReturn);
}
#endif /* PWM_GET_OUTPUT_STATE_API */


/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief            This function disables the user notifications.
* @details          If development error detection for the Pwm module is enabled:
*                   - The PWM functions shall check the parameter ChannelNumber and raise
*                   development error PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
*
*                   If development error detection for the Pwm module is enabled,
*                   when a development error occurs, the corresponding PWM function shall:
*                   - Report the error to the Development Error Tracer.
*                   - Skip the desired functionality in order to avoid any corruptions of
*                      data or hardware registers (this means leave the function without any actions).
*                   - Return pwm level low for the function Pwm_GetOutputState.
*
*                   If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*                   The detailed description of the detected errors can be found in chapter
*                   Error classification and chapter API specification (see PWM_SWS).
*
*                    All functions from the PWM module except Pwm_Init, Pwm_DeInit and Pwm_GetVersionInfo
*                   shall be re-entrant for different PWM channel numbers. In order to keep a simple module
*                   implementation, no check of PWM088 must be performed by the module.
*                   The function Pwm_DisableNotification shall be pre compile time configurable On/Off by the
*                   configuration parameter: PwmNotificationSupported.
*
*                   If development error detection for the Pwm module is enabled, if any function
*                   (except Pwm_Init) is called before Pwm_Init has been called, the called function shall
*                   raise development error PWM_E_UNINIT.
*
* @param[in]        ChannelNumber - pwm channel id
*
* @return           void
*
* @api
*
* @implements     DPWM01002, DPWM02029
*
*/

/*
* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC (void, PWM_CODE) Pwm_DisableNotification(VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber)
{
    if (NULL_PTR != Pwm_Cfg_Ptr)
    {
/* @implements DPWM01015 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        if (ChannelNumber >= Pwm_Cfg_Ptr->ChannelCount)
        {

            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_DISABLENOTIFICATION_ID,
                (uint8) PWM_E_PARAM_CHANNEL
            );
        }
        else
        {
#endif /* PWM_DEV_ERROR_DETECT */
            Pwm_LLD_DisableNotification( ChannelNumber );
        }
/* @implements DPWM01015 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {

        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_DISABLENOTIFICATION_ID,
            (uint8) PWM_E_UNINIT
        );
    }
#endif /* PWM_DEV_ERROR_DETECT */
}
#endif /* PWM_NOTIFICATION_SUPPORTED */


/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief            This function enables the user notifications.
* @details          The function Pwm_EnableNotification shall enable the PWM signal edge notification
*                   according to notification parameter.
*                   If development error detection for the Pwm module is enabled:
*                   - The PWM functions shall check the parameter ChannelNumber and raise
*                   development error PWM_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
*
*                   If development error detection for the Pwm module is enabled, when a development error
*                   occurs, the corresponding PWM function shall:
*
*                       - Report the error to the Development Error Tracer.
*                       - Skip the desired functionality in order to avoid any corruptions of
*                           data or hardware registers (this means leave the function without any actions).
*                       - Return pwm level low for the function Pwm_GetOutputState.
*
*                   If the PwmDevErorDetect switch is enabled, API parameter checking is enabled.
*                   The detailed description of the detected errors can be found in chapter
*                   Error classification and chapter API specification (see PWM_SWS).
*
*                   If development error detection for the Pwm module is enabled, if any function
*                   (except Pwm_Init) is called before Pwm_Init has been called, the called function
*                   shall raise development error PWM_E_UNINIT.
*
* @param[in]        ChannelNumber - pwm channel id
* @param[in]        Notification  - notification type to be enabled
*
* @return           void
*
* @api
*
* @implements     DPWM01003, DPWM02030
*
*/
/*
* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC (void, PWM_CODE) Pwm_EnableNotification(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber,
        VAR(Pwm_EdgeNotificationType, AUTOMATIC) Notification
    )
{
    if (NULL_PTR != Pwm_Cfg_Ptr)
    {
/* @implements DPWM01016 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        if (ChannelNumber >= Pwm_Cfg_Ptr->ChannelCount)
        {

            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_ENABLENOTIFICATION_ID,
                (uint8) PWM_E_PARAM_CHANNEL
            );
        }
        /* @violates @ref Pwm_C_REF_2 pointer arithmetic other than array indexing used */
        else if (NULL_PTR == Pwm_Cfg_Ptr->ChannelsPtr[ChannelNumber].Pwm_Channel_Notification)
        {
            /* if the configured notification for this channel is NULL_PTR but
            EnalbeNotification is still called then report the error */

            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_ENABLENOTIFICATION_ID,
                (uint8) PWM_E_PARAM_NOTIFICATION_NULL
            );
        }
        else
        {
#endif /* PWM_DEV_ERROR_DETECT */
            Pwm_LLD_EnableNotification( ChannelNumber, Notification );
        }
/* @implements DPWM01016 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {

        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_ENABLENOTIFICATION_ID,
            (uint8) PWM_E_UNINIT
        );
    }
#endif /* PWM_DEV_ERROR_DETECT */
}
#endif /* PWM_NOTIFICATION_SUPPORTED */


/*===============================================================================================*/
#if (PWM_VERSION_INFO_API == STD_ON)
/**
* @brief            This function returns Pwm driver version details
* @details          The function Pwm_GetVersionInfo shall return the version information of this module.
*                   The version information includes: Module Id, Vendor Id, Vendor specific version number.
*
* @param[in,out]    versioninfo - pointer to Std_VersionInfoType output variable
*
* @return           void
*
* @api
*
* @implements     DPWM01005, DPWM02032
*
*/
/*
* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC(void, PWM_CODE) Pwm_GetVersionInfo(
        P2VAR(Std_VersionInfoType , AUTOMATIC, PWM_APPL_DATA) versioninfo
    )
{


#if (PWM_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != versioninfo)
    {
#endif /* PWM_DEV_ERROR_DETECT */

        (versioninfo)->vendorID         = (uint16)PWM_VENDOR_ID;
        (versioninfo)->moduleID         = (uint16)PWM_MODULE_ID;

        (versioninfo)->sw_major_version = (uint8)PWM_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)PWM_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)PWM_SW_PATCH_VERSION;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        /* if the parameter versioninfo is NULL_PTR then report the error */

        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_GETVERSIONINFO_ID,
            (uint8) PWM_E_PARAM_POINTER
        );
    }
#endif /* PWM_DEV_ERROR_DETECT */
}
#endif /* PWM_VERSION_INFO_API */

/**
* @brief            This function will enter critical section
* @details          
*
*/
/*
* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC (void, PWM_CODE) Pwm_Schm_ProtectResource(VAR(uint8, AUTOMATIC) Pwm_ExclusiveArea) 
{
    switch ( Pwm_ExclusiveArea)
    {
    case 0:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_00();
        break;        
#if ( 1U < PWM_MAX_CHANNELS)    
    case 1:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_01();
        break;        
#endif    
#if ( 2U < PWM_MAX_CHANNELS )    
    case 2:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_02();
        break;  
#endif    
#if ( 3U < PWM_MAX_CHANNELS )  
    case 3:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_03();
        break;  
#endif    
#if ( 4U < PWM_MAX_CHANNELS )  
    case 4:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_04();
        break;        
#endif    
#if ( 5U < PWM_MAX_CHANNELS )  
    case 5:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_05();
        break;        
#endif    
#if ( 6U < PWM_MAX_CHANNELS )   
    case 6:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_06();
        break;        
#endif    
#if ( 7U < PWM_MAX_CHANNELS )   
    case 7:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_07();
        break;        
#endif    
#if ( 8U < PWM_MAX_CHANNELS )  
    case 8:
       SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_08();
       break;        
#endif    
#if ( 9U < PWM_MAX_CHANNELS )  
    case 9:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_09();
        break;        
#endif    
#if ( 10U < PWM_MAX_CHANNELS )  
    case 10:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_10();
        break;        
#endif    
#if ( 11U < PWM_MAX_CHANNELS )  
    case 11:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_11();
        break;        
#endif    
#if ( 12U < PWM_MAX_CHANNELS )  
    case 12:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_12();
        break;        
#endif    
#if ( 13U < PWM_MAX_CHANNELS )  
    case 13:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_13();
        break;        
#endif    
#if ( 14U < PWM_MAX_CHANNELS )  
    case 14:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_14();
        break;        
#endif    
#if ( 15U < PWM_MAX_CHANNELS )  
    case 15:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_15();
        break;        
#endif    
#if ( 16U < PWM_MAX_CHANNELS )  
    case 16:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_16();
        break;        
#endif    
#if ( 17U < PWM_MAX_CHANNELS )  
    case 17:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_17();
        break;        
#endif    
#if ( 18U < PWM_MAX_CHANNELS )  
    case 18:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_18();
        break;        
#endif    
#if ( 19U < PWM_MAX_CHANNELS )  
    case 19:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_19();
        break;        
#endif    
#if ( 20U < PWM_MAX_CHANNELS )  
    case 20:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_20();
        break;        
#endif    
#if ( 21U < PWM_MAX_CHANNELS )  
    case 21:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_21();
        break;        
#endif    
#if ( 22U < PWM_MAX_CHANNELS )  
    case 22:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_22();
        break;        
#endif    
#if ( 23U < PWM_MAX_CHANNELS )  
    case 23:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_23();
        break;        
#endif    
#if ( 24U < PWM_MAX_CHANNELS )  
    case 24:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_24();
        break;        
#endif    
#if ( 25U < PWM_MAX_CHANNELS )  
    case 25:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_25();
        break;        
#endif    
#if ( 26U < PWM_MAX_CHANNELS )  
    case 26:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_26();
        break;        
#endif    
#if ( 27U < PWM_MAX_CHANNELS )  
    case 27:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_27();
        break;        
#endif    
#if ( 28U < PWM_MAX_CHANNELS )  
    case 28:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_28();
        break;        
#endif    
#if ( 29U < PWM_MAX_CHANNELS )  
    case 29:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_29();
        break;        
#endif    
#if ( 30U < PWM_MAX_CHANNELS )  
    case 30:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_30();
        break;        
#endif    
#if ( 31U < PWM_MAX_CHANNELS )  
    case 31:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_31();
        break;        
#endif    
#if ( 32U < PWM_MAX_CHANNELS )  
    case 32:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_32();
        break;        
#endif    
#if ( 33U < PWM_MAX_CHANNELS )  
    case 33:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_33();
        break;        
#endif    
#if ( 34U < PWM_MAX_CHANNELS )  
    case 34:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_34();
        break;        
#endif    
#if ( 35U < PWM_MAX_CHANNELS )  
    case 35:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_35();
        break;        
#endif    
#if ( 36U < PWM_MAX_CHANNELS )  
    case 36:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_36();
        break;        
#endif    
#if ( 37U < PWM_MAX_CHANNELS )  
    case 37:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_37();
        break;        
#endif    
#if ( 38U < PWM_MAX_CHANNELS )  
    case 38:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_38();
        break;        
#endif    
#if ( 39U < PWM_MAX_CHANNELS )  
    case 39:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_39();
        break;        
#endif    
#if ( 40U < PWM_MAX_CHANNELS )  
    case 40:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_40();
        break;        
#endif    
#if ( 41U < PWM_MAX_CHANNELS )  
    case 41:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_41();
        break;        
#endif    
#if ( 42U < PWM_MAX_CHANNELS )  
    case 42:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_42();
        break;        
#endif    
#if ( 43U < PWM_MAX_CHANNELS )  
    case 43:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_43();
        break;        
#endif    
#if ( 44U < PWM_MAX_CHANNELS )  
    case 44:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_44();
        break;        
#endif    
#if ( 45U < PWM_MAX_CHANNELS )  
    case 45:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_45();
        break;        
 #endif    
#if ( 46U < PWM_MAX_CHANNELS )  
    case 46:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_46();
        break;        
#endif    
#if ( 47U < PWM_MAX_CHANNELS )  
    case 47:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_47();
        break;        
#endif    
#if ( 48U < PWM_MAX_CHANNELS )  
    case 48:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_48();
        break;        
#endif    
#if ( 49U < PWM_MAX_CHANNELS )  
    case 49:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_49();
        break;        
#endif    
#if ( 50U < PWM_MAX_CHANNELS )  
    case 50:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_50();
        break;        
#endif    
#if ( 51U < PWM_MAX_CHANNELS )  
    case 51:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_51();
        break;        
#endif    
#if ( 52U < PWM_MAX_CHANNELS )  
    case 52:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_52();
        break;        
#endif    
#if ( 53U < PWM_MAX_CHANNELS )  
    case 53:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_53();
        break;        
#endif    
#if ( 54U < PWM_MAX_CHANNELS )  
    case 54:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_54();
        break;        
#endif    
#if ( 55U < PWM_MAX_CHANNELS )  
    case 55:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_55();
        break;        
#endif    
#if ( 56U < PWM_MAX_CHANNELS )  
    case 56:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_56();
        break;        
#endif    
#if ( 57U < PWM_MAX_CHANNELS )  
    case 57:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_57();
        break;        
#endif    
#if ( 58U < PWM_MAX_CHANNELS )  
    case 58:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_58();
        break;        
#endif    
#if ( 59U < PWM_MAX_CHANNELS )  
    case 59:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_59();
        break;        
#endif    
#if ( 60U < PWM_MAX_CHANNELS )  
    case 60:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_60();
        break;        
#endif    
#if ( 62U < PWM_MAX_CHANNELS )  
    case 61:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_61();
        break;        
#endif    
#if ( 62U < PWM_MAX_CHANNELS )  
    case 62:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_62();
        break;        
#endif    
#if ( 63U < PWM_MAX_CHANNELS )  
    case 63:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_63();
        break;        
#endif    
#if ( 64U < PWM_MAX_CHANNELS )  
    case 64:
        SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_64();
        break;   
#endif    
    default:
        Cer_ReportError((uint16)PWM_MODULE_ID,(uint8)0,(uint8)PWM_SCHM_PROTECTRESOURCE_ID,(uint8)0);
        /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
        *                    Cer_ReportError() function implementation 
        */
        break; 
    }
}

/**
* @brief            This function will exit critical section
* @details          
*
*/
/*
* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC (void, PWM_CODE) Pwm_Schm_UnprotectResource(VAR(uint8, AUTOMATIC) Pwm_ExclusiveArea) 
{
    switch ( Pwm_ExclusiveArea)
    {
    case 0:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_00();
        break;        
#if ( 1U < PWM_MAX_CHANNELS)    
    case 1:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_01();
        break;        
#endif    
#if ( 2U < PWM_MAX_CHANNELS )    
    case 2:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_02();
        break;  
#endif    
#if ( 3U < PWM_MAX_CHANNELS )  
    case 3:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_03();
        break;  
#endif    
#if ( 4U < PWM_MAX_CHANNELS )  
    case 4:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_04();
        break;        
#endif    
#if ( 5U < PWM_MAX_CHANNELS )  
    case 5:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_05();
        break;        
#endif    
#if ( 6U < PWM_MAX_CHANNELS )   
    case 6:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_06();
        break;        
#endif    
#if ( 7U < PWM_MAX_CHANNELS )   
    case 7:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_07();
        break;        
#endif    
#if ( 8U < PWM_MAX_CHANNELS )  
    case 8:
       SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_08();
       break;        
#endif    
#if ( 9U < PWM_MAX_CHANNELS )  
    case 9:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_09();
        break;        
#endif    
#if ( 10U < PWM_MAX_CHANNELS )  
    case 10:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_10();
        break;        
#endif    
#if ( 11U < PWM_MAX_CHANNELS )  
    case 11:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_11();
        break;        
#endif    
#if ( 12U < PWM_MAX_CHANNELS )  
    case 12:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_12();
        break;        
#endif    
#if ( 13U < PWM_MAX_CHANNELS )  
    case 13:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_13();
        break;        
#endif    
#if ( 14U < PWM_MAX_CHANNELS )  
    case 14:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_14();
        break;        
#endif    
#if ( 15U < PWM_MAX_CHANNELS )  
    case 15:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_15();
        break;        
#endif    
#if ( 16U < PWM_MAX_CHANNELS )  
    case 16:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_16();
        break;        
#endif    
#if ( 17U < PWM_MAX_CHANNELS )  
    case 17:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_17();
        break;        
#endif    
#if ( 18U < PWM_MAX_CHANNELS )  
    case 18:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_18();
        break;        
#endif    
#if ( 19U < PWM_MAX_CHANNELS )  
    case 19:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_19();
        break;        
#endif    
#if ( 20U < PWM_MAX_CHANNELS )  
    case 20:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_20();
        break;        
#endif    
#if ( 21U < PWM_MAX_CHANNELS )  
    case 21:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_21();
        break;        
#endif    
#if ( 22U < PWM_MAX_CHANNELS )  
    case 22:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_22();
        break;        
#endif    
#if ( 23U < PWM_MAX_CHANNELS )  
    case 23:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_23();
        break;        
#endif    
#if ( 24U < PWM_MAX_CHANNELS )  
    case 24:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_24();
        break;        
#endif    
#if ( 25U < PWM_MAX_CHANNELS )  
    case 25:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_25();
        break;        
#endif    
#if ( 26U < PWM_MAX_CHANNELS )  
    case 26:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_26();
        break;        
#endif    
#if ( 27U < PWM_MAX_CHANNELS )  
    case 27:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_27();
        break;        
#endif    
#if ( 28U < PWM_MAX_CHANNELS )  
    case 28:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_28();
        break;        
#endif    
#if ( 29U < PWM_MAX_CHANNELS )  
    case 29:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_29();
        break;        
#endif    
#if ( 30U < PWM_MAX_CHANNELS )  
    case 30:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_30();
        break;        
#endif    
#if ( 31U < PWM_MAX_CHANNELS )  
    case 31:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_31();
        break;        
#endif    
#if ( 32U < PWM_MAX_CHANNELS )  
    case 32:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_32();
        break;        
#endif    
#if ( 33U < PWM_MAX_CHANNELS )  
    case 33:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_33();
        break;        
#endif    
#if ( 34U < PWM_MAX_CHANNELS )  
    case 34:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_34();
        break;        
#endif    
#if ( 35U < PWM_MAX_CHANNELS )  
    case 35:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_35();
        break;        
#endif    
#if ( 36U < PWM_MAX_CHANNELS )  
    case 36:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_36();
        break;        
#endif    
#if ( 37U < PWM_MAX_CHANNELS )  
    case 37:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_37();
        break;        
#endif    
#if ( 38U < PWM_MAX_CHANNELS )  
    case 38:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_38();
        break;        
#endif    
#if ( 39U < PWM_MAX_CHANNELS )  
    case 39:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_39();
        break;        
#endif    
#if ( 40U < PWM_MAX_CHANNELS )  
    case 40:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_40();
        break;        
#endif    
#if ( 41U < PWM_MAX_CHANNELS )  
    case 41:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_41();
        break;        
#endif    
#if ( 42U < PWM_MAX_CHANNELS )  
    case 42:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_42();
        break;        
#endif    
#if ( 43U < PWM_MAX_CHANNELS )  
    case 43:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_43();
        break;        
#endif    
#if ( 44U < PWM_MAX_CHANNELS )  
    case 44:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_44();
        break;        
#endif    
#if ( 45U < PWM_MAX_CHANNELS )  
    case 45:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_45();
        break;        
 #endif    
#if ( 46U < PWM_MAX_CHANNELS )  
    case 46:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_46();
        break;        
#endif    
#if ( 47U < PWM_MAX_CHANNELS )  
    case 47:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_47();
        break;        
#endif    
#if ( 48U < PWM_MAX_CHANNELS )  
    case 48:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_48();
        break;        
#endif    
#if ( 49U < PWM_MAX_CHANNELS )  
    case 49:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_49();
        break;        
#endif    
#if ( 50U < PWM_MAX_CHANNELS )  
    case 50:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_50();
        break;        
#endif    
#if ( 51U < PWM_MAX_CHANNELS )  
    case 51:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_51();
        break;        
#endif    
#if ( 52U < PWM_MAX_CHANNELS )  
    case 52:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_52();
        break;        
#endif    
#if ( 53U < PWM_MAX_CHANNELS )  
    case 53:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_53();
        break;        
#endif    
#if ( 54U < PWM_MAX_CHANNELS )  
    case 54:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_54();
        break;        
#endif    
#if ( 55U < PWM_MAX_CHANNELS )  
    case 55:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_55();
        break;        
#endif    
#if ( 56U < PWM_MAX_CHANNELS )  
    case 56:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_56();
        break;        
#endif    
#if ( 57U < PWM_MAX_CHANNELS )  
    case 57:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_57();
        break;        
#endif    
#if ( 58U < PWM_MAX_CHANNELS )  
    case 58:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_58();
        break;        
#endif    
#if ( 59U < PWM_MAX_CHANNELS )  
    case 59:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_59();
        break;        
#endif    
#if ( 60U < PWM_MAX_CHANNELS )  
    case 60:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_60();
        break;        
#endif    
#if ( 62U < PWM_MAX_CHANNELS )  
    case 61:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_61();
        break;        
#endif    
#if ( 62U < PWM_MAX_CHANNELS )  
    case 62:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_62();
        break;        
#endif    
#if ( 63U < PWM_MAX_CHANNELS )  
    case 63:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_63();
        break;        
#endif    
#if ( 64U < PWM_MAX_CHANNELS )  
    case 64:
        SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_64();
        break;   
#endif  
    default:
        Cer_ReportError((uint16)PWM_MODULE_ID,(uint8)0,(uint8)PWM_SCHM_UNPROTECTRESOURCE_ID,(uint8)0);
        /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
        *  Cer_ReportError() function implementation 
        */
        break; 
    }
}

#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm_C_REF_1 Only preprocessor statements and comments before "#include"
*/
/*
* @violates @ref Pwm_C_REF_5 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */


