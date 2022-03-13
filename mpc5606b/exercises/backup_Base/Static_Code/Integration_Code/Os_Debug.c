/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Os_Debug.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Debug feature(CPU/IT Load, Stack Depth)          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 1.0.0     23-Jan-2015    MJ.Woo        Initial version                     **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os.h"
#include "Os_Debug.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define OS_DEBUG_C_AR_RELEASE_MAJOR_VERSION    4
#define OS_DEBUG_C_AR_RELEASE_MINOR_VERSION    0
#define OS_DEBUG_C_AR_RELEASE_REVISION_VERSION 3

/* File version information */
#define OS_DEBUG_C_SW_MAJOR_VERSION    40
#define OS_DEBUG_C_SW_MINOR_VERSION    69
#define OS_DEBUG_C_SW_PATCH_VERSION    0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
//#if 0
//#if (OS_AR_RELEASE_MAJOR_VERSION != OS_DEBUG_C_AR_RELEASE_MAJOR_VERSION)
//#error "Os_Debug.c : Mismatch in Specification Major Version"
//#endif
//#if (OS_AR_RELEASE_MINOR_VERSION != OS_DEBUG_C_AR_RELEASE_MINOR_VERSION)
//#error "Os_Debug.c : Mismatch in Specification Minor Version"
//#endif
//#if (OS_AR_RELEASE_REVISION_VERSION != OS_DEBUG_C_AR_RELEASE_REVISION_VERSION)
//#error "Os_Debug.c : Mismatch in Specification REVISION Version"
//#endif
//#if (OS_SW_MAJOR_VERSION != OS_DEBUG_C_SW_MAJOR_VERSION)
//#error "Os_Debug.c : Mismatch in Software Major Version"
//#endif
//#if (OS_SW_MINOR_VERSION != OS_DEBUG_C_SW_MINOR_VERSION)
//#error "Os_Debug.c : Mismatch in Software Minor Version"
//#endif
//#endif
void *memcpy(void *dst, const void *src, unsigned long n);

void *memcpy(void *dst, const void *src, unsigned long n)
{
    P2VAR(uint8, AUTOMATIC, COM_VAR)LpDest;
    P2VAR(uint8, AUTOMATIC, COM_VAR)LpSrc;
    unsigned long LddBufferIndex;
    LddBufferIndex = 0;
    /* Get the pointer to destination data */
    LpDest = (P2VAR(uint8, AUTOMATIC, COM_VAR))dst;
    /* Get the pointer to source */
    LpSrc = (P2VAR(uint8, AUTOMATIC, COM_VAR))src;
    /* Copy data */
    while(n != 0)
    {
      /* Loop for "Length" number of times */
      LpDest[LddBufferIndex] = LpSrc[LddBufferIndex];
      LddBufferIndex++;
      n--;
    }
}
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#if (OS_DEBUG_CPULOAD == STD_ON)

#define OS_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
/** This global variable used to save elapsed CPU time. */
VAR(uint32, OS_VAR) Os_GulCPUTimeElapsed[OS_CORE_COUNT];
/** This global variable used to save previous timestamp for CPU load. */
VAR(uint32, OS_VAR) Os_GulTimestampBefore[OS_CORE_COUNT];
/** This global variable used to save idle time. */
VAR(uint32, OS_VAR) Os_GulCPUTimeInIdle[OS_CORE_COUNT];
/** This global variable used to save interrupt time. */
VAR(uint32, OS_VAR) Os_GulCPUTimeInIT[OS_CORE_COUNT];
/** This global variable used to save timestamp when enter idle mode. */
VAR(uint32, OS_VAR) Os_GulIdleEntryTime[OS_CORE_COUNT];
/** This global variable used to save timestamp when enter interrupt context. */
VAR(uint32, OS_VAR) Os_GulITEntryTime[OS_CORE_COUNT];
#define OS_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

