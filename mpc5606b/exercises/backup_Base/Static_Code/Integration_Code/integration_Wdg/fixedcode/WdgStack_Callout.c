/*******************************************************************************
**                                                                            **
**  (C) 2016 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: WdgStack_Callout.c                                            **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR AUTRON WDG STACK CALLOUT                              **
**                                                                            **
**  PURPOSE   : Autron Watchdog stack Functionality                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By           Description                           **
********************************************************************************
** 1.0.4     12-Jul-2016   Kuksun       Update #5513                          **
** 1.0.0     29-Apr-2016   Sinil        Initial version                       **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "WdgStack_Callout.h"

#if ((WDGSTACK_ENABLE_INTERNAL_WDG == STD_ON) \
  || (WDGSTACK_ENABLE_EXTERNAL_WDG == STD_ON) \
  || (WDGSTACK_ENABLE == STD_ON))
#include "HwResource.h"
#endif

#if HWRESOURCE_VENDOR(HWRESOURCE_FREESCALE)
#include "Wdg.h"
#include "Reg_Macros.h"
#include "Reg_eSys_Swt.h"
#endif

#if (WDGSTACK_ENABLE_INTERNAL_WDG == STD_ON)
#if HWRESOURCE_VENDOR(HWRESOURCE_FREESCALE)
#include "Wdg_Swt_LLD.h"
#include "Gpt.h"
#elif HWRESOURCE_VENDOR(HWRESOURCE_INFINEON)
#include "Wdg_17_Scu.h"
#elif HWRESOURCE_VENDOR(HWRESOURCE_RENESAS)
#include "Wdg_59_DriverA.h"
#include "Wdg_59_DriverA_Private.h"
#if HWRESOURCE_MCU(HWRESOURCE_RH850F1K)
#include "Wdg_59_DriverA_Irq.h"
#include "Wdg_59_DriverA_Cfg.h"
#endif
#elif HWRESOURCE_VENDOR(HWRESOURCE_CYPRESS)
#include "Wdg_66_IA_Controller.h"
#endif
#endif /* (WDGSTACK_ENABLE_INTERNAL_WDG == STD_ON) */

#if (WDGSTACK_ENABLE_EXTERNAL_WDG == STD_ON)
#include "Wdg_76_Acw.h"
#include "Wdg_76_Acw_Config.h"
#endif /* (WDGSTACK_ENABLE_EXTERNAL_WDG == STD_ON) */

#if (WDGSTACK_ENABLE == STD_ON)
#include "WdgM.h"
#endif /* (WDGSTACK_ENABLE == STD_ON) */

/*******************************************************************************
**                       Function Definitions                                 **
*******************************************************************************/
/*******************************************************************************
** Function Name      : WdgStack_DisableIntWdg                                **
**                                                                            **
** Service ID         : NA                                                    **
**                                                                            **
** Description        : Disable internal watchdog while booting               **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : None                                                  **
**                                                                            **
** InOut parameter    : None                                                  **
**                                                                            **
** Output Parameters  : None                                                  **
**                                                                            **
** Return parameter   : None                                                  **
**                                                                            **
** Preconditions      : None                                                  **
**                                                                            **
** Remarks            : Global Variable(s) : None                             **
**                                                                            **
**                      Function(s) invoked :                                 **
*******************************************************************************/
void WdgStack_DisableIntWdg(void)
{
  /* Bolero is need to clear soft lock of Internal Watchdog on initial sequence 
  Because internal Watchdog automatically set to soft lock as 100ms time out 
  period after reset */
  #if HWRESOURCE_VENDOR(HWRESOURCE_FREESCALE)
  {
    /*
      polyspace:begin<MISRA-C:11.3:Not a defect:Justify with annotations> 
      It is nessacert for addressing memory mapped register
    */
    REG_WRITE32(SWT_SR(0), SWT_UNLOCK_SEQ1);
    REG_WRITE32(SWT_SR(0), SWT_UNLOCK_SEQ2);

    /* Prevent to hard lock by clear bit for Disable watchdog */
    REG_BIT_CLEAR32(SWT_CR(0), SWT_WDG_ENABLED);

    /*
      polyspace:end<MISRA-C:11.3:Not a defect:Justify with annotations> 
      It is nessacert for addressing memory mapped register
    */
  }
  #elif HWRESOURCE_VENDOR(HWRESOURCE_INFINEON)
  {
  }
  #elif HWRESOURCE_VENDOR(HWRESOURCE_RENESAS)
  {
  }
  #endif
}

