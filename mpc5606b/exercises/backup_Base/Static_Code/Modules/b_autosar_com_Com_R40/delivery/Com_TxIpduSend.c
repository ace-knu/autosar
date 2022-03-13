/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Com_TxIpduSend.c                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Com Module                                            **
**                                                                            **
**  PURPOSE   : Provision of I-PDU sending functions.                         **
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
** 2.2.0     16-Apr-2017   Chan Kim    Internal Redmine #7861, #7707, #7525   **
** 2.1.9     20-Mar-2017   Chan Kim    Internal Redmine #7851                 **
** 2.1.7     30-Nov-2016   Chan Kim    Internal Redmine #6807                 **
** 2.1.4     19-Aug-2016   Chan Kim    Internal Redmine #5813                 **
** 2.1.0     25-May-2016   Chan Kim    Internal Redmine #4998                 **
** 2.0.11    10-Mar-2016   Chan Kim    Internal Redmine #4350                 **
** 2.0.8     12-Feb-2016   Chan Kim    Internal Redmine #4158                 **
** 2.0.5     12-Jan-2016   Chan Kim    Internal Redmine #3865                 **
** 2.0.4     14-Dec-2015   Chan Kim    Internal Redmine #3434                 **
** 2.0.3     24-Nov-2015   Chan Kim    Internal Redmine #3544, #3535          **
** 1.0.17    27-Feb-2015   Chan Kim    Internal Redmine #2275                 **
** 1.0.16    27-Feb-2015   Chan Kim    Internal Redmine #2202                 **
** 1.0.14    03-Nov-2014   Chan Kim    Internal Redmine #1463, #1204, #1518   **
** 1.0.11    20-Mar-2014   Chan Kim    Internal Redmine #695                  **
** 1.0.9     11-Feb-2014   Chan Kim    Internal Redmine #605                  **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Com.h"          /* Com header file */
#include "Com_TxIpdu.h"   /* Com Tx I-PDU header file */
#include "Com_Main.h"     /* Com Main header file */
#include "Com_Pack.h"     /* Com Pack header file */
#include "Com_Error.h"    /* SchM Com header file */
#include "SchM_Com.h"     /* Com Error header file */
#if(COM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"          /* Det header file */
#endif
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version Information */
#define COM_TXIPDUSEND_C_AR_RELEASE_MAJOR_VERSION  4
#define COM_TXIPDUSEND_C_AR_RELEASE_MINOR_VERSION  0
#define COM_TXIPDUSEND_C_AR_RELEASE_REVISION_VERSION  3

/* Software version information */
#define COM_TXIPDUSEND_C_SW_MAJOR_VERSION  2
#define COM_TXIPDUSEND_C_SW_MINOR_VERSION  2

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (COM_AR_RELEASE_MAJOR_VERSION != COM_TXIPDUSEND_C_AR_RELEASE_MAJOR_VERSION)
  #error "Com_Invalid.c : Mismatch in Com Specification Major Version"
#endif

#if (COM_AR_RELEASE_MINOR_VERSION != COM_TXIPDUSEND_C_AR_RELEASE_MINOR_VERSION)
  #error "Com_Invalid.c : Mismatch in Com Specification Minor Version"
#endif

#if (COM_AR_RELEASE_REVISION_VERSION !=  \
  COM_TXIPDUSEND_C_AR_RELEASE_REVISION_VERSION)
  #error "Com_Invalid.c : Mismatch in Com Specification Revision Version"
#endif

#if (COM_SW_MAJOR_VERSION != COM_TXIPDUSEND_C_SW_MAJOR_VERSION)
  #error "Com_Invalid.c : Mismatch in Com Software Major Version"
#endif

