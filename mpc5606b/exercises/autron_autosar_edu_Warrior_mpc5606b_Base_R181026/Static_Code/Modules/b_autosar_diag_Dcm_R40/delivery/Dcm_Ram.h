/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_Ram.h                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_Ram                                          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By                Description                      **
********************************************************************************
** 1.0.6     12-06-2017    Sungeol Baek      #5428                            **
**                                                                            **
** 1.0.5     03-03-2016    Sungeol Baek      #3754, RTRT reflection           **
**                                                                            **
** 1.0.4     18-11-2015    Youngjin Yun      #3400                            **
**                                                                            **
** 1.0.3     10-08-2015    Youngjin Yun      #2977                            **
**                                                                            **
** 1.0.2     26-02-2015    Sungeol Baek      #2163                            **
**                                                                            **
** 1.0.1     26-02-2015    YoungJin Yun      #1044                            **
**                                                                            **
** 1.0.0     09-01-2013    Autron            Initial Version                  **
*******************************************************************************/

#ifndef DCM_RAM_H
#define DCM_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Dcm_PCTypes.h"
#include "Dcm_DslInternal.h"


/* polyspace:begin<MISRA-C:8.12:Not a defect:Justify with annotations> Not Defect  */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
** Constants of unspecified size                                              **
*******************************************************************************/


/*******************************************************************************
** Variables of 8-bit size                                                    **
*******************************************************************************/
#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
extern    VAR(boolean, DCM_VAR) Dcm_TriggerCancelPendingOperation;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
#if(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON)
extern VAR(uint8, DCM_VAR) Dcm_GucPeriodicTransMode;
#endif

#if ((DCM_DSP_DIAG_SESSION_SERVICE == STD_ON) || (DCM_DSP_STOP_DIAG_SESSION_SERVICE== STD_ON))
/* Stores diagnostic session index */
extern VAR(Dcm_DiagSessionStateType, DCM_VAR) Dcm_DiagSessionState;
#endif


#if (DCM_ROUTINECONTROL_SERVICE == STD_ON)
extern VAR(uint8, DCM_VAR) Dcm_GucRoutineSubFunction;
#endif

extern VAR(uint8, DCM_VAR) Dcm_GucPeriodicSID;

#if(DCM_DSP_MAX_DID_SIZE !=DCM_ZERO)
extern VAR(uint8, DCM_VAR) Dcm_GaaDidReadSignalData[];
#endif

extern VAR(uint32, DCM_VAR) Dcm_GulResBufferPosition;

extern VAR(uint8, DCM_VAR) Dcm_GucReadLastDIDCount;

#if(DCM_TRANSFER_DATA_SERVICE == STD_ON)
extern P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Dcm_GpMemoryData;
#endif

extern P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Dcm_GpDIDSignalDataPtr;

#if((DCM_TRANSFER_DATA_SERVICE == STD_ON) || \
  (DCM_REQUEST_UPLOAD_SERVICE == STD_ON) || \
 (DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON))
extern VAR(uint8, DCM_VAR)Dcm_GucBlockSeqCounter;
#endif

#if(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
extern VAR(uint8, DCM_VAR) Dcm_GucEventType;

extern VAR(uint8, DCM_VAR) Dcm_GucEventState;

extern VAR(uint8, DCM_VAR) Dcm_GucActiveWindowTime;
#endif

#if(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
#if(DCM_MAX_NO_OF_PRECONFIGURED_DID != DCM_ZERO)
extern VAR(uint8, DCM_VAR) Dcm_GucPreConfigRoeDidIndex;
#endif
#endif

/* Global Variable to store SubNetValue for service 0x28 */
extern VAR(uint8, DCM_VAR) Dcm_GucTranslationType;

extern VAR(uint8, DCM_VAR) Dcm_GucAvailableDTCStatusMask;

#if(DCM_WRITE_MEMORY_BY_ADDRESS_SERVICE == STD_ON)
extern VAR(uint8, DCM_VAR)Dcm_GucMemAddrSizeBytes;

extern VAR(uint8, DCM_VAR)Dcm_GucMemoryIdentifier;
#endif

