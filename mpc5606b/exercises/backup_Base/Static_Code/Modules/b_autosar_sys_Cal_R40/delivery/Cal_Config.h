/*******************************************************************************
**                                                                            **
**  (C) 2016 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cal_Config.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAL                                                   **
**                                                                            **
**  PURPOSE   : Cal module const variable declarations for making a library   **
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
** 1.0.4     11-Jan-2017   Sinil        Redmine #7197                         **
** 1.0.3     09-Aug-2016   Sinil        Redmine #5695                         **
** 1.0.2     08-Jul-2016   Sinil        Redmine #5478                         **
** 1.0.1     16-May-2016   Sinil        Redmine #4903                         **
** 1.0.0     12-May-2016   Sinil        Initial version                       **
*******************************************************************************/

#ifndef CAL_CONFIG_H
#define CAL_CONFIG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cal_Cfg.h"

/*******************************************************************************
**                       Global Data                                          **
*******************************************************************************/
#define CAL_START_SEC_CONST_32
#include "MemMap.h"

#if (CAL_HASH_STATUS == STD_ON)
/* CAL_HASH_CONTEXT_BUFFER_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddHashContextBufferSize;

/* CAL_HASH_CFGID_LIMIT */
extern CONST(uint32, CAL_CONST) Cal_GddHashCfgidLimit;
#endif /* (CAL_HASH_STATUS == STD_ON) */

#if (CAL_MAC_GENERATE_STATUS == STD_ON)
/* CAL_MAC_GENERATE_CONTEXT_BUFFER_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddMacGenerateContextBufferSize;

/* CAL_MAC_GENERATE_MAX_KEY_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddMacGenerateMaxKeySize;

/* CAL_MAC_GENERATE_CFGID_LIMIT */
extern CONST(uint32, CAL_CONST) Cal_GddMacGenerateCfgidLimit;
#endif /* (CAL_MAC_GENERATE_STATUS == STD_ON) */

#if (CAL_MAC_VERIFY_STATUS == STD_ON)
/* CAL_MAC_VERIFY_CONTEXT_BUFFER_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddMacVerifyContextBufferSize;

/* CAL_MAC_VERIFY_MAX_KEY_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddMacVerifyMaxKeySize;

/* CAL_MAC_VERIFY_CFGID_LIMIT */
extern CONST(uint32, CAL_CONST) Cal_GddMacVerifyCfgidLimit;
#endif /* (CAL_MAC_VERIFY_STATUS == STD_ON) */

#if (CAL_RANDOM_SEED_STATUS == STD_ON)
/* CAL_RANDOM_CONTEXT_BUFFER_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddRandomContextBufferSize;

/* CAL_RANDOM_SEED_CFGID_LIMIT */
extern CONST(uint32, CAL_CONST) Cal_GddRandomSeedCfgidLimit;
#endif /* (CAL_RANDOM_SEED_STATUS == STD_ON) */

#if (CAL_RANDOM_GENERATE_STATUS == STD_ON)
/* CAL_RANDOM_GENERATE_CFGID_LIMIT */
extern CONST(uint32, CAL_CONST) Cal_GddRandomGenerateCfgidLimit;

#if (defined(CAL_AUTRANDOMSEED_STATUS) && (CAL_AUTRANDOMSEED_STATUS == STD_ON)) \
  || (defined(CAL_AUTRANDOMGENERATE_STATUS) && (CAL_AUTRANDOMGENERATE_STATUS == STD_ON))
/* CAL_AUTRANDOM_SEED_ADDR */
extern CONST(uint32, CAL_CONST) Cal_GulAutRandomSeedAddr;
#endif
#endif /* (CAL_RANDOM_GENERATE_STATUS == STD_ON) */

#if (CAL_SYM_BLOCK_ENCRYPT_STATUS == STD_ON)
/* CAL_SYM_BLOCK_ENCRYPT_CONTEXT_BUFFER_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddSymBlockEncryptContextBufferSize;

/* CAL_SYM_BLOCK_ENCRYPT_MAX_KEY_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddSymBlockEncryptMaxKeySize;

/* CAL_SYM_BLOCK_ENCRYPT_CFGID_LIMIT */
extern CONST(uint32, CAL_CONST) Cal_GddSymBlockEncryptCfgidLimit;
#endif /* (CAL_SYM_BLOCK_ENCRYPT_STATUS == STD_ON) */

