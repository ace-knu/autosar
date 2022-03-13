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
   \file        ecies.h

   \brief       ECIES implementation according to the IEEE Std 1363a

   \see  IEEE Std 1363-2000 and IEEE Std 1363a
         All quoted references refer to the IEEE standard

   KDF (KDF2) + XOR Encryption is used.
   DHAES and NON-DHAES Mode is supported
   SHA-1 and SHA-256 is supported for KDF and HMAC
   EscEcc_ECDH_DISABLE in ecc.h must not be defined!

  $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_ECIES_H_
#define _ESC_ECIES_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#include "ecc.h"

#ifndef EscEcc_ECDH_DISABLE

#ifdef  __cplusplus
/* *INDENT-OFF* */
extern "C" {
/* *INDENT-ON* */
#endif

/***************************************************************************
 * 2. DEFINES                                                              *
 ***************************************************************************/

/** Enables the SHA-1 */
#define EscEcies_USE_SHA1 1U

/** Enables the SHA-256 */
#define EscEcies_USE_SHA256 2U

/* User definable configuration */

#ifndef EscEcies_PLAIN_LEN
    /** Set the plaintext length */
#   define EscEcies_PLAIN_LEN 16U
#endif

#ifndef EscEcies_DHAES_DISABLE
#   if 0
        /**
         * Enable NON-DHAES Mode for compatibility with ANSI X9.63.
         * In this mode the scheme is malleable and is not secure against an
         * adaptively chosen ciphertext attack (CCA2) (see D.5.3.3 - Note 1)
         **/
#       define EscEcies_DHAES_DISABLE
#   endif
#endif

#ifndef EscEcies_HASH_TYPE
/** Determines the hash algorithm for the key derivation function and the HMAC.
    Supported values:
    - EscEcies_USE_SHA1
    - EscEcies_USE_SHA256

    Since SHA-224 is not supported in IEEE Std 1363a,
    EscSha256_IS_SHA224 must not be defined in sha_256.h */
#    define EscEcies_HASH_TYPE EscEcies_USE_SHA1
#endif

#ifndef EscEcies_MAC_KEY_BYTES
    /** Set the used key length for the MAC tag in bytes */
#   define EscEcies_MAC_KEY_BYTES 16U
#endif


/* Everything below this line is not to be configured */

#if (EscEcies_HASH_TYPE == EscEcies_USE_SHA1)
#    include "sha_1.h"
#    include "hmac_sha_1.h"
     /** Length of the output of one hash operation (depends on the used hash algorithm) */
#    define EscEcies_HASH_LEN EscSha1_DIGEST_LEN
     /** Length of the MAC Tag */
#    define EscEcies_MAC_TAG_LEN EscSha1_DIGEST_LEN
#elif (EscEcies_HASH_TYPE == EscEcies_USE_SHA256)
#   include "sha_256.h"
#   ifdef EscSha256_IS_SHA224
#       error SHA-224 is not supported in IEEE Std 1363a
#   endif
#   include "hmac_sha_2.h"

    /** Length of the output of one hash operation (depends on the used hash algorithm) */
#   define EscEcies_HASH_LEN EscSha256_DIGEST_LEN
    /** Length of the MAC Tag */
#   define EscEcies_MAC_TAG_LEN EscSha256_DIGEST_LEN
#else
#   error "EscEcies_HASH_TYPE is not supported!"
#endif

/** Length of the encoded ECC public key */
#define EscEcies_PUBLIC_KEY_LEN ( ( 2U * ECC_KEY_BYTES ) + 1U )

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/
/** ECIES context. */
typedef struct {
    /** Encryption/Decryption Counter for the KDF Parameter */
    UINT32 counter;
    /** senders public key */
    EscEcc_PublicKeyT pubKey;
    /** The shared secret which will be computed with the senders private
        and the receivers public key */
#ifndef EscEcies_DHAES_DISABLE
    UINT8 sharedSecret[ EscEcies_PUBLIC_KEY_LEN + ECC_KEY_BYTES ];
#else
    UINT8 sharedSecret[ ECC_KEY_BYTES ];
#endif
} EscEcies_ContextT;
/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/
/**
Validate public key, init the encryption counter, generate the sender's key pair

\param[out] ctx The ECIES context.
\param[in] recPublicKey The Receiver's public key. The key is validated by this function. 
\param[in] privKey The private key of the sender. Has to be a one-time key with the size of ECC_KEY_BYTES.
           For more information about the generation of private keys see D.3.1 and D.4.1.4 - note 7

\return TRUE on error.
 */
extern BOOL
EscEcies_Init_Encrypt(
    EscEcies_ContextT* ctx,
    const EscEcc_PublicKeyT* recPublicKey,
    const UINT8 privKey[] );

/**
Init decryption counter and compute the shared secret

\param[out] ctx The ECIES context.
\param[in] ciphertext The ciphertext with the encoded public key of the sender
\param[in] privKey The private Key of the receiver.

\return TRUE on error.
 */
BOOL
EscEcies_Init_Decrypt(
    EscEcies_ContextT* ctx,
    const UINT8 ciphertext[],
    const UINT8 privKey[] );

/**
Encrypts one data block.
This implementation uses the KDF parameters as an encryption counter as proposed in 11.3.2 - Note 1 and D.5.3.3

\param[in] ctx The ECIES context.
\param[in] plaintext The plaintext.
\param[out] ciphertext Array to store ciphertext. Has to be the size of the
            plaintext length (EscEcies_PLAIN_LEN) plus the size of the MAC (EscEcies_MAC_TAG_LEN) plus
            the size of one encoded public key (EscEcies_PUBLIC_KEY_LEN).
            MAC sizes:
            HMAC with SHA-1 : 20 bytes  (EscSha1_DIGEST_LEN)
            HMAC with SHA-256: 32 bytes (EscSha256_DIGEST_LEN)

\return TRUE on error.
*/
extern BOOL EscEcies_Encrypt(
    EscEcies_ContextT* ctx,
    const UINT8 plaintext[],
    UINT8 ciphertext[] );

/**
Decrypts one data block and check the appended MAC for validity. Multiple ciphertext blocks must be
decrypted in the same order as the encryption took place.
This implementation uses the KDF parameters as an encryption counter as proposed in 11.3.2 - Note 1 and D.5.3.3

\param[in] ctx The ECIES context.
\param[in] ciphertext The ciphertext.
\param[out] plaintext Array to store the plaintext. Has to be the size of the
            ciphertext minus the size of the MAC (EscEcies_MAC_TAG_LEN) minus
            the size of one encoded public key (EscEcies_PUBLIC_KEY_LEN).
            MAC sizes:
            HMAC with SHA-1 : 20 bytes  (EscSha1_DIGEST_LEN)
            HMAC with SHA-256: 32 bytes (EscSha256_DIGEST_LEN)

\return TRUE on error or invalid MAC.
*/
extern BOOL EscEcies_Decrypt(
    EscEcies_ContextT* ctx,
    const UINT8 ciphertext[],
    UINT8 plaintext[] );


/* SINGLE BLOCK ENCRYPTION/DECRYPTION */

/**
Encrypts one data block. Since this function does not use the KDF parameters, the resulting ciphertext
is not compatible with the EscEcies_Decrypt function. The output has to be decrypted with EscEcies_Decrypt_Single.

\param[in] plaintext The plaintext.
\param[out] ciphertext Array to store ciphertext. Has to be the size of the
            plaintext length plus the size of the MAC (EscEcies_MAC_TAG_LEN) plus
            (((ECC_KEY_BYTES * 2) + 1 byte) (for the encoded public key of the sender).
            MAC sizes:
            HMAC with SHA-1 : 20 bytes  (EscSha1_DIGEST_LEN)
            HMAC with SHA-256: 32 bytes (EscSha256_DIGEST_LEN)
\param[in] recPublicKey The Receiver's public key. The key is validated by this function.
\param[in] privKey The private Key of the sender. Has to be a one-time key with the size of ECC_KEY_BYTES.
           For more information about the generation of private keys see D.3.1 and D.4.1.4 - note 7

\return TRUE on error.
*/
extern BOOL EscEcies_Encrypt_Single(
    const UINT8 plaintext[],
    UINT8 ciphertext[],
    const EscEcc_PublicKeyT* recPublicKey,
    const UINT8 privKey[] );

/**
Decrypts one data block and check the appended MAC for validity. Since this function does not use the KDF
parameters, the ciphertext has to be encrypted with the the EscEcies_Encrypt_Single function.

\param[in] ciphertext The ciphertext.
\param[out] plaintext Array to store the plaintext. Has to be the size of the
            ciphertext minus the size of the MAC (EscEcies_MAC_TAG_LEN) minus
            (((ECC_KEY_BYTES * 2) + 1 byte) (for the encoded public key of the sender).
            MAC sizes:
            HMAC with SHA-1 : 20 bytes  (EscSha1_DIGEST_LEN)
            HMAC with SHA-256: 32 bytes (EscSha256_DIGEST_LEN)
\param[in] privKey The private Key of the receiver.

\return TRUE on error or invalid MAC.
*/
extern BOOL EscEcies_Decrypt_Single(
    const UINT8 ciphertext[],
    UINT8 plaintext[],
    const UINT8 privKey[] );

/***************************************************************************
 * 6. MACRO FUNCTIONS                                                      *
 ***************************************************************************/

#ifdef  __cplusplus
/* *INDENT-OFF* */
}
/* *INDENT-ON* */
#endif

#endif /* EscEcc_ECDH_DISABLE */

#endif /* _ESC_ECIES_H_ */

/***************************************************************************
 * 7. END                                                                  *
 ***************************************************************************/
