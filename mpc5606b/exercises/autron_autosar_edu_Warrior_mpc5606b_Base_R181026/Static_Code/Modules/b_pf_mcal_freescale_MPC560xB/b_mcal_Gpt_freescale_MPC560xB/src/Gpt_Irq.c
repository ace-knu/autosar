/**
*   @file    Gpt_Irq.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - GPT driver source file.
*   @details GPT driver source file, containing the C implementation of functions prototypes that:
*            - are Autosar specific and are not exported by the GPT driver.
*            - are not related to the GPT driver related IPs.    
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS_Stm_Pit_Rtc
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20140606
*
*   (c) Copyright 2006-2014 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*=================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section GPT_IRQ_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section GPT_IRQ_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_IRQ_C_REF_3
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* This violation is due to the use of pointer arithmatic, which is used for the speed optimization,
* the indexing of the pointer is taken care and hence the unintended memory location will not be
* accessed.
*
* @section GPT_IRQ_C_REF_4
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* The cast is used to address memory mapped registers or other hw resources.
*
* @section GPT_IRQ_C_REF_5
* Violates MISRA 2004 Required Rule 10.5, Shift left of signed quantity(int)
* This rule can not be avoided because it appears when addressing memory mapped registers
* or other hardware specific feature.
*
* @section GPT_IRQ_C_REF_6
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
* @section GPT_IRQ_C_REF_7
* Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope
* If a variable to be used within a Function in the same file use Static.Similarly if a function is called 
* from elsewhere within the same file use Static.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Gpt_Irq.c
* @requirements   BSW00374, BSW00318
* @implements     DGPT03902, DGPT03400
*/
#include "Gpt.h"
#include "Gpt_LLD.h"
#include "Reg_eSys_eMIOS.h"
#include "Reg_eSys_Stm.h"
#include "Reg_eSys_Pit.h"
#include "Reg_eSys_Rtc.h"
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @brief   Source file version information
* @requirements BSW00374, BSW00379, BSW00318
*/
#define GPT_IRQ_VENDOR_ID                           43
/* @violates @ref GPT_IRQ_C_REF_6 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_IRQ_AR_RELEASE_MAJOR_VERSION_C          4
/* @violates @ref GPT_IRQ_C_REF_6 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_IRQ_AR_RELEASE_MINOR_VERSION_C          0
/* @violates @ref GPT_IRQ_C_REF_6 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_IRQ_AR_RELEASE_REVISION_VERSION_C       3
#define GPT_IRQ_SW_MAJOR_VERSION_C                  1
#define GPT_IRQ_SW_MINOR_VERSION_C                  0
#define GPT_IRQ_SW_PATCH_VERSION_C                  1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (GPT_IRQ_VENDOR_ID != GPT_VENDOR_ID)
    #error "Gpt_Irq.c and Gpt.h have different vendor ids"
#endif
#if ((GPT_IRQ_AR_RELEASE_MAJOR_VERSION_C != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IRQ_AR_RELEASE_MINOR_VERSION_C != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IRQ_AR_RELEASE_REVISION_VERSION_C != GPT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Irq.c and Gpt.h are different"
#endif
#if ((GPT_IRQ_SW_MAJOR_VERSION_C != GPT_SW_MAJOR_VERSION) || \
     (GPT_IRQ_SW_MINOR_VERSION_C != GPT_SW_MINOR_VERSION) || \
     (GPT_IRQ_SW_PATCH_VERSION_C != GPT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Irq.c and Gpt.h are different"
#endif

#if (GPT_IRQ_VENDOR_ID != GPT_LLD_VENDOR_ID)
    #error "Gpt_Irq.c and Gpt_LLD.h have different vendor ids"
#endif
#if ((GPT_IRQ_AR_RELEASE_MAJOR_VERSION_C != GPT_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IRQ_AR_RELEASE_MINOR_VERSION_C != GPT_LLD_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IRQ_AR_RELEASE_REVISION_VERSION_C != GPT_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Irq.c and Gpt_LLD.h are different"
#endif
#if ((GPT_IRQ_SW_MAJOR_VERSION_C != GPT_LLD_SW_MAJOR_VERSION) || \
     (GPT_IRQ_SW_MINOR_VERSION_C != GPT_LLD_SW_MINOR_VERSION) || \
     (GPT_IRQ_SW_PATCH_VERSION_C != GPT_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Irq.c and Gpt_LLD.h are different"
#endif

#if (GPT_IRQ_VENDOR_ID != REG_ESYS_EMIOS_H_VENDOR_ID)
    #error "Gpt_Irq.c and Reg_eSys_eMIOS.h have different vendor ids"
#endif
#if ((GPT_IRQ_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_EMIOS_H_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IRQ_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_EMIOS_H_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IRQ_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_EMIOS_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Irq.c and Reg_eSys_eMIOS.h are different"
#endif
#if ((GPT_IRQ_SW_MAJOR_VERSION_C != REG_ESYS_EMIOS_H_SW_MAJOR_VERSION) || \
     (GPT_IRQ_SW_MINOR_VERSION_C != REG_ESYS_EMIOS_H_SW_MINOR_VERSION) || \
     (GPT_IRQ_SW_PATCH_VERSION_C != REG_ESYS_EMIOS_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Irq.c and Reg_eSys_eMIOS.h are different"
#endif

#if (GPT_IRQ_VENDOR_ID != REG_ESYS_STM_VENDOR_ID)
    #error "Gpt_Irq.c and Reg_eSys_Stm.h have different vendor ids"
#endif
#if ((GPT_IRQ_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_STM_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IRQ_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_STM_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IRQ_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_STM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Irq.c and Reg_eSys_Stm.h are different"
#endif
#if ((GPT_IRQ_SW_MAJOR_VERSION_C != REG_ESYS_STM_SW_MAJOR_VERSION) || \
     (GPT_IRQ_SW_MINOR_VERSION_C != REG_ESYS_STM_SW_MINOR_VERSION) || \
     (GPT_IRQ_SW_PATCH_VERSION_C != REG_ESYS_STM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Irq.c and Reg_eSys_Stm.h are different"
#endif

#if (GPT_IRQ_VENDOR_ID != REG_ESYS_PIT_VENDOR_ID)
    #error "Gpt_Irq.c and Reg_eSys_Pit.h have different vendor ids"
#endif
#if ((GPT_IRQ_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_PIT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IRQ_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_PIT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IRQ_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_PIT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Irq.c and Reg_eSys_Pit.h are different"
#endif
#if ((GPT_IRQ_SW_MAJOR_VERSION_C != REG_ESYS_PIT_SW_MAJOR_VERSION) || \
     (GPT_IRQ_SW_MINOR_VERSION_C != REG_ESYS_PIT_SW_MINOR_VERSION) || \
     (GPT_IRQ_SW_PATCH_VERSION_C != REG_ESYS_PIT_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_Irq.c and Reg_eSys_Pit.h are different"
#endif

#if (GPT_IRQ_VENDOR_ID != REG_ESYS_RTC_VENDOR_ID)
    #error "Gpt_Irq.c and  Reg_eSys_Rtc.h have different vendor ids"
#endif
#if ((GPT_IRQ_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_RTC_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IRQ_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_RTC_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IRQ_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_RTC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Irq.c and Reg_eSys_Rtc.h are different"
#endif
#if ((GPT_IRQ_SW_MAJOR_VERSION_C != REG_ESYS_RTC_SW_MAJOR_VERSION) || \
     (GPT_IRQ_SW_MINOR_VERSION_C != REG_ESYS_RTC_SW_MINOR_VERSION) || \
     (GPT_IRQ_SW_PATCH_VERSION_C != REG_ESYS_RTC_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_Irq.c and Reg_eSys_Rtc.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define GPT_START_SEC_CODE
/* @violates @ref GPT_IRQ_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

/*=================================================================================================
*                                       GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief   EMIOS_Gpt_LLD_ProcessInterrupt.
* @details Non-AutoSar support function used by interrupt service routines to call notification 
*         functions if provided and enabled
*    
* @param[in]     hwChannel      hardware channel index
*
* @implements   DGPT03403
*/
/* @violates @ref GPT_IRQ_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Gpt_eMIOS_LLD_ProcessInterrupt(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel)
{
    P2CONST(Gpt_LLD_ChannelConfigType, AUTOMATIC, GPT_APPL_CONST) tempPtr;
    VAR(uint8, AUTOMATIC) LogicChannel;
    VAR(Gpt_ChannelType, AUTOMATIC) mIdx;   /** @brief assigned eMIOS HW module  index */
    VAR(Gpt_ChannelType, AUTOMATIC) chIdx;  /** @brief assigned eMIOS HW channel index */

    mIdx  = (uint8)((uint8)hwChannel >> (uint8)5U);
    chIdx = (uint8)((uint8)hwChannel &  (uint8)0x1FU);

    LogicChannel = GPT_LLD_EMIOS_HardwareMap[hwChannel];
    if (((uint8)0xffu != LogicChannel) && (NULL_PTR != Gpt_Cfg_Ptr))
    {
        /* Find hardware channel number in global GPT initialization structure */
        /* using Hardware Map Array */
        /* @violates @ref GPT_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        tempPtr = &Gpt_LLD_ChannelConfigPtr[LogicChannel];

        /* Timer_flag_clear(hwChannel); */
        /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
        REG_WRITE32(EMIOS_CSR(mIdx, chIdx), CSR_FLAG_BIT);

        /* If channel mode is one-shot, stop the channel and disable interrupts */
        if (GPT_CH_MODE_ONESHOT == (tempPtr->Gpt_ChannelMode))
        {
            /* Timer_gpio_input_mode(hwChannel); */
        /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
            REG_RMW32(EMIOS_CCR(mIdx, chIdx), (CCR_MODE_MASK|CCR_EDSEL_MASK), (CCR_MODE_GPI|CCR_EDSEL_MASK));

            /* Disable Interrupts */
            /* @violates @ref GPT_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
            REG_BIT_CLEAR32(EMIOS_CCR(mIdx, chIdx), CCR_FEN_MASK);
            Gpt_ChannelStatus[LogicChannel] = GPT_STATUS_EXPIRED;
        }
        /* Check if a notification exists for the channel */
        if (GPT_NOTIFICATION_DISABLED != GPT_GET_NOTIFICATION(LogicChannel))
        {
            tempPtr->Gpt_Notification();
        }
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
        if ((GPT_MODE_SLEEP == Gpt_Current_Mode) && (tempPtr->GptDisableEcumWakeupSourceNotification == (boolean)FALSE))
        {
            GPT_SET_WAKEUP_GEN(LogicChannel,GPT_WAKEUP_YES);
            EcuM_CheckWakeup(tempPtr->Gpt_ChannelWakeUpInfo);           
        }

#endif
#endif
    }
    else
    {
        /* Report Cer Error */
        Cer_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_EMIOS_INTERRUPT_ID, (uint8)GPT_CER_UNINIT_INTERRUPT);
        /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                                                  Cer_ReportError() function implementation */
    }
}