extern VAR(uint8, DCM_VAR)Dcm_GucDataForId;

/* Global variable to store protocol status */
extern VAR(uint8, DCM_VAR) Dcm_GucProtocolIndex;

/* Array for WriteMemory Data values */
extern VAR(uint8, DCM_VAR) Dcm_GaaWriteData[DCM_THIRTY_TWO];

/* Global pointer to store pointer to the request or response data */
extern Dcm_MsgType Dcm_GpReqResData;

/* Global pointer to store WriteMemory data */
extern P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Dcm_GpWriteData;

/* Global Variable to store the NRC */
extern VAR(uint8, DCM_VAR) Dcm_GaaResponseBuf[DCM_THREE];

/* To store TID value */
extern VAR(uint8, DCM_VAR) Dcm_GucTIDValue;

/* To store PID Count */
extern VAR(uint8, DCM_VAR) Dcm_GucPIDCount;

/* To indicate ID belongs to Availability list */
extern VAR(uint8, DCM_VAR) Dcm_GucAvlState;

/* Global Variable to store the PositionInDataRecordsizes in DynDID */
extern VAR(uint8, DCM_VAR) Dcm_GucPosInDtaRec;

/* Global Variable to store the Memorysize in DynDID */
extern VAR(uint8, DCM_VAR) Dcm_GucMemorysize;

/* Global Variable to store the TxBuffer Index in DynDID */
extern VAR(uint8, DCM_VAR) Dcm_GucTxBufInd;

extern VAR(uint8, DCM_VAR)Dcm_GucReadGlobal;

/* Global Variable to store the New Session Requested */
extern VAR(uint8, DCM_VAR) Dcm_GucSecurSequChk;

/* Global Variable to store the jump to boot needed for new session requested */
extern VAR(uint8, DCM_VAR) Dcm_GucSessionForBoot;

/* Global Variable to store Subfunction for service 0x10 */
extern VAR(uint8, DCM_VAR) Dcm_GucSubFunValue;

#if(DCM_PAGEDBUFFER_ENABLED == STD_ON)
/* Global Variable to store record number */
extern VAR(uint8, DCM_VAR) Dcm_GucRecordNumber;
#endif

#if(((DCM_READ_MEMORY_BY_ADDRESS_SERVICE == STD_ON)) || \
  (DCM_DYNAMICALLYDEFINE_DATA_IDENTIFIER_SERVICE == STD_ON) || \
  (DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON))
/* Global Variable to store Memory Identifier for 0x23 service */
extern VAR(uint8, DCM_VAR) Dcm_GucRMBAMemoryIdentifier;
#endif

/* Global Variable to store number of Data Ids */
extern VAR(uint8, DCM_VAR) Dcm_GucNumOfDataIds;

/* Global Variable to store current protocol priority */
extern VAR(uint8, DCM_VAR) Dcm_GucPrtclPriority;

#if ((DCM_DSP_DIAG_SESSION_SERVICE == STD_ON) || \
 (DCM_DSP_SECURITY_SERVICE == STD_ON))
/* Stores diagnostic service or security index */
extern VAR(uint8, DCM_VAR) Dcm_GucDspStIndex;
#endif

/* Global Array to store the communication mode */
extern VAR(uint8, DCM_VAR) Dcm_GaaCommMode[];

/* Global variable to store the Subfunction respective to the request*/
extern VAR(uint8, DCM_VAR) Dcm_GucSubFunction;

/* Global variable to store the Periodic RXPDUID */
extern VAR(uint8, DCM_VAR) Dcm_GucPeriodicRxPduId;

/* Global Variable to store session and security access count */
extern VAR(uint8, DCM_VAR) Dcm_GucFailedSecurityAccessCount;

#if((DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON) || \
(DCM_OBD_REQPOWERTRAIN_FREEZEFRAMEDATA_SERVICE == STD_ON))
/* Global Variable to store the RxPduId of Periodic request */
extern VAR(uint8, DCM_VAR) Dcm_GucPIDValue;
#endif

