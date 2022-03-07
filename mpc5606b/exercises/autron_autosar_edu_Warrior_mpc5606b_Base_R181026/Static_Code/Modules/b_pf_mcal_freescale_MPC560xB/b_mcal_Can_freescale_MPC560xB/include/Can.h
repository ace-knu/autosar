/**
*   @file    Can.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface.
*   @details API header for CAN driver.
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


#ifndef CAN_H
#define CAN_H

#ifdef __cplusplus
extern "C"{
#endif

/*
(CAN043) The file Can.h contains the declaration of the Can module API.
(CAN037) The file Can.h only contains 'extern' declarations of constants, global data, type definitions and services
            that are specified in the Can module SWS.
*/

/**
* @file           Can.h
* @implements     DCAN02424
*/


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Can_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to the requirement that request to have empty APIs if polling is not used.
*
* @section Can_h_REF_2
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Can_h_REF_3
* Violates MISRA 2004 Required Rule 1.4, Required
* This violation is due to the requirement that request to have a file version check.
*
* @section Can_h_REF_4
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section Can_h_REF_5
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
* @section Can_h_REF_6
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only accessed
* from within a single function.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Can.h
* @implements     DCAN02402, DCAN02201
*/
#include "ComStack_Types.h"
#include "Can_Cfg.h"
#include "Can_GeneralTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
    Internal micro-dependent versioning. Check of AUTOSAR & Vendor specification version.
