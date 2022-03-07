/**
*   @file    Gpt_Pit_LLD_Irq.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - PIT driver source file.
*   @details PIT driver interrupt routines..
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
* @section GPT_PIT_LLD_IRQ_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section GPT_PIT_LLD_IRQ_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_PIT_LLD_IRQ_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* The cast is used to address memory mapped registers or other hw resources.
*
* @section GPT_PIT_LLD_IRQ_C_REF_4
* Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness, and 10.3,
* Cast of complex integer expression to larger type.
* Many type conversions are implemented in MACROS. The code was tested successfully with 3
* different compilers.
*
* @section GPT_PIT_LLD_IRQ_C_REF_5
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
#include "Gpt.h"
#include "Gpt_LLD.h"
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_Pit_LLD_Irq.c
* @requirements   BSW00374, BSW00318
* @implements     DGPT09700
*/
#define GPT_PIT_LLD_IRQ_VENDOR_ID_C                    43
/* @violates @ref GPT_PIT_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 5.1,
* The long identifiers are maintained for better readability. */
#define GPT_PIT_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C     4
/* @violates @ref GPT_PIT_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 5.1,
* The long identifiers are maintained for better readability. */
#define GPT_PIT_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C     0
/* @violates @ref GPT_PIT_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 5.1,
* The long identifiers are maintained for better readability. */
#define GPT_PIT_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C  3
/* @violates @ref GPT_PIT_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 5.1,
* The long identifiers are maintained for better readability. */
#define GPT_PIT_LLD_IRQ_SW_MAJOR_VERSION_C             1
/* @violates @ref GPT_PIT_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 5.1,
* The long identifiers are maintained for better readability. */
#define GPT_PIT_LLD_IRQ_SW_MINOR_VERSION_C             0
/* @violates @ref GPT_PIT_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 5.1,
* The long identifiers are maintained for better readability. */
#define GPT_PIT_LLD_IRQ_SW_PATCH_VERSION_C             1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#if ( GPT_PIT_LLD_IRQ_VENDOR_ID_C!= GPT_VENDOR_ID)
#error "Gpt_Pit_LLD_Irq.c and Gpt.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_PIT_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_PIT_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_PIT_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C != GPT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Pit_LLD_Irq.c and Gpt.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_PIT_LLD_IRQ_SW_MAJOR_VERSION_C != GPT_SW_MAJOR_VERSION) || \
     (GPT_PIT_LLD_IRQ_SW_MINOR_VERSION_C != GPT_SW_MINOR_VERSION) || \
     (GPT_PIT_LLD_IRQ_SW_PATCH_VERSION_C != GPT_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Pit_LLD_Irq.c and Gpt.h are different"
#endif

#if ( GPT_PIT_LLD_IRQ_VENDOR_ID_C!= GPT_LLD_VENDOR_ID)
#error "Gpt_Pit_LLD_Irq.c and Gpt_LLD.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_PIT_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C != GPT_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_PIT_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C != GPT_LLD_AR_RELEASE_MINOR_VERSION) || \
     (GPT_PIT_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C != GPT_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Pit_LLD_Irq.c and Gpt_LLD.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_PIT_LLD_IRQ_SW_MAJOR_VERSION_C != GPT_LLD_SW_MAJOR_VERSION) || \
     (GPT_PIT_LLD_IRQ_SW_MINOR_VERSION_C != GPT_LLD_SW_MINOR_VERSION) || \
     (GPT_PIT_LLD_IRQ_SW_PATCH_VERSION_C != GPT_LLD_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Pit_LLD_Irq.c and Gpt_LLD.h are different"
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
#ifdef GPT_PIT_CH_0_ISR_USED
ISR(Gpt_PIT_TIMER_0_ISR);
#endif

#ifdef GPT_PIT_CH_1_ISR_USED
ISR(Gpt_PIT_TIMER_1_ISR);
#endif

#ifdef GPT_PIT_CH_2_ISR_USED
ISR(Gpt_PIT_TIMER_2_ISR);
#endif

#ifdef GPT_PIT_CH_3_ISR_USED
ISR(Gpt_PIT_TIMER_3_ISR);
#endif

#ifdef GPT_PIT_CH_4_ISR_USED
ISR(Gpt_PIT_TIMER_4_ISR);
#endif

#ifdef GPT_PIT_CH_5_ISR_USED
ISR(Gpt_PIT_TIMER_5_ISR);
#endif

#ifdef GPT_PIT_CH_6_ISR_USED
ISR(Gpt_PIT_TIMER_6_ISR);
#endif

#ifdef GPT_PIT_CH_7_ISR_USED
ISR(Gpt_PIT_TIMER_7_ISR);
#endif

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
#define GPT_START_SEC_CODE
/* @violates @ref GPT_PIT_LLD_IRQ_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_PIT_LLD_IRQ_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef GPT_PIT_CH_0_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_TIMER_0 hw channel.
*
*
* @isr
*/
ISR(Gpt_PIT_TIMER_0_ISR)
{
    Gpt_Pit_ProcessInterrupt((Gpt_ChannelType)PIT_CH_0);
    /* @violates @ref GPT_PIT_LLD_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /* @violates @ref GPT_PIT_LLD_IRQ_C_REF_4 Violates MISRA 2004 Required Rules 10.1 */
    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_CH_1_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_TIMER_1 hw channel.
*
*
* @isr
*/
ISR(Gpt_PIT_TIMER_1_ISR)
{
    Gpt_Pit_ProcessInterrupt((Gpt_ChannelType)PIT_CH_1);
    /* @violates @ref GPT_PIT_LLD_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /* @violates @ref GPT_PIT_LLD_IRQ_C_REF_4 Violates MISRA 2004 Required Rules 10.1 */
    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_CH_2_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_TIMER_2 hw channel.
*
*
* @isr
*/
ISR(Gpt_PIT_TIMER_2_ISR)
{
    Gpt_Pit_ProcessInterrupt((Gpt_ChannelType)PIT_CH_2);
    /* @violates @ref GPT_PIT_LLD_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /* @violates @ref GPT_PIT_LLD_IRQ_C_REF_4 Violates MISRA 2004 Required Rules 10.1 */
    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_CH_3_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_TIMER_3 hw channel.
*
*
* @isr
*/
ISR(Gpt_PIT_TIMER_3_ISR)
{
    Gpt_Pit_ProcessInterrupt((Gpt_ChannelType)PIT_CH_3);
    /* @violates @ref GPT_PIT_LLD_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /* @violates @ref GPT_PIT_LLD_IRQ_C_REF_4 Violates MISRA 2004 Required Rules 10.1 */
    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_CH_4_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_TIMER_4 hw channel.
*
*
* @isr
*/
ISR(Gpt_PIT_TIMER_4_ISR)
{
    Gpt_Pit_ProcessInterrupt((Gpt_ChannelType)PIT_CH_4);
    /* @violates @ref GPT_PIT_LLD_IRQ_C_REF_4 Violates MISRA 2004 Required Rules 10.1 */
    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_CH_5_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_TIMER_5 hw channel.
*
*
* @isr
*/
ISR(Gpt_PIT_TIMER_5_ISR)
{
    Gpt_Pit_ProcessInterrupt((Gpt_ChannelType)PIT_CH_5);
    /* @violates @ref GPT_PIT_LLD_IRQ_C_REF_4 Violates MISRA 2004 Required Rules 10.1 */
    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_CH_6_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_TIMER_6 hw channel.
*
*
* @isr
*/
ISR(Gpt_PIT_TIMER_6_ISR)
{
    Gpt_Pit_ProcessInterrupt((Gpt_ChannelType)PIT_CH_6);
    /* @violates @ref GPT_PIT_LLD_IRQ_C_REF_4 Violates MISRA 2004 Required Rules 10.1 */
    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_CH_7_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_TIMER_7 hw channel.
*
*
* @isr
*/
ISR(Gpt_PIT_TIMER_7_ISR)
{
    Gpt_Pit_ProcessInterrupt((Gpt_ChannelType)PIT_CH_7);
    /* @violates @ref GPT_PIT_LLD_IRQ_C_REF_4 Violates MISRA 2004 Required Rules 10.1 */
    EXIT_INTERRUPT();
}
#endif

#define GPT_STOP_SEC_CODE
/* @violates @ref GPT_PIT_LLD_IRQ_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_PIT_LLD_IRQ_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
