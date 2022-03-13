/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cpl_EscHmacSha1Generate.h                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crypto Abstraction Library Module                     **
**                                                                            **
**  PURPOSE   : Header file for primitives interface                          **
**                - CycurLib Hmac Sha1 Generate                               **
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

#ifndef CPL_HMACSHA1GENERATE_H
#define CPL_HMACSHA1GENERATE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cal_Types.h"

/* Check if the primitive status is available, if not set STD_OFF */
#ifndef CAL_ESCHMACSHA1GENERATE_STATUS
#define CAL_ESCHMACSHA1GENERATE_STATUS STD_OFF
#endif

/* Signature Interface */
#if (CAL_MAC_GENERATE_STATUS == STD_ON)
/* Is Sha1 Generate is configured */
#if (CAL_ESCHMACSHA1GENERATE_STATUS == STD_ON)
#include "Cpl_EscGlobalType.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CAL_START_SEC_CODE
#include "MemMap.h"

/* Function for initialization */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscHmacSha1GenerateStart(
  const void *cfgPtr, Cal_MacGenerateCtxBufType contextBuffer,
  const Cal_SymKeyType *keyPtr);

/* Function for Updating with the data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscHmacSha1GenerateUpdate(
  const void *cfgPtr, Cal_MacGenerateCtxBufType contextBuffer,
  const uint8 *dataPtr, uint32 dataLength);

/* Function for finishing the operation */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscHmacSha1GenerateFinish(
  const void *cfgPtr, Cal_MacGenerateCtxBufType contextBuffer, uint8 *resultPtr,
  uint32 *resultLengthPtr, boolean TruncationIsAllowed);

#define CAL_STOP_SEC_CODE
#include "MemMap.h"

#endif /* (CAL_ESCHMACSHA1GENERATE_STATUS == STATUS_ON) */
#endif /* (CAL_MAC_GENERATE_STATUS == STD_ON) */

#endif /* CPL_HMACSHA1GENERATE_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
