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
   \file        des_cbc.h

   \brief       DES implementation CBC mode
   \see FIPS PUB 46-3

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_DES_CBC_H_
#define _ESC_DES_CBC_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#include "des_ecb.h"

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

/** DES context CBC. */
typedef struct {
    /** Context in ECB mode. */
    EscDesEcb_ContextT ecbCtx;

    /** 64-bit initialization vector   */
    UINT8 iv[ EscDes_BLOCK_BYTES ];
} EscDesCbc_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
Initializes the CBC Context with the corresponding DES key and IV.

This function does not check the key for weaknesses nor does it
check the parity bits.

To check if a key is a known weak key, use the function EscDesKeytest_IsKeyWeak().
\see des_keytest.h

\param[out] cbcCtx The DES CBC context.
\param[in] key Key bytes array. Array of size EscDesCbc_KEY_BYTES.
\param[in] iv 64-bit initialization vector. Array of EscDes_BLOCK_BYTES bytes.

\return TRUE on error.
*/
extern BOOL
EscDesCbc_Init(
    EscDesCbc_ContextT* cbcCtx,
    const UINT8 key[],
    const UINT8 iv[] );

/**
Decrypts one or more data blocks and updates the DES context.

The context must be initialized with EscDesCbc_Init.
Plain pointer can be the same as cipher pointer.

\param[in] cbcCtx The previous DES CBC context.
\param[out] cbcCtx The updated DES CBC context.
\param[out] plain Will contain the plaintext after the function call.
\param[in] cipher Cipher data bytes array.
\param[in] length Length of plain and cipher data in bytes. Has to be multiple of EscDesCbc_BLOCK_BYTES bytes
           and not 0.

\return TRUE on error.
*/
extern BOOL
EscDesCbc_Decrypt(
    EscDesCbc_ContextT* cbcCtx,
    UINT8 plain[],
    const UINT8 cipher[],
    UINT32 length );

/**
Encrypts one or more data blocks and updates the DES context.

The context must be initialized with EscDesCbc_Init.

plain pointer can be the same as cipher pointer.

\param[in] cbcCtx The previous DES CBC context.
\param[out] cbcCtx The updated DES CBC context.
\param[in] plain Plaintext to encrypt.
\param[out] cipher Array to write ciphertext to.
\param[in] length Length of plain and cipher data in bytes. Has to be multiple of EscDesCbc_BLOCK_BYTES bytes
           and not 0.

\return TRUE on error.
*/
extern BOOL
EscDesCbc_Encrypt(
    EscDesCbc_ContextT* cbcCtx,
    UINT8 cipher[],
    const UINT8 plain[],
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
