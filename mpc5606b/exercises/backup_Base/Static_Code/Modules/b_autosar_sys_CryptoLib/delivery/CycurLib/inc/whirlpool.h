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
   \file        whirlpool.h

   \brief       Whirlpool implementation
   A maximum of 2^32-2 Byte can be hashed.

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef WHIRLPOOL_H_
#define WHIRLPOOL_H_

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

/***************************************************************
 Set optimization flags according to global speed define.
 ***************************************************************/
#ifdef Esc_OPTIMIZE_SPEED
#    if 1
#       ifndef EscWhirlpool_8BIT_OPTIMIZATION
/** Increases speed significantly on costs of 1/4KB tables */
#           define EscWhirlpool_8BIT_OPTIMIZATION
#       endif
#    endif
#endif

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** Length of digest in byte. */
#define EscWhirlpool_DIGEST_LEN 64U

/** Length of one hash block in bytes. */
#define EscWhirlpool_BLOCK_BYTES 64U

/** Length of one hash block in bytes. */
#define EscWhirlpool_COLS 8U

/** Length of one hash block in bytes. */
#define EscWhirlpool_ROWS 8U

/** Number of bits per byte. */
#define EscWhirlpool_BITS_PER_BYTES 8U

/** Hash context for Whirlpool */
typedef struct {
    /** Hash values. */
    UINT8 hash[ EscWhirlpool_DIGEST_LEN ];
    /** Current block. */
    UINT8 block[ EscWhirlpool_BLOCK_BYTES ];
    /** Number of bytes in block used. */
    UINT8 blockLen;
    /** Total length of the message in byte. */
    UINT32 totalLen;
} EscWhirlpool_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
This function initializes the Whirlpool values.

\param[out] ctx Pointer to Whirlpool context.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscWhirlpool_Init(
    EscWhirlpool_ContextT* ctx );

/**
This function updates Whirlpool context for a block of data.

\param[in] ctx Pointer to input Whirlpool context.
\param[out] ctx Pointer to updated Whirlpool context.
\param[in] payload Pointer to input data chunk.
\param[in] dataLen Number of bytes of input data chunk.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscWhirlpool_Update(
    EscWhirlpool_ContextT* ctx,
    const UINT8 payload[],
    UINT32 dataLen );

/**
This function does the final wrapup and returns the digest.

\param[in] ctx Pointer to last Whirlpool context.
\param[out] ctx Pointer to updated Whirlpool context.
\param[out] digest Pointer to Whirlpool_DIGEST_LEN byte digest.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscWhirlpool_Finish(
    EscWhirlpool_ContextT* ctx,
    UINT8 digest[] );

/**
This function calculates and returns a digest.

\param[in] payload Pointer to input data.
\param[in] dataLen Number of bytes of input data.
\param[out] digest Pointer to EscWhirlpool_DIGEST_LEN byte digest.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscWhirlpool_Calc(
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
#endif /* WHIRLPOOL_H_ */
/***************************************************************************
 * 7. END                                                                  *
 ***************************************************************************/
