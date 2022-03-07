/**
*   @file    Dio_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Dio configuration header.
*   @details This file is the Autosar DIO driver configuration header. This
*            file is automatically generated, do not modify manually.
*
*   @requirements .
*   @implements   DDIO04010.
*
*   @addtogroup DIO_CFG
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : SIUL
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

#ifndef DIO_CFG_H
#define DIO_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Dio_CFG_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Dio_CFG_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 
* 31 character signifiance and case sensitivity are supported for external identifiers.
*
* @section Dio_CFG_REF_4
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*
* @section Dio_CFG_REF_5
* Violates MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string literal, a
* parenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*
* @section Dio_CFG_REF_6
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only 
* accessed from within a single function.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define DIO_VENDOR_ID_CFG                   43
/*
* @violates @ref Dio_CFG_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define DIO_AR_RELEASE_MAJOR_VERSION_CFG    4
/*
* @violates @ref Dio_CFG_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
/* @violates @ref Dio_CFG_REF_3 MISRA 2004 Advisory Rule 1.4, The compiler/linker shall be checked to ensure that
   31 character signifiance and case sensitivity are supported for external identifiers.
*/
#define DIO_AR_RELEASE_MINOR_VERSION_CFG    0
/*
* @violates @ref Dio_CFG_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
/* @violates @ref Dio_CFG_REF_3 MISRA 2004 Advisory Rule 1.4, The compiler/linker shall be checked to ensure that
   31 character signifiance and case sensitivity are supported for external identifiers.
*/
#define DIO_AR_RELEASE_REVISION_VERSION_CFG 3
#define DIO_SW_MAJOR_VERSION_CFG            1
#define DIO_SW_MINOR_VERSION_CFG            0
#define DIO_SW_PATCH_VERSION_CFG            1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/**
* @brief          Enable/Disable Development Error Detection.
*
* @implements     DDIO04017.
*
* @api
*/
#define DIO_DEV_ERROR_DETECT        (STD_ON)

/**
* @brief          Function @p Dio_GetVersionInfo() enable switch.
*
* @api
*/
#define DIO_VERSION_INFO_API        (STD_OFF)

/**
* @brief          Function @p Dio_FlipChannel() enable switch.
*
* @api
*/
#define DIO_FLIP_CHANNEL_API        (STD_OFF)

/**
* @brief          Function @p Dio_MaskedWritePort() enable switch.
*
* @api
*/
#define DIO_MASKEDWRITEPORT_API     (STD_OFF)

/**
* @brief          Undefined pins masking enable switch.
*
* @api
*/
#define DIO_READZERO_UNDEFINEDPORTS (STD_OFF)

/**
* @brief          Number of pin intervals.
*
* @note           Used for DET checking.
*
* @api
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DIO_PIN_INTERVALS           (uint8)0x2

/**
* @brief          Number of port intervals.
* @note           Used for @p DIO_READZERO_UNDEFINEDPORTS.
*
* @api
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DIO_PORT_INTERVALS          (uint8)0x2

/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
/**
* @brief          Reversed port functionality enable switch.
*
* @api
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DIO_REVERSEPORTBITS STD_OFF

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief          Type of a DIO port representation.
*
* @requirements   .
* @implements     DDIO04021.
*
* @api
*/
typedef uint8 Dio_PortType;

/*
* @brief          Type of a DIO channel representation.
*
* @requirements   .
* @implements     DDIO04019.
*
* @api
*/
typedef uint8 Dio_ChannelType;

/*
* @brief          Type of a DIO port levels representation.
*
* @requirements   .
* @implements     DDIO04020.
*
* @api
*/
typedef uint16 Dio_PortLevelType;

/**
* @brief          Type of a DIO channel levels representation.
*
* @requirements   .
* @implements     DDIO04024.
*
* @api
*/
typedef uint8 Dio_LevelType;

