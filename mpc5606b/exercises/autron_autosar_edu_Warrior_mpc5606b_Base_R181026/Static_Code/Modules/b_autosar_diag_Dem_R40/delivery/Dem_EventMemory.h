/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_EventMemory.h                                             **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Event Manager                              **
**                                                                            **
**  PURPOSE   : C header for Dem_EventMemory.c                                **
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
** 1.4.0    16-11-2016      YoungJin.Yun  Changes made As per Redmine #6549,  **
**                                        #6188                               **
**                                                                            **
** 1.3.0    30-08-2016      YoungJin.Yun  Changes made As per Redmine #5011   **
**                                                                            **
** 1.2.0    16-06-2016      YoungJin.Yun  Changes made As per Redmine #1164,  **
**                                        #4901                               **
**                                                                            **
** 1.0.0    07-02-2015      YoungJin.Yun  Initial Version                     **
*******************************************************************************/


#ifndef DEM_EVENTMEMORY_H
#define DEM_EVENTMEMORY_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem_PCTypes.h"
#include "Dem_Ram.h"

/*******************************************************************************
**                      Extern function definition                            **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(Dem_UdsStatusByteType, DEM_CODE) Dem_EvMem_GetUdsStatusByteToNvData(
 const Dem_EventIdType EventId,
 const Dem_DTCOriginType DTCOrigin);

extern FUNC(void, DEM_CODE) Dem_EvMem_SetUdsStatusByteToNvData(
  const Dem_EventIdType EventId);
    
extern FUNC(void, DEM_CODE) Dem_EvMem_VerifyAllEventMemories(void);

extern FUNC(uint8, DEM_CODE) 
Dem_EvMem_TriggerNvDataStorage(
  const Dem_EventIdType EventId,
  const Dem_DTCOriginType DTCOrigin,
  const Dem_UdsStatusByteType EventStatusByteOld,
  uint8 NvDataBlkStatus,
  boolean EvMemEntryIsDirty,
  boolean EvStatusIsDirty);

extern FUNC(void, DEM_CODE) Dem_EvMem_Init(void);

extern FUNC(uint32, DEM_CODE) Dem_EvMem_GetTimeStamp(
  Dem_EventMemoryEntryPtrType entry);

extern FUNC(uint8, DEM_CODE) Dem_EvMem_EventIsImmediateStorage(
  Dem_DTCOriginType DTCOrigin,  
  Dem_EventIdType EventId);
  
extern FUNC(boolean, DEM_CODE) Dem_EvMem_SetFirstLastFailedDtc(
  Dem_DTCOriginType DTCOrigin, 
  Dem_DTCType DTC);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_EvMem_ProcessEventRetention(
  Dem_EventIdType EventId, 
  Dem_DTCOriginType DTCOrigin,  
  const Dem_UdsStatusByteType EventStatusByteOld,
  #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_TYPE1)  
  const Dem_UdsStatusByteType DTCStatusOld,
  #endif
  #if ((DEM_SIZE_OF_EVENT_DATA > 0U) || (DEM_DCM_RPT_FAILEDCONFIRMEDDTCINFO_USED == STD_ON)) 
  Dem_DTCType DTC,
  #endif  
  P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA)  EventDirty,
  P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA)  StatusDirty);

#if (DEM_EVMEM_TIMESTAMP_USED == STD_ON)
extern FUNC(uint32, DEM_CODE) Dem_EvMem_FindNewTimeStamp(Dem_DTCOriginType DTCOrigin);
#endif

extern FUNC(void, DEM_CODE) Dem_EvMem_AddMemLocInEvMemMap(
  Dem_EventIdType EventId,
  Dem_DTCOriginType DTCOrigin,
  Dem_NumOfEventMemoryEntryType MemLocation);

extern FUNC(void, DEM_CODE) Dem_EvMem_ClearMemLocInEvMemMap(
  Dem_EventIdType EventId,
  Dem_DTCOriginType DTCOrigin  
  #if (DEM_EVMEM_TIMESTAMP_USED == STD_ON)  
  ,Dem_EventMemoryEntryPtrType EvMemEt
  #endif
);


extern FUNC(Dem_EventMemoryEntryPtrType, DEM_CODE) Dem_EvMem_FindEntry(
  Dem_EventIdType EventId,
  Dem_DTCOriginType DTCOrigin);

#if (DEM_EVENT_DISPLACEMENT_SUPPORT == STD_ON)
extern FUNC(Dem_NumOfEventMemoryEntryType, DEM_CODE)
Dem_EvMem_FindEntryWithLowestPriority(
  Dem_EventIdType EventId,
  Dem_EventPriorityType PriorityOfNewEvent,
  Dem_DTCOriginType DTCOrigin);
#endif


extern FUNC(boolean, DEM_CODE)
  Dem_EvMem_ClearDTCOccurrenceTime(const Dem_DTCType DTC, boolean AllDTCs);

FUNC(boolean, DEM_CODE) Dem_EvMem_TriggerImmediateStorage(
  const Dem_EventMemoryEntryPtrType EvMemEntry);

extern FUNC(boolean, DEM_CODE) Dem_EvMem_SetEvMemOverflowFlag(
  Dem_DTCOriginType DTCOrigin, 
  boolean state);

extern FUNC(void, DEM_CODE) Dem_EvMem_AgingEvMemEntry(
  Dem_EventIdType EventId,
  Dem_DTCOriginType DTCOrigin,  
  Dem_EventMemoryEntryPtrType EvMemEntry);

extern FUNC(void, DEM_CODE) Dem_EvMem_PreInit(void);


extern FUNC(void, DEM_CODE) Dem_EvMem_MainFunctionClearDtc(void);

extern FUNC(void, DEM_CODE) Dem_EvMem_RequestWriteAllBlocks(void);

extern FUNC(void, DEM_CODE) Dem_EvMem_RequestReadAllBlocks(void);

extern FUNC(void, DEM_CODE) Dem_EvMem_TriggerWriteAllBlocks(void);

extern FUNC(void, DEM_CODE) Dem_EvMem_MainFunctionReadAll(void);

extern FUNC(void, DEM_CODE) Dem_EvMem_MainFunctionWriteAll(void);

extern FUNC(void, DEM_CODE) Dem_EvMem_SetTimeStamp( Dem_EventMemoryEntryPtrType entry, uint32 NewTimeStamp );

extern FUNC(boolean, DEM_CODE) Dem_EvMem_Lock(void);

#if(DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO)
FUNC(Dem_EventMemoryEntryPtrType, DEM_CODE) Dem_EvMem_GetEmEntryByMemPosition(
  const Dem_DTCOriginType DTCOrigin, 
  const Dem_NumOfEventMemoryEntryType MemLocation);

extern FUNC(Dem_EventIdType, DEM_CODE) Dem_EvMem_GetEventIdByEvMemEntry(
  const Dem_DTCOriginType DTCOrigin, 
  const Dem_NumOfEventMemoryEntryType MemLocation);

extern FUNC(void, DEM_CODE) Dem_EvMem_SetEventId(
  Dem_EventMemoryEntryPtrType EmEntry,
  Dem_EventIdType EventId);

extern FUNC(void, DEM_CODE) Dem_EvMem_ClearEventMemoryEntry
 (Dem_EventMemoryEntryPtrType EmEntry);

extern FUNC(void, DEM_CODE) Dem_EvMem_ResetManagementBlock(boolean SetfootPrintAsDefault);

extern FUNC(void, DEM_CODE) Dem_EvMem_ResetEventStatusNvRamBlock(void);

#if (DEM_SIZE_OF_EXTENDED_DATA > 0u)
extern FUNC(P2VAR(uint8, AUTOMATIC, DEM_VAR), DEM_CODE) Dem_EvMem_GetEDBuffer(
  Dem_EventRelatedDataCPCType EvData,
  Dem_EventMemoryEntryPtrType MemEntry,
  P2VAR(uint32, AUTOMATIC, DEM_VAR) BufSize);
#endif

#if (DEM_SIZE_OF_FREEZEFRAME > 0u)
extern  FUNC(P2VAR(uint8, AUTOMATIC, DEM_VAR), DEM_CODE) Dem_EvMem_GetFFBufferForWriting(
  const Dem_RecordNumberType  MaxLimit,
  Dem_EventMemoryEntryPtrType MemEntry,
  P2VAR(uint32, AUTOMATIC, DEM_VAR) BufSize);

extern FUNC(Dem_RecordNumberType, DEM_CODE) Dem_EvMem_GetRecNumOfFF(
  Dem_EventMemoryEntryCPCType entry);

#endif

extern FUNC(uint8*, DEM_CODE) 
Dem_EvMem_GetEventDataBuffer(Dem_EventMemoryEntryPtrType entry);

extern FUNC(boolean, DEM_CODE) Dem_EvMem_CheckFirstEcuRun(void);

extern FUNC(boolean, DEM_CODE) 
Dem_EvMem_DTCOriginIsValid(
  const Dem_DTCOriginType DTCOrigin);

extern FUNC(boolean, DEM_CODE) 
Dem_EvMem_SetOpCycleState(
  uint8 OperationCycleId,
  Dem_OperationCycleStateType state);

extern FUNC(void, DEM_CODE) 
Dem_EvMem_GetOpCycleState(
  uint8 OperationCycleId,
  P2VAR(Dem_OperationCycleStateType, AUTOMATIC, DEM_VAR) CycleState);


extern FUNC(boolean, DEM_CODE) 
Dem_EvMem_IncAgingCounter(
  Dem_EventMemoryEntryPtrType entry,
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) AgingCounter);

extern FUNC(uint8, DEM_CODE) 
Dem_EvMem_GetAgingCounter(
  Dem_EventMemoryEntryPtrType MemEntry);

extern FUNC(boolean, DEM_CODE) 
Dem_EvMem_SetAgingCounter(
  Dem_EventMemoryEntryPtrType entry,
  uint8 AgingCounter);

extern FUNC(Dem_EventIdType, DEM_CODE) 
Dem_EvMem_FaultConfirmation(
  Dem_EventIdType EventId, 
  Dem_DTCOriginType DTCOrigin,
  #if (DEM_NUM_OF_ENABLE_TRIP_COUNTER > 1U)
  uint8 EventFailureThreshold,
  #endif
  P2VAR (boolean, AUTOMATIC, DEM_APPL_DATA) EventDirty);

extern FUNC(boolean, DEM_CODE) 
Dem_EvMem_SetFailureCounter(
  Dem_EventMemoryEntryPtrType entry,
  uint8 FailureCounter);

FUNC(uint8, DEM_CODE) 
Dem_EvMem_GetFailureCounter(
  Dem_EventMemoryEntryPtrType entry);


extern FUNC(boolean, DEM_CODE) 
Dem_EvMem_IncEventOccCounter(
  Dem_EventMemoryEntryPtrType entry);

extern FUNC(Dem_EventOccurrenceType, DEM_CODE) 
Dem_EvMem_GetEventOccCounter(
  Dem_EventMemoryEntryPtrType MemEntry);

extern FUNC(uint8, DEM_CODE) 
Dem_EvMem_SetEventOccCounter(
  Dem_EventMemoryEntryPtrType entry,
  Dem_EventOccurrenceType OccurrenceCounter);

extern FUNC(boolean, DEM_CODE) Dem_EvMem_GetEvMemOverflowFlag(
  Dem_DTCOriginType DTCOrigin);

extern FUNC(Std_ReturnType, DEM_CODE)
Dem_EvMem_GetDTCByOccurrenceTime(
  Dem_DTCRequestType ReqType, 
  P2VAR (uint32, AUTOMATIC, DEM_APPL_DATA) DTC);

extern FUNC(boolean, DEM_CODE) 
Dem_EvMem_GetIndicatorAttStatus(
  const Dem_EventIdType EventId,
  const Dem_NumOfIndicatorAttributeType IndicatorAttrId);
  
extern FUNC(boolean, DEM_CODE) 
Dem_EvMem_SetIndicatorAttStatus(
  const Dem_EventIdType EventId,
  const Dem_NumOfIndicatorAttributeType IndicatorAttrId,
  const boolean AttStatus);

extern FUNC(boolean, DEM_CODE) 
Dem_EvMem_SetIndicatorFailureCounter(
  const Dem_NumOfIndicatorAttributeType FailureCounterId,
  const uint8 FailureCounter);

extern FUNC(boolean, DEM_CODE) 
Dem_EvMem_SetIndicatorHealingCounter(
  const Dem_NumOfIndicatorAttributeType HealingCounterId,
  const uint8 HealingCounter);

extern FUNC(boolean, DEM_CODE) Dem_EvMem_IncreaseIndicatorFailureCounter(
  const Dem_NumOfIndicatorAttributeType FailureCounterId,
  P2VAR(uint8, AUTOMATIC, DEM_VAR) CounterValue);

extern FUNC(boolean, DEM_CODE) Dem_EvMem_IncreaseIndicatorHealingCounter(
  const Dem_NumOfIndicatorAttributeType HealingCounterId,
  P2VAR(uint8, AUTOMATIC, DEM_VAR) CounterValue);

#endif /* DEM_MAX_EVENT_DESTINATION_SELECTED */

