/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Com_Main.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Com Module                                            **
**                                                                            **
**  PURPOSE   : Provision of scheduled functions.                             **
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
** 2.2.3     08-Dec-2017   Chan Kim    Internal Redmine #10849, #10851, #10911**
** 2.2.2     01-Sep-2017   Chan Kim    Internal Redmine #9784, #9980          **
** 2.2.1     24-Aug-2017   Chan Kim    Internal Redmine #9652, #9657, #9740   **
** 2.2.0     16-Apr-2017   Chan Kim    Internal Redmine #7861, #7707, #7803,  **
**                                     #7744, #7830, #7525                    **
** 2.1.9     20-Mar-2017   Chan Kim    Internal Redmine #7851                 **
** 2.1.7     30-Nov-2016   Chan Kim    Internal Redmine #6806, #6807          **
** 2.1.6     08-Nov-2016   Chan Kim    Internal Redmine #6557                 **
** 2.1.4     19-Aug-2016   Chan Kim    Internal Redmine #5813                 **
** 2.1.3     12-Jul-2016   Chan Kim    Internal Redmine #5550                 **
** 2.1.0     25-May-2016   Chan Kim    Internal Redmine #4998                 **
** 2.0.13    13-May-2016   Chan Kim    Internal Redmine #4806, #4757, #4842   **
**                                     #3959, #4853, #4908                    **
** 2.0.12    08-Apr-2016   Chan Kim    Internal Redmine #4546                 **
** 2.0.11    10-Mar-2016   Chan Kim    Internal Redmine #4349                 **
** 2.0.10    25-Feb-2016   Chan Kim    Internal Redmine #4250                 **
** 2.0.9     19-Feb-2016   Chan Kim    Internal Redmine #4186                 **
** 2.0.8     12-Feb-2016   Chan Kim    Internal Redmine #4138, #4109, #4139,  **
**                                     #4140, #4158                           **
** 2.0.5     12-Jan-2016   Chan Kim    Internal Redmine #3864, #3865          **
** 2.0.4     14-Dec-2015   Chan Kim    Internal Redmine #3434, #3447          **
** 2.0.3     24-Nov-2015   Chan Kim    Internal Redmine #3544, #3535          **
** 2.0.2     19-Sep-2015   Chan Kim    Internal Redmine #3182                 **
** 1.0.17    02-Apr-2015   Chan Kim    Internal Redmine #2421                 **
** 1.0.16    27-Feb-2015   Chan Kim    Internal Redmine #2202                 **
** 1.0.15    09-Feb-2015   Chan Kim    Internal Redmine #2142                 **
** 1.0.14    03-Nov-2014   Chan Kim    Internal Redmine #1463, #1517, #1519,  **
**                                     #1329, #1504, #1518                    **
** 1.0.11    20-Mar-2014   Chan Kim    Internal Redmine #693, #694, #696, #730**
** 1.0.9     11-Feb-2014   Chan Kim    Internal Redmine #605                  **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Com.h"          /* Com header file */
#include "Com_Main.h"     /* Com Main header file */
#include "Com_TxIpdu.h"   /* Com Tx I-PDU header file */
#include "Com_Pack.h"     /* Com Pack header file */
#include "Com_UnPack.h"   /* Com UnPack header file */
#include "SchM_Com.h"     /* SchM Com header file */
#include "Com_Cbk.h"      /* Com Cbk header file */
#include "PduR_Com.h"     /* PduR Com header file */
#include "Com_Error.h"    /* Com Error header file */
#include "Com_IpduGrp.h"  /* Com Ipdu Group header file */
#if(COM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"          /* Det header file */
#endif
#if(COM_IDSM_SUPPORT == STD_ON)
#include "IdsM_Cbk.h"     /* IdsM Cbk header file */
#endif
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COM_MAIN_C_AR_RELEASE_MAJOR_VERSION  4
#define COM_MAIN_C_AR_RELEASE_MINOR_VERSION  0
#define COM_MAIN_C_AR_RELEASE_REVISION_VERSION  3

/* Software Version Information */
#define COM_MAIN_C_SW_MAJOR_VERSION  2
#define COM_MAIN_C_SW_MINOR_VERSION  2

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if(COM_AR_RELEASE_MAJOR_VERSION != COM_MAIN_C_AR_RELEASE_MAJOR_VERSION)
  #error "Com_Main.c : Mismatch in Com Specification Major Version"
#endif

#if(COM_AR_RELEASE_MINOR_VERSION != COM_MAIN_C_AR_RELEASE_MINOR_VERSION)
  #error "Com_Main.c : Mismatch in Com Specification Minor Version"
#endif

#if(COM_AR_RELEASE_REVISION_VERSION != COM_MAIN_C_AR_RELEASE_REVISION_VERSION)
  #error "Com_Main.c : Mismatch in Com Specification Revision Version"
#endif

#if(COM_SW_MAJOR_VERSION != COM_MAIN_C_SW_MAJOR_VERSION)
  #error "Com_Main.c : Mismatch in Com Software Major Version"
#endif

#if(COM_SW_MINOR_VERSION != COM_MAIN_C_SW_MINOR_VERSION)
  #error "Com_Main.c : Mismatch in Com Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define COM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* This global array holds the memory size of signal based on its type */
CONST(uint8, COM_CONST) Com_GaaSigMemSize[COM_FIVE] 
= {COM_ONE, COM_TWO, COM_FOUR, COM_FOUR, COM_ZERO};
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/* polyspace:begin<MISRA-C:8.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #7283) */
/* polyspace:begin<RTE: NIV : Not a defect : No Action Planned > initialized variable */
/* polyspace:begin<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:begin<RTE: OBAI : Not a defect : No Action Planned > configured memory access index */

