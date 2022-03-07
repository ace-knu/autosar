/**
*   @file    Dio_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Dio low level header.
*   @details This file is the DIO driver low level header.
*
*   @addtogroup DIO_LLD
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

#ifndef DIO_LLD_H
#define DIO_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section DIO_LLD_h_REF_1
*          Violates MISRA 2004 Advisory Rule 19.7,
*          A function shall be used in preference to a function-like macro.
*          Middle layer between AUTOSAR and hardware needs a way to map HLD
*          functions to LLD functions.
*
* @section DIO_LLD_h_REF_2
*          Violates MISRA 2004 Required Rule 1.4,
*          The compiler/linker shall be checked to ensure that 31 character signifiance and case
*          sensitivity are supported for external identifiers.
*          This violation is due to the requirement that requests to have a file version check.
*
* @section DIO_LLD_h_REF_3
*          Violates MISRA 2004 Required Rule 5.1,
*          Identifiers (internal and external) shall not rely on the significance of more than 31
*          characters.
*
* @section DIO_LLD_h_REF_4
*          Violates MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string literal, a
*          parenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Dio_Cfg.h"
#include "Dio_Siul_LLD.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define DIO_VENDOR_ID_LLD                   43
/* 
* @violates @ref DIO_LLD_h_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers 
*/
#define DIO_AR_RELEASE_MAJOR_VERSION_LLD    4
/* 
* @violates @ref DIO_LLD_h_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers 
*/
#define DIO_AR_RELEASE_MINOR_VERSION_LLD    0
/* 
* @violates @ref DIO_LLD_h_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers 
*/
/* 
* @violates @ref DIO_LLD_h_REF_2 MISRA 2004 Advisory Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character signifiance and case sensitivity are supported for external identifiers.
*/
#define DIO_AR_RELEASE_REVISION_VERSION_LLD 3
#define DIO_SW_MAJOR_VERSION_LLD            1
#define DIO_SW_MINOR_VERSION_LLD            0
#define DIO_SW_PATCH_VERSION_LLD            1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#if (DIO_VENDOR_ID_LLD != DIO_VENDOR_ID_CFG)
#error "Dio_LLD.h and Dio_Cfg.h have different vendor ids"
#endif
#if ((DIO_AR_RELEASE_MAJOR_VERSION_LLD    != DIO_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (DIO_AR_RELEASE_MINOR_VERSION_LLD    != DIO_AR_RELEASE_MINOR_VERSION_CFG) || \
     (DIO_AR_RELEASE_REVISION_VERSION_LLD != DIO_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Dio_LLD.h and Dio_Cfg.h are different"
#endif
#if ((DIO_SW_MAJOR_VERSION_LLD != DIO_SW_MAJOR_VERSION_CFG) || \
     (DIO_SW_MINOR_VERSION_LLD != DIO_SW_MINOR_VERSION_CFG) || \
     (DIO_SW_PATCH_VERSION_LLD != DIO_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Dio_LLD.h and Dio_Cfg.h are different"
#endif


/* @implements    DDIO04015.*/
#if ((DIO_AR_RELEASE_MAJOR_VERSION_LLD != SIUL_DIO_AR_RELEASE_MAJOR_VERSION_LLD) || \
     (DIO_AR_RELEASE_MINOR_VERSION_LLD != SIUL_DIO_AR_RELEASE_MINOR_VERSION_LLD) || \
     (DIO_AR_RELEASE_REVISION_VERSION_LLD != SIUL_DIO_AR_RELEASE_REVISION_VERSION_LLD))
     #error "AUTOSAR Version Numbers of Dio_LLD.h and Siul_Dio_LLD.h are different"
#endif

#if ((DIO_SW_MAJOR_VERSION_LLD != SIUL_DIO_SW_MAJOR_VERSION_LLD) || \
     (DIO_SW_MINOR_VERSION_LLD != SIUL_DIO_SW_MINOR_VERSION_LLD) || \
     (DIO_SW_PATCH_VERSION_LLD != SIUL_DIO_SW_PATCH_VERSION_LLD))
    #error "Software Version Numbers of Dio_LLD.h and Siul_Dio_LLD.h are different"
