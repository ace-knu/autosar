/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: WdgM_PCTypes.h                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR WDGM                                                  **
**                                                                            **
**  PURPOSE   : Provision for Watchdog Manager pre-compile time parameters    **
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
** 1.0.14    13-Nov-2015   Sinil        1. MemClass changed                   **
** 1.0.13    29-Oct-2015   Sinil        1. Remove size of array for making    **
**                                      library                               **
** 1.0.12    23-Apr-2015   Sinil        1. Fix Misra-c rule violations        **
** 1.0.11    12-Nov-2014   Sinil        1. Fix for polyspace                  **
** 1.0.10    04-Nov-2014   Sinil        1. Add ddCounterID field in           **
**                                      WdgM_SupervisedEntityType             **
**                                      2. Change ddCounterID to pCounterID   **
** 1.0.9     21-Oct-2014   Sinil        1. Change WdgM_RteFuncPtrType argument**
**                                      data type                             **
**                                      2. Rename WdgM_TriggerModeType        **
**                                      3. Change including                   **
**                                      4. Remove version information         **
**                                      5. Rearrange items and change naming  **
** 1.0.8     07-Oct-2014   Sinil        1. Add WdgM_TriggerMode               **
** 1.0.7     30-Sep-2014   Sinil        1. Remove WDGM_ENABLE_OS_COUNTER      **
**                                      dependent variables                   **
** 1.0.6     28-Jan-2014   Sinil        TaskID:811                            **
**                                      1. Change usTotalSEInMode to          **
**                                      ddTotalSEInMode                       **
** 1.0.5     08-Jan-2014   Sinil        TaskID:809                            **
**                                      1. Variable type changed              **
**                                      2. Include header changed             **
** 1.0.4     23-Dec-2013   Sinil        Change dependency of logical          **
**                                        supervision                         **
** 1.0.3     18-Jun-2013   Sinil        CR 138 : Remove size of array for     **
**                                        making library                      **
** 1.0.2     05-Jun-2013   Sinil        CR 128 : Change from                  **
**                                        Rte_StatusType to Std_ReturnType    **
** 1.0.0     01-Jan-2013   Autron       Initial version                       **
*******************************************************************************/

#ifndef WDGM_PCTYPES_H
#define WDGM_PCTYPES_H
/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/*
  polyspace:begin<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation
*/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "WdgM_Cfg.h"
#include "Rte_WdgM_Type.h"
#include "WdgIf.h"
#include "Os.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define WDGM_ZERO                             ((uint8)0x00)
#define WDGM_ONE                              ((uint8)0x01)

#define WDGM_TRUE                             ((boolean)0x01)
#define WDGM_FALSE                            ((boolean)0x00)

/*  Macros to Update and Extract the SE Local Supervision status*/
#define WDGM_CLEAR_STATUS                     ((uint8)0x00)
#define WDGM_STATUS_MASK                      ((uint8)0x07)
#define WDGM_CLEAR_SE                         ((uint8)0xF8)

#define WDGM_ALIVESUPERVISION_CORRECT         ((uint8)0x10)
#define WDGM_DEADLINESUPERVISION_CORRECT      ((uint8)0x20)
#define WDGM_LGSUPERVISION_CORRECT            ((uint8)0x40)
#define WDGM_SET_ALLSUPVSN_CORRECT            ((uint8)0x70)

#define WDGM_ALIVESUPERVISION_INCORRECT       ((uint8)0xEF)
#define WDGM_DEADLINESUPERVISION_INCORRECT    ((uint8)0xDF)
#define WDGM_LGSUPERVISION_INCORRECT          ((uint8)0xBF)

/*  Macros to check Deadline Supervision Started or not */
#define WDGM_DS_STARTED                       ((uint8)0x01)
#define WDGM_DS_NOT_STARTED                   ((uint8)0x00)

/* Macros to extract SE parameters  */
#define WDGM_B0_AS                            ((uint8)0x01)
#define WDGM_B1_DS                            ((uint8)0x02)
#define WDGM_B2_ILS                           ((uint8)0x04)
#define WDGM_B3_ELS                           ((uint8)0x08)
#define WDGM_B4_PARTITION                     ((uint8)0x10)
#define WDGM_B5_APPLICATION                   ((uint8)0x20)

/*******************************************************************************
**                       Global Data Types                                    **
*******************************************************************************/
/* Type used for Rte Direct API */
typedef P2FUNC(Std_ReturnType, WDGM_CODE, WdgM_RteFuncPtrType)
  (Rte_ModeType_WdgM_Mode);

