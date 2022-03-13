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
   \file        der.h

   \brief       DER encoding rules according to ISO8825-1:2003
   Only primitives can be decoded, not constructed values yet.

   All functions return FALSE on success.

   The first function to call is EscDer_Init, afterwards
   the DER code is traversed as a stream. Reading a primitive
   from the DER code, moves the stream further. So no element
   can be read twice.

   After returning an error, the context is in an undefined state,
   EscDer_Init must be called again.
   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_DER_H_
#define _ESC_DER_H_

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

/* Everything below this line is not to be configured. */

/** Coordinated Universal Time */
#define DER_TAG_UTCTime 0x17U
/** Generalized Time */
#define DER_TAG_GeneralizedTime 0x18U

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** DER Context data. Don't access its members directly. */
typedef struct {
    /** Pointer to the DER code to read from */
    const UINT8 * derCode;
    /** Length in bytes of derCode */
    UINT32 len;
    /** Position to read the next byte from */
    UINT32 currentPos;
} EscDer_ContextT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
Initializes the DER context.

\param[out] ctx The initialized context.
\param[in] derCode The DER code to parse. The pointer must remain valid
    for all subsequent der_* calls.
\param[in] codeLen The number of available bytes of code.
*/
extern void
EscDer_Init(
    EscDer_ContextT* ctx,
    const UINT8 derCode[],
    UINT32 codeLen );

/**
Reads a BOOLEAN value from the context.

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[out] boolVal Will contain the boolean value.
    Note that every boolVal !=0 is considered true.
\return TRUE on error.
*/
extern BOOL
EscDer_NextBoolean(
    EscDer_ContextT* ctx,
    UINT8* boolVal );

/**
Reads an INTEGER value from the context
up to 32 bit length

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[out] intVal Will contain the integer value.
\return TRUE on error.
*/
extern BOOL
EscDer_NextInteger(
    EscDer_ContextT* ctx,
    UINT32* intVal );

/**
Reads an INTEGER value from the context
with unlimited length.
Byteformat is little endian.

The function calls EscDer_NextIntegerLongBe
and performs an endianness conversion.

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[out] intVal Will contain the integer value in little endian format.
\param[in] intValLength Maximum length of intVal in byte.
\param[out] outLen Actual number of bytes written into intVal.
\return TRUE on error.
*/
extern BOOL
EscDer_NextIntegerLongLe(
    EscDer_ContextT* ctx,
    UINT8 intVal[],
    UINT32 intValLength,
    UINT32* outLen );

/**
Reads an INTEGER value from the context
with unlimited length.
Byteformat is big endian.

As the DER byteformat is already big endian, just a pointer
to the DER code is returned.

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[out] intVal Will return a pointer to the integer value inside the DER code.
    The value is BIG Endian encoded.
\param[out] intValLen Will be updated with the length of intVal in byte.
\return TRUE on error.
*/
BOOL
EscDer_NextIntegerLongBe(
    EscDer_ContextT* ctx,
    const UINT8* intVal[],
    UINT32* intValLen );

/**
Reads a BIT STRING value from the context.

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[out] bitstring Will return a pointer to the bitstring value inside the DER code.
\param[out] numBits The number of bits of the bitstring.
\return TRUE on error.
*/
extern BOOL
EscDer_NextBitString(
    EscDer_ContextT* ctx,
    const UINT8* bitstring[],
    UINT32* numBits );

/**
Reads the next null token from the context.

\param[in] ctx The current context.
\param[out] ctx The updated context.
\return TRUE on error
*/
extern BOOL
EscDer_NextNull(
    EscDer_ContextT* ctx );

/**
Reads an OCTET_STRING value from the context
with unlimited length.

In fact, just a pointer to the EscDer_ContextT code is returned.

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[out] octString Will return a pointer to the octet string value inside the DER code.
\param[out] stringLen Will be updated with the length of octString in byte.
\return TRUE on error.
*/
extern BOOL
EscDer_NextOctetString(
    EscDer_ContextT* ctx,
    const UINT8* octString[],
    UINT32* stringLen );

