/**
*   @file    Gpt_Rtc_LLD_Irq.c
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section GPT_RTC_LLD_IRQ_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before #include
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement
* MEMMAP003.
*
* @section GPT_RTC_LLD_IRQ_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_RTC_LLD_IRQ_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* The cast is used to address memory mapped registers or other hw resources.
*
* @section GPT_RTC_LLD_IRQ_C_REF_4
* Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness.
* The long names are maintained for better readability.
*
* @section GPT_RTC_LLD_IRQ_C_REF_5
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
/**
* @file           Gpt_Rtc_LLD_Irq.c
* @requirements   BSW00374, BSW00318
* @implements     DGPT10700
*/
#include "Gpt.h"
#include "Gpt_LLD.h"
#include "Reg_eSys_RTC.h"
#include "Mcal.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_Rtc_LLD_Irq.c
* @requirements   BSW00374, BSW00318
*/
#define GPT_RTC_LLD_IRQ_VENDOR_ID_C                    43
/* @violates @ref GPT_RTC_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_RTC_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C     4
/* @violates @ref GPT_RTC_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_RTC_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C     0
/* @violates @ref GPT_RTC_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_RTC_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C  3
/* @violates @ref GPT_RTC_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_RTC_LLD_IRQ_SW_MAJOR_VERSION_C             1
/* @violates @ref GPT_RTC_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_RTC_LLD_IRQ_SW_MINOR_VERSION_C             0
/* @violates @ref GPT_RTC_LLD_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 5.1, 
* The long identifiers are maintained for better readability. */
#define GPT_RTC_LLD_IRQ_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (GPT_RTC_LLD_IRQ_VENDOR_ID_C != REG_ESYS_RTC_VENDOR_ID)
    #error "Gpt_Rtc_LLD_Irq.c and Reg_eSys_Rtc.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_RTC_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_RTC_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_RTC_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_RTC_AR_RELEASE_MINOR_VERSION) || \
     (GPT_RTC_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_RTC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Rtc_LLD_Irq.c and Reg_eSys_Rtc.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_RTC_LLD_IRQ_SW_MAJOR_VERSION_C != REG_ESYS_RTC_SW_MAJOR_VERSION) || \
     (GPT_RTC_LLD_IRQ_SW_MINOR_VERSION_C != REG_ESYS_RTC_SW_MINOR_VERSION) || \
     (GPT_RTC_LLD_IRQ_SW_PATCH_VERSION_C != REG_ESYS_RTC_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Rtc_LLD_Irq.c and Reg_eSys_Rtc.h are different"
#endif

#if (GPT_RTC_LLD_IRQ_VENDOR_ID_C != GPT_VENDOR_ID)
    #error "Rtc_Gpt_LLD_IRQ.c and Gpt.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_RTC_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_RTC_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_RTC_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C != GPT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Rtc_LLD_Irq.c and Gpt.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_RTC_LLD_IRQ_SW_MAJOR_VERSION_C != GPT_SW_MAJOR_VERSION) || \
     (GPT_RTC_LLD_IRQ_SW_MINOR_VERSION_C != GPT_SW_MINOR_VERSION) || \
     (GPT_RTC_LLD_IRQ_SW_PATCH_VERSION_C != GPT_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Rtc_LLD_Irq.c and Gpt.h are different"
#endif

#if (GPT_RTC_LLD_IRQ_VENDOR_ID_C != GPT_LLD_VENDOR_ID)
    #error "Rtc_Gpt_LLD_IRQ.c and Gpt_LLD.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_RTC_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C != GPT_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_RTC_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C != GPT_LLD_AR_RELEASE_MINOR_VERSION) || \
     (GPT_RTC_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C != GPT_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Rtc_LLD_Irq.c and Gpt_LLD.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_RTC_LLD_IRQ_SW_MAJOR_VERSION_C != GPT_LLD_SW_MAJOR_VERSION) || \
     (GPT_RTC_LLD_IRQ_SW_MINOR_VERSION_C != GPT_LLD_SW_MINOR_VERSION) || \
     (GPT_RTC_LLD_IRQ_SW_PATCH_VERSION_C != GPT_LLD_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Rtc_LLD_Irq.c and Gpt_LLD.h are different"
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
#ifdef GPT_RTC_CH_0_ISR_USED
ISR(Gpt_RTC_Ch_0_ISR);
#endif

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
#define GPT_START_SEC_CODE
/* @violates @ref GPT_RTC_LLD_IRQ_C_REF_1 MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_RTC_LLD_IRQ_C_REF_2 MISRA 2004 Advisory Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

/*==================================================================================================
 *                                     GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef GPT_RTC_CH_0_ISR_USED
/*================================================================================================*/
/**
* @brief          Interrupt handler for RTC channel
* @details        Interrupt Service Routine corresponding to Gpt_RTC_Ch_0 hw channel.
*
*
* @isr
*/
ISR(Gpt_RTC_Ch_0_ISR)
{
    Gpt_Rtc_ProcessInterrupt((Gpt_ChannelType)RTC_CH_0);
    /* @violates @ref GPT_RTC_LLD_IRQ_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer */
    /* @violates @ref GPT_RTC_LLD_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif

#define GPT_STOP_SEC_CODE
/* @violates @ref GPT_RTC_LLD_IRQ_C_REF_1 MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_RTC_LLD_IRQ_C_REF_2 MISRA 2004 Advisory Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
