/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_EventRelatedData.h                                        **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Event Manager                              **
**                                                                            **
**  PURPOSE   : C header for Dem_EventRelatedData.c                            **
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
** 1.0.0    07-02-2015      YoungJin.Yun  Initial Version                     **
*******************************************************************************/


#ifndef DEM_EVENTRELATEDDATA_H
#define DEM_EVENTRELATEDDATA_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem_PCTypes.h"
#include "Dem_Config.h"

#define DEM_START_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**                Extern function definition                                  **
*******************************************************************************/

#if (DEM_SIZE_OF_FREEZEFRAME > 0U)    
extern FUNC(Std_ReturnType, DEM_CODE) 
Dem_GetSizeOfFreezeFrameByRecord(
  Dem_EventIdType EventId,
  Dem_RecordNumberType RecordNumber,
  Dem_DTCOriginType DTCOrigin,   /* DTCOrigin is verified by caller */
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame);

#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U)
extern FUNC(boolean, DEM_CODE)
Dem_CaptureFFClass(
  Dem_FreezeFrameClassCPCType FFDataClass,
  P2VAR(uint8, AUTOMATIC, DEM_VAR) OutBuffer,
  uint32 BufSize);
#endif

#endif

#if (DEM_SIZE_OF_EVENT_DATA > 0U)
extern FUNC(boolean, DEM_CODE)
Dem_StoreEventRelatedData(
 P2CONST(Dem_EventRelatedDataType, AUTOMATIC, DEM_CONST) EvData,
 Dem_EventMemoryEntryPtrType EvMemEntry);
#endif


#if (DEM_OBD_SUPPORT == STD_ON)
#if (DEM_SIZE_OF_OBD_FF > 0u)
extern FUNC(boolean, DEM_CODE)
Dem_StoreObdFFClass(
  Dem_EventRelatedDataCPCType EvData,
  Dem_EventMemoryEntryPtrType entry);
#endif
#endif


extern FUNC(Std_ReturnType, DEM_CODE) 
Dem_ReadDataOfExtendedData(
  Dem_EventRelatedDataPCType EvData,
  Dem_DTCOriginType DTCOrigin,
  Dem_ExtendedDataNumberType  ExtendedDataNumber,
  P2VAR(uint8, AUTOMATIC, DEM_VAR) DestBuffer,
  P2VAR(uint16, AUTOMATIC, DEM_VAR) BufSize);



extern FUNC(Dem_ReturnReadEventDataType, DEM_CODE)
Dem_ReadDataOfFreezeFrame(
  Dem_EventRelatedDataPCType EvData,   
  Dem_DTCOriginType DTCOrigin,
  Dem_RecordNumberType RecordNumber,
  boolean ReportTotalDid,
  Dem_DataIdentifierType DataIdentifier,
  Dem_FFBufferFormatType HeaderType,
  P2VAR(uint8, AUTOMATIC, DEM_VAR) DestBuffer,
  P2VAR(uint16, AUTOMATIC, DEM_VAR) BufSize);


#if ((DEM_OBD_SUPPORT == STD_ON) && (DEM_MAX_NUMBER_OF_PID_RECDS > DEM_ZERO))
extern FUNC(Std_ReturnType, DEM_CODE) 
Dem_GetReadDataOfPID(
  P2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_CONST)entry,
  P2VAR(uint8, AUTOMATIC, DEM_VAR)DestBuffer,
  boolean ReportTotalRecord, 
  Dem_PidIdentifierType PidIdentifier,
  boolean ReportTotalDataElement,
  Dem_NumOfDataElementClassType DataElementIndexOfPID);
#endif

extern FUNC(Dem_SizeOfExtendedDataClassType, DEM_CODE)
Dem_GetSizeOfExtendedData(
  Dem_ExtendedDataClassPCType EDClass,
  const Dem_ExtendedDataNumberType ExtendedDataNumber,
  P2VAR(Dem_NumOfExtendedDataRecordClassType, AUTOMATIC, DEM_VAR) NumOfMatchedEDR);

/**************************************************/
#define DEM_STOP_SEC_CODE
#include "MemMap.h"
/*************************************************/


#endif

