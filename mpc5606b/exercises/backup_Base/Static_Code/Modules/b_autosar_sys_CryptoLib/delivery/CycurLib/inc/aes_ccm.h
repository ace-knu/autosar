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
   \file        aes_ccm.h

   \brief       AES implementation (FIPS-197 compliant)
                CCM-Mode (NIST Special Publication 800-38C)

   \see  NIST SP 800-38C


  $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_AES_CCM_H_
#define _ESC_AES_CCM_H_

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

/* Everything below this line is not to be configured */

/** Size of the used blocks - see NIST SP 800-38C */
#define EscAesCcm_BLOCKSIZE 16U

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** Context for the CCM parameters */
typedef struct {
    /** Pointer to key array */
    const UINT8* key;
    /** Pointer to plaintext array for encryption,
        pointer to ciphertext array for decryption */
    const UINT8* payload;
    /** Length of the payload in bytes. The value len_data can be
        presented in q bytes, where q can take the following values: 2, 3, 4.
        The maximum of q + len_nonce is 15 */
    UINT32 len_data;
    /** Pointer to nonce array */
    const UINT8* nonce;
    /** Length of the nonce in bytes. Can take the following values:
        7, 8, 9, 10, 11, 12, 13, whereby the maximum of q + len_nonce is 15 */
    UINT8 len_nonce;
    /** Pointer to associated data array */
    const UINT8* ad;
    /** Length of the associated data in bytes */
    UINT32 len_ad;
    /** Length of the MAC in byte. Can take the following values:
        4, 6, 8, 10, 12, 14, 16 */
    UINT8 len_mac;
} EscAesCcm_ParamsT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
Encrypts one or more data blocks.

params->payload points to plaintext and can be identical to the ciphertext pointer.

\param[in] params The AES CCM parameters.
\param[out] ciphertext Array to store ciphertext to.
            The array has to be at least (len_data + len_mac) bytes.

\return TRUE on error.
*/
extern BOOL
EscAesCcm_Encrypt(
    const EscAesCcm_ParamsT* params,
    UINT8 ciphertext[] );

/**
Decrypts one or more data blocks and check the appended MAC for validity.

Differently from the NIST SP the encrypted plaintext is written to the plain[]
array even if the MAC is not valid. Nevertheless, in such a case a TRUE, which
indicates an error, is returned.

params->payload points to ciphertext and can be identical to the plaintext pointer.

\param[in] params The AES CCM parameters.
\param[out] plaintext Array to store decrypted ciphertext to.
            The plaintext has a size of (len_data - len_mac) bytes.

\return TRUE on error or invalid MAC.
*/
extern BOOL
EscAesCcm_Decrypt(
    const EscAesCcm_ParamsT* params,
    UINT8 plaintext[] );

/***************************************************************************
 * 6. MACRO FUNCTIONS                                                      *
 ***************************************************************************/

#ifdef  __cplusplus
/* *INDENT-OFF* */
}
/* *INDENT-ON* */
#endif

#endif /* _ESC_AES_CCM_H_ */

/***************************************************************************
 * 7. END                                                                  *
 ***************************************************************************/
