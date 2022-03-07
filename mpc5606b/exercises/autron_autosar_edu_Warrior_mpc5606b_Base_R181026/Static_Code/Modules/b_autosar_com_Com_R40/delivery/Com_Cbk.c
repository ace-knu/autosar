/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Com_Cbk.c                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Com Module                                            **
**                                                                            **
**  PURPOSE   : Provision of callback functions and their functionality.      **
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
** 2.2.0     16-Apr-2017   Chan Kim    Internal Redmine #7707, #7861, #7525   **
** 2.1.9     20-Mar-2017   Chan Kim    Internal Redmine #7851                 **
** 2.1.7     30-Nov-2016   Chan Kim    Internal Redmine #6806, #6807          **
** 2.1.4     19-Aug-2016   Chan Kim    Internal Redmine #5687, #5813          **
** 2.1.0     25-May-2016   Chan Kim    Internal Redmine #4998                 **
** 2.0.8     12-Feb-2016   Chan Kim    Internal Redmine #4138, #4158          **
** 2.0.5     12-Jan-2016   Chan Kim    Internal Redmine #3863                 **
** 2.0.3     24-Nov-2015   Chan Kim    Internal Redmine #3544, #3535          **
** 2.0.2     19-Sep-2015   Chan Kim    Internal Redmine #3182, #3178          **
** 1.0.16    27-Feb-2015   Chan Kim    Internal Redmine #2202                 **
** 1.0.14    03-Nov-2014   Chan Kim    Internal Redmine #1463, #1517, #1518   **
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
#define COM_CBK_C_AR_RELEASE_MAJOR_VERSION       4
#define COM_CBK_C_AR_RELEASE_MINOR_VERSION       0
#define COM_CBK_C_AR_RELEASE_REVISION_VERSION    3

/* Software version information */
#define COM_CBK_C_SW_MAJOR_VERSION  2
#define COM_CBK_C_SW_MINOR_VERSION  2

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if(COM_AR_RELEASE_MAJOR_VERSION != COM_CBK_C_AR_RELEASE_MAJOR_VERSION)
  #error "Com_Cbk.c : Mismatch in Com Specification Major Version"
#endif

#if(COM_AR_RELEASE_MINOR_VERSION != COM_CBK_C_AR_RELEASE_MINOR_VERSION)
  #error "Com_Cbk.c : Mismatch in Com Specification Minor Version"
#endif

#if(COM_AR_RELEASE_REVISION_VERSION != \
  COM_CBK_C_AR_RELEASE_REVISION_VERSION)
  #error "Com_Cbk.c : Mismatch in Com Specification Revision Version"
#endif

#if(COM_SW_MAJOR_VERSION != COM_CBK_C_SW_MAJOR_VERSION)
  #error "Com_Cbk.c : Mismatch in Com Software Major Version"
#endif

#if(COM_SW_MINOR_VERSION != COM_CBK_C_SW_MINOR_VERSION)
  #error "Com_Cbk.c : Mismatch in Com Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/* polyspace:begin<RTE: NIV : Not a defect : No Action Planned > initialized variable */
/* polyspace:begin<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:begin<RTE: OBAI : Not a defect : No Action Planned > configured  memory access index */
/* polyspace:begin<RTE: STD_LIB : Not a defect : No Action Planned> configured & generated memory address */

