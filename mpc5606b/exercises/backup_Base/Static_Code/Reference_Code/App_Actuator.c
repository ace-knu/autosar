/*******************************************************************************
**  (C) 2014 Hyundai AUTRON                                                   **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: App_Actuator.c                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR FiM                                                   **
**                                                                            **
**  PURPOSE   : Sample code for testing FiM module                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
 **                      Include Section                                      **
 ******************************************************************************/

#include "Rte_SWC_Actuator.h"

/*******************************************************************************
**                       Global Data                                          **
*******************************************************************************/
#define SWC_Actuator_START_SEC_VAR_CLEARED_8
#include "SWC_Actuator_MemMap.h"

uint8 SwcFiM_TestPhase = 0;
uint8 SwcFiM_TestPhaseEnable = 0;

#define SWC_Actuator_STOP_SEC_VAR_CLEARED_8
#include "SWC_Actuator_MemMap.h"

#define SWC_Actuator_START_SEC_VAR_CLEARED_BOOLEAN
#include "SWC_Actuator_MemMap.h"

boolean permissionResult = FALSE;

#define SWC_Actuator_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "SWC_Actuator_MemMap.h"

#define SWC_Actuator_START_SEC_CODE
#include "SWC_Actuator_MemMap.h"
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Run_Actuator                                        **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Sample runnable                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        :                                                     **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/

FUNC(void, SWC_Actuator_CODE) Run_Actuator(void)
{
  if (1 == SwcFiM_TestPhaseEnable)
  {
    switch(SwcFiM_TestPhase)
    {
      case 1:
      {
        boolean permission = FALSE;
        /* preconditions
         * 1. FIM is integrated
         * 2. FIM has inbibition mask (TESTED AND FAILED) with DEM_E_TEST_EVENT1 */
        Rte_Call_SWC_Actuator_R_Func_FiMFID_1_GetFunctionPermission(&permission);

        if (TRUE == permission)
        {
          permissionResult = TRUE;
        }
        else
        {
          permissionResult = FALSE;

        }
      }
      break;

      default:
      break;
    }

    SwcFiM_TestPhase = 0U;
  }
}

/*******************************************************************************
** Function Name        : App_Act_GetFunctionPermission                       **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : request the permission state of FID to the SWC.     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : FiM_FunctionIdType FID                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : boolean *Permission                                 **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        :                                                     **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(Std_ReturnType, SWC_Actuator_CODE) App_Act_GetFunctionPermission(
    IN uint8 FID, OUT P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA)Permission)
{
  Std_ReturnType LddRetVal = RTE_E_OK;
  if(FID == 0)
  {
    LddRetVal = Rte_Call_SWC_Actuator_R_Func_FiMFID_0_GetFunctionPermission(Permission);
  }
  else if(FID == 1)
  {
    LddRetVal = Rte_Call_SWC_Actuator_R_Func_FiMFID_1_GetFunctionPermission(Permission);
  }
  else
  {
    LddRetVal = RTE_E_INVALID;
  }

  return LddRetVal;
}


#define SWC_Actuator_STOP_SEC_CODE
#include "SWC_Actuator_MemMap.h"

