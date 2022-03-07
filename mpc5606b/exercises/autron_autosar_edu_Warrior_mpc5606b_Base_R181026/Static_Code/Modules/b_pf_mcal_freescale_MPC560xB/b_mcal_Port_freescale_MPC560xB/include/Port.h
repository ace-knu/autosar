/**
*   @file    Port.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Port - driver API.
*   @details This file contains the PORT Autosar driver API.
*
*   @addtogroup Port
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
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF11_ASR_REL_4_0_REV_0003_20161011
*
*   (c) Copyright 2006-2016 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef PORT_H
#define PORT_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section PORT_H_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 
* 31 character signifiance and case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section PORT_H_REF_4
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*
* @section PORT_H_REF_5
* Violates MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string literal, a
* parenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @implements DPORT00001 */
#include "Std_Types.h"

/* @implements DPORT00002 */
#include "Port_Cfg.h"

/* @implements DPORT00007 */
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
* @implements DPORT03001
*/
#define PORT_VENDOR_ID                    43
#define PORT_MODULE_ID                    124
#define PORT_AR_RELEASE_MAJOR_VERSION     4
#define PORT_AR_RELEASE_MINOR_VERSION     0
/*
* @violates @ref PORT_H_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
/*
* @violates @ref PORT_H_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_AR_RELEASE_REVISION_VERSION  3
#define PORT_SW_MAJOR_VERSION             1
#define PORT_SW_MINOR_VERSION             0
#define PORT_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/*
* @file    Port.h
* @implements DPORT06001
*/
/* Check if the files Port.h and Port_Cfg.h are of the same vendor */
#if (PORT_VENDOR_ID != PORT_VENDOR_ID_CFG_H)
    #error "Port.h and Port_Cfg.h have different vendor ids"