/*================================================================================================*/
/**
* @brief   Gpt_Pit_ProcessInterrupt.
* @details Non-AutoSar support function used by interrupt service routines to call notification 
*          functions if provided and enabled
*    
* @param[in]     hwChannel      hardware channel index
*
* @implements   DGPT03402
*/
/* @violates @ref GPT_IRQ_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Gpt_Pit_ProcessInterrupt(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel)
{
    P2CONST(Gpt_LLD_ChannelConfigType, AUTOMATIC, GPT_APPL_CONST) tempPtr;
    VAR(uint8, AUTOMATIC) LogicChannel;
    VAR(uint32, AUTOMATIC) irqStatus;
    
    LogicChannel = GPT_LLD_PIT_HardwareMap[hwChannel];
    if (((uint8)0xffu != LogicChannel) && (NULL_PTR != Gpt_Cfg_Ptr))
    {
        /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
        irqStatus  = ((PIT_READ_INTERRUPT(hwChannel)) << 1);
        /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
        irqStatus &= (REG_READ32(PIT_TCTRL(hwChannel)) & PIT_TCTRL_TIE);
        
        if((uint32)0 != irqStatus)
        {
            /* Find hardware channel number in global GPT initialization structure */
            /* using Hardware Map Array */
            /* @violates @ref GPT_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            tempPtr = &Gpt_LLD_ChannelConfigPtr[LogicChannel];

            /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
            PIT_CLEAR_INT_FLAG(hwChannel);
            /* If channel mode is one-shot, stop the channel and disable interrupts */
            if (GPT_CH_MODE_ONESHOT == (tempPtr->Gpt_ChannelMode))
            {
                /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
                PIT_TIMER_DISABLE(hwChannel);
                /* Disable Interrupts */
                /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
                PIT_INTERRUPT_DISABLE(hwChannel);
                Gpt_ChannelStatus[LogicChannel] = GPT_STATUS_EXPIRED;
            }

            /* Check if a notification exists for the channel */
            if (GPT_NOTIFICATION_DISABLED != GPT_GET_NOTIFICATION(LogicChannel))
            {
                tempPtr->Gpt_Notification();
            }

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
            if ((GPT_MODE_SLEEP == Gpt_Current_Mode) && (tempPtr->GptDisableEcumWakeupSourceNotification == (boolean)FALSE))
            {
                GPT_SET_WAKEUP_GEN(LogicChannel,GPT_WAKEUP_YES);
                EcuM_CheckWakeup(tempPtr->Gpt_ChannelWakeUpInfo);                
            }
