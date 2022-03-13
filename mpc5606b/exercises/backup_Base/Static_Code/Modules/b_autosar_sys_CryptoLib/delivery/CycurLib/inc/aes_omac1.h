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
   \file        aes_omac1.h

   \brief       AES-OMAC1 implementation.
                Equivalent to AES-CMAC (NIST SP 800-38B)

   \see         NIST SP 800-38B

   Key sizes of 128, 192 and 256 bits are allowed.

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_AES_OMAC1_H_
#define _ESC_AES_OMAC1_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#include "aes_ecb.h"

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
/** AES context in OMAC1 mode. */
typedef struct {
    /** Context in ECB mode. */
    EscAesEcb_ContextT ecbCtx;
    /** Current block. */
    UINT8 block[ EscAes_BLOCK_BYTES ];
    /** Number of bytes in block used. */
    UINT8 blockLen;
} EscAesOmac1_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
Initializes the OMAC1 context with the corresponding AES key.

\param[out] omac1Ctx The AES OMAC1 context.
\param[in] key Key bytes array. Array of size EscAes_KEY_BYTES.

\return TRUE on error.
*/
extern BOOL
EscAesOmac1_Init(
    EscAesOmac1_ContextT* omac1Ctx,
    const UINT8 key[] );

/**
Updates the AES OMAC1 context with message data.

\param[in] omac1Ctx The previous AES OMAC1 context.
\param[out] omac1Ctx The updated AES OMAC1 context.
\param[in] message The message to add to the authentication code.
\param[in] messageLen of message in byte. Doesn't need to match AES block boundaries.

\return TRUE on error.
*/
extern BOOL
EscAesOmac1_Update(
    EscAesOmac1_ContextT* omac1Ctx,
    const UINT8 message[],
    UINT32 messageLen );

/**
Returns the MAC value calculated using OMAC1

\param[in] omac1Ctx The previous AES OMAC1 context.
\param[out] omac1Ctx The updated AES OMAC1 context. It is invalid now.
\param[in] mac Array to store the calculated MAC.
\param[in] macLen Number of bytes to write to mac.

\return TRUE on error.
*/
extern BOOL
EscAesOmac1_Finish(
    EscAesOmac1_ContextT* omac1Ctx,
    UINT8 mac[],
    UINT8 macLen );

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
