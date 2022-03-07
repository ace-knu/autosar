/*******************************************************************************
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.								          **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanSM_ComM.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN State Manager Module                              **
**                                                                            **
**  PURPOSE   : Provision of declaration of initialization function           **
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
** 1.10.0    27-Oct-2016   Lim Jong Sun   #7076                               **
** 1.9.4     11-Sep-2015   Lim Jong Sun   Fixed MISRA-C Violation             **
** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
*******************************************************************************/
#ifndef CANSM_COMM_H
#define CANSM_COMM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/*	polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations>
		No Impact of this rule violation										  */
#include "Rte_Type.h"                 /* ComM header file */



/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANSM_COMM_H_AR_RELEASE_MAJOR_VERSION         4
#define CANSM_COMM_H_AR_RELEASE_MINOR_VERSION         0
#define CANSM_COMM_H_AR_RELEASE_REVISION_VERSION      3

/* Software Version Information */
#define CANSM_COMM_H_SW_MAJOR_VERSION                 1
#define CANSM_COMM_H_SW_MINOR_VERSION                 10

/*******************************************************************************
**                  Global Data Types                                         **
*******************************************************************************/

/*******************************************************************************
**                Function Prototypes                                         **
*******************************************************************************/



#define CANSM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_RequestComMode(NetworkHandleType
  NetworkHandle, ComM_ModeType ComM_Mode);

extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_GetCurrentComMode(
  NetworkHandleType NetworkHandle, P2VAR(ComM_ModeType, AUTOMATIC,
    CANSM_APPL_DATA) ComM_ModePtr);

#define CANSM_STOP_SEC_CODE
#include "MemMap.h" /* Memmap header file */
/*  polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations>
    No Impact of this rule violation                                          */

#endif /* CANSM_COMM_H */

/*******************************************************************************
**                   End of File                                              **
*******************************************************************************/

