/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf_Error.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : The file contains the Development Error Tracer code helping   **
**              to findout the error occurred within the CanIf module during  **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By              Description                        **
********************************************************************************
** 2.5.0    06-Dec-2016    Js.Lim     #7077                                   **
** 2.4.3    29-Nov-2016    Js.Lim     #6744                                   **
** 2.2.2    15-Mar-2016    Kt.Kim     #4386                                   **
** 2.2.1    13-Jun-2015    Kt.Kim     Improvement #2724                       **
** 2.2.0    02-Jul-2013    Kt.Kim     Lib-Build Support                       **
** 1.0.0    04-Feb-2013    Kt.Kim     Initial version                         **
*******************************************************************************/
#ifndef CANIF_ERROR_H
#define CANIF_ERROR_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf_Cfg.h"                /* Configuration header file */
#include "CanIf_Types.h"              /* Header file for config Ptr type */
#include "CanIf.h"                    /* Header file for Fr Module */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANIF_ERROR_AR_RELEASE_MAJOR_VERSION     ((uint8)4)
#define CANIF_ERROR_AR_RELEASE_MINOR_VERSION     ((uint8)0)
#define CANIF_ERROR_AR_RELEASE_REVISION_VERSION  ((uint8)3)

/* Software Version Information */
#define CANIF_ERROR_SW_MAJOR_VERSION  ((uint8)2)
#define CANIF_ERROR_SW_MINOR_VERSION  ((uint8)5)

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/*  polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations>
    No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1236)       */

#if (STD_ON == CANIF_DEV_ERROR_DETECT)
/* This Error code is used when CanIf module is not initialized */
#define CANIF_GLOBAL_INIT_STATUS_ERROR(CANIF_API_ID, LenStdRetVal)              \
  do{                                                                           \
    switch(CanIf_GblCanIfStatus)                                                \
    {                                                                           \
      case CANIF_UNINITIALISED:                                                 \
        (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID, \
                                                               CANIF_E_UNINIT); \
        (LenStdRetVal) = (uint8)E_NOT_OK;                                       \
        break;                                                                    \
      default:                                                                \
        break;                                                                \
    };                                                                           \
  }while(0)

/* This Error code is used when controller id has invalid Id */
#define CANIF_CONTROLLER_RANGE_ERROR(CANIF_API_ID, LenStdRetVal)                \
  do{                                                                           \
    if(ControllerId > CANIF_NO_OF_CONTROLLER)                                   \
    {                                                                           \
      (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,   \
                                                 CANIF_E_PARAM_CONTROLLERID);   \
      (LenStdRetVal) = (uint8)E_NOT_OK;                                         \
    }                                                                           \
  }while(0)

/* This Error code is used when controller Mode is invalid or out of defined
   values or CANIF_CS_UNINIT */
#define CANIF_INVALID_CONTROLLER_MODE_ERROR(CANIF_API_ID, LenStdRetVal)             \
  do{                                                                               \
      switch(ControllerMode)                                                    \
      {                                                                         \
        case CANIF_CS_SLEEP:                                                    \
        break;                                                                  \
        case CANIF_CS_STARTED:                                                  \
        break;                                                                  \
        case CANIF_CS_STOPPED:                                                  \
        break;                                                                  \
        case CANIF_CS_UNINIT:                                                   \
        default:                                                                \
          (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,   \
                                                      CANIF_E_PARAM_CTRLMODE);      \
          (LenStdRetVal) = (uint8)E_NOT_OK;                                     \
          break;                                                                \
      };                                                                         \
  }while(0)
/* This Error code is used when DLC is incorrect */
#define CANIF_CANIDTYPE_DLC_ERROR(CANIF_API_ID, LenStdRetVal)                  \
  do{                                                                         \
if (((uint8)E_OK == (LenStdRetVal)) && ((NULL_PTR != PduInfoPtr) &&              \
                               (PduInfoPtr->SduLength > (uint8)CANIF_EIGHT)))  \
{                                                                              \
  (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,            \
                                                            CANIF_E_PARAM_DLC);\
  (LenStdRetVal) = (uint8)E_NOT_OK;                                              \
}                                                                              \
  }while(0)

/* This Error code is used when SDU length is incorrect */
#define CANIF_VALID_SDU_LENGTH(CANIF_API_ID, LenStdRetVal)                     \
  do{                                                                         \
if  (((uint8)E_OK == (LenStdRetVal)) && (NULL_PTR != PduInfoPtr))                \
{                                                                              \
  if ((PduInfoPtr->SduLength) > (uint8)CANIF_EIGHT)                            \
  {                                                                            \
    (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,          \
                                                         CANIF_E_PARAM_DLC);   \
    (LenStdRetVal) = (uint8)E_NOT_OK;                                            \
  }                                                                            \
}                                                                              \
  }while(0)

