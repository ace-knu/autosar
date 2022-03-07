/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf_IntTypes.h                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : Provision of AUTOSAR CanIf Structure type definitions         **
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
** 2.5.4    11-Oct-2017    C.Kim     #9850                                    **
** 2.5.2    17-Apr-2017    Js.Lim    #8220                                    **
** 2.5.1    23-Mar-2017    Js.Lim    #7042, #8007                             **
** 2.5.0    06-Dec-2016    Js.Lim    #6745, #7077                             **
** 2.3.8    12-Aug-2016    Kt.Kim    #5739                                    **
** 2.3.7    12-Jun-2016    Kt.Kim    #5139                                    **
** 2.3.6    18-Mar-2016    Kt.Kim    #4442                                    **
** 2.3.5    11-Mar-2016    Kt.Kim    #4386                                    **
** 2.3.4    14-Dec-2015    Kt.Kim    #3464                                    **
** 2.3.3    19-Jun-2015    Kt.Kim    Correction for MISRA                     **
** 2.2.0    30-May-2013    Kt.Kim    Lib-Build Support                        **
** 2.1.0    29-May-2013    Kt.Kim    OsekNm Support                           **
** 1.0.0    04-Feb-2013    Kt.Kim    Initial version                          **
*******************************************************************************/

#ifndef CANIF_INTTYPES_H
#define CANIF_INTTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "CanIf.h"                      /* CAN Interface header file */
#if (STD_ON == CANIF_PDUR_CALLBACK)
#include "PduR_CanIf.h"                 /* Call-back PduR header file */
#endif
#if (STD_ON == CANIF_CANTP_CALLBACK)
#include "CanTp_Cbk.h"                  /* Call-back CanTp header file */
#endif
#if (STD_ON == CANIF_CANNM_CALLBACK)
#include "CanNm_Cbk.h"                  /* Call-back CannM header file */
#endif
#if (STD_ON == CANIF_CANTRCV_SUPPORT)
#include "CanIf_CanTrcv.h"              /* Call-back CanTrcv header file */
#endif
#if (STD_ON == CANIF_DEV_ERROR_DETECT)
#include "Det.h"                        /* DET header file */
#endif
#include "CanIf_UserInc.h"              /* CanIf User included header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANIF_INT_AR_RELEASE_MAJOR_VERSION       (4)
#define CANIF_INT_AR_RELEASE_MINOR_VERSION       (0)
#define CANIF_INT_AR_RELEASE_REVISION_VERSION    (3)

/* Software Version Information */
#define CANIF_INT_SW_MAJOR_VERSION    (2)
#define CANIF_INT_SW_MINOR_VERSION    (5)
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define CANIF_BLOCK                               ((uint8)0x10)

#define CANIF_TX_PN_MASK                          ((uint8)0x10)

#define CANIF_ZERO                                (0x00)

#define CANIF_ONE                                 (0x01)

#define CANIF_TWO                                 (0x02)

#define CANIF_SEVEN                               (0x07)

#define CANIF_EIGHT                               (0x08)

#define CANIF_NINE                                (0x09)

/* #8007 */
#define CANIF_THIRTYTWO                           (0x20)

#define CANIF_16                                  (0x10)

#define CANIF_INITIALISED                   ((uint8)0x01)

#define CANIF_UNINITIALISED                 ((uint8)0x00)

#define CANIF_TRUE                          ((uint8)0x01)

#define CANIF_FALSE                         ((uint8)0x00)

#define CANIF_RANGE_SUCCESS                 ((uint8)0x80)

#define CANIF_FAILURE                       ((uint8)0x00)

#define CANIF_MAX_DLC                       ((uint8)0x08)

#define CANIF_FULL_CAN                      ((uint8)0x01)

#define CANIF_BASIC_CAN                     ((uint8)0x00)

#define CANIF_RX_BASIC_CAN_STD              ((uint8)0x00)

#define CANIF_RX_BASIC_CAN_EXT              ((uint8)0x01)

#define CANIF_RX_BASIC_CAN_MIXED            ((uint8)0x02)

#define CANIF_RX_FULL_CAN_STD               ((uint8)0x03)

#define CANIF_RX_FULL_CAN_EXT               ((uint8)0x04)

