/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cpl_EscRsaDecrypt.h                                           **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crypto Abstraction Library Module                     **
**                                                                            **
**  PURPOSE   : Header file for primitives interface                          **
**                - CycurLib RSA Decrypt                                      **
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

#ifndef CPL_ESCRSADECRYPT_H
#define CPL_ESCRSADECRYPT_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cal_Types.h"

/* Check if the primitive status is available, if not set STD_OFF */
#ifndef CAL_ESCRSADECRYPT_STATUS
#define CAL_ESCRSADECRYPT_STATUS STD_OFF
#endif

/* Asymmetrical Interface */
#if (CAL_ASYM_DECRYPT_STATUS == STD_ON)
/* Is RSA Decrypt is configured */
#if (CAL_ESCRSADECRYPT_STATUS == STD_ON)
#include "Cpl_EscGlobalType.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CAL_START_SEC_CODE
#include "MemMap.h"

/* Function for initialization */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscRsaDecryptStart(
  const void* cfgPtr, Cal_AsymDecryptCtxBufType contextBuffer,
  const Cal_AsymPrivateKeyType* keyPtr);

/* Function for Updating with the data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscRsaDecryptUpdate(
  const void* cfgPtr, Cal_AsymDecryptCtxBufType contextBuffer,
  const uint8* cipherTextPtr, uint32 cipherTextLength, uint8* plainTextPtr,
  uint32* plainTextLengthPtr);

/* Function for finishing the operation */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscRsaDecryptFinish(
  const void* cfgPtr, Cal_AsymDecryptCtxBufType contextBuffer,
  uint8* plainTextPtr, uint32* plainTextLengthPtr);

#define CAL_STOP_SEC_CODE
#include "MemMap.h"

#endif /* (CAL_ESCRSADECRYPT_STATUS == STATUS_ON) */
#endif /* (CAL_ASYM_DECRYPT_STATUS == STD_ON)  */

#endif /* CPL_ESCRSADECRYPT_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
