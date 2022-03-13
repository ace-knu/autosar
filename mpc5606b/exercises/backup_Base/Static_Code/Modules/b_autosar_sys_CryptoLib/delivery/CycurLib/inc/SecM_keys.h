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
   \file SecM_keys.h

   \brief  External header for defining keys for SecM.

   Configuration according to Chapter 7 of HIS Security Module Specification,

   Configuration is supposed to be modified by the integrator.

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_SECM_KEYS_H_
#define _ESC_SECM_KEYS_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/
#include "rsa.h"

#ifdef  __cplusplus
/* *INDENT-OFF* */
extern "C" {
 /* *INDENT-ON* */
#endif

/***************************************************************************
 * 2. DEFINES                                                              *
 ***************************************************************************/

/**
  Since the keys are defined as _arrays_ you need to specify
  the array-size. Take care that the sizes equals the corresponding parameters.
 */
#define SEC_AUTHENTICITY_KEY_LEN 16U    /* This may even be > 64, since it will be hashed */

/** Only exponents up to 2^24-1 are supported.
\note Do not modify! */
#define SEC_EXPONENT_LEN         3U
/** The length of the modulus in byte
\note Do not modify! Modify in rsa.h instead */
#define SEC_MODULUS_LEN          EscRsa_KEY_BYTES

#if 0
/* Not implemented */
/** The key for security class AAA. Not implemented. */
#    define SEC_ENCRYPTION_KEY   { 0 }
/** The key size for security class AAA. Not implemented. */
#    define SEC_ENCRYPTION_KEY_LEN   0
#endif

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** This key is used during the HMAC computations! */
#define SEC_AUTHENTICITY_KEY                                                                                           \
    {                                                                                                                  \
        0x30U, 0x31U, 0x32U, 0x33U, 0x34U, 0x35U, 0x36U, 0x37U, 0x38U, 0x39U, 0x61U, 0x62U, 0x63U, 0x64U, 0x65U, 0x66U \
    }

/* Signature Key */

/**
RSA modulus to verify signature with. Value in Big-Endian format.
*/
#define SEC_MODULUS                                                                                                     \
    {                                                                                                                   \
        0xf7U, 0x24U, 0x2fU, 0x3bU, 0xb8U, 0x69U, 0x7eU, 0xe5U, 0xc3U, 0xacU, 0xafU, 0x80U, 0x0bU, 0xa1U, 0xc8U, 0x4eU, \
        0x3cU, 0x89U, 0xeaU, 0x37U, 0x39U, 0x87U, 0x07U, 0x3dU, 0x97U, 0x1eU, 0x91U, 0xf8U, 0x3aU, 0xd4U, 0x36U, 0xf6U, \
        0x09U, 0xbbU, 0xbbU, 0x8fU, 0xbfU, 0x25U, 0x03U, 0x98U, 0x86U, 0x0bU, 0xb2U, 0x0cU, 0x63U, 0x0bU, 0xa1U, 0x24U, \
        0xd9U, 0x34U, 0x8bU, 0xe0U, 0xbaU, 0x61U, 0xf9U, 0x43U, 0x66U, 0x21U, 0x20U, 0x5eU, 0x02U, 0x89U, 0xaeU, 0x23U, \
        0x8dU, 0xdaU, 0xbdU, 0x16U, 0xebU, 0xb7U, 0x15U, 0xeaU, 0x85U, 0xddU, 0xb9U, 0x88U, 0xccU, 0x31U, 0xd3U, 0x74U, \
        0xd7U, 0xc5U, 0x80U, 0x0aU, 0x74U, 0xf6U, 0xdaU, 0x68U, 0x11U, 0x06U, 0xd0U, 0xa6U, 0x3dU, 0x50U, 0xbaU, 0x1fU, \
        0xeaU, 0x4fU, 0xc2U, 0x02U, 0x95U, 0x0fU, 0x58U, 0x2eU, 0x12U, 0xe0U, 0xbaU, 0xf6U, 0xffU, 0xe0U, 0xf4U, 0xc5U, \
        0xe2U, 0x76U, 0xa5U, 0xaaU, 0xdaU, 0xe7U, 0xb8U, 0x77U, 0x34U, 0x76U, 0xd0U, 0x9bU, 0x0bU, 0x88U, 0x3aU, 0x83U  \
    }

/**
RSA public exponent to verify signature with. Value in Big-Endian format.
*/
#define SEC_EXPONENT { 0x00U, 0x9dU, 0x85U }

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. MACRO FUNCTIONS / PARAMETER CHECKS                                   *
 ***************************************************************************/

#ifdef  __cplusplus
/* *INDENT-OFF* */
}
/* *INDENT-ON* */
#endif
#endif
/***************************************************************************
 * 6. END                                                                  *
 ***************************************************************************/
