/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: WdgM_Ram.h                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR WDGM                                                  **
**                                                                            **
**  PURPOSE   : Watchdog Manager RAM variable declarations                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By           Description                           **
********************************************************************************
** 1.0.10    13-Nov-2015   Sinil        1. MemSection and MemClass changed    **
** 1.0.9     23-Apr-2015   Sinil        1. Fix Misra-c rule violations        **
** 1.0.8     03-Nov-2014   Sinil        1. Change WdgM_GbaAlreadyUpdated to   **
**                                      WdgM_GaaAlreadyUpdated                **
** 1.0.7     21-Oct-2014   Sinil        1. Remove WdgM_GaaFoundErrIntLogical  **
**                                      and add WdgM_GaaErrorInfo             **
**                                      2. Change including                   **
**                                      3. Rearrange items                    **
** 1.0.6     07-Oct-2014   Sinil        1. Add precompile condition for       **
**                                      WdgM_GbaAlreadyUpdated                **
**                                      2. Fix performing internal logical    **
**                                      supervision                           **
** 1.0.5     18-Jun-2013   Sinil        CR 138 : Remove size of array for     **
**                                        making library                      **
** 1.0.4     10-Jun-2013   Sinil        CR 127 : Add an global array for      **
**                                        making library                      **
** 1.0.3     28-May-2013   Sinil        change from                           **
**                                        WDGM_START_SEC_VAR_CLEARED_16,      **
**                                        WDGM_STOP_SEC_VAR_CLEARED_16        **
**                                        to                                  **
**                                        WDGM_START_SEC_VAR_CLEARED_32,      **
**                                        WDGM_STOP_SEC_VAR_CLEARED_32        **
**                                        for WdgM_GulFreeRunningCounter      **
** 1.0.0     01-Jan-2013   Autron       Initial version                       **
*******************************************************************************/

#ifndef WDGM_RAM_H
#define WDGM_RAM_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Rte_Type.h"
#include "WdgM_Cfg.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global variable to store the current mode of watchdog manager */
extern VAR(WdgM_ModeType, WDGM_VAR_POWER_ON_INIT) WdgM_GddCurrentMode;
#define WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
extern VAR(uint8, WDGM_VAR_POWER_ON_INIT) WdgM_GaaSEStatus[WDGM_TOTAL_SES];
#define WDGM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global variable to store the overall supervision status */
extern VAR(WdgM_GlobalStatusType, WDGM_VAR_POWER_ON_INIT)
  WdgM_GddGlobalSupervisionStatus;
#define WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
/* Global variable to store first expired SE id status of WdgM */
extern VAR(boolean, WDGM_VAR_POWER_ON_INIT) WdgM_GblFirstExpSEIDStatus;
#define WDGM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#define WDGM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"
/* Global variable to store the SEID of first expired SE */
extern VAR(WdgM_SupervisedEntityIdType, WDGM_VAR_NOINIT)
  WdgM_GddFirstExpiredSEID;
#define WDGM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"
/* Global variable to store the inverse SEID value of first expired SE */
extern VAR(WdgM_SupervisedEntityIdType, WDGM_VAR_NOINIT)
  WdgM_GddInvFirstExpiredSEID;
#define WDGM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global variable to store the amount of expired supervision cycles for how
  long the blocking of watchdog triggering shall be postponed in a given mode */
extern VAR(WdgM_ExpSupCycleTolType, WDGM_VAR_POWER_ON_INIT)
  WdgM_GddExpSupervisionCycleCounter;
#define WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#if(WDGM_ENABLE_ALIVE_SUPERVISION == STD_ON)
#define WDGM_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
/* Global variable to store the WdgM_MainFunction call count */
extern VAR(uint32, WDGM_VAR_POWER_ON_INIT) WdgM_GulFreeRunningCounter;
#define WDGM_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

#define WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global array to store the failed cycles of each supervised entity */
extern VAR(WdgM_FailureTolType, WDGM_VAR_POWER_ON_INIT)
  WdgM_GddFailedRefCycleCounter[WDGM_TOTAL_SES];
#define WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
/* Global variable to store error occurrence in performing alive supervisions */
extern VAR(boolean, WDGM_VAR_POWER_ON_INIT)
  WdgM_GaaAlreadyUpdated[WDGM_TOTAL_SES];
#define WDGM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
#endif

#if(WDGM_DEV_ERROR_DETECT == STD_ON)
#define WDGM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
/* Global variable to store Initialization status of WdgM */
extern VAR(boolean, WDGM_VAR_POWER_ON_INIT) WdgM_GblModuleInitStatus;
#define WDGM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
#endif

#if(WDGM_ERROR_INFO_API == STD_ON)
#define WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
extern VAR(WdgM_ErrorInfoType, WDGM_VAR_POWER_ON_INIT)
  WdgM_GaaErrorInfo[WDGM_TOTAL_SES];
#define WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#endif /* WDGM_RAM_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
