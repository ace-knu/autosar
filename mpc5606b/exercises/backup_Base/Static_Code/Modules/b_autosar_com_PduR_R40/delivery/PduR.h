/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: PduR.h                                                        **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR PDU Router                                            **
**                                                                            **
**  PURPOSE   : Module Header File                                            **
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
** 2.2.0     01-Feb-2017   Chan Kim    Redmine #6922                          **
** 2.1.0     17-Jun-2016   Chan Kim    Redmine #5190                          **
** 2.0.8     10-Jun-2016   Chan Kim    Redmine #5143                          **
** 2.0.3     24-Nov-2015   Chan Kim    Redmine #3545, #4519                   **
** 2.0.0     11-Aug-2015   Chan Kim    Redmine #2949                          **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/
#ifndef PDUR_H
#define PDUR_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComStack_Types.h"       /* Com Stack Types header file */
#include "PduR_Types.h"           /* Type definition header file */
#include "PduR_Cfg.h"             /* Configuration header file */
#include "PduR_PCTypes.h"         /* PDU Router module post-build time header */
#include "PduR_Ram.h"             /* Type definition header file */


/*Instance ID*/
#define PDUR_INSTANCE_ID                  ((uint8) 0)

/* AUTRON BUGFIX Definition - Enable Featuring */
#define AUTRON_LOCAL_BUG_FIX	
/*******************************************************************************
**                     Service Id's                                           **
*******************************************************************************/
/* Service ID for PduR_Init */
#define PDUR_INIT_SID                     ((uint8)0xF0)

/* Service ID for PduR_GetVersionInfo */
#define PDUR_GET_VERSION_SID              ((uint8)0xF1)

/* Service ID for PduR_GetConfigurationId */
#define PDUR_GET_CONFIG_ID_SID            ((uint8)0xF2)

/* Service ID for  PduR_EnableRouting*/
#define PDUR_ENABLE_ROUTING_SID           ((uint8)0xF3)

/* Service ID for  PduR_DisableRouting*/
#define PDUR_DISABLE_ROUTING_SID          ((uint8)0xF4)

/* Service ID for  PduR_ComTransmit */
#define PDUR_COM_TRANSMIT_SID             ((uint8)0x89)

/* Service ID for  PduR_DcmTransmit */
#define PDUR_DCM_TRANSMIT_SID             ((uint8)0x99)

/* Service ID for  PduR_IpdumTransmit */
#define PDUR_IPDUM_TRANSMIT_SID           ((uint8)0xA9)

/* Service ID for  PduR_DbgTransmit */
#define PDUR_DBG_TRANSMIT_SID             ((uint8)0xB9)

/* Service ID for  PduR_<User:Up>CancelTransmit  */
#define PDUR_COM_CANCEL_TRANSMIT_SID      ((uint8)0x8A)

/* Service ID for  PduR_<User:Up>CancelTransmit  */
#define PDUR_DCM_CANCEL_TRANSMIT_SID      ((uint8)0x9A)

/* Service ID for  PduR_<User:Up>CancelTransmit  */
#define PDUR_IPDUM_CANCEL_TRANSMIT_SID    ((uint8)0xAA)

/* Service ID for  PduR_<User:Up>CancelTransmit  */
#define PDUR_DBG_CANCEL_TRANSMIT_SID      ((uint8)0xBA)

/* Service ID for  PduR_ChangeParameter*/
#define PDUR_COM_CHANGE_PARAMETER_SID     ((uint8)0x8B)

/* Service ID for  PduR_ChangeParameter*/
#define PDUR_DCM_CHANGE_PARAMETER_SID     ((uint8)0x9B)

/* Service ID for  PduR_<User:Up>CancelReceive  */
#define PDUR_COM_CANCEL_RECEIVE_SID       ((uint8)0x8C)

/* Service ID for  PduR_<User:Up>CancelReceive  */
#define PDUR_DCM_CANCEL_RECEIVE_SID       ((uint8)0x9C)

/* Service ID for  PduR_<Lo>RxIndication     */
#define PDUR_CANIF_RX_INDICATION_SID      ((uint8)0x01)

/* Service ID for  PduR_<Lo>RxIndication     */
#define PDUR_CANNM_RX_INDICATION_SID      ((uint8)0x11)

