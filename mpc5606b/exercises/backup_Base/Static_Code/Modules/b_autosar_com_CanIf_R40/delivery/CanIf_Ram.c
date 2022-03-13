/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf_Ram.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : Provision of Global RAM Variables                             **
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
** 2.5.0    06-Dec-2016    Js.Lim      #7077                                  **
** 2.1.2    05-Jan-2016    Kt.Kim      #3813                                  **
** 2.1.0    29-May-2013    Kt.Kim      OsekNm Support                         **
** 1.0.0    04-Feb-2013    Kt.Kim      Initial version                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf_Ram.h"              /* CanIf RAM header */
#include "CanIf_IntTypes.h"         /* CanIf Internal types header */
#include "CanIf_PCTypes.h"          /* Pre-compile time header file */
#if (STD_ON == CANIF_DEV_ERROR_DETECT)
#include "CanIf_Error.h"            /* CanIf Det file */
#endif
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CANIF_RAM_C_AR_RELEASE_MAJOR_VERSION    4
#define CANIF_RAM_C_AR_RELEASE_MINOR_VERSION    0
#define CANIF_RAM_C_AR_RELEASE_REVISION_VERSION 3

/* File version information */
#define CANIF_RAM_C_SW_MAJOR_VERSION    2
#define CANIF_RAM_C_SW_MINOR_VERSION    5
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (CANIF_RAM_AR_RELEASE_MAJOR_VERSION != \
  CANIF_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "CANIF_RAM.c : Mismatch in Specification Major Version"
#endif
#if (CANIF_RAM_AR_RELEASE_MINOR_VERSION != \
  CANIF_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "CANIF_RAM.c : Mismatch in Specification Minor Version"
#endif
#if (CANIF_RAM_AR_RELEASE_REVISION_VERSION != \
  CANIF_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "CANIF_RAM.c : Mismatch in Specification Revision Version"
#endif
#if (CANIF_RAM_SW_MAJOR_VERSION != CANIF_RAM_C_SW_MAJOR_VERSION)
  #error "CANIF_RAM.c : Mismatch in Software Major Version"
#endif
#if (CANIF_RAM_SW_MINOR_VERSION != CANIF_RAM_C_SW_MINOR_VERSION)
  #error "CANIF_RAM.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#if (STD_ON == CANIF_DEV_ERROR_DETECT)
#define CANIF_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
/* Global variable to store Initialization status of CAN Interface */
VAR (boolean, CANIF_VAR) CanIf_GblCanIfStatus;
#define CANIF_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_CANTRCV_SUPPORT)
#define CANIF_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
/* Global array for Operation Mode */
VAR (uint8, CANIF_VAR) CanIf_GaaTrcvMode [CANIF_NO_OF_TRANSCEIVER];
#define CANIF_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_DEV_ERROR_DETECT)
#if (STD_ON == CANIF_CANTRCV_SUPPORT)
#define CANIF_START_SEC_VAR_NO_INIT_8
#include "MemMap.h"
/* Global array for Operation Mode */
VAR (uint8, CANIF_VAR) CanIf_GaaOperMode [CANIF_NO_OF_TRANSCEIVER];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h"
#endif

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "MemMap.h"
/* Global array for HrhId */
VAR (uint8, CANIF_VAR) CanIf_GaaHrhArrayId [CANIF_NO_OF_CANDRIVER];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
#define CANIF_START_SEC_VAR_NO_INIT_8
#include "MemMap.h"
/* Global array for HrhOffset */
VAR (uint8, CANIF_VAR) CanIf_GaaHrhOffSetId [CANIF_NO_OF_CANDRIVER];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h"
#endif

#define CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global array for Controller */
VAR (CanIf_Controller, CANIF_VAR) CanIf_GaaController [CANIF_NO_OF_CONTROLLER];

/* Global variable for saving CAN identifier of received message */
VAR(Can_IdType, CANIF_NOINIT_DATA) CanIf_GddRxCanId;

#if (STD_ON == CANIF_TX_LPDU)
/* Global variable for Tx Pdu status for gateway buffer */
VAR(uint8, CANIF_NOINIT_DATA) CanIf_GaaTxPduGwStatus[CANIF_NO_OF_TXLPDU];
#endif
#define CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
