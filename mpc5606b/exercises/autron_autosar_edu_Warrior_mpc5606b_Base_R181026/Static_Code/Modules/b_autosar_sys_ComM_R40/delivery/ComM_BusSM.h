/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: ComM_BusSM.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR COM Manager                                           **
**                                                                            **
**  PURPOSE   : Provision of external declaration of BusSM Bus Off            **
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
** 1.0.6   04-Jul-2013   Daejun Park      CR~129, XAR~581 : ComM library      **
** 1.0.0   17-Dec-2012   Daejun Park            Initial version               **
*******************************************************************************/

#ifndef COMM_BUSSM_H
#define COMM_BUSSM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COMM_BUSSM_AR_RELEASE_MAJOR_VERSION    COMM_AR_RELEASE_MAJOR_VERSION
#define COMM_BUSSM_AR_RELEASE_MINOR_VERSION    COMM_AR_RELEASE_MINOR_VERSION
#define COMM_BUSSM_AR_RELEASE_REVISION_VERSION COMM_AR_RELEASE_REVISION_VERSION

/* Software Version Information */
#define COMM_BUSSM_SW_MAJOR_VERSION            COMM_SW_MAJOR_VERSION
#define COMM_BUSSM_SW_MINOR_VERSION            COMM_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_BusSM_ModeIndication */
extern FUNC(void, COMM_CODE) ComM_BusSM_ModeIndication(NetworkHandleType
  Channel, P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* COMM_BUSSM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

