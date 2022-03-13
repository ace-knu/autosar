/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IoHwAb_Gpt.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IOHWAB                                                **
**                                                                            **
**  PURPOSE   : C header for IoHwAb Gpt                                       **
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
** 1.0.2     05-Jun-2015   Jongyoung  1.Misra-C coding Rule adaption          **
**                                      Duplicated Extern declaration (8.8)   **
** 1.0.1     28-May-2015   Jongyoung  1.Bolero Errata e7953 resolved          **
**                                      IoHwAb_Pre(Post)ModeChange Api        **
** 1.0.0     07-Mar-2014   Sinil        Initial version                       **
*******************************************************************************/

#ifndef IOHWAB_GPT_H
#define IOHWAB_GPT_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IoHwAb.h"

#if defined(IOHWAB_MCAL_FREESCALE_MPC560XB)
#include "Reg_eSys_Pit.h"
#include "Gpt_Cfg.h"
#endif /* defined(IOHWAB_MCAL_FREESCALE_MPC560XB) */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/* #if (IOHWAB_USE_GPT == STD_ON) */
/* #endif */

#if defined(IOHWAB_MCAL_FREESCALE_MPC560XB)
extern FUNC(void, IOHWAB_CODE)IoHwAb_GptPreModeChange(
  P2VAR(IoHwAb_IndexType, AUTOMATIC, IOHWAB_APPL_DATA) PIT_TIE_STATUS);

extern FUNC(void, IOHWAB_CODE)IoHwAb_GptPostModeChange(
  P2VAR(IoHwAb_IndexType, AUTOMATIC, IOHWAB_APPL_DATA) PIT_TIE_STATUS);
#endif /* defined(IOHWAB_MCAL_FREESCALE_MPC560XB) */

#endif /* IOHWAB_GPT_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
