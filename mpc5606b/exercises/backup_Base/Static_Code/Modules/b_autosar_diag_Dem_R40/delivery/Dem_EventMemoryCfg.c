/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_EventMemoryCfg.c                                          **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostics Event Manager Module                      **
**                                                                            **
**  PURPOSE   : Provides the interface of varialble data that are configurable**
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision Date:DD-MM-YYYY By            Description                         **
********************************************************************************
** 1.5.4    31-08-2017    EunKyung.Kim    Changes made As per Redmine #9551   **
**                                                                            **
** 1.5.3    20-07-2017    EunKyung.Kim    Changes made As per Redmine #9294   **
**                                                                            **
** 1.5.2    31-05-2017    EunKyung.Kim    Changes made As per Redmine #8166   **
**                                                                            **
** 1.5.1    05-04-2017      YoungJin.Yun  Changes made As per Redmine #8049,  **
**                                        #8083                               **
**                                                                            **
** 1.5.1    09-03-2017      YoungJin.Yun  Changes made As per Redmine #6201,  **
**                                        #6425                               **
**                                                                            **
** 1.5.0    16-11-2016      YoungJin.Yun  Changes made As per Redmine #6549,  **
**                                                                            **
** 1.4.0    30-09-2016      YoungJin.Yun  Changes made As per Redmine #5991   **
**                                                                            **
** 1.3.0    30-08-2016      YoungJin.Yun  Changes made As per Redmine #5011   **
**                                                                            **
** 1.2.0    16-04-2016      Youngjin Yun  Changes made As per Redmine #1164   **
**                                                                            **
** 1.1.0    07-01-2016      YoungJin.Yun  Changes made As per Redmine #3353,  **
**                                        #3638,#2473,#3271,#2827,#1151, #2589**
**                                        #698                                **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem.h"        /* DEM module Header File */
#include "Dem_Ram.h"    /* DEM Ram Header File */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"        /* Det Module Header File */
#endif

#include "NvM.h"              /* NVRAM manager symbols Header File */

#include "SchM_Dem.h"   /* Basic s/w module Scheduler symbols Header File */
#include "Dem_Config.h"
#include "Dem_Dtc.h"
#include "Dem_Event.h"
#include "Dem_EventMemory.h"
#include "Dem_EventRelatedData.h"
#include "Dem_Indicator.h"
#include "Dem_Version.h"
#if (DEM_J1939_SUPPORT == STD_ON)
#include "Dem_J1939.h"
#endif




/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
 **                    Function Definitions                                   **
 ******************************************************************************/

#define DEM_START_SEC_CODE
#include "MemMap.h"

#if (DEM_DCM_RPT_FAILEDCONFIRMEDDTCINFO_USED == STD_ON)
static FUNC(boolean, DEM_CODE) Dem_EvMem_SetFirstLastConfirmedDTC(
  Dem_DTCOriginType DTCOrigin, 
  Dem_DTCType DTC);
#endif

#if (DEM_NVRAMBLOCK_ACCESS_OPTIMIZATION_SUPPORT == STD_ON)  
static FUNC(void, DEM_CODE) Dem_EvMem_SetUdsStatusByteToEvMemEntry(
  const Dem_EventIdType EventId,
  const Dem_DTCOriginType DTCOrigin,
  const Dem_NumOfEventMemoryEntryType memLoc);
#endif  
  


FUNC(void, DEM_CODE) Dem_EvMem_SetEventId(
  Dem_EventMemoryEntryPtrType EmEntry, 
  Dem_EventIdType EventId)
{
  EmEntry->EventIdRef = EventId;
}

FUNC(void, DEM_CODE) Dem_EvMem_ClearEventMemoryEntry( Dem_EventMemoryEntryPtrType EmEntry )
{
  #if (DEM_DEV_ERROR_DETECT == STD_ON)
   /* polyspace<RTE:UNR:Not a defect:No action planned> entry always is not null, but this is added to prevent the misra rule violation 21.1 */      
  if (NULL_PTR == EmEntry)
  {
    DEM_REPORT_ERROR(DEM_UNSPECIFIED_SID, DEM_E_PARAM_POINTER);
  }
  else
  #endif
  {
    uint32 i;
    #if (DEM_SIZE_OF_EVENT_DATA > 0u)    
    for (i = 0; i < DEM_SIZE_OF_EVENT_DATA; i++)
    {
      EmEntry->data[i] = DEM_SET_BYTE;
    }
    #if (DEM_SIZE_OF_FREEZEFRAME > 0u)
    /* Clear the number of FF captured */
    EmEntry->IndexOfFFRecords = 0u;
    #endif
    #endif
    
    SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
    /* Clear the event from memory */
    EmEntry->EventIdRef = DEM_NO_EVENT;  
    SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
  
    #if (DEM_NVRAMBLOCK_ACCESS_OPTIMIZATION_SUPPORT == STD_ON)
    for (i = 0; i < DEM_MAX_NUM_EVENTS_PER_DTC; i++)
    {
      EmEntry->EventStatuByte[i] = 0x0;
    }   
    #endif
    
    #if (DEM_EVMEM_TIMESTAMP_USED == STD_ON)
    EmEntry->TimeStamp = 0U;
    #endif
    
    /* Clear the Occurrence counter */
    /*entry->EventStatusMask = DEM_UDS_STATUS_TNCSLC | DEM_UDS_STATUS_TNCTOC; */
    EmEntry->EventOccurrenceCounter = 0u;

    #if (DEM_NUM_OF_ENABLE_TRIP_COUNTER > 1U)
    EmEntry->FailureCycleCounter = 0u;
    #endif
    
    #if (DEM_AGING_CYCLE_COUNTER_PROCESS == DEM_PROCESS_AGINGCTR_EXTERN)
    /* The first start of the Dem module, the aging cycle counter
        * shall be set to be unavailable (255)
        */
    EmEntry->AgingCycleCounter = DEM_EXTERN_COUNTER_MAX;
    #else
    EmEntry->AgingCycleCounter = 0u;
    #endif  
  }  
}


FUNC(Dem_EventMemoryEntryPtrType, DEM_CODE)
Dem_EvMem_GetEmEntryByMemPosition(
  const Dem_DTCOriginType DTCOrigin, 
  const Dem_NumOfEventMemoryEntryType MemLocation)
{  
#if 1
  Dem_EventMemoryEntryPtrType memEntry = NULL_PTR;;

  switch(DTCOrigin) {
  case DEM_DTC_ORIGIN_PRIMARY_MEMORY:
    /* if (MemLocation < Dem_SizeOfEventMemory[DTCOrigin]) */
    {
      memEntry = &Dem_PrimaryEventMemory[MemLocation];
    }
    break;
  #if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC > 0U)        
  case DEM_DTC_ORIGIN_SECONDARY_MEMORY:
    /* if (MemLocation < Dem_SizeOfEventMemory[DTCOrigin]) */
    {
      memEntry = &Dem_SecondaryEventMemory[MemLocation];
    }
    break;
  #endif
  /* polyspace<RTE:UNR:Not a defect:No action planned> Default switch clause is unreachable. switch-expression. */
  default:
    break;
  }  

  return memEntry;
#else  
  return &(((Dem_EventMemoryEntryPtrType)Dem_EventMemory[DTCOrigin])[MemLocation]);
#endif
}

FUNC(Dem_EventIdType, DEM_CODE) 
Dem_EvMem_GetEventIdByEvMemEntry(  
  const Dem_DTCOriginType DTCOrigin, 
  const Dem_NumOfEventMemoryEntryType MemLocation)
{
#if 1
  Dem_EventIdType eventId;

  switch(DTCOrigin) {
  case DEM_DTC_ORIGIN_PRIMARY_MEMORY:
    eventId = Dem_PrimaryEventMemory[MemLocation].EventIdRef;
    break;
  #if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC > 0U)    
  case DEM_DTC_ORIGIN_SECONDARY_MEMORY:
    eventId = Dem_SecondaryEventMemory[MemLocation].EventIdRef;
    break;    
  #endif
  /* polyspace<RTE:UNR:Not a defect:No action planned> Default switch clause is unreachable. switch-expression. */    
  default:
    eventId = DEM_NO_EVENT;
    break;
  }  

  return eventId;
#else
  return ((Dem_EventMemoryEntryPtrType)Dem_EventMemory[DTCOrigin])[MemLocation].EventIdRef;
#endif
}

#if(DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO)

#if (DEM_SIZE_OF_EXTENDED_DATA > 0u)
/*******************************************************************************
** Function Name        : Dem_EvMem_GetEDBuffer                           
**                                                                            
** Service ID           : None                                                
**                                                                            
** Description          : Get the buffer for extended data. 
**                                                                            
** Sync/Async           : Synchronous                                         
**                                                                            
** Re-entrancy          : Reentrant                                           
**                                                                            
** Input Parameters     : MaxLimit
**                                                                            
** InOut parameter      : entry
**                                                                            
** Output Parameters    : RecordIndex
**                                                                            
** Return parameter     : void
**                                                                            
** Preconditions        : None                                                
**                                                                            
** Remarks              : Global Variable(s)  :                               
**                        None
**                                                                            
**                        Function(s) invoked :                               
**                        None                                                
*******************************************************************************/
FUNC(P2VAR(uint8, AUTOMATIC, DEM_VAR), DEM_CODE) Dem_EvMem_GetEDBuffer(
  Dem_EventRelatedDataCPCType EvData,
  Dem_EventMemoryEntryPtrType MemEntry,
  P2VAR(uint32, AUTOMATIC, DEM_VAR) BufSize)
{
  P2VAR(uint8, AUTOMATIC, DEM_VAR) dst = NULL_PTR;
  uint32 offset = 0U;

  /* if Event has a FFClass , src shall be shifted */
  #if (DEM_SIZE_OF_FREEZEFRAME > 0u)  
  if (EvData->FFClassPos < Dem_Num_Of_FreezeFrameClass)
  {
    /* when FF exists, max freeze frame record is 2
     * Data format = [-FF0-|-FF1-| ED ] */
    offset = (uint32)EvData->MaxNumOfFreezeFrameRecords * (uint32)Dem_FreezeFrameClass[EvData->FFClassPos].size;
  }
  #endif
  /* RecordIndex starts from zero */ 
  dst = &MemEntry->data[offset];
  *BufSize = Dem_Size_Of_Event_Data - offset;

  return dst;
}
#endif




/*******************************************************************************
** Function Name        : Dem_EvMem_GetFFBufferForWriting                           
**                                                                            
** Service ID           : None                                                
**                                                                            
** Description          : Get the next index of the freeze frame records. 
**                                                                            
** Sync/Async           : Synchronous                                         
**                                                                            
** Re-entrancy          : Reentrant                                           
**                                                                            
** Input Parameters     : MaxLimit
**                                                                            
** InOut parameter      : entry
**                                                                            
** Output Parameters    : RecordIndex
**                                                                            
** Return parameter     : void
**                                                                            
** Preconditions        : None                                                
**                                                                            
** Remarks              : Global Variable(s)  :                               
**                        None
**                                                                            
**                        Function(s) invoked :                               
**                        None                                                
*******************************************************************************/
#if (DEM_SIZE_OF_FREEZEFRAME > 0u)
FUNC(P2VAR(uint8, AUTOMATIC, DEM_VAR), DEM_CODE) Dem_EvMem_GetFFBufferForWriting(
  const Dem_RecordNumberType  MaxLimit,
  Dem_EventMemoryEntryPtrType MemEntry,
  P2VAR(uint32, AUTOMATIC, DEM_VAR) BufSize)
{
  P2VAR(uint8, AUTOMATIC, DEM_VAR) dst = NULL_PTR;

  /* Tip, the range of Record Number is 1~254(0xFE). Record Number 0 is value for OBD Freeze Frame */  
  #if (DEM_DEV_ERROR_DETECT == STD_ON)  
  if (NULL_PTR != MemEntry)
  #endif
  {
    Dem_NumOfRecordNumberType iFFRecord = MemEntry->IndexOfFFRecords;
    if ((0U != MaxLimit) && (iFFRecord <= MaxLimit))
    {
      if(iFFRecord < MaxLimit)    
      {
        /* Increment the index of ListOfRecordNumbers for Next Step */
        MemEntry->IndexOfFFRecords++;
      }
      else 
      {
        /* Record Number  is never 0u, it is always more than one. 
         * [Dem585] If more than one freeze frame record isconfigured for a specific event,
         *  and this event is updated in the event memory, and all available freeze frame record
         * slots for this event are occupied, the Dem module shall update the most recent record. */    
        iFFRecord = MaxLimit - 1U;
      }          
      /* RecordIndex starts from zero */ 
      dst = &MemEntry->data[iFFRecord * (*BufSize)];
      *BufSize  = Dem_Size_Of_Event_Data - (iFFRecord * (*BufSize));          
    }
    else
    {
      /* MaxLimit never be 0, if MaxLimit is 0, FFClass of EvData will be generated as NULL_PTR . */
      DEM_REPORT_ERROR(DEM_UNSPECIFIED_SID, DEM_E_PARAM_CONFIG);
    }
  }

  return dst;
}