#if(DCM_OBD_REQ_ONBOARD_MONITORRESULT_SERVICE == STD_ON)
/* Global Variable to store the RxPduId of Periodic request */
extern VAR(uint8, DCM_VAR) Dcm_GucOBDMIDValue;
#endif

#if(DCM_OBD_REQ_CTLRL_ONBOADSYSTEM_SERVICE == STD_ON)
/* Global Variable to store the RxPduId of Periodic request */
extern VAR(uint8, DCM_VAR) Dcm_GucTIDDValue;
#endif

#if((DCM_COMMUNICATION_CONTROL_SERVICE == STD_ON) || \
(DCM_ENABLE_NORMAL_MSG_TRANSMISSION_SERVICE == STD_ON))
/* Global Variable to store SubNetValue for service 0x28 */
extern VAR(uint8, DCM_VAR) Dcm_GucSubNetValue;

/* Global Variable to store CommunicationModeType for service 0x28 */
extern VAR(uint8, DCM_VAR) Dcm_GucCommunicationModeType;

/* Global Variable to store CommunicationModeType for service 0x28 */
extern VAR(uint8, DCM_VAR) Dcm_GucComCtrlMode;
#endif

#if(DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON)
extern VAR(uint8, DCM_VAR) Dcm_GucInOutParameter;
#endif

extern VAR(uint8, DCM_VAR) Dcm_GucIDIndex;

#if(DCM_DSP_SECURITY_SERVICE == STD_ON)
extern VAR(uint8, DCM_VAR) Dcm_GaaSeed[];
#endif

extern VAR(uint8, DCM_VAR) Dcm_GaaPidSignalData[DCM_THIRTY_TWO];

#if(DCM_PAGEDBUFFER_ENABLED == STD_ON)
/* Global Variable to store record number */
extern VAR(uint8, DCM_VAR) Dcm_GucNumofDTC;
#endif

#if (DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
/* Global Variable for number of identified events stored */
extern VAR(uint8, DCM_VAR) Dcm_GucRoeSTRTIndex;

/* Global Variable to store the status of the ROE transmission */
extern VAR(uint8, DCM_VAR) Dcm_GucResOnEventStatus;
#endif

/*******************************************************************************
** Variables of 16-bit size                                                   **
*******************************************************************************/
#define DCM_START_SEC_VAR_CLEARED_16
#include "MemMap.h"

/* Global Variable to remember Maximum Number of response Pending */
extern VAR(uint16, DCM_VAR) Dcm_GusMaxNoOfRespPend;

extern VAR(uint16, DCM_VAR) Dcm_GusMaxNoOfForceRespPend;

#if(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON)
extern VAR(uint16, DCM_VAR) Dcm_GaaPeriodicID[][2U];

extern VAR(uint16, DCM_VAR)Dcm_GaaActivePeriodicTimer[DCM_THREE];
#endif

extern VAR(uint16, DCM_VAR) Dcm_IndexOfDslPeriodicData;

#if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || \
  (DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON))

/* Global pointer to store 16 bit Read Data */
extern P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) Dcm_GpUint16Data;
#endif

extern VAR(uint16, DCM_VAR) Dcm_GusDataIdentifier;

#if((DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON) && \
  (DCM_MAX_NO_OF_PRECONFIGURED_DID != DCM_ZERO))
extern VAR(uint16, DCM_VAR) Dcm_GusRoeDidIndex;
#endif

/* Array for current timer values */
extern VAR(uint16, DCM_VAR) Dcm_GaaTimer[DCM_MAX_TIMERS];

extern VAR(uint16, DCM_VAR) Dcm_GusDIDBufIndex;

/* Global Variable to store Timer value */
extern VAR(uint16, DCM_VAR) Dcm_GusTImerValue;

/* Global pointer to store pointer to the Data Id array */
extern P2CONST(uint16, DCM_VAR, DCM_PRIVATE_CONST) Dcm_GpDataId;

