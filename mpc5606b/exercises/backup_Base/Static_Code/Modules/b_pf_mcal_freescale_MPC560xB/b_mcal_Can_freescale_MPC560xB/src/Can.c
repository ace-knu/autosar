/**
*   @file    Can.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface
*   @details API implementation for CAN driver.
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


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Can_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Can_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* here are different kinds of execution code sections.
*
* @section Can_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
* @section Can_c_REF_4
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* This violation is due to the structure of the types used.
*
* @section Can_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Can_c_REF_6
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
 * significance of more than 31 characters.
*
*/


/*
Driver Limitations:
    1. The maximum number of Can_DisableControllerInterrupts levels of nesting is 127. (variable "sint8" used for nesting level: -128 .. +127)
    2. This file contains 2 types of functions: first are the Autosar APIs and then are some user defined functions.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @file           Can.c
* @implements     DCAN02423
*/
#include "Can.h"
#include "Can_LLD.h"
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*  (CAN111) Can.c shall check if the correct version of Can.h is included.
            This shall be done by a preprocessor check of the version numbers CAN_SW_MAJOR_VERSION, CAN_SW_MINOR_VERSION and CAN_SW_PATCH_VERSION.
*/
/**
* @file           Can.c
* @implements     DCAN02423
*/
#define CAN_VENDOR_ID_C                      43
#define CAN_AR_RELEASE_MAJOR_VERSION_C       4
#define CAN_AR_RELEASE_MINOR_VERSION_C       0
/*
* @violates @ref Can_c_REF_3 Violates MISRA 2004 Required Rule 1.4,  Identifier clash
*/
/* @violates @ref Can_c_REF_6 This is required as per autosar Requirement.*/
#define CAN_AR_RELEASE_REVISION_VERSION_C    3
#define CAN_SW_MAJOR_VERSION_C               1
#define CAN_SW_MINOR_VERSION_C               0
#define CAN_SW_PATCH_VERSION_C               1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CAN header file are of the same vendor */
#if (CAN_VENDOR_ID_C != CAN_VENDOR_ID)
    #error "Can.c and Can.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_C    != CAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_AR_RELEASE_MINOR_VERSION_C    != CAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_AR_RELEASE_REVISION_VERSION_C != CAN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Can.c and Can.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_C != CAN_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_C != CAN_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_C != CAN_SW_PATCH_VERSION))
    #error "Software Version Numbers of Can.c and Can.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CAN_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Can.c and Det.h are different"
    #endif
  #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/* @violates @ref Can_c_REF_6 This is required as per autosar Requirement.*/
#define CAN_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Can_c_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/

#include "MemMap.h"


#if (CAN_DEV_ERROR_DETECT == STD_ON)

/**
* @brief          This variable holds the state of the driver.
* @details        This variable holds the state of the driver. After reset is UNINIT. The output of Can_Init() function
*                 (only to first call) should set this variable into READY state.
*                  CAN_UNINIT = The CAN controller is not initialized. All registers belonging to the CAN module are in reset state, CAN interrupts are disabled.
*                  The CAN Controller is not participating on the CAN bus.
*                  The Can module must only implement a variable for the module state, when the development error tracing is switched on.
*                  When the development error tracing is switched off, the Can module does not need to implement this 'state machine',
*                  because the state information is only needed to check if Can_Init was called prior to any Can module function.
*
* @implements     DCAN01801
*
*/
/* @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
VAR(Can_StatusType, CAN_VAR) Can_DriverStatus = CAN_UNINIT;
#endif

/* @violates @ref Can_c_REF_6 This is required as per autosar Requirement.*/
#define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Can_c_REF_1 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
* @violates @ref Can_c_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/

#include "MemMap.h"


/* @violates @ref Can_c_REF_6 This is required as per autosar Requirement.*/
#define CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Can_c_REF_1 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
* @violates @ref Can_c_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/

#include "MemMap.h"

/* Pointer to the current Driver Configuration (passed to the driver during initialization). Initialized by Can_Init(). */
P2CONST(Can_ConfigType, CAN_VAR, CAN_APPL_CONST) Can_CurrentConfigPtr = NULL_PTR;
P2CONST(Can_ControlerDescriptorType, CAN_VAR, CAN_APPL_CONST) Can_ControlerDescriptorsPtr = NULL_PTR;

/* @violates @ref Can_c_REF_6 This is required as per autosar Requirement.*/
#define CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Can_c_REF_1 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
* @violates @ref Can_c_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/

#include "MemMap.h"


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define CAN_START_SEC_CODE
/*
* @violates @ref Can_c_REF_1 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
* @violates @ref Can_c_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/

#include "MemMap.h"


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


/*================================================================================================*/
/*
* @brief          Returns the version information of this module. SID = 0x07
* @details        This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      versioninfo A pointer to location to store version info
*                             Must be omitted if the function does not have parameters.
*
* @return         void
*
* @api
*
* @pre            The CAN_VERSION_INFO_API define must be configured on.
* @post           The version information is return if the parameter versionInfo is not a null pointer.
*
* @implements     DCAN01002, DCAN01003, DCAN01004, DCAN01005, DCAN01006, DCAN01007
*
*/
#if (CAN_VERSION_INFO_API == STD_ON)
/* @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC(void, CAN_CODE) Can_GetVersionInfo( P2VAR(Std_VersionInfoType, AUTOMATIC, CAN_APPL_DATA) versioninfo)
    {

    #if (CAN_DEV_ERROR_DETECT == STD_ON)
        /*
        (CAN177) If development error detection for the Can module is enabled: The function Can_GetVersionInfo shall
                     raise the error CAN_E_PARAM_POINTER if the parameter versionInfo is a null pointer.
        */
        if ( NULL_PTR == versioninfo )
        {
            Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_GET_VERSION_INFO, (uint8)CAN_E_PARAM_POINTER);
        }
        else
        {
    #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
            /*
            (CAN105) The function Can_GetVersionInfo shall return the version information of this module. The version information
                         includes: Module Id, Vendor Id, Vendor specific version numbers.
            */
            versioninfo->vendorID         = (uint16)CAN_VENDOR_ID;
            versioninfo->moduleID         = (uint16)CAN_MODULE_ID;
            versioninfo->sw_major_version = (uint8)CAN_SW_MAJOR_VERSION;
            versioninfo->sw_minor_version = (uint8)CAN_SW_MINOR_VERSION;
            versioninfo->sw_patch_version = (uint8)CAN_SW_PATCH_VERSION;
    #if (CAN_DEV_ERROR_DETECT == STD_ON)
        }
    #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    }

