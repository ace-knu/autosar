/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Com_TxSig.c                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Com Module                                            **
**                                                                            **
**  PURPOSE   : Provision of send, invalidate and update functions and their  **
**              functionality.                                                **
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
** 2.2.3     08-Dec-2017   Chan Kim    Internal Redmine #10849, #10851, #10918**
** 2.2.0     16-Apr-2017   Chan Kim    Internal Redmine #7861, #7707, #7525,  **
**                                     #7709                                  **
** 2.1.9     20-Mar-2017   Chan Kim    Internal Redmine #7851                 **
** 2.1.7     30-Nov-2016   Chan Kim    Internal Redmine #6807                 **
** 2.1.0     25-May-2016   Chan Kim    Internal Redmine #4998                 **
** 2.0.8     12-Feb-2016   Chan Kim    Internal Redmine #4158                 **
** 2.0.3     10-Dec-2015   Chan Kim    Internal Redmine #3641                 **
** 2.0.3     24-Nov-2015   Chan Kim    Internal Redmine #3544, #3535          **
** 1.0.16    27-Feb-2015   Chan Kim    Internal Redmine #2202                 **
** 1.0.15    09-Feb-2015   Chan Kim    Internal Redmine #2142                 **
** 1.0.11    20-Mar-2014   Chan Kim    Internal Redmine #644, #647            **
** 1.0.10    03-Mar-2014   Chan Kim    Internal Redmine #644, #647, #655      **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Com.h"          /* Com header file */
#include "Com_Main.h"     /* Com Main header file */
#include "Com_TxIpdu.h"   /* Com Tx I-PDU header file */
#include "Com_Pack.h"     /* Com Pack header file */
#include "Com_Invalid.h"  /* Com Invalid header file */
#include "SchM_Com.h"     /* SchM Com header file */
#include "Com_Error.h"    /* Com Error header file */
#if(COM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"          /* Det header file */
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version Information */
#define COM_TXSIG_C_AR_RELEASE_MAJOR_VERSION  4
#define COM_TXSIG_C_AR_RELEASE_MINOR_VERSION  0
#define COM_TXSIG_C_AR_RELEASE_REVISION_VERSION  3

/* Software version information */
#define COM_TXSIG_C_SW_MAJOR_VERSION  2
#define COM_TXSIG_C_SW_MINOR_VERSION  2

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if(COM_AR_RELEASE_MAJOR_VERSION != COM_TXSIG_C_AR_RELEASE_MAJOR_VERSION)
  #error "Com_TxSig.c : Mismatch in Com Specification Major Version"
#endif

#if(COM_AR_RELEASE_MINOR_VERSION != COM_TXSIG_C_AR_RELEASE_MINOR_VERSION)
  #error "Com_TxSig.c : Mismatch in Com Specification Minor Version"
#endif

#if(COM_AR_RELEASE_REVISION_VERSION != \
  COM_TXSIG_C_AR_RELEASE_REVISION_VERSION)
  #error "Com_TxSig.c : Mismatch in Com Specification Revision Version"
#endif

#if(COM_SW_MAJOR_VERSION != COM_TXSIG_C_SW_MAJOR_VERSION)
  #error "Com_TxSig.c : Mismatch in Com Software Major Version"
#endif

#if(COM_SW_MINOR_VERSION != COM_TXSIG_C_SW_MINOR_VERSION)
  #error "Com_TxSig.c : Mismatch in Com Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/* polyspace:begin<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:begin<RTE: OBAI : Not a defect : No Action Planned > configured memory access index */

/*******************************************************************************
** Function Name        : Com_SendSignal                                      **
**                                                                            **
** Service ID           : 0x0A                                                **
**                                                                            **
** Description          : This function updates the signal object identified  **
**                        by SignalId with data referenced by SignalDataPtr.  **
**                        If the signal has the "triggered" transfer property,**
**                        the associated I-PDU will be transmitted immediately**
**                        after the update, except when the signal is packed  **
**                        into an I-PDU with "periodic" transmission mode; in **
**                        this case, no transmission is initiated by the call **
**                        to this service. If the signal has the "pending"    **
**                        transfer property, no transmission is caused by the **
**                        update. All the notification flags will be reset.   **
**                                                                            **
* Sync/Async           : Asynchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same signal.                  **
**                        Reentrant for different signals.                    **
**                                                                            **
** Input Parameters     : SignalId, SignalDataPtr                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaTxSignal            **
**                                                 Com_GaaTxPack              **
**                                                 Com_GaaTxIpdu              **
**                                                 Com_GaaTxTPIpdu            **
**                                                 Com_GaaTxTPStatus          **
**                                                 Com_GaaTxIpduStatus        **
**                                                 Com_GaaValidateValue       **
**                        Function(s) invoked    : Det_ReportError()          **
**                                                 SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
**                                                 Com_SendSigTMS()           **
**                                                 Com_TxRequest()            **
**                                                 Com_ShadowBufferUpdate()   **
**                                                 pWrFuncPtr                 **
**                                                 pValidateDataPtr           **
*******************************************************************************/
#if((COM_TX_SIGNAL == STD_ON) || (COM_TX_SIGGROUP == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, COM_CODE) Com_SendSignal (Com_SignalIdType SignalId,
  P2CONST(void, AUTOMATIC, COM_CONST) SignalDataPtr)
{
  /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Initialize return value to E_OK */
  #if((COM_DEV_ERROR_DETECT == STD_ON)|| \
  ((COM_TX_SIGGROUP == STD_ON)&&(COM_TX_SIGNAL == STD_ON)))
  LucReturnValue = (uint8)E_OK;
  #endif
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_SENDSIGNAL);
  /* Check whether signal ID is out of range */
  COM_DET_TX_SIGNALID_RANGE_CHECK_FLAG(COMSERVICEID_SENDSIGNAL);
  /* Check whether signal data pointer is equal to NULL */
  COM_DET_SIGNAL_DATA_PTR(COMSERVICEID_SENDSIGNAL);
  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif /* COM_DEV_ERROR_DETECT */
  {
    #if((COM_TX_SIGGROUP == STD_ON)&&(COM_TX_SIGNAL == STD_ON))
    /* If the Id is actually a signal */
    if(SignalId < COM_TX_SIG_GRPSIG_BOUNDARY)
    #endif
    {
      #if (COM_TX_SIGNAL == STD_ON)
      LucReturnValue = Com_SendSignalService(SignalId, SignalDataPtr);
      #endif
    }
    #if((COM_TX_SIGGROUP == STD_ON)&&(COM_TX_SIGNAL == STD_ON))
    else
    #endif
    {
      #if(COM_TX_SIGGROUP == STD_ON)
      /* Internal function to copy the data into I-PDU buffer 
      and check conditions to initiate transmissions */
      Com_UpdateShadowSignalService(SignalId - COM_TX_SIG_GRPSIG_BOUNDARY, 
                                                                 SignalDataPtr);
      #endif
    }
  }
  /* Return value */
  return(LucReturnValue);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_SendDynSignal                                   **
