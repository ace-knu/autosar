/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: MemIf_Version.c                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR MemStack Integration Module                           **
**                                                                            **
**  PURPOSE   : Provision of Version information                              **
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
** 1.0.0     11-Jun-2015   SONG CY       Initial Version                      **
*******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "Mem_Integration.h"
#include "MemIf_Cfg.h"
#include "SchM_NvM.h"
#include "NvM.h"
#include "NvM_Ram.h"

#ifdef MEMIF_FLS_DRIVER_INDEX
#include "Fls.h"
#include "Fee.h"
#endif

#ifdef MEMIF_EEP_DRIVER_INDEX
#include "Ea.h"
#include "Eep.h"
#endif
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
uint8 ConfigIDRamBlock[2];

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define NVM_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Mem_Driver_StartUp                                  **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : Service for basic Memory Stack Initialization       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Eep_Init, Ea_Init             **
**                             Fls_17_Pmu_Init, Mem_FlsInitPerform, Fee_Init  **
**                             Mem_FeeInitPerform, NvM_Init, NvM_ReadAll      **
**                             Mem_Call_NvM_BITP                              **
*******************************************************************************/
FUNC(void, NVM_CODE) Mem_Driver_StartUp(void)
{
    #ifdef MEMIF_EEP_DRIVER_INDEX
    Eep_Init(NULL_PTR);
    Ea_Init();
    #endif
    #ifdef MEMIF_FLS_DRIVER_INDEX
    Fls_Init(&FlsConfigSet_0);
    Mem_FlsInitPerform();
    Fee_Init();
    Mem_FeeInitPerform();
    #endif
    NvM_Init();
    NvM_ReadAll();
    NvM_Call_NvM_BITP_MainFunction();
}
/*******************************************************************************
** Function Name        : Mem_Driver_ShutDown                                 **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : Service for WriteAll Perform                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : NvM_WriteAll,                 **
**                             Mem_Call_NvM_BITP                              **
*******************************************************************************/
FUNC(void, NVM_CODE) Mem_Driver_ShutDown(void)
{
    NvM_WriteAll();
    NvM_Call_NvM_BITP_MainFunction();
}
/*******************************************************************************
** Function Name        : Mem_FlsInitPerform                                  **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : Service for basic FLS Initialization                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Fls_GetStatus, Fls_MainFunction*
*******************************************************************************/
#ifdef MEMIF_FLS_DRIVER_INDEX
FUNC(void, NVM_CODE) Mem_FlsInitPerform(void)
{
    uint32 LulTimeOutIndex;
    LulTimeOutIndex=0;
    while((Fls_GetStatus() != MEMIF_IDLE)&&(LulTimeOutIndex<0xFFFF))
    {
        Fls_MainFunction();
        LulTimeOutIndex++;
    };
}
#endif
/*******************************************************************************
** Function Name        : Mem_FeeInitPerform                                  **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : Service for basic FEE Initialization                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Fee_GetStatus                 **
**                             Fls_MainFunction, Fee_MainFunctions            **
*******************************************************************************/
#ifdef MEMIF_FLS_DRIVER_INDEX
FUNC(void, NVM_CODE) Mem_FeeInitPerform(void)
{

    uint32 LulTimeOutIndex; 
    LulTimeOutIndex=0;
    while((Fee_GetStatus() != MEMIF_IDLE)&&(LulTimeOutIndex<0xFFFFFF))
    {
        Fls_MainFunction();
        Fee_MainFunction();
        LulTimeOutIndex++;
    };
}
#endif

/*******************************************************************************
** Function Name        : NvM_Call_NvM_BITP_MainFunction                      **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : Service for Call NvM Bsw Internal Trigger Point     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
*******************************************************************************/
FUNC(void, NVM_CODE) NvM_Call_NvM_BITP_MainFunction(void)
{
    SchM_ActMainFunction_NvM_BITP_CallCyclicMemFunction();
}

/*******************************************************************************
** Function Name        : NvM_Call_MemMainFunctions                           **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : Service for Call MemoryStack Mainfunction           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
*******************************************************************************/
FUNC(void, NVM_CODE) NvM_Call_MemMainFunctions(void)
{
    SchM_Switch_NvM_MemCyclicMode(RTE_MODE_MemCyclicMode_IDLEEXECUTE);

    do {
        #ifdef MEMIF_FLS_DRIVER_INDEX
        Fee_MainFunction();
        Fls_MainFunction();
        #endif
        #ifdef MEMIF_EEP_DRIVER_INDEX
        Ea_MainFunction();
        Eep_MainFunction();
        #endif
        NvM_MainFunction();
    } while (((NvM_GucReadAllRequest != NVM_MULTIBLK_UNREQUESTED)||
               (NvM_GucWriteAllRequest != NVM_MULTIBLK_UNREQUESTED)));

    SchM_Switch_NvM_MemCyclicMode(RTE_MODE_MemCyclicMode_TASKEXECUTE);
}

#define NVM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                         End of File                                        **
*******************************************************************************/
