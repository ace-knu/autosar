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
   \file        _aes.h

   \brief       AES implementation (FIPS-197 compliant)
   Common functions. The functions are not supposed to be called
   by the user. Use one of the submodule functions instead.

   \see FIPS-197

   Key sizes of 128, 192 and 256 bits are allowed.

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC__AES_H_
#define _ESC__AES_H_

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
/* User definable configuration */
#ifndef EscAes_KEY_BITS
/** Size of AES key (in bit): 128, 192, 256 */
#    define EscAes_KEY_BITS 128U
#endif

#ifdef Esc_OPTIMIZE_SPEED
/* Set this to one to use only one of the T-tables (2 kB).
   Set this to zero to use all of the four T-tables (8 kB) */
#   if 0
#       ifndef EscAes_USE_T_TABLES_SMALL
/** Uses T-Table implementation with only one table (2 kB) */
#           define EscAes_USE_T_TABLES_SMALL
#       endif
#   endif
#endif



/* Everything below this line is not to be configured */

/** Size of the AES key in bytes. */
#define EscAes_KEY_BYTES ( EscAes_KEY_BITS / 8U )

/** Size of AES block in bits. */
#define EscAes_BLOCK_BITS   128U

/** Size of one AES data block in bytes. */
#define EscAes_BLOCK_BYTES ( EscAes_BLOCK_BITS / 8U )

/** Size of IV in bytes. */
#define EscAes_IV_BYTES EscAes_BLOCK_BYTES

/* Parameter checks. */
#if ( EscAes_KEY_BITS != 128U ) && ( EscAes_KEY_BITS != 192U ) && ( EscAes_KEY_BITS != 256U )
#    error wrong key_SIZE!
#endif

#if ( ( defined( Esc_OPTIMIZE_SPEED ) ) && ( !defined( EscAes_USE_T_TABLES_SMALL ) ) )
#   ifndef EscAes_USE_T_TABLES_FULL
/** Uses T-Table implementation with all four tables (8 kB) */
#           define EscAes_USE_T_TABLES_FULL
#   endif
#endif

#ifndef Esc_OPTIMIZE_SPEED
#   if defined( EscAes_USE_T_TABLES_FULL ) || defined ( EscAes_USE_T_TABLES_SMALL )
#       error AES T-table configuration is not allowed without Esc_OPTIMIZE_SPEED!
#   endif
#endif

/** Number of columns (32-bit words) comprising the state. */
#define EscAes_Nb 4U

/** Number of 32-bit words comprising the cipher key. */
#define EscAes_Nk ( EscAes_KEY_BITS / 32U )

/** Number of rounds. */
#define EscAes_Nr ( EscAes_Nk + EscAes_Nb + 2U )

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
Copies on AES block from src to destination.
*/
extern void
EscAes_CopyBlock(
    UINT8 dest[],
    const UINT8 source[] );

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
