/**
*   @file    Lin_Linflex_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - Low level driver header file.
*   @details This file includes the function prototypes defined in the LIN low level driver for LinFlex.
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

#ifndef LINFLEX_LLD_H
#define LINFLEX_LLD_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section LINFlex_LLD_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section LINFlex_LLD_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section LINFlex_LLD_h_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal
* and external) shall not rely on the significance of more 
* than 31 characters.
*
* @section LINFlex_LLD_h_REF_4
* Violates MISRA 2004 Required Rule  8.8, declaring an 
* external identifier in a header file, that will be 
* included in any file where the identifier is defined or used.
*
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
* @file           Lin_Linflex_LLD.h
* @implements     DLIN04004
*/
#define LIN_VENDOR_ID_FLEX                    43
/*
* @violates @ref LINFlex_LLD_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref LINFlex_LLD_h_REF_3 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_MAJOR_VERSION_FLEX     4
/*
* @violates @ref LINFlex_LLD_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref LINFlex_LLD_h_REF_3 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_MINOR_VERSION_FLEX     0
/*
* @violates @ref LINFlex_LLD_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref LINFlex_LLD_h_REF_3 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_REVISION_VERSION_FLEX  3
#define LIN_SW_MAJOR_VERSION_FLEX             1
#define LIN_SW_MINOR_VERSION_FLEX             0
#define LIN_SW_PATCH_VERSION_FLEX             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief        Sleep command ID 0x3C.
*
* @implements   DLIN04005
*/
#define LIN_SLEEP_COMMAND_ID    ((uint32)0x0000003C) /**< @brief Sleep
                                                          command ID 0x3C.*/

/**
* @brief        Sleep command length frame.
*
* @implements   DLIN04005
*/
#define LIN_DATA_LENGTH_8       ((uint32)7U)         /**< @brief Sleep
                                                          command length.*/

/**
* @brief        Sleep command frame: 0xFF data.
*
* @implements   DLIN04005
*/
#define LIN_DATA_255                   255U          /**< @brief 0xFF
                                                          data.*/

/**
* @brief        Sleep command frame: 0x00 data.
*
* @implements   DLIN04005
*/
#define LIN_DATA_0                       0U          /**< @brief 0x00
                                                          data.*/

/**
* @brief        Catastrophic Errors Recovery (CER) Codes returned by the LIN driver.
*
* @details      Unexpected frame status CER code.
*
* @implements   DLIN04003
*
* @violates @ref LINFlex_LLD_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*
* @violates @ref LINFlex_LLD_h_REF_3 This is required as per Autosar Requirement.
*/
#define LIN_CER_UNEXPECTED_FRAME_STATUS_INTERRUPT ((uint8)0x01U)
                                               /**< @brief Unexpected
                                                    frame status.*/

/**
* @brief        Catastrophic Errors Recovery (CER) Codes returned by the LIN driver.
*
* @details      Unexpected frame error status CER code.
*
* @implements   DLIN04003
*
* @violates @ref LINFlex_LLD_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*
* @violates @ref LINFlex_LLD_h_REF_3 This is required as per Autosar Requirement.
*/
#define LIN_CER_UNEXPECTED_FRAME_ERROR_STATUS_INTERRUPT ((uint8)0x02U)
                                               /**< @brief Unexpected
                                                    frame error
                                                    status.*/
/*==================================================================================================
                                             ENUMS
==================================================================================================*/
/**
* @brief          API LINFLEX LLD functions service IDs.
* @details        Service IDs of the LINFLEX LLD API.
* @implements     DLIN04006
*/
typedef enum
    {
    LINFLEX_LLD_COPYDATA_ID        = (uint8)0x03U, /**< @brief
                                  LINFLEX_LLD_CopyData() ID.*/
    LINFLEX_LLD_HWGETSTATUS_ID     = (uint8)0x04U, /**< @brief
                                  LINFLEX_LLD_HardwareGetStatus() ID.*/
    LINFLEX_LLD_WAKEUP_ID          = (uint8)0x05U, /**< @brief
                                  LINFLEX_LLD_WakeUp() ID.*/
    LINFLEX_LLD_GOTOSLEEPINT_ID    = (uint8)0x06U, /**< @brief
                                  LINFLEX_LLD_GoToSleepInternal() ID.*/
    LINFLEX_LLD_GOTOSLEEP_ID       = (uint8)0x07U, /**< @brief
                                  LINFLEX_LLD_GoToSleep() ID.*/
    LINFLEX_LLD_SENDRESPONSE_ID    = (uint8)0x08U, /**< @brief
                                  LINFLEX_LLD_SendResponse()ID.*/
    LINFLEX_LLD_SENDHEADER_ID      = (uint8)0x09U, /**< @brief
                                  LINFLEX_LLD_SendHeader() ID.*/
    LINFLEX_LLD_DEINITCHANNEL_ID   = (uint8)0x0AU, /**< @brief
                                  LINFLEX_LLD_DeInitChannel() ID.*/
    LINFLEX_LLD_INITCHANNEL_ID     = (uint8)0x0BU, /**< @brief
                                  LINFLEX_LLD_InitChannel() ID.*/
    LINFLEX_LLD_CHECKWAKEUP_ID     = (uint8)0x0CU, /**< @brief
                                  LINFlex_LLD_CheckWakeup() ID.*/
    LINFLEX_LLD_IRQHANDLER_ID      = (uint8)0x0DU  /**< @brief
                                  LINFLEX_LLD_InterruptHandler() ID.*/
    } API_LINFLEX_LLD_Function_IDs;

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define LIN_START_SEC_VAR_NO_INIT_8
/** 
* @violates @ref LINFlex_LLD_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/* @violates @ref LINFlex_LLD_h_REF_4 Declaring an external identifier in
*  a header file, that will be included in any file where the identifier
*  is defined or used */
extern volatile VAR(uint8,LIN_VAR)Lin_LinChStatus[LIN_HW_MAX_MODULES];

