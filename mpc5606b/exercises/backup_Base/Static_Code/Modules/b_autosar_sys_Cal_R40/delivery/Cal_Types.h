/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cal_Types.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR AUTOSAR Crypto Abstraction Library Module             **
**                                                                            **
**  PURPOSE   : Provides the types, particularly the configuration types, for **
**              the CAL module                                                **
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
** 1.0.7     09-Aug-2016   Sinil        Redmine #5540                         **
** 1.0.6     10-Jun-2016   Sinil        Redmine #4533                         **
** 1.0.5     16-May-2016   Sinil        Redmine #4903                         **
** 1.0.4     12-May-2016   Sinil        Redmine #4880                         **
** 1.0.0     01-Jan-2013   Autron       Initial version                       **
*******************************************************************************/

#ifndef CAL_TYPES_H
#define CAL_TYPES_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"            /* For AUTOSAR Standard types */
#include "Cal_Cfg.h"              /* header for Module type declarations */
#include "Cal_Config.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define CAL_TYPES_AR_RELEASE_MAJOR_VERSION       CAL_AR_RELEASE_MAJOR_VERSION
#define CAL_TYPES_AR_RELEASE_MINOR_VERSION       CAL_AR_RELEASE_MINOR_VERSION
#define CAL_TYPES_AR_RELEASE_REVISION_VERSION\
  CAL_AR_RELEASE_REVISION_VERSION

/* FILE VERSION INFORMATION */
#define CAL_TYPES_SW_MAJOR_VERSION               CAL_SW_MAJOR_VERSION
#define CAL_TYPES_SW_MINOR_VERSION               CAL_SW_MINOR_VERSION
#define CAL_TYPES_SW_PATCH_VERSION               CAL_SW_PATCH_VERSION

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Macro to define length of data being zero */
#define CAL_LENGTH_ZERO                          ((uint32)0x00)

/* Macro for const value */
#define CAL_ZERO                                 (0x00U)
#define CAL_ONE                                  (0x01U)
#define CAL_TWO                                  (0x02U)
#define CAL_THREE                                (0x03U)
#define CAL_EIGHT                                (0x08U)
#define CAL_BYTE_MASK                            (0xFFU)

/* Macro to define the Multiplier 8 with shift */
#define CAL_MULTIPLIER_8                         ((uint32)0x03)

/* Macro to define the Divisor 8 with shift */
#define CAL_DIVISOR_8                            ((uint32)0x03)

/* Boolean for CAL */
#define CAL_TRUE                                 ((boolean)0x01)
#define CAL_FALSE                                ((boolean)0x00)

/* Macro to define the index where the service state information is
 * stored in the context buffer */
#define CAL_INDEX_OF_SERVICE_STATE_IN_CTX_BUFFER ((uint32)0x00)

/* Macro to define the initializing value for context buffer */
#define CAL_CONTEXT_BUFFER_INITIALIZER           ((Cal_AlignType) 0x00)


/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> 
   use function like-macro for removing unused argument compiler warning */
#define CAL_PARAM_UNUSED(x)                      do { \
                                                   if((uint32)(x) != (uint32)CAL_ZERO) {} \
                                                 } while(0)
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> 
   use function like-macro for removing unused argument compiler warning */
#define CAL_PARAM_UNUSED_PTR(x)                  do { \
                                                   if((x) != NULL_PTR) {} \
                                                 } while(0)

/*******************************************************************************
**                      Common Global Data Types                              **
*******************************************************************************/
/* Identifier for a CAL Service*/
typedef uint16 Cal_ConfigIdType;

/* Enumeration of the return type of the CAL module */
typedef enum
{
  CAL_E_OK = 0, /* return code for successful execution of a function */
  CAL_E_NOT_OK = 1, /* return code for function failure  */
  /* Service request failed as buffer size is not adequate */
  CAL_E_SMALL_BUFFER = 3,
  CAL_E_ENTROPY_EXHAUSTION = 4 /* entropy of random number generator is exhausted */
} Cal_ReturnType;

/* Enumeration for the result type of verification operations  */
typedef enum
{
  CAL_E_VER_OK = 0,               /* Verification is successful */
  CAL_E_VER_NOT_OK = 1                /* Verification is unsuccessful */
} Cal_VerifyResultType;

/* Structure for the public asymmetrical key. */
#if((CAL_ASYM_ENCRYPT_STATUS == STD_ON) ||\
  (CAL_SIGNATURE_VERIFY_STATUS == STD_ON) ||\
  (CAL_ASYM_PUBLIC_KEY_EXTRACT_STATUS == STD_ON) ||\
  (CAL_SYM_KEY_WRAP_ASYM_STATUS == STD_ON) ||\
  (CAL_ASYM_KEY_WRAP_ASYM_STATUS == STD_ON))
typedef struct
{
  uint32 length; /* data length*/
  Cal_AlignType data[CAL_ASYM_PUB_KEY_MAX_SIZE]; /* data */
} Cal_AsymPublicKeyType;
#endif

