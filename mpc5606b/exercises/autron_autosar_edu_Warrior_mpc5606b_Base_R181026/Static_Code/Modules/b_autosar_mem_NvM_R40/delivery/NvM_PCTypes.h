/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: NvM_PCTypes.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR NvM Module                                            **
**                                                                            **
**  PURPOSE   : Provision of AUTOSAR NVRAM Manager Type Definitions and       **
**              Block Descriptor structure.                                   **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision    Date          By             Description                       **
********************************************************************************
** 1.3.4     07-Dec-2016   Song CY     Redmine #6889                          **
** 1.3.3     16-Nov-2016   Song CY     Redmine #6680                          **
** 1.3.2     10-Oct-2016   Song CY     Redmine #6215                          **
** 1.3.0       25-Jul-2016   Song CY      Redmine #3883                       **
** 1.2.3       24-Mar-2016   Song CY      Redmine #4276                       **
** 1.2.2       11-Feb-2016  Song CY       Redmine #4183                       **
** 1.1.9       10-Nov-2015  Song CY       Correct MISRA-Rule Violation        **
** 1.1.7       09-Jul-2015  Song CY       Correct MISRA-Rule Violation        **
** 1.1.6       03-Mar-2015  Song CY       As per RedMine 2208, Add states of  **
**                                        ProcessReadblock                    **
**                                        As per RedMine 2216, Remove version **
**                                        Information                         **
** 1.1.4       02-Dec-2014  Song CY       RedMine 1719, Update for PolySpace  **
** 1.0.10      18-Feb-2014  Song CY       RedMine 632, Update for RTRT        **
** 1.0.8       30-Sep-2013  Song CY       Update for Library                  **
** 1.0.0       25-Jan-2013    CY Song     Initial version                     **
*******************************************************************************/

#ifndef NVM_PCTYPES_H
#define NVM_PCTYPES_H

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/*
  polyspace:begin<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation
*/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "NvM.h"

/*******************************************************************************
**                        Global Data                                         **
*******************************************************************************/
/* Bit Order for Block Descriptor Parameters  (ucBlkParams) */
#define NVM_TRUE                          ((boolean)1)
#define NVM_FALSE                         ((boolean)0)

/* Macros used used for accessing a particular block */
#define NVM_ZERO                          ((uint8)0U)
#define NVM_ONE                           ((uint8)1U)
#define NVM_TWO                           ((uint8)2U)
#define NVM_FOUR                          ((uint8)4U)
#define NVM_SIX                           ((uint8)6U)
#define NVM_EIGHT                         ((uint8)8U)
#define NVM_SIXTEEN                       ((uint8)16U)
#define NVM_TWENTYFOUR                    ((uint8)24U)
#define NVM_100                           ((uint8)100U)
#define NVM_FF                            ((uint8)0xFFU)

#define NVM_RESVD_DEVICEID                ((uint8)255U)

#define NVM_STD_PRIORITY                  ((uint8)1U)
#define NVM_IMM_PRIORITY                  ((uint8)0U)

/* Macros used for CRC offset values */
#define NVM_1BYECRC_STARTVALUE            ((uint8)0xFFU)
#define NVM_2BYECRC_STARTVALUE            ((uint16)0xFFFFU)
#define NVM_4BYECRC_STARTVALUE            (0xFFFFFFFFU)

/* MACROS USED FOR PROCESSING BYTES/BLOCKS IN MULTIPLE CYCLES */

/* Defines the Number of Bytes parsed per scan cycle in restoreROM */
#define NVM_BYTES_PER_SCAN                ((uint8)32U)

/* MASKS USED TO READ/SET THE SPECIFIC BITS IN NvM_GaaRamStatus */

/* To get the error bits in the error field of RAM */
#define NVM_ERROR_BIT_MASK                ((uint16)0x000FU)

/* To update the error bits in the error field of RAM */
#define NVM_NOT_ERROR_BIT_MASK            ((uint16)0xFFF0U)

/* Mask to set the Write protection bit */
#define NVM_WRITE_PROTECT_MASK            ((uint16)0x0080U)

/* Mask to clear the Write protection bit */
#define NVM_NOT_WRITE_PROTECT_MASK        ((uint16)0xFF7FU)

/* Mask to Set the Lock protection bit */
#define NVM_LOCK_RAM_MASK                 ((uint16)0x0040U)

/* Mask to clear the Lock protection bit */
#define NVM_UNLOCK_RAM_MASK               ((uint16)0xFFBFU)

