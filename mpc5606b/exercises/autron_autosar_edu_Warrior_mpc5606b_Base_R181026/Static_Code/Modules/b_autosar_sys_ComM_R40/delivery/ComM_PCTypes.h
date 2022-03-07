/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  INC-MODULE: ComM_PCTypes.h                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR COM Manager                                           **
**                                                                            **
**  PURPOSE   : Provision of pre-compile time parameters                      **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date             By                   Description                **
********************************************************************************
** 1.7.14    19-Jun-2017      Jeonghan Jeong       #6530                      **
** 1.0.8     20-Jun-2016      Kyungtae Kim         #4959 #5147                **
** 1.0.6     04-Jul-2013      Daejun Park          CR~129, XAR~581            **
** 1.0.0     28-May-2013      Daejun Park          Initial Version            **
*******************************************************************************/

#ifndef COMM_PCTYPES_H
#define COMM_PCTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComM.h"                 /* ComM header file */
#if (COMM_LINNETWORK_PRESENT == STD_ON)
#include "LinSM.h"                /* LinSM Module header file */
#endif
#if (COMM_CANNETWORK_PRESENT == STD_ON)
#include "CanSM.h"                /* CanSM Module header file */
#include "CanSM_ComM.h"           /* CanSM and ComM Module header file */
#endif
#if (COMM_FRNETWORK_PRESENT == STD_ON)
#include "FrSM.h"                 /* FrSM Module header file */
#endif
#if (COMM_ETHNETWORK_PRESENT == STD_ON)
#include "EthSM.h"                /* EthSM Module header file */
#endif
#if (COMM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"                  /* Det Module header file */
#endif

/*******************************************************************************
**                       Version Information                                  **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define COMM_PCTYPES_AR_RELEASE_MAJOR_VERSION (COMM_AR_RELEASE_MAJOR_VERSION)
#define COMM_PCTYPES_AR_RELEASE_MINOR_VERSION (COMM_AR_RELEASE_MINOR_VERSION)
#define COMM_PCTYPES_AR_RELEASE_REVISION_VERSION\
  (COMM_AR_RELEASE_REVISION_VERSION)

/* FILE VERSION INFORMATION */
#define COMM_PCTYPES_SW_MAJOR_VERSION         (COMM_SW_MAJOR_VERSION)
#define COMM_PCTYPES_SW_MINOR_VERSION         (COMM_SW_MINOR_VERSION)
#define COMM_PCTYPES_SW_PATCH_VERSION         (COMM_SW_PATCH_VERSION)

/*******************************************************************************
**                       Global Data Types                                    **
*******************************************************************************/

/*
 * DET ERRORS
 * This Det error is returned of API service is used without ComM initialized
 */
#define COMM_E_NOT_INITED                     (0x01)

/* This Det error is returned of API service is used with wrong parameters */
#define COMM_E_WRONG_PARAMETERS               (0x02)

/* ComM return types */
#ifndef COMM_E_MODE_LIMITATION
#define COMM_E_MODE_LIMITATION                (0x02)
#endif

#ifndef COMM_E_UNINIT
#define COMM_E_UNINIT                         (0x03)
#endif



/* Inhibition status Masks */
#define COMM_LIMITCHNTONOCOM_MASK             (0x02)
#define COMM_PREVENTWAKEUP_MASK               (0x01)

/* Prevent Wakeup Masks*/
#define COMM_PREVENTWAKEUP_MASK_SET           (0x01)
#define COMM_PREVENTWAKEUP_MASK_CLR           ((uint8) 0xFE)

/* Limit Channel to No Communication Masks*/
#define COMM_LIMITCHANNELTONOCOMM_MASK_SET    (0x02)
#define COMM_LIMITCHANNELTONOCOMM_MASK_CLR    ((uint8) 0xFD)

/* Network Mode Indications */
#define COMM_NMSTART_IND                      (0x01)
#define COMM_NMMODE_IND                       (0x02)
#define COMM_BUSSLEEPMODE_IND                 (0x03)
#define COMM_PREPBUSSLEEPMODE_IND             (0x04)
#define COMM_NMRST_IND                        (0x05)

