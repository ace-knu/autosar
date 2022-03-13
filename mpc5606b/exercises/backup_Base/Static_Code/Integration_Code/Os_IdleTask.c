/*******************************************************************************
**                                                                            **
**  (C) 2016-2017 HYUNDAI AUTRON Co., Ltd.                                    **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Os_IdleTask.c                                                 **
**                                                                            **
**  TARGET    : MPC560xB                                                      **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Idle Task                                        **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 1.1.4     25-Apr-2017    MJ.Woo        Redmine #8314                       **
** 1.1.3     27-Mar-2017    JH.Lee        Redmine #7467                       **
** 1.1.1     30-Nov-2016    JH.Lee        Redmine #6687                       **
** 1.1.0     04-Nov-2016    JH.Lee        Redmine #6493                       **
** 1.0.0     03-Mar-2016    MJ.Woo        Initial version                     **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os.h"
#include "Os_Debug.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
TASK(OsTask_BSW_System_Idle)
{
  /* polyspace<RTE: NTL : Not a defect : No Action Planned > Idle task with the lowest priority */
  while (TRUE)
  {
    #ifdef PM_ENABLED
    #if (PM_ENABLED == STD_ON)
    Pm_ActivatePmTask();
    #endif
    #endif

    /* Enable Interrupt before executing a wait instruction.
     * To Prevent the result of falling into an infinite loop. */
    OS_ENABLEINTERRUPTS();

    #if (OS_DEBUG_CPULOAD == STD_ON)
    /* The Os_SetIdleForCPULoad() should be placed
     * at the bottom of the idle loop. */
    Os_SetIdleForCPULoad();
    #else
    __WAIT();
    #endif
  }
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

