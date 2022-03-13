/**
*   @file    Gpt_Rtc_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - Source file of the RTC driver.
*   @details RTC driver interface.
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
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section GPT_RTC_LLD_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation  is not  fixed since  the inclusion  of MemMap.h  is as  per Autosar  requirement
* MEMMAP003.
*
* @section GPT_RTC_LLD_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_RTC_LLD_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* The cast is used to address memory mapped registers or other hw resources.
*
* @section GPT_RTC_LLD_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* The long names are maintained for better readability.
*
* @section GPT_RTC_LLD_C_REF_5
* Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable
* The pointer is used only within scope.
*
* @section GPT_RTC_LLD_C_REF_6
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
* @section GPT_RTC_LLD_C_REF_7
* Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope
* If a variable to be used within a Function in the same file use Static.Similarly if a function is called 
* from elsewhere within the same file use Static.
*
*/
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Gpt_Rtc_LLD.c
* @requirements   BSW00374, BSW00318
* @implements     DGPT10600
*/
#include "Gpt_Rtc_LLD.h"
#include "Reg_eSys_Rtc.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_Rtc_LLD.c
* @requirements   BSW00374, BSW00318
*/
#define GPT_RTC_LLD_VENDOR_ID_C                    43
/* @violates @ref GPT_RTC_LLD_C_REF_4 MISRA 2004 Rule 1.4: Identifier clash. */
/* @violates @ref GPT_RTC_LLD_C_REF_6 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_RTC_LLD_AR_RELEASE_MAJOR_VERSION_C     4
/* @violates @ref GPT_RTC_LLD_C_REF_4 MISRA 2004 Rule 1.4: Identifier clash. */
/* @violates @ref GPT_RTC_LLD_C_REF_6 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_RTC_LLD_AR_RELEASE_MINOR_VERSION_C     0
/* @violates @ref GPT_RTC_LLD_C_REF_4 MISRA 2004 Rule 1.4: Identifier clash. */
/* @violates @ref GPT_RTC_LLD_C_REF_6 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_RTC_LLD_AR_RELEASE_REVISION_VERSION_C  3
#define GPT_RTC_LLD_SW_MAJOR_VERSION_C             1
#define GPT_RTC_LLD_SW_MINOR_VERSION_C             0
#define GPT_RTC_LLD_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (GPT_RTC_LLD_VENDOR_ID_C != GPT_RTC_LLD_VENDOR_ID)
#error "Gpt_Rtc_LLD.c and Gpt_Rtc_LLD.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_RTC_LLD_AR_RELEASE_MAJOR_VERSION_C != GPT_RTC_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_RTC_LLD_AR_RELEASE_MINOR_VERSION_C != GPT_RTC_LLD_AR_RELEASE_MINOR_VERSION) || \
     (GPT_RTC_LLD_AR_RELEASE_REVISION_VERSION_C != GPT_RTC_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Rtc_LLD.c and Gpt_Rtc_LLD.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_RTC_LLD_SW_MAJOR_VERSION_C != GPT_RTC_LLD_SW_MAJOR_VERSION) || \
     (GPT_RTC_LLD_SW_MINOR_VERSION_C != GPT_RTC_LLD_SW_MINOR_VERSION) || \
     (GPT_RTC_LLD_SW_PATCH_VERSION_C != GPT_RTC_LLD_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Rtc_LLD.c and Gpt_Rtc_LLD.h are different"
#endif


#if (GPT_RTC_LLD_VENDOR_ID_C != REG_ESYS_RTC_VENDOR_ID)
#error "Gpt_Rtc_LLD.c and Reg_eSys_Rtc.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_RTC_LLD_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_RTC_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_RTC_LLD_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_RTC_AR_RELEASE_MINOR_VERSION) || \
     (GPT_RTC_LLD_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_RTC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Rtc_LLD.c and Reg_eSys_Rtc.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_RTC_LLD_SW_MAJOR_VERSION_C != REG_ESYS_RTC_SW_MAJOR_VERSION) || \
     (GPT_RTC_LLD_SW_MINOR_VERSION_C != REG_ESYS_RTC_SW_MINOR_VERSION) || \
     (GPT_RTC_LLD_SW_PATCH_VERSION_C != REG_ESYS_RTC_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Rtc_LLD.c and Reg_eSys_Rtc.h are different"
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
/* @violates @ref GPT_RTC_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.15,Repeated include MemMap.h */
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief          Gpt driver initialization function for the Rtc module.
* @details        This function:
*                       - resets the Rtc control register
*                       - clears the Rtc interrupt flags
*                       - sets the clock source for Rtc  (selection in tresos)
*                       - sets the prescaler value (selection in tresos)
*                       - configures the freeze mode (enabled/disabled)
*                       - enables API Interrupt (RTCC - APIIE) - the RTCC - APIEN (API function) is
*                         not enabled here, but enabled when starting the RTC timer channel, after
*                         setting the timeout value (in RTCC - APIVAL)
*                       - enables the RTC counter
*
* @param[in]     freezeEnable     indicates if the Freeze mode is enabled
* @param[in]     channelClkSrc    clock source for the RTC channel
* @param[in]     channelPrescale   Prescaler value for the RTC channel
*
*
* @implements    DGPT10202
*/
FUNC (void, GPT_CODE) Rtc_LLD_InitChannel(VAR(Rtc_Gpt_LLD_ChannelClkSrcType, AUTOMATIC) channelClkSrc,
                                          VAR(Gpt_PrescaleType, AUTOMATIC) channelPrescale,
                                          VAR(boolean, AUTOMATIC) freezeEnable)
{
    /* Reset RTC control register */
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    RTC_RESET_CNTRL_REG();

    /* Clear interrupt request */
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    RTC_CLEAR_ALL_INTERRUPT();

    /* Configure clock select and prescaler */
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    RTC_CLOCK_SELECT(channelClkSrc);
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    RTC_CONFIGURE_PRESCALER(channelPrescale);
    if ((boolean)TRUE == freezeEnable)
    {
        /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        RTC_FREEZE_ENABLE();
    }

    /* Enable API interrupt and start RTC counter */
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    RTC_API_INT_ENABLE();
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    RTC_COUNTER_ENABLE();
}

