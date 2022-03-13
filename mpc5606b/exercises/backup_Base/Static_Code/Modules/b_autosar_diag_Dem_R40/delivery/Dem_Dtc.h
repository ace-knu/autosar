/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_Dtc.h                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Event Manager                              **
**                                                                            **
**  PURPOSE   : C header for Dem_Dtc.c                                        **
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
** 1.1.1    15-02-2017      YoungJin.Yun  Changes made As per Redmine #7379   **
**                                                                            **
** 1.1.0    30-08-2016      YoungJin.Yun  Changes made As per Redmine #5011   **
**                                                                            **
** 1.0.1    16-04-2016      Youngjin Yun  Changes made As per Redmine #1164   **
**                                                                            **
** 1.0.0    06-11-2015      Autron        Initial Version                     ** 
*******************************************************************************/

#ifndef DEM_DTC_H
#define DEM_DTC_H
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

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetConditionOfDTCRecordUpdate(
  const Dem_DTCType DTC,
  const Dem_DTCOriginType DTCOrigin);

extern FUNC(void, DEM_CODE) Dem_CountAndStoreFilterDtc(void);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCGroupId(
  Dem_DTCGroupType DTCGroup,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCGroupId);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_ClearSingleDTCStatusByte(
  Dem_CombinedDtcPCType CbDTC,  
  Dem_DTCOriginType DTCOrigin);

extern FUNC(Dem_UdsStatusByteType, DEM_CODE) Dem_GetDTCStatus(
  Dem_EventIdType EventId);

extern FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_InternalClearDTC(uint32 DTC,
  Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin);
  

/* polyspace:begin<MISRA-C:1.1:Not a defect:No action planned> inline-MISRA C:2012 permits the use of inline functions in header files */
/* polyspace:begin<MISRA-C:8.1:Not a defect:No action planned> inline-MISRA C:2012 permits the use of inline functions in header files */
/* polyspace:begin<MISRA-C:8.5:Not a defect:No action planned> inline-MISRA C:2012 permits the use of inline functions in header files */

static DEM_INLINE FUNC(Dem_CombinedDtcPCType, DEM_CODE) Dem_GetCbDTCByEventId(Dem_EventIdType EventId)
{
  Dem_CombinedDtcPCType cbDTC;

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* polyspace<RTE:UNR:Not a defect:No action planned> If-condition always evaluates to false. */  
  if ((EventId > Dem_Number_Of_Events) || (DEM_NO_EVENT == EventId))
  /* polyspace<RTE:UNR:Not a defect:No action planned> If-condition always evaluates to false. */    
  {
    cbDTC = NULL_PTR;
  }  
  else
  #endif
  {    
    uint16 pos = Dem_Event[EventId - 1U].e_PointToDTC;
    if (pos < Dem_Max_Number_Of_DTC) 
    {
      cbDTC = &Dem_GaaCombinedDtc[pos];
    }
    else
    {
      cbDTC = NULL_PTR;
    }
  }
  
  return cbDTC;
}


static DEM_INLINE FUNC(boolean, DEM_CODE) Dem_DTCFormatIsValid(
  Dem_EventIdType EventId, 
  Dem_DTCFormatType DTCFormat)
{
  boolean valid = DEM_FALSE;
  Dem_CombinedDtcPCType cbDTC = Dem_GetCbDTCByEventId(EventId);
  if (NULL_PTR != cbDTC)
  {
    if (cbDTC->ddDtcFormat == DTCFormat)
    {
      valid = DEM_TRUE;
    }
  }     
  return valid;
}

static DEM_INLINE  FUNC(Dem_CombinedDtcPCType , DEM_CODE) Dem_GetDtcByDtcId(
  const uint32 DTC)
{
  P2CONST(Dem_CombinedDtcType, AUTOMATIC,  DEM_VAR) cbDTC = NULL_PTR;
  uint16 dtcLoc;
  uint32 dtcVal;  
  
  for (dtcLoc = 0U; dtcLoc < Dem_Max_Number_Of_DTC; dtcLoc++)
  {     
    #if(DEM_OBD_SUPPORT == STD_ON)    
    if(Dem_GaaCombinedDtc[dtcLoc].ddDtcFormat != DEM_DTC_FORMAT_UDS)
    {
       /* Making DTC lowByte to zero for OBD DTC */
      dtcVal = Dem_GaaCombinedDtc[dtcLoc].usObdDtc << 8U ;
    }
    else
    #endif
    {
      dtcVal = Dem_GaaCombinedDtc[dtcLoc].ulUdsDtc;
    }
      
    if (dtcVal == DTC)
    {
      cbDTC = &Dem_GaaCombinedDtc[dtcLoc];      
    }
  }
  
  return cbDTC;
}