/* Service ID for  PduR_<Lo>RxIndication     */
#define PDUR_IPDUM_RX_INDICATION_SID      ((uint8)0x21)

/* Service ID for  PduR_<Lo>RxIndication     */
#define PDUR_FRIF_RX_INDICATION_SID       ((uint8)0x31)

/* Service ID for  PduR_<Lo>RxIndication     */
#define PDUR_FRNM_RX_INDICATION_SID       ((uint8)0x41)

/* Service ID for  PduR_<Lo>RxIndication     */
#define PDUR_LINIF_RX_INDICATION_SID      ((uint8)0x51)

/* Service ID for  PduR_<Lo>RxIndication     */
#define PDUR_SOADIF_RX_INDICATION_SID     ((uint8)0x61)

/* Service ID for  PduR_<Lo>TxConfirmation   */
#define PDUR_CANIF_TX_CONFIRMATION_SID    ((uint8)0x02)

/* Service ID for  PduR_<Lo>TxConfirmation  */
#define PDUR_CANNM_TX_CONFIRMATION_SID   ((uint8)0x12)

/* Service ID for  PduR_<Lo>TxConfirmation  */
#define PDUR_IPDUM_TX_CONFIRMATION_SID   ((uint8)0x22)

/* Service ID for  PduR_<Lo>TxConfirmation  */
#define PDUR_FRIF_TX_CONFIRMATION_SID    ((uint8)0x32)

/* Service ID for  PduR_<Lo>TxConfirmation  */
#define PDUR_FRNM_TX_CONFIRMATION_SID    ((uint8)0x42)

/* Service ID for  PduR_<Lo>TxConfirmation  */
#define PDUR_LINIF_TX_CONFIRMATION_SID   ((uint8)0x52)

/* Service ID for  PduR_<Lo>TxConfirmation  */
#define PDUR_SOADIF_TX_CONFIRMATION_SID   ((uint8)0x62)

/* Service ID for  PduR_<Lo>TriggerTransmit */
#define PDUR_CANNM_TRIGGER_TRANSMIT_SID   ((uint8)0x13)

/* Service ID for  PduR_<Lo>TriggerTransmit */
#define PDUR_FRIF_TRIGGER_TRANSMIT_SID    ((uint8)0x33)

/* Service ID for  PduR_<Lo>TriggerTransmit */
#define PDUR_FRNM_TRIGGER_TRANSMIT_SID    ((uint8)0x43)

/* Service ID for  PduR_<Lo>TriggerTransmit */
#define PDUR_LINIF_TRIGGER_TRANSMIT_SID   ((uint8)0x53)

/* Service ID for  PduR_<Lo>TriggerTransmit  */
#define PDUR_SOADIF_TRIGGER_TRANSMIT_SID  ((uint8)0x63)

/* Service ID for  PduR_<LoTp>CopyRxData    */
#define PDUR_CANTP_COPYRX_DATA_SID        ((uint8)0x04)

/* Service ID for  PduR_<LoTp>CopyRxData     */
#define PDUR_J1939_COPYRX_DATA_SID        ((uint8)0x14)

/* Service ID for  PduR_<LoTp>CopyRxData     */
#define PDUR_FRTP_COPYRX_DATA_SID         ((uint8)0x34)

/* Service ID for  PduR_<LoTp>CopyRxData     */
#define PDUR_LINTP_COPYRX_DATA_SID        ((uint8)0x54)

/* Service ID for  PduR_<LoTp>CopyRxData     */
#define PDUR_SOADTP_COPYRX_DATA_SID       ((uint8)0x64)

/* Service ID for  PduR_<LoTp>CopyRxData     */
#define PDUR_CANTP_RX_INDICATION_SID      ((uint8)0x05)

/* Service ID for  PduR_<LoTp>CopyRxData     */
#define PDUR_J1939_RX_INDICATION_SID      ((uint8)0x15)

/* Service ID for  PduR_<LoTp>CopyRxData     */
#define PDUR_FRTP_RX_INDICATION_SID       ((uint8)0x35)

/* Service ID for  PduR_<LoTp>CopyRxData     */
#define PDUR_LINTP_RX_INDICATION_SID      ((uint8)0x55)

/* Service ID for  PduR_<LoTp>CopyRxData    */
#define PDUR_SOADTP_RX_INDICATION_SID     ((uint8)0x65)

