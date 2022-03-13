/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_Ram.c                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostics Event Manager Module                      **
**                                                                            **
**  PURPOSE   : Defining Global Variables                                     **
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
********************************************************************************
** 1.2.1    06-02-2016      YoungJin.Yun  Changes made As per Redmine #7308   **
**                                        ,#7251                              **
**                                                                            **
** 1.2.0    16-11-2016      YoungJin.Yun  Changes made As per Redmine #6549   **
**                                        #6188                               **
**                                                                            **
** 1.1.0    16-04-2016      Youngjin Yun  Changes made As per Redmine #1164   **
**                                                                            **
** 1.0.4    11-01-2014      YoungJin Yun  Changes made As per Redmine #366,   **
**                                        #368,#371,#372,#405,#366,#367,#368, ** 
**                                        #371,#372,#405,#369,#373,#374,#375, **
**                                        #376,#370,#377,#381,#382,#383,#384, **
**                                        #385,#386,#387,#388,#389,#390,#391, **
**                                        #397,#398,#399,#400,#378,#380,#401, **
**                                        #403,#404,#406,#409,#410,#411,#412  **
**                                        #367                                **
**                                                                            **
** 1.0.0    01-01-2013      Autron      Initial Version                       **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem.h"        /* Dem module header file */
#include "NvM.h"        /* NVRAM manager symbols Header File */
#include "Dem_Ram.h"    /* Dem global Ram variables header file */
#if (DEM_OBD_SUPPORT == STD_ON)
#include "Dem_ObdRam.h" /* Dem global Ram variables header file for OBD */
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*************************************************************************
 * VAR INIT_UNSPECIFIED
 ************************************************************************/
#define DEM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

/* Dem_BasedTimeDebounceStatus is updated in the Dem_PreInit */
VAR(Dem_EvMemTriggerType, DEM_VAR) Dem_EvMemTrigger;
/* Dem_BasedTimeDebounceStatus is updated in the Dem_EvMem_Init */
VAR(Dem_ClearDtcStateType, DEM_VAR) Dem_ClearDtcState;
/* Dem_BasedTimeDebounceStatus is updated in the Dem_SetDTCFilter */
VAR(Dem_DTCFilterStateType, DEM_VAR)  Dem_DTCFilterState;
/* Dem_AllEventStatusByte is updated in the Dem_EvMem_Init */
VAR(Dem_UdsStatusByteType, DEM_VAR) Dem_AllEventStatusByte
  [DEM_NUMBER_OF_EVENTS + 1U];  

/* Dem_BasedTimeDebounceStatus is updated in the Dem_PreInit */
#if (DEM_NUMBER_OF_PRE_DEBOUNCE_TIME > 0U)
VAR(Dem_TimeDebounceStatusType, DEM_VAR) Dem_BasedTimeDebounceStatus
  [DEM_NUMBER_OF_PRE_DEBOUNCE_TIME];
#endif

#define DEM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

/*************************************************************************
 * VAR_NO_INIT_UNSPECIFIED
 ************************************************************************/
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

VAR(Dem_GenericNvRamDataType, DEM_VAR_NOINIT) Dem_NonVolatileData;

VAR(Dem_EventStatusNvRamDataType, DEM_VAR_NOINIT) Dem_EventStatusNvRamData;

/* Primary Event Memory variable : */
VAR(Dem_EventMemoryEntryType, DEM_VAR_NOINIT) Dem_PrimaryEventMemory
  [DEM_MAX_NUMBER_EVENT_ENTRY_PRI];

#if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC > 0U)
/* Secondary Event Memory variable */
VAR(Dem_EventMemoryEntryType, DEM_VAR_NOINIT) Dem_SecondaryEventMemory
  [DEM_MAX_NUMBER_EVENT_ENTRY_SEC];
#endif

#if (DEM_MAX_NUMBER_EVENT_ENTRY_MIR > 0U)
/* Mirror Event Memory variable */
VAR(Dem_EventMemoryEntryType, DEM_VAR_NOINIT) Dem_MirrorEventMemory
  [DEM_MAX_NUMBER_EVENT_ENTRY_MIR];
#endif

#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/*************************************************************************
 * VAR_CLEARED_UNSPECIFIED
 ************************************************************************/

#define DEM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

VAR(Dem_RecordUpdateType, DEM_VAR) Dem_GstRecordDisableDTC;

VAR(Dem_FilteredFreezeFrameRecordType, DEM_VAR) Dem_FilteredFFRecord;

#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U) 
VAR(Dem_PrestoreBufferType, DEM_VAR) Dem_GaaPrestoreBuffer
  [DEM_MAX_NUMBER_PRESTORED_FF]; 
#endif

