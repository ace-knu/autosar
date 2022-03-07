/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR DCM                                                   **
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
** Revision  Date          By                   Description                   **
********************************************************************************
** 1.0.0     09-01-2013    Autron               Initial Version               **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Dcm_Version.h"        /* Dcm Version Header File */
#include "Dcm.h"
#include "Rte_Dcm.h"
#include "Rte.h"
#include "Dem.h"

#if(DCM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#include "SchM_Dcm.h"
#include "ComM.h"
#include "PduR.h"
#include "BswM.h"
#include "NvM.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define DCM_VERSION_C_AR_RELEASE_MAJOR_VERSION      4
#define DCM_VERSION_C_AR_RELEASE_MINOR_VERSION      0
#define DCM_VERSION_C_AR_RELEASE_REVISION_VERSION   3

/* FILE VERSION INFORMATION */
#define DCM_VERSION_C_SW_MAJOR_VERSION  1
#define DCM_VERSION_C_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (DCM_VERSION_AR_RELEASE_MAJOR_VERSION != \
                                         DCM_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "Dcm_Version : Mismatch in Specification Major Version"
#endif

#if (DCM_VERSION_AR_RELEASE_MINOR_VERSION != \
                                         DCM_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "Dcm_Version : Mismatch in Specification Minor Version"
#endif

#if (DCM_VERSION_AR_RELEASE_REVISION_VERSION != \
                                      DCM_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "Dcm_Version : Mismatch in Specification Patch Version"
#endif

#if (DCM_VERSION_SW_MAJOR_VERSION != DCM_VERSION_C_SW_MAJOR_VERSION)
  #error "Dcm_Version : Mismatch in Major Version"
#endif

#if (DCM_VERSION_SW_MINOR_VERSION != DCM_VERSION_C_SW_MINOR_VERSION)
  #error "Dcm_Version : Mismatch in Minor Version"
#endif

#if (DCM_DEV_ERROR_DETECT == STD_ON)
#if (DET_AR_RELEASE_MAJOR_VERSION != DCM_DET_AR_RELEASE_MAJOR_VERSION)
  #error "Det.h : Mismatch in Specification Major Version"
#endif

#if (DET_AR_RELEASE_MINOR_VERSION != DCM_DET_AR_RELEASE_MINOR_VERSION)
  #error "Det.h : Mismatch in Specification Minor Version"
#endif
#endif

#if (RTE_AR_RELEASE_MAJOR_VERSION != DCM_RTE_AR_RELEASE_MAJOR_VERSION)
  #error "Rte.h : Mismatch in Specification Major Version"
#endif

#if (RTE_AR_RELEASE_MINOR_VERSION != DCM_RTE_AR_RELEASE_MINOR_VERSION)
  #error "Rte.h : Mismatch in Specification Minor Version"
#endif

#if (DEM_AR_RELEASE_MAJOR_VERSION != DCM_DEM_AR_RELEASE_MAJOR_VERSION)
  #error "Dem.h : Mismatch in Specification Major Version"
#endif

#if (DEM_AR_RELEASE_MINOR_VERSION != DCM_DEM_AR_RELEASE_MINOR_VERSION)
  #error "Dem.h : Mismatch in Specification Minor Version"
#endif

#if (COMM_AR_RELEASE_MAJOR_VERSION != DCM_COMM_AR_RELEASE_MAJOR_VERSION)
  #error "ComM.h : Mismatch in Specification Major Version"
#endif

#if (COMM_AR_RELEASE_MINOR_VERSION != DCM_COMM_AR_RELEASE_MINOR_VERSION)
  #error "ComM.h : Mismatch in Specification Minor Version"
#endif

#if (PDUR_AR_RELEASE_MAJOR_VERSION != DCM_PDUR_AR_RELEASE_MAJOR_VERSION)
  #error "PduR.h : Mismatch in Specification Major Version"
#endif

#if (PDUR_AR_RELEASE_MINOR_VERSION != DCM_PDUR_AR_RELEASE_MINOR_VERSION)
  #error "PduR.h : Mismatch in Specification Minor Version"
#endif

#if (BSWM_AR_RELEASE_MAJOR_VERSION != DCM_BSWM_AR_RELEASE_MAJOR_VERSION)
  #error "BswM.h : Mismatch in Specification Major Version"
#endif

#if (BSWM_AR_RELEASE_MINOR_VERSION != DCM_BSWM_AR_RELEASE_MINOR_VERSION)
  #error "BswM.h : Mismatch in Specification Minor Version"
#endif

#if (NVM_AR_RELEASE_MAJOR_VERSION != DCM_NVM_AR_RELEASE_MAJOR_VERSION)
  #error "NvM.h : Mismatch in Specification Major Version"
#endif

#if (NVM_AR_RELEASE_MINOR_VERSION != DCM_NVM_AR_RELEASE_MINOR_VERSION)
  #error "NvM.h : Mismatch in Specification Minor Version"
#endif

#if 0
#if (IOHWAB_AR_RELEASE_MAJOR_VERSION != DCM_IOHWAB_AR_RELEASE_MAJOR_VERSION)
  #error "IoHwAb.h : Mismatch in Specification Major Version"
#endif

#if (IOHWAB_AR_RELEASE_MINOR_VERSION != DCM_IOHWAB_AR_RELEASE_MINOR_VERSION)
  #error "IoHwAb.h : Mismatch in Specification Minor Version"
#endif
#endif
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
