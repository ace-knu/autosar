/**
*     @file    Icu_NonASR.c
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - ICU Driver non AUTOSAR source file.
*     @details ICU driver source file, containing the non Autosar API specification and other
*              variables and functions that are exported by the ICU driver.
*
*     @addtogroup ICU_MODULE
*     @{
*/
/*==================================================================================================
*     Project             : AUTOSAR 4.0 MCAL
*     Platform            : PA
*     Peripheral          : eMIOS
*     Dependencies        : none
*
*     Autosar Version     :  4.0.3
*     Autosar Revision    : ASR_REL_4_0_REV_0003
*     Autosar ConfVariant :
*     SWVersion           : 1.0.1
*     BuildVersion        : MPC560xB_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20140606
*
*     (c) Copyright 2006-2014 Freescale Semiconductor Inc and STMicroelectronics
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_NonASR_c_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_NonASR_c_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Icu_NonASR_c_3
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Icu_NonASR_c_4
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form
* of pointer arithmetic.
* The violation occurs because the variables are defined as per Autosar API specifications.
*
* @section Icu_NonASR_c_5
* Violates MISRA 2004 Required Rule 8.10, External function could be made static.
* Not required from Autosar specification.
*
*@section Icu_NonASR_c_6
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
*/


/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
/* @implements DICU01501 */
#include "Icu_NonASR.h"
#include "Icu_LLD.h"
/*
* @violates @ref Icu_NonASR_c_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu.h"

#if (ICU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif


/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/

/* @implements     DICU01301, DICU01302, DICU01303, DICU01304, DICU01305, DICU01306, DICU01307 */
#define ICU_NONASR_VENDOR_ID_C                      43

/*
* @violates @ref Icu_NonASR_c_2 Identifier clash.
*/
/*
* @violates @ref Icu_NonASR_c_6 This violation cannot be fixed since naming convention of Identifiers (internal and external)
are followed as per Autosar standards ,some times which may exceeds more than 31 characters.
*/
#define ICU_NONASR_AR_RELEASE_MAJOR_VERSION_C       4
/*
* @violates @ref Icu_NonASR_c_2 Identifier clash.
*/
/*
* @violates @ref Icu_NonASR_c_6 This violation cannot be fixed since naming convention of Identifiers (internal and external)
are followed as per Autosar standards ,some times which may exceeds more than 31 characters.
*/
#define ICU_NONASR_AR_RELEASE_MINOR_VERSION_C       0
/*
* @violates @ref Icu_NonASR_c_2 Identifier clash.
*/
/*
* @violates @ref Icu_NonASR_c_6 This violation cannot be fixed since naming convention of Identifiers (internal and external)
are followed as per Autosar standards ,some times which may exceeds more than 31 characters.
*/
#define ICU_NONASR_AR_RELEASE_REVISION_VERSION_C    3
#define ICU_NONASR_SW_MAJOR_VERSION_C               1
#define ICU_NONASR_SW_MINOR_VERSION_C               0
#define ICU_NONASR_SW_PATCH_VERSION_C               1


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if Icu_NonASR.c and Icu_NonASR.h are of the same vendor */
#if (ICU_NONASR_VENDOR_ID_C != ICU_NONASR_VENDOR_ID_H)
    #error "Vendor IDs of Icu_NonASR.c and Icu_NonASR.h are different"
#endif
    /* Check if Icu_NonASR.c and Icu_NonASR.h are of the same Autosar version */