**                                                                            **
** Service ID           : 0x21                                                **
**                                                                            **
** Description          : The service Com_SendDynSignal updates the signal    **
**                        object identified by SignalId with the signal       **
**                        referenced by the SignalDataPtr parameter.          **
**                                                                            **
* Sync/Async           : Asynchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same signal.                  **
**                        Reentrant for different signals.                    **
**                                                                            **
** Input Parameters     : SignalId, SignalDataPtr, Length                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : LucReturnValue                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaTxSignal            **
**                                                 Com_GaaTxIpdu              **
**                                                 Com_GaaTxTPIpdu            **
**                                                 Com_GaaTxTPStatus          **
**                                                 Com_GaaTxPack              **
**                                                 Com_GaaTxDynSigLength      **
**                                                 Com_GaaTxIpduStatus        **
**                                                 Com_GaaValidateValue       **
**                        Function(s) invoked    : Det_ReportError()          **
**                                                 SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
**                                                 Com_TxRequest()            **
**                                                 pWrFuncPtr                 **
**                                                 pFilterFuncPtr             **
**                                                 pValidateDataPtr           **
*******************************************************************************/
#if(COM_TX_DYN_SUPPORT == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, COM_CODE) Com_SendDynSignal(Com_SignalIdType SignalId,
  P2CONST(void, AUTOMATIC, COM_CONST) SignalDataPtr, uint16 Length)
{
  /* Pointer to Tx signal structure */
  P2CONST(Com_TxSignal, AUTOMATIC, COM_CONST) LpTxSignal;
  /* Pointer to Tx pack structure */
  P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack;
  /* Pointer to Tx Ipdu */
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu;
  /* #2142 : separate DYN PDU from TP */
  #if(COM_TX_TP_SUPPORT == STD_ON)
  /* Pointer to TP Ipdu structure */
  P2CONST(Com_TxTPIpdu, AUTOMATIC, COM_CONST) LpTxTPIpdu;
  #endif
  /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Local variable to store signal config */
  uint8 LucSigConfig;
  /* Local variable to store signal property */
  uint8 LucSigProperty;
  #if(COM_TX_SIGNAL_TRIGONCHANGE == STD_ON)
  boolean LblReturnFlag = COM_TRUE;
  #endif

  /* Initialize return value to E_OK */
  LucReturnValue = (uint8)E_OK;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_SENDDYNSIGNAL);
  /* Check whether signal ID is out of range */
  COM_DET_TX_SIGNALID_RANGE_CHECK_FLAG(COMSERVICEID_SENDDYNSIGNAL);
  /* Check whether signal data pointer is equal to NULL */
  COM_DET_SIGNAL_DATA_PTR(COMSERVICEID_SENDDYNSIGNAL);
  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif /* COM_DEV_ERROR_DETECT */
  {
    /* Get the pointer to Tx signal structure */
    LpTxSignal = &Com_GaaTxSignal[SignalId];
    /* Get the pointer to Tx IPdu structure */
    LpTxIpdu =  &Com_GaaTxIpdu[LpTxSignal->ddTxIpduIndex];

    /* Get the pointer toTxPack structure */
    LpTxPack = &(Com_GaaTxPack[LpTxSignal->ddTxPackIndex]);
    if(LpTxPack->ddSigTypeOrSize < (PduLengthType)Length)
    {
      LucReturnValue = (uint8)E_NOT_OK;
    }
    if(LucReturnValue != (uint8)E_NOT_OK)
    {
      /* #2142 : separate DYN PDU from TP */
      if(LpTxIpdu->ucIpduType == COM_DYN_IPDU)
      {
        #if(COM_TX_TP_SUPPORT == STD_ON)    
        if(LpTxIpdu->ucTxTPRef != COM_INVALID_NONE)
        {
          /* Get the pointer to TP structure  */
          LpTxTPIpdu = &Com_GaaTxTPIpdu[LpTxIpdu->ucTxTPRef];
          
          if(((Com_GaaTxTPStatus[LpTxTPIpdu->ucTxTPStatusRef]) & 
          (LpTxTPIpdu->ucTxTPStatusMask)) != COM_ZERO)
          {
            LucReturnValue = (uint8)COM_BUSY;
          }
        }
        if(LucReturnValue != (uint8)COM_BUSY)        
        #endif      
        {
          /* Setting the length */
          Com_GaaTxDynSigLength[LpTxPack->ddTxIpduDynLegthRef] = 
          (PduLengthType)Length;
          /* Invoke write function to pack data referred by SignalDataPtr to I-PDU
          buffer */
          (void)Com_PackRequestWrite(LpTxPack, SignalDataPtr);
          /* Get the signal configuration into local variable */
          LucSigConfig = LpTxSignal->ucTxSigConfig;

          #if(COM_TX_SIGNAL_UB == STD_ON)
          /* Check whether update bit is configured */
          if((LucSigConfig & COM_TX_SIGNAL_UB_CONFIG_MASK) != COM_FALSE)
          {
            /* Enter protection area */
            SchM_Enter_Com_TX_IPDU_BUFFER_PROTECTION_AREA();
            /* Set update bit to one */
            *(LpTxSignal->pUbit) |= LpTxSignal->ucUbitMask;
            /* Exit protection area */
            SchM_Exit_Com_TX_IPDU_BUFFER_PROTECTION_AREA();
          }
          #endif
          
          /* Set return value to COM_SERVICE_NOT_AVAILABLE */
          LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;

          #if(COM_TX_SIGNAL_TRIGONCHANGE == STD_ON)
          /* Mask the signal configuration to get signal property */
          LucSigProperty = LucSigConfig & COM_TX_SIG_PROPERTY_CONFIG_MASK;
          if((LucSigProperty >= COM_TX_SIG_TRIGGERED_ON_CHANGE))
          {
            /* Check whether old value is equal to new value or not */
            if(Com_GaaValidateValue[LpTxPack->ddSignalType].pValidateDataPtr 
              != NULL_PTR)
            {
              /* polyspace:begin<RTE: COR : Not a defect : No Action Planned > configured memory access index */
              LblReturnFlag = ((Com_GaaValidateValue[LpTxPack->ddSignalType].pValidateDataPtr)
                (SignalDataPtr,LpTxSignal->pSignalBuffer,
                LpTxPack->ddSigTypeOrSize));
              /* polyspace:end<RTE: COR : Not a defect : No Action Planned > configured memory access index */
            }
          }
          #endif
          
          /* Check whether Tx I-PDU is enabled */
          if(Com_GaaTxIpduStatus[LpTxSignal->ddTxIpduIndex] != (PduIdType)COM_ZERO)
          {
            /* Set return value to E_OK */
            LucReturnValue = (uint8)E_OK;
            /* Mask the signal configuration to get signal property */
            LucSigProperty = LucSigConfig & COM_TX_SIG_PROPERTY_CONFIG_MASK;
            #if(COM_TX_SIGNAL_TRIGONCHANGE == STD_ON)
            if(LblReturnFlag == COM_TRUE)
            #endif
            {
              /* Check whether signal transfer property is triggered or
                 transmission mode selection is configured */                
              if(LucSigProperty  > COM_TX_SIG_PENDING_PROPERTY)
              {
                #if ((COM_TX_IPDU_TMS == STD_ON) || \
                (COM_TX_IPDU_REPETITION == STD_ON) || \
                ((COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) \
                && (COM_TX_IPDU_GW == STD_ON))|| \
                (COM_TX_IPDU_GW == STD_ON) || \
                (COM_TX_IPDU_DM == STD_ON))
                LucReturnValue = Com_TxRequest(LpTxSignal->ddTxIpduIndex, 
                  LucSigConfig);
                #else
                LucReturnValue = Com_TxRequest(LpTxSignal->ddTxIpduIndex);
                #endif
              } /* signal transfer property is triggered */
            } /* Check whether Tx I-PDU group is enabled */
          }
        }
      }
      else
      {
        /* Set return value to "E_NOT_OK" */
        LucReturnValue = (uint8)E_NOT_OK;      
      }
    } /* Check whether any development error has occurred */
  }
  /* Return value */
  return(LucReturnValue);
}

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_UpdateShadowSignal                              **
**                                                                            **
** Service ID           : 0x0C                                                **
**                                                                            **
** Description          : This function updates the signal, which belongs to  **
**                        a signal group, with the data referenced by         **
**                        SignalDataPtr. The update of the signal data is     **
**                        done in the shadow buffer, not in the I-PDU. Sign   **
**                        extension and byte swapping are performed as the    **
**                        signal is inserted into the shadow buffer.          **
**                                                                            **
* Sync/Async           : Synchronous                                          **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same signal.                  **
**                        Reentrant for different signals.                    **
**                                                                            **
** Input Parameters     : SignalId, SignalDataPtr                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :  None                      **
**                        Function(s) invoked    :  Det_ReportError()         **
**                                                  Com_ShadowBufferUpdate()  **
*******************************************************************************/
#if(COM_TX_SIGGROUP == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"