static DEM_INLINE FUNC(Dem_NumOfEventIdType, DEM_CODE) Dem_GetStartEventIdMapOfCbDTC(Dem_CombinedDtcPCType CombinedDTC)
{
  return CombinedDTC->dtc_PointToEventList;
}

static DEM_INLINE FUNC(Dem_EventIdType, DEM_CODE) Dem_GetEventIdByEventIdMapOfCbDTC(Dem_NumOfEventIdType EventIdMapIdx)
{
  return Dem_ListOfCombinedEvents[EventIdMapIdx];
}

static DEM_INLINE FUNC(Dem_NumOfEventIdType, DEM_CODE) Dem_GetEndEventIdMapOfCbDTC(Dem_CombinedDtcPCType CombinedDTC)
{
  Dem_NumOfEventIdType endPos = CombinedDTC->dtc_PointToEventList + CombinedDTC->ddNumberOfEvents;    
  if (endPos > Dem_Max_ListOfCombinedEvents)
  /* polyspace<RTE:UNR:Not a defect:No action planned> The block is only partially unreachable. */     
  {
    endPos = 0U;
  }
  return endPos;
}

static DEM_INLINE FUNC(Dem_DTCType, DEM_CODE) Dem_GetDtcByCombineDTC(
  P2CONST(Dem_CombinedDtcType, AUTOMATIC, DEM_CONST) cbDTC)
{
  Dem_DTCType DTC;
  #if(DEM_OBD_SUPPORT == STD_ON)
  if (cbDTC->ddDtcFormat != DEM_DTC_FORMAT_UDS)
  {
     /* Making DTC lowByte to zero for OBD DTC */
    DTC = (uint32)cbDTC->usObdDtc << 8U ;
  }
  else
  #endif
  {
    DTC = cbDTC->ulUdsDtc;
  }

  return DTC;
}


static DEM_INLINE FUNC(Dem_DTCType, DEM_CODE) Dem_GetDTCValue(
  const Dem_EventIdType EventId,
  const Dem_DTCFormatType DTCFormat)
{
  Dem_DTCType DTC = DEM_NO_DTC;

  uint16 dtcLoc = Dem_Event[EventId - 1U].e_PointToDTC;
  if (dtcLoc < Dem_Max_Number_Of_DTC) 
  {
    #if(DEM_OBD_SUPPORT == STD_ON)
    if (DTCFormat == DEM_DTC_FORMAT_OBD)
    {
       /* Making DTC lowByte to zero for OBD DTC */
      DTC = (uint32)Dem_GaaCombinedDtc[dtcLoc].usObdDtc << 8U ;
    }
    else
    #endif
    #if (DEM_J1939_SUPPORT == STD_ON)    
    if (DTCFormat == DEM_DTC_FORMAT_J1939)
    {
      DTC = Dem_GaaCombinedDtc[dtcLoc].J1939DTCValue;
    }
    else
    #endif    
    /* DEM_DTC_FORMAT_UDS */
    {
      DTC = Dem_GaaCombinedDtc[dtcLoc].ulUdsDtc;
    }
  }

  return DTC;
}

/* polyspace:end<MISRA-C:8.5:Not a defect:No action planned> inline-MISRA C:2012 permits the use of inline functions in header files */
/* polyspace:end<MISRA-C:8.1:Not a defect:No action planned> inline-MISRA C:2012 permits the use of inline functions in header files */
/* polyspace:end<MISRA-C:1.1:Not a defect:No action planned> inline-MISRA C:2012 permits the use of inline functions in header files */

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DEM_DTC_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/


