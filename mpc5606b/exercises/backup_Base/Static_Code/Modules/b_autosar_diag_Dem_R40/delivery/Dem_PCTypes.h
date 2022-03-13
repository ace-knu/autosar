/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_PCTypes.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Event Manager                              **
**                                                                            **
**  PURPOSE   : This file contains the structure definitions and macro        **
**              definitions of DEM module                                     **
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
** 1.5.0    09-03-2017      YoungJin.Yun  Changes made As per Redmine #6202   **
**                                                                            **
** 1.4.0    06-02-2016      YoungJin.Yun  Changes made As per Redmine #7379   **
**                                                                            **
** 1.3.1    30-12-2016      YoungJin.Yun  Changes made As per Redmine #6409   **
**                                                                            **
** 1.3.0    16-11-2016      YoungJin.Yun  Changes made As per Redmine #6549   **
**                                                                            **
** 1.2.1    30-10-2016      YoungJin.Yun  Changes made As per Redmine #6188   **
**                                                                            **
** 1.2.0    30-08-2016      YoungJin.Yun  Changes made As per Redmine #5011   **
**                                                                            **
** 1.1.0    16-04-2016      Youngjin Yun  Changes made As per Redmine #1164   **
**                                                                            **
** 1.0.5    16-04-2015      Sungeol Baek  Changes made As per Reminde #2171   **
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

#ifndef DEM_PCTYPES_H
#define DEM_PCTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
/* polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations> Not a defect */
/* polyspace:begin<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */

#include "Dem_Types.h"
#include "NvM.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

typedef struct STag_Dem_ConfigData
{
  uint8 LucDummy;
} Dem_ConfigType;


typedef struct STag_Dem_DataElementExternalCSType {
  /*defines the prototype of the C function "ReadDataElement"*/P2FUNC(Std_ReturnType, DEM_APPL_CODE, pDemDataElementReadFnc)
( P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA));

  /*Defines the size of the data element in bytes*/
  uint8 ucDemDataElementDataSize;

  /*Defines whether data is obtained through R-Port or DemDataElementReadFnc*/
  boolean blDemDataElementUsePort;

} Dem_DataElementExternalCSType;


/*******************************************************************************
 ** Structure for DEM Internal Data Element Class Type                         **
 *******************************************************************************/
typedef struct STag_Dem_DataElementInternalType {
  /*Defines the size of the data element in bytes*/
  uint8 ucDemDataElementDataSize;

  /*defines which parameter is mapped to the data element*/
  uint8 ucDemInternalDataElement;

} Dem_DataElementInternalType;

/*******************************************************************************
 ** Operation cycle IDs and related events structure                           **
 *******************************************************************************/
typedef struct STag_Dem_OperationCycleType 
{
  #if(DEM_MAX_EVENT_PER_CYCLE > DEM_ZERO)
  /* Stores the number of EventIDs configured for the OperationCycleId */
  Dem_EventIdType NumOfEvents;

  /* Index of the Indices array of EventParameter array */
  CONSTP2CONST(Dem_EventIdType, AUTOMATIC, DEM_CONST) ListOfEventIndex;
  #endif

  /* Operation Cycle Id */
  uint8 ucOperationCycleId;

} Dem_OperationCycleType;
/*******************************************************************************
 ** Operation cycle IDs and related events structure                           **
 *******************************************************************************/
typedef struct STag_Dem_OperationCycleName {
  /* Operation Cycle Id */
  uint8 ucOperationCycle;

} Dem_OperationCycleName;

/*******************************************************************************
 **                 Structure for combined DTC                                 **
 *******************************************************************************/
typedef struct STag_Dem_CombinedDtcType
{
  /* Stores the number of EventIDs configured for the DTC */
  Dem_EventIdType ddNumberOfEvents;

  /* Events Configured for DTC */
  Dem_NumOfEventIdType dtc_PointToEventList;

  /* DTCGroup Index*/
  Dem_DTCGroupType ddDtcGroup;

  /* Kind of DTC */
  Dem_DTCKindType ddDtcKind;

  /* Format of DTC */
  Dem_DTCFormatType ddDtcFormat;

  /* Severity of DTC */
  Dem_DTCSeverityType ddDtcSeverity;

  /* Diagnostic Trouble Code For NON-OBD*/
  uint32 ulUdsDtc;

  #if (DEM_OBD_SUPPORT == STD_ON)
  /* Diagnostic Trouble Code For OBD*/
  uint16 usObdDtc;
  #endif

  /* Diagnostic Trouble Code FunctionalUnit */
  uint8 ucDtcFunctionalUnit;

  /* Flag to enable Immediate NVRAM Storage */
  uint8 EvMemTriggerFlag;

  #if (DEM_J1939_SUPPORT == STD_ON)
  uint32 J1939DTCValue;

  boolean J1939DM1ActCondCDTC;
  #endif  

  Dem_UdsStatusByteType UdsStatusAvailabilityMask;  
}Dem_CombinedDtcType;


/*******************************************************************************
 **                 Structure type of Pid Record                               **
 *******************************************************************************/
#if (DEM_OBD_SUPPORT == STD_ON)
typedef struct STag_Dem_PidRecordType
{
  /* Freeze Frame is configured for Pid */
  uint8 ucPid;

  /* No of data elements */
  uint8 ucNumOfDataElements;

  /* Index of data element array */
  uint8 aaPidDataElementIndex[DEM_MAX_NUMBER_OF_PID_DATAELEMENT];

}Dem_PidRecordType;
#endif
/*******************************************************************************
 **                 Structure type of Pid Record                               **
 *******************************************************************************/
#if (DEM_OBD_SUPPORT == STD_ON)
typedef struct STag_Dem_PidDataElementType
{

  uint8 ucDataElementType;

  uint8 ucDataElementIndex;

}Dem_PidDataElementType;
#endif

