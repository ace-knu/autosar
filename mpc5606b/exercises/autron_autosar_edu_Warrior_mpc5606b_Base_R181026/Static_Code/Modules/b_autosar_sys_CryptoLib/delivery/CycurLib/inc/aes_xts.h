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
   \file        aes_xts.h

   \brief       AES-XTS implementation

   \see IEEE 1619

   Key sizes of 128 and 256 bits are allowed.

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_AES_XTS_H_
#    define _ESC_AES_XTS_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#    include "aes_ecb.h"

/* Parameter checks. */
#    if ( EscAes_KEY_BITS == 128U ) || ( EscAes_KEY_BITS == 256U )

#        ifdef  __cplusplus
/* *INDENT-OFF* */
extern "C" {
 /* *INDENT-ON* */
#        endif

/***************************************************************************
 * 2. DEFINES                                                              *
 ***************************************************************************/

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** AES context in XTS mode. */
typedef struct {
    /** Context in ECB mode. */
    EscAesEcb_ContextT ecbCtx1;

    /** Context in ECB mode. */
    EscAesEcb_ContextT ecbCtx2;
} EscAesXts_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/
/**
Initializes the AES-XTS Context with the corresponding AES keys.

\param[out] xtsCtx The AES XTS context.
\param[in] key1 Key bytes array. Array of size EscAes_KEY_BYTES.
\param[in] key2 Key bytes array. Array of size EscAes_KEY_BYTES.

\return TRUE on error.
*/
extern BOOL
EscAesXts_Init(
    EscAesXts_ContextT* xtsCtx,
    const UINT8 key1[],
    const UINT8 key2[] );

/**
Decrypts one data unit (i.e., sector).

The context must be initialized with EscAesXts_Init.

\param[in] xtsCtx initialized AES XTS context.
\param[in] cipher Ciphertext to decrypt.
\param[out] plain Array to write plaintext to encrypt.
\param[in] length Length of plain and cipher data in bytes. Has to be at least EscAes_BLOCK_BYTES bytes.
\param[in] tweak tweak value. Array of size EscAes_BLOCK_BYTES.

\return TRUE on error.
*/
extern BOOL
EscAesXts_Decrypt(
    const EscAesXts_ContextT* xtsCtx,
    const UINT8 cipher[],
    UINT8 plain[],
    UINT32 length,
    const UINT8 tweak[] );

#        ifdef Esc_HAS_INT64
/**
Decrypts one data unit (i.e., sector) based on the sector number.

The context must be initialized with EscAesXts_Init.

plain pointer and cipher pointer may not overlap.

\param[in] xtsCtx initialized AES XTS context.
\param[in] cipher Ciphertext to decrypt.
\param[out] plain Array to write plaintext to encrypt.
\param[in] length Length of plain and cipher data in bytes. Has to be at least EscAes_BLOCK_BYTES bytes.
\param[in] data_unit_number sector number.

\return TRUE on error.
*/
extern BOOL
EscAesXts_DecryptSector(
    const EscAesXts_ContextT* xtsCtx,
    const UINT8 cipher[],
    UINT8 plain[],
    UINT32 length,
    UINT64 data_unit_number );

#        endif

/**
Encrypts one data unit (i.e., sector).

The context must be initialized with EscAesXts_Init.

\param[in] xtsCtx initialized AES XTS context.
\param[in] plain Plaintext to encrypt.
\param[out] cipher Array to write ciphertext to.
\param[in] length Length of plain and cipher data in bytes. Has to be at least EscAes_BLOCK_BYTES bytes.
\param[in] tweak tweak value. Array of size EscAes_BLOCK_BYTES.

\return TRUE on error.
*/
extern BOOL
EscAesXts_Encrypt(
    const EscAesXts_ContextT* xtsCtx,
    const UINT8 plain[],
    UINT8 cipher[],
    UINT32 length,
    const UINT8 tweak[] );

#        ifdef Esc_HAS_INT64
/**
Encrypts one data unit (i.e., sector) based on the sector number.

The context must be initialized with EscAesXts_Init.

plain pointer and cipher pointer may not overlap.

\param[in] xtsCtx initialized AES XTS context.
\param[in] plain Plaintext to encrypt.
\param[out] cipher Array to write ciphertext to.
\param[in] length Length of plain and cipher data in bytes. Has to be at least EscAes_BLOCK_BYTES bytes.
\param[in] data_unit_number sector number.

\return TRUE on error.
*/
extern BOOL
EscAesXts_EncryptSector(
    const EscAesXts_ContextT* xtsCtx,
    const UINT8 plain[],
    UINT8 cipher[],
    UINT32 length,
    UINT64 data_unit_number );

#        endif

/***************************************************************************
 * 6. MACRO FUNCTIONS                                                      *
 ***************************************************************************/

#        ifdef  __cplusplus
/* *INDENT-OFF* */
}
/* *INDENT-ON* */
#        endif

#    endif

#endif
/***************************************************************************
 * 7. END                                                                  *
 ***************************************************************************/