#define DEM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/*************************************************************************
 * VAR CLEARED_32
 ************************************************************************/

#define DEM_START_SEC_VAR_CLEARED_32
#include "MemMap.h"

#if (DEM_EVMEM_TIMESTAMP_USED == STD_ON)
VAR(uint32, DEM_VAR) Dem_MaxTimeStamp
  [DEM_NUM_OF_DTC_ORGINS+1];
#endif

#define DEM_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

/*************************************************************************
 * VAR CLEARED_16
 ************************************************************************/

#define DEM_START_SEC_VAR_CLEARED_16
#include "MemMap.h"

#if (DEM_BSW_ERROR_BUFFER_SIZE > 0U)
/* BSW error buffer */
VAR(uint16, DEM_VAR) Dem_GaaErrorBuffer
  [DEM_BSW_ERROR_BUFFER_SIZE];
#endif

#if (DEM_NUMBER_OF_PRE_DEBOUNCE_COUNTER > 0U)
/* Debounce Counter based */
VAR(sint16, DEM_VAR) Dem_GssTempCounter
  [DEM_NUMBER_OF_PRE_DEBOUNCE_COUNTER];
#endif

#define DEM_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

/*************************************************************************
 * VAR CLEARED_8
 ************************************************************************/

#define DEM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

VAR(uint8, DEM_VAR) Dem_GucInit;

VAR(uint8, DEM_VAR) Dem_EventState
  [DEM_NUMBER_OF_EVENTS+1U];

VAR(uint8, DEM_VAR) Dem_GucDisableDtcSettingDTCKind;

VAR(Dem_NumOfEventMemoryEntryType, DEM_VAR) Dem_EvMemToEventMap
  [DEM_NUMBER_OF_EVENTS + 1U];  

VAR(Dem_NumOfEventMemoryEntryType, DEM_VAR) Dem_NumOfStoredEvtMemEntryies
  [DEM_NUM_OF_DTC_ORGINS+1U];

/* DEM_NVDATA_ALL_EVENT_STATUS_ID, DEM_NVDATA_GENERIC_NVRAM_DATA_ID */
VAR(uint8, DEM_VAR_NOINIT) Dem_NonVolatileDataState[2U];

/* Primary Event Memory variable */
static VAR(uint8, DEM_VAR) Dem_PrimaryEventMemoryState
  [DEM_MAX_NUMBER_EVENT_ENTRY_PRI];

#if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC > 0U)
/* Secondary Event Memory variable */
static VAR(uint8, DEM_VAR) Dem_SecondaryEventMemoryState
  [DEM_MAX_NUMBER_EVENT_ENTRY_SEC];
#endif

#if (DEM_MAX_NUMBER_EVENT_ENTRY_MIR > 0U)
/* Mirror Event Memory variable */
static VAR(uint8, DEM_VAR) Dem_MirrorEventMemoryState
  [DEM_MAX_NUMBER_EVENT_ENTRY_MIR];
#endif

#if (DEM_BSW_ERROR_BUFFER_SIZE > 0U)
VAR(uint8, DEM_VAR) Dem_GucErrorWriteIndex;
/* Used to check whether event is stored */
VAR(uint8, DEM_VAR) Dem_GaaErrorBufferStatus
  [DEM_BSW_ERROR_BUFFER_SIZE];
#endif

#if (DEM_OPERATION_CYCLE_STATUS_STORAGE == STD_OFF)
VAR(uint8, DEM_VAR) Dem_OperationCycleState
  [DEM_NUMBER_OPERATION_CYCLES];
#endif

/* @IF_REQ: DEM_SIZE_OF_EVENT_DATA -> Max size (FF+ED) */
#if (DEM_SIZE_OF_EVENT_DATA > 0U)
VAR(uint8, DEM_VAR) Dem_EvEventDataCapture
  [DEM_SIZE_OF_EVENT_DATA];
#endif

#if (DEM_NUMBER_OF_PRE_DEBOUNCE_COUNTER > 0U)
/* Debounce Counter based */
VAR(uint8, DEM_VAR) Dem_CtrDebDirection
  [DEM_NUMBER_OF_PRE_DEBOUNCE_COUNTER];
#endif

#define DEM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

/*****************************************************************************/
/* VAR CLEARED BOOLEAN                                                       */
/*****************************************************************************/

#define DEM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

VAR(boolean, DEM_VAR) Dem_OperationCycleTrigger;

VAR(boolean, DEM_VAR) Dem_GaaDisableDtcSettingGroupDTC
  [DEM_MAX_NUM_GRP_DTC];

VAR(boolean, DEM_VAR) Dem_GblDisableDtcSettingAllDTC;

