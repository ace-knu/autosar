/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_PCTypes.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_PCTypes                                      **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By                 Description                     **
********************************************************************************
** 1.0.10    27-06-2017    Jin     Jung       #8647                           **
**                                                                            **
** 1.0.9     25-05-2015    Sungeol Baek       #5006                           **
**                                                                            **
** 1.0.8     18-11-2015    Youngjin Yun       #3400                           **
**                                                                            **
** 1.0.7     10-08-2015    Youngjin Yun       #2977                           **
**                                                                            **
** 1.0.6     01-07-2015    YoungJin Yun       #2252                           **
**                                                                            **
** 1.0.5     19-06-2015    YoungJin Yun       #2718, #2693, #2692, #2691,     **
**                                            #2717, #2716                    **
**                                                                            **
** 1.0.4     16-06-2015    YoungJin Yun       #2717                           **
**                                                                            **
** 1.0.3     16-04-2015    Sungeol Baek       #2171                           **
**                                                                            **
** 1.0.2     24-03-2015    Sungeol Baek       #2370                           **
**                                                                            **
** 1.0.1     26-02-2015    YoungJin Yun       #1044                           **
**                                                                            **
** 1.0.0     09-01-2013    Autron             Initial Version                 **
*******************************************************************************/
#ifndef DCM_PCTYPES_H
#define DCM_PCTYPES_H

/* polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations> Not a defect */
/* polyspace:begin<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dcm.h"
#if(DCM_DIDSERVICE_SUPPORT_ENABLE == STD_ON)
#include "NvM.h"
#endif

/*******************************************************************************
**                      Structure related to Endianess Conversion             **
*******************************************************************************/
#if(CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
  /*  If the processor is Big Endian */
  /*  WORD Type Index */
  #define DCM_WORD_MS_BYTE_IDX        0u
  #define DCM_WORD_LS_BYTE_IDX        1u

  /*  DWORD Type Index */
  #define DCM_DWORD_MS_BYTE_IDX       0u
  #define DCM_DWORD_MS_MID_BYTE_IDX   1u
  #define DCM_DWORD_LS_MID_BYTE_IDX   2u 
  #define DCM_DWORD_LS_BYTE_IDX       3u
 
#else
  /* If the processor is Little Endian */
  /*  WORD Type Index */
  #define DCM_WORD_MS_BYTE_IDX        1u
  #define DCM_WORD_LS_BYTE_IDX        0u
  
  /*  DWORD Type Index */
  #define DCM_DWORD_LS_BYTE_IDX       0u
  #define DCM_DWORD_LS_MID_BYTE_IDX   1u
  #define DCM_DWORD_MS_MID_BYTE_IDX   2u
  #define DCM_DWORD_MS_BYTE_IDX       3u
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#ifndef DCM_SWCGEN
/* Length of diagnostic message (request, positive or negative response) */
typedef uint32 Dcm_MsgLenType;

/* Base type for diagnostic message item */
typedef uint8 Dcm_MsgItemType;

/*
 * IdContext is used to determine the relation between request and response
 * confirmation
 */
typedef uint8 Dcm_IdContextType;

#endif

/* TODO: Swcgen
 * Base type for diagnostic message (request, positive or negative response) */
typedef Dcm_MsgItemType* Dcm_MsgType;



/* Additional information on message request */
typedef struct STagDcm_MsgAddInfoType
{
  /* To know if the request type is physical or functional */
  uint8 reqType;
  /* To know if the positive response is to be suppressed */
  uint8 suppressPosResponse;

  /* To know if the Cancel operation is pending  */
  uint8 cancelOperation;
}Dcm_MsgAddInfoType;

/*
 * This structure contains all information, which is necessary to process a
 * diagnostic message from request to response and response confirmation.
 */
typedef struct STagDcm_MsgContextType
{
  /* Request data, starting directly after service identifier */
  Dcm_MsgType reqData;
  /* Request data length (excluding service identifier) */
  Dcm_MsgLenType reqDataLen;
  /* Positive response data, starting directly after service identifier */
  Dcm_MsgType resData;
  /* Positive response data length (excluding service identifier) */
  Dcm_MsgLenType resDataLen;
  /* Additional information about service request and response */
  Dcm_MsgAddInfoType msgAddInfo;
  /* The maximal length of a response */
  Dcm_MsgLenType resMaxDataLen;
  /*
   * This message context identifier can be used to determine the relation
   * between request and response confirmation
   */
  Dcm_IdContextType idContext;
  /* Pdu Identifier on which the request was received */
  PduIdType dcmRxPduId;
}Dcm_MsgContextType;


typedef struct STagDcm_RequestContextType
{
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) rct_MsgContext;
  uint8 rct_ServiceIndex;
  uint8 rct_SubFunctionId;  
  PduIdType rct_RxPduId;
  Std_ReturnType rct_RequestResult;
} Dcm_RequestContextType;



#if(DCM_DSP_SECURITY_SERVICE == STD_ON)
#define Dcm_DspClearSecurityTimer() do{Dcm_GaaTimer[DCM_SECURITY_TIMER] = DCM_ZERO;} while(0)
#endif

#if (DCM_READDTC_SUPPORT == STD_ON)
/* Type definition for ReadDTC sub functions */
typedef P2FUNC(void, DCM_APPL_CODE, Dcm_CbkFuncPtrType)(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

/*******************************************************************************
** Structure of the Periodic transmission parameters                          **
*******************************************************************************/

#if ((DCM_PROTOCOL_TRANSTYPE2 == STD_ON) && \
(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON))
typedef struct STagDcm_DslPeriodicTxId
{
  /* Status of the ongoing RxPduId */
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pPerPduIdStatus;

  /* Handle Id to be used by the Lower Layer to confirm the transmission of
     the DcmDslPeriodicTxPdu to the LowerLayer */
  uint16 usPerTxConfmPduId;

  /* TxPduId for periodic transmission */
  PduIdType ddPerTxPduId;

  uint8 ucPeriBufferIndex;

  uint8 ucPerPduIdStatusMask;

  boolean blBufferProvided;

}Dcm_DslPeriodicTxId;
#endif

#if ((DCM_PROTOCOL_TRANSTYPE2 == STD_ON) && \
(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON))
typedef struct STagDcm_DslPeriodicTxBuf
{
  /* pointer to data for periodic transmission */
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pPerData;

  /* Length of data for periodic transmission */
  uint32 ulDataLen;

  /* status of data for periodic transmission */
  uint8 ucDataStatus;

}Dcm_DslPeriodicTxBuf;
#endif

/*******************************************************************************
** Structure of the ResponseOnEvent transmission parameters                   **
*******************************************************************************/
#if ((DCM_PROTOCOL_TRANSTYPE2 == STD_ON) && \
   (DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON))
typedef struct STagDcm_DslRoeTrans
{
  /* TxPduId for Roe transmission if ROE Transmission Type is TYPE1 */
  PduIdType ddRoeTxPduId;

  /* Handle Id to be used by the Lower Layer to confirm the transmission of
     the DcmDslRoeTxPdu to the LowerLayer */
  uint16 usRoeTxConfirmPduId;

  /* Buffer used for the transmission of ROE event messages */
  uint8 ucRoeRxBufferId;

  /* Buffer used for the transmission of ROE event messages */
  uint8 ucRoeTxBufferId;

  boolean blRoeTransType;

}Dcm_DslRoeTrans;
#endif
/*******************************************************************************
** Structure for the PduId configuration                                      **
*******************************************************************************/

typedef struct STagDcm_PduIdTable
{
   /* Status of the ongoing RxPduId */
   P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pPduIdStatus;

   #if ((DCM_PROTOCOL_TRANSTYPE2 == STD_ON) &&  \
   (DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON))
   /* Pointer to support Periodic Type 2 for protocol ID 5 & 6 */
   P2VAR(Dcm_DslPeriodicTxId, AUTOMATIC, DCM_APPL_DATA) pPeriodicTxId;
   #endif

   #if ((DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON) && \
        (DCM_PROTOCOL_TRANSTYPE2 == STD_ON))
   P2CONST(Dcm_DslRoeTrans, AUTOMATIC, DCM_APPL_CONST) pRoeTxId;
   #endif

  #if((DCM_COMMUNICATION_CONTROL_SERVICE == STD_ON) || \
  (DCM_ENABLE_NORMAL_MSG_TRANSMISSION_SERVICE == STD_ON))
  /* Function to perform mode switch for the corresponding network */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pSchMSwitchCommModeFunc)
  (Dcm_CommunicationModeType CommunicationType);
  #endif

   /* Referred TxPduId configured for a particular RxPduId */
   PduIdType ddTxPduId;

   /* Protocol Id */
   Dcm_ProtocolType ddProtocolId;

   /* Channel Identifier associated to the received Pdu */
  uint32 ulProRxChannelId;
  uint32 ulRxCopiedLength;

  /* Handle Id to be used by the Lower Layer to confirm the transmission
     of the DcmDsProtocolTxPdu to the LowerLayer */
  uint16 usTxConfirmationPduId;

  /* Tester source address configured per protocol and provided
     for the jump to Bootloader */
  uint16 ucProRxTesterSrcAddr;

  #if ((DCM_PROTOCOL_TRANSTYPE2 == STD_ON) &&  \
  (DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON))
  uint8 ucPeriTransRxBufferIndex;
  #endif

  /* Rx address type */
  uint8 ucRxAddrType;

  /* Mask required for updating the status of RxPduId */
  uint8 ucPduIdStatusMask;

  /* Buffer Id for message transmission */
  uint8 ucTxBufferId;

  /* Buffer Id for message reception */
  uint8 ucRxBufferId;

  #if ((DCM_PROTOCOL_TRANSTYPE2 == STD_ON) &&  \
  (DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON))
  /*  Number Of Periodic Connection*/
  uint8 ucNoofPeriodicCon;
  #endif

  uint8 ucRxComChannelRef;

  uint8 ucReceiveStatus;

}Dcm_PduIdTable;
/*******************************************************************************
** Structure declarations of  diagnostic session service                      **
*******************************************************************************/

typedef struct STagDcm_DiagSessionConfigType
{

  /* Diagnostic Session control level */
  Dcm_SesCtrlType ddSesCtrlLevel;

  /* Timer value of P2StarServerMax for the session */
  uint16 usSesP2StrServerMax;

  /* Timer value of P2ServerMax for the session */
  uint16 usSesP2ServerMax;

  /* SessionForBoot level */
  uint8 ucSesForBootLevel;

}Dcm_DiagSessionConfigType;

/*******************************************************************************
** Structure declaration for DcmModeCOndition                                 **
*******************************************************************************/
#if (DCM_MODE_CONDITION == STD_ON)
typedef struct STagDcm_ModeConditionConfigType
{
  P2FUNC(uint8, DCM_APPL_CODE, pGetCurrentMode)(void);

  /* To get the mode value supported */
  uint8 ucBsworSwcMode;

  /* Dcm Condition Type */
  uint8 ucConditionType;

}Dcm_ModeConditionConfigType;
#endif


#if (DCM_MODE_RULE == STD_ON)
typedef struct STagDcm_ModeRuleConfigType
{

 /* Type of Logical operator used */
  uint8 ucLogicalOperator;

  #if(DCM_DSP_MODE_RULE_NRC == STD_ON)
  /* Type of NRC To be Send  */
  uint8 ucNRCType;
  #endif

  /* The Number of mode condition Argument */
  uint8 ucDcmNoOfModeCondnArg;

  /*index of Mode condition index array*/
  uint8 ucIndexOfModeConditionIndexArray;

  /* The Number of mode Rule Argument */
  uint8 ucDcmNoOfModeRuleArg;

  /*index of Mode rule index array*/
  uint8 ucIndexOfModeRuleIndexArray;
}Dcm_ModeRuleConfigType;
#endif

#if((DCM_COMMUNICATION_CONTROL_SERVICE == STD_ON) || \
(DCM_ENABLE_NORMAL_MSG_TRANSMISSION_SERVICE == STD_ON))
typedef struct STagDcm_CommControlConfigType
{
  /* Function to perform mode switch for the corresponding network */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pSchMSwitchCommModeFunc)\
  (Dcm_CommunicationModeType CommunicationType);

  /* Reference to Specific ComM Channel */
  uint8 ucSingleComChannelRef;

  /* Value of SubSetNumber */
  uint8 ucSubNetNumber;

}Dcm_CommControlConfigType;


typedef struct STagDcm_AllCommControlConfigType
{
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pSchMSwitchAllCommModeFunc)
    (Dcm_CommunicationModeType CommunicationType);

  /* Reference to ComM Channel */
  uint8 ucComChannelRef;
}Dcm_AllCommControlConfig;

#endif

/*******************************************************************************
** Structure for the Sub Service identifier table configuration               **
*******************************************************************************/

typedef struct STagDcm_SubServiceIdConfigType
{
  /* Pointer to array of sessions supporting the requested Sub service Id */
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pSubSerSession;

  /* Pointer to array of security levels supporting the requested Sub
     service Id */
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pSubSerSecurity;

  /* [SWS_Dcm_00764]
   * Std_ReturnType <Module>_<DiagnosticService>_<SubService>( 
   *  Dcm_OpStatusType OpStatus, 
   *  const Dcm_MsgContextType* pMsgContext)
   */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pSubServiceFnc) (
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

  #if (DCM_MODE_RULE == STD_ON)
   /*variable to hold the index of moderuleArrayindex */
  Dcm_ModeType ucsubmoderuleArrayindex;
  #endif

  /* Number of sessions */
  uint8 ucSubSerSessionCount;

  /* Number of security levels */
  uint8 ucSubSerSecurityCount;

  /* Id of the SubService identifier in hex. The possible Service identifier
     are predefined in the ISO 14229-1 and ISO 15031-5 */
  uint8 ucSubServiceId;

  #if(DCM_READDTC_SUPPORT == STD_ON)
  /* Subfunction Length */
  uint8 ucSubFuncLength;
  #endif

  #if (DCM_MODE_RULE == STD_ON)
   /*variable to hold the index of moderuleArrayindex */
  boolean blModeRuleConfigured;
  #endif

}Dcm_SubServiceIdConfigType;

