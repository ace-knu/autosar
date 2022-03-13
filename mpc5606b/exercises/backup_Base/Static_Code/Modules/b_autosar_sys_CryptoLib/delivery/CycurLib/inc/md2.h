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
   \file        md2.h

   \brief       MD2 implementation.

   A maximum of 2^32-2 byte can be hashed.

   \see      RFC-1319

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_MD2_H_
#define _ESC_MD2_H_

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

/** Length of one hash block in bytes */
#define EscMd2_BLOCK_BYTES 16U

/** The MD2 digest length in bytes. */
#define EscMd2_DIGEST_LEN EscMd2_BLOCK_BYTES

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** Hash context for MD2. */
typedef struct {
    /** The first 16 byte point to state. The next 32 byte are temporary variables. */
    UINT8 x[ 3U * EscMd2_BLOCK_BYTES ];
    /** The current checksum. */
    UINT8 checksum[ EscMd2_BLOCK_BYTES ];
    /** Current block. */
    UINT8 block[ EscMd2_BLOCK_BYTES ];
    /** Number of bytes in block used. */
    UINT8 blockLen;
    /** Total length of the message in byte. */
    UINT32 totalLen;
} EscMd2_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
This function initializes the MD2 context.

\param[out] ctx pointer to MD2 context.

\return TRUE on error.
*/
extern BOOL
EscMd2_Init(
    EscMd2_ContextT* ctx );

/**
This function updates MD2 context for a block of data.

\param[in] ctx Pointer to input MD2 context.
\param[out] ctx Pointer to updated MD2 context.
\param[in] payload Pointer to input data chunk.
\param[in] dataLen Number of bytes of input data chunk.

\return TRUE on error.
*/
extern BOOL
EscMd2_Update(
    EscMd2_ContextT* ctx,
    const UINT8 payload[],
    UINT32 dataLen );

/**
This function does the final wrapup and returns the hash.

\param[in] ctx Pointer to last MD2 context.
\param[out] ctx Pointer to updated MD2 context.
\param[out] digest Pointer to EscMd2_DIGEST_LEN x 8-bit hash value.

\return TRUE on error.
*/
extern BOOL
EscMd2_Finish(
    EscMd2_ContextT* ctx,
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
