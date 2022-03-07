/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_Config.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Event Manager                              **
**                                                                            **
**  PURPOSE   : Declares the global variables for configurable values         **
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
** 1.0.2    20-07-2017    EunKyung.Kim    Changes made As per Redmine #9294   **
**                                                                            **
** 1.0.2    16-05-2016    Youngjin Yun    Changes made As per Redmine #1164   **
**                                                                            **
** 1.0.1    16-04-2015    Sungeol Baek    Changes made As per Reminde #2171   **
**                                                                            **
** 1.0.0    14-01-2014    Youngjin Yun    Initial Version                     **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Dem.h" 
#include "Dem_Ram.h"    /* DEM Ram Header File */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"        /* Det Module Header File */
#endif

#include "NvM.h"              /* NVRAM manager symbols Header File */

#include "SchM_Dem.h"   /* Basic s/w module Scheduler symbols Header File */
#include "Rte_Dem.h"
#include "Dem_NvData.h"
#include "Dem_Config.h"
#include "Dem_Event.h"
#include "Dem_EventMemory.h"
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#ifdef DEM_MAX_SIZE_OF_PID_DATAELEMENT
const Dem_SizeOfPidDataElementType Dem_Max_Size_Of_Pid_DataElement = DEM_MAX_SIZE_OF_PID_DATAELEMENT;
#endif

#ifdef DEM_MAX_NUMBER_OF_PID_RECDS
const Dem_NumOfPidClassType Dem_Max_Number_Of_PID_Recds = DEM_MAX_NUMBER_OF_PID_RECDS;
#endif

#ifdef DEM_MAX_NUMBER_OF_PID_DATAELEMENT
const Dem_NumOfPidDataElementType Dem_Max_Number_Of_Pid_DataElement = DEM_MAX_NUMBER_OF_PID_DATAELEMENT;
#endif

/* Configuration Range : 1 ~ 256 , but 255  */
#ifdef DEM_NUMBER_OPERATION_CYCLES
const uint8  Dem_Num_Operation_Cycles = DEM_NUMBER_OPERATION_CYCLES;
#endif

#if (DEM_DEBOUNCE_TIME_SUPPORT == STD_ON)
const Dem_NumOfDebounceType Dem_Number_Of_Pre_Debounce_Time = DEM_NUMBER_OF_PRE_DEBOUNCE_TIME;
#endif

#ifdef DEM_NUMBER_OF_PRE_DEBOUNCE_COUNTER
const Dem_NumOfDebounceType Dem_Number_Of_Pre_Debounce_Counter = DEM_NUMBER_OF_PRE_DEBOUNCE_COUNTER;
#endif

#ifdef DEM_MAX_NUM_GRP_DTC
const uint8  Dem_Max_Num_Grp_DTC = DEM_MAX_NUM_GRP_DTC;
#endif

#ifdef DEM_NUMBER_OF_INDICATORS
const Dem_NumOfIndicatorAttributeType  Dem_Number_Of_Indicators = DEM_NUMBER_OF_INDICATORS;
#else
const Dem_NumOfIndicatorAttributeType  Dem_Number_Of_Indicators = 0;
#endif

#ifdef DEM_NUM_OF_INDICATOR_ATTRIBUTE_STATUS
const Dem_NumOfIndicatorAttributeType  Dem_Num_Of_Indicator_Attribute_Status = DEM_NUM_OF_INDICATOR_ATTRIBUTE_STATUS;
#endif





#ifdef DEM_MAX_NUM_OF_DTC_STAT_CHNG_FCTS
const uint32  Dem_Max_Num_Of_DTC_Stat_Chng_Fcts = DEM_MAX_NUM_OF_DTC_STAT_CHNG_FCTS;
#endif

#ifdef DEM_NUMBER_OF_EVENTS
const Dem_EventIdType Dem_Number_Of_Events = DEM_NUMBER_OF_EVENTS; 
#endif

#ifdef DEM_BSW_ERROR_BUFFER_SIZE
const uint8  Dem_BSW_Error_Buffer_Size = DEM_BSW_ERROR_BUFFER_SIZE;
#endif