#endif /* (CAN_VERSION_INFO_API == STD_ON) */


/*================================================================================================*/
/**
* @brief          Initialize the CAN driver. SID = 0x00.
* @details        Initialize all the controllers.
*                 The CAN module shall be initialized by Can_Init(<&Can_Configuration>) service call during the start-up.
*                 This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Config Pointer to driver configuration.
*
* @return         void
*
* @api
*
* @pre            Can_Init shall be called at most once during runtime.
* @post           Can_Init shall initialize all the controllers and set the driver in READY state.
*
* @implements     DCAN01008, DCAN01009, DCAN01010, DCAN01011, DCAN01012, DCAN01013, DCAN01014, DCAN01015, DCAN01016, DCAN01017, DCAN01018, DCAN01128, DCAN01103
* @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static
*/
FUNC (void, CAN_CODE) Can_Init( P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) Config)
    {

        /* Variable for indexing the controllers. */
        VAR(uint8, AUTOMATIC) can_controller = 0U;

#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /*
           (CAN027) Detected development errors shall be reported to the Det_ReportError service of the Development Error Tracer (DET)
                   if the pre-processor switch CanDevErrorDetection is set.
           (CAN083) If the CanDevErrorDetection switch is enabled API parameter checking is enabled.
           (CAN028)Development Errors call the Development Error Tracer when DET is switched on and the Can module detects an error.

        */
        if ( CAN_READY == Can_DriverStatus )
        {
            /*
            (CAN247) The Can module environment shall call Can_Init at most once during runtime.
            (CAN091) After return of the DET the Can module function that raised the development error shall return immediately.
            (CAN174) If development error detection for the Can module is enabled: The function Can_Init shall raise the
                       error CAN_E_TRANSITION if the driver is not in 'uninitialized' state.
            (CAN248) The function Can_Init shall report the error CAN_E_UNINIT, if Can_Init was called prior to any Can module function.
            */
            Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_INIT, (uint8)CAN_E_TRANSITION);
        }
        else
        {
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

#if (CAN_PRECOMPILE_SUPPORT == STD_ON)
            /* Update config pointer with default configuration if precompile support on. */
            Can_CurrentConfigPtr = (NULL_PTR == Config) ? &Can_ConfigSet_PC : Config;
            Can_ControlerDescriptorsPtr = Can_CurrentConfigPtr->ControlerDescriptors;
#endif /* #if (CAN_PRECOMPILE_SUPPORT == STD_ON) */

            /*
            (CAN056) Post-Build configuration elements that are marked as 'm ultiple' ('M' or 'x') can be selected by passing
                       the pointer 'Config' to the init function of the module..
            */
#if (CAN_PRECOMPILE_SUPPORT == STD_OFF)
    #if (CAN_DEV_ERROR_DETECT == STD_ON)
            if ( NULL_PTR == Config )
            {
                /*
                (CAN175) If development error detection for the Can module is enabled: The function Can_Init shall raise the
                           error CAN_E_PARAM_POINTER if a NULL pointer was given as config parameter.
                */
                Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_INIT, (uint8)CAN_E_PARAM_POINTER);
            }
            else
            {
    #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

                /* Copy pointer to current Can Driver configuration. */
                Can_CurrentConfigPtr = Config;
                Can_ControlerDescriptorsPtr = Config->ControlerDescriptors;
#endif /* #if (CAN_PRECOMPILE_SUPPORT == STD_OFF) */

                    /* Initialisation of usefull indicators. */
                    Can_LLD_InitVariables();

                    /* Loop through all Can controllers configured based CanControllerId parameter. */
                    for ( can_controller = 0U; can_controller < (uint8)Can_CurrentConfigPtr->Can_ControllersConfigured; can_controller++)
                    {
                        /* The initialization is skipped for the controllers that are not enabled. */
                        /* @violates @ref Can_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        if ( FLEXCAN_NULL_OFFSET != (Can_ControlerDescriptorsPtr[can_controller].ControllerOffset))
                        {
                            /* Init - ControllerState, FirstHrhIndex, HthOffset, DefaultConfigIndex, MaxMBCount, CanWakeupSourceID, Freeze controller and more ... */
                            /*
                               (CAN239) The function Can_Init shall initialize all on-chip hardware resources that are used by the CAN controller.
                            */
                            Can_LLD_Init( can_controller);

                            /*
                                (CAN250) The function Can_Init shall initialize: static variables, including flags, Common setting for the
                                       complete CAN HW unit, CAN controller specific settings for each CAN controller.
                               (CAN245) The function Can_Init shall initialize all CAN controllers according to their configuration.
                               (CAN053) Can module/controller initalization - registers of CAN controller hardware resources that are not used.
                            */
                            Can_LLD_ChangeBaudrate( can_controller);
                        }
                    }
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                /*
                  (CAN246) After initializing all controllers inside the HW Unit, the function Can_Init shall change the module state to CAN_READY.
                */
                Can_DriverStatus = CAN_READY;
    #if (CAN_PRECOMPILE_SUPPORT == STD_OFF)
            }
    #endif /* # CAN_PRECOMPILE_SUPPORT */
        }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

    }

