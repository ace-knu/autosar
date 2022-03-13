/**
*   @file    Port_Siul_LLD_CfgEx.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Port - SIUL low level IP driver exported structures.
*   @details Interface between the high level driver (Autosar dependent) and the low level driver(platform dependent).
*
*   @addtogroup Siul
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

#ifndef PORT_SIUL_LLD_CFGEX_H
#define PORT_SIUL_LLD_CFGEX_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Port_Siul_LLD_CfgEx_H_REF_1
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief current file vendor, Autosar and API version numbers
*       The integration of incompatible files shall be avoided.
* @implements   DPORT05002
*/
#define SIUL_VENDOR_ID_EXT_H                     43
/*
* @violates @ref Port_Siul_LLD_CfgEx_H_REF_1 Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*/
#define SIUL_AR_RELEASE_MAJOR_VERSION_EXT_H      4
/*
* @violates @ref Port_Siul_LLD_CfgEx_H_REF_1 Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*/
#define SIUL_AR_RELEASE_MINOR_VERSION_EXT_H      0
/*
* @violates @ref Port_Siul_LLD_CfgEx_H_REF_1 Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*/
#define SIUL_AR_RELEASE_REVISION_VERSION_EXT_H   3
#define SIUL_SW_MAJOR_VERSION_EXT_H              1
#define SIUL_SW_MINOR_VERSION_EXT_H              0
#define SIUL_SW_PATCH_VERSION_EXT_H              1

/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*
* @brief Data type for the symbolic name of a port pin.
* @details Shall cover all available port pins. The type should be chosen for the specific MCU
*         platform (best performance).
* @implements DPORT04025
*/
typedef uint32 Port_PinType;

/**
* @brief Possible directions of a port pin.
* @implements DPORT04026
*/
typedef enum
{
    PORT_PIN_IN = 0,        /**< @brief Sets port pin as input. */
    PORT_PIN_OUT            /**< @brief Sets port pin as output. */
} Port_PinDirectionType;

/**
* @brief Different port pin modes.
* @details A port pin shall be configurable with a number of port pin modes (type Port_PinModeType).
*        The type Port_PinModeType shall be used with the function call Port_SetPinMode
* @implements DPORT04027
*/
typedef uint8 Port_PinModeType;

/**
* @brief   Single pin configuration.
* @details This structure contains all configuration parameters of a single pin
*          identified by @p SIUPin.
* @implements DPORT04028
* @api
*/
typedef struct
{
    VAR(uint8,  PORT_VAR)   SIUPin; /**< @brief Pin Defined on Part SIUx */
    VAR(uint16, PORT_VAR)   PCR;    /**< @brief Pad Control Register */
    VAR(sint8,  PORT_VAR)   PDO;    /**< @brief Pad Data Output */
    VAR(boolean,PORT_VAR)   DC;     /**< @brief Direction changebility*/
    VAR(boolean,PORT_VAR)   MC;     /**< @brief Mode changebility*/
} Port_LLD_PinConfigType;

/**
 * @brief   Default pin configuration.
 * @details This structure contains all configuration parameters of a Default pin
 * @api
*/
typedef struct
{
    VAR(uint16, PORT_VAR)   PCR;    /**< Pad Control Register */
    VAR(sint8,  PORT_VAR)   PDO;    /**< Pad Data Output */
} Port_LLD_UnUsedPinConfigType;

/*
* @brief Data type used for Pad Selection Configuration.
* @details This type should be chosen for the specific MCU platform (best performance).
* @implements DPORT04029
* @api
*/
typedef uint32 Port_LLD_PadSelConfigType;

#ifdef __cplusplus
}
#endif
/* PORT_SIUL_LLD_CFGEX_H */
#endif
/** @} */