/**
Reads a IA5String value from the context
with unlimited length.

In fact, just a pointer to the EscDer_ContextT code is returned.

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[out] ia5String Will return a pointer to the IA5String inside the DER code.
\param[out] stringLen Will be updated with the length of ia5String in byte.
\return TRUE on error.
*/
extern BOOL
EscDer_NextIa5String(
    EscDer_ContextT* ctx,
    const UINT8* ia5String[],
    UINT32* stringLen );

/**
Reads a VisibleString value from the context
with unlimited length.

In fact, just a pointer to the EscDer_ContextT code is returned.

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[out] visibleString Will return a pointer to the VisibleString inside the DER code.
\param[out] stringLen Will be updated with the length of visibleString in byte.
\return TRUE on error.
*/
extern BOOL
EscDer_NextVisibleString(
    EscDer_ContextT* ctx,
    const UINT8* visibleString[],
    UINT32* stringLen );

/**
Reads a UTF8String value from the context
with unlimited length.

In fact, just a pointer to the EscDer_ContextT code is returned.

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[out] UTF8String Will return a pointer to the UTF8String inside the DER code.
\param[out] stringLen Will be updated with the length of visibleString in byte.
\return TRUE on error.
*/
extern BOOL
EscDer_NextUTF8String(
    EscDer_ContextT* ctx,
    const UINT8* UTF8String[],
    UINT32* stringLen );

/**
Reads a PrintableString value from the context
with unlimited length.

In fact, just a pointer to the EscDer_ContextT code is returned.

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[out] printableString Will return a pointer to the PrintableString inside the DER code.
\param[out] stringLen Will be updated with the length of PrintableString in byte.
\return TRUE on error.
*/
extern BOOL
EscDer_NextPrintableString(
    EscDer_ContextT* ctx,
    const UINT8* printableString[],
    UINT32* stringLen );

/**
Reads a octet string value from the context
with unlimited length. An octet string is usually an ASCII string.

In fact, just a pointer to the EscDer_ContextT code is returned.

The string can be of type VisibleString, PrintableString or Ia5String.
BitStrings are not included.

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[out] outString Will return a pointer to the String inside the DER code.
\param[out] stringLen Will be updated with the length of String in byte.

\return TRUE on error.
*/
extern BOOL
EscDer_NextAnyString(
    EscDer_ContextT* ctx,
    const UINT8* outString[],
    UINT32* stringLen );

/**
Reads the UTC time from the context with variable length,
as the time might be represented in different formats.

The most common formats are "YYMMDD000000Z", "YYMMDD0000Z" and "YYMMDDHHMMSSZ",
where the first one is the official one.

In fact, just a pointer to the EscDer_ContextT code is returned.

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[out] timeString Will return a pointer to the time inside the DER code.
\param[out] stringLen Will be updated with the length of printableString in byte.
\return TRUE on error.
*/
extern BOOL
EscDer_NextUtcTime(
    EscDer_ContextT* ctx,
    const UINT8* timeString[],
    UINT32* stringLen );

/**
Reads the Generalized time from the context with variable length,
as the time might be represented in different formats.

The most common formats are "YYYYMMDD000000Z", "YYYYMMDD0000Z" and "YYYYMMDDHHMMSSZ",
where the first one is the official one.

In fact, just a pointer to the EscDer_ContextT code is returned.

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[out] timeString Will return a pointer to the time inside the DER code.
\param[out] stringLen Will be updated with the length of printableString in byte.
\return TRUE on error.
*/
extern BOOL
EscDer_NextGeneralizedTime(
    EscDer_ContextT* ctx,
    const UINT8* timeString[],
    UINT32* stringLen );

/**
Reads an OBJECT IDENTIFIER value from the context
with unlimited length.

The first subidentifier is the combined form of
the first identifier components using the formula
(X*40)+Y.

\see ISO/IEC 8825-1:2003 Section 8.19.4

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[out] identifiers Will contain the identifiers of the next oid.
\param[out] maxIdentifiers The maximum number of identifiers to write to.
\param[out] outNumIdentifiers The actual number of identifiers written.
\return TRUE on error.
*/
extern BOOL
EscDer_NextOid(
    EscDer_ContextT* ctx,
    UINT32 identifiers[],
    UINT32 maxIdentifiers,
    UINT32* outNumIdentifiers );

