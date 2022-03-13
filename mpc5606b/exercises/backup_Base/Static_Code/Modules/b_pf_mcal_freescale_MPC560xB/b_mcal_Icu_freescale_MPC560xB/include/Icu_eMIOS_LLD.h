/**
*   @file    Icu_eMIOS_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Icu - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup ICU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS
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
#ifndef ICU_EMIOS_LLD_H
#define ICU_EMIOS_LLD_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_eMIOS_LLD_h_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
*@section Icu_eMIOS_LLD_h_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
* @section Icu_eMIOS_LLD_h_3
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Icu_eMIOS_LLD_h_1 precautions to prevent the contents of a header file being
*           included twice
*/
#include "Std_Types.h"
/* @implements     DICU03700 */
/*
* @violates @ref Icu_eMIOS_LLD_h_1 precautions to prevent the contents of a header file being
*           included twice
*/
#include "Icu.h"
#include "Icu_Cfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @implements     DICU03001, DICU03002, DICU03003, DICU03004, DICU03005, DICU03006, DICU03007 */
#define ICU_EMIOS_LLD_H_VENDOR_ID                           43
#define ICU_EMIOS_LLD_H_MODULE_ID                           122

/*
* @violates @ref Icu_eMIOS_LLD_h_2 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION            4
/*
* @violates @ref Icu_eMIOS_LLD_h_2 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION            0
/*
* @violates @ref Icu_eMIOS_LLD_h_2 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_LLD_H_AR_RELEASE_REVISION_VERSION         3
/*
* @violates @ref Icu_eMIOS_LLD_h_2 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_LLD_H_SW_MAJOR_VERSION                    1
/*
* @violates @ref Icu_eMIOS_LLD_h_2 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_LLD_H_SW_MINOR_VERSION                    0
/*
* @violates @ref Icu_eMIOS_LLD_h_2 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_LLD_H_SW_PATCH_VERSION                    1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Icu_eMIOS_LLD.h file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
           (ICU_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu_eMIOS_LLD.h and Std_Types.h are different"
    #endif
#endif

/* Check if Icu_eMIOS_LLD.h file and Icu_Cfg.h header file are of the same vendor */
#if (ICU_EMIOS_LLD_H_VENDOR_ID != ICU_VENDOR_ID_CFG)
    #error "Icu_eMIOS_LLD.h and Icu_Cfg.h have different vendor IDs"
#endif

