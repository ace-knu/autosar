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
   \file        SecM_hash.h

   \brief       Hash Functions.

   Hash Function wrappers according to
   "HIS Security Module Specification Version 1.1 final".

   The header file contains macros and typedefs to call the
   configured hash function.

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_SECM_HASH_H_
#define _ESC_SECM_HASH_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#include "SecM_types.h"

#ifdef  __cplusplus
/* *INDENT-OFF* */
extern "C" {
 /* *INDENT-ON* */
#endif

/***************************************************************************
 * 2. DEFINES                                                              *
 ***************************************************************************/

/** Size of the hash value. In all configurations the same */
#define HASH_SIZE 20U

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/
/** State parameter for hash function */
#if ( SEC_SECURITY_CLASS == SEC_CLASS_C )

#    if ( SEC_HASH_ALGORITHM == SEC_RIPEMD160 )
#        include "hmac_ripemd_160.h"
typedef EscHmacRipemd_ContextT SecMV_HashContext;

#    elif ( SEC_HASH_ALGORITHM == SEC_SHA1 )
#        include "hmac_sha_1.h"
typedef EscHmacSha1_ContextT SecMV_HashContext;

#    else
#        error "SEC_HASH_ALGORITHM undefined"
#    endif

#elif ( SEC_SECURITY_CLASS == SEC_CLASS_CCC )
#    if ( SEC_HASH_ALGORITHM == SEC_RIPEMD160 )
#        include "ripemd_160.h"
typedef EscRipemd_ContextT SecMV_HashContext;

#    elif ( SEC_HASH_ALGORITHM == SEC_SHA1 )
#        include "sha_1.h"
typedef EscSha1_ContextT SecMV_HashContext;

#    else
#        error "SEC_HASH_ALGORITHM undefined"
#    endif
#else
typedef UINT8 SecMV_HashContext;
#endif

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/
/**
Initializes the hash key.

\param[out] ctx Hash Context.

\return
    - SECM_OK: Success
    - SECM_NOT_OK: Failure
*/
extern SecM_StatusType
SecMV_hash_init(
    SecMV_HashContext* ctx );

/**
Updates the hash key with new data.

\param[in] ctx Previous hash context.
\param[in] payload Data to add.
\param[in] length Number of bytes to add.
\param[out] ctx Updated hash context.

\return
    - SECM_OK: Success
    - SECM_NOT_OK: Failure
*/
extern SecM_StatusType
SecMV_hash_update(
    SecMV_HashContext* ctx,
    const UINT8 payload[],
    UINT32 length );

/**
Writes the hash value back.

\param[in] ctx Previous hash context.
\param[out] ctx Updated hash context.
\param[out] hash Resulting hash value.

\return
    - SECM_OK: Success
    - SECM_NOT_OK: Failure
*/
extern SecM_StatusType
SecMV_hash_finish(
    SecMV_HashContext* ctx,
    UINT8 hash[] );

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
