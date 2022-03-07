/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: NvM.h                                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR NvM Module                                            **
**                                                                            **
**  PURPOSE   : Provision of Macros and API Prototype Declarations            **
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
** 1.3.2       29-Jun-2017   Yun  YJ      Redmine #8869                       **
** 1.3.1       21-Sep-2016   Song CY      Redmine #6058                       **
** 1.1.8       02-Oct-2015   Song CY      RedMine #2720, Add Lowpower Define  **
** 1.1.7       09-Jul-2015   Song CY      Correct MISRA-Rule Violation        **
** 1.0.0       25-Jan-2013    CY Song     Initial version                     **
*******************************************************************************/

#ifndef NVM_H
#define NVM_H
/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/*
polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard-Chap 5.1.2)
*/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "NvM_Cfg.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/* Service Id Of All Application APIS */

/* Service ID for NvM_SetDataIndex */
#define  NVM_SETDATAINDEX_SID                 ((uint8)0x01U)

/* Service ID for NvM_GetDataIndex */
#define  NVM_GETDATAINDEX_SID                 ((uint8)0x02U)

/* Service ID for NvM_SetBlockProtection */
#define  NVM_SETBLOCKPROTECTION_SID           ((uint8)0x03U)

/* Service ID for NvM_GetErrorStatus */
#define  NVM_GETERRORSTATUS_SID               ((uint8)0x04U)

/* Service ID for NvM_SetRamBlockStatus */
#define  NVM_SETRAMBLOCKSTATUS_SID            ((uint8)0x05U)

/* Service ID for NvM_ReadBlock */
#define  NVM_READBLOCK_SID                    ((uint8)0x06U)

/* Service ID for NvM_WriteBlock */
#define  NVM_WRITEBLOCK_SID                   ((uint8)0x07U)

/* Service ID for NvM_RestoreBlockDefaults */
#define  NVM_RESTOREBLOCKDEFAULTS_SID         ((uint8)0x08U)

/* Service ID for NvM_EraseNvBlock */
#define  NVM_ERASENVBLOCK_SID                 ((uint8)0x09U)

/* Service ID for NvM_CancelWriteAll */
#define  NVM_CANCELWRITEALL_SID               ((uint8)0x0aU)

/* Service ID for NvM_InvalidateNvBlock */
#define  NVM_INVALIDATENVBLOCK_SID            ((uint8)0x0bU)

/* Service ID for NvM_ReadAll */
#define  NVM_READALL_SID                      ((uint8)0x0cU)

/* Service ID for NvM_WriteAll */
#define  NVM_WRITEALL_SID                     ((uint8)0x0dU)

/* Service ID for NvM_GetVersionInfo */
#define  NVM_GETVERSIONINFO_SID               ((uint8)0x0fU)

/* Service ID for NvM_SetBlockLockStatus */
#define NVM_SETBLOCKLOCKSTATUS_SID            ((uint8)0x13U)

/* Service ID for NvM_CancelJobs */
#define NVM_CANCELJOBS_SID                    ((uint8)0x10U)

/* Service ID for NvM_CalculateCRCStaticID */
#define NVM_CALCRCSID_SID                     ((uint8)0x20U)

/* Service ID for NvM_MainFunction */
#define NVM_MAINFUNCTION_SID                  ((uint8)0x0eU)

/* NvM Instance Id */
#define  NVM_INSTANCE_ID                      ((uint8)0x00U)

/* Det Error Codes */

/* DET Code to report request Invalid BlockID */
#define NVM_E_PARAM_BLOCK_ID          0x0a

/* DET Code to report request of wrong parameter for Block Management type */
#define NVM_E_PARAM_BLOCK_TYPE        0x0b

/* DET Code to report overflow of DataIndex parameter of configured datasets */
#define NVM_E_PARAM_BLOCK_DATA_IDX    0x0c

/*
 * DET Code to report absence of Permanent RAM block when NULL pointer is
 * passed as parameter
 */
#define NVM_E_PARAM_ADDRESS           0x0d

/* DET Code to report passing of NULL pointer as parameter in synchronous API */
#define NVM_E_PARAM_DATA              0x0e

/* DET Code to report passing of NULL_PTR as parameter of versioninfo */
#define NVM_E_PARAM_POINTER           0x0f

/* DET Code to report Uninitialized state */
#define NVM_E_NOT_INITIALIZED         0x14

/* DET Code to report NVRAM block identifier is already in requested service */
#define NVM_E_BLOCK_PENDING           0x15