typedef enum ETag_WdgM_CpType
{
  WDGM_CP_INITIAL = 0x00,
  WDGM_CP_FINAL,
  WDGM_CP_BI
} WdgM_CpType;

typedef enum ETag_WdgM_TriggerModeType
{
  WDGM_TM_NORMAL = 0x00,
  WDGM_TM_TIMEOUT,
  WDGM_TM_DEINIT
} WdgM_TriggerModeType;

#if(WDGM_ENABLE_ALIVE_SUPERVISION == STD_ON)
typedef struct STag_WdgM_AliveSupervisionType
{
  /* Supervised entity to be supervised */
  WdgM_SupervisedEntityIdType ddSEId;
  /* Index to the SE array WdgM_GaaSupervisedEntity */
  WdgM_SupervisedEntityIndexType ddSEArrayIndex;
  /* Checkpoint to be supervised */
  WdgM_CheckpointIdType ddCheckpoint;
  /* Expected alive indications of the Checkpoint */
  WdgM_ExAliveIndicationsCountType ddExAliveIndications;
  /* Reference supervision cycles to perform the checkup with counted
    alive indications */
  WdgM_AliveSupRefCycleCountType ddSupervisionRefCycle;
  /* Allowed additional to the expected alive indications */
  uint8 ucExAliveIndMaxMargin;
  /* Allowed missing expected alive indications */
  uint8 ucExAliveIndMinMargin;
} WdgM_AliveSupervisionType;
#endif

#if(WDGM_ENABLE_DEADLINE_SUPERVISION == STD_ON)
typedef struct STag_WdgM_DeadlineSupervisionStatusType
{
  /* Tick value updated by OS */
  TickType ddValue;
  /* Status of the corresponding deadline monitoring i.e. WDGM_DS_STARTED,
    WDGM_DS_NOT_STARTED */
  uint8 ucStatus;
} WdgM_DeadlineSupervisionStatusType;

typedef struct STag_WdgM_DeadlineSupervisionType
{
  /* Supervised entity to be supervised */
  WdgM_SupervisedEntityIdType ddSEId;
  /* Final Checkpoint to be supervised */
  WdgM_CheckpointIdType ddInitialCheckpoint;
  /* Final Checkpoint to be supervised */
  WdgM_CheckpointIdType ddFinalCheckpoint;
  /* Allowed additional time span for deadline */
  uint32 ulDeadlineMax;
  /* Allowed missing time span for deadline */
  uint32 ulDeadlineMin;
} WdgM_DeadlineSupervisionType;
#endif

#if(WDGM_ENABLE_INTERNAL_TRANSITION == STD_ON)
typedef struct STag_WdgM_IntLogicalSupervisionStatusType
{
  /* Store the last reported CP details for internal transition */
  WdgM_CheckpointIdType ddLastReportedCP;
  /* Store the activity status of the corresponding internal transition */
  boolean blActivityFlag;
} WdgM_IntLogicalSupervisionStatusType;
#endif

#if(WDGM_ENABLE_EXTERNAL_TRANSITION == STD_ON)
typedef struct STag_WdgM_ExtLogicalSupervisionStatusType
{
  /* Store the last reported SE/CP details for external transition */
  WdgM_ExLSGraphArrayType ddLastRepExLSGraphArrIdx;
  /* Store the activity status of the corresponding external transition */
  boolean blActivityFlag;
} WdgM_ExtLogicalSupervisionStatusType;

typedef struct STag_WdgM_ExLSGraphType
{
  /* Supervised entity to be supervised */
  WdgM_SupervisedEntityIdType ddSEId;
  /* Final Checkpoint to be supervised */
  WdgM_CheckpointIdType ddCheckpoint;
  /* Index of Checkpoint Mapping Array
    WdgM_GaaExLS<MODE_ID><GRAPH_ID>MapArray */
  WdgM_CpMapArrayIndexType ddCpMapArrayIndex;
  /* Maximum available transition paths for a corresponding check point */
  uint8 ucMaxBranches;
  /* Check point type. Either WDGM_CP_INITIAL, WDGM_CP_FINAL or WDGM_CP_BI */
  WdgM_CpType enCpType;
} WdgM_ExLSGraphType;

typedef struct STag_WdgM_ExLSGraphMapArrayType
{
  /* Supervised entity to be supervised */
  WdgM_SupervisedEntityIdType ddSEId;
  /* Final Checkpoint to be supervised */
  WdgM_CheckpointIdType ddCheckpoint;
} WdgM_ExLSGraphMapArrayType;

