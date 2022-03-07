/*******************************************************************************
**                            HYUNDAI MOTORS GROUP                            **
**                                                                            **
**                            All rights reserved                             **
**                                                                            **
**            You can NOT use this sample code for Product Release            **
*******************************************************************************/
/*******************************************************************************
**  (C) 2014 Hyundai AUTRON                                                   **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: App_WdgM.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR WdgM                                                  **
**                                                                            **
**  PURPOSE   : Sample code for testing WdgM module                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 1.0.3     26-Feb-2015   Sinil          1. Add a macro for integration test **
** 1.0.2     13-Jan-2015   Sinil          1. Add a flag for testing wdg       **
**                                        expiration                          **
**                                        2. Change naming                    **
** 1.0.1     09-Dec-2014   Sinil          10ms alive supervision only         **
** 1.0.0     15-Oct-2014   Sinil          Initial version                     **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Rte_Swc_WdgMTest.h"

/*******************************************************************************
**                      Function Declarations                                 **
*******************************************************************************/
#define SWC_WdgMTest_START_SEC_CODE
#include "SWC_WdgMTest_MemMap.h"
void RE_Wdg_Cbk(void);
#define SWC_WdgMTest_STOP_SEC_CODE
#include "SWC_WdgMTest_MemMap.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define WDGMTEST_ENABLE_INTEGRATION_TEST              STD_ON

/*******************************************************************************
**                       Global Data                                          **
*******************************************************************************/
WdgM_GlobalStatusType WdgMTest_GddGlobalStatus;
WdgM_SupervisedEntityIdType WdgMTest_GddExpiredSEID;
boolean WdgMTest_GblStart = FALSE;
#if (WDGMTEST_ENABLE_INTEGRATION_TEST == STD_ON)
boolean WdgMTest_GblExpireWdg = FALSE;
#endif

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define SWC_WdgMTest_START_SEC_CODE
#include "SWC_WdgMTest_MemMap.h"
void RE_WdgMTest(void)
{
  if (WdgMTest_GblStart == FALSE)
  {
    (void)Rte_Call_WdgM_API_R_SetMode(WDGM_WDGMMODE1, WDGM_SE_INIT);
    WdgMTest_GblStart = TRUE;
  }

  #if (WDGMTEST_ENABLE_INTEGRATION_TEST == STD_ON)
  if (WdgMTest_GblExpireWdg == FALSE)
  {
  #endif
    /* WdgMAliveSupervision0 */
    (void)Rte_Call_SE_WdgMTest_CheckpointReached(WDGM_SE_WDGMTEST_CP_WDGMTEST_AS0);
  #if (WDGMTEST_ENABLE_INTEGRATION_TEST == STD_ON)
  }
  #endif
}
#define SWC_WdgMTest_STOP_SEC_CODE
#include "SWC_WdgMTest_MemMap.h"

#define SWC_WdgMTest_START_SEC_CODE
#include "SWC_WdgMTest_MemMap.h"
void RE_WdgMTestGlobalMode(void)
{
  if (Rte_Call_WdgM_API_R_GetGlobalStatus(&WdgMTest_GddGlobalStatus) == E_OK)
  {
    switch (WdgMTest_GddGlobalStatus)
    {
    case WDGM_GLOBAL_STATUS_OK:
      break;
    case WDGM_GLOBAL_STATUS_FAILED:
      break;
    case WDGM_GLOBAL_STATUS_EXPIRED:
      (void)Rte_Call_WdgM_API_R_GetFirstExpiredSEID(&WdgMTest_GddExpiredSEID);
      break;
    case WDGM_GLOBAL_STATUS_STOPPED:
      break;
    default:
      break;
    }
  }
}
#define SWC_WdgMTest_STOP_SEC_CODE
#include "SWC_WdgMTest_MemMap.h"

#define SWC_WdgMTest_START_SEC_CODE
#include "SWC_WdgMTest_MemMap.h"
void RE_Wdg_Cbk(void)
{
}
#define SWC_WdgMTest_STOP_SEC_CODE
#include "SWC_WdgMTest_MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
