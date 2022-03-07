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
   \file        pkcs1_rsaes_v15.h

   \brief       PKCS#1 v1.5 RSAES encryption and decryption

   Byteformat of all long numbers is Big-Endian.

   \see         ftp://ftp.rsasecurity.com/pub/pkcs/pkcs-1/pkcs-1v2-1.pdf


   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_PKCS1_RSAES_V15_H_
#define _ESC_PKCS1_RSAES_V15_H_

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

/* Everything below this line is not to be configured */

/** Number of bytes which will be padded as fixed bytes to the message */
#define EscPkcs1RsaEsV15_FIXED_PADDING_SIZE        3U
/** The minimum number of bytes which will be padded as random bytes to the message */
#define EscPkcs1RsaEsV15_MIN_RANDOM_PADDING_SIZE   8U
/** The minimum number of bytes which will be padded to the message */
#define EscPkcs1RsaEsV15_MIN_PADDING_SIZE          ( EscPkcs1RsaEsV15_MIN_RANDOM_PADDING_SIZE + EscPkcs1RsaEsV15_FIXED_PADDING_SIZE )
/** The maximum size of the plaintext message */
#define EscPkcs1RsaEsV15_MAX_MESSAGE_SIZE          ( EscRsa_KEY_BYTES - EscPkcs1RsaEsV15_MIN_PADDING_SIZE )

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** A public key */
typedef struct {
    /** Modulus */
    const UINT8 * modulus;

    /** Public exponent */
    UINT32 pubExp;
} EscPkcs1RsaEsV15_PubKeyT;

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
} EscPkcs1RsaEsV15_PrivKeyT;

/** Parameters for EscPkcsRsaEsV15_Encrypt */
typedef struct {
    /** Random context. */
    EscRandom_ContextT* randCtx;

    /** Message to be encrypted. */
    const UINT8 * message;

    /** Size of the message in bytes. */
    UINT16 messageLen;

    /** Public key structure. */
    const EscPkcs1RsaEsV15_PubKeyT * pubKey;

    /** Ciphertext of size EscRsa_KEY_BYTES. */
    UINT8* cipher;
} EscPkcs1RsaEsV15_EncryptDataT;

/** Parameters for EscPkcs1RsaEsV15_Decrypt */
typedef struct {
    /** Ciphertext of size EscRsa_KEY_BYTES to be decrypted. */
    const UINT8 * cipher;

    /** Decrypted message. */
    UINT8* message;

    /**
     * [in] Size of the message buffer in bytes. Must be at least 'EscPkcs1RsaEsV15_MAX_MESSAGE_SIZE'.
     * [out] Size of the message in bytes
     **/
    UINT16* messageLen;

    /** Private key structure. */
    const EscPkcs1RsaEsV15_PrivKeyT * privKey;
} EscPkcs1RsaEsV15_DecryptDataT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
Encrypts a message according to RSAES-PKCS#1 v1.5.
\see Section 7.2.1

\param[in] encryptData Parameters for encryption.

\return TRUE on error
*/

extern BOOL
EscPkcs1RsaEsV15_Encrypt(
    const EscPkcs1RsaEsV15_EncryptDataT* encryptData );
/**
Decrypts a message according to RSAES-PKCS#1 v1.5.
\see Section 7.2.2

\param[in] decryptData Parameters for decryption.

\return TRUE on error
*/
extern BOOL
EscPkcs1RsaEsV15_Decrypt(
    const EscPkcs1RsaEsV15_DecryptDataT* decryptData );

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
