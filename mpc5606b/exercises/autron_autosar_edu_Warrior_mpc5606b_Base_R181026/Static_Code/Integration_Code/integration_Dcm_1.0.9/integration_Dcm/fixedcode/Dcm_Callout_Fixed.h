/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_CallOuts.H                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : This file contains the declaration for Dcm callout functions  **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By              Description                        **
********************************************************************************
** 1.0.0     20-02-2017    Autron          Initial Version                    **
*******************************************************************************/

#ifndef DCM_CALLOUT_FIXED_H
#define DCM_CALLOUT_FIXED_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dcm_CallOuts.h"

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define DCM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
extern FUNC(Dcm_EcuStartModeType, DCM_CALLOUT_CODE) Dcm_Internal_GetProgConditions
  (P2VAR(Dcm_ProgConditionsType, AUTOMATIC,DCM_APPL_DATA) ProgConditions);

extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Internal_SetProgConditions
  (P2CONST(Dcm_ProgConditionsType, AUTOMATIC,DCM_APPL_CONST) ProgConditions);
#define DCM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

#endif /* End DCM_CALLOUT_FIXED_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
