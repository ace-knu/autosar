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
**  PURPOSE   : C header for Dem_Config.c                                     **
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
** 1.0.1    16-05-2016      Youngjin Yun  Changes made As per Redmine #1164   **
**                                                                            **
** 1.0.0    14-01-2014      Youngjin Yun  Initial Version                     **
*******************************************************************************/

#ifndef DEM_CONFIG_H
#define DEM_CONFIG_H
/* @IF_REQ : Check range */
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Necessary in logic */

#include "Dem_PCTypes.h"
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#ifdef DEM_MAX_SIZE_OF_PID_DATAELEMENT
extern const Dem_SizeOfPidDataElementType Dem_Max_Size_Of_Pid_DataElement;
#endif

#ifdef DEM_MAX_NUMBER_OF_PID_DATAELEMENT
extern const Dem_NumOfPidDataElementType Dem_Max_Number_Of_Pid_DataElement;
#endif

#ifdef DEM_MAX_NUMBER_OF_PID_RECDS
extern const Dem_NumOfPidClassType Dem_Max_Number_Of_PID_Recds;
#endif

/* Configuration Range : 0 ~ 255  */
#if (DEM_STORAGE_CONDITION_SUPPORT == STD_ON)
extern const uint16  Dem_Number_Storage_Condition;
#endif

/* Configuration Range : 1 ~ 256 , but 255  */
#ifdef DEM_NUMBER_OPERATION_CYCLES
extern const uint8  Dem_Num_Operation_Cycles;
#endif

#if (DEM_DEBOUNCE_TIME_SUPPORT == STD_ON)
extern const Dem_NumOfDebounceType Dem_Number_Of_Pre_Debounce_Time;
#endif

#ifdef DEM_NUMBER_OF_PRE_DEBOUNCE_COUNTER
extern const Dem_NumOfDebounceType Dem_Number_Of_Pre_Debounce_Counter;
#endif

#ifdef DEM_MAX_NUM_GRP_DTC
extern const uint8  Dem_Max_Num_Grp_DTC;
#endif

extern const Dem_NumOfIndicatorAttributeType  Dem_Number_Of_Indicators;


#ifdef DEM_MAX_NUM_OF_DTC_STAT_CHNG_FCTS
extern const uint32  Dem_Max_Num_Of_DTC_Stat_Chng_Fcts;
#endif

#ifdef DEM_NUMBER_OF_EVENTS 
extern const Dem_EventIdType Dem_Number_Of_Events;
#endif

#ifdef DEM_BSW_ERROR_BUFFER_SIZE  /* range 0:255 */
extern const uint8  Dem_BSW_Error_Buffer_Size;
#endif

#ifdef DEM_STATUS_AVAILABILITY_MASK
extern const uint8  Dem_Status_Availability_Mask;
#endif

#ifdef DEM_IMMEDIATE_NV_STORAGE_LIMIT
extern const uint8  Dem_Immdiate_Nv_Storage_Limit;
#endif

#ifdef DEM_MAX_NUMBER_EVENT_ENTRY_MIR
extern const uint8 Dem_Max_Number_Event_Entry_Mir;
#endif

#ifdef DEM_MAX_NUMBER_EVENT_ENTRY_PRI
extern const uint8 Dem_Max_Number_Event_Entry_Pri;
#endif

#ifdef DEM_MAX_NUMBER_EVENT_ENTRY_SEC
extern const uint8 Dem_Max_Number_Event_Entry_Sec;
#endif

#ifdef DEM_MAX_NUMBER_EVENT_ENTRY_PER
extern const uint8 Dem_Max_Number_Event_Entry_Per;
#endif

#ifdef DEM_TASK_TIME
extern const uint16 Dem_Task_Time;
#endif

#ifdef DEM_MAX_NUMBER_OF_DTC
extern const uint16 Dem_Max_Number_Of_DTC;
#endif

#ifdef DEM_MIL_INDICATORID
extern const uint8 Dem_MIL_IndicatorId;
#endif

#ifdef DEM_PID01_BYTEB_LOWER_NIBBLE
extern const uint8 DEM_PID01_ByteB_Lower_Nibble;
#endif

