/**
*   @file    Can_FlexCan_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - LLD module interface.
*   @details Low Level Driver header file for IPV = FlexCan.
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


#ifndef CAN_FLEXCAN_LLD_H
#define CAN_FLEXCAN_LLD_H


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section FlexCan_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
* @section  FlexCan_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section FlexCan_h_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
* @section FlexCan_h_REF_4
* Violates MISRA 2004 Required Rule  8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*  (CAN222) Imported types: Dem_Types.h, CanIf_Types.h, Std_Types.h, ComStack_Types.h */
/*
* @file           Can_FlexCan_LLD.h
* @implements     DCAN02201
*/
#include "Reg_Macros.h"
#include "Reg_eSys_FlexCan.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Can_FlexCan_LLD.h
* @implements     DCAN02423
*/
/*
* @violates @ref FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 1.4
*/
#define CAN_VENDOR_ID_FLEXCAN_H                    43
#define CAN_MODULE_ID_FLEXCAN_H                    80
/* @violates @ref FlexCan_h_REF_3 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_MAJOR_VERSION_FLEXCAN_H     4
/* @violates @ref FlexCan_h_REF_3 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_MINOR_VERSION_FLEXCAN_H     0
/*
* @violates @ref FlexCan_h_REF_1 Violates MISRA 2004 Required Rule 1.4, Identifier clash
*/
/* @violates @ref FlexCan_h_REF_3 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_REVISION_VERSION_FLEXCAN_H  3
#define CAN_SW_MAJOR_VERSION_FLEXCAN_H             1
#define CAN_SW_MINOR_VERSION_FLEXCAN_H             0
#define CAN_SW_PATCH_VERSION_FLEXCAN_H             1

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
* @brief          Can_HandleType
* @details        Used for value received by Tressos interface configuration.
*                 Controller does not provide any bit field to differentiate BASIC-CAN & FULL-CAN.
*
* @implements     DCAN02803
*/
typedef enum
    {
        CAN_BASIC = 0U,    /*< @brief Basic-CAN device functions */
        CAN_FULL           /*< @brief Full-CAN device functions */
    } Can_HandleType;


/**
* @brief          CAN Interrupts state.
* @details        CAN Interrupts state.
*
* @implements     DCAN02804
*/
typedef enum
    {
        CAN_INTERRUPT_DISABLED = 0U,  /*< @brief Interrupts disabled */
        CAN_INTERRUPT_ENABLED         /*< @brief Interrupts enabled */

    } Can_InterruptStateType;



/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Records the status of a CAN Controller during runtime.
* @details        Records the status of a CAN Controller during runtime.
*
* @implements     DCAN02805
* @note           This structure is not configured by Tresos.
*/
typedef struct
    {
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
        VAR(uint32, CAN_VAR) TxGuard[2]; /*< @brief Guard bits for EXCLUSIVE ACCESS to Tx MBs */

        VAR(uint32, CAN_VAR) MBInterruptMask[2]; /*< @brief Pre-calculated MB INT masks (used in Can_EnableControllerInterrupts) */

        VAR(PduIdType, CAN_VAR) TxPduId[64]; /*< @brief Storage space for PDU_ID (supplied in call to Can_Write and needed after Tx in CanIf_TxConfirmation) */
#else /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */
        VAR(uint32, CAN_VAR) TxGuard[1]; /*< @brief Guard bits for EXCLUSIVE ACCESS to Tx MBs */

        VAR(uint32, CAN_VAR) MBInterruptMask[1]; /*< @brief Pre-calculated MB INT masks (used in Can_EnableControllerInterrupts) */

        VAR(PduIdType, CAN_VAR) TxPduId[32]; /*< @brief Storage space for PDU_ID (supplied in call to Can_Write and needed after Tx in CanIf_TxConfirmation) */
#endif /* (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_32) */

        volatile VAR(sint8, CAN_VAR) IntDisableLevel; /*< @brief Storage space for Can_DisableControllerInterrupts nesting level */

        volatile VAR(Can_HwHandleType, CAN_VAR) CancelMBIndex; /*< @brief Index of MB buffer being cancelled. */

        volatile VAR(uint8, CAN_VAR) FirstTxMBIndex; /*< @brief Index of the first MB used for Tx for a specific controller. This value is relative to 0 (which is first MB). */

        VAR(uint8, CAN_VAR) ControllerSWFlag; /*< @brief Software flags for tracking interrupt changes state */

        VAR(uint8, CAN_VAR) InterruptMode; /*< @brief Global interrupt autorization state */

        VAR(Can_ControllerStateType, CAN_VAR) ControllerState; /*< @brief FlexCAN controller power state */

        VAR(uint16, CAN_VAR) Can_MBMapping[CAN_MAXMB_CONFIGURED]; /*< @brief Map for every MB the HOH assigned according to configuration. */

        VAR(uint8, CAN_VAR) CurrentBaudRateIndex; /*< @brief Current controller baudrate */
    } Can_ControllerStatusType;

