/*******************************************************************************
**  (C) 2014 Hyundai AUTRON                                                   **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: App_DiagnosticMonitor.c                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Dem                                                   **
**                                                                            **
**  PURPOSE   : Sample code for testing Dem module                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
 **                      Include Section                                      **
 ******************************************************************************/
#include "Rte_SWC_DiagnosticMonitor.h"
#include "App_DiagnosticMonitor.h"

/*******************************************************************************
**                       Global Data                                          **
*******************************************************************************/

#define SWC_DiagnosticMonitor_START_SEC_VAR_CLEARED_8
#include "SWC_DiagnosticMonitor_MemMap.h"

uint8 SwcDem_TestPhaseEnable = 0;
uint8 SwcDem_TestPhase = 0;
uint8 SwcDem_TestFailedCtr = 0;

uint8 SwcDem_InitMonitorForEventInvoked = 0U;
uint8 SwcDem_EventStatusChangedInvoked = 0U;

#define SWC_DiagnosticMonitor_STOP_SEC_VAR_CLEARED_8
#include "SWC_DiagnosticMonitor_MemMap.h"


#define SWC_DiagnosticMonitor_START_SEC_CODE
#include "SWC_DiagnosticMonitor_MemMap.h"


/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : InitMonitorForEvent_DEM_E_TEST                      **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : The Dem module provides the interface               **
**                        InitMonitorForEvent* to trigger the initalization   **
**                        of a diagnostic monitor                             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : InitMonitorReason                                   **
**                        - DEM_INIT_MONITOR_CLEAR: Event was cleared         **
**                          and all internal values and states are reset      **
**                                                                            **
**                        - DEM_INIT_MONITOR_RESTART: Operation cycle of      **
**                          the event was (re-)started.                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : RTE_E_OK                                            **
**                                                                            **
** Preconditions        :                                                     **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(Std_ReturnType, SWC_DiagnosticMonitor_CODE) InitMonitorForEvent_DEM_E_TEST(
    IN VAR(Dem_InitMonitorReasonType, AUTOMATIC) InitMonitorReason)
{
  switch(InitMonitorReason)
  {
  case DEM_INIT_MONITOR_CLEAR:
    /* TODO */
    break;
  case DEM_INIT_MONITOR_RESTART:
    /* TODO */
    break;
  default:
    break;
  }

  SwcDem_InitMonitorForEventInvoked = 1;

  return RTE_E_OK;
}


