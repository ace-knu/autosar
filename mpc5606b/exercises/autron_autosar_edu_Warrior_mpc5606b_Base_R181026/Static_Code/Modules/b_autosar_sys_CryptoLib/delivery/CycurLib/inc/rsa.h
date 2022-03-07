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
   \file        rsa.h

   \brief       RSA encryption and decryption

   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_RSA_H_
#define _ESC_RSA_H_

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
#ifndef EscRsa_KEY_BITS
/** Size of RSA modulus (in bit): 1024, 1536, 2048, 3072, 4096 */
#    define EscRsa_KEY_BITS 2048U
#endif

#if 1   /* enable(1) if you need RSA key generation */
#    ifndef EscRsa_ENABLE_GENRSA
/** Enable RSA key generation. */
#        define EscRsa_ENABLE_GENRSA
#    endif
#endif

#if 0   /* enable(1) if you want RSA with CRT optimization */
#    ifndef EscRsa_ENABLE_CRT
/** Enable decryption using the Chinese Remainder Theorem (CRT) */
#        define EscRsa_ENABLE_CRT
#    endif
#endif

/***************************************************************
 Set optimization flags according to global speed define.
 The default configuration optimizes for verifications with a
 short exponent of 2^16+1
 The following configurations yield the best performance in
 the given use case:
    VERY short exponent (3) verification/decryption:
        Disable all (no MontgomeryMul, no SlidingWindow)
    Short exponent (2^16+1) verification/decryption:
        Use MontgomeryMultiplication
    Short and VERY short exponent (3) at same time:
        Use MontgomeryMultiplication and enable EscRsa_NO_MONTGOM_SHORT_EXP
    Long/random exponent signature verification/generation or
    encryption/decryption:
        Use MontgomeryMultiplication + SlidingWindow

   Note: the use of sliding window and Montgomery speeds up calculation with big
   exponents substantially, but increases ROM and RAM usage
   The use of Montgomery with the EscRsa_NO_MONTGOM_SHORT_EXP option increases
   ROM usage but automatically chooses the best multiplication algorithm for short
   and very short (3) exponents.
 ***************************************************************/
#ifdef Esc_OPTIMIZE_SPEED
/* speed optimization */
#    if 1                   /* disable(0) if you only use VERY short exponent (3) */
#        ifndef EscRsa_USE_MONTGOM_MUL
/**          Enable the Montgomery Reduction */
#            define EscRsa_USE_MONTGOM_MUL
#        endif
#        if 0               /* enable(1) for dual use of short and VERY short exponent (3) */
#            ifndef EscRsa_NO_MONTGOM_SHORT_EXP
/**              Disable the Montgomery Reduction when using the exponent 3 */
#                define EscRsa_NO_MONTGOM_SHORT_EXP
#            endif
#        endif
#    endif
#    if 0                   /* enable(1) for long/random exponent */
#        ifndef EscRsa_USE_SLIDING_WINDOW
/**          Enable for using the Sliding Window algorithm
             Increases speed, but also increases code size and stack used */
#            define EscRsa_USE_SLIDING_WINDOW
#        endif
#    endif
#else
/* size optimization */
#    if 0                   /* enable(1) if you only use short exponents (32 bit) in order to save about 2 * EscRsa_KEY_BYTES byte of stack */
#        ifndef EscRsa_USE_SHORT_EXPONENT
/**          Enable the stack saving option when using only short (32 bit) exponents */
#            define EscRsa_USE_SHORT_EXPONENT
#        endif
#    endif
#    if 0                   /* enable(1) if you want to enable an inconvenient interface of ModExpLong and ModExp in order to save about 2 * EscRsa_KEY_BYTES of stack - cannot be used together with any PKCS module */
#        ifndef EscRsa_ENABLE_STACK_SAVING_INTERFACE
/**          Enable an inconvenient interface for reducing the stack usage */
#            define EscRsa_ENABLE_STACK_SAVING_INTERFACE
#        endif
#    endif
#endif

#ifdef EscRsa_USE_SLIDING_WINDOW
#    ifndef EscRsa_WINDOW_SIZE
/**      Window size for the Sliding Window algorithm
         The higher the window size, the higher the RAM usage! */
#        define EscRsa_WINDOW_SIZE 4U
#    endif
#endif

/* Everything below this line is not to be configured */

#ifdef Esc_HAS_INT64
/** RSA base for calculation (16 or 32 bits) */
#    define EscRsa_RSA_BASE 32U
/** half word for calculation (e.g., factor; 16 or 32 bit) */
#    define EscRsa_HWORD UINT32
/** full word for calculation (e.g., result; 32 or 64 bit) */
#    define EscRsa_FWORD UINT64
#else
/** RSA base for calculation (16 or 32 bits) */
#    define EscRsa_RSA_BASE 16U
/** half word for calculation (e.g., factor; 16 or 32 bit) */
#    define EscRsa_HWORD UINT16
/** full word for calculation (e.g., result; 32 or 64 bit) */
#    define EscRsa_FWORD UINT32
#endif

