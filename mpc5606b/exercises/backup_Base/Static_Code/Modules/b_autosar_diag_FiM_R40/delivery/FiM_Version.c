/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: FiM_Version.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Function Inhibition Manager Module                    **
**                                                                            **
**  PURPOSE   : Provision of FiM Module Version information                   **
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

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem.h"                      /* Dem Header File */
#include "FiM.h"              /* FiM Version Definition Header File */
#if(FIM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"                      /* Det Header file */
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define FIM_VERSION_C_AR_RELEASE_MAJOR_VERSION  4
#define FIM_VERSION_C_AR_RELEASE_MINOR_VERSION  0
#define FIM_VERSION_C_AR_RELEASE_REVISION_VERSION  3

/* FiM Software Version Information */
#define FIM_VERSION_C_SW_MAJOR_VERSION  1
#define FIM_VERSION_C_SW_MINOR_VERSION  0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/* FiM Version Check */
#if (FIM_VERSION_AR_RELEASE_MAJOR_VERSION != \
  FIM_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "FiM_Version.c : Mismatch in Specification Major Version"
#endif
#if (FIM_VERSION_AR_RELEASE_MINOR_VERSION != \
  FIM_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "FiM_Version.c : Mismatch in Specification Minor Version"
#endif
#if (FIM_VERSION_AR_RELEASE_REVISION_VERSION != \
  FIM_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "FiM_Version.c : Mismatch in Specification Patch Version"
#endif
#if (FIM_VERSION_SW_MAJOR_VERSION != FIM_VERSION_C_SW_MAJOR_VERSION)
  #error "FiM_Version.c : Mismatch in Major Version"
#endif
#if (FIM_VERSION_SW_MINOR_VERSION != FIM_VERSION_C_SW_MINOR_VERSION)
  #error "FiM_Version.c : Mismatch in Minor Version"
#endif

/* Dem version check */
#if (DEM_AR_RELEASE_MAJOR_VERSION != FIM_DEM_AR_RELEASE_MAJOR_VERSION)
  #error "Dem.h : Mismatch in Specification Major Version"
#endif
#if (DEM_AR_RELEASE_MINOR_VERSION != FIM_DEM_AR_RELEASE_MINOR_VERSION)
  #error "Dem.h : Mismatch in Specification Minor Version"
#endif

/* Det version check */
#if (FIM_DEV_ERROR_DETECT == STD_ON)
 #if (DET_AR_RELEASE_MAJOR_VERSION != FIM_DET_AR_RELEASE_MAJOR_VERSION)
   #error "Det.h : Mismatch in Specification Major Version"
 #endif
 #if (DET_AR_RELEASE_MINOR_VERSION != FIM_DET_AR_RELEASE_MINOR_VERSION)
   #error "Det.h : Mismatch in Specification Minor Version"
 #endif
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/*******************************************************************************
** Function Name    : FiM_GetVersionInfo                                     **
**                                                                           **
** Service ID       : 0x04                                                   **
**                                                                           **
** Description      : This Service returns the version information of        **
**                    Function Inhibition Manager Module.                    **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : Reentrant                                              **
**                                                                           **
** Input Parameters : None                                                   **
**                                                                           **
** InOut parameter  : None                                                   **
**                                                                           **
** Output Parameters: Std_VersionInfoType *versioninfo                       **
**                                                                           **
** Return parameter : None                                                   **
**                                                                           **
** Preconditions    : None                                                   **
**                                                                           **
** Remarks          :                                                        **
*******************************************************************************/
#if(FIM_VERSION_INFO_API == STD_ON)
#define FIM_START_SEC_CODE
#include "MemMap.h"
  FUNC (void, FIM_CODE) FiM_GetVersionInfo
    (P2VAR(Std_VersionInfoType, AUTOMATIC, FIM_APPL_DATA)versioninfo)
{
  #if(FIM_DEV_ERROR_DETECT == STD_ON)
  /* check NULL pointer */
  if(versioninfo == NULL_PTR)
  {
  /* Report to DET */
  (void)Det_ReportError(FIM_MODULE_ID, FIM_INSTANCE_ID,
    FIM_GETVERSIONINFO_SID, FIM_E_INVALID_POINTER);
  }
  else
  #endif
  {
    /* Load the vendor Id */
    versioninfo->vendorID = FIM_VENDOR_ID;
    /* Load the module Id */
    versioninfo->moduleID = FIM_MODULE_ID;
    /* Load Software Major Version */
    versioninfo->sw_major_version = FIM_SW_MAJOR_VERSION;
    /* Load Software Minor Version */
    versioninfo->sw_minor_version = FIM_SW_MINOR_VERSION;
    /* Load Software Patch Version */
    versioninfo->sw_patch_version = FIM_SW_PATCH_VERSION;
  }
}
#define FIM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* (FIM_VERSION_INFO_API == STD_ON) */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
