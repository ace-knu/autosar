/**
*   @file    Pwm_NonASR.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Pwm - Pwm NonAutosar high level interface implementation.
*   @details Pwm NonAutosar high level interface implementation.
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
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Pwm_C_REF_3
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Pwm_C_REF_4
* Violates MISRA 2004 Required Rule 17.4, This violation is due to the use of pointer arithmetic,
* which is used for the speed optimization, the indexing of the pointer is taken care and hence the
* unintended memory location will not be accessed.
*
* @section Pwm_C_REF_5
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.

* @section Pwm_C_REF_6
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not be 
* implicitly converted to a different underlying type if: 
* a) it is not a conversion to a wider integer type of the same signedness, or 
* b) the expression is complex, or 
* c) the expression is not constant and is a function argument, or 
* d) the expression is not constant and is a return expression 
*
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
/**
* @{
* @file           Pwm_NonASR.c
* @implements     DPWM02203
* 
*/
#include "Pwm.h"
#include "Pwm_NonASR.h"
#include "Pwm_LLD.h"


#if (PWM_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif


/*===============================================================================================
*                                        SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Pwm_NonASR.c
* @implements     DPWM02512, DPWM02501, DPWM02502, DPWM02503, DPWM02509, DPWM02510, DPWM02511
*/
#define PWM_NONASR_C_VENDOR_ID                          43
/*
* @violates @ref Pwm_C_REF_5 This is required as per autosar Requirement, 
*/
#define PWM_NONASR_C_AR_RELEASE_MAJOR_VERSION           4
/*
* @violates @ref Pwm_C_REF_5 This is required as per autosar Requirement, 
*/
#define PWM_NONASR_C_AR_RELEASE_MINOR_VERSION           0
/*
* @violates @ref Pwm_C_REF_5 This is required as per autosar Requirement, 
*/
#define PWM_NONASR_C_AR_RELEASE_REVISION_VERSION        3
#define PWM_NONASR_C_SW_MAJOR_VERSION                   1
#define PWM_NONASR_C_SW_MINOR_VERSION                   0
#define PWM_NONASR_C_SW_PATCH_VERSION                   1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/


/* Check if source file and PWM header file are of the same vendor */
#if (PWM_NONASR_C_VENDOR_ID != PWM_VENDOR_ID)
    #error "Pwm_NonASR.c and Pwm.h have different vendor ids"
#endif

