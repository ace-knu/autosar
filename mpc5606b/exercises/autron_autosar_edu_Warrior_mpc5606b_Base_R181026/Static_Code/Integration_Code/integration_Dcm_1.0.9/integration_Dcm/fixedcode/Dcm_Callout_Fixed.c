/*******************************************************************************
**  (C) 2012 HYUNDAI AUTRON Company                                           **
**  Confidential Proprietary Information Distribution Limited                 **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**                                                                            **
**  SRC-MODULE: Dcm_Callout_User.c                                            **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : This file contains the API definitions for Dsl layer of Dcm,  **
**              Initialization and scheduler functions of Dcm module          **
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
** 1.0.1     29-03.2017    Jin      Jung   #7558, #7977                       **
**                                                                            **
** 1.0.0     20-02-2017    Autron          Initial Version                    **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Dcm_CallOuts.h"
/* Use the FBL provided by AUTRON (Do not modify, if you use AUTRON FBL) */
#if (DCM_AUTRON_FBL_USED == STD_ON)
#include "Dcm_Callout_Fixed.h"
#include "Fbl_Stub.h"

/*******************************************************************************
**                      Dcm_Internal_GetProgCondition()                       **
*******************************************************************************/
#define DCM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(Dcm_EcuStartModeType, DCM_CALLOUT_CODE) Dcm_Internal_GetProgConditions
  (P2VAR(Dcm_ProgConditionsType, AUTOMATIC,DCM_APPL_DATA) ProgConditions)
{
  Dcm_EcuStartModeType StartMode = DCM_COLD_START;
  P2VAR(Dcm_McuDepProgConditionsType, AUTOMATIC,DCM_APPL_DATA)
  bcore_ProgConditions = (Dcm_McuDepProgConditionsType*)bcore_GetProgConditions();

  /* ApplUpdated is cleared in the Dcm_Init() */
  ProgConditions->ApplUpdated = bcore_ProgConditions->ApplUpdated;
  /* ResponseRequired is cleared in the Dcm_MainFunction() */
  ProgConditions->ResponseRequired = bcore_ProgConditions->ResponseRequired;
  
  if(DCM_TRUE == bcore_ProgConditions->ApplUpdated)
  {
    /* Update return value */
    StartMode = DCM_WARM_START;
  }
  else
  {
    /* Do Nothing */
  }

  if(DCM_TRUE == bcore_ProgConditions->ResponseRequired)
  {
    ProgConditions->ProtocolId          = bcore_ProgConditions->ProtocolId;
    ProgConditions->TesterSourceAddr    = bcore_ProgConditions->TesterSourceAddr;
    ProgConditions->Sid                 = bcore_ProgConditions->Sid;
    ProgConditions->SubFncId            = bcore_ProgConditions->SubFncId;
  }
  else
  {
    ProgConditions->ProtocolId          = (uint8)0x00;
    ProgConditions->TesterSourceAddr    = (uint16)0x00;
    ProgConditions->Sid                 = (uint8)0x00;
    ProgConditions->SubFncId            = (uint8)0x00;
  }

  ProgConditions->SecLvInfo = (uint8)0x00;
  ProgConditions->ReprogramingRequest = (boolean)0x00;

  return StartMode;
}

/*******************************************************************************
**                      Dcm_Internal_SetProgConditions()                      **
*******************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Internal_SetProgConditions
  (P2CONST(Dcm_ProgConditionsType, AUTOMATIC,DCM_APPL_DATA) ProgConditions)
{
  Std_ReturnType RetVal = E_NOT_OK;
  P2VAR(Dcm_McuDepProgConditionsType, AUTOMATIC,DCM_APPL_DATA)
  bcore_ProgConditions = (Dcm_McuDepProgConditionsType*) bcore_GetProgConditions();

  if(NULL_PTR != ProgConditions)
  {
    if(ProgConditions->ReprogramingRequest == DCM_TRUE)
    {
      bcore_ProgConditions->ProtocolId          = ProgConditions->ProtocolId;
      bcore_ProgConditions->TesterSourceAddr    = ProgConditions->TesterSourceAddr;
      bcore_ProgConditions->Sid                 = ProgConditions->Sid;
      bcore_ProgConditions->SubFncId            = ProgConditions->SubFncId;
      bcore_ProgConditions->ReprogramingRequest = ProgConditions->ReprogramingRequest;
      bcore_ProgConditions->ApplUpdated         = ProgConditions->ApplUpdated;
      bcore_ProgConditions->ResponseRequired    = ProgConditions->ResponseRequired;
      bcore_ProgConditions->SecLvInfo           = ProgConditions->SecLvInfo;

      bcore_SetStartupCommand(RESTART_BOOT_DIAG);
      RetVal = E_OK;
    }
    else 
    { 
      bcore_ProgConditions->ProtocolId          = (uint8)0x00;
      bcore_ProgConditions->TesterSourceAddr    = (uint16)0x00;
      bcore_ProgConditions->Sid                 = (uint8)0x00;
      bcore_ProgConditions->SubFncId            = (uint8)0x00;
      bcore_ProgConditions->ReprogramingRequest = (boolean)0x00;
      bcore_ProgConditions->ApplUpdated         = (boolean)0x00;
      bcore_ProgConditions->ResponseRequired    = (boolean)0x00;
      bcore_ProgConditions->SecLvInfo           = (uint8)0x00;

      bcore_SetStartupCommand(DCM_FALSE);
    }
  }
  else
  {
    /* return E_NOT_OK */
  }

  return RetVal;
}
#define DCM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

#endif
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
