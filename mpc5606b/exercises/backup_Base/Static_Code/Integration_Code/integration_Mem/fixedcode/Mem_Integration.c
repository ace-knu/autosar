/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Mem_Integration.c                                             **
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
**                     Include Section                                        **
*******************************************************************************/
#include "Os.h"
#include "Mem_Integration.h" /* NvM.h */
#include "MemIf_Cfg.h"
#include "SchM_NvM.h"
#include "NvM.h"
#include "NvM_Ram.h"
#include "NvM_Config.h"

#if(NVM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#if (MEM_FLS_USED == STD_ON)
#include "Fls.h"
#endif

#if (MEM_FEE_USED == STD_ON)
#include "Fee.h"
#endif

#if (MEM_EA_USED == STD_ON)
#include "Ea.h"
#include "Eep.h"
#include "SchM_Eep.h"
#endif

#if(NVM_DRV_MODE_SWITCH == STD_OFF)
#error "1 NvMDrvModeSwitch should be true."
#error "2 FlsDefaultMode should be configured as MEMIF_MODE_FAST"
#error "3 FlsSetModeApi should be true."
#error "4 FeeSetModeSupported should be true."
#error "5 EepDefaultMode should be configured as MEMIF_MODE_FAST"
#error "6 EaSetModeSupported should be true."
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
uint8 ConfigIDRamBlock[2];
boolean Mem_InvertMainFunctionSeq = NVM_FALSE;

