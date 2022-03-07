/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: PduR_Version.c                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR PDU Router                                            **
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
** Revision  Date          By          Description                            **
********************************************************************************
** 2.2.0     01-Feb-2017   Chan Kim    Redmine #6922                          **
** 2.1.0     17-Jun-2016   Chan Kim    Redmine #5190                          **
** 2.0.3     24-Nov-2015   Chan Kim    Redmine #3545, #4519                   **
** 2.0.0     11-Aug-2015   Chan Kim    Redmine #2949                          **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR.h"           /* Generated Header File */
#include "PduR_Cfg.h"           /* Generated Header File */
#include "PduR_Version.h"       /* PduR Version Header File */
#include "PduR_Incl.h"          /* PduR Inclusion Header File */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#if (PDUR_AR_RELEASE_MAJOR_VERSION != PDUR_VERSION_AR_RELEASE_MAJOR_VERSION)
#error "PduR_Version.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_AR_RELEASE_MINOR_VERSION != PDUR_VERSION_AR_RELEASE_MINOR_VERSION)
#error "PduR_Version.c : Mismatch in Specification Minor Version"
#endif
#if (PDUR_AR_RELEASE_REVISION_VERSION !=\
     PDUR_VERSION_AR_RELEASE_REVISION_VERSION)
#error "PduR_Version.c : Mismatch in Specification Revision Version"
#endif

/* Software Version Information */
#if (PDUR_SW_MAJOR_VERSION != PDUR_VERSION_SW_MAJOR_VERSION)
#error "PduR_Version.c : Mismatch in software Major Version"
#endif
#if (PDUR_SW_MINOR_VERSION != PDUR_VERSION_SW_MINOR_VERSION)
#error "PduR_Version.c : Mismatch in software Minor Version"
#endif

/* CanIf Version check*/
#if (PDUR_CANIF_SUPPORT == STD_ON)
#if (CANIF_AR_RELEASE_MAJOR_VERSION != PDUR_CANIF_AR_RELEASE_MAJOR_VERSION)
#error "CanIf.h : Mismatch in Specification Major Version"
#endif

#if (CANIF_AR_RELEASE_MINOR_VERSION != PDUR_CANIF_AR_RELEASE_MINOR_VERSION)
#error "CanIf.h : Mismatch in Specification Minor Version"
#endif
#endif /* End of if (PDUR_CANIF_SUPPORT == STD_ON) */

/* LinIf Version Check */
#if (PDUR_LINIF_SUPPORT == STD_ON)
#if (LINIF_AR_RELEASE_MAJOR_VERSION != PDUR_LINIF_AR_RELEASE_MAJOR_VERSION)
#error "LinIf.h : Mismatch in Specification Major Version"
#endif

#if (LINIF_AR_RELEASE_MINOR_VERSION != PDUR_LINIF_AR_RELEASE_MINOR_VERSION)
#error "LinIf.h : Mismatch in Specification Minor Version"
#endif
#endif /* End of if (PDUR_LINIF_SUPPORT == STD_ON) */

/* FrIf version check */
#if (PDUR_FRIF_SUPPORT == STD_ON)
#if (FRIF_AR_RELEASE_MAJOR_VERSION != PDUR_FRIF_AR_RELEASE_MAJOR_VERSION)
#error "FrIf.h : Mismatch in Specification Major Version"
#endif

#if (FRIF_AR_RELEASE_MINOR_VERSION != PDUR_FRIF_AR_RELEASE_MINOR_VERSION)
#error "FrIf.h : Mismatch in Specification Minor Version"
#endif
#endif /* End of if (PDUR_FRIF_SUPPORT == STD_ON) */

/* CanTp Version check */
#if (PDUR_CANTP_SUPPORT == STD_ON)
#if (CANTP_AR_RELEASE_MAJOR_VERSION != PDUR_CANTP_AR_RELEASE_MAJOR_VERSION)
#error "CanTp.h : Mismatch in Specification Major Version"
#endif

