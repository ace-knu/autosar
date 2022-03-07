/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Com_Version.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR COM Module                                            **
**                                                                            **
**  PURPOSE   : Provision of Version Information.                             **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By          Description                            **
********************************************************************************
** 2.2.0     16-Apr-2017   Chan Kim    Internal Redmine #7525                 **
** 2.1.0     25-May-2016   Chan Kim    Internal Redmine #4998                 **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Com.h"                 /* Com module header file */
#include "Com_Version.h"         /* Com version header file */

#if(COM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"                 /* Det module header file */
#endif

#include "PduR.h"                /* PduR module header file */
#include "Rte.h"                 /* Rte module header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COM_VERSION_C_AR_RELEASE_MAJOR_VERSION       4
#define COM_VERSION_C_AR_RELEASE_MINOR_VERSION       0
#define COM_VERSION_C_AR_RELEASE_REVISION_VERSION    3

/* Software Version Information */
#define COM_VERSION_C_SW_MAJOR_VERSION  2
#define COM_VERSION_C_SW_MINOR_VERSION  2

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if(COM_AR_RELEASE_MAJOR_VERSION != COM_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "Com_Version.c : Mismatch in Com Specification Major Version"
#endif

#if(COM_AR_RELEASE_MINOR_VERSION != COM_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "Com_Version.c : Mismatch in Com Specification Minor Version"
#endif

#if(COM_AR_RELEASE_REVISION_VERSION != \
  COM_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "Com_Version.c : Mismatch in Com Specification Revision Version"
#endif

#if(COM_SW_MAJOR_VERSION != COM_VERSION_C_SW_MAJOR_VERSION)
  #error "Com_Version.c : Mismatch in Com Software Major Version"
#endif

#if(COM_SW_MINOR_VERSION != COM_VERSION_C_SW_MINOR_VERSION)
  #error "Com_Version.c : Mismatch in Com Software Minor Version"
#endif

#if(COM_DEV_ERROR_DETECT == STD_ON)
  #if(DET_AR_RELEASE_MAJOR_VERSION != COM_DET_AR_RELEASE_MAJOR_VERSION)
    #error "Det.h : Mismatch in Det Specification Major Version"
  #endif

  #if(DET_AR_RELEASE_MINOR_VERSION != COM_DET_AR_RELEASE_MINOR_VERSION)
    #error "Det.h : Mismatch in Det Specification Minor Version"
  #endif
#endif /* COM_DEV_ERROR_DETECT */

#if(PDUR_AR_RELEASE_MAJOR_VERSION != COM_PDUR_AR_RELEASE_MAJOR_VERSION)
  #error "PduR.h : Mismatch in PduR Specification Major Version"
#endif

#if(PDUR_AR_RELEASE_MINOR_VERSION != COM_PDUR_AR_RELEASE_MINOR_VERSION)
  #error "PduR.h : Mismatch in PduR Specification Minor Version"
#endif

#if(RTE_AR_RELEASE_MAJOR_VERSION != COM_RTE_AR_RELEASE_MAJOR_VERSION)
  #error "Rte.h : Mismatch in Rte Specification Major Version"
#endif

#if(RTE_AR_RELEASE_MINOR_VERSION != COM_RTE_AR_RELEASE_MINOR_VERSION)
  #error "Rte.h : Mismatch in Rte Specification Minor Version"
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