/* Check if source file and PWM header file are of the same Autosar version */
#if ((PWM_NONASR_C_AR_RELEASE_MAJOR_VERSION != PWM_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_NONASR_C_AR_RELEASE_MINOR_VERSION != PWM_AR_RELEASE_MINOR_VERSION) || \
        (PWM_NONASR_C_AR_RELEASE_REVISION_VERSION != PWM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_NonASR.c and Pwm.h are different"
#endif

/* Check if source file and PWM header file are of the same Software version */
#if ((PWM_NONASR_C_SW_MAJOR_VERSION != PWM_SW_MAJOR_VERSION)  || \
        (PWM_NONASR_C_SW_MINOR_VERSION != PWM_SW_MINOR_VERSION)  || \
        (PWM_NONASR_C_SW_PATCH_VERSION != PWM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_NonASR.c and Pwm.h are different"
#endif



/* Check if source file and Pwm_NonASR.h are of the same vendor */
#if (PWM_NONASR_C_VENDOR_ID != PWM_NONASR_H_VENDOR_ID)
    #error "Pwm_NonASR.c and Pwm_NonASR.h have different vendor ids"
#endif

/* Check if source file and Pwm_NonASR.h are of the same Autosar version */
#if ((PWM_NONASR_C_AR_RELEASE_MAJOR_VERSION != PWM_NONASR_H_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_NONASR_C_AR_RELEASE_MINOR_VERSION != PWM_NONASR_H_AR_RELEASE_MINOR_VERSION) || \
        (PWM_NONASR_C_AR_RELEASE_REVISION_VERSION != PWM_NONASR_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_NonASR.c and Pwm_NonASR.h are different"
#endif

/* Check if source file and Pwm_NonASR.h are of the same Software version */
#if ((PWM_NONASR_C_SW_MAJOR_VERSION != PWM_NONASR_H_SW_MAJOR_VERSION) || \
        (PWM_NONASR_C_SW_MINOR_VERSION != PWM_NONASR_H_SW_MINOR_VERSION) || \
        (PWM_NONASR_C_SW_PATCH_VERSION != PWM_NONASR_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_NonASR.c and Pwm_NonASR.h are different"
#endif



/* Check if source file and PWM LLD header file are of the same vendor */
#if (PWM_NONASR_C_VENDOR_ID != PWM_LLD_H_VENDOR_ID)
    #error "Pwm_NonASR.c and Pwm.h have different vendor ids"
#endif

    /* Check if source file and PWM LLD header file are of the same Autosar version */
#if ((PWM_NONASR_C_AR_RELEASE_MAJOR_VERSION != PWM_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_NONASR_C_AR_RELEASE_MINOR_VERSION != PWM_LLD_H_AR_RELEASE_MINOR_VERSION) || \
        (PWM_NONASR_C_AR_RELEASE_REVISION_VERSION != PWM_LLD_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_NonASR.c and Pwm.h are different"
#endif

/* Check if source file and PWM LLD header file are of the same Software version */
#if ((PWM_NONASR_C_SW_MAJOR_VERSION != PWM_LLD_H_SW_MAJOR_VERSION) || \
        (PWM_NONASR_C_SW_MINOR_VERSION != PWM_LLD_H_SW_MINOR_VERSION) || \
        (PWM_NONASR_C_SW_PATCH_VERSION != PWM_LLD_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_NonASR.c and Pwm.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    /* Check if source file and DET header file are of the same version */
    #if ((PWM_NONASR_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
            (PWM_NONASR_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Pwm_NonASR.c and Det.h are different"
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

/*===============================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
===============================================================================================*/

/*===============================================================================================
*                                       LOCAL FUNCTIONS
===============================================================================================*/

/*===============================================================================================
*                                       GLOBAL FUNCTIONS
===============================================================================================*/
/*
* @violates @ref Pwm_LLD_C_REF_1 Only preprocessor statements and comments before "#include"
*/
#define PWM_START_SEC_CODE
/*
* @violates @ref Pwm_C_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"
/*===============================================================================================*/
#ifdef PWM_SETCOUNTERBUS_API
#if (PWM_SETCOUNTERBUS_API == STD_ON)
/**
* @brief            function to change the frequency of pwm channels running on PWM_MODE_OPWMB or PWM_MODE_OPWMT mode.
* @details          This function is useful to change the frequency of the output PWM signal between
*                   two counter buses frequency
*
* @param[in]        ChannelNumber - pwm channel id
* @param[in]        Bus           - the eMIOS bus to change to
*
* @implements       DPWM01026, DPWM02515
*
*/
/*
* @violates @ref Pwm_C_REF_3 The respective code could not be made static because
*  of layers architecture design of the driver
*/
FUNC (void, PWM_CODE) Pwm_SetCounterBus(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber,
        VAR(uint32, AUTOMATIC) Bus
    )
{
/* @implements DPWM01027 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)

    if (Pwm_Cfg_Ptr == NULL_PTR)
    {

        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_SETCOUNTERBUS_ID,
            (uint8) PWM_E_UNINIT
        );
    }
    else if (ChannelNumber >= Pwm_Cfg_Ptr->ChannelCount)
    {

        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_SETCOUNTERBUS_ID,
            (uint8) PWM_E_PARAM_CHANNEL
        );
    }
    else if ((Bus != PWM_BUS_A) && (Bus != PWM_BUS_DIVERSE))
    {

        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_SETCOUNTERBUS_ID,
            (uint8) PWM_E_COUNTERBUS
        );
    } else
#endif /* PWM_DEV_ERROR_DETECT */
    {
        Pwm_LLD_SetCounterBus( ChannelNumber, Bus );
    }

}
#endif
#endif /* PWM_SETCOUNTERBUS_API */


/*===============================================================================================*/
#ifdef PWM_SETCHANNELOUTPUT_API
#if (PWM_SETCHANNELOUTPUT_API == STD_ON)
/**
* @brief            function to set the state of the PWM pin as requested for the current cycle
* @details          This function is useful to set the state of the PWM pin as requested
*                   for the current cycle and continues with normal PWM operation from the next cycle
*
* @param[in]        ChannelNumber - pwm channel id
* @param[in]        State         - Active/Inactive state of the channel
*
* @implements       DPWM02513
*
*/
/*
* @violates @ref Pwm_C_REF_3 The respective code could not be made static because
*  of layers architecture design of the driver
*/
FUNC (void, PWM_CODE) Pwm_SetChannelOutput(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber,
        VAR(Pwm_StateType, AUTOMATIC) State
    )
{

#if (PWM_DEV_ERROR_DETECT == STD_ON)

    if (Pwm_Cfg_Ptr == NULL_PTR)
    {
        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_SETCHANNELOUTPUT_ID,
            (uint8) PWM_E_UNINIT
        );
    }
    else if (ChannelNumber >= Pwm_Cfg_Ptr->ChannelCount)
    {
        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_SETCHANNELOUTPUT_ID,
            (uint8) PWM_E_PARAM_CHANNEL
        );
    } else
#endif /* PWM_DEV_ERROR_DETECT */
    {
        Pwm_LLD_SetChannelOutput( ChannelNumber, State );
    }
}
#endif
#endif /* PWM_SETCHANNELOUTPUT_API */


/*===============================================================================================*/
#ifdef PWM_DUAL_CLOCK_MODE
#if (PWM_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief            Implementation specific function to change the peripheral clock frequency.
* @details          This function is useful to set the prescalers that divide the PWM channels
*                   clock frequency.
*
* @param[in]        Prescaler - prescaler type
*
* @implements       DPWM02514, DPWM01007
*
*/
/* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC (void, PWM_CODE) Pwm_SetClockMode(VAR(Pwm_SelectPrescalerType, AUTOMATIC) Prescaler)
{
/* @implements DPWM01020 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)

        if (Pwm_Cfg_Ptr == NULL_PTR)
        {
            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_SETCLOCKMODE_ID,
                (uint8) PWM_E_UNINIT
            );
        }
        else
#endif /* PWM_DEV_ERROR_DETECT */
        {
            Pwm_LLD_SelectPrescaler(Prescaler);
        }
}
#endif
#endif /* PWM_DUAL_CLOCK_MODE */

/*===============================================================================================*/
#ifdef PWM_FEATURE_OPWMT
    #if (PWM_FEATURE_OPWMT == STD_ON)
    
#ifdef PWM_SET_TRIGGER_DELAY_API
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
/**
* @brief      Implementation specific function to change the trigger delay
* @details    This function is useful to set the trigger delay to opwmt mode
*    If no DET error reported then the trigger delay for  the PWM channels will be set.
*    If development error detection for the Pwm module is enabled:
*    Report the error to the Development Error Tracer.
*    Skip the desired functionality in order to avoid any corruptions of
*   data or hardware registers: This means leave the function without any actions.
*
* @param[in] ChannelNumber - pwm channel id
* @param[in] TriggerDelay         - triggerdelay
* @implements DPWM01024, DPWM02522
*
*/
/* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC (void, PWM_CODE) Pwm_SetTriggerDelay
                        (
                              VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber,
                              VAR(uint16, AUTOMATIC) TriggerDelay
                        )
{
/* @implements DPWM01025 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)

        if (NULL_PTR == Pwm_Cfg_Ptr)
        {
            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_SETTRIGGERDELAY_ID,
                (uint8) PWM_E_UNINIT
            );
        }
        else if (ChannelNumber >= Pwm_Cfg_Ptr->ChannelCount)
        {

            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_SETTRIGGERDELAY_ID,
                (uint8) PWM_E_PARAM_CHANNEL
            );
        }
        else if
            (
                 /* @violates @ref Pwm_C_REF_4 pointer arithmetic other than array indexing used */
                (Pwm_Cfg_Ptr->ChannelsPtr[ChannelNumber].SpecificCfg.EmiosCfg.Pwm_ParamValue
                   &
                CCR_MODE_MASK) != CCR_MODE_OPWMT
            )
        {
            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_SETTRIGGERDELAY_ID,
                (uint8) PWM_E_PARAM_CHANNEL
            );
        }
        else
#endif /* PWM_DEV_ERROR_DETECT */
        {
            /* @violates @ref Pwm_C_REF_6 The value of an expression of integer type shall not be 
               implicitly converted to a different underlying type */
            Pwm_LLD_SetTriggerDelay(ChannelNumber,TriggerDelay);
        }
}
#endif
#endif/*PWM_SET_TRIGGER_DELAY_API*/

#endif
#endif/*PWM_FEATURE_OPWMT*/
/*===============================================================================================*/
#ifdef PWM_SET_DUTY_CYCLE_NOUPDATE_API
#if (PWM_SET_DUTY_CYCLE_NOUPDATE_API == STD_ON)
/**
* @brief       Implementation specific function to change the dutycycle value synchronously.
* @details     This function sets the dutycycle and/or period for the specified FlexPwm channel.
*
*
* @param[in]   ChannelNumber   pwm channel id
* @param[in]   DutyCycle       pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return      void
*
* @implements DPWM02527
*
*
*/
/* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC (void, PWM_CODE) Pwm_SetDutyCycle_NoUpdate(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber,
        VAR(uint16, AUTOMATIC) DutyCycle
    )
{
    if (NULL_PTR != Pwm_Cfg_Ptr)
    {
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
            Pwm_LLD_SetDutyCycle_NoUpdate(ChannelNumber, DutyCycle);
        }
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
#endif
#endif  /* PWM_SET_DUTY_CYCLE_NOUPDATE_API */


/*===============================================================================================*/
#ifdef PWM_SET_PERIOD_DUTY_NOUPDATE_API
#if (PWM_SET_PERIOD_DUTY_NOUPDATE_API == STD_ON)

/**
* @brief       Implementation specific function to change the dutycycle and period value for the
*              specified FlexPwm channel to the buffered register.
* @details     If the period is set to zero the setting of the duty-cycle is not relevant.
*              In this case the output shall be zero (zero percent duty-cycle).
*
* @param[in]   ChannelNumber   pwm channel id
* @param[in]   Period          pwm signal period value
* @param[in]   DutyCycle       pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return      void
*
* @implements DPWM02521
*
*/
/* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC (void, PWM_CODE) Pwm_SetPeriodAndDuty_NoUpdate(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber,
        VAR(Pwm_PeriodType, AUTOMATIC)  Period,
        VAR(uint16, AUTOMATIC)          DutyCycle
    )
{
    if (NULL_PTR != Pwm_Cfg_Ptr)
    {
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
            /* @violates @ref Pwm_C_REF_4 pointer arithmetic other than array indexing used */
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

            Pwm_LLD_SetPeriodAndDuty_NoUpdate( ChannelNumber, Period, DutyCycle  );
        }

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
#endif
#endif /* PWM_SET_PERIOD_DUTY_NOUPDATE_API */

