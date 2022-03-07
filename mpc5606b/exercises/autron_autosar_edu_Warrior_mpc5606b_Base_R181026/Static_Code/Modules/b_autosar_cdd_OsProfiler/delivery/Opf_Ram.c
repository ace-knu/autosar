/*******************************************************************************
**                                                                            **
**  (C) 2016-2017 HYUNDAI AUTRON Co., Ltd.                                    **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Opf_Ram.c                                                     **
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
**                      Include Section                                       **
*******************************************************************************/
#include "Opf_Ram.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#if (OPF_PROFILE_ENABLED == STD_ON)

#define OPF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

VAR(Tdd_Opf_GaaTaskCache, OS_VAR) Opf_GaaTaskCache[OPF_MAX_TASK_ID];
VAR(Tdd_Opf_TaskInfo, OS_VAR) Opf_GaaTaskInfo[OPF_PROFILE_TASK_COUNT];
VAR(Tdd_Opf_EventQ, OS_VAR) Opf_GddEventQ;
VAR(Tdd_Opf_ProfileEventQ, OS_VAR) Opf_GddProfileEventQ;
VAR(Tdd_Opf_OsProfiler, OS_VAR) Opf_GddOsProfiler;

#define OPF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define OPF_START_SEC_VAR_CLEARED_32
#include "MemMap.h"

VAR(uint32, OS_VAR) Opf_GulIndexTicks;
VAR(OpfSystimeTickType, OS_VAR) Opf_GddSystimeTick;
VAR(OpfTimeSpanType, OS_VAR) Opf_GddSystimeSpan;

#define OPF_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

#define OPF_START_SEC_CONST_8
#include "MemMap.h"

#if (OPF_PROFILE_ISR == STD_ON)
CONST(uint8, OS_CONST) Opf_Profile_Isr = STD_ON;
#else
CONST(uint8, OS_CONST) Opf_Profile_Isr = STD_OFF;
#endif
#if (OPF_PROFILE_TIME_INDEX == STD_ON)
CONST(uint8, OS_CONST) Opf_Profile_Time_Index = STD_ON;
#else
CONST(uint8, OS_CONST) Opf_Profile_Time_Index = STD_OFF;
#endif
CONST(uint8, OS_CONST) Opf_Max_Task_Id = OPF_MAX_TASK_ID;
CONST(uint8, OS_CONST) Opf_Xosc_Clock = OPF_XOSC_CLOCK;
#if (OPF_TARGET_OS == OPF_FREESCALE_MPC560XB)
CONST(uint8, OS_CONST) Opf_OSNTSKS = OSNTSKS;
#endif

#define OPF_STOP_SEC_CONST_8
#include "MemMap.h"

#define OPF_START_SEC_CONST_32
#include "MemMap.h"

CONST(OpfEventQueueSizeType, OS_CONST) Opf_Event_Queue_Length =
                                                         OPF_EVENT_QUEUE_LENGTH;
CONST(uint32, OS_CONST) Opf_Profile_Task_Count = OPF_PROFILE_TASK_COUNT;

#if (OPF_PROFILE_TIME_INDEX == STD_ON)
CONST(uint32, OS_CONST) Opf_Time_Index_Usec = OPF_TIME_INDEX_USEC;
#else
CONST(uint32, OS_CONST) Opf_Time_Index_Usec = OPF_ZERO;
#endif

CONST(uint32, OS_CONST) Sizeof_Tdd_Opf_Event = sizeof(Tdd_Opf_Event);
CONST(uint32, OS_CONST) Sizeof_Tdd_Opf_EventQ = sizeof(Tdd_Opf_EventQ);
CONST(uint32, OS_CONST) Sizeof_Tdd_Opf_ProfileEventQ =
                                                  sizeof(Tdd_Opf_ProfileEventQ);
CONST(uint32, OS_CONST) Sizeof_Tdd_Opf_GaaTaskCache =
                                                   sizeof(Tdd_Opf_GaaTaskCache);
CONST(uint32, OS_CONST) Sizeof_Tdd_Opf_TaskInfo = sizeof(Tdd_Opf_TaskInfo);

#define OPF_STOP_SEC_CONST_32
#include "MemMap.h"

#endif /* #if (OPF_PROFILE_ENABLED == STD_ON) */
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
