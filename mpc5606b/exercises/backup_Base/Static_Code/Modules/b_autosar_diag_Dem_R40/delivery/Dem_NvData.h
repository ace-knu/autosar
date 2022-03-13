/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_NvData.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Event Manager                              **
**                                                                            **
**  PURPOSE   : C header for Dem_NvData.h                                     **
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
** 1.0.0    14-01n-2014     YoungJin.Yun  Initial Version                     **
*******************************************************************************/



#ifndef DEM_NVDATA_H
#define DEM_NVDATA_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem_PCTypes.h"
#include "NvM.h"              /* NVRAM manager symbols Header File */

#define DEM_START_SEC_CODE
#include "MemMap.h"


extern FUNC(NvM_RequestResultType, DEM_CODE)
Dem_NvData_GetNvMErrorStatus(NvM_BlockIdType BlockId);



extern FUNC(Std_ReturnType, DEM_CODE) Dem_NvData_GetNvMBlockId(
  const Dem_NvDataIdType NvDataId,
  const Dem_DTCOriginType DTCOrigin,
  const Dem_NumOfEventMemoryEntryType MemLocation,  
  P2VAR(NvM_BlockIdType, AUTOMATIC, DEM_APPL_DATA) BlockId);
  
extern FUNC(Std_ReturnType, DEM_CODE) Dem_NvData_ReadNonVolatileData(
  const Dem_NvDataIdType NvDataId);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_NvData_WriteNonVolatileData(
  const Dem_NvDataIdType NvDataId);

extern FUNC(boolean, DEM_CODE) Dem_NvData_WaitNvmFinishJob(
  const uint8 Filter,
  const boolean Direction);
  
extern FUNC(Std_ReturnType, DEM_CODE)
Dem_NvData_WriteBlock(
  NvM_BlockIdType BlockId,
  P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_SrcPtr);
  
#define DEM_STOP_SEC_CODE
#include "MemMap.h"


#endif