/*******************************************************************************
** Function Name        : Dem_EvMem_GetRecNumOfFF                           
**                                                                            
** Service ID           : None                                                
**                                                                            
** Description          : Gets the record number of a freeze frame 
**                                                                            
** Sync/Async           : Synchronous                                         
**                                                                            
** Re-entrancy          : Reentrant                                           
**                                                                            
** Input Parameters     : entry
**                                                                          
** InOut parameter      : None
**                                                                            
** Output Parameters    : None
**                                                                            
** Return parameter     : void
**                                                                            
** Preconditions        : None                                                
**                                                                            
** Remarks              : Global Variable(s)  :                               
**                        None
**                                                                            
**                        Function(s) invoked :                               
**                        None                                                
*******************************************************************************/
FUNC(Dem_RecordNumberType, DEM_CODE)
Dem_EvMem_GetRecNumOfFF(Dem_EventMemoryEntryCPCType entry)
{
  Dem_RecordNumberType recNum;
  if(NULL_PTR != entry)
  {
    recNum = entry->IndexOfFFRecords;
  }
  else
  /* polyspace<RTE:UNR:Not a defect:No action planned> Above If-condition always evaluates to true. Avoid the runtime error of the polyspace */  
  {
    recNum = (uint8)DEM_ZERO;
  }

  return recNum;
}

#endif

/*******************************************************************************
** Function Name        : Dem_EvMem_GetEventDataBuffer                          
**                                                                            
** Service ID           : None                                                
**                                                                            
** Description          : It is used to get the buffer address of             
**                        the specified event memory entry.                   
**                                                                            
** Sync/Async           : Synchronous                                         
**                                                                            
** Re-entrancy          : Reentrant                                           
**                                                                            
** Input Parameters     : entry                                               
**                                                                            
** InOut parameter      : None                                                
**                                                                            
** Output Parameters    : buffer                                              
**                                                                            
** Return parameter     : void                                                
**                                                                            
** Preconditions        : None                                                
**                                                                            
** Remarks              : Global Variable(s)  :                               
**                        None                                                
**                                                                            
**                        Function(s) invoked :                               
**                        None                                                
*******************************************************************************/
#if (DEM_SIZE_OF_EVENT_DATA > 0u)
FUNC(uint8* , DEM_CODE) Dem_EvMem_GetEventDataBuffer(
  Dem_EventMemoryEntryPtrType entry)
{
  return entry->data;
}
 
#endif
 /*
 switch(type)
 case ED
 if (NULL_PTR != EvData->FFClass)
  {
    src += EvData->MaxNumOfFreezeFrameRecords*EvData->FFClass->size;
  }
  else
   *buffer = entry->data;
  */
/* (DEM_MAX_EVENT_DESTINATION_SELECTED > DEM_ZERO) */
#endif

#if (DEM_EVMEM_TIMESTAMP_USED == STD_ON)
FUNC(void, DEM_CODE) Dem_EvMem_SetTimeStamp( Dem_EventMemoryEntryPtrType entry, uint32 NewTimeStamp )
{
  entry->TimeStamp = NewTimeStamp;
}

FUNC(uint32, DEM_CODE) Dem_EvMem_GetTimeStamp( Dem_EventMemoryEntryPtrType entry)
{
  return entry->TimeStamp;
}
#endif

/******************************************************************************
 * Function Name        : Dem_EvMem_SetFirstLastFailedDtc
 *
 * Service ID           : None
 *
 * Description          : Sets the order of an failed DTC. 
 *                        It used to UDS $17-[0B or 0D]
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Reentrant
 *
 * Input Parameters     : DTC
 *                        
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * Return parameter     : void
 *
 * Preconditions        : None
 *
 * Remarks              : Global Variable(s)  :
 *                        Dem_EventStatusNvRamData
 *
 *                        Function(s) invoked :
 *
 *****************************************************************************/
#if (DEM_DCM_RPT_FAILEDCONFIRMEDDTCINFO_USED == STD_ON)
FUNC(boolean, DEM_CODE)
Dem_EvMem_SetFirstLastFailedDtc(Dem_DTCOriginType DTCOrigin, Dem_DTCType DTC)
{
  boolean dirty = DEM_FALSE;

  /* polyspace<RTE:UNR:Not a defect:No action planned> If-condition evaluates to true or false according to configuration */  
  if (DEM_DTC_ORIGIN_PRIMARY_MEMORY == DTCOrigin)
  {
    const uint32 FirstIndex = DEM_FIRST_FAILED_DTC - 1U;
    const uint32 RecentIndex = DEM_MOST_RECENT_FAILED_DTC - 1U;
    
    SchM_Enter_Dem_REQUEST_OCCTIME_PROTECTION();
    /* Occurrence time DTC manipulation (First Failed DTC)*/
    if(DEM_NO_DTC == Dem_EventStatusNvRamData.DTCOccurenceTime[FirstIndex])
    {
      Dem_EventStatusNvRamData.DTCOccurenceTime[FirstIndex] = DTC;
      dirty = DEM_TRUE;
    }
    /* Most recent failed DTC */
    if (DTC != Dem_EventStatusNvRamData.DTCOccurenceTime[RecentIndex])
    {
      Dem_EventStatusNvRamData.DTCOccurenceTime[RecentIndex] = DTC;
      dirty = DEM_TRUE;    
    }
    SchM_Exit_Dem_REQUEST_OCCTIME_PROTECTION();
  }

  return dirty;
}


/******************************************************************************
 * Function Name        : Dem_EvMem_SetFirstLastConfirmedDTC
 *
 * Service ID           : None
 *
 * Description          : Sets the order of an comfirmed DTC. 
 *                        It used to UDS $17-[0C or 0E]
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Reentrant
 *
 * Input Parameters     : DTC
 *                        
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * Return parameter     : void
 *
 * Preconditions        : None
 *
 * Remarks              : Global Variable(s)  :
 *                        Dem_EventStatusNvRamData
 *
 *                        Function(s) invoked :
 *
 *****************************************************************************/
FUNC(boolean, DEM_CODE)
static Dem_EvMem_SetFirstLastConfirmedDTC(Dem_DTCOriginType DTCOrigin, Dem_DTCType DTC)
{
  boolean dirty = DEM_FALSE;

  /* polyspace<RTE:UNR:Not a defect:No action planned> If-condition evaluates to true or false according to configuration */
  if (DEM_DTC_ORIGIN_PRIMARY_MEMORY == DTCOrigin)
  {
    const uint32 FirstIndex = DEM_FIRST_DET_CONFIRMED_DTC - 1U;
    const uint32 MostIndex = DEM_MOST_REC_DET_CONFIRMED_DTC - 1U;

    SchM_Enter_Dem_REQUEST_OCCTIME_PROTECTION();
    /* Occurrence time DTC manipulation (first detected confirmed DTC ) */
    if(DEM_NO_DTC == Dem_EventStatusNvRamData.DTCOccurenceTime[FirstIndex])
    {
      Dem_EventStatusNvRamData.DTCOccurenceTime[FirstIndex] = DTC;    
      dirty = DEM_TRUE;
    }
    /* Most recently detected confirmed DTC */
    if (DTC != Dem_EventStatusNvRamData.DTCOccurenceTime[MostIndex])
    {
      Dem_EventStatusNvRamData.DTCOccurenceTime[MostIndex] = DTC;    
      dirty = DEM_TRUE;
    }
    SchM_Exit_Dem_REQUEST_OCCTIME_PROTECTION();
  }
  return dirty;
}

/******************************************************************************
 * Function Name        : Dem_SetClearOrderOfDtc
 *
 * Service ID           : None
 *
 * Description          : Clears the order of the specific DTC. 
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Reentrant
 *
 * Input Parameters     : DTC
 *                        
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * Return parameter     : void
 *
 * Preconditions        : None
 *
 * Remarks              : 
 *****************************************************************************/
FUNC(boolean, DEM_CODE)
Dem_EvMem_ClearDTCOccurrenceTime(const Dem_DTCType DTC, boolean AllDTCs)
{
  uint32 i;
  boolean dirty = DEM_FALSE;
  
  SchM_Enter_Dem_REQUEST_OCCTIME_PROTECTION();

  if (DEM_TRUE == AllDTCs)
  {
    for (i = 0u; i < DEM_MAX_DTC_REQEST_TYPE; i++)
    {  
      if (DEM_NO_DTC != Dem_EventStatusNvRamData.DTCOccurenceTime[i])
      {
        Dem_EventStatusNvRamData.DTCOccurenceTime[i] = DEM_NO_DTC;
        dirty = DEM_TRUE;
      }
    }
  }
  else
  {
    for (i = 0u; i < DEM_MAX_DTC_REQEST_TYPE; i++)
    {
      if (DTC == Dem_EventStatusNvRamData.DTCOccurenceTime[i])
      {
        Dem_EventStatusNvRamData.DTCOccurenceTime[i] = DEM_NO_DTC;
        dirty = DEM_TRUE;
      }
    }
  }
  SchM_Exit_Dem_REQUEST_OCCTIME_PROTECTION();

  return dirty;
}
#endif

/*******************************************************************************
** Function Name        : Dem_EvMem_SetEvMemOverflowFlag
**                                                                            
** Service ID           : None                                                
**                                                                            
** Description          : Sets the overflow indication flag of event memory 
**                                                                            
** Sync/Async           : Synchronous                                         
**                                                                            
** Re-entrancy          : Reentrant                                           
**                                                                            
** Input Parameters     : DTCOrigin,
**                        state (DEM_TRUE: memory is full, DEM_FALSE: not full)
**                                                                            
** InOut parameter      : None
**                                                                            
** Output Parameters    : None
**                                                                            
** Return parameter     : void
**                                                                            
** Preconditions        : None                                                
**                                                                            
** Remarks              :    
*******************************************************************************/
FUNC(boolean, DEM_CODE) Dem_EvMem_SetEvMemOverflowFlag(
  Dem_DTCOriginType DTCOrigin, 
  boolean state)
{
  boolean dirty = DEM_FALSE;

  if (DEM_TRUE == Dem_EvMem_DTCOriginIsValid(DTCOrigin))
  {
    boolean oldState = Dem_IsBit8Set(Dem_EventStatusNvRamData.EventMemoryOverflow, DTCOrigin);
    if (oldState != state)
    {
      Dem_EventStatusNvRamData.EventMemoryOverflow = (state == DEM_TRUE) ? 
        Dem_SetBit8(Dem_EventStatusNvRamData.EventMemoryOverflow, DTCOrigin) :
        Dem_ClearBit8(Dem_EventStatusNvRamData.EventMemoryOverflow, DTCOrigin);
        
      dirty = DEM_TRUE;
    }
  }
  
  return dirty;
}

