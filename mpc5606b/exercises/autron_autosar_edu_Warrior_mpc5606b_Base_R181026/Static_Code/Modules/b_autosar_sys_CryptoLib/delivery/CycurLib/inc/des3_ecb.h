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
   \file        des3_ecb.h

   \brief       3-DES implementation ECB mode


   \see FIPS PUB 46-3



   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_DES3_ECB_H_
#define _ESC_DES3_ECB_H_

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

/** 3-DES context ECB. */
typedef struct {
    /** The key schedule for key K1. */
    EscDes_KeySchedT sched1;
    /** The key schedule for key K2. */
    EscDes_KeySchedT sched2;
    /** The key schedule for key K3. */
    EscDes_KeySchedT sched3;
} EscDes3Ecb_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
Initializes the ECB Context with the corresponding 3-DES key.

This function does not check the key for weaknesses nor does it
check the parity bits.

To check if a key is a known weak key, use the function EscDesKeytest_IsKeyWeak().
\see des_keytest.h

\param[out] ecbCtx The 3-DES ECB context.
\param[in] k1 TDEA K1. Key bytes array. Array of size EscDes_KEY_BYTES.
\param[in] k2 TDEA K2. Key bytes array. Array of size EscDes_KEY_BYTES.
\param[in] k3 TDEA K3. Key bytes array. Array of size EscDes_KEY_BYTES.

\return TRUE on error.
*/
extern BOOL
EscDes3Ecb_Init(
    EscDes3Ecb_ContextT* ecbCtx,
    const UINT8 k1[],
    const UINT8 k2[],
    const UINT8 k3[] );

/**
Encrypts one 3-DES block in ECB mode.

Performs the TDEA encryption operation:<BR>
I - DES_E_K1 - DES_D_K2 - DES_E_K3 - O

Block size is EscDes_BLOCK_BYTES.
The context must be initialized with EscDes3Ecb_Init.

The parameters plain and cipher can point to the same location.

\param[in] ecbCtx Context initialized with EscDes3Ecb_Init.
\param[out] cipher Encrypted plaintext. Must be exactly EscDes_BLOCK_BYTES bytes.
\param[in] plain Plaintext to encrypt. Must be exactly EscDes_BLOCK_BYTES bytes.

\return TRUE on error.
*/
extern BOOL
EscDes3Ecb_Encrypt(
    const EscDes3Ecb_ContextT* ecbCtx,
    UINT8 cipher[],
    const UINT8 plain[] );

/**
Decrypts one 3-DES block in ECB mode.

Performs the TDEA encryption operation:<BR>
I - DES_D_K3 - DES_E_K2 - DES_D_K1 - O

Block size is EscDes_BLOCK_BYTES.
The context must be initialized with EscDes3Ecb_Init.

The parameters plain and cipher can point to the same location.

\param[in] ecbCtx Context initialized with EscDes3Ecb_Init.
\param[out] plain Decrypted ciphertext. Must be exactly EscDes_BLOCK_BYTES bytes.
\param[in] cipher Ciphertext to decrypt. Must be exactly EscDes_BLOCK_BYTES bytes.

\return TRUE on error.
*/
extern BOOL
EscDes3Ecb_Decrypt(
    const EscDes3Ecb_ContextT* ecbCtx,
    UINT8 plain[],
    const UINT8 cipher[] );

/**
Encrypts one 3-DES block in ECB mode.

Performs the TDEA encryption operation:<BR>
I - DES_E_K1 - DES_D_K2 - DES_E_K3 - O

Block size is EscDes_BLOCK_BYTES.
The context must be initialized with EscDes3Ecb_Init.

The parameters plain and cipher can point to the same location.

This function performs no parameter check and is intended for internal use.

\param[in] ecbCtx Context initialized with EscDes3Ecb_Init.
\param[out] cipher Encrypted plaintext. Must be exactly EscDes_BLOCK_BYTES bytes.
\param[in] plain Plaintext to encrypt. Must be exactly EscDes_BLOCK_BYTES bytes.
*/
extern void
EscDes3Ecb_EncryptFast(
    const EscDes3Ecb_ContextT* ecbCtx,
    UINT8 cipher[],
    const UINT8 plain[] );

/**
Decrypts one 3-DES block in ECB mode.

Performs the TDEA encryption operation:<BR>
I - DES_D_K3 - DES_E_K2 - DES_D_K1 - O

Block size is EscDes_BLOCK_BYTES.
The context must be initialized with EscDes3Ecb_Init.

The parameters plain and cipher can point to the same location.

This function performs no parameter check and is intended for internal use.

\param[in] ecbCtx Context initialized with EscDes3Ecb_Init.
\param[out] plain Decrypted ciphertext. Must be exactly EscDes_BLOCK_BYTES bytes.
\param[in] cipher Ciphertext to decrypt. Must be exactly EscDes_BLOCK_BYTES bytes.
*/
extern void
EscDes3Ecb_DecryptFast(
    const EscDes3Ecb_ContextT* ecbCtx,
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
