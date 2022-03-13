/*******************************************************************************
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanTp.h                                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN Transport Protocol                                **
**                                                                            **
**  PURPOSE   : Main header file for CanTp                                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 1.7.7     02-May-2016   Lim Jong Sun   #4803                               **
** 1.7.4     26-Nov-2015   Lim Jong Sun   #2786                               **
** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
*******************************************************************************/
#ifndef CANTP_H
#define CANTP_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComStack_Types.h"       /* Communication Stack Types Header File */
#include "CanTp_Cfg.h"            /* Configuration header file */
#if (CANTP_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"                  /* DET header file */
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CANTP_H_AR_RELEASE_MAJOR_VERSION    4
#define CANTP_H_AR_RELEASE_MINOR_VERSION    0
#define CANTP_H_AR_RELEASE_REVISION_VERSION 3

/* CANTP software version information */
#define CANTP_H_SW_MAJOR_VERSION            1
#define CANTP_H_SW_MINOR_VERSION            0
#define CANTP_H_SW_PATCH_VERSION            3

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Instance id */
#define CANTP_INSTANCE_ID          ((uint8) 0)

/*  DET Error codes */
#define CANTP_E_PARAM_ID           ((uint8) 0x02)
#define CANTP_E_PARAM_POINTER      ((uint8) 0x03)
#define CANTP_E_UNINIT             ((uint8) 0x20)
#define CANTP_E_INVALID_TX_ID      ((uint8) 0x30)
#define CANTP_E_INVALID_RX_ID      ((uint8) 0x40)
#define CANTP_E_INVALID_TX_LENGTH  ((uint8) 0x70)
#define CANTP_E_INVALID_RX_LENGTH  ((uint8) 0x80)
#define CANTP_E_INVALID_TATYPE     ((uint8) 0x90)
#define CANTP_E_OPER_NOT_SUPPORTED ((uint8) 0xA0)
#define CANTP_E_COM                ((uint8) 0xB0)
#define CANTP_E_RX_COM             ((uint8) 0xC0)
#define CANTP_E_TX_COM             ((uint8) 0xD0)

/* API Service IDs */
#define CANTP_INIT_SID             ((uint8) 0x01)
#define CANTP_SHUTDOWN_SID         ((uint8) 0x02)
#define CANTP_TRANSMIT_SID         ((uint8) 0x03)
#define CANTP_MAINFUNCTION_SID     ((uint8) 0x06)
#define CANTP_GETVERSIONINFO_SID   ((uint8) 0x07)
#define CANTP_RXINDICATION_SID     ((uint8) 0x42)
#define CANTP_TXCONFIRMATION_SID   ((uint8) 0x40)
#define CANTP_CANCELTRANSMIT_SID   ((uint8) 0x08)
#define CANTP_CANCELRECEIVE_SID    ((uint8) 0x09)
#define CANTP_CHANGEPARAM_SID      ((uint8) 0x0A)
#define CANTP_READPRAM_SID         ((uint8) 0x0B)

/* CanTp Initialization configuration */
typedef struct STag_CanTp_ConfigurationType
{
  /* ucMainfunctionPeriod value */
  uint8 ucMainfunctionPeriod;
} CanTp_ConfigType;

/*******************************************************************************
**                                  Macros                                    **
*******************************************************************************/
/* MISRA-C 14.2 fixed */
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> use function like-macro for removing unused argument compiler warning */
#define CANTP_UNUSED_PTR(x)                        do { \
                                                    if((x) != NULL_PTR) {} \
                                                  } while(0)
                                                    
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> use function like-macro for removing unused argument compiler warning */
#define CANTP_UNUSED(x)                            do { \
                                                    if((uint32)(x) != \
                                                    (uint32)CANTP_ZERO) {} \
                                                  } while(0)                                                    
                                                  
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CANTP_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void,
  CANTP_CODE) CanTp_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC,
    CANTP_APPL_DATA) versioninfo);
#define CANTP_STOP_SEC_CODE
#include "MemMap.h"

#define CANTP_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void,
  CANTP_CODE) CanTp_Init(P2CONST(CanTp_ConfigType, AUTOMATIC,
    CANTP_APPL_CONST) CfgPtr);

#define CANTP_STOP_SEC_CODE
#include "MemMap.h"

#define CANTP_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANTP_CODE) CanTp_Shutdown(void);

#define CANTP_STOP_SEC_CODE
#include "MemMap.h"

#define CANTP_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_Transmit(PduIdType CanTpTxSduId,
  P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) CanTpTxInfoPtr);
#define CANTP_STOP_SEC_CODE
#include "MemMap.h"

#define CANTP_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_CancelTransmit(PduIdType
  CanTpTxSduId);
#define CANTP_STOP_SEC_CODE
#include "MemMap.h"

#define CANTP_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_ChangeParameter(PduIdType id,
  TPParameterType parameter, VAR(uint16, AUTOMATIC) Value);
#define CANTP_STOP_SEC_CODE
#include "MemMap.h"

#define CANTP_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_CancelReceive(PduIdType
  CanTpRxSduId);
#define CANTP_STOP_SEC_CODE
#include "MemMap.h"

#define CANTP_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_ReadParameter(PduIdType id,
  TPParameterType parameter, P2VAR(uint16, AUTOMATIC, CANTP_APPL_DATA) LpValue);
#define CANTP_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CANTP_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