/*******************************************************************************
** Function Name        : CBStatusEvt_DEM_E_TEST_EVENT1                       **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Triggers on changes of the event status byte        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : EventStatusOld                                      **
**                        - UDS DTC status byte of event before change        **
**                        EventStatusNew                                      **
**                       - UDS DTC status byte of event after change          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : RTE_E_OK                                            **
**                                                                            **
** Preconditions        :                                                     **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(Std_ReturnType, SWC_DiagnosticMonitor_CODE)  CBStatusEvt_DEM_E_TEST_EVENT1(
    IN VAR(Dem_EventStatusExtendedType, AUTOMATIC) EventStatusOld,
    IN VAR(Dem_EventStatusExtendedType, AUTOMATIC) EventStatusNew)
{
  SwcDem_EventStatusChangedInvoked = 1;
  return RTE_E_OK;
}


/*******************************************************************************
** Function Name        : CBStatusEvt_E_MODE_CHANGE_PROJECT                   **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Triggers on changes of the event status byte        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : EventStatusOld                                      **
**                        - UDS DTC status byte of event before change        **
**                        EventStatusNew                                      **
**                       - UDS DTC status byte of event after change          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : RTE_E_OK                                            **
**                                                                            **
** Preconditions        :                                                     **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(Std_ReturnType, SWC_DiagnosticMonitor_CODE)  CBStatusEvt_E_MODE_CHANGE_PROJECT(
    IN VAR(Dem_EventStatusExtendedType, AUTOMATIC) EventStatusOld,
    IN VAR(Dem_EventStatusExtendedType, AUTOMATIC) EventStatusNew)
{
  return RTE_E_OK;
}



/*******************************************************************************
** Function Name        : CBReadData_DE_0001                                  **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Requests the current value of the data element      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Data -containing the value of the data element      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     :                                                     **
**  - RTE_E_OK : Operation was successful                                     **
 *  - RTE_E_CSDataServices_DE_0001_E_NOT_OK : Operation failed                **
**                                                                            **
** Preconditions        :                                                     **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(Std_ReturnType, SWC_DiagnosticMonitor_CODE)  CBReadData_DE_0001(
    OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
  Data[0] = 0xA5;
  Data[1] = 0xB5;
  Data[2] = 0xC5;

  return RTE_E_OK;
}

/*******************************************************************************
** Function Name        : CBReadData_DE_0002                                  **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Requests the current value of the data element      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : Data -containing the value of the data element      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     :                                                     **
**  - RTE_E_OK : Operation was successful                                     **
 *  - RTE_E_CSDataServices_DE_0002_E_NOT_OK : Operation failed                **
**                                                                            **
** Preconditions        :                                                     **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
FUNC(Std_ReturnType, SWC_DiagnosticMonitor_CODE) CBReadData_DE_0002(
    OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
  Data[0] = 0x01;
  Data[1] = 0x02;
  Data[2] = 0x03;

  return RTE_E_OK;
}

/*******************************************************************************
** Function Name        : DiagnosticMonitor                                   **
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

FUNC(void, SWC_DiagnosticMonitor_CODE) DiagnosticMonitor(void)
{
  VAR(Std_ReturnType, RTE_DATA) LddRetVal = RTE_E_OK;

  switch(SwcDem_TestPhase)
  {
    /******************************************************************************************/
    case 1:
      LddRetVal = Rte_Call_OpCycle_POWER_CYCLE_SetOperationCycleState(DEM_CYCLE_STATE_START);
      if (RTE_E_OK != LddRetVal)
      {
        /* do something */
      }
    break;

    case 2:
      LddRetVal = Rte_Call_OpCycle_POWER_CYCLE_SetOperationCycleState(DEM_CYCLE_STATE_END);
      if (RTE_E_OK != LddRetVal)
      {
        /* do something */
      }
    break;

    /******************************************************************************************/
    case 3:
      LddRetVal = Rte_Call_EnableCond_EnableCondtion_0_SetEnableCondition(TRUE);
      if (RTE_E_OK != LddRetVal)
      {
        /* do something */
      }
    break;

    case 4:
      LddRetVal = Rte_Call_EnableCond_EnableCondtion_0_SetEnableCondition(FALSE);
      if (RTE_E_OK != LddRetVal)
      {
        /* do something */
      }
    break;

    /******************************************************************************************/
    case 5:
      LddRetVal = Rte_Call_Event_DEM_E_TEST_EVENT1_SetEventStatus(DEM_EVENT_STATUS_FAILED);
      if (RTE_E_OK != LddRetVal)
      {
        /* do something */
      }
    break;

    case 6:
      LddRetVal = Rte_Call_Event_DEM_E_TEST_EVENT2_SetEventStatus(DEM_EVENT_STATUS_FAILED);
      if (RTE_E_OK != LddRetVal)
      {
        /* do something */
      }
     break;

    case 7:
      LddRetVal = Rte_Call_Event_DEM_E_TEST_EVENT1_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
      if (RTE_E_OK != LddRetVal)
      {
        /* do something */
      }
    break;

    case 8:
      LddRetVal = Rte_Call_Event_DEM_E_TEST_EVENT2_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
      if (RTE_E_OK != LddRetVal)
      {
        /* do something */
      }
     break;

    /******************************************************************************************/
    case 9:
      LddRetVal = Rte_Call_Event_DEM_E_TEST_EVENT1_SetEventStatus(DEM_EVENT_STATUS_PASSED);
      if (RTE_E_OK != LddRetVal)
      {
        /* do something */
      }
    break;

    case 10:
      LddRetVal = Rte_Call_Event_DEM_E_TEST_EVENT2_SetEventStatus(DEM_EVENT_STATUS_PASSED);
      if (RTE_E_OK != LddRetVal)
      {
        /* do something */
      }
     break;

    case 11:
      LddRetVal = Rte_Call_Event_DEM_E_TEST_EVENT1_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
      if (RTE_E_OK != LddRetVal)
      {
        /* do something */
      }
    break;

    case 12:
      LddRetVal = Rte_Call_Event_DEM_E_TEST_EVENT2_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
      if (RTE_E_OK != LddRetVal)
      {
        /* do something */
      }
     break;

    /******************************************************************************************/
    case 13:
    {
      /**
       * Dem_IndicatorStatusType
       *
       * DEM_INDICATOR_OFF : Indicator off mode
       * DEM_INDICATOR_CONTINUOUS: Indicator continuously on mode
       * DEM_INDICATOR_BLINKING: Indicator blinking mode
       * DEM_INDICATOR_BLINK_CONT: Indicator blinking or continuously on mode
       */
      VAR(Dem_IndicatorStatusType, RTE_DATA) IndicatorStatus;

      /* Refer to the dem configuration
       * (1) DemGeneral/Indicator
       * (2) DemConfigSet/DemEventParamenter(DEM_E_TEST_EVENT1,DEM_E_TEST_EVENT2)
       *     /DemEventClass/DemIndicatorAttribute/DemIndicatorRef
       */
      LddRetVal = Rte_Call_IndStatus_DemIndicator_0_GetIndicatorStatus(&IndicatorStatus);
      if (RTE_E_OK == LddRetVal)
      {
        if (DEM_INDICATOR_OFF != IndicatorStatus)
        {
          /* Do something */
        }
      }

      break;
    }

    default: break;
  }

  if (RTE_E_OK != LddRetVal)
  {
    if (SwcDem_TestFailedCtr < 0xFFU)
    {
      SwcDem_TestFailedCtr++;
    }
  }
  SwcDem_TestPhase = 0U;
}

#define SWC_DiagnosticMonitor_STOP_SEC_CODE
#include "SWC_DiagnosticMonitor_MemMap.h"
/*******************************************************************************
 **                      End of File                                           **
 *******************************************************************************/

