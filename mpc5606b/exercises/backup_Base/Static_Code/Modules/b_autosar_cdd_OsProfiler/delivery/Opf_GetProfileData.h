/*******************************************************************************
**                                                                            **
**  (C) 2016 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Opf_GetProfileData.h                                          **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : OS Profiler                                                   **
**                                                                            **
**  PURPOSE   : Implementation of GetProfileData module                       **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 1.1.0     30-Nov-2016    SH.Yoo        Redmine #6816                       **
** 1.0.0     14-Jul-2016    SH.Yoo        Redmine #4024                       **
*******************************************************************************/

#ifndef OPF_GETPROFILEDATA_H
#define OPF_GETPROFILEDATA_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#include "Opf_Cfg.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
extern FUNC(Tdd_Opf_ProfileTaskInfo *, OPF_CODE) Opf_GetTaskInfo
                                                             (uint16 LddTaskID);
extern FUNC(Tdd_Opf_ProfileEventQ *, OPF_CODE) Opf_GetProfileInfo(void);

#endif /* OPF_GETPROFILEDATA_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