/*================================================================================================*/
#ifdef PWM_SYNC_UPDATE
#if (PWM_SYNC_UPDATE == STD_ON)

/**
* @brief       Implementation specific function to updates the LDOK bits of flexpwm submodules.
*
* @details     This function is used to update the LDOK bits of Flex PWM channels of all the
*              submodules synchronously, this should be called after calling
*              Pwm_SetPeriodAndDuty_NoUpdate() or Pwm_SetDutyCycle_NoUpdate() API.
*              example:- For Submodule 0 MaskValue is 1
*                        For Submodule 0 and Submodule 1 MaskValue is 3
*                        For Submodule 0, Submodule 1 and Submodule 2 MaskValue is 7
*                        For Submodule 0, Submodule 1, Submodule 2 and Submodule 3 MaskValue is 15
*                        For Module value 0 means FlexPWM0
*                        For Module value 1 means FlexPWM1
*
* @param[in]   Module    pwm module id
* @param[in]   MaskValue pwm submodule mask value
*
* @return      void
*
* @implements  DPWM02526
*
*/
/* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC (void, PWM_CODE) Pwm_SyncUpdate(
            VAR(Pwm_ModuleType,AUTOMATIC)Module,
            VAR(uint16,AUTOMATIC)MaskValue
        )
{
   if (NULL_PTR != Pwm_Cfg_Ptr)
    {
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    if (Module > PWM_FLEXPWM_NO)
    {
          Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_SETPERIODANDDUTY_ID,
                (uint8) PWM_E_PARAM_CHANNEL
            );
    }
    else
    {
#endif /* PWM_DEV_ERROR_DETECT */
     Pwm_LLD_SyncUpdate( Module, MaskValue );
    }
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
#endif
#endif /* PWM_SYNC_UPDATE */

