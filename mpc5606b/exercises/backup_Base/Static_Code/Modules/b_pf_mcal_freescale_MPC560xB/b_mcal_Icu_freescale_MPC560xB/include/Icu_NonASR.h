/**
*     @file    Icu_NonASR.h
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - ICU driver non Autosar header file.
*     @details ICU driver header file, containing non Autosar API specification and other variables
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
*     Autosar ConfVariant
*     SWVersion           : 1.0.1
*     BuildVersion        : MPC560xB_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20140606
*
*     (c) Copyright 2006-2014 Freescale Semiconductor Inc and STMicroelectronics
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef ICU_NONASR_H
#define ICU_NONASR_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_NonASR_h_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
*@section Icu_NonASR_h_2
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
* @violates @ref Icu_NonASR_h_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Std_Types.h"
/*  @implements DICU01500 */
/*
* @violates @ref Icu_NonASR_h_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu.h"



/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*@implements     DICU01104, DICU01105, DICU01106, DICU01107, DICU01108, DICU01109, DICU01110*/
#define ICU_NONASR_VENDOR_ID_H                      43
#define MODULENAME_MODULE_ID                        122

/*
* @violates @ref Icu_NonASR_h_2 This violation cannot be fixed since naming convention of Identifiers (internal and external)
are followed as per Autosar standards ,some times which may exceeds more than 31 characters.
*/
#define ICU_NONASR_AR_RELEASE_MAJOR_VERSION_H       4
/*
* @violates @ref Icu_NonASR_h_2 This violation cannot be fixed since naming convention of Identifiers (internal and external)
are followed as per Autosar standards ,some times which may exceeds more than 31 characters.
*/
#define ICU_NONASR_AR_RELEASE_MINOR_VERSION_H       0
/*
* @violates @ref Icu_NonASR_h_2 This violation cannot be fixed since naming convention of Identifiers (internal and external)
are followed as per Autosar standards ,some times which may exceeds more than 31 characters.
*/
#define ICU_NONASR_AR_RELEASE_REVISION_VERSION_H    3
#define ICU_NONASR_SW_MAJOR_VERSION_H               1
#define ICU_NONASR_SW_MINOR_VERSION_H               0
#define ICU_NONASR_SW_PATCH_VERSION_H               1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
    /* Check if Icu_NonASR.h and Std_Types.h are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_NONASR_AR_RELEASE_MAJOR_VERSION_H != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_NONASR_AR_RELEASE_MINOR_VERSION_H != STD_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu_NonASR.h and Std_Types.h are different"
    #endif
#endif
/* Check if Icu_NonASR.h and Icu.h are of the same vendor */
#if (ICU_NONASR_VENDOR_ID_H != ICU_VENDOR_ID)
#error "Vendor IDs of Icu_NonASR.h and Icu.h are different"
#endif

