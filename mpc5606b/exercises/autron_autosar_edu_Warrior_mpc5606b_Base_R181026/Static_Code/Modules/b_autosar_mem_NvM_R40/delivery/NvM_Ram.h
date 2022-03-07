/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: NvM_Ram.h                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR NvM Module                                            **
**                                                                            **
**  PURPOSE   : Global Variable declarations.                                 **
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
** 1.2.0       10-Dec-2015   Song CY     Correct MISRA-Rule Violation         **
** 1.1.9       10-Nov-2015   Song CY     Correct MISRA-Rule Violation         **
** 1.1.8       02-Oct-2015   Song CY     RedMine #2720, Remove PM Flag        **
** 1.1.7       09-Jun-2015   Song CY     Correct MISRA-Rule Violation         **
**                                       #2501, #2265 Modify Variable Type    **
** 1.1.6       03-Mar-2015   Song CY     As per RedMine 2216, Remove version  **
**                                       Information                          **
** 1.1.4       02-Dec-2014   Song CY     RedMine 1719, Update for PolySpace   **
** 1.1.0       18-Apr-2014   Song CY     RedMine718 Version and PM flag       **
**                                       is updated                           **
** 1.0.10      18-Feb-2014   Song CY     RedMine 632, Update for RTRT         **
** 1.0.8       30-Sep-2013   Song CY     Update for Library                   **
** 1.0.0       25-Jan-2013   CY Song     Initial version                      **
*******************************************************************************/

#ifndef NVM_RAM_H
#define NVM_RAM_H

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/*
  polyspace:begin<MISRA-C:5.1:Not a defect:Justify with annotations> This Identifier is Specification.
  polyspace:begin<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation
*/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "NvM_PCTypes.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/* Init RAM 16 Bit Section */
#define NVM_START_SEC_VAR_CLEARED_16
#include "MemMap.h"

/* Holds the total block length */
extern VAR(uint16, NVM_VAR) NvM_GusBlockLength;

/* Holds the total block length */
extern VAR(uint16, NVM_VAR)
  NvM_GaaRamStatus[];

#if(NVM_TOTAL_NUM_OF_READALL_BLOCKS > 0)
/* Holds the count of blocks to be processed for ReadAll operation */
extern VAR(uint16, NVM_VAR) NvM_GusReadAllCnt;
#endif

#if(NVM_TOTAL_NUM_OF_WRITEALL_BLOCKS > 0)
/* Holds the count of blocks to be processed for WriteAll operation */
extern VAR(uint16, NVM_VAR) NvM_GusWriteAllCnt;
#endif

#define NVM_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

/* Init RAM 8 Bit Section */
#define NVM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
/* Holds the retry count */
extern VAR(uint8, NVM_VAR) NvM_GucRetryCount;

#if((NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1) && \
 (NVM_JOB_PRIORITIZATION == STD_ON) && (NVM_IMM_JOB_PRIORITY == STD_ON))
/* Holds the start position of Immediate queue buffer */
extern VAR(uint8, NVM_VAR) NvM_GucImmQueStartPos;

/* Holds the end position of Immediate queue buffer */
extern VAR(uint8, NVM_VAR) NvM_GucImmQueEndPos;

/* Holds the count of requests present in Immediate queue buffer */
extern VAR(uint8, NVM_VAR) NvM_GucImmQueEnDis;
#endif

#if(NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1)
/* Holds the start position of Standard queue buffer */
extern VAR(uint8, NVM_VAR) NvM_GucStdQueStartPos;

/* Holds the end position of Standard queue buffer */
extern VAR(uint8, NVM_VAR) NvM_GucStdQueEndPos;

/* Holds the count of requests present in Standard queue buffer */
extern VAR(uint8, NVM_VAR) NvM_GucStdQueEnDis;
#endif

/*
 * Following variables are used for maintaining Main and Sub states of NVRAM
 * Manager Module
 */

/* Holds the NVRAM Manager main state */
extern VAR(uint8, NVM_VAR) NvM_GucState;

