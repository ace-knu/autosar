/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanSM_PCTypes.h                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN State Manager Module                              **
**                                                                            **
**  PURPOSE   : To provide configuration specific data types                  **
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
** 1.9.9     18-May-2016   Lim Jong Sun   #4872                               **
** 1.9.6     26-Nov-2015   Lim Jong Sun   #2786                               **
** 1.9.5     20-Oct-2015   Lim Jong Sun   #3210                               **
** 1.0.1     26-May-2014   Lim Jong Sun   #703                                **
** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
*******************************************************************************/
#ifndef CANSM_PCTYPES_H
#define CANSM_PCTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanSM_Cfg.h"            /* CanSM Cfg header file*/
#include "CanSM_Error.h"          /* CanSM Error header file */
#include "SchM_CanSM.h"           /* SchM CanSM header file */
#include "CanSM_Version.h"        /* CanSM Version header file */
#if (STD_ON == CANSM_DEM_STATUS)
#include "Dem.h"                  /* Dem header file */
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANSM_PCTYPES_AR_RELEASE_MAJOR_VERSION         4
#define CANSM_PCTYPES_AR_RELEASE_MINOR_VERSION         0
#define CANSM_PCTYPES_AR_RELEASE_REVISION_VERSION      3

/* Software Version Information */
#define CANSM_PCTYPES_SW_MAJOR_VERSION                 1
#define CANSM_PCTYPES_SW_MINOR_VERSION                 10

/*******************************************************************************
**                      MACRO Definitions                                     **
*******************************************************************************/

/* Macro for fetching the Network handle */
#if (STD_OFF == CANSM_SINGLE_NW_CHANNEL)
#define CANSM_LDDNETWORKHANDLE                    (LddNetworkHandle)
#else
#define CANSM_LDDNETWORKHANDLE                    (0)
#endif

/* Macro for fetching the BOR counter and Tx Ensured */
#if (STD_OFF == CANSM_BOR_COUNTER_MACRO_SUPPORT)
#define CANSM_BOR_L1TOL2                          (LpStaticNetwork->\
                                                   ddBorCounterL1ToL2)
#else
#define CANSM_BOR_L1TOL2                          (CANSM_BOR_COUNTER_L1_TO_L2)
#endif

/* Macro for fetching the BOR timer values */
#if (STD_OFF == CANSM_BUSOFF_RECOVERY_MACRO_SUPPORT)
#define CANSM_BOR_TIMEL1                          (LpStaticNetwork->\
                                                   ddCanSMBorTimeL1)
#define CANSM_BOR_TIMEL2                          (LpStaticNetwork->\
                                                   ddCanSMBorTimeL2)
#define CANSM_BOR_TIME_TXENSURED                  (LpStaticNetwork->\
                                                   ddBorTimeTxEnsured)
#else
#define CANSM_BOR_TIMEL1                          (CANSM_BOR_TIME_L1)
#define CANSM_BOR_TIMEL2                          (CANSM_BOR_TIME_L2)
#define CANSM_BOR_TIME_TXENSURED                  (CANSM_BOR_TIME_TX_ENSURED)
#endif

/* Macro for fetching the Controller ID  */
#if (STD_OFF == CANSM_SINGLE_CNTRL_CHANNEL)
#define CANSM_CNTRL_ID                            (CanSM_GaaStaticController[\
    LucControllerIndex])
#else
#define   CANSM_CNTRL_ID                          (LpStaticNetwork->\
  ucControllerIndex)
#endif

/* Macro for setting the controller mode for respective networks */
#if (STD_OFF == CANSM_SINGLE_CNTRL_CHANNEL)
#define CANIF_SETCONTROLLERMODE(ControllerID, ControllerMode)\
  {\
    (LucNoOfController) = (LpStaticNetwork->ucNumberOfController);\
    (LucControllerIndex) = (ControllerID);\
    do\
    {\
      LddResult |= CanIf_SetControllerMode(LucControllerIndex, \
        ControllerMode);\
      --LucNoOfController;\
      ++LucControllerIndex;\
    } while (LucNoOfController != CANSM_ZERO);\
  }

/* Macro for changing the Baud rate of controllers for respective networks */
#define CANIF_CHANGEBAUDRATE(ControllerID, Baudrate)\
  {\
    (LucNoOfController) = LpStaticNetwork->ucNumberOfController;\
    (LucControllerIndex) = (ControllerID);\
    do\
    {\
      LddResult |= CanIf_ChangeBaudrate(LucControllerIndex, Baudrate);\
      --LucNoOfController;\
      ++LucControllerIndex;\
    } while (LucNoOfController != CANSM_ZERO);\
  }

