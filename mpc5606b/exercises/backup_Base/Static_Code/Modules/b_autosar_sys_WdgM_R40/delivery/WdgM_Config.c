/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: WdgM_Config.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR WDGM                                                  **
**                                                                            **
**  PURPOSE   : Watchdog Manager const variable definitions for               **
**              making a library                                              **
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
** 1.0.10    23-Apr-2015   Sinil        1. Fix Misra-c rule violations        **
** 1.0.9     27-Jan-2015   Sinil        1. Remove unnecessary comment for     **
**                                      polyspace                             **
** 1.0.8     12-Nov-2014   Sinil        1. Comment for polyspace              **
** 1.0.7     04-Nov-2014   Sinil        1. Remove WdgM_GddOsCounter           **
**                                      2. Remove WdgM_GusMaxAliveSupervisions**
** 1.0.6     21-Oct-2014   Sinil        1. Rearrange items                    **
** 1.0.5     07-Oct-2014   Sinil        1. Add WdgM_GusDeInitTimeout          **
**                                      2. Add precompile condition for       **
**                                      WdgM_GulMaxAliveSupervisionRefCycle   **
**                                      and WdgM_GusMaxAliveSupervisions      **
** 1.0.4     30-Sep-2014   Sinil        1. Add WdgM_GddOsCounter              **
** 1.0.3     02-Sep-2014   Sinil        Add WdgM_GusMaxAliveSupervisions      **
** 1.0.2     03-Jan-2014   Sinil        TaskID:809 Variable name and type     **
**                                       changed                              **
**                                      C style comment adjusted              **
** 1.0.1     16-Dec-2013   Sinil        Wdgm_Dem_Cfg.h was included and       **
**                                        related macro's adjusted            **
** 1.0.0     05-Jun-2013   Sinil        Initial version                       **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "WdgM_Config.h"

/*******************************************************************************
**                       Global Data                                          **
*******************************************************************************/
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* WDGM_INIT_MODE */
CONST(WdgM_ModeType, WDGM_CONST) WdgM_GddInitMode = WDGM_INIT_MODE;
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* WDGM_TOTAL_SES */
CONST(WdgM_SupervisedEntityIndexType, WDGM_CONST) WdgM_GddTotalSEs
  = WDGM_TOTAL_SES;
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* WDGM_TOTAL_MODES */
CONST(WdgM_ModeType, WDGM_CONST) WdgM_GddTotalModes = WDGM_TOTAL_MODES;
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_16
#include "MemMap.h"
/* WDGM_DEINIT_TIMEOUT */
CONST(uint16, WDGM_CONST) WdgM_GusDeInitTimeout = WDGM_DEINIT_TIMEOUT;
#define WDGM_STOP_SEC_CONST_16
#include "MemMap.h"

#if(WDGM_DEFENSIVE_BEHAVIOR == STD_ON)
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* WDGM_TOTAL_SET_MODE_API_CALLERS */
CONST(uint8, WDGM_CONST) WdgM_GucTotalSetModeApiCallers
  = WDGM_TOTAL_SET_MODE_API_CALLERS;
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(WDGM_ENABLE_ALIVE_SUPERVISION == STD_ON)
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* WDGM_MAX_ALIVE_SUPERVISION_REF_CYCLE */
CONST(uint32, WDGM_CONST) WdgM_GulMaxAliveSupervisionRefCycle
  = WDGM_MAX_ALIVE_SUPERVISION_REF_CYCLE;
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(WDGM_DEM_ERROR_REPORT == STD_ON)
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* WDGM_E_IMPROPER_CALLER */
CONST(Dem_EventIdType, WDGM_CONST) WdgM_GddEImproperCaller
  = WDGM_E_IMPROPER_CALLER;
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* WDGM_E_MONITORING */
CONST(Dem_EventIdType, WDGM_CONST) WdgM_GddEMonitoring = WDGM_E_MONITORING;
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* WDGM_E_SET_MODE */
CONST(Dem_EventIdType, WDGM_CONST) WdgM_GddESetMode = WDGM_E_SET_MODE;
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
