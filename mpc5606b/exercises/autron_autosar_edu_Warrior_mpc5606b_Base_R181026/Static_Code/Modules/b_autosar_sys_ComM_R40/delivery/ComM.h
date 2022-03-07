/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: ComM.h                                                        **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR COM Manager                                           **
**                                                                            **
**  PURPOSE   : Provision of external declaration of APIs and Service IDs     **
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
** 1.0.0   17-Dec-2012   Daejun Park            Initial version               **
*******************************************************************************/

#ifndef COMM_H
#define COMM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComStack_Types.h"       /* Communication Stack header file */
#include "Rte_ComM_Type.h"        /* Rte and ComM types header file */
#include "NvM_Types.h"            /* NvM types header file */
#include "ComM_Cfg.h"             /* Module configuration header file*/
#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
#include "Com.h"                  /* Com Module header file */
#endif
#include "ComM_Types.h"           /* ComM Types header file */
#include "ComM_PCTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Instance ID for DET report error */
#define COMM_INSTANCE_ID                   0x00

/* Service ID for ComM_COMCbk */
#define COMM_COMCBK_SID                    0x61

/* Service ID for Main Function */
#define COMM_MAINFUNCTION_SID              0x60

/* Service ID for ComM_Init */
#define COMM_INIT_SID                      0x01

/* Service ID for ComM_DeInit */
#define COMM_DEINIT_SID                    0x02

/* Service ID for ComM_GetState */
#define COMM_GETSTATE_SID                  0x34

/* Service ID for ComM_GetStatus */
#define COMM_GETSTATUS_SID                 0x03

/* Service ID for ComM_GetInhibitionStatus */
#define COMM_GETINHIBITIONSTATUS_SID       0x04

/* Service ID for ComM_RequestComMode */
#define COMM_REQUESTCOMMODE_SID            0x05

/* Service ID for ComM_GetRequestedComMode */
#define COMM_GETREQUESTEDCOMMODE_SID       0x07

/* Service ID for ComM_GetCurrentComMode */
#define COMM_GETCURRENTCOMMODE_SID         0x08

/* Service ID for ComM_PreventWakeUp */
#define COMM_PREVENTWAKEUP_SID             0x09

/* Service ID for ComM_LimitChannelToNoComMode */
#define COMM_LIMITCHANNELTONOCOMMODE_SID   0x0b

/* Service ID for ComM_LimitECUToNoComMode */
#define COMM_LIMITECUTONOCOMMODE_SID       0x0c

/* Service ID for ComM_ReadInhibitCounter */
#define COMM_READINHIBITCOUNTER_SID        0x0d

/* Service ID for ComM_ResetInhibitCounter */
#define COMM_RESETINHIBITCOUNTER_SID       0x0e

/* Service ID for ComM_SetECUGroupClassification */
#define COMM_SETECUGROUPCLASSIFICATION_SID 0x0f

/* Service ID for ComM_GetVersionInfo */
#define COMM_GETVERSIONINFO_SID            0x10

/* Service ID for ComM_Nm_NetworkStartIndication */
#define COMM_NM_NETWORKSTARTINDICATION_SID 0x15

/* Service ID for ComM_Nm_NetworkMode */
#define COMM_NM_NETWORKMODE_SID            0x18

/* Service ID for ComM_Nm_PrepareBusSleepMode */
#define COMM_NM_PREPAREBUSSLEEPMODE_SID    0x19

/* Service ID for ComM_Nm_BusSleepMode */
#define COMM_NM_BUSSLEEPMODE_SID           0x1a

/* Service ID for ComM_Nm_RestartIndication */
#define COMM_NM_RESTARTINDICATION_SID      0x1b

/* Service ID for ComM_DCM_ActiveDiagnostic */
#define COMM_DCM_ACTIVEDIAGNOSTIC_SID      0x1f

