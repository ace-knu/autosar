/**
*   @file    Gpt_Pit_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - PIT driver source file.
*   @details Detailed file description (can be multiple lines).
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
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section GPT_PIT_LLD_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section GPT_PIT_LLD_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_PIT_LLD_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* The cast is used to address memory mapped registers or other hw resources.
*
* @section GPT_PIT_LLD_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* The long names are maintained for better readability..
*
* @section GPT_PIT_LLD_C_REF_5
* Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness.
* The long names are maintained for better readability..
*
* @section GPT_PIT_LLD_C_REF_6
* Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable
* The pointer is used only within scope.
*
* @section GPT_PIT_LLD_C_REF_7
* Violates MISRA 2004 Required Rule 16.4, The identifiers used in the declaration and definition of
* a function shall be identical
*
* @section GPT_PIT_LLD_C_REF_8
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gpt_Pit_LLD.h"
#include "Reg_eSys_Pit.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_Pit_LLD.c
* @requirements   BSW00374, BSW00318
* @implements     DGPT09600
* @{
*/
#define GPT_PIT_LLD_VENDOR_ID_C                    43
/* @violates @ref GPT_PIT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 1.4, Identifier clash */
/* @violates @ref GPT_PIT_LLD_C_REF_8 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_PIT_LLD_AR_RELEASE_MAJOR_VERSION_C     4
/* @violates @ref GPT_PIT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 1.4, Identifier clash */
/* @violates @ref GPT_PIT_LLD_C_REF_8 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_PIT_LLD_AR_RELEASE_MINOR_VERSION_C     0
/* @violates @ref GPT_PIT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 1.4, Identifier clash */
/* @violates @ref GPT_PIT_LLD_C_REF_8 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_PIT_LLD_AR_RELEASE_REVISION_VERSION_C  3
#define GPT_PIT_LLD_SW_MAJOR_VERSION_C             1
#define GPT_PIT_LLD_SW_MINOR_VERSION_C             0
#define GPT_PIT_LLD_SW_PATCH_VERSION_C             1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#if ( GPT_PIT_LLD_VENDOR_ID_C!= GPT_PIT_LLD_VENDOR_ID)
    #error "Gpt_Pit_LLD.c and Gpt_Pit_LLD.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_PIT_LLD_AR_RELEASE_MAJOR_VERSION_C != GPT_PIT_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_PIT_LLD_AR_RELEASE_MINOR_VERSION_C != GPT_PIT_LLD_AR_RELEASE_MINOR_VERSION) || \
     (GPT_PIT_LLD_AR_RELEASE_REVISION_VERSION_C != GPT_PIT_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Pit_LLD.c and Gpt_Pit_LLD.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_PIT_LLD_SW_MAJOR_VERSION_C != GPT_PIT_LLD_SW_MAJOR_VERSION) || \
     (GPT_PIT_LLD_SW_MINOR_VERSION_C != GPT_PIT_LLD_SW_MINOR_VERSION) || \
     (GPT_PIT_LLD_SW_PATCH_VERSION_C != GPT_PIT_LLD_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Pit_LLD.c and Gpt_Pit_LLD.h are different"
#endif

#if ( GPT_PIT_LLD_VENDOR_ID_C!= REG_ESYS_PIT_VENDOR_ID)
    #error "Gpt_Pit_LLD.c and Reg_eSys_Pit.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_PIT_LLD_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_PIT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_PIT_LLD_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_PIT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_PIT_LLD_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_PIT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Pit_LLD.c and Reg_eSys_Pit.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_PIT_LLD_SW_MAJOR_VERSION_C != REG_ESYS_PIT_SW_MAJOR_VERSION) || \
     (GPT_PIT_LLD_SW_MINOR_VERSION_C != REG_ESYS_PIT_SW_MINOR_VERSION) || \
     (GPT_PIT_LLD_SW_PATCH_VERSION_C != REG_ESYS_PIT_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Pit_LLD.c and Reg_eSys_Pit.h are different"
#endif

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
#define GPT_START_SEC_CODE
/* @violates @ref GPT_PIT_LLD_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_PIT_LLD_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief   Gpt driver initialization function for Pit module.
* @details This function is called separately for each PIT hw channel corresponding to the configured
*          timer channels, and:
*          - enables the PIT module
*          - configures the freeze mode (enabled/disabled)
*          - disables the IRQ correpsonding to the PIT channel
*          - clears the (pending) interrupt flag corresponding to Pit channel
*          - disables the PIT timer channel
*          - clears the Load Value register correponding to the Pit channel.
*
* @param[in]     freezeEnable     indicates if the Freeze mode is enabled
* @param[in]     hwChannel        Pit hw channel ID
*
*
* @implements DGPT09206
*/
FUNC (void, GPT_CODE) Pit_LLD_InitChannel(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
                                          VAR(boolean, AUTOMATIC) freezeEnable)
{
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */    
    PIT_ENABLE_MODULE();
    if ((boolean)TRUE == freezeEnable)
    {
        /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */        
        PIT_FREEZE_ENABLE();
    }
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    PIT_INTERRUPT_DISABLE(hwChannel);
    /* Clear pending interrupts */
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    PIT_CLEAR_INT_FLAG(hwChannel);
    /* Stop Channel to Configure Channel */
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    PIT_TIMER_DISABLE(hwChannel);
    /* Set Compare Value to 0 */
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    PIT_SETLOADVALUE(hwChannel, 0);
}

