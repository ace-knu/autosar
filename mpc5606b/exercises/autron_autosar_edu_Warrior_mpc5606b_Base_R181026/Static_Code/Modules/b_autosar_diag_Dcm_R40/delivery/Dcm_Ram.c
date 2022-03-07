/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_Ram.c                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : Global variable definitions                                   **
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
** 1.0.7     12-06-2017    Jin     Jung      #5428                            **
**                                                                            **
** 1.0.6     15-02-2017    Jin     Jung      #5460                            **
**                                                                            **
** 1.0.5     14-10-2016    Jin     Jung      #2467                            **
**                                                                            **
** 1.0.4     03-03-2016    Sungeol Baek      #3754, RTRT reflection           **
**                                                                            **
** 1.0.3     10-08-2015    Youngjin Yun      #2977                            **
**                                                                            **
** 1.0.2     26-02-2015    Sungeol Baek      #2163                            **
**                                                                            **
** 1.0.1     26-02-2015    YoungJin Yun      #1044                            **
**                                                                            **
** 1.0.0     09-01-2013    Autron            Initial Version                  **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Dcm.h"
#include "Dcm_Ram.h"
#include "Rte_Dcm.h"
#include "Dcm_DspMain.h"
#include "Dem.h"


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
** Variables of 8-bit size                                                    **
*******************************************************************************/

#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
  VAR(boolean, DCM_VAR) Dcm_TriggerCancelPendingOperation;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
#if ((DCM_DSP_DIAG_SESSION_SERVICE == STD_ON) || (DCM_DSP_STOP_DIAG_SESSION_SERVICE== STD_ON))
/* Stores diagnostic session index */
  VAR(Dcm_DiagSessionStateType, DCM_VAR) Dcm_DiagSessionState;
#endif


  VAR(uint8, DCM_VAR) Dcm_GucReadLastDIDCount;


#if (DCM_ROUTINECONTROL_SERVICE == STD_ON)
  VAR(uint8, DCM_VAR) Dcm_GucRoutineSubFunction;
#endif

  VAR(uint8, DCM_VAR) Dcm_GucPeriodicSID;

  VAR(uint32, DCM_VAR) Dcm_GulResBufferPosition;

#if(DCM_DSP_MAX_DID_SIZE != DCM_ZERO)
  VAR(uint8, DCM_VAR) Dcm_GaaDidReadSignalData[DCM_DSP_MAX_DID_SIZE];
#endif

  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Dcm_GpDIDSignalDataPtr;

#if((DCM_TRANSFER_DATA_SERVICE == STD_ON) || \
  (DCM_REQUEST_UPLOAD_SERVICE == STD_ON) || \
 (DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON))
  VAR(uint8, DCM_VAR)Dcm_GucBlockSeqCounter;
#endif

#if(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
  VAR(uint8, DCM_VAR) Dcm_GucEventType;

  VAR(uint8, DCM_VAR) Dcm_GucEventState;

  VAR(uint8, DCM_VAR) Dcm_GucActiveWindowTime;
#endif

/* Global Variable to store SubNetValue for service 0x28 */
  VAR(uint8, DCM_VAR) Dcm_GucTranslationType;

  VAR(uint8, DCM_VAR) Dcm_GucAvailableDTCStatusMask;

#if(DCM_WRITE_MEMORY_BY_ADDRESS_SERVICE == STD_ON)
  VAR(uint8, DCM_VAR)Dcm_GucMemAddrSizeBytes;

  VAR(uint8, DCM_VAR)Dcm_GucMemoryIdentifier;
#endif

  VAR(uint8, DCM_VAR)Dcm_GucDataForId;

/* Global variable to store protocol status */
  VAR(uint8, DCM_VAR) Dcm_GucProtocolIndex;

/* Array for WriteMemory Data values */
  VAR(uint8, DCM_VAR) Dcm_GaaWriteData[DCM_THIRTY_TWO];

/* Global pointer to store pointer to the request or response data */
  Dcm_MsgType Dcm_GpReqResData;

/* Global pointer to store WriteMemory data */
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Dcm_GpWriteData;

/* Global Variable to store the NRC */
  VAR(uint8, DCM_VAR) Dcm_GaaResponseBuf[DCM_THREE];