#if (CANTP_AR_RELEASE_MINOR_VERSION != PDUR_CANTP_AR_RELEASE_MINOR_VERSION)
#error "CanTp.h : Mismatch in Specification Minor Version"
#endif
#endif /* End of if (PDUR_CANTP_SUPPORT == STD_ON) */

/* FrTp Version check */
#if (PDUR_FRTP_SUPPORT == STD_ON)
#if (FRTP_AR_RELEASE_MAJOR_VERSION != PDUR_FRTP_AR_RELEASE_MAJOR_VERSION)
#error "FrTp.h : Mismatch in Specification Major Version"
#endif

#if (FRTP_AR_RELEASE_MINOR_VERSION != PDUR_FRTP_AR_RELEASE_MINOR_VERSION)
#error "FrTp.h : Mismatch in Specification Minor Version"
#endif
#endif /* End of if (PDUR_FRTP_SUPPORT == STD_ON) */

/* Com Version check */
#if (PDUR_COM_SUPPORT == STD_ON)
#if (COM_AR_RELEASE_MAJOR_VERSION != PDUR_COM_AR_RELEASE_MAJOR_VERSION)
#error "Com.h : Mismatch in Specification Major Version"
#endif

#if (COM_AR_RELEASE_MINOR_VERSION != PDUR_COM_AR_RELEASE_MINOR_VERSION)
#error "Com.h : Mismatch in Specification Minor Version"
#endif
#endif /* End of if (PDUR_COM_SUPPORT == STD_ON) */

/* Dcm Version check */
#if (PDUR_DCM_SUPPORT == STD_ON)
#if (DCM_AR_RELEASE_MAJOR_VERSION != PDUR_DCM_AR_RELEASE_MAJOR_VERSION)
#error "Dcm.h : Mismatch in Specification Major Version"
#endif

#if (DCM_AR_RELEASE_MINOR_VERSION != PDUR_DCM_AR_RELEASE_MINOR_VERSION)
#error "Dcm.h : Mismatch in Specification Minor Version"
#endif
#endif /* End of if (PDUR_DCM_SUPPORT == STD_ON) */

/* IpduM Version check */
#if (PDUR_IPDUM_SUPPORT == STD_ON)
#if (IPDUM_AR_RELEASE_MAJOR_VERSION != PDUR_IPDUM_AR_RELEASE_MAJOR_VERSION)
#error "Ipdum.h : Mismatch in Specification Major Version"
#endif

#if (IPDUM_AR_RELEASE_MINOR_VERSION != PDUR_IPDUM_AR_RELEASE_MINOR_VERSION)
#error "Ipdum.h : Mismatch in Specification Minor Version"
#endif
#endif /* End of if (PDUR_IPDUM_SUPPORT == STD_ON) */

/* DET Version check */
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
#if (DET_AR_RELEASE_MAJOR_VERSION != PDUR_DET_AR_RELEASE_MAJOR_VERSION)
#error "Det.h : Mismatch in Specification Major Version"
#endif

#if (DET_AR_RELEASE_MINOR_VERSION != PDUR_DET_AR_RELEASE_MINOR_VERSION)
#error "Det.h : Mismatch in Specification Minor Version"
#endif
#endif  /* End of if (PDUR_DEV_ERROR_DETECT == STD_ON) */

/* FrNm Version check */
#if (PDUR_FRNM_SUPPORT == STD_ON)
#if (FRNM_AR_RELEASE_MAJOR_VERSION != PDUR_FRNM_AR_RELEASE_MAJOR_VERSION)
#error "FrNm.h : Mismatch in Specification Major Version"
#endif

#if (FRNM_AR_RELEASE_MINOR_VERSION != PDUR_FRNM_AR_RELEASE_MINOR_VERSION)
#error "FrNm.h : Mismatch in Specification Minor Version"
#endif
#endif /* End of if (PDUR_FRNM_SUPPORT == STD_ON) */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
