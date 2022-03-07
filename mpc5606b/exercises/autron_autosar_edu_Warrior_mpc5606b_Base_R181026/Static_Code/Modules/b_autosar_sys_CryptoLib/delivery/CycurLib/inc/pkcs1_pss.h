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
   \file        pkcs1_pss.h

   \brief       PKCS#1 v2.1 RSASSA-PSS signature creation and verification
                with MGF1 as the mask generation function

   Byteformat of all long numbers is Big-Endian.

   \see         ftp://ftp.rsasecurity.com/pub/pkcs/pkcs-1/pkcs-1v2-1.pdf


   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_PKCS1_PSS_H_
#define _ESC_PKCS1_PSS_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#include "rsa.h"
#ifndef EscRsa_ENABLE_STACK_SAVING_INTERFACE
#    include "random.h"

#    ifdef  __cplusplus
/* *INDENT-OFF* */
extern "C" {
 /* *INDENT-ON* */
#    endif

/***************************************************************************
 * 2. DEFINES                                                              *
 ***************************************************************************/

/** Enables the SHA-1 */
#define EscPkcs1Pss_USE_SHA1 1U

/** Enables the SHA-224/SHA-256 */
#define EscPkcs1Pss_USE_SHA256 2U

/** Enables the SHA-384/SHA-512 */
#define EscPkcs1Pss_USE_SHA512 3U

/* User definable configuration */

#ifndef EscPkcs1Pss_HASH_TYPE
/** Determines the hash algorithm.
    Supported values:
    - EscPkcs1Pss_USE_SHA1
    - EscPkcs1Pss_USE_SHA256
    - EscPkcs1Pss_USE_SHA512

    * For using SHA224 or SHA384 please refer to the configuration of
      the SHA-256 respectively SHA-512 module.
*/
#    define EscPkcs1Pss_HASH_TYPE EscPkcs1Pss_USE_SHA1
#endif

#if ( EscPkcs1Pss_HASH_TYPE == EscPkcs1Pss_USE_SHA1 )
/* SHA-1 */
#   include "sha_1.h"

#   ifndef EscPkcs1Pss_SALT_LEN
        /** The length of the used salt. By default we use the length of the hash value */
#       define EscPkcs1Pss_SALT_LEN EscSha1_DIGEST_LEN
#   endif


#elif ( EscPkcs1Pss_HASH_TYPE == EscPkcs1Pss_USE_SHA256 )
/* SHA-256 */
#    include "sha_256.h"

#   ifndef EscPkcs1Pss_SALT_LEN
        /** The length of the used salt. By default we use the length of the hash value */
#       define EscPkcs1Pss_SALT_LEN EscSha256_DIGEST_LEN
#   endif


#elif ( EscPkcs1Pss_HASH_TYPE == EscPkcs1Pss_USE_SHA512 )
/* SHA-512 */
#    include "sha_512.h"

#   ifndef EscPkcs1Pss_SALT_LEN
        /** The length of the used salt. By default we use the length of the hash value */
#       define EscPkcs1Pss_SALT_LEN EscSha512_DIGEST_LEN
#   endif


#else
#   error "EscPkcs1Pss_HASH_TYPE is not supported"
#endif


/* Everything below this line is not to be configured */

#if ( EscPkcs1Pss_HASH_TYPE == EscPkcs1Pss_USE_SHA1 )
    /** The length of the used digest */
#   define EscPkcs1Pss_DIGEST_LEN EscSha1_DIGEST_LEN
#elif ( EscPkcs1Pss_HASH_TYPE == EscPkcs1Pss_USE_SHA256 )
    /** The length of the used digest */
#   define EscPkcs1Pss_DIGEST_LEN EscSha256_DIGEST_LEN
#elif ( EscPkcs1Pss_HASH_TYPE == EscPkcs1Pss_USE_SHA512 )
    /** The length of the used digest */
#   define EscPkcs1Pss_DIGEST_LEN EscSha512_DIGEST_LEN
#else
#   error "EscPkcs1Pss_HASH_TYPE is not supported"
#endif

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
} EscPkcs1Pss_PrivKeyT;

/** A public key */
typedef struct {
    /** Modulus */
    UINT8 modulus[ EscRsa_KEY_BYTES ];

    /** Public exponent */
    UINT32 pubExp;
} EscPkcs1Pss_PubKeyT;

/** Parameters for EscPkcs1Pss_Sign */
typedef struct {
    /** Random context. */
    EscRandom_ContextT* randCtx;

    /** Message to be encrypted. */
    const UINT8 * message;

    /** Size of the message in bytes. */
    UINT32 messageLen;

    /** Private key structure. */
    const EscPkcs1Pss_PrivKeyT * privKey;

    /** Signature of size EscRsa_KEY_BYTES. */
    UINT8* signature;
} EscPkcs1Pss_SignDataT;

/** Parameters for EscPkcs1Pss_Verify */
typedef struct {
    /** Message. */
    const UINT8 * message;

    /** Size of the message in bytes. */
    UINT32 messageLen;

    /** Public key structure. */
    const EscPkcs1Pss_PubKeyT * pubKey;

    /** Signature to be verified, of size EscRsa_KEY_BYTES. */
    const UINT8 * signature;
} EscPkcs1Pss_VerifyDataT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
Signs a message according to RSASSA-PSS-Sign.
\see Section 8.1.1

\param[in] signData Parameters for signing.

\return TRUE on error
*/
extern BOOL
EscPkcs1Pss_Sign(
    const EscPkcs1Pss_SignDataT* signData );

/**
Verifies a message according to RSASSA-PSS-Verify.
\see Section 8.1.2

\param[in] verifyData Parameters for verifying.

\return TRUE on error or if verification fails.
*/
extern BOOL
EscPkcs1Pss_Verify(
    const EscPkcs1Pss_VerifyDataT* verifyData );

/***************************************************************************
 * 6. MACRO FUNCTIONS                                                      *
 ***************************************************************************/
#        ifdef  __cplusplus
/* *INDENT-OFF* */
}
/* *INDENT-ON* */
#        endif

#endif /* EscRsa_ENABLE_STACK_SAVING_INTERFACE */

#endif
/***************************************************************************
 * 7. END                                                                  *
 ***************************************************************************/