#ifdef DEM_PID01_BYTEC_SPARK
extern const uint8 DemM_PID01_ByteC_Spark;
#endif

#ifdef DEM_PID01_BYTEC_COMPRESSION
extern const uint8 Dem_PID01_ByteC_Compression;
#endif


extern const uint8 Dem_Max_Number_Prestored_FF;

extern const Dem_NumOfEventRelatedDataType Dem_Num_Of_EventRelatedData;


/*extern const uint8 Dem_FreezeFrame_Capture;*/
/*extern const uint8 Dem_ExtendedData_Capture;*/

#if (DEM_ENABLE_CONDITION_SUPPORT > 0u)
extern const uint8 Dem_Num_Enable_Condition;
#endif

#ifdef DEM_NUM_OF_EVENTRELATEDDATA
extern const Dem_NumOfEventRelatedDataType Dem_Num_Of_EventRelatedData;
#endif

#ifdef DEM_NUMBER_OF_PRE_DEBOUNCE_MONITOR_INTERNAL
extern const Dem_NumOfDebounceType Dem_Number_Of_Pre_Debounce_Monitor_Internal;
#endif

#ifdef DEM_AGING_REQUIERES_TESTED_CYCLE
extern const boolean Dem_CfgAgingRequieresTestedCycle;
#endif

#ifdef DEM_OPERATION_CYCLE_STATUS_STORAGE
extern const uint8 Dem_Operation_Cycle_Status_Storage;
#endif

#if(DEM_NUMBER_OF_INDICATORS == DEM_ZERO)
extern P2CONST(Dem_IndicatorAttributeType, AUTOMATIC, DEM_CONST) Dem_GaaIndicatorList;
#endif

#ifdef DEM_MAX_LISTOFCOMBINEDEVENTS
extern const uint16  Dem_Max_ListOfCombinedEvents;
#endif 

#ifdef DEM_NUM_OF_PRIMARY_EVENTMEMORY_NVBLOCKID 
extern const Dem_NumOfEventMemoryEntryType Dem_Num_Of_Primary_EventMemory_NvBlockId;
#endif

#ifdef DEM_NUM_OF_SECONDARY_EVENTMEMORY_NVBLOCKID
extern const Dem_NumOfEventMemoryEntryType Dem_Num_Of_Secondary_EventMemory_NvBlockId;
#endif


#ifdef DEM_NUM_OF_FREEZEFRAMECLASS
extern const Dem_NumOfFreezeFrameClassType Dem_Num_Of_FreezeFrameClass;
#endif

#ifdef DEM_NUM_OF_EXTENDEDDATACLASS
extern const Dem_NumOfExtendedDataClassType Dem_Num_Of_ExtendedDataClass;
#endif

#ifdef DEM_MAX_LISTOFFFRECORDNUMBERS
extern const uint16 Dem_Max_ListOfFFRecordNumbers;
#endif

#ifdef DEM_NUM_OF_EXTENDEDDATARECORDCLASS
extern const uint16 Dem_Num_Of_ExtendedDataRecordClass;
#endif 

#ifdef DEM_SIZE_OF_EVENT_DATA
extern const uint32 Dem_Size_Of_Event_Data;
#endif 

#ifdef DEM_SIZE_OF_EXTENDED_DATA
extern const uint32 Dem_Size_Of_Extended_Data;
#endif

#ifdef DEM_MAX_LISTOFEDRECORDCLASSINDEX
extern const uint16 Dem_Max_ListOfEDRecordClassIndex;
#endif

#ifdef DEM_MAX_LISTOFDIDCLASSINDEX
extern const uint16 Dem_Max_ListOfDidClassIndex;
#endif

#ifdef DEM_MAX_LISTOFDATAELEMENTCLASSINDEX
extern const uint16 Dem_Max_ListOfDataElementClassIndex;
#endif

#ifdef DEM_MAX_NUM_OF_EVENT_STAT_CHNG_FCTS
extern const Dem_NumOfEvtStatFctsType Dem_Max_ListOfEvtStatusChangedFctPtr;
#endif