#define CANIF_RX_FULL_CAN_MIXED             ((uint8)0x05)

#define CANIF_MAX_UL                        ((uint8)0x08)

#define CANIF_WAKEUP_VALIDATION_VALUE       ((uint8)0x81)

#define CANIF_PDUR                         ((uint8)0x00)

#define CANIF_CANTP                         ((uint8)0x01)

#define CANIF_CANNM                         ((uint8)0x02)

#define CANIF_CDD                           ((uint8)0x03)

#define CANIF_J1939TP                       ((uint8)0x04)

#define CANIF_XCP                           ((uint8)0x05)

#define CANIF_OSEKNM                        ((uint8)0x06)
/* #5139 */
#define CANIF_J1939NM                       ((uint8)0x07)

#define CANIF_STANDARD_CANID_VALUE          ((uint32) 0x7FF)

#define CANIF_EXTENDED_CANID_VALUE          ((uint32)0x9FFFFFFFU)

#define CANIF_CANDRV_WAKEUPSOURCE           ((uint8)0x00)

#define CANIF_CANTRCV_WAKEUPSOURCE          ((uint8)0x01)

#define CANIF_STANDARD_CANID_TYPE           ((uint8) 0x00)

#define CANIF_EXTENDED_CANID_TYPE           ((uint8) 0x01)

#define CANIF_MIXED_CANID_TYPE              ((uint8) 0x02)

#define CANIF_CANFD_STANDARD_CANID_TYPE     ((uint8) 0x03)

#define CANIF_CANFD_EXTENDED_CANID_TYPE     ((uint8) 0x04)

#define CANIF_CANFD_MIXED_CANID_TYPE        ((uint8) 0x05)

#define CANIF_CONTROLLER_WAKEUP_ON                    (1)

#define CANIF_CONTROLLER_WAKEUP_OFF                    (0)

#define CANIF_RX_DISABLED                   ((uint8) 0x00)

#define CANIF_RX_ENABLED                    ((uint8) 0x01)

#define CANIF_TX_DISABLED                   ((uint8) 0x00)

#define CANIF_TX_ENABLED                    ((uint8) 0x01)

#define CANIF_TX_OFFLINE_ACTIVE             ((uint8) 0x02)

#define CANIF_TX_ONLINE_ACTIVE              ((uint8) 0x08)

#define CANIF_TX_BAT_ERROR                  ((uint8) 0x01)
#define CANIF_TX_BAT_NORMAL                 ((uint8) 0x00)

#define CANIF_TRCV_INIT_MODE                ((uint8) 0xff)

/* #5139 */
#define CANIF_TWELVE                        ((uint8)12)

#define CANIF_FOUR                          ((uint8)4)

#define CANIF_THREE                         ((uint8)3)

#define CANIF_SIXTEEN                       ((uint8)16)

#define CANIF_TWENTY_FOUR                   ((uint8)24)

#define CANIF_CANID_MASK_ONE                ((uint8)0xFF)

#define CANIF_CANID_MASK_TWO                ((uint16)0xFFFF)

#define CANIF_MASK_BYTE_ONE                 ((uint16)0XFF00)

#define CANIF_CANID_MASK_FOUR               ((uint32)0x1FFFFFFF)

#define CANIF_MASK_BYTE_FOUR                ((uint32)0XFF000000)

#define CANIF_MASK_BYTE_THREE               ((uint32)0X00FF0000)

#define CANIF_EXTENDED_BIT_SET              0x80000000ul

/* mask for getting the Tx Status with Partial networking feature ON of the
   controller */
#define CANIF_TX_PNENABLED                 ((uint8) 0x10)

#define CANIF_CANFD_MAX_LENGTH             ((uint8) 0x40)
/* #5139 */
#define CANIF_MAX_META_PDU_DATA_LENGTH     ((uint8) 0x46)

#define CANIF_CANID_BYTE_MASK              ((uint32)0x000000FFU)
/* #8220 */
#if (STD_OFF == CANIF_CANFD_ID_16BIT_SUPPORT)
#define CANIF_STANDARD_FD_VALUE            ((uint32)0x40000000U)
#else
#define CANIF_STANDARD_FD_VALUE            ((uint32)0x00004000U)
#endif
#define CANIF_EXTENDED_FD_VALUE            ((uint32)0x40000000U)

