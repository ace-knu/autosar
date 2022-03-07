/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf_Types.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : Type definition of AUTOSAR CanIf                              **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By              Description                        **
********************************************************************************
** 2.5.0    06-Dec-2016    Js.Lim      #7077                                  **
** 2.0.1    16-Sep-2013    Kt.Kim      CanIf_BatVolSetModeType Added          **
** 1.0.0    04-Feb-2013    Kt.Kim      Initial version                        **
*******************************************************************************/

#ifndef CANIF_TYPES_H
#define CANIF_TYPES_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf_Can.h"                  /* CAN Driver Module Header File */
#include "CanIf_Cfg.h"
#if (STD_ON == CANIF_CANTRCV_SUPPORT)
#include "CanIf_CanTrcv.h"              /* CAN Transceiver Module Header File */
#endif
#include "Can_GeneralTypes.h"           /* Can Generaltypes header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANIF_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define CANIF_TYPES_AR_RELEASE_MINOR_VERSION     0
#define CANIF_TYPES_AR_RELEASE_REVISION_VERSION  3

/* Software Version Information */
#define CANIF_TYPES_SW_MAJOR_VERSION  2
#define CANIF_TYPES_SW_MINOR_VERSION  5
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
typedef struct STag_CanIf_ConfigType
{
  uint8 ucDummy;
}CanIf_ConfigType;

typedef enum
{
  CANIF_GET_OFFLINE = 0,
  CANIF_GET_OFFLINE_ACTIVE,
  CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE,
  CANIF_GET_ONLINE,
  CANIF_GET_RX_ONLINE,
  CANIF_GET_TX_ONLINE
}CanIf_PduGetModeType;

/* State transitions that are used by the function CanIf_SetControllerMode */
typedef enum
{
  CANIF_CS_UNINIT = 0,
  CANIF_CS_SLEEP,
  CANIF_CS_STARTED,
  CANIF_CS_STOPPED
} CanIf_ControllerModeType;

/* State transitions that are used by the function CanIf_SetChannelMode */
typedef enum
{
  CANIF_SET_OFFLINE = 0,
  CANIF_SET_ONLINE,
  CANIF_SET_RX_OFFLINE,
  CANIF_SET_RX_ONLINE,
  CANIF_SET_TX_OFFLINE,
  CANIF_SET_TX_OFFLINE_ACTIVE,
  CANIF_SET_TX_ONLINE
} CanIf_PduSetModeType;

/* Return value of the Notification Status API */
typedef enum
{
  CANIF_NO_NOTIFICATION = 0,
  CANIF_TX_RX_NOTIFICATION
} CanIf_NotifStatusType;

/* Return value of the WakeupSourceType. */
typedef enum
{
  CANIF_CONTROLLER_WAKEUP = 0,
  CANIF_TRANSCEIVER_WAKEUP
}CanIf_WakeupSourceType;

/* Return value of the CanIf_TrcvWakeupModeType. */
typedef enum
{
  CANIF_TRCV_WU_ENABLE = 0,
  CANIF_TRCV_WU_DISABLE,
  CANIF_TRCV_WU_CLEAR
}CanIf_TrcvWakeupModeType;

/* Battery voltage state transitions that are used by
 * the function CanIf_SetBatteryVoltageMode */
typedef enum
{
  CANIF_SET_BATVOL_NORMAL = 0,
  CANIF_SET_BATVOL_CRITICAL
}CanIf_BatVolSetModeType;
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* CANIF_TYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
