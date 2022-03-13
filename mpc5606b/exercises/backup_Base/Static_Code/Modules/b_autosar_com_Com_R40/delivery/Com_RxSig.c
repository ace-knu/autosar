/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Com_RxSig.c                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Com Module                                            **
**                                                                            **
**  PURPOSE   : Provision of receive functions and their functionality.       **
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
** 2.2.0     16-Apr-2017   Chan Kim    Internal Redmine #7861, #7707, #7525,  **
**                                     #7744, #7803                           **
** 2.1.9     20-Mar-2017   Chan Kim    Internal Redmine #7851                 **
** 2.1.7     30-Nov-2016   Chan Kim    Internal Redmine #6807                 **
** 2.1.0     25-May-2016   Chan Kim    Internal Redmine #4998                 **
** 2.0.8     12-Feb-2016   Chan Kim    Internal Redmine #4158                 **
** 2.0.3     24-Nov-2015   Chan Kim    Internal Redmine #3544, #3535          **
** 1.0.15    09-Feb-2015   Chan Kim    Internal Redmine #2142                 **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Com.h"          /* Com header file */
#include "Com_Main.h"     /* Com Main header file */
#include "Com_Pack.h"     /* Com Pack header file */
#include "Com_Error.h"    /* Com Error header file */
#if(COM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"                 /* Det header file */
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version Information */
#define COM_RXSIG_C_AR_RELEASE_MAJOR_VERSION  4
#define COM_RXSIG_C_AR_RELEASE_MINOR_VERSION  0
#define COM_RXSIG_C_AR_RELEASE_REVISION_VERSION  3

/* Software version information */
#define COM_RXSIG_C_SW_MAJOR_VERSION  2
#define COM_RXSIG_C_SW_MINOR_VERSION  2

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if(COM_AR_RELEASE_MAJOR_VERSION != COM_RXSIG_C_AR_RELEASE_MAJOR_VERSION)
  #error "Com_RxSig.c : Mismatch in Com Specification Major Version"
#endif

#if(COM_AR_RELEASE_MINOR_VERSION != COM_RXSIG_C_AR_RELEASE_MINOR_VERSION)
  #error "Com_RxSig.c : Mismatch in Com Specification Minor Version"
#endif

#if(COM_AR_RELEASE_REVISION_VERSION != COM_RXSIG_C_AR_RELEASE_REVISION_VERSION)
  #error "Com_RxSig.c : Mismatch in Com Specification Revision Version"
#endif

#if(COM_SW_MAJOR_VERSION != COM_RXSIG_C_SW_MAJOR_VERSION)
  #error "Com_RxSig.c : Mismatch in Com Software Major Version"
#endif

#if(COM_SW_MINOR_VERSION != COM_RXSIG_C_SW_MINOR_VERSION)
  #error "Com_RxSig.c : Mismatch in Com Software Minor Version"
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
** Function Name        : Com_ReceiveSignal                                   **
**                                                                            **
** Service ID           : 0x0B                                                **
**                                                                            **
** Description          : Com_ReceiveSignal copies the data of the signal     **
**                        identified by SignalId to the location specified by **
**                        SignalDataPtr.                                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same signal.                  **
**                        Reentrant for different signals.                    **
**                                                                            **
** Input Parameters     : SignalId                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : SignalDataPtr                                       **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaRxSignal            **
**                                                 Com_GaaRxUnpack            **
**                                                 Com_GaaRxIpduStatus        **
**                                                 Com_GaaWrFuncPtr           **
**                        Function(s) invoked    : Det_ReportError()          **
**                                                 pWrFuncPtr                 **
**                                                 pRdFuncPtr                 **
**                                                 Com_ShadowSignalCopy()     **
*******************************************************************************/

