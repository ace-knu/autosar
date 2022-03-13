/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Com.h                                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Com Module                                            **
**                                                                            **
**  PURPOSE   : Provision of declaration of APIs                              **
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
** 2.2.0     16-Apr-2017   Chan Kim    Internal Redmine #7525, #7525          **
** 2.1.7     30-Nov-2016   Chan Kim    Internal Redmine #6807, #6823          **
** 2.1.0     25-May-2016   Chan Kim    Internal Redmine #4998                 **
** 2.0.3     24-Nov-2015   Chan Kim    Internal Redmine #3544, #3535          **
** 1.0.14    03-Nov-2014   Chan Kim    Internal Redmine #1204                 **
** 1.0.12    26-May-2014   Chan Kim    Internal Redmine #901                  **
** 1.0.11    20-Mar-2014   Chan Kim    Internal Redmine #644, #647            **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/

#ifndef COM_H
#define COM_H

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COM_H_AR_RELEASE_MAJOR_VERSION  4
#define COM_H_AR_RELEASE_MINOR_VERSION  0
#define COM_H_AR_RELEASE_REVISION_VERSION  3

/* Software Version Information */
#define COM_H_SW_MAJOR_VERSION  2
#define COM_H_SW_MINOR_VERSION  2

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "ComStack_Types.h" /* Com Stack Types header file */
#include "Com_Types.h"      /* Com Types header file */
#include "Com_Cfg.h"        /* Com Configuration header file */
#include "Com_PCTypes.h"    /* Com PCTypes header file */
#include "Com_Ram.h"

/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Necessary in logic */

/*******************************************************************************
**                                  Macros                                    **
*******************************************************************************/
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> use function like-macro for removing unused argument compiler warning */
#define COM_UNUSED(x)                            do { \
                                                    if((uint32)(x) != \
                                                    (uint32)COM_ZERO) {} \
                                                  } while(0)
  
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> use function like-macro for removing unused argument compiler warning */
#define COM_UNUSED_PTR(x)                        do { \
                                                    if((x) != NULL_PTR) {} \
                                                  } while(0)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Instance ID */
