/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IoHwAb_IOManager.h                                            **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IOHWAB                                                **
**                                                                            **
**  PURPOSE   : C header for IO Manager                                       **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By         Description                             **
********************************************************************************
** 1.0.7     06-Jul-2017   Jongyoung  #9107                                   **
** 1.0.6     31-Mar-2017   Jongyoung  #7890                                   **
** 1.0.5     05-Mar-2017   Jongyoung  #7764                                   **
** 1.0.4     05-Jun-2015   Jongyoung  1.Misra-C coding Rule adaption          **
**                                      Duplicated Extern declaration (8.8)   **
** 1.0.3     27-Sep-2014   Jongyoung  Polyspace result Adaption               **
** 1.0.2     18-Sep-2014   Sinil      1. Remove unnecessary include           **
** 1.0.1     28-Apr-2014   Sinil         Task ID : 853                        **
**                                       Update including os header with      **
**                                       mcal info                            **
** 1.0.0     07-Mar-2014   Sinil      Initial version                         **
*******************************************************************************/
#ifndef IOHWAB_IOMANAGER_H
#define IOHWAB_IOMANAGER_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IoHwAb.h"
#include "Os.h"


#if (IOHWAB_USE_IO_MAN_FASTTIMER == STD_ON)
extern FUNC(Std_ReturnType, COSVAB_CODE)CoSvAb_FastTimerStart(CoSvAb_TimerType Timer_name, CoSvAb_FastTimerDelay Delay);
#endif /* (IOHWAB_USE_IO_MAN_FASTTIMER == STD_ON) */

#if (IOHWAB_USE_PM_MODULE == STD_ON)
extern FUNC(Std_ReturnType, Pm_CODE) Pm_GetPowerMode(OUT P2VAR(Pm_PowerModeType, AUTOMATIC, RTE_APPL_DATA) mode);
#endif /* (IOHWAB_USE_PM_MODULE == STD_ON) */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/*polyspace:begin<MISRA-C:8.8:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #7283)*/

#if (IOHWAB_USE_IO_MAN == STD_ON)
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_IOMInit(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_IOMDeInit(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_IOMDigInInit(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAB_IOMDigInSample(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_IOMAnaInAcqEnd(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_IOML2H(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_IOMH2L(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_IOMInputsLP(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_IOMOutputsLP(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_IOMOnTimer(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_IOMDelayTicks(uint32 ticks);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern IOHWAB_IOM_TASK_FG2_FUNC;
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern IOHWAB_IOM_TASK_FG1_FUNC;
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"
#endif /* (IOHWAB_USE_IO_MAN == STD_ON) */
/*polyspace:end<MISRA-C:8.8:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #7283)*/
#endif /* IOHWAB_IOMANAGER_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
