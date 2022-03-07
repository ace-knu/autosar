/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Det_Version.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Development Error Tracer                              **
**                                                                            **
**  PURPOSE   : Provision of Version information                              **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By               Description                       **
********************************************************************************
** 1.0.1     07-Mar-2013   Nitin Kumar     Global variable                    **
**                                         Det_GusErrorCount and precompile   **
**                                         option DET_ERROR_COUNT_SUPPORT     **
**                                         has been removed.                  **
** 1.0.0     01-Jan-2013   Autron          Initial Version                    **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Det.h"                /* Header file of DET */
#include "Det_Version.h"        /* Det Version header file */
#if (DET_RAM_BUFFER == STD_ON)
#include "Rte.h"                  /* Header file of RTE */
#endif
#if (DET_FORWARD_TO_DLT == STD_ON)
#include "Dlt.h"                  /* Header file of DLT */
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define DET_VERSION_C_AR_RELEASE_MAJOR_VERSION    4
#define DET_VERSION_C_AR_RELEASE_MINOR_VERSION    0
#define DET_VERSION_C_AR_RELEASE_REVISION_VERSION 3

/* FILE VERSION INFORMATION */
#define DET_VERSION_C_SW_MAJOR_VERSION            1
#define DET_VERSION_C_SW_MINOR_VERSION            0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (DET_VERSION_AR_RELEASE_MAJOR_VERSION !=\
     DET_VERSION_C_AR_RELEASE_MAJOR_VERSION)
#error "Det.c : Mismatch in Specification Major Version"
#endif

#if (DET_VERSION_AR_RELEASE_MINOR_VERSION !=\
     DET_VERSION_C_AR_RELEASE_MINOR_VERSION)
#error "Det.c : Mismatch in Specification Minor Version"
#endif

#if (DET_VERSION_AR_RELEASE_REVISION_VERSION !=\
     DET_VERSION_C_AR_RELEASE_REVISION_VERSION)
#error "Det.c : Mismatch in Specification Patch Version"
#endif

#if (DET_VERSION_SW_MAJOR_VERSION != DET_VERSION_C_SW_MAJOR_VERSION)
#error "Det_Ram.c : Mismatch in Software Major Version"
#endif
#if (DET_VERSION_SW_MINOR_VERSION != DET_VERSION_C_SW_MINOR_VERSION)
#error "Det_Ram.c : Mismatch in Software Minor Version"
#endif

/* RTE AUTOSAR Specification Version Information */
#if (DET_RAM_BUFFER == STD_ON)
#if (RTE_AR_RELEASE_MAJOR_VERSION != DET_RTE_AR_RELEASE_MAJOR_VERSION)
#error "Rte.h : Mismatch in Specification Major Version"
#endif

#if (RTE_AR_RELEASE_MINOR_VERSION != DET_RTE_AR_RELEASE_MINOR_VERSION)
#error "Rte.h : Mismatch in Specification Minor Version"
#endif

#endif

/* Dlt AUTOSAR Specification Version Information */
#if (DET_FORWARD_TO_DLT == STD_ON)
#if (DLT_AR_RELEASE_MAJOR_VERSION != DET_DLT_AR_RELEASE_MAJOR_VERSION)
#error "Dlt.h : Mismatch in Specification Major Version"
#endif

#if (DLT_AR_RELEASE_MINOR_VERSION != DET_DLT_AR_RELEASE_MINOR_VERSION)
#error "Dlt.h : Mismatch in Specification Minor Version"
#endif

#endif

/*******************************************************************************
**                      Global Types                                          **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