/* To store TID value */
  VAR(uint8, DCM_VAR) Dcm_GucTIDValue;

/* To store PID Count */
  VAR(uint8, DCM_VAR) Dcm_GucPIDCount;

/* To indicate ID belongs to Availability list */
  VAR(uint8, DCM_VAR) Dcm_GucAvlState;

/* Global Variable to store the PositionInDataRecordsizes in DynDID */
  VAR(uint8, DCM_VAR) Dcm_GucPosInDtaRec;

/* Global Variable to store the Memorysize in DynDID */
  VAR(uint8, DCM_VAR) Dcm_GucMemorysize;

/* Global Variable to store the TxBuffer Index in DynDID */
  VAR(uint8, DCM_VAR) Dcm_GucTxBufInd;

  VAR(uint8, DCM_VAR)Dcm_GucReadGlobal;

/* Global Variable to store the New Session Requested */
  VAR(uint8, DCM_VAR) Dcm_GucSecurSequChk;

/* Global Variable to store the jump to boot needed for new session requested */
  VAR(uint8, DCM_VAR) Dcm_GucSessionForBoot;

/* Global Variable to store Subfunction for service 0x10 */
  VAR(uint8, DCM_VAR) Dcm_GucSubFunValue;

#if(DCM_PAGEDBUFFER_ENABLED == STD_ON)
/* Global Variable to store record number */
  VAR(uint8, DCM_VAR) Dcm_GucRecordNumber;
#endif

#if(((DCM_READ_MEMORY_BY_ADDRESS_SERVICE == STD_ON)) || \
  (DCM_DYNAMICALLYDEFINE_DATA_IDENTIFIER_SERVICE == STD_ON) || \
  (DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON))
/* Global Variable to store Memory Identifier for 0x23 service */
  VAR(uint8, DCM_VAR) Dcm_GucRMBAMemoryIdentifier;
#endif

/* Global Variable to store number of Data Ids */
  VAR(uint8, DCM_VAR) Dcm_GucNumOfDataIds;

/* Global Variable to store current protocol priority */
  VAR(uint8, DCM_VAR) Dcm_GucPrtclPriority;

#if ((DCM_DSP_DIAG_SESSION_SERVICE == STD_ON) || \
 (DCM_DSP_SECURITY_SERVICE == STD_ON))
/* Stores diagnostic service or security index */
  VAR(uint8, DCM_VAR) Dcm_GucDspStIndex;
#endif

/* Global variable to store the communication mode */
  VAR(uint8, DCM_VAR) Dcm_GaaCommMode[DCM_NO_OF_COMM_CHANNELS];

/* Global variable to store the Subfunction respective to the request*/
  VAR(uint8, DCM_VAR) Dcm_GucSubFunction;

/* Global variable to store the Periodic RXPDUID */
  VAR(uint8, DCM_VAR) Dcm_GucPeriodicRxPduId;

/* Global Variable to store session and security access count */
  VAR(uint8, DCM_VAR) Dcm_GucFailedSecurityAccessCount;

#if((DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON) || \
(DCM_OBD_REQPOWERTRAIN_FREEZEFRAMEDATA_SERVICE == STD_ON))
/* Global Variable to store the RxPduId of Periodic request */
  VAR(uint8, DCM_VAR) Dcm_GucPIDValue;
#endif

#if(DCM_OBD_REQ_ONBOARD_MONITORRESULT_SERVICE == STD_ON)
/* Global Variable to store the RxPduId of Periodic request */
  VAR(uint8, DCM_VAR) Dcm_GucOBDMIDValue;
#endif

#if(DCM_OBD_REQ_CTLRL_ONBOADSYSTEM_SERVICE == STD_ON)
/* Global Variable to store the RxPduId of Periodic request */
  VAR(uint8, DCM_VAR) Dcm_GucTIDDValue;
#endif

#if((DCM_COMMUNICATION_CONTROL_SERVICE == STD_ON) || \
(DCM_ENABLE_NORMAL_MSG_TRANSMISSION_SERVICE == STD_ON))
/* Global Variable to store SubNetValue for service 0x28 */
  VAR(uint8, DCM_VAR) Dcm_GucSubNetValue;

