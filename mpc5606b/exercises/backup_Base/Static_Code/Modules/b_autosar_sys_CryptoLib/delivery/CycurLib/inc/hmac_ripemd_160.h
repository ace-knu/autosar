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
   \file        hmac_ripemd_160.h

   \brief       HMAC-RIPEMD-160 implementation, RFC 2104 compliant

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef  _ESC_HMAC_RIPEMD_160_H_
#define  _ESC_HMAC_RIPEMD_160_H_

/***************************************************************************
* 1. INCLUDES                                                              *
****************************************************************************/

#include "ripemd_160.h"

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
/** HMAC-RIPEMD context */
typedef struct {
    /** RIPEMD context */
    EscRipemd_ContextT rmd_ctx;

    /**
    this buffer holds the hmac key - the key will be hashed during the
    initialisation when it's length is greater than 64 bytes.
    */
    UINT8 hmac_key[ 64 ];
    /** Length of the hmac_key */
    UINT8 hmac_key_length;
} EscHmacRipemd_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
This function initializes the HMAC-RIPEMD-160 values

\param[in] ctx Pointer to hash context.
\param[in] key Array with hmac key.
\param[in] key_length Length of hmac key. Must be > 0.
\param[out] ctx Pointer to hash context.

\return TRUE on error.

\note      Testcases can be found here:
            http://homes.esat.kuleuven.be/~bosselae/ripemd160.html#Outline
*/
extern BOOL
EscHmacRipemd_Init(
    EscHmacRipemd_ContextT* ctx,
    const UINT8 key[],
    UINT32 key_length );

/**
This function updates hash context for a block of data.

\param[in] ctx Pointer to input RIPEMD context.
\param[in] chunk_data Array of input data chunk.
\param[in] chunk_length Length in number of bytes of input data chunk.
\param[out] ctx Pointer to updated RIPEMD context.

\return TRUE on error.
*/
extern BOOL
EscHmacRipemd_Update(
    EscHmacRipemd_ContextT* ctx,
    const UINT8 chunk_data[],
    UINT32 chunk_length );

/**
This function does the final wrapup and returns the hash

\param[in] ctx Pointer to last hash context.
\param[out] hmac_hash Array with 5 × 32-bit hash words (20 bytes).

\return TRUE on error.
*/
extern BOOL
EscHmacRipemd_Finish(
    EscHmacRipemd_ContextT* ctx,
    UINT8 hmac_hash[] );

/**
This function calculates the HMAC based on RIPEMD-160 for the input data.

\see RFC 2104

\param[in] key Secret MAC key.
\param[in] key_length Length of key in bytes. Must be > 0.
\param[in] payload Data to be hashed.
\param[in] data_length Length of data in bytes.

\param[out] hmac_hash Pointer to 5 × 32-bit hash words.

\return TRUE on error.
*/
extern BOOL
EscHmacRipemd_Calc(
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