#if (HWRESOURCE_VENDOR(HWRESOURCE_INFINEON))
extern FUNC(void, NVM_CODE) Fee_IllegalStateNotification (void);
extern void Fee_IllegalStateCallback (void);
#endif

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
    #if (MEM_EA_USED == STD_ON)
    Eep_Init(NULL_PTR);
    Ea_Init();
    #endif
    
    #if (MEM_FLS_USED == STD_ON)    
    Mem_FlsInitPerform();       
    #endif

    #if (MEM_FEE_USED == STD_ON)      
    Mem_FeeInitPerform();
    #endif
    
    #ifdef NVM_GPT_CHANNEL_ID
    Gpt_EnableNotification(NvM_GddGptChannel);
    #endif

    /* Reset the task sequence control variable */    
    Mem_InvertMainFunctionSeq = NVM_FALSE;
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
    /* Reset the task sequence control variable */    
    Mem_InvertMainFunctionSeq = NVM_FALSE;    
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
#if (MEM_FLS_USED == STD_ON) 
FUNC(void, NVM_CODE) Mem_FlsInitPerform(void)
{
  uint32 timeOut = 0xFFFFU;

  /* Infineon aurix family */
  #if HWRESOURCE_VENDOR(HWRESOURCE_INFINEON)
  Fls_17_Pmu_Init(&Fls_17_Pmu_ConfigRoot[0]);

  /* Freescale(NXP) or ST mpc family */
  #elif (HWRESOURCE_VENDOR(HWRESOURCE_FREESCALE) || HWRESOURCE_VENDOR(HWRESOURCE_ST))
  Fls_Init(&FlsConfigSet_0);

  /* Cypress traveo family */
  #elif HWRESOURCE_VENDOR(HWRESOURCE_CYPRESS)
  Fls_Init(NULL_PTR);
  
  #else
  #error "MCU is not supported yet"
  #endif     
  
  while( (Fls_GetStatus() != MEMIF_IDLE) && (timeOut > 0U) )
  {
    Fls_MainFunction();
    timeOut--;
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
#if (MEM_FEE_USED == STD_ON)
FUNC(void, NVM_CODE) Mem_FeeInitPerform(void)
{
  uint8 triggerRetry = 0U;  
  
  Fee_Init();
  do {
    uint32 timeout = 0xFFFFFFUL;
    
    while
    (
      (Fee_GetStatus() != MEMIF_IDLE)
      #if HWRESOURCE_VENDOR(HWRESOURCE_CYPRESS)    
      && (Fee_GetStatus() != MEMIF_UNINIT)
      #endif
      && (timeout > 0U)
    )
    {
      #if (MEM_FLS_USED == STD_ON) 
      Fls_MainFunction();
      #endif
      
      Fee_MainFunction();
      timeout--;
    };

    /* #if HWRESOURCE_VENDOR(HWRESOURCE_CYPRESS) */
    if (MEMIF_UNINIT == Fee_GetStatus())
    {
      triggerRetry = Mem_ExceptionHandlerOnFeeInitFail();
    }    
    /* #endif */
    
  } while(triggerRetry > 0U);

  /* On ReadAll/WriteAll : mode will be changed from slow to fast */
  Fee_SetMode (MEMIF_MODE_SLOW);
}
#endif

/*******************************************************************************
** Function Name        : NvM_Call_NvM_BITP_MainFunction                      **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : Service for Call NvM Bsw Internal Trigger Point     **
**                        by Mem_Driver_StartUp or GPT.                       **
**                        Refer to GPT_CHANNELCONFIG_DEFAULT.                 **
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
  TaskStateType taskState = RUNNING;  
  StatusType result = GetTaskState(OsTask_BSW_Mem_Process, &taskState);

  /* Note : Since this function runs within the interrupt(GPT), 
   *        no critical section is required 
   *
   * SUSPENDED : Task is terminated */
  if ( ((TaskStateType)SUSPENDED == taskState)&& (E_OK == result) )
  {
    /* Activate Activate OsTask_BSW_Mem_Process 
     *
     * 1. GPT(or RealAll/WriteAll) invokes NvM_Call_NvM_BITP_MainFunction 
     * 2. NvM_Call_NvM_BITP_MainFunction activates OsTask_BSW_Mem_Process
     * 3. OsTask_BSW_Mem_Process invokes NvM_Call_MemMainFunctions
     */
    if (SCHM_E_LIMIT == SchM_ActMainFunction_NvM_BITP_CallCyclicMemFunction())
    {   
      /* The function NvM_Call_NvM_BITP_MainFunction is always invoked by GPT*/
      MEM_START_ONE_SHOT_TIMER();
      MEM_REPORT_ERROR(NVM_MAINFUNCTION_SID, NVM_E_PARAM_DATA);
    }
  }
  else
  {
    MEM_START_ONE_SHOT_TIMER();
  }
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
** Remarks              : This function is invoked by GPT or Dem(Not used GPT)**
**                        or EcuM(Mem_Driver_ShutDown).                       **
**                        NvM_WriteAll(Mem_Driver_ShutDown) and               **
**                        Dem_WriteNvData can not be used together            **
*******************************************************************************/
FUNC(void, NVM_CODE) NvM_Call_MemMainFunctions(void)
{  
  /* Disable NvM_MainFunction to run at OsTask_BSW_FG1_5ms_Mem  
   * The initial value of the MemCyclicMode is NONEEEXECUTE */
  if (SCHM_E_LIMIT == SchM_Switch_NvM_MemCyclicMode(RTE_MODE_MemCyclicMode_IDLEEXECUTE))
  {    
    MEM_REPORT_ERROR(NVM_MAINFUNCTION_SID, NVM_E_PARAM_DATA);/* Invalid configuration */
  }
  /* Sequence of the tasks
   * NvM->Fee->Fls->Ea->Eep ---> Fls->Fee->Eep->Ea->NvM 
   */
  if (MEM_TRIGGER_RUN_2MF()) 
  {
    NvM_MainFunction(); /* Request to ReadAll/WriteAll */
    NvM_MainFunction(); /* Initialize the block */
  }  
  
  do
  {
    if (NVM_FALSE == Mem_InvertMainFunctionSeq)
    {
      NvM_MainFunction();        
      #if (MEM_FEE_USED == STD_ON)
      Fee_MainFunction();
      #endif
      #if (MEM_FLS_USED == STD_ON)
      Fls_MainFunction();
      #endif 
      #if (MEM_EA_USED == STD_ON)
      Ea_MainFunction();        
      Eep_MainFunction();
      #endif
    }
    else
    {        
      #if (MEM_FLS_USED == STD_ON)
      Fls_MainFunction();
      #endif        
      #if (MEM_FEE_USED == STD_ON)
      Fee_MainFunction();
      #endif        
      #if (MEM_EA_USED == STD_ON)
      Eep_MainFunction();        
      Ea_MainFunction();
      #endif        
      NvM_MainFunction(); 
    }
    Mem_InvertMainFunctionSeq = !Mem_InvertMainFunctionSeq;
  } 
  while (MEM_TRIGGER_LOOP());
    
  /* 
   * When ReadAll/WriteAll is completed, Fls device mode will be changed as MEMIF_MODE_SLOW 
   */

  #ifdef NVM_GPT_CHANNEL_ID
  if (MEM_TRIGGER_GPT()) 
  {
    /* NvM_Call_MemMainFunctions will be invoked */
    MEM_START_ONE_SHOT_TIMER();
  }
  else
  #endif
  {
    /* Reset the task sequence control variable */    
    Mem_InvertMainFunctionSeq = NVM_FALSE; 
    
    /* Refer to Rte.c : TASK(OsTask_BSW_FG1_5ms_Mem)
     * TASK(OsTask_BSW_FG1_5ms_Mem)
     * {
     *   if((MemCyclicMode != IDLEEXECUTE) && (MemCyclicMode != NONEEEXECUTE))
     *   {
     *     NvM_MainFunction();
     *   }
     * }
     *
     * In case GPT fails, enable a OsTask_BSW_FG1_5ms_Mem */
    if (SCHM_E_LIMIT == SchM_Switch_NvM_MemCyclicMode(RTE_MODE_MemCyclicMode_TASKEXECUTE))
    {    
      MEM_REPORT_ERROR(NVM_MAINFUNCTION_SID, NVM_E_PARAM_DATA);/* Invalid configuration */
    }  
  }
}

/*******************************************************************************
** Function Name        : Fee_IllegalStateNotification                        **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Aurix Fee IllegalStateNotification                  **
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
#if (HWRESOURCE_VENDOR(HWRESOURCE_INFINEON))
FUNC(void, NVM_CODE) Fee_IllegalStateNotification (void)
{
  /* Indicate job is completed with error */
  NvM_GddJobResultLowLevel = NVM_REQ_NOT_OK;
  /* Because application user could modify Fee_IllegalStateCallback function, */
  /* it is in App_FeeIllegalCbk.c file */
  Fee_IllegalStateCallback();
}
#endif

#define NVM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                         End of File                                        **
*******************************************************************************/