/* Mask to set RamCrcRequested bit */
#define NVM_CRC_REQUESTED_MASK            ((uint16)0x0100U)

/* Mask to Set the check redundant which block is first write bit */
#define NVM_FIR_REDUNDANT_MASK            ((uint16)0x0200U)

/* Mask to Set the check redundant which block is first write bit */
#define NVM_SEC_REDUNDANT_MASK            ((uint16)0xFDFFU)

/* Mask to Set the need to check redundant bit */
#define NVM_CHECK_NEED_REDUNDANT_MASK     ((uint16)0x0400U)

/* Mask to clear the need to check redundant bit */
#define NVM_CHECK_DONE_REDUNDANT_MASK     ((uint16)0xFBFFU)

/* MACROS TO READ CONFIGURATION INFORMATION FROM usBlkParams*/

/* Bit 0 - Generation of CRC */
#define NVM_CALC_RAM_BLK_CRC                  ((uint16)0x0001U)
/* Bit 1 - Default Write Protection */
#define NVM_BLOCK_WRITE_PROT                  ((uint16)0x0002U)
/* Bit 2 - Block is of one time Write */
#define NVM_WRITE_BLOCK_ONCE                  ((uint16)0x0004U)
/* Bit 3 - Resistant to changed software */
#define NVM_RESISTANT_TO_CHANGED_SW           ((uint16)0x0008U)
/* Bit 4 - Enables/Disables processing block during readall */
#define NVM_SELECT_BLOCK_FOR_READALL          ((uint16)0x0010U)
/* Bit 6 - Enables/Disables explicit synchronization mechanism*/
#define NVM_BLOCK_USE_SYNC_MECHANISM_ENABLE   ((uint16)0x0040U)
/* Bit 8 - Enables/Disables Write Verification */
#define NVM_WRITE_VERIFICATION_ENABLE         ((uint16)0x0100U)
/* Bit 9 - Enables/Disables Static ID check */
#define NVM_STATIC_BLOCK_ID_CHECK             ((uint16)0x0200U)
/* Bit 10 - If it is set, it intimates to BswM about the current status */
#define NVM_BSWM_BLOCK_STATUS_INFORMATION     ((uint16)0x0400U)
/* Bit 11 - If it is set, it intimates to Calculate CRC on ROM data */
#define NVM_DEFAULT_ROM_CRC_ENABLED           ((uint16)0x0800U)

/* Macro to check CRC configured */
#define NVM_CALC_CRC_BLOCK_CHECK              ((uint16)0x0021U)

/* MACROS RELATED TO CRC CALCULATION */

/* Defines macros for CRC length */
#define NVM_CRC_4BYTE                     0x04
#define NVM_CRC_2BYTE                     0x02
#define NVM_CRC_1BYTE                     0x01

/* MACROS RELATED TO RAM INTERNAL STATES */

/* Macro to define RAM status */
#define NVM_INVALID_UNCHANGED             ((uint8)0x00U)
#define NVM_VALID_UNCHANGED               ((uint8)0x20U)
#define NVM_VALID_CHANGED                 ((uint8)0x30U)

/* MACROS RELATED TO MASK RAM INTERNAL STATES */
#define NVM_CLEAR_RAM_INTERNAL_STATE      ((uint16)0xFFCFU)
#define NVM_RAM_STATUS_MASK               ((uint16)0x0030U)

/* Macro to indicate the status of Redundant block */
typedef enum
{
  NVM_RE_CHK_NONE = 0,
  NVM_RE_CHKED_ORIGIN,
  NVM_RE_CHKED_COPY,
} NvM_StatusReBlock;

/* Macro to indicate the first write of Redundant block */
typedef enum
{
  NVM_RE_ORIGINAL_FIRST = 0,
  NVM_RE_COPY_FIRST,
} NvM_RefirstBlock;

/* Macro to indicate the status of ReadAll/WriteAll processing */
#define NVM_MULTIBLK_UNREQUESTED          0x00
#define NVM_MULTIBLK_REQUESTED            0x01
#define NVM_MULTIBLK_IN_PROGRESS          0x02

/* MACROS TO DEFINE VARIOUS FUNCTIONAL STATES */
/* Common state values used in all API processing functions */
#define NVM_IDLE                          0x00
#define NVM_SUB_IDLE                      0x00

