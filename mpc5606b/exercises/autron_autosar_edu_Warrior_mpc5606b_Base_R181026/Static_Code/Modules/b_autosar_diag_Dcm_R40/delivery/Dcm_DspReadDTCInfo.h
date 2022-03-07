/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_DspReadDTCInfo.h                                          **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_DspReadDTCInfo                               **
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

#ifndef DCM_DSPREADDTCINFO_H
#define DCM_DSPREADDTCINFO_H

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

extern FUNC(void, DCM_CODE) Dcm_DspRptDTC(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE) Dcm_DemGetNumberOfReportedDTC(void);

extern FUNC(void, DCM_CODE)
  Dcm_GetNumberOfFilteredDtcBySeverityInfo(void);

extern FUNC(void, DCM_CODE) Dcm_DspRptDTCFltDetCtr(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(uint32, DCM_CODE) Dcm_DspReadReqdDTCInfo(
  uint32 LulBufferSize);

extern FUNC(uint32, DCM_CODE) Dcm_DspReadReqdDTCFDC(
  uint32 LulBufferSize);

extern FUNC(void, DCM_CODE) Dcm_DspRptDTCBySeverityInfo(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(uint32, DCM_CODE) Dcm_DspUpdDTCBySeverityMask(
  uint32 LulBufferSize);

extern FUNC(void, DCM_CODE) Dcm_DspRptDTCBySeverityInfoOfDTC(
 P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DCM_DSPREADDTCINFO_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
