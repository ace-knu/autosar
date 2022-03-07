/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_DspNonPagedDTCSubFct.h                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_DspNonPagedDTCSubFct                         **
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
** 1.0.0     09-01-2013    Autron          Initial Version                    **
*******************************************************************************/

#ifndef DCM_DSPNONPAGEDDTCSUBFCT_H
#define DCM_DSPNONPAGEDDTCSUBFCT_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Dcm_PCTypes.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define DCM_START_SEC_CODE
#include "MemMap.h"

#if(DCM_RPT_NOOFDTC == STD_ON)
extern FUNC(void, DCM_CODE) Dcm_DspRptNoOfDTC(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE) Dcm_DemGetNumberOfFilteredDtc(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

extern FUNC(void, DCM_CODE) Dcm_DspRptFailedConfirmedDTCInfo(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

#if(DCM_RPT_DTCSNAPSHOTREC_IDENTFN == STD_ON)
extern FUNC(void, DCM_CODE) Dcm_DspRptDTCSnapshotRecIdentfn(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DCM_DSPNONPAGEDDTCSUBFCT_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
