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
   \file        sha_512.h

   \brief       SHA-384 and SHA-512 implementation.
   A maximum of 2^32-2 Bytes can be hashed.

   \see      FIPS-180-2 at
   http://csrc.nist.gov/publications/fips/fips180-2/fips180-2withchangenotice.pdf

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_SHA_512_H_
#define _ESC_SHA_512_H_

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

#ifndef EscSha512_IS_SHA384
#    if 0
/** Calculates SHA-284. Calculates SHA-512 if not defined. */
#        define EscSha512_IS_SHA384
#    endif
#endif

/** Length of digest in bytes. */
#ifdef EscSha512_IS_SHA384
#    define EscSha512_DIGEST_LEN 48U
#else
#    define EscSha512_DIGEST_LEN 64U
#endif

/** Length of one hash block in bytes. */
#define EscSha512_BLOCK_BYTES 128U

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/
#ifdef Esc_HAS_INT64
/** Word type 64 bit. */
typedef UINT64 EscSha512_WordT;
#else
/** A 64 bit word split up into twice 32 bit. */
typedef struct {
    /** High word. */
    UINT32 high;
    /** Low word. */
    UINT32 low;
} EscSha512_WordT;
#endif

/** Hash context for SHA. */
typedef struct {
    /** Hash values H from FIPS-180-2. */
    EscSha512_WordT hash[ 8 ];

    /** Current block. */
    UINT8 block[ EscSha512_BLOCK_BYTES ];
    /** Number of bytes in block used. */
    UINT8 blockLen;
    /** Total length of the message in byte. */
    UINT32 totalLen;
} EscSha512_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
This function initializes the SHA calculation according to FIPS-180-2.

\see FIPS-180-2

\param[out] ctx pointer to SHA context.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscSha512_Init(
    EscSha512_ContextT* ctx );

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
EscSha512_Update(
    EscSha512_ContextT* ctx,
    const UINT8 payload[],
    UINT32 dataLen );

/**
This function does the final wrapup and returns the digest.

\see FIPS-180-2

\param[in] ctx Pointer to last SHA context.
\param[out] ctx Pointer to updated SHA context.
\param[out] digest Pointer to EscSha512_DIGEST_LEN x 8-bit digest value.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscSha512_Finish(
    EscSha512_ContextT* ctx,
    UINT8 digest[] );

/**
This function calculates and returns a SHA digest.

\see FIPS-180-2

\param[in] payload Pointer to input data.
\param[in] dataLen Number of bytes of input data.
\param[out] digest Pointer to EscSha512_DIGEST_LEN x 8-bit hash value.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscSha512_Calc(
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
