/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CAN_ModeTransition_MPC560x.h                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN Integration Module                                **
**                                                                            **
**  PURPOSE   : Provision of delclarations                                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By               Description                       **
********************************************************************************
** 1.0.0     20-Apr-2016   Kyungtae Kim  Initial Version                      **
*******************************************************************************/
#ifndef CAN_MODE_TRANSITION_MPC560X_H_
#define CAN_MODE_TRANSITION_MPC560X_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Can.h"
#include "Reg_eSys.h"
#include "Reg_eSys_Rtc.h"
#include "Reg_eSys_WKPU.h"
#include "Reg_eSys_MagicCarpet.h"
#include "Reg_eSys_Stm.h"
#include "Reg_eSys_DSPI.h"
#include "Reg_eSys_Pit.h"
#include "Reg_eSys_eMIOS.h"
#include "Reg_eSys_FlexCan.h"
#include "Reg_eSys_SIUL.h"
#include "Reg_eSys_Pit.h"

#include "Os_prop.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/


/*******************************************************************************
**                       Function Prototypes                                  **
*******************************************************************************/
#define CAN_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Can_ReturnType, CAN_CODE) CanSetMDIS(void);
extern FUNC(Can_ReturnType, CAN_CODE) CanClearMDIS(void);
#define CAN_STOP_SEC_CODE
#include "MemMap.h"


#endif /* MEMDRIVERINIT_H_ */
