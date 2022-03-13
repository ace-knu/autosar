/*******************************************************************************
**                                                                            **
**  (C) 2016 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Os_Imp_Cfg.h                                                  **
**                                                                            **
**  TARGET    : MPC560xB                                                      **
**                                                                            **
**  PRODUCT   : AUTOSAR OS Integration Code                                   **
**                                                                            **
**  PURPOSE   : Header file containing the definition of configuration for    **
**              OS Implementation Integration functions                       **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 1.0.0     08-Mar-2016    MJ.Woo        Initial version                     **
*******************************************************************************/
#ifndef OS_IMP_CFG_H_
#define OS_IMP_CFG_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "../../Modules/b_pf_mcal_freescale_MPC560xB/b_mcal_base_freescale_MPC560xB/include/Std_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define OS_IMP_CFG_AR_RELEASE_MAJOR_VERSION    4
#define OS_IMP_CFG_AR_RELEASE_MINOR_VERSION    0
#define OS_IMP_CFG_AR_RELEASE_REVISION_VERSION 3

/* Software version information */
#define OS_IMP_CFG_SW_MAJOR_VERSION    1
#define OS_IMP_CFG_SW_MINOR_VERSION    0
#define OS_IMP_CFG_SW_PATCH_VERSION    0

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* If you want to disable CPU/IT Load features, change this option to STD_OFF */
#define OS_DEBUG_CPULOAD        STD_ON
/* If you want to disable Stack Depth feature, change this option to STD_OFF */
#define OS_DEBUG_STACKDEPTH     STD_ON
/* If ErrM module is not used, change this option to STD_OFF */
#define OS_ERRM_USED            STD_ON
/* If Pm module is not used, change this option to STD_OFF */
#define OS_PM_USED              STD_OFF

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* OS_IMP_CFG_H_ */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
