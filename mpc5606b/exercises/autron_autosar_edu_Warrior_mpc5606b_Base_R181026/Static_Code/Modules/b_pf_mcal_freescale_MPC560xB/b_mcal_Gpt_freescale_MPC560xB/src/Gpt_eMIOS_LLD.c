/**
*   @file    Gpt_eMIOS_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - Brief file description (one line).
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
* @section Gpt_eMIOS_LLD_C_REF_1
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* The cast is used to address memory mapped registers or other hw resources.
* 
* @section Gpt_eMIOS_LLD_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file. This violation is not fixed
* since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Gpt_eMIOS_LLD_C_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section Gpt_eMIOS_LLD_C_REF_4
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @implements     DGPT07600 */
#include "Gpt_eMIOS_LLD.h"
#include "Reg_eSys_eMIOS.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define GPT_EMIOS_LLD_C_VENDOR_ID                       43
/* @violates @ref Gpt_eMIOS_LLD_C_REF_4 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_EMIOS_LLD_C_AR_RELEASE_MAJOR_VERSION        4
/* @violates @ref Gpt_eMIOS_LLD_C_REF_4 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_EMIOS_LLD_C_AR_RELEASE_MINOR_VERSION        0
/* @violates @ref Gpt_eMIOS_LLD_C_REF_4 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_EMIOS_LLD_C_AR_RELEASE_REVISION_VERSION     3
/* @violates @ref Gpt_eMIOS_LLD_C_REF_4 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_EMIOS_LLD_C_SW_MAJOR_VERSION                1
/* @violates @ref Gpt_eMIOS_LLD_C_REF_4 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_EMIOS_LLD_C_SW_MINOR_VERSION                0
/* @violates @ref Gpt_eMIOS_LLD_C_REF_4 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_EMIOS_LLD_C_SW_PATCH_VERSION                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and GPT header file are of the same Software version */
#if (GPT_EMIOS_LLD_C_VENDOR_ID != GPT_EMIOS_LLD_H_VENDOR_ID)
    #error "Gpt_eMIOS_LLD.c and Gpt_eMIOS_LLD.h have different vendor ids"