/*******************************************************************************
** Structure for the Service identifier table configuration                   **
*******************************************************************************/

typedef struct STagDcm_ServiceIdConfigType
{
  /* Pointer to array of sessions supporting the requested service Id */
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pSession;

  /* Pointer to array of security levels supporting the requested service Id */
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pSecurity;

  /* [SWS_Dcm_00763]
   * Std_ReturnType <Module>_<DiagnosticService>(
   *  Dcm_OpStatusType OpStatus, 
   *  const Dcm_MsgContextType* pMsgContext )
   */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pDiagnosticService)(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

  /* Reference to the Sub Service table configured for this Service ID */
  P2CONST(Dcm_SubServiceIdConfigType, AUTOMATIC, DCM_APPL_CONST)pSubServiceId;

  #if (DCM_MODE_RULE == STD_ON)
  /* index for seviceModeruleindexarray at service level */
  Dcm_ModeType ucseviceModeruleindexarray;
  #endif

  /* Number of sessions */
  uint8 ucSessionCount;

  /* Number of security levels */
  uint8 ucSecurityCount;

  /* Number of Sub Service configured for this ServiceID */
  uint8 ucSubServiceCount;

    /* Service Id */
  uint8 ucServiceId;

  /* Minimum Length of request to validate */
  uint8 ucMinReqLength;

  /* Sub function availability */
  boolean blSubFunctionAvailable;

  #if (DCM_MODE_RULE == STD_ON)
  /* index for seviceModeruleindexarray at service level */
  boolean blModeRuleConfigured;
  #endif

}Dcm_ServiceIdConfigType;
/*******************************************************************************
** Structure for the protocol configuration                                   **
*******************************************************************************/

typedef struct STagDcm_ProtocolConfig
{
    /* Status of the ongoing Protocol */
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pProtocolStatus;
  #if(DCM_DSP_SESSION_REF == STD_ON)

  /* Reference to the DcmDspSession table used for this protocol */
  P2CONST(Dcm_DiagSessionConfigType, AUTOMATIC, DCM_APPL_CONST)pSessiontable;
  #endif

  /* Pointer to table of service identifiers */
  P2CONST(Dcm_ServiceIdConfigType, AUTOMATIC, DCM_APPL_CONST) pServiceIdTable;

  /* Protocol preempt timeout */
  uint16 usPrtclPreempTimeOut;

  /* This parameter is used to guarantee that the DCM response is available on
  * the bus before reaching P2
  */
  uint16 usTimStrP2ServerAdjust;

  /* This parameter is used to guarantee that the DCM response is available on
  * the bus before reaching P2*
  */
  uint16 usTimStrP2StarServerAdjust;

  /* Protocol priority */
  uint8 ucProtocolPrio;

  /* Service Table Id linked for the protocol */
  uint8 ucCurrentSIdTable;

  /* Mask required for updating the status of Protocol */
  uint8 ucPrtclStatusMask;

  #if(DCM_DSP_SESSION_REF == STD_ON)
  /* Tool search for default session and give the index for that table*/
  uint8 ucDefaultSesIndex;

  /* Tool search for index of that table*/
  uint8 ucSesTableIndex;

  /* Number of Sessions configured for that table */
  uint8 ucSesCntInTable;
  #endif

  uint8 ucServiceCount;

  /* Enables the parallel processing of ROE or Periodic Transmission protocol */
  boolean blProtocolIsParallelExecutab;

  /* Selects the transmission type for protocol */
  boolean blProtocolTransType;

  /* To check which endianness enabled*/
  boolean blProtocolEndiannessConvEnabled;

  boolean blSendRespPendOnTransToBoot;

}Dcm_ProtocolConfig;

/*******************************************************************************
** Structure of generic buffer configuration required for storing request and **
** response messages. These buffer Ids can be used as both Tx and Rx buffer Id**
*******************************************************************************/

typedef struct STagDcm_BufferConfig
{
  /* Pointer to RAM buffer area for the configured buffer Id */
  Dcm_MsgType pBufferArea;

  /* Size of the Buffer */
  Dcm_MsgLenType ulBufferSize;

}Dcm_BufferConfig;


/*******************************************************************************
**  Structure for the DID Services                                            **
*******************************************************************************/

#if(DCM_DIDSERVICE_SUPPORT_ENABLE == STD_ON)

#if(DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON)
/* Structure for DidInfo DIDWrite */

typedef struct STagDcm_DIDInfoTypeDidWrite
{
  /* Pointer to array of sessions supporting the requested DID for Write */
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pDidWriteSession;

  /*Pointer to array of security levels supporting the requested DID for Write*/
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pDidWriteSecurity;

  #if (DCM_MODE_RULE == STD_ON)
  /*variable to hold the index of moderuleArrayindex */
  Dcm_ModeType ucDIDmoderuleArrayindex;
  #endif

  /* Number of sessions */
  uint8 ucDidWriteSesCount;

  /* Number of security levels */
  uint8 ucDidWriteSecCount;

  #if (DCM_MODE_RULE == STD_ON)
  /*variable to hold the index of moderuleArrayindex */
  boolean blModeRuleConfigured;
  #endif

}Dcm_DIDInfoTypeDidWrite;

#endif


#if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || \
  (DCM_DYNAMICALLYDEFINE_DATA_IDENTIFIER_SERVICE == STD_ON) || \
  (DCM_READ_SCALINGDATA_BYIDENTIFIER_SERVICE == STD_ON)||\
  (DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON))
/* Structure for DidInfo DIDRead */
typedef struct STagDcm_DIDInfoTypeDidRead
{
  /* Pointer to array of sessions supporting the requested DID for Read */
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pDidReadSession;

  /*Pointer to array of security levels supporting the requested DID for Read*/
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pDidReadSecurity;

  #if (DCM_MODE_RULE == STD_ON)
  /*variable to hold the index of moderuleArrayindex */
  uint8 ucDIDmoderuleArrayindex;
  #endif

  /* Number of sessions */
  uint8 ucDidReadSesCount;

  /* Number of security levels */
  uint8 ucDidReadSecCount;

  #if(DCM_DYNAMICALLYDEFINE_DATA_IDENTIFIER_SERVICE == STD_ON)
  /* */
  uint8 ucMaxNumSourceElem;
  #endif

  #if (DCM_MODE_RULE == STD_ON)
  boolean blModeRuleConfigured;
  #endif

}Dcm_DIDInfoTypeDidRead;

#endif

#if(DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON)
/* Structure for DidInfo DIDControl */
typedef struct STagDcm_DIDInfoTypeDidCtrl
{
  /* Pointer to array of sessions supporting the requested DID */
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pDidCtrlSession;

  /* Pointer to array of security levels supporting the requested DID*/
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pDidCtrlSecurity;

  /* Number of sessions */
  uint8 ucDidCtrlSesCount;

  /* Number of security levels */
  uint8 ucDidCtrlSecCount;

  #if (DCM_MODE_RULE == STD_ON)
   /*variable to hold the index of moderuleArrayindex */
  Dcm_ModeType ucDIDmoderuleArrayindex;
  #endif

  /* This indicates the presence of Freeze current state */
  boolean blFreezeCrntState;

  /* This indicates the presence of Reset to default */
  boolean blResetToDefault;

  /* This indicates the presence of Return control to ECU */
  boolean blRetCtrlToEcu;

  /* This indicates the presence of Short term adjustment */
  boolean blShrtTermAdj;

  #if (DCM_MODE_RULE == STD_ON)
  /*variable to hold the index of moderuleArrayindex */
  boolean blModeRuleConfigured;
  #endif

}Dcm_DIDInfoTypeDidCtrl;

#endif

#endif

#if(DCM_DIDSERVICE_SUPPORT_ENABLE == STD_ON)
/*Structure for DID info*/
typedef struct STagDcm_DIDInfoType
{
  #if(DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON)
  /*  Pointer to Dcm_DIDInfoTypeDidCtrl type */
  P2CONST(Dcm_DIDInfoTypeDidCtrl, AUTOMATIC, DCM_APPL_CONST) pDidControl;
  #endif

  #if ((DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON) ||\
  (DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || \
  (DCM_DYNAMICALLYDEFINE_DATA_IDENTIFIER_SERVICE == STD_ON) || \
  (DCM_READ_SCALINGDATA_BYIDENTIFIER_SERVICE == STD_ON))
  /*  Pointer to Dcm_DIDInfoTypeDidRead type */
  P2CONST(Dcm_DIDInfoTypeDidRead, AUTOMATIC, DCM_APPL_CONST) pDidRead;
  #endif

  #if(DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON)
  /*  Pointer to Dcm_DIDInfoTypeDidWrite type */
  P2CONST(Dcm_DIDInfoTypeDidWrite, AUTOMATIC, DCM_APPL_CONST) pDidWrite;
  #endif

  /* Indicates if this DID can be dynamically defined true = DID can be
  * dynamically defined false = DID can not be dynamically defined
  */
  boolean blDynamicallyDefined;

}Dcm_DIDInfoType;

/*Structure for DcmDspData info*/
typedef struct STagDcm_DataInfoType
{
  #if(DCM_READ_SCALINGDATA_BYIDENTIFIER_SERVICE == STD_ON)
  /*If Scaling information service is available for this Data, it provides the
  * size of the scaling information
  */
  uint32 ulDataScalingInfoSize;
  #endif

  /*Indicates if the datalength of the Data is fixed true = datalength of the
  * Data is fixed false = datalength of the Data is variable
  */
  boolean blDataFixedLength;

}Dcm_DataInfoType;


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ConditionCheckReadAsyncType)(
  Dcm_OpStatusType OpStatus, 
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) Nrc);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ConditionCheckReadSyncType)(
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC, DCM_APPL_DATA) Nrc);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ReadDataLengthAsyncType)(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) pDidLength);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ReadDataLengthSyncType)(
  P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) pDidLength);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ReadDataAsyncType)(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);   

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ReadDataSyncType)
   (P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);


/* Asynchronous interface */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_FreezeCurrentStateAsyncType)(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ResetToDefaultAsyncType)(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ReturnControlToEcuAsyncType)(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ShortTermAdjustmentFixedAsyncType)(
  P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) pControlOptionRecord,
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode
);
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ShortTermAdjustmentVarAsyncType)(
  P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) pControlOptionRecord,
  uint16 usDataLength, 
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode
);


/* Synchronous interface */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_FreezeCurrentStateSyncType)(
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ResetToDefaultSyncType)(
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ReturnControlToEcuSyncType)(
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ShortTermAdjustmentFixedSyncType)(
  P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) pControlOptionRecord,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode
);
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ShortTermAdjustmentVarSyncType)(
  P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) pControlOptionRecord,
  uint16 usDataLength, 
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode
);


typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_GetScalingInformationAsyncType)(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pScalingInfo,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_GetScalingInformationSyncType)(
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pScalingInfo,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode);
  

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_WriteDataFixedAsyncType )(
  P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) Data, 
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);  

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_WriteDataVarAsyncType)(
  P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) Data,
  uint16 usDataLength, 
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_WriteDataFixedSyncType )(
  P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) Data, 
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_WriteDataVarSyncType)(
  P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) Data,
  uint16 usDataLength, 
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);

/* TODO

typedef struct varAsync 
{
  fp writeDataVarAsync
  fp readDataVarAsync
}

typedef  struct varSync 
{
  fp writeDataVarSync
  fp readDataVarSync

}

typedef  struct FixedAsync 
{
  fp writeDataFixedAsync
}


typedef  struct FixedSync 
{
  fp writeDataFixedSync
}

typedef  struct nvmblock
{
  blockid
}




struct Data
{
  void* interface (refer to  varAsync or varSync or FixedAsync or FixedAsync)
  boolean fixed
  ucDcmDspDataUsePort 
  ucDcmDspDataType    
} DataType

 no need 

 3) pDataInfo (FixedSync or FixedAsync != null)
 */

typedef struct STagDcm_DcmDspDataconfig
{
  #if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || (DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON))
  Dcm_ConditionCheckReadAsyncType pConditionCheckReadAsync;
  Dcm_ReadDataLengthAsyncType pReadDataLengthAsync;
  Dcm_ReadDataAsyncType pReadDataAsync;  

  Dcm_ConditionCheckReadSyncType pConditionCheckReadSync;
  Dcm_ReadDataLengthSyncType pReadDataLengthSync;
  Dcm_ReadDataSyncType pReadDataSync;    
  #endif

  #if(DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON)
  Dcm_FreezeCurrentStateAsyncType pFreezeCurrentStateAsync;
  Dcm_ResetToDefaultAsyncType   pResetToDefaultAsync;
  Dcm_ReturnControlToEcuAsyncType pReturnControlToEcuAsync;
  
  Dcm_ShortTermAdjustmentFixedAsyncType pShortTermAdjustmentFixedAsync;
  Dcm_ShortTermAdjustmentVarAsyncType pShortTermAdjustmentVarAsync;

  Dcm_FreezeCurrentStateSyncType pFreezeCurrentStateSync;
  Dcm_ResetToDefaultSyncType   pResetToDefaultSync;
  Dcm_ReturnControlToEcuSyncType pReturnControlToEcuSync;
  
  Dcm_ShortTermAdjustmentFixedSyncType pShortTermAdjustmentFixedSync;
  Dcm_ShortTermAdjustmentVarSyncType pShortTermAdjustmentVarSync;
  #endif

  #if(DCM_READ_SCALINGDATA_BYIDENTIFIER_SERVICE == STD_ON)
  Dcm_GetScalingInformationAsyncType pGetScalingInformationAsync;
  
  Dcm_GetScalingInformationSyncType pGetScalingInformationSync;
  #endif

  #if(DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON)
  Dcm_WriteDataFixedAsyncType pWriteDataFixedAsync;
  Dcm_WriteDataVarAsyncType pWriteDataVarAsync;

  Dcm_WriteDataFixedSyncType pWriteDataFixedSync;  
  Dcm_WriteDataVarSyncType pWriteDataVarSync;
  #endif

  /* Pointer to Dcm_DataInfoType type */
  P2CONST(Dcm_DataInfoType, AUTOMATIC, DCM_APPL_CONST) pDataInfo;
  
  /* Length of data associated to the Data */
  uint16 usDcmDspDataSize;

  /*NRAM blockId to access the data. Only relevant if DcmDspDataUsePort==UseBlockId  */
  NvM_BlockIdType usDcmDspDataBlockIdRef;

  #if (DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON)
   /* Sender-Reciever Interface */
  uint8 ucWriteFunctionIndex;
  #endif

  #if ((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || (DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON))
  /* Sender-Reciever Interface */
  uint8 ucReadFunctionIndex;
  
  /* ECU Signal */
  uint8 ucEcuSignalFunctionIndex;
  #endif

  /* UsePort */
  uint8 ucDcmDspDataUsePort;
  
  /* DataType*/
  uint8 ucDcmDspDataType;

}Dcm_DcmDspDataconfig;