#endif
/* Check if the files Port.h and Port_Cfg.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (PORT_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (PORT_AR_RELEASE_REVISION_VERSION != PORT_AR_RELEASE_REVISION_VERSION_CFG_H))
     #error "AutoSar Version Numbers of Port.h and Port_Cfg.h are different"
#endif
/* Check if the files Port.h and Port_Cfg.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION_CFG_H) || \
     (PORT_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION_CFG_H) || \
     (PORT_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION_CFG_H))
  #error "Software Version Numbers of Port.h and Port_Cfg.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the files Port.h and Std_Types.h are of the same version */
   #if ((PORT_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
       (PORT_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
       #error "AutoSar Version Numbers of Port.h and Std_Types.h are different"
   #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/* Istance IDs */
/**
* @brief   Instance ID of port driver.
* @implements DPORT03002
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_INSTANCE_ID         (uint8)0x0

/* Service IDs */
/*
* @brief   Service ID of port driver.
* @implements DPORT03003
*/
/**
* @brief   API service ID for PORT Init function.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_INIT_ID                    (uint8)0x00
/**
* @brief   API service ID for PORT set pin direction function.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_SETPINDIRECTION_ID         (uint8)0x01
/**
* @brief   API service ID for PORT refresh pin direction function.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_REFRESHPINDIRECTION_ID     (uint8)0x02
/**
* @brief   API service ID for PORT get version info function.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_GETVERSIONINFO_ID          (uint8)0x03
/**
* @brief   API service ID for PORT set pin mode.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_SETPINMODE_ID              (uint8)0x04

/* Errors IDs */
/*
* @brief   Error ID of port driver.
* @details The following errors and exception are detectable by the PORT driver
*          if development error detection is enabled.
*
* @implements DPORT03004
*/

/**
* @brief   Invalid Port Pin ID requested.
* @details Det Error value, returned by Port_SetPinDirection and Port_PinMode
*          if an wrong PortPin ID is passed.
*
* @api
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
 #define PORT_E_PARAM_PIN                (uint8)0x0A
/**
* @brief   Port Pin Direction not configured as changeable.
* @details Det Error value, returned by Port_SetPinDirection
*          if the passed PortPin have unchangeable direction.
* @api
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_E_DIRECTION_UNCHANGEABLE   (uint8)0x0B
/**
* @brief   API Port_Init() service called with wrong parameter.
* @details Det Error value, returned by Port_Init function
*          if Port_Init is called with wrong parameter.
* @api
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_E_PARAM_CONFIG             (uint8)0x0C
/**
* @brief   API Port_SetPinMode() service called when mode is invalid.
* @details Det Error value, returned by Port_SetPinMode function
*          if the passed PortPinMode is invalid.
* @api
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_E_PARAM_INVALID_MODE       (uint8)0x0D
/**
* @brief   API Port_SetPinMode() service called when mode is unchangeable.
* @details Det Error value, returned by Port_SetPinMode function
*          if the passed PortPin have a unchangeable Mode.
* @api
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_E_MODE_UNCHANGEABLE        (uint8)0x0E
/**
* @brief   API service called without module initialization.
* @details Det Error value, returned by a function if API service called
*          prior to module initialization.
* @api
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_E_UNINIT                   (uint8)0x0F
/**
* @brief   API service called with NULL Pointer Parameter.
* @details Det Error value, returned by Port_GetVersionInfo function
*          if API is called with NULL Pointer Parameter.
*
* @api
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_E_PARAM_POINTER                   (uint8)0x10
/* Errors IDs */
/*
* @brief   Error ID of port driver.
* @details The following errors and exception are detectable by the PORT driver
*          if development error detection is enabled.
*
* @implements DPORT03020
*/
/**
* @brief   API service called with invalid direction.
* @details Errors and exceptions that will be detected by the PORT driver.
*
* @api
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define  PORT_E_INVALID_DIRECTION       (uint8)0x11
/**
* @brief   Code variant
* @implements DPORT03011
*/

/**
* @brief Port GPIO Mode
* @implements DPORT04004
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_GPIO_MODE                  (Port_PinModeType)0
/**
* @brief Port Alternate 1 Mode
* @implements DPORT04005
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_ALT1_FUNC_MODE             (Port_PinModeType)1
/**
* @brief Port Alternate 2 Mode
* @implements DPORT04006
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_ALT2_FUNC_MODE             (Port_PinModeType)2
/**
* @brief Port Alternate 3 Mode
* @implements DPORT04007
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_ALT3_FUNC_MODE             (Port_PinModeType)3
/**
* @brief Port Analog input Mode
* @implements DPORT04008
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_ANALOG_INPUT_MODE          (Port_PinModeType)4
/**
* @brief Port Input only Mode
* @implements DPORT04009
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_ONLY_INPUT_MODE            (Port_PinModeType)5
/**
* @brief Port OSC Signal Mode
* @implements DPORT04010
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_OSC_SIGNAL_MODE            (Port_PinModeType)6
/**
* @brief Port Extra Input Mode
* @implements DPORT04011
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_EXTRA_INPUT_MODE           (Port_PinModeType)7
/**
* @brief Port Extra2 Input Mode
* @implements DPORT04030
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_EXTRA2_INPUT_MODE          (Port_PinModeType)8
/**
* @brief Port Alternate 4 Mode
* @implements DPORT04020
*/
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_ALT4_FUNC_MODE             (Port_PinModeType)9
/**
 * @brief Port Primary Mode
 * @implements DPORT04031
 */
/*
* @violates @ref PORT_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_PRIMARY_MODE               (Port_PinModeType)10

#ifdef PORT_PRECOMPILE_SUPPORT
PORT_CONFIG_PC
#endif

#ifndef PORT_PRECOMPILE_SUPPORT
PORT_CONFIG_PB
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#ifndef PORT_PRECOMPILE_SUPPORT
/*
* @violates @ref PORT_H_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
/* 
* @violates @ref PORT_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice. 
*/
#include "MemMap.h"


/*
* @violates @ref PORT_H_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* 
* @violates @ref PORT_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice. 
*/
#include "MemMap.h"
#endif

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
/* Allocate defined section for PORT code */
#define PORT_START_SEC_CODE
/* @implements DPORT00008 */
/* 
* @violates @ref PORT_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice. 
*/
#include "MemMap.h"

/*
* Initializes the Port Driver module.
*/
extern FUNC(void, PORT_CODE) Port_Init
(
    P2CONST(Port_ConfigType,AUTOMATIC,PORT_APPL_CONST) ConfigPtr
);

/*
* Sets the port pin direction.
*/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON) || defined(__DOXYGEN__)
extern FUNC(void, PORT_CODE) Port_SetPinDirection
(
    VAR(Port_PinType, AUTOMATIC) Pin,
    VAR(Port_PinDirectionType, AUTOMATIC) Direction
);
#endif

/*
* Refreshes port direction.
*/
extern FUNC(void, PORT_CODE) Port_RefreshPortDirection
(
    void
);

/*
* Sets the port pin mode.
*/
#if (PORT_SET_PIN_MODE_API == STD_ON) || defined(__DOXYGEN__)
extern FUNC(void, PORT_CODE) Port_SetPinMode
(
    VAR(Port_PinType, AUTOMATIC) Pin,
    VAR(Port_PinModeType, AUTOMATIC) Mode
);
#endif

/*
* Returns the version information of this module.
*/
#if  (PORT_VERSION_INFO_API == STD_ON) || defined(__DOXYGEN__)
extern FUNC (void, PORT_CODE) Port_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, PORT_APPL_DATA) pVersionInfo);
#endif /* PORT_VERSION_INFO_API == STD_ON */

#define PORT_STOP_SEC_CODE
/* @implements DPORT00008 */
/* 
* @violates @ref PORT_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice. 
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* PORT_H */

/** @} */
