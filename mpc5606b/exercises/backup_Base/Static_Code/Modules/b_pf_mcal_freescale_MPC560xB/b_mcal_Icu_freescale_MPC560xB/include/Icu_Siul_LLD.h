/**
*     @file    Icu_Siul_LLD.h
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - SIUL low level driver exported functions.
*     @details Interface between the high level driver (Autosar dependent) and the low level driver(platform dependent).
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

/*
* @file    Icu_Siul_LLD.h
*/

#ifndef ICU_SIUL_LLD_H
#define ICU_SIUL_LLD_H

#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_Siul_LLD_h_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Icu_Siul_LLD_h_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
*@section Icu_Siul_LLD_h_3
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
* @violates @ref Icu_Siul_LLD_h_2 precautions to prevent the
* contents of a header file being included twice */

#include "Std_Types.h"
/*
* @violates @ref Icu_Siul_LLD_h_2 precautions to prevent the
* contents of a header file being included twice
*/
#include "Reg_Macros.h"
/*
* @violates @ref Icu_Siul_LLD_h_2 precautions to prevent the
* contents of a header file being included twice
*/
/*     @implements     DICU04500 */
#include "Icu_Cfg.h"
/*
* @violates @ref Icu_Siul_LLD_h_2 precautions to prevent the
* contents of a header file being included twice
*/
#include "Reg_eSys_SIUL.h"


/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @implements     DICU04011, DICU04012, DICU04013, DICU04014, DICU04015, DICU04016, DICU04017
*/
#define ICU_SIUL_LLD_VENDOR_ID            43

/*
* @violates @ref Icu_Siul_LLD_h_3 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_LLD_AR_RELEASE_MAJOR_VERSION     4
/*
* @violates @ref Icu_Siul_LLD_h_3 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_LLD_AR_RELEASE_MINOR_VERSION     0
/*
* @violates @ref Icu_Siul_LLD_h_3 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_LLD_AR_RELEASE_REVISION_VERSION     3
#define ICU_SIUL_LLD_SW_MAJOR_VERSION     1
#define ICU_SIUL_LLD_SW_MINOR_VERSION     0
#define ICU_SIUL_LLD_SW_PATCH_VERSION     1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_SIUL_LLD_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_SIUL_LLD_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu_Siul_LLD.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and Icu_Cfg.h file are of the same vendor */
#if (ICU_SIUL_LLD_VENDOR_ID != ICU_VENDOR_ID_CFG)
#error "Icu_Siul_LLD.h and Icu.h have different vendor IDs"
#endif
#if ((ICU_SIUL_LLD_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ICU_SIUL_LLD_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ICU_SIUL_LLD_AR_RELEASE_REVISION_VERSION != ICU_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Icu_Siul_LLD.h and Icu_Cfg.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_SIUL_LLD_SW_MAJOR_VERSION != ICU_SW_MAJOR_VERSION_CFG) || \
     (ICU_SIUL_LLD_SW_MINOR_VERSION != ICU_SW_MINOR_VERSION_CFG) || \
     (ICU_SIUL_LLD_SW_PATCH_VERSION != ICU_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Icu_Siul_LLD.h and Icu_Cfg.h are different"
#endif


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

#if (IPV_SIUL ==  IPV_SIUL_01_00_01_15)
/**
* @{
* @brief   SIUL_IRQ_CHANNEL_MASK - used for masking IRQ Channels
* @remarks on this IP are available 32 channels
*/
#define SIUL_IRQ_CHANNEL_MASK            ((uint32)0xFFFFFFFFU)
/**@}*/
#elif (IPV_SIUL ==  IPV_SIUL_01_00_01_17)
/**
* @{
* @brief   SIUL_IRQ_CHANNEL_MASK - used for masking IRQ Channels
* @remarks on this IP are available 25 channels
*/
#define SIUL_IRQ_CHANNEL_MASK            ((uint32)0xFFFFFFFFU)
/**@}*/
#elif (IPV_SIUL ==  IPV_SIUL_01_00_02_02)
/**
@{
@brief   SIUL_IRQ_CHANNEL_MASK - used for masking IRQ Channels
@remarks on this IP are available 32 channels
*/
#define SIUL_IRQ_CHANNEL_MASK            ((uint32)0xFFFFFFFFU)
/**@}*/
#else
/**
* @{
* @brief   SIUL_IRQ_CHANNEL_MASK - used for masking IRQ Channels
* @remarks Beside IRQ Channels, SIUL provides also NMI capabilities. In order to not alter NMI
*          settings all the operations will be masked.
*/
#define SIUL_IRQ_CHANNEL_MASK            ((uint32)0x00FFFFFFU)
/**@}*/
#endif


/**
* @{
* @brief   SIUL_IRQ_CHANNEL_GROUP_MASK - used for masking a group of IRQ Channels
* @remarks The groups are mapped as follows IRQ0-IRQ7; IRQ8-IRQ15; IRQ16-IRQ23; IRQ24-IRQ31
*/
/*
* @violates @ref Icu_Siul_LLD_h_1 Function-like macro defined
*/

#define SIUL_IRQ_CHANNEL_GROUP_MASK(hwChannel) ((uint32)((BIT7|BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0) \
                                                                                    << (hwChannel)))
