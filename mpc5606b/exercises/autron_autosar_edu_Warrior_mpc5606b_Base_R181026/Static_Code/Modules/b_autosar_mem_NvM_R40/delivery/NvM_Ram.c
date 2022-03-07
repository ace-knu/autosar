/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: NvM_Ram.c                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR NvM Module                                            **
**                                                                            **
**  PURPOSE   : Global variable declarations.                                 **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision    Date           By          Description                         **
********************************************************************************
** 1.3.4       13-Jun-2017   YJ Yun      Correct MISRA Rule, Redmine #8268    **
** 1.3.3       16-Nov-2016   Song CY     Redmine #6680                        **
** 1.3.2       10-Oct-2016   Song CY     Redmine #6215                        **
** 1.3.0       25-Jul-2016   Song CY     Redmine #5383                        **
** 1.2.2       11-Feb-2016   Song CY     Redmine #4183                        **
** 1.1.8       02-Oct-2015   Song CY     RedMine #2720, Remove PM Flag        **
** 1.1.7       09-Jun-2015   Song CY     Correct MISRA-Rule Violation         **
**                                       #2501, #2265 Modify Variable Type    **
** 1.1.6       03-Mar-2015   Song CY     As per RedMine 2216, Remove version  **
**                                       Information                          **
** 1.1.4       02-Dec-2014   Song CY     RedMine 1719, Update for PolySpace   **
** 1.1.0       18-Apr-2014   Song CY     RedMine718 Version and PM flag       **
**                                       is updated                           **
** 1.0.0       25-Jan-2013    CY Song    Initial version                      **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/*
  polyspace:begin<MISRA-C:5.1:Not a defect:Justify with annotations> This Identifier is Specification.
*/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "NvM.h"         /* NvM header file */
#include "NvM_Ram.h"     /* Global variables header file */

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/* Init RAM 16 Bit Section */
#define NVM_START_SEC_VAR_CLEARED_16
#include "MemMap.h"

/* Holds the total block length */
VAR(uint16, NVM_VAR)NvM_GusBlockLength;

/* Holds the total block length */
VAR(uint16, NVM_VAR)
  NvM_GaaRamStatus[NVM_TOTAL_NUM_OF_NVRAM_BLOCKS];

#if(NVM_TOTAL_NUM_OF_READALL_BLOCKS > 0)
/* Holds the count of blocks to be processed for ReadAll operation */
VAR(uint16, NVM_VAR)NvM_GusReadAllCnt;
#endif

#if(NVM_TOTAL_NUM_OF_WRITEALL_BLOCKS > 0)
/* Holds the count of blocks to be processed for WriteAll operation */
VAR(uint16, NVM_VAR)NvM_GusWriteAllCnt;
#endif

#define NVM_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

/* Init RAM 8 Bit Section */
#define NVM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
/* Holds the retry count */
VAR(uint8, NVM_VAR)NvM_GucRetryCount;

#if((NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1) && \
 (NVM_JOB_PRIORITIZATION == STD_ON) && (NVM_IMM_JOB_PRIORITY == STD_ON))
/* Holds the start position of Immediate queue buffer */
VAR(uint8, NVM_VAR)NvM_GucImmQueStartPos;

/* Holds the end position of Immediate queue buffer */
VAR(uint8, NVM_VAR)NvM_GucImmQueEndPos;

/* Holds the count of requests present in Immediate queue buffer */
VAR(uint8, NVM_VAR) NvM_GucImmQueEnDis;
#endif

#if(NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1)
/* Holds the start position of Standard queue buffer */
VAR(uint8, NVM_VAR)NvM_GucStdQueStartPos;

/* Holds the end position of Standard queue buffer */
VAR(uint8, NVM_VAR)NvM_GucStdQueEndPos;

/* Holds the count of requests present in Standard queue buffer */
VAR(uint8, NVM_VAR)NvM_GucStdQueEnDis;
#endif

/*
 * Following variables are used for maintaining Main and Sub states of NVRAM
 * Manager Module
 */