#if (CAN_CHANGE_BAUDRATE_API == STD_ON)
/*================================================================================================*/
/**
* @brief          Initialize the CAN controllers baudrate. SID = 0x0D.
* @details        Initialize the controller based on ID input parameter.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller Can controller to be initialized - based on configuration order list (CanControllerId).
* @param[in]      Baudrate Baudrate for which the controller shall be initialised.
*
* @retval         E_OK  request to change the Baudrate accepted.
* @retval         E_NOT_OK  request to change the Baudrate not accepted.
*
* @api
*
* @pre            Before controller re-initalization of baudrate the driver must be initialized and the controllers must be in Stop state.
* @post           Interrupts and MBs must be configured for respond to CAN bus.
*
* @implements     DCAN01020, DCAN01021, DCAN01022, DCAN01023, DCAN01024, DCAN01025, DCAN01026, DCAN01027, DCAN02905
*
* @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static
*/
FUNC (Std_ReturnType, CAN_CODE) Can_ChangeBaudrate( VAR(uint8, AUTOMATIC) Controller,
                                                    CONST(uint16, CAN_CONST) Baudrate)
    {
        VAR(Std_ReturnType, AUTOMATIC) Out_can_return = (uint8)E_NOT_OK;
        VAR(uint8, AUTOMATIC) ApiId = (uint8)0x0D;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* If Can_DriverStatus is CAN_UNINIT then the driver was not initialised yet. */
        if ( CAN_UNINIT == Can_DriverStatus )
        {
            /*
               (CAN450) If development error detection for the Can module is enabled: The function Can_ChangeBaudrate shall raise the
                       error CAN_E_UNINIT if the driver is not yet initialized.
            */
            Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_CHANGE_BAUDRATE, (uint8)CAN_E_UNINIT);
        }
        else
        {
            /* The Controller ID must be within range and the selected controller must be configured for use in the config tool. */

            if ( (Controller >= (uint8)Can_CurrentConfigPtr->Can_ControllersConfigured) ||
            /* @violates @ref Can_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                 (FLEXCAN_NULL_OFFSET == (Can_ControlerDescriptorsPtr[Controller].ControllerOffset)) )
            {
                /*
                   (CAN452) If development error detection for the Can module is enabled: The function Can_ChangeBaudrate shall raise the
                           error CAN_E_PARAM_CONTROLLER if the parameter Controller is out of range.
                */
                Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_CHANGE_BAUDRATE, (uint8)CAN_E_PARAM_CONTROLLER);
            }
            else
            {
                    if ( CAN_STOPPED != Can_ControllerStatuses[Controller].ControllerState )
                    {
                        /*
                          (CAN453) If development error detection for the Can module is enabled: if the controller is not in state CANIF_CS_STOPPED,
                                   the function Can_ChangeBaudrate shall raise the error CAN_E_TRANSITION.
                           (CAN256) The Can module environment shall only call Can_ChangeBaudrate when the CAN controller is in state CANIF_CS_STOPPED.
                        */
                        Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_CHANGE_BAUDRATE, (uint8)CAN_E_TRANSITION);
                    }
                    else
                    {
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                            /* Check the Baudrate */
                            if ( (uint8)E_OK != Can_LLD_CheckBaudrate( Controller, Baudrate, ApiId) )
                            {
                                #if (CAN_DEV_ERROR_DETECT == STD_ON)
                                /*
                                   (CAN451) If development error detection for the Can module is enabled: The function Can_ChangeBaudrate shall raise
                                           the error CAN_E_PARAM_BAUDRATE if the parameter Baudrate has an invalid value.
                                */
                                Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_CHANGE_BAUDRATE, (uint8)CAN_E_PARAM_BAUDRATE);
                                #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                            }
                            else
                            {
                                /*
                                  (CAN062) The function Can_ChangeBaudrate shall re-initialize the CAN controller and the controller specific settings.
                                   (CAN255) The function Can_ChangeBaudrate shall only affect register areas that contain specific configuration for a single CAN controller.
                                */
                                Can_LLD_ChangeBaudrate( Controller);
                                Out_can_return = (uint8)E_OK;
                            }
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                    }
            }
        }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        return (Out_can_return);
    }

/*================================================================================================*/
/**
* @brief          Check the CAN controllers Baudrate. SID = 0x0E.
* @details        Check the controller's configured baudrate.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller Can controller to be initialized - based on configuration order list (CanControllerId).
* @param[in]      Baudrate Baudrate for which the controller shall be initialised.
*
* @retval         E_OK  Baudrate is configred for the controller.
* @retval         E_NOT_OK  Baudrate is not configured for the controller.
*
* @api
*
* @pre            Before controller re-initalization the driver must be initialized.
* @post           Interrupts and MBs must be configured for respond to CAN bus.
*
* @implements     DCAN02906, DCAN02907, DCAN02908, DCAN02909
*
* @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static
*/
FUNC (Std_ReturnType, CAN_CODE) Can_CheckBaudrate( VAR(uint8, AUTOMATIC) Controller,
                                                   CONST(uint16, CAN_CONST) Baudrate)
    {
        VAR(Std_ReturnType, AUTOMATIC) Out_can_return = (uint8)E_NOT_OK;
        VAR(uint8, AUTOMATIC) ApiId = (uint8)0x0E;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* If Can_DriverStatus is CAN_UNINIT then the driver was not initialised yet. */
        if ( CAN_UNINIT == Can_DriverStatus )
        {
            /*
               (CAN456) If development error detection for the Can module is enabled: The function Can_CheckBaudrate shall raise the
                       error CAN_E_UNINIT if the driver is not yet initialized.
            */
            Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_CHECK_BAUDRATE, (uint8)CAN_E_UNINIT);
        }
        else
        {
            /* The Controller ID must be within range and the selected controller must be configured for use in the config tool. */

            if ( (Controller >= (uint8)Can_CurrentConfigPtr->Can_ControllersConfigured) ||
            /* @violates @ref Can_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                 (FLEXCAN_NULL_OFFSET == (Can_ControlerDescriptorsPtr[Controller].ControllerOffset)) )
            {
                /*
                   (CAN457) If development error detection for the Can module is enabled: The function Can_CheckBaudrate shall raise the
                           error CAN_E_PARAM_CONTROLLER if the parameter Controller is out of range.
                */
                Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_CHECK_BAUDRATE, (uint8)CAN_E_PARAM_CONTROLLER);
            }
            else
            {
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                    /* Check the Baudrate */
                    if ( (uint8)E_OK != Can_LLD_CheckBaudrate( Controller, Baudrate, ApiId) )
                    {
                        /* Invalid Baudrate */
                        #if (CAN_DEV_ERROR_DETECT == STD_ON)
                        /*
                           (CAN458) If development error detection for the Can module is enabled: The function Can_CheckBaudrate shall raise
                                   the error CAN_E_PARAM_BAUDRATE if the parameter Baudrate has an invalid value.
                        */
                        Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_CHECK_BAUDRATE, (uint8)CAN_E_PARAM_BAUDRATE);
                        #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                    }
                    else
                    {
                        /* Valid Baudrate */
                        Out_can_return = (uint8)E_OK;
                    }
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        return (Out_can_return);
    }
