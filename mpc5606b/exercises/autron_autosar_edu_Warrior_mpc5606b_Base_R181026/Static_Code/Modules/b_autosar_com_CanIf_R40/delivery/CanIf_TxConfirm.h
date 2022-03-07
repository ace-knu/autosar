/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf_TxConfirm.h                                             **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : Prototype definition of CanIf_TxConfirm.c                     **
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
** 2.5.0    06-Dec-2016    Js.Lim      #7077                                  **
** 1.0.0    04-Feb-2013    Kt.Kim      Initial version                        **
*******************************************************************************/
#ifndef CANIF_TXCONFIRM_H
#define CANIF_TXCONFIRM_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf_Tx.h"              /* Transmit Header */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANIF_TXCONFIRM_AR_RELEASE_MAJOR_VERSION       4
#define CANIF_TXCONFIRM_AR_RELEASE_MINOR_VERSION       0
#define CANIF_TXCONFIRM_AR_RELEASE_REVISION_VERSION    3

/* Software Version Information */
#define CANIF_TXCONFIRM_SW_MAJOR_VERSION    2
#define CANIF_TXCONFIRM_SW_MINOR_VERSION    5
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Inline Function                                       **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if ((STD_ON == CANIF_DEV_ERROR_DETECT) && (STD_ON == CANIF_TX_LPDU))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_DETCancelTxConfirmation (
                       VAR(PduIdType, CANIF_VAR) CanTxPduId,
                       P2CONST(PduInfoType, AUTOMATIC, CANIF_CONST) PduInfoPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_DummyTxConfirmation (PduIdType CanTxPduId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
#if (STD_ON == CANIF_TX_LPDU)
/*  polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations>
    No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1236)       */
#define CanIf_DummyTxConfirmation(CanTxPduId)
/*  polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations>
    No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1236)       */

#endif
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CANIF_TX_CONFIRM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