#ifdef DEM_STATUS_AVAILABILITY_MASK
const uint8  Dem_Status_Availability_Mask = DEM_STATUS_AVAILABILITY_MASK;
#endif

#ifdef DEM_IMMEDIATE_NV_STORAGE_LIMIT
const uint8  Dem_Immdiate_Nv_Storage_Limit = DEM_IMMEDIATE_NV_STORAGE_LIMIT;
#endif

#ifdef DEM_MAX_NUMBER_EVENT_ENTRY_MIR
const uint8 Dem_Max_Number_Event_Entry_Mir = DEM_MAX_NUMBER_EVENT_ENTRY_MIR;
#endif

#ifdef DEM_MAX_NUMBER_EVENT_ENTRY_PRI
const uint8 Dem_Max_Number_Event_Entry_Pri = DEM_MAX_NUMBER_EVENT_ENTRY_PRI;
#endif

#ifdef DEM_MAX_NUMBER_EVENT_ENTRY_SEC
const uint8 Dem_Max_Number_Event_Entry_Sec = DEM_MAX_NUMBER_EVENT_ENTRY_SEC;
#endif

#ifdef DEM_MAX_NUMBER_EVENT_ENTRY_PER
const uint8 Dem_Max_Number_Event_Entry_Per = DEM_MAX_NUMBER_EVENT_ENTRY_PER;
#endif

#ifdef DEM_TASK_TIME
const uint16 Dem_Task_Time = DEM_TASK_TIME;
#endif

#ifdef DEM_MAX_NUMBER_OF_DTC
const Dem_NumOfDTCValueType Dem_Max_Number_Of_DTC = DEM_MAX_NUMBER_OF_DTC;
#endif

#ifdef DEM_MIL_INDICATORID
const uint8 Dem_MIL_IndicatorId = DEM_MIL_INDICATORID;
#endif

#ifdef DEM_PID01_BYTEB_LOWER_NIBBLE
const uint8 DEM_PID01_ByteB_Lower_Nibble = DEM_PID01_BYTEB_LOWER_NIBBLE;
#endif

#ifdef DEM_PID01_BYTEC_SPARK
const uint8 DemM_PID01_ByteC_Spark = DEM_PID01_BYTEC_SPARK;
#endif

#ifdef DEM_PID01_BYTEC_COMPRESSION
const uint8 Dem_PID01_ByteC_Compression = DEM_PID01_BYTEC_COMPRESSION;
#endif


#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U)
const Dem_NumOfPrestoredFFType Dem_Max_Number_Prestored_FF = DEM_MAX_NUMBER_PRESTORED_FF;
const uint32 Dem_Size_Of_Prestored_FF = DEM_SIZE_OF_PRESTORED_FF;
#endif 


#if (DEM_ENABLE_CONDITION_SUPPORT == STD_ON)
const uint8 Dem_Num_Enable_Condition = DEM_NUMBER_ENABLE_CONDITION;
#endif

/* Configuration Range : 0 ~ 255  */
#if (DEM_STORAGE_CONDITION_SUPPORT == STD_ON)
const uint16  Dem_Number_Storage_Condition = DEM_NUMBER_STORAGE_CONDITION;
#endif

#ifdef DEM_NUM_OF_PRIMARY_EVENTMEMORY_NVBLOCKID 
const Dem_NumOfEventMemoryEntryType Dem_Num_Of_Primary_EventMemory_NvBlockId = DEM_NUM_OF_PRIMARY_EVENTMEMORY_NVBLOCKID;
#endif

#ifdef DEM_NUM_OF_SECONDARY_EVENTMEMORY_NVBLOCKID
const Dem_NumOfEventMemoryEntryType Dem_Num_Of_Secondary_EventMemory_NvBlockId = DEM_NUM_OF_SECONDARY_EVENTMEMORY_NVBLOCKID;
#endif



