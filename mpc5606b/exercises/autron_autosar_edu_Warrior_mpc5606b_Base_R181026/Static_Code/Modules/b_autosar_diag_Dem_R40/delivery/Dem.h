/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem.h                                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Event Manager                              **
**                                                                            **
**  PURPOSE   : Provision of extern declarations of APIs and Service ID       **
**              macros                                                        **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By          Description                            **
********************************************************************************
** 1.1.0    06-02-2016     YoungJin.Yun   Changes made As per Redmine #7379   **
**                                                                            **
** 1.0.2     16-04-2015    Sungeol Baek     As per reminde #2171              **
**                                           MISRA Rule modification          **
** ---------------------------------------------------------------------------**
** 1.0.1    26-Mar-2015   YJ.Yun      Removed DEM_SETAGINGCYCLESTATE_SID to be**
**                                    not supported                           **
** ---------------------------------------------------------------------------**
** 1.0.0    01-Jan-2013   Autron      Initial Version                         **
*******************************************************************************/

#ifndef DEM_H
#define DEM_H

/* 
   polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect
   polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations> Not a defect
   polyspace:begin<MISRA-C:8.8:Not a defect:Justify with annotations> Not a defect 
*/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem_Types.h"
#include "Dem_PCTypes.h" 
#include "Dem_Cfg.h"     /* Dem_PBcfg.h [SWS_Dem_00151 */
#include "Dem_Config.h"
#if (DEM_J1939_SUPPORT == STD_ON)
#include "Dem_J1939.h" /* J1939 */
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define DEM_UNUSED(x)                 do\
{\
  /* polyspace<RTE:UNR:Not a defect:No action planned> No problem. Unreachable code */\
  if((uint8)(x) != (uint8)DEM_ZERO) \
  /* polyspace<RTE:UNR:Not a defect:No action planned> No problem. Unreachable code */\
  {\
  }\
} while(0)

#define DEM_UNUSED_PTR(x)             do\
{\
  /* polyspace<RTE:UNR:Not a defect:No action planned> No problem. Unreachable code */\
  if((x) != NULL_PTR) \
  /* polyspace<RTE:UNR:Not a defect:No action planned> No problem. Unreachable code */\
  {\
  }\
} while(0)

