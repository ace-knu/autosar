/**
* @file    Port_Siul_LLD.h
* @version 1.0.1
*
* @brief   AUTOSAR Port - SIUL low level IP driver interface.
* @details API of the SIUL low level IP driver.
*
* @addtogroup Siul
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

#ifndef PORT_SIUL_LLD_H
#define PORT_SIUL_LLD_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_SIUL_LLD_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file, 
* Precautions shall be taken in order to prevent the contents of a header file 
* being included twice This is not a violation since all header files are 
* protected against multiple inclusions
*
* @section PORT_SIUL_LLD_H_REF_2
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
* @section PORT_SIUL_LLD_H_REF_3
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*
* @file     Port_Siul_LLD.h
* @note     File included for legacy.
* @implements DPORT00018
*/
#include "modules.h"

/*
* @file  Port_Siul_LLD.h
* @implements DPORT00019
*/
#include "Port_Cfg.h"
/*
* @file  Port_Siul_LLD.h
* @implements DPORT00020
*/
#include "Port_Siul_LLD_CfgEx.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 * @implements   DPORT05003
 */
#define SIUL_VENDOR_ID_LLD_H                     43
/* @violates @ref PORT_SIUL_LLD_H_REF_3 Violates MISRA 2004 Required Rule 5.1 */
#define SIUL_AR_RELEASE_MAJOR_VERSION_LLD_H      4
/* @violates @ref PORT_SIUL_LLD_H_REF_3 Violates MISRA 2004 Required Rule 5.1 */
#define SIUL_AR_RELEASE_MINOR_VERSION_LLD_H      0
/* @violates @ref PORT_SIUL_LLD_H_REF_2 Violates MISRA 2004 Required Rule 1.4 */
/* @violates @ref PORT_SIUL_LLD_H_REF_3 Violates MISRA 2004 Required Rule 5.1 */
#define SIUL_AR_RELEASE_REVISION_VERSION_LLD_H   3
#define SIUL_SW_MAJOR_VERSION_LLD_H              1
#define SIUL_SW_MINOR_VERSION_LLD_H              0
#define SIUL_SW_PATCH_VERSION_LLD_H              1


#if (USE_PORT_MODULE == STD_ON)
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/*
* @file Port_Siul_LLD.h
* @implements   DPORT06001
*/
/* Check if the files Port_Siul_LLD.h and Port_Cfg.h are of the same vendor */
#if (SIUL_VENDOR_ID_LLD_H != PORT_VENDOR_ID_CFG_H)
    #error "Port_Siul_LLD.h and Port_Cfg.h have different vendor ids"
#endif
/* Check if the files Port_Siul_LLD.h and Port_Cfg.h are of the same Autosar version */
#if ((SIUL_AR_RELEASE_MAJOR_VERSION_LLD_H    != PORT_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (SIUL_AR_RELEASE_MINOR_VERSION_LLD_H    != PORT_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (SIUL_AR_RELEASE_REVISION_VERSION_LLD_H != PORT_AR_RELEASE_REVISION_VERSION_CFG_H))
  #error "AutoSar Version Numbers of Port_Siul_LLD.h and Port_Cfg.h are different"
#endif
/* Check if the files Port_Siul_LLD.h and Port_Cfg.h are of the same software version */
#if ((SIUL_SW_MAJOR_VERSION_LLD_H != PORT_SW_MAJOR_VERSION_CFG_H) || \
     (SIUL_SW_MINOR_VERSION_LLD_H != PORT_SW_MINOR_VERSION_CFG_H) || \
     (SIUL_SW_PATCH_VERSION_LLD_H != PORT_SW_PATCH_VERSION_CFG_H))
  #error "Software Version Numbers of Port_Siul_LLD.h and Port_Cfg.h are different"
#endif

/* Check if the files Port_Siul_LLD.h and Port_Siul_LLD_CfgEx.h are of the same vendor */
#if (SIUL_VENDOR_ID_LLD_H != SIUL_VENDOR_ID_EXT_H)
    #error "Port_Siul_LLD.h and Port_Siul_LLD_CfgEx.h have different vendor ids"
#endif
/* Check if the files Port_Siul_LLD.h and Port_Siul_LLD_CfgEx.h are of the same Autosar version */
#if ((SIUL_AR_RELEASE_MAJOR_VERSION_LLD_H    != SIUL_AR_RELEASE_MAJOR_VERSION_EXT_H) || \
     (SIUL_AR_RELEASE_MINOR_VERSION_LLD_H    != SIUL_AR_RELEASE_MINOR_VERSION_EXT_H) || \
     (SIUL_AR_RELEASE_REVISION_VERSION_LLD_H != SIUL_AR_RELEASE_REVISION_VERSION_EXT_H))
   #error "AutoSar Version Numbers of Port_Siul_LLD.h and Port_Siul_LLD_CfgEx.h are different"
#endif
/* Check if the files Port_Siul_LLD.h and Port_Siul_LLD_CfgEx.h are of the same software version */
#if ((SIUL_SW_MAJOR_VERSION_LLD_H != SIUL_SW_MAJOR_VERSION_EXT_H) || \
     (SIUL_SW_MINOR_VERSION_LLD_H != SIUL_SW_MINOR_VERSION_EXT_H) || \
     (SIUL_SW_PATCH_VERSION_LLD_H != SIUL_SW_PATCH_VERSION_EXT_H))
  #error "Software Version Numbers of Port_Siul_LLD.h and Port_Siul_LLD_CfgEx.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
/* @brief Allocate defined section for PORT code. */
#define PORT_START_SEC_CODE
/*
* @file  Port_Siul_LLD.h
* @implements DPORT00021
* @violates @ref PORT_SIUL_LLD_H_REF_1 Violates MISRA 2004 Advisory Rule 19.15, Repeated include
* file MemMap.h
*/
#include "MemMap.h"

/* @brief        Initializes the SIUL IP Driver. */
FUNC (void, PORT_CODE) PORT_Siul_Init(P2CONST(Port_ConfigType,AUTOMATIC,PORT_APPL_DATA) ConfigPtr);

/* @brief   Sets the port pin direction */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
FUNC (uint8, PORT_CODE) PORT_Siul_SetPinDirection(VAR(Port_PinType, PORT_VAR) iu8PinIndex,
                                                VAR(Port_PinDirectionType, PORT_VAR) chenDirection);
#endif

/* @brief   Refreshes port direction. */
FUNC (void, PORT_CODE) PORT_Siul_RefreshPortDirection(VAR(uint8, PORT_VAR) numPins);


#if (PORT_SET_PIN_MODE_API == STD_ON)
/* @brief   Sets the port pin mode. */
FUNC (uint8, PORT_CODE) PORT_Siul_SetPinMode(VAR(Port_PinType, PORT_VAR) iu8PinIndex,
                                             VAR(Port_PinModeType, PORT_VAR) chu8Mode);
#endif

#define PORT_STOP_SEC_CODE
/*
* @file  Port_Siul_LLD.h
* @implements DPORT00021
* @violates @ref PORT_SIUL_LLD_H_REF_1 Violates MISRA 2004 Advisory Rule 19.15, Repeated include
* file MemMap.h
*/
#include "MemMap.h"
/* USE_PORT_MODULE */
#endif


#ifdef __cplusplus
}
#endif
/* PORT_SIUL_LLD_H */
#endif
/** @} */