/*******************************************************************************
** Function Name        : Dem_EvMem_GetEvMemOverflowFlag
**                                                                            
** Service ID           : None                                                
**                                                                            
** Description          : Gets the overflow indication flag of event memory 
**                                                                            
** Sync/Async           : Synchronous                                         
**                                                                            
** Re-entrancy          : Reentrant                                           
**                                                                            
** Input Parameters     : DTCOrigin,
**                        
**                                                                            
** InOut parameter      : None
**                                                                            
** Output Parameters    : None
**                                                                            
** Return parameter     : boolean(DEM_TRUE: memory is full, DEM_FALSE: not full)
**                                                                            
** Preconditions        : None                                                
**                                                                            
** Remarks              : 
*******************************************************************************/
FUNC(boolean, DEM_CODE) Dem_EvMem_GetEvMemOverflowFlag(
  Dem_DTCOriginType DTCOrigin)
{
  return  Dem_IsBit8Set(Dem_EventStatusNvRamData.EventMemoryOverflow, DTCOrigin);
}

/******************************************************************************
 * Function Name        : Dem_EvMem_CheckFirstEcuRun
 *
 * Service ID           : None
 *
 * Description          : Checks whether non-volatile datas are written
 *                        at least one  or not in the NvRam
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Reentrant
 *
 * Input Parameters     : None
 *                        
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * Return parameter     : boolean
 *
 * Preconditions        : None
 *
 * Remarks              : 
 *****************************************************************************/
FUNC(boolean, DEM_CODE) Dem_EvMem_CheckFirstEcuRun(void)
{
  boolean retVal;

  if (
    (DEM_NVM_FOOTPRINT            == Dem_NonVolatileData.FootPrint) &&
    (DEM_EVMEM_VERSION_SIGNATURES == Dem_NonVolatileData.EvMemVer[0]) &&
    (DEM_EVMEM_VERSION_MAJOR      == Dem_NonVolatileData.EvMemVer[1]) &&
    (DEM_EVMEM_VERSION_MINOR      == Dem_NonVolatileData.EvMemVer[2]) &&
    (DEM_EVMEM_VERSION_REVISION   == Dem_NonVolatileData.EvMemVer[3]))
  {
    retVal = DEM_TRUE;
  }
  else
  {
    retVal = DEM_FALSE;  
  }
  return retVal;
}



/******************************************************************************
 * Function Name        : Dem_EvMem_ResetEventStatusNvRamBlock
 *
 * Service ID           : None
 *
 * Description          : Clears the non-volatile data(event memory, etc)
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Reentrant
 *
 * Input Parameters     : None
 *                        
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * Return parameter     : None
 *
 * Preconditions        : None
 *
 * Remarks              : Global Variable(s)  :
 *                        Dem_EventStatusNvRamData
 *
 *                        Function(s) invoked :
 *                        DEM_RST_UDSSTATUSBYTE()
 *****************************************************************************/
FUNC(void, DEM_CODE) Dem_EvMem_ResetEventStatusNvRamBlock(void)
{
  Dem_EventIdType nvDataIndex;

  for(nvDataIndex = 0U; nvDataIndex < DEM_BITARRAY_BITNSLOTS(1U + Dem_Number_Of_Events); nvDataIndex++)
  {    
    #if (DEM_UDS_STATUS_TF_ALLEVENTSTATUS > 0U)
    Dem_EventStatusNvRamData.TF_BitArray[nvDataIndex] = 0U;
    #endif   
   
    #if (DEM_UDS_STATUS_TFTOC_ALLEVENTSTATUS > 0U)
    Dem_EventStatusNvRamData.TFTOC_BitArray[nvDataIndex] = 0U;
    #endif
    
    #if (DEM_UDS_STATUS_PDTC_ALLEVENTSTATUS > 0U)
    Dem_EventStatusNvRamData.PDTC_BitArray[nvDataIndex] = 0U;
    #endif
    
    #if (DEM_UDS_STATUS_CDTC_ALLEVENTSTATUS > 0U)
    Dem_EventStatusNvRamData.CDTC_BitArray[nvDataIndex] = 0xFFU;
    #endif
    
    #if (DEM_UDS_STATUS_TNCSLC_ALLEVENTSTATUS > 0U)
    Dem_EventStatusNvRamData.TNCSLC_BitArray[nvDataIndex] = 0xFFU;
    #endif
    
    #if (DEM_UDS_STATUS_TFSLC_ALLEVENTSTATUS > 0U)
    Dem_EventStatusNvRamData.TFSLC_BitArray[nvDataIndex] = 0U;
    #endif  
    
    #if (DEM_UDS_STATUS_TNCTOC_ALLEVENTSTATUS > 0U) 
    Dem_EventStatusNvRamData.TNCTOC_BitArray[nvDataIndex] = 0xFFU;
    #endif
    
    #if (DEM_UDS_STATUS_WIR_ALLEVENTSTATUS > 0U)
    Dem_EventStatusNvRamData.WIR_BitArray[nvDataIndex] = 0U;
    #endif
  }

  #if ((DEM_OBD_SUPPORT == STD_ON) && (DEM_NUMBER_OF_INDICATORS > 0U))
  for(nvDataIndex = 0u; nvDataIndex < Dem_Number_Of_Indicators; nvDataIndex++)
  {    
    Dem_EventStatusNvRamData.IndicatorMilCounter[nvDataIndex] = 0U;
  }
  #endif

  #if(DEM_NUM_OF_INDICATOR_ATTRIBUTE_STATUS > 0u)
  for(nvDataIndex = 0u; nvDataIndex < Dem_Num_Of_Indicator_Attribute_Status; nvDataIndex++)
  {    
    Dem_EventStatusNvRamData.AttributeStatus[nvDataIndex] = 0U;
  }
  #endif

  #if(DEM_NUM_OF_FAILURE_COUNTER > 0u)
  for(nvDataIndex = 0u; nvDataIndex < Dem_Num_Of_Failure_Counter; nvDataIndex++)
  {    
    Dem_EventStatusNvRamData.IndicatorFailureCycleCounter[nvDataIndex] = 0U;
  }
  #endif
  
  #if(DEM_NUM_OF_HEALING_COUNTER > 0u)
  for(nvDataIndex = 0u; nvDataIndex < Dem_Num_Of_Healing_Counter; nvDataIndex++)
  {    
    Dem_EventStatusNvRamData.IndicatorHealingCycleCounter[nvDataIndex] = 0U;
  }
  #endif

  /* Clears the order of the DTCs */
  #if (DEM_DCM_RPT_FAILEDCONFIRMEDDTCINFO_USED == STD_ON)
  for (nvDataIndex = 0; nvDataIndex < DEM_MAX_DTC_REQEST_TYPE; nvDataIndex++)
  {
    Dem_EventStatusNvRamData.DTCOccurenceTime[nvDataIndex] = DEM_NO_DTC;
  }  
  #endif  

  Dem_EventStatusNvRamData.EventMemoryOverflow = 0U;
}



/******************************************************************************
 * Function Name        : Dem_EvMem_ResetManagementBlock
 *
 * Service ID           : None
 *
 * Description          : Clears the non-volatile data(event memory, etc)
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Reentrant
 *
 * Input Parameters     : SetfootPrintAsDefault
 *                        
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * Return parameter     : None
 *
 * Preconditions        : None
 *
 * Remarks              : 
 *****************************************************************************/
FUNC(void, DEM_CODE) Dem_EvMem_ResetManagementBlock(boolean SetfootPrintAsDefault)
{
  uint8 ocIndex;
 
  /* Initialize the operation cycle state */
  for(ocIndex = 0u; ocIndex < Dem_Num_Operation_Cycles; ocIndex++)
  {
    (void)Dem_EvMem_SetOpCycleState((uint8)ocIndex, DEM_CYCLE_STATE_END);
  } 

  if (DEM_TRUE == SetfootPrintAsDefault)
  {
    Dem_NonVolatileData.FootPrint = DEM_NVM_FOOTPRINT;
    Dem_NonVolatileData.EvMemVer[0] = DEM_EVMEM_VERSION_SIGNATURES;
    Dem_NonVolatileData.EvMemVer[1] = DEM_EVMEM_VERSION_MAJOR;
    Dem_NonVolatileData.EvMemVer[2] = DEM_EVMEM_VERSION_MINOR;
    Dem_NonVolatileData.EvMemVer[3] = DEM_EVMEM_VERSION_REVISION;     
  }
  else
  {
    Dem_NonVolatileData.FootPrint = 0;  
    Dem_NonVolatileData.EvMemVer[0] = 0U;
    Dem_NonVolatileData.EvMemVer[1] = 0U;
    Dem_NonVolatileData.EvMemVer[2] = 0U;
    Dem_NonVolatileData.EvMemVer[3] = 0U;    
  }
}

/******************************************************************************
* Function Name        : Dem_EvMem_SetOpCycleState
*
* Service ID           : None
*
* Description          : Sets the state of an operation(start or end)
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant
*
* Input Parameters     : OperationIndex, state
*                        
* InOut parameter      : None
*
* Output Parameters    : None
*
* Return parameter     : void
*
* Preconditions        : None
*
* Remarks              : 
*****************************************************************************/
FUNC(boolean, DEM_CODE) Dem_EvMem_SetOpCycleState(
    uint8 OperationCycleId,
  Dem_OperationCycleStateType state)
{
  boolean dirty;
  #if (DEM_OPERATION_CYCLE_STATUS_STORAGE == STD_ON)  
  if (Dem_NonVolatileData.OperationCycleState[OperationCycleId] != state)
  {
    Dem_NonVolatileData.OperationCycleState[OperationCycleId] = state;  
    dirty = DEM_TRUE;
  }  
  else
  {
    dirty = DEM_FALSE;
  }
  #else
  Dem_OperationCycleState[OperationCycleId] = state;
  dirty = DEM_FALSE;
  #endif
  
  return dirty;
}

/******************************************************************************
* Function Name        : Dem_EvMem_GetOpCycleState
*
* Service ID           : None
*
* Description          : Sets the state of an operation(start or end)
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant
*
* Input Parameters     : OperationIndex 
*                        
* InOut parameter      : None
*
* Output Parameters    : state
*
* Return parameter     : void
*
* Preconditions        : None
*
* Remarks              : 
*****************************************************************************/
FUNC(void, DEM_CODE) Dem_EvMem_GetOpCycleState(
  uint8 OperationCycleId,
  P2VAR(Dem_OperationCycleStateType, AUTOMATIC, DEM_VAR) CycleState)
{
  #if (DEM_OPERATION_CYCLE_STATUS_STORAGE == STD_ON)  
  *CycleState = Dem_NonVolatileData.OperationCycleState[OperationCycleId];
  #else
  *CycleState = Dem_OperationCycleState[OperationCycleId];
  #endif
}


/******************************************************************************
* Function Name        : Dem_EvMem_IncAgingCounter
*
* Service ID           : None
*
* Description          : Increase the aging counter of the event that stored
*                         in the event memory
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant
*
* Input Parameters     : entry
*                        
* InOut parameter      : None
*
* Output Parameters    : None
*
* Return parameter     : uint8
*
* Preconditions        : None
*
* Remarks              : Global Variable(s)  :
*
*                        Function(s) invoked :
*
*****************************************************************************/
FUNC(boolean, DEM_CODE) Dem_EvMem_IncAgingCounter(
  Dem_EventMemoryEntryPtrType entry,
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) AgingCounter)
{
  boolean dirty = DEM_FALSE;
  if (entry->AgingCycleCounter < (uint8)0xFF)
  {
    ++(entry->AgingCycleCounter);
    *AgingCounter = entry->AgingCycleCounter;
    dirty = DEM_TRUE;
   }

  return dirty;
}

/******************************************************************************
* Function Name        : Dem_EvMem_GetAgingCounter
*
* Service ID           : None
*
* Description          : Gets the aging counter of the event that stored
*                         in the event memory
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant
*
* Input Parameters     : entry
*                        
* InOut parameter      : None
*
* Output Parameters    : AgingCycleCounter
*
* Return parameter     : void
*
* Preconditions        : None
*
* Remarks              : Global Variable(s)  :
*
*                        Function(s) invoked :
*
*****************************************************************************/
FUNC(uint8, DEM_CODE) 
Dem_EvMem_GetAgingCounter(  
  Dem_EventMemoryEntryPtrType MemEntry)
{
  return MemEntry->AgingCycleCounter;
}

