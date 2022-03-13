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
   \file        aes_gcm.h

   \brief       AES-GCM implementation (Galois/Counter Mode)

   \see NIST Special Publication 800-38D
   http://csrc.nist.gov/publications/nistpubs/800-38D/SP-800-38D.pdf

   \see _aes.h

   The following papers and standards are referenced:
   - The Galois/Counter Mode of Operation (GCM), David A. McGrew and John Viega

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_AES_GCM_H_
#define _ESC_AES_GCM_H_

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

/** Context in GCM mode for encryption. */
typedef struct {
    /** Pointer to key array */
    const UINT8 * key;
    /** Pointer to aad array */
    const UINT8 * aad;
    /** Length of the additional authentication data in bytes */
    UINT32 len_aad;
    /** Pointer to plaintext array for encryption,
       Pointer to ciphertext array for decryption */
    const UINT8 * payload;
    /** Length of the payload in bytes */
    UINT32 len_data;
    /** Pointer to initialization vector */
    const UINT8 * iv;
    /** Length of the iv in bytes */
    UINT32 len_iv;
} EscAesGcm_ParamsT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
Encrypts one or more data blocks.

params->payload points to plaintext and can be identical to
the cipher pointer.

\param[in] params The AES GCM parameters.
\param[out] cipher Array to write ciphertext to. Has to be the same size as the plaintext array.
\param[out] t Calculated Authentication tag with a size of 16 bytes.

\return TRUE on error.
*/

extern BOOL
EscAesGcm_Encrypt(
    const EscAesGcm_ParamsT* params,
    UINT8 cipher[],
    UINT8 t[] );

/**
Decrypts one or more data blocks.

params->payload points to ciphertext and can be identical to
the plain pointer.

\param[in] params The AES GCM parameters.
\param[out] plain Array to write decrypted ciphertext to. Has to be the same size of the ciphertext array
\param[in] t Authentication Tag of 16 bytes to verify.

\return TRUE on error.
*/

extern BOOL
EscAesGcm_Decrypt(
    const EscAesGcm_ParamsT* params,
    UINT8 plain[],
    const UINT8 t[] );

/***************************************************************************
 * 6. MACRO FUNCTIONS                                                      *
 ***************************************************************************/

#ifdef  __cplusplus
/* *INDENT-OFF* */
}
/* *INDENT-ON* */
#endif

#endif /* _ESC_AES_GCM_H_ */

/***************************************************************************
 * 7. END                                                                  *
 ***************************************************************************/