/* DET Code to report the service is not possible with current configuration */
#define NVM_E_BLOCK_CONFIG            0x18

/* DET Code to report if block is locked */
#define NVM_E_BLOCK_LOCKED            0x19


#define NVM_LOWPOWER_PREVENT          (0x00U)

#define NVM_LOWPOWER_ALLOW            (0x01U)
/*******************************************************************************
**                       Function Prototypes                                  **
*******************************************************************************/

#define NVM_START_SEC_CODE
#include "MemMap.h"
/* NvM_Init API Prototype Declarations */
extern FUNC(void, NVM_CODE)NvM_Init(void);

/* NvM_CancelWriteAll API Prototype Declarations */
extern FUNC(void, NVM_CODE)NvM_CancelWriteAll(void);

/* NvM_ReadAll API Prototype Declarations */
extern FUNC(void, NVM_CODE)NvM_ReadAll(void);

/* NvM_WriteAll API Prototype Declarations */
extern FUNC(void, NVM_CODE)NvM_WriteAll(void);

/* NvM_MainFunction API Prototype Declarations */
extern FUNC(void, NVM_CODE)NvM_MainFunction(void);

/* NvM_SetBlockLockStatus API Prototype Declarations */
extern FUNC(void, NVM_CODE)NvM_SetBlockLockStatus
  (NvM_BlockIdType BlockId, boolean BlockLocked);

/* NvM_GetErrorStatus API Prototype Declarations */
extern FUNC(Std_ReturnType, NVM_CODE)NvM_GetErrorStatus(NvM_BlockIdType
  BlockId, P2VAR(NvM_RequestResultType, AUTOMATIC, NVM_APPL_DATA)
  RequestResultPtr);

#if(NVM_SET_RAM_BLOCK_STATUS_API  == STD_ON)
/* NvM_SetRamBlockStatus API Prototype Declarations */
extern FUNC(Std_ReturnType, NVM_CODE)NvM_SetRamBlockStatus
  (NvM_BlockIdType BlockId, boolean BlockChanged);
#endif

#if(NVM_API_CONFIG_CLASS  ==  NVM_API_CONFIG_CLASS_3)

/* NvM_SetBlockProtection API Prototype Declarations */
extern FUNC(Std_ReturnType, NVM_CODE)NvM_SetBlockProtection
  (NvM_BlockIdType BlockId, boolean ProtectionEnabled);

/* NvM_EraseNvBlock API Prototype Declarations */
extern FUNC(Std_ReturnType, NVM_CODE)NvM_EraseNvBlock(NvM_BlockIdType
  BlockId);

/* NvM_InvalidateNvBlock API Prototype Declarations */
extern FUNC(Std_ReturnType, NVM_CODE)NvM_InvalidateNvBlock(
  NvM_BlockIdType BlockId);
  
#endif

#if(NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1)
/* NvM_SetDataIndex API Prototype Declarations */
extern FUNC(Std_ReturnType, NVM_CODE)NvM_SetDataIndex(NvM_BlockIdType
  BlockId, uint8 DataIndex);

/* NvM_GetDataIndex API Prototype Declarations */
extern FUNC(Std_ReturnType, NVM_CODE)NvM_GetDataIndex(NvM_BlockIdType
  BlockId, P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) DataIndexPtr);

/* NvM_ReadBlock API Prototype Declarations */
extern FUNC(Std_ReturnType, NVM_CODE)NvM_ReadBlock(NvM_BlockIdType
  BlockId, P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr);

/* NvM_WriteBlock API Prototype Declarations */
extern FUNC(Std_ReturnType, NVM_CODE)NvM_WriteBlock(NvM_BlockIdType
  BlockId, P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_SrcPtr);

/* NvM_RestoreBlockDefaults API Prototype Declarations */
extern FUNC(Std_ReturnType, NVM_CODE)NvM_RestoreBlockDefaults(
  NvM_BlockIdType BlockId, P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr);

extern FUNC(Std_ReturnType, NVM_CODE)NvM_CancelJobs
  (NvM_BlockIdType BlockId);

#if (NVM_VERSION_INFO_API == STD_ON)
/* NvM_GetVersionInfo API Prototype Declarations */
extern FUNC(void, NVM_CODE)NvM_GetVersionInfo
  (P2VAR(Std_VersionInfoType, AUTOMATIC, NVM_APPL_DATA) versioninfo);
#endif /* (NVM_VERSION_INFO_API == STD_ON) */

#endif /* (NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1) */

#define NVM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/*
polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard-Chap 5.1.2)
*/

#endif /* NVM_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
