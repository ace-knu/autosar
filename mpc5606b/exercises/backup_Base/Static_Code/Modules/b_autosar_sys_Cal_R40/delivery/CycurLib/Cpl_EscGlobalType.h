/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cpl_EscGlobalType.h                                           **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crypto Abstraction Library Module                     **
**                                                                            **
**  PURPOSE   : Header file for global types                                  **
**                - CycurLib interface                                        **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By           Description                           **
********************************************************************************
** 1.1.0     23-Jan-2016   Sinil        Redmine #7276                         **
** 1.0.10    06-Oct-2016   Sinil        Redmine #6195                         **
** 1.0.9     20-Sep-2016   Sinil        Redmine #5542                         **
** 1.0.8     10-Aug-2016   Sinil        Redmine #5747                         **
** 1.0.7     08-Jul-2016   Sinil        Redmine #5540                         **
** 1.0.6     01-Jun-2016   Sinil        Redmine #5093, #5094                  **
** 1.0.5     16-May-2016   Sinil        Redmine #4797                         **
** 1.0.0     10-Mar-2015   Autron       Initial version                       **
*******************************************************************************/

#ifndef CPL_ESCGLOBALTYPES_H
#define CPL_ESCGLOBALTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "cycurlib_config.h"
#include "aes_ecb.h"
#include "aes_cbc.h"
#include "rsa.h"
#if (CAL_FBLLIB_USED == STD_ON)
#include "Fbl_Shared.h"
#else
#include "sha_1.h"
#include "pkcs1_v15.h"
#endif
#include "hmac_sha_1.h"
#include "hmac_sha_2.h"
#include "aes_omac1.h"
#include "random.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* 16 */
#define ESC_AES_KEY_BYTES_LEN                           EscAes_KEY_BYTES
/* 16 */
#define ESC_AES_IV_BYTES_LEN                            EscAes_IV_BYTES
/* 256 */
#define ESC_RSA_KEY_BYTES_LEN                           EscRsa_KEY_BYTES
/* 20 */
#define ESC_SHA1_DIGEST_LEN                             EscSha1_DIGEST_LEN
/* 32 */
#define ESC_SHA256_DIGEST_LEN                           EscSha256_DIGEST_LEN
/* 2 */
#define ESC_PKCS1V15_DIGEST_TYPE_SHA1                   EscPkcs1V15_DIGEST_TYPE_SHA1

/*******************************************************************************
**                       Global Data Types                                    **
*******************************************************************************/
#if ((CAL_HASH_STATUS == STD_ON) && (CAL_ESCSHA1_STATUS == STD_ON))
/* Cpl_EscSha1ContextBuffer size : 96 */
typedef struct STag_Cpl_EscSha1ContextBuffer
{
  /* Define job state */
  VAR(Cal_AlignType, CAL_VAR_NOINIT) ddJobState;

  /* CycurLib Sha1 primitive library context */
  VAR(EscSha1_ContextT, CAL_VAR_NOINIT) ddSha1Context;
} Cpl_EscSha1ContextBuffer;
#endif

#if (((CAL_MAC_GENERATE_STATUS == STD_ON) && (CAL_ESCHMACSHA1GENERATE_STATUS == STD_ON)) \
  || ((CAL_MAC_VERIFY_STATUS == STD_ON) && (CAL_ESCHMACSHA1VERIFY_STATUS == STD_ON)))
/* Cpl_EscHmacSha1ContextBuffer size : 164 */
typedef struct STag_Cpl_EscHmacSha1ContextBuffer
{
  /* Define job state */
  VAR(Cal_AlignType, CAL_VAR_NOINIT) ddJobState;

  /* Stores context pointer in Hmac Sha1 */
  VAR(EscHmacSha1_ContextT, AUTOMATIC) ddSha1Context;
} Cpl_EscHmacSha1ContextBuffer;
#endif

#if (((CAL_MAC_GENERATE_STATUS == STD_ON) && (CAL_ESCHMACSHA256GENERATE_STATUS == STD_ON)) \
  || ((CAL_MAC_VERIFY_STATUS == STD_ON) && (CAL_ESCHMACSHA256VERIFY_STATUS == STD_ON)))
