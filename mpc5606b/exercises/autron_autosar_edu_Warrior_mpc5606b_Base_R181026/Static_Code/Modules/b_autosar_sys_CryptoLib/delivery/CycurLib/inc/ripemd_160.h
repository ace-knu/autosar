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
   \file        ripemd_160.h

   \brief       RIPEMD-160 implementation.

   According to:
   ISO/IEC FDIS 10118-3 Final Draft 2003, Chapter 7
   algorithm from:
   - Hans Dobbertin, Antoon Bosselaers, Bart Preneel:
   - "RIPEMD-160:A Strengthened Version of RIPEMD"

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_RIPEMD_160_H_
#define _ESC_RIPEMD_160_H_

/***************************************************************************
* 1. INCLUDES                                                              *
****************************************************************************/

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

/** Hash context for RIPEMD-160 */
typedef struct {
    /** high word of 64-bit value for bytes count */
    UINT32 total_bytes_Hi;
    /** low word of 64-bit value for bytes count  */
    UINT32 total_bytes_Lo;
    /** 5 × 32-bit hash words                     */
    UINT32 vector[ 5 ];
    /** 64 byte buffer                            */
    UINT8 buffer[ 64 ];
} EscRipemd_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
This function initializes the RIPEMD-160 values

Hans Dobbertin, Antoon Bosselaers, Bart Preneel:
"RIPEMD-160:A Strengthened Version of RIPEMD"
published in Fast Software Encryption, LNCS 1039, D. Gollmann, Ed., Springer-Verlag, 1996, pp. 71-82

\param[out] ctx Pointer to hash context.

\return TRUE on error.

\note      Testcases can be found here:
            http://homes.esat.kuleuven.be/~bosselae/ripemd160.html#Outline
*/
extern BOOL
EscRipemd_Init(
    EscRipemd_ContextT* ctx );

/**
This function updates hash context for a block of data

Hans Dobbertin, Antoon Bosselaers, Bart Preneel:
"RIPEMD-160:A Strengthened Version of RIPEMD"

\param[in] ctx Pointer to input RIPEMD context.
\param[in] chunk_data Array input data chunk.
\param[in] chunk_length Length in number of bytes of input data chunk.
\param[out] ctx Pointer to updated RIPEMD context.

\return TRUE on error.
*/
extern BOOL
EscRipemd_Update(
    EscRipemd_ContextT* ctx,
    const UINT8 chunk_data[],
    UINT32 chunk_length );

/**
This function does the final wrapup and returns the hash

Hans Dobbertin, Antoon Bosselaers, Bart Preneel:
"RIPEMD-160:A Strengthened Version of RIPEMD"

\param[in] ctx Pointer to last hash context.
\param[out] ctx Updated hash context.
\param[out] rmd_hash array to 5 × 32-bit hash words (20 bytes)

\return TRUE on error.
*/
extern BOOL
EscRipemd_Finish(
    EscRipemd_ContextT* ctx,
    UINT8 rmd_hash[] );

/**
This function calculates and returns a RIPEMD-160 hash

Hans Dobbertin, Antoon Bosselaers, Bart Preneel:
- "RIPEMD-160:A Strengthened Version of RIPEMD"
- Implementation: ISO/IEC FDIS 10118-3

\param[in] payload Pointer to input data.
\param[in] data_length Length in number of bytes of the payload.
\param[out] rmd_hash Pointer to 160 bit hash value.

\return TRUE on error.
*/
extern BOOL
EscRipemd_Calc(
    const UINT8 payload[],
    const UINT32 data_length,
    UINT8 rmd_hash[] );

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
