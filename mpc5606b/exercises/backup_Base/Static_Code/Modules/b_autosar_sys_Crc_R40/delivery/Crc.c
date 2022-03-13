/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Crc.c                                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Crc Library Module                                    **
**                                                                            **
**  PURPOSE   : Implementation of Version Information for CRC Library Module  **
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
**                      Include Section                                       **
*******************************************************************************/
#include "Crc.h"                       /* Crc Header file */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CRC_C_AR_RELEASE_MAJOR_VERSION      4
#define CRC_C_AR_RELEASE_MINOR_VERSION      0
#define CRC_C_AR_RELEASE_REVISION_VERSION   3

/* Software Version Information*/
#define CRC_C_SW_MAJOR_VERSION      1
#define CRC_C_SW_MINOR_VERSION      0
#define CRC_C_SW_PATCH_VERSION      0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if(CRC_AR_RELEASE_MAJOR_VERSION != CRC_C_AR_RELEASE_MAJOR_VERSION)
  #error "Crc.c : Mismatch in Specification Major Version"
#endif

#if(CRC_AR_RELEASE_MINOR_VERSION != CRC_C_AR_RELEASE_MINOR_VERSION)
  #error "Crc.c : Mismatch in Specification Minor Version"
#endif

#if(CRC_AR_RELEASE_REVISION_VERSION != CRC_C_AR_RELEASE_REVISION_VERSION)
  #error "Crc.c : Mismatch in Specification Revision Version"
#endif

#if(CRC_SW_MAJOR_VERSION != CRC_C_SW_MAJOR_VERSION)
  #error "Crc.c : Mismatch in Major version"
#endif

#if(CRC_SW_MINOR_VERSION != CRC_C_SW_MINOR_VERSION)
  #error "Crc.c : Mismatch in Minor version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Crc_GetVersionInfo                                  **
**                                                                            **
** Service ID           : 0x04                                                **
**                                                                            **
** Description          : This function returns the version information of CRC**
**                        Library module.                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Versioninfo                                         **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "MemMap.h"
FUNC(void, CRC_CODE) Crc_GetVersionInfo
  (P2VAR(Std_VersionInfoType, AUTOMATIC, CRC_APPL_DATA) Versioninfo)
{
  if(Versioninfo != NULL_PTR)
  {
    /* Copy the vendor Id */
    Versioninfo->vendorID = CRC_VENDOR_ID;
    /* Copy the module Id */
    Versioninfo->moduleID = CRC_MODULE_ID;
    /* Copy Software Major Version */
    Versioninfo->sw_major_version = CRC_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    Versioninfo->sw_minor_version = CRC_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    Versioninfo->sw_patch_version = CRC_SW_PATCH_VERSION;
  } /* if(Versioninfo != NULL_PTR) */

  /* If the received Versioninfo pointer is NULL it shall return from the
  Crc_GetVersionInfo API without performing any further functionality. */
}
#define CRC_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
