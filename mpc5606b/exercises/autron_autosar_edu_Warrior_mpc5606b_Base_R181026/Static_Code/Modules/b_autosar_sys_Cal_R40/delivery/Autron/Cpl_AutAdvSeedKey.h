/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cpl_AutAdvSeedKey.h                                           **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crypto Abstraction Library Module                     **
**                                                                            **
**  PURPOSE   : Header file for primitives interface                          **
**                - Autron Advanced SeedKey                                   **
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
** 1.0.0     15-Sep-2015   Sinil        Initial version                       **
*******************************************************************************/

#ifndef CPL_AUTADVSEEDKEY_H
#define CPL_AUTADVSEEDKEY_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cal_Types.h"            /* Header file for Cal types */

/* Check if the primitive status is available, if not set STD_OFF */
#ifndef CAL_AUTADVSEEDKEY_STATUS
#define CAL_AUTADVSEEDKEY_STATUS STD_OFF
#endif

/* Hash Interface */
#if (CAL_HASH_STATUS == STD_ON)
/* Is Random Generate is configured */
#if (CAL_AUTADVSEEDKEY_STATUS == STD_ON)

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/** Length of seed in bytes. */
#define CAL_AUT_ADVSEEDKEY_SEED_BYTES                   8U
/** Length of key in bytes. */
#define CAL_AUT_ADVSEEDKEY_KEY_BYTES                    8U

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Cpl_AutAdvSeedKeyContextBuffer size : 9(12) */
typedef struct STag_Cpl_AutAdvSeedKeyContextBuffer
{
  /* Define job state */
  VAR(Cal_AlignType, CAL_VAR_NOINIT) ddJobState;

  /* Advanced SeedKey value */
  VAR(uint8, CAL_VAR_NOINIT) aaSeedValue[CAL_AUT_ADVSEEDKEY_SEED_BYTES];
} Cpl_AutAdvSeedKeyContextBuffer;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CAL_START_SEC_CODE
#include "MemMap.h"

/* Function for initialization */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_AutAdvSeedKeyStart(const void *cfgPtr,
  Cal_HashCtxBufType contextBuffer);

/* Function for Updating with the data */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_AutAdvSeedKeyUpdate(
  const void *cfgPtr, Cal_HashCtxBufType contextBuffer, const uint8 *dataPtr,
  uint32 dataLength);

/* Function for finishing the operation */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_AutAdvSeedKeyFinish(
  const void *cfgPtr, Cal_HashCtxBufType contextBuffer, uint8 *resultPtr,
  uint32 *resultLengthPtr, boolean TruncationIsAllowed);

#define CAL_STOP_SEC_CODE
#include "MemMap.h"

#endif /* (CAL_AUTADVSEEDKEY_STATUS == STATUS_ON) */
#endif /* (CAL_HASH_STATUS == STD_ON)  */

#endif /* CPL_AUTADVSEEDKEY_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