/** Size of RSA modulus in byte */
#define EscRsa_KEY_BYTES ( EscRsa_KEY_BITS / 8U )

/** Size of one RSA Word in byte */
#define EscRsa_WORD_SIZE ( EscRsa_RSA_BASE / 8U )

/** Length of RSA modulus in words */
#define EscRsa_RSA_SIZE_WORDS  ( EscRsa_KEY_BYTES / EscRsa_WORD_SIZE )

/** The maximum value of one HWORD */
#define EscRsa_MAX_VAL ( ( ( (EscRsa_FWORD)1U ) << EscRsa_RSA_BASE ) - 1U )

/* Configuration check */
#if ( ( EscRsa_KEY_BITS - ( ( EscRsa_KEY_BITS / 8U ) * 8U ) ) != 0U )
#    error "Wrong EscRsa_KEY_BITS!"
#endif

#if ( EscRsa_KEY_BITS != 1024U ) && ( EscRsa_KEY_BITS != 1536U ) && ( EscRsa_KEY_BITS != 2048U ) && ( EscRsa_KEY_BITS != 3072U ) && ( EscRsa_KEY_BITS != 4096U )
#    error "The size of the RSA modulus must be defined to 1024, 1536, 2048, 3072 or 4096"
#endif

#ifdef EscRsa_ENABLE_GENRSA
#    ifndef EscRsa_PRIMETEST_ITER
/** Number of iterations of the Miller-Rabin primality test */
#        define EscRsa_PRIMETEST_ITER 5U
#    endif
/** A random number generator is required by the RSA Key Generation  */
#    include "random.h"
#endif

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/** RSA field element. */
typedef struct {
    /** RSA field element in 16bit / 32bit words */
    EscRsa_HWORD words[ EscRsa_RSA_SIZE_WORDS ];
    /* No carry needed */
} EscRsa_FieldElementT;

#if defined( EscRsa_ENABLE_GENRSA ) || defined( EscRsa_ENABLE_CRT )
/** RSA key pair. */
typedef struct {
    /** RSA public modulus n = p * q */
    EscRsa_FieldElementT n;
    /** RSA public exponent e */
    EscRsa_FieldElementT e;
    /** RSA private exponent d = e^(-1) mod (p-1)*(q-1) */
    EscRsa_FieldElementT d;
    /** RSA private first prime p (used for CRT) */
    EscRsa_FieldElementT p;
    /** RSA private second prime q (used for CRT) */
    EscRsa_FieldElementT q;
    /** RSA private d mod (p-1) (used for CRT) */
    EscRsa_FieldElementT dmp1;
    /** RSA private d mod (q-1) (used for CRT) */
    EscRsa_FieldElementT dmq1;
    /** RSA private q^(-1) mod p (used for CRT) */
    EscRsa_FieldElementT iqmp;
} EscRsa_KeyPairT;
#endif

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

#ifndef EscRsa_ENABLE_STACK_SAVING_INTERFACE

/**
Modular exponentiation with big exponents, which is used for
RSA decryption or RSA signature generation.
The private key consists of a modulus and a private exponent.

c = m^e mod modulus

Implements RSASP1 of the PKCS#1 standard.

The most significant modulus bit must be set.

\param[in] message Pointer to the data that is going to be signed/decrypted.
\param[in] modulus Pointer to public modulus.
\param[in] exponent Pointer to private exponent.
\param[out] result Pointer to the generated signature/plaintext.

\return TRUE on error.

\note This function uses big endian input and output.
*/
extern BOOL
EscRsa_ModExpLong(
    const UINT8 message[],
    const UINT8 modulus[],
    const UINT8 exponent[],
    UINT8 result[] );

/**
Modular exponentiation with small exponents, which is used for
RSA encryption or RSA signature verification.
The public key consists of a modulus and a public exponent.

c = m^e mod modulus

Implements RSAVP1 of the PKCS#1 standard.

The most significant modulus bit must be set.

\param[in] message Pointer to the input data.
\param[in] modulus Pointer to public modulus.
\param[in] exponent Pointer to private exponent.
\param[out] result Pointer to the result of the exponentiation.

\return TRUE on error.

\note This function uses big endian input and output.
*/
extern BOOL
EscRsa_ModExp(
    const UINT8 message[],
    const UINT8 modulus[],
    const UINT32 exponent,
    UINT8 result[] );

#else /* EscRsa_ENABLE_STACK_SAVING_INTERFACE */

