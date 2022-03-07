/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_Indicator.h                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Event Manager                              **
**                                                                            **
**  PURPOSE   : C header for Dem_Indicator.c                                  **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision Date:DD-MM-YYYY By            Description                         **
********************************************************************************
** 1.1.0    16-04-2016      Youngjin Yun  Changes made As per Redmine #1164   **
**                                                                            **
** 1.0.0    11-06-2015      Autron        Initial Version                     **
*******************************************************************************/

#ifndef DEM_INDICATOR_H
#define DEM_INDICATOR_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(boolean, DEM_CODE) Dem_InitIndicator(Dem_EventIdType EventId);
extern FUNC(boolean, DEM_CODE) Dem_ActivateIndicatorOnEventFailed(Dem_EventIdType EventId, uint8  testFailedThisOpCycle);
extern FUNC(boolean, DEM_CODE) Dem_DeActivateIndicatorOnEventPassed(Dem_EventIdType EventId);
extern FUNC(boolean, DEM_CODE) Dem_DeActivateIndicatorOnOperationChange(Dem_EventIdType EventId);

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DEM_INDICATOR_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/