/* Structure for the private asymmetrical key */
#if((CAL_ASYM_DECRYPT_STATUS == STD_ON) ||\
  (CAL_SIGNATURE_GENERATE_STATUS == STD_ON) ||\
  (CAL_ASYM_PRIVATE_KEY_EXTRACT_STATUS == STD_ON) ||\
  (CAL_ASYM_KEY_WRAP_SYM_STATUS == STD_ON) ||\
  (CAL_ASYM_KEY_WRAP_ASYM_STATUS == STD_ON))
typedef struct
{
  uint32 length; /* data length*/
  Cal_AlignType data[CAL_ASYM_PRIV_KEY_MAX_SIZE]; /* data */
} Cal_AsymPrivateKeyType;
#endif

/* Structure for the symmetrical key */
#if((CAL_SYM_BLOCK_ENCRYPT_STATUS == STD_ON) ||\
  (CAL_SYM_BLOCK_DECRYPT_STATUS == STD_ON) ||\
  (CAL_SYM_ENCRYPT_STATUS == STD_ON) ||\
  (CAL_SYM_DECRYPT_STATUS == STD_ON) ||\
  (CAL_KEY_DERIVE_STATUS == STD_ON) ||\
  (CAL_SYM_KEY_EXTRACT_STATUS == STD_ON) ||\
  (CAL_MAC_GENERATE_STATUS == STD_ON) ||\
  (CAL_MAC_VERIFY_STATUS == STD_ON) ||\
  (CAL_SYM_KEY_WRAP_SYM_STATUS == STD_ON) ||\
  (CAL_SYM_KEY_WRAP_ASYM_STATUS == STD_ON) ||\
  (CAL_ASYM_KEY_WRAP_SYM_STATUS == STD_ON))
typedef struct
{
  uint32 length; /* data length*/
  Cal_AlignType data[CAL_SYM_KEY_MAX_SIZE]; /* data */
} Cal_SymKeyType;
#endif

#if((CAL_KEY_EXCHANGE_CALC_PUB_VAL_STATUS == STD_ON) ||\
  (CAL_KEY_EXCHANGE_CALC_SECRET_STATUS == STD_ON))
/* Structure for the Key Exchange Base type*/
typedef struct
{
  uint32 length; /* data length*/
  Cal_AlignType data[CAL_KEY_EX_BASE_MAX_SIZE]; /* data */
} Cal_KeyExchangeBaseType;

/* Structure for the Key Exchange Private type*/
typedef struct
{
  uint32 length; /* data length*/
  Cal_AlignType data[CAL_KEY_EX_PRIV_MAX_SIZE]; /* data */
} Cal_KeyExchangePrivateType;
#endif

/*******************************************************************************
**                      Hash Interface                                        **
*******************************************************************************/
#if (CAL_HASH_STATUS == STD_ON)
/* Hash Interface States */
#define CAL_HASH_IDLE                            ((Cal_AlignType)0x01)
#define CAL_HASH_ACTIVE                          ((Cal_AlignType)0x02)

/* Type definition of the context buffer of a Hash service */
typedef Cal_AlignType Cal_HashCtxBufType[CAL_HASH_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Hash interface */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_HashCtxBufType contextBuffer);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_HashCtxBufType contextBuffer, const uint8 *dataPtr, uint32 dataLength);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_HashCtxBufType contextBuffer, uint8 *resultPtr, uint32 *resultLengthPtr,
    boolean TruncationIsAllowed);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_HashConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_HashConfigType, CAL_CONST)
  Cal_GaaHashConfigType[CAL_HASH_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /*( CAL_HASH_STATUS == STD_ON) */

/*******************************************************************************
**                      MAC Interface                                         **
*******************************************************************************/
#if (CAL_MAC_GENERATE_STATUS == STD_ON)
/* MAC Generate Interface States */
#define CAL_MAC_GENERATE_IDLE                    ((Cal_AlignType)0x03)
#define CAL_MAC_GENERATE_ACTIVE                  ((Cal_AlignType)0x04)

/* Type definition of the context buffer of a Mac Generate service */
typedef Cal_AlignType
  Cal_MacGenerateCtxBufType[CAL_MAC_GENERATE_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Mac Generate interface */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_MacGenerateCtxBufType contextBuffer, const Cal_SymKeyType *keyPtr);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_MacGenerateCtxBufType contextBuffer, const uint8 *dataPtr,
    uint32 dataLength);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_MacGenerateCtxBufType contextBuffer, uint8 *resultPtr,
    uint32 *resultLengthPtr, boolean TruncationIsAllowed);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_MacGenerateConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_MacGenerateConfigType, CAL_CONST)
  Cal_GaaMacGenerateConfigType[CAL_MAC_GENERATE_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_MAC_GENERATE_STATUS == STD_ON) */