/******************************************************************************
* Function Name        : Dem_EvMem_SetAgingCounter
*
* Service ID           : None
*
* Description          : Sets the aging counter of the event that stored
*                        to API parameter AgingCycleCounter in the event memory
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant
*
* Input Parameters     : entry, AgingCycleCounter
*                        
* InOut parameter      : None
*
* Output Parameters    : None
*
* Return parameter     : uint8
*
* Preconditions        : None
*
* Remarks              : Global Variable(s)  :
*
*                        Function(s) invoked :
*
*****************************************************************************/
FUNC(boolean, DEM_CODE) 
Dem_EvMem_SetAgingCounter(
  Dem_EventMemoryEntryPtrType entry,
  uint8 AgingCounter)
{
  boolean dirty = DEM_FALSE;
  if (AgingCounter != entry->AgingCycleCounter)
  {
    dirty = DEM_TRUE;
    entry->AgingCycleCounter = AgingCounter;
  }

  return dirty;
}

/******************************************************************************
* Function Name        : Dem_EvMem_SetFailureCounter
*
* Service ID           : None
*
* Description          : Sets the aging counter of the event that stored
*                        to API parameter FailureCycleCounter in the event memory
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant
*
* Input Parameters     : entry, FailureCycleCounter
*                        
* InOut parameter      : None
*
* Output Parameters    : None
*
* Return parameter     : uint8
*
* Preconditions        : None
*
* Remarks              : Global Variable(s)  :
*
*                        Function(s) invoked :
*
*****************************************************************************/
FUNC(boolean, DEM_CODE) 
Dem_EvMem_SetFailureCounter(
  Dem_EventMemoryEntryPtrType entry,
  uint8 FailureCounter)
{
  boolean dirty = DEM_FALSE;

  #if (DEM_NUM_OF_ENABLE_TRIP_COUNTER > 1U)
  if (entry->FailureCycleCounter != FailureCounter)
  {
    entry->FailureCycleCounter = FailureCounter;
    dirty = DEM_TRUE;
  }
  #else
  /* polyspace<RTE:UNR:Not a defect:No action planned> If-condition evaluates to true or false according to configuration */
  DEM_UNUSED(FailureCounter);
  /* polyspace<RTE:UNR:Not a defect:No action planned> If-condition evaluates to true or false according to configuration */
  DEM_UNUSED_PTR(entry);
  #endif

  return dirty;
}


/******************************************************************************
* Function Name        : Dem_EvMem_GetFailureCounter
*
* Service ID           : None
*
* Description          : Gets the failure counter of the event that stored
*                        in the event memory
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant
*
* Input Parameters     : entry
*                        
* InOut parameter      : None
*
* Output Parameters    : None
*
* Return parameter     : uint8
*
* Preconditions        : None
*
* Remarks              : Global Variable(s)  :
*
*                        Function(s) invoked :
*
*****************************************************************************/
FUNC(uint8, DEM_CODE) 
Dem_EvMem_GetFailureCounter(
  Dem_EventMemoryEntryPtrType entry)
{ 
  #if (DEM_NUM_OF_ENABLE_TRIP_COUNTER > 1U)

  return entry->FailureCycleCounter;  

  #else

  DEM_UNUSED_PTR(entry);
  return 0U;
  
  #endif  
}


/******************************************************************************
 * Function Name        : Dem_EvMem_IncEventOccCounter
 *
 * Service ID           : None
 *
 * Description          : This function increments  the  occurrence counter 
 *                        by one, triggered by each UDS DTC status bit 0 
 *                        (TestFailed) transition from 0 to 1, if the related 
                          event is already stored in the event memory.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Reentrant
 *
 * Input Parameters     : entry
 *                        
 * InOut parameter      : None
 *
 * Output Parameters    : 
 *
 * Return parameter     : uint8 (value of the current occurrence counter)
 *
 * Preconditions        : counter shall be more than one.
 *
 * Remarks              : Global Variable(s)  :
 *                        None
 *
 *                        Function(s) invoked :
 *                        None
 *
 *****************************************************************************/
FUNC(boolean, DEM_CODE) 
Dem_EvMem_IncEventOccCounter(
  Dem_EventMemoryEntryPtrType entry)
{
  boolean dirty = DEM_FALSE;
  Dem_EventOccurrenceType occurrenceCounter = 0;
  
  /* @IF_REQ , @IF_REQ :
    KPIT used the condition below.
    "#if ((DEM_OBD_SUPPORT == STD_OFF) && \
    (DEM_OCCCTR_PROCESSING == DEM_PROCESS_OCCCTR_TF)) "
     */
  
  /*## EVENT OCCURRENCE ##
  
  (1) case DEM_PROCESS_OCCCTR_TF
       As per SWS_Dem_00524 -
  
    condition I :   the  Dem  module  shall  increment  the  occurrence counter  by one,
                triggered by each UDS DTC status bit 0 (TestFailed)
                transition from 0 to 1,
  
    condition II: if the related event is already stored in the event memory.
  
  (2) case DEM_PROCESS_OCCCTR_CDTC
        As per SWS_Dem_00580 -
  
    condition I :   the Dem module shall increment the occurrence counter  by one,
                    triggered by each UDS DTC status bit 0 (TestFailed) transition from
                0 to 1.
  
    condition II: if the related event is already stored in the event memory
  
    condition III:  the UDS DTC Status bit 3 (ConfirmedDTC) is equal to 1
    */
  
  occurrenceCounter = entry->EventOccurrenceCounter;
  
  /* NOTE : NO ZERO  */
  if((occurrenceCounter > (uint8)0x00) && (occurrenceCounter  < (uint8)DEM_OCC_MAX))
  {
    dirty = DEM_TRUE;
     /* Dem524:  Increment the occurrence counter by one. */
    SchM_Enter_Dem_REQUEST_OCC_PROTECTION();
    ++entry->EventOccurrenceCounter;
    SchM_Exit_Dem_REQUEST_OCC_PROTECTION();

  }
  
  return dirty;
}

/******************************************************************************
 * Function Name        : Dem_EvMem_GetEventOccCounter
 *
 * Service ID           : None
 *
 * Description          : Gets the event occurrence counter in the event memory
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Reentrant
 *
 * Input Parameters     : entry
 *                        
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * Return parameter     : void
 *
 * Preconditions        : 
 *
 * Remarks              : Global Variable(s)  :
 *                        None
 *
 *                        Function(s) invoked :
 *                        None
 *
 *****************************************************************************/
FUNC(Dem_EventOccurrenceType, DEM_CODE) 
Dem_EvMem_GetEventOccCounter(
  Dem_EventMemoryEntryPtrType MemEntry)
{
  return MemEntry->EventOccurrenceCounter;
}

/******************************************************************************
 * Function Name        : Dem_EvMem_SetEventOccCounter
 *
 * Service ID           : None
 *
 * Description          : Sets the event occurrence counter in the event memory
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Reentrant
 *
 * Input Parameters     : EventOccurrenceCounter
 *                        
 * InOut parameter      : entry
 *
 * Output Parameters    : 
 *
 * Return parameter     : uint8 (value of the current occurrence counter)
 *
 * Preconditions        : 
 *
 * Remarks              : Global Variable(s)  :
 *                        None
 *
 *                        Function(s) invoked :
 *                        None
 *
 *****************************************************************************/
FUNC(uint8, DEM_CODE) 
Dem_EvMem_SetEventOccCounter(
   Dem_EventMemoryEntryPtrType entry,
   Dem_EventOccurrenceType OccurrenceCounter)
{
  /*don't care dirty state */
  SchM_Enter_Dem_REQUEST_OCC_PROTECTION();
  entry->EventOccurrenceCounter = OccurrenceCounter;
  SchM_Exit_Dem_REQUEST_OCC_PROTECTION();

  return OccurrenceCounter;
}


/******************************************************************************
 * Function Name        : Dem_EvMem_GetDTCByOccurrenceTime
 *
 * Service ID           : None
 *
 * Description          : Sets the order of an failed DTC. 
 *                        It used to UDS $17-[0B or 0D]
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Reentrant
 *
 * Input Parameters     : DTC
 *                        
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * Return parameter     : void
 *
 * Preconditions        : None
 *
 * Remarks              : 
 *****************************************************************************/
#if (DEM_DCM_RPT_FAILEDCONFIRMEDDTCINFO_USED == STD_ON)
FUNC(Std_ReturnType, DEM_CODE)
Dem_EvMem_GetDTCByOccurrenceTime(
  Dem_DTCRequestType ReqType, 
  P2VAR (uint32, AUTOMATIC, DEM_APPL_DATA) DTC)
{
  Std_ReturnType retVal = E_NOT_OK;

  ReqType = ReqType -1u;
  /* polyspace<RTE:UNR:Not a defect:No action planned> If-condition always evaluates to true. Avoid the runtime error of the polyspace */
  if (ReqType < DEM_MAX_DTC_REQEST_TYPE)
  {
    SchM_Enter_Dem_REQUEST_OCCTIME_PROTECTION();
    *DTC = Dem_EventStatusNvRamData.DTCOccurenceTime[ReqType];
    SchM_Exit_Dem_REQUEST_OCCTIME_PROTECTION();

    if (DEM_NO_DTC != *DTC)
    {
      retVal = E_OK;
    }
  }

  return retVal;
}
#endif


/******************************************************************************
* Function Name        : Dem_EvMem_IncreaseIndicatorHealingCounter
*
* Service ID           : None
*
* Description          : Increase the failure counter of the event that stored
*                        in the event memory
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant
*
* Input Parameters     : entry
*                        
* InOut parameter      : None
*
* Output Parameters    : None
*
* Return parameter     : uint8
*
* Preconditions        : None
*
* Remarks              : Global Variable(s)  :
*
*                        Function(s) invoked :
*
*****************************************************************************/
FUNC(boolean, DEM_CODE) Dem_EvMem_IncreaseIndicatorHealingCounter(
  const Dem_NumOfIndicatorAttributeType HealingCounterId,
  P2VAR(uint8, AUTOMATIC, DEM_VAR) CounterValue)
{
  boolean dirty = DEM_FALSE;
  #if (DEM_NUM_OF_HEALING_COUNTER > 0u)
  if (HealingCounterId < Dem_Num_Of_Healing_Counter)
  {
    if (Dem_EventStatusNvRamData.IndicatorHealingCycleCounter[HealingCounterId] < (uint8)0xFF)
    {
      Dem_EventStatusNvRamData.IndicatorHealingCycleCounter[HealingCounterId]++;
      dirty = DEM_TRUE;
    }
    *CounterValue = Dem_EventStatusNvRamData.IndicatorHealingCycleCounter[HealingCounterId];
  }
  else
  {
    *CounterValue = 0U;
  }
  #endif

  return dirty;
}

/******************************************************************************
* Function Name        : Dem_EvMem_IncreaseIndicatorFailureCounter
*
* Service ID           : None
*
* Description          : Increase the failure counter of the event that stored
*                        in the event memory
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant
*
* Input Parameters     : entry
*                        
* InOut parameter      : None
*
* Output Parameters    : None
*
* Return parameter     : uint8
*
* Preconditions        : None
*
* Remarks              : Global Variable(s)  :
*
*                        Function(s) invoked :
*
*****************************************************************************/
FUNC(boolean, DEM_CODE) Dem_EvMem_IncreaseIndicatorFailureCounter(
  const Dem_NumOfIndicatorAttributeType FailureCounterId,
  P2VAR(uint8, AUTOMATIC, DEM_VAR) CounterValue)
{
  boolean dirty = DEM_FALSE;
  
  #if (DEM_NUM_OF_FAILURE_COUNTER > 0u)
  if (FailureCounterId < Dem_Num_Of_Failure_Counter)
  {
    if (Dem_EventStatusNvRamData.IndicatorFailureCycleCounter[FailureCounterId] < (uint8)0xFF)
    {
      dirty = DEM_TRUE;
      Dem_EventStatusNvRamData.IndicatorFailureCycleCounter[FailureCounterId]++;
    }
    *CounterValue = Dem_EventStatusNvRamData.IndicatorFailureCycleCounter[FailureCounterId];
  }
  else
  {
    *CounterValue = 0U;
  }
  #endif

  return dirty;
}

