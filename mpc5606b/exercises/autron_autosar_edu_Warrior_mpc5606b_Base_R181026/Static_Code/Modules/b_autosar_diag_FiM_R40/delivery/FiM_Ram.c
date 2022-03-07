/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: FiM_Ram.c                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Function Inhibition Manager Module                    **
**                                                                            **
**  PURPOSE   : Global RAM Variables of FiM                                   **
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
** 1.0.2     14-01-2013    Autron        Initial version                      **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "FiM_Ram.h"     /* Ram header file */

/*******************************************************************************
**                           Global Data                                      **
*******************************************************************************/

#define FIM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
/* Global Variable to store FIM Initialization status */
VAR(boolean, FIM_VAR_POWER_ON_INIT) FiM_GblInitStatus;
#define FIM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"


#define FIM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"
/* Global array to store FID permission state */
VAR(boolean, FIM_VAR_NOINIT)
  FiM_GaaFidPermissionState[FIM_TOTAL_NUM_OF_FIDS];
#define FIM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define FIM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global array to store inhibition counter for all FID¡¯s */
VAR(FiM_FidsSizeType, FIM_VAR_NOINIT)
  FiM_GaaFidInhibitCounter[FIM_TOTAL_NUM_OF_FIDS];
#define FIM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
