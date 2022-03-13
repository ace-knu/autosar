/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: WdgM_Version.c                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Watchdog Manager Module                               **
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
** Revision  Date          By           Description                           **
********************************************************************************
** 1.0.4     21-Oct-2014   Sinil        1. Change including                   **
** 1.0.3     03-Jan-2014   Sinil        TaskID:809                            **
**                                      1. Lines reordered                    **
**                                      2. Include header and error log       **
**                                      changed                               **
** 1.0.2     23-Dec-2013   Sinil        Add precondition for version check    **
** 1.0.0     01-Jan-2013   Autron       Initial version                       **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "WdgM_Version.h"     /* WdgM version header file */
#include "WdgM.h"             /* WdgM module header file */
#include "WdgIf.h"            /* WdgIf version header file */
#include "Mcu.h"              /* Mcu module Header file */
#if(WDGM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"              /* Det module Header file */
#endif
#if(WDGM_DEM_ERROR_REPORT == STD_ON)
#include "Dem.h"              /* Dem version Header file */
#endif
#include "Rte.h"              /* Rte version header file */
#include "BswM.h"             /* BswM version header file */
#include "Os.h"               /* Os version header file */

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/* WdgM version check */
#if (WDGM_AR_RELEASE_MAJOR_VERSION != \
  WDGM_VERSION_AR_RELEASE_MAJOR_VERSION)
  #error "WdgM.h : Mismatch in Specification Major Version"
#endif
#if (WDGM_AR_RELEASE_MINOR_VERSION != \
  WDGM_VERSION_AR_RELEASE_MINOR_VERSION)
  #error "WdgM.h : Mismatch in Specification Minor Version"
#endif
#if (WDGM_AR_RELEASE_REVISION_VERSION != \
  WDGM_VERSION_AR_RELEASE_REVISION_VERSION)
  #error "WdgM.h : Mismatch in Specification Revision Version"
#endif
#if (WDGM_SW_MAJOR_VERSION != WDGM_VERSION_SW_MAJOR_VERSION)
  #error "WdgM.h : Mismatch in Software Major Version"
#endif
#if (WDGM_SW_MINOR_VERSION != WDGM_VERSION_SW_MINOR_VERSION)
  #error "WdgM.h : Mismatch in Software Minor Version"
#endif
#if (WDGM_SW_PATCH_VERSION != WDGM_VERSION_SW_PATCH_VERSION)
  #error "WdgM.h : Mismatch in Software Patch Version"
#endif

/* WdgIf version check */
#if defined(WDGIF_AR_RELEASE_MAJOR_VERSION) \
  && defined(WDGIF_AR_RELEASE_MINOR_VERSION)
#if (WDGIF_AR_RELEASE_MAJOR_VERSION != WDGM_WDGIF_AR_RELEASE_MAJOR_VERSION)
  #error "WdgIf.h : Mismatch in Specification Major Version"
#endif
#if (WDGIF_AR_RELEASE_MINOR_VERSION != WDGM_WDGIF_AR_RELEASE_MINOR_VERSION)
  #error "WdgIf.h : Mismatch in Specification Minor Version"
#endif
#endif

/* Mcu version check */
#if defined(MCU_AR_RELEASE_MAJOR_VERSION) \
  && defined(MCU_AR_RELEASE_MINOR_VERSION)
#if (MCU_AR_RELEASE_MAJOR_VERSION != WDGM_MCU_AR_RELEASE_MAJOR_VERSION)
  #error "Mcu.h : Mismatch in Specification Major Version"
#endif
#if (MCU_AR_RELEASE_MINOR_VERSION != WDGM_MCU_AR_RELEASE_MINOR_VERSION)
  #error "Mcu.h : Mismatch in Specification Minor Version"
#endif
#endif

/* DET Version check */
#if (WDGM_DEV_ERROR_DETECT == STD_ON)
#if defined(DET_AR_RELEASE_MAJOR_VERSION) \
  && defined(DET_AR_RELEASE_MINOR_VERSION)
#if (DET_AR_RELEASE_MAJOR_VERSION != WDGM_DET_AR_RELEASE_MAJOR_VERSION)
  #error "Det.h : Mismatch in Specification Major Version"
#endif
#if (DET_AR_RELEASE_MINOR_VERSION != WDGM_DET_AR_RELEASE_MINOR_VERSION)
  #error "Det.h : Mismatch in Specification Minor Version"
#endif
#endif
#endif /* #if(WDGM_DEV_ERROR_DETECT == STD_ON) */

/* DEM Version check */
#if(WDGM_DEM_ERROR_REPORT == STD_ON)
#if defined(DEM_AR_RELEASE_MAJOR_VERSION) \
  && defined(DEM_AR_RELEASE_MINOR_VERSION)
#if (DEM_AR_RELEASE_MAJOR_VERSION != WDGM_DEM_AR_RELEASE_MAJOR_VERSION)
  #error "Dem.h : Mismatch in Specification Major Version"
#endif
#if (DEM_AR_RELEASE_MINOR_VERSION != WDGM_DEM_AR_RELEASE_MINOR_VERSION)
  #error "Dem.h : Mismatch in Specification Minor Version"
#endif
#endif
#endif /* #if(WDGM_DEM_ERROR_REPORT == STD_ON) */

/* RTE Version check */
#if defined(RTE_AR_RELEASE_MAJOR_VERSION) \
  && defined(RTE_AR_RELEASE_MINOR_VERSION)
#if (RTE_AR_RELEASE_MAJOR_VERSION != WDGM_RTE_AR_RELEASE_MAJOR_VERSION)
  #error "Rte.h : Mismatch in Rte Specification Major Version"
#endif
#if (RTE_AR_RELEASE_MINOR_VERSION != WDGM_RTE_AR_RELEASE_MINOR_VERSION)
  #error "Rte.h : Mismatch in Rte Specification Minor Version"
#endif
#endif

/* BswM version check */
#if defined(BSWM_AR_RELEASE_MAJOR_VERSION) \
  && defined(BSWM_AR_RELEASE_MINOR_VERSION)
#if (BSWM_AR_RELEASE_MAJOR_VERSION != WDGM_BSWM_AR_RELEASE_MAJOR_VERSION)
  #error "BswM.h : Mismatch in Specification Major Version"
#endif
#if (BSWM_AR_RELEASE_MINOR_VERSION != WDGM_BSWM_AR_RELEASE_MINOR_VERSION)
  #error "BswM.h : Mismatch in Specification Minor Version"
#endif
#endif

/* OS version check */
#if defined(OS_AR_RELEASE_MAJOR_VERSION) \
  && defined(OS_AR_RELEASE_MINOR_VERSION)
#if (OS_AR_RELEASE_MAJOR_VERSION != WDGM_OS_AR_RELEASE_MAJOR_VERSION)
  #error "Os.h : Mismatch in Specification Major Version"
#endif
#if (OS_AR_RELEASE_MINOR_VERSION != WDGM_OS_AR_RELEASE_MINOR_VERSION)
  #error "Os.h : Mismatch in Specification Minor Version"
#endif
#endif

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
