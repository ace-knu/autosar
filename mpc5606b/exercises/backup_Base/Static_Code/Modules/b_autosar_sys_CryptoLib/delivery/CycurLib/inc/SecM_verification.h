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
   \file        SecM_verification.h

   \brief       SecM_verification implementation.

   Implementation of SecM security module verification routine
   according to:
   "HIS Security Module Specification Version 1.1 final"
   (SecM235)

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_SECM_VERIFICATION_H_
#define _ESC_SECM_VERIFICATION_H_

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

/** CRC verification failed */
#define VERIFICATION_CRC_ERROR 0x02U

/** HMAC/Signature verification failed */
#define VERIFICATION_SIG_ERROR 0x04U

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

#if ( SEC_MEMORY_ACCESS == SEC_ADDRESS )
/** Part of FL_SegmentListType */
typedef struct {
    /** Start address of the segment for signature verification */
    UINT32 transferredAddress;
    /** Start address of the segment in flash                   */
    UINT32 targetAddress;
    /** Length of the segment (in byte)                           */
    UINT32 length;
} FL_SegmentInfoType;
#elif ( SEC_MEMORY_ACCESS == SEC_FILE )
/** Needed for FL_FileIDType */
typedef UINT32 FL_FileLengthType;

/** Part of FL_SegmentInfoType */
typedef struct {
    /** File name                             */
    UINT8* idString;
    /** Length of the file ID (in characters) */
    UINT8 length;
} FL_FileIDType;

/** Part of FL_SegmentListType */
typedef struct {
    /** File name for the signature verification */
    FL_FileIDType targetFile;
    /** File name in flash                       */
    FL_FileIDType transferredFile;
    /** Length of file (in characters)           */
    FL_FileLengthType length;
} FL_SegmentInfoType;
#else
#    error "SEC_MEMORY_ACCESS not defined!"
#endif

/** Part of SecM_VerifyParamType */
typedef struct {
    /** No. of segments/files                            */
    UINT8 nrOfSegments;
    /** Array with pointers to file/segment information */
    FL_SegmentInfoType* segmentInfo;
} FL_SegmentListType;

/** Parameters for SecM_Verification (SecM 237) */
typedef struct {
    /** Segment/File list                                        */
    FL_SegmentListType segmentList;
    /** Start address of the logical block                                  */
    UINT32 blockStartAddress;
    /** Length of the logical block (in byte)                               */
    UINT32 blockLength;
    /** Verification Data from the diagnostic tester (transmitted w/ check) */
    SecM_VerifyDataType verificationData;
    /** From the verification routine calculated CRC value                  */
    SecM_CRCType crcTotal;
    /** Pointer to the watchdog trigger routine                             */
    FL_WDTriggerFctType wdTriggerFct;
    /** Pointer to memory read routine                                      */
    FL_ReadMemoryFctType readMemory;
} SecM_VerifyParamType;

/** Parameterlist of SecM_InitVerification. Not used. */
typedef void SecM_VerifyInitType;

/** Parameterlist of SecM_DeinitVerification. Not used. */
typedef void SecM_VerifyDeinitType;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
HIS interface for the Verification function (SecM235).

This function calls SecM_VerifySignature()

\param[in] verifyParam Verification parameter.

\return
    - SECM_OK: Execution successful.
    - SECM_NOT_OK: General error during verification.
    - VERIFICATION_CRC_ERROR: Crc verification failed ( CRC mismatch! ).
    - VERIFICATION_SIG_ERROR: Hash OR signature verification failed ( hash/sig mismatch! ).
*/
extern SecM_StatusType
SecM_Verification(
    SecM_VerifyParamType* verifyParam );

/**
De-initializes the verification (SecM245).

\param[in] deinit Reserved for future use.

\return
    - SECM_OK: Success
    - SECM_NOT_OK: Failure
*/
extern SecM_StatusType
SecM_DeinitVerification(
    const SecM_VerifyDeinitType* deinit );

/**
Initializes the verification (SecM245).

\param[in] init Reserved for future use.

\return
    - SECM_OK: Success
    - SECM_NOT_OK: Failure
*/
extern SecM_StatusType
SecM_InitVerification(
    const SecM_VerifyInitType* init );

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
