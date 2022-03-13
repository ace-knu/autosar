/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: PduR_Version.h                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR PDU Router                                            **
**                                                                            **
**  PURPOSE   : C header for PduR_Version                                     **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By          Description                            **
********************************************************************************
** 2.2.0     01-Feb-2017   Chan Kim    Redmine #6922                          **
** 2.1.0     17-Jun-2016   Chan Kim    Redmine #5190                          **
** 2.0.5     06-Apr-2016   Chan Kim    Redmine #4519                          **
** 2.0.0     11-Aug-2015   Chan Kim    Redmine #2949                          **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/
#ifndef PDUR_VERSION_H
#define PDUR_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */

/* AUTOSAR Specification Version Information */
#define PDUR_VERSION_AR_RELEASE_MAJOR_VERSION    4
#define PDUR_VERSION_AR_RELEASE_MINOR_VERSION    0
#define PDUR_VERSION_AR_RELEASE_REVISION_VERSION 3

/* Software Version Information */
#define PDUR_VERSION_SW_MAJOR_VERSION            2
#define PDUR_VERSION_SW_MINOR_VERSION            2

/* Other (Interface) module version information */
#if (PDUR_CANIF_SUPPORT == STD_ON)
#define PDUR_CANIF_AR_RELEASE_MAJOR_VERSION      4
#define PDUR_CANIF_AR_RELEASE_MINOR_VERSION      0
#endif

#if (PDUR_LINIF_SUPPORT == STD_ON)
#define PDUR_LINIF_AR_RELEASE_MAJOR_VERSION      4
#define PDUR_LINIF_AR_RELEASE_MINOR_VERSION      0
#endif

#if (PDUR_FRIF_SUPPORT == STD_ON)
#define PDUR_FRIF_AR_RELEASE_MAJOR_VERSION       4
#define PDUR_FRIF_AR_RELEASE_MINOR_VERSION       0
#endif

/* Other (Transport Protocol) module version information */
#if (PDUR_CANTP_SUPPORT == STD_ON)
#define PDUR_CANTP_AR_RELEASE_MAJOR_VERSION      4
#define PDUR_CANTP_AR_RELEASE_MINOR_VERSION      0
#endif

#if (PDUR_FRTP_SUPPORT == STD_ON)
#define PDUR_FRTP_AR_RELEASE_MAJOR_VERSION       4
#define PDUR_FRTP_AR_RELEASE_MINOR_VERSION       0
#endif

/* Other (Upper Layer) module version information */
#if (PDUR_COM_SUPPORT == STD_ON)
#define PDUR_COM_AR_RELEASE_MAJOR_VERSION        4
#define PDUR_COM_AR_RELEASE_MINOR_VERSION        0
#endif

#if (PDUR_DCM_SUPPORT == STD_ON)
#define PDUR_DCM_AR_RELEASE_MAJOR_VERSION        4
#define PDUR_DCM_AR_RELEASE_MINOR_VERSION        0
#endif

#if (PDUR_IPDUM_SUPPORT == STD_ON)
#define PDUR_IPDUM_AR_RELEASE_MAJOR_VERSION      4
#define PDUR_IPDUM_AR_RELEASE_MINOR_VERSION      0
#endif

#if (PDUR_DEV_ERROR_DETECT == STD_ON)
#define PDUR_DET_AR_RELEASE_MAJOR_VERSION        4
#define PDUR_DET_AR_RELEASE_MINOR_VERSION        0
#endif

#if (PDUR_FRNM_SUPPORT == STD_ON)
#define PDUR_FRNM_AR_RELEASE_MAJOR_VERSION      4
#define PDUR_FRNM_AR_RELEASE_MINOR_VERSION      0
#endif
#endif /* PDUR_VERSION_H */
/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