/* Global Variable to store CommunicationModeType for service 0x28 */
  VAR(uint8, DCM_VAR) Dcm_GucCommunicationModeType;

/* Global Variable to store CommunicationModeType for service 0x28 */
  VAR(Dcm_CommunicationModeType, DCM_VAR) Dcm_GucComCtrlMode;
#endif

#if(DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON)
  VAR(uint8, DCM_VAR) Dcm_GucInOutParameter;
#endif
  VAR(uint8, DCM_VAR) Dcm_GucIDIndex;

#if(DCM_DSP_SECURITY_SERVICE == STD_ON)
 VAR(uint8, DCM_VAR) Dcm_GaaSeed[DCM_MAX_SECURITY_SEED_SIZE];
#endif

 VAR(uint8, DCM_VAR) Dcm_GaaPidSignalData[DCM_THIRTY_TWO];

#if(DCM_PAGEDBUFFER_ENABLED == STD_ON)
/* Global Variable to store record number */
  VAR(uint8, DCM_VAR) Dcm_GucNumofDTC;
#endif

#if (DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
/* Global Variable for number of identified events stored */
  VAR(uint8, DCM_VAR) Dcm_GucRoeSTRTIndex;

/* Global Variable to store the status of the ROE transmission */
  VAR(uint8, DCM_VAR) Dcm_GucResOnEventStatus;
#endif

#if(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
#if(DCM_MAX_NO_OF_PRECONFIGURED_DID != DCM_ZERO)
  VAR(uint8, DCM_VAR) Dcm_GucPreConfigRoeDidIndex;
#endif
#endif

#define DCM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"
/*******************************************************************************
** Variables of 16-bit size                                                   **
*******************************************************************************/
#define DCM_START_SEC_VAR_CLEARED_16
#include "MemMap.h"

/* Global Variable to remember Maximum Number of response Pending */
  VAR(uint16, DCM_VAR) Dcm_GusMaxNoOfRespPend;

  VAR(uint16, DCM_VAR) Dcm_GusMaxNoOfForceRespPend;

#if(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON)
  VAR(uint16, DCM_VAR) Dcm_GaaPeriodicID[DCM_DSP_MAX_PERIODIC_DID_SCHEDULED][DCM_TWO];

  VAR(uint16, DCM_VAR)Dcm_GaaActivePeriodicTimer[DCM_THREE];
#endif

#if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || \
    (DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON))
/* Global pointer to store 16 bit Read Data */
  P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) Dcm_GpUint16Data;
#endif

  VAR(uint16, DCM_VAR) Dcm_GusDataIdentifier;
#if((DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON) && \
    (DCM_MAX_NO_OF_PRECONFIGURED_DID != DCM_ZERO))
 VAR(uint16, DCM_VAR) Dcm_GusRoeDidIndex;
#endif

/* Array for current timer values */
  VAR(uint16, DCM_VAR) Dcm_GaaTimer[DCM_MAX_TIMERS];

  VAR(uint16, DCM_VAR) Dcm_GusDIDBufIndex;

/* Global Variable to store Timer value */
  VAR(uint16, DCM_VAR) Dcm_GusTImerValue;

/* Global pointer to store pointer to the Data Id array */
  P2CONST(uint16, DCM_VAR, DCM_PRIVATE_CONST) Dcm_GpDataId;

#if((DCM_PAGEDBUFFER_ENABLED == STD_ON)||\
    (DCM_READ_MEMORY_BY_ADDRESS_SERVICE == STD_ON))
/* Global Variable to store Memory size for 0x23 service */
  VAR(uint16, DCM_VAR) Dcm_GusRMBAMemorySize;
#endif

#if(DCM_WRITE_MEMORY_BY_ADDRESS_SERVICE == STD_ON)
/* Global Variable to store Memory size for 0x23 service */
  VAR(uint16, DCM_VAR) Dcm_GusWriteMemorySize;
#endif

  VAR(uint16, DCM_VAR) Dcm_GusDIDIndexVal;

#if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) ||\
    (DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON) || \
    (DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON))
/* Bug #2467 */
VAR(uint16, DCM_VAR) Dcm_GaaReadDid[DCM_ONE];
#endif

  VAR(uint16, DCM_VAR) Dcm_GusDataPosition;