#if(COM_RX_SIGNAL == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, COM_CODE) Com_ReceiveSignal (Com_SignalIdType SignalId,
  P2VAR(void, AUTOMATIC, COM_VAR) SignalDataPtr)
{
  /* Pointer to Rx Signal structure */
  P2CONST(Com_RxSignal, AUTOMATIC, COM_CONST) LpRxSignal;
  /* Pointer to Rx Unpack structure */
  P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST) LpRxUnpack;
  #if(COM_RX_TP_SUPPORT == STD_ON)
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu;
  P2CONST(Com_RxTPIpdu, AUTOMATIC, COM_CONST) LpRxTPIpdu;
  #endif
  #if((COM_RX_SIGNAL_UBDMREPLACE == STD_ON)|| \
       (COM_RX_SIGNAL_FILTER == STD_ON) || (COM_RX_SIGNAL_INVALID == STD_ON))
  /* Local variable to store Signal type Or Size */
  uint8 LucSigTypeOrSize;
  #endif
  /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Initialize DET error flag to false */
  LucReturnValue = (uint8)E_OK;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_RECEIVESIGNAL);
  /* Check whether signal ID is out of range */
  COM_DET_RX_SIGNALID_RANGE_CHECK_FLAG(COMSERVICEID_RECEIVESIGNAL);
  /* Check whether signal data pointer is equal to NULL */
  COM_DET_SIGNAL_DATA_PTR(COMSERVICEID_RECEIVESIGNAL);
  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif /* COM_DEV_ERROR_DETECT */
  {
    #if(COM_RX_TP_SUPPORT == STD_ON)
    
      /* Get the pointer to  Rx signal */
    LpRxSignal = &Com_GaaRxSignal[SignalId];
    
    /* Get the pointer to Tx IPdu structure */
    LpRxIpdu =  &Com_GaaRxIpdu[LpRxSignal->ddRxpduId];
    
    if(LpRxIpdu->ucRxTPRef != COM_INVALID_NONE)
    {
      /* Get the pointer to TP structure  */
      LpRxTPIpdu = &Com_GaaRxTPIpdu[LpRxIpdu->ucRxTPRef];
      if((Com_GaaRxTPStatus[LpRxTPIpdu->ucRxTPStatusRef] 
      & (LpRxTPIpdu->ucRxTPStatusMask)) != COM_ZERO)
      {
        LucReturnValue = (uint8)COM_BUSY;
      }
    }
    if(LucReturnValue == (uint8)E_OK)
    #endif /* COM_DEV_ERROR_DETECT */
    {
  
      if(SignalId < COM_RX_SIG_GRPSIG_BOUNDARY)
      {
        /* Get the pointer to  Rx signal */
        LpRxSignal = &Com_GaaRxSignal[SignalId];
        /* Get the pointer to RxUnpack structure */
        LpRxUnpack = &Com_GaaRxUnpack[LpRxSignal->ddRxUnpackIndex];
        #if((COM_RX_SIGNAL_UBDMREPLACE == STD_ON)|| \
             (COM_RX_SIGNAL_FILTER == STD_ON) || \
             (COM_RX_SIGNAL_INVALID == STD_ON))
        /* Check whether signal buffer is equal to NULL */
        if(LpRxSignal->pSignalBuffer != NULL_PTR)
        {
          /* Invoke the write function to unpack the data from the signal buffer
          and copy to SignalDataPtr */
          
          LucSigTypeOrSize = LpRxUnpack->ucSignalType;
         
          Com_GaaWrFuncPtr[LucSigTypeOrSize].pWrFuncPtr
           (LpRxSignal->pSignalBuffer, SignalDataPtr,LpRxUnpack->ddSignalSize);
        }
       
        else 
        #endif
        {
          /* Invoke the unpack function for the signal */
          (void)Com_UnPackRequestRead(LpRxUnpack, SignalDataPtr);                                                   
        }
        /* Check whether Rx I-PDU is enabled */
        if((PduIdType)COM_ZERO == Com_GaaRxIpduStatus[LpRxSignal->ddRxpduId])
        {
          /* Set return value to "COM_SERVICE_NOT_AVAILABLE" */
          LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;
        }
      } /* Check whether any development error has occurred */
      #if(COM_RX_SIGGROUP == STD_ON)
      else
      {
         LucReturnValue = Com_ShadowSignalCopy(SignalId - COM_RX_SIG_GRPSIG_BOUNDARY, 
          SignalDataPtr);
      }
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
** Function Name        : Com_ReceiveDynSignal                                **
**                                                                            **
** Service ID           : 0x22                                                **
**                                                                            **
** Description          : The service Com_ReceiveDynSignal returns in Length  **
**                        the length of the dynamical length signal and in    **
**                        SignalDataPtr a pointer to the data of the signal   **
**                        identified by SignalId.                             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same signal.                  **
**                        Reentrant for different signals.                    **
**                                                                            **
** Input Parameters     : SignalId                                            **
**                                                                            **
** InOut parameter      : length                                              **
**                                                                            **
** Output Parameters    : SignalDataPtr                                       **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaRxSignal            **
**                                                 Com_GaaRxIpdu              **
**                                                 Com_GaaRxTPIpdu            **
**                                                 Com_GaaRxUnpack            **
**                                                 Com_GaaRxTPStatus          **
**                                                 Com_GaaRxDynSigLength      **
**                                                 Com_GaaRxIpduStatus        **
**                                                 Com_GaaWrFuncPtr           **
**                        Function(s) invoked    : Det_ReportError()          **
**                                                 pRdFuncPtr                 **
**                                                 pWrFuncPtr                 **
*******************************************************************************/
#if(COM_RX_DYN_SUPPORT == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, COM_CODE) Com_ReceiveDynSignal(Com_SignalIdType SignalId, 
  P2VAR(void, AUTOMATIC, COM_VAR) SignalDataPtr, 
  P2VAR(uint16, AUTOMATIC, COM_VAR) length)
{
  /* Pointer to Rx Signal structure */
  P2CONST(Com_RxSignal, AUTOMATIC, COM_CONST) LpRxSignal;
  /* Pointer to Rx Unpack structure */
  P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST) LpRxUnpack;
  /* Pointer to Rx Ipdu */
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu;

  /* #2142 : separate DYN PDU from TP */
  #if(COM_RX_TP_SUPPORT == STD_ON)
  /* Pointer to Rx TP structure */
  P2CONST(Com_RxTPIpdu, AUTOMATIC, COM_CONST) LpRxTPIpdu;
  #endif
  
   #if((COM_RX_SIGNAL_UBDMREPLACE == STD_ON)|| \
                        (COM_RX_SIGNAL_FILTER == STD_ON) || \
                         (COM_RX_SIGNAL_INVALID == STD_ON))
  uint8 LucSigTypeOrSize;
  #endif
  /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Variable to hold the existing length of the dynamic signal */
  
  /* Initialize DET error flag to false */
  LucReturnValue = (uint8)E_OK;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_RECEIVEDYNSIGNAL);
  /* Check whether signal ID is out of range */
  COM_DET_RX_SIGNALID_RANGE_CHECK_FLAG(COMSERVICEID_RECEIVEDYNSIGNAL);
  /* Check whether signal data pointer is equal to NULL */
  COM_DET_SIGNAL_DATA_PTR(COMSERVICEID_RECEIVEDYNSIGNAL);
  /* Check whether Common pointer is NULL */
  COM_DET_COMMON_PTR_CHECK_FLAG(length, COMSERVICEID_RECEIVEDYNSIGNAL);
  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif /* COM_DEV_ERROR_DETECT */
  {
    /* Get the pointer to  Rx signal */
    LpRxSignal = &Com_GaaRxSignal[SignalId];
    /* Get the pointer to  Rx Ipdu */
    LpRxIpdu = &Com_GaaRxIpdu[LpRxSignal->ddRxpduId];
    /* #2142 : separate DYN PDU from TP */
    #if(COM_RX_TP_SUPPORT == STD_ON)
    /* Get the pointer to Rx TP structure */
    LpRxTPIpdu = &Com_GaaRxTPIpdu[LpRxIpdu->ucRxTPRef];
    #endif
    /* Get the pointer to RxUnpack structure */
    LpRxUnpack = &Com_GaaRxUnpack[LpRxSignal->ddRxUnpackIndex];

    if(LpRxIpdu->ucIpduType == COM_DYN_IPDU)
    {
      #if(COM_RX_TP_SUPPORT == STD_ON)    
      if(LpRxIpdu->ucRxTPRef != COM_INVALID_NONE)
      {
        if(COM_ZERO != (Com_GaaRxTPStatus[LpRxTPIpdu->ucRxTPStatusRef] & 
                       (LpRxTPIpdu->ucRxTPStatusMask)))
        {
          /* If TP Buffer is locked, return COM_BUSY */
          LucReturnValue = (uint8)COM_BUSY;
        }
      }
      #endif

      if(LucReturnValue == (uint8)E_OK)
      {
        if(*length >= (uint16)Com_GaaRxDynSigLength[LpRxIpdu->ddRxIpduDynLegthRef])
        {
          /* Get the dynamic signal length */
          *length = (uint16)Com_GaaRxDynSigLength[LpRxIpdu->ddRxIpduDynLegthRef];
          #if((COM_RX_SIGNAL_UBDMREPLACE == STD_ON)|| \
                          (COM_RX_SIGNAL_FILTER == STD_ON) || \
                           (COM_RX_SIGNAL_INVALID == STD_ON))
          /* Check whether signal buffer is equal to NULL */
          if(LpRxSignal->pSignalBuffer != NULL_PTR)
          {
            LucSigTypeOrSize = LpRxUnpack->ucSignalType;
            /* Invoke the write function to unpack the data from the signal buffer
            and copy to SignalDataPtr */
            Com_GaaWrFuncPtr[LucSigTypeOrSize].pWrFuncPtr
             (LpRxSignal->pSignalBuffer, SignalDataPtr, (PduLengthType)(*length));
          }
          else 
          #endif
          {
            /* Invoke the unpack function for the signal */
            (void)Com_UnPackRequestRead(LpRxUnpack, SignalDataPtr);
          }
          /* Check whether Rx I-PDU is enabled */
          if((PduIdType)COM_ZERO == Com_GaaRxIpduStatus[LpRxSignal->ddRxpduId])
          {
            /* Set return value to "COM_SERVICE_NOT_AVAILABLE" */
            LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;
          }
        }
        else
        {
          /* Set return value to "E_NOT_OK" */
          LucReturnValue = (uint8)E_NOT_OK;
        }
      }
    }
    else
    {
      /* Set return value to "E_NOT_OK" */
      LucReturnValue = (uint8)E_NOT_OK;
    }
  } /* Check whether any development error has occurred */
  /* Return value */
  return(LucReturnValue);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_ReceiveShadowSignal                             **
