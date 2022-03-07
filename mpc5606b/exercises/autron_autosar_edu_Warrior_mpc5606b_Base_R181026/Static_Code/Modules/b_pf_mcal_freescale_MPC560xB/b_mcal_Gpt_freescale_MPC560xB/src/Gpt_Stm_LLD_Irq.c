/**
*   @file    Gpt_Stm_LLD_Irq.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - STM driver source file.
*   @details Containes the Interrupt Service mechanism.
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
* @section GPT_STM_LLD_IRQ_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section GPT_STM_LLD_IRQ_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_STM_LLD_IRQ_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* The cast is used to address memory mapped registers or other hw resources.
*
* @section GPT_STM_LLD_IRQ_C_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type than an integral type.
* This is part of the test file used for checking the BASE header files. Conversions are verified to
* be ok for this file.
*
* @section GPT_STM_LLD_IRQ_C_REF_5
* Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness.
* The long names are maintained for better readability.
*
*@section GPT_STM_LLD_IRQ_C_REF_6
* Violates MISRA 2004 Required Rule 5.1, This violation is not  fixed since naming convention of 
* Identifiers (internal and external) are followed as per Autosar standards ,some times which may
* exceeds more than 31 characters.
*
*@section GPT_STM_LLD_IRQ_C_REF_7
* Violates MISRA 2004 Required Rule 12.8, The right-hand operand of a shift operator shall lie 
* between zero and one less than the width in bits of the underlying type of the left-hand operand
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Gpt_Stm_LLD_Irq.c
* @requirements   BSW00374, BSW00318
* @implements     DGPT08700
*/
#include "Gpt.h"
#include "Gpt_LLD.h"
#include "Reg_eSys_Stm.h"
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_Stm_LLD_Irq.c
* @brief          Parameters that shall be published within the Gpt driver header file and also in the
*                 module's description file
* @requirements   BSW00374, BSW00379, BSW00318
* @{
*/

#define GPT_STM_LLD_IRQ_VENDOR_ID_C                    43
/* @violates @ref GPT_STM_LLD_IRQ_C_REF_6 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_STM_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C     4
/* @violates @ref GPT_STM_LLD_IRQ_C_REF_6 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_STM_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C     0
/* @violates @ref GPT_STM_LLD_IRQ_C_REF_6 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_STM_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C  3
/* @violates @ref GPT_STM_LLD_IRQ_C_REF_6 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_STM_LLD_IRQ_SW_MAJOR_VERSION_C             1
/* @violates @ref GPT_STM_LLD_IRQ_C_REF_6 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_STM_LLD_IRQ_SW_MINOR_VERSION_C             0
/* @violates @ref GPT_STM_LLD_IRQ_C_REF_6 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_STM_LLD_IRQ_SW_PATCH_VERSION_C             1
/**@}*/
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (GPT_STM_LLD_IRQ_VENDOR_ID_C != REG_ESYS_STM_VENDOR_ID)
    #error "Gpt_Stm_LLD_Irq.c and Reg_eSys_Stm.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_STM_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_STM_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_STM_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_STM_AR_RELEASE_MINOR_VERSION) || \
     (GPT_STM_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_STM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Stm_LLD_Irq.c and Reg_eSys_Stm.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_STM_LLD_IRQ_SW_MAJOR_VERSION_C != REG_ESYS_STM_SW_MAJOR_VERSION) || \
     (GPT_STM_LLD_IRQ_SW_MINOR_VERSION_C != REG_ESYS_STM_SW_MINOR_VERSION) || \
     (GPT_STM_LLD_IRQ_SW_PATCH_VERSION_C != REG_ESYS_STM_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Stm_LLD_Irq.c and Reg_eSys_Stm.h are different"
#endif

#if (GPT_STM_LLD_IRQ_VENDOR_ID_C != GPT_VENDOR_ID)
    #error "Gpt_Stm_LLD_Irq.c and Gpt.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_STM_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_STM_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_STM_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C != GPT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Stm_LLD_Irq.c and Gpt.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_STM_LLD_IRQ_SW_MAJOR_VERSION_C != GPT_SW_MAJOR_VERSION) || \
     (GPT_STM_LLD_IRQ_SW_MINOR_VERSION_C != GPT_SW_MINOR_VERSION) || \
     (GPT_STM_LLD_IRQ_SW_PATCH_VERSION_C != GPT_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Stm_LLD_Irq.c and Gpt.h are different"
#endif

#if (GPT_STM_LLD_IRQ_VENDOR_ID_C != GPT_LLD_VENDOR_ID)
    #error "Gpt_Stm_LLD_Irq.c and Gpt_LLD.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_STM_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C != GPT_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_STM_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C != GPT_LLD_AR_RELEASE_MINOR_VERSION) || \
     (GPT_STM_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C != GPT_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Stm_LLD_Irq.c and Gpt_LLD.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_STM_LLD_IRQ_SW_MAJOR_VERSION_C != GPT_LLD_SW_MAJOR_VERSION) || \
     (GPT_STM_LLD_IRQ_SW_MINOR_VERSION_C != GPT_LLD_SW_MINOR_VERSION) || \
     (GPT_STM_LLD_IRQ_SW_PATCH_VERSION_C != GPT_LLD_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Stm_LLD_Irq.c and Gpt_LLD.h are different"
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
#ifdef GPT_STM_0_CH_0_ISR_USED
ISR(Gpt_STM_0_Ch_0_ISR);
#endif

#ifdef GPT_STM_0_CH_1_ISR_USED
ISR(Gpt_STM_0_Ch_1_ISR);
#endif

#ifdef GPT_STM_0_CH_2_ISR_USED
ISR(Gpt_STM_0_Ch_2_ISR);
#endif

#ifdef GPT_STM_0_CH_3_ISR_USED
ISR(Gpt_STM_0_Ch_3_ISR);
#endif

#ifdef GPT_STM_1_CH_0_ISR_USED
ISR(Gpt_STM_1_Ch_0_ISR);
#endif

#ifdef GPT_STM_1_CH_1_ISR_USED
ISR(Gpt_STM_1_Ch_1_ISR);
#endif

#ifdef GPT_STM_1_CH_2_ISR_USED
ISR(Gpt_STM_1_Ch_2_ISR);
#endif

#ifdef GPT_STM_1_CH_3_ISR_USED
ISR(Gpt_STM_1_Ch_3_ISR);
#endif

#ifdef GPT_STM_2_CH_0_ISR_USED
ISR(Gpt_STM_2_Ch_0_ISR);
#endif

#ifdef GPT_STM_2_CH_1_ISR_USED
ISR(Gpt_STM_2_Ch_1_ISR);
#endif

#ifdef GPT_STM_2_CH_2_ISR_USED
ISR(Gpt_STM_2_Ch_2_ISR);
#endif

#ifdef GPT_STM_2_CH_3_ISR_USED
ISR(Gpt_STM_2_Ch_3_ISR);
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define GPT_START_SEC_CODE
/* @violates @ref GPT_STM_LLD_IRQ_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_STM_LLD_IRQ_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef GPT_STM_0_CH_0_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_0_Ch_0 hw channel.
*
*
* @isr
*/
ISR(Gpt_STM_0_Ch_0_ISR)
{
    Gpt_Stm_ProcessInterrupt((Gpt_ChannelType)STM_0_CH_0);
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_0_CH_0_ISR_USED */

#ifdef GPT_STM_0_CH_1_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_0_Ch_1 hw channel (or for shared ISR).
*
*
* @isr
*
* @note    On some platforms there is only one interrupt line shared for channels 1, 2 and 3.
*/
ISR(Gpt_STM_0_Ch_1_ISR)
{
#ifndef GPT_STM_ISR_1_SHARED
    Gpt_Stm_ProcessInterrupt((Gpt_ChannelType)STM_0_CH_1);
#else
    /*
    * @violates @ref GPT_STM_LLD_IRQ_C_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be
    * performed between a pointer to a function and any type than an integral type.
    */
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_7 Violates MISRA 2004 Required Rule 12.8 */
    if (STM_CH_READ_ISR_REQ(STM_0_CH_1))
    {
        Gpt_Stm_ProcessInterrupt((Gpt_ChannelType)STM_0_CH_1);
    }
    /*
    * @violates @ref GPT_STM_LLD_IRQ_C_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be
    * performed between a pointer to a function and any type than an integral type.
    */
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_7 Violates MISRA 2004 Required Rule 12.8 */
    else if (STM_CH_READ_ISR_REQ(STM_0_CH_2))
    {
        Gpt_Stm_ProcessInterrupt((Gpt_ChannelType)STM_0_CH_2);
    }
    /*
    * @violates @ref GPT_STM_LLD_IRQ_C_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be
    * performed between a pointer to a function and any type than an integral type.
    */
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_7 Violates MISRA 2004 Required Rule 12.8 */
    else if (STM_CH_READ_ISR_REQ(STM_0_CH_3))
    {
        Gpt_Stm_ProcessInterrupt((Gpt_ChannelType)STM_0_CH_3);
    }
    else
    {
        /* Do nothing. Empty else added to fix MISRA Violation*/ 
    }
#endif /* GPT_STM_0_ISR_1_SHARED */
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_CH_1_ISR_USED */

#ifndef GPT_STM_ISR_1_SHARED
#ifdef GPT_STM_0_CH_2_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_0_Ch_2 hw channel.
*
*
* @isr
*/
ISR(Gpt_STM_0_Ch_2_ISR)
{
    Gpt_Stm_ProcessInterrupt((Gpt_ChannelType)STM_0_CH_2);
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_0_CH_2_ISR_USED */

#ifdef GPT_STM_0_CH_3_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_0_Ch_3 hw channel.
*
*
* @isr
*/
/*************************************************************************************************/
ISR(Gpt_STM_0_Ch_3_ISR)
{
    Gpt_Stm_ProcessInterrupt((Gpt_ChannelType)STM_0_CH_3);
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_0_CH_3_ISR_USED */

#endif /* GPT_STM_ISR_1_SHARED */


#ifdef GPT_STM_1_CH_0_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_1_Ch_0 hw channel.
*
*
* @isr
*/
ISR(Gpt_STM_1_Ch_0_ISR)
{
    Gpt_Stm_ProcessInterrupt((Gpt_ChannelType)STM_1_CH_0);
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_1_CH_0_ISR_USED */

#ifdef GPT_STM_1_CH_1_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_1_Ch_1 hw channel (or for shared ISR).
*
*
* @isr
*
*/
ISR(Gpt_STM_1_Ch_1_ISR)
{
    Gpt_Stm_ProcessInterrupt((Gpt_ChannelType)STM_1_CH_1);
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_1_CH_1_ISR_USED */

#ifdef GPT_STM_1_CH_2_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_1_Ch_2 hw channel.
*
*
* @isr
*/
ISR(Gpt_STM_1_Ch_2_ISR)
{
    Gpt_Stm_ProcessInterrupt((Gpt_ChannelType)STM_1_CH_2);
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_1_CH_2_ISR_USED */

#ifdef GPT_STM_1_CH_3_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_1_Ch_3 hw channel.
*
*
* @isr
*/
/*************************************************************************************************/
ISR(Gpt_STM_1_Ch_3_ISR)
{
    Gpt_Stm_ProcessInterrupt((Gpt_ChannelType)STM_1_CH_3);
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_1_CH_3_ISR_USED */

#ifdef GPT_STM_2_CH_0_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_2_Ch_0 hw channel.
*
*
* @isr
*/
ISR(Gpt_STM_2_Ch_0_ISR)
{
    Gpt_Stm_ProcessInterrupt((Gpt_ChannelType)STM_2_CH_0);
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_2_CH_0_ISR_USED */

#ifdef GPT_STM_2_CH_1_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_2_Ch_1 hw channel (or for shared ISR).
*
*
* @isr
*
*/
ISR(Gpt_STM_2_Ch_1_ISR)
{
    Gpt_Stm_ProcessInterrupt((Gpt_ChannelType)STM_2_CH_1);
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_2_CH_1_ISR_USED */

#ifdef GPT_STM_2_CH_2_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_2_Ch_2 hw channel.
*
*
* @isr
*/
ISR(Gpt_STM_2_Ch_2_ISR)
{
    Gpt_Stm_ProcessInterrupt((Gpt_ChannelType)STM_2_CH_2);
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_2_CH_2_ISR_USED */

#ifdef GPT_STM_2_CH_3_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_2_Ch_3 hw channel.
*
*
* @isr
*/
/*************************************************************************************************/
ISR(Gpt_STM_2_Ch_3_ISR)
{
    Gpt_Stm_ProcessInterrupt((Gpt_ChannelType)STM_2_CH_3);
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_3 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /* @violates @ref GPT_STM_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_2_CH_3_ISR_USED */

#define GPT_STOP_SEC_CODE
/* @violates @ref GPT_STM_LLD_IRQ_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_STM_LLD_IRQ_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
