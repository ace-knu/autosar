/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: NvM_Cbk.h                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR NvM Module                                            **
**                                                                            **
**  PURPOSE   : Provision of Macros and API Prototype Declarations            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision    Date           By          Description                         **
********************************************************************************
** 1.1.7       09-Jul-2015  Song CY       Justify MISRA-Rule Violation        **
** 1.1.6       03-Mar-2015  Song CY       As per RedMine 2216, Remove version **
**                                        Information                         **
** 1.0.0       25-Jan-2013    CY Song     Initial version                     **
*******************************************************************************/

#ifndef NVM_CBK_H
#define NVM_CBK_H

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/*
polyspace:begin<MISRA-C:8.8:Not a defect:Justify with annotations> No Impact of this rule violation (Mcal FEE violate spec - Not include NvM_Chk.h but declare extern)
*/

/*******************************************************************************
**                   Include Section                                         ***
*******************************************************************************/
#include "NvM_Cfg.h"


/*******************************************************************************
**                   Global Data                                              **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if(NVM_POLLING_MODE == STD_OFF)

#define NVM_START_SEC_CODE
#include "MemMap.h"

/* For MemIf job end notification without error */
extern FUNC(void, NVM_CODE) NvM_JobEndNotification(void);

/* For MemIf job end notification with error */
extern FUNC(void, NVM_CODE) NvM_JobErrorNotification(void);

#define NVM_STOP_SEC_CODE
#include "MemMap.h"

#endif

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/*
polyspace:bnd<MISRA-C:8.8:Not a defect:Justify with annotations> No Impact of this rule violation (Mcal FEE violate spec - Not include NvM_Chk.h but declare extern)
*/

#endif /* NVM_CBK_H */

/*******************************************************************************
**                          END OF FILE                                       **
*******************************************************************************/
