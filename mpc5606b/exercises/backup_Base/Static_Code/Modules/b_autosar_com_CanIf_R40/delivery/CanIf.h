/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf.h                                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : Provision of external declaration of APIs and Service Ids     **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
*******************************************************************************/
/*******************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 2.5.3    11-Sep-2017    Js.Lim    #9889                                    **
** 2.5.0    06-Dec-2016    Js.Lim    #6745, #7077                             **
** 2.2.6    12-Aug-2016    Kt.Kim    #5739                                    **
** 2.2.5    13-Jun-2016    Kt.Kim    #5139                                    **
** 2.2.4    05-Jan-2016    Kt.Kim    #3813                                    **
** 2.2.3    16-Dec-2015    Kt.Kim    Code fix for MISRA 14.2                  **
** 2.2.2    13-Jun-2015    Kt.Kim    #2724                                    **
** 2.1.0    29-May-2013    Kt.Kim    OsekNm Support                           **
** 1.0.0    04-Feb-2013    Kt.Kim    Initial version                          **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#ifndef CANIF_H
#define CANIF_H

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANIF_CANIF_AR_RELEASE_MAJOR_VERSION       4
#define CANIF_CANIF_AR_RELEASE_MINOR_VERSION       0
#define CANIF_CANIF_AR_RELEASE_REVISION_VERSION    3

/* Software Version Information */
#define CANIF_CANIF_SW_MAJOR_VERSION    2
#define CANIF_CANIF_SW_MINOR_VERSION    5
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComStack_Types.h"     /* STANDARD Types Header File */
#include "CanIf_Cfg.h"          /* Configuration header file */
#include "CanIf_Types.h"        /* Type definition header file */
#if (STD_ON == CANIF_AUTRON_CANTRCV_SUPPORT)
#include "CanTrcv.h"            /* CanTrcv header file */
#endif
#if (STD_ON == CANIF_EXTENAL_CANTRCV_SUPPORT)
#include "CanIf_CanTrcv.h"            /* CanTrcv header file */
#endif
#if (STD_ON == CANIF_WAKEUP_SUPPORT)
#include "EcuM.h"               /* EcuM header file */
#endif
#if (STD_ON == CANIF_PDUR_CALLBACK)
#include "PduR_CanIf.h"         /* PduR header file */
#endif
#if (STD_ON == CANIF_CANTP_CALLBACK)
#include "CanTp_Cbk.h"          /* CanTp header file */
#endif
#if (STD_ON == CANIF_CANNM_CALLBACK)
#include "CanNm_Cbk.h"          /* CanNm header file */
#endif
#if ((STD_ON == CANIF_TX_XCP_CALLBACK) || (STD_ON == CANIF_RX_XCP_CALLBACK))
#include "Xcp_Cbk.h"            /* Xcp header file */
#endif
#if ((STD_ON == CANIF_TX_J1939TP_CALLBACK) || \
                                          (STD_ON == CANIF_RX_J1939TP_CALLBACK))
#include "J1939Tp_Cbk.h"        /* J1939Tp header file */
#endif
/* #5139 */
#if ((STD_ON == CANIF_TX_J1939NM_CALLBACK) || \
                                          (STD_ON == CANIF_RX_J1939NM_CALLBACK))
#include "J1939Nm_Cbk.h"        /* J1939Nm header file */
#endif
#include "CanIf_UserInc.h"
#include "CanIf_Dbg.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/
/* Invalid CAN ID is reported using following error code */
#define CANIF_E_PARAM_CANID            ((uint8)10)

/* Invalid DLC is reported using following error code */
#define CANIF_E_PARAM_DLC              ((uint8)11)

/* Invalid HRH is reported using following error code */
#define CANIF_E_PARAM_HRH              ((uint8)12)

/* Invalid controller ID is reported using following error code */
#define CANIF_E_PARAM_CONTROLLER       ((uint8)14)

/* Invalid controller ID is reported using following error code */
#define CANIF_E_PARAM_CONTROLLERID     ((uint8)15)

/* Invalid wakeup source ID is reported using following error code*/
#define CANIF_E_PARAM_WAKEUPSOURCE     ((uint8)16)

/* Invalid mode request is reported using following error code */
#define CANIF_E_PARAM_TRCV             ((uint8)17)

/* Invalid pointer input is reported using following error code */
#define CANIF_E_PARAM_TRCVMODE         ((uint8)18)

/* API service called with wrong database addresss */
#define CANIF_E_PARAM_TRCVWAKEUPMODE   ((uint8)19)

/* API service used without module initialization */
#define CANIF_E_PARAM_CTRLMODE         ((uint8)21)