/* type definitions for objects depends on CAN DB import */
/* They shall be fixed to uint16 regardless of CAN DB import result */
typedef PduIdType CanIf_TxPduIdType;
typedef PduIdType CanIf_RxPduIdType;
typedef uint16 CanIf_HthType;
typedef uint16 CanIf_TxQueueType;
typedef uint16 CanIf_DynamicIdType;
typedef uint16 CanIf_IdType;

/* type definition of Rx call-back function */
typedef void (*CanIf_Rx_Callback)(PduIdType CanTxPduId, const void *SduPtr);

typedef void (*CanIf_Rx_CddCbk)(PduIdType CanTxPduId, const void *SduPtr,
                                                            Can_IdType ddCanId);

#if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
/* Structure for Transciever */
typedef struct STagCanIf_TransceiverConfigType
{
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  uint8 ucCanIfCanTrcvId;    /* Trcv ID used by the state manager in case of
                             multiple driver */
  #endif
  uint8 ucCanTrcvId;         /* CanTrcvId */
  uint8 ucCanTrcvDriverId;   /* driver id in case of multiple driver support */
}CanIf_TransceiverConfigType;
#endif

#if (STD_ON == CANIF_WAKEUP_SUPPORT)
/* Structure for wakeup source information */
typedef struct STag_CanIf_WakeupSource
{
  EcuM_WakeupSourceType ddWakeupEvent;  /* Wakeup event */
  uint8 ucWakeupSource;    /* CANIF_<CANDRV/CANTRCV_WAKEUPSOURCE */
  uint8 ucCanCntrlOrTrcvId; /* CanControllerId/CanTrcvId */
  #if ((STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT) || \
                                      (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT))
  uint8 ucDriverId; /*Driver Id*/
  #endif
  uint8 ucControllerConfigId;  /* Index of the CAN Controller structure */

  uint8 ucNoOfCanCntrlOrTrcvId;
} CanIf_WakeupSource;
#endif

/* Structure for Rx L-PDU(Range Or List)  */
typedef struct STag_CanIf_RxLpdu
{
  Can_IdType ddCanIdLl;  /* CAN-ID lower limit (Range), / actual ID(List) */
  Can_IdType ddCanIdUl;  /* CAN-ID upper limit */
  #if ((STD_ON == CANIF_READRXPDU_NOTIFY_STATUS_API) || \
      (STD_ON == CANIF_READRXPDU_DATA_API))
  CanIf_RxPduIdType ddRxNotifyId;  /*  Notify Id */
  #endif
  /* #5139 */  
  CanIf_RxPduIdType ddRxPduId;  
  CanIf_RxPduIdType ddTargetId;  /* TargetPduId */
  uint8 ucCallbackIndex;  /* CanRxPduId */
  uint8 ucDlc;  /* Statically configured DLC */
  uint8 ucRxUserOrNotifSts;  /* ucRxUserOrNotifSts
                             Upper Layer - Lower nibble
                             0xX0- PDUR
                             0xX1- CANTP
                             0xX2- CAN NM
                             0xX3- CDD
                             0xX4- J1939TP
                             0xX5- XCP
                          */
                          /* Notif Status  - Upper Nibble
                             0x1X - Notify
                             0x2X - Data
                             0x4X - IdsM
                          */
  uint8 ucControllerId;   /* Controller to which the RxLpdu is mapped to */
  
  /* #5139 */
  #if (STD_ON == CANIF_META_DATA_SUPPORT)
  uint32 ulCanIfRxPduCanIdMask;
  uint8 ucMetaDataLength;
  #endif

} CanIf_RxLpdu;
#if ((STD_ON == CANIF_DEV_ERROR_DETECT) ||                                     \
                                    (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT))
