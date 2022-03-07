/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Com_Types.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR COM Module                                            **
**                                                                            **
**  PURPOSE   : Provision of declaration of COM types.                        **
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
** 2.2.0     16-Apr-2017   Chan Kim    Internal Redmine #7525                 **
** 2.1.0     25-May-2016   Chan Kim    Internal Redmine #4998                 **
** 2.0.3     24-Nov-2015   Chan Kim    Internal Redmine #3544, #3535          **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/

#ifndef COM_TYPES_H
#define COM_TYPES_H

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COM_TYPES_AR_RELEASE_MAJOR_VERSION  4
#define COM_TYPES_AR_RELEASE_MINOR_VERSION  0
#define COM_TYPES_AR_RELEASE_REVISION_VERSION  3

/* Software Version Information */
#define COM_TYPES_SW_MAJOR_VERSION  2
#define COM_TYPES_SW_MINOR_VERSION  2

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Std_Types.h" /* Standard types header file  */
#include "Com_Cfg.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Typedefenition for Com Service Id */
typedef uint8 Com_ServiceIdType;

/* Service ID of Com Initialization */
#define COMSERVICEID_INIT                         ((Com_ServiceIdType)0x01)
/* Service ID of Com De-Initialization */
#define COMSERVICEID_DEINIT                       ((Com_ServiceIdType)0x02)
/* Service ID of Com I-PDU Group Control */
#define COMSERVICEID_IPDUGROUPCONTROL             ((Com_ServiceIdType)0x03)
/* Service ID of Com Reception DM Control */
#define COMSERVICEID_RECEPTIONDMCONTROL           ((Com_ServiceIdType)0x06)
/* Service ID of Com Get Status */
#define COMSERVICEID_GETSTATUS                    ((Com_ServiceIdType)0x07)
/* Service ID of Com Configuration ID */
#define COMSERVICEID_GETCONFIGURATIONID           ((Com_ServiceIdType)0x08)
/* Service ID of Com Get Version Info */
#define COMSERVICEID_GETVERSIONINFO               ((Com_ServiceIdType)0x09)
/* Service ID of Com Send Signal */
#define COMSERVICEID_SENDSIGNAL                   ((Com_ServiceIdType)0x0A)
/* Service ID of Com Receive Signal */
#define COMSERVICEID_RECEIVESIGNAL                ((Com_ServiceIdType)0x0B)
/* Service ID of Com Update Shadow Signal */
#define COMSERVICEID_UPDATESHADOWSIGNAL           ((Com_ServiceIdType)0x0C)
/* Service ID of Com Send Signal Group */
#define COMSERVICEID_SENDSIGNALGROUP              ((Com_ServiceIdType)0x0D)
/* Service ID of Com Receive Signal Group */
#define COMSERVICEID_RECEIVESIGNALGROUP           ((Com_ServiceIdType)0x0E)
/* Service ID of Com Receive Shadow Signal */
#define COMSERVICEID_RECEIVESHADOWSIGNAL          ((Com_ServiceIdType)0x0F)
/* Service ID of Com Invalidate Signal */
#define COMSERVICEID_INVALIDATESIGNAL             ((Com_ServiceIdType)0x10)
/* Service ID of Com Invalidate Shadow Signal */
#define COMSERVICEID_INVALIDATESHADOWSIGNAL       ((Com_ServiceIdType)0x16)
/* Service ID of Com Trigger Ipdu Send */
#define COMSERVICEID_TRIGGERIPDUSEND              ((Com_ServiceIdType)0x17)
/* Service ID of Com Main Function Rx */
#define COMSERVICEID_MAINFUNCTIONRX               ((Com_ServiceIdType)0x18)
/* Service ID of Com Main Function Tx */
#define COMSERVICEID_MAINFUNCTIONTX               ((Com_ServiceIdType)0x19)
/* Service ID of Com Main Function Gateway */
#define COMSERVICEID_MAINFUNCTIONROUTESIGNALS     ((Com_ServiceIdType)0x1A)
/* Service ID of Com Invalidate Signal Group */
#define COMSERVICEID_INVALIDATESIGNALGROUP        ((Com_ServiceIdType)0x1B)
/* Service ID of Com Clear I-PDU Group Vector */
#define COMSERVICEID_CLEARIPDUGROUPVECTOR         ((Com_ServiceIdType)0x1C)
/* Service ID of Com Set I-PDU Group */
#define COMSERVICEID_SETIPDUGROUP                 ((Com_ServiceIdType)0x1D)
/* Service ID of Com Tp Rx Indication */
#define COMSERVICEID_TPRXINDICATION               ((Com_ServiceIdType)0x1E)
/* Service ID of Com Send Dynamic Signal */
#define COMSERVICEID_SENDDYNSIGNAL                ((Com_ServiceIdType)0x21)
/* Service ID of Com Tp Rx Indication */
#define COMSERVICEID_RECEIVEDYNSIGNAL             ((Com_ServiceIdType)0x22)
/* Service ID of Com Tp Rx Copy */
#define COMSERVICEID_COPYRXDATA                   ((Com_ServiceIdType)0x44)
/* Service ID of Com Tp Tx Copy */
#define COMSERVICEID_COPYTXDATA                   ((Com_ServiceIdType)0x43)
/* Service ID of Com Send Signal Group Array */
#define COMSERVICEID_SENDSIGNALGROUPARRAY         ((Com_ServiceIdType)0x23)
/* Service ID of Com Receive Signal Group Array */
#define COMSERVICEID_RECEIVESIGNALGROUPARRAY      ((Com_ServiceIdType)0x24)

/* Service ID of Com Tp Rx Indication */
#define COMSERVICEID_STARTOFRECEPTION             ((Com_ServiceIdType)0x25)
/* Service ID of Com Tp Rx Indication */
#define COMSERVICEID_TPTXCONFIRMATION             ((Com_ServiceIdType)0x26)
/* Service ID of Com Tp Rx Indication */
#define COMSERVICEID_SWITCHIPDUTXMODE             ((Com_ServiceIdType)0x27)
/* Service ID of Com Tx Confirmation */
#define COMSERVICEID_TXCONFIRMATION               ((Com_ServiceIdType)0x40)
/* Service ID of Com Trigger Transmit */
#define COMSERVICEID_TRIGGERTRANSMIT              ((Com_ServiceIdType)0x41)
/* Service ID of Com Rx Indication */
#define COMSERVICEID_RXINDICATION                 ((Com_ServiceIdType)0x42)


/* Error code for API service called with wrong parameter */
#define COM_E_PARAM                               ((uint8)0x01)
/* Error code for API service called without COM being initialized */
#define COM_E_UNINIT                              ((uint8)0x02)
/* Error code for API service called with NULL Pointer */
#define COM_E_PARAM_POINTER                       ((uint8)0x03)


/* Structure for the COM configuration type */
typedef struct STagCom_ConfigType
{
  uint8 ucDummy;
}Com_ConfigType;

/* Status value returned by the API service Com_GetStatus() */
typedef enum
{
  COM_UNINIT = 0x00,
  COM_INIT
}Com_StatusType;


typedef uint8 Com_IpduGroupIdType;
/* I-PDU group vector */
typedef uint8 Com_IpduGroupVector[COM_IPDU_GRP_VECTOR_SIZE];
#endif /* COM_TYPES_H  */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