#if (COM_SW_MINOR_VERSION != COM_TXIPDUSEND_C_SW_MINOR_VERSION)
  #error "Com_Invalid.c : Mismatch in Com Software Minor Version"
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
** Function Name        : Com_TriggerIPDUSend                                 **
**                                                                            **
** Service ID           : 0x17                                                **
**                                                                            **
** Description          : This function triggers the I-PDU with the given ID  **
*                         for transmission.                                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ComTxPduId                                          **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : It shall only be used from within I-PDU callout.    **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaTxMDTimer           **
**                                                 Com_GaaTxIpdu[]            **
**                                                 Com_GaaTxIpduStatusBit     **
**                                                 Com_GaaTxPduInfoPtr        **
**                        Function(s) invoked    : Det_ReportError()          **
**                                                 SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
**                                                 Com_Transmit()             **
**                                                 pIpduCallout()             **
*******************************************************************************/
#if(COM_TX_IPDU == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_TriggerIPDUSend(PduIdType ComTxPduId)
{
  #if((COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) || \
      (COM_TX_IPDU_TRIGGERCALLOUT == STD_ON))
  /* Pointer to Tx Ipdu structure */
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu;
  #endif
  #if(COM_TX_IPDU_TRIGGERCALLOUT == STD_ON)
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR) LpPduInfoPtr;
  #endif
  #if(COM_TX_IPDU_MINDELAY_ENABLED == STD_ON)
  /* Local variable to store Ipdu config */
  uint8 LucIpduConfig;
  #endif
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Local variable to store return value */
  uint8 LucReturnValue;
  #endif
  #if(COM_TX_IPDU_MINDELAY_ENABLED == STD_ON)
  boolean LblReturnFlag;
  LblReturnFlag = COM_TRUE;
  #endif
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Initialize error flag to false */
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_TRIGGERIPDUSEND);
  /* Check whether Tx PDU ID is out of range */
  COM_DET_TXPDUID_RANGE_CHECK_FLAG(ComTxPduId, COMSERVICEID_TRIGGERIPDUSEND);
  
  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif /* COM_DEV_ERROR_DETECT */
  {
    #if((COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) || \
         (COM_TX_IPDU_TRIGGERCALLOUT == STD_ON))
    /* Get the pointer to TxIpdu strcuture */
    LpTxIpdu = &Com_GaaTxIpdu[ComTxPduId];
    #endif
    /* Invoke Com_TxRequest() function to trigger I-PDU for transmission */
    #if((COM_TX_IPDU_MINDELAY_ENABLED == STD_ON))
    LucIpduConfig = LpTxIpdu->ucTxConfig;
    if((LucIpduConfig & COM_TX_IPDU_MDT_CONFIG_MASK) != COM_FALSE)
    {
      LblReturnFlag = COM_FALSE;
      /* Check whether minimum delay timer is set to zero */
      if(Com_GaaTxMDTimer[LpTxIpdu->ddTxMDTimerIndex] != (uint16)COM_ZERO)
      {
        SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
        Com_GaaTxIpduStatusBit[ComTxPduId] |= COM_TX_PENDING_STATUS_MASK;
        SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
        LblReturnFlag = COM_TRUE;
      }
    } /* Check whether minimum delay timer is configured for I-PDU */
    if(LblReturnFlag == COM_FALSE)
    #endif
    {
      #if(COM_TX_IPDU_TRIGGERCALLOUT == STD_ON)
      /* Get the pointer to PduInfoPtr structure */
      LpPduInfoPtr = &Com_GaaTxPduInfoPtr[ComTxPduId];
      #endif

      /* Reduce the invoking count of Protection Area - by AUTRON START */  
      #if(COM_TX_IPDU_TRIGGERCALLOUT == STD_ON)
      /* Check whether I-PDU callout is configured */
      if(LpTxIpdu->ddIpduTriggerCalloutIndex != COM_INVALID_TXID_PARAM)
      {
        /* Enter protection area */
        SchM_Enter_Com_TX_IPDU_BUFFER_PROTECTION_AREA();      
        (void)Com_TxIpduTriggerCallout(ComTxPduId, (PduInfoType *)LpPduInfoPtr);	
        /* Exit Critical Area */
        SchM_Exit_Com_TX_IPDU_BUFFER_PROTECTION_AREA();
      }
      #endif
      /* Reduce the invoking count of Protection Area - by AUTRON END */  

      /* Invoke the Com_Transmit() function to transmit an I-PDU to the lower
        layer */
      (void)Com_Transmit((PduIdType)ComTxPduId);
    }
  }/* Check whether any development error has occurred */
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#else
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_TriggerIPDUSend(PduIdType ComTxPduId)
{
  COM_UNUSED(ComTxPduId);
  /* #1204 : Dummy Function for integration with BswM Module */
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_TxRequest                                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function triggers the I-PDU with the given ID  **
*                         for transmission.                                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same PDU-ID.                  **
**                        Reentrant for different PDU-IDs.                    **
**                                                                            **
** Input Parameters     : LpTxIpdu                                            **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : It shall only be used from within I-PDU callout.    **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaTxIpdu              **
**                                                 Com_GaaTxMode              **
**                                                 Com_GaaTxIpduStatusBit     **
**                                                 Com_GaaTxReptCount         **
**                                                 Com_GaaTxDMTimer           **
**                                                 Com_GaaTxMDTimer           **                                                   
**                        Function(s) invoked    : SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
**                                                 Com_Transmit()             **
**                                                 Com_TxIpduTMSCalc          **
*******************************************************************************/
#if(COM_TX_IPDU == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
#if ((COM_TX_IPDU_TMS == STD_ON) || \
  (COM_TX_IPDU_REPETITION == STD_ON) || \
  ((COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) && (COM_TX_IPDU_GW == STD_ON))|| \
  (COM_TX_IPDU_GW == STD_ON) || \
  (COM_TX_IPDU_DM == STD_ON))