#ifdef DEM_NUM_OF_EVENTRELATEDDATA
const Dem_NumOfEventRelatedDataType Dem_Num_Of_EventRelatedData = DEM_NUM_OF_EVENTRELATEDDATA;
#else
const Dem_NumOfEventRelatedDataType Dem_Num_Of_EventRelatedData = 0U;
#endif

#ifdef DEM_NUMBER_OF_PRE_DEBOUNCE_MONITOR_INTERNAL
const Dem_NumOfDebounceType Dem_Number_Of_Pre_Debounce_Monitor_Internal = DEM_NUMBER_OF_PRE_DEBOUNCE_MONITOR_INTERNAL;
#else
const Dem_NumOfDebounceType Dem_Number_Of_Pre_Debounce_Monitor_Internal = 0U;
#endif

#ifdef DEM_AGING_REQUIERES_TESTED_CYCLE
const boolean Dem_CfgAgingRequieresTestedCycle = (boolean)DEM_AGING_REQUIERES_TESTED_CYCLE;
#endif



#ifdef DEM_OPERATION_CYCLE_STATUS_STORAGE
const uint8 Dem_Operation_Cycle_Status_Storage = DEM_OPERATION_CYCLE_STATUS_STORAGE;
#endif


#if(DEM_NUMBER_OF_INDICATORS == DEM_ZERO)
P2CONST(Dem_IndicatorAttributeType,AUTOMATIC, DEM_CONST) Dem_GaaIndicatorList = NULL_PTR;
#endif

#ifdef DEM_MAX_LISTOFCOMBINEDEVENTS
const uint16  Dem_Max_ListOfCombinedEvents = DEM_MAX_LISTOFCOMBINEDEVENTS;
#endif 

#ifdef DEM_NUM_OF_FREEZEFRAMECLASS
const Dem_NumOfFreezeFrameClassType Dem_Num_Of_FreezeFrameClass = DEM_NUM_OF_FREEZEFRAMECLASS;
#endif

#ifdef DEM_NUM_OF_EXTENDEDDATACLASS
const Dem_NumOfExtendedDataClassType Dem_Num_Of_ExtendedDataClass = DEM_NUM_OF_EXTENDEDDATACLASS;
#endif

#ifdef DEM_MAX_LISTOFFFRECORDNUMBERS
const uint16 Dem_Max_ListOfFFRecordNumbers = DEM_MAX_LISTOFFFRECORDNUMBERS;
#endif

#ifdef DEM_NUM_OF_EXTENDEDDATARECORDCLASS
const uint16 Dem_Num_Of_ExtendedDataRecordClass = DEM_NUM_OF_EXTENDEDDATARECORDCLASS;
#endif 

#ifdef DEM_SIZE_OF_EVENT_DATA
const uint32 Dem_Size_Of_Event_Data = DEM_SIZE_OF_EVENT_DATA;
#endif 

#ifdef DEM_SIZE_OF_EXTENDED_DATA
const uint32 Dem_Size_Of_Extended_Data = DEM_SIZE_OF_EXTENDED_DATA;
#endif

#ifdef DEM_MAX_LISTOFEDRECORDCLASSINDEX
const uint16 Dem_Max_ListOfEDRecordClassIndex = DEM_MAX_LISTOFEDRECORDCLASSINDEX;
#endif

#ifdef DEM_MAX_LISTOFDIDCLASSINDEX
const uint16 Dem_Max_ListOfDidClassIndex = DEM_MAX_LISTOFDIDCLASSINDEX;
#endif

#ifdef DEM_MAX_LISTOFDATAELEMENTCLASSINDEX
const uint16 Dem_Max_ListOfDataElementClassIndex = DEM_MAX_LISTOFDATAELEMENTCLASSINDEX;
#endif

#ifdef DEM_MAX_NUM_OF_EVENT_STAT_CHNG_FCTS
const Dem_NumOfEvtStatFctsType Dem_Max_ListOfEvtStatusChangedFctPtr = DEM_MAX_NUM_OF_EVENT_STAT_CHNG_FCTS;
#endif