FUNC(void, COM_CODE) Com_UpdateShadowSignal
           (Com_SignalIdType SignalId,
           P2CONST(void, AUTOMATIC, COM_CONST) SignalDataPtr)
{
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Initialize error flag to false */
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_UPDATESHADOWSIGNAL);
  /* Check whether signal ID is out of range */
  COM_DET_SIGNALID_TX_USS_RANGE_CHECK_FLAG(COMSERVICEID_UPDATESHADOWSIGNAL);  
  /* Check whether signal data pointer is equal to NULL */
  COM_DET_SIGNAL_DATA_PTR(COMSERVICEID_UPDATESHADOWSIGNAL);
  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif
  {
    /* Update shadow buffer */
    Com_UpdateShadowSignalService(SignalId - COM_TX_SIG_GRPSIG_BOUNDARY, 
                                                                SignalDataPtr);
  }
  /* Check whether any development error has occurred */
}

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_InvalidateSignal                                **
**                                                                            **
** Service ID           : 0x10                                                **
**                                                                            **
** Description          : Sender side AUTOSAR Software Component indicates    **
**                        via the RTE to AUTOSAR COM that is not able to      **
**                        provide a valid value for the corresponding signal. **
**                        This function replaces the actual value with the    **
**                        invalid value for the signal.                       **
**                                                                            **
* Sync/Async           : Asynchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same signal.                  **
**                        Reentrant for different signals.                    **
**                                                                            **
** Input Parameters     : SignalId                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :  Com_GaaTxSignal           **
**                        Function(s) invoked    :  Com_SendSignal()          **
**                                                  Det_ReportError()         **
*******************************************************************************/
#if((COM_TX_SIGNAL_INVALID == STD_ON) && (COM_TX_SIGNAL == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, COM_CODE) Com_InvalidateSignal(Com_SignalIdType SignalId)
{
  /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Initializing return value to E_OK */
  LucReturnValue = (uint8)E_OK;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_INVALIDATESIGNAL);
  /* Check whether signal ID is out of range */
  COM_DET_TX_SIGNALID_RANGE_CHECK_FLAG(COMSERVICEID_INVALIDATESIGNAL);

  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif
  {
    #if(COM_DEV_ERROR_DETECT == STD_ON)
    /* Check whether Common pointer is NULL */
    COM_DET_COMMON_PTR_PARAM_CHECK_FLAG(Com_GaaTxSignal[SignalId].pInvalidData,
    COMSERVICEID_INVALIDATESIGNAL);
    if(LucReturnValue == (uint8)E_OK)
    #endif
    {
      /* Invoke Com_SendSignal() function with signal ID and invalid data
         value as input parameters */
      LucReturnValue = Com_SendSignal(SignalId, Com_GaaTxSignal[SignalId].pInvalidData);
    }
  }
  /* Return value */
  return(LucReturnValue);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_InvalidateShadowSignal                          **
**                                                                            **
** Service ID           : 0x16                                                **
**                                                                            **
** Description          : Sender side AUTOSAR Software Component indicates    **
**                        via the RTE to AUTOSAR COM that is not able to      **
**                        provide a valid value for the corresponding signal. **
**                        The RTE has to call this function for each signal   **
**                        inside signal group.This function replaces the      **
**                        actual value with the invalid value for the signal  **
**                        in the signal group.                                **
**                                                                            **
* Sync/Async           : Synchronous                                          **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same signal.                  **
**                        Reentrant for different signals.                    **
**                                                                            **
** Input Parameters     : SignalId                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :  Com_GaaTxSigInGrp         **
**                        Function(s) invoked    :  Com_UpdateShadowSignal()  **
**                                                  Det_ReportError()         **
*******************************************************************************/

