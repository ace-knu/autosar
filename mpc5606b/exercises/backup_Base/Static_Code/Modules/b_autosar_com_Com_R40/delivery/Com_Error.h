/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Com_Error.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Com Module                                            **
**                                                                            **
**  PURPOSE   : Header file for the declaration of all the DET related errors **
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
** 2.2.0     16-Apr-2017   Chan Kim    Internal Redmine #7707, #7525          **
** 2.1.0     25-May-2016   Chan Kim    Internal Redmine #4998                 **
** 2.0.3     24-Nov-2015   Chan Kim    Internal Redmine #3544, #3535          **
** 1.0.15    26-Jan-2015   Chan Kim    Internal Redmine #2051                 **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */

#ifndef COM_ERROR_H
#define COM_ERROR_H
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COM_ERROR_AR_RELEASE_MAJOR_VERSION  4
#define COM_ERROR_AR_RELEASE_MINOR_VERSION  0
#define COM_ERROR_AR_RELEASE_REVISION_VERSION  3

/* Software Version Information */
#define COM_ERROR_SW_MAJOR_VERSION  2
#define COM_ERROR_SW_MINOR_VERSION  2

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/* polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations>  */
#if(COM_DEV_ERROR_DETECT ==  STD_OFF)

#else

/* Check whether module is initialized */
#define COM_DET_INIT_STATUS_CHECK_FLAG(COM_API_SERVICEID)                     \
  do{                                                                         \
    if(Com_GddComStatus == COM_UNINIT)                                        \
    {                                                                         \
      (void)Det_ReportError (COM_MODULE_ID, COM_INSTANCE_ID,                  \
                                    COM_API_SERVICEID, COM_E_UNINIT);         \
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;                      \
    }                                                                         \
  }while(0)
  
/* Check whether Tx PDU ID is out of range */
#define COM_DET_TXPDUID_RANGE_CHECK_FLAG(ComTxPduId,                          \
                                             COM_API_SERVICEID)               \
  do{                                                                         \
    if((ComTxPduId) >= COM_TX_IPDU_COUNT)                                     \
    {                                                                         \
      (void)Det_ReportError (COM_MODULE_ID, COM_INSTANCE_ID,                  \
                                     COM_API_SERVICEID, COM_E_PARAM);         \
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;                      \
    }                                                                         \
  }while(0)                                                                     

/* Check whether Rx PDU ID is out of range */
#define COM_DET_RXPDUID_RANGE_CHECK_FLAG(ComRxPduId,                          \
                                             COM_API_SERVICEID)               \
  do{                                                                         \
    if((ComRxPduId) >= COM_RX_IPDU_COUNT)                                     \
    {                                                                         \
      (void)Det_ReportError (COM_MODULE_ID, COM_INSTANCE_ID,                  \
                                     COM_API_SERVICEID, COM_E_PARAM);         \
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;                      \
    }                                                                         \
  }while(0)                                                                     

/* Check whether PduInfoPtr pointer is NULL */
#define  COM_DET_PDUINFOPTR_PTR_CHECK_FLAG(PduInfoPtr,COM_API_SERVICEID)      \
  do{                                                                         \
    if((PduInfoPtr) == NULL_PTR)                                              \
    {                                                                         \
      (void)Det_ReportError (COM_MODULE_ID, COM_INSTANCE_ID,                  \
                                     COM_API_SERVICEID, COM_E_PARAM_POINTER); \
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;                      \
    }                                                                         \
    else if(((PduInfoPtr)->SduDataPtr) == NULL_PTR)                           \
    {                                                                         \
      (void)Det_ReportError (COM_MODULE_ID, COM_INSTANCE_ID,                  \
        COM_API_SERVICEID, COM_E_PARAM_POINTER);                              \
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;                      \
    }                                                                         \
    else                                                                      \
    {                                                                         \
    }                                                                         \
  }while(0)                                                                     

/* Check whether Common pointer is NULL */
#define COM_DET_COMMON_PTR_CHECK_FLAG(CommonPtr,COM_API_SERVICEID)            \
  do{                                                                         \
    if((CommonPtr) == NULL_PTR)                                               \
    {                                                                         \
      (void)Det_ReportError (COM_MODULE_ID, COM_INSTANCE_ID,                  \
                                     COM_API_SERVICEID, COM_E_PARAM_POINTER); \
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;                      \
    }                                                                         \
    else                                                                      \
    {                                                                         \
    }                                                                         \
  }while(0)     

/* Check whether Common pointer is NULL */
#define COM_DET_COMMON_PTR_PARAM_CHECK_FLAG(CommonPtr,COM_API_SERVICEID)            \
  do{                                                                         \
    if((CommonPtr) == NULL_PTR)                                               \
    {                                                                         \
      (void)Det_ReportError (COM_MODULE_ID, COM_INSTANCE_ID,                  \
                                     COM_API_SERVICEID, COM_E_PARAM); \
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;                      \
    }                                                                         \
    else                                                                      \
    {                                                                         \
    }                                                                         \
  }while(0)     

