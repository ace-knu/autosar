/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  INC-MODULE: ComM_Config.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR COM Manager                                           **
**                                                                            **
**  PURPOSE   : Provision of external declaration of constant variables       **
**              to save the configured values                                 **
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
**                                         ComM_COMCbk from ComM_Internal.h   **
** 1.0.4   07-Jun-2013   Daejun Park      CR~118, XAR~557 : ComM library      **
**                                        -Add inclusion of header file       **
**                                         ComM.h                             **
**                                        -Add new constant variables         **
**                                         to replace macros in static code   **
**                                        -Move function prototype            **
**                                         ComM_MainFunction                  **
**										                     from ComM_Internal.h               **
*******************************************************************************/

#ifndef COMM_CONFIG_H_
#define COMM_CONFIG_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComM_PCTypes.h"
#include "ComStack_Types.h"       /* Communication Stack header file */
#include "ComM_Cfg.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define COMM_CONFIG_AR_RELEASE_MAJOR_VERSION COMM_AR_RELEASE_MAJOR_VERSION
#define COMM_CONFIG_AR_RELEASE_MINOR_VERSION COMM_AR_RELEASE_MINOR_VERSION
#define COMM_CONFIG_AR_RELEASE_REVISION_VERSION\
  COMM_AR_RELEASE_REVISION_VERSION

/* FILE VERSION INFORMATION */
#define COMM_CONFIG_SW_MAJOR_VERSION         COMM_SW_MAJOR_VERSION
#define COMM_CONFIG_SW_MINOR_VERSION         COMM_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define COMM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern const uint8 ComM_GucEcuGroupClassification;
extern const uint8 ComM_GucTotalUsers;
extern const uint8 ComM_GucTotalChannels;
extern const uint8 ComM_GucMaxChannelId;
extern const uint8 ComM_GucMaxUserId;

#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON))
extern const uint8 ComM_GucTotalPncs;
extern const uint8 ComM_GucTotalSignals;
extern const uint8 ComM_GucPncComMaxLength;
#endif
#endif

#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COMM_CODE) ComM_MainFunction(NetworkHandleType Channel);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON))

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_COMCbk */
extern FUNC(void, COMM_CODE) ComM_COMCbk(Com_SignalIdType SignalId);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#endif /*(COMM_PNC_SUPPORT == STD_ON)&& (COMM_PNC_ENABLED == STD_ON)*/
#endif /* End of if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED ==
        *STD_ON)) */

#endif /* COMM_CONFIG_H_ */
