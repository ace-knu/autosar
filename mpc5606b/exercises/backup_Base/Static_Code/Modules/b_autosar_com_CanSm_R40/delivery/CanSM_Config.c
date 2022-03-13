/*******************************************************************************
**  (C) 2013 Hyundai AUTRON Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanSM_Config.c                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN State Manager Module                              **
**                                                                            **
**  PURPOSE   : CanTSM Library Relase.                                        **
**                                                                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 1.10.0    27-Oct-2016   Lim Jong Sun   #7048                               **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanSM_Cfg.h"
#include "CanSM_PCTypes.h"
/*******************************************************************************
**            Variable for Library                  **
*******************************************************************************/
#if (STD_ON == CANSM_CANTRCV_SUPPORT)
#define CANSM_START_SEC_CONST_8
#include "MemMap.h"
CONST(uint8, CANSM_CONST) CanSm_GucLastTrcvHandle = CANSM_LAST_TRANSCEIVER_HANDLE;
#define CANSM_STOP_SEC_CONST_8
#include "MemMap.h"
#endif
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/