/* Instance ID */
#define DEM_INSTANCE_ID                                       ((uint8)0x00)
/* Service ID for Dem_GetVersionInfo*/
#define DEM_GETVERSIONINFO_SID                                ((uint8)0x00)
/* Service ID for Dem_Init */
#define DEM_INIT_SID                                          ((uint8)0x02)
/* Service ID for Dem_Shutdown */
#define DEM_SHUTDOWN_SID                                      ((uint8)0x03)
/* Service ID for Dem_SetEventStatus  */
#define DEM_SETEVENTSTATUS_SID                                ((uint8)0x04)
/* Service ID for Dem_ResetEventStatus */
#define DEM_RESETEVENTSTATUS_SID                              ((uint8)0x05)
/* Service ID for Dem_PrestoreFreezeFrame */
#define DEM_PRESTOREFREEZEFRAME_SID                           ((uint8)0x06)
/* Service ID for Dem_ClearPrestoredFreezeFrame */
#define DEM_CLEARPRESTOREDFREEZEFRAME_SID                     ((uint8)0x07)
/* Service ID for Dem_SetOperationCycleState */
#define DEM_SETOPERATIONCYCLESTATE_SID                        ((uint8)0x08)
/* Service ID for Dem_GetEventStatus */
#define DEM_GETEVENTSTATUS_SID                                ((uint8)0x0a)
/* Service ID for Dem_GetEventFailed */
#define DEM_GETEVENTFAILED_SID                                ((uint8)0x0b)
/* Service ID for Dem_GetEventTested */
#define DEM_GETEVENTTESTED_SID                                ((uint8)0x0c)
/* Service ID for Dem_GetDTCOfEvent */
#define DEM_GETDTCOFEVENT_SID                                 ((uint8)0x0d)
/* Service ID for Dem_GetSeverityOfDTC */
#define DEM_GETSEVERITYOFDTC_SID                              ((uint8)0x0e)
/* Service ID for Dem_ReportErrorStatus */
#define DEM_REPORTERRORSTATUS_SID                             ((uint8)0x0f)
/* Service ID for Dem_SetDTCFilter */
#define DEM_SETDTCFILTER_SID                                  ((uint8)0x13)
/* Service ID for Dem_GetStatusOfDTC */
#define DEM_GETSTATUSOFDTC_SID                                ((uint8)0x15)
/* Service ID for Dem_GetDTCStatusAvailabilityMask */
#define DEM_GETDTCSTATUSAVAILABILITYMASK_SID                  ((uint8)0x16)
/* Service ID for Dem_GetNumberOfFilteredDTC */
#define DEM_GETNUMBEROFFILTEREDDTC_SID                        ((uint8)0x17)
/* Service ID for Dem_GetNextFilteredDTC */
#define DEM_GETNEXTFILTEREDDTC_SID                            ((uint8)0x18)
/* Service ID for Dem_GetDTCByOccurrenceTime */
#define DEM_GETDTCBYOCCURRENCETIME_SID                        ((uint8)0x19)
/* Service ID for Dem_DisableDTCRecordUpdate */
#define DEM_DISABLEDTCRECORDUPDATE_SID                        ((uint8)0x1a)
/* Service ID for Dem_EnableDTCRecordUpdate */
#define DEM_ENABLEDTCRECORDUPDATE_SID                         ((uint8)0x1b)
/* Service ID for Dem_GetFreezeFrameDataByDTC */
#define DEM_GETFREEZEFRAMEDATABYDTC_SID                       ((uint8)0x1d)
/* Service ID for Dem_GetExtendedDataRecordByDTC */
#define DEM_GETEXTENDEDDATARECORDBYDTC_SID                    ((uint8)0x20)
/* Service ID for Dem_GetSizeOfExtendedDataRecordByDTC */
#define DEM_GETSIZEOFEXTENDEDDATARECORDBYDTC_SID              ((uint8)0x21)
/* Service ID for Dem_ClearDTC */
#define DEM_CLEARDTC_SID                                      ((uint8)0x22)
/* Service ID for Dem_GetIndicatorStatus */
#define DEM_GETINDICATORSTATUS_SID                            ((uint8)0x29)
/* Service ID for Dem_MainFunction */
#define DEM_MAINFUNCTION_SID                                  ((uint8)0x55)
/* Service ID for Dem_SetEnableCondition */
#define DEM_SETENABLECONDITION_SID                            ((uint8)0x39)
/* Service ID for Dem_GetNextFilteredRecord */
#define DEM_GETNEXTFILTEREDRECORD_SID                         ((uint8)0x3a)
/* Service ID for Dem_GetNextFilteredDTCAndFDC */
#define DEM_GETNEXTFILTEREDDTCANDFDC_SID                      ((uint8)0x3b)
/* Service ID for Dem_GetNextFilteredDTCAndSeverity */
#define DEM_GETNEXTFILTEREDDTCANDSEVERITY_SID                 ((uint8)0x3d)
/* Service ID for Dem_GetTranslationType */
#define DEM_GETTRANSLATIONTYPE_SID                            ((uint8)0x3c)
/* Service ID for Dem_GetFaultDetectionCounter */
#define DEM_GETFAULTDETECTIONCOUNTER_SID                      ((uint8)0x3e)
/* Service ID for Dem_SetEventDisabled */
#define DEM_SETEVENTDISABLED_SID                              ((uint8)0x51)
/* Service ID for Dem_GetEventMemoryOverflow*/
#define DEM_GETEVENTMEMORYOVERFLOW_SID                        ((uint8)0x32)
/* Service ID for Dem_SetAgingCycleCounterValue*/
#define DEM_SETAGINGCYCLECOUNTERVALUE_SID                     ((uint8)0x12)

/* Service ID for Dem_SetAgingCycleState*/
/* #define DEM_SETAGINGCYCLESTATE_SID                         ((uint8)0x11)*/

