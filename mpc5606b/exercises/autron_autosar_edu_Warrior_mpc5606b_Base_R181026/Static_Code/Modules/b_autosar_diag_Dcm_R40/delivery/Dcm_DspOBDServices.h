/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_DspOBDServices.h                                          **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_DspOBDServices                               **
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
** 1.0.1     10-08-2015    Youngjin Yun   #2977                               **
**                                                                            **
** 1.0.0     09-01-2013    Autron         Initial Version                     **
*******************************************************************************/

#ifndef DCM_DSPOBDSERVICES_H
#define DCM_DSPOBDSERVICES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Dcm.h"
#include "Dcm_PCTypes.h"


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define DCM_START_SEC_CODE
#include "MemMap.h"

#if(DCM_OBD_REQCURRENT_POWERTRAIN_DIAGDATA_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmOBDReqCurrentPowerTrainDiagData(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_OBD_REQPOWERTRAIN_FREEZEFRAMEDATA_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmOBDReqPowerTrainFreezeFrameData(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if((DCM_OBD_GETDTC_03_SERVICE == STD_ON) || \
(DCM_OBD_GETDTC_07_SERVICE == STD_ON) || (DCM_OBD_GETDTC_0A_SERVICE == STD_ON))
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmOBDGetDTC(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_OBD_GETDTC_07_SERVICE == STD_ON)
extern FUNC(void, DCM_CODE) Dcm_DcmOBDGetDTC_07
  (P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_OBD_GETDTC_0A_SERVICE == STD_ON)
extern FUNC(void, DCM_CODE) Dcm_DcmOBDGetDTC_0A
  (P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_OBD_CLRRESET_EMISSION_DIAGINFO_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmOBDClrResetEmissionDiagInfo(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_OBD_REQ_ONBOARD_MONITORRESULT_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmOBDReqOnboadMonitorResult(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
extern FUNC(void, DCM_CODE)Dcm_DcmOBDReqOnboadMonitorResultCall(
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpReqResData,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpTxBuffer, uint8 LucOBDMIDCount,
  P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) LpResLength);
#endif

#if(DCM_OBD_REQ_CTLRL_ONBOADSYSTEM_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmOBDReqCtlrOnboadSystem(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_OBD_REQVEHICLE_INFO_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmOBDRegVehicleInfo(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE) Dcm_DcmOBDRegVehicleInfoCall(
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpReqResData,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpTxBuffer, uint8 LucVIDCount,
  P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) LpRespLength
  );
#endif

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DCM_DSPOBDSERVICES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