#if((DCM_PAGEDBUFFER_ENABLED == STD_ON)||\
(DCM_READ_MEMORY_BY_ADDRESS_SERVICE == STD_ON))
/* Global Variable to store Memory size for 0x23 service */
extern VAR(uint16, DCM_VAR) Dcm_GusRMBAMemorySize;
#endif

#if(DCM_WRITE_MEMORY_BY_ADDRESS_SERVICE == STD_ON)
/* Global Variable to store Memory size for 0x23 service */
extern VAR(uint16, DCM_VAR) Dcm_GusWriteMemorySize;
#endif

extern VAR(uint16, DCM_VAR) Dcm_GusDIDIndexVal;

extern VAR(uint16, DCM_VAR) Dcm_GusDataPosition;

#if(DCM_ROUTINECONTROL_SERVICE == STD_ON)

extern VAR(uint16, DCM_VAR) Dcm_GusRIDIndex;

extern VAR(uint16, DCM_VAR) Dcm_GusRoutineIdentifier;

extern VAR(uint16, DCM_VAR) Dcm_GusLastSignalLength;
#endif

#if(DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON)
extern VAR(uint16, DCM_VAR) Dcm_GusTempDIDsize;
#endif

extern VAR(uint16, DCM_VAR) Dcm_GusDidReadIndex;

extern VAR(uint16, DCM_VAR) Dcm_GusReadDIDCount;

extern VAR(uint16, DCM_VAR) Dcm_GusSignalDataLoc;

#if(DCM_ROUTINECONTROL_SERVICE == STD_ON)
extern VAR(uint16, DCM_VAR) Dcm_GusCurrentDataLength;
#endif

#if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) ||\
  (DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON) || \
    (DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON))
extern VAR(uint16, DCM_VAR) Dcm_GaaReadDid[];
#endif
#define DCM_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"
/*******************************************************************************
** Variables of 32-bit size                                                   **
*******************************************************************************/
#define DCM_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
#if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || \
  (DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON))
/* Global pointer to store 32 bit Read Data */
extern P2VAR(uint32, AUTOMATIC, DCM_APPL_DATA) Dcm_GpUint32Data;
#endif

/* Global Variable to store DTC value for 0x14 service */
extern VAR(uint32, DCM_VAR) Dcm_GulDTCValue;

#if((DCM_PAGEDBUFFER_ENABLED == STD_ON) ||\
(DCM_READ_MEMORY_BY_ADDRESS_SERVICE == STD_ON))
/* Global Variable to store Memory Address for 0x23 service */
extern VAR(uint32, DCM_VAR) Dcm_GulRMBAMemoryAddress;
#endif

#if(DCM_WRITE_MEMORY_BY_ADDRESS_SERVICE == STD_ON)
/* Global Variable to store Memory Address for 0x23 service */
extern VAR(uint32, DCM_VAR) Dcm_GulWriteMemoryAddress;
#endif

#if((DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON) || \
  (DCM_TRANSFER_DATA_SERVICE == STD_ON))
extern VAR(uint32, DCM_VAR)Dcm_GulDLMemAddress;

extern VAR(uint32, DCM_VAR)Dcm_GulDLMemSize;
#endif

#if(DCM_REQUEST_UPLOAD_SERVICE == STD_ON)
extern VAR(uint32, DCM_VAR)Dcm_GulULMemAddress;

extern VAR(uint32, DCM_VAR)Dcm_GulULMemSize;
#endif

extern VAR(uint32, DCM_VAR)Dcm_GulNumOfBytesToBeTransfer;

/* Global Variable to store Memory Address */
extern VAR(uint32, DCM_VAR) Dcm_GulMemoryAddress;

/* Global Variable to store Memory Size */
extern VAR(uint32, DCM_VAR) Dcm_GulMemorySize;

/* Global Variable to store Channel Identifier associated to the received Pdu*/
extern VAR(uint32, DCM_VAR) Dcm_GulChannelIdentifier;

extern VAR(uint32, DCM_VAR) Dcm_GulNumOfBytes;

extern VAR(uint32, DCM_VAR) Dcm_GulBlockLength;

/* To store Max Buffer configured value */
extern VAR(uint32, DCM_VAR) Dcm_GulMaxBufValue;