/*===============================================================================================*/

#ifdef MULTI_PWM_CHANNEL_SYNCH
#if (MULTI_PWM_CHANNEL_SYNCH == STD_ON)
/**
@brief   Implementation specific function to enable/disable the buffer transfer.

@details This function is useful to enable/disable the buffer transfer to synchronize multiple
         PWM channels.

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
/* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC (void, PWM_CODE) Pwm_BufferTransferEnableDisable
                             (
                                 VAR(uint8, AUTOMATIC) ModuleIndex,
                                 VAR(uint32, AUTOMATIC) ChannelMask
                             )
{
/* @implements DPWM01013 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)

        if (NULL_PTR == Pwm_Cfg_Ptr)
        {
            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_BUFTRANSFER_ID,
                (uint8) PWM_E_UNINIT
            );
        }
        else
#endif /* PWM_DEV_ERROR_DETECT */
        {
            Pwm_LLD_BufferTransferEnableDisable(ModuleIndex, ChannelMask);
        }
}
#endif
#endif


/*===============================================================================================*/
#ifdef PWM_GET_CHANNEL_STATE
#if (PWM_GET_CHANNEL_STATE == STD_ON)
/**
* @brief            Implementation specific function to return the dutycycle value
* @details          This function return the DutyCycle value of the channel
*
* @param[in]        ChannelNumber - ChannelNumber
*
* @return           Pwm_DutyType
*
* @implements       DPWM01012, DPWM02520
*
*/
/* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC (Pwm_DutyType, PWM_CODE) Pwm_GetChannelState(
        VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber
    )
{
VAR(Pwm_DutyType, AUTOMATIC) Pwm_duty_return = (Pwm_DutyType)0U;
    if (NULL_PTR != Pwm_Cfg_Ptr)
    {
/* @implements DPWM01017 */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        if (ChannelNumber >= Pwm_Cfg_Ptr->ChannelCount)
        {

            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_GETCHANNELSTATE_ID,
                (uint8) PWM_E_PARAM_CHANNEL
            );
        }
        else
        {
#endif /* PWM_DEV_ERROR_DETECT */

            Pwm_duty_return = Pwm_LLD_GetChannelState( ChannelNumber);
            
        }

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {

        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_GETCHANNELSTATE_ID,
            (uint8) PWM_E_UNINIT
        );
    }