/*******************************************************************************
 ** Indicator Attribute list                                                   **
 *******************************************************************************/
typedef struct STag_Dem_IndicatorAttributeType 
{
  uint8 IndicatorIdRef;             
  Dem_EventIdType EventIdRef;       
  Dem_IndicatorStatusType Behavior; /* blinking , conti ...*/

  /*
  Dem_EventIdType ddNumberOfEvents;
  Dem_EventIdType ListOfEventIndex[DEM_MAX_EVENT_PER_INDICATOR];
  */

  uint8 NumFailureCycles; /* for the WarningIndicatorOnCriteria */
  uint8 NumHealingCycles; /* for the WarningIndicatorOffCriteria */
  
  Dem_NumOfIndicatorAttributeType HealingCycleCounterPos;
  Dem_NumOfIndicatorAttributeType FailureCycleCounterPos;
  Dem_NumOfIndicatorAttributeType IndicatorAttStatusPos;

  #if(DEM_OBD_SUPPORT == STD_ON)
  P2VAR(uint8, AUTOMATIC, DEM_VAR) ObdMilCycleCounter;
  #endif
} Dem_IndicatorAttributeType;

/*******************************************************************************
 ** Structure for DEM Pre Debounce Counter Type                                **
 *******************************************************************************/
#if (DEM_DEBOUNCE_COUNTER_SUPPORT == STD_ON)
typedef struct STag_Dem_PreDebounceCounterType {
  /* Step size for increment of FDC */
  uint16 usDemCountIncStepSize;

  /* Step size for decrementing the FDC */
  uint16 usDemCountDecStepSize;

  /*Counter Failed Threshold*/
  sint16 ssDemCounterFailedThreshold;

  /*Counter Passed Threshold*/
  sint16 ssDemCounterPassedThreshold;

  /*Jump Up Value */
  sint16 ssDemCounterJumpUpValue;

  /*Jump Down Value*/
  sint16 ssDemCounterJumpDownValue;

  /* Switch for the Dem Jump Down */
  boolean blDemJumpDown;

  /* Switch for the Dem Jump Up */
  boolean blDemJumpUp;

} Dem_PreDebounceCounterType;
#endif
/*******************************************************************************
 ** Structure for DEM Pre Debounce Monitor Internal Type                       **
 *******************************************************************************/
#if (DEM_NUMBER_OF_PRE_DEBOUNCE_MONITOR_INTERNAL > DEM_ZERO)
typedef struct STag_Dem_PreDebounceMonitorInternalType
{

  /* Pointer to DemCallBackGetFaultDetectionCounter Function */
  P2FUNC(Std_ReturnType, DEM_APPL_CODE, pDemCallBackGetFDCnt)
  (P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA));

  Dem_EventIdType dmi_EventId; /* not used */

}Dem_PreDebounceMonitorInternalType;
#endif
/*******************************************************************************
 ** Structure for DEM Pre Debounce Time Base Type                              **
 *******************************************************************************/
#if (DEM_DEBOUNCE_TIME_SUPPORT == STD_ON)
typedef struct STag_Dem_PreDebounceTimeBasedType {

  /* Time out duration in ms for Event Failed qualification in Dem */
  uint32 ulDemTimeFailedThreshold;

  /* Time out duration in ms for Event Passed qualification in Dem */
  uint32 ulDemTimePassedThreshold;

  /* Event Id */
  Dem_EventIdType t_EventId;

} Dem_PreDebounceTimeBasedType;
#endif




/*******************************************************************************
 ** function pointer typedefinition                                            **
 *******************************************************************************/
/* There is not return type in the AR 4.2.1 */
/* Fixed : Argument EventId is removed */
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_EvtStatusChangedFctPtrType)
(Dem_UdsStatusByteType EventStatusOld, Dem_UdsStatusByteType EventStatusNew);

typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_DtcStatusChangedFctPtrType)
(uint32 DTC, uint8 DtcStatusOld, uint8 DtcStatusNew);

typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_DtcInitMonitorOfFctPtrType)
(Dem_InitMonitorReasonType InitMonitorReason);

/*******************************************************************************
 ** Record Update Structure                                                    **
 *******************************************************************************/

typedef struct STag_Dem_RecordUpdateType {
  /* Diagnostic Trouble Code For NON-OBD*/
  uint32 ulUdsDtc;

#if (DEM_OBD_SUPPORT == STD_ON)
  /* Diagnostic Trouble Code For OBD*/
  uint16 usObdDtc;
#endif

  Dem_DTCOriginType ddDtcOrigin;

} Dem_RecordUpdateType;


/*******************************************************************************
 ** Dem General OBD                                                            **
 *******************************************************************************/
#if (DEM_OBD_SUPPORT ==  STD_ON)
typedef struct STag_Dem_GeneralOBDInfo
{
  /* Pointer to DemOBDInputAcceleratorPaddleInformation in data element array */
  P2CONST(Dem_DataElementExternalCSType, AUTOMATIC, DEM_CONST)
  pOBDInputAcceleratorPaddleInformation;

  /* Pointer to DemOBDInputAmbientPressure in data element array */
  P2CONST(Dem_DataElementExternalCSType, AUTOMATIC, DEM_CONST)
  pOBDInputAmbientPressure;

  /* Pointer to DemOBDInputAmbientTemperature in data element array */
  P2CONST(Dem_DataElementExternalCSType, AUTOMATIC, DEM_CONST)
  pOBDInputAmbientTemperature;

  /* Pointer to DemOBDInputDistanceInformation in data element array */
  P2CONST(Dem_DataElementExternalCSType, AUTOMATIC, DEM_CONST)
  pOBDInputDistanceInformation;

  /* Pointer to DemOBDInputEngineSpeed in data element array */
  P2CONST(Dem_DataElementExternalCSType, AUTOMATIC, DEM_CONST)
  pOBDInputEngineSpeed;

  /* Pointer to DemOBDInputEngineTemperature in data element array */
  P2CONST(Dem_DataElementExternalCSType, AUTOMATIC, DEM_CONST)
  pOBDInputEngineTemperature;

  /* Pointer to DemOBDInputProgrammingEvent in data element array */
  P2CONST(Dem_DataElementExternalCSType, AUTOMATIC, DEM_CONST)
  pOBDInputProgrammingEvent;

  /* Pointer to DemOBDInputVehicleSpeed in data element array */
  P2CONST(Dem_DataElementExternalCSType, AUTOMATIC, DEM_CONST)
  pOBDInputVehicleSpeed;

}Dem_GeneralOBDInfo;
#endif