/* Structure for DIDOutSignal parameters*/
typedef struct STagDcm_DIDPackSignal
{
  uint32 ulSignalLength;
  /* Signal type */
  uint8 ucNoOfShiftBits;

  uint8  ucStartMask;

  uint8 ucEndMask;

  uint8 ucWrFuncIndex;

  uint8 ucSignalTypeorSize;

  uint8 ucSignalStartByte;

}Dcm_DIDPackSignal;

/* Structure for DIDOutSignal parameters*/
typedef struct STagDcm_DIDUnPackSignal
{
  uint32 ulSignalLength;
  uint8 ucNoOfShiftBits;

  uint8  ucEndMask;

  uint8 ucRdFuncIndex;

  uint8 ucSignalType;

  uint8 ucSignalSize;

  uint8 ucSignalStartByte;

  uint8 ucSignMask;

}Dcm_DIDUnPackSignal;

/*Structure for DcmDspData container and position relevant for this DID*/
typedef struct STagDcm_DcmDspSignalconfig
{
  /*  Pointer to Dcm_DcmDspDataconfig type */
  P2CONST(Dcm_DcmDspDataconfig, AUTOMATIC, DCM_APPL_CONST) pDcmDspData;

  #if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) ||\
  (DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON))
  P2CONST(Dcm_DIDPackSignal, AUTOMATIC, DCM_APPL_CONST)pDidPackSignal;
  #endif

  #if((DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON) ||\
  (DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON))
  P2CONST(Dcm_DIDUnPackSignal, AUTOMATIC, DCM_APPL_CONST)pDidUnPackSignal;
  #endif

  /*Defines the position of the data defined by DcmDspDidDataRef reference to
  * DcmDspData container in the DID
  */
  uint16 usDcmDspDidDataPos;

  /* Status of DID signal value read / write operation */
  /* Status of DID signal value read / write operation */
  uint8 ucDidSignalOpStatus;
}Dcm_DcmDspSignalconfig;

/* Structure for the configuration (parameters) of the DID */
typedef struct STagDcm_DIDParaConfig
{
  /*Reference to 1.. n DcmDspData container and position relevant for this DID*/
  P2VAR(Dcm_DcmDspSignalconfig, AUTOMATIC, DCM_APPL_DATA) pDcmDspSignal;

  #if ((DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON) &&\
  (DCM_EXTERNAL_ROE_ENABLED == STD_ON))
  /* Function name to activate/deactivate an ROE event managed externally.
  * Only relevant if DcmDspDataUsePort== usefunc
  */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pActivateEventFnc)
    (uint8 RoeEvenId, Dcm_RoeStateType RoeState);
  #endif
  /* Reference to DcmDspDidInfo containing information on this DID */
  P2CONST(Dcm_DIDInfoType, AUTOMATIC, DCM_APPL_CONST) pDidInfo;

  /* Pointer to array of DID reference */
  P2CONST(uint16, AUTOMATIC, DCM_APPL_CONST) pDidRef;

  /*  2 byte Identifier of the DID */
  uint16 usDcmDspDidIdentifier;

  /* Number of DidReferrence count */
  uint16 usDidRefCount;

  #if ((DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON) &&\
  (DCM_EXTERNAL_ROE_ENABLED == STD_ON))
  /*  EventId to be used within API Dcm_TriggerOnEvent() and
  * xxx_DcmActivateEvent()
  */
  uint8 ucDcmDspDidRoeEventId;
  #endif

  /* Number of DcmDspSignal */
  uint8 ucDcmDspSignalCount;

  #if (DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
  /* If set to TRUE, the ROE queue mechanism will be used in case of ROE
  * OnChangeOfDataIdentifier on this DID. If set to FALSE, the ROE event will
  * be sent without queuing
  */
  boolean blDidRoeQueueEnabled;
  /* This OnChangeOfDataIdentifier event is configured as externally managed */
  #if(DCM_EXTERNAL_ROE_ENABLED == STD_ON)
  boolean blDcmDspDidExtRoeEnabled;
  #endif
 #endif
  /*  Allow to activate or deactivate the usage of a DID, for multi purpose
  ECUs true = DID available false = DID not available */
  boolean blDspDidUsed;

  #if(DCM_MAX_NO_OF_PRECONFIGURED_DID != DCM_ZERO)
  boolean blPreConfigEnabled;
  #endif

}Dcm_DIDParaConfig;



/* Structure for the configuration (parameters) of the DID Range */
typedef struct STagDcm_DIDRangeConfig
{
  /* Function name to request from application if a specific DID is
  * available within the range or not..
  * Only relevant if DcmDspDidRangeUsePort is set to false
  */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pIsDidAvailableFnc)
                                 (uint16 DID, uint8* supported);

  /* Function name to request from application the data range value of a DID.
  * (ReadData-function).
  *  Only relevant if DcmDspDidRangeUsePort is set to false.
  */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pDidRangeReadDidFnc)
    (uint16 DID, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA)Data,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA)DataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA)ErrorCode);

  /* IN P2VAR -> P2CONST : Modified by youngjin.yun */
  /* Function name to requests the application to write a data value of a DID.
  * Only relevant if DcmDspDidRangeUsePort is set to false
  */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pDidRangeWriteDidFnc)(
    uint16 DID, 
    P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA)Data,
    Dcm_OpStatusType OpStatus, 
    uint16 DataLength,
    Dcm_NegativeResponseCodeType* ErrorCode);
/*
  FUNC(Std_ReturnType, RTE_CODE)Xxx_WriteDidData(
    IN AUTOSAR_uint16 DID,
    IN P2CONST(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) Data,
    IN Dcm_OpStatusType OpStatus,
    IN AUTOSAR_uint16 DataLength,
    OUT P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
*/
  /* Reference to DcmDspDidInfo containing information on this DID */
  P2CONST(Dcm_DIDInfoType, AUTOMATIC, DCM_APPL_CONST) pDidInfo;

  /*  DID Range Lower limit */
  uint16 usDidRangeIdLowerLimit;

  /*  DID Range Upper limit */
  uint16 usDidRangeIdUpperLimit;

  /*  Maximum data length in bytes */
  uint16 usDidRangeMaxDataLength;

  /* Status of DID signal value read / write operation */
  uint8 ucDidRangeOpStatus;

  /*  Parameter specifying if there are gaps in the DID range */
  boolean blDidRangeHasGaps ;

  /*  When the parameter DcmDspDidRangeUsePort is set to true the DCM will
   access the Data using an R-Port requiring a
   PortInteface DataServices_DIDRange. In that case,
   DcmDspDidRangeIsDidAvailableFnc, DcmDspDidRangeReadDidFnc
   and DcmDspDidRangeWriteDidFnc are ignored and the RTE APIs are used.
   When the parameter DcmDspDidRangeUsePort
   is false, the DCM calls the functions defined in
   DcmDspDidRangeIsDidAvailableFnc, DcmDspDidRangeReadDidFnc and
   DcmDspDidRangeWriteDidFnc.
   */
  boolean blDcmDspDidRangeUsePort;

}Dcm_DIDRangeConfig;
#endif
/*******************************************************************************
** Structure declarations of  Dynamically defined by identifier service       **
*******************************************************************************/


/* Structure for DidInfo Source DID */
typedef struct STagDcm_SrcIDInfoType
{
  /*  sourceDataIdentifier */
  uint16 usSrcID;

  /* Priority of Source */
  uint16 usPriority;

  /* positionInSourceDataRecord */
  uint8 ucPosInSrc;

  /* memorySize */
  uint8 ucMemSize;

}Dcm_SrcIDInfoType;

/* Structure for DidInfo Dynamic DID - Sub Function 01
             Defined by Identifier                   */
typedef struct STagDcm_DymDefinedDIDInfoType
{

  /* Pointer to array of SourceId info for this Dynamic DID  */
  P2VAR(Dcm_SrcIDInfoType, AUTOMATIC, DCM_APPL_DATA) pSrcIDInfo;

  /* Dynamic Data Identifier */
  uint16 usDynDid;

  /* Number of Source IDs from request  */
  uint8 ucSrcIDCount;

  /* DID information is set */
  boolean blDidSet;

}Dcm_DymDefinedDIDInfoType;

/* Structure for DidInfo Memory Address */
typedef struct STagDcm_MemAddInfoType
{
  /*  Memory Address */
  uint32 ulMemAddrs;

  /* memorySize */
  uint32 ulMemSize;

  /* Priority of Source */
  uint16 usPriority;

}Dcm_MemAddInfoType;

/* Structure for DidInfo Dynamic DID - Sub Function 02
                Defined by Memory Address                */
typedef struct STagDcm_DymMemDIDInfoType
{
  /* Pointer to array of Memory Address info for this Dynamic DID  */
  P2VAR(Dcm_MemAddInfoType, AUTOMATIC, DCM_APPL_DATA) pMemAddInfo;

  /* Dynamic Data Identifier */
  uint16 usDynDid;

  /* Number of Address count from request  */
  uint8 ucMemAddressCount;

  /* DID information is set */
  boolean blMemAddSet;

}Dcm_DymMemDIDInfoType;


/******************************************************************************/
/*  Structure declaration Routine Control Service 0x31                        */
/******************************************************************************/

#if( DCM_ROUTINECONTROL_SERVICE == STD_ON)

#if(DCM_ROUTINE_REQUEST_OUTSIGNAL_CONFIGURED == STD_ON)
/* Structure for RequestResultOutSignal parameters*/
typedef struct STagDcm_RequestResOutSignalType
{
  uint32 ulSignalLength;

  uint8 ucNoOfShiftBits;

  uint8  ucStartMask;

  uint8 ucEndMask;

  uint8 ucWrFuncIndex;

  uint8 ucSignalTypeorSize;

  uint8 ucSignalStartByte;


}Dcm_RequestResOutSignalType;
#endif

#if(DCM_ROUTINE_START_INSIGNAL_CONFIGURED == STD_ON)
/* Structure for StartRoutuneInSignal parameters */
typedef struct STagDcm_StartRoutineInSignalType
{
  uint32 ulSignalLength;

  uint8 ucNoOfShiftBits;

  uint8  ucEndMask;

  uint8 ucRdFuncIndex;

  uint8 ucSignalType;

  uint8 ucSignalSize;

  uint8 ucSignalStartByte;

  uint8 ucSignMask;

}Dcm_StartRoutineInSignalType;
#endif

#if(DCM_ROUTINE_START_OUTSIGNAL_CONFIGURED == STD_ON)
/* Structure for StartRoutuneOutSignal parameters */
typedef struct STagDcm_StartRoutineOutSignalType
{
  uint32 ulSignalLength;

  uint8 ucNoOfShiftBits;

  uint8  ucStartMask;

  uint8 ucEndMask;

  uint8 ucWrFuncIndex;

  uint8 ucSignalTypeorSize;

  uint8 ucSignalStartByte;

}Dcm_StartRoutineOutSignalType;
#endif

#if(DCM_ROUTINE_STOP_INSIGNAL_CONFIGURED == STD_ON)
typedef struct STagDcm_StopRoutineInSignalType
{
  uint32 ulSignalLength;

  uint8 ucNoOfShiftBits;

  uint8  ucEndMask;

  uint8 ucRdFuncIndex;

  uint8 ucSignalType;

  uint8 ucSignalSize;

  uint8 ucSignalStartByte;

  uint8 ucSignMask;

}Dcm_StopRoutineInSignalType;
#endif

#if(DCM_ROUTINE_STOP_OUTSIGNAL_CONFIGURED == STD_ON)
/* Structure for StopRoutuneOutSignal parameters */
typedef struct STagDcm_StopRoutineOutSignalType
{
  uint32 ulSignalLength;

  uint8 ucNoOfShiftBits;

  uint8  ucStartMask;

  uint8 ucEndMask;

  uint8 ucWrFuncIndex;

  uint8 ucSignalTypeorSize;

  uint8 ucSignalStartByte;


}Dcm_StopRoutineOutSignalType;
#endif


typedef struct STagDcm_RoutineSignalInfoType
{
  #if(DCM_ROUTINE_REQUEST_OUTSIGNAL_CONFIGURED == STD_ON)
 /* Pointer to array of Request Result Out parameters*/
  P2CONST(Dcm_RequestResOutSignalType, AUTOMATIC, DCM_APPL_CONST)
    pRequestResOut;
  #endif

  #if(DCM_ROUTINE_START_INSIGNAL_CONFIGURED == STD_ON)
  /* Pointer to array of Start Routine In parameters*/
  P2CONST(Dcm_StartRoutineInSignalType, AUTOMATIC, DCM_APPL_CONST)
    pStartRoutineIn;
  #endif

  #if(DCM_ROUTINE_START_OUTSIGNAL_CONFIGURED == STD_ON)
   /* Pointer to array of Start Routine Out parameters*/
  P2CONST(Dcm_StartRoutineOutSignalType, AUTOMATIC, DCM_APPL_CONST)
    pStartRoutineOut;
  #endif

  #if(DCM_ROUTINE_STOP_INSIGNAL_CONFIGURED == STD_ON)
  /* Pointer to array of Stop Routine In parameters*/
  P2CONST(Dcm_StopRoutineInSignalType, AUTOMATIC, DCM_APPL_CONST)
    pStopRoutineIn;
  #endif

  #if(DCM_ROUTINE_STOP_OUTSIGNAL_CONFIGURED == STD_ON)
   /* Pointer to array of Stop Routine Out parameters*/
  P2CONST(Dcm_StopRoutineOutSignalType, AUTOMATIC, DCM_APPL_CONST)
    pStopRoutineOut;
  #endif

  /* Number of StartRoutineInSignal */
  uint16 ucNumOfStartRtnInSignal;

  /* Number of RoutineStopInSignal */
  uint16 ucNumOfStopRtnInSignal;

  /* Number of RoutineStartOutSignal */
  uint16 ucNumOfStartRtnOutSignal;

  /* Number of RoutineStopOutSignal */
  uint16 ucNumOfStopRtnOutSignal;

  /* Number of RoutineRequestResOutSignal */
  uint16 ucNumOfRtnRequestResOutSignal;

}Dcm_RoutineSignalInfoType;



