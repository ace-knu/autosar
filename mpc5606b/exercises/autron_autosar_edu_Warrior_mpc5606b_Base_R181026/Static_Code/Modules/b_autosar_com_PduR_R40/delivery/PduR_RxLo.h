/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: PduR_RxLo.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR PDU Router                                            **
**                                                                            **
**  PURPOSE   : Header file of PduR_RxLo.c                                    **
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
** 2.0.3     24-Nov-2015   Chan Kim    Redmine #3545, #4519                   **
** 2.0.0     11-Aug-2015   Chan Kim    Redmine #2949                          **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/
#ifndef PDUR_RXLO_H
#define PDUR_RXLO_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define PDUR_RXLO_AR_RELEASE_MAJOR_VERSION     4
#define PDUR_RXLO_AR_RELEASE_MINOR_VERSION     0
#define PDUR_RXLO_AR_RELEASE_REVISION_VERSION  3

/* Software Version Information */
#define PDUR_RXLO_SW_MAJOR_VERSION             2
#define PDUR_RXLO_SW_MINOR_VERSION             2
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if (PDUR_LO_RXINDICATION == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
extern FUNC(void, PDUR_CODE) PduR_LoRxIndication(PduIdType LddRxPduId,
  uint8 LucAPIId,
  uint8 LucModuleType,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr);
#else
extern FUNC(void, PDUR_CODE) PduR_LoRxIndication(PduIdType LddRxPduId,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr);

#endif /*#if (PDUR_DEV_ERROR_DETECT == STD_ON)*/
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* #if (PDUR_LO_RXINDICATION == STD_ON) */
#endif /* #if (PDUR_ZERO_COST_OPERATION == STD_OFF)*/

#if ((PDUR_ZERO_COST_OPERATION == STD_OFF) && (PDUR_LO_RXINDICATION == STD_ON))
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, PDUR_VAR) PduR_DETCheckLoRxIndication(
  PduIdType LddRxPduId, uint8 LucModuleType, uint8 LucAPIId,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_VAR) LpPduInfoPtr);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* #if ((PDUR_ZERO_COST_OPERATION == STD_OFF) &&
                                           (PDUR_LO_RXINDICATION == STD_ON)) */
#endif /* #if (PDUR_DEV_ERROR_DETECT == STD_ON)*/

#if ((PDUR_FIFO_TX_BUFFER_SUPPORT == STD_ON) ||\
  (PDUR_SB_TX_BUFFER_SUPPORT == STD_ON))
#if (PDUR_IF_GATEWAY_OPERATION == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
extern FUNC(boolean, PDUR_VAR) PduR_GWBufferUpdate
(P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr,
  P2CONST(PduR_LoGWRxIndication, AUTOMATIC, PDUR_CONST) LpGWIfPdu);
#else
extern FUNC(void, PDUR_VAR) PduR_GWBufferUpdate
(P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr,
  P2CONST(PduR_LoGWRxIndication, AUTOMATIC, PDUR_CONST) LpGWIfPdu);
#endif
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* #if (PDUR_DEV_ERROR_DETECT == STD_ON)*/
#endif

#if (PDUR_IF_GATEWAY_OPERATION == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
#if ((PDUR_DEV_ERROR_DETECT == STD_ON) && \
((PDUR_FIFO_TX_BUFFER_SUPPORT == STD_ON) || \
(PDUR_SB_TX_BUFFER_SUPPORT == STD_ON)))
extern FUNC(boolean, PDUR_VAR) PduR_GWLoRxIndication(PduIdType LddRxPduId,
       P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr);
#else
extern FUNC(void, PDUR_VAR) PduR_GWLoRxIndication(PduIdType LddRxPduId,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr);
#endif
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* #if (PDUR_DEV_ERROR_DETECT == STD_ON)*/


#endif /* PDUR_RXLO_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
