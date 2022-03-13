/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Com_Filter.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Com Module                                            **
**                                                                            **
**  PURPOSE   : Provision of declaration of filter functions.                 **
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
** 1.0.11    03-Mar-2014   Chan Kim    Internal Redmine #642                  **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/

#ifndef COM_FILTER_H
#define COM_FILTER_H

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COM_FILTER_AR_RELEASE_MAJOR_VERSION  4
#define COM_FILTER_AR_RELEASE_MINOR_VERSION  0
#define COM_FILTER_AR_RELEASE_REVISION_VERSION  3

/* Software Version Information */
#define COM_FILTER_SW_MAJOR_VERSION  2
#define COM_FILTER_SW_MINOR_VERSION  2

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

extern FUNC(boolean, COM_CODE) Com_FNever
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FMaskedNewEqualsX_8
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FMaskedNewEqualsX_16
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FMaskedNewEqualsX_32
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FMaskedNewDiffersX_8
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FMaskedNewDiffersX_16
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FMaskedNewDiffersX_32
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FMaskedNewDiffersMaskedOld_8
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FMaskedNewDiffersMaskedOld_16
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FMaskedNewDiffersMaskedOld_32
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FNewIsWithin_u8
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FNewIsWithin_s8
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FNewIsWithin_u16
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FNewIsWithin_s16
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FNewIsWithin_u32
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FNewIsWithin_s32
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FNewIsOutside_u8
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FNewIsOutside_s8
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FNewIsOutside_u16
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FNewIsOutside_s16
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FNewIsOutside_u32
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FNewIsOutside_s32
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_FOneEveryN
                          (P2CONST(void, AUTOMATIC, COM_CONST) LpFilter,
                      P2CONST(void, AUTOMATIC, COM_CONST) LpSigDataPtr,
                       uint8 ActivateCode);

#define COM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* COM_FILTER_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