#define COM_INSTANCE_ID ((uint8)0x0)
/* Service ID for Com Service Not Available */
#define COM_SERVICE_NOT_AVAILABLE  ((uint8)0x80)
/* Service ID for Com Busy */
#define COM_BUSY  ((uint8)0x81)


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_Init
   (P2CONST(Com_ConfigType, AUTOMATIC, COM_CONST) config);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_DeInit(void);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#if(COM_VERSIONINFO_API == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_GetVersionInfo
  (P2VAR(Std_VersionInfoType, AUTOMATIC, COM_VAR)versioninfo);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if((COM_TX_IPDU == STD_ON) || (COM_RX_IPDU == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_SetIpduGroup(Com_IpduGroupVector
  ipduGroupVector, Com_IpduGroupIdType IpduGroupId, boolean bitval);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if((COM_TX_IPDU == STD_ON) || (COM_RX_IPDU == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_ClearIpduGroupVector(Com_IpduGroupVector
  ipduGroupVector);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if((COM_TX_IPDU == STD_ON) || (COM_RX_IPDU == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC (void, COM_CODE) Com_IpduGroupControl(Com_IpduGroupVector
  ipduGroupVector, boolean initialize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#else
#define COM_START_SEC_CODE
#include "MemMap.h"
/* #1204 : Dummy Function for integration with BswM Module */
extern FUNC (void, COM_CODE) Com_IpduGroupControl(Com_IpduGroupVector
  ipduGroupVector, boolean initialize);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if((COM_RX_IPDU_DM == STD_ON) || \
   (COM_RX_SIGNAL_UBDM == STD_ON) || \
   (COM_RX_SIGGROUP_UBDM == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_ReceptionDMControl(Com_IpduGroupVector
  ipduGroupVector);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#else
#define COM_START_SEC_CODE
#include "MemMap.h"
/* #1204 : Dummy Function for integration with BswM Module */
extern FUNC(void, COM_CODE) Com_ReceptionDMControl(Com_IpduGroupVector
  ipduGroupVector);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Com_StatusType, COM_CODE) Com_GetStatus(void);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint32, COM_CODE) Com_GetConfigurationId(void);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#if(COM_TX_SIGNAL_INVALID == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint8, COM_CODE) Com_InvalidateSignal (Com_SignalIdType SignalId);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_SwitchIpduTxMode(PduIdType PduId, boolean Mode);
#define COM_STOP_SEC_CODE
#include "MemMap.h"

#if(COM_TX_SIGINGROUP_INVALID == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint8, COM_CODE) Com_InvalidateSignalGroup
  (Com_SignalGroupIdType SignalGroupId);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if(COM_TX_SIGINGROUP_INVALID == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_InvalidateShadowSignal
  (Com_SignalIdType SignalId);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if(COM_TX_SIGNAL == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint8, COM_CODE) Com_SendSignal
  (Com_SignalIdType SignalId,
  P2CONST(void, AUTOMATIC, COM_CONST) SignalDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if(COM_RX_SIGNAL == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint8, COM_CODE) Com_ReceiveSignal
  (Com_SignalIdType SignalId,
  P2VAR(void, AUTOMATIC, COM_VAR) SignalDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if(COM_TX_SIGGROUP == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_UpdateShadowSignal
  (Com_SignalIdType SignalId,
  P2CONST(void, AUTOMATIC, COM_CONST) SignalDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if(COM_TX_SIGGROUP == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint8, COM_CODE) Com_SendSignalGroup
  (Com_SignalGroupIdType SignalGroupId);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/* #7525 */
#if(COM_TX_SIGGROUP == STD_ON)
#if((COM_ENABLE_SIGNALGROUP_ARRAY_API == STD_ON) && (COM_TX_SIGINGROUP_ARRAY_ACCESS == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint8, COM_CODE) Com_SendSignalGroupArray 
  (Com_SignalGroupIdType SignalGroupId, P2CONST (uint8, AUTOMATIC, COM_CONST) SignalGroupArrayPtr );
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif

#if(COM_RX_SIGGROUP == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint8, COM_CODE) Com_ReceiveSignalGroup
  (Com_SignalGroupIdType SignalGroupId);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/* #7525 */
#if(COM_RX_SIGGROUP == STD_ON)
#if((COM_ENABLE_SIGNALGROUP_ARRAY_API == STD_ON) && (COM_RX_SIGINGROUP_ARRAY_ACCESS == STD_ON))
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint8, COM_CODE) Com_ReceiveSignalGroupArray
  (Com_SignalGroupIdType SignalGroupId, P2VAR (uint8, AUTOMATIC, COM_VAR)SignalGroupArrayPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif

#if(COM_RX_SIGGROUP == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_ReceiveShadowSignal
  (Com_SignalIdType SignalId,
  P2VAR(void, AUTOMATIC, COM_VAR) SignalDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if(COM_TX_IPDU == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COM_CODE) Com_TriggerIPDUSend(PduIdType ComTxPduId);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#else
#define COM_START_SEC_CODE
#include "MemMap.h"
/* #1204 : Dummy Function for integration with BswM Module */
extern FUNC(void, COM_CODE) Com_TriggerIPDUSend(PduIdType ComTxPduId);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif


#if(COM_TX_DYN_SUPPORT == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint8, COM_CODE) Com_SendDynSignal(Com_SignalIdType SignalId,
  P2CONST(void, AUTOMATIC, COM_CONST) SignalDataPtr, uint16 Length);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if(COM_RX_DYN_SUPPORT == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint8, COM_CODE) Com_ReceiveDynSignal(Com_SignalIdType SignalId,
  P2VAR(void, AUTOMATIC, COM_VAR) SignalDataPtr,
  P2VAR(uint16, AUTOMATIC, COM_VAR) length);
#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Com_StatusType, COM_CODE) Com_GetStatus(void);
#define COM_STOP_SEC_CODE
#include "MemMap.h"


#if(COM_SIGNAL_RANGE_VALIDATION_CHECK == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COM_CODE) Com_TxSigValidationCheck
						 (uint16 signalSize, uint8 signalType, P2CONST(void, AUTOMATIC, COM_CONST) SignalDataPtr);
#define COM_STOP_SEC_CODE
#include "MemMap.h"  
#endif

/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Necessary in logic */
#endif /* COM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