/* Sub states of WriteBlock function */
#define   NVM_WRITE_NVBLOCK               0x01
#define   NVM_WRITE_PROCESS_NV_BLOCK      0x02
#define   NVM_IMMD_WRITE_PENDING          0x03
#define   NVM_PROCESS_WRITE_VERIFY        0x04

/* Sub states of WriteAll function */
#define   NVM_WRITE_ALL_IDLE              0x00
#define   NVM_WRITE_ALL_BLOCK             0x01
#define   NVM_WRITE_ALL_PROCESS           0x02
#define   NVM_WRITE_ALL_INIT              0x03

/* Sub states of Erase/Invalidate function */
#define NVM_ERASEINVALIDATE_START         0x01
#define NVM_ERASEINVALIDATE_PROCESSING    0x02

/* Sub states of ProcessReadblock function */
#define NVM_READ_START                    0x01
#define NVM_READ_NVBLOCK                  0x02
#define NVM_READ_ROM                      0x03
#define NVM_READ_REDUNDANT_RETRY          0x04
#define NVM_READ_ERROR_STATUS             ((uint8)0xFFU)

/* Sub states of ProcessReadAllBlocks function */
#define NVM_READALL_INIT                  0x01
#define NVM_READALL_PROCESS               0x02
#define NVM_READALL_BLKPROCESS            0x05
#define NVM_READALL_ROMBLK_PROCESS        0x04

typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_InitNotificationFnType)(void);

typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_NotificationFnType)
  (uint8 ServiceId, NvM_RequestResultType JobResult);

typedef P2FUNC(void, NVM_APPL_CODE, NvM_MultiCBFnType)
  (uint8 ServiceId, NvM_RequestResultType JobResult);

typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvMReadMirrorNotification)
  (const void* NvMBuffer);

  typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvMWriteMirrorNotification)
  (void* NvMBuffer);

/* Typedef of NvM_BlkDescTbl structure */

/* Structure for Block Descriptor Table */
typedef struct STag_NvM_BlkDescTbl
{
  /* Pointer to permanent RAM block data array */
  /* If NVM_RAM_BLOCK_DATA_ADDRESS is STD_ON and Ram Block address is not
   * configured for a particular block then generate NULL_PTR
   */
  #if(NVM_RAM_BLOCK_DATA_ADDRESS == STD_ON)
  P2VAR(void, AUTOMATIC, NVM_DATA)pRamBlkData;
  #endif

  /* Pointer to RAM Index field */
  P2VAR(uint8, AUTOMATIC, NVM_DATA)pRamIndex;

  /* Pointer to ROM Block Data */
  P2CONST(void, AUTOMATIC, NVM_CONST)pRomBlkData;

  /* Pointer to   Init Block callback */
  /* If NVM_INIT_CALLBACK is STD_ON and Notification is not configured then
   * generate NULL_PTR
   */
  #if (NVM_INIT_CALLBACK == STD_ON)
  NvM_InitNotificationFnType pNvMInitNotification_BlockId;
  #endif

  /* Pointer to Single Block callback  */
  /* If NVM_SINGLE_BLOCK_CALLBACK is STD_ON and Notification is not configured
   * then generate NULL_PTR
   */
  #if (NVM_SINGLE_BLOCK_CALLBACK == STD_ON)
  NvM_NotificationFnType pNvMNotification_BlockId;
  #endif

  /* Pointer to ReadRamBlockFromNvm callback */
  /* If NVM_BLOCK_USE_SYNC_MECHANISM is STD_ON and callback is not configured
   * then generate NULL_PTR
   */
  #if(NVM_BLOCK_USE_SYNC_MECHANISM == STD_ON)
  NvMReadMirrorNotification pNvMReadRamBlockFromNvm;
  #endif

  /* Pointer to WriteRamBlockToNv callback */
  #if(NVM_BLOCK_USE_SYNC_MECHANISM == STD_ON)
  NvMWriteMirrorNotification pNvMWriteRamBlockToNvm;
  #endif

  /* NVRAM Block Identifier */
  NvM_BlockIdType ddBlockId;

  NvM_BlockManagementType enBlkMngmntType;

  /* BlockBase Number */
  uint16 usNvBlkBaseNumber;

  /* Block Data Length */
  uint16 usNvBlkDataLength;

  /* Write Verification Data Size */
  /* If NVM_WRITE_VERIFICATION is STD_OFF & NvMWriteVerificationDataSize is
   * configured then the configured value should not be considered
   */
  #if(NVM_WRITE_VERIFICATION == STD_ON)
  uint16 usWriteVerificationDataSize;
  #endif

  #if(NVM_WRITE_VERIFICATION == STD_ON)
  uint16 usWriteVerificationSteps;
  #endif

  /* Bit 0 - This bit is set if NvMBlockUseCrc parameter in NvMBlockDescriptor
   *         container is configured as true
   * Bit 1 - This bit is set if NvMBlockWriteProt parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 2 - This bit is set if NvMWriteBlockOnce parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 3 - This bit is set if NvMResistantToChangedSw parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 4 - This bit is set if NvMSelectBlockForReadAll parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 5 - This bit is set if NvMCalcRamBlockCrc parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 6 - This bit is set if NvMBlockUseSyncMechanism parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 7 - This bit is set if NvMSelectBlockForWriteAll parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 8 - This bit is set if NvMWriteVerification parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 9 - This bit is set if NvMStaticBlockIDCheck parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 10 - This bit is set if NvMBswMBlockStatusInformation parameter in
   *         NvMBlockDescriptor container is configured as true
   * Bit 11 - This bit is set if NvMDefaultROMCRCEnabled parameter in
   *          NvMBlockDescriptor container is configured as true
   */
  uint16 usBlkParams;

  /* NVRAM device ID value */
  uint8 ucNvramDeviceId;

  /* = 0 if not configured, = 1 for 8 bit CRC, = 2 for 16 bit and =4 for
   * 32 bit
   */
  #if(NVM_CRC_SUPPORT == STD_ON)
  uint8 ucCrcLength;
  #endif

  /* Number of NV blocks */
  uint8 ucNumOfNvBlks;

  /* Number of ROM blocks */
  uint8 ucNumOfRomBlks;

  /* Max Number of Read Retries */
  uint8 ucMaxNumOfReadRetries;

  /* Max Number of Write Retries */
  uint8 ucMaxNumOfWriteRetries;

  /* Block Priority:0-Immediate other than 0-Standard   */
  #if((NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1) && \
      (NVM_JOB_PRIORITIZATION == STD_ON))
  uint8 ucBlkJobPriority;
  #endif

}NvM_BlkDescTbl;

