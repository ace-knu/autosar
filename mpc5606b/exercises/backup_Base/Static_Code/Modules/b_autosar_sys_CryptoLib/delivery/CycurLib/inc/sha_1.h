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
   \file        sha_1.h

   \brief       SHA-1 implementation (FIPS-180-2 resp. RFC 2202 compliant)
   A maximum of 2^32-2 Byte can be hashed.

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_SHA_1_H_
#define _ESC_SHA_1_H_

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

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** Length of digest in byte. */
#define EscSha1_DIGEST_LEN 20U

/** Length of one hash block in bytes. */
#define EscSha1_BLOCK_BYTES 64U

/** Hash context for SHA-1 */
typedef struct {
    /** Hash values H from FIPS-180-2. */
    UINT32 hash[ 5 ];
    /** Current block. */
    UINT8 block[ EscSha1_BLOCK_BYTES ];
    /** Number of bytes in block used. */
    UINT8 blockLen;
    /** Total length of the message in byte. */
    UINT32 totalLen;
} EscSha1_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
This function initializes the SHA values according to FIPS-180-2.

\see FIPS-180-2

\param[out] ctx Pointer to SHA-1 context.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscSha1_Init(
    EscSha1_ContextT* ctx );

/**
This function updates SHA-1 context for a block of data.

\see FIPS-180-2

\param[in] ctx Pointer to input SHA-1 context.
\param[out] ctx Pointer to updated SHA-1 context.
\param[in] payload Pointer to input data chunk.
\param[in] dataLen Number of bytes of input data chunk.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscSha1_Update(
    EscSha1_ContextT* ctx,
    const UINT8 payload[],
    UINT32 dataLen );

/**
This function does the final wrapup and returns the digest.

\see FIPS-180-2

\param[in] ctx Pointer to last SHA-1 context.
\param[out] ctx Pointer to updated SHA-1 context.
\param[out] digest Pointer to EscSha1_DIGEST_LEN byte digest.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscSha1_Finish(
    EscSha1_ContextT* ctx,
    UINT8 digest[] );

/**
This function calculates and returns a digest.

\see FIPS-180-2

\param[in] payload Pointer to input data.
\param[in] dataLen Number of bytes of input data.
\param[out] digest Pointer to EscSha1_DIGEST_LEN byte digest.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscSha1_Calc(
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
