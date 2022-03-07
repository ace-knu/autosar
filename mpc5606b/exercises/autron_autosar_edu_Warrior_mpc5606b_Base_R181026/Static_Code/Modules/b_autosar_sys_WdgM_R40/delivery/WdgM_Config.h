/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: WdgM_Config.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR WDGM                                                  **
**                                                                            **
**  PURPOSE   : Watchdog Manager const variable declarations for              **
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
** 1.0.7     04-Nov-2014   Sinil        1. Remove WdgM_GddOsCounter           **
**                                      2. Remove WdgM_GusMaxAliveSupervisions**
** 1.0.6     21-Oct-2014   Sinil        1. Rearrange items                    **
**                                      2. Change including                   **
** 1.0.5     07-Oct-2014   Sinil        1. Add WdgM_GusDeInitTimeout          **
**                                      2. Add precompile condition for       **
**                                      WdgM_GulMaxAliveSupervisionRefCycle   **
**                                      and WdgM_GusMaxAliveSupervisions      **
** 1.0.4     30-Sep-2014   Sinil        1. Add WdgM_GddOsCounter              **
** 1.0.3     02-Sep-2014   Sinil        Add WdgM_GusMaxAliveSupervisions      **
** 1.0.2     03-Jan-2014   Sinil        TaskID:809                            **
**                                      1. Variable name and type changed     **
**                                      2. C style comment adjusted           **
** 1.0.1     16-Dec-2013   Sinil        Wdgm_Dem_Cfg.h was included and       **
**                                        related macro's adjusted            **
** 1.0.0     05-Jun-2013   Sinil        Initial version                       **
*******************************************************************************/

#ifndef WDGM_CONFIG_H
#define WDGM_CONFIG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Rte_Type.h"
#include "WdgM_Cfg.h"
#if(WDGM_DEM_ERROR_REPORT == STD_ON)
#include "WdgM_Dem_Cfg.h"              /* Dem Header file */
#endif
#if(WDGM_ENABLE_DEADLINE_SUPERVISION == STD_ON)
#include "Os.h"
#endif

/*******************************************************************************
**                       Global Data                                          **
*******************************************************************************/
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* WDGM_INIT_MODE */
extern CONST(WdgM_ModeType, WDGM_CONST) WdgM_GddInitMode;
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* WDGM_TOTAL_SES */
extern CONST(WdgM_SupervisedEntityIndexType, WDGM_CONST) WdgM_GddTotalSEs;
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* WDGM_TOTAL_MODES */
extern CONST(WdgM_ModeType, WDGM_CONST) WdgM_GddTotalModes;
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_16
#include "MemMap.h"
/* WDGM_DEINIT_TIMEOUT */
extern CONST(uint16, WDGM_CONST) WdgM_GusDeInitTimeout;
#define WDGM_STOP_SEC_CONST_16
#include "MemMap.h"

#if(WDGM_DEFENSIVE_BEHAVIOR == STD_ON)
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* WDGM_TOTAL_SET_MODE_API_CALLERS */
extern CONST(uint8, WDGM_CONST) WdgM_GucTotalSetModeApiCallers;
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(WDGM_ENABLE_ALIVE_SUPERVISION == STD_ON)
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* WDGM_MAX_ALIVE_SUPERVISION_REF_CYCLE */
extern CONST(uint32, WDGM_CONST) WdgM_GulMaxAliveSupervisionRefCycle;
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if(WDGM_DEM_ERROR_REPORT == STD_ON)
#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* WDGM_E_IMPROPER_CALLER */
extern CONST(Dem_EventIdType, WDGM_CONST) WdgM_GddEImproperCaller;
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* WDGM_E_MONITORING */
extern CONST(Dem_EventIdType, WDGM_CONST) WdgM_GddEMonitoring;
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* WDGM_E_SET_MODE */
extern CONST(Dem_EventIdType, WDGM_CONST) WdgM_GddESetMode;
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#endif /* WDGM_CONFIG_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
