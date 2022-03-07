/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Com_IpduGrp.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Com Module                                            **
**                                                                            **
**  PURPOSE   : Provision of declaration of I-PDU group intexternal functions.**
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
** 2.2.3     08-Dec-2017   Chan Kim    Internal Redmine #10849, #10851        **
** 2.2.0     16-Apr-2017   Chan Kim    Internal Redmine #7525                 **
** 2.1.7     30-Nov-2016   Chan Kim    Internal Redmine #6807                 **
** 2.1.0     25-May-2016   Chan Kim    Internal Redmine #4998                 **
** 2.0.10    25-Feb-2016   Chan Kim    Internal Redmine #4250                 **
** 1.0.16    27-Feb-2015   Chan Kim    Internal Redmine #2202                 **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */

#ifndef COM_IPDUGRP_H
#define COM_IPDUGRP_H

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COM_IPDUGRP_AR_RELEASE_MAJOR_VERSION  4
#define COM_IPDUGRP_AR_RELEASE_MINOR_VERSION  0
#define COM_IPDUGRP_AR_RELEASE_REVISION_VERSION  3

/* Software Version Information */
#define COM_IPDUGRP_SW_MAJOR_VERSION  2
#define COM_IPDUGRP_SW_MINOR_VERSION  2

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if((COM_TX_IPDU == STD_ON) || (COM_RX_IPDU == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_StartIpduGroup(Com_IpduGroupIdType IpduGroupId,
                                                          boolean Initialize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if((COM_TX_IPDU == STD_ON) || (COM_RX_IPDU == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_StopIpduGroup(Com_IpduGroupIdType IpduGroupId);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if((COM_RX_IPDU_DM == STD_ON) || \
  (COM_RX_SIGNAL_UBDM == STD_ON) || \
  (COM_RX_SIGGROUP_UBDM == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_EnableRxDM(Com_IpduGroupIdType IpduGroupId);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if((COM_RX_IPDU_DM == STD_ON) || \
  (COM_RX_SIGNAL_UBDM == STD_ON) || \
  (COM_RX_SIGGROUP_UBDM == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_DisableRxDM(Com_IpduGroupIdType IpduGroupId);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if((COM_FILTER_ONEEVERYN == STD_ON) && (COM_RX_SIGNAL_FILTER == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE)
              Com_RxFilterCalc(PduIdType LddIpduIndex, boolean Initialize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON) 
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_TxCounterUpdate
   (P2CONST(Com_TxIpduCounter, AUTOMATIC, COM_CONST) LpTxIpduCounter);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#endif /* COM_IPDUGRP_H */
/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
