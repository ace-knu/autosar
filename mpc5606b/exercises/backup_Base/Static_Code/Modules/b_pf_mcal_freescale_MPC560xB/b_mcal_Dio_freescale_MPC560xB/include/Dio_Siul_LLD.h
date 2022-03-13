/**
*   @file    Dio_Siul_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Dio SIUL low level SIUL header.
*   @details This file is the SIUL DIO low level driver header.
*
*   @addtogroup SIUL_DIO
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
===================================================================================================*/

#ifndef SIUL_DIO_LLD_H
#define SIUL_DIO_LLD_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Dio_Siul_H_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
*          order to prevent the contents of a header file being included twice.
*          Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section Dio_Siul_H_REF_2
*          Violates MISRA 2004 Required Rule 5.1,
*          Identifiers (internal and external) shall not rely on the significance of more than 31
*          characters. 
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SIUL_DIO_VENDOR_ID_LLD                    43
/*
* @violates @ref Dio_Siul_H_REF_2 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define SIUL_DIO_AR_RELEASE_MAJOR_VERSION_LLD     4
/*
* @violates @ref Dio_Siul_H_REF_2 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define SIUL_DIO_AR_RELEASE_MINOR_VERSION_LLD     0
/*
* @violates @ref Dio_Siul_H_REF_2 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define SIUL_DIO_AR_RELEASE_REVISION_VERSION_LLD  3
#define SIUL_DIO_SW_MAJOR_VERSION_LLD             1
#define SIUL_DIO_SW_MINOR_VERSION_LLD             0
#define SIUL_DIO_SW_PATCH_VERSION_LLD             1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

#define DIO_PORTID_SHIFT                    ((uint32)2UL)

#define DIO_CHANNELGRP_OFFSET_PINS          ((uint32)0x0000FFFFUL)

#define DIO_CHANNELGRP_MASK_PINS            ((uint32)16UL)

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

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define DIO_START_SEC_CODE
/**
* @violates @ref Dio_Siul_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

FUNC(Dio_LevelType, DIO_CODE) Dio_SIUL_ReadChannel
(
    CONST(Dio_ChannelType, DIO_CONST) ChannelId
);

FUNC(void, DIO_CODE) Dio_SIUL_WriteChannel
(
    CONST(Dio_ChannelType, DIO_CONST) ChannelId,
    CONST(Dio_LevelType, DIO_CONST) Level
);

#if DIO_FLIP_CHANNEL_API == STD_ON
FUNC(Dio_LevelType, DIO_CODE) Dio_SIUL_FlipChannel
(
    CONST(Dio_ChannelType, DIO_CONST) ChannelId
);
#endif /* DIO_FLIP_CHANNEL_API */

FUNC(Dio_PortLevelType, DIO_CODE) Dio_SIUL_ReadPort
(
    CONST(Dio_PortType, DIO_CONST) PortId
);

FUNC(void, DIO_CODE) Dio_SIUL_WritePort
(
    CONST(Dio_PortType, DIO_CONST) PortId,
    CONST(Dio_PortLevelType, DIO_CONST) Level
);

FUNC(Dio_PortLevelType, DIO_CODE) Dio_SIUL_ReadChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr
);

FUNC(void, DIO_CODE) Dio_SIUL_WriteChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr,
    CONST(Dio_PortLevelType, DIO_CONST) Level
);

#if DIO_MASKEDWRITEPORT_API == STD_ON
FUNC(void, DIO_CODE) Dio_SIUL_MaskedWritePort
(
    CONST(Dio_PortType, DIO_CONST) PortId,
    CONST(Dio_PortLevelType, DIO_CONST) Level,
    CONST(Dio_PortLevelType, DIO_CONST) Mask
);
#endif /* DIO_MASKEDWRITEPORT_API */

#define DIO_STOP_SEC_CODE
/**
* @violates @ref Dio_Siul_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* SIUL_DIO_LLD_H */

/** @} */
