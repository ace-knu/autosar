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
   \file        crc_32.h

   \brief       CRC32 implementation according to IEEE 802.3


   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef  _ESC_CRC_32_H_
#define  _ESC_CRC_32_H_

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
/* User definable configuration */

#ifndef EscCrc32_INITIAL_VALUE
/** Initial value. */
#    define EscCrc32_INITIAL_VALUE 0xFFFFFFFFU
#endif

#ifndef Esc_OPTIMIZE_SPEED
#   ifndef EscCrc32_QUOTIENT
/** CRC32 polynomial. Only configurable in size optimized version. */
#       define EscCrc32_QUOTIENT 0xEDB88320U
#   endif
#endif

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
Initializes the crc32 checksum.

Initializes start value with 0xFFFFFFFF.

\param[out] crc Pointer to CRC checksum.

\return TRUE on error.
*/
extern BOOL
EscCrc32_Init(
    UINT32* crc );

/**
Calculate crc32 checksum according to IEEE 802.3.

Bytes are reversed before processing (least significant bit <--> most significant bit ...).

\param[in] message Message array.
\param[in] length Length of message in bytes.
\param[out] crc Pointer to CRC checksum.

\return TRUE on error.
*/
extern BOOL
EscCrc32_Compute(
    const UINT8 message[],
    UINT32* crc,
    UINT32 length );

/**
Finalize crc32 checksum according to IEEE 802.3.

32 bit result of processing is reversed before complementing.

\param[out] crc Pointer to CRC checksum.

\return TRUE on error.
*/
extern BOOL
EscCrc32_Finalize(
    UINT32* crc );

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