/*******************************************************************************
 **   Dem RatioId                                                              **
 *******************************************************************************/

#if (DEM_OBD_SUPPORT ==  STD_ON)
typedef struct STag_Dem_RatioIdInfo
{
  /* DemDiagnosticEventRef */
  Dem_EventIdType rid_EventId;

  /* Primary DemFunctionIdRef */
  uint16 ucPrimaryFid;

  /* DemSecondaryFunctionIdRef */
  uint16 ucSecondaryFid[5];

  /* IUMPR Group assigned to the Ratio id */
  uint8 ucIUMPRGroup;

  /* DemRatioIdType */
  uint8 ucRatioIdType;
}Dem_RatioIdInfo;
#endif


typedef struct STag_Dem_TimeDebounceStatusType 
{
  /* Event Status of Time based debouncing*/
  Dem_EventStatusType tds_EventStatus;
  uint32 tds_Counter;
} Dem_TimeDebounceStatusType;


typedef struct STag_Dem_FilteredFreezeFrameRecordType
{
  Dem_EventIdType nextEvent;
  Dem_NumOfRecordNumberType nextRecord;
/*  Dem_NumOfEventIdType numOfEvents; */
} Dem_FilteredFreezeFrameRecordType;


/*******************************************************************************
 ** Structure for DEM External Data Element Class Type                         **
 *******************************************************************************/
typedef  P2FUNC(uint8, DEM_APPL_CODE, Dem_DataElementReadFuncType)(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA));

typedef struct STag_Dem_DataElementClassType {
  /*defines the prototype of the C function "ReadDataElement" */
  Dem_DataElementReadFuncType ReadFunc;

  /*Defines the size of the data element in bytes*/
  Dem_SizeOfDataElementClassType size;

  /*
   bit 0 : Defines whether DataElement is Internal Type or External type
   bit 1-7 : defines which parameter is mapped to the data element
   */
  uint8 type;
} Dem_DataElementClassType;

/******************************************************************************
 *                 Did class
 ******************************************************************************/
typedef struct STag_Dem_DidClassType {
  /* Freeze Frame is configured for Did */
  Dem_DataIdentifierType DataId;

  Dem_SizeOfDidClassType size;

  /* No of data elements */
  Dem_NumOfDataElementClassType NumOfDataElementClass;
  
  /* Size of all DataElements in bytes */
  uint16 PointToDataElementMap;
} Dem_DidClassType;


/*******************************************************************************
 ** Freeze frame class                                                        **
 *******************************************************************************/
typedef struct STag_Dem_FreezeFrameClassType {
  Dem_SizeOfFreezeFrameClassType size;
  const Dem_NumOfDidClassType NumOfDidClass;
  /* An array of the DID */
  uint16 PointToDidMap;
} Dem_FreezeFrameClassType;

/*******************************************************************************
 ** Extended data record class                                                **
 *******************************************************************************/
typedef struct STag_Dem_ExtendedDataRecordClassType {
  /* Extended Data record number */
  Dem_ExtendedDataNumberType ExtendedDataRecordNumber;

  Dem_SizeOfExtendedDataRecordClassType size;

  /* Extended data should be updated or no */
  uint8 RecordUpdate;

  /* No of data elements */
  Dem_NumOfDataElementClassType NumOfDataElementClass;

  /* An array of the Data Element */
  uint16 PointToDataElementMap;
} Dem_ExtendedDataRecordClassType;

/*******************************************************************************
 ** Extended data class                                                       **
 *******************************************************************************/
/* No of data elements */
typedef struct STag_Dem_ExtendedDataClassType {
  Dem_SizeOfExtendedDataClassType size;
  Dem_NumOfExtendedDataRecordClassType NumOfEDRecordClass;
  uint16 PointToEDRecordMap;
} Dem_ExtendedDataClassType;

/*******************************************************************************
 ** OBD freeze frame class                                                    **
 *******************************************************************************/
#if (DEM_OBD_SUPPORT == STD_ON)
typedef struct STag_Dem_PidClassType
{
  /* Freeze Frame is configured for Did */
  Dem_PidIdentifierType PidIdentifier;

  /* No of data elements */
  Dem_NumOfPidDataElementType NumOfPidDataElements;

  /* Size of all DataElements in bytes */
  Dem_SizeOfPidClassType size;

  /* An array of the Data Element */
  Dem_DataElementClassType *PidDataElement;
}Dem_PidClassType;

typedef struct STag_Dem_OBDClassType
{
  /* No of data elements */
  Dem_NumOfPidClassType NumOfPidClass;
  /* Size of all PidClass in bytes */
  Dem_SizeOfOBDFreezeFrameDataType size;
  /* An array of the Data Element */
  Dem_PidClassType *PidClass;
}Dem_OBDClassType;
#endif

/*******************************************************************************
 ** Event related data                                                        **
 *******************************************************************************/