/*******************************************************************************
** Function Name        : Com_MainFunctionRx                                  **
**                                                                            **
** Service ID           : 0x18                                                **
**                                                                            **
** Description          : This function perform the processing of the Com     **
**                        reception activities that are not directly initiated**
**                        by the calls from the RTE and PDU Router.           **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Cyclic                                              **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GusRxWriteIndex        **
**                                                 Com_GusRxReadStatus        **
**                                                 Com_GaaReceiveHistoryList  **
**                                                 Com_GaaRxIpdu              **
**                                                 Com_GaaRxPduInfoPtr        **
**                                                 Com_GaaRxGWIpduStatus      **
**                                                 Com_GaaRxDMTimer           **
**                        Function(s) invoked    : Det_ReportError()          **
**                                                 SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
**                                                 Com_RxSigProcessing()      **
**                                                 Com_RxSigGrpProcessing()   **
**                                                 Com_RxUpdateDmTimers()     **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_MainFunctionRx(void)
{
  #if(COM_RX_IPDU == STD_ON)
  #if((COM_RX_SIG_GATEWAY == STD_ON) || (COM_RX_SIGGROUP_GW == STD_ON) || \
       (COM_RX_IPDU_DEFERRED == STD_ON) || (COM_RX_IPDU_DM == STD_ON))
  /* Pointer to Rx I-Pdu structure */
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu;
  /* Local variable to store Rx config */
  uint8 LucRxConfig;
  /* Local variable to store Rx PduId */
  PduIdType LddComRxPduId;
  #endif
  #if(COM_RX_IPDU_HISTORY_LIST > 1)
  /* Local variable to store read index */
  uint16 LusReadIndex;
  #endif
  /* Local variable to store write index  */
  uint16 LusWriteIndex;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Initialize error flag to false */
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_MAINFUNCTIONRX);
  if(LucReturnValue == (uint8)E_OK)
  #endif
  {
    /* Copy the write index into local variable to process */
    LusWriteIndex = Com_GusRxWriteIndex;
    #if(COM_RX_IPDU_HISTORY_LIST > 1)
    /* Process Rx I-PDUs */
    LusReadIndex = Com_GusRxReadStatus;
    #endif
    #if(COM_RX_IPDU_HISTORY_LIST > 1)
    while(LusReadIndex != LusWriteIndex)
    #else
    if(LusWriteIndex == COM_ONE)
    #endif
    {
      
      #if((COM_RX_SIG_GATEWAY == STD_ON) || (COM_RX_SIGGROUP_GW == STD_ON) || \
       (COM_RX_IPDU_DEFERRED == STD_ON) || (COM_RX_IPDU_DM == STD_ON))
      #if(COM_RX_IPDU_HISTORY_LIST > 1)
      /* Getting RX PduId in local variable */
      LddComRxPduId = Com_GaaReceiveHistoryList[LusReadIndex];
      #endif
      #endif
      #if(COM_RX_IPDU_HISTORY_LIST > 1)
      ++LusReadIndex;
      /* Check if ReadIndex has exceeded configured no. of Rx buffer */
      if(LusReadIndex >= (uint16)COM_RX_IPDU_HISTORY_LIST)
      {
        /* setting local variable to zero */
        LusReadIndex = (uint16)COM_ZERO;
      }
      Com_GusRxReadStatus = LusReadIndex;
      #else
      #if((COM_RX_SIG_GATEWAY == STD_ON) || (COM_RX_SIGGROUP_GW == STD_ON) || \
       (COM_RX_IPDU_DEFERRED == STD_ON) || (COM_RX_IPDU_DM == STD_ON))
      LddComRxPduId = (PduIdType)COM_ZERO;
      #endif
      Com_GusRxWriteIndex = (uint16)COM_ZERO;
      #endif
      #if((COM_RX_SIG_GATEWAY == STD_ON) || (COM_RX_SIGGROUP_GW == STD_ON) || \
       (COM_RX_IPDU_DEFERRED == STD_ON) || (COM_RX_IPDU_DM == STD_ON))
      /* Get the pointer to first Rx L-PDU in the receive history list */
      LpRxIpdu = &Com_GaaRxIpdu[LddComRxPduId];
      /* Get the configuration data for Rx Ipdu */
      LucRxConfig = LpRxIpdu->ucRxConfig;
      #endif
      #if(COM_RX_IPDU_DEFERRED == STD_ON)
      /* Check whether Rx I-PDU status is Deferred */
      if((LucRxConfig & COM_RX_IPDU_DEFERRED_CONFIG_MASK) != COM_FALSE)
      {
        #if(COM_RX_SIGNAL == STD_ON)
        /* Check whether  Rx signals are configured */
        if((LucRxConfig & COM_RX_IPDU_SIGNAL_CONFIG_MASK) != COM_FALSE)
        {
          /* Invoke Com_RxSigProcessing() function to process all the
          signals configured in an I-PDU */
          Com_RxSigProcessing(LddComRxPduId, LpRxIpdu,
            *(PduLengthType *)Com_GaaRxPduInfoPtr[LddComRxPduId].SduLength);
        }
        #endif /* #if(COM_RX_SIGNAL == STD_ON) */
        #if(COM_RX_SIGGROUP == STD_ON)
        /* Check whether  Rx signal groups are configured */
        if((LucRxConfig & COM_RX_IPDU_SIGGRP_CONFIG_MASK) != COM_FALSE)
        {
          /* Invoke Com_RxSigGrpProcessing() function to process all
           the signal groups configured in an I-PDU */
          Com_RxSigGrpProcessing(LddComRxPduId, LpRxIpdu,
               *(PduLengthType *)Com_GaaRxPduInfoPtr[LddComRxPduId].SduLength);
        }
        #endif /* #if(COM_RX_SIGGROUP == STD_ON) */
        
        #if(COM_RX_SIG_GATEWAY == STD_ON)
        /* Check whether signal based gateway is configured */
        if((LucRxConfig & COM_RX_IPDU_GATEWAY_CONFIG_MASK) != COM_FALSE)
        {
          SchM_Enter_Com_RX_GW_STS_PROTECTION_AREA();
          /* Set the gateway I-PDU status */
          Com_GaaRxGWIpduStatus[LpRxIpdu->ucRxGWStsIndex]
                                                       |= LpRxIpdu->ucRxGWStsMask;
          SchM_Exit_Com_RX_GW_STS_PROTECTION_AREA();
        }
        #endif        
      } /* Check whether Rx I-PDU is configured as deferred or not */
      #endif /* #if(COM_RX_IPDU_DEFERRED == STD_ON) */


      #if(COM_RX_IPDU_DM == STD_ON)
      /* Check whether deadline monitoring is configured for Rx I-PDU */
      if((LucRxConfig & COM_RX_IPDU_DM_CONFIG_MASK) != COM_FALSE)
      {
        #if(COM_RX_INTERRUPT_BASED_PROCESS == STD_OFF)
        SchM_Enter_Com_RX_DM_STS_PROTECTION_AREA();
        #endif
        Com_GaaRxDMTimer[LpRxIpdu->ddRxIpduDmIndex] = COM_INVALID_DM_TIMER;
        #if(COM_RX_INTERRUPT_BASED_PROCESS == STD_OFF)
        SchM_Exit_Com_RX_DM_STS_PROTECTION_AREA();
        #endif
      }
      #endif
    } /* Check for all received PDUs */
    #if((COM_RX_IPDU_DM == STD_ON) || \
         (COM_RX_SIGNAL_UBDM == STD_ON) || \
         (COM_RX_SIGGROUP_UBDM == STD_ON))
    /*
      Check whether Rx deadline monitoring is configured for Rx I-PDU
      groups
    */
    Com_RxUpdateDmTimers();
    #endif
  } /* Check whether module is initialized */
  #endif  
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Com_RxUpdateDmTimers                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This is Com internal function. This function updates**
**                        deadline monitoring timers of Rx I-PDUs and signals **
**                        with an update bit.                                 **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : void                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaRxDm                **
**                                                 Com_GaaRxDmStatus          **
**                                                 Com_GaaRxDMTimer           **
**                        Function(s) invoked    : Com_RxSigNotifyOrReplace() **
**                                                 SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
*******************************************************************************/
#if((COM_RX_IPDU_DM == STD_ON) || \
   (COM_RX_SIGNAL_UBDM == STD_ON) || \
   (COM_RX_SIGGROUP_UBDM == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_RxUpdateDmTimers(void)
{
  /* Pointer to Rx deadline monitoring structure */
  P2CONST(Com_RxDm, AUTOMATIC, COM_CONST) LpRxDm;
  #if(COM_RX_SIG_GATEWAY == STD_ON)
  /* Pointer to Rx Ipdu structure */
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu;
  /* Pointer to Rx I-PDU configured for gateway structure */
  P2CONST(Com_RxGWIpdu, AUTOMATIC, COM_CONST)LpRxGWIpdu;
  #endif    
  /* Local variable to store timer value */
  uint16 LusTimer;
  /* Local variable to store number of Rx deadline monitoring counts */
  uint8 LucNoOfRxDm;
  /* Local variable to store deadline monitoring timer value */
  uint8 LddDmCount;
  /* Local variable to store status count */
  uint8 LucCount;
  uint8 LucRxDmIndex;
  LddDmCount = COM_ZERO;
  /* Get the number of Rx deadline monitoring counts */
  LucNoOfRxDm = COM_RX_IPDU_DM_COUNT;
  /* Get the pointer to Rx deadline monitoring structure */
  LucRxDmIndex = COM_ZERO;
  LpRxDm = &Com_GaaRxDm[LucRxDmIndex];
  /* Loop for number of Rx deadline monitoring counts */
  do
  {
    if((Com_GaaRxIpduStatus[LpRxDm->ddRxpduId] != (PduIdType)COM_ZERO) 
      && (Com_GaaRxDmStatus[LddDmCount] != (PduIdType)COM_ZERO))
    {
      LucCount = LpRxDm->ucRxDmCount;
      do
      {
        /* Get the deadline monitoring timer value to local variable */
        LusTimer = Com_GaaRxDMTimer[LddDmCount];
        if(COM_INVALID_DM_TIMER == LusTimer)
        {
          #if(COM_RX_INTERRUPT_BASED_PROCESS == STD_OFF)
          SchM_Enter_Com_RX_DM_STS_PROTECTION_AREA();
          #endif
          /* Load the local value of deadline monitoring timer to Rx deadline
            monitoring timer  */
          Com_GaaRxDMTimer[LddDmCount] = (LpRxDm->usRxDmTimeout);
          /* Decrement the count of the number of signals configured for Rx
                                                        deadline monitoring */
          #if(COM_RX_INTERRUPT_BASED_PROCESS == STD_OFF)
          SchM_Exit_Com_RX_DM_STS_PROTECTION_AREA();
          #endif
        }
        else if((uint16)COM_ZERO != LusTimer)
        {
          /* Decrement the deadline monitoring timer */
          LusTimer--;
          /* Check whether Rx deadline monitoring timer is equal to zero */
          if((uint16)COM_ZERO == LusTimer)
          {
            /* Copy the Rx deadline monitoring timeout value to local variable*/
            LusTimer = (LpRxDm->usRxDmTimeout);
            Com_RxSigNotifyOrReplace(LpRxDm);
            #if(COM_RX_SIGNAL_FILTER == STD_ON)			
            /* Reset the previous value in MASKED_NEW_DIFFERS_MASKED_OLD filter
            , when Rx Timeout is occurred - Fixed by AUTRON START*/
            Com_RxSigDMFilterReset(LpRxDm);
            /* Reset the previous value in MASKED_NEW_DIFFERS_MASKED_OLD filter
            , when Rx Timeout is occurred - Fixed by AUTRON END*/			
            #endif
            #if(COM_RX_SIG_GATEWAY == STD_ON)
            LpRxIpdu = &Com_GaaRxIpdu[LpRxDm->ddRxpduId];
            if((LpRxIpdu->ucRxConfig & COM_RX_IPDU_GATEWAY_CONFIG_MASK) != 
                                                                    COM_FALSE)
            {
              LpRxGWIpdu = &Com_GaaRxGWIpdu[LpRxIpdu->ddRxGWIpduIndex];
              
              #if((COM_RX_SIGNAL_GW == STD_ON) || (COM_RX_SIGINGROUP_GW == STD_ON))
              /* Check whether the Rx signals are configured for the gateway */
              if(LpRxGWIpdu->ucNoOfRxGWSignal != COM_ZERO)
              {
                /* Invoke Com_RxGWSigProcessing() function to process all Rx
                signals configured for gateway */
                Com_RxGWSigProcessing(LpRxGWIpdu, COM_SIG_GW_STATUS_TOUT);
              }
              #endif
              #if(COM_RX_SIGGROUP_GW == STD_ON)
              /* Check whether Rx signal groups are configured for gateway */
              if(LpRxGWIpdu->ucNoOfRxGWSigGroup != COM_ZERO)
              {
                /* Invoke Com_RxGWSigGrpProcessing() function to process all Rx
                signal groups configured for gateway */
                Com_RxGWSigGrpProcessing(LpRxGWIpdu, COM_SIG_GW_STATUS_TOUT);
              }
              #endif
            }
            #endif
            
          } /* Check whether Rx deadline monitoring timer is equal to zero */
          #if(COM_RX_INTERRUPT_BASED_PROCESS == STD_OFF)
          SchM_Enter_Com_RX_DM_STS_PROTECTION_AREA();
          #endif
          /* Load the local value of deadline monitoring timer to Rx deadline
            monitoring timer  */
          Com_GaaRxDMTimer[LddDmCount] = LusTimer;
          /* Decrement the count of the number of signals configured for Rx
                                                        deadline monitoring */
          #if(COM_RX_INTERRUPT_BASED_PROCESS == STD_OFF)
          SchM_Exit_Com_RX_DM_STS_PROTECTION_AREA();
          #endif
        } 
        else
        {
          /* Dummy loop to avoid QAC warning */
        }
        LucNoOfRxDm--;
        /* Get the pointer to n Rx deadline monitoring structure */
        LucRxDmIndex++;
        LpRxDm = &Com_GaaRxDm[LucRxDmIndex];
        LddDmCount++;
        --LucCount;
      }while (LucCount != COM_ZERO);
    }
    else
    {
      LucNoOfRxDm -= LpRxDm->ucRxDmCount;
      LddDmCount += LpRxDm->ucRxDmCount;
      /* Get the pointer to n Rx deadline monitoring structure */
      LucRxDmIndex += LpRxDm->ucRxDmCount;
      LpRxDm = &Com_GaaRxDm[LucRxDmIndex];   
    }
  }while(LucNoOfRxDm != COM_ZERO);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_MainFunctionTx                                  **
**                                                                            **
** Service ID           : 0x19                                                **
**                                                                            **
** Description          : This function perform the processing of the Com     **
**                        transmission activities that are not directly       **
**                        initiated by the calls from the RTE and PDU Router. **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Cyclic                                              **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :   Com_GaaTxIpduStatus      **
**                                                   Com_GaaTxIpdu            **
**                                                   Com_GaaTxIpduStatusBit   **
**                                                   Com_GaaTxIpduDm          **
**                                                   Com_GaaTxDMTimer         **
**                                                   Com_GaaTxMode            **
**                                                   Com_GaaTxPeriodicTimer   **
**                                                   Com_GaaTxReptTimer       **
**                                                   Com_GaaTxReptCount       **
**                        Function(s) invoked    :   Det_ReportError()        **
**                                                   SchM_Enter_Com()         **
**                                                   SchM_Exit_Com()          **
**                                                   SchM_Exit_Com()          **
**                                                   Com_Transmit()           **
**                                                   Com_TxUpdateDmTimers()   **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_MainFunctionTx(void)
{
  /* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Code structure for optimal performance */
  #if(COM_TX_IPDU == STD_ON)
  
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu;

  #if(((COM_MAINFUNC_BASED_TRANSMIT == STD_ON) && (COM_TX_IPDU_DM == STD_ON)) || \
  ((COM_MAINFUNC_BASED_TRANSMIT == STD_OFF) && (COM_TX_IPDU_DM == STD_ON)) || \
  ((COM_TX_IPDU_TMS == STD_ON) || \
  (COM_TX_RETRY_REQUEST == STD_ON) || \
  (COM_TX_IPDU_REPETITION == STD_ON) || \
  (COM_MAINFUNC_BASED_TRANSMIT == STD_ON) || \
  (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) || \
  (COM_TX_IPDU_PT == STD_ON)))
  P2CONST(Com_TxMode, AUTOMATIC, COM_CONST) LpTxMode;
  #endif

  #if((COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) || \
    (COM_TX_IPDU_PT == STD_ON) || (COM_TX_IPDU_REPETITION == STD_ON))
  uint16 LusTimer;
  #endif

  #if(COM_TX_IPDU_REPETITION == STD_ON)
  uint8 LucReptSubCount;
  #endif

  #if((COM_TX_IPDU_DM == STD_ON) \
    || ((COM_ENABLE_MDT_CYCLIC == STD_ON) && (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON)))
  uint8 LucTxConfig;
  #endif  

  #if((COM_TX_IPDU_TMS == STD_ON) || \
  (COM_TX_RETRY_REQUEST == STD_ON) || \
  (COM_TX_IPDU_REPETITION == STD_ON) || \
  (COM_MAINFUNC_BASED_TRANSMIT == STD_ON) || \
  (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) || \
  (COM_TX_IPDU_PT == STD_ON))
  /* Local variable to store mode */
  uint8 LucTxMode;  
  #endif
  

  /* Local variable to store no. of Tx Pdu */
  PduIdType LddNoOfTxIpdu;

  #if((COM_TX_IPDU_DEFERRED == STD_ON) || \
  (COM_TX_IPDU_DM == STD_ON) || \
  (COM_TX_IPDU_TMS == STD_ON) || \
  (COM_TX_RETRY_REQUEST == STD_ON) || \
  (COM_MAINFUNC_BASED_TRANSMIT == STD_ON) || \
  (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) || \
  (COM_TX_IPDU_REPETITION == STD_ON))
  uint16 LusTxIpduStatusBit;
  #endif

  
  /* Check whether module is initialized */
  #if(COM_DEV_ERROR_DETECT == STD_ON)
   /* Local variable to store return value */
  uint8 LucReturnValue;
  #endif
  /* Initializing variable to None mode */
  #if((COM_TX_IPDU_TMS == STD_ON) || \
  (COM_TX_RETRY_REQUEST == STD_ON) || \
  (COM_TX_IPDU_REPETITION == STD_ON) || \
  (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) || \
  (COM_MAINFUNC_BASED_TRANSMIT == STD_ON) || \
  (COM_TX_IPDU_PT == STD_ON))
  boolean LblTransmitFlag;
  #endif
  /* Check whether module is initialized */
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Initialize error flag to false */
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_MAINFUNCTIONTX);

  if(LucReturnValue == (uint8)E_OK)
  #endif
  {
    /* Get the number of Tx I-PDU groups */
    LddNoOfTxIpdu = (PduIdType)COM_TX_IPDU_COUNT;
    /* Loop for number of Tx I-PDU groups */
    do
    {
      #if((COM_TX_IPDU_TMS == STD_ON) || \
      (COM_TX_RETRY_REQUEST == STD_ON) || \
      (COM_TX_IPDU_REPETITION == STD_ON) || \
      (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) || \
      (COM_MAINFUNC_BASED_TRANSMIT == STD_ON) || \
      (COM_TX_IPDU_PT == STD_ON))    
      LblTransmitFlag = COM_FALSE;  
      #endif      
      
      LddNoOfTxIpdu--;
      /* Check whether I-PDU group is started */
      if(Com_GaaTxIpduStatus[LddNoOfTxIpdu] != (PduIdType)COM_ZERO)
      {
        SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
        #if((COM_TX_IPDU_DEFERRED == STD_ON) || \
            (COM_TX_IPDU_DM == STD_ON) || \
            (COM_TX_IPDU_TMS == STD_ON) || \
            (COM_TX_RETRY_REQUEST == STD_ON) || \
            (COM_MAINFUNC_BASED_TRANSMIT == STD_ON) || \
            (COM_TX_IPDU_REPETITION == STD_ON))
        LusTxIpduStatusBit = Com_GaaTxIpduStatusBit[LddNoOfTxIpdu];
        #endif
        Com_GaaTxIpduStatusBit[LddNoOfTxIpdu] &= ((uint16)
                                           ~(COM_TX_CONFIRM_STATUS_MASK | 
                                            COM_TX_PT_STATUS_MASK | 
                                            COM_TX_RETRY_STATUS_MASK | 
                                            COM_TX_DM_STATUS_MASK |
                                            COM_TX_MAINFUNC_SEND_STATUS_MASK |
                                            COM_TX_REPT_CONFIRM_HANDLE_MASK |
                                            COM_TX_REPT_STATUS_MASK));
        SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
      
        /* Get the pointer to Tx Ipdu */
        LpTxIpdu = &Com_GaaTxIpdu[LddNoOfTxIpdu];
        #if(COM_MAINFUNC_BASED_TRANSMIT == STD_ON)
        #if((COM_TX_IPDU_DEFERRED == STD_ON) || (COM_TX_IPDU_DM == STD_ON))
        /* Check whether Tx Ipdu is transmitted successfully */
        if((LusTxIpduStatusBit & COM_TX_CONFIRM_STATUS_MASK) != COM_FALSE)
        {
          #if(COM_TX_IPDU_DM == STD_ON)
          /* Check whether Pdu is configured for deadline monitoring */
          if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_DM_CONFIG_MASK) != COM_FALSE)
          {
            /* Reset deadline monitoring timer to zero */
            Com_GaaTxDMTimer[LpTxIpdu->ddTxIpduDmIndex] = (uint16)COM_ZERO;
          }
          #endif    
          /* Check whether TMS is configured */
          #if(COM_TX_IPDU_DM == STD_ON)
          LpTxMode = &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex];
          if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_DM_CONFIG_MASK) != COM_FALSE)
          {
            #if(COM_TX_IPDU_TMS == STD_ON)
            if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_TMS_CONFIG_MASK) 
              == COM_FALSE)
            #endif
            {
              if(LpTxMode->ucTxMode == COM_TX_NONE_MODE)
              {
                Com_GaaTxDMTimer[LpTxIpdu->ddTxIpduDmIndex] =
                Com_GaaTxIpduDm[LpTxIpdu->ddTxIpduDmIndex].usDmTimeout + (uint16)COM_ONE;
                
                SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
                Com_GaaTxIpduStatusBit[LddNoOfTxIpdu] |= COM_TX_REQ_STATUS_MASK;
                SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();        
              }
            }
          }
          #endif
          #if((COM_TX_IPDU_DEFERRED == STD_ON) && \
            (COM_TX_SIGNAL_NOTIFY  == STD_ON))
          /* Check whether Tx Ipdu is configured for deferred or immediate */
          if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_DEF_NOTIFY_CONFIG_MASK)
                                          == COM_TX_IPDU_DEF_NOTIFY_CONFIG_MASK)
          {
            Com_TxSigConfirmation(LpTxIpdu);
          }
          #endif
        }
        #endif
        #if(COM_TX_IPDU_DM == STD_ON)
        /* Check whether Deadline monitoring Status reset bit is set to true */
        if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_DM_CONFIG_MASK) != COM_FALSE)
        {
          if((LusTxIpduStatusBit & COM_TX_DM_STATUS_MASK) != COM_FALSE)
          {
            /* Reset the deadline monitoring */
            Com_GaaTxDMTimer[LpTxIpdu->ddTxIpduDmIndex] =
            Com_GaaTxIpduDm[LpTxIpdu->ddTxIpduDmIndex].usDmTimeout + (uint16)COM_ONE;
            SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
            Com_GaaTxIpduStatusBit[LddNoOfTxIpdu] &= COM_TX_DM_STATUS_MASK_NEG;
            SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
          }
        }
        #endif
        #else
        #if(COM_TX_IPDU_DM == STD_ON)
        /* Check whether Deadline monitoring Status reset bit is set to true */
        if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_DM_CONFIG_MASK) != COM_FALSE)
        {
          if((LusTxIpduStatusBit & COM_TX_DM_STATUS_MASK) != COM_FALSE)
          {
            /* Reset the deadline monitoring */
            Com_GaaTxDMTimer[LpTxIpdu->ddTxIpduDmIndex] =
            Com_GaaTxIpduDm[LpTxIpdu->ddTxIpduDmIndex].usDmTimeout + (uint16)COM_ONE;
            SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
            Com_GaaTxIpduStatusBit[LddNoOfTxIpdu] &= COM_TX_DM_STATUS_MASK_NEG;
            SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
          }
        }
        #endif
        #if((COM_TX_IPDU_DEFERRED == STD_ON) || (COM_TX_IPDU_DM == STD_ON))
        /* Check whether Tx Ipdu is transmitted successfully */
        if((LusTxIpduStatusBit & COM_TX_CONFIRM_STATUS_MASK) != COM_FALSE)
        {
          #if(COM_TX_IPDU_DM == STD_ON)
          /* Check whether Pdu is configured for deadline monitoring */
          if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_DM_CONFIG_MASK) != COM_FALSE)
          {
            /* Reset deadline monitoring timer to zero */
            Com_GaaTxDMTimer[LpTxIpdu->ddTxIpduDmIndex] = (uint16)COM_ZERO;
          }
          #endif    
          /* Check whether TMS is configured */
          #if(COM_TX_IPDU_DM == STD_ON)
          LpTxMode = &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex];
          if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_DM_CONFIG_MASK) != COM_FALSE)
          {
            #if(COM_TX_IPDU_TMS == STD_ON)
            if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_TMS_CONFIG_MASK) 
              == COM_FALSE)
            #endif
            {
              if(LpTxMode->ucTxMode == COM_TX_NONE_MODE)
              {
                Com_GaaTxDMTimer[LpTxIpdu->ddTxIpduDmIndex] =
                Com_GaaTxIpduDm[LpTxIpdu->ddTxIpduDmIndex].usDmTimeout + (uint16)COM_ONE;
                SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
                Com_GaaTxIpduStatusBit[LddNoOfTxIpdu] |= COM_TX_REQ_STATUS_MASK;
                SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
              }
            }
          }
          #endif
          #if((COM_TX_IPDU_DEFERRED == STD_ON) \
            && (COM_TX_SIGNAL_NOTIFY  == STD_ON))
          /* Check whether Tx Ipdu is configured for deferred or immediate */
          if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_DEF_NOTIFY_CONFIG_MASK)
                                          == COM_TX_IPDU_DEF_NOTIFY_CONFIG_MASK)
          {
            Com_TxSigConfirmation(LpTxIpdu);
          }
          #endif
        }
        #endif
        #endif


        #if((COM_TX_IPDU_TMS == STD_ON) || \
          (COM_TX_RETRY_REQUEST == STD_ON) || \
          (COM_TX_IPDU_REPETITION == STD_ON) || \
          (COM_MAINFUNC_BASED_TRANSMIT == STD_ON) || \
          (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) || \
          (COM_TX_IPDU_PT == STD_ON))

        /* Get the pointer to Tx Mode */
        LpTxMode = &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex];
        #if((COM_TX_IPDU_DM == STD_ON) \
          || ((COM_ENABLE_MDT_CYCLIC == STD_ON) && (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON)))
        LucTxConfig = LpTxIpdu->ucTxConfig;
        #endif
        
        #if(COM_TX_IPDU_TMS == STD_ON)
        /* Check if the transmission mode is configured as true/false */
        if((LusTxIpduStatusBit & COM_TX_TMS_STATUS_MASK) == COM_FALSE)
        {
          LpTxMode = 
              &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex
              +(PduIdType)COM_ONE];
        }
        #if(COM_TX_IPDU_PT == STD_ON)
        if((LusTxIpduStatusBit & COM_TX_PT_STATUS_MASK) != COM_FALSE)
        {
          /* #3434 cyclic PDU handling in case of TMS switch */
          if(((LpTxMode->ucTxMode) <= COM_TX_MIXEDNTIMES_MODE)  &&
                               ((LpTxMode->ucTxMode) != COM_TX_NONE_MODE))
          {
            Com_GaaTxPeriodicTimer[LpTxIpdu->ddTxPeriodicTimerIndex] =
                                                          (uint16)(COM_ONE);
          }
        }  
        #endif
        #endif
        LucTxMode = LpTxMode->ucTxMode;
        /* Check whether current Tx mode is none */
        if(LucTxMode != COM_TX_NONE_MODE)
        {
          #if(COM_TX_IPDU_PT == STD_ON)
          /* Check whether current Tx mode is periodic or mixed */
          if(LucTxMode <= COM_TX_MIXEDNTIMES_MODE)
          {
            /* Get the Tx periodic timer value to local variable */
            LusTimer = Com_GaaTxPeriodicTimer[LpTxIpdu->ddTxPeriodicTimerIndex];
            /* Decrement the Tx periodic timer value in the local
            variable */
            LusTimer--;
            /* Check whether Tx periodic timer value is equal to zero */
            if(LusTimer == (uint16)COM_ZERO)
            {
              LusTimer = LpTxMode->usPeriodicValue;
              LblTransmitFlag = COM_TRUE;
      		
              /* #3447 handling overlap condition of MIXED type PDU */
              if(LucTxMode == COM_TX_MIXEDNTIMES_MODE)
              {
                #if(COM_TX_REPT_COUNT > COM_MACRO_ZERO)
                if((Com_GaaTxReptCount[LpTxIpdu->ddTxReptIndex] != COM_ZERO) 
                || (Com_GaaTxReptSubCount[LpTxIpdu->ddTxReptIndex] != COM_ZERO))
                {
                  LblTransmitFlag = COM_FALSE;
                }
                #endif
              }
              
              /* #2022 MDTForCyclicTransmission related compile error 
              & incorrect operation is fixed(ref 4.2.1 Com Spec) */
              #if(COM_ENABLE_MDT_CYCLIC == STD_OFF)
              SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
              Com_GaaTxIpduStatusBit[LddNoOfTxIpdu] 
                |= COM_TX_REPT_CONFIRM_HANDLE_MASK;
              SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
              #endif        
            }
            /* Load the periodic timer value in the local variable to the
               Tx periodic timer */
            Com_GaaTxPeriodicTimer[LpTxIpdu->ddTxPeriodicTimerIndex] = LusTimer;
          } /* Check whether current Tx mode is periodic or mixed */
          #endif
          
          #if(COM_TX_IPDU_REPETITION == STD_ON)
          /* Check whether current Tx Mode is n-times (direct/mixed) */
          if ((LucTxMode == COM_TX_DIRECTNTIMES_MODE) ||
              (LucTxMode == COM_TX_MIXEDNTIMES_MODE))
          {
            /* Reset the counter and timer if send request is called from
               application */
            if((LusTxIpduStatusBit & COM_TX_REPT_STATUS_MASK) != COM_ZERO)
            {
              Com_GaaTxReptTimer[LpTxIpdu->ddTxReptIndex] =
                                                     LpTxMode->usReptTimerValue;
              #if(COM_MAINFUNC_BASED_TRANSMIT == STD_OFF)
              if((LusTxIpduStatusBit & COM_TX_MAINFUNC_SEND_STATUS_MASK) 
                != COM_FALSE)
              {
                Com_GaaTxReptTimer[LpTxIpdu->ddTxReptIndex] 
                  = Com_GaaTxReptTimer[LpTxIpdu->ddTxReptIndex] - (uint16)COM_ONE;
              }
              #else
              Com_GaaTxReptCount[LpTxIpdu->ddTxReptIndex] 
                  = LpTxMode->ucReptCount;
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
            else
            {
              /* Check whether repetition count is not equal to zero */
              if((Com_GaaTxReptCount[LpTxIpdu->ddTxReptIndex] != COM_ZERO) 
              || (Com_GaaTxReptSubCount[LpTxIpdu->ddTxReptIndex] != COM_ZERO))
              {
                /* Get the repetition timer value to a local variable */
                LusTimer = (Com_GaaTxReptTimer[LpTxIpdu->ddTxReptIndex]);
                /* Decrement the repetition timer value in local variable */
                LusTimer--;
                /* Check whether repetition timer in local variable is equal
                to zero */
                if(LusTimer == (uint16)COM_ZERO)
                {
                  /* Load the configured repetition timer value to local
                  variable */
                  LusTimer = (LpTxMode->usReptTimerValue);
                  /* Set Transmit flag to true */
                  LblTransmitFlag = COM_TRUE;
                  LucReptSubCount = Com_GaaTxReptSubCount[LpTxIpdu->ddTxReptIndex];
                   if(LucReptSubCount != COM_ZERO)
                  {
                    /* Decrement the repetition count */
                    LucReptSubCount--;
                    /* Set the repetition count */
                    Com_GaaTxReptSubCount[LpTxIpdu->ddTxReptIndex] = LucReptSubCount;
                  }
                  #if(COM_ENABLE_MDT_CYCLIC == STD_OFF)
                  SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
                  Com_GaaTxIpduStatusBit[LddNoOfTxIpdu] 
                    |= COM_TX_REPT_CONFIRM_HANDLE_MASK;
                  SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
                  #endif                  
                } /* Check whether repetition timer in local variable is
                     equal to zero */
                /* Load the repetition timer value from local variable to
                 the repetition timer */
                Com_GaaTxReptTimer[LpTxIpdu->ddTxReptIndex] = LusTimer;
              }
            } /* Check whether repetition count is not equal to zero */
          }
          #endif

          #if((COM_TX_IPDU_TMS == STD_ON) || \
          (COM_TX_RETRY_REQUEST == STD_ON) || \
          (COM_TX_IPDU_REPETITION == STD_ON) || \
          (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) || \
          (COM_MAINFUNC_BASED_TRANSMIT == STD_ON) || \
          (COM_TX_IPDU_PT == STD_ON))
          /* Check whether Transmit flag is true */
          if(COM_TRUE == LblTransmitFlag)
          #endif
          {
            #if(COM_TX_IPDU_DM == STD_ON)
            /* Check whether Tx deadline monitoring is configured */
            if((LucTxConfig & COM_TX_IPDU_DM_CONFIG_MASK) != COM_FALSE)
            {
              if(LucTxMode <= COM_TX_MIXEDNTIMES_MODE)
              {
                /* Check whether deadline monitoring timer is zero */
                if((Com_GaaTxDMTimer[LpTxIpdu->ddTxIpduDmIndex]) == (uint16)COM_ZERO)
                {
                  /* Load the deadline monitoring timer with the deadline
                  monitoring timeout value */
                  Com_GaaTxDMTimer[LpTxIpdu->ddTxIpduDmIndex] =
                  Com_GaaTxIpduDm[LpTxIpdu->ddTxIpduDmIndex].usDmTimeout 
                  + (uint16)COM_ONE;
                }
              }
            } /* Check whether Tx deadline monitoring is configured */
            #endif /* #if(COM_TX_IPDU_DM == STD_ON) */

            /* #2022 MDTForCyclicTransmission related compile error 
            & incorrect operation is fixed(ref 4.2.1 Com Spec) */
            #if(COM_ENABLE_MDT_CYCLIC == STD_ON)
            #if(COM_TX_IPDU_MINDELAY_ENABLED == STD_ON)
            /* Check whether minimum delay timer is configured */
            if((LucTxConfig & COM_TX_IPDU_MDT_CONFIG_MASK) != COM_FALSE)
            {
              LblTransmitFlag = COM_FALSE;
              /* Check whether minimum delay timer is reset to zero */
              if(Com_GaaTxMDTimer[LpTxIpdu->ddTxMDTimerIndex] == (uint16)COM_ZERO)
              {
                #if(COM_TX_IPDU_TMS == STD_ON)
                if((LucTxMode != COM_TX_PERIODIC_MODE) ||
                 (LusTxIpduStatusBit & COM_TX_PENDING_STATUS_MASK) == COM_FALSE)
                {
                  /* Invoke Com_Transmit to transmit an Ipdu to the lower
                   layer */
                  LblTransmitFlag = COM_TRUE;
                }
                #else
                /* Invoke Com_Transmit to transmit an Ipdu to the lower
                   layer */
                LblTransmitFlag = COM_TRUE;
                #endif /* #if(COM_TX_IPDU_TMS == STD_ON) */
              }
              else
              {
                SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
                Com_GaaTxIpduStatusBit[LddNoOfTxIpdu] 
                  |= COM_TX_PENDING_STATUS_MASK;
                SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
              }
            }
            #endif 
            #endif
          } /* Check whether Transmit flag is true */
        } /* Check whether current Tx mode is not none */
        
        #if(COM_TX_RETRY_REQUEST == STD_ON)
        /* Check whether Tx RETRY bit is set to one */
        if(((LusTxIpduStatusBit & COM_TX_RETRY_STATUS_MASK) != COM_FALSE) && 
            (LucTxMode != COM_TX_NONE_MODE))
        {
          /* If so transmit an I-PDU once again to lower layer */
          LblTransmitFlag = COM_TRUE;
        }
        #endif

        #if(COM_MAINFUNC_BASED_TRANSMIT == STD_ON)
        /* #1463 : Add mainfunction transmit option for trigger on change 
        transfer type */
        if(((LusTxIpduStatusBit & COM_TX_MAINFUNC_SEND_STATUS_MASK) 
          != COM_FALSE) && (LucTxMode != COM_TX_NONE_MODE))
        {
          /* If so transmit an I-PDU once again to lower layer */
          LblTransmitFlag = COM_TRUE;
        }
        #endif
        #endif
        
        #if(COM_TX_IPDU_MINDELAY_ENABLED == STD_ON)
        
        /* Check whether Ipdu is transmitted successfully */
        if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_MDT_CONFIG_MASK) != (COM_ZERO))
        {
          LusTimer = Com_GaaTxMDTimer[LpTxIpdu->ddTxMDTimerIndex];
          if(LusTimer != (uint16)COM_ZERO)
          {
            /* Decrement periodic timer */
            --LusTimer;
            /* Check whether minimum delay timer is equal to zero */
            if((uint16)COM_ZERO == LusTimer)
            {
              LusTxIpduStatusBit = Com_GaaTxIpduStatusBit[LddNoOfTxIpdu];
              #if(COM_TX_IPDU_TMS == STD_ON)||(COM_TX_IPDU_REPETITION == STD_ON)
              /* Get the pointer to Tx Mode */
              LpTxMode = &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex];
              #endif
              #if(COM_TX_IPDU_TMS == STD_ON)
              /* Check if the transmission mode is configured as true/false */
              if((LusTxIpduStatusBit & COM_TX_TMS_STATUS_MASK) == COM_FALSE)
              {
                LpTxMode = 
                &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex
                +(PduIdType)COM_ONE];          
              }
              #endif
              
              /* Check whether Tx pending flag is true */
              if(((LusTxIpduStatusBit & COM_TX_PENDING_STATUS_MASK) 
                != COM_FALSE))
              {
                LblTransmitFlag = COM_TRUE;
                SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
                Com_GaaTxIpduStatusBit[LddNoOfTxIpdu] &=
                                       (uint16)(~COM_TX_PENDING_STATUS_MASK);
                            
                /* #2022 MDTForCyclicTransmission related compile error 
                & incorrect operation is fixed(ref 4.2.1 Com Spec) */                     
                #if(COM_ENABLE_MDT_CYCLIC == STD_OFF)
                Com_GaaTxIpduStatusBit[LddNoOfTxIpdu] 
                &= (uint16)(~COM_TX_REPT_CONFIRM_HANDLE_MASK);
                #endif
                SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
                #if((COM_TX_IPDU_TMS == STD_ON) && (COM_TX_IPDU_PT == STD_ON))
                
                /* Check whether current Tx mode is periodic */
                if(LpTxMode->ucTxMode == COM_TX_PERIODIC_MODE)
                {
                  /* Load the Tx periodic timer with the configured periodic
                  value */
                  Com_GaaTxPeriodicTimer[LpTxIpdu->ddTxPeriodicTimerIndex] =
                                                    (LpTxMode->usPeriodicValue);
                }
                #endif /* #if(COM_TX_IPDU_TMS == STD_ON) */
        
                #if(COM_TX_IPDU_REPETITION == STD_ON)
                if((LpTxMode->ucTxMode == COM_TX_DIRECTNTIMES_MODE) ||
                (LpTxMode->ucTxMode == COM_TX_MIXEDNTIMES_MODE))
                {
                  /* Check whether repetition counter is not equal to zero */
                  if((Com_GaaTxReptCount[LpTxIpdu->ddTxReptIndex] != COM_ZERO) 
                  || (Com_GaaTxReptSubCount[LpTxIpdu->ddTxReptIndex] != COM_ZERO))
                  {
                    /* Load the Tx repetition timer value from the configured
                    repetition value */
                    Com_GaaTxReptTimer[LpTxIpdu->ddTxReptIndex] =
                                                    LpTxMode->usReptTimerValue;
                  }
                }
                #endif /*(COM_TX_IPDU_REPETITION == STD_ON)*/
              } /* Check Tx pending flag is set to true */
            } /* Check whether minimum delay timer is equal to zero */
            SchM_Enter_Com_TX_MDT_PROTECTION_AREA();
            /* Reset minimum delay timer to zero */
            Com_GaaTxMDTimer[LpTxIpdu->ddTxMDTimerIndex] = LusTimer;
            SchM_Exit_Com_TX_MDT_PROTECTION_AREA();
          } /* Check whether minimum delay timer is configured */
        }
        #endif

        #if((COM_TX_IPDU_TMS == STD_ON) || \
          (COM_TX_RETRY_REQUEST == STD_ON) || \
          (COM_MAINFUNC_BASED_TRANSMIT == STD_ON) || \
          (COM_TX_IPDU_REPETITION == STD_ON) || \
          (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON)|| (COM_TX_IPDU_PT == STD_ON))
        /* Check whether Tx bit is set to one */
        if(COM_TRUE == LblTransmitFlag)
        #endif
        {        
          (void)Com_Transmit(LddNoOfTxIpdu);
        }        
      } /* Check whether Tx I-PDUs is active or not */
    }while (LddNoOfTxIpdu != (PduIdType)COM_ZERO);
    
    #if(COM_TX_IPDU_DM == STD_ON)
    Com_TxUpdateDmTimers();
    #endif
  } /* Check whether module is initialized */
  #endif
  /* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Code structure for optimal performance */  
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Com_Transmit                                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function initiate Tx request for an I-PDU to   **
**                        the lower layer. It also invokes I-PDU callout to   **
**                        the upper layer if configured.                      **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non-Reentrant for same Tx I-PDU.                    **
**                        Reentrant for different Tx I-PDUs.                  **
**                                                                            **
** Input Parameters     : LpTxIpdu                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :  Com_GaaTxPduInfoPtr       **
**                                                  Com_GaaTxIpduCounter      **
**                                                  Com_GaaTxTPIpdu           **
**                                                  Com_GaaTxDynSigLength     **
**                                                  Com_GaaTxMDTimer          **
**                                                  Com_GaaTxMDTimeout        **
**                                                  Com_GaaTxUpdateBit        **
**                                                  Com_GaaTxIpduStatusBit    **
**                                                  Com_GaaTxTPStatus         **
**                                                  Com_GaaCounterStatusFlag  **
**                        Function(s) invoked    :  SchM_Enter_xxx()          **
**                                                  SchM_Exit_xxx()           **
**                                                  PduR_ComTransmit()        **
**                                                  Com_TxCounterUpdate()     **
**                                                  Com_TxClearUpdateBit()    **
**                                                  Com_TransIpduCounter()    **
**                                                  pIpduCallout              **
*******************************************************************************/
#if(COM_TX_IPDU == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, COM_CODE) Com_Transmit
  (PduIdType LddTxIpduId)
{
  P2VAR(PduInfoType, AUTOMATIC, COM_VAR) LpPduInfoPtr;
  #if(COM_TX_TP_SUPPORT == STD_ON)
  /* Pointer to Tx Ipdu */
  P2CONST(Com_TxTPIpdu, AUTOMATIC, COM_CONST) LpTxTPIpdu;
  #endif
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu;
  /* Local variable to store return value */
  #if((COM_TX_IPDU_COUNTER_ENABLED == STD_ON))
  P2CONST(Com_TxIpduCounter, AUTOMATIC, COM_CONST) LpTxIpduCounter;
  #endif
  Std_ReturnType LddReturnValue;
  #if(COM_TX_IPDU_CALLOUT == STD_ON)
  boolean LblCalloutValue;
  #endif
  LpTxIpdu = &Com_GaaTxIpdu[LddTxIpduId];
  /* Get the pointer to PduInfoPtr structure */
  LpPduInfoPtr = &Com_GaaTxPduInfoPtr[LddTxIpduId];  

  #if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON) 
  /* Check whether Tx I-PDU counter is configured */
  if(LpTxIpdu->ddTxIpduCounter != COM_INVALID_TXID_PARAM)
  {
    /* Get the pointer to Tx I-PDU counter structure */
    LpTxIpduCounter = &Com_GaaTxIpduCounter[LpTxIpdu->ddTxIpduCounter];
    Com_TxCounterUpdate(LpTxIpduCounter);
  } /* if(LpTxIpdu->pTxIpduCounter != NULL_PTR) */
  #endif

  #if((COM_TX_IPDU_CALLOUT == STD_ON))
  /* Initialize return value to E_OK */
  LddReturnValue = (uint8)E_OK;
  /* Initialize IPDU_CALLOUT return value to COM_TRUE */
  LblCalloutValue = COM_TRUE;
  /* Check whether I-PDU callout is configured */
  if(LpTxIpdu->ddIpduCalloutIndex != COM_INVALID_TXID_PARAM)
  {
    /* Exit Critical Area */
    SchM_Enter_Com_TX_IPDU_BUFFER_PROTECTION_AREA();
    LblCalloutValue = Com_TxIpduCallout(LddTxIpduId, 
      (PduInfoType *)LpPduInfoPtr);
    /* Exit Critical Area */
    SchM_Exit_Com_TX_IPDU_BUFFER_PROTECTION_AREA();
  }
  /* Check whether I-PDU callout return value is E_OK */
  if(COM_TRUE == LblCalloutValue)
  #endif
  {
    SchM_Enter_Com_TX_IPDU_DATA_PROTECTION();
    #if(COM_TX_DYN_SUPPORT == STD_ON)
    if((LpTxIpdu->ucIpduType == COM_DYN_IPDU) 
      && (LpTxIpdu->ddTxIpduDynLegthRef != COM_INVALID_TXID_PARAM))
    {
      LpPduInfoPtr->SduLength = 
                              (PduLengthType)((LpTxIpdu->ddTxNonDynLength) +
        Com_GaaTxDynSigLength[LpTxIpdu->ddTxIpduDynLegthRef]);
    }
    #endif
    LddReturnValue = PduR_ComTransmit(LpTxIpdu->ddTxIpduId, LpPduInfoPtr);
    /* Check whether lower layer's return value is E_OK and
       update bit needs to be cleared */
    if((uint8)E_OK == LddReturnValue)
    {
      Com_GaaTxIpduStatusBit[LddTxIpduId] &=
             (uint16)(~(COM_TX_RETRY_STATUS_MASK | COM_TX_CONFIRM_STATUS_MASK));
      Com_GaaTxIpduStatusBit[LddTxIpduId] |= (COM_TX_REQ_STATUS_MASK);
      
      #if(COM_TX_IPDU_MINDELAY_ENABLED == STD_ON)
      /* Check whether minimum delay timer is configured */
      if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_MDT_CONFIG_MASK) != COM_ZERO)
      {
        /* Check whether minimum delay timer is equal to zero */
        if(Com_GaaTxMDTimer[LpTxIpdu->ddTxMDTimerIndex] == (uint16)COM_ZERO)
        {
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
          if((Com_GaaTxIpduStatusBit[LddTxIpduId] 
            & COM_TX_REPT_CONFIRM_HANDLE_MASK) == COM_FALSE)
          {
            Com_GaaTxMDTimer[LpTxIpdu->ddTxMDTimerIndex] =
            Com_GaaTxMDTimeout[LpTxIpdu->ddTxMDTimerIndex];
          }
          #endif
        }
      }
      #endif
      #if(COM_TX_SIGNAL_UB == STD_ON)
      /* Check whether update bit needs to be cleared */
      if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_UB_CONFIG_MASK) != COM_ZERO)
      {
        #if(COM_TX_TP_SUPPORT == STD_ON)
        if(LpTxIpdu->ucTxTPRef == COM_INVALID_NONE)
        #endif
        {
          if(Com_GaaTxUpdateBit[LpTxIpdu->ddTxIpduUbIndex].ucUBConfig ==
                                            COM_TX_IPDU_UB_TRANSMIT_CONFIG_MASK)
          {
            Com_TxClearUpdateBit(LpTxIpdu, LpPduInfoPtr->SduDataPtr);
          }
        }
      }
      #endif/*#if(COM_TX_SIGNAL_UB == STD_ON)*/

      #if(COM_TX_TP_SUPPORT == STD_ON)
      /* If IPDU is TP or DYN, lock the buffer */
      if(LpTxIpdu->ucTxTPRef != COM_INVALID_NONE)
      {
        /* Get the pointer to TP structure  */
        LpTxTPIpdu = &Com_GaaTxTPIpdu[LpTxIpdu->ucTxTPRef];
        Com_GaaTxTPStatus[LpTxTPIpdu->ucTxTPStatusRef] |=
                                                (LpTxTPIpdu->ucTxTPStatusMask);
      }
      #endif
    } /* Check whether lower layer's return value is E_OK */
    else
    {
      #if(COM_TX_RETRY_REQUEST == STD_ON)
      /* Set Retry Bit */
      Com_GaaTxIpduStatusBit[LddTxIpduId] |= COM_TX_RETRY_STATUS_MASK;
      #endif
      
      #if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON)
      if(LpTxIpdu->ddTxIpduCounter != COM_INVALID_TXID_PARAM)
      {
        Com_GaaCounterStatusFlag[LpTxIpdu->ddTxIpduCounter] = 
                                                          COM_COUNTER_E_PENDING;
        Com_TransIpduCounter(LpTxIpdu);
      }
      #endif
    }
    SchM_Exit_Com_TX_IPDU_DATA_PROTECTION();
  }
  #if((COM_TX_IPDU_CALLOUT == STD_ON))
  else
  {
    #if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON)
    if(LpTxIpdu->ddTxIpduCounter != COM_INVALID_TXID_PARAM)
    {
      Com_GaaCounterStatusFlag[LpTxIpdu->ddTxIpduCounter] = 
                                                        COM_COUNTER_E_PENDING;
      Com_TransIpduCounter(LpTxIpdu);
    }
    #endif  
  }
  #endif
  return(LddReturnValue);
}

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_MainFunctionRouteSignals                        **
**                                                                            **
** Service ID           : 0x1A                                                **
**                                                                            **
** Description          : This function forwards the received signals, which  **
**                        are to be routed from received I-PDUs to transmit   **
**                        I-PDUs.                                             **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Cyclic                                              **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaRxGWIpdu            **
**                                                 Com_GaaRxGWIpduStatus      **
**                        Function(s) invoked    : Det_ReportError()          **
**                                                 Com_RxGWSigProcessing()    **
**                                                 Com_RxGWSigGrpProcessing() **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_MainFunctionRouteSignals(void)
{
  #if(COM_RX_SIG_GATEWAY == STD_ON)
  /* Pointer to Rx I-PDU configured for gateway structure */
  P2CONST(Com_RxGWIpdu, AUTOMATIC, COM_CONST)LpRxGWIpdu;
  P2VAR(uint8, AUTOMATIC, COM_VAR)LpIpduStatus;
  /* Local variable to store signal count */
  uint8 LucNoOfIpduStsCount;
  /* Local variable to store Ipdu status */
  uint8 LucIpduStatus;
  /* Local variable to store count */
  uint8 LucCount;
  PduIdType LddRxGWIpduIndex;
  PduIdType LddRxGWIpduStatusIndex;
  /* Check whether module is initialized */
  #if(COM_DEV_ERROR_DETECT == STD_ON)
   /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Initialize error flag to false */
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_MAINFUNCTIONROUTESIGNALS);
  if(LucReturnValue == (uint8)E_OK)
  #endif
  {
    /* Get the pointer to gateway I-PDU status */
    LddRxGWIpduStatusIndex = (PduIdType)COM_ZERO;
    /* Get the pointer to first gateway Rx I-PDU structure */
    LddRxGWIpduIndex = (PduIdType)COM_ZERO;
    
    /* Get the number of Rx I-PDUs configured for gateway */
    LucNoOfIpduStsCount = COM_RX_IPDU_GWSTATUS_COUNT;
    /* Initialize counter to zero */
    LucCount = COM_ZERO;
    /* Loop for the number of gateway Rx I-PDUs (I-PDUs configured for gateway)
    */
    do
    {
      /* Get the pointer to n I-PDU status */
      LpIpduStatus = &Com_GaaRxGWIpduStatus[LddRxGWIpduStatusIndex];
    
      /* Get the pointer to n gatewayed Rx I-PDU structure */
      LddRxGWIpduIndex = LddRxGWIpduIndex + (PduIdType)LucCount;
      /* Initialize counter to eight */
      LucCount = COM_EIGHT;
      /* Get the I-PDU status of gatewayed I-PDU to local variable */
      LucIpduStatus = *LpIpduStatus;
      /* Check whether I-PDU status is set */
      if(LucIpduStatus != COM_ZERO)
      {
        SchM_Enter_Com_RX_GW_STS_PROTECTION_AREA();
        /* Reset the I-PDU status */
        *LpIpduStatus = COM_ZERO;
        SchM_Exit_Com_RX_GW_STS_PROTECTION_AREA();
        /* Loop for all I-PDU status */
        do
        {        
          /* Check whether the status of gatewayed I-PDU is not false */
          if((LucIpduStatus & (COM_ONE)) != COM_FALSE)
          {
            LpRxGWIpdu = 
            (P2CONST(Com_RxGWIpdu, AUTOMATIC, COM_CONST))
            &Com_GaaRxGWIpdu[LddRxGWIpduIndex];
            
            #if((COM_RX_SIGNAL_GW == STD_ON) || (COM_RX_SIGINGROUP_GW == STD_ON))
            /* Check whether the Rx signals are configured for the gateway */
            if(LpRxGWIpdu->ucNoOfRxGWSignal != COM_ZERO)
            {
              /* Invoke Com_RxGWSigProcessing() function to process all Rx
              signals configured for gateway */
              Com_RxGWSigProcessing(LpRxGWIpdu, COM_SIG_GW_STATUS_NORMAL);
            }
            #endif
            #if(COM_RX_SIGGROUP_GW == STD_ON)
            /* Check whether Rx signal groups are configured for gateway */
            if(LpRxGWIpdu->ucNoOfRxGWSigGroup != COM_ZERO)
            {
              /* Invoke Com_RxGWSigGrpProcessing() function to process all Rx
              signal groups configured for gateway */
              Com_RxGWSigGrpProcessing(LpRxGWIpdu, COM_SIG_GW_STATUS_NORMAL);
            }
            #endif
          }
          /* Get the pointer to the n gatewayed Rx I-PDU */
          LddRxGWIpduIndex++;
          if(LddRxGWIpduIndex < (PduIdType)COM_RX_GW_COUNT)
          {
            /* Shift I-PDU status right by one to get the n status */
            LucIpduStatus >>= COM_ONE;
          }
          else
          {
            /* Set I-PDU status as zero */
            LucIpduStatus = COM_ZERO;
          }
          
          /* Decrement the counter */
          LucCount--;
        }while(LucIpduStatus != COM_ZERO);
      } /* Check whether I-PDU status is set */
      /* Decrement the count of the number of Rx I-PDUs configured for
      gateway */
      LucNoOfIpduStsCount--;
      LddRxGWIpduStatusIndex++;

    }while(LucNoOfIpduStsCount != COM_ZERO);
  } /* Report to DET, if module is not initialized */
  #endif
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Com_TxUpdateDmTimers                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function update deadline monitoring timers of  **
**                        Tx I-PDUs .                                         **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaTxIpduDm            **
**                                                 Com_GaaTxIpdu              **
**                                                 Com_GaaTxIpduStatus        **
**                                                 Com_GaaTxDMTimer           **
**                                                 Com_GaaTxIpduStatusBit     **
**                                                 Com_GaaTxMode              **
**                                                 Com_GaaTxMDTimer           **
**                                                 Com_GaaSigErrorCbk         **
**                                                 Com_GaaTxReptCount         **
**                                                 Com_GaaTxTPIpdu            **
**                                                 Com_GaaTxTPStatus          **
**                        Function(s) invoked    : SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
**                                                 PduR_ComCancelTransmit()   **
**                                                 pSigErrorCbk               **
*******************************************************************************/
#if(COM_TX_IPDU_DM == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_TxUpdateDmTimers(void)
{
  #if(COM_SIG_ERR_CBK_NOTIFY == STD_ON)
  /* Pointer to notification error call-back structure */
  P2CONST(Com_SigErrorCbk, AUTOMATIC, COM_CONST) LpSigErrorCbk;
  /* Local variable to store notification error call-back */
  uint8 LucNoOfSigCallback;
  Com_ErrCbkCountType LddSigErrorCbkIndex;
  #endif
  #if(COM_TX_CANCEL_SUPPORT == STD_ON)
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu;
  #if(COM_TX_TP_SUPPORT == STD_ON)
  P2CONST(Com_TxTPIpdu, AUTOMATIC, COM_CONST) LpTxTPIpdu;
  #endif
  #endif
  PduIdType LddTxIpduIndex;
  /* Local variable to store no. of TxIpdu configured for Deadline monitoring */
  PduIdType LddNoOfTxIpduDm;
  /* Local variable to store timer */
  uint16 LusTimer;

  /* Get the number of Tx I-PDUs configured for deadline monitoring */
  LddNoOfTxIpduDm = COM_TX_IPDU_DM_COUNT;
  /* Loop for the number of Tx I-PDUs configured for deadline monitoring */  
  while(LddNoOfTxIpduDm != (PduIdType)COM_ZERO)
  {  
    --LddNoOfTxIpduDm;
    LddTxIpduIndex = Com_GaaTxIpduDm[LddNoOfTxIpduDm].ddComTxPduId;
    #if(COM_TX_CANCEL_SUPPORT == STD_ON)
    LpTxIpdu = &Com_GaaTxIpdu[LddTxIpduIndex];
    #endif
    if(Com_GaaTxIpduStatus[LddTxIpduIndex] != (PduIdType)COM_ZERO)
    {
      {
        LusTimer = 
                Com_GaaTxDMTimer[Com_GaaTxIpdu[LddTxIpduIndex].ddTxIpduDmIndex];
        if(LusTimer != (uint16)COM_ZERO)
        {
          --LusTimer;

          if((uint16)COM_ZERO == LusTimer)
          {
            /* Reset Retry bit after deadline monitoring is over */
            SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
            Com_GaaTxIpduStatusBit[LddTxIpduIndex] &=
                 (uint16)(~(COM_TX_RETRY_STATUS_MASK | COM_TX_REQ_STATUS_MASK));
            SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
            #if(COM_TX_IPDU_TMS == STD_ON)
            if((Com_GaaTxIpdu[LddTxIpduIndex].ucTxConfig &
                                      COM_TX_IPDU_TMS_CONFIG_MASK) == COM_FALSE)
            #endif
            {
              if(Com_GaaTxMode[Com_GaaTxIpdu[LddTxIpduIndex].ddTrueTxModeIndex].
                                                   ucTxMode == COM_TX_NONE_MODE)
              {
                LusTimer = Com_GaaTxIpduDm[LddNoOfTxIpduDm].usDmTimeout;
                SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
                Com_GaaTxIpduStatusBit[LddTxIpduIndex] |=
                                                       (COM_TX_REQ_STATUS_MASK);
                SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
              }
            }
            #if(COM_TX_IPDU_MINDELAY_ENABLED == STD_ON)
            /* Check whether minimum delay timer is configured for I-PDU */
            if((Com_GaaTxIpdu[LddTxIpduIndex].ucTxConfig &
                                      COM_TX_IPDU_MDT_CONFIG_MASK) != COM_FALSE)
            {
              SchM_Enter_Com_TX_MDT_PROTECTION_AREA();
              /* Reset minimum delay timer to zero */
              Com_GaaTxMDTimer[Com_GaaTxIpdu[LddTxIpduIndex].ddTxMDTimerIndex]
                                                                    = (uint16)COM_ZERO;
              SchM_Exit_Com_TX_MDT_PROTECTION_AREA();
            }
            #endif
            #if(COM_TX_IPDU_REPETITION == STD_ON)
            /* Reset Repetition count*/
            if((Com_GaaTxIpdu[LddTxIpduIndex].ddTxReptIndex)
              != COM_INVALID_TXID_PARAM)
            {
              Com_GaaTxReptCount[Com_GaaTxIpdu[LddTxIpduIndex].ddTxReptIndex] =
              COM_ZERO;
              Com_GaaTxReptSubCount[Com_GaaTxIpdu[LddTxIpduIndex].ddTxReptIndex] =
              COM_ZERO;
            }
            #endif
            #if(COM_TX_CANCEL_SUPPORT == STD_ON)
            if(COM_TRUE == Com_GaaTxIpduDm[LddNoOfTxIpduDm].blCancelTxFlag)
            {
              (void)PduR_ComCancelTransmit(LpTxIpdu->ddTxIpduId);
            }
            #endif
            #if(COM_SIG_ERR_CBK_NOTIFY == STD_ON)
            /* Get the number of error notification call-back functions for
            corresponding signals configured for notification */
            LucNoOfSigCallback =
                        Com_GaaTxIpduDm[LddNoOfTxIpduDm].ucNoOfSigErrorCbk;
            /* Get the pointer to SigErrorCbk structure */
            LddSigErrorCbkIndex = 
              Com_GaaTxIpduDm[LddNoOfTxIpduDm].ddSigErrCbkIndex;
            LpSigErrorCbk = &Com_GaaSigErrorCbk[LddSigErrorCbkIndex];
            /* Loop for all the signals configured for notification (timeout) */
            do
            {
              /* Invoke the error notification call-back function */
              (LpSigErrorCbk->pSigErrorCbk)();
              /* Get the pointer to n SigErrorCbk structure */
              LddSigErrorCbkIndex++;
              LpSigErrorCbk = &Com_GaaSigErrorCbk[LddSigErrorCbkIndex];
              /* Decrement the count of number of signals configured for
              notification */
              LucNoOfSigCallback--;
            }while(LucNoOfSigCallback != COM_ZERO);
            #endif /*#if(COM_SIG_ERR_CBK_NOTIFY == STD_ON)*/
            #if(COM_TX_CANCEL_SUPPORT == STD_ON)
            if(COM_TRUE == Com_GaaTxIpduDm[LddNoOfTxIpduDm].blCancelTxFlag)
            {
              (void) PduR_ComCancelTransmit(LpTxIpdu->ddTxIpduId);
              #if(COM_TX_TP_SUPPORT == STD_ON)
              if(LpTxIpdu->ucTxTPRef != COM_INVALID_NONE)
              {
                LpTxTPIpdu = &Com_GaaTxTPIpdu[LpTxIpdu->ucTxTPRef];
                if((Com_GaaTxTPStatus[LpTxTPIpdu->ucTxTPStatusRef] &
                  (LpTxTPIpdu->ucTxTPStatusMask)) != COM_ZERO)
                {
                  SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
                  /* Unlock the buffer */
                  Com_GaaTxTPStatus[LpTxTPIpdu->ucTxTPStatusRef] &=
                                       (uint8)(~(LpTxTPIpdu->ucTxTPStatusMask));
                  SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
                }
              }
              #endif
            }
            #endif
          } /* Check whether deadline monitoring timer value is equal to zero */
          Com_GaaTxDMTimer[LddNoOfTxIpduDm] = LusTimer;
        }
      }
    }
  }
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_TxSigConfirmation                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function generates transmit confirmation       **
**                        notification per signal for the "deferred" Tx I-PDUs**
**                        of the Tx I-PDU group.                              **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : LpTxIpdu                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :  Com_GaaTxIpduConfirm      **
**                                                  Com_GaaSigNotifCbk        **
**                        Function(s) invoked    :  pSigNotifCbk              **
*******************************************************************************/

#if(COM_TX_SIGNAL_NOTIFY == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_TxSigConfirmation(
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST)LpTxIpdu)
{
  /* Pointer to Tx confirmation structure */
  P2CONST(Com_TxIpduConfirm, AUTOMATIC, COM_CONST) LpTxIpduConfirm;
  /* Pointer to notification call-back structure */
  P2CONST(Com_SigNotifCbk, AUTOMATIC, COM_CONST) LpSigNotifCbk;
  /* Local variable to store notification error call-back */
  uint8 LucNoOfSigCallback;
  Com_NotifCountType LddSigNotifCbkIndex;
  
  /* Get the pointer to confirmation structure */
  LpTxIpduConfirm = &Com_GaaTxIpduConfirm[LpTxIpdu->ddTxPduConfirmIndex];
  /* Get the number of call-back functions */
  LucNoOfSigCallback =  LpTxIpduConfirm->ucNoOfSigCallback;
  /* Get the pointer to signal notification call-back structure */
  LddSigNotifCbkIndex = LpTxIpduConfirm->ddSigNotifCbkIndex;
  LpSigNotifCbk = &Com_GaaSigNotifCbk[LddSigNotifCbkIndex];
  /* Loop for number of signals configured for call-back */
  while(LucNoOfSigCallback != COM_ZERO)
  {
    /* Invoke signal notification call-back function */
    (LpSigNotifCbk->pSigNotifCbk)();
    /* Decrement the number of signal call-back count */
    LucNoOfSigCallback--;
    /* Get pointer to n signal notification call-back structure */
    LddSigNotifCbkIndex++;
    LpSigNotifCbk = &Com_GaaSigNotifCbk[LddSigNotifCbkIndex];
  }
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_TxClearUpdateBit                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function clears update bit for all signals     **
**                        configured for a particular I-PDU.                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non-Reentrant for same Tx I-PDU.                    **
**                        Reentrant for different Tx I-PDUs.                  **
**                                                                            **
** Input Parameters     : LpTxIpdu, LpSourcePtr                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaTxUpdateBit         **
**                        Function(s) invoked    : SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
*******************************************************************************/
#if((COM_TX_SIGNAL_UB == STD_ON) || (COM_TX_SIGGROUP_UB == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_TxClearUpdateBit(
                  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST)LpTxIpdu,
                  P2VAR(uint8, AUTOMATIC, COM_VAR)LpSourcePtr)
{
  /* Pointer to Tx confirmation structure */
  P2CONST(Com_TxUpdateBit, AUTOMATIC, COM_CONST) LpTxUpdateBit;
  /* Pointer to Tx confirmation structure */
  P2CONST(uint8, AUTOMATIC, COM_CONST) LpUBitsTxIpduMask;
  /* Local variable to store no. of byte */
  uint16 LusNoOfByte;
  uint16 LusBufferIndex;
  uint16 LusUBitsTxIpduMaskIndex;

  LusBufferIndex = (uint16)COM_ZERO;
  /* Get the pointer to Tx Update bit Structure */
  LpTxUpdateBit = &Com_GaaTxUpdateBit[LpTxIpdu->ddTxIpduUbIndex];
  /* Get the pointer to I-PDU SduDataPtr */
  LusBufferIndex = LusBufferIndex + (LpTxUpdateBit->ucStartPosition);
  LusNoOfByte = LpTxUpdateBit->ucEndPosition;
  LpUBitsTxIpduMask = LpTxUpdateBit->pUbitsTxIpduMask;
  LusUBitsTxIpduMaskIndex = (uint16)COM_ZERO; 

  /* Enter protection area */
  SchM_Enter_Com_TX_IPDU_BUFFER_PROTECTION_AREA();
  /* Loop for number of bytes of data in I-PDU */
  do
  {
    /* Reset update bits in I-PDU by applying mask */
    (LpSourcePtr[LusBufferIndex]) &= (LpUBitsTxIpduMask[LusUBitsTxIpduMaskIndex]);
    /* Increase the index of buffer */
    LusBufferIndex++;
    LusUBitsTxIpduMaskIndex++;
    /* Decrement the number of bytes in I-PDU count */
    LusNoOfByte--;
  }while(LusNoOfByte != (uint16)COM_ZERO);
  /* Exit protection area */
  SchM_Exit_Com_TX_IPDU_BUFFER_PROTECTION_AREA();
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_RxSigProcessing                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function process all signals configured for    **
**                        particular I-PDU.                                   **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non-Reentrant for same Rx I-PDU.                    **
**                        Reentrant for different Rx I-PDUs.                  **
**                                                                            **
** Input Parameters     : LpRxIpdu                                            **
**                                                                            **
** InOut parameter      : LddLength                                           **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaRxTPIpdu            **
**                                                 Com_GaaRxSignal            **
**                                                 Com_GaaRxDMTimer           **
**                                                 Com_GaaRxUnpack            **
**                                                 Com_GaaRxInvalid           **
**                                                 Com_GaaInvalidFuncPtr      **
**                                                 Com_GaaInvNotifCbk         **
**                                                 Com_GaaWrFuncPtr           **
**                                                 Com_GaaSigNotifCbk         **
**                                                 Com_GaaRxDynSigLength      **
**                        Function(s) invoked    : SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
**                                                 pRdFuncPtr                 **
**                                                 pInvalidFuncPtr            **
**                                                 pFilterFuncPtr             **
**                                                 pWrFuncPtr                 **
**                                                 pSigNotifCbk               **
*******************************************************************************/
#if (COM_RX_SIGNAL == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_RxSigProcessing(
                PduIdType ComRxPduId, P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST)LpRxIpdu,
                PduLengthType LddLength)
{
  /* Pointer to Rx Signal structure */
  P2CONST(Com_RxSignal, AUTOMATIC, COM_CONST) LpRxSignal;
  #if(COM_RX_SIGNAL_INVALID == STD_ON)
  /* Pointer to Rx Invalid structure */
  P2CONST(Com_RxInvalid, AUTOMATIC, COM_CONST) LpRxInvalid;
  #endif
  #if(COM_RX_DYN_SUPPORT == STD_ON)
  /* Pointer to Rx TP structure */
  PduLengthType LddDynSigLength;
  #endif
  #if ((COM_RX_SIGNAL_FILTER == STD_ON) || (COM_RX_SIGNAL_INVALID == STD_ON) \
                                    ||  (COM_RX_SIGNAL_UBDMREPLACE == STD_ON))
  /* Pointer to Rx unpack structure */
  P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST) LpRxUnpack;
  P2VAR(uint8, AUTOMATIC, COM_VAR) LpSignalData = NULL_PTR;
  /* buffer Loop Index */  
  PduLengthType LddBufferIndex;  
  #endif
  #if ((COM_RX_SIGNAL_FILTER == STD_ON) || (COM_RX_SIGNAL_INVALID == STD_ON)\
                                      ||(COM_RX_SIGNAL_UBDMREPLACE == STD_ON))
  /* Local variable to store signal size */
  PduLengthType LddSignalSize;
  /* Local variable to store signal type */
  uint8 LucSignalType;
  PduLengthType LddSignalMemSize;
  #endif
  #if ((COM_RX_SIGNAL_UB == STD_ON) || (COM_RX_SIGNAL_UBDM == STD_ON) || \
       (COM_RX_SIGNAL_FILTER == STD_ON) || (COM_RX_SIGNAL_INVALID == STD_ON)\
                                      ||(COM_RX_SIGNAL_UBDMREPLACE == STD_ON)\
                                            ||(COM_RX_SIGNAL_NOTIFY == STD_ON))
  /* Local variable to store signal configuration */
  uint8 LucSigConfig;
  #endif
  uint8 LucNoOfSignal;
  Com_SignalIdType LddRxSignalIndex;

  #if((COM_IDSM_SUPPORT == STD_ON) && (COM_RX_SIGNAL_FILTER == STD_ON))
  boolean LblIsInvRangeSigPdu = COM_FALSE;
  uint16 LaaInvRangeSigList[COM_FOUR] = {COM_SIG_RANGECHECK_DEF_ID,
                                         COM_SIG_RANGECHECK_DEF_ID,
                                         COM_SIG_RANGECHECK_DEF_ID,
                                         COM_SIG_RANGECHECK_DEF_ID};
  uint8 LucInvRangeSigListIndex = COM_ZERO;                                       
  #else
  COM_UNUSED(ComRxPduId);
  #endif

  /* #1504 : Update Dynamic signal length before invoking callback function */
  #if(COM_RX_DYN_SUPPORT == STD_ON)
  /* #2142 : separate DYN PDU from TP */
  if(COM_DYN_IPDU == LpRxIpdu->ucIpduType)
  {
    LddDynSigLength = (PduLengthType)(LddLength - LpRxIpdu->ddRxNonDynLength);
    Com_GaaRxDynSigLength[LpRxIpdu->ddRxIpduDynLegthRef] = LddDynSigLength;
  }
  #endif
  
  /* Get the number of  Rx signals */
  LucNoOfSignal = LpRxIpdu->ucNoOfRxSignal;
  /* Get the pointer to  Rx signal structure */
  LddRxSignalIndex = LpRxIpdu->ddRxSigIndex;
  LpRxSignal = &Com_GaaRxSignal[LddRxSignalIndex];  
  /* Loop for number of  Rx signals */
  do
  {
    if(LddLength >= LpRxSignal->ddSignalEndByte)
    {
      #if ((COM_RX_SIGNAL_UB == STD_ON) || \
      (COM_RX_SIGNAL_UBDM == STD_ON) || \
        (COM_RX_SIGNAL_FILTER == STD_ON) || \
        (COM_RX_SIGNAL_INVALID == STD_ON) || \
        (COM_RX_SIGNAL_UBDMREPLACE == STD_ON) || \
        (COM_RX_SIGNAL_NOTIFY == STD_ON))
      /* Get the signal configuration */
      LucSigConfig = LpRxSignal->ucRxSigConfig;
      #endif
      /* Each bit represent signal configuration in an I-PDU
        0x01 : Notification
        0x02 : Reserved for future purpose
        0x04 : Update bit
        0x08 : Update bit deadline monitoring
        0x10 : Update bit deadline monitoring with timeout replacement
        0x20 : Filtering
        0x40 : Invalidation
        0x80 : Invalidation replacement with init value */
      #if (COM_RX_SIGNAL_UB == STD_ON)
      /* Check whether update bit is configured */
      if((LucSigConfig & COM_RX_SIGNAL_UB_CONFIG_MASK) != COM_FALSE)
      {
        /* Check whether signal is received with an update bit */
        if(COM_FALSE == (*(LpRxSignal->pUBit) & (LpRxSignal->ucUbitMask)))
        {
          /* return if update bit is not set */
          LucSigConfig = COM_ZERO;
        }
        #if (COM_RX_SIGNAL_UBDM == STD_ON)
        /* Check whether signal has been configured for deadline monitoring */
        else if((LucSigConfig & COM_RX_SIGNAL_UBDM_CONFIG_MASK) != COM_FALSE)
        {
          #if(COM_RX_INTERRUPT_BASED_PROCESS == STD_OFF)
          SchM_Enter_Com_RX_DM_STS_PROTECTION_AREA();
          #endif
          Com_GaaRxDMTimer[LpRxSignal->ucRxUbDmIndex] = COM_INVALID_DM_TIMER;
          #if(COM_RX_INTERRUPT_BASED_PROCESS == STD_OFF)
          SchM_Exit_Com_RX_DM_STS_PROTECTION_AREA();
          #endif
        }
        else
        {
          /* Dummy loop to avoid QAC warning */
        }
        #endif
      }
      if(LucSigConfig != COM_ZERO)
      #endif
      {
        /* #7803 */
        #if ((COM_RX_SIGNAL_FILTER == STD_ON) || \
                                (COM_RX_SIGNAL_INVALID == STD_ON))
        /* Check whether signal is configured for invalidation/filtering/UB
        deadline monitoring with timeout replacement */
        if(LucSigConfig >= COM_RX_SIGNAL_UBDMREPLACE_CONFIG_MASK)
        {
          /* Get the pointer to Rx unpack structure */
          LpRxUnpack = &Com_GaaRxUnpack[LpRxSignal->ddRxUnpackIndex];

          if(LpRxUnpack->ucSignalType < COM_FOUR)
          {
            LddSignalMemSize = (PduLengthType)Com_GaaSigMemSize[LpRxUnpack->ucSignalType];
          }
          else
          {
            LddSignalMemSize = LpRxUnpack->ddSignalSize;
          }          

          if(COM_FALSE 
            == (LpRxIpdu->ucRxConfig & COM_RX_IPDU_DEFERRED_CONFIG_MASK))
          {            
            #if(COM_RX_SIGNAL_IMMEDIATENOTIFY == STD_ON) 
            for(LddBufferIndex = (PduLengthType)COM_ZERO; LddBufferIndex < 
            LddSignalMemSize; LddBufferIndex++)
            {
              Com_GaaSignalValidCKBufferIM[LddBufferIndex] = COM_ZERO;
            }

            LpSignalData = (P2VAR(uint8, AUTOMATIC, COM_VAR))
                                      &Com_GaaSignalValidCKBufferIM[COM_ZERO];
            #endif
          }
          else
          {
            #if(COM_RX_IPDU_DEFERRED == STD_ON)
            for(LddBufferIndex = (PduLengthType)COM_ZERO; LddBufferIndex < 
            LddSignalMemSize; LddBufferIndex++)
            {
              Com_GaaSignalValidCKBufferDE[LddBufferIndex] = COM_ZERO;
            }

            LpSignalData = (P2VAR(uint8, AUTOMATIC, COM_VAR))
                                      &Com_GaaSignalValidCKBufferDE[COM_ZERO];
            #endif
          }    

          /* Invoke read function to unpack signal data from I-PDU buffer */
          (void)Com_UnPackRequestRead(LpRxUnpack, LpSignalData);
          /* Get the type of the signal */
          LucSignalType = LpRxUnpack->ucSignalType;
          /* Get the size of the signal */
          LddSignalSize = LpRxUnpack->ddSignalSize;
          #if (COM_RX_SIGNAL_INVALID == STD_ON)
          /* Check whether invalidation has been configured */
          if((LucSigConfig & COM_RX_SIGNAL_INVALID_CONFIG_MASK) != COM_FALSE)
          {
            LpRxInvalid = &(Com_GaaRxInvalid[LpRxSignal->ucInvIndex]);
            /* Invoke invalid function and check the return value */
            if((Com_GaaInvalidFuncPtr[LucSignalType].pInvalidFuncPtr)
             (LpRxInvalid->pInvalidValue,LpSignalData,LddSignalSize)
                                                                  != COM_FALSE)
            {
              /* Check whether invalidation with replacement
              has been configured */
              if((LucSigConfig & COM_RX_SIGNAL_INVREPLACE_CONFIG_MASK) 
                != COM_FALSE)
              {
                /* Get the pointer to init value */
                /* polyspace:begin<MISRA-C:11.5:Not a defect:Justify with annotations> No Impact of this rule violation */
                LpSignalData = 
                    (P2VAR(uint8, AUTOMATIC, COM_VAR))(LpRxInvalid->pInitValue);
                /* polyspace:end<MISRA-C:11.5:Not a defect:Justify with annotations> No Impact of this rule violation */                    
                /* Negation of sixth bit for getting 
                original signal configuration */
                LucSigConfig &= (uint8)(~(COM_RX_SIGNAL_FILTER_CONFIG_MASK));
              }
              else
              {
                #if (COM_RX_INVALIDNOTIFY == STD_ON)
                /* Invoke invalid notification call-back function */
                (*(Com_GaaInvNotifCbk[LpRxInvalid->ddInvNotifCbkIndex]))();
                #endif
                /* Set signal configuration to zero */
                LucSigConfig = COM_ZERO;
              }
            } /* Invoke invalid function and check the return value */
          } /* Check whether invalidation has been configured */
          #endif/*#if (COM_RX_SIGNAL_INVALID == STD_ON)*/

          #if (COM_RX_SIGNAL_FILTER == STD_ON)
          /* Check whether filtering is configured for signal */
          if((LucSigConfig & COM_RX_SIGNAL_FILTER_CONFIG_MASK) != COM_FALSE)
          {
            /* Reset the previous value in MASKED_NEW_DIFFERS_MASKED_OLD filter, 
            when Rx Timeout is occurred - Fixed by AUTRON START*/		  
            /* Invoke filter function and check the return value */
            /* polyspace:begin<RTE: NIP : Not a defect : No Action Planned > Initialized pointer */
            /* polyspace:begin<RTE: COR : Not a defect : No Action Planned> Not Null Pointer */
            if(COM_FALSE == (((P2CONST(Com_FilterNever, AUTOMATIC, COM_CONST))
                             (LpRxSignal->pFilter))->pFilterFuncPtr)
                                (LpRxSignal->pFilter, LpSignalData, COM_ZERO))
            {
              /* Set signal configuration to zero */
              LucSigConfig = COM_ZERO;
              #if(COM_IDSM_SUPPORT == STD_ON)
              {
                if((LpRxSignal->ucRxSigConfig & COM_RX_SIGNAL_IDSM_MASK) != COM_ZERO)
                {
                  if(LucInvRangeSigListIndex < COM_FOUR)
                  {
                    LblIsInvRangeSigPdu = COM_TRUE;
                    LaaInvRangeSigList[LucInvRangeSigListIndex] = (uint16)LddRxSignalIndex;
                    LucInvRangeSigListIndex++;
                  }
                }
              }
              #endif
            }
            /* polyspace:end<RTE: NIP : Not a defect : No Action Planned > Initialized pointer */
            /* polyspace:end<RTE: COR : Not a defect : No Action Planned> Not Null Pointer */            
            /* Reset the previous value in MASKED_NEW_DIFFERS_MASKED_OLD filter, 
            when Rx Timeout is occurred - Fixed by AUTRON END*/		  			
          }
          #endif
          /* Check whether signal configuration is equal to zero */
          if(LucSigConfig != COM_ZERO)
          {
            /* Invoke write function to pack signal data into signal buffer */
            Com_GaaWrFuncPtr[LucSignalType].pWrFuncPtr
                        (LpSignalData, LpRxSignal->pSignalBuffer,LddSignalSize);

          }
        }/* Check whether signal is configured for invalidation/filtering/update
          bit deadline monitoring with timeout replacement */
        #endif/*#if ((COM_RX_SIGNAL_FILTER == STD_ON) ||
                          (COM_RX_SIGNAL_INVALID == STD_ON))*/
        #if (COM_RX_SIGNAL_NOTIFY == STD_ON)
        /* Check whether notification has been configured for signal */
        if((LucSigConfig & COM_RX_SIGNAL_NOTIF_CONFIG_MASK) != COM_FALSE)
        {
          /* Invoke notification call-back function */
          (Com_GaaSigNotifCbk[LpRxSignal->ddNotifCbkIndex].pSigNotifCbk)();
        }
        #endif
      } /* if(LddLength > LpRxSignal->ucEndPosition) */
    }
    /* Decrement the count of number of signals */
    LucNoOfSignal--;
    /* Get the pointer to n  Rx signal structure */
    LddRxSignalIndex++;
    LpRxSignal = &Com_GaaRxSignal[LddRxSignalIndex];  
  }while(LucNoOfSignal != COM_ZERO);

  #if((COM_IDSM_SUPPORT == STD_ON) && (COM_RX_SIGNAL_FILTER == STD_ON))
  if(LblIsInvRangeSigPdu == COM_TRUE)
  {
    IdsM_SigRangeCheckErrorReport(ComRxPduId,
    (P2CONST(uint16, AUTOMATIC, COM_CONST))&LaaInvRangeSigList[COM_ZERO], 
    (P2CONST(uint8, AUTOMATIC, COM_CONST))Com_GaaRxPduInfoPtr[ComRxPduId].SduDataPtr, 
    LddLength);
  }
  #endif
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_RxSigGrpProcessing                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function process all Rx signal groups          **
**                        configured for the I-PDU.                           **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non-Reentrant for same Rx I-PDU.                    **
**                        Reentrant for different Rx I-PDUs.                  **
**                                                                            **
** Input Parameters     : LpRxIpdu                                            **
**                                                                            **
** InOut parameter      : LddLength                                           **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaRxSigGroup          **
**                                                 Com_GaaRxDMTimer           **
**                                                 Com_GaaRxInvSigGroup       **
**                                                 Com_GaaRxSigInGrp          **
**                                                 Com_GaaRxSigInGrpInv       **
**                                                 Com_GaaRxUnpack            **
**                                                 Com_GaaInvalidFuncPtr      **
**                                                 Com_GaaInvNotifCbk         **
**                                                 Com_GaaSigNotifCbk         **
**                        Function(s) invoked    : SchM_Enter_Com()           **
**                                                 SchM_Exit_Com()            **
**                                                 pRdFuncPtr                 **
**                                                 pInvalidFuncPtr            **
**                                                 pWrFuncPtr                 **
**                                                 pSigNotifCbk               **
*******************************************************************************/
#if(COM_RX_SIGGROUP == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_RxSigGrpProcessing(
                PduIdType ComRxPduId, P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST)LpRxIpdu,
                PduLengthType LddLength)
{
  #if((COM_RX_SIGGROUP_UB == STD_ON) || \
     (COM_RX_SIGGROUP_INVALID == STD_ON) || \
     (COM_RX_SIGGROUP_INVALIDREPLACE == STD_ON))
  /* Pointer to Rx deadline monitoring structure */
  P2CONST(uint8, AUTOMATIC, COM_CONST) LpIpduBuffer;
  /* Pointer to Pack structure */
  P2CONST(Com_TxPack, AUTOMATIC, COM_CONST)LpPackSigGroup;  
  #endif
  /* Pointer to Rx Signal Group structure */
  P2CONST(Com_RxSigGroup, AUTOMATIC, COM_CONST) LpRxSigGroup;
  #if(COM_RX_SIGGROUP_INVALID == STD_ON)
  /* Pointer to Rx Unpack structure */
  P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST) LpRxUnpack;
  /* Pointer to Signal Data structure */
  P2VAR(uint8, AUTOMATIC, COM_VAR) LpSignalData = NULL_PTR;
  /* Pointer to Rx Invalid Signal Group structure */
  P2CONST(Com_RxInvSigGroup, AUTOMATIC, COM_CONST) LpRxInvSigGrp;
  /* Pointer to Rx Signal InGroup Invalid structure */
  P2CONST(Com_RxSigInGrpInv, AUTOMATIC, COM_CONST) LpRxSigInGrpInv;
  /* Pointer to Rx Signal InGroup structure */
  P2CONST(Com_RxSigInGrp, AUTOMATIC, COM_CONST) LpRxSigInGrp;
  /* Local variable to store no of signal or size */
  uint8 LucNoOfSigOrSize;
  #endif
  /* Local variable to store signal group */
  uint8 LucNoOfSigGroup;
  #if((COM_RX_SIGGROUP_UB == STD_ON) || \
       (COM_RX_SIGGROUP_INVALID == STD_ON) || \
       (COM_RX_SIGGROUP_NOTIFY == STD_ON)  || \
       (COM_RX_SIGGROUP_INVALIDREPLACE == STD_ON))
  /* Local variable to store signal group configuration */
  uint8 LucSigGroupConfig;
  #endif
  #if(COM_RX_SIGGROUP_INVALID == STD_ON)
  PduLengthType LddBufferIndex; 
  #endif
  #if(COM_RX_SIGGROUP_INVALID == STD_ON)
  /* Local variable to store Invalid flag */
  boolean LblInvalidFlag;
  Com_SignalIdType LddRxSigInGrpIndex;
  PduLengthType LddSignalMemSize;  
  #endif
  Com_SignalGroupIdType LddRxSigGroupIndex;
  /* Get the number of  Rx signal groups */
  LucNoOfSigGroup = LpRxIpdu->ucNoOfRxSigGroup;
  /* Get the pointer to  Rx signal group structure */
  LddRxSigGroupIndex = LpRxIpdu->ddRxSigGrpIndex;
  LpRxSigGroup = &Com_GaaRxSigGroup[LddRxSigGroupIndex];
  /* Loop for number of  Rx signal groups */
  do
  {
    /* Check length of received Ipdu is part of signal configuration */
    if(LddLength >= LpRxSigGroup->ddSignalEndByte)
    {
      #if((COM_RX_SIGGROUP_UB == STD_ON) || \
          (COM_RX_SIGGROUP_INVALID == STD_ON) || \
          (COM_RX_SIGGROUP_NOTIFY == STD_ON)  || \
          (COM_RX_SIGGROUP_INVALIDREPLACE == STD_ON))
      /* Get the signal group configuration */
      LucSigGroupConfig = LpRxSigGroup->ucSigGroupConfig;
      #endif

      #if((COM_RX_SIGGROUP_UB == STD_ON) || \
           (COM_RX_SIGGROUP_INVALID == STD_ON) || \
           (COM_RX_SIGGROUP_INVALIDREPLACE == STD_ON))
      /* Get the pointer to I-PDU buffer */
      LpIpduBuffer = (P2CONST(uint8, AUTOMATIC, COM_CONST))
                                                   LpRxSigGroup->pIpduBuffer;
      #endif
      #if(COM_RX_SIGGROUP_UB == STD_ON)
      /* Signal group configuration:
         0x01: Notification
         0x02: Update bit
         0x04: Update bit with timeout
         0x08: Invalid configuration
         0x10: Replace the value (Invalid replacement )
         0x20: Replace the value (Timeout/Invalid Replacement) */
      /* Check whether update bit is configured */
      if((LucSigGroupConfig & COM_RX_SIGGRP_UB_CONFIG_MASK) != COM_FALSE)
      {
        /* Check whether signal group is received with an update bit */
        if(COM_FALSE == (*(LpRxSigGroup->pUBit) & (LpRxSigGroup->ucUbitMask)))
        {

          /* Set signal group configuration to zero */
          LucSigGroupConfig = COM_ZERO;
        }
        #if(COM_RX_SIGGROUP_UBDM == STD_ON)
        /* Check whether update bit with deadline monitoring is configured */
        else if((LucSigGroupConfig & COM_RX_SIGGRP_UBDM_CONFIG_MASK)
                                                                  != COM_FALSE)
        {
          #if(COM_RX_INTERRUPT_BASED_PROCESS == STD_OFF)
          SchM_Enter_Com_RX_DM_STS_PROTECTION_AREA();
          #endif
          /* Update Rx deadline monitoring status */
          Com_GaaRxDMTimer[LpRxSigGroup->ucRxUbDmIndex] = COM_INVALID_DM_TIMER;
          #if(COM_RX_INTERRUPT_BASED_PROCESS == STD_OFF)
          SchM_Exit_Com_RX_DM_STS_PROTECTION_AREA();
          #endif
        }
        else
        {
          /* Dummy loop to avoid QAC warning */
        }
        #endif
      }
      #endif
      #if(COM_RX_SIGGROUP_INVALID == STD_ON)
      /* Check whether signal group is configured for invalidation */
      if((LucSigGroupConfig & COM_RX_SIGGRP_INVALID_CONFIG_MASK) != COM_FALSE)
      {
        /* Initialize invalid flag to false */
        LblInvalidFlag = COM_ZERO;

        LpRxInvSigGrp = &(Com_GaaRxInvSigGroup[LpRxSigGroup->ucInvIndex]);
        /* Get the number of signals in signal group configured for
        invalidation check */
        LucNoOfSigOrSize = LpRxInvSigGrp->ucNoOfSignal;

        /* Get the pointer to  Rx signal in group structure */
        LddRxSigInGrpIndex = LpRxInvSigGrp->ddRxSigInGrpIndex;
        LpRxSigInGrp = &(Com_GaaRxSigInGrp[LddRxSigInGrpIndex]);

        if(COM_FALSE 
          == (LpRxIpdu->ucRxConfig & COM_RX_IPDU_DEFERRED_CONFIG_MASK))
        {            
          #if(COM_RX_SIGGROUP_IMMEDIATENOTIFY == STD_ON) 
          LpSignalData = (P2VAR(uint8, AUTOMATIC, COM_VAR))
                                    &Com_GaaSignalValidCKBufferIM[COM_ZERO];
          #endif
        }
        else
        {
          #if(COM_RX_IPDU_DEFERRED == STD_ON)
          LpSignalData = (P2VAR(uint8, AUTOMATIC, COM_VAR))
                                    &Com_GaaSignalValidCKBufferDE[COM_ZERO];
          #endif
        } 
        
        /* Loop for number of signals configured for invalidation */
        do
        {
          /* #7803 */
          if(LpRxSigInGrp->ucSigInGrpInvIndex != COM_INVALID_NONE)
          {
            LpRxSigInGrpInv = &(Com_GaaRxSigInGrpInv[LpRxSigInGrp->ucSigInGrpInvIndex]);
            /* Get the pointer to Rx unpack structure */
            LpRxUnpack = &Com_GaaRxUnpack[LpRxSigInGrpInv->ddRxUnpackIndex];

            if(LpRxUnpack->ucSignalType < COM_FOUR)
            {
              LddSignalMemSize = (PduLengthType)Com_GaaSigMemSize[LpRxUnpack->ucSignalType];
            }
            else
            {
              LddSignalMemSize = LpRxUnpack->ddSignalSize;
            }

            if(COM_FALSE 
              == (LpRxIpdu->ucRxConfig & COM_RX_IPDU_DEFERRED_CONFIG_MASK))
            {            
              #if(COM_RX_SIGNAL_IMMEDIATENOTIFY == STD_ON) 
              for(LddBufferIndex = (PduLengthType)COM_ZERO; LddBufferIndex < 
              LddSignalMemSize; LddBufferIndex++)
              {
                Com_GaaSignalValidCKBufferIM[LddBufferIndex] = COM_ZERO;
              }
              #endif
            }
            else
            {
              #if(COM_RX_IPDU_DEFERRED == STD_ON)
              for(LddBufferIndex = (PduLengthType)COM_ZERO; LddBufferIndex < 
              LddSignalMemSize; LddBufferIndex++)
              {
                Com_GaaSignalValidCKBufferDE[LddBufferIndex] = COM_ZERO;
              }
              #endif
            }          

            /* Invoke read function to unpack signal data from I-PDU buffer */
            (void)Com_UnPackRequestRead(LpRxUnpack, LpSignalData);
            /* Invoke the corresponding invalid function and check the return
               value */
            if(((Com_GaaInvalidFuncPtr[LpRxUnpack->ucSignalType].pInvalidFuncPtr)(
                                   LpRxSigInGrpInv->pInvalidValue, LpSignalData,
                                    LpRxUnpack->ddSignalSize)) != COM_FALSE)
            {
              /* #1329 : Remove invalid notification function call. */ 
              /* Set invalid flag to true */
              LblInvalidFlag = COM_TRUE;
            }
          }
          /* Decrement the count of number of signals */
          LucNoOfSigOrSize--;
          /* Increment the pointer by one */
          LddRxSigInGrpIndex++;
          LpRxSigInGrp = &(Com_GaaRxSigInGrp[LddRxSigInGrpIndex]);
        }while(LucNoOfSigOrSize != COM_ZERO);
        /* Check whether invalid flag is true */
        if(COM_TRUE == LblInvalidFlag)
        {
         /* Check whether signal group is configured for invalid notification */
          #if(COM_RX_SIGGROUP_INVALIDREPLACE == STD_ON)
          if((LucSigGroupConfig & COM_RX_SIGGRP_INVREPLACE_CONFIG_MASK) ==
                                                                     COM_FALSE)
          #endif
          {
            #if(COM_RX_INVALIDNOTIFY == STD_ON)
            /* Invoke invalid notification call-back function */
            (*(Com_GaaInvNotifCbk[LpRxInvSigGrp->ddInvNotifCbkIndex]))();
            #endif
            /* Reset signal group configuration to zero */
            LucSigGroupConfig = COM_ZERO;
          }
          #if(COM_RX_SIGGROUP_INVALIDREPLACE == STD_ON)
          else
          {
            /* Get the pointer to init value and pack it into I-PDU buffer */
            LpIpduBuffer = (P2CONST(uint8, AUTOMATIC, COM_CONST))
                                                   (LpRxInvSigGrp->pInitValue);
          }
          #endif
        } /* Check whether invalid flag is true */
      } /* Check whether signal group is configured for invalidation */
      #endif/*#if(COM_RX_SIGGROUP_INVALID == STD_ON)*/

      #if((COM_RX_SIGGROUP_UB == STD_ON) || \
           (COM_RX_SIGGROUP_INVALID == STD_ON) || \
           (COM_RX_SIGGROUP_INVALIDREPLACE == STD_ON))
      /* Check whether signal group is configured for timeout or invalid
      replacement */
      /* #7744, #7830 */
      if(((LucSigGroupConfig & COM_RX_SIGGRP_UB_CONFIG_MASK) != COM_FALSE) || ((LucSigGroupConfig & COM_RX_SIGGRP_INVREPLACE_CONFIG_MASK) != COM_FALSE))
      {
        /* Invoke write function to pack signal group data into signal group
        buffer */
        /* polyspace:begin<RTE: NIP : Not a defect : No Action Planned > Initialized pointer */
        LpPackSigGroup = LpRxSigGroup->pPackSigGrpBuffer;
        (void)Com_PackSigGrp(LpPackSigGroup, LpIpduBuffer, LpPackSigGroup->pWrBuffer, LpRxSigGroup->pMaskingBuffer);   
        /* polyspace:end<RTE: NIP : Not a defect : No Action Planned > Initialized pointer */
      }
      #endif
      #if(COM_RX_SIGGROUP_NOTIFY == STD_ON)
      /* Check whether signal group is configured for notification */
      if((LucSigGroupConfig & COM_RX_SIGGRP_NOTIF_CONFIG_MASK) != COM_FALSE)
      {

        /* Invoke notification call-back function */
        (Com_GaaSigNotifCbk[LpRxSigGroup->ddNotifCbkIndex].pSigNotifCbk)();
      }
      #endif
    }
    /* Decrement the count of number of  signal groups */
    LucNoOfSigGroup--;
    /* Get the pointer to n  Rx signal group structure */
    LddRxSigGroupIndex++;
    LpRxSigGroup = &Com_GaaRxSigGroup[LddRxSigGroupIndex];
  }while(LucNoOfSigGroup != COM_ZERO);
  COM_UNUSED(ComRxPduId);  
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_RxGWSigProcessing                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function processes all signals in the I-PDU    **
**                        that are configured for gateway, based on the signal**
**                        transfer property.                                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : LpRxGWIpdu                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaRxGWSignal          **
**                                                 Com_GaaRxUnpack            **
**                        Function(s) invoked    : pRdFuncPtr                 **
**                                                 Com_SendSignal()           **
*******************************************************************************/
#if((COM_RX_SIGNAL_GW == STD_ON) || (COM_RX_SIGINGROUP_GW == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_RxGWSigProcessing
           (P2CONST(Com_RxGWIpdu, AUTOMATIC, COM_CONST)LpRxGWIpdu, uint8 
           lucGWStatus)
{
  /* Pointer to Gate Way Rx Signal structure */
  P2CONST(Com_RxGWSignal, AUTOMATIC, COM_CONST)LpGWRxSignal;

  /* Pointer to Rx Unpack structure */
  P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST) LpRxUnpack;
  /* Local variable to store Tx signal ID */
  Com_SignalIdType LddTxSignalId;
  /* buffer Loop Index */  
  PduLengthType LddBufferIndex;
  /* Local variable to store no. of Gateway signal  */
  uint8 LucNoOfGWSignal;
  /* Local variable to store no. of route signal */
  uint8 LucNoOfRouteSignal;
  
  PduLengthType LddSignalMemSize;
  /* Local variable to store the tx index */
  Com_SignalIdType LddRouteTxIndex;

  Com_SignalIdType LddRxGWSignalIndex;

  #if(COM_TX_GW_CALLOUT_SUPPORT == STD_ON)
  boolean LblSigCalloutResult;
  #endif
  
  /* Local variable to store return value */
  #if(COM_RX_SIGNAL_UB == STD_ON)
  /* Local variable to store process flag */
  boolean LblProcessFlag;
  #endif
  /* Get the number of Rx gateway signals */
  LucNoOfGWSignal = LpRxGWIpdu->ucNoOfRxGWSignal;
  /* Get the pointer to  Rx gateway signal structure */
  LddRxGWSignalIndex = LpRxGWIpdu->ddGWRxSigIndex;

  /* Loop for all  Rx signals that are configured for gateway */
  /* Because this function is invoke, when Signal number is over one.
  So, LucNoOfGWSignal variable is always over one. 
  And, it's fine to use "do-while" operation */
  do
  {
    /* Get the pointer to n  Rx gateway signal structure */
    LpGWRxSignal = &Com_GaaRxGWSignal[LddRxGWSignalIndex];
    
    if((lucGWStatus == COM_SIG_GW_STATUS_TOUT) && 
      (LpGWRxSignal->blDMTrigger == COM_FALSE))
    {
      /* Do nothing */
    }
    else
    {
      #if(COM_RX_SIGNAL_UB == STD_ON)
      /* Set the process flag to true */
      LblProcessFlag = COM_TRUE;
      /* Check whether update bit is configured signal */
      if((LpGWRxSignal->ucUbitMask) != COM_ZERO)
      {
        /* Check whether signal is received with an update bit */
        if(COM_FALSE == (*(LpGWRxSignal->pUBit) & (LpGWRxSignal->ucUbitMask)))
        {
          /* Set the process flag to false */
          LblProcessFlag = COM_FALSE;
        }
      }
      /* Check whether process flag is true */
      if(COM_TRUE == LblProcessFlag)
      #endif
      {
        LpRxUnpack = &(Com_GaaRxUnpack[LpGWRxSignal->ddRxUnpackIndex]);

        if(LpRxUnpack->ucSignalType < COM_FOUR)
        {
          LddSignalMemSize = (PduLengthType)Com_GaaSigMemSize[LpRxUnpack->ucSignalType];
        }
        else
        {
          LddSignalMemSize = LpRxUnpack->ddSignalSize;
        }

        for(LddBufferIndex = (PduLengthType)COM_ZERO; LddBufferIndex < 
        LddSignalMemSize; LddBufferIndex++)
        {
          Com_GaaSignalGWBuffer[LddBufferIndex] = COM_ZERO;
        }
        
        /* Invoke read function to unpack the signal from an I-PDU */
        (void)Com_UnPackRequestRead(LpRxUnpack, 
          (P2VAR(void, AUTOMATIC, COM_VAR)) &Com_GaaSignalGWBuffer[COM_ZERO]);
        /* Get the number of signals to be routed */
        LucNoOfRouteSignal = LpGWRxSignal->ucNoOfRouteSignal;
        /* Get the index of Tx Signal handleID structure */
        LddRouteTxIndex = LpGWRxSignal->ddTxSigIndex;
  	  
  	  	
        /* Loop for number of Tx signals to be routed */
        do
        {        
          LddTxSignalId = 
  			  (Com_SignalIdType)Com_GaaTxGWSignal[LddRouteTxIndex].ddGWTxSigIndex;
          #if(COM_TX_GW_CALLOUT_SUPPORT == STD_ON)
          for(LddBufferIndex = (PduLengthType)COM_ZERO; LddBufferIndex < 
          LddSignalMemSize; LddBufferIndex++) 
          {
            Com_GaaSignalGWBufferSub[LddBufferIndex] = 
            Com_GaaSignalGWBuffer[LddBufferIndex];
          }                
          LblSigCalloutResult = COM_TRUE;
          if(Com_GaaTxGWSignal[LddRouteTxIndex].ucGWCalloutAction != 
          COM_SIG_GW_CALLOUT_ACT_NONE)
          {
            if(!((COM_SIG_GW_STATUS_NORMAL == lucGWStatus) && 
            (Com_GaaTxGWSignal[LddRouteTxIndex].ucGWCalloutAction == 
            COM_SIG_GW_CALLOUT_ACT_TOUTONLY)))
            {
              if(Com_GaaTxGWSignal[LddRouteTxIndex].ddGWCalloutFunctionPtr != 
              NULL_PTR)
              {
                /* polyspace:begin<RTE : COR : Not a defect : Justify with annotations> Configured function pointer */            
                LblSigCalloutResult = 
                (Com_GaaTxGWSignal[LddRouteTxIndex].ddGWCalloutFunctionPtr)
                (&Com_GaaSignalGWBufferSub[COM_ZERO], lucGWStatus);
                /* polyspace:end<RTE : COR : Not a defect : Justify with annotations> Configured function pointer */
              }
              else
              {
                LblSigCalloutResult = COM_FALSE;
              }
            }
          }
          else
          #endif
          {
            /* in case of callout function is not configured. */
          }

          #if(COM_TX_GW_CALLOUT_SUPPORT == STD_ON)
          if(LblSigCalloutResult == COM_TRUE)
          #endif
          {
            if(LddTxSignalId >= COM_TX_SIGNAL_COUNT)
            {
              #if(COM_TX_SIGGROUP == STD_ON)
              /* Invoke Com_UpdateShadowSignal() function to update the data into
              shadow buffer with signal data */
              #if(COM_TX_GW_CALLOUT_SUPPORT == STD_ON)
              Com_UpdateShadowSignal(LddTxSignalId,
              (P2VAR(void, AUTOMATIC, 
              COM_VAR))&Com_GaaSignalGWBufferSub[COM_ZERO]);
              (void)Com_SendSignalGroup
    		      (Com_GaaTxSigInGrp[LddTxSignalId-COM_TX_SIGNAL_COUNT]
    		      .ddSigGrpIndex);
              #else
              Com_UpdateShadowSignal(LddTxSignalId,
              (P2VAR(void, AUTOMATIC, 
              COM_VAR))&Com_GaaSignalGWBuffer[COM_ZERO]);
              (void)Com_SendSignalGroup
    		      (Com_GaaTxSigInGrp[LddTxSignalId-COM_TX_SIGNAL_COUNT]
    		      .ddSigGrpIndex);
              #endif
              #endif
            }
            else
            {
              #if(COM_TX_GW_CALLOUT_SUPPORT == STD_ON)
              (void)Com_SendSignal(LddTxSignalId, 
              &Com_GaaSignalGWBufferSub[COM_ZERO]);
              #else
              (void)Com_SendSignal(LddTxSignalId, 
              &Com_GaaSignalGWBuffer[COM_ZERO]);
              #endif
            }
          }

          /* Decrement the count of number of signals to be routed */
          LucNoOfRouteSignal--;

      		/* Increase the index of routed tx signal */
      		LddRouteTxIndex++;

        }while(LucNoOfRouteSignal != COM_ZERO);
      } /* Check whether process flag is true */
    }

    LddRxGWSignalIndex++;

    /* Decrement count of number of gateway signals */
    LucNoOfGWSignal--;
  }while(LucNoOfGWSignal != COM_ZERO);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_RxGWSigGrpProcessing                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function processes all signal groups in the    **