/* Macro for setting the Pdu mode*/
#define CANIF_SETPDUMODE(ControllerID, PduMode)\
  {\
    LucNoOfController = LpStaticNetwork->ucNumberOfController;\
    (LucControllerIndex) = (ControllerID);\
    do\
    {\
      LddResult |= CanIf_SetPduMode(LucControllerIndex, PduMode);\
      --LucNoOfController;\
      ++LucControllerIndex;\
    } while (LucNoOfController != CANSM_ZERO);\
  }
#endif /* End of if (STD_OFF == CANSM_SINGLE_CNTRL_CHANNEL) */

#define  CANSM_DEM_NO_EVENT                       ((Dem_EventIdType)0x0)
#define  CANSM_CANTRCV_INVALID_ID                 ((uint8)0xFF)
#define  CANSM_INVALID_ID                         ((uint8)0xFF)

/* This type define the network is Invalid */
#define  CANSM_INVALID_NETWORK                    ((uint8)0xFF)

/* This type define Max Bor Counter */
#define  CANSM_MAX_BOR_COUNTER                    ((uint8)0xFF)

/* Defined for Numerical value*/
#define CANSM_ZERO                                ((uint8) 0x00)
#define CANSM_ONE                                 ((uint8) 0x01)
#define CANSM_TWO                                 ((uint8) 0x02)
#define CANSM_THREE                               ((uint8) 0x03)
#define CANSM_FOUR                                ((uint8) 0x04)
#define CANSM_FIVE                                ((uint8) 0x05)
#define CANSM_SIX                                 ((uint8) 0x06)
#define CANSM_SEVEN                               ((uint8) 0x07)
#define CANSM_EIGHT                               ((uint8) 0x08)
#define CANSM_TRUE                                ((uint8) 0x01)
#define CANSM_FALSE                               ((uint8) 0x00)

/* MISRA-C 10.1, 10.5, 12.8 fixed **/
/* polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations> No Impact of this rule violation */
/* CanSM BswM Mode */
#define CANSM_BSWM_USER_ID(chid)    	((uint16)((uint16)(chid) << CANSM_EIGHT) + (CANSM_MODULE_ID))
/* polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations> No Impact of this rule violation */

/* Mode indication status for NO COMMUNICATION */
#define CANSM_NOCOMMUNICATION                     ((uint8) 0x00)

/* Mode indication status for SILENT COMMUNICATION */
#define CANSM_SILENTCOMMUNICATION                 ((uint8) 0x01)

/* Mode indication status for FULL COMMUNICATION */
#define CANSM_FULLCOMMUNICATION                   ((uint8) 0x02)

/* Mode indication status for Bus Off Recovery START*/
#define CANSM_BORSTART                            ((uint8) 0x03)

/* Mode indication status for Bus Off Recovery Wait */
#define CANSM_BORWAIT                             ((uint8) 0x04)

/* Mode indication status for checking Bus Off*/
#define CANSM_CHECKBUSOFF                         ((uint8) 0x05)

/* Mode indication status for No to Full Communication*/
#define CANSM_NOTOFULLCOMMREQUESTED               ((uint8) 0x06)

/* Mode indication status for Silent to Full Communication*/
#define CANSM_SILENTTOFULLCOMMREQUESTED           ((uint8) 0x07)

/* Mode indication status for Silent Communication*/
#define CANSM_SILENTCOMMREQUESTED                 ((uint8) 0x08)

/* Mode indication status for Changiong the Baud Rate*/
#define CANSM_CHANGEBAUDRATESERVICE               ((uint8) 0x09)

/* Mode indication status for Partial Networking Not Supported*/
#define CANSM_DEINITPNNOTSUPPORTED                ((uint8) 0x0A)

/* Mode indication status for Partial Networking Supported*/
#define CANSM_DEINITPNSUPPORTED                   ((uint8) 0x0B)

/* Mode indication status for TimeOut*/
#define CANSM_TXTIMEOUTEXCEPTIONSERVICE           ((uint8) 0x0C)

/* Macro for Intermediate Network SubState */
#define CANSM_FULL_T_BUSOFF                       ((uint8) 0x00)
#define CANSM_FULL_RESTART_CC                     ((uint8) 0x02)
#define CANSM_FULL_TX_OFF                         ((uint8) 0x04)

/* Macro for Internal SubState in CANSM_BSM_S_PRE_FULLCOM sub state Machine */
#define CANSM_PREFULL_TRCV_NORMAL                 ((uint8) 0x00)
#define CANSM_PREFULL_TRCV_NORMAL_WAIT            ((uint8) 0x01)
#define CANSM_PREFULL_CC_STOPPED                  ((uint8) 0x02)
#define CANSM_PREFULL_CC_STOPPED_WAIT             ((uint8) 0x03)
#define CANSM_PREFULL_CC_STARTED                  ((uint8) 0x04)
#define CANSM_PREFULL_CC_STARTED_WAIT             ((uint8) 0x05)
#define CANSM_PREFULL_CC_ONLINE                   ((uint8) 0x06)

