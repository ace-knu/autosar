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
   \file        ecc.h

   \brief       Elliptic curve cryptography

   Elliptic Curve Diffie/Hellman (ECDH) and
   Elliptic Curve Digital Signature Algorithm (ECDSA)

   Byteorder of the long numbers is Little endian

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_ECC_H_
#define _ESC_ECC_H_

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

/** Enables the secPr1 curves */
#define EscEcc_secPr1 1

/** Enables the brainpoolPr1 curves */
#define EscEcc_brainpoolPr1 2

/* User definable configuration */

#ifndef EscEcc_CURVE_TYPE
/** Set the curve type.
    Supported curves:
    - EscEcc_secPr1
    - EscEcc_brainpoolPr1 */
#   define EscEcc_CURVE_TYPE EscEcc_secPr1
#endif

#ifndef EscEcc_KEY_LENGTH
/** Set the ECC key length (in bits).
    Supported values:
    - secPr1:  160U, 192U, 224U, 256U, 384U or 521U
    - brainpoolPr1: 160U, 192U, 224U, 256U, 320U, 384U or 512U

    For 521 bits: All input and output byte arrays have a size of 66 bytes.
    But only the first 521 bits are used (in the last byte only the first bit is used) */
#    define EscEcc_KEY_LENGTH 160U
#endif

#if 0
/** Disable ECDH */
#    define EscEcc_ECDH_DISABLE
#endif

#if 0
/** Disable ECDSA */
#    define EscEcc_ECDSA_DISABLE
#endif

/***************************************************************
 Set optimization flags according to global speed define.
 ***************************************************************/
#ifdef Esc_OPTIMIZE_SPEED
#    if 1
#        ifndef EscEcc_USE_SLIDING_WINDOW
/**          Enable for using the Sliding Window algorithm
             Increases speed, but also increases code size and stack used */
#            define EscEcc_USE_SLIDING_WINDOW
#        endif
#    endif

#    ifdef EscEcc_USE_SLIDING_WINDOW
#        ifndef EscEcc_WINDOW_SIZE
/**          Window size for the Sliding Window algorithm 
             The higher the window size, the higher the RAM usage! */
#            define EscEcc_WINDOW_SIZE 4U
#        endif
#    endif

#    ifndef EscEcc_ECDSA_DISABLE
#        if 1
#            ifndef EscEcc_USE_JACOBIAN_DUAL_MULTIPLY_ADD
/**              Enable for using the 'Shamir's trick' for signature verification */
#                define EscEcc_USE_JACOBIAN_DUAL_MULTIPLY_ADD
#            endif
#        endif
#    endif
#endif

/* Everything below this line is not to be configured */

/** Invalid EscEcc_PointT type */
#define C_PT_NONE     0U
/** Affine coordinates EscEcc_PointT type */
#define C_PT_AFFINE   1U
/** Jacobian coordinates EscEcc_PointT type */
#define C_PT_JACOBIAN 2U

/** Maximum number of WORD of a EscEcc_FieldElementT. Key length + 2. */
#if ( EscEcc_CURVE_TYPE == EscEcc_secPr1 )
#   if ( EscEcc_KEY_LENGTH == 160U )
#       define EscEcc_MAX_WORDS  7U
#   elif ( EscEcc_KEY_LENGTH == 192U )
#       define EscEcc_MAX_WORDS  7U
#   elif ( EscEcc_KEY_LENGTH == 224U )
#       define EscEcc_MAX_WORDS  8U
#   elif ( EscEcc_KEY_LENGTH == 256U )
#       define EscEcc_MAX_WORDS  9U
#   elif ( EscEcc_KEY_LENGTH == 384U )
#       define EscEcc_MAX_WORDS  13U
#   elif ( EscEcc_KEY_LENGTH == 521U )
#       define EscEcc_MAX_WORDS  18U
#   else
#       error "ECC key length must be defined to 160U, 192U, 224U, 256U, 384U or 521U for secPr1 curves"
#   endif /* EscEcc_KEY_LENGTH  */
#elif ( EscEcc_CURVE_TYPE == EscEcc_brainpoolPr1 )
#   if ( EscEcc_KEY_LENGTH == 160U )
#       define EscEcc_MAX_WORDS  6U
#   elif ( EscEcc_KEY_LENGTH == 192U )
#       define EscEcc_MAX_WORDS  7U
#   elif ( EscEcc_KEY_LENGTH == 224U )
#       define EscEcc_MAX_WORDS  8U
#   elif ( EscEcc_KEY_LENGTH == 256U )
#       define EscEcc_MAX_WORDS  9U
#   elif ( EscEcc_KEY_LENGTH == 320U )
#       define EscEcc_MAX_WORDS  11U
#   elif ( EscEcc_KEY_LENGTH == 384U )
#       define EscEcc_MAX_WORDS  13U
#   elif ( EscEcc_KEY_LENGTH == 512U )
#       define EscEcc_MAX_WORDS  17U
#   else
#       error "ECC key length must be defined to 160U, 192U, 224U, 256U, 320U or 512U for brainpoolPr1 curves"
#   endif /* EscEcc_KEY_LENGTH  */
#else
# error "Not supported EscEcc_CURVE_TYPE!"
#endif /* EscEcc_CURVE_TYPE */

/** The size of the key in bytes */
#if ( EscEcc_KEY_LENGTH  != 521U )
#   define ECC_KEY_BYTES ( EscEcc_KEY_LENGTH / 8U )
#else
#   define ECC_KEY_BYTES 66U
#endif

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** A field element with long number arithmetic */
typedef struct {
    /** the words of the long number */
    UINT32 word[ EscEcc_MAX_WORDS ];
} EscEcc_FieldElementT;