#endif
#endif
        }
    }
    else
    {
        /* Report Cer Error */
        Cer_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_PIT_INTERRUPT_ID, (uint8)GPT_CER_UNINIT_INTERRUPT);
        /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                                                  Cer_ReportError() function implementation */
    }
}

/*================================================================================================*/
/**
* @brief   Gpt_Stm_ProcessInterrupt.
* @details Non-AutoSar support function used by interrupt service routines to call notification 
*          functions if provided and enabled
*    
* @param[in]     hwChannel      hardware channel index
*
* @implements   DGPT03401
*/
/* @violates @ref GPT_IRQ_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Gpt_Stm_ProcessInterrupt(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel)
{
    P2CONST(Gpt_LLD_ChannelConfigType, AUTOMATIC, GPT_APPL_CONST) tempPtr;
    VAR(uint8, AUTOMATIC) LogicChannel;
    VAR(uint32, AUTOMATIC) tempCompare;
    VAR(uint32, AUTOMATIC) irqStatus;
    LogicChannel = GPT_LLD_STM_HardwareMap[hwChannel];
    if (((uint8)0xffu != LogicChannel) && (NULL_PTR != Gpt_Cfg_Ptr))
    {
         /* Check the status flag register and interrupt enable register */
         /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
        irqStatus  = STM_CH_READ_ISR_REQ(hwChannel);
        /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
        irqStatus &= ((REG_READ32(STM_CCR(hwChannel))) & STM_CCR_ENABLE);
        
        if((uint32)0 != irqStatus)
        {
            /* Find hardware channel number in global GPT initialization structure */
            /* using Hardware Map Array */
            /* @violates @ref GPT_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            tempPtr = &Gpt_LLD_ChannelConfigPtr[LogicChannel];
            /* Disable channel before clearing interrupt status flag, errata e500 */
            /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
            STM_CH_DISABLE(hwChannel);
            /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
            STM_CH_CLEAR_ISR_REQ(hwChannel);

            /* If channel mode is one-shot, stop the channel and disable interrupts */
            if (GPT_CH_MODE_ONESHOT == (tempPtr->Gpt_ChannelMode))
            {
                /* Change internal channel status */
                Gpt_ChannelStatus[LogicChannel] = GPT_STATUS_EXPIRED;
            }
            /* CONTINUOUS MODE */
            else
            {
                /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
                tempCompare = STM_GET_COUNTER(hwChannel);
                /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
                STM_SET_COMPARE(hwChannel, tempCompare + Gpt_LLD_ChannelInfo[LogicChannel].Gpt_ReloadValue);
                /* Enable hardware channel */
                /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
                STM_CH_ENABLE(hwChannel);
            }

            /* Check if a notification exists for the channel */
            if (GPT_NOTIFICATION_DISABLED != GPT_GET_NOTIFICATION(LogicChannel))
            {
                tempPtr->Gpt_Notification();
            }
        }
    }
    else
    {
        /* Report Cer Error */
        Cer_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_STM_INTERRUPT_ID, (uint8)GPT_CER_UNINIT_INTERRUPT);
    }
}

