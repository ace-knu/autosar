/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_Obd.h                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Event Manager                              **
**                                                                            **
**  PURPOSE   : C header for Dem_Obd.c                                        **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By          Description                            **
********************************************************************************
**                                                                            **
** 1.0.0     06-11-2015    Autron      Initial Version                        **                      
*******************************************************************************/

#ifndef DEM_OBD_H
#define DEM_OBD_H
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


#if(DEM_OBD_SUPPORT == STD_ON)
extern FUNC(void, DEM_CODE) Dem_InitOBD(void);
extern FUNC(void, DEM_CODE) Dem_MainFunctionOBD(void);
#endif


#if ((DEM_NUMBER_OF_INDICATORS > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
extern FUNC(void, DEM_CODE)
Dem_SetMalfuntionOnOff(
    Dem_EventParameterCPCType event,
    uint8 OperationCycleId,
    Dem_UdsStatusByteType EventStatusMask);
#endif


#if (DEM_OBD_SUPPORT == STD_ON)
extern FUNC(void, DEM_CODE) Dem_CalcPIDValue(
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PIDValue,
  uint8 LusByteValue, uint8 LucOBDReadinessGrp);

extern FUNC(void, DEM_CODE) Dem_CalcPID41_34(
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID41Value);
#endif

#if (DEM_OBD_SUPPORT == STD_ON)

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetPIDDataOnRequest(
  P2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_APPL_CONST)LpEventMemory,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)DestBuffer,
  uint8 LucEventMemoryIndex, boolean ReportTotalRecord, uint16 DataIdentifier,
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)LucTotalSizePid);
#endif

#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
extern FUNC(void, DEM_CODE) Dem_ProcessIumpr(uint8 LucOperationCycleId);
#endif

#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
extern FUNC(void, DEM_CODE)Dem_GetRatioIndex(
  Dem_EventParameterCPCType event,
  uint32 ArrayIndex,
  P2VAR(uint8, AUTOMATIC,DEM_VAR) RatioId);
#endif


#define DEM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DEM_INDICATOR_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/