#if (CAL_MAC_VERIFY_STATUS == STD_ON)
/* MAC Verify Interface States */
#define CAL_MAC_VERIFY_IDLE                      ((Cal_AlignType)0x05)
#define CAL_MAC_VERIFY_ACTIVE                    ((Cal_AlignType)0x06)

/* Type definition of the context buffer of a Mac Verify service */
typedef Cal_AlignType
  Cal_MacVerifyCtxBufType[CAL_MAC_VERIFY_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Mac Verify interface */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_MacVerifyCtxBufType contextBuffer, const Cal_SymKeyType *keyPtr);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_MacVerifyCtxBufType contextBuffer, const uint8 *dataPtr,
    uint32 dataLength);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_MacVerifyCtxBufType contextBuffer, const uint8 *MacPtr,
    uint32 MacLength, Cal_VerifyResultType *resultPtr);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_MacVerifyConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_MacVerifyConfigType, CAL_CONST)
  Cal_GaaMacVerifyConfigType[CAL_MAC_VERIFY_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /*(CAL_MAC_VERIFY_STATUS == STD_ON)*/

/*******************************************************************************
**                      Random Interface                                      **
*******************************************************************************/
/* Random interface configured */
#if (CAL_RANDOM_SEED_STATUS == STD_ON)
/* Random Seed Interface States */
#define CAL_RANDOM_SEED_IDLE                     ((Cal_AlignType)0x07)
#define CAL_RANDOM_SEED_ACTIVE                   ((Cal_AlignType)0x08)

/* Type definition of the context buffer of a Random Seed service */
typedef Cal_AlignType Cal_RandomCtxBufType[CAL_RANDOM_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Random Seed interface */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_RandomCtxBufType contextBuffer);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_RandomCtxBufType contextBuffer, const uint8 *seedPtr,
    uint32 seedLength);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_RandomCtxBufType contextBuffer);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_RandomSeedConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_RandomSeedConfigType, CAL_CONST)
  Cal_GaaRandomSeedConfigType[CAL_RANDOM_SEED_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_RANDOM_SEED_STATUS == STD_ON) */

#if (CAL_RANDOM_GENERATE_STATUS == STD_ON)
/* Structure contains all the information needed for Random Generate interface
**/
typedef struct
{
  /* pointer to Primitive Function */
  Cal_ReturnType (*PrimitiveFct)(const void *cfgPtr,
    Cal_RandomCtxBufType contextBuffer, uint8 *resultPtr, uint32 resultLength);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_RandomGenerateConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_RandomGenerateConfigType, CAL_CONST)
  Cal_GaaRandomGenerateConfigType[CAL_RANDOM_GENERATE_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_RANDOM_GENERATE_STATUS == STD_ON) */

/*******************************************************************************
**                      Symmetrical Block Interface                           **
*******************************************************************************/
/* Symmetrical block interface configured */
#if (CAL_SYM_BLOCK_ENCRYPT_STATUS == STD_ON)
/* Symmetric Block Encrypt Interface States */
#define CAL_SYM_BLOCK_ENCRYPT_IDLE               ((Cal_AlignType)0x09)
#define CAL_SYM_BLOCK_ENCRYPT_ACTIVE             ((Cal_AlignType)0x0A)

/* Type definition of the context buffer of a Symmetric Block Encrypt service */
typedef Cal_AlignType
  Cal_SymBlockEncryptCtxBufType[CAL_SYM_BLOCK_ENCRYPT_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Symmetrical Block *
 * Encryption interface                                                *
 */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_SymBlockEncryptCtxBufType contextBuffer, const Cal_SymKeyType *keyPtr);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_SymBlockEncryptCtxBufType contextBuffer, const uint8 *plainTextPtr,
    uint32 plainTextLength, uint8 *cipherTextPtr, uint32 *cipherTextLengthPtr);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_SymBlockEncryptCtxBufType contextBuffer);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_SymBlockEncryptConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_SymBlockEncryptConfigType, CAL_CONST)
  Cal_GaaSymBlockEncryptConfigType[CAL_SYM_BLOCK_ENCRYPT_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_SYM_BLOCK_ENCRYPT_STATUS == STD_ON) */

#if (CAL_SYM_BLOCK_DECRYPT_STATUS == STD_ON)
/* Symmetric Block Decrypt Interface States */
#define CAL_SYM_BLOCK_DECRYPT_IDLE               ((Cal_AlignType)0x0B)
#define CAL_SYM_BLOCK_DECRYPT_ACTIVE             ((Cal_AlignType)0x0C)

