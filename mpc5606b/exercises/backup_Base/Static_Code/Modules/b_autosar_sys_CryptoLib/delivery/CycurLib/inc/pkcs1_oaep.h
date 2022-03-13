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
   \file        pkcs1_oaep.h

   \brief       PKCS#1 v2.1 RSAES-OAEP encryption and decryption
                with MGF1 as the mask generation function

   Byteformat of all long numbers is Big-Endian.

   \see         ftp://ftp.rsasecurity.com/pub/pkcs/pkcs-1/pkcs-1v2-1.pdf


   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_PKCS1_OAEP_H_
#define _ESC_PKCS1_OAEP_H_

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
#define EscPkcs1Oaep_USE_SHA1 1U

/** Enables the SHA-224/SHA-256 */
#define EscPkcs1Oaep_USE_SHA256 2U

/** Enables the SHA-384/SHA-512 */
#define EscPkcs1Oaep_USE_SHA512 3U

/* User definable configuration */

#ifndef EscPkcs1Oaep_HASH_TYPE
/** Determines the hash algorithm.
    Supported values:
    - EscPkcs1Oaep_USE_SHA1
    - EscPkcs1Oaep_USE_SHA256
    - EscPkcs1Oaep_USE_SHA512

    * For using SHA224 or SHA384 please refer to the configuration of
      the SHA-256 respectively SHA-512 module.
*/
#    define EscPkcs1Oaep_HASH_TYPE EscPkcs1Oaep_USE_SHA1
#endif


/* Everything below this line is not to be configured */

#if ( EscPkcs1Oaep_HASH_TYPE == EscPkcs1Oaep_USE_SHA1 )
/* SHA-1 */
#   include "sha_1.h"
    /** The length of the used digest */
#   define EscPkcs1Oaep_DIGEST_LEN EscSha1_DIGEST_LEN
#elif ( EscPkcs1Oaep_HASH_TYPE == EscPkcs1Oaep_USE_SHA256 )
/* SHA-256 */
#    include "sha_256.h"
    /** The length of the used digest */
#   define EscPkcs1Oaep_DIGEST_LEN EscSha256_DIGEST_LEN
#elif ( EscPkcs1Oaep_HASH_TYPE == EscPkcs1Oaep_USE_SHA512 )
/* SHA-512 */
#    include "sha_512.h"
    /** The length of the used digest */
#   define EscPkcs1Oaep_DIGEST_LEN EscSha512_DIGEST_LEN
#else
#   error "EscPkcs1Oaep_HASH_TYPE is not supported"
#endif

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** A public key */
typedef struct {
    /** Pointer to modulus */
    const UINT8 * modulus;

    /** Length of modulus in bits */
    UINT32 modulusLenBits;

    /** Public exponent */
    UINT32 pubExp;
} EscPkcs1Oaep_PubKeyT;

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
} EscPkcs1Oaep_PrivKeyT;

/** Parameters for EscPkcs1Oaep_Encrypt */
typedef struct {
    /** Random context. */
    EscRandom_ContextT* randCtx;

    /** Message to be encrypted. */
    const UINT8 * message;

    /** Size of the message in bytes. */
    UINT32 messageLen;

    /** Label to be assigned. */
    const UINT8 * label;

    /** Size of the label in bytes. */
    UINT32 labelLen;

    /** Public key structure. */
    const EscPkcs1Oaep_PubKeyT * pubKey;

    /** Ciphertext of size EscRsa_KEY_BYTES. */
    UINT8* cipher;
} EscPkcs1Oaep_EncryptDataT;

/** Parameters for EscPkcs1Oaep_Decrypt */
typedef struct {
    /** Ciphertext of size EscRsa_KEY_BYTES to be decrypted. */
    const UINT8 * cipher;

    /** Label to be verified. */
    const UINT8 * label;

    /** Size of the label in bytes. */
    UINT32 labelLen;

    /** Decrypted message. */
    UINT8* message;

    /**
     * [in] Size of the message buffer in bytes.
     * [out] Size of the message in bytes
     **/
    UINT32* messageLen;

    /** Private key structure. */
    const EscPkcs1Oaep_PrivKeyT * privKey;
} EscPkcs1Oaep_DecryptDataT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
Encrypts a message according to RSAES-OAEP.
\see Section 7.1.1

\param[in] encryptData Parameters for encryption.

\return TRUE on error
*/
extern BOOL
EscPkcs1Oaep_Encrypt(
    const EscPkcs1Oaep_EncryptDataT* encryptData );

/**
Decrypts a message according to RSAEP-OAEP.
\see Section 7.1.2

\param[in] decryptData Parameters for decryption.

\return TRUE on error or if verification fails.
*/
extern BOOL
EscPkcs1Oaep_Decrypt(
    const EscPkcs1Oaep_DecryptDataT* decryptData );

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