/**
* @brief          Type of a DIO configuration structure.
*
* @note           In this implementation there is no need for a configuration
*                 structure there is only a dummy field, it is recommended
*                 to initialize this field to zero.
*
* @requirements   .
* @implements     DDIO04023.
*
* @api
*/
typedef struct
{
    VAR(uint8, DIO_VAR) dummy;                /**< @brief Dummy field,
                                                   structs cannot be empty. */
} Dio_ConfigType;

/**
* @brief          Type of a DIO channel group representation.
*
* @requirements   .
* @implements     DDIO04022.
*
* @api
*/
typedef struct
{
    VAR(Dio_PortType, DIO_VAR) port;          /**< @brief Port identifier.  */
    VAR(uint8, DIO_VAR) offset;   /**< @brief Bit offset within
                                                   the port.                */
    VAR(Dio_PortLevelType, DIO_VAR) mask;     /**< @brief Group mask.       */
} Dio_ChannelGroupType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/*
* @violates @ref Dio_CFG_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define DIO_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "MemMap.h"
/*
* @violates @ref Dio_CFG_REF_6 Objects shall be defined at block scope if they are only
* accessed from within a single function.
*/
extern CONST(Dio_ChannelType, DIO_CONST) valid_pin_ranges[DIO_PIN_INTERVALS];
/*
* @violates @ref Dio_CFG_REF_6 Objects shall be defined at block scope if they are only
* accessed from within a single function.
*/
extern CONST(Dio_PortType, DIO_CONST) valid_port_ranges[DIO_PORT_INTERVALS];
/*
* @violates @ref Dio_CFG_REF_6 Objects shall be defined at block scope if they are only
* accessed from within a single function.
*/


/* ========== MODULE-CONFIGURATION ========== */
extern CONST(Dio_ConfigType, DIO_CONST) DioConfig_0;

/* ---------- DioPort_A ---------- */

/**
* @brief          Symbolic name for the port DioPort_A.
*
* @requirements   .
* @implements     DDIO04009.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioPort_DioPort_A (Dio_PortType)0x00U

/**
* @brief          Symbolic name for the channel DioPort_A_DioChannel_0.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_A_DioChannel_0 (Dio_ChannelType)0x00U

/**
* @brief          Symbolic name for the channel DioPort_A_DioChannel_1.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_A_DioChannel_1 (Dio_ChannelType)0x01U

/**
* @brief          Symbolic name for the channel DioPort_A_DioChannel_10.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_A_DioChannel_10 (Dio_ChannelType)0x0aU

/**
* @brief          Symbolic name for the channel DioPort_A_DioChannel_11.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_A_DioChannel_11 (Dio_ChannelType)0x0bU

/**
* @brief          Symbolic name for the channel DioPort_A_DioChannel_12.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_A_DioChannel_12 (Dio_ChannelType)0x0cU

/**
* @brief          Symbolic name for the channel DioPort_A_DioChannel_13.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_A_DioChannel_13 (Dio_ChannelType)0x0dU

/**
* @brief          Symbolic name for the channel DioPort_A_DioChannel_14.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_A_DioChannel_14 (Dio_ChannelType)0x0eU

/**
* @brief          Symbolic name for the channel DioPort_A_DioChannel_15.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_A_DioChannel_15 (Dio_ChannelType)0x0fU

/**
* @brief          Symbolic name for the channel DioPort_A_DioChannel_2.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_A_DioChannel_2 (Dio_ChannelType)0x02U

/**
* @brief          Symbolic name for the channel DioPort_A_DioChannel_3.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_A_DioChannel_3 (Dio_ChannelType)0x03U

/**
* @brief          Symbolic name for the channel DioPort_A_DioChannel_4.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_A_DioChannel_4 (Dio_ChannelType)0x04U

/**
* @brief          Symbolic name for the channel DioPort_A_DioChannel_5.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_A_DioChannel_5 (Dio_ChannelType)0x05U

/**
* @brief          Symbolic name for the channel DioPort_A_DioChannel_6.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_A_DioChannel_6 (Dio_ChannelType)0x06U

/**
* @brief          Symbolic name for the channel DioPort_A_DioChannel_7.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_A_DioChannel_7 (Dio_ChannelType)0x07U

/**
* @brief          Symbolic name for the channel DioPort_A_DioChannel_8.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_A_DioChannel_8 (Dio_ChannelType)0x08U

/**
* @brief          Symbolic name for the channel DioPort_A_DioChannel_9.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_A_DioChannel_9 (Dio_ChannelType)0x09U

extern CONST(Dio_ChannelGroupType, DIO_CONST) WdgExtGroup_PA10;

/**
* @brief        Symbolic name for the channel group DioChannelGroup_ExtWdg.
*
* @requirements .
* @implements   DDIO04025.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
/*
* @violates @ref Dio_CFG_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define DioConf_DioChannelGroupIdentification_DioChannelGroup_ExtWdg &WdgExtGroup_PA10

/* ---------- DioPort_B ---------- */