/* Service ID for  PduR_<LoTp>StartOfReception */
#define PDUR_CANTP_STARTOF_RECEPTION_SID  ((uint8)0x06)

/* Service ID for  PduR_<LoTp>StartOfReception     */
#define PDUR_J1939_STARTOF_RECEPTION_SID  ((uint8)0x16)

/* Service ID for  PduR_<LoTp>StartOfReception     */
#define PDUR_FRTP_STARTOF_RECEPTION_SID   ((uint8)0x36)

/* Service ID for  PduR_<LoTp>StartOfReception     */
#define PDUR_LINTP_STARTOF_RECEPTION_SID  ((uint8)0x56)

/* Service ID for  PduR_<LoTp>StartOfReception     */
#define PDUR_SOADTP_STARTOF_RECEPTION_SID ((uint8)0x66)

/* Service ID for  PduR_<LoTp>CopyTxData     */
#define PDUR_CANTP_COPYTX_DATA_SID        ((uint8)0x07)

/* Service ID for  PduR_<LoTp>CopyTxData      */
#define PDUR_J1939_COPYTX_DATA_SID        ((uint8)0x17)

/* Service ID for  PPduR_<LoTp>CopyTxData      */
#define PDUR_FRTP_COPYTX_DATA_SID         ((uint8)0x37)

/* Service ID for  PduR_<LoTp>CopyTxData      */
#define PDUR_LINTP_COPYTX_DATA_SID        ((uint8)0x57)

/* Service ID for  PduR_<LoTp>CopyTxData      */
#define PDUR_SOADTP_COPYTX_DATA_SID       ((uint8)0x67)

/* Service ID for  PduR_<LoTp>TxConfirmation     */
#define PDUR_CANTP_TX_CONFIRMATION_SID    ((uint8)0x08)

/* Service ID for  PduR_<LoTp>TxConfirmation     */
#define PDUR_J1939_TX_CONFIRMATION_SID    ((uint8)0x18)

/* Service ID for  PduR_<LoTp>TxConfirmation     */
#define PDUR_FRTP_TX_CONFIRMATION_SID     ((uint8)0x38)

/* Service ID for  PduR_<LoTp>TxConfirmation     */
#define PDUR_LINTP_TX_CONFIRMATION_SID    ((uint8)0x58)

/* Service ID for  PduR_<LoTp>TxConfirmation     */
#define PDUR_SOADTP_TX_CONFIRMATION_SID   ((uint8)0x68)


/*******************************************************************************
**                                  Macros                                    **
*******************************************************************************/
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> 
   use function like-macro for removing unused argument compiler warning */
#define PDUR_UNUSED(x)                            do { \
                                                    if((uint32)(x) != \
                                                    (uint32)PDUR_ZERO) {} \
                                                  } while(0)
  
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> 
   use function like-macro for removing unused argument compiler warning */
#define PDUR_UNUSED_PTR(x)                        do { \
                                                    if((x) != NULL_PTR) {} \
                                                  } while(0)


/*******************************************************************************
**                     Global Data                                            **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define PDUR_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void,PDUR_CODE) PduR_Init(P2CONST(PduR_PBConfigType, AUTOMATIC,
    PDUR_APPL_CONST) ConfigPtr);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#if (PDUR_VERSION_INFO_API == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void,PDUR_CODE) PduR_GetVersionInfo
    (P2VAR(Std_VersionInfoType, AUTOMATIC,PDUR_APPL_DATA) versioninfo);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (PDUR_VERSION_INFO_API == STD_ON) */

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if (PDUR_ROUTINGPATH_GROUP_SUPPORT == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, PDUR_CODE) PduR_EnableRouting(PduR_RoutingPathGroupIdType id);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (PDUR_ROUTINGPATH_GROUP_SUPPORT == STD_ON) */
#endif /* End of if (PDUR_ZERO_COST_OPERATION == STD_OFF) */

#if (PDUR_ZERO_COST_OPERATION == STD_OFF)
#if (PDUR_ROUTINGPATH_GROUP_SUPPORT == STD_ON)
#define PDUR_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void,
  PDUR_CODE) PduR_DisableRouting(PduR_RoutingPathGroupIdType id);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (PDUR_ROUTINGPATH_GROUP_SUPPORT == STD_ON) */
#endif /* End of if (PDUR_ZERO_COST_OPERATION == STD_OFF) */

#endif /* PDUR_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
