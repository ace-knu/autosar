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
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By              Description                        **
********************************************************************************
** 1.0.9     18-04-2017    Jin     Jung    #8221                              **
**                                                                            **
** 1.0.8     30-03-2017    Jin     Jung    #7558                              **
**                                                                            **
** 1.0.7     21-02-2017    Jin     Jung    #6626 #6778 #7340                  **
**                                                                            **
** 1.0.6     01-11-2016    Jin     Jung    #5745                              **
**                                                                            **
** 1.0.5     27-07-2016    Jin     Jung    #5649                              **
**                                                                            **
** 1.0.4     17-06-2016    Jin     Jung    #5232                              **
**                                                                            **
** 1.0.3     24-05-2016    Jin     Jung    #4717 #4927 #4928                  **
**                                                                            **
** 1.0.2     05-05-2016    Jin     Jung    Modify DeliveryBox                 **
**                                                                            **
** 1.0.1     17-04-2014    YoungJin Yun    Dcm_SetProgConditions,             **
**                                         Dcm_SetProgConditions are updated  **
**                                                                            **
** 1.0.0     03-07-2013    Autron          Initial Version                    **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Dcm_CallOuts.h"
/* Use the FBL provided by AUTRON (Do not modify, if you use AUTRON FBL) */
#if (DCM_AUTRON_FBL_USED == STD_ON)
#include "Dcm_Callout_Fixed.h"
#include "Fbl_Stub.h"
#include "Fbl_Shared.h"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
*                       Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Dcm_ReadMemory                                      **
**                                                                            **
** Description          : The Dcm_ReadMemory callout is used to request memory**
**                        data identified by the parameter memoryAddress and  **
**                        memorySize from the UDS request message.            **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus, MemoryIdentifier(NotSupported),           **
**                        MemoryAddress, MemorySize                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : MemoryData                                          **
**                                                                            **
** Return parameter     : ReturnReadMemoryType                                **
**                        DCM_READ_OK: read was successful                    **
**                        DCM_READ_FAILED: read was not successful            **
**                        DCM_READ_PENDING: read is not yet finished          **
**                        DCM_READ_FORCE_RCRRP: reading is pending,           **
**                        the Response pending transmission starts immediately**
**                                                                            **
** Preconditions        : DCM module must be initialised                      **
*******************************************************************************/
#define DCM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
FUNC(Dcm_ReturnReadMemoryType, DCM_CALLOUT_CODE) Dcm_ReadMemory
/* polyspace<MISRA-C:5.6:Not a defect:Justify with annotations> OpStatus : AUTOSAR Standard */
  (Dcm_OpStatusType OpStatus,
  uint8 MemoryIdentifier /* Not Supported Argument */,
  uint32 MemoryAddress, uint32 MemorySize,
  P2VAR(uint8, AUTOMATIC,DCM_APPL_DATA) pMemoryData)
{
  Dcm_ReturnReadMemoryType RetVal = DCM_READ_FAILED;

  /* This code is just sample based on default setting about memory range ! */

  uint32 i = 0U;
  uint32 index = MemoryAddress;
 
  if((MemoryAddress <= 0x2109196CU) && (MemoryAddress >= 0x21091968U))
  {
    /* if MemoryAddress is 0x21091968 - 0x2109196C */
    RetVal = DCM_READ_OK;

    index = MemoryAddress - 0x21091968U;
    MemorySize = MemorySize + index;

    for(; index < MemorySize; index++, i++)
    {
      pMemoryData[i] = (uint8)index;
    }
  }
  
  /* The following lines of code is added to avoid compiler warning */

  DCM_UNUSED(OpStatus);
  /* MemoryIdentifier argument is not supported by Dcm */
  DCM_UNUSED(MemoryIdentifier);

  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_WriteMemory                                     **
**                                                                            **
** Description          : The Dcm_WriteMemory callout is used to write memory **
**                        data identified by the parameter memoryAddress and  **
**                        memorySize.                                         **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus, MemoryIdentifier(NotSupported),           **
**                        MemoryAddress, MemorySize, MemoryData               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : ReturnWriteMemoryType                               **
**                        DCM_WRITE_OK: write was successful                  **
**                        DCM_WRITE_FAILED: write was not successful          **
**                        DCM_WRITE_PENDING: write is not yet finished        **
**                        DCM_WRITE_FORCE_RCRRP: writing is pending,          **
**                        the Response pending transmission starts immediately**
**                                                                            **
** Preconditions        : DCM module must be initialised                      **
*******************************************************************************/
FUNC(Dcm_ReturnWriteMemoryType, DCM_CALLOUT_CODE) Dcm_WriteMemory
/* polyspace<MISRA-C:5.6:Not a defect:Justify with annotations> OpStatus : AUTOSAR Standard */
  (Dcm_OpStatusType OpStatus,
  uint8 MemoryIdentifier /* Not Supported Argument */,
  uint32 MemoryAddress, uint32 MemorySize,
  P2VAR(uint8, AUTOMATIC,DCM_APPL_DATA) pWriteData)
{
  Dcm_ReturnWriteMemoryType RetVal = DCM_WRITE_FAILED;

  /* This code is just sample based on default setting about memory range ! */
  
  uint32 i = 0U;
  uint32 index = MemoryAddress;
  uint8 dummyArray[5] = {0U, 0U, 0U, 0U, 0U};
  
  if((MemoryAddress <= 0x2048130EU) && (MemoryAddress >= 0x20481309U))
  {
    /* if MemoryAddress is 0x20481309 - 0x2048130E */
    RetVal = DCM_WRITE_OK;

    index = MemoryAddress - 0x20481309U;
    MemorySize = MemorySize + index;
    for(; index < MemorySize; index++,i++)
    {
      dummyArray[i] = pWriteData[i];
    }
  }

  /* Callout shall be filled by the system designer
  The following lines of code is added to avoid compiler warning */

  DCM_UNUSED(OpStatus);
  DCM_UNUSED_PTR(dummyArray);
  /* MemoryIdentifier argument is not supported by Dcm */
  DCM_UNUSED(MemoryIdentifier);

  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_GetProgConditions                               **
**                                                                            **
** Description          : The Dcm_GetProgConditions callout is called upon Dcm**
**                        initialization and allows to determine if a response**
**                        ($50 or $51) has to be sent. The context parameter  **
**                        are defined in Dcm_ProgConditionsType.              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : ProgConditions : Conditions on which the jump from  **
**                                         the bootloader has been requested  **
**                                                                            **
** Return parameter     : Dcm_EcuStartModeType                                **
**                        DCM_COLD_START : The ECU starts normally            **
**                        DCM_WARM_START : The ECU starts from a bootloader   **
**                                         jump                               **
*******************************************************************************/
FUNC(Dcm_EcuStartModeType, DCM_CALLOUT_CODE) Dcm_GetProgConditions
  (P2VAR(Dcm_ProgConditionsType, AUTOMATIC,DCM_APPL_DATA) ProgConditions)
{
  Dcm_EcuStartModeType StartMode = DCM_COLD_START;

  /*
   * Callout shall be filled by the system designer
   * The following lines of code is added to avoid compiler warning
   */

  /* Use the FBL provided by AUTRON (Do not modify, if you use AUTRON FBL) */
  #if(DCM_AUTRON_FBL_USED == STD_ON)
  StartMode = Dcm_Internal_GetProgConditions(ProgConditions);
  #endif

  return StartMode;
}

/*******************************************************************************
** Function Name        : Dcm_SetProgConditions                               **
**                                                                            **
** Description          : The Dcm_SetProgConditions callout allows the        **
**                        integrator to store relevant information prior to   **
**                        jumping to bootloader/jump due to ECUReset request. **
**                        The context parameter are defined                   **
**                        in Dcm_ProgConditionsType.                          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ProgConditions : Conditions on which the jump to    **
**                                         bootloader has been requested      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                        E_OK: Transfer was successful                       **
**                        E_NOT_OK: Transfer was not successful               **
**                        DCM_E_PENDING: Transfer is not yet finished         **
*******************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_SetProgConditions
  (P2CONST(Dcm_ProgConditionsType, AUTOMATIC,DCM_APPL_DATA) ProgConditions)
{
  Std_ReturnType RetVal = E_NOT_OK;

 /*
  * Callout shall be filled by the system designer
  * The following lines of code is added to avoid compiler warning
  */

  /* Use the FBL provided by AUTRON (Do not modify, if you use AUTRON FBL) */
  #if(DCM_AUTRON_FBL_USED == STD_ON)
  RetVal = Dcm_Internal_SetProgConditions(ProgConditions);
  #endif

  return RetVal;
}

#ifdef DcmConf_DcmDspSecurityRow_L21
/*******************************************************************************
** Function Name        : Dcm_GetRandomSeed                                   **
**                                                                            **
** Description          : This function is used to update the RandomSeed used **
**                        in the C-SAC algorithm.                             **
**                                                                            **
** Precondition         : Use a SecurityLeveL L21 (CSAC)                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : RandomSeed : RandomSeed To be applied to the C-SAC  **
**                                     platform                               **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                        E_OK: RandomSeed is valid                           **
**                              Apply user randomseed in platform             **
**                        E_NOT_OK: RandomSeed is invalid                     **
*******************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_GetRandomSeed
  (P2VAR(uint8, AUTOMATIC,DCM_APPL_DATA) RandomSeed)
{
  Std_ReturnType RetVal = E_NOT_OK;

 /*
  * Apply user RandomSeed to the argument in this callout function.
  * RandomSeed is a 16-row array. (RandomSeed[16])
  */
  
 /*
  * If you apply RandomSeed, you must return E_OK.
  * E_OK : Use the user RandomSeed
  * E_NOT_OK : Use the Autron RandomSeed
  */

  return RetVal;
}