/******************************************************************************
* Function Name        : Dem_EvMem_SetIndicatorHealingCounter
*
* Service ID           : None
*
* Description          : Increase the failure counter of the event that stored
*                        in the event memory
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant
*
* Input Parameters     : entry
*                        
* InOut parameter      : None
*
* Output Parameters    : None
*
* Return parameter     : uint8
*
* Preconditions        : None
*
* Remarks              : Global Variable(s)  :
*
*                        Function(s) invoked :
*
*****************************************************************************/
FUNC(boolean, DEM_CODE) 
Dem_EvMem_SetIndicatorHealingCounter(
  const Dem_NumOfIndicatorAttributeType HealingCounterId,
  const uint8 HealingCounter)
{
  boolean dirty = DEM_FALSE;

  #if (DEM_NUM_OF_HEALING_COUNTER > 0u)
  if (HealingCounterId < Dem_Num_Of_Healing_Counter)
  {
    if (Dem_EventStatusNvRamData.IndicatorHealingCycleCounter[HealingCounterId] != HealingCounter)
    {
      Dem_EventStatusNvRamData.IndicatorHealingCycleCounter[HealingCounterId] = HealingCounter;
      dirty = DEM_TRUE;
    }
  }
  #endif

  return dirty;
}

/******************************************************************************
* Function Name        : Dem_EvMem_IncreaseIndicatorFailureCounter
*
* Service ID           : None
*
* Description          : Increase the failure counter of the event that stored
*                        in the event memory
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant
*
* Input Parameters     : entry
*                        
* InOut parameter      : None
*
* Output Parameters    : None
*
* Return parameter     : uint8
*
* Preconditions        : None
*
* Remarks              : Global Variable(s)  :
*
*                        Function(s) invoked :
*
*****************************************************************************/
FUNC(boolean, DEM_CODE) 
Dem_EvMem_SetIndicatorFailureCounter(
  const Dem_NumOfIndicatorAttributeType FailureCounterId,
  const uint8 FailureCounter)
{
  boolean dirty = DEM_FALSE;
  #if (DEM_NUM_OF_FAILURE_COUNTER > 0u)
  if (FailureCounterId < Dem_Num_Of_Failure_Counter)
  {
    if (Dem_EventStatusNvRamData.IndicatorFailureCycleCounter[FailureCounterId] != FailureCounter)
    {
      Dem_EventStatusNvRamData.IndicatorFailureCycleCounter[FailureCounterId] = FailureCounter;
      dirty = DEM_TRUE;
    }
  }
  #endif

  return dirty;
}

/******************************************************************************
* Function Name        : Dem_EvMem_IncreaseIndicatorFailureCounter
*
* Service ID           : None
*
* Description          : Increase the failure counter of the event that stored
*                        in the event memory
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant
*
* Input Parameters     : entry
*                        
* InOut parameter      : None
*
* Output Parameters    : None
*
* Return parameter     : uint8
*
* Preconditions        : None
*
* Remarks              : Global Variable(s)  :
*
*                        Function(s) invoked :
*
*****************************************************************************/
FUNC(boolean, DEM_CODE) 
Dem_EvMem_SetIndicatorAttStatus(
  const Dem_EventIdType EventId,
  const Dem_NumOfIndicatorAttributeType IndicatorAttrId,
  const boolean AttStatus)
{
  boolean dirty = DEM_FALSE;

  #if (DEM_NUM_OF_INDICATOR_ATTRIBUTE_STATUS > 0u)
  if (Dem_Event[EventId - 1U].ucNumberofIndicator > 1U)
  {  
    if (IndicatorAttrId < Dem_Num_Of_Indicator_Attribute_Status)
    {
      if (Dem_EventStatusNvRamData.AttributeStatus[IndicatorAttrId] != AttStatus)
      {
        Dem_EventStatusNvRamData.AttributeStatus[IndicatorAttrId] = AttStatus;
        dirty = DEM_TRUE;
      }
    }
  }
  #endif
  
  return dirty;
}

/******************************************************************************
* Function Name        : Dem_EvMem_IncreaseIndicatorFailureCounter
*
* Service ID           : None
*
* Description          : Increase the failure counter of the event that stored
*                        in the event memory
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant
*
* Input Parameters     : entry
*                        
* InOut parameter      : None
*
* Output Parameters    : None
*
* Return parameter     : uint8
*
* Preconditions        : None
*
* Remarks              : Global Variable(s)  :
*
*                        Function(s) invoked :
*
*****************************************************************************/
FUNC(boolean, DEM_CODE) 
Dem_EvMem_GetIndicatorAttStatus(
  const Dem_EventIdType EventId,
  const Dem_NumOfIndicatorAttributeType IndicatorAttrId)
{
  boolean status = DEM_FALSE;

  #if (DEM_NUM_OF_INDICATOR_ATTRIBUTE_STATUS > 0u)
  if (Dem_Event[EventId - 1U].ucNumberofIndicator > 1U)
  {
    if (IndicatorAttrId < Dem_Num_Of_Indicator_Attribute_Status)
    {
      status = Dem_EventStatusNvRamData.AttributeStatus[IndicatorAttrId];
    }
  }
  else
  #endif
  {
    status = (boolean)(((uint8)(Dem_AllEventStatusByte[EventId] >> 7U)) & (uint8)0x01);
  }
  
  return status;
}

/******************************************************************************
* Function Name        : Dem_EvMem_GetUdsStatusByteToNvData
*
* Service ID           : None
*
* Description          : Retrieve event status of the specific event in the 
*                        nv data
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant
*
* Input Parameters     : entry
*                        
* InOut parameter      : None
*
* Output Parameters    : None
*
* Return parameter     : uint8
*
* Preconditions        : None
*
* Remarks              : This function is called by Dem_EvMem_Init once
*
*****************************************************************************/
FUNC(Dem_UdsStatusByteType, DEM_CODE) 
Dem_EvMem_GetUdsStatusByteToNvData(
 const Dem_EventIdType EventId,
 const Dem_DTCOriginType DTCOrigin
)
{
  Dem_UdsStatusByteType udsStatusByte = 0U;

  #if (DEM_NVRAMBLOCK_ACCESS_OPTIMIZATION_SUPPORT == STD_ON)
  if (Dem_EvMemToEventMap[EventId] <  Dem_SizeOfEventMemory[DTCOrigin])
  {
    Dem_EventMemoryEntryPtrType memEntry = NULL_PTR;

    /* Duplicated code for performance and runtime check(polyspace) */        
    if (DEM_DTC_ORIGIN_PRIMARY_MEMORY == DTCOrigin)  
    {
      memEntry = &Dem_PrimaryEventMemory[Dem_EvMemToEventMap[EventId]];              
    }        
    #if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC > 0U)  
    else if (DEM_DTC_ORIGIN_SECONDARY_MEMORY == DTCOrigin) 
    {
      memEntry = &Dem_SecondaryEventMemory[Dem_EvMemToEventMap[EventId]]; 
    }
    #endif
    else
    {
      /* Do nothing */
    }        
    if (NULL_PTR != memEntry) 
    {
      #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_TYPE1)      
      Dem_CombinedDtcPCType cbDTC = Dem_GetCbDTCByEventId(EventId);
      if (NULL_PTR != cbDTC)
      {
        if (1U == cbDTC->ddNumberOfEvents)
        {
          udsStatusByte = memEntry->EventStatuByte[0];
        }
        else
        {
          Dem_NumOfEventIdType index = 0U;
          Dem_NumOfEventIdType startPos = Dem_GetStartEventIdMapOfCbDTC(cbDTC);
          const Dem_NumOfEventIdType endPos = Dem_GetEndEventIdMapOfCbDTC(cbDTC);                
          while (startPos < endPos)
          {    
            if ((index < DEM_MAX_NUM_EVENTS_PER_DTC) && (Dem_ListOfCombinedEvents[startPos] == EventId))
            {
              udsStatusByte = memEntry->EventStatuByte[index];
              break;
            }
            ++index;
            ++startPos;
          }
        }
      }
      #else
      udsStatusByte = memEntry->EventStatuByte[0];
      #endif
    }
  }
  else
  #endif  
  {    
    /*+------------------------------------+-----+
      | TestFailed                         | 0   |
      +------------------------------------+-----+
      | TestFailedThisOperationCycle       | 1   |
      +------------------------------------+-----+
      | PendingDTC                         | 2   |
      +------------------------------------+-----+
      | ConfirmedDTC                       | 3   |
      +------------------------------------+-----+
      | TestNotCompletedSinceLastClear     | 4   |
      +------------------------------------+-----+
      | TestFailedSinceLastClear           | 5   |
      +------------------------------------+-----+
      | TestNotCompletedThisOperationCycle | 6   |
      +------------------------------------+-----+
      | WarningIndicatorRequested          | 7   |
      +------------------------------------+-----+*/
    
    #if (DEM_UDS_STATUS_TF_ALLEVENTSTATUS > 0U)
    DEM_UDSSTATUS_GET_NV(udsStatusByte, EventId, 0U, Dem_EventStatusNvRamData.TF_BitArray);
    #else
    /* Default Value is 'Clear' */    
    #endif   
   
    #if (DEM_UDS_STATUS_TFTOC_ALLEVENTSTATUS > 0U)
    DEM_UDSSTATUS_GET_NV(udsStatusByte, EventId, 1U, Dem_EventStatusNvRamData.TFTOC_BitArray);
    #else
    /* Default Value is 'Clear' */    
    #endif
    
    #if (DEM_UDS_STATUS_PDTC_ALLEVENTSTATUS > 0U)
    DEM_UDSSTATUS_GET_NV(udsStatusByte, EventId, 2U, Dem_EventStatusNvRamData.PDTC_BitArray);
    #else
    /* Default Value is 'Clear' */    
    #endif

    #if (DEM_UDS_STATUS_CDTC_ALLEVENTSTATUS > 0U) /* always not used */
    DEM_UDSSTATUS_GET_NV(udsStatusByte, EventId, 3U, Dem_EventStatusNvRamData.CDTC_BitArray);
    #else
    /* Default Value is 'Clear' */    
    #endif
    
    #if (DEM_UDS_STATUS_TNCSLC_ALLEVENTSTATUS > 0U)
    DEM_UDSSTATUS_GET_NV(udsStatusByte, EventId, 4U, Dem_EventStatusNvRamData.TNCSLC_BitArray);
    #else
    udsStatusByte |= DEM_UDS_STATUS_TNCSLC;    
    #endif
    
    #if (DEM_UDS_STATUS_TFSLC_ALLEVENTSTATUS > 0U)
    DEM_UDSSTATUS_GET_NV(udsStatusByte, EventId, 5U, Dem_EventStatusNvRamData.TFSLC_BitArray);
    #else
    /* Default Value is 'Clear' */    
    #endif  
    
    #if (DEM_UDS_STATUS_TNCTOC_ALLEVENTSTATUS > 0U) 
    DEM_UDSSTATUS_GET_NV(udsStatusByte, EventId, 6U, Dem_EventStatusNvRamData.TNCTOC_BitArray);
    #else
    udsStatusByte |= DEM_UDS_STATUS_TNCTOC;
    #endif
    
    #if (DEM_UDS_STATUS_WIR_ALLEVENTSTATUS > 0U)
    DEM_UDSSTATUS_GET_NV(udsStatusByte, EventId, 7U, Dem_EventStatusNvRamData.WIR_BitArray);
    #else
    /* Default Value is 'Clear' */
    #endif 
  }

  return udsStatusByte;
}

