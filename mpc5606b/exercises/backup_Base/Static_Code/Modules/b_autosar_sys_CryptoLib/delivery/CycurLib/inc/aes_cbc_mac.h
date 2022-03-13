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
   \file        aes_cbc_mac.h

   \brief       AES implementation (FIPS-197 compliant)
   CBC-MAC-Mode

   \see FIPS-197

   Key sizes of 128, 192 and 256 bits are allowed.

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_AES_CBC_MAC_H_
#define _ESC_AES_CBC_MAC_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#include "aes_cbc.h"

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

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/
/**
Initializes the CBC context with the corresponding AES key.

\note According to FIPS 113 and RFC 3566 IV is initialized to zero.

\param[out] cbcCtx The AES CBC context.
\param[in] key Key bytes array. Array of size EscAes_KEY_BYTES.

\return TRUE on error.
*/
extern BOOL
EscAesCbcMac_Init(
    EscAesCbc_ContextT* cbcCtx,
    const UINT8 key[] );

/**
Initializes the CBC context with the corresponding AES key and IV.

\param[out] cbcCtx The AES CBC context.
\param[in] key Key bytes array. Array of size EscAes_KEY_BYTES.
\param[in] iv 128-bit initialization vector. Array of EscAes_IV_BYTES bytes.

\return TRUE on error.
*/
extern BOOL
EscAesCbcMac_InitIV(
    EscAesCbc_ContextT* cbcCtx,
    const UINT8 key[],
    const UINT8 iv[] );

/**
Calculates CBC-MAC over one or more data blocks and updates the AES context.

The context must be initialized with EscAesCbcMac_Init.

\param[in] cbcCtx The previous AES CBC context.
\param[out] cbcCtx The updated AES CBC context.
\param[in] plain Message the MAC is computed for.
\param[in] length Length of plain data in bytes. Has to be multiple of EscAes_BLOCK_BYTES bytes
           and not 0.

\return TRUE on error.
*/
extern BOOL
EscAesCbcMac_Update(
    EscAesCbc_ContextT* cbcCtx,
    const UINT8 plain[],
    UINT32 length );

/**
Returns the CBC-MAC.

The context must be initialized with EscAesCbcMac_Init.

\param[in] cbcCtx The previous AES CBC context.
\param[out] mac Array of size EscAes_BLOCK_BYTES the mac value is written to to.

\return TRUE on error.
*/
extern BOOL
EscAesCbcMac_Finish(
    const EscAesCbc_ContextT* cbcCtx,
    UINT8 mac[] );

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
