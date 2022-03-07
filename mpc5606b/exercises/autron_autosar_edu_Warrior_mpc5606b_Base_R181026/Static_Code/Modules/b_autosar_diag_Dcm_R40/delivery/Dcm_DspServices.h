/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_DspServices.h                                             **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_DspServices                                  **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 1.0.3    10-08-2015    Youngjin Yun    #2977                               **
**                                                                            **
** 1.0.2    16-04-2015    Sungeol Baek    #2171                               **
**                                                                            **
** 1.0.1    26-02-2015    YoungJin Yun    #414, #1044                         **
**                                                                            **
** 1.0.0    09-01-2013    Autron          Initial Version                     **
*******************************************************************************/

#ifndef DCM_DSPSERVICES_H
#define DCM_DSPSERVICES_H

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/*
polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard-Chap 5.1.2)
*/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define DCM_START_SEC_CODE
#include "MemMap.h"

#if(DCM_READDTC_SUPPORT == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmReadDTCInformation(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_DSP_CLR_DIAG_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmClearDiagnosticInformation(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE) Dcm_DspClearDiagInfo(uint32 LulDTC,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_DSP_CONTROL_DTC_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmControlDTCSetting(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_DSP_DIAG_SESSION_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDiagnosticSessionControl(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_DSP_SECURITY_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmSecurityAccess(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

FUNC(Std_ReturnType, DCM_CODE)Dcm_DspInternal_DcmSecurityAccess(
  Dcm_OpStatusType anOpStatus,
  P2CONST(Dcm_SecurityLevConfigType, AUTOMATIC, DCM_APPL_CONST) aSecData,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) aReqResData,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) anOutNegRespCode,
  uint8 aSecurityLevel);
#endif

#if(DCM_DSP_TESTER_PRESENT_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmTesterPresent(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_ECURESET_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmECUResetService(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if (DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) 
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmReadDataByIdentifier(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || \
(DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON))

extern FUNC(void, DCM_CODE) Dcm_ResetDIDOpStatus(void);
#endif

#if(DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmWriteDataByIdentifier(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
extern FUNC(void, DCM_CODE) Dcm_DcmWriteDataByIdentifierCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
  uint16 LusDIDIndex);

extern FUNC(void, DCM_CODE) Dcm_DspWriteDidRangeData(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
  uint16 LusDataIdentifier, uint16 LusDIDIndex);

extern FUNC(void, DCM_CODE) Dcm_ResetWriteDIDOpStatus(void);
#endif

#if(DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmInputOutputControlByIdentifier(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(Std_ReturnType, DCM_CODE)  Dcm_DspInternal_DcmInputOutputControlByIdentifier(
  Dcm_OpStatusType anOpStatus,
  uint8 anInputOutputControlParameter, 
  P2CONST(Dcm_DIDParaConfig, AUTOMATIC, DCM_APPL_CONST) aCfgDid,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) aMsgContext);

extern FUNC(void, DCM_CODE) Dcm_DspReturnControlToEcu(void);
#endif

#if(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmReadDataByPeriodicIdentifier(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(Std_ReturnType, DCM_CODE)
  Dcm_DspInternal_DcmReadDataByPeriodicIdentifier(
  Dcm_OpStatusType OpStatus,
   P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE) Dcm_StopPeriodicTransmission(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE)Dcm_HandlePeriodicResponse
(P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_READ_SCALINGDATA_BYIDENTIFIER_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmReadScalingDataByIdentifier(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || \
  (DCM_READ_SCALINGDATA_BYIDENTIFIER_SERVICE == STD_ON) || \
  (DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON) || \
  (DCM_DYNAMICALLYDEFINE_DATA_IDENTIFIER_SERVICE == STD_ON) || \
  (DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON) || \
  (DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON) || \
  (DCM_ROUTINECONTROL_SERVICE == STD_ON))
extern FUNC(boolean, DCM_CODE) Dcm_IDSearch(uint16 aTypeOfDid,
  uint16 aDataId,
  P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) aOutDidIndex);
#endif

#if(DCM_ROUTINECONTROL_SERVICE == STD_ON)

extern FUNC(void, DCM_CODE) Dcm_DspStrtStpReqRsltRoutineControl(\
  uint8 LucStartStopRoutine, uint16 LusMaxBufferSize,
  uint16 LusRIDIndex,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_DYNAMICALLYDEFINE_DATA_IDENTIFIER_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDynamicallyDefineDataIdentifier(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_COMMUNICATION_CONTROL_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmCommunicationControl(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if (DCM_RPT_DTCSNAPSHOTREC_BYSNAPSHOTNUM == STD_ON)
extern FUNC(void, DCM_CODE) Dcm_DspRptDTCSnapshotRecByRecordNum(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_LINK_CONTROL_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmLinkControlService(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_ENABLE_NORMAL_MSG_TRANSMISSION_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmEnableNormalMsgTransmission(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmStopDiagnosticSession(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

#if(DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON)
extern FUNC(void, DCM_CODE) Dcm_DspInternal_DcmReadDataByIdentifier(
  Dcm_OpStatusType anOpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) aMsgContext);
#endif

extern FUNC(void, DCM_CODE) 
Dcm_DspInternal_MemClear(
  P2VAR(uint8,AUTOMATIC,DEM_VAR) aDest,
  const uint32 aSize);
  
extern FUNC(void, DCM_CODE) 
Dcm_DspInternal_MemCopy(  
  P2VAR(uint8,AUTOMATIC,DEM_VAR) aDest,
  P2CONST(uint8,AUTOMATIC,DEM_VAR) aSrc,
  const uint32 aSize);

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/*
polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard-Chap 5.1.2)
*/
#endif /* DCM_DSPSERVICES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
