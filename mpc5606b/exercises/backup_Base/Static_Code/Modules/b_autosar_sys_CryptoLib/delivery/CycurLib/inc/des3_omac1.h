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
   \file        des3_omac1.h

   \brief       3-DES-OMAC1 implementation.
                Equivalent to 3-DES-CMAC (NIST SP 800-38B)

   \see         NIST SP 800-38B

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_DES3_OMAC1_H_
#define _ESC_DES3_OMAC1_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#include "des3_ecb.h"

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
/** 3-DES context in OMAC1 mode. */
typedef struct {
    /** Context in ECB mode. */
    EscDes3Ecb_ContextT ecbCtx;
    /** Current block. */
    UINT8 block[ EscDes_BLOCK_BYTES ];
    /** Number of bytes in block used. */
    UINT8 blockLen;
} EscDes3Omac1_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
Initializes the OMAC1 context with the corresponding DES3 key.

This function does not check the key for weaknesses nor does it
check the parity bits.

To check if a key is a known weak key, use the function EscDesKeytest_IsKeyWeak().
\see des_keytest.h

\param[out] omac1Ctx The DES3 OMAC1 context.
\param[in] k1 TDEA K1. Key bytes array. Array of size EscDes_KEY_BYTES.
\param[in] k2 TDEA K2. Key bytes array. Array of size EscDes_KEY_BYTES.
\param[in] k3 TDEA K3. Key bytes array. Array of size EscDes_KEY_BYTES.

\return TRUE on error.
*/
extern BOOL
EscDes3Omac1_Init(
    EscDes3Omac1_ContextT* omac1Ctx,
    const UINT8 k1[],
    const UINT8 k2[],
    const UINT8 k3[] );

/**
Updates the DES3 OMAC1 context with message data.

\param[in] omac1Ctx The previous DES3 OMAC1 context.
\param[out] omac1Ctx The updated DES3 OMAC1 context.
\param[in] message The message to add to the authentication code.
\param[in] messageLen of message in byte. Doesn't need to match DES block boundaries.

\return TRUE on error.
*/
extern BOOL
EscDes3Omac1_Update(
    EscDes3Omac1_ContextT* omac1Ctx,
    const UINT8 message[],
    UINT32 messageLen );

/**
Returns the MAC value calculated using OMAC1

\param[in] omac1Ctx The previous DES3 OMAC1 context.
\param[out] omac1Ctx The updated DES3 OMAC1 context. It is invalid now.
\param[in] mac Array to store the calculated MAC.
\param[in] macLen Number of bytes to write to mac.

\return TRUE on error.
*/
extern BOOL
EscDes3Omac1_Finish(
    EscDes3Omac1_ContextT* omac1Ctx,
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
