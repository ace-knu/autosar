/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Com_UnPack.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Com Module                                            **
**                                                                            **
**  PURPOSE   : Provision of declaration of unpack functions.                 **
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
** 1.0.17    27-Feb-2015   Chan Kim    Internal Redmine #2271                 **
** 1.0.11    03-Mar-2014   Chan Kim    Internal Redmine #642                  **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */

#ifndef COM_UNPACK_H
#define COM_UNPACK_H

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COM_UNPACK_AR_RELEASE_MAJOR_VERSION  4
#define COM_UNPACK_AR_RELEASE_MINOR_VERSION  0
#define COM_UNPACK_AR_RELEASE_REVISION_VERSION  3

/* Software Version Information */
#define COM_UNPACK_SW_MAJOR_VERSION  2
#define COM_UNPACK_SW_MINOR_VERSION  2

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_UnPackOneByte
             (P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST)LpRxUnpack,
                          P2VAR(void, AUTOMATIC, COM_VAR)LpSigDataPtr);

#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_UnPackBytes
             (P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST)LpRxUnpack,
                          P2VAR(void, AUTOMATIC, COM_VAR)LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"


#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_UnPackFiveBytes
             (P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST)LpRxUnpack,
                          P2VAR(void, AUTOMATIC, COM_VAR)LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_UnPackNBytes
             (P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST)LpRxUnpack,
                          P2VAR(void, AUTOMATIC, COM_VAR)LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_UnPackFiveByteOrdering
             (P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST)LpRxUnpack,
                          P2VAR(void, AUTOMATIC, COM_VAR)LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_UnPackByteOrdering
             (P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST)LpRxUnpack,
                          P2VAR(void, AUTOMATIC, COM_VAR)LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_UnPackEightByteOrdering
(P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST)LpRxUnpack,
                           P2VAR(void, AUTOMATIC, COM_VAR)LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_UnPackEightBytes
(P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST)LpRxUnpack,
                           P2VAR(void, AUTOMATIC, COM_VAR)LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_UnPackNineByteOrdering
(P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST)LpRxUnpack,
                           P2VAR(void, AUTOMATIC, COM_VAR)LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_UnPackNineBytes
(P2CONST(Com_RxUnpack, AUTOMATIC, COM_CONST)LpRxUnpack,
                           P2VAR(void, AUTOMATIC, COM_VAR)LpSigDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"





#endif /* COM_UNPACK_H */
/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

