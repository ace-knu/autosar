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
   \file        pkcs1_v15.h

   \brief       PKCS#1 v2.1 signature verification

   Implementation of RSASSA-PKCS1-v1_5_Verify.
   Byteformat of all long numbers is Big-Endian.

   \see         ftp://ftp.rsasecurity.com/pub/pkcs/pkcs-1/pkcs-1v2-1.pdf


   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_PKCS1_V15_H_
#define _ESC_PKCS1_V15_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#include "rsa.h"
#ifndef EscRsa_ENABLE_STACK_SAVING_INTERFACE

#        ifdef  __cplusplus
/* *INDENT-OFF* */
extern "C" {
 /* *INDENT-ON* */
#        endif

/***************************************************************************
 * 2. DEFINES                                                              *
 ***************************************************************************/

/* User definable configuration */
#        if 0
/** Support for MD2 digest disabled. */
#            define EscPkcs1V15_DIGEST_MD2_DISABLE
#        endif

#        if 0
/** Support for MD5 digest disabled . */
#            define EscPkcs1V15_DIGEST_MD5_DISABLE
#        endif

#        if 0
/** Support for SHA1 digest disabled. */
#            define EscPkcs1V15_DIGEST_SHA1_DISABLE
#        endif

#        if 0
/** Support for SHA224 digest disabled. */
#            define EscPkcs1V15_DIGEST_SHA224_DISABLE
#        endif

#        if 0
/** Support for SHA256 digest disabled. */
#            define EscPkcs1V15_DIGEST_SHA256_DISABLE
#        endif

#        if 0
/** Support for SHA384 digest disabled. */
#            define EscPkcs1V15_DIGEST_SHA384_DISABLE
#        endif

#        if 0
/** Support for SHA512 digest disabled. */
#            define EscPkcs1V15_DIGEST_SHA512_DISABLE
#        endif

#        if 0
/** Support for RIPEMD-160 digest disabled. */
#            define EscPkcs1V15_DIGEST_RIPEMD160_DISABLE
#        endif

/* Everything below this line is not to be configured */

#        ifndef EscPkcs1V15_DIGEST_MD2_DISABLE
/** MD2 algorithm. The length of hashDigest is 16 byte. */
#            define EscPkcs1V15_DIGEST_TYPE_MD2          0U
#        endif
#        ifndef EscPkcs1V15_DIGEST_MD5_DISABLE
/** MD5 algorithm. The length of hashDigest is 16 byte. */
#            define EscPkcs1V15_DIGEST_TYPE_MD5          1U
#        endif
#        ifndef EscPkcs1V15_DIGEST_SHA1_DISABLE
/** SHA-1 algorithm. The length of hashDigest is 20 byte. */
#            define EscPkcs1V15_DIGEST_TYPE_SHA1         2U
#        endif
#        ifndef EscPkcs1V15_DIGEST_SHA224_DISABLE
/** SHA-224 algorithm. The length of hashDigest is 28 byte. */
#            define EscPkcs1V15_DIGEST_TYPE_SHA224       3U
#        endif
#        ifndef EscPkcs1V15_DIGEST_SHA256_DISABLE
/** SHA-256 algorithm. The length of hashDigest is 32 byte. */
#            define EscPkcs1V15_DIGEST_TYPE_SHA256       4U
#        endif
#        ifndef EscPkcs1V15_DIGEST_SHA384_DISABLE
/** SHA-384 algorithm. The length of hashDigest is 48 byte. */
#            define EscPkcs1V15_DIGEST_TYPE_SHA384       5U
#        endif
#        ifndef EscPkcs1V15_DIGEST_SHA512_DISABLE
/** SHA-512 algorithm. The length of hashDigest is 64 byte. */
#            define EscPkcs1V15_DIGEST_TYPE_SHA512       6U
#        endif
#        ifndef EscPkcs1V15_DIGEST_RIPEMD160_DISABLE
/** RIPEMD-160 algorithm. The length of hashDigest is 20 byte. */
#            define EscPkcs1V15_DIGEST_TYPE_RIPEMD160    7U
#        endif

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** A private key */
typedef struct {
    /** Modulus */
    UINT8 modulus[ EscRsa_KEY_BYTES ];

#   ifdef EscRsa_ENABLE_CRT
    /** Private exponent, CRT format */
    UINT8 p[ EscRsa_KEY_BYTES / 2U ];
    UINT8 q[ EscRsa_KEY_BYTES / 2U ];
    UINT8 dmp1[ EscRsa_KEY_BYTES / 2U ];
    UINT8 dmq1[ EscRsa_KEY_BYTES / 2U ];
    UINT8 iqmp[ EscRsa_KEY_BYTES / 2U ];
#   else
    /** Private exponent */
    UINT8 privExp[ EscRsa_KEY_BYTES ];
#   endif
} EscPkcs1V15_PrivKeyT;

/** Parameters for EscPkcs1V15_Sign */
typedef struct {
    /** The calculated digest of the message. The length is selected by
        the parameter digestType. */
    const UINT8 * hashDigest;

    /** Private key structure. */
    const EscPkcs1V15_PrivKeyT * privKey;

    /** Signature size EscRsa_KEY_BYTES. */
    UINT8 * signature;

    /** The type of the digest. One of the EscPkcs1V15_DIGEST_TYPE_xxx defines. */
    UINT8 digestType;
} EscPkcs1V15_SignParamsT;

/** Parameters for EscPkcs1V15_Verify. */
typedef struct {
    /** Signature created with RSASSA-PKCS1-v1_5_Sign.
    The length of the signature is EscRsa_KEY_BYTES bytes. */
    const UINT8 * signature;

    /** RSA modulus in big endian byte order. The length of the
    modulus is EscRsa_KEY_BYTES bytes. */
    const UINT8 * modulus;

    /** The public Exponent. */
    UINT32 pubExp;

    /** The calculated digest of the message. The length is selected by
    the parameter digestType. */
    const UINT8 * hashDigest;

    /** The type of the digest. One of the EscPkcs1V15_DIGEST_TYPE_xxx defines. */
    UINT8 digestType;
} EscPkcs1V15_VerifyParamsT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
Signs a message according to
RSASSA-PKCS1-v1_5_Sign.

The RSA Key Length is configured in rsa.h.

\see PKCS#1 v2.1, section 8.2.1
\see rsa.h

\param[in] params Parameters for signing.

\return TRUE on error
*/
extern BOOL
EscPkcs1V15_Sign(
    const EscPkcs1V15_SignParamsT* params );

/**
Verifies the signature of a message according to
RSASSA-PKCS1-v1_5_Verify.

The RSA Key Length is configured in rsa.h.

\see PKCS#1 v2.1, section 8.2.2
\see rsa.h

\param[in] params Parameters for verifying.

\return TRUE on error or if verification fails.
*/
extern BOOL
EscPkcs1V15_Verify(
    const EscPkcs1V15_VerifyParamsT* params );

/***************************************************************************
 * 6. MACRO FUNCTIONS                                                      *
 ***************************************************************************/
#        ifdef  __cplusplus
/* *INDENT-OFF* */
}
/* *INDENT-ON* */
#        endif

#    endif

#endif
/***************************************************************************
 * 7. END                                                                  *
 ***************************************************************************/
