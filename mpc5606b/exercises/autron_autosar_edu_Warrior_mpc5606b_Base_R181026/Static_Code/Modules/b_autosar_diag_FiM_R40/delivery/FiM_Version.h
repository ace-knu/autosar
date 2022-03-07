/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: FiM_Version.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Function Inhibition Manager Module                    **
**                                                                            **
**  PURPOSE   : C header for FiM_Version.c                                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By            Description                          **
********************************************************************************
** 1.0.0     01-Nov-2012   Autron        Initial version                      **
*******************************************************************************/
#ifndef FIM_VERSION_H
#define FIM_VERSION_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "FiM_Cfg.h"        /* FiM Cfg Definition Header File */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define FIM_VERSION_AR_RELEASE_MAJOR_VERSION     FIM_AR_RELEASE_MAJOR_VERSION
#define FIM_VERSION_AR_RELEASE_MINOR_VERSION     FIM_AR_RELEASE_MINOR_VERSION
#define FIM_VERSION_AR_RELEASE_REVISION_VERSION  FIM_AR_RELEASE_REVISION_VERSION

/* FiM Software Version Information */
#define FIM_VERSION_SW_MAJOR_VERSION     FIM_SW_MAJOR_VERSION
#define FIM_VERSION_SW_MINOR_VERSION     FIM_SW_MINOR_VERSION

/* Version information of Dem module */
#define FIM_DEM_AR_RELEASE_MAJOR_VERSION         4
#define FIM_DEM_AR_RELEASE_MINOR_VERSION         0

/*Version information of Det module */
#if (FIM_DEV_ERROR_DETECT == STD_ON)
  #define FIM_DET_AR_RELEASE_MAJOR_VERSION       4
  #define FIM_DET_AR_RELEASE_MINOR_VERSION       0
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
	/* Extern for FiM_GetVersionInfo */
#if (FIM_VERSION_INFO_API == STD_ON)
extern FUNC(void, FIM_CODE)FiM_GetVersionInfo
(
P2VAR(Std_VersionInfoType, AUTOMATIC, FIM_APPL_DATA)versioninfo
);
#endif

#endif /* FIM_VERSION_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