typedef struct STag_Dem_EventRelatedData {
  Dem_EventIdType EventIdRef;

  /* Pointer to Event Data changed function*/
  /* Fixed : EventId is removed*/
  P2FUNC(Std_ReturnType, DEM_APPL_CODE, CallbackEventDataChanged)(void);

  /* Freeze Frame Pre storage is supported or not */
  boolean FFPreStorageSupported;

  Dem_NumOfRecordNumberType MaxNumOfFreezeFrameRecords;
  /* List of All Record Numbers that is configured. */
  uint16 FFRecordNumPos;

  /* An array of the DID */
  Dem_NumOfFreezeFrameClassType FFClassPos;

  Dem_NumOfExtendedDataClassType EDClassPos;

  #if (DEM_OBD_SUPPORT == STD_ON)
  CONSTP2CONST(Dem_OBDClassType, AUTOMATIC, DEM_CONST) OBDClassPos;
  #endif
} Dem_EventRelatedDataType;

/*******************************************************************************
 ** Event parameter                                                           **
 *******************************************************************************/
typedef struct STag_Dem_EventParameterType 
{
  Dem_NumOfEventRelatedDataType e_PointToData;
  /*CallBacks*/
  /* Function pointer to ClearEventAllowed */
  P2FUNC(Std_ReturnType, DEM_APPL_CODE, pDemClearEventAllowed)
  (P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) pAllowed);

  /* Function Pointer to Init Monitor For Event*/
  P2FUNC(Std_ReturnType, DEM_APPL_CODE, pDemInitMonitorForEvent)
  (Dem_InitMonitorReasonType InitMonitorReason);

  /* Operation Cycle Reference */
  uint8 e_OperationCycleId;

  #if (DEM_AGING_CYCLE_COUNTER_PROCESS == DEM_PROCESS_AGINGCTR_INTERN)
  /* Aging Cycle Reference*/
  uint8 e_AgingCycleId;
  #endif

  /* Pointer to Combined DTC array */
  uint16 e_PointToDTC;

  /* Number of Event Status functions for the event */
  uint8 ddNumOfEventStatusFct;
  /* Index of array of indexes of event status functions */
  Dem_NumOfEvtStatFctsType PointToEventStatusFncMap;

  /* Bit 0  : DEM_EVENT_KIND_BSW                      (0)
   *          DEM_EVENT_KIND_SWC                      (1)
   *
   * Bit 1-2: DEM_DEBOUNCE_COUNTER_BASED              (0x01U)
   *          DEM_DEBOUNCE_TIME_BASED                 (0x02U)
   *          DEM_DEBOUNCE_MONITOR_BASED              (0x03U)
   *          DEM_DEBOUNCE_NO_DEBOUNCE_BASED          (0x00U)
   *
   * Bit 3  : DEM_EVENT_SIGNIFICANCE_FAULT            (0x01U)
   *          DEM_EVENT_SIGNIFICANCE_OCCURRENCE       (0x00U)
   *
   * Bit 4  : AgingAllowed                            TRUE/FALSE
   *
   * Bit 5  : StorageTestFailed                       TRUE/FALSE
   *
   * Bit 6  : Reset WIR                               TRUE/FALSE
   */   
  uint8 ParamFieldsA;

  /* Index to debounce array */
  Dem_NumOfDebounceType ucIndexOfDebounceAry;

  /*Aging counter Threshold*/
  uint8 ucAgingCycleCounterThreshold;

  /* Event destinations */
  #if(DEM_MAX_EVENT_DESTINATION_SELECTED > 0u)
  uint8 aaEventDestination;
  #endif

  /* Event failure Cycle Counter Threshold */
  uint8 ucEventFailureThreshold;

  #if ((DEM_J1939_SUPPORT == STD_ON) || (DEM_EVENT_DISPLACEMENT_SUPPORT == STD_ON))
  /* Event priority */
  Dem_EventPriorityType ucEventPriority;
  #endif  

  #if (DEM_ENABLE_CONDITION_SUPPORT == STD_ON)
  /* Number of EnableConditions */
  uint8 ucNumOfEnableCondition;
  /* Index to array of EnableCondition */
  uint16 PointToEnableConditionMap;
  #endif

  #if (DEM_STORAGE_CONDITION_SUPPORT == STD_ON)
  /* Number of StorageConditions */
  uint8 ucNumOfStorageCondition;
  /* Index to array of StorageCondition */
  uint16 PointToStorageConditionMap;
  #endif

  /* @IF_REQ :   #if (DEM_NUMBER_OF_INDICATORS > 0u) */
  /* Total number of Indicators of the Event */
  uint8 ucNumberofIndicator;
  /* Array of indices of the Indicator ID array*/
  Dem_NumOfIndicatorAttributeType e_PointToIndicator;
  /* #endif */
  
  #if(DEM_OBD_SUPPORT == STD_ON)
  #if (DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO)
  uint16 usRatioIdCount;
  uint8 aaRatioIndex[DEM_NUMBER_OF_RATIO_INFO];
  #endif

  #if (DEM_PTO_SUPPORT == STD_ON)
  /* PTO is Enabled or not */
  boolean blPTOStatus;
  #endif  

  /* Event OBD Readiness Group*/
  uint32 ulEventOBDReadinessGroup;  
  uint16 usObdDtc;

  #endif
}Dem_EventParameterType;


/*******************************************************************************
 ** non-volatile data                                                         **
 *******************************************************************************/
  
  
typedef struct STag_Dcm_DTCFilterStateType {
  Dem_DTCOriginType dfs_DTCOrigin;               
  Dem_FilterForFDCType dfs_FilterForFDC;
  Dem_DTCSeverityType dfs_DTCKind;               
  Dem_DTCSeverityType dfs_DTCSeverityMask;     
  Dem_FilterWithSeverityType dfs_FilterWithSeverity;
  Dem_UdsStatusByteType dfs_DTCStatusMask;
  Dem_DTCFormatType dfs_DTCFormat;
  
  boolean dfs_JobAction;
  uint16  dfs_NumOfFilteredDTC;
  Dem_EventIdType  dfs_NextEvent;
} Dem_DTCFilterStateType;