/*
* @violates @ref Icu_Siul_LLD_h_1 Function-like macro defined
*/
#define SIUL_CHANNEL_MASK(hwChannel) (((uint32)BIT0 << (uint32)(hwChannel)) & SIUL_IRQ_CHANNEL_MASK)


/**
* @{
* @brief SIUL_EIISR_ESEL - compute EIISR.ESEL bitfield value for a given channel
*/
/*
* @violates @ref Icu_Siul_LLD_h_1 Function-like macro defined
*/

#define SIUL_EIISR_ESEL(hwChannel, value) (((uint32)(value)) << ((uint32)(hwChannel) << (uint32)1U))

/**@}*/


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/**
* @brief         SIUL_ActivationType
* @details       This indicates the activation type SIUL channel (Rising, Falling or Both)
*
* @implements    DICU04021
*/
typedef enum
{

    SIUL_FALLING_EDGE = 0x0U,  /*< @brief  An appropriate action shall be executed when a falling
                               * edge occurs on the SIUL input signal. */

    SIUL_RISING_EDGE  = 0x1U,  /*< @brief  An appropriate action shall be executed when a rising
                               * edge occurs on the ICU input signal. */

    SIUL_BOTH_EDGES   = 0x2U  /*< @brief  An appropriate action shall be executed when a rising
                                *   edge or falling edge occurs on the ICU input signal. */
} SIUL_ActivationType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief            SIUL_Icu_IRQ_ParamType
* @details          SIUL Channel interrupt parameter type (i.e Interrupt registers)
*/
/*================================================================================================*/
typedef uint32 SIUL_Icu_IRQ_ParamType;

/*================================================================================================*/
/**
* @brief            SIUL_Icu_IRQ_ChannelType
* @details          Type for saving the SIUL interrupt channel id
* @implements       DICU04022
*/
/*================================================================================================*/
typedef uint8  SIUL_Icu_IRQ_ChannelType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
/*
* @violates @ref Icu_Siul_LLD_h_2 precautions to prevent the
* contents of a header file being included twice */

#include "MemMap.h"


FUNC (void, ICU_CODE) Icu_Siul_LLD_InitChannel(CONST(SIUL_Icu_IRQ_ParamType, AUTOMATIC) ParamValue,
                                              CONST(SIUL_Icu_IRQ_ChannelType, AUTOMATIC) hwChannel);


FUNC (void, ICU_CODE) Icu_Siul_LLD_DeInitChannel(VAR(SIUL_Icu_IRQ_ChannelType, AUTOMATIC)
                                                                                       hwChannel);


#if (ICU_SET_MODE_API == STD_ON)
FUNC (void, ICU_CODE) Icu_Siul_LLD_SetSleepMode(
                                               VAR(SIUL_Icu_IRQ_ChannelType, AUTOMATIC) hwChannel,
                                               VAR(boolean, AUTOMATIC) WakeUpEnabled);


FUNC (void, ICU_CODE) Icu_Siul_LLD_SetNormalMode(VAR(SIUL_Icu_IRQ_ChannelType, AUTOMATIC) hwChannel,
                                                VAR(boolean, AUTOMATIC) NotificationActive);
#endif  /* ICU_SET_MODE_API  */

/*
* @violates @ref Icu_Siul_LLD_h_3 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_Siul_LLD_SetActivationCondition(
                                                 VAR(SIUL_Icu_IRQ_ChannelType, AUTOMATIC) hwChannel,
                                                 VAR(SIUL_ActivationType, AUTOMATIC) Activation);


#if (ICU_EDGE_DETECT_API == STD_ON)
/*
* @violates @ref Icu_Siul_LLD_h_3 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_Siul_LLD_EnableEdgeDetection(
                                               VAR(SIUL_Icu_IRQ_ChannelType, AUTOMATIC) hwChannel);

/*
* @violates @ref Icu_Siul_LLD_h_3 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_Siul_LLD_DisableEdgeDetection(
                                               VAR(SIUL_Icu_IRQ_ChannelType, AUTOMATIC) hwChannel);
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_GET_INPUT_STATE_API == STD_ON)
FUNC (boolean, ICU_CODE) Icu_Siul_LLD_GetInputState(
                                              VAR(SIUL_Icu_IRQ_ChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_GET_INPUT_STATE_API */


#if (ICU_DUAL_CLOCK_MODE == STD_ON)
FUNC (void, ICU_CODE) SIUL_Icu_LLD_SelectPrescaler
                                          (CONST(SIUL_Icu_IRQ_ParamType, AUTOMATIC) ParamValue, 
                                          VAR(uint8, AUTOMATIC)IFCP_SIUL_Prescalar);
#endif  /* ICU_DUAL_CLOCK_MODE */

#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_Siul_LLD_h_2 precautions to prevent the
* contents of a header file being included twice  */

#include "MemMap.h"


#ifdef __cplusplus
}
#endif

#endif  /* ICU_SIUL_LLD_H */
/** @} */

