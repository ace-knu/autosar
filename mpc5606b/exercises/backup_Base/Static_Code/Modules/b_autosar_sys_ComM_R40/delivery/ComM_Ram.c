/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  INC-MODULE: ComM_Ram.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR COM Manager                                           **
**                                                                            **
**  PURPOSE   : Provision of Communication Manager Ram                        **
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
** 1.0.0   12-Apr-2013   Daejun Park      Initial version                     **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "ComM_Ram.h"             /* Global variables header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COMM_RAM_C_AR_RELEASE_MAJOR_VERSION    4
#define COMM_RAM_C_AR_RELEASE_MINOR_VERSION    0
#define COMM_RAM_C_AR_RELEASE_REVISION_VERSION 3

/* Software Version Information */
#define COMM_RAM_C_SW_MAJOR_VERSION            1
#define COMM_RAM_C_SW_MINOR_VERSION            0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (COMM_RAM_AR_RELEASE_MAJOR_VERSION != COMM_RAM_C_AR_RELEASE_MAJOR_VERSION)
#error "ComM_Ram.c : Mismatch in Specification Major Version"
#endif
#if (COMM_RAM_AR_RELEASE_MINOR_VERSION != COMM_RAM_C_AR_RELEASE_MINOR_VERSION)
#error "ComM_Ram.c : Mismatch in Specification Minor Version"
#endif
#if (COMM_RAM_AR_RELEASE_REVISION_VERSION !=\
     COMM_RAM_C_AR_RELEASE_REVISION_VERSION)
#error "ComM_Ram.c : Mismatch in Specification Revision Version"
#endif
#if (COMM_RAM_SW_MAJOR_VERSION != COMM_RAM_C_SW_MAJOR_VERSION)
#error "ComM_Ram.c : Mismatch in Software Major Version"
#endif
#if (COMM_RAM_SW_MINOR_VERSION != COMM_RAM_C_SW_MINOR_VERSION)
#error "ComM_Ram.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define COMM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "MemMap.h"

