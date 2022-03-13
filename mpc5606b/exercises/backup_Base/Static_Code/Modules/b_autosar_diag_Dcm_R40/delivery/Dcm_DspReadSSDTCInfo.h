/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_DspReadSSDTCInfo.h                                        **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_DspReadSSDTCInfo                             **
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

#ifndef DCM_DSPREADSSDTCINFO_H
#define DCM_DSPREADSSDTCINFO_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define DCM_START_SEC_CODE
#include "MemMap.h"

#if((DCM_RPT_DTCSNAPSHOTREC_BYDTCNUM == STD_ON) || \
(DCM_RPT_DTCSNAPSHOTREC_BYSNAPSHOTNUM == STD_ON) || \
(DCM_RPT_DTCEXTENDEDDATARECORD == STD_ON))
extern FUNC(void, DCM_CODE) Dcm_DspRptDTCSnapshotRecByDTCNum(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif
extern FUNC(uint32, DCM_CODE) Dcm_DspRepDTCSnapRecID(
  uint32 LulBufferSize);

extern FUNC(uint32, DCM_CODE) Dcm_DspProcessSubFctFFData(
  uint8 LucRecordNumber, uint32 LulBufferSize);

extern FUNC(void, DCM_CODE) Dcm_DspUpdateBasicsOfEventData(void);

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DCM_DSPREADSSDTCINFO_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
