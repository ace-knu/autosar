/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : CAN_ModeTransition_MPC560x.c                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN Module                                            **
**                                                                            **
**  PURPOSE   : Provision of HAL APIs for CAN                                 **
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
** 1.0.0     20-Apr-2016   Kyungtae Kim   Initial version                     **
*******************************************************************************/
#include "HwResource.h"
#if HWRESOURCE_VENDOR(HWRESOURCE_FREESCALE)
#include "CAN_ModeTransition_MPC560x.h"

volatile uint8 GucFlexCanMdisStatus = 0;

#define FLEXCAN_CH_MAX (6u)

#define CAN_START_SEC_CODE
#include "MemMap.h"
FUNC(Can_ReturnType, CAN_CODE) CanSetMDIS(void)
{
  Can_ReturnType LddReturn; 
  uint32 LulTimeoutCnt;
  uint8 LucChidx;
  uint8 LucChShiftTemp;

  GucFlexCanMdisStatus = 0u;
  LddReturn = CAN_OK;
  
  for(LucChidx=0u; LucChidx < FLEXCAN_CH_MAX; LucChidx++)
  {
    if(((uint32)FLEXCAN_MCR_READ(LucChidx) & FLEXCAN_MCR_MDIS) != FLEXCAN_MCR_MDIS)
    {
      FLEXCAN_SET_MCR_MDIS(LucChidx);
      LulTimeoutCnt = (uint32)CAN_TIMEOUT_DURATION;
      LucChShiftTemp = ((uint16)1 << LucChidx);
      GucFlexCanMdisStatus = (GucFlexCanMdisStatus | LucChShiftTemp);

      while ( (FLEXCAN_MCR_MDIS != ((uint32)FLEXCAN_MCR_READ(LucChidx) & FLEXCAN_MCR_MDIS)) &&
              (LulTimeoutCnt > (uint32)0x0U))
      {
          LulTimeoutCnt--;
      }
      if(LulTimeoutCnt == 0)
      {
        LddReturn = CAN_NOT_OK;
      }
    }
  }
  return LddReturn;
}

FUNC(Can_ReturnType, CAN_CODE) CanClearMDIS(void)
{
  Can_ReturnType LddReturn; 
  uint32 LulTimeoutCnt;
  uint8 LucChidx;
  uint8 LucChStatusTemp;
  
  LddReturn = CAN_OK;

  for(LucChidx=0u; LucChidx < FLEXCAN_CH_MAX; LucChidx++)
  {
    LucChStatusTemp = ((uint16)1u << LucChidx);
    if((GucFlexCanMdisStatus & LucChStatusTemp) == LucChStatusTemp)
    {
      FLEXCAN_CLEAR_MCR_MDIS(LucChidx);
      LulTimeoutCnt = (uint32)CAN_TIMEOUT_DURATION;

      while ( (FLEXCAN_MCR_MDIS == ((uint32)FLEXCAN_MCR_READ(LucChidx) & FLEXCAN_MCR_MDIS)) &&
              (LulTimeoutCnt > (uint32)0x0U) )
      {
          LulTimeoutCnt--;
      }
      if(LulTimeoutCnt == 0)
      {
        LddReturn = CAN_NOT_OK;
      }
    }
  }

  return LddReturn;

}
#define CAN_STOP_SEC_CODE
#include "MemMap.h"

#endif 
/* #if HWRESOURCE_VENDOR(HWRESOURCE_FREESCALE) */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
