/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Mem_Integration_User.c                                        **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR MemStack Integration Module                           **
**                                                                            **
**  PURPOSE   : Provision of Version information                              **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "HwResource.h"
#include "Mem_Integration.h"

#if (MEM_FEE_USED == STD_ON)
#include "Fee.h"
#endif

#define NVM_START_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Function Name        : Mem_ExceptionHandlerOnFeeInitFail                   **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : This function handles exception when Fee module     **
**                        faileds to initialize                               **
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
** Remarks              :                                                     **
*******************************************************************************/
#if (MEM_FEE_USED == STD_ON)
FUNC(uint8, NVM_CODE) Mem_ExceptionHandlerOnFeeInitFail(void)
{
  uint8 retVal; 
  
  #if (HWRESOURCE_VENDOR(HWRESOURCE_CYPRESS))  
  static uint8 retryCount = 1;
  
  if (retryCount > 0U)
  {
    retVal = retryCount;  
  
    /* In case of Cypress, there is no workaround unless fee fails to erase all */
    /* Fee_Clear(); */
    retryCount--;
  }
  else
  #endif   
  {
    retVal = 0U; /* do not retry Fee_Init */
  }

  return retVal;
}
#endif

#define NVM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                         End of File                                        **
*******************************************************************************/

