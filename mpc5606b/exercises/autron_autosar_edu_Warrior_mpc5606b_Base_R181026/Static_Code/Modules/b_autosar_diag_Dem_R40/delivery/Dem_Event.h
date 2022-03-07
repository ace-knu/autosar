/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_Event.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Event Manager                              **
**                                                                            **
**  PURPOSE   : C header for Dem_Event.c                                      **
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
** 1.0.1    10-06-2016      YoungJin.Yun  Changes made As per Redmine #5169   **
**                                                                            **
** 1.0.0    07-02-2015      YoungJin.Yun  Initial Version                     **
*******************************************************************************/

#ifndef DEM_EVENT_H
#define DEM_EVENT_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem_PCTypes.h"
#include "SchM_Dem.h"

#define DEM_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                  Extern Function Definition                                **
*******************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) 
Dem_GetEventConditionsAndControlDTCSetting(Dem_EventIdType EventId);


extern FUNC(Std_ReturnType, DEM_CODE) Dem_ProcessEventStatus(
  Dem_EventIdType EventId, Dem_EventStatusType EventStatus);

#if (DEM_BSW_ERROR_BUFFER_SIZE > 0U) 
extern FUNC(void, DEM_CODE) Dem_MainfunctionBswEvents(void);
#endif


extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventDTCOrigin(
  Dem_EventParameterCPCType event,
  P2VAR(Dem_DTCOriginType, AUTOMATIC, DEM_VAR) DTCOrigin
  /*,P2VAR(boolean, AUTOMATIC, DEM_VAR) MirrorExist */);    


extern FUNC(boolean, DEM_CODE) Dem_DTCOriginBelongToEvent(
  Dem_EventIdType EventId,
  Dem_DTCOriginType DTCOrigin);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetOpCycleStateByEvent(
  Dem_EventIdType EventId,
  P2VAR(Dem_OperationCycleStateType, AUTOMATIC, DEM_VAR) CycleState);  

extern FUNC(Dem_TestResultType, DEM_CODE) Dem_GetTestResultThisOperation(
    Dem_EventIdType EventId, 
    Dem_UdsStatusByteType EventStatusByte, 
    boolean RequireTestedCycle);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventDTC(
  Dem_EventParameterCPCType event,
  P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA) DTC);

extern FUNC(Dem_EventIdType, DEM_CODE) Dem_GetEventIdByDTC(
  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  uint8 ApiId,
  #endif
  const Dem_DTCType DTC);

extern FUNC(void, DEM_CODE) Dem_InitBswEventQueue(void);

/*******************************************************************************
**                  Inline Function Definition                                **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:No action planned> inline-MISRA C:2012 permits the use of inline functions in header files */
/* polyspace:begin<MISRA-C:8.1:Not a defect:No action planned> inline-MISRA C:2012 permits the use of inline functions in header files */
/* polyspace:begin<MISRA-C:8.5:Not a defect:No action planned> inline-MISRA C:2012 permits the use of inline functions in header files */

static DEM_INLINE FUNC(boolean, DEM_CODE) Dem_EventIdIsValid(Dem_EventIdType EventId)
{
  boolean valid;
  if ((EventId <= Dem_Number_Of_Events) && (DEM_NO_EVENT != EventId))
  {
    valid = DEM_TRUE;    
  }
  else
  /* polyspace<RTE:UNR:Not a defect:No action planned> If-condition evaluates to true or false according to configuration */
  {
    valid = DEM_FALSE;
  }
  return valid;
}

static DEM_INLINE FUNC(DemEventKindType, DEM_CODE) Dem_GetEventKind(Dem_EventIdType EventId)
{
  return DEM_GET_EVENTPARAM_EVENT_KIND(Dem_Event[EventId-1U].ParamFieldsA);
}


static DEM_INLINE FUNC(boolean, DEM_CODE) Dem_EventStatusIsValid(Dem_EventStatusType EventStatus)
{ 
  boolean valid;
  if (
    ( (EventStatus == (Dem_EventStatusType)DEM_EVENT_STATUS_PASSED) ||
      (EventStatus == (Dem_EventStatusType)DEM_EVENT_STATUS_FAILED))
    ||
    ((EventStatus == (Dem_EventStatusType)DEM_EVENT_STATUS_PREPASSED) ||
    (EventStatus == (Dem_EventStatusType)DEM_EVENT_STATUS_PREFAILED) ) 
  )
  {
    valid = DEM_TRUE;    
  }
  else
  {
    valid = DEM_FALSE;
  }

  return valid;
}

static DEM_INLINE FUNC(uint8, DEM_CODE)  Dem_SetBit8(uint8 Val, uint8 Position)
{
  uint8 mask = (uint8)(1U << Position);
  return Val | mask;
}

static DEM_INLINE FUNC(uint8, DEM_CODE)  Dem_ClearBit8(uint8 Val, uint8 Position)
{
  uint8 mask = (uint8)(1U << Position);
  return Val & ((uint8)~mask);
}