/* Cpl_EscHmacSha256ContextBuffer size : 176 */
typedef struct STag_Cpl_EscHmacSha256ContextBuffer
{
  /* Define job state */
  VAR(Cal_AlignType, CAL_VAR_NOINIT) ddJobState;

  /* Stores context pointer in Hmac Sha256 */
  VAR(EscHmacSha256_ContextT, AUTOMATIC) ddSha256Context;
} Cpl_EscHmacSha256ContextBuffer;
#endif

#if (((CAL_MAC_GENERATE_STATUS == STD_ON) && (CAL_ESCCMACAESGENERATE_STATUS == STD_ON)) \
  || ((CAL_MAC_VERIFY_STATUS == STD_ON) && (CAL_ESCCMACAESVERIFY_STATUS == STD_ON)))
/* Cpl_EscCmacAesContextBuffer size : 376 */
typedef struct STag_Cpl_EscCmacAesContextBuffer
{
  /* Define job state */
  VAR(Cal_AlignType, CAL_VAR_NOINIT) ddJobState;

  /* Stores context pointer in Cmac Aes */
  VAR(EscAesOmac1_ContextT, AUTOMATIC) ddCmacAesContext;
} Cpl_EscCmacAesContextBuffer;
#endif

#if (((CAL_SYM_ENCRYPT_STATUS == STD_ON) && (CAL_ESCAESECBENCRYPT_STATUS == STD_ON)) \
  || ((CAL_SYM_DECRYPT_STATUS == STD_ON) && (CAL_ESCAESECBDECRYPT_STATUS == STD_ON)))
/* Cpl_EscAesEcbContextBuffer size : 356 */
typedef struct STag_Cpl_EscAesEcbContextBuffer
{
  /* Define job state */
  VAR(Cal_AlignType, CAL_VAR_NOINIT) ddJobState;

  /* CycurLib AES ECB primitive library context */
  VAR(EscAesEcb_ContextT, CAL_VAR_NOINIT) ddEscAesEcbContext;
} Cpl_EscAesEcbContextBuffer;
#endif

#if (((CAL_SYM_ENCRYPT_STATUS == STD_ON) && (CAL_ESCAESCBCENCRYPT_STATUS == STD_ON)) \
  || ((CAL_SYM_DECRYPT_STATUS == STD_ON) && (CAL_ESCAESCBCDECRYPT_STATUS == STD_ON)))
/* Cpl_EscAesCbcContextBuffer size : 372 */
typedef struct STag_Cpl_EscAesCbcContextBuffer
{
  /* Define job state */
  VAR(Cal_AlignType, CAL_VAR_NOINIT) ddJobState;

  /* CycurLib AES CBC primitive library context */
  VAR(EscAesCbc_ContextT, CAL_VAR_NOINIT) ddEscAesCbcContext;
} Cpl_EscAesCbcContextBuffer;
#endif

#if (((CAL_SIGNATURE_VERIFY_STATUS == STD_ON) && (CAL_ESCPKCS1V15SEEDVERIFY_STATUS == STD_ON)) \
  || ((CAL_SIGNATURE_VERIFY_STATUS == STD_ON) && (CAL_ESCPKCS1V15SHA1VERIFY_STATUS == STD_ON)) \
  || ((CAL_ASYM_ENCRYPT_STATUS == STD_ON) && (CAL_ESCRSAENCRYPT_STATUS == STD_ON)))
/* EscRsa_PubKeyType size : 260 */
typedef struct STag_EscRsa_PubKeyType
{
  uint8 modulus[ESC_RSA_KEY_BYTES_LEN];
  uint32 exponent;
} EscRsa_PubKeyType;
#endif

#if (((CAL_SIGNATURE_GENERATE_STATUS == STD_ON) && (CAL_ESCPKCS1V15SHA1GENERATE_STATUS == STD_ON)) \
 || ((CAL_ASYM_DECRYPT_STATUS == STD_ON) && (CAL_ESCRSADECRYPT_STATUS == STD_ON)))
/* EscRsa_PrivKeyType size : 512 */
typedef struct STag_EscRsa_PriKeyType
{
  uint8 modulus[ESC_RSA_KEY_BYTES_LEN];
  uint8 exponent[ESC_RSA_KEY_BYTES_LEN];
} EscRsa_PrivKeyType;
#endif

