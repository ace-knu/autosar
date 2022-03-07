/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
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
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 1.0.0     23-Jan-2015    MJ.Woo        Initial version                     **
*******************************************************************************/
#ifndef OS_DEBUG_H_
#define OS_DEBUG_H_

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
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define OS_DEBUG_AR_RELEASE_MAJOR_VERSION    4
#define OS_DEBUG_AR_RELEASE_MINOR_VERSION    0
#define OS_DEBUG_AR_RELEASE_REVISION_VERSION 3

/* Software version information */
#define OS_DEBUG_SW_MAJOR_VERSION    40
#define OS_DEBUG_SW_MINOR_VERSION    69
#define OS_DEBUG_SW_PATCH_VERSION    0

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* If you want to disable debugging features, change this option to STD_OFF */
#define OS_DEBUG_CPULOAD        STD_ON
#define OS_DEBUG_STACKDEPTH     STD_ON

/* 1,000,000 ticks(1 second when STM clock is 1MHz) */
#define OS_CPULOAD_INTERVAL     1000000u
#define OS_FULL_PERMILLAGE      1000u
#define OS_TIMESTAMP_MAX        0xFFFFFFFFu

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

#ifndef NULL
#define NULL (0)
#endif

/** Get current System Timer Tick */
#define OS_GET_TIMESTAMP()      OSSTM_CNT
/** Macro to disable External interrupts */
#if defined(OSGHSPPC)
#define OS_DISABLEINTERRUPTS()  __DI()
#elif defined(OSCWPPC)
#define OS_DISABLEINTERRUPTS()  __asm(wrteei  0)
#endif
/** Macro to enable External interrupts */
#if defined(OSGHSPPC)
#define OS_ENABLEINTERRUPTS()   __EI()
#elif defined(OSCWPPC)
#define OS_ENABLEINTERRUPTS()    __asm(wrteei  1)
#endif
#if defined(OSGHSPPC)
/** Disable interrupts and return previous interrupt state (EE bit of MSR) */
#define OS_DISABLE_AND_SAVE_INTERRUPTS() __DIR()
/** Restore interrupt state (EE bit of MSR) */
#define OS_RESTORE_INTERRUPTS(x)         __RIR(x)
#elif defined(OSCWPPC)
/** Disable interrupts and return previous interrupt state (EE bit of MSR) */
OSINLINE OSDWORD OS_DISABLE_AND_SAVE_INTERRUPTS (void)
{
    register OSDWORD x;
    asm
    {
      mfmsr    x;
      e_rlwinm x, x, 0x0, 0x11, 0x0F;
    }
    return x;
}
/** Restore interrupt state (EE bit of MSR) */
OSINLINE void OS_RESTORE_INTERRUPTS (register OSDWORD x)
{
  register OSDWORD y;
    asm
    {
      e_andi   y, x, 0x8000;
      mfmsr    x;
      e_rlwinm y, y, 0x0, 0x11, 0x0F;
      or       x, x, y;
      mtmsr    x;
    }
}
#endif
/** r1 register(used to stack pointer register) */
#define OS_R1                   1u
/* Get the SP register value */
#if defined(OSGHSPPC) || defined(OSDIABPPC)
OSASM OSDWORD OSGETSTACKPOINTER_ (void)
{
    mr r3, r1
}

OSINLINE OSDWORD OS_GETSP (void)
{
    return OSGETSTACKPOINTER_();
}
#endif

#if defined(OSCWPPC)
OSINLINE OSDWORD OS_GETSP (void)
{
    register OSDWORD x;
    OSASM
    {
        mr x, r1;
    }
    return x;
}
#endif
#define OS_PIT_MCR    (*(volatile uint32 *)(0xC3FF0000u))
#define OS_PIT0_LDVAL (*(volatile uint32 *)(0xC3FF0100u))
#define OS_PIT0_CVAL  (*(volatile uint32 *)(0xC3FF0104u))
#define OS_PIT0_TCTRL (*(volatile uint32 *)(0xC3FF0108u))
#define OS_PIT0_TFLG  (*(volatile uint32 *)(0xC3FF010Cu))
#define OS_PIT1_LDVAL (*(volatile uint32 *)(0xC3FF0110u))
#define OS_PIT1_CVAL  (*(volatile uint32 *)(0xC3FF0114u))
#define OS_PIT1_TCTRL (*(volatile uint32 *)(0xC3FF0118u))
#define OS_PIT1_TFLG  (*(volatile uint32 *)(0xC3FF011Cu))
#define OS_PIT2_LDVAL (*(volatile uint32 *)(0xC3FF0120u))
#define OS_PIT2_CVAL  (*(volatile uint32 *)(0xC3FF0124u))
#define OS_PIT2_TCTRL (*(volatile uint32 *)(0xC3FF0128u))
#define OS_PIT2_TFLG  (*(volatile uint32 *)(0xC3FF012Cu))
#define OS_PIT3_LDVAL (*(volatile uint32 *)(0xC3FF0130u))
#define OS_PIT3_CVAL  (*(volatile uint32 *)(0xC3FF0134u))
#define OS_PIT3_TCTRL (*(volatile uint32 *)(0xC3FF0138u))
#define OS_PIT3_TFLG  (*(volatile uint32 *)(0xC3FF013Cu))

#define OS_PIT7_LDVAL (*(volatile uint32 *)(0xC3FF0170u))
#define OS_PIT7_CVAL  (*(volatile uint32 *)(0xC3FF0174u))
#define OS_PIT7_TCTRL (*(volatile uint32 *)(0xC3FF0178u))
#define OS_PIT7_TFLG  (*(volatile uint32 *)(0xC3FF017Cu))

/**
  * This structure holds the CPU and Interrupt Load value.
  */
typedef struct STag_Os_LoadType
{
  uint16 usCPULoad;     /**< Current CPU Load value */
  uint16 usCPULoadPeak; /**< CPU Load Peak value after value reset */
  uint16 usITLoad;      /**< Current Interrupt Load value */
  uint16 usITLoadPeak;  /**< Interrupt Load Peak value after value reset */
} Os_LoadType;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

INLINE void Os_Halt(void)
{
#if defined(OSGHSPPC)
  __WAIT();
#elif defined(OSCWPPC)
  asm
  {
      wait;
  }
#endif
}

extern FUNC(void, OS_CODE) Os_MeasureCPULoadRun(void);

#if (OS_DEBUG_CPULOAD == STD_ON)
extern FUNC(void, OS_CODE) Os_InitCPULoad(void);
extern FUNC(void, OS_CODE) Os_SetIdleForCPULoad(void);
extern FUNC(void, OS_CODE) Os_ResetIdleEntry(void);
extern FUNC(void, OS_CODE) Os_ITEntryForCPULoad(void);
extern FUNC(void, OS_CODE) Os_ITExitForCPULoad(void);
extern FUNC(void, OS_CODE) Os_UserGetCPULoad(
                 P2VAR(Os_LoadType, AUTOMATIC, OS_VAR) LpLoad, boolean restart);
extern FUNC(void, OS_CODE) Os_ClearCPULoadPeak(void);
extern FUNC(void, OS_CODE) Os_ClearITLoadPeak(void);
#endif
#if (OS_DEBUG_STACKDEPTH == STD_ON)
extern FUNC(void, OS_CODE) Os_FillMainStackPattern(void);
extern FUNC(uint32, OS_CODE) MainStack_GetUsage(void);
#endif

extern  FUNC(void, OS_CODE) Os_GetTaskJitter(void);


#endif /* OS_DEBUG_H_ */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
