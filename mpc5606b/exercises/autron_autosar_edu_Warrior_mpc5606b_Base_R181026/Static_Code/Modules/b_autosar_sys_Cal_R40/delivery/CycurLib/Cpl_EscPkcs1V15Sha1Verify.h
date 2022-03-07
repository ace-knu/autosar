/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cpl_EscPkcs1V15Sha1Verify.h                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crypto Abstraction Library Module                     **
**                                                                            **
**  PURPOSE   : Header file for primitives interface                          **
**                - CycurLib Pkcs1V15 Sha1 Verify                             **
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

#ifndef CPL_ESCPKCS1V15SHA1VERIFY_H
#define CPL_ESCPKCS1V15SHA1VERIFY_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cal_Types.h"

/* Check if the primitive status is available, if not set STD_OFF */
#ifndef CAL_ESCPKCS1V15SHA1VERIFY_STATUS
#define CAL_ESCPKCS1V15SHA1VERIFY_STATUS STD_OFF
#endif

/* Signature Interface */
#if (CAL_SIGNATURE_VERIFY_STATUS == STD_ON)
/* Is Pkcs1V15 Sha1 Verify is configured */
#if (CAL_ESCPKCS1V15SHA1VERIFY_STATUS == STD_ON)
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cpl_EscGlobalType.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CAL_START_SEC_CODE
#include "MemMap.h"

/* Function for initialization */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscPkcs1V15Sha1VerifyStart(
  const void* cfgPtr, Cal_SignatureVerifyCtxBufType contextBuffer,
  const Cal_AsymPublicKeyType* keyPtr);

/* Function for Updating with the data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscPkcs1V15Sha1VerifyUpdate(
  const void* cfgPtr, Cal_SignatureVerifyCtxBufType contextBuffer,
  const uint8* dataPtr, uint32 dataLength);

/* Function for finishing the operation */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscPkcs1V15Sha1VerifyFinish(
  const void* cfgPtr, Cal_SignatureVerifyCtxBufType contextBuffer,
  const uint8* signaturePtr, uint32 signatureLength,
  Cal_VerifyResultType* resultPtr);

#define CAL_STOP_SEC_CODE
#include "MemMap.h"

#endif /* (CAL_ESCPKCS1V15SHA1VERIFY_STATUS == STATUS_ON) */
#endif /* (CAL_SIGNATURE_VERIFY_STATUS == STD_ON) */

#endif /* CPL_ESCPKCS1V15SHA1VERIFY_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