/*================================================================================================*/
#if (GPT_DEINIT_API == STD_ON)
/**
* @brief   Gpt driver de-initialization function for Pit module.
* @details This function is called separately for each PIT hw channel corresponding to the configured
*          timer channels, and:
*          - disables the PIT channel
*          - disables the freeze mode
*          - disables IRQ corresponding to Pit channel
*          - clears the (pending) interrupt flag corresponding to Pit channel
*
* @param[in]     hwChannel        Pit hw channel ID
*
*
* @implements DGPT09201
*/
FUNC (void, GPT_CODE) Pit_LLD_DeInit(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel)
{
    /* Reset Status and Control Register */
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    PIT_FREEZE_DISABLE();
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    PIT_INTERRUPT_DISABLE(hwChannel);
    /* Clear Interrupt Flag */
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    PIT_CLEAR_INT_FLAG(hwChannel);
}
#endif

/*================================================================================================*/
/**
* @brief   Gpt driver function for starting the Pit timer channel.
* @details This function:
*          - clears the (pending) interrupt flag corresponding to Pit channel
*          - disables the PIT timer channel
*          - sets the load/timeout value into the PIT timer channel register
*          - enables the PIT timer channel
*         - enables the IRQ corresponding to the PIT timer channel,if channel configured in One Shot mode.
*
* @param[in]     hwChannel        Pit hw channel ID
* @param[in]     value            channel timeout value
* @param[in]     channelMode      One Shot or Continous
*
*
* @implements DGPT09209
*/
FUNC (void, GPT_CODE) Pit_LLD_StartTimer(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
                                         VAR(Gpt_ValueType, AUTOMATIC) value,
                                         VAR(Gpt_ChannelModeType, AUTOMATIC) channelMode)
{
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */    
    PIT_CLEAR_INT_FLAG(hwChannel);
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    PIT_TIMER_DISABLE(hwChannel);
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    PIT_SETLOADVALUE(hwChannel, value);
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    PIT_TIMER_ENABLE(hwChannel);

    if (GPT_CH_MODE_ONESHOT == channelMode)
    {
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
        PIT_INTERRUPT_ENABLE(hwChannel);
        /* in One Shot mode the PIT channel is disabled within the Gpt ISR */
    }
}

/*================================================================================================*/
/**
* @brief   Gpt driver function for stopping the Pit timer channel.
* @details This function disables the PIT channel
*
* @param[in]     hwChannel        Pit hw channel ID
* @param[out]    returnValuePtr   current time value on stop
*
*
* @implements DGPT09210
*/
FUNC (void, GPT_CODE) Pit_LLD_StopTimer(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
                                        P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr)
{
    /* @violates @ref GPT_PIT_LLD_C_REF_6 taking address of near auto variable */
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    *returnValuePtr = PIT_GETLOADVALUE(hwChannel) - PIT_READTIMERVALUE(hwChannel);
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    PIT_TIMER_DISABLE(hwChannel);
    
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    PIT_CLEAR_INT_FLAG(hwChannel);
}

