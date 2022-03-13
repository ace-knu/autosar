/******************************************************************************
*
*       Freescale(TM) and the Freescale logo are trademarks of Freescale Semiconductor, Inc.
*       All other product or service names are the property of their respective owners.
*       (C) Freescale Semiconductor, Inc. 2018
*
*       THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
*       BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
*       Freescale Semiconductor, Inc.
*
*       Description: Configuration Header file
*
*       Note: The implementation that was used is: AUTOSAR_MPC5600
*       System Generator for AUTOSAR OS/MPC5600 - Version: 4.0 Build 4.0.69
*
********************************************************************************/
#ifndef OSCFG_H
#define OSCFG_H
#define APP_START_SEC_CODE
#include    "Os_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"


/* Applications */
#define OsApplication0 ((ApplicationType)OS_MKOBJID(OBJECT_APPLICATION, 0U)) /* Application ID */

/* Spinlock */

/* Application modes */
#define OsAppMode0 ((AppModeType)0U)       /* AppMode ID */

/* Common stack */

/* Task definitions */
#define OsTask_BSW_ComMModeRequest ((TaskType)OS_MKOBJID(OBJECT_TASK, 0U)) /* Task ID */
extern void FuncOsTask_BSW_ComMModeRequest(void); /* Task entry point */
#define OsTask_BSW_AppModeRequest ((TaskType)OS_MKOBJID(OBJECT_TASK, 1U)) /* Task ID */
extern void FuncOsTask_BSW_AppModeRequest(void); /* Task entry point */
#define OsTask_BSW_FG2_IOManager ((TaskType)OS_MKOBJID(OBJECT_TASK, 2U)) /* Task ID */
extern void FuncOsTask_BSW_FG2_IOManager(void); /* Task entry point */
#define OsTask_BSW_FG2_WdgMAPI ((TaskType)OS_MKOBJID(OBJECT_TASK, 3U)) /* Task ID */
extern void FuncOsTask_BSW_FG2_WdgMAPI(void); /* Task entry point */
#define OsTask_ASW_FG2_WdgMTestMode ((TaskType)OS_MKOBJID(OBJECT_TASK, 4U)) /* Task ID */
extern void FuncOsTask_ASW_FG2_WdgMTestMode(void); /* Task entry point */
#define OsTask_BSW_FG1_5ms_Mem ((TaskType)OS_MKOBJID(OBJECT_TASK, 5U)) /* Task ID */
extern void FuncOsTask_BSW_FG1_5ms_Mem(void); /* Task entry point */
#define OsTask_BSW_FG1_5ms_Com ((TaskType)OS_MKOBJID(OBJECT_TASK, 6U)) /* Task ID */
extern void FuncOsTask_BSW_FG1_5ms_Com(void); /* Task entry point */
#define OsTask_BSW_FG1_IOManager ((TaskType)OS_MKOBJID(OBJECT_TASK, 7U)) /* Task ID */
extern void FuncOsTask_BSW_FG1_IOManager(void); /* Task entry point */
#define OsTask_BSW_FG1_10ms ((TaskType)OS_MKOBJID(OBJECT_TASK, 8U)) /* Task ID */
extern void FuncOsTask_BSW_FG1_10ms(void); /* Task entry point */
#define OsTask_ASW_FG1_10ms ((TaskType)OS_MKOBJID(OBJECT_TASK, 9U)) /* Task ID */
extern void FuncOsTask_ASW_FG1_10ms(void); /* Task entry point */
#define OsTask_ASW_TestModeManager ((TaskType)OS_MKOBJID(OBJECT_TASK, 10U)) /* Task ID */
extern void FuncOsTask_ASW_TestModeManager(void); /* Task entry point */
#define OsTask_ASW_FG1_100ms ((TaskType)OS_MKOBJID(OBJECT_TASK, 11U)) /* Task ID */
extern void FuncOsTask_ASW_FG1_100ms(void); /* Task entry point */
#define OsTask_BSW_Mem_Process ((TaskType)OS_MKOBJID(OBJECT_TASK, 12U)) /* Task ID */
extern void FuncOsTask_BSW_Mem_Process(void); /* Task entry point */
#define OsTask_BSW_Init ((TaskType)OS_MKOBJID(OBJECT_TASK, 13U)) /* Task ID */
extern void FuncOsTask_BSW_Init(void); /* Task entry point */
#define OsTask_BSW_System_Idle ((TaskType)OS_MKOBJID(OBJECT_TASK, 14U)) /* Task ID */
extern void FuncOsTask_BSW_System_Idle(void); /* Task entry point */

