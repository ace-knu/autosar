/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cpl_EscAesCbcDecrypt.h                                        **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crypto Abstraction Library Module                     **
**                                                                            **
**  PURPOSE   : Header file for primitives interface                          **
**                - CycurLib AES CBC Decrypt                                  **
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
** 1.0.4     08-Jul-2016   Sinil        Redmine #5478                         **
** 1.0.3     16-May-2016   Sinil        Redmine #4903                         **
** 1.0.2     02-May-2016   Sinil        Redmine #4607                         **
** 1.0.0     10-Mar-2015   Autron       Initial version                       **
*******************************************************************************/

#ifndef CPL_ESCAESCBCDECRYPT_H
#define CPL_ESCAESCBCDECRYPT_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cal_Types.h"

/* Check if the primitive status is available, if not set STD_OFF */
#ifndef CAL_ESCAESCBCDECRYPT_STATUS
#define CAL_ESCAESCBCDECRYPT_STATUS STD_OFF
#endif

/* Symmetrical Interface */
#if (CAL_SYM_DECRYPT_STATUS == STD_ON)
/* CycurLib AES CBC Decrypt is configured */
#if (CAL_ESCAESCBCDECRYPT_STATUS == STD_ON)
#include "Cpl_EscGlobalType.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CAL_START_SEC_CODE
#include "MemMap.h"

/* Function for initialization */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscAesCbcDecryptStart
  (const void* cfgPtr, Cal_SymDecryptCtxBufType contextBuffer,
  const Cal_SymKeyType* keyPtr, const uint8* InitVectorPtr,
  uint32 InitVectorLength);

/* Function for Updating with the data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscAesCbcDecryptUpdate
  (const void* cfgPtr, Cal_SymDecryptCtxBufType contextBuffer,
  const uint8* cipherTextPtr, uint32 cipherTextLength, uint8* plainTextPtr,
  uint32* plainTextLengthPtr);

/* Function for finishing the operation */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscAesCbcDecryptFinish
  (const void* cfgPtr, Cal_SymDecryptCtxBufType contextBuffer,
  uint8* plainTextPtr, uint32* plainTextLengthPtr);

#define CAL_STOP_SEC_CODE
#include "MemMap.h"

#endif /* (CAL_ESCAESCBCDECRYPT_STATUS == STD_ON) */
#endif /* (CAL_SYM_DECRYPT_STATUS == STD_ON) */

#endif /* CPL_ESCAESCBCDECRYPT_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