#if(DCM_TRANSFER_DATA_SERVICE == STD_ON)
extern VAR(uint32, DCM_VAR) Dcm_GulTransferResponseLength;
#endif

extern VAR(uint32, DCM_VAR) Dcm_GulFDCRespSize;

#if(DCM_PAGEDBUFFER_ENABLED == STD_ON)
/* Global Variable to store buffer size in case of paged processing */
extern VAR(uint32, DCM_VAR) Dcm_GulBufferSize;
#endif

/* Global Variable to store DTC */
extern VAR(Tun_DcmDword32, DCM_VAR) Dcm_GunDTC;
#define DCM_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"
/*******************************************************************************
** Variables of boolean                                                   **
*******************************************************************************/
#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
extern VAR(boolean, DCM_VAR)Dcm_GblSendResponse;

extern VAR(boolean, DCM_VAR)Dcm_GblPduRTransmitResponse;

/* sg.baek 022305 - Task #2163 in redmine */

extern VAR(boolean, DCM_VAR)Dcm_GblReceiveRquest;

#if((DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON) && \
         (DCM_MAX_NO_OF_PRECONFIGURED_DID != DCM_ZERO))
extern VAR(boolean, DCM_VAR)Dcm_GblNvmReadFlag;
#endif

extern VAR(boolean, DCM_VAR)Dcm_GblReset;

#if(DCM_RESPONSEON_SECOND_DECLINE_REQUEST == STD_ON)
/* Global Variable to store the status of the second request*/
extern VAR(boolean, DCM_VAR) Dcm_GblSecDeclRequest;
#endif

extern VAR(boolean, DCM_VAR)Dcm_GblDTCFDCPending;

extern VAR(boolean, DCM_VAR)Dcm_GblJumpToBootloader;

#if(DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON)
/* Global variable to store Read Data for Boolean */
extern P2VAR(boolean, AUTOMATIC, DCM_APPL_DATA) Dcm_GpDcmReadData;
#endif

/* Global variable to store Initialization status of DCM */
extern VAR(boolean, DCM_VAR_POWER_ON_INIT) Dcm_GblInitStatus;

/* Global variable to store Initialization status of DCM */
extern VAR(boolean, DCM_VAR) Dcm_GblDIDRangePresent;

extern VAR(boolean, DCM_VAR) DCM_GblIsDIDInResp;

extern VAR(boolean, DCM_VAR) Dcm_GblDIDNotSupportedSession;

#if((DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON) || \
  (DCM_TRANSFER_DATA_SERVICE == STD_ON) || \
  (DCM_REQUEST_UPLOAD_SERVICE == STD_ON))
extern VAR(boolean, DCM_VAR)Dcm_GblDownLoadActive;
#endif

extern VAR(boolean, DCM_VAR) Dcm_GblFaultDetcetionCounter;

extern VAR(boolean, DCM_VAR)Dcm_GblDownLoadPendingStatus;

extern VAR(boolean, DCM_VAR)Dcm_GblProtocolEndianess;

extern VAR(boolean, DCM_VAR)Dcm_GblDownLoadForceStatus;

#if((DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON) || \
  (DCM_TRANSFER_DATA_SERVICE == STD_ON) || \
  (DCM_REQUEST_UPLOAD_SERVICE == STD_ON))
extern VAR(boolean, DCM_VAR)Dcm_GblUpLoadActive;
#endif

/* Global Variable to Store DID Reference Status */
extern VAR(boolean, DCM_VAR)Dcm_GblDIDReferrenceStatus;

#if ((DCM_DSP_DIAG_SESSION_SERVICE == STD_ON) || \
(DCM_ECURESET_SERVICE == STD_ON) || \
(DCM_LINK_CONTROL_SERVICE == STD_ON))
extern VAR(boolean, DCM_VAR) Dcm_GblExecuteECUReset;
#endif

/* Global variable to store the communication mode */
extern VAR(boolean, DCM_VAR) Dcm_GblFirstCallToMain;

