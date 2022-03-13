/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cal.h                                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crypto Abstraction Library Module                     **
**                                                                            **
**  PURPOSE   : Provides function prototypes to access the CAL services       **
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
** 1.0.3     08-Jul-2016   Sinil        Redmine #5478                         **
** 1.0.2     16-May-2016   Sinil        Redmine #4903                         **
** 1.0.0     01-Jan-2013   Autron       Initial version                       **
*******************************************************************************/

#ifndef CAL_H
#define CAL_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cal_Types.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CAL_START_SEC_CODE
#include "MemMap.h"

#if (CAL_VERSION_INFO_API == STD_ON)
/* Function for version information */
extern FUNC(void, CAL_CODE) Cal_GetVersionInfo(
  Std_VersionInfoType *versioninfo);
#endif

/* Hash Interface */
#if (CAL_HASH_STATUS == STD_ON)
/* Function for starting the Hash service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_HashStart(Cal_ConfigIdType cfgId,
  Cal_HashCtxBufType contextBuffer);

/* Function for feeding Hash service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_HashUpdate(Cal_ConfigIdType cfgId,
  Cal_HashCtxBufType contextBuffer, const uint8* dataPtr, uint32 dataLength);

/* Function for finishing the Hash service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_HashFinish(Cal_ConfigIdType cfgId,
  Cal_HashCtxBufType contextBuffer, uint8* resultPtr, uint32* resultLengthPtr,
  boolean TruncationIsAllowed);
#endif /* (CAL_HASH_STATUS == STD_ON) */

/* MAC interface */
#if (CAL_MAC_GENERATE_STATUS == STD_ON)
/* Function for starting the MAC Generate service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_MacGenerateStart(
  Cal_ConfigIdType cfgId, Cal_MacGenerateCtxBufType contextBuffer,
  const Cal_SymKeyType* keyPtr);

/* Function for feeding MAC Generate service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_MacGenerateUpdate(
  Cal_ConfigIdType cfgId, Cal_MacGenerateCtxBufType contextBuffer,
  const uint8* dataPtr, uint32 dataLength);

/* Function for finishing the MAC Generate service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_MacGenerateFinish(
  Cal_ConfigIdType cfgId, Cal_MacGenerateCtxBufType contextBuffer,
  uint8* resultPtr, uint32* resultLengthPtr, boolean TruncationIsAllowed);
#endif /* (CAL_MAC_GENERATE_STATUS == STD_ON) */

#if (CAL_MAC_VERIFY_STATUS == STD_ON)
/* Function for starting the MAC Verify service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_MacVerifyStart(Cal_ConfigIdType cfgId,
  Cal_MacVerifyCtxBufType contextBuffer, const Cal_SymKeyType* keyPtr);

/* Function for feeding MAC Verify service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_MacVerifyUpdate(
  Cal_ConfigIdType cfgId, Cal_MacVerifyCtxBufType contextBuffer,
  const uint8* dataPtr, uint32 dataLength);

/* Function for finishing the MAC Verify service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_MacVerifyFinish(
  Cal_ConfigIdType cfgId, Cal_MacVerifyCtxBufType contextBuffer,
  const uint8* MacPtr, uint32 MacLength, Cal_VerifyResultType* resultPtr);
#endif /* (CAL_MAC_VERIFY_STATUS == STD_ON) */

/* Random interface */
#if (CAL_RANDOM_SEED_STATUS == STD_ON)
/* Function for starting the Random Seed service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_RandomSeedStart(
  Cal_ConfigIdType cfgId, Cal_RandomCtxBufType contextBuffer);

/* Function for feeding Random Seed service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_RandomSeedUpdate(
  Cal_ConfigIdType cfgId, Cal_RandomCtxBufType contextBuffer,
  const uint8* seedPtr, uint32 seedLength);

/* Function for finishing the Random Seed service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_RandomSeedFinish(
  Cal_ConfigIdType cfgId, Cal_RandomCtxBufType contextBuffer);
#endif /* (CAL_RANDOM_SEED_STATUS == STD_ON) */