typedef struct STag_CanIf_HrhInit
{
 #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  uint8 ucMaxHrhId;    /* Maximum Hrh Id */
 #endif

 #if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
 uint8 ucHrhOffSetId;  /* Hrh Offeset Id */
 #endif
} CanIf_HrhInit;
#endif
/* Structure for HRH */
typedef struct STag_CanIf_Hrh
{
  PduIdType ddRxLpduIndex;    /* Pointer to first range or list kind of Rx L-PDU(s)
                          structure */
  PduIdType ddNoOfRxLpdusRange;    /* Number of range kind of Rx L-PDU(s) */
  PduIdType ddNoOfRxLpdusList;     /* Number of list kind of Rx L-PDU(s) */
  uint8 ucFilterMethod;   /* Filter Method :  0x00: -> BasicCAN WITH STANDARD
                          0x01: -> BASICCAN WITH EXTENDED
                          0x02: -> BASICCAN WITH MIXED
                          0x03: -> FULLCAN WITH STANDARD
                          0x04: -> FULLCAN WITH EXTENDED
                          0x05: -> FULLCAN WITH MIXED */
  #if (CANIF_NO_OF_CONTROLLER > CANIF_ONE)
  uint8 ucControllerId;   /* Index to the controller */
  #endif
} CanIf_Hrh;

 #if ((STD_ON == CANIF_READRXPDU_DATA_API) || \
                                  (STD_ON == CANIF_READRXPDU_NOTIFY_STATUS_API))
/* Structure for Rx L-PDU Notification */

typedef struct STag_CanIf_RxLpduNotify
{
  #if (STD_ON == CANIF_READRXPDU_DATA_API)
  uint8 aaRxBufferData[CANIF_EIGHT];    /* Pointer to Rx L-PDU data buffer */
  #endif
  uint8 ucDlcOrNotify;    /* Pointer to Rx L-PDU status */

} CanIf_RxLpduNotify;
#endif

/* Structure for Transmit L-PDU */
typedef struct STag_CanIf_TxLpdu
{
  Can_IdType ddCanId;    /* Statically configured CAN-ID */
  Can_HwHandleType ddHthIdorBufferId;    /* Statically configured Hth Id */
  #if (STD_ON == CANIF_READTXPDU_NOTIFY_STATUS_API)
  uint8 ucTxNotifyStatusIndex;   /* Pointer to Tx L-PDU notify status */
  #endif
  #if (STD_ON == CANIF_SETDYNAMICTXID_API)
  CanIf_DynamicIdType ddDynCanIdIndex;   /* Dynamic CAN-ID */
  #endif
  PduIdType ddTxConfirmPduId;  /* Handle Id - for confirmation */
  PduIdType ddTxPduId;  /* Handle Id - CanTxPduId */
  /*#if (STD_ON == CANIF_TX_MULTIPLE_CALLBACK)*/
  uint8 ucCallbackIndex;   /* Callback function index */
  /*#endif*/
  uint8 ucTxCbkUser;    /* Callback Id for confirmation */
  uint8 ucHTHTypeOrTXPN;   /* Lower nibble | Higher nibble
                              0x0X              0xX0
                           CANIF_FULL_CAN  | CANIF_TXPN_ENABLED
                           CANIF_BASIC_CAN | CANIF_TXPN_ENABLED
                           CANIF_FULL_CAN  | CANIF_TXPN_DISABLED
                           CANIF_BASIC_CAN | CANIF_TXPN_DISABLED
                           Type of HTH */
  #if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
  uint8 ucDriverId;    /* CAN Driver Id */
  #endif
  #if (STD_ON == CANIF_READTXPDU_NOTIFY_STATUS_API)
  uint8 ucTxNotifyStsMask;    /* Mask for the bit corresponding to L-PDU
                              notify status */
  #endif
  #if ((STD_ON == CANIF_SETDYNAMICTXID_API) && \
                                             (STD_ON == CANIF_DEV_ERROR_DETECT))
  uint8 ucCanIdType;    /* Type of CAN-ID */
  #endif
  #if (CANIF_NO_OF_CONTROLLER > CANIF_ONE)
  uint8 ucControllerId;   /* Type of CAN-ID */
  #endif
  /* #5139 */
  #if (STD_ON == CANIF_META_DATA_SUPPORT)
  Can_IdType ddCanIdMask;
  uint8      ucMetaDataLength;
  #endif
} CanIf_TxLpdu;