#ifdef DEM_MAX_LISTOFENABLECONDITIONID
const uint8 Dem_Max_ListOfEnableConditionId = DEM_MAX_LISTOFENABLECONDITIONID;
#endif

#ifdef DEM_MAX_LISTOFSTORAGECONDITIONID
const uint8 Dem_Max_ListOfStorageConditionId = DEM_MAX_LISTOFSTORAGECONDITIONID;
#endif

#ifdef DEM_NUM_OF_HEALING_COUNTER
const Dem_NumOfIndicatorAttributeType Dem_Num_Of_Healing_Counter = DEM_NUM_OF_HEALING_COUNTER;
#endif

#ifdef DEM_NUM_OF_FAILURE_COUNTER
const Dem_NumOfIndicatorAttributeType Dem_Num_Of_Failure_Counter = DEM_NUM_OF_FAILURE_COUNTER;
#endif

/*
DEM_NUM_OF_DIDCLASS
DEM_NUM_OF_DATAELEMENTCLASS
*/

const Dem_DTCTranslationFormatType Dem_Type_Of_Dtc_Supported = DEM_TYPE_OF_DTC_SUPPORTED;

const boolean Dem_Status_Bit_Storage_TestFailed = DEM_STATUS_BIT_STORAGE_TESTFAILED; 


const boolean Dem_Aging_Requieres_Tested_Cycle = DEM_AGING_REQUIERES_TESTED_CYCLE;
const boolean Dem_Healing_Requieres_Tested_Cycle = DEM_HEALING_REQUIERES_TESTED_CYCLE;

#if (DEM_UDS_STATUS_IN_EVENT_NVBLOCK == STD_ON)
const boolean Dem_Uds_Status_In_Event_NvBlock = DEM_TRUE;
#else
const boolean Dem_Uds_Status_In_Event_NvBlock = DEM_FALSE;
#endif


#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
 **                   Static Function Definitions                             **
 *******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

#define DEM_START_SEC_CODE
#include "MemMap.h"



/*******************************************************************************
** Function Name        : Dem_SetEventIdOfPrestoredFF
**                                                                            
** Service ID           : None                                                
**                                                                            
** Description          : Set the Event identifier of a specific entry to 
**                        EventId.
**                                                                            
** Sync/Async           : Synchronous                                         
**                                                                            
** Re-entrancy          : Reentrant                                           
**                                                                            
** Input Parameters     : BufferIndex,EventId
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
#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U)
FUNC(void, DEM_CODE) 
Dem_SetEventIdOfPrestoredFF(
  Dem_NumOfPrestoredFFType BufferIndex,
  const Dem_EventIdType EventId)
{
  Dem_GaaPrestoreBuffer[BufferIndex].EventIdRef = EventId;
}



/*******************************************************************************
** Function Name        : Dem_GetBufferOfPrestoredFF                          
**                                                                            
** Service ID           : None                                                
**                                                                            
** Description          : It is used to get the buffer address and BufferIndex 
**                        index of buffer corresponding to EventId in the 
**                        prestored buffer in which freeze frames are stored. 
**                                                                            
** Sync/Async           : Synchronous                                         
**                                                                            
** Re-entrancy          : Reentrant                                           
**                                                                            
** Input Parameters     : EventId                                             
**                                                                            
** InOut parameter      : BufferIndex                                         
**                                                                            
** Output Parameters    : buffer                                              
**                                                                            
** Return parameter     : void                                                
**                                                                            
** Preconditions        : None                                                
**                                                                            
** Remarks              :                                      
*******************************************************************************/
FUNC(P2VAR(uint8, AUTOMATIC, DEM_VAR), DEM_CODE) 
Dem_GetBufferOfPrestoredFF(
  const Dem_EventIdType EventId,
  P2VAR(Dem_NumOfPrestoredFFType, AUTOMATIC, DEM_VAR) BufferIndex)
{
  Dem_NumOfPrestoredFFType index;
  P2VAR(uint8, AUTOMATIC, DEM_VAR) buffer = NULL_PTR;
  
  for(index = 0U; index < Dem_Max_Number_Prestored_FF; index++)
  {
    if(Dem_GaaPrestoreBuffer[index].EventIdRef == EventId)
    {
      #if (DEM_SIZE_OF_PRESTORED_FF > 0U)
      buffer = Dem_GaaPrestoreBuffer[index].data;
      if (NULL_PTR != BufferIndex)
      {
        *BufferIndex = index;
      }
      #endif
      
      break;
    }
  }

  return buffer;
}

