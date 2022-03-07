/*******************************************************************************
**                            HYUNDAI MOTORS GROUP                            **
**                                                                            **
**                            All rights reserved                             **
**                                                                            **
**            You can NOT use this sample code for Product Release            **
*******************************************************************************/
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
** 0.0.1      18-Dec-2015   Daejun Park   Initial version                     **
*******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "ErrM.h"
#include "Dem_Cfg.h"
#include "Os_error_api.h"
#include "OsHook.h"

#define SWC_ErrM_START_SEC_CODE
#include "SWC_ErrM_MemMap.h"
Std_ReturnType ErrM_Callback(uint16 ErrorId, ErrM_ErrorType ErrorType)
{
  Std_ReturnType LddReturn;

  LddReturn = E_OK;
  if (ErrorType == ERRM_OS_ERROR)
  {
    if ((ErrorId == (uint16)_E_OS_SYS_MACHINECHECK) ||
        (ErrorId == (uint16)_E_OS_SYS_DATASTORAGE))
    {
      /* Reset Action */
      LddReturn = E_NOT_OK;
    }
    else
    {
      /* No Action */
    }
  }
  else /* ERRM_DEM_EVENT_FAIL */
  {
    if ((ErrorId == (uint16)DemConf_DemEventParameter_WDGM_E_MONITORING) || 
        (ErrorId == (uint16)DemConf_DemEventParameter_WDG_E_MISS_TRIGGER))
    {
      /* Reset Action */
      LddReturn = E_NOT_OK;
    }
    else
    {
      /* No Action */
    }
  }

  return LddReturn;
}
#define SWC_ErrM_STOP_SEC_CODE
#include "SWC_ErrM_MemMap.h"