#if(DCM_ROUTINECONTROL_SERVICE == STD_ON)
  VAR(uint16, DCM_VAR) Dcm_GusRIDIndex;

  VAR(uint16, DCM_VAR) Dcm_GusRoutineIdentifier;

  VAR(uint16, DCM_VAR) Dcm_GusLastSignalLength;
#endif

#if(DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON)
  VAR(uint16, DCM_VAR) Dcm_GusTempDIDsize;
#endif

  VAR(uint16, DCM_VAR) Dcm_GusDidReadIndex;

  VAR(uint16, DCM_VAR) Dcm_GusReadDIDCount;

  VAR(uint16, DCM_VAR) Dcm_GusSignalDataLoc;

  VAR(uint16, DCM_VAR) Dcm_IndexOfDslPeriodicData;

#if(DCM_ROUTINECONTROL_SERVICE == STD_ON)
  VAR(uint16, DCM_VAR) Dcm_GusCurrentDataLength;
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
  P2VAR(uint32, AUTOMATIC, DCM_APPL_DATA) Dcm_GpUint32Data;
#endif

/* Global Variable to store DTC value for 0x14 service */
  VAR(uint32, DCM_VAR) Dcm_GulDTCValue;

#if((DCM_PAGEDBUFFER_ENABLED == STD_ON) ||\
(DCM_READ_MEMORY_BY_ADDRESS_SERVICE == STD_ON))
/* Global Variable to store Memory Address for 0x23 service */
  VAR(uint32, DCM_VAR) Dcm_GulRMBAMemoryAddress;
#endif

#if(DCM_WRITE_MEMORY_BY_ADDRESS_SERVICE == STD_ON)
/* Global Variable to store Memory Address for 0x23 service */
  VAR(uint32, DCM_VAR) Dcm_GulWriteMemoryAddress;
#endif

#if((DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON) || \
  (DCM_TRANSFER_DATA_SERVICE == STD_ON))
  VAR(uint32, DCM_VAR)Dcm_GulDLMemAddress;

  VAR(uint32, DCM_VAR)Dcm_GulDLMemSize;
#endif

#if(DCM_REQUEST_UPLOAD_SERVICE == STD_ON)
  VAR(uint32, DCM_VAR)Dcm_GulULMemAddress;

  VAR(uint32, DCM_VAR)Dcm_GulULMemSize;
#endif

/* Global Variable to store Memory Address */
  VAR(uint32, DCM_VAR) Dcm_GulMemoryAddress;

/* Global Variable to store Memory Size */
  VAR(uint32, DCM_VAR) Dcm_GulMemorySize;

/* Global Variable to store Channel Identifier associated to the received Pdu*/
  VAR(uint32, DCM_VAR) Dcm_GulChannelIdentifier;

  VAR(uint32, DCM_VAR) Dcm_GulNumOfBytesToBeTransfer;

  VAR(uint32, DCM_VAR) Dcm_GulNumOfBytes;

  VAR(uint32, DCM_VAR) Dcm_GulBlockLength;

/* To store Max Buffer configured value */
  VAR(uint32, DCM_VAR) Dcm_GulMaxBufValue;

#if(DCM_TRANSFER_DATA_SERVICE == STD_ON)
  VAR(uint32, DCM_VAR) Dcm_GulTransferResponseLength;
#endif

  VAR(uint32, DCM_VAR) Dcm_GulFDCRespSize;

#if(DCM_PAGEDBUFFER_ENABLED == STD_ON)
/* Global Variable to store buffer size in case of paged processing */
  VAR(uint32, DCM_VAR) Dcm_GulBufferSize;
#endif

/* Global Variable to store DTC */
  VAR(Tun_DcmDword32, DCM_VAR) Dcm_GunDTC;
  
#define DCM_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"
/*******************************************************************************
** Variables of boolean                                                       **
*******************************************************************************/
#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
  VAR(boolean, DCM_VAR)Dcm_GblSendResponse;

  VAR(boolean, DCM_VAR)Dcm_GblPduRTransmitResponse;

/* sg.baek 022305 - Task #2163 in redmine */
  VAR(boolean, DCM_VAR)Dcm_GblReceiveRquest;

