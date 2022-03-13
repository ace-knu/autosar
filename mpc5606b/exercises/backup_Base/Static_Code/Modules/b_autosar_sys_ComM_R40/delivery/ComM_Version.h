/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: ComM_Version.h                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR COM Manager                                           **
**                                                                            **
**  PURPOSE   : C header for ComM_Version                                     **
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
** 1.0.7   20-Jul-2016   Kyungtae Kim     #2070                               **
** 1.0.6   04-Jul-2013   Daejun Park      CR~129, XAR~581 : ComM library      **
** 1.0.0   17-Dec-2012   Daejun Park            Initial version               **
*******************************************************************************/

#ifndef COMM_VERSION_H
#define COMM_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComM.h"                 /* ComM header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COMM_VERSION_AR_RELEASE_MAJOR_VERSION COMM_AR_RELEASE_MAJOR_VERSION
#define COMM_VERSION_AR_RELEASE_MINOR_VERSION COMM_AR_RELEASE_MINOR_VERSION
#define COMM_VERSION_AR_RELEASE_REVISION_VERSION\
  COMM_AR_RELEASE_REVISION_VERSION

/* ComM Software Version Information */
#define COMM_VERSION_SW_MAJOR_VERSION         COMM_SW_MAJOR_VERSION
#define COMM_VERSION_SW_MINOR_VERSION         COMM_SW_MINOR_VERSION

/* CanSM Software Version Information */
#if (COMM_CANNETWORK_PRESENT == STD_ON)
#define COMM_CANSM_AR_RELEASE_MAJOR_VERSION   4
#define COMM_CANSM_AR_RELEASE_MINOR_VERSION   0
#endif

/* Dcm Software Version Information */
#define COMM_DCM_AR_RELEASE_MAJOR_VERSION     4
#define COMM_DCM_AR_RELEASE_MINOR_VERSION     0

/* Det Software Version Information */
#if (COMM_DEV_ERROR_DETECT == STD_ON)
#define COMM_DET_AR_RELEASE_MAJOR_VERSION     4
#define COMM_DET_AR_RELEASE_MINOR_VERSION     0
#endif

/* FrSM Software Version Information */
#if (COMM_FRNETWORK_PRESENT == STD_ON)
#define COMM_FRSM_AR_RELEASE_MAJOR_VERSION    4
#define COMM_FRSM_AR_RELEASE_MINOR_VERSION    0
#endif

/* LinSM Software Version Information */
#if (COMM_LINNETWORK_PRESENT == STD_ON)
#define COMM_LINSM_AR_RELEASE_MAJOR_VERSION   4
#define COMM_LINSM_AR_RELEASE_MINOR_VERSION   0
#endif

/* EthSM Software Version Information */
#if (COMM_ETHNETWORK_PRESENT == STD_ON)
#define COMM_ETHSM_AR_RELEASE_MAJOR_VERSION   4
#define COMM_ETHSM_AR_RELEASE_MINOR_VERSION   1
#endif

#if ((COMM_FULL_NMVARIANT_SUPPORT == STD_ON) ||\
  (COMM_PASSIVE_NMVARIANT_SUPPORT == STD_ON))

/* Nm Software Version Information */
#define COMM_NM_AR_RELEASE_MAJOR_VERSION      4
#define COMM_NM_AR_RELEASE_MINOR_VERSION      0
#endif

/* NvM Software Version Information */
#if (COMM_NVM_BLOCK_DESCRIPTOR == STD_ON)
#define COMM_NVM_AR_RELEASE_MAJOR_VERSION     4
#define COMM_NVM_AR_RELEASE_MINOR_VERSION     0
#endif

/* Rte Software Version Information */
#define COMM_RTE_AR_RELEASE_MAJOR_VERSION     4
#define COMM_RTE_AR_RELEASE_MINOR_VERSION     0

/* BswM Software Version Information */
#define COMM_BSWM_AR_RELEASE_MAJOR_VERSION    4
#define COMM_BSWM_AR_RELEASE_MINOR_VERSION    0

/*Com Software Version Information */
#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON))
#define COMM_COM_AR_RELEASE_MAJOR_VERSION     4
#define COMM_COM_AR_RELEASE_MINOR_VERSION     0
#endif
#endif

#endif /* COMM_VERSION_H */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