/* Structure for Controller */
typedef struct STagCanIf_ControllerConfigType
{
  /* Pointer to tx Lpdu */
  P2CONST(CanIf_TxLpdu, AUTOMATIC, CANIF_CONST)pTxLpdu;
  CanIf_TxPduIdType ddNoOfTxPdu;    /* Index number to Tx L-PDU link to queue */

  #if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
  uint8 ucCanDriverId;        /* CAN Driver Id */
  #endif
  #if (CANIF_NO_OF_CONTROLLER >  CANIF_ONE)
  uint8 ucCanControllerId;   /* Statically configured ControllerId */
  #endif
  #if (STD_ON == CANIF_CTRL_WAKEUP_SUPPORT)
  boolean blWakeupEnabled;   /* Indication of wakeup */
  #endif
  #if (STD_ON == CANIF_PN_SUPPORT)
  boolean blPartialNWEnabled;   /* Indication of Partial networking feature */
  #endif
} CanIf_ControllerConfigType;

typedef struct STag_CanIf_Controller
{
  uint8 ucControllerMode;    /* Mode of the Controller */
  uint8 ucTxStatus;      /* Tx Status
                            0x00  Disabled
                            0x01  Enabled */
  uint8 ucRxStatus;      /* Rx Status
                            0x00  Disabled
                            0x01  Enabled */
#if (STD_ON == CANIF_CANCM_SUPPORT)
  uint8 ucBatVolStatus; /*  Battery Voltage Status
                            0x00  Normal
                            0x01  Error
                        */
#endif
} CanIf_Controller;

/* Structure for CAN Driver */
typedef struct STag_CanIf_CanDriver
{
  /* Function to set ControllerMode ->Can_SetControllerMode */
  P2FUNC(Can_ReturnType, CANIF_APPL_CODE, pCanSetControllerMode)
                           (uint8 Controller, Can_StateTransitionType ModeType);

  /* Function to Write CAN Data to Driver->Can_Write */
  P2FUNC(Can_ReturnType, CANIF_APPL_CODE, pCanWrite) (Can_HwHandleType Hth,
                    P2CONST(Can_PduType, AUTOMATIC, CANIF_APPL_CONST) pPduInfo);

  /* Function to check wakeup occured->Can_CheckWakeup */
   P2FUNC(Can_ReturnType, CANIF_APPL_CODE, pCanCheckwakeup) (uint8 controller);

  /* Function to check wakeup occured->Can_CheckBaudrate */
  P2FUNC(Std_ReturnType, CANIF_APPL_CODE, pCanCheckBaudrate) (uint8 controller,
      CONST(uint16, CANIF_CONST) Baudrate);

  /* Function to check wakeup occured->Can_ChangeBaudrate */
  P2FUNC(Std_ReturnType, CANIF_APPL_CODE, pCanChangeBaudrate) (uint8 controller,
      CONST(uint16, CANIF_CONST) Baudrate);
} CanIf_CanDriver;

/* Function pointer to CanTrcv Driver */
typedef struct STag_CanIf_CanTrcvDriver
{
  /* Function to set CanTrcv Mode ->CanTrcv_SetOpMode */
  P2FUNC(Std_ReturnType, CANIF_APPL_CODE, pCanTrcvSetOpMode)
                       (uint8 Transceiver, CanTrcv_TrcvModeType TrcvWakeupMode);
  /* Function to get CanTrcv Mode ->CanTrcv_GetOpMode */
  P2FUNC(Std_ReturnType, CANIF_APPL_CODE, pCanTrcvGetOpMode)
                      (uint8 Transceiver, P2VAR(CanTrcv_TrcvModeType, AUTOMATIC,
                                                        CANIF_APPL_DATA)OpMode);
  #if(STD_ON == CANIF_TRCV_WAKEUP_SUPPORT) 
  /* Function to get CanTrcv Mode ->CanTrcv_GetBusWuReason */
  P2FUNC(Std_ReturnType, CANIF_APPL_CODE, pCanTrcvGetBusWuReason)
  (uint8 Transceiver, P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC,
                                               CANIF_APPL_DATA)TrcvWuReasonPtr);
  /* Function to set CanTrcv Wakeup Mode ->CanTrcv_SetWakeupMode */
  P2FUNC(Std_ReturnType, CANIF_APPL_CODE, pCanTrcvSetWakeupMode)
                 (uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode);
  /* Function to check wakeup occured->CanTrcv_CheckWakeup  */
  P2FUNC(Std_ReturnType, CANIF_APPL_CODE, pCanTrcvCheckWakeup)
                                                            (uint8 Transceiver);
  /* Function to Clear TrcvWufFlag */
  P2FUNC(Std_ReturnType, CANIF_APPL_CODE, pClearTrcvWufFlag)(uint8 Transceiver);

  /* Function to Clear TrcvWufFlag */
  P2FUNC(Std_ReturnType, CANIF_APPL_CODE, pCheckWakeFlag)(uint8 Transceiver);
  #endif
} CanIf_CanTrcvDriver;