#if(DCM_RESPONSEON_SECOND_DECLINE_REQUEST == STD_ON)
/* Global Variable to store the status of the second request*/
  VAR(boolean, DCM_VAR) Dcm_GblSecDeclRequest;
#endif

#if((DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON) && \
         (DCM_MAX_NO_OF_PRECONFIGURED_DID != DCM_ZERO))

  VAR(boolean, DCM_VAR)Dcm_GblNvmReadFlag;
#endif

  VAR(boolean, DCM_VAR)Dcm_GblDTCFDCPending;

  VAR(boolean, DCM_VAR)Dcm_GblJumpToBootloader;

  VAR(boolean, DCM_VAR)Dcm_GblReset;

#if(DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON)
  P2VAR(boolean, AUTOMATIC, DCM_APPL_DATA) Dcm_GpDcmReadData;
#endif

/* Global variable to store Initialization status of DCM */
  VAR(boolean, DCM_VAR_POWER_ON_INIT) Dcm_GblInitStatus;

/* Global variable to store Initialization status of DCM */
  VAR(boolean, DCM_VAR) Dcm_GblDIDRangePresent;

  VAR(boolean, DCM_VAR) DCM_GblIsDIDInResp;

  VAR(boolean, DCM_VAR) Dcm_GblDIDNotSupportedSession;

#if((DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON) || \
  (DCM_TRANSFER_DATA_SERVICE == STD_ON) || \
  (DCM_REQUEST_UPLOAD_SERVICE == STD_ON))
  VAR(boolean, DCM_VAR)Dcm_GblDownLoadActive;
#endif

  VAR(boolean, DCM_VAR) Dcm_GblFaultDetcetionCounter;

  VAR(boolean, DCM_VAR)Dcm_GblDownLoadPendingStatus;

  VAR(boolean, DCM_VAR)Dcm_GblProtocolEndianess;

  VAR(boolean, DCM_VAR)Dcm_GblDownLoadForceStatus;

#if((DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON) || \
  (DCM_TRANSFER_DATA_SERVICE == STD_ON) || \
  (DCM_REQUEST_UPLOAD_SERVICE == STD_ON))
  VAR(boolean, DCM_VAR)Dcm_GblUpLoadActive;
#endif

/* Global Variable to Store DID Reference Status */
  VAR(boolean, DCM_VAR)Dcm_GblDIDReferrenceStatus;

#if ((DCM_DSP_DIAG_SESSION_SERVICE == STD_ON) || \
(DCM_ECURESET_SERVICE == STD_ON) ||\
(DCM_LINK_CONTROL_SERVICE == STD_ON))
  VAR(boolean, DCM_VAR) Dcm_GblExecuteECUReset;
#endif

/* Global variable to store the communication mode */
  VAR(boolean, DCM_VAR) Dcm_GblFirstCallToMain;

/* To indicate multiple record */
  VAR(boolean, DCM_VAR) Dcm_GblMultipleRecord;

  VAR(boolean, DCM_VAR) Dcm_GblTimerExpired;

/* Global Variable to store the status of the periodic transmission */
  VAR(boolean, DCM_VAR) Dcm_GblResOnPeriodicIdStatus;

/* Global Variable to store the status of the normal transmission */
  VAR(boolean, DCM_VAR) Dcm_GblNormalReq;

/*  Global variable to Store the number of Filter Dtc By Severity mask */
  VAR(boolean, DCM_VAR) Dcm_GblNumFilterDTCStatusBySevirtMask;

/* Global variable to store Initialization status of DCM */
  VAR(boolean, DCM_VAR) Dcm_GblStart;

  VAR(boolean, DCM_VAR) Dcm_GblRespPendConfirmation;

/* Global variable to store Initialization status of DCM */
  VAR(boolean, DCM_VAR) Dcm_GblStop;

#if(DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON)
  VAR(boolean, DCM_VAR) Dcm_GblDIDReferred;

  VAR(boolean, DCM_VAR) Dcm_GblDIDReferredIo;

  VAR(boolean, DCM_VAR) Dcm_GblDIDReferredCon;
#endif

#if(DCM_TRANSFER_DATA_SERVICE == STD_ON)
  VAR(boolean, DCM_VAR)Dcm_GblBlockSeqCounterRepeated;
#endif