/* DET error used with parameter passed as null pointer */
#define CANIF_E_PARAM_POINTER          ((uint8)20)

/* DET error reported when module is unintialized */
#define CANIF_E_UNINIT                 ((uint8)30)

/* Not supported API request is reported using following error code */
#define CANIF_E_INVALID_TXPDUID        ((uint8)50)

/* Invalid Transceiver Id */
#define CANIF_E_INVALID_RXPDUID        ((uint8)60)

/* Invalid CAN Transceiver operation Mode */
#define CANIF_E_INVALID_DLC            ((uint8)61)

/* Invalid PDU Mode */
#define CANIF_E_PARAM_PDU_MODE         ((uint8)22)

/* Invalid LPDU*/
#define CANIF_E_PARAM_LPDU             ((uint8)13)

/* Invalid CAN Transceiver operation Mode */
#define CANIF_E_STOPPED                ((uint8)70)

/* Invalid Tx-Pdu ID is reported using following error code */
#define CANIF_E_NOT_SLEEP              ((uint8)71)

/* Macro to check whether wake up is disabled */
#define CANIF_WAKEUP_DISABLED          ((uint8)0x00)

/* Macro to check whether wake up is enabled */
#define CANIF_WAKEUP_ENABLED           ((uint8)0x01)

/* Macro to check for invalid value */
#define CANIF_INVALID                  ((PduIdType)0xff)

/* Macro for error id for transciever */
#define CANIF_E_TRANSCEIVER            ((uint8)91)

/* macro for invalid rxpduid */
#define CANIF_INVALID_RXPDUID          ((PduIdType)0xffff)

/* macro for gateway buffer state */
#define CANIF_GW_NOREQUEST   ((uint8)0x00)
#define CANIF_GW_STOPPED     ((uint8)0x01)
#define CANIF_GW_REQUESTED   ((uint8)0x02)
#define CANIF_GW_NOCOMM      ((uint8)0x03)
#define CANIF_GW_ERRVOL      ((uint8)0x04)

/* Macro for Cancellation unsed */
#define CANIF_AUTRON_AUTOSAR_CANCELLATION_USED (STD_OFF)

/*******************************************************************************
**                      Service Id of API                                     **
*******************************************************************************/
/* Service ID for CanIf_Init */
#define CANIF_INIT_SID                        ((uint8)0x01)
/* Service ID for CanIf_SetController */
#define CANIF_SET_CNTRL_MODE_SID              ((uint8)0x03)
/* Service ID for CanIf_GetControllerMode */
#define CANIF_GET_CNTRL_MODE_SID              ((uint8)0x04)
/* Service ID for CanIf_Transmit */
#define CANIF_TRANSMIT_SID                    ((uint8)0x05)
/* Service ID for CanIf_CancelTransmit */
#define CANIF_CANCEL_TRANSMIT_SID             ((uint8)0x18)
/* Service ID for CanIf_ReadRxPduData */
#define CANIF_READ_RXPDU_DATA_SID             ((uint8)0x06)
/* Service ID for CanIf_ReadTxNotifStatus */
#define CANIF_READ_TX_NOTIF_STATUS_SID        ((uint8)0x07)
/* Service ID for CanIf_ReadRxNotifStatus */
#define CANIF_READ_RX_NOTIF_STATUS_SID        ((uint8)0x08)
/* Service ID for CanIf_SetPduMode */
#define CANIF_SET_PDU_MODE_SID                ((uint8)0x09)
/* Service ID for CanIf_GetPduMode */
#define CANIF_GET_PDU_MODE_SID                ((uint8)0x0a)
/* Service ID for CanIf_VersionInfo */
#define CANIF_GET_VERSIONNFO_SID              ((uint8)0x0b)
/* Service ID for CanIf_SetDynamicTxId */
#define CANIF_SET_DYNAMIC_TXID_SID            ((uint8)0x0c)
/* Service ID for CanIf_GetTrcvWakeupReason */
#define CANIF_GET_TRCV_WAKEUPREASON_SID       ((uint8)0x0f)
/* Service ID for CanIf_SetTransceiverWakeupMode */
#define CANIF_SET_TRCV_WAKEUP_MODE_SID        ((uint8)0x10)
/* Service ID for CanIf_CheckWakeup */
#define CANIF_CHECK_WAKEUP_SID                ((uint8)0x11)
/* Service ID for CanIf_CheckValidation */
#define CANIF_CHECK_VALIDATION_SID            ((uint8)0x12)
/* Service ID for CanIf_TxConfirmation */
#define CANIF_TX_CONFIRMATION_SID             ((uint8)0x13)
/* Service ID for CanIf_RxIndication */
#define CANIF_RX_INDICATION_SID               ((uint8)0x14)
/* Service ID for CanIf_CancelTxConfirmation */
#define CANIF_CANCEL_TX_CONFRM_SID            ((uint8)0x15)
/* Service ID for CanIf_ControllerBusOff */
#define CANIF_CNTRL_BUS_OFF_SID               ((uint8)0x16)
/* Service ID for CanIf_ControllerModeIndication */
#define CANIF_CTRL_MODE_IND_SID               ((uint8)0x17)
/* Service ID for CanIf_ClearTrcvWufFlag */
#define CANIF_CLEAR_TRCV_WUF_SID              ((uint8)0x1e)
/* Service ID for CanIf_CheckTrcvWakeFlag */
#define CANIF_CHECK_TRCV_WAKE_SID             ((uint8)0x1f)
/* Service ID for CanIf_CheckTrcvWakeFlagIndication */
#define CANIF_CHECK_TRCV_WAKE_FLAG_IND_SID    ((uint8)0x21)
/* Service ID for CanIf_TrcvModeIndication */
#define CANIF_TRCV_MODE_IND_SID               ((uint8)0x22)
/* Service ID for CanIf_ConfirmPnAvailability */
#define CANIF_CONFIRM_PN_AVAILIBILITY_SID     ((uint8)0x1a)
/* Service ID for CanIf_ClearTrcvWufFlagIndication */
#define CANIF_CLEAR_TRCV_WAKE_FLAG_IND_SID    ((uint8)0x20)
/* Service ID for CanIf_GetTxConfirmationState */
#define CANIF_GET_TX_CONFIRM_STATE_SID        ((uint8)0x19)
/* Service ID for CanIf_CheckBaudrate */
#define CANIF_CHECK_BAUD_RATE_SID             ((uint8)0x1c)
/* Service ID for CanIf_ChangeBaudrate */
#define CANIF_CHANGE_BAUD_RATE_SID            ((uint8)0x1b)
/* Service ID for CanIf_SetTrcvMode */
#define CANIF_SET_TRCV_MODE_SID               ((uint8)0x0d)
/* Service ID for CanIf_GetTrcvMode */
#define CANIF_GET_TRCV_MODE_SID               ((uint8)0x0e)
/* Instance ID */
#define CANIF_INSTANCE_ID                     ((uint8)0x00)