#define OS_START_SEC_VAR_CLEARED_16
#include "MemMap.h"
/** This global variable used to save CPU load. */
VAR(uint16, OS_VAR) Os_GusCPULoad[OS_CORE_COUNT];
/** This global variable used to save Interrupt load. */
VAR(uint16, OS_VAR) Os_GusITLoad[OS_CORE_COUNT];
/** This global variable used to save peak CPU load. */
VAR(uint16, OS_VAR) Os_GusCPULoadPeak[OS_CORE_COUNT];
/** This global variable used to save peak Interrupt load. */
VAR(uint16, OS_VAR) Os_GusITLoadPeak[OS_CORE_COUNT];
#define OS_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

#define OS_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
/** This global Variable used as a flag to hold idle mode. */
VAR(boolean, OS_VAR) Os_GblInIdleMode[OS_CORE_COUNT];
/** This global Variable used to check that 'wait' instruction is not called */
VAR(boolean, OS_VAR) Os_GblBeforeHalt[OS_CORE_COUNT];
#define OS_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#define OS_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
/** This global Variable used to check the interrupt context. */
VAR(uint8, OS_VAR) Os_GucITCount[OS_CORE_COUNT];
#define OS_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#endif /* if (OS_DEBUG_CPULOAD == STD_ON) */

#define OS_THOUSAND             1000u

typedef struct STagTdd_Os_Jitter
{
  uint32 ddmax;
  uint32 ddcur;
}Tdd_Os_Jitter;

VAR(Tdd_Os_Jitter, OS_VAR) Os_GddJitter[OSNALMS];

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

#define OS_START_SEC_CODE
#include "MemMap.h"



#if (OS_DEBUG_CPULOAD == STD_ON)
static inline FUNC(void, OS_CODE) Os_SumCPUTimeInIT(uint32 LulTimestampNow);

static FUNC(void, OS_CODE) Os_MeasureCPULoad(boolean LblUserReq);

void Os_MeasureCPULoadRun(void)
{
 // #if (OS_DEBUG_CPULOAD == STD_ON)
 // Os_MeasureCPULoad();
 // #endif /* if (OS_DEBUG_CPULOAD == STD_ON) */
}

/***************************************************************************//**
 * Function Name        : Os_InitCPULoad
 *
 * Service ID           : NA
 *
 * Description          : This function initializes CPU and IT load variables.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : NA
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GulCPUTimeElapsed, Os_GulTimestampBefore,
 *                        Os_GulCPUTimeInIdle, Os_GulIdleEntryTime,
 *                        Os_GblInIdleMode, Os_GulCPUTimeInIT,
 *                        Os_GulITEntryTime, Os_GucITCount, Os_GusCPULoad,
 *                        Os_GusITLoad, Os_GusCPULoadPeak, Os_GusITLoadPeak
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
FUNC(void, OS_CODE) Os_InitCPULoad(void)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  Os_GulCPUTimeElapsed[OS_CORE_ID] = 0;
  Os_GulTimestampBefore[OS_CORE_ID] = OS_GET_TIMESTAMP();

  Os_GulCPUTimeInIdle[OS_CORE_ID] = 0;
  Os_GulIdleEntryTime[OS_CORE_ID] = 0;
  Os_GblInIdleMode[OS_CORE_ID] = OS_FALSE;

  Os_GulCPUTimeInIT[OS_CORE_ID] = 0;
  Os_GulITEntryTime[OS_CORE_ID] = 0;
  Os_GucITCount[OS_CORE_ID] = 0;

  Os_GusCPULoad[OS_CORE_ID] = 0;
  Os_GusITLoad[OS_CORE_ID] = 0;
  Os_GusCPULoadPeak[OS_CORE_ID] = 0;
  Os_GusITLoadPeak[OS_CORE_ID] = 0;
}

/***************************************************************************//**
 * Function Name        : Os_ITEntryForCPULoad
 *
 * Service ID           : NA
 *
 * Description          : Update idle time.
 *                        Start CPU occupancy time measure in Interrupt.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : NA
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GulCPUTimeInIdle, Os_GulIdleEntryTime,
 *                        Os_GblInIdleMode, Os_GulITEntryTime, Os_GucITCount
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
FUNC(void, OS_CODE) Os_ITEntryForCPULoad(void)
{
  uint32 LulTimestampNow = OS_GET_TIMESTAMP();
  uint32 LulCPUTimeInIdle;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* Sum CPU time in IDLE */
  if (Os_GblInIdleMode[OS_CORE_ID] == OS_TRUE)
  {
    Os_GblInIdleMode[OS_CORE_ID] = OS_FALSE;

    if (LulTimestampNow >= Os_GulIdleEntryTime[OS_CORE_ID])
    {
      LulCPUTimeInIdle = (LulTimestampNow - Os_GulIdleEntryTime[OS_CORE_ID]);
    }
    else
    {
      LulCPUTimeInIdle = (OS_TIMESTAMP_MAX - Os_GulIdleEntryTime[OS_CORE_ID]);
      LulCPUTimeInIdle += (LulTimestampNow + OS_ONE);
    }

    /* add to Os_GulCPUTimeInIdle the duration of idle mode */
    Os_GulCPUTimeInIdle[OS_CORE_ID] += LulCPUTimeInIdle;
  }

  /* Record IT entry time */
  if (Os_GucITCount[OS_CORE_ID] == 0)
  {
    Os_GulITEntryTime[OS_CORE_ID] = LulTimestampNow;
  }
  Os_GucITCount[OS_CORE_ID]++;
}

