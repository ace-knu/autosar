/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cpl_EscHmacSha1Verify.h                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crypto Abstraction Library Module                     **
**                                                                            **
**  PURPOSE   : Header file for primitives interface                          **
**                - CycurLib Hmac Sha1 Verify                                 **
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
** 1.0.1     02-May-2016   Sinil        Redmine #4607                         **
** 1.0.0     16-Sep-2015   Sinil        Initial version                       **
*******************************************************************************/

#ifndef CPL_ESCHMACSHA1VERIFY_H
#define CPL_ESCHMACSHA1VERIFY_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cal_Types.h"

/* Check if the primitive status is available, if not set STD_OFF */
#ifndef CAL_ESCHMACSHA1VERIFY_STATUS
#define CAL_ESCHMACSHA1VERIFY_STATUS STD_OFF
#endif

/* Signature Interface */
#if (CAL_MAC_VERIFY_STATUS == STD_ON)
/* Is Pkcs1V15 Sha1 Verify is configured */
#if (CAL_ESCHMACSHA1VERIFY_STATUS == STD_ON)
#include "Cpl_EscGlobalType.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CAL_START_SEC_CODE
#include "MemMap.h"

/* Function for initialization */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscHmacSha1VerifyStart(
  const void *cfgPtr, Cal_MacVerifyCtxBufType contextBuffer,
  const Cal_SymKeyType *keyPtr);

/* Function for Updating with the data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscHmacSha1VerifyUpdate(
  const void *cfgPtr, Cal_MacVerifyCtxBufType contextBuffer,
  const uint8 *dataPtr, uint32 dataLength);

/* Function for finishing the operation */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscHmacSha1VerifyFinish(
  const void *cfgPtr, Cal_MacVerifyCtxBufType contextBuffer,
  const uint8 *MacPtr, uint32 MacLength, Cal_VerifyResultType *resultPtr);

#define CAL_STOP_SEC_CODE
#include "MemMap.h"

#endif /* (CAL_ESCHMACSHA1VERIFY_STATUS == STATUS_ON) */
#endif /* (CAL_MAC_VERIFY_STATUS == STD_ON) */

#endif /* CPL_ESCHMACSHA1VERIFY_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