/*******************************************************************************
**                      Macro                                                 **
*******************************************************************************/
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> use function like-macro for removing unused argument compiler warning */
#define CANIF_UNUSED_PTR(x)                do { \
                                            if((x) != NULL_PTR) {} \
                                          } while(0)
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> use function like-macro for removing unused argument compiler warning */
#define CANIF_UNUSED(x)                            do { \
                                                    if((uint32)(x) != \
                                                    (uint32)CANIF_ZERO) {} \
                                                  } while(0)                                           

/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> use function like-macro for reduce execution time and stack */
#define CANIF_STORE_IN_QUEUE(x) do {                                              \
            LpTxQueue = &(CanIf_GddTxBuffCon.pTxQueue[(x)]);                   \
            LpTxQueue->ddTxLPduId = LddCanPduInfo.swPduHandle;                 \
            LpTxQueue->ucDlc = LddCanPduInfo.length;                           \
            LucCount = LddCanPduInfo.length;                                   \
            LpTxQueue->ddCanId = LddCanPduInfo.id;                             \
            while ((uint8)CANIF_ZERO != LucCount)                      \
            {                                                                  \
              LucCount--;                                              \
              LpTxQueue->aaTxBuffer[LucCount] = LddCanPduInfo.sdu[LucCount];                        \
            };                                                                  \
} while(0)