/**
* @brief          Symbolic name for the port DioPort_B.
*
* @requirements   .
* @implements     DDIO04009.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioPort_DioPort_B (Dio_PortType)0x01U

/**
* @brief          Symbolic name for the channel DioPort_B_DioChannel_0.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_B_DioChannel_0 (Dio_ChannelType)0x10U

/**
* @brief          Symbolic name for the channel DioPort_B_DioChannel_1.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_B_DioChannel_1 (Dio_ChannelType)0x11U

/**
* @brief          Symbolic name for the channel DioPort_B_DioChannel_10.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_B_DioChannel_10 (Dio_ChannelType)0x1aU

/**
* @brief          Symbolic name for the channel DioPort_B_DioChannel_11.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_B_DioChannel_11 (Dio_ChannelType)0x1bU

/**
* @brief          Symbolic name for the channel DioPort_B_DioChannel_12.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_B_DioChannel_12 (Dio_ChannelType)0x1cU

/**
* @brief          Symbolic name for the channel DioPort_B_DioChannel_13.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_B_DioChannel_13 (Dio_ChannelType)0x1dU

/**
* @brief          Symbolic name for the channel DioPort_B_DioChannel_14.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_B_DioChannel_14 (Dio_ChannelType)0x1eU

/**
* @brief          Symbolic name for the channel DioPort_B_DioChannel_15.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_B_DioChannel_15 (Dio_ChannelType)0x1fU

/**
* @brief          Symbolic name for the channel DioPort_B_DioChannel_2.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_B_DioChannel_2 (Dio_ChannelType)0x12U

/**
* @brief          Symbolic name for the channel DioPort_B_DioChannel_3.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_B_DioChannel_3 (Dio_ChannelType)0x13U

/**
* @brief          Symbolic name for the channel DioPort_B_DioChannel_4.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_B_DioChannel_4 (Dio_ChannelType)0x14U

/**
* @brief          Symbolic name for the channel DioPort_B_DioChannel_5.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_B_DioChannel_5 (Dio_ChannelType)0x15U

/**
* @brief          Symbolic name for the channel DioPort_B_DioChannel_6.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_B_DioChannel_6 (Dio_ChannelType)0x16U

/**
* @brief          Symbolic name for the channel DioPort_B_DioChannel_7.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_B_DioChannel_7 (Dio_ChannelType)0x17U

/**
* @brief          Symbolic name for the channel DioPort_B_DioChannel_8.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_B_DioChannel_8 (Dio_ChannelType)0x18U

/**
* @brief          Symbolic name for the channel DioPort_B_DioChannel_9.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_B_DioChannel_9 (Dio_ChannelType)0x19U

/* ---------- DioPort_C ---------- */