typedef P2CONST( Can_MBConfigContainerType, CAN_CONST, CAN_APPL_DATA)   Can_PtrMBConfigContainerType;
typedef P2CONST( Can_ControlerDescriptorType, CAN_CONST, CAN_APPL_DATA) Can_PtrControlerDescriptorType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/* @violates @ref FlexCan_h_REF_3 This is required as per autosar Requirement. */
#define CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref FlexCan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"

/**
* @brief          Array holding current status/run-time configuration of individual FlexCAN controllers
* @details        Array holding current status/run-time configuration of individual FlexCAN controllers:
*                 - information like Guard bits, Pre-calculated MB INT masks, Storage space for PDU_ID, INT nesting level,
*                 Index of MB buffer being cancelled, Index of the first MB used for Tx
*                 - declared as global variable in "can_LLD.c" file.
*                 See Can_FlexCan_LLD.c for declaration.
*
* @implements     DCAN02806
*/
/* @violates @ref FlexCan_h_REF_4 Violates MISRA 2004 Required Rule 8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used */
extern VAR(Can_ControllerStatusType, CAN_VAR) Can_ControllerStatuses[CAN_MAXCTRL_CONFIGURED];

/**
* @brief          Array holding current MCR Register status
* @details        Array holding current MCR Register status. If the Can_SetControllerMode returns with CAN_NOT_OK,
*                 then the MCR Register is saved and the Can_MainFunction_Mode must be called to see a state change
*                 of the controller
*
* @implements     DCAN02810
*
*/
/* @violates @ref FlexCan_h_REF_4 Violates MISRA 2004 Required Rule 8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used */
extern VAR(uint32, CAN_VAR) Can_MCR_Configuration[CAN_MAXCTRL_SUPPORTED];

/* @violates @ref FlexCan_h_REF_3 This is required as per autosar Requirement. */
#define CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref FlexCan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"


/* @violates @ref FlexCan_h_REF_3 This is required as per autosar Requirement. */
#define CAN_START_SEC_VAR_NO_INIT_32
/*
* @violates @ref FlexCan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"
#if (CAN_API_ERROR_STATUS == STD_ON)
/*
* @brief   Array holding  status of ESR register of FlexCAN controllers
*/
/* @violates @ref FlexCan_h_REF_4 Violates MISRA 2004 Required Rule 8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used */
extern VAR(uint32, CAN_VAR)  Can_EsrRegStatus[ CAN_MAXCTRL_SUPPORTED ];
#endif
/* @violates @ref FlexCan_h_REF_3 This is required as per autosar Requirement. */
#define CAN_STOP_SEC_VAR_NO_INIT_32
/*
* @violates @ref FlexCan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_START_SEC_CODE
/*
* @violates @ref FlexCan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"

FUNC (void, CAN_CODE) Can_LLD_InitVariables( void);


FUNC (void, CAN_CODE) Can_LLD_Init(VAR(uint8, AUTOMATIC) Controller);


FUNC (Can_ReturnType, CAN_CODE) Can_LLD_ResetController( VAR(uint8, AUTOMATIC) Controller);


FUNC (void, CAN_CODE) Can_LLD_ChangeBaudrate( VAR(uint8, AUTOMATIC) Controller);

FUNC (Can_ReturnType, CAN_CODE) Can_LLD_SetControllerMode( VAR(uint8, AUTOMATIC) Controller,
                                                           P2CONST(Can_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) can_ptrControlerDescriptor,
                                                           VAR(Can_StateTransitionType, AUTOMATIC) Transition,
                                                           VAR(boolean, AUTOMATIC) canif_notification_required);

/* @violates @ref FlexCan_h_REF_3 This is required as per autosar Requirement. */
FUNC (void, CAN_CODE) Can_LLD_DisableControllerInterrupts( VAR(uint8, AUTOMATIC) Controller,
                                                           P2CONST(Can_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) can_ptrControlerDescriptor);

/* @violates @ref FlexCan_h_REF_3 This is required as per autosar Requirement. */
FUNC (void, CAN_CODE) Can_LLD_EnableControllerInterrupts( VAR(uint8, AUTOMATIC) Controller,
                                                          P2CONST(Can_ControlerDescriptorType, AUTOMATIC, CAN_APPL_CONST) can_ptrControlerDescriptor);


