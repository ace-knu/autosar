/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Det_PCTypes.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Development Error Tracer                              **
**                                                                            **
**  PURPOSE   : This file contains the structure declarations and macro       **
**              definitions of DET module                                     **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By               Description                       **
********************************************************************************
** 1.0.0     01-Jan-2013   Autron          Initial Version                    **
*******************************************************************************/
#ifndef DET_PCTYPES_H
#define DET_PCTYPES_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* DET macros */
#define DET_ZERO                             ((uint8)0x00)
#define DET_ONE                              ((uint8)0x01)
#define DET_TWO                              ((uint8)0x02)
#define DET_TRUE                             ((boolean)0x01)
#define DET_FALSE                            ((boolean)0x00)
#define DET_INITIALIZED                      ((boolean)0x01)

#define DET_INSTANCE_ID                      ((uint8)0)

/* Det Error Hook Function Pointer */
typedef P2FUNC(Std_ReturnType, DET_CODE, Det_FuncPtrType)
  (uint16 LusModuleId, uint8 LucInstanceId, uint8 LucApiId, uint8 LucErrorId);

/* Structure to store the parameters of DET Report Error function */
typedef struct STag_Det_ErrorType
{
  /* To store the ModuleId of the reporting module */
  uint16 usModuleId;
  /* To store the index based InstanceId of the reporting module */
  uint8 ucInstanceId;
  /* To store the ApiId of the reporting function */
  uint8 ucApiId;
  /* To store the ErrorId of the reporting error */
  uint8 ucErrorId;
}Det_ErrorType;

#if(DET_ERROR_HOOK == STD_ON)
#define DET_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of Function Pointers for Error Hook */
extern CONST(Det_FuncPtrType, DET_CONST) Det_GaaErrorHook[DET_TOTAL_ERROR_HOOKS];
#define DET_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

/*******************************************************************************
**                           Function Prototypes                              **
*******************************************************************************/

#endif /* DET_PCTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
