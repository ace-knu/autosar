/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cpl_EscSha1.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crypto Abstraction Library Module                     **
**                                                                            **
**  PURPOSE   : Header file for primitives interface                          **
**                - CycurLib Sha1                                             **
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
** 1.0.2     02-May-2016   Sinil        Redmine #4607                         **
** 1.0.0     10-Mar-2015   Autron       Initial version                       **
*******************************************************************************/

#ifndef CPL_ESCSHA1_H
#define CPL_ESCSHA1_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cal_Types.h"

/* Check if the primitive status is available, if not set STD_OFF */
#ifndef CAL_ESCSHA1_STATUS
#define CAL_ESCSHA1_STATUS STD_OFF
#endif

/* Hash Interface */
#if (CAL_HASH_STATUS == STD_ON)
/* Is Sha1 is configured */
#if (CAL_ESCSHA1_STATUS == STD_ON)
#include "Cpl_EscGlobalType.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CAL_START_SEC_CODE
#include "MemMap.h"

/* Function for initialization */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscSha1Start(const void *cfgPtr,
  Cal_HashCtxBufType contextBuffer);

/* Function for Updating with the data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscSha1Update(const void *cfgPtr,
  Cal_HashCtxBufType contextBuffer, const uint8 *dataPtr, uint32 dataLength);

/* Function for finishing the operation */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_EscSha1Finish(const void *cfgPtr,
  Cal_HashCtxBufType contextBuffer, uint8 *resultPtr, uint32 *resultLengthPtr,
  boolean TruncationIsAllowed);

#define CAL_STOP_SEC_CODE
#include "MemMap.h"

#endif /* (CAL_ESCSHA1_STATUS == STATUS_ON) */
#endif /* (CAL_HASH_STATUS == STD_ON)  */

#endif /* CPL_ESCSHA1_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