static DEM_INLINE FUNC(boolean, DEM_CODE)  Dem_IsBit8Set(uint8 Val, uint8 Position)
{
  boolean isSet;  
  /* polyspace<MISRA-C:21.1:Not a defect:Justify with annotations  a defect> Rule violation by runtime error(orange) of PolySpace */
  Val = (uint8)(Val >> Position);
  if ((uint8)(Val & (uint8)1U) != (uint8)0U)
  {
    isSet = DEM_TRUE;
  }
  else
  {
    isSet = DEM_FALSE;
  }
  return isSet;
}

static DEM_INLINE FUNC(void, DEM_CODE) Dem_EvSetProcState(Dem_EventIdType EventId, uint8 ProcessState)
{
  Dem_EventState[EventId] = (uint8)Dem_SetBit8((uint8)Dem_EventState[EventId], (uint8)ProcessState);
}

static DEM_INLINE FUNC(boolean, DEM_CODE) Dem_EvIsProcStateTriggered(Dem_EventIdType EventId, uint8 ProcessState)
{
  return Dem_IsBit8Set((uint8)Dem_EventState[EventId], (uint8)ProcessState);
}

static DEM_INLINE FUNC(void, DEM_CODE) Dem_EvClearProcState(Dem_EventIdType EventId, uint8 ProcessState)
{
  Dem_EventState[EventId] = (uint8)Dem_ClearBit8((uint8)Dem_EventState[EventId], (uint8)ProcessState);
}

static DEM_INLINE FUNC(void, DEM_CODE) Dem_EvInitProcState(Dem_EventIdType EventId)
{
  Dem_EventState[EventId] = 0x00;
}

static DEM_INLINE FUNC(Dem_EventIdType, DEM_CODE) Dem_GetFirstEventOfDTC(Dem_CombinedDtcPCType DTCClass)
{
  Dem_EventIdType firstEventId = DEM_NO_EVENT;
  /* polyspace<RTE:UNR:Not a defect:No action planned> If-condition always evaluates to true */  
  if (DTCClass->dtc_PointToEventList < Dem_Max_ListOfCombinedEvents)
  {
    Dem_EventIdType eventId = Dem_ListOfCombinedEvents[DTCClass->dtc_PointToEventList];    
    /* polyspace<RTE:UNR:Not a defect:No action planned> If-condition always evaluates to true */  
    if (DEM_TRUE == Dem_EventIdIsValid(eventId))
    {
      firstEventId = eventId;
    }
  }

  return firstEventId;
}

static DEM_INLINE FUNC(boolean, DEM_CODE) Dem_EventHasDtc(Dem_EventIdType EventId)
{
  boolean valid;
  if (Dem_Event[EventId - 1U].e_PointToDTC < Dem_Max_Number_Of_DTC)
  {
    valid = DEM_TRUE;    
  }
  else
  {
    valid = DEM_FALSE;
  }
  return valid;
}

static DEM_INLINE FUNC(boolean, DEM_CODE) Dem_GetLockByEventId(
  const Dem_EventIdType EventId)
{
  boolean lock;

  SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
  if (DEM_TRUE == Dem_EvIsProcStateTriggered(EventId, DEM_EVPROCSTATE_EVENT_LOCK))
  { 
    lock = DEM_FALSE;
  }
  else
  {
    lock = DEM_TRUE;
    Dem_EvSetProcState(EventId, DEM_EVPROCSTATE_EVENT_LOCK);   
  }
  
  SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();  

  return lock;
}

static DEM_INLINE FUNC(boolean, DEM_CODE) Dem_GetLocksByEventIdAndEvMem(
  const Dem_EventIdType EventId)
{
  boolean lock;

  SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();

  if (DEM_CLEARDTC_STATE_READY == Dem_ClearDtcState.cds_State)
  {
    if (DEM_TRUE == Dem_EvIsProcStateTriggered(EventId, DEM_EVPROCSTATE_EVENT_LOCK))
    { 
      lock = DEM_FALSE;
    }
    else
    {
      lock = DEM_TRUE;
      Dem_EvSetProcState(EventId, DEM_EVPROCSTATE_EVENT_LOCK);   
    }
  }
  else
  {
    lock = DEM_FALSE;
  }
  
  SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();  

  return lock;
}


static DEM_INLINE FUNC(void, DEM_CODE) Dem_FreeLockByEventId(
  const Dem_EventIdType EventId)
{
  SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
  Dem_EvClearProcState(EventId, DEM_EVPROCSTATE_EVENT_LOCK);      
  SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();  
}

/* polyspace:end<MISRA-C:8.5:Not a defect:No action planned> inline-MISRA C:2012 permits the use of inline functions in header files */
/* polyspace:end<MISRA-C:8.1:Not a defect:No action planned> inline-MISRA C:2012 permits the use of inline functions in header files */
/* polyspace:end<MISRA-C:1.1:Not a defect:No action planned> inline-MISRA C:2012 permits the use of inline functions in header files */


/**************************************************/
#define DEM_STOP_SEC_CODE
#include "MemMap.h"
/*************************************************/

#endif

     

