/*******************************************************************************
**                            HYUNDAI MOTORS GROUP                            **
**                                                                            **
**                            All rights reserved                             **
**                                                                            **
**            You can NOT use this sample code for Product Release            **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : App_Mode.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Application Mode SWC                                  **
**                                                                            **
**  PURPOSE   : Sample SWC code for Application Mode                          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                              Revision History                              **
********************************************************************************
** Revision   Date          By            Description                         **
********************************************************************************
** 1.0.0      14-Sep-2015   Daejun Park   Initial version                     **
** 2.0.0      21-Oct-2015   Daejun Park   Update for ODIN 2016b               **
*******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "CanIf_Cbk.h"
#include "Rte_SWC_AppMode.h"

uint8 AppMode_GucTestCase = 0u;
uint8 AppMode_GucWakeupCount = 0u;
uint8 AppMode_GucBusoffCount = 0u;
Rte_ModeType_EcuMode AppMode_GddEcuMode = RTE_TRANSITION_EcuMode;

Rte_ModeType_MDG_WakeupEvent AppMode_GddWakeupEvent = RTE_MODE_MDG_WakeupEvent_INITIAL_MODE; //AppMode_WakeupEventValidated 함수 추가

Rte_ModeType_MDG_ComMMode AppMode_GddComMMode_Project = RTE_MODE_MDG_ComMMode_NO_COM;
//Rte_ModeType_MDG_CanSMBORState AppMode_GddBORState_Project = RTE_MODE_MDG_CanSMBORState_COMPLETE;

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

#define SWC_AppMode_START_SEC_CODE
#include "SWC_AppMode_MemMap.h"

/*******************************************************************************
** Function Name        : AppMode_InitCompleted                               **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          : Runnable invoked when BSW Init Completed            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
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
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/

FUNC(void, SWC_AppMode_CODE) AppMode_InitCompleted(void)
{
  Rte_ModeType_MDG_InitState LddPrevInitState, LddNextInitState;
  (void)Rte_Mode_modeNotificationPort_InitState_InitState(&LddPrevInitState, &LddNextInitState);

  /* Condition when BSW initialization completed */
  if (LddNextInitState == RTE_MODE_MDG_InitState_COMPLETE)
  {
      /* Notification when BSW Init Completed */
      Rte_Write_modeRequestPort_AppMode_AppMode(APP_MODE_ACTIVE);
  }
}

/*******************************************************************************
** Function Name        : AppMode_EcuModeSwitched                             **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          : Runnable invoked when EcuMode updated from BswM     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
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
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/

FUNC(void, SWC_AppMode_CODE) AppMode_EcuModeSwitched(void)
{
  Rte_ModeType_EcuMode LddPrevEcuMode, LddNextEcuMode;
  (void)Rte_Mode_modeNotificationPort_EcuMode_EcuMode(&LddPrevEcuMode, &LddNextEcuMode);
  
  if (LddNextEcuMode == RTE_MODE_EcuMode_ECUM_STATE_RUN)
  {
    /* Condition when ECU state changed from STARTUP to RUN */
    if (AppMode_GddWakeupEvent == RTE_MODE_MDG_WakeupEvent_INITIAL_MODE)
    {
      /* This code is executed only once shortly after Rte_Start */
    Rte_Write_modeRequestPort_ComMMode_Project_ComMMode_Project(COMM_MODE_FULL_COM);
    }
    /* Condition when ECU state changed from SLEEP to RUN */
    else
    {
      if (AppMode_GddWakeupEvent == RTE_MODE_MDG_WakeupEvent_CAN1RX)
      {
        Rte_Write_modeRequestPort_ComMMode_Project_ComMMode_Project(COMM_MODE_FULL_COM);
        //Rte_Write_modeRequestPort_ComMMode_Communication_Test_ComMMode_Communication_Test(COMM_MODE_FULL_COM);
      }
    }
  }
}

/*******************************************************************************
** Function Name        : AppMode_WakeupEventValidated                        **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          : Runnable invoked when wakeup event occurs           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
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
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
FUNC(void,AppMode_CODE) AppMode_WakeupEventValidated(void)
{
  Rte_ModeType_MDG_WakeupEvent LddPrevWakeupEvent;
  (void)Rte_Mode_modeNotificationPort_WakeupEvent_WakeupEvent(&LddPrevWakeupEvent, &AppMode_GddWakeupEvent);
  /* Conditions when wakeup occured from ECU SLEEP */
  if (AppMode_GddWakeupEvent == RTE_MODE_MDG_WakeupEvent_CAN1RX)
  {
    Rte_Write_modeRequestPort_AppMode_AppMode(APP_MODE_ACTIVE);
  }
  /* Conditions when remote wakeup occured from BUS SLEEP */
  else if (AppMode_GddWakeupEvent == RTE_MODE_MDG_WakeupEvent_CAN1RX_POLL)
  {
    /* Actions when CanCM Polling Wakeup occurs */
    /* IF full com requested here, App Mode Active should be requested */
  }
}
/*******************************************************************************
** Function Name        : AppMode_ComMModeSwitched_Project                    **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          : Runnable invoked when ComM Mode switched            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
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
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/

FUNC(void,AppMode_CODE) AppMode_ComMModeSwitched_Project(void)
{
  Rte_ModeType_MDG_ComMMode LddPrevBusState, LddNextBusState;
  Rte_Mode_modeNotificationPort_ComMMode_Project_ComMMode_Project(&LddPrevBusState, &LddNextBusState);

  /* Conditions when Com Mode No Com switched */
  if (LddNextBusState == RTE_MODE_MDG_ComMMode_NO_COM)
  {
  }
  /* Conditions when Com Mode Silent Com switched */
  else if (LddNextBusState == RTE_MODE_MDG_ComMMode_SILENT_COM)
  {
  }
  /* Conditions when Full Mode No Com switched */
  else if (LddNextBusState == RTE_MODE_MDG_ComMMode_FULL_COM)
  {
  }
}
/*******************************************************************************
** Function Name        : AppMode_CanSMBorStateSwitched                       **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          : Runnable invoked when CanSM Busoff Recovery State   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
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
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/

FUNC(void,AppMode_CODE) AppMode_CanSMBorStateSwitched_Project(void) //17.12.1 rtu코드 반영,  변수LddNextBorState추가
{
// Rte_ModeType_MDG_CanSMBORState LddPrevBorState, LddNextBorState;
// Rte_Mode_modeNotificationPort_CanSMBORState_Project_CanSMBORState_Project(&LddPrevBorState, &LddNextBorState);
  
  /* Conditions when bus-off recovery started */
