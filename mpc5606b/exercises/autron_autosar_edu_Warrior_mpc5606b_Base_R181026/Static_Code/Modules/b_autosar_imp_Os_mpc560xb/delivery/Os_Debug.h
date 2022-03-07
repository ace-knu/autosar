/*******************************************************************************
**                                                                            **
**  (C) 2015-2016 HYUNDAI AUTRON Co., Ltd.                                    **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Os_Debug.h                                                    **
**                                                                            **
**  TARGET    : MPC56xx                                                       **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Header file for Os_Debug.c file containing the declaration    **
**              of Debug features(CPU/IT Load, Stack Depth) related functions **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/
#ifndef OS_DEBUG_H
#define OS_DEBUG_H
/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 1.1.3     27-Mar-2017    JH.Lee        Redmine #7467                       **
** 1.1.0     04-Nov-2016    JH.Lee        Redmine #6493                       **
**           19-Oct-2016    SH.Yoo        Redmine #5372,#5823                 **                 
** 1.0.1     08-Mar-2016    MJ.Woo        Redmine #4255                       **
** 1.0.0     23-Jan-2015    MJ.Woo        Initial version                     **
*******************************************************************************/
/* polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations> Function like macro is used to improve performance  */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_types_basic.h"
#include "Os_platform_base.h"
#include "Os_hw_core.h"
#include "Os_hw_stm.h"
#include "Os_compiler_internal_api.h"

#include "Os_alarm_api.h"
#include "Os_alarm_internal_types.h"
#include "Os_alarm_config.h"
#include "Os_task_internal_types.h"
#include "Os_Imp_Cfg.h"

#if (OS_PM_USED == STD_ON)
#include "Pm_Cfg.h"
#if (PM_ENABLED == STD_ON)
#include "SchM_Pm.h"
#endif /* End of PM_ENABLED == STD_ON*/
#endif /* End of PM_USED == STD_ON */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* 1,000,000 ticks(1 second when STM clock is 1MHz) */
#define OS_CPULOAD_INTERVAL     1000000u
#define OS_FULL_PERMILLAGE      1000u
/** The maximum value of timestamp */
#define OS_TIMESTAMP_MAX        0xFFFFFFFFu

/* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> 64 bit should be used to express large value  */
typedef unsigned long long Os_uint64;
typedef unsigned int Os_uint;

/* Pattern to used to fill the stack area */
/* polyspace:begin<MISRA-C:8.9:Not a defect:Justify with annotations> This value is came from LD file and it is unique  */
/* polyspace:begin<MISRA-C:8.12:Not a defect:Justify with annotations> This array is for representing stack address  */
extern OSDWORD OS_MAIN_TOS[];
extern OSDWORD OS_MAIN_BOS[];
/* polyspace:end<MISRA-C:8.9:Not a defect:Justify with annotations>  This value is came from LD file and it is unique */
/* polyspace:end<MISRA-C:8.12:Not a defect:Justify with annotations>  This array is for representing stack address */
/* Definitions for compatibility with AUTRON OS */
#define OS_ISR_COUNT            1
#define OS_PRE_ZERO             0
#define OS_MULTICORE            STD_OFF
#define OS_CORE_COUNT           1
#define OS_CORE_ID              0
#define OS_GET_CORE_ID(OS_CORE_ID)
#define OS_TRUE                 (1u)
#define OS_FALSE                (0u)
#define OS_ZERO                 (0u)
#define OS_ONE                  (1u)

/* Max count of measurement */
#define OS_MEASURECOUNT_MAX    0xFFFFFFFFu

/** Get current System Timer Tick */
#define OS_GET_TIMESTAMP()      OSSTM_CNT
/** Macro to disable External interrupts */
#define OS_DISABLEINTERRUPTS()  (__DI())
/** Macro to enable External interrupts */
#define OS_ENABLEINTERRUPTS()   (__EI())
/** Disable interrupts and return previous interrupt state (EE bit of MSR) */
#define OS_DISABLE_AND_SAVE_INTERRUPTS() (__DIR())
/** Restore interrupt state (EE bit of MSR) */
#define OS_RESTORE_INTERRUPTS(x)         (__RIR(x))

/** r1 register(used to stack pointer register) */
#define OS_R1                   1u
/** Macros to get Stack Pointer */
#define OS_GETSP()              (__GETREG(OS_R1))

/**
  * This structure holds the CPU and Interrupt Load value.
  */
typedef struct STag_Os_LoadType
{
  uint16 usCPULoad;     /**< Current CPU Load value */
  uint16 usCPULoadPeak; /**< CPU Load Peak value after value reset */
  uint16 usCPULoadMean; /**< CPU Load Mean value */  
  uint16 usITLoad;      /**< Current Interrupt Load value */
  uint16 usITLoadPeak;  /**< Interrupt Load Peak value after value reset */
  uint16 usITLoadMean;  /**< Interrupt Load Mean value */  
} Os_LoadType;


#define OS_THOUSAND             1000u


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/


extern FUNC(void, OS_CODE) Os_MeasureCPULoadRun(void);

#if (OS_DEBUG_CPULOAD == STD_ON)
extern FUNC(void, OS_CODE) Os_InitCPULoad(void);
extern FUNC(void, OS_CODE) Os_SetIdleForCPULoad(void);
extern FUNC(void, OS_CODE) Os_ResetIdleEntry(void);
extern FUNC(void, OS_CODE) Os_ITEntryForCPULoad(void);
extern FUNC(void, OS_CODE) Os_ITExitForCPULoad(void);
extern FUNC(void, OS_CODE) Os_ClearCPULoadPeak(void);
extern FUNC(void, OS_CODE) Os_ClearITLoadPeak(void);
extern FUNC(void, OS_CODE) Os_MeasureCPULoad(void);
extern FUNC(void, OS_CODE) Os_UserGetCPULoad(P2VAR(Os_LoadType, AUTOMATIC, OS_VAR) LpLoad);
extern FUNC(void, OS_CODE) Os_RestartMeanLoad(void);
extern FUNC(void, OS_CODE) Os_DebugH2L(void);
#endif
#if ((OS_DEBUG_STACKDEPTH == STD_ON) && (!defined(OSMEMPROTECTION)))
extern FUNC(void, OS_CODE) Os_FillMainStackPattern(void);
extern FUNC(uint32, OS_CODE) MainStack_GetUsage(void);
#endif

#if (OS_PM_USED == STD_ON)
#if (PM_ENABLED == STD_ON)
extern void Pm_ActivatePmTask(void);
#endif
#endif

extern void __DI(void);
extern void __EI(void);
extern Os_uint __DIR(void);
extern void __RIR(Os_uint x);

#endif /* OS_DEBUG_H_ */

/* polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations> Function like macro is used to improve performance  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
