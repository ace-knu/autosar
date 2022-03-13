/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf_PCTypes.h                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : Provision of variables of which value is set at link time     **
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
** 2.5.4    11-Oct-2017    C.Kim     #9850, #10240                            **
** 2.5.0    06-Dec-2016    Js.Lim    #7077                                    **
** 2.2.9    12-Aug-2016    Kt.Kim    #5739                                    **
** 2.2.8    13-Jun-2016    Kt.Kim    #5139                                    **
** 2.2.7    11-Mar-2016    Kt.Kim    #4386                                    **
** 2.2.6    25-Aug-2015    Kt.Kim    #2999                                    **
** 2.2.5    13-Jun-2015    Kt.Kim    #2724                                    **
** 2.2.4    13-Apr-2013    Kt.Kim    #2254                                    **
** 2.1.0    29-May-2013    Kt.Kim    Library Support                          **
** 1.0.0    04-Feb-2013    Kt.Kim    Initial version                          **
*******************************************************************************/

#ifndef CANIF_PCTYPES_H
#define CANIF_PCTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf.h"                      /* CAN Interface header file */
#include "CanIf_IntTypes.h"             /* CAN Internal Types header file */
#if (STD_ON == CANIF_ECUM_CALLBACK)
#include "EcuM.h"                       /* EcuM header file */
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANIF_PCTYPES_AR_RELEASE_MAJOR_VERSION     (4)
#define CANIF_PCTYPES_AR_RELEASE_MINOR_VERSION     (0)
#define CANIF_PCTYPES_AR_RELEASE_REVISION_VERSION  (3)

/* File version information */
#define CANIF_PCTYPES_SW_MAJOR_VERSION  (2)
#define CANIF_PCTYPES_SW_MINOR_VERSION  (5)

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* Macro defined for CAN_CONTROLLER_ID */
#if (CANIF_ONE == CANIF_NO_OF_CONTROLLER)
#define CAN_CONTROLLER_ID (ControllerId)
#else
#define CAN_CONTROLLER_ID (LpStaticController->ucCanControllerId)
#endif
/* Tx status mask for controller */
#define CANIF_TX_STATUS_MASK         ((uint8)0x0f)
/* Status value to indicate that Queue is occupied */
#define CANIF_TXQUEUE_OCCUPIED       ((uint8)0x80)
/* Rx status mask for controller */
#define CANIF_RX_STATUS_MASK         ((uint8)0x0f)
/* Rx Validate wake up value for controller */
#define CANIF_RX_VALIDATE_WAKEUP     ((uint8)0x81)
/* Status value to indicate that Queue is free */
#define CANIF_INVALID_TXQUEUE        ((CanIf_TxQueueType)0xff)
/* to fill the controller id field in structure */
#define CANIF_INVALID_CONTROLLER     ((uint8)0xff)
/* to check whether the upper layer is correct or not */
#define CANIF_TX_INVALID_UL_USER     ((uint8)0xff)
/* to check whether the upper layer is correct or not */
#define CANIF_RX_INVALID_UL_USER     ((uint8)0xff)
/* to check whether the Dynamic CanId is configured or not */
#define CANIF_INVALID_DYNCANID       ((CanIf_DynamicIdType)0xff)
/* Mask value to get the upper layer Id */
#define CANIF_UL_MASK                ((uint8)0x0f)
/* Mask value to get the HTH type */
#define CANIF_HTHTYPE_MASK           ((uint8)0x0f)
/* Status Mask value to get the Partial Networking status */
#define CANIF_PN_STATUS_MASK         ((uint8)0x10)
/* both Partial network and TX confirmation indication */
#define CANIF_TX_CONFIRM_PN_ENABLED  ((uint8)0x90)
/* TX confirm bit is MSB of Higher nibble, PN enabled bit is MSB of lower
 nibble */
#define CANIF_TX_CONFIRM_STATUS_MASK ((uint8)0x80)
/* Status mask for getting the Notification value */
#define CANIF_NOTIFY_STATUS_MASK     ((uint8)0x80)
/* Status mask for getting the Rx Notification value */
#define CANIF_RX_NOTIFY_STATUS_MASK  ((uint8)0x10)
/* Status mask for getting the Rx Data value */
#define CANIF_RX_DATA_STATUS_MASK    ((uint8)0x20)
/* Status mask for IDSM report target PDU */
#define CANIF_RX_IDSM_REPORT_MASK    ((uint8)0x40)
/* Status mask for getting the Dlc value */
#define CANIF_RX_DLC_STATUS_MASK     ((uint8)0x0f)
/* Status mask for getting the queue status */
#define CANIF_QUEUE_STATUS_MASK      ((uint8)0xF0)
/* mask for getting the Tx Status of the controller */
#define CANIF_TX_ENABLED_MASK        ((uint8)0x0f)
/* mask for getting the Tx confirmation Status of the controller */
#define CANIF_TX_CONFIRMED           ((uint8)0x80)
/*mask for getting battery voltage status for blocking transmit request */
#define CANIF_TX_BAT_STATUS_MASK     ((uint8)0x20)
/* Mask for Standard CAN ID */
#define CANIF_STANDARD_ID_MASK     ((uint16)0x07FF)
/* Mask for Extended CAN ID */
#define CANIF_EXTENDED_ID_MASK     ((uint32)0x1FFFFFFF)
/* Mask for CAN Frame Type */
#define CANIF_FRAME_TYPE_MASK      ((uint32)0xC0000000)

#if (STD_ON == CANIF_SETDYNAMICTXID_API)
#define CANIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations>
    No Impact of this rule violation(Array size will fixed in linking time)   */    