#endif
#if ((GPT_EMIOS_LLD_C_AR_RELEASE_MAJOR_VERSION != GPT_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
        (GPT_EMIOS_LLD_C_AR_RELEASE_MINOR_VERSION != GPT_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION) || \
        (GPT_EMIOS_LLD_C_AR_RELEASE_REVISION_VERSION != GPT_EMIOS_LLD_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_eMIOS_LLD.c and Gpt_eMIOS_LLD.h are different"
#endif
#if ((GPT_EMIOS_LLD_C_SW_MAJOR_VERSION != GPT_EMIOS_LLD_H_SW_MAJOR_VERSION) || \
        (GPT_EMIOS_LLD_C_SW_MINOR_VERSION != GPT_EMIOS_LLD_H_SW_MINOR_VERSION) || \
        (GPT_EMIOS_LLD_C_SW_PATCH_VERSION != GPT_EMIOS_LLD_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_eMIOS_LLD.c and Gpt_eMIOS_LLD.h are different"
#endif

/* check if Gpt_eMIOS_LLD.c and Reg_eSys_eMIOS.h are of the same Software version */
#if (GPT_EMIOS_LLD_C_VENDOR_ID != REG_ESYS_EMIOS_H_VENDOR_ID)
    #error "Gpt_eMIOS_LLD.c and Reg_eSys_eMIOS.h have different vendor ids"
#endif
#if ((GPT_EMIOS_LLD_C_AR_RELEASE_MAJOR_VERSION != REG_ESYS_EMIOS_H_AR_RELEASE_MAJOR_VERSION) || \
        (GPT_EMIOS_LLD_C_AR_RELEASE_MINOR_VERSION != REG_ESYS_EMIOS_H_AR_RELEASE_MINOR_VERSION) || \
        (GPT_EMIOS_LLD_C_AR_RELEASE_REVISION_VERSION != REG_ESYS_EMIOS_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_eMIOS_LLD.c and Reg_eSys_eMIOS.h are different"
#endif
#if ((GPT_EMIOS_LLD_C_SW_MAJOR_VERSION != REG_ESYS_EMIOS_H_SW_MAJOR_VERSION) || \
        (GPT_EMIOS_LLD_C_SW_MINOR_VERSION != REG_ESYS_EMIOS_H_SW_MINOR_VERSION) || \
        (GPT_EMIOS_LLD_C_SW_PATCH_VERSION != REG_ESYS_EMIOS_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_eMIOS_LLD.c and Reg_eSys_eMIOS.h are different"
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
/*
* @violates @ref Gpt_eMIOS_LLD_C_REF_2 Repeated include file 
*/
#include "MemMap.h"


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief   Gpt driver initialization function for Emios module.
* @details This function is called separately for each EMIOS hw channel corresponding to the configured
*          timer channels, and:
*         - disables the interrupt corresponding to Emios channel
*         - puts the Emios channel into GPIO mode
*         - sets the prescaler value
*         - enables/disables the Freeze Mode
*         - clears the (pending) interrupt flag corresponding to Emios channel
*         - resets the UC A register.
*
* @param[in]     freezeEnable     indicates if the Freeze mode is enabled
* @param[in]     channelPrescale  prescaler value for the corresponding Emios channel
* @param[in]     hwChannel        Emios hw channel ID
*
* @return       void
*
* @implements DGPT07208
*/
FUNC (void, GPT_CODE) Emios_LLD_InitChannel(
        VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
        VAR(Gpt_PrescaleType, AUTOMATIC) channelPrescale,
        VAR(boolean, AUTOMATIC) freezeEnable
    )
{

    VAR(uint32, AUTOMATIC) tempParam;
    VAR(Gpt_ChannelType, AUTOMATIC) mIdx;   /* Assigned eMIOS HW module  index */
    VAR(Gpt_ChannelType, AUTOMATIC) chIdx;  /* Assigned eMIOS HW channel index */

    mIdx  = (uint8)((uint8)hwChannel >> (uint8)5U);
    chIdx = (uint8)((uint8)hwChannel &  (uint8)0x1FU);

    /* only write UCDIS register if it's available */
    #ifdef EMIOS_UCDIS
        /* enable unified channel to make registers writable */
        /*
        * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
        */
        REG_BIT_CLEAR32( EMIOS_UCDIS(mIdx), (uint32)((uint32)1<<(chIdx)) );
    #endif

    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_BIT_CLEAR32(EMIOS_CCR(mIdx, chIdx),CCR_FEN_MASK);

    /* Stop Channel to Configure Channel */
    /* Timer_gpio_input_mode(hwChannel); */
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_RMW32(EMIOS_CCR(mIdx, chIdx), (CCR_MODE_MASK|CCR_EDSEL_MASK), (CCR_MODE_GPI|CCR_EDSEL_MASK));

    /* Save current emios channel param value in local variable */
    if ((boolean)TRUE == freezeEnable)
    {
        tempParam = ((channelPrescale<<CCR_UCPRE_SHIFT) | CCR_FREN_MASK | CCR_BSL_MASK);
    }
    else
    {
        tempParam = ((channelPrescale<<CCR_UCPRE_SHIFT) | CCR_BSL_MASK);
    }

    /* Initialize prescale value, channel filter, freeze enable, and bus select and disable the prescaler */
    /* Timer_init_control(hwChannel, tempParam); */
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_RMW32
    (
        EMIOS_CCR(mIdx, chIdx), 
        (CCR_FREN_MASK|CCR_UCPRE_MASK|CCR_UCPREN_MASK|CCR_IF_MASK|CCR_FCK_MASK|CCR_BSL_MASK), 
        ((tempParam)&(CCR_FREN_MASK|CCR_UCPRE_MASK|CCR_UCPREN_MASK|CCR_IF_MASK|CCR_FCK_MASK|CCR_BSL_MASK))
        /*
        * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
        */
     );

    /* Clear pending interrupts */
    /* Timer_flag_clear(hwChannel); */
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_WRITE32(EMIOS_CSR(mIdx, chIdx), CSR_FLAG_BIT);

    /* Set Compare Value to 1 (writing 0 may lead to unpredictable result ) */
    /* Timer_set_regA(hwChannel, 1); */
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_WRITE32(EMIOS_CADR(mIdx, chIdx), 1);
}

#if (GPT_DEINIT_API == STD_ON)
/*================================================================================================*/
/**
* @brief   Gpt driver de-initialization function for Emios module.
* @details This function is called separately for each EMIOS hw channel corresponding to the configured
*          timer channels, and:
*          - resets the Emios channel control register
*          - resets the UC A register.
*          - clears the (pending) interrupt flag corresponding to Emios channel
*
* @param[in]     hwChannel        Emios hw channel ID
*
* @implements DGPT07201
*/

FUNC (void, GPT_CODE) Emios_LLD_DeInit(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel)
{
    VAR(Gpt_ChannelType, AUTOMATIC) mIdx;   /* Assigned eMIOS HW module  index */
    VAR(Gpt_ChannelType, AUTOMATIC) chIdx;  /* Assigned eMIOS HW channel index */

    mIdx  = (uint8)((uint8)hwChannel >> (uint8)5U);
    chIdx = (uint8)((uint8)hwChannel &  (uint8)0x1FU);

    /* Reset Timer control register */
    /* Internal Counter is also cleared when entering GPIO Mode */
    /* This is applicable for the following lines of code */
    /* Timer_reset(hwChannel); */
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_WRITE32(EMIOS_CCR(mIdx, chIdx), 0x0UL);

    /* Set Compare Value to 1 (writing 0 may lead to unpredictable result ) */
    /* Timer_set_regA(hwChannel, 1); */
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_WRITE32(EMIOS_CADR(mIdx, chIdx), 1);

    /* Clear Interrupt Flag */
    /* Timer_flag_clear(hwChannel); */
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_WRITE32(EMIOS_CSR(mIdx, chIdx), CSR_FLAG_BIT);

    /* only write UCDIS register if it's available */
    #ifdef EMIOS_UCDIS
        /* disable unified channel */
        /*
        * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
        */
        REG_BIT_SET32( EMIOS_UCDIS(mIdx), (uint32)((uint32)1<<(chIdx)) );
    #endif /* EMIOS_UCDIS */
}
#endif /* GPT_DEINIT_API */


/*==================================================================================================*/
/**
* @brief   Gpt driver function for starting the Emios timer channel.
* @details This function:
*          - puts the Emios channel into GPIO mode
*          - enables the channel prescaler
*          - programs the UC A register with the value passed as input parameter
*          - sets the Emios channel mode to Modulus Counter Buffered (Up counter)
*          - enables the IRQ for the Emios channel, if channel configured in One Shot mode.
*
* @param[in]     hwChannel        Emios hw channel ID
* @param[in]     value            channel timeout value
* @param[in]     channelMode      channel mode: Continous or One Shot
*
* @implements DGPT07204
*/
FUNC (void, GPT_CODE) Emios_LLD_StartTimer(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
                                         VAR(Gpt_ValueType, AUTOMATIC) value,
                                         VAR(Gpt_ChannelModeType, AUTOMATIC) channelMode)
{
    VAR(Gpt_ChannelType, AUTOMATIC) mIdx;   /* Assigned eMIOS HW module  index */
    VAR(Gpt_ChannelType, AUTOMATIC) chIdx;  /* Assigned eMIOS HW channel index */

    mIdx  = (uint8)((uint8)hwChannel >> (uint8)5U);
    chIdx = (uint8)((uint8)hwChannel &  (uint8)0x1FU);

    /* Timer_gpio_input_mode(hwChannel); */
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_RMW32(EMIOS_CCR(mIdx, chIdx), (CCR_MODE_MASK|CCR_EDSEL_MASK), (CCR_MODE_GPI|CCR_EDSEL_MASK));

    /* Timer_channel_pres_enable(hwChannel); */
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_BIT_SET32(EMIOS_CCR(mIdx, chIdx), CCR_UCPREN_MASK);

    /* Timer_set_regA(hwChannel, value); */
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_WRITE32(EMIOS_CADR(mIdx, chIdx), value);
    
    /* Timer_mcb_mode(hwChannel); */
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_RMW32(EMIOS_CCR(mIdx, chIdx), CCR_MODE_MASK, CCR_MODE_MCB_INT_CLOCK);

    /* For one-shot channels, interrupts are required to shut down the channel */
    /* This is a workaround for the lack of one-shot mode in the hardware */
    /* Notifications must still be turned on using Gpt_EnableNotification */
    if (GPT_CH_MODE_ONESHOT == channelMode)
    {
        /* Timer_int_enable(hwChannel); */
        /*
        * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
        */
        REG_BIT_SET32(EMIOS_CCR(mIdx, chIdx), CCR_FEN_MASK);
    }
}

/*==================================================================================================*/
/**
* @brief   Gpt driver function for stopping the Emios timer channel.
* @details This function puts the Emios channel into GPIO mode
* 
* @param[in]     hwChannel        Emios hw channel ID
* @param[out]    returnValuePtr   current time value on stop
* 
* @implements DGPT07205
*/

FUNC (void, GPT_CODE) Emios_LLD_StopTimer(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel, 
                                                P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr)
{
    VAR(Gpt_ChannelType, AUTOMATIC) mIdx;   /*  assigned eMIOS HW module  index */
    VAR(Gpt_ChannelType, AUTOMATIC) chIdx;  /*  assigned eMIOS HW channel index */

    mIdx  = (uint8)((uint8)hwChannel >> (uint8)5U);
    chIdx = (uint8)((uint8)hwChannel &  (uint8)0x1FU);
    
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    *returnValuePtr = REG_READ32(EMIOS_CCNTR(mIdx, chIdx));

    /* Timer_gpio_input_mode(hwChannel); */
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_RMW32(EMIOS_CCR(mIdx, chIdx), (CCR_MODE_MASK|CCR_EDSEL_MASK), (CCR_MODE_GPI|CCR_EDSEL_MASK));
    
    /* Timer_flag_clear(hwChannel); */
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_WRITE32(EMIOS_CSR(mIdx, chIdx), CSR_FLAG_MASK);
}

#if ((GPT_TIME_ELAPSED_API == STD_ON) || (GPT_TIME_REMAINING_API == STD_ON))
/*==================================================================================================*/
/**
* @brief   Gpt driver function for getting the current time value for an Emios timer channel.
* @details This function is called for reading the Emios channel counter register.
*
* @param[in]     hwChannel        Emios hw channel ID
* @param[out]    returnValuePtr   current time value
* 
* @implements DGPT07206
*/

FUNC (void, GPT_CODE) Emios_LLD_GetTime(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
                                        P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr)
{
    VAR(Gpt_ChannelType, AUTOMATIC) mIdx;   /* Assigned eMIOS HW module  index */
    VAR(Gpt_ChannelType, AUTOMATIC) chIdx;  /* Assigned eMIOS HW channel index */

    mIdx  = (uint8)((uint8)hwChannel >> (uint8)5U);
    chIdx = (uint8)((uint8)hwChannel &  (uint8)0x1FU);
    
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    *returnValuePtr = REG_READ32(EMIOS_CCNTR(mIdx, chIdx));    
}
#endif /* GPT_TIME_API */

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/*==================================================================================================*/
/**
* @brief   Gpt driver function for putting the Emios timer channel in SLEEP mode.
* @details This function is called separately for each EMIOS hw channel corresponding to the configured
*          timer channels, and:
*          - clears the (pending) interrupt flag corresponding to Emios channel
*          - puts the Emios channel into GPIO mode, if the wake up functionality is disabled
*          - enables the IRQ for the Emios channel, if the wake up functionality is enabled
*
* @param[in]     hwChannel        Emios hw channel ID
* @param[in]     wakeUpEnabled    Indicates whether wake up functionality is enabled or not for the
*                                 corresponding channel.
* @param[out]    returnValuePtr   current time value on stop
* @implements DGPT07210
*/
FUNC (void, GPT_CODE) Emios_LLD_SetSleepMode(VAR(uint8, AUTOMATIC) hwChannel, boolean wakeUpEnabled,
                                            P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr)
{
    VAR(Gpt_ChannelType, AUTOMATIC) mIdx;   /* Assigned eMIOS HW module  index */
    VAR(Gpt_ChannelType, AUTOMATIC) chIdx;  /* Assigned eMIOS HW channel index */

    mIdx  = (uint8)((uint8)hwChannel >> (uint8)5U);
    chIdx = (uint8)((uint8)hwChannel &  (uint8)0x1FU);
    
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    *returnValuePtr = REG_READ32(EMIOS_CCNTR(mIdx, chIdx));

    /* Timer_flag_clear(hwChannel); */
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_WRITE32(EMIOS_CSR(mIdx, chIdx), CSR_FLAG_MASK);

    /* Check if wake-up is NOT enabled */
    if ((boolean)FALSE == wakeUpEnabled)
    {
        /* Timer_gpio_input_mode(hwChannel); */
        /*
        * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
        */
        REG_RMW32(EMIOS_CCR(mIdx, chIdx), (CCR_MODE_MASK|CCR_EDSEL_MASK), (CCR_MODE_GPI|CCR_EDSEL_MASK));
    }
    else
    {
        /* Timer_int_enable(hwChannel); */
        /*
        * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
        */
        REG_BIT_SET32(EMIOS_CCR(mIdx, chIdx), CCR_FEN_MASK);
    }
}
#endif /* GPT_WAKEUP_FUNCTIONALITY_API */

#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
/*==================================================================================================*/
/**
* @brief   Gpt driver function for enabling the Emios timer channel notifification/IRQ.
* @details This function:
*          - clears the (pending) interrupt flag corresponding to Emios channel
*          - enables the IRQ corresponding to the Emios channel
*
* @param[in]     hwChannel        Emios hw channel ID
*
* @implements    DGPT07203
*/
FUNC (void, GPT_CODE) Emios_LLD_EnableNotification(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel)
{
    VAR(Gpt_ChannelType, AUTOMATIC) mIdx;   /* Assigned eMIOS HW module  index */
    VAR(Gpt_ChannelType, AUTOMATIC) chIdx;  /* Assigned eMIOS HW channel index */

    mIdx  = (uint8)((uint8)hwChannel >> (uint8)5U);
    chIdx = (uint8)((uint8)hwChannel &  (uint8)0x1FU);

    /* Enable Timer Interrupt if it's not already enabled */
    /* Timer_flag_clear(hwChannel); */
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_WRITE32(EMIOS_CSR(mIdx, chIdx), CSR_FLAG_MASK);

    /* Timer_int_enable(hwChannel); */
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_BIT_SET32(EMIOS_CCR(mIdx, chIdx), CCR_FEN_MASK);
}

/*==================================================================================================*/
/**
* @brief   Gpt driver function for disabling the Emios timer channel notifification/IRQ.
* @details This function disables the IRQ corresponding to the Emios channel
* 
* @param[in]     hwChannel        Emios hw channel ID
* 
* @implements DGPT07202
*/
FUNC (void, GPT_CODE) Emios_LLD_DisableNotification(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel)
{
    VAR(Gpt_ChannelType, AUTOMATIC) mIdx;   /* Assigned eMIOS HW module  index */
    VAR(Gpt_ChannelType, AUTOMATIC) chIdx;  /* Assigned eMIOS HW channel index */

    mIdx  = (uint8)((uint8)hwChannel >> (uint8)5U);
    chIdx = (uint8)((uint8)hwChannel &  (uint8)0x1FU);

    /* Timer_int_disable(hwChannel); */
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_BIT_CLEAR32(EMIOS_CCR(mIdx, chIdx), CCR_FEN_MASK);
}
#endif /* GPT_ENABLE_DISABLE_NOTIFICATION_API */

#if (GPT_DUAL_CLOCK_MODE == STD_ON)
/*==================================================================================================*/
/**
* @brief      The function changes the EMIOS channel prescaler value.
* @details    This function sets the EMIOS channel prescaler based on the input mode.
*
* @param[in]  chPrescale     prescaler value for the corresponding Emios channel
* @param[in]  hwChannel      Emios hw channel ID
*
* @implements    DGPT07211
*/
FUNC (void, GPT_CODE) Emios_LLD_SelectPrescaler(VAR(Gpt_ChannelType, AUTOMATIC) hwChannel,
                                                VAR(Gpt_PrescaleType, AUTOMATIC) chPrescale)
{
    VAR(uint32, AUTOMATIC) tempParam;
    VAR(Gpt_ChannelType, AUTOMATIC) mIdx;   /* Assigned eMIOS HW module  index */
    VAR(Gpt_ChannelType, AUTOMATIC) chIdx;  /* Assigned eMIOS HW channel index */

    mIdx  = (uint8)((uint8)hwChannel >> (uint8)5U);
    chIdx = (uint8)((uint8)hwChannel &  (uint8)0x1FU);

    /* Save current emios channel param value in local variable */
    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    tempParam = REG_READ32(EMIOS_CCR(mIdx, chIdx));
    tempParam &= ~((uint32)CCR_UCPRE_MASK);
    tempParam |= ((((uint32)chPrescale)<<CCR_UCPRE_SHIFT) & (uint32)CCR_UCPRE_MASK);

    /*
    * @violates @ref Gpt_eMIOS_LLD_C_REF_1 Cast from unsigned long to pointer 
    */
    REG_WRITE32(EMIOS_CCR(mIdx, chIdx), tempParam);
}
#endif /* GPT_DUAL_CLOCK_MODE == STD_ON */


/*==================================================================================================*/

#define GPT_STOP_SEC_CODE
/*
* @violates @ref Gpt_eMIOS_LLD_C_REF_2 Repeated include file 
*/
/*
* @violates @ref Gpt_eMIOS_LLD_C_REF_3 Declaration before #include 
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
