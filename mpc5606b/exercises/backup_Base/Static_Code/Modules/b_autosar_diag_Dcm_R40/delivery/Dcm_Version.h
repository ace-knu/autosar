/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_Version.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_Version                                      **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By                   Description                   **
********************************************************************************
** 1.0.0     09-01-2013    Autron               Initial Version               **
*******************************************************************************/
#ifndef DCM_VERSION_H
#define DCM_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dcm_Types.h"
#include "Dcm_Cfg.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR SPECIFICATION VERSION */
#define DCM_VERSION_AR_RELEASE_MAJOR_VERSION     DCM_AR_RELEASE_MAJOR_VERSION
#define DCM_VERSION_AR_RELEASE_MINOR_VERSION     DCM_AR_RELEASE_MINOR_VERSION
#define DCM_VERSION_AR_RELEASE_REVISION_VERSION  DCM_AR_RELEASE_REVISION_VERSION

/* SOFTWARE VERSION INFORMATION */
#define DCM_VERSION_SW_MAJOR_VERSION        DCM_SW_MAJOR_VERSION
#define DCM_VERSION_SW_MINOR_VERSION        DCM_SW_MINOR_VERSION

#define DCM_DET_AR_RELEASE_MAJOR_VERSION            4
#define DCM_DET_AR_RELEASE_MINOR_VERSION            0

#define DCM_SCHM_AR_RELEASE_MAJOR_VERSION           4
#define DCM_SCHM_AR_RELEASE_MINOR_VERSION           0
#define DCM_RTE_AR_RELEASE_MAJOR_VERSION            4
#define DCM_RTE_AR_RELEASE_MINOR_VERSION            0

#define DCM_DEM_AR_RELEASE_MAJOR_VERSION            4
#define DCM_DEM_AR_RELEASE_MINOR_VERSION            0

#define DCM_COMM_AR_RELEASE_MAJOR_VERSION           4
#define DCM_COMM_AR_RELEASE_MINOR_VERSION           0

#define DCM_PDUR_AR_RELEASE_MAJOR_VERSION           4
#define DCM_PDUR_AR_RELEASE_MINOR_VERSION           0

#define DCM_NVM_AR_RELEASE_MAJOR_VERSION            4
#define DCM_NVM_AR_RELEASE_MINOR_VERSION            0

#define DCM_IOHWAB_AR_RELEASE_MAJOR_VERSION         4
#define DCM_IOHWAB_AR_RELEASE_MINOR_VERSION         0

#define DCM_BSWM_AR_RELEASE_MAJOR_VERSION           4
#define DCM_BSWM_AR_RELEASE_MINOR_VERSION           0

#define DCM_DLT_AR_RELEASE_MAJOR_VERSION            4
#define DCM_DLT_AR_RELEASE_MINOR_VERSION            0

#endif /* DCM_VERSION_H */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
