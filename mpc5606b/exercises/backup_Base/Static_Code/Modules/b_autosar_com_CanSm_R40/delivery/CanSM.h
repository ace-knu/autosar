/*******************************************************************************
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.								          **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanSM.h                                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN State Manager Module                              **
**                                                                            **
**  PURPOSE   : Provision of External declaration of APIs Service Ids         **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 1.10.0    27-Oct-2016   Lim Jong Sun   #7076                               **
** 1.9.8     25-Apr-2016   Lim Jong Sun   #4734                               **
** 1.9.6     26-Nov-2015   Lim Jong Sun   #2786                               **
** 1.9.4     11-Sep-2015   Lim Jong Sun   #2525                               **
** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
*******************************************************************************/
#ifndef CANSM_H
#define CANSM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComStack_Types.h"       /* Com Stack Types header file */
#include "CanSM_Types.h"          /* CanSM Types header file */
#include "ComM.h"                 /* ComM header file */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANSM_H_AR_RELEASE_MAJOR_VERSION         4
#define CANSM_H_AR_RELEASE_MINOR_VERSION         0
#define CANSM_H_AR_RELEASE_REVISION_VERSION      3

/* Software Version Information */
#define CANSM_H_SW_MAJOR_VERSION                 1
#define CANSM_H_SW_MINOR_VERSION                 10

/*******************************************************************************
**                      Published Information                                 **
*******************************************************************************/
/* Module Instance ID  */
#define CANSM_MODULE_INSTANCE_ID                ((uint8) 0)

/*******************************************************************************
**                      DET error value                                       **
*******************************************************************************/

/* Not yet initialized */
#define CANSM_E_UNINIT                          ((uint8) 0x01)

/* Called with NULL PTR */
#define CANSM_E_PARAM_POINTER                   ((uint8) 0x02)

/* Network number invalid */
#define CANSM_E_INVALID_NETWORK_HANDLE          ((uint8) 0x03)

/* Controller number invalid */
#define CANSM_E_PARAM_CONTROLLER                ((uint8) 0x04)

/* Transceiver number invalid */
#define CANSM_E_PARAM_TRANSCEIVER               ((uint8) 0x05)

/* Id for Bus Off Recovery Det error */
#define CANSM_E_BUSOFF_RECOVERY_ACTIVE          ((uint8) 0x06)

/* Id for Wait mode Indication Det error */
#define CANSM_E_WAIT_MODE_INDICATION            ((uint8) 0x07)

/* Id for Invalid ComM Request Det error */
#define CANSM_E_INVALID_COMM_REQUEST            ((uint8) 0x08)

/* Id for Invalid Baudrate Det error */
#define CANSM_E_PARAM_INVALID_BAUDRATE          ((uint8) 0x09)

/* Timeout error */
#define CANSM_E_MODE_REQUEST_TIMEOUT            ((uint8) 0x0a)

/*******************************************************************************
**                      Service id of CANSM API's                             **
*******************************************************************************/

/* Service id for CanSM_Init API */
#define CANSMSERVICEID_INIT                     ((uint8) 0x00)

/* Service ID of CanSM Get Version Info */
#define CANSMSERVICEID_GETVERSIONINFO           ((uint8) 0x01)

/* Service ID of CanSM RequestMode */
#define CANSMSERVICEID_REQCOMMODE               ((uint8) 0x02)

/* Service ID of CanSM Get CurrentMode */
#define CANSMSERVICEID_GETCURRENTCOMMODE        ((uint8) 0x03)

/* Service ID of CanSM ControllerBusoff */
#define CANSMSERVICEID_CONTROLLERBUSOFF         ((uint8) 0x04)

/* Service ID of CanSM MainFunction */
#define CANSMSERVICEID_MAINFUNCTION             ((uint8) 0x05)

/* Service ID of CanSM Confirm Pn Availability */
#define CANSMSERVICEID_CONFIRMPNAVAILABILTY     ((uint8) 0x06)

/* Service ID of CanSM Trcv Timeout Exception */
#define CANSMSERVICEID_TXTIMEOUTEXCEPTION       ((uint8) 0x0B)

/* Service ID of CanSM Clear WUF Indication */
#define CANSMSERVICEID_CLRTRCVWUFFLAGINDCN      ((uint8) 0x08)

/* Service ID of CanSM Trcv Mode Indication */
#define CANSMSERVICEID_TRCVMODEINDICATION       ((uint8) 0x09)

/* Service ID of CanSM Ccheck WUF Indication */
#define CANSMSERVICEID_CHKTRCVWUFFLAGINDCN      ((uint8) 0x0A)

/* Service ID of CanSM Check baudrate */
#define CANSMSERVICEID_CHECKBAUDRATE            ((uint8) 0x0C)

/* Service ID of CanSM Change Baudrate*/
#define CANSMSERVICEID_CHANGEBAUDRATE           ((uint8) 0x0E)

/* Service ID of CanSM Controller Mode Indication */
#define CANSMSERVICEID_CHECKCONTRLMODEINDICATON ((uint8) 0x07)

/*******************************************************************************
**                                  Macros                                    **
*******************************************************************************/
/* MISRA-C 14.2 fixed */
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> use function like-macro for removing unused argument compiler warning */
#define CANSM_UNUSED_PTR(x)                        do { \
                                                    if((x) != NULL_PTR) {} \
                                                  } while(0)

/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> use function like-macro for removing unused argument compiler warning */
#define CANSM_UNUSED(x)                            do { \
                                                    if((uint32)(x) != \
                                                    (uint32)CANSM_ZERO) {} \
                                                  } while(0)      
                                                    
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define CANSM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANSM_CODE) CanSM_Init(P2CONST(CanSM_ConfigType, AUTOMATIC,
    CANSM_APPL_CONST) ConfigPtr);

#define CANSM_STOP_SEC_CODE
#include "MemMap.h"

#define CANSM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, CANSM_CODE) CanSM_GetVersionInfo(P2VAR(Std_VersionInfoType,
    AUTOMATIC, CANSM_APPL_DATA) versionInfo);

#define CANSM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* End of ifndef CANSM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