/* Structure of Job queue */
typedef struct STag_NvM_JobQueue
{
  P2CONST(uint8, AUTOMATIC, NVM_CONST) pTempRamBlkData;
  NvM_BlockIdType ddBlock_Idx;
  uint8 ucService_Id;
  uint8 ucNextIndex;
  uint8 ucPreviousIndex;
  #if((NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1) && \
      (NVM_JOB_PRIORITIZATION == STD_ON))
  uint8 ucPriority;
  #endif
}NvM_JobQueue;

/* Define struct for direct manipulation of 16 bit data */
typedef struct UTag_NvM_Word16
{
  uint16 usWordReg16;
}NvM_Word16;


/* Define struct for direct manipulation of 32 bit register */
typedef struct UTag_NvM_DWord32
{
 uint32 ulLongReg32;
}NvM_DWord32;


/*
 * This array defines the structure for each NVRAM block configured
 * in input XML file
 */
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(NvM_BlkDescTbl, NVM_CONST) NvM_GaaBlkDescTbl[];

extern CONST(NvM_MultiCBFnType, NVM_CONST) NvM_NvMMultiCBFctPtr;
#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Size of the array should be the total number of blocks configure for
 * Static ID and CRC
 * Eg: Block 2 = SID ON, CRC 8 ON    = 2+1
 *    Block 3 = SID ON, CRC 16 ON   = 2+2
 *   Block 4 = SID OFF, CRC 32 ON  = 0+4
 *    Then total of NvM_GaaCrcSID should be 11
 */
#if((NVM_STATIC_ID_CHECK == STD_ON) || (NVM_CRC_SUPPORT == STD_ON))
#define NVM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
extern VAR(uint8, NVM_VAR) NvM_GaaCrcSID[];
#define NVM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"
#endif

#if(NVM_DATASET_PRESENT == STD_ON)
#define NVM_START_SEC_VAR_POWER_ON_CLEARED_8
#include "MemMap.h"
/* Size of the array should be the number of blocks with dataset management
 * that are configured
 */
extern VAR(uint8, NVM_VAR) NvM_GaaRamIndex[];
#define NVM_STOP_SEC_VAR_POWER_ON_CLEARED_8
#include "MemMap.h"
#endif

#endif /* NVM_PCTYPES_H */
/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/*
  polyspace:end<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation
*/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
