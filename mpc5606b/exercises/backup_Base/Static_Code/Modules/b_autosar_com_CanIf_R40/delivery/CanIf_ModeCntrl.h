/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf_ModeCntrl.h                                             **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : Header file of CanIf_ModeCntrl.c                              **
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
** 2.5.0    06-Dec-2016    Js.Lim     #7077                                   **
** 1.0.1    08-Jan-2016    Kt.Kim     #3813                                   **
** 1.0.0    04-Feb-2013    Kt.Kim     Initial version                         **
*******************************************************************************/
#ifndef CANIF_MODECNTRL_H
#define CANIF_MODECNTRL_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf_Tx.h"            /* Tx Interface header file */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANIF_MODECNTRL_AR_RELEASE_MAJOR_VERSION       4
#define CANIF_MODECNTRL_AR_RELEASE_MINOR_VERSION       0
#define CANIF_MODECNTRL_AR_RELEASE_REVISION_VERSION    3

/* Software Version Information */
#define CANIF_MODECNTRL_SW_MAJOR_VERSION    2
#define CANIF_MODECNTRL_SW_MINOR_VERSION    5
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC (void, CANIF_CODE) CanIf_SetTxOrRxSts (
                      VAR(uint8, CANIF_VAR) ControllerId, 
                      VAR(CanIf_PduSetModeType, CANIF_VAR) LddPduMode);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#if (STD_ON == CANIF_DEV_ERROR_DETECT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_DETSetControllerMode (
                       VAR(uint8, CANIF_VAR) ControllerId, 
                       VAR(CanIf_ControllerModeType, CANIF_VAR) ControllerMode);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#define CANIF_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Can_ReturnType, CANIF_CODE) CanIf_SetControllerModeService (
                               VAR(uint8, CANIF_VAR) Controller, 
                               VAR(Can_StateTransitionType, CANIF_VAR) CanMode);
#define CANIF_START_SEC_CODE
#include "MemMap.h"

#endif /* CANIF_MODE_CNTRL_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
