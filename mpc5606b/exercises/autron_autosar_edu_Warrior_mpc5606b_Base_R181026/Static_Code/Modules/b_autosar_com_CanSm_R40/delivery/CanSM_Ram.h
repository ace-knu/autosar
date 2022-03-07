/*******************************************************************************
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.								          **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanSM_Ram.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN State Manager Module                              **
**                                                                            **
**  PURPOSE   : Provision of declaration of RAM area.                         **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 1.10.0    27-Oct-2016   Lim Jong Sun   #7048                               **
** 1.9.4     11-Sep-2015   Lim Jong Sun   Fixed MISRA-C Violation             **
** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
*******************************************************************************/
#ifndef CANSM_RAM_H
#define CANSM_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanSM_PCTypes.h"        /* Inclusion of CanSM Pctypes header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANSM_RAM_H_AR_RELEASE_MAJOR_VERSION         4
#define CANSM_RAM_H_AR_RELEASE_MINOR_VERSION         0
#define CANSM_RAM_H_AR_RELEASE_REVISION_VERSION      3

/* Software Version Information */
#define CANSM_RAM_H_SW_MAJOR_VERSION                 1
#define CANSM_RAM_H_SW_MINOR_VERSION                 10

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#if (STD_ON == CANSM_DEV_ERROR_DETECT)
#define CANSM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* Memmap header file */
/* Global variable to store initialization status of CANSM Module */
extern VAR(boolean, CANSM_VAR) CanSM_GblInitStatus;
#define CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* Memmap header file */
#endif

#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* Memmap header file */
extern VAR(Tdd_CanSM_Network, CANSM_VAR) CanSM_GaaNetwork[CANSM_NUMBER_OF_NETWORKS];
#define CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* Memmap header file */

/* Global function pointer array */
#define CANSM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#if (STD_ON == CANSM_PN_AVAILABILITY)
extern CONST(CanSM_TransFuncPtr, CANSM_CONST) CanSM_TransFuncPtrType[13];
#else
extern CONST(CanSM_TransFuncPtr, CANSM_CONST) CanSM_TransFuncPtrType[11];	
#endif
#define CANSM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (STD_ON == CANSM_CANTRCV_SUPPORT)
#define CANSM_START_SEC_CONST_8
#include "MemMap.h"
extern CONST(uint8, CANTRCV_CONST) CanSm_GucLastTrcvHandle;
#define CANSM_STOP_SEC_CONST_8
#include "MemMap.h"
#endif

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#endif /* CANSM_RAM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