/**************************************************
 *   Static Function Prototype Declaration
 **************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:No action planned> inline-MISRA C:2012 permits the use of inline functions in header files */
/* polyspace:begin<MISRA-C:8.1:Not a defect:No action planned> inline-MISRA C:2012 permits the use of inline functions in header files */
/* polyspace:begin<MISRA-C:8.5:Not a defect:No action planned> inline-MISRA C:2012 permits the use of inline functions in header files */ 
static DEM_INLINE FUNC(void, DEM_CODE) Dem_EvMem_SetNvmResult(Std_ReturnType NvmResult)
{
  Dem_EvMemTrigger.nvmResult = NvmResult;
}

static DEM_INLINE FUNC(Std_ReturnType, DEM_CODE) Dem_EvMem_GetNvmResult(void)
{
  return Dem_EvMemTrigger.nvmResult;
}

static DEM_INLINE FUNC(void, DEM_CODE) Dem_EvMem_SetReadNvDataTrigger(boolean TriggerState)
{
  Dem_EvMemTrigger.readNvBlocksTrigger = TriggerState;
}

static DEM_INLINE FUNC(void, DEM_CODE) Dem_EvMem_SetWriteNvDataTrigger(boolean TriggerState)
{
  Dem_EvMemTrigger.writeNvBlocksTrigger = TriggerState;
}


