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
   \file        SecM.h

   \brief       Main header file for security module implementation.

   Header with function prototypes for SecM according to:
   "HIS Security Module Specification Version 1.1 final"

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_SECM_H_
#define _ESC_SECM_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/
#include "SecM_config.h"
#include "SecM_types.h"
#include "SecM_verification.h"
#include "SecM_verifySignature.h"

#ifdef  __cplusplus
/* *INDENT-OFF* */
extern "C" {
 /* *INDENT-ON* */
#endif

/***************************************************************************
 * 2. DEFINES                                                              *
 ***************************************************************************/

/** Security module main version */
#define SEC_MAIN_VERSION   1
/** Security module sub version */
#define SEC_SUB_VERSION    1
/** Security module bugfix version */
#define SEC_BUGFIX_VERSION 1

/** CRC computing state Init */
#define kCRCInit     1U
/** CRC computing state Compute */
#define kCRCCompute  2U
/** CRC computing state Finalize */
#define kCRCFinalize 3U

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** Parameter list for SecM_ComputeCRC() (SecM213) */
typedef struct {
    /** Current CRC value                                   */
    SecM_CRCType currentCRC;
    /** State of the CRC computing: init, compute, finalize */
    UINT8 crcState;
    /** const pointer to buffer with source data            */
    const UINT8* crcSourceBuffer;
    /** Number of bytes in the buffer                       */
    SecM_LengthType crcByteCount;
    /** Pointer to watchdog trigger routine                 */
    FL_WDTriggerFctType wdTriggerFct;
} SecM_CRCParamType;

/** Input parameter list for SecM_Decryption() (SecM257) */
typedef struct {
    /** Pointer to received/encrypted data block          */
    const UINT8* DataBuffer;
    /** Length of received/encrypted data block (in byte) */
    SecM_LengthType Length;
} SecM_DecInputParamType;

/** Output parameter list for SecM_Decryption() (SecM257) */
typedef struct {
    /** Pointer to decrypted data block          */
    UINT8* DataBuffer;
    /** Length of decrypted data block (in byte) */
    SecM_LengthType Length;
} SecM_DecOutputParamType;

/** Configuration parameter list for SecM_Decryption() (SecM257) */
typedef struct {
    /** Start address of the segment               */
    UINT32 segmentAdress;
    /** Length of the segment (in byte)            */
    UINT32 segmentLength;
    /** Data format ID of encryption & compression */
    UINT8 mode;
    /** Pointer to the watchdog trigger routine    */
    FL_WDTriggerFctType wdTriggerFct;
} SecM_DecParamType;

/** Function parameters for SecM_GenerateSeed() */
typedef struct {
    /** X value of the seed */
    SecM_WordType seedX;
    /** Y value of the seed */
    SecM_WordType seedY;
} SecM_SeedType;

/**  SecM_InitDecryption() parameter type */
typedef void SecM_DecInitType;
/**  SecM_DeinitDecryption() parameter type */
typedef void SecM_DecDeinitType;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
HIS interface for the CRC function (SecM211)

\param[in] crcParam CRC parameters.
\param[out] crcParam Updated crcParam->crcState.

\return
    - SECM_OK: Success
    - SECM_NOT_OK: Failure
*/
extern SecM_StatusType
SecM_ComputeCRC(
    SecM_CRCParamType* crcParam );

/**
HIS interface for the Decryption function (SecM257)

\param[in] inputBlock Structure with received/encrypted data block.
\param[in] decParam Parameters which are necessary for the decryption.
\param[out] outputBlock Structure with decrypted data block.

\return
    - SECM_OK: Success
    - SECM_NOT_OK: Failure
*/
extern SecM_StatusType
SecM_Decryption(
    const SecM_DecInputParamType* inputBlock,
    SecM_DecOutputParamType* outputBlock,
    const SecM_DecParamType* decParam );

/**
HIS interface for the CompareKey function (SecM205)

\param[in] key Key received during challenge&response protocol.
\param[in] seed Random seed value used during challenge&response protocol.

\return
    - SECM_OK: Keys are equal
    - SECM_NOT_OK: Keys are not equal
*/
extern SecM_StatusType
SecM_CompareKey(
    const SecM_KeyType key,
    const SecM_SeedType seed );

/*!
HIS interface for the ComputeKey function (SecM199)

\param[in] seed Random seed value.
\param[in] k ECU specific key.
\param[out] key Key derived from ECU-key and seed.

   \return
   - SECM_OK: Success
   - SECM_NOT_OK: Failure
 */
extern SecM_StatusType
SecM_ComputeKey(
    const SecM_SeedType seed,
    const SecM_WordType k,
    SecM_KeyType* key );

/**
HIS interface for the GenerateSeed function (SecM193)

\param[in] seed Random 64 Bit input.
\param[out] seed Generated seed.

\return
    - SECM_OK: Success
    - SECM_NOT_OK: Failure
*/
/***************************************************************************/
extern SecM_StatusType
SecM_GenerateSeed(
    SecM_SeedType* seed );

/**
HIS interface for the DeinitDecryption function (SecM263)

\param[in] deinit Reserved for future use.
\param[out] deinit Reserved for future use.

\return
    - SECM_OK: Success
    - SECM_NOT_OK: Failure
*/
extern SecM_StatusType
SecM_DeinitDecryption(
    const SecM_DecDeinitType* deinit );

/**
HIS interface for the InitDecryption function (SecM263)

\param[out] init Reserved for future use.

\return
    - SECM_OK: Success
    - SECM_NOT_OK: Failure
*/
extern SecM_StatusType
SecM_InitDecryption(
    const SecM_DecInitType* init );

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
