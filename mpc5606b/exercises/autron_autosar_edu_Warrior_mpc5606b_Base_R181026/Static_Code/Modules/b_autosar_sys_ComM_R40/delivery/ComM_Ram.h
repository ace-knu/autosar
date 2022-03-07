/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  INC-MODULE: ComM_Ram.h                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR COM Manager                                           **
**                                                                            **
**  PURPOSE   : Header file of ComM_Ram.c                                     **
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
** 1.0.7   15-May-2015   Kyungtae Kim     Cleared error against MISRA rule    **
** 1.0.6   04-Jul-2013   Daejun Park      CR~129, XAR~581 : ComM library      **
**                                        -Add new global arrays              **
**                                         ComM_GstFullComReq and             **
**                                         ComM_GaaNvmChannelInhibition       **
**                                         for library                        **
** 1.0.5   19-Jun-2013   Daejun Park      CR~120, XAR~559 : Bug fix           **
**                                        -Prevent ComM from switching to     ** 
**                                         NO_COMM while Nm requested         **
** 1.0.4   07-Jun-2013   Daejun Park      CR~118, XAR~557 : ComM library      **
**                                        -Add global variable                **
**                                         ComM_GaaUserRteInd                 **
** 1.0.1   12-Apr-2013   Nitin Kumar      As per SCR ASRBSW403_SCR_408,       **
**                                        memmap section is updated for       **
**                                        variable ComM_GaaTimeCnt.           **
** 1.0.0   17-Dec-2012   Ravi Tiwari            Initial version               **
*******************************************************************************/

#ifndef COMM_RAM_H
#define COMM_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComM_PCTypes.h"         /* Pre compile Types header file */
#include "ComM_Types.h"           /* ComM Types header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define COMM_RAM_AR_RELEASE_MAJOR_VERSION COMM_AR_RELEASE_MAJOR_VERSION
#define COMM_RAM_AR_RELEASE_MINOR_VERSION COMM_AR_RELEASE_MINOR_VERSION
#define COMM_RAM_AR_RELEASE_REVISION_VERSION\
  COMM_AR_RELEASE_REVISION_VERSION

/* FILE VERSION INFORMATION */
#define COMM_RAM_SW_MAJOR_VERSION         COMM_SW_MAJOR_VERSION
#define COMM_RAM_SW_MINOR_VERSION         COMM_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define COMM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "MemMap.h"