typedef uint8 word_t;
enum
{
  NUM_OF_WORD_BITS = sizeof(word_t) * 8
};

/***************************************************************************************
 *                             CAUTION!!!!!                                            *
 *                                                                                     *
 * If the structures for event memory, the structure alignment shall be considered     *
 ***************************************************************************************/
typedef struct STag_Dem_EventStatusNvRamDataType 
{ 
  /* ISO14229 - 189 page
   * Record of the first/most recent failed DTC shall be independent of the aging process of confirmed DTCs. 
   * As  mentioned  above,  first/most  recent  failed  DTC  information  shall  be  cleared  upon  a  successful 
   * ClearDiagnosticInformation  request  from  the  client */
  #if (DEM_DCM_RPT_FAILEDCONFIRMEDDTCINFO_USED == STD_ON)
  /* the variable for DTC Request by occurrence time */
  Dem_DTCType DTCOccurenceTime[4];
  #endif


  /* @IF_REQ : if DTCAvailiableMask is 0xFF , Bit array is not good */
  /* [SWS_Dem_00525] If the configuration parameter DemStatusBitStorageTestFailed
   * is set to True, the Dem module shall retain the information for UDS DTC status bit 0
   * (TestFailed) over power cycles (non-volatile).*/
  #if (DEM_UDS_STATUS_TF_ALLEVENTSTATUS > 0U)
  uint8 TF_BitArray[DEM_BITARRAY_BITNSLOTS(1U+DEM_NUMBER_OF_EVENTS)];
  #endif

  /* [SWS_Dem_00389] 
   * Note: The information for UDS DTC status bit 1 (TestFailedThisOperationCycle) is
   * non-volatile, if the PendingDTC bit is used (refer to [SWS_Dem_00006]) or if the Dem
   * module supports operation cycles over power cycles (refer to DemOperationCycleStatusStorage). */    
  #if (DEM_UDS_STATUS_TFTOC_ALLEVENTSTATUS > 0U)
  uint8 TFTOC_BitArray[DEM_BITARRAY_BITNSLOTS(1U+DEM_NUMBER_OF_EVENTS)];
  #endif

  /* 1. [SWS_Dem_01183] The information for UDS DTC status bit 2 (PendingDTC) needs
   *    to be stored non-volatile*/
  #if (DEM_UDS_STATUS_PDTC_ALLEVENTSTATUS > 0U)
  uint8 PDTC_BitArray[DEM_BITARRAY_BITNSLOTS(1U+DEM_NUMBER_OF_EVENTS)];
  #endif

  #if (DEM_UDS_STATUS_CDTC_ALLEVENTSTATUS > 0U)
  uint8 CDTC_BitArray[DEM_BITARRAY_BITNSLOTS(1U+DEM_NUMBER_OF_EVENTS)];
  #endif

  /* [SWS_Dem_00392] 
   * Note: The information for UDS DTC status bit 4 (TestNotCompletedSinceLastClear) is
   * non-volatile. */
  #if (DEM_UDS_STATUS_TNCSLC_ALLEVENTSTATUS > 0U)
  uint8 TNCSLC_BitArray[DEM_BITARRAY_BITNSLOTS(1U+DEM_NUMBER_OF_EVENTS)];
  #endif

  /* 1. [SWS_Dem_00393] 
   *    Note: The information for UDS DTC status bit 4 (TestNotCompletedSinceLastClear) is non-volatile.
   * 2. PDTC is stored only in the event memory entry  and DemStatusBitHandlingTestFailedSinceLastClear is normal */
  #if (DEM_UDS_STATUS_TFSLC_ALLEVENTSTATUS > 0U)
  uint8 TFSLC_BitArray[DEM_BITARRAY_BITNSLOTS(1U+DEM_NUMBER_OF_EVENTS)];
  #endif  

  /* [SWS_Dem_00394] 
   * Note: The information for UDS DTC status bit 1 (TestNotCompleteThisOperationCycle) is
   * non-volatile, if the PendingDTC bit is used (refer to [SWS_Dem_00006]) or if the Dem
   * module supports operation cycles over power cycles (refer to DemOperationCycleStatusStorage). */    
  #if (DEM_UDS_STATUS_TNCTOC_ALLEVENTSTATUS > 0U)
  uint8 TNCTOC_BitArray[DEM_BITARRAY_BITNSLOTS(1U+DEM_NUMBER_OF_EVENTS)];
  #endif

  /* 2. if dispacement is not supported, WIR is stored only in the event memory */
  #if (DEM_UDS_STATUS_WIR_ALLEVENTSTATUS > 0U) 
  uint8 WIR_BitArray[DEM_BITARRAY_BITNSLOTS(1U+DEM_NUMBER_OF_EVENTS)];
  #endif

  /* @IF_REQ : healing and failure counter can be merged one variable */  
  #if (DEM_NUM_OF_HEALING_COUNTER > 0u)
  uint8 IndicatorHealingCycleCounter[DEM_NUM_OF_HEALING_COUNTER];
  #endif

  #if (DEM_NUM_OF_FAILURE_COUNTER > 0u)
  uint8 IndicatorFailureCycleCounter[DEM_NUM_OF_FAILURE_COUNTER];
  #endif
  
  #if (DEM_NUM_OF_INDICATOR_ATTRIBUTE_STATUS > 0u)
  uint8 AttributeStatus[DEM_NUM_OF_INDICATOR_ATTRIBUTE_STATUS];
  #endif

  #if ((DEM_OBD_SUPPORT == STD_ON) && (DEM_NUMBER_OF_INDICATORS > 0U))
  uint8 IndicatorMilCounter[DEM_NUMBER_OF_INDICATORS/WORD_SIZE+1];
  #endif

  uint8  EventMemoryOverflow; /* 4 bits are used */    
  
  uint8 endOfStructure;  
} Dem_EventStatusNvRamDataType;