#if(COM_TX_SIGINGROUP_INVALID == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_InvalidateShadowSignal
  (Com_SignalIdType SignalId)
{
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Initialize DET error flag to false */
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_INVALIDATESHADOWSIGNAL);
  /* Check whether signal ID is out of range */
  COM_DET_SIGNALID_TX_USS_RANGE_CHECK_FLAG(COMSERVICEID_INVALIDATESHADOWSIGNAL); 
  
  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif /* #if(COM_DEV_ERROR_DETECT == STD_ON) */
  {
    #if(COM_DEV_ERROR_DETECT == STD_ON)
    /* Check whether Common pointer is NULL */
    COM_DET_COMMON_PTR_CHECK_FLAG(Com_GaaTxSigInGrp
    [SignalId - COM_TX_SIG_GRPSIG_BOUNDARY].pInvalidData
    , COMSERVICEID_INVALIDATESHADOWSIGNAL);
    /* Check whether any development error has occurred */
    if(LucReturnValue == (uint8)E_OK)
    #endif /* #if(COM_DEV_ERROR_DETECT == STD_ON) */    
    {
      /* Invoke Com_UpdateShadowSignal() function with signal ID and
      invalid data value as input parameters */
      Com_UpdateShadowSignal(SignalId,
        Com_GaaTxSigInGrp[SignalId - COM_TX_SIG_GRPSIG_BOUNDARY].pInvalidData);
    }
  }
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_InvalidateSignalGroup                           **
**                                                                            **
** Service ID           : 0x1B                                                **
**                                                                            **
** Description          : Sender side AUTOSAR Software Component indicates    **
**                        via the RTE to AUTOSAR COM that is not able to      **
**                        provide a valid value for the corresponding signal  **
**                        group. After Invalidating the actual signal group   **
**                        data a Com_SendSignalGroup is performed internally. **
**                                                                            **
* Sync/Async           : Asynchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same signal group.            **
**                        Reentrant for different signal groups.              **
**                                                                            **
** Input Parameters     : SignalGroupId                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)   : Com_GaaTxSigGroup            **
**                                               Com_GaaTxGroupSignal         **
**                        Function(s) invoked  : Com_InvalidateShadowSignal() **
**                                               Det_ReportError()            **
**                                               Com_SendSignalGroup()        **
*******************************************************************************/
#if(COM_TX_SIGINGROUP_INVALID == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, COM_CODE) Com_InvalidateSignalGroup
                                           (Com_SignalGroupIdType SignalGroupId)
{
  #if(COM_TX_TP_SUPPORT == STD_ON)
  /* Pointer to Tx Ipdu */
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu; 
  /* Pointer to TP Ipdu structure */
  P2CONST(Com_TxTPIpdu, AUTOMATIC, COM_CONST) LpTxTPIpdu;
  #endif
  /* Pointer to Tx signal group structure */
  P2CONST(Com_TxSigGrp, AUTOMATIC, COM_CONST) LpTxSigGrp;
  /* Pointer to Tx group signal structure */
  P2CONST(Com_TxGroupSignal, AUTOMATIC, COM_CONST)LpTxGroupSignal;
  /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Local variable to store group signal count */
  uint8 LucGroupSignalCount;

  Com_SignalIdType LddTxGroupSignalIndex;
  /* Initialize return value to COM_SERVICE_NOT_AVAILABLE */
  LucReturnValue = (uint8)E_OK;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_INVALIDATESIGNALGROUP);
  /* Check whether signal group ID is out of range */
  COM_DET_TXSIGNALGROUPID_RANGE_CHECK_FLAG(COMSERVICEID_INVALIDATESIGNALGROUP);
  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif /* COM_DEV_ERROR_DETECT */
  {
    /* Get the pointer to Tx signal group structure */
    LpTxSigGrp = &Com_GaaTxSigGroup[SignalGroupId];
    
    #if(COM_TX_TP_SUPPORT == STD_ON)
   /* Get the pointer to Tx IPdu structure */
    LpTxIpdu =  &Com_GaaTxIpdu[LpTxSigGrp->ddTxIpduIndex];
    
    if(LpTxIpdu->ucTxTPRef != COM_INVALID_NONE)
    {
      /* Get the pointer to TP structure  */
      LpTxTPIpdu = &Com_GaaTxTPIpdu[LpTxIpdu->ucTxTPRef];
      if((Com_GaaTxTPStatus[LpTxTPIpdu->ucTxTPStatusRef] 
      & (LpTxTPIpdu->ucTxTPStatusMask)) != COM_ZERO)
      {
        LucReturnValue = (uint8)COM_BUSY;
      }
    }
    if(LucReturnValue == (uint8)E_OK)
    #endif
    {
      /* Get the number of Group Signals */
      LucGroupSignalCount = LpTxSigGrp->ucGroupSignalCount;
      /* Get the pointer to Group Signal */
      LddTxGroupSignalIndex = LpTxSigGrp->ddTxGrpSigIndex;
      LpTxGroupSignal =
                    &Com_GaaTxGroupSignal[LddTxGroupSignalIndex];
      while(LucGroupSignalCount != COM_ZERO)
      {
        /*Invoke Com_InvalidateShadowSignal() function with Signal Id as input
        parameter*/
        Com_InvalidateShadowSignal(LpTxGroupSignal->ddSignalId);

        LddTxGroupSignalIndex++;
        LpTxGroupSignal =
                    &Com_GaaTxGroupSignal[LddTxGroupSignalIndex];
        LucGroupSignalCount--;
      }
      /* Invoke Com_SendSignalGroup() function with SignalGroup ID*/
      LucReturnValue = Com_SendSignalGroup(SignalGroupId);
    }
  }
  return(LucReturnValue);
}

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_SendSignalGroup                                 **
**                                                                            **
** Service ID           : 0x0D                                                **
**                                                                            **
** Description          : This function copies the contents of the associated **
**                        shadow buffer to the associated I-PDU.              **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same signal group.            **
**                        Reentrant for different signal groups.              **
**                                                                            **
** Input Parameters     : SignalGroupId                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : All signals should be updated in the shadow buffer  **
**                        by the call of Com_UpdateShadowSignal().            **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaTxSigGroup          **
**                                                 Com_GaaTxPack              **
**                                                 Com_GaaTxSigGrpModeSel     **
**                                                 Com_GaaFilterStatus        **
**                                                 Com_GaaTxIpduStatus        **
**                        Function(s) invoked    : SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
**                                                 Det_ReportError()          **
**                                                 Com_PackAndValidateSigGrp()**
**                                                 Com_TxRequest()            **
*******************************************************************************/
#if(COM_TX_SIGGROUP == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, COM_CODE) Com_SendSignalGroup (Com_SignalGroupIdType SignalGroupId)
{
  /* Pointer to Tx pack structure */
  P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack;
  /* Pointer to Tx signal Group structure */
  P2CONST(Com_TxSigGrp, AUTOMATIC, COM_CONST) LpTxSigGrp;
  #if(COM_TX_TP_SUPPORT == STD_ON)
  /* Pointer to Tx Ipdu */
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu; 
  /* Pointer to TP Ipdu structure */
  P2CONST(Com_TxTPIpdu, AUTOMATIC, COM_CONST) LpTxTPIpdu;
  #endif
  /* Local variable to store return value */
  uint8 LucReturnValue = (uint8)E_OK;
  /* Local variable to store signal group config */
  uint8 LucSigGrpConfig;
  /* Local variable to store signal group property */
  uint8 LucSigGrpProperty;
  #if(COM_TX_SIGGROUP_TRIGONCHANGE == STD_ON)
  boolean LblReturnFlag = COM_TRUE;
  #endif
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /*  return value to COM_SERVICE_NOT_AVAILABLE */
  LucReturnValue = (uint8)E_OK;

  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_SENDSIGNALGROUP);
  /* Check whether signal group ID is out of range */
  COM_DET_TXSIGNALGROUPID_RANGE_CHECK_FLAG(COMSERVICEID_SENDSIGNALGROUP);
  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif /* COM_DEV_ERROR_DETECT */
  {
  
    /* Get the pointer to Tx signal group structure */
    LpTxSigGrp = &Com_GaaTxSigGroup[SignalGroupId];
    /* #7525 */
    #if((COM_ENABLE_SIGNALGROUP_ARRAY_API == STD_ON) && (COM_TX_SIGINGROUP_ARRAY_ACCESS == STD_ON))
    if(LpTxSigGrp->blArrayAccess == COM_TRUE)
    {
      /* AUTOSAR dose not define the behavior of illegally calling*/
      /* Discard the request */
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;
    }  

    if(LucReturnValue == (uint8)E_OK)
    #endif
    {
    
      #if(COM_TX_TP_SUPPORT == STD_ON)
     /* Get the pointer to Tx IPdu structure */
      LpTxIpdu =  &Com_GaaTxIpdu[LpTxSigGrp->ddTxIpduIndex];
      
      if(LpTxIpdu->ucTxTPRef != COM_INVALID_NONE)
      {
        /* Get the pointer to TP structure  */
        LpTxTPIpdu = &Com_GaaTxTPIpdu[LpTxIpdu->ucTxTPRef];
        if((Com_GaaTxTPStatus[LpTxTPIpdu->ucTxTPStatusRef] 
        & (LpTxTPIpdu->ucTxTPStatusMask)) != COM_ZERO)
        {
          LucReturnValue = (uint8)COM_BUSY;
        }
      }
     
      if(LucReturnValue == (uint8)E_OK)
      #endif
      {
        LpTxPack = &(Com_GaaTxPack[LpTxSigGrp->ddTxSigGrpPackIndex]);
        /* Get the signal group configuration */
        LucSigGrpConfig = LpTxSigGrp->ucTxSigGrpConfig;
        /* Extract the signal property - first 5 bits of signal configuration */
        LucSigGrpProperty = LucSigGrpConfig & COM_TX_SIG_PROPERTY_CONFIG_MASK;
        /* Invoke Com_PackAndValidateSigGrp() function to pack and validate signal
        group data from shadow buffer to I-PDU buffer */
        /* #7709 start */
        #if(COM_TX_SIGGROUP_TRIGONCHANGE == STD_ON)
        if(LucSigGrpProperty >= COM_TX_SIG_TRIGGERED_ON_CHANGE)
        {
          #if(COM_TX_SIGGROUP_GROUPSIG_TRIGONCHANGE == STD_ON)
          /* polyspace:begin<RTE: NIV : Not a defect : No Action Planned > initialized variable */
          if(LpTxSigGrp->pOnChangeStatus != NULL_PTR)
          {
            if(*(LpTxSigGrp->pOnChangeStatus) != COM_ZERO)
            {
              (void)Com_PackSigGrp(LpTxPack, LpTxSigGrp->pShadowBuffer, LpTxPack->pWrBuffer, LpTxSigGrp->pMaskingBuffer);
              *(LpTxSigGrp->pOnChangeStatus) = COM_ZERO;
            }
            else
            {
              LblReturnFlag = COM_FALSE;
            }
          }
          else
          /* polyspace:end<RTE: NIV : Not a defect : No Action Planned > initialized variable */
          #endif
          {
            LblReturnFlag = Com_PackAndValidateSigGrp(LpTxPack, LpTxSigGrp->pShadowBuffer, LpTxPack->pWrBuffer, LpTxSigGrp->pMaskingBuffer);                    
          }
        }
        else
        {
          (void)Com_PackSigGrp(LpTxPack, LpTxSigGrp->pShadowBuffer, LpTxPack->pWrBuffer, LpTxSigGrp->pMaskingBuffer);
        }
        #else
        (void)Com_PackSigGrp(LpTxPack, LpTxSigGrp->pShadowBuffer, LpTxPack->pWrBuffer, LpTxSigGrp->pMaskingBuffer);
        /* #7709 end */	
        #endif
        #if(COM_TX_SIGGROUP_UB == STD_ON)
        /* Check whether update bit is configured */
        if((LucSigGrpConfig & COM_TX_SIGNAL_UB_CONFIG_MASK) != COM_FALSE)
        {
          /* Enter protection area */
          SchM_Enter_Com_TX_IPDU_BUFFER_PROTECTION_AREA();
          /* Set the update bit */
         
          *(LpTxSigGrp->pUbit) |= LpTxSigGrp->ucUbitMask;
          /* Exit protection area */
          SchM_Exit_Com_TX_IPDU_BUFFER_PROTECTION_AREA();
        }
        #endif
        #if(COM_TX_SIGGROUP_TMS == STD_ON)
        LucSigGrpConfig = Com_TxSigGrpModeSelect(LpTxSigGrp);
        #endif
        /* Set return value to COM_SERVICE_NOT_AVAILABLE */
        LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;
        /* Check whether I-PDU group is started */
        if(Com_GaaTxIpduStatus[LpTxSigGrp->ddTxIpduIndex] != (PduIdType)COM_ZERO)
        {
          /* Set return value to E_OK */
          LucReturnValue = (uint8)E_OK;
          #if(COM_TX_SIGGROUP_TRIGONCHANGE == STD_ON)
          if(LblReturnFlag == COM_TRUE)
          #endif
          {
            if((LucSigGrpProperty) > COM_TX_SIG_PENDING_PROPERTY)
            {
              #if ((COM_TX_IPDU_TMS == STD_ON) || \
              (COM_TX_IPDU_REPETITION == STD_ON) || \
              ((COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) \
              && (COM_TX_IPDU_GW == STD_ON))|| \
              (COM_TX_IPDU_GW == STD_ON) || \
              (COM_TX_IPDU_DM == STD_ON))
              (void)Com_TxRequest(LpTxSigGrp->ddTxIpduIndex, LucSigGrpConfig);
              
              #else
              (void)Com_TxRequest(LpTxSigGrp->ddTxIpduIndex);
              #endif
            } /* Check whether signal group property is triggered */
          } /* Check whether I-PDU group is started */
        }
      }
    }
  } /* DET Check */
  /* Return value */
  return(LucReturnValue);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/* #7525 #7709 start */
