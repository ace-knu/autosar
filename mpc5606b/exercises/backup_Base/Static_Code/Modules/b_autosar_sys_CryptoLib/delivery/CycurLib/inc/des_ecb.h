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
   \file        des_ecb.h

   \brief       DES implementation ECB mode
   \see FIPS PUB 46-3

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_DES_ECB_H_
#define _ESC_DES_ECB_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#include "_des.h"

#ifdef  __cplusplus
/* *INDENT-OFF* */
extern "C" {
 /* *INDENT-ON* */
#endif

/***************************************************************************
 * 2. DEFINES                                                              *
 ***************************************************************************/
/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** DES context ECB. */
typedef struct {
    /** The key schedule. */
    EscDes_KeySchedT sched;
} EscDesEcb_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
Initializes the ECB Context with the corresponding DES key.

This function does not check the key for weaknesses nor does it
check the parity bits.

To check if a key is a known weak key, use the function EscDesKeytest_IsKeyWeak().
\see des_keytest.h

\param[out] ecbCtx The DES ECB context.
\param[in] key Key bytes array. Array of size EscDes_KEY_BYTES.

\return TRUE on error.
*/
extern BOOL
EscDesEcb_Init(
    EscDesEcb_ContextT* ecbCtx,
    const UINT8 key[] );

/**
Encrypts one DES block in ECB mode.

Block size is EscDes_BLOCK_BYTES.
The context must be initialized with EscDesEcb_Init.

The parameters plain and cipher can point to the same location.

\param[in] ecbCtx Context initialized with EscDesEcb_Init.
\param[out] cipher Encrypted plaintext. Must be exactly EscDes_BLOCK_BYTES bytes.
\param[in] plain Plaintext to encrypt. Must be exactly EscDes_BLOCK_BYTES bytes.

\return TRUE on error.
*/
extern BOOL
EscDesEcb_Encrypt(
    const EscDesEcb_ContextT* ecbCtx,
    UINT8 cipher[],
    const UINT8 plain[] );

/**
Decrypts one DES block in ECB mode.

Block size is EscDes_BLOCK_BYTES.
The context must be initialized with EscDesEcb_Init.

The parameters plain and cipher can point to the same location.

\param[in] ecbCtx Context initialized with EscDesEcb_Init.
\param[out] plain Decrypted ciphertext. Must be exactly EscDes_BLOCK_BYTES bytes.
\param[in] cipher Ciphertext to decrypt. Must be exactly EscDes_BLOCK_BYTES bytes.

\return TRUE on error.
*/
extern BOOL
EscDesEcb_Decrypt(
    const EscDesEcb_ContextT* ecbCtx,
    UINT8 plain[],
    const UINT8 cipher[] );

/**
Encrypts one DES block in ECB mode.

Block size is EscDes_BLOCK_BYTES.
The context must be initialized with EscDesEcb_Init.

The parameters plain and cipher can point to the same location.

This function performs no parameter check and is intended for internal use.

\param[in] ecbCtx Context initialized with EscDesEcb_Init.
\param[out] cipher Encrypted plaintext. Must be exactly EscDes_BLOCK_BYTES bytes.
\param[in] plain Plaintext to encrypt. Must be exactly EscDes_BLOCK_BYTES bytes.
*/
extern void
EscDesEcb_EncryptFast(
    const EscDesEcb_ContextT* ecbCtx,
    UINT8 cipher[],
    const UINT8 plain[] );

/**
Decrypts one DES block in ECB mode.

Block size is EscDes_BLOCK_BYTES.
The context must be initialized with EscDesEcb_Init.

The parameters plain and cipher can point to the same location.

This function performs no parameter check and is intended for internal use.

\param[in] ecbCtx Context initialized with EscDesEcb_Init.
\param[out] plain Decrypted ciphertext. Must be exactly EscDes_BLOCK_BYTES bytes.
\param[in] cipher Ciphertext to decrypt. Must be exactly EscDes_BLOCK_BYTES bytes.
*/
extern void
EscDesEcb_DecryptFast(
    const EscDesEcb_ContextT* ecbCtx,
    UINT8 plain[],
    const UINT8 cipher[] );

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
