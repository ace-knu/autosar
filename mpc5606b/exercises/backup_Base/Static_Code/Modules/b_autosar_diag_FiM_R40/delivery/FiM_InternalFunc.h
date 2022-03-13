/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: FiM_InternalFunc.h                                            **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Function Inhibition Manager Module                    **
**                                                                            **
**  PURPOSE   : c Header for FiM_InternalFunc.c                               **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By            Description                          **
********************************************************************************
** 1.0.1     26-Nov-2012   Udaykumar B   extern's of                          **
**                                       FiM_EventIdLinearSearch,             **
**                                       FiM_FidLinearSearch API's are added  **
**                                       to implement linear search           **
**                                       functionality and two macros         **
**                                       FIM_EN_EVENTID_BINARYSEARCH,         **
**                                       FIM_EN_FID_BINARYSEARCH are added as **
**                                       Pre-compile switches for the externs **
**                                                                            **
** 1.0.0     01-Nov-2012   Autron        Initial version                      **
*******************************************************************************/
#ifndef FIM_INTERNALFUNC_H
#define FIM_INTERNALFUNC_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "FiM_Ram.h"  /* Ram header file */

/*******************************************************************************
**                           Global Data                                      **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define FIM_START_SEC_CODE
#include "MemMap.h"


extern FUNC(Std_ReturnType, FIM_CODE)FiM_CalcAllFidsPermissions(void);

extern FUNC(void, FIM_CODE)FiM_CalcFidPermission(
FiM_EventFidLinkType LddFirstEventFidLink,
Dem_EventStatusExtendedType LddEventStatusExtended,
FiM_EventsSizeType LddEvent
);

#define FIM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* End of FIM_INTERNALFUNC_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