#endif /* (CAN_CHANGE_BAUDRATE_API == STD_ON) */

/*================================================================================================*/
/**
* @brief          Put the controller into a required state. SID = 0x03.
* @details        Switch the controller from one state to another.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller - Can controller for which the status shall be changed - based on configuration order list (CanControllerId).
* @param[in]      Transition - Possible transitions (CAN_T_STOP / CAN_T_START / CAN_T_SLEEP / CAN_T_WAKEUP)
* @return         Can_ReturnType  Result of the transition.
* @retval         CAN_OK   Transition initiated.
* @retval         CAN_NOT_OK  Development or production error.
*
* @api
*
* @pre            Before changing the controller state the driver must be initialized.
* @post           After the transition to the new state the interrupts required for that state must be enebaled.
*
* @implements     DCAN01028, DCAN01029, DCAN01030, DCAN01031, DCAN01032
*
* @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static
*/
FUNC (Can_ReturnType, CAN_CODE) Can_SetControllerMode( VAR(uint8, AUTOMATIC) Controller,
                                                       VAR(Can_StateTransitionType, AUTOMATIC) Transition )
    {

        /* Returns the result of transition mode. */
        VAR(Can_ReturnType, AUTOMATIC)  Out_can_return = CAN_NOT_OK;

        /*
           (CAN089) The Can module environment shall indicate development errors only in the return values of a function of the Can module when DET
                   is switched on and the function provides a return value. The returned value is CAN_NOT_OK.
        */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* If Can_CurrentConfigPtr is NULL_PTR then the Driver was not initialised yet. */
        if ( CAN_UNINIT == Can_DriverStatus )
        {
            /*
               (CAN198) If development error detection for the Can module is enabled: if the module is not yet initialized, the
                       function Can_SetControllerMode shall raise development error CAN_E_UNINIT and return CAN_NOT_OK.
            */
            Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_E_UNINIT);
        }
        else
        {
            /* Controller ID must be within range and the selected Controller must be configured for use in the config tool. */

            if ( (Controller >= (uint8)Can_CurrentConfigPtr->Can_ControllersConfigured) ||
            /* @violates @ref Can_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                 (FLEXCAN_NULL_OFFSET == (Can_ControlerDescriptorsPtr[Controller].ControllerOffset)) )
            {
                /*
                   (CAN199) If development error detection for the Can module is enabled: if the parameter Controller is out of range,
                           the function Can_SetControllerMode shall raise development error CAN_E_PARAM_CONTROLLER and return CAN_NOT_OK.
                */
                Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_SET_CONTROLLER_MODE, (uint8)CAN_E_PARAM_CONTROLLER);
            }
            else
            {
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                /* Call the LLD function for transition execution. */
                /* @violates @ref Can_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                Out_can_return = Can_LLD_SetControllerMode( Controller, &(Can_CurrentConfigPtr->ControlerDescriptors[Controller]), Transition, (boolean)TRUE);
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        }
#endif /* (CAN_DEV_ERROR_DETECT==STD_ON)  */

        return (Out_can_return);
    }


