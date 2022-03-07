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
    \file        hash_drbg.h

    \brief       Pseudo Random Number Generator w/ SHA-*

    \see        NIST publication SP 800-90:
                Recommendation for Random Number Generation Using
                Deterministic Random Bit Generators


    Pseudo random number generator implementation according to NIST SP 800-90
    "Hash_DRBG" Recommendation.
    The random number generator requires an entropy input with at least 128 bit.
    The quality of the entropy is very important for the use of this PRNG!
    This PRNG has a security strength of 128 bit in comparing to symmetric key
    algorithms. For more information about the security strength see "NIST
    Special Publications 800-57" chapter 5.6.1.

    Also the PRNG requires a nonce with at least 64 bit extra entropy or a value
    that is expected to repeat no more often than a 64 bit random string would
    be expected to repeat. The remaining bits shall be filled with a
    personalization string, which makes every instance of this PRNG unique, for
    example the serial no. of the host device is a good value.

    $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_HASH_DRBG_H_
#define _ESC_HASH_DRBG_H_

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

#ifndef EscHashDrbg_SECURITY_STRENGTH
/** Determines the desired security strength in Bits (128, 192, 256).*/
#    define EscHashDrbg_SECURITY_STRENGTH 128U
#endif

#ifndef EscHashDrbg_SHA_TYPE
/**
 * Determines the hash algorithm:
 *   1 = SHA-1
 *   2 = (SHA-224, SHA-256)^1
 *   3 = (SHA-384,SHA-512)^1
 * ^1 Depending on the configuration of the SHA module
 **/
#    define EscHashDrbg_SHA_TYPE 1
#endif

#if 0
#    ifndef EscHashDrbg_ADJUSTABLE_OUTPUT_LENGTH
/**
 * Enable (1) for variable PRNG output length. When Disabled, fixed output
 * length is set to the SHA-module's output length.
 **/
#        define EscHashDrbg_ADJUSTABLE_OUTPUT_LENGTH
#    endif
#endif

#ifndef EscHashDrbg_RESEED_INTERVAL
/**
 * Maximum allowed function calls of EscHashDrbg_GetRandom before the reseed
 * function has to be called. Maximum is (2^32) -1 (UINT32). The default value
 * has been adopted from the NIST example pseudo code
 **/
#    define EscHashDrbg_RESEED_INTERVAL 100000U
#endif

#ifndef EscHashDrbg_ENTROPY_LEN
/**
 * entropy length - must be the array size of values for INIT and RESEED
 * calls! For 128 bit security strength, entropy must to be at least 16 bytes
 **/
#    define EscHashDrbg_ENTROPY_LEN 16U
#endif

#ifndef EscHashDrbg_NONCE_LEN
/**
 * nonce length - must be the array size of values for INIT and RESEED
 * calls! For 128 bit security strength, nonce must to be at least 8 bytes
 **/
#    define EscHashDrbg_NONCE_LEN 8U
#endif

/* Everything below this line is not to be configured */
#if ( ( EscHashDrbg_SHA_TYPE == 1 ) || ( EscHashDrbg_SHA_TYPE == 2 ) )
/**
 * seed length - according to the standard the length must be 440 bit for SHA-1,
 * SHA-224, and SHA-256
 **/
#    define EscHashDrbg_SEED_LEN 55U
#else
/**
 * seed length - according to the standard the length must be 888 bit for
 * SHA-384 and SHA-512
 **/
#    define EscHashDrbg_SEED_LEN 111U
#endif

#if ( EscHashDrbg_SHA_TYPE == 1 )
#    include "sha_1.h"
/** Length of the output of one hash operation (depending on the chosen hash algorithm)*/
#    define EscHashDrbg_BLOCK_LEN EscSha1_DIGEST_LEN
#else
#    if ( EscHashDrbg_SHA_TYPE == 2 )
#        include "sha_256.h"
#        define EscHashDrbg_BLOCK_LEN EscSha256_DIGEST_LEN
#    else
#        if ( EscHashDrbg_SHA_TYPE == 3 )
#            include "sha_512.h"
#            define EscHashDrbg_BLOCK_LEN EscSha512_DIGEST_LEN
#        else
#            error "EscHashDrbg_SHA_TYPE wrong!"
#        endif
#    endif
#endif

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/
/** PRNG context */
typedef struct {
    /** seed vector   */
    UINT8 seed[ EscHashDrbg_SEED_LEN ];

    /** state vector   */
    UINT8 state[ EscHashDrbg_SEED_LEN ];

    /** reseed counter   */
    UINT32 counter;
} EscHashDrbg_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
Initializes the PRNG.
This function has to be called once before using the PRNG!

\param[out] ctx The PRNG context.
\param[in]  entropy Pointer to the array with the entropy input. (EscHashDrbg_ENTROPY_LEN bytes)
\param[in]  nonce Pointer to the array with the nonce. (EscHashDrbg_NONCE_LEN bytes)

\return TRUE on error.
*/
extern BOOL
EscHashDrbg_Init(
    EscHashDrbg_ContextT* ctx,
    const UINT8 entropy[],
    const UINT8 nonce[]
    );

/**
Compute a new seed and a new state with newly generated entropy.
This function must be called if the Reseed counter is higher than the define
EscHashDrbg_RESEED_INTERVAL according to the NIST Recommendation.

\param[out] ctx The PRNG context.
\param[in] entropy Random Number Array to add entropy to Seed and State. (EscHashDrbg_ENTROPY_LEN bytes)

\return TRUE on error.
*/

extern BOOL
EscHashDrbg_Reseed(
    EscHashDrbg_ContextT* ctx,
    const UINT8 entropy[]
    );

#ifdef EscHashDrbg_ADJUSTABLE_OUTPUT_LENGTH
/**
Returns a random number derived from the actual state. The internal state is updated.
The return data is depending on the define EscHashDrbg_ADJUSTABLE_OUTPUT_LENGTH

\param[out] ctx The PRNG context.
\param[out] rnd The random number. (EscHashDrbg_BLOCK_LEN bytes or the requested length)
\param[in]  len The length in bytes of the rnd array. (maximal 16 bit)

\return TRUE on error.
*/
extern BOOL
EscHashDrbg_GetRandom(
    EscHashDrbg_ContextT* ctx,
    UINT8 rnd[],
    UINT16 len
    );

#else
/**
Returns a random number derived from the actual state. The internal state is updated.
The return data is depending on the define EscHashDrbg_ADJUSTABLE_OUTPUT_LENGTH

\param[out] ctx The PRNG context.
\param[out] rnd The random number. (EscHashDrbg_BLOCK_LEN bytes)

\return TRUE on error.
*/
extern BOOL
EscHashDrbg_GetRandom(
    EscHashDrbg_ContextT* ctx,
    UINT8 rnd[]
    );

#endif

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