*/
/**
* @{
* @file           Can.h
* @implements     DCAN02423
*/
#define CAN_VENDOR_ID                   43
#define CAN_MODULE_ID                   80
#define CAN_AR_RELEASE_MAJOR_VERSION    4
#define CAN_AR_RELEASE_MINOR_VERSION    0
/*
* @violates @ref Can_h_REF_3 Violates MISRA 2004 Required Rule 1.4, Required
*/
#define CAN_AR_RELEASE_REVISION_VERSION 3
#define CAN_SW_MAJOR_VERSION            1
#define CAN_SW_MINOR_VERSION            0
#define CAN_SW_PATCH_VERSION            1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Can configuration header file are of the same vendor */
#if (CAN_VENDOR_ID != CAN_VENDOR_ID_CFG)
#error "Can.h and Can_Cfg.h have different vendor ids"
#endif
/* Check if current file and Can configuration header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (CAN_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (CAN_AR_RELEASE_REVISION_VERSION != CAN_AR_RELEASE_REVISION_VERSION_CFG_H))
  #error "AutoSar Version Numbers of Can.h and Can_Cfg.h are different"
#endif
/* Check if current file and CAN configuration header file are of the same software version */
#if ((CAN_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION_CFG_H) || \
     (CAN_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION_CFG_H) || \
     (CAN_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION_CFG_H))
  #error "Software Version Numbers of Can.h and Can_Cfg.h are different"
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @{
* @brief          Development errors.
* @details        (CAN104) The Can module shall be able to detect the following errors and exceptions depending on its configuration (development/production).
*                 (CAN026) Development Errors shall indicate errors that are caused by erroneous usage of the Can module API. This covers API
*                   parameter checks and call sequence errors.
*                 (CAN080) Development error values are of type uint8.
*
* @implements     DCAN02402, DCAN01402, DCAN02409, DCAN02406, DCAN02405, DCAN02404, DCAN02403, DCAN02408, DCAN02407
*/
#define CAN_E_PARAM_POINTER      ((uint8)0x01U)
#define CAN_E_PARAM_HANDLE       ((uint8)0x02U)
#define CAN_E_PARAM_DLC          ((uint8)0x03U)
#define CAN_E_PARAM_CONTROLLER   ((uint8)0x04U)
#define CAN_E_UNINIT             ((uint8)0x05U)
#define CAN_E_TRANSITION         ((uint8)0x06U)
#define CAN_E_DATALOST           ((uint8)0x07U)
#define CAN_E_DEFAULT            ((uint8)0x08U)
#define CAN_E_PARAM_BAUDRATE     ((uint8)0x09U)
/**@}*/

/**
* @{
* @brief          Service ID (APIs) for Det reporting
* @details        Service ID (APIs) for Det reporting
*
* @implements     DCAN02402, DCAN01402
*/
#define CAN_SID_INIT                          ((uint8)0x00U)
#define CAN_SID_MAIN_FUNCTION_WRITE           ((uint8)0x01U)
#define CAN_SID_SET_CONTROLLER_MODE           ((uint8)0x03U)
/* @violates @ref Can_h_REF_5 This is required as per autosar Requirement. */
#define CAN_SID_DISABLE_CONTROLLER_INTERRUPTS ((uint8)0x04U)
/* @violates @ref Can_h_REF_5 This is required as per autosar Requirement. */
#define CAN_SID_ENABLE_CONTROLLER_INTERRUPTS  ((uint8)0x05U)
#define CAN_SID_WRITE                         ((uint8)0x06U)
#define CAN_SID_GET_VERSION_INFO              ((uint8)0x07U)
#define CAN_SID_MAIN_FUNCTION_READ            ((uint8)0x08U)
#define CAN_SID_MAIN_FUNCTION_BUS_OFF         ((uint8)0x09U)
#define CAN_SID_MAIN_FUNCTION_WAKEUP          ((uint8)0x0AU)
#define CAN_SID_CBK_CHECK_WAKEUP              ((uint8)0x0BU)
#define CAN_SID_MAIN_FUNCTION_MODE            ((uint8)0x0CU)
#define CAN_SID_CHANGE_BAUDRATE               ((uint8)0x0DU)
#define CAN_SID_CHECK_BAUDRATE                ((uint8)0x0EU)
#define CAN_SID_SETCLOCKMODE                  ((uint8)0x0FU)
#define CAN_SID_ABORT_MB                      ((uint8)0x10U)
#define CAN_SID_GET_ERROR_STATUS              ((uint8)0x11U)
/**@}*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief          Can_ObjType
* @details        Used for value received by Tressos interface configuration.
*                 Describe the MB configuration.
*
* @implements     DCAN02427
*/
typedef enum
    {
        CAN_RECEIVE = 0U,   /**< @brief Receive MB */
        CAN_TRANSMIT        /**< @brief Transmit MB */
    } Can_ObjType;


/**
* @brief          CanIdType
* @details        Used for value received by Tressos interface configuration.
*                 Used to diferentiate Extended, Mixed or Standard Id type.
*
* @implements     DCAN02429
*/
typedef enum
    {
        CAN_EXTENDED = 0U,  /**< @brief Extended ID (29 bits) */
        CAN_STANDARD,       /**< @brief Standard ID (11 bits) */
        CAN_MIXED           /**< @brief Mixed ID (29 bits) */
    } CanIdType;


/**
* @brief          Can_StatusType
* @details        CAN Driver status used for checking and preventing double driver intialization.
*                 CAN_UNINIT = The CAN controller is not initialized. The CAN Controller is not participating on the CAN bus.
*                              All registers belonging to the CAN module are in reset state, CAN interrupts are disabled.
*                 CAN_READY = Controller has initialized: static variables, including flags;
*                             Common setting for the complete CAN HW unit; CAN controller specific settings for each CAN controller.
*
* @implements     DCAN02430
*/
typedef enum
    {
        CAN_UNINIT = 0U, /**< @brief Driver not initialized */
        CAN_READY       /**< @brief Driver ready */
    } Can_StatusType;

/**
* @brief          CAN Controller states.
* @details        States that defines the controllers.
*
* @implements     DCAN02415
*/
typedef enum
    {
        CAN_STOPPED = 0U, /**< @brief Controller in state STOPPED */
        CAN_STARTED,      /**< @brief Controller in state STARTED */
        CAN_SLEEPED       /**< @brief Controller in state SLEEPED */
    } Can_ControllerStateType;

/**
* @brief          Can_ClockMode
* @details        CAN source clock selection used in Can_SetClockMode Non-Autosar API.
*
* @implements     DCAN02431
*/
typedef enum
    {
        CAN_NORMAL = 0U, /**< @brief Standard configuration (default) */
        CAN_ALTERNATE    /**< @brief Second configuration (special) */
    } Can_ClockMode;


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief          Configuration of FlexCAN controller.
* @details        This structure is initialized by Tresos considering user settings.
*                 Used by Can_ChangeBaudrate() API to set the default baudrate after initialization.
*                 and to change the baudrate when the FlexCAN is in stopped mode.
*
* @implements     DCAN02416
*/
typedef struct
    {
        CONST(uint32, CAN_CONST) ControlRegister; /**< @brief Content of the Control Register (CTRL) fields: PRESDIV, RJW, PSEG1, PSEG2, CLKSRC, LPB, SMP, BOFF_REC, LOM, PROPSEG. */

#if (CAN_DUAL_CLOCK_MODE == STD_ON)
        CONST(uint32, CAN_CONST) ControlRegister_Alternate; /**< @brief Content of the Control Register (CTRL) fields: PRESDIV, RJW, PSEG1, PSEG2, CLKSRC, LPB, SMP, BOFF_REC, LOM, PROPSEG. */
#endif /* (CAN_DUAL_CLOCK_MODE == STD_ON) */

        CONST(uint16, CAN_CONST) ControllerBaudRate; /**< @brief Configured BaudRate in kbps. */
/* @violates @ref Can_h_REF_5 This is required as per autosar Requirement. */        
    } Can_ControllerBaudrateConfigType;

/*
* @{
* @brief          Can_IdPtrType
* @details        Type for storing pointer to the Identifier Lenght Type.
*                 - used by "Can_ConfigType" structure (pointer to the FilterMasks).
*
* @implements     DCAN02422
*/
#if (CAN_EXTENDEDID == STD_ON)
typedef CONSTP2CONST(uint32, CAN_CONST, CAN_APPL_CONST) Can_IdPtrType;
#else /* (CAN_EXTENDEDID == STD_OFF) */
typedef CONSTP2CONST(uint16, CAN_CONST, CAN_APPL_CONST) Can_IdPtrType;
#endif /* (CAN_EXTENDEDID == STD_OFF) */
/**@}*/

/**
* @brief          Type for pointer to function.
* @details        Type for pointer to function. Used for user handlers from plugin.
*
* @implements     DCAN02426
*/
#if (CAN_API_ERROR_STATUS == STD_ON)
typedef void (*Can_PCallBackType_ret)( uint32 status);
#endif
typedef void (*Can_PCallBackType)( void);


#if (CAN_RXFIFO_ENABLE == STD_ON)
/**
* @brief          Rx Fifo Table IDs and Filter Masks
* @details        Rx Fifo Table IDs and Filter Masks
*
* @implements     DCAN02432
*/
typedef struct
    {
        CONST(uint32, CAN_CONST) TableId; /**< @brief Table with the IDs specific for Rx Fifo */

        CONST(uint32, CAN_CONST) TableFilterMask; /**< @brief Table with the Filter masks */

    } Can_RxFiFoTableIdConfigType;

#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */


/**
* @brief          Can_MBConfigObjectType
* @details        Type for storing information about Message Buffers (CAN hardware objs).
*                 Used by Can_MBConfigContainerType.
*
* @implements     DCAN02433
*/
typedef struct
    {
        VAR(Can_HwHandleType, CAN_VAR) IdMaskIndex; /**< @brief Index into array of Can_FilterMaskType values (uint8/uint16), Current MB and the coresponding filter mask. */

        CONST(uint8, CAN_CONST) ControllerId; /**< @brief Controller ID (index into controller address array containing Can_ControllerPtrType). */

        VAR(CanIdType, CAN_VAR) IdType; /**< @brief ID type: CAN_EXTENDED, CAN_STANDARD, CAN_MIXED. */

        VAR(Can_ObjType, CAN_VAR) MBType; /**< @brief Receive/Transmit */

        VAR(Can_IdType, CAN_VAR) MessageId; /**< @brief (extended identifier) (uint16/uint32). configurable by CanHardwareObject/CanIdValue. */

        CONST(uint8, CAN_CONST) LocalPriority; /**< @brief Local priority bits used for arbitration. */

        VAR(uint32, CAN_VAR) HWObjID; /**< @brief HW Obiect ID */

        CONST(uint8, CAN_CONST) CanMainFuncRWPeriodRef; /**< @brief read write period reference */

    } Can_MBConfigObjectType;


/**
* @brief          Type for storing Message Buffer configurations.
* @details        The MessageBufferConfigs array is sorted according to:
*                 - HRHs first, HTHs next (AutoSAR requirement)
*                 - Controller ID (HRHs and HTHs belonging to all controllers must be grouped together)
*                 - Message ID (to ensure top priority IDs are first which means they will be serviced first)
*
* @implements     DCAN02418
*/
typedef struct
    {
        CONSTP2CONST(Can_MBConfigObjectType, CAN_CONST, CAN_APPL_CONST) MessageBufferConfigsPtr; /**< @brief Pointer to the MB array . */

        CONST(Can_HwHandleType, CAN_CONST) MessageBufferConfigCount; /**< @brief Number of elements in the array -( having 6 controllers with 64MBs each uint8 is not enough to store this value -> the type is extended to uint16). */

    } Can_MBConfigContainerType;


/**
* @brief          Structure for describing individual FlexCAN controllers on the chip.
* @details        HRH = Hardware Receive Handle (HRH) is defined and provided by the CAN driver.
*                       Each HRH represents exactly one hardware object.
*                       The HRH can be used to optimize software filtering.
*                 HTH = The Hardware Transmit Handle (HTH) is defined and provided by the CAN driver.
*                       Each HTH represents one or several hardware objects, that are
*                       configured as hardware transmit pool.
*
* @implements     DCAN02434
*/
typedef struct
    {
        CONST(uint8, CAN_CONST) ControllerOffset; /**< @brief Hardware Offset for Can controller: FLEXCAN_A = Offset[0], FLEXCAN_B = Offset[1], ... */

        CONST(uint8, CAN_CONST) MaxMBCount; /**< @brief Max Message Buffer number. */

        CONST(uint8, CAN_CONST) MaxBaudRateCount; /**< @brief Max BaudRate number. */

        CONST(uint8, CAN_CONST) DefaultBaudRateIndex; /**< @brief Default baudrate index. */

        CONSTP2CONST(Can_ControllerBaudrateConfigType, CAN_CONST, CAN_APPL_CONST) ControllerBaudrateConfigsPtr; /**< @brief Pointer to the Configuration of Baudrate timing parameter for FlexCAN baudrate controller ( CTRL value register). */

#if (CAN_WAKEUP_SUPPORT == STD_ON)
        CONST(uint32, CAN_CONST) CanWakeupSourceID; /*< @brief WakeUp source ID (type def uint32 EcuM_WakeupSourceType - in EcuM.h (uint32) ). */
#endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */

#if (CAN_RXFIFO_ENABLE == STD_ON)
        CONST(uint8, CAN_CONST) RxFiFoTableIdConfigIndex; /*< @brief RxFifo TableID Controller index. */

        CONST(Can_PCallBackType, CAN_CONST) Can_RxFifoOverflowNotification; /*< @brief Pointer to RX FIFO Overflow notification function. */

        CONST(Can_PCallBackType, CAN_CONST) Can_RxFifoWarningNotification; /*< @brief Pointer to RX FIFO Warning notification function. */
#endif  /* (CAN_RXFIFO_ENABLE == STD_ON) */

#if (CAN_ERROR_NOTIFICATION_ENABLE == STD_ON)
#if (CAN_API_ERROR_STATUS == STD_ON)
        /**
        @brief Pointer to Error interrupt notification function (ESR[ERR_INT]).
        */
        CONST(Can_PCallBackType_ret, CAN_CONST) Can_ErrorNotification;
#else
        CONST(Can_PCallBackType, CAN_CONST) Can_ErrorNotification; /*< @brief Pointer to Error interrupt notification function (ESR[ERR_INT]). */
#endif /* (CAN_API_ERROR_STATUS == STD_ON) */
#endif /* (CAN_ERROR_NOTIFICATION_ENABLE == STD_ON) */

        CONST(uint32, CAN_CONST) Options; /*< @brief BusOff Sw Recovery, RXFifo En, IDAM Type,  Event Trigger Mode TxProcessing/RxProcessing/BusoffProcessing/WakeuProcessing: Polling vs Interrupt mode. */

#if (CAN_MIX_MB_SUPPORT == STD_ON)
        CONST(uint8, CAN_CONST) Can_NumberOfMB; /*< @brief Number of message Buffers available for FlexCan unit. */
#endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */

#if (CAN_RXFIFO_ENABLE == STD_ON)
    CONST(Can_HwHandleType, CAN_CONST) FirstHrhIndex;
#endif  /* (CAN_RXFIFO_ENABLE == STD_ON) */ 

    } Can_ControlerDescriptorType;


/**
* @brief          Top Level structure containing all Driver configuration.
* @details        A pointer to this structure is transmitted to Can_Init() to initalize the driver at startup.
*                 The application selects one of the configurations by using a pointer to one of the elements
*                 of this array as a parameter of the Can_Init function.
*
* @implements     DCAN02419
*/
typedef struct
    {
        VAR(uint8, CAN_VAR) Can_ControllersConfigured; /**< @brief Number of Can Controllers configured in Tresos plugin. */

        VAR(Can_IdPtrType, CAN_VAR) FilterMasksPtr; /**< @brief Pointer to the first FilterMask value - any controller can have many filter masks for Can messages. */

        CONST(Can_MBConfigContainerType, CAN_CONST) MBConfigContainer; /**< @brief Pointer to the first MB configuration of this Controller. */

        P2CONST(Can_ControlerDescriptorType, CAN_CONST, CAN_APPL_CONST) ControlerDescriptors; /**< @brief Pointer to the first FlexCAN Controller description. */

#if (CAN_RXFIFO_ENABLE == STD_ON)

        CONSTP2CONST(Can_RxFiFoTableIdConfigType, CAN_CONST, CAN_APPL_CONST) Can_RxFiFoTableIdConfigPtr; /**< @brief Pointer to the Table IDs for the RxFifo. */

#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */

        /*Maximum Object IDs configured */
        VAR(uint32, CAN_VAR) Can_max_object_Id;

        /*Controller ID mapping*/
        CONST(uint8, CAN_CONST) Can_ControllerID_Mapping[CAN_MAX_OBJECT_ID];

        /*Can Object Type mapping*/
        CONST(Can_ObjType, CAN_CONST) Can_ObjectType_Mapping[CAN_MAX_OBJECT_ID];
      /**
       * @brief CAN Driver DEM Error
       *
       */
    #if (CAN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
        /* Can Driver DEM Error: CAN_E_TIMEOUT */
        CONST(Mcal_DemErrorType, CAN_CONST) Can_E_TimeoutCfg;
    #endif
    } Can_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/* @violates @ref Can_h_REF_5 This is required as per autosar Requirement. */
#define CAN_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Can_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"

/**
* @brief          Holds current status/run-time of CAN driver: CAN_UNINIT or CAN_READY (declared as global variable in "Can.c" file).
* @details        (CAN103) After power-up/reset, the Can module shall be in the state CAN_UNINIT.
*                 Covers CAN103
*
* @implements     DCAN00103, DCAN02410
*/

#if (CAN_DEV_ERROR_DETECT == STD_ON)

extern VAR(Can_StatusType, CAN_VAR) Can_DriverStatus;

#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

/* @violates @ref Can_h_REF_5 This is required as per autosar Requirement. */
#define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Can_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"

/* @violates @ref Can_h_REF_5 This is required as per autosar Requirement. */
#define CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Can_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"

/* Pointer to the current Driver Configuration (passed to the driver during initialization). Initialized by Can_Init(). */
extern P2CONST(Can_ConfigType, CAN_VAR, CAN_APPL_CONST) Can_CurrentConfigPtr;
extern P2CONST(Can_ControlerDescriptorType, CAN_VAR, CAN_APPL_CONST) Can_ControlerDescriptorsPtr;

/* @violates @ref Can_h_REF_5 This is required as per autosar Requirement. */
#define CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Can_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"

/* @violates @ref Can_h_REF_5 This is required as per autosar Requirement. */
#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Can_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"

/* Extern declarations for CanController Configuration and CanConfigType. Exports the PC or PB Can_ConfigType structures. */
#if (CAN_PRECOMPILE_SUPPORT == STD_ON)
    /* Export Driver configuration */
    /* @violates @ref Can_h_REF_6 Violates MISRA 2004 Required Rule 8.7,The object is defined with external linkage but is only used in function*/  
    CAN_INIT_CONFIG_PC_DEFINES
#endif /* #if (CAN_PRECOMPILE_SUPPORT == STD_ON) */

#if (CAN_PRECOMPILE_SUPPORT == STD_OFF)
    /* Export Driver configuration */
    CAN_INIT_CONFIG_PB_DEFINES
#endif /* #if (CAN_PRECOMPILE_SUPPORT == STD_OFF) */

/* @violates @ref Can_h_REF_5 This is required as per autosar Requirement. */
#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Can_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define CAN_START_SEC_CODE
/*
* @violates @ref Can_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"


extern FUNC (void, CAN_CODE) Can_Init( P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) Config);



#if (CAN_VERSION_INFO_API == STD_ON)

extern FUNC(void, CAN_CODE) Can_GetVersionInfo( P2VAR(Std_VersionInfoType, AUTOMATIC, CAN_APPL_DATA) versioninfo);

#endif /* (CAN_VERSION_INFO_API == STD_ON) */

#if (CAN_CHANGE_BAUDRATE_API == STD_ON)

extern FUNC (Std_ReturnType, CAN_CODE) Can_ChangeBaudrate( VAR(uint8, AUTOMATIC) Controller,
                                                           CONST(uint16, CAN_CONST) Baudrate);



extern FUNC (Std_ReturnType, CAN_CODE) Can_CheckBaudrate( VAR(uint8, AUTOMATIC) Controller,
                                                           CONST(uint16, CAN_CONST) Baudrate);

#endif /* (CAN_CHANGE_BAUDRATE_API == STD_ON) */


extern FUNC (Can_ReturnType, CAN_CODE) Can_SetControllerMode( VAR(uint8, AUTOMATIC) Controller,
                                                              VAR(Can_StateTransitionType, AUTOMATIC) Transition);



extern FUNC (void, CAN_CODE) Can_DisableControllerInterrupts( VAR(uint8, AUTOMATIC) Controller);



extern FUNC (void, CAN_CODE) Can_EnableControllerInterrupts( VAR(uint8, AUTOMATIC) Controller);



extern FUNC (Can_ReturnType, CAN_CODE) Can_Write( VAR(Can_HwHandleType, AUTOMATIC) Hth,
                                                  P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_CONST) PduInfo);


