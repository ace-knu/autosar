/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_Ram.h                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostics Event Manager Module                      **
**                                                                            **
**  PURPOSE   : Header file for Dem_Ram.c                                     **
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


#ifndef DEM_RAM_H
#define DEM_RAM_H
 
/* polyspace:begin<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem.h"        /* Dem module header file */
#include "NvM.h"        /* NVRAM manager symbols Header File */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*************************************************************************
 * VAR INIT_UNSPECIFIED
 ************************************************************************/
#define DEM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

/* Dem_BasedTimeDebounceStatus is updated in the Dem_PreInit */
extern VAR(Dem_EvMemTriggerType, DEM_VAR) Dem_EvMemTrigger;
/* Dem_BasedTimeDebounceStatus is updated in the Dem_EvMem_Init */
extern VAR(Dem_ClearDtcStateType, DEM_VAR) Dem_ClearDtcState;
/* Dem_BasedTimeDebounceStatus is updated in the Dem_SetDTCFilter */
extern VAR(Dem_DTCFilterStateType, DEM_VAR) Dem_DTCFilterState;
/* Dem_AllEventStatusByte is updated in the Dem_EvMem_Init */
extern VAR(Dem_UdsStatusByteType, DEM_VAR) Dem_AllEventStatusByte[];  
/* Dem_BasedTimeDebounceStatus is updated in the Dem_PreInit */
#if (DEM_NUMBER_OF_PRE_DEBOUNCE_TIME >0u)
/* Predebounce time */
extern VAR(Dem_TimeDebounceStatusType, DEM_VAR) Dem_BasedTimeDebounceStatus[];
#endif

#define DEM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

/*************************************************************************
 * VAR_NO_INIT_UNSPECIFIED
 ************************************************************************/
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

extern VAR(Dem_GenericNvRamDataType, DEM_VAR_NOINIT) Dem_NonVolatileData;

extern VAR(Dem_EventStatusNvRamDataType, DEM_VAR_NOINIT) Dem_EventStatusNvRamData;

/* Primary Event Memory variable */
extern VAR(Dem_EventMemoryEntryType, DEM_VAR_NOINIT) Dem_PrimaryEventMemory[];

#if (DEM_MAX_NUMBER_EVENT_ENTRY_SEC > 0U)
/* Secondary Event Memory variable */
extern VAR(Dem_EventMemoryEntryType, DEM_VAR_NOINIT) Dem_SecondaryEventMemory[];
#endif

#if (DEM_MAX_NUMBER_EVENT_ENTRY_MIR > 0U)
/* Mirror Event Memory variable */
extern VAR(Dem_EventMemoryEntryType, DEM_VAR_NOINIT) Dem_MirrorEventMemory[];
#endif

#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/*************************************************************************
 * VAR_CLEARED_UNSPECIFIED
 ************************************************************************/

#define DEM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

extern VAR(Dem_RecordUpdateType, DEM_VAR) Dem_GstRecordDisableDTC;

extern VAR(Dem_FilteredFreezeFrameRecordType, DEM_VAR) Dem_FilteredFFRecord;

#if (DEM_MAX_NUMBER_PRESTORED_FF > 0U) 
extern VAR(Dem_PrestoreBufferType, DEM_VAR) Dem_GaaPrestoreBuffer[];
#endif

#define DEM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/*************************************************************************
 * VAR CLEARED_32
 ************************************************************************/

#define DEM_START_SEC_VAR_CLEARED_32
#include "MemMap.h"

#if (DEM_EVMEM_TIMESTAMP_USED == STD_ON)
extern VAR(uint32, DEM_VAR) Dem_MaxTimeStamp[];
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
extern VAR(uint16, DEM_VAR) Dem_GaaErrorBuffer[];
#endif

#if (DEM_NUMBER_OF_PRE_DEBOUNCE_COUNTER > 0U)
/* Debounce Counter based */
extern VAR(sint16, DEM_VAR)  Dem_GssTempCounter[];
#endif

#define DEM_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

/*************************************************************************
 * VAR CLEARED_8
 ************************************************************************/

