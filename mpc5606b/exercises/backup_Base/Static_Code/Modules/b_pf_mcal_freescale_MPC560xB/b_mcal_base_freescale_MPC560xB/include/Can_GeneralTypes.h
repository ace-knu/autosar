/**
*   @file    Can_GeneralTypes.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - General Types.
*   @details API header for all types and constants that are shared among the AUTOSAR CAN
*            modules Can, CanIf and CanTrcv.
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


#ifndef CAN_GENERAL_TYPES_H
#define CAN_GENERAL_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @file           Can_GeneralTypes.h
* @implements     DCAN02203
*/
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Can_GeneralTypes_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Can_GeneralTypes_REF_2
* Violates MISRA 2004 Required Rule 9.3, In an enumerator list, the '=' construct shall not be used
* to explicitly initialise members other than the first, unless all items
* are explicitly initialised.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "ComStack_Cfg.h"

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
* @brief          CAN State Modes of operation.
* @details        State transitions that are used by the function CAN_SetControllerMode().
*
* @implements     DCAN02415
*/
typedef enum
    {
        CAN_T_STOP = 0U,   /**< @brief CANIF_CS_STARTED -> CANIF_CS_STOPPED */
        CAN_T_START,       /**< @brief CANIF_CS_STOPPED -> CANIF_CS_STARTED */
        CAN_T_SLEEP,       /**< @brief CANIF_CS_STOPPED -> CANIF_CS_SLEEP */
        CAN_T_WAKEUP       /**< @brief CANIF_CS_SLEEP -> CANIF_CS_STOPPED */
    } Can_StateTransitionType;


/**
* @brief          Can_ReturnType
* @details        CAN Return Types from Functions.
*
* @implements     DCAN02414
*/
typedef enum
    {
        CAN_OK = 0U,    /**< @brief Operation was ok executed */
        CAN_NOT_OK,     /**< @brief Operation was not ok executed */
        CAN_BUSY        /**< @brief Operation was rejected because of busy state */
    } Can_ReturnType;

/**
* @brief          CanTrcv_TrcvModeType
* @details        Operating modes of the CAN Transceiver Driver..
*
* @implements     DCAN02416
*/
typedef enum
    {
         CANTRCV_TRCVMODE_NORMAL = 0U,
         CANTRCV_TRCVMODE_SLEEP,
         CANTRCV_TRCVMODE_STANDBY,
    } CanTrcv_TrcvModeType;

/**
* @brief          CanTrcv_TrcvWakeupModeType
* @details        CAN transceiver concerning wake up events and wake up notifications..
*
* @implements     DCAN02418
*/   
typedef enum
    {  
         CANTRCV_WUMODE_ENABLE = 0U,
         CANTRCV_WUMODE_DISABLE,
         CANTRCV_WUMODE_CLEAR,
    } CanTrcv_TrcvWakeupModeType;

/**
* @brief          CanTrcv_TrcvWakeupReasonType
* @details        wake up reason detected by the CAN transceiver in detail.
*
* @implements     DCAN02419
*/   
typedef enum
    {  
         CANTRCV_WU_ERROR = 0U,
         CANTRCV_WU_BY_BUS,
         CANTRCV_WU_BY_PIN,
         CANTRCV_WU_INTERNALLY,
         CANTRCV_WU_NOT_SUPPORTED,
         CANTRCV_WU_POWER_ON,
         CANTRCV_WU_RESET,
         CANTRCV_WU_BY_SYSERR,
    } CanTrcv_TrcvWakeupReasonType;     
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @{
* @brief          Can_IdType
* @details        Type for storing the Identifier Length Type: Normal /Extended.
*                   - used by "Can_MessageBufferConfigObjectType" structure.
*                 The driver does not distinguish between Extended and Mixed transmission modes.
*                 Extended transmission mode of operation behaves the same as Mixed mode.
*
* @implements     DCAN02420
*/
#ifdef CAN_EXTENDEDID
    #if (CAN_EXTENDEDID == STD_ON)
    typedef  VAR(uint32, CAN_VAR) Can_IdType;
    #else /* (CAN_EXTENDEDID == STD_OFF) */
    typedef VAR(uint16, CAN_VAR) Can_IdType;
    #endif /* (CAN_EXTENDEDID == STD_ON/STD_OFF) */
#else
    typedef VAR(uint16, CAN_VAR) Can_IdType;
#endif
/**@}*/

/**
* @brief          Can_PduType
* @details        Type used to provide ID, DLC, SDU from CAN interface to CAN driver.
*                 HTH/HRH = ID+DLC+SDU.
*
* @implements     DCAN02417
*/
typedef struct
    {
        VAR(Can_IdType, CAN_VAR) id; /**< @brief CAN L-PDU = Data Link Layer Protocol Data Unit.
                                                 Consists of Identifier, DLC and Data(SDU)  It is
                                                 uint32 for CAN_EXTENDEDID=STD_ON, else is uint16.
                                                 */
        VAR(PduIdType, CAN_VAR) swPduHandle; /**< @brief The L-PDU Handle = defined and placed
                                                         inside the CanIf module layer. Each handle
                                                         represents an L-PDU, which is a constant
                                                         structure with information for Tx/Rx
                                                         processing. */
        VAR(uint8, CAN_VAR) length; /**< @brief DLC = Data Length Code (part of L-PDU that describes
                                                the SDU length). */
        P2VAR(uint8, CAN_VAR, CAN_APPL_DATA) sdu; /**< @brief CAN L-SDU = Link Layer Service Data
                                                              Unit. Data that is transported inside
                                                              the L-PDU. */
    } Can_PduType;


/**
* @{
* @brief          Can_HwHandleType
* @details        Represents the hardware object handles of a CAN hardware unit.
                  For CAN hardware units with more than 255 HW objects use extended range.
*                   - used by "Can_Write" function.
*                 The driver does not distinguish between Extended and Mixed transmission modes.
*                 Extended transmission mode of operation behaves the same as Mixed mode.
*
* @implements     DCAN02421
*/
#ifdef CAN_MBCOUNTEXTENSION
    #if (CAN_MBCOUNTEXTENSION == STD_ON)
    typedef VAR(uint32, CAN_VAR) Can_HwHandleType;
    #else /* (CAN_MBCOUNTEXTENSION==STD_OFF) */
    typedef VAR(uint16, CAN_VAR) Can_HwHandleType;
    #endif /* (CAN_MBCOUNTEXTENSION==STD_ON/STD_OFF) */
#else
    typedef VAR(uint16, CAN_VAR) Can_HwHandleType;
#endif
/**@}*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*CAN_GENERAL_TYPES_H*/

/** @} */