/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> use function like-macro for reduce execution time and stack */
#define CANIF_TXPDU_GW_STATUS(x) (CanIf_GaaTxPduGwStatus[(x)]) 
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_Init (P2CONST(CanIf_ConfigType, AUTOMATIC,
                                                   CANIF_APPL_CONST) ConfigPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_SetControllerMode (
                       VAR(uint8, CANIF_VAR) ControllerId, 
                       VAR(CanIf_ControllerModeType, CANIF_VAR) ControllerMode);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_GetControllerMode (
 VAR(uint8, CANIF_VAR) ControllerId, 
 P2VAR(CanIf_ControllerModeType, AUTOMATIC, CANIF_APPL_DATA) ControllerModePtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#if (STD_ON == CANIF_TX_LPDU)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit (
                  VAR(PduIdType, CANIF_VAR) CanTxPduId,
                  P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_CANCEL_TRANSMIT_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CancelTransmit (
                                          VAR(PduIdType, CANIF_VAR) CanTxPduId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_READRXPDU_DATA_API)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReadRxPduData (
                     VAR(PduIdType, CANIF_VAR) CanRxPduId,
                     P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if ((STD_ON == CANIF_TX_LPDU) && (STD_ON == CANIF_READTXPDU_NOTIFY_STATUS_API))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadTxNotifStatus (
                                          VAR(PduIdType, CANIF_VAR) CanTxPduId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_READRXPDU_NOTIFY_STATUS_API)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadRxNotifStatus(
                                          VAR(PduIdType, CANIF_VAR) CanRxPduId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode (
                           VAR(uint8, CANIF_VAR) ControllerId, 
                           VAR(CanIf_PduSetModeType, CANIF_VAR) PduModeRequest);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_GetPduMode (
            VAR(uint8, CANIF_VAR) ControllerId,
            P2VAR(CanIf_PduGetModeType, AUTOMATIC, CANIF_APPL_DATA) PduModePtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#if (STD_ON == CANIF_VERSION_INFO_API)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE)CanIf_GetVersionInfo 
           (P2VAR(Std_VersionInfoType, AUTOMATIC, CANIF_APPL_DATA)VersionInfo);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if ((STD_ON == CANIF_TX_LPDU) && (STD_ON == CANIF_SETDYNAMICTXID_API))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE)CanIf_SetDynamicTxId (
                                           VAR(PduIdType, CANIF_VAR) CanTxPduId,
                                           VAR(Can_IdType, CANIF_VAR) CanId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_CANTRCV_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvMode (
                          VAR(uint8, CANIF_VAR) TransceiverId,
                          VAR(CanTrcv_TrcvModeType, CANIF_VAR) TransceiverMode);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_CANTRCV_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvMode
           (P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_VAR)TransceiverModePtr,
            VAR(uint8, CANIF_VAR) TransceiverId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_TRCV_WAKEUP_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason (
      VAR(uint8, CANIF_VAR) TransceiverId, 
      P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_VAR)TrcvWuReasonPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_TRCV_WAKEUP_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvWakeupMode (
                     VAR(uint8, CANIF_VAR) TransceiverId,
                     VAR(CanTrcv_TrcvWakeupModeType, CANIF_VAR) TrcvWakeupMode);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_WAKEUP_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckWakeup (
                            VAR(EcuM_WakeupSourceType, CANIF_VAR) WakeupSource);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_WAKEUP_CHECK_VALIDATION_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckValidation (
                            VAR(EcuM_WakeupSourceType, CANIF_VAR) WakeupSource);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_TXCONFIRM_POLLING_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(CanIf_NotifStatusType, CANIF_CODE)CanIf_GetTxConfirmationState (
                                            VAR(uint8, CANIF_VAR) ControllerId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if ((STD_ON == CANIF_PN_SUPPORT) && (STD_ON == CANIF_CANTRCV_SUPPORT))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag (
                                           VAR(uint8, CANIF_VAR) TransceiverId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if ((STD_ON == CANIF_PN_SUPPORT) && (STD_ON == CANIF_CANTRCV_SUPPORT))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckTrcvWakeFlag (
                                           VAR(uint8, CANIF_VAR) TransceiverId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_CHANGE_BAUDRATE_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckBaudrate (
                                            VAR(uint8, CANIF_VAR) ControllerId,
                                           CONST(uint16, CANIF_CONST) Baudrate);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ChangeBaudrate (
                                           VAR(uint8, CANIF_VAR) ControllerId,
                                           CONST(uint16, CANIF_CONST) Baudrate);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if ((STD_ON == CANIF_PN_SUPPORT) && (STD_ON == CANIF_CANTRCV_SUPPORT))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_CheckTrcvWakeFlagIndication (
                                           VAR(uint8, CANIF_VAR) TransceiverId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if ((STD_ON == CANIF_PN_SUPPORT) && (STD_ON == CANIF_CANTRCV_SUPPORT))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_ClearTrcvWufFlagIndication(
                                           VAR(uint8, CANIF_VAR) TransceiverId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_PN_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_ConfirmPnAvailability (
                                           VAR(uint8, CANIF_VAR) TransceiverId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

/* internally used for Direct OSKEK NM */
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void,CANIF_CODE) CanIf_ReadRxCanId
           (P2VAR(Can_IdType, AUTOMATIC, CANIF_APPL_DATA) CanIdPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetBatteryVoltageMode( VAR(uint8, CANIF_VAR) ControllerId,
    VAR(CanIf_BatVolSetModeType, CANIF_VAR) BatteryVolMode);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"


#endif /* CANIF_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
