/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: FiM_Types.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Function Inhibition Manager Module                    **
**                                                                            **
**  PURPOSE   : Type definition of Function Inhibition Manager                **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By            Description                          **
********************************************************************************
** 1.0.0     01-Nov-2012   Autron        Initial version                      **
*******************************************************************************/
#ifndef FIM_TYPES_H
#define FIM_TYPES_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"     /* Std Types Definition Header File */
#include "Rte_FiM_Type.h"  /* Rte FiM Definition Header file */
#include "FiM_Cfg.h"       /* FiM Cfg Definition Header File */

/*******************************************************************************
**                           Global Data                                      **
*******************************************************************************/
typedef struct STagTdd_FiM_ConfigData
{
  uint8 dummy;
}FiM_ConfigType;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#endif /* FIM_TYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