/* Nm Variants */
#define COMM_NMVARIANT_NONE                   (0x00)
#define COMM_NMVARIANT_LIGHT                  (0x01)
#define COMM_NMVARIANT_FULL                   (0x02)
#define COMM_NMVARIANT_PASSIVE                (0x03)

/* Internal Bus Type */
#define COMM_INTERNAL                         (0x03)
#define COMM_NUMBER_OF_BUS_TYPES              (0x05)

/* Number of Bus Type */

/* Macros used to set, check masked values of various global variables */
#define COMM_ZERO                             (0x00)
#define COMM_ONE                              (0x01)
#define COMM_TWO                              (0x02)
#define COMM_THREE                            (0x03)
#define COMM_FOUR                             (0x04)
#define COMM_EIGHT                            (0x08)

/* Inhibition Status range for Set Ecu Group Classification */
#define COMM_INHIBITION_RANGE                 (0x03)

/* Macro to know if user request for mode change is accepted */
#define COMM_FULLCOMMREQ_ACCPTD               (COMM_ONE)
#define COMM_NOCOMMREQ_ACCPTD                 (COMM_TWO)

/* True / False / Invalid */
#define COMM_TRUE                             (COMM_ONE)
#define COMM_FALSE                            (COMM_ZERO)
#define COMM_INVALID_CHANNEL                  (COMM_TOTAL_CHANNELS)
#define COMM_INVALID_USER                     (COMM_TOTAL_USERS)

/* Not used User Id */
#define COMM_NOT_USED_USER_ID                 ((uint8) 255)

/* Maximum Inhibit counter value */
#define COMM_INHIBITCNT_MAX                   ((uint16) 65535)

#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON))

/*PNC Gateway */
#define COMM_ACTIVE_GW                        (0X00)
#define COMM_PASSIVE_GW                       (0X01)

/*Type Of Signal*/
#define COMM_EIRA                             (0x00)
#define COMM_ERA                              (0x01)

/*Types Of PNC User Requests*/
#define PNC_USER_NO_COMM                      (0x00)
#define PNC_USER_FULL_COMM                    (0x01)

/*Type Of Signal Direction*/
#define COMM_RX                               (0x00)
#define COMM_TX                               (0x01)

#endif /* End of if ((COMM_CANNETWORK_PRESENT == STD_ON) ||
        *(COMM_FRNETWORK_PRESENT == STD_ON)) */
#endif /* End of if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED ==
        *STD_ON)) */

typedef struct STag_ComM_Data
{
  /*Ecugroup Type  ComMEcuGroupClassification*/
  ComM_InhibitionStatusType ddComMEcuInhibition;

  #if (COMM_MODE_LIMITATION_ENABLED == STD_ON)

  /*Inhibit counter ----> ComMNoCom */
  uint16 usComMFullComInhibitCounter;
  #endif
} ComM_Data;