**                                                                            **
** Service ID           : 0x0f                                                **
**                                                                            **
** Description          : The service Com_ReceiveShadowSignal updates the     **
**                        group signal which is referenced by SignalDataPtr   **
**                        with the data in the shadow buffer.                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same signal.                  **
**                        Reentrant for different signals.                    **
**                                                                            **
** Input Parameters     : SignalId                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : SignalDataPtr                                       **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    : Det_ReportError()          **
**                                                 Com_ShadowSignalCopy()     **
*******************************************************************************/

#if(COM_RX_SIGGROUP == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_ReceiveShadowSignal
(Com_SignalIdType SignalId, P2VAR(void, AUTOMATIC, COM_VAR) SignalDataPtr)
{
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Initialize error flag to false */
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_RECEIVESHADOWSIGNAL);
  /* Check whether signal ID is out of range */
  COM_DET_SIGNALID_RX_USS_RANGE_CHECK_FLAG(COMSERVICEID_RECEIVESHADOWSIGNAL);
  /* Check whether signal data pointer is equal to NULL */
  COM_DET_SIGNAL_DATA_PTR(COMSERVICEID_RECEIVESHADOWSIGNAL);

  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif /* COM_DEV_ERROR_DETECT */
  {
    (void)Com_ShadowSignalCopy(SignalId - COM_RX_SIG_GRPSIG_BOUNDARY, SignalDataPtr);                                         
  } /* Check whether any development error has occurred */
}

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/* #7525, #7744, #7803 start */
/*******************************************************************************
** Function Name        : Com_ReceiveSignalGroup                              **
**                                                                            **
** Service ID           : 0x0E                                                **
**                                                                            **
** Description          : This function copies the received signal group from **
**                        the I-PDU to the shadow buffer. After this call,    **
**                        the signals from this signal group could be copied  **
**                        from the shadow buffer to the upper layer by a call **
**                        of Com_ReceiveShadowSignal().                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different signal groups.              **
**                        Non-Reentrant for the same signal group.            **
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
** Remarks              : Global Variable(s)     :  Com_GaaRxSigGroup         **
**                                                  Com_GaaRxIpduStatus       **
**                        Function(s) invoked    :  Det_ReportError()         **
**                                                  pWrFuncPtr                **
*******************************************************************************/
#if(COM_RX_SIGGROUP == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, COM_CODE) Com_ReceiveSignalGroup
  (Com_SignalGroupIdType SignalGroupId)
{
  /* Pointer to Rx Signal Group structure */
  P2CONST(Com_RxSigGroup, AUTOMATIC, COM_CONST) LpRxSigGroup;
  /* Pointer to Pack signal group  structure */
  P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpPackSigGroup;
  #if(COM_RX_TP_SUPPORT == STD_ON)
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu;
  P2CONST(Com_RxTPIpdu, AUTOMATIC, COM_CONST) LpRxTPIpdu;
  #endif
  /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Initialize error flag to false */
  LucReturnValue = (uint8)E_OK;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_RECEIVESIGNALGROUP);
  /* Check whether signal group ID is out of range */
  COM_DET_RXSIGNALGROUPID_RANGE_CHECK_FLAG(COMSERVICEID_RECEIVESIGNALGROUP);
  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif /* COM_DEV_ERROR_DETECT */
  {
    /* Get the pointer to  Rx signal group structure */
    LpRxSigGroup = &Com_GaaRxSigGroup[SignalGroupId];
    #if((COM_ENABLE_SIGNALGROUP_ARRAY_API == STD_ON) && (COM_RX_SIGINGROUP_ARRAY_ACCESS == STD_ON))
    if(LpRxSigGroup->blArrayAccess == COM_TRUE)
    {
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;
    }

    if(LucReturnValue == (uint8)E_OK)
    #endif
    {
      #if(COM_RX_TP_SUPPORT == STD_ON)
      
      /* Get the pointer to Tx IPdu structure */
      LpRxIpdu =  &Com_GaaRxIpdu[LpRxSigGroup->ddRxpduId];
      
      if(LpRxIpdu->ucRxTPRef != COM_INVALID_NONE)
      {
        /* Get the pointer to TP structure  */
        LpRxTPIpdu = &Com_GaaRxTPIpdu[LpRxIpdu->ucRxTPRef];
        if((Com_GaaRxTPStatus[LpRxTPIpdu->ucRxTPStatusRef] 
        & (LpRxTPIpdu->ucRxTPStatusMask)) != COM_ZERO)
        {
          LucReturnValue = (uint8)COM_BUSY;
        }
      }
      if(LucReturnValue == (uint8)E_OK)
      #endif
      {
        /* Check whether Rx I-PDU is enabled */
        if((PduIdType)COM_ZERO == Com_GaaRxIpduStatus[LpRxSigGroup->ddRxpduId])
        {
          /* Set return value to "COM_TRUE" */
          LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;
        }
        /* Get the pointer to PackSigGroup structure */
        LpPackSigGroup = LpRxSigGroup->pPackShadowBuffer;
        #if((COM_RX_SIGGROUP_INVALID == STD_ON) || \
                                     (COM_RX_SIGGROUP_UBDMREPLACE == STD_ON))
        /* Check whether timeout replacement value is configured */
        
        if((LpRxSigGroup->pPackSigGrpBuffer) != NULL_PTR)
        {
          /* Invoke the write function to pack the signal group buffer into shadow
          buffer */
          /* polyspace:begin<RTE: NIP : Not a defect : No Action Planned > Initialized pointer */
          (void)Com_PackSigGrpArray(LpPackSigGroup, LpRxSigGroup->pPackSigGrpBuffer->pWrBuffer, LpPackSigGroup->pWrBuffer);    
          /* polyspace:end<RTE: NIP : Not a defect : No Action Planned > Initialized pointer */
        }
        else
        #endif
        {
          /* Invoke the pack function to pack the I-PDU buffer into shadow buffer
          */
          /* polyspace:begin<RTE: NIP : Not a defect : No Action Planned > Initialized pointer */
          (void)Com_PackSigGrpArray(LpPackSigGroup, LpRxSigGroup->pIpduBuffer, LpPackSigGroup->pWrBuffer);
          /* polyspace:end<RTE: NIP : Not a defect : No Action Planned > Initialized pointer */
        }
      } /* Check whether any development error has occurred */
    }
  }
  /* Return value */
  return(LucReturnValue);
}

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif


