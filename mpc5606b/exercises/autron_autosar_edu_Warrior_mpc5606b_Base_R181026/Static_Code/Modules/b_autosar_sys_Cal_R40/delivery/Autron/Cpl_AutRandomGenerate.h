/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cpl_AutRandomGenerate.h                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crypto Abstraction Library Module                     **
**                                                                            **
**  PURPOSE   : Header file for primitives interface                          **
**                - Autron Random Generate                                    **
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
** 1.0.4     16-May-2016   Sinil        Redmine #4903                         **
** 1.0.3     02-May-2016   Sinil        Redmine #4607                         **
** 1.0.0     10-Mar-2015   Autron       Initial version                       **
*******************************************************************************/

#ifndef CPL_AUTRANDOMGENERATE_H
#define CPL_AUTRANDOMGENERATE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cal_Types.h"

/* Check if the primitive status is available, if not set STD_OFF */
#ifndef CAL_AUTRANDOMGENERATE_STATUS
#define CAL_AUTRANDOMGENERATE_STATUS STD_OFF
#endif

/* Random Interface */
#if (CAL_RANDOM_GENERATE_STATUS == STD_ON)
/* Is Random Generate is configured */
#if (CAL_AUTRANDOMGENERATE_STATUS == STD_ON)

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "AutRandom.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#ifndef CPL_AUTRANDOMCONTEXTBUFFER
#define CPL_AUTRANDOMCONTEXTBUFFER
/* Cpl AutRandom Context buffer*/
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
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_AutRandomGenerate(
  const void* cfgPtr, Cal_RandomCtxBufType contextBuffer, uint8* resultPtr,
  uint32 resultLength);
#define CAL_STOP_SEC_CODE
#include "MemMap.h"
#endif /* (CAL_AUTRANDOMGENERATE_STATUS == STATUS_ON) */
#endif /* (CAL_RANDOM_GENERATE_STATUS == STD_ON)  */

#endif /* CPL_AUTRANDOMGENERATE_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
