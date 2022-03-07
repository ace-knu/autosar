/**
*   @file    Dio.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Dio high level header.
*   @details This file is the Autosar DIO driver high level header.
*
*   @addtogroup DIO_HLD
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : SIUL
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

#ifndef DIO_H
#define DIO_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Dio_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Dio_H_REF_2
* Violates MISRA 2004 Required Rule 12.5, The operands of a logic && or || shall be primary-expressions
* This is necessary to simplify the code structure and easier readability. 
*
* @section Dio_H_REF_4
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*
* @section Dio_H_REF_5
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only 
* accessed from within a single function.
*
*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define DIO_VENDOR_ID                    43
#define DIO_MODULE_ID                    120
#define DIO_AR_RELEASE_MAJOR_VERSION     4
#define DIO_AR_RELEASE_MINOR_VERSION     0
#define DIO_AR_RELEASE_REVISION_VERSION  3
#define DIO_SW_MAJOR_VERSION             1
#define DIO_SW_MINOR_VERSION             0
#define DIO_SW_PATCH_VERSION             1

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*
* @implements     DDIO00003.
*/
#include "Std_Types.h"

#include "Mcal.h"
#include "Dio_LLD.h"

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((DIO_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (DIO_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Dio.h and Std_Types.h are different"
    #endif
#endif

/* @implements    DDIO03009.*/
/* Check if current file and DIO configuration header file are of the same vendor.*/
#if (DIO_VENDOR_ID != DIO_VENDOR_ID_CFG)
#error "Dio.h and Dio_Cfg.h have different vendor ids"
#endif

/* Check if current file and DIO configuration header file are of the same Autosar version.*/
#if ((DIO_AR_RELEASE_MAJOR_VERSION    != DIO_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (DIO_AR_RELEASE_MINOR_VERSION    != DIO_AR_RELEASE_MINOR_VERSION_CFG) || \
     (DIO_AR_RELEASE_REVISION_VERSION != DIO_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Dio.h and Dio_Cfg.h are different"
#endif

/* Check if current file and DIO configuration header file are of the same software version.*/
#if ((DIO_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION_CFG) || \
     (DIO_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION_CFG) || \
     (DIO_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Dio.h and Dio_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/**
* @brief          Invalid channel name requested.
*
* @implements     DDIO03013, DDIO03014.
*
* @api
*/
#define DIO_E_PARAM_INVALID_CHANNEL_ID          ((uint8)0x0A)


/**
* @brief          API service called with "NULL pointer" parameter.
*
* @implements     DDIO03013, DDIO03015.
*
* @api
*/
#define DIO_E_PARAM_CONFIG                      ((uint8)0x10)

/**
* @brief          Invalid port name requested.
*
* @implements     DDIO03013, DDIO03016.
*
* @api
*/
#define DIO_E_PARAM_INVALID_PORT_ID             ((uint8)0x14)

/**
* @brief          Invalid ChannelGroup id passed.
*
* @implements     DDIO03013, DDIO03017.
*
* @api
*/
#define DIO_E_PARAM_INVALID_GROUP_ID            ((uint8)0x1F)

/**
* @brief          API service called with a NULL pointer.
* @details        In case of this error, the API service shall return
*                 immediately without any further action, beside reporting
*                 this development error.
*
* @implements     DDIO03013, DDIO03018.
*
* @api
*/
#define DIO_E_PARAM_POINTER                     ((uint8)0x20)

/**
* @brief          API service ID for @p Dio_Init() function.
* @details        Parameters used when raising an error/exception.
*
* @implements     DDIO03026.
*
* @api
*/
#define DIO_INIT_ID                             ((uint8)0x10)

/**
* @brief          API service ID for @p Dio_ReadChannel() function.
* @details        Parameters used when raising an error/exception.
*
* @implements     DDIO03019.
*
* @api
*/
#define DIO_READCHANNEL_ID                      ((uint8)0x00)

/**
* @brief          API service ID for @p Dio_WriteChannel() function.
* @details        Parameters used when raising an error/exception.
*
* @implements     DDIO03020.
*
* @api
*/
#define DIO_WRITECHANNEL_ID                     ((uint8)0x01)

/**
* @brief          API service ID for @p Dio_Init() function.
* @details        Parameters used when raising an error/exception.
*
* @implements     DDIO03027.
*
* @api
*/
#define DIO_FLIPCHANNEL_ID                      ((uint8)0x11)

/**
* @brief          API service ID for @p Dio_ReadPort() function.
* @details        Parameters used when raising an error/exception.
*
* @implements     DDIO03021.
*
* @api
*/
#define DIO_READPORT_ID                         ((uint8)0x02)

/**
* @brief          API service ID for @p Dio_WritePort() function.
* @details        Parameters used when raising an error/exception.
*
* @implements     DDIO03022.
*
* @api
*/
#define DIO_WRITEPORT_ID                        ((uint8)0x03)

/**
* @brief          API service ID for @p Dio_ReadChannel() Group function.
* @details        Parameters used when raising an error/exception.
*
* @implements     DDIO03023.
*
* @api
*/
#define DIO_READCHANNELGROUP_ID                 ((uint8)0x04)

/**
* @brief          API service ID for @p Dio_WriteChannel() Group function.
* @details        Parameters used when raising an error/exception.
*
* @implements     DDIO03024.
*
* @api
*/
#define DIO_WRITECHANNELGROUP_ID                ((uint8)0x05)

/**
* @brief          API service ID for DIO Get Version() Info function.
* @details        Parameters used when raising an error/exception.
*
* @implements     DDIO03025.
*
* @api
*/
#define DIO_GETVERSIONINFO_ID                   ((uint8)0x12)

/**
* @brief          API service ID for @p Dio_MaskedWritePort() function.
* @details        Parameters used when raising an error/exception.
*
* @implements     DDIO03028.
*
* @api
*
*/
#define DIO_MASKEDWRITEPORT_ID                  ((uint8)0x06)

/**
* @brief          Instance ID of the Dio driver.
*
* @implements     .
*
* @api
*/
#define DIO_INSTANCE_ID                         ((uint8)0x00)

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/* @violates @ref Dio_H_REF_2 The operands of a logic && or || */
#if !defined(DIO_PRECOMPILE_SUPPORT) || defined(__DOXYGEN__)
/*
* @violates @ref Dio_H_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define DIO_START_SEC_VAR_INIT_UNSPECIFIED
/* @implements  DDIO00004.*/
/*
* @violates @ref Dio_H_REF_1 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"
/*
* @violates @ref Dio_H_REF_5 Objects shall be defined at block scope if they are only 
* accessed from within a single function.
*/
extern P2CONST(Dio_ConfigType, DIO_VAR, DIO_APPL_CONST) Dio_CurrentConfigPtr;
/*
* @violates @ref Dio_H_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define DIO_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @implements  DDIO00004.*/
/*
* @violates @ref Dio_H_REF_1 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"
#endif /* !defined(DIO_PRECOMPILE_SUPPORT) */

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define DIO_START_SEC_CODE
/* @implements  DDIO00004.*/
/*
* @violates @ref Dio_H_REF_1 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

#if (DIO_DEV_ERROR_DETECT == STD_ON) || defined(__DOXYGEN__)
STATIC FUNC(uint8, DIO_CODE) invalid_pin
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
);

STATIC FUNC(uint8, DIO_CODE) invalid_port
(
    CONST(Dio_PortType, AUTOMATIC) PortId
);
#endif /* DIO_DEV_ERROR_DETECT == STD_ON */

FUNC(void, DIO_CODE)Dio_Init
(
    P2CONST(Dio_ConfigType, AUTOMATIC, DIO_APPL_CONST) ConfigPtr
);

#if DIO_VERSION_INFO_API == STD_ON
FUNC(void, DIO_CODE)Dio_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DIO_APPL_DATA) versioninfo
);
#endif /* DIO_VERSION_INFO_API == STD_ON */

FUNC(Dio_LevelType, DIO_CODE) Dio_ReadChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
);

FUNC(void, DIO_CODE) Dio_WriteChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId,
    CONST(Dio_LevelType, AUTOMATIC) Level
);

#if DIO_FLIP_CHANNEL_API == STD_ON
FUNC(Dio_LevelType, DIO_CODE) Dio_FlipChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
);
#endif /* DIO_FLIP_CHANNEL_API == STD_ON */

FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadPort
(
    CONST(Dio_PortType, AUTOMATIC) PortId
);

FUNC(void, DIO_CODE) Dio_WritePort
(
    CONST(Dio_PortType, AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level
);

FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadChannelGroup
(
  P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr
);

FUNC(void, DIO_CODE) Dio_WriteChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr,
    CONST(Dio_PortLevelType, AUTOMATIC) Level
);

#if DIO_MASKEDWRITEPORT_API == STD_ON
FUNC(void, DIO_CODE) Dio_MaskedWritePort
(
    CONST(Dio_PortType, AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level,
    CONST(Dio_PortLevelType, AUTOMATIC) Mask
);
#endif /* DIO_MASKEDWRITEPORT_API == STD_ON */

#define DIO_STOP_SEC_CODE
/* @implements  DDIO00004.*/
/*
* @violates @ref Dio_H_REF_1 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DIO_H */

/** @} */