/*================================================================================================*/
/**
* @brief          Disable INTs. SID = 0x04.
* @details        Switch OFF the controller's interrupts.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller Can controller for which interrupts shall be disabled - based on configuration order list (CanControllerId).
*
* @return         void
*
* @api
*
* @pre            Driver must be initalzied before changing the interrupts state (en/dis).
* @post           Controller must not respond to any interrupt assertion.
*
* @implements     DCAN01033, DCAN01034, DCAN01035
*
* @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static
*/
FUNC (void, CAN_CODE) Can_DisableControllerInterrupts( VAR(uint8, AUTOMATIC) Controller)
    {

#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* If Can_CurrentConfigPtr is NULL_PTR then the driver was not initialised yet. */
        if ( CAN_UNINIT == Can_DriverStatus )
        {
            /*
               (CAN205) If development error detection for the Can module is enabled: The function Can_DisableControllerInterrupts shall
                       raise the error CAN_E_UNINIT if the driver not yet initialized.
            */
            Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_DISABLE_CONTROLLER_INTERRUPTS, (uint8)CAN_E_UNINIT);
        }
        else
        {
            /* The Controller ID must be within range and the selected Controller must be configured for use in the config tool. */

            if ( (Controller >= (uint8)Can_CurrentConfigPtr->Can_ControllersConfigured) ||
             /* @violates @ref Can_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                 (FLEXCAN_NULL_OFFSET == (Can_ControlerDescriptorsPtr[Controller].ControllerOffset)) )
            {
                /*
                   (CAN206) If development error detection for the Can module is enabled: The function Can_DisableControllerInterrupts shall
                           raise the error CAN_E_PARAM_CONTROLLER if the parameter Controller is out of range.
                */
                Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_DISABLE_CONTROLLER_INTERRUPTS, (uint8)CAN_E_PARAM_CONTROLLER);
            }
            else
            {
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                /* Call the LLD function for disabling interrupts. */
                /* @violates @ref Can_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                Can_LLD_DisableControllerInterrupts( Controller, &(Can_CurrentConfigPtr->ControlerDescriptors[Controller]));
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    }


/*================================================================================================*/
/**
* @brief          Enable INTs. SID = 0x05.
* @details        Switch ON the controller's interrupts.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller Can controller for which interrupts shall be disabled - based on configuration order list (CanControllerId).
*
* @return         void
*
* @api
*
* @pre            Driver must be initalzied before changing the interrupts state (en/dis).
* @post           Controller must respond to interrupt assertion.
*
* @implements     DCAN01036, DCAN01037, DCAN01038
 * @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static
*/
FUNC (void, CAN_CODE) Can_EnableControllerInterrupts( VAR(uint8, AUTOMATIC) Controller)
    {

#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* If Can_CurrentConfigPtr is NULL_PTR then the driver was not initialised yet. */
        if ( CAN_UNINIT == Can_DriverStatus )
        {
            /*
               (CAN209) If development error detection for the Can module is enabled: The function Can_EnableControllerInterrupts shall raise
                       the error CAN_E_UNINIT if the driver not yet initialized.
            */
            Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_ENABLE_CONTROLLER_INTERRUPTS, (uint8)CAN_E_UNINIT);
        }
        else
        {
            /* Controller ID must be within range and the selected Controller must be configured for use in the config tool. */

            if ( (Controller >= (uint8)Can_CurrentConfigPtr->Can_ControllersConfigured) ||
             /* @violates @ref Can_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                 (FLEXCAN_NULL_OFFSET == (Can_ControlerDescriptorsPtr[Controller].ControllerOffset)) )
            {
                /*
                   (CAN210) If development error detection for the Can module is enabled: The function Can_EnableControllerInterrupts shall
                           raise the error CAN_E_PARAM_CONTROLLER if the parameter Controller is out of range.
                */
                Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_ENABLE_CONTROLLER_INTERRUPTS, (uint8)CAN_E_PARAM_CONTROLLER);
            }
            else
            {
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                /* Call the LLD function for enabling interrupts. */
                /* @violates @ref Can_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used  */
                Can_LLD_EnableControllerInterrupts( Controller, &(Can_CurrentConfigPtr->ControlerDescriptors[Controller]));
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    }


/*================================================================================================*/
/**
* @brief          Transmit information on CAN bus. SID = 0x06.
* @details        Can_Write checks if hardware transmit object that is identified by the HTH is free.
*                    Can_Write checks if another Can_Write is ongoing for the same HTH.
*                     a) hardware transmit object is free:
*                         The mutex for that HTH is set to 'signaled' the ID, DLC and SDU are put in a format appropriate for
*                           the hardware (if necessary) and copied in the appropriate hardware registers/buffers.
*                        All necessary control operations to initiate the transmit are done.
*                         The mutex for that HTH is released. The function returns with CAN_OK.
*                    b) hardware transmit object is busy with another transmit request.
*                         The function returns with CAN_BUSY.
*                     c) A preemptive call of Can_Write has been issued, that could not be handled reentrant (i.e. a call with the same HTH).
*                        The function returns with CAN_BUSY the function is non blocking
*                     d) The hardware transmit object is busy with another transmit request for an L-PDU that has lower priority than that for the current request
*                        The transmission of the previous L-PDU is cancelled (asynchronously).
*                        The function returns with CAN_BUSY.
*                   This routine is called by:
*                   - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Hth Information which HW-transmit handle shall be used for transmit.
*                 Implicitly this is also the information about the controller to use because the Hth numbers are unique inside one hardware unit.
* @param[in]      PduInfo Pointer to SDU user memory, DLC and Identifier.
* @return         Can_ReturnType   Result of the write operation.
* @retval         CAN_OK   Write command has been accepted.
* @retval         CAN_NOT_OK  Development error occured.
* @retval         CAN_BUSY   No of TX hardware buffer available or preemtive call of Can_Write() that can't be implemented reentrant.
*
* @api
*
* @pre            Driver must be initialized and MB must be configured for Tx.
* @post           The data can be transmitted or rejected because of another data with a higher priority.
*
* @implements     DCAN01039, DCAN01040, DCAN01041, DCAN01042, DCAN01043
*
* @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static
*/
FUNC (Can_ReturnType, CAN_CODE) Can_Write( VAR(Can_HwHandleType, AUTOMATIC) Hth,
                                           P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_CONST) PduInfo )
    {

        /* Variable for return status */
        VAR(Can_ReturnType, AUTOMATIC)  Out_can_return = CAN_NOT_OK;


#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* If Can_CurrentConfigPtr is NULL_PTR then the driver was not initialised yet. */
        if ( CAN_UNINIT == Can_DriverStatus )
        {
            /*
               (CAN216) If development error detection for the Can module is enabled: The function Can_Write shall raise the error CAN_E_UNINIT if
                       the driver not yet initialized.
            */
            Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_WRITE, (uint8)CAN_E_UNINIT);
            Out_can_return = CAN_NOT_OK;
        }
        else
        {
            /* Hth must be below MessageBufferConfigCount and should be a Tx MB type. */
            if ( (Hth >= Can_CurrentConfigPtr->Can_max_object_Id) ||
                 (CAN_TRANSMIT != (Can_ObjType)Can_CurrentConfigPtr->Can_ObjectType_Mapping[Hth]) )

            {
                /*
                   (CAN217) If development error detection for the Can module is enabled: The function Can_Write shall raise the error CAN_E_PARAM_HANDLE
                           if the parameter Hth is not a configured Hardware Transmit Handle.
                */
                Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_WRITE, (uint8)CAN_E_PARAM_HANDLE);
                Out_can_return = CAN_NOT_OK;
            }
            else
            {
                /* Report Error if Protocol Data Unit information pointer is NULL. */
                if ( (NULL_PTR == PduInfo) || (NULL_PTR == PduInfo->sdu) )
                {
                    /*
                       (CAN219) If development error detection for the Can module is enabled: The function Can_Write shall raise the
                               error CAN_E_PARAM_POINTER if the parameter PduInfo or the SDU pointer inside PduInfo is a null-pointer.
                     */
                    Det_ReportError ( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_WRITE, CAN_E_PARAM_POINTER);
                    Out_can_return = CAN_NOT_OK;
                }
                else
                {
                    /* Report error if length > 8 bytes. */
                    if ( (PduInfo->length) > FLEXCAN_MB_DATABYTES )
                    {
                        /*
                           (CAN218) If development error detection for the Can module is enabled: The function Can_Write shall raise the
                                   error CAN_E_PARAM_DLC if the length is more than 8 byte.
                        */
                        Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_WRITE, (uint8)CAN_E_PARAM_DLC);
                        Out_can_return = CAN_NOT_OK;
                    }
                    else
                    {
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                        /* Call the LLD function for transmitting data. */
                        Out_can_return = Can_LLD_Write( Hth, PduInfo);
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                    }
                }
            }
        }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

        return (Out_can_return);
    }