/* ISR functions */

/* ISRs definition */
#define OSISRAdc_EndGroupConvUnit0() OSISR2DISP(Adc_EndGroupConvUnit0) /* IrqChannel is EXTERNAL */
extern void OS_isr_Adc_EndGroupConvUnit0(void); /* irq: Adc_EndGroupConvUnit0; channel: EXTERNAL; category: 2 */
#define Adc_EndGroupConvUnit0LEVEL 1U      /* interrupt level of Adc_EndGroupConvUnit0 */
#define Adc_EndGroupConvUnit0PRIORITY 1U   /* priority of Adc_EndGroupConvUnit0 */
#define OSISRCan_IsrFCB_BO() OSISR2DISP(Can_IsrFCB_BO) /* IrqChannel is EXTERNAL */
extern void OS_isr_Can_IsrFCB_BO(void); /* irq: Can_IsrFCB_BO; channel: EXTERNAL; category: 2 */
#define Can_IsrFCB_BOLEVEL 1U              /* interrupt level of Can_IsrFCB_BO */
#define Can_IsrFCB_BOPRIORITY 1U           /* priority of Can_IsrFCB_BO */
#define OSISRCan_IsrFCB_MB_00_03() OSISR2DISP(Can_IsrFCB_MB_00_03) /* IrqChannel is EXTERNAL */
extern void OS_isr_Can_IsrFCB_MB_00_03(void); /* irq: Can_IsrFCB_MB_00_03; channel: EXTERNAL; category: 2 */
#define Can_IsrFCB_MB_00_03LEVEL 1U        /* interrupt level of Can_IsrFCB_MB_00_03 */
#define Can_IsrFCB_MB_00_03PRIORITY 1U     /* priority of Can_IsrFCB_MB_00_03 */
#define OSISRCan_IsrFCB_MB_04_07() OSISR2DISP(Can_IsrFCB_MB_04_07) /* IrqChannel is EXTERNAL */
extern void OS_isr_Can_IsrFCB_MB_04_07(void); /* irq: Can_IsrFCB_MB_04_07; channel: EXTERNAL; category: 2 */
#define Can_IsrFCB_MB_04_07LEVEL 1U        /* interrupt level of Can_IsrFCB_MB_04_07 */
#define Can_IsrFCB_MB_04_07PRIORITY 1U     /* priority of Can_IsrFCB_MB_04_07 */
#define OSISRCan_IsrFCB_MB_08_11() OSISR2DISP(Can_IsrFCB_MB_08_11) /* IrqChannel is EXTERNAL */
extern void OS_isr_Can_IsrFCB_MB_08_11(void); /* irq: Can_IsrFCB_MB_08_11; channel: EXTERNAL; category: 2 */
#define Can_IsrFCB_MB_08_11LEVEL 1U        /* interrupt level of Can_IsrFCB_MB_08_11 */
#define Can_IsrFCB_MB_08_11PRIORITY 1U     /* priority of Can_IsrFCB_MB_08_11 */
#define OSISRCan_IsrFCB_MB_12_15() OSISR2DISP(Can_IsrFCB_MB_12_15) /* IrqChannel is EXTERNAL */
extern void OS_isr_Can_IsrFCB_MB_12_15(void); /* irq: Can_IsrFCB_MB_12_15; channel: EXTERNAL; category: 2 */
#define Can_IsrFCB_MB_12_15LEVEL 1U        /* interrupt level of Can_IsrFCB_MB_12_15 */
#define Can_IsrFCB_MB_12_15PRIORITY 1U     /* priority of Can_IsrFCB_MB_12_15 */
#define OSISRCan_IsrFCB_MB_16_31() OSISR2DISP(Can_IsrFCB_MB_16_31) /* IrqChannel is EXTERNAL */
extern void OS_isr_Can_IsrFCB_MB_16_31(void); /* irq: Can_IsrFCB_MB_16_31; channel: EXTERNAL; category: 2 */
#define Can_IsrFCB_MB_16_31LEVEL 1U        /* interrupt level of Can_IsrFCB_MB_16_31 */
#define Can_IsrFCB_MB_16_31PRIORITY 1U     /* priority of Can_IsrFCB_MB_16_31 */
#define OSISRCan_IsrFCB_MB_32_63() OSISR2DISP(Can_IsrFCB_MB_32_63) /* IrqChannel is EXTERNAL */
extern void OS_isr_Can_IsrFCB_MB_32_63(void); /* irq: Can_IsrFCB_MB_32_63; channel: EXTERNAL; category: 2 */
#define Can_IsrFCB_MB_32_63LEVEL 1U        /* interrupt level of Can_IsrFCB_MB_32_63 */
#define Can_IsrFCB_MB_32_63PRIORITY 1U     /* priority of Can_IsrFCB_MB_32_63 */
#define OSISREMIOS_0_CH_2_CH_3_ISR() OSISR2DISP(EMIOS_0_CH_2_CH_3_ISR) /* IrqChannel is EXTERNAL */
extern void OS_isr_EMIOS_0_CH_2_CH_3_ISR(void); /* irq: EMIOS_0_CH_2_CH_3_ISR; channel: EXTERNAL; category: 2 */
#define EMIOS_0_CH_2_CH_3_ISRLEVEL 1U      /* interrupt level of EMIOS_0_CH_2_CH_3_ISR */
#define EMIOS_0_CH_2_CH_3_ISRPRIORITY 1U   /* priority of EMIOS_0_CH_2_CH_3_ISR */
#define OSISREMIOS_0_CH_6_CH_7_ISR() OSISR2DISP(EMIOS_0_CH_6_CH_7_ISR) /* IrqChannel is EXTERNAL */
extern void OS_isr_EMIOS_0_CH_6_CH_7_ISR(void); /* irq: EMIOS_0_CH_6_CH_7_ISR; channel: EXTERNAL; category: 2 */
#define EMIOS_0_CH_6_CH_7_ISRLEVEL 1U      /* interrupt level of EMIOS_0_CH_6_CH_7_ISR */
#define EMIOS_0_CH_6_CH_7_ISRPRIORITY 1U   /* priority of EMIOS_0_CH_6_CH_7_ISR */
#define OSISRGpt_PIT_TIMER_1_ISR() OSISR2DISP(Gpt_PIT_TIMER_1_ISR) /* IrqChannel is EXTERNAL */
extern void OS_isr_Gpt_PIT_TIMER_1_ISR(void); /* irq: Gpt_PIT_TIMER_1_ISR; channel: EXTERNAL; category: 2 */
#define Gpt_PIT_TIMER_1_ISRLEVEL 1U        /* interrupt level of Gpt_PIT_TIMER_1_ISR */
#define Gpt_PIT_TIMER_1_ISRPRIORITY 1U     /* priority of Gpt_PIT_TIMER_1_ISR */
#define OSISRGpt_PIT_TIMER_3_ISR() OSISR2DISP(Gpt_PIT_TIMER_3_ISR) /* IrqChannel is EXTERNAL */
extern void OS_isr_Gpt_PIT_TIMER_3_ISR(void); /* irq: Gpt_PIT_TIMER_3_ISR; channel: EXTERNAL; category: 2 */
#define Gpt_PIT_TIMER_3_ISRLEVEL 1U        /* interrupt level of Gpt_PIT_TIMER_3_ISR */
#define Gpt_PIT_TIMER_3_ISRPRIORITY 1U     /* priority of Gpt_PIT_TIMER_3_ISR */
#define OSISREMIOS_0_CH_4_CH_5_ISR() OSISR2DISP(EMIOS_0_CH_4_CH_5_ISR) /* IrqChannel is EXTERNAL */
extern void OS_isr_EMIOS_0_CH_4_CH_5_ISR(void); /* irq: EMIOS_0_CH_4_CH_5_ISR; channel: EXTERNAL; category: 2 */
#define EMIOS_0_CH_4_CH_5_ISRLEVEL 1U      /* interrupt level of EMIOS_0_CH_4_CH_5_ISR */
#define EMIOS_0_CH_4_CH_5_ISRPRIORITY 1U   /* priority of EMIOS_0_CH_4_CH_5_ISR */
#define Adc_EndGroupConvUnit0 ((ISRType)OS_MKOBJID(OBJECT_ISR, 0U)) /* ISR ID */
#define Can_IsrFCB_BO ((ISRType)OS_MKOBJID(OBJECT_ISR, 1U)) /* ISR ID */
#define Can_IsrFCB_MB_00_03 ((ISRType)OS_MKOBJID(OBJECT_ISR, 2U)) /* ISR ID */
#define Can_IsrFCB_MB_04_07 ((ISRType)OS_MKOBJID(OBJECT_ISR, 3U)) /* ISR ID */
#define Can_IsrFCB_MB_08_11 ((ISRType)OS_MKOBJID(OBJECT_ISR, 4U)) /* ISR ID */
#define Can_IsrFCB_MB_12_15 ((ISRType)OS_MKOBJID(OBJECT_ISR, 5U)) /* ISR ID */
#define Can_IsrFCB_MB_16_31 ((ISRType)OS_MKOBJID(OBJECT_ISR, 6U)) /* ISR ID */
#define Can_IsrFCB_MB_32_63 ((ISRType)OS_MKOBJID(OBJECT_ISR, 7U)) /* ISR ID */
#define EMIOS_0_CH_2_CH_3_ISR ((ISRType)OS_MKOBJID(OBJECT_ISR, 8U)) /* ISR ID */
#define EMIOS_0_CH_6_CH_7_ISR ((ISRType)OS_MKOBJID(OBJECT_ISR, 9U)) /* ISR ID */
#define Gpt_PIT_TIMER_1_ISR ((ISRType)OS_MKOBJID(OBJECT_ISR, 10U)) /* ISR ID */
#define Gpt_PIT_TIMER_3_ISR ((ISRType)OS_MKOBJID(OBJECT_ISR, 11U)) /* ISR ID */
#define EMIOS_0_CH_4_CH_5_ISR ((ISRType)OS_MKOBJID(OBJECT_ISR, 12U)) /* ISR ID */