/* Service ID for Dem_SetStorageCondition*/
#define DEM_SETSTORAGECONDITION_SID                           ((uint8)0x38)
/* Service ID for Dem_GetEventExtendedDataRecord*/
#define DEM_GETEVENTEXTENDEDDATARECORD_SID                    ((uint8)0x30)
/* Service ID for Dem_GetEventFreezeFrameData*/
#define DEM_GETEVENTFREEZEFRAMEDATA_SID                       ((uint8)0x31)
/* Service ID for Dem_SetDTCSuppression*/
#define DEM_SETDTCSUPPRESSION_SID                             ((uint8)0x33)
/* Service ID for Dem_SetFreezeFrameRecordFilter*/
#define DEM_SETFREEZEFRAMERECORDFILTER_SID                    ((uint8)0x3f)
/* Service ID for Dem_GetFunctionalUnitOfDTC*/
#define DEM_GETFUNCTIONALUNITOFDTC_SID                        ((uint8)0x34)
/* Service ID for Dem_GetFreezeFrameDataByRecord*/
#define DEM_GETOBDFREEZEFRAMEDATABYRECORD_SID                 ((uint8)0x1c)
#define DEM_GETFREEZEFRAMEDATABYRECORD_SID                    ((uint8)0x1c)


/*  Dem_GetFreezeFrameDataByRecord is renamed  
    to Dem_DcmGetOBDFreezeFrameData()  in the AUTOSAR R4.1.2*/ 
    
/* Service ID for Dem_DcmGetOBDFreezeFrameData*/
#define DEM_GETOBDFREEZEFRAMEDATA_SID                         ((uint8)0x1c)


/* Service ID for Dem_GetSizeOfFreezeFrameByDTC*/
#define DEM_GETSIZEOFFREEZEFRAMEBYDTC_SID                     ((uint8)0x1f)
/* Service ID for Dem_DisableDTCSetting*/
#define DEM_DISABLEDTCSETTING_SID                             ((uint8)0x24)
/* Service ID for Dem_EnableDTCSetting*/
#define DEM_ENABLEDTCSETTING_SID                              ((uint8)0x25)
/* Service ID for Dem_DcmCancelOperation*/
#define DEM_DCMCANCELOPERATION_SID                            ((uint8)0x2a)
/* Service ID for Dem_DcmReadDataOfPID01*/
#define DEM_DCMREADDATAOFPID01_SID                            ((uint8)0x61)
/* Service ID for Dem_DcmReadDataOfPID1C*/
#define DEM_DCMREADDATAOFPID1C_SID                            ((uint8)0x63)
/* Service ID for Dem_DcmReadDataOfPID21*/
#define DEM_DCMREADDATAOFPID21_SID                            ((uint8)0x64)
/* Service ID for Dem_DcmReadDataOfPID30*/
#define DEM_DCMREADDATAOFPID30_SID                            ((uint8)0x65)
/* Service ID for Dem_DcmReadDataOfPID31*/
#define DEM_DCMREADDATAOFPID31_SID                            ((uint8)0x66)
/* Service ID for Dem_DcmReadDataOfPID41*/
#define DEM_DCMREADDATAOFPID41_SID                            ((uint8)0x67)
/* Service ID for Dem_DcmReadDataOfPID4D*/
#define DEM_DCMREADDATAOFPID4D_SID                            ((uint8)0x68)
/* Service ID for Dem_DcmReadDataOfPID4E*/
#define DEM_DCMREADDATAOFPID4E_SID                            ((uint8)0x69)
/* Service ID for Dem_ReadDataOfOBDFreezeFrame*/
#define DEM_READDATAOFOBDFREEZEFRAME_SID                      ((uint8)0x52)
/* Service ID for Dem_GetDTCOfOBDFreezeFrame*/
#define DEM_GETDTCOFOBDFREEZEFRAME_SID                        ((uint8)0x53)
/* Service ID for Dem_SetPtoStatus*/
#define DEM_SETPTOSTATUS_SID                                  ((uint8)0x79)
/* Service ID for Dem_RepIUMPRFaultDetect*/
#define DEM_REPIUMPRFAULTDETECT_SID                           ((uint8)0x73)
/* Service ID for Dem_RepIUMPRFaultDetect*/
#define DEM_REPIUMPRDENLOCK_SID                               ((uint8)0x71)
/* Service ID for Dem_RepIUMPRDenRelease*/
#define DEM_REPIUMPRDENRELEASE_SID                            ((uint8)0x72)
/* Service ID for Dem_GetInfoTypeValue08*/
#define DEM_GETINFOTYPEVALUE08_SID                            ((uint8)0x6b)
/* Service ID for Dem_GetInfoTypeValue0B*/
#define DEM_GETINFOTYPEVALUE0B_SID                            ((uint8)0x6c)
/* Service ID for Dem_DltGetMostRecentFreezeFrameRecordData*/
#define DEM_DLTGETMOSTRECENTFREEZEFRAMERECORDDATA_SID         ((uint8)0x41)
/* Service ID for Dem_DltGetAllExtendedDataRecords*/
#define DEM_DLTGETALLEXTENDEDDATARECORDS_SID                  ((uint8)0x40)