typedef struct STagDcm_RoutineConfigType
{
  /* Pointer to the Routine signal information*/
  P2CONST(Dcm_RoutineSignalInfoType, AUTOMATIC,DCM_APPL_CONST)
    pRoutineSignalInfo;
  /* pointer to supported session */
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pRoutineSession;

  /* pointer to supported security */
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pRoutineSecurity;

  #if (DCM_MODE_RULE == STD_ON)
   /*variable to hold the index of moderuleArrayindex */
  Dcm_ModeType ucDIDmoderuleArrayindex;
  #endif

  /* Total length of StartOut Signal */
  uint32 ulRoutineTotalStartOutLength;

  /* Total length of StartOut Signal */
  uint32 ulRoutineTotalStopOutLength;

  /* Total length of StartOut Signal */
  uint32 ulRoutineTotalReqResOutLength;

    /* 2 bytes Identifier of the RID */
  uint16 usRoutineIdentifier;

   /* Number of sessions */
  uint8 ucSessionCount;

  /* Number of security levels */
  uint8 ucSecurityCount;

  /* Start Stop Flag */
  uint8 ucStartStopRIDFlag;

  /* Routine UsePort */
  boolean blRoutineUsePort;

  /* Routine Fixed length */
  boolean blRoutineFixedLength;

  /* Routine Usage */
  boolean blRoutineUsed;

  /* Request Result Routine Support */
  boolean blRequestResultSupported;

  /* Stop Routine Support */
  boolean blStopRoutineSupported;

   #if (DCM_MODE_RULE == STD_ON)
  /*variable to hold the index of moderuleArrayindex */
  boolean blModeRuleConfigured;
  #endif

}Dcm_RoutineConfigType;


#endif
/*******************************************************************************
** Structure declarations of  security access service                         **
*******************************************************************************/

typedef struct STagDcm_SecurityLevConfigType
{
  #if (DCM_DSP_SECURITY_SERVICE == STD_ON)
  /* Function to get Seed value */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pGetSeedFun)
  (P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) SecurityAccessRecord,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Seed,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) Error);

  /* Function to get Seed value */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pGetSeedAsyncFun)
    (P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) SecurityAccessRecord,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Seed,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) Error);

  /* Function to get Seed value when ucSecurityADRSize is zero */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pGetSeedFunadr)
    (P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Seed,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) Error);

  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pGetSeedAsyncFunadr)
    (Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Seed,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) Error);

  /* Function to compare key value  */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pCompareKeyFun)
    (P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) Key);

  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pCompareKeyAsyncFun)
    (P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) Key, Dcm_OpStatusType OpStatus);
  #endif

  /* Security level value */
  Dcm_SecLevelType ddSecLevel;

    /* Size of the AccessDataRecord used in GetSeed */
  uint32 ulSecurityADRSize;

  /* Size of security key */
  uint32 ulSizeOfKey;

  /* Size of security seed */
  uint32 ulSizeOfSeed;

  /*
  Delay time after failed security access value is
  DCM_SEC_DELAY_INV_KEY/ DCM_TASK_TIME
  */
  uint16 usSecDelayInvKey;

  /* Start delay timer on power on (in ms) */
  uint16 usSecurityDelayTimeOnBoot;



  /* Number of security accesses after which delay time is activated */
  uint8 ucSecNumMaxAttDelay;

  uint8 ucSecurityUsePort;

}Dcm_SecurityLevConfigType;

/*******************************************************************************
** Structure declaration for OBDMID service                                   **
*******************************************************************************/

#if (DCM_OBD_REQ_ONBOARD_MONITORRESULT_SERVICE == STD_ON)
/* Structure declaration for OBDMID configured*/
typedef struct STagDcm_OBDMidTids
{
/* Function name for request to application to get DTR value */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pGetDTRValueFnc)
  (Dcm_OpStatusType OpStatus,
  P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) TestValue,
  P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) MinLimit,
  P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) MaxLimit,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Status);

  /*  Test Id for Service 06 */
  uint8 ucTestResultTestId;

  /*  contains the OBDMID and the assigned TIDs for Service 06 */
  uint8 ucTestResultUaSid;
}Dcm_OBDMidTids;

typedef struct STagDcm_OBDMidConfigType
{
  /* to hold Tid, Uasid */
  P2CONST(Dcm_OBDMidTids, AUTOMATIC, DCM_APPL_CONST) pDcmObdMidTids;

  /*  contains the OBDMID and the assigned TIDs for Service 06 */
  uint8 ucTestResultObdmid;

  uint8 ucNoOfTids;

}Dcm_OBDMidConfigType;
#endif

/*******************************************************************************
** Structure declaration for VehicleInfo service                              **
*******************************************************************************/

#if (DCM_OBD_REQVEHICLE_INFO_SERVICE == STD_ON)

typedef struct STagDcm_VehInfoData
{

 /*  Function name for reading the associated INFOTYPE */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pGetVehInfoTypeFnc)
    (Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) DataValueBuffer);

  /* Vehicle Info Data Order */
  uint8 ucVehInfoDataOrder;

  /* Vid Buffer Size  */
  uint8 ucVehInfoBufSize;

  /* InfoID UsePort */
  boolean blVehInfoUsePort;

}Dcm_VehInfoData;

typedef struct STagDcm_VehInfoConfigType
{
  P2CONST(Dcm_VehInfoData, AUTOMATIC, DCM_APPL_CONST) pDcmVehInfoData;

  uint8 ucVehInfoTypeId;

  /*  INFOTYPE for Service 09 */
  uint8 ucNoOfVehInfoData;

}Dcm_VehInfoConfigType;

#endif

/*******************************************************************************
** Structure declaration for RequestControl service                           **
*******************************************************************************/

#if (DCM_OBD_REQ_CTLRL_ONBOADSYSTEM_SERVICE == STD_ON)
typedef struct STagDcm_RequestControlConfigType
{
  /* Function name for request to application to stop a routine */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pReqControlFnc)
  (P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) OutBuffer,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) InBuffer);

  /* request control  in buffer Size */
  uint8 ucRequestControlInBufferSize;

   /* request control out buffer Size */
  uint8 ucRequestControlOutBufferSize;

  /* buffer for control option */
  uint8 ucRequestControlTestId;

}Dcm_RequestControlConfigType;
#endif


/*******************************************************************************
** Structure declaration for CallBackDCMRequestServices                       **
*******************************************************************************/

typedef struct STagDcm_CbkReqServicesConfigType
{
  /* Function name to indicate protocol start to application */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pStartProtocolFun)
    (Dcm_ProtocolType ProtocolID);

  /* Function name to indicate protocol stop to application */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pStopProtocolFun)
    (Dcm_ProtocolType ProtocolID);

}Dcm_CbkReqServicesConfigType;

/*******************************************************************************
** Structure declaration for ServiceRequestManufacturerIndication             **
*******************************************************************************/

#if(DCM_REQUEST_MANUFACTURER_INDICATION_ENABLED == STD_ON)
typedef struct STagDcm_SerReqManuIndConfigType
{
  /*
  Function name to Indicate successful reception of a new request to application
  */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pManuIndicationFun)(
    uint8 SID, 
    P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) RequestData,
    uint16 DataSize, 
    uint8 ReqType, 
    uint16 SourceAddress,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);

  /*
  Function name to Indicate successful transmission of response to application
  */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pManuConfirmationFun)(uint8 SID, 
    uint8 ReqType, 
    uint16 SourceAddress,
    Dcm_ConfirmationStatusType ConfirmationStatus);

}Dcm_SerReqManuIndConfigType;
#endif

/*******************************************************************************
** Structure declaration for ServiceRequestSupplierIndication                 **
*******************************************************************************/

#if (DCM_REQUEST_SUPPLIER_INDICATION_ENABLED == STD_ON)
typedef struct STagDcm_SerReqSuppIndConfigType
{
  /*
  Function name to Indicate successful reception of a new request to application
  */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pSuppIndicationFun)(
    uint8 SID, 
    P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) RequestData,
    uint16 DataSize, 
    uint8 ReqType, 
    uint16 SourceAddress,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode);

  /*
  Function name to Indicate successful transmission of response to application
  */
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pSuppConfirmationFun)(
    uint8 SID, 
    uint8 ReqType, 
    uint16 SourceAddress,
    Dcm_ConfirmationStatusType ConfirmationStatus);

}Dcm_SerReqSuppIndConfigType;
#endif

/*******************************************************************************
** Structure declaration for Availability List for PID/OBDMID/TID/InfoType    **
*******************************************************************************/
typedef struct STagDcm_IDEncodeByteConfig
{
  /*EncodedByteA Information */
  uint8 ucEncodeByteA;

  /*EncodedByteB Information */
  uint8 ucEncodeByteB;

  /*EncodedByteC Information */
  uint8 ucEncodeByteC;

  /*EncodedByteD Information */
  uint8 ucEncodeByteD;

}Dcm_IDEncodeByteConfig;

/*******************************************************************************
** Structure declaration for ReadMemoryByAddress                              **
*******************************************************************************/
#if ((DCM_READ_MEMORY_BY_ADDRESS_SERVICE == STD_ON) || \
  (DCM_DYNAMICALLYDEFINE_DATA_IDENTIFIER_SERVICE == STD_ON))
typedef struct STagDcm_ReadMemRngInfoConfigType
{

  /* pointer to supported security */
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pReadMemRngSec;

  #if (DCM_MODE_RULE == STD_ON)
  /*variable to hold the index of moderuleArrayindex */
  Dcm_ModeType ucDIDmoderuleArrayindex;
  #endif

  /* High memory address of a range allowed for reading */
  uint32 ulReadMemRngHigh;

  /* Low memory address of a range allowed for reading */
  uint32 ulReadMemRngLow;

  /* Memory Identifier */
  uint8 ucReadMemoryIdentifier;

  /* Security count for ReadMemory */
  uint8 ucReadMemSecCount;

  /* Value of the Memory whether used or not*/
  boolean blUseMemoryValue;

  #if (DCM_MODE_RULE == STD_ON)
   /*variable to hold the index of moderuleArrayindex */
  boolean blModeRuleConfigured;
  #endif

}Dcm_ReadMemRngInfoConfigType;
#endif

/*******************************************************************************
** Structure declaration for WriteMemoryByAddress                             **
*******************************************************************************/
#if ((DCM_WRITE_MEMORY_BY_ADDRESS_SERVICE == STD_ON) ||\
     (DCM_TRANSFER_DATA_SERVICE == STD_ON))
typedef struct STagDcm_WriteMemRngInfoConfigType
{

  /* pointer to supported security */
  P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) pWriteMemRngSec;

  #if (DCM_MODE_RULE == STD_ON)
   /*variable to hold the index of moderuleArrayindex */
  Dcm_ModeType ucDIDmoderuleArrayindex;
  #endif

  /* High memory address of a range allowed for writing */
  uint32 ulWriteMemRngHigh;

  /* Low memory address of a range allowed for writing */
  uint32 ulWriteMemRngLow;

  /* Memory Identifier */
  uint8 ucWriteMemoryIdentifier;

  /* Security count */
  uint8 ucWriteMemSecCount;

  /* Memory value used or not */
   boolean blUseMemoryValue;

  #if (DCM_MODE_RULE == STD_ON)
  /*variable to hold the index of moderuleArrayindex */
  boolean blModeRuleConfigured;
  #endif

}Dcm_WriteMemRngInfoConfigType;
#endif
/*******************************************************************************
**       Structure for PID Packing                                            **
*******************************************************************************/
#if(DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON)
typedef struct STagDcm_PIDPackSignal
{
  uint8 ucNoOfShiftBits;

  uint8  ucStartMask;

  uint8 ucEndMask;

  uint8 ucWrFuncIndex;

  uint8 ucSignalTypeorSize;

  uint8 ucSignalStartByte;

}Dcm_PIDPackSignal;
#endif
/*******************************************************************************
**       Structure for PID Support Info                                       **
*******************************************************************************/
typedef struct STagDcmDspPidSupportInfo
{
  /* Length of the supported information in bytes */
   uint8 ucDcmDspPidSupportInfoLen;

  /* Position of the supported information in bytes */
   uint8 ucDcmDspPidSupportInfoPos;
}DcmDspPidSupportInfo;

/*******************************************************************************
**       Structure for PID DATA 01 and 02 services                            **
*******************************************************************************/
#if((DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON) || \
    (DCM_OBD_REQPOWERTRAIN_FREEZEFRAMEDATA_SERVICE == STD_ON))