#if (STD_ON == CANIF_CANFD_SUPPORT)
/* This Error code is used when SDU length is incorrect */
#define CANIF_CANFD_VALID_SDU_LENGTH(CANIF_API_ID, LenStdRetVal)                \
  do{                                                                         \
if  (((uint8)E_OK == (LenStdRetVal)) && (NULL_PTR != PduInfoPtr))                \
{                                                                              \
  if ((PduInfoPtr->SduLength) > (uint8)CANIF_CANFD_MAX_LENGTH)                  \
  {                                                                            \
    (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,          \
                                                         CANIF_E_PARAM_DLC);   \
    (LenStdRetVal) = (uint8)E_NOT_OK;                                            \
  }                                                                            \
}                                                                              \
  }while(0)
#endif

/* This Error code is used when Transceiver ID is not defined */
#define CANIF_INVALID_TRANSCEIVERID_ERROR(CANIF_API_ID, LenStdRetVal)          \
  do{                                                                         \
if (((uint8)E_OK == (LenStdRetVal)) && (LpCanTrcv->ucCanIfCanTrcvId !=           \
                                                              TransceiverId))  \
{                                                                              \
  (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,            \
                                                          CANIF_E_PARAM_TRCV); \
  (LenStdRetVal) = (uint8)E_NOT_OK;                                              \
}                                                                              \
  }while(0)
/* This Error code is used when Transceiver ID is Invalid */
#define CANIF_TRANSCEIVERID_RANGE_ERROR(CANIF_API_ID, LenStdRetVal)            \
  do{                                                                         \
if (TransceiverId >= (uint8)CANIF_NO_OF_TRANSCEIVER)                           \
{                                                                              \
  (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,            \
                                                           CANIF_E_PARAM_TRCV);\
  (LenStdRetVal) = (uint8)E_NOT_OK;                                              \
}                                                                              \
  }while(0)
/* This Error code is used when transition of Transceiver mode is prohibited */
#define CANIF_TRCV_MODE_SLEEP_STANDBY_ERROR(CANIF_API_ID, LucCurrentOpMode,    \
                                               TransceiverMode, LenStdRetVal)  \
  do{                                                                         \
if (((uint8)E_OK == (LenStdRetVal)) &&                                           \
     (((uint8) CANTRCV_TRCVMODE_SLEEP == (LucCurrentOpMode)) &&                  \
          ((CanTrcv_TrcvModeType)CANTRCV_TRCVMODE_STANDBY == (TransceiverMode))))\
{                                                                              \
  (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,             \
                                                      CANIF_E_PARAM_TRCVMODE); \
 (LenStdRetVal) = (uint8)E_NOT_OK;                                               \
}                                                                              \
  }while(0)

/* This Error code is used when transition of Transceiver mode is prohibited */
#define CANIF_TRCV_MODE_SLEEP_NORMAL_ERROR(CANIF_API_ID, LucCurrentOpMode,     \
                                             TransceiverMode, LenStdRetVal)    \
  do{                                                                         \
if (((uint8)E_OK == (LenStdRetVal)) &&                                           \
   (((uint8) CANTRCV_TRCVMODE_NORMAL == (LucCurrentOpMode)) &&                   \
            ((CanTrcv_TrcvModeType)CANTRCV_TRCVMODE_SLEEP == (TransceiverMode))))\
{                                                                              \
  (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,             \
                                                    CANIF_E_PARAM_TRCVMODE);   \
 (LenStdRetVal) = (uint8)E_NOT_OK;                                               \
}                                                                              \
  }while(0)

/* This Error code is used when Transceiver mode is invalid */
#define CANIF_TRCV_MODE_INVALID_ERROR(CANIF_API_ID,                             \
                                             TransceiverMode, LenStdRetVal)     \
  do{                                                                           \
    switch(TransceiverMode)                                                     \
    {                                                                           \
      case CANTRCV_TRCVMODE_STANDBY:                                            \
        break;                                                                  \
      case CANTRCV_TRCVMODE_NORMAL:                                             \
        break;                                                                  \
      case CANTRCV_TRCVMODE_SLEEP:                                              \
        break;                                                                  \
      default:                                                                  \
        (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID, \
                                                    CANIF_E_PARAM_TRCVMODE);    \
        (LenStdRetVal) = (uint8)E_NOT_OK;                                       \
          break;                                                                \
    };                                                                           \
  }while(0)

