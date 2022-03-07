
/**
*     @file Icu_Cfg.h
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - contains the configuration data of the ICU driver
*     @details Contains the configuration data of the ICU driver
*
*     Project AUTOSAR 4.0 MCAL
*     Platform PA
*     Peripheral eMIOS
*     Dependencies none
*
*     ARVersion 4.0.3
*     ARRevision ASR_REL_4_0_REV_0003
*     ARConfVariant
*     SWVersion 1.0.1
*     BuildVersion MPC560xB_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20140606
*
*     (c) Copyright 2006-2014 Freescale Semiconductor Inc. & STMicroelectronics
*     All Rights Reserved.
*/
/*==================================================================================================
* ==================================================================================================*/

/**
 * @file    Icu_Cfg.h
 * @remarks Implements DICU02500
*/

#ifndef ICU_CFG_H
#define ICU_CFG_H

/**
* @page misra_violations MISRA-C:2004 violations
*
*@section Icu_Cfg_h_1
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
* @section Icu_Cfg_h_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Icu_Cfg_h_3
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused
*
* @section Icu_Cfg_h_4
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, a constant, a
* parenthesised expression, a type qualifier, a storage class
* specifier, or a do-while-zero construct
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/




/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @{
* @brief   Configuration header file version information
* @details The integration of incompatible files shall be avoided.
* @implements DICU02101, DICU02102, DICU02103, DICU02104, DICU02105, DICU02106, DICU02033
*/

#define ICU_VENDOR_ID_CFG                       43

/*
* @violates @ref Icu_Cfg_h_1 This is required as per autosar Requirement, 
*/
#define ICU_AR_RELEASE_MAJOR_VERSION_CFG        4
/*
* @violates @ref Icu_Cfg_h_1 This is required as per autosar Requirement, 
*/
#define ICU_AR_RELEASE_MINOR_VERSION_CFG        0
/*
* @violates @ref Icu_Cfg_h_1 This is required as per autosar Requirement, 
*/
#define ICU_AR_RELEASE_REVISION_VERSION_CFG     3