#if (CAL_RANDOM_GENERATE_STATUS == STD_ON)
/* Function for Random Generate service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_RandomGenerate(Cal_ConfigIdType cfgId,
  Cal_RandomCtxBufType contextBuffer, uint8* resultPtr, uint32 resultLength);
#endif /* (CAL_RANDOM_GENERATE_STATUS == STD_ON) */

/* Symmetrical Block */
#if (CAL_SYM_BLOCK_ENCRYPT_STATUS == STD_ON)
/* Function for starting the Symmetrical Block Encryption service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymBlockEncryptStart(
  Cal_ConfigIdType cfgId, Cal_SymBlockEncryptCtxBufType contextBuffer,
  const Cal_SymKeyType* keyPtr);

/* Function for feeding Symmetrical Block Encryption service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymBlockEncryptUpdate(
  Cal_ConfigIdType cfgId, Cal_SymBlockEncryptCtxBufType contextBuffer,
  const uint8* plainTextPtr, uint32 plainTextLength, uint8* cipherTextPtr,
  uint32* cipherTextLengthPtr);

/* Function for finishing the Symmetrical Block Encryption service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymBlockEncryptFinish(
  Cal_ConfigIdType cfgId, Cal_SymBlockEncryptCtxBufType contextBuffer);
#endif /* (CAL_SYM_BLOCK_ENCRYPT_STATUS == STD_ON) */

#if (CAL_SYM_BLOCK_DECRYPT_STATUS == STD_ON)
/* Function for starting the Symmetrical Block Decryption service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymBlockDecryptStart(
  Cal_ConfigIdType cfgId, Cal_SymBlockDecryptCtxBufType contextBuffer,
  const Cal_SymKeyType* keyPtr);

/* Function for feeding Symmetrical Block Decryption service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymBlockDecryptUpdate(
  Cal_ConfigIdType cfgId, Cal_SymBlockDecryptCtxBufType contextBuffer,
  const uint8* cipherTextPtr, uint32 cipherTextLength, uint8* plainTextPtr,
  uint32* plainTextLengthPtr);

/* Function for finishing the Symmetrical Block Decryption service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymBlockDecryptFinish(
  Cal_ConfigIdType cfgId, Cal_SymBlockDecryptCtxBufType contextBuffer);
#endif /* (CAL_SYM_BLOCK_DECRYPT_STATUS == STD_ON) */

/* Symmetrical interface */
#if (CAL_SYM_ENCRYPT_STATUS == STD_ON)
/* Function for starting the Symmetrical Encryption service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymEncryptStart(
  Cal_ConfigIdType cfgId, Cal_SymEncryptCtxBufType contextBuffer,
  const Cal_SymKeyType* keyPtr, const uint8* InitVectorPtr,
  uint32 InitVectorLength);

/* Function for feeding Symmetrical Encryption service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymEncryptUpdate(
  Cal_ConfigIdType cfgId, Cal_SymEncryptCtxBufType contextBuffer,
  const uint8* plainTextPtr, uint32 plainTextLength, uint8* cipherTextPtr,
  uint32* cipherTextLengthPtr);

/* Function for finishing the Symmetrical Encryption service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymEncryptFinish(
  Cal_ConfigIdType cfgId, Cal_SymEncryptCtxBufType contextBuffer,
  uint8* cipherTextPtr, uint32* cipherTextLengthPtr);
#endif /* (CAL_SYM_ENCRYPT_STATUS == STD_ON) */