/* Check whether PduInfoPtr pointer is NULL */
#define  COM_DET_IPDUGROUPVECTOR_CHECK_FLAG(COM_API_SERVICEID)                \
  do{                                                                         \
    if(ipduGroupVector == NULL_PTR)                                           \
    {                                                                         \
      (void)Det_ReportError (COM_MODULE_ID, COM_INSTANCE_ID,                  \
                                     COM_API_SERVICEID, COM_E_PARAM_POINTER); \
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;                      \
    }                                                                         \
  }while(0)                                                                   
  
/* Check whether signal ID is out of range */
#define  COM_DET_RX_SIGNALID_RANGE_CHECK_FLAG(COM_API_SERVICEID)              \
  do{                                                                         \
    if(SignalId >= (COM_RX_SIGNAL_COUNT + COM_RX_SIGINGROUP_COUNT))           \
    {                                                                         \
      (void)Det_ReportError (COM_MODULE_ID, COM_INSTANCE_ID,                  \
                                     COM_API_SERVICEID, COM_E_PARAM);         \
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;                      \
    }                                                                         \
  }while(0)                                                                     


/* Check whether signal ID is out of range */
#define  COM_DET_TX_SIGNALID_RANGE_CHECK_FLAG(COM_API_SERVICEID)              \
  do{                                                                         \
    if(SignalId >= (COM_TX_SIGNAL_COUNT + COM_TX_SIGINGROUP_COUNT))           \
    {                                                                         \
      (void)Det_ReportError (COM_MODULE_ID, COM_INSTANCE_ID,                  \
                                     COM_API_SERVICEID, COM_E_PARAM);         \
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;                      \
    }                                                                         \
  }while(0)                                                                     


/* Check whether signal group ID is out of range */
#define  COM_DET_RXSIGNALGROUPID_RANGE_CHECK_FLAG(COM_API_SERVICEID)          \
  do{                                                                         \
    if(SignalGroupId >= COM_RX_SIGGROUP_COUNT)                                \
    {                                                                         \
      (void)Det_ReportError (COM_MODULE_ID, COM_INSTANCE_ID,                  \
                                     COM_API_SERVICEID, COM_E_PARAM);         \
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;                      \
    }                                                                         \
  }while(0)                                                                     
/* Check whether signal group ID is out of range */
#define  COM_DET_TXSIGNALGROUPID_RANGE_CHECK_FLAG(COM_API_SERVICEID)          \
  do{                                                                         \
    if(SignalGroupId >= COM_TX_SIGGROUP_COUNT)                                \
    {                                                                         \
      (void)Det_ReportError (COM_MODULE_ID, COM_INSTANCE_ID,                  \
                                     COM_API_SERVICEID, COM_E_PARAM);         \
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;                      \
    }                                                                         \
  }while(0)                                                                     

/* Check whether signal group ID is out of range */
#define  COM_DET_SIGNALID_TX_USS_RANGE_CHECK_FLAG(COM_API_SERVICEID)          \
  do{                                                                         \
    if(SignalId >= (Com_SignalIdType)(COM_TX_SIG_GRPSIG_BOUNDARY +            \
      (Com_SignalIdType)COM_TX_SIGINGROUP_COUNT))                             \
    {                                                                         \
      (void)Det_ReportError (COM_MODULE_ID, COM_INSTANCE_ID,                  \
                                     COM_API_SERVICEID, COM_E_PARAM);         \
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;                      \
    }                                                                         \
  }while(0)                                                                     

/* Check whether signal group ID is out of range */
#define  COM_DET_SIGNALID_RX_USS_RANGE_CHECK_FLAG(COM_API_SERVICEID)          \
  do{                                                                         \
    if(SignalId >= (Com_SignalIdType)(COM_RX_SIG_GRPSIG_BOUNDARY +            \
      (Com_SignalIdType)COM_RX_SIGINGROUP_COUNT))                             \
    {                                                                         \
      (void)Det_ReportError (COM_MODULE_ID, COM_INSTANCE_ID,                  \
                                     COM_API_SERVICEID, COM_E_PARAM);         \
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;                      \
    }                                                                         \
  }while(0)                                                                     


/* Check whether signal data pointer is out of range */
#define  COM_DET_SIGNAL_DATA_PTR(COM_API_SERVICEID)                           \
  do{                                                                         \
    if(SignalDataPtr == NULL_PTR)                                             \
    {                                                                         \
      (void)Det_ReportError (COM_MODULE_ID, COM_INSTANCE_ID,                  \
                                     COM_API_SERVICEID, COM_E_PARAM_POINTER); \
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;                      \
    }                                                                         \
  }while(0)                                                                     


/* Check whether I-PDU group ID is out of range */
#define  COM_DET_IPDUGROUPID_RANGE_CHECK_FLAG(COM_API_SERVICEID)              \
  do{                                                                         \
    if(IpduGroupId >= COM_IPDUGROUP_COUNT)                                    \
    {                                                                         \
      (void)Det_ReportError (COM_MODULE_ID, COM_INSTANCE_ID,                  \
                                     COM_API_SERVICEID, COM_E_PARAM);         \
      LucReturnValue = (uint8)COM_SERVICE_NOT_AVAILABLE;                      \
    }                                                                         \
  }while(0)                                                                     

#endif /* checking weather DET error check is ON */
/* polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations>  */

#endif /* COM_ERROR_H  */
/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
