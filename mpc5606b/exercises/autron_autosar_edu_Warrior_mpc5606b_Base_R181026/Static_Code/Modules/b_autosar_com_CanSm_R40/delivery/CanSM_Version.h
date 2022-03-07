/*******************************************************************************
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.								          **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanSM_Version.h                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN State Manager Module                              **
**                                                                            **
**  PURPOSE   : Header for CanSM_Version.c                                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 1.10.0    27-Oct-2016   Lim Jong Sun   #7076                               **
** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
*******************************************************************************/
#ifndef CANSM_VERSION_H
#define CANSM_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanSM.h"                /* Inclusion of CanSM header */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define CANSM_VERSION_H_AR_RELEASE_MAJOR_VERSION         4
#define CANSM_VERSION_H_AR_RELEASE_MINOR_VERSION         0
#define CANSM_VERSION_H_AR_RELEASE_REVISION_VERSION      3

/* Software Version Information */
#define CANSM_VERSION_H_SW_MAJOR_VERSION                 1
#define CANSM_VERSION_H_SW_MINOR_VERSION                 10



/* Other (Interface) module version information */
#define CANSM_CANIF_AR_RELEASE_MAJOR_VERSION   4
#define CANSM_CANIF_AR_RELEASE_MINOR_VERSION   0

#define CANSM_CANNM_AR_RELEASE_MAJOR_VERSION   4
#define CANSM_CANNM_AR_RELEASE_MINOR_VERSION   0

#define CANSM_CANTRCV_AR_RELEASE_MAJOR_VERSION 4
#define CANSM_CANTRCV_AR_RELEASE_MINOR_VERSION 0

#define CANSM_COMM_AR_RELEASE_MAJOR_VERSION    4
#define CANSM_COMM_AR_RELEASE_MINOR_VERSION    0

#if (STD_ON == CANSM_DEV_ERROR_DETECT)
#define CANSM_DET_AR_RELEASE_MAJOR_VERSION     0x04
#define CANSM_DET_AR_RELEASE_MINOR_VERSION     0x00
#endif

#define CANSM_DEM_AR_RELEASE_MAJOR_VERSION     4
#define CANSM_DEM_AR_RELEASE_MINOR_VERSION     0

#define CANSM_SCHM_AR_RELEASE_MAJOR_VERSION    4
#define CANSM_SCHM_AR_RELEASE_MINOR_VERSION    0

#define CANSM_BSWM_AR_RELEASE_MAJOR_VERSION    4
#define CANSM_BSWM_AR_RELEASE_MINOR_VERSION    0

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
#endif /* CANSM_VERSION_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