/**
* @brief          Symbolic name for the port DioPort_C.
*
* @requirements   .
* @implements     DDIO04009.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioPort_DioPort_C (Dio_PortType)0x02U

/**
* @brief          Symbolic name for the channel DioPort_C_DioChannel_0.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_C_DioChannel_0 (Dio_ChannelType)0x20U

/**
* @brief          Symbolic name for the channel DioPort_C_DioChannel_1.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_C_DioChannel_1 (Dio_ChannelType)0x21U

/**
* @brief          Symbolic name for the channel DioPort_C_DioChannel_10.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_C_DioChannel_10 (Dio_ChannelType)0x2aU

/**
* @brief          Symbolic name for the channel DioPort_C_DioChannel_11.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_C_DioChannel_11 (Dio_ChannelType)0x2bU

/**
* @brief          Symbolic name for the channel DioPort_C_DioChannel_12.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_C_DioChannel_12 (Dio_ChannelType)0x2cU

/**
* @brief          Symbolic name for the channel DioPort_C_DioChannel_13.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_C_DioChannel_13 (Dio_ChannelType)0x2dU

/**
* @brief          Symbolic name for the channel DioPort_C_DioChannel_14.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_C_DioChannel_14 (Dio_ChannelType)0x2eU

/**
* @brief          Symbolic name for the channel DioPort_C_DioChannel_15.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_C_DioChannel_15 (Dio_ChannelType)0x2fU

/**
* @brief          Symbolic name for the channel DioPort_C_DioChannel_2.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_C_DioChannel_2 (Dio_ChannelType)0x22U

/**
* @brief          Symbolic name for the channel DioPort_C_DioChannel_3.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_C_DioChannel_3 (Dio_ChannelType)0x23U

/**
* @brief          Symbolic name for the channel DioPort_C_DioChannel_4.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_C_DioChannel_4 (Dio_ChannelType)0x24U

/**
* @brief          Symbolic name for the channel DioPort_C_DioChannel_5.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_C_DioChannel_5 (Dio_ChannelType)0x25U

/**
* @brief          Symbolic name for the channel DioPort_C_DioChannel_6.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_C_DioChannel_6 (Dio_ChannelType)0x26U

/**
* @brief          Symbolic name for the channel DioPort_C_DioChannel_7.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_C_DioChannel_7 (Dio_ChannelType)0x27U

/**
* @brief          Symbolic name for the channel DioPort_C_DioChannel_8.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_C_DioChannel_8 (Dio_ChannelType)0x28U

/**
* @brief          Symbolic name for the channel DioPort_C_DioChannel_9.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_C_DioChannel_9 (Dio_ChannelType)0x29U

/* ---------- DioPort_D ---------- */

/**
* @brief          Symbolic name for the port DioPort_D.
*
* @requirements   .
* @implements     DDIO04009.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioPort_DioPort_D (Dio_PortType)0x03U

/**
* @brief          Symbolic name for the channel DioPort_D_DioChannel_0.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_D_DioChannel_0 (Dio_ChannelType)0x30U

/**
* @brief          Symbolic name for the channel DioPort_D_DioChannel_1.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_D_DioChannel_1 (Dio_ChannelType)0x31U

/**
* @brief          Symbolic name for the channel DioPort_D_DioChannel_10.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_D_DioChannel_10 (Dio_ChannelType)0x3aU

/**
* @brief          Symbolic name for the channel DioPort_D_DioChannel_11.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_D_DioChannel_11 (Dio_ChannelType)0x3bU

/**
* @brief          Symbolic name for the channel DioPort_D_DioChannel_12.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_D_DioChannel_12 (Dio_ChannelType)0x3cU

/**
* @brief          Symbolic name for the channel DioPort_D_DioChannel_13.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_D_DioChannel_13 (Dio_ChannelType)0x3dU

/**
* @brief          Symbolic name for the channel DioPort_D_DioChannel_14.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_D_DioChannel_14 (Dio_ChannelType)0x3eU

/**
* @brief          Symbolic name for the channel DioPort_D_DioChannel_15.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_D_DioChannel_15 (Dio_ChannelType)0x3fU

/**
* @brief          Symbolic name for the channel DioPort_D_DioChannel_2.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_D_DioChannel_2 (Dio_ChannelType)0x32U

/**
* @brief          Symbolic name for the channel DioPort_D_DioChannel_3.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_D_DioChannel_3 (Dio_ChannelType)0x33U

/**
* @brief          Symbolic name for the channel DioPort_D_DioChannel_4.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_D_DioChannel_4 (Dio_ChannelType)0x34U

/**
* @brief          Symbolic name for the channel DioPort_D_DioChannel_5.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_D_DioChannel_5 (Dio_ChannelType)0x35U

/**
* @brief          Symbolic name for the channel DioPort_D_DioChannel_6.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_D_DioChannel_6 (Dio_ChannelType)0x36U

/**
* @brief          Symbolic name for the channel DioPort_D_DioChannel_7.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_D_DioChannel_7 (Dio_ChannelType)0x37U

/**
* @brief          Symbolic name for the channel DioPort_D_DioChannel_8.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_D_DioChannel_8 (Dio_ChannelType)0x38U

/**
* @brief          Symbolic name for the channel DioPort_D_DioChannel_9.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_D_DioChannel_9 (Dio_ChannelType)0x39U

/* ---------- DioPort_E ---------- */