typedef struct STag_Dem_GenericNvRamDataType 
{
  uint32 FootPrint;
  uint8  EvMemVer[4];      
  #if (DEM_OPERATION_CYCLE_STATUS_STORAGE == STD_ON)
  uint8 OperationCycleState[DEM_NUMBER_OPERATION_CYCLES];
  #endif

  uint8 endOfStructure;
} Dem_GenericNvRamDataType;


/*******************************************************************************
 ** Event memory                                                              **
 *******************************************************************************/

/* Note: Configuration dependancy
 * [1] data : DemFreeFrameClass or DemExtendedDataClass is configured 
 * [2] IndexOfFFRecords:  DemMaxNumberFreezeFrameRecords is greater than 0
 * 
 */
typedef struct STag_Dem_EventMemory 
{
  #if (DEM_EVMEM_TIMESTAMP_USED == STD_ON)
  uint32 TimeStamp;
  #endif
  
  /* Event Id which failure */
  Dem_EventIdType EventIdRef;

  #if (DEM_NVRAMBLOCK_ACCESS_OPTIMIZATION_SUPPORT == STD_ON)
  /* Event Status Byte */
  Dem_UdsStatusByteType EventStatuByte[DEM_MAX_NUM_EVENTS_PER_DTC];
  #endif

  /*
   1. The  Dem  module  shall  initialize  the  occurrence  counter  with
   the value  one  if  the  related  event  is entered in the  respective  event memory

   DEM_PROCESS_OCCCTR_TF : If  the  configuration  parameter
   DemOccurrenceCounterProcessing  (refer  to  DemGeneral)  is
   DEM_PROCESS_OCCCTR_TF,  the  Dem  module  shall  increment  the  occurrence
   counter  by one, triggered by each UDS DTC status bit 0 (TestFailed) transition from
   0 to 1, if the related event is already stored in the event memory.

   DEM_PROCESS_OCCCTR_CDTC: If  the  configuration  parameter
   DemOccurrenceCounterProcessing  (refer  to  DemGeneral)  is
   DEM_PROCESS_OCCCTR_CDTC, the Dem module shall increment the occurrence
   counter  by one, triggered by each UDS DTC status bit 0 (TestFailed) transition from
   0 to 1, if the related event is already stored in the event memory and the UDS DTC
   Status bit 3 (ConfirmedDTC) is equal to 1  */
  Dem_EventOccurrenceType EventOccurrenceCounter;

  /* To clear the event in the event memory 
  @IF_REQ : if internal data element is mapped to the aging counter, 
   this variable is deplicated entry.data[n]*/
  uint8 AgingCycleCounter;

  /* To set the confirmed bit
   * @IF_REQ : if internal data element is mapped to the healing counter, 
   * this variable is deplicated entry.data[n]*/
  #if (DEM_NUM_OF_ENABLE_TRIP_COUNTER > 1U)   
  uint8 FailureCycleCounter;
  #endif

  #if (DEM_SIZE_OF_FREEZEFRAME > 0u)
  /* IndexOfFFRecords point to empty slot of ListOfRecordNumbers. 
   * @IF_REQ: It can be calculated based on the padding data of freeze frame records */
  Dem_NumOfRecordNumberType IndexOfFFRecords;
  #endif

  /* 3. EXTENDED DATA */
  #if (DEM_SIZE_OF_EVENT_DATA > 0u)
  uint8 data[DEM_SIZE_OF_EVENT_DATA];
  #endif

  uint8 endOfStructure;
} Dem_EventMemoryEntryType;

/* @IF_REQ */
/*
typedef struct STag_Dem_ChronoEventMemoryType
{
  Dem_EventIdType EventId;
  Dem_NumOfEventMemoryEntryType ref;
} Dem_ChronoEventMemoryType;
*/
/*******************************************************************************
 ** PreStore Buffer of RAM                                                     **
 *******************************************************************************/

typedef struct STag_Dem_PrestoreBufferType {
  /* Event Id which failure */
  Dem_EventIdType EventIdRef;

  #if (DEM_SIZE_OF_PRESTORED_FF > 0U)
  uint8 data[DEM_SIZE_OF_PRESTORED_FF];
  #endif

} Dem_PrestoreBufferType;

#if (DEM_OBD_SUPPORT == STD_ON)

#if (DEM_MAX_SIZE_OF_PID_DATAELEMENT > 0U))
typedef struct STag_Dem_OBDFreezeFrameDataType
{
  /* Although structure of PIDData has logical ploblem, it is optimized about capicity
   of storage for PID.*/
  /* PID data element: Size and data */
  uint8 PIDData[DEM_MAX_NUMBER_OF_PID_DATAELEMENT][DEM_MAX_SIZE_OF_PID_DATAELEMENT];
}Dem_OBDFreezeFrameDataType;
#endif

#endif


typedef struct STag_Dem_ClearDtcStateType 
{
  uint8 cds_State; 
  Dem_ReturnClearDTCType cds_Result;
  boolean cds_RequestCancel;

  Dem_EventIdType cds_EventIdRef;
  Dem_EventIdType cds_StartEventIdRef;  

  uint32 cds_DTC;
  Dem_DTCFormatType cds_DTCFormat;
  Dem_DTCOriginType cds_DTCOrigin;
  Dem_NumOfEventMemoryEntryType cds_MemLocation;

  uint8 cds_User;
} Dem_ClearDtcStateType;