#if (CAL_SYM_DECRYPT_STATUS == STD_ON)
/* Function for starting the Symmetrical Decryption service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymDecryptStart(
  Cal_ConfigIdType cfgId, Cal_SymDecryptCtxBufType contextBuffer,
  const Cal_SymKeyType* keyPtr, const uint8* InitVectorPtr,
  uint32 InitVectorLength);

/* Function for feeding Symmetrical Decryption service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymDecryptUpdate(
  Cal_ConfigIdType cfgId, Cal_SymDecryptCtxBufType contextBuffer,
  const uint8* cipherTextPtr, uint32 cipherTextLength, uint8* plainTextPtr,
  uint32* plainTextLengthPtr);

/* Function for finishing the Symmetrical Decryption service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymDecryptFinish(
  Cal_ConfigIdType cfgId, Cal_SymDecryptCtxBufType contextBuffer,
  uint8* plainTextPtr, uint32* plainTextLengthPtr);
#endif /* (CAL_SYM_DECRYPT_STATUS == STD_ON) */

/* Asymmetrical interface */
#if (CAL_ASYM_ENCRYPT_STATUS == STD_ON)
/* Function for starting the Assymmetrical Encryption service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_AsymEncryptStart(
  Cal_ConfigIdType cfgId, Cal_AsymEncryptCtxBufType contextBuffer,
  const Cal_AsymPublicKeyType* keyPtr);

/* Function for feeding Assymmetrical Encryption service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_AsymEncryptUpdate(
  Cal_ConfigIdType cfgId, Cal_AsymEncryptCtxBufType contextBuffer,
  const uint8* plainTextPtr, uint32 plainTextLength, uint8* cipherTextPtr,
  uint32* cipherTextLengthPtr);

/* Function for finishing the Assymmetrical Encryption service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_AsymEncryptFinish(
  Cal_ConfigIdType cfgId, Cal_AsymEncryptCtxBufType contextBuffer,
  uint8* cipherTextPtr, uint32* cipherTextLengthPtr);
#endif /* (CAL_ASYM_ENCRYPT_STATUS == STD_ON) */

#if (CAL_ASYM_DECRYPT_STATUS == STD_ON)
/* Function for starting the Assymmetrical Decryption service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_AsymDecryptStart(
  Cal_ConfigIdType cfgId, Cal_AsymDecryptCtxBufType contextBuffer,
  const Cal_AsymPrivateKeyType* keyPtr);

/* Function for feeding Assymmetrical Decryption service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_AsymDecryptUpdate(
  Cal_ConfigIdType cfgId, Cal_AsymDecryptCtxBufType contextBuffer,
  const uint8* cipherTextPtr, uint32 cipherTextLength, uint8* plainTextPtr,
  uint32* plainTextLengthPtr);

/* Function for finishing the Assymmetrical Decryption service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_AsymDecryptFinish(
  Cal_ConfigIdType cfgId, Cal_AsymDecryptCtxBufType contextBuffer,
  uint8* plainTextPtr, uint32* plainTextLengthPtr);
#endif /* (CAL_ASYM_DECRYPT_STATUS == STD_ON) */

/* Signature interface */
#if (CAL_SIGNATURE_GENERATE_STATUS == STD_ON)
/* Function for starting the Signature Generate service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SignatureGenerateStart(
  Cal_ConfigIdType cfgId, Cal_SignatureGenerateCtxBufType contextBuffer,
  const Cal_AsymPrivateKeyType* keyPtr);

/* Function for feeding Signature Generate service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SignatureGenerateUpdate(
  Cal_ConfigIdType cfgId, Cal_SignatureGenerateCtxBufType contextBuffer,
  const uint8* dataPtr, uint32 dataLength);

/* Function for finishing the Signature Generate service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SignatureGenerateFinish(
  Cal_ConfigIdType cfgId, Cal_SignatureGenerateCtxBufType contextBuffer,
  uint8* resultPtr, uint32* resultLengthPtr);
#endif /* (CAL_SIGNATURE_GENERATE_STATUS == STD_ON) */