/* Check if Icu_NonASR.h and Icu.h are of the same Software version */
#if ((ICU_NONASR_AR_RELEASE_MAJOR_VERSION_H != ICU_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_NONASR_AR_RELEASE_MINOR_VERSION_H != ICU_AR_RELEASE_MINOR_VERSION) || \
     (ICU_NONASR_AR_RELEASE_REVISION_VERSION_H != ICU_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_NonASR.h and Icu.h are different"
#endif

/* Check if Icu_NonASR.h and Icu.h are of the same Software version */
#if ((ICU_NONASR_SW_MAJOR_VERSION_H != ICU_SW_MAJOR_VERSION) || \
     (ICU_NONASR_SW_MINOR_VERSION_H != ICU_SW_MINOR_VERSION) || \
     (ICU_NONASR_SW_PATCH_VERSION_H != ICU_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_NonASR.h and Icu.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
#if (ICU_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief   API Icu_SetClockMode service called with wrong parameter
* @implements DICU01103
*/
#define ICU_E_PARAM_CLOCK_MODE          0x7AU

/**
* @brief   API service ID for Icu_SetClockMode function
* @details Parameters used when raising an error/exception
* @implements DICU01111
*/
#define ICU_SET_CLOCK_MODE_ID           0x7BU

#endif /* ICU_DUAL_CLOCK_MODE */

#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
/**
* @brief   API service ID for Icu_GetInputLevel function
* @details Parameters used when raising an error/exception
* @implements DICU01113
*/
#define ICU_GET_INPUT_LEVEL_ID          0x7CU

#endif /* ICU_GET_INPUT_LEVEL_API */

#ifdef ICU_GET_PULSE_WIDTH_API
#if (ICU_GET_PULSE_WIDTH_API == STD_ON)
/**
* @brief   API service ID for Icu_GetPulseWidth function
* @details Parameters used when raising an error/exception
* @implements DICU01117
*/
#define ICU_GET_PULSE_WIDTH_ID          0x7DU
#endif
#endif

#if (ICU_CAPTURERGISTER_API == STD_ON)
/**
* @brief   API service ID for Icu_GetCaptureRegisterValue function
* @details Parameters used when raising an error/exception
* @implements DICU01118
*/
#define ICU_CAPTUREREGISTER_ID         0x7EU
#endif
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

#if (ICU_DUAL_CLOCK_MODE == STD_ON)
/**
 * @brief   Definition of prescaler type.
 * @details Enumeration of available prescalers.
 *
 * @implements DICU01102
*/
typedef enum
{
    /* Default channel prescaler option */
    ICU_NORMAL    = 0x0U,
    /* Alternative prescaler to be used depending on user application ( e.g. low power modes ) */
    ICU_ALTERNATE = 0x1U
} Icu_SelectPrescalerType;

#endif /* ICU_DUAL_CLOCK_MODE */

#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
/**
 * @brief   Return the status of the pin.
 * @details Enumeration of to check the status of emios pin.
 *
 * @implements DICU01114
*/
typedef enum
{
    /* Default Input PIN Status */
    ICU_LEVEL_LOW    = 0x0U,
    /* As Icu_GetInputState do not give the Actual PIN status user can call the Non Autosar API
        Icu_GetInputLevel to get the Actual status of PIN*/
    ICU_LEVEL_HIGH = 0x1U
} Icu_LevelType;

#endif /* ICU_GET_INPUT_LEVEL_API */

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#define ICU_START_SEC_CODE
/*
* @violates @ref Icu_NonASR_h_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"



#if (ICU_DUAL_CLOCK_MODE == STD_ON)
/*================================================================================================*/
/*
* @brief      This function changes the channel prescaler.
* @details    This function sets all channels prescalers based on the input mode.
* @param[in]  Prescaler - Prescaler type ( Normal or Alternate )
* @pre        Icu_Init must be called before.
* @remarks    Covers ICU002, ICU111, ICU112, ICU022, ICU048, PR-MCAL-3195
* @remarks    Implements DICU10021
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_SetClockMode(VAR(Icu_SelectPrescalerType, AUTOMATIC) Prescaler);
#endif

#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
/*================================================================================================*/
/*
* @brief      This function returns the actual status of PIN.
* @details    This function returns the actual status o PIN .
* @param[in]     Channel          Numeric identifier of the ICU channel
* @return  void
* @pre        Icu_Init must be called before.
* @remarks    Covers PR-MCAL-3242
* @implements DICU01100
*/
/*================================================================================================*/
FUNC (Icu_LevelType, ICU_CODE) Icu_GetInputLevel(VAR(uint8, AUTOMATIC) Channel);
#endif

#ifdef ICU_GET_PULSE_WIDTH_API
#if (ICU_GET_PULSE_WIDTH_API == STD_ON)
/*================================================================================================*/
/**
 @brief      This function returns the signals High time, Low time and Period without using the
 *           channel interrupt.
 @details    This function returns the signals High time, Low time and Period without using the
 *           channel interrupt.
 @param[in]     Channel          Numeric identifier of the ICU channel
 @pre        Icu_Init must be called before.
 @implements DICU01116
*/
/*================================================================================================*/
extern FUNC (void, ICU_CODE) Icu_GetPulseWidth(VAR(uint8, AUTOMATIC) Channel);
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
extern FUNC (Icu_ValueType, ICU_CODE)   Icu_GetCaptureRegisterValue(VAR(Icu_ChannelType, \
                                                                         AUTOMATIC) Channel);
#endif /* ICU_CAPTURERGISTER_API == STD_ON */

#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_NonASR_h_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"



#ifdef __cplusplus
}
#endif

#endif  /* ICU_NONASR_H */
/** @} */