**                        I-PDU that are configured for gateway, based on the **
**                        their transfer property.                            **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : LpRxGWIpdu                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaRxGWSigGroup        **
**                                                 Com_GaaRxGWSigInGrp        **
**                                                 Com_GaaRxUnpack            **
**                        Function(s) invoked    : pRdFuncPtr                 **
**                                                 Com_UpdateShadowSignal()   **
**                                                 Com_SendSignalGroup()      **
*******************************************************************************/
#if(COM_RX_SIGGROUP_GW == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_RxGWSigGrpProcessing
           (P2CONST(Com_RxGWIpdu, AUTOMATIC, COM_CONST)LpRxGWIpdu, uint8 
           lucGWStatus)
{
  /* Pointer to Rx GateWay Signal Group structure */
  P2CONST(Com_RxGWSigGroup, AUTOMATIC, COM_CONST) LpRxGWSigGrp;
  /* Pointer to Rx GateWay Signal In Group structure */
  P2CONST(Com_RxGWSigInGrp, AUTOMATIC, COM_CONST) LpRxGWSigInGrp;
  /* Pointer to Rx Unpack structure */
  P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST) LpRxUnpack;

  /* Local variable to store Tx signal ID */
  Com_SignalIdType LddTxSignalId;
  /* buffer Loop Index */  
  PduLengthType LddBufferIndex;
  /* Local variable to store no of GateWay Signal Group */
  uint8 LucNoOfGWSigGroup;
  /* Local variable to store no of Signal In Group */
  uint8 LucNoOfSigInGrp;
  /* Local variable to store no. of Signal Group route */
  uint8 LucNoOfRoute;
  /* Local variable to store no. of Group Signal route */
  uint8 LucNoOfSignalRoute;
  /* Local variable to store Tx Signal Group Index */
  Com_SignalGroupIdType LddTxSigGroupIndex;

  Com_SignalIdType LddRxGWSigInGrpIndex;
  Com_SignalGroupIdType LddRxGWSigGroupIndex;

  /* Local variable to store the tx index */
  Com_SignalIdType LddRouteTxIndex;
  Com_SignalGroupIdType LddRouteSigGroupTxIndex;

  #if(COM_TX_GW_CALLOUT_SUPPORT == STD_ON)
  boolean LblSigCalloutResult;
  uint8 LucCalloutStatusIndex;
  #endif  

  PduLengthType LddSignalMemSize;
	
  /* Local variable to store return value */
  #if(COM_RX_SIGGROUP_UB == STD_ON)
  /* Local variable to store process flag */
  boolean LblProcessFlag;
  #endif
  /* Get the number of Rx gateway signal groups */
  LucNoOfGWSigGroup = LpRxGWIpdu->ucNoOfRxGWSigGroup;
  /* Get the pointer to  Rx gateway signal group structure */
  LddRxGWSigGroupIndex = LpRxGWIpdu->ddGWRxSigGrpIndex;
  /* Loop for all signal groups that are configured for gateway */
  /* Because this function is invoke, when SignalGroup number is over one.
  So, LucNoOfGWSigGroup variable is always over one. 
  And, it's fine to use "do-while" operation */
  do
  {

    /* Get the pointer to n  Rx gateway signal group structure */
    LpRxGWSigGrp = &Com_GaaRxGWSigGroup[LddRxGWSigGroupIndex];
    
    if((lucGWStatus == COM_SIG_GW_STATUS_TOUT) && 
      (LpRxGWSigGrp->blDMTrigger == COM_FALSE))
    {
      /* Do nothing */
    }
    else
    {
      #if(COM_RX_SIGGROUP_UB == STD_ON)
      /* Set the process flag to true */
      LblProcessFlag = COM_TRUE;
      /* Check whether update bit is configured for signal group */
      if((LpRxGWSigGrp->ucRxUbitMask) != COM_ZERO)
      {
        /* Check whether signal group is received with an update bit */
        if((*(LpRxGWSigGrp->pRxUBit) & (LpRxGWSigGrp->ucRxUbitMask)) ==
                                                                        COM_FALSE)
        {
          /* Set the process flag to false */
          LblProcessFlag = COM_ZERO;
        }
      }
      #endif
      #if(COM_RX_SIGGROUP_UB == STD_ON)
      /* Check whether process flag is true */
      if(COM_TRUE == LblProcessFlag)
      #endif
      {
        #if(COM_TX_GW_CALLOUT_SUPPORT == STD_ON)
        for(LucCalloutStatusIndex = COM_ZERO; LucCalloutStatusIndex < 
        (uint8)COM_RX_SIG_GRP_GW_MAX; LucCalloutStatusIndex++)
        {
          Com_GaaSigGrpGWStatus[LucCalloutStatusIndex] = COM_INVALID_NONE;
        }
        LddRouteSigGroupTxIndex = LpRxGWSigGrp->ddTxSigGrpIndex;
        LucNoOfRoute =  LpRxGWSigGrp->ucNoOfRouteSigGroup;
        do
        {        
          LblSigCalloutResult = COM_TRUE;
          if(Com_GaaTxGWSignal[LddRouteSigGroupTxIndex].ucGWCalloutAction != 
          COM_SIG_GW_CALLOUT_ACT_NONE)
          {
            if(!((COM_SIG_GW_STATUS_NORMAL == lucGWStatus) && 
            (Com_GaaTxGWSignal[LddRouteSigGroupTxIndex].ucGWCalloutAction == 
            COM_SIG_GW_CALLOUT_ACT_TOUTONLY)))
            {   
              if(Com_GaaTxGWSignal[LddRouteSigGroupTxIndex].ddGWCalloutFunctionPtr 
              != NULL_PTR)
              {
                /* polyspace:begin<RTE : COR : Not a defect : Justify with annotations> Configured function pointer */ 
                LblSigCalloutResult = 
                (Com_GaaTxGWSignal[LddRouteSigGroupTxIndex].ddGWCalloutFunctionPtr)
                (NULL_PTR, lucGWStatus);
                /* polyspace:end<RTE : COR : Not a defect : Justify with annotations> Configured function pointer */               
              }
              else
              {
                LblSigCalloutResult = COM_FALSE;
              }
            }
          }   
          Com_GaaSigGrpGWStatus[LucNoOfRoute-COM_ONE] = (uint8)LblSigCalloutResult;
          LucNoOfRoute--;
          LddRouteSigGroupTxIndex++;
        }while(LucNoOfRoute != COM_ZERO);
        #endif
        
        /* Get the pointer to  Rx gateway signal group */
        LddRxGWSigInGrpIndex = LpRxGWSigGrp->ddRxSigInGrpIndex;
        LpRxGWSigInGrp =
                 &Com_GaaRxGWSigInGrp[LddRxGWSigInGrpIndex];
        /* Get the number of signals in signal group */
        LucNoOfSigInGrp = LpRxGWSigGrp->ucNoOfSigInGrp;
        /* Loop for number of signals in signal group */
        do
        {
          LpRxUnpack = &(Com_GaaRxUnpack[LpRxGWSigInGrp->ddRxUnpackIndex]);
          
          if(LpRxUnpack->ucSignalType < COM_FOUR)
          {
            LddSignalMemSize = (PduLengthType)Com_GaaSigMemSize[LpRxUnpack->ucSignalType];
          }
          else
          {
            LddSignalMemSize = LpRxUnpack->ddSignalSize;
          }          
          
          for(LddBufferIndex = (PduLengthType)COM_ZERO; LddBufferIndex < 
          LddSignalMemSize; LddBufferIndex++)
          {
            Com_GaaSignalGWBuffer[LddBufferIndex] = COM_ZERO;
          }        

          
          /* Invoke read function to unpack the signal from an I-PDU */
          (void)Com_UnPackRequestRead(LpRxUnpack,
              (P2VAR(void, AUTOMATIC, COM_VAR))&Com_GaaSignalGWBuffer[COM_ZERO]);
          /* Get the number of signals in signal group to be routed */
          LucNoOfSignalRoute = LpRxGWSigInGrp->ucNoOfRouteSigInGrp;
          /* Get the index to signal in  Rx gateway signal group
          structure */
          LddRouteTxIndex = LpRxGWSigInGrp->ddTxSigIndex;
          /* Loop for number of signals to be routed */
          do
          {
            #if(COM_TX_SIGGROUP == STD_ON)

            #if(COM_TX_GW_CALLOUT_SUPPORT == STD_ON)
            if(Com_GaaSigGrpGWStatus[LucNoOfSignalRoute-COM_ONE] == (uint8)COM_TRUE)            
            #endif
            {          
              LddTxSignalId = 
              (Com_SignalIdType)Com_GaaTxGWSignal[LddRouteTxIndex].ddGWTxSigIndex;
              /* Invoke Com_UpdateShadowSignal() function to update the data into
                 shadow buffer with signal data */
              Com_UpdateShadowSignal(LddTxSignalId,
                (P2VAR(void, AUTOMATIC, COM_VAR))&Com_GaaSignalGWBuffer[COM_ZERO]);
            }
            #endif
  		  
            /* Increase the index of routed tx signal */
            LddRouteTxIndex++;
  		  
            /* Decrement the count of number of signals to be routed */
            LucNoOfSignalRoute--;

          }while(LucNoOfSignalRoute != COM_ZERO);

          /* Get the pointer to n  Rx gateway signal in group
          structure */
          LddRxGWSigInGrpIndex++;
          LpRxGWSigInGrp =
                 &Com_GaaRxGWSigInGrp[LddRxGWSigInGrpIndex];
          /* Decrement the number of signal in group count */
          LucNoOfSigInGrp--;
        }while(LucNoOfSigInGrp != COM_ZERO);


        
        /* Get the number of  Rx gateway signal groups to be routed */
        LucNoOfRoute =  LpRxGWSigGrp->ucNoOfRouteSigGroup;
        /* Get the index of Tx SignalGroup handleID structure */
        LddRouteSigGroupTxIndex = LpRxGWSigGrp->ddTxSigGrpIndex;


  	  
        /* Loop for number of signal groups count */
        do
        {
          #if(COM_TX_GW_CALLOUT_SUPPORT == STD_ON)
          if(Com_GaaSigGrpGWStatus[LucNoOfRoute-COM_ONE] == (uint8)COM_TRUE)
          #endif  
          {
            LddTxSigGroupIndex 
              = (Com_SignalGroupIdType)Com_GaaTxGWSignal[LddRouteSigGroupTxIndex]
              .ddGWTxSigIndex;
            (void)Com_SendSignalGroup(LddTxSigGroupIndex);
          }


          /* Increase the index of routed tx signal */
          LddRouteSigGroupTxIndex++;
          /* Decrement the count of the number of  Rx gateway signal group
          to be routed */
          LucNoOfRoute--;
        }while(LucNoOfRoute != COM_ZERO);
      } /* Check whether process flag is true */
    }

    LddRxGWSigGroupIndex++;

    /* Decrement the count of the number of gateway signal groups */
    LucNoOfGWSigGroup--;
  }while(LucNoOfGWSigGroup != COM_ZERO);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_SwitchIpduTxMode                                **
