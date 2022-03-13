/*******************************************************************************
**                            HYUNDAI MOTORS GROUP                            **
**                                                                            **
**                            All rights reserved                             **
**                                                                            **
**            You can NOT use this sample code for Product Release            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os.h"
#include "OsHook.h"
#include "Os_Debug.h"
#include "EcuM.h"
#if (OS_ERRM_USED == STD_ON)
#include "ErrM.h"
#endif
#include "Opf_OsProfiler.h"
#include "App_OsHook.h"


/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

#define OSHOOK_START_SEC_CODE
#include "Os_memmap.h"

FUNC(void, OS_CODE) ErrorHook(StatusType Error)
{
  /* Do not modify : Start */
  #if (OPF_PROFILE_ENABLED == STD_ON)
  if (E_OS_LIMIT == Error)
  {
    Opf_SetLimitErrorEvent();
  }
  #endif

  Os_UpdateOsErrorInfo(Error);
  #if (OS_ERRM_USED == STD_ON)
  ErrM_OsErrorNotification(Error);
  #else
  AppCallbackOnSystemError(Error);
  #endif
  /* Do not modify : End */
}

FUNC(void, OS_CODE) PreTaskHook(void)
{
  /* Do not modify : Start */
  #if (OPF_PROFILE_ENABLED == STD_ON)
  Opf_SetPreTaskEvent();
  #endif

  #if (OS_DEBUG_CPULOAD == STD_ON)
  Os_ResetIdleEntry();
  #endif
  /* Do not modify : End */
}

FUNC(void, OS_CODE) PostTaskHook(void)
{
  #if (OPF_PROFILE_ENABLED == STD_ON)
  Opf_SetPostTaskEvent();
  #endif
}

FUNC(void, OS_CODE) StartupHook(void)
{
  /* Do not modify : Start */
  #if (OPF_PROFILE_ENABLED == STD_ON)
  Opf_InitOsProfiler();
  Opf_StartOsProfiler();
  #endif
  #if (OS_DEBUG_STACKDEPTH == STD_ON)
  Os_FillMainStackPattern();
  #endif
  #if (OS_DEBUG_CPULOAD == STD_ON)
  Os_InitCPULoad();
  #endif
  /* Do not modify : End */
}

FUNC(void, OS_CODE) ShutdownHook(StatusType Error)
{
  /* Do not modify : Start */
  Os_UpdateOsErrorInfo(Error);
  #if (OS_ERRM_USED == STD_ON)
  ErrM_OsErrorNotification(Error);
  #else
  AppCallbackOnSystemError(Error);
  #endif
  EcuM_Shutdown();
  /* Do not modify : End */
}

FUNC(void, OS_CODE) PreIsrHook(void)
{
  /* Do not modify : Start */
  #if (OPF_PROFILE_ENABLED == STD_ON)
  Opf_SetPreIsrEvent();
  #endif

  #if (OS_DEBUG_CPULOAD == STD_ON)
  Os_ITEntryForCPULoad();
  #endif

  /* Do not modify : End */
}

FUNC(void, OS_CODE) PostIsrHook(void)
{
  /* Do not modify : Start */
  
  #if (OPF_PROFILE_ENABLED == STD_ON)
  Opf_SetPostIsrEvent();
  #endif

  #if (OS_DEBUG_CPULOAD == STD_ON)
  Os_ITExitForCPULoad();
  #endif
  /* Do not modify : End */
}

#if (OS_ERRM_USED == STD_OFF)
FUNC(void, OS_CODE) AppCallbackOnSystemError(StatusType ErrorId)
{
  if ((ErrorId == (StatusType)_E_OS_SYS_MACHINECHECK) ||
      (ErrorId == (StatusType)_E_OS_SYS_DATASTORAGE))
  {
    /* ECC Error occurred!! */
  }
}
#endif

FUNC(void, OS_CODE) Opf_StartOsProfilerWrap()
{
  /* Do not modify : Start */
  #if (OPF_PROFILE_ENABLED == STD_ON)
  Opf_StartOsProfiler();
  #endif
  /* Do not modify : End */
}

FUNC(void, OS_CODE) Opf_StopOsProfilerWrap()
{
  /* Do not modify : Start */
  #if (OPF_PROFILE_ENABLED == STD_ON)
  Opf_StopOsProfiler();
  #endif
  /* Do not modify : End */
}

#define OSHOOK_STOP_SEC_CODE
#include "Os_memmap.h"
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