FUNC(Std_ReturnType, COM_CODE)Com_TxRequest(PduIdType LddTxPduId,
                                                                uint8 LucConfig)
#else

FUNC(Std_ReturnType, COM_CODE)Com_TxRequest(PduIdType LddTxPduId)

#endif
{
  /* Pointer to Tx mode structure */
  P2CONST(Com_TxMode, AUTOMATIC, COM_CONST) LpTxMode;
  /* Pointer to Tx Ipdu structure */
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu;
  /* Local variable to store return value */
  Std_ReturnType LenReturnValue;
  #if((COM_TX_IPDU_TMS == STD_ON)||(COM_TX_IPDU_MINDELAY_ENABLED == STD_ON))
  /* Local variable to store Ipdu config */
  uint8 LucIpduConfig;
  #endif

  /* Initialize IpduStatusBit */
  uint16 LusTxIpduStatusBit = (uint16)COM_ZERO;

  /* Local variable to store transmit flag */
  /* Initialize Transmit Flag */  
  uint8 LucTransmitFlag = COM_FALSE;

  /* Initializing return value to zero */
  LenReturnValue = (uint8)E_OK;
  /* Get the pointer to Tx Ipdu */
  LpTxIpdu = &Com_GaaTxIpdu[LddTxPduId];
  /* Get the pointer to True Tx mode */
  LpTxMode = &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex];
  #if((COM_TX_IPDU_TMS == STD_ON)||(COM_TX_IPDU_MINDELAY_ENABLED == STD_ON))
  /* Get the Tx Ipdu configuration */
  LucIpduConfig = LpTxIpdu->ucTxConfig;
  #endif
  #if (COM_TX_IPDU_TMS == STD_ON)
  if((LucIpduConfig & COM_TX_IPDU_TMS_CONFIG_MASK) != COM_FALSE)
  {
    LucTransmitFlag = Com_TxIpduTMSCalc(LddTxPduId, LucConfig);
    if(LucTransmitFlag == COM_MODE_TRANSMIT_MASK)
    {
      LpTxMode = 
      &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex+(PduIdType)COM_ONE];
    }
  }
  else
  {
    #if(COM_API_MODE_SWITCH_ENABLED == STD_ON)
    if((Com_GaaTxIpduStatusBit[LddTxPduId] & COM_TX_TMS_STATUS_MASK)
                                                                   == COM_FALSE)
    {
      LpTxMode = 
      &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex+(PduIdType)COM_ONE];
    }
    #endif
    if(((LpTxMode->ucTxMode > COM_TX_PERIODIC_MODE)))
    {
      LucTransmitFlag = COM_TRUE;
    }
  }
  #else
  {
    #if(COM_API_MODE_SWITCH_ENABLED == STD_ON)
    if((Com_GaaTxIpduStatusBit[LddTxPduId] & COM_TX_TMS_STATUS_MASK)
                                                                   == COM_FALSE)
    {
      LpTxMode = 
      &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex+(PduIdType)COM_ONE];
    }
    #endif
    if(((LpTxMode->ucTxMode > COM_TX_PERIODIC_MODE)))
    {
      LucTransmitFlag = COM_TRUE;
    }
  }  
  #endif
  if((LucTransmitFlag & (COM_ONE)) != COM_FALSE)
  {
    #if((COM_TX_IPDU_TMS == STD_ON)||(COM_TX_IPDU_DM == STD_ON) \
       ||(COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) || \
       (COM_TX_IPDU_REPETITION == STD_ON) || \
       (COM_TX_IPDU_GW == STD_ON))
    LusTxIpduStatusBit = Com_GaaTxIpduStatusBit[LddTxPduId];
    #endif
    
    #if (COM_TX_IPDU_REPETITION == STD_ON)
    /* Check whether repetition counter is not zero */
    if((((LpTxMode->ucTxMode) >= COM_TX_MIXEDNTIMES_MODE) &&
        ((LpTxMode->ucTxMode) != COM_TX_DIRECT_MODE)) && 
        ((LucConfig & COM_TX_SIGPROP_WOREPT_CONFIG_MASK) !=
                                           COM_TX_SIGPROP_WOREPT_CONFIG_MASK))
    {
      LusTxIpduStatusBit |= COM_TX_REPT_STATUS_MASK;
      #if(COM_MAINFUNC_BASED_TRANSMIT  == STD_OFF)
      Com_GaaTxReptCount[LpTxIpdu->ddTxReptIndex] = LpTxMode->ucReptCount;
      if(LpTxMode->ucReptCount != COM_ZERO)
      {
        Com_GaaTxReptSubCount[LpTxIpdu->ddTxReptIndex] 
            = LpTxMode->ucReptCount - COM_ONE;
      }
      else
      {
        Com_GaaTxReptSubCount[LpTxIpdu->ddTxReptIndex] = COM_ZERO;
      }      
      #endif
    }
    #endif    
    #if (COM_TX_IPDU_DM == STD_ON)
    /* Check whether deadline monitoring is configured */
    if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_DM_CONFIG_MASK) != COM_FALSE)
    {
      /* Check whether timer is equal to zero or Tx mode is direct */
      if(((Com_GaaTxDMTimer[LpTxIpdu->ddTxIpduDmIndex]) == (uint16)COM_ZERO) ||
                              (LpTxMode->ucTxMode >= COM_TX_MIXEDNTIMES_MODE))
      {
        LusTxIpduStatusBit |= COM_TX_DM_STATUS_MASK;
      }
    }
    #endif
    #if (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON)
    /* Check whether minimum delay timer is configured for I-PDU */
    if((LucIpduConfig & COM_TX_IPDU_MDT_CONFIG_MASK) != COM_FALSE)
    {
      /* Check whether minimum delay timer is set to zero */
      if(Com_GaaTxMDTimer[LpTxIpdu->ddTxMDTimerIndex] != (uint16)COM_ZERO)
      {
        LusTxIpduStatusBit |= COM_TX_PENDING_STATUS_MASK;
        #if(COM_MAINFUNC_BASED_TRANSMIT == STD_OFF)
        /* #1518 : Set the status bit for repetition count */
        LusTxIpduStatusBit |= COM_TX_REPT_COUNT_HANDLE_MASK;
        #endif
        LucTransmitFlag = COM_FALSE;
        #if (COM_TX_IPDU_GW == STD_ON)
        LucConfig = COM_ZERO;
        #endif
      }
    } /* Check whether minimum delay timer is configured for I-PDU */
    #endif
    #if (COM_TX_IPDU_GW == STD_ON)
    if(((LucConfig & COM_TX_SIG_GW_CONFIG_MASK) != COM_FALSE))
    {
      LusTxIpduStatusBit |= COM_TX_RETRY_STATUS_MASK;
      LucTransmitFlag = COM_FALSE;
    }
    #endif
    /* #2275 : Polyspace Runtime Error Red fixed */
    SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
    
    #if((COM_TX_IPDU_TMS == STD_ON)||(COM_TX_IPDU_DM == STD_ON) \
       ||(COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) || \
       (COM_TX_IPDU_REPETITION == STD_ON) || \
       (COM_TX_IPDU_GW == STD_ON))
    Com_GaaTxIpduStatusBit[LddTxPduId] = LusTxIpduStatusBit;
    #endif

    
    /* Invoke the Com_Transmit() function to transmit an I-PDU to the lower
    layer */
    #if ((COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) || (COM_TX_IPDU_GW == STD_ON))
    if(LucTransmitFlag != COM_FALSE)
    #endif
    {
      LusTxIpduStatusBit |= COM_TX_MAINFUNC_SEND_STATUS_MASK;
      Com_GaaTxIpduStatusBit[LddTxPduId] = LusTxIpduStatusBit;
      SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
      #if(COM_MAINFUNC_BASED_TRANSMIT == STD_OFF)
      LenReturnValue = Com_Transmit(LddTxPduId);
      #endif      
    }
    #if ((COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) || (COM_TX_IPDU_GW == STD_ON))
    else
    {
      SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
    }
    #endif
    
  }/* if(LucTransmitFlag == COM_TRUE) */
  return(LenReturnValue);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_SendSigTMS                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function added for cyclomatic complexity reduction. **