/* Autron specific sid */
#define DEM_EVMEM_FINDNEWOREXISTEDENTRY_SID                   ((uint8)0x60)
#define DEM_UNSPECIFIED_SID                                   ((uint8)0xFE)
#define DEM_CAPTUREDATAELEMENTCLASS_SID                       ((uint8)0xFD)


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"

/* Called by BswM */
extern FUNC(void, DEM_CODE) Dem_ReadNvData(void);

/* Called by BswM */
extern FUNC(void, DEM_CODE) Dem_WriteNvData(void);

/* 
  polyspace:begin<MISRA-C:16.4:Not a defect:Justify with annotations> Not a defect 
*/

/* Dem_GetVersionInfo */
extern FUNC(void, DEM_CODE) Dem_GetVersionInfo
  (P2VAR(Std_VersionInfoType, AUTOMATIC, DEM_APPL_DATA) versioninfo);

/* Dem_PreInit */
extern FUNC(void, DEM_CODE) Dem_PreInit(
  P2CONST(Dem_ConfigType, AUTOMATIC, DEM_APPL_CONST)Dem_ConfigPtr);

/* Dem_Init */
extern FUNC(void, DEM_CODE) Dem_Init(void);

/* Dem_Shutdown */
extern FUNC(void, DEM_CODE) Dem_Shutdown(void);

/* Dem_ReportErrorStatus */
extern FUNC(void, DEM_CODE) Dem_ReportErrorStatus(
  Dem_EventIdType EventId,
  Dem_EventStatusType EventStatus);

