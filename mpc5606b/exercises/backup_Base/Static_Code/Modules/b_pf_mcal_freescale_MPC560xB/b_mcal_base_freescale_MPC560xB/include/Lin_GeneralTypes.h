/**
*   @file    Lin_GeneralTypes.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - General Types.
*   @details API header for all types and constants that are shared among the AUTOSAR LIN modules
*            Lin, LinIf and LinTrcv.
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


#ifndef LIN_GENERAL_TYPES_H
#define LIN_GENERAL_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @file           Lin_GeneralTypes.h
* @implements     DLIN02203
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

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief          Checksum models for the LIN Frame.
* @details        This type is used to specify the Checksum model to be
*                 used for the LIN Frame.
* @implements     DLIN05031
*/
typedef enum
    {
    LIN_ENHANCED_CS,    /**< @brief Enhanced checksum model.*/
    LIN_CLASSIC_CS      /**< @brief Classic checksum model.*/
    } Lin_FrameCsModelType;

/**
* @brief          Frame response types.
* @details        This type is used to specify whether the frame
*                 processor is required to transmit the response
*                 part of the LIN frame.
* @implements     DLIN05034
*/

typedef enum
    {
    LIN_MASTER_RESPONSE,    /**< @brief Response is generated from
                                        this (master) node.*/
    LIN_SLAVE_RESPONSE,     /**< @brief Response is generated from a
                                        remote slave node.*/
    LIN_SLAVE_TO_SLAVE      /**< @brief Response is generated from one
                                        slave to another slave.*/
                            /**< @brief For the master the response
                                        will be anonymous, it does not
                                        have to receive the response.*/
    } Lin_FrameResponseType;

/**
* @brief          LIN Frame and Channel states operation.
* @details        LIN operation states for a LIN channel or frame, as returned
*                 by the API service Lin_GetStatus().
*                 part of the LIN frame.
* @implements     DLIN05036
*/
typedef enum
    {
    LIN_NOT_OK = 0,     /**< @brief Development or production error
                                    occurred.*/
    LIN_TX_OK,          /**< @brief Successful transmission.*/
    LIN_TX_BUSY,        /**< @brief Ongoing transmission (Header or
                                    Response).*/
    LIN_TX_HEADER_ERROR,/**< @brief Erroneous header transmission such
                                    as:
                                     - Mismatch between sent and read
                                       back data
                                     - Identifier parity error
                                     - Physical bus error.*/
    LIN_TX_ERROR,       /**< @brief Erroneous transmission such as:
                                     - Mismatch between sent and read
                                       back data
                                     - Physical bus error.*/
    LIN_RX_OK,          /**< @brief Reception of correct response.*/
    LIN_RX_BUSY,        /**< @brief Ongoing reception:
                                    at least one response byte has
                                    been received, but the checksum
                                    byte has not been received.*/
    LIN_RX_ERROR,       /**< @brief Erroneous reception such as:
                                     - Framing error
                                     - Overrun error
                                     - Checksum error
                                     - Short response.*/
    LIN_RX_NO_RESPONSE, /**< @brief No response byte has been received
                                    so far.*/
                        /**< @brief This is a mess !!
                                   Frame status is mixed with channel
                                   status but i kept it here only
                                   because of LIN168.*/
    LIN_OPERATIONAL,    /**< @brief Normal operation;
                                     - The related LIN channel is ready
                                       to transmit next header
                                     - No data from previous frame
                                       available (e.g. after
                                       initialization).*/
    LIN_CH_SLEEP        /**< @brief Sleep mode operation;
                                     - In this mode wake-up detection
                                       from slave nodes is enabled.*/
    } Lin_StatusType;
/**
* @brief          LinTrcv_TrcvModeType
* @details        Operating modes of the LIN Transceiver Driver.
*
* @implements     DLIN05037
*/ 
typedef enum
    {
         LINTRCV_TRCV_MODE_NORMAL, /** < @brief Transceiver mode NORMAL. */
         LINTRCV_TRCV_MODE_SLEEP,  /** < @brief Transceiver mode STANDBY. */
         LINTRCV_TRCV_MODE_STANDBY /** < @brief Transceiver mode SLEEP. */
    } LinTrcv_TrcvModeType;

/**
* @brief          LinTrcv_TrcvWakeupModeType
* @details        Wake up operating modes of the LIN Transceiver Driver.
*
* @implements     DLIN05038
*/ 
typedef enum
    {  
         LINTRCV_WUMODE_ENABLE, /** < @brief The notification for wakeup events is enabled
                                                                                    on the addressed network. */
         LINTRCV_WUMODE_DISABLE,/** < @brief The notification for wakeup events is disabled
                                                                                      on the addressed network. */
         LINTRCV_WUMODE_CLEAR  /** < @brief A stored wakeup event is cleared on the 
                                                                              addressed network. */
    } LinTrcv_TrcvWakeupModeType;

/**
* @brief          LinTrcv_TrcvWakeupReasonType
* @details        wake up reason detected by the LIN transceiver in detail..
*
* @implements     DLIN05039
*/ 
typedef enum
    {  
         LINTRCV_WU_ERROR, /** < @brief Due to an error wake up reason was not detected. 
                                                                  This value may only be reported when error was reported
                                                         to DEM before.*/
         LINTRCV_WU_NOT_SUPPORTED, /** < @brief The transceiver does not support any
                                                                                    information for the wake up reason.*/
         LINTRCV_WU_BY_BUS, /** < @brief The transceiver has detected, that the network 
                                                                    has caused the wake up of the ECU.*/
         LINTRCV_WU_BY_PIN, /** < @brief The transceiver has detected a wake-up event at
                                                                    one of the transceiver's pins (not at the LIN bus).*/
         LINTRCV_WU_INTERNALLY, /** < @brief The transceiver has detected, that the network
                                                                                has been woken up by the 
                                                                      ECU via a request to NORMAL mode.*/
         LINTRCV_WU_RESET,   /** < @brief The transceiver has detected, that the wake up
                                                                       is due to an ECU reset. */
         LINTRCV_WU_POWER_ON /** < @brief The transceiver has detected, that the wake up
                                                                   is due to an ECU reset after power on.*/
    } LinTrcv_TrcvWakeupReasonType;
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Data length of a LIN Frame.
* @details        This type is used to specify the number of SDU
*                 data bytes to copy.
* @implements     DLIN05032
*/
typedef uint8 Lin_FrameDlType;

/**
* @brief          The LIN identifier (0..0x3F) with its parity bits.
* @details        Represents all valid protected Identifier used by
*                 Lin_SendHeader().
* @implements     DLIN05033
*/
typedef uint8 Lin_FramePidType;

/**
* @brief          The LIN identifier (0..0x3F) with its parity bits.
* @details        This Type is used to provide PID, checksum model,
*                 data length and SDU pointer from the LIN Interface
*                 to the LIN driver.
* @implements     DLIN05035
*/
typedef struct
    {
    Lin_FramePidType      Pid;     /**< @brief LIN frame identifier.*/
    Lin_FrameCsModelType  Cs;      /**< @brief Checksum model type.*/
    Lin_FrameResponseType Drc;     /**< @brief Response type.*/
    Lin_FrameDlType       Dl;      /**< @brief Data length.*/
    uint8*                SduPtr;  /**< @brief Pointer to Sdu.*/
    } Lin_PduType;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* LIN_GENERAL_TYPES_H */

/** @} */