#if ((GPT_TIME_ELAPSED_API == STD_ON) || (GPT_TIME_REMAINING_API == STD_ON))
/*************************************************************************************************/
/**
@brief   Gpt driver function for getting the current time for an Pit timer channel.
@details This function:
         - reads the PIT channel load register
         - reads the PIT counter register
         - depending on above it calculates and returns the elapsed time

@param[in]     hwChannel        Pit hw channel ID
@param[out]    returnValuePtr   elapsed time value

@remarks Implements DGPT09204, DGPT09205
*/
FUNC (void, GPT_CODE) Pit_LLD_GetTime(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
                                             P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr)
{
    /* This is applicable for the following lines of code */
    /* @violates @ref GPT_PIT_LLD_C_REF_6 taking address of near auto variable */
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    *returnValuePtr = PIT_GETLOADVALUE(hwChannel) - PIT_READTIMERVALUE(hwChannel);
     /* MISRA-C:2004 11.1 VIOLATION: End of code block */
}
#endif

/*================================================================================================*/
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
* @brief   Gpt driver function for putting the Pit timer channel in SLEEP mode.
* @details This function is called separately for each PIT hw channel corresponding to the configured
*         timer channels, and:
*         - clears the (pending) interrupt flag corresponding to Pit timer channel
*         - disable the Pit timer channel if the channel wakeup function is disabled
*         - enable the Pit timer channel if the channel wakeup function is enabled
*
* @param[in]     hwChannel        Pit hw channel ID
* @param[in]     wakeUpEnabled    Indicates whether wake up functionality is enabled or not for the
*                                 corresponding channel.
* @param[out]    returnValuePtr   current time value on stop
*
*
* @implements DGPT09208
*/
FUNC (void, GPT_CODE) Pit_LLD_SetSleepMode(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
                                           VAR(boolean, AUTOMATIC) wakeUpEnabled,
                                           P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr)
/*
* @violates @ref Gpt_PIT_LLD_C_REF_7 The identifiers used in the declaration and definition of
* a function shall be identical
*/
{
    /* @violates @ref GPT_PIT_LLD_C_REF_6 taking address of near auto variable */
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    *returnValuePtr = PIT_GETLOADVALUE(hwChannel) - PIT_READTIMERVALUE(hwChannel);
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    PIT_CLEAR_INT_FLAG(hwChannel);

    /* Check if wake-up is NOT enabled */
    if ((boolean)FALSE == wakeUpEnabled)
    {
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
        PIT_TIMER_DISABLE(hwChannel);
    }
    else
    {
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
        PIT_INTERRUPT_ENABLE(hwChannel);
    }
}
#endif

/*================================================================================================*/
#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
/**
* @brief   Gpt driver function for enabling the Pit timer channel notification/IRQ.
* @details This function:
*         - enables the IRQ corresponding to the Pit timer channel
*
* @param[in]     hwChannel        Pit hw channel ID
*
*
* @implements DGPT09203
*/
FUNC (void, GPT_CODE) Pit_LLD_EnableNotification(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel)
{
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    PIT_INTERRUPT_ENABLE(hwChannel);
}

/*================================================================================================*/
/**
* @brief   Gpt driver function for disabling the Pit timer channel notification/IRQ.
* @details This function disables the IRQ corresponding to the Pit timer channel
*
* @param[in]     hwChannel        Pit hw channel ID
*
*
* @implements DGPT09202
*/
FUNC (void, GPT_CODE) Pit_LLD_DisableNotification(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel)
{
    /* @violates @ref GPT_PIT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    PIT_INTERRUPT_DISABLE(hwChannel);
}
#endif

#define GPT_STOP_SEC_CODE
/* @violates @ref GPT_PIT_LLD_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_PIT_LLD_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
