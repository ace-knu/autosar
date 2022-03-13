/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  INC-MODULE: ComM_Nm.h                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR COM Manager                                           **
**                                                                            **
**  PURPOSE   : Provision of external declaration of Network Management       **
**              Indication API's                                              **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date             By                   Description                **
********************************************************************************
** 1.0.7   28-May-2015   Kyungtae Kim     Cleared error against MISRA rulle   **
** 1.0.6   04-Jul-2013   Daejun Park      CR~129, XAR~581 : ComM library      **
** 1.0.0   17-Dec-2012   Daejun Park            Initial version               **
*******************************************************************************/

#ifndef COMM_NM_H
#define COMM_NM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COMMNM_AR_RELEASE_MAJOR_VERSION (COMM_AR_RELEASE_MAJOR_VERSION)
#define COMMNM_AR_RELEASE_MINOR_VERSION (COMM_AR_RELEASE_MINOR_VERSION)
#define COMMNM_AR_RELEASE_REVISION_VERSION\
  (COMM_AR_RELEASE_REVISION_VERSION)

/* Software Version Information */
#define COMMNM_SW_MAJOR_VERSION         (COMM_SW_MAJOR_VERSION)
#define COMMNM_SW_MINOR_VERSION         (COMM_SW_MINOR_VERSION)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_Nm_NetworkStartIndication */
extern FUNC(void, COMM_CODE) ComM_Nm_NetworkStartIndication(NetworkHandleType
  Channel);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_Nm_NetworkMode */
extern FUNC(void, COMM_CODE) ComM_Nm_NetworkMode(NetworkHandleType Channel);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_Nm_PrepareBusSleepMode */
extern FUNC(void, COMM_CODE) ComM_Nm_PrepareBusSleepMode(NetworkHandleType
  Channel);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_Nm_BusSleepMode */
extern FUNC(void, COMM_CODE) ComM_Nm_BusSleepMode(NetworkHandleType Channel);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_Nm_RestartIndication  */
extern FUNC(void, COMM_CODE) ComM_Nm_RestartIndication(NetworkHandleType
  Channel);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* COMM_NM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

