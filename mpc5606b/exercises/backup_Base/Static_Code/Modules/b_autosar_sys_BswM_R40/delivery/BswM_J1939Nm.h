/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : BswM_J1939Nm.h                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR BswM Module                                           **
**                                                                            **
**  PURPOSE   : Providing interface to FrSM                                   **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                              Revision History                              **
********************************************************************************
** Revision  Date          By            Description                          **
********************************************************************************
** 1.0.0     10-May-2016   Sanghoon Bae  Initial version                      **
*******************************************************************************/

#ifndef BSWM_J1939NM_H
#define BSWM_J1939NM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "J1939Nm.h"
#include "NmStack_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define BSWM_START_SEC_CODE
#include "MemMap.h"
/* Extern for BswM_J1939DcmBroadcastStatus */
extern FUNC(void, BSWM_CODE) BswM_J1939Nm_StateChangeNotification
 (NetworkHandleType Network,
  uint8 Node,
  Nm_StateType NmState);
#define BSWM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* BSWM_J1939NM_H */


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