static DEM_INLINE FUNC(void, DEM_CODE) Dem_EvMem_SetWriteNvDataEndModeTrigger(boolean TriggerState)
{
  Dem_EvMemTrigger.writeNvBlocksEndModeTrigger = TriggerState;
}


static DEM_INLINE FUNC(void, DEM_CODE) Dem_EvMem_SetWaitNvmFinishJobTrigger(boolean TriggerState)
{
  Dem_EvMemTrigger.waitNvBlocksJobFinishTrigger = TriggerState;
}

static DEM_INLINE FUNC(boolean, DEM_CODE) Dem_EvMem_ReadNvDataIsTriggered(void)
{
  return Dem_EvMemTrigger.readNvBlocksTrigger;
}

static DEM_INLINE FUNC(boolean, DEM_CODE) Dem_EvMem_WriteNvDataIsTriggered(void)
{
  return Dem_EvMemTrigger.writeNvBlocksTrigger;
}

static DEM_INLINE FUNC(uint8, DEM_CODE) Dem_EvMem_WriteNvDataEndModeTriggered(void)
{
  return Dem_EvMemTrigger.writeNvBlocksEndModeTrigger;
}

static DEM_INLINE FUNC(boolean, DEM_CODE) Dem_NvmWaitFinishJobIsTrigger(void)
{
  return Dem_EvMemTrigger.waitNvBlocksJobFinishTrigger;
}

