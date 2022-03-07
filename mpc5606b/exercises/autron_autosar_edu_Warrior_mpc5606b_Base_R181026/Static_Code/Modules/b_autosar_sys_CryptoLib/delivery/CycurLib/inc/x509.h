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
   \file        x509.h

   \brief       x.509 Parser

   Algorithms sha1WithRSAEncryption, sha256WithRSAEncryption and
   sha2WithECDSA are supported.

   Byteorder of all long numbers is Big-Endian.
   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_X509_H_
#define _ESC_X509_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#include "cycurlib_config.h"
#include "der.h"

#ifdef  __cplusplus
/* *INDENT-OFF* */
extern "C" {
 /* *INDENT-ON* */
#endif

/***************************************************************************
 * 2. DEFINES                                                              *
 ***************************************************************************/

/** enables the X509 module using SHA-1 with RSA */
#define EscX509_SHA1_WITH_RSA 1

/** enables the X509 module using SHA-256 with RSA */
#define EscX509_SHA2_WITH_RSA 2

/** enables the X509 module using SHA-256 with ECDSA */
#define EscX509_SHA2_WITH_ECC 3

/* User definable configuration */

#if 1
#    ifndef EscX509_PARSE_INFO
        /** Parse all accessible certificate attributes. If undefined,
            only the public key and the signature will be parsed. */
#       define EscX509_PARSE_INFO
#    endif
#endif

#ifndef EscX509_MODE
     /** Defines the used X509 Mode */
#    define EscX509_MODE EscX509_SHA1_WITH_RSA
#endif

/* Everything below this line is not to be configured. */

#if ( EscX509_MODE != EscX509_SHA2_WITH_ECC ) && ( EscX509_MODE != EscX509_SHA1_WITH_RSA ) && ( EscX509_MODE != EscX509_SHA2_WITH_RSA )
#    error "EscX509_MODE either needs to be set to EscX509_SHA2_WITH_ECC, EscX509_SHA1_WITH_RSA or EscX509_SHA1_WITH_RSA."
#endif

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

#if ( EscX509_MODE == EscX509_SHA1_WITH_RSA ) || ( EscX509_MODE == EscX509_SHA2_WITH_RSA )

/** A RSA public key */
typedef struct {
    /** Pointer to the modulus in big endian format.*/
    const UINT8* modulus;
    /** Number of bits inside the public key */
    UINT32 modulusBits;

    /** Contains the public exponent */
    UINT32 pubExp;
} EscX509_PubKeyT;

/** A RSA signature */
typedef struct {
    /** Pointer to the signature */
    const UINT8 * signBytes;
    /** Number of bits of the signature */
    UINT32 signLenBits;
} EscX509_SignatureT;

#elif EscX509_MODE == EscX509_SHA2_WITH_ECC

/** An ECC public key */
typedef struct {
    /** Pointer to the bytes of the x coordinate */
    const UINT8 * x;
    /** Number of bytes x points to */
    UINT32 xLen;
    /** Pointer to the bytes of the y coordinate */
    const UINT8 * y;
    /** Number of bytes y points to */
    UINT32 yLen;
} EscX509_PubKeyT;

/** An ECDSA signature */
typedef struct {
    /** Pointer to the bytes of r */
    const UINT8 * r;
    /** Number of bytes r points to */
    UINT32 rLen;
    /** Pointer to the bytes of s */
    const UINT8 * s;
    /** Number of bytes s points to */
    UINT32 sLen;
} EscX509_SignatureT;

#endif

/** Represents a long integer */
typedef struct {
    /** Bytes of the integer in big endian format */
    const UINT8 * intBytes;
    /** Number of bytes intBytes points to */
    UINT32 intLen;
} EscX509_IntegerT;

/** Represents a human readable string.
The string is not zero terminated. */
typedef struct {
    /** Points to the first byte of the string or NULL if stringLen is 0U. */
    const UINT8 * stringBytes;
    /** Number of bytes of the string */
    UINT32 stringLen;
} EscX509_StringT;

#ifdef EscX509_PARSE_INFO
/** Relative distinguished name. */
typedef struct {
    /** Country name. (C) */
    EscX509_StringT country;
    /** Organization name. (O) */
    EscX509_StringT organization;
    /** Organizational unit name. (OU) */
    EscX509_StringT organizationalUnit;
    /** Common name. (CN) */
    EscX509_StringT commonName;
    /** Locality name. (L)*/
    EscX509_StringT locality;
    /** State or province name. (ST) */
    EscX509_StringT stateOrProvince;
} EscX509_DistinguishedNameT;
#endif

/** The part of the certificate used for hashkey calculation.
Required to verify the certificate. */
typedef struct {
    /** Start of the tbsCertificate */
    const UINT8 * certStart;
    /** Length of the tbsCertificate in byte */
    UINT32 certLen;
} EscX509_TbsCertificateT;

/** A x.509 certificate. */
typedef struct {
    /** TBSCertificate element for hashkey calculation */
    EscX509_TbsCertificateT tbsCertificate;

#ifdef EscX509_PARSE_INFO
    /** Version of the certificate. Lowest version is 1. */
    UINT32 version;
    /** Certificates serial number. */
    EscX509_IntegerT serialNumber;
    /** Issuer of the certificate. */
    EscX509_DistinguishedNameT issuer;
    /** UTCTime notBefore */
    EscX509_StringT notBefore;
    /** UTCTime notAfter */
    EscX509_StringT notAfter;
    /** Subject which is certified. */
    EscX509_DistinguishedNameT subject;
#endif

    /** Public key of the certificate */
    EscX509_PubKeyT pubKey;

    /** The certificates signature */
    EscX509_SignatureT signature;
} EscX509_CertificateT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
Parses a certificate and returns it's content in the specified
X509_certificate structure. The pointers of the X509_certificate
point to locations inside certCode array, so it must not be deleted.

\param[out] cert The parsed certificate.
\param[in] certCode Pointer to the beginning of a DER encoded x.509 certificate.
\param[in] certCodeLen Exact number of bytes of the certificate.
\return TRUE on error.
*/
extern BOOL
EscX509_Parse(
    EscX509_CertificateT* cert,
    const UINT8 certCode[],
    UINT32 certCodeLen );

/**
Verifies a parsed certificate against a verification key.

\param[in] cert The parsed certificate.
\param[in] verificationKey The key to verify the certificate against.
\return TRUE on error or if verification fails.
*/
extern BOOL
EscX509_VerifyWithKey(
    const EscX509_CertificateT* cert,
    const EscX509_PubKeyT* verificationKey );

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