/* Holds the NVRAM Manager main state */
VAR(uint8, NVM_VAR)NvM_GucState;

/* Holds the NVRAM Manager Sub state */
VAR(uint8, NVM_VAR)NvM_GucSubState;

/* Holds the NVRAM Manager Sub states of ReadAll Function */
VAR(uint8, NVM_VAR)NvM_GucReadAllState;

/*  Holds the NVRAM Manager Sub states of WriteAll Function */
VAR(uint8, NVM_VAR)NvM_GucWriteAllSubState;

/* Following variables are used for generic purpose */

/* Indicates Global status of WriteAll/ReadAll function */
VAR(uint8, NVM_VAR)NvM_GucNotifiedGlobalStatus;

/*
 * Following variables are used as flags for holding the status of NVRAM
 * Manager operation during different API requests
 */

/* Flag to indicate status of processing of Redundant block */
VAR(NvM_StatusReBlock, NVM_VAR)NvM_GddReStatus;

/* Flag to indicate status of processing of Redundant block */
VAR(NvM_RefirstBlock, NVM_VAR)NvM_GddFirstBlock;

/* Flag to indicate status of Writing of Redundant block */
VAR(uint8, NVM_VAR)NvM_GucChkRedundant;

/* Flag to indicate NvM_WriteAll request acceptance */
VAR(uint8, NVM_VAR)NvM_GucWriteAllRequest;

/* Flag to indicate NvM_ReadAll request acceptance */
VAR(uint8, NVM_VAR)NvM_GucReadAllRequest;

/* To hold the status of write verification */
#if(NVM_WRITE_VERIFICATION == STD_ON)
VAR(uint8, NVM_VAR)NvM_GucWriteVerify;
#endif

#if(NVM_BLOCK_USE_SYNC_MECHANISM == STD_ON)
/* Holds count for Mirror Retries */
VAR(uint8, NVM_VAR)NvM_GucMirrorCount;
#endif

/* Holds count for sending PM Prevent */
VAR(uint8, NVM_VAR) NvM_GucPM_Count;

/* Pointer to store start address of ROM CRC */
P2CONST(uint8, AUTOMATIC, NVM_APPL_CONST)NvM_GpRomBlkDataAddrs;

/* Global variable to calculate CRC */
VAR(uint8, NVM_VAR) NvM_GucMsb;
VAR(uint8, NVM_VAR) NvM_GucMidHi;
VAR(uint8, NVM_VAR) NvM_GucMidLow;
VAR(uint8, NVM_VAR) NvM_GucLsb;

#if((NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && \
    (NVM_JOB_PRIORITIZATION == STD_ON) && (NVM_IMM_JOB_PRIORITY == STD_ON))
/* Holds the free index of Immediate queue buffer */
VAR(uint8, NVM_VAR)
  NvM_GaaImmFreeList[NVM_SIZE_IMMEDIATE_JOB_QUEUE];

/* Holds the index of Immediate Free list */
VAR(uint8, NVM_VAR)NvM_GucImmFreeIndx;

/* Holds the index of Immediate Free list */
VAR(uint8, NVM_VAR)NvM_GucImmFreeSlotsAvail;
#endif

#if(NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1)
/* Holds the free index of Standard queue buffer */
VAR(uint8, NVM_VAR)
  NvM_GaaStdFreeList[NVM_SIZE_STANDARD_JOB_QUEUE];

/* Holds the index of Standard Free list */
VAR(uint8, NVM_VAR)NvM_GucStdFreeIndx;

/* Holds the index of Standard Free list */
VAR(uint8, NVM_VAR)NvM_GucStdFreeSlotsAvail;
#endif

#if(NVM_BLOCK_USE_SYNC_MECHANISM == STD_ON)
/* Buffer to hold Mirror data */
VAR(uint8, NVM_VAR)NvM_GaaMirrorBuffer[NVM_MIRROR_BUFFER];
#endif

/* Pointer to the RAM data block */
P2VAR(uint8, AUTOMATIC, NVM_VAR)NvM_GpRamAddr;