/* Holds the NVRAM Manager Sub state */
extern VAR(uint8, NVM_VAR) NvM_GucSubState;

/* Holds the NVRAM Manager Sub states of ReadAll Function */
extern VAR(uint8, NVM_VAR) NvM_GucReadAllState;

/*  Holds the NVRAM Manager Sub states of WriteAll Function */
extern VAR(uint8, NVM_VAR) NvM_GucWriteAllSubState;

/* Following variables are used for generic purpose */

/* Indicates Global status of WriteAll/ReadAll function */
extern VAR(uint8, NVM_VAR) NvM_GucNotifiedGlobalStatus;

/*
 * Following variables are used as flags for holding the status of NVRAM
 * Manager operation during different API requests
 */

/* Flag to indicate status of processing of Redundant block */
extern VAR(NvM_StatusReBlock, NVM_VAR) NvM_GddReStatus;

/* Flag to indicate status of processing of Redundant block */
extern VAR(NvM_RefirstBlock, NVM_VAR)NvM_GddFirstBlock;

/* Flag to indicate status of Writing of Redundant block */
extern VAR(uint8, NVM_VAR) NvM_GucChkRedundant;

/* Flag to indicate NvM_WriteAll request acceptance */
extern VAR(uint8, NVM_VAR) NvM_GucWriteAllRequest;

/* Flag to indicate NvM_ReadAll request acceptance */
extern VAR(uint8, NVM_VAR) NvM_GucReadAllRequest;

/* To hold the status of write verification */
#if(NVM_WRITE_VERIFICATION == STD_ON)
extern VAR(uint8, NVM_VAR) NvM_GucWriteVerify;
#endif

#if(NVM_BLOCK_USE_SYNC_MECHANISM == STD_ON)
/* Holds count for Mirror Retries */
extern VAR(uint8, NVM_VAR) NvM_GucMirrorCount;
#endif

/* Holds count for sending PM Prevent */
extern VAR(uint8, NVM_VAR) NvM_GucPM_Count;

/* Pointer to store start address of ROM CRC */
extern P2CONST(uint8, AUTOMATIC, NVM_APPL_CONST) NvM_GpRomBlkDataAddrs;

/* Global variable to calculate CRC */
extern VAR(uint8, NVM_VAR) NvM_GucMsb;
extern VAR(uint8, NVM_VAR) NvM_GucMidHi;
extern VAR(uint8, NVM_VAR) NvM_GucMidLow;
extern VAR(uint8, NVM_VAR) NvM_GucLsb;

#if((NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1) && \
    (NVM_JOB_PRIORITIZATION == STD_ON) && (NVM_IMM_JOB_PRIORITY == STD_ON))
/* Holds the free index of Immediate queue buffer */
extern VAR(uint8, NVM_VAR)
  NvM_GaaImmFreeList[];

/* Holds the index of Immediate Free list */
extern VAR(uint8, NVM_VAR) NvM_GucImmFreeIndx;

/* Holds the index of Immediate Free list */
extern VAR(uint8, NVM_VAR) NvM_GucImmFreeSlotsAvail;
#endif

#if(NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1)
/* Holds the free index of Standard queue buffer */
extern VAR(uint8, NVM_VAR)
  NvM_GaaStdFreeList[];

/* Holds the index of Standard Free list */
extern VAR(uint8, NVM_VAR) NvM_GucStdFreeIndx;

/* Holds the index of Standard Free list */
extern VAR(uint8, NVM_VAR) NvM_GucStdFreeSlotsAvail;
#endif

#if(NVM_BLOCK_USE_SYNC_MECHANISM == STD_ON)
/* Buffer to hold Mirror data */
extern VAR(uint8, NVM_VAR) NvM_GaaMirrorBuffer[];
#endif

/* Pointer to the RAM data block */
extern P2VAR(uint8, AUTOMATIC, NVM_VAR) NvM_GpRamAddr;

