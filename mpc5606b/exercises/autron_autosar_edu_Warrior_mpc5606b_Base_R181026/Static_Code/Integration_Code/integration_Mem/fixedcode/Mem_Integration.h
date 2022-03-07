/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Mem_Integration.h                                             **
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

#ifndef MEMDRIVERINIT_H_
#define MEMDRIVERINIT_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "NvM.h"
#include "HwResource.h"
#include "MemIf_Cfg.h"
#include "Mem_Integration_User.h"

#ifdef NVM_GPT_CHANNEL_ID
#include "Gpt.h"
#endif

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/
#ifdef MEMIF_FLS_DRIVER_INDEX
  #define MEM_FEE_USED          (STD_ON)     

  #if ((HWRESOURCE_GET_MCU() != HWRESOURCE_RH850F1H) && \
       (HWRESOURCE_GET_MCU() != HWRESOURCE_RH850F1L) && \
       (HWRESOURCE_GET_MCU() != HWRESOURCE_RH850F1K))
    #define MEM_FLS_USED          (STD_ON)     
  #else
    /* in case of RH850, Fls is not used but the specific library of the renesas 
     * is included int the Fee */     
    #define MEM_FLS_USED          (STD_OFF)
  #endif
#else 
  /* FEE is not configured */
  #define MEM_FEE_USED          (STD_OFF)   
  /* FLS is not configured */
  #define MEM_FLS_USED          (STD_OFF)
#endif

#ifdef MEMIF_EEP_DRIVER_INDEX
#define MEM_EA_USED          (STD_ON)
#else
#define MEM_EA_USED          (STD_OFF)
#endif

#ifdef NVM_GPT_CHANNEL_ID
#define MEM_START_ONE_SHOT_TIMER() \
do {\
  Gpt_DisableNotification(NvM_GddGptChannel);\
  Gpt_StopTimer(NvM_GddGptChannel);\
  Gpt_EnableNotification(NvM_GddGptChannel);\
  Gpt_StartTimer(NvM_GddGptChannel, NvM_GddGptValue);\
} while(0)

#else
#define MEM_START_ONE_SHOT_TIMER() do {} while(0)
#endif

#if (NVM_DEV_ERROR_DETECT == STD_ON)
#define MEM_REPORT_ERROR(sid,error) \
do {\
  (void)Det_ReportError(NVM_MODULE_ID, NVM_INSTANCE_ID, (sid), (error));\
} while(0)
#else
#define MEM_REPORT_ERROR(sid,error)  do {} while(0)
#endif /* end of DET */


#define MEM_TRIGGER_READALL       (NVM_MULTIBLK_UNREQUESTED != NvM_GucReadAllRequest)
#define MEM_TRIGGER_WRITEALL      (NVM_MULTIBLK_UNREQUESTED != NvM_GucWriteAllRequest)
#define MEM_TRIGGER_DEM           (Dem_NvmWaitFinishJobIsTrigger() == DEM_TRUE)

/* using while-loop during writeAll */   
#if (MEM_WRITEALL_FAST_MODE == STD_ON) 
  /* When Dem_WriteNvData is called, NvM_WriteBlock is run.
   * So it is not necessary to invoke logic that calls NvM_MainFunction twice */
  #define MEM_TRIGGER_RUN_2MF()    ((MEM_TRIGGER_READALL) || (MEM_TRIGGER_WRITEALL))
  
  #ifdef NVM_GPT_CHANNEL_ID
    /* e.g. NvM_ReadBlock, NvM_WriteBlock... */
    #define MEM_TRIGGER_GPT()     (NVM_IDLE != NvM_GucState) 
    /* When GPT is used , Dem_WriteNvData don't invoke OsTask_BSW_Mem_Process */
    #define MEM_TRIGGER_LOOP()    ((MEM_TRIGGER_READALL) || (MEM_TRIGGER_WRITEALL))
  #else
    #define MEM_TRIGGER_GPT()     (0) /* Not used */
    /* Dem: backward compatibility */
    #include "Dem_EventMemory.h"
    #define MEM_TRIGGER_LOOP()    ((MEM_TRIGGER_READALL) ||  (MEM_TRIGGER_WRITEALL) || (MEM_TRIGGER_DEM)) 
  #endif
/* not used fast mode during writeAll, GPT or periodic task is used instead of while-loop  */   
#else
  #define MEM_TRIGGER_RUN_2MF()   (MEM_TRIGGER_READALL) /* only ReadAll */
  #define MEM_TRIGGER_LOOP()      (MEM_TRIGGER_READALL)
  #ifdef NVM_GPT_CHANNEL_ID
    /* When Dem_WriteNvData is invoked, Dem_NvmWaitFinishJobIsTrigger() do not need to be verified
     * because NvM_GucState is changed to non-idle. */
    #define MEM_TRIGGER_GPT()     ((NVM_IDLE != NvM_GucState) || (MEM_TRIGGER_WRITEALL))
  #else
    #define MEM_TRIGGER_GPT()     (0) /* Not used */
  #endif  
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
extern uint8 ConfigIDRamBlock[2];

/*******************************************************************************
**                       Function Prototypes                                  **
*******************************************************************************/
#define NVM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, NVM_CODE) Mem_Driver_StartUp(void);
extern FUNC(void, NVM_CODE) Mem_FlsInitPerform(void);
extern FUNC(void, NVM_CODE) Mem_FeeInitPerform(void);
extern FUNC(void, NVM_CODE) Mem_Driver_ShutDown(void);
extern FUNC(void, NVM_CODE) NvM_Call_NvM_BITP_MainFunction(void);
#define NVM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* MEMDRIVERINIT_H_ */
