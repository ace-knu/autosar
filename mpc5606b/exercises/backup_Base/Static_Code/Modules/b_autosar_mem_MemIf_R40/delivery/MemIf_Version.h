/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: MemIf_Version.h                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR MemIf Module                                          **
**                                                                            **
**  PURPOSE   : C header for MemIf_Version                                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By               Description                       **
********************************************************************************
** 1.0.0     07-Feb-2013   CY Song          Initial Version                   **
*******************************************************************************/
#ifndef MEMIF_VERSION_H
#define MEMIF_VERSION_H

/*******************************************************************************
**                    Include Section                                         **
*******************************************************************************/
#include "MemIf.h"

/*******************************************************************************
**                     Version Information                                    **
*******************************************************************************/
/* AUTOSAR specification version information */
#define MEMIF_VERSION_AR_RELEASE_MAJOR_VERSION  MEMIF_AR_RELEASE_MAJOR_VERSION
#define MEMIF_VERSION_AR_RELEASE_MINOR_VERSION  MEMIF_AR_RELEASE_MINOR_VERSION
#define MEMIF_VERSION_AR_RELEASE_REVISION_VERSION \
  MEMIF_AR_RELEASE_REVISION_VERSION

/* File version information */
#define MEMIF_VERSION_SW_MAJOR_VERSION  MEMIF_SW_MAJOR_VERSION
#define MEMIF_VERSION_SW_MINOR_VERSION  MEMIF_SW_MINOR_VERSION

/* Included files AUTOSAR specification version */
#if(MEMIF_DEV_ERROR_DETECT == STD_ON)
#define MEMIF_DET_AR_RELEASE_MAJOR_VERSION  4
#define MEMIF_DET_AR_RELEASE_MINOR_VERSION  0
#endif

#if(MEMIF_MAX_CONFIGURED_EA_DEVICES > MEMIF_ZERO)
#define MEMIF_EA_AR_RELEASE_MAJOR_VERSION  4
#define MEMIF_EA_AR_RELEASE_MINOR_VERSION  0
#endif

#if(MEMIF_MAX_CONFIGURED_FEE_DEVICES > MEMIF_ZERO)
#define MEMIF_FEE_AR_RELEASE_MAJOR_VERSION  4
#define MEMIF_FEE_AR_RELEASE_MINOR_VERSION  0
#endif

#endif /* end of MEMIF_VERSION_H */
/*******************************************************************************
**                         End of File                                        **
*******************************************************************************/