extern FUNC (Can_ReturnType, CAN_CODE) Can_CheckWakeup( VAR(uint8, AUTOMATIC) controller);





#if (CAN_TXPOLL_SUPPORTED == STD_ON)

extern FUNC (void, CAN_CODE) Can_MainFunction_Write( void );

#else /* (CAN_TXPOLL_SUPPORTED == STD_OFF) */

/* @violates @ref Can_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define Can_MainFunction_Write()

#endif /* (CAN_TXPOLL_SUPPORTED == STD_OFF) */

#if (CAN_RXPOLL_SUPPORTED == STD_ON)


extern FUNC (void, CAN_CODE) Can_MainFunction_Read( void);


#else /* (CAN_RXPOLL_SUPPORTED == STD_OFF) */
/* @violates @ref Can_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define Can_MainFunction_Read()

#endif /* (CAN_RXPOLL_SUPPORTED == STD_OFF) */



#if (CAN_BUSOFFPOLL_SUPPORTED == STD_ON)

extern FUNC (void, CAN_CODE) Can_MainFunction_BusOff( void);

#else /* (CAN_BUSOFFPOLL_SUPPORTED == STD_OFF) */

/* @violates @ref Can_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define Can_MainFunction_BusOff()


#endif /* (CAN_BUSOFFPOLL_SUPPORTED == STD_OFF) */