/***************************************************************************//**
 * Function Name        : Os_SumCPUTimeInIT
 *
 * Service ID           : NA
 *
 * Description          : Update CPU time used in ISR.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param[in]             LulTimestampNow    Current timestamp
 *                                           (range : 0 ~ OS_TIMESTAMP_MAX)
 *
 * @return              : void
 *
 * @pre                 : NA
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GulCPUTimeInIT, Os_GulITEntryTime
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
static inline FUNC(void, OS_CODE) Os_SumCPUTimeInIT(uint32 LulTimestampNow)
{
  uint32 LulCPUTimeInIT;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  if (LulTimestampNow >= Os_GulITEntryTime[OS_CORE_ID])
  {
    LulCPUTimeInIT = (LulTimestampNow - Os_GulITEntryTime[OS_CORE_ID]);
  }
  else
  {
    LulCPUTimeInIT = (OS_TIMESTAMP_MAX - Os_GulITEntryTime[OS_CORE_ID]);
    LulCPUTimeInIT += (LulTimestampNow + OS_ONE);
  }

  /* add to Os_GulCPUTimeInIT the duration of ISR */
  Os_GulCPUTimeInIT[OS_CORE_ID] += LulCPUTimeInIT;
}

/***************************************************************************//**
 * Function Name        : Os_ITExitForCPULoad
 *
 * Service ID           : NA
 *
 * Description          : Stop CPU occupancy time measure in Interrupt.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : NA
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GucITCount
 *
 *                        Function(s) invoked    :
 *                        Os_SumCPUTimeInIT()
 ******************************************************************************/
FUNC(void, OS_CODE) Os_ITExitForCPULoad(void)
{
  uint32 LulTimestampNow = OS_GET_TIMESTAMP();
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* Sum CPU time in IT */
  Os_GucITCount[OS_CORE_ID]--;
  if (Os_GucITCount[OS_CORE_ID] == 0)
  {
    Os_SumCPUTimeInIT(LulTimestampNow);
  }
}

/***************************************************************************//**
 * Function Name        : Os_ResetIdleEntry
 *
 * Service ID           : NA
 *
 * Description          : If an Interrupt is occurred after set idle flag but
 *                        not passed Halt(wait mode), then reset idle flag and
 *                        idle entry time
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : This function should be called from PreTaskHook()
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GblBeforeHalt, Os_GblInIdleMode,
 *                        Os_GulIdleEntryTime
 *
 *                        Function(s) invoked    :
 *                        GetTaskID()
 ******************************************************************************/
