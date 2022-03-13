/*******************************************************************************
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanTp_Cbk.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN Transport Protocol                                **
**                                                                            **
**  PURPOSE   : Internal header file for CanTp                                **
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
** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
*******************************************************************************/
#ifndef CANTP_CBK_H
#define CANTP_CBK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComStack_Types.h"       /* Com Stack header */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CANTP_CBK_AR_RELEASE_MAJOR_VERSION    4
#define CANTP_CBK_AR_RELEASE_MINOR_VERSION    0
#define CANTP_CBK_AR_RELEASE_REVISION_VERSION 3

/* CANTP software version information */
#define CANTP_CBK_SW_MAJOR_VERSION            1
#define CANTP_CBK_SW_MINOR_VERSION            0
#define CANTP_CBK_SW_PATCH_VERSION            3

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CANTP_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANTP_CODE) CanTp_RxIndication(PduIdType RxPduId, P2CONST(
    PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr);
#define CANTP_STOP_SEC_CODE
#include "MemMap.h"

#define CANTP_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANTP_CODE) CanTp_TxConfirmation(PduIdType TxPduId);
#define CANTP_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CANTP_CBK_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