#define ICU_SW_MAJOR_VERSION_CFG                1
#define ICU_SW_MINOR_VERSION_CFG                0
#define ICU_SW_PATCH_VERSION_CFG                1
/**@}*/
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @{
* @brief Implementation specific.
*        Each channel provides a subset of the functionality available in the unified channel,
*        at a resolution of 16 bits.
*/
/*
* @violates @ref Icu_Cfg_h_3 This is not a standard library macro, 
*/ 
#define EMIOS_COUNTER_MASK              ((Icu_ValueType) 0xFFFF)
/**@}*/


/**@brief General Configuration Containers */
/**
* @{
* @brief Maximum number of ICU channels configured
*/
/**
*   @brief Maximum number of ICU channels
*   @implements DICU02135
*/

#define ICU_MAX_CHANNEL     ((Icu_ChannelType)3)
#define ICU_MAX_DMA_CHANNEL               ((Icu_ChannelType)0)
/**@}*/
/**
* @brief  Switches the Development Error Detection and Notification on or off.
*         STD_ON: Enabled. STD_OFF: Disabled.
* @implements DICU02109
*/
#define ICU_DEV_ERROR_DETECT            (STD_OFF)
#define ICU_NONBONDED_WAKEUP_PULLUP

/**
* @brief  Switch for enabling Wakeup source reporting.
*         STD_ON: Report Wakeup source. STD_OFF: Do not report Wakeup source.
* @implements DICU02119
*/
#define ICU_REPORT_WAKEUP_SOURCE        (STD_OFF)

/**
* @{
* @brief Configuration of Optional API's
*/
/**
* @brief  Adds / removes the service Icu_GetVersionInfo() from the code.
*         STD_ON: Icu_GetVersionInfo() can be used. STD_OFF: Icu_GetVersionInfo() can not be used.
* @implements DICU02117
*/
#define ICU_GET_VERSION_INFO_API        (STD_OFF)

/**
* @brief  Adds / removes the service Icu_DeInit() from the code.
*         STD_ON: Icu_DeInit() can be used. STD_OFF: Icu_DeInit() can not be used.
* @implements DICU02108
*/
#define ICU_DE_INIT_API                 (STD_OFF)

/**
* @brief  Adds / removes the service Icu_SetMode() from the code.
*         STD_ON: Icu_SetMode() can be used. STD_OFF: Icu_SetMode() can not be used.
* @implements DICU02120
*/
#define ICU_SET_MODE_API                (STD_ON)

/**
* @brief  Adds / removes the service Icu_DisableWakeup() from the code.
*         STD_ON: Icu_DisableWakeup() can be used. STD_OFF: Icu_DisableWakeup() can not be used.
* @implements DICU02110
*/
#define ICU_DISABLE_WAKEUP_API          (STD_OFF)

/**
* @brief  Adds / removes the service Icu_EnableWakeup() from the code.
*         STD_ON: Icu_EnableWakeup() can be used. STD_OFF: Icu_EnableWakeup() can not be used.
* @implements DICU02113
*/
#define ICU_ENABLE_WAKEUP_API           (STD_OFF)

/**
* @brief  Adds / removes all services related to the timestamping functionality as listed
*         below from the code: Icu_StartTimestamp(), Icu_StopTimestamp(), Icu_GetTimestampIndex().
*         STD_ON: The services listed above can be used. STD_OFF: The services listed above can not be used.
* @implements DICU02122
*/
#define ICU_TIMESTAMP_API               (STD_ON)

/**
* @brief  Adds / removes all services related to the edge counting functionality as listed below,
*         from the code: Icu_ResetEdgeCount(), Icu_EnableEdgeCount(), Icu_DisableEdgeCount(), Icu_GetEdgeNumbers().
*         STD_ON: The services listed above can be used. STD_OFF: The services listed above can not be used.
* @implements DICU02112
*/
#define ICU_EDGE_COUNT_API              (STD_ON)

/**
* @brief  Adds / removes the service Icu_GetTimeElapsed() from the code.
*         STD_ON: Icu_GetTimeElapsed() can be used. STD_OFF: Icu_GetTimeElapsed() can not be used.
* @implements DICU02116
*/
#define ICU_GET_TIME_ELAPSED_API        (STD_ON)

/**
* @brief  Adds / removes the service Icu_GetDutyCycleValues() from the code.
*         STD_ON: Icu_GetDutyCycleValues() can be used. STD_OFF: Icu_GetDutyCycleValues() can not be used.
* @implements DICU02114
*/
#define ICU_GET_DUTY_CYCLE_VALUES_API   (STD_ON)

/**
* @brief  Adds / removes the service Icu_GetInputState() from the code.
*         STD_ON: Icu_GetInputState() can be used. STD_OFF: Icu_GetInputState() can not be used.
* @implements DICU02115
*/
#define ICU_GET_INPUT_STATE_API         (STD_ON)

/**
* @brief  Adds / removes the services Icu_StartSignalMeasurement() and Icu_StopSignalMeasurement() from the code.
*         STD_ON: Icu_StartSignalMeasurement() and Icu_StopSignalMeasurement() can be used.
*         STD_OFF: Icu_StartSignalMeasurement() and Icu_StopSignalMeasurement() can not be used.
* @implements DICU02121
*/
#define ICU_SIGNAL_MEASUREMENT_API      (STD_ON)

/**
*   @brief  Adds / removes the service Icu_CheckWakeup() from the code.
*        STD_ON: Icu_CheckWakeup() can be used.
*        STD_OFF: Icu_CheckWakeup() can not be used.
*   @implements DICU02130
*/
#define ICU_WAKEUP_FUNCTIONALITY_API      (STD_OFF)

/**
*   @brief  Adds / removes the services Icu_EnableEdgeDetection() and Icu_DisableEdgeDetection() from the code.
*        STD_ON: Icu_EnableEdgeDetection() and Icu_DisableEdgeDetection() can be used.
*        STD_OFF: Icu_EnableEdgeDetection() and Icu_DisableEdgeDetection() can not be used.
*
*   @implements  DICU02131
*/
#define ICU_EDGE_DETECT_API      (STD_ON)

/**
* @brief  Implementation specific parameter
*         Adds/Removes the code related to overflow notification
*         STD_ON: Overflow notification function will be called if overflow occurs
*         STD_OFF: Overflow notification function will not be called though overflow occurs
*   @implements DICU02118
*/
#define ICU_OVERFLOW_NOTIFICATION_API   (STD_OFF)


/**
*   @brief   Adds / removes the service Icu_SetClockMode() from the code.
*         STD_ON:  Icu_SetClockMode() can be used.
*         STD_OFF: Icu_SetClockMode() can not be used.
*
*   @implements DICU02111
*/
#define ICU_DUAL_CLOCK_MODE             (STD_OFF)

/**
*   @brief   Adds / removes the service Icu_GetInputLevel() from the code.
*         STD_ON:  Icu_GetInputLevel() can be used.
*         STD_OFF: Icu_GetInputLevel() can not be used.
*
*   @implements DICU02132
*/
#define ICU_GET_INPUT_LEVEL_API             (STD_OFF)



/**
*   @brief   Adds / removes the service Icu_GetPulseWidth() from the code.
*         STD_ON:  Icu_GetPulseWidth() can be used.
*         STD_OFF: Icu_GetPulseWidth() can not be used.
*   @implements DICU02136
*/
#define ICU_GET_PULSE_WIDTH_API             (STD_OFF)
  
/**
*   @brief   Maximum configurable DMA Channels.
*
*   @implements DICU02133
*/

#define ICU_DMA_MAX_HW_CHANNELS          32U

/**
*   @brief   Adds / removes the service Icu_GetCaptureRegisterValue() from the code.
*         STD_ON:  Icu_GetCaptureRegisterValue() can be used.
*         STD_OFF: Icu_GetCaptureRegisterValue() can not be used.
*
*   @implements DICU02133
*/
#define ICU_CAPTURERGISTER_API         (STD_OFF)

/**
*   @brief   Get the wakeup mask for non bounded wakeup pin from resource file
*
*   @implements
*/
#define ICU_WKUP_PULLUP_MASK            ((uint32)0x00000000u)

/**
*   @brief   If Dma is configured for any of the ICU channel
*                  this macro will be STD_ON.
*
*   @implements DICU02134
*/
/* ICU with DMA is Avilable for different derivatives*/

#define ICU_DMA_SUPPORTED (STD_OFF)
/**@}*/
/**@brief   External declaration of the ICU configuration structure */
/* @violates @ref Icu_Cfg_h_4 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */ 
#define ICU_CFG_EXTERN_DECLARATIONS \
extern CONST(Icu_ConfigType, ICU_CONST) IcuConfigSet_0;

/**
* @brief Icu Channel symbolic names
* @details Get All Symbolic Names from configuration tool
* @implements DICU02123
* @{
*/
/*
* @violates @ref Icu_Cfg_h_1 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Icu_Cfg_h_2 Identifier clash.
*/        
    #define IcuConf_IcuChannel_IcuChannel_EdgeCounter  ((Icu_ChannelType)0U)
/*
* @violates @ref Icu_Cfg_h_1 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Icu_Cfg_h_2 Identifier clash.
*/        
    #define IcuConf_IcuChannel_IcuChannel_SignalMeasurement  ((Icu_ChannelType)1U)
/*
* @violates @ref Icu_Cfg_h_1 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Icu_Cfg_h_2 Identifier clash.
*/        
    #define IcuConf_IcuChannel_IcuChannel_Timestamp  ((Icu_ChannelType)2U)
/**@}*/

/**
* @brief ISR's configured for Icu channels
* @details Macros for channels used in ISR
* @{
*/
#define ICU_EMIOS_0_CH_6_ISR_USED
#define ICU_EMIOS_0_CH_7_ISR_USED
#define ICU_EMIOS_0_CH_8_ISR_USED
/**@}*/


/**
* @brief Signal measurement mode
* @details define SAIC mode if any channels not supporting IPWM or IPM mode is configured
* @{
*/

                                        /*
* @violates @ref Icu_Cfg_h_1 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Icu_Cfg_h_3 This is not a standard library macro, 
*/ 
#define SIGNAL_MEASUREMENT_USES_SAIC_MODE
/**@}*/
/*ICU DMA ISR macros*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief Implementation specific. This type shall be chosen in order to have the most efficient
*        implementation on a specific microcontroller platform.
*        Range: 0  to width of the timer register.
*        Description: Width of the buffer for timestamp ticks and measured elapsed timeticks
*/
typedef uint16 Icu_TimerRegisterWidthType;

/**
* @brief Implementation specific. This type shall be chosen in order to have the most efficient
*        implementation on a specific microcontroller platform.
*        Description: Type, to abstract the return value of the service Icu_GetTimestampIndex().
*/
typedef uint16 Icu_HwSpecificIndexType;

/**
* @brief Implementation specific. This type shall be chosen in order to have the most efficient
*        implementation on a specific microcontroller platform.
*        Description: Type, to abstract the return value of the service Icu_GetEdgeNumbers().
*/
typedef uint16 Icu_HwSpecificEdgeNumberType;




/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif    /* ICU_CFG_H */
/**@}*/