/**
* @brief          Symbolic name for the port DioPort_E.
*
* @requirements   .
* @implements     DDIO04009.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioPort_DioPort_E (Dio_PortType)0x04U

/**
* @brief          Symbolic name for the channel DioPort_E_DioChannel_0.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_E_DioChannel_0 (Dio_ChannelType)0x40U

/**
* @brief          Symbolic name for the channel DioPort_E_DioChannel_1.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_E_DioChannel_1 (Dio_ChannelType)0x41U

/**
* @brief          Symbolic name for the channel DioPort_E_DioChannel_10.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_E_DioChannel_10 (Dio_ChannelType)0x4aU

/**
* @brief          Symbolic name for the channel DioPort_E_DioChannel_11.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_E_DioChannel_11 (Dio_ChannelType)0x4bU

/**
* @brief          Symbolic name for the channel DioPort_E_DioChannel_12.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_E_DioChannel_12 (Dio_ChannelType)0x4cU

/**
* @brief          Symbolic name for the channel DioPort_E_DioChannel_13.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_E_DioChannel_13 (Dio_ChannelType)0x4dU

/**
* @brief          Symbolic name for the channel DioPort_E_DioChannel_14.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_E_DioChannel_14 (Dio_ChannelType)0x4eU

/**
* @brief          Symbolic name for the channel DioPort_E_DioChannel_15.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_E_DioChannel_15 (Dio_ChannelType)0x4fU

/**
* @brief          Symbolic name for the channel DioPort_E_DioChannel_2.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_E_DioChannel_2 (Dio_ChannelType)0x42U

/**
* @brief          Symbolic name for the channel DioPort_E_DioChannel_3.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_E_DioChannel_3 (Dio_ChannelType)0x43U

/**
* @brief          Symbolic name for the channel DioPort_E_DioChannel_4.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_E_DioChannel_4 (Dio_ChannelType)0x44U

/**
* @brief          Symbolic name for the channel DioPort_E_DioChannel_5.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_E_DioChannel_5 (Dio_ChannelType)0x45U

/**
* @brief          Symbolic name for the channel DioPort_E_DioChannel_6.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_E_DioChannel_6 (Dio_ChannelType)0x46U

/**
* @brief          Symbolic name for the channel DioPort_E_DioChannel_7.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_E_DioChannel_7 (Dio_ChannelType)0x47U

/**
* @brief          Symbolic name for the channel DioPort_E_DioChannel_8.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_E_DioChannel_8 (Dio_ChannelType)0x48U

/**
* @brief          Symbolic name for the channel DioPort_E_DioChannel_9.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_E_DioChannel_9 (Dio_ChannelType)0x49U

/* ---------- DioPort_F ---------- */

