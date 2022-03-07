/**
*   @file    Can_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface
*   @details Main header file - can include different IPV models.
*
*   @addtogroup CAN_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : FLEXCAN
*   Dependencies         : 
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

#ifndef CAN_LLD_H
#define CAN_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section CAN_LLD_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
* @section CAN_LLD_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section CAN_LLD_h_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can_FlexCan_LLD.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Can_LLD.h
* @implements     DCAN02662
*/
#define CAN_VENDOR_ID_LLD_H                    43
#define CAN_MODULE_ID_LLD_H                    80
/* @violates @ref CAN_LLD_h_REF_3 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_MAJOR_VERSION_LLD_H     4
/* @violates @ref CAN_LLD_h_REF_3 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_MINOR_VERSION_LLD_H     0
/*
* @violates @ref CAN_LLD_h_REF_1 Violates MISRA 2004 Required Rule 1.4,   Identifier clash
*/
/* @violates @ref CAN_LLD_h_REF_3 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_REVISION_VERSION_LLD_H  3
#define CAN_SW_MAJOR_VERSION_LLD_H             1
#define CAN_SW_MINOR_VERSION_LLD_H             0
#define CAN_SW_PATCH_VERSION_LLD_H             1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CAN configuration header file are of the same vendor */
#if (CAN_VENDOR_ID_LLD_H != CAN_VENDOR_ID_CFG)
#error "Can_LLD.h and Can_Cfg.h have different vendor ids"
#endif
/* Check if current file and CAN configuration header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_LLD_H    != CAN_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (CAN_AR_RELEASE_MINOR_VERSION_LLD_H    != CAN_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (CAN_AR_RELEASE_REVISION_VERSION_LLD_H != CAN_AR_RELEASE_REVISION_VERSION_CFG_H))
#error "AutoSar Version Numbers of Can_LLD.h and Can_Cfg.h are different"
#endif
/* Check if current file and CAN configuration header file are of the same software version */
#if ((CAN_SW_MAJOR_VERSION_LLD_H != CAN_SW_MAJOR_VERSION_CFG_H) || \
     (CAN_SW_MINOR_VERSION_LLD_H != CAN_SW_MINOR_VERSION_CFG_H) || \
     (CAN_SW_PATCH_VERSION_LLD_H != CAN_SW_PATCH_VERSION_CFG_H))
#error "Software Version Numbers of Can_LLD.h and Can_Cfg.h are different"
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

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

#if (CAN_PRECOMPILE_SUPPORT == STD_OFF)
/* @violates @ref CAN_LLD_h_REF_3 This is required as per autosar Requirement. */
#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref  CAN_LLD_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include files */
#include "MemMap.h"

/* @violates @ref CAN_LLD_h_REF_3 This is required as per autosar Requirement. */
#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref  CAN_LLD_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include files */
#include "MemMap.h"
#endif

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_START_SEC_CODE
/*
* @violates @ref CAN_LLD_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"


FUNC(void, CAN_CODE) Can_LLD_Process_BusOff( CONST(uint8, CAN_CONST) controller );


#if (CAN_WAKEUP_SUPPORT == STD_ON)
FUNC(void, CAN_CODE) Can_LLD_Process_Wakeup( CONST(uint8, CAN_CONST) controller );
#endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */

#if (CAN_CHANGE_BAUDRATE_API == STD_ON)

FUNC (Std_ReturnType, CAN_CODE) Can_LLD_CheckBaudrate( VAR(uint8, AUTOMATIC) controller,
                                                       CONST(uint16, CAN_CONST) Baudrate,
                                                       VAR(uint8, AUTOMATIC) ApiId);
#endif /* (CAN_CHANGE_BAUDRATE_API == STD_ON) */

FUNC(void, CAN_CODE) Can_LLD_Process_Rx( CONST(uint8, CAN_CONST) controller,
                                     CONST(uint8, CAN_CONST) mbindex_start,
                                     CONST(uint8, CAN_CONST) mbindex_end );


FUNC(void, CAN_CODE) Can_LLD_Process_Tx( CONST(uint8, CAN_CONST) controller,
                                     CONST(uint8, CAN_CONST) mbindex_start,
                                     CONST(uint8, CAN_CONST) mbindex_end );


#if (CAN_RXFIFO_ENABLE == STD_ON)
FUNC(void, CAN_CODE) Can_LLD_RxFifoFrameAvNotif( CONST(uint8, CAN_CONST) controller);
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */

#define CAN_STOP_SEC_CODE
/*
* @violates @ref CAN_LLD_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*TEMPLATE_H*/

/** @} */
