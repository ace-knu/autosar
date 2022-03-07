/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: PduR_RxTp.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR PDU Router                                            **
**                                                                            **
**  PURPOSE   : Header file of PduR_RxTp.c                                    **
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
** 2.2.2     01-Dec-2017   Chan Kim    Redmine #10813                         **
** 2.2.0     01-Feb-2017   Chan Kim    Redmine #6922                          **
** 2.1.5     30-Nov-2016   Chan Kim    Redmine #6568, #6706, #6771            **
** 2.1.0     17-Jun-2016   Chan Kim    Redmine #5190, #5250                   **
** 2.0.8     10-Jun-2016   Chan Kim    Redmine #5143                          **
** 2.0.3     24-Nov-2015   Chan Kim    Redmine #3545, #4519                   **
** 2.0.0     11-Aug-2015   Chan Kim    Redmine #2949                          **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
#ifndef PDUR_RXTP_H
#define PDUR_RXTP_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version information */
#define PDUR_RXTP_AR_RELEASE_MAJOR_VERSION    4
#define PDUR_RXTP_AR_RELEASE_MINOR_VERSION    0
#define PDUR_RXTP_AR_RELEASE_REVISION_VERSION 3

/* PDUR software version information */
#define PDUR_RXTP_SW_MAJOR_VERSION            2
#define PDUR_RXTP_SW_MINOR_VERSION            2
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if (PDUR_TP_RXINDICATION == STD_ON)
#if (PDUR_TP_GATEWAY_OPERATION == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint8, PDUR_CODE) PduR_BuffUpdateLoTpStartOfReception(
  PduLengthType LddTpSduLength, P2VAR(PduLengthType, AUTOMATIC,
    PDUR_VAR) LpBufferSizePtr);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif /* End of if (PDUR_TP_RXINDICATION == STD_ON) */

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if (PDUR_TP_RXINDICATION == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
#if (PDUR_FOUR_ONE_ONE == STD_ON)
#if ((PDUR_J1939TP_SUPPORT == STD_ON) || (PDUR_SECOC_SUPPORT == STD_ON))
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpStartOfReception(
  PduIdType LddRxPduId, uint8 LucAPIId, uint8 LucModuleType,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr, 
  PduLengthType TpSduLength,
  P2VAR(PduLengthType,AUTOMATIC, PDUR_VAR) bufferSizePtr);
#else
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpStartOfReception(
  PduIdType LddRxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr, 
  PduLengthType TpSduLength,
  P2VAR(PduLengthType, AUTOMATIC, PDUR_VAR) bufferSizePtr);
#endif
#endif
#else
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpStartOfReception(
  PduIdType LddRxPduId, uint8 LucAPIId, uint8 LucModuleType,
  PduLengthType TpSduLength, 
  P2VAR(PduLengthType, AUTOMATIC, PDUR_VAR) LpBufferSizePtr);
#else
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpStartOfReception(
  PduIdType LddRxPduId, PduLengthType TpSduLength,
  P2VAR(PduLengthType, AUTOMATIC, PDUR_VAR) LpBufferSizePtr);
#endif
#endif /* End of if (PDUR_FOUR_ONE_ONE = PDUR_ONE == STD_ON) */
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (PDUR_TP_RXINDICATION == STD_ON) */
#endif /* End of if (PDUR_ZERO_COST_OPERATION == STD_OFF) */

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if (PDUR_TP_RXINDICATION == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyRxData
  (PduIdType LddRxPduId,
  uint8 LucAPIId, uint8 LucModuleType,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr,
  P2VAR(PduLengthType, AUTOMATIC, PDUR_VAR) LpBufferSizePtr);
#else
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyRxData
  (PduIdType LddRxPduId,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr,
  P2VAR(PduLengthType, AUTOMATIC, PDUR_VAR) LpBufferSizePtr);
#endif
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (PDUR_TP_RXINDICATION == STD_ON) */
#endif /* End of if (PDUR_ZERO_COST_OPERATION == STD_OFF) */

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if (PDUR_TP_RXINDICATION == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
extern FUNC(void, PDUR_CODE) PduR_LoTpRxIndication(PduIdType LddRxPduId,
  uint8 LucAPIId, uint8 LucModuleType, NotifResultType result);
#else
extern FUNC(void, PDUR_CODE) PduR_LoTpRxIndication(PduIdType LddRxPduId,
  NotifResultType result);

#endif
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (PDUR_TP_RXINDICATION == STD_ON) */
#endif /* End of if (PDUR_ZERO_COST_OPERATION == STD_OFF) */

#if(PDUR_ZERO_COST_OPERATION == STD_OFF)
#if((PDUR_FUN_CHANGEPARAMETER_SUPPORT == STD_ON) &&\
  (PDUR_TP_RXINDICATION == STD_ON))
#define PDUR_START_SEC_CODE
#include "MemMap.h"
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
extern FUNC(Std_ReturnType, PDUR_VAR) PduR_ChangeParameter(
  PduIdType LddRxPduId, uint8 LucAPIId, TPParameterType PduParameterName,
  uint16 LusValue);

#else
extern FUNC(Std_ReturnType, PDUR_VAR) PduR_ChangeParameter(
  PduIdType LddRxPduId, TPParameterType PduParameterName, uint16 LusValue);

#endif
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if
        *(PDUR_FUN_CHANGEPARAMETER_SUPPORT == STD_ON) && (PDUR_TP_RXINDICATION
        *== STD_ON)) */
#endif

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if ((PDUR_CANCEL_RECEIVE_SUPPORT == STD_ON) &&\
  (PDUR_TP_RXINDICATION == STD_ON))
#define PDUR_START_SEC_CODE
#include "MemMap.h"
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
extern FUNC(Std_ReturnType, PDUR_VAR) PduR_CancelReceive(PduIdType LddRxPduId,
  uint8 LucAPIId);

#else
extern FUNC(Std_ReturnType, PDUR_VAR) PduR_CancelReceive(PduIdType LddRxPduId);

#endif
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if ((PDUR_CANCEL_RECEIVE_SUPPORT == STD_ON) &&
        *(PDUR_TP_RXINDICATION == STD_ON)) */
#endif /* End of if (PDUR_ZERO_COST_OPERATION == STD_OFF) */

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if ((PDUR_CANCEL_RECEIVE_SUPPORT == STD_ON) &&\
  (PDUR_TP_RXINDICATION == STD_ON))
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, PDUR_VAR) PduR_DETCheckCancelReceive(
  PduIdType LddRxPduId, uint8 LucAPIId);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if ((PDUR_CANCEL_RECEIVE_SUPPORT == STD_ON) &&
        *(PDUR_TP_RXINDICATION == STD_ON)) */
