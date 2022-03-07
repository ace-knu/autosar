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
   \file        sha_256.h

   \brief       SHA-224 and SHA-256 implementation also known as SHA-2.
   A maximum of 2^32-2 byte can be hashed.

   \see      FIPS-180-2 at
   http://csrc.nist.gov/publications/fips/fips180-2/fips180-2withchangenotice.pdf

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_SHA_256_H_
#define _ESC_SHA_256_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#include "cycurlib_config.h"

#ifdef  __cplusplus
/* *INDENT-OFF* */
extern "C" {
 /* *INDENT-ON* */
#endif

/***************************************************************************
 * 2. DEFINES                                                              *
 ***************************************************************************/

#ifndef EscSha256_IS_SHA224
#    if 0
/** Calculates SHA-224. Calculates SHA-256 if not defined. */
#        define EscSha256_IS_SHA224
#    endif
#endif

/** Length of digest in byte */
#ifdef EscSha256_IS_SHA224
#    define EscSha256_DIGEST_LEN 28U
#else
#    define EscSha256_DIGEST_LEN 32U
#endif

/** Length of one hash block in bytes */
#define EscSha256_BLOCK_BYTES 64U

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** Hash context for SHA-224 and SHA-256. */
typedef struct {
    /** Hash values H from FIPS-180-2. */
    UINT32 hash[ 8 ];
    /** Current block. */
    UINT8 block[ EscSha256_BLOCK_BYTES ];
    /** Number of bytes in block used. */
    UINT8 blockLen;
    /** Total length of the message in byte. */
    UINT32 totalLen;
} EscSha256_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
This function initializes the SHA values according to FIPS-180-2.

\see FIPS-180-2

\param[out] ctx pointer to SHA context.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscSha256_Init(
    EscSha256_ContextT* ctx );

/**
This function updates SHA context for a block of data.

\see FIPS-180-2

\param[in] ctx Pointer to input SHA context.
\param[out] ctx Pointer to updated SHA context.
\param[in] payload Pointer to input data chunk.
\param[in] dataLen Number of bytes of input data chunk.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscSha256_Update(
    EscSha256_ContextT* ctx,
    const UINT8 payload[],
    UINT32 dataLen );

/**
This function does the final wrapup and returns the hash.

\see FIPS-180-2

\param[in] ctx Pointer to last SHA context.
\param[out] ctx Pointer to updated SHA context.
\param[out] digest Pointer to EscSha256_DIGEST_LEN x 8-bit hash value.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscSha256_Finish(
    EscSha256_ContextT* ctx,
    UINT8 digest[] );

/**
This function calculates and returns a EscSha256_Calc hash.

\see FIPS-180-2

\param[in] payload Pointer to input data.
\param[in] dataLen Number of bytes of input data.
\param[out] digest Pointer to EscSha256_DIGEST_LEN x 8-bit hash value.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscSha256_Calc(
    const UINT8 payload[],
    UINT32 dataLen,
    UINT8 digest[] );

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