/** Field parameters */
typedef struct {
    /** Precalculated P, used in barrett reduction */
    EscEcc_FieldElementT precalc_my_p;
    /** Prime */
    EscEcc_FieldElementT prime_p;
    /** Length of p in words */
    UINT8 pLen;
} EscEcc_FieldT;

/** Elliptic curve point */
typedef struct {
    /** Type of the curve */
    UINT8 type;
    /** X-Coordinate */
    EscEcc_FieldElementT x;
    /** Y-Coordinate */
    EscEcc_FieldElementT y;
    /** Z-Coordinate */
    EscEcc_FieldElementT z;
} EscEcc_PointT;

/** Elliptic curve */
typedef struct {
    /** Coefficient a */
    EscEcc_FieldElementT coefficient_a;
    /** Coefficient b */
    EscEcc_FieldElementT coefficient_b;
    /** Base point G */
    EscEcc_PointT base_point_G;
    /** n */
    EscEcc_FieldT base_point_order_n;
    /** Cofactor h */
    UINT32 cofactor_h;
    /** Field parameters */
    EscEcc_FieldT ecc_field_params;
} EscEcc_CurveT;

/** Public key for ECC */
typedef struct {
    /** Pointer to x */
    UINT8 x[ ECC_KEY_BYTES ];
    /** Pointer to y */
    UINT8 y[ ECC_KEY_BYTES ];
} EscEcc_PublicKeyT;

/** ECDSA signature */
typedef struct {
    /** Bytes of r */
    UINT8 r_bytes[ ECC_KEY_BYTES ];
    /** Bytes of s */
    UINT8 s_bytes[ ECC_KEY_BYTES ];
} EscEcc_SignatureT;

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

#include "ecc_curves32.h"

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/**
This function generates the corresponding public key

- Q = d * G
- Public Key:  Q
- Private Key: d
- Basepoint:   G

\param[out] pQ Public key point (affine).
\param[in] d Private key field element d of length ECC_KEY_BYTES (maximum allowed size is EscEcc_KEY_LENGTH bits).

\return TRUE on error.
*/
extern BOOL
EscEcc_PublicKeyGeneration(
    EscEcc_PublicKeyT* pQ,
    const UINT8 d[] );

/**
This function performs an embedded public key validation

Check, that:
- Q != (0)
- Qx & Qy are properly represented elements in GF(p)
- Q lies on elliptic curve defined by a & b

\param[in] pQ Public key point (affine).

\return TRUE on error or validation error
*/
extern BOOL
EscEcc_EmbeddedPublicKeyValidation(
    const EscEcc_PublicKeyT* pQ );

/**
This function validates the public key

Check, that:
- Q != (0)
- Qx & Qy are properly represented elements in GF(p)
- Q lies on elliptic curve defined by a & b
- Q * n = (0)

\param[in] pQ Public key point (affine).

\return TRUE on error or validation error
*/
extern BOOL
EscEcc_PublicKeyValidation(
    const EscEcc_PublicKeyT* pQ );

#ifndef EscEcc_ECDSA_DISABLE
/**
This function generates the corresponding signature for a hashed message

\param[out] ecc_sig ECC signature.
\param[in] msg_hash Hash of signing message of length ECC_KEY_BYTES (maximum allowed size is EscEcc_KEY_LENGTH bits).
\param[in] d Private key field element d of length ECC_KEY_BYTES (maximum allowed size is EscEcc_KEY_LENGTH bits).
\param[in] k Field element unpredictable integer k of length ECC_KEY_BYTES (maximum allowed size is EscEcc_KEY_LENGTH bits).

\return TRUE on error.

*/
extern BOOL
EscEcc_SignatureGeneration(
    EscEcc_SignatureT* ecc_sig,
    const UINT8 msg_hash[],
    const UINT8 d[],
    const UINT8 k[] );

/**
This function verifies the corresponding signature for a hashed message.
\warning This function does NOT validate the public key pQ! You can use EscEcc_PublicKeyValidation()
to check if the public key is valid. 

\param[in] msg_hash Hashed signing message of length ECC_KEY_BYTES (maximum allowed size is EscEcc_KEY_LENGTH bits).
\param[in] ecc_sig ECC signature.
\param[in] pQ Public key point Q.

\return TRUE on error.

*/
extern BOOL
EscEcc_SignatureVerification(
    const UINT8 msg_hash[],
    const EscEcc_SignatureT* ecc_sig,
    const EscEcc_PublicKeyT* pQ );

#endif /* EscEcc_ECDSA_DISABLE */

#ifndef EscEcc_ECDH_DISABLE
/**
This function computes the shared secret z based on ECDH

- P = dA * QB
- Shared Secret:    z = P->x
- Private Key of A: dA
- Public Key of B:  QB

\warning This function does NOT validate the public key pQB! You can use EscEcc_PublicKeyValidation()
to check if the public key is valid. 

\param[out] z Shared secret field element z of length ECC_KEY_BYTES (maximum allowed size is EscEcc_KEY_LENGTH bits).
\param[in] dA Private key field element d of A of length ECC_KEY_BYTES (maximum allowed size is EscEcc_KEY_LENGTH bits).
\param[in] pQB Public key point of B (affine).

\return TRUE on error.
*/
extern BOOL
EscEcc_ComputeSharedSecret(
    UINT8 z[],
    const UINT8 dA[],
    const EscEcc_PublicKeyT* pQB );

#endif /* EscEcc_ECDH_DISABLE */

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