#if(DCM_DSP_CONTROL_DTC_SERVICE == STD_ON)
  VAR(boolean, DCM_VAR)Dcm_GblDTCSettingDisabled;
#endif

/*
 * Response pending on bootloader transition
 */
  VAR(boolean, DCM_VAR)Dcm_GblRspPenOnBtlTrans;

  VAR(boolean, DCM_VAR)Dcm_GblPosRspTransOnReset;

#if((DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON) || \
(DCM_OBD_REQ_ONBOARD_MONITORRESULT_SERVICE == STD_ON) || \
(DCM_OBD_REQ_CTLRL_ONBOADSYSTEM_SERVICE == STD_ON) || \
(DCM_OBD_REQVEHICLE_INFO_SERVICE == STD_ON))
  VAR(boolean, DCM_VAR)Dcm_GblAvailabilityPIDFlag;
#endif

#if (DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
/* Gobal Variable to store the requested serviceToRespondTo */
VAR(boolean, DCM_VAR) Dcm_GblRoeClearAll;

#if(DCM_ROE_QUEUE_ENABLED == STD_ON)
/* Gobal Variable to store the requested serviceToRespondTo */
VAR(boolean, DCM_VAR) Dcm_GblRoeQueueOngoing;
#endif
#endif

#if ((DCM_READ_ITC_SERVICE_SUPPRT == STD_ON) ||\
     (DCM_CLEAR_ITC_SERVICE_SUPPRT == STD_ON))
  VAR(boolean, DCM_VAR)Dcm_InternalTroubleCodeService;
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
  VAR(Dcm_DidProcStateType, DCM_VAR) Dcm_DidProcState[1];
#endif

#if(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON)
/* Added by AUTRON */
  VAR(Dcm_PeriodicDidProcStateType, DCM_VAR) Dcm_PeriodicDidProcState[1];
#endif

#if(DCM_DSP_SECURITY_SERVICE == STD_ON)
/* Added by AUTRON */
  VAR(Dcm_SecurityAccessStateType, DCM_VAR) Dcm_SecurityAccessState[1];
#endif

/* Global Variable to store the value of Tx length and Rx data buffer  */
  VAR(PduInfoType, DCM_VAR) Dcm_GddTxMessageType;

/* Global Variable to store the value of Rx length and Rx data buffer  */
  VAR(PduInfoType, DCM_VAR) Dcm_GddRxMessageType;

  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA)
  Dcm_GpPerMsgContext;

  VAR(Dcm_ServiceForcePendingStatusType, DCM_VAR)
  Dcm_ServiceForcePendingStatus;

  VAR(Dcm_ServicePendingStatusType, DCM_VAR)
  Dcm_ServicePendingStatus;

  /* MISRA Rule : 18.4
     Message      : Unions shall not be used.
     Reason       : Data access of larger data types is used to achieve
                    better throughput
     Verification : However, part of the code is verified
                    manually and it is not having any impact.
  */
  VAR(Dcm_MemServicePendingStatusType, DCM_VAR)\
                        Dcm_MemServicePendingStatus;

/* Global Variable to store the pointer to the current timing values */
  VAR(Dcm_TimerServerType, DCM_VAR) Dcm_GstCurrentTimingValue;

/* Global Variable to store the current security level */
  VAR(Dcm_SecLevelType, DCM_VAR) Dcm_GddSecurityLevel;

/* Global Variable of MsgContext Type */
  VAR(Dcm_MsgContextType, DCM_VAR) Dcm_GstMsgContext;

  VAR(Dcm_MsgContextType, DCM_VAR) Dcm_GstPerMsgContext;

/* Global Variable to store length of the request which is in progress */
  VAR(Dcm_MsgLenType, DCM_VAR) Dcm_GaaReqLength[DCM_NUM_OF_PROTOCOLCONFIG];

  VAR(uint8, DCM_VAR) Dcm_GaaTesterPresentReqBuff[DCM_BUFSZ_TESTERPRESENT];

/* Global Variable to store Protocol Id */
  VAR(Dcm_ProtocolType, DCM_VAR) Dcm_GddProtocolId;

  /* MISRA Rule : 18.4
     Message      : Unions shall not be used.
     Reason       : Data access of larger data types is used to achieve
                    better throughput
     Verification : However, part of the code is verified
                    manually and it is not having any impact.
  */