/* Dem_GetEventStatus */
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventStatus(
  Dem_EventIdType EventId,
  P2VAR (Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA)
  EventStatusExtended);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus
  (Dem_EventIdType EventId, Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventStatus(
  Dem_EventIdType EventId);

/* Dem_GetEventFailed */
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFailed(
  Dem_EventIdType EventId, 
  P2VAR (boolean, AUTOMATIC, DEM_APPL_DATA) EventFailed);

/* Dem_GetEventTested */
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventTested(
  Dem_EventIdType EventId,
  P2VAR (boolean, AUTOMATIC, DEM_APPL_DATA)EventTested);

/* Dem_GetDTCOfEvent */
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCOfEvent(
  Dem_EventIdType EventId,
  Dem_DTCFormatType DTCFormat,
  P2VAR (uint32, AUTOMATIC, DEM_APPL_DATA) DTCOfEvent);

/* Dem_SetEnableCondition */
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetEnableCondition
  (uint8 EnableConditionID, boolean ConditionFulfilled);

/* Dem_SetStorageCondition */
extern  FUNC(Std_ReturnType, DEM_CODE) Dem_SetStorageCondition(
  uint8 StorageConditionID, 
  boolean ConditionFulfilled);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetOperationCycleState(
  uint8  OperationCycleId,
  Dem_OperationCycleStateType CycleState);

/* Dem_GetIndicatorStatus */
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetIndicatorStatus(
  uint8 IndicatorId,
  P2VAR (Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA) IndicatorStatus);

/* Dem_GetEventFreezeFrameData */
extern FUNC(Std_ReturnType, DEM_CODE)Dem_GetEventFreezeFrameData(
  Dem_EventIdType EventId, 
  uint8 RecordNumber, 
  boolean ReportTotalRecord,
  uint16 DataIdentifier, 
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer);

/* Dem_GetEventExtendedDataRecord */
extern FUNC(Std_ReturnType, DEM_CODE)Dem_GetEventExtendedDataRecord(
  Dem_EventIdType EventId,
  uint8 RecordNumber,
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer);

/* Dem_GetEventMemoryOverflow */
extern FUNC(Std_ReturnType, DEM_CODE)Dem_GetEventMemoryOverflow(
  Dem_DTCOriginType DTCOrigin,
  P2VAR (boolean, AUTOMATIC, DEM_APPL_DATA) OverflowIndication);

#if(DEM_DTC_SUPPRESSION_SUPPORT == STD_ON)
extern FUNC(Std_ReturnType, DEM_CODE)Dem_SetDTCSuppression(
  uint32 DTC, 
  Dem_DTCFormatType DTCFormat, 
  boolean SuppressionStatus);
#endif
/* Dem_SetDTCFilter */
extern FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_SetDTCFilter(
  uint8 DTCStatusMask, 
  Dem_DTCKindType DTCKind, 
  Dem_DTCFormatType DTCFormat,
  Dem_DTCOriginType DTCOrigin, 
  Dem_FilterWithSeverityType FilterWithSeverity,
  Dem_DTCSeverityType DTCSeverityMask,
  Dem_FilterForFDCType FilterForFaultDetectionCounter);

/* Dem_SetFreezeFrameRecordFilter */
extern FUNC(Dem_ReturnSetFilterType, DEM_CODE)Dem_SetFreezeFrameRecordFilter(
  Dem_DTCFormatType DTCFormat,
  P2VAR (uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredRecords);

/* Dem_GetStatusOfDTC */
extern FUNC(Dem_ReturnGetStatusOfDTCType, DEM_CODE) Dem_GetStatusOfDTC(
  uint32 DTC, Dem_DTCOriginType DTCOrigin,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus);

/* Dem_GetDTCStatusAvailabilityMask */
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCStatusAvailabilityMask(
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatusMask);

/* Dem_GetNumberOfFilteredDTC */
extern FUNC(Dem_ReturnGetNumberOfFilteredDTCType, DEM_CODE)
  Dem_GetNumberOfFilteredDTC(
  P2VAR (uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredDTC);

/* Dem_GetNextFilteredDTC */
extern FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE)Dem_GetNextFilteredDTC(
  P2VAR (uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus);

/* Dem_GetDTCByOccurrenceTime */
extern FUNC(Dem_ReturnGetDTCByOccurrenceTimeType, DEM_CODE) Dem_GetDTCByOccurrenceTime(
  Dem_DTCRequestType DTCRequest,
  P2VAR (uint32, AUTOMATIC, DEM_APPL_DATA) DTC);

/* Dem_GetNextFilteredRecord */
extern FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE)Dem_GetNextFilteredRecord(
  P2VAR (uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) RecordNumber);

/* Dem_GetNextFilteredDTCAndFDC */
extern FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE)
  Dem_GetNextFilteredDTCAndFDC(
  P2VAR (uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
  P2VAR (sint8, AUTOMATIC, DEM_APPL_DATA) DTCFaultDetectionCounter);

/* Dem_GetNextFilteredDTCAndSeverity */
extern FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE) Dem_GetNextFilteredDTCAndSeverity(
  P2VAR (uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus,
  P2VAR (Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity,
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) DTCFunctionalUnit);

/* Dem_GetTranslationType */
extern FUNC(Dem_DTCTranslationFormatType, DEM_CODE)Dem_GetTranslationType(void);

/* Dem_GetSeverityOfDTC */
extern FUNC(Dem_ReturnGetSeverityOfDTCType, DEM_CODE)Dem_GetSeverityOfDTC(
  uint32 DTC,
  P2VAR (Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity);

/* Dem_GetFunctionalUnitOfDTC */
extern FUNC(Dem_ReturnGetFunctionalUnitOfDTCType, DEM_CODE) Dem_GetFunctionalUnitOfDTC(
  uint32 DTC,
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) DTCFunctionalUnit);

/* Dem_DisableDTCRecordUpdate */
extern FUNC(Dem_ReturnDisableDTCRecordUpdateType, DEM_CODE) Dem_DisableDTCRecordUpdate(
  uint32 DTC, 
  Dem_DTCOriginType DTCOrigin);

/* Dem_EnableDTCRecordUpdate */
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EnableDTCRecordUpdate(void);

/* If absolute addressing is used a unique record number for a
   freeze frame exists throughout the whole ECU. */
#if (DEM_OBD_SUPPORT == STD_ON) /* Unused macro|| DEM_RECORD_UNIQUE_SERVER == STD_ON) */
/* Dem_GetFreezeFrameDataByRecord */
extern FUNC(Dem_ReturnGetFreezeFrameDataByRecordType, DEM_CODE) Dem_GetFreezeFrameDataByRecord(
  uint8 RecordNumber,
  Dem_DTCOriginType DTCOrigin, 
  P2VAR (uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
  P2VAR (uint16, AUTOMATIC, DEM_APPL_DATA) BufSize);
#endif

/* Dem_GetFreezeFrameDataByDTC */
extern FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE) Dem_GetFreezeFrameDataByDTC(
  uint32 DTC, 
  Dem_DTCOriginType DTCOrigin,
  uint8 RecordNumber, 
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
  P2VAR (uint16, AUTOMATIC, DEM_APPL_DATA) BufSize);

/* Dem_GetSizeOfFreezeFrameByDTC */
extern FUNC(Dem_ReturnGetSizeOfFreezeFrameByDTCType, DEM_CODE) Dem_GetSizeOfFreezeFrameByDTC(
  uint32 DTC, 
  Dem_DTCOriginType DTCOrigin,
  uint8 RecordNumber, 
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)SizeOfFreezeFrame);

/* Dem_GetExtendedDataRecordByDTC */
extern FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE) Dem_GetExtendedDataRecordByDTC(
  uint32 DTC, 
  Dem_DTCOriginType DTCOrigin,
  uint8 ExtendedDataNumber, 
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize);