#ifdef DEM_MAX_LISTOFENABLECONDITIONID
extern const uint8 Dem_Max_ListOfEnableConditionId;
#endif

#ifdef DEM_MAX_LISTOFSTORAGECONDITIONID
extern const uint8 Dem_Max_ListOfStorageConditionId;
#endif

#ifdef DEM_NUM_OF_HEALING_COUNTER
extern const Dem_NumOfIndicatorAttributeType Dem_Num_Of_Healing_Counter;
#endif

#ifdef DEM_NUM_OF_FAILURE_COUNTER
extern const Dem_NumOfIndicatorAttributeType Dem_Num_Of_Failure_Counter;
#endif

extern const uint32 Dem_Size_Of_Prestored_FF;
extern const boolean Dem_Status_Bit_Storage_TestFailed;


extern const boolean Dem_Aging_Requieres_Tested_Cycle;
extern const boolean Dem_Healing_Requieres_Tested_Cycle;

#ifdef DEM_NUM_OF_INDICATOR_ATTRIBUTE_STATUS
extern const Dem_NumOfIndicatorAttributeType  Dem_Num_Of_Indicator_Attribute_Status;
#endif

extern const Dem_DTCTranslationFormatType Dem_Type_Of_Dtc_Supported;

extern const boolean Dem_Uds_Status_In_Event_NvBlock;


#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"




/*******************************************************************************
**                      Function Prototype                                    **
*******************************************************************************/

#define DEM_START_SEC_CODE
#include "MemMap.h"

#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U)
extern FUNC(void, DEM_CODE) 
Dem_SetEventIdOfPrestoredFF(
  Dem_NumOfPrestoredFFType BufferIndex,
  const Dem_EventIdType EventId);

extern FUNC(P2VAR(uint8, AUTOMATIC, DEM_VAR), DEM_CODE) 
Dem_GetBufferOfPrestoredFF(
  const Dem_EventIdType EventId,
  P2VAR(Dem_NumOfPrestoredFFType, AUTOMATIC, DEM_VAR) BufferIndex);

extern FUNC(Std_ReturnType, DEM_CODE)
Dem_ClearSinglePrestoredFFbyEventId(Dem_EventIdType EventId);

extern FUNC(void, DEM_CODE)
Dem_ClearAllPrestoredFreezeFrame(void);
#endif


#if (DEM_STORAGE_CONDITION_SUPPORT == STD_ON)
extern FUNC(void, DEM_CODE)
Dem_SetStorageConditionStatus(uint8 index, boolean state);

extern FUNC(void, DEM_CODE)
Dem_InitStorageConditionStatus(void);


#endif

#if (DEM_DEBOUNCE_TIME_SUPPORT == STD_ON)  
extern FUNC(P2CONST(Dem_PreDebounceTimeBasedType, AUTOMATIC, DEM_VAR) , DEM_CODE)
Dem_GetCfgDebounceTimer(Dem_NumOfDebounceType DebouceId);

extern FUNC(P2VAR(Dem_TimeDebounceStatusType, AUTOMATIC, DEM_VAR), DEM_CODE)
Dem_GetDebounceTimerStatus(
  Dem_NumOfDebounceType DebounceId);
#endif

extern FUNC(void, DEM_CODE)
Dem_SetEnableConditionStatus(uint8 index, boolean state);

extern FUNC(void, DEM_CODE)
Dem_InitEnableConditionStatus(void);


extern FUNC(boolean, DEM_CODE)
Dem_GetStorageConditionStatus(uint16 index);

extern FUNC(boolean, DEM_CODE)
Dem_GetEnableConditionStatus(uint16 index);

extern FUNC(P2CONST(Dem_IndicatorAttributeType, AUTOMATIC, DEM_CONST) , DEM_CODE) 
Dem_GetCfgIndicatorAtt(Dem_NumOfIndicatorAttributeType IndicatorAttrId);

/**************************************************/
#define DEM_STOP_SEC_CODE
#include "MemMap.h"
/*************************************************/

/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Necessary in logic */

#endif