/*================================================================================================*/
/**
* @brief          Function called at fixed cyclic time. SID 0x01.
* @details        Service for performs the polling of TX confirmation and TX cancellation confirmation when CAN_TX_PROCESSING is set to POLLING.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @api
*
* @pre            Driver must be initialized.
* @post           Send the data from that MB that is configured for Tx.
*
* @implements     DCAN01045, DCAN01046, DCAN01047, DCAN01062
*/
#if (CAN_TXPOLL_SUPPORTED == STD_ON)
/* @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (void, CAN_CODE) Can_MainFunction_Write( void)
{

    if ( NULL_PTR != Can_CurrentConfigPtr )
    {
        #if (CAN_DEV_ERROR_DETECT == STD_ON)
            /* Test whether the driver is already initialised. */
            if ( CAN_UNINIT == Can_DriverStatus )
            {
                /*
                   (CAN179) If development error detection for the module Can is enabled: The function Can_MainFunction_Write shall raise
                           the error CAN_E_UNINIT if the driver is not yet initialized.
                */
                Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_WRITE, (uint8)CAN_E_UNINIT);
            }
            else
            {
        #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                /* Poll all controllers for Tx MB statuses. */
                Can_LLD_MainFunction_Write();

        #if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    }
}

#endif /*(CAN_TXPOLL_SUPPORTED == STD_ON)   */


/*================================================================================================*/
/*
* @brief          Function called at fixed cyclic time.  SID = 0x08.
* @details        Service for performs the polling of RX indications when CAN_RX_PROCESSING is set to POLLING.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @api
*
* @pre            Driver must be initialized.
* @post           Receive the data from that MB that is configured for Rx.
*
* @implements     DCAN01048, DCAN01049, DCAN01050, DCAN01051, DCAN01134
*/
#if (CAN_RXPOLL_SUPPORTED  == STD_ON)
 /* @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (void, CAN_CODE) Can_MainFunction_Read( void)
{

    if ( NULL_PTR != Can_CurrentConfigPtr )
    {
        #if (CAN_DEV_ERROR_DETECT == STD_ON)
            /* Test whether the driver is already initialised. */
            if ( CAN_UNINIT == Can_DriverStatus )
            {
                /*
                   (CAN181) If development error detection for the Can module is enabled: The function Can_MainFunction_Read shall raise the
                           error CAN_E_UNINIT if the driver not yet initialized.
                */
                Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_UNINIT);
            }
            else
            {
        #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                /* Poll all controllers for Rx MB statuses. */
                Can_LLD_MainFunction_Read();

        #if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    }
}

#endif /* (CAN_RXPOLL_SUPPORTED == STD_ON) */


/*================================================================================================*/
/*
* @brief          Function called at fixed cyclic time. SID - 0x09.
* @details        Service for performs the polling of BusOff events that are configured statically as 'to be polled'.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @api
*
* @pre            Driver must be initialized.
* @post           Handle the Busoff event.
*
* @implements     DCAN01052, DCAN01053, DCAN01054, DCAN01055, DCAN01135
*/
#if (CAN_BUSOFFPOLL_SUPPORTED == STD_ON)
 /* @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (void, CAN_CODE) Can_MainFunction_BusOff( void)
{

    /* Variable for indexing the controllers */
    VAR(uint8, AUTOMATIC) can_controller = 0U;


    if ( NULL_PTR != Can_CurrentConfigPtr )
    {
        #if (CAN_DEV_ERROR_DETECT == STD_ON)
            /* Test whether the driver is already initialised. */
            if ( CAN_UNINIT == Can_DriverStatus )
            {
                /*
                   (CAN184) If development error detection for the Can module is enabled: The function Can_MainFunction_BusOff shall raise
                           the error CAN_E_UNINIT if the driver not yet initialized.
                */
                Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_BUS_OFF, (uint8)CAN_E_UNINIT);
            }
            else
            {
        #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

                /* Loop through all Can controllers configured based CanControllerId parameter. */
                for ( can_controller = (uint8)0U; can_controller < (uint8)Can_CurrentConfigPtr->Can_ControllersConfigured; can_controller++)
                {
                    /*
                       (CAN109) The function Can_MainFunction_BusOff shall perform the polling of bus-off events that are configured statically as 'to be polled'.
                    */
        /* @violates @ref Can_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    if ( (FLEXCAN_NULL_OFFSET !=(Can_ControlerDescriptorsPtr[can_controller].ControllerOffset))  &&
                    /* @violates @ref Can_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                         ((CAN_CONTROLLERCONFIG_BOPOL_EN & (uint32)(Can_ControlerDescriptorsPtr[can_controller].Options)) != (uint32)0x0U) )
                    {
                        /* Check for BusOff status. */
                        if ( (uint8)E_OK == Can_LLD_CheckBusOff(can_controller) )
                        {
                            /* Process BusOff event. */
                            Can_LLD_Process_BusOff( can_controller);
                        }
                    }
                }
        #if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    }
}

