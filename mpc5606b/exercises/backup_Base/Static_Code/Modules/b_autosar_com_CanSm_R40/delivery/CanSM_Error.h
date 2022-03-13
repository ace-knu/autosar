/*******************************************************************************
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.								          **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanSM_Error.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN State Manager Module                              **
**                                                                            **
**  PURPOSE   : This file provides macros for DET checking for CanSM module   **
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
** 1.10.0    27-Oct-2016   Lim Jong Sun   #7048                               **
** 1.9.7     19-Jan-2015   Lim Jong Sun   #3905 duplication Version define    **
** 1.9.6     13-Jan-2015   Lim Jong Sun   Feature #3415 Mode Change on Bus-Off**
** 1.0.1     27-Aug-2015   Lim Jong Sun   Fixed MISRA-C                       **
** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
*******************************************************************************/
#ifndef CANSM_ERROR_H
#define CANSM_ERROR_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanSM.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANSM_ERROR_AR_RELEASE_MAJOR_VERSION         4
#define CANSM_ERROR_AR_RELEASE_MINOR_VERSION         0
#define CANSM_ERROR_AR_RELEASE_REV_VERSION           3

/* Software Version Information */
#define CANSM_ERROR_H_SW_MAJOR_VERSION         1
#define CANSM_ERROR_H_SW_MINOR_VERSION         10

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if (STD_ON == CANSM_DEV_ERROR_DETECT)

/*------------------------ CANSM_INVALID_COMM_REQUEST-----------------------*/
/* polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations> No Impact of this rule violation*/
#define CANSM_INVALID_COMM_REQUEST_DET_CHECK(LddResult, ComM_Mode, \
                                             LucModeStatus, ServiceID)\
  do{\
    if ((((LucModeStatus) == ((uint8)(CANSM_NOCOMMUNICATION))) &&\
        ((ComM_Mode) == ((ComM_ModeType)(COMM_SILENT_COMMUNICATION)))) ||\
             ((ComM_Mode) > ((ComM_ModeType)(COMM_FULL_COMMUNICATION))))\
    {\
      (void)Det_ReportError(CANSM_MODULE_ID, CANSM_MODULE_INSTANCE_ID,\
        ServiceID, CANSM_E_INVALID_COMM_REQUEST);\
      (LddResult) = ((uint8)(E_NOT_OK));\
    }\
  }while(0)
  
/*------------------------ CANSM_INVALID_COMM_REQUEST-----------------------*/
#define CANSM_INVALID_COMM_REQUEST_CHECK(LddResult, ComM_Mode,\
                                             LucModeStatus, ServiceID)\
  do{\
    if (((LucModeStatus) == ((uint8)(CANSM_NOCOMMUNICATION))) &&\
        ((ComM_Mode) == ((ComM_ModeType)(COMM_SILENT_COMMUNICATION))))\
    {\
      (void)Det_ReportError(CANSM_MODULE_ID, CANSM_MODULE_INSTANCE_ID, \
        ServiceID, CANSM_E_INVALID_COMM_REQUEST);\
      (LddResult) = ((uint8)(E_NOT_OK));\
    }\
  }while(0)
  
  /*------------------------ CANSM_TIMEOUT------- ----------------------------*/
#define CANSM_TIMEOUT_DET_ERROR()\
  do{\
    (void)Det_ReportError(CANSM_MODULE_ID, CANSM_MODULE_INSTANCE_ID,\
    CANSMSERVICEID_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);\
  }while(0)

/*------------------------ CANSM_INITED_DET_CHECK ----------------------------*/
#define CANSM_INITED_DET_CHECK(LddResult, ServiceID)\
  do{\
    if ((CanSM_GblInitStatus) == ((boolean)CANSM_UNINITED))\
    {\
      (void)Det_ReportError(CANSM_MODULE_ID, CANSM_MODULE_INSTANCE_ID,\
        ServiceID, CANSM_E_UNINIT);\
      (LddResult) = ((uint8)(E_NOT_OK));\
    }\
  }while(0)

/*------------------------ CANSM_VALID_TRCV_NETWORK_CHECK ------------------*/
#define CANSM_VALID_TRCV_NETWORK_CHECK(LddResult, Transceiver, ServiceID)\
  do{\
    if ((((uint8)CanSm_GucLastTrcvHandle) < (Transceiver)) || \
        (CANSM_INVALID_NETWORK == CanSM_GaaStaticTrvToNw[(Transceiver)]))\
    {\
      (void)Det_ReportError(CANSM_MODULE_ID, CANSM_MODULE_INSTANCE_ID, \
        (ServiceID), CANSM_E_PARAM_TRANSCEIVER);\
      (LddResult) = (uint8)E_NOT_OK;\
    }\
  }while(0)