/* Type definition of the context buffer of a Symmetric Block Decrypt service */
typedef Cal_AlignType
  Cal_SymBlockDecryptCtxBufType[CAL_SYM_BLOCK_DECRYPT_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Symmetrical Block *
 * Decryption interface                                                *
 */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_SymBlockDecryptCtxBufType contextBuffer, const Cal_SymKeyType *keyPtr);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_SymBlockDecryptCtxBufType contextBuffer, const uint8 *cipherTextPtr,
    uint32 cipherTextLength, uint8 *plainTextPtr, uint32 *plainTextLengthPtr);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_SymBlockDecryptCtxBufType contextBuffer);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_SymBlockDecryptConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_SymBlockDecryptConfigType, CAL_CONST)
  Cal_GaaSymBlockDecryptConfigType[CAL_SYM_BLOCK_DECRYPT_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_SYM_BLOCK_DECRYPT_STATUS == STD_ON) */

/*******************************************************************************
**                      Symmetrical Interface                                 **
*******************************************************************************/
/* Symmetrical interface configured */
#if (CAL_SYM_ENCRYPT_STATUS == STD_ON)
/* Symmetric Encrypt Interface States */
#define CAL_SYM_ENCRYPT_IDLE                     ((Cal_AlignType)0x0D)
#define CAL_SYM_ENCRYPT_ACTIVE                   ((Cal_AlignType)0x0E)

/* Type definition of the context buffer of a Symmetric Encrypt service */
typedef Cal_AlignType
  Cal_SymEncryptCtxBufType[CAL_SYM_ENCRYPT_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Symmetrical Encryption */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_SymEncryptCtxBufType contextBuffer, const Cal_SymKeyType *keyPtr,
    const uint8 *InitVectorPtr, uint32 InitVectorLength);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_SymEncryptCtxBufType contextBuffer, const uint8 *plainTextPtr,
    uint32 plainTextLength, uint8 *cipherTextPtr, uint32 *cipherTextLengthPtr);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_SymEncryptCtxBufType contextBuffer, uint8 *cipherTextPtr,
    uint32 *cipherTextLengthPtr);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_SymEncryptConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_SymEncryptConfigType, CAL_CONST)
  Cal_GaaSymEncryptConfigType[CAL_SYM_ENCRYPT_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_SYM_ENCRYPT_STATUS == STD_ON) */

#if (CAL_SYM_DECRYPT_STATUS == STD_ON)
/* Symmetric Decrypt Interface States */
#define CAL_SYM_DECRYPT_IDLE                     ((Cal_AlignType)0x0F)
#define CAL_SYM_DECRYPT_ACTIVE                   ((Cal_AlignType)0x10)

/* Type definition of the context buffer of a Symmetric Decrypt service */
typedef Cal_AlignType
  Cal_SymDecryptCtxBufType[CAL_SYM_DECRYPT_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Symmetrical Decryption */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_SymDecryptCtxBufType contextBuffer, const Cal_SymKeyType *keyPtr,
    const uint8 *InitVectorPtr, uint32 InitVectorLength);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_SymDecryptCtxBufType contextBuffer, const uint8 *cipherTextPtr,
    uint32 cipherTextLength, uint8 *plainTextPtr, uint32 *plainTextLengthPtr);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_SymDecryptCtxBufType contextBuffer, uint8 *plainTextPtr,
    uint32 *plainTextLengthPtr);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_SymDecryptConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_SymDecryptConfigType, CAL_CONST)
  Cal_GaaSymDecryptConfigType[CAL_SYM_DECRYPT_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_SYM_DECRYPT_STATUS == STD_ON) */

/*******************************************************************************
**                      Asymmetrical Interface                                **
*******************************************************************************/
/* Asymmetrical interface configured */
#if (CAL_ASYM_ENCRYPT_STATUS == STD_ON)
/* Asymmetric Encrypt Interface States */
#define CAL_ASYM_ENCRYPT_IDLE                    ((Cal_AlignType)0x11)
#define CAL_ASYM_ENCRYPT_ACTIVE                  ((Cal_AlignType)0x12)

/* Type definition of the context buffer of a Asymmetric Encrypt service */
typedef Cal_AlignType
  Cal_AsymEncryptCtxBufType[CAL_ASYM_ENCRYPT_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Asymmetrical Encryption */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_AsymEncryptCtxBufType contextBuffer,
    const Cal_AsymPublicKeyType *keyPtr);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_AsymEncryptCtxBufType contextBuffer, const uint8 *plainTextPtr,
    uint32 plainTextLength, uint8 *cipherTextPtr, uint32 *cipherTextLengthPtr);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_AsymEncryptCtxBufType contextBuffer, uint8 *cipherTextPtr,
    uint32 *cipherTextLengthPtr);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_AsymEncryptConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_AsymEncryptConfigType, CAL_CONST)
  Cal_GaaAsymEncryptConfigType[CAL_ASYM_ENCRYPT_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_ASYM_ENCRYPT_STATUS == STD_ON) */

#if (CAL_ASYM_DECRYPT_STATUS == STD_ON)
/* Asymmetric Decrypt Interface States */
#define CAL_ASYM_DECRYPT_IDLE                    ((Cal_AlignType)0x13)
#define CAL_ASYM_DECRYPT_ACTIVE                  ((Cal_AlignType)0x14)

