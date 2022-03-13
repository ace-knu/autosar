/**
*     @file    Icu.h
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - ICU driver header file.
*     @details ICU driver header file, containing the Autosar API specification and other variables
*              and functions that are exported by the ICU driver.
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

#ifndef ICU_H
#define ICU_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_h_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_h_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
*@section Icu_h_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*/


/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @file           Icu.h
* @implements     DICU01400
*/

/*
* @violates @ref Icu_h_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Std_Types.h"
/*
* @violates @ref Icu_h_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu_Cfg.h"
/*
* @violates @ref Icu_h_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Reg_Macros.h"
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
#include "EcuM_Cbk.h"
#endif  /* ICU_REPORT_WAKEUP_SOURCE */



/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @implements     DICU01041, DICU01042, DICU01043, DICU01087, DICU01088, DICU01089, DICU01090 */
#define ICU_VENDOR_ID                       43
#define ICU_MODULE_ID                       122

#define ICU_AR_RELEASE_MAJOR_VERSION        4
#define ICU_AR_RELEASE_MINOR_VERSION        0
/*
* @violates @ref Icu_h_2 Identifier clash.
*/
#define ICU_AR_RELEASE_REVISION_VERSION     3
#define ICU_SW_MAJOR_VERSION                1
#define ICU_SW_MINOR_VERSION                0
#define ICU_SW_PATCH_VERSION                1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
    /* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu.h and Std_Types.h are different"
    #endif
#endif
/* Check if source file and ICU configuration header file are of the same vendor */
#if (ICU_VENDOR_ID != ICU_VENDOR_ID_CFG)
    #error "Icu.h and ICU_Cfg.h have different vendor IDs"
#endif
    /* Check if header file and ICU configuration header file are of the same Autosar version */