/*----------------------------------------------------------------------------*/
typedef struct STag_ComM_Channels
{
  /* This structure element contains the channel identification number of the
   * channel.
   * --> ComMChannelId */
  NetworkHandleType ddChannelId;

  /*
   * This structure element defines the timeout after state ready sleep is
   * left.
   * --> ComMNmLightTimeout*/
  #if (COMM_LIGHT_NMVARIANT_SUPPORT == STD_ON)
  ComM_TimeType ddNmLightTimeout;
  #endif

  /*
   * This structure element contains the minimum time duration in
   * full communication mode.
   * Derivation: ComMTMinFullComModeDuration/ComMMainFunctionPeriod*/
  uint16 usMinFullComMode;

  /*
   * Time in seconds the pnc state machine shall wait in sub-state
   * PNC_PREPARE_SLEEP
   * Derivation: ComMPncPrepareSleepTimer/ComMMainFunctionPeriod */
  #if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
  #if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT ==\
    STD_ON))

  uint16 usPncPrepareSleepTimer;
  #endif
  #endif

  /*
   * This variable contains the bus type of the channel.
   * 0 - CAN, 1 - Ethernet, 2 - FlexRay, 4 - LIN
   * --> ComMBusType */
  uint8 ucBusType;

  /*This variable contains the Gateway behaviour of a ComMChannel..
   * 0 - Active, 1 - Passive, 2 - Invalid
   * --> ComMPncGatewayType*/
  #if (((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))\
  && (COMM_PNC_GW_ENABLED == STD_ON))
  uint8 ucPncGatewayType;
  #endif

  /*
   * This structure element defines the functionality of the network
   * management.
   * --> ComMNmVariant*/
  uint8 ucNmVariant;

  /* This structure element defines bit 0 defines ComMNoWakeup inhibition, not
   * allowing ECU to wake up the channel, bit 1 defines
   * ComMNoCom, not allowing channel to switch to Silent or Full communication
   * --> ComMGlobalNvmBlockDescriptor*/
  #if ((COMM_WAKEUP_INHIBITION_ENABLED == STD_ON) ||\
  (COMM_MODE_LIMITATION_ENABLED == STD_ON))
  uint8 ucComMInhibition;
  #endif

  #if (COMM_DIRECT_CHANNEL == STD_ON)

  /*
   *-----------------------ComMUserPerChannel --------------------------------
   * This should only be present if it is not a part of any PNC Cluster
   */

  /* This stucture element contains the starting index to ChannelToUserMapping
   * array pointing to the user of this channel*/
  uint8 ucChannelUserIndex;

  /* This structure element contains the number of users associated with a
   * particular channel */
  uint8 ucChannelUserCount;

  /*-------------------------------------------------------------------------*/
  #endif /* End of if (COMM_DIRECT_CHANNEL == STD_ON) */

  #if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
  #if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT ==\
    STD_ON))

  /* This stucture element contains the starting index to ChannelToPncMapping
   * array pointing to the user of this channel*/
  uint8 ucPncIndex;

  /* This structure element contains the number of Pnc associated with a
   * particular channel */
  uint8 ucPncCount;

  /* Every time Nm shall be called using the API Nm_NetworkRequest when, FULL
   * Communication is requested due to a change in the PNC state machine to
   * PNC_REQUESTED.
   * -->  ComMPncNmRequest */
  boolean blPncNmRequest;

  /*
   * boolean parameter that defines whether Channel is part of PNC cluster
   * ComMChannelPerPnc: If the Channel is refered by any PNC : TRUE
   */
  boolean blChannelPnc;
  #endif /* End of if ((COMM_CANNETWORK_PRESENT == STD_ON) ||
          *(COMM_FRNETWORK_PRESENT == STD_ON)) */
  #endif /* End of if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED ==
          *STD_ON)) */

  /* This structure element defines if the optional SenderReceiver Port of
   * Interface ComM_CurrentChannelRequest will be provided for this channel.
   * --> ComMFullCommRequestNotificationEnabled*/
  #if ((COMM_FULLCOMM_REQ_NOTFN_ENABLED == STD_ON) && \
    (COMM_DIRECT_USER_MAPPING == STD_OFF))
  boolean blFullCommReqNotifEn;
  #endif

  /* This structure element defines if the NoWakeUp inhibition state of the
   * channel shall be stored in the block: ComMGlobalNvmBlockDescriptor.
   * --> ComMGlobalNvmBlockDescriptor*/
  #if ((COMM_NVM_BLOCK_DESCRIPTOR == STD_ON) &&\
  ((COMM_WAKEUP_INHIBITION_ENABLED == STD_ON) ||\
  (COMM_MODE_LIMITATION_ENABLED == STD_ON)))
  boolean blNoWakeUpNvmStorage;
  #endif
} ComM_Channels;

typedef struct STag_ComM_Users
{
  /*
   * This structure element contains the user identification number of the
   * corresponding user.
   */
  ComM_UserHandleType ddUserId;

  #if (COMM_DIRECT_CHANNEL == STD_ON)

  /*
   *------The channel is implicit already referenced by the PNC ---
   *Avoid redundant configuration
   */

  /* This structure element contains the number of channels for the users not
   *   using PNC */
  uint8 ucNoOfDirectChannels;

  /* This structure element contains index of DirectChannelIndexArray array. */
  uint8 ucDirectChannelIndex;

  /*------------------------------------------------------------------------*/
  #endif /* End of if (COMM_DIRECT_CHANNEL == STD_ON) */

  #if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
  #if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT ==\
    STD_ON))

  /* This structure element gives the number of users linked to the PNC */
  uint8 ucNoOfPncUser;

  /* User start index for the current channel */
  uint8 ucPncUserIndex;
  #endif
  #endif
} ComM_Users;