/* Type definition of the context buffer of a Asymmetric Decrypt service */
typedef Cal_AlignType
  Cal_AsymDecryptCtxBufType[CAL_ASYM_DECRYPT_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Asymmetrical Decryption */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_AsymDecryptCtxBufType contextBuffer,
    const Cal_AsymPrivateKeyType *keyPtr);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_AsymDecryptCtxBufType contextBuffer, const uint8 *cipherTextPtr,
    uint32 cipherTextLength, uint8 *plainTextPtr, uint32 *plainTextLengthPtr);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_AsymDecryptCtxBufType contextBuffer, uint8 *plainTextPtr,
    uint32 *plainTextLengthPtr);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_AsymDecryptConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_AsymDecryptConfigType, CAL_CONST)
  Cal_GaaAsymDecryptConfigType[CAL_ASYM_DECRYPT_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_ASYM_DECRYPT_STATUS == STD_ON) */

/*******************************************************************************
**                      Signature Interface                                   **
*******************************************************************************/
/* Signature Interface configured */
#if (CAL_SIGNATURE_GENERATE_STATUS == STD_ON)
/* Signature generate Interface States */
#define CAL_SIGNATURE_GENERATE_IDLE              ((Cal_AlignType)0x15)
#define CAL_SIGNATURE_GENERATE_ACTIVE            ((Cal_AlignType)0x16)

/* Type definition of the context buffer of a Signature Generate service */
typedef Cal_AlignType
  Cal_SignatureGenerateCtxBufType[CAL_SIGNATURE_GENERATE_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Signature Generation */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_SignatureGenerateCtxBufType contextBuffer,
    const Cal_AsymPrivateKeyType *keyPtr);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_SignatureGenerateCtxBufType contextBuffer, const uint8 *dataPtr,
    uint32 dataLength);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_SignatureGenerateCtxBufType contextBuffer, uint8 *resultPtr,
    uint32 *resultLengthPtr);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_SignatureGenerateConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_SignatureGenerateConfigType, CAL_CONST)
  Cal_GaaSignatureGenerateConfigType[CAL_SIGNATURE_GENERATE_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_SIGNATURE_GENERATE_STATUS == STD_ON) */

#if (CAL_SIGNATURE_VERIFY_STATUS == STD_ON)
/* Signature Verification Interface States */
#define CAL_SIGNATURE_VERIFY_IDLE                ((Cal_AlignType)0x17)
#define CAL_SIGNATURE_VERIFY_ACTIVE              ((Cal_AlignType)0x18)

/* Type definition of the context buffer of a Signature Verify service */
typedef Cal_AlignType
  Cal_SignatureVerifyCtxBufType[CAL_SIGNATURE_VERIFY_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for SignatureVerification */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_SignatureVerifyCtxBufType contextBuffer,
    const Cal_AsymPublicKeyType *keyPtr);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_SignatureVerifyCtxBufType contextBuffer, const uint8 *dataPtr,
    uint32 dataLength);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_SignatureVerifyCtxBufType contextBuffer, const uint8 *signaturePtr,
    uint32 signatureLength, Cal_VerifyResultType *resultPtr);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_SignatureVerifyConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_SignatureVerifyConfigType, CAL_CONST)
  Cal_GaaSignatureVerifyConfigType[CAL_SIGNATURE_VERIFY_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_SIGNATURE_VERIFY_STATUS == STD_ON) */

/*******************************************************************************
**                      Checksum Interface                                    **
*******************************************************************************/
/* Checksum interface configured */
#if (CAL_CHECKSUM_STATUS == STD_ON)
/* Checksum Interface States */
#define CAL_CHECKSUM_IDLE                        ((Cal_AlignType)0x19)
#define CAL_CHECKSUM_ACTIVE                      ((Cal_AlignType)0x1A)

/* Type definition of the context buffer of a Checksum service */
typedef Cal_AlignType Cal_ChecksumCtxBufType[CAL_CHECKSUM_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Checksum */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_ChecksumCtxBufType contextBuffer);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_ChecksumCtxBufType contextBuffer, const uint8 *dataPtr,
    uint32 dataLength);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_ChecksumCtxBufType contextBuffer, uint8 *resultPtr,
    uint32 *resultLengthPtr, boolean TruncationIsAllowed);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_ChecksumConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_ChecksumConfigType, CAL_CONST)
  Cal_GaaChecksumConfigType[CAL_CHECKSUM_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_CHECKSUM_STATUS == STD_ON) */

/*******************************************************************************
**                      Key Derivation Interface                              **
*******************************************************************************/
/* Key derivation interface configured */
#if (CAL_KEY_DERIVE_STATUS == STD_ON)
/* Key derivation Interface States */
#define CAL_KEY_DERIVE_IDLE                      ((Cal_AlignType)0x1B)
#define CAL_KEY_DERIVE_ACTIVE                    ((Cal_AlignType)0x1C)

