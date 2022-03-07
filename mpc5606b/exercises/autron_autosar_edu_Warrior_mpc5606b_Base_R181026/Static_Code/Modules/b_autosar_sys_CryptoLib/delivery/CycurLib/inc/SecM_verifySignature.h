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
   \file        SecM_verifySignature.h

   \brief       SecM_verifySignature implementation

   Implementation of SecM security module verifySignature routine
   according to:
   "HIS Security Module Specification Version 1.1 final"
   (SecM219)

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_SECM_VERIFY_SIGNATURE_H_
#define _ESC_SECM_VERIFY_SIGNATURE_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#include "SecM_types.h"
#include "SecM_hash.h"

#ifdef  __cplusplus
/* *INDENT-OFF* */
extern "C" {
 /* *INDENT-ON* */
#endif

/***************************************************************************
 * 2. DEFINES                                                              *
 ***************************************************************************/

/** Initialization (SecM221)*/
#define kHashInit     1U
/** Computing (SecM221)*/
#define kHashCompute  2U
/** Finalize (SecM221)*/
#define kHashFinalize 3U
/** Signature verification (SecM221)*/
#define kSigVerify    4U

/** Minimum size of SecM_SignatureType.sigResultBuffer */
#define SECM_MIN_SIGNATURE_TYPE_LENGTH  sizeof( SecMV_HashContext )

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** Part of SecM_SignatureParamType */
typedef struct {
    /** Startaddress of the signature    */
    UINT32 sigResultBuffer;
    /** Length of the signature in bytes,
    at least SECM_MIN_SIGNATURE_TYPE_LENGTH bytes */
    UINT32 length;
} SecM_SignatureType;

/** Parameters for SecM_VerifySignature (SecM221) */
typedef struct {
    /** Current hash value                                        */
    SecM_SignatureType currentHash;
    /** Pointer to current length of the hashed data (in 64 Byte) */
    UINT32* currentDataLength;
    /** State of the signature computing: init, compute, finalize */
    UINT8 sigState;
    /** Pointer to buffer with source data or the signature/HMAC  */
    const UINT8* sigSourceBuffer;
    /** Number of bytes in buffer                                 */
    SecM_LengthType sigByteCount;
    /** Pointer to watchdog                                       */
    FL_WDTriggerFctType wdTriggerFct;
} SecM_SignatureParamType;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
Signature verification function

\see 1. HIS Security Module Specification 1.1 (final), 2006-07-03, p. 24
\see 2. PKCS #1 v2.0 by RSA Laboratories

\param[in] sigParam Parameters which are necessary to calculate the signature.
    Minimum size of SecM_SignatureType.sigResultBuffer has to be SECM_MIN_SIGNATURE_TYPE_LENGTH.
\param[out] sigParam Updated status in sigResultBuffer.

\return
    - SECM_OK: Success
    - SECM_NOT_OK: Failure
*/
/***************************************************************************/
extern SecM_StatusType
SecM_VerifySignature(
    const SecM_SignatureParamType* sigParam );

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
