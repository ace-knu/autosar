/*******************************************************************************
**                                                                            **
**  (C) 2016-2017 HYUNDAI AUTRON Co., Ltd.                                    **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Opf_Ram.h                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : OS Profiler                                                   **
**                                                                            **
**  PURPOSE   : Ram Data for OS Profiler                                      **
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
** 1.1.2     22-Aug-2017    MJ.Woo        Redmine #6959                       **
** 1.1.0     24-Nov-2016    SH.Yoo        Redmine #6849, #6755                **
** 1.0.0     14-Jul-2016    SH.Yoo        Redmine #4024                       **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C:8.12:Not a defect:Justify with annotations> External linkage with array size makes error because of compiler optimization  */

#ifndef OPF_RAM_H
#define OPF_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Opf_Types.h"
#include "Opf_Cfg.h"
#if (OPF_TARGET_OS == OPF_FREESCALE_MPC560XB)
#include "Os_prop.h"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
extern VAR(Tdd_Opf_EventQ, OS_VAR) Opf_GddEventQ;
extern VAR(Tdd_Opf_ProfileEventQ, OS_VAR) Opf_GddProfileEventQ;
extern VAR(Tdd_Opf_GaaTaskCache, OS_VAR) Opf_GaaTaskCache[];
extern VAR(Tdd_Opf_TaskInfo, OS_VAR) Opf_GaaTaskInfo[];
extern VAR(Tdd_Opf_OsProfiler, OS_VAR) Opf_GddOsProfiler;
extern VAR(uint32, OS_VAR) Opf_GulIndexTicks;
extern VAR(OpfSystimeTickType, OS_VAR) Opf_GddSystimeTick;
extern VAR(OpfTimeSpanType, OS_VAR) Opf_GddSystimeSpan;

extern CONST(uint8, OS_CONST) Opf_Profile_Isr;
extern CONST(uint8, OS_CONST) Opf_Profile_Time_Index;
extern CONST(uint8, OS_CONST) Opf_Max_Task_Id;
extern CONST(uint8, OS_CONST) Opf_Xosc_Clock;
#if (OPF_TARGET_OS == OPF_FREESCALE_MPC560XB)
extern CONST(uint8, OS_CONST) Opf_OSNTSKS;
#endif

extern CONST(OpfEventQueueSizeType, OS_CONST) Opf_Event_Queue_Length;
extern CONST(uint32, OS_CONST) Opf_Profile_Task_Count;
extern CONST(uint32, OS_CONST) Opf_Time_Index_Usec;

extern CONST(uint32, OS_CONST) Sizeof_Tdd_Opf_Event;
extern CONST(uint32, OS_CONST) Sizeof_Tdd_Opf_EventQ;
extern CONST(uint32, OS_CONST) Sizeof_Tdd_Opf_ProfileEventQ;
extern CONST(uint32, OS_CONST) Sizeof_Tdd_Opf_GaaTaskCache;
extern CONST(uint32, OS_CONST) Sizeof_Tdd_Opf_TaskInfo;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* OPF_RAM_H */

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                  **
*******************************************************************************/
/* polyspace:end<MISRA-C:8.12:Not a defect:Justify with annotations> External linkage with array size makes error because of compiler optimization  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
