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
   \file        arc4.h

   \brief       ARC4 implementation also known as ARCFOUR

   \see         http://www.mozilla.org/projects/security/pki/nss/draft-kaukonen-cipher-arcfour-03.txt

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_ARC4_H_
#define _ESC_ARC4_H_

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

/** Number of bytes in the state. This value is fixed and not configurable. */
#define EscArc4_STATE_BYTES 256U

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/
/** Arc4 context. */
typedef struct {
    /** State. */
    UINT8 state[ EscArc4_STATE_BYTES ];
    /** Index i. */
    UINT8 i;
    /** Index j. */
    UINT8 j;
} EscArc4_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/
/**
Initializes the ARC4 context with the key.

\param[out] ctx The ARC4 context.
\param[in] key Key bytes array of keyLen bytes.
\param[in] keyLen Number of bytes in key. 1 <= keyLen <= 256

\return TRUE on error.
*/
extern BOOL
EscArc4_Init(
    EscArc4_ContextT* ctx,
    const UINT8 key[],
    UINT16 keyLen );

/**
Exors the generated pseudo random numbers with the input text.

The same function can be used for encryption and decryption.

The inData pointer can be the same as outData pointer.

\param[in] ctx The previous ARC4 context.
\param[out] ctx The updated ARC4 context.
\param[out] outData The inputData exored with the next random numbers.
\param[in] inData The input data.
\param[in] len The number of bytes in inData and outData.

\return TRUE on error.
*/
extern BOOL
EscArc4_Apply(
    EscArc4_ContextT* ctx,
    UINT8 outData[],
    const UINT8 inData[],
    UINT32 len );

/**
Generate n bytes of the key stream and discard them.

Use this function for RC4-Drop[n]. It exist several suggestions for
discarding the first n bytes of the keystreamm. For example RFC4345 favoured
1536 as a good value for n.

\param[in] ctx The previous ARC4 context.
\param[out] ctx The updated ARC4 context.
\param[in] n The number of bytes which will be generated and discarded.

\return TRUE on error.
*/
extern BOOL
EscArc4_Drop(
    EscArc4_ContextT* ctx,
    UINT32 n );

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
