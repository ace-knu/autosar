/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf_Tx.h                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : Header file of CanIf_Tx.c                                     **
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
** 2.2.2    12-Feb-2016    Kt.Kim      #3813                                  **
** 2.2.1    17-Aug-2015    Kt.Kim      Cleared violation against MISRA 2.2/2.3**
** 2.2.0    17-Jun-2013    Kt.Kim      Lib-Build Support                      **
**                                     Restore CANIF_TX_QUEUE define          **
** 2.1.0    30-May-2013    Kt.Kim      Lib-Build Support                      **
** 1.0.0    04-Feb-2013    Kt.Kim      Initial version                        **
*******************************************************************************/

#ifndef CANIF_TX_H
#define CANIF_TX_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf.h"                  /* CanInterface header file */
#include "CanIf_Ram.h"              /* Ram header file */
#include "CanIf_IntTypes.h"         /* CanIf Internal Types header file */
#include "CanIf_Error.h"            /* CanIf DET Error file */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANIF_TX_AR_RELEASE_MAJOR_VERSION       4
#define CANIF_TX_AR_RELEASE_MINOR_VERSION       0
#define CANIF_TX_AR_RELEASE_REVISION_VERSION    3

/* Software Version Information */
#define CANIF_TX_SW_MAJOR_VERSION    2
#define CANIF_TX_SW_MINOR_VERSION    5
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if ((STD_ON == CANIF_DEV_ERROR_DETECT) && (STD_ON == CANIF_TX_LPDU))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_DETTransmit (
                       VAR(PduIdType, CANIF_VAR) CanTxPduId,
                       P2CONST(PduInfoType, AUTOMATIC, CANIF_CONST) PduInfoPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_ClearTxQueue (
 P2CONST(CanIf_ControllerConfigType, AUTOMATIC, CANIF_CONST) LpStaticController);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_TxQueueHandling (
                     P2CONST(CanIf_TxBuffer, AUTOMATIC, CANIF_CONST) LpTxBuffer,
                     VAR(CanIf_TxQueueType, CANIF_VAR) LddTxQueueId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_QueueTransmit (
                         P2CONST(CanIf_TxLpdu, AUTOMATIC, CANIF_CONST)LpTxLpdu);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(CanIf_TxQueueType, CANIF_CODE) CanIf_CheckQueueStatus (
                     P2CONST(CanIf_TxBuffer, AUTOMATIC, CANIF_CONST)LpTxBuffer);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_TxNotification (
                        P2CONST(CanIf_TxLpdu, AUTOMATIC, CANIF_CONST) LpTxLpdu);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Can_ReturnType, CANIF_CODE) CanIf_CanWriteService (
                          P2CONST(CanIf_TxLpdu, AUTOMATIC, CANIF_CONST)LpTxLpdu,
                          VAR(Can_HwHandleType, CANIF_VAR) LddHth, 
                          P2CONST(Can_PduType, AUTOMATIC, CANIF_CONST) PduInfo);
                          
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#else

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Can_ReturnType, CANIF_CODE) CanIf_CanWriteService (
                          VAR(Can_HwHandleType, CANIF_VAR) LddHth,
                          P2CONST(Can_PduType, AUTOMATIC, CANIF_CONST) PduInfo);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif


#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_ClearTxBuffer (
                    VAR(CanIf_TxPduIdType, CANIF_VAR) LddTxPduId, 
                    P2CONST(CanIf_TxBuffer, AUTOMATIC, CANIF_CONST) LpTxBuffer);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CANIF_TX_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
