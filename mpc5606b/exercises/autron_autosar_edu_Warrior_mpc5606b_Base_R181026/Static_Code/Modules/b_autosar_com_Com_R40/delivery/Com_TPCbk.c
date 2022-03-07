/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Com_TPCbk.c                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Com Module                                            **
**                                                                            **
**  PURPOSE   : Provision of TP callback functions and their functionality.   **
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
** 2.2.3     08-Dec-2017   Chan Kim    Internal Redmine #10849, #10851        **
** 2.2.1     24-Aug-2017   Chan Kim    Internal Redmine #9652, #9657          **
** 2.2.0     16-Apr-2017   Chan Kim    Internal Redmine #7861, #7707, #7525   **
** 2.1.9     20-Mar-2017   Chan Kim    Internal Redmine #7851                 **
** 2.1.7     30-Nov-2016   Chan Kim    Internal Redmine #6806, #6807          **
** 2.1.0     25-May-2016   Chan Kim    Internal Redmine #4998                 **
** 2.0.13    13-May-2016   Chan Kim    Internal Redmine #3959                 **
** 2.0.8     12-Feb-2016   Chan Kim    Internal Redmine #4138, #4158          **
** 2.0.3     24-Nov-2015   Chan Kim    Internal Redmine #3544, #3535          **
** 2.0.2     19-Sep-2015   Chan Kim    Internal Redmine #3182                 **
** 1.0.16    27-Feb-2015   Chan Kim    Internal Redmine #2202                 **
** 1.0.15    09-Feb-2015   Chan Kim    Internal Redmine #2142                 **
** 1.0.14    03-Nov-2014   Chan Kim    Internal Redmine #1463                 **
** 1.0.12    26-May-2014   Chan Kim    Internal Redmine #818                  **
** 1.0.11    20-Mar-2014   Chan Kim    Internal Redmine #695                  **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Com.h"          /* Com header file */
#include "Com_Cbk.h"      /* Com Cbk header file */
#include "Com_Main.h"     /* Com Main header file */
#include "SchM_Com.h"     /* SchM Com header file */
#include "Com_Error.h"    /* Com Error header file */
#if(COM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"          /* Det header file */
#endif
#include "string.h"       /* memcpy() */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version Information */
#define COM_TP_CBK_C_AR_RELEASE_MAJOR_VERSION       4
#define COM_TP_CBK_C_AR_RELEASE_MINOR_VERSION       0
#define COM_TP_CBK_C_AR_RELEASE_REVISION_VERSION    3

/* Software version information */
#define COM_TP_CBK_C_SW_MAJOR_VERSION  2
#define COM_TP_CBK_C_SW_MINOR_VERSION  2

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if(COM_AR_RELEASE_MAJOR_VERSION != COM_TP_CBK_C_AR_RELEASE_MAJOR_VERSION)
  #error "Com_TPCbk.c : Mismatch in Com Specification Major Version"
#endif

#if(COM_AR_RELEASE_MINOR_VERSION != COM_TP_CBK_C_AR_RELEASE_MINOR_VERSION)
  #error "Com_TPCbk.c : Mismatch in Com Specification Minor Version"
#endif

#if(COM_AR_RELEASE_REVISION_VERSION != \
  COM_TP_CBK_C_AR_RELEASE_REVISION_VERSION)
  #error "Com_TPCbk.c : Mismatch in Com Specification Revision Version"
#endif

#if(COM_SW_MAJOR_VERSION != COM_TP_CBK_C_SW_MAJOR_VERSION)
  #error "Com_TPCbk.c : Mismatch in Com Software Major Version"
#endif

#if(COM_SW_MINOR_VERSION != COM_TP_CBK_C_SW_MINOR_VERSION)
  #error "Com_TPCbk.c : Mismatch in Com Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/* polyspace:begin<RTE: NIV : Not a defect : No Action Planned > initialized variable */
/* polyspace:begin<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:begin<RTE: OBAI : Not a defect : No Action Planned > configured memory access index */
/* polyspace:begin<RTE: STD_LIB : Not a defect : No Action Planned> configured & generated memory address */