/* Type definition of the context buffer of a Key derivation service */
typedef Cal_AlignType
  Cal_KeyDeriveCtxBufType[CAL_KEY_DERIVE_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Key Derivation */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_KeyDeriveCtxBufType contextBuffer, uint32 keyLength, uint32 iterations);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_KeyDeriveCtxBufType contextBuffer, const uint8 *passwordPtr,
    uint32 passwordLength, const uint8 *saltPtr, uint32 saltLength);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_KeyDeriveCtxBufType contextBuffer, Cal_SymKeyType *keyPtr);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_KeyDeriveConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_KeyDeriveConfigType, CAL_CONST)
  Cal_GaaKeyDeriveConfigType[CAL_KEY_DERIVE_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_KEY_DERIVE_STATUS == STD_ON) */

/*******************************************************************************
**                      KeyExchangeCalcPubVal Interface                       **
*******************************************************************************/
/* Key exchange interface configured */
#if (CAL_KEY_EXCHANGE_CALC_PUB_VAL_STATUS == STD_ON)
/* Type definition of the context buffer of Key exchange calc pub val service */
typedef Cal_AlignType
  Cal_KeyExchangePubValCtxBufType[CAL_KEY_EXCHANGE_PUB_VAL_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for public value calculation */
typedef struct
{
  /* pointer to Primitive Function */
  Cal_ReturnType (*PrimitiveFct)(const void *cfgPtr,
    const Cal_KeyExchangeBaseType *basePtr,
    const Cal_KeyExchangePrivateType *privateValuePtr, uint8 *publicValuePtr,
    uint32 *publicValueLengthPtr);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_KeyExchangeCalcPubValConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_KeyExchangeCalcPubValConfigType, CAL_CONST)
  Cal_GaaKeyExchangeCalcPubValConfigType
  [CAL_KEY_EXCHANGE_CALC_PUB_VAL_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_KEY_EXCHANGE_CALC_PUB_VAL_STATUS == STD_ON) */

/*******************************************************************************
**                      KeyExchangeCalcSecret Interface                       **
*******************************************************************************/
/* Key exchange interface configured */
#if (CAL_KEY_EXCHANGE_CALC_SECRET_STATUS == STD_ON)
/* Key Exchange Cal Secret Interface States */
#define CAL_KEY_EXCHANGE_CALC_SECRET_IDLE        ((Cal_AlignType)0x1D)
#define CAL_KEY_EXCHANGE_CALC_SECRET_ACTIVE      ((Cal_AlignType)0x02)

/* Type definition of the context buffer of Key exchange calc Secret service */
typedef Cal_AlignType Cal_KeyExchangeCalcSecretCtxBufType
  [CAL_KEY_EXCHANGE_CALC_SECRET_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Key Exchange */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_KeyExchangeCalcSecretCtxBufType contextBuffer,
    const Cal_KeyExchangeBaseType *basePtr,
    const Cal_KeyExchangePrivateType *privateValuePtr);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_KeyExchangeCalcSecretCtxBufType contextBuffer,
    const uint8 *partnerPublicValuePtr, uint32 partnerPublicValueLength);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_KeyExchangeCalcSecretCtxBufType contextBuffer, uint8 *sharedSecretPtr,
    uint32 *sharedSecretLengthPtr, boolean TruncationIsAllowed);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_KeyExchangeCalcSecretConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_KeyExchangeCalcSecretConfigType, CAL_CONST)
  Cal_GaaKeyExchangeCalcSecretConfigType
  [CAL_KEY_EXCHANGE_CALC_SECRET_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_KEY_EXCHANGE_CALC_SECRET_STATUS == STD_ON) */

/*******************************************************************************
**                      Symmetrical Key Extraction Interface                  **
*******************************************************************************/
/* Symmetrical Key Extract interface configured */
#if (CAL_SYM_KEY_EXTRACT_STATUS == STD_ON)
/* Symmetrical Key Extract Interface States */
#define CAL_SYM_KEY_EXTRACT_IDLE                 ((Cal_AlignType)0x1F)
#define CAL_SYM_KEY_EXTRACT_ACTIVE               ((Cal_AlignType)0x20)

/* Type definition of the context buffer of a Key Extract service */
typedef Cal_AlignType
  Cal_SymKeyExtractCtxBufType[CAL_SYM_KEY_EXTRACT_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Key Extraction interface */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_SymKeyExtractCtxBufType contextBuffer);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_SymKeyExtractCtxBufType contextBuffer, const uint8 *dataPtr,
    uint32 dataLength);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_SymKeyExtractCtxBufType contextBuffer, Cal_SymKeyType *keyPtr);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_SymKeyExtractConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_SymKeyExtractConfigType, CAL_CONST)
  Cal_GaaSymKeyExtractConfigType[CAL_SYM_KEY_EXTRACT_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_SYM_KEY_EXTRACT_STATUS == STD_ON) */