/* Dem_GetSizeOfExtendedDataRecordByDTC */
extern FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE) Dem_GetSizeOfExtendedDataRecordByDTC(
  uint32 DTC, 
  Dem_DTCOriginType DTCOrigin,
  uint8 ExtendedDataNumber,
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord);

/* Dem_DisableDTCSetting */
extern FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE)Dem_DisableDTCSetting(
  Dem_DTCGroupType DTCGroup, 
  Dem_DTCKindType DTCKind);

/* Dem_EnableDTCSetting */
extern FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE)Dem_EnableDTCSetting(
  Dem_DTCGroupType DTCGroup, 
  Dem_DTCKindType DTCKind);

/* Dem_DcmCancelOperation */
extern FUNC(void, DEM_CODE) Dem_DcmCancelOperation(void);

#if (DEM_TRIGGER_DLT_REPORTS == STD_ON)
extern FUNC(Std_ReturnType, DEM_CODE)Dem_DltGetMostRecentFreezeFrameRecordData(
  Dem_EventIdType EventId, 
  uint8* DestBuffer, 
  uint16* BufSize);
#endif

#if(DEM_TRIGGER_DLT_REPORTS == STD_ON)
extern FUNC(Std_ReturnType, DEM_CODE)Dem_DltGetAllExtendedDataRecords(
  Dem_EventIdType EventId, 
  uint8* DestBuffer, 
  uint16* BufSize);
#endif

#if (DEM_OBD_SUPPORT == STD_ON)
extern FUNC(Std_ReturnType, DEM_CODE)Dem_SetEventDisabled(
  Dem_EventIdType EventId);

/* Dem_RepIUMPRFaultDetect */
extern FUNC(Std_ReturnType, DEM_CODE)Dem_RepIUMPRFaultDetect(
Dem_RatioIdType RatioID);