/******************************************************************************
* Function Name        : Dem_EvMem_SetUdsStatusByteToEvMemEntry
*
* Service ID           : None
*
* Description          : Stores the event status in the event memory entry
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant
*
* Input Parameters     : entry
*                        
* InOut parameter      : None
*
* Output Parameters    : None
*
* Return parameter     : uint8
*
* Preconditions        : None
*
* Remarks              : Global Variable(s)  :
*
*                        Function(s) invoked :
*
*****************************************************************************/
#if (DEM_NVRAMBLOCK_ACCESS_OPTIMIZATION_SUPPORT == STD_ON)
static FUNC(void, DEM_CODE) 
Dem_EvMem_SetUdsStatusByteToEvMemEntry(
  const Dem_EventIdType EventId,
  const Dem_DTCOriginType DTCOrigin,
  const Dem_NumOfEventMemoryEntryType memLoc)
{
  Dem_UdsStatusByteType EventStatusByteNew = Dem_AllEventStatusByte[EventId];
  Dem_EventMemoryEntryPtrType evMemEntry = NULL_PTR;

  /* Duplicated code for performance and runtime check(polyspace) */        
  if (DEM_DTC_ORIGIN_PRIMARY_MEMORY == DTCOrigin)  
  {
    evMemEntry = &Dem_PrimaryEventMemory[memLoc];
  }        
  #if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC > 0U)  
  else if (DEM_DTC_ORIGIN_SECONDARY_MEMORY == DTCOrigin) 
  {
    evMemEntry = &Dem_SecondaryEventMemory[memLoc];
  }
  #endif
  else
  {
    /* Do nothing */
  } 

  /* Dem_CombinedDtcPCType cbDTC = Dem_GetCbDTCByEventId(EventId); */        
  /* polyspace<RTE:UNR:Not a defect:No action planned>  Avoid the runtime error of the polyspace */          
  if (NULL_PTR != evMemEntry)
  {
    #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_TYPE1)      
    Dem_CombinedDtcPCType cbDTC = Dem_GetCbDTCByEventId(EventId);
    if (NULL_PTR != cbDTC)
    {    
      if (1U == cbDTC->ddNumberOfEvents)
      {
        evMemEntry->EventStatuByte[0] = EventStatusByteNew;      
      }
      /* > 1U */
      else
      {
        Dem_NumOfEventIdType index = 0U;
        Dem_NumOfEventIdType startPos = Dem_GetStartEventIdMapOfCbDTC(cbDTC);
        const Dem_NumOfEventIdType endPos = Dem_GetEndEventIdMapOfCbDTC(cbDTC);                
        while (startPos < endPos)
        {    
          if ((index < DEM_MAX_NUM_EVENTS_PER_DTC) && 
            (Dem_ListOfCombinedEvents[startPos] == EventId))
          {
            evMemEntry->EventStatuByte[index] = EventStatusByteNew;
            break;
          }
          ++index;
          ++startPos;
        }
      }
    }
    #else
    evMemEntry->EventStatuByte[0] = EventStatusByteNew;
    #endif
  }

}
#endif

/******************************************************************************
* Function Name        : Dem_EvMem_SetUdsStatusByteToNvData
*
* Service ID           : None
*
* Description          : Stores the event status in the Event Status Nv Data
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant
*
* Input Parameters     : entry
*                        
* InOut parameter      : None
*
* Output Parameters    : None
*
* Return parameter     : uint8
*
* Preconditions        : None
*
* Remarks              : Global Variable(s)  :
*
*                        Function(s) invoked :
*
*****************************************************************************/
FUNC(void, DEM_CODE) 
Dem_EvMem_SetUdsStatusByteToNvData(
  const Dem_EventIdType EventId)
{
  #if ((DEM_UDS_STATUS_TF_ALLEVENTSTATUS > 0U)     ||\
       (DEM_UDS_STATUS_TFTOC_ALLEVENTSTATUS > 0U)  ||\
       (DEM_UDS_STATUS_PDTC_ALLEVENTSTATUS > 0U)   ||\
       (DEM_UDS_STATUS_CDTC_ALLEVENTSTATUS > 0U)   ||\
       (DEM_UDS_STATUS_TNCSLC_ALLEVENTSTATUS > 0U) ||\
       (DEM_UDS_STATUS_TFSLC_ALLEVENTSTATUS > 0U)  ||\
       (DEM_UDS_STATUS_TNCTOC_ALLEVENTSTATUS > 0U) ||\
       (DEM_UDS_STATUS_WIR_ALLEVENTSTATUS > 0U))
  Dem_UdsStatusByteType EventStatusByteNew = Dem_AllEventStatusByte[EventId];
  #endif

  /*+------------------------------------+-+----------------------+
    | TestFailed                         |0| Ram->GeneralNvData   |
    +------------------------------------+-+----------------------+
    | TestFailedThisOperationCycle       |1| Ram->GeneralNvData   |
    +------------------------------------+-+----------------------+
    | PendingDTC                         |2| Ram->GeneralNvData   |
    +------------------------------------+-+----------------------+
    | ConfirmedDTC                       |3| N/A                  |
    +------------------------------------+-+----------------------+
    | TestNotCompletedSinceLastClear     |4| Ram->GeneralNvData   |
    +------------------------------------+-+----------------------+
    | TestFailedSinceLastClear           |5| Ram->GeneralNvData   |
    +------------------------------------+-+----------------------+
    | TestNotCompletedThisOperationCycle |6| Ram->GeneralNvData   |
    +------------------------------------+-+----------------------+
    | WarningIndicatorRequested          |7| Ram->GeneralNvData   |
    +------------------------------------+-+----------------------+*/ 
  #if (DEM_UDS_STATUS_TF_ALLEVENTSTATUS > 0U)
  DEM_UDSSTATUS_SYNC_NV(Dem_EventStatusNvRamData.TF_BitArray, EventId, EventStatusByteNew, DEM_UDS_STATUS_TF);    
  #endif   
 
  #if (DEM_UDS_STATUS_TFTOC_ALLEVENTSTATUS > 0U)
  DEM_UDSSTATUS_SYNC_NV(Dem_EventStatusNvRamData.TFTOC_BitArray, EventId, EventStatusByteNew, DEM_UDS_STATUS_TFTOC);    
  #endif
  
  #if (DEM_UDS_STATUS_PDTC_ALLEVENTSTATUS > 0U)
  DEM_UDSSTATUS_SYNC_NV(Dem_EventStatusNvRamData.PDTC_BitArray, EventId, EventStatusByteNew, DEM_UDS_STATUS_PDTC);    
  #endif

  #if (DEM_UDS_STATUS_CDTC_ALLEVENTSTATUS > 0U)
  DEM_UDSSTATUS_SYNC_NV(Dem_EventStatusNvRamData.CDTC_BitArray, EventId, EventStatusByteNew, DEM_UDS_STATUS_CDTC);    
  #endif
    
  #if (DEM_UDS_STATUS_TNCSLC_ALLEVENTSTATUS > 0U)
  DEM_UDSSTATUS_SYNC_NV(Dem_EventStatusNvRamData.TNCSLC_BitArray, EventId, EventStatusByteNew, DEM_UDS_STATUS_TNCSLC);        
  #endif
  
  #if (DEM_UDS_STATUS_TFSLC_ALLEVENTSTATUS > 0U)
  DEM_UDSSTATUS_SYNC_NV(Dem_EventStatusNvRamData.TFSLC_BitArray, EventId, EventStatusByteNew, DEM_UDS_STATUS_TFSLC);
  #endif  
  
  #if (DEM_UDS_STATUS_TNCTOC_ALLEVENTSTATUS > 0U)  
  DEM_UDSSTATUS_SYNC_NV(Dem_EventStatusNvRamData.TNCTOC_BitArray, EventId, EventStatusByteNew, DEM_UDS_STATUS_TNCTOC);            
  #endif
  
  #if (DEM_UDS_STATUS_WIR_ALLEVENTSTATUS > 0U)
  DEM_UDSSTATUS_SYNC_NV(Dem_EventStatusNvRamData.WIR_BitArray, EventId, EventStatusByteNew, DEM_UDS_STATUS_WIR);
  #endif  
}


/******************************************************************************
* Function Name        : Dem_EvMem_SetUdsStatusByteToNvData
*
* Service ID           : None
*
* Description          : Trigger the storage of event status on event status is changed
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant
*
* Input Parameters     : -
*                        
* InOut parameter      : -
*
* Output Parameters    : -
*
* Return parameter     : -
*
* Preconditions        : None
*
* Remarks              : 
*****************************************************************************/
FUNC(uint8, DEM_CODE) 
Dem_EvMem_TriggerNvDataStorage(
  const Dem_EventIdType EventId,
  const Dem_DTCOriginType DTCOrigin,
  const Dem_UdsStatusByteType EventStatusByteOld,
  uint8 NvDataBlkStatus,
  boolean EvMemEntryIsDirty,
  boolean EvStatusIsDirty)
{
  #if (DEM_DEV_ERROR_DETECT == STD_ON)  
  /* polyspace<RTE:UNR:Not a defect:No action planned>  Avoid the runtime error of the polyspace */        
  if ((DEM_NO_EVENT != EventId) && (EventId <= Dem_Number_Of_Events) )
  #endif
  {
    Dem_NumOfEventMemoryEntryType memLoc = Dem_EvMemToEventMap[EventId];            

    #if (DEM_NVRAMBLOCK_ACCESS_OPTIMIZATION_SUPPORT == STD_ON)    
    if ( memLoc < Dem_SizeOfEventMemory[DTCOrigin])
    {
      Dem_UdsStatusByteType mask;
      boolean storageTestFailed = DEM_GET_EVENTPARAM_STORAGE_TF(Dem_Event[EventId-1U].ParamFieldsA);
      
      if (DEM_TRUE == storageTestFailed)
      {
        mask = DEM_UDS_STATUS_MASK_EVMEM | ((Dem_UdsStatusByteType)DEM_UDS_STATUS_TF);
      }
      else /* FALSE */
      {
        mask = DEM_UDS_STATUS_MASK_EVMEM & ((Dem_UdsStatusByteType)(~(Dem_UdsStatusByteType)DEM_UDS_STATUS_TF));
      }      
      if (((EventStatusByteOld ^ Dem_AllEventStatusByte[EventId]) & mask) != 0U)
      {  
        Dem_EvMem_SetUdsStatusByteToEvMemEntry(EventId, DTCOrigin, memLoc);      
        EvMemEntryIsDirty = DEM_TRUE;
      }
    }
    else
    #endif
    {    
      /* if NvRamBlockAccessOptimizationSupport supports and displacement support is off, 
       * EventStatus is missing in the EventStatusNvBlock */    
      #if (DEM_UDS_STATUS_IN_EVENT_NVBLOCK == STD_ON)      
      const Dem_UdsStatusByteType EventStatusByteNew = Dem_AllEventStatusByte[EventId];

      Dem_UdsStatusByteType mask;
      boolean storageTestFailed = DEM_GET_EVENTPARAM_STORAGE_TF(Dem_Event[EventId-1U].ParamFieldsA);
      
      if (DEM_TRUE == storageTestFailed)
      {
        mask = DEM_UDS_STATUS_MASK_ALLEVENTSTATUS | ((Dem_UdsStatusByteType)DEM_UDS_STATUS_TF);
      }
      else /* FALSE */
      {
        mask = DEM_UDS_STATUS_MASK_ALLEVENTSTATUS & ((Dem_UdsStatusByteType)(~(Dem_UdsStatusByteType)DEM_UDS_STATUS_TF));
      }  
      
      #if (DEM_NVRAMBLOCK_ACCESS_OPTIMIZATION_SUPPORT == STD_ON)  /* if displacement is on and optimization is on*/
      /* if opimization is on  (status & mask) != 0U or (status & mask) is changed */
      if ( ((EventStatusByteNew & DEM_UDS_STATUS_TRIGGER_ALLEVENTSTATUS ) != 0U) ||
           (((EventStatusByteOld ^ EventStatusByteNew) & DEM_UDS_STATUS_TRIGGER_ALLEVENTSTATUS) != 0U) )
      #endif
      {
        if (((EventStatusByteOld ^ EventStatusByteNew) & mask) != 0U)
        {  
          Dem_EvMem_SetUdsStatusByteToNvData(EventId);
          EvStatusIsDirty = DEM_TRUE;
        }
      }
      #endif
    }

    if ((DEM_TRUE == EvMemEntryIsDirty) && ( memLoc < Dem_SizeOfEventMemory[DTCOrigin]))
    {
      Dem_EvMem_SetEvMemNvBlockStatus(DTCOrigin, memLoc, NvDataBlkStatus);
    }
    
    if (DEM_TRUE == EvStatusIsDirty)
    {
      Dem_EvMem_SetNonVolatieDataStatus(DEM_NVDATA_ALL_EVENT_STATUS_ID, NvDataBlkStatus);
    }
  }

  return NvDataBlkStatus;
}