#if (CAN_WAKEUP_SUPPORT == STD_ON)
  #if (CAN_WAKEUPPOLL_SUPPORTED == STD_ON)

extern FUNC (void, CAN_CODE) Can_MainFunction_Wakeup( void);

  #else /* (CAN_WAKEUPPOLL_SUPPORTED == STD_OFF) */



  #define Can_MainFunction_Wakeup()


  #endif /* (CAN_WAKEUPPOLL_SUPPORTED == STD_OFF) */
#endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */


extern FUNC (void, CAN_CODE) Can_MainFunction_Mode( void);


#if (CAN_API_ENABLE_ABORT_MB == STD_ON)


extern FUNC(void, CAN_CODE) Can_AbortMb( VAR(Can_HwHandleType, AUTOMATIC) Hth);

#endif /* (CAN_API_ENABLE_ABORT_MB == STD_ON) */



#if (CAN_DUAL_CLOCK_MODE == STD_ON)


extern FUNC(Std_ReturnType, CAN_CODE) Can_SetClockMode( VAR(uint8, AUTOMATIC) can_controller, VAR(Can_ClockMode, AUTOMATIC) can_clk_mode);

#endif /* CAN_DUAL_CLOCK_MODE == STD_ON */

#if (CAN_API_ERROR_STATUS == STD_ON)

/* @violates @ref Can_c_REF_4  Use of external objects*/
extern FUNC (uint32, CAN_CODE) Can_GetErrorStatus( VAR(uint8, AUTOMATIC) can_controller);

#endif /* CAN_API_ERROR_STATUS == STD_ON */
/*================================================================================================*/
#if ((defined CAN_API_TXCANCEL_CHECK) && (CAN_API_TXCANCEL_CHECK == STD_ON))
extern FUNC (void, CAN_CODE) Can_CheckTxCancel(void);

#endif /* CAN_API_TXCANCEL_CHECK == STD_ON */

#define CAN_STOP_SEC_CODE
/*
* @violates @ref Can_h_REF_4 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*CAN_H*/

/** @} */