#if ((ICU_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ICU_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ICU_AR_RELEASE_REVISION_VERSION != ICU_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Icu.h and ICU_Cfg.h are different"
#endif
/* Check if header file and ICU configuration header file are of the same software version */
#if ((ICU_SW_MAJOR_VERSION != ICU_SW_MAJOR_VERSION_CFG) || \
     (ICU_SW_MINOR_VERSION != ICU_SW_MINOR_VERSION_CFG) || \
     (ICU_SW_PATCH_VERSION != ICU_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Icu.h and ICU_Cfg.h are different"
#endif

#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        /* Check if header file and EcuM_Cbk.h file are of the same Autosar version */
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        #if ((ICU_AR_RELEASE_MAJOR_VERSION != ECUM_CBK_AR_RELEASE_MAJOR_VERSION) || \
             (ICU_AR_RELEASE_MINOR_VERSION != ECUM_CBK_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu.h and EcuM_Cbk.h are different"
        #endif
    #endif
#endif  /* ICU_REPORT_WAKEUP_SOURCE */



/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/


/**
* @brief   API Icu_Init service called with wrong parameter
* @implements DICU01060
*/
#define ICU_E_PARAM_CONFIG              0x0AU

/**
* @brief   API service used with an invalid channel identifier or channel was not configured for
*          the functionality of the calling API
* @implements DICU01059
*/
#define ICU_E_PARAM_CHANNEL             0x0BU

/**
* @brief   API service used with an invalid or not feasible activation
* @implements DICU01056
*/
#define ICU_E_PARAM_ACTIVATION          0x0CU

/**
* @brief   API service used with an invalid application-buffer pointer
* @implements DICU01057
*/
#define ICU_E_PARAM_BUFFER_PTR          0x0DU

/**
* @brief   API service used with an invalid buffer size
* @implements DICU01058
*/
#define ICU_E_PARAM_BUFFER_SIZE         0x0EU

/**
* @brief   API service Icu_SetMode used with an invalid mode
* @implements DICU01061
*/
#define ICU_E_PARAM_MODE                0x0FU

/**
* @brief   API service used without module initialization
* @implements DICU01063
*/
#define ICU_E_UNINIT                    0x14U

/**
* @brief   API service Icu_StopTimestamp called on a channel which was not
*          started or already stopped
* @implements DICU01055
*/
#define ICU_E_NOT_STARTED               0x15U

/**
* @brief   API service Icu_SetMode is called while a running operation
* @implements DICU01052
*/
#define ICU_E_BUSY_OPERATION            0x16U

/**
* @brief   API Icu_Init service called when the ICU driver and the Hardware
*          are already initialized
* @implements DICU01051
*/
#define ICU_E_ALREADY_INITIALIZED       0x17U

/**
* @brief   API Icu_StartTimeStamp is called and the parameter NotifyInterval is invalid (e.g. 0,
*           NotifyInterval < 1)
* @implements DICU01092
*/
#define ICU_E_PARAM_NOTIFY_INTERVAL     0x18U

/**
* @brief   API Icu_GetVersionInfo is called and the parameter versioninfo is is invalid
*          ( e.g. NULL )
* @implements DICU01093
*/
#define ICU_E_PARAM_VINFO               0x19U

/**
* @brief   API Icu_GetEdgeNumbers service called when the Counter rolls over
* @implements DICU01053
*/
#define ICU_E_EDGECOUNTING_OVERFLOW     0xD0U

/**
* @brief   API Icu_GetTimestampIndex service called when the Time stamp count overflows
* @implements DICU01062
*/
#define ICU_E_TIMESTAMP_OVERFLOW        0xD1U

/**
* @brief   API Icu_GetTimeElapsed service called when the Time elapsed overflows
* @implements DICU01054
*/
#define ICU_E_MEASUREMENT_OVERFLOW      0xD2U
/**
 @brief  API service called in SLEEP mode
@remarks Covers  PR-MCAL-3327
*/
#define ICU_E_FORBIDEN_MODE             0xD3U

/**
* @brief API service ID for Icu_Init function
* @details Parameters used when raising an error/exception
* @implements DICU01075
*/
#define ICU_INIT_ID                     0x00U

/**
* @brief API service ID for Icu_DeInit function
* @details Parameters used when raising an error/exception
* @implements DICU01047
*/
#define ICU_DEINIT_ID                   0x01U

/**
* @brief API service ID for Icu_SetMode function
* @details Parameters used when raising an error/exception
* @implements DICU01079
*/
#define ICU_SETMODE_ID                  0x02U

/**
* @brief API service ID for Icu_DisableWakeup function
* @details Parameters used when raising an error/exception
* @implements DICU01050
*/
#define ICU_DISABLEWAKEUP_ID            0x03U

/**
* @brief API service ID for Icu_EnableWakeup function
* @details Parameters used when raising an error/exception
* @implements DICU01068
*/
#define ICU_ENABLEWAKEUP_ID             0x04U

/**
* @brief API service ID for Icu_SetActivationCondition function
* @details Parameters used when raising an error/exception
* @implements DICU01078
*/
#define ICU_SETACTIVATIONCONDITION_ID   0x05U

/**
* @brief API service ID for Icu_DisableNotification function
* @details Parameters used when raising an error/exception
* @implements DICU01049
*/
#define ICU_DISABLENOTIFICATION_ID      0x06U

/**
* @brief API service ID for Icu_EnableNotification function
* @details Parameters used when raising an error/exception
* @implements DICU01067
*/
#define ICU_ENABLENOTIFICATION_ID       0x07U

/**
* @brief API service ID for Icu_GetInputState function
* @details Parameters used when raising an error/exception
* @implements DICU01071
*/
#define ICU_GETINPUTSTATE_ID            0x08U

/**
* @brief API service ID for Icu_StartTimestamp function
* @details Parameters used when raising an error/exception
* @implements DICU01083
*/
#define ICU_STARTTIMESTAMP_ID           0x09U

/**
* @brief API service ID for Icu_StopTimestamp function
* @details Parameters used when raising an error/exception
* @implements DICU01086
*/
#define ICU_STOPTIMESTAMP_ID            0x0AU

/**
* @brief API service ID for Icu_GetTimestampIndex function
* @details Parameters used when raising an error/exception
* @implements DICU01073
*/
#define ICU_GETTIMESTAMPINDEX_ID        0x0BU

/**
* @brief API service ID for Icu_ResetEdgeCount function
* @details Parameters used when raising an error/exception
* @implements DICU01077
*/
#define ICU_RESETEDGECOUNT_ID           0x0CU

/**
* @brief API service ID for Icu_EnableEdgeCount function
* @details Parameters used when raising an error/exception
* @implements DICU01066
*/
#define ICU_ENABLEEDGECOUNT_ID          0x0DU

/**
* @brief API service ID for Icu_DisableEdgeCount function
* @details Parameters used when raising an error/exception
* @implements DICU01048
*/
#define ICU_DISABLEEDGECOUNT_ID         0x0EU

/**
* @brief API service ID for Icu_GetEdgeNumbers function
* @details Parameters used when raising an error/exception
* @implements DICU01070
*/
#define ICU_GETEDGENUMBERS_ID           0x0FU

/**
* @brief API service ID for Icu_GetTimeElapsed function
* @details Parameters used when raising an error/exception
* @implements DICU01072
*/
#define ICU_GETTIMEELAPSED_ID           0x10U

/**
* @brief API service ID for Icu_GetDutyCycleValues function
* @details Parameters used when raising an error/exception
* @implements DICU01069
*/
#define ICU_GETDUTYCYCLEVALUES_ID       0x11U

/**
* @brief API service ID for Icu_GetVersionInfo function
* @details Parameters used when raising an error/exception
* @implements DICU01074
*/
#define ICU_GETVERSIONINFO_ID           0x12U

/**
* @brief API service ID for Icu_StartSignalMeasurement function
* @details Parameters used when raising an error/exception
* @implements DICU01082
*/
#define ICU_STARTSIGNALMEASUREMENT_ID   0x13U

/**
* @brief API service ID for Icu_StopSignalMeasurement function
* @details Parameters used when raising an error/exception
* @implements DICU01085
*/
#define ICU_STOPSIGNALMEASUREMENT_ID    0x14U

/**
* @brief API service ID for Icu_CheckWakeup function
* @details Parameters used when raising an error/exception
* @implements DICU01096
*/
#define ICU_CHECKWAKEUP_ID              0x15U
/**
* @brief API service ID for Icu_EnableEdgeDetection function
* @details Parameters used when raising an error/exception
* @implements DICU01094
*/
#define ICU_ENABLEEDGEDETECTION_ID      0x16U

/**
* @brief API service ID for Icu_DisableEdgeDetection function
* @details Parameters used when raising an error/exception
* @implements DICU01095
*/
#define ICU_DISABLEEDGEDETECTION_ID     0x17U

/**
* @brief API service ID for Icu_DeInit function
* @details Parameters used when raising an error/exception, 
* when the channel is running and user calls the deinit API
*/
#define ICU_CHANNELRUNNINGCALLDEINIT_ID   0x20U


/*================================================================================================*/

/**
 * @brief          This gives the numeric ID (hardware channel number) of an ICU channel
 *
 * @implements     DICU01039
*/
/*================================================================================================*/
typedef uint8                           Icu_ChannelType;
/*================================================================================================*/

/**
 * @brief          The Icu_ParamType contains combined bit fields for initialization options, for
 *                 different registers.
 *
 * @implements     DICU01034
*/
/*================================================================================================*/
typedef uint32                          Icu_ParamType;
/*================================================================================================*/

/**
 * @brief          Type for saving the timer register width value
 *
 * @implements     DICU01033
*/
/*================================================================================================*/
typedef Icu_TimerRegisterWidthType      Icu_ValueType;
/*================================================================================================*/

/**
 * @brief          Type for saving the ICU Hardware specific index
 *
 * @implements     DICU01036
*/
/*================================================================================================*/
typedef Icu_HwSpecificIndexType         Icu_IndexType;
/*================================================================================================*/

/**
 * @brief          Type for saving hardware specific edge number
 *
 * @implements     DICU01037
*/
/*================================================================================================*/
typedef Icu_HwSpecificEdgeNumberType    Icu_EdgeNumberType;
/*================================================================================================*/

/**
 * @brief          Type for saving the Wakeup value
 *
 * @implements     DICU01032
*/
/*================================================================================================*/
typedef uint32                          Icu_WakeupValue;
/*================================================================================================*/

/**
 * @brief          Type for saving the ICU measurement submode type
 *
 * @implements     DICU01040
*/
/*================================================================================================*/
typedef uint8                           Icu_MeasurementSubModeType;

/**
 * @brief          The notification functions shall have no parameters and no return value.
 *
 * @implements     DICU01035
*/
typedef void (*Icu_NotifyType)(void);

/**
 * @brief          Type for saving the ICU Clock Prescaler type
 *
 * @implements     
*/
typedef uint8                           Icu_ClockPrescalerType;


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/**
 * @brief Allow enabling / disabling of all interrupts which are not required for the ECU wakeup.
 *
 * @implements DICU01022
*/
typedef enum
{
    ICU_MODE_NORMAL = 0U,     /*< @brief Normal operation, all used interrupts are enabled
                               *          according to the notification requests. */
    ICU_MODE_SLEEP            /*< @brief Reduced power operation. In sleep mode only those
                               *          notifications are available which are configured as wakeup
                               *          capable. */
} Icu_ModeType;


/**
 * @brief Input state of an ICU channel.
 *
 * @implements DICU01024
*/
typedef enum
{
    ICU_ACTIVE = 0U,         /*< @brief An activation edge has been detected. */
    ICU_IDLE                 /*< @brief No activation edge has been detected since the last call of
                              *          Icu_GetInputState() or Icu_Init(). */
} Icu_InputStateType;


/**
 * @brief Definition of the measurement mode type.
 *
 * @implements DICU01023
*/
typedef enum
{
    ICU_MODE_SIGNAL_EDGE_DETECT = 0U,   /*< @brief Mode for detecting edges. */
    ICU_MODE_SIGNAL_MEASUREMENT,        /*< @brief Mode for measuring different times between
                                         *          various configurable edges. */
    ICU_MODE_TIMESTAMP,                 /*< @brief Mode for capturing timer values on configurable
                                         *          edges. */
    ICU_MODE_EDGE_COUNTER               /*< @brief Mode for counting edges on configurable
                                         *          edges. */
} Icu_MeasurementModeType;


/**
 * @brief Definition of the measurement property type.
 *
 * @implements DICU01028
*/
typedef enum
{
    ICU_LOW_TIME = 0U,                  /*< @brief The channel is configured for reading the
                                         *          elapsed Signal Low Time. */
    ICU_HIGH_TIME,                      /*< @brief The channel is configured for reading the
                                         *          elapsed Signal High Time. */
    ICU_PERIOD_TIME,                    /*< @brief The channel is configured for reading the
                                         *          elapsed Signal Period Time. */
    ICU_DUTY_CYCLE                      /*< @brief The channel is configured to read values which
                                         *          are needed for calculating the duty cycle
                                         *          (coherent Active and Period Time). */
/*
* @violates @ref Icu_h_3 This violation cannot be fixed since naming convention of Identifiers (internal and external)
are followed as per Autosar standards ,some times which may exceeds more than 31 characters.
*/
} Icu_SignalMeasurementPropertyType;


/**
 * @brief Definition of the timestamp measurement property type.
 *
 * @implements DICU01027
*/
typedef enum
{
    ICU_LINEAR_BUFFER = 0U,     /*< @brief The buffer will just be filled once. */
    ICU_CIRCULAR_BUFFER         /*< @brief After reaching the end of the buffer, the driver
                                 *          restarts at the beginning of the buffer. */
} Icu_TimestampBufferType;


/**
 * @brief Definition of the type of activation of an ICU channel.
 *
 * @implements DICU01026
*/
typedef enum
{
    ICU_FALLING_EDGE = 0x0U,     /*< @brief An appropriate action shall be executed when a falling
                                  *          edge occurs on the ICU input signal. */
    ICU_RISING_EDGE  = 0x1U,     /*< @brief An appropriate action shall be executed when a rising
                                  *          edge occurs on the ICU input signal */
    ICU_BOTH_EDGES   = 0x2U      /*< @brief An appropriate action shall be executed when either a
                                  *         rising or falling edge occur on the ICU input signal. */
} Icu_ActivationType;



/**
 * @brief Definition of the type of wake up capability of an ICU channel.
 *
 * @implements DICU01025
*/
typedef enum
{
    ICU_WAKEUP_NOTCAPABLE = 0x0U,    /*< @brief Channel is not wakeup capable. */
    ICU_WAKEUP_CAPABLE    = 0x1U     /*< @brief TChannel is wakeup capable. */
} Icu_WakeupCapableType;

/**
* @brief  Definition of bit mask to isolate the wake up capability  bitfield
 */
#define ICU_WAKEUP_MASK         ((uint32)BIT31)
/**
* @brief  Definition wake up capability bitfield position
 */
#define ICU_WAKEUP_SHIFT        ((uint32)31U)

/**
* @brief  Definition of bit mask to isolate the configured edge activation type
 */
#define ICU_EDGE_PARAM_MASK     ((uint32)(BIT30|BIT29))
/**
* @brief  Definition edge activation type bitfield position
 */
#define ICU_EDGE_PARAM_SHIFT    ((uint32)29U)


#ifdef ICU_CUSTOM_NOTIFICATION_API
/**
* @brief Definition of Custom Notification Handler Enabled bitfield
 */
#define ICU_CUSTOM_NOTIFICATION_ENABLED         BIT0
/**
* @brief Definition of bit mask to isolate the Custom Notification Handler Enabled bitfield
 */
#define ICU_CUSTOM_NOTIFICATION_ENABLED_MASK    (uint32)BIT28
/**
* @brief  Definition of Custom Notification Handler Enabled bitfield position
 */
#define ICU_CUSTOM_NOTIFICATION_ENABLED_SHIFT   (uint32)28U
#endif  /* ICU_CUSTOM_NOTIFICATION_API */


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/**
 * @brief Structure that contains ICU Duty cycle parameters. It contains the values needed for
 *        calculating duty cycles i.e Period time value and active time value.
 *
 * @implements DICU01029
*/
typedef struct
{
    Icu_ValueType ActiveTime;          /*< @brief Low or High time value. */
    Icu_ValueType PeriodTime;         /*< @brief Period time value. */
} Icu_DutyCycleType;


/**
 * @brief    Structure that contains ICU channel configuration.
 * @details  It contains the information like Icu Channel Mode, Channel Notification function,
 *           overflow Notification function.
 *
 * @implements DICU01031
*/
typedef struct
{
    Icu_ParamType Icu_ParamValue;                       /*< @brief  Configuration parameters of
                                                         *           hardware channlel registers. */
#ifdef GTM_TIM_FILTER_AVAILABLE
    Icu_ParamType Icu_FilterParamRe;                       /*< @brief  Configuration parameters of
                                                         *           hardware channlel registers. */
    Icu_ParamType Icu_FilterParamFe;                       /*< @brief  Configuration parameters of
                                                         *           hardware channlel registers. */
#endif
    Icu_MeasurementModeType Icu_Channel_Mode;           /*< @brief  EDGE_DETECT, TIME_STAMP,
                                                         *           SIGNAL_MEASUREMENT or
                                                         *           EDGE_COUNTER. */
    Icu_MeasurementSubModeType Icu_Channel_Property;    /*< @brief  CIRCULAR_BUFFER or
                                                         *           LINEAR_BUFFER for TIME_STAMP,
                                                         *           DUTY_CYCLE, HIGH_TIME, LOW_TIME
                                                         *           or PERIOD_TIME for
                                                         *           SIGNAL_MEASUREMENT and
                                                         *           RISING_EDGE, FALLING_EDGE or
                                                         *           BOTH_EDGES for EDGE_COUNTER. */
    Icu_NotifyType Icu_Channel_Notification;            /*< @brief  Icu Channel Notification
                                                         *           function for TIME_STAMP or
                                                         *           EDGE_COUNTER mode. */

#if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
        /*< @brief  Icu Channel Overflow Notification function. */
/*
* @violates @ref Icu_h_3 This violation cannot be fixed since naming convention of Identifiers (internal and external)
are followed as per Autosar standards ,some times which may exceeds more than 31 characters.
*/
    Icu_NotifyType Icu_Channel_OverFlowNotification;
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */
#ifdef ICU_GET_PULSE_WIDTH_API
/**
* @brief Measurement of ICU signal property without using interrupt
* @implements DICU01031
*/
/*
* @violates @ref Icu_h_3 This violation cannot be fixed since naming convention of Identifiers (internal and external)
are followed as per Autosar standards ,some times which may exceeds more than 31 characters.
*/    
    boolean IcuSignalMeasureWithoutInterrupt;
#endif
    Icu_WakeupValue Icu_Channel_WakeupValue;           /*< @brief EcuM wakeup source Id. */
/**
* @brief Disable notification to EcuM
*/
/*
* @violates @ref Icu_h_3 This violation cannot be fixed since naming convention of Identifiers (internal and external)
are followed as per Autosar standards ,some times which may exceeds more than 31 characters.
*/     
    boolean IcuDisableEcumWakeupSourceNotification;
#ifdef ICU_DMA_SUPPORTED     
#if (ICU_DMA_SUPPORTED == STD_ON)        
    boolean Icu_DMA_Enable;    
    uint8 Icu_DMA_Channel;
        
#ifdef ICU_ETIMER_DMA_SUPPORTED
#if (ICU_ETIMER_DMA_SUPPORTED == STD_ON)
    /**
    @brief DREQ selection for ETimer channel.
    */
    Icu_ChannelType Etimer_DMA_DREQ;
#endif
#endif

#endif
#endif
} Icu_ChannelConfigType;



/**
 * @brief This type contains initialization data.
 * @details he notification functions shall be configurable
 *         as function pointers within the initialization data structure (Icu_ConfigType).
 *         This type of the external data structure shall contain the
 *         initialization data for the ICU driver. It shall contain:
 *         - Wakeup Module Info (in case the wakeup-capability is true)
 *         - ICU dependent properties for used HW units
 *         - Clock source with optional prescaler (if provided by HW)
 * @implements DICU01030
*/
typedef struct
{
    /*< @brief The number of configured channels. */
    CONST(Icu_ChannelType, ICU_CONST) Icu_MaxChannels;

    /*< @brief Pointer to Icu channel configuration. */
    P2CONST(Icu_ChannelConfigType, ICU_VAR, ICU_APPL_CONST) Icu_ChannelConfigPtr;

    /*< @brief This index relates the Icu Channel number with the respective global variable,
     *          depending on the measurement mode Each kind of measurement mode has an array(s) in
     *          the ICU driver.. */
    P2CONST(Icu_ChannelType, ICU_VAR, ICU_APPL_CONST) Icu_ChannelIndex;

    /*< @brief Array for mapping the Icu channels to hardware channels. */
    P2CONST(Icu_ChannelType, ICU_VAR, ICU_APPL_CONST) Icu_ChannelId;

    /*< @brief This index relates the Hardware channels with the respective ICU channel.. */
    P2CONST(Icu_ChannelType, ICU_VAR, ICU_APPL_CONST) Icu_HWMap;

    /*< @brief This index relates the Wakeup pins with the respective ICU channel. */
    P2CONST(Icu_ChannelType, ICU_VAR, ICU_APPL_CONST) Icu_HWWKMap;
    /*< @brief This index relates the Hardware channels with the respective ICU channel.. */
#ifdef ICU_DMA_SUPPORTED        
    P2CONST(Icu_ChannelType, ICU_VAR, ICU_APPL_CONST) Icu_DMAHWMap;

    /*< @brief This index relates the Wakeup pins with the respective ICU channel. */
    P2CONST(Icu_ChannelType, ICU_VAR, ICU_APPL_CONST) Icu_DmaChannelIndex;
#endif 
    CONST(Icu_ClockPrescalerType, ICU_CONST) Icu_Irq_ClockPrescaler;
#if (ICU_DUAL_CLOCK_MODE == STD_ON)
    CONST(Icu_ClockPrescalerType, ICU_CONST) Icu_Irq_AlternateClockPrescaler;
#endif
} Icu_ConfigType;


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#ifndef ICU_PRECOMPILE_SUPPORT
/*
* @violates @ref Icu_h_3 This violation cannot be fixed since naming convention of Identifiers (internal and external)
are followed as per Autosar standards ,some times which may exceeds more than 31 characters.
*/    
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Icu_h_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"

ICU_CFG_EXTERN_DECLARATIONS
/*
* @violates @ref Icu_h_3 This violation cannot be fixed since naming convention of Identifiers (internal and external)
are followed as per Autosar standards ,some times which may exceeds more than 31 characters.
*/
#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED

/*
* @violates @ref Icu_h_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"

#endif /* #ifndef ICU_PRECOMPILE_SUPPORT*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#define ICU_START_SEC_CODE
/*
* @violates @ref Icu_h_1 precautions to prevent the contents
*        of a header file being included twice
*/

#include "MemMap.h"



FUNC (void, ICU_CODE) Icu_Init(P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr);


#if (ICU_DE_INIT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_DeInit(void);
#endif /* ICU_DE_INIT_API */


#if (ICU_SET_MODE_API == STD_ON)
FUNC (void, ICU_CODE) Icu_SetMode(VAR(Icu_ModeType, AUTOMATIC) Mode);
#endif /* ICU_SET_MODE_API */


#if (ICU_DISABLE_WAKEUP_API == STD_ON)
FUNC (void, ICU_CODE) Icu_DisableWakeup(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_DISABLE_WAKEUP_API */


#if (ICU_ENABLE_WAKEUP_API == STD_ON)
FUNC (void, ICU_CODE) Icu_EnableWakeup(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_ENABLE_WAKEUP_API */


#if ((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON) && (ICU_REPORT_WAKEUP_SOURCE == STD_ON) && \
 (ICU_ENABLE_WAKEUP_API == STD_ON))
FUNC (void, ICU_CODE) Icu_CheckWakeup( VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource );
#endif /* ICU_WAKEUP_FUNCTIONALITY_API && ICU_REPORT_WAKEUP_SOURCE  &&  ICU_ENABLE_WAKEUP_API */


FUNC (void, ICU_CODE) Icu_SetActivationCondition(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                     VAR(Icu_ActivationType, AUTOMATIC) Activation);


FUNC (void, ICU_CODE) Icu_DisableNotification(VAR(Icu_ChannelType, AUTOMATIC) Channel);


FUNC (void, ICU_CODE) Icu_EnableNotification(VAR(Icu_ChannelType, AUTOMATIC) Channel);


#if (ICU_GET_INPUT_STATE_API == STD_ON)
FUNC (Icu_InputStateType, ICU_CODE) Icu_GetInputState(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_GET_INPUT_STATE_API */


#if (ICU_TIMESTAMP_API == STD_ON)
FUNC (void, ICU_CODE) Icu_StartTimestamp(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                           P2VAR(Icu_ValueType, AUTOMATIC, ICU_APPL_DATA) BufferPtr,
                                           VAR(uint16, AUTOMATIC) BufferSize,
                                           VAR(uint16, AUTOMATIC) NotifyInterval);
#endif /* ICU_TIMESTAMP_API */


#if (ICU_TIMESTAMP_API == STD_ON)
FUNC (void, ICU_CODE) Icu_StopTimestamp(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_TIMESTAMP_API */


#if (ICU_TIMESTAMP_API == STD_ON)
FUNC (Icu_IndexType, ICU_CODE) Icu_GetTimestampIndex(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_TIMESTAMP_API */


#if (ICU_EDGE_COUNT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_ResetEdgeCount(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_EDGE_COUNT_API */


#if (ICU_EDGE_COUNT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_EnableEdgeCount(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_EDGE_COUNT_API */


#if (ICU_EDGE_COUNT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_DisableEdgeCount(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_EDGE_COUNT_API */


#if (ICU_EDGE_COUNT_API == STD_ON)
FUNC (Icu_EdgeNumberType, ICU_CODE) Icu_GetEdgeNumbers(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_EDGE_COUNT_API */


#if (ICU_EDGE_DETECT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_EnableEdgeDetection(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_EDGE_DETECT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_DisableEdgeDetection(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_GET_TIME_ELAPSED_API== STD_ON)
FUNC (Icu_ValueType, ICU_CODE) Icu_GetTimeElapsed(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_GET_TIME_ELAPSED_API */


#if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)
FUNC (void, ICU_CODE) Icu_GetDutyCycleValues(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                             P2VAR(Icu_DutyCycleType, AUTOMATIC, ICU_APPL_DATA)
                                                                                  DutyCycleValues);
#endif /* ICU_GET_DUTY_CYCLE_VALUES_API */


#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_StartSignalMeasurement(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_SIGNAL_MEASUREMENT_API */


#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_StopSignalMeasurement(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_SIGNAL_MEASUREMENT_API */


#if (ICU_GET_VERSION_INFO_API == STD_ON)
FUNC(void, ICU_CODE) Icu_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,ICU_APPL_DATA)
                                                                                      versioninfo);
#endif  /* ICU_GET_VERSION_INFO_API == STD_ON */

#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_h_1 precautions to prevent the contents
*        of a header file being included twice
*/

#include "MemMap.h"



#ifdef __cplusplus
}
#endif

#endif  /* ICU_H */
/** @} */