//  if (LddNextBorState == RTE_MODE_MDG_CanSMBORState_START)
//  {
//    AppMode_GucBusoffCount++;
//  }
  /* Conditions when bus-off recovery completed */
//  else if (LddNextBorState == RTE_MODE_MDG_CanSMBORState_COMPLETE)
//  {
//  }
}
/*******************************************************************************
** Function Name        : AppMode_PduGroupSwitched_Project_Tx                 **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          : Runnable invoked when CanSM PduGroup Switched       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
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
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/

FUNC(void,AppMode_CODE) AppMode_PduGroupSwitched_Project_Tx (void)
{
  Rte_ModeType_MDG_PduGroup LddPrevPduState, LddNextPduState;
  Rte_Mode_modeNotificationPort_PduGroupTx_Project_PduGroupTx_Project(&LddPrevPduState, &LddNextPduState);

  /* Conditions when PduGroup started */
  if (LddNextPduState == RTE_MODE_MDG_PduGroup_STOP)
  {
  }
  /* Conditions when PduGroup completed */
  else if (LddNextPduState == RTE_MODE_MDG_PduGroup_START)
  {
  }
}

/*******************************************************************************
** Function Name        : AppMode_PduGroupSwitched_Project_Rx                 **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          : Runnable invoked when CanSM PduGroup Switched       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
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
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
FUNC(void,AppMode_CODE) AppMode_PduGroupSwitched_Project_Rx (void)
{
  Rte_ModeType_MDG_PduGroup LddPrevPduState, LddNextPduState;
  Rte_Mode_modeNotificationPort_PduGroupRx_Project_PduGroupRx_Project(&LddPrevPduState, &LddNextPduState);

  /* Conditions when PduGroup started */
  if (LddNextPduState == RTE_MODE_MDG_PduGroup_STOP)
  {
    /* Pdu Group Stop */
  }
  /* Conditions when PduGroup completed */
  else if (LddNextPduState == RTE_MODE_MDG_PduGroup_START)
  {
    /* Pdu Group Start */
  }
}

/*******************************************************************************
** Function Name        : AppMode_Test                                        **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          : Test application runnable                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non Reentrant                                       **
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
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
FUNC(void, SWC_AppMode_CODE) AppMode_Test(void)
{
    switch (AppMode_GucTestCase)
    {
    case 1: /* ECU RUN Test */
      Rte_Write_modeRequestPort_AppMode_AppMode(APP_MODE_ACTIVE);

      Rte_Write_modeRequestPort_ComMMode_Project_ComMMode_Project(COMM_MODE_FULL_COM);

      AppMode_GucTestCase = 0;
      break;

    case 2: /* ECU OFF Test */
      Rte_Write_modeRequestPort_ComMMode_Project_ComMMode_Project(COMM_MODE_NO_COM);

      Rte_Write_modeRequestPort_AppMode_AppMode(APP_MODE_INACTIVE_OFF);

      AppMode_GucTestCase = 0;
      break;

    case 3: /* ECU RESET Test */
      Rte_Write_modeRequestPort_ComMMode_Project_ComMMode_Project(COMM_MODE_NO_COM);

      Rte_Write_modeRequestPort_AppMode_AppMode(APP_MODE_INACTIVE_RESET);

      AppMode_GucTestCase = 0;
      break;

    case 4: /* ECU SLEEP Test */
      Rte_Write_modeRequestPort_ComMMode_Project_ComMMode_Project(COMM_MODE_NO_COM);

      Rte_Write_modeRequestPort_AppMode_AppMode(APP_MODE_INACTIVE_SLEEP);

      AppMode_GucTestCase = 0;
      break;

    case 5: /* FULL COM Test */
      Rte_Write_modeRequestPort_ComMMode_Project_ComMMode_Project(COMM_MODE_FULL_COM);

      AppMode_GucTestCase = 0;
      break;

    case 6: /* Test Mode Change to MODE_A */
      Rte_Write_modeRequestPort_TestMode_TestMode(MODE_A);

      AppMode_GucTestCase = 0;
      break;

    case 7: /* Test Mode Change to MODE_B */
      Rte_Write_modeRequestPort_TestMode_TestMode(MODE_B);

      AppMode_GucTestCase = 0;
      break;

    case 8: /* Can BusOff Test */
      CanIf_ControllerBusOff(0);

      AppMode_GucTestCase = 0;
      break;


    default:
      break;
    }
}
#define SWC_AppMode_STOP_SEC_CODE
#include "SWC_AppMode_MemMap.h"