/* ISR1 id */

/* Resources definitions */
#define OsResource_Sleep ((ResourceType)OS_MKOBJID(OBJECT_RESOURCE, 0U)) /* Resource ID */
#define RES_ACCESS_PROTECTION ((ResourceType)OS_MKOBJID(OBJECT_RESOURCE, 1U)) /* Resource ID */
#define RES_SCHEDULER ((ResourceType)OS_MKOBJID(OBJECT_RESOURCE, 2U)) /* Resource ID */

/* Events definition */

/* Alarms identification */
#define OsAlarm_BSW_5ms_Mem ((AlarmType)OS_MKOBJID(OBJECT_ALARM, 0U)) /* Alarm ID */
#define OsAlarm_BSW_5ms_Com ((AlarmType)OS_MKOBJID(OBJECT_ALARM, 1U)) /* Alarm ID */
#define OsAlarm_BSW_10ms ((AlarmType)OS_MKOBJID(OBJECT_ALARM, 2U)) /* Alarm ID */
#define OsAlarm_ASW_10ms ((AlarmType)OS_MKOBJID(OBJECT_ALARM, 3U)) /* Alarm ID */
#define OsAlarm_ASW_100ms ((AlarmType)OS_MKOBJID(OBJECT_ALARM, 4U)) /* Alarm ID */