#if (CAL_SYM_BLOCK_DECRYPT_STATUS == STD_ON)
/* CAL_SYM_BLOCK_DECRYPT_CONTEXT_BUFFER_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddSymBlockDecryptContextBufferSize;

/* CAL_SYM_BLOCK_DECRYPT_MAX_KEY_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddSymBlockDecryptMaxKeySize;

/* CAL_SYM_BLOCK_DECRYPT_CFGID_LIMIT */
extern CONST(uint32, CAL_CONST) Cal_GddSymBlockDecryptCfgidLimit;
#endif /* (CAL_SYM_BLOCK_DECRYPT_STATUS == STD_ON) */

#if (CAL_SYM_ENCRYPT_STATUS == STD_ON)
/* CAL_SYM_ENCRYPT_CONTEXT_BUFFER_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddSymEncryptContextBufferSize;

/* CAL_SYM_ENCRYPT_MAX_KEY_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddSymEncryptMaxKeySize;

/* CAL_SYM_ENCRYPT_CFGID_LIMIT */
extern CONST(uint32, CAL_CONST) Cal_GddSymEncryptCfgidLimit;
#endif /* (CAL_SYM_ENCRYPT_STATUS == STD_ON) */

#if (CAL_SYM_DECRYPT_STATUS == STD_ON)
/* CAL_SYM_DECRYPT_CONTEXT_BUFFER_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddSymDecryptContextBufferSize;

/* CAL_SYM_DECRYPT_MAX_KEY_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddSymDecryptMaxKeySize;

/* CAL_SYM_DECRYPT_CFGID_LIMIT */
extern CONST(uint32, CAL_CONST) Cal_GddSymDecryptCfgidLimit;
#endif /* (CAL_SYM_DECRYPT_STATUS == STD_ON) */

#if (CAL_ASYM_ENCRYPT_STATUS == STD_ON)
/* CAL_ASYM_ENCRYPT_CONTEXT_BUFFER_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddAsymEncryptContextBufferSize;

/* CAL_ASYM_ENCRYPT_MAX_KEY_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddAsymEncryptMaxKeySize;

/* CAL_ASYM_ENCRYPT_CFGID_LIMIT */
extern CONST(uint32, CAL_CONST) Cal_GddAsymEncryptCfgidLimit;
#endif /* (CAL_ASYM_ENCRYPT_STATUS == STD_ON) */

#if (CAL_ASYM_DECRYPT_STATUS == STD_ON)
/* CAL_ASYM_DECRYPT_CONTEXT_BUFFER_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddAsymDecryptContextBufferSize;

/* CAL_ASYM_DECRYPT_MAX_KEY_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddAsymDecryptMaxKeySize;

/* CAL_ASYM_DECRYPT_CFGID_LIMIT */
extern CONST(uint32, CAL_CONST) Cal_GddAsymDecryptCfgidLimit;
#endif /* (CAL_ASYM_DECRYPT_STATUS == STD_ON) */

#if (CAL_SIGNATURE_GENERATE_STATUS == STD_ON)
/* CAL_SIGNATURE_GENERATE_CONTEXT_BUFFER_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddSignatureGenerateContextBufferSize;

/* CAL_SIGNATURE_GENERATE_MAX_KEY_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddSignatureGenerateMaxKeySize;

/* CAL_SIGNATURE_GENERATE_CFGID_LIMIT */
extern CONST(uint32, CAL_CONST) Cal_GddSignatureGenerateCfgidLimit;
#endif /* (CAL_SIGNATURE_GENERATE_STATUS == STD_ON) */

#if (CAL_SIGNATURE_VERIFY_STATUS == STD_ON)
/* CAL_SIGNATURE_VERIFY_CONTEXT_BUFFER_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddSignatureVerifyContextBufferSize;

/* CAL_SIGNATURE_VERIFY_MAX_KEY_SIZE */
extern CONST(uint32, CAL_CONST) Cal_GddSignatureVerifyMaxKeySize;

/* CAL_SIGNATURE_VERIFY_CFGID_LIMIT */
extern CONST(uint32, CAL_CONST) Cal_GddSignatureVerifyCfgidLimit;
#endif /* (CAL_SIGNATURE_VERIFY_STATUS == STD_ON) */

#define CAL_STOP_SEC_CONST_32
#include "MemMap.h"

#endif /* CAL_CONFIG_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
