/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_DspResponseOnEvent.h                                      **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_DspResponseOnEvent                           **
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
** 1.0.0     30-01-2013    Autron         Initial Version                     **
*******************************************************************************/

#ifndef DCM_DSPRESPONSEONEVENT_H
#define DCM_DSPRESPONSEONEVENT_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define DCM_START_SEC_CODE
#include "MemMap.h"

#if(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmSetUpRoeEvent
  (uint8 eventTypeRecordLength,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE) Dcm_DspDisableRoe(void);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DspReadROEDIDValue(
          uint16 DIDIndex, P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DIDSize,
          P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) pBuffer);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DspEnableRoe(void);

extern FUNC(void, DCM_CODE) Dcm_DspResetRoe(void);
#if(DCM_ROE_QUEUE_ENABLED == STD_ON)
extern FUNC(void, DCM_CODE) Dcm_DspClearQueue(void);
#endif

#if(DCM_MAX_NO_OF_PRECONFIGURED_DID != DCM_ZERO)
extern FUNC(void, DCM_CODE) Dcm_DspRestorePreconfigDID(void);
#endif
extern FUNC(void, DCM_CODE) Dcm_DcmResponseOnEvent(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

#if(DCM_ROE_QUEUE_ENABLED == STD_ON)
extern FUNC(void, DCM_CODE) Dcm_DspSetQueueIndex(boolean QueueMode);

extern FUNC(Std_ReturnType, DCM_CODE)
  Dcm_DspQueueRoeEvents(uint8 IdIndex);

#endif

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_StopROE(void);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_RestartROE(void);

#if(DCM_EXTERNAL_ROE_ENABLED == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_TriggerOnEvent(
  uint8 RoeEventId);
#endif
#endif

#if(DCM_MAX_NO_OF_PRECONFIGURED_DID != DCM_ZERO)
extern FUNC(void, DCM_CODE) Dcm_StoreRoeEvent(void);


extern FUNC(void, DCM_CODE) Dcm_RetrieveStoredRoeEvent(uint8 LucRoepduIdValue);

#endif
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* DCM_DSPRESPONSEONEVENT_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
