/*******************************************************************************
**  (C) 2013 Hyundai AUTRON Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanTp_Config.c                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN Transport Protocol                                **
**                                                                            **
**  PURPOSE   : CanTp Library Relase.                                         **
**                                                                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 1.7.10    24-Apr-2015   Lim Jong Sun   #8152                               **
** 1.7.5     02-Feb-2015   Lim Jong Sun   #3965                               **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Platform_Types.h"
#include "CanTp_Cfg.h"

/*******************************************************************************
**            Variable for Library                  **
*******************************************************************************/
  
#define CANTP_START_SEC_CONST_8
#include "MemMap.h"
CONST(uint8, CANTP_CONST) Cantp_Main_Function_Period = CANTP_MAIN_FUNCTION_PERIOD;
CONST(uint8, CANTP_CONST) Cantp_Channel_Id = CANTP_CHANNEL_ID;
CONST(uint8, CANTP_CONST) Cantp_Total_Rx_Tx_Channels = CANTP_TOTAL_RX_TX_CHANNELS;
CONST(uint8, CANTP_CONST) CanTp_No_Of_Channels = CANTP_NO_OF_CHANNELS;
#if ((STD_ON == CANTP_TX_SDU_PADDING_ACTIVATION) ||\
  (STD_ON == CANTP_RX_SDU_PADDING_ACTIVATION))
CONST(uint8, CANTP_CONST) Cantp_Padding_Byte = CANTP_PADDING_BYTE;
#endif
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define CANTP_START_SEC_CONST_16
#include "MemMap.h"
CONST(uint16, CANTP_CONST) Cantp_Maxno_Rx_Npdu = CANTP_MAXNO_RX_NPDU;
CONST(uint16, CANTP_CONST) Cantp_Maxno_Rx_Sdu = CANTP_MAXNO_RX_SDU;
CONST(uint16, CANTP_CONST) Cantp_Max_Confirm_Id = CANTP_MAX_CONFIRM_ID;
CONST(uint16, CANTP_CONST) Cantp_Max_Indic_Id = CANTP_MAX_INDIC_ID;
#ifndef CANTP_MAX_TX_SDUID
#define CANTP_MAX_TX_SDUID 0
#endif
CONST(uint16, CANTP_CONST) Cantp_Max_Tx_Sduid = CANTP_MAX_TX_SDUID;
#ifndef CANTP_MAX_RX_SDUID
#define CANTP_MAX_RX_SDUID 0
#endif
CONST(uint16, CANTP_CONST) Cantp_Max_Rx_Sduid = CANTP_MAX_RX_SDUID;
#ifndef CANTP_RX_FCPDU_START
#define CANTP_RX_FCPDU_START 0
#endif
CONST(uint16, CANTP_CONST) Cantp_Rx_Fcpdu_start = CANTP_RX_FCPDU_START;
#ifndef CANTP_MAX_RX_FCNPDUID
#define CANTP_MAX_RX_FCNPDUID 0
#endif
CONST(uint16, CANTP_CONST) Cantp_Max_Rx_Fcnpduid = CANTP_MAX_RX_FCNPDUID;
#define CANTP_STOP_SEC_CONST_16
#include "MemMap.h"