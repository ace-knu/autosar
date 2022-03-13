/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: ComM_Types.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR COM Manager                                           **
**                                                                            **
**  PURPOSE   : Type definition of Communication Manager                      **
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
** 1.0.8   15-May-2015   Kyungtae Kim     Cleared errors against MISRA rule   **
** 1.0.7   31-Oct-2013   Daejun Park      CR~184, XAR~720 : ComM Type         **
** 1.0.6   04-Jul-2013   Daejun Park      CR~129, XAR~581 : ComM library      **
** 1.0.0   17-Dec-2012   Daejun Park            Initial version               **
*******************************************************************************/
#ifndef COMM_TYPES_H
#define COMM_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComM_Cfg.h"
#include "Rte_Type.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* ComM initialization values type definition */
#define COMM_UNINIT ((ComM_InitStatusType) 0)
#define COMM_INIT   ((ComM_InitStatusType) 1)

/* ComM States with sub states */
#define COMM_NO_COM_NO_PENDING_REQUEST  ((ComM_StateType) 0)
#define COMM_NO_COM_REQUEST_PENDING     ((ComM_StateType) 1)
#define COMM_FULL_COM_NETWORK_REQUESTED ((ComM_StateType) 2)
#define COMM_FULL_COM_READY_SLEEP       ((ComM_StateType) 3)
#define COMM_SILENT_COM                 ((ComM_StateType) 4)

/* ComM Main States */
#define COMM_NO_COMMUNICATION       (RTE_MODE_ComMMode_COMM_NO_COMMUNICATION)
#define COMM_SILENT_COMMUNICATION   (RTE_MODE_ComMMode_COMM_SILENT_COMMUNICATION)
#define COMM_FULL_COMMUNICATION     (RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION)

#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED == STD_ON))
#if ((COMM_CANNETWORK_PRESENT == STD_ON) || (COMM_FRNETWORK_PRESENT == STD_ON))

/* ComM PNC Current */
#define PNC_REQUESTED          ((ComM_PncModeType) 0) /* PNC is requested by a local ComM user */
#define PNC_READY_SLEEP        ((ComM_PncModeType) 1) /* PNC is requested by a remote ComM user */
#define PNC_PREPARE_SLEEP      ((ComM_PncModeType) 2) /* PNC is active with no deadline monitoring */
#define PNC_NO_COMMUNICATION   ((ComM_PncModeType) 3) /* PNC does not communicate */
#define PNC_FULL_COMMUNICATION ((ComM_PncModeType) 4) /* PNC is able to communicate */

#endif /* End of if ((COMM_CANNETWORK_PRESENT == STD_ON) ||
        *(COMM_FRNETWORK_PRESENT == STD_ON)) */
#endif /* End of if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNC_ENABLED ==
        *STD_ON)) */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* COMM_TYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

