/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cpl_AutSeedKey.h                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crypto Abstraction Library Module                     **
**                                                                            **
**  PURPOSE   : Header file for primitives interface                          **
**                - Autron SeedKey                                            **
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
** 1.0.3     08-Jul-2016   Sinil        Redmine #5478                         **
** 1.0.2     02-May-2016   Sinil        Redmine #4607                         **
** 1.0.0     10-Mar-2015   Autron       Initial version                       **
*******************************************************************************/

#ifndef CPL_AUTSEEDKEY_H
#define CPL_AUTSEEDKEY_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cal_Types.h"

/* Check if the primitive status is available, if not set STD_OFF */
#ifndef CAL_AUTSEEDKEY_STATUS
#define CAL_AUTSEEDKEY_STATUS STD_OFF
#endif

/* Hash Interface */
#if (CAL_HASH_STATUS == STD_ON)
/* Is Random Generate is configured */
#if (CAL_AUTSEEDKEY_STATUS == STD_ON)
#include "AutSeedKey.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/** Length of one hash block in bytes. */
#define AUT_SEEDKEY_BLOCK_BYTES                         Aut_SeedKey_BLOCK_BYTES
/** Length of digest in byte. */
#define AUT_SEEDKEY_DIGEST_LEN                          Aut_SeedKey_DIGEST_LEN

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Cpl_EscSeedKeyContextBuffer size : 8 */
typedef struct STag_Cpl_AutSeedKeyContextBuffer
{
  /* Define job state */
  VAR(Cal_AlignType, CAL_VAR_NOINIT) ddJobState;

  /* Autron SeedKey primitive library context */
  VAR(AutSeedKeyContext, CAL_VAR_NOINIT) ddSeedKeyContext;
} Cpl_AutSeedKeyContextBuffer;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CAL_START_SEC_CODE
#include "MemMap.h"

/* Function for initialization */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_AutSeedKeyStart(const void *cfgPtr,
  Cal_HashCtxBufType contextBuffer);

/* Function for Updating with the data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_AutSeedKeyUpdate(const void *cfgPtr,
  Cal_HashCtxBufType contextBuffer, const uint8 *dataPtr, uint32 dataLength);

/* Function for finishing the operation */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_AutSeedKeyFinish(const void *cfgPtr,
  Cal_HashCtxBufType contextBuffer, uint8 *resultPtr, uint32 *resultLengthPtr,
  boolean TruncationIsAllowed);

#define CAL_STOP_SEC_CODE
#include "MemMap.h"
#endif /* (CAL_AUTSEEDKEY_STATUS == STATUS_ON) */
#endif /* (CAL_HASH_STATUS == STD_ON)  */

#endif /* CPL_AUTSEEDKEY_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
