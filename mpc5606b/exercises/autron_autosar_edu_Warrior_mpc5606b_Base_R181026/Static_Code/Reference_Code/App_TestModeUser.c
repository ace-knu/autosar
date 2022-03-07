/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "Rte_SWC_TestModeUser.h"
uint8 ModeUser_A_CallCounter = 0;
uint8 ModeUser_B_CallCounter = 0;

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define SWC_TestModeUser_START_SEC_CODE
#include "SWC_TestModeUser_MemMap.h"

FUNC(void, SWC_TestModeUser_CODE) TestModeUser_A(void)
{
  ModeUser_A_CallCounter++;
}

FUNC(void, SWC_TestModeUser_CODE) TestModeUser_B(void)
{
  ModeUser_B_CallCounter++;
}
#define SWC_TestModeUser_STOP_SEC_CODE
#include "SWC_TestModeUser_MemMap.h"