/* Pointer to the backup of RAM data block */
extern P2VAR(uint8, AUTOMATIC, NVM_VAR) NvM_GpRamAddrBackup;

/* Pointer to the RAM data block */
extern P2VAR(uint8, AUTOMATIC, NVM_VAR) NvM_GpPreviousRamAddr;
/* Pointer to store write verify data */
extern P2VAR(uint8, AUTOMATIC, NVM_VAR) NvM_GpWriteVerifySourceData;

extern P2VAR(uint8, AUTOMATIC, NVM_VAR) NvM_GaaDataBuffer;

/* Buffer to hold Mirror data */
extern VAR(uint8, NVM_VAR) NvM_GaaDataBufferSource[];

#define NVM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
#if((NVM_STATIC_ID_CHECK == STD_ON) || (NVM_CRC_SUPPORT == STD_ON))
/* Holds the CRC/Static ID data */
extern VAR(uint8, NVM_VAR) NvM_GaaReadCRCSID[];
#endif

/* Indicates status of MEMIF Driver service command */
extern VAR(NvM_RequestResultType, NVM_VAR)
  NvM_GddJobResultLowLevel;

#if (NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1)
/* Buffer to hold the standard priority request Block Id and Service Id */
extern VAR(NvM_JobQueue, NVM_VAR) NvM_GaaStdQueueBuffer
  [];

/* Structure to hold the standard priority request Block Id and Service Id */
extern VAR(NvM_JobQueue, NVM_VAR) NvM_GstStdPrevReq;
#endif

#if((NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1) && \
    (NVM_JOB_PRIORITIZATION == STD_ON) && (NVM_IMM_JOB_PRIORITY == STD_ON))
/* Buffer to hold the immediate priority request Block Id and Service Id */
extern VAR(NvM_JobQueue, NVM_VAR) NvM_GaaImmQueueBuffer
  [];
#endif

/* Pointer to Global Descriptor Table */
extern P2CONST(NvM_BlkDescTbl, AUTOMATIC, NVM_APPL_CONST) NvM_GpNvmBlkDescTbl;

/* Indicates the Global Block Id which is under progress */
extern VAR(NvM_BlockIdType, NVM_VAR) NvM_GddBlockIdx;


/* Holds the Block Management type */
extern VAR(NvM_BlockManagementType, NVM_VAR) NvM_GenBlkMngmntType;
#define NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
/* Holds the status of whether block is skipped */
extern VAR(boolean, NVM_VAR) NvM_Gblflag;

/* Holds the status of whether block is skipped */
extern VAR(boolean, NVM_VAR) NvM_GblRestoreFlag;

#if((NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1) && \
    (NVM_JOB_PRIORITIZATION == STD_ON) && (NVM_IMM_JOB_PRIORITY == STD_ON))
/*
 * Flag to indicate immediate priority request (immediate Erase/Write) is in
 * progress
 */
extern VAR(boolean, NVM_VAR) NvM_GblHighPriorityRequest;

/* Flag holds the status of previous immediate request */
extern VAR(boolean, NVM_VAR) NvM_GblPrevReqImm;
#endif

/* Flag to indicate status of "Cancel Write All" request */
extern VAR(boolean, NVM_VAR) NvM_GblCancelWriteAll;

/* Flag to indicate that stored and compiled Configuration Ids are matching */
extern VAR(boolean, NVM_VAR) NvM_GblConfigIdMatch;

/* Variable to indicate NVRAM Manager is initialized */
extern VAR(boolean, NVM_VAR) NvM_GblInitDone;

#if (NVM_BLOCK_USE_SYNC_MECHANISM == STD_ON)
/* Variable to indicate NVRAM Manager is initialized */
extern VAR(boolean, NVM_VAR) NvM_GblQueueShuffle;
#endif
#define NVM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/*
  polyspace:end<MISRA-C:5.1:Not a defect:Justify with annotations> This Identifier is Specification.
  polyspace:end<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation
*/

#endif  /* NVM_RAM_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
