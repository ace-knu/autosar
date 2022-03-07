/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "Rte_SWC_TestModeManager.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define SWC_TestModeManager_START_SEC_CODE
#include "SWC_TestModeManager_MemMap.h"

FUNC(void, SWC_TestModeManager_CODE) TestModeManager(void)
{
//  Rte_ModeType_MDG_TestMode LddRequestMode;
//
//  Rte_Read_TestModeRequestInterface_TestMode(&LddRequestMode);
//
//  if(LddRequestMode == MODE_A)
//  {
//    Rte_Switch_modeSwitchPort_TestMode_TestMode(MODE_A);
//  }
//  else if(LddRequestMode == MODE_B)
//  {
//    Rte_Switch_modeSwitchPort_TestMode_TestMode(MODE_B);
//  }
}
#define SWC_TestModeManager_STOP_SEC_CODE
#include "SWC_TestModeManager_MemMap.h"