/*******************************************************************************
**                      Symmetrical Key Interface                             **
*******************************************************************************/
/* Symmetrical Key Wrap interface configured */
#if (CAL_SYM_KEY_WRAP_SYM_STATUS == STD_ON)
/* Symmetrical Key Wrap Sym Interface States */
#define CAL_SYM_KEY_WRAP_SYM_IDLE                ((Cal_AlignType)0x21)
#define CAL_SYM_KEY_WRAP_SYM_ACTIVE              ((Cal_AlignType)0x22)

/* Type definition of the context buffer of Symmetrical Key Wrap Sym service */
typedef Cal_AlignType
  Cal_SymKeyWrapSymCtxBufType[CAL_SYM_KEY_WRAP_SYM_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Key Wrapping interface */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_SymKeyWrapSymCtxBufType contextBuffer, const Cal_SymKeyType *keyPtr,
    const Cal_SymKeyType *wrappingKeyPtr);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_SymKeyWrapSymCtxBufType contextBuffer, uint8 *dataPtr,
    uint32 *dataLengthPtr);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_SymKeyWrapSymCtxBufType contextBuffer);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_SymKeyWrapSymConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_SymKeyWrapSymConfigType, CAL_CONST)
  Cal_GaaSymKeyWrapSymConfigType[CAL_SYM_KEY_WRAP_SYM_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_SYM_KEY_WRAP_SYM_STATUS == STD_ON) */

/*******************************************************************************
**                      Asymmetrical Key Interface                            **
*******************************************************************************/
#if (CAL_SYM_KEY_WRAP_ASYM_STATUS == STD_ON)
/* Symmetrical Key Wrap Asym Interface States */
#define CAL_SYM_KEY_WRAP_ASYM_IDLE               ((Cal_AlignType)0x23)
#define CAL_SYM_KEY_WRAP_ASYM_ACTIVE             ((Cal_AlignType)0x24)

/* Type definition of the context buffer of Symmetrical Key Wrap Asym service */
typedef Cal_AlignType
  Cal_SymKeyWrapAsymCtxBufType[CAL_SYM_KEY_WRAP_ASYM_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for  Key Wrapping interface */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_SymKeyWrapAsymCtxBufType contextBuffer, const Cal_SymKeyType *keyPtr,
    const Cal_AsymPublicKeyType *wrappingKeyPtr);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_SymKeyWrapAsymCtxBufType contextBuffer, uint8 *dataPtr,
    uint32 *dataLengthPtr);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_SymKeyWrapAsymCtxBufType contextBuffer);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_SymKeyWrapAsymConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_SymKeyWrapAsymConfigType, CAL_CONST)
  Cal_GaaSymKeyWrapAsymConfigType[CAL_SYM_KEY_WRAP_ASYM_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_SYM_KEY_WRAP_ASYM_STATUS == STD_ON) */

/*******************************************************************************
**                      AsymmPubKeyExtract Interface                          **
*******************************************************************************/
/* Asymmetrical Public Key Extract interface configured */
#if (CAL_ASYM_PUBLIC_KEY_EXTRACT_STATUS == STD_ON)
/* Asymmetrical Public Key Extract Interface States */
#define CAL_ASYM_PUBLIC_KEY_EXTRACT_IDLE         ((Cal_AlignType)0x25)
#define CAL_ASYM_PUBLIC_KEY_EXTRACT_ACTIVE       ((Cal_AlignType)0x26)

/* Type definition of the context buffer of Asymmetrical public Key Extract
 * service */
typedef Cal_AlignType Cal_AsymPublicKeyExtractCtxBufType
  [CAL_ASYM_PUBLIC_KEY_EXTRACT_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Public Key Extraction */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_AsymPublicKeyExtractCtxBufType contextBuffer);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_AsymPublicKeyExtractCtxBufType contextBuffer, const uint8 *dataPtr,
    uint32 dataLength);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_AsymPublicKeyExtractCtxBufType contextBuffer,
    Cal_AsymPublicKeyType *keyPtr);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_AsymPublicKeyExtractConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_AsymPublicKeyExtractConfigType, CAL_CONST)
  Cal_GaaAsymPublicKeyExtractConfigType
  [CAL_ASYM_PUBLIC_KEY_EXTRACT_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_ASYM_PUBLIC_KEY_EXTRACT_STATUS == STD_ON) */

/*******************************************************************************
**                      AsymmPrivKeyExtract Interface                         **
*******************************************************************************/
/* Asymmetrical Private Key Extract interface configured */
#if (CAL_ASYM_PRIVATE_KEY_EXTRACT_STATUS == STD_ON)
/* Asymmetrical Private Key Extract Interface States */
#define CAL_ASYM_PRIVATE_KEY_EXTRACT_IDLE        ((Cal_AlignType)0x27)
#define CAL_ASYM_PRIVATE_KEY_EXTRACT_ACTIVE      ((Cal_AlignType)0x28)