typedef struct STag_WdgM_ExLogicalSupervisionType
{
  /* Pointer to corresponding WdgM_GaaExLSGraph<MODE_ID><GRAPH_ID> */
  P2CONST(WdgM_ExLSGraphType, AUTOMATIC, WDGM_CONST) pExLSGraph;
  /* Pointer to corresponding WdgM_GaaExLSGraph<MODE_ID><GRAPH_ID>MapArray */
  P2CONST(WdgM_ExLSGraphMapArrayType, AUTOMATIC, WDGM_CONST)
    pExLSGraphMapArray;
  /* Total number of checkpoints configured in the external graph */
  WdgM_CheckpointIdType ddTotalCheckpoints;
} WdgM_ExLogicalSupervisionType;
#endif

typedef struct STag_WdgM_LocalStatusParamType
{
  /* Supervised entity to be supervised */
  WdgM_SupervisedEntityIdType ddSEId;
  /* Index to the SE array WdgM_GaaSupervisedEntity */
  WdgM_SupervisedEntityIndexType ddSEArrayIndex;
  /* Failed Alive supervision tolerance */
  uint8 ucFailedTolerance;
} WdgM_ActiveSEType;

#if(WDGM_ENABLE_TRIGGER == STD_ON)
typedef struct STag_WdgM_TriggerType
{
  /* WdgIf mode for the corresponding WdgM mode */
  WdgIf_ModeType ddWdgIfMode;
  /* Wdg Trigger Timeout */
  uint16 usWdgIfTimeout;
  /* WdgIf Device Id */
  uint8 ucWdgIfDeviceId;
} WdgM_TriggerType;
#endif

typedef struct STag_WdgM_CheckpointGraphType
{
  #if(WDGM_ENABLE_INTERNAL_TRANSITION == STD_ON)
  /* Index of Checkpoint Mapping Array WdgM_GaaSE<SEID>CpIntLSGraphMap */
  WdgM_CpMapArrayIndexType ddCpMapArrayIndex;
  /* Maximum available transition paths for a corresponding check point */
  uint8 ucMaxBranches;
  #endif
  /* Check point type. Either WDGM_CP_INITIAL, WDGM_CP_FINAL or WDGM_CP_BI */
  WdgM_CpType enCpType;
} WdgM_CheckpointGraphType;

typedef struct STag_WdgM_SupervisedEntityType
{
  /* Pointer to corresponding WdgM_GaaSE<SEID>Checkpoints */
  P2CONST(WdgM_CheckpointGraphType, AUTOMATIC, WDGM_CONST) pCheckpoint;
  /* Pointer to corresponding WdgM_GaaIntLSGraphSE<SEID>MapArray */
  #if(WDGM_ENABLE_INTERNAL_TRANSITION == STD_ON)
  P2CONST(WdgM_CheckpointIdType, AUTOMATIC, WDGM_CONST)
    pIntLSGraphMapArray;
  #endif
  /* Pointer to Rte function pointer switch */
  WdgM_RteFuncPtrType pRteSwitchMode;
  /* Total configured check points for a supervised entity */
  WdgM_CheckpointIdType ddTotalCheckpoints;
  /* Supervised Entity Id */
  WdgM_SupervisedEntityIdType ddSEId;
  #if(WDGM_ENABLE_DEADLINE_SUPERVISION == STD_ON)
  /* OsCounter ID */
  const CounterType* pCounterID;
  #endif
  #if(WDGM_ENABLE_OS_APPLICATION == STD_ON)
  /* OS Application ID */
  ApplicationType ddApplication;
  #endif
  #if(WDGM_ENABLE_INTERNAL_TRANSITION == STD_ON)
  /* Index to Internal Logical Supervision Status Array */
  WdgM_IntLogicSupStatArrIndexType ddILSIndex;
  #endif
  #if(WDGM_ENABLE_ECUC_PARTITION == STD_ON)
  /* ECUC Partition ID */
  uint8 ucEcucpartitionId;
  #endif
  /* Supervision algorithms applicable for SE */
  uint8 ucSupervisions;
} WdgM_SupervisedEntityType;