/* Service ID for ComM_DCM_InactiveDiagnostic */
#define COMM_DCM_INACTIVEDIAGNOSTIC_SID    0x20

/* Service ID for ComM_CommunicationAllowed */
#define COMM_COMMUNICATIONALLOWED_SID      0x35

/* Service ID for ComM_Ecum_WakeUpIndication */
#define COMM_ECUM_WAKEUPINDICATION_SID     0x2a

/* Service ID for ComM_BusSM_ModeIndication */
#define COMM_BUSSM_MODEINDICATION_SID      0x33

/* Service ID for ComM_ResetRequestedChannel */
#define COMM_RESETREQUESTEDCHANNEL_SID      0x36


#define COMM_RTE_NOTIF (STD_OFF)
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_Init */
extern FUNC(void, COMM_CODE) ComM_Init(void);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_DeInit */
extern FUNC(void, COMM_CODE) ComM_DeInit(void);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_ResetRequestedChannel */
extern FUNC(void, COMM_CODE) ComM_ResetRequestedChannel(NetworkHandleType Channel);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"


#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_GetStatus */
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetStatus(P2VAR(ComM_InitStatusType,
  AUTOMATIC, COMM_APPL_DATA) Status);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_GetState */
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetState(NetworkHandleType Channel,
  P2VAR(ComM_StateType, AUTOMATIC, COMM_APPL_DATA) State);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#if ((COMM_WAKEUP_INHIBITION_ENABLED == STD_ON) ||\
  (COMM_MODE_LIMITATION_ENABLED == STD_ON))
#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_GetInhibitionStatus */
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetInhibitionStatus(
  NetworkHandleType Channel, P2VAR(ComM_InhibitionStatusType, AUTOMATIC,
  COMM_APPL_DATA) Status);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_RequestComMode */
extern FUNC(Std_ReturnType, COMM_CODE) ComM_RequestComMode(ComM_UserHandleType
  User, ComM_ModeType ComMode);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_GetRequestedComMode */
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetRequestedComMode(
  ComM_UserHandleType User, P2VAR(ComM_ModeType, AUTOMATIC,
  COMM_APPL_DATA) ComMode);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_GetCurrentComMode */
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurrentComMode(
  ComM_UserHandleType User, P2VAR(ComM_ModeType, AUTOMATIC,
  COMM_APPL_DATA) ComMode);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_SetECUGroupClassification */
extern FUNC(Std_ReturnType, COMM_CODE) ComM_SetECUGroupClassification(
  ComM_InhibitionStatusType Status);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#if (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_PreventWakeUp */
extern FUNC(Std_ReturnType, COMM_CODE) ComM_PreventWakeUp(NetworkHandleType
  Channel, boolean Status);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_LimitChannelToNoComMode */
extern FUNC(Std_ReturnType, COMM_CODE) ComM_LimitChannelToNoComMode(
  NetworkHandleType Channel, boolean Status);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_ReadInhibitCounter */
extern FUNC(Std_ReturnType, COMM_CODE) ComM_ReadInhibitCounter(P2VAR(uint16,
  AUTOMATIC, COMM_APPL_DATA) CounterValue);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_ResetInhibitCounter */
extern FUNC(Std_ReturnType, COMM_CODE) ComM_ResetInhibitCounter(void);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_LimitECUToNoComMode */
extern FUNC(Std_ReturnType, COMM_CODE) ComM_LimitECUToNoComMode(boolean Status);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (COMM_MODE_LIMITATION_ENABLED == STD_ON) */

#if (COMM_VERSION_INFO_API == STD_ON)
#define COMM_START_SEC_CODE
#include "MemMap.h"

/* Extern for ComM_GetVersionInfo */
extern FUNC(void, COMM_CODE) ComM_GetVersionInfo(P2VAR(Std_VersionInfoType,
  AUTOMATIC, COMM_APPL_DATA) Versioninfo);

#define COMM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#endif /* COMM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