/* Global Variable to store page buffer status */
  VAR(Dcm_DspSerPgStatusType, DCM_VAR) Dcm_DspSerPgStatus;

  /* MISRA Rule : 18.4
     Message      : Unions shall not be used.
     Reason       : Data access of larger data types is used to achieve
                    better throughput
     Verification : However, part of the code is verified
                    manually and it is not having any impact.
  */
/* Global Variable to store the status of the timer */
  VAR(Dcm_ReqTimerFlagStatusType, DCM_VAR)
  Dcm_TimerReqFlagStatus;

  /* MISRA Rule : 18.4
     Message      : Unions shall not be used.
     Reason       : Data access of larger data types is used to achieve
                    better throughput
     Verification : However, part of the code is verified
                    manually and it is not having any impact.
  */
/* Global Variable to store the status of the transmission */
  VAR(Dcm_TxRespStatusType, DCM_VAR) Dcm_TxRespStatus;

  /* MISRA Rule : 18.4
     Message      : Unions shall not be used.
     Reason       : Data access of larger data types is used to achieve
                    better throughput
     Verification : However, part of the code is verified
                    manually and it is not having any impact.
  */
/* Global Variable to store the status of the protocol
and provide buffer for transmission */
  VAR(Dcm_PrtclTxBufStatusType, DCM_VAR) Dcm_PrtclTxBufStatus;

/* Global Variable to store the current session level */
  VAR(Dcm_SesCtrlType, DCM_VAR) Dcm_GddCurrentSession;

/* Global Variable to store the previous session */
  VAR(Dcm_SesCtrlType, DCM_VAR) Dcm_GddOldSession;

/* Global Variable to store negative response code */
  VAR(Dcm_NegativeResponseCodeType, DCM_VAR) Dcm_GddNegRespError;

/* Global Variable to store OpStatus */
  VAR(Dcm_OpStatusType, DCM_VAR) Dcm_GddGeneralOpStatus;

/* Global Variable to store DcmTxPduId */
  VAR(PduIdType, DCM_VAR) Dcm_GddDcmTxPduId;

#if(DCM_RESPONSEON_SECOND_DECLINE_REQUEST == STD_ON)
/* Global Variable to store DcmTxPduId of the second request*/
  VAR(PduIdType, DCM_VAR) Dcm_GddSecDeclTxPduId;
#endif

#if(DCM_RESPONSEON_SECOND_DECLINE_REQUEST == STD_ON)
/* Global Variable to store DcmTxPduId of the second request*/
  VAR(PduIdType, DCM_VAR) Dcm_GddSecDeclConfTxPduId;
#endif

/* Global Variable to store DcmDslTxConfirmationPduId */
  VAR(PduIdType, DCM_VAR) Dcm_GddDcmTxConfPduId;

#if((DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON) && \
     (DCM_PROTOCOL_TRANSTYPE2 == STD_ON))
  VAR(PduIdType, DCM_VAR) Dcm_GddDcmPeriodicTxConfPduId;
#endif

#if(DCM_PAGEDBUFFER_ENABLED == STD_ON)
/* Global Variable to store the response length pending in paged transmission*/
  VAR(Dcm_MsgLenType, DCM_VAR) Dcm_GddCurrentLength;
#endif

/* Global Variable to store the RxPduId */
  VAR(PduIdType, DCM_VAR) Dcm_GddRxPduId;

/* Global Variable to store the response length for the first page */
  VAR(Dcm_MsgLenType, DCM_VAR) Dcm_GddTxResponseLen;

/* Global Variable to store the request length from the request */
  VAR(PduLengthType, DCM_VAR) Dcm_GddTpSduLength;

#if(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON)
/* Global Variable to store the RxPduId of Periodic request */
  VAR(PduIdType, DCM_VAR) Dcm_GddPIdRxPduId;
#endif

  VAR(Dcm_OpStatusType, DCM_VAR) Dcm_GddOpStatus;

#if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || \
(DCM_DYNAMICALLYDEFINE_DATA_IDENTIFIER_SERVICE == STD_ON))
  VAR(Dcm_OpStatusType, DCM_VAR) Dcm_GddCheckReadOpStatus;
#endif