/*******************************************************************************
** Function Name        : Com_StartOfReception                                **
**                                                                            **
** Service ID           : 0x25                                                **
**                                                                            **
** Description          : This function returns the pointer to the size of    **
**                        the AUTOSAR COM module’s internal receive buffer    **
**                        for the I-PDU with the ID ComRxPduId.               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same PDU-ID.                  **
**                        Reentrant for different PDU-ID.                     **
**                                                                            **
** Input Parameters     : ComRxPduId, TpSduLength                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : RxBufferSizePtr                                     **
**                                                                            **
** Return parameter     : BufReq_ReturnType                                   **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GddComStatus           **
**                                                 Com_GaaRxIpduStatus        **
**                                                 Com_GaaRxIpdu              **
**                                                 Com_GaaRxTPIpdu            **
**                                                 Com_GaaRxTPStatus          **
**                                                 Com_GaaRxPduInfoPtr        **
**                        Function(s) invoked    : Det_ReportError()          **
*******************************************************************************/
#if(COM_RX_TP_SUPPORT == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(BufReq_ReturnType, COM_CODE) Com_StartOfReception(PduIdType 
  ComRxPduId, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, 
  COM_VAR) RxBufferSizePtr)
{
  /* Pointer to Ipdu Buffer */
  P2CONST(Com_RxPduInfoType, AUTOMATIC, COM_CONST) LpPduInfoPtr;
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu;
  /* Pointer to Rx TP structure */
  P2CONST(Com_RxTPIpdu, AUTOMATIC, COM_CONST) LpRxTPIpdu;
  /* Return value */
  BufReq_ReturnType LddReturnValue;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  uint8 LucReturnValue;
  #endif  

  /* Initialize return value */
  LddReturnValue = BUFREQ_OK;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Initialize DET error flag to E_OK */
  LucReturnValue = (uint8)E_OK;  
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_STARTOFRECEPTION);
  /* Check whether Ipdu ID is out of range */
  COM_DET_RXPDUID_RANGE_CHECK_FLAG(ComRxPduId, COMSERVICEID_STARTOFRECEPTION);
  /* Check whether input buffer is NULL  */
  COM_DET_COMMON_PTR_CHECK_FLAG(RxBufferSizePtr, COMSERVICEID_STARTOFRECEPTION);
  if(LucReturnValue != (uint8)E_OK)
  {
    LddReturnValue = BUFREQ_E_NOT_OK;
  }
  if(LucReturnValue == (uint8)E_OK)
  #endif
  {
    if(Com_GaaRxIpduStatus[ComRxPduId] != (PduIdType)COM_ZERO)
    {
      /* Get the pointer to  Rx Ipdu */
      LpRxIpdu = &Com_GaaRxIpdu[ComRxPduId];
      /* Get the pointer to Rx TP structure */
      LpRxTPIpdu = &Com_GaaRxTPIpdu[LpRxIpdu->ucRxTPRef];
      /* Check if buffer is locked */
      if(COM_ZERO == ((Com_GaaRxTPStatus[LpRxTPIpdu->ucRxTPStatusRef]) & 
        (LpRxTPIpdu->ucRxTPStatusMask)))
      {
        /* If length is greater than maximum length for the Ipdu */
        if(TpSduLength > (LpRxTPIpdu->ddRxTPMaxIpduSize))
        {
          LddReturnValue = BUFREQ_E_OVFL;
        }
        else
        {
          #if((COM_TP_RX_IPDU_COUNTER_ENABLED == STD_ON))
          if((LpRxTPIpdu->pDoubleIpduBuffer) != NULL_PTR)
          {
            /* Get the pointer to temporary internal buffer if counter or 
            replication is configured */
            LpPduInfoPtr = LpRxTPIpdu->pDoubleIpduBuffer;
          }
          else
          #endif
          {
            /* Get the pointer to internal buffers */
            LpPduInfoPtr = &Com_GaaRxPduInfoPtr[ComRxPduId];
          }
          /* Store the size of the (dynamic) Ipdu */
          /* COM656 */
          *LpPduInfoPtr->SduLength = TpSduLength;
          /* Update length */
          /* COM657 */
          *RxBufferSizePtr = (PduLengthType)LpRxTPIpdu->ddRxTPMaxIpduSize;
          /* Set the TP buffer status to "locked" */
          Com_GaaRxTPStatus[LpRxTPIpdu->ucRxTPStatusRef] 
            |= LpRxTPIpdu->ucRxTPStatusMask;
        }
      }
      else
      {
        LddReturnValue = BUFREQ_E_BUSY;         
      }
     
    }
    else
    {
      LddReturnValue = BUFREQ_E_NOT_OK; 
    }
  }
  return(LddReturnValue);
}

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_CopyRxData                                      **
**                                                                            **
** Service ID           : 0x23                                                **
**                                                                            **
** Description          : Called once upon reception of each segment. Within  **
**                        this call, the received data is copied to the       **
**                        receive TP buffer. The API might only be called     **
**                        with an SduLength greater 0 if RxBufferSizePtr      **
**                        returned by the previous API call indicates         **
**                        sufficient receive buffer                           **
**                        (SduLength&lt= RxBufferSizePtr). The function must  **
**                        only be called if the connection has been accepted  **
**                        by an initial call to Com_StartOfReception.         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same signal.                  **
**                        Reentrant for different signals.                    **
**                                                                            **
** Input Parameters     : LddComRxpduId, PduInfoPointer                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : RxBufferSizePtr                                     **
**                                                                            **
** Return parameter     : BufReq_ReturnType                                   **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaRxIpdu              **
**                                                 Com_GaaRxTPIpdu            **
**                                                 Com_GaaRxIpduStatus        **
**                                                 Com_GaaRxPduInfoPtr        **
**                                                 Com_GaaRxIpduTPLength      **
**                        Function(s) invoked    : Det_ReportError()          **
*******************************************************************************/
#if(COM_RX_TP_SUPPORT == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(BufReq_ReturnType, COM_CODE) Com_CopyRxData(PduIdType ComRxPduId, 
  P2CONST(PduInfoType, AUTOMATIC, COM_CONST)PduInfoPointer, 
  P2VAR(PduLengthType, AUTOMATIC, COM_VAR)RxBufferSizePtr)
{
  /* Pointer to Ipdu Buffer */
  P2CONST(Com_RxPduInfoType, AUTOMATIC, COM_CONST) LpPduInfoPtr;
  /* Pointer to Com_RxIpdu */
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu;
  /* Pointer to Rx TP structure */
  P2CONST(Com_RxTPIpdu, AUTOMATIC, COM_CONST) LpRxTPIpdu;
  /* Return value */
  BufReq_ReturnType LddReturnValue;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  uint8 LucReturnValue;
  #endif  
  /* Initialize return value */
  LddReturnValue = BUFREQ_OK;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Initialize DET error flag to E_OK */
  LucReturnValue = (uint8)E_OK;  
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_COPYRXDATA);
  /* Check whether Ipdu ID is out of range */
  COM_DET_RXPDUID_RANGE_CHECK_FLAG(ComRxPduId, COMSERVICEID_COPYRXDATA);
  /* Check whether input buffer is NULL  */
  COM_DET_PDUINFOPTR_PTR_CHECK_FLAG(PduInfoPointer, COMSERVICEID_COPYRXDATA);
  if(LucReturnValue != (uint8)E_OK)
  {
    LddReturnValue = BUFREQ_E_NOT_OK;
  }  
  if(LucReturnValue == (uint8)E_OK)
  #endif
  {
    /* Get the pointer to Rx Ipdu structure */
    LpRxIpdu = &Com_GaaRxIpdu[ComRxPduId];
    /* Get the pointer to Rx TP structure */
    LpRxTPIpdu = &Com_GaaRxTPIpdu[LpRxIpdu->ucRxTPRef];
    if((Com_GaaRxIpduTPLength[LpRxTPIpdu->ucRxIpduTPLengthRef] + 
        PduInfoPointer->SduLength) <= LpRxTPIpdu->ddRxTPMaxIpduSize)
    {
      /* Check if Ipdu has been started */
      if(Com_GaaRxIpduStatus[ComRxPduId] != (PduIdType)COM_ZERO) 
      {
        #if(COM_TP_RX_IPDU_COUNTER_ENABLED == STD_ON)
          if((LpRxTPIpdu->pDoubleIpduBuffer) != NULL_PTR)
          {
            LpPduInfoPtr = LpRxTPIpdu->pDoubleIpduBuffer;
          }
          else
        #endif
        {
          /* Get the pointer to PduInfoPtr structure */
          LpPduInfoPtr = &Com_GaaRxPduInfoPtr[ComRxPduId];
        }
        if(PduInfoPointer->SduLength > COM_ZERO)
        {
          /* Copy data from PduR buffer to Com internal Ipdu Buffer */
          memcpy(
          (P2VAR(void, AUTOMATIC, COM_VAR))(&(LpPduInfoPtr->SduDataPtr
          [Com_GaaRxIpduTPLength[LpRxTPIpdu->ucRxIpduTPLengthRef]])), 
          (P2CONST(void, AUTOMATIC, COM_CONST))(PduInfoPointer->SduDataPtr),
          PduInfoPointer->SduLength);    
        }

        Com_GaaRxIpduTPLength[LpRxTPIpdu->ucRxIpduTPLengthRef] += 
         (PduLengthType)(PduInfoPointer->SduLength);

        *RxBufferSizePtr = (PduLengthType) (LpRxTPIpdu->ddRxTPMaxIpduSize
          - Com_GaaRxIpduTPLength[LpRxTPIpdu->ucRxIpduTPLengthRef]);
      }
      else
      {
        LddReturnValue = BUFREQ_E_NOT_OK;
      }
    }
  
    else
    {
      LddReturnValue = BUFREQ_E_BUSY;
    }
  }
  return(LddReturnValue);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_CopyTxData                                      **