/******************************************************************************
 * Function Name        : Dem_EvMem_ProcessEventRetention == 2
 *
 * Service ID           : None
 *
 * Description          : This function is used to update data and
 *                        to add new event in the event memory
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Reentrant
 *
 * Input Parameters     : event, DTC, DTCOrigin
 *
 * InOut parameter      : None
 *
 * Output Parameters    : EntryStored
 *
 * Return parameter     : Std_ReturnType
 *
 * Preconditions        : None
 *
 * Remarks              : Global Variable(s)  :
 *                        Dem_EventRelatedData
 *
 *                        Function(s) invoked :
 *                        Dem_GetConditionOfDTCRecordUpdate
 *                        Dem_EvMem_IncEventOccCounter
 *                        DEM_CLR_UDSSTATUSBYTE
 *                        Dem_StoreObdFFClass
 *                        CallbackEventDataChanged
 *****************************************************************************/
FUNC(Std_ReturnType, DEM_CODE) Dem_EvMem_ProcessEventRetention(
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
  P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA)  StatusDirty 
)
{        
  Std_ReturnType retVal = DEM_PROCESSEVENTRETENTION_FAILED;
  Dem_EventParameterPCType event = &Dem_Event[EventId-1U];     
  Dem_NumOfEventMemoryEntryType memLoc = Dem_EvMemToEventMap[EventId];
  Dem_EventMemoryEntryPtrType memEntry = NULL_PTR;      

  /* Already stored */
  if (memLoc < Dem_SizeOfEventMemory[DTCOrigin])
  { 
    #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_TYPE1)  
    uint8 dtcConfirmed  = (uint8)(DTCStatusOld & (Dem_UdsStatusByteType)DEM_UDS_STATUS_CDTC);
    #else /* combination is disabled or type 2 */
    uint8 dtcConfirmed  = (uint8)(EventStatusByteOld & (Dem_UdsStatusByteType)DEM_UDS_STATUS_CDTC);
    #endif        

    /* Duplicated code for performance and runtime check(polyspace) */        
    if (DEM_DTC_ORIGIN_PRIMARY_MEMORY == DTCOrigin)  
    {
      memEntry = &Dem_PrimaryEventMemory[memLoc];              
    }        
    #if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC > 0U)  
    else if (DEM_DTC_ORIGIN_SECONDARY_MEMORY == DTCOrigin) 
    {
      memEntry = &Dem_SecondaryEventMemory[memLoc]; 
    }
    #endif
    else
    {
      /* Do nothing */
    }
    
    if (NULL_PTR != memEntry) /* Always true */
    {       
      if (0U != memEntry->AgingCycleCounter)
      {
        memEntry->AgingCycleCounter = 0U;/* Init aging cycle counter */
        *EventDirty = DEM_TRUE;
      }
      
      #if (DEM_NUM_OF_ENABLE_TRIP_COUNTER > 1U)  
      if ((event->ucEventFailureThreshold > 1U) && (0U == dtcConfirmed))
      {               
        #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_TYPE1)  
        uint8 testFailedThisOpCycle = (uint8)(DTCStatusOld & (Dem_UdsStatusByteType) DEM_UDS_STATUS_TFTOC);
        #else /* combination is disabled or type 2 */
        uint8 testFailedThisOpCycle = (uint8)(EventStatusByteOld & (Dem_UdsStatusByteType) DEM_UDS_STATUS_TFTOC);
        #endif        

        if (0U == testFailedThisOpCycle)
        {
        
          if (memEntry->FailureCycleCounter < (uint8)0xFF)
          {
            ++memEntry->FailureCycleCounter;            
            *EventDirty = DEM_TRUE;/* minimum of  memEntry->FailureCycleCounter is 1 */
          }
          /* EventFailureThreshold is more than 2 or equal to 2 */
          if (memEntry->FailureCycleCounter >= event->ucEventFailureThreshold)
          {
            SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();             
            DEM_SET_UDSSTATUSBYTE(memEntry->EventIdRef, DEM_UDS_STATUS_CDTC);
            SchM_Exit_Dem_REQUEST_STATUS_PROTECTION(); 
            
            memEntry->FailureCycleCounter = 0U;
            #if (DEM_DCM_RPT_FAILEDCONFIRMEDDTCINFO_USED == STD_ON)
            *StatusDirty |= Dem_EvMem_SetFirstLastConfirmedDTC(DTCOrigin, DTC);
            #endif
            *EventDirty = DEM_TRUE;
            
            dtcConfirmed = (uint8)DEM_TRUE;
          }  
        }
      } 
      #endif

      if (memEntry->EventOccurrenceCounter  < (uint8)DEM_OCC_MAX)
      {
        /* [SWS_Dem_00524] If the con?guration parameter DemOccurrenceCounterPro-
         * cessing (refer to DemGeneral) is DEM_PROCESS_OCCCTR_TF , the Dem module
         * shall increment the occurrence counter by one, triggered by each event status bit 0
         * (TestFailed) transition from 0 to 1, if the related event is already stored in the event
         * memory.
         *
         * [SWS_Dem_00580] 
         * If the con?guration parameter DemOccurrenceCounterPro-
         * cessing (refer to DemGeneral) is DEM_PROCESS_OCCCTR_CDTC, the Dem module
         * shall increment the occurrence counter by one, triggered by each UDS DTC status bit
         * 0 (TestFailed) transition from 0 to 1, if the related event is already stored in the event
         * memory and the event Status bit 3 (ConfirmedDTC) is equal to 1 (refer to chapter 0). 
         */      
        #if (DEM_OCCCTR_PROCESSING == DEM_PROCESS_OCCCTR_CDTC)      
        if (0U != dtcConfirmed)
        #endif        
        {
          ++memEntry->EventOccurrenceCounter;
          *EventDirty = DEM_TRUE;
        }
      }      
      /**********************************************************************************
       *             Check WarningIndicatorOnCondition                                  *
       * [1] @RfC 63657, use  DemOperationCycleRef                                      *
       * [2] @SWS_Dem_01052, @SWS_Dem_01051 : Combined DTC's ComfirmedDTC == 1          *
       * [3] New Event or TFTOC changed from 0 to 1 (threshold != 0)                    *
       * [4] Indicator Failure Counter should be increased by 1 on each operation cycle *
       **********************************************************************************/
      if ((event->ucNumberofIndicator > 0U) && (0U != dtcConfirmed))
      {
        *StatusDirty |= Dem_ActivateIndicatorOnEventFailed(
          EventId, (uint8)(EventStatusByteOld & (Dem_UdsStatusByteType) DEM_UDS_STATUS_TFTOC));
      }

      /* Dem672_Conf, Dem663_Conf
       * SWS_Dem_00270 : 
       * [1] New and other events including their associated freeze frames and extended data
       *     records can still be added to and changed in the event memory as long as space is available.
       * [2] The function Dem_DcmDisableDTCRecordUpdate does not affect the DTC status information update.*/      
      #if (DEM_SIZE_OF_EVENT_DATA > 0U) 
      if (event->e_PointToData < Dem_Num_Of_EventRelatedData)      
      {
        if (DEM_CONDITIONDTCRECUP_DISABLED_DTC != Dem_GetConditionOfDTCRecordUpdate(DTC, DTCOrigin)) 
        {
          if (DEM_TRUE == Dem_StoreEventRelatedData(&Dem_EventRelatedData[event->e_PointToData], memEntry))
          {
            *EventDirty = DEM_TRUE;
          }
        }          
      }
      #endif

      #if (DEM_EVMEM_TIMESTAMP_USED == STD_ON)
      if (Dem_MaxTimeStamp[DTCOrigin] != memEntry->TimeStamp)
      {
        memEntry->TimeStamp = Dem_EvMem_FindNewTimeStamp(DTCOrigin);
      }
      #endif

      #if (DEM_J1939_SUPPORT == STD_ON)
      /* [SWS_Dem_00787] If an 'stored event' gets re-qualified as failed 
       * (UDS DTC status bit 0 changes from 0 to 1) and a respective event memory entry exists, 
       * the Dem module shall update the chronological order of the event storage by setting the
       * particular event as most recent event memory entry. */
      Dem_EvMem_DelChronologicalOrder(DTCOrigin, memLoc);
      Dem_EvMem_AddNewChronologicalOrder(DTCOrigin, memLoc);
      #endif

      retVal = DEM_PROCESSEVENTRETENTION_OK; 
    }
  } 
  else /** New Event */
  {
    Dem_NumOfEventMemoryEntryType numOfMemEntries = Dem_SizeOfEventMemory[DTCOrigin];
    /* Duplicated code for performance and runtime check(polyspace) */
    /* No need the memory protection */
    if (Dem_NumOfStoredEvtMemEntryies[DTCOrigin] < numOfMemEntries)
    {
      if (DEM_DTC_ORIGIN_PRIMARY_MEMORY == DTCOrigin)
      {
        for (memLoc = 0U; memLoc < numOfMemEntries; memLoc++)    
        {
          SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();
          if(DEM_NO_EVENT == Dem_PrimaryEventMemory[memLoc].EventIdRef)
          {
            memEntry = &Dem_PrimaryEventMemory[memLoc];                
            memEntry->EventIdRef = EventId; /* Set EventId */
            SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();                
            break;
          }
          else
          {
            SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
          }
        }
      }
      #if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC > 0U)  
      else if (DEM_DTC_ORIGIN_SECONDARY_MEMORY == DTCOrigin) 
      {
        for (memLoc = 0U; memLoc < numOfMemEntries; memLoc++)    
        {
          SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();            
          if(DEM_NO_EVENT == Dem_SecondaryEventMemory[memLoc].EventIdRef)
          {
            memEntry = &Dem_SecondaryEventMemory[memLoc];                 
            memEntry->EventIdRef = EventId;  /* Set EventId */
            SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
            break;
          }
          else
          {
            SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
          }              
        }
      }
      #endif
      else
      {
        /* retVal = DEM_PROCESSEVENTRETENTION_FAILED; */
      }        
    }        
    #if (DEM_EVENT_DISPLACEMENT_SUPPORT == STD_ON)          
    else  /* event memory is full */
    {        
      memLoc = Dem_EvMem_FindEntryWithLowestPriority(EventId, event->ucEventPriority, DTCOrigin);
      if (memLoc < Dem_SizeOfEventMemory[DTCOrigin])
      {
        /* Duplicated code for performance and runtime check(polyspace) */        
        if (DEM_DTC_ORIGIN_PRIMARY_MEMORY == DTCOrigin)  
        {
          memEntry = &Dem_PrimaryEventMemory[memLoc];
        }        
        #if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC > 0U)  
        else if (DEM_DTC_ORIGIN_SECONDARY_MEMORY == DTCOrigin) 
        {
          memEntry = &Dem_SecondaryEventMemory[memLoc];
        }
        #endif
        else
        {
          /* Do nothing */
        } 
      }
    }
    #endif

    /* New Entry */
    if (NULL_PTR != memEntry)
    { 
      #if (DEM_EVMEM_TIMESTAMP_USED == STD_ON)
      memEntry->TimeStamp = Dem_EvMem_FindNewTimeStamp(DTCOrigin);
      if (Dem_MaxTimeStamp[DTCOrigin] < memEntry->TimeStamp)
      {
        Dem_MaxTimeStamp[DTCOrigin] = memEntry->TimeStamp;
      }          
      #endif

      #if (DEM_NVRAMBLOCK_ACCESS_OPTIMIZATION_SUPPORT == STD_ON)
      {
        uint16 i;
        for (i = 0; i < DEM_MAX_NUM_EVENTS_PER_DTC; i++)
        {
          memEntry->EventStatuByte[i] = 0x0U;
        }   
      }
      #endif      
      
      /* Dem523: The Dem module shall initialize the occurrence counter with
       * the value one if the related event is entered in the respective event memory. */
      memEntry->EventOccurrenceCounter = 1U;
      /* Initialize the failure counter related ConfirmedDTC */
      #if (DEM_NUM_OF_ENABLE_TRIP_COUNTER > 1U)
      memEntry->FailureCycleCounter = 0U;
      #endif
      memEntry->AgingCycleCounter = 0U;
      
      #if (DEM_SIZE_OF_EVENT_DATA > 0u) 
      {
        uint32 idx;
        for (idx = 0; idx < DEM_SIZE_OF_EVENT_DATA; idx++)
        {
          memEntry->data[idx] = DEM_SET_BYTE;
        }
        #if (DEM_SIZE_OF_FREEZEFRAME > 0U)
        memEntry->IndexOfFFRecords = 0U;
        #endif           
        /* Dem672_Conf, Dem663_Conf: */           
        if (event->e_PointToData < Dem_Num_Of_EventRelatedData)
        {
          (void)Dem_StoreEventRelatedData(&Dem_EventRelatedData[event->e_PointToData], memEntry);
        }          
      }
      #endif  

      SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();   
      Dem_EvMem_AddMemLocInEvMemMap(EventId, DTCOrigin, memLoc);                    
      SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();   

      #if (DEM_J1939_SUPPORT == STD_ON)
      Dem_EvMem_AddNewChronologicalOrder(DTCOrigin, memLoc);
      #endif

      /*******************************************************************
       *                      ConfirmedDTC bit = 1                       *            
       * [1] @ISO 14229:2013, 373p, Figure D.9                           *
       * [2] @RfC 59420, Remove the DemEventFailureCycleRef              *
       * [3] new event or TestFailedThisOperationCycle from 0 to 1       *
       *******************************************************************/
      #if (DEM_NUM_OF_ENABLE_TRIP_COUNTER > 1U)  
      /* 
       * Confirmation threshold [ "Blank" == one ]
       *
       * The ConfirmedDTC bit is set (change from 0 to 1) at the same time as the pendingDTC bit 
       * because this example is for a non emissions-related server/ECU with a confirmation threshold of 1.
       */
      if (event->ucEventFailureThreshold > 1U)
      {           
        memEntry->FailureCycleCounter = 1U; /* Because new event */
      }          
      else
      #endif
      {
        SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();             
        DEM_SET_UDSSTATUSBYTE(EventId, DEM_UDS_STATUS_CDTC);
        SchM_Exit_Dem_REQUEST_STATUS_PROTECTION(); 

        #if (DEM_DCM_RPT_FAILEDCONFIRMEDDTCINFO_USED == STD_ON)
        *StatusDirty |= Dem_EvMem_SetFirstLastConfirmedDTC(DTCOrigin, DTC);
        #endif

        /* New Event and Event is comfirmed */
        if (event->ucNumberofIndicator > 0U) 
        {
          *StatusDirty |= Dem_ActivateIndicatorOnEventFailed(EventId, (uint8)0U); /* 0U == new event */
        }            
      }
      *EventDirty = DEM_TRUE;

      retVal = DEM_PROCESSEVENTRETENTION_OK; 
    }
    else
    {
      retVal = DEM_PROCESSEVENTRETENTION_FULL;
    }
  }      
  
  return retVal;
}
  