/*******************************************************************************
** Function Name        : Dem_ClearSinglePrestoredFFbyEventId                           
**                                                                            
** Service ID           : None                                                
**                                                                            
** Description          : Clears a prestored freeze frame of a specific event. 
**                                                                            
** Sync/Async           : Synchronous                                         
**                                                                            
** Re-entrancy          : Reentrant                                           
**                                                                            
** Input Parameters     : EventId
**                                                                            
** InOut parameter      : None
**                                                                            
** Output Parameters    : None
**                                                                            
** Return parameter     : Std_ReturnType
**                                                                            
** Preconditions        : None                                                
**                                                                            
** Remarks              :                   
*******************************************************************************/
FUNC(Std_ReturnType, DEM_CODE)
Dem_ClearSinglePrestoredFFbyEventId(Dem_EventIdType EventId)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint32 index;

  #if (DEM_DEV_ERROR_DETECT == STD_ON)
  /* polyspace<RTE:UNR:Not a defect:No action planned> If-condition evaluates to true or false according to configuration */  
  if ((EventId <= Dem_Number_Of_Events) && (DEM_NO_EVENT != EventId))  
  #endif
  {
    Dem_EventParameterCPCType event = &Dem_Event[EventId - 1];

    if (event->e_PointToData < Dem_Num_Of_EventRelatedData)
    {
      Dem_EventRelatedDataCPCType EvData = &Dem_EventRelatedData[event->e_PointToData];
      if ((EvData->FFClassPos < Dem_Num_Of_FreezeFrameClass)
          #if (DEM_OBD_SUPPORT == STD_ON)
          ||(EvData->OBDClassPos < Dem_Num_Of_OBDFreezeFrameClass)
          #endif
        )
      {
        if (DEM_TRUE == EvData->FFPreStorageSupported)
        {              
          for(index = 0u; index < Dem_Max_Number_Prestored_FF; index++)
          {
            if(Dem_GaaPrestoreBuffer[index].EventIdRef == EventId)
            {
              uint32 i;
              
              #if (DEM_SIZE_OF_PRESTORED_FF > 0U)              
              for (i = 0; i < DEM_SIZE_OF_PRESTORED_FF; i++)
              {
                Dem_GaaPrestoreBuffer[index].data[i] = DEM_SET_BYTE;
              }              
              #endif
              Dem_GaaPrestoreBuffer[index].EventIdRef = DEM_NO_EVENT;

              retVal = E_OK;
              break;
            }
          }
        }
      }
    }
  }
  return retVal;
}

/*******************************************************************************
** Function Name        : Dem_ClearAllPrestoredFreezeFrame                          
**                                                                            
** Service ID           : None                                                
**                                                                            
** Description          : Clears the prestored buffer
**                                                                            
** Sync/Async           : Synchronous                                         
**                                                                            
** Re-entrancy          : Reentrant                                           
**                                                                            
** Input Parameters     : None
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
FUNC(void, DEM_CODE)
Dem_ClearAllPrestoredFreezeFrame(void)
{
  uint32 index;
  for(index = 0u; index < Dem_Max_Number_Prestored_FF; index++)
  {
    uint32 i;

    #if (DEM_SIZE_OF_PRESTORED_FF > 0U)
    for (i = 0; i < DEM_SIZE_OF_PRESTORED_FF; i++)
    {
      Dem_GaaPrestoreBuffer[index].data[i] = 0U;
    }  
    #endif
    
    Dem_GaaPrestoreBuffer[index].EventIdRef = DEM_NO_EVENT;
  }
}
#endif

/******************************************************************************
 * Function Name        : Dem_SetStorageConditionStatus
 *
 * Service ID           : None
 *
 * Description          : Sets the state of the storage condition
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Reentrant
 *
 * Input Parameters     : index, state
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
 *                        Dem_GaaStorageConditionStatus
 *
 *                        Function(s) invoked :
 *                        None
 *
 *****************************************************************************/
