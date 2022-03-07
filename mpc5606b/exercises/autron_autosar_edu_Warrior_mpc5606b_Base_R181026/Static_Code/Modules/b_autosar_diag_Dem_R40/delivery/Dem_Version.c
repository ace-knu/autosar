/*******************************************************************************
**  (C) 2014 Hyundai Autron Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Dem_Version.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Dem Module                                            **
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
** 1.1.1    20-07-2017     EunKyung.Kim   Changes made As per Redmine #9294   **
**                                                                            **
** 1.1.0    30-09-2016     YoungJin.Yun   Changes made As per Redmine #5921   **
**                                                                            **
** 1.0.0     01-Jan-2013   Autron       Initial Version                       **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem.h"
#include "Dem_Version.h"        /* Dem Version Header File */

#include "NvM.h"              /* NVRAM Header File */
#include "Rte.h"
#if (DEM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"              /* DET header file */
#endif
#if (DEM_TRIGGER_DCM_REPORTS == STD_ON)
#include "Dcm.h"
#endif
#if (DEM_FIM_INTEGRATED == STD_ON)
#include "FiM.h"
#endif
#if (DEM_TRIGGER_DLT_REPORTS == STD_ON)
#include "Dlt.h"
#endif
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define DEM_VERSION_C_MAJOR_VERSION     4
#define DEM_VERSION_C_MINOR_VERSION     0
#define DEM_VERSION_C_REVISION_VERSION  3

/* Software Version Information */
#define DEM_VERSION_C_SW_MAJOR_VERSION     1
#define DEM_VERSION_C_SW_MINOR_VERSION     0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (DEM_VERSION_AR_MAJOR_VERSION != \
  DEM_VERSION_C_MAJOR_VERSION)
  #error "Dem_Version.c : Mismatch in Specification Major Version"
#endif

#if (DEM_VERSION_AR_MINOR_VERSION != \
  DEM_VERSION_C_MINOR_VERSION)
  #error "Dem_Version.c : Mismatch in Specification Minor Version"
#endif

#if (DEM_VERSION_AR_REVISION_VERSION != \
  DEM_VERSION_C_REVISION_VERSION)
  #error "Dem_Version.c : Mismatch in Specification Revision Version"
#endif

#if (DEM_VERSION_SW_MAJOR_VERSION != DEM_VERSION_C_SW_MAJOR_VERSION)
  #error "Dem_Version.c : Mismatch in Major Version"
#endif

#if (DEM_VERSION_SW_MINOR_VERSION != DEM_VERSION_C_SW_MINOR_VERSION)
  #error "Dem_Version.c : Mismatch in Minor Version"
#endif

#if (DEM_DEV_ERROR_DETECT == STD_ON)
#if (DET_AR_RELEASE_MAJOR_VERSION != DEM_DET_AR_RELEASE_MAJOR_VERSION)
  #error "Det.h : Mismatch in Specification Major Version"
#endif

#if (DET_AR_RELEASE_MINOR_VERSION != DEM_DET_AR_RELEASE_MINOR_VERSION)
  #error "Det.h : Mismatch in Specification Minor Version"
#endif
#endif


#if (RTE_AR_RELEASE_MAJOR_VERSION != DEM_RTE_AR_RELEASE_MAJOR_VERSION)
  #error "Rte.h : Mismatch in Specification Major Version"
#endif

#if (RTE_AR_RELEASE_MINOR_VERSION != DEM_RTE_AR_RELEASE_MINOR_VERSION)
  #error "Rte.h : Mismatch in Specification Minor Version"
#endif

#if (DEM_TRIGGER_DCM_REPORTS == STD_ON)
#if (DCM_AR_RELEASE_MAJOR_VERSION != DEM_DCM_AR_RELEASE_MAJOR_VERSION)
  #error "Dcm.h : Mismatch in Specification Major Version"
#endif

#if (DCM_AR_RELEASE_MINOR_VERSION != DEM_DCM_AR_RELEASE_MINOR_VERSION)
  #error "Dcm.h : Mismatch in Specification Minor Version"
#endif
#endif

#if (DEM_FIM_INTEGRATED == STD_ON)
#if (FIM_AR_RELEASE_MAJOR_VERSION != DEM_FIM_AR_RELEASE_MAJOR_VERSION)
  #error "FiM.h : Mismatch in Specification Major Version"
#endif

#if (FIM_AR_RELEASE_MINOR_VERSION != DEM_FIM_AR_RELEASE_MINOR_VERSION)
  #error "FiM.h : Mismatch in Specification Minor Version"
#endif
#endif

#if (DEM_TRIGGER_DLT_REPORTS == STD_ON)
#if (DLT_AR_RELEASE_MAJOR_VERSION != DEM_DLT_AR_RELEASE_MAJOR_VERSION)
  #error "Dlt.h : Mismatch in Specification Major Version"
#endif

#if (DLT_AR_RELEASE_MINOR_VERSION != DEM_DLT_AR_RELEASE_MINOR_VERSION)
  #error "Dlt.h : Mismatch in Specification Minor Version"
#endif
#endif
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