#if ((CAL_ASYM_ENCRYPT_STATUS == STD_ON) && (CAL_ESCRSAENCRYPT_STATUS == STD_ON))
/* Cpl_EscRsaPublicKeyContextBuffer size : 8 */
typedef struct STag_Cpl_EscRsaPublicKeyContextBuffer
{
  /* Define job state */
  VAR(Cal_AlignType, CAL_VAR_NOINIT) ddJobState;

  /* Stores public key pointer in RSA */
  P2CONST(Cal_AsymPublicKeyType, AUTOMATIC, CAL_VAR_NOINIT) pPublicKeyPtr;
} Cpl_EscRsaPublicKeyContextBuffer;
#endif

#if ((CAL_ASYM_DECRYPT_STATUS == STD_ON) && (CAL_ESCRSADECRYPT_STATUS == STD_ON))
/* Cpl_EscRsaPrivateKeyContextBuffer size : 8 */
typedef struct STag_Cpl_EscRsaPrivateKeyContextBuffer
{
  /* Define job state */
  VAR(Cal_AlignType, CAL_VAR_NOINIT) ddJobState;

  /* Stores private key pointer in RSA */
  P2CONST(Cal_AsymPrivateKeyType, AUTOMATIC, CAL_VAR_NOINIT) pPrivateKeyPtr;
} Cpl_EscRsaPrivateKeyContextBuffer;
#endif

#if ((CAL_SIGNATURE_GENERATE_STATUS == STD_ON) && (CAL_ESCPKCS1V15SHA1GENERATE_STATUS == STD_ON))
/* Cpl_EscPkcs15V15Sha1GenerateContextBuffer size : 100 */
typedef struct STag_Cpl_EscPkcs15V15Sha1GenerateContextBuffer
{
  /* Define job state */
  VAR(Cal_AlignType, CAL_VAR_NOINIT) ddJobState;

  /* Stores private key pointer in RSA */
  P2CONST(Cal_AsymPrivateKeyType, AUTOMATIC, CAL_VAR_NOINIT) pPrivateKeyPtr;
  /* Stores context pointer in SHA1 */
  VAR(EscSha1_ContextT, AUTOMATIC) ddSha1Context;
} Cpl_EscPkcs15V15Sha1GenerateContextBuffer;
#endif

#if ((CAL_SIGNATURE_VERIFY_STATUS == STD_ON) && (CAL_ESCPKCS1V15SHA1VERIFY_STATUS == STD_ON))
/* Cpl_EscPkcs15V15Sha1VerifyContextBuffer size : 100 */
typedef struct STag_Cpl_EscPkcs15V15Sha1VerifyContextBuffer
{
  /* Define job state */
  VAR(Cal_AlignType, CAL_VAR_NOINIT) ddJobState;

  /* Stores public key pointer in RSA */
  P2CONST(Cal_AsymPublicKeyType, AUTOMATIC, CAL_VAR_NOINIT) pPublicKeyPtr;

  /* Stores context pointer in SHA1 */
  VAR(EscSha1_ContextT, AUTOMATIC) ddSha1Context;
} Cpl_EscPkcs15V15Sha1VerifyContextBuffer;
#endif

#if ((CAL_SIGNATURE_VERIFY_STATUS == STD_ON) && (CAL_ESCPKCS1V15SEEDVERIFY_STATUS == STD_ON))
/* Esc_SeedType size : 20 */
typedef struct STag_EscPkcs15V15_SeedType
{
  uint8 seed[ESC_SHA1_DIGEST_LEN];
} EscPkcs15V15_SeedType;

/* Cpl_EscPkcs15V15Sha1VerifyContextBuffer size : 72 */
typedef struct STag_Cpl_EscPkcs15V15SeedVerifyContextBuffer
{
  /* Define job state */
  VAR(Cal_AlignType, CAL_VAR_NOINIT) ddJobState;

  /* Stores public key pointer in RSA */
  P2CONST(Cal_AsymPublicKeyType, AUTOMATIC, CAL_VAR_NOINIT) pPublicKeyPtr;

  /* Stores context pointer in Seed */
  VAR(EscPkcs15V15_SeedType, AUTOMATIC) ddSeedContext;
} Cpl_EscPkcs15V15SeedVerifyContextBuffer;
#endif

#endif /* CPL_ESCGLOBALTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