/*#if (STD_ON == CANIF_RX_MULTIPLE_CALLBACK)*/
/* Structure for Rx callback user */
/* Improvment #7042 - PduInfo type change */
typedef struct STag_CanIf_RxCbkUser
{
  /* Callback function for Rx Indication */
  P2FUNC(void, CANIF_APPL_CODE, pRxIndication)(PduIdType LddTargetRxPduId,
                    P2CONST(PduInfoType, AUTOMAITC, CANIF_CONST) PduInfoPtr);
} CanIf_RxCbkUser;
/* #endif */


/* Structure for Tx callback user */
typedef struct STag_CanIf_TxCbkUser
{
  /* Transmit Function for different callback user */
  P2FUNC(void, CANIF_APPL_CODE, pTxCbkUser)(CanIf_TxPduIdType LddTargetPduId);
} CanIf_TxCbkUser;

/* Structure for Transmit Queue for Tx buffer
   This structure need not be generated by the tool */
typedef struct STag_CanIf_TxQueue
{
  P2VAR(struct STag_CanIf_TxQueue, AUTOMATIC, CANIF_VAR)pTxNextQueue;
  Can_IdType ddCanId;    /* Statically configured CanId */
  PduIdType ddTxLPduId;    /* Transmit Pdu Id */
  #if (CANIF_CANFD_SUPPORT == STD_ON)
  uint8 aaTxBuffer[CANIF_THIRTYTWO];   /* RAM Pointer to the Buffer Area */
  #else
  uint8 aaTxBuffer[CANIF_EIGHT];       /* RAM Pointer to the Buffer Area */
  #endif
  uint8 ucDlc;    /* Data length Code*/
} CanIf_TxQueue;

typedef struct STag_CanIf_TxBuffer
{
  /* Pointer to First Queue to be transmitted */
  P2VAR(P2VAR(CanIf_TxQueue, AUTOMATIC, CANIF_VAR), AUTOMAITC, CANIF_VAR) 
                                                                  pTxFirstQueue;
  Can_HwHandleType ddHthId;         /* HTH start Index */
  CanIf_TxQueueType ddQueueIndex;   /* Queue Start index */
  CanIf_TxQueueType ddNoOfTxQueue;    /* number of TxQueue */
} CanIf_TxBuffer;


/* Structure for pointers for arrays relevant to Tx Buferring Functionality */
typedef struct STag_CanIf_TxBufferPtrsType
{
  /* Pointer to tx buffer arrays */
  P2CONST(CanIf_TxBuffer, AUTOMATIC, CANIF_CONST)pTxBuffer;
  /* Pointer to tx queue arrays */
  P2VAR(CanIf_TxQueue, AUTOMATIC, CANIF_CONST)pTxQueue;
  /* Pointer to PduToQueueMappting arrays */
  P2VAR(CanIf_TxPduIdType,AUTOMATIC, CANIF_CONST)pTxPduToQueueMapping;
  /* Pointer to basic tx pdu mapping arrays */
  P2CONST(uint16, AUTOMATIC, CANIF_CONST)pBasicTxPduIndex;
  
}CanIf_TxBufferPtrsType;

typedef struct STag_CanIf_Precompile_Options
{
  uint8 ucRxMultipleCallback;
  uint8 ucTxMultipleCallback;
  uint8 ucTxBasicCanPdu;
  uint8 ucRxBasicCanSupport;
  uint8 ucTxBuffering;
  uint16 ddNumOfTxQueue;
  uint16 ddNumOfTxBuffer;
  uint16 ddNumOfRxPdu;
  uint16 ddNumOfTxPdu; 
  uint16 ddNumOfTxBasicPdu; 
}CanIf_Precompile_Options;

typedef signed int CanIf_PtrSize;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* CANIF_INTTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
