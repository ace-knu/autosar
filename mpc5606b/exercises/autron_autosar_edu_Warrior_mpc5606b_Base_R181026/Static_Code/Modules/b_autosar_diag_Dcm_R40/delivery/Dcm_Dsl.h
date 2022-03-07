/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_Dsl.h                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_Dsl                                          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 1.0.0     09-01-2013    Autron         Initial Version                     **
*******************************************************************************/

#ifndef DCM_DSL_H
#define DCM_DSL_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define DCM_START_SEC_CODE
#include "MemMap.h"

#if(DCM_DSP_SESSION_REF == STD_ON)
extern FUNC(void, DCM_CODE) Dcm_DslSetParameters(void);
#endif

extern FUNC(void, DCM_CODE) Dcm_DslTransmit(PduIdType LddTxPduId,
  boolean LblPeriodicTransmission, boolean LblROETransmission);

extern FUNC(void, DCM_CODE) Dcm_DslStatusReset(void);

#if ((DCM_PROTOCOL_TRANSTYPE2 == STD_ON) && \
    (DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON))
extern FUNC(BufReq_ReturnType, DCM_APPL_CODE)Dcm_DslCopyPeriodicTxData(
  PduIdType DcmTxPduId,
  P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
  P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) TxDataCntPtr);
#endif

#if ((DCM_PROTOCOL_TRANSTYPE2 == STD_ON) && \
    (DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON))
extern FUNC(BufReq_ReturnType, DCM_APPL_CODE)Dcm_DslCopyROETxData(
  P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
  P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) TxDataCntPtr);
#endif

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DCM_DSL_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
