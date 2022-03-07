/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Det_Version.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Development Error Tracer                              **
**                                                                            **
**  PURPOSE   : This file contains declaration of functions defined in        **
**              Development Error Tracer module which are used by             **
**              the other modules.                                            **
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
** 1.0.0     01-Jan-2013   Autron          Initial Version                    **
*******************************************************************************/
#ifndef DET_VERSION_H
#define DET_VERSION_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Det_Cfg.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define DET_VERSION_AR_RELEASE_MAJOR_VERSION DET_AR_RELEASE_MAJOR_VERSION
#define DET_VERSION_AR_RELEASE_MINOR_VERSION DET_AR_RELEASE_MINOR_VERSION
#define DET_VERSION_AR_RELEASE_REVISION_VERSION DET_AR_RELEASE_REVISION_VERSION

/* DET Software Version Information */
#define DET_VERSION_SW_MAJOR_VERSION     DET_SW_MAJOR_VERSION
#define DET_VERSION_SW_MINOR_VERSION     DET_SW_MINOR_VERSION
#define DET_VERSION_SW_PATCH_VERSION     DET_SW_PATCH_VERSION

/* Rte Software Version Information */
#define DET_RTE_AR_RELEASE_MAJOR_VERSION      4
#define DET_RTE_AR_RELEASE_MINOR_VERSION      0

/* Dlt Software Version Information */
#define DET_DLT_AR_RELEASE_MAJOR_VERSION      4
#define DET_DLT_AR_RELEASE_MINOR_VERSION      0


#endif /* DET_VERSION_H */

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
