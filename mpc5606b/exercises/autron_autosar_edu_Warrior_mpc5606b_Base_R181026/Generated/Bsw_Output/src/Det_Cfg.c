/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME: Det_Cfg.c                                                      **
**                                                                            **
**  MODULE-NAME: AUTOSAR DET Module                                           **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 1.0.5                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/

/*
 * INPUT FILE:    Configuration\ECU\Ecud_Det.arxml
 * GENERATED ON:  This timestamp is removed.
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Det.h"
#include "Det_PCTypes.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define DET_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array of Function Pointers for Error Hook */
CONST(Det_FuncPtrType, DET_CONST) Det_GaaErrorHook[DET_TOTAL_ERROR_HOOKS] = {
Det_ErrorHook
};
#define DET_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
