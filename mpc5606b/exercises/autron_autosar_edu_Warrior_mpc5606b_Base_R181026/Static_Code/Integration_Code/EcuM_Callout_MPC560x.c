/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : EcuM_Callout_MPC560x.c                                        **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR EcuM Module                                           **
**                                                                            **
**  PURPOSE   :  Callouts implementation for EcuM module                      **
**               EcuM_AL_DriverInitZero                                       **
**               EcuM_AL_DriverInitOne                                        **
**               EcuM_AL_DriverRestart                                        **
**               EcuM_AL_SetProgrammableInterrupts                            **
**               EcuM_OnGoOffOne                                              **
**               EcuM_OnGoOffTwo                                              **
**               EcuM_AL_SwitchOff                                            **
**               EcuM_AL_Reset                                                **
**               EcuM_EnableWakeupSources                                     **
**               EcuM_DisableWakeupSources                                    **
**               EcuM_ClearWakeupInterrupts                                   **
**               EcuM_CheckWakeup                                             **
**               EcuM_StartWakeupSources                                      **
**               EcuM_StopWakeupSources                                       **
**               EcuM_CheckValidation                                         **
**               EcuM_GenerateRamHash                                         **
**               EcuM_SleepActivity                                           **
**               EcuM_CheckRamHash                                            **
**               EcuM_DeterminePbConfiguration                                **
**               EcuM_ErrorHook                                               **
**               EcuM_LoopDetection                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                              Revision History                              **
********************************************************************************
** Revision   Date          By            Description                         **
********************************************************************************
** 2.4.1      27-May-2015   Jihoon Jung   Redmine #2550                       **
** 2.2.1      26-Dec-2014   Daejun Park   Redmine #1879, #2094                **
**                                        -Update to AUTRON template          **
**                                        -Bug fix in case larger than        **
**                                         63ms alarm                         **
** 2.2.0      25-Nov-2014   Daejun Park   Redmine #1536                       **
** 1.0.12     13-Dec-2013   Daejun Park   CR~208, XAR~779                     **
**                                        -Move pre-compile condition         **
**                                         from EcuM.c                        **
** 1.0.0      04-Mar-2013   Daejun Park   Initial version                     **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "EcuM.h"
#include "EcuM_Config.h"
#include "EcuM_Cbk.h"    /* ECU State Manager Callout-Callback Header File */
#include "EcuM_Generated_Callouts.h"
#include "EcuM_Ram.h"
#include "BswM_EcuM.h"
#include "Mcu.h"
#include "SchM_EcuM.h"
#include "Rte_EcuM.h"

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
#include "Gpt.h"
#endif

#include "Can.h"
#include "ComM.h"

#include "Reg_Macros.h"
#include "Reg_eSys_MagicCarpet.h"