#if (DEM_NUMBER_STORAGE_CONDITION > 0U)
VAR(boolean, DEM_VAR) Dem_GaaStorageConditionStatus
  [DEM_NUMBER_STORAGE_CONDITION];
#endif

#if (DEM_NUMBER_ENABLE_CONDITION > 0U)
VAR(boolean, DEM_VAR) Dem_EnableConditionStatus
  [DEM_NUMBER_ENABLE_CONDITION];
#endif

#if defined(DEM_NVBLOCKS_CANBE_SKIPPED_ON_SWRESET)
VAR(boolean, DEM_VAR) Dem_DoReadFromNv;
#endif

#define DEM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/*************************************************************************
 * CONST
 ************************************************************************/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* This pointer array points to the event memories */
CONSTP2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_CONST) Dem_EventMemory
  [DEM_NUM_OF_DTC_ORGINS+1U] =
{
  NULL_PTR,

  &Dem_PrimaryEventMemory[0],

#if (DEM_MAX_NUMBER_EVENT_ENTRY_MIR > 0U)
  &Dem_MirrorEventMemory[0],
#else
  NULL_PTR,
#endif

#if (DEM_OBD_SUPPORT == STD_ON) && (DEM_MAX_NUMBER_EVENT_ENTRY_PER > 0U)
  &Dem_PermanentEventMemory[0],
#else
  NULL_PTR,
#endif

#if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC > 0U)
  &Dem_SecondaryEventMemory[0],
#else
  NULL_PTR,
#endif
};

CONSTP2VAR(uint8, AUTOMATIC, DEM_CONST) Dem_EventMemoryState
  [DEM_NUM_OF_DTC_ORGINS+1U] =
{
  NULL_PTR,

  &Dem_PrimaryEventMemoryState[0],

  #if (DEM_MAX_NUMBER_EVENT_ENTRY_MIR > 0U)
  &Dem_MirrorEventMemoryState[0],
  #else
  NULL_PTR,
  #endif

  #if (DEM_OBD_SUPPORT == STD_ON) && (DEM_MAX_NUMBER_EVENT_ENTRY_PER > 0U)
  &Dem_PermanentEventMemoryState[0],
  #else
  NULL_PTR,
  #endif

  #if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC > 0U)
  &Dem_SecondaryEventMemoryState[0],
  #else
  NULL_PTR,
  #endif
};  

/* number of the entries of each event memory */
CONST(Dem_NumOfEventMemoryEntryType, DEM_CONST) Dem_SizeOfEventMemory
  [DEM_NUM_OF_DTC_ORGINS+1] =
{
  0,
  DEM_MAX_NUMBER_EVENT_ENTRY_PRI,
  DEM_MAX_NUMBER_EVENT_ENTRY_MIR,
  DEM_MAX_NUMBER_EVENT_ENTRY_PER,
  DEM_MAX_NUMBER_EVENT_ENTRY_SEC
};

CONST(Dem_DTCOriginType, DEM_CONST) Dem_SupportedDTCOrigins[] = {
  DEM_DTC_ORIGIN_PRIMARY_MEMORY,
  #if(DEM_MAX_NUMBER_EVENT_ENTRY_SEC > 0u)
  DEM_DTC_ORIGIN_SECONDARY_MEMORY,
  #endif
};

CONST(uint8, DEM_CONST)  Dem_NumOfSupportedDTCOrigins 
  = COUNTOF(Dem_SupportedDTCOrigins);

CONST(Dem_NvDataIdType, DEM_CONST) Dem_DataIdOfSingleNvBlocks[] = {
  DEM_NVDATA_ALL_EVENT_STATUS_ID,
  DEM_NVDATA_GENERIC_NVRAM_DATA_ID
};

CONST(Dem_NvDataIdType, DEM_CONST)  Dem_NumOfSupportedSingleNvBlocks = COUNTOF(Dem_DataIdOfSingleNvBlocks);

#if defined(DEM_NVM_BLK_ID_EVENT_STATUS)
CONST(NvM_BlockIdType, DEM_CONST) Dem_EventStatusNvRamBlkId = DEM_NVM_BLK_ID_EVENT_STATUS;
#else
CONST(NvM_BlockIdType, DEM_CONST) Dem_EventStatusNvRamBlkId = 0U;
#endif

#if defined(DEM_NVM_BLK_ID_NON_VOLATILE_DATA)
CONST(NvM_BlockIdType, DEM_CONST) Dem_NonVolatileDataBlkId = DEM_NVM_BLK_ID_NON_VOLATILE_DATA;
#else
CONST(NvM_BlockIdType, DEM_CONST) Dem_NonVolatileDataBlkId = 0U;
#endif


#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  

/*****************************************************************************/

/*******************************************************************************
**                       End of File                                          **
*******************************************************************************/