/*******************************************************************************
** Function Name        : Com_SendSignalGroupArray                            **
**                                                                            **
** Service ID           : 0x23                                                **
**                                                                            **
** Description          : This function copies the contents of the associated **
**                        shadow buffer to the associated I-PDU.              **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same signal group.            **
**                        Reentrant for different signal groups.              **
**                                                                            **
** Input Parameters     : SignalGroupId                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : SignalGroupArrayPtr                                 **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : All signals should be updated in the shadow buffer  **
**                        by the call of Com_UpdateShadowSignal().            **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaTxSigGroup          **
**                                                 Com_GaaTxPack              **
**                                                 Com_GaaTxSigGrpModeSel     **
**                                                 Com_GaaFilterStatus        **
**                                                 Com_GaaTxIpduStatus        **
**                        Function(s) invoked    : SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
**                                                 Det_ReportError()          **
**                                                 Com_PackAndValidateSigGrp()**
**                                                 Com_TxRequest()            **
*******************************************************************************/
#if(COM_TX_SIGGROUP == STD_ON)
#if((COM_ENABLE_SIGNALGROUP_ARRAY_API == STD_ON) && (COM_TX_SIGINGROUP_ARRAY_ACCESS == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, COM_CODE) Com_SendSignalGroupArray (Com_SignalGroupIdType SignalGroupId, P2CONST (uint8, AUTOMATIC, COM_CONST) SignalGroupArrayPtr )
{
  /* Pointer to Tx pack structure */
  P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack;
   /* Pointer to Tx signal Group structure */
  P2CONST(Com_TxSigGrp, AUTOMATIC, COM_CONST) LpTxSigGrp;
  #if(COM_TX_TP_SUPPORT == STD_ON)
  /* Pointer to Tx Ipdu */
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu; 
  /* Pointer to TP Ipdu structure */
  P2CONST(Com_TxTPIpdu, AUTOMATIC, COM_CONST) LpTxTPIpdu;
  #endif
  /* Local variable to store return value */
  uint8 LucReturnValue = (uint8)E_OK;
  /* Local variable to store signal group config */
  uint8 LucSigGrpConfig;
  /* Local variable to store signal group property */
  uint8 LucSigGrpProperty;
  #if(COM_TX_SIGGROUP_TRIGONCHANGE == STD_ON)
  boolean LblReturnFlag = COM_TRUE;
  #endif

  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /*  return value to COM_SERVICE_NOT_AVAILABLE */
  LucReturnValue = (uint8)E_OK;

  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_SENDSIGNALGROUPARRAY);
  /* Check whether signal group ID is out of range */
  COM_DET_TXSIGNALGROUPID_RANGE_CHECK_FLAG(COMSERVICEID_SENDSIGNALGROUPARRAY);
  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif /* COM_DEV_ERROR_DETECT */
  {
  
    /* Get the pointer to Tx signal group structure */
    LpTxSigGrp = &Com_GaaTxSigGroup[SignalGroupId];

    /* [SWS_Com_00843] */
    if(LpTxSigGrp->blArrayAccess != COM_TRUE)
    {
      /* AUTOSAR dose not define the behavior of illegally calling*/
      /* Discard the request */
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;
    }
    else
    {      
      #if(COM_TX_TP_SUPPORT == STD_ON)
      /* Get the pointer to Tx IPdu structure */
      LpTxIpdu =  &Com_GaaTxIpdu[LpTxSigGrp->ddTxIpduIndex];
      
      if(LpTxIpdu->ucTxTPRef != COM_INVALID_NONE)
      {
        /* Get the pointer to TP structure  */
        LpTxTPIpdu = &Com_GaaTxTPIpdu[LpTxIpdu->ucTxTPRef];
        if((Com_GaaTxTPStatus[LpTxTPIpdu->ucTxTPStatusRef] 
        & (LpTxTPIpdu->ucTxTPStatusMask)) != COM_ZERO)
        {
          LucReturnValue = (uint8)COM_BUSY;
        }
      }
     
      if(LucReturnValue == (uint8)E_OK)
      #endif
      {
        LpTxPack = &(Com_GaaTxPack[LpTxSigGrp->ddTxSigGrpPackIndex]);
        /* Get the signal group configuration */
        LucSigGrpConfig = LpTxSigGrp->ucTxSigGrpConfig;
        /* Extract the signal property - first 5 bits of signal configuration */
        LucSigGrpProperty = LucSigGrpConfig & COM_TX_SIG_PROPERTY_CONFIG_MASK;
        /* Invoke Com_PackAndValidateSigGrp() function to pack and validate signal
        group data from shadow buffer to I-PDU buffer */
        #if(COM_TX_SIGGROUP_TRIGONCHANGE == STD_ON)
        if(LucSigGrpProperty >= COM_TX_SIG_TRIGGERED_ON_CHANGE)
        {
          LblReturnFlag = Com_PackAndValidateSigGrpArray(LpTxPack, SignalGroupArrayPtr, LpTxPack->pWrBuffer);        
        }
        else
        {
          (void)Com_PackSigGrpArray(LpTxPack, SignalGroupArrayPtr, LpTxPack->pWrBuffer);
        }
        #else
        (void)Com_PackSigGrpArray(LpTxPack, SignalGroupArrayPtr, LpTxPack->pWrBuffer);
        #endif
        #if(COM_TX_SIGGROUP_UB == STD_ON)
        /* Check whether update bit is configured */
        if((LucSigGrpConfig & COM_TX_SIGNAL_UB_CONFIG_MASK) != COM_FALSE)
        {
          /* Enter protection area */
          SchM_Enter_Com_TX_IPDU_BUFFER_PROTECTION_AREA();
          /* Set the update bit */
         
          *(LpTxSigGrp->pUbit) |= LpTxSigGrp->ucUbitMask;
          /* Exit protection area */
          SchM_Exit_Com_TX_IPDU_BUFFER_PROTECTION_AREA();
        }
        #endif
        #if(COM_TX_SIGGROUP_TMS == STD_ON)
        LucSigGrpConfig = Com_TxSigGrpModeSelect(LpTxSigGrp);
        #endif
        /* Set return value to COM_SERVICE_NOT_AVAILABLE */
        LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;
        /* Check whether I-PDU group is started */
        if(Com_GaaTxIpduStatus[LpTxSigGrp->ddTxIpduIndex] != (PduIdType)COM_ZERO)
        {
          /* Set return value to E_OK */
          LucReturnValue = (uint8)E_OK;
          #if(COM_TX_SIGGROUP_TRIGONCHANGE == STD_ON)
          if(LblReturnFlag == COM_TRUE)
          #endif
          {
            if((LucSigGrpProperty) > COM_TX_SIG_PENDING_PROPERTY)
            {
              #if ((COM_TX_IPDU_TMS == STD_ON) || \
              (COM_TX_IPDU_REPETITION == STD_ON) || \
              ((COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) \
              && (COM_TX_IPDU_GW == STD_ON))|| \
              (COM_TX_IPDU_GW == STD_ON) || \
              (COM_TX_IPDU_DM == STD_ON))
              (void)Com_TxRequest(LpTxSigGrp->ddTxIpduIndex, LucSigGrpConfig);
              
              #else
              (void)Com_TxRequest(LpTxSigGrp->ddTxIpduIndex);
              #endif
            } /* Check whether signal group property is triggered */
          } /* Check whether I-PDU group is started */
        }
      } /* DET Check */
    }
  }
  /* Return value */
  return(LucReturnValue);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/* #7525 #7709 end */