/* Check if Icu_eMIOS_LLD.h file and Icu_Cfg.h file are of the same Autosar version */
#if ((ICU_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
        (ICU_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
        (ICU_EMIOS_LLD_H_AR_RELEASE_REVISION_VERSION != ICU_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Icu_eMIOS_LLD.h and Icu_Cfg.h are different"
#endif

/* Check if Icu_eMIOS_LLD.h file and Icu_Cfg.h header file are of the same Software version */
#if ((ICU_EMIOS_LLD_H_SW_MAJOR_VERSION != ICU_SW_MAJOR_VERSION_CFG) || \
        (ICU_EMIOS_LLD_H_SW_MINOR_VERSION != ICU_SW_MINOR_VERSION_CFG) || \
        (ICU_EMIOS_LLD_H_SW_PATCH_VERSION != ICU_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Icu_eMIOS_LLD.h and Icu_Cfg.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief ID for edge overflow
* @details Additional errors that are detected because of specific implementation
*         and/or specific hardware properties shall be added in the ICU device specific
*         implementation specification. The classification and enumeration shall be compatible
*         with the errors listed above.
* @implements  DICU03027
*/
#define ICU_E_EDGE_OVERFLOW     (0x18U)

/**
* @brief   Define for configuring Falling edge
* @details To automatically set the value in the eMios cfg register
* @implements DICU03020
*/
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_FALLING_EDGE_PARAM     ((uint32)((0x0U << CCR_EDSEL_SHIFT)|(0x0U << CCR_EDPOL_SHIFT)))

/**
* @brief   Define for configuring Rising edge
* @details To automatically set the value in the eMios cfg register
* @implements DICU03026
*/
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_RISING_EDGE_PARAM      ((uint32)((0x0U << CCR_EDSEL_SHIFT)|(BIT0 << CCR_EDPOL_SHIFT)))

/**
* @brief   Define for configuring Both edge
* @details To automatically set the value in the eMios cfg register
* @implements DICU03011
*/
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_BOTH_EDGES_PARAM       ((uint32)((BIT0 << CCR_EDSEL_SHIFT)|(0x0U << CCR_EDPOL_SHIFT)))

/**
* @brief EMIOS unified channel specific control register bits desctiption
* @note Hardware Dependent Definition - DO NOT CHANGE
*/
/**
* @brief EMIOS unified channel bus source control
* @note Hardware Dependent Definition - DO NOT CHANGE
* @implements DICU03012
*/
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_BUS_A                         ((uint32)0x0U)
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_BUS_DIVERSE                   ((uint32)0x1U)

/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_BUS_F                         ((uint32)0x2U)

/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_BUS_INTERNAL_COUNTER          ((uint32)0x3U)
/**
* @brief EMIOS unified channel digital filter control
* @note Hardware Dependent Definition - DO NOT CHANGE
* @implements DICU03019
*/
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_DIGITAL_FILTER_BYPASSED       ((uint32)0U)
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_DIGITAL_FILTER_02             ((uint32)BIT0)
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_DIGITAL_FILTER_04             ((uint32)BIT1)
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_DIGITAL_FILTER_08             ((uint32)BIT2)
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_DIGITAL_FILTER_16             ((uint32)BIT3)
/**
* @brief EMIOS unified channel prescaller control
* @note Hardware Dependent Definition - DO NOT CHANGE
* @implements DICU03007
*/
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_PRESCALER_DIVIDE_1            ((uint32)0U)
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_PRESCALER_DIVIDE_2            ((uint32)1U)
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_PRESCALER_DIVIDE_3            ((uint32)2U)
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_PRESCALER_DIVIDE_4            ((uint32)3U)
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_FREEZE_ENABLE                 ((uint32)0x1U)

/**
* @brief EMIOS controller register values
* @implements DICU03013,DICU03014,DICU03015,DICU03016,DICU03017,DICU03018,DICU03021,DICU03022,
*             DICU03023
*/
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_CCR_CLEAR                     ((uint32)0x00000000U)
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_CADR_CLEAR                    ((uint32)0x00000000U)
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_INIT_CADR                     ((uint32)0x00FFFFFFU)
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_CBDR_CLEAR                    ((uint32)0x00000000U)
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_CCNTR_CLEAR                   ((uint32)0x00000000U)
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_INIT_CCNTR                    ((uint32)0x00000001U)
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_CCNTR_INIT                    ((uint32)0x00000000U)
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_CSR_CLEAR                     ((uint32)0xFFFFFFFFU)
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_IFER_ENABLE                   ((uint32)0x0000FFFFU)
/*
* @violates @ref Icu_eMIOS_LLD_h_3 This is not a standard library macro, 
*/
#define EMIOS_UCPRE_CLEAR                   ((uint32)0xF3FFFFFFU)
/**
* @brief Number of channels on a eMIOS module
* @implements DICU03024
*/
#define eMIOS_N_CHANNELS   32U

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief    eMIOS_ChannelModeType
* @details  Type that indicates the channel mode type(Counter mode, Detect mode or Capture mode).
* @implements DICU03009
*/
/*================================================================================================*/
typedef enum
{
    /** EMIOS_CHANNEL_MODE_EDGE_DETECT = Mode for detecting edges. */
    EMIOS_CHANNEL_MODE_EDGE_DETECT = 0U,
    /** EMIOS_CHANNEL_MODE_EDGE_COUNTER = Mode for counting edges on configurable edges. */
    EMIOS_CHANNEL_MODE_EDGE_COUNTER,
    /** EMIOS_CHANNEL_MODE_CAPTURE_MODE = Mode for capturing edges. */
    EMIOS_CHANNEL_MODE_CAPTURE_MODE
} eMIOS_ChannelModeType;

/*================================================================================================*/
/**
* @brief    eMIOS_ActivationType
* @details  Type that indicates the channel activation type(Rising, Falling, Both Edges or Opposite
*           Edges).
* @implements DICU03008
*/
/*================================================================================================*/
typedef enum
{
    /** EMIOS_OPPOSITE_EDGES = An appropriate action shall be executed when either a falling or
        rising edge occur on the ICU input signal. */
#ifdef SIGNAL_MEASUREMENT_USES_SAIC_MODE
    EMIOS_OPPOSITE_EDGES    = 0x3U,
#endif   /* SIGNAL_MEASUREMENT_USES_SAIC_MODE */
    /** EMIOS_FALLING_EDGE = An appropriate action shall be executed when a falling edge occurs
        on the ICU input signal. */
    EMIOS_FALLING_EDGE      = 0x0U,
    /** EMIOS_RISING_EDGE = An appropriate action shall be executed when a rising edge occurs on
        the ICU input signal.*/
    EMIOS_RISING_EDGE       = 0x1U,
    /** EMIOS_RISING_EDGE = An appropriate action shall be executed when either a rising or
        falling edge occur on the ICU input signal.*/
    EMIOS_BOTH_EDGES        = 0x2U
} eMIOS_ActivationType;

/*================================================================================================*/
/**
* @brief    eMIOS_OperationMode
* @details  eMIOS Unified Channel Modes of Operation.
*           These macros are used in ICU plug-in for specifying the UC mode to be used
* @implements DICU03010
*/
/*================================================================================================*/
typedef enum
{
    /** EMIOS_UC_DAOC_MODE = eMIOS channel in default mode */
    EMIOS_UC_UNSPECIFIED_MODE = 0x0U,
    /** EMIOS_UC_DAOC_MODE = eMIOS channel in Double Action Output Compare mode */
    EMIOS_UC_DAOC_MODE,
    /** EMIOS_UC_GPIO_MODE = eMIOS channel in General purpose Input/Output mode */
    EMIOS_UC_GPIO_MODE,
    /** EMIOS_UC_IPM_MODE = eMIOS channel in Input Period Measurement mode */
    EMIOS_UC_IPM_MODE,
    /** EMIOS_UC_IPWM_MODE = eMIOS channel in Input Pulse Width Measurement mode */
    EMIOS_UC_IPWM_MODE,
    /** EMIOS_UC_MC_MODE = eMIOS channel in Modulus Counter mode */
    EMIOS_UC_MC_MODE,
    /** EMIOS_UC_MCB_MODE = eMIOS channel in Modulus Counter Buffered mode */
    EMIOS_UC_MCB_MODE,
    /** EMIOS_UC_OPWMB_MODE = eMIOS channel in Output Pulse Width Modulation Buffered mode */
    EMIOS_UC_OPWMB_MODE,
    /** EMIOS_UC_OPWMT_MODE = eMIOS channel in Output Pulse Width Modulation with Trigger
        mode */
    EMIOS_UC_OPWMT_MODE,
    /** EMIOS_UC_OPWFMB_MODE = eMIOS channel in Output Pulse Width and Frequency
        Modulation Buffered mode*/
    EMIOS_UC_OPWFMB_MODE,
    /** EMIOS_UC_OPWMCB_MODE = eMIOS channel in Output Pulse Width Modulation
        Counter Buffered mode */
    EMIOS_UC_OPWMCB_MODE,
    /** EMIOS_UC_SAIC_MODE = eMIOS channel in Single Action Input Capture mode */
    EMIOS_UC_SAIC_MODE,
    /** EMIOS_UC_SAOC_MODE = eMIOS channel in Single Action Output Capture mode */
    EMIOS_UC_SAOC_MODE
} eMIOS_OperationMode;


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/



/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
/*
* @violates @ref Icu_eMIOS_LLD_h_1 precautions to prevent the contents of a header file being
*           included twice
*/
#include "MemMap.h"

/*================================================================================================*/

FUNC (boolean, ICU_CODE) Icu_eMIOS_LLD_CheckOverflowFlag(CONST(uint32, AUTOMATIC) flags);

/*================================================================================================*/

FUNC (void, ICU_CODE) Icu_eMIOS_LLD_InitChannel(CONST(uint32, AUTOMATIC) ParamValue,
                                                CONST(uint8, AUTOMATIC) hwChannel);

/*================================================================================================*/

FUNC (void, ICU_CODE) Icu_eMIOS_LLD_DeInitChannel(
                                                CONST(uint8, AUTOMATIC) hwChannel,
                                                VAR(boolean,AUTOMATIC) reg_EMIOSCNT_available,
                                                VAR(boolean,AUTOMATIC) reg_EMIOSB_available);

/*================================================================================================*/
#if (ICU_SET_MODE_API == STD_ON)


FUNC (void, ICU_CODE) Icu_eMIOS_LLD_SetSleepMode(
                                                VAR(uint8, AUTOMATIC) hwChannel,
                                                VAR(boolean, AUTOMATIC) WakeUpEnabled,
                                                CONST(Icu_MeasurementModeType, AUTOMATIC) channelMode);

FUNC (void, ICU_CODE) Icu_eMIOS_LLD_SetNormalMode(
                                                VAR(uint8, AUTOMATIC) hwChannel,
                                                VAR(boolean, AUTOMATIC) NotificationActive,
                                                CONST(Icu_MeasurementModeType, AUTOMATIC) channelMode);

#endif  /* ICU_SET_MODE_API */


/*================================================================================================*/
/*
* @violates @ref Icu_eMIOS_LLD_h_2 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_eMIOS_LLD_SetActivationCondition(
                                                VAR(uint8, AUTOMATIC) hwChannel,
                                                VAR(eMIOS_ActivationType, AUTOMATIC) activation);

/*================================================================================================*/

#if (ICU_GET_INPUT_STATE_API == STD_ON)

FUNC (boolean, ICU_CODE) Icu_eMIOS_LLD_GetInputState(VAR(uint8, AUTOMATIC) hwChannel);

#endif /* ICU_GET_INPUT_STATE_API */


/*================================================================================================*/
#if (ICU_TIMESTAMP_API == STD_ON)
FUNC (void, ICU_CODE) Icu_eMIOS_LLD_StartTimestamp(VAR(uint8, AUTOMATIC) hwChannel);

FUNC (void, ICU_CODE) Icu_eMIOS_LLD_StopTimestamp(VAR(uint8, AUTOMATIC) hwChannel);

FUNC(uint32, ICU_CODE) Icu_eMIOS_LLD_GetTimeStamp(VAR(uint8, AUTOMATIC) hwChannel);

#endif /* ICU_TIMESTAMP_API */


/*================================================================================================*/
#if (ICU_EDGE_COUNT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_eMIOS_LLD_ResetEdgeCount(VAR(uint8, AUTOMATIC) hwChannel);

FUNC (void, ICU_CODE) Icu_eMIOS_LLD_EnableEdgeCount(
                                                VAR(uint8, AUTOMATIC) hwChannel,
                                                VAR(uint32, AUTOMATIC) startValue);

FUNC (void, ICU_CODE) Icu_eMIOS_LLD_DisableEdgeCount(
                                            VAR(uint8, AUTOMATIC) hwChannel,
                                            P2VAR(uint32, AUTOMATIC, ICU_APPL_DATA) currentValue );

FUNC (uint32, ICU_CODE) Icu_eMIOS_LLD_GetEdgeNumbers(VAR(uint8, AUTOMATIC) hwChannel);

#endif /* ICU_EDGE_COUNT_API */


/*================================================================================================*/
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/*
* @violates @ref Icu_eMIOS_LLD_h_2 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_eMIOS_LLD_StartSignalMeasurement(
                                                VAR(uint8, AUTOMATIC) hwChannel,
                                                VAR(eMIOS_ActivationType, AUTOMATIC) activation,
                                                VAR(eMIOS_OperationMode, AUTOMATIC) mode);
/*
* @violates @ref Icu_eMIOS_LLD_h_2 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_eMIOS_LLD_StopSignalMeasurement(VAR(uint8, AUTOMATIC) hwChannel);
#endif  /* ICU_SIGNAL_MEASUREMENT_API */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON) || (ICU_CAPTURERGISTER_API == STD_ON)
FUNC(uint32, ICU_CODE) Icu_eMIOS_LLD_GetCaptureRegA(VAR(uint8, AUTOMATIC) hwChannel);

FUNC(uint32, ICU_CODE) Icu_eMIOS_LLD_GetCaptureRegB(VAR(uint8, AUTOMATIC) hwChannel);
#endif



#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/*
* @violates @ref Icu_eMIOS_LLD_h_2 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_eMios_LLD_EnableEdgeDetection(VAR(uint8, AUTOMATIC) hwChannel);
#endif /* ICU_EDGE_DETECT_API */

/*================================================================================================*/

#if (ICU_EDGE_DETECT_API == STD_ON)
/*
* @violates @ref Icu_eMIOS_LLD_h_2 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_eMios_LLD_DisableEdgeDetection(VAR(uint8, AUTOMATIC) hwChannel);
#endif /* ICU_EDGE_DETECT_API */

/*================================================================================================*/
#if (ICU_DUAL_CLOCK_MODE == STD_ON)

FUNC (void, ICU_CODE) Icu_eMIOS_LLD_SelectPrescaler(
                                                    CONST(uint32, AUTOMATIC) ParamValue,
                                                    CONST(uint8, AUTOMATIC) hwChannel);

#endif  /* ICU_DUAL_CLOCK_MODE */

/*================================================================================================*/

FUNC (boolean, ICU_CODE) Icu_eMIOS_LLD_GetInputLevel(VAR(uint8, AUTOMATIC) hwChannel);


/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_eMIOS_LLD_ProcessInterrupt(CONST(uint8, AUTOMATIC) hwChannel);

#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_eMIOS_LLD_h_1 precautions to prevent the contents of a header file being
*           included twice
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* ICU_EMIOS_LLD_H */
/** @} */