#if (DEM_STORAGE_CONDITION_SUPPORT == STD_ON)
FUNC(void, DEM_CODE)
Dem_SetStorageConditionStatus(uint8 index, boolean state)
{
  #if (DEM_NUMBER_STORAGE_CONDITION > 0u)
  Dem_GaaStorageConditionStatus[index] = state;
  #endif
}

/******************************************************************************
 * Function Name        : Dem_InitStorageConditionStatus
 *
 * Service ID           : None
 *
 * Description          : Resets the state of the storage conditions
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Reentrant
 *
 * Input Parameters     : index, state
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
 *                        Dem_Number_Storage_Condition
 *                        Dem_GaaStorageConditionStatus
 *                        Dem_GaaStorageCondition
 *
 *                        Function(s) invoked :
 *                        None
 *
 *****************************************************************************/
FUNC(void, DEM_CODE)
Dem_InitStorageConditionStatus(void)
{
  #if (DEM_NUMBER_STORAGE_CONDITION > 0u)
  uint8 index = 0u;

  for(index = DEM_ZERO; index < Dem_Number_Storage_Condition; index++)
  {
    Dem_GaaStorageConditionStatus[index] = Dem_GaaStorageCondition[index];
  }
  #endif
}

/******************************************************************************
 * Function Name        : Dem_GetStorageConditionStatus
 *
 * Service ID           : None
 *
 * Description          : Gets the state of the storage condition
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Reentrant
 *
 * Input Parameters     : index
 *                        
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * Return parameter     : boolean
 *
 * Preconditions        : None
 *
 * Remarks              : Global Variable(s)  :
 *                        Dem_GaaStorageConditionStatus
 *
 *                        Function(s) invoked :
 *                        None
 *
 *****************************************************************************/
FUNC(boolean, DEM_CODE)
Dem_GetStorageConditionStatus(uint16 index)
{
  boolean status = DEM_TRUE;

  #if ((DEM_NUMBER_STORAGE_CONDITION > 0u) && (DEM_MAX_LISTOFSTORAGECONDITIONID > 0U))
  status = Dem_GaaStorageConditionStatus[Dem_ListOfStorageConditionId[index]];
  #endif
  
  return status;
}

#endif

/******************************************************************************
 * Function Name        : Dem_SetEnableConditionStatus
 *
 * Service ID           : None
 *
 * Description          : Resets the state of the enable conditions
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Reentrant
 *
 * Input Parameters     : index, state
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
 *                        Dem_EnableConditionStatus
 *
 *                        Function(s) invoked :
 *                        None
 *
 *****************************************************************************/
#if (DEM_ENABLE_CONDITION_SUPPORT == STD_ON)
FUNC(void, DEM_CODE)
Dem_SetEnableConditionStatus(uint8 index, boolean state)
{
  #if (DEM_NUMBER_ENABLE_CONDITION > 0u)
  Dem_EnableConditionStatus[index] = state;
  #endif
}

/******************************************************************************
 * Function Name        : Dem_InitEnableConditionStatus
 *
 * Service ID           : None
 *
 * Description          : Resets the state of the enable conditions
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Reentrant
 *
 * Input Parameters     : index, state
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
 *                        Dem_Num_Enable_Condition
 *                        Dem_GaaEnableCondition
 *                        Dem_EnableConditionStatus
 *
 *                        Function(s) invoked :
 *                        None
 *
 *****************************************************************************/

FUNC(void, DEM_CODE)
Dem_InitEnableConditionStatus(void)
{
  #if (DEM_NUMBER_ENABLE_CONDITION > 0u)
  uint8 index = 0u;

  for(index = 0u; index < Dem_Num_Enable_Condition; index++)
  {
    Dem_EnableConditionStatus[index] = Dem_GaaEnableCondition[index];
  }
  #endif
}