typedef struct STag_WdgM_ModePropertyType
{
  #if(WDGM_ENABLE_ALIVE_SUPERVISION == STD_ON)
  /* Pointer to corresponding WdgM_GaaMode<MODE_ID>AliveSupervisions[] */
  P2CONST(WdgM_AliveSupervisionType, AUTOMATIC, WDGM_CONST)
    pAliveSupervisions;
  #endif
  #if(WDGM_ENABLE_DEADLINE_SUPERVISION == STD_ON)
  /* Pointer to corresponding  WdgM_GaaMode<MODE_ID>DeadlineSupervision */
  P2CONST(WdgM_DeadlineSupervisionType, AUTOMATIC, WDGM_CONST)
    pDeadlineSupervisions;
  #endif
  #if(WDGM_ENABLE_EXTERNAL_TRANSITION == STD_ON)
  /* Pointer to corresponding  WdgM_GaaMode<MODE_ID>ExLogicalSupervisions */
  P2CONST(WdgM_ExLogicalSupervisionType, AUTOMATIC, WDGM_CONST)
    pExLogicalSupervisions;
  #endif
  /* Pointer to corresponding  WdgM_GaaMode<MODE_ID>ActiveSE */
  P2CONST(WdgM_ActiveSEType, AUTOMATIC, WDGM_CONST) pActiveSEList;
  #if(WDGM_ENABLE_TRIGGER == STD_ON)
  /* Pointer to corresponding  WdgM_GaaMode<MODE_ID>Triggers */
  P2CONST(WdgM_TriggerType, AUTOMATIC, WDGM_CONST) pTriggers;
  #endif
  /* Duration in which the blocking of watchdog triggering shall be postponed */
  uint16 usWdgTrigBlockCount;
  /* MainFunction period */
  uint16 usSupervisionCycle;
  #if(WDGM_ENABLE_ALIVE_SUPERVISION == STD_ON)
  /* Total Configured Alive Supervisions */
  uint16 usTotalAliveSupervisions;
  #endif
  #if(WDGM_ENABLE_DEADLINE_SUPERVISION == STD_ON)
  /* Total Configured Deadline Supervisions */
  uint16 usTotalDeadlineSupervisions;
  #endif
  #if(WDGM_ENABLE_EXTERNAL_TRANSITION == STD_ON)
  /* Total Configured External Logical Supervisions */
  uint16 usTotalExLogicalSupervisions;
  #endif
  /* Total number of active SE's in the current mode */
  WdgM_SupervisedEntityIndexType ddTotalSEInMode;
  #if(WDGM_ENABLE_TRIGGER == STD_ON)
  /* Total Configured Triggers */
  uint8 ucTotalTriggers;
  #endif
} WdgM_ModePropertyType;

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include"MemMap.h"
extern CONST(WdgM_ModePropertyType, WDGM_CONST) WdgM_GaaModes[];
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_UNSPECIFIED
#include"MemMap.h"
extern CONST(WdgM_SupervisedEntityType, WDGM_CONST)
  WdgM_GaaSupervisedEntity[];
#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define WDGM_START_SEC_CONST_16
#include"MemMap.h"
/* Global array to store the list of WdgM_SetMode API caller Id's */
extern CONST(uint16, WDGM_CONST) 
  WdgM_GaaSetModeCallerId[];
#define WDGM_STOP_SEC_CONST_16
#include "MemMap.h"

#if(WDGM_ENABLE_ALIVE_SUPERVISION == STD_ON)
#define WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global variable to store Alive Indication status */
extern VAR(WdgM_ExAliveIndicationsCountType, WDGM_VAR_POWER_ON_INIT)
  WdgM_GaaAliveIndicationStatus[];
#define WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#if(WDGM_ENABLE_DEADLINE_SUPERVISION == STD_ON)
#define WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global variable to store Deadline Monitoring status */
extern VAR(WdgM_DeadlineSupervisionStatusType, WDGM_VAR_POWER_ON_INIT)
  WdgM_GaaDeadlineSupervisionStatus[];
#define WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#if(WDGM_ENABLE_INTERNAL_TRANSITION == STD_ON)
#define WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global variable to store Internal Logical Supervision status */
extern VAR(WdgM_IntLogicalSupervisionStatusType, WDGM_VAR_POWER_ON_INIT)
  WdgM_GaaIntLogicalSupervisionStatus[];
#define WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

#if(WDGM_ENABLE_EXTERNAL_TRANSITION == STD_ON)
#define WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* Global variable to store External Logical Supervision status */
extern VAR(WdgM_ExtLogicalSupervisionStatusType, WDGM_VAR_POWER_ON_INIT)
  WdgM_GaaExtLogicalSupervisionStatus[];
#define WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/*
  polyspace:end<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation
*/

#endif /* WDGM_PCTYPES_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