/* Pointer to the backup of RAM data block */
P2VAR(uint8, AUTOMATIC, NVM_VAR)NvM_GpRamAddrBackup;

/* Pointer to the RAM data block */
P2VAR(uint8, AUTOMATIC, NVM_VAR)NvM_GpPreviousRamAddr;
/* Pointer to store write verify data */
P2VAR(uint8, AUTOMATIC, NVM_VAR)NvM_GpWriteVerifySourceData;

P2VAR(uint8, AUTOMATIC, NVM_VAR) NvM_GaaDataBuffer;

/* Buffer to hold Mirror data, 6 : management bytes for EA , 2 : reserved */
VAR(uint8, NVM_VAR)
  NvM_GaaDataBufferSource[NVM_MIRROR_BUFFER+NVM_CRC_SID_SIZE + 8U];

#define NVM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#if((NVM_STATIC_ID_CHECK == STD_ON) || (NVM_CRC_SUPPORT == STD_ON))
/* Holds the CRC/Static ID data */
VAR(uint8, NVM_VAR)NvM_GaaReadCRCSID[NVM_CRC_SID_SIZE];
#endif

/* Indicates status of MEMIF Driver service command */
VAR(NvM_RequestResultType, NVM_VAR)
  NvM_GddJobResultLowLevel;

#if (NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1)
/* Buffer to hold the standard priority request Block Id and Service Id */
VAR(NvM_JobQueue, NVM_VAR)NvM_GaaStdQueueBuffer
  [NVM_SIZE_STANDARD_JOB_QUEUE];

/* Structure to hold the standard priority request Block Id and Service Id */
VAR(NvM_JobQueue, NVM_VAR)NvM_GstStdPrevReq;
#endif

#if((NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1) && \
    (NVM_JOB_PRIORITIZATION == STD_ON) && (NVM_IMM_JOB_PRIORITY == STD_ON))
/* Buffer to hold the immediate priority request Block Id and Service Id */
VAR(NvM_JobQueue, NVM_VAR)NvM_GaaImmQueueBuffer
  [NVM_SIZE_IMMEDIATE_JOB_QUEUE];
#endif

/* Pointer to Global Descriptor Table */
P2CONST(NvM_BlkDescTbl, AUTOMATIC, NVM_APPL_CONST)NvM_GpNvmBlkDescTbl;

/* Indicates the Global Block Id which is under progress */
VAR(NvM_BlockIdType, NVM_VAR)NvM_GddBlockIdx;

/* Holds the Block Management type */
VAR(NvM_BlockManagementType, NVM_VAR)NvM_GenBlkMngmntType;
#define NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
/* Holds the status of whether block is skipped */
VAR(boolean, NVM_VAR)NvM_Gblflag;

/* Holds the status of whether block is skipped */
VAR(boolean, NVM_VAR)NvM_GblRestoreFlag;

#if((NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1) && \
    (NVM_JOB_PRIORITIZATION == STD_ON) && (NVM_IMM_JOB_PRIORITY == STD_ON))
/*
 * Flag to indicate immediate priority request (immediate Erase/Write) is in
 * progress
 */
VAR(boolean, NVM_VAR)NvM_GblHighPriorityRequest;

/* Flag holds the status of previous immediate request */
VAR(boolean, NVM_VAR)NvM_GblPrevReqImm;
#endif

/* Flag to indicate status of "Cancel Write All" request */
VAR(boolean, NVM_VAR)NvM_GblCancelWriteAll;

/* Flag to indicate that stored and compiled Configuration Ids are matching */
VAR(boolean, NVM_VAR)NvM_GblConfigIdMatch;

/* Variable to indicate NVRAM Manager is initialized */
VAR(boolean, NVM_VAR)NvM_GblInitDone;

#if (NVM_BLOCK_USE_SYNC_MECHANISM == STD_ON)
/* Variable to indicate NVRAM Manager is initialized */
VAR(boolean, NVM_VAR)NvM_GblQueueShuffle;
#endif
#define NVM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/*
  polyspace:end<MISRA-C:5.1:Not a defect:Justify with annotations> This Identifier is Specification.
*/
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
