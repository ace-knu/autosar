/*******************************************************************************
**  (C) 2013 Hyundai AUTRON Company                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanTp_Ram.h                                                   **
**                                                                            **
**  TARGET    : ALL                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CANTP MODULE                                          **
**                                                                            **
**  PURPOSE   : Header file for CanTp_Ram.c                                   **
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
** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
*******************************************************************************/
#ifndef CANTP_RAM_H
#define CANTP_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanTp_Cfg.h"            /* Configuration header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CANTP_RAM_AR_RELEASE_MAJOR_VERSION    4
#define CANTP_RAM_AR_RELEASE_MINOR_VERSION    0
#define CANTP_RAM_AR_RELEASE_REVISION_VERSION 3

/* CANTP software version information */
#define CANTP_RAM_SW_MAJOR_VERSION            1
#define CANTP_RAM_SW_MINOR_VERSION            0
#define CANTP_RAM_SW_PATCH_VERSION            2

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define CANTP_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/* Global variable to store CanTp Initialization status */
extern VAR(boolean, CANTP_VAR) CanTp_GblInitStatus;
#define CANTP_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#endif /* CANTP_RAM_H */

/*******************************************************************************
**                          END OF FILE                                       **
*******************************************************************************/