**                        It validates TMS for a signal when Com_SendSignal   ** 
**                        is called Ipdu callout                              **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : SignalDataPtr,LpTxSignal                            **
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
**                        Function(s) invoked    :  SchM_Enter_xxx()          **
**                                                  SchM_Exit_xxx             **                                                                                       
*******************************************************************************/
#if(COM_TX_IPDU_TMS == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, COM_CODE) Com_SendSigTMS(P2CONST(Com_TxSignal, AUTOMATIC, COM_CONST) 
  LpTxSignal, P2CONST(void, AUTOMATIC, COM_CONST) SignalDataPtr)
{
  /* Pointer to Filter structure */
  P2CONST(Com_FilterNever, AUTOMATIC, COM_CONST) LpFilter;
  uint8 LucSigConfig;
  LucSigConfig = LpTxSignal->ucTxSigConfig;
  /* Check whether filter is configured */
  if((LucSigConfig & COM_TX_SIG_FILTER_CONFIG_MASK) != COM_FALSE)
  {
    LpFilter =(P2CONST(Com_FilterNever, AUTOMATIC, COM_CONST))
    (LpTxSignal->pFilter);
    /* Invoke filter function and get the return value */
    /* Reset the previous value in MASKED_NEW_DIFFERS_MASKED_OLD filter, 
	  when Rx Timeout is occurred - Fixed by AUTRON START*/	
	  /* polyspace:begin<RTE: COR : Not a defect : No Action Planned > configured memory access index */
	  /* polyspace:begin<RTE: NIP : Not a defect : No Action Planned > Initialized pointer */
	  /* polyspace:begin<RTE: NIV : Not a defect : No Action Planned > initialized variable */
    if(COM_TRUE == (LpFilter->pFilterFuncPtr)(LpFilter, SignalDataPtr, COM_ZERO))
    /* Reset the previous value in MASKED_NEW_DIFFERS_MASKED_OLD filter, 
	  when Rx Timeout is occurred - Fixed by AUTRON END*/		
    {
      /* Signal bit(1ST bit) will be turned true */
      LucSigConfig |= COM_TX_SIG_TMS_STATUS_MASK;
      /* Enter protection area */
      SchM_Enter_Com_TX_TMS_STATUS_PROTECTION_AREA();
      /* Set the filter status to true */
      *(LpFilter->pFilterStatus) |= (LpFilter->ucFltrStsMask);
      /* Exit protection area */
      SchM_Exit_Com_TX_TMS_STATUS_PROTECTION_AREA();
    }
    else
    {
      /* Enter protection area */
      SchM_Enter_Com_TX_TMS_STATUS_PROTECTION_AREA();
      /* Set the filter status to false */
      *(LpFilter->pFilterStatus) &= (uint8) (~(LpFilter->ucFltrStsMask));
      /* Exit protection area */
      SchM_Exit_Com_TX_TMS_STATUS_PROTECTION_AREA();
    }
    /* polyspace:end<RTE: COR : Not a defect : No Action Planned > configured memory access index */
	  /* polyspace:end<RTE: NIP : Not a defect : No Action Planned > Initialized pointer */
	  /* polyspace:end<RTE: NIV : Not a defect : No Action Planned > initialized variable */
	  
    /* #3434 cyclic PDU handling in case of TMS switch */
    if((uint8)(LucSigConfig & COM_TX_SIG_PROPERTY_CONFIG_MASK) == 
    COM_TX_SIG_PENDING_PROPERTY)
    {
      (void)Com_TxIpduTMSCalc(LpTxSignal->ddTxIpduIndex, LucSigConfig);
    }
  } /* Check whether filter is configured */
  return(LucSigConfig);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_TxIpduTMSCalc                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Internal function to calculate transmission mode    **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LddTxPduId                                          **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Com_GaaTxIpduStatusBit,       **
**                                              Com_GaaFilterStatus           **
**                                              Com_GaaTxIpdu                 **
**                                              Com_GaaTxMode                 **
**                        Function(s) invoked : SchM_Enter_xxx,               **
**                                              SchM_Exit_xxx                 **
*******************************************************************************/
#if((COM_TX_IPDU_TMS == STD_ON) && (COM_TX_IPDU == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, COM_CODE) Com_TxIpduTMSCalc
                                (PduIdType LddTxPduId, uint8 LucConfig)
{
  /* Pointer to Tx Ipdu structure */
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu;
  P2CONST(uint8, AUTOMATIC, COM_CONST) LpFilterStatus;
  P2CONST(Com_TxMode, AUTOMATIC, COM_CONST) LpTxMode;
  uint16 LusTxIpduStatusBit;
  uint8 LucFltrStatusCount;
  boolean LblFilterResult;
  uint8 LucTransmitFlag;
  uint8 LucTMSResult;  
  uint8 LucFilterStatusIndex;
  LucTransmitFlag = COM_ZERO;
  LblFilterResult = COM_TRUE;
  LucTMSResult = (LucConfig & COM_TX_SIG_TMS_STATUS_MASK);
  /* Get the pointer to Tx Ipdu */
  LpTxIpdu = &Com_GaaTxIpdu[LddTxPduId];  
  /* Get the pointer to True Tx mode */
  LpTxMode = &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex];
  if(((Com_GaaTxIpduStatusBit[LddTxPduId] & COM_TX_TMS_STATUS_MASK) !=
                                                                LucTMSResult))
  {
    SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
    LusTxIpduStatusBit = Com_GaaTxIpduStatusBit[LddTxPduId];
    /* Initialize filter status to false */
    LblFilterResult = COM_FALSE;
    if(COM_FALSE == LucTMSResult)
    {
      /* Get the pointer to filter status */
      LucFilterStatusIndex = LpTxIpdu->pTxModeSelect->ucFilterStatusIndex;
      LpFilterStatus =
      &Com_GaaFilterStatus[LucFilterStatusIndex];
      /* Get the counter */
      LucFltrStatusCount = LpTxIpdu->pTxModeSelect->ucFilterStatusCount;
      /* Loop for all the signals configured for filtering */
      do
      {
        /* Decrement the filter status count */
        LucFltrStatusCount--;
        /* Check whether filter status is set to true */
        if(*LpFilterStatus != COM_ZERO)
        {
          /* Set filter result to true */
          LblFilterResult = COM_TRUE;
          /* Set filter status count to zero to break the loop */
          LucFltrStatusCount = COM_ZERO;
        }

        /* Increment the filter status pointer to point to n filter status
           area */
        LucFilterStatusIndex++;
        LpFilterStatus =
        &Com_GaaFilterStatus[LucFilterStatusIndex];
      }while(LucFltrStatusCount != COM_ZERO);

      /* Check whether filter result is set to true */
      if(COM_FALSE == LblFilterResult)
      {
        LusTxIpduStatusBit &= (uint16)(~COM_TX_TMS_STATUS_MASK);
        /* Get the pointer to false Tx mode */
        LpTxMode = 
        &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex+(PduIdType)COM_ONE];
        LucTransmitFlag |= COM_FALSE_MODE_INDICATION_MASK;
      }
    }
    else
    {
      /* Set True Mode Status */
      LusTxIpduStatusBit |= COM_TX_TMS_STATUS_MASK;
    }
    /* Check whether filter output is false */
    if(COM_FALSE == LblFilterResult)
    {
      /* Check whether transmission mode is none */
      if((LpTxMode->ucTxMode != COM_TX_NONE_MODE) && (LpTxMode->ucTxMode != 
      COM_TX_PERIODIC_MODE))
      {
        /* Transmission flag true */
        LucTransmitFlag |= COM_TRUE;
      }
      #if (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON)
      /* Check whether minimum delay timer is configured */
      if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_MDT_CONFIG_MASK) != COM_ZERO)
      {
        /* Clear Tx Pending Status Mask */
        LusTxIpduStatusBit &= (uint16)(~COM_TX_PENDING_STATUS_MASK);
      }
      #endif
      /* Check whether its periodic or mixed */
      if((LpTxMode->ucTxMode <= COM_TX_MIXEDNTIMES_MODE) &&
         (LpTxMode->ucTxMode != COM_TX_NONE_MODE))
      {
        /* Set status bit to reset periodic timer */
        LusTxIpduStatusBit |= COM_TX_PT_STATUS_MASK;
      }
      else
      {
        /* Clear Periodic timer status bit */
        LusTxIpduStatusBit &= (uint16)(~COM_TX_PT_STATUS_MASK);
      }
    }
    /* Update the status bits into global variable */
    Com_GaaTxIpduStatusBit[LddTxPduId] = LusTxIpduStatusBit;
    SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
  }
  else if(COM_FALSE == LucTMSResult)
  {
    /* Get the pointer to false transmission mode */
    LpTxMode = 
    &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex+(PduIdType)COM_ONE];
    LucTransmitFlag |= COM_FALSE_MODE_INDICATION_MASK;
  }
  else
  {
    /* To avoid QAC warning */
  }
  if(COM_TRUE == LblFilterResult)
  {
    if(((LucConfig & COM_TX_SIG_PROPERTY_CONFIG_MASK) >
        COM_TX_SIG_PENDING_PROPERTY) &&
       ((LpTxMode->ucTxMode > COM_TX_PERIODIC_MODE)))
    {
      LucTransmitFlag |= COM_TRUE;
    }
  }  
  return(LucTransmitFlag);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/* polyspace:end<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : No Action Planned > configured memory access index */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