#if (GPT_DEINIT_API == STD_ON)
/*================================================================================================*/
/**
* @brief         Gpt driver de-initialization function for Rtc module.
* @details       This function:
*                       - resets the Rtc control register
*                       - clears the Rtc interrupt flags
*
*
* @implements    DGPT10203
*/
FUNC (void, GPT_CODE) Rtc_LLD_DeInit()
{
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    RTC_RESET_CNTRL_REG();

    /* Clear all interrupts */
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    RTC_CLEAR_ALL_INTERRUPT();
}
#endif

/*================================================================================================*/
/**
* @brief          A brief text description (one line).
* @details        A detailed text description of the code object being described, it can span more
*                 lines and contain formatting tags (both Doxygen and HTML). Optional tag.
*
* @brief          Gpt driver function for starting the Rtc timer channel.
* @details        This function:
*                       - disables the API functionality
*                       - sets the timeout value (in RTCC - APIVAL)
*                       - enables API functionality (RTCC - APIEN).
*                       - reads the RTC counter register and stores the value of the channel start time
*                       - if in one shot mode, enables API Interrupt, in order to stop the channel in the ISR
*
* @param[in]      value            channel timeout value
* @param[in]      channelMode      One Shot or Continous
*
* @param[in,out]  startTimeValuePtr pointer to the start time value
*
*
* @implements     DGPT10204
*/
FUNC (void, GPT_CODE) Rtc_LLD_StartTimer(VAR(Gpt_ValueType, AUTOMATIC) value,
                                         VAR(Gpt_ChannelModeType, AUTOMATIC) channelMode,
                                         P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) startTimeValuePtr)
{
    /* Stop API counter */
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    RTC_API_DISABLE();

    /* Configure channel compare register */
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    RTC_API_SET_COMPARE(value);

    /* Restart API counter */
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    RTC_API_ENABLE();

    /* store the value of the channel start time */
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    *startTimeValuePtr = RTC_API_GET_COUNTER();

    if (channelMode == GPT_CH_MODE_ONESHOT)
    {
        /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        RTC_API_INT_ENABLE();
    }
}

/*================================================================================================*/
/**
* @brief          Gpt driver function for stopping the Rtc timer channel.
* @details        This function:
*                           - disables the API functionality
*                           - clears the API interrupt flag
* @param[out]    returnValuePtr   current time value on stop
*
*
* @implements     DGPT10205
*/
FUNC (void, GPT_CODE) Rtc_LLD_StopTimer(P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr)
{
        /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        /* @violates @ref GPT_RTC_LLD_C_REF_5 taking address of near auto variable */
        *returnValuePtr = RTC_API_GET_COMPARE() - RTC_API_GET_COUNTER();
        /* Stop API counter */
        /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        RTC_API_DISABLE();

        /* Clear interrupt flag */
        /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        RTC_CLEAR_API_INTERRUPT();
}