/******************************************************************************
* Function Name        : Dem_EvMem_EventIsImmediateStorage
*
* Service ID           : None
*
* Description          : Checks whether Event supports immediate storage or not
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant
*
* Input Parameters     : DTCOrigin, MemLocation, EventId
*                        
* InOut parameter      : None
*
* Output Parameters    : None
*
* Return parameter     : uint8
*
* Preconditions        : This function shall be called when DTC supports immediate-storage
*
* Remarks              : 
*
*****************************************************************************/
FUNC(uint8, DEM_CODE) Dem_EvMem_EventIsImmediateStorage(
  Dem_DTCOriginType DTCOrigin,  
  Dem_EventIdType EventId)
{
  uint8  support = DEM_EVMEM_STATUS_DIRTY | DEM_EVMEM_STATUS_TRIGGER_NVM;

  Dem_NumOfEventMemoryEntryType memLoc = Dem_EvMemToEventMap[EventId];
  
  if (memLoc < Dem_SizeOfEventMemory[DTCOrigin])
  {  
    Dem_EventMemoryEntryPtrType memEntry;
    /* @IF_REQ : if occ is 255 and limit is 255 ? */
    /* [SWS_Dem_00552] 
     * If immediate nonvolatile storage is enabled for a specific DTC,
     * the Dem module shall not trigger further immediate write operations to NVRAM for this
     * DTC, if its occurrence counter has reached the threshold defined by the configuration
     * parameter DemImmediateNvStorageLimit */                  

    switch(DTCOrigin) {
    case DEM_DTC_ORIGIN_PRIMARY_MEMORY:
      memEntry = &Dem_PrimaryEventMemory[memLoc];      
      if (memEntry->EventOccurrenceCounter >= Dem_Immdiate_Nv_Storage_Limit)
      {
        support = DEM_EVMEM_STATUS_DIRTY;  
      }      
      break;
    #if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC > 0U)        
    case DEM_DTC_ORIGIN_SECONDARY_MEMORY:
      memEntry = &Dem_SecondaryEventMemory[memLoc];      
      if (memEntry->EventOccurrenceCounter >= Dem_Immdiate_Nv_Storage_Limit)
      {
        support = DEM_EVMEM_STATUS_DIRTY;  
      }        

      break;
    #endif
    /* polyspace<RTE:UNR:Not a defect:No action planned> Default switch clause is unreachable. switch-expression. */
    default:
      break;
    }  
  }


  return support;
}


/*******************************************************************************
 ** Function Name       : Dem_EvMem_ClearMemLocInEvMemMap
 **
 ** Service ID          : None
 **
 ** Description         : clear event memory index into the event memory map
 **
 ** Sync/Async          : Synchronous
 **
 ** Re-entrancy         : Reentrant
 **
 ** Input Parameters    : EventId, DTCOrigin, MemLocation
 **
 ** InOut parameter     : None
 **
 ** Output Parameters   : None
 **
 ** Return parameter    : void
 **
 ** Preconditions       : None
 **
 ** Remarks             : 
 *******************************************************************************/
FUNC(void, DEM_CODE) Dem_EvMem_ClearMemLocInEvMemMap(
  Dem_EventIdType EventId,
  Dem_DTCOriginType DTCOrigin
  #if (DEM_EVMEM_TIMESTAMP_USED == STD_ON)  
  ,Dem_EventMemoryEntryPtrType EvMemEt
  #endif
)
{
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_TYPE1)
  P2CONST(Dem_CombinedDtcType, AUTOMATIC,  DEM_VAR) cbDTC = Dem_GetCbDTCByEventId(EventId);    
  if (NULL_PTR != cbDTC)
  {
    if (1U == cbDTC->ddNumberOfEvents)
    {
      Dem_EvMemToEventMap[EventId] = DEM_NO_EVMEM_ENTRY;
    }
    else
    {
      Dem_NumOfEventIdType startPos = Dem_GetStartEventIdMapOfCbDTC(cbDTC);
      const Dem_NumOfEventIdType endPos = Dem_GetEndEventIdMapOfCbDTC(cbDTC);                
      for (;startPos < endPos; startPos++)
      {
        Dem_EvMemToEventMap[Dem_ListOfCombinedEvents[startPos]] = DEM_NO_EVMEM_ENTRY;
      }
    }
  }
  #else  
  Dem_EvMemToEventMap[EventId] = DEM_NO_EVMEM_ENTRY;
  #endif

  Dem_EvClearProcState(EventId, DEM_EVPROCSTATE_EVENT_STORED);  
  if (Dem_NumOfStoredEvtMemEntryies[DTCOrigin] > 0U)
  {
    Dem_NumOfStoredEvtMemEntryies[DTCOrigin]--;
  }

  #if (DEM_EVMEM_TIMESTAMP_USED == STD_ON)
  if (NULL_PTR != EvMemEt)
  {
    if (Dem_MaxTimeStamp[DTCOrigin] == EvMemEt->TimeStamp)
    {
      if (Dem_MaxTimeStamp[DTCOrigin] > 0U)
      {
        Dem_MaxTimeStamp[DTCOrigin]--;
      }
    } 
  }
  #endif  
}


/*******************************************************************************
 ** Function Name       : Dem_EvMem_AddMemLocInEvMemMap
 **
 ** Service ID          : None
 **
 ** Description         : Insert new event memory index into the event memory-
 **                       Map
 **
 ** Sync/Async          : Synchronous
 **
 ** Re-entrancy         : Reentrant
 **
 ** Input Parameters    : EventId, DTCOrigin, MemLocation
 **
 ** InOut parameter     : None
 **
 ** Output Parameters   : None
 **
 ** Return parameter    : void
 **
 ** Preconditions       : None
 **
 ** Remarks             : 
 *******************************************************************************/
FUNC(void, DEM_CODE) Dem_EvMem_AddMemLocInEvMemMap(
  Dem_EventIdType EventId,
  Dem_DTCOriginType DTCOrigin,
  Dem_NumOfEventMemoryEntryType MemLocation)
{
  #if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_TYPE1)
  P2CONST(Dem_CombinedDtcType, AUTOMATIC,  DEM_VAR) cbDTC = Dem_GetCbDTCByEventId(EventId);    
  if (NULL_PTR != cbDTC)
  {  
    if (1U == cbDTC->ddNumberOfEvents)
    {
      Dem_EvMemToEventMap[EventId] = MemLocation;
    }
    else
    {
      Dem_NumOfEventIdType startPos = Dem_GetStartEventIdMapOfCbDTC(cbDTC);
      const Dem_NumOfEventIdType endPos = Dem_GetEndEventIdMapOfCbDTC(cbDTC);                
      for (;startPos < endPos; startPos++)
      {
        Dem_EvMemToEventMap[Dem_ListOfCombinedEvents[startPos]] = MemLocation;
      }
    }
  }
  #else  
  Dem_EvMemToEventMap[EventId] = MemLocation;
  #endif

  Dem_EvSetProcState(EventId, DEM_EVPROCSTATE_EVENT_STORED);  
  if (Dem_NumOfStoredEvtMemEntryies[DTCOrigin] < DEM_NO_EVMEM_ENTRY)
  {
    Dem_NumOfStoredEvtMemEntryies[DTCOrigin]++;  
  }
}



/******************************************************************************
* Function Name        : Dem_EvMem_FindEntry
*
* Service ID           : None
*
* Description          : Find the stored event in the event memory
*
* Sync/Async           : Synchronous
*
* Re-entrancy          : Reentrant(Not same event Id)
*
* Input Parameters     : EventId, DTCOrigin, MemLocation
*                        
* InOut parameter      : None
*
* Output Parameters    : None
*
* Return parameter     : pointer for event memory entry
*
* Preconditions        : None
*
* Remarks              : 
*
*****************************************************************************/
FUNC(Dem_EventMemoryEntryPtrType, DEM_CODE) Dem_EvMem_FindEntry(
  Dem_EventIdType EventId,
  Dem_DTCOriginType DTCOrigin)
{  
  Dem_NumOfEventMemoryEntryType memLoc = DEM_NO_EVMEM_ENTRY;
  Dem_EventMemoryEntryPtrType memEntry = NULL_PTR;

  SchM_Enter_Dem_REQUEST_STATUS_PROTECTION();

  if (DEM_DTC_ORIGIN_PRIMARY_MEMORY == DTCOrigin)  
  {
    memLoc = Dem_EvMemToEventMap[EventId];
    if (memLoc < Dem_SizeOfEventMemory[DTCOrigin])
    {      
      memEntry = &Dem_PrimaryEventMemory[memLoc];               
    }
  }
  
  #if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC > 0U)  
  else if (DEM_DTC_ORIGIN_SECONDARY_MEMORY == DTCOrigin) 
  {
    memLoc = Dem_EvMemToEventMap[EventId];
    if (memLoc < Dem_SizeOfEventMemory[DTCOrigin])
    {  
      memEntry = &Dem_SecondaryEventMemory[memLoc]; 
    }
  }
  #endif
  else
  {
    /* Do nothing */
  }
  
  SchM_Exit_Dem_REQUEST_STATUS_PROTECTION();
  
  return memEntry;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

