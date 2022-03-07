/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_DslInternal.h                                             **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_DslInternal                                  **
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
** 1.0.1     26-02-2015    Sungeol Baek   #2163                               **
**                                                                            **
** 1.0.0     09-01-2013    Autron         Initial Version                     **
*******************************************************************************/

#ifndef DCM_DSLINTERNAL_H
#define DCM_DSLINTERNAL_H

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

extern FUNC(void, DCM_CODE)Dcm_DslPduRTransmit(void);

/* sg.baek 022305 - Task #2163 in redmine */
extern FUNC(void, DCM_CODE)Dcm_DslCheckPrtclStatus(void);

#if(DCM_DEV_ERROR_DETECT == STD_ON)
extern FUNC(void, DCM_CODE)Dcm_DslTxIncorrectCondition(uint8 API_ServiceId);
#else
extern FUNC(void, DCM_CODE)Dcm_DslTxIncorrectCondition(void);
#endif	

extern FUNC(void, DCM_CODE) Dcm_DslSetSesTimingValues
     (P2CONST(Dcm_TimerServerType, AUTOMATIC, DCM_APPL_DATA) TimerServerNew);

extern FUNC(void, DCM_CODE) DslInternal_SetSesCtrlType
    (Dcm_SesCtrlType LddSesCtrlType);

extern FUNC(void, DCM_CODE) DslInternal_SetSecurityLevel
  (Dcm_SecLevelType SecurityLevel);

/*******************************************************************************
**                     Periodic transmission handling                         **
*******************************************************************************/
#if(DCM_READ_DATA_BYPERIODICIDENTIFIER_SERVICE == STD_ON)

extern FUNC(Dcm_StatusType, DCM_CODE)
  DslInternal_ResponseOnOneDataByPeriodicId(uint8 PeriodicId);
#endif

/*******************************************************************************
**                     Response On Event handling                             **
*******************************************************************************/

#if(DCM_RESPONSE_ON_EVENT_SERVICE == STD_ON)
extern FUNC(Dcm_StatusType, DCM_CODE)
  DslInternal_ResponseOnOneEvent(const Dcm_MsgType MsgPtr,
  Dcm_MsgLenType MsgLen, PduIdType DcmRxPduId);
#endif

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DCM_DSLINTERNAL_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
