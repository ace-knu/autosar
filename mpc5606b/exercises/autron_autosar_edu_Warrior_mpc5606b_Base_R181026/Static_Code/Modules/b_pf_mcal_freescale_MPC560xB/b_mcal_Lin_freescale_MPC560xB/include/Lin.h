/**
*   @file    Lin.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - High level header of LIN driver.
*   @details This file contains declarations of the functions defined by AutoSAR.
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

#ifndef LIN_H
#define LIN_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Lin_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @implements     DLIN02090 */
#include "Mcal.h"
#include "ComStack_Types.h"
/* @implements     DLIN05025 */
#include "Lin_GeneralTypes.h"
#include "Lin_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @implements     DLIN02038 */
#define LIN_VENDOR_ID                      43
#define LIN_MODULE_ID                      82
#define LIN_AR_RELEASE_MAJOR_VERSION       4
#define LIN_AR_RELEASE_MINOR_VERSION       0
/*
* @violates @ref Lin_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_REVISION_VERSION    3
#define LIN_SW_MAJOR_VERSION               1
#define LIN_SW_MINOR_VERSION               0
#define LIN_SW_PATCH_VERSION               1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/           
/* Check if current file and Lin_Cfg header file are of the same Autosar version */
  #if ((LIN_AR_RELEASE_MAJOR_VERSION    != LIN_AR_RELEASE_MAJOR_VERSION_CFG) || \
       (LIN_AR_RELEASE_MINOR_VERSION    != LIN_AR_RELEASE_MINOR_VERSION_CFG) || \
       (LIN_AR_RELEASE_REVISION_VERSION != LIN_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Lin.h and Lin_Cfg.h are different"
  #endif
/* Check if current file and Lin_Cfg header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION != LIN_SW_MAJOR_VERSION_CFG) || \
     (LIN_SW_MINOR_VERSION != LIN_SW_MINOR_VERSION_CFG))
  #error "Software Version Numbers of Lin.h and Lin_Cfg.h are different"
#endif
/* Check if current file and ComStack_Types header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  #if ((LIN_AR_RELEASE_MAJOR_VERSION    != COMSTACKTYPE_AR_RELEASE_MAJOR_VERSION) || \
       (LIN_AR_RELEASE_MINOR_VERSION    != COMSTACKTYPE_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lin.h and ComStack_Types.h are different"
  #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief            API service used without module initialization
* @details          The LIN Driver module shall report the development error "LIN_E_UNINIT (0x00)", 
*                   when the API Service is used without module initialization.
* @implements       DLIN02002
* 
* @api
*/
#define LIN_E_UNINIT            ((uint8)0x00U)

/**
* @brief            API service used with an invalid or inactive channel parameter
* @details          The LIN Driver module shall report the development error 
*                   "LIN_E_INVALID_CHANNEL (0x02)", when API Service used with 
*                   an invalid or inactive channel parameter.
* @implements       DLIN02002
* 
* @api
*/
#define LIN_E_INVALID_CHANNEL   ((uint8)0x02U)

/**
* @brief            API service called with invalid configuration pointer
* @details          The LIN Driver module shall report the development error 
*                   "LIN_E_INVALID_POINTER (0x03)", when API Service is called 
*                   with invalid configuration pointer.
* @implements       DLIN02002
* 
* @api
*/
#define LIN_E_INVALID_POINTER   ((uint8)0x03U)

/**
* @brief            Invalid state transition for the current state
* @details          The LIN Driver module shall report the development error 
*                   "LIN_E_STATE_TRANSITION (0x04)", when Invalid state transition 
*                   occurs from the current state.
* @implements       DLIN02002
* 
* @api
*/
#define LIN_E_STATE_TRANSITION  ((uint8)0x04U)

/**
* @brief            CER (Catastrophic Error recovery) errors.
* @details          CER invalid state
* @implements       DLIN02002
* 
* @api
*/
#define LIN_E_DEFAULT           ((uint8)0x05U) /**< @brief CER invalid
                                                    state.*/

/**
* @brief            API service called with a NULL pointer
* @details          The LIN Driver module shall report the development error 
*                   "LIN_E_PARAM_POINTER (0x05)", when API Service is called 
*                   with a NULL pointer. In case of this error, the API service 
*                   shall return immediately without any further action, 
*                   beside reporting this development error.
* @implements       DLIN02002
* 
* @api
*/
#define LIN_E_PARAM_POINTER  ((uint8)0x05U)

/**
* @brief            LIN driver states
* @details          The state LIN_UNINIT means that the Lin module has not 
*                   been initialized yet and cannot be used.
* @implements       DLIN02006, DLIN09003
* 
* @api
*/
#define LIN_UNINIT              0x01U

/**
* @brief            LIN driver states
* @details          The LIN_INIT state indicates that the LIN driver has been 
*                   initialized, making each available channel ready for service.
* @implements       DLIN02006, DLIN09001
* 
* @api
*/
#define LIN_INIT                0x02U

/**
* @brief            LIN Channel states
* @details          The detection of a wake-up pulse is enabled. The LIN 
*                   hardware is into a low power mode if such a mode is 
*                   provided by the hardware.
* @implements       DLIN02004
* 
* @api
*/
#define LIN_CH_SLEEP_STATE              0x02U

/**
* @brief            LIN Channel states
* @details          The individual channel has been initialized (using 
*                   at least one statically configured data set) and 
*                   is able to participate in the LIN cluster.
* @implements       DLIN02004, DLIN09002
* 
* @api
*/
#define LIN_CH_OPERATIONAL_STATE        0x03U

/**
* @brief            LIN Channel states
* @details          The individual channel is not ready to 
*                   proceess a frame.
* @implements       DLIN02007
* 
* @api
*/
#define LIN_CH_NOT_READY_STATE          0x04U

/**
* @brief            LIN Channel states
* @details          The individual channel is ready to proceess a frame.
* @implements       DLIN02007
* 
* @api
*/
#define LIN_CH_READY_STATE              0x05U

/**
* @brief            LIN Channel states
* @details          LIN frame was sent; no errors.
* @implements       DLIN02007
* 
* @api
*/
#define LIN_TX_COMPLETE_STATE           0x06U

/**
* @brief            LIN Channel states
* @details          LIN frame was received; no errors.
* @implements       DLIN02007
* 
* @api
*/
#define LIN_RX_COMPLETE_STATE           0x07U

/**
* @brief            LIN Channel states
* @details          State after the LIN frame header was correctly sent.
* @implements       DLIN02007
* 
* @api
*/
#define LIN_CH_RECEIVE_NOTHING_STATE    0x08U

/**
* @brief            Interrupt Errors conditions
* @details          No error occurred on a channel.
* @implements       DLIN02003
* 
* @api
*/
#define LIN_NO_ERROR                    0x00U

/**
* @brief            Interrupt Errors conditions
* @details          Bit error on a channel:
*                   - During response field transmission (Slave and Master modes);
*                   - During header transmission (in Master mode).
* @implements       DLIN02003
* 
* @api
*/
#define LIN_BIT_ERROR                   0x01U

/**
* @brief            Interrupt Errors conditions
* @details          Checksum error on a channel.
* @implements       DLIN02003
* 
* @api
*/
#define LIN_CHECKSUM_ERROR              0x02U

/**
* @brief            Interrupt Errors conditions
* @details          Inconsistent Synch Field.
* @implements       DLIN02003
* 
* @api
*/
#define LIN_SYNCH_FIELD_ERROR           0x03U

/**
* @brief            Interrupt Errors conditions
* @details          Break Delimiter too short (< 1 bit).
* @implements       DLIN02003
* 
* @api
*/
#define LIN_BREAK_DELIMITER_ERROR       0x04U

/**
* @brief            Interrupt Errors conditions
* @details          Parity error.
* @implements       DLIN02003
* 
* @api
*/
#define LIN_IDENTIFIER_PARITY_ERROR     0x05U

/**
* @brief            Interrupt Errors conditions
* @details          Invalid stop bit:
*                   - During reception of any data in the 
*                     response field (Slave and Master modes);
*                   - During reception of Synch or Identifier
*                     Field (Slave mode).
* @implements       DLIN02003
* 
* @api
*/
#define LIN_FRAMING_ERROR               0x06U

/**
* @brief            Interrupt Errors conditions
* @details          New data byte is received on a channel
*                   and the buffer full flag is not cleared.
* @implements       DLIN02003
* 
* @api
*/
#define LIN_BUFFER_OVER_RUN_ERROR       0x07U

/**
* @brief            Interrupt Errors conditions
* @details          Noise detected on a received character.
* @implements       DLIN02003
* 
* @api
*/
#define LIN_NOISE_ERROR                 0x08U

/**
* @brief            Interrupt Errors conditions
* @details          Header or Response timeout detected.
* @implements       DLIN02003
* 
* @api
*/
#define LIN_TIMEOUT_ERROR               0x09U

/**
* @brief            Commands IDs
* @details          Tx frame is a master frame (response is provided by
*                   master).
* @implements       DLIN02005
* 
* @api
*/
#define LIN_TX_MASTER_RES_COMMAND       0x01U

/**
* @brief            Commands IDs
* @details          Tx frame is a slave frame (response is provided by
*                   slave).
* @implements       DLIN02005
* 
* @api
*/
#define LIN_TX_SLAVE_RES_COMMAND        0x02U

/**
* @brief            Commands IDs
* @details          Tx frame is a sleep command frame.
* @implements       DLIN02005
* 
* @api
*/
#define LIN_TX_SLEEP_COMMAND            0x03U

/**
* @brief            Commands IDs
* @details          No tx master command pending.
* @implements       DLIN02005
* 
* @api
*/
#define LIN_TX_NO_COMMAND               0x04U

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/
/**
* @brief          API functions service IDs.
* @details        Service IDs of the AUTOSAR LIN API.
* @implements     DLIN02015
*/
typedef enum
    {

#ifdef LIN_USE_MSC

    MSC_INITCHANNEL_ID       =   (uint8)0x0BU, /**< @brief
                                               Msc_InitChannel() ID.*/
    MSC_DEINITCHANNEL_ID     =   (uint8)0x0CU,  /**< @brief
                                               Msc_DeInitChannel() ID.*/
    MSC_GETSTATUS_ID         =   (uint8)0x0DU,  /**< @brief
                                               Msc_GetStatus() ID.*/
    MSC_POLLING_ID           =   (uint8)0x0EU,  /**< @brief
                                               Msc_Polling() ID.*/
#endif

    LIN_GETSTATUS_ID         =   (uint8)0x08U, /**< @brief
                                               Lin_GetStatus() ID.*/
    LIN_GETVERSIONINFO_ID    =   (uint8)0x01U, /**< @brief
                                               Lin_GetVersionInfo() ID.*/
    LIN_GOTOSLEEP_ID         =   (uint8)0x06U, /**< @brief
                                               Lin_GoToSleep() ID.*/
    LIN_GOTOSLEEPINTERNAL_ID =   (uint8)0x09U, /**< @brief
                                               Lin_GoToSleepInternal() ID.*/
    LIN_INIT_ID              =   (uint8)0x00U, /**< @brief
                                               Lin_Init()ID.*/
    LIN_SENDFRAME_ID         =   (uint8)0x04U, /**< @brief
                                               Lin_SendFrame() ID.*/
    LIN_WAKEUP_ID            =   (uint8)0x07U, /**< @brief
                                               Lin_WakeUp() ID.*/
    LIN_CHECKWAKEUP_ID       =   (uint8)0x0AU  /**< @brief
                                               Lin_CheckWakeup() ID.*/
    } API_Function_IDs;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_START_SEC_CODE
/*
* @violates @ref Lin_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/* @implements     DLIN02036 */
FUNC(Std_ReturnType, LIN_CODE)  Lin_CheckWakeup(VAR(uint8, AUTOMATIC) Channel);

/* @implements     DLIN02037 */
FUNC(void, LIN_CODE)            Lin_Init(P2CONST(Lin_ConfigType, AUTOMATIC, LIN_APPL_CONST) Config);

/* @implements     DLIN02030 */
FUNC(Lin_StatusType, LIN_CODE)  Lin_GetStatus(VAR(uint8, AUTOMATIC) Channel, \
                                  P2P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) Lin_SduPtr);