#endif /* (CAN_BUSOFFPOLL_SUPPORTED == STD_ON) */


/*================================================================================================*/
/**
* @brief          Function called at fixed cyclic time. SID = 0x0A.
* @details        Service for performs performs the polling of WakeUp events that are configured statically as 'to be polled'.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @api
*
* @pre            Driver must be initialized.
* @post           Handle the Wakeup event.
*
* @implements     DCAN01056, DCAN01057, DCAN01058, DCAN01059, DCAN01136
*/
#if ((CAN_WAKEUP_SUPPORT == STD_ON) && (CAN_WAKEUPPOLL_SUPPORTED == STD_ON))

FUNC (void, CAN_CODE) Can_MainFunction_Wakeup( void)
{

    /* Variable for indexing the controllers */
    VAR(uint8, AUTOMATIC) can_controller = 0U;


    if ( NULL_PTR != Can_CurrentConfigPtr )
    {
        #if (CAN_DEV_ERROR_DETECT == STD_ON)
            /* Test whether the driver is already initialised. */
            if ( CAN_UNINIT == Can_DriverStatus )
            {
                /*
                   (CAN186) If development error detection for the Can module is enabled: The function Can_MainFunction_Wakeup shall raise the error CAN_E_UNINIT if the driver not yet initialized.
                */
                Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_WAKEUP, (uint8)CAN_E_UNINIT);
            }
            else
            {
        #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

                /* Loop through all Can controllers configured based CanControllerId parameter. */
                for ( can_controller = (uint8)0U; can_controller < (uint8)Can_CurrentConfigPtr->Can_ControllersConfigured; can_controller++)
                {
                    /*
                       (CAN112) The function Can_MainFunction_Wakeup shall perform the polling of wake-up events that are configured
                               statically as 'to be polled'.
                    */
                    if ( (FLEXCAN_NULL_OFFSET != (Can_ControlerDescriptorsPtr[can_controller].ControllerOffset)) &&
                          ((CAN_CONTROLLERCONFIG_WAKSUP_EN & (uint32)(Can_ControlerDescriptorsPtr[can_controller].Options)) != (uint32)0x0U) &&
                         ((CAN_CONTROLLERCONFIG_WKPOL_EN & (uint32)(Can_ControlerDescriptorsPtr[can_controller].Options)) != (uint32)0x0U) )
                    {
                        /* Check for wake up condition. */
                        if ( (uint8)E_OK == Can_LLD_CheckWakeup( can_controller) )
                        {
                            /* Process Wakeup event. */
                            Can_LLD_Process_Wakeup( can_controller);
                        }
                    }
                }

        #if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    }
}

#endif /* ((CAN_WAKEUP_SUPPORT == STD_ON) && (CAN_WAKEUPPOLL_SUPPORTED == STD_ON)) */

/*================================================================================================*/
/**
* @brief          Function called at fixed cyclic time. SID = 0x0C.
* @details        Service for performs performs the polling of CAN status register flags to detect transition of CAN Controller state
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @api
*
* @pre            Driver must be initialized.
* @post           Handle the transition of Can Controller state.
*
* @implements     DCAN01060, DCAN01061, DCAN01063, DCAN01064, DCAN01137
* @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static
*/

FUNC (void, CAN_CODE) Can_MainFunction_Mode( void)
{

    if(NULL_PTR != Can_CurrentConfigPtr)
    {
        #if (CAN_DEV_ERROR_DETECT == STD_ON)
            /* Test whether the driver is already initialised. */
            if ( CAN_UNINIT == Can_DriverStatus )
            {
                /*
                   (CAN379) If development error detection for the Can module is enabled: The function Can_MainFunction_Mode shall raise the error CAN_E_UNINIT if the driver is not yet initialized.
                */
                Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_MODE, (uint8)CAN_E_UNINIT);
            }
            else
            {
        #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

                /* Check for wake up condition. */
                Can_LLD_MainFunction_Mode();

        #if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    }
}


/*================================================================================================*/
/**
* @brief          Process check of WakeUp condition. SID = 0x0B.
* @details        This service shall evaluate the WakeupSource parameter to get the information,
*                 which dedicate wakeup source needs to be checked, either a CAN transceiver or controller device.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      controller Can controller ID - based on configuration order list (CanControllerId).
* @return         Std_ReturnType Result of the wakeup verification.
* @retval         E_OK  Wakeup was detected for the given controller.
* @retval         E_NOT_OK  No wakeup was detected for the given controller.
*
* @api
*
* @pre            Driver must be initialized.
* @post           Return the Wakeup event occurence.
*
* @implements     DCAN01065, DCAN01066, DCAN01067, DCAN01064
*
*/
/* @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (Can_ReturnType, CAN_CODE) Can_CheckWakeup( VAR(uint8, AUTOMATIC) controller)
    {

        /* E_NOT_OK is defined as (uint8)0x01 */
        VAR(Can_ReturnType, AUTOMATIC) Out_can_return = CAN_NOT_OK;


    #if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Test whether the driver is already initialised. */
        if ( CAN_UNINIT == Can_DriverStatus )
        {
            /*
               (CAN362) If development error detection for the Can module is enabled: The function Can_CheckWakeup shall raise
                       the error CAN_E_UNINIT if the driver is not yet initialized.
            */
            Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_CBK_CHECK_WAKEUP, (uint8)CAN_E_UNINIT);
        }
        else
        {
            /*
               (CAN363) If development error detection for the Can module is enabled: The function Can_CheckWakeup shall raise the
                       error CAN_E_PARAM_CONTROLLER if the parameter Controller is out of range.
            */
            if ( (controller >= (uint8)Can_CurrentConfigPtr->Can_ControllersConfigured) ||
            /* @violates @ref Can_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                 (FLEXCAN_NULL_OFFSET == (Can_ControlerDescriptorsPtr[controller].ControllerOffset)) )
            {
                Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_CBK_CHECK_WAKEUP, (uint8)CAN_E_PARAM_CONTROLLER);
            }
            else
            {
    #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

                /* Call LLD function for checking wakeup status. */
                Out_can_return = (Can_ReturnType)Can_LLD_CheckWakeup( controller);
    #if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        }
    #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

        return (Out_can_return);
    }



/*================================================================================================*/
/*
* @brief          Process a message buffer abort
* @details        This function write a abort code (b'1001) to MBCS[CODE] field of the MB.
*                This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Hth - HW-transmit handler
*
* @api
*
* @pre            Driver must be initialized and the current MB transmission should be ready for transmit.
*
* @implements     DCAN01068
*
* @note           Not AUTOSAR required. This is user implementation.
*
*/
#if ((CAN_API_ENABLE_ABORT_MB == STD_ON) && (CAN_HW_TRANSMIT_CANCELLATION == STD_ON))
 /* @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC(void, CAN_CODE) Can_AbortMb( VAR(Can_HwHandleType, AUTOMATIC) Hth )
    {

#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Test if the driver is already initialised. */
        if ( CAN_UNINIT == Can_DriverStatus )
        {
            Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_ABORT_MB, (uint8)CAN_E_UNINIT);
        }
        else
        {
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

            Can_LLD_AbortMb(Hth);

#if (CAN_DEV_ERROR_DETECT == STD_ON)
        }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

    }

