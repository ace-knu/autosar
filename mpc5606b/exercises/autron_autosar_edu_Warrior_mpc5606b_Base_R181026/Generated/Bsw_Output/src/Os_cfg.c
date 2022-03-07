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
*       Description: Configuration Data file
*
*       Note: The implementation that was used is: AUTOSAR_MPC5600
*       System Generator for AUTOSAR OS/MPC5600 - Version: 4.0 Build 4.0.69
*
********************************************************************************/
#include    <Os.h>
#include    <Os_internal_config.h>
#define OSTEXT_START_SEC_CODE
#include    "Os_sections.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

const    OSAPP   OsAppCfgTable[OSNAPPS] = 
{
    {
        0xfffe0000U, /* all tasks of the application, priority-wise */
    }, /* OsApplication0 */
};

/* Task Configuration table */
const    OSTSK   OsTaskCfgTable[OSNTSKS] = 
{
    {
        1U, /* Application identification mask value */
        (OSTASKENTRY) &FuncOsTask_BSW_ComMModeRequest, /* entry point of task */
        0U, /* running prio (internal resource) */
        0U, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT */
        0U, /* task id (task number in the task table) */
        0U, /* application identification value */
    }, /* OsTask_BSW_ComMModeRequest */
    {
        1U, /* Application identification mask value */
        (OSTASKENTRY) &FuncOsTask_BSW_AppModeRequest, /* entry point of task */
        1U, /* running prio (internal resource) */
        0U, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT */
        1U, /* task id (task number in the task table) */
        0U, /* application identification value */
    }, /* OsTask_BSW_AppModeRequest */
    {
        1U, /* Application identification mask value */
        (OSTASKENTRY) &FuncOsTask_BSW_FG2_IOManager, /* entry point of task */
        2U, /* running prio (internal resource) */
        0U, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT */
        2U, /* task id (task number in the task table) */
        0U, /* application identification value */
    }, /* OsTask_BSW_FG2_IOManager */
    {
        1U, /* Application identification mask value */
        (OSTASKENTRY) &FuncOsTask_BSW_FG2_WdgMAPI, /* entry point of task */
        2U, /* running prio (internal resource) */
        0U, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT */
        3U, /* task id (task number in the task table) */
        0U, /* application identification value */
    }, /* OsTask_BSW_FG2_WdgMAPI */
    {
        1U, /* Application identification mask value */
        (OSTASKENTRY) &FuncOsTask_ASW_FG2_WdgMTestMode, /* entry point of task */
        2U, /* running prio (internal resource) */
        0U, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT */
        4U, /* task id (task number in the task table) */
        0U, /* application identification value */
    }, /* OsTask_ASW_FG2_WdgMTestMode */
    {
        1U, /* Application identification mask value */
        (OSTASKENTRY) &FuncOsTask_BSW_FG1_5ms_Mem, /* entry point of task */
        5U, /* running prio (internal resource) */
        0U, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT */
        5U, /* task id (task number in the task table) */
        0U, /* application identification value */
    }, /* OsTask_BSW_FG1_5ms_Mem */
    {
        1U, /* Application identification mask value */
        (OSTASKENTRY) &FuncOsTask_BSW_FG1_5ms_Com, /* entry point of task */
        5U, /* running prio (internal resource) */
        0U, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT */
        6U, /* task id (task number in the task table) */
        0U, /* application identification value */
    }, /* OsTask_BSW_FG1_5ms_Com */
    {
        1U, /* Application identification mask value */
        (OSTASKENTRY) &FuncOsTask_BSW_FG1_IOManager, /* entry point of task */
        5U, /* running prio (internal resource) */
        0U, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT */
        7U, /* task id (task number in the task table) */
        0U, /* application identification value */
    }, /* OsTask_BSW_FG1_IOManager */
    {
        1U, /* Application identification mask value */
        (OSTASKENTRY) &FuncOsTask_BSW_FG1_10ms, /* entry point of task */
        5U, /* running prio (internal resource) */
        0U, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT */
        8U, /* task id (task number in the task table) */
        0U, /* application identification value */
    }, /* OsTask_BSW_FG1_10ms */
    {
        1U, /* Application identification mask value */
        (OSTASKENTRY) &FuncOsTask_ASW_FG1_10ms, /* entry point of task */
        5U, /* running prio (internal resource) */
        0U, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT */
        9U, /* task id (task number in the task table) */
        0U, /* application identification value */
    }, /* OsTask_ASW_FG1_10ms */
    {
        1U, /* Application identification mask value */
        (OSTASKENTRY) &FuncOsTask_ASW_TestModeManager, /* entry point of task */
        10U, /* running prio (internal resource) */
        0U, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT */
        10U, /* task id (task number in the task table) */
        0U, /* application identification value */
    }, /* OsTask_ASW_TestModeManager */
    {
        1U, /* Application identification mask value */
        (OSTASKENTRY) &FuncOsTask_ASW_FG1_100ms, /* entry point of task */
        5U, /* running prio (internal resource) */
        0U, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT */
        11U, /* task id (task number in the task table) */
        0U, /* application identification value */
    }, /* OsTask_ASW_FG1_100ms */
    {
        1U, /* Application identification mask value */
        (OSTASKENTRY) &FuncOsTask_BSW_Mem_Process, /* entry point of task */
        12U, /* running prio (internal resource) */
        0U, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT */
        12U, /* task id (task number in the task table) */
        0U, /* application identification value */
    }, /* OsTask_BSW_Mem_Process */
    {
        1U, /* Application identification mask value */
        (OSTASKENTRY) &FuncOsTask_BSW_Init, /* entry point of task */
        13U, /* running prio (internal resource) */
        0U | OSTSKACTIVATE, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT */
        13U, /* task id (task number in the task table) */
        0U, /* application identification value */
    }, /* OsTask_BSW_Init */
    {
        1U, /* Application identification mask value */
        (OSTASKENTRY) &FuncOsTask_BSW_System_Idle, /* entry point of task */
        14U, /* running prio (internal resource) */
        0U | OSTSKACTIVATE, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT */
        14U, /* task id (task number in the task table) */
        0U, /* application identification value */
    }, /* OsTask_BSW_System_Idle */
};
const    OSISRCFGTYPE   OsIsrCfg[OSNISR + 1] =  /*Interrupts config table*/
{
    {
        OS_isr_Adc_EndGroupConvUnit0, /* actual ISR function */
        OSTRUSTEDISR2, /* ISR type */
        62U,  
        1U, /* ISR PRIORITY */
        0U, /* application identification value */
    }, /* Adc_EndGroupConvUnit0 */
    {
        OS_isr_Can_IsrFCB_BO, /* actual ISR function */
        OSTRUSTEDISR2, /* ISR type */
        86U,  
        1U, /* ISR PRIORITY */
        0U, /* application identification value */
    }, /* Can_IsrFCB_BO */
    {
        OS_isr_Can_IsrFCB_MB_00_03, /* actual ISR function */
        OSTRUSTEDISR2, /* ISR type */
        88U,  
        1U, /* ISR PRIORITY */
        0U, /* application identification value */
    }, /* Can_IsrFCB_MB_00_03 */
    {
        OS_isr_Can_IsrFCB_MB_04_07, /* actual ISR function */
        OSTRUSTEDISR2, /* ISR type */
        89U,  
        1U, /* ISR PRIORITY */
        0U, /* application identification value */
    }, /* Can_IsrFCB_MB_04_07 */
    {
        OS_isr_Can_IsrFCB_MB_08_11, /* actual ISR function */
        OSTRUSTEDISR2, /* ISR type */
        90U,  
        1U, /* ISR PRIORITY */
        0U, /* application identification value */
    }, /* Can_IsrFCB_MB_08_11 */
    {
        OS_isr_Can_IsrFCB_MB_12_15, /* actual ISR function */
        OSTRUSTEDISR2, /* ISR type */
        91U,  
        1U, /* ISR PRIORITY */
        0U, /* application identification value */
    }, /* Can_IsrFCB_MB_12_15 */
    {
        OS_isr_Can_IsrFCB_MB_16_31, /* actual ISR function */
        OSTRUSTEDISR2, /* ISR type */
        92U,  
        1U, /* ISR PRIORITY */
        0U, /* application identification value */
    }, /* Can_IsrFCB_MB_16_31 */
    {
        OS_isr_Can_IsrFCB_MB_32_63, /* actual ISR function */
        OSTRUSTEDISR2, /* ISR type */
        93U,  
        1U, /* ISR PRIORITY */
        0U, /* application identification value */
    }, /* Can_IsrFCB_MB_32_63 */
    {
        OS_isr_EMIOS_0_CH_2_CH_3_ISR, /* actual ISR function */
        OSTRUSTEDISR2, /* ISR type */
        142U,  
        1U, /* ISR PRIORITY */
        0U, /* application identification value */
    }, /* EMIOS_0_CH_2_CH_3_ISR */
    {
        OS_isr_EMIOS_0_CH_6_CH_7_ISR, /* actual ISR function */
        OSTRUSTEDISR2, /* ISR type */
        144U,  
        1U, /* ISR PRIORITY */
        0U, /* application identification value */
    }, /* EMIOS_0_CH_6_CH_7_ISR */
    {
        OS_isr_Gpt_PIT_TIMER_1_ISR, /* actual ISR function */
        OSTRUSTEDISR2, /* ISR type */
        60U,  
        1U, /* ISR PRIORITY */
        0U, /* application identification value */
    }, /* Gpt_PIT_TIMER_1_ISR */
    {
        OS_isr_Gpt_PIT_TIMER_3_ISR, /* actual ISR function */
        OSTRUSTEDISR2, /* ISR type */
        127U,  
        1U, /* ISR PRIORITY */
        0U, /* application identification value */
    }, /* Gpt_PIT_TIMER_3_ISR */
    {
        OS_isr_EMIOS_0_CH_4_CH_5_ISR, /* actual ISR function */
        OSTRUSTEDISR2, /* ISR type */
        143U,  
        1U, /* ISR PRIORITY */
        0U, /* application identification value */
    }, /* EMIOS_0_CH_4_CH_5_ISR */
    {
        OSISRSystemTimer, /* actual ISR function */
        OSSYSINTERRUPT, /* ISR type */
        30U, /* index in OsIsr */
        15U, /* Interrupt priority */
        OSINVALID_OSAPPLICATION, /* appId */
    }, /* SysTimer */
    {
        OSISRException, /* actual ISR function */
        OSSYSINTERRUPT, /* ISR type */
        OSISREXCEPTIONIDX, /* Index of interrupt */
        OSISREXCEPTIONPRIO, /* Interrupt priority */
        OSINVALID_OSAPPLICATION, /* appId */
    }, /* Exception */
};
const    OSRESCFG   OsResCfg[OSNRESS + OSNISRRESS] = 
{
    { 0U, /* Application identification mask value */14U, /* Resource priority for task resources */ }, /* OsResource_Sleep */
    { 0U, /* Application identification mask value */-1, /* Resource priority for task resources */ }, /* RES_ACCESS_PROTECTION */
    { 0xFFU, /* Application identification mask value */0U, /* Resource priority for task resources */ }, /* RES_SCHEDULER */
};