#endif /* PWM_DEV_ERROR_DETECT */
return Pwm_duty_return;
}
#endif
#endif /* PWM_GET_CHANNEL_STATE_API */
/*==================================================*/
#ifdef PWM_OUTPUTSWCONTROL_API
#if (PWM_OUTPUTSWCONTROL_API == STD_ON)
/**
* @brief         This API provides the option to force the PWM channel to appropriate state through software
* @details        This function
*                        -allows user to set PWM O/P to LOW or PWM normal state for FlexPWM channel
*
* @param[in]      LogicalChannelNumber     PWM channel id
* @param[in]      val                                PWM o/p state

* @return         void
*
* @implements     DPWM02523
*/
/* @violates @ref Pwm_C_REF_3 external ... could be made static
*/
FUNC (void, PWM_CODE)Pwm_ForceSWOutputValue(
            VAR(Pwm_ChannelType, AUTOMATIC) PwmChannel,
            VAR(Pwm_OutputStateType, AUTOMATIC) Val)
{
    if (NULL_PTR != Pwm_Cfg_Ptr)
    {
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        if (PwmChannel >= Pwm_Cfg_Ptr->ChannelCount)
        {

            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_FORCESWOUTPUT_ID,
                (uint8) PWM_E_PARAM_CHANNEL
            );
        }        
        else
        {
#endif /* PWM_DEV_ERROR_DETECT */

            Pwm_LLD_ForceSWOutputValue( PwmChannel, Val);
        }

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {

        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_FORCESWOUTPUT_ID,
            (uint8) PWM_E_UNINIT
        );
    }
