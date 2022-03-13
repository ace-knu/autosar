/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: ComM_Config.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR COM Manager                                           **
**                                                                            **
**  PURPOSE   : Provision of definition of constant variables                 **
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
** 1.0.4   07-Jun-2013   Daejun Park      CR~118, XAR~557 : ComM library      **
**                                        -Add inclusion of header file       **
**                                         ComM_Config.h                      **
**                                        -Add new constant variables         **
**                                         to replace macros in static code   **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComM_Config.h"
#include "ComM_Cfg.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COMM_CONFIG_C_AR_RELEASE_MAJOR_VERSION    4
#define COMM_CONFIG_C_AR_RELEASE_MINOR_VERSION    0
#define COMM_CONFIG_C_AR_RELEASE_REVISION_VERSION 3

/* Software Version Information */
#define COMM_CONFIG_C_SW_MAJOR_VERSION            1
#define COMM_CONFIG_C_SW_MINOR_VERSION            0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (COMM_CONFIG_AR_RELEASE_MAJOR_VERSION !=\
     COMM_CONFIG_C_AR_RELEASE_MAJOR_VERSION)
#error "ComM_Config.c : Mismatch in Specification Major Version"
#endif

#if (COMM_CONFIG_AR_RELEASE_MINOR_VERSION !=\
     COMM_CONFIG_C_AR_RELEASE_MINOR_VERSION)
#error "ComM_Config.c : Mismatch in Specification Minor Version"
#endif

#if (COMM_CONFIG_AR_RELEASE_REVISION_VERSION !=\
     COMM_CONFIG_C_AR_RELEASE_REVISION_VERSION)
#error "ComM_Config.c : Mismatch in Specification Revision Version"
#endif

#if (COMM_CONFIG_SW_MAJOR_VERSION != COMM_CONFIG_C_SW_MAJOR_VERSION)
#error "ComM_Config.c : Mismatch in Major Version"
#endif

#if (COMM_CONFIG_SW_MINOR_VERSION != COMM_CONFIG_C_SW_MINOR_VERSION)
#error "ComM_Config.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define COMM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

const uint8 ComM_GucEcuGroupClassification = COMM_ECU_GROUP_CLASSIFICATION;
const uint8 ComM_GucTotalUsers = COMM_TOTAL_USERS;
const uint8 ComM_GucTotalChannels = COMM_TOTAL_CHANNELS;
const uint8 ComM_GucMaxChannelId = COMM_MAX_CHANNELID;
const uint8 ComM_GucMaxUserId = COMM_MAX_USERID;

#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON))
const uint8 ComM_GucTotalPncs = COMM_TOTAL_PNCS;
const uint8 ComM_GucTotalSignals = COMM_TOTAL_SIGNALS;
const uint8 ComM_GucPncComMaxLength = PNC_COM_MAX_LENGTH;
#endif
#endif

#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