/* Alarms table */
const    OSALM   OsAlarmsCfg[OSNUSERALMS] = 
{
    {
        1U, /* appMask */
        5U, /* task to notify */
        0U, /* attached Counter ID */
        0U, /* application identification value */
    }, /* OsAlarm_BSW_5ms_Mem */
    {
        1U, /* appMask */
        6U, /* task to notify */
        0U, /* attached Counter ID */
        0U, /* application identification value */
    }, /* OsAlarm_BSW_5ms_Com */
    {
        1U, /* appMask */
        8U, /* task to notify */
        0U, /* attached Counter ID */
        0U, /* application identification value */
    }, /* OsAlarm_BSW_10ms */
    {
        1U, /* appMask */
        9U, /* task to notify */
        0U, /* attached Counter ID */
        0U, /* application identification value */
    }, /* OsAlarm_ASW_10ms */
    {
        1U, /* appMask */
        11U, /* task to notify */
        0U, /* attached Counter ID */
        0U, /* application identification value */
    }, /* OsAlarm_ASW_100ms */
};

/* Counter table */
const    OSCTR   OsCountersCfg[OSNCTRS] = 
{
    {
        1U, /* appMask */
        0xffffffffU, /* maximum allowed counter value */
        1U, /* conversion constant */
        0x1U, /* minimum period value for alarm */
        0U, /* application identification value */
    }, /* OsCounter_0 */
};
const    OSSHORT   OsIsr[OSNINTC] =  /* OSNINTERRUPTS external interrupt handlers table */
{
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    13U, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    10U, OSNISR, 0U, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 1U, OSNISR, 2U, 3U, 
    4U, 5U, 6U, 7U, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 11U, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, 8U, 12U, 9U, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, 
    OSNISR, OSNISR, OSNISR, OSNISR, 
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#define OSTEXT_STOP_SEC_CODE
#include    "Os_sections.h"