/* RAM allocation of dynamic CAN-ID */
extern VAR(Can_IdType, CANIF_VAR) CanIf_GddCanId[];
#define CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#endif

#define CANIF_START_SEC_CONST_8
#include "MemMap.h"
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations>
    No Impact of this rule violation(Array size will fixed in linking time)   */    
/* Global array for mapping between Hrh and index of CanIf_GaaHrh  */
extern CONST(uint8, CANIF_CONST) CanIf_GaaHrhMapArray[];
#define CANIF_STOP_SEC_CONST_8
#include "MemMap.h"

/* 8241 */
#if((STD_ON == CANIF_CANFD_SUPPORT) && (STD_ON == CANIF_CANFD_DISCRETE_DLC_SUPPORT))
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for ControllerConfigType structure */
extern CONST(uint8, CANIF_CONST) CanIf_GaaDiscreteDlctoDataLength[CANIF_SEVEN];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for ControllerConfigType structure */
extern CONST(CanIf_ControllerConfigType, CANIF_CONST)
 CanIf_GaaControllerConfigType[CANIF_NO_OF_CONTROLLER];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations>
    No Impact of this rule violation(Array size will fixed in linking time)   */    
/* Global array for HRH structure */
extern CONST(CanIf_Hrh, CANIF_CONST) CanIf_GaaHrh[];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (STD_ON == CANIF_TX_LPDU)
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations>
    No Impact of this rule violation(Array size will fixed in linking time)   */    
/* Global array for Tx L-PDU structure */
extern CONST(CanIf_TxLpdu, CANIF_CONST) CanIf_GaaTxLpdu[];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations>
    No Impact of this rule violation(Array size will fixed in linking time)   */    
/* Global array for Tx L-PDU structure */
extern CONST(CanIf_TxBuffer, CANIF_CONST) CanIf_GaaTxBuffer[];
/* Global array for mapping index between queue and tx basic pdu */
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations>
    No Impact of this rule violation(Array size will fixed in linking time)   */    
extern CONST(uint16, CANIF_CONST) CanIf_GaaTxBasicPduIndexMapping[];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations>
    No Impact of this rule violation(Array size will fixed in linking time)   */    
/* Global array for Rx L-PDU structure */
extern CONST(CanIf_RxLpdu, CANIF_CONST) CanIf_GaaRxLpdu[];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for CAN Driver structure  */
extern CONST(CanIf_CanDriver, CANIF_CONST) CanIf_GaaCanDriver[];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_MULTIPLE_TRCVDRV_SUPPORT)
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for CAN Transceiver Driver structure  */
extern CONST(CanIf_CanTrcvDriver, CANIF_CONST) CanIf_GaaCanTrcvDriver[];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Global array for CAN Transceiver Channel structure */
extern CONST(CanIf_TransceiverConfigType, CANIF_CONST) CanIf_GaaCanTrcv[];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_DEV_ERROR_DETECT)
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations>
    No Impact of this rule violation(Array size will fixed in linking time)   */    
extern CONST(CanIf_HrhInit, CANIF_CONST) CanIf_GaaHrhInit[];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_WAKEUP_SUPPORT)
/* Global array for wakeup sources */
#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(CanIf_WakeupSource, CANIF_CONST) 
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations>
    No Impact of this rule violation(Array size will fixed in linking time)   */    
  CanIf_GaaWakeupSource[];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#define CANIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations>
    No Impact of this rule violation(Array size will fixed in linking time)   */    
/* Global array for Queue allocation */
extern P2VAR(CanIf_TxQueue, CANIF_VAR, CANIF_VAR) CanIf_GaaQueueList[];
#define CANIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Global variable for reading pre-compile option at link time */
extern CONST(CanIf_Precompile_Options, CANIF_CONST) CanIf_GddPrecompOpt;

/* Global array for Single Rx Indication Callback Arrays */
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations>
    No Impact of this rule violation(Array size will fixed in linking time)   */    
extern CONST(CanIf_RxCbkUser, CANIF_CONST) CanIf_GaaRxSingleCbkUser[];

/* Global array for Tx Confirmation Callbacks */
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations>
    No Impact of this rule violation(Array size will fixed in linking time)   */    
extern CONST(CanIf_TxCbkUser, CANIF_CONST) CanIf_GaaTxSingleCbkUser[];

/*Global pointer for Multiple Rx Indication Callback Arrays */
extern CONSTP2CONST(CanIf_RxCbkUser,AUTOMATIC, CANIF_CONST) CanIf_GpRxMulCbkUser;

/*Global pointer for Multiple Tx Confirmation Callback Arrays */
extern CONSTP2CONST(CanIf_TxCbkUser,AUTOMATIC, CANIF_CONST) CanIf_GpTxMulCbkUser;

/* Global variable for Tx Bufferring Functionality */
extern CONST(CanIf_TxBufferPtrsType, CANIF_CONST) CanIf_GddTxBuffCon;

  #if (STD_ON == CANIF_TX_MULTIPLE_CALLBACK)
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations>
    No Impact of this rule violation(Array size will fixed in linking time)   */    
extern CONST(CanIf_TxCbkUser, CANIF_CONST)CanIf_GaaTxCbkUser[];
  #endif
  #if (STD_ON == CANIF_RX_MULTIPLE_CALLBACK)
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations>
    No Impact of this rule violation(Array size will fixed in linking time)   */    
extern CONST(CanIf_RxCbkUser, CANIF_CONST)CanIf_GaaRxCbkUser[];
  #endif
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"



#endif /* CANIF_PCTYPES_H */
/*******************************************************************************
**                          END OF FILE                                       **
*******************************************************************************/