/******************************************************************************
 * Function Name        : Dem_GetEnableConditionStatus
 *
 * Service ID           : None
 *
 * Description          : Gets the state of the enable condition
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Reentrant
 *
 * Input Parameters     : index
 *                        
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * Return parameter     : boolean
 *
 * Preconditions        : None
 *
 * Remarks              : Global Variable(s)  :
 *                        Dem_EnableConditionStatus
 *
 *                        Function(s) invoked :
 *                        None
 *
 *****************************************************************************/
FUNC(boolean, DEM_CODE)
Dem_GetEnableConditionStatus(uint16 index)
{
  boolean status = DEM_TRUE;

  #if ((DEM_NUMBER_ENABLE_CONDITION > 0u) && (DEM_MAX_LISTOFENABLECONDITIONID > 0U))
  status = Dem_EnableConditionStatus[Dem_ListOfEnableConditionId[index]];
  #endif
  
  return status;
}
#endif


/*******************************************************************************
** Function Name        : Dem_GetCfgDebounceTimer                             **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Returns the structure variables of                  **
**                        time based debounce                                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : index                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : CfgTimer                                            **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        Dem_GaaPreDebounceTimeBased                         **
**                                                                            **
**                        Function(s) invoked : None                          **
*******************************************************************************/
#if (DEM_DEBOUNCE_TIME_SUPPORT == STD_ON)  

FUNC(P2CONST(Dem_PreDebounceTimeBasedType, AUTOMATIC, DEM_VAR) , DEM_CODE)
Dem_GetCfgDebounceTimer(Dem_NumOfDebounceType DebouceId)
{
  P2CONST(Dem_PreDebounceTimeBasedType, AUTOMATIC, DEM_VAR) timerConf = NULL_PTR;

  #if (DEM_NUMBER_OF_PRE_DEBOUNCE_TIME > 0u)
  if (DebouceId < Dem_Number_Of_Pre_Debounce_Time)
  {
    timerConf = &Dem_GaaPreDebounceTimeBased[DebouceId];
  }
  #endif
  
  return timerConf;
}

FUNC(P2VAR(Dem_TimeDebounceStatusType, AUTOMATIC, DEM_VAR), DEM_CODE)
Dem_GetDebounceTimerStatus(
  Dem_NumOfDebounceType DebounceId)
{
  P2VAR(Dem_TimeDebounceStatusType, AUTOMATIC, DEM_VAR) timerStatus = NULL_PTR; 

  #if (DEM_NUMBER_OF_PRE_DEBOUNCE_TIME > 0u)
  if (DebounceId < Dem_Number_Of_Pre_Debounce_Time)
  {
    timerStatus = &Dem_BasedTimeDebounceStatus[DebounceId];
  }
  #endif

  return timerStatus;
}

#endif

/******************************************************************************
 * Function Name        : Dem_GetCfgIndicatorAtt
 *
 * Service ID           : None
 *
 * Description          : Gets the freeze frame class related parameter 
 *                        of a event
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Reentrant
 *
 * Input Parameters     : event
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * Return parameter     : Dem_FreezeFrameClassPCType
 *
 * Preconditions        : None
 *
 * Remarks              :
 *                        Global Variable(s)  :
 *                        Dem_EventRelatedData
 *
 *                        Function(s) invoked :
 *****************************************************************************/
FUNC(P2CONST(Dem_IndicatorAttributeType, AUTOMATIC, DEM_CONST), DEM_CODE) 
Dem_GetCfgIndicatorAtt(Dem_NumOfIndicatorAttributeType IndicatorAttrId)
{
  #if(DEM_NUMBER_OF_INDICATORS > 0U)      
    return &Dem_GaaIndicatorList[IndicatorAttrId];
  #else
    return NULL_PTR;
  #endif
}



#define DEM_STOP_SEC_CODE
#include "MemMap.h"



