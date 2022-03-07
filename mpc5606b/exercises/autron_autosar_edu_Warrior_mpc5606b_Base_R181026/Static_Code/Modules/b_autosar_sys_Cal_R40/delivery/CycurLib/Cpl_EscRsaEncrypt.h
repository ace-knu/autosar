/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cpl_EscRsaEncrypt.h                                           **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crypto Abstraction Library Module                     **
**                                                                            **
**  PURPOSE   : Header file for primitives interface                          **
**                - CycurLib RSA Encrypt                                      **
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
** 1.0.5     08-Jul-2016   Sinil        Redmine #5478                         **
** 1.0.4     16-May-2016   Sinil        Redmine #4903                         **
** 1.0.3     02-May-2016   Sinil        Redmine #4607                         **
** 1.0.0     10-Mar-2015   Autron       Initial version                       **
*******************************************************************************/

#ifndef CPL_ESCRSAENCRYPT_H
#define CPL_ESCRSAENCRYPT_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cal_Types.h"

/* Check if the primitive status is available, if not set STD_OFF */
#ifndef CAL_ESCRSAENCRYPT_STATUS
#define CAL_ESCRSAENCRYPT_STATUS STD_OFF
#endif

/* Asymmetrical Interface */
#if (CAL_ASYM_ENCRYPT_STATUS == STD_ON)
/* Is RSA Encrypt is configured */
#if (CAL_ESCRSAENCRYPT_STATUS == STD_ON)
#include "Cpl_EscGlobalType.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CAL_START_SEC_CODE
#include "MemMap.h"

/* Function for initialization */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscRsaEncryptStart(
  const void* cfgPtr, Cal_AsymEncryptCtxBufType contextBuffer,
  const Cal_AsymPublicKeyType* keyPtr);

/* Function for Updating with the data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscRsaEncryptUpdate(
  const void* cfgPtr, Cal_AsymEncryptCtxBufType contextBuffer,
  const uint8* plainTextPtr, uint32 plainTextLength, uint8* cipherTextPtr,
  uint32* cipherTextLengthPtr);

/* Function for finishing the operation */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscRsaEncryptFinish(
  const void* cfgPtr, Cal_AsymEncryptCtxBufType contextBuffer,
  uint8* cipherTextPtr, uint32* cipherTextLengthPtr);

#define CAL_STOP_SEC_CODE
#include "MemMap.h"

#endif /* (CAL_ESCRSAENCRYPT_STATUS == STATUS_ON) */
#endif /* (CAL_ASYM_ENCRYPT_STATUS == STD_ON)  */

#endif /* CPL_ESCRSAENCRYPT_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
