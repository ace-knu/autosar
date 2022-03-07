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
   \file        aes_cbc.h

   \brief       AES implementation (FIPS-197 compliant)
   CBC-Mode

   \see FIPS-197

   Key sizes of 128, 192 and 256 bits are allowed.

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_AES_CBC_H_
#define _ESC_AES_CBC_H_

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
/** AES context in CBC mode. */
typedef struct {
    /** Context in ECB mode. */
    EscAesEcb_ContextT ecbCtx;

    /** 128-bit initialization vector   */
    UINT8 iv[ EscAes_BLOCK_BYTES ];
} EscAesCbc_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/
/**
Initializes the CBC Context with the corresponding AES key and IV.

\param[out] cbcCtx The AES CBC context.
\param[in] key Key bytes array. Array of size EscAes_KEY_BYTES.
\param[in] iv 128-bit initialization vector. Array of EscAes_IV_BYTES bytes.

\return TRUE on error.
*/
extern BOOL
EscAesCbc_Init(
    EscAesCbc_ContextT* cbcCtx,
    const UINT8 key[],
    const UINT8 iv[] );

/**
Decrypts one or more data blocks and updates the AES context.

The context must be initialized with EscAesCbc_Init.
Plain pointer can be the same as cipher pointer.

\param[in] cbcCtx The previous AES CBC context.
\param[out] cbcCtx The updated AES CBC context.
\param[out] plain Will contain the plaintext after the function call.
\param[in] cipher Cipher data bytes array.
\param[in] length Length of plain and cipher data in bytes. Has to be multiple of EscAes_BLOCK_BYTES bytes
           and not 0.

\return TRUE on error.
*/
extern BOOL
EscAesCbc_Decrypt(
    EscAesCbc_ContextT* cbcCtx,
    UINT8 plain[],
    const UINT8 cipher[],
    UINT32 length );

/**
Encrypts one or more data blocks and updates the AES context.

The context must be initialized with EscAesCbc_Init.

plain pointer can be the same as cipher pointer.

\param[in] cbcCtx The previous AES CBC context.
\param[out] cbcCtx The updated AES CBC context.
\param[in] plain Plaintext to encrypt.
\param[out] cipher Array to write ciphertext to.
\param[in] length Length of plain and cipher data in bytes. Has to be multiple of EscAes_BLOCK_BYTES bytes
           and not 0.

\return TRUE on error.
*/
extern BOOL
EscAesCbc_Encrypt(
    EscAesCbc_ContextT* cbcCtx,
    const UINT8 plain[],
    UINT8 cipher[],
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