#if (CAL_SIGNATURE_VERIFY_STATUS == STD_ON)
/* Function for starting the Signature Verify service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SignatureVerifyStart(
  Cal_ConfigIdType cfgId, Cal_SignatureVerifyCtxBufType contextBuffer,
  const Cal_AsymPublicKeyType* keyPtr);

/* Function for feeding Signature Verify service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SignatureVerifyUpdate(
  Cal_ConfigIdType cfgId, Cal_SignatureVerifyCtxBufType contextBuffer,
  const uint8* dataPtr, uint32 dataLength);

/* Function for finishing the Signature Verify service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SignatureVerifyFinish(
  Cal_ConfigIdType cfgId, Cal_SignatureVerifyCtxBufType contextBuffer,
  const uint8* signaturePtr, uint32 signatureLength,
  Cal_VerifyResultType* resultPtr);
#endif /* (CAL_SIGNATURE_VERIFY_STATUS == STD_ON) */

/* Checksum interface */
#if (CAL_CHECKSUM_STATUS == STD_ON)
/* Function for starting the Checksum service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_ChecksumStart(Cal_ConfigIdType cfgId,
  Cal_ChecksumCtxBufType contextBuffer);

/* Function for feeding Checksum service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_ChecksumUpdate(Cal_ConfigIdType cfgId,
  Cal_ChecksumCtxBufType contextBuffer, const uint8* dataPtr,
  uint32 dataLength);

/* Function for finishing the Checksum service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_ChecksumFinish(Cal_ConfigIdType cfgId,
  Cal_ChecksumCtxBufType contextBuffer, uint8* resultPtr,
  uint32* resultLengthPtr, boolean TruncationIsAllowed);
#endif /* (CAL_CHECKSUM_STATUS == STD_ON) */

/* Key Derivation */
#if (CAL_KEY_DERIVE_STATUS == STD_ON)
/* Function for starting the Key Derive service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_KeyDeriveStart(
  Cal_ConfigIdType cfgId, Cal_KeyDeriveCtxBufType contextBuffer,
  uint32 keyLength, uint32 iterations);

/* Function for feeding Key Derive service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_KeyDeriveUpdate(
  Cal_ConfigIdType cfgId, Cal_KeyDeriveCtxBufType contextBuffer,
  const uint8* passwordPtr, uint32 passwordLength, const uint8 * saltPtr,
  uint32 saltLength);

/* Function for finishing the Key Derive service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_KeyDeriveFinish(
  Cal_ConfigIdType cfgId, Cal_KeyDeriveCtxBufType contextBuffer,
  Cal_SymKeyType* keyPtr);
#endif /* (CAL_KEY_DERIVE_STATUS == STD_ON) */

/* Key Exchange CalcPubVal*/
#if (CAL_KEY_EXCHANGE_CALC_PUB_VAL_STATUS == STD_ON)
/* Function for starting the public value calculation service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_KeyExchangeCalcPubVal(
  Cal_ConfigIdType cfgId, const Cal_KeyExchangeBaseType* basePtr,
  const Cal_KeyExchangePrivateType* privateValuePtr, uint8* publicValuePtr,
  uint32* publicValueLengthPtr);
#endif /* (CAL_KEY_EXCHANGE_CALC_PUB_VAL_STATUS == STD_ON) */

/* Key Exchange CalcSecret */
#if (CAL_KEY_EXCHANGE_CALC_SECRET_STATUS == STD_ON)
/* Function for starting the key exchange service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_KeyExchangeCalcSecretStart(
  Cal_ConfigIdType cfgId, Cal_KeyExchangeCalcSecretCtxBufType contextBuffer,
  const Cal_KeyExchangeBaseType* basePtr,
  const Cal_KeyExchangePrivateType* privateValuePtr);

/* Function for feeding key exchange service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_KeyExchangeCalcSecretUpdate(
  Cal_ConfigIdType cfgId, Cal_KeyExchangeCalcSecretCtxBufType contextBuffer,
  const uint8* partnerPublicValuePtr, uint32 partnerPublicValueLength);

/* Function for finishing the key exchange service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_KeyExchangeCalcSecretFinish(
  Cal_ConfigIdType cfgId, Cal_KeyExchangeCalcSecretCtxBufType contextBuffer,
  uint8* sharedSecretPtr, uint32* sharedSecretLengthPtr,
  boolean TruncationIsAllowed);
#endif /* (CAL_KEY_EXCHANGE_CALC_SECRET_STATUS == STD_ON) */

