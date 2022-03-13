/*******************************************************************************
**                                                                            **
**  (C) 2016 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : EcuM_Boot.c                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Boot Code                                             **
**                                                                            **
**  PURPOSE   :  Autron Platform Boot Functionality                           **
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
** 2.0.5      27-Sep-2017   Sanghoon Bae  #10091 #10092                       **
** 2.0.4      22-Aug-2017   Sanghoon Bae  #9619                               **
** 2.0.2      23-Mar-2017   Sanghoon Bae  #7559                               **
** 2.0.0      22-Jul-2016   Sanghoon Bae  Initial version                     **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "EcuM.h"
#include "Os.h"

#if (ECUM_LP_CALLOUT_ENABLED == STD_ON)
#include "LowPower_Callout.h"
#endif

int main(void);

/*******************************************************************************
**                       Function Definitions                                 **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name      : main                                                  **
**                                                                            **
** Service ID         : NA                                                    **
**                                                                            **
** Description        : Booting main function                                 **
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
**                      Function(s) invoked :                                 **
**                      EcuM_PreInit                                          **
**                      EcuM_Init                                             **
**                      EcuM_BootCallout                                      **
*******************************************************************************/
int main(void)
{
  EcuM_PreInit();

  #if (ECUM_LP_CALLOUT_ENABLED == STD_ON)
  EcuM_Boot_Callout();
  #endif

  /* polyspace<RTE: NTC : Not a defect : No Action Planned > Due to calling StartOs by EcuM_Init */
  EcuM_Init();
  
  return 0;
}

/*******************************************************************************
* TASK BODIES
*******************************************************************************/
#if (ECUM_MULTI_CORE_SUPPORT == STD_ON)
TASK(OsTask_BSW_Init_Main)
{
  EcuM_StartupTwo();

  (void)TerminateTask();
}
  
#if (ECUM_NO_OF_CORES > 1)
TASK(OsTask_BSW_Init_Sub1)
{
  EcuM_StartupTwo();

  (void)TerminateTask();
}
#endif

#if (ECUM_NO_OF_CORES > 2)
TASK(OsTask_BSW_Init_Sub2)
{
  EcuM_StartupTwo();

  (void)TerminateTask();
}
#endif

#else
TASK(OsTask_BSW_Init)
{
  EcuM_StartupTwo();

  (void)TerminateTask();
}  
#endif


#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"