/*------------------------ CANSM_CHECK_INVALID_NETWORK ---------------------*/
#define CANSM_CHECK_INVALID_NETWORK(LddResult, NetworkHandle, ServiceID)\
  do{\
    if (((NetworkHandleType)(CANSM_LAST_NETWORK_HANDLE)) <= (NetworkHandle))\
    {\
      (void)Det_ReportError(CANSM_MODULE_ID, CANSM_MODULE_INSTANCE_ID, \
        ServiceID, CANSM_E_INVALID_NETWORK_HANDLE);\
      (LddResult) = ((uint8)(E_NOT_OK));\
    }\
  }while(0)

/*------------------------ CANSM_CHECK_INVALID_POINTER ----------------------*/
#define CANSM_CHECK_INVALID_POINTER(LddResult, Pointer, ServiceID)\
  do{\
    if ((Pointer) == (NULL_PTR))\
    {\
      (void)Det_ReportError(CANSM_MODULE_ID, CANSM_MODULE_INSTANCE_ID, \
        ServiceID, CANSM_E_PARAM_POINTER);\
      (LddResult) = ((uint8)(E_NOT_OK));\
    }\
  }while(0)

/*------------------------ CANSM_CHECK_INVALID_NETWORK_HANDLE ---------------*/
#define CANSM_CHECK_INVALID_NETWORK_HANDLE(LddResult, LddNetworkHandle, \
                                           ServiceID)\
  do{\
    if (((NetworkHandleType)(CANSM_INVALID_NETWORK)) == (LddNetworkHandle))\
    {\
      (void)Det_ReportError(CANSM_MODULE_ID, CANSM_MODULE_INSTANCE_ID, \
        ServiceID, CANSM_E_INVALID_NETWORK_HANDLE);\
      (LddResult) = (uint8)(E_NOT_OK);\
    }\
  }while(0)

/*------------------------ CANSM_CHECK_INVALID_CONTROLLER -------------------*/
#define CANSM_CHECK_INVALID_CONTROLLER(LddResult, Controller, ServiceID)\
  do{\
    if ((Controller) >= ((uint8)(CANSM_LAST_CONTROLLER_HANDLE)))\
    {\
      (void)Det_ReportError(CANSM_MODULE_ID, CANSM_MODULE_INSTANCE_ID, \
        ServiceID, CANSM_E_PARAM_CONTROLLER);\
      (LddResult) = ((uint8)(E_NOT_OK));\
    }\
  }while(0)

/*------------------------ CANSM_CHECK_INVALID_BAUDRATE ---------------------*/
#define CANSM_CHECK_INVALID_BAUDRATE(LddResult, ServiceID)\
  do{\
    if (((LpNetwork->usBaudrate) != (Baudrate)) || ((LpNetwork->ucResult) != \
                                                                  ((uint8)E_OK)))\
    {\
      (void)Det_ReportError(CANSM_MODULE_ID, CANSM_MODULE_INSTANCE_ID, \
        ServiceID, CANSM_E_PARAM_INVALID_BAUDRATE);\
      (LddResult) = ((uint8)(E_NOT_OK));\
    }\
  }while(0)

/*--------------- CANSM_E_BUSOFF_RECOVERY_ACTIVE ----------------------------*/
#define CANSM_CHECK_BUSOFF_RECOVERY_ACTIVE(LddResult, LucModeStatus, \
                                                                     ServiceID)\
  do{\
    if ((CANSM_TWO) < (LucModeStatus))\
    {\
      if (((CANSM_BORSTART) == (LucModeStatus)) || \
          ((CANSM_BORWAIT) == (LucModeStatus)))\
      {\
        (void)Det_ReportError(CANSM_MODULE_ID, CANSM_MODULE_INSTANCE_ID, \
          ServiceID, CANSM_E_BUSOFF_RECOVERY_ACTIVE);\
        (LddResult) = ((uint8)(E_NOT_OK));\
      }\
    }\
  }while(0)

/*--------------- CANSM_E_WAIT_MODE_INDICATION ------------------------------*/
#define CANSM_CHECK_WAIT_MODE_INDICATION(LddResult, LucModeStatus, ServiceID)\
  do{\
    if ((CANSM_TWO) < (LucModeStatus))\
    {\
      if (((CANSM_BORSTART) != (LucModeStatus)) &&\
          ((CANSM_BORWAIT) != (LucModeStatus)) &&\
          ((CANSM_CHECKBUSOFF) != (LucModeStatus)))\
      {\
        (void)Det_ReportError(CANSM_MODULE_ID, CANSM_MODULE_INSTANCE_ID, \
          ServiceID, CANSM_E_WAIT_MODE_INDICATION);\
        (LddResult) = ((uint8)(E_NOT_OK));\
      }\
    }\
  }while(0)
  /* polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations> No Impact of this rule violation*/
#endif /* End of if (STD_ON == CANSM_DEV_ERROR_DETECT) */

#endif /* CANSM_ERROR_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/

