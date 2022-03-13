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
   \file        md5.h

   \brief       MD-5 implementation.

   A maximum of 2^32-2 byte can be hashed.

   \see      RFC-1321

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_MD5_H_
#define _ESC_MD5_H_

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

/** The MD-5 digest length in bytes. */
#define EscMd5_DIGEST_LEN 16U

/** Length of one hash block in bytes */
#define EscMd5_BLOCK_BYTES 64U

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** Hash context for MD-5. */
typedef struct {
    /** Hash values h0 .. h4. */
    UINT32 h[ 4 ];
    /** Current block. */
    UINT8 block[ EscMd5_BLOCK_BYTES ];
    /** Number of bytes in block used. */
    UINT8 blockLen;
    /** Total length of the message in byte. */
    UINT32 totalLen;
} EscMd5_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
This function initializes the MD5 values according.

\param[out] ctx pointer to MD5 context.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscMd5_Init(
    EscMd5_ContextT* ctx );

/**
This function updates MD5 context for a block of data.

\param[in] ctx Pointer to input MD5 context.
\param[out] ctx Pointer to updated MD5 context.
\param[in] payload Pointer to input data chunk.
\param[in] dataLen Number of bytes of input data chunk.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscMd5_Update(
    EscMd5_ContextT* ctx,
    const UINT8 payload[],
    UINT32 dataLen );

/**
This function does the final wrapup and returns the hash.

\param[in] ctx Pointer to last MD5 context.
\param[out] ctx Pointer to updated MD5 context.
\param[out] digest Pointer to EscMd5_DIGEST_LEN x 8-bit hash value.

\return TRUE on error.
*/
/***************************************************************************/
extern BOOL
EscMd5_Finish(
    EscMd5_ContextT* ctx,
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