#endif /* PWM_DEV_ERROR_DETECT */
}
#endif 
#endif /* PWM_OUTPUTSWCONTROL_API */
/*==================================================*/

/**
* @brief         This API provides the option to set duty cycle via DMA mode
* @details        This function
*                        -allows user to set duty cycle for sub-modules via dma mode
*
* @param[in]      Module      module id
* @param[in]      BufferPtr   Pointer to duty of sub-modules array
* @param[in]      BufferSize  Size of array
* @return         void
*
* @implements     DPWM01014
*/
#ifdef PWM_DMASETDUTYCYCLE_API
#if (PWM_DMASETDUTYCYCLE_API == STD_ON)
/*
* @violates @ref Pwm_C_REF_3 The respective code could not be made static because
*  of layers architecture design of the driver
*/
FUNC (void, PWM_CODE)Pwm_DmaSetDutyCycle(
            P2VAR(Pwm_DutyDmaType, AUTOMATIC, PWM_APPL_DATA) BufferPtr,
            VAR(uint16, AUTOMATIC) BufferSize
    )
{
    if (NULL_PTR != Pwm_Cfg_Ptr)
    {
#if (PWM_DEV_ERROR_DETECT == STD_ON)
        if (NULL_PTR == BufferPtr)
        {
            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_DMASETDUDTCYCLE_ID,
                (uint8) PWM_E_PARAM_CHANNEL
            );
        }
        else if (BufferSize > Pwm_Cfg_Ptr->ChannelCount)
        {
            Det_ReportError
            (
                (uint16) PWM_MODULE_ID,
                (uint8) 0,
                (uint8) PWM_DMASETDUDTCYCLE_ID,
                (uint8) PWM_E_PARAM_CHANNEL
            );
        }
        else
        {
#endif /* PWM_DEV_ERROR_DETECT */

            Pwm_LLD_DmaSetDutyCycle(BufferPtr, BufferSize);
        }

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {

        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_DMASETDUDTCYCLE_ID,
            (uint8) PWM_E_UNINIT
        );
    }
#endif /* PWM_DEV_ERROR_DETECT */
}
#endif
#endif /* PWM_DMASETDUTYCYCLE_API */
/*==================================================*/
#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm_C_REF_1 Only preprocessor statements and comments before "#include"
*/
/*
* @violates @ref Pwm_C_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */


