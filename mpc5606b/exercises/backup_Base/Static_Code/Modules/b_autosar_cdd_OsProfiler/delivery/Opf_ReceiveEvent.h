/*******************************************************************************
**                                                                            **
**  (C) 2016-2017 HYUNDAI AUTRON Co., Ltd.                                    **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Opf_ReceiveEvent.h                                            **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : OS Profiler                                                   **
**                                                                            **
**  PURPOSE   : Implementation of ReceiveEvent module                         **
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
** 1.1.2     22-Aug-2017    MJ.Woo        Redmine #6959                       **
** 1.1.0     24-Nov-2016    SH.Yoo        Redmine #6755                       **
** 1.0.0     14-Jul-2016    SH.Yoo        Redmine #4024                       **
*******************************************************************************/

#ifndef OPF_RECEIVEEVENT_H
#define OPF_RECEIVEEVENT_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Opf_Types.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
extern FUNC(void, OPF_CODE) Opf_SetPreTaskEvent(void);
extern FUNC(void, OPF_CODE) Opf_SetPostTaskEvent(void);
extern FUNC(void, OPF_CODE) Opf_SetPreIsrEvent(void);
extern FUNC(void, OPF_CODE) Opf_SetPostIsrEvent(void);
extern FUNC(void, OPF_CODE) Opf_SetLimitErrorEvent(void);
extern FUNC(void, OPF_CODE) Opf_SetActivateTaskEvent(OpfTaskIDType LddTaskID,
                                                   OpfTimeSpanType LddTimeSpan);
extern FUNC(void, OPF_CODE) Opf_SetLimitTaskEvent(OpfTaskIDType LddTaskID);
extern FUNC(void, OPF_CODE) Opf_SetTimeIndexEvent(OpfSpanTickType LddSpanTick);
extern FUNC(void, OPF_CODE) Opf_SetTaskEvent(OpfTaskIDType LddTaskID,
                                                         OpfStateType LddState);

#endif /* OPF_RECEIVEEVENT_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
