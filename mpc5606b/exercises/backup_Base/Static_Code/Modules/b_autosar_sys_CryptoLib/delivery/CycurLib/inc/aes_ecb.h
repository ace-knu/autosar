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
   \file        aes_ecb.h

   \brief       AES implementation (FIPS-197 compliant)
   ECB-Mode

   \see FIPS-197

   Key sizes of 128, 192 and 256 bits are allowed.

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_AES_ECB_H_
#define _ESC_AES_ECB_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#include "_aes.h"

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
/** AES context ECB. */
typedef struct {
    /** Encryption round keys */
    UINT32 round_keys[ ( EscAes_Nr + 1U ) * 4U ];
#if ( defined( EscAes_USE_T_TABLES_SMALL ) || defined( EscAes_USE_T_TABLES_FULL ) )
    UINT32 dec_keys[ ( EscAes_Nr + 1U ) * 4U ];
#endif
} EscAesEcb_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
Initializes the ECB Context with the corresponding AES key.

\param[out] ecbCtx The AES ECB context.
\param[in] key Key bytes array. Array of size EscAes_KEY_BYTES.

\return TRUE on error.
*/
extern BOOL
EscAesEcb_Init(
    EscAesEcb_ContextT* ecbCtx,
    const UINT8 key[] );

/**
Encrypts one AES block in ECB mode.

Block size is EscAes_BLOCK_BYTES.
The context must be initialized with EscAesEcb_Init.

The parameters plain and cipher can point to the same location.

\param[in] ecbCtx Context initialized with EscAesEcb_Init.
\param[in] plain Plaintext to encrypt. Must be exactly EscAes_BLOCK_BYTES bytes.
\param[out] cipher Encrypted plaintext. Must be exactly EscAes_BLOCK_BYTES bytes.

\return TRUE on error.
*/
extern BOOL
EscAesEcb_Encrypt(
    const EscAesEcb_ContextT* ecbCtx,
    const UINT8 plain[],
    UINT8 cipher[] );

/**
Decrypts one AES block in ECB mode.

Block size is EscAes_BLOCK_BYTES.
The context must be initialized with EscAesEcb_Init.

The parameters plain and cipher can point to the same location.

\param[in] ecbCtx Context initialized with EscAesEcb_Init.
\param[in] cipher Ciphertext to decrypt. Must be exactly EscAes_BLOCK_BYTES bytes.
\param[out] plain Decrypted ciphertext. Must be exactly EscAes_BLOCK_BYTES bytes.

\return TRUE on error.
*/
extern BOOL
EscAesEcb_Decrypt(
    const EscAesEcb_ContextT* ecbCtx,
    const UINT8 cipher[],
    UINT8 plain[] );

/**
Encrypts one AES block in ECB mode.

Block size is EscAes_BLOCK_BYTES.
The context must be initialized with EscAesEcb_Init.

The parameters plain and cipher can point to the same location.

This function performs no parameter check and is intended for internal use.

\param[in] ecbCtx Context initialized with EscAesEcb_Init.
\param[in] plain Plaintext to encrypt. Must be exactly EscAes_BLOCK_BYTES bytes.
\param[out] cipher Encrypted plaintext. Must be exactly EscAes_BLOCK_BYTES bytes.
*/
extern void
EscAesEcb_EncryptFast(
    const EscAesEcb_ContextT* ecbCtx,
    const UINT8 plain[],
    UINT8 cipher[] );

/**
Decrypts one AES block in ECB mode.

Block size is EscAes_BLOCK_BYTES.
The context must be initialized with EscAesEcb_Init.

The parameters plain and cipher can point to the same location.

This function performs no parameter check and is intended for internal use.

\param[in] ecbCtx Context initialized with EscAesEcb_Init.
\param[in] cipher Ciphertext to decrypt. Must be exactly EscAes_BLOCK_BYTES bytes.
\param[out] plain Decrypted ciphertext. Must be exactly EscAes_BLOCK_BYTES bytes.
*/
extern void
EscAesEcb_DecryptFast(
    const EscAesEcb_ContextT* ecbCtx,
    const UINT8 cipher[],
    UINT8 plain[] );

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
