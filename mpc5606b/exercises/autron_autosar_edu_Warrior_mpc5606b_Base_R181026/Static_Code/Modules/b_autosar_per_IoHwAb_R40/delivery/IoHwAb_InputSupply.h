/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IoHwAb_InputSupply.h                                          **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IOHWAB                                                **
**                                                                            **
**  PURPOSE   : C header for Input Supply                                     **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By         Description                             **
********************************************************************************
** 1.0.1     22-Jul-2016   Jongyoung  #5219                                   **
*******************************************************************************/

#ifndef IOHWAB_INPUTSUPPLY_H
#define IOHWAB_INPUTSUPPLY_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IoHwAb.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if (IOHWAB_USE_IN_SUP_SWT == STD_ON)
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_InputSupplyInit(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#if (IOHWAB_USE_DIG_IN == STD_ON)
#if (IOHWAB_USE_DIG_SUP_SWT == STD_ON)
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_InputSupplyDigitalControl(
  boolean blHp, boolean blOn);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"
#endif /* (IOHWAB_USE_DIG_SUP_SWT == STD_ON) */
#endif /* (IOHWAB_USE_DIG_IN == STD_ON)*/

#if (IOHWAB_USE_ANA_IN == STD_ON)
#if (IOHWAB_USE_ANA_SUP_SWT == STD_ON)
#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IOHWAB_CODE)IoHwAb_InputSupplyAnalogControl(boolean blOn);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"
#endif /* (IOHWAB_USE_ANA_SUP_SWT == STD_ON) */
#endif /* (IOHWAB_USE_ANA_IN == STD_ON)*/

#endif /* (IOHWAB_USE_IN_SUP_SWT == STD_ON) */

#endif /* IOHWAB_INPUTSUPPLY_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
