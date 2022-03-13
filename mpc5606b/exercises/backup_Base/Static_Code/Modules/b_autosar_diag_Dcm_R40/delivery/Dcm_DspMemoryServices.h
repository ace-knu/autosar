/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_DspMemoryServices.h                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_DspMemoryServices                            **
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

#ifndef DCM_DSPMEMORYSERVICES_H
#define DCM_DSPMEMORYSERVICES_H
/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/*
polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard-Chap 5.1.2)
*/
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

#if(DCM_READ_MEMORY_BY_ADDRESS_SERVICE == STD_ON)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmReadMemoryByAddress(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE)Dcm_DcmReadMemoryCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_WRITE_MEMORY_BY_ADDRESS_SERVICE == STD_ON)

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmWriteMemoryByAddress(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE) Dcm_DcmWriteMemoryCall
  (P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_REQUEST_DOWNLOAD_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmRequestDownLoad(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE) Dcm_DcmDownLoadCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_REQUEST_UPLOAD_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmRequestUpLoad(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern FUNC(void, DCM_CODE) Dcm_DcmUpLoadCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_TRANSFER_DATA_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmTransferData(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern  FUNC(void, DCM_CODE) Dcm_DownLoadTransferCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
extern  FUNC(void, DCM_CODE)Dcm_UpLoadTransferCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#if(DCM_TRANSFER_EXIT_SERVICE == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmRequestTransferExit(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);

extern  FUNC(void, DCM_CODE)Dcm_RequestTransferExitCall(
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext);
#endif

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/*
polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard-Chap 5.1.2)
*/
#endif /* DCM_DSPMEMORYSERVICES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