/* @violates @ref LINFlex_LLD_h_REF_4 Declaring an external identifier in
*  a header file, that will be included in any file where the identifier
*  is defined or used */
extern volatile VAR(uint8,LIN_VAR)Lin_LinChFrameStatus[LIN_HW_MAX_MODULES];

/* @violates @ref LINFlex_LLD_h_REF_4 Declaring an external identifier in
*  a header file, that will be included in any file where the identifier
*  is defined or used */
extern VAR(uint8, LIN_VAR)TransmitHeaderCommand[LIN_HW_MAX_MODULES];

/* @violates @ref LINFlex_LLD_h_REF_4 Declaring an external identifier in
*  a header file, that will be included in any file where the identifier
*  is defined or used */
extern volatile VAR(uint8,LIN_VAR)Lin_LinChFrameErrorStatus[LIN_HW_MAX_MODULES];

/* @violates @ref LINFlex_LLD_h_REF_4 Declaring an external identifier in
*  a header file, that will be included in any file where the identifier
*  is defined or used */
extern VAR(sint8,LIN_VAR)Lin_ChannelHardwareMap[LIN_HW_MAX_AVAILABLE_MODULES];

#define LIN_STOP_SEC_VAR_NO_INIT_8
/** 
* @violates @ref LINFlex_LLD_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"
/*
* @violates @ref LINFlex_LLD_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref LINFlex_LLD_h_REF_3 This is required as per Autosar Requirement. */
#define LIN_START_SEC_VAR_INIT_UNSPECIFIED
/** 
* @violates @ref LINFlex_LLD_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"
extern P2CONST(Lin_ConfigType,LIN_VAR,LIN_APPL_CONST) Lin_Cfg_Ptr;
/*
* @violates @ref LINFlex_LLD_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref LINFlex_LLD_h_REF_3 This is required as per Autosar Requirement. */
#define LIN_STOP_SEC_VAR_INIT_UNSPECIFIED
/** 
* @violates @ref LINFlex_LLD_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"
/*
* @violates @ref LINFlex_LLD_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref LINFlex_LLD_h_REF_3 This is required as per Autosar Requirement. */
#define LIN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/** 
* @violates @ref LINFlex_LLD_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/* @violates @ref LINFlex_LLD_h_REF_4 Declaring an external identifier in
*  a header file, that will be included in any file where the identifier
*  is defined or used */
extern P2CONST(Lin_ChannelConfigType,LIN_VAR,LIN_APPL_CONST)Lin_Channel_Cfg_Ptr[LIN_HW_MAX_MODULES];

/*
* @violates @ref LINFlex_LLD_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref LINFlex_LLD_h_REF_3 This is required as per Autosar Requirement. */
#define LIN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/** 
* @violates @ref LINFlex_LLD_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_START_SEC_CODE
/** 
* @violates @ref LINFlex_LLD_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

FUNC (void, LIN_CODE) LINFlex_Tx_Rx_InterruptHandler(CONST(uint8, AUTOMATIC) Channel);
FUNC (void, LIN_CODE) LINFlex_ErrorInterruptHandler(CONST(uint8, AUTOMATIC) Channel);

/*****************************************************************************
**                          Non-AUTOSAR LIN Low Level Driver API's          **
*****************************************************************************/
FUNC (Std_ReturnType, LIN_CODE) LINFlex_LLD_CheckWakeup(CONST(uint8, AUTOMATIC) Channel);
FUNC (void, LIN_CODE) LINFlex_LLD_InitChannel(CONST(uint8, AUTOMATIC) Channel);
FUNC (Std_ReturnType, LIN_CODE) LINFlex_LLD_SendHeader(CONST(uint8, AUTOMATIC) Channel, \
                                P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) PduInfoPtr);
FUNC (void, LIN_CODE) LINFlex_LLD_SendResponse(CONST(uint8, AUTOMATIC) Channel, \
                                P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) PduInfoPtr);
FUNC (Std_ReturnType, LIN_CODE) LINFlex_LLD_GoToSleep(CONST(uint8, AUTOMATIC) Channel);
FUNC (Std_ReturnType, LIN_CODE) LINFlex_LLD_GoToSleepInternal(CONST(uint8, AUTOMATIC) Channel);
FUNC (void, LIN_CODE) LINFlex_LLD_WakeUp(CONST(uint8, AUTOMATIC) Channel);
FUNC (Lin_StatusType, LIN_CODE) LINFlex_LLD_HardwareGetStatus(CONST(uint8, AUTOMATIC) Channel,
                             P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) LinSduPtr);
FUNC (void, LIN_CODE) LINFlex_LLD_CopyData(CONST(uint8, AUTOMATIC) Channel, \
                                P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) LinSduPtr);

#define LIN_STOP_SEC_CODE
/** 
* @violates @ref LINFlex_LLD_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* LINFLEX_LLD_H */

/** @} */