typedef struct STagDcmDspPidData
{
 #if(DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON)

  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pGetPidValFnc)
  (P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA)DataValueBuffer);

   P2CONST(Dcm_PIDPackSignal, AUTOMATIC, DCM_APPL_CONST) pDcmDspPidPackSigRef;
  #endif

  P2CONST(DcmDspPidSupportInfo,AUTOMATIC, DCM_APPL_CONST)
  pDcmDspPidDataSupportInfoRef;


  #if(DCM_OBD_REQPOWERTRAIN_FREEZEFRAMEDATA_SERVICE == STD_ON)
  /* Data Element Index of PID */
  uint8 ucPIDDataElementIndex;
  #endif

  /* Length of data associated to the PID in bit */
  uint8 ucDcmDspPidDataSize;

  /*This is the position in bit of the PID structure and will not start at
  position 0 in case a support information is available */
  uint8 ucDcmDspPidDataPos;

  /* referenced Bit of the SupportInfo */
    uint8 ucDcmDspPidDataSupportInfoBit;

  #if(DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON)
   uint8 ucDcmDspPidDataUsePort;
   uint8 ucDcmPIDDataType;
  #endif
  #if((DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON) && \
  (DCM_PID_DATA_SENDER_RECEIVER == STD_ON))
  uint8 ucReadFunctionIndex;
  #endif
}Dcm_DspPidData;
#endif
/*******************************************************************************
**       Structure for PID 01 AND 02 SERVICES                                 **
*******************************************************************************/
#if((DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON) || \
    (DCM_OBD_REQPOWERTRAIN_FREEZEFRAMEDATA_SERVICE == STD_ON))
typedef struct STagDcm_PIDConfigType
{
  #if((DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON) || \
    (DCM_OBD_REQPOWERTRAIN_FREEZEFRAMEDATA_SERVICE == STD_ON))
  /* Pointer to the DcmDspPid  for a Signal in the PID */
  P2CONST(Dcm_DspPidData, AUTOMATIC, DCM_APPL_CONST) pDcmDspPidData;
  #endif

  /* 1 bytes Identifier of the PID */
  uint8 ucDcmDspPidIdentifier;

  /* Length of the PID in byte. */
  uint8 ucPidBufferSize;

  /* ucPidService */
   uint8 ucPidService;
  /* No of PID Data */
  uint8 ucNumofPIDData;

  /*  No of PID SupportInfo */
  uint8 ucNumofPIDSupportInfo;
  /* Allow to activate or deactivate the usage of a PID, */
   boolean blPIDUse;

}Dcm_PIDConfigType;
#endif

typedef struct STagDcm_PackUnpackSignalData
{
  uint32 ulSignalLength;
  uint8 ucShiftBits;
  uint8 ucStartMask;
  uint8 ucEndMask;
  uint8 ucSignalType;
  uint8 ucSignalTypeorSize;
  uint8 ucSignalSize;
  uint8 ucSignMask;
}Dcm_PackUnpackSignalData;

typedef struct STagDcm_SigRdFuncPtr
{
  /* Pointer to read function pointer. Depending upon the signal type and
  endianness, generation tool should generate the appropriate function. */
  P2FUNC(void, DCM_APPL_CODE, pRdFuncPtr)
  (Dcm_PackUnpackSignalData LddUnPackSignal,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpRequestData,
  P2VAR(void, AUTOMATIC, DCM_APPL_DATA)LpSignalDataPtr);
}Dcm_SigRdFuncPtr;


typedef struct STagDcm_SigWrFuncPtr
{
  /* Pointer to read function pointer. Depending upon the signal type and
  endianness, generation tool should generate the appropriate function. */
  P2FUNC(void, DCM_APPL_CODE, pWrFuncPtr)
  (Dcm_PackUnpackSignalData LddPackSignal,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpResponseData,
  P2CONST(void, AUTOMATIC, DCM_APPL_DATA)LpSignalDataPtr);
}Dcm_SigWrFuncPtr;


#if(((DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON) || \
   (DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON)) && \
   (DCM_DATA_SENDER_RECEIVER == STD_ON))

#if(DCM_READ_WRITE_SEND_RECV_UINT8 == STD_ON)
/* Structure for signal write function with datatype uint8*/
typedef struct STagDcm_DIDSigReadWriteUint8Function
{
  #if (DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON)
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pWriteDataUint8Func)
    (P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
  #endif

  #if (DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON)
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pReadDataUint8Func)
    (P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
  #endif

}Dcm_DIDSigReadWriteUint8Function;
#endif

#if(DCM_READ_WRITE_SEND_RECV_UINT16 == STD_ON)

/* Structure for signal write function with datatype uint8*/
typedef struct STagDcm_DIDSigReadWriteUint16Function
{
  #if(DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON)
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pWriteDataUint16Func)
    (P2CONST(uint16, AUTOMATIC, DCM_APPL_DATA) Data);
  #endif

  #if (DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON)
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pReadDataUint16Func)
    (P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) Data);
  #endif
}Dcm_DIDSigReadWriteUint16Function;
#endif

#if(DCM_READ_WRITE_SEND_RECV_UINT32 == STD_ON)
/* Structure for signal write function with datatype uint8*/
typedef struct STagDcm_DIDSigReadWriteUint32Function
{
  #if(DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON)
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pWriteDataUint32Func)
    (P2CONST(uint32, AUTOMATIC, DCM_APPL_DATA) Data);
  #endif

  #if (DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON)
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pReadDataUint32Func)
    (P2VAR(uint32, AUTOMATIC, DCM_APPL_DATA) Data);
  #endif
}Dcm_DIDSigReadWriteUint32Function;
#endif

#if(DCM_READ_WRITE_SEND_RECV_SINT8 == STD_ON)
/* Structure for signal write function with datatype uint8*/
typedef struct STagDcm_DIDSigReadWriteSint8Function
{
  #if(DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON)
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pWriteDataSint8Func)
    (P2CONST(sint8, AUTOMATIC, DCM_APPL_DATA) Data);
  #endif

  #if (DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON)    
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pReadDataSint8Func)
    (P2VAR(sint8, AUTOMATIC, DCM_APPL_DATA) Data);
  #endif
}Dcm_DIDSigReadWriteSint8Function;
#endif

#if(DCM_READ_WRITE_SEND_RECV_SINT16 == STD_ON)
/* Structure for signal write function with datatype uint8*/
typedef struct STagDcm_DIDSigReadWriteSint16Function
{
  #if(DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON)
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pWriteDataSint16Func)
    (P2CONST(sint16, AUTOMATIC, DCM_APPL_DATA) Data);
  #endif

  #if (DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON)    
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pReadDataSint16Func)
    (P2VAR(sint16, AUTOMATIC, DCM_APPL_DATA) Data);
  #endif
}Dcm_DIDSigReadWriteSint16Function;
#endif

#if(DCM_READ_WRITE_SEND_RECV_SINT32 == STD_ON)
/* Structure for signal write function with datatype uint8*/
typedef struct STagDcm_DIDSigReadWriteSint32Function
{
  #if(DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON)
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pWriteDataSint32Func)
    (P2CONST(sint32, AUTOMATIC, DCM_APPL_DATA) Data);
  #endif

  #if (DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON)      
  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pReadDataSint32Func)
    (P2VAR(sint32, AUTOMATIC, DCM_APPL_DATA) Data);
  #endif
}Dcm_DIDSigReadWriteSint32Function;
#endif

#endif

#if ((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || (DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON))
#if (DCM_USE_ECU_SIGNAL_ENABLED == STD_ON)

#if(DCM_DSP_USE_ECU_SIGNAL_UINT8 == STD_ON)
/* Structure for ECU signal read/control function with datatype uint8 */
typedef struct STagDcm_DIDEcuSignalUint8Function
{
 /* Function name to read certain ECU Signal of type uint8 */
  P2FUNC(void, DCM_APPL_CODE, pDataReadEcuSignalUint8)
    (P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) signal);

 /* Function name to control the access to a certain ECU Signal of type uint8
  * by the DCM. Only relevant if DcmDspDataUsePort==UseEcuSignal */
  P2FUNC(void, DCM_APPL_CODE, pDataControlEcuSignalUint8Fnc)
    (uint8 action, uint8 signal);

}Dcm_DIDEcuSignalUint8Function;
#endif

#if(DCM_DSP_USE_ECU_SIGNAL_UINT16 == STD_ON)
/* Structure for ECU signal read/control function with datatype uint16 */
typedef struct STagDcm_DIDEcuSignalUint16Function
{
 /* Function name to read certain ECU Signal of type uint16 */
  P2FUNC(void, DCM_APPL_CODE, pDataReadEcuSignalUint16)
    (P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) signal);

 /* Function name to control the access to a certain ECU Signal of type uint16
  * by the DCM. Only relevant if DcmDspDataUsePort==UseEcuSignal */
  P2FUNC(void, DCM_APPL_CODE, pDataControlEcuSignalUint16Fnc)
    (uint8 action, uint16 signal);

}Dcm_DIDEcuSignalUint16Function;
#endif

#if(DCM_DSP_USE_ECU_SIGNAL_UINT32 == STD_ON)
/* Structure for ECU signal read/control function with datatype uint32 */
typedef struct STagDcm_DIDEcuSignalUint32Function
{
 /* Function name to read certain ECU Signal of type uint32 */
  P2FUNC(void, DCM_APPL_CODE, pDataReadEcuSignalUint32)
    (P2VAR(uint32, AUTOMATIC, DCM_APPL_DATA) signal);

 /* Function name to control the access to a certain ECU Signal of type uint32
  * by the DCM. Only relevant if DcmDspDataUsePort==UseEcuSignal */
  P2FUNC(void, DCM_APPL_CODE, pDataControlEcuSignalUint32Fnc)
    (uint8 action, uint32 signal);

}Dcm_DIDEcuSignalUint32Function;
#endif


#if(DCM_DSP_USE_ECU_SIGNAL_SINT8 == STD_ON)
/* Structure for ECU signal read/control function with datatype sint8 */
typedef struct STagDcm_DIDSignalSint8Function
{
 /* Function name to read certain ECU Signal of type sint8 */
  P2FUNC(void, DCM_APPL_CODE, pDataReadEcuSignalSint8)
    (P2VAR(sint8, AUTOMATIC, DCM_APPL_DATA) signal);

 /* Function name to control the access to a certain ECU Signal of type sint8
  * by the DCM. Only relevant if DcmDspDataUsePort==UseEcuSignal */
  P2FUNC(void, DCM_APPL_CODE, pDataControlEcuSignalSint8Fnc)
    (uint8 action, sint8 signal);

}Dcm_DIDEcuSignalSint8Function;
#endif

#if(DCM_DSP_USE_ECU_SIGNAL_SINT16 == STD_ON)
/* Structure for ECU signal read/control function with datatype sint16 */
typedef struct STagDcm_DIDEcuSignalSint16Function
{
 /* Function name to read certain ECU Signal of type sint16 */
  P2FUNC(void, DCM_APPL_CODE, pDataReadEcuSignalSint16)
    (P2VAR(sint16, AUTOMATIC, DCM_APPL_DATA) signalSint16);

 /* Function name to control the access to a certain ECU Signal of type sint16
  * by the DCM. Only relevant if DcmDspDataUsePort==UseEcuSignal */
  P2FUNC(void, DCM_APPL_CODE, pDataControlEcuSignalSint16Fnc)
    (uint8 action, sint16 signal);

}Dcm_DIDEcuSignalSint16Function;
#endif

#if(DCM_DSP_USE_ECU_SIGNAL_SINT32 == STD_ON)
/* Structure for ECU signal read/control function with datatype sint32 */
typedef struct STagDcm_DIDEcuSignalSint32Function
{
 /* Function name to read certain ECU Signal of type sint32 */
  P2FUNC(void, DCM_APPL_CODE, pDataReadEcuSignalSint32)
    (P2VAR(sint32, AUTOMATIC, DCM_APPL_DATA) signalSint32);

 /* Function name to control the access to a certain ECU Signal of type sint32
  * by the DCM. Only relevant if DcmDspDataUsePort==UseEcuSignal */
  P2FUNC(void, DCM_APPL_CODE, pDataControlEcuSignalSint32Fnc)
    (uint8 action, sint32 signal);

}Dcm_DIDEcuSignalSint32Function;
#endif

#endif
#endif

#if(DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON)

#if(DCM_DSP_PID_UINT8 == STD_ON)
/* Structure for signal write function with datatype uint8*/
typedef struct STagDcm_PIDUint8Func
{

  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pReadWriteDataUint8Func)
    (P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);

}Dcm_PIDUint8Func;
#endif

#if(DCM_DSP_PID_UINT16 == STD_ON)

/* Structure for signal write function with datatype uint8*/
typedef struct STagDcm_PIDUint16Func
{

  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pReadWriteDataUint16Func)
    (P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) Data);

}Dcm_PIDUint16Func;
#endif

#if(DCM_DSP_PID_UINT32 == STD_ON)
/* Structure for signal write function with datatype uint8*/
typedef struct STagDcm_PIDUint32Func
{

  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pReadWriteDataUint32Func)
    (P2VAR(uint32, AUTOMATIC, DCM_APPL_DATA) Data);

}Dcm_PIDUint32Func;
#endif

#if(DCM_DSP_PID_SINT8 == STD_ON)
/* Structure for signal write function with datatype uint8*/
typedef struct STagDcm_PIDSint8Func
{

  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pReadWriteDataSint8Func)
    (P2VAR(sint8, AUTOMATIC, DCM_APPL_DATA) Data);

}Dcm_PIDSint8Func;
#endif

#if(DCM_DSP_PID_SINT16 == STD_ON)
/* Structure for signal write function with datatype uint8*/
typedef struct STagDcm_PIDSint16Func
{

  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pReadWriteDataSint16Func)
    (P2VAR(sint16, AUTOMATIC, DCM_APPL_DATA) Data);

}Dcm_PIDSint16Func;
#endif

#if(DCM_DSP_PID_SINT32 == STD_ON)
/* Structure for signal write function with datatype uint8*/
typedef struct STagDcm_PIDSint32Func
{

  P2FUNC(Std_ReturnType, DCM_APPL_CODE, pReadWriteDataSint32Func)
    (P2VAR(sint32, AUTOMATIC, DCM_APPL_DATA) Data);

}Dcm_PIDSint32Func;
#endif
#endif