/*--------------------Structure for PNC states------------------------------- */
#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON))
typedef struct STag_ComM_Pncs
{
  PNCHandleType ddPncId;

  /*
   *--------------------ComMPncComSignal--------------------------------------
   * This structure element gives the number of Com Signals linked to the Pnc
   */
  uint16 usNoOfComSignal;

  /* Com Signals index for the current PNC*/
  uint16 usComSignalIndex;

  /*
   *--------------For Reference to [ ComMusers ]----------------------------
   * This structure element gives the number of users linked to the Pnc
   */
  uint8 ucUserCount;

  /* User start index for the current channel */
  uint8 ucUserIndex;

  /*
   *--------------For Reference to [ ComMChannel ]----------------------------
   * This structure element contains the number of channels for the user.
   */
  uint8 ucNoOfChannelPnc;

  /* This structure element conatains index of ChannelIndexArray array. */
  uint8 ucChannelPncIndex;
} ComM_Pncs;

/*--------------------Structure for ComMPncComSignal------------------------- */
typedef struct STag_ComM_ComSignal
{
  /*Reference to [ ComSignal ]*/
  Com_SignalIdType ddComMComSigId;

  /*Reference to [ ComMChannel ]*/
  #if (COMM_PNC_GW_ENABLED == STD_ON)
  NetworkHandleType ddComMChannelId;
  #endif

  /*ComMPncComSignalDirection*/
  uint8 ucComMPncComSigDir;

  /*ComMPncComSignalKind*/
  uint8 ucComMPncComSignalKind;
} ComM_ComSignal;
#endif /* End of if ((COMM_CANNETWORK_PRESENT == STD_ON) ||
        *(COMM_FRNETWORK_PRESENT == STD_ON)) */
#endif /* End of if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED ==
        *STD_ON)) */

/*--------------------------------------------------------------------------- */
#if (COMM_FUNC_BUSSMCOMMODE_SUPPORT == STD_ON)

/* typedef for handling function pointer for requesting communication mode from
 *   corresponding SM */
typedef P2FUNC(Std_ReturnType, COMM_APPL_CODE, ComM_SMReqComModeFuncPtr)
  (NetworkHandleType ddChannelId, ComM_ModeType ComMode);

/* typedef for handling function pointer to get current communication mode from
 *   corresponding SM*/
typedef P2FUNC(Std_ReturnType, COMM_APPL_CODE, ComM_SMGetCurComModeFuncPtr)
  (NetworkHandleType ddChannelId, P2VAR(ComM_ModeType, AUTOMATIC,
    COMM_APPL_DATA)
  ComModePtr);

#define COMM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Array containing pointer to function for SM Get current mode API */
extern CONST(ComM_SMGetCurComModeFuncPtr, COMM_CONST)
ComM_GaaSMGetCurComModeFun[COMM_NUMBER_OF_BUS_TYPES];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define COMM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Array containing pointer to function for SM request mode API */
extern CONST(ComM_SMReqComModeFuncPtr, COMM_CONST) 
ComM_GaaSMReqComModeFun[COMM_NUMBER_OF_BUS_TYPES];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /* (COMM_FUNC_BUSSMCOMMODE_SUPPORT == STD_ON) */

#if (COMM_USER_SEQUENTIAL == STD_OFF)
#define COMM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Array used for mapping User Id to be sequential */
extern CONST(ComM_UserHandleType, COMM_CONST) 
ComM_GaaUserMapArray[COMM_MAX_USERID + COMM_ONE];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if (COMM_CHANNEL_SEQUENTIAL == STD_OFF)
#define COMM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Array used for mapping Channel Id to be sequential */
extern CONST(NetworkHandleType, COMM_CONST) 
ComM_GaaChannelMapArray[COMM_MAX_CHANNELID + COMM_ONE];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#if (COMM_DIRECT_CHANNEL == STD_ON)
#define COMM_START_SEC_CONST_8
#include "MemMap.h"