/* Symmetrical Key Extraction */
#if (CAL_SYM_KEY_EXTRACT_STATUS == STD_ON)
/* Function for starting the symmetrical key extraction service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymKeyExtractStart(
  Cal_ConfigIdType cfgId, Cal_SymKeyExtractCtxBufType contextBuffer);

/* Function for feeding symmetrical key extraction service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymKeyExtractUpdate(
  Cal_ConfigIdType cfgId, Cal_SymKeyExtractCtxBufType contextBuffer,
  const uint8* dataPtr, uint32 dataLength);

/* Function for finishing the symmetrical key extraction service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymKeyExtractFinish(
  Cal_ConfigIdType cfgId, Cal_SymKeyExtractCtxBufType contextBuffer,
  Cal_SymKeyType* keyPtr);
#endif /* (CAL_SYM_KEY_EXTRACT_STATUS == STD_ON) */

/* Symmetrical Key Wrap Sym Key */
#if (CAL_SYM_KEY_WRAP_SYM_STATUS == STD_ON)
/* Function for starting the symmetrical key wrapping service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymKeyWrapSymStart(
  Cal_ConfigIdType cfgId, Cal_SymKeyWrapSymCtxBufType contextBuffer,
  const Cal_SymKeyType* keyPtr, const Cal_SymKeyType* wrappingKeyPtr);

/* Function for feeding symmetrical key wrapping service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymKeyWrapSymUpdate(
  Cal_ConfigIdType cfgId, Cal_SymKeyWrapSymCtxBufType contextBuffer,
  uint8* dataPtr, uint32* dataLengthPtr);

/* Function for finishing the symmetrical key wrapping service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymKeyWrapSymFinish(
  Cal_ConfigIdType cfgId, Cal_SymKeyWrapSymCtxBufType contextBuffer);
#endif /* (CAL_SYM_KEY_WRAP_SYM_STATUS == STD_ON) */

/* Symmetrical Key Wrap Asym Key */
#if (CAL_SYM_KEY_WRAP_ASYM_STATUS == STD_ON)
/* Function for starting the symmetrical key wrapping service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymKeyWrapAsymStart(
  Cal_ConfigIdType cfgId, Cal_SymKeyWrapAsymCtxBufType contextBuffer,
  const Cal_SymKeyType* keyPtr, const Cal_AsymPublicKeyType* wrappingKeyPtr);

/* Function for feeding symmetrical key wrapping service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymKeyWrapAsymUpdate(
  Cal_ConfigIdType cfgId, Cal_SymKeyWrapAsymCtxBufType contextBuffer,
  uint8* dataPtr, uint32* dataLengthPtr);

/* Function for finishing the symmetrical key wrapping service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_SymKeyWrapAsymFinish(
  Cal_ConfigIdType cfgId, Cal_SymKeyWrapAsymCtxBufType contextBuffer);
#endif /* (CAL_SYM_KEY_WRAP_ASYM_STATUS == STD_ON) */

/* Asymmetrical PubKeyExtraction */
#if (CAL_ASYM_PUBLIC_KEY_EXTRACT_STATUS == STD_ON)
/* Function for starting the asymmetrical public key extraction service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_AsymPublicKeyExtractStart(
  Cal_ConfigIdType cfgId, Cal_AsymPublicKeyExtractCtxBufType contextBuffer);

/* Function for feeding asymmetrical public key extraction service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_AsymPublicKeyExtractUpdate(
  Cal_ConfigIdType cfgId, Cal_AsymPublicKeyExtractCtxBufType contextBuffer,
  const uint8* dataPtr, uint32 dataLength);

/* Function for finishing the asymmetrical public key extraction service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_AsymPublicKeyExtractFinish(
  Cal_ConfigIdType cfgId, Cal_AsymPublicKeyExtractCtxBufType contextBuffer,
  Cal_AsymPublicKeyType* keyPtr);
#endif /* (CAL_ASYM_PUBLIC_KEY_EXTRACT_STATUS == STD_ON) */