#endif

#if (DIO_VENDOR_ID_LLD != SIUL_DIO_VENDOR_ID_LLD)
    #error "VENDOR ID for Dio_LLD.h and Siul_Dio_LLD.h is different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/



/**
* @brief          Mapping macro between low level layer and high level layer.
*
* @implements     DDIO04002.
*
**/
/* 
* @violates @ref  DIO_LLD_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/*
* @violates @ref DIO_LLD_h_REF_4 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define Dio_LLD_ReadChannel(ChannelId)\
    Dio_SIUL_ReadChannel(ChannelId)

/**
* @brief          Mapping macro between low level layer and high level layer.
*
* @implements     DDIO04005.
*
**/
/* 
* @violates @ref  DIO_LLD_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

/*
* @violates @ref DIO_LLD_h_REF_4 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define Dio_LLD_WriteChannel(ChannelId, ChannelLevel) \
Dio_SIUL_WriteChannel((ChannelId), (ChannelLevel))

#if (DIO_FLIP_CHANNEL_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Mapping macro between low level layer and high level layer.
*
* @implements     DDIO04001.
**/

/* 
* @violates @ref  DIO_LLD_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/*
* @violates @ref DIO_LLD_h_REF_4 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define Dio_LLD_FlipChannel(ChannelId) \
    Dio_SIUL_FlipChannel(ChannelId)
#endif /* DIO_FLIP_CHANNEL_API == STD_ON */

/**
* @brief          Mapping macro between low level layer and high level layer.
*
* @implements     DDIO04004.
*
**/
/*
*  @violates @ref  DIO_LLD_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/*
* @violates @ref DIO_LLD_h_REF_4 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define Dio_LLD_ReadPort(PortId) \
    Dio_SIUL_ReadPort(PortId)

/**
* @brief          Mapping macro between low level layer and high level layer.
*
* @implements     DDIO04007.
*
**/
/*
* @violates @ref  DIO_LLD_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/*
* @violates @ref DIO_LLD_h_REF_4 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define Dio_LLD_WritePort(PortId, PortLevel) \
Dio_SIUL_WritePort((PortId), (PortLevel))

/**
* @brief          Mapping macro between low level layer and high level layer.
*
* @implements     DDIO04003.
*
**/
/*
* @violates @ref  DIO_LLD_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/*
* @violates @ref DIO_LLD_h_REF_4 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define Dio_LLD_ReadChannelGroup(ChannelGroupIdPtr) \
Dio_SIUL_ReadChannelGroup(ChannelGroupIdPtr)

/**
* @brief          Mapping macro between low level layer and high level layer.
*
* @implements     DDIO04006.
*
**/
/*
* @violates @ref  DIO_LLD_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/*
* @violates @ref DIO_LLD_h_REF_4 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define Dio_LLD_WriteChannelGroup(ChannelGroupIdPtr, Level) \
Dio_SIUL_WriteChannelGroup((ChannelGroupIdPtr), (Level))

#if (DIO_MASKEDWRITEPORT_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Mapping macro between low level layer and high level layer.
*
* @implements     DDIO04026.
*
**/
/*
* @violates @ref  DIO_LLD_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
/*
* @violates @ref DIO_LLD_h_REF_4 MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string
* literal, aparenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*/
#define Dio_LLD_MaskedWritePort(PortId, PortLevel, Mask)                    \
    Dio_SIUL_MaskedWritePort((PortId), (PortLevel), (Mask))
#endif /* DIO_MASKEDWRITEPORT_API */

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

#ifdef __cplusplus
}
#endif

#endif /* DIO_LLD_H */

/** @} */