/* Dem_RepIUMPRDenLock */
extern FUNC(Std_ReturnType, DEM_CODE)Dem_RepIUMPRDenLock(
Dem_RatioIdType RatioID);

/* Dem_RepIUMPRDenRelease */
extern FUNC(Std_ReturnType, DEM_CODE)Dem_RepIUMPRDenRelease(
Dem_RatioIdType RatioID);

/* Dem_GetInfoTypeValue08 */
extern FUNC(Std_ReturnType, DEM_CODE)Dem_GetInfoTypeValue08(
  Dcm_OpStatusType OpStatus,
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08);

/* Dem_GetInfoTypeValue0B */
extern FUNC(Std_ReturnType, DEM_CODE)Dem_GetInfoTypeValue0B(
  Dcm_OpStatusType OpStatus,
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0B);

/* Dem_DcmReadDataOfPID01 */
extern FUNC(Std_ReturnType, DEM_CODE)Dem_DcmReadDataOfPID01(
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) PID01Value);

/* Dem_DcmReadDataOfPID1C */
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID1C(
 P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID1CValue);

/* Dem_DcmReadDataOfPID21 */
extern FUNC(Std_ReturnType, DEM_CODE)Dem_DcmReadDataOfPID21(
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) PID21Value);

/* Dem_DcmReadDataOfPID30 */
extern FUNC(Std_ReturnType, DEM_CODE)Dem_DcmReadDataOfPID30(
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) PID30Value);

/* Dem_DcmReadDataOfPID31 */
extern FUNC(Std_ReturnType, DEM_CODE)Dem_DcmReadDataOfPID31(
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) PID31Value);

/* Dem_DcmReadDataOfPID41 */
extern FUNC(Std_ReturnType, DEM_CODE)Dem_DcmReadDataOfPID41(
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) PID41Value);

/* Dem_DcmReadDataOfPID4D */
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4D(
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4DValue);

/* Dem_DcmReadDataOfPID4E */
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4E(
 P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4EValue);

/* Dem_ReadDataOfOBDFreezeFrame */
extern FUNC(Std_ReturnType, DEM_CODE)Dem_ReadDataOfOBDFreezeFrame(
  uint8 PID, uint8 DataElementIndexOfPID,
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
  P2VAR (uint8, AUTOMATIC, DEM_APPL_DATA) BufSize);

/* Dem_GetDTCOfOBDFreezeFrame */
extern FUNC(Std_ReturnType, DEM_CODE)Dem_GetDTCOfOBDFreezeFrame(
  uint8 FrameNumber, 
  P2VAR (uint32, AUTOMATIC, DEM_APPL_DATA) DTC);

/* Dem_SetPtoStatus */
extern FUNC(Std_ReturnType, DEM_CODE)Dem_SetPtoStatus(
  boolean PtoStatus);
#endif

extern FUNC(Dem_ReturnClearDTCType, DEM_CODE)Dem_ClearDTC(
  uint32 DTC,
  Dem_DTCFormatType DTCFormat, 
  Dem_DTCOriginType DTCOrigin);
  
/* Dem_MainFunction */
extern FUNC(void, DEM_CODE) Dem_MainFunction(void);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_ClearPrestoredFreezeFrame(
  Dem_EventIdType EventId); 

extern FUNC(Std_ReturnType, DEM_CODE) Dem_PrestoreFreezeFrame(
  Dem_EventIdType EventId);


extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetFaultDetectionCounter(
  Dem_EventIdType EventId,
  P2VAR (sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter);

extern FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_CddClearDTC(uint32 DTC,
  Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin);

/* polyspace:end<MISRA-C:16.4:Not a defect:Justify with annotations> Not a defect */


#define DEM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**                  NVRAM Block Id Permanent RAM addresses                     *
*******************************************************************************/
/* 
   polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect
   polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations> Not a defect
   polyspace:end<MISRA-C:8.8:Not a defect:Justify with annotations> Not a defect 
*/

#endif /* DEM_H */


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
