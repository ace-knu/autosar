/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: WdgM.h                                                        **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR WDGM                                                  **
**                                                                            **
**  PURPOSE   : Header file to publish Watchdog Manager function prototypes   **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By           Description                           **
********************************************************************************
** 1.0.10    20-Aug-2015   Sinil        1. Follow function prototype argument **
**                                      naming rule                           **
**                                      2. Add WdgM Type header file include  **
** 1.0.9     27-May-2015   Sinil        1. Fix Misra-c rule violations        **
** 1.0.8     23-Apr-2015   Sinil        1. Fix Misra-c rule violations        **
** 1.0.7     27-Jan-2015   Sinil        1. Add a macro for unused pointer     **
** 1.0.6     12-Nov-2014   Sinil        1. Fix for polyspace                  **
** 1.0.5     21-Oct-2014   Sinil        1. Make data structure                **
**                                      WdgM_ChangeModeIntReqType             **
**                                      2. Remove unused items                **
**                                      3. Rearrange items and change naming  **
** 1.0.4     15-Jul-2014   Sinil        1. Remove WdgM_PmTrigger              **
** 1.0.3     30-May-2014   Sinil        1. WdgM_PmModeChange and              **
**                                      WdgM_PmTrigger added                  **
** 1.0.2     28-May-2013   Sinil        WdgM_LocalStatusType,                 **
                                          WdgM_GlobalStatusType are moved to  **
                                          RTE generation                      **
** 1.0.0     01-Jan-2013   Autron       Initial version                       **
*******************************************************************************/

#ifndef WDGM_H
#define WDGM_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"                /* Standars types Header file */
#include "Rte_WdgM_Type.h"            /* Rte generated types Header file */
#include "WdgM_Cfg.h"                 /* Cfg Header file */
#include "WdgM_PCTypes.h"             /* WdgM Types Header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* Instance identification */
#define WDGM_INSTANCE_ID                          ((uint8)0x00)

#define WDGM_UNINITIALIZED                        ((boolean)0x00)
#define WDGM_INITIALIZED                          ((boolean)0x01)

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/
/* DET error is reported if an API is invoked without module initialization */
#define WDGM_E_NO_INIT                            ((uint8)0x10)
/* DET error is reported if an API is invoked with wrong "mode" parameter */
#define WDGM_E_PARAM_MODE                         ((uint8)0x12)
/* DET error is reported if an API is invoked with wrong "SEID" parameter */
#define WDGM_E_PARAM_SEID                         ((uint8)0x13)
/* DET error is reported if an API is invoked with a null pointer parameter */
#define WDGM_E_INV_POINTER                        ((uint8)0x14)
/* DET error is reported if Disabling of watchdog not allowed  */
#define WDGM_E_DISABLE_NOT_ALLOWED                ((uint8)0x15)
/* DET error is reported if an API is invoked with an invalid CheckpointId */
#define WDGM_E_CPID                               ((uint8)0x16)
/* DET error is reported if WdgM_UpdateAliveCounter is invoked */
#define WDGM_E_DEPRECATED                         ((uint8)0x17)
/*
   DET error is reported if WdgM_UpdateAliveIndication cannot determine the
   Checkpoint, because there are more than one alive supervisions configured
   in the current mode for the given Supervised Entity
 */
#define WDGM_E_AMBIGIOUS                          ((uint8)0x18)
/*
   DET error is reported if WdgM_CheckpointReached is invoked with a checkpoint
   of a Supervised Entity that is deactivated in the current Watchdog Manager
   mode
 */
#define WDGM_E_SEDEACTIVATED                      ((uint8)0x19)