#if ((ICU_NONASR_AR_RELEASE_MAJOR_VERSION_C != ICU_NONASR_AR_RELEASE_MAJOR_VERSION_H) || \
     (ICU_NONASR_AR_RELEASE_MINOR_VERSION_C != ICU_NONASR_AR_RELEASE_MINOR_VERSION_H) || \
     (ICU_NONASR_AR_RELEASE_REVISION_VERSION_C != ICU_NONASR_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of Icu_NonASR.c and Icu_NonASR.h are different"
#endif

/* Check if Icu_NonASR.c and Icu_NonASR.h are of the same Software version */
#if ((ICU_NONASR_SW_MAJOR_VERSION_C != ICU_NONASR_SW_MAJOR_VERSION_H) || \
     (ICU_NONASR_SW_MINOR_VERSION_C != ICU_NONASR_SW_MINOR_VERSION_H) || \
     (ICU_NONASR_SW_PATCH_VERSION_C != ICU_NONASR_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Icu_NonASR.c and Icu_NonASR.h are different"
#endif

/* Check if Icu_NonASR.c and Icu_LLD.h are of the same vendor */
#if (ICU_NONASR_VENDOR_ID_C != ICU_LLD_VENDOR_ID)
    #error "Vendor IDs of Icu_NonASR.c and Icu_LLD.h are different"
#endif

    /* Check if Icu_NonASR.c and Icu_LLD.h are of the same Autosar version */
#if ((ICU_NONASR_AR_RELEASE_MAJOR_VERSION_C != ICU_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_NONASR_AR_RELEASE_MINOR_VERSION_C != ICU_LLD_AR_RELEASE_MINOR_VERSION) || \
     (ICU_NONASR_AR_RELEASE_REVISION_VERSION_C != ICU_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_NonASR.c and Icu_LLD.h are different"
#endif

/* Check if Icu_NonASR.c and Icu_LLD.h are of the same Software version */
#if ((ICU_NONASR_SW_MAJOR_VERSION_C != ICU_LLD_SW_MAJOR_VERSION) || \
     (ICU_NONASR_SW_MINOR_VERSION_C != ICU_LLD_SW_MINOR_VERSION) || \
     (ICU_NONASR_SW_PATCH_VERSION_C != ICU_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_NonASR.c and Icu_LLD.h are different"
#endif

/* Check if Icu_NonASR.c and Det.h are of the same version */
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        #if ((ICU_NONASR_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (ICU_NONASR_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu_NonASR.c and Det.h are different"
        #endif
    #endif
#endif /* ICU_DEV_ERROR_DETECT */

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
/*
* @violates @ref Icu_NonASR_c_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"


/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#if (ICU_DUAL_CLOCK_MODE == STD_ON)
/*================================================================================================*/
/**
* @brief      This function changes the channel prescaler.
* @details    This function sets all channels prescalers based on the input mode.
*
* @param[in]  Prescaler - Prescaler type ( Normal or Alternate )
*
* @return  void
*
* @pre        Icu_Init must be called before.
*
* @violates @ref Icu_NonASR_c_5 External function could be made static.
*
* @implements DICU01101, DICU10021
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_SetClockMode(VAR(Icu_SelectPrescalerType, AUTOMATIC) Prescaler)
{
    VAR(Icu_ChannelType, AUTOMATIC) numChl;
    P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) tempPtr;

    /* [ICU002]: Detected development errors shall be reported to the Det_ReportError service of the
    *  Development Error Tracer (DET) if the pre-processor switch ICU_DEV_ERROR_DETECT is set
    */
    /* [ICU111]: The detection of development errors is configurable (ON / OFF) at precompile time.
    *  The switch ICU_DEV_ERROR_DETECT  shall activate or  deactivate the detection  of all
    *  development errors.
    */
    /* [ICU112]: If the switch ICU_DEV_ERROR_DETECT is enabled, API parameter checking is enabled.*/
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    /* If Development  Error Detection is  enabled, report error  Icu is uninitialized  is passed as
    *  a NULL Pointer
     */
    if (NULL_PTR == Icu_Cfg_Ptr)
    {
        /* [ICU022]  - The  service Icu_Init()  shall be  called first  before calling any other ICU
        *  services. If not respected, the error code ICU_E_UNINIT will be reported to the
        *  Development Error Tracer (if development error detection is enabled).
        */
        Det_ReportError((uint16)ICU_MODULE_ID, (uint8)0U,
                        (uint8)ICU_SET_CLOCK_MODE_ID, (uint8)ICU_E_UNINIT);

        /* [ICU048] - If development error detection is enabled and an error is detected the desired
        *  functionality shall be skipped and the requested service is left without any action.
        */
    }
    else if ((ICU_NORMAL != Prescaler) && (ICU_ALTERNATE != Prescaler))
    {
        /* [ICU125] - If development error detection is enabled, the parameter Mode shall be checked
        *  by this service.  If Mode is invalid,  then the error ICU_E_PARAM_MODE shall be reported
        *  to the Development Error Tracer.
         */
        Det_ReportError((uint16)ICU_MODULE_ID, (uint8)0U,
                        (uint8)ICU_SET_CLOCK_MODE_ID, (uint8)ICU_E_PARAM_CLOCK_MODE);
        /* [ICU048] - If development error detection is enabled and an error is detected the desired
        *  functionality shall be skipped and the requested service is left without any action.
        */
    }
    else
#endif /* ICU_DEV_ERROR_DETECT */
    {
        for (numChl = 0U; numChl < Icu_Cfg_Ptr->Icu_MaxChannels; numChl++)
        {
            /*
            * @violates @ref Icu_NonASR_c_4 Array indexing shall be the only allowed form of
            *        pointer arithmetic.
            */
            tempPtr = &Icu_Cfg_Ptr->Icu_ChannelConfigPtr[numChl];

            /* Call low level function */
            Icu_LLD_SelectPrescaler(tempPtr, numChl, Prescaler);
        }
    }
}
/* ICU_DUAL_CLOCK_MODE */
#endif


#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
/*================================================================================================*/
/**
* @brief      This function returns the actual status of PIN.

* @details    This function returns the actual status of PIN.
*
* @param[in]     Channel          Numeric identifier of the ICU channel
*
* @return  Icu_LevelType
*
* @pre        Icu_Init must be called before.
*
* @violates @ref Icu_NonASR_c_5 External function could be made static.
*
* @implements DICU01112
*/
/*================================================================================================*/
FUNC (Icu_LevelType, ICU_CODE) Icu_GetInputLevel(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Icu_LevelType, AUTOMATIC) tempStatus = (Icu_LevelType)ICU_LEVEL_LOW;

    /* [ICU002]: Detected development errors shall be reported to the Det_ReportError service of the
    *  Development Error Tracer (DET) if the pre-processor switch ICU_DEV_ERROR_DETECT is set
    */
    /* [ICU111]: The detection of development errors is configurable (ON / OFF) at precompile  time.
    *  The switch ICU_DEV_ERROR_DETECT  shall activate or  deactivate the detection  of all
    *  development errors.
    */
    /* [ICU112]: If the switch ICU_DEV_ERROR_DETECT is enabled, API parameter checking is enabled.*/
#if (ICU_DEV_ERROR_DETECT == STD_ON)

    /* If Development Error Detection is enabled, report error ICU is uninitialized */
    if (NULL_PTR == Icu_Cfg_Ptr)
    {
        /* [ICU022]  - The  service Icu_Init()  shall be  called first  before calling any other ICU
        *  services. If not respected, the error code ICU_E_UNINIT will be reported to the
        *  Development Error Tracer (if development error detection is enabled).
        */
        Det_ReportError((uint16)ICU_MODULE_ID, (uint8)0U, (uint8)ICU_GET_INPUT_LEVEL_ID,
                        (uint8)ICU_E_UNINIT);
        /* [ICU048] - If development error detection is enabled and an error is detected the desired
         * functionality shall be skipped and the requested service is left without any action.
        */
    }
    /* Test for invalid channel and report ICU_E_PARAM_CHANNEL */
    else if ((Channel >= Icu_Cfg_Ptr->Icu_MaxChannels))
    {
        /* [ICU024]  - If  development error  detection is  enabled, the  parameter Channel shall be
        * checked by this service. If Channel is invalid, then the error ICU_E_PARAM_CHANNEL shall
        * be reported to the Development Error Tracer.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, (uint8)0U, (uint8)ICU_GET_INPUT_LEVEL_ID,
                        (uint8)ICU_E_PARAM_CHANNEL);
        /* [ICU048] - If development error detection is enabled and an error is detected the desired
        *  functionality shall be skipped and the requested service is left without any action.
        */
    }
        /* Test for EMIOS/ETIMER channel and  report ICU_E_PARAM_CHANNEL If the channel is not an
        EMIOS/ETIMER Channel*/
        /*
        * @violates @ref Icu_NonASR_c_4 Array indexing shall be the only allowed form of
        *        pointer arithmetic.
        */
    else if ((ICU_VALID_CHANNEL_INPUT_LEVEL <= Icu_Cfg_Ptr->Icu_ChannelId[Channel]))
    {
        /* [ICU024]  - If  development error  detection is  enabled, the  parameter Channel shall be
        * checked by this service. If Channel is not an emios/etimer channel, then the error
        * ICU_E_PARAM_CHANNEL shall  be reported to the Development Error Tracer.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, (uint8)0U, (uint8)ICU_GET_INPUT_LEVEL_ID,
                        (uint8)ICU_E_PARAM_CHANNEL);
        /* [ICU048] - If development error detection is enabled and an error is detected the desired
        *  functionality shall be skipped and the requested service is left without any action.
        */
    }

    else if ((ICU_MODE_SIGNAL_EDGE_DETECT !=
        /*
        * @violates @ref Icu_NonASR_c_4 Array indexing shall be the only allowed form of
        *        pointer arithmetic.
        */
              Icu_Cfg_Ptr->Icu_ChannelConfigPtr[Channel].Icu_Channel_Mode) &&
             (ICU_MODE_SIGNAL_MEASUREMENT !=
        /*
        * @violates @ref Icu_NonASR_c_4 Array indexing shall be the only allowed form of
        *        pointer arithmetic.
        */
              Icu_Cfg_Ptr->Icu_ChannelConfigPtr[Channel].Icu_Channel_Mode ))
    {
        /* [ICU162]  - If  development error  detection is  enabled, the  parameter Channel shall be
        *  checked by this service. If Channel is invalid (invalid channel or channel not configured
        *  as ICU_MODE_SIGNAL_EDGE_DETECT     or    ICU_MODE_SIGNAL_MEASUREMENT,   then  the  error
        *  ICU_E_PARAM_CHANNEL shall be reported to the Development Error Tracer.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, (uint8)0U, (uint8)ICU_GET_INPUT_LEVEL_ID,
                        (uint8)ICU_E_PARAM_CHANNEL);

        /* [ICU049] - If development error detection is enabled and an error is detected the service
        *  returns ICU_IDLE.
        */
    }

    else
    {
#endif /* ICU_DEV_ERROR_DETECT */

        /* Call low level function */
        tempStatus=(Icu_LevelType)Icu_LLD_GetInputLevel(Channel);

 #if (ICU_DEV_ERROR_DETECT == STD_ON)
    }
 #endif
        return(tempStatus);
}
/* ICU_GET_INPUT_LEVEL_API */
#endif

#ifdef ICU_GET_PULSE_WIDTH_API
#if (ICU_GET_PULSE_WIDTH_API == STD_ON)
/*================================================================================================*/
/**
 @brief      This function returns the signals High time, Low time and Period without using the
             channel interrupt.
 @details    This function returns the signals High time, Low time and Period without using the
             channel interrupt.
 @param[in]     Channel          Numeric identifier of the ICU channel
 @pre        Icu_Init must be called before.
 @implements DICU01115
*/
/*================================================================================================*/
/*
* @violates @ref Icu_NonASR_c_5 External function could be made static.
*/
FUNC (void, ICU_CODE) Icu_GetPulseWidth(VAR(uint8, AUTOMATIC) Channel)
{
    /* [ICU002]: Detected development errors shall be reported to the Det_ReportError service of the
    Development Error Tracer (DET) if the pre-processor switch ICU_DEV_ERROR_DETECT is set
    */
    /* [ICU111]: The detection of development errors is configurable (ON / OFF) at precompile  time.
    The switch ICU_DEV_ERROR_DETECT  shall activate or  deactivate the detection  of all development
    errors.
    */
    /* [ICU112]: If the switch ICU_DEV_ERROR_DETECT is enabled, API parameter checking is
    enabled. */
#if (ICU_DEV_ERROR_DETECT == STD_ON)

    /* If Development Error Detection is enabled, report error Icu is uninitialized */
    if (NULL_PTR == Icu_Cfg_Ptr)
    {
        /* [ICU022]  - The  service Icu_Init()  shall be  called first  before calling any other ICU
        services. If not respected, the error code ICU_E_UNINIT will be reported to the  Development
        Error Tracer (if development error
         detection is enabled).
        */
        Det_ReportError((uint16)ICU_MODULE_ID, (uint8)0U,
                        (uint8)ICU_GET_PULSE_WIDTH_ID,
                        (uint8)ICU_E_UNINIT);

        /* [ICU048] - If development error detection is enabled and an error is detected the desired
        functionality shall be skipped and the requested service is left without any action.
        */
    }
    /* Test for invalid channel and report ICU_E_PARAM_CHANNEL
       This service shall be available for each ICU channel in Measurement Mode "Signal
       Measurement".
    */
    /* @violates @ref Icu_NonASR_c_4 Array indexing shall be the only allowed form of
            pointer arithmetic. */
    else if (Channel >= Icu_Cfg_Ptr->Icu_MaxChannels)
    {
        /* [ICU024]  - If  development error  detection is  enabled, the  parameter Channel shall be
        checked by this service. If Channel is invalid, then the error ICU_E_PARAM_CHANNEL shall  be
         reported to the Development Error Tracer.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, (uint8)0U,
                        (uint8)ICU_GET_PULSE_WIDTH_ID,
                        (uint8)ICU_E_PARAM_CHANNEL);

        /* [ICU048] - If development error detection is enabled and an error is detected the desired
        functionality shall be skipped and the
         requested service is left without any action.
        */
    }
    else if (ICU_MODE_SIGNAL_MEASUREMENT !=
     /*
            * @violates @ref Icu_NonASR_c_4 Array indexing shall be the only allowed form of
            *        pointer arithmetic.
            */
             Icu_Cfg_Ptr->Icu_ChannelConfigPtr[Channel].Icu_Channel_Mode)
    {
        /* If  development error  detection is  enabled, the  parameter Channel shall be
          checked by this service. If Channel is invalid (invalid channel or channel not configured
          as ICU_MODE_SIGNAL_MEASUREMENT,     then    the     error
          ICU_E_PARAM_CHANNEL shall be reported to the Development Error Tracer.
          */
        Det_ReportError((uint16)ICU_MODULE_ID, (uint8)0U,
                        (uint8)ICU_GET_PULSE_WIDTH_ID,
                        (uint8)ICU_E_PARAM_CHANNEL);

        /* [ICU048] - If development error detection is enabled and an error is detected the desired
        functionality shall be skipped and the requested service is left without any action.
        */
    }
    /* @violates @ref Icu_NonASR_c_4 Array indexing shall be the only allowed form of
            pointer arithmetic. */
    else if (Icu_Cfg_Ptr->Icu_ChannelConfigPtr[Channel].IcuSignalMeasureWithoutInterrupt != (boolean)TRUE)
    {
        /* If  development error  detection is  enabled, the  parameter Channel shall be
          checked by this service. If Channel configured as ICU_MODE_SIGNAL_MEASUREMENT but the
          IcuSignalMeasurementProperty is ICU_DUTY_CYCLE and IcuSignalMeasureWithoutInterrupt is FALSE
          ICU_E_PARAM_CHANNEL shall be reported to the Development Error Tracer.
          */
        Det_ReportError((uint16)ICU_MODULE_ID, (uint8)0U,
                        (uint8)ICU_GET_PULSE_WIDTH_ID,
                        (uint8)ICU_E_PARAM_CHANNEL);
    }
    else
    {
#endif
        /* Call low level function */
        Icu_LLD_GetPulseWidth(Channel);

#if (ICU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif
#endif

#if (ICU_CAPTURERGISTER_API == STD_ON)
/*================================================================================================*/
/**
* @brief   This function starts the measurement of signals.
* @details. This service returns the value of register A.
*                                                       This API is used to measure the time difference
*                                                        between 2 differen EMIOS channels.
*
* @param[in]     Channel          Numeric identifier of the ICU channel
*
* @return Icu_ValueType -  Value of register A
* @api
*
* @pre Icu_Init must be called before.
* @pre The given channel must be configured in Measurement Mode Signal Measurement.
*
* @implements DICU01020
*/
/*================================================================================================*/
/*
* @violates @ref Icu_NonASR_c_5 External function could be made static.
*/
FUNC (Icu_ValueType, ICU_CODE) Icu_GetCaptureRegisterValue(VAR(Icu_ChannelType, AUTOMATIC) Channel)
    {
        VAR(Icu_ValueType, AUTOMATIC) tempValue = (Icu_ValueType)0U;

    /* [ICU002]: Detected development errors shall be reported to the Det_ReportError service of the
    *  Development Error Tracer (DET) if the pre-processor switch     ICU_DEV_ERROR_DETECT is set
    */
    /* [ICU111]: The detection of development errors is configurable (ON / OFF) at precompile  time.
    *  The switch ICU_DEV_ERROR_DETECT  shall activate or  deactivate the detection  of all
    *  development errors.
    */
    /* [ICU112]: If the switch ICU_DEV_ERROR_DETECT is enabled, API parameter checking is
    *  enabled. */
#if (ICU_DEV_ERROR_DETECT == STD_ON)

        /* If Development Error Detection is enabled, report error Icu is uninitialized */
    if (NULL_PTR == Icu_Cfg_Ptr)
        {
        /* [ICU022]  - The  service Icu_Init()  shall be  called first  before calling any other ICU
        *  services. If not respected, the error code ICU_E_UNINIT will be reported to the
        *  Development Error Tracer (if development error detection is enabled).
        */
        Det_ReportError((uint16)ICU_MODULE_ID, (uint8)0U, (uint8)ICU_CAPTUREREGISTER_ID,
                        (uint8)ICU_E_UNINIT);

        /* [ICU048] - If development error detection is enabled and an error is detected the desired
        *  functionality shall be skipped and the requested service is left without any action.
        */
        }
        /* Test for invalid channel and report ICU_E_PARAM_CHANNEL */
        /* [ICU074]: This service shall be available for each ICU channel in Measurement Mode "Signal Measurement". */
        else if (Channel >= Icu_Cfg_Ptr->Icu_MaxChannels)
        {
        /* [ICU176]:    If    development    error    detection    is    enabled,    the    function
        *  Icu_StartSignalMeasurement shall check the parameter Channel. If Channel is invalid
        *  (invalid identifier or channel  not configured for  mode  ICU_MODE_SIGNAL_MEASUREMENT),
        *  the  function Icu_StartSignalMeasurement shall raise development error
        *  ICU_E_PARAM_CHANNEL.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, (uint8)0U, (uint8)ICU_CAPTUREREGISTER_ID,
                        (uint8)ICU_E_PARAM_CHANNEL);

        /* [ICU048] - If development error detection is enabled and an error is detected the desired
        *  functionality shall be skipped and the requested service is left without any action.
        */
        }
    else if (ICU_MODE_SIGNAL_MEASUREMENT !=

    /* @violates @ref Icu_NonASR_c_4 Array indexing shall be the only allowed form of
            pointer arithmetic. */
             Icu_Cfg_Ptr->Icu_ChannelConfigPtr[Channel].Icu_Channel_Mode)
        {
        /* [ICU176]:    If    development    error    detection    is    enabled,    the    function
        *  Icu_StartSignalMeasurement shall check the parameter Channel. If Channel is invalid
        *  (invalid identifier or channel  not configured for  mode  ICU_MODE_SIGNAL_MEASUREMENT),
        *  the  function Icu_StartSignalMeasurement shall raise development error
        *  ICU_E_PARAM_CHANNEL.
        */
            Det_ReportError((uint16) ICU_MODULE_ID, (uint8)0U, (uint8) ICU_CAPTUREREGISTER_ID,
                            (uint8) ICU_E_PARAM_CHANNEL);

        /* [ICU048] - If development error detection is enabled and an error is detected the desired
        *  functionality shall be skipped and the requested service is left without any action.
        */
        }
        else
        {
#endif

/*
* @violates @ref Icu_c_4 Array indexing shall be the only allowed form of
*                 pointer arithmetic.
*/
            tempValue = Icu_LLD_GetCaptureRegisterValue(Channel);
#if (ICU_DEV_ERROR_DETECT == STD_ON)
        }
#endif
     return (tempValue);
    }
#endif
/*================================================================================================*/
#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_NonASR_c_1 precautions to prevent the contents
*        of a header file being included twice
*/
/*
* @violates @ref Icu_NonASR_c_3 only preprocessor statements and
*        comments before "#include".
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file */
/** @} */