typedef struct STag_Dem_EvMemTriggerType
{
  boolean readNvBlocksTrigger;
  boolean writeNvBlocksTrigger;
  boolean waitNvBlocksJobFinishTrigger; 
  uint8   writeNvBlocksEndModeTrigger;
  Std_ReturnType nvmResult;
} Dem_EvMemTriggerType;


/* @IF_REQ
typedef struct STag_Dem_OperationCycleAsyncStateType
{
  Dem_OperationCycleStateType ocs_State;
  boolean ocs_Trigger;
} Dem_OperationCycleAyncStateType;
*/

/*******************************************************************************
 **                      extern declarations                                   **
 *******************************************************************************/

/*******************************************************************************
 ** Definition and configuration of Event Parameter Structure                  **
 *******************************************************************************/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (DEM_NUM_OF_PRIMARY_EVENTMEMORY_NVBLOCKID > 0U)
/* Array Dem_PrimaryNvmBlockId */
extern CONST(NvM_BlockIdType, DEM_CONST) Dem_PrimaryEventMemoryNvmBlockId[];
#endif

#if (DEM_NUM_OF_SECONDARY_EVENTMEMORY_NVBLOCKID > 0U)
/* Array Dem_PrimaryNvmBlockId */
extern CONST(NvM_BlockIdType, DEM_CONST) Dem_SecondaryEventMemoryNvmBlockId[];
#endif

#if (DEM_NO_OF_OPERATIONCYCLECONFIGURED > 0u)
extern CONST(Dem_OperationCycleName, DEM_CONST)  Dem_GstOperationCycleName[];
#endif

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
 ** Definition and configuration of Combined Dtc Structure                     **
 *******************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONST(Dem_CombinedDtcType, DEM_CONST) Dem_GaaCombinedDtc[];

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONST(Dem_EventIdType, DEM_CONST) Dem_ListOfCombinedEvents[];

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
 ** Array of PIDs                                                              **
 *******************************************************************************/
#if (DEM_OBD_SUPPORT ==  STD_ON)
#if (DEM_MAX_NUMBER_OF_PID_RECDS > DEM_ZERO)

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONST(Dem_PidRecordType, DEM_CONST) Dem_GaaPid[];

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#endif
#endif
/*******************************************************************************
 ** Array of PIDs                                                              **
 *******************************************************************************/
#if (DEM_OBD_SUPPORT ==  STD_ON)
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#if(DEM_MAX_NUMBER_OF_PID_DATAELEMENT > DEM_ZERO)
extern CONST(Dem_PidDataElementType, DEM_CONST) Dem_GaaDataElementRefAry[];
#endif
#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif
/*******************************************************************************
 ** Operation cycle information                                                **
 *******************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONST(Dem_OperationCycleType, DEM_CONST)
    Dem_GaaOperationCycleIdsList[];

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
 ** Enable Condition information                                               **
 *******************************************************************************/
#if (DEM_NUMBER_ENABLE_CONDITION > DEM_ZERO)
#define DEM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"
extern CONST(boolean, DEM_CONST)
    Dem_GaaEnableCondition[];

#define DEM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"
#endif

/*******************************************************************************
 ** Storage Condition information                                              **
 *******************************************************************************/
#if (DEM_NUMBER_STORAGE_CONDITION > DEM_ZERO)
#define DEM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

extern CONST(boolean, DEM_CONST)
    Dem_GaaStorageCondition[];

#define DEM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"
#endif
/*******************************************************************************
 ** Pre Debounce Counter information                                           **
 *******************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (DEM_NUMBER_OF_PRE_DEBOUNCE_COUNTER > DEM_ZERO)
extern CONST(Dem_PreDebounceCounterType, DEM_CONST) 
  Dem_GaaPreDebounceCounter[];
#endif

/*******************************************************************************
 ** Pre Debounce Monitor Internal information                                  **
 *******************************************************************************/
#if (DEM_NUMBER_OF_PRE_DEBOUNCE_MONITOR_INTERNAL > DEM_ZERO)
extern CONST(Dem_PreDebounceMonitorInternalType, DEM_CONST)
Dem_GaaPreDebounceMonitorInternal[];
#endif

/*******************************************************************************
 ** Pre Debounce Time information                                              **
 *******************************************************************************/
#if (DEM_NUMBER_OF_PRE_DEBOUNCE_TIME > 0u)
extern CONST(Dem_PreDebounceTimeBasedType, DEM_CONST)
    Dem_GaaPreDebounceTimeBased [];
#endif

/*******************************************************************************
 ** List of supported IndicatorIds                                             **
 *******************************************************************************/
#if(DEM_NUMBER_OF_INDICATORS > DEM_ZERO)
extern CONST(Dem_IndicatorAttributeType, DEM_CONST) Dem_GaaIndicatorList[];
#endif

/*******************************************************************************
 ** General OBD Information                                                    **
 *******************************************************************************/
#if (DEM_OBD_SUPPORT ==  STD_ON)
extern CONST(Dem_GeneralOBDInfo, DEM_CONST)Dem_GstGeneralOBDInfo[];
#endif

/*******************************************************************************
 ** Array of ratio Id Info                                                     **
 *******************************************************************************/
#if((DEM_NUMBER_OF_RATIO_INFO > DEM_ZERO) && (DEM_OBD_SUPPORT == STD_ON))
extern CONST(Dem_RatioIdInfo, DEM_CONST)
Dem_GaaRatioIdInfo[];
#endif

/*******************************************************************************
 ** Array of Function Pointers to Event Status Changed Function                **
 *******************************************************************************/
extern CONST(Dem_EvtStatusChangedFctPtrType, DEM_CONST) 
  Dem_ListOfEvtStatusChangedFctPtr[];

/*******************************************************************************
 ** Array of Function Pointers to Event Status Changed Function                **
 *******************************************************************************/