#if (WDGSTACK_INIT_USING_ECUM == STD_OFF)
/*******************************************************************************
** Function Name      : WdgStack_Init                                         **
**                                                                            **
** Service ID         : NA                                                    **
**                                                                            **
** Description        : Initialize watchdog stack modules                     **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : None                                                  **
**                                                                            **
** InOut parameter    : None                                                  **
**                                                                            **
** Output Parameters  : None                                                  **
**                                                                            **
** Return parameter   : None                                                  **
**                                                                            **
** Preconditions      : None                                                  **
**                                                                            **
** Remarks            : Global Variable(s) : None                             **
**                                                                            **
**                      Function(s) invoked :                                 **
*******************************************************************************/
void WdgStack_Init(void)
{
  #if (WDGSTACK_ENABLE_INTERNAL_WDG == STD_ON)
  #if HWRESOURCE_VENDOR(HWRESOURCE_FREESCALE)
  {
    Wdg_Init(NULL_PTR);
  }
  #elif HWRESOURCE_VENDOR(HWRESOURCE_INFINEON)
  {
    Wdg_17_Scu_Init(&Wdg_ConfigRoot[0]);
  }
  #elif HWRESOURCE_VENDOR(HWRESOURCE_RENESAS)
  {
    Wdg_59_DriverA_Init(&Wdg_59_DriverA_GstConfiguration); 
  }
  #endif
  #endif /* (WDGSTACK_ENABLE_INTERNAL_WDG == STD_ON) */

  #if (WDGSTACK_ENABLE_EXTERNAL_WDG == STD_ON)
  {
    Wdg_76_Acw_Init(NULL_PTR);
  }
  #endif /* (WDGSTACK_ENABLE_EXTERNAL_WDG == STD_ON) */

  #if (WDGSTACK_ENABLE == STD_ON)
  {
    WdgM_Init(NULL_PTR);
  }
  #endif /* (WDGSTACK_ENABLE == STD_ON) */
}

#endif/* (WDGSTACK_INIT_USING_ECUM == STD_OFF) */
/*******************************************************************************
** Function Name      : WdgStack_TransitHighToLow                             **
**                                                                            **
** Service ID         : NA                                                    **
**                                                                            **
** Description        : Control watchdog stack modules while high to low      **
**                      transition occurs                                     **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : None                                                  **
**                                                                            **
** InOut parameter    : None                                                  **
**                                                                            **
** Output Parameters  : None                                                  **
**                                                                            **
** Return parameter   : None                                                  **
**                                                                            **
** Preconditions      : None                                                  **
**                                                                            **
** Remarks            : Global Variable(s) : None                             **
**                                                                            **
**                      Function(s) invoked :                                 **
*******************************************************************************/
void WdgStack_TransitHighToLow(void)
{
  /* Internal Watchdog */
  #if (WDGSTACK_ENABLE_INTERNAL_WDG == STD_ON)
  #if HWRESOURCE_VENDOR(HWRESOURCE_FREESCALE)
  {
    uint32 LddSwtCR = 0x00000000UL;
    /*
      polyspace:start<MISRA-C:11.3:Not a defect:Justify with annotations> 
      It is nessacert for addressing memory mapped register
    */
    LddSwtCR = REG_READ32(SWT_CR(0));

    /* Disable watchdog */
    REG_BIT_CLEAR32(SWT_CR(0), SWT_WDG_ENABLED);

    /* Set Timer-out register */
    REG_WRITE32(SWT_TO(0), 0x00003200UL);

    /* Set window register */
    REG_WRITE32(SWT_WN(0), 0x00003200UL);

    /* Set the Control Register */
    REG_WRITE32(SWT_CR(0), LddSwtCR);

    /* Stop timer for watchdog trigger */
    Gpt_StopTimer(Wdg_ConfigPtr[0]->Gpt_Channel);
    /*
      polyspace:end<MISRA-C:11.3:Not a defect:Justify with annotations> 
      It is nessacert for addressing memory mapped register
    */
  }
  #elif HWRESOURCE_VENDOR(HWRESOURCE_INFINEON)
  {
    /* Not supported */
  }
  #elif HWRESOURCE_VENDOR(HWRESOURCE_RENESAS)
  {
    /* It's not possible to change the configuration of the internal wdg after
      it has started */
  }
  #endif
  #endif /* (WDGSTACK_ENABLE_INTERNAL_WDG == STD_ON) */

  /* External Watchdog */
  #if (WDGSTACK_ENABLE_EXTERNAL_WDG == STD_ON)
  /* Stop timer for watchdog trigger */
  Gpt_StopTimer(Wdg_76_Acw_GptChannel);
  #endif /* (WDGSTACK_ENABLE_EXTERNAL_WDG == STD_ON) */

  WdgStack_TriggerWatchdog();
}