/* Macro for Internal SubState in CANSM_BSM_DeinitPnSupported
                                                             sub state Machine*/
#define CANSM_PN_TRCV_CLEAR_WUF                   ((uint8) 0x00)
#define CANSM_PN_CLEAR_WUF_WAIT                   ((uint8) 0x01)
#define CANSM_PN_CC_STOPPED                       ((uint8) 0x02)
#define CANSM_PN_STOPPED_WAIT                     ((uint8) 0x03)
#define CANSM_PN_TRCV_NORMAL                      ((uint8) 0x04)
#define CANSM_PN_TRCV_NORMAL_WAIT                 ((uint8) 0x05)
#define CANSM_PN_TRCV_STANDBY                     ((uint8) 0x06)
#define CANSM_PN_TRCV_STANDBY_WAIT                ((uint8) 0x07)
#define CANSM_PN_CS_SLEEP                         ((uint8) 0x08)
#define CANSM_PN_CS_SLEEP_WAIT                    ((uint8) 0x09)
#define CANSM_PN_TRCV_CHECK_WUF                   ((uint8) 0x0A)
#define CANSM_PN_TRCV_CLEAR_WUF_WAIT              ((uint8) 0x0B)
#define CANSM_PN_NO_COMMUNICATION                 ((uint8) 0x0C)
#define CANSM_PN_WFLAG_IN_NOT_CC_SLEEP            ((uint8) 0x0E)
#define CANSM_PN_WFLAG_IN_NOT_CC_SLEEP_WAIT       ((uint8) 0x0F)
#define CANSM_PN_IN_NOT_CC_SLEEP_NOCOMM           ((uint8) 0x10)

/* Macro for Internal SubState in CANSM_BSM_DeinitPnNotSupported
                                                             sub state Machine*/
#define CANSM_WOPN_CS_STOPPED                     ((uint8) 0x00)
#define CANSM_WOPN_CS_STOPPED_WAIT                ((uint8) 0x01)
#define CANSM_WOPN_CS_SLEEP                       ((uint8) 0x02)
#define CANSM_WOPN_CS_SLEEP_WAIT                  ((uint8) 0x03)
#define CANSM_WOPN_TRCV_MODE_NORMAL               ((uint8) 0x04)
#define CANSM_WOPN_TRCV_MODE_NORMAL_WAIT          ((uint8) 0x05)
#define CANSM_WOPN_TRCV_MODE_STANDBY              ((uint8) 0x06)
#define CANSM_WOPN_TRCV_MODE_STANDBY_WAIT         ((uint8) 0x07)
#define CANSM_WOPN_NO_COMMUNICATION               ((uint8) 0x08)

/* Macros for CanSM Baudrate Substate Machine */
#define CANSM_BR_CC_STOPPED                       ((uint8) 0x00)
#define CANSM_BR_STARTED                          ((uint8) 0x02)
#define CANSM_BR_CC_ONLINE                        ((uint8) 0x04)

/* Macro for Internal SubState in CANSM_BSM_TX_TIMEOUTEXCEPTION
                                                            sub state Machine */
#define CANSM_TIMEOUT_CC_STOPPED                  ((uint8) 0x00)
#define CANSM_TIMEOUT_CC_STARTED                  ((uint8) 0x02)
#define CANSM_TIMEOUT_CC_ONLINE                   ((uint8) 0x04)

#define CANSM_E_WAITSTATE                         ((uint8) 0x80)

#define CANSM_TRCV_CLEARWUPFLAG_INDICATION        ((uint8) 0x03)
#define CANSM_TRCV_CHECKWUPFLAG_INDICATION        ((uint8) 0x04)

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