/*******************************************************************************
** Function Name        : Com_TxConfirmation                                  **
**                                                                            **
** Service ID           : 0x40                                                **
**                                                                            **
** Description          : This function called by the lower layer after the   **
**                        PDU has been transmitted on the network. This       **
**                        function generates the notification for the         **
**                        configured signals.                                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same PDU-ID.                  **
**                        Reentrant for different PDU-ID.                     **
**                                                                            **
** Input Parameters     : ComTxPduId                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaTxIpduStatusBit     **
**                                                 Com_GaaTxIpdu              **
**                        Function(s) invoked    : Det_ReportError()          **
**                                                 SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
**                                                 Com_TxIpduConfirmation()   **
**                                                 Com_TxSigConfirmation()    **
*******************************************************************************/
#if(COM_TX_IPDU == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_TxConfirmation(PduIdType ComTxPduId)
{
  /* #7707 */
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Local variable to store return value */
  uint8 LucReturnValue;
  #endif
  #if(COM_TX_IPDU_REPETITION == STD_ON)
  boolean LblReturnValue;
  #endif
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Initialize DET error flag to false */
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_TXCONFIRMATION);
  /* Check whether Tx PDU ID is out of range */
  COM_DET_TXPDUID_RANGE_CHECK_FLAG(ComTxPduId, COMSERVICEID_TXCONFIRMATION);
  if(LucReturnValue == (uint8)E_OK)
  #endif /* COM_DEV_ERROR_DETECT */
  {
    /* Check whether Tx I-PDU is started */
    if((Com_GaaTxIpduStatusBit[ComTxPduId] & COM_TX_REQ_STATUS_MASK) !=
                                                                      COM_FALSE)
    {
      #if((COM_TX_SIGNAL_UB == STD_ON) || \
          (COM_TX_SIGGROUP_UB == STD_ON) || \
          (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) || \
          (COM_TX_IPDU_REPETITION == STD_ON))
      #if(COM_TX_IPDU_REPETITION == STD_ON)
      LblReturnValue = Com_TxIpduConfirmation(ComTxPduId);
      #else
      (void)Com_TxIpduConfirmation(ComTxPduId);
      #endif
      #endif
      #if(COM_TX_IPDU_REPETITION == STD_ON)
      if(LblReturnValue == COM_TRUE)
      #endif/*#if(COM_TX_IPDU_UPDATEBIT == STD_ON)*/      
      {
        /* Update confirmation status mask */
        #if(COM_TX_INTERRUPT_BASED_PROCESS == STD_OFF)
        SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
        #endif
        Com_GaaTxIpduStatusBit[ComTxPduId] |= COM_TX_CONFIRM_STATUS_MASK;
        Com_GaaTxIpduStatusBit[ComTxPduId] &= (uint16)(~COM_TX_REQ_STATUS_MASK);
        #if(COM_TX_INTERRUPT_BASED_PROCESS == STD_OFF)
        SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
        #endif

        #if(COM_TX_SIGNAL_IMMEDIATENOTIFY == STD_ON)
        if((Com_GaaTxIpdu[ComTxPduId].ucTxConfig & 
          COM_TX_IPDU_DEF_NOTIFY_CONFIG_MASK) == COM_TX_IPDU_NOTIFY_CONFIG_MASK)
        {
          Com_TxSigConfirmation(&Com_GaaTxIpdu[ComTxPduId]);
        }
        #endif /* #if(COM_TX_SIGNAL_IMMEDIATENOTIFY == STD_ON) */
      }  
    } /* Check whether Tx I-PDU is started */
  } /* Check whether any development error has occurred */
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_TriggerTransmit                                 **
**                                                                            **
** Service ID           : 0x41                                                **
**                                                                            **
** Description          : The lower layer calls this function when a Com      **
**                        I-PDU shall be transmitted. Within this function,   **
**                        Com shall copy the contents of its I-PDU transmit   **
**                        buffer to the L-PDU buffer given by SduPtr.         **
**                                                                            **
** Sync/Async           : Synchronous                                        **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same PDU-ID.                  **
**                        Reentrant for different PDU-ID.                     **
**                                                                            **
** Input Parameters     : ComTxPduId, PduInfoPtr                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : SduPtr                                              **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GddComStatus           **
**                                                 Com_GaaTxPduInfoPtr        **
**                                                 Com_GaaTxIpdu              **
**                                                 Com_GaaTxUpdateBit         **
**                                                 Com_GaaCounterStatusFlag   **
**                                                 Com_GaaTxIpduStatus        **
**                        Function(s) invoked    : Det_ReportError()          **
**                                                 SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
**                                                 Com_TxClearUpdateBit()     **
**                                                 Com_TransIpduCounter()     **
**                                                 pIpduCallout               **
*******************************************************************************/
#if(COM_TX_IPDU == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, COM_CODE) Com_TriggerTransmit (PduIdType ComTxPduId,
                   P2VAR(PduInfoType, AUTOMATIC, COM_VAR)PduInfoPtr)
{
  P2VAR(uint8, AUTOMATIC, COM_VAR)LpSourcePtr;
  /* Pointer to Tx Ipdu structure */
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu;
  /* Callout function input value is changed in 4.1.1 com specification 
  - Fixed by AUTRON START*/          
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR)LpPduInfoPtr;
  /* Callout function input value is changed in 4.1.1 com specification 
  - Fixed by AUTRON END*/             

  /* Local variable to store no. of byte */
  PduLengthType LddNoOfByte;

  /* Local variable to store return value */
  Std_ReturnType LddReturnValue;
  /* #7707 */
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Local variable to store return value */
  uint8 LucReturnValue;
  #endif  
  /* Initialize return value */
  LddReturnValue = (uint8)E_OK;
  
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Initialize error flag to false */
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_TRIGGERTRANSMIT);
  /* Check whether PduInfoPtr pointer is NULL */
  COM_DET_PDUINFOPTR_PTR_CHECK_FLAG(PduInfoPtr, COMSERVICEID_TRIGGERTRANSMIT);
  /* Check whether Tx PDU ID is out of range */
  COM_DET_TXPDUID_RANGE_CHECK_FLAG(ComTxPduId, COMSERVICEID_TRIGGERTRANSMIT);   
  if(LucReturnValue != (uint8)E_OK)
  {
    /* Specification of AUTOSASR for return value of Com_TriggerTransmit func*/
    LddReturnValue = (uint8)E_NOT_OK;
  }
  if(LucReturnValue == (uint8)E_OK)
  #endif /* COM_DEV_ERROR_DETECT */
  {
    /* Callout function input value is changed in 4.1.1 com specification 
    - Fixed by AUTRON START*/        
    LpPduInfoPtr = (PduInfoType*)&Com_GaaTxPduInfoPtr[ComTxPduId];
  
    /* Get the pointer to I-PDU buffer */
    LpSourcePtr = LpPduInfoPtr->SduDataPtr;

    /* Get the size of I-PDU data buffer to local variable */
    LddNoOfByte = LpPduInfoPtr->SduLength;
    /* Callout function input value is changed in 4.1.1 com specification 
    - Fixed by AUTRON END*/            
    PduInfoPtr->SduLength = LddNoOfByte;
    LpTxIpdu = &Com_GaaTxIpdu[ComTxPduId];
   

    /* Enter protection area */
    SchM_Enter_Com_TX_IPDU_BUFFER_PROTECTION_AREA();

    #if(COM_TX_IPDU_TRIGGERCALLOUT == STD_ON)
    /* Check whether I-PDU callout is configured */
    if(LpTxIpdu->ddIpduTriggerCalloutIndex != COM_INVALID_TXID_PARAM)
    {
      (void)Com_TxIpduTriggerCallout(ComTxPduId, (PduInfoType *)LpPduInfoPtr);
    }
    #endif

    /* Copy the data buffer */
    memcpy(
    (P2VAR(void, AUTOMATIC, COM_VAR))(PduInfoPtr->SduDataPtr),
    (P2CONST(void, AUTOMATIC, COM_CONST))(&LpSourcePtr[COM_ZERO]),
    LddNoOfByte);
    
    /* Exit protection area */
    SchM_Exit_Com_TX_IPDU_BUFFER_PROTECTION_AREA();

    #if((COM_TX_SIGNAL_UB == STD_ON) || \
          (COM_TX_SIGGROUP_UB == STD_ON))
    /* Check whether update bit needs to be cleared */
    if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_UB_CONFIG_MASK) != COM_ZERO)
    {
      if(COM_TX_IPDU_UB_TRIGGER_CONFIG_MASK == 
      (Com_GaaTxUpdateBit[LpTxIpdu->ddTxIpduUbIndex].ucUBConfig))
      {
        
        Com_TxClearUpdateBit(LpTxIpdu, LpSourcePtr);
      }
    }
    #endif /*#if(COM_TX_SIGNAL_UB == STD_ON)*/
    
    #if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON)
    if(LpTxIpdu->ddTxIpduCounter != COM_INVALID_TXID_PARAM)
    {
      if(COM_COUNTER_TRIGTX == 
                            Com_GaaCounterStatusFlag[LpTxIpdu->ddTxIpduCounter])
      {
        Com_TransIpduCounter(LpTxIpdu);
      }
    }
    #endif
    /* Set the Ipdu Status even if Mode is None */
    if(Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex].ucTxMode == COM_TX_NONE_MODE)
    {
      SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
      Com_GaaTxIpduStatusBit[ComTxPduId] |= (uint16) (COM_TX_REQ_STATUS_MASK);
      SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
    }
    /* Check whether Tx I-PDU is enabled */
    if(Com_GaaTxIpduStatus[ComTxPduId] == (PduIdType)COM_ZERO)
    {
      /* Specification of AUTOSASR for return value of Com_TriggerTransmit func*/
      LddReturnValue = (uint8)E_NOT_OK;
    }
  } /* Check whether any development error has occurred */
  return(LddReturnValue);
}

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif


