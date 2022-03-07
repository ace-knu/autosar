#include "EcuM.h"
#include "Os.h"
#include "Os_Debug.h"
#include "Reg_eSys_Swt.h"
//#include "Pm_Cfg.h"
//#include "SchM_Pm.h"


void pre_init(void);
void main(void);

void main(void)
{
  pre_init();

  /* polyspace<RTE: NTC : Not a defect : No Action Planned > Due to calling StartOs by EcuM_Init */
  EcuM_Init();
}

TASK(OsTask_BSW_Init)
{
  EcuM_StartupTwo();

  (void)TerminateTask();
}

TASK(OsTask_BSW_System_Idle)
{
  /* polyspace<RTE: NTL : Not a defect : No Action Planned > Idle task with the lowest priority */
  while(TRUE)
  {
    #if (PM_ENABLED == STD_ON)
    Pm_ActivatePmTask();
    #endif

    #if (OS_DEBUG_CPULOAD == STD_ON)
    /* The Os_SetIdleForCPULoad() should be placed
     * at the bottom of the idle loop. */
    Os_SetIdleForCPULoad();
    #else
    Os_Halt();
    #endif
  }
}

void pre_init(void)
{
  /*
  * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed
  * between a pointer to a function and any type other than an integral type.
  */
  /* polyspace<RTE: ABS_ADDR : Not a defect : No Action Planned > Macro that is defined by MCAL. */
  /* polyspace<MISRA-C:11.3:Not a defect:Justify with annotations> Macro that is defined by MCAL. */
  REG_WRITE32(SWT_SR, SWT_UNLOCK_SEQ1);
  /*
  * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed
  * between a pointer to a function and any type other than an integral type.
  */
  /* polyspace<RTE: ABS_ADDR : Not a defect : No Action Planned > Macro that is defined by MCAL. */
  /* polyspace<MISRA-C:11.3:Not a defect:Justify with annotations> Macro that is defined by MCAL. */
  REG_WRITE32(SWT_SR, SWT_UNLOCK_SEQ2);

  /* Disable watchdog */
  /*
  * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed
  * between a pointer to a function and any type other than an integral type.
  */
  /* polyspace<RTE: ABS_ADDR : Not a defect : No Action Planned > Macro that is defined by MCAL. */
  /* polyspace<MISRA-C:11.3:Not a defect:Justify with annotations> Macro that is defined by MCAL. */
  REG_BIT_CLEAR32(SWT_CR, SWT_WDG_ENABLED);
}
