/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Det.c                                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Development Error Tracer                              **
**                                                                            **
**  PURPOSE   : This file contains the API definitions for Det module         **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By              Description                        **
********************************************************************************
** 1.0.2     30-May-2017   EunKyung Kim    Changes made As per Redmine #8700, **
**                                         #8703							  **
**                                                                            **
** 1.0.1     07-Mar-2013   Nitin Kumar     1. Precompile option               **
**                                         "DET_NOTIFY_FUNC" has been added to**
**                                         Det_Init and Det_ReportError API.  **
**                                         2. Pointer class and memclass has  **
**                                         been updated for "LpErrors".       **
**                                         3. Global variable                 **
**                                         Det_GusErrorCount and precompile   **
**                                         option DET_ERROR_COUNT_SUPPORT     **
**                                         has been removed.                  **
**                                                                            **
** 1.0.0     01-Jan-2013   Autron          Initial Version                    **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Det.h"                    /* Header file of DET */
#include "Det_Cfg.h"                /* Det Cfg header file */
#include "Det_PCTypes.h"            /* Det PCTypes file */
#include "Det_Ram.h"                /* Det Ram header file */
#include "Rte_Det.h"
#if (DET_RAM_BUFFER == STD_ON)
#include "SchM_Det.h"                /* Header file of SCHM */
#endif
#include "Det_Version.h"            /* Det Version header file */
#if (DET_FORWARD_TO_DLT == STD_ON)
#include "Dlt.h"                    /* Header file of DLT */
#endif


/*******************************************************************************
**                      Global Types                                          **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name       : Det_GetVersionInfo                                   **
**                                                                            **
** Service ID          : 0x03                                                 **
**                                                                            **
** Description         : This service gives version information of the Det    **
**                       module. The version information includes module Id,  **
**                       vendor Id, InstanceId & vendor specific version no's **
**                                                                            **
** Sync/Async          : Synchronous                                          **
**                                                                            **
** Re-entrancy         : Reentrant                                            **
**                                                                            **
** Input Parameters    : None                                                 **
**                                                                            **
** InOut Parameters    : None                                                 **
**                                                                            **
** Output Parameters   : versioninfo                                          **
**                                                                            **
** Return parameter    : None                                                 **
**                                                                            **
** Preconditions       : None                                                 **
**                                                                            **
** Remarks             : This function shall be pre compile time configurable **
**                       On/Off by the configuration parameter                **
**                       DET_VERSION_INFO_API                                 **
**                       Global Variable(s)  : None                           **
**                       Function(s) invoked : Det_ReportError                **
*******************************************************************************/
/* Check Pre-compile option enabled for versioninfo API */
#if (DET_VERSION_INFO_API == STD_ON)
#define DET_START_SEC_CODE
#include "MemMap.h"
FUNC(void, DET_CODE) Det_GetVersionInfo(P2VAR(Std_VersionInfoType,
  AUTOMATIC, DET_APPL_DATA) versioninfo)
{
  /* Check whether the pointer passed to API is Null Pointer */
  if (versioninfo == NULL_PTR)
  {
    /* The Development Error Tracer shall not deliver the version information
     *   if the received version info pointer is NULL and shall raise the Error
     *   DET_E_PARAM_POINTER and return without any further action  */
    (void)Det_ReportError(DET_MODULE_ID, DET_INSTANCE_ID,
      DET_GETVERSIONINFO_SID, DET_E_PARAM_POINTER);
  }
  else
  {
    /* Copy the vendor Id */
    versioninfo->vendorID = DET_VENDOR_ID;

    /* Copy the module Id */
    versioninfo->moduleID = DET_MODULE_ID;

    /* Copy Software Major Version */
    versioninfo->sw_major_version = DET_SW_MAJOR_VERSION;

    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = DET_SW_MINOR_VERSION;

    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = DET_SW_PATCH_VERSION;
  } /* End of else */
} /* End of Det_GetVersionInfo */

#define DET_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (DET_VERSION_INFO_API == STD_ON) */

/*******************************************************************************
** Function Name      : Det_Init                                              **
**                                                                            **
** Service ID         : 0x00                                                  **
**                                                                            **
** Description        : This function is used to clear the logged errors and  **
**                      the reported error count.                             **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : None                                                  **
**                                                                            **
** InOut Parameters   : None                                                  **
**                                                                            **
** Output Parameters  : None                                                  **
**                                                                            **
** Return parameter   : None                                                  **
**                                                                            **
** Preconditions      : None                                                  **
**                                                                            **
** Remarks            : Global Variable(s) :Det_GusErrorsBuffIndex,           **
**                                          Det_GblInitStatus                 **
**                      Function(s) invoked:None                              **
*******************************************************************************/
#define DET_START_SEC_CODE
#include "MemMap.h"
FUNC(void, DET_CODE) Det_Init(void)
{
  #if (DET_RAM_BUFFER == STD_ON)

  /* Initialize RAM buffer index */
  Det_GusErrorsBuffIndex = DET_ZERO;
  #endif /* #if(DET_RAM_BUFFER == STD_ON) */

  /* Update the module init status variable */
  Det_GblInitStatus = DET_INITIALIZED;
} /* End of Det_Init */

