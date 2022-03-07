/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : ErrM.h                                                        **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Error Management SWC                                  **
**                                                                            **
**  PURPOSE   : SWC code for Error Management                                 **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                              Revision History                              **
********************************************************************************
** Revision   Date          By            Description                         **
********************************************************************************
** 0.0.1      18-Dec-2015   Daejun Park   Initial version                     **
*******************************************************************************/

#ifndef ERRM_H
#define ERRM_H
/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "Rte_SWC_ErrM.h"

#define ERRM_MAX_NUMBER  32

typedef enum {
  ERRM_NONE,
  ERRM_OS_ERROR,
  ERRM_DEM_EVENT_FAIL
} ErrM_ErrorType;

typedef struct {
  uint16 ErrorId;
  ErrM_ErrorType ErrorType;
} ErrM_ErrorHistoryType;

#define SWC_ErrM_START_SEC_CODE
#include "SWC_ErrM_MemMap.h"
extern void ErrM_OsErrorNotification(uint8 ErrorId);
#define SWC_ErrM_STOP_SEC_CODE
#include "SWC_ErrM_MemMap.h"

#define SWC_ErrM_START_SEC_CODE
#include "SWC_ErrM_MemMap.h"
extern Std_ReturnType ErrM_Callback(uint16 ErrorId, ErrM_ErrorType ErrorType);
#define SWC_ErrM_STOP_SEC_CODE
#include "SWC_ErrM_MemMap.h"

#define SWC_ErrM_START_SEC_CODE
#include "SWC_ErrM_MemMap.h"
extern void ErrM_ErrorProcess(uint16 ErrorId, ErrM_ErrorType ErrorType);
#define SWC_ErrM_STOP_SEC_CODE
#include "SWC_ErrM_MemMap.h"

#endif