/*******************************************************************************
**                      Service IDs                                           **
*******************************************************************************/
/* Service Id of WdgM_Init */
#define WDGM_INIT_SID                             ((uint8)0x00)
/* Service Id of WdgM_DeInit */
#define WDGM_DEINIT_SID                           ((uint8)0x01)
/* Service Id of WdgM_GetVersionInfo */
#define WDGM_GETVERSIONINFO_SID                   ((uint8)0x02)
/* Service Id of WdgM_SetMode */
#define WDGM_SETMODE_SID                          ((uint8)0x03)
/* Service Id of WdgM_GetMode */
#define WDGM_GETMODE_SID                          ((uint8)0x0b)
/* Service Id of WdgM_CheckpointReached */
#define WDGM_CHECKPOINTREACHED_SID                ((uint8)0x0e)
/* Service Id of WdgM_UpdateAliveCounter */
#define WDGM_UPDATEALIVECOUNTER_SID               ((uint8)0x04)
/* Service Id of WdgM_GetAliveSupevisionStatus */
#define WDGM_GETLOCALSTATUS_SID                   ((uint8)0x0c)
/* Service Id of WdgM_GetGlobalStatus */
#define WDGM_GETGLOBALSTATUS_SID                  ((uint8)0x0d)
/* Service Id of WdgM_GetGlobalStatus */
#define WDGM_PERFORMRESET_SID                     ((uint8)0x0f)
/* Service Id of WdgM_GetFirstExpiredSEID */
#define WDGM_GETFIRSTEXPIRED_SEID_SID             ((uint8)0x10)
/* Service Id of WdgM_Mainfunction */
#define WDGM_MAINFUNCTION_SID                     ((uint8)0x08)
/* Service Id of WdgM_GetErrorInfo */
#define WDGM_GETERRORINFO_SID                     ((uint8)0xa0)
/* Service Id of WdgM_ChangeModeInt */
#define WDGM_CHANGEMODEINT_SID                    ((uint8)0xa1)

/*******************************************************************************
**                                  Macros                                    **
*******************************************************************************/
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> 
   use function like-macro for removing unused argument compiler warning */
#define WDGM_UNUSED(x)                            do { \
                                                    if((uint32)(x) != (uint32)WDGM_ZERO) {} \
                                                  } while(0)
  
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> 
   use function like-macro for removing unused argument compiler warning */
#define WDGM_UNUSED_PTR(x)                        do { \
                                                    if((x) != NULL_PTR) {} \
                                                  } while(0)

/*******************************************************************************
**                         Global Data Types                                  **
*******************************************************************************/
/* This structure contains all post-build configurable parameters */
typedef struct STag_WdgM_ConfigType
{
  /* Dummy element */
  boolean blDummy;
} WdgM_ConfigType;

typedef enum ETag_WdgM_ChangeModeIntReqType
{
  WDGM_CMR_WDG_OFF = 0x00,
  WDGM_CMR_WDG_RESTART,
  WDGM_PM_MODE_LP_REQ,    /* Will be removed */
  WDGM_PM_MODE_HP_REQ     /* Will be removed */
} WdgM_ChangeModeIntReqType;

/*******************************************************************************
**                       Function Prototypes                                  **
*******************************************************************************/
#define WDGM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, WDGM_CODE) WdgM_Init
  (P2CONST(WdgM_ConfigType, AUTOMATIC, WDGM_APPL_CONST) pConfigPtr);
#define WDGM_STOP_SEC_CODE
#include "MemMap.h"

#define WDGM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, WDGM_CODE) WdgM_DeInit(void);
#define WDGM_STOP_SEC_CODE
#include "MemMap.h"

#if(WDGM_VERSION_INFO_API == STD_ON)
#define WDGM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, WDGM_CODE) WdgM_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, WDGM_APPL_DATA) pVersionInfo);
#define WDGM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if(WDGM_ERROR_INFO_API == STD_ON)
#define WDGM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetErrorInfo(
  WdgM_SupervisedEntityIdType ddSEID,
  P2VAR(WdgM_ErrorInfoType, WDGM_DATA, WDGM_APPL_DATA) pErrorInfo);
#define WDGM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#define WDGM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, WDGM_CODE) WdgM_PmModeChange(
  WdgM_ChangeModeIntReqType ddReqMode);
#define WDGM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* WDGM_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