/**
Reads a OBJECT IDENTIFIER (0x06) value from the context
and compares them with the OID components passed.

The first two OID components are passed separately,
not as a combined subidentifier.


\see ISO/IEC 8825-1:2003 Section 8.19.4

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[in] oidComponents Contains the OID components to check.
\param[in] numComponents The number of components to check.
\return TRUE on error.
*/
extern BOOL
EscDer_NextOidCheck(
    EscDer_ContextT* ctx,
    const UINT32 oidComponents[],
    UINT32 numComponents );

/**
Reads a RELATIVE OID (0x0D) value from the context
with unlimited length.

\see ISO/IEC 8825-1:2003 Section 8.20

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[out] identifiers Will contain the identifiers of the next oid.
\param[out] maxIdentifiers The maximum number of identifiers to write to.
\param[out] outNumIdentifiers The actual numbe of identifiers written.
\return TRUE on error.
*/
extern BOOL
EscDer_NextOidRel(
    EscDer_ContextT* ctx,
    UINT32 identifiers[],
    UINT32 maxIdentifiers,
    UINT32* outNumIdentifiers );

/**
Reads a RELATIVE OID (0x0D) value from the context
and compares them with the OID components passed.

\see ISO/IEC 8825-1:2003 Section 8.20

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[in] oidComponents Contains the OID components to check.
\param[in] numComponents The number of components to check.
\return TRUE on error.
*/
extern BOOL
EscDer_NextOidRelCheck(
    EscDer_ContextT* ctx,
    const UINT32 oidComponents[],
    UINT32 numComponents );

/**
Reads a sequence from the DER Context. The sequence is
a new DER context itself, which can be used to access its elements.

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[out] outSequence A new context to access the elements of the sequence.
\return TRUE on error.
*/
extern BOOL
EscDer_NextSequence(
    EscDer_ContextT* ctx,
    EscDer_ContextT* outSequence );

/**
Reads a set from the DER Context. The set is
a new DER context itself, which can be used to access its elements.

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[out] outSet A new context to access the elements of the set.
\return TRUE on error.
*/
extern BOOL
EscDer_NextSet(
    EscDer_ContextT* ctx,
    EscDer_ContextT* outSet );

/**
Reads the next tagged value and returns a context to
to read its contents.
No application tagging supported.

\see ISO/IEC 8825-1:2003 Section 8.14

\param[in] ctx The current context.
\param[out] ctx The updated context.
\param[in] tag The tag to read.
\param[out] taggedContent The content returned content of the tagged value.
\return TRUE on error.
*/
extern BOOL
EscDer_NextTaggedValue(
    EscDer_ContextT* ctx,
    UINT32 tag,
    EscDer_ContextT* taggedContent );

/**
Skips the next element of the code,
no matter which type it is.

\param[in] ctx The current context.
\param[out] ctx The updated context.
\return TRUE on error.
*/
extern BOOL
EscDer_NextSkip(
    EscDer_ContextT* ctx );

/**
Reads the next identifier,
without changing the context state.

\param[in] ctx The current context.
\param[out] tag The tag of the next identifier.
\param[out] cla The class of the next identifier.
\return TRUE on error.
*/
extern BOOL
EscDer_GetIdentifier(
    const EscDer_ContextT* ctx,
    UINT32* tag,
    UINT32* cla );

/**
Returns a pointer to the current location of the code.
\param[in] ctx The current context.
\return A pointer to the next byte of code of the current context.
*/
extern const UINT8*
EscDer_GetCurrentCode(
    const EscDer_ContextT* ctx );

/**
Returns the current offset to the start of the context.
\param[in] ctx The current context.
\return The number of bytes read so far.
*/
extern UINT32
EscDer_GetCurrentPosition(
    const EscDer_ContextT* ctx );

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
