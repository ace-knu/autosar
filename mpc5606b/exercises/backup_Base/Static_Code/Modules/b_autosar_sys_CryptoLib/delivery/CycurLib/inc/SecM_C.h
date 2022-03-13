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
   \file        SecM_C.h

   \brief       Security class C dependent implementation.

   "HIS Security Module Specification Version 1.1 final"

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_SECM_C_H_
#define _ESC_SECM_C_H_

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

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** State variables */
typedef struct {
    /** Holds params for signature verification. */
    SecM_SignatureParamType sigParam;
    /** sigParam points to this value */
    UINT32 currentDataLength;
    /** Hash context for HASH routine */
    SecMV_HashContext ctx;
} SecMV_VerifyDataC;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
Adds another block of data to the verification data.

HIS Security Module Specification 1.1 (final), 2006-07-03 (SecM237)

\param[in] verifyParam Verification parameters.
\param[in] block Block to add.
\param[out] verifyData VENDOR Verification Data.

\return
    - SECM_OK: Success
    - SECM_NOT_OK: Failure
*/
extern SecM_StatusType
SecMV_ClassAddBlockC(
    const SecM_VerifyParamType* verifyParam,
    SecMV_VerifyDataC* verifyData,
    const SecMV_VerificationBlock* block );

/**
Initializes verifyData
\param[in] verifyParam Verification parameters.
\param[out] verifyData VENDOR Verification Data to initialize.

\return
    - SECM_OK: Success
    - SECM_NOT_OK: Failure
*/
extern SecM_StatusType
SecMV_ClassInitC(
    const SecM_VerifyParamType* verifyParam,
    SecMV_VerifyDataC* verifyData );

/**
Verifies if the calculated verification data
matches the one in verifyParam

\param[in] verifyParam Verification parameters.
\param[out] verifyData VENDOR Verification Data to initialize.

\return
    - SECM_OK: Execution successful.
    - SECM_NOT_OK: General error during verification.
    - VERIFICATION_CRC_ERROR: Crc verification failed ( CRC mismatch! ).
    - VERIFICATION_SIG_ERROR: Hash OR signature verification failed ( hash/sig mismatch! ).
*/
extern SecM_StatusType
SecMV_CheckVerifyDataC(
    const SecM_VerifyParamType* verifyParam,
    SecMV_VerifyDataC* verifyData );

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
