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
   \file        _des.h

   \brief       DES implementation generic code.

   All functions and data structures in this module are not supposed to
   be used by the by other DES modules. The must not be called by the
   user directly.


   \see FIPS PUB 46-3

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC__DES_H_
#define _ESC__DES_H_

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

/** The length of an 56 bit DES key in bytes including parity bits.
 The parity bits are ignored. */
#define EscDes_KEY_BYTES 8U

/** Size of one DES block in bytes. */
#define EscDes_BLOCK_BYTES 8U

/** The number of rounds. */
#define EscDes_NUM_ROUNDS 16U

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/
/** The keys required for one round. */
typedef struct {
    /** First part of the round key. */
    UINT32 k1;
    /** Second part of the round key. */
    UINT32 k2;
} EscDes_RoundKeyT;

/** The DES key schedule. */
typedef struct {
    /** Encryption round keys */
    EscDes_RoundKeyT k[ EscDes_NUM_ROUNDS ];
} EscDes_KeySchedT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
 Performs the initial permutation.

 This is an internal function, which should not be called by the user directly.

 \param[out] l Updated l, containing l_0 of the first round.
 \param[out] r Updated r, containing r_0 of the first round.
 \param[in] desBlock The input DES-Block.

 */
extern void
EscDes_IntitialPermutation(
    UINT32* l,
    UINT32* r,
    const UINT8 desBlock[] );

/**
 Performs the final permutation.

 This is an internal function, which should not be called by the user directly.

 \param[out] desBlock The result of the permutation.
 \param[in] l Containing l_16 of the last round.
 \param[in] r Containing r_16 of the last round.

 */
extern void
EscDes_FinalPermutation(
    UINT8 desBlock[],
    UINT32 l,
    UINT32 r );

/**
Processes the DES rounds forward.

This is an internal function, which should not be called by the user directly.

\param[in] sched The key schedule.
\param[in] pl Points to l_0 of the first round.
\param[in] pr Points to r_0 of the first round.
\param[out] pl Updated to l_16 of the last round.
\param[out] pr Updated to r_16 of the last round.

*/
extern void
EscDes_EncryptRounds(
    const EscDes_KeySchedT* sched,
    UINT32* pl,
    UINT32* pr );

/**
Processes the DES rounds forward.

This is an internal function, which should not be called by the user directly.

\param[in] sched The key schedule.
\param[in] pl Points to l_16 of the last round.
\param[in] pr Points to r_16 of the last round.
\param[out] pl Updated to l_0 of the first round.
\param[out] pr Updated to r_0 of the first round.

*/
extern void
EscDes_DecryptRounds(
    const EscDes_KeySchedT* sched,
    UINT32* pl,
    UINT32* pr );

/**
Initializes the ECB Context with the corresponding DES key.

This is an internal function, which should not be called by the user directly.

\param[in] sched Buffer, to store the key schedule to.
\param[out] sched The initialized key schedule.
\param[in] key The DES key to use. EscDes_KEY_BYTES byte.
*/
extern void
EscDes_Init(
    EscDes_KeySchedT* sched,
    const UINT8 key[] );

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