typedef struct STagTdd_CanSM_StaticNetwork
{
  /* Network handle ID */
  NetworkHandleType ucCanSmNetworkHandle;

  /* Dem Event ID */
  #if (STD_ON == CANSM_DEM_STATUS)
  Dem_EventIdType ddEventId;
  #endif

  /* Timer Values for Bus OFF Recovery */
  #if (STD_OFF == CANSM_BUSOFF_RECOVERY_MACRO_SUPPORT)
  CanSM_TimerType ddCanSMBorTimeL1;
  CanSM_TimerType ddCanSMBorTimeL2;
  CanSM_TimerType ddBorTimeTxEnsured;
  #endif

  /* Threshold value for transition from L1 to L2 timer value */
  #if (STD_OFF == CANSM_BOR_COUNTER_MACRO_SUPPORT)
  CanSM_BusOffCntType ddBorCounterL1ToL2;
  #endif

  /* Transceiver ID */
  #if (STD_ON == CANSM_CANTRCV_SUPPORT)
  uint8 ucCanSmTranceiverId;
  #endif

  /* Number of controller Configured per Network */
  #if (STD_OFF == CANSM_SINGLE_CNTRL_CHANNEL)
  uint8 ucNumberOfController;
  #endif
  /* Controller Index if single network */
  uint8 ucControllerIndex;

  /* Indicating Partial networking is Supported or not */
  #if (STD_ON == CANSM_PN_AVAILABILITY)
  boolean blPnSupported;
  #endif

  /* Parameter indicating if polling is enabled or not */
  #if (STD_ON == CANSM_BOR_TX_CONFIRMATION_POLLING)
  boolean blCanSMTxConfirmationPolling;
  #endif

  /* Parameter indicating if Dem error reporting is enabled*/
  #if (STD_ON == CANSM_DEM_STATUS)
  boolean blDemStatusFlag;
  #endif

  /* Dem Event ID */
  #if (STD_ON == CANSM_DEM_STATUS)
  Dem_EventIdType ddModeEventId;
  #endif
} Tdd_CanSM_StaticNetwork;

#if (STD_OFF == CANSM_SINGLE_NW_CHANNEL)
typedef P2FUNC(void, CANSM_CODE, CanSM_FunPtrType)
  (NetworkHandleType LddNetworkHandle);
#else
typedef P2FUNC(void, CANSM_CODE, CanSM_FunPtrType) (void);
#endif

/* Structure to pointers to function which mode transition in the CanSM */
typedef struct STag_CanSM_TransFuncPtr
{
  P2FUNC(void, CANSM_CODE, pTransFuncPtr)
  (NetworkHandleType LddNetworkHandle);
} CanSM_TransFuncPtr;

typedef struct STagTdd_CanSM_Network
{
  /* Variable to store baudrate value */
  #if (STD_ON == CANSM_CHANGE_BAUDRATE_API)
  uint16 usBaudrate;
  #endif
  /* Variable to store the timer value for the network */
  CanSM_TimerType ddTimer;

  /* Variable to store the Requested Time Value for the network */
  CanSM_TimerType ddCanSMModeReqReptTime;

  /* Variable to store the Bus off count value for the network */
  CanSM_BusOffCntType ddBusOffCounter;

  /* Variable to store the mode status for the network */
  uint8 ucModeStatus;

  /* Variable to store the requested mode status for the network */
  uint8 ucReqModeStatus;

  /* Variable to store the mode requested for Controllers and Transceiver
  for the network */
  uint8 ucMode;

  /* Variable to store controller count for the network */
  uint8 ucCanSMCtrlCount;

  /* Variable to store the internal state for the network */
  uint8 ucCanSMNWIntSubState;

  /* Variable to store the mode request repeat value for the network */
  uint8 ucCanSMModeReqReptMax;

  /* Variable to store the result for the valid baudrate check */
  #if (STD_ON == CANSM_CHANGE_BAUDRATE_API)
  uint8 ucResult;
  #endif
  
  /* Bug #703 - Add to check duplicate Bus off Event while Bus Off Recovery */
  /* Variable to store the Bus Off Repetition */
  uint8 ucBusOffRep;
  
} Tdd_CanSM_Network;

/* CanSM State type defined for initialization and deinitialization of CanSM */
typedef enum EtagCanSM_StateType
{
  CANSM_INITED = CANSM_TRUE,
  CANSM_UNINITED = CANSM_FALSE
} CanSM_StateType;

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/* Extern for CanSM_GaaStaticNetwork */
#define CANSM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Tdd_CanSM_StaticNetwork, CANSM_CONST) CanSM_GaaStaticNetwork[CANSM_NUMBER_OF_NETWORKS];
#define CANSM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Extern for CanSM_GaaInternalController */
#define CANSM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(uint8, CANSM_CONST) CanSM_GaaInternalController[CANSM_LAST_CONTROLLER_HANDLE];
#define CANSM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Extern for CanSM_GaaInternalNetwork */
#define CANSM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(NetworkHandleType, CANSM_CONST) CanSM_GaaInternalNetwork[CANSM_LAST_NETWORK_HANDLE];
#define CANSM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Extern for CanSM_GaaStaticController */
#define CANSM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(uint8, CANSM_CONST) CanSM_GaaStaticController[CANSM_LAST_CONTROLLER_HANDLE];
#define CANSM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (STD_ON == CANSM_CANTRCV_SUPPORT)
/* Extern for CanSM_GaaStaticTrvToNw */
#define CANSM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation(Array size will fixed in linking time)   */
extern CONST(NetworkHandleType, CANSM_CONST) CanSM_GaaStaticTrvToNw[];

#define CANSM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#endif /* CANSM_PCTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