/* Counters identification */
#define OsCounter_0 ((CounterType)OS_MKOBJID(OBJECT_COUNTER, 0U)) /* Counter ID */
#define OSMINCYCLE_OsCounter_0 ((TickType)0x1U) /* OsCounter_0 */
#define OSMAXALLOWEDVALUE_OsCounter_0 ((TickType)0xffffffffU) /* OsCounter_0 */
#define OSTICKSPERBASE_OsCounter_0 1UL     /* OsCounter_0 */
#define OS_TICKS2NS_OsCounter_0(ticks) (PhysicalTimeType)(ticks*1000U) /*  */
#define OS_TICKS2US_OsCounter_0(ticks) (PhysicalTimeType)((OSQWORD)(ticks)*1000ULL/1000UL) /*  */
#define OS_TICKS2MS_OsCounter_0(ticks) (PhysicalTimeType)((OSQWORD)(ticks)*1000ULL/1000000UL) /*  */
#define OS_TICKS2SEC_OsCounter_0(ticks) (PhysicalTimeType)((OSQWORD)(ticks)*1000ULL/1000000000UL) /*  */
#define OSMINCYCLE ((TickType)0x1U)        /* SysTimer */
#define OSMAXALLOWEDVALUE ((TickType)0xffffffffU) /* SysTimer */
#define OSTICKSPERBASE 1UL                 /* SysTimer */
#define OSTICKDURATION 1000UL              /* SysTimer */

/* Messages identification */

/* Flags identification */

/* Message callback prototypes */

/* scheduletable */
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#define APP_STOP_SEC_CODE
#include    "Os_memmap.h"

#endif /* OSCFG_H */