/*******************************************************************************
** Function Name        : Com_RxIndication                                    **
**                                                                            **
** Service ID           : 0x42                                                **
**                                                                            **
** Description          : This function is called by the lower layer when an  **
**                        I-PDU shall be received. Within this function, COM  **
**                        Module shall copy the contents of its received      **
**                        I-PDU buffer from the L-PDU buffer given by SduPtr. **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same PDU-ID.                  **
**                        Reentrant for different PDU-ID.                     **
**                                                                            **
** Input Parameters     : ComRxPduId, PduInfoPtr                              **
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
**                                                 Com_GaaRxIpduStatus        **
**                                                 Com_GaaRxPduInfoPtr        **
**                                                 Com_GaaReceiveHistoryList  **
**                                                 Com_GusRxWriteIndex        **
**                                                 Com_GaaRxGWIpduStatus      **
**                        Function(s) invoked    : Det_ReportError()          **
**                                                 SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
**                                                 Com_RxIpduValidate()       **
**                                                 Com_RxSigProcessing()      **
**                                                 Com_RxSigGrpProcessing()   **
*******************************************************************************/


#if(COM_RX_IPDU == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_RxIndication(PduIdType ComRxPduId,
  P2CONST(PduInfoType, AUTOMATIC, COM_CONST)PduInfoPtr)
{  
  /* Pointer to Rx Ipdu structure */
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu;
  
  /* Local variable to store size count */
  PduLengthType LddSize;
  /* #7707 */
  #if(COM_DEV_ERROR_DETECT == STD_ON)          
  uint8 LucReturnValue;
  #endif
  #if((COM_RX_IPDU_CALLOUT == STD_ON) || \
      (COM_RX_REPLICATION == STD_ON)  || \
      (COM_RX_IPDU_COUNTER_ENABLED == STD_ON))
  boolean LblReturnValue;
  #endif
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Local variable to store return value */
  /* Initialize error flag to false */
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_RXINDICATION);
  /* Check whether PduInfoPtr pointer is NULL */
  COM_DET_PDUINFOPTR_PTR_CHECK_FLAG(PduInfoPtr, COMSERVICEID_RXINDICATION);
  /* Check whether Tx PDU ID is out of range */
  COM_DET_RXPDUID_RANGE_CHECK_FLAG(ComRxPduId, COMSERVICEID_RXINDICATION);

  if(LucReturnValue == (uint8)E_OK)
  #endif /* COM_DEV_ERROR_DETECT */
  {
    
    /* Get the pointer to Tx Ipdu */
    LpRxIpdu = &Com_GaaRxIpdu[ComRxPduId];
      
    /* Check whether Rx I-PDU is started */
    if(Com_GaaRxIpduStatus[ComRxPduId] != (PduIdType)COM_ZERO)
    {
      #if((COM_RX_IPDU_CALLOUT == STD_ON) || \
          (COM_RX_REPLICATION == STD_ON)  || \
          (COM_RX_IPDU_COUNTER_ENABLED == STD_ON)) 
      LblReturnValue = Com_RxIpduValidate(ComRxPduId, PduInfoPtr);
      if(LblReturnValue == COM_TRUE)
      #endif
      {
        if(LpRxIpdu->ddRxIpduLength < PduInfoPtr->SduLength)
        {
          /* The maximum allowed length of the I-pdu */
          LddSize = LpRxIpdu->ddRxIpduLength;
        }
        else
        {
          /* Get the length of an I-PDU */
          LddSize = PduInfoPtr->SduLength;
        }
       
        *Com_GaaRxPduInfoPtr[ComRxPduId].SduLength = LddSize;
        /* Copy the data buffer */
        
        memcpy(
        (P2VAR(void, AUTOMATIC, COM_VAR))(Com_GaaRxPduInfoPtr[ComRxPduId].SduDataPtr),
        (P2CONST(void, AUTOMATIC, COM_CONST))(PduInfoPtr->SduDataPtr),
        LddSize);

        #if(COM_RX_INTERRUPT_BASED_PROCESS == STD_OFF)
        SchM_Enter_Com_RX_FIFO_PROTECTION_AREA();
        #endif
        #if(COM_RX_IPDU_HISTORY_LIST > 1)
        Com_GaaReceiveHistoryList[Com_GusRxWriteIndex] = (PduIdType)ComRxPduId;
      
        Com_GusRxWriteIndex++;
      
        if(Com_GusRxWriteIndex >= (uint16)COM_RX_IPDU_HISTORY_LIST)
        {
          Com_GusRxWriteIndex = (uint16)COM_ZERO;
        }
        #else
        Com_GusRxWriteIndex++;
        #endif
        #if(COM_RX_INTERRUPT_BASED_PROCESS == STD_OFF)
        SchM_Exit_Com_RX_FIFO_PROTECTION_AREA();
        #endif
       
        #if((COM_RX_SIGNAL_IMMEDIATENOTIFY == STD_ON) || \
            (COM_RX_SIGGROUP_IMMEDIATENOTIFY == STD_ON))
        {
          if((COM_FALSE == (Com_GaaRxIpdu[ComRxPduId].ucRxConfig &
                              COM_RX_IPDU_DEFERRED_CONFIG_MASK)))
          {
            #if(COM_RX_SIGNAL_IMMEDIATENOTIFY == STD_ON)
            /* Check whether Rx  signals are present */
           
            if(LpRxIpdu->ucNoOfRxSignal != COM_ZERO)
            {
              /* Invoke Com_RxSigProcessing() function to process Rx signals */
              Com_RxSigProcessing(ComRxPduId, LpRxIpdu, LddSize);
            }
            #endif

            #if(COM_RX_SIGGROUP_IMMEDIATENOTIFY == STD_ON)
            /* Check whether Rx signal groups are present */
            if(LpRxIpdu->ucNoOfRxSigGroup != COM_ZERO)
            {
              
              /* Invoke Com_RxSigGrpProcessing() function to process Rx signal
              groups */
             
              Com_RxSigGrpProcessing(ComRxPduId, LpRxIpdu, LddSize);
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
        }
        #endif /* #if(COM_RX_IPDU_DEFERRED == STD_ON)  */
          
        #if((COM_RX_REPLICATION == STD_ON) && \
          (COM_RX_IPDU_COUNTER_ENABLED == STD_ON))
        Com_GblNoConfirmation = COM_FALSE;
        #endif
      }  /* Check return value of I-PDU call out */
    } /* Check whether Rx I-PDU group is started */
  } /* Check whether any development error has occurred */
}

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_RxReplication                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called by the Com module when the  **
**                        I-PDU is configured for I-PDU replication. Within   **
**                        this function, Com module shall perform the         **
**                        Communication Protection mechanism for I-PDUs       **
**                        received.                                           **
**                                                                            **
** Re-entrancy          : Non Reentrant for the same PDU-ID.                  **
**                        Reentrant for different PDU-ID.                     **
**                                                                            **
** Input Parameters     : LpRxIpdu, LpSduDataPtr                              **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :  Com_GaaRxRepliCount,         **
**                                               Com_GaaRxIpduReplication     **
**                                               Com_GaaRamIpduRepliSts       **
**                        Function(s) invoked :                               **
**                        SchM_Enter_xxx,  SchM_Exit_xxx                      **
*******************************************************************************/
#if(COM_RX_REPLICATION == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(boolean, COM_CODE) Com_RxReplication(
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu,
  P2CONST(uint8, AUTOMATIC, COM_CONST) LpSduDataPtr)
{
  P2CONST(Com_RxIpduReplication, AUTOMATIC, COM_CONST)
    LpRxIpduRepli;
  P2VAR(uint8, AUTOMATIC, COM_VAR) LpRepliSts;
  P2VAR(uint8, AUTOMATIC, COM_VAR) LpIpduTempBuff;
  /* uint8 -> PduLengthType for variable which has Pdu Length info 
  - Fixed by AUTRON START*/        
  PduLengthType LddSizeOrCount;
  /* uint8 -> PduLengthType for variable which has Pdu Length info 
  - Fixed by AUTRON END*/        
  uint8 LucRepliCount;
  boolean LblReturnValue;
  PduLengthType LddBufferIndex;

  LddBufferIndex = (PduLengthType)COM_ZERO;
  /* Set return value to FALSE */
  LblReturnValue = COM_FALSE;
  /* Load the pointer for Rx Replication stucture */
  LpRxIpduRepli = &Com_GaaRxIpduReplication[LpRxIpdu->ucRxIpduRepliIndex];
  /* Get the length of I-PDU */
  LddSizeOrCount = LpRxIpdu->ddRxIpduLength;
  /* Load the pointer for replicated I-PDU buffer */
  LpIpduTempBuff =
    (P2VAR(uint8, AUTOMATIC, COM_VAR)) (LpRxIpduRepli->pIpduBuffer);
  /* Get the actual replication count */
  LucRepliCount = Com_GaaRxRepliCount[LpRxIpduRepli->ucIpduRepliCountIndex];
  /* Shift to get the value */
  LucRepliCount >>= (LpRxIpduRepli->ucIpduRepliCountShift);
  LucRepliCount &= COM_REPLICATION_MASK;

  /* Check whether received I-PDU is first replicated I-PDU */
  if(COM_ZERO == LucRepliCount)
  {
    /* Enter protection area */
    SchM_Enter_Com_RX_IPDU_DATA_PROTECTION_AREA();
    memcpy(
    (P2VAR(void, AUTOMATIC, COM_VAR))(LpIpduTempBuff), 
    (P2CONST(void, AUTOMATIC, COM_CONST))(LpSduDataPtr), 
    (PduLengthType)LddSizeOrCount);
    /* Exit protection area */
    SchM_Exit_Com_RX_IPDU_DATA_PROTECTION_AREA();
    /* Load the replication count */
    LucRepliCount = LpRxIpduRepli->ucIpduRepliCount;
  }
  /* Is received I-PDU is not the first replicated I-PDU */
  else
  {
    /* Get the pointer to Rx Replication status */
    LpRepliSts = &Com_GaaRamIpduRepliSts[LpRxIpduRepli->ucIpduRepliStsIndex];
    /* Check replicated status of the I-PDU for mismatch in I-PDU */
    if(COM_ZERO == ((*LpRepliSts) & LpRxIpduRepli->ucIpduRepliEnMask))
    {
      /*
       * Compare each byte pointed by LpSduDataPtr with data byte which is
       * present in replicated I-PDU buffer
       */
      while(LddSizeOrCount != (PduLengthType)COM_ZERO)
      {
        /* Compare each data byte with data already stored in buffer */
        if(LpIpduTempBuff[LddBufferIndex] != LpSduDataPtr[LddBufferIndex])
        {
          /* Enter protection area */
          SchM_Enter_Com_RX_IPDU_STS_PROTECTION_AREA();
          /* Set replicated status mask */
          (*LpRepliSts) |= LpRxIpduRepli->ucIpduRepliEnMask;
          /* Exit protection area */
          SchM_Exit_Com_RX_IPDU_STS_PROTECTION_AREA();
          /* Load with Zero to break the loop */
          LddSizeOrCount = (PduLengthType)COM_ZERO;
        }
        else
        {
          /* Decrement I-PDU size count variable */
          LddSizeOrCount--;
          /* Increment pointer index */
          LddBufferIndex++;
        }
      } /* End while(LucSizeOrCount != COM_ZERO) */
    } /* check whether any mismatch in replicated I-PDUs */

    /* Decrement Replication Count variable */
    LucRepliCount-- ;

    /* Check whether all replicated I-PDUs are received */
    if(COM_ZERO == LucRepliCount)
    {
      /*
       * Check replicated status mask for any data mismatch in any of the
       * replicated I-PDUs
       */
      if(((*LpRepliSts) & LpRxIpduRepli->ucIpduRepliEnMask) == COM_ZERO)
      {
        LblReturnValue = COM_TRUE;
      }

      /* Enter protection area */
      SchM_Enter_Com_RX_IPDU_STS_PROTECTION_AREA();
      /* Reset replicated status mask */
      (*LpRepliSts) &= (uint8)(~LpRxIpduRepli->ucIpduRepliEnMask);
      /* Exit protection area */
      SchM_Exit_Com_RX_IPDU_STS_PROTECTION_AREA();
    } /* End if(LucRepliCount == COM_ZERO) */

  } /* Check whether Replicated I-PDU is not received for first time */

  /* Load the present replication count */
  LucRepliCount = 
    (uint8)(LucRepliCount << (LpRxIpduRepli->ucIpduRepliCountShift));
  /* Original value copied into a local variable */
 
  /* Load the timer with updated timer value */
  Com_GaaRxRepliCount[LpRxIpduRepli->ucIpduRepliCountIndex] = LucRepliCount;
  return(LblReturnValue);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_RxIpduCounterChk                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called by the Com module when the  **
**                        I-PDU is configured for I-PDU replication. Within   **
**                        this function, Com module shall perform the         **
**                        Communication Protection mechanism for I-PDUs       **
**                        received                                            **
**                                                                            **
** Re-entrancy          : Non Reentrant for the same PDU-ID.                  **
**                        Reentrant for different PDU-ID.                     **
**                                                                            **
** Input Parameters     : ComRxPduId, LpSduDataPtr                            **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Com_GaaRxIpdu                 **
**                                              Com_GaaRxIpduCounter          **
**                                              Com_GaaRxUnpack               **
**                                              Com_GaaRxIpduCountVal         **
**                                              Com_GaaRamIpduCounterSts      **
**                                              Com_GaaRxCntNotify            **
**                        Function(s) invoked : SchM_Enter_xxx()              **
**                                              SchM_Exit_xxx()               **
*******************************************************************************/
#if(COM_RX_IPDU_COUNTER_ENABLED == STD_ON) 
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(boolean, COM_CODE) Com_RxIpduCounterChk(PduIdType ComRxPduId, 
  P2CONST(uint8, AUTOMATIC, COM_CONST) LpSduDataPtr)
{
  P2CONST(Com_RxIpduCounter, AUTOMATIC, COM_CONST) LpRxIpduCounter;
  P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST) LpRxUnpack;
  uint8 LucExpCount;
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu;
  uint8 LucIpduData;
  uint8 LucRxCountData;
  uint8 LucMaxExpCount;
  boolean LblReturnValue;
  LpRxIpdu = &Com_GaaRxIpdu[ComRxPduId];
  /* Set default return value */
  LblReturnValue = COM_TRUE;
  /* Load pointer for required Rx I-PDU counter structure */
  LpRxIpduCounter = &Com_GaaRxIpduCounter[LpRxIpdu->ddRxIpduCounter];
  /* Load pointer for RxUnpack structure */
  LpRxUnpack = &Com_GaaRxUnpack[LpRxIpduCounter->ddRxUnpackIndex];
  /* Get the I-PDU buffer data to a local I-PDU variable */
  LucIpduData = *((P2CONST(uint8, AUTOMATIC, COM_CONST))(LpSduDataPtr +
    (Com_PtrType)LpRxUnpack->ucByteIndex));
  /*
   * Shift the local I-PDU variable by the number of shift bits to the get
   * the start position of counter data
   */
  LucIpduData = (uint8)(LucIpduData >> (LpRxUnpack->ucNoOfShiftBits));

  /* Get the counter data */
  LucRxCountData = LucIpduData;
  /* Apply the end mask to clear unoccupied area of counter */
  LucRxCountData &= LpRxUnpack->ucRdEndMask;

  /* Load the pointer for Expected I-PDU Count */
  LucExpCount = Com_GaaRxIpduCountVal[LpRxIpduCounter->ucRxIpduCountData];
  LucExpCount = 
              (uint8)(LucExpCount >> LpRxIpduCounter->ucRxIpduCounterShiftBits);
  LucExpCount &= LpRxIpduCounter->ucRxIpduCntWrpMask;

  /* Get maximum expected value with threshold */
  LucMaxExpCount = LucExpCount +(LpRxIpduCounter->ucIPduCounterThreshold);
  /* Get maximum count with counter wrap around */
  LucMaxExpCount &= LpRxIpduCounter->ucRxIpduCntWrpMask;

  /* Check counter status whether I-PDU is received for first time */
  if(COM_ZERO == 
            ((Com_GaaRamIpduCounterSts[LpRxIpduCounter->ucIpduCnterStsIndex]) & 
                                          LpRxIpduCounter->ucIpduCounterEnMask))
  {
    /* Enter protection area */
    SchM_Enter_Com_RX_IPDU_STS_PROTECTION_AREA();
    /* Set the status bit indicating that the first Rx is over */
    Com_GaaRamIpduCounterSts[LpRxIpduCounter->ucIpduCnterStsIndex] 
      |= LpRxIpduCounter->ucIpduCounterEnMask;
    /* Exit protection area */
    SchM_Exit_Com_RX_IPDU_STS_PROTECTION_AREA();
  }
  else
  {
    /* Check for expected counter without counter wrap around */
    if(LucExpCount <= LucMaxExpCount)
    {
      /*
       * Discard the I-PDU when (received counter < expected counter) or
       * (received counter > expected counter with threshold)
       */
      if((LucRxCountData < LucExpCount) || (LucRxCountData > LucMaxExpCount))
      {
        LblReturnValue = COM_FALSE;
      }
    }
    /* Check for expected counter with counter wrap around */
    else
    {
      /*
       * Discard the I-PDU when (received counter < expected counter) and
       * (received counter > expected counter with threshold)
       */
      if((LucRxCountData < LucExpCount) 
        && (LucRxCountData > LucMaxExpCount))
      {
        LblReturnValue = COM_FALSE;
      }
    }
  }

  /* Set expected counter if LblReturnValue is not reset */
  if(COM_TRUE == LblReturnValue)
  {
    /* Increment counter data for setting expected value */
    LucMaxExpCount = LucRxCountData + COM_ONE;
    /* Apply Threshold */
    LucMaxExpCount &= LpRxIpduCounter->ucRxIpduCntWrpMask; 
    /* Shift the value */
    LucMaxExpCount = 
      (uint8)(LucMaxExpCount << (LpRxIpduCounter->ucRxIpduCounterShiftBits));
    LucExpCount = Com_GaaRxIpduCountVal[LpRxIpduCounter->ucRxIpduCountData];
    LucExpCount &= 
    (uint8)(~((uint8)((LpRxIpduCounter->ucRxIpduCntWrpMask)<<
      (LpRxIpduCounter->ucRxIpduCounterShiftBits))));
    /* Load the expected count value respecting counter wrap around */
    Com_GaaRxIpduCountVal[LpRxIpduCounter->ucRxIpduCountData] = LucMaxExpCount;
    Com_GaaRxIpduCountVal[LpRxIpduCounter->ucRxIpduCountData] |= LucExpCount;
  }
  #if(COM_RX_COUNTER_NOTIFY == STD_ON)
  else
  {
    /* Check whether counter notification is configured */
    if(LpRxIpduCounter->ucRxCntNotifIndx != COM_INVALID_NONE)
    {
      /* Invoke counter notification function*/
      (*Com_GaaRxCntNotify[LpRxIpduCounter->ucRxCntNotifIndx])(ComRxPduId,
        Com_GaaRxIpduCountVal[LpRxIpduCounter->ucRxIpduCountData], 
        LucRxCountData);
    }
  }
  #endif
  return(LblReturnValue);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif


/*******************************************************************************
** Function Name        : Com_RxIpduValidate                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function added for cyclomatic complexity reduction. **
**                        It validates Ipdu callout and also the counter      **
**                        value                                               **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : ComRxPduId, PduInfoPtr                              **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :  Com_GaaRxIpdu             **
**                        Function(s) invoked    :  pIpduCallout              **
**                                                  Com_RxReplication()       **
**                                                  Com_RxIpduCounterChk()    **
*******************************************************************************/
#if((COM_RX_IPDU_CALLOUT == STD_ON) || \
    (COM_RX_REPLICATION == STD_ON)  || \
    (COM_RX_IPDU_COUNTER_ENABLED == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"    
FUNC(boolean, COM_CODE) Com_RxIpduValidate(PduIdType ComRxPduId,
  P2CONST(PduInfoType, AUTOMATIC, COM_CONST)PduInfoPtr)
{
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu;
  /* Set LblReturnFlag to TRUE */
  boolean LblReturnFlag = COM_TRUE;
  /* Get the pointer to Tx Ipdu */
  LpRxIpdu = &Com_GaaRxIpdu[ComRxPduId];  
  
  #if(COM_RX_IPDU_CALLOUT == STD_ON)
  /* Check whether I-PDU callout is configured */
  if((LpRxIpdu->ddIpduCalloutIndex) != COM_INVALID_RXID_PARAM)
  {
    LblReturnFlag = Com_RxIpduCallout(ComRxPduId, 
    (P2CONST(PduInfoType, AUTOMATIC, COM_CONST))PduInfoPtr);
  }
  if(COM_TRUE == LblReturnFlag)
  #endif
  {
    #if((COM_RX_REPLICATION == STD_ON) \
	  &&(COM_RX_IPDU_COUNTER_ENABLED == STD_ON) )
    /* Check whether Rx Replication is configured for this I-PDU */  
    if(LpRxIpdu->ucRxIpduRepliIndex != COM_INVALID_NONE)
    {
      /* Invoke Com_RxReplication() to check I-PDU Replication */
      LblReturnFlag = Com_RxReplication(
      (P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST))LpRxIpdu, 
      (P2CONST(uint8, AUTOMATIC, COM_CONST))PduInfoPtr->SduDataPtr);
    }
  	else
  	{
  	  LblReturnFlag = COM_TRUE;
  	}
  
    if(COM_TRUE == LblReturnFlag)
    #endif
    {
      #if(COM_RX_IPDU_COUNTER_ENABLED == STD_ON)
      /* Check whether I-PDU counter is configured */
      if(LpRxIpdu->ddRxIpduCounter != COM_INVALID_RXID_PARAM)
      {        
        /* Invoke Com_RxIpduCounterChk() to check I-PDU counter */
        LblReturnFlag = 
                       Com_RxIpduCounterChk(ComRxPduId, 
                       (P2CONST(uint8, AUTOMATIC, COM_CONST))PduInfoPtr->SduDataPtr);
        #if(COM_RX_REPLICATION == STD_ON)
        #endif
      }      
      else
      {
        LblReturnFlag = COM_TRUE;
      }
	    #endif 
    }     
  }
  return(LblReturnFlag);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h" 
#endif

/*******************************************************************************
** Function Name        : Com_TxIpduConfirmation                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function added for cyclomatic complexity reduction. **
**                        It performs setting of update bit and updating      **
**                        of repetition counter                               **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LddComTxPduId                                       **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :  Com_GaaTxIpdu             **
**                                                  Com_GaaTxMDTimer          **
**                                                  Com_GaaTxMDTimeout        **
**                                                  Com_GaaTxUpdateBit        **
**                                                  Com_GaaTxMode             **
**                                                  Com_GaaTxIpduStatusBit    **
**                                                  Com_GaaTxReptCount        **
**                        Function(s) invoked    :  SchM_Enter_xxx()          **
**                                                  SchM_Exit_xxx()           **
**                                                  Com_TxClearUpdateBit()    **
*******************************************************************************/
 #if((COM_TX_SIGNAL_UB == STD_ON) || \
     (COM_TX_SIGGROUP_UB == STD_ON) || \
     (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) || \
     (COM_TX_IPDU_REPETITION == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"      
FUNC(boolean, COM_CODE) Com_TxIpduConfirmation(PduIdType LddComTxPduId)
{
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu;
  #if(COM_TX_IPDU_REPETITION == STD_ON)
  /* Pointer to Tx Mode structure */
  P2CONST(Com_TxMode, AUTOMATIC, COM_CONST) LpTxMode;
  /* Local variable to store repetition value */
  uint8 LucReptCount;
  /* Local variable to store repetition sub value */
  uint8 LucReptSubCount;
  #endif
  
  boolean LblReturnValue;
  
  LblReturnValue = COM_TRUE;
  /* Get the pointer to Tx Ipdu */
  LpTxIpdu = &Com_GaaTxIpdu[LddComTxPduId];
  #if(COM_TX_IPDU_MINDELAY_ENABLED == STD_ON)
  /* Check whether minimum delay timer is configured */
  if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_MDT_CONFIG_MASK) != COM_ZERO)
  {
    /* Check whether minimum delay timer is equal to zero */
    if(Com_GaaTxMDTimer[LpTxIpdu->ddTxMDTimerIndex] != (uint16)COM_ZERO)
    {
      #if(COM_TX_INTERRUPT_BASED_PROCESS == STD_OFF)
      SchM_Enter_Com_TX_MDT_PROTECTION_AREA();
      #endif
      /* Load minimum delay timer with the configured value plus one */
      /* #1517 : remove the plus one code for preventing MDT delay */
      /* leave the FEATURE in order to specify major point 
      of both transmit mode */
      /* #2022 MDTForCyclicTransmission related compile error 
	  & incorrect operation is fixed(ref 4.2.1 Com Spec) */
      #if(COM_ENABLE_MDT_CYCLIC == STD_ON)
      Com_GaaTxMDTimer[LpTxIpdu->ddTxMDTimerIndex]  =
      Com_GaaTxMDTimeout[LpTxIpdu->ddTxMDTimerIndex];
      #else
      if((Com_GaaTxIpduStatusBit[LddComTxPduId] 
        & COM_TX_REPT_CONFIRM_HANDLE_MASK) == COM_FALSE)
      {
        Com_GaaTxMDTimer[LpTxIpdu->ddTxMDTimerIndex]  =
        Com_GaaTxMDTimeout[LpTxIpdu->ddTxMDTimerIndex];
      }
      else
      {
        Com_GaaTxIpduStatusBit[LddComTxPduId] 
          &= (uint16)(~COM_TX_REPT_CONFIRM_HANDLE_MASK);
      }
     
      #endif
      #if(COM_TX_INTERRUPT_BASED_PROCESS == STD_OFF)
      SchM_Exit_Com_TX_MDT_PROTECTION_AREA();
      #endif
    }
  }
  #endif
  #if((COM_TX_SIGNAL_UB == STD_ON) || \
          (COM_TX_SIGGROUP_UB == STD_ON))
  /* Check whether update bit needs to be cleared */
  if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_UB_CONFIG_MASK) != COM_ZERO)
  {
    if(Com_GaaTxUpdateBit[LpTxIpdu->ddTxIpduUbIndex].ucUBConfig ==
      COM_TX_IPDU_UB_CONFIRM_CONFIG_MASK)
    {
      Com_TxClearUpdateBit(LpTxIpdu,
        Com_GaaTxPduInfoPtr[LddComTxPduId].SduDataPtr);
    }
  }
  #endif
  
  #if(COM_TX_IPDU_REPETITION == STD_ON)
  /* Get the pointer to true Tx mode */
  LpTxMode = &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex];
  #if(COM_TX_IPDU_TMS == STD_ON)
  /* Check whether TMS is configured */
  if((Com_GaaTxIpduStatusBit[LddComTxPduId] & COM_TX_TMS_STATUS_MASK) ==
                                                                  COM_FALSE)
  {
    LpTxMode = 
    &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex+(PduIdType)COM_ONE];
  }
  #endif /* #if(COM_TX_IPDU_TMS == STD_ON) */

  /* Check whether repetition count is configured */
  if(LpTxMode->ucReptCount != COM_ZERO)
  {
    /* #1518 : Clear the status bit for repetition count and prevent updating repetition count */
    #if(COM_MAINFUNC_BASED_TRANSMIT == STD_OFF)
    if((Com_GaaTxIpduStatusBit[LddComTxPduId] & COM_TX_REPT_COUNT_HANDLE_MASK) != COM_FALSE)
    {
      #if(COM_TX_INTERRUPT_BASED_PROCESS == STD_OFF)
      SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
      #endif
      Com_GaaTxIpduStatusBit[LddComTxPduId] &= 
                                           (uint16)(~COM_TX_REPT_COUNT_HANDLE_MASK);
      #if(COM_TX_INTERRUPT_BASED_PROCESS == STD_OFF)
      SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();  
      #endif
      LblReturnValue = COM_FALSE;
    }
    else
    #endif
    {
      /* Get the repetition count value to local variable */
      LucReptCount = Com_GaaTxReptCount[LpTxIpdu->ddTxReptIndex];
      LucReptSubCount = Com_GaaTxReptSubCount[LpTxIpdu->ddTxReptIndex];
      /* Check whether repetition count value is greater than zero */
      if(LucReptCount != COM_ZERO)
      {
        /* Decrement the repetition count */
        LucReptCount--;
        /* Set the repetition count */
        Com_GaaTxReptCount[LpTxIpdu->ddTxReptIndex] = LucReptCount;
        /* Check whether repetition count is not equal to zero */
        if((LucReptCount != COM_ZERO) || (LucReptSubCount != COM_ZERO))
        {
          LblReturnValue = COM_FALSE;
          /* Reset the Tx Request Bit */
          #if(COM_TX_INTERRUPT_BASED_PROCESS == STD_OFF)
          SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
          #endif
          Com_GaaTxIpduStatusBit[LddComTxPduId] &= 
                                               (uint16)(~COM_TX_REQ_STATUS_MASK);
          #if(COM_TX_INTERRUPT_BASED_PROCESS == STD_OFF)
          SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();            
          #endif
        }
      }
    }
  } /* Check whether repetition count is configured */
  #endif
  return(LblReturnValue);    
}
#define COM_STOP_SEC_CODE
#include "MemMap.h" 
#endif

