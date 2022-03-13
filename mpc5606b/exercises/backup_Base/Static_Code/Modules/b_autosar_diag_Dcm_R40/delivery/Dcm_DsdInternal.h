/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_DsdInternal.h                                             **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : Provision of external declaration of APIs and Service IDs     **
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
** 1.0.2     10-08-2015    Youngjin Yun   #2977                               **
**                                                                            **
** 1.0.1     16-04-2015    Sungeol Baek   #2171                               **
**                                                                            **
** 1.0.0     09-01-2013    Autron         Initial Version                     **
*******************************************************************************/

#ifndef DCM_DSDINTERNAL_H
#define DCM_DSDINTERNAL_H
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
 /* To SID index   */
extern FUNC(uint8, DCM_CODE)  Dcm_DsdSIdIndex(uint8  aServiceID);

 /* To provide indications  */
extern FUNC(boolean, DCM_CODE)Dcm_DsdIndication
  (PduIdType LddRxPduId, boolean LblStopProtocol, boolean LblPerTransmission,
    boolean LblROETransmission);

/* To provide confirmation  */
extern FUNC(void, DCM_CODE) Dcm_DsdConfirmation
                                       (NotifResultType LddResult);

/* Get Pdu ID */
extern FUNC(uint8,  DCM_CODE)  Dcm_GetProtocolIDIndex(uint8  aProtocolID);

extern 
boolean  Dcm_DsdValidateSecurity(
  P2CONST(uint8,  AUTOMATIC,  DCM_APPL_CONST) pSecurityLevelTable,
  uint8  numOfSecurityLevelEntry);  
  
extern boolean Dcm_DsdValidateSession(
P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST)LpSesLevel, uint8 LucNoOfSes);

extern FUNC(uint8, DCM_CODE) Dcm_DsdGetSubServiceModeRuleIndex(
  P2CONST(Dcm_SubServiceIdConfigType, AUTOMATIC, DCM_APPL_CONST)LpSubService,
                                     uint8 LucSubfucCount, uint8 LucSubfucion);

extern boolean Dcm_DsdModeConditionCheck(uint8 LucModeRuleIndex);

extern boolean  Dcm_DsdModeRuleCheck(Dcm_ModeType  LucModeRuleIndex);


/*******************************************************************************
**                     Response completion handling                           **
*******************************************************************************/

extern FUNC(void, DCM_CODE) Dcm_ExternalSetNegResponse(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
  Dcm_NegativeResponseCodeType ErrorCode);

extern FUNC(void, DCM_CODE) Dcm_ExternalProcessingDone
          (P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE) Dcm_InternalSetNegResponse(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
  Dcm_NegativeResponseCodeType ErrorCode);
  
extern FUNC(void, DCM_CODE) Dcm_InternalProcessingDone(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
  boolean IsSync);

/*******************************************************************************
**                       Paged transmission handling                          **
*******************************************************************************/

#if(DCM_PAGEDBUFFER_ENABLED == STD_ON)
extern FUNC(void, DCM_CODE) Dcm_DsdStartPagedProcessing
             (P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE) Dcm_DsdProcessPage(Dcm_MsgLenType FilledPageLen);
#endif

extern FUNC(void, DCM_CODE) Dcm_DsdCancelOperation(void);

extern FUNC(Dcm_MsgType, DCM_CODE) 
Dcm_DsdInternal_GetMsgTxBuffer(
  PduIdType aPduId,
  Dcm_BufferKindType aBufferKind
);

/*******************************************************************************
**                       Request Dispatcher                                   **
*******************************************************************************/
extern FUNC(void, DCM_CODE) Dcm_DiagnosticSerivceDispatch(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_RequestContextType, AUTOMATIC, DCM_APPL_DATA) requestContext);  

/*******************************************************************************
**                     Message context                                        **
*******************************************************************************/
extern FUNC(  P2CONST(Dcm_BufferConfig, AUTOMATIC, DCM_APPL_CONST), DCM_CODE) 
  Dcm_DsdInternal_GetBuffferConfig(PduIdType DcmRxPduId);
  

extern FUNC(P2CONST(Dcm_ProtocolConfig, AUTOMATIC, DCM_CONST), DCM_CODE) Dcm_DsdInternal_GetProcotocolByRxPduId(
  PduIdType DcmRxPduId);

  
extern  FUNC(P2VAR(Dcm_RequestContextType, AUTOMATIC, DCM_APPL_DATA), DCM_CODE) 
  Dcm_DsdInternal_GetRequestContextByRxPduId(PduIdType DcmRxPduId);

extern FUNC(P2CONST(Dcm_SubServiceIdConfigType, AUTOMATIC, DCM_PRIVATE_CONST), DCM_CODE) 
  Dcm_DsdInternal_GetSubFunctionByMsgContext(P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(P2CONST(Dcm_DiagSessionConfigType, AUTOMATIC, DCM_APPL_CONST), DCM_CODE) 
Dcm_DsdInternal_GetSessionCfg(
  P2CONST(Dcm_ProtocolConfig, AUTOMATIC, DCM_APPL_CONST) protocolCfg,
  Dcm_SesCtrlType requestSession,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) outSessionIndex);
  
FUNC(void, DCM_CODE) Dcm_DsdInternal_InitRequestContext(void);

#define DCM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/*
polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard-Chap 5.1.2)
*/
#endif /* DCM_DSDINTERNAL_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