/* This Error code is used when Pdu Mode is invalid */
#define CANIF_INVALID_PDU_MODE_REQ_ERROR(CANIF_API_ID, LenStdRetVal)            \
  do{                                                                           \
      switch(PduModeRequest)                                                    \
      {                                                                         \
        case CANIF_SET_OFFLINE:                                                 \
        break;                                                                  \
        case CANIF_SET_ONLINE:                                                  \
        break;                                                                  \
        case CANIF_SET_RX_OFFLINE:                                              \
        break;                                                                  \
        case CANIF_SET_RX_ONLINE:                                               \
        break;                                                                  \
        case CANIF_SET_TX_OFFLINE:                                              \
        break;                                                                  \
        case CANIF_SET_TX_OFFLINE_ACTIVE:                                       \
        break;                                                                  \
        case CANIF_SET_TX_ONLINE:                                               \
          break;                                                                \
        default:                                                                \
          (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID, \
                                                       CANIF_E_PARAM_PDU_MODE);   \
          (LenStdRetVal) = (uint8)E_NOT_OK;                                       \
          break;                                                                \
      };                                                                           \
  }while(0)
/* This Error code is used when Hrh is invalid */
#define CANIF_INVALID_HRH_ERROR(CANIF_API_ID, Hrh, LenStdRetVal)               \
  do{                                                                         \
if (((Hrh) > CanIf_GaaHrhArrayId[CANIF_ZERO]) ||                                 \
                                 (CANIF_INVALID == CanIf_GaaHrhMapArray[(Hrh)])) \
{                                                                              \
   (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,           \
                                                            CANIF_E_PARAM_HRH);\
   (LenStdRetVal) = (uint8)E_NOT_OK;                                             \
}                                                                              \
  }while(0)
/* This Error code is used when CanId is invalid */
#define CANIF_INVALID_STANDARD_CANID_ERROR(CANIF_API_ID, LenStdRetVal)         \
  do{                                                                         \
  if ((((uint8)CANIF_RX_BASIC_CAN_STD == LucSftwrFltrng) ||                   \
                      ((uint8)CANIF_RX_FULL_CAN_STD == LucSftwrFltrng)) &&    \
                                      (CanId >  CANIF_STANDARD_CANID_VALUE) && \
                                 ((CanId & CANIF_STANDARD_FD_VALUE)== CANIF_ZERO))  \
  {                                                                            \
    (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,          \
                                                       CANIF_E_PARAM_CANID);   \
    (LenStdRetVal) = (uint8)E_NOT_OK;                                            \
  }                                                                              \
  }while(0)

#define CANIF_INVALID_EXTENDED_CANID_ERROR(CANIF_API_ID, LenStdRetVal)         \
  do{                                                                         \
  if ((((uint8)CANIF_RX_BASIC_CAN_EXT == LucSftwrFltrng) ||                    \
                      ((uint8)CANIF_RX_FULL_CAN_EXT == LucSftwrFltrng)) &&    \
                                        (CanId >  CANIF_EXTENDED_CANID_VALUE) && \
                             ((CanId & CANIF_EXTENDED_FD_VALUE)== CANIF_ZERO))  \
  {                                                                            \
    (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,          \
                                                      CANIF_E_PARAM_CANID);    \
    (LenStdRetVal) = (uint8)E_NOT_OK;                                            \
}                                                                              \
  }while(0)


/* This Error code is used RxPduId is out of range */
#define CANIF_RXPDUID_RANGE_ERROR(CANIF_API_ID, LenStdRetVal)                  \
  do{                                                                         \
if (CanRxPduId >= CanIf_GddPrecompOpt.ddNumOfRxPdu)                            \
{                                                                              \
  (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,            \
                                                   CANIF_E_INVALID_RXPDUID);   \
  (LenStdRetVal) = (uint8)E_NOT_OK;                                              \
}                                                                              \
  }while(0)
/* This Error code is used TxPduId is out of range */
#define CANIF_TXPDUID_RANGE_ERROR(CANIF_API_ID, LenStdRetVal)                  \
  do{                                                                         \
if (CanTxPduId >= (PduIdType)CanIf_GddPrecompOpt.ddNumOfTxPdu)                               \
{                                                                              \
  (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,            \
                                                    CANIF_E_INVALID_TXPDUID);  \
  (LenStdRetVal) = (uint8)E_NOT_OK;                                              \
}                                                                              \
  }while(0)

/* This Error code is used Lpdu is out of range */
#define CANIF_LPDU_RANGE_ERROR(CANIF_API_ID, LenStdRetVal)                     \
  do{                                                                         \
if (CanTxPduId >= (PduIdType)CanIf_GddPrecompOpt.ddNumOfTxPdu)                               \
{                                                                              \
  (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,            \
                                                    CANIF_E_PARAM_LPDU);       \
  (LenStdRetVal) = (uint8)E_NOT_OK;                                              \
}                                                                              \
  }while(0)