/*******************************************************************************
** Function Name        : Com_ReceiveSignalGroupArray                         **
**                                                                            **
** Service ID           : 0x24                                                **
**                                                                            **
** Description          : This function copies the received signal group from **
**                        the I-PDU to the shadow buffer. After this call,    **
**                        the signals from this signal group could be copied  **
**                        from the shadow buffer to the upper layer by a call **
**                        of Com_ReceiveShadowSignal().                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different signal groups.              **
**                        Non-Reentrant for the same signal group.            **
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
** Remarks              : Global Variable(s)     :  Com_GaaRxSigGroup         **
**                                                  Com_GaaRxIpduStatus       **
**                        Function(s) invoked    :  Det_ReportError()         **
**                                                  pWrFuncPtr                **
*******************************************************************************/

#if(COM_RX_SIGGROUP == STD_ON)
#if((COM_ENABLE_SIGNALGROUP_ARRAY_API == STD_ON) && (COM_RX_SIGINGROUP_ARRAY_ACCESS == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, COM_CODE) Com_ReceiveSignalGroupArray(Com_SignalGroupIdType SignalGroupId, P2VAR (uint8, AUTOMATIC, COM_VAR)SignalGroupArrayPtr)
{
  /* Pointer to Rx Signal Group structure */
  P2CONST(Com_RxSigGroup, AUTOMATIC, COM_CONST) LpRxSigGroup;
  /* Pointer to Pack signal group  structure */
  P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpPackSigGroup;
  #if(COM_RX_TP_SUPPORT == STD_ON)
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu;
  P2CONST(Com_RxTPIpdu, AUTOMATIC, COM_CONST) LpRxTPIpdu;
  #endif
  /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Initialize error flag to false */
  LucReturnValue = (uint8)E_OK;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_RECEIVESIGNALGROUPARRAY);
  /* Check whether signal group ID is out of range */
  COM_DET_RXSIGNALGROUPID_RANGE_CHECK_FLAG(COMSERVICEID_RECEIVESIGNALGROUPARRAY);
  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif /* COM_DEV_ERROR_DETECT */
  {
    /* Get the pointer to  Rx signal group structure */
    LpRxSigGroup = &Com_GaaRxSigGroup[SignalGroupId];  
    #if(COM_RX_TP_SUPPORT == STD_ON)
    /* Get the pointer to Tx IPdu structure */
    LpRxIpdu =  &Com_GaaRxIpdu[LpRxSigGroup->ddRxpduId];
    
    if(LpRxIpdu->ucRxTPRef != COM_INVALID_NONE)
    {
      /* Get the pointer to TP structure  */
      LpRxTPIpdu = &Com_GaaRxTPIpdu[LpRxIpdu->ucRxTPRef];
      if((Com_GaaRxTPStatus[LpRxTPIpdu->ucRxTPStatusRef] 
      & (LpRxTPIpdu->ucRxTPStatusMask)) != COM_ZERO)
      {
        LucReturnValue = (uint8)COM_BUSY;
      }
    }
    if(LucReturnValue == (uint8)E_OK)
    #endif
    {
      /* Check whether Rx I-PDU is enabled */
      if((PduIdType)COM_ZERO == Com_GaaRxIpduStatus[LpRxSigGroup->ddRxpduId])
      {
        /* Set return value to "COM_TRUE" */
        LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;
      }
      /* Get the pointer to PackSigGroup structure */
      LpPackSigGroup = LpRxSigGroup->pPackShadowBuffer;
      #if((COM_RX_SIGGROUP_INVALID == STD_ON) || \
                                   (COM_RX_SIGGROUP_UBDMREPLACE == STD_ON))
      /* Check whether timeout replacement value is configured */
      
      if((LpRxSigGroup->pPackSigGrpBuffer) != NULL_PTR)
      {
        /* Invoke the write function to pack the signal group buffer into shadow
        buffer */
        /* polyspace:begin<RTE: NIP : Not a defect : No Action Planned > Initialized pointer */
        (void)Com_PackSigGrpArray(LpPackSigGroup, LpRxSigGroup->pPackSigGrpBuffer->pWrBuffer, SignalGroupArrayPtr);
        /* polyspace:end<RTE: NIP : Not a defect : No Action Planned > Initialized pointer */
      }
      else
      #endif
      {
        /* Invoke the pack function to pack the I-PDU buffer into shadow buffer
        */
        (void)Com_PackSigGrpArray(LpPackSigGroup, LpRxSigGroup->pIpduBuffer, SignalGroupArrayPtr);
      }
    } /* Check whether any development error has occurred */
  }
  /* Return value */
  return(LucReturnValue);
}

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/* #7525, #7744, #7803 end */
/*******************************************************************************
** Function Name        : Com_ShadowSignalCopy                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function copies the received signal group from **
**                        the I-PDU to the shadow buffer. After this call,    **
**                        the signals from this signal group could be copied  **
**                        from the shadow buffer to the upper layer by a call **
**                        of Com_ReceiveShadowSignal().                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different signal groups.              **
**                        Non-Reentrant for the same signal group.            **
**                                                                            **
** Input Parameters     : SignalId                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : SignalDataPtr                                       **
**                                                                            **
** Return parameter     : LucReturnValue                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :  Com_GaaRxSigInGrp         **
**                                                  Com_GaaRxUnpack           **
**                        Function(s) invoked    :  pRdFuncPtr                **
*******************************************************************************/
/* #7525 start */
#if(COM_RX_SIGGROUP == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, COM_CODE) Com_ShadowSignalCopy
(Com_SignalIdType SignalId, P2VAR(void, AUTOMATIC, COM_VAR) SignalDataPtr)
{
  /* Pointer to Rx Signal Group structure */
  P2CONST(Com_RxSigInGrp, AUTOMATIC, COM_CONST) LpRxSigInGrp;
  /* Pointer to Rx Unpack structure */
  P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST) LpRxUnpack;
  #if((COM_ENABLE_SIGNALGROUP_ARRAY_API == STD_ON) && (COM_RX_SIGINGROUP_ARRAY_ACCESS == STD_ON))
  P2CONST(Com_RxSigGroup, AUTOMATIC, COM_CONST) LpRxSigGroup;
  #endif

  uint8 LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;

  /* Get the pointer to  Rx signal in group */
  LpRxSigInGrp = &Com_GaaRxSigInGrp[SignalId];

  #if((COM_ENABLE_SIGNALGROUP_ARRAY_API == STD_ON) && (COM_RX_SIGINGROUP_ARRAY_ACCESS == STD_ON))
  LpRxSigGroup = &Com_GaaRxSigGroup[LpRxSigInGrp->ddSigGrpIndex];
  if(LpRxSigGroup->blArrayAccess != COM_TRUE)  
  #endif
  {  
    /* Get the pointer to RxUnpack structure */
    LpRxUnpack = &Com_GaaRxUnpack[LpRxSigInGrp->ddRxUnpackIndex];
    /* Invoke read function to unpack the data from the I-PDU buffer to
    SignalDataPtr */
    (void)Com_UnPackRequestRead(LpRxUnpack, SignalDataPtr);
    LucReturnValue = (uint8)E_OK;
  }
  return LucReturnValue;
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/* #7525 end */
/* polyspace:end<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : No Action Planned > configured memory access index */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