/*******************************************************************************
** Function Name        : Com_TransIpduCounter                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function added for cyclomatic complexity reduction. **
**                        It sets the next expected counter value             **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpTxIpdu                                            **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaTxIpduCounter       **
**                                                 Com_GaaTxIpduCountVal      **
**                                                 Com_GaaCounterStatusFlag   **
**                        Function(s) invoked    : SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
*******************************************************************************/
#if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE)
         Com_TransIpduCounter(P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST)LpTxIpdu)
{
  P2CONST(Com_TxIpduCounter, AUTOMATIC, COM_CONST) LpTxIpduCounter;
  uint8 LucTxIpduCountValue;

  LpTxIpduCounter = &Com_GaaTxIpduCounter[LpTxIpdu->ddTxIpduCounter];
  /* Check whether Tx I-PDU counter is configured */
  if(LpTxIpdu->ddTxIpduCounter != COM_INVALID_TXID_PARAM)
  {
    /* Get the present counter data */
    LucTxIpduCountValue = 
                      Com_GaaTxIpduCountVal[LpTxIpduCounter->ucTxIpduCountData];
    if(COM_COUNTER_E_PENDING == 
                          Com_GaaCounterStatusFlag[LpTxIpdu->ddTxIpduCounter])
    {
      /* Decrement I-PDU count value */
      LucTxIpduCountValue--;
      SchM_Enter_Com_IPDU_COUNTER_PROTECTION();
      Com_GaaCounterStatusFlag[LpTxIpdu->ddTxIpduCounter] =COM_COUNTER_TRIGTX;
      SchM_Exit_Com_IPDU_COUNTER_PROTECTION();
    }
    else if(Com_GaaCounterStatusFlag[LpTxIpdu->ddTxIpduCounter] 
      == COM_COUNTER_TRIGTX)
    {
      /* Increment I-PDU count value */
      LucTxIpduCountValue++;
      Com_GaaCounterStatusFlag[LpTxIpdu->ddTxIpduCounter] = COM_ZERO;
      
    }
    /* Apply wrap around mask to the counter data */
    LucTxIpduCountValue &= LpTxIpduCounter->ucTxIpduCntWrpMask;
  }
  else
  {
    LucTxIpduCountValue = LpTxIpduCounter->ucTxIpduCntWrpMask;
  }
   /* Enter protection area */
  SchM_Enter_Com_IPDU_COUNTER_PROTECTION();
  /* Load present counter data in buffer */
  Com_GaaTxIpduCountVal[LpTxIpduCounter->ucTxIpduCountData] 
    = LucTxIpduCountValue;
  /* Exit Critical Area */
  SchM_Exit_Com_IPDU_COUNTER_PROTECTION();
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/* polyspace:end<RTE: NIV : Not a defect : No Action Planned > initialized variable */
/* polyspace:end<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : No Action Planned > configured memory access index */
/* polyspace:end<RTE: STD_LIB : Not a defect : No Action Planned> configured & generated memory address */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