#define DET_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Det_ReportError                                       **
**                                                                            **
** Service ID         : 0x01                                                  **
**                                                                            **
** Description        : Development Error Tracer to report errors.            **
**                                                                            **
** Sync/Async         : Depending on implemented functionality: 1. Breakpoint **
**                      set: no return 2. Internal error counting/logging in  **
**                      RAM: synchronous 3. External error logging via        **
**                      communication interface: asynchronous                 **
**                                                                            **
** Re-entrancy        : Reentrant                                             **
**                                                                            **
** Input Parameters   : uint16 ModuleId                                       **
**                      uint8 InstanceId                                      **
**                      uint8 ApiId                                           **
**                      uint8 ErrorId                                         **
**                                                                            **
** InOut Parameters   : None                                                  **
**                                                                            **
** Output Parameters  : None                                                  **
**                                                                            **
** Return parameter   : Std_ReturnType                                        **
**                                                                            **
** Preconditions      : None                                                  **
**                                                                            **
** Remarks            : Global Variable(s) :Det_GusErrorsBuffIndex            **
**                                          Det_GaaErrors                     **
**                                          Det_GblInitStatus                 **
**                      Function(s) invoked:Dlt_DetForwardErrorTrace(),       **
**                                       SchM_Enter_Det_RAM_DATA_PROTECTION(),**
**                                       SchM_Exit_Det_RAM_DATA_PROTECTION()  **
*******************************************************************************/
#define DET_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, DET_CODE) Det_ReportError(uint16 ModuleId, uint8
  InstanceId, uint8 ApiId, uint8 ErrorId)
{
  #if (DET_RAM_BUFFER == STD_ON)
  P2VAR(Det_ErrorType, AUTOMATIC, DET_APPL_DATA) LpErrors;
  #endif
  Std_ReturnType LddReturnVal;
  #if (DET_ERROR_HOOK == STD_ON)
  uint16 LusErrCount;

  LusErrCount = DET_ZERO;
  #endif

  /* This API call will be always success */
  LddReturnVal = E_OK;

  if ((Det_GblInitStatus == DET_INITIALIZED)
  #if (DET_RAM_BUFFER == STD_ON)
      && (Det_GusErrorsBuffIndex < DET_RAM_BUFFER_SIZE)
  #endif
     )
  {
    #if (DET_ERROR_HOOK == STD_ON)

    /* Invoke configured Error Hook Functions */
    for(; LusErrCount < DET_TOTAL_ERROR_HOOKS; LusErrCount++)
    {
      (void)(*Det_GaaErrorHook[LusErrCount]) (ModuleId, InstanceId, ApiId,
        ErrorId);
    } 

    #endif

    #if (DET_FORWARD_TO_DLT == STD_ON)

    /* Forward error to Dlt */
    Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, ErrorId);
    #endif

    #if (DET_RAM_BUFFER == STD_ON)

    /* Invoke function to enable data protection */
    SchM_Enter_Det_RAM_DATA_PROTECTION();

    /* Get a pointer to point global structure Det_GaaErrors */
    LpErrors = &Det_GaaErrors[Det_GusErrorsBuffIndex];

    /* Store development error parameter got through Det_ReportError function */
    LpErrors->usModuleId = ModuleId;
    LpErrors->ucInstanceId = InstanceId;
    LpErrors->ucApiId = ApiId;
    LpErrors->ucErrorId = ErrorId;

    /* Increment array of structure index */
    Det_GusErrorsBuffIndex++;

    if (Det_GusErrorsBuffIndex >= DET_RAM_BUFFER_SIZE)
    {
      /* Initialize array of structure index */
      Det_GusErrorsBuffIndex = DET_ZERO;
    }
    else
    {
      /* To avoid QAC warning */
    }

    /* Invoke function to disable data protection */
    SchM_Exit_Det_RAM_DATA_PROTECTION();
    #endif
  } /* End of if (Det_GblInitStatus == DET_INITIALIZED) */
  else
  {
    /* To avoid QAC warning */
  }
  return (LddReturnVal);
} /* End of Det_ReportError */

#define DET_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Det_Start                                             **
**                                                                            **
** Service ID         : 0x02                                                  **
**                                                                            **
** Description        : This functionality is defined when development errors **
**                      are logged via communication interface                **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : None                                                  **
**                                                                            **
** InOut Parameters   : None                                                  **
**                                                                            **
** Output Parameters  : None                                                  **
**                                                                            **
** Return parameter   : None                                                  **
**                                                                            **
** Preconditions      : None                                                  **
**                                                                            **
** Remarks            : Global Variable(s) :None                              **
**                      Function(s) invoked:None                              **
*******************************************************************************/
#define DET_START_SEC_CODE
#include "MemMap.h"
FUNC(void, DET_CODE) Det_Start(void)
{
  /* Empty function */
}

#define DET_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