/*******************************************************************************
** Function Name        : Com_UpdateShadowSignalService                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function added for cyclomatic complexity reduction. **
**                        Updates shadow buffers                              **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : SignalId, SignalDataPtr                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :  Com_GaaTxSigInGrp         **
**                                                  Com_GaaTxPack             **
**                        Function(s) invoked    :  pWrFuncPtr                **
**                                                  pFilterFuncPtr            **
*******************************************************************************/
#if(COM_TX_SIGGROUP == STD_ON)
FUNC(void, COM_CODE) Com_UpdateShadowSignalService(Com_SignalIdType SignalId,
           P2CONST(void, AUTOMATIC, COM_CONST) SignalDataPtr)
{
  /* #7525 #7705 start */
  /* Pointer to Tx signal In Group structure */
  P2CONST(Com_TxSigInGrp, AUTOMATIC, COM_CONST)LpTxSigInGrp;
  #if(((COM_ENABLE_SIGNALGROUP_ARRAY_API == STD_ON) && (COM_TX_SIGINGROUP_ARRAY_ACCESS == STD_ON)) || ((COM_TX_SIGGROUP_TRIGONCHANGE == STD_ON) && (COM_TX_SIGGROUP_GROUPSIG_TRIGONCHANGE == STD_ON)))
  /* Pointer to Tx signal Group structure */
  P2CONST(Com_TxSigGrp, AUTOMATIC, COM_CONST) LpTxSigGrp;
  #endif
  /* Pointer to Tx Pack structure */
  P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack;
  #if(COM_TX_IPDU_TMS == STD_ON)
  /* Pointer to filter structure */
  P2CONST(Com_FilterNever, AUTOMATIC, COM_CONST) LpFilter;
  #endif
  #if((COM_TX_SIGGROUP_TRIGONCHANGE == STD_ON) && (COM_TX_SIGGROUP_GROUPSIG_TRIGONCHANGE == STD_ON))
  boolean LblReturnFlag;
  #endif
  /* Get the pointer to Tx signal in group structure */
  LpTxSigInGrp = &Com_GaaTxSigInGrp[SignalId];
  /* Get the pointer to TxPack structure */
  LpTxPack = &(Com_GaaTxPack[LpTxSigInGrp->ddTxPackIndex]);
  /* Invoke the write function to pack signal data into shadow buffer */

  #if(COM_SIGNAL_RANGE_VALIDATION_CHECK == STD_ON)
  /* Fix the input value(#644) - 14.03.03 by Chan Kim START */ 
  /*
  adding range check for HMC specification - by Chan Kim 2013.09.11-START
  */
  if(!Com_TxSigValidationCheck(LpTxSigInGrp->usBitSize, 
  	LpTxSigInGrp->ucType, SignalDataPtr))
  {
    return;
  }
  /*
  adding range check for HMC specification - by Chan Kim 2013.09.11-END
  */
  /* Fix the input value(#644) - 14.03.03 by Chan Kim END */ 
  #endif

  #if(((COM_ENABLE_SIGNALGROUP_ARRAY_API == STD_ON) && (COM_TX_SIGINGROUP_ARRAY_ACCESS == STD_ON)) || ((COM_TX_SIGGROUP_TRIGONCHANGE == STD_ON) && (COM_TX_SIGGROUP_GROUPSIG_TRIGONCHANGE == STD_ON)))
  LpTxSigGrp = &Com_GaaTxSigGroup[LpTxSigInGrp->ddSigGrpIndex];
  #endif

  #if((COM_ENABLE_SIGNALGROUP_ARRAY_API == STD_ON) && (COM_TX_SIGINGROUP_ARRAY_ACCESS == STD_ON))
  /* AUTOSAR dose not define the behavior of illegally calling*/
  /* Discard the request */
  if(LpTxSigGrp->blArrayAccess != COM_TRUE)
  #endif
  {  
    (void)Com_PackRequestWrite(LpTxPack, SignalDataPtr);

    #if((COM_TX_SIGGROUP_TRIGONCHANGE == STD_ON) && (COM_TX_SIGGROUP_GROUPSIG_TRIGONCHANGE == STD_ON))
    if(LpTxSigGrp->pOnChangeStatus != NULL_PTR)
    {
      if(COM_TX_SIG_TRIGGERED_ON_CHANGE == (LpTxSigInGrp->ucTxSigConfig & COM_TX_SIG_PROPERTY_CONFIG_MASK))
      {
        if(Com_GaaValidateValue[LpTxPack->ddSignalType].pValidateDataPtr != NULL_PTR)
        {
          /* Check whether old value is equal to new value or not */
          /* polyspace:begin<RTE: COR : Not a defect : No Action Planned > configured memory access index */
          LblReturnFlag = ((Com_GaaValidateValue[LpTxPack->ddSignalType].pValidateDataPtr)
                                    (SignalDataPtr,LpTxSigInGrp->pSignalBuffer,
                                     LpTxPack->ddSigTypeOrSize));
          /* polyspace:end<RTE: COR : Not a defect : No Action Planned > configured memory access index */

          if(LblReturnFlag == COM_TRUE)
          {
            *(LpTxSigGrp->pOnChangeStatus) = COM_ONE;          
          }
        }
      }
    }
    #endif
    #if(COM_TX_IPDU_TMS == STD_ON)
    /* polyspace:begin<RTE: NIP : Not a defect : No Action Planned > Initialized pointer */
    /* polyspace:begin<RTE: NIV : Not a defect : No Action Planned > initialized variable */
    /* Check whether filter is configured */
    if(LpTxSigInGrp->pFilter != NULL_PTR)
    {
      LpFilter = (P2CONST(Com_FilterNever, AUTOMATIC, COM_CONST))
                                                   (LpTxSigInGrp->pFilter);
      if((LpFilter->ucFltrStsMask) != COM_ZERO)
      {
        /* Invoke filter function and check the return value */
        /* Reset the previous value in MASKED_NEW_DIFFERS_MASKED_OLD filter,
        when Rx Timeout is occurred - Fixed by AUTRON START*/		  
        /* polyspace:begin<RTE: COR : Not a defect : No Action Planned > configured memory access index */
        if((LpFilter->pFilterFuncPtr)(LpFilter, SignalDataPtr, COM_ZERO) 
  	    == COM_TRUE)
  	    /* polyspace:end<RTE: COR : Not a defect : No Action Planned > configured memory access index */
        /* Reset the previous value in MASKED_NEW_DIFFERS_MASKED_OLD filter,
        when Rx Timeout is occurred - Fixed by AUTRON END*/		  
        {
          SchM_Enter_Com_TX_TMS_STATUS_PROTECTION_AREA();
          /* Set the filter status to true */
          *(LpFilter->pFilterStatus) |= (LpFilter->ucFltrStsMask);
          SchM_Exit_Com_TX_TMS_STATUS_PROTECTION_AREA();
        }
        else
        {
          SchM_Enter_Com_TX_TMS_STATUS_PROTECTION_AREA();
          /* Set the filter status of the group signal to false by masking it
             with the filter status mask value.*/
          *(LpFilter->pFilterStatus) &= (uint8)(~(LpFilter->ucFltrStsMask));
          SchM_Exit_Com_TX_TMS_STATUS_PROTECTION_AREA();
        }
      }
    } /* Check whether filter is configured */
    /* polyspace:end<RTE: NIP : Not a defect : No Action Planned > Initialized pointer */
    /* polyspace:end<RTE: NIV : Not a defect : No Action Planned > initialized variable */
    #endif /*  #if(COM_TX_IPDU_TMS == STD_ON) */
  }  
  /* #7525 #7705 end */
}
#endif
/*******************************************************************************
** Function Name        : Com_SendSignalService                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function added for cyclomatic complexity reduction. **
**                                                                            **
* Sync/Async           : Asynchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same signal.                  **
**                        Reentrant for different signals.                    **
**                                                                            **
** Input Parameters     : SignalId, SignalDataPtr                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaTxSignal            **
**                                                 Com_GaaTxPack              **
**                                                 Com_GaaTxIpdu              **
**                                                 Com_GaaTxTPIpdu            **
**                                                 Com_GaaTxTPStatus          **
**                                                 Com_GaaTxIpduStatus        **
**                                                 Com_GaaValidateValue       **
**                        Function(s) invoked    : SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
**                                                 Com_SendSigTMS()           **
**                                                 Com_TxRequest()            **
**                                                 pWrFuncPtr                 **
**                                                 pValidateDataPtr           **
*******************************************************************************/
#if (COM_TX_SIGNAL == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, COM_CODE) Com_SendSignalService (Com_SignalIdType SignalId,
  P2CONST(void, AUTOMATIC, COM_CONST) SignalDataPtr)
{
  /* Pointer to Tx signal structure */
  P2CONST(Com_TxSignal, AUTOMATIC, COM_CONST) LpTxSignal;
  /* Pointer to Tx pack structure */
  P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack;
  #if(COM_TX_TP_SUPPORT == STD_ON)
  /* Pointer to Tx Ipdu */
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu; 
  /* Pointer to TP Ipdu structure */
  P2CONST(Com_TxTPIpdu, AUTOMATIC, COM_CONST) LpTxTPIpdu;
  #endif  
  /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Local variable to store signal config */
  uint8 LucSigConfig;
  /* Local variable to store signal property */
  uint8 LucSigProperty;
  #if(COM_TX_SIGNAL_TRIGONCHANGE == STD_ON)
  boolean LblReturnFlag = COM_TRUE;
  #endif

  /* Get the pointer to Tx signal structure */
  LpTxSignal = &Com_GaaTxSignal[SignalId];

  #if(COM_SIGNAL_RANGE_VALIDATION_CHECK == STD_ON)
  /*
  adding range check for HMC specification - by Chan Kim 2013.09.11-START
  */
  if(!Com_TxSigValidationCheck(LpTxSignal->usBitSize, 
  	LpTxSignal->ucType, SignalDataPtr))
  {
    return E_NOT_OK;
  }
  /*
  adding range check for HMC specification - by Chan Kim 2013.09.11-END
  */
  #endif


  /* Get the pointer toTxPack structure */
  LpTxPack = &(Com_GaaTxPack[LpTxSignal->ddTxPackIndex]);
  #if(COM_TX_TP_SUPPORT == STD_ON)
  LucReturnValue = (uint8)E_OK;
  /* Get the pointer to Tx IPdu structure */
  LpTxIpdu =  &Com_GaaTxIpdu[LpTxSignal->ddTxIpduIndex];
  
  if(LpTxIpdu->ucTxTPRef != COM_INVALID_NONE)
  {
    /* Get the pointer to TP structure  */
    LpTxTPIpdu = &Com_GaaTxTPIpdu[LpTxIpdu->ucTxTPRef];
    if((Com_GaaTxTPStatus[LpTxTPIpdu->ucTxTPStatusRef] 
    & (LpTxTPIpdu->ucTxTPStatusMask)) != COM_ZERO)
    {
      LucReturnValue = (uint8)COM_BUSY;
    }
  }
  if(LucReturnValue == (uint8)E_OK)
  #endif
  {
    /* Invoke write function to pack data referred by SignalDataPtr to I-PDU
    buffer */
    (void)Com_PackRequestWrite(LpTxPack, SignalDataPtr);
    #if((COM_TX_SIGNAL_UB == STD_ON) || (COM_TX_IPDU_TMS == STD_OFF))
    /* Get the signal configuration into local variable */
    LucSigConfig = LpTxSignal->ucTxSigConfig;
    #endif
    #if(COM_TX_SIGNAL_UB == STD_ON)
    /* Check whether update bit is configured */
    if((LucSigConfig & COM_TX_SIGNAL_UB_CONFIG_MASK) != COM_FALSE)
    {
      /* Enter protection area */
      SchM_Enter_Com_TX_IPDU_BUFFER_PROTECTION_AREA();
      /* Set update bit to one */
      *(LpTxSignal->pUbit) |= LpTxSignal->ucUbitMask;
      /* Exit protection area */
      SchM_Exit_Com_TX_IPDU_BUFFER_PROTECTION_AREA();
    }
    #endif
    #if(COM_TX_IPDU_TMS == STD_ON)
    LucSigConfig = Com_SendSigTMS(LpTxSignal, SignalDataPtr);
    #endif
    /* Set return value to COM_SERVICE_NOT_AVAILABLE */
    LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;


    /* Mask the signal configuration to get signal property */
    LucSigProperty = LucSigConfig & COM_TX_SIG_PROPERTY_CONFIG_MASK;

    #if(COM_TX_SIGNAL_TRIGONCHANGE == STD_ON)
    if((LucSigProperty >= COM_TX_SIG_TRIGGERED_ON_CHANGE))
    {
      if(Com_GaaValidateValue[LpTxPack->ddSignalType].pValidateDataPtr != 
      NULL_PTR)
      {
        /* Check whether old value is equal to new value or not */
        /* polyspace:begin<RTE: COR : Not a defect : No Action Planned > configured memory access index */
        LblReturnFlag = ((Com_GaaValidateValue[LpTxPack->ddSignalType].pValidateDataPtr)
                                  (SignalDataPtr,LpTxSignal->pSignalBuffer,
                                   LpTxPack->ddSigTypeOrSize));
        /* polyspace:end<RTE: COR : Not a defect : No Action Planned > configured memory access index */
      }
    }
    #endif
      
    /* Check whether Tx I-PDU is enabled */
    if(Com_GaaTxIpduStatus[LpTxSignal->ddTxIpduIndex] != (PduIdType)COM_ZERO)
    {
      /* Set return value to E_OK */
      LucReturnValue = (uint8)E_OK;

      #if(COM_TX_SIGNAL_TRIGONCHANGE == STD_ON)
      if(LblReturnFlag == COM_TRUE)
      #endif
      {
        /* Check whether signal transfer property is triggered or
           transmission mode selection is configured */           
        if(LucSigProperty  > COM_TX_SIG_PENDING_PROPERTY)
        {  
          #if ((COM_TX_IPDU_TMS == STD_ON) || \
          (COM_TX_IPDU_REPETITION == STD_ON) || \
          ((COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) \
          && (COM_TX_IPDU_GW == STD_ON))|| \
          (COM_TX_IPDU_GW == STD_ON) || \
          (COM_TX_IPDU_DM == STD_ON))
          LucReturnValue = Com_TxRequest(LpTxSignal->ddTxIpduIndex, 
            LucSigConfig);
          #else
          LucReturnValue = Com_TxRequest(LpTxSignal->ddTxIpduIndex);
          #endif
        } /* signal transfer property is triggered */
      } /* Check whether Tx I-PDU group is enabled */
    } /* Check whether any development error has occurred */
  }    
  /* Return value */
  return(LucReturnValue);
}

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_TxSigGrpModeSelect                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function determines the transmission mode.     **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same signal group.            **
**                        Reentrant for different signal groups.              **
**                                                                            **
** Input Parameters     : LpTxSigGrp                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : All signals should be updated in the shadow buffer  **
**                        by the call of Com_UpdateShadowSignal().            **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaTxSigGrpModeSel     **
**                                                 Com_GaaFilterStatus        **
**                        Function(s) invoked    : SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
*******************************************************************************/
#if(COM_TX_SIGGROUP_TMS == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, COM_CODE) Com_TxSigGrpModeSelect
                       (P2CONST(Com_TxSigGrp, AUTOMATIC, COM_CONST) LpTxSigGrp)
{
  P2CONST(Com_TxSigGrpModeSel, AUTOMATIC, COM_CONST) LpTxSigGrpModeSel;
  P2CONST(uint8, AUTOMATIC, COM_CONST) LpFilterStatus;
  uint8 LucFilterStatusCount;
  uint8 LucSigGrpConfig;
  uint8 LucFilterStatusIndex;
  boolean LblResult;
  LucSigGrpConfig = LpTxSigGrp->ucTxSigGrpConfig ;
  /* Check whether update bit is configured */
  if((LucSigGrpConfig & COM_TX_SIG_TMS_CONFIG_MASK) != COM_FALSE)
  {
    LblResult = COM_FALSE;
    /* Get the pointer to Tx Mode Select structure*/
    LpTxSigGrpModeSel =
                &Com_GaaTxSigGrpModeSel[LpTxSigGrp->ucTxSigGrpModeSelIndex];
    /* Get the pointer to filter status */
    LucFilterStatusIndex = LpTxSigGrpModeSel->ucFilterStatusIndex;
    LpFilterStatus =
               &Com_GaaFilterStatus[LucFilterStatusIndex];
    /* Get the counter */
    LucFilterStatusCount = LpTxSigGrpModeSel->ucNoOfFilterStsByte;
    /* Loop for all the signals configured for filtering */
    do
    {
      /* Decrement the filter status count */
      LucFilterStatusCount--;
      /* Check whether filter status is set to true */
   
      if(*LpFilterStatus != COM_ZERO)
      {
        LblResult = COM_TRUE;
        /* Set filter result to true */
        LucSigGrpConfig |= COM_TX_SIG_TMS_STATUS_MASK;
        /* Enter protection area */
        SchM_Enter_Com_TX_TMS_STATUS_PROTECTION_AREA();
        
        Com_GaaFilterStatus[LpTxSigGrpModeSel->ucIpduFilterStsIndex] |=
        LpTxSigGrpModeSel->ucFilterStatusMask;
        /* Exit protection area */
        SchM_Exit_Com_TX_TMS_STATUS_PROTECTION_AREA();
        /* Set filter status count to zero to break the loop */
        LucFilterStatusCount = COM_ZERO;
      }

      /* Increment the filter status pointer to point to n filter status
         area */
      LucFilterStatusIndex++;
      LpFilterStatus =
               &Com_GaaFilterStatus[LucFilterStatusIndex];
    }while(LucFilterStatusCount != COM_ZERO);
  
    if(LblResult != COM_TRUE)
    {
      /* Enter protection area */
      SchM_Enter_Com_TX_TMS_STATUS_PROTECTION_AREA();
      /* Update the filter Staatus */
      Com_GaaFilterStatus[LpTxSigGrpModeSel->ucIpduFilterStsIndex] &=
                            (uint8)~(LpTxSigGrpModeSel->ucFilterStatusMask);
      /* Exit protection area */
      SchM_Exit_Com_TX_TMS_STATUS_PROTECTION_AREA();
    }
  }
  return(LucSigGrpConfig);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : Com_TxSigValidationCheck                              **
**                                                                            **
** Service ID         : NA                                                    **
**                                                                            **
** Description        : This function check the signal data is valid or not.  **
**                                                                            **
** Sync/Async         : Asynchronous                                          **
**                                                                            **
** Re-entrancy        : Non-Reentrant for the same signal group.              **
**                      Reentrant for different signal groups.                **
**                                                                            **
** Input Parameters   : signalSize, signalType, SignalDataPtr                 **
**                                                                            **
** InOut parameter    : None                                                  **
**                                                                            **
** Output Parameters  : None                                                  **
**                                                                            **
** Return parameter   : boolean                                               **
**                                                                            **
** Preconditions      : All signals should be updated in the shadow buffer    **
**                      by the call of Com_UpdateShadowSignal().              **
**                                                                            **
** Remarks            : Global Variable(s)    : None                          **
**                      Function(s) invoked   : None                          **
*******************************************************************************/
#if(COM_SIGNAL_RANGE_VALIDATION_CHECK == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(boolean, COM_CODE) Com_TxSigValidationCheck
(uint16 signalSize, uint8 signalType, 
P2CONST(void, AUTOMATIC, COM_CONST) SignalDataPtr)
{
  boolean LblSigTypeBooleanVar = COM_ZERO;
  uint8 LucSigTypeUint8Var = COM_ZERO;
  sint8 LscSigTypeSint8Var = (sint8)COM_ZERO;
  sint8 LscSigTypeSint8VarUP = (sint8)COM_ONE;
  sint8 LscSigTypeSint8VarLO = (sint8)COM_ZERO;
  
  uint16 LusSigTypeUint16Var = (uint16)COM_ZERO;
  sint16 LssSigTypeSint16Var = (sint16)COM_ZERO;
  sint16 LscSigTypeSint16VarUP = (sint16)COM_ONE;
  sint16 LscSigTypeSint16VarLO = (sint16)COM_ZERO;  
  
  uint32 LulSigTypeUint32Var = (uint32)COM_ZERO;
  sint32 LslSigTypeSint32Var = (sint32)COM_ZERO;  
  sint32 LscSigTypeSint32VarUP = (sint32)COM_ONE;
  sint32 LscSigTypeSint32VarLO = (sint32)COM_ZERO;  

  boolean LblTypeValueValid = COM_TRUE;

  if(SignalDataPtr != NULL_PTR)
  {
  
    switch(signalType)
    {
      case COM_SIG_TYPE_BOOLEAN:
        LblSigTypeBooleanVar = *(boolean*)(SignalDataPtr);
        if((LblSigTypeBooleanVar >> COM_ONE) > COM_ZERO)
        {
          LblTypeValueValid = COM_FALSE;
        }
        break;
      case COM_SIG_TYPE_UINT8:
        LucSigTypeUint8Var = *(uint8*)(SignalDataPtr);
        if(signalSize > (uint16)COM_EIGHT)
        {
          LblTypeValueValid = COM_FALSE;
        }
        else
        {
          if((signalSize != (uint16)COM_EIGHT) 
            && ((LucSigTypeUint8Var >> signalSize) > COM_ZERO))
          {
            LblTypeValueValid = COM_FALSE;
          }    
        }
        break;    
      case COM_SIG_TYPE_SINT8:
        LscSigTypeSint8Var = *(sint8*)(SignalDataPtr);    
        if(signalSize > (uint16)COM_EIGHT || signalSize == (uint16)COM_ZERO)
        {
          LblTypeValueValid = COM_FALSE;
        }
        else
        {
          if(signalSize != (uint16)COM_EIGHT) 
          {
            LucSigTypeUint8Var = COM_ONE << (signalSize-COM_ONE);
            LscSigTypeSint8VarLO = -(LucSigTypeUint8Var);
            LscSigTypeSint8VarUP = (sint8)(LucSigTypeUint8Var - COM_ONE);
            if((LscSigTypeSint8Var > LscSigTypeSint8VarUP) 
              || (LscSigTypeSint8Var < LscSigTypeSint8VarLO))
            {
              LblTypeValueValid = COM_FALSE;
            }
          }
        }
        break;    
      case COM_SIG_TYPE_UINT16:
        LusSigTypeUint16Var = *(uint16*)(SignalDataPtr);
        if(signalSize > (uint16)COM_SIXTEEN)
        {
          LblTypeValueValid = COM_FALSE;
        }
        else
        {    
          if((signalSize != (uint16)COM_SIXTEEN) 
            && ((LusSigTypeUint16Var >> signalSize) > COM_ZERO))
          {
            LblTypeValueValid = COM_FALSE;
          }   
        }
        break;    
      case COM_SIG_TYPE_SINT16:
        LssSigTypeSint16Var = *(sint16*)(SignalDataPtr);
        if(signalSize > (uint16)COM_SIXTEEN || signalSize == (uint16)COM_ZERO)
        {
          LblTypeValueValid = COM_FALSE;
        }
        else
        {
          if(signalSize != (uint16)COM_SIXTEEN) 
          {
            LusSigTypeUint16Var = COM_ONE << (signalSize-(uint16)COM_ONE);
            LscSigTypeSint16VarLO = -(LusSigTypeUint16Var);
            LscSigTypeSint16VarUP = (sint16)(LusSigTypeUint16Var - COM_ONE);
            if((LssSigTypeSint16Var > LscSigTypeSint16VarUP) 
              || (LssSigTypeSint16Var < LscSigTypeSint16VarLO))
            {
              LblTypeValueValid = COM_FALSE;
            }    
          }
        }
        break;    
      case COM_SIG_TYPE_UINT32:
        LulSigTypeUint32Var = *(uint32*)(SignalDataPtr);   
        if(signalSize > (uint16)COM_THIRTY_TWO)
        {
          LblTypeValueValid = COM_FALSE;
        }
        else
        {    
          if((signalSize != (uint16)COM_THIRTY_TWO) 
            && ((LulSigTypeUint32Var >> signalSize) > COM_ZERO))
          {
            LblTypeValueValid = COM_FALSE;
          }    
        }
        break;    
      case COM_SIG_TYPE_SINT32:
        LslSigTypeSint32Var = *(sint32*)(SignalDataPtr);  
        if(signalSize > (uint16)COM_THIRTY_TWO || signalSize == (uint16)COM_ZERO)
        {
          LblTypeValueValid = COM_FALSE;
        }
        else
        {
          if(signalSize != (uint16)COM_THIRTY_TWO) 
          {
            LulSigTypeUint32Var = COM_ONE << (signalSize-(uint16)COM_ONE);
            LscSigTypeSint32VarLO = -(LulSigTypeUint32Var);
            LscSigTypeSint32VarUP = (sint32)(LulSigTypeUint32Var - COM_ONE);
            if((LslSigTypeSint32Var > LscSigTypeSint32VarUP) 
              || (LslSigTypeSint32Var < LscSigTypeSint32VarLO))
            {
              LblTypeValueValid = COM_FALSE;
            }      
          }
        }
        break;
      case COM_SIG_TYPE_FLOAT32:    
        break;
      
      case COM_SIG_TYPE_UINT8_N:    
        break;
      
      case COM_SIG_TYPE_FLOAT64:    
        break;
      
      case COM_SIG_TYPE_UINT8_DYN:    
        break;    

      default:
        LblTypeValueValid = COM_FALSE;    
        break;
    }
  }
  else
  {
    LblTypeValueValid = COM_FALSE;    
  }
  return LblTypeValueValid;
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"  
#endif

/* polyspace:end<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : No Action Planned > configured memory access index */


/*******************************************************************************
**                          END OF FILE                                       **
*******************************************************************************/