/* Channel to user map array : In channels, Channel Index --> User ID */
extern CONST(ComM_UserHandleType, COMM_CONST) 
ComM_GaaChannelToUserMapping[COMM_NUMBER_OF_USERTOCHANNEL];
#define COMM_STOP_SEC_CONST_8
#include "MemMap.h"
#endif

#define COMM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Array containing user data structure information */
extern CONST(ComM_Users, COMM_CONST) ComM_GaaUsers[COMM_TOTAL_USERS];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (COMM_DIRECT_CHANNEL == STD_ON)
#define COMM_START_SEC_CONST_8
#include "MemMap.h"
/* Channel indices array : In Users, Direct Channel Index --> Channel Index*/
extern CONST(uint8, COMM_CONST) ComM_GaaChnInxArr[COMM_NUMBER_OF_USERTOCHANNEL];
#define COMM_STOP_SEC_CONST_8
#include "MemMap.h"
#endif

#define COMM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Array containing channel data structure information */
extern CONST(ComM_Channels, COMM_CONST) ComM_GaaChannels[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*--------------------PNC is implemented-------------------------------------*/
#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON))
#define COMM_START_SEC_CONST_8
#include "MemMap.h"

/* Channel to PNC map array for PNC associated with the channel */
extern CONST(ComM_UserHandleType, COMM_CONST) ComM_GaaPncToUserMapping[];
#define COMM_STOP_SEC_CONST_8
#include "MemMap.h"

#define COMM_START_SEC_CONST_8
#include "MemMap.h"

/* Channel indices array : In Pnc, Channel Index --> Channel ID */
extern CONST(NetworkHandleType, COMM_CONST) ComM_GaaChnPncInxArr[];
#define COMM_STOP_SEC_CONST_8
#include "MemMap.h"

#define COMM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Array containing PNC data structure information */
extern CONST(ComM_Pncs, COMM_CONST) ComM_GaaPncs[COMM_TOTAL_PNCS];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*------------PNC ComSignal related information to be stored------------------*/
#define COMM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Array containing ComSignal data structure information */
extern CONST(ComM_ComSignal, COMM_CONST)
ComM_GaaComSignal[COMM_TOTAL_SIGNALS];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define COMM_START_SEC_CONST_8
#include "MemMap.h"

/* Pnc indices array : In Users, Index --> PNC Index*/
extern CONST(uint8, COMM_CONST) ComM_GaaPncUserInxArr[];
#define COMM_STOP_SEC_CONST_8
#include "MemMap.h"

#define COMM_START_SEC_CONST_8
#include "MemMap.h"

/* Channel to PNC map array : In Channels, Channel Index --> PNC Index */
extern CONST(uint8, COMM_CONST) ComM_GaaChannelToPncMapping[];
#define COMM_STOP_SEC_CONST_8
#include "MemMap.h"
#endif /* End of if ((COMM_CANNETWORK_PRESENT == STD_ON) ||
        *(COMM_FRNETWORK_PRESENT == STD_ON)) */
#endif /* End of if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED ==
        *STD_ON)) */

#define COMM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* This variable contains the default values is to be stored from NvM */
extern CONST(ComM_Data, COMM_CONST) ComM_GstConstData;
#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if ((COMM_FULLCOMM_REQ_NOTFN_ENABLED == STD_ON) &&\
  (COMM_DIRECT_USER_MAPPING == STD_OFF))
extern CONST(ComM_UserHandleArrayType, COMM_CONST) 
ComM_GaaConstFullComReq[COMM_TOTAL_CHANNELS];
#endif

#if (COMM_NVM_BLOCK_DESCRIPTOR == STD_ON)
extern CONST(uint8, COMM_CONST) 
ComM_GaaConstChannelInhibitStatus[COMM_NVMSTORE_CHANNELS];
#endif

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* COMM_PCTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

