/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Com_IpduGrp.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Com Module                                            **
**                                                                            **
**  PURPOSE   : Provision of start/stop of I-PDU group & deadline monitoring  **
**              system.                                                       **
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
** 2.2.0     16-Apr-2017   Chan Kim    Internal Redmine #7861, #7525, #9740   **
** 2.1.9     20-Mar-2017   Chan Kim    Internal Redmine #7851                 **
** 2.1.7     30-Nov-2016   Chan Kim    Internal Redmine #6807                 **
** 2.1.5     07-Oct-2016   Chan Kim    Internal Redmine #5874, #5909          **
** 2.1.4     19-Aug-2016   Chan Kim    Internal Redmine #5687, #5813          **
** 2.1.3     12-Jul-2016   Chan Kim    Internal Redmine #5479, #5550          **
** 2.1.1     20-Jun-2016   Chan Kim    Internal Redmine #5265                 **
** 2.1.0     25-May-2016   Chan Kim    Internal Redmine #4998                 **
** 2.0.13    13-May-2016   Chan Kim    Internal Redmine #4908                 **
** 2.0.10    25-Feb-2016   Chan Kim    Internal Redmine #4250                 **
** 2.0.8     12-Feb-2016   Chan Kim    Internal Redmine #4158                 **
** 2.0.3     24-Nov-2015   Chan Kim    Internal Redmine #3544, #3535          **
** 2.0.2     18-Sep-2015   Chan Kim    Internal Redmine #3178                 **
** 1.0.16    27-Feb-2015   Chan Kim    Internal Redmine #2202                 **
** 1.0.14    03-Nov-2014   Chan Kim    Internal Redmine #1463, #1204, #1632   **
** 1.0.12    26-May-2014   Chan Kim    Internal Redmine #883                  **
** 1.0.11    20-Mar-2014   Chan Kim    Internal Redmine #729                  **
** 1.0.9     11-Feb-2014   Chan Kim    Internal Redmine #605                  **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Com.h"          /* Com header file */
#include "Com_Main.h"     /* Com Main header file */
#include "Com_Error.h"    /* Com Error header file */
#include "Com_IpduGrp.h"  /* Com Ipdu Group header file */
#include "SchM_Com.h"     /* SchM Com header file */
#if(COM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"          /* Det header file */
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COM_IPDUGRP_C_AR_RELEASE_MAJOR_VERSION  4
#define COM_IPDUGRP_C_AR_RELEASE_MINOR_VERSION   0
#define COM_IPDUGRP_C_AR_RELEASE_REVISION_VERSION  3

/* Software Version Information */
#define COM_IPDUGRP_C_SW_MAJOR_VERSION  2
#define COM_IPDUGRP_C_SW_MINOR_VERSION  2

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if(COM_AR_RELEASE_MAJOR_VERSION != COM_IPDUGRP_C_AR_RELEASE_MAJOR_VERSION)
  #error "Com_IpduGrp.c : Mismatch in Com Specification Major Version"
#endif

#if(COM_AR_RELEASE_MINOR_VERSION != COM_IPDUGRP_C_AR_RELEASE_MINOR_VERSION)
  #error "Com_IpduGrp.c : Mismatch in Com Specification Minor Version"
#endif

#if(COM_AR_RELEASE_REVISION_VERSION != \
  COM_IPDUGRP_C_AR_RELEASE_REVISION_VERSION)
  #error "Com_IpduGrp.c : Mismatch in Com Specification Revision Version"
#endif

#if(COM_SW_MAJOR_VERSION != COM_IPDUGRP_C_SW_MAJOR_VERSION)
  #error "Com_IpduGrp.c : Mismatch in Com Software Major Version"
#endif

#if(COM_SW_MINOR_VERSION != COM_IPDUGRP_C_SW_MINOR_VERSION)
  #error "Com_IpduGrp.c : Mismatch in Com Software Minor Version"
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