/* To indicate multiple record */
extern VAR(boolean, DCM_VAR) Dcm_GblMultipleRecord;

extern VAR(boolean, DCM_VAR) Dcm_GblTimerExpired;

/* Global Variable to store the status of the periodic transmission */
extern VAR(boolean, DCM_VAR) Dcm_GblResOnPeriodicIdStatus;

/* Global Variable to store the status of the normal transmission */
extern VAR(boolean, DCM_VAR) Dcm_GblNormalReq;

/*  Global variable to Store the number of Filter Dtc By Severity mask */
extern VAR(boolean, DCM_VAR) Dcm_GblNumFilterDTCStatusBySevirtMask;

/* Global variable to store Initialization status of DCM */
extern VAR(boolean, DCM_VAR) Dcm_GblStart;

extern VAR(boolean, DCM_VAR) Dcm_GblRespPendConfirmation;

/* Global variable to store Initialization status of DCM */
extern VAR(boolean, DCM_VAR) Dcm_GblStop;

#if(DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON)
extern VAR(boolean, DCM_VAR) Dcm_GblDIDReferred;

extern VAR(boolean, DCM_VAR) Dcm_GblDIDReferredIo;

extern VAR(boolean, DCM_VAR) Dcm_GblDIDReferredCon;
#endif

#if(DCM_TRANSFER_DATA_SERVICE == STD_ON)
extern VAR(boolean, DCM_VAR)Dcm_GblBlockSeqCounterRepeated;
#endif

#if(DCM_DSP_CONTROL_DTC_SERVICE == STD_ON)
extern  VAR(boolean, DCM_VAR)Dcm_GblDTCSettingDisabled;
#endif

extern VAR(boolean, DCM_VAR)Dcm_GblRspPenOnBtlTrans;

extern VAR(boolean, DCM_VAR)Dcm_GblPosRspTransOnReset;

#if((DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON) || \
(DCM_OBD_REQ_ONBOARD_MONITORRESULT_SERVICE == STD_ON) || \
(DCM_OBD_REQ_CTLRL_ONBOADSYSTEM_SERVICE == STD_ON) || \
(DCM_OBD_REQVEHICLE_INFO_SERVICE == STD_ON))
extern VAR(boolean, DCM_VAR)Dcm_GblAvailabilityPIDFlag;

#endif
#if (DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
/* Gobal Variable to store the requested serviceToRespondTo */
extern VAR(boolean, DCM_VAR) Dcm_GblRoeClearAll;

#if(DCM_ROE_QUEUE_ENABLED == STD_ON)
/* Gobal Variable to store the requested serviceToRespondTo */
extern VAR(boolean, DCM_VAR) Dcm_GblRoeQueueOngoing;
#endif
#endif

#if ((DCM_READ_ITC_SERVICE_SUPPRT == STD_ON) ||\
     (DCM_CLEAR_ITC_SERVICE_SUPPRT == STD_ON))

  extern VAR(boolean, DCM_VAR)Dcm_InternalTroubleCodeService;
#endif
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
/*******************************************************************************
** Variables of unspecified size that are Initialized in Dcm                  **
*******************************************************************************/
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Added by AUTRON */
#if(DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON)
extern VAR(Dcm_DidProcStateType, DCM_VAR) Dcm_DidProcState[1];
#endif

#if(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON)
/* Added by AUTRON */
extern VAR(Dcm_PeriodicDidProcStateType, DCM_VAR) Dcm_PeriodicDidProcState[1];
#endif

#if(DCM_DSP_SECURITY_SERVICE == STD_ON)
/* Added by AUTRON */
extern  VAR(Dcm_SecurityAccessStateType, DCM_VAR) Dcm_SecurityAccessState[1];
#endif

/* Global Variable to store the value of Tx length and Rx data buffer  */
extern VAR(PduInfoType, DCM_VAR) Dcm_GddTxMessageType;

/* Global Variable to store the value of Rx length and Rx data buffer  */
extern VAR(PduInfoType, DCM_VAR) Dcm_GddRxMessageType;

extern P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA)
  Dcm_GpPerMsgContext;

