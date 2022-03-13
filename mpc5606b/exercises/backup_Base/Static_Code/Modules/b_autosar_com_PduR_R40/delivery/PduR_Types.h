/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: PduR_Types.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR PDU Router                                            **
**                                                                            **
**  PURPOSE   : Type definition of AUTOSAR PDU Router                         **
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
** 2.0.0     11-Aug-2015   Chan Kim    Redmine #2949                          **
** 1.0.0     29-Apr-2013   Autron      Initial Version                        **
*******************************************************************************/

#ifndef PDUR_TYPES_H
#define PDUR_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComStack_Types.h" /* COM Stack header module */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define PDUR_TYPES_AR_RELEASE_MAJOR_VERSION         4
#define PDUR_TYPES_AR_RELEASE_MINOR_VERSION         0
#define PDUR_TYPES_AR_RELEASE_REVISION_VERSION      3

/* Software Version Information */
#define PDUR_TYPES_SW_MAJOR_VERSION                 2
#define PDUR_TYPES_SW_MINOR_VERSION                 2
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Invalid configuration pointer */
#define PDUR_E_CONFIG_PTR_INVALID            ((uint8) 0)

/* API service used without module initialization */
#define PDUR_E_INVALID_REQUEST               ((uint8) 1)

/* Invalid PduId is reported using following error code */
#define PDUR_E_PDU_ID_INVALID                ((uint8) 2)

/* Rejection of Transmit request for a valid and idle PDU identifier by
 *     TP module is reported using following error code */
#define PDUR_E_TP_TX_REQ_REJECTED            ((uint8) 3)

/* Invalid PDUParameterValue/PduCancelReason is reported using following
 * error code */
#define PDUR_E_PARAM_INVALID                 ((uint8) 4)

/* Invalid Routing Path Group Id is reported using following error code */
#define PDUR_E_ROUTING_PATH_GROUP_ID_INVALID ((uint8) 8)

/* NULL Data pointer is reported using the following error code */
#define PDUR_E_NULL_POINTER                  ((uint8) 0x09)

/* A I-PDU ID is received that is already in process is reported using following
   error code */
#define PDUR_E_DUPLICATE_IPDU_ID             ((uint8) 0x06)

/* I-PDU buffer is longer than expected is reported using following
   error code */
#define PDUR_E_IPDU_TOO_LONG                 ((uint8) 0x07)

/* Buffer Overflow is reported using following error code */
#define PDUR_E_PDU_INSTANCES_LOST            ((uint8) 0x0A)

/* PDU Router initialization failed using following error code */
#define PDUR_E_INIT_FAILED                   ((uint8) 0x0B)

/* PduR ConfigId returntype */
typedef uint16 PduR_PBConfigIdType;

typedef uint16 PduR_RoutingPathGroupIdType;

/* PDU Router States */
typedef enum STag_PduR_StateType
{
  /*PDU Router is not initialised*/
  PDUR_UNINIT  = 0,
  /* PDU Router initialized successfully */
  PDUR_ONLINE
}PduR_StateType;

typedef uint8 PduR_ReturnType;

/**
 * typedef PduR_PBConfigType
 *
 * This structure is required to be generated in case of Post Build or Multiple
 *  configuration
 */
/* Structure for PduR_PBConfigType */
typedef struct STag_PduR_PBConfigType
{
uint8 dummy;
}PduR_PBConfigType;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* PDUR_TYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