/* This array contains the Sub States of the channel */
extern VAR(ComM_StateType, COMM_VAR_POWER_ON_INIT)
ComM_GaaSubComMode[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "MemMap.h"

/* This array contains the Requested Com Mode of the Channel */
extern VAR(ComM_ModeType, COMM_VAR_POWER_ON_INIT)
ComM_GaaReqedComModeCnt[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "MemMap.h"

/* This array contains the Requested Communication mode of the User */
extern VAR(ComM_ModeType, COMM_VAR_POWER_ON_INIT)
ComM_GaaRequestedComMode[COMM_TOTAL_USERS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/* Global Variable to store initialization status of ComM */
extern VAR(ComM_InitStatusType, COMM_VAR_POWER_ON_INIT) ComM_GblInit;
#define COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_32
#include "MemMap.h"

/* This array contains the Timeout Counter of the Channel: Maximum Range */
extern VAR(uint32, COMM_VAR_POWER_ON_INIT)
ComM_GaaTimeCnt[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

#define COMM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "MemMap.h"

/* This variable contains the information which is to be stored in NvM */
extern VAR(ComM_Data, COMM_VAR_NOINIT) ComM_GstData;
#define COMM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "MemMap.h"

#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/* This array contains the Inhibition status of the Channels */
extern VAR(ComM_InhibitionStatusType, COMM_NO_INIT_DATA)
ComM_GaaChannelInhibition[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON))

#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/* This array contains the Sub PNC mode of the Pncs */
extern VAR(ComM_PncModeType, COMM_NO_INIT_DATA)
ComM_GaaSubPNCMode[COMM_TOTAL_PNCS];
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_16
#include "MemMap.h"

/* This array contains the PNC Timeout Counter of the Channel */
extern VAR(uint16, COMM_VAR_POWER_ON_INIT) 
 ComM_GaaPncTimeCnt[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

#endif /* End of if ((COMM_CANNETWORK_PRESENT == STD_ON) ||
        *(COMM_FRNETWORK_PRESENT == STD_ON)) */
#endif /* End of if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED ==
        *STD_ON)) */

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_8
#include "MemMap.h"

/* This array contains the Current Communication mode of the channels */
extern VAR(uint8, COMM_VAR_POWER_ON_INIT) ComM_GaaCurComMode[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_8
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_8
#include "MemMap.h"

/* This array contains the Network indications of the Channel */
extern VAR(uint8, COMM_VAR_POWER_ON_INIT)
ComM_GaaNmIndication[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_8
#include "MemMap.h"

#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON))
#define COMM_START_SEC_VAR_POWER_ON_CLEARED_8
#include "MemMap.h"

/* This array contains the signal to be TX from ComM */
extern VAR(uint8, COMM_VAR_POWER_ON_INIT) ComM_GaaSignalTx[PNC_COM_MAX_LENGTH];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_8
#include "MemMap.h"
#endif
#endif

#define COMM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

/* Global variable to store the number of channels left No Communication mode
 *   and entered Full Communication mode */
extern VAR(uint8, COMM_VAR_POWER_ON_INIT) ComM_GucChannelsFullComMode;
#define COMM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

/* This array contains whether Network is requested for the Channel */
extern VAR(uint8, COMM_VAR_POWER_ON_INIT) ComM_GaaNmRequested[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#if (COMM_FULL_NMVARIANT_SUPPORT == STD_ON)
#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the if SM is requested or not for the channels */
extern VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaNmRequestProcessing[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"
#endif

#define COMM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

/* This array contains the Inhibited Communication request of the channels
 *   during bus wake up inhibition */
extern VAR(uint8, COMM_VAR_POWER_ON_INIT)
ComM_GaaInhibitionReqst[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the information to track the user RTE indication */
extern VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaUserRteInd[COMM_TOTAL_USERS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the if SM is requested or not for the channels */
extern VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaModeRequested[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the wake up indication of the channels */
extern VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaWakeupIndication[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON))
#define COMM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the wake up indication of the channels */
extern VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaPNCWakeupIndication[COMM_TOTAL_PNCS];
#define COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
#endif
#endif

#define COMM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* Global Variable to store Limit ECU to No Communication inhibition */
extern VAR(boolean, COMM_VAR_POWER_ON_INIT) ComM_GblLimitEcuToNoCom;
#define COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* Global variable to indicate the DCM active diagnostic mode detected */
extern VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaDcmActiveDiagnostic[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* Global variable to indicate DCM inactive diagnostic mode detected */
extern VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaDcmInactiveDiagnostic[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* Global variable to store the Synchronous wakeup of all channels */
extern VAR(boolean, COMM_VAR_POWER_ON_INIT) ComM_GblWakeUp;
#define COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* Global variable to store if communication is allowed or not */
extern VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaCommunicationAllowed[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON))
#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the User PNC Requests */
extern VAR(boolean, COMM_NO_INIT_DATA)
ComM_GaaRequestedPNCMode[COMM_TOTAL_PNCS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the pnc Requested flags */
extern VAR(boolean, COMM_VAR_POWER_ON_INIT) ComM_GaaReqFlag[COMM_TOTAL_PNCS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the pnc Requested to pnc ready flags */
extern VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaReqToReadyFlag[COMM_TOTAL_PNCS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the status of PNC for Rx EIRA */
extern VAR(boolean, COMM_VAR_POWER_ON_INIT) ComM_GaaPncRxEIRA[COMM_TOTAL_PNCS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the Rx EIRA signal of Pncs */
extern VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaPncRxEIRASignal[COMM_TOTAL_PNCS*COMM_TOTAL_SIGNALS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

#if (COMM_PNC_GW_ENABLED == STD_ON)
#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the status of PNC for Rx ERAn */
extern VAR(boolean, COMM_VAR_POWER_ON_INIT) ComM_GaaPncRxERAn[COMM_TOTAL_PNCS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the Rx ERA signal of Pncs */
extern VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaPncRxERASignal[COMM_TOTAL_PNCS*COMM_TOTAL_SIGNALS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"
#endif /* End of if (COMM_PNC_GW_ENABLED == STD_ON) */
#endif /* End of if ((COMM_CANNETWORK_PRESENT == STD_ON) ||
        *(COMM_FRNETWORK_PRESENT == STD_ON)) */
#endif /* End of if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED ==
        *STD_ON)) */

#if ((COMM_FULLCOMM_REQ_NOTFN_ENABLED == STD_ON) &&\
  (COMM_DIRECT_USER_MAPPING == STD_OFF))
#define COMM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/* This array contains the Number of Full Communication Requests
   of the Channel during Inhibition State */
extern VAR(ComM_UserHandleArrayType, COMM_VAR_POWER_ON_INIT) ComM_GstFullComReq[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#if (COMM_NVM_BLOCK_DESCRIPTOR == STD_ON)
#define COMM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

/* This array contains NvM Inhibition Status of the Channel */
extern VAR(uint8, COMM_VAR_POWER_ON_INIT) ComM_GaaNvmChannelInhibition[COMM_NVMSTORE_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"
#endif

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* COMM_RAM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

