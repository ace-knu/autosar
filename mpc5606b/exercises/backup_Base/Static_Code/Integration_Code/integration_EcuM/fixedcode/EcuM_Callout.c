/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : EcuM_Callout.c                                                **
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
** 2.0.6      14-Dec-2017   Sanghoon Bae  #10953, #10954                      **
** 2.0.4      22-Aug-2017   Sanghoon Bae  #9619                               **
** 2.0.3      09-Aug-2017   Sanghoon Bae  Cypress Preinit Code inserted       ** 
**                                        Redmine #9463                       **
** 2.0.2      20-Feb-2017   Sanghoon Bae  RH850 Temporary solution removed    ** 
**                                        Redmine #7887                       **
** 2.0.0      22-Jul-2016   Sanghoon Bae  New version table for               ** 
**                                        autosar_integration_EcuM            **
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

#include "HwResource.h"

#if (HWRESOURCE_VENDOR(HWRESOURCE_FREESCALE))
#include "Reg_Macros.h"
#include "Reg_eSys_MagicCarpet.h"
#include "WdgStack_Callout.h"
#endif

#if (HWRESOURCE_VENDOR(HWRESOURCE_RENESAS))
#include "Os_service.h"
#endif

#if (HWRESOURCE_FAMILY(HWRESOURCE_S6J32XX))
#include "s6j3200_EIC.h"
#endif

#if (HWRESOURCE_FAMILY(HWRESOURCE_S6J33XX))
#include "s6j3300_EIC.h"
#endif

#if (HWRESOURCE_FAMILY(HWRESOURCE_SPC58XC))
#include "Reg_eSys_Rtc.h"
#include "Reg_eSys_MagicCarpet.h"
#include "Reg_eSys_FCCU.h"
#endif

#if (ECUM_PM_ENABLED == STD_ON)
#include "Pm_Callout.h"
#endif

#if (ECUM_LP_CALLOUT_ENABLED == STD_ON)
#include "LowPower_Callout.h"
#endif
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_DriverInitZero(void)
{
  #if (ECUM_DRIVER_INIT_ZERO == STD_ON)
  EcuM_Gen_AL_DriverInitZero();
  #endif
}

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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_DriverInitOne
  (P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONST) ConfigPtr)
{
  #if (ECUM_DRIVER_INIT_ONE == STD_ON)
  EcuM_Gen_AL_DriverInitOne(ConfigPtr);
  #endif
}

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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_DriverRestart
  (P2CONST (EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONST) ConfigPtr)
{
  #if (ECUM_DRIVER_RESTART == STD_ON)
  EcuM_Gen_AL_DriverRestart(ConfigPtr);
  #endif
}

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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_SetProgrammableInterrupts(void)
{
  /* Callout shall be filled by the system designer */
}

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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_OnGoOffOne(void)
{
  EcuM_GddState = ECUM_STATE_GO_OFF_ONE;

  /* Indicate state change to BswM */
  BswM_EcuM_CurrentState(EcuM_GddState);
}

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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_OnGoOffTwo(void)
{
  EcuM_GddState = ECUM_STATE_GO_OFF_TWO;
}

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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_SwitchOff(void)
{
  EcuM_GddState = ECUM_STATE_OFF;
}

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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_Reset(EcuM_ResetType reset)
{
  EcuM_GddState = ECUM_STATE_RESET;
  
  if (reset == ECUM_RESET_MCU || reset == ECUM_INVALID_SHUTDOWN)
  {
    Mcu_PerformReset();
  }
}

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
FUNC(void, ECUM_CODE) EcuM_EnableWakeupSources
  (EcuM_WakeupSourceType wakeupSource)
{
  EcuM_Gen_EnableWakeupSources(wakeupSource);
}

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
FUNC(void, ECUM_CODE) EcuM_DisableWakeupSources
  (EcuM_WakeupSourceType wakeupSource)
{
  EcuM_Gen_DisableWakeupSources(wakeupSource);
}



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
**                        Function(s) invoked    : Gpt_CheckWakeup Pm_GoWakeup**
**                                                 EcuM_Gen_CheckWakeup       **
*******************************************************************************/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_CheckWakeup
  (EcuM_WakeupSourceType wakeupSource)
{
  #if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
  if (wakeupSource == ECUM_ALARM_WAKEUP_SOURCE_ID)
  {
    SchM_Enter_EcuM_ALARM_TIME_PROTECTION();
    
    Gpt_CheckWakeup(wakeupSource);
    
    #if (ECUM_PM_ENABLED == STD_ON)
    Pm_GoWakeup();
    #endif
    SchM_Exit_EcuM_ALARM_TIME_PROTECTION();
  }
  else
  #endif
  {
    /* Wakeup Sequence */
    EcuM_Gen_CheckWakeup(wakeupSource);
  }
}

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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_StartWakeupSources
  (EcuM_WakeupSourceType wakeupSource)
{
  /* Callout shall be filled by the system designer */
}

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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_StopWakeupSources
  (EcuM_WakeupSourceType wakeupSource)
{
  /* Callout shall be filled by the system designer */
}

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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_CheckValidation
  (EcuM_WakeupSourceType wakeupSource)
{
  /* Callout shall be filled by the system designer */
}

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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_GenerateRamHash(void)
{
  /* Callout shall be filled by the system designer */
}

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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_SleepActivity(void)
{
  /* Callout shall be filled by the system designer */
}

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
FUNC(uint8, ECUM_CALLOUT_CODE) EcuM_CheckRamHash(void)
{
  return (1);
}

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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_ErrorHook(Std_ReturnType reason)
{
  /* Callout shall be filled by the system designer */
  ECUM_UNUSED(reason);
}

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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_LoopDetection(void)
{
  #if HWRESOURCE_VENDOR(HWRESOURCE_FREESCALE)
  /* Turn to reset mode if current mode is safe mode */  
  /* polyspace<RTE: ABS_ADDR : Not a defect : No Action Planned > Macro that is defined by MCAL. */
  /* polyspace<MISRA-C:11.3:Not a defect:Justify with annotations> Macro that is defined by MCAL. */
  if ((REG_READ32(MC_ME_GS_R) & ME_GS_CURRENT_MODE) == ME_GS_CURRENT_MODE_SAFE)
  {
    Mcu_PerformReset();
  }
  #endif
}