/**
* @brief          Symbolic name for the port DioPort_F.
*
* @requirements   .
* @implements     DDIO04009.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioPort_DioPort_F (Dio_PortType)0x05U

/**
* @brief          Symbolic name for the channel DioPort_F_DioChannel_0.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_F_DioChannel_0 (Dio_ChannelType)0x50U

/**
* @brief          Symbolic name for the channel DioPort_F_DioChannel_1.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_F_DioChannel_1 (Dio_ChannelType)0x51U

/**
* @brief          Symbolic name for the channel DioPort_F_DioChannel_10.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_F_DioChannel_10 (Dio_ChannelType)0x5aU

/**
* @brief          Symbolic name for the channel DioPort_F_DioChannel_11.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_F_DioChannel_11 (Dio_ChannelType)0x5bU

/**
* @brief          Symbolic name for the channel DioPort_F_DioChannel_12.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_F_DioChannel_12 (Dio_ChannelType)0x5cU

/**
* @brief          Symbolic name for the channel DioPort_F_DioChannel_13.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_F_DioChannel_13 (Dio_ChannelType)0x5dU

/**
* @brief          Symbolic name for the channel DioPort_F_DioChannel_14.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_F_DioChannel_14 (Dio_ChannelType)0x5eU

/**
* @brief          Symbolic name for the channel DioPort_F_DioChannel_15.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_F_DioChannel_15 (Dio_ChannelType)0x5fU

/**
* @brief          Symbolic name for the channel DioPort_F_DioChannel_2.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_F_DioChannel_2 (Dio_ChannelType)0x52U

/**
* @brief          Symbolic name for the channel DioPort_F_DioChannel_3.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_F_DioChannel_3 (Dio_ChannelType)0x53U

/**
* @brief          Symbolic name for the channel DioPort_F_DioChannel_4.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_F_DioChannel_4 (Dio_ChannelType)0x54U

/**
* @brief          Symbolic name for the channel DioPort_F_DioChannel_5.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_F_DioChannel_5 (Dio_ChannelType)0x55U

/**
* @brief          Symbolic name for the channel DioPort_F_DioChannel_6.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_F_DioChannel_6 (Dio_ChannelType)0x56U

/**
* @brief          Symbolic name for the channel DioPort_F_DioChannel_7.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_F_DioChannel_7 (Dio_ChannelType)0x57U

/**
* @brief          Symbolic name for the channel DioPort_F_DioChannel_8.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_F_DioChannel_8 (Dio_ChannelType)0x58U

/**
* @brief          Symbolic name for the channel DioPort_F_DioChannel_9.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_F_DioChannel_9 (Dio_ChannelType)0x59U

/* ---------- DioPort_G ---------- */

