/***************************************************************************
 * Copyright                                                               *
 *                                                                         *
 *     ESCRYPT GmbH - Embedded Security       ESCRYPT Inc.                 *
 *     Zentrum fuer IT-Sicherheit             315 E Eisenhower Parkway     *
 *     Lise-Meitner-Allee 4                   Suite 214                    *
 *     44801 Bochum                           Ann Arbor, MI 48108          *
 *     Germany                                USA                          *
 *                                                                         *
 *     http://www.escrypt.com                                              *
 *     info"at"escrypt.com                                                 *
 *                                                                         *
 * All Rights reserved                                                     *
 ***************************************************************************/

/***************************************************************************/
/*!
   \file        cycurlib_config.h

   \brief       Main configuration file for the CycurLIB.

   This file will be included in any CycurLIB module.
   It has to be adapted for each implementation.

   $Rev: 2068 $
 */
/***************************************************************************/
#ifndef _ESC_CYCURLIB_H_
#define _ESC_CYCURLIB_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#ifdef  __cplusplus
/* *INDENT-OFF* */
extern "C" {
 /* *INDENT-ON* */
#endif

/***************************************************************************
 * 2. DEFINES                                                              *
 ***************************************************************************/

#if 1
#    ifndef Esc_HAS_INT64
/**
Platform has UINT64 data types.
Violates MISRA-C:2004 rule 1.1 (Code should conform to ISO C90)
but can speed up ECC, RSA and SHA-512 performance substantially.
This define is also required for some functions of the AES_XTS module.
*/
#        define Esc_HAS_INT64
#    endif
#endif

#if 1
#    ifndef Esc_OPTIMIZE_SPEED
/**
Use speed optimized versions of algorithms, e.g.
    - AES
    - CRC_32
    - DES
    - ECC
    - RSA
    - Whirlpool
*/
#        define Esc_OPTIMIZE_SPEED
#    endif
#endif

#if 0
#    ifndef Esc_NDEBUG
/**
Defining Esc_NDEBUG disables asserts, as well as further online-selftests.

It is also possible to define the Esc_NDEBUG to the ANSI-C NDEBUG define,
which is supported by most of the today's IDEs and Compilers
*/
#        define Esc_NDEBUG
#    endif
#endif

#if 0
#    ifndef Esc_NDEBUG
#        ifdef NDEBUG
/**
It is also possible to define the Esc_NDEBUG to the ANSI-C NDEBUG define,
which is supported by most of the today's IDEs and Compilers
*/
#            define Esc_NDEBUG
#        endif
#    endif
#endif

#if 0
#    ifndef EscTst_ENABLE_LOGGING
/**
Set this define to enable the debug output of the CycurLIB selftest.
The default implementation for the output violates MISRA by
using printf of stdio.h.

Edit ESCLIB_PRINTF macro in /tests/src/selftest.c to adjust to your own implementation
if your platform doesn't support stdlib.h.
*/
#        define EscTst_ENABLE_LOGGING
#    endif
#endif

#if 0
#    ifndef EscTstStack_ENABLE_STACK_LOGGING
/**
Set this define to enable the logging of the stack usage in the CycurLIB selftest.
Stack logging consumes a huge amount of RAM and might confuse many compilers.
To see the result, EscTst_ENABLE_LOGGING has also to be defined. 
The maximum of measured stack usage can be defined in /tests/src/stackusage.c
*/
#        define EscTstStack_ENABLE_STACK_LOGGING
#    endif
#endif


/* Everything below this line is not to be configured */

#ifdef Esc_NDEBUG
/*lint -save -esym(961,19.7) We violate MISRA-C Advisory rule 19.7 */
/** In Release version we disable the Esc_ASSERT function. */
#    define Esc_ASSERT( p ) ( (void)0 )
/*lint -restore */
#else
#    include <assert.h>
/*lint -save -esym(961,19.7) We violate MISRA-C Advisory rule 19.7 */
/** In Debug version we use the assert macro from the standard library */
#    define Esc_ASSERT( p ) assert(p)
/*lint -restore */
#endif

#ifdef Esc_HAS_INT64
#    ifndef UINT64
/** 64 bit unsigned integer. Not MISRA compatible. */
typedef unsigned long long UINT64;
#    endif
#    ifndef SINT64
/** 64 bit signed integer. Not MISRA compatible. */
typedef signed long long SINT64;
#    endif
#endif

#ifndef UINT32
/** 32 bit unsigned integer. */
typedef unsigned long UINT32;
#endif

#ifndef UINT16
/** 16 bit unsigned integer. */
typedef unsigned short UINT16;
#endif

#ifndef UINT8
/** 8 bit unsigned integer. */
typedef unsigned char UINT8;
#endif

#ifndef SINT32
/** 32 bit signed integer. */
typedef signed long SINT32;
#endif

#ifndef SINT16
/** 16 bit signed integer. */
typedef signed short SINT16;
#endif

#ifndef SINT8
/** 8 bit signed integer. */
typedef signed char SINT8;
#endif

#ifndef CHAR
/** Single character of a C-Style string. */
typedef char CHAR;
#endif

#ifndef BOOL
/** Type can only be TRUE (Non-zero) or FALSE (Zero). Boolean operations deliver the expected results. */
typedef UINT8 BOOL;
#endif

#ifndef TRUE
/** BOOL value true. */
#    define TRUE        ( (BOOL)1 )
#endif

#ifndef FALSE
/** BOOL value false. */
#    define FALSE       ( (BOOL)0 )
#endif

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/***************************************************************************
 * 6. MACRO FUNCTIONS                                                      *
 ***************************************************************************/

#ifdef  __cplusplus
/* *INDENT-OFF* */
}
/* *INDENT-ON* */
#endif
#endif
/***************************************************************************
 * 7. END                                                                  *
 ***************************************************************************/