/*******************************************************************************
**                        ROE Structures                                      **
*******************************************************************************/
#if (DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
typedef struct STagDcm_RoeRequestInfo
{
  PduIdType ddRoeRxPduId;
  PduIdType ddRoeTxPduId;
  /* Request data, including service identifier */
  Dcm_MsgItemType RoeReqData[DCM_ROE_MAX_REQ_DATA_LEN];
  /* Request data length (excluding service identifier) */
  Dcm_MsgLenType ddRoeReqDataLen;

  /* DID information when the sub-function is onChangeOfDataIdentifier */
  uint16 usDIDIndex;
  uint16 usDIDValue;
  /* Temporary buffer to store the DID value managed internally */
  uint16 usDIDValueSize;

  /* Rx address type */
  uint8 ucRxAddrType;
  /* numberOfIdentifiedEvents of this serviceToRespondTo */
  uint8 ucNumOfIdentifiedEvents;
  /* reqeusted event window time */
  uint8 ucEventWindowTime;
  /* event window time counter */
  uint8 ucEventWindowTimeCounter;
  /* Temporary buffer to store the DID value managed internally */
  uint8 ucInternalBuffer[DCM_ROE_BUF_SIZE];
  /* eventTypeRecord when the sub-function is onDTCStatusChange */
  uint8 ucStatusMask;
  /* byte #1 of eventTypeRecord when the sub-function is onTimerInterrupt */
  uint8 ucTimeMask;
  uint8 ucTimeMaskCounter;

  boolean blIsRoeStarted;
  boolean blIsOnDTCStsChngRxed;
  boolean blIsOnTimeInterruptRxed;
  boolean blIsOnChngOfDIDRxed;
  boolean blIsDIDManagedInternally;
  /* corresponding DID value is already read and ready to compare
  when the sub-function is onChangeOfDataIdentifier */
  boolean blDIDValueInit;
}Dcm_RoeRequestInfo;

typedef struct STagDcm_RoeRetryProcessInfo
{
  /* tx retry counter of this event */
  uint8 ucRoeTxRetryCount;
  boolean blRetryRoeEvent;
}Dcm_RoeRetryProcessInfo;

#if(DCM_ROE_QUEUE_ENABLED == STD_ON)
typedef struct STagDcm_DslRoeQueueInfo
{
  /* serviceToRespondToRecord service Id */
  Dcm_IdContextType idContext;

  /* Pointer to the ROE Queue Buffer */
  uint8 aaRoeQueueBuffer[DCM_ROE_MAX_EVENT_LENGTH];

  /* Pointer to Buffer to store ROE event length */
  uint32 ulRoeLengthInfoBuffer;

  /* serviceToRespondToRecord Buffer Index Id */
  uint8 ucSTRTId;

  /* serviceToRespondToRecord suppressed positive response bit status */
  boolean suppressPosResponse;

  /* serviceToRespondToRecord Buffer Index Id */
  boolean reqType;
}Dcm_DslRoeQueueInfo;

typedef struct STagDcm_RoeQueueProcessInfo
{
  uint8 QueueReadIndex;
  uint8 QueueWriteIndex;
  boolean blQueueElementInProcess;
  boolean blQueueEmpty;
}Dcm_RoeQueueProcessInfo;

#endif

#if(DCM_MAX_NO_OF_PRECONFIGURED_DID != DCM_ZERO)
typedef struct STagDcm_PreConfiguredRoe
{
  uint16 usDidValue;
  uint8 usRxPduIdValue;
  uint8 usEventWindowTime;
  boolean blRoeStarted;
}Dcm_PreConfiguredRoe;
#endif
#endif

/*******************************************************************************
**                        Timer Structure                                     **
*******************************************************************************/
typedef struct STagDcm_ReqTimerFlagStatusType
{
  uint8 ucRoeInterMsgTimer;
  uint8 ucP2MaxTimer;
  uint8 ucS3Timer;
  uint8 ucPagedBufferTimer;
  uint8 ucPrtclPreemptTimer;
  uint8 ucSecLevTimer;
}Dcm_ReqTimerFlagStatusType;

/*******************************************************************************
**                        Response Structure                                  **
*******************************************************************************/

typedef struct STagDcm_TxRespStatusType
{
  uint8 ucNormResponse;
  uint8 ucNegResp;
  uint8 ucRespFailed;
  uint8 ucRespPending;
  uint8 ucFirstPageTrans;
  uint8 ucPagedTrans;
  uint8 ucFailedInd;
  uint8 ucDslPagedTrans;
  uint8 ucNeedFailedConfiramtion;
} Dcm_TxRespStatusType;

/*******************************************************************************
**                        buffer and protocol Structure                       **
*******************************************************************************/

typedef struct STagDcm_PrtclTxBufStatusType
{
  uint8 ucCopyTxRejected;
  uint8 ucReportOBDDtc;
  uint8 ucPeriodicIdStatus;
  uint8 ReportNumOfDtc;
  uint8 ucBufferProvided;
  uint8 ucProtclStatus;
  uint8 ucClearDTCStatus;
  uint8 ucNumFilterDTCStatus;
} Dcm_PrtclTxBufStatusType;

/*******************************************************************************
**                        Paging Structure                                    **
*******************************************************************************/
typedef struct STagDcm_DspSerPgStatusType
{
  uint8 ucSecSeedReq;
  uint8 ucMultipleRecd;
  uint8 ucPagingInMid;
  uint8 ucFirstPage;
  uint8 ucPagingStarted;
  uint8 ucUpdatePageStarted;
  uint8 ucLastPage;
  uint8 ucDemDisableInvoked;
} Dcm_DspSerPgStatusType;

typedef struct STagDcm_ServicePendingStatusType
{
  uint8 ucIoCtrlReadCdtChkPendingStatus;
  uint8 ucReadPerDIDPendingStatus;
  uint8 ucRoutineReqFunc;
  uint8 ucRoutinePendingStatus;
  uint8 ucWriteDataByIdPendingStatus;
  uint8 ucReadDataPendingStatus;
  uint8 ucCheckReadPendingStatus;
  uint8 ucIocontrolPendingStatus;
} Dcm_ServicePendingStatusType;

typedef struct STagDcm_ServiceForcePendingStatusType
{
  uint8 ucRoutineForcePendingStatus;
  uint8 ucForcePendingStatus;
  uint8 ucWriteMemForcePendingStatus;
  uint8 ucReadMemForcePendingStatus;
  uint8 ucTransferExitForcePendingStatus;
  uint8 ucTransferDataForcePendingStatus;
  uint8 ucUlForcePendingStatus;
  uint8 ucDlForcePendingStatus;
} Dcm_ServiceForcePendingStatusType;

typedef struct STagDcm_MemServicePendingStatusType
{
  uint8 ucStartProtocolFailed;
  uint8 ucIoCtrlReadDataPendingStatus;
  uint8 ucWriteMemPendingStatus;
  uint8 ucReadMemPendingStatus;
  uint8 ucTransferExitPendingStatus;
  uint8 ucTransferDataPendingStatus;
  uint8 ucUlPendingStatus;
  uint8 ucDlPendingStatus;
} Dcm_MemServicePendingStatusType;

/* polyspace:begin<MISRA-C:18.4:Not a defect:Justify with annotations> Union used for hanlding endian conversion */
/* Define union for direct manipulation of 16 bit data */
#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
typedef union
{
  struct                                     /* Defining byte fields */
  {
    uint8 ucLsByte;                          /* Least significant byte */
    uint8 ucMsByte;                          /* Most significant byte */
  } ddByte;

  uint16 usWordReg16;                        /* 16 bit CRC field*/

}Tun_DcmWord16;

/* Define union for Big Endian */
#else

typedef union
{
  /* Structure for accessing byte fields */
  struct
  {
    uint8 ucMsByte;                          /* Most significant byte */
    uint8 ucLsByte;                          /* Least significant byte */
  } ddByte;

  uint16 usWordReg16;                        /* 16 bit field */

} Tun_DcmWord16;

#endif

/* Union for direct manipulation of 32 bit register */
#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)

typedef union                                /* Little Endian Ordering */
{
 struct
 {
   uint8 ucLsByte;                           /* Least Significant byte (0)*/
   uint8 ucMidLowByte;                       /* Byte (1)*/
   uint8 ucMidHiByte;                        /* Byte (2) */
   uint8 ucMsByte;                           /* Most Significant byte (3) */
 } ddByte;

 uint32 ulLongReg32;

} Tun_DcmDword32;

#else

typedef union                                /* Big Endian Ordering */
{
  struct
  {
    uint8 ucMsByte;                          /* Most Significant byte (3) */
    uint8 ucMidHiByte;                       /* Byte (2)*/
    uint8 ucMidLowByte;                      /* Byte (1)*/
    uint8 ucLsByte;                          /* Least Significant byte (0)*/
  } ddByte;

  uint32 ulLongReg32;

} Tun_DcmDword32;

#endif  /* (CPU_BYTE_ORDER == LOW_BYTE_FIRST) */

/* Union for 16 bit CPU byte order */
typedef union
{
  struct
  {
    uint8 BO_Byte[2];
  }byte_val;
  uint16 whole_word;
}Dcm_MIWord_Access;


/* Union for 32 bit CPU byte order */
typedef union
{
  struct
  {
    uint8 BO_Byte[4];
  }byte_val;
  uint32 whole_dword;
}Dcm_MIdWord_Access;
/* polyspace:end<MISRA-C:18.4:Not a defect:Justify with annotations> Union used for hanlding endian conversion */


typedef struct STagDcm_DspServiceProcessingStsType
{
  uint8 ucRoeStartReqRxed;
  uint8 ucRoeStoreRequest;
  uint8 ucRoeServiceRequest;
  uint8 RoutineVariableLength;
  uint8 ucRoeStorePending;
  uint8 ucReadScalingDataPending;
  uint8 ucSecSeedReqPending;
  uint8 ucSecCompareKeyReqPending;
} Dcm_DspServiceProcessingStsType;

/*******************************************************************************
**          Timing parameters valid for a diagnostic protocol                 **
*******************************************************************************/

typedef struct STagDcm_TimerServerType
{
  uint16 Timer_P2StarServerMin;
  uint16 Timer_P2StarServerMax;
  uint16 Timer_P2ServerAdjust;
  uint16 Timer_P2StrServerAdjust;
  uint16 Timer_S3Server;
  uint16 Timer_P2ServerMax;
}Dcm_TimerServerType;

/*******************************************************************************

**               Different types of timing parameters                         **
*******************************************************************************/

typedef enum
{
  /* Configured Default timing parameters */
  DCM_DEFAULT = 0,
  /* Current active timing parameters */
  DCM_CURRENT,
  /* Configured Timing parameters limits */
  DCM_LIMITS
}Dcm_TimerModeType;


typedef uint8 Dcm_BufferKindType;
#define DCM_BUFFER_KIND_TX                (0x01u)
#define DCM_BUFFER_KIND_RX                (0x02u)
#define DCM_BUFFER_KIND_TX_ROE            (0x03u)
#define  DCM_BUFFER_KIND_TX_PERIODIC       (0x04u)




/* Added by AUTRON */
#define DCM_DID_PROC_TYPE_DID         0x01
#define DCM_DID_PROC_RANGE_DIDRANGE   0x02

typedef struct STagDcm_DidStatusType {
  uint8 modeOfReadDid;
  uint8 did;
  uint8 sig;

} Dcm_DidStatusType;

typedef struct STagDcm_DidProcStateType
{
  uint16 iDidTable;
  Dcm_DidType typeOfDid;
  
  uint16 iDid;
  uint16 NumOfDid;    
  uint16 dataId;
  uint16 sizeOfSigInBytes;
  
  Dcm_DidStatusType state;


  /* signal index of DID */
  uint16 SigIndex;

  /* DIDRef of DID */
  uint16 iDidRef;  
  uint16 iDidTableRef;
  
  #if(DCM_DYNAMICALLYDEFINE_DATA_IDENTIFIER_SERVICE == STD_ON)
  uint16 iSrcDid;
  #endif

  Dcm_MsgLenType baseOfRespBuf;
  boolean atLeastOne;
  Dcm_OpStatusType ucOpStatus;
  
} Dcm_DidProcStateType;

#if(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON)
typedef struct STagDcm_PeriodicDidProcStateType
{
  uint16 iDidTable;
  uint16 iDID;      
  uint16 NumOfDid;    
  
  struct {
    uint8 sig;
    uint8 pDID;
  } state;

  /* signal index of DID */
  uint16 SigIndex;
  
  boolean atLeastOne;
} Dcm_PeriodicDidProcStateType;
#endif

#if(DCM_DSP_SECURITY_SERVICE == STD_ON)
typedef struct STagDcm_SecurityAccessStateType {
  uint8 sa_Static_Seed;
  uint8 sa_Att_Cnt;
  uint8 sa_SecurityLevel;
  uint8 sa_CfgIndex;  
  boolean sa_RequestSeedFinished;
} Dcm_SecurityAccessStateType;
#endif


/*******************************************************************************
**                          Session Check definition                          **
*******************************************************************************/
#define CHECK_DEFAULT_SESSION(LucSession) ((DCM_DEFAULT_SESSION) == (LucSession))

#define CHECK_NONDEFAULT_SESSION(LucSession) ((DCM_DEFAULT_SESSION) != (LucSession))


/*******************************************************************************
**              Start timer definition for Diagnostic layer timers            **
*******************************************************************************/
#define DCM_START_TIMER(LucTimerName, LusTimerValue) \
  do{Dcm_GaaTimer[(LucTimerName)] = (LusTimerValue)/Dcm_Task_Time;} while(0)

/*******************************************************************************
**              Stop timer definition for Diagnostic layer timers             **
*******************************************************************************/
#define DCM_STOP_TIMER(LucTimerName) \
  do{Dcm_GaaTimer[(LucTimerName)] = DCM_ZERO;} while(0)

/*******************************************************************************
**           GLOBAL DECLARATIONS                                              **
*******************************************************************************/