**                                                                            **
** Service ID           : 0x27                                                **
**                                                                            **
** Description          : The service Com_SwitchIpduTxMode sets the           **
**                        transmission mode of the I-PDU referenced by PduId  **
**                        to Mode. In case the transmission mode changes, the **
**                        new mode shall immediately be effective. In case the**
**                        requested transmission mode was already active for  **
**                        this I-PDU, the call will have no effect.           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : PduId, Mode                                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : It shall only be used from within I-PDU callout.    **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaTxIpdu              **
**                                                 Com_GaaTxIpduStatusBit     **
**                                                 Com_GaaTxMode              **
**                                                 Com_GaaTxReptCount         **
**                                                 Com_GaaTxMDTimer           **
**                        Function(s) invoked    : Det_ReportError()          **
**                                                 Com_Transmit()             **
**                                                 SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
*******************************************************************************/
#if(COM_TX_IPDU == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_SwitchIpduTxMode(PduIdType PduId,
  boolean Mode)
{
  /* Pointer to Tx mode structure */
  P2CONST(Com_TxMode, AUTOMATIC, COM_CONST) LpTxMode;
  /* Pointer to Tx Ipdu structure */
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Local variable to store return value */
  uint8 LucReturnValue;
  #endif
  #if(COM_TX_IPDU_MINDELAY_ENABLED == STD_ON)
  /* Local variable to store Ipdu config */
  uint8 LucIpduConfig;
  #endif
  /* Flag to check if transmission is needed or not */
  boolean LblTransmitFlag;
  /* Local status of the Ipdu */
  uint16 LusTxIpduStatusBit;
  LblTransmitFlag = COM_FALSE;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Initialize error flag to false */
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_SWITCHIPDUTXMODE);
  /* Check whether I-PDU group ID is out of range */
  COM_DET_TXPDUID_RANGE_CHECK_FLAG(PduId, COMSERVICEID_SWITCHIPDUTXMODE);
  if(LucReturnValue == (uint8)E_OK)
  #endif
  {
    LpTxIpdu = &Com_GaaTxIpdu[PduId];
    /* Get the status in a local variable */
    LusTxIpduStatusBit = Com_GaaTxIpduStatusBit[PduId];
    /* Get a pointer to TRUE mode */
    LpTxMode = &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex];
    #if(COM_TX_IPDU_MINDELAY_ENABLED == STD_ON)
    /* Get the Ipdu configuration */
    LucIpduConfig = LpTxIpdu->ucTxConfig;
    #endif
    /* If the Tx Ipdu has been started */
    if((LusTxIpduStatusBit & COM_TX_REQ_STATUS_MASK) != COM_FALSE)
    {
      /* Check if the status are different */
      if((Com_GaaTxIpduStatusBit[PduId] & COM_TX_TMS_STATUS_MASK) != Mode)
      {
        /* The mode is changing, so reset pending flag for MDT */
        #if(COM_TX_IPDU_MINDELAY_ENABLED == STD_ON)
        /* Check whether minimum delay timer is configured */
        if((LucIpduConfig & COM_TX_IPDU_MDT_CONFIG_MASK) != COM_ZERO)
        {
          /* Clear Tx Pending Status Mask */
          LusTxIpduStatusBit &= (uint16)(~(COM_TX_PENDING_STATUS_MASK));
        }
        #endif
        /* If mode is False */
        if(COM_FALSE == Mode)
        {
          /* Set the status flag to indicate that TMS has evaluated to false */
          LusTxIpduStatusBit &= (uint16)(~(COM_TX_TMS_STATUS_MASK));
          /* Get the pointer to false Tx mode */
          LpTxMode = 
          &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex+(PduIdType)COM_ONE];
        }/* If mode is False */
        /* Resetting timers if the mode is PERIODIC or MIXED (COM244)*/
        if((LpTxMode->ucTxMode <= COM_TX_MIXEDNTIMES_MODE)  &&
             (LpTxMode->ucTxMode != COM_TX_NONE_MODE))
        {
          /* Set status bit to reset periodic timer */
          /* Timer will then be reset in main function */
          LusTxIpduStatusBit |= COM_TX_PT_STATUS_MASK;
        }
        /* Check if the mode is MIXED or DIRECT */
        if(LpTxMode->ucTxMode > COM_TX_PERIODIC_MODE)
        {
          LblTransmitFlag = COM_TRUE;
          #if(COM_TX_IPDU_REPETITION == STD_ON)
          /* Check whether repetition counter is not zero */
          /* Prepare for  n-times Tx */
          if(((LpTxMode->ucTxMode) >= COM_TX_MIXEDNTIMES_MODE) &&
            ((LpTxMode->ucTxMode) != COM_TX_DIRECT_MODE))
          {
            LusTxIpduStatusBit |= COM_TX_REPT_STATUS_MASK;
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
          }
          #endif
          #if(COM_TX_IPDU_MINDELAY_ENABLED == STD_ON)
          /* Check whether minimum delay timer is configured for I-PDU */
          if((LucIpduConfig & COM_TX_IPDU_MDT_CONFIG_MASK) != COM_FALSE)
          {
            /* Check whether minimum delay timer is set to zero */
            if(Com_GaaTxMDTimer[LpTxIpdu->ddTxMDTimerIndex] != (uint16)COM_ZERO)
            {
              LusTxIpduStatusBit |= COM_TX_PENDING_STATUS_MASK;
              LblTransmitFlag = COM_FALSE;
              #if (COM_TX_IPDU_DM == STD_ON)
              if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_DM_CONFIG_MASK) != 
              COM_FALSE)
              {
                LusTxIpduStatusBit |= COM_TX_DM_STATUS_MASK;
              }
              #endif
            }
          } /* Check whether minimum delay timer is configured for I-PDU */
          #endif
        } /* Check if the mode is MIXED or DIRECT */
        if(COM_TRUE == LblTransmitFlag)
        {
          (void)Com_Transmit((PduIdType)PduId);
        }
        SchM_Enter_Com_TX_IPDU_STATUS_PROTECTION_AREA();
        Com_GaaTxIpduStatusBit[PduId] = LusTxIpduStatusBit;
        SchM_Exit_Com_TX_IPDU_STATUS_PROTECTION_AREA();
      }/* Check if the status are different */
    }/* If the Tx Ipdu has been started */
  }
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_RxSigNotifyOrReplace                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function added for cyclomatic complexity reduction. **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpRxDm                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaSigReplace          **
**                                                 Com_GaaInvNotifCbk         **
**                                                 Com_GaaSigErrorCbk         **
**                                                 Com_GaaTxPack              **
**                        Function(s) invoked    : pWrFuncPtr                 **
**                                                 pSigErrorCbk               **
*******************************************************************************/
#if((COM_RX_IPDU_DM == STD_ON) || \
   (COM_RX_SIGNAL_UBDM == STD_ON) || \
   (COM_RX_SIGGROUP_UBDM == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_RxSigNotifyOrReplace(
                         P2CONST(Com_RxDm, AUTOMATIC, COM_CONST) LpRxDm)
{
  #if(COM_SIG_ERR_CBK_NOTIFY == STD_ON)
  /* Pointer to notification error call-back structure */
  P2CONST(Com_SigErrorCbk, AUTOMATIC, COM_CONST) LpSigErrorCbk;
  Com_ErrCbkCountType LddSigErrorCbkIndex;
  #endif  
  #if((COM_RX_SIGNAL_REPLACE == STD_ON) || \
     (COM_RX_SIGGROUP_REPLACE == STD_ON) || \
     (COM_RX_SIGNAL_UBDMREPLACE == STD_ON) || \
     (COM_RX_SIGGROUP_UBDMREPLACE == STD_ON))
  /* #7744 start */
  /* Pointer to structure */
  P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpPackTimeout;
  uint8 LucSigReplaceIndex;  
  #endif  
  #if((COM_RX_SIGNAL_REPLACE == STD_ON) || \
     (COM_RX_SIGNAL_UBDMREPLACE == STD_ON))
  /* Pointer to signal replace structure */
  P2CONST(Com_SigReplace, AUTOMATIC, COM_CONST) LpSigReplace;       
  #endif

  #if((COM_RX_SIGGROUP_REPLACE == STD_ON) || \
     (COM_RX_SIGGROUP_UBDMREPLACE == STD_ON))
  /* Pointer to signal group replace structure */
  P2CONST(Com_SigGrpReplace, AUTOMATIC, COM_CONST) LpSigGrpReplace;       
  /* Pointer to Rx Signal Group structure */
  P2CONST(Com_RxSigGroup, AUTOMATIC, COM_CONST) LpRxSigGroup;  
  #endif

  
    /* Local variable to store signal count */
  #if((COM_RX_SIGNAL_REPLACE == STD_ON) || \
       (COM_RX_SIGGROUP_REPLACE == STD_ON) || \
       (COM_RX_SIGNAL_UBDMREPLACE == STD_ON) || \
       (COM_RX_SIGGROUP_UBDMREPLACE == STD_ON) || \
       (COM_SIG_ERR_CBK_NOTIFY == STD_ON))
  uint8 LucNoOfSigCount;
  #endif  
  #if((COM_RX_SIGNAL_REPLACE == STD_ON) || \
     (COM_RX_SIGNAL_UBDMREPLACE == STD_ON))
  LucNoOfSigCount = LpRxDm->ucNoOfSigReplace;
  /* Check whether any replacement is configured */
  if(LucNoOfSigCount != COM_ZERO)
  {
    /* Get the pointer to LpSigReplace structure */
    LucSigReplaceIndex = LpRxDm->ucSigReplaceIndex;
    LpSigReplace = &Com_GaaSigReplace[LucSigReplaceIndex];
    do
    {
      LpPackTimeout = &Com_GaaTxPack[LpSigReplace->ddTxPackIndex];
      /* Invoke write function to pack the initial value into
         I-PDU/signal buffer */
      (void)Com_PackRequestWrite(LpPackTimeout, LpSigReplace->pInitValue);
      
      /* Increment the index */
      LucSigReplaceIndex++;
      LpSigReplace = &Com_GaaSigReplace[LucSigReplaceIndex];
      /* Decrement the signal count*/
      LucNoOfSigCount--;
    }while(LucNoOfSigCount != COM_ZERO);
  }
  #endif

  #if((COM_RX_SIGGROUP_REPLACE == STD_ON) || \
     (COM_RX_SIGGROUP_UBDMREPLACE == STD_ON))
  LucNoOfSigCount = LpRxDm->ucNoOfSigGrpReplace;
  /* Check whether any replacement is configured */
  if(LucNoOfSigCount != COM_ZERO)
  {
    /* Get the pointer to LpSigReplace structure */
    LucSigReplaceIndex = LpRxDm->ucSigGrpReplaceIndex;
    LpSigGrpReplace = &Com_GaaSigGrpReplace[LucSigReplaceIndex];
    do
    {
      LpPackTimeout = &Com_GaaTxPack[LpSigGrpReplace->ddTxPackIndex];
      LpRxSigGroup = &Com_GaaRxSigGroup[LpSigGrpReplace->ddSigGrpIndex];
      /* Invoke write function to pack the initial value into
         I-PDU/signal buffer */
      (void)Com_PackSigGrp(LpPackTimeout, LpSigGrpReplace->pInitValue, LpPackTimeout->pWrBuffer, LpRxSigGroup->pMaskingBuffer);
      
      /* Increment the index */
      LucSigReplaceIndex++;
      LpSigGrpReplace = &Com_GaaSigGrpReplace[LucSigReplaceIndex];
      /* Decrement the signal count*/
      LucNoOfSigCount--;
    }while(LucNoOfSigCount != COM_ZERO);
  }  
  #endif
  /* #7744 end */
  #if(COM_SIG_ERR_CBK_NOTIFY == STD_ON)
  /* Get the number of signals configured for error notification
  call-back */
  LucNoOfSigCount = LpRxDm->ucNoOfSigCallback;
  /* Check whether signal is configured for error notification
                                                         call-back */
  if(LucNoOfSigCount != COM_ZERO)
  {
    /* Get the pointer to SigErrorCbk structure */
    LddSigErrorCbkIndex = LpRxDm->ddSigErrCbkIndex;
    LpSigErrorCbk = &Com_GaaSigErrorCbk[LddSigErrorCbkIndex];
    /* Loop for all the signals configured for error notification
    (timeout) */
    do
    {
      /* Invoke the error notification call-back function with
                                       COM_TIMEOUT as a parameter */
      (LpSigErrorCbk->pSigErrorCbk)();

      /* Get the pointer to n SigErrorCbk structure */
      LddSigErrorCbkIndex++;
      LpSigErrorCbk = &Com_GaaSigErrorCbk[LddSigErrorCbkIndex];
      /* Decrement the count of the number of signals configured for
                                    error notification call-back */
      LucNoOfSigCount--;
    }while(LucNoOfSigCount != COM_ZERO);
  } /* Check whether signal is configured for error notification */
  #endif /*#if(COM_SIG_ERR_CBK_NOTIFY == STD_ON) */
} 
#define COM_STOP_SEC_CODE
#include "MemMap.h" 
#endif
/*******************************************************************************
** Function Name        : Com_RxSigDMFilterReset                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function added for cyclomatic complexity reduction. **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpRxDm                                              **
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
**                                                 Com_GaaRxSignal            **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
/* Reset the previous value in MASKED_NEW_DIFFERS_MASKED_OLD filter, 
when Rx Timeout is occurred - Fixed by AUTRON START*/
#if((COM_RX_IPDU_DM == STD_ON) && (COM_RX_SIGNAL_FILTER == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_RxSigDMFilterReset(
                         P2CONST(Com_RxDm, AUTOMATIC, COM_CONST) LpRxDm)
{
  /* Local variable to store signal configuration */
  uint8 LucSigConfig;
  uint8 LucNoOfSignal;
  /* Pointer to Rx I-Pdu structure */
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu;
  /* Pointer to Rx Signal structure */
  P2CONST(Com_RxSignal, AUTOMATIC, COM_CONST) LpRxSignal;

  Com_SignalIdType LddRxSignalIndex;

  if(LpRxDm != NULL_PTR)
  {
    LpRxIpdu = &Com_GaaRxIpdu[LpRxDm->ddRxpduId];

    /* Get the number of  Rx signals */
    LucNoOfSignal = LpRxIpdu->ucNoOfRxSignal;
    /* Internal Redmine #696 */
    if(LucNoOfSignal != COM_ZERO)
    {
      /* Get the pointer to  Rx signal structure */
      LddRxSignalIndex = LpRxIpdu->ddRxSigIndex;
      LpRxSignal = &Com_GaaRxSignal[LddRxSignalIndex];
      /* Loop for number of  Rx signals */
      do
      {
        LucSigConfig = LpRxSignal->ucRxSigConfig;
        if((LucSigConfig & COM_RX_SIGNAL_FILTER_CONFIG_MASK) != COM_FALSE)
        {
          (((P2CONST(Com_FilterNever, AUTOMATIC, COM_CONST))
            (LpRxSignal->pFilter))->pFilterFuncPtr)
            (LpRxSignal->pFilter, NULL_PTR, COM_INVALID_PARAM);
        }

        /* Decrement the count of number of signals */
        LucNoOfSignal--;

        /* Get the pointer to n Rx signal structure */
        LddRxSignalIndex++;
        LpRxSignal = &Com_GaaRxSignal[LddRxSignalIndex];
      }while(LucNoOfSignal != COM_ZERO);
    }
  }
} 
#define COM_STOP_SEC_CODE
#include "MemMap.h" 
#endif
/* Reset the previous value in MASKED_NEW_DIFFERS_MASKED_OLD filter, 
when Rx Timeout is occurred - Fixed by AUTRON END*/


