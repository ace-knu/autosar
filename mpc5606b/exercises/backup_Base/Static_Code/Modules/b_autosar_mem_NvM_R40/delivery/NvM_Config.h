/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: NvM_Config.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR NVM                                                   **
**                                                                            **
**  PURPOSE   : Provides Variable for upper layers                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By               Description                       **
********************************************************************************
** 1.3.2     10-Oct-2016   Song CY     Redmine #6215                          **
** 1.2.3     24-Mar-2016   Song CY     Redmine #4276                          **
** 1.1.8     02-Oct-2015   Song CY     For Runtime Err, add library variable  **
** 1.0.8     30-Sep-2013   Song CY         Update for Library.                **
** 1.0.1     04-Jun-2013    CY Song         XAR~603 : NvM library             **
**                                          Add global variable               **
**                                          NvM_GusTotalNumOfBlock            **
** 1.0.0       25-Jan-2013    CY Song     Initial version                     **
*******************************************************************************/
#ifndef NVM_CONFIG_H_
#define NVM_CONFIG_H_
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#ifdef NVM_GPT_CHANNEL_ID
#include "Gpt.h"
#endif

#include "NvM_Cfg.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define NVM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern const uint8  NvM_GucRepeatMirrorOperations;
extern const uint8  NvM_GucSizeImmediateJobQueue;
extern const uint8  NvM_GucSizeStadardJobQueue;
extern const uint8  NvM_GucCrcSidSize;
extern const uint8  NvM_GucDynConfig;

#if(NVM_DEMERROR_REPORT == STD_ON)
extern const uint16  NvM_GusIntegrityFailed;
extern const uint16  NvM_GusLossOfRedundancy;
extern const uint16  NvM_GusQueueOverflow;
extern const uint16  NvM_GusReqFailed;
extern const uint16  NvM_GusVerifyFailed;
extern const uint16  NvM_GusWriteProtected;
extern const uint16  NvM_GusWrongBlockId;
#endif

#ifdef NVM_GPT_CHANNEL_ID
extern const Gpt_ChannelType NvM_GddGptChannel;
extern const Gpt_ValueType NvM_GddGptValue;
#endif

extern const uint16  NvM_GusTotalNumOfReadAllBlocks;
extern const uint16  NvM_GusTotalNumOfWriteAllBlocks;
extern const uint16  NvM_GusBlockNotConfigReadAll;
extern const uint16  NvM_GusBlockNotConFigWriteAll;
extern const uint16  NvM_GusTotalNumOfBlock;
extern const uint16  NvM_GusMirrorBufferSize;


extern const uint8  NvM_GucDataSetSlectionBits;
extern const uint16 NvM_GusCRCNumOfBytes;
extern const uint16  NvM_GusDataSetIndex;

#if(NVM_WRITE_VERIFICATION == STD_ON)
extern const uint16  NvM_GusMaxWriteVerBlkLength;
#endif /* (NVM_WRITE_VERIFICATION == STD_ON) */

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#endif /* NvM_CONFIG_H_ */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
