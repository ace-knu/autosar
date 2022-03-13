/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf_Rx.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : Header file of CanIf_Rx.c                                     **
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
** 2.5.0    06-Dec-2016    Js.Lim    #6745, #7077                             **
** 1.0.1    13-Jun-2016    Kt.Kim    #5139                                    **
** 1.0.0    04-Feb-2013    Kt.Kim    Initial version                          **
*******************************************************************************/

#ifndef CANIF_RX_H
#define CANIF_RX_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf_Cbk.h"           /* Call-back header file */
#include "CanIf_Ram.h"           /* Ram header file */
#include "CanIf_PCTypes.h"       /* Pre-compile time header file */
#include "CanSM_Cbk.h"           /* CAN State Manager call back header file */
#if (STD_ON == CANIF_PDUR_CALLBACK)
#include "PduR_CanIf.h"          /* Call-back PduR header file */
#endif
#if (STD_ON == CANIF_CANTP_CALLBACK)
#include "CanTp_Cbk.h"           /* Call-back CanTp header file */
#endif
#if (STD_ON == CANIF_CANNM_CALLBACK)
#include "CanNm_Cbk.h"           /* Call-back CanNm header file */
#endif
#include "SchM_CanIf.h"          /* SchM CanIf Header file */
#if (STD_ON == CANIF_DEV_ERROR_DETECT)
#include "CanIf_Error.h"         /* DET header file */
#endif
#if (STD_ON == CANIF_AUTRON_CANTRCV_SUPPORT)
#include "CanTrcv.h"            /* CanTrcv header file */
#endif
#if (STD_ON == CANIF_EXTENAL_CANTRCV_SUPPORT)
#include "CanIf_CanTrcv.h"            /* CanTrcv header file */
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANIF_RX_AR_RELEASE_MAJOR_VERSION       4
#define CANIF_RX_AR_RELEASE_MINOR_VERSION       0
#define CANIF_RX_AR_RELEASE_REVISION_VERSION    3

/* Software Version Information */
#define CANIF_RX_SW_MAJOR_VERSION    2
#define CANIF_RX_SW_MINOR_VERSION    5
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if (STD_ON == CANIF_RX_LPDU)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_RxNotification (
                         P2CONST(CanIf_RxLpdu, AUTOMATIC, CANIF_CONST) LpRxLpdu, 
                         VAR(uint8, CANIF_VAR) CanDlc,
                         P2CONST(uint8, AUTOMATIC, CANIF_CONST) CanSduPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

/* #5139 */
#if ((STD_ON == CANIF_RX_LPDU) && (STD_ON == CANIF_META_DATA_SUPPORT))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(P2VAR(uint8, AUTOMATIC, CANIF_VAR), CANIF_CODE) CanIf_RxData
  (Can_IdType CanId, uint8 CanDlc, P2CONST(CanIf_RxLpdu, AUTOMATIC, CANIF_CONST)
    LpRxLpdu, P2CONST(uint8, AUTOMATIC, CANIF_APPL_CONST) CanSduPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_BINARY_SEARCH)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(P2CONST(CanIf_RxLpdu, AUTOMATIC, CANIF_CONST), CANIF_CODE) 
                         CanIf_BinarySearch (
                         P2CONST(CanIf_RxLpdu, AUTOMATIC, CANIF_CONST) LpRxLpdu,
                         VAR(PduIdType, CANIF_VAR) LddSize,
                         VAR(Can_IdType, CANIF_VAR) LddCanId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(P2CONST(CanIf_RxLpdu, AUTOMATIC, CANIF_CONST), CANIF_CODE) 
                          CanIf_TriggerSWFilter (
                          P2CONST(CanIf_Hrh, AUTOMATIC, CANIF_CONST) LpHrh, 
                          VAR(Can_IdType, CANIF_VAR) CanId) ;
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#if ((STD_ON == CANIF_READRXPDU_NOTIFY_STATUS_API) || \
                                           (STD_ON == CANIF_READRXPDU_DATA_API))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_RxStatusUpdate (
                       P2CONST(CanIf_RxLpdu, AUTOMATIC, CANIF_CONST) LpRxLpdu,
                       P2CONST(PduInfoType, AUTOMATIC, CANIF_CONST) PduInfoPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_LINEAR_SEARCH)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(P2CONST(CanIf_RxLpdu, AUTOMATIC, CANIF_CONST), CANIF_CODE) 
                         CanIf_LinearSearch (
                         P2CONST(CanIf_RxLpdu, AUTOMATIC, CANIF_CONST) LpRxLpdu, 
                         VAR(PduIdType, CANIF_VAR) LddSize,
                         VAR(Can_IdType, CANIF_VAR) LddCanId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif  /*CANIF_RX_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