#if(DCM_COMMUNICATION_CONTROL_SERVICE == STD_ON)
  VAR(Dcm_CommunicationModeType, DCM_VAR)Dcm_GddCommunicationType;
#endif

#if((DCM_DSP_SECURITY_SERVICE == STD_ON) || \
(DCM_READ_SCALINGDATA_BYIDENTIFIER_SERVICE == STD_ON) || \
(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON) || \
(DCM_ROUTINECONTROL_SERVICE == STD_ON))
  /* MISRA Rule : 18.4
     Message      : Unions shall not be used.
     Reason       : Data access of larger data types is used to achieve
                    better throughput
     Verification : However, part of the code is verified
                    manually and it is not having any impact.
  */
  VAR(Dcm_DspServiceProcessingStsType, DCM_VAR)
Dcm_DspServiceProcessingSts;
#endif

#if(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
/* Global Variable to store the pointer to the MsgContext */
P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA)
  Dcm_GpRoeMsgContext;

/* Global Variable to store the response length pending in paged transmission*/
VAR(Dcm_MsgLenType, DCM_VAR) Dcm_GddRoeReqLength;
#endif

  /* MISRA Rule : 18.4
     Message      : Unions shall not be used.
     Reason       : Data access of larger data types is used to achieve
                    better throughput
     Verification : However, part of the code is verified
                    manually and it is not having any impact.
  */

#if(DCM_ROUTINECONTROL_SERVICE == STD_ON)
  P2VAR(void, AUTOMATIC, DCM_APPL_DATA) Dcm_GpRoutineSignalInDataPtr;

  P2VAR(void, AUTOMATIC, DCM_APPL_DATA) Dcm_GpRoutineSignalOutDataPtr;
#endif

  VAR(Dcm_ProgConditionsType, DCM_VAR) Dcm_GddProgConditions;

#if(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
VAR(Dcm_MsgContextType, DCM_VAR) Dcm_GstRoeMsgContext;

VAR(Dcm_RoeRequestInfo, DCM_VAR)
  Dcm_GddRoeRequestInfo[DCM_ROE_STRT_SIZE];

#if(DCM_MAX_NO_OF_PRECONFIGURED_DID != DCM_ZERO)

  VAR(Dcm_PreConfiguredRoe, DCM_VAR)
  Dcm_GddPreConfiguredDID[DCM_MAX_NO_OF_PRECONFIGURED_DID];

#endif
#if(DCM_ROE_QUEUE_ENABLED == STD_ON)

VAR(Dcm_RoeQueueProcessInfo, DCM_VAR) Dcm_GddRoeQueueProcessInfo;

VAR(Dcm_DslRoeQueueInfo, DCM_VAR)
  Dcm_GaaRoeQueueInfo[DCM_ROE_MAX_QUEUE_LENGTH];
#endif

VAR(PduIdType, DCM_VAR) Dcm_GddRoeRxPduId;

VAR(PduIdType, DCM_VAR) Dcm_GddStartRoeRxPduId;

/* Gobal Variable to store the requested serviceToRespondTo */
VAR(Dcm_RoeRetryProcessInfo, DCM_VAR) Dcm_GddRoeRetryProcessInfo;
#endif

VAR(Dcm_RequestContextType, DCM_VAR)  Dcm_RequestContext[DCM_NUM_OF_PROTOCOLCONFIG];
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/* Added by youngjin.yun, 2015-01-02 */
#define DCM_START_SEC_CONST_8
#include "MemMap.h"

/* number of the entries of each data type */
CONST(uint8, DCM_CONST) 
  Dcm_SizeOfDataType[7] =
{
  1, /* DCM_DSP_DATA_TYPE_BOOLEAN 0 */
  2, /* DCM_DSP_DATA_TYPE_SINT16  1 */
  4, /* DCM_DSP_DATA_TYPE_SINT32  2 */
  1, /* DCM_DSP_DATA_TYPE_SINT8   3 */
  2, /* DCM_DSP_DATA_TYPE_UINT16  4 */
  4, /* DCM_DSP_DATA_TYPE_UINT32  5 */
  1, /* DCM_DSP_DATA_TYPE_UINT8   6 */
};

#define DCM_STOP_SEC_CONST_8
#include "MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
