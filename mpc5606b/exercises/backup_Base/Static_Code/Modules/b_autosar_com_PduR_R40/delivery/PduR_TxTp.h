/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: PduR_TxTp.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR PDU Router                                            **
**                                                                            **
**  PURPOSE   : Header file of PduR_TxTp.c                                    **
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
** 2.2.0     01-Feb-2017   Chan Kim    Redmine #6922                          **
** 2.1.5     30-Nov-2016   Chan Kim    Redmine #6568, #6706, #6771            **
** 2.1.0     17-Jun-2016   Chan Kim    Redmine #5190                          **
** 2.0.0     11-Aug-2015   Chan Kim    Redmine #2949                          **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/
#ifndef PDUR_TXTP_H
#define PDUR_TXTP_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR_PCTypes.h"  /* PDU Router module post-build time header */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version information */
#define PDUR_TXTP_AR_RELEASE_MAJOR_VERSION    4
#define PDUR_TXTP_AR_RELEASE_MINOR_VERSION    0
#define PDUR_TXTP_AR_RELEASE_REVISION_VERSION 3

/* PDUR software version information */
#define PDUR_TXTP_SW_MAJOR_VERSION            2
#define PDUR_TXTP_SW_MINOR_VERSION            2
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#if (PDUR_TP_GATEWAY_OPERATION == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpGWCopyTxData
 (P2CONST(PduR_TpCopyTxDataBuf, AUTOMATIC, PDUR_CONST) LpTpCopyTxData,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr,
  P2VAR(RetryInfoType, AUTOMATIC, PDUR_VAR) LpRetry,
  P2VAR(PduLengthType, AUTOMATIC, PDUR_VAR) LpAvailableDataPtr);
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if (PDUR_TP_TXCONFIRMATION == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyTxData
 (PduIdType LddTxPduId, uint8 LucAPIId, uint8 LucModuleType,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr,
  P2VAR(RetryInfoType, AUTOMATIC, PDUR_VAR) LpRetry,
  P2VAR(PduLengthType, AUTOMATIC, PDUR_VAR) LpAvailableDataPtr);

#else
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyTxData
  (PduIdType LddTxPduId, 
  P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr,
  P2VAR(RetryInfoType, AUTOMATIC, PDUR_VAR) LpRetry,
  P2VAR(PduLengthType, AUTOMATIC, PDUR_VAR) LpAvailableDataPtr);

#endif
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (PDUR_TP_TXCONFIRMATION == STD_ON) */
#endif

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if (PDUR_TP_TXCONFIRMATION == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
extern FUNC(void, PDUR_CODE) PduR_LoTpTxConfirmation(PduIdType LddTxPduId,
  uint8 LucAPIId, PduIdType LucModuleType, NotifResultType result);

#else
extern FUNC(void, PDUR_CODE) PduR_LoTpTxConfirmation(PduIdType LddTxPduId,
  NotifResultType result);

#endif
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (PDUR_TP_TXCONFIRMATION == STD_ON) */
#endif /* End of if (PDUR_ZERO_COST_OPERATION == STD_OFF) */

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if (PDUR_TP_TXCONFIRMATION == STD_ON)
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_DETCheckLoTpCopyTxData(
  PduIdType LddTxPduId, uint8 LucModuleType, uint8 LucAPIId,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr,
  P2VAR(PduLengthType, AUTOMATIC, PDUR_VAR) LpAvailableDataPtr);
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
#endif

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if (PDUR_TP_TXCONFIRMATION == STD_ON)
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, PDUR_CODE) PduR_DETCheckLoTpTxConfirmation(
  PduIdType LddTxPduId, uint8 LucAPIId, PduIdType LucModuleType);
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
#endif


#endif /* PDUR_TXTP_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
