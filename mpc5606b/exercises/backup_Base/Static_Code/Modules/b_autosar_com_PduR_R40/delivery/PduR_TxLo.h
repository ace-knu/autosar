/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: PduR_TxLo.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR PDU Router                                            **
**                                                                            **
**  PURPOSE   : Header file of PduR_TxLo.c                                    **
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
** 2.1.0     17-Jun-2016   Chan Kim    Redmine #5190                          **
** 2.0.5     06-Apr-2016   Chan Kim    Redmine #4519                          **
** 2.0.3     24-Nov-2015   Chan Kim    Redmine #3545, #4519                   **
** 2.0.0     11-Aug-2015   Chan Kim    Redmine #2949                          **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */

#ifndef PDUR_TXLO_H
#define PDUR_TXLO_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version information */
#define PDUR_TXLO_AR_RELEASE_MAJOR_VERSION    4
#define PDUR_TXLO_AR_RELEASE_MINOR_VERSION    0
#define PDUR_TXLO_AR_RELEASE_REVISION_VERSION 3

/* PDUR software version information */
#define PDUR_TXLO_SW_MAJOR_VERSION            2
#define PDUR_TXLO_SW_MINOR_VERSION            2
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/


#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if (PDUR_LO_TXCONFIRMATION == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
extern FUNC(void, PDUR_CODE) PduR_LoTxConfirmation(PduIdType LddTxPduId,
  uint8 LucAPIId, uint8 LucModuleType);
#else
extern FUNC(void, PDUR_CODE) PduR_LoTxConfirmation(PduIdType LddTxPduId);
#endif
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif /* End of if (PDUR_LO_TXCONFIRMATION == STD_ON) */

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if ((PDUR_TRIGGER_TRANSMIT_SUPPORT == STD_ON) &&\
  (PDUR_LO_TXCONFIRMATION == STD_ON))
#define PDUR_START_SEC_CODE
#include "MemMap.h"
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_LoTriggerTransmit(
  PduIdType LddTxPduId, uint8 LucAPIId, uint8 LucModuleType,
  P2VAR(PduInfoType, AUTOMATIC, PDUR_VAR) LpPduInfoPtr);

#else
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_LoTriggerTransmit
  (PduIdType LddTxPduId, P2VAR(PduInfoType, AUTOMATIC, PDUR_VAR) LpPduInfoPtr);

#endif
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if ((PDUR_TRIGGER_TRANSMIT_SUPPORT == STD_ON) &&
        *(PDUR_LO_TXCONFIRMATION == STD_ON)) */
#endif /* End of if (PDUR_ZERO_COST_OPERATION == STD_OFF) */

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if ((PDUR_TRIGGER_TRANSMIT_SUPPORT == STD_ON) &&\
  (PDUR_LO_TXCONFIRMATION == STD_ON))
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_DETCheckLoTriggerTransmit(
  PduIdType LddTxPduId, uint8 LucAPIId, uint8 LucModuleType,
  P2VAR(PduInfoType, AUTOMATIC, PDUR_VAR) LpPduInfoPtr);
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
#endif

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if (PDUR_LO_TXCONFIRMATION == STD_ON)
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"

extern FUNC(boolean, PDUR_CODE) PduR_DETCheckLoTxConfirmation(
  PduIdType LddTxPduId, uint8 LucAPIId, uint8 LucModuleType);
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
#endif

#if ((PDUR_ZERO_COST_OPERATION == STD_OFF) && \
  (PDUR_LO_TXCONFIRMATION == STD_ON))
#if (PDUR_FIFO_TX_BUFFER_SUPPORT == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, PDUR_CODE) PduR_GWLoTxConfirmation(
       P2CONST(PduR_LoTxConf, AUTOMATIC, PDUR_CONST) LpLoTxConfirmation);
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if (PDUR_LO_TXCONFIRMATION == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, PDUR_CODE) PduR_IfTxConfirmation(PduIdType TxPduId);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (PDUR_ZERO_COST_OPERATION == STD_OFF) */
#endif /* End of if (PDUR_LO_TXCONFIRMATION == STD_ON) */

#endif /* PDUR_TXLO_H */

/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