/*******************************************************************************
** Function Name      : WdgStack_TransitLowToHigh                             **
**                                                                            **
** Service ID         : NA                                                    **
**                                                                            **
** Description        : Control watchdog stack modules while low to high      **
**                      transition occurs                                     **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : None                                                  **
**                                                                            **
** InOut parameter    : None                                                  **
**                                                                            **
** Output Parameters  : None                                                  **
**                                                                            **
** Return parameter   : None                                                  **
**                                                                            **
** Preconditions      : None                                                  **
**                                                                            **
** Remarks            : Global Variable(s) : None                             **
**                                                                            **
**                      Function(s) invoked :                                 **
*******************************************************************************/
void WdgStack_TransitLowToHigh(void)
{
  WdgStack_TriggerWatchdog();

  #if (WDGSTACK_ENABLE == STD_ON)
  #if HWRESOURCE_VENDOR(HWRESOURCE_FREESCALE)
  {
    (void) WdgM_PmModeChange(WDGM_PM_MODE_HP_REQ);
  }
  #elif HWRESOURCE_VENDOR(HWRESOURCE_INFINEON)
  {
    /* Not supported */
  }
  #elif HWRESOURCE_VENDOR(HWRESOURCE_RENESAS)
  {
    (void) WdgM_PmModeChange(WDGM_PM_MODE_HP_REQ);
  }
  #endif
  #endif /* (WDGSTACK_ENABLE == STD_ON) */
}

/*******************************************************************************
** Function Name      : WdgStack_TriggerWatchdog                              **
**                                                                            **
** Service ID         : NA                                                    **
**                                                                            **
** Description        : Trigger watchdog stack modules                        **
**                                                                            **
** Sync/Async         : Synchronous                                           **
**                                                                            **
** Re-entrancy        : Non Reentrant                                         **
**                                                                            **
** Input Parameters   : None                                                  **
**                                                                            **
** InOut parameter    : None                                                  **
**                                                                            **
** Output Parameters  : None                                                  **
**                                                                            **
** Return parameter   : None                                                  **
**                                                                            **
** Preconditions      : None                                                  **
**                                                                            **
** Remarks            : Global Variable(s) : None                             **
**                                                                            **
**                      Function(s) invoked :                                 **
*******************************************************************************/
void WdgStack_TriggerWatchdog(void)
{
  /* Internal Watchdog */
  #if (WDGSTACK_ENABLE_INTERNAL_WDG == STD_ON)
  #if HWRESOURCE_VENDOR(HWRESOURCE_FREESCALE)
  {
    Wdg_SWT_Trigger((Wdg_IPW_InstanceType) 0x00);
  }
  #elif HWRESOURCE_VENDOR(HWRESOURCE_INFINEON)
  {
    /* Not supported */
  }
  #elif HWRESOURCE_VENDOR(HWRESOURCE_RENESAS)
  {
    /* The window period of the internal wdg should be 100% */
    
    #if HWRESOURCE_MCU(HWRESOURCE_RH850F1K)
    Wdg_59_DriverA_TriggerFunc(WDG_59_DRIVERA_TRIGGER_FUNCTION_ISR_SID);   
   
    #elif HWRESOURCE_MCU(HWRESOURCE_RH850F1L)
    Wdg_59_DriverA_TriggerFunc(WDG_59_DRIVERA_INCLUDE_CRITICAL_SECTION);
    
    #else
   
    #error "Not supported MCU Package, Contact to the Module Manager"
    
    #endif
  }
  #elif HWRESOURCE_VENDOR(HWRESOURCE_CYPRESS)
  {
    Wdg_66_IA_Internal_ActivateTrigger();
  }
  
  #endif
  #endif /* (WDGSTACK_ENABLE_INTERNAL_WDG == STD_ON) */

  /* External Watchdog */
  #if (WDGSTACK_ENABLE_EXTERNAL_WDG == STD_ON)
  Wdg_76_Acw_Trigger();
  #endif /* (WDGSTACK_ENABLE_EXTERNAL_WDG == STD_ON) */
}

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