extern VAR(Dcm_ServiceForcePendingStatusType, DCM_VAR)
  Dcm_ServiceForcePendingStatus;

extern VAR(Dcm_ServicePendingStatusType, DCM_VAR)
  Dcm_ServicePendingStatus;

extern VAR(Dcm_MemServicePendingStatusType, DCM_VAR)
  Dcm_MemServicePendingStatus;

/* Global Variable to store the pointer to the current timing values */
extern VAR(Dcm_TimerServerType, DCM_VAR) Dcm_GstCurrentTimingValue;

/* Global Variable to store the current security level */
extern VAR(Dcm_SecLevelType, DCM_VAR) Dcm_GddSecurityLevel;

/* Global Variable of MsgContext Type */
extern VAR(Dcm_MsgContextType, DCM_VAR) Dcm_GstMsgContext;

extern VAR(Dcm_MsgContextType, DCM_VAR) Dcm_GstPerMsgContext;

/* Global Variable to store length of the request which is in progress */
extern VAR(Dcm_MsgLenType, DCM_VAR) Dcm_GaaReqLength[];

/* Global Variable to store tester present request data */
extern VAR(uint8, DCM_VAR) Dcm_GaaTesterPresentReqBuff[DCM_BUFSZ_TESTERPRESENT];

/* Global Variable to store Protocol Id */
extern VAR(Dcm_ProtocolType, DCM_VAR) Dcm_GddProtocolId;

/* Global Variable to store page buffer status */
extern VAR(Dcm_DspSerPgStatusType, DCM_VAR) Dcm_DspSerPgStatus;

/* Global Variable to store the status of the timer */
extern VAR(Dcm_ReqTimerFlagStatusType, DCM_VAR)
  Dcm_TimerReqFlagStatus;

/* Global Variable to store the status of the transmission */
extern VAR(Dcm_TxRespStatusType, DCM_VAR) Dcm_TxRespStatus;

/* Global Variable to store the status of the protocol
and provide buffer for transmission */
extern VAR(Dcm_PrtclTxBufStatusType, DCM_VAR) Dcm_PrtclTxBufStatus;

/* Global Variable to store the current session level */
extern VAR(Dcm_SesCtrlType, DCM_VAR) Dcm_GddCurrentSession;

/* Global Variable to store the previous session */
extern VAR(Dcm_SesCtrlType, DCM_VAR) Dcm_GddOldSession;

/* Global Variable to store negative response code */
extern VAR(Dcm_NegativeResponseCodeType, DCM_VAR) Dcm_GddNegRespError;

/* Global Variable to store OpStatus */
extern VAR(Dcm_OpStatusType, DCM_VAR) Dcm_GddGeneralOpStatus;

/* Global Variable to store DcmTxPduId */
extern VAR(PduIdType, DCM_VAR) Dcm_GddDcmTxPduId;

#if(DCM_RESPONSEON_SECOND_DECLINE_REQUEST == STD_ON)
/* Global Variable to store DcmTxPduId of the second request*/
extern VAR(PduIdType, DCM_VAR) Dcm_GddSecDeclTxPduId;
#endif

#if(DCM_RESPONSEON_SECOND_DECLINE_REQUEST == STD_ON)
/* Global Variable to store DcmTxPduId of the second request*/
extern VAR(PduIdType, DCM_VAR) Dcm_GddSecDeclConfTxPduId;
#endif

/* Global Variable to store DcmDslTxConfirmationPduId */
extern VAR(PduIdType, DCM_VAR) Dcm_GddDcmTxConfPduId;

#if((DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON) && \
     (DCM_PROTOCOL_TRANSTYPE2 == STD_ON))
extern VAR(PduIdType, DCM_VAR) Dcm_GddDcmPeriodicTxConfPduId;
#endif

#if(DCM_PAGEDBUFFER_ENABLED == STD_ON)
/* Global Variable to store the response length pending in paged transmission*/
extern VAR(Dcm_MsgLenType, DCM_VAR) Dcm_GddCurrentLength;
#endif

