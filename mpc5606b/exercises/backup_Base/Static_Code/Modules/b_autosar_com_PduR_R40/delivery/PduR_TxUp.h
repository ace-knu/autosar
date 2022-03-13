/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: PduR_TxUp.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR PDU Router                                            **
**                                                                            **
**  PURPOSE   : Header file of PduR_TxUp.c                                    **
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
** 2.0.8     10-Jun-2016   Chan Kim    Redmine #5143                          **
** 2.0.0     11-Aug-2015   Chan Kim    Redmine #2949                          **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/
#ifndef PDUR_TXUP_H
#define PDUR_TXUP_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version information */
#define PDUR_TXUP_AR_RELEASE_MAJOR_VERSION    4
#define PDUR_TXUP_AR_RELEASE_MINOR_VERSION    0
#define PDUR_TXUP_AR_RELEASE_REVISION_VERSION 3

/* PDUR software version information */
#define PDUR_TXUP_SW_MAJOR_VERSION            2
#define PDUR_TXUP_SW_MINOR_VERSION            2
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if ((PDUR_IF_TRANSMIT == STD_ON)||(PDUR_TP_TRANSMIT == STD_ON))
#define PDUR_START_SEC_CODE
#include "MemMap.h"
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_UpTransmit(PduIdType LddTxPduId,
  uint8 LucAPIId, uint8 LucModuleType,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr);

#else
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_UpTransmit(PduIdType LddTxPduId,
 P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr);

#endif
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if ((PDUR_IF_TRANSMIT == STD_ON)||
        *(PDUR_TP_TRANSMIT == STD_ON))*/
#endif /* End of if (PDUR_ZERO_COST_OPERATION == STD_OFF) */

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if ((PDUR_IF_TRANSMIT == STD_ON)||(PDUR_TP_TRANSMIT == STD_ON))
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_DETCheckUpTransmit(
  PduIdType LddTxPduId, uint8 LucAPIId, uint8 LucModuleType,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (PDUR_DEV_ERROR_DETECT == STD_ON) */
#endif /* End of if ((PDUR_IF_TRANSMIT == STD_ON)||
        *(PDUR_TP_TRANSMIT == STD_ON))*/
#endif /* End of if (PDUR_ZERO_COST_OPERATION == STD_ON) */

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if ((PDUR_IF_CANCEL_TRANSMIT_SUPPORT == STD_ON) ||\
  (PDUR_TP_CANCEL_TRANSMIT_SUPPORT == STD_ON))
#define PDUR_START_SEC_CODE
#include "MemMap.h"
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
extern FUNC(Std_ReturnType, PDUR_CODE)PduR_UpCancelTransmit(PduIdType LddTxPduId,
  uint8 LucAPIId, uint8 LucModuleType);

#else
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_UpCancelTransmit(PduIdType
                                                                    LddTxPduId);

#endif
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if ((PDUR_IF_CANCEL_TRANSMIT_SUPPORT == STD_ON) ||\
  (PDUR_TP_CANCEL_TRANSMIT_SUPPORT == STD_ON))
#if ((PDUR_IF_TRANSMIT == STD_ON)||(PDUR_TP_TRANSMIT == STD_ON))     
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_DETCheckCancelTransmit(
  PduIdType LddTxPduId, uint8 LucAPIId, uint8 LucModuleType);
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
#endif
#endif


#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if (PDUR_TP_TRANSMIT == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_TpTransmit
(P2CONST(PduR_UpTx, AUTOMATIC, PDUR_CONST) LpUpTransmit,
P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr);
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if (PDUR_IF_TRANSMIT == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_IfTransmit
(P2CONST(PduR_UpTx, AUTOMATIC, PDUR_CONST) LpUpTransmit,
P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) LpPduInfoPtr);
#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif

#endif /* PDUR_TXUP_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
