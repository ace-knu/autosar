/**
*   @file    Wdg_Channel.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Wdg - contains the data exported by the watchodg module
*   @details Contains the information that will be exported by the module, as requested by Autosar.
*
*   @addtogroup  Wdg
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : Swt
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF12_ASR_REL_4_0_REV_0003_20161209
*
*   (c) Copyright 2006-2016 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef WDG_CHANNEL_H
#define WDG_CHANNEL_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Wdg_Channel_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 
* character significance and case sensitivity are supported for external identifiers.
* define name is required by the AUTOSAR specifications although it exceedes the max length of 31 characters.
*
* @section Wdg_Channel_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the contents 
* of a header file being included twice.
* Required by the Autosar specification.Needed for different code sections definition.
*
* @section Wdg_Channel_h_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Wdg_Channel_h_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "Mcal.h"
/*
* @violates @ref Wdg_Channel_h_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "WdgIf_Types.h"
/*
* @violates @ref Wdg_Channel_h_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "Wdg_Cfg.h"
#if (WDG_TYPE == WDG_EXTERNAL_MODULE_SPI)
    #include "Spi.h"
#elif(WDG_TYPE == WDG_EXTERNAL_MODULE_DIO)
    #include "Dio.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_CHANNEL_VENDOR_ID                    43
#define WDG_CHANNEL_MODULE_ID                    102
/* @violates @ref Wdg_Channel_h_REF_3 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION     4
/* @violates @ref Wdg_Channel_h_REF_3 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_CHANNEL_AR_RELEASE_MINOR_VERSION     0
/*
* @violates @ref Wdg_Channel_h_REF_1 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to 
* ensure that 31 character significance and case sensitivity are supported for external identifiers.
*/
/* @violates @ref Wdg_Channel_h_REF_3 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_CHANNEL_AR_RELEASE_REVISION_VERSION  3
#define WDG_CHANNEL_SW_MAJOR_VERSION             1
#define WDG_CHANNEL_SW_MINOR_VERSION             0
#define WDG_CHANNEL_SW_PATCH_VERSION             1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and WDG configuration header file are of the same vendor */
#if (WDG_CHANNEL_VENDOR_ID != WDG_VENDOR_ID_CFG)
    #error "Wdg_Channel.h and Wdg_Cfg.h have different vendor ids"
#endif

/* Check if current file and WDG configuration header file are of the same Autosar version */
#if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION    != WDG_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION    != WDG_AR_RELEASE_MINOR_VERSION_CFG) || \
     (WDG_CHANNEL_AR_RELEASE_REVISION_VERSION != WDG_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Wdg.h and Wdg_Cfg.h are different"
#endif

/* Check if current file and WDG configuration header file are of the same software version */
#if ((WDG_CHANNEL_SW_MAJOR_VERSION != WDG_SW_MAJOR_VERSION_CFG) || \
     (WDG_CHANNEL_SW_MINOR_VERSION != WDG_SW_MINOR_VERSION_CFG) || \
     (WDG_CHANNEL_SW_PATCH_VERSION != WDG_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Wdg.h and Wdg_Cfg.h are different"
#endif

/* Check if current file and Std_Types header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wdg.h and Std_Types.h are different"
    #endif
#endif

/* Check if source file and WDG external dependencies are of the same Autosar version */
#if (WDG_TYPE == WDG_EXTERNAL_MODULE_SPI)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        #if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION != SPI_AR_RELEASE_MAJOR_VERSION) || \
             (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION != SPI_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Wdg.h and Spi.h are different"
        #endif
    #endif
#elif (WDG_TYPE == WDG_EXTERNAL_MODULE_DIO)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        #if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION) || \
             (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Wdg.h and Dio.h are different"
        #endif
    #endif  
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

/**
* @brief  This enumerated type will contain the service ids for the watchodg functions
*
* @pre To define WDG_GETVERSION_ID, WDG_VERSION_INFO_API has to be equal to STD_ON
*
*/
enum
{
#if (WDG_VERSION_INFO_API == STD_ON) || defined(__DOXYGEN__)
    WDG_GETVERSION_ID           = 0x04, /*< @brief The service id for the Wdg_GetVersion function,
                                            used when using DET */
#endif
    WDG_INIT_ID                 = 0x00, /*< @brief The service id for the Wdg_Init function, used
                                            when using DET */
    WDG_SETMODE_ID              = 0x01, /*< @brief The service id for the Wdg_SetMode function, used
                                            when using DET */
    WDG_SETTRIGGERCONDITION_ID  = 0x02  /*< @brief The service id for the Wdg_SetTriggerCondition function, used
                                            when using DET */                                      
};

/**
* @brief  Indicates the aditional det errors used by the watchdog driver
*/
enum
{
    WDG_E_DRIVER_STATE  = 0x10, /*< @brief API service used in wrong context (e.g. driver not
                                            initialized) */
    WDG_E_PARAM_MODE,           /*< @brief = 0x11 API service called with wrong/inconsistent
                                                   parameter(s) */
    WDG_E_PARAM_CONFIG,         /*< @brief = 0x12 API service called with wrong/inconsistent
                                                   parameter(s) */
    WDG_E_PARAM_TIMEOUT,        /*< @brief = 0x13 The passed timeout value is higher than the 
                                                   maximum timeout value */  
    WDG_E_PARAM_POINTER         /*< @brief = 0x14 API is called with wrong pointer value 
                                                   (e.g. NULL pointer) */
};

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/*
* @violates @ref Wdg_Channel_h_REF_3 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define WDG_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Wdg_Channel_h_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "MemMap.h"

extern VAR(WdgIf_ModeType, WDG_VAR) Wdg_Current_Mode[WDG_NO_OF_INSTANCES];
extern P2CONST(Wdg_ConfigType, WDG_VAR, WDG_APPL_CONST) Wdg_ConfigPtr[WDG_NO_OF_INSTANCES];
/*
* @violates @ref Wdg_Channel_h_REF_3 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Wdg_Channel_h_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "MemMap.h"


/*
* @violates @ref Wdg_Channel_h_REF_3 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Wdg_Channel_h_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "MemMap.h"
/* @brief  Import extern declarations of WDG configuration from Wdg_Cfg.h */
WDG_CFG_EXTERN_DECLARATIONS
/*
* @violates @ref Wdg_Channel_h_REF_3 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Wdg_Channel_h_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else 
#define WDG_START_SEC_RAMCODE
#endif

/*
* @violates @ref Wdg_Channel_h_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "MemMap.h"

FUNC(void, WDG_CODE) Wdg_ChannelInit(P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr,
                                                   CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance);

FUNC(Std_ReturnType, WDG_CODE) Wdg_ChannelSetMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode,
                                                   CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance);

FUNC(void, WDG_CODE) Wdg_ChannelSetTriggerCondition (VAR(uint16, AUTOMATIC) Timeout,
                                                   CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance);

#if (WDG_VERSION_INFO_API == STD_ON) || defined(__DOXYGEN__)
FUNC(void, WDG_CODE) Wdg_ChannelGetVersionInfo
        (P2VAR(Std_VersionInfoType, AUTOMATIC, WDG_APPL_DATA) versioninfo,
         CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance);

#endif /* WDG_VERSION_INFO_API == STD_ON */

#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else 
#define WDG_STOP_SEC_RAMCODE
#endif

/*
* @violates @ref Wdg_Channel_h_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* WDG_CHANNEL_H */

/** @} */