#if (DCM_READDTC_SUPPORT == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Function pointer declaration for ReadDtc subfunctions implementation */
extern CONST(Dcm_CbkFuncPtrType, DCM_CONST) Dcm_GaaDspReadDTCFctPtr[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#define DCM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for RxTxPduId configuration */
extern VAR(Dcm_PduIdTable, DCM_VAR) Dcm_GaaPduIdTableConfig[];
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for protocol configuration */
extern CONST(Dcm_ProtocolConfig, DCM_CONST) Dcm_GaaProtocolConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for buffer configuration */
extern CONST(Dcm_BufferConfig, DCM_CONST) Dcm_GaaBufferConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for ServiceId configuration */
extern CONST(Dcm_ServiceIdConfigType, DCM_CONST) Dcm_GaaSIdConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (DCM_OBD_REQVEHICLE_INFO_SERVICE == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for the VehicleInfo configuration */
extern CONST(Dcm_VehInfoConfigType, DCM_CONST) Dcm_GaaVehInfoConfig[];

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_VehInfoData, DCM_CONST) Dcm_GaaVehInfoData[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if((DCM_COMMUNICATION_CONTROL_SERVICE == STD_ON) || \
    (DCM_ENABLE_NORMAL_MSG_TRANSMISSION_SERVICE == STD_ON))
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*  Number Of Communication Channel Configure*/
extern CONST(Dcm_CommControlConfigType, DCM_CONST) Dcm_GaaCommControlConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_AllCommControlConfig, DCM_CONST) Dcm_GaaAllCommControlConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if ((DCM_PROTOCOL_TRANSTYPE2 == STD_ON) && \
(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON))
#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/*  Number Of Periodic Connection*/
extern VAR(Dcm_DslPeriodicTxId, DCM_VAR) Dcm_GaaDcmDslPeriodicTxId[];
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
extern VAR(Dcm_DslPeriodicTxBuf,  DCM_APPL_DATA)
Dcm_GaaDslPeriodicData[];
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#if ((DCM_PROTOCOL_TRANSTYPE2 == STD_ON) && \
(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON))
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_DslRoeTrans, DCM_CONST) Dcm_GaaDcmDslRoeTxId[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif


#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for Security level configuration */
extern CONST(Dcm_SecurityLevConfigType, DCM_CONST) Dcm_GaaSecurityLevConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
 /* Array of structures for Diagnostic session service */
extern CONST(Dcm_DiagSessionConfigType, DCM_CONST) Dcm_GaaDiagSessionConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_8
#include "MemMap.h"
/*
 * This array contains the index of the function pointer array of Dsp internal
 * functions for subfunctions of ReadDtcInformation service
 */
extern CONST(uint8, DCM_CONST) Dcm_GaaSIdTABConfig[];
#define DCM_STOP_SEC_CONST_8
#include "MemMap.h"

#define DCM_START_SEC_CONST_8
#include "MemMap.h"
/* Array of index for the OBD ServiceIds Configured */
extern CONST(uint8, DCM_CONST) Dcm_GaaOBDSIdTABConfig[];
#define DCM_STOP_SEC_CONST_8
#include "MemMap.h"

#define DCM_START_SEC_CONST_8
#include "MemMap.h"
/* Array of Sessions supported for the ServiceId */
extern CONST(uint8, DCM_CONST) Dcm_GaaSessionsToSId[];
#define DCM_STOP_SEC_CONST_8
#include "MemMap.h"

#if (DCM_NUM_OF_SECURITYLEVELSTOSID > 0)
#define DCM_START_SEC_CONST_8
#include "MemMap.h"
/* Array of Security levels supported for ServiceId */
extern CONST(uint8, DCM_CONST) Dcm_GaaSecuritylevelsToSId[];
#define DCM_STOP_SEC_CONST_8
#include "MemMap.h"
#endif

#if(DCM_OBD_REQ_ONBOARD_MONITORRESULT_SERVICE == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for OBDMID service configuration */
extern CONST(Dcm_OBDMidConfigType, DCM_CONST) Dcm_GaaOBDMidConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_OBDMidTids, DCM_CONST) Dcm_GaaObdMidTids[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#endif

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of CallBackDCMRequestServices */
extern CONST(Dcm_CbkReqServicesConfigType, DCM_CONST)
  Dcm_GaaCbkReqServices[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (DCM_REQUEST_MANUFACTURER_INDICATION_ENABLED == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of Manufacturer Indication */
extern CONST(Dcm_SerReqManuIndConfigType, DCM_CONST)
  Dcm_GaaManuIndConfigType[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if (DCM_REQUEST_SUPPLIER_INDICATION_ENABLED == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of Supplier Indication */
extern CONST(Dcm_SerReqSuppIndConfigType, DCM_CONST)
  Dcm_GaaSuppIndConfigType[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if (DCM_OBD_REQ_CTLRL_ONBOADSYSTEM_SERVICE == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for RequestControl Service for TIDS */
extern CONST(Dcm_RequestControlConfigType, DCM_CONST)
    Dcm_GaaRequestControlConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if((DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON) || \
(DCM_OBD_REQPOWERTRAIN_FREEZEFRAMEDATA_SERVICE == STD_ON))
#define DCM_START_SEC_CONST_8
#include "MemMap.h"
/* To hold the configured PIDs */
extern CONST(uint8, DCM_CONST) Dcm_GaaPIDs[];
#define DCM_STOP_SEC_CONST_8
#include "MemMap.h"
#endif

#if(DCM_OBD_REQ_ONBOARD_MONITORRESULT_SERVICE == STD_ON)
#define DCM_START_SEC_CONST_8
#include "MemMap.h"
/* To hold the configured OBDMIDs */
extern CONST(uint8, DCM_CONST) Dcm_GaaOBDMIDs[];
#define DCM_STOP_SEC_CONST_8
#include "MemMap.h"
#endif

#if(DCM_OBD_REQ_CTLRL_ONBOADSYSTEM_SERVICE == STD_ON)
#define DCM_START_SEC_CONST_8
#include "MemMap.h"
/* To hold the configured TIDs */
extern CONST(uint8, DCM_CONST) Dcm_GaaTIDs[];
#define DCM_STOP_SEC_CONST_8
#include "MemMap.h"
#endif

#if(DCM_OBD_REQVEHICLE_INFO_SERVICE == STD_ON)
#define DCM_START_SEC_CONST_8
#include "MemMap.h"
/* To hold the configured InfoTypeId */
extern CONST(uint8, DCM_CONST) Dcm_GaaVIDs[];
#define DCM_STOP_SEC_CONST_8
#include "MemMap.h"
#endif

#if(DCM_ROUTINECONTROL_SERVICE == STD_ON)
#define DCM_START_SEC_CONST_16
#include "MemMap.h"
/* To hold the configured RoutineId */
extern CONST(uint16, DCM_CONST) Dcm_GaaRtnIdentifier[];
#define DCM_STOP_SEC_CONST_16
#include "MemMap.h"

#define DCM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for RouitneControl configuration */
extern VAR(Dcm_RoutineConfigType, DCM_VAR)
  Dcm_GaaRoutineControlConfig[];
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for RouitneSignal Info configuration */
extern CONST(Dcm_RoutineSignalInfoType, DCM_CONST)
  Dcm_GaaRoutineSignalInfo[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if(DCM_ROUTINE_REQUEST_OUTSIGNAL_CONFIGURED == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for RequestResOutSignalType configuration */
extern CONST(Dcm_RequestResOutSignalType, DCM_CONST)
Dcm_GaaRequestResOutSignalType[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_ROUTINE_START_INSIGNAL_CONFIGURED == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for StartRoutineInSignalType configuration */
extern CONST(Dcm_StartRoutineInSignalType, DCM_CONST)
  Dcm_GaaStartRoutineInSignal[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_ROUTINE_START_OUTSIGNAL_CONFIGURED == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for StartRoutineOutSignalType configuration */
extern CONST(Dcm_StartRoutineOutSignalType, DCM_CONST)
  Dcm_GaaStartRoutineOutSignal[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_ROUTINE_STOP_INSIGNAL_CONFIGURED == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for StopRoutineInSignalType configuration */
extern CONST(Dcm_StopRoutineInSignalType, DCM_CONST)
  Dcm_GaaStopRoutineInSignal[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_ROUTINE_STOP_OUTSIGNAL_CONFIGURED == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for StopRoutineOutSignalType configuration */
extern CONST(Dcm_StopRoutineOutSignalType, DCM_CONST)
  Dcm_GaaStopRoutineOutSignal[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif
#endif

#if ((DCM_READ_MEMORY_BY_ADDRESS_SERVICE == STD_ON) || \
  (DCM_DYNAMICALLYDEFINE_DATA_IDENTIFIER_SERVICE == STD_ON))
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for read memory by address configuration */
extern CONST(Dcm_ReadMemRngInfoConfigType, DCM_CONST)
  Dcm_GaaReadMemRngConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if ((DCM_WRITE_MEMORY_BY_ADDRESS_SERVICE == STD_ON) || \
    (DCM_TRANSFER_DATA_SERVICE == STD_ON))
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for read memory by address configuration */
extern CONST(Dcm_WriteMemRngInfoConfigType, DCM_CONST)
  Dcm_GaaWriteMemRngConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for supported PIDs List for $01*/
extern CONST(Dcm_IDEncodeByteConfig, DCM_CONST) Dcm_GaaPIDEncodeByte1[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for supported PIDs List */
extern CONST(Dcm_IDEncodeByteConfig, DCM_CONST) Dcm_GaaPIDEncodeByte[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for supported OBDMIDs List */
extern CONST(Dcm_IDEncodeByteConfig, DCM_CONST) Dcm_GaaOBDMIDEncodeByte[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for supported TIDs List */
extern CONST(Dcm_IDEncodeByteConfig, DCM_CONST) Dcm_GaaTIDEncodeByte[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for supported InfoTypes List */
extern CONST(Dcm_IDEncodeByteConfig, DCM_CONST)
  Dcm_GaaVIDEncodeByte[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_16
#include "MemMap.h"
/* Array of did ref */
extern CONST(uint16, DCM_CONST) Dcm_GaaDidRefToDid[];
#define DCM_STOP_SEC_CONST_16
#include "MemMap.h"

#define DCM_START_SEC_CONST_8
#include "MemMap.h"
/* Array of protocol ID */
extern CONST(uint8, DCM_CONST) Dcm_GaaProtocolIds[];
#define DCM_STOP_SEC_CONST_8
#include "MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of protocol ID */
extern CONSTP2CONST (uint8, AUTOMATIC, DCM_CONST)Dcm_GpOBDBaseAddress[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of array of DID, RID */
extern CONSTP2CONST (uint16, AUTOMATIC, DCM_CONST)Dcm_GpUDSBaseAddress[DCM_TWO];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"



#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern P2CONST(Dcm_IDEncodeByteConfig, AUTOMATIC, DCM_APPL_CONST)
Dcm_GpEncodeByte[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_8
#include "MemMap.h"
extern CONST(uint8, DCM_CONST) Dcm_GaaAvailConfigID[];
#define DCM_STOP_SEC_CONST_8
#include "MemMap.h"

#define DCM_START_SEC_CONST_8
#include "MemMap.h"
extern CONST(uint8, DCM_CONST) Dcm_GaaProtocol_OBD_SID[];
#define DCM_STOP_SEC_CONST_8
#include "MemMap.h"

#if (DCM_NUM_OF_SUBSERVICEIDCONFIG > 0)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for Sub Service ID configuration */
extern CONST(Dcm_SubServiceIdConfigType, DCM_CONST)Dcm_GaaSubServiceIdConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_MODE_CONDITION == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_ModeConditionConfigType, DCM_CONST)
  Dcm_GaaModeConditionConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_8
#include "MemMap.h"
extern CONST(uint8, DCM_CONST) Dcm_GaaModeConditionIndexArray[];
#define DCM_STOP_SEC_CONST_8
#include "MemMap.h"
#endif

#if(DCM_MODE_RULE == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_ModeRuleConfigType, DCM_CONST)Dcm_GaaModeRuleConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_8
#include "MemMap.h"
extern CONST(uint8, DCM_CONST) Dcm_GaaModeRuleIndexArray[];
#define DCM_STOP_SEC_CONST_8
#include "MemMap.h"
#endif

#if(DCM_DIDSERVICE_SUPPORT_ENABLE == STD_ON)

#if(DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for DidInfo DIDWrite configured for DIDs */
extern CONST(Dcm_DIDInfoTypeDidWrite, DCM_CONST)
  Dcm_GaaDIDInfoTypeDidWriteConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

  #if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || \
  (DCM_DYNAMICALLYDEFINE_DATA_IDENTIFIER_SERVICE == STD_ON) || \
  (DCM_READ_SCALINGDATA_BYIDENTIFIER_SERVICE == STD_ON) ||\
  (DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON))
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for DidInfo DIDRead configured for DIDs */
extern CONST(Dcm_DIDInfoTypeDidRead, DCM_CONST)
  Dcm_GaaDIDInfoTypeDidReadConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for DidInfo DIDControl configuration */
extern CONST(Dcm_DIDInfoTypeDidCtrl, DCM_CONST)
  Dcm_GaaDIDInfoTypeDidCtrlConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#define DCM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for Data configuration */
extern VAR(Dcm_DIDRangeConfig, DCM_VAR) Dcm_GaaDcmDspDIDRangeConfig[];
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#if((DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON) ||\
  (DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON))
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_DIDUnPackSignal, DCM_CONST) Dcm_GaaDIDUnPackSignal[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif
#if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) ||\
  (DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON))

#if (DCM_NUM_OF_GAADIDPACKSIGNAL != 0U)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_DIDPackSignal, DCM_CONST) Dcm_GaaDIDPackSignal[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#endif

#if (DCM_NUM_OF_GAADATAINFOTYPECONFIG != 0U)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for Data info configuration */
extern CONST(Dcm_DataInfoType, DCM_CONST) Dcm_GaaDataInfoTypeConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if (DCM_NUM_OF_GAADCMDSPDATACONFIG != 0u)
#define DCM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for Data configuration */
extern CONST(Dcm_DcmDspDataconfig, DCM_CONST) Dcm_GaaDcmDspDataConfig[];
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#endif


#if (DCM_NUM_OF_GAADCMDSPSIGNALCONFIG != 0U)
#define DCM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for Data configuration */
extern VAR(Dcm_DcmDspSignalconfig, DCM_VAR) Dcm_GaaDcmDspSignalConfig[];
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#endif

#define DCM_START_SEC_CONST_16
#include "MemMap.h"
/* Array of structures for Data configuration */
extern CONST(uint16, DCM_CONST) Dcm_GusPreconfigureDidList[];
#define DCM_STOP_SEC_CONST_16
#include "MemMap.h"

#if (DCM_NUM_OF_DIDPARACONFIG != 0U)
#define DCM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for DID Parameter configuration */
extern CONST(Dcm_DIDParaConfig, DCM_CONST) Dcm_GaaDIDParaConfig[];
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#endif

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of structures for DID Parameter configuration */
extern CONST(Dcm_DIDInfoType, DCM_CONST) Dcm_GaaDIDInfoTypeConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_16
#include "MemMap.h"
/* To hold the configured DIDs */
extern CONST(uint16, DCM_CONST) Dcm_GaaDidIdentifier[];
#define DCM_STOP_SEC_CONST_16
#include "MemMap.h"
#endif

#if((DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON) || \
    (DCM_OBD_REQPOWERTRAIN_FREEZEFRAMEDATA_SERVICE == STD_ON))
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_PIDConfigType, DCM_CONST) Dcm_GaaPIDConfig[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_DspPidData, DCM_CONST) Dcm_GaaDcmDspPidData[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if(DCM_OBD_PID_SUPPORT_INFO == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(DcmDspPidSupportInfo, DCM_CONST) Dcm_GaaDcmDspPidSupportInfo[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif
#endif

#if(DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_PIDPackSignal, DCM_CONST) Dcm_GaaPIDPackSignal[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if (DCM_TOTAL_NUM_OF_DYM_DID != 0U)
#define DCM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/* Structure for Dym DID info defined by identifier */
extern VAR(Dcm_DymDefinedDIDInfoType, DCM_VAR)
Dcm_GaaDymDefinedDIDInfoType[];
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#endif


#if (DCM_TOTAL_NUM_OF_DYM_DID != 0U)
#define DCM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/* Structure for Dym DID info defined by memory Address */
extern VAR(Dcm_DymMemDIDInfoType, DCM_VAR)
Dcm_GaaDymMemDIDInfoType[];
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#endif

#define DCM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/* Structure for Static DID info  */
extern VAR(Dcm_SrcIDInfoType, DCM_VAR)
Dcm_GaaSrcDIDInfoTypeConfig[];
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/* Structure for Memory Address info */
extern VAR(Dcm_MemAddInfoType, DCM_VAR)
Dcm_GaaMemAddInfoTypeConfig[];
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
/* Array for RxPduId status */
extern VAR(uint8, DCM_VAR) Dcm_GaaRxStatus[];
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
/* Array for Protocol status */
extern VAR(uint8, DCM_VAR) Dcm_GaaProtclStatus[];
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
/* Array for configured RAM buffer area */
extern VAR(uint8, DCM_VAR) Dcm_GaaBufferArea[];
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#if(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON)
#define DCM_START_SEC_CONST_16
#include "MemMap.h"
extern CONST(uint16, DCM_CONST) Dcm_GaaPeriodicTime[];
#define DCM_STOP_SEC_CONST_16
#include "MemMap.h"

#if (DCM_PROTOCOL_TRANSTYPE2 == STD_ON) 
#if (DCM_DSP_MAX_PERIODIC_DID_SCHEDULED != 0U)
#define DCM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
extern VAR(uint8, DCM_APPL_DATA) Dcm_GaaPerodicBuffer[];
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"
#endif
#endif

#endif

#if( DCM_ROUTINECONTROL_SERVICE == STD_ON)
#define DCM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
extern VAR(uint8, DCM_VAR) Dcm_GaaRoutineSignalInData[];
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
extern VAR(uint8, DCM_VAR) Dcm_GaaRoutineSignalOutData[];
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_16
#include "MemMap.h"

/* Array for Out Signal */
extern VAR(uint16, DCM_VAR) Dcm_GaaRoutineSignalOutData16[];
#define DCM_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_32
#include "MemMap.h"

/* Array for Out Signal */
extern VAR(uint32, DCM_VAR) Dcm_GaaRoutineSignalOutData32[];
#define DCM_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

#endif

#if(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON)
#define DCM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
extern VAR(uint8, DCM_VAR) Dcm_GaaPeriodicStatus[];
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"
#endif

#if((DCM_ROUTINECONTROL_SERVICE == STD_ON) || \
(DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON) || \
(DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON))

#if (DCM_NUM_OF_GAASIGRDFUNCPTR != 0U)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_SigRdFuncPtr,DCM_CONST) Dcm_GaaSigRdFuncPtr[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#define DCM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
extern VAR(uint8, DCM_APPL_DATA) Dcm_GaaDIDSignalData[];
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#if(DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON)
#define DCM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
extern VAR(uint8, DCM_VAR) Dcm_GaaDIDSignalOutData[];
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"
#endif

#endif

#if((DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON) || \
(DCM_ROUTINECONTROL_SERVICE == STD_ON) || \
(DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || \
(DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON))

#if (DCM_NUM_OF_GAASIGWRFUNCPTR != 0U)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_SigWrFuncPtr,DCM_CONST) Dcm_GaaSigWrFuncPtr[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#endif

#if((DCM_READ_MEMORY_BY_ADDRESS_SERVICE == STD_ON) || \
 (DCM_WRITE_MEMORY_BY_ADDRESS_SERVICE == STD_ON) || \
  (DCM_REQUEST_UPLOAD_SERVICE == STD_ON) || \
  (DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON) || \
  (DCM_DYNAMICALLYDEFINE_DATA_IDENTIFIER_SERVICE == STD_ON))

#if (DCM_NUM_OF_ADDRESS_LENGTH_FORMAT_ID_CONFIG != 0U)
#define DCM_START_SEC_CONST_8
#include "MemMap.h"
/* Array of protocol ID */
extern CONST(uint8, DCM_CONST) Dcm_GaaAddressAndLengthFormatIds[];
#define DCM_STOP_SEC_CONST_8
#include "MemMap.h"
#endif

#endif

#if(((DCM_WRITEDATA_BYIDENTIFIER_SERVICE == STD_ON) || \
   (DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON)) && \
   (DCM_DATA_SENDER_RECEIVER == STD_ON))

#if(DCM_READ_WRITE_SEND_RECV_UINT8 == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_DIDSigReadWriteUint8Function, DCM_CONST)
  Dcm_GaaSigReadWriteUint8Func[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_READ_WRITE_SEND_RECV_UINT16 == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_DIDSigReadWriteUint16Function, DCM_CONST)
  Dcm_GaaSigReadWriteUint16Func[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_READ_WRITE_SEND_RECV_UINT32 == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_DIDSigReadWriteUint32Function, DCM_CONST)
  Dcm_GaaSigReadWriteUint32Func[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_READ_WRITE_SEND_RECV_SINT8 == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_DIDSigReadWriteSint8Function, DCM_CONST)
  Dcm_GaaSigReadWriteSint8Func[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_READ_WRITE_SEND_RECV_SINT16 == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_DIDSigReadWriteSint16Function, DCM_CONST)
  Dcm_GaaSigReadWriteSint16Func[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_READ_WRITE_SEND_RECV_SINT32 == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_DIDSigReadWriteSint32Function, DCM_CONST)
  Dcm_GaaSigReadWriteSint32Func[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#endif


#if((DCM_READ_DATA_BYIDENTIFIER_SERVICE == STD_ON) || \
    ((DCM_IOCONTROL_BYIDENTIFIER_SERVICE == STD_ON) && (DCM_USE_ECU_SIGNAL_ENABLED == STD_ON)))

#if(DCM_DSP_USE_ECU_SIGNAL_UINT8 == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_DIDEcuSignalUint8Function, DCM_CONST)
  Dcm_GaaEcuSignalUint8Func[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_DSP_USE_ECU_SIGNAL_UINT16 == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_DIDEcuSignalUint16Function, DCM_CONST)
  Dcm_GaaEcuSignalUint16Func[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_DSP_USE_ECU_SIGNAL_UINT32 == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_DIDEcuSignalUint32Function, DCM_CONST)
  Dcm_GaaEcuSignalUint32Func[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_DSP_USE_ECU_SIGNAL_SINT8 == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_DIDEcuSignalSint8Function, DCM_CONST)
  Dcm_GaaEcuSignalSint8Func[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_DSP_USE_ECU_SIGNAL_SINT16 == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_DIDEcuSignalSint16Function, DCM_CONST)
  Dcm_GaaEcuSignalSint16Func[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_DSP_USE_ECU_SIGNAL_SINT32 == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_DIDEcuSignalSint32Function, DCM_CONST)
  Dcm_GaaEcuSignalSint32Func[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#endif

#if((DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON))

#if(DCM_DSP_PID_UINT8 == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_PIDUint8Func, DCM_CONST) Dcm_GaaPIDUint8Func[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_DSP_PID_UINT16 == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_PIDUint16Func, DCM_CONST) Dcm_GaaPIDUint16Func[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_DSP_PID_UINT32 == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_PIDUint32Func, DCM_CONST) Dcm_GaaPIDUint32Func[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_DSP_PID_SINT8 == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_PIDSint8Func, DCM_CONST) Dcm_GaaPIDSint8Func[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_DSP_PID_SINT16 == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_PIDSint16Func, DCM_CONST) Dcm_GaaPIDSint16Func[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_DSP_PID_SINT32 == STD_ON)
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Dcm_PIDSint32Func, DCM_CONST) Dcm_GaaPIDSint32Func[];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#endif


#if (DCM_DEV_ERROR_DETECT == STD_ON)
#define DCM_REPORT_ERROR(sid, type)               do{(void)Det_ReportError(DCM_MODULE_ID, DCM_INSTANCE_ID,(sid),(type));} while(0)
#else
#define DCM_REPORT_ERROR(sid, type)               do{}while(0)
#endif


#define iRetDidTable(val) \
do {Dcm_ServicePendingStatus.ucReadDataPendingStatus =  (val);} while(0)

#define DCM_SET_RDATA_PENDING_STATUS(s)\
do {\
  Dcm_ServicePendingStatus.ucReadDataPendingStatus = (s);\
} while(0)

#define DCM_IS_PDID_RUNNING ((Dcm_GblResOnPeriodicIdStatus == DCM_TRUE) &&\
  (Dcm_GucPeriodicSID == DCM_READDATABYPERIODICIDENTIFIER))

/* ((uint16_t)((uint16_t)port << 4) & mode) >> 6; compliant  */
/* uint16, uint8 array, uint16 */
#define DCM_GET_DATAID_FROM_REQUEST(lvalue, rvalue, pos) \
do {\
  (lvalue) = (uint16)(rvalue)[(pos)];\
  (lvalue) = (uint16)((lvalue) << 8U);\
  (lvalue) = (lvalue) | (uint16)(rvalue)[(pos) + 1U];\
} while(0)

/* uint8, uint16, uint16 */
#define DCM_SET_DATAID_IN_RESPONSE(buf,pos,did) \
do {\
  if((Dcm_GblResOnPeriodicIdStatus == DCM_TRUE) &&\
    (Dcm_GucPeriodicSID == DCM_READDATABYPERIODICIDENTIFIER))\
  {\
    (buf)[(pos)] = DCM_U16_LO_BYTE((did));\
    (pos) += 1;\
  }\
  else\
  {\
    (buf)[(pos) + 0U] = DCM_U16_HI_BYTE((did));\
    (buf)[(pos) + 1U] = DCM_U16_LO_BYTE((did));\
    (pos) += DCM_SIZEOF_DATAID;\
  }\
} while(0)

#define DCM_CLR_PERIODIC_PDU_STATUS(PDU)  (*((PDU)->pPerPduIdStatus) &= ~((PDU)->ucPerPduIdStatusMask))
#define DCM_SET_PERIODIC_PDU_STATUS(PDU)  (*((PDU)->pPerPduIdStatus) |=  ((PDU)->ucPerPduIdStatusMask))

#define DCM_CLR_PDU_STATUS(PDU)  (*((PDU)->pPduIdStatus) &= (uint8)(~((PDU)->ucPduIdStatusMask)))
#define DCM_SET_PDU_STATUS(PDU)  (*((PDU)->pPduIdStatus) |=  ((PDU)->ucPduIdStatusMask))

#define DCM_IS_SET_PDU_STATUS(PDU) \
  (((*((PDU)->pPduIdStatus)) & ((PDU)->ucPduIdStatusMask)) == ((PDU)->ucPduIdStatusMask))

#define DCM_CLR_PROTOCOL_STATUS(PRT)  (*((PRT)->pProtocolStatus) &= (uint8)(~((PRT)->ucPrtclStatusMask)))
#define DCM_SET_PROTOCOL_STATUS(PRT)  (*((PRT)->pProtocolStatus) |=  ((PRT)->ucPrtclStatusMask))
#define DCM_IS_SET_PROTOCOL_STATUS(PRT) \
  (((*((PRT)->pProtocolStatus)) & ((PRT)->ucPrtclStatusMask)) == ((PRT)->ucPrtclStatusMask))


#if((DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON) && (DCM_PROTOCOL_TRANSTYPE2 == STD_OFF))
#define DCM_RES_ON_PERIODICIDSTATUS_EQ_TRUE (Dcm_GblResOnPeriodicIdStatus == DCM_TRUE)
#else
#define DCM_RES_ON_PERIODICIDSTATUS_EQ_TRUE (DCM_FALSE)
#endif

#if(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
#define DCM_RES_ON_EVENTSTATUS_EQ_DCM_ROEONGOING  (Dcm_GucResOnEventStatus == DCM_ROEONGOING)
#else
#define DCM_RES_ON_EVENTSTATUS_EQ_DCM_ROEONGOING  (DCM_FALSE)
#endif 


#if ((DCM_DSP_DIAG_SESSION_SERVICE == STD_ON) || (DCM_DSP_STOP_DIAG_SESSION_SERVICE== STD_ON))
typedef struct STagDcm_DiagSessionStateType
{
  VAR(uint8, DCM_VAR) sessionTableIndex;
  VAR(boolean, DCM_VAR) sendPendingResp;
} Dcm_DiagSessionStateType;
#endif


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/* polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations> Not a defect */
/* polyspace:end<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */

#endif

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