#if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)

FUNC (void, CAN_CODE) Can_LLD_Cancel( VAR(uint8, AUTOMATIC) controller,
                                      VAR(uint8, AUTOMATIC) mbindex);

#endif /* (CAN_HW_TRANSMIT_CANCELLATION == STD_ON) */

#if ((CAN_API_ENABLE_ABORT_MB == STD_ON) && (CAN_HW_TRANSMIT_CANCELLATION == STD_ON))

FUNC(void, CAN_CODE) Can_LLD_AbortMb( VAR(Can_HwHandleType, AUTOMATIC) Hth );

#endif


FUNC (Can_ReturnType, CAN_CODE) Can_LLD_Write( Can_HwHandleType Hth,
                                               P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_CONST) PduInfo);


FUNC (void, CAN_CODE) FlexCan_LLD_Process_Tx( CONST(uint8, CAN_CONST) controller,
                                          CONST(uint8, CAN_CONST) mbindex_start,
                                          CONST(uint8, CAN_CONST) mbindex_end);


FUNC (void, CAN_CODE) FlexCan_LLD_Process_Rx( CONST(uint8, CAN_CONST) controller,
                                          CONST(uint8, CAN_CONST) mbindex_start,
                                          CONST(uint8, CAN_CONST) mbindex_end);


#if (CAN_WAKEUP_SUPPORT == STD_ON)

FUNC (void, CAN_CODE) FlexCan_LLD_Process_Wakeup( CONST(uint8, CAN_CONST) controller);

#endif /* (CAN_WAKEUP_SUPPORTED == STD_ON) */


#if (CAN_TXPOLL_SUPPORTED == STD_ON)

FUNC (void, CAN_CODE) Can_LLD_MainFunction_Write( void);
/* @violates @ref FlexCan_h_REF_3 This is required as per autosar Requirement. */
FUNC (void, CAN_CODE) Can_LLD_MainFunction_Multiple_Write_Poll( VAR(uint8, AUTOMATIC) writepoll);

#endif /* (CAN_TXPOLL_SUPPORTED == STD_ON) */

#if (CAN_RXPOLL_SUPPORTED == STD_ON)

FUNC (void, CAN_CODE) Can_LLD_MainFunction_Read( void);
/* @violates @ref FlexCan_h_REF_3 This is required as per autosar Requirement. */
FUNC (void, CAN_CODE) Can_LLD_MainFunction_Multiple_Read_Poll( VAR(uint8, AUTOMATIC) readpoll);

#endif /* (CAN_RXPOLL_SUPPORTED == STD_ON) */


FUNC (void, CAN_CODE) FlexCan_LLD_Process_BusOff( CONST(uint8, CAN_CONST) controller);


FUNC (Std_ReturnType, CAN_CODE) Can_LLD_CheckWakeup( VAR(uint8, AUTOMATIC) controller);


FUNC (Std_ReturnType, CAN_CODE) Can_LLD_CheckBusOff( VAR(uint8, AUTOMATIC) controller);


FUNC (void, CAN_CODE) Can_LLD_MainFunction_Mode( void);



#if (CAN_RXFIFO_ENABLE == STD_ON)

FUNC(void, CAN_CODE) FlexCan_LLD_RxFifoFrameAvNotif( CONST(uint8, CAN_CONST) controller);

#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */



#if (CAN_DUAL_CLOCK_MODE == STD_ON)

FUNC(Std_ReturnType, CAN_CODE) Can_LLD_SetClockMode( VAR(uint8, AUTOMATIC) can_controller, VAR(Can_ClockMode, AUTOMATIC) can_clk_mode);

#endif /* CAN_DUAL_CLOCK_MODE == STD_ON */

#if (CAN_API_ERROR_STATUS == STD_ON)

FUNC (uint32, CAN_CODE) Can_LLD_GetErrorStatus( VAR(uint8, AUTOMATIC) can_controller);

#endif /* CAN_API_ERROR_STATUS == STD_ON */

#if ((defined CAN_API_TXCANCEL_CHECK) && (CAN_API_TXCANCEL_CHECK == STD_ON))

FUNC (void, CAN_CODE) Can_LLD_CheckTxCancel(void);

#endif /* CAN_API_TXCANCEL_CHECK == STD_ON */

#define CAN_STOP_SEC_CODE
/*
* @violates @ref FlexCan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* CAN_FLEXCAN_LLD_H */

/** @} */