/* Global Variable to store the RxPduId */
extern VAR(PduIdType, DCM_VAR) Dcm_GddRxPduId;

/* Global Variable to store the response length for the first page */
extern VAR(Dcm_MsgLenType, DCM_VAR) Dcm_GddTxResponseLen;

/* Global Variable to store the request length from the request */
extern VAR(PduLengthType, DCM_VAR) Dcm_GddTpSduLength;

#if(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON)
/* Global Variable to store the RxPduId of Periodic request */
extern VAR(PduIdType, DCM_VAR) Dcm_GddPIdRxPduId;
#endif

extern VAR(Dcm_OpStatusType, DCM_VAR) Dcm_GddOpStatus;

#if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || \
(DCM_DYNAMICALLYDEFINE_DATA_IDENTIFIER_SERVICE == STD_ON))
extern VAR(Dcm_OpStatusType, DCM_VAR) Dcm_GddCheckReadOpStatus;
#endif

#if(DCM_COMMUNICATION_CONTROL_SERVICE == STD_ON)
extern VAR(Dcm_CommunicationModeType, DCM_VAR)Dcm_GddCommunicationType;
#endif

#if((DCM_DSP_SECURITY_SERVICE == STD_ON) || \
(DCM_READ_SCALINGDATA_BYIDENTIFIER_SERVICE == STD_ON) || \
(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON) || \
(DCM_ROUTINECONTROL_SERVICE == STD_ON))
extern VAR(Dcm_DspServiceProcessingStsType, DCM_VAR)
Dcm_DspServiceProcessingSts;
#endif

#if(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
/* Global Variable to store the pointer to the MsgContext */
extern P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA)
  Dcm_GpRoeMsgContext;

/* Global Variable to store the response length pending in paged transmission*/
extern VAR(Dcm_MsgLenType, DCM_VAR) Dcm_GddRoeReqLength;
#endif

#if(DCM_ROUTINECONTROL_SERVICE == STD_ON)
extern P2VAR(void, AUTOMATIC, DCM_APPL_DATA) Dcm_GpRoutineSignalInDataPtr;

extern P2VAR(void, AUTOMATIC, DCM_APPL_DATA) Dcm_GpRoutineSignalOutDataPtr;
#endif

extern VAR(Dcm_ProgConditionsType, DCM_VAR) Dcm_GddProgConditions;

#if(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
extern VAR(Dcm_MsgContextType, DCM_VAR) Dcm_GstRoeMsgContext;

extern VAR(Dcm_RoeRequestInfo, DCM_VAR)
  Dcm_GddRoeRequestInfo[];

#if(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
#if(DCM_MAX_NO_OF_PRECONFIGURED_DID != DCM_ZERO)
extern VAR(Dcm_PreConfiguredRoe, DCM_VAR)
  Dcm_GddPreConfiguredDID[];
#endif
#endif

#if(DCM_ROE_QUEUE_ENABLED == STD_ON)
extern VAR(Dcm_RoeQueueProcessInfo, DCM_VAR) Dcm_GddRoeQueueProcessInfo;

extern VAR(Dcm_DslRoeQueueInfo, DCM_VAR)
  Dcm_GaaRoeQueueInfo[];
#endif

extern VAR(PduIdType, DCM_VAR) Dcm_GddRoeRxPduId;

extern VAR(PduIdType, DCM_VAR) Dcm_GddStartRoeRxPduId;

/* Gobal Variable to store the requested serviceToRespondTo */
extern VAR(Dcm_RoeRetryProcessInfo, DCM_VAR) Dcm_GddRoeRetryProcessInfo;
#endif

extern VAR(Dcm_RequestContextType, DCM_VAR)  Dcm_RequestContext[];
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/* Added by youngjin.yun, 2015-01-02 */
#define DCM_START_SEC_CONST_8
#include "MemMap.h"
extern CONST(uint8, DCM_CONST) 
  Dcm_SizeOfDataType[7];
#define DCM_STOP_SEC_CONST_8
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/* polyspace:end<MISRA-C:8.12:Not a defect:Justify with annotations> Not Defect  */

#endif /* DCM_RAM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
