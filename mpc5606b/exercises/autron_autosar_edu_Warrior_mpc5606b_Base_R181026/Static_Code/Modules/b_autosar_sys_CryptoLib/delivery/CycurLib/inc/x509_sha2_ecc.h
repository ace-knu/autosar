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
   \file        x509_sha2_ecc.h

   \brief       x.509 Parser supporting SHA2 with ECDSA

   Only algorithm sha2WithECDSA is supported.

   Byteorder of all long numbers is Big-Endian.
   $Rev: 2068 $
 */
/***************************************************************************/

#ifndef _ESC_X509_SHA2_ECC_H_
#define _ESC_X509_SHA2_ECC_H_

/***************************************************************************
 * 1. INCLUDES                                                             *
 ***************************************************************************/

#include "x509.h"
#include "der.h"
#include "sha_256.h"
#include "ecc.h"

#if EscX509_MODE == EscX509_SHA2_WITH_ECC

#    ifdef  __cplusplus
/* *INDENT-OFF* */
extern "C" {
 /* *INDENT-ON* */
#    endif

/***************************************************************************
 * 2. DEFINES                                                              *
 ***************************************************************************/

/***************************************************************************
 * 3. DECLARATIONS                                                         *
 ***************************************************************************/

/***************************************************************************
 * 4. CONSTANTS                                                            *
 ***************************************************************************/

/***************************************************************************
 * 5. FUNCTION PROTOTYPES                                                  *
 ***************************************************************************/

/* local functions prototypes - not intended to be used directly */

/**
Checks the signature algorithm of a given certificate and returns
FALSE if SHA-2 with ECDSA is used.

\param[in] certCtx Context of the DER encoded x.509 certificate.
\param[out] certCtx Updated context of the DER encoded x.509 certificate.
\return TRUE on error.
\note Local function prototype - not intended to be used directly.
*/
extern BOOL
EscX509Sha2Ecc_CheckSignAlgorithm(
    EscDer_ContextT* certCtx );

/**
Reads the signature of a given x.509 certificate.

\param[in] ctx Context of the DER encoded x.509 certificate.
\param[out] ctx Updated context of the DER encoded x.509 certificate.
\param[out] cert Updated x.509 certificate structure.
\return TRUE on error.
\note Local function prototype - not intended to be used directly.
*/
extern BOOL
EscX509Sha2Ecc_GetSignature(
    EscDer_ContextT* ctx,
    EscX509_CertificateT* cert );

/**
Reads the public key of a given x.509 certificate.

\param[in] certCtx Context of the DER encoded x.509 certificate.
\param[out] certCtx Updated context of the DER encoded x.509 certificate.
\param[out] cert Updated x.509 certificate structure.
\return TRUE on error.
\note Local function prototype - not intended to be used directly.
\note We only support named curves.
*/
extern BOOL
EscX509Sha2Ecc_GetPubKey(
    EscDer_ContextT* certCtx,
    EscX509_CertificateT* cert );

/***************************************************************************
 * 6. MACRO FUNCTIONS                                                      *
 ***************************************************************************/
#    ifdef  __cplusplus
/* *INDENT-OFF* */
}
/* *INDENT-ON* */
#    endif

#endif /* EscX509_MODE == EscX509_SHA2_WITH_ECC */

#endif /* _ESC_X509_SHA2_ECC_H_ */
/***************************************************************************
 * 7. END                                                                  *
 ***************************************************************************/