/**
* @brief          Symbolic name for the port DioPort_G.
*
* @requirements   .
* @implements     DDIO04009.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioPort_DioPort_G (Dio_PortType)0x06U

/**
* @brief          Symbolic name for the channel DioPort_G_DioChannel_0.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_G_DioChannel_0 (Dio_ChannelType)0x60U

/**
* @brief          Symbolic name for the channel DioPort_G_DioChannel_1.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_G_DioChannel_1 (Dio_ChannelType)0x61U

/**
* @brief          Symbolic name for the channel DioPort_G_DioChannel_10.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_G_DioChannel_10 (Dio_ChannelType)0x6aU

/**
* @brief          Symbolic name for the channel DioPort_G_DioChannel_11.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_G_DioChannel_11 (Dio_ChannelType)0x6bU

/**
* @brief          Symbolic name for the channel DioPort_G_DioChannel_12.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_G_DioChannel_12 (Dio_ChannelType)0x6cU

/**
* @brief          Symbolic name for the channel DioPort_G_DioChannel_13.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_G_DioChannel_13 (Dio_ChannelType)0x6dU

/**
* @brief          Symbolic name for the channel DioPort_G_DioChannel_14.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_G_DioChannel_14 (Dio_ChannelType)0x6eU

/**
* @brief          Symbolic name for the channel DioPort_G_DioChannel_15.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_G_DioChannel_15 (Dio_ChannelType)0x6fU

/**
* @brief          Symbolic name for the channel DioPort_G_DioChannel_2.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_G_DioChannel_2 (Dio_ChannelType)0x62U

/**
* @brief          Symbolic name for the channel DioPort_G_DioChannel_3.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_G_DioChannel_3 (Dio_ChannelType)0x63U

/**
* @brief          Symbolic name for the channel DioPort_G_DioChannel_4.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_G_DioChannel_4 (Dio_ChannelType)0x64U

/**
* @brief          Symbolic name for the channel DioPort_G_DioChannel_5.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_G_DioChannel_5 (Dio_ChannelType)0x65U

/**
* @brief          Symbolic name for the channel DioPort_G_DioChannel_6.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_G_DioChannel_6 (Dio_ChannelType)0x66U

/**
* @brief          Symbolic name for the channel DioPort_G_DioChannel_7.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_G_DioChannel_7 (Dio_ChannelType)0x67U

/**
* @brief          Symbolic name for the channel DioPort_G_DioChannel_8.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_G_DioChannel_8 (Dio_ChannelType)0x68U

/**
* @brief          Symbolic name for the channel DioPort_G_DioChannel_9.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_G_DioChannel_9 (Dio_ChannelType)0x69U

/* ---------- DioPort_H ---------- */

/**
* @brief          Symbolic name for the port DioPort_H.
*
* @requirements   .
* @implements     DDIO04009.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioPort_DioPort_H (Dio_PortType)0x07U

/**
* @brief          Symbolic name for the channel DioPort_H_DioChannel_0.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_H_DioChannel_0 (Dio_ChannelType)0x70U

/**
* @brief          Symbolic name for the channel DioPort_H_DioChannel_1.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_H_DioChannel_1 (Dio_ChannelType)0x71U

/**
* @brief          Symbolic name for the channel DioPort_H_DioChannel_10.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_H_DioChannel_10 (Dio_ChannelType)0x7aU

/**
* @brief          Symbolic name for the channel DioPort_H_DioChannel_2.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_H_DioChannel_2 (Dio_ChannelType)0x72U

/**
* @brief          Symbolic name for the channel DioPort_H_DioChannel_3.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_H_DioChannel_3 (Dio_ChannelType)0x73U

/**
* @brief          Symbolic name for the channel DioPort_H_DioChannel_4.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_H_DioChannel_4 (Dio_ChannelType)0x74U

/**
* @brief          Symbolic name for the channel DioPort_H_DioChannel_5.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_H_DioChannel_5 (Dio_ChannelType)0x75U

/**
* @brief          Symbolic name for the channel DioPort_H_DioChannel_6.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_H_DioChannel_6 (Dio_ChannelType)0x76U

/**
* @brief          Symbolic name for the channel DioPort_H_DioChannel_7.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_H_DioChannel_7 (Dio_ChannelType)0x77U

/**
* @brief          Symbolic name for the channel DioPort_H_DioChannel_8.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_H_DioChannel_8 (Dio_ChannelType)0x78U

/**
* @brief          Symbolic name for the channel DioPort_H_DioChannel_9.
*
* @requirements   .
* @implements     DDIO04008.
*/
/*
* @violates @ref Dio_CFG_REF_5 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
*                          literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define DioConf_DioChannel_DioPort_H_DioChannel_9 (Dio_ChannelType)0x79U

/*
* @violates @ref Dio_CFG_REF_4 MISRA 2004 Required Rule 5.1,Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Dio_CFG_REF_2 Required Rule 19.15, Repeated include file.
*/
#include "MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* DIO_CFG_H */

/** @} */
