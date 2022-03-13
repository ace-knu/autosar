/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Com_Ram.c                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Com Module                                            **
**                                                                            **
**  PURPOSE   : Provision of initialization of RAM area.                      **
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
** 2.1.6     08-Nov-2016   Chan Kim    Internal Redmine #6557                 **
** 2.1.0     25-May-2016   Chan Kim    Internal Redmine #4998                 **
** 2.0.13    13-May-2016   Chan Kim    Internal Redmine #3959, #4757          **
** 2.0.8     12-Feb-2016   Chan Kim    Internal Redmine #4140, #4109          **
** 2.0.2     19-Sep-2015   Chan Kim    Internal Redmine #3182                 **
** 1.0.14    03-Nov-2014   Chan Kim    Internal Redmine #1463                 **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Com.h"          /* Com header file */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version Information */
#define COM_RAM_C_AR_RELEASE_MAJOR_VERSION       4
#define COM_RAM_C_AR_RELEASE_MINOR_VERSION       0
#define COM_RAM_C_AR_RELEASE_REVISION_VERSION    3

/* Software version information */
#define COM_RAM_C_SW_MAJOR_VERSION  2
#define COM_RAM_C_SW_MINOR_VERSION  2

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if(COM_AR_RELEASE_MAJOR_VERSION != COM_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "Com_Ram.c : Mismatch in Com Specification Major Version"
#endif

#if(COM_AR_RELEASE_MINOR_VERSION != COM_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "Com_Ram.c : Mismatch in Com Specification Minor Version"
#endif

#if(COM_AR_RELEASE_REVISION_VERSION != COM_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "Com_Ram.c : Mismatch in Com Specification Revision Version"
#endif

#if(COM_SW_MAJOR_VERSION != COM_RAM_C_SW_MAJOR_VERSION)
  #error "Com_Ram.c : Mismatch in Com Software Major Version"
#endif

#if(COM_SW_MINOR_VERSION != COM_RAM_C_SW_MINOR_VERSION)
  #error "Com_Ram.c : Mismatch in Com Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" 
/* Global variable to store initialization status of COM Module */
VAR (Com_StatusType, COM_VAR) Com_GddComStatus;
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
 
#if(COM_TX_IPDU_COUNTER_ENABLED == STD_ON)
#define COM_START_SEC_VAR_CLEARED_8
#include "MemMap.h" 
/* Global variable to store initialization status of COM Module */
VAR (uint8, COM_VAR) Com_GaaCounterStatusFlag[COM_TX_IPDU_COUNTER_SIZE];
#define COM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" 
#endif

#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" 
/*  I-PDU group status. */
VAR(uint8, COM_VAR) Com_GaaIpduGrpEnStatus[COM_IPDU_GRP_VECTOR_SIZE];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" 

#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" 
/*  I-PDU group DeadLine monitoring status. */
VAR(uint8, COM_VAR) Com_GaaIpduGrpDmStatus[COM_IPDU_GRP_VECTOR_SIZE];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" 

#if(COM_RX_IPDU == STD_ON)

#define COM_START_SEC_VAR_CLEARED_16
#include "MemMap.h" 
/* Global variable to write status of COM Module */
VAR (uint16, COM_VAR) Com_GusRxWriteIndex;
#define COM_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" 

#define COM_START_SEC_VAR_CLEARED_16
#include "MemMap.h" 
/* Global variable to read status of COM Module */
VAR (uint16, COM_VAR) Com_GusRxReadStatus;
#define COM_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" 

#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" 
/*  Rx Ipdu Status */
VAR(PduIdType, COM_VAR) Com_GaaRxIpduStatus[COM_RX_IPDU_COUNT];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
 
#if((COM_RX_IPDU_DM == STD_ON) \
      || (COM_RX_SIGNAL_UBDM == STD_ON) \
      || (COM_RX_SIGGROUP_UBDM == STD_ON))
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" 
/*  Rx Ipdu Status */
VAR(PduIdType, COM_VAR)  Com_GaaRxDmStatus[COM_RX_IPDU_DM_COUNT];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" 
#endif

#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" 
/*  Receive History List */
VAR(PduIdType, COM_VAR)
                            Com_GaaReceiveHistoryList[COM_RX_IPDU_HISTORY_LIST];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" 

#endif

#if(COM_RX_SIG_GATEWAY == STD_ON)
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4
#include "MemMap.h" 
/*  signal gateway process temporary buffer */
VAR(uint8, COM_VAR) Com_GaaSignalGWBuffer[COM_MAX_TOTAL_PDU_SIZE];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4
#include "MemMap.h"
#endif

#if(COM_RX_SIG_GATEWAY == STD_ON)
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4
#include "MemMap.h" 
/*  signal gateway process temporary sub buffer */
VAR(uint8, COM_VAR) Com_GaaSignalGWBufferSub[COM_MAX_TOTAL_PDU_SIZE];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4
#include "MemMap.h"
#endif

#if(COM_RX_SIGGROUP_GW == STD_ON)
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" 
/*  signal group gateway process temporary buffer */
VAR(uint8, COM_VAR) Com_GaaSigGrpGWStatus[COM_RX_SIG_GRP_GW_MAX];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif


#if((COM_RX_SIGNAL_IMMEDIATENOTIFY == STD_ON) || \
                    (COM_RX_SIGGROUP_IMMEDIATENOTIFY == STD_ON))
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4
#include "MemMap.h" 
/*  signal filter, invalid, UB process temporary buffer */
VAR(uint8, COM_VAR) Com_GaaSignalValidCKBufferIM[COM_MAX_TOTAL_PDU_SIZE];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4
#include "MemMap.h"
#endif

#if(COM_RX_IPDU_DEFERRED == STD_ON)
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4
#include "MemMap.h" 
/*  signal filter, invalid, UB process temporary buffer */
VAR(uint8, COM_VAR) Com_GaaSignalValidCKBufferDE[COM_MAX_TOTAL_PDU_SIZE];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4
#include "MemMap.h"
#endif

#if(COM_TX_IPDU == STD_ON)

#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" 
/*  Tx Ipdu Status Bit */
VAR(uint16, COM_VAR) Com_GaaTxIpduStatusBit[COM_TX_IPDU_COUNT];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" 

#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" 
/*  Tx Ipdu Status */
VAR(PduIdType, COM_VAR) Com_GaaTxIpduStatus[COM_TX_IPDU_COUNT];
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" 
#endif

#if((COM_RX_REPLICATION == STD_ON) && \
            (COM_RX_IPDU_COUNTER_ENABLED == STD_ON))
#define COM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" 
/* Global variable to store initialization status of COM Module */
VAR (boolean, COM_VAR) Com_GblNoConfirmation;
#define COM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
#endif

/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
