/**
 *     @file    Icu_Wkpu_LLD.h
 *     @version 1.0.1
 *
 *     @brief   AUTOSAR Icu - WKPU header file support for ICU driver.
 *     @details WKPU header file, containing the variables and functions that are exported by the WKPU driver.
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
 *     Autosar Version     : 4.0.3
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

/**
* @file    Icu_WKPU_LLD.h
* @remarks Implements DICU06201
*/

#ifndef WKPU_ICU_LLD_H
#define WKPU_ICU_LLD_H


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_WKPU_LLD_h_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Icu_WKPU_LLD_h_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
*@section Icu_WKPU_LLD_h_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
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
/**
* @file  Icu_WKPU_LLD.h
* @violates @ref Icu_WKPU_LLD_h_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
* contents of a header file being included twice
*/

#include "Std_Types.h"
/*
* @violates @ref Icu_WKPU_LLD_h_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Reg_Macros.h"
/*
* @violates @ref Icu_WKPU_LLD_h_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu_Cfg.h"
/*
* @violates @ref Icu_WKPU_LLD_h_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Reg_eSys_WKPU.h"



/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @brief   Header file version information
* @remarks Covers BSW00374, BSW00379, BSW00318
*/
#define WKPU_ICU_LLD_VENDOR_ID            43

/*
* @violates @ref Icu_WKPU_LLD_h_3 This is required as per autosar Requirement, 
*/
#define ICU_WKPU_LLD_H_AR_RELEASE_MAJOR_VERSION     4
/*
* @violates @ref Icu_WKPU_LLD_h_3 This is required as per autosar Requirement, 
*/
#define ICU_WKPU_LLD_H_AR_RELEASE_MINOR_VERSION     0
/*
* @violates @ref Icu_WKPU_LLD_h_3 This is required as per autosar Requirement, 
*/
#define ICU_WKPU_LLD_H_AR_RELEASE_REVISION_VERSION     3

#define ICU_WKPU_LLD_H_SW_MAJOR_VERSION     1
#define ICU_WKPU_LLD_H_SW_MINOR_VERSION     0
#define ICU_WKPU_LLD_H_SW_PATCH_VERSION     1
/**@}*/

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifdef CHECK_AUTOSAR_VERSION
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_WKPU_LLD_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_WKPU_LLD_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu_WKPU_LLD.h and Std_Types.h are different"
    #endif
    #endif
#endif