/*******************************************************************************
** Function Name        : EcuM_SetMode                                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Callout used for Set Mcu Mode                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : McuMode                                             **
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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_SetMode
  (Mcu_ModeType McuMode)
{
  #if (ECUM_PM_ENABLED == STD_ON)                  
  Pm_MakeTransition(McuMode);
  #else
  Mcu_SetMode(McuMode);
  #endif
}

/*******************************************************************************
** Function Name        : EcuM_PreInit                                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Callout used for before EcuM Init                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : McuMode                                             **
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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_PreInit(void)
{
  #if HWRESOURCE_VENDOR(HWRESOURCE_FREESCALE)                  
  WdgStack_DisableIntWdg();
  #endif
  
  #if HWRESOURCE_VENDOR(HWRESOURCE_RENESAS)
  /*  To use SuspendAllInterrupts() and ResumeAllInterrupts() before StartOS */
  /* RH850 Renesas OS specific */
  _kernel_fv0_InitializeIntService();
  #endif
  
  #if HWRESOURCE_VENDOR(HWRESOURCE_CYPRESS)
  /*  To Clear External Interrupt Flag */
  /* Cypress specific */
  EIC00_ENICR = 0xFFFFFFFF;
  EIC00_EIRCR = 0xFFFFFFFF;
  #endif
  
  #if HWRESOURCE_FAMILY(HWRESOURCE_SPC58XC)
  /* Chorus specific */
  
  /*  To Prevent Mcu Init DET */
  REG_WRITE32(MC_CGM_AC0_SC_R, 0);
  REG_WRITE32(MC_CGM_AC1_SC_R, 0);
  REG_WRITE32(MC_CGM_AC3_SC_R, 0);
  REG_WRITE32(MC_CGM_AC4_SC_R, 0);
  REG_WRITE32(MC_CGM_AC6_SC_R, 0);
  REG_WRITE32(MC_CGM_AC8_SC_R, 0);
  REG_WRITE32(MC_CGM_AC9_SC_R, 0);
  REG_WRITE32(MC_CGM_AC11_SC_R, 0);
  REG_WRITE32(MC_CGM_AC12_SC_R, 0);
  
  REG_WRITE32(MC_ME_IS_R, 0x10u);
  
  /* Reset FCCU Status (#10953) */
  REG_WRITE32(FCCU_RFK_R, 0xAB3498FE);
  REG_WRITE32(FCCU_RF_S0_R, (1U << 18U));

  /* Clear ST_DONE Reset Flag (#10954) */
  REG_WRITE32( (MC_RGM_FES_R) , 0x4UL);
  
  #endif
}

/*******************************************************************************
** Function Name        : EcuM_PreSleep                                       **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Pre Callout for Go Halt Sequence                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
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
**                                                                            **
**                        Function(s) invoked    : EcuM_ClearWakeupEvent      **
**                                                 EcuM_H2LTransition_App     **
**                                                 EcuM_H2LTransition_Swp     **
*******************************************************************************/

FUNC(void, ECUM_CALLOUT_CODE) EcuM_PreSleep(void)
{
  /* Clear All Wakeup Sources */
  EcuM_ClearWakeupEvent(ECUM_WKSOURCE_ALL_SOURCES);

  #if (ECUM_LP_CALLOUT_ENABLED == STD_ON)
  /* Callout For Platform */
  EcuM_H2LTransition_Callout_Swp();

  /* Callout For User */
  EcuM_H2LTransition_Callout_App();
  #endif
}

/*******************************************************************************
** Function Name        : EcuM_PostSleep                                      **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Post Callout for Go Halt Sequence                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : GoHaltResult                                        **
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
**                                                                            **
**                        Function(s) invoked    : EcuM_L2HTransition_Swp     **
**                                                 EcuM_L2HTransition_App     **
*******************************************************************************/

FUNC(void, ECUM_CALLOUT_CODE) EcuM_PostSleep
  (Std_ReturnType GoHaltResult)
{
  #if (ECUM_LP_CALLOUT_ENABLED == STD_ON)
  /* Callout For Platform */
  EcuM_L2HTransition_Callout_Swp(GoHaltResult);

  /* Callout For User */
  EcuM_L2HTransition_Callout_App(GoHaltResult);
  #endif
}

#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