/* This Error code is used when CanId is out of range for Standard type */
#define CANIF_STD_CANID_ERROR(CANIF_API_ID, LenStdRetVal)                      \
  do{                                                                         \
if (CanId > (Can_IdType)CANIF_STANDARD_CANID_VALUE)                            \
{                                                                              \
  (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,                          \
                                            CANIF_API_ID, CANIF_E_PARAM_CANID);\
  (LenStdRetVal) = (uint8)E_NOT_OK;                                              \
}                                                                              \
  }while(0)
/* This Error code is used when CanId is out of range for extended type */
#define CANIF_EXTD_CANID_ERROR(CANIF_API_ID, LenStdRetVal)                     \
  do{                                                                         \
if  (CanId > (Can_IdType)CANIF_EXTENDED_CANID_VALUE)                           \
{                                                                              \
  (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,                          \
                             CANIF_API_ID, CANIF_E_PARAM_CANID);               \
  (LenStdRetVal) = (uint8)E_NOT_OK;                                              \
}                                                                              \
  }while(0)
/* This Error code is used notification value is out of range */
#define CANIF_NOTIFICATION_STATUS_ERROR(CANIF_API_ID, LenStdRetVal)            \
  do{                                                                         \
if ((uint8)CANIF_ZERO == LucNotifStsMask)                                      \
{                                                                              \
   (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,            \
                                                   CANIF_E_INVALID_TXPDUID);   \
   (LenStdRetVal) = (uint8)E_NOT_OK;                                             \
}                                                                              \
  }while(0)

/* This Error code is used when Controller mode is Uninit */
#define CANIF_UNINIT_CONTROLLER_MODE_ERROR(CANIF_API_ID, LenStdRetVal)         \
  do{                                                                         \
if (((uint8)E_OK == (LenStdRetVal)) && ((uint8)CANIF_CS_UNINIT ==                \
                                               LpController->ucControllerMode))\
{                                                                              \
  (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,            \
                                                             CANIF_E_UNINIT);  \
  (LenStdRetVal) = (uint8)E_NOT_OK;                                              \
}                                                                              \
  }while(0)
/* This Error code is used when TrcvWakeupMode is out of raange */
#define CANIF_INVALID_TRCV_WAKEUPMODE_ERROR(CANIF_API_ID, LenStdRetVal)        \
  do{                                                                         \
if (TrcvWakeupMode >  CANIF_TRCV_WU_CLEAR)                                     \
{                                                                              \
  (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,            \
                                                 CANIF_E_PARAM_TRCVWAKEUPMODE);\
  (LenStdRetVal) = (uint8)E_NOT_OK;                                              \
}                                                                              \
  }while(0)

/* This Error code is used when Pdu Mode is Offline or  controller mode is in stopped*/
#define CANIF_OFFLINE_PDU_STOPPED_CTRL_MODE(CANIF_API_ID, LenStdRetVal)                     \
  do{                                                                         \
if (((CANIF_TX_DISABLED == LucTxStatus) && (CANIF_RX_DISABLED == LucRxStatus)) \
                                       || (CANIF_TX_DISABLED == LucTxStatus) \
                                       || (CANIF_CS_STOPPED == LucCurrentMode))  \
{                                                                              \
  (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,            \
                                                             CANIF_E_STOPPED); \
  (LenStdRetVal) = (uint8)E_NOT_OK;                                              \
}                                                                              \
  }while(0)
/* This Error code is used when controller mode is in not in sleep */
#define CANIF_NOT_SLEEP_MODE_ERROR(CANIF_API_ID, LenStdRetVal)                 \
  do{                                                                         \
if ((uint8)CANIF_CS_SLEEP != LucCurrentMode)                                   \
{                                                                              \
  Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,            \
                                                           CANIF_E_NOT_SLEEP); \
  (LenStdRetVal) = (uint8)E_NOT_OK;                                              \
}                                                                              \
  }while(0)

/* This Error code is used when input parameter is NULL_PTR */
#define CANIF_NULL_PTR_ERROR(CANIF_API_ID, LenStdRetVal, CANIF_INPUT_PTR)      \
  do{                                                                         \
if ((CANIF_INPUT_PTR) == NULL_PTR)                                               \
{                                                                              \
  (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO, CANIF_API_ID,            \
                                                       CANIF_E_PARAM_POINTER); \
  (LenStdRetVal) = (uint8)E_NOT_OK;                                              \
}                                                                              \
  }while(0)
  
/* polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations>
   No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1236)  */
   
 #endif /* (STD_ON == CANIF_DEV_ERROR_DETECT) */
 
 #endif  /* CANIF_ERROR_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