/*
 * Event memory entries's status
 */
static DEM_INLINE FUNC(boolean , DEM_CODE) Dem_EvMem_IsEvMemNvBlockStatusFilter(
  const Dem_DTCOriginType DTCOrigin, 
  const Dem_NumOfEventMemoryEntryType MemLocation,
  const uint8 Filter)
{
  boolean matchFilter;
  CONSTP2VAR(uint8, AUTOMATIC, DEM_CONST) evMemStatus = Dem_EventMemoryState[DTCOrigin];
  if ((evMemStatus[MemLocation] & Filter) == Filter)
  {
    matchFilter = DEM_TRUE;
  }
  else
  {
    matchFilter = DEM_FALSE;
  }
  return matchFilter;  
}

/* NOTE: DTCOrigin , DTCOrigin shall be verified by caller */
static DEM_INLINE FUNC(void , DEM_CODE) Dem_EvMem_SetEvMemNvBlockStatus(
   Dem_DTCOriginType DTCOrigin,  
   Dem_NumOfEventMemoryEntryType MemLocation,
   uint8 EvMemStatus)
{
  CONSTP2VAR(uint8, AUTOMATIC, DEM_CONST) evMemStatusList = Dem_EventMemoryState[DTCOrigin];

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (NULL_PTR != evMemStatusList)
  #endif  
  {
    evMemStatusList[MemLocation] |= EvMemStatus; 
  }
}

/* NOTE: DTCOrigin , DTCOrigin shall be verified by caller */
static DEM_INLINE FUNC(void , DEM_CODE) Dem_EvMem_InitEvMemNvBlockStatus(
  const Dem_DTCOriginType DTCOrigin,  
  const Dem_NumOfEventMemoryEntryType MemLocation,
  const uint8 EvMemStatus)
{
  CONSTP2VAR(uint8, AUTOMATIC, DEM_CONST) evMemStatusList = Dem_EventMemoryState[DTCOrigin];
  evMemStatusList[MemLocation] = EvMemStatus;
}

