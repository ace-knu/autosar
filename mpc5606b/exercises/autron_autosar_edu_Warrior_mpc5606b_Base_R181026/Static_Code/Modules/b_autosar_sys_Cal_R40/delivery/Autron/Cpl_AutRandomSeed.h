/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cpl_AutRandomSeed.h                                           **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crypto Abstraction Library Module                     **
**                                                                            **
**  PURPOSE   : Header file for primitives interface                          **
**                - Autron Random Seed                                        **
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
** 1.0.4     08-Jul-2016   Sinil        Redmine #5478                         **
** 1.0.3     16-May-2016   Sinil        Redmine #4903                         **
** 1.0.2     02-May-2016   Sinil        Redmine #4607                         **
** 1.0.0     28-Aug-2015   Autron       Initial version                       **
*******************************************************************************/

#ifndef CPL_AUTRANDOMSEED_H
#define CPL_AUTRANDOMSEED_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cal_Types.h"

/* Check if the primitive status is available, if not set STD_OFF */
#ifndef CAL_AUTRANDOMSEED_STATUS
#define CAL_AUTRANDOMSEED_STATUS STD_OFF
#endif

/* Random Interface */
#if (CAL_RANDOM_SEED_STATUS == STD_ON)
/* Is Random Generate is configured */
#if (CAL_AUTRANDOMSEED_STATUS == STD_ON)
#include "AutRandom.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#ifndef CPL_AUTRANDOMCONTEXTBUFFER
#define CPL_AUTRANDOMCONTEXTBUFFER
/* Cpl_AutRandomContextBuffer size : 12 */
typedef struct STag_Cpl_AutRandomContextBuffer
{
  /* Define job state */
  VAR(Cal_AlignType, CAL_VAR_NOINIT) ddJobState;

  /* AutRandom context */
  VAR(AutRandomContext, CAL_VAR_NOINIT) ddAutRandomContext;
} Cpl_AutRandomContextBuffer;
#endif

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CAL_START_SEC_CODE
#include "MemMap.h"

/* Function for initialization */
extern Cal_ReturnType Cpl_AutRandomSeedStart(const void *cfgPtr,
  Cal_RandomCtxBufType contextBuffer);

/* Function for Updating with the data */
extern Cal_ReturnType Cpl_AutRandomSeedUpdate(const void *cfgPtr,
  Cal_RandomCtxBufType contextBuffer, const uint8 *seedPtr, uint32 seedLength);

/* Function for finishing the operation */
extern Cal_ReturnType Cpl_AutRandomSeedFinish(const void *cfgPtr,
  Cal_RandomCtxBufType contextBuffer);

#define CAL_STOP_SEC_CODE
#include "MemMap.h"

#endif /* (CAL_AUTRANDOMSEED_STATUS == STATUS_ON) */
#endif /* (CAL_RANDOM_SEED_STATUS == STD_ON)  */

#endif /* CPL_AUTRANDOMSEED_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