#endif /* End of if (PDUR_ZERO_COST_OPERATION == STD_OFF) */

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if ((PDUR_FUN_CHANGEPARAMETER_SUPPORT == STD_ON) &&\
  (PDUR_TP_RXINDICATION == STD_ON))
#if (PDUR_DEV_ERROR_DETECT == STD_ON)

#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, PDUR_CODE) PduR_DETCheckChangeParameter(
  PduIdType LddRxPduId, uint8 LucAPIId, uint16 LusPduParameterValue);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if ((PDUR_FUN_CHANGEPARAMETER_SUPPORT == STD_ON) &&
        *(PDUR_TP_RXINDICATION == STD_ON)) */
#endif /* End of if (PDUR_DEV_ERROR_DETECT == STD_ON) */
#endif

#if ((PDUR_ZERO_COST_OPERATION == STD_OFF) && (PDUR_TP_RXINDICATION == STD_ON))
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_DETCheckLoTpCopyRxData(
  PduIdType LddRxPduId, uint8 LucModuleType, uint8 LucAPIId,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr,
  P2VAR(PduLengthType, AUTOMATIC, PDUR_VAR) LpBufferSizePtr);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if ((PDUR_ZERO_COST_OPERATION == STD_OFF) &&
        *(PDUR_TP_RXINDICATION == STD_ON)) */
#endif /* End of if (PDUR_DEV_ERROR_DETECT == STD_ON) */

#if ((PDUR_TP_RXINDICATION == STD_ON) && (PDUR_ZERO_COST_OPERATION == STD_OFF))
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, PDUR_CODE) PduR_DETCheckLoTpRxIndication(
  PduIdType LddRxPduId, uint8 LucModuleType, uint8 LucAPIId);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if ((PDUR_ZERO_COST_OPERATION == STD_OFF) &&
        *(PDUR_TP_RXINDICATION == STD_ON)) */
#endif /* End of if (PDUR_DEV_ERROR_DETECT == STD_ON) */

#if (PDUR_TP_GATEWAY_OPERATION == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpGWCopyRxData(
    PduIdType LddRxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_VAR) LpBufferSizePtr);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (PDUR_TP_GATEWAY_OPERATION == STD_ON) */

#if ((PDUR_TP_RXINDICATION == STD_ON) && (PDUR_ZERO_COST_OPERATION == STD_OFF))
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_DETCheckLoTpStartOfReception(
  PduIdType LddRxPduId, uint8 LucAPIId, uint8 LucModuleType,
  P2VAR(PduLengthType, AUTOMATIC, PDUR_VAR) LpBufferSizePtr);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* */
#endif

#if (PDUR_TP_GATEWAY_OPERATION == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, PDUR_CODE) PduR_UpTpRxIndication(
  P2CONST(PduR_GWRxTpPdu, AUTOMATIC, PDUR_CONST) LpGWTpPdu,
  P2VAR(PduR_TpBuffer, AUTOMATIC, PDUR_VAR) LpTpBuffer, NotifResultType result);
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif /* PDUR_RXTP_H */

/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