/* @implements     DLIN02032 */
FUNC(Std_ReturnType, LIN_CODE)  Lin_GoToSleep(VAR(uint8, AUTOMATIC) Channel);

/* @implements     DLIN02033 */
FUNC(Std_ReturnType, LIN_CODE)  Lin_GoToSleepInternal(VAR(uint8, AUTOMATIC) Channel);

/* @implements     DLIN02034 */
FUNC(Std_ReturnType, LIN_CODE)  Lin_SendFrame(VAR(uint8, AUTOMATIC) Channel, \
                                  P2VAR(Lin_PduType, AUTOMATIC,LIN_APPL_DATA) PduInfoPtr);
/* @implements     DLIN02035 */
FUNC(Std_ReturnType, LIN_CODE)  Lin_Wakeup(VAR(uint8, AUTOMATIC) Channel);

/* @implements     DLIN02031 */
#if LIN_VERSION_INFO_API == STD_ON
  FUNC (void, LIN_CODE) Lin_GetVersionInfo (P2VAR (Std_VersionInfoType, AUTOMATIC, \
              LIN_APPL_DATA) versioninfo);
#endif  /* #if LIN_VERSION_INFO_API == STD_ON */

#define LIN_STOP_SEC_CODE
/*
* @violates @ref Lin_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* LIN_H */

/** @} */
