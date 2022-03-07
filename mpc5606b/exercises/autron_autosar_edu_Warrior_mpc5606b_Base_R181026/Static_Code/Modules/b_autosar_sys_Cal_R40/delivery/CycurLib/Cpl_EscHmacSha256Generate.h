/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cpl_EscHmacSha256Generate.h                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crypto Abstraction Library Module                     **
**                                                                            **
**  PURPOSE   : Header file for primitives interface                          **
**                - CycurLib Hmac Sha256 Generate                             **
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
** 1.0.1     08-Jul-2016   Sinil        Redmine #5478                         **
** 1.0.0     01-Jun-2016   Sinil        Initial version, Redmine #5093        **
*******************************************************************************/

#ifndef CPL_HMACSHA256GENERATE_H
#define CPL_HMACSHA256GENERATE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cal_Types.h"

/* Check if the primitive status is available, if not set STD_OFF */
#ifndef CAL_ESCHMACSHA256GENERATE_STATUS
#define CAL_ESCHMACSHA256GENERATE_STATUS STD_OFF
#endif

/* Signature Interface */
#if (CAL_MAC_GENERATE_STATUS == STD_ON)
/* Is Sha256 Generate is configured */
#if (CAL_ESCHMACSHA256GENERATE_STATUS == STD_ON)
#include "Cpl_EscGlobalType.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CAL_START_SEC_CODE
#include "MemMap.h"

/* Function for initialization */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscHmacSha256GenerateStart(
  const void *cfgPtr, Cal_MacGenerateCtxBufType contextBuffer,
  const Cal_SymKeyType *keyPtr);

/* Function for Updating with the data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscHmacSha256GenerateUpdate(
  const void *cfgPtr, Cal_MacGenerateCtxBufType contextBuffer,
  const uint8 *dataPtr, uint32 dataLength);

/* Function for finishing the operation */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscHmacSha256GenerateFinish(
  const void *cfgPtr, Cal_MacGenerateCtxBufType contextBuffer, uint8 *resultPtr,
  uint32 *resultLengthPtr, boolean TruncationIsAllowed);

#define CAL_STOP_SEC_CODE
#include "MemMap.h"

#endif /* (CAL_ESCHMACSHA256GENERATE_STATUS == STATUS_ON) */
#endif /* (CAL_MAC_GENERATE_STATUS == STD_ON) */

#endif /* CPL_HMACSHA256GENERATE_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