/* This array contains the Sub States of the channel */
VAR(ComM_StateType, COMM_VAR_POWER_ON_INIT)
ComM_GaaSubComMode[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "MemMap.h"

/* This array contains the Requested Com Mode of the Channel */
VAR(ComM_ModeType, COMM_VAR_POWER_ON_INIT)
ComM_GaaReqedComModeCnt[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "MemMap.h"

/* This array contains the Requested Communication mode of the User */
VAR(ComM_ModeType, COMM_VAR_POWER_ON_INIT)
ComM_GaaRequestedComMode[COMM_TOTAL_USERS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/* Global Variable to store initialization status of ComM */
VAR(ComM_InitStatusType, COMM_VAR_POWER_ON_INIT) ComM_GblInit;
#define COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_32
#include "MemMap.h"

/* This array contains the Timeout Counter of the Channel: Maximum Range */
VAR(uint32, COMM_VAR_POWER_ON_INIT)
ComM_GaaTimeCnt[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

#if ((COMM_FULLCOMM_REQ_NOTFN_ENABLED == STD_ON) &&\
  (COMM_DIRECT_USER_MAPPING == STD_OFF))
#define COMM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/* This array contains the Number of Full Communication Requests 
   of the Channel during Inhibition State */
VAR(ComM_UserHandleArrayType, COMM_VAR_POWER_ON_INIT) 
ComM_GstFullComReq[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#if (COMM_NVM_BLOCK_DESCRIPTOR == STD_ON)
#define COMM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

/* This array contains NvM Inhibition Status of the Channel */
VAR(uint8, COMM_VAR_POWER_ON_INIT) 
ComM_GaaNvmChannelInhibition[COMM_NVMSTORE_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"
#endif

#define COMM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "MemMap.h"

/* This variable contains the information which is to be stored in NvM */
VAR(ComM_Data, COMM_VAR_NOINIT) ComM_GstData;
#define COMM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "MemMap.h"

#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/* This array contains the Inhibition status of the Channels */
VAR(ComM_InhibitionStatusType, COMM_NO_INIT_DATA)
ComM_GaaChannelInhibition[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON))

#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/* This array contains the Sub PNC mode of the Pncs */
VAR(ComM_PncModeType, COMM_NO_INIT_DATA)
ComM_GaaSubPNCMode[COMM_TOTAL_PNCS];
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_16
#include "MemMap.h"

/* This array contains the PNC Timeout Counter of the Channel */
VAR(uint16, COMM_VAR_POWER_ON_INIT) ComM_GaaPncTimeCnt[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

#endif /* End of if ((COMM_CANNETWORK_PRESENT == STD_ON) ||
        *(COMM_FRNETWORK_PRESENT == STD_ON)) */
#endif /* End of if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED ==
        *STD_ON)) */

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_8
#include "MemMap.h"

/* This array contains the Current Communication mode of the channels */
VAR(uint8, COMM_VAR_POWER_ON_INIT) ComM_GaaCurComMode[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_8
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_8
#include "MemMap.h"

/* This array contains the Network indications of the Channel */
VAR(uint8, COMM_VAR_POWER_ON_INIT)
ComM_GaaNmIndication[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_8
#include "MemMap.h"

#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON))
#define COMM_START_SEC_VAR_POWER_ON_CLEARED_8
#include "MemMap.h"

/* This array contains the signal to be TX from ComM */
VAR(uint8, COMM_VAR_POWER_ON_INIT) ComM_GaaSignalTx[PNC_COM_MAX_LENGTH];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_8
#include "MemMap.h"
#endif
#endif

#define COMM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

/* Global variable to store the number of channels left No Communication mode
 *   and entered Full Communication mode */
VAR(uint8, COMM_VAR_POWER_ON_INIT) ComM_GucChannelsFullComMode;
#define COMM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

/* This array contains whether Network is requested for the Channel */
VAR(uint8, COMM_VAR_POWER_ON_INIT) ComM_GaaNmRequested[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#if (COMM_FULL_NMVARIANT_SUPPORT == STD_ON)

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the if SM is requested or not for the channels */
VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaNmRequestProcessing[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"
#endif

#define COMM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"

/* This array contains the Inhibited Communication request of the channels
 *   during bus wake up inhibition */
VAR(uint8, COMM_VAR_POWER_ON_INIT)
ComM_GaaInhibitionReqst[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the information to track the user RTE indication */
VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaUserRteInd[COMM_TOTAL_USERS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the if SM is requested or not for the channels */
VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaModeRequested[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the wake up indication of the channels */
VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaWakeupIndication[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"


#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON))
#define COMM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the wake up indication of the channels */
VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaPNCWakeupIndication[COMM_TOTAL_PNCS];
#define COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
#endif
#endif

#define COMM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* Global Variable to store Limit ECU to No Communication inhibition */
VAR(boolean, COMM_VAR_POWER_ON_INIT) ComM_GblLimitEcuToNoCom;
#define COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* Global variable to indicate the DCM active diagnostic mode detected */
VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaDcmActiveDiagnostic[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* Global variable to indicate DCM inactive diagnostic mode detected */
VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaDcmInactiveDiagnostic[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* Global variable to store the Synchronous wakeup of all channels */
VAR(boolean, COMM_VAR_POWER_ON_INIT) ComM_GblWakeUp;
#define COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* Global variable to store if communication is allowed or not */
VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaCommunicationAllowed[COMM_TOTAL_CHANNELS];
#define COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON))
#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the User PNC Requests */
VAR(boolean, COMM_NO_INIT_DATA)
ComM_GaaRequestedPNCMode[COMM_TOTAL_PNCS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the pnc Requested flags */
VAR(boolean, COMM_VAR_POWER_ON_INIT) ComM_GaaReqFlag[COMM_TOTAL_PNCS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the pnc Requested to pnc ready flags */
VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaReqToReadyFlag[COMM_TOTAL_PNCS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the status of PNC for Rx EIRA */
VAR(boolean, COMM_VAR_POWER_ON_INIT) ComM_GaaPncRxEIRA[COMM_TOTAL_PNCS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the Rx EIRA signal of Pncs */
VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaPncRxEIRASignal[COMM_TOTAL_PNCS*COMM_TOTAL_SIGNALS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

#if (COMM_PNC_GW_ENABLED == STD_ON)
#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the status of PNC for Rx ERAn */
VAR(boolean, COMM_VAR_POWER_ON_INIT) ComM_GaaPncRxERAn[COMM_TOTAL_PNCS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"

/* This array contains the Rx ERA signal of Pncs */
VAR(boolean, COMM_VAR_POWER_ON_INIT)
ComM_GaaPncRxERASignal[COMM_TOTAL_PNCS*COMM_TOTAL_SIGNALS];
#define COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#include "MemMap.h"
#endif /* End of if (COMM_PNC_GW_ENABLED == STD_ON) */
#endif /* End of if ((COMM_CANNETWORK_PRESENT == STD_ON) ||
        *(COMM_FRNETWORK_PRESENT == STD_ON)) */
#endif /* End of if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED ==
        *STD_ON)) */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