/*================================================================================================*/
/**
* @brief   RTC_Gpt_ProcessInterrupt.
* @details Non-AutoSar support function used by interrupt service routines to call notification 
*          functions if provided and enabled
*    
* @param[in]     hwChannel      hardware channel index
*
* @implements   DGPT03404
*/
/* @violates @ref GPT_IRQ_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Gpt_Rtc_ProcessInterrupt(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel)
{
    P2CONST(Gpt_LLD_ChannelConfigType, AUTOMATIC, GPT_APPL_CONST) tempPtr;
    VAR(uint8, AUTOMATIC) LogicChannel;
    VAR(uint32, AUTOMATIC) irqStatus;
    LogicChannel = GPT_LLD_RTC_HardwareMap[hwChannel];
    if (((uint8)0xffu != LogicChannel) && (NULL_PTR != Gpt_Cfg_Ptr))
    {
         /* Check the status flag register and interrupt enable register */
         /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
        irqStatus  = (RTC_READ_API_INTERRUPT() << 1U);
        /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
        irqStatus &= RTC_READ_API_INT_ENABLE();
        
        if((uint32)0 != irqStatus)
        {    
            /* Find hardware channel number in global GPT initialization structure */
            /* using Hardware Map Array */
            /* @violates @ref GPT_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            tempPtr = &Gpt_LLD_ChannelConfigPtr[LogicChannel];
            /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
            RTC_CLEAR_API_INTERRUPT();

            /* If channel mode is one-shot, stop the channel and disable interrupts */
            if (GPT_CH_MODE_ONESHOT == (tempPtr->Gpt_ChannelMode))
            {
                /* Because RTC timer is always one-shot, stop the channel and disable interrupts */
                /* Putting the RTC timer off stops the channel */
            /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
                RTC_API_DISABLE();

                /* Change internal channel status */
                Gpt_ChannelStatus[LogicChannel] = GPT_STATUS_EXPIRED;
            }

            /* Check if a notification exists for the channel */
            if (GPT_NOTIFICATION_DISABLED != GPT_GET_NOTIFICATION(LogicChannel))
            {
                tempPtr->Gpt_Notification();
            }
            else
            {
                /* Disable API interrupt */
                /* @violates @ref GPT_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
                RTC_API_INT_DISABLE();
            }

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
            if ((GPT_MODE_SLEEP == Gpt_Current_Mode) && (tempPtr->GptDisableEcumWakeupSourceNotification == (boolean)FALSE))
            {
                GPT_SET_WAKEUP_GEN(LogicChannel,GPT_WAKEUP_YES);
                EcuM_CheckWakeup(tempPtr->Gpt_ChannelWakeUpInfo);               
            }
#endif
#endif
        }
    }
    else
    {
        /* Report Cer Error */
        Cer_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_RTC_INTERRUPT_ID, (uint8)GPT_CER_UNINIT_INTERRUPT);
    }
}

#define GPT_STOP_SEC_CODE
/* @violates @ref GPT_IRQ_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_IRQ_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
