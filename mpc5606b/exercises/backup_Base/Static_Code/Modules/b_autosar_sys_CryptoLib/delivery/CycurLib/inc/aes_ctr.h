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
   \file        aes_ctr.h

   \brief       AES implementation (FIPS-197 compliant)
   CTR mode

   \see FIPS-197

   Key sizes of 128, 192 and 256 bits are allowed.

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_AES_CTR_H_
#define _ESC_AES_CTR_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#include "aes_ecb.h"

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
/** AES context in CTR mode. */
typedef struct {
    /** Context in ECB mode. */
    EscAesEcb_ContextT ecbCtx;

    /** The length of the counter in byte. The counter will wrap around
        to 0x0, if it exceeds 2^8 counterBytes.
    */
    UINT8 counterBytes;

    /** 128-bit initialization vector. */
    UINT8 iv[ EscAes_BLOCK_BYTES ];
} EscAesCtr_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/
/**
Initializes the CTR Context with the corresponding AES key.

The form of the IV is nonce|counter.

The nonce consists of the IVs bytes at indices 0..(nonceLength-1).
The IV bytes at indices nonceLength..(EscAes_IV_BYTES-1) set the initial
counter value having the least significant byte at position EscAes_IV_BYTES-1.


\param[out] ctrCtx The AES CTR context.
\param[in] key Key bytes array. Array of size EscAes_KEY_BYTES.
\param[in] iv IV consisting of the nonce and the initial counter value. Length must be EscAes_IV_BYTES.
\param[in] nonceLength The length of the nonce in byte. Can be 0..EscAes_IV_BYTES-1.

\return TRUE on error.
*/
extern BOOL
EscAesCtr_Init(
    EscAesCtr_ContextT* ctrCtx,
    const UINT8 key[],
    const UINT8 iv[],
    UINT8 nonceLength );

/**
Applies AES CTR mode to the data.

The same function can be applied for encryption and decryption.

For encryption, source is the plaintext and dest the resulting ciphertext.

For Decryption, source is the ciphertext and dest the resulting plaintext.
Decrypts one or more data blocks in CTR mode and updates the AES context.

The context must be initialized with EscAesCtr_Init.

\attention The source and the dest pointer must point to non overlapping memory.

\param[in] ctrCtx The previous AES CTR context.
\param[out] ctrCtx The updated AES CTR context.
\param[in] source Plaintext for encryption, ciphertext for encryption.
\param[out] dest Ciphertext for encryption, plaintext for decryption.
\param[in] length Length of plain and cipher data in bytes. Has to be multiple of EscAes_BLOCK_BYTES bytes
           and not 0.

\return TRUE on error.
*/
extern BOOL
EscAesCtr_Apply(
    EscAesCtr_ContextT* ctrCtx,
    const UINT8 source[],
    UINT8 dest[],
    UINT32 length );

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