/**
Modular exponentiation with big exponents, which is used for
RSA decryption or RSA signature generation.
The private key consists of a modulus and a private exponent.

c = m^e mod modulus

Implements RSASP1 of the PKCS#1 standard.

The most significant modulus bit must be set.

\param[in] message Pointer to the data that is going to be signed/decrypted (array of 16bit or 32bit unsigned integers depending on presence of 64bit integers (Esc_HAS_INT64)).
\param[out] message Pointer to the generated signature/plaintext (array of 16bit or 32bit unsigned integers depending on presence of 64bit integers (Esc_HAS_INT64)).
\param[in] modulus Pointer to public modulus (array of 16bit or 32bit unsigned integers depending on presence of 64bit integers (Esc_HAS_INT64)).
\param[in] exponent_field Pointer to private exponent (array of 16bit or 32bit unsigned integers depending on presence of 64bit integers (Esc_HAS_INT64)).

\return TRUE on error.

\note This function uses big endian input and output.

\note When using EscRsa_ENABLE_STACK_SAVING_INTERFACE you have to take care formatting the input and output yourself!
*/
extern BOOL
EscRsa_ModExpLongSaveStack(
    EscRsa_FieldElementT* message,
    const EscRsa_FieldElementT* modulus,
    const EscRsa_FieldElementT* exponent_field );

/**
Modular exponentiation with small exponents, which is used for
RSA encryption or RSA signature verification.
The public key consists of a modulus and a public exponent.

c = m^e mod modulus

Implements RSAVP1 of the PKCS#1 standard.

The most significant modulus bit must be set.

\param[in] message Pointer to the input data (array of 16bit or 32bit unsigned integers depending on presence of 64bit integers (Esc_HAS_INT64)).
\param[out] message Pointer to the result of the exponentiation (array of 16bit or 32bit unsigned integers depending on presence of 64bit integers (Esc_HAS_INT64)).
\param[in] modulus Pointer to public modulus (array of 16bit or 32bit unsigned integers depending on presence of 64bit integers (Esc_HAS_INT64)).
\param[in] exponent Pointer to private exponent.

\return TRUE on error.

\note This function uses big endian input and output.

\note When using EscRsa_ENABLE_STACK_SAVING_INTERFACE you have to take care formatting the input and output yourself!
*/
extern BOOL
EscRsa_ModExpSaveStack(
    EscRsa_FieldElementT* message,
    const EscRsa_FieldElementT* modulus,
    const UINT32 exponent );

#endif /* EscRsa_ENABLE_STACK_SAVING_INTERFACE */

#ifdef EscRsa_ENABLE_GENRSA

/**
RSA key pair generation

\param[in] randCtx Pointer to the random context, used to get random numbers.
\param[out] keyPair Pointer to the generated RSA key pair.
\param[in] pubExp Public exponent of the RSA key pair, typically set to 65535U.

\return TRUE on error.
*/
extern BOOL
EscRsa_GenerateKeyPair(
    EscRandom_ContextT* randCtx,
    EscRsa_KeyPairT* keyPair,
    UINT32 pubExp );

#endif /* EscRsa_ENABLE_GENRSA */

#ifdef EscRsa_ENABLE_CRT

#    ifndef EscRsa_ENABLE_STACK_SAVING_INTERFACE

/**
Modular exponentiation with Chinese Remainder Theorem

c = m^d mod modulus

Implements RSASP1 of the PKCS#1 standard.

The most significant modulus bit must be set.

\param[out] result Pointer to the result of the exponentiation (array of 8bit unsigned integers).
\param[in] message Pointer to the input data (array of 8bit unsigned integers).
\param[in] keyPair Pointer to the key pair, the private part is used.

\return TRUE on error.

\note This function uses big endian input and output.
*/
extern BOOL
EscRsa_ModExpCrt(
    UINT8 result[],
    const UINT8 message[],
    const EscRsa_KeyPairT* keyPair );

#    else /* EscRsa_ENABLE_STACK_SAVING_INTERFACE */

/**
Modular exponentiation with Chinese Remainder Theorem

c = m^d mod modulus

Implements RSASP1 of the PKCS#1 standard.

The most significant modulus bit must be set.

\param[out] result Pointer to the result of the exponentiation (array of 16bit or 32bit unsigned integers depending on presence of 64bit integers (Esc_HAS_INT64)).
\param[in] message Pointer to the input data (array of 16bit or 32bit unsigned integers depending on presence of 64bit integers (Esc_HAS_INT64)).
\param[in] keyPair Pointer to the key pair, the private part is used.

\return TRUE on error.

\note This function uses little endian input and output.
*/
extern BOOL
EscRsa_ModExpCrtSaveStack(
    EscRsa_FieldElementT* result,
    const EscRsa_FieldElementT* message,
    const EscRsa_KeyPairT* keyPair );

#    endif /* EscRsa_ENABLE_STACK_SAVING_INTERFACE */
#endif /* EscRsa_ENABLE_CRT */

#if ( !defined( EscRsa_ENABLE_STACK_SAVING_INTERFACE ) ) || ( defined( EscRsa_ENABLE_GENRSA ) ) || ( defined( EscRsa_ENABLE_CRT ) )
/**
Converts a byte array into one EscRsa_FieldElement.

\param[out] dest Pointer to the resulting FieldElement.
\param[in] source Pointer to the input array.
\param[in] len Length of the input array, the maximum length is EscRsa_KEY_BYTES.
*/
extern void
EscRsaFe_FromBytesBE(
    EscRsa_FieldElementT* dest,
    const UINT8 source[],
    UINT16 len );

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
