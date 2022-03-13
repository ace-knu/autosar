/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: WdgM_Version.h                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR WDGM                                                  **
**                                                                            **
**  PURPOSE   : Header for WdgM_Version.c                                     **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By           Description                           **
********************************************************************************
** 1.0.4     03-Feb-2015   Sinil        1. Update version infos from common   **
**                                      published version                     **
** 1.0.3     21-Oct-2014   Sinil        1. Update                             **
**                                      WDGM_VERSION_SW_PATCH_VERSION         **
** 1.0.2     30-Sep-2014   Sinil        1. Remove Det precompiler option      **
** 1.0.0     01-Jan-2013   Autron       Initial version                       **
*******************************************************************************/

#ifndef WDGM_VERSION_H
#define WDGM_VERSION_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "WdgM_Cfg.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define WDGM_VERSION_AR_RELEASE_MAJOR_VERSION    WDGM_AR_RELEASE_MAJOR_VERSION
#define WDGM_VERSION_AR_RELEASE_MINOR_VERSION    WDGM_AR_RELEASE_MINOR_VERSION
#define WDGM_VERSION_AR_RELEASE_REVISION_VERSION WDGM_AR_RELEASE_REVISION_VERSION

/* Software Version Information */
#define WDGM_VERSION_SW_MAJOR_VERSION     WDGM_SW_MAJOR_VERSION
#define WDGM_VERSION_SW_MINOR_VERSION     WDGM_SW_MINOR_VERSION
#define WDGM_VERSION_SW_PATCH_VERSION     WDGM_SW_PATCH_VERSION

/*Version information of WdgIf module */
#define WDGM_WDGIF_AR_RELEASE_MAJOR_VERSION        4
#define WDGM_WDGIF_AR_RELEASE_MINOR_VERSION        0

/*Version information of Mcu module */
#define WDGM_MCU_AR_RELEASE_MAJOR_VERSION          4
#define WDGM_MCU_AR_RELEASE_MINOR_VERSION          0

/*Version information of Det module */
#define WDGM_DET_AR_RELEASE_MAJOR_VERSION          4
#define WDGM_DET_AR_RELEASE_MINOR_VERSION          0

/*Version information of Dem module */
#define WDGM_DEM_AR_RELEASE_MAJOR_VERSION          4
#define WDGM_DEM_AR_RELEASE_MINOR_VERSION          0

/* Version information of RTE module */
#define WDGM_RTE_AR_RELEASE_MAJOR_VERSION          4
#define WDGM_RTE_AR_RELEASE_MINOR_VERSION          0

/*Version information of BswM module */
#define WDGM_BSWM_AR_RELEASE_MAJOR_VERSION         4
#define WDGM_BSWM_AR_RELEASE_MINOR_VERSION         0

/*Version information of Os module */
#define WDGM_OS_AR_RELEASE_MAJOR_VERSION           4
#define WDGM_OS_AR_RELEASE_MINOR_VERSION           0

#endif /* WDGM_VERSION_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
