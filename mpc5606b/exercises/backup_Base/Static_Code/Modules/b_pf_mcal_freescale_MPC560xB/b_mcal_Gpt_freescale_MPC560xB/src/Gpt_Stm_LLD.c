/**
*   @file    Gpt_Stm_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - STM driver source file.
*   @details Containes the interface functions of the STM driver.
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
* @section GPT_STM_LLD_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section GPT_STM_LLD_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_STM_LLD_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* The cast is used to address memory mapped registers or other hw resources.
*
* @section GPT_STM_LLD_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* The long names are maintained for better readability.
*
* @section GPT_STM_LLD_C_REF_5
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Gpt_Stm_LLD.c
* @requirements   BSW00374, BSW00318
* @implements     DGPT08600, DGPT01026
*/
#include "Gpt_Stm_LLD.h"
#include "Reg_eSys_Stm.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_Stm_LLD.c
* @brief          Parameters that shall be published within the Gpt driver header file and also in
*                 the module's description file
* @requirements   BSW00374, BSW00379, BSW00318
* @{
*/
#define GPT_STM_LLD_VENDOR_ID_C                    43
/*@violates @ref GPT_STM_LLD_C_REF_4 Violates MISRA 2004 Required Rule 1.4, Identifier clash */
/* @violates @ref GPT_STM_LLD_C_REF_5 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_STM_LLD_AR_RELEASE_MAJOR_VERSION_C     4
/*@violates @ref GPT_STM_LLD_C_REF_4 Violates MISRA 2004 Required Rule 1.4, Identifier clash */
/* @violates @ref GPT_STM_LLD_C_REF_5 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_STM_LLD_AR_RELEASE_MINOR_VERSION_C     0
/*@violates @ref GPT_STM_LLD_C_REF_4 Violates MISRA 2004 Required Rule 1.4, Identifier clash */
/* @violates @ref GPT_STM_LLD_C_REF_5 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_STM_LLD_AR_RELEASE_REVISION_VERSION_C  3
#define GPT_STM_LLD_SW_MAJOR_VERSION_C             1
#define GPT_STM_LLD_SW_MINOR_VERSION_C             0
#define GPT_STM_LLD_SW_PATCH_VERSION_C             1
/**@}*/
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (GPT_STM_LLD_VENDOR_ID_C != GPT_STM_LLD_VENDOR_ID)
    #error "Gpt_Stm_LLD.c and Gpt_Stm_LLD.hhave different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_STM_LLD_AR_RELEASE_MAJOR_VERSION_C != GPT_STM_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_STM_LLD_AR_RELEASE_MINOR_VERSION_C != GPT_STM_LLD_AR_RELEASE_MINOR_VERSION) || \
     (GPT_STM_LLD_AR_RELEASE_REVISION_VERSION_C != GPT_STM_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Stm_LLD.c and Gpt_Stm_LLD.hare different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_STM_LLD_SW_MAJOR_VERSION_C != GPT_STM_LLD_SW_MAJOR_VERSION) || \
     (GPT_STM_LLD_SW_MINOR_VERSION_C != GPT_STM_LLD_SW_MINOR_VERSION) || \
     (GPT_STM_LLD_SW_PATCH_VERSION_C != GPT_STM_LLD_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Stm_LLD.c and Gpt_Stm_LLD.hare different"
#endif

#if (GPT_STM_LLD_VENDOR_ID_C != REG_ESYS_STM_VENDOR_ID)
    #error "Gpt_Stm_LLD.c and Reg_eSys_Stm.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_STM_LLD_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_STM_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_STM_LLD_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_STM_AR_RELEASE_MINOR_VERSION) || \
     (GPT_STM_LLD_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_STM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Stm_LLD.c and Reg_eSys_Stm.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_STM_LLD_SW_MAJOR_VERSION_C != REG_ESYS_STM_SW_MAJOR_VERSION) || \
     (GPT_STM_LLD_SW_MINOR_VERSION_C != REG_ESYS_STM_SW_MINOR_VERSION) || \
     (GPT_STM_LLD_SW_PATCH_VERSION_C != REG_ESYS_STM_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Stm_LLD.c and Reg_eSys_Stm.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
/* @violates @ref GPT_STM_LLD_C_REF_5 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref GPT_STM_LLD_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

/* Array containing the channel counters' value load */
static VAR(Gpt_ValueType, GPT_VAR) Stm_LLD_Load[GPT_STM_CHAN_NUM];

/* @violates @ref GPT_STM_LLD_C_REF_5 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref GPT_STM_LLD_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_STM_LLD_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"


/* @violates @ref GPT_STM_LLD_C_REF_5 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_START_SEC_CONST_32
/* @violates @ref GPT_STM_LLD_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_STM_LLD_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"
/**
* @brief base address array for STM
*/
CONST(uint32, GPT_CONST) STM_BASE_ADDR[] = {
#ifdef STM_0_BASEADDR
    STM_0_BASEADDR
#endif
#ifdef STM_1_BASEADDR
   ,STM_1_BASEADDR
#endif
#ifdef STM_2_BASEADDR
   ,STM_2_BASEADDR
#endif
};
/* @violates @ref GPT_STM_LLD_C_REF_5 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_STOP_SEC_CONST_32
/* @violates @ref GPT_STM_LLD_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_STM_LLD_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define GPT_START_SEC_CODE
/* @violates @ref GPT_STM_LLD_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_STM_LLD_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief   Gpt driver initialization function for Stm module.
* @details This function is called separately for each STM hw channel corresponding to the configured
*          timer channels, and:
*          - sets the prescaler value
*          - configures the freeze mode (enabled/disabled)
*          - enables the STM counter
*          - disables the STM channel
*          - clears the (pending) interrupt flag corresponding to Stm channel
*          - clears the compare register correponding to the Stm channel.
*
* @param[in]     freezeEnable     indicates if the Freeze mode is enabled
* @param[in]     channelPrescale  prescaler value for the corresponding Stm channel
* @param[in]     hwChannel        Stm hw channel ID
*

*
* @implements DGPT08204
*/
FUNC (void, GPT_CODE) Stm_LLD_InitChannel(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
                                          VAR(Gpt_PrescaleType, AUTOMATIC) channelPrescale,
                                          VAR(boolean, AUTOMATIC) freezeEnable)
{
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    STM_SET_PRESCALER(hwChannel, channelPrescale);
    if ((boolean)TRUE == freezeEnable)
    {
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
        STM_SET_FRZ(hwChannel);
    }
    else
    {
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
        STM_CLR_FRZ(hwChannel);
    }
    /* Timer Counter is enabled */
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    STM_TIMER_COUNTER_ENABLE(hwChannel);

    /* STM channel disabled */
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    STM_CH_DISABLE(hwChannel);

    /* Clear interrupt request */
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    STM_CH_CLEAR_ISR_REQ(hwChannel);

    /* Set Compare Value to 0 */
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    STM_SET_COMPARE(hwChannel, 0U);
    
    Stm_LLD_Load[hwChannel] = 0U;
}

#if (GPT_DEINIT_API == STD_ON)
/*================================================================================================*/
/**
* @brief   Gpt driver de-initialization function for Stm module.
* @details This function is called separately for each STM hw channel corresponding to the configured
*          timer channels, and:
*          - disables the STM counter
*          - resets the prescaler bits in the control register
*          - disables the STM channel
*          - clears the (pending) interrupt flag corresponding to Stm channel
*          - clears the compare register correponding to the Stm channel.
*
* @param[in]     hwChannel        Stm hw channel ID
*
* @pre     On/Off by the configuration parameter: GPT_DEINIT_API
*

*
* @implements DGPT08201
*/
FUNC (void, GPT_CODE) Stm_LLD_DeInit(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel)
{
    /* Timer Counter is disabled */
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    STM_TIMER_COUNTER_DISABLE(hwChannel);

    /* Reset Prescaler */
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    STM_SET_PRESCALER(hwChannel, 0U);

    /* disable channel configured */
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    STM_CH_DISABLE(hwChannel);

    /* Set Compare Value to 0 */
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    STM_SET_COMPARE(hwChannel, 0UL);

    /* Clear Interrupt Flag */
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    STM_CH_CLEAR_ISR_REQ(hwChannel);
}
#endif

/*================================================================================================*/
/**
* @brief   Gpt driver function for starting the Stm timer channel.
* @details This function:
*          - reads the current counter register value and sets the compare register to the sum of
*            counter register value plus the timeout value
*          - enables the STM channel
*
* @param[in]     hwChannel        Stm hw channel ID
* @param[in]     value            channel timeout value
*

*
* @implements DGPT08207
*/
FUNC (void, GPT_CODE) Stm_LLD_StartTimer(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
                                         VAR(Gpt_ValueType, AUTOMATIC) value)
{
    VAR(uint32, AUTOMATIC) counterValue;

    /* Configure channel compare register */
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    counterValue = STM_GET_COUNTER(hwChannel);

    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    STM_SET_COMPARE(hwChannel, ((uint32)(counterValue + value)));

    Stm_LLD_Load[hwChannel] = value;

    /* Enable hardware channel */
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    STM_CH_ENABLE(hwChannel);

    /* for STM, there is no need to enable the corresponding timer channel IRQ, as there is no HW
       support for enabling/disabling the STM IRQ */
}

/*================================================================================================*/
/**
* @brief   Gpt driver function for stopping the Stm timer channel.
* @details This function:
*          - disables the STM channel
*          - clears the (pending) interrupt flag corresponding to Stm channel
*
* @param[in]     hwChannel        Stm hw channel ID
* @param[out]    returnValuePtr   current time value on stop
*
*
* @implements DGPT08208
*/
FUNC (void, GPT_CODE) Stm_LLD_StopTimer(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
                                        P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr)
{
    VAR(Gpt_ValueType, AUTOMATIC) compareValue;
    VAR(Gpt_ValueType, AUTOMATIC) counterValue;

    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    compareValue = STM_GET_COMPARE(hwChannel);
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    counterValue = STM_GET_COUNTER(hwChannel);
  
    if (counterValue > compareValue)
    {
        *returnValuePtr = Stm_LLD_Load[hwChannel] - ((((STM_CNT_MAX_VALUE - counterValue) + compareValue)) + STM_OVERFLOW_PAD);
    }
    else
    {
        *returnValuePtr = Stm_LLD_Load[hwChannel] - (compareValue - counterValue);
    }

    /* Disable hardware channel */
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    STM_CH_DISABLE(hwChannel);

    /* Clear interrupt flag */
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    STM_CH_CLEAR_ISR_REQ(hwChannel);

}

#if ((GPT_TIME_ELAPSED_API == STD_ON) || (GPT_TIME_REMAINING_API == STD_ON))
/*================================================================================================*/
/**
* @brief   Gpt driver function for getting the current time value for an Stm timer channel.
* @details This function:
*          - reads the STM channel compare register
*          - reads the STM counter register
*          - depending on above and on channel timeout value it calculates and returns the elapsed
*            time
*
* @param[in]     hwChannel        Stm hw channel ID
* @param[in]     returnValuePtr   current time value
*
* @pre     On/Off by the configuration parameter: GPT_TIME_ELAPSED_API and GPT_TIME_REMAINING_API
*
*
* @implements DGPT08202
*/
FUNC (void, GPT_CODE) Stm_LLD_GetTime(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
                                             P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr)
{
    VAR(uint32, AUTOMATIC) compareValue;
    VAR(uint32, AUTOMATIC) counterValue;
    

    /* Read compare and counter registers */
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    compareValue = STM_GET_COMPARE(hwChannel);
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    counterValue = STM_GET_COUNTER(hwChannel);
  
    if (counterValue > compareValue)
    {
        *returnValuePtr = Stm_LLD_Load[hwChannel] - ((((STM_CNT_MAX_VALUE - counterValue) + compareValue)) + STM_OVERFLOW_PAD);
    }
    else
    {
        *returnValuePtr = Stm_LLD_Load[hwChannel] - (compareValue - counterValue);
    }
}
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/*================================================================================================*/
/**
* @brief   Gpt driver function for putting the Stm timer channel in NORMAL mode.
* @details This function enables the Stm counter
*
* @pre     On/Off by the configuration parameter: GPT_WAKEUP_FUNCTIONALITY_API
*

*
* @implements DGPT08205
*/
FUNC (void, GPT_CODE) Stm_LLD_SetNormalMode(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel)
{
    /* Timer Counter is re-enabled */
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    STM_TIMER_COUNTER_ENABLE(hwChannel);
}
#endif

#if (GPT_DUAL_CLOCK_MODE == STD_ON)
/*================================================================================================*/
/**
* @brief      The function changes the STM prescaler value.
* @details    This function sets the STM prescaler based on the input mode.
*
* @param[in]  chPrescale     prescaler value
*
* @pre     On/Off by the configuration parameter: GPT_DUAL_CLOCK_MODE
*

*
* @implements DGPT08209
*/
FUNC (void, GPT_CODE) Stm_LLD_SelectPrescaler(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
                                              VAR(Gpt_PrescaleType, AUTOMATIC) chPrescale)
{  
    /* @violates @ref GPT_STM_LLD_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    STM_SET_PRESCALER(hwChannel, chPrescale);
}
#endif


#define GPT_STOP_SEC_CODE
/* @violates @ref GPT_STM_LLD_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_STM_LLD_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"



#ifdef __cplusplus
}
#endif

/** @} */
