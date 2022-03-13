/**
*   @file    Platform_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - Platform dependend data type definitions.
*   @details AUTOSAR platform types header file. It contains all 
*            platform dependent types and symbols. Those types must be abstracted in order to 
*            become platform and compiler independent.
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
/**
* @file        Platform_Types.h
* @implements  DBASE08000, DBASE08001, DBASE08036, DBASE08037
*/

/**   
* @file         Platform_Types.h
* @requirements PLATFORM002
* @note         It is not allowed to add any extension to this file. Any extension invalidates the 
*               AUTOSAR conformity
*/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Platform_Types_h_REF_1
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
 * significance of more than 31 characters.
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Platform_Types.h
* @implements    DBASE08028, DBASE08029, DBASE08030, DBASE08031, DBASE08032, DBASE08033, DBASE08034
*/
#define PLATFORM_VENDOR_ID                      43
/*
* @violates @ref Platform_Types_h_REF_1 This is required as per autosar Requirement, 
*/
#define PLATFORM_AR_RELEASE_MAJOR_VERSION       4
/*
* @violates @ref Platform_Types_h_REF_1 This is required as per autosar Requirement, 
*/
#define PLATFORM_AR_RELEASE_MINOR_VERSION       0
/*
* @violates @ref Platform_Types_h_REF_1 This is required as per autosar Requirement, 
*/
#define PLATFORM_AR_RELEASE_REVISION_VERSION    3
#define PLATFORM_SW_MAJOR_VERSION               1
#define PLATFORM_SW_MINOR_VERSION               0
#define PLATFORM_SW_PATCH_VERSION               1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          8bit Type Processor
* @implements     DBASE08022
*/
#define CPU_TYPE_8 8

/**
* @brief          16bit Type Processor
* @implements     DBASE08020
*/
#define CPU_TYPE_16 16

/**
* @brief          32bit Type Processor
* @implements     DBASE08021
*/
#define CPU_TYPE_32 32

/**
* @brief          MSB First Processor
* @implements     DBASE08027
*/
#define MSB_FIRST 0

/**
* @brief          LSB First Processor
* @implements     DBASE08026
*/
#define LSB_FIRST 1

/**
* @brief          HIGH_BYTE_FIRST Processor
* @implements     DBASE08024
*/
#define HIGH_BYTE_FIRST 0

/** 
* @brief          LOW_BYTE_FIRST Processor
* @implements     DBASE08025
*/
#define LOW_BYTE_FIRST 1

/** 
* @brief          Processor type
* @implements     DBASE08019
*/
#define CPU_TYPE (CPU_TYPE_32)

/** 
* @brief          Bit order on register level.
* @implements     DBASE08017
*/
#define CPU_BIT_ORDER (MSB_FIRST)

/** 
* @brief The byte order on memory level shall be indicated in the platform types header file using 
*        the symbol CPU_BYTE_ORDER.
* @implements    DBASE08018
*/
#define CPU_BYTE_ORDER (HIGH_BYTE_FIRST)

#ifndef TRUE
    /** 
    * @brief Boolean true value
    * @implements DBASE08035
    */
    #define TRUE 1
#endif
#ifndef FALSE
    /** 
    * @brief Boolean false value
    * @implements DBASE08023
    */
    #define FALSE 0
#endif

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** 
* @brief The standard AUTOSAR type boolean shall be implemented on basis of an eight bits long 
*        unsigned integer.
* @implements DBASE08002
*/
typedef unsigned char boolean;


/** 
* @brief Unsigned 8 bit integer with range of 0 ..+255 (0x00..0xFF) - 
*        8 bit
* @implements DBASE08003
*/
typedef unsigned char uint8;

/** 
* @brief Unsigned 16 bit integer with range of 0 ..+65535 (0x0000..0xFFFF) - 
*        16 bit
* @implements DBASE08004
*/
typedef unsigned short uint16;

/** 
* @brief Unsigned 32 bit integer with range of 0 ..+4294967295 (0x00000000..0xFFFFFFFF) - 
*        32 bit
* @implements DBASE08005
*/
typedef unsigned long uint32;

/** 
* @brief Signed 8 bit integer with range of -128 ..+127 (0x80..0x7F) - 
*        7 bit + 1 sign bit 
* @implements DBASE08006
*/
typedef signed char sint8;

/** 
* @brief Signed 16 bit integer with range of -32768 ..+32767 (0x8000..0x7FFF) - 
*        15 bit + 1 sign bit 
* @implements DBASE08007
*/
typedef signed short sint16;

/** 
* @brief Signed 32 bit integer with range of -2147483648.. +2147483647 (0x80000000..0x7FFFFFFF) - 
*        31 bit + 1 sign bit 
* @implements DBASE08008
*/
typedef signed long sint32;

/** 
* @brief Unsigned integer at least 8 bit long. Range of at least 0 ..+255 (0x00..0xFF) - 
*        8 bit
* @implements DBASE08009
*/
typedef unsigned long uint8_least;

/** 
* @brief  Unsigned integer at least 16 bit long. Range of at least 0 ..+65535 (0x0000..0xFFFF) - 
*         16 bit
* @implements DBASE08010
*/
typedef unsigned long uint16_least;

/** 
* @brief Unsigned integer at least 32 bit long. Range of at least 0 ..+4294967295 
*       (0x00000000..0xFFFFFFFF) - 32 bit
* @implements DBASE08011
*/
typedef unsigned long uint32_least;

/** 
* @brief Signed integer at least 8 bit long. Range - at least -128 ..+127. 
*        At least 7 bit + 1 bit sign
* @implements DBASE08012
*/
typedef signed long sint8_least;

/** 
* @brief Signed integer at least 16 bit long. Range - at least -32768 ..+32767. 
*        At least 15 bit + 1 bit sign
* @implements DBASE08013
*/
typedef signed long sint16_least;

/** 
* @brief Signed integer at least 32 bit long. Range - at least -2147483648.. +2147483647. 
*       At least 31 bit + 1 bit sign
* @implements DBASE08014
*/
typedef signed long sint32_least;

/** 
* @brief 32bit long floating point data type
* @implements DBASE08015
*/
typedef float float32;

/** 
* @brief 64bit long floating point data type
* @implements DBASE08016
*/
typedef double float64;

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif


#endif /* #ifndef PLATFORM_TYPES_H */

/** @} */