/*******************************************************************************
** Function Name        : Com_RxIpduCallout                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function added for cyclomatic complexity reduction. **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : PduInfoPtr, PduId                                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Com_GaaRxIpdu                 **
**                                              Com_GaaRxIpduCallOut          **
**                        Function(s) invoked : pIpduCallout                  **
*******************************************************************************/
#if(COM_RX_IPDU_CALLOUT == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
boolean Com_RxIpduCallout(PduIdType PduId, 
P2CONST(PduInfoType, AUTOMATIC, COM_CONST)PduInfoPtr)
{
  boolean LblCalloutFlag;
  /* Pointer to Rx Ipdu structure */
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu;
  
  LblCalloutFlag = COM_TRUE;
  LpRxIpdu = &Com_GaaRxIpdu[PduId];
  
  /* Check the function pointer is vaild before invoke the function 
  - Fixed by AUTRON START*/
  if(Com_GaaRxIpduCallOut[LpRxIpdu->ddIpduCalloutIndex].pIpduCallout 
  != NULL_PTR)  
  {
    /* Callout function input value is changed in 4.1.1 com specification 
    - Fixed by AUTRON START*/            
    /* Invoke I-PDU callout function to upper layer */
    LblCalloutFlag = (Com_GaaRxIpduCallOut[LpRxIpdu->ddIpduCalloutIndex].
    pIpduCallout)(PduId, PduInfoPtr);
    /* Callout function input value is changed in 4.1.1 com specification 
    - Fixed by AUTRON END*/      		  
  }
  /* Check the function pointer is vaild before invoke the function 
  - Fixed by AUTRON END*/	  
  return(LblCalloutFlag);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_TxIpduCallout                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function added for cyclomatic complexity reduction. **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : PduInfoPtr, PduId                                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Com_GaaTxIpdu                 **
**                                              Com_GaaTxIpduCallOut          **
**                        Function(s) invoked : pIpduCallout                  **
*******************************************************************************/
#if(COM_TX_IPDU_CALLOUT == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
boolean Com_TxIpduCallout(PduIdType PduId, 
P2VAR(PduInfoType, AUTOMATIC, COM_VAR)PduInfoPtr)
{
  boolean LblCalloutFlag;
  /* Pointer to Rx Ipdu structure */
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu;
  
  LblCalloutFlag = COM_TRUE;
  LpTxIpdu = &Com_GaaTxIpdu[PduId];  

  /* Check the function pointer is vaild before invoke the function 
  - Fixed by AUTRON START*/
  if(Com_GaaTxIpduCallOut[LpTxIpdu->ddIpduCalloutIndex].pIpduCallout 
  != NULL_PTR)  
  {
    /* Callout function input value is changed in 4.1.1 com specification 
    - Fixed by AUTRON START*/            
    /* Invoke I-PDU callout function to upper layer */
    LblCalloutFlag = (Com_GaaTxIpduCallOut[LpTxIpdu->ddIpduCalloutIndex].
    pIpduCallout)(PduId, PduInfoPtr);
    /* Callout function input value is changed in 4.1.1 com specification 
    - Fixed by AUTRON END*/           
  }
  /* Check the function pointer is vaild before invoke the function 
  - Fixed by AUTRON END*/   
  return(LblCalloutFlag);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif


/*******************************************************************************
** Function Name        : Com_TxIpduTriggerCallout                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function added for cyclomatic complexity reduction. **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : PduInfoPtr, PduId                                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Com_GaaTxIpdu                 **
**                                              Com_GaaTxIpduCallOut          **
**                        Function(s) invoked : pIpduCallout                  **
*******************************************************************************/
#if(COM_TX_IPDU_TRIGGERCALLOUT == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
boolean Com_TxIpduTriggerCallout(PduIdType PduId, 
P2VAR(PduInfoType, AUTOMATIC, COM_VAR)PduInfoPtr)
{
  boolean LblCalloutFlag;
  /* Pointer to Rx Ipdu structure */
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu;
  
  LblCalloutFlag = COM_TRUE;
  LpTxIpdu = &Com_GaaTxIpdu[PduId];
  
  /* Check the function pointer is vaild before invoke the function 
  - Fixed by AUTRON START*/
  if(Com_GaaTxIpduCallOut[LpTxIpdu->ddIpduTriggerCalloutIndex].pIpduCallout 
  != NULL_PTR)  
  {
    /* Callout function input value is changed in 4.1.1 com specification 
    - Fixed by AUTRON START*/            
    /* Invoke I-PDU callout function to upper layer */
    LblCalloutFlag = (Com_GaaTxIpduCallOut
    [LpTxIpdu->ddIpduTriggerCalloutIndex].pIpduCallout)(PduId, PduInfoPtr);
    /* Callout function input value is changed in 4.1.1 com specification 
    - Fixed by AUTRON END*/           
  }
  /* Check the function pointer is vaild before invoke the function 
  - Fixed by AUTRON END*/   
  return(LblCalloutFlag);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif




/*******************************************************************************
** Function Name        : Com_PackRequestWrite                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function invoke the configured packing         **
**                        function.                                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same data.                    **
**                        Reentrant for different data.                       **
**                                                                            **
** Input Parameters     : LpTxPack, LpDataPtr                                 **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaSigWrFuncPtr        **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_PackRequestWrite
  (P2CONST(Com_TxPack, AUTOMATIC, COM_CONST) LpTxPack,
  P2CONST (void, AUTOMATIC, COM_CONST) LpDataPtr)
{
  #if(COM_SIG_WR_FUNC_COUNT > COM_MACRO_ZERO)
  /* Invoke write function to pack data to buffer */
  (Com_GaaSigWrFuncPtr[LpTxPack->ucWrFuncIndex].pWrFuncPtr)(LpTxPack,
  (P2CONST(void, AUTOMATIC, COM_CONST))LpDataPtr);
  #endif
}

#define COM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Com_UnPackRequestRead                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function invokes the configured unpacking      **
**                        function.                                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant for the same data.                    **
**                        Reentrant for different data.                       **
**                                                                            **
** Input Parameters     : LpRxUnpack, LpDataPtr                               **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaSigRdFuncPtr        **
**                        Function(s) invoked    : None                       **
*******************************************************************************/

#define COM_START_SEC_CODE
#include "MemMap.h"
/* polyspace:begin<MISRA-C:16.7:Not a defect:Justify with annotations> No Impact of this rule violation */
FUNC(void, COM_CODE) Com_UnPackRequestRead
  (P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST) LpRxUnpack,         
  P2VAR(void, AUTOMATIC, COM_VAR)LpDataPtr)
{
  #if(COM_SIG_RD_FUNC_COUNT > COM_MACRO_ZERO)  
  /* Invoke read function to unpack data from buffer */
  (Com_GaaSigRdFuncPtr[LpRxUnpack->ucRdFuncIndex].pRdFuncPtr)
                                 (LpRxUnpack, LpDataPtr);  
  #endif
}
/* polyspace:end<MISRA-C:16.7:Not a defect:Justify with annotations> No Impact of this rule violation */

#define COM_STOP_SEC_CODE
#include "MemMap.h"
/* polyspace:end<MISRA-C:8.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #7283) */
/* polyspace:end<RTE: NIV : Not a defect : No Action Planned > initialized variable */
/* polyspace:end<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : No Action Planned > configured memory access index */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
