/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : ErrM.c                                                        **
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
** 0.0.2      15-06-2015    Daejun Park   Redmine #5187                       **
**                                                                            **
** 0.0.1      18-Dec-2015   Daejun Park   Initial version                     **
*******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "ErrM.h"
#include "Os.h"

#define SWC_ErrM_START_SEC_VAR_NO_INIT_8
#include "SWC_ErrM_MemMap.h"
uint8 ErrM_GucDemErrorCount = 0;
uint8 ErrM_GucOsErrorCount = 0;
uint8 ErrM_GucErrorCount = 0;
uint8 ErrM_GucErrorIndex = 0;
#define SWC_ErrM_STOP_SEC_VAR_NO_INIT_8
#include "SWC_ErrM_MemMap.h"

#define SWC_ErrM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "SWC_ErrM_MemMap.h"
ErrM_ErrorHistoryType ErrM_GaaErrorHistory[ERRM_MAX_NUMBER];
#define SWC_ErrM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "SWC_ErrM_MemMap.h"

#define SWC_ErrM_START_SEC_CODE
#include "SWC_ErrM_MemMap.h"
Std_ReturnType ErrM_DemEventNotification(
  Dem_EventIdType EventId,
  Dem_EventStatusExtendedType EventStatusOld,
  Dem_EventStatusExtendedType EventStatusNew)
{
  if ((EventStatusNew & 0x01) == 0x01)
  {
    SuspendOSInterrupts();
    ErrM_GaaErrorHistory[ErrM_GucErrorIndex].ErrorId = (uint16)EventId;
    ErrM_GaaErrorHistory[ErrM_GucErrorIndex].ErrorType = ERRM_DEM_EVENT_FAIL;

    ErrM_GucDemErrorCount++;
    ErrM_GucErrorIndex = (++ErrM_GucErrorCount) % ERRM_MAX_NUMBER;
    ResumeOSInterrupts();

    ErrM_ErrorProcess((uint16)EventId, ERRM_DEM_EVENT_FAIL);
  }

  return (E_OK);
}
#define SWC_ErrM_STOP_SEC_CODE
#include "SWC_ErrM_MemMap.h"

#define SWC_ErrM_START_SEC_CODE
#include "SWC_ErrM_MemMap.h"
void ErrM_OsErrorNotification(uint8 ErrorId)
{
  ErrM_GaaErrorHistory[ErrM_GucErrorIndex].ErrorId = (uint16)ErrorId;
  ErrM_GaaErrorHistory[ErrM_GucErrorIndex].ErrorType = ERRM_OS_ERROR;

  ErrM_GucOsErrorCount++;
  ErrM_GucErrorIndex = (++ErrM_GucErrorCount) % ERRM_MAX_NUMBER;

  ErrM_ErrorProcess((uint16)ErrorId, ERRM_OS_ERROR);
}
#define SWC_ErrM_STOP_SEC_CODE
#include "SWC_ErrM_MemMap.h"

#define SWC_ErrM_START_SEC_CODE
#include "SWC_ErrM_MemMap.h"
void ErrM_ErrorProcess(uint16 ErrorId, ErrM_ErrorType ErrorType)
{
  Std_ReturnType LddReturn;

  LddReturn = ErrM_Callback(ErrorId, ErrorType);
  if (LddReturn == E_NOT_OK)
  {
    /* Reset Action */
    Rte_Write_modeRequestPort_AppMode_AppMode(APP_MODE_INACTIVE_RESET);
  }
  else
  {
    /* No Action */
  }
}
#define SWC_ErrM_STOP_SEC_CODE
#include "SWC_ErrM_MemMap.h"