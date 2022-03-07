/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: PduR_Config.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR PDU Router                                            **
**                                                                            **
**  PURPOSE   : Provision of Version information                              **
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
** 2.1.1     17-Jun-2016   Chan Kim    Redmine #5632                          **
** 2.1.0     17-Jun-2016   Chan Kim    Redmine #5190                          **
** 2.0.8     10-Jun-2016   Chan Kim    Redmine #5143                          **
** 2.0.4     19-Feb-2016   Chan Kim    Redmine #3813                          **
** 2.0.3     24-Nov-2015   Chan Kim    Redmine #3545, #4519                   **
** 2.0.0     11-Aug-2015   Chan Kim    Redmine #2949                          **
** 1.0.7     10-Jun-2013   Chan Kim    Change code for release Library        **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define PDUR_CFG_C_AR_RELEASE_MAJOR_VERSION     4
#define PDUR_CFG_C_AR_RELEASE_MINOR_VERSION     0
#define PDUR_CFG_C_AR_RELEASE_REVISION_VERSION  3

/* Software Version Information */
#define PDUR_CFG_C_SW_MAJOR_VERSION     2
#define PDUR_CFG_C_SW_MINOR_VERSION     2
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#if (PDUR_AR_RELEASE_MAJOR_VERSION != PDUR_CFG_C_AR_RELEASE_MAJOR_VERSION)
#error "PduR_Version.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_AR_RELEASE_MINOR_VERSION != PDUR_CFG_C_AR_RELEASE_MINOR_VERSION)
#error "PduR_Version.c : Mismatch in Specification Minor Version"
#endif
#if (PDUR_AR_RELEASE_REVISION_VERSION !=\
     PDUR_CFG_C_AR_RELEASE_REVISION_VERSION)
#error "PduR_Version.c : Mismatch in Specification Revision Version"
#endif

/* Software Version Information */
#if (PDUR_SW_MAJOR_VERSION != PDUR_CFG_C_SW_MAJOR_VERSION)
#error "PduR_Version.c : Mismatch in software Major Version"
#endif
#if (PDUR_SW_MINOR_VERSION != PDUR_CFG_C_SW_MINOR_VERSION)
#error "PduR_Version.c : Mismatch in software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**						Variable for Library								  **
*******************************************************************************/

#define PDUR_START_SEC_CONST_UNSPECIFIED
#include "Memmap.h"		
CONST(PduR_RoutingPathGroupIdType, PDUR_CONST) PduR_Max_RoutingPath_Group_ID
= PDUR_MAX_ROUTINGPATH_GROUP_ID;

CONST(PduIdType, PDUR_CONST) 	PduR_Total_No_Of_TP_RxPdu
= PDUR_TOTAL_NO_OF_TP_RXPDU;

CONST(uint32, PDUR_CONST)  PduR_Group_Mask_Value
= PDUR_GROUP_MASK_VALUE;

CONST(PduIdType, PDUR_CONST) 	PduR_Lo_RxIndication_MaxPduID
= PDUR_LO_RXINDICATION_MAXPDUID;

CONST(PduIdType, PDUR_CONST) 	PduR_Lo_TxConfirmation_MaxPduID
= PDUR_LO_TXCONFIRMATION_MAXPDUID;

CONST(PduIdType, PDUR_CONST) 	PduR_Up_MaxPduID
= PDUR_UP_MAXPDUID;

CONST(PduLengthType, PDUR_CONST) PduR_TP_Buffer_Max_Length
= PDUR_TP_BUFFER_MAX_LENGTH;

CONST(PduIdType, PDUR_CONST) 	PduR_TP_TxConfirmation_MaxPduID
= PDUR_TP_TXCONFIRMATION_MAXPDUID;

CONST(PduIdType, PDUR_CONST) 	PduR_TP_RxIndication_MaxPduID
= PDUR_TP_RXINDICATION_MAXPDUID;

CONST(uint16, PDUR_CONST) 	PduR_TP_Buffer_Index_Count
= PDUR_TP_BUFFER_INDEX_COUNT;

CONST(uint16, PDUR_CONST) 	PduR_FIFO_Buffer_Index_Count
= PDUR_FIFO_BUFFER_INDEX_COUNT;
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include "Memmap.h"





/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