FUNC(void, OS_CODE) Os_ResetIdleEntry(void)
{
  TaskType LddRunningTask;
  StatusType LddReturn;

  LddReturn = GetTaskID(&LddRunningTask);
  if ((LddReturn == E_OK) && (LddRunningTask == OsTask_BSW_System_Idle) &&
      (Os_GblBeforeHalt[OS_CORE_ID] == OS_TRUE))
  {
    Os_GblInIdleMode[OS_CORE_ID] = OS_TRUE;
    Os_GulIdleEntryTime[OS_CORE_ID] = OS_GET_TIMESTAMP();
  }
}

/***************************************************************************//**
 * Function Name        : Os_MeasureCPULoad
 *
 * Service ID           : NA
 *
 * Description          : This service measures CPU and IT load.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param[in]             LblUserReq    OS_TRUE : Calculate CPU and IT load even if
 *                                      not reached at OS_CPULOAD_INTERVAL
 *                                      OS_FALSE : Calculate CPU and IT load when
 *                                      exceed OS_CPULOAD_INTERVAL
 *
 * @return              : void
 *
 * @pre                 : NA
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GulCPUTimeElapsed, Os_GulTimestampBefore,
 *                        Os_GulCPUTimeInIdle, Os_GusCPULoad, Os_GusITLoad,
 *                        Os_GusCPULoadPeak, Os_GusITLoadPeak
 *
 *                        Function(s) invoked    :
 *                        Os_SumCPUTimeInIT()
 ******************************************************************************/