/* Asymmetrical PrivKeyExtraction */
#if (CAL_ASYM_PRIVATE_KEY_EXTRACT_STATUS == STD_ON)
/* Function for starting the asymmetrical private key extraction service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_AsymPrivateKeyExtractStart(
  Cal_ConfigIdType cfgId, Cal_AsymPrivateKeyExtractCtxBufType contextBuffer);

/* Function for feeding asymmetrical private key extraction service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_AsymPrivateKeyExtractUpdate(
  Cal_ConfigIdType cfgId, Cal_AsymPrivateKeyExtractCtxBufType contextBuffer,
  const uint8* dataPtr, uint32 dataLength);

/* Function for finishing the asymmetrical private key extraction service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_AsymPrivateKeyExtractFinish(
  Cal_ConfigIdType cfgId, Cal_AsymPrivateKeyExtractCtxBufType contextBuffer,
  Cal_AsymPrivateKeyType* keyPtr);
#endif /* (CAL_ASYM_PRIVATE_KEY_EXTRACT_STATUS == STD_ON) */

/* Asym Wrap using Sym key */
#if (CAL_ASYM_KEY_WRAP_SYM_STATUS == STD_ON)
/* Function for starting the asymmetrical key wrapping service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_AsymPrivateKeyWrapSymStart(
  Cal_ConfigIdType cfgId, Cal_AsymPrivateKeyWrapSymCtxBufType contextBuffer,
  const Cal_AsymPrivateKeyType* keyPtr, const Cal_SymKeyType* wrappingKeyPtr);

/* Function for feeding asymmetrical key wrapping service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_AsymPrivateKeyWrapSymUpdate(
  Cal_ConfigIdType cfgId, Cal_AsymPrivateKeyWrapSymCtxBufType contextBuffer,
  uint8* dataPtr, uint32* dataLengthPtr);

/* Function for finishing the asymmetrical key wrapping service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_AsymPrivateKeyWrapSymFinish(
  Cal_ConfigIdType cfgId, Cal_AsymPrivateKeyWrapSymCtxBufType contextBuffer);
#endif /* (CAL_ASYM_KEY_WRAP_SYM_STATUS == STD_ON) */

/* Asym Wrap using Aym key */
#if (CAL_ASYM_KEY_WRAP_ASYM_STATUS == STD_ON)
/* Function for starting the asymmetrical key wrapping service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_AsymPrivateKeyWrapAsymStart(
  Cal_ConfigIdType cfgId, Cal_AsymPrivateKeyWrapAsymCtxBufType contextBuffer,
  const Cal_AsymPrivateKeyType* keyPtr,
  const Cal_AsymPublicKeyType* wrappingKeyPtr);

/* Function for feeding asymmetrical key wrapping service with user data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_AsymPrivateKeyWrapAsymUpdate(
  Cal_ConfigIdType cfgId, Cal_AsymPrivateKeyWrapAsymCtxBufType contextBuffer,
  uint8* dataPtr, uint32* dataLengthPtr);

/* Function for finishing asymmetrical key wrapping service */
extern FUNC(Cal_ReturnType, CAL_CODE) Cal_AsymPrivateKeyWrapAsymFinish(
  Cal_ConfigIdType cfgId, Cal_AsymPrivateKeyWrapAsymCtxBufType contextBuffer);
#endif /* (CAL_ASYM_KEY_WRAP_ASYM_STATUS == STD_ON) */

#define CAL_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CAL_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