#endif /* ((CAN_API_ENABLE_ABORT_MB == STD_ON) && (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)) */



/*================================================================================================*/
/*
* @brief          Process a transition from one clock source to another.
* @details        This function is configuring Can controllers to run on the same baudrate, but having a different MCU source clock.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      can_controller controller ID
* @param[in]      can_clk_mode clock mode selection
* @return         Std_ReturnType Result of the clock switch operation.
* @retval         E_OK  Switch clock operation was ok.
* @retval         E_NOT_OK  Switch clock operation was not ok.
*
* @api
*
* @pre            Driver must be initialized and all the controllers must be in Stop state.
*
* @implements     DCAN01133
*
* @note           Not AUTOSAR required. This is user implementation.
*
*/
#if (CAN_DUAL_CLOCK_MODE == STD_ON)
/* @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC(Std_ReturnType, CAN_CODE) Can_SetClockMode( VAR(uint8, AUTOMATIC) can_controller, VAR(Can_ClockMode, AUTOMATIC) can_clk_mode)
    {

        VAR(Std_ReturnType, AUTOMATIC) Out_can_return = (uint8)E_NOT_OK;

#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Test if the driver is already initialised. */
        if ( CAN_UNINIT == Can_DriverStatus )
        {
            Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_SETCLOCKMODE, (uint8)CAN_E_UNINIT);
        }
        else
        {
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

            if ( CAN_STOPPED == Can_ControllerStatuses[can_controller].ControllerState )
            {
                Out_can_return = Can_LLD_SetClockMode( can_controller, can_clk_mode);
            }

#if (CAN_DEV_ERROR_DETECT == STD_ON)
        }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

        return (Out_can_return);
    }

#endif /* CAN_DUAL_CLOCK_MODE == STD_ON */

#if (CAN_API_ERROR_STATUS == STD_ON)
/*================================================================================================*/
/*
* @brief         This function checks the error status and intimated to upper layer.
* @details       This routine is called by an upper layer.
* 
* @param[in]     controller CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* 
* @return        void
* 
* @pre           Driver must be initialized.
* @post          Inform CanIf about errorstatus .
* @notes         Not AUTOSAR required. This is user implementation.
*/
/*================================================================================================*/
/* @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (uint32, CAN_CODE) Can_GetErrorStatus( VAR(uint8, AUTOMATIC) can_controller)
    {
        /* Error status */
        VAR(uint32, AUTOMATIC) can_err_status = 0U;

#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Test if the driver is already initialised. */
        if ( CAN_UNINIT == Can_DriverStatus )
        {
            Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_GET_ERROR_STATUS, (uint8)CAN_E_UNINIT);
        }
        else
        {
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
            can_err_status = Can_LLD_GetErrorStatus( can_controller);

#if (CAN_DEV_ERROR_DETECT == STD_ON)
        }
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

        return can_err_status;
    }
#endif /* CAN_API_ERROR_STATUS == STD_ON */

#if ((defined CAN_API_TXCANCEL_CHECK) && (CAN_API_TXCANCEL_CHECK == STD_ON))
/*================================================================================================*/
/*
@brief         This function checks the transmit cancel confirmation when can driver used in
               interrupt mode or in Polling mode.
@details       This routine is called by an upper layer.

@param[in]     none
@param[out]     none

@return        void

@pre           Driver must be initialized.
@post          Inform CanIf about transmit cancel confirmation.
@notes         Not AUTOSAR required. This is user implementation.
*/
/*================================================================================================*/
/* @violates @ref Can_c_REF_5 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
FUNC (void, CAN_CODE) Can_CheckTxCancel(void)
{
    if ( NULL_PTR != Can_CurrentConfigPtr )
    {
        #if (CAN_DEV_ERROR_DETECT == STD_ON)
            /* Test whether the driver is already initialised. */
            if ( CAN_UNINIT == Can_DriverStatus )
            {
                /*
                   (CAN181) If development error detection for the Can module is enabled: The function Can_MainFunction_Read shall raise the
                           error CAN_E_UNINIT if the driver not yet initialized.
                */
                Det_ReportError( (uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_SID_MAIN_FUNCTION_READ, (uint8)CAN_E_UNINIT);
            }
            else
            {
        #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
                Can_LLD_CheckTxCancel();

        #if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        #endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    }
}
#endif /* CAN_API_TXCANCEL_CHECK == STD_ON */

#define CAN_STOP_SEC_CODE

/*
* @violates @ref Can_c_REF_1 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
* @violates @ref Can_c_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/

#include "MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
