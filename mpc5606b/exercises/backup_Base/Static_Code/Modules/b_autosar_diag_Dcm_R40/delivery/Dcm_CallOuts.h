/*******************************************************************************
**  (C) 2014 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_CallOuts.H                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : This file contains the declaration for Dcm callout functions  **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By              Description                        **
********************************************************************************
** 1.0.3     19-04-2017    Jin      Jung   #6973, #8006                       **
**                                                                            **
** 1.0.2     05-12-2016    Jin      Jung   #6645                              **
**                                                                            **
** 1.0.1     24-05-2016    Jun      Jung   #4922                              **
**                                                                            **
** 1.0.0     06-07-2011    Autron          Initial Version                    **
*******************************************************************************/

#ifndef DCM_CALLOUTS_H
#define DCM_CALLOUTS_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dcm.h"
#include "Dcm_PCTypes.h"
#include "HwResource.h"
#include "Rte_Type.h"
/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define DCM_START_SEC_CALLOUT_CODE
#include "MemMap.h"

#if (HWRESOURCE_VENDOR(HWRESOURCE_INFINEON))
/* Structure for programming condition used in both DCM and FBL (For AURIX) */
typedef struct
{
  /* Tester source address configured per protocol */
  uint16 TesterSourceAddr;
  /* reserved for align */
  uint16 reserved0;
  /* Id of the protocol on which the request has been received */
  uint8 ProtocolId;
  /* Service identifier of the received request */
  uint8 Sid;
  /* Identifier of the received subfunction */
  uint8 SubFncId;
  /* Set to true in order to request reprogramming of the ECU */
  uint8 ReprogramingRequest;
  /* Indicate whether the application has been updated or not */
  uint8 ApplUpdated;
  /* Set to true in case the flashloader or application shall send a response */
  uint8 ResponseRequired;
  /* Jump from FBL */
  uint8 JumpFromBootloader;
  /* Security Level 0:lock otherwise:unlock */
  uint8 SecLvInfo;
  /* Reserved bit */
  uint8 Reserved[2];
}Dcm_McuDepProgConditionsType;
#else
/* Structure for programming condition used in both DCM and FBL */
typedef struct
{
  /* Tester source address configured per protocol */
  uint16 TesterSourceAddr;
  /* Id of the protocol on which the request has been received */
  uint8 ProtocolId;
  /* Service identifier of the received request */
  uint8 Sid;
  /* Identifier of the received subfunction */
  uint8 SubFncId;
  /* Set to true in order to request reprogramming of the ECU */
  uint8 ReprogramingRequest;
  /* Indicate whether the application has been updated or not */
  uint8 ApplUpdated;
  /* Set to true in case the flashloader or application shall send a response */
  uint8 ResponseRequired;
  /* Security Level 0:lock otherwise:unlock */
  uint8 SecLvInfo;
}Dcm_McuDepProgConditionsType;
#endif

extern FUNC(Dcm_EcuStartModeType, DCM_CALLOUT_CODE) Dcm_GetProgConditions
  (P2VAR(Dcm_ProgConditionsType, AUTOMATIC,DCM_APPL_DATA) ProgConditions);

extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_SetProgConditions
  (P2CONST(Dcm_ProgConditionsType, AUTOMATIC,DCM_APPL_CONST) ProgConditions);

#ifdef DcmConf_DcmDspSecurityRow_L21
extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_GetRandomSeed
  (P2VAR(uint8, AUTOMATIC,DCM_APPL_DATA) RandomSeed);

extern FUNC(void, DCM_CALLOUT_CODE) Dcm_GetPublicKey
  (P2VAR(uint8, AUTOMATIC,DCM_APPL_DATA) PublicKey);
#endif

extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ProcessRequestTransferExit
  (Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) LpMemoryData,
  uint32* LulParameterRecordSize, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC,
  DCM_PRIVATE_DATA)LpNegativeErrorCode);


extern FUNC(Dcm_ReturnReadMemoryType, DCM_CALLOUT_CODE) Dcm_ReadMemory
  (Dcm_OpStatusType OpStatus,uint8 MemoryIdentifier,uint32 MemoryAddress,
    uint32 MemorySize, P2VAR(uint8, AUTOMATIC,DCM_APPL_DATA) MemoryData);

extern FUNC(Dcm_ReturnWriteMemoryType, DCM_CALLOUT_CODE) Dcm_WriteMemory
  (Dcm_OpStatusType OpStatus,uint8 MemoryIdentifier,uint32 MemoryAddress,
    uint32 MemorySize, P2VAR(uint8, AUTOMATIC,DCM_APPL_DATA) pWriteData);

extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ProcessRequestDownload
  (Dcm_OpStatusType OpStatus,uint8 DataFormatIdentifier,uint32 MemoryAddress,
    uint32 MemorySize, P2VAR(uint32, AUTOMATIC, DCM_PRIVATE_DATA)LpBlockLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC,
        DCM_PRIVATE_DATA)LpNegativeErrorCode);

extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ProcessRequestUpload
  (Dcm_OpStatusType OpStatus,uint8 DataFormatIdentifier,uint32 MemoryAddress,
    uint32 MemorySize, P2VAR(uint32, AUTOMATIC, DCM_PRIVATE_DATA)LpBlockLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC,
        DCM_PRIVATE_DATA)LpNegativeErrorCode);
        
#define DCM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

#endif /* End DCM_CALLOUTS_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