#if ((GPT_TIME_ELAPSED_API == STD_ON) || (GPT_TIME_REMAINING_API == STD_ON))
/*================================================================================================*/
/**
* @brief          A brief text description (one line).
* @details        A detailed text description of the code object being described, it can span more
*                 lines and contain formatting tags (both Doxygen and HTML). Optional tag.
*
* @brief           Gpt driver function for getting the current time value for an Rtc timer channel.
* @details        This function:
*                        - reads timeOut value (RTCC - APIVAL)
*                        - reads the RTC counter register
*                        - depending on above it calculates and returns the current time
*
* @param[in]      startTimeValue   RTC start timer value
* @param[out]    returnValuePtr   current time value
*
*
* @implements     DGPT10206
*/
FUNC (void, GPT_CODE) Rtc_LLD_GetTime(VAR(Gpt_ValueType, AUTOMATIC) startTimeValue,
                                             P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr)
{
    VAR(uint32, AUTOMATIC) currentTimerValue, timeOutValue;

    /* Read counter register */
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    timeOutValue = RTC_API_GET_COMPARE();
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    currentTimerValue = RTC_API_GET_COUNTER();
    
        /* Check the RTC API counter is overflow */
    if (startTimeValue > currentTimerValue)
    {
        *returnValuePtr = timeOutValue - (((RTC_APIVAL_MASK - startTimeValue) + currentTimerValue)%timeOutValue);
    }
    else
    {
        *returnValuePtr = timeOutValue - ((currentTimerValue - startTimeValue)%timeOutValue);
    }
}
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/*================================================================================================*/
/**
* @brief          Gpt driver function for putting the Rtc timer channel in SLEEP mode.
* @details        This function:
*                      - if wakeup is disabled for the RTC timer channel
*                                        - disables the RTC counter
*                                        - disables the API functionality (RTCC - APIEN)
*                                        - clears the Rtc interrupt flags
*                      - if wakeup is enabled for the RTC timer channel
*                                        - clears the API interrupt flag
*                                        - enables API Interrupt (RTCC - APIIE)
*
* @param[in]      wakeupEnabled    Indicates whether wake up functionality is enabled or not for the
*                                  corresponding channel.
* @param[out]    returnValuePtr   current time value on stop
*
*
* @implements     DGPT10208
*/
FUNC (void, GPT_CODE) Rtc_LLD_SetSleepMode(VAR(boolean, AUTOMATIC) wakeupEnabled, 
                                                     P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr)
{
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    *returnValuePtr = RTC_API_GET_COUNTER();
    /* Check if wake-up is NOT enabled */
    if ((boolean)FALSE == wakeupEnabled)
    {
        /* Disable RTC counter and API */
        /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        RTC_COUNTER_DISABLE();
        /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        RTC_API_DISABLE();

        /* Clear interrupt request */
        /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        RTC_CLEAR_ALL_INTERRUPT();
    }
    else
    {
        /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        RTC_CLEAR_API_INTERRUPT();
        /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        RTC_API_INT_ENABLE();
    }
}
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/*================================================================================================*/
/**
* @brief          Gpt driver function for putting the Rtc timer channel in NORMAL mode.
* @details        This function enables the Rtc counter
*
*
* @implements     DGPT10209
*/
/* @violates @ref GPT_RTC_LLD_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Rtc_LLD_SetNormalMode()
{
    /* RTC counter is re-enabled */
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    RTC_COUNTER_ENABLE();
}
#endif

#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
/*================================================================================================*/
/**
* @brief          Gpt driver function for enabling the Rtc timer channel notification/IRQ.
* @details        This function:
*                         - clears the (pending) API interrupt flag
*                         - enables the API IRQ (RTCC - APIIE)
*
*
* @implements     DGPT10211
*/
FUNC (void, GPT_CODE) Rtc_LLD_EnableNotification()
{
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    RTC_CLEAR_API_INTERRUPT();
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    RTC_API_INT_ENABLE();
}

/*================================================================================================*/
/**
* @brief          A brief text description (one line).
* @details        A detailed text description of the code object being described, it can span more
*                 lines and contain formatting tags (both Doxygen and HTML). Optional tag.
*
* @brief          Gpt driver function for disabling the Rtc timer channel notification/IRQ.
* @details        This function disables the API IRQ (RTCC - APIIE)
*
*
* @implements      DGPT10210
*/
FUNC (void, GPT_CODE) Rtc_LLD_DisableNotification()
{
    /* @violates @ref GPT_RTC_LLD_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    RTC_API_INT_DISABLE();
}
#endif

#define GPT_STOP_SEC_CODE
/* @violates @ref GPT_RTC_LLD_C_REF_1 MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_RTC_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
