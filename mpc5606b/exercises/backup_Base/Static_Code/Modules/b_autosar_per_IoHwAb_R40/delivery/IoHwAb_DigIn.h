/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IoHwAb_DigIn.h                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IOHWAB                                                **
**                                                                            **
**  PURPOSE   : C header for DigIn                                            **
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
** 1.0.3     16-SEP-2015   Jongyoung  1.MISRA-C Rule violation fix            **
** 1.0.2     05-Jun-2015   Jongyoung  1.Misra-C coding Rule adaption          **
**                                      Duplicated Extern declaration (8.8)   **
** 1.0.1     27-Sep-2014   Jongyoung  Polyspace result Adaption               **
** 1.0.0     07-Mar-2014   Sinil      Initial version                         **
*******************************************************************************/

#ifndef IOHWAB_DIGIN_H
#define IOHWAB_DIGIN_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IoHwAb.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define IOHWAB_DIGIN_COUNT_BIT_MASK              (0x0FU)
#define IOHWAB_DIGIN_FILT_BIT_MASK               (0x10U)
#define IOHWAB_DIGIN_RAW_BIT_MASK                (0x20U)
#define IOHWAB_DIGIN_RESULT_SET_BIT_MASK         (0x30U)
#define IOHWAB_DIGIN_FREEZE_BIT_MASK             (0x40U)
#define IOHWAB_DIGIN_UNFREEZE_BIT_MASK           (0xBFU)
#define IOHWAB_DIGIN_RESULT_COUNT_CLEAR_BIT_MASK (0xC0U)

/*******************************************************************************
**                      Macro                                                 **
*******************************************************************************/
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> No Impact of this rule violation */
#define IOHWAB_DIGIN_GET_FILT_VAL(x)      (((x) & IOHWAB_DIGIN_FILT_BIT_MASK) >> 4)
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> No Impact of this rule violation */
#define IOHWAB_DIGIN_GET_RAW_VAL(x)       (((x) & IOHWAB_DIGIN_RAW_BIT_MASK)  >> 5)
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> No Impact of this rule violation */
#define IOHWAB_DIGIN_GET_FREEZE_VAL(x)    (((x) & IOHWAB_DIGIN_FREEZE_BIT_MASK) >> 6)

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#if (IOHWAB_USE_DIG_IN == STD_ON)
#define IOHWAB_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
extern VAR(uint8, IOHWAB_VAR) IoHwAb_DigInFilteringStart;
#define IOHWAB_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"
#endif /* (IOHWAB_USE_DIG_IN == STD_ON) */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if (IOHWAB_USE_DIG_IN == STD_ON)

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void,IOHWAB_CODE)IoHwAb_DigInInit1(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void,IOHWAB_CODE)IoHwAb_DigInInit2(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void,IOHWAB_CODE)IoHwAb_DigInH2L(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void,IOHWAB_CODE)IoHwAb_DigInSampleLP(void);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void,IOHWAB_CODE)IoHwAb_DigInReadHwInputs(boolean blFast);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#define IOHWAB_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void,IOHWAB_CODE)IoHwAb_DigInDebounce(IoHwAb_IndexType Idx,
  IoHwAb_IndexType NumFilt);
#define IOHWAB_STOP_SEC_CODE
#include "MemMap.h"

#endif /* (IOHWAB_USE_DIG_IN == STD_ON) */

#endif /* IOHWAB_ANAIN_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