static FUNC(void, OS_CODE) Os_MeasureCPULoad(boolean LblUserReq)
{
  uint32 LulTimestampNow = OS_GET_TIMESTAMP();
  uint32 LulCPUTimeElapsed;
  uint32 LulCPULoad;
  boolean LblMeasurementFail = OS_FALSE;
  boolean LblRestart = OS_FALSE;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* Get the elapsed time since entering here last. */
  if (LulTimestampNow > Os_GulTimestampBefore[OS_CORE_ID])
  {
    LulCPUTimeElapsed = (LulTimestampNow - Os_GulTimestampBefore[OS_CORE_ID]);
  }
  else if (LulTimestampNow < Os_GulTimestampBefore[OS_CORE_ID])
  {
    LulCPUTimeElapsed = (OS_TIMESTAMP_MAX - Os_GulTimestampBefore[OS_CORE_ID]);
    LulCPUTimeElapsed += (LulTimestampNow + OS_ONE);
  }
  else
  {
    LulCPUTimeElapsed = OS_TIMESTAMP_MAX;
  }
  Os_GulTimestampBefore[OS_CORE_ID] = LulTimestampNow;

  /* Os_GulCPUTimeElapsed overflows */
  if ((OS_TIMESTAMP_MAX - Os_GulCPUTimeElapsed[OS_CORE_ID]) < LulCPUTimeElapsed)
  {
    LblMeasurementFail = OS_TRUE;
  }
  else
  {
    Os_GulCPUTimeElapsed[OS_CORE_ID] += LulCPUTimeElapsed;
    /* In case that OS enters the idle state rarely
     * or measurement interval is too small
     */
    if ((Os_GulCPUTimeElapsed[OS_CORE_ID] < Os_GulCPUTimeInIdle[OS_CORE_ID]) ||
        (Os_GulCPUTimeElapsed[OS_CORE_ID] < Os_GulCPUTimeInIT[OS_CORE_ID]))
    {
      LblMeasurementFail = OS_TRUE;
    }
  }

  if (LblMeasurementFail == OS_FALSE)
  {
    if ((Os_GulCPUTimeElapsed[OS_CORE_ID] >= OS_CPULOAD_INTERVAL) ||
         (LblUserReq == OS_TRUE))
    {
      if (Os_GulCPUTimeElapsed[OS_CORE_ID] == OS_ZERO)
      {
        Os_GusCPULoad[OS_CORE_ID] = OS_ZERO;
        Os_GusITLoad[OS_CORE_ID] = OS_ZERO;
      }
      else if (Os_GulCPUTimeElapsed[OS_CORE_ID] <
                                          (OS_TIMESTAMP_MAX/OS_FULL_PERMILLAGE))
      {
        /* Calculate CPU load */
        LulCPULoad = Os_GulCPUTimeElapsed[OS_CORE_ID] -
                                                Os_GulCPUTimeInIdle[OS_CORE_ID];
        LulCPULoad = (LulCPULoad * OS_FULL_PERMILLAGE) /
                                               Os_GulCPUTimeElapsed[OS_CORE_ID];
        Os_GusCPULoad[OS_CORE_ID] = (uint16)LulCPULoad;
        /* Calculate IT load */
        /* If current context is ISR */
        if (Os_GucITCount[OS_CORE_ID] > 0)
        {
          Os_SumCPUTimeInIT(LulTimestampNow);
          /* Updating Interrupt entry time is required
           * when call this function in ISR */
          Os_GulITEntryTime[OS_CORE_ID] = LulTimestampNow;
        }
        LulCPULoad = Os_GulCPUTimeInIT[OS_CORE_ID];
        LulCPULoad = (LulCPULoad * OS_FULL_PERMILLAGE) /
                                               Os_GulCPUTimeElapsed[OS_CORE_ID];
        Os_GusITLoad[OS_CORE_ID] = (uint16)LulCPULoad;
      }
      else
      {
        /* Calculate CPU load */
        LulCPULoad = Os_GulCPUTimeElapsed[OS_CORE_ID] -
                                                Os_GulCPUTimeInIdle[OS_CORE_ID];
        LulCPULoad = LulCPULoad /
                        (Os_GulCPUTimeElapsed[OS_CORE_ID] / OS_FULL_PERMILLAGE);
        Os_GusCPULoad[OS_CORE_ID] = (uint16)LulCPULoad;
        /* Calculate IT load */
        /* If current context is ISR */
        if (Os_GucITCount[OS_CORE_ID] > 0)
        {
          Os_SumCPUTimeInIT(LulTimestampNow);
          /* Updating Interrupt entry time is required
           * when call this function in ISR */
          Os_GulITEntryTime[OS_CORE_ID] = LulTimestampNow;
        }
        LulCPULoad = Os_GulCPUTimeInIT[OS_CORE_ID];
        LulCPULoad = LulCPULoad /
                        (Os_GulCPUTimeElapsed[OS_CORE_ID] / OS_FULL_PERMILLAGE);
        Os_GusITLoad[OS_CORE_ID] = (uint16)LulCPULoad;
      }

      /* Update peak load */
      if (Os_GusCPULoad[OS_CORE_ID] > Os_GusCPULoadPeak[OS_CORE_ID])
      {
        Os_GusCPULoadPeak[OS_CORE_ID] = Os_GusCPULoad[OS_CORE_ID];
      }

      if (Os_GusITLoad[OS_CORE_ID] > Os_GusITLoadPeak[OS_CORE_ID])
      {
        Os_GusITLoadPeak[OS_CORE_ID] = Os_GusITLoad[OS_CORE_ID];
      }

      /* Prepare for the next interval
       */
      LblRestart = OS_TRUE;
    }
  }

  if ( (LblMeasurementFail == OS_TRUE) || (LblRestart == OS_TRUE) )
  {
    /* Restart measurement */
    Os_GulCPUTimeElapsed[OS_CORE_ID] = 0;
    Os_GulCPUTimeInIdle[OS_CORE_ID] = 0;
    Os_GulCPUTimeInIT[OS_CORE_ID] = 0;
  }
}

/***************************************************************************//**
 * Function Name        : Os_SetIdleForCPULoad
 *
 * Service ID           : NA
 *
 * Description          : Start CPU idle time measure and enter wait state
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : None Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : NA
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GblInIdleMode, Os_GulIdleEntryTime,
 *                        Os_GblBeforeHalt
 *
 *                        Function(s) invoked    :
 *                        Os_MeasureCPULoad(), Os_Halt()
 ******************************************************************************/
