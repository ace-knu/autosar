/**
*   @file    Eth_GeneralTypes.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base driver type definitions header file
*   @details Definitions of types for the Ethernet driver
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup ETH_DRIVER
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

#ifndef ETH_GENERALTYPES_H
#define ETH_GENERALTYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Eth_GeneralTypes_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, A compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers.
* Name length of the macro is unfortunately longer than 31 characters required by the agreed file
* template and cannot be changed. Authors of the template have not taken the MISRA rules into
* account.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "ComStack_Types.h" /* Mandatory include - see the SWS */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_VENDOR_ID_ETHGENERALTYPES                    43
#define ETH_MODULE_ID_ETHGENERALTYPES                    0
/** @violates @ref Eth_GeneralTypes_h_REF_1 MISRA rule 1.4 */
#define ETH_AR_RELEASE_MAJOR_VERSION_ETHGENERALTYPES     4
/** @violates @ref Eth_GeneralTypes_h_REF_1 MISRA rule 1.4 */
#define ETH_AR_RELEASE_MINOR_VERSION_ETHGENERALTYPES     0
/** @violates @ref Eth_GeneralTypes_h_REF_1 MISRA rule 1.4 */
#define ETH_AR_RELEASE_REVISION_VERSION_ETHGENERALTYPES  3
/** @violates @ref Eth_GeneralTypes_h_REF_1 MISRA rule 1.4 */
#define ETH_SW_MAJOR_VERSION_ETHGENERALTYPES             1
/** @violates @ref Eth_GeneralTypes_h_REF_1 MISRA rule 1.4 */
#define ETH_SW_MINOR_VERSION_ETHGENERALTYPES             0
/** @violates @ref Eth_GeneralTypes_h_REF_1 MISRA rule 1.4 */
#define ETH_SW_PATCH_VERSION_ETHGENERALTYPES             1

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
* @brief          TEthernet Driver specific return type
* @details        A variable of this type will hold the return type.
*/
typedef enum
{
    ETH_OK = 0,  /**< success*/
    ETH_E_NOT_OK,   /**< general failure   */
    ETH_E_NO_ACCESS      /**< Ethernet hardware access failure*/
} Eth_ReturnType;

/**
* @brief          The Ethernet driver state.
* @details        A variable of this type holds the state of the Ethernet driver
*                 module. The driver is at the ETH_STATE_UNINIT at the beginning
*                 until the Eth_Init() function is called. The state remains
*                 equal to the ETH_STATE_INIT until the Eth_ControllerInit()
*                 function is called. Then the state is ETH_STATE_ACTIVE.
*/
typedef enum
{
    ETH_STATE_UNINIT = 0, /**< The driver has not been initialized yet */
    ETH_STATE_INIT,       /**< The driver has not been configured but
                               the controller has not been initialized yet */
    ETH_STATE_ACTIVE      /**< The driver was initialized and
                               the controller was configured */
} Eth_StateType;

/**
* @brief          The Ethernet controller mode.
* @details        This type is used to store the information whether the
*                 Ethernet controller is stopped or running.
*/
typedef enum
{
    ETH_MODE_DOWN = 0,    /**< Controller is shut down */
    ETH_MODE_ACTIVE       /**< Controller is active */
}  Eth_ModeType;

/**
* @brief          The Ethernet reception status
* @details        This status is returned by the @c Eth_Receive() function to indicate
*                 whether any frame has been received and if yes, whether there is any
*                 frame still waiting in the queue (for another @c Eth_Receive() call).
*/
typedef enum
{
    ETH_RECEIVED = 0,   /**< A frame has been received and there are no more frames in the queue */
    ETH_NOT_RECEIVED,   /**< No frames received */
    ETH_RECEIVED_MORE_DATA_AVAILABLE, /**< A frame received and at least another one 
                                          in the queue detected */
    ETH_RECEIVED_FRAMES_LOST /**< Ethernet frame has been received, some frames got lost */
} Eth_RxStatusType;

/**
* @brief          Action type for PHY address filtering
* @details        The Enumeration type describes the action to be taken
*                 for the MAC address given in *PhysAddrPtr
*/
typedef enum
{
    ETH_ADD_TO_FILTER = 0,    /**< Add address to the filter */
    ETH_REMOVE_FROM_FILTER    /**< Remove address */
} Eth_FilterActionType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief         Frame type.
* @details       This type is used to pass the value of type/length field in the
*                Ethernet frame header. It is 16 bits long unsigned integer.
*                - Values less than or equal to 1500 represent the length.
*                - Values grater than 1500 represent the type (i.e. 0x800 = IP).
*/
typedef uint16 Eth_FrameType;

/**
* @brief         Type used to pass transmit/receive data to/from the driver.
* @details       This type was defined as 8 bit wide unsigned integer because
*                this definition is available on all CPU types.
*/
typedef uint8 Eth_DataType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* ETH_GENERALTYPES_H */
/** @} */
