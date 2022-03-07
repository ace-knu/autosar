/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : EcuM_Types.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR EcuM Module                                           **
**                                                                            **
**  PURPOSE   : Type definitions of ECU State Manager                         **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                              Revision History                              **
********************************************************************************
** Revision   Date          By            Description                         **
********************************************************************************
** 2.5.5      14-Jul-2016   Sanghoon Bae  Redmine #5257                       **
** 2.5.1      12-Oct-2015   Sanghoon Bae  Redmine #3035                       **
** 2.4.2      10-Jun-2015   Jihoon Jung   Redmine #2702                       **
**                                        -Add ECUM_E_START_CORE_FAILED       **
** 2.4.1      27-May-2015   Jihoon Jung   Redmine #2550                       **
** 2.3.2      29-Mar-2015   Daejun Park   Redmine #2388                       **
**                                        -Add EcuM_WakeupType type           **
** 2.2.1      26-Dec-2014   Daejun Park   Redmine #1879                       **
**                                        -Update to AUTRON template          **
** 2.0.4      12-Jun-2014   Daejun Park   Move reset mode to configuration    **
** 1.2.2      22-Apr-2014   Daejun Park   Add macro for return value          **
** 1.1.0      07-Mar-2014   Daejun Park   Move macro definition               **
**                                        from EcuM_PCTypes.h                 **
** 1.0.11     04-Jul-2013   Daejun Park   CR~129, XAR~581 : EcuM library      **
** 1.0.0      04-Mar-2013   Daejun Park   Initial version                     **
*******************************************************************************/\

/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */

#ifndef ECUM_TYPES_H
#define ECUM_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "Rte_EcuM_Type.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define ECUM_WKSOURCE_ALL_SOURCES  ((EcuM_WakeupSourceType) 0xFFFFFFFFU)

/* Possible states of a wakeup source */
typedef enum 
{ 
  ECUM_WKSTATUS_NONE      = 0,
  ECUM_WKSTATUS_PENDING   = 1,
  ECUM_WKSTATUS_VALIDATED = 2,
  ECUM_WKSTATUS_EXPIRED   = 3,
  ECUM_WKSTATUS_DISABLED  = 4,
  ECUM_WKSTATUS_ENABLED   = 5
} EcuM_WakeupStatusType;

typedef enum 
{ 
  ECUM_WK_NONE            = 0,
  ECUM_WK_UNKNOWN         = 1,
  ECUM_WK_KNOWN           = 2,
  ECUM_WK_KNOWN_ALARM     = 3
} EcuM_WakeupType;

/* For DET Error */
#define ECUM_E_UNINIT                          0x10
#define ECUM_E_SERVICE_DISABLED                0x11
#define ECUM_E_NULL_POINTER                    0x12
#define ECUM_E_INVALID_PAR                     0x13
#define ECUM_E_STATE_PAR_OUT_OF_RANGE          0x16
#define ECUM_E_UNKNOWN_WAKEUP_SOURCE           0x17
#define ECUM_E_START_CORE_FAILED               0x18
#define ECUM_E_SHUTDOWN_FAILED                 0x19
#define ECUM_E_UNKNOWN_SLEEP_MODE              0x20
#define ECUM_E_INVALID_API_CALL                0x21
#define ECUM_E_INVALID_SHUTDOWNTARGET          0x22

#define ECUM_E_EARLIER_ACTIVE                  0x10
#define ECUM_E_PAST                            0x11
#define ECUM_E_NOT_ACTIVE                      0x12
#define ECUM_E_NOT_ALLOWED                     0x13

/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
#endif /* ECUM_TYPES_H */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