FUNC(void, OS_CODE) Os_SetIdleForCPULoad(void)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  if (Os_GblInIdleMode[OS_CORE_ID] == OS_FALSE)
  {
    #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
    OS_DISABLEINTERRUPTS();
    #endif

    Os_MeasureCPULoad(OS_FALSE);
    Os_GblInIdleMode[OS_CORE_ID] = OS_TRUE;
    Os_GulIdleEntryTime[OS_CORE_ID] = OS_GET_TIMESTAMP();
    Os_GblBeforeHalt[OS_CORE_ID] = OS_TRUE;

    #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
    OS_ENABLEINTERRUPTS();
    #endif
  }
  /* Wait until an interrupt occurs */
  Os_Halt();
  Os_GblBeforeHalt[OS_CORE_ID] = OS_FALSE;
  Os_GblInIdleMode[OS_CORE_ID] = OS_FALSE;
}

/***************************************************************************//**
 * Function Name        : Os_ClearCPULoadPeak
 *
 * Service ID           : NA
 *
 * Description          : Clear CPU Load Peak value in current core.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : NA
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GusCPULoadPeak
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
FUNC(void, OS_CODE) Os_ClearCPULoadPeak(void)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  Os_GusCPULoadPeak[OS_CORE_ID] = 0;
}

/***************************************************************************//**
 * Function Name        : Os_ClearITLoadPeak
 *
 * Service ID           : NA
 *
 * Description          : Clear Interrupt Load Peak value in current core.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : NA
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GusITLoadPeak
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
FUNC(void, OS_CODE) Os_ClearITLoadPeak(void)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  Os_GusITLoadPeak[OS_CORE_ID] = 0;
}

/***************************************************************************//**
 * Function Name        : Os_UserGetCPULoad
 *
 * Service ID           : NA
 *
 * Description          : This service is used to get CPU and Interrupt Load.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : None Re-entrant
 *
 * @param[out]            LpLoad     A pointer for save CPU and IT load
 * @param[in]             restart    OS_TRUE : Get load and restart measurement
 *                                   OS_FALSE : Just get load
 *
 * @return              : void
 *
 * @pre                 : NA
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GusCPULoad, Os_GusCPULoadPeak, Os_GusITLoad,
 *                        Os_GusITLoadPeak
 *
 *                        Function(s) invoked    :
 *                        Os_MeasureCPULoad()
 ******************************************************************************/
FUNC(void, OS_CODE) Os_UserGetCPULoad(
                  P2VAR(Os_LoadType, AUTOMATIC, OS_VAR) LpLoad, boolean restart)
{
  #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
  uint32 LulIntStat;
  #endif
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
  LulIntStat = OS_DISABLE_AND_SAVE_INTERRUPTS();
  #endif

  if (restart == OS_TRUE)
  {
    Os_MeasureCPULoad(OS_TRUE);
  }

  if (LpLoad != NULL_PTR)
  {
    LpLoad->usCPULoad = Os_GusCPULoad[OS_CORE_ID];
    LpLoad->usCPULoadPeak = Os_GusCPULoadPeak[OS_CORE_ID];
    LpLoad->usITLoad = Os_GusITLoad[OS_CORE_ID];
    LpLoad->usITLoadPeak = Os_GusITLoadPeak[OS_CORE_ID];
  }

  #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
  OS_RESTORE_INTERRUPTS(LulIntStat);
  #endif
}
#endif /* if (OS_DEBUG_CPULOAD == STD_ON) */

#if (OS_DEBUG_STACKDEPTH == STD_ON)
/***************************************************************************//**
 * Function Name        : Os_FillMainStackPattern
 *
 * Service ID           : NA
 *
 * Description          : Fill stack pattern to the Main stack
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : NA
 *
 * @remarks             : Global Variable(s)     :
 *                        OS_MAIN_BOS
 *
 *                        Function(s) invoked    :
 *                        OS_GETSP()
 ******************************************************************************/
FUNC(void, OS_CODE) Os_FillMainStackPattern(void)
{
  P2VAR(uint32, AUTOMATIC, OS_VAR) LpStackPointer;
  P2VAR(uint32, AUTOMATIC, OS_VAR) LpAddr;

  LpStackPointer = (uint32 *)OS_GETSP();

  for (LpAddr = (uint32 *)OS_MAIN_BOS; LpAddr < LpStackPointer; LpAddr++)
  {
    *LpAddr = OSSTKCHECKPATTERN;
  }
}