#define DEM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

extern VAR(uint8, DEM_VAR) Dem_GucInit;

extern VAR(uint8, DEM_VAR) Dem_EventState[];

extern VAR(uint8, DEM_VAR) Dem_GucDisableDtcSettingDTCKind;

extern VAR(Dem_NumOfEventMemoryEntryType, DEM_VAR) Dem_EvMemToEventMap[];  

extern VAR(Dem_NumOfEventMemoryEntryType, DEM_VAR) Dem_NumOfStoredEvtMemEntryies[];

/* DEM_NVDATA_ALL_EVENT_STATUS_ID, DEM_NVDATA_GENERIC_NVRAM_DATA_ID */
extern VAR(uint8, DEM_VAR_NOINIT) Dem_NonVolatileDataState[];

#if (DEM_BSW_ERROR_BUFFER_SIZE > 0U)
extern VAR(uint8, DEM_VAR) Dem_GucErrorWriteIndex;
/* Used to check whether event is stored */
extern VAR(uint8, DEM_VAR) Dem_GaaErrorBufferStatus[];
#endif

#if (DEM_OPERATION_CYCLE_STATUS_STORAGE == STD_OFF)
extern VAR(uint8, DEM_VAR) Dem_OperationCycleState[];
#endif

#if (DEM_SIZE_OF_EVENT_DATA > 0U)
extern VAR(uint8, DEM_VAR) Dem_EvEventDataCapture[];
#endif

#if (DEM_NUMBER_OF_PRE_DEBOUNCE_COUNTER > 0U)
/* Debounce Counter based */
extern VAR(uint8, DEM_VAR) Dem_CtrDebDirection[];
#endif

#define DEM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

/*****************************************************************************/
/* VAR CLEARED BOOLEAN                                                       */
/*****************************************************************************/

#define DEM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

extern VAR(boolean, DEM_VAR) Dem_OperationCycleTrigger;

extern VAR(boolean, DEM_VAR) Dem_GaaDisableDtcSettingGroupDTC[];

extern VAR(boolean, DEM_VAR) Dem_GblDisableDtcSettingAllDTC;

#if (DEM_NUMBER_STORAGE_CONDITION > 0U)
extern VAR(boolean, DEM_VAR) Dem_GaaStorageConditionStatus[];
#endif

#if (DEM_NUMBER_ENABLE_CONDITION > 0U)
extern VAR(boolean, DEM_VAR) Dem_EnableConditionStatus[];
#endif

#if defined(DEM_NVBLOCKS_CANBE_SKIPPED_ON_SWRESET)
extern VAR(boolean, DEM_VAR) Dem_DoReadFromNv;
#endif

#define DEM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/*************************************************************************
 * CONST
 ************************************************************************/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* This pointer array points to the event memories */
extern CONSTP2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_CONST) Dem_EventMemory[];

extern CONSTP2VAR(uint8, AUTOMATIC, DEM_CONST) Dem_EventMemoryState[];



extern CONST(Dem_NumOfEventMemoryEntryType, DEM_CONST) Dem_SizeOfEventMemory[];



extern CONST(Dem_DTCOriginType, DEM_CONST) Dem_SupportedDTCOrigins[];

extern CONST(uint8, DEM_CONST)  Dem_NumOfSupportedDTCOrigins;



extern CONST(Dem_NvDataIdType, DEM_CONST) Dem_DataIdOfSingleNvBlocks[];
    
extern CONST(Dem_NvDataIdType, DEM_CONST)  Dem_NumOfSupportedSingleNvBlocks;

/* BlockId is allocated in the Dem_Config.c */
extern CONST(NvM_BlockIdType, DEM_CONST)  Dem_EventStatusNvRamBlkId;

/* BlockId is allocated in the Dem_Config.c */
extern CONST(NvM_BlockIdType, DEM_CONST)  Dem_NonVolatileDataBlkId;

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*****************************************************************************/

/* polyspace:end<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */

#endif /* DEM_RAM_H */
/*******************************************************************************
**                       End of File                                          **
*******************************************************************************/