/* Check if header file and Icu_Cfg.h file are of the same vendor */
#if (WKPU_ICU_LLD_VENDOR_ID != ICU_VENDOR_ID_CFG)
#error "Icu_WKPU_LLD.h and Icu.h have different vendor IDs"
#endif
#ifdef CHECK_AUTOSAR_VERSION
    #if ((ICU_WKPU_LLD_H_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
         (ICU_WKPU_LLD_H_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
         (ICU_WKPU_LLD_H_AR_RELEASE_PATCH_VERSION != ICU_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Icu_WKPU_LLD.h and Icu_Cfg.h are different"
    #endif
#endif


/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_WKPU_LLD_H_SW_MAJOR_VERSION != ICU_SW_MAJOR_VERSION_CFG) || \
     (ICU_WKPU_LLD_H_SW_MINOR_VERSION != ICU_SW_MINOR_VERSION_CFG) || \
     (ICU_WKPU_LLD_H_SW_PATCH_VERSION != ICU_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Icu_WKPU_LLD.h and Icu_Cfg.h are different"
#endif


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/**
* @{
* @brief   WKPU_ISR_CHANNEL_MASK - used for masking IRQ Channels
* @remarks Beside IRQ Channels, SIU provides also NMI capabilities. In order to not alter NMI
* settings all the operations will be masked.
*/
#if (IPV_WKUP == IPV_WKUP_01_00_12_00)
#define WKPU_ISR_CHANNEL_MASK           ((uint32)0xFFFFFFFFU)
#else
#define WKPU_ISR_CHANNEL_MASK           ((uint32)0x1FFFFFFFU)
#endif
/**@}*/

/**
* @{
* @brief WKPU_CHANNEL_MASK - Used for masking WKPU IRQ channels
*/
/**
* @violates @ref Icu_WKPU_LLD_h_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/

#define WKPU_CHANNEL_MASK(hwChannel)     (((uint32)BIT0 << (uint32)(hwChannel)) &  \
                                                                              WKPU_ISR_CHANNEL_MASK)

/**@}*/

/**
* @{
* @brief   WKPU_IRQ_CHANNEL_GROUP_MASK - used for masking a group of IRQ Channels
* @remarks The groups are mapped as follows WKUP0-7; WKUP8-15; WKUP16-23; WKUP24-31
*/

/*
* @violates @ref Icu_WKPU_LLD_h_1 Function-like macro
*        defined
*/
#define WKPU_IRQ_CHANNEL_GROUP_MASK(hwChannel)   \
                                  ((uint32)((BIT7|BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0) << (hwChannel)))

/**@}*/

/**
* @{
* @brief WKPU_EIISR_ESEL - compute EIISR.ESEL bitfield value for a given channel
*/
/**
* @violates @ref Icu_WKPU_LLD_h_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/

#define WKPU_EIISR_ESEL(hwChannel, value)       (((uint32)(value)) << ((uint32)(hwChannel) <<  \
                                                                                        (uint32)1U))

/**@}*/


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*================================================================================================*/
/**
* @{
* @enum   WKPU_ActivationType
*         Type that indicates the channel activation type(Rising, Falling, Both Edges or Opposite
*         Edges).
*/
/*================================================================================================*/
typedef enum
{
    /** WKPU_FALLING_EDGE = An appropriate action shall be executed when a falling edge
        occurs on the WKPU input signal. */
    WKPU_FALLING_EDGE = 0x0U,
    /** WKPU_RISING_EDGE = An appropriate action shall be executed when a rising edge
        occurs on the WKPU input signal. */
    WKPU_RISING_EDGE  = 0x1U,
    /** WKPU_BOTH_EDGES = An appropriate action shall be executed when a falling edge or
        rising edge occurs on the WKPU input signal. */
    WKPU_BOTH_EDGES   = 0x2U
} WKPU_ActivationType;
/**@}*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*================================================================================================*/
/**
* @typedef   WKPU_Icu_ParamType
*            WKPU Channel parameter type (i.e used for register values)
*/
/*================================================================================================*/
typedef uint32 WKPU_Icu_ParamType;

/*================================================================================================*/
/**
* @typedef   WKPU_Icu_ChannelType
*            Type for saving the WKPU channel id
*/
/*================================================================================================*/
typedef uint8  WKPU_Icu_ChannelType;


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE

/*
* @violates @ref Icu_WKPU_LLD_h_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"


/*================================================================================================*/
/**
* @brief      Icu driver function that initializes WKPU channel.
* @details    This function:
*              - Disables IRQ Interrupt
*              - Sets Interrupt Filter Enable Register
*              - Sets Wakeup/Interrupt Pull-up Enable Register
*              - Sets Activation Condition
*
* @param[in]  ParamValue - Wake interrupt value
* @param[in]  hwChannel - Wake channel
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_WKPU_LLD_InitChannel(CONST(WKPU_Icu_ParamType, AUTOMATIC) ParamValue,
                                               CONST(WKPU_Icu_ChannelType, AUTOMATIC) hwChannel);

/*================================================================================================*/
/**
* @brief      Icu driver function that initializes WKPU channel.
* @details    This function:
*              - Disables IRQ Interrupt
*              - Clears Wakeup/Interrupt Filter Enable Register
*              - Clears Wakeup/Interrupt Pull-up Enable Register
*              - Clears edge event enable registers
*              - Clear Interrupt Filter Enable Register
*
* @param[in]  hwChannel   - WKUP HW Channel
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_WKPU_LLD_DeInitChannel(VAR(WKPU_Icu_ChannelType, AUTOMATIC) hwChannel);

#if (ICU_SET_MODE_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu driver function that sets WKPU channel to SLEEP mpde
* @details    This function enables the interrupt for WKUP channel if wakeup is enabled for the
*             channel
*
* @param[in]  hwChannel       - IRQ HW Channel
* @param[in]  WakeUpEnabled   - channel wakeup feature is enabled
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_WKPU_LLD_SetSleepMode(VAR(WKPU_Icu_ChannelType, AUTOMATIC) hwChannel,
                                                VAR(boolean, AUTOMATIC) WakeUpEnabled);

/*================================================================================================*/
/**
* @brief      Icu driver function that sets WKPU channel to NORMAL mpde
* @details    This function enables the interrupt for WKUP channel if Notifcation is enabled
*             for the channel
*
* @param[in]  hwChannel IRQ HW Channel
* @param[in]  NotificationActive  - channel notification is activated
*
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_WKPU_LLD_SetNormalMode(VAR(WKPU_Icu_ChannelType, AUTOMATIC) hwChannel,
                                                 VAR(boolean, AUTOMATIC) NotificationActive);
#endif  /* ICU_SET_MODE_API  */

/*================================================================================================*/
/**
* @brief      Icu driver function that sets activation condition of WKUP channel
* @details    This function enables the requested activation condition(rising, falling or both
*             edges)for corresponding WKPU channels.
*
* @param[in]  hwChannel - Wake up hardware channel
* @param[in]  Activation - activation condition
*/
/*================================================================================================*/
/*
* @violates @ref Icu_WKPU_LLD_h_3 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_WKPU_LLD_SetActivationCondition(
                                                    VAR(WKPU_Icu_ChannelType, AUTOMATIC) hwChannel,
                                                    VAR(WKPU_ActivationType, AUTOMATIC) Activation);


#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu_WKPU_LLD_EnableEdgeDetection
 * @details    WKPU IP function that starts the edge detection service for an WKPU channel
 *
 * @param[in]      hwChannel   - WKPU encoded hardware channel
 *
 * @return void
 *
 * @implements
*/
/*================================================================================================*/
/*
* @violates @ref Icu_WKPU_LLD_h_3 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_WKPU_LLD_EnableEdgeDetection(VAR(uint8, AUTOMATIC) hwChannel);
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu_WKPU_LLD_DisableEdgeDetection
 * @details    WKPU IP function that stops the edge detection service for an WKPU channel
 *
 * @param[in]      hwChannel   - WKPU encoded hardware channel
 *
 * @return void
 *
 * @implements
*/
/*================================================================================================*/
/*
* @violates @ref Icu_WKPU_LLD_h_3 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_WKPU_LLD_DisableEdgeDetection(VAR(uint8, AUTOMATIC) hwChannel);
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu driver function that gets the input state of WKPU channel.
* @details    This function:
*             - Checks if interrupt flags for corresponding WKPU channel is set then
*             it clears the interrupt flag and returns the value as true.
*
* @param[in]  hwChannel - IRQ HW Channel
*
* @return     boolean
*              - true - if channel is active
*              - false - If channel is in idle
*/
/*================================================================================================*/
FUNC (boolean, ICU_CODE) Icu_WKPU_LLD_GetInputState(VAR(WKPU_Icu_ChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_GET_INPUT_STATE_API */

/*==================================================================================================*/
/**
@brief      The function enables pull up for not configured and unavailable Wakeup pins.
@details    This function:
            The function enables pull up for not configured and unavailable Wakeup pins.

@param[in]  hwChannel - PullUpEnable

@return  
*/
/*==================================================================================================*/
/*
* @violates @ref Icu_WKPU_LLD_h_3 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) WKPU_LLD_PullUpNonBondedWakeupPin(void);

#define ICU_STOP_SEC_CODE

/*
* @violates @ref Icu_WKPU_LLD_h_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"


#ifdef __cplusplus
}
#endif

#endif  /* WKPU_ICU_LLD_H */
/**@}*/
