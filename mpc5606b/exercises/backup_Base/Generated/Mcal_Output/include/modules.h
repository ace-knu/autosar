/**
*   @file    modules.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - Project configuration.
*   @details Header file describing all Autosar MCAL modules present in the current project.
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : XPC560XB
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
/**
* @file        modules.h
*/
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section  modules_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section modules_h_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
 * significance of more than 31 characters.
*/

#ifndef MODULES_H
#define MODULES_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** 
* @file        modules.h
* @brief Include Standard types & defines
*/
/*
* @violates @ref modules_h_REF_1  Precautions shall be taken in order
* to prevent the contents of a header being included twice.
*/
#include "Std_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/** 
@{
* @brief Parameters that shall be published within the modules header file.
*       The integration of incompatible files shall be avoided.
*/
#define MODULES_VENDOR_ID                       43
/*
* @violates @ref modules_h_REF_2 This is required as per autosar Requirement, 
*/
#define MODULES_AR_RELEASE_MAJOR_VERSION_H      4
/*
* @violates @ref modules_h_REF_2 This is required as per autosar Requirement, 
*/
#define MODULES_AR_RELEASE_MINOR_VERSION_H      0
/*
* @violates @ref modules_h_REF_2 This is required as per autosar Requirement, 
*/
#define MODULES_AR_RELEASE_REVISION_VERSION_H   3
#define MODULES_SW_MAJOR_VERSION_H              1
#define MODULES_SW_MINOR_VERSION_H              0
#define MODULES_SW_PATCH_VERSION_H              1
/**@}*/
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** 
* @brief This constant used for other modules to check if ADC is present in the project.  
*/
#define USE_ADC_MODULE              (STD_ON)

/** 
* @brief This constant used for other modules to check if CAN is present in the project.  
*/
#define USE_CAN_MODULE              (STD_ON)

/** 
* @brief This constant used for other modules to check if DIO is present in the project.  
*/
#define USE_DIO_MODULE              (STD_ON)

/** 
* @brief This constant used for other modules to check if ETH is present in the project.  
*/
#define USE_ETH_MODULE              (STD_OFF)

/** 
* @brief This constant used for other modules to check if FEE is present in the project.  
*/
#define USE_FEE_MODULE              (STD_ON)

/** 
* @brief This constant used for other modules to check if FLS is present in the project.  
*/
#define USE_FLS_MODULE              (STD_ON)

/** 
* @brief This constant used for other modules to check if Fr is present in the project.  
*/
#define USE_FR_MODULE              (STD_OFF)

/** 
* @brief This constant used for other modules to check if GPT is present in the project.  
*/
#define USE_GPT_MODULE              (STD_ON)

/** 
* @brief This constant used for other modules to check if ICU is present in the project.  
*/
#define USE_ICU_MODULE              (STD_ON)

/** 
* @brief This constant used for other modules to check if LIN is present in the project.  
*/
#define USE_LIN_MODULE              (STD_OFF)

/** 
* @brief This constant used for other modules to check if MCU is present in the project.  
*/
#define USE_MCU_MODULE              (STD_ON)

/** 
* @brief This constant used for other modules to check if PORT is present in the project.  
*/
#define USE_PORT_MODULE             (STD_ON)

/** 
* @brief This constant used for other modules to check if PWM is present in the project.  
*/
#define USE_PWM_MODULE              (STD_ON)

/** 
* @brief This constant used for other modules to check if SPI is present in the project.  
*/
#define USE_SPI_MODULE              (STD_ON)

/** 
* @brief This constant used for other modules to check if WDG is present in the project.  
*/
#define USE_WDG_MODULE              (STD_ON)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MODULES_H */

/** @} */


