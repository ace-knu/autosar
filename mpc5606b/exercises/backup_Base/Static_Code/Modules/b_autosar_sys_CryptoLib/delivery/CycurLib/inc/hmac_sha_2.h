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
   \file        hmac_sha_2.h

   \brief       HMAC-SHA-2 implementation, according to FIPS-180-2 and RFC 2104

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_HMAC_SHA_256_H_
#define _ESC_HMAC_SHA_256_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#include "sha_256.h"

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
/** Hash context for SHA-2 */
typedef struct {
    /** SHA-2 hash context */
    EscSha256_ContextT sha_ctx;

    /**
    this buffer holds the hmac key - the key will be hashed during the
    initialisation when it's length is greater than EscSha256_BLOCK_BYTES bytes.
    */
    UINT8 hmac_key[ EscSha256_BLOCK_BYTES ];

    /** Length of the hmac_key */
    UINT8 hmac_key_length;
} EscHmacSha256_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
This function initializes the HMAC-SHA-2 values.

\param[in] hmac_ctx Pointer to hash context.
\param[in] key Pointer to hmac key.
\param[in] key_length Length of hmac key. Must be at least 1 byte.
\param[out] hmac_ctx Updated hash context.

\return TRUE on error.
*/
extern BOOL
EscHmacSha256_Init(
    EscHmacSha256_ContextT* hmac_ctx,
    const UINT8 key[],
    UINT32 key_length );

/**
This function updates hash context for a block of data

\param[in] hmac_ctx Pointer to input HMAC SHA2 context.
\param[in] chunk_data Pointer to input data chunk.
\param[in] chunk_length Length in number of bytes of input data chunk.
\param[out] hmac_ctx Pointer to updated SHA2 context.

\return TRUE on error.
*/
extern BOOL
EscHmacSha256_Update(
    EscHmacSha256_ContextT* hmac_ctx,
    const UINT8 chunk_data[],
    UINT32 chunk_length );

/**
This function does the final wrapup and returns the hash

\param[in] hmac_ctx Pointer to last hash context.
\param[out] hmac_hash Array with EscSha256_DIGEST_LEN bytes.

\return TRUE on error.
*/
extern BOOL
EscHmacSha256_Finish(
    EscHmacSha256_ContextT* hmac_ctx,
    UINT8 hmac_hash[] );

/**
Calculate HMAC based on SHA-2 for the input data

\see     RFC 2104
\see     FIPS-180-2

\param[in] key Secret MAC key.
\param[in] key_length Length of key in bytes. Must be at least 1 byte.
\param[in] payload Data to be hashed.
\param[in] data_length Length of data in bytes.
\param[out] hmac_hash Array with EscSha256_DIGEST_LEN bytes.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscHmacSha256_Calc(
    const UINT8 key[],
    UINT32 key_length,
    const UINT8 payload[],
    UINT32 data_length,
    UINT8 hmac_hash[] );

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
