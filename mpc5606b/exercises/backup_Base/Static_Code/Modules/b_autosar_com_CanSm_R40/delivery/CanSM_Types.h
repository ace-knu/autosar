/*******************************************************************************
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.								          **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanSM_Types.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN State Manager Module                              **
**                                                                            **
**  PURPOSE   : Type definition of Autosar CAN State Manager                  **
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
** 1.10.0    27-Oct-2016   Lim Jong Sun   #7076                               **
** 1.9.5     23-Sep-2015   Lim Jong Sun   Feature#3210 Add BswM_RequestMode   **
**                                        to Notify Bus Off Start & Complete  **
** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
*******************************************************************************/
#ifndef CANSM_TYPES_H
#define CANSM_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanSM_Cfg.h"            /* Inclusion for CanSM header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANSM_TYPES_H_AR_RELEASE_MAJOR_VERSION         4
#define CANSM_TYPES_H_AR_RELEASE_MINOR_VERSION         0
#define CANSM_TYPES_H_AR_RELEASE_REVISION_VERSION      3

/* Software Version Information */
#define CANSM_TYPES_H_SW_MAJOR_VERSION                 1
#define CANSM_TYPES_H_SW_MINOR_VERSION                 10

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Structure for the CANSM configuration type */
typedef struct STagCanSM_ConfigType
{
  uint8 ucDummy;
} CanSM_ConfigType;

/* CanSM module specific types */
typedef enum
{
  CANSM_BSWM_NO_COMMUNICATION,
  CANSM_BSWM_SILENT_COMMUNICATION,
  CANSM_BSWM_FULL_COMMUNICATION,
  CANSM_BSWM_BUS_OFF,
  CANSM_BSWM_CHANGE_BAUDRATE
} CanSM_BswMCurrentStateType;

/* CanSM Bus Off mode */
typedef enum
{
  CANSM_BSWM_BOR_START,
  CANSM_BSWM_BOR_COMPLETE
} CanSM_BswM_BORState;

/*******************************************************************************
**                      MACRO Definitions                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* CANSM_TYPES_H */

/*******************************************************************************
**                   End of File                                              **
*******************************************************************************/