/***************************************************************************//**
 * Function Name        : MainStack_GetUsage
 *
 * Service ID           : NA
 *
 * Description          : Returns the number of used bytes into the Main stack
 *                        (System internal). The return value should be bigger
 *                        than 0
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * Parameters           : None
 *
 * @return              : Number of maximum used bytes of Main stack
 *                        (range : 0 ~ Main stack size)
 *
 * @pre                 : NA
 *
 * @remarks             : Global Variable(s)     :
 *                        OS_MAIN_TOS, OS_MAIN_BOS
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
FUNC(uint32, OS_CODE) MainStack_GetUsage(void)
{
  uint32 LulStackIndex;
  uint32 LulStackDepth;
  uint32 LulMainStackSize;
  uint32 LulStackPatternSize;

  LulStackPatternSize = sizeof(uint32);
  /* 4byte unit */
  LulMainStackSize = OS_MAIN_TOS - OS_MAIN_BOS;

  for (LulStackIndex = 0; LulStackIndex < LulMainStackSize; LulStackIndex++)
  {
    if (OS_MAIN_BOS[LulStackIndex] != OSSTKCHECKPATTERN)
    {
      break;
    }
  }
  LulStackDepth = (LulMainStackSize - LulStackIndex) * LulStackPatternSize;

  return LulStackDepth;
}
#endif /* if (OS_DEBUG_STACKDEPTH == STD_ON) */

/***************************************************************************//**
 * Function Name        : Os_GetTaskJitter
 *
 * Service ID           : NA
 *
 * Description          : This service is used to get jitter of periodic task.
 *                        The Jitter is consists of maximum value and current value.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : None Re-entrant
 *
 * @param                 NA
 *
 * @return              : void
 *
 * @pre                 : NA
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaMaxJitter, Os_GaaStaticAlarm, Os_GaaAlarm
 *                        Os_GpStaticTask
 *                        Function(s) invoked    :
                          None
 ******************************************************************************/
 FUNC(void, OS_CODE) Os_GetTaskJitter(void)
{
#if (OSNUSERALMS > 0U )
TickType LddCycle;
uint32 LddCurrentJitter;
uint8 LucCount;
TickType LddTick;


//#if (OS_MULTICORE == STD_ON)
//CoreIDType OS_CORE_ID;
//#endif

/* Check whether the current task is new or preempted */
  if(OsRunning_->pcontext == OS_ZERO)
  {
//  /* Get The coreID */
//   OS_GET_CORE_ID(OS_CORE_ID);
    LucCount = OS_ZERO;


    while(LucCount < OSNALMS)
    {
      /* Find the alarm which activates current task */
      if((TaskType)(OsAlarmsCfg[LucCount].taskIndex)
                                            == OsRunning_->taskId)
      {
          #if  defined(OSALMSETEVENT) || defined(OSSCTSETEVENT)
          if(OsAlarms[LucCount].action.event == 0)
          #endif
          {
            /* Get left ticks to expired alarm */
          GetAlarm(OS_MKOBJID(OBJECT_ALARM,LucCount), &LddTick);
           /* Get cycle ticks to expired alarm */
          LddCycle = OsAlarms[LucCount].cycle;
		  
          /* Calculate Jitter value (in permile) */
		  if(LddCycle > LddTick)
		  {
          LddCurrentJitter = (LddCycle - LddTick)*OS_THOUSAND/LddCycle;
		  }
		  else
		  {
		  LddCurrentJitter = OS_ZERO;
	    }
		      /* Save current jitter value in alarm ID (in permile) */
          Os_GddJitter[LucCount].ddcur = LddCurrentJitter;
          /* Save Maximum jitter value in alarm ID (in permile) */
          if(LddCurrentJitter > Os_GddJitter[LucCount].ddmax)
          {
             Os_GddJitter[LucCount].ddmax = LddCurrentJitter;
          }
          break;
          }
      }
      LucCount++;
    }
  }
}
#endif


#define OS_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
