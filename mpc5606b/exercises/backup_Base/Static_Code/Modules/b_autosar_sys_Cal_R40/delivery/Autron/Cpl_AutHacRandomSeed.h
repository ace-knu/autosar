/*******************************************************************************
**                                                                            **
**  (C) 2016 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cpl_AutHacRandomSeed.h                                        **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crypto Abstraction Library Module                     **
**                                                                            **
**  PURPOSE   : Header file for primitives interface                          **
**                - Autron Hac Random Seed                                    **
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
** 1.0.1     11-Jan-2017   Sinil        Redmine #7197                         **
** 1.0.0     26-Oct-2016   Sinil        Redmine #6688                         **
*******************************************************************************/

#ifndef CPL_AUTHACRANDOMSEED_H
#define CPL_AUTHACRANDOMSEED_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cal_Types.h"

/* Check if the primitive status is available, if not set STD_OFF */
#ifndef CAL_AUTHACRANDOMSEED_STATUS
#define CAL_AUTHACRANDOMSEED_STATUS                     (STD_OFF)
#endif

/* Random Interface */
#if (CAL_RANDOM_SEED_STATUS == STD_ON)
/* Is Random Generate is configured */
#if (CAL_AUTHACRANDOMSEED_STATUS == STD_ON)
#if (CAL_FBLLIB_USED == STD_ON)
#include "Fbl_Shared.h"
#else
#include "Hac_Prng.h"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#ifndef CPL_AUTHACRANDOMCONTEXTBUFFER
#define CPL_AUTHACRANDOMCONTEXTBUFFER
/* Cpl_AutHacRandomContextBuffer size : 56 */
typedef struct STag_Cpl_AutHacRandomContextBuffer
{
  /* Define job state */
  VAR(Cal_AlignType, CAL_VAR_NOINIT) ddJobState;

  /* Hac Pseudo Random context */
  VAR(HacPrngCtx, CAL_VAR_NOINIT) ddHacPrngCtx;
} Cpl_AutHacRandomContextBuffer;
#endif

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CAL_START_SEC_CODE
#include "MemMap.h"

/* Function for initialization */
extern Cal_ReturnType Cpl_AutHacRandomSeedStart(const void* cfgPtr,
  Cal_RandomCtxBufType contextBuffer);

/* Function for Updating with the data */
extern Cal_ReturnType Cpl_AutHacRandomSeedUpdate(const void* cfgPtr,
  Cal_RandomCtxBufType contextBuffer, const uint8* seedPtr, uint32 seedLength);

/* Function for finishing the operation */
extern Cal_ReturnType Cpl_AutHacRandomSeedFinish(const void* cfgPtr,
  Cal_RandomCtxBufType contextBuffer);

#define CAL_STOP_SEC_CODE
#include "MemMap.h"

#endif /* (CAL_AUTHACRANDOMSEED_STATUS == STATUS_ON) */
#endif /* (CAL_RANDOM_SEED_STATUS == STD_ON)  */

#endif /* CPL_AUTHACRANDOMSEED_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