extern CONST(Dem_DtcStatusChangedFctPtrType, DEM_CONST)
Dem_GaaDtcStatusChangedFctPtr[];

/*******************************************************************************
 ** Array of group of DTC's
 *******************************************************************************/
extern CONST(Dem_DTCGroupType, DEM_CONST) Dem_GaaGroupDTC[];

/********************************************************************/
#if (DEM_SIZE_OF_EXTENDED_DATA > 0U)
extern CONST(Dem_ExtendedDataRecordClassType, DEM_CONST)
  Dem_ExtendedDataRecordClass[];

extern CONST(Dem_ExtendedDataClassType, DEM_CONST)
  Dem_ExtendedDataClass[];
#endif

/********************************************************************/
#if (DEM_SIZE_OF_EXTENDED_DATA > 0U)
extern CONST(Dem_NumOfExtendedDataRecordClassType, DEM_CONST)
  Dem_ListOfEDRecordClassIndex[];
#endif

#if (DEM_SIZE_OF_FREEZEFRAME > 0u)
extern CONST(Dem_RecordNumberType, DEM_CONST) Dem_ListOfFFRecordNumbers[];
extern CONST(Dem_FreezeFrameClassType, DEM_CONST) Dem_FreezeFrameClass[];
#endif

/********************************************************************/
#if (DEM_SIZE_OF_EVENT_DATA > 0U)
extern CONST(Dem_EventRelatedDataType, DEM_CONST) Dem_EventRelatedData[];
#endif

extern CONST(uint8, DEM_CONST) Dem_ListOfEnableConditionGroupId[];

extern CONST(Dem_EventParameterType, DEM_CONST) Dem_Event[];


/********************************************************************/
#if (DEM_SIZE_OF_EVENT_DATA > 0U)
extern CONST(Dem_DataElementClassType, DEM_CONST) Dem_DataElementClass[];
#endif

/********************************************************************/
#if (DEM_SIZE_OF_EVENT_DATA > 0U)
extern CONST(Dem_NumOfDataElementClassType, DEM_CONST) 
  Dem_ListOfDataElementClassIndex[];
#endif

/********************************************************************/
#if (DEM_SIZE_OF_FREEZEFRAME > 0U)
extern CONST(Dem_DidClassType, DEM_CONST) Dem_DidClass[];
#endif
/********************************************************************/
#if (DEM_SIZE_OF_FREEZEFRAME > 0U)
extern CONST(Dem_NumOfDidClassType, DEM_CONST) Dem_ListOfDidClassIndex[];
#endif

#if (DEM_MAX_LISTOFENABLECONDITIONID > 0U)
extern CONST(uint8, DEM_CONST) Dem_ListOfEnableConditionId[];
#endif

#if (DEM_MAX_LISTOFSTORAGECONDITIONID > 0U)
extern CONST(uint8, DEM_CONST) Dem_ListOfStorageConditionId[];
#endif


#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"



/*******************************************************************************
 ** Definition of type                                                        **
 *******************************************************************************/
/* types of the event parameter */
typedef P2VAR(Dem_EventParameterType,AUTOMATIC,DEM_VAR) Dem_EventParameterPtrType;
typedef P2CONST(Dem_EventParameterType,AUTOMATIC,DEM_VAR) Dem_EventParameterPCType;
typedef CONSTP2CONST(Dem_EventParameterType,AUTOMATIC,DEM_CONST) Dem_EventParameterCPCType;

/* types of the event memory */
typedef P2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR) Dem_EventMemoryEntryPtrType;
typedef P2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_VAR) Dem_EventMemoryEntryPCType;
typedef CONSTP2VAR(Dem_EventMemoryEntryType, AUTOMATIC, DEM_CONST) Dem_EventMemoryEntryCPType;
typedef CONSTP2CONST(Dem_EventMemoryEntryType, AUTOMATIC, DEM_CONST) Dem_EventMemoryEntryCPCType;

typedef CONSTP2CONST(Dem_DataElementClassType, AUTOMATIC, DEM_CONST) Dem_DataElementClassCPCType;

typedef CONSTP2CONST(Dem_DidClassType, AUTOMATIC, DEM_CONST) Dem_DidClassCPCType;

typedef P2CONST(Dem_FreezeFrameClassType, AUTOMATIC, DEM_CONST) Dem_FreezeFrameClassPCType;
typedef CONSTP2CONST(Dem_FreezeFrameClassType, AUTOMATIC, DEM_CONST) Dem_FreezeFrameClassCPCType;

typedef P2CONST(Dem_CombinedDtcType, AUTOMATIC,  DEM_CONST) Dem_CombinedDtcPCType;


typedef CONSTP2CONST(Dem_ExtendedDataRecordClassType, AUTOMATIC, DEM_CONST) Dem_ExtendedDataRecordClassCPCType;

typedef P2CONST(Dem_ExtendedDataClassType, AUTOMATIC, DEM_CONST) Dem_ExtendedDataClassPCType;
typedef CONSTP2CONST(Dem_ExtendedDataClassType, AUTOMATIC, DEM_CONST) Dem_ExtendedDataClassCPCType;



typedef CONSTP2CONST(Dem_EventRelatedDataType, AUTOMATIC, DEM_CONST) Dem_EventRelatedDataCPCType;
typedef P2CONST(Dem_EventRelatedDataType, AUTOMATIC, DEM_VAR) Dem_EventRelatedDataPCType;
typedef P2VAR(Dem_EventRelatedDataType, AUTOMATIC, DEM_VAR) Dem_EventRelatedDataPtrType;

/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
/* polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations> Not a defect */
/* polyspace:end<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */


#endif /* DEM_PCTYPES_H */
/*******************************************************************************
 **                      End of File                                           **
 *******************************************************************************/
