/*******************************************************************************
**                                                                            **
**  (C) 2016 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cpl_AutHacRandomGenerate.h                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crypto Abstraction Library Module                     **
**                                                                            **
**  PURPOSE   : Header file for primitives interface                          **
**                - Autron Hac Random Generate                                **
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
** 1.0.0     26-Oct-2016   Sinil        Redmine #6688                         **
*******************************************************************************/

#ifndef CPL_AUTHACRANDOMGENERATE_H
#define CPL_AUTHACRANDOMGENERATE_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cal_Types.h"

/* Check if the primitive status is available, if not set STD_OFF */
#ifndef CAL_AUTHACRANDOMGENERATE_STATUS
#define CAL_AUTHACRANDOMGENERATE_STATUS                 (STD_OFF)
#endif

/* Random Interface */
#if (CAL_RANDOM_GENERATE_STATUS == STD_ON)
/* Is Random Generate is configured */
#if (CAL_AUTHACRANDOMGENERATE_STATUS == STD_ON)
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
/* Cpl_AutHacRandomContextBuffer size : 52 */
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
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_AutHacRandomGenerate(
  const void* cfgPtr, Cal_RandomCtxBufType contextBuffer, uint8* resultPtr,
  uint32 resultLength);

#define CAL_STOP_SEC_CODE
#include "MemMap.h"

#endif /* (CAL_AUTHACRANDOMGENERATE_STATUS == STATUS_ON) */
#endif /* (CAL_RANDOM_GENERATE_STATUS == STD_ON)  */

#endif /* CPL_AUTHACRANDOMGENERATE_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
