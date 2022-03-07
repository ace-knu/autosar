/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: MemIf_Version.c                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR MemIf Module                                          **
**                                                                            **
**  PURPOSE   : Provision of Version information                              **
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

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "MemIf_Version.h"
#if(MEMIF_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if(MEMIF_MAX_CONFIGURED_FEE_DEVICES > MEMIF_ZERO)
#include "Fee.h"
#endif
#if(MEMIF_MAX_CONFIGURED_EA_DEVICES > MEMIF_ZERO)
#include "Ea.h"
#endif
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define MEMIF_VERSION_C_AR_RELEASE_MAJOR_VERSION  4
#define MEMIF_VERSION_C_AR_RELEASE_MINOR_VERSION  0
#define MEMIF_VERSION_C_AR_RELEASE_REVISION_VERSION  3

/* File version information */
#define MEMIF_VERSION_C_SW_MAJOR_VERSION  1
#define MEMIF_VERSION_C_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if(MEMIF_DEV_ERROR_DETECT == STD_ON)
#if(DET_AR_RELEASE_MAJOR_VERSION != MEMIF_DET_AR_RELEASE_MAJOR_VERSION)
  #error "Det.h : Mismatch in Specification Major Version"
#endif
#if(DET_AR_RELEASE_MINOR_VERSION != MEMIF_DET_AR_RELEASE_MINOR_VERSION)
  #error "Det.h : Mismatch in Specification Minor Version"
#endif
#endif

#if(MEMIF_MAX_CONFIGURED_EA_DEVICES > MEMIF_ZERO)
#if(EA_AR_RELEASE_MAJOR_VERSION != MEMIF_EA_AR_RELEASE_MAJOR_VERSION)
  #error "Ea.h : Mismatch in Specification Major Version"
#endif
#if(EA_AR_RELEASE_MINOR_VERSION != MEMIF_EA_AR_RELEASE_MINOR_VERSION)
  #error "Ea.h : Mismatch in Specification Minor Version"
#endif
#endif

#if(MEMIF_MAX_CONFIGURED_FEE_DEVICES > MEMIF_ZERO)
#if(FEE_AR_RELEASE_MAJOR_VERSION != MEMIF_FEE_AR_RELEASE_MAJOR_VERSION)
  #error "Fee.h : Mismatch in Specification Major Version"
#endif

#if(FEE_AR_RELEASE_MINOR_VERSION != MEMIF_FEE_AR_RELEASE_MINOR_VERSION)
  #error "Fee.h : Mismatch in Specification Minor Version"
#endif
#endif
/*******************************************************************************
**                         End of File                                        **
*******************************************************************************/