/* Type definition of the context buffer of Asymmetrical private Key Extract
 * service */
typedef Cal_AlignType Cal_AsymPrivateKeyExtractCtxBufType
  [CAL_ASYM_PRIVATE_KEY_EXTRACT_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Private Key Extraction */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_AsymPrivateKeyExtractCtxBufType contextBuffer);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_AsymPrivateKeyExtractCtxBufType contextBuffer, const uint8 *dataPtr,
    uint32 dataLength);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_AsymPrivateKeyExtractCtxBufType contextBuffer,
    Cal_AsymPrivateKeyType *keyPtr);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_AsymPrivateKeyExtractConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_AsymPrivateKeyExtractConfigType, CAL_CONST)
  Cal_GaaAsymPrivateKeyExtractConfigType
  [CAL_ASYM_PRIVATE_KEY_EXTRACT_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_ASYM_KEY_EXTRACT_STATUS == STD_ON) */

/*******************************************************************************
**                      Symmetrical key Interface                             **
*******************************************************************************/
/* Asymmetrical Key Wrap interface configured */
#if (CAL_ASYM_KEY_WRAP_SYM_STATUS == STD_ON)
/* Asymmetrical Key Wrap Sym Interface States */
#define CAL_ASYM_KEY_WRAP_SYM_IDLE               ((Cal_AlignType)0x29)
#define CAL_ASYM_KEY_WRAP_SYM_ACTIVE             ((Cal_AlignType)0x2A)

/* Type definition of the context buffer of Asymmetrical Key Wrap symmetric
 * service */
typedef Cal_AlignType Cal_AsymPrivateKeyWrapSymCtxBufType
  [CAL_ASYM_PRIVATE_KEY_WRAP_SYM_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Private Key Wrapping */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_AsymPrivateKeyWrapSymCtxBufType contextBuffer,
    const Cal_AsymPrivateKeyType *keyPtr, const Cal_SymKeyType *wrappingKeyPtr);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_AsymPrivateKeyWrapSymCtxBufType contextBuffer, uint8 *dataPtr,
    uint32 *dataLengthPtr);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_AsymPrivateKeyWrapSymCtxBufType contextBuffer);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_AsymPrivateKeyWrapSymConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_AsymPrivateKeyWrapSymConfigType, CAL_CONST)
  Cal_GaaAsymPrivateKeyWrapSymConfigType
  [CAL_ASYM_KEY_WRAP_SYM_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_ASYM_KEY_WRAP_SYM_STATUS == STD_ON) */

/*******************************************************************************
**                      Asymmetrical key Interface                            **
*******************************************************************************/
#if (CAL_ASYM_KEY_WRAP_ASYM_STATUS == STD_ON)
/* Asymmetrical Key Extract Asym Interface States */
#define CAL_ASYM_KEY_WRAP_ASYM_IDLE              ((Cal_AlignType)0x2B)
#define CAL_ASYM_KEY_WRAP_ASYM_ACTIVE            ((Cal_AlignType)0x2C)

/* Type definition of the context buffer of a Asymmetrical Key Wrap asymmetric
 * service */
typedef Cal_AlignType Cal_AsymPrivateKeyWrapAsymCtxBufType
  [CAL_ASYM_PRIVATE_KEY_WRAP_ASYM_CONTEXT_BUFFER_SIZE];

/* Structure contains all the information needed for Private Key Wrapping */
typedef struct
{
  /* pointer to Primitive Start Function */
  Cal_ReturnType (*PrimitiveStartFct)(const void *cfgPtr,
    Cal_AsymPrivateKeyWrapAsymCtxBufType contextBuffer,
    const Cal_AsymPrivateKeyType *keyPtr,
    const Cal_AsymPublicKeyType *wrappingKeyPtr);

  /* pointer to Primitive Update Function */
  Cal_ReturnType (*PrimitiveUpdateFct)(const void *cfgPtr,
    Cal_AsymPrivateKeyWrapAsymCtxBufType contextBuffer, uint8 *dataPtr,
    uint32 *dataLengthPtr);

  /* pointer to Primitive Finish Function */
  Cal_ReturnType (*PrimitiveFinishFct)(const void *cfgPtr,
    Cal_AsymPrivateKeyWrapAsymCtxBufType contextBuffer);

  void *PrimitiveConfigPtr;       /* pointer to configuration of Primitive */
  Cal_ConfigIdType configId;      /* Configuration Identifier */
} Cal_AsymPrivateKeyWrapAsymConfigType;

#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Cal_AsymPrivateKeyWrapAsymConfigType, CAL_CONST)
  Cal_GaaAsymPrivateKeyWrapAsymConfigType
  [CAL_ASYM_KEY_WRAP_ASYM_CFGID_LIMIT];
#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (CAL_ASYM_KEY_WRAP_ASYM_STATUS == STD_ON) */

#endif /* CAL_TYPES_H */

/******************************************************************************
**                      End of File                                          **
******************************************************************************/