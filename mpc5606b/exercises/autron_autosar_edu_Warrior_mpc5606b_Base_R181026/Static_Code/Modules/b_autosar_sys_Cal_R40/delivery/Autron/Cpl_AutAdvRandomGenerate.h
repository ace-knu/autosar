/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Cpl_AutAdvRandomGenerate.h                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crypto Abstraction Library Module                     **
**                                                                            **
**  PURPOSE   : Header file for primitives interface                          **
**                - Autron Advanced Random Generate                           **
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
** 1.0.3     12-May-2016   Sinil        Redmine #4880                         **
** 1.0.2     02-May-2016   Sinil        Redmine #4607                         **
** 1.0.0     15-Sep-2015   Sinil        Initial version                       **
*******************************************************************************/

#ifndef CPL_AUTADVRANDOMGENERATE_H
#define CPL_AUTADVRANDOMGENERATE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cal_Types.h"            /* Header file for Cal types */

/* Check if the primitive status is available, if not set STD_OFF */
#ifndef CAL_AUTADVRANDOMGENERATE_STATUS
#define CAL_AUTADVRANDOMGENERATE_STATUS                 (STD_OFF)
#endif

/* Random Interface */
#if (CAL_RANDOM_GENERATE_STATUS == STD_ON)
/* Is Random Generate is configured */
#if (CAL_AUTADVRANDOMGENERATE_STATUS == STD_ON)

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/** Length of advanced random number in byte. */
#define CAL_AUT_ADVRANDOM_NUM_BYTES                     ((uint8)8U)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#ifndef CPL_AUTADVRANDOMCONTEXTBUFFER
#define CPL_AUTADVRANDOMCONTEXTBUFFER
/* Cpl AutAdvRandom Context buffer*/
typedef struct STag_Cpl_AutAdvRandomContextBuffer
{
  /* Define job state */
  VAR(Cal_AlignType, CAL_VAR_NOINIT) ddJobState;
} Cpl_AutAdvRandomContextBuffer;
#endif

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CAL_START_SEC_CODE
#include "MemMap.h"
/* Function for initialization */
extern FUNC(Cal_ReturnType, CAL_CODE) Cpl_AutAdvRandomGenerate(
  const void* cfgPtr, Cal_RandomCtxBufType contextBuffer, uint8* resultPtr,
  uint32 resultLength);
#define CAL_STOP_SEC_CODE
#include "MemMap.h"
#endif /* (CAL_AUTADVRANDOMGENERATE_STATUS == STATUS_ON) */
#endif /* (CAL_RANDOM_GENERATE_STATUS == STD_ON)  */

#endif /* CPL_AUTADVRANDOMGENERATE_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