/*******************************************************************************
** Function Name        : Com_StartIpduGroup                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function starts a pre-configured I-PDU group.  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different I-PDU groups.               **
**                        Non-Reentrant for same I-PDU group.                 **
**                                                                            **
** Input Parameters     : IpduGroupId, Initialize                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaIpduGroup           **
**                                                 Com_GaaIpduGrpEnStatus     **
**                                                 Com_GaaIpduGrpDmStatus     **
**                                                 Com_GaaTxIpduGroup         **
**                                                 Com_GaaTxIpduStatus        **
**                                                 Com_GaaTxIpduStatusBit     **
**                                                 Com_GaaRxIpduGroup         **
**                                                 Com_GaaRxIpduStatus        **
**                        Function(s) invoked    : SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_StartIpduGroup(Com_IpduGroupIdType IpduGroupId,
  boolean Initialize)
{
  /* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Code structure for optimal performance */  
  /* Pointer to Ipdu group structure */
  P2CONST(Com_IpduGroup, AUTOMATIC, COM_CONST) LpIpduGroup;
  PduIdType LddPduIndex;
  PduIdType LddIpduHandleId;
  /* Local variable to store no. Of Ipdus */
  PduIdType LddNoOfIpdus;

  /* Pointer to Tx Ipdu */
  #if((COM_TX_IPDU_TMS == STD_ON) || (COM_TX_IPDU_PT == STD_ON) \
  || (COM_TX_IPDU_DM == STD_ON) || (COM_TX_TP_SUPPORT == STD_ON) \
  || (COM_TX_IPDU_REPETITION == STD_ON) || (COM_TX_IPDU_COUNTER_ENABLED == STD_ON) \
  || (COM_TX_SIGNAL_UB == STD_ON) || (COM_TX_SIGGROUP_UB == STD_ON) || (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON))
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu; 
  #endif
  #if(COM_TX_TP_SUPPORT == STD_ON)    
  /* Pointer to TP Ipdu structure */
  P2CONST(Com_TxTPIpdu, AUTOMATIC, COM_CONST) LpTxTPIpdu;
  #endif
  #if(COM_RX_TP_SUPPORT == STD_ON)  
  /* Pointer to TP Ipdu structure */
  P2CONST(Com_RxTPIpdu, AUTOMATIC, COM_CONST) LpRxTPIpdu;
  #endif  
  Com_IpduGroupIdType LddIpduGroupId;

  #if(COM_TX_IPDU_DM == STD_ON)  
  P2CONST(Com_TxMode, AUTOMATIC, COM_CONST) LpTxModeTrue;
  #if(COM_TX_IPDU_TMS == STD_ON)
  P2CONST(Com_TxMode, AUTOMATIC, COM_CONST) LpTxModeFalse;
  #endif
  #endif

  #if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON)
  P2CONST(Com_TxIpduCounter, AUTOMATIC, COM_CONST) LpTxIpduCounter;
  #endif

  #if((COM_TX_IPDU_TMS == STD_ON)||(COM_TX_IPDU_PT == STD_ON) \
  ||(COM_TX_IPDU_DM == STD_ON))
  /* Pointer to Tx mode structure */
  P2CONST(Com_TxMode, AUTOMATIC, COM_CONST) LpTxMode;
  #endif   

  #if(COM_TX_IPDU_TMS == STD_ON)
  P2CONST(Com_TxIpduModeSel, AUTOMATIC, COM_CONST) LpTxModeSelect;
  P2CONST(uint8, AUTOMATIC, COM_CONST) LpFilterStatus;
  uint8 LucFilterStatusIndex;
  boolean LblFilterResult;  
  #endif          

  #if(COM_RX_IPDU_COUNTER_ENABLED == STD_ON)
  P2CONST(Com_RxIpduCounter, AUTOMATIC, COM_CONST) LpRxIpduCounter;
  #endif
  #if(COM_RX_REPLICATION == STD_ON)
  P2CONST(Com_RxIpduReplication, AUTOMATIC, COM_CONST)LpRxIpduRepli;
  #endif  

  #if((COM_RX_IPDU_DM == STD_ON) || \
    (COM_RX_SIGNAL_UBDM == STD_ON) || \
    (COM_RX_SIGGROUP_UBDM == STD_ON))
  P2CONST(Com_RxDm, AUTOMATIC, COM_CONST) LpRxDm;
  PduIdType LddRxDmTimerIndex;
  uint8 LucCount;
  #endif  

  #if((COM_TX_IPDU_TMS == STD_ON) || \
  ((COM_FILTER_ONEEVERYN == STD_ON) && (COM_RX_SIGNAL_FILTER == STD_ON)))
  uint8 LucFilterStsCount;
  #endif 
  
  #if((COM_RX_IPDU_DM == STD_ON) || \
    (COM_RX_SIGNAL_UBDM == STD_ON) || \
    (COM_RX_SIGGROUP_UBDM == STD_ON) || \
    (COM_RX_IPDU_COUNTER_ENABLED == STD_ON) || \
    (COM_RX_TP_SUPPORT == STD_ON) || \
    (COM_RX_REPLICATION == STD_ON))
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu;
  #endif    

  LddIpduGroupId = IpduGroupId;
  /* Get the pointer to the I-PDU group structure */
  LpIpduGroup = &Com_GaaIpduGroup[LddIpduGroupId];
  /* Get the number of I-PDU Group */
  /* Enable Ipdu Group Status */
  Com_GaaIpduGrpEnStatus[LpIpduGroup->ucGroupIndex] |=
                                             (LpIpduGroup->ucStatusMask);
  /* Enable Ipdu Group Status */
  Com_GaaIpduGrpDmStatus[LpIpduGroup->ucGroupIndex] |=
                                             (LpIpduGroup->ucStatusMask);
  #if(COM_TX_IPDU == STD_ON)
  /* Get the number of Tx I-PDUs  */
  LddNoOfIpdus = (PduIdType)LpIpduGroup->ddNoOfTxIpdus;
  LddPduIndex = (PduIdType)LpIpduGroup->ddTxIpduIndex;

  /* Loop for all Tx PDUs belong to that group */
  while(LddNoOfIpdus != (PduIdType)COM_ZERO)
  {
    --LddNoOfIpdus;
    LddIpduHandleId = (PduIdType)Com_GaaTxIpduGroup[LddPduIndex];
    if(Com_GaaTxIpduStatus[LddIpduHandleId] == (PduIdType)COM_ZERO)
    {


      /* Check if initialization is equal to true then clear all bits */
      if(COM_TRUE == Initialize)
      {
        Com_GaaTxIpduStatusBit[LddIpduHandleId] &= (COM_TX_TMS_STATUS_MASK);
      }
      else
      {
        Com_GaaTxIpduStatusBit[LddIpduHandleId] &= 
                                                ((COM_TX_TMS_STATUS_MASK) |
                                                (COM_TX_PT_STATUS_MASK) |
                                                (COM_TX_RETRY_STATUS_MASK));
      }

      #if((COM_TX_IPDU_TMS == STD_ON) || (COM_TX_IPDU_PT == STD_ON) \
      || (COM_TX_IPDU_DM == STD_ON) || (COM_TX_TP_SUPPORT == STD_ON) \
      || (COM_TX_IPDU_REPETITION == STD_ON) || (COM_TX_IPDU_COUNTER_ENABLED == STD_ON) \
      || (COM_TX_SIGNAL_UB == STD_ON) || (COM_TX_SIGGROUP_UB == STD_ON) || (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON))
      LpTxIpdu = &Com_GaaTxIpdu[LddIpduHandleId];
      #endif

      #if(COM_TX_IPDU_TMS == STD_ON)
      LblFilterResult = COM_TRUE;
      if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_TMS_CONFIG_MASK) != COM_FALSE)
      {
        LblFilterResult = COM_FALSE;
        LpTxModeSelect = LpTxIpdu->pTxModeSelect;
        /* Get the pointer to filter status */
        LucFilterStatusIndex = LpTxModeSelect->ucFilterStatusIndex;
        LpFilterStatus =
              &Com_GaaFilterStatus[LucFilterStatusIndex];
        /* Get the counter */
        LucFilterStsCount = LpTxModeSelect->ucFilterStatusCount;
        /* Loop for all the signals configured for filtering */
        do
        {
          /* Decrement the filter status count */
          LucFilterStsCount--;
          /* Check whether filter status is set to true */
          if(*LpFilterStatus != COM_ZERO)
          {
            /* Set filter status count to zero to break the loop */
            LucFilterStsCount = COM_ZERO;
            /* Set the return value to true */
            LblFilterResult = COM_TRUE;
      
          } /* if(*LpFilterStatus != COM_ZERO) */
           
          /* Increment the filter status pointer to point to n
             filter status area */
          LucFilterStatusIndex++;
          LpFilterStatus =
              &Com_GaaFilterStatus[LucFilterStatusIndex];         
        }while(LucFilterStsCount != COM_ZERO);
        
        #if(COM_TX_IPDU_PT == STD_ON) 
        if((Com_GaaTxIpduStatusBit[LddIpduHandleId] &
          COM_TX_TMS_STATUS_MASK) != LblFilterResult)
        {
          /* Get the pointer to Tx Mode */
          LpTxMode = &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex]; 
            
          if(COM_FALSE == LblFilterResult)
          {
            LpTxMode = 
            &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex
            +(PduIdType)COM_ONE]; 
          } 
          if(((LpTxMode->ucTxMode) <= COM_TX_MIXEDNTIMES_MODE) &&
                           ((LpTxMode->ucTxMode) != COM_TX_NONE_MODE))
          {
            /* Load the the periodic timer with offset value */
            Com_GaaTxPeriodicTimer[LpTxIpdu->ddTxPeriodicTimerIndex] =
                                        (LpTxMode->usOffsetValue);
          } /* Check whether Tx mode of the I-PDU is periodic or mixed */
        }
        #endif    
      } /* if((LucTxConfig & COM_TX_IPDU_TMS_CONFIG_MASK) != COM_FALSE) */
      
      Com_GaaTxIpduStatusBit[LddIpduHandleId] 
        &= (uint16)(~COM_TX_TMS_STATUS_MASK);
      Com_GaaTxIpduStatusBit[LddIpduHandleId] 
        |= LblFilterResult;
      #else
      Com_GaaTxIpduStatusBit[LddIpduHandleId] 
        |= (COM_TX_TMS_STATUS_MASK);          
      #endif

      
      
      if(COM_TRUE == Initialize)
      {
        #if((COM_TX_IPDU_TMS == STD_ON)||(COM_TX_IPDU_PT == STD_ON) \
        ||(COM_TX_IPDU_DM == STD_ON))
        /* Get the pointer to Tx Mode */
        LpTxMode = &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex];
        #endif  
        #if((COM_TX_IPDU_TMS == STD_ON)||(COM_TX_IPDU_PT == STD_ON))
        if(COM_FALSE == 
        (Com_GaaTxIpduStatusBit[LddIpduHandleId] & COM_TX_TMS_STATUS_MASK))
        {
          LpTxMode = 
          &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex
          +(PduIdType)COM_ONE];
        }
        #endif  
        #if (COM_TX_IPDU_MINDELAY_ENABLED == STD_ON)          
        if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_MDT_CONFIG_MASK) 
          != COM_FALSE)
        {
          Com_GaaTxMDTimer[LpTxIpdu->ddTxMDTimerIndex] = (uint16)COM_ZERO;
        }
        #endif  
        #if((COM_TX_SIGNAL_UB == STD_ON) || \
                       (COM_TX_SIGGROUP_UB == STD_ON))
        if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_UB_CONFIG_MASK) != COM_FALSE)
        {
          Com_TxClearUpdateBit(LpTxIpdu,
                 Com_GaaTxPduInfoPtr[LddIpduHandleId].SduDataPtr);
        }
        #endif
        #if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON)
        if(LpTxIpdu->ddTxIpduCounter != COM_INVALID_TXID_PARAM)
        {
          LpTxIpduCounter 
            = &Com_GaaTxIpduCounter[LpTxIpdu->ddTxIpduCounter];
          Com_GaaTxIpduCountVal[LpTxIpduCounter->ucTxIpduCountData] &=
                   (uint8)(~(LpTxIpduCounter->ucTxIpduCntWrpMask));

        }
        #endif
        #if(COM_TX_IPDU_DM == STD_ON)
        if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_DM_CONFIG_MASK) != COM_FALSE)
        {
          Com_GaaTxDMTimer[LpTxIpdu->ddTxIpduDmIndex] = (uint16)COM_ZERO;

          if(((LpTxIpdu->ucTxConfig & COM_TX_IPDU_TMS_CONFIG_MASK) 
            == COM_FALSE) && (LpTxMode->ucTxMode == COM_TX_NONE_MODE))
          {
            Com_GaaTxIpduStatusBit[LddIpduHandleId] 
              |= COM_TX_DM_STATUS_MASK;
          }
        }
        #endif  
        #if(COM_TX_IPDU_PT == STD_ON) 
        if(((LpTxMode->ucTxMode) <= COM_TX_MIXEDNTIMES_MODE) &&
                ((LpTxMode->ucTxMode) != COM_TX_NONE_MODE))
        {
          /* Load the the periodic timer with offset value */
          Com_GaaTxPeriodicTimer[LpTxIpdu->ddTxPeriodicTimerIndex] =
                            (LpTxMode->usOffsetValue);

        } /* Check whether Tx mode of the I-PDU is periodic or mixed */
        #endif  
        #if((COM_TX_IPDU_TMS == STD_ON) && (COM_FILTER_ONEEVERYN == STD_ON))
        if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_TMS_CONFIG_MASK) 
          != COM_FALSE)
        {
          LucFilterStsCount = COM_NO_OF_FILTER_ONEVERYN;
          do
          {
            --LucFilterStsCount;
            if(Com_GaaFilterOneEveryN[LucFilterStsCount].ddComPduId ==
                                                          LddIpduHandleId)
            {
              #if(COM_RX_SIGNAL_FILTER == STD_ON)
              if(Com_GaaFilterOneEveryN[LucFilterStsCount].ucFltrStsMask
                                                             != COM_ZERO)
              #endif
              {
                *Com_GaaFilterOneEveryN[LucFilterStsCount].pCounter =
                                                                 (uint16)COM_ZERO;
              }
            }
          }while(LucFilterStsCount != COM_ZERO);
        }
        #endif
      } /* if(Initialize == COM_TRUE) */

      #if(COM_TX_IPDU_DM == STD_ON)
      #if(COM_TX_IPDU_TMS == STD_ON)
      if(COM_FALSE == (LpTxIpdu->ucTxConfig & 
                                  COM_TX_IPDU_TMS_CONFIG_MASK))
      #endif
      {
        LpTxModeTrue = &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex];
        #if(COM_TX_IPDU_TMS == STD_ON)
        LpTxModeFalse = LpTxModeTrue;
        #endif
        #if(COM_TX_IPDU_TMS == STD_ON)
        if((LpTxIpdu->ucTxConfig & COM_TX_IPDU_TMS_CONFIG_MASK) 
          != COM_ZERO)
        { 
          LpTxModeFalse = 
          &Com_GaaTxMode[LpTxIpdu->ddTrueTxModeIndex
          +(PduIdType)COM_ONE];    
        }
        #endif
        if((COM_TX_NONE_MODE == LpTxModeTrue->ucTxMode) &&
          ((LpTxIpdu->ucTxConfig & COM_TX_IPDU_TMS_CONFIG_MASK) 
          != COM_FALSE))
        {
          #if(COM_TX_IPDU_TMS == STD_ON)
          if(COM_TX_NONE_MODE == LpTxModeFalse->ucTxMode)
          #endif
          {
            Com_GaaTxDMTimer[LpTxIpdu->ddTxIpduDmIndex] =
            Com_GaaTxIpduDm[LpTxIpdu->ddTxIpduDmIndex].usDmTimeout 
            + (uint16)COM_ONE;
            /* Set Request bit */
            Com_GaaTxIpduStatusBit[LddIpduHandleId] 
              |= COM_TX_REQ_STATUS_MASK;
          }
        }
      }
      #endif

      #if(COM_TX_IPDU_REPETITION == STD_ON)
      if((LpTxIpdu->ddTxReptIndex) != COM_INVALID_TXID_PARAM)
      {
        Com_GaaTxReptTimer[LpTxIpdu->ddTxReptIndex] = (uint16)COM_ZERO;
        Com_GaaTxReptCount[LpTxIpdu->ddTxReptIndex] = COM_ZERO;
        Com_GaaTxReptSubCount[LpTxIpdu->ddTxReptIndex] = COM_ZERO;
      }
      #endif
      /* #1632 : Initialize TP status */
      #if(COM_TX_TP_SUPPORT == STD_ON)
      /* Get the pointer to Tx Ipdu */
      if(LpTxIpdu->ucTxTPRef != COM_INVALID_PARAM)
      {
        LpTxTPIpdu = &Com_GaaTxTPIpdu[LpTxIpdu->ucTxTPRef];
        Com_GaaTxTPStatus[LpTxTPIpdu->ucTxTPStatusRef] &= 
                             (uint8)~(LpTxTPIpdu->ucTxTPStatusMask);
      }
      #endif
    }
    ++Com_GaaTxIpduStatus[LddIpduHandleId];
    ++LddPduIndex;
    
  }
  #endif /* #if(COM_TX_IPDU == STD_ON) */

  #if(COM_RX_IPDU == STD_ON)
  /* Get the number of Tx I-PDUs  */
  LddNoOfIpdus = (PduIdType)LpIpduGroup->ddNoOfRxIpdus;
  /* Get the group index */
  LddPduIndex = (PduIdType)LpIpduGroup->ddRxIpduIndex;

  /* Loop for all Rx PDUs */
  while(LddNoOfIpdus != (PduIdType)COM_ZERO)
  {
    --LddNoOfIpdus;
    LddIpduHandleId = (PduIdType)Com_GaaRxIpduGroup[LddPduIndex];	
    /* Check if the I-PDU has already been started */
    if((PduIdType)COM_ZERO == Com_GaaRxIpduStatus[LddIpduHandleId])
    { 
      #if((COM_RX_IPDU_DM == STD_ON) || \
        (COM_RX_SIGNAL_UBDM == STD_ON) || \
        (COM_RX_SIGGROUP_UBDM == STD_ON) || \
        (COM_RX_IPDU_COUNTER_ENABLED == STD_ON) || \
        (COM_RX_TP_SUPPORT == STD_ON) || \
        (COM_RX_REPLICATION == STD_ON))
      LpRxIpdu = &Com_GaaRxIpdu[LddIpduHandleId];
      
      #endif          
      if(COM_TRUE == Initialize)
      {
        #if((COM_FILTER_ONEEVERYN == STD_ON) \
          && (COM_RX_SIGNAL_FILTER == STD_ON))
        if(((Com_GaaRxIpdu[LddIpduHandleId].ucRxConfig &
          COM_RX_ONEVERYN_CONFIG_MASK) != COM_FALSE))
        {
          LucFilterStsCount = COM_NO_OF_FILTER_ONEVERYN;
          do
          {
            --LucFilterStsCount;
            #if(COM_TX_IPDU_TMS == STD_ON)
            if(Com_GaaFilterOneEveryN[LucFilterStsCount].ddComPduId ==
                                               LddIpduHandleId)
            #endif
            {
              #if((COM_TX_IPDU_TMS == STD_ON) \
              && (COM_NO_OF_FILTER_ONEVERYN > COM_MACRO_ZERO))
              if(COM_ZERO 
                == Com_GaaFilterOneEveryN[LucFilterStsCount].ucFltrStsMask)
              #endif
              {                 
                *Com_GaaFilterOneEveryN[LucFilterStsCount].pCounter 
                  = (uint16)COM_ZERO;
              }
            }
          }while(LucFilterStsCount != COM_ZERO);
        }
        #endif
        #if((COM_RX_IPDU_DM == STD_ON) || \
          (COM_RX_SIGNAL_UBDM == STD_ON) || \
          (COM_RX_SIGGROUP_UBDM == STD_ON))
        if((Com_GaaRxIpdu[LddIpduHandleId].ucRxConfig &
                       COM_RX_DM_CONFIG_MASK) != COM_FALSE)
        {
          if(((PduIdType)COM_ZERO == 
                      Com_GaaRxDmStatus[Com_GaaRxIpdu[LddIpduHandleId]
                      .ddRxIpduDmIndex]))
          {
            LddRxDmTimerIndex = LpRxIpdu->ddRxIpduDmIndex;
            LpRxDm = &Com_GaaRxDm[LddRxDmTimerIndex];
            LucCount = LpRxDm->ucRxDmCount;
            do
            {
              Com_GaaRxDMTimer[LddRxDmTimerIndex] 
                = LpRxDm->usRxDmFirstTimeout;
              --LucCount;
              LddRxDmTimerIndex++;
              LpRxDm = &Com_GaaRxDm[LddRxDmTimerIndex];
            }while(LucCount != COM_ZERO);
          }
          Com_GaaRxDmStatus[Com_GaaRxIpdu[LddIpduHandleId]
            .ddRxIpduDmIndex]++;
        }
        #endif
        
        #if(COM_RX_IPDU_COUNTER_ENABLED == STD_ON)
        if((LpRxIpdu->ddRxIpduCounter != COM_INVALID_RXID_PARAM))
        {
          LpRxIpduCounter 
            = &Com_GaaRxIpduCounter[LpRxIpdu->ddRxIpduCounter];
          Com_GaaRxIpduCountVal[LpRxIpduCounter->ucRxIpduCountData] &=
          (uint8)(~(LpRxIpduCounter->ucRxIpduCntWrpMask));
          Com_GaaRamIpduCounterSts[LpRxIpduCounter->ucIpduCnterStsIndex] &=
          (uint8)(~(LpRxIpduCounter->ucIpduCounterEnMask));
        }
        #endif
        
        #if(COM_RX_REPLICATION == STD_ON)
        if((LpRxIpdu->ucRxIpduRepliIndex != COM_INVALID_NONE))
        {
          LpRxIpduRepli 
            = &Com_GaaRxIpduReplication[LpRxIpdu->ucRxIpduRepliIndex];
          Com_GaaRxRepliCount[LpRxIpduRepli->ucIpduRepliCountIndex] &=
          (uint8)(~(uint8)((COM_REPLICATION_MASK <<
          (COM_EIGHT - (LpRxIpduRepli->ucIpduRepliCountShift)))));
          Com_GaaRamIpduRepliSts[LpRxIpduRepli->ucIpduRepliStsIndex] &=
          (uint8)(~(LpRxIpduRepli->ucIpduRepliEnMask));
        }
        #endif
        
      }
      /* #1632 : Initialize TP status */
      #if(COM_RX_TP_SUPPORT == STD_ON)
      /* Get the pointer to Rx Ipdu */
      if(LpRxIpdu->ucRxTPRef != COM_INVALID_PARAM)
      {
        /* Get the pointer to Rx TP structure */
        LpRxTPIpdu = &Com_GaaRxTPIpdu[LpRxIpdu->ucRxTPRef];
        Com_GaaRxTPStatus[LpRxTPIpdu->ucRxTPStatusRef] 
          &= (uint8)(~(LpRxTPIpdu->ucRxTPStatusMask));
      }
      #endif          
    }
    ++Com_GaaRxIpduStatus[LddIpduHandleId];
    ++LddPduIndex;
  }
  #endif
  /* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Code structure for optimal performance */    
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Com_StopIpduGroup                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Internal function stops a                      **
**                        pre-configured I-PDU group.                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different I-PDU groups.               **
**                        Non-Reentrant for same I-PDU group.                 **
**                                                                            **
** Input Parameters     : IpduGroupId                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaIpduGroup           **
**                                                 Com_GaaIpduGrpEnStatus     **
**                                                 Com_GaaTxIpduGroup         **
**                                                 Com_GaaTxIpduStatus        **
**                                                 Com_GaaTxIpduStatusBit     **
**                                                 Com_GaaTxIpdu              **
**                                                 Com_GaaTxIpduConfirm       **
**                                                 Com_GaaSigErrorCbk         **
**                                                 Com_GaaTxIpduCounter       **
**                                                 Com_GaaTxIpduCountVal      **
**                                                 Com_GaaRxIpduGroup         **
**                                                 Com_GaaRxIpduStatus        **
**                                                 Com_GaaIpduGrpDmStatus     **
**                                                 Com_GaaRxIpdu              **
**                                                 Com_GaaRxDmStatus          **
**                        Function(s) invoked    : SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
**                                                 pSigErrorCbk               **
**                                                 Com_TxZeroCounterUpdate()  **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_StopIpduGroup(Com_IpduGroupIdType IpduGroupId)
{
  /* Pointer to Ipdu group structure */
  P2CONST(Com_IpduGroup, AUTOMATIC, COM_CONST) LpIpduGroup;
  #if(COM_TX_IPDU_ERRORNOTIFY == STD_ON)
  /* Pointer to Tx Ipdu confirm structure */
  P2CONST(Com_TxIpduConfirm, AUTOMATIC, COM_CONST) LpTxIpduConfirm;
  /* Pointer to signal error Call back structure */
  P2CONST(Com_SigErrorCbk, AUTOMATIC, COM_CONST) LpSigErrorCbk;
  #endif
  #if((COM_TX_IPDU_ERRORNOTIFY == STD_ON) || \
    (COM_TX_IPDU_COUNTER_ENABLED == STD_ON))
  P2CONST(Com_TxIpdu, AUTOMATIC, COM_CONST) LpTxIpdu;
  #endif
  #if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON)
  P2CONST(Com_TxIpduCounter, AUTOMATIC, COM_CONST) LpTxIpduCounter;
  P2CONST(Com_TxPack, AUTOMATIC, COM_CONST)LpTxPack;
  uint8 LucTxIpduCntVal;  
  #endif
  /* Local variable to store no. Of Ipdus */
  PduIdType LddNoOfIpdus;
  /* Local variable to store Com Ipdu handle ID */

  PduIdType LddPduIndex;
  PduIdType LddIpduHandleId;
  #if(COM_TX_IPDU_ERRORNOTIFY == STD_ON)
  uint8 LddNoOfCount;
  Com_ErrCbkCountType LddSigErrorCbkIndex;
  #endif  
  /* Get the pointer to the I-PDU group structure */
  LpIpduGroup = &Com_GaaIpduGroup[IpduGroupId];
  /* Enable Ipdu Group Status */
  Com_GaaIpduGrpEnStatus[LpIpduGroup->ucGroupIndex] &=
                                      (uint8)(~(LpIpduGroup->ucStatusMask));
  #if(COM_TX_IPDU == STD_ON)
  /* Get the number of Tx I-PDUs  */
  LddNoOfIpdus = (PduIdType)LpIpduGroup->ddNoOfTxIpdus;
  LddPduIndex = (PduIdType)LpIpduGroup->ddTxIpduIndex;
  /* Loop for all PDUs */
  while(LddNoOfIpdus != (PduIdType)COM_ZERO)
  {
    --LddNoOfIpdus;
    LddIpduHandleId = (PduIdType)Com_GaaTxIpduGroup[LddPduIndex];
    LddPduIndex++;
    /* change the status */
    Com_GaaTxIpduStatus[LddIpduHandleId]--;
    if(Com_GaaTxIpduStatus[LddIpduHandleId] == (PduIdType)COM_ZERO)
    {
      #if((COM_TX_IPDU_ERRORNOTIFY == STD_ON) || \
      (COM_TX_IPDU_COUNTER_ENABLED == STD_ON))
      /* Get the pointer to Tx Ipdu */
      LpTxIpdu = &Com_GaaTxIpdu[LddIpduHandleId];
      #endif
      #if(COM_TX_IPDU_ERRORNOTIFY == STD_ON)
      if((Com_GaaTxIpduStatusBit[LddIpduHandleId] &
                                     COM_TX_REQ_STATUS_MASK) != COM_FALSE)
      {            
        if(LpTxIpdu->ddTxPduConfirmIndex != COM_INVALID_TXID_PARAM)
        {
          /* Get the pointer to Tx Confirmation Structure */
          LpTxIpduConfirm =
                     &Com_GaaTxIpduConfirm[LpTxIpdu->ddTxPduConfirmIndex];
          /* Get the number of signals configured for call-back
             notification */
          LddNoOfCount = LpTxIpduConfirm->ucNoOfSigErrorCbk;
          /* Check whether number of signal call-back notification
          count is not equal to zero */
          if(LddNoOfCount != COM_ZERO)
          {
            /* Get the pointer to SigErrorCbk structure */
            LddSigErrorCbkIndex = LpTxIpduConfirm->ddSigErrCbkIndex;
            LpSigErrorCbk =
                 &Com_GaaSigErrorCbk[LddSigErrorCbkIndex];
            /* Loop for all the signals configured for timeout error
            notification */
            do
            {
              /* Invoke the error notification function  */
              (LpSigErrorCbk->pSigErrorCbk)();

              /* Get the pointer to n SigErrorCbk structure */
              LddSigErrorCbkIndex++;
              LpSigErrorCbk =
                 &Com_GaaSigErrorCbk[LddSigErrorCbkIndex];
              /* Decrement the signal error notification
              call-back count */
              LddNoOfCount--;
            }while(LddNoOfCount != COM_ZERO);

          } /* Check whether number of error callback is configured */
        }
      } /* Check whether Tx Request bit is set to true */
      #endif /*#if(COM_TX_IPDU_ERRORNOTIFY == STD_ON))*/
      
      #if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON)
      if(LpTxIpdu->ddTxIpduCounter != COM_INVALID_TXID_PARAM)
      {
        /* Get the pointer to Tx I-PDU counter structure */
        LpTxIpduCounter = 
          &Com_GaaTxIpduCounter[LpTxIpdu->ddTxIpduCounter];
        Com_GaaTxIpduCountVal[LpTxIpduCounter->ucTxIpduCountData] = 
              COM_ZERO;
        
        /* Get the pointer to TxPack structure */
        LpTxPack = &Com_GaaTxPack[LpTxIpduCounter->ddTxPackIndex];
        /* Get the present counter data */
        LucTxIpduCntVal = 
          Com_GaaTxIpduCountVal[LpTxIpduCounter->ucTxIpduCountData];
        
        /* Apply wrap around mask to the counter data */
        LucTxIpduCntVal &= LpTxIpduCounter->ucTxIpduCntWrpMask;
        
        /* Invoke write function to pack counter data to I-PDU buffer */
        (void)Com_PackRequestWrite(LpTxPack,
        (P2CONST(void, AUTOMATIC, COM_CONST))&LucTxIpduCntVal);
        
        /* Load present counter data in buffer */
        Com_GaaTxIpduCountVal[LpTxIpduCounter->ucTxIpduCountData] = 
        LucTxIpduCntVal;
      }
      #endif
    }
  }
  #endif
  #if(COM_RX_IPDU == STD_ON)
  /* Get the number of Rx I-PDUs  */
  LddNoOfIpdus = (PduIdType)LpIpduGroup->ddNoOfRxIpdus;
  LddPduIndex = (PduIdType)LpIpduGroup->ddRxIpduIndex;
  /* Loop for all PDUs */
  while(LddNoOfIpdus != (PduIdType)COM_ZERO)
  {
    LddIpduHandleId = (PduIdType)Com_GaaRxIpduGroup[LddPduIndex];
    --LddNoOfIpdus;
    LddPduIndex++;
    Com_GaaRxIpduStatus[LddIpduHandleId]--;
  }
  #if((COM_RX_IPDU_DM == STD_ON) || \
      (COM_RX_SIGNAL_UBDM == STD_ON) || \
      (COM_RX_SIGGROUP_UBDM == STD_ON))
  /* Check whether requested I-PDU group is active for Deadline
     monitoring */
  if((Com_GaaIpduGrpDmStatus[LpIpduGroup->ucGroupIndex] &
                              (LpIpduGroup->ucStatusMask)) != COM_FALSE)
  {
    /* Enable Ipdu Group Status */
    Com_GaaIpduGrpDmStatus[LpIpduGroup->ucGroupIndex] &=
                                      (uint8)(~(LpIpduGroup->ucStatusMask));
    /* Get the number of Rx I-PDUs  */
    LddNoOfIpdus = (PduIdType)LpIpduGroup->ddNoOfRxIpdus;

    LddPduIndex = (PduIdType)LpIpduGroup->ddRxIpduIndex;
    /* Loop for all PDUs */
    while(LddNoOfIpdus != (PduIdType)COM_ZERO)
    {
      LddIpduHandleId = Com_GaaRxIpduGroup[LddPduIndex];
      --LddNoOfIpdus;
      LddPduIndex++;
      if((Com_GaaRxIpdu[LddIpduHandleId].ucRxConfig &
                                      COM_RX_DM_CONFIG_MASK) != COM_FALSE)
      {
        Com_GaaRxDmStatus[Com_GaaRxIpdu[LddIpduHandleId].ddRxIpduDmIndex]--;
      }
    }
  } /* Check whether deadline monitoring is active */
  #endif /* Dead line Monitoring */
  #endif
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Com_SetIpduGroup                                    **
**                                                                            **
** Service ID           : 0x1D                                                **
**                                                                            **
** Description          : This function will set and reset the bit position of**
**                        I-PDU group in the group vector groups.             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : , ipduGroupId, bitVal                               **
**                                                                            **
** InOut parameter      : ipduGroupVector                                     **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Com_GaaIpduGroup              **
**                        Function(s) invoked : Det_ReportError()             **
*******************************************************************************/
#if((COM_TX_IPDU == STD_ON) || (COM_RX_IPDU == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_SetIpduGroup(Com_IpduGroupVector
  ipduGroupVector, Com_IpduGroupIdType IpduGroupId, boolean bitval)
{
  P2CONST(Com_IpduGroup, AUTOMATIC, COM_CONST) LpIpduGroup;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  uint8 LucReturnValue;
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_SETIPDUGROUP);
  /* Check whether I-PDU group ID is out of range */
  COM_DET_IPDUGROUPID_RANGE_CHECK_FLAG(COMSERVICEID_SETIPDUGROUP);
  /* Check whether ipduGroupVector is equal to NULL */
  COM_DET_IPDUGROUPVECTOR_CHECK_FLAG(COMSERVICEID_SETIPDUGROUP);
  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif
  {
    /* Get the pointer to I-PDU structure */
    LpIpduGroup = &Com_GaaIpduGroup[IpduGroupId];

    /* If bitval is true set ipduGroupVector */
    if(COM_TRUE == bitval)
    {
      /* Set the bit of corresponding ipduGroupId in the ipduGroupVector */
      ipduGroupVector[LpIpduGroup->ucGroupIndex] |= LpIpduGroup->ucStatusMask;
    }
    /* If bitval is false reset ipduGroupVector */
    else
    {
      /* Reset the bit of corresponding ipduGroupId in the ipduGroupVector */
      ipduGroupVector[LpIpduGroup->ucGroupIndex] &=  
                                            (uint8)(~LpIpduGroup->ucStatusMask);
    }
  } /* if(LblDetErrFlag == COM_FALSE) */
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_ClearIpduGroupVector                            **
**                                                                            **
** Service ID           : 0x1C                                                **
**                                                                            **
** Description          : This function sets all bits of the given            **
**                        ipduGroupVector to 0                                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : ipduGroupVector                                     **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Det_ReportError()             **
*******************************************************************************/
#if((COM_TX_IPDU == STD_ON) || (COM_RX_IPDU == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_ClearIpduGroupVector(Com_IpduGroupVector
  ipduGroupVector)
{
  uint8 LucVectArrIndex;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  uint8 LucReturnValue;
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_CLEARIPDUGROUPVECTOR);
  /* Check whether ipduGroupVector is equal to NULL */
  COM_DET_IPDUGROUPVECTOR_CHECK_FLAG(COMSERVICEID_CLEARIPDUGROUPVECTOR);

  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif
  {
    /* Set ipduGroupVector to Zero */
    for(LucVectArrIndex = COM_ZERO;
      LucVectArrIndex < COM_IPDU_GRP_VECTOR_SIZE; LucVectArrIndex++)
    {
      /* Initialize IpduGroupVector with Zero */
      ipduGroupVector[LucVectArrIndex] = COM_ZERO;
    }
  }
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_IpduGroupControl                                **
**                                                                            **
** Service ID           : 0x03                                                **
**                                                                            **
** Description          : This function starts and stops pre-configured I-PDU **
**                        groups.                                             **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : ipduGroupVector, initialize                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Com_GaaIpduGroup              **
**                        Function(s) invoked : Det_ReportError()             **
**                                              Com_StartIpduGroup()          **
**                                              Com_StopIpduGroup()           **
*******************************************************************************/
#if((COM_TX_IPDU == STD_ON) || (COM_RX_IPDU == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC (void, COM_CODE) Com_IpduGroupControl(Com_IpduGroupVector
  ipduGroupVector, boolean initialize)
{
  /* Pointer to Ipdu group structure */
  P2CONST(Com_IpduGroup, AUTOMATIC, COM_CONST) LpIpduGroup;
  uint8 LucVectArrIndex;
  uint8 LucGrpStsByte;
  uint8 LucBitPosition;
  uint8 LucGrpId;
  uint8 LucNoOfIpduGroups;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Initialize DET error flag to false */
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_IPDUGROUPCONTROL);
  /* Check if the "Vector" is NULL */
  COM_DET_IPDUGROUPVECTOR_CHECK_FLAG(COMSERVICEID_IPDUGROUPCONTROL);
  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif
  {
    LucVectArrIndex = COM_ZERO;
    
    while(LucVectArrIndex < COM_IPDU_GRP_VECTOR_SIZE)
    {
      LucBitPosition = COM_ZERO;
      /* Get the difference between the requested Ipdu group
         states and the current state*/
      LucGrpStsByte = ipduGroupVector[LucVectArrIndex];
      /* Check if there is a change */
      while(LucBitPosition < COM_EIGHT)
      {
        /* Get the I-PDU group Id for which status is changed */
        LucGrpId = (LucVectArrIndex * COM_EIGHT) + LucBitPosition;
        /* Check if the Group Id is valid */
        if(LucGrpId <= ((uint8)COM_IPDUGROUP_COUNT - COM_ONE))
        {
          /* Get the pointer to the I-PDU group structure */
          LpIpduGroup = &Com_GaaIpduGroup[LucGrpId];
          /* Get the number of I-PDU Groups contained in this group */
          LucNoOfIpduGroups = (LpIpduGroup->ucNoOfIpduGroups);
          /* This check is useful in case of a "super" group Ipdu */
          /* If the group was disable earlier and is now enabled */
          if(COM_TRUE == (LucGrpStsByte & (COM_ONE)))
          {
            /* If the super group is enabled we have to enable all
            the groups contained */

            if((Com_GaaIpduGrpEnStatus[LpIpduGroup->ucGroupIndex] &
                                  (LpIpduGroup->ucStatusMask)) == COM_FALSE)
            {
              Com_StartIpduGroup(LucGrpId, initialize);
            }           
            
            LucGrpStsByte = LucGrpStsByte >> LucNoOfIpduGroups;
            LucBitPosition += LucNoOfIpduGroups;
          }
          else
          {
             /* stops only one Ipdu group since an Ipdu can be
             stopped only if it is stopped in all the Ipdu Groups
             it is contained in */
            if((Com_GaaIpduGrpEnStatus[LpIpduGroup->ucGroupIndex] &
                                    (LpIpduGroup->ucStatusMask)) != COM_FALSE)
            {
              Com_StopIpduGroup(LucGrpId);
            }
            LucGrpStsByte = LucGrpStsByte >> LucNoOfIpduGroups;
            LucBitPosition += LucNoOfIpduGroups;
          }
        }
        else
        {
          /* Break out of the loop */
          LucVectArrIndex = (uint8)COM_IPDU_GRP_VECTOR_SIZE;
          LucBitPosition = COM_EIGHT;
        }
      }
      LucVectArrIndex++;
    }
  }
}

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#else
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC (void, COM_CODE) Com_IpduGroupControl(Com_IpduGroupVector
  ipduGroupVector, boolean initialize)
{
  COM_UNUSED_PTR(ipduGroupVector);
  COM_UNUSED(initialize);  
  /* #1204 : Dummy Function for integration with BswM Module */
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Com_EnableRxDM                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function enables the reception deadline        **
**                        monitoring for the I-PDU(s) within the requested    **
**                        Rx I-PDU group.                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different I-PDU groups.               **
**                        Non-Reentrant for same I-PDU group.                 **
**                                                                            **
** Input Parameters     : IpduGroupId                                         **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :Com_GaaIpduGroup            **
**                                                Com_GaaIpduGrpDmStatus      **
**                                                Com_GaaRxIpduGroup          **
**                                                Com_GaaRxIpdu               **
**                                                Com_GaaRxDmStatus           **
**                                                Com_GaaRxDm                 **
**                                                Com_GaaRxDMTimer            **
**                        Function(s) invoked    :SchM_Enter_xxx()            **
**                                                SchM_Exit_xxx()             **
*******************************************************************************/
#if((COM_RX_IPDU_DM == STD_ON) || \
     (COM_RX_SIGNAL_UBDM == STD_ON) || \
     (COM_RX_SIGGROUP_UBDM == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_EnableRxDM(Com_IpduGroupIdType IpduGroupId)
{
  /* Pointer to Ipdu group structure */
  P2CONST(Com_IpduGroup, AUTOMATIC, COM_CONST) LpIpduGroup;
  /* Pointer to Rx Ipdu structure */
  P2CONST(Com_RxIpdu, AUTOMATIC, COM_CONST) LpRxIpdu;
  #if(COM_RX_IPDU_DM == STD_ON)
  /* Pointer to RxDm structure */
  P2CONST(Com_RxDm, AUTOMATIC, COM_CONST) LpRxDm;
  #endif
  /* Local variable to store Com Ipdu handle ID */
  PduIdType LddIpduIndex;
  PduIdType LddPduIndex;
  /* Local variable to store no. Of Ipdus */
  PduIdType LddNoOfIpdus;
  #if(COM_RX_IPDU_DM == STD_ON)
  /* Local variable to store RxDm timer index*/
  PduIdType LddRxDmTimerIndex;
  /* Local variable to store count */
  uint8 LucCount;
  #endif
  /* Local variable to store no. Of Ipdu groups */
  uint8 LucNoOfIpduGroups;
  Com_IpduGroupIdType LddIpduGroupId;

  LddIpduGroupId = IpduGroupId;
  /* Get the pointer to the I-PDU group structure */
  LpIpduGroup = &Com_GaaIpduGroup[LddIpduGroupId];
  /* Get the number of Tx I-PDU groups  */
  LucNoOfIpduGroups = (LpIpduGroup->ucNoOfIpduGroups);
  do
  {

    /* Check whether requested I-PDU group deadline monitoring is stopped */
    if(COM_FALSE == (Com_GaaIpduGrpDmStatus[LpIpduGroup->ucGroupIndex] &
                                      (LpIpduGroup->ucStatusMask)))
    {
      /* Disable Ipdu Group Dm Status */
      Com_GaaIpduGrpDmStatus[LpIpduGroup->ucGroupIndex] |=
                                                    (LpIpduGroup->ucStatusMask);
      /* Get the number of Rx I-PDUs  */
      LddNoOfIpdus = LpIpduGroup->ddNoOfRxIpdus;
      LddPduIndex = (LpIpduGroup->ddRxIpduIndex + LddNoOfIpdus) - 
      (PduIdType)COM_ONE;
      /* Loop for all PDUs */
      while(LddNoOfIpdus != (PduIdType)COM_ZERO)
      {
        LddIpduIndex = Com_GaaRxIpduGroup[LddPduIndex];

        if((Com_GaaRxIpdu[LddIpduIndex].ucRxConfig &
                                            COM_RX_DM_CONFIG_MASK) != COM_FALSE)
        {
          if(((PduIdType)COM_ZERO ==  
                Com_GaaRxDmStatus[Com_GaaRxIpdu[LddIpduIndex].ddRxIpduDmIndex]))
          {
            LpRxIpdu = &Com_GaaRxIpdu[LddIpduIndex];
            #if(COM_RX_IPDU_DM == STD_ON)
            LddRxDmTimerIndex = LpRxIpdu->ddRxIpduDmIndex;
            LpRxDm = &Com_GaaRxDm[LddRxDmTimerIndex];
            LucCount = LpRxDm->ucRxDmCount;
            do
            {
              #if(COM_RX_INTERRUPT_BASED_PROCESS == STD_OFF)
              SchM_Enter_Com_RX_DM_STS_PROTECTION_AREA();
              #endif
              Com_GaaRxDMTimer[LddRxDmTimerIndex] = LpRxDm->usRxDmFirstTimeout;
              #if(COM_RX_INTERRUPT_BASED_PROCESS == STD_OFF)
              SchM_Exit_Com_RX_DM_STS_PROTECTION_AREA();
              #endif
              --LucCount;
              LddRxDmTimerIndex++;
              LpRxDm = &Com_GaaRxDm[LddRxDmTimerIndex];
            }while(LucCount != COM_ZERO);
            #endif
          }
          Com_GaaRxDmStatus[Com_GaaRxIpdu[LddIpduIndex].ddRxIpduDmIndex]++;
        }
        LddNoOfIpdus--;
        LddPduIndex--;
      }
    } /* Decrement the number of Tx I-PDU groups */
      LucNoOfIpduGroups--;

      /* Get the pointer to n Tx I-PDU group structure */
      LddIpduGroupId++;
      /* Get the pointer to the I-PDU group structure */
      LpIpduGroup = &Com_GaaIpduGroup[LddIpduGroupId];
  }while(LucNoOfIpduGroups != COM_ZERO);
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_DisableRxDM                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function disables the reception deadline       **
**                        monitoring for the I-PDU(s) within the requested    **
**                        Rx I-PDU group.                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different I-PDU groups.               **
**                        Non-Reentrant for same I-PDU group.                 **
**                                                                            **
** Input Parameters     : IpduGroupId                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : Com_GaaIpduGroup           **
**                                                 Com_GaaIpduGrpDmStatus     **
**                                                 Com_GaaRxIpduGroup         **
**                                                 Com_GaaRxIpdu              **
**                                                 Com_GaaRxDmStatus          **
**                        Function(s) invoked    : SchM_Enter_xxx()           **
**                                                 SchM_Exit_xxx()            **
*******************************************************************************/
#if((COM_RX_IPDU_DM == STD_ON) || \
     (COM_RX_SIGNAL_UBDM == STD_ON) || \
     (COM_RX_SIGGROUP_UBDM == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_DisableRxDM(Com_IpduGroupIdType IpduGroupId)
{
  /* Pointer to Ipdu group structure */
  P2CONST(Com_IpduGroup, AUTOMATIC, COM_CONST) LpIpduGroup;
  /* Local variable to store Com Ipdu handle ID */
  PduIdType LddIpduIndex;
  PduIdType LddPduIndex;
  /* Local variable to store no Of Ipdus */
  PduIdType LddNoOfIpdus;
  {
    /* Get the pointer to the I-PDU group structure */
    LpIpduGroup = &Com_GaaIpduGroup[IpduGroupId];

    /* Check whether its parent Ipdu Group */
    if((Com_GaaIpduGrpDmStatus[LpIpduGroup->ucGroupIndex] &
                                (LpIpduGroup->ucStatusMask)) != COM_FALSE)
    {
      /* Enable Ipdu Group Status */
      Com_GaaIpduGrpDmStatus[LpIpduGroup->ucGroupIndex] &=
                                          (uint8)(~(LpIpduGroup->ucStatusMask));
      /* Get the number of Rx I-PDUs  */
      LddNoOfIpdus = LpIpduGroup->ddNoOfRxIpdus;
      LddPduIndex = (LpIpduGroup->ddRxIpduIndex + LddNoOfIpdus) 
      - (PduIdType)COM_ONE;
      /* Loop for all PDUs */
      while(LddNoOfIpdus != (PduIdType)COM_ZERO)
      {

        LddIpduIndex = Com_GaaRxIpduGroup[LddPduIndex];
        if((Com_GaaRxIpdu[LddIpduIndex].ucRxConfig &
                                          COM_RX_DM_CONFIG_MASK) != COM_FALSE)
        {
          Com_GaaRxDmStatus[Com_GaaRxIpdu[LddIpduIndex].ddRxIpduDmIndex]--;
        }
        LddNoOfIpdus--;
        LddPduIndex--;
      }
    } /* Check whether deadline monitoring is active */
  } /* if(LucReturnValue == COM_FALSE) */
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif


/*******************************************************************************
** Function Name        : Com_ReceptionDMControl                              **
**                                                                            **
** Service ID           : 0x06                                                **
**                                                                            **
** Description          : This function enables or disables deadline          **
**                        monitoring for Rx I-PDUs in I-PDU Groups            **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : ipduGroupVector                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :Com_GaaIpduGroup               **
**                        Function(s) invoked :Det_ReportError()              **
**                                             Com_EnableRxDM()               **
**                                             Com_DisableRxDM()              **
*******************************************************************************/
#if((COM_RX_IPDU_DM == STD_ON) || \
     (COM_RX_SIGNAL_UBDM == STD_ON) || \
     (COM_RX_SIGGROUP_UBDM == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_ReceptionDMControl(Com_IpduGroupVector
  ipduGroupVector)
{
  /* Pointer to Ipdu group structure */
  P2CONST(Com_IpduGroup, AUTOMATIC, COM_CONST) LpIpduGroup;
  uint8 LucVectArrIndex;
  uint8 LucGrpStsByte;
  uint8 LucBitPosition;
  uint8 LucGrpId;
  uint8 LucNoOfIpduGroups;
  #if(COM_DEV_ERROR_DETECT == STD_ON)
  /* Local variable to store return value */
  uint8 LucReturnValue;
  /* Initialize DET error flag to false */
  LucReturnValue = (uint8)E_OK;
  /* Check whether module is initialized */
  COM_DET_INIT_STATUS_CHECK_FLAG(COMSERVICEID_RECEPTIONDMCONTROL);
  /* Check if the "Vector" is NULL */
  COM_DET_IPDUGROUPVECTOR_CHECK_FLAG(COMSERVICEID_RECEPTIONDMCONTROL);
  /* Check whether any development error has occurred */
  if(LucReturnValue == (uint8)E_OK)
  #endif
  {
    LucVectArrIndex = COM_ZERO;
    
    while(LucVectArrIndex < COM_IPDU_GRP_VECTOR_SIZE)
    {
      LucBitPosition = COM_ZERO;
      /* Get the difference between the requested Ipdu group
         states and the current state*/
      LucGrpStsByte = ipduGroupVector[LucVectArrIndex];
      /* Check if there is a change */
      while(LucBitPosition < COM_EIGHT)
      {
        /* Get the I-PDU group Id for which status is changed */
        LucGrpId = (LucVectArrIndex * COM_EIGHT) + LucBitPosition;
        /* Check if the Group Id is valid */
        if(LucGrpId <= (uint8)(COM_IPDUGROUP_COUNT - COM_ONE))
        {
          /* Get the pointer to the I-PDU group structure */
          LpIpduGroup = &Com_GaaIpduGroup[LucGrpId];
          /* Get the number of I-PDU Groups contained in this group */
          LucNoOfIpduGroups = (LpIpduGroup->ucNoOfIpduGroups);
          /* This check is useful in case of a "super" group Ipdu */
          /* If the group was disable earlier and is now enabled */
          if(COM_TRUE == (LpIpduGroup->blRxDmEnabled))
          {
            if(COM_TRUE == (LucGrpStsByte & (COM_ONE)))
            {
              /* If the super group is enabled we have to enable all
              the groups contained */
              Com_EnableRxDM(LucGrpId);
              LucGrpStsByte = LucGrpStsByte >> LucNoOfIpduGroups;
              LucBitPosition += LucNoOfIpduGroups;
            }
            else
            {
               /* stops only one Ipdu group since an Ipdu can be
               stopped only if it is stopped in all the Ipdu Groups
               it is contained in */
              
              Com_DisableRxDM(LucGrpId);
              LucGrpStsByte = LucGrpStsByte >> COM_ONE;
              LucBitPosition += COM_ONE;
            }
          }
          else
          {
            LucGrpStsByte = LucGrpStsByte >> COM_ONE;
            LucBitPosition += COM_ONE;
          }
        }
        else
        {
          /* Break out of the loop */
          LucVectArrIndex = COM_IPDU_GRP_VECTOR_SIZE;
          LucBitPosition = COM_EIGHT;
        }
      }
      LucVectArrIndex++;
    }
  }
}

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#else
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_ReceptionDMControl(Com_IpduGroupVector
  ipduGroupVector)
{
  COM_UNUSED_PTR(ipduGroupVector);
  /* #1204 : Dummy Function for integration with BswM Module */
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_TxCounterUpdate                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function added for cyclomatic complexity reduction. **
**                        Updates counter value in the I-PDU buffer           **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpTxIpduCounter                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Com_GaaTxPack                 **
**                                              Com_GaaTxIpduCountVal         **
**                        Function(s) invoked : SchM_Enter_xxx()              **
**                                              SchM_Exit_xxx()               **
**                                              pWrFuncPtr                    **
*******************************************************************************/
#if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON) 
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE) Com_TxCounterUpdate
   (P2CONST(Com_TxIpduCounter, AUTOMATIC, COM_CONST) LpTxIpduCounter)
{
  P2CONST(Com_TxPack, AUTOMATIC, COM_CONST)LpTxPack;
  uint8 LucTxIpduCntVal;

  /* Get the pointer to TxPack structure */
  LpTxPack = &Com_GaaTxPack[LpTxIpduCounter->ddTxPackIndex];
  /* Get the present counter data */
  LucTxIpduCntVal = 
    Com_GaaTxIpduCountVal[LpTxIpduCounter->ucTxIpduCountData];
  /* Increment I-PDU count value */
  LucTxIpduCntVal++;
  /* Apply wrap around mask to the counter data */
  LucTxIpduCntVal &= LpTxIpduCounter->ucTxIpduCntWrpMask;

  /* Invoke write function to pack counter data to I-PDU buffer */
  (void)Com_PackRequestWrite(LpTxPack,
  (P2CONST(void, AUTOMATIC, COM_CONST))&LucTxIpduCntVal);

  /* Enter protection area */
  SchM_Enter_Com_IPDU_COUNTER_PROTECTION();
  /* Load present counter data in buffer */
  Com_GaaTxIpduCountVal[LpTxIpduCounter->ucTxIpduCountData] = 
  LucTxIpduCntVal;
  /* Exit Critical Area */
  SchM_Exit_Com_IPDU_COUNTER_PROTECTION();
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Com_RxFilterCalc                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function added for cyclomatic complexity reduction. **
**                        It validates filter value for all involved signals  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LddIpduIndex, Initialize                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Com_GaaRxIpdu                 **
**                                              Com_GaaFilterOneEveryN        **
**                        Function(s) invoked : None                          **
*******************************************************************************/
#if((COM_FILTER_ONEEVERYN == STD_ON) && (COM_RX_SIGNAL_FILTER == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, COM_CODE)
              Com_RxFilterCalc(PduIdType LddIpduIndex, boolean Initialize)
{
  uint8 LucFilterStsCount;
  if(((Com_GaaRxIpdu[LddIpduIndex].ucRxConfig &
    COM_RX_ONEVERYN_CONFIG_MASK) != COM_FALSE)
    && (COM_TRUE == Initialize))
  {
    LucFilterStsCount = COM_NO_OF_FILTER_ONEVERYN;
    do
    {
      --LucFilterStsCount;
        #if(COM_TX_IPDU_TMS == STD_ON)
      if(Com_GaaFilterOneEveryN[LucFilterStsCount].ddComPduId ==
                                                      LddIpduIndex)
      #endif
      {
        #if((COM_TX_IPDU_TMS == STD_ON) \
          && (COM_NO_OF_FILTER_ONEVERYN > COM_MACRO_ZERO))
        if(COM_ZERO == Com_GaaFilterOneEveryN[LucFilterStsCount].ucFltrStsMask)
        #endif
        {
       
          *Com_GaaFilterOneEveryN[LucFilterStsCount].pCounter = COM_ZERO;
        }
      }
    }while(LucFilterStsCount != COM_ZERO);
  }
}
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/* polyspace:end<RTE: NIV : Not a defect : No Action Planned > initialized variable */
/* polyspace:end<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : No Action Planned > configured memory access index */
/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
