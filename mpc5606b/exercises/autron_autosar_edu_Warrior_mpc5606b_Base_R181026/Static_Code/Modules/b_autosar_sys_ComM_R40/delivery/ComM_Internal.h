/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: ComM_Internal.h                                               **
**                                                                            **
**  TARGET    : ALL                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR COM Manager                                           **
**                                                                            **
**  PURPOSE   : Provision of Internal Main Function and                       **
**              sub functions to change the mode                              **
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
**                                        -Move function prototype            **
**                                         ComM_COMCbk to ComM_Config.h       **
** 1.0.4   07-Jun-2013   Daejun Park      CR~118, XAR~557 : ComM library      **
**                                        -Move function prototype            **
**                                         ComM_MainFunction                  **
**										                     to ComM_Config.h                   **
** 1.0.0   28-May-2013   Daejun Park         Initial version                  **
*******************************************************************************/

#ifndef COMM_INTERNAL_H
#define COMM_INTERNAL_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "ComM_PCTypes.h"         /* ComM Pre Compile Types header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION COMM_AR_RELEASE_MAJOR_VERSION
#define COMM_INTERNAL_AR_RELEASE_MINOR_VERSION COMM_AR_RELEASE_MINOR_VERSION
#define COMM_INTERNAL_AR_RELEASE_REVISION_VERSION\
  COMM_AR_RELEASE_REVISION_VERSION

/* FILE VERSION INFORMATION */
#define COMM_INTERNAL_SW_MAJOR_VERSION         COMM_SW_MAJOR_VERSION
#define COMM_INTERNAL_SW_MINOR_VERSION         COMM_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM Switch Communication Mode */
extern FUNC(void, COMM_CODE) ComM_SwitchComMMode(uint8 LucIndex, ComM_ModeType
  LddComMMode);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM Switch Mode to Full communication */
extern FUNC(void, COMM_CODE) ComM_SwitchToFullCom(uint8 LucIndex);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM Switch Mode to no communication */
extern FUNC(void, COMM_CODE) ComM_SwitchToNoCom(uint8 LucIndex);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for processing the Pending Request in no Communication */
extern FUNC(boolean, COMM_CODE) ComM_NoComNoPendingRequest(uint8 LucIndex);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for processing the Request Pending in no Communication */
extern FUNC(void, COMM_CODE) ComM_NoComRequestPending(uint8 LucIndex, boolean
  LblPassiveWakeFlag);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_ETHNETWORK_PRESENT == STD_ON))
#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for switching from ComM Full Communication To Silent Communication */
extern FUNC(void, COMM_CODE) ComM_FullComMToSilentComM(uint8 LucIndex);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if ((COMM_WAKEUP_INHIBITION_ENABLED == STD_ON) ||\
  (COMM_MODE_LIMITATION_ENABLED == STD_ON))
#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(boolean, COMM_CODE) ComM_RequestComModeInhibitionCheck(uint8
  LucIndex, ComM_ModeType LddComMMode);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if ((COMM_FULLCOMM_REQ_NOTFN_ENABLED == STD_ON) &&\
  (COMM_DIRECT_USER_MAPPING == STD_OFF))
#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COMM_CODE) ComM_RequestComModeRteUpdate(uint8 LucIndex, uint8
  LucUserIndex, ComM_ModeType LddComMMode);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (COMM_DEV_ERROR_DETECT == STD_ON)
#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_UserDETCheck*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_UserDETCheck(ComM_UserHandleType
  User, uint8 ApiId);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_ChannelDETCheck*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_ChannelDETCheck(NetworkHandleType
  Channel, uint8 ApiId);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* (COMM_DEV_ERROR_DETECT == STD_ON) */

#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON))

#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COMM_CODE) ComM_PncUserHandle(uint8 LucPncIndex,
  ComM_ModeType LddComMode);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COMM_CODE) ComM_PncUserLowestMode(uint8 LucUserIndx);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurComModePNC(uint8 LucIndex,
  P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) LddLowestMode);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Static function if current PNC mode is Full */
extern FUNC(void, COMM_CODE) ComM_PNCFullMode(uint8 LucPncIndex);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Static function if current PNC mode is No */
extern FUNC(void, COMM_CODE) ComM_PNCNoMode(uint8 LucPncIndex);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COMM_CODE) ComM_PNCComSigFullCom(uint8 LucIndex);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COMM_CODE) ComM_PNCNetwReq(uint8 LucPncInx, uint8
  LucByteIndex, uint8 LucMask, uint8 LucIndex);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COMM_CODE) ComM_ComSignalReception(Com_SignalIdType SignalId,
  P2CONST(uint8, AUTOMATIC, COMM_APPL_DATA) ComSignalRxPtr );

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COMM_CODE) ComM_PNCFullModePrepareSleep(uint8 LucPncIndex);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COMM_CODE) ComM_PNCFullModeReadySleep(uint8 LucPncIndex);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COMM_CODE) ComM_PNCFullModeRequested(uint8 LucPncIndex);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, COMM_CODE) ComM_RequestComModePNC(uint8
  LucUserIndex, ComM_ModeType ComMode);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#endif /*(COMM_PNC_SUPPORT == STD_ON)&& (COMM_PNC_ENABLED == STD_ON)*/
#endif /* End of if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED ==
        *STD_ON)) */

#if (COMM_DIRECT_CHANNEL == STD_ON)
#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, COMM_CODE) ComM_RequestComModeDirectChnl(uint8
  LucUserIndex, ComM_ModeType ComMode);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurComModeDirectChnl(uint8
  LucUserChannelIndex, uint8 LucNoOfChannels, P2VAR(ComM_ModeType, AUTOMATIC,
    COMM_APPL_DATA) LddLowestMode);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (COMM_DIRECT_CHANNEL == STD_ON) */

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* STATIC function if current comm mode is Full comm */
extern FUNC(void, COMM_CODE) ComM_FullComMode(uint8 LucIndex);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* STATIC function if current comm mode is No comm */
extern FUNC(void, COMM_CODE) ComM_NoComMode(uint8 LucIndex);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_ETHNETWORK_PRESENT == STD_ON))
#define COMM_START_SEC_CODE
#include "MemMap.h"

/* STATIC function if current comm mode is Silent comm */
extern FUNC(void, COMM_CODE) ComM_SilentComMode(uint8 LucIndex);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COMM_CODE) ComM_FullComNetwReq(uint8 LucIndex);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COMM_CODE) ComM_FullComReadySleep(uint8 LucIndex);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COMM_CODE) ComM_FullComNetwReqSubTwo(uint8 LucIndex);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#if ((COMM_LIGHT_NMVARIANT_SUPPORT == STD_ON) ||\
  (COMM_NONE_NMVARIANT_SUPPORT == STD_ON))
#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint8, COMM_CODE) ComM_FullComNetwReqSubOne(uint8 LucIndex);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#endif /* COMM_INTERNAL_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