#include "Wdg_39_Acw.h"
#include "Wdg.h"
#include "WdgM.h"


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : EcuM_AL_DriverInitZero                              **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout shall provide driver initialization    **
**                        and other hardware-related startup activities for   **
**                        loading the post-build configuration data. Note:    **
**                        Here only pre-compile and link-time configurable    **
**                        modules may be used.                                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked :                               **
**                        EcuM_Gen_AL_DriverInitZero                          **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_DriverInitZero(void)
{
  #if (ECUM_DRIVER_INIT_ZERO == STD_ON)
  EcuM_Gen_AL_DriverInitZero();
  #endif
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_AL_DriverInitOne                               **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout shall provide driver initialization    **
**                        and other hardware-related startup activities in    **
**                        case of a power on reset                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ConfigPtr                                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked :                               **
**                        EcuM_Gen_AL_DriverInitOne                           **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_DriverInitOne
  (P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONST) ConfigPtr)
{
  #if (ECUM_DRIVER_INIT_ONE == STD_ON)
  EcuM_Gen_AL_DriverInitOne(ConfigPtr);
  #endif

  Wdg_Init(&WdgSettingsConfig);
  Wdg_39_Acw_Init(NULL_PTR);
  WdgM_Init(NULL_PTR);
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_AL_DriverRestart                               **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout shall provide driver initialization    **
**                        and other hardware-related startup activities in    **
**                        case of a power on reset.                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ConfigPtr                                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked :                               **
**                        EcuM_Gen_AL_DriverRestart                           **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_DriverRestart
  (P2CONST (EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONST) ConfigPtr)
{
  #if (ECUM_DRIVER_RESTART == STD_ON)
  EcuM_Gen_AL_DriverRestart(ConfigPtr);
  #endif
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_AL_SetProgrammableInterrupts                   **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This call allows the system designer to notify that **
**                        the GO OFF I state is about to be entered.          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_SetProgrammableInterrupts(void)
{
  /* Callout shall be filled by the system designer */
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_OnGoOffOne                                     **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This call allows the system designer to notify that **
**                        the GO OFF I state is about to be entered.          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(void, ECUM_CALLOUT_CODE) EcuM_OnGoOffOne(void)
{
  EcuM_GddState = ECUM_STATE_GO_OFF_ONE;

  /* Indicate state change to BswM */
  BswM_EcuM_CurrentState(EcuM_GddState);
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_OnGoOffTwo                                     **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This call allows the system designer to notify that **
**                        the GO OFF II state is about to be entered.         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(void, ECUM_CALLOUT_CODE) EcuM_OnGoOffTwo(void)
{
  EcuM_GddState = ECUM_STATE_GO_OFF_TWO;
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_AL_SwitchOff                                   **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout shall take the code for shutting off   **
**                        the power supply of the ECU. If the ECU cannot      **
**                        unpower itself, a reset may be an adequate reaction.**
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_SwitchOff(void)
{
  /* Callout shall be filled by the system designer */
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_AL_Reset                                       **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout shall take the code for shutting off   **
**                        the power supply of the ECU. If the ECU cannot      **
**                        unpower itself, a reset may be an adequate reaction.**
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : reset                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_Reset(EcuM_ResetType reset)
{
  Mcu_PerformReset();
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_EnableWakeupSources                            **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : The ECU Manager Module calls EcuM_EnableWakeupSource**
**                        to allow the system designer to notify wakeup       **
**                        sources defined in the wakeupSource bitfield that   **
**                        SLEEP will be entered and to adjust their source    **
**                        accordingly.                                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : wakeupSource                                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(void, ECUM_CODE) EcuM_EnableWakeupSources
  (EcuM_WakeupSourceType wakeupSource)
{

}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_DisableWakeupSources                           **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : The callout shall set up the given wakeup source(s) **
**                        so that they are not able to wakeup the ECU.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : wakeupSource                                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(void, ECUM_CODE) EcuM_DisableWakeupSources
  (EcuM_WakeupSourceType wakeupSource)
{

}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_CheckWakeup                                    **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout is called by the EcuM to poll a wakeup **
**                        source. It shall also be called by the ISR of a     **
**                        wakeup source to set up the PLL and check other     **
**                        wakeup sources that may be connected to the same    **
**                        interrupt.                                          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : wakeupSource                                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(void, ECUM_CALLOUT_CODE) EcuM_CheckWakeup
  (EcuM_WakeupSourceType wakeupSource)
{
  #if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
  if (wakeupSource == ECUM_ALARM_WAKEUP_SOURCE_ID)
  {
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    Gpt_CheckWakeup(wakeupSource);
    #endif
  }
  #endif

  if (wakeupSource == ECUM_WKSOURCE_CAN1RX)
  {
    /* Wakeup Sequence */
    Can_CheckWakeup(wakeupSource);
  }
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_StartWakeupSources                             **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : The callout shall start the given wakeup source(s)  **
**                        so that they are ready to perform wakeup validation.**
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : wakeupSource                                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(void, ECUM_CALLOUT_CODE) EcuM_StartWakeupSources
  (EcuM_WakeupSourceType wakeupSource)
{
  /* Callout shall be filled by the system designer */
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_StopWakeupSources                              **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : The callout shall stop the given wakeup source(s)   **
**                        after unsuccessful wakeup validation.               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : EcuM_WakeupSourceType wakeupSource                  **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(void, ECUM_CALLOUT_CODE) EcuM_StopWakeupSources
  (EcuM_WakeupSourceType wakeupSource)
{
  /* Callout shall be filled by the system designer */
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_CheckValidation                                **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout is called by the EcuM to validate a    **
**                        wakeup source. If a valid wakeup has been detected, **
**                        it shall be reported to EcuM via                    **
**                        EcuM_ValidateWakeupEvent().                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : wakeupSource                                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(void, ECUM_CALLOUT_CODE) EcuM_CheckValidation
  (EcuM_WakeupSourceType wakeupSource)
{
  /* Callout shall be filled by the system designer */
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_GenerateRamHash                                **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : Used just before Putting the ECU physically to sleep**
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(void, ECUM_CALLOUT_CODE) EcuM_GenerateRamHash(void)
{
  /* Callout shall be filled by the system designer */
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_SleepActivity                                  **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout is invoked periodically in all reduced **
**                        clock sleep modes. It is explicitly allowed to poll **
**                        wakeup sources from this callout and to call wakeup **
**                        notification functions to indicate the end of the   **
**                        sleep state to the ECU State Manager.               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(void, ECUM_CALLOUT_CODE) EcuM_SleepActivity(void)
{
  /* Callout shall be filled by the system designer */
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_CheckRamHash                                   **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout is intended to provide a RAM integrity **
**                        test.                                               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(uint8, ECUM_CALLOUT_CODE) EcuM_CheckRamHash(void)
{
  return (1);
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_DeterminePbConfiguration                       **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout should evaluate some condition,        **
**                        like port pin or NVRAM value, to determine which    **
**                        post-build configuration shall be used in the       **
**                        remainder of the startup process. It shall load     **
**                        this configuration data into a piece of memory that **
**                        is accessible by all BSW modules and shall return a **
**                        pointer to the EcuM post-build configuration as a   **
**                        base for all BSW module post-build configurations.  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : EcuM_ConfigType*                                    **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        EcuM_GaaConfig                                      **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(P2CONST(EcuM_ConfigType, ECUM_CONST, ECUM_APPL_CONST),
  ECUM_CALLOUT_CODE) EcuM_DeterminePbConfiguration(void)
{
  /* The return value is updated only for compilation purpose. Valid address of
   *   EcuM_GaaConfig structure needs to be provided here. MISRA Rule 11.3 is
   * not considered in this case */
  P2CONST(EcuM_ConfigType, ECUM_CONST, ECUM_CONST) LpConfigPtr;
  LpConfigPtr = &EcuM_GaaConfig[0];
  return (LpConfigPtr);
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_ErrorHook                                      **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : In unrecoverable error situations, the ECU State    **
**                        Manager will call this callout. It is up the        **
**                        system integrator to react accordingly              **
**                        (reset, halt, restart, safe state etc. )            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : reason                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(void, ECUM_CALLOUT_CODE) EcuM_ErrorHook(Std_ReturnType reason)
{
  /* Callout shall be filled by the system designer */
  ECUM_UNUSED(reason);
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_LoopDetection                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Callout used for reset loop detection               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : void                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(void, ECUM_CALLOUT_CODE) EcuM_LoopDetection(void)
{
  /* Turn to reset mode if current mode is safe mode */
  /* polyspace<RTE: ABS_ADDR : Not a defect : No Action Planned > Macro that is defined by MCAL. */
  /* polyspace<MISRA-C:11.3:Not a defect:Justify with annotations> Macro that is defined by MCAL. */
  if ((REG_READ32(MC_ME_GS_R) & ME_GS_CURRENT_MODE) == ME_GS_CURRENT_MODE_SAFE)
  {
    Mcu_PerformReset();
  }
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