/* NOTE: DTCOrigin , DTCOrigin shall be verified by caller */
static DEM_INLINE FUNC(void , DEM_CODE) Dem_EvMem_ClearEvMemNvBlockStatus(
  const Dem_DTCOriginType DTCOrigin,  
  const Dem_NumOfEventMemoryEntryType MemLocation,
  const uint8 EvMemStatus)
{
  CONSTP2VAR(uint8, AUTOMATIC, DEM_CONST) evMemStatusList = Dem_EventMemoryState[DTCOrigin];
  evMemStatusList[MemLocation] = evMemStatusList[MemLocation] & ((uint8)(~EvMemStatus));
}

/*
 * Non-volatile data's status
 */

static DEM_INLINE FUNC(boolean , DEM_CODE) 
Dem_EvMem_NonVolatieDataStatusFilter(
  const Dem_NvDataIdType NvDataId,  
  const uint8 Filter)
{
  boolean matchFilter;
  if ((Dem_NonVolatileDataState[NvDataId] & Filter) == Filter)
  {
    matchFilter = DEM_TRUE;
  }
  else
  {
    matchFilter = DEM_FALSE;
  }
  return matchFilter;
}

/* NOTE: DTCOrigin , DTCOrigin shall be verified by caller */
static DEM_INLINE FUNC(void , DEM_CODE) Dem_EvMem_SetNonVolatieDataStatus(
  const Dem_NvDataIdType NvDataId,  
  const uint8 EvMemStatus)
{
  Dem_NonVolatileDataState[NvDataId] |= EvMemStatus;
}

/* NOTE: DTCOrigin , DTCOrigin shall be verified by caller */
static DEM_INLINE FUNC(void , DEM_CODE) Dem_EvMem_InitNonVolatieDataStatus(
  const Dem_NvDataIdType NvDataId,  
  const uint8 EvMemStatus)
{
  Dem_NonVolatileDataState[NvDataId] = EvMemStatus;
}

/* NOTE: DTCOrigin , DTCOrigin shall be verified by caller */
static DEM_INLINE FUNC(void , DEM_CODE) Dem_EvMem_ClearNonVolatieDataStatus(
  const Dem_NvDataIdType NvDataId,  
  const uint8 EvMemStatus)
{
  Dem_NonVolatileDataState[NvDataId] &= (uint8)(~EvMemStatus);
}

static DEM_INLINE FUNC(boolean, DEM_CODE) Dem_EvMem_WaitClearAllBlocks(
  P2VAR(Dem_ReturnClearDTCType, AUTOMATIC,DEM_VAR) ClearDtcReturnValue)
{  
  boolean retVal;
  
  #if (DEM_CLEAR_DTC_BEHAVIOUR == DEM_CLRRESP_NONVOLATILE_FINISH)   
  retVal = Dem_NvmWaitFinishJobIsTrigger();
  if (DEM_FALSE == retVal)
  {
    if (E_NOT_OK == Dem_EvMem_GetNvmResult())
    {
      *ClearDtcReturnValue = DEM_CLEAR_FAILED;
    }
    else
    {
      *ClearDtcReturnValue = DEM_CLEAR_OK;
    }
  }
  #elif  (DEM_CLEAR_DTC_BEHAVIOUR == DEM_CLRRESP_NONVOLATILE_TRIGGER)
  retVal = Dem_EvMem_WriteNvDataIsTriggered();  
  if (DEM_FALSE == retVal)
  {
    /* Don't care return value of NvM */
    *ClearDtcReturnValue = DEM_CLEAR_OK;
  }
  #else
  {
    /* Don't care return value of NvM */
    *ClearDtcReturnValue = DEM_CLEAR_OK;
    retVal = DEM_FALSE;
  }
  #endif    

  return retVal;
}

/* polyspace:end<MISRA-C:1.1:Not a defect:No action planned> inline-MISRA C:2012 permits the use of inline functions in header files */
/* polyspace:end<MISRA-C:8.1:Not a defect:No action planned> inline-MISRA C:2012 permits the use of inline functions in header files */
/* polyspace:end<MISRA-C:8.5:Not a defect:No action planned> inline-MISRA C:2012 permits the use of inline functions in header files */

/**************************************************/
#define DEM_STOP_SEC_CODE
#include "MemMap.h"
/*************************************************/

#endif