/*******************************************************************************
** Function Name        : Dcm_GetPublicKey                                    **
**                                                                            **
** Description          : This function is used to update the RandomSeed used **
**                        in the C-SAC algorithm.                             **
**                                                                            **
** Precondition         : Use a SecurityLeveL L21 (CSAC) &&                   **
**                        Do not use the Autron Fbl                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : PublicKey : Public key                              **
**                                    for certificate authentication          **
**                                                                            **
** Return parameter     : none                                                **
*******************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_GetPublicKey
  (P2VAR(uint8, AUTOMATIC,DCM_APPL_DATA) PublicKey)
{
  /* Do not consider return value in this function */

  #if(DCM_AUTRON_FBL_USED == STD_ON)
  /*
   * Autron Fbl Public Key Used.
   * If you want to use your public key, delete this code.
   */
  T_BAIFT *ls_baift = (T_BAIFT *)&cas_FBL_BAIFT;
  uint16 LulIndex = 0U;

  /* Copy Fbl public key to the dcm */
  for( ; LulIndex < 256U; LulIndex++)
  {
    PublicKey[LulIndex] = ((const uint8*)ls_baift->pcs_Pubkey)[LulIndex];
  }
  #endif
  /*
   * PublicKey Size is 256-bytes.
   * PublicKey[256] shall be initialized.
   * Refer to ES95489 and assign your public key for C-SAC.
   */
}
#endif

#define DCM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
