/**
* @file    Port_LLD.h
*
* @version 1.0.1
* @brief   AUTOSAR Port - PORT driver low level driver interface.
* @details Interface between the high level driver (Autosar dependent) and the low level driver(IP dependent).
*          It is platform specific.
*
* @addtogroup  Port
* @{
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

#ifndef PORT_LLD_H
#define PORT_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/**
*  @page misra_violations MISRA-C:2004 violations
*
* @section Port_LLD_H_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character signifiance and case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Port_LLD_H_REF_4
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*
* @section Port_LLD_H_REF_5
* Violates MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string literal, a
* parenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file  Port_LLD.h
* @implements DPORT00015
*/
#include "Port_Siul_LLD.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
* @implements   DPORT04024
*/
#define PORT_VENDOR_ID_LLD_H                    43
/*
* @violates @ref Port_LLD_H_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_AR_RELEASE_MAJOR_VERSION_LLD_H     4
/*
* @violates @ref Port_LLD_H_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_AR_RELEASE_MINOR_VERSION_LLD_H     0
/*
* @violates @ref Port_LLD_H_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
/*
* @violates @ref Port_LLD_H_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_AR_RELEASE_REVISION_VERSION_LLD_H  3
#define PORT_SW_MAJOR_VERSION_LLD_H             1
#define PORT_SW_MINOR_VERSION_LLD_H             0
#define PORT_SW_PATCH_VERSION_LLD_H             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/**
* @file    Port_LLD.h
* @implements   DPORT06001
*/
/* Check if Port_LLD.h and Port_Siul_LLD.h file are of the same vendor */
#if (PORT_VENDOR_ID_LLD_H != SIUL_VENDOR_ID_LLD_H)
    #error "Port_LLD.h and Port_Siul_LLD.h have different vendor ids"
#endif

/* Check if Port_LLD.h and Port_Siul_LLD.h file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_LLD_H    != SIUL_AR_RELEASE_MAJOR_VERSION_LLD_H) || \
     (PORT_AR_RELEASE_MINOR_VERSION_LLD_H    != SIUL_AR_RELEASE_MINOR_VERSION_LLD_H) || \
     (PORT_AR_RELEASE_REVISION_VERSION_LLD_H != SIUL_AR_RELEASE_REVISION_VERSION_LLD_H))
   #error "AutoSar Version Numbers of Port_LLD.h and Port_Siul_LLD.h are different"
#endif

/* Check if Port_LLD.h and Port_Siul_LLD.h file are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_LLD_H != SIUL_SW_MAJOR_VERSION_LLD_H) || \
     (PORT_SW_MINOR_VERSION_LLD_H != SIUL_SW_MINOR_VERSION_LLD_H) || \
     (PORT_SW_PATCH_VERSION_LLD_H != SIUL_SW_PATCH_VERSION_LLD_H))
   #error "Software Version Numbers of Port_LLD.h and Port_Siul_LLD.h are different"
#endif

/*==================================================================================================
*                                      DEFINES
==================================================================================================*/
/**
* @brief  Mapping between low level layer and high level layer for PORT_LLD_Init function.
*/
/*
* @violates @ref Port_LLD_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_LLD_Init                  PORT_Siul_Init
/**
* @brief  Mapping between low level layer and high level layer for PORT_LLD_SetPinDirection function.
*/
/*
* @violates @ref Port_LLD_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_LLD_SetPinDirection       PORT_Siul_SetPinDirection
/**
* @brief  Mapping between low level layer and high level layer for PORT_LLD_RefreshPortDirection function.
*/
/*
* @violates @ref Port_LLD_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_LLD_RefreshPortDirection  PORT_Siul_RefreshPortDirection
/**
* @brief  Mapping between low level layer and high level layer for PORT_LLD_SetPinMode function.
*/
/*
* @violates @ref Port_LLD_H_REF_5 C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define PORT_LLD_SetPinMode            PORT_Siul_SetPinMode

#ifdef __cplusplus
}
#endif

#endif /*PORT_LLD_H*/
/** @} */
