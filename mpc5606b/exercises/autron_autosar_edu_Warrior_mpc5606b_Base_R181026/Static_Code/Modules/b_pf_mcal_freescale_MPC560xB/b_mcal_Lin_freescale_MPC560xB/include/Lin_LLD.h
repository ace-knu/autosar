/**
*   @file    Lin_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - Isolation level header file for LIN driver.
*   @details Header file for function definition on isolation level betwen high and low level driver.
*
*   @addtogroup LIN
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : LINFlex
*   Dependencies         : 
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF5_ASR_REL_4_0_REV_0003_20140822
*
*   (c) Copyright 2006-2014 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef LIN_LLD_H
#define LIN_LLD_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Lin_LLD_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_LLD_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Lin_LLD_h_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal
* and external) shall not rely on the significance of more 
* than 31 characters.
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
/**
* @file           Lin_LLD.h
* @implements     DLIN03201
*/
#define LIN_LLD_VENDOR_ID                    43
/*
* @violates @ref Lin_LLD_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref Lin_LLD_h_REF_3 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_MAJOR_VERSION_LLD     4
/*
* @violates @ref Lin_LLD_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref Lin_LLD_h_REF_3 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_MINOR_VERSION_LLD     0
/*
* @violates @ref Lin_LLD_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref Lin_LLD_h_REF_3 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_REVISION_VERSION_LLD  3
#define LIN_SW_MAJOR_VERSION_LLD             1
#define LIN_SW_MINOR_VERSION_LLD             0
#define LIN_SW_PATCH_VERSION_LLD             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin configuration header file are of the same vendor */
#if (LIN_LLD_VENDOR_ID != LIN_VENDOR_ID_CFG)
    #error "Lin_LLD.h and Lin_Cfg.h have different vendor ids"
#endif

/* Check if current file and Lin configuration header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_LLD    != LIN_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (LIN_AR_RELEASE_MINOR_VERSION_LLD    != LIN_AR_RELEASE_MINOR_VERSION_CFG) || \
     (LIN_AR_RELEASE_REVISION_VERSION_LLD != LIN_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Lin_LLD.h and Lin_Cfg.h are different"
#endif
/* Check if current file and Lin configuration header file are of the same software version */
#if ((LIN_SW_MAJOR_VERSION_LLD != LIN_SW_MAJOR_VERSION_CFG) || \
     (LIN_SW_MINOR_VERSION_LLD != LIN_SW_MINOR_VERSION_CFG) || \
     (LIN_SW_PATCH_VERSION_LLD != LIN_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Lin_LLD.h and Lin_Cfg.h are different"
#endif

/* Check if current file and Lin header file are of the same vendor */
#if (LIN_LLD_VENDOR_ID != LIN_VENDOR_ID)
    #error "Lin_LLD.h and Lin.h have different vendor ids"
#endif

/* Check if current file and Lin header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_LLD    != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_AR_RELEASE_MINOR_VERSION_LLD    != LIN_AR_RELEASE_MINOR_VERSION) || \
     (LIN_AR_RELEASE_REVISION_VERSION_LLD != LIN_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Lin_LLD.h and Lin.h are different"
#endif
/* Check if current file and Lin header file are of the same software version */
#if ((LIN_SW_MAJOR_VERSION_LLD != LIN_SW_MAJOR_VERSION) || \
     (LIN_SW_MINOR_VERSION_LLD != LIN_SW_MINOR_VERSION) || \
     (LIN_SW_PATCH_VERSION_LLD != LIN_SW_PATCH_VERSION))
#error "Software Version Numbers of Lin_LLD.h and Lin.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_START_SEC_CODE
/** 
* @violates @ref Lin_LLD_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

FUNC (Std_ReturnType, LIN_CODE) Lin_LLD_CheckWakeup(CONST(uint8, AUTOMATIC) Channel);
FUNC (void, LIN_CODE) Lin_LLD_InitChannel(CONST(uint8, AUTOMATIC) Channel);
FUNC (Std_ReturnType, LIN_CODE) Lin_LLD_SendHeader(CONST(uint8, AUTOMATIC) Channel, \
                                P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) PduInfoPtr);
FUNC (void, LIN_CODE) Lin_LLD_SendResponse(CONST(uint8, AUTOMATIC) Channel, P2CONST(Lin_PduType, \
                                AUTOMATIC, LIN_APPL_CONST) PduInfoPtr);
FUNC (Std_ReturnType, LIN_CODE) Lin_LLD_GoToSleep(CONST(uint8, AUTOMATIC) Channel);
FUNC (Std_ReturnType, LIN_CODE) Lin_LLD_GoToSleepInternal(CONST(uint8, AUTOMATIC) Channel);
FUNC (Lin_StatusType, LIN_CODE) Lin_LLD_HardwareGetStatus(CONST(uint8, AUTOMATIC) Channel, \
                                P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) LinSduPtr);
FUNC (void, LIN_CODE) Lin_LLD_WakeUp(CONST(uint8, AUTOMATIC) Channel);

#define LIN_STOP_SEC_CODE
/** 
* @violates @ref Lin_LLD_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* LIN_LLD_H */

/** @} */