**                                                                            **
** Service ID           : 0x24                                                **
**                                                                            **
** Description          : At invocation of Com_CopyTxData the AUTOSAR COM     **
**                        module copy the requested transmit data of the      **
**                        large IPDU with ID PduId from its internal transmit **
**                        buffer to the location specified by the PduInfoPtr. **
**                        The function Com_CopyTxData also calculates and     **
**                        sets the TxDataCntPtr to the amount of remaining    **
**                        bytes for the transmission of this large I-PDU.     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same signal.                  **
**                        Reentrant for different signals.                    **
**                                                                            **
** Input Parameters     : PduId, PduInfoPtr, RetryInfoPtr                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : TxDataCntPtr                                        **
**                                                                            **
** Return parameter     : BufReq_ReturnType                                   **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GddComStatus           **
**                                                 Com_GaaTxIpdu              **
**                                                 Com_GaaTxTPIpdu            **
**                                                 Com_GaaTxIpduStatusBit     **
**                                                 Com_GaaTxPduInfoPtr        **
**                                                 Com_GaaTxIpduTPLength      **
**                                                 Com_GaaTxDynSigLength      **
**                        Function(s) invoked    : Det_ReportError()          **
*******************************************************************************/
#if(COM_TX_TP_SUPPORT == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
/* polyspace:begin<MISRA-C:16.7:Not a defect:Justify with annotations> Not a defect, AUTOSAR specification */
FUNC(BufReq_ReturnType, COM_CODE) Com_CopyTxData(PduIdType ComTxPduId, 
  P2CONST(PduInfoType, AUTOMATIC, COM_CONST)PduInfoPtr,
  P2VAR(RetryInfoType, AUTOMATIC, COM_VAR)RetryInfoPtr, 
  P2VAR(PduLengthType, AUTOMATIC, COM_VAR)TxDataCntPtr)
{
  /* Pointer to Ipdu Buffer */
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR) LpPduInfoPtr;
  /* Pointer to Com_TxIpdu */
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu;
  /* Pointer to TP Ipdu structure */
  P2CONST(Com_TxTPIpdu, AUTOMATIC, COM_CONST) LpTxTPIpdu;
  /* Return value */
  BufReq_ReturnType LddReturnValue;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  uint8 LucReturnValue = (uint8)E_OK;
  #endif    
  LddReturnValue = BUFREQ_OK;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Initialize DET error flag to E_OK */
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_COPYTXDATA);
  /* Check whether Ipdu ID is out of range */
  COM_DET_TXPDUID_RANGE_CHECK_FLAG(ComTxPduId, COMSERVICEID_COPYTXDATA);
  /* Check whether input buffer is NULL  */
  COM_DET_PDUINFOPTR_PTR_CHECK_FLAG(PduInfoPtr, COMSERVICEID_COPYTXDATA);

  if(LucReturnValue != (uint8)E_OK)
  {
    LddReturnValue = BUFREQ_E_NOT_OK;
  }  
  if(LucReturnValue == (uint8)E_OK)
  #endif
  {
    /* Get pointer to Ipdu structure */
    LpTxIpdu = &Com_GaaTxIpdu[ComTxPduId];
    /* Get the pointer to TP structure  */
    LpTxTPIpdu = &Com_GaaTxTPIpdu[LpTxIpdu->ucTxTPRef];
    /* Check if Ipdu has been started */
    if(Com_GaaTxIpduStatus[ComTxPduId] != (PduIdType)COM_ZERO)
    {
      /* Get the pointer to PduInfoPtr structure */
      LpPduInfoPtr = &Com_GaaTxPduInfoPtr[ComTxPduId];
      if(PduInfoPtr->SduLength > COM_ZERO)
      {
        /* Copy data from internal buffer to the buffer specified by PduR */
        memcpy(
        (P2VAR(void, AUTOMATIC, COM_VAR))(PduInfoPtr->SduDataPtr), 
        (P2CONST(void, AUTOMATIC, COM_CONST))(&(LpPduInfoPtr->SduDataPtr[Com_GaaTxIpduTPLength
        [LpTxTPIpdu->ucTxIpduTPLengthRef]])) ,        
        PduInfoPtr->SduLength);
      }
      /* Update the length parameter with the remaining number of bytes yet 
         to be copied */
      /* Update the number of bytes already copied */
      Com_GaaTxIpduTPLength[LpTxTPIpdu->ucTxIpduTPLengthRef] += 
        (PduLengthType)(PduInfoPtr->SduLength);
      #if(COM_TX_DYN_SUPPORT == STD_ON)
      /* #2142 : separate DYN PDU from TP */
      if((LpTxIpdu->ucIpduType == COM_DYN_IPDU) && 
        (LpTxIpdu->ddTxIpduDynLegthRef != COM_INVALID_TXID_PARAM))
      {
        *TxDataCntPtr = (PduLengthType)(LpTxIpdu->ddTxNonDynLength  + 
          Com_GaaTxDynSigLength[LpTxIpdu->ddTxIpduDynLegthRef] - 
          Com_GaaTxIpduTPLength[LpTxTPIpdu->ucTxIpduTPLengthRef]);
      }
      else
      #endif
      {
        *TxDataCntPtr = (PduLengthType)(LpPduInfoPtr->SduLength - 
          Com_GaaTxIpduTPLength[LpTxTPIpdu->ucTxIpduTPLengthRef]);
      }        
    }
    else
    {
      LddReturnValue = BUFREQ_E_NOT_OK;
    }
  }

  COM_UNUSED_PTR(RetryInfoPtr);
  return(LddReturnValue);
}
/* polyspace:end<MISRA-C:16.7:Not a defect:Justify with annotations> Not a defect, AUTOSAR specification */

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_TpRxIndication                                  **
**                                                                            **
** Service ID           : 0x1E                                                **
**                                                                            **
** Description          : By a call to Com_TpRxIndication the AUTOSAR COM     **
**                        module starts the processing of the received large  **
**                        or dynamic length IPDU                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same PDU-ID.                  **
**                        Reentrant for different PDU-ID.                     **
**                                                                            **
** Input Parameters     : PduId, Result                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaRxIpdu              **
**                                                 Com_GaaRxTPIpdu            **
**                                                 Com_GaaRxIpduStatus        **
**                                                 Com_GaaRxTPStatus          **
**                                                 Com_GaaRxPduInfoPtr        **
**                                                 Com_GaaReceiveHistoryList  **
**                                                 Com_GusRxWriteIndex        **
**                                                 Com_GaaRxIpduTPLength      **
**                        Function(s) invoked    : Det_ReportError()          **
**                                                 SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
**                                                 Com_RxIpduCallout()        **
**                                                 Com_RxIpduCounterChk()     **
**                                                 Com_DoubleBufferCall()     **
**                                                 Com_RxSigProcessing()      **
**                                                 Com_RxSigGrpProcessing()   **
*******************************************************************************/
#if(COM_RX_TP_SUPPORT == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE)Com_TpRxIndication(PduIdType ComRxPduId, 
  NotifResultType Result)
{
  /* Pointer to Rx Ipdu structure */
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu;
  /* Pointer to Rx TP structure */
  P2CONST(Com_RxTPIpdu, AUTOMATIC, COM_CONST) LpRxTPIpdu;
  #if(COM_TP_RX_IPDU_COUNTER_ENABLED == STD_ON)
  /* Pointer to Ipdu Buffer */
  P2VAR(Com_RxPduInfoType, AUTOMATIC, COM_VAR) LpPduInfoPtr;
  /* Load SduDataPtr in local pointer */
  P2CONST(uint8, AUTOMATIC, COM_CONST)LpSduPtr;
  boolean LblCounterFlag;
  #endif
  #if(COM_RX_IPDU_CALLOUT == STD_ON)
  /* Local variable to store callout flag */
  boolean LblCalloutFlag;
  PduInfoType LddPduCalloutInfo;
  #endif
  #if(COM_TP_RX_IPDU_COUNTER_ENABLED == STD_ON)
  LblCounterFlag = COM_FALSE;
  #endif
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Initialize error flag to false */
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_TPRXINDICATION);
  /* Check whether Tx PDU ID is out of range */
  COM_DET_RXPDUID_RANGE_CHECK_FLAG(ComRxPduId, COMSERVICEID_TPRXINDICATION);

  if(LucReturnValue == (uint8)E_OK)
  #endif /* COM_DEV_ERROR_DETECT */
  {
    /* Check if Result from PduR is "ok". Otherwise Ipdu will not be processed 
       the Ipdu */
    /* Get the pointer to Tx Ipdu */
    LpRxIpdu = &Com_GaaRxIpdu[ComRxPduId];
    /* Get the pointer to Rx TP structure */
    LpRxTPIpdu = &Com_GaaRxTPIpdu[LpRxIpdu->ucRxTPRef];
    /* Check whether Rx I-PDU is started */
    if(Com_GaaRxIpduStatus[ComRxPduId] != (PduIdType)COM_ZERO)
    {
      /* If TP Buffer is locked i.e any TP Tx is in progress */
      if((Com_GaaRxTPStatus[LpRxTPIpdu->ucRxTPStatusRef] & 
      (LpRxTPIpdu->ucRxTPStatusMask)) != COM_ZERO)
      {
        /* Unlock the buffer */
        Com_GaaRxTPStatus[LpRxTPIpdu->ucRxTPStatusRef] 
          &= (uint8)(~(LpRxTPIpdu->ucRxTPStatusMask));
		
        /* For handling SoAd TP message, when Header option is disabled 
        by AUTRON #818 */
        if(*(PduLengthType *)Com_GaaRxPduInfoPtr[ComRxPduId].SduLength == (PduLengthType)COM_ZERO)
        {
          *(PduLengthType *)Com_GaaRxPduInfoPtr[ComRxPduId].SduLength 
          = Com_GaaRxIpduTPLength[LpRxTPIpdu->ucRxIpduTPLengthRef];
        }
		  
        /* Set the length of Ipdu copied to zero */
        Com_GaaRxIpduTPLength[LpRxTPIpdu->ucRxIpduTPLengthRef] = COM_ZERO;
        if(NTFRSLT_OK == Result)
        {
          #if(COM_RX_IPDU_CALLOUT == STD_ON)
          LblCalloutFlag = COM_TRUE;
          /* Check whether I-PDU callout is configured */
          if((LpRxIpdu->ddIpduCalloutIndex) != COM_INVALID_RXID_PARAM)
          {      
            LddPduCalloutInfo.SduDataPtr = 
            Com_GaaRxPduInfoPtr[ComRxPduId].SduDataPtr;
            LddPduCalloutInfo.SduLength = 
            (PduLengthType)(*Com_GaaRxPduInfoPtr[ComRxPduId].SduLength);
            
            LblCalloutFlag = Com_RxIpduCallout(ComRxPduId, 
            (PduInfoType *)&LddPduCalloutInfo);
          }
          
          if(COM_TRUE == LblCalloutFlag)
          #endif
          {
            #if(COM_TP_RX_IPDU_COUNTER_ENABLED == STD_ON)
              /* Check whether I-PDU counter is configured */
            if(LpRxIpdu->ddRxIpduCounter != COM_INVALID_RXID_PARAM)
            {
              if(LpRxTPIpdu->pDoubleIpduBuffer != NULL_PTR)
              {
                /* Load SduDataPtr in local pointer */
                LpSduPtr = (LpRxTPIpdu->pDoubleIpduBuffer->SduDataPtr);
              
                /* Invoke Com_RxIpduCounterChk() to check I-PDU counter */
                LblCounterFlag = Com_RxIpduCounterChk(ComRxPduId, LpSduPtr);
              }
            }
            #endif
            {
              #if(COM_TP_RX_IPDU_COUNTER_ENABLED == STD_ON)
              if(COM_TRUE == LblCounterFlag)
              #endif
              {
                #if(COM_TP_RX_IPDU_COUNTER_ENABLED == STD_ON)
                /* Get the pointer to */
                LpPduInfoPtr = 
                  (Com_RxPduInfoType *)&Com_GaaRxPduInfoPtr[ComRxPduId];

                Com_DoubleBufferCall(LpRxTPIpdu, LpPduInfoPtr, LpSduPtr);
                #endif
                
                SchM_Enter_Com_RX_FIFO_PROTECTION_AREA();
                Com_GaaReceiveHistoryList[Com_GusRxWriteIndex] = (PduIdType)ComRxPduId;
                Com_GusRxWriteIndex++;
                if(Com_GusRxWriteIndex >= (uint16)COM_RX_IPDU_HISTORY_LIST)
                {
                  Com_GusRxWriteIndex = (uint16)COM_ZERO;
                }
                SchM_Exit_Com_RX_FIFO_PROTECTION_AREA();
                #if((COM_RX_SIGNAL_IMMEDIATENOTIFY == STD_ON) || \
                    (COM_RX_SIGGROUP_IMMEDIATENOTIFY == STD_ON))
                if((COM_FALSE == (Com_GaaRxIpdu[ComRxPduId].ucRxConfig &
                                COM_RX_IPDU_DEFERRED_CONFIG_MASK)))
                {
                  /* Get the pointer to RxIpdu structure */
                  LpRxIpdu = &Com_GaaRxIpdu[ComRxPduId];

                  #if(COM_RX_SIGNAL_IMMEDIATENOTIFY == STD_ON)
                  /* Check whether Rx  signals are present */
                  if(LpRxIpdu->ucNoOfRxSignal != COM_ZERO)
                  {
                    /* Invoke Com_RxSigProcessing() function to process 
                      Rx signals */
                    Com_RxSigProcessing(ComRxPduId, LpRxIpdu, 
                     *(PduLengthType *)Com_GaaRxPduInfoPtr[ComRxPduId].SduLength);
                  }
                  #endif

                  #if(COM_RX_SIGGROUP_IMMEDIATENOTIFY == STD_ON)
                  /* Check whether Rx signal groups are present */
                  if(LpRxIpdu->ucNoOfRxSigGroup != COM_ZERO)
                  {
                    Com_RxSigGrpProcessing(ComRxPduId, LpRxIpdu, 
                      *(PduLengthType *)Com_GaaRxPduInfoPtr[ComRxPduId].SduLength);
                  }
                  #endif

                  #if(COM_RX_SIG_GATEWAY == STD_ON)
                  /* Check whether signal based gateway is configured */
                  if((LpRxIpdu->ucRxConfig & COM_RX_IPDU_GATEWAY_CONFIG_MASK) != 
                                                                    COM_FALSE)
                  {
                    SchM_Enter_Com_RX_GW_STS_PROTECTION_AREA();
                    /* Set the gateway I-PDU status */
                    Com_GaaRxGWIpduStatus[LpRxIpdu->ucRxGWStsIndex] |= 
                                                LpRxIpdu->ucRxGWStsMask;
                    SchM_Exit_Com_RX_GW_STS_PROTECTION_AREA();
                  }
                  #endif                  
                }
                #endif /* #if(COM_RX_IPDU_DEFERRED == STD_ON)  */
              } /* Check if counter flag is set */ 
            }  /* Check if replpication flag is set */ 
          }  /* Check return value of I-PDU call out */
        } /* Check whether Rx I-PDU group is started */
      } /* Check if TP buffer is locked */
      
    } /* Check if Result from PduR is "ok" */  
  }  /* Check whether any development error has occurred */
}

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_TpTxConfirmation                                **
**                                                                            **
** Service ID           : 0x26                                                **
**                                                                            **
** Description          : This function is called by the PduR after a large   **
**                        I-PDU has been transmitted via the transport        **
**                        protocol on its network.                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same PDU-ID.                  **
**                        Reentrant for different PDU-ID.                     **
**                                                                            **
** Input Parameters     : PduId, Result                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaTxIpduTPLength      **
**                                                 Com_GaaTxIpdu              **
**                                                 Com_GaaTxTPIpdu            **
**                                                 Com_GaaTxUpdateBit         **
**                                                 Com_GaaTxPduInfoPtr        **
**                                                 Com_GaaTxMode              **
**                                                 Com_GaaTxTPStatus          **
**                                                 Com_GaaTxIpduTPLength      **
**                        Function(s) invoked    : Det_ReportError()          **
**                                                 SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
**                                                 Com_TpTxConfMDT()          **
**                                                 Com_TxClearUpdateBit()     **
**                                                 Com_TxSigConfirmation()    **
*******************************************************************************/
#if(COM_TX_TP_SUPPORT == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_TpTxConfirmation(PduIdType ComTxPduId, 
  NotifResultType Result)
{
  /* Pointer to Tx Ipdu structure */
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu;
  /* Pointer to Tx Ipdu */
  P2CONST(Com_TxTPIpdu, AUTOMATIC, COM_CONST) LpTxTPIpdu;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Local variable to store return value */
  uint8 LucReturnValue;
  #endif
  #if((COM_TX_SIGNAL_UB == STD_ON) || \
      (COM_TX_SIGGROUP_UB == STD_ON) || \
      (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) || \
      (COM_TX_IPDU_REPETITION == STD_ON))
  boolean LblReturnValue;
  #endif
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Initialize DET error flag to false */
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_TPTXCONFIRMATION);
  /* Check whether Tx PDU ID is out of range */
  COM_DET_TXPDUID_RANGE_CHECK_FLAG(ComTxPduId, COMSERVICEID_TPTXCONFIRMATION);
  if(LucReturnValue == (uint8)E_OK)
  #endif /* COM_DEV_ERROR_DETECT */
  {
    /* Check whether Tx I-PDU is started */
    if((Com_GaaTxIpduStatusBit[ComTxPduId] & COM_TX_REQ_STATUS_MASK) !=
      COM_FALSE)
    {
      /* Get the pointer to Tx Ipdu */
      LpTxIpdu = &Com_GaaTxIpdu[ComTxPduId];
      /* Get the pointer to TP structure  */
      LpTxTPIpdu = &Com_GaaTxTPIpdu[LpTxIpdu->ucTxTPRef];
      if((uint8)NTFRSLT_OK == Result)
      {

        #if((COM_TX_SIGNAL_UB == STD_ON) || \
          (COM_TX_SIGGROUP_UB == STD_ON) || \
          (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) || \
          (COM_TX_IPDU_REPETITION == STD_ON))
        LblReturnValue = Com_TxIpduConfirmation(ComTxPduId);
        if(LblReturnValue == COM_TRUE)
        #endif/*#if(COM_TX_IPDU_UPDATEBIT == STD_ON)*/      
        {
          /* Update confirmation status mask */
          SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();

          Com_GaaTxIpduStatusBit[ComTxPduId] |= COM_TX_CONFIRM_STATUS_MASK;
          Com_GaaTxIpduStatusBit[ComTxPduId] &= (uint16)(~COM_TX_REQ_STATUS_MASK);        
          SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();

          #if(COM_TX_SIGNAL_IMMEDIATENOTIFY == STD_ON)
          
          if(COM_TX_IPDU_NOTIFY_CONFIG_MASK == 
                    (LpTxIpdu->ucTxConfig & COM_TX_IPDU_DEF_NOTIFY_CONFIG_MASK))
          {
            Com_TxSigConfirmation(LpTxIpdu);
          }
          /* Update the length of the Ipdu in Com internal Ipdu buffers */
          Com_GaaTxPduInfoPtr[ComTxPduId].SduLength = 
            Com_GaaTxIpduTPLength[LpTxTPIpdu->ucTxIpduTPLengthRef];
          #endif /* #if(COM_TP_TX_SIGNAL_IMMEDIATENOTIFY == STD_ON) */
        }
      }  
      SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
      /* Unlock the buffer no matter what the result */
      Com_GaaTxTPStatus[LpTxTPIpdu->ucTxTPStatusRef] &= 
                                       (uint8)~(LpTxTPIpdu->ucTxTPStatusMask);
      SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
      /* Set the length of Ipdu copied to zero */
      Com_GaaTxIpduTPLength[LpTxTPIpdu->ucTxIpduTPLengthRef] = COM_ZERO;
    } /* Check whether Tx I-PDU is started */
  } /* Check whether any development error has occurred */
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_DoubleBufferCall                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function added for cyclomatic complexity reduction. **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpRxTPIpdu, LpPduInfoPtr, LpSduPtr                  **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
*******************************************************************************/
#if(COM_TP_RX_IPDU_COUNTER_ENABLED == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE)Com_DoubleBufferCall(P2CONST
  (Com_RxTPIpdu, AUTOMATIC, COM_CONST) 
  LpRxTPIpdu, P2VAR(Com_RxPduInfoType, AUTOMATIC, COM_VAR) LpPduInfoPtr,
  P2CONST(uint8, AUTOMATIC, COM_CONST)LpSduPtr)
{
   if(LpRxTPIpdu->pDoubleIpduBuffer != NULL_PTR)
  {        
    *(uint16 *)LpPduInfoPtr->SduLength = 
      *(uint16 *)LpRxTPIpdu->pDoubleIpduBuffer->SduLength;
    /* Copy the contents of double buffer to actual buffer */
    memcpy(
    (P2VAR(void, AUTOMATIC, COM_VAR)(LpPduInfoPtr->SduDataPtr)), 
    (P2CONST(void, AUTOMATIC, COM_CONST)(LpSduPtr)), 
    *(PduLengthType *)(LpPduInfoPtr->SduLength));
  }
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/* polyspace:end<RTE: NIV : Not a defect : No Action Planned > initialized variable */
/* polyspace:end<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : No Action Planned > configured memory access index */
/* polyspace:end<RTE: STD_LIB : Not a defect : No Action Planned> configured & generated memory address */

/*******************************************************************************
**                          END OF FILE                                       **
*******************************************************************************/
