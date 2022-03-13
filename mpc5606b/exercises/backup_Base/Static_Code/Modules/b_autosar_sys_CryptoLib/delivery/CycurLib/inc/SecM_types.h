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
   \file SecM_types.h

   \brief  Security module type definitions

   Header with type definitions for SecM according to:
   "HIS Security Module Specification Version 1.1 final"

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_SECM_TYPES_H_
#define _ESC_SECM_TYPES_H_

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

/** Return value for success */
#define SECM_OK     0U

/** Return value for failure */
#define SECM_NOT_OK 1U

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** Indicates a length */
typedef UINT16 SecM_LengthType;
/** Status, in most cases SECM_OK or SECM_NOT_OK */
typedef UINT8 SecM_StatusType;
/** A unsigned 32 bit integer */
typedef UINT32 SecM_WordType;
/** Contains a CRC-32 value */
typedef UINT32 SecM_CRCType;
/** Pointer to the data to verify */
typedef const UINT8* SecM_VerifyDataType;
/** Key type for SecM_CompareKey() */
typedef SecM_WordType SecM_KeyType;

/** Address type of HIS Flashloader Specification */
typedef UINT32 FL_AddressType;
/** Length type of HIS Flashloader Specification */
typedef UINT32 FL_LengthType;
/** Data type of HIS Flashloader Specification */
typedef UINT8 FL_DataType;

/** Pointer to watchdog-trigger function (FL-619) */
typedef void (
    *FL_WDTriggerFctType )(
    void );

/**
Function to read data according to HIS Flash Loader Specification v1.1 (FL-413).

\note HIS Security Module Specification (SeM237) and HIS Flash
Loader Specification (FL-413) differ.
*/
typedef FL_LengthType (
    *FL_ReadMemoryFctType )(
    FL_AddressType addr,
    FL_LengthType len,
    FL_DataType* payload );

/**
A segment is divided in multiple blocks during verification,
to reduce memory consumption and allow 16 bit counters for some HIS functions.
Therefore the block size must be below 0x10000.
Increasing the size improves performance at the cost of RAM.
*/
#define SECMV_MAX_BLOCK_SIZE  64U

/** Used to pass data blocks during SecM_Verification() */
typedef struct {
    /** Address of this block */
    UINT32 address;
    /** Segment, this block belongs to. Starts at 0 */
    SecM_WordType segIdx;
    /** Index of the block within segment. Starts at 0. */
    SecM_WordType blockIdx;
    /** Number of bytes of this block */
    SecM_LengthType len;
    /** Block data */
    UINT8 payload[ SECMV_MAX_BLOCK_SIZE ];
} SecMV_VerificationBlock;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

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
