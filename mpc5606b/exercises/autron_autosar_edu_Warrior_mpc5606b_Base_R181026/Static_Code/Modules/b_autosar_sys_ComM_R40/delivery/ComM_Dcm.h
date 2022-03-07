/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: ComM_Dcm.h                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR COM Manager                                           **
**                                                                            **
**  PURPOSE   : Provision of external declaration of Dcm                      **
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
** 1.0.7   30-Jun-2015   Kyungtae Kim     Change for MISRA rule 19.4          **
** 1.0.6   04-Jul-2013   Daejun Park      CR~129, XAR~581 : ComM library      **
** 1.0.0   17-Dec-2012   Daejun Park            Initial version               **
*******************************************************************************/

#ifndef COMM_DCM_H
#define COMM_DCM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COMMDCM_AR_RELEASE_MAJOR_VERSION (COMM_AR_RELEASE_MAJOR_VERSION)
#define COMMDCM_AR_RELEASE_MINOR_VERSION (COMM_AR_RELEASE_MINOR_VERSION)
#define COMMDCM_AR_RELEASE_REVISION_VERSION\
  (COMM_AR_RELEASE_REVISION_VERSION)

/* Software Version Information */
#define COMMDCM_SW_MAJOR_VERSION         (COMM_SW_MAJOR_VERSION)
#define COMMDCM_SW_MINOR_VERSION         (COMM_SW_MINOR_VERSION)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_DCM_ActiveDiagnostic */
extern FUNC(void, COMM_CODE) ComM_DCM_ActiveDiagnostic(NetworkHandleType
  Channel);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_DCM_InactiveDiagnostic */
extern FUNC(void, COMM_CODE) ComM_DCM_InactiveDiagnostic(NetworkHandleType
  Channel);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* COMM_DCM